/*
 * function: func_021BA3E8
 * address:  0x021BA3E8
 * packet:   pkt_ov217_021BA3E8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C29F8  0x021C29F8  thumb  ov217
 *   d_021C3008  0x021C3008  data  a4
 *   d_021C3004  0x021C3004  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

extern void func_021C29F8(u8 *p, u32 b, u16 c);
extern u8 d_021C3008[];
extern u8 d_021C3004[];

void func_021BA3E8(char *self, int i)
{
    func_021C29F8(*(void **)(self + i * 4 + 0x38),
                  *(u32 *)(d_021C3004 + i * 0x14),
                  *(u16 *)(d_021C3008 + i * 0x14));
}
