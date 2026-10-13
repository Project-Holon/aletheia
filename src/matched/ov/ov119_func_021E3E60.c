/*
 * function: func_021E3E60
 * address:  0x021E3E60
 * packet:   pkt_ov119_021E3E60
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_InitSystem  0x0204A48C  arm
 *   d_021E7CC8     0x021E7CC8  data  ov119  a4
 *   d_021E7D40     0x021E7D40  data  ov119  a4
 *
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of func_021DFDA0's preamble.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22800.h"

typedef unsigned short u16;

extern int d_021E7CC8;
extern int d_021E7D40;
typedef unsigned int   u32;
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);

void func_021E3E60(void *p)
{
    CLACT_InitSystem((const struct Cfg *)(&d_021E7CC8), (u32)(&d_021E7D40), ((struct Obj22800 *)p)->f5F4);
}
