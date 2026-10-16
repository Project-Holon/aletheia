/*
 * function: DWCi_CancelPreConnectedServerProcessWithResetLevel
 * address:  0x02171FD4
 * packet:   pkt_ov009_02171FD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_CancelPreConnectedServerProcessWithResetLevel (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_TempNewNodeInfo_IsValid                0x02176554 arm   ov009
 *   DWCi_TempNewNodeInfo_Clear                0x0217653C arm   ov009
 *   func_02175F3C                0x02175F3C arm   ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   DWCi_GetHostStatus                0x02175FB8 arm   ov009
 *   DWCi_SetMatchStatus                0x02175F4C arm   ov009
 *   DWCi_CloseCancelHostAsync                0x02172E18 arm   ov009
 *   DWCi_NodeInfoList_GetCount                0x0217603C arm   ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex                0x0217637C arm   ov009
 *   DWCi_SendCancelMatchSynCommand                0x02173614 arm   ov009
 *   func_02172BB8                0x02172BB8 arm   ov009
 *   DWCi_StopMeshMaking                0x02176674 arm   ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
struct DWCstMatchControl {
    u8 pad0[0x18];
    u8 f18;
    u8 pad1[0x5dc - 0x19];
    int f5dc;
    u8 pad2[0x618 - 0x5e0];
    int f618;
    u8 pad3[0x632 - 0x61c];
    u16 f632;
    u8 pad4[0x654 - 0x634];
    int f654;
    u8 pad5[0x67c - 0x658];
    int f67c;
    u8 pad6[0x6d8 - 0x680];
    u8 f6d8;
};
struct DWCstNodeInfo { int profileID; };
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int func_02175F3C(void);
extern void NNCancel(int cookie);
extern unsigned char DWCi_GetHostStatus(void);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_CloseCancelHostAsync(int profileID);
extern int DWCi_NodeInfoList_GetCount(void);
extern char *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_SendCancelMatchSynCommand(int profileID, unsigned char command);
extern void func_02172BB8(int level);
extern int DWCi_StopMeshMaking(void);

int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel)
{
    struct DWCstNodeInfo *pNodeInfo;
    int i;

    if (DWCi_TempNewNodeInfo_IsValid())
        DWCi_TempNewNodeInfo_Clear();
    ((struct DWCstMatchControl *)func_02175F3C())->f6d8 = 0xff;
    if (((struct DWCstMatchControl *)func_02175F3C())->f618 != 0) {
        NNCancel(((struct DWCstMatchControl *)func_02175F3C())->f618);
        ((struct DWCstMatchControl *)func_02175F3C())->f618 = 0;
    }
    ((struct DWCstMatchControl *)func_02175F3C())->f67c = 0;
    if (DWCi_GetHostStatus() == 2) {
        ((struct DWCstMatchControl *)func_02175F3C())->f18 = 0;
        ((struct DWCstMatchControl *)func_02175F3C())->f5dc = 0;
        DWCi_SetMatchStatus(0x11);
        ((struct DWCstMatchControl *)func_02175F3C())->f654 = 0;
        ((struct DWCstMatchControl *)func_02175F3C())->f632 = 0;
        DWCi_CloseCancelHostAsync(clientPid);
        for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = (struct DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            if (!DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xd))
                return 0;
        }
        if (DWCi_NodeInfoList_GetCount() == 1)
            func_02172BB8(resetLevel);
    } else {
        DWCi_StopMeshMaking();
    }
    return 1;
}
