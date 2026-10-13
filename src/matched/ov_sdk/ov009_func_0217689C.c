/*
 * function: DWCi_AutoSuspendComplete
 * address:  0x0217689C
 * packet:   pkt_ov009_0217689C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AutoSuspendComplete (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   DWCi_SuspendComplete  0x021768EC  arm  ov009
 */

extern int func_02175F3C(void);
extern int DWC_GetAIDBitmap(void);
extern void DWCi_SuspendComplete(int result);

void DWCi_AutoSuspendComplete(void)
{
    if (*(int *)(func_02175F3C() + 0x2c) == 0xff)
        return;
    if (*(int *)(func_02175F3C() + 0x2c) == 1)
        *(unsigned int *)(func_02175F3C() + 0x1c) = DWC_GetAIDBitmap();
    else
        *(unsigned int *)(func_02175F3C() + 0x1c) = 0;
    DWCi_SuspendComplete(0);
}
