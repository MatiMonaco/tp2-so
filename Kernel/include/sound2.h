#ifndef _SOUND_H
#define _SOUND_H

#include <time.h>
#include <stdint.h>

#define PIT_3_PORT 0x42
#define PIT_CONFIGURE_PORT 0x43
#define NOT_KEYBOARD_PORT 0x61

void soundOn(int frec);
void soundOff();
void beep();
