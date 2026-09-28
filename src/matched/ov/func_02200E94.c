/*
 * function: func_02200E94
 * address:  0x02200E94
 * packet:   pkt_02200E94
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02202940  0x02202940  thumb  ov135

 * Tear down the +0xfa0 sub-object, then release the +0xd40 resource.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_02202940(u8 *p);
extern void func_020452E8(u32 v);

void func_02200E94(u8 *p)
{
    func_02202940(p + 0xfa0);
    func_020452E8(*(u32 *)(p + 0xd40));
}
