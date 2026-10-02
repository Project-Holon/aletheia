/*
 * function: func_021BB784
 * address:  0x021BB784
 * packet:   pkt_021BB784
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBB0C  0x021BBB0C  thumb
 *
 * blocker: target 0x021BBB0C is an unlabelled Thumb leaf in ov072 (labelled
 * only in the unrelated overlapping overlays ov110/ov225), so no `label`
 * branch and no `sole-ref/code` function start in ov072 attests it; the only
 * pool word naming it is this function's own. All 12 bytes and the relocation
 * field are right.
 
 *
 * UNBLOCKED: func_021BBB0C is now an EXACT entry in layout/matched/ov072;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

unsigned int func_021BBB0C(void *p, int n);

unsigned int func_021BB784(char *p, int n)
{
    return func_021BBB0C(p + 4, n);
}
