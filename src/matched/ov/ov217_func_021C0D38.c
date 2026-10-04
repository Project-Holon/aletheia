/*
 * function: func_021C0D38
 * address:  0x021C0D38
 * packet:   pkt_ov217_021C09D8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled 22-byte ov217 leaf in a .word run; tail-calls func_021C29F8 with
 * two ov217 data-table loads indexed by i*0x14.  Middle of the
 * func_021BA31C blocker chain.
 *
 * symbols:
 *   func_021C29F8  0x021C29F8  thumb  ov217
 *   d_021C3F5C     0x021C3F5C  data   a4
 *   d_021C3F60     0x021C3F60  data   a1
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern u8 d_021C3F5C[];
extern u8 d_021C3F60[];

void func_021C0D38(u8 *p, u32 i)
{
    func_021C29F8((u8 *)(*(u32 *)(p + i * 4 + 0x2c)),
                  *(u32 *)(d_021C3F5C + i * 0x14),
                  *(u16 *)(d_021C3F60 + i * 0x14));
}
