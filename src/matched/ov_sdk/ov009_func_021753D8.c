/*
 * function: DWCi_ProcessNNFailure
 * address:  0x021753D8
 * packet:   pkt_ov009_021753D8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessNNFailure (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_StopMatch  0x0216EB68  arm  ov009
 */

extern int func_02175F3C(void);
extern void DWCi_StopMatch(int error, int code);

int DWCi_ProcessNNFailure(int ignoreError)
{
    if (ignoreError)
        return 1;
    if (*(unsigned char *)(func_02175F3C() + 0x15) != 3)
        *(unsigned char *)(func_02175F3C() + 0x5f9) += 1;
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 3 || *(int *)(func_02175F3C() + 0x798) != 0 || *(unsigned char *)(func_02175F3C() + 0x5f9) >= 5) {
        DWCi_StopMatch(6, -86420);
        return 0;
    }
    return 1;
}
