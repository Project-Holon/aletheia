/*
 * function: func_0218FF20
 * address:  0x0218FF20
 * packet:   pkt_ov021_0218FF20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02190000  0x02190000  thumb
 */
#include "../include/Obj04204.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02190000(u32 *p);

void func_0218FF20(u8 *a, u32 a1, u32 a2, u32 a3)
{
    if (((struct Obj04204 *)a)->fC != 0)
        func_02190000((u32 *)a);
}
