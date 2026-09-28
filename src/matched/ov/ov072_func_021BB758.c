/*
 * function: func_021BB758
 * address:  0x021BB758
 * packet:   pkt_021BB758
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BBAFC  0x021BBAFC  thumb
 *
 * blocker: target 0x021BBAFC is an unlabelled Thumb leaf (a `ldr r3,[pc,#0];
 * bx r3` veneer followed by its own pool) in ov072, so no `label` branch and
 * no `sole-ref/code` function start attests it; the only pool word naming it
 * is this function's own. All 12 bytes and the relocation field are right.
 
 *
 * UNBLOCKED: func_021BBAFC is now an EXACT entry in layout/matched/ov072;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

void func_021BBAFC(char *);

void func_021BB758(char *p)
{
    func_021BBAFC(p + 4);
}
