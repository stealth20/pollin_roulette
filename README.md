# pollin_roulette

Alternativ-Firmware für den Roulette-Bausatz von Pollin.de  
https://www.pollin.de/p/bausatz-roulette-810163?utm_source=google&utm_medium=fshopping&gclid=CjwKCAiAiML-BRAAEiwAuWVggh9v3cvVZu4plJZtavQpk4j6eNH6-6Ru-SYItPxHDI77VmRyl9mvUBoCN-UQAvD_BwE


You can open project with QtCreator 

or 

develop by using simple text editor


## BUILD:

make

## PROGRAM

### Program fuses first:

- Internal RC 4Mhz 
- divide main clock by 8

### Flash MCU
avrisp2 is set as default flash tool.
If you want use other tool please edit avrdude settings in Makefile

make program


