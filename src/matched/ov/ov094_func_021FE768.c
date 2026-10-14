/*
 * function: BTLV_EFFVM_DelayTaskMain
 * address:  0x021FE768
 * packet:   pkt_ov094_021FE768
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StepScalarWithLimit  0x021F9220  thumb  ov094
 *   func_0200F698  0x0200F698  thumb
 *   BTLV_EFFECT_DeleteTask  0x021F89BC  thumb  ov094
 */
extern void BTLV_EFFECT_StepScalarWithLimit(int *p, int *d, int *lim, int *flag);
extern void func_0200F698(void *a, void *b);
extern void BTLV_EFFECT_DeleteTask(void *h);

void BTLV_EFFVM_DelayTaskMain(void *h, int *s)
{
    int flag = 1;

    BTLV_EFFECT_StepScalarWithLimit(&s[1], &s[3], &s[2], &flag);
    func_0200F698((void *)0xffff, (void *)(s[1] >> 12));
    if (flag)
        BTLV_EFFECT_DeleteTask(h);
}
