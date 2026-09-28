/*
 * function: func_021C0524
 * address:  0x021C0524
 * packet:   pkt_021C0524
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Releases each of the 0x3D handles held from +0xDC on.
 */


extern void func_0204B3B4(int);

void func_021C0524(int unused, char *p)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++)
        func_0204B3B4(*(int *)(p + i * 4 + 0xdc));
}

