/*
 * function: DWCi_ConnectToGameServerAsync
 * address:  0x0216D27C
 * packet:   pkt_ov009_0216D27C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ConnectToGameServerAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_SetMatchCommonParam  0x0216F5FC  arm  ov009
 *   DWCi_NodeInfoList_GetMyNodeInfo  0x02176344  arm  ov009
 *   DWCi_TempNewNodeInfo_Clear  0x0217653C  arm  ov009
 *   DWCi_NodeInfoList_InsertToTop  0x0217604C  arm  ov009
 *   DWCi_SetConnectionAttemptParam  0x02175560  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   DWCi_SetMatchStatus  0x02175F4C  arm  ov009
 *   ServerBrowserNewA  0x0219EC74  arm  ov009
 *   DWCi_HandleSBError  0x02173D9C  arm  ov009
 *   DWCi_GPSetServerStatus  0x0216F20C  arm  ov009
 *   DWCi_HandleGPError  0x02173D28  arm  ov009
 *   DWCi_QR2Startup  0x0216CD8C  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_0216F770  0x0216F770  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   DWCi_HandleMatchCommandError  0x021719A4  arm  ov009
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct DWCstNodeInfo {
    int profileID;
    u32 publicInetAddress;
    u32 privateInetAddress;
    u16 publicQueryPort;
    u16 privateQueryPort;
    u32 gt2IP;
    u16 gt2Port;
    u8 aid;
    u8 hasPrivateAddress;
    int nnTryCount;
    u64 nextMeshMakeTryTick;
    u8 connUserData[4];
} DWCstNodeInfo;

extern char *func_02175F3C(void);
extern void DWCi_SetMatchCommonParam(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
struct node_s;
extern int DWCi_NodeInfoList_InsertToTop(struct node_s *newNode);
extern void DWCi_SetConnectionAttemptParam(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern void func_02175F84(int a0);
extern void DWCi_SetMatchStatus(int a0);
extern int ServerBrowserNewA(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
extern int DWCi_HandleSBError(int a0);
extern int DWCi_GPSetServerStatus(int status);
extern int DWCi_HandleGPError(void);
extern int DWCi_QR2Startup(int a0);
extern void func_0219B490(int a0);
extern int func_0216F770(int a0);
extern void func_021719D0(int a0, int a1);
extern void DWCi_HandleMatchCommandError(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);

void DWCi_ConnectToGameServerAsync(int topology, int serverPid, void *matchedCallback, void *matchedParam,
                   void *newClientCallback, void *newClientParam, void *attemptCallback,
                   u8 *connectionUserData, void *attemptParam)
{
    DWCstNodeInfo tempNodeInfoBackup;
    DWCstNodeInfo myNodeInfoBackup;
    DWCstNodeInfo serverNodeInfo;
    u8 scResvRetryCount;

    if (*(int *)(func_02175F3C() + 0x798) != 0) {
        tempNodeInfoBackup = *(DWCstNodeInfo *)(func_02175F3C() + 0x554);
        myNodeInfoBackup = *DWCi_NodeInfoList_GetMyNodeInfo();
        scResvRetryCount = *(u8 *)(func_02175F3C() + 0x62b);
    }
    DWCi_SetMatchCommonParam(3, 0, matchedCallback, matchedParam);
    *(int *)(func_02175F3C() + 0x7b0) = topology;
    if (*(int *)(func_02175F3C() + 0x798) == 0) {
        MI_CpuFill8(&serverNodeInfo, 0, 0x28);
        DWCi_TempNewNodeInfo_Clear();
        *(u8 *)(func_02175F3C() + 0x56a) = 0xff;
        *(int *)(func_02175F3C() + 0x554) = serverPid;
    } else {
        *(DWCstNodeInfo *)(func_02175F3C() + 0x554) = tempNodeInfoBackup;
        DWCi_NodeInfoList_InsertToTop((struct node_s *)(&myNodeInfoBackup));
        MI_CpuCopy8(myNodeInfoBackup.connUserData, (void *)(func_02175F3C() + 0x7bc), 4);
        *(u8 *)(func_02175F3C() + 0x62b) = scResvRetryCount;
    }
    *(int *)(func_02175F3C() + 0x778) = (int)newClientCallback;
    *(int *)(func_02175F3C() + 0x77c) = (int)newClientParam;
    DWCi_SetConnectionAttemptParam((void *)((int)attemptCallback), (unsigned char *)((int)connectionUserData), (void *)((int)attemptParam));
    *(u8 *)(func_02175F3C() + 0x18) = 1;
    *(int *)(func_02175F3C() + 0x5dc) = *(int *)(func_02175F3C() + 0x678);
    func_02175F84(1);
    if (*(int *)(func_02175F3C() + 0x798) == 0)
        DWCi_SetMatchStatus(0x16);
    if (*(int *)(func_02175F3C() + 0x5e0) == 0) {
        *(int *)(func_02175F3C() + 0x5e0) = ServerBrowserNewA(
            *(int *)(func_02175F3C() + 0x684),
            *(int *)(func_02175F3C() + 0x684),
            *(int *)(func_02175F3C() + 0x688), 0, 0x14, 1, 0, 0x02174058, 0);
    }
    if (*(int *)(func_02175F3C() + 0x5e0) == 0) {
        if (DWCi_HandleSBError(5) != 0)
            return;
    }
    DWCi_GPSetServerStatus(5);
    if (DWCi_HandleGPError() != 0)
        return;
    if (*(int *)(func_02175F3C() + 0x10) == 0) {
        if (DWCi_QR2Startup(*(int *)(func_02175F3C() + 0x678)) != 0)
            return;
    } else {
        func_0219B490(*(int *)(func_02175F3C() + 0x10));
    }
    if (*(int *)(func_02175F3C() + 0x798) == 0) {
        DWCi_HandleSBError(func_0216F770(*(int *)(func_02175F3C() + 0x678)));
        return;
    }
    func_0219B490(*(int *)(func_02175F3C() + 0x10));
    DWCi_SetMatchStatus(3);
    func_021719D0(serverPid, 0);
    DWCi_HandleMatchCommandError();
}
