/*
 * function: POKE_SUMMARY_MAIN_ClearWindowWaitB
 * address:  0x021B75C8
 * packet:   pkt_021B75C8
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Extent runs long: 0x021B75D4 is an unlabelled follower leaf, so EXACT*.
 *
 * symbols:
 *   POKE_SUMMARY_MAIN_ClearWindow  0x021B74D8  thumb  ov173
 */

extern void POKE_SUMMARY_MAIN_ClearWindow(char *p);

int POKE_SUMMARY_MAIN_ClearWindowWaitB(char *p)
{
    POKE_SUMMARY_MAIN_ClearWindow(p);
    return 1;
}
