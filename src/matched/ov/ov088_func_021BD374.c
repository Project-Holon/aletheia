/*
 * function: func_021BD374
 * address:  0x021BD374
 * packet:   pkt_ov088_021BD374
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in a .word run at ov088:021BD374.  The caller
 * func_021BE6E8 lives in ov204 (0x021BDA40..), which does not overlap ov088
 * (0x021B95A0..0x021BDA20), the only overlay in the window that its own
 * window does not overlap, so ov088 is the resident copy.
 */

void func_021BD374(unsigned char *p)
{
    if (p[4] != 3)
        p[6] = 0;
}
