/*
 * function: func_021BD878
 * address:  0x021BD878
 * packet:   pkt_021BD878
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Clears the word at +0x34.
 */


void func_021BD878(char *p)
{
    *(int *)(p + 0x34) = 0;
}

