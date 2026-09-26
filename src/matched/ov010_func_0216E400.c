/*
 * function: func_0216E400
 * address:  0x0216E400
 * packet:   pkt_0216E400
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021D5E04  0x021D5E04  data  ov093  a4
 *
 * note: the parked file gave no overlay hint; un-hinted, sole-ref/data saw
 * data at 0x021D5E04 in several overlapping overlays and refused.  ov093 is
 * the one overlay where it is a data object start, so the hint fixes the
 * choice and the site resolves as sole-ref/data.
 */

typedef unsigned int u32;

extern u32 d_021D5E04[];

u32 func_0216E400(int i)
{
    return d_021D5E04[i];
}
