#include "pico/stdlib.h"

#define UNIT_MS 200u

static const uint LED_PIN = PICO_DEFAULT_LED_PIN;

static void dot(void)
{
    gpio_put(LED_PIN, 1);
    sleep_ms(UNIT_MS);
    gpio_put(LED_PIN, 0);
    sleep_ms(UNIT_MS); // element gap (1 unit)
}

static void dash(void)
{
    gpio_put(LED_PIN, 1);
    sleep_ms(3 * UNIT_MS);
    gpio_put(LED_PIN, 0);
    sleep_ms(UNIT_MS); // element gap (1 unit)
}

static void letter_gap(void)
{
    // After the element gap (1 unit) we need 2 more units to make 3 units between letters
    sleep_ms(2 * UNIT_MS);
}

static void word_gap(void)
{
    // After the element gap (1 unit) we need 6 more units to make 7 units between words
    sleep_ms(6 * UNIT_MS);
}

static void send_S(void)
{
    dot();
    dot();
    dot();
    letter_gap();
}

static void send_O(void)
{
    dash();
    dash();
    dash();
    letter_gap();
}

int main(void)
{
    // Initialize chosen LED pin
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // SOS: S O S
        send_S();
        send_O();
        send_S();

        // pause between repeated SOS transmissions
        word_gap();
    }
    return 0;
}
