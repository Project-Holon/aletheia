/*
 * function: BTLV_MCSS_AnimCallbackClearPending
 * address:  0x02201894
 * packet:   pkt_ov094_02201894
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_GetMcss  0x021F8694  thumb  ov094
 */
extern char *BTLV_EFFECT_GetMcss(void);

void BTLV_MCSS_AnimCallbackClearPending(int i)
{
    *(int *)(BTLV_EFFECT_GetMcss() + i * 0x5c + 0x4c) = 0;
}
