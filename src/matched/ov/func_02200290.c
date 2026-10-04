/*
 * function: func_02200290
 * address:  0x02200290
 * packet:   pkt_02200290
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Tail call into func_0204B3B4 with the pointer held at +0xbf4.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_02200290(u8 *p)
{
    func_0204B3B4((struct Obj *)(*(u32 *)(p + 0xbf4)));
}
