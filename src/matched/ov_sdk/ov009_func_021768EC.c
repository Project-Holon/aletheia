/*
 * function: func_021768EC
 * address:  0x021768EC
 * packet:   pkt_ov009_021768EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SuspendComplete (dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 */

extern char *func_02175F3C(void);
extern void func_0219B490(int status);

void func_021768EC(int result)
{
    if (*(void (**)(int, int, int))(func_02175F3C() + 0x34) != 0)
        (*(void (**)(int, int, int))(func_02175F3C() + 0x34))(result, *(int *)(func_02175F3C() + 0x2c), *(int *)(func_02175F3C() + 0x38));
    if (result == 0)
        func_0219B490(*(int *)(func_02175F3C() + 0x10));
    *(int *)(func_02175F3C() + 0x2c) = 0xff;
    *(int *)(func_02175F3C() + 0x48) = 0;
}
