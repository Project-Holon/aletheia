/*
 * function: func_021755D4
 * address:  0x021755D4
 * packet:   pkt_ov009_021755D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SetupGameServer_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02175530  0x02175530  arm  ov009
 *   func_02176344  0x02176344  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 */

typedef struct MatchCnt {
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
} MatchCnt;

typedef struct NodeInfo {
    unsigned char pad0[0x16];
    unsigned char f16;
} NodeInfo;

extern int func_02175F3C(void);
extern int func_02175530(void);
extern NodeInfo *func_02176344(void);
extern void func_02175F4C(int status);
extern void func_02175F84(int status);
extern int func_0216F20C(int matchType);
extern int func_02173D28(int error);

void func_021755D4(int init)
{
    NodeInfo *pMyNodeInfo;
    int matchType;
    int gpResult;

    if (init) {
        ((MatchCnt *)func_02175F3C())->f790 = func_02175530();
        pMyNodeInfo = func_02176344();
        pMyNodeInfo->f16 = 0;
        ((MatchCnt *)func_02175F3C())->f7C4 = 1;
    }
    ((MatchCnt *)func_02175F3C())->f14 = 2;
    func_02175F4C(13);
    func_02175F84(2);
    ((MatchCnt *)func_02175F3C())->f5DC = 0;
    ((MatchCnt *)func_02175F3C())->f18 = 0;
    if (((MatchCnt *)func_02175F3C())->f15 == 0) {
        matchType = 3;
    } else if (((MatchCnt *)func_02175F3C())->f15 == 1) {
        matchType = 4;
    } else {
        matchType = 6;
    }
    if (((MatchCnt *)func_02175F3C())->f15 == 3)
        ((MatchCnt *)func_02175F3C())->f15 = 2;
    gpResult = func_0216F20C(matchType);
    func_02173D28(gpResult);
    ((MatchCnt *)func_02175F3C())->f67C = 0;
}
