/*
 * function: BTLV_MCSS_MakeAddWorkFromTrainer
 * address:  0x022006A0
 * packet:   pkt_ov094_022006A0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call stub: forwards (p, out) and passes !(flags & 1) as the third
 * argument of MCSS_TOOL_MakeAddWorkFromTrainer.
 *
 * symbols:
 *   MCSS_TOOL_MakeAddWorkFromTrainer  0x02017214  thumb
 */
struct Stats;
extern void MCSS_TOOL_MakeAddWorkFromTrainer(void *p, struct Stats *out, void *q);

void BTLV_MCSS_MakeAddWorkFromTrainer(void *p, void *out, int flags)
{
    MCSS_TOOL_MakeAddWorkFromTrainer(p, out, (void *)((flags & 1) == 0));
}
