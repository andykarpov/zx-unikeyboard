# zx-unikeyboard-ps2

This is a ps/2 keyboard controller that allows to connect any keyboard matrix and remap its keys into a ps/2 keyboard.

Based on zx-unikeyboard controller 
https://github.com/valerium-labs/zx-unikeyboard 

Based on ideas of converting a custom keyboard into PS/2-keyboard https://zx-pk.ru/threads/32497-kak-peredelat-prakticheski-lyubuyu-klaviaturu-v-ps-2.html 
and PS/2-CPLD-keyboard controller by andykarpov https://github.com/andykarpov/ps2_cpld_kbd

Unikeyboard ps/2 controller lets you connect any laptop or desktop keyboard matrix (up to 26 pins in any order), 
scan its keypresses to collect the pins interaction (AVR-Keyexplorer module), build an array of its keys and then "learn" 
a controller firmware (avr_kbd_ps2) to convert your keyboard layout into standard ps/2 keyboard.
