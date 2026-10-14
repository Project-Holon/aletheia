/*
 * function: GURU2_MAIN_AddPulseEffect
 * address:  0x021E14CC
 * packet:   pkt_021E14CC
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14251.h"
#include "../include/Obj23800.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void GURU2_MAIN_AddPulseEffect(char *p, char *q)
{
    char *r = p + 0xC90 + ((struct Obj23800 *)q)->fC * 0x10;

    ((struct Obj14251 *)r)->f0 = 1;
    *(char * *)&((struct Obj14251 *)r)->fC = q;
}
