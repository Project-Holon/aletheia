/*
 * function: func_021C3354
 * address:  0x021C3354
 * packet:   pkt_021C3354
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Posts message 0x17 with the halfword at +0 as its last argument.
 */


extern void func_02049B90(int, int, int, int, int, int, int);

void func_021C3354(unsigned short *p)
{
    func_02049B90(0x17, 5, 0, 0, 0x20, 0x20, *p);
}

