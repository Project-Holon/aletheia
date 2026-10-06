/*
 * function: func_021C4134
 * address:  0x021C4134
 * packet:   pkt_021C4134
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14182.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);

void func_021C4134(u8 *p)
{
    if (((struct Obj14182 *)p)->fC)
        func_02045808(((struct Obj14182 *)p)->fC);
    func_020307B0(p);
}
