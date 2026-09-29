/*
 * function: DWCi_GT2ConnectedCallback
 * address:  0x0216E834
 * packet:   pkt_ov009_0216E834
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2ConnectedCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_SetMatchStatus              0x02175F4C arm
 *   DWCi_ClearMeshMakingTempInfo     0x02176870 arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720D8 arm
 *   DWCi_MakeGT2ConnectString        0x0216E808 arm
 *   gt2AddressToString               0x02198620 arm
 *   gt2Connect                       0x02195B44 arm
 *   DWCi_HandleGT2Error              0x02173FB4 arm
 *   DWCi_GT2GetConnectionListIdx     0x0216BB6C arm
 *   DWCi_StopMatch                   0x0216EB68 arm
 *   DWCi_GetGT2ConnectionByIdx       0x0216BBCC arm
 *   DWCi_GetConnectionInfoByIdx      0x0216BC2C arm
 *   DWCi_ResetLastSomeDataRecvTimeByAid 0x02177748 arm
 *   gt2SetConnectionData             0x02195E70 arm
 *   DWCi_PostProcessConnection       0x02172254 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstMatchControl
{
    u8 pad0[4];
    void *f4;
    void *f8;
    u8 f_c;
    u8 pad1[0x554 - 0xd];
    u32 f_554;
    u8 pad2[0x564 - 0x558];
    u32 f_564;
    u16 f_568;
    u8 f_56a;
    u8 pad3[0x5a8 - 0x56b];
    u32 f_5a8;
    u32 f_5ac;
    u8 pad4[0x5c2 - 0x5b0];
    u8 f_5c2;
    u8 pad5[0x61c - 0x5c3];
    int f_61c;
};

struct DWCstConnectionInfo
{
    u8 f0;
    u8 f1;
    u8 pad[2];
    u32 f4;
};

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern int DWCi_CancelPreConnectedServerProcess(int clientPid);
extern void DWCi_MakeGT2ConnectString(char * buf, int bufLen);
extern char * gt2AddressToString(u32 ip, u16 port, char * string);
extern int gt2Connect(void * socket, void ** connection, char * remoteAddress,
                      u8 * message, int len, int timeout, void * callbacks,
                      int blocking);
extern int DWCi_HandleGT2Error(int result);
extern int DWCi_GT2GetConnectionListIdx(void);
extern void DWCi_StopMatch(int error, int errorCode);
extern void ** DWCi_GetGT2ConnectionByIdx(int index);
extern struct DWCstConnectionInfo * DWCi_GetConnectionInfoByIdx(int index);
extern void DWCi_ResetLastSomeDataRecvTimeByAid(u8 aid);
extern void gt2SetConnectionData(void * connection, void * data);
extern void DWCi_PostProcessConnection(int type);

void DWCi_GT2ConnectedCallback(void * connection, int result)
{
    struct DWCstConnectionInfo * pConInfo;
    void ** pGt2Con;
    char pidStr[24];
    int gt2Result;
    int index;

    if (DWCi_GetMatchCnt() != 0) {
        if (DWCi_GetMatchCnt()->f_61c == 6)
            goto entry;
        if (DWCi_GetMatchCnt()->f_61c == 0xf)
            goto entry;
    }
    if (DWCi_GetMatchCnt()->f_5a8 != 0xf)
        return;
entry:
    if (result != 0) {
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            return;
        }
        if (DWCi_GetMatchCnt()->f_5a8 == 0xf) {
            DWCi_ClearMeshMakingTempInfo();
            return;
        }
        if (result == 5)
            return;
        if (result == 6) {
            DWCi_GetMatchCnt()->f_c++;
            if (DWCi_GetMatchCnt()->f_c > 5) {
                DWCi_GetMatchCnt()->f_c = 0;
                DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->f_554);
                return;
            }
            DWCi_MakeGT2ConnectString(pidStr, 0x18);
            gt2Result = gt2Connect(*(void **)DWCi_GetMatchCnt()->f4, 0,
                gt2AddressToString(DWCi_GetMatchCnt()->f_564,
                                   DWCi_GetMatchCnt()->f_568, 0),
                (u8 *)pidStr, -1, 0x1388, DWCi_GetMatchCnt()->f8, 0);
            if (gt2Result == 1) {
                DWCi_HandleGT2Error(gt2Result);
                return;
            }
            if (gt2Result == 0)
                return;
            DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->f_554);
            return;
        }
        DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->f_554);
        return;
    }

    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        DWCi_StopMatch(6, 0xfffeabc4);
        return;
    }
    pGt2Con = DWCi_GetGT2ConnectionByIdx(index);
    pConInfo = DWCi_GetConnectionInfoByIdx(index);
    *pGt2Con = connection;
    pConInfo->f0 = index;
    if (DWCi_GetMatchCnt()->f_5a8 != 0xf) {
        pConInfo->f1 = DWCi_GetMatchCnt()->f_56a;
        pConInfo->f4 = DWCi_GetMatchCnt()->f_554;
    } else {
        pConInfo->f1 = DWCi_GetMatchCnt()->f_5c2;
        pConInfo->f4 = DWCi_GetMatchCnt()->f_5ac;
    }
    DWCi_ResetLastSomeDataRecvTimeByAid(pConInfo->f1);
    gt2SetConnectionData(connection, pConInfo);
    if (DWCi_GetMatchCnt()->f_61c == 0xf ||
        DWCi_GetMatchCnt()->f_5a8 == 0xf)
        DWCi_PostProcessConnection(0);
    else
        DWCi_PostProcessConnection(1);
}

