/*
 * function: func_02175698
 * address:  0x02175698
 * packet:   pkt_ov009_02175698
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ConnectToGameServerAsync_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0219EC74  0x0219EC74  arm  ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_02174058  0x02174058  arm  ov009
 */

typedef struct MatchCnt {
    unsigned char pad0[0x14];
    unsigned char f14;
    unsigned char pad1[0x554 - 0x15];
    int f554;
    unsigned char pad2[0x5E0 - 0x558];
    int f5E0;
    unsigned char pad3[0x684 - 0x5E4];
    int f684;
    int f688;
} MatchCnt;

extern int func_02175F3C(void);
extern int func_0219EC74(int a, int b, int c, int d, int e, int f, int g, void (*cb)(void), int h);
extern int func_02173D9C(int err);
extern void func_02175F4C(int status);
extern int func_021719D0(int a, int b);
extern int func_021719A4(int error);
extern void func_02174058(void *sb, int reason, void *server);

void func_02175698(void)
{
    int result;

    ((MatchCnt *)func_02175F3C())->f14 = 3;
    if (((MatchCnt *)func_02175F3C())->f5E0 == 0) {
        ((MatchCnt *)func_02175F3C())->f5E0 = func_0219EC74(((MatchCnt *)func_02175F3C())->f684, ((MatchCnt *)func_02175F3C())->f684,
                                              ((MatchCnt *)func_02175F3C())->f688, 0, 20, 1, 0,
                                              (void (*)(void))func_02174058, 0);
    }
    if (((MatchCnt *)func_02175F3C())->f5E0 == 0) {
        if (func_02173D9C(5))
            return;
    }
    func_02175F4C(3);
    result = func_021719D0(((MatchCnt *)func_02175F3C())->f554, 0);
    func_021719A4(result);
}
