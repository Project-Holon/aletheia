/*
 * function: DUP_FITTING_ITEM_ListIsFull
 * address:  0x021BA18C
 * packet:   pkt_021BA18C
 * region:   ov133
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj14156.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int DUP_FITTING_ITEM_ListIsFull(char *p)
{
    return ((struct Obj14156 *)p)->f4 == ((struct Obj14156 *)p)->f6;
}
