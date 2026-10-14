/*
 * function: GURU2_MAIN_IsMemberFlagSet
 * address:  0x021E16C4
 * packet:   pkt_021E16C4
 * region:   ov137
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj01753.h"
#include "../include/Obj23803.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int GURU2_MAIN_IsMemberFlagSet(char *p, int mask)
{
    return (((struct Obj23803 *)(*(char * *)&((struct Obj01753 *)p)->fDC))->f40 & mask) != 0;
}
