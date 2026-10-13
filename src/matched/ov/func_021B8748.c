/*
 * function: BTL_MAIN_GetGameData
 * address:  0x021B8748
 * packet:   pkt_021B8748
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MAIN_GetGameData   0x021B8748  thumb ov093
 *
 * double deref: *(u32*)(*p + 0x58)
 */
#include "../include/Obj18131.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u32 BTL_MAIN_GetGameData(void **p)
{
    return ((struct Obj18131 *)((u8 *)*p))->f58;
}
