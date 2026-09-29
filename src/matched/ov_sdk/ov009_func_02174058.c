/*
 * function: func_02174058
 * address:  0x02174058
 * packet:   pkt_ov009_02174058
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    the retry tail (state 2 and a fresh timeout tick) is written out at the end of
 *           cases 0x16, 4 and 0xC; the compiler cross-jumps the identical copies, which
 *           leaves the one-instruction jump stubs the image has. The counter, running
 *           maximum and per-server count of the case 0xC scan are block locals of its
 *           sbCount > 1 arm; declaration order in the function block fixes the rest of
 *           the register assignment. The bare MC() call and the unused
 *           ServerBrowserGetServer(sb, 0) call in case 4 are in the image and kept.
 *
 * sdk:      DWCi_SBCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   DWCi_GetMatchCnt                           0x02175F3C arm ov009
 *   DWCi_SBPrintServerData                     0x0217478C arm ov009
 *   ServerBrowserCount                         0x0219F068 arm ov009
 *   ServerBrowserGetServer                     0x0219F058 arm ov009
 *   DWCi_CheckDWCServer                        0x02173BE4 arm ov009
 *   ServerBrowserRemoveServer                  0x0219EFA8 arm ov009
 *   SBServerGetPublicInetAddress               0x0219E1EC arm ov009
 *   SBServerGetPublicQueryPort                 0x0219E1F4 arm ov009
 *   SBServerGetPrivateInetAddress              0x0219E238 arm ov009
 *   SBServerGetPrivateQueryPort                0x0219E240 arm ov009
 *   SBServerHasPrivateAddress                  0x0219E220 arm ov009
 *   DWCi_NodeInfoList_InsertToTop              0x0217604C arm ov009
 *   DWCi_StartMatch                            0x02175AA4 arm ov009
 *   DWCi_NodeInfoList_GetFreeAID               0x02176474 arm ov009
 *   DWCi_EvaluateServers                       0x02174790 arm ov009
 *   DWCi_RandomizeServers                      0x02174930 arm ov009
 *   DWCi_TempNewNodeInfo_Clear                 0x0217653C arm ov009
 *   SBServerGetIntValueA                       0x0219E120 arm ov009
 *   DWCi_ConnectToGameServerAsync_InterChange  0x02175698 arm ov009
 *   DWCi_CancelReservation                     0x02171F68 arm ov009
 *   DWCi_HandleMatchCommandError               0x021719A4 arm ov009
 *   DWCi_SetMatchStatus                        0x02175F4C arm ov009
 *   DWCi_SendResvCommandToFriend               0x02171C08 arm ov009
 *   DWCi_NNStartupAsync                        0x0216FC34 arm ov009
 *   DWCi_HandleNNError                         0x02173EF8 arm ov009
 *   DWCi_GetTopologyType                       0x02176860 arm ov009
 *   DWCi_ConnectToGameServerAsync              0x0216D27C arm ov009
 *   OS_GetTick                                 0x020870D0 arm
 *   MI_CpuFill8                                0x02082BCC arm
 *   MI_CpuCopy8                                0x02082D44 arm
 *   s_bInNNThink                               0x021AAA20 data
 *   g_021A20A4                                 0x021A20A4 data
 *   g_021A21A4                                 0x021A21A4 data
 *   g_021A2170                                 0x021A2170 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

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
    u8 f_15;
    u8 pad1[0x554 - 0x16];
    u32 f_554;
    u32 f_558;
    u32 f_55C;
    u16 f_560;
    u16 f_562;
    u8 pad2[0x56A - 0x564];
    u8 f_56A;
    u8 f_56B;
    u8 pad3[0x5D4 - 0x56C];
    u16 f_5D4;
    u8 pad4[0x5D8 - 0x5D6];
    u32 f_5D8;
    u8 pad5[0x5E4 - 0x5DC];
    u32 f_5E4;
    u64 f_5E8;
    u64 f_5F0;
    u8 pad6[0x61C - 0x5F8];
    int f_61C;
    u8 pad7[0x678 - 0x620];
    u32 f_678;
    int f_67C;
    u8 pad8[0x770 - 0x680];
    u32 f_770;
    u32 f_774;
    u32 f_778;
    u32 f_77C;
    u8 pad9[0x7B8 - 0x780];
    u32 f_7B8;
    u32 f_7BC;
    u32 f_7C0;
};

extern struct { int pad[5]; int depth; } s_bInNNThink;
extern char g_021A20A4[];
extern char g_021A21A4[];
extern char g_021A2170[];
extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
extern unsigned long long OS_GetTick(void);
extern void DWCi_SBPrintServerData(void *server);
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
extern void DWCi_ConnectToGameServerAsync_InterChange(int a);
extern int DWCi_CancelReservation(int pid);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
extern int DWCi_NNStartupAsync(int isQR2, int cookie, struct DWCstNodeInfo *node);
extern int DWCi_HandleNNError(int error);
extern int DWCi_GetTopologyType(void);
extern void DWCi_ConnectToGameServerAsync(int topology, int serverPid,
    void *a, void *b, void *c, void *d, void *e, void *f, void *g);

#define MC() DWCi_GetMatchCnt()
#define RETRY() do { MC()->f_5E4 = 2; tick = OS_GetTick(); MC()->f_5E8 = tick; } while (0)

void func_02174058(void *sb, int reason, void *server)
{
    int sbCount;
    void *targetServer;
    int i;
    int profileID;
    u64 tick;
    struct DWCstNodeInfo tmpNodeInfo;

    s_bInNNThink.depth++;

    if (MC()->f_5F0 != 0) {
        if (reason == 4 || reason == 5) {
            MC()->f_5F0 = 0;
        } else {
            tick = OS_GetTick();
            MC()->f_5F0 = tick + (u64)0xEFB5F7;
        }
    }

    switch (reason) {
    case 0:
        DWCi_SBPrintServerData(server);
        break;
    case 4:
        MC()->f_5F0 = 0;
        for (i = 0; i < ServerBrowserCount(sb); i++) {
            server = ServerBrowserGetServer(sb, i);
            if (DWCi_CheckDWCServer(server) == 0) {
                ServerBrowserRemoveServer(sb, server);
                i--;
            }
        }
        switch (MC()->f_61C) {
        case 0x16: {
            int j;

            j = 0;
            if (ServerBrowserCount(sb) > 0) {
                do {
                    server = ServerBrowserGetServer(sb, j);
                    if (MC()->f_5D8 != 0 &&
                        MC()->f_5D8 == SBServerGetPublicInetAddress(server) &&
                        MC()->f_5D4 != 0 &&
                        MC()->f_5D4 == SBServerGetPublicQueryPort(server))
                        break;
                    j++;
                } while (j < ServerBrowserCount(sb));
            }
            if (j < ServerBrowserCount(sb)) {
                MI_CpuFill8(&tmpNodeInfo, 0, 0x28);
                tmpNodeInfo.f0 = MC()->f_678;
                tmpNodeInfo.f16 = 0xFF;
                tmpNodeInfo.f4 = MC()->f_5D8;
                tmpNodeInfo.f_c = MC()->f_5D4;
                tmpNodeInfo.f8 = SBServerGetPrivateInetAddress(server);
                tmpNodeInfo.f_e = SBServerGetPrivateQueryPort(server);
                tmpNodeInfo.f17 = SBServerHasPrivateAddress(server);
                MI_CpuCopy8(&MC()->f_7BC, &tmpNodeInfo.f_24, 4);
                if (MC()->f_15 == 0) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->f_15 == 1) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->f_15 == 2) {
                    tmpNodeInfo.f16 = DWCi_NodeInfoList_GetFreeAID();
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->f_15 == 3) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                }
                goto end;
            }
            RETRY();
            goto end;
        }
        case 2:
            DWCi_EvaluateServers(1);
            DWCi_RandomizeServers();
            if (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                DWCi_TempNewNodeInfo_Clear();
                MC()->f_554 = SBServerGetIntValueA(server, g_021A20A4, 0);
                MC()->f_56A = 0xFF;
                MC()->f_558 = SBServerGetPublicInetAddress(server);
                MC()->f_560 = SBServerGetPublicQueryPort(server);
                MC()->f_55C = SBServerGetPrivateInetAddress(server);
                MC()->f_562 = SBServerGetPrivateQueryPort(server);
                MC()->f_56B = SBServerHasPrivateAddress(server);
                DWCi_ConnectToGameServerAsync_InterChange(MC()->f_554);
            } else {
                MC()->f_5E4 = 2;
                tick = OS_GetTick();
                MC()->f_5E8 = tick;
                DWCi_TempNewNodeInfo_Clear();
            }
            goto end;
        case 4:
            while (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                if (SBServerGetPublicInetAddress(server) == MC()->f_558 &&
                    SBServerGetPublicQueryPort(server) == MC()->f_560)
                    break;
                ServerBrowserRemoveServer(sb, server);
            }
            if (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                profileID = SBServerGetIntValueA(server, g_021A20A4, 0);
                if (MC()->f_15 == 1) {
                    MC();
                    if (profileID != MC()->f_67C ||
                        DWCi_EvaluateServers(0) == 0) {
                        if (DWCi_HandleMatchCommandError(
                                DWCi_CancelReservation(MC()->f_67C)) != 0)
                            goto end;
                        DWCi_SetMatchStatus(3);
                        DWCi_TempNewNodeInfo_Clear();
                        DWCi_HandleMatchCommandError(
                            DWCi_SendResvCommandToFriend(0, 0, MC()->f_67C));
                        goto end;
                    }
                }
                DWCi_SetMatchStatus(5);
                ServerBrowserGetServer(sb, 0);
                DWCi_HandleNNError(DWCi_NNStartupAsync(0, 0,
                    (struct DWCstNodeInfo *)&MC()->f_554));
                goto end;
            }
            RETRY();
            goto end;
        case 0xC:
            sbCount = ServerBrowserCount(sb);
            if (sbCount != 0) {
                if (sbCount > 1) {
                    int k;
                    int max_numplayers;
                    int numplayers;

                    max_numplayers = -1;
                    for (k = 0; k < sbCount; k++) {
                        server = ServerBrowserGetServer(sb, k);
                        numplayers = SBServerGetIntValueA(server, g_021A21A4, -1);
                        if (max_numplayers < numplayers) {
                            targetServer = server;
                            max_numplayers = numplayers;
                        }
                    }
                } else {
                    targetServer = ServerBrowserGetServer(sb, 0);
                }
                DWCi_TempNewNodeInfo_Clear();
                MC()->f_554 = SBServerGetIntValueA(targetServer, g_021A20A4, 0);
                MC()->f_56A = 0xFF;
                MC()->f_558 = SBServerGetPublicInetAddress(targetServer);
                MC()->f_560 = SBServerGetPublicQueryPort(targetServer);
                MC()->f_55C = SBServerGetPrivateInetAddress(targetServer);
                MC()->f_562 = SBServerGetPrivateQueryPort(targetServer);
                MC()->f_56B = SBServerHasPrivateAddress(targetServer);
                MC()->f_15 = SBServerGetIntValueA(targetServer, g_021A2170, -1);
                {
                    int topology = DWCi_GetTopologyType();

                    profileID = SBServerGetIntValueA(targetServer, g_021A20A4, 0);
                    DWCi_ConnectToGameServerAsync(topology, profileID,
                        (void *)MC()->f_770, (void *)MC()->f_774,
                        (void *)MC()->f_778, (void *)MC()->f_77C,
                        (void *)MC()->f_7B8, &MC()->f_7BC,
                        (void *)MC()->f_7C0);
                }
                goto end;
            }
            RETRY();
            goto end;
        default:
            goto end;
        }
        break;
    }
end:
    s_bInNNThink.depth--;
}
