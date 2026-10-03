/*
 * function: func_021735A4
 * address:  0x021735A4
 * packet:   pkt_ov009_021735A4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SendTypeMatchAck (dwc_match.o)
 *
 * symbols:
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02173064  0x02173064  arm  ov009
 *   func_02176554  0x02176554  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 */

extern unsigned char func_02175FB8(void);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern void func_02173064(int aid, int type);
extern int func_02176554(void);
extern int func_02175F3C(void);
extern void func_02175F4C(int status);

void func_021735A4(void)
{
    int i;

    if (func_02175FB8() != 2)
        return;
    for (i = 1; i < func_0217603C(); i++)
        func_02173064(*(unsigned char *)(func_0217637C(i) + 0x16), 4);
    if (func_02176554())
        func_02173064(*(unsigned char *)(func_02175F3C() + 0x56a), 4);
    func_02175F4C(20);
}
