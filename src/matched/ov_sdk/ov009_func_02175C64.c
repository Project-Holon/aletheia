/*
 * function: func_02175C64
 * address:  0x02175C64
 * packet:   pkt_ov009_02175C64
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RequestSuspendMatchProcess (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175BFC  0x02175BFC  arm  ov009
 *   func_0216CB90  0x0216CB90  arm  ov009
 *   func_021768EC  0x021768EC  arm  ov009
 *   func_02175D10  0x02175D10  arm  ov009
 */

extern int func_02175F3C(void);
extern void func_02175BFC(int suspend, void *callback, void *param);
extern int func_0216CB90(void);
extern void func_021768EC(int result);
extern int func_02175D10(int suspend);

int func_02175C64(void)
{
    int ret;
    int suspend;

    if (*(int *)(func_02175F3C() + 0x48) == 0)
        return 0;
    if (*(int *)(func_02175F3C() + 0x44) != 0) {
        func_02175BFC(*(int *)(func_02175F3C() + 0x2c), *(void **)(func_02175F3C() + 0x34), *(void **)(func_02175F3C() + 0x38));
        *(int *)(func_02175F3C() + 0x44) = 0;
    }
    suspend = *(int *)(func_02175F3C() + 0x2c);
    if (suspend == 0xff)
        return 0;
    ret = func_0216CB90();
    if ((suspend != 0 && ret != 0) || (suspend == 0 && ret == 0)) {
        func_021768EC(0);
        return 1;
    }
    func_02175D10(suspend);
    return 1;
}
