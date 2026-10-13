/*
 * function: BTLV_SCU_IsMonDamageAnimDone
 * address:  0x021ED250
 * packet:   pkt_ov093_021ED250
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F8180  0x021F8180  thumb  ov094
 */
extern int func_021F7EB4(void);
extern int func_021F8180(void);
int BTLV_SCU_IsMonDamageAnimDone(void)
{
    int a = func_021F7EB4();
    if ((func_021F8180() | a) == 0)
        return 1;
    return 0;
}
