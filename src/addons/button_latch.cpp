#include "addons/button_latch.h"
#include "pico/stdlib.h"

#define BUTTON_PIN 4      // Replace with your actual GPIO
#define LED_PIN 25        // Replace with BOARD_LED_PIN if using onboard LED

void ButtonLatchAddon::setup() {
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);  // For active-low button

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    lastButtonState = true; // Not pressed
    latchedState = false;
}

void ButtonLatchAddon::process() {
    bool currentButtonState = gpio_get(BUTTON_PIN);

    if (!currentButtonState && lastButtonState) {  // Rising edge (button press)
        latchedState = !latchedState;
        gpio_put(LED_PIN, latchedState);
    }

    lastButtonState = currentButtonState;
}