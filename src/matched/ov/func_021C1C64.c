/*
 * function: WIFICLUB_GetSelectedSlotPlusOne
 * address:  0x021C1C64
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte getter 0x8ED bytes into the block.
 */
#include "../include/Obj18283.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

u8 WIFICLUB_GetSelectedSlotPlusOne(char *p)
{
    return ((struct Obj18283 *)p)->f8ED;
}
