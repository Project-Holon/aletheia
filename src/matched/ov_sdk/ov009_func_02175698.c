/*
 * function: DWCi_ConnectToGameServerAsync_InterChange
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
 *   DWCi_HandleSBError  0x02173D9C  arm  ov009
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   DWCi_HandleMatchCommandError  0x021719A4  arm  ov009
 *   DWCi_SBCallback  0x02174058  arm  ov009
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
extern int DWCi_HandleSBError(int err);
extern void DWCi_SetMatchStatus(int status);
extern int func_021719D0(int a, int b);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_SBCallback(void *sb, int reason, void *server);

void DWCi_ConnectToGameServerAsync_InterChange(void)
{
    int result;

    ((MatchCnt *)func_02175F3C())->f14 = 3;
    if (((MatchCnt *)func_02175F3C())->f5E0 == 0) {
        ((MatchCnt *)func_02175F3C())->f5E0 = func_0219EC74(((MatchCnt *)func_02175F3C())->f684, ((MatchCnt *)func_02175F3C())->f684,
                                              ((MatchCnt *)func_02175F3C())->f688, 0, 20, 1, 0,
                                              (void (*)(void))DWCi_SBCallback, 0);
    }
    if (((MatchCnt *)func_02175F3C())->f5E0 == 0) {
        if (DWCi_HandleSBError(5))
            return;
    }
    DWCi_SetMatchStatus(3);
    result = func_021719D0(((MatchCnt *)func_02175F3C())->f554, 0);
    DWCi_HandleMatchCommandError(result);
}
