/*
 * file:     unit_0216C858_p07.c
 * unit:     yes
 * function: DWCi_GT2ConnectAttemptCallback
 * address:  0x0216E5B0
 * packet:   pkt_ov009_0216E5B0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2ConnectAttemptCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   gt2Reject                        0x02195B38 arm
 *   strtoul                          0x02095EAC arm
 *   DWCi_GT2GetConnectionListIdx     0x0216BB6C arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_StopResendingMatchCommand   0x0216EB48 arm
 *   DWCi_SetMatchStatus              0x02175F4C arm
 *   DWCi_StopMatch                   0x0216EB68 arm
 *   gt2Accept                        0x02195B2C arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_GetGT2ConnectionByIdx       0x0216BBCC arm
 *   DWCi_GetConnectionInfoByIdx      0x0216BC2C arm
 *   DWCi_ResetLastSomeDataRecvTimeByAid 0x02177748 arm
 *   gt2SetConnectionData             0x02195E70 arm
 *   DWCi_PostProcessConnection       0x02172254 arm
 *   g_021A204C                       0x021A204C data
 *   g_021A2058                       0x021A2058 data
 *   g_021A2064                       0x021A2064 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[8];
    void *f8;
    u8 pad1[0x554 - 0xc];
    u32 f_554;
    u8 pad2[0x564 - 0x558];
    u32 f_564;
    u16 f_568;
    u8 f_56a;
    u8 pad4[0x5a4 - 0x56b];
    u32 f_5a4;
    u8 pad5[0x608 - 0x5a8];
    int f_608;
    int f_60c;
    u8 pad6[0x61c - 0x610];
    int f_61c;
    u8 pad7[0x62a - 0x620];
    u8 f_62a;
    u8 pad8[0x630 - 0x62b];
    u16 f_630;
};

struct DWCstConnectionInfo
{
    u8 f0;
    u8 f1;
    u8 pad[2];
    u32 f4;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void gt2Reject(void * connection, void * message, int code);
extern unsigned long strtoul(const char * s, char ** end, int base);
extern int DWCi_GT2GetConnectionListIdx(void);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_StopResendingMatchCommand(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_StopMatch(int error, int errorCode);
extern int gt2Accept(void * connection, void * flag);
extern int DWCi_NodeInfoList_GetCount(void);
extern void ** DWCi_GetGT2ConnectionByIdx(int index);
extern struct DWCstConnectionInfo * DWCi_GetConnectionInfoByIdx(int index);
extern void DWCi_ResetLastSomeDataRecvTimeByAid(u8 aid);
extern void gt2SetConnectionData(void * connection, void * data);
extern void DWCi_PostProcessConnection(int type);

extern char g_021A204C[];
extern char g_021A2058[];
extern char g_021A2064[];

void DWCi_GT2ConnectAttemptCallback(void * userdata, void * connection,
                                    unsigned int ip, unsigned short port,
                                    int latency, unsigned char * message, int len)
{
    int index;
    int remotePid = 0;
    struct DWCstConnectionInfo * pConInfo;
    struct DWCstMatchControl * m;
    void ** pGt2Con;

    if (DWCi_GetMatchCnt() != 0 && DWCi_GetMatchCnt()->f_61c == 5)
        return;
    if (DWCi_GetMatchCnt() != 0 && DWCi_GetMatchCnt()->f_61c == 6 &&
        DWCi_GetMatchCnt()->f_62a == 0)
        goto process;
    gt2Reject(connection, g_021A204C, -1);
    return;

process:
    if (message != 0 && len != 0)
        remotePid = strtoul((char *)message, 0, 10);
    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        gt2Reject(connection, g_021A2058, -1);
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_StopResendingMatchCommand();
            DWCi_SetMatchStatus(1);
            return;
        }
        DWCi_StopMatch(6, 0xfffeabc4);
        return;
    }
    if (DWCi_GetMatchCnt()->f_564 == ip) {
        if ((unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)) ==
            DWCi_GetMatchCnt()->f_568)
            goto accept;
    }
    if (remotePid == DWCi_GetMatchCnt()->f_554) {
        DWCi_GetMatchCnt()->f_564 = ip;
        DWCi_GetMatchCnt()->f_568 = ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
        goto accept;
    }
    gt2Reject(connection, g_021A2064, -1);
    return;

accept:
    *(unsigned long long *)&DWCi_GetMatchCnt()->f_608 = 0;
    if (gt2Accept(connection, DWCi_GetMatchCnt()->f8) == 0) {
        DWCi_StopMatch(6, 0xfffec5e6);
        return;
    }
    DWCi_StopResendingMatchCommand();
    if (DWCi_GetMatchCnt()->f_5a4 == 0 && DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GetMatchCnt()->f_630 =
            (latency >> 1) >= 0xffff ? 0xffff : (latency >> 1);
    }
    pGt2Con = DWCi_GetGT2ConnectionByIdx(index);
    pConInfo = DWCi_GetConnectionInfoByIdx(index);
    *pGt2Con = connection;
    pConInfo->f0 = index;
    pConInfo->f1 = DWCi_GetMatchCnt()->f_56a;
    pConInfo->f4 = DWCi_GetMatchCnt()->f_554;
    DWCi_ResetLastSomeDataRecvTimeByAid(pConInfo->f1);
    gt2SetConnectionData(connection, pConInfo);
    DWCi_PostProcessConnection(2);
}

