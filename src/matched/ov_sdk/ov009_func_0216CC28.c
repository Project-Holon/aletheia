/*
 * function: func_0216CC28
 * address:  0x0216CC28
 * packet:   pkt_0216CC28
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by
 * func_02175F3C(), every field through a fresh getter call.  The +0x5f0/+0x5f4
 * pair is the one place a local reuses one getter result.
 *
 * symbols:
 *   func_02175F1C  0x02175F1C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_0217601C  0x0217601C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_02173B18  0x02173B18  arm  ov009
 *   func_0216F388  0x0216F388  arm  ov009
 */

extern void  func_02175F1C(int a0);
extern int func_02175F3C(void);
extern void  func_02175F4C(int a0);
extern void  func_02082BCC(void *p, int v, int n);
extern void  func_0217601C(void);
extern void  func_0217653C(void);
extern void  func_02173B18(void);
extern int   func_0216F388(int a0);

int func_0216CC28(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    char *q;

    func_02175F1C(a0);
    *(int *)(func_02175F3C() + 0x0) = a1;
    *(int *)(func_02175F3C() + 4) = a2;
    *(int *)(func_02175F3C() + 8) = a3;
    *(int *)(func_02175F3C() + 0x10) = 0;
    *(int *)(func_02175F3C() + 0x5d8) = 0;
    *(unsigned short *)(func_02175F3C() + 0x5d4) = 0;
    *(int *)(func_02175F3C() + 0x5e0) = 0;
    func_02175F4C(0);
    *(char *)(func_02175F3C() + 0x19) = 0;
    *(int *)(func_02175F3C() + 0x678) = 0;
    *(int *)(func_02175F3C() + 0x684) = a4;
    *(int *)(func_02175F3C() + 0x688) = a5;
    *(int *)(func_02175F3C() + 0x68c) = a6;
    *(int *)(func_02175F3C() + 0x690) = a7;
    func_02082BCC((void *)(func_02175F3C() + 0x694), 0, 0x40);
    *(int *)(func_02175F3C() + 0x6d4) = 0;
    *(int *)(func_02175F3C() + 0x770) = 0;
    *(int *)(func_02175F3C() + 0x774) = 0;
    *(int *)(func_02175F3C() + 0x780) = 0;
    *(int *)(func_02175F3C() + 0x784) = 0;
    *(int *)(func_02175F3C() + 0x788) = 0;
    *(int *)(func_02175F3C() + 0x78c) = 0;
    *(int *)(func_02175F3C() + 0x790) = 0;
    *(char *)(func_02175F3C() + 0x794) = 0;
    *(int *)(func_02175F3C() + 0x798) = 0;
    *(char *)(func_02175F3C() + 0x15) = 0;
    *(char *)(func_02175F3C() + 0x16) = 0;
    q = (char *)func_02175F3C();
    *(int *)(q + 0x5f0) = 0;
    *(int *)(q + 0x5f4) = 0;
    *(int *)(func_02175F3C() + 0x7c8) = 0;
    *(int *)(func_02175F3C() + 0x7d4) = 1;
    *(char *)(func_02175F3C() + 0x7b5) = 0;
    *(char *)(func_02175F3C() + 0x7b6) = 0;
    *(int *)(func_02175F3C() + 0x7b0) = 0;
    func_0217601C();
    func_0217653C();
    func_02173B18();
    return func_0216F388(0);
}
