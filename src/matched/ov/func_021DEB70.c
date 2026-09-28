/*
 * function: func_021DEB70
 * address:  0x021DEB70
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Tail wrapper: builds the 6-argument NitroSystem call with the
 *   two stack words 0x20 and 0x4c; third argument shifted left 5.
 */


extern void func_02049B40(int, int, int, int, int, int);
void func_021DEB70(int a, int b, int c)
{
    func_02049B40(0x74, b + 0x26, 0, c << 5, 0x20, 0x4c);
}
