#!/bin/sh

export PATH=$HOME/.platformio/penv/bin:$PATH

echo "Building AVR sources"

pio run -t clean
pio run
cp .pio/build/ATmega32/firmware.hex ../../releases/avr_kbd_ps2.hex
