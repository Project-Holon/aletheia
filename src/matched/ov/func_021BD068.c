/*
 * function: func_021BD068
 * address:  0x021BD068
 * packet:   pkt_021BD068
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00575.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct U16Vec;
extern void func_02045808(struct U16Vec *vec);

void func_021BD068(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f1C;
    if (v != 0) {
        func_02045808((struct U16Vec *)v);
        ((struct Obj00575 *)p)->f1C = 0;
    }
}
