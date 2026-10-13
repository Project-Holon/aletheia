/*
 * file:     unit_0217576C.c
 * unit:     yes
 * function: func_0217576C, func_021758C4, func_02175AA4, func_02175BFC, func_02175C64, func_02175D10, func_02175EB4, func_02175EFC, func_02175F1C, func_02175F3C, func_02175F4C, DWCi_SetHostStatus, func_02175FB8, func_02175FC8, func_02175FE4, func_0217601C, func_0217603C, func_0217604C, func_021760FC, func_02176164, func_02176254, func_02176344, func_02176358, func_0217637C, func_021763AC, func_02176410, func_02176474, func_02176500, func_0217653C, func_02176554, func_0217656C, func_02176580, func_02176594, func_02176674, func_021767E4, func_021767F4, func_02176860, func_02176870, func_0217689C, func_021768EC, func_0217695C
 * address:  0x0217576C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * dwc_match.o of the DWC match library: suspend requests, the node-info list,
 * the match control block accessors.
 *
 * symbols:
 *   DWC_IsServerMyself                0x0216BA08 arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   DWC_GetAIDBitmap                0x0216B908 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_02176344                0x02176344 arm   ov009
 *   func_0216FF2C                0x0216FF2C arm   ov009
 *   func_021719A4                0x021719A4 arm   ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02175EB4  0x02175EB4  arm  ov009
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   func_0216CB90  0x0216CB90  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   func_0219F00C                0x0219F00C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_02171C08                0x02171C08 arm   ov009
 *   gpIsBuddy                    0x021861A8 arm   ov009
 *   func_021719D0                0x021719D0 arm   ov009
 *   func_0216F770                0x0216F770 arm   ov009
 *   func_02173D9C                0x02173D9C arm   ov009
 *   func_021768EC  0x021768EC  arm  ov009
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   func_021758C4  0x021758C4  arm  ov009
 *   g_021AAA20  0x021AAA20  data
 *   func_02176A8C  0x02176A8C  arm  ov009
 *   DWCi_GetMatchCnt       0x02175F3C arm
 *   qr2_send_statechanged  0x0219B490 arm
 *   func_02177748  0x02177748  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_NodeInfoList_GetMyNodeInfo           0x02176344 arm
 *   DWCi_GetGT2Connection                     0x0216BAF4 arm
 *   OS_GetTick     0x020870D0  arm
 *   func_0216BAF4  0x0216BAF4  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_02171F68  0x02171F68  arm  ov009
 */
#include "dwc_match_ctl_types.h"

extern struct NNThinkGlobal g_021AAA20;

extern int DWC_IsServerMyself(void);
extern u64 OS_GetTick(void);
extern int DWC_GetAIDBitmap(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const u32 *data, int len);
extern int func_021719A4(int error);
extern int func_0216F20C(int status);
extern u8 DWC_GetMyAID(void);
extern int func_0216CB90(void);
extern void func_0219F00C(void *p);
extern int func_02171C08(int delay, int init, int resendPid);
extern int gpIsBuddy(void **connection, int profile);
extern int func_021719D0(int profileID, int delay);
extern int func_0216F770(int profileID);
extern int func_02173D9C(int error);
extern void func_02176A8C(int a, int b);
extern void qr2_send_statechanged(void *qrec);
extern void func_02177748(int aid);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *DWCi_GetGT2Connection(unsigned char aid);
extern int func_0216BAF4(int aid);
extern void func_02199FB4(int cookie);
extern int func_02171F68(int unused);

int func_0217576C(int immediate);
static int func_021758C4(u8 AID, int suspend, int immediate);
int func_02175AA4(void);
void func_02175BFC(int suspend, void (*callback)(int, int, void *), void *suspendResultParam);
int func_02175C64(void);
static int func_02175D10(int suspend);
int func_02175EB4(void);
int func_02175EFC(void);
void func_02175F1C(DWCstMatchControl *a);
DWCstMatchControl *func_02175F3C(void);
void func_02175F4C(int state);
void DWCi_SetHostStatus(int host);
unsigned char func_02175FB8(void);
int func_02175FC8(void);
void func_02175FE4(void);
void func_0217601C(void);
int func_0217603C(void);
int func_0217604C(DWCstNodeInfo *newNode);
int func_021760FC(DWCstNodeInfo *newNode);
int func_02176164(unsigned char aid);
int func_02176254(int profileID);
DWCstNodeInfo *func_02176344(void);
DWCstNodeInfo *func_02176358(void);
DWCstNodeInfo *func_0217637C(int index);
DWCstNodeInfo *func_021763AC(int pid);
DWCstNodeInfo *func_02176410(unsigned char aid);
unsigned char func_02176474(void);
int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
void func_0217653C(void);
int func_02176554(void);
void func_0217656C(DWCstNodeInfo *p);
int func_02176580(const DWCstNodeInfo *p);
unsigned long long func_02176594(void);
int func_02176674(void);
int func_021767E4(void);
int func_021767F4(void);
int func_02176860(void);
void DWCi_ClearMeshMakingTempInfo(void);
void func_0217689C(void);
void func_021768EC(int result);
int func_0217695C(void);


int func_0217576C(int immediate)
{
    u32 sendData[3];
    DWCstNodeInfo *pNodeInfo;
    int result;
    int i;
    u64 tick;

    if (!DWC_IsServerMyself())
        return 1;
    if (func_02175F3C()->state == 0x13 || func_02175F3C()->state == 0x14)
        return 1;
    if (immediate == 0) {
        tick = OS_GetTick();
        if (((tick - func_02175F3C()->serverPollingTime) * 64) / 33514 <= 15000)
            goto done;
    }
    sendData[0] = func_02175F3C()->profileID;
    sendData[1] = DWC_GetAIDBitmap();
    sendData[2] = func_02175F3C()->flag7c8;
    for (i = 0; i < func_0217603C(); i++) {
        pNodeInfo = func_0217637C(i);
        if (pNodeInfo != func_02176344()) {
            result = func_0216FF2C(0x83, pNodeInfo->profileID, pNodeInfo->publicInetAddress, pNodeInfo->publicQueryPort, sendData, 3);
            if (func_021719A4(result))
                return -1;
        }
    }
    tick = OS_GetTick();
    func_02175F3C()->serverPollingTime = tick;
done:
    return 1;
}


static int func_021758C4(u8 AID, int suspend, int immediate)
{
    int i;
    u32 sendlen;
    u32 oldbitmap;
    u32 senddata[4];
    int result;
    int sm;
    u32 bitmap;
    DWCstNodeInfo *pServerNodeInfo;
    int bRet;

    result = 1;
    sendlen = 0;
    pServerNodeInfo = func_0217637C(0);
    oldbitmap = func_02175F3C()->suspendBitmap;
    if (suspend)
        func_02175F3C()->suspendBitmap |= result << AID;
    else
        func_02175F3C()->suspendBitmap &= ~(result << AID);
    if (oldbitmap != func_02175F3C()->suspendBitmap)
        func_0216F20C(-1);
    bitmap = func_02175F3C()->suspendBitmap;
    if (!func_02175EB4())
        bitmap &= ~(result << DWC_GetMyAID());
    sm = func_0216CB90();
    bRet = 1;
    if (!((suspend && sm) || (!suspend && !sm)))
        bRet = 0;
    if (immediate == 1) {
        DWCstNodeInfo *pNodeInfo;

        pNodeInfo = func_02176410(AID);
        senddata[sendlen++] = func_02175F3C()->profileID;
        senddata[sendlen++] = result;
        if (bRet) {
            if (func_02175F3C()->f_030 != 0) {
                senddata[sendlen++] = suspend;
                senddata[sendlen++] = bitmap;
            }
        }
        result = func_0216FF2C(0x82, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                               pNodeInfo->publicQueryPort, senddata, sendlen);
        if (func_021719A4(result))
            return 0;
    }
    if (bRet) {
        if (func_02175F3C()->f_030 != 1) {
            func_02175F3C()->f_030 = 1;
            senddata[0] = func_02175F3C()->profileID;
            senddata[1] = 1;
            senddata[2] = suspend;
            senddata[3] = bitmap;
            for (i = 0; i < func_0217603C(); i++) {
                DWCstNodeInfo *pNodeInfo = func_0217637C(i);

                if (pNodeInfo != pServerNodeInfo) {
                    result = func_0216FF2C(0x82, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                                           pNodeInfo->publicQueryPort, senddata, 4);
                    if (func_021719A4(result))
                        return 0;
                }
            }
        }
    }
    return 1;
}


/*
 * sdk:      DWCi_StartMatch (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02175AA4(void)
{
    int result;
    int sbError;

    if (func_02175F3C()->sbObj != 0)
        func_0219F00C(func_02175F3C()->sbObj);
    if (func_02175F3C()->connectGroupID != 0) {
        func_02175F4C(0xc);
    } else if (func_02175F3C()->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
    } else if (func_02175F3C()->qr2MatchTypeExt == 1) {
        func_02175F4C(3);
        result = 1;
        if (func_021719A4(func_02171C08(0, 1, 0)))
            result = 0;
        return result;
    } else if (func_02175F3C()->qr2MatchTypeExt == 2) {
        func_02175F4C(0xd);
        func_02175F3C()->f_00D = 1;
        return 1;
    } else if (func_02175F3C()->qr2MatchTypeExt == 3) {
        if (gpIsBuddy(func_02175F3C()->pGpObj, func_02175F3C()->tempNewNodeInfo.profileID)) {
            func_02175F4C(3);
            result = func_021719A4(func_021719D0(func_02175F3C()->tempNewNodeInfo.profileID, 0));
            if (result)
                return 0;
        }
        return 1;
    }
    func_02175F3C()->reqProfileID = 0;
    sbError = func_02173D9C(func_0216F770(func_02175F3C()->reqProfileID));
    result = 0;
    if (sbError == 0)
        result = 1;
    return result;
}


/*
 * sdk:      DWCi_RequestSuspendMatchInit (dwc_match.o)
 */
void func_02175BFC(int suspend, void (*callback)(int, int, void *), void *suspendResultParam)
{
    func_02175F3C()->f_030 = 0;
    func_02175F3C()->suspendRequest = suspend;
    func_02175F3C()->suspendCallback = callback;
    func_02175F3C()->suspendResultParam = suspendResultParam;
    func_02175F3C()->f_020 = 0;
    {
        u64 tick = OS_GetTick();
        func_02175F3C()->suspendStartTick = tick;
    }
    func_02175F3C()->f_048 = 1;
}


/*
 * sdk:      DWCi_RequestSuspendMatchProcess (dwc_match.o)
 */
int func_02175C64(void)
{
    int ret;
    int suspend;

    if (func_02175F3C()->f_048 == 0)
        return 0;
    if (func_02175F3C()->suspendRestart != 0) {
        func_02175BFC(func_02175F3C()->suspendRequest, func_02175F3C()->suspendCallback, func_02175F3C()->suspendResultParam);
        func_02175F3C()->suspendRestart = 0;
    }
    suspend = func_02175F3C()->suspendRequest;
    if (suspend == 0xff)
        return 0;
    ret = func_0216CB90();
    if ((suspend != 0 && ret != 0) || (suspend == 0 && ret == 0)) {
        func_021768EC(0);
        return 1;
    }
    func_02175D10(suspend);
    return 1;
}


/*
 * sdk:      DWCi_RequestSuspendMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The object reads the tick before it calls func_02175F3C for the store, which
 * a block-local copy reproduces (the DWARF lists no tick variable).
 */
static int func_02175D10(int suspend)
{
    DWCstNodeInfo *pServerNodeInfo;
    DWCstNodeInfo *pMyNodeInfo;
    u32 senddata[4];
    int result;

    if (func_02175FB8() == 2)
        return func_021758C4(func_02176344()->aid, suspend, 0);
    if (func_02175F3C()->state != 1)
        return 1;
    if (func_02175F3C()->f_030) {
        if (((OS_GetTick() - func_02175F3C()->f_020) * 64) / 33514 < func_02175F3C()->f_7CC)
            return 1;
    }
    if (((OS_GetTick() - func_02175F3C()->f_020) * 64) / 33514 > 3000) {
        pMyNodeInfo = func_02176344();
        pServerNodeInfo = func_0217637C(0);
        senddata[0] = func_02175F3C()->profileID;
        senddata[1] = 0;
        senddata[2] = suspend;
        senddata[3] = pMyNodeInfo->aid;
        result = func_0216FF2C(0x82, pServerNodeInfo->profileID, pServerNodeInfo->publicInetAddress,
                               pServerNodeInfo->publicQueryPort, senddata, 4);
        if (func_021719A4(result))
            return 0;
        {
            u64 now = OS_GetTick();
            func_02175F3C()->f_020 = now;
        }
        func_02175F3C()->f_7CC = 3000;
    }
    return 1;
}


/*
 * sdk:      DWCi_IsServerSuspendEnabled (dwc_match.o)
 */
int func_02175EB4(void)
{
    if (DWC_IsServerMyself()) {
        if (func_02175F3C()->state == 13 || func_02175F3C()->state == 22)
            return 1;
        return 0;
    }
    return 1;
}


/*
 * True while the match state is 9, 10 or 11.
 */
int func_02175EFC(void)
{
    unsigned int v = func_02175F3C()->state - 9;
    return v <= 2;
}


/*
 * Stores the match control block and the tick it was stored at.
 */
void func_02175F1C(DWCstMatchControl *a)
{
    unsigned long long v;
    g_021AAA20.pMatch = a;
    v = OS_GetTick();
    *(int *)(((char *)&g_021AAA20) + 0x18) = (int)v;
    *(int *)(((char *)&g_021AAA20) + 0x1c) = (int)(v >> 32);
}


/*
 * DWCi_GetMatchCnt: the match control block.
 */
DWCstMatchControl *func_02175F3C(void)
{
    return g_021AAA20.pMatch;
}


/*
 * DWCi_SetMatchStatus: records the new match state, logging a change first.
 */
void func_02175F4C(int state)
{
    if (g_021AAA20.pMatch->state != state) {
        func_02176A8C(g_021AAA20.pMatch->state, state);
    }
    g_021AAA20.pMatch->state = state;
}


void DWCi_SetHostStatus(int host)
{
    g_021AAA20.pMatch->qr2HostState = host;
    if (func_02175F3C()->qr2Obj != 0)
        qr2_send_statechanged(func_02175F3C()->qr2Obj);
}


unsigned char func_02175FB8(void)
{
    return func_02175F3C()->qr2HostState;
}


/*
 * Cleared when the word at +0x7b0 of the module block is one.
 */
int func_02175FC8(void)
{
    return func_02175F3C()->topologyType != 1;
}


/*
 * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record.
 */
void func_02175FE4(void)
{
    int i;

    for (i = 0; i < func_0217603C(); i++) {
        func_02177748(func_0217637C(i)->aid);
    }
}


/*
 * Clears the node count and the node list.
 */
void func_0217601C(void)
{
    MI_CpuFill8(&func_02175F3C()->nodeCount, 0, 0x504);
}


/*
 * Word at +0x50 of the block func_02175F3C returns.
 */
int func_0217603C(void)
{
    return func_02175F3C()->nodeCount;
}


/*
 * sdk:      DWCi_NodeInfoList_InsertToTop (dwc_match.o)
 */
int func_0217604C(DWCstNodeInfo *newNode)
{
    int i;

    if (func_02175F3C()->nodeCount == 32)
        return 0;
    for (i = func_02175F3C()->nodeCount; i > 0; i--)
        func_02175F3C()->nodeInfoList[i] = func_02175F3C()->nodeInfoList[i - 1];
    func_02175F3C()->nodeInfoList[0] = *newNode;
    func_02175F3C()->nodeCount += 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_Append (dwc_match.o)
 */
int func_021760FC(DWCstNodeInfo *newNode)
{
    if (func_02175F3C()->nodeCount == 32)
        return 0;
    func_02175F3C()->nodeInfoList[func_02175F3C()->nodeCount] = *newNode;
    func_02175F3C()->nodeCount += 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_RemoveAID (TwlDWC/libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The shift-down loop reads BOTH list bases first and only then does the index
 * arithmetic: the two func_02175F3C() results go into two locals, the
 * destination is node `i` (old i), then i is bumped, then the source is node
 * `i` (new i).  That is what makes the image keep the first result raw in r7
 * across the second call (`mov r7, r0`) and emit both `mla`s after it; folding
 * the arithmetic into the first call site loses those 4 bytes.
 */
int func_02176164(unsigned char aid)
{
    int removeAidIndex;
    int i;
    DWCstMatchControl *d;
    DWCstMatchControl *s;

    if (func_02175F3C()->nodeCount == 0) return 0;
    for (removeAidIndex = 0; removeAidIndex < func_02175F3C()->nodeCount;
         removeAidIndex++) {
        if (aid == func_02175F3C()->nodeInfoList[removeAidIndex].aid)
            break;
    }
    if (removeAidIndex == func_02175F3C()->nodeCount) return 0;
    for (i = removeAidIndex; i < func_02175F3C()->nodeCount - 1; ) {
        u8 *a = (u8 *)func_02175F3C();
        u8 *b = (u8 *)func_02175F3C();
        d = (DWCstMatchControl *)(a + i * 0x28);
        i++;
        s = (DWCstMatchControl *)(b + i * 0x28);
        d->nodeInfoList[0] = s->nodeInfoList[0];
    }
    func_02175F3C()->nodeCount -= 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_RemoveProfileID (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02176254(int profileID)
{
    int removeIndex;

    if (func_02175F3C()->nodeCount == 0)
        return 0;
    for (removeIndex = 0; removeIndex < func_02175F3C()->nodeCount; removeIndex++) {
        if (profileID == func_02175F3C()->nodeInfoList[removeIndex].profileID)
            break;
    }
    if (removeIndex == func_02175F3C()->nodeCount)
        return 0;
    for (; removeIndex < func_02175F3C()->nodeCount - 1; removeIndex++)
        func_02175F3C()->nodeInfoList[removeIndex] = func_02175F3C()->nodeInfoList[removeIndex + 1];
    func_02175F3C()->nodeCount--;
    return 1;
}


/*
 * DWCi_NodeInfoList_GetMyNodeInfo: the node record of this host.
 */
DWCstNodeInfo *func_02176344(void)
{
    return func_021763AC(func_02175F3C()->profileID);
}


/*
 * The first node record, or null when the list is empty.
 */
DWCstNodeInfo *func_02176358(void)
{
    DWCstMatchControl *p = func_02175F3C();
    if (p->nodeCount < 1) return 0;
    return func_02175F3C()->nodeInfoList;
}


/*
 * DWCi_NodeInfoList_GetNodeInfoForIndex: the node record at an index, or null past the count.
 */
DWCstNodeInfo *func_0217637C(int index)
{
    if (index >= func_02175F3C()->nodeCount) {
        return 0;
    }
    return &func_02175F3C()->nodeInfoList[index];
}


/*
 * DWCi_NodeInfoList_GetNodeInfoForProfileID: the node record whose profile id matches, or null.
 */
DWCstNodeInfo *func_021763AC(int pid)
{
    int i;

    for (i = 0; i < func_02175F3C()->nodeCount; i++) {
        if (pid == func_02175F3C()->nodeInfoList[i].profileID) {
            return &func_02175F3C()->nodeInfoList[i];
        }
    }
    return 0;
}


/*
 * sdk:      DWCi_NodeInfoList_GetNodeInfoForAID (dwc_match.o)
 *
 * Extra open callee of DWCi_DeleteAID (0x0216BCA4).
 */
DWCstNodeInfo *func_02176410(unsigned char aid)
{
    int i;

    for (i = 0; i < func_02175F3C()->nodeCount; i++) {
        if (aid == func_02175F3C()->nodeInfoList[i].aid)
            return &func_02175F3C()->nodeInfoList[i];
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

    if (func_02175F3C()->nodeCount == 32)
        return 0xff;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < func_02175F3C()->nodeCount; j++) {
            if (i == func_02175F3C()->nodeInfoList[j].aid)
                break;
        }
        if (j == func_02175F3C()->nodeCount)
            return i;
    }
    return 0xff;
}


int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID)
{
    DWCstNodeInfo *pNodeInfo = func_021763AC(profileID);

    if (pNodeInfo == 0)
        return 0;
    if (pNodeInfo == func_02176344())
        return 0;
    return DWCi_GetGT2Connection(pNodeInfo->aid) == 0;
}


/*
 * Clears the new-node record.
 */
void func_0217653C(void)
{
    func_0217656C(&func_02175F3C()->tempNewNodeInfo);
}


/*
 * True when the new-node record is in use.
 */
int func_02176554(void)
{
    return func_02176580(&func_02175F3C()->tempNewNodeInfo);
}


/*
 * Clears a node record.
 */
void func_0217656C(DWCstNodeInfo *p)
{
    MI_CpuFill8(p, 0, 0x28);
}


/*
 * True when the node record has a profile id.
 */
int func_02176580(const DWCstNodeInfo *p)
{
    return p->profileID != 0;
}


/*
 * sdk:      DWCi_GetNextMeshMakeTryTick (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
unsigned long long func_02176594(void)
{
    int existGT2Count;
    int i;
    int myNodeIndex;
    DWCstNodeInfo *pMyNodeInfo;
    unsigned long long tick;
    DWCstNodeInfo *pNodeInfo;

    pMyNodeInfo = func_02176344();
    tick = OS_GetTick();
    tick += 0x17F898;
    existGT2Count = 0;
    myNodeIndex = 0;
    if (func_0217603C() > 2) {
        for (i = 1; i < func_0217603C(); i++) {
            pNodeInfo = func_0217637C(i);
            if (pMyNodeInfo == pNodeInfo) {
                myNodeIndex = i;
            } else {
                DWCi_GetGT2Connection(pNodeInfo->aid);
                if (DWCi_GetGT2Connection(pNodeInfo->aid) != 0)
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
    if (func_02175F3C()->inMeshMaking == 0) {
        return 0;
    }
    func_02175F3C()->inMeshMaking = 0;
    func_02175F3C()->backupState = func_02175F3C()->state;
    if (func_02176554() != 0) {
        *(DWCstNodeInfo *)&func_02175F3C()->backupProfileID = func_02175F3C()->tempNewNodeInfo;
    } else {
        MI_CpuFill8(&func_02175F3C()->backupProfileID, 0, 0x28);
    }
    if (func_02175F3C()->nnInfo.cookie != 0) {
        func_02199FB4(func_02175F3C()->nnInfo.cookie);
        func_02175F3C()->nnInfo.cookie = 0;
        func_02175F3C()->f_5F8 = 0;
        func_02175F3C()->f_5FC = 0;
        func_02175F3C()->nnFailedTime = 0;
    }
    if (func_02175F3C()->state == 3 || func_02175F3C()->state == 5 ||
        func_02175F3C()->state == 6 || func_02175F3C()->state == 14 ||
        func_02175F3C()->state == 15) {
        if (func_02175F3C()->reqProfileID != 0) {
            if (func_021719A4(func_02171F68(0)) != 0) {
                func_0217653C();
                return 1;
            }
        }
        func_02175F3C()->qr2Flag18 = 0;
        func_02175F3C()->serverProfileID = 0;
    }
    func_0217653C();
    return 1;
}


/*
 * Word at +0x7c4 of the block func_02175F3C returns.
 */
int func_021767E4(void)
{
    return func_02175F3C()->flag7c4;
}


/*
 * Whether this host is the server of a running match that has not been the first server.
 */
int func_021767F4(void)
{
    if (func_02175F3C()->flag7d4 == 0) {
        return 0;
    }
    if (DWC_IsServerMyself() != 0 &&
        (func_02175F3C()->qr2MatchTypeExt == 1 || func_02175F3C()->qr2MatchTypeExt == 3 || func_02175F3C()->qr2MatchTypeExt == 2) &&
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
    return func_02175F3C()->topologyType;
}


void DWCi_ClearMeshMakingTempInfo(void)
{
    func_02175F3C()->backupState = 0;
    MI_CpuFill8(&func_02175F3C()->backupProfileID, 0, 0x28);
}


void func_0217689C(void)
{
    if (func_02175F3C()->suspendRequest == 0xff)
        return;
    if (func_02175F3C()->suspendRequest == 1)
        func_02175F3C()->suspendBitmap = DWC_GetAIDBitmap();
    else
        func_02175F3C()->suspendBitmap = 0;
    func_021768EC(0);
}


/*
 * sdk:      DWCi_SuspendComplete (dwc_match.o)
 */
void func_021768EC(int result)
{
    if (func_02175F3C()->suspendCallback != 0)
        func_02175F3C()->suspendCallback(result, func_02175F3C()->suspendRequest, func_02175F3C()->suspendResultParam);
    if (result == 0)
        qr2_send_statechanged(func_02175F3C()->qr2Obj);
    func_02175F3C()->suspendRequest = 0xff;
    func_02175F3C()->f_048 = 0;
}


/*
 * Set when the word at +0x7b0 of the module block is two.
 */
int func_0217695C(void)
{
    return func_02175F3C()->topologyType == 2;
}
