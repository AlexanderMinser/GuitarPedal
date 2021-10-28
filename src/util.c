#include "util.h"

/* spin for some amount of ticks */
void delay1(unsigned volatile int t) {
    for (unsigned volatile int i = 0; i < t; i++);
}