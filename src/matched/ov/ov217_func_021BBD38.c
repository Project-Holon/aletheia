/*
 * function: func_021BBD38
 * address:  0x021BBD38
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field setter, u8 at +0x32.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25854.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BBD38(void *p, u8 v)
{
    ((struct Obj25854 *)p)->f32 = v;
}
