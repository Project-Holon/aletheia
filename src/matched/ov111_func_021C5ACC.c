/*
 * function: func_021C5ACC
 * address:  0x021C5ACC
 * packet:   pkt_ov111_021C5ACC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040B1C  0x02040B1C  arm
 *   func_021C59DC  0x021C59DC  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_02040B1C(u8 index, const void *src, u32 size, u32 tile);
extern void func_021C59DC(u32 bg, int mode);

void func_021C5ACC(u32 bg, const void *src, int mode)
{
    func_02040B1C(bg, src, 0x3000, 1);
    func_021C59DC(bg, mode);
}
