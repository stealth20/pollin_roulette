#include "avr/io.h"

#define SPEAKER_PIN     PB2

void beep_init(void);
void beep(uint8_t type);
