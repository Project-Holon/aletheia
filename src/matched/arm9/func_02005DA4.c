/*
 * function: GFL_USE_ChangeBgm
 * address:  0x02005DA4
 * packet:   pkt_02005DA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_BeginBgmChange  0x02005F70  thumb
 *
 * Wrapper that forwards all four arguments to GFL_USE_BeginBgmChange.  Seeded in
 * layout/function_starts.txt from its only caller, the bl at ov012
 * 0x021745D0 (w6_fix18).
 */

extern void GFL_USE_BeginBgmChange(unsigned int a, unsigned short b, int c, int d);

void GFL_USE_ChangeBgm(unsigned int a, unsigned short b, int c, int d)
{
    GFL_USE_BeginBgmChange(a, b, c, d);
}
