/*
 * function: func_02188CFC
 * address:  0x02188CFC
 * packet:   pkt_ov021_02188CFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   data_021D35A8  0x021D35A8  data
 *   func_021A6DC0  0x021A6DC0  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00020.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern const u8 data_021D35A8[];
extern u32 func_021A6DC0(u8 *p);

u32 func_02188CFC(u8 *p)
{
    u32 r;
    u32 k = data_021D35A8[**(u32 * *)&((struct Obj00020 *)p)->f108];

    if (k == 2)
        k = func_021A6DC0(((struct Obj00020 *)p)->f10C);
    r = k;
    return r;
}
