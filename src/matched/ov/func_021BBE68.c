/*
 * function: func_021BBE68
 * address:  0x021BBE68
 * packet:   pkt_021BBE68
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202822C  0x0202822C  thumb
 *
 * UNBLOCKED: 0x0202822C now has an EXACT entry in layout/matched/arm9
 * (pkt_0202822C.json, filed separately); the call site resolves as matched,
 * verdict promoted to EXACT.
 */

void func_0202822C(int);

void func_021BBE68(int x)
{
    if (x != 0)
        func_0202822C(x);
}
