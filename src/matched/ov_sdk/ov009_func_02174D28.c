/*
 * function: func_02174D28
 * address:  0x02174D28
 * packet:   pkt_ov009_02174D28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QR2NatnegCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0217695C  0x0217695C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_0216FC34  0x0216FC34  arm  ov009
 *   func_02173EF8  0x02173EF8  arm  ov009
 */

typedef struct MatchCnt {
    unsigned char pad0[0x554];
    unsigned char f554[0x57C - 0x554];
    int f57C;
    unsigned char pad1[0x5F8 - 0x580];
    unsigned char f5F8;
    unsigned char pad2[0x5FC - 0x5F9];
    int f5FC;
    long long f600;
    unsigned char pad3[0x61C - 0x608];
    int f61C;
    unsigned char pad4[0x6D8 - 0x620];
    unsigned char f6D8;
} MatchCnt;

extern int func_0216BA08(void);
extern int func_02175F3C(void);
extern int func_0217695C(void);
extern void func_02175F4C(int status);
extern int func_0216FC34(int type, int cookie, void *param);
extern int func_02173EF8(int nnError);

void func_02174D28(int cookie)
{
    int nnError;

    if (func_0216BA08() == 0 && ((MatchCnt *)func_02175F3C())->f57C != 0)
        return;
    if (((MatchCnt *)func_02175F3C())->f61C == 1) {
        if (func_0217695C() == 0)
            return;
        func_02175F4C(5);
    } else if (((MatchCnt *)func_02175F3C())->f61C != 5 && ((MatchCnt *)func_02175F3C())->f61C != 14) {
        return;
    }
    if (cookie == ((MatchCnt *)func_02175F3C())->f5FC) {
        ((MatchCnt *)func_02175F3C())->f5F8++;
    } else {
        ((MatchCnt *)func_02175F3C())->f5F8 = 0;
        ((MatchCnt *)func_02175F3C())->f5FC = cookie;
    }
    ((MatchCnt *)func_02175F3C())->f600 = 0;
    nnError = func_0216FC34(1, cookie, ((MatchCnt *)func_02175F3C())->f554);
    if (func_02173EF8(nnError) != 0)
        return;
    ((MatchCnt *)func_02175F3C())->f6D8 = 0xFF;
}
