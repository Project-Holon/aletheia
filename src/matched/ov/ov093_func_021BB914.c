/*
 * function: BTL_SERVER_FinishMainCounter
 * address:  0x021BB914
 * packet:   pkt_021BB914
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9234  0x021B9234  thumb  ov093
 *
 * blocker: target 0x021B9234 is unlabelled in ov093 and in all 11 overlapping
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 
 *
 * UNBLOCKED: func_021B9234 is now an EXACT entry in layout/matched/ov093;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

void func_021B9234(unsigned char *p);

void BTL_SERVER_FinishMainCounter(int *p)
{
    func_021B9234((unsigned char *)p[3]);
}
