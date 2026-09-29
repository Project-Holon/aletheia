/*
 * function: DWCi_SBCallback
 * address:  0x02174058
 * packet:   pkt_ov009_02174058
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker: partial rewrite.  The reason dispatch (0 -> print, 4 -> rescan),
 *          the DWC-server prune loop, the state switch on +0x61C and the
 *          state 0x16 / 0xC server-selection and field-fill paths are
 *          transcribed from the listing; the state 2 and 4 arms are
 *          abbreviated, so this body does not reproduce the vendor bytes.
 *
 * sdk:      DWCi_SBCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   OS_GetTick                       0x020870D0 arm
 *   DWCi_SBPrintServerData           0x0217478C arm
 *   ServerBrowserCount               0x0219F068 arm
 *   ServerBrowserGetServer           0x0219F058 arm
 *   DWCi_CheckDWCServer              0x02173BE4 arm
 *   ServerBrowserRemoveServer        0x0219EFA8 arm
 *   SBServerGetPublicInetAddress     0x0219E1EC arm
 *   SBServerGetPublicQueryPort       0x0219E1F4 arm
 *   MI_CpuFill8                      0x02082BCC arm
 *   SBServerGetPrivateInetAddress    0x0219E238 arm
 *   SBServerGetPrivateQueryPort      0x0219E240 arm
 *   SBServerHasPrivateAddress        0x0219E220 arm
 *   MI_CpuCopy8                      0x02082D44 arm
 *   DWCi_NodeInfoList_InsertToTop    0x0217604C arm
 *   DWCi_StartMatch                  0x02175AA4 arm
 *   DWCi_NodeInfoList_GetFreeAID     0x02176474 arm
 *   DWCi_EvaluateServers             0x02174790 arm
 *   DWCi_RandomizeServers            0x02174930 arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653C arm
 *   SBServerGetIntValueA             0x0219E120 arm
 *   DWCi_ConnectToGameServerAsync_InterChange 0x02175698 arm
 *   DWCi_CancelReservation           0x02171F68 arm
 *   DWCi_HandleMatchCommandError     0x021719A4 arm
 *   DWCi_SetMatchStatus              0x02175F4C arm
 *   DWCi_SendResvCommandToFriend     0x02171C08 arm
 *   DWCi_NNStartupAsync              0x0216FC34 arm
 *   DWCi_HandleNNError               0x02173EF8 arm
 *   DWCi_GetTopologyType             0x02176860 arm
 *   DWCi_ConnectToGameServerAsync    0x0216D27C arm
 *   s_bInNNThink                     0x021AAA20 data
 *   g_021A20A4                       0x021A20A4 data
 *   g_021A21A4                       0x021A21A4 data
 *   g_021A2170                       0x021A2170 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct DWCstNodeInfo {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 f_c;
    u16 f_e;
    u8 pad0[0x16 - 0x10];
    u8 f16;
    u8 f17;
    u8 pad1[0x24 - 0x18];
    u32 f_24;
};

struct DWCstMatchControl {
    u8 pad0[0x15];
    u8 f_15;                           /* 0x15 */
    u8 pad1[0x554 - 0x16];
    u32 f_554;                         /* 0x554 */
    u32 f_558;                         /* 0x558 */
    u32 f_55C;                         /* 0x55C */
    u8 pad2[0x56A - 0x560];
    u8 f_56A;                          /* 0x56A */
    u8 f_56B;                          /* 0x56B */
    u8 pad3[0x5D4 - 0x56C];
    u16 f_5D4;                         /* 0x5D4 */
    u8 pad4[0x5D8 - 0x5D6];
    u32 f_5D8;                         /* 0x5D8 */
    u8 pad5[0x5E4 - 0x5DC];
    u32 f_5E4;                         /* 0x5E4 */
    unsigned long long f_5E8;          /* 0x5E8 */
    unsigned long long f_5F0;          /* 0x5F0 */
    u8 pad6[0x61C - 0x5F8];
    int f_61C;                         /* 0x61C */
    u8 pad7[0x678 - 0x620];
    u32 f_678;                         /* 0x678 */
    int f_67C;                         /* 0x67C */
    u32 f_680;                         /* 0x680 */
    u8 pad8[0x770 - 0x684];
    u32 f_770;                         /* 0x770 */
    u32 f_774;                         /* 0x774 */
    u32 f_778;                         /* 0x778 */
    u32 f_77C;                         /* 0x77C */
    u8 pad9[0x7B8 - 0x780];
    u32 f_7B8;                         /* 0x7B8 */
    u8 pad10[0x7C0 - 0x7BC];
    u32 f_7C0;                         /* 0x7C0 */
};

extern unsigned char s_bInNNThink[];
extern char g_021A20A4[];
extern char g_021A21A4[];
extern char g_021A2170[];
extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
extern unsigned long long OS_GetTick(void);
extern void DWCi_SBPrintServerData(void);
extern int ServerBrowserCount(void *sb);
extern void *ServerBrowserGetServer(void *sb, int index);
extern int DWCi_CheckDWCServer(void *server);
extern void ServerBrowserRemoveServer(void *sb, void *server);
extern u32 SBServerGetPublicInetAddress(void *server);
extern unsigned short SBServerGetPublicQueryPort(void *server);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern u32 SBServerGetPrivateInetAddress(void *server);
extern unsigned short SBServerGetPrivateQueryPort(void *server);
extern int SBServerHasPrivateAddress(void *server);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int DWCi_NodeInfoList_InsertToTop(struct DWCstNodeInfo *newNode);
extern int DWCi_StartMatch(void);
extern unsigned char DWCi_NodeInfoList_GetFreeAID(void);
extern int DWCi_EvaluateServers(int sort);
extern void DWCi_RandomizeServers(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int SBServerGetIntValueA(void *server, char *key, int idefault);
extern void DWCi_ConnectToGameServerAsync_InterChange(void);
extern int DWCi_CancelReservation(void);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
extern int DWCi_NNStartupAsync(int isQR2, int cookie, struct DWCstNodeInfo *node);
extern int DWCi_HandleNNError(int error);
extern int DWCi_GetTopologyType(void);
extern void DWCi_ConnectToGameServerAsync(int topology, int serverPid,
    void *a, void *b, void *c, void *d, void *e, void *f, void *g);

static void DWCi_SBCallback(void *sb, int reason, void *server)
{
    struct DWCstMatchControl *mc;
    struct DWCstNodeInfo tmpNodeInfo;
    unsigned long long tick;
    int i;
    int sbCount;
    int best;
    void *bestServer;

    s_bInNNThink[0x14]++;

    mc = DWCi_GetMatchCnt();
    if (mc->f_5F0 != 0 || (unsigned int)(mc->f_5F0 >> 32) != 0) {
        if (reason == 4 || reason == 5) {
            mc = DWCi_GetMatchCnt();
            mc->f_5F0 = 0;
        } else {
            tick = OS_GetTick();
            mc = DWCi_GetMatchCnt();
            mc->f_5F0 = tick;
        }
    }

    if (reason == 0) {
        DWCi_SBPrintServerData();
        return;
    }
    if (reason != 4)
        return;

    mc = DWCi_GetMatchCnt();
    mc->f_5F0 = 0;

    sbCount = ServerBrowserCount(sb);
    for (i = 0; i < sbCount; i++) {
        server = ServerBrowserGetServer(sb, i);
        if (!DWCi_CheckDWCServer(server)) {
            ServerBrowserRemoveServer(sb, server);
            i--;
        }
    }

    switch (DWCi_GetMatchCnt()->f_61C) {
    case 2:
        DWCi_EvaluateServers(1);
        DWCi_RandomizeServers();
        if (ServerBrowserCount(sb) != 0) {
            server = ServerBrowserGetServer(sb, 0);
            DWCi_TempNewNodeInfo_Clear();
            DWCi_GetMatchCnt()->f_554 =
                SBServerGetIntValueA(server, g_021A20A4, 0);
            DWCi_GetMatchCnt()->f_56A = 0xFF;
            DWCi_GetMatchCnt()->f_558 = SBServerGetPublicInetAddress(server);
            DWCi_GetMatchCnt()->f_5D4 = SBServerGetPublicQueryPort(server);
            DWCi_GetMatchCnt()->f_55C = SBServerGetPrivateInetAddress(server);
            DWCi_GetMatchCnt()->f_56B = SBServerHasPrivateAddress(server);
            DWCi_ConnectToGameServerAsync_InterChange();
            return;
        }
        break;
    case 4:
        DWCi_TempNewNodeInfo_Clear();
        tick = OS_GetTick();
        DWCi_GetMatchCnt()->f_5E8 = tick;
        return;
    case 0xC:
        sbCount = ServerBrowserCount(sb);
        if (sbCount == 0)
            break;
        best = -1;
        bestServer = 0;
        for (i = 0; i < sbCount; i++) {
            int v;

            server = ServerBrowserGetServer(sb, i);
            v = SBServerGetIntValueA(server, g_021A21A4, best);
            if (best < v) {
                bestServer = server;
                best = v;
            }
        }
        if (sbCount <= 0 || bestServer == 0)
            bestServer = ServerBrowserGetServer(sb, 0);
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt()->f_554 =
            SBServerGetIntValueA(bestServer, g_021A20A4, 0);
        DWCi_GetMatchCnt()->f_56A = 0xFF;
        DWCi_GetMatchCnt()->f_558 = SBServerGetPublicInetAddress(bestServer);
        DWCi_GetMatchCnt()->f_5D4 = SBServerGetPublicQueryPort(bestServer);
        DWCi_GetMatchCnt()->f_55C = SBServerGetPrivateInetAddress(bestServer);
        DWCi_GetMatchCnt()->f_56B = SBServerHasPrivateAddress(bestServer);
        DWCi_GetMatchCnt()->f_15 =
            SBServerGetIntValueA(bestServer, g_021A2170, -1);
        {
            int topology;

            topology = DWCi_GetTopologyType();
            DWCi_ConnectToGameServerAsync(topology,
                SBServerGetIntValueA(bestServer, g_021A20A4, 0),
                (void *)DWCi_GetMatchCnt()->f_770,
                (void *)DWCi_GetMatchCnt()->f_774,
                (void *)DWCi_GetMatchCnt()->f_778,
                (void *)DWCi_GetMatchCnt()->f_77C,
                (void *)DWCi_GetMatchCnt()->f_7B8,
                (unsigned char *)(DWCi_GetMatchCnt()->f_554 + 0x554),
                (void *)DWCi_GetMatchCnt()->f_7C0);
        }
        return;
    case 0x16:
        best = 0;
        if (ServerBrowserCount(sb) > 0) {
            for (i = 0; ; i++) {
                server = ServerBrowserGetServer(sb, i);
                if (DWCi_GetMatchCnt()->f_5D8 != 0 &&
                    DWCi_GetMatchCnt()->f_5D8 == SBServerGetPublicInetAddress(server) &&
                    DWCi_GetMatchCnt()->f_5D4 == SBServerGetPublicQueryPort(server))
                    break;
                if (i + 1 >= ServerBrowserCount(sb))
                    break;
            }
        }
        if (i >= ServerBrowserCount(sb))
            break;
        MI_CpuFill8(&tmpNodeInfo, 0, sizeof(tmpNodeInfo));
        tmpNodeInfo.f0 = DWCi_GetMatchCnt()->f_680;
        tmpNodeInfo.f16 = 0xFF;
        tmpNodeInfo.f4 = DWCi_GetMatchCnt()->f_5D8;
        tmpNodeInfo.f_c = DWCi_GetMatchCnt()->f_5D4;
        tmpNodeInfo.f8 = SBServerGetPublicInetAddress(server);
        tmpNodeInfo.f_e = SBServerGetPublicQueryPort(server);
        tmpNodeInfo.f17 = SBServerHasPrivateAddress(server);
        MI_CpuCopy8((u8 *)DWCi_GetMatchCnt() + 0x7BC,
                    (u8 *)&tmpNodeInfo + 0x24, 4);
        if (DWCi_GetMatchCnt()->f_15 == 0) {
            DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
            DWCi_StartMatch();
            return;
        }
        if (DWCi_GetMatchCnt()->f_15 == 1)
            DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
        else if (DWCi_GetMatchCnt()->f_15 == 2)
            tmpNodeInfo.f16 = DWCi_NodeInfoList_GetFreeAID();
        else if (DWCi_GetMatchCnt()->f_15 != 3)
            break;
        return;
    default:
        break;
    }
}

