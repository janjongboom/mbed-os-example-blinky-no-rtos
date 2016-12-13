# Blinky for mbed OS 5 - without using mbed RTOS

This application demonstrates how to remove mbed RTOS from an mbed OS 5 program to save RAM and flash.

For build instructions, see [ARMmbed/mbed-os-example-blinky](https://github.com/armmbed/mbed-os-example-blinky).

## Application size

Compiled with GCC 4.9.3 on a FRDM-K64F, with `NDEBUG` enabled and without serial drivers ([more info](https://developer.mbed.org/blog/entry/Optimizing-memory-usage-in-mbed-OS-52/)):

```
Total Static RAM memory (data + bss): 2560 bytes
Total Flash memory (text + data + misc): 5624 bytes
```
