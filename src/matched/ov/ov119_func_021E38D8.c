/*
 * function: POKETRADE_3D_SetToonEdgeColors
 * address:  0x021E38D8
 * packet:   pkt_021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Program the two register bits selected by the two flags.
 *
 * symbols:
 *   (none)
 */

void POKETRADE_3D_SetToonEdgeColors(int a, int b)
{
    *(volatile unsigned int *)0x040004c0 = 0x6b5a5ef7 | ((a != 0) << 15);
    *(volatile unsigned int *)0x040004c4 = 0x00007fff | ((b != 0) << 15);
}

