/*
 * function: func_02172A58
 * address:  0x02172A58
 * packet:   pkt_ov009_02172A58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FinishCancelMatch (dwc_match.o)
 *
 * symbols:
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 *   func_0216F6C0  0x0216F6C0  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02169038  0x02169038  arm  ov009
 */

extern int func_0216F20C(int status);
extern int func_02173D28(int gpResult);
extern void func_0216F6C0(void);
extern char *func_02175F3C(void);
extern int func_02169038(int profileID);

void func_02172A58(void)
{
    int gpResult;
    int a = 1;
    int b;

    gpResult = func_0216F20C(a);
    if (func_02173D28(gpResult))
        return;
    func_0216F6C0();
    if (*(int *)(func_02175F3C() + 0x680) == 0) {
        if (*(unsigned char *)(func_02175F3C() + 0x14) != 2)
            a = 0;
    }
    b = *(int *)(func_02175F3C() + 0x680) == 0;
    {
        char *m = func_02175F3C();

        (*(int (**)(int, int, int, int, int, int))(m + 0x770))(0, 1, b, a, func_02169038(*(int *)(func_02175F3C() + 0x680)), *(int *)(func_02175F3C() + 0x774));
    }
    *(unsigned char *)(func_02175F3C() + 0x62a) = 0;
}
