/*
 * function: func_02172EAC
 * address:  0x02172EAC
 * packet:   pkt_ov009_02172EAC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CloseShutdownClientSC (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * symbols:
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02176554  0x02176554  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   DWCi_CloseConnectionHard  0x0216BEA4  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_02173C84  0x02173C84  arm  ov009
 *
 * The DWARF declares DWCi_GetAIDFromProfileID with one parameter; the call site
 * loads r1 = 0, so the file passes it. The list stores index first and increment
 * after (validPid[len] = x; len++;); the post-increment form colors the counts
 * differently and adds a copy in the new-node block.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct DWCstNodeInfo {
    int profileID;              /* +0x00 */
    u32 publicInetAddress;      /* +0x04 */
    u32 privateInetAddress;     /* +0x08 */
    u16 publicQueryPort;        /* +0x0c */
    u16 privateQueryPort;       /* +0x0e */
    u32 gt2IP;                  /* +0x10 */
    u16 gt2Port;                /* +0x14 */
    u8 aid;                     /* +0x16 */
    u8 hasPrivateAddress;       /* +0x17 */
    int nnTryCount;             /* +0x18 */
    u64 nextMeshMakeTryTick;    /* +0x1c */
    u8 connUserData[4];         /* +0x24 */
} DWCstNodeInfo;

typedef struct DWCstMatchControl {
    char pad0[0x554];
    DWCstNodeInfo tempNewNodeInfo;  /* +0x554 */
    char pad57c[0x629 - 0x57c];
    u8 closeState;              /* +0x629 */
} DWCstMatchControl;

extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int func_02176554(void);
extern int func_02175F3C(void);
extern char *func_021763AC(int pid);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int error);
extern int DWCi_CloseConnectionHard(u8 aid);
extern void func_0217653C(void);
extern u8 func_02173C84(int profileID, int arg);

static int func_02172EAC(u32 bitmap)
{
    u8 aid;
    int senddata[32];
    int senddataLen;
    int validPid[32];
    int validPidLen;
    int result;
    int i;
    int bShutdownNewNode;
    int bRet;
    DWCstNodeInfo *nodeInfo;

    senddataLen = 0;
    validPidLen = 0;
    bShutdownNewNode = 0;
    bRet = 1;

    for (i = 1; i < func_0217603C(); i++) {
        DWCstNodeInfo *nodeInfo = (DWCstNodeInfo *)func_0217637C(i);

        if (nodeInfo) {
            if (bitmap & (1 << nodeInfo->aid)) {
                validPid[validPidLen] = nodeInfo->profileID;
                validPidLen++;
            } else {
                senddata[senddataLen] = nodeInfo->profileID;
                senddataLen++;
            }
        }
    }

    if (func_02176554()) {
        DWCstNodeInfo *nodeInfo = &((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo;

        if (bitmap & (1 << nodeInfo->aid)) {
            validPid[validPidLen] = nodeInfo->profileID;
            validPidLen++;
        } else {
            senddata[senddataLen] = nodeInfo->profileID;
            senddataLen++;
            bShutdownNewNode = 1;
        }
    }

    for (i = 0; i < validPidLen; i++) {
        nodeInfo = (DWCstNodeInfo *)func_021763AC(validPid[i]);
        if (func_02176554() && nodeInfo == 0 &&
            validPid[i] == ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.profileID)
            nodeInfo = &((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo;
        if (nodeInfo) {
            result = func_0216FF2C(0x10, validPid[i], nodeInfo->publicInetAddress,
                                   nodeInfo->publicQueryPort, (const unsigned int *)senddata, senddataLen);
            if (func_021719A4(result))
                bRet = 0;
        }
    }

    ((DWCstMatchControl *)func_02175F3C())->closeState = 1;
    if (bShutdownNewNode) {
        DWCi_CloseConnectionHard(((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.aid);
        func_0217653C();
    }
    for (i = 0; i < senddataLen; i++) {
        aid = func_02173C84(senddata[i], 0);
        if (aid != 0xff)
            DWCi_CloseConnectionHard(aid);
    }
    ((DWCstMatchControl *)func_02175F3C())->closeState = 0;
    return bRet;
}
