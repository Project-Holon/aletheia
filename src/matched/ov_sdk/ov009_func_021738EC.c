/*
 * function: DWCi_ProcessCancelMatchSynTimeout
 * address:  0x021738EC
 * packet:   pkt_ov009_021738EC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessCancelMatchSynTimeout (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   OS_GetTick                       0x020870D0 arm
 *   _ll_udiv                         0x0209C00C arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637C arm
 *   DWCi_SendCancelMatchSynCommand   0x02173614 arm
 *   DWCi_CloseShutdownClientSC       0x02172EAC arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_RestartFromCancel           0x02172BB8 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[0x61c];
    int f_61c;
    u8 pad1[0x62d - 0x620];
    u8 f_62d;
    u8 pad2[0x632 - 0x62e];
    u16 f_632;
    u8 pad3[0x654 - 0x634];
    u32 f_654;
    u8 pad4[0x660 - 0x658];
    unsigned long long f_660;
};

struct DWCstNodeInfo
{
    int f0;
    u8 pad[0x16 - 4];
    u8 f16;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern unsigned long long OS_GetTick(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_SendCancelMatchSynCommand(int profileID, u8 command);
extern int DWCi_CloseShutdownClientSC(u32 bitmap);
extern int DWCi_NodeInfoList_GetCount(void);
extern void DWCi_RestartFromCancel(int level);

int DWCi_ProcessCancelMatchSynTimeout(void)
{
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->f_61c == 7 ||
        DWCi_GetMatchCnt()->f_61c == 0x11 ||
        DWCi_GetMatchCnt()->f_61c == 0x12) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->f_660;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->f_61c) {
    case 7: {
        struct DWCstNodeInfo * pNodeInfo;

        if (passTime <= 0x1770)
            break;
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        if (DWCi_SendCancelMatchSynCommand(pNodeInfo->f0, 0xe) == 0)
            return 0;
        break;
    }
    case 0x11:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->f_62d++;
        if (DWCi_GetMatchCnt()->f_62d > 5) {
            if (DWCi_CloseShutdownClientSC(DWCi_GetMatchCnt()->f_654) == 0)
                return 0;
            if (DWCi_NodeInfoList_GetCount() > 1) {
                DWCi_GetMatchCnt()->f_62d = 0;
                passTime = OS_GetTick();
                DWCi_GetMatchCnt()->f_660 = passTime;
            } else {
                DWCi_RestartFromCancel(2);
            }
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                struct DWCstNodeInfo * pNodeInfo =
                    DWCi_NodeInfoList_GetNodeInfoForIndex(i);

                if (DWCi_GetMatchCnt()->f_654 & (1 << pNodeInfo->f16))
                    continue;
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->f0, 0xd) == 0)
                    return 0;
            }
        }
        break;
    case 0x12:
        if (passTime <= DWCi_GetMatchCnt()->f_632)
            break;
        DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}
