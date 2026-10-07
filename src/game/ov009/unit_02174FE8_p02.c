/*
 * file:     unit_02174FE8_p02.c
 * unit:     yes
 * function: func_021755D4, func_02175698
 * address:  0x021755D4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175530  0x02175530  arm  ov009
 *   func_02176344  0x02176344  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 *   func_0219EC74  0x0219EC74  arm  ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_02174058  0x02174058  arm  ov009
 */
typedef struct MatchCnt_021755D4 {
    unsigned char pad0[0x14];
    unsigned char f14;
    unsigned char f15;
    unsigned char pad1[0x18 - 0x16];
    unsigned char f18;
    unsigned char pad2[0x5DC - 0x19];
    int f5DC;
    unsigned char pad3[0x67C - 0x5E0];
    int f67C;
    unsigned char pad4[0x790 - 0x680];
    int f790;
    unsigned char pad5[0x7C4 - 0x794];
    int f7C4;
} MatchCnt_021755D4;

typedef struct NodeInfo {
    unsigned char pad0[0x16];
    unsigned char f16;
} NodeInfo;

typedef struct MatchCnt_02175698 {
    unsigned char pad0[0x14];
    unsigned char f14;
    unsigned char pad1[0x554 - 0x15];
    int f554;
    unsigned char pad2[0x5E0 - 0x558];
    int f5E0;
    unsigned char pad3[0x684 - 0x5E4];
    int f684;
    int f688;
} MatchCnt_02175698;

extern int func_02175F3C(void);
extern int func_02175530(void);
extern char *func_02176344(void);
extern void func_02175F4C(int status);
extern void func_02175F84(int status);
extern int func_0216F20C(int matchType);
extern int func_02173D28(int error);
extern int func_0219EC74(int a, int b, int c, int d, int e, int f, int g, void (*cb)(void), int h);
extern int func_02173D9C(int err);
extern int func_021719D0(int a, int b);
extern int func_021719A4(int error);
extern void func_02174058(void *sb, int reason, void *server);
void func_021755D4(int init);
void func_02175698(void);


/*
 * sdk:      DWCi_SetupGameServer_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_021755D4(int init)
{
    NodeInfo *pMyNodeInfo;
    int matchType;
    int gpResult;

    if (init) {
        ((MatchCnt_021755D4 *)func_02175F3C())->f790 = func_02175530();
        pMyNodeInfo = (NodeInfo *)func_02176344();
        pMyNodeInfo->f16 = 0;
        ((MatchCnt_021755D4 *)func_02175F3C())->f7C4 = 1;
    }
    ((MatchCnt_021755D4 *)func_02175F3C())->f14 = 2;
    func_02175F4C(13);
    func_02175F84(2);
    ((MatchCnt_021755D4 *)func_02175F3C())->f5DC = 0;
    ((MatchCnt_021755D4 *)func_02175F3C())->f18 = 0;
    if (((MatchCnt_021755D4 *)func_02175F3C())->f15 == 0) {
        matchType = 3;
    } else if (((MatchCnt_021755D4 *)func_02175F3C())->f15 == 1) {
        matchType = 4;
    } else {
        matchType = 6;
    }
    if (((MatchCnt_021755D4 *)func_02175F3C())->f15 == 3)
        ((MatchCnt_021755D4 *)func_02175F3C())->f15 = 2;
    gpResult = func_0216F20C(matchType);
    func_02173D28(gpResult);
    ((MatchCnt_021755D4 *)func_02175F3C())->f67C = 0;
}


/*
 * sdk:      DWCi_ConnectToGameServerAsync_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_02175698(void)
{
    int result;

    ((MatchCnt_02175698 *)func_02175F3C())->f14 = 3;
    if (((MatchCnt_02175698 *)func_02175F3C())->f5E0 == 0) {
        ((MatchCnt_02175698 *)func_02175F3C())->f5E0 = func_0219EC74(((MatchCnt_02175698 *)func_02175F3C())->f684, ((MatchCnt_02175698 *)func_02175F3C())->f684,
                                              ((MatchCnt_02175698 *)func_02175F3C())->f688, 0, 20, 1, 0,
                                              (void (*)(void))func_02174058, 0);
    }
    if (((MatchCnt_02175698 *)func_02175F3C())->f5E0 == 0) {
        if (func_02173D9C(5))
            return;
    }
    func_02175F4C(3);
    result = func_021719D0(((MatchCnt_02175698 *)func_02175F3C())->f554, 0);
    func_021719A4(result);
}
