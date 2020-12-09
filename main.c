/**
 * set fuses to internal RC 4 MHz to save battery
 * set divide main clock by 8
 */
#define F_CPU 500000

#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <stdlib.h>

#include "led.h"
#include "beep.h"

#define BUTTON_PIN      PB0

int main(void){
    int8_t i = 0;
    uint8_t run = 0;
    uint8_t nloops = 0;
    uint8_t luckyNumber = 13;

    //init button
    DDRB  &= ~(1<<BUTTON_PIN);
    //pullup
    PORTB |=  (1<<BUTTON_PIN);

    beep_init();

    beep(EndSound);

    while(1){
        if(run){
            setLed(i);
            beep(Ball);
            if(nloops == 5 && i == luckyNumber){
                beep(EndSound);
                setLed(i);
                for(uint8_t d = 0; d < 70; ++d){
                    _delay_ms(20);
                }
                ledByeBye();
                setLed(i);
                for(uint8_t d = 0; d < 70; ++d){
                    _delay_ms(10);
                }
                setLed(LED_ALL_OFF);
                run = 0;
            }else{
                _delay_ms((i + 37 * nloops)/2);
            }
            if(i < 36){
                ++i;
            }else {
                i = 0;
                ++nloops;
            }
        }else if((PINB & (1 << BUTTON_PIN))==0){
            run = 1;
            nloops = 0;
            i = luckyNumber;
            luckyNumber = rand() % 37;
        }
	}
	return 0;
}

