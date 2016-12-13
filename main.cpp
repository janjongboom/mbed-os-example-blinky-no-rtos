#include "mbed.h"

DigitalOut led1(LED1);

// This code does not use mbed RTOS
int main() {
    while (true) {
        led1 = !led1;
        // Sleeping on the main (only) thread
        wait_ms(500);
    }
}

