/*
 * function: PARTICLE_SetupSystemBorrowed
 * address:  0x02051360
 * packet:   pkt_02051230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PARTICLE_SetupSystemBorrowed.c \
 *       --func PARTICLE_SetupSystemBorrowed --addr 0x02051360 --cc 1.1p1 --arm
 *
 * symbols:
 *   PARTICLE_SetupSystem  0x02051230  arm
 */
#include "../include/Obj02319.h"

typedef unsigned short u16;

extern void PARTICLE_SetupSystem(void *p, unsigned int a1, unsigned int a2, unsigned int a3);

void PARTICLE_SetupSystemBorrowed(void *p, unsigned int a1, unsigned int a2, unsigned int a3)
{
    PARTICLE_SetupSystem(p, a1, a2, a3);
    ((struct Obj02319 *)p)->f32 = (u16)((((struct Obj02319 *)p)->f32 & ~1) | 1);
}
