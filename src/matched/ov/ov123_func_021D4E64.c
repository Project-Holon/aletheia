/*
 * function: func_021D4E64
 * address:  0x021D4E64
 * packet:   pkt_021D4E64
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4E34  0x021D4E34  thumb
 *   func_020452E8  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04495.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void func_021D4E34(u8 *p);
extern u32 func_020452E8(struct Descriptor *d);

void func_021D4E64(u8 *p)
{
    func_021D4E34(p);
    func_020452E8(((struct Obj04495 *)p)->f224);
    *(u32 *)&((struct Obj04495 *)p)->f224 = 0;
}
