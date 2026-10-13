/*
 * function: BTL_SERVER_AddMainCounter
 * address:  0x021BB908
 * packet:   pkt_021BB908
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_AddBonusMoney  0x021B91E4  thumb  ov093
 *
 * blocker: target 0x021B91E4 is unlabelled in ov093 and in all 11 overlapping
 * overlays, with no outside branch; the pool relocation has no witness.
 * All bytes correct.
 
 *
 * UNBLOCKED: BTL_MAIN_AddBonusMoney is now an EXACT entry in layout/matched/ov093;
 * the call site resolves as matched, verdict promoted to EXACT.
*/

void BTL_MAIN_AddBonusMoney(void *p, int add);

void BTL_SERVER_AddMainCounter(int *p, int add)
{
    BTL_MAIN_AddBonusMoney((void *)p[3], add);
}
