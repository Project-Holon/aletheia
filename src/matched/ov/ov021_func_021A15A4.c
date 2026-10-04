/*
 * function: func_021A15A4
 * address:  0x021A15A4
 * packet:   pkt_ov021_021A15A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDE5C     0x021DDE5C  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06005.h"
#include "../include/Obj07489.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern char d_021DDE5C[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

u8 *func_021A15A4(u8 *p, u32 heap)
{
    u8 *q = (u8 *)func_02030734((u16)heap, 0x70, 1, d_021DDE5C, 0x95);
    ((struct Obj06005 *)q)->f0 = ((struct Obj07489 *)p)->f0;
    ((struct Obj06005 *)q)->f2 = ((struct Obj07489 *)p)->f2;
    ((struct Obj06005 *)q)->f4 = ((struct Obj07489 *)p)->f4;
    q[0x1e] = p[8];
    ((struct Obj06005 *)q)->f8 = 1;
    return q;
}
