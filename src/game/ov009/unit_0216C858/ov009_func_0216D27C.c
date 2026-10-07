/*
 * function: func_0216D27C
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
 *   func_0216F5FC  0x0216F5FC  arm  ov009
 *   func_02176344  0x02176344  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_0217604C  0x0217604C  arm  ov009
 *   func_02175560  0x02175560  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_0219EC74  0x0219EC74  arm  ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 *   func_0216CD8C  0x0216CD8C  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_0216F770  0x0216F770  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
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
extern void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
extern DWCstNodeInfo *func_02176344(void);
extern void func_0217653C(void);
struct node_s;
extern int func_0217604C(struct node_s *newNode);
extern void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern void func_02175F84(int a0);
extern void func_02175F4C(int a0);
extern int func_0219EC74(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
extern int func_02173D9C(int a0);
extern int func_0216F20C(int status);
extern int func_02173D28(void);
extern int func_0216CD8C(int a0);
extern void func_0219B490(int a0);
extern int func_0216F770(int a0);
extern void func_021719D0(int a0, int a1);
extern void func_021719A4(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);

void func_0216D27C(int topology, int serverPid, void *matchedCallback, void *matchedParam,
                   void *newClientCallback, void *newClientParam, void *attemptCallback,
                   u8 *connectionUserData, void *attemptParam)
{
    DWCstNodeInfo tempNodeInfoBackup;
    DWCstNodeInfo myNodeInfoBackup;
    DWCstNodeInfo serverNodeInfo;
    u8 scResvRetryCount;

    if (*(int *)(func_02175F3C() + 0x798) != 0) {
        tempNodeInfoBackup = *(DWCstNodeInfo *)(func_02175F3C() + 0x554);
        myNodeInfoBackup = *func_02176344();
        scResvRetryCount = *(u8 *)(func_02175F3C() + 0x62b);
    }
    func_0216F5FC(3, 0, matchedCallback, matchedParam);
    *(int *)(func_02175F3C() + 0x7b0) = topology;
    if (*(int *)(func_02175F3C() + 0x798) == 0) {
        MI_CpuFill8(&serverNodeInfo, 0, 0x28);
        func_0217653C();
        *(u8 *)(func_02175F3C() + 0x56a) = 0xff;
        *(int *)(func_02175F3C() + 0x554) = serverPid;
    } else {
        *(DWCstNodeInfo *)(func_02175F3C() + 0x554) = tempNodeInfoBackup;
        func_0217604C((struct node_s *)(&myNodeInfoBackup));
        MI_CpuCopy8(myNodeInfoBackup.connUserData, (void *)(func_02175F3C() + 0x7bc), 4);
        *(u8 *)(func_02175F3C() + 0x62b) = scResvRetryCount;
    }
    *(int *)(func_02175F3C() + 0x778) = (int)newClientCallback;
    *(int *)(func_02175F3C() + 0x77c) = (int)newClientParam;
    func_02175560((void *)((int)attemptCallback), (unsigned char *)((int)connectionUserData), (void *)((int)attemptParam));
    *(u8 *)(func_02175F3C() + 0x18) = 1;
    *(int *)(func_02175F3C() + 0x5dc) = *(int *)(func_02175F3C() + 0x678);
    func_02175F84(1);
    if (*(int *)(func_02175F3C() + 0x798) == 0)
        func_02175F4C(0x16);
    if (*(int *)(func_02175F3C() + 0x5e0) == 0) {
        *(int *)(func_02175F3C() + 0x5e0) = func_0219EC74(
            *(int *)(func_02175F3C() + 0x684),
            *(int *)(func_02175F3C() + 0x684),
            *(int *)(func_02175F3C() + 0x688), 0, 0x14, 1, 0, 0x02174058, 0);
    }
    if (*(int *)(func_02175F3C() + 0x5e0) == 0) {
        if (func_02173D9C(5) != 0)
            return;
    }
    func_0216F20C(5);
    if (func_02173D28() != 0)
        return;
    if (*(int *)(func_02175F3C() + 0x10) == 0) {
        if (func_0216CD8C(*(int *)(func_02175F3C() + 0x678)) != 0)
            return;
    } else {
        func_0219B490(*(int *)(func_02175F3C() + 0x10));
    }
    if (*(int *)(func_02175F3C() + 0x798) == 0) {
        func_02173D9C(func_0216F770(*(int *)(func_02175F3C() + 0x678)));
        return;
    }
    func_0219B490(*(int *)(func_02175F3C() + 0x10));
    func_02175F4C(3);
    func_021719D0(serverPid, 0);
    func_021719A4();
}
