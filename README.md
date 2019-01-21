# Blinky for Mbed OS 5 - without using Mbed RTOS

This application demonstrates how to remove Mbed RTOS from an Mbed OS 5 program to save RAM and flash. Note that you'll lose IP networking capabilities, and the opportunity to run tests through Greentea. This also has effects on tickless mode and the sleep manager might not function anymore. In the future Mbed OS is introducing a bare-metal mode, which no longer requires this work.

Note that patching the networking libraries is possible, see [mbed-os#7956](https://github.com/ARMmbed/mbed-os/issues/7956) for some pointers.

## How does it work?

In `.mbedignore` folders that depend on the RTOS are excluded. This also means the `MBED_CONF_RTOS_PRESENT` is no longer defined.

**Additional optimizations**

* Disable flush of standard I/O's at exit (see `mbed_app.json`).
* Build with newlib-nano.

## Application size

Compiled with GCC 6 on a FRDM-K64F with [newlib-nano](https://os.mbed.com/blog/entry/Reducing-memory-usage-with-a-custom-prin/) and a release profile:

```
Total Static RAM memory (data + bss): 2568 bytes
Total Flash memory (text + data): 6320 bytes
```

To compile with newlib-nano in release mode, build with the `tiny` profile:

```
$ mbed compile --profile=./profiles/tiny.json
```

## Mbed minimal printf

UART and Serial drivers take up a lot of space. See [minimal-printf](https://github.com/ARMmbed/minimal-printf) for a size-optimized library.
