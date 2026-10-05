/*
 * function: func_021DEB70
 * address:  0x021DEB70
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *
 * Tail wrapper: builds the 6-argument NitroSystem call with the
 *   two stack words 0x20 and 0x4c; third argument shifted left 5.
 */


typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021DEB70(int a, int b, int c)
{
    func_02049B40(0x74, b + 0x26, 0, c << 5, 0x20, 0x4c);
}
