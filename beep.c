#include "beep.h"
#define F_CPU 500000
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#define BALL_PERIOD     90
#define ENDSOUND_PERIOD 37

void beep(uint8_t type){
    if(type == 0){
        for (int8_t i = 0; i < 5; ++i) {
            PORTB |= (1<<SPEAKER_PIN);
            _delay_us(BALL_PERIOD);
            PORTB &= ~(1<<SPEAKER_PIN);
            _delay_us(BALL_PERIOD);
        }
    }else {
        for(uint8_t j = 0; j < 3; ++j){
            for (uint16_t i = 0; i < 1500; ++i) {
                PORTB |= (1<<SPEAKER_PIN);
                _delay_us(ENDSOUND_PERIOD);
                PORTB &= ~(1<<SPEAKER_PIN);
                _delay_us(ENDSOUND_PERIOD);
            }
            _delay_ms(200);
        }
    }
}
