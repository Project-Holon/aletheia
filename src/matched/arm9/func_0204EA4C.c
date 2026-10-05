/*
 * function: func_0204EA4C
 * address:  0x0204EA4C
 * packet:   pkt_0204EA4C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the +8 word of the cell-actor singleton to 1.
 * Witness leaf for ov180 func_021B6704.
 *
 * symbols:
 *   g_02146A80 0x02146A80 data a4
 */

extern char *g_02146A80;

void func_0204EA4C(void)
{
    *(int *)(g_02146A80 + 8) = 1;
}
