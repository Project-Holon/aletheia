/*
 * function: func_0217689C
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
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_021768EC  0x021768EC  arm  ov009
 */

extern char *func_02175F3C(void);
extern unsigned int func_0216B908(void);
extern void func_021768EC(int result);

void func_0217689C(void)
{
    if (*(int *)(func_02175F3C() + 0x2c) == 0xff)
        return;
    if (*(int *)(func_02175F3C() + 0x2c) == 1)
        *(unsigned int *)(func_02175F3C() + 0x1c) = func_0216B908();
    else
        *(unsigned int *)(func_02175F3C() + 0x1c) = 0;
    func_021768EC(0);
}
