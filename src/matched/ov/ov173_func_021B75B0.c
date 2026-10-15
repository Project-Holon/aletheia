/*
 * function: POKE_SUMMARY_MAIN_ClearWindowWaitA
 * address:  0x021B75B0
 * packet:   pkt_021B75B0
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Extent runs long: 0x021B75BC is an unlabelled follower leaf, so EXACT*.
 *
 * symbols:
 *   POKE_SUMMARY_MAIN_ClearWindow  0x021B74D8  thumb  ov173
 */

extern void POKE_SUMMARY_MAIN_ClearWindow(char *p);

int POKE_SUMMARY_MAIN_ClearWindowWaitA(char *p)
{
    POKE_SUMMARY_MAIN_ClearWindow(p);
    return 1;
}
