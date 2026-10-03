/*
 * function: func_021C66A0
 * address:  0x021C66A0
 * packet:   pkt_ov136_021C66A0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B878        0x0204B878  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021C66A0(u8 *p, int i, u32 v)
{
    func_0204B878(*(void **)(p + i * 4 + 0x1F0), (u16)v);
}
