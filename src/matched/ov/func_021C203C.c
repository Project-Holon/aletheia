/*
 * function: WIFICLUB_ClearSlotState
 * address:  0x021C203C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the byte at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */
#include "../include/Obj18286.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void WIFICLUB_ClearSlotState(char *p, int i)
{
    *(u8 *)(p + i + 0x8CB) = 0;
    ((struct Obj18286 *)p)->f8F1 = 1;
}
