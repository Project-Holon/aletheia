/*
 * function: func_021C9B78
 * address:  0x021C9B78
 * packet:   pkt_ov021_021C9B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Remaps kind 2/7 to 3/8, pushes it to the +0x70 object and refreshes the +0xe counter from +0x74.
 *
 * symbols:
 *   func_0200D914  0x0200D914  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_021CA238  0x021CA238  thumb
 *   func_021CA250  0x021CA250  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03617.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Blk1AC;
struct Blk3C;
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern void func_021CA238(u8 *p, u16 v);
extern int func_021CA250(u32 a);

void func_021C9B78(u8 *p)
{
    u8 v;

    if (p[9] == 2)
        v = 3;
    else if (p[9] == 7)
        v = 8;
    p[9] = v;
    func_0200D914((struct Blk3C *)(((struct Obj03617 *)p)->f70), 0, &v);
    if (func_0200DB44((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]) == 1)
        func_021CA238(p, func_0200DAC4((struct Blk1AC *)(((struct Obj03617 *)p)->f74), p[9]));
    else
        func_021CA250((u32)p);
}
