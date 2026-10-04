/*
 * function: func_021BDF00
 * address:  0x021BDF00
 * packet:   pkt_021BDF00
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE0E0  0x021BE0E0  thumb  ov203
 *   func_021BE078  0x021BE078  thumb  ov203
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25309.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021BE0E0(u8 *);
extern void func_021BE078(u8 *);

void func_021BDF00(u8 *p)
{
    if (((struct Obj25309 *)p)->f14 == 0) {
        func_021BE0E0(p + 4);
        func_021BE078(p);
    }
}

