/*
 * function: func_021753D8
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
 *   func_0216EB68  0x0216EB68  arm  ov009
 */

extern int func_02175F3C(void);
extern void func_0216EB68(int error, int code);

int func_021753D8(int ignoreError)
{
    if (ignoreError)
        return 1;
    if (*(unsigned char *)(func_02175F3C() + 0x15) != 3)
        *(unsigned char *)(func_02175F3C() + 0x5f9) += 1;
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 3 || *(int *)(func_02175F3C() + 0x798) != 0 || *(unsigned char *)(func_02175F3C() + 0x5f9) >= 5) {
        func_0216EB68(6, -86420);
        return 0;
    }
    return 1;
}
