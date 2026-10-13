/*
 * function: BTLV_SCU_IsMonMotionDone
 * address:  0x021ED280
 * packet:   pkt_ov093_021ED280
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 */
extern int func_021F7EB4(void);
int BTLV_SCU_IsMonMotionDone(char *p)
{
    if (func_021F7EB4() == 0)
        return 1;
    return 0;
}
