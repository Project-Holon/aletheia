/*
 * function: FLDMMDL_GetDrawProcList
 * address:  0x0216E40C
 * packet:   pkt_0216E40C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021D770C  0x021D770C  data  ov021  a4
 *
 * note: the parked file gave no overlay hint; un-hinted, sole-ref saw data at
 * 0x021D770C in several overlapping overlays and refused.  ov021 is the
 * pointer-table home of the word (the ov021 datum is 0x021D86C0), so the hint
 * fixes the choice and the site resolves as sole-ref/self.
 */

typedef unsigned int u32;

extern u32 d_021D770C[];

u32 FLDMMDL_GetDrawProcList(int i)
{
    return d_021D770C[i];
}
