/*
 * file:     unit_0216F014_p23.c
 * unit:     yes
 * function: func_02173C9C, func_02173CFC, func_02173D28, func_02173D9C, func_02173E30, func_02173EF8, func_02173F54, func_02173FB4, func_02174058
 * address:  0x02173C9C
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
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   OS_GetTick  0x020870D0  arm
 *   func_0216EB68  0x0216EB68  arm  ov009
 *   func_0216B994  0x0216B994  arm  ov009
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
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
 *   MI_CpuFill8                                0x02082BCC arm
 *   MI_CpuCopy8                                0x02082D44 arm
 *   s_bInNNThink                               0x021AAA20 data
 *   g_021A20A4                                 0x021A20A4 data
 *   g_021A21A4                                 0x021A21A4 data
 *   g_021A2170                                 0x021A2170 data
 */
#define MC() DWCi_GetMatchCnt()
#define RETRY() do { MC()->f_5E4 = 2; tick = OS_GetTick(); MC()->f_5E8 = tick; } while (0)
enum E { E_OK, E_A, E_B, E_C, E_D, E_E, E_NET };

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

extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int func_02175F3C(void);
extern unsigned long long OS_GetTick(void);
extern void func_0216EB68(int error, int errorCode);
extern int func_0216B994(void);
extern void func_0216A3B8(int dwcError, int errorCode);
extern void DWCi_SetError(int dwcError, int errorCode);
extern struct DWCstMatchControl *DWCi_GetMatchCnt(void);
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
unsigned int func_02173C9C(int valid);
void func_02173CFC(void);
int func_02173D28(int error);
int func_02173D9C(int error);
int func_02173E30(int error);
int func_02173EF8(int error);
int func_02173F54(int result);
int func_02173FB4(int result);
void func_02174058(void *sb, int reason, void *server);
extern struct { int pad[5]; int depth; } s_bInNNThink;
extern char g_021A20A4[];
extern char g_021A21A4[];
extern char g_021A2170[];


/*
 * sdk:      DWCi_GetAIDBitmask (dwc_match.o)
 */
unsigned int func_02173C9C(int valid)
{
    unsigned int bitmask = 0;
    int i;

    for (i = 1; i < func_0217603C(); i++)
        bitmask |= 1 << *(unsigned char *)(func_0217637C(i) + 0x16);
    if (valid == 0)
        bitmask |= 1 << *(unsigned char *)(func_02175F3C() + 0x56a);
    return bitmask;
}


/*
 * DWCi_InitClWaitTimeout: clears the wait flag and stamps the current tick.
 */
void func_02173CFC(void)
{
    unsigned long long t;

    ((char *)func_02175F3C())[0x62e] = 0;
    t = OS_GetTick();
    *(unsigned long long *)(func_02175F3C() + 0x670) = t;
}


/*
 * Maps a match-command error to a DWC error and stops the match.
 */
int func_02173D28(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 9;
        errorCode = -2;
        break;
    case 3:
        dwcError = 6;
        errorCode = -10;
        break;
    case 4:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    func_0216EB68(dwcError, errorCode + -81000);
    return error;
}


/*
 * DWCi_HandleSBError: maps a server browsing error to a DWC error and stops the match.
 */
int func_02173D9C(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -30;
        break;
    case 3:
        dwcError = 6;
        errorCode = -20;
        break;
    case 4:
        dwcError = 6;
        errorCode = -40;
        break;
    case 5:
        dwcError = 9;
        errorCode = -1;
        break;
    case 6:
        dwcError = 9;
        errorCode = -2;
        break;
    }
    func_0216EB68(dwcError, errorCode + -85000);
    return error;
}


/*
 * sdk:      DWCi_HandleQR2Error (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02173E30(int error)
{
    int errorCode;
    int dwcError;

    if (error == 0)
        return 0;
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -60;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    case 4:
        dwcError = 6;
        errorCode = -80;
        break;
    case 5:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    switch (func_0216B994()) {
    case 2:
        func_0216A3B8(dwcError, errorCode - 64000);
        break;
    case 4:
        func_0216EB68(dwcError, errorCode - 84000);
        break;
    default:
        DWCi_SetError(dwcError, errorCode - 94000);
        break;
    }
    return error;
}


/*
 * DWCi_HandleNNError: maps a NAT negotiation error to a DWC error and stops the match.
 */
int func_02173EF8(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 6;
        errorCode = -50;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    }
    func_0216EB68(dwcError, errorCode + -86000);
    return error;
}


int func_02173F54(int result)
{
    enum E dwcError;

    if (result == 0)
        return 0;
    switch (result) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        dwcError = E_NET;
        break;
    }
    if (dwcError != E_OK)
        func_0216EB68(dwcError, -86009);
    return result;
}


/*
 * sdk:      DWCi_HandleGT2Error (dwc_match.o)
 */
int func_02173FB4(int result)
{
    int dwcError;
    int errorCode;

    if (result == 0)
        return 0;
    switch (result) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
    case 5:
        dwcError = 0;
        errorCode = 0;
        result = 0;
        break;
    case 3:
        dwcError = 6;
        errorCode = -10;
        break;
    case 4:
        dwcError = 6;
        errorCode = -30;
        break;
    case 6:
        dwcError = 6;
        errorCode = -70;
        break;
    case 7:
        dwcError = 6;
        errorCode = -80;
        break;
    }
    if (dwcError != 0)
        func_0216EB68(dwcError, errorCode + -87000);
    return result;
}


/*
 * notes:    the retry tail (state 2 and a fresh timeout tick) is written out at the end of
 *           cases 0x16, 4 and 0xC; the compiler cross-jumps the identical copies, which
 *           leaves the one-instruction jump stubs the image has. The counter, running
 *           maximum and per-server count of the case 0xC scan are block locals of its
 *           sbCount > 1 arm; declaration order in the function block fixes the rest of
 *           the register assignment. The bare MC() call and the unused
 *           ServerBrowserGetServer(sb, 0) call in case 4 are in the image and kept.
 *
 * sdk:      DWCi_SBCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
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
