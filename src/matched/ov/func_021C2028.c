/*
 * function: WIFICLUB_SetSlotState
 * address:  0x021C2028
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte setter at index i of the 0x8CB table, then sets the byte at +0x8F1.
 */
#include "../include/Obj18285.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

void WIFICLUB_SetSlotState(char *p, int i, u8 v)
{
    *(u8 *)(p + i + 0x8CB) = v;
    ((struct Obj18285 *)p)->f8F1 = 1;
}
