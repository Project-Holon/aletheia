/*
 * function: BTLV_EFFECT_IsRecordEnabledInComm
 * address:  0x021F88F4
 * packet:   pkt_ov094_021F88F4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns BTL_MAIN_IsRecordEnabledInComm of the handle at 0x1e4 of the global work block, or 0 when it is null.
 *
 * symbols:
 *   gBtlvEff  0x0220AF20  data  ov094
 *   BTL_MAIN_IsRecordEnabledInComm 0x021BA1EC thumb ov093
 */
extern char *gBtlvEff;
extern int BTL_MAIN_IsRecordEnabledInComm(char **p);

int BTLV_EFFECT_IsRecordEnabledInComm(void)
{
    int r = 0;
    void *h = *(void **)(gBtlvEff + 0x1e4);
    if (h != 0)
        r = BTL_MAIN_IsRecordEnabledInComm(h);
    return r;
}
