/*
 * function: func_0203D864
 * address:  0x0203D864
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the net context's +0x2c and +0x1c words.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D864.c \
 *       --func func_0203D864 --addr 0x0203D864 --arm --cc 1.1p1
 */
#include "../include/Obj11380.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);

void func_0203D864(void)
{
    u8 *p = func_0203D788();

    if (p != 0) {
        ((struct Obj11380 *)p)->f2C = 0;
        ((struct Obj11380 *)p)->f1C = 0;
    }
}
