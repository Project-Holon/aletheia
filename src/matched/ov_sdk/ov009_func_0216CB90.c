/*
 * function: DWC_GetSuspendMatch
 * address:  0x0216CB90
 * packet:   pkt_ov009_0216CB90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_GetSuspendMatch (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   DWCi_IsServerSuspendEnabled  0x02175EB4  arm  ov009
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 */

extern int func_02175F3C(void);
extern unsigned char func_02175FB8(void);
extern int DWC_GetAIDBitmap(void);
extern int DWCi_IsServerSuspendEnabled(void);
extern unsigned char DWC_GetMyAID(void);

int DWC_GetSuspendMatch(void)
{
    int bNew = -1;
    unsigned int bitmap;

    if (!func_02175F3C())
        return 0;
    if (!func_02175FB8())
        return 0;
    bitmap = *(unsigned int *)(func_02175F3C() + 0x1c);
    bitmap &= DWC_GetAIDBitmap();
    if (!DWCi_IsServerSuspendEnabled())
        bitmap &= ~(1 << DWC_GetMyAID());
    if ((bitmap ^ DWC_GetAIDBitmap()) == 0)
        bNew = 1;
    else if ((bitmap & DWC_GetAIDBitmap()) == 0)
        bNew = 0;
    if (bNew != -1)
        *(int *)(func_02175F3C() + 0x28) = bNew == 1;
    return *(int *)(func_02175F3C() + 0x28);
}
