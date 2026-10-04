/*
 * function: func_021A02C4
 * address:  0x021A02C4
 * packet:   pkt_ov021_021A02C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   d_021DDE28     0x021DDE28  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12697.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern char d_021DDE28[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, u16 heap);

u8 *func_021A02C4(u16 heap)
{
    u8 *p = (u8 *)func_02030734(heap, 0x10, 1, d_021DDE28, 0x51);
    ((struct Obj12697 *)p)->f8 = 0x0FFFFFFF;
    ((struct Obj12697 *)p)->fC = func_020490F4(0x51, heap);
    return p;
}
