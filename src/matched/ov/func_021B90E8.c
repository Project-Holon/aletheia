/*
 * function: BTL_MAIN_GetMyItem
 * address:  0x021B90E8
 * packet:   pkt_021B90E8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetMyItem   0x021B90E8  thumb ov093
 *
 * double deref: *(u32*)(*p + 0x60)
 */
#include "../include/Obj18134.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 BTL_MAIN_GetMyItem(void **p)
{
    return ((struct Obj18134 *)((u8 *)*p))->f60;
}
