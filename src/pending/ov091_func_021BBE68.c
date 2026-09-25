/*
 * function: func_021BBE68
 * address:  0x021BBE68
 * packet:   pkt_021BBE68
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0202822C  0x0202822C  thumb
 *
 * blocker: target 0x0202822C has no `func_`/`sub_` label in the listings
 * (no witness at all), and no branch outside this 12-byte range reaches it,
 * so the `bl` site cannot be resolved.  All bytes are correct.
 */

void func_0202822C(int);

void func_021BBE68(int p)
{
    if (p) {
        func_0202822C(p);
    }
}
