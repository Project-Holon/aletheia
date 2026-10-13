/*
 * function: DWCi_SetMatchCommonParam
 * address:  0x0216F5FC
 * packet:   pkt_ov009_0216F5FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetMatchCommonParam (dwc_match.o)
 *
 * symbols:
 *   func_0216F388  0x0216F388  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern void func_0216F388(int flag);
extern char *func_02175F3C(void);

void DWCi_SetMatchCommonParam(unsigned char matchType, unsigned char numEntry, void *callback, void *param)
{
    func_0216F388(0);
    *(unsigned char *)(func_02175F3C() + 0x14) = matchType;
    *(unsigned char *)(func_02175F3C() + 0x17) = numEntry;
    *(void **)(func_02175F3C() + 0x770) = callback;
    *(void **)(func_02175F3C() + 0x774) = param;
    *(unsigned char *)(func_02175F3C() + 0x5f9) = 0;
    *(int *)(func_02175F3C() + 0x2c) = 0xff;
    *(unsigned char *)(func_02175F3C() + 0x30) = 0;
    *(unsigned char *)(func_02175F3C() + 0x16) = 0;
    *(unsigned char *)(func_02175F3C() + 0x7a8) = 1;
    *(int *)(func_02175F3C() + 0x7ac) = 0;
    *(unsigned char *)(func_02175F3C() + 0x17) = numEntry;
    *(int *)(func_02175F3C() + 0x1c) = 0;
    *(int *)(func_02175F3C() + 0x28) = 0;
    *(unsigned long long *)(func_02175F3C() + 0x20) = 0;
    *(int *)(func_02175F3C() + 0x48) = 0;
    *(int *)(func_02175F3C() + 0x7c4) = 1;
    *(unsigned long long *)(func_02175F3C() + 0x7cc) = 0;
    *(int *)(func_02175F3C() + 0x634) = 0;
}
