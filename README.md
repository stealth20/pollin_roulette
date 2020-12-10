# pollin_roulette

Alternativ-Firmware für den Roulette-Bausatz von Pollin.de  
https://www.pollin.de/p/bausatz-roulette-810163?utm_source=google&utm_medium=fshopping&gclid=CjwKCAiAiML-BRAAEiwAuWVggh9v3cvVZu4plJZtavQpk4j6eNH6-6Ru-SYItPxHDI77VmRyl9mvUBoCN-UQAvD_BwE


You can open project with QtCreator 

or 

develop by using simple text editor


## BUILD:

make

## PROGRAM

To program controller directly in the circuit board by using ISP connector you have to decrease power voltage from 9V to max 6V.
Because programming pins are used as GPIO's to control the LEDs directly we have to reduce supply voltage under forward voltage of LEDs.
Alternatively you can unsolder R1, R2 and R3 before programming.

### Program fuses first:

- Internal RC 4Mhz 
- divide main clock by 8

### Flash MCU
avrisp2 is set as default flash tool.
If you want use other tool please edit avrdude settings in Makefile

make program


