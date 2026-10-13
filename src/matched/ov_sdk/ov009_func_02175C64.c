/*
 * function: DWCi_RequestSuspendMatchProcess
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
 *   DWCi_RequestSuspendMatchInit  0x02175BFC  arm  ov009
 *   DWC_GetSuspendMatch  0x0216CB90  arm  ov009
 *   DWCi_SuspendComplete  0x021768EC  arm  ov009
 *   func_02175D10  0x02175D10  arm  ov009
 */

extern int func_02175F3C(void);
extern void DWCi_RequestSuspendMatchInit(int suspend, void *callback, void *param);
extern int DWC_GetSuspendMatch(void);
extern void DWCi_SuspendComplete(int result);
extern int func_02175D10(int suspend);

int DWCi_RequestSuspendMatchProcess(void)
{
    int ret;
    int suspend;

    if (*(int *)(func_02175F3C() + 0x48) == 0)
        return 0;
    if (*(int *)(func_02175F3C() + 0x44) != 0) {
        DWCi_RequestSuspendMatchInit(*(int *)(func_02175F3C() + 0x2c), *(void **)(func_02175F3C() + 0x34), *(void **)(func_02175F3C() + 0x38));
        *(int *)(func_02175F3C() + 0x44) = 0;
    }
    suspend = *(int *)(func_02175F3C() + 0x2c);
    if (suspend == 0xff)
        return 0;
    ret = DWC_GetSuspendMatch();
    if ((suspend != 0 && ret != 0) || (suspend == 0 && ret == 0)) {
        DWCi_SuspendComplete(0);
        return 1;
    }
    func_02175D10(suspend);
    return 1;
}
