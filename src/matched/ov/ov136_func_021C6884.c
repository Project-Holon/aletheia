/*
 * function: func_021C6884
 * address:  0x021C6884
 * packet:   pkt_ov136_021C6884
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C66A0 0x021C66A0 thumb
 *   func_021C66CC 0x021C66CC thumb
 */

typedef unsigned char u8;
extern void func_021C66CC(u8 *, int, int, int);
typedef unsigned int   u32;
extern void func_021C66A0(u8 *p, int i, u32 v);
void func_021C6884(u8 *p)
{
    func_021C66CC(p, 2, 0xE0, 0xB0);
    func_021C66A0(p, 2, 4);
}
