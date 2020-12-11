/**
 * set fuses to internal RC 4 MHz to save battery
 * set divide main clock by 8
 */
#define F_CPU 500000

#include <avr/io.h>
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>
#include <stdlib.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>

#include "led.h"
#include "beep.h"

#define BUTTON_PIN      PB0
#define PCIE    5

int sleep(){
    sei();
    sleep_mode();
    cli();
}

int main(void){
    int8_t i = 0;
    uint8_t nloops = 0;
    uint8_t luckyNumber = 13;

    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    GIMSK |= ( 1 << PCIE );
    PCMSK = ( 1 << PCINT0 );

    //init button
    DDRB  = (1<<SPEAKER_PIN);
    //pullup
    PORTB |=  (1<<BUTTON_PIN);

    beep(1);

    while(1){
        if((PINB & (1 << BUTTON_PIN))==0){
            nloops = 0;
            i = luckyNumber;
            luckyNumber = rand() % 37;
            while(1){
                setLed(i);
                beep(0);
                if(nloops == 5 && i == luckyNumber){
                    beep(1);
                    ledByeBye();
                    setLed(i);
                    _delay_ms(1500);
                    setLed(LED_ALL_OFF);
                    break;
                }else{
                    _delay_ms((i + 37 * nloops)/2);
                }
                if(i < 36){
                    ++i;
                }else {
                    i = 0;
                    ++nloops;
                }
            }
        }
        sleep();
	}
	return 0;
}

EMPTY_INTERRUPT(PCINT_vect);
