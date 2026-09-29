/*
 * function:DWCi_ProcessRecvMatchCommand
 * address: 0x021702A0
 * packet:  pkt_ov009_021702A0
 * region:  ov009
 * compiler:1.1p1
 * flags:   -O4,p
 * lang:    c99
 * isa:     arm
 * status:  DIFF
 *
 * blocker: partial reconstruction.  The prologue, the switch on the
 *          state/command field and, per case, the real ordered callee
 *          sequence taken from the listing are transcribed.  The per-case
 *          guarding conditions and argument expressions are not yet
 *          reproduced, so the body is a genuine partial, not a match.
 *          Vendor extent 4396 bytes.
 *
 * sdk:      DWCi_ProcessRecvMatchCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   DWCi_IsError                     0x02059F38 arm
 *   OS_GetTick                       0x020870D0 arm
 *   func_0209C00C                    0x0209C00C arm
 *   DWC_CloseAllConnectionsHard      0x0216B65C arm
 *   DWC_GetState                     0x0216B994 arm
 *   DWCi_GetGT2Connection            0x0216BAF4 arm
 *   DWCi_CloseConnectionHard         0x0216BEA4 arm
 *   DWCi_StopResendingMatchCommand   0x0216EB48 arm
 *   DWCi_StopMatch                   0x0216EB68 arm
 *   DWCi_ProcessMatchPollingPacket   0x0216F058 arm
 *   DWCi_SBUpdateAsync               0x0216F770 arm
 *   DWCi_NNStartupAsync              0x0216FC34 arm
 *   DWCi_SendMatchCommand            0x0216FF2C arm
 *   DWCi_CheckResvCommand            0x021713CC arm
 *   DWCi_ProcessResvOK               0x02171884 arm
 *   DWCi_HandleMatchCommandError     0x021719A4 arm
 *   DWCi_SendResvCommand             0x021719D0 arm
 *   DWCi_RetryReserving              0x02171E34 arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720D8 arm
 *   DWCi_CancelPreConnectedClientProcess 0x02172124 arm
 *   DWCi_PostProcessConnection       0x02172254 arm
 *   DWCi_RestartFromCancel           0x02172BB8 arm
 *   DWCi_CloseAllConnectionsByTimeout 0x02172E7C arm
 *   DWCi_ProcessCancelMatchSynTimeout 0x021738EC arm
 *   DWCi_GetAIDFromProfileID         0x02173C84 arm
 *   DWCi_InitClWaitTimeout           0x02173CFC arm
 *   DWCi_HandleSBError               0x02173D9C arm
 *   DWCi_HandleNNError               0x02173EF8 arm
 *   DWCi_NNCompletedCallback         0x02174FE8 arm
 *   DWCi_SendServerDownQuery         0x02175458 arm
 *   DWCi_IsBackupMine                0x021754FC arm
 *   DWCi_SetupGameServer_InterChange 0x021755D4 arm
 *   DWCi_StartMatch                  0x02175AA4 arm
 *   DWCi_GetMatchCnt                 0x02175F3C arm
 *   DWCi_SetMatchStatus              0x02175F4C arm
 *   DWCi_IsServerChangeEnabled       0x02175FC8 arm
 *   DWCi_ResetLastSomeDataRecvTimeByAidAll 0x02175FE4 arm
 *   DWCi_NodeInfoList_GetCount       0x0217603C arm
 *   DWCi_NodeInfoList_InsertToTop    0x0217604C arm
 *   DWCi_NodeInfoList_GetMyNodeInfo  0x02176344 arm
 *   DWCi_NodeInfoList_GetServerNodeInfo 0x02176358 arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637C arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763AC arm
 *   DWCi_NodeInfoList_GetFreeAID     0x02176474 arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653C arm
 *   DWCi_GetNextMeshMakeTryTick      0x02176594 arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_GetTopologyType             0x02176860 arm
 *   DWCi_AutoSuspendComplete         0x0217689C arm
 *   DWCi_GetGT2NumConnection         0x02176960 arm
 *   DWCi_GetGT2NumConnection         0x02176978 arm
 *   DWCi_GetResvDenyReasonString     0x021769E0 arm
 *   DWCi_HandleMatchCommandError     0x021779A4 arm
 *   gpIsBuddy                        0x021861A8 arm
 *   gt2Think                         0x02195AF0 arm
 *   qr2_think                        0x0219B1E8 arm
 *   qr2_send_statechanged            0x0219B490 arm
 *   DWCi_GetFriendListIndex          0x21769038 arm
 *   DWCi_ProcessRequestMatch         0x217758C4 arm
 */

void *DWCi_GetMatchCnt();
extern int DWCi_IsError();
extern int OS_GetTick();
extern int func_0209C00C();
extern int DWC_CloseAllConnectionsHard();
extern int DWC_GetState();
extern int DWCi_GetGT2Connection();
extern int DWCi_CloseConnectionHard();
extern int DWCi_StopResendingMatchCommand();
extern int DWCi_StopMatch();
extern int DWCi_ProcessMatchPollingPacket();
extern int DWCi_SBUpdateAsync();
extern int DWCi_NNStartupAsync();
extern int DWCi_SendMatchCommand();
extern int DWCi_CheckResvCommand();
extern int DWCi_ProcessResvOK();
extern int DWCi_HandleMatchCommandError();
extern int DWCi_SendResvCommand();
extern int DWCi_RetryReserving();
extern int DWCi_CancelPreConnectedServerProcess();
extern int DWCi_CancelPreConnectedClientProcess();
extern int DWCi_PostProcessConnection();
extern int DWCi_RestartFromCancel();
extern int DWCi_CloseAllConnectionsByTimeout();
extern int DWCi_ProcessCancelMatchSynTimeout();
extern int DWCi_GetAIDFromProfileID();
extern int DWCi_InitClWaitTimeout();
extern int DWCi_HandleSBError();
extern int DWCi_HandleNNError();
extern int DWCi_NNCompletedCallback();
extern int DWCi_SendServerDownQuery();
extern int DWCi_IsBackupMine();
extern int DWCi_SetupGameServer_InterChange();
extern int DWCi_StartMatch();
extern int DWCi_SetMatchStatus();
extern int DWCi_IsServerChangeEnabled();
extern int DWCi_ResetLastSomeDataRecvTimeByAidAll();
extern int DWCi_NodeInfoList_GetCount();
extern int DWCi_NodeInfoList_InsertToTop();
extern int DWCi_NodeInfoList_GetMyNodeInfo();
extern int DWCi_NodeInfoList_GetServerNodeInfo();
extern int DWCi_NodeInfoList_GetNodeInfoForIndex();
extern int DWCi_NodeInfoList_GetNodeInfoForProfileID();
extern int DWCi_NodeInfoList_GetFreeAID();
extern int DWCi_TempNewNodeInfo_Clear();
extern int DWCi_GetNextMeshMakeTryTick();
extern int DWCi_StopMeshMaking();
extern int DWCi_GetTopologyType();
extern int DWCi_AutoSuspendComplete();
extern int DWCi_GetGT2NumConnection();
extern int DWCi_GetGT2NumConnection();
extern int DWCi_GetResvDenyReasonString();
extern int DWCi_HandleMatchCommandError();
extern int gpIsBuddy();
extern int gt2Think();
extern int qr2_think();
extern int qr2_send_statechanged();
extern int DWCi_GetFriendListIndex();
extern int DWCi_ProcessRequestMatch();

static int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
    unsigned long srcIP, unsigned short srcPort, unsigned long *data, int len)
{
    if (DWCi_GetMatchCnt() == 0 ||
        ((int *)((char *)DWCi_GetMatchCnt() + 0x61C))[0] == 0)
        return 1;
    if (DWC_GetState() == 4 &&
        ((int *)((char *)DWCi_GetMatchCnt() + 0x61C))[0] == 1 &&
        DWCi_NodeInfoList_GetCount() > 0 &&
        srcPid == ((int *)DWCi_NodeInfoList_GetNodeInfoForIndex(0))[0])
        DWCi_InitClWaitTimeout();
    switch (command) {

    case 1:
        func_02082BCC();
        DWCi_CheckResvCommand();
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt();
        DWCi_ProcessResvOK();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetNodeInfoForProfileID();
        DWCi_GetMatchCnt();
        func_02169038();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetMyNodeInfo();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        DWCi_GetResvDenyReasonString();
        DWCi_GetMatchCnt();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        break;
    case 2:
        DWCi_GetMatchCnt();
        func_02082BCC();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetMyNodeInfo();
        DWCi_GetMatchCnt();
        DWCi_SetMatchStatus();
        DWCi_SBUpdateAsync();
        DWCi_HandleSBError();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        DWCi_NNStartupAsync();
        DWCi_HandleNNError();
        break;
    case 3:
        DWCi_GetMatchCnt();
        DWCi_StopMeshMaking();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        DWCi_StopMatch();
        DWCi_GetMatchCnt();
        DWCi_RetryReserving();
        break;
    case 4:
        DWCi_GetMatchCnt();
        DWCi_StopMeshMaking();
        DWCi_GetMatchCnt();
        gpIsBuddy();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        DWCi_TempNewNodeInfo_Clear();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        DWCi_TempNewNodeInfo_Clear();
        func_02171C08();
        DWCi_GetMatchCnt();
        break;
    case 5:
        DWCi_GetMatchCnt();
        DWCi_StopMeshMaking();
        DWCi_GetMatchCnt();
        func_02176554();
        DWCi_GetMatchCnt();
        func_0216BBDC();
        DWCi_GetMatchCnt();
        func_02195DE4();
        DWCi_CancelPreConnectedServerProcess();
        break;
    case 6:
        func_02176554();
        func_0217695C();
        DWCi_GetMatchCnt();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        func_02195E60();
        DWCi_GetMatchCnt();
        DWCi_NNCompletedCallback();
        DWCi_GetMatchCnt();
        break;
    case 7:
        DWCi_StopMeshMaking();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetNodeInfoForIndex();
        DWCi_GetMatchCnt();
        func_0217695C();
        DWCi_GetMatchCnt();
        func_02169038();
        DWCi_GetMatchCnt();
        break;
    case 9:
        DWCi_GetGT2NumConnection();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetNodeInfoForIndex();
        DWCi_GetMatchCnt();
        DWCi_PostProcessConnection();
        break;
    case 8:
        DWCi_GetMatchCnt();
        DWCi_GetGT2Connection();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        DWCi_NNStartupAsync();
        break;
    case 10:
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetServerNodeInfo();
        DWCi_GetMatchCnt();
        break;
    case 12:
        DWCi_GetMatchCnt();
        DWCi_CancelPreConnectedClientProcess();
        DWCi_GetMatchCnt();
        DWCi_CloseAllConnectionsByTimeout();
        DWCi_RestartFromCancel();
        break;
    case 13:
        func_021736AC();
        break;
    case 14:
        func_021736AC();
        break;
    case 15:
        func_021736AC();
        break;
    case 16:
        DWCi_NodeInfoList_GetServerNodeInfo();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetNodeInfoForProfileID();
        DWCi_GetMatchCnt();
        DWCi_CloseConnectionHard();
        DWCi_GetMatchCnt();
        DWCi_CloseConnectionHard();
        DWCi_GetMatchCnt();
        func_02176554();
        DWCi_GetMatchCnt();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        DWCi_IsBackupMine();
        DWCi_GetMatchCnt();
        DWCi_GetAIDFromProfileID();
        DWCi_NodeInfoList_GetNodeInfoForIndex();
        DWCi_GetMatchCnt();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        OS_GetTick();
        DWCi_GetMatchCnt();
        DWCi_SetMatchStatus();
        DWCi_ResetLastSomeDataRecvTimeByAidAll();
        DWCi_GetMatchCnt();
        DWCi_IsBackupMine();
        DWCi_GetAIDFromProfileID();
        DWCi_GetMatchCnt();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt();
        DWC_CloseAllConnectionsHard();
        OS_GetTick();
        DWCi_GetMatchCnt();
        DWCi_SBUpdateAsync();
        DWCi_InitClWaitTimeout();
        DWCi_NodeInfoList_GetNodeInfoForProfileID();
        func_02175FB8();
        func_021758C4();
        func_02175FB8();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        DWCi_ProcessMatchPollingPacket();
        break;
    default:
        break;
    }
    return 0;
}
