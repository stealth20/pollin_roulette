#include "led.h"

#define F_CPU 500000
#define __DELAY_BACKWARD_COMPATIBLE__
#include <util/delay.h>

#define OFF_B 0b11111010
#define OFF_D 0x7F

// high - PORTD
uint8_t lport_mask[5]={
    0b10111100,
    0b00111111,
    0b00111111,
    0b00000000,
    0b00000
};

// high - PORTD
uint8_t hport_mask[5]={
    0b11110010,
    0b11001111,
    0b00111111,
    0b00000000,
    0b00000

};

struct Pin{
    uint8_t hpin;
    uint8_t lpin;
};


static struct Pin pins[] = {
{PB3, PB1}, //D0
{PD3, PB1}, //D32
{PB1, PD3}, //D15
{PB1, PD6}, //D19
{PD5, PD6}, //D4
{PD6, PD5}, //D21
{PD6, PB1}, //D2
{PD4, PD5}, //D25

{PD5, PD4}, //D17
{PD3, PD4}, //D34
{PD4, PD3}, //D6
{PD0, PD3}, //D27
{PB1, PD4}, //D13
{PB1, PD5}, //D36
{PD5, PB1}, //D11
{PD4, PB1}, //D30

{PD1, PD0}, //D8
{PD0, PD1}, //D23
{PD2, PD0}, //D10
{PD1, PD2}, //D5
{PD2, PD1}, //D24
{PD0, PD2}, //D16
{PB7, PB6}, //D33
{PB6, PB7}, //D1

{PB5, PB6}, //D20
{PB6, PB5}, //D14
{PB7, PB5}, //D31
{PB5, PB7}, //D9
{PB5, PB4}, //D22
{PB4, PB5}, //D18
{PB3, PB4}, //D29
{PB4, PB3}, //D7

{PB7, PB4}, //D28
{PB4, PB7}, //D12
{PB7, PB3}, //D35
{PB3, PB7}, //D3
{PB1, PB3}  //D26
};

void setLed(int8_t i){
    DDRB  &= ~OFF_B;
    PORTB &= ~OFF_B;
    DDRD  &= ~OFF_D;
    PORTD &= ~OFF_D;
    if(i < 0 || i > 36 ){
        return;
    }

    volatile uint8_t* hport;
    volatile uint8_t* lport;
    if(hport_mask[i / 8] & (1<<(i % 8))){
        hport = &PORTD;
    }else{
        hport = &PORTB;
    }
    if(lport_mask[i / 8] & (1<<(i % 8))){
        lport = &PORTD;
    }else{
        lport = &PORTB;
    }

    *(hport - 1) |= (1<<pins[i].hpin); //DDR
    *(hport) |= (1<<pins[i].hpin);

    *(lport - 1) |= (1<<pins[i].lpin); //DDR
    *(lport) &= ~(1<<pins[i].lpin);
}

void ledByeBye(void){
    uint16_t n = 80;
    uint16_t s = 30;
    for(uint16_t j = s; j < n; ++j){
        //setLed(LED_ALL_OFF);
        if(j < (n-s)/2+s/2){
            setLed((j*j/20) % 36);
        }else{
            setLed(((n+s-j)*(n+s-j)/20)%36);
        }

        _delay_ms(20);
    }
    setLed(LED_ALL_OFF);
}
