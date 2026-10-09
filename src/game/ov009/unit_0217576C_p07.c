/*
 * file:     unit_0217576C_p07.c
 * unit:     yes
 * function: func_0217637C, func_021763AC, func_02176410, func_02176474, func_02176500, func_0217653C, func_02176554, func_0217656C, func_02176580, func_02176594, func_02176674, func_021767E4, func_021767F4, func_02176860, func_02176870, func_0217689C, func_021768EC, func_0217695C
 * address:  0x0217637C
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
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_NodeInfoList_GetMyNodeInfo           0x02176344 arm
 *   DWCi_GetGT2Connection                     0x0216BAF4 arm
 *   func_02176344  0x02176344  arm  ov009
 *   OS_GetTick     0x020870D0  arm
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0216BAF4  0x0216BAF4  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_02171F68  0x02171F68  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_0216BA08  0x0216BA08  arm  ov009
 *   DWCi_GetMatchCnt  0x02175F3C arm
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 */
typedef unsigned char u8;

struct DWCstNodeInfo
{
	int profileID;
	unsigned int ip;
	unsigned int privateInetAddress;
	unsigned short port;
	unsigned short privateQueryPort;
	unsigned int gt2IP;
	unsigned short gt2Port;
	unsigned char aid;
	unsigned char hasPrivateAddress;
	int nnTryCount;
	unsigned long long nextMeshMakeTryTick;
	unsigned char connUserData[4];
};

typedef struct NodeInfo_02176594 {
    unsigned char pad0[0x16];
    unsigned char aid;
} NodeInfo_02176594;

typedef struct {
    int w[10];
} NodeInfo_02176674;

struct DWCstMatchControl
{
	void **connection;
	unsigned char pad4[0x9];
	unsigned char f0d;
	unsigned char pade[0x2];
	void *qr2Obj;
	unsigned char pad14[0x1];
	unsigned char qr2MatchTypeExt;
	unsigned char hostState;
	unsigned char pad17[0x5];
	unsigned int suspendBitmap;
	unsigned long long f20;
	unsigned char pad28[0x8];
	unsigned char suspendSent;
	unsigned char pad31[0x523];
	int f554;
	unsigned char pad558[0x50];
	int lastStateBeforeStopMeshMaking;
	unsigned char  tempNodeInfoBeforeStopMeshMaking[0x28];
	unsigned char pad5d4[0xc];
	void *sbObj;
	unsigned char pad5e4[0x38];
	int f61c;
	unsigned char pad620[0x58];
	unsigned int f678;
	int f67c;
	unsigned char pad680[0x118];
	int f798;
	unsigned char pad79c[0x4];
	unsigned long long f7a0;
	unsigned char pad7a8[0x20];
	unsigned int f7c8;
	unsigned long long f7cc;
};

extern char *func_02175F3C(void);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern struct DWCstNodeInfo * DWCi_NodeInfoList_GetMyNodeInfo(void);
extern void * DWCi_GetGT2Connection(unsigned char aid);
extern void func_02082BCC(void *p, int v, int n);
extern char *func_02176344(void);
extern unsigned long long OS_GetTick(void);
extern int func_0217603C(void);
extern int func_0216BAF4(int aid);
extern void MI_CpuFill8(void *p, int v, int n);
extern void func_02199FB4(int cookie);
extern int func_02171F68(int unused);
extern int func_021719A4(int error);
extern int func_0216BA08(void);
extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern int func_0216B908(void);
extern void func_0219B490(int status);
/* * DWCi_NodeInfoList_GetNodeInfoForIndex: the 0x28-byte node record at an index, or null past the count. */ char *func_0217637C(int index);
/* * DWCi_NodeInfoList_GetNodeInfoForProfileID: the node record whose profile id matches, or null. */ char *func_021763AC(int pid);
/* * sdk: DWCi_NodeInfoList_GetNodeInfoForAID (dwc_match.o) * * Extra open callee of DWCi_DeleteAID (0x0216BCA4). */ char *func_02176410(unsigned char aid);
/* * sdk: DWCi_NodeInfoList_GetFreeAID (dwc_match.o) */ unsigned char func_02176474(void);
int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
/* * Clears the block 0x554 bytes into the module block. */ void func_0217653C(void);
/* * Prepares the block 0x554 bytes into the module block. */ int func_02176554(void);
/* * Clears 0x28 bytes of the argument. */ void func_0217656C(void *p);
/* * True when the word a pointer points at is non-zero. */ int func_02176580(const int *p);
/* * sdk: DWCi_GetNextMeshMakeTryTick (libdwcmatch.TWL.HYB.a dwc_match.o) */ unsigned long long func_02176594(void);
/* * DWCi_StopMeshMaking: abandons the mesh step in progress, cancelling any NAT negotiation. */ int func_02176674(void);
/* * Word at +0x7c4 of the block func_02175F3C returns. */ int func_021767E4(void);
/* * Whether this host is the server of a running match that has not been the first server. */ int func_021767F4(void);
/* * Word at +0x7b0 of the block func_02175F3C returns. */ int func_02176860(void);
void DWCi_ClearMeshMakingTempInfo(void);
void func_0217689C(void);
/* * sdk: DWCi_SuspendComplete (dwc_match.o) */ void func_021768EC(int result);
/* * Set when the word at +0x7b0 of the module block is two. */ int func_0217695C(void);




/*
 * DWCi_NodeInfoList_GetNodeInfoForIndex: the 0x28-byte node record at an index, or null past the count.
 */
char *func_0217637C(int index)
{
    if (index >= *(int *)(func_02175F3C() + 0x50)) {
        return 0;
    }
    return func_02175F3C() + 0x54 + index * 0x28;
}




/*
 * DWCi_NodeInfoList_GetNodeInfoForProfileID: the node record whose profile id matches, or null.
 */
char *func_021763AC(int pid)
{
    int i;

    for (i = 0; i < *(int *)(func_02175F3C() + 0x50); i++) {
        if (pid == *(int *)(func_02175F3C() + i * 0x28 + 0x54)) {
            return func_02175F3C() + 0x54 + i * 0x28;
        }
    }
    return 0;
}




/*
 * sdk:      DWCi_NodeInfoList_GetNodeInfoForAID (dwc_match.o)
 *
 * Extra open callee of DWCi_DeleteAID (0x0216BCA4).
 */
char *func_02176410(unsigned char aid)
{
    int i;

    for (i = 0; i < *(int *)(func_02175F3C() + 0x50); i++) {
        if (aid == *(unsigned char *)(func_02175F3C() + i * 0x28 + 0x6a))
            return func_02175F3C() + 0x54 + i * 0x28;
    }
    return 0;
}




/*
 * sdk:      DWCi_NodeInfoList_GetFreeAID (dwc_match.o)
 */
unsigned char func_02176474(void)
{
    unsigned char i;
    int j;

    if (*(int *)(func_02175F3C() + 0x50) == 32)
        return 0xff;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < *(int *)(func_02175F3C() + 0x50); j++) {
            if (i == *(unsigned char *)(func_02175F3C() + j * 40 + 0x6a))
                break;
        }
        if (j == *(int *)(func_02175F3C() + 0x50))
            return i;
    }
    return 0xff;
}




int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID)
{
    struct DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID);

    if (pNodeInfo == 0)
        return 0;
    if (pNodeInfo == DWCi_NodeInfoList_GetMyNodeInfo())
        return 0;
    return DWCi_GetGT2Connection(pNodeInfo->aid) == 0;
}




/*
 * Clears the block 0x554 bytes into the module block.
 */
void func_0217653C(void)
{
    func_0217656C((void *)(func_02175F3C() + 0x554));
}




/*
 * Prepares the block 0x554 bytes into the module block.
 */
int func_02176554(void)
{
    return func_02176580((const int *)(func_02175F3C() + 0x554));
}



/*
 * Clears 0x28 bytes of the argument.
 */
void func_0217656C(void *p)
{
    func_02082BCC(p, 0, 0x28);
}


/*
 * True when the word a pointer points at is non-zero.
 */
int func_02176580(const int *p)
{
    return *p != 0;
}



/*
 * sdk:      DWCi_GetNextMeshMakeTryTick (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
unsigned long long func_02176594(void)
{
    int existGT2Count;
    int i;
    int myNodeIndex;
    NodeInfo_02176594 *pMyNodeInfo;
    unsigned long long tick;
    NodeInfo_02176594 *pNodeInfo;

    pMyNodeInfo = (NodeInfo_02176594 *)func_02176344();
    tick = OS_GetTick();
    tick += 0x17F898;
    existGT2Count = 0;
    myNodeIndex = 0;
    if (func_0217603C() > 2) {
        for (i = 1; i < func_0217603C(); i++) {
            pNodeInfo = (NodeInfo_02176594 *)func_0217637C(i);
            if (pMyNodeInfo == pNodeInfo) {
                myNodeIndex = i;
            } else {
                func_0216BAF4(pNodeInfo->aid);
                if (func_0216BAF4(pNodeInfo->aid) != 0)
                    existGT2Count++;
            }
        }
    }
    tick += (long long)existGT2Count * 0x17F898;
    tick += ((unsigned long long)((func_0217603C() - 1 - myNodeIndex) * 6000) * 33514) >> 6;
    return tick;
}



/*
 * DWCi_StopMeshMaking: abandons the mesh step in progress, cancelling any NAT negotiation.
 */
int func_02176674(void)
{
    if (*(int *)(func_02175F3C() + 0x5a4) == 0) {
        return 0;
    }
    *(int *)(func_02175F3C() + 0x5a4) = 0;
    *(int *)(func_02175F3C() + 0x5a8) = *(int *)(func_02175F3C() + 0x61c);
    if (func_02176554() != 0) {
        *(NodeInfo_02176674 *)(func_02175F3C() + 0x5ac) = *(NodeInfo_02176674 *)(func_02175F3C() + 0x554);
    } else {
        MI_CpuFill8(func_02175F3C() + 0x5ac, 0, 0x28);
    }
    if (*(int *)(func_02175F3C() + 0x618) != 0) {
        func_02199FB4(*(int *)(func_02175F3C() + 0x618));
        *(int *)(func_02175F3C() + 0x618) = 0;
        *(unsigned char *)(func_02175F3C() + 0x5f8) = 0;
        *(int *)(func_02175F3C() + 0x5fc) = 0;
        *(unsigned long long *)(func_02175F3C() + 0x600) = 0;
    }
    if (*(int *)(func_02175F3C() + 0x61c) == 3 || *(int *)(func_02175F3C() + 0x61c) == 5 ||
        *(int *)(func_02175F3C() + 0x61c) == 6 || *(int *)(func_02175F3C() + 0x61c) == 14 ||
        *(int *)(func_02175F3C() + 0x61c) == 15) {
        if (*(int *)(func_02175F3C() + 0x67c) != 0) {
            if (func_021719A4(func_02171F68(0)) != 0) {
                func_0217653C();
                return 1;
            }
        }
        *(unsigned char *)(func_02175F3C() + 0x18) = 0;
        *(int *)(func_02175F3C() + 0x5dc) = 0;
    }
    func_0217653C();
    return 1;
}



/*
 * Word at +0x7c4 of the block func_02175F3C returns.
 */
int func_021767E4(void)
{
    return *(int *)(func_02175F3C() + 0x7c4);
}



/*
 * Whether this host is the server of a running match that has not been the first server.
 */
int func_021767F4(void)
{
    if (*(int *)(func_02175F3C() + 0x7d4) == 0) {
        return 0;
    }
    if (func_0216BA08() != 0 &&
        (*(unsigned char *)(func_02175F3C() + 0x15) == 1 || *(unsigned char *)(func_02175F3C() + 0x15) == 3 || *(unsigned char *)(func_02175F3C() + 0x15) == 2) &&
        func_021767E4() == 0) {
        return 1;
    }
    return 0;
}



/*
 * Word at +0x7b0 of the block func_02175F3C returns.
 */
int func_02176860(void)
{
    return *(int *)(func_02175F3C() + 0x7b0);
}



void DWCi_ClearMeshMakingTempInfo(void)
{
    DWCi_GetMatchCnt()->lastStateBeforeStopMeshMaking = 0;
    MI_CpuFill8(&DWCi_GetMatchCnt()->tempNodeInfoBeforeStopMeshMaking, 0, 0x28);
}



void func_0217689C(void)
{
    if (*(int *)(func_02175F3C() + 0x2c) == 0xff)
        return;
    if (*(int *)(func_02175F3C() + 0x2c) == 1)
        *(unsigned int *)(func_02175F3C() + 0x1c) = func_0216B908();
    else
        *(unsigned int *)(func_02175F3C() + 0x1c) = 0;
    func_021768EC(0);
}



/*
 * sdk:      DWCi_SuspendComplete (dwc_match.o)
 */
void func_021768EC(int result)
{
    if (*(void (**)(int, int, int))(func_02175F3C() + 0x34) != 0)
        (*(void (**)(int, int, int))(func_02175F3C() + 0x34))(result, *(int *)(func_02175F3C() + 0x2c), *(int *)(func_02175F3C() + 0x38));
    if (result == 0)
        func_0219B490(*(int *)(func_02175F3C() + 0x10));
    *(int *)(func_02175F3C() + 0x2c) = 0xff;
    *(int *)(func_02175F3C() + 0x48) = 0;
}



/*
 * Set when the word at +0x7b0 of the module block is two.
 */
int func_0217695C(void)
{
    return *(int *)(func_02175F3C() + 0x7b0) == 2;
}
