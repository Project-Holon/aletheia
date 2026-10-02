/*
 * function: func_021EE200
 * address:  0x021EE200
 * packet:   pkt_ov093_021EE200
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EF694  0x021EF694  thumb  ov093
 *   func_021ECEB8  0x021ECEB8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021EF694(u32 a, u16 b);
extern void func_021ECEB8(u8 *, u32, u16, u32);

void func_021EE200(u8 *p)
{
    func_021EF694(*(u32 *)(p + 0x34), 0xf);
    func_021ECEB8(p, *(u32 *)(p + 0x34), 0, 0);
}
