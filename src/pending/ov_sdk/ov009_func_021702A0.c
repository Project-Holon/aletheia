/*
 * function: func_021702A0
 * address: 0x021702A0
 * packet:  pkt_ov009_021702A0
 * region:  ov009
 * compiler:1.1p1
 * flags:   -O4,p
 * lang:    c99
 * isa:     arm
 * status:  DIFF
 *
 * measured (wave8, 2026-09-30): renamed the C definition/header to
 *          func_021702A0.  `match.py one --diff` now reports:
 *            compiled 852 bytes, 156 relocation sites, 150/156 resolved,
 *            204 concrete mismatching rows (~717 bytes) of 369 compared rows,
 *            6 unresolved (2x DWCi_HandleMatchCommandError @0x21779A4 has no
 *            witness outside the range -- contested ov009/ov014).
 *          IMPORTANT: the compared range is only 021702A0..021705F4 (852 B),
 *          NOT the 4396 B of the object -- a mid-function `func_` label at
 *          0x021705F4 cuts the extent (see idiom
 *          a-bl-target-inside-a-function-cuts-its-extent).  The image's real
 *          prologue is `push {r3,r4,r5,r6,r7,r8,sb,sl,fp,lr}` +
 *          `sub sp,sp,#0x170` with data/len read at [sp,#0x198]/[sp,#0x19c];
 *          the draft compiles `push {r3,r4,r5,lr}` with no frame, so it is
 *          wrong from +0000.  Case bodies are bare call skeleton (no argument
 *          set-up) which is why it is 852 B instead of 4396 B.
 *
 * blocker: no byte of this body is verified.  It compiles 852 bytes with
 *          push {r3, r4, r5, lr} where the image has
 *          push {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} + sub sp, sp, #0x170:
 *          the frame is wrong from +0000, the first differing byte, and the
 *          draft's case numbers are the jump-table index rather than the
 *          command values, so nothing in it is structure the image confirms
 *          (717 concrete byte(s) differ, 204 mismatching rows).  The whole
 *          function has to be written: 1099 instructions, 228 bl, 22 case
 *          blocks of 100-750 bytes each (command 2 alone is
 *          0x021703F4..0x021706DC, 744 bytes).  That is transcription, not
 *          discovery - the vendor object
 *          sdk/TwlDWC/lib/ARM9-TS/Rom/libdwcmatch.TWL.HYB.a (dwc_match.o) is
 *          byte-identical to the image over all 4396 bytes (0 concrete
 *          mismatches of 3712, 228 relocation fields) and
 *          `python tools/sdkobj.py 0x021702A0 --region ov009` prints its
 *          object-vs-image listing plus the DWARF prototype, the six register
 *          params, every local with its frame offset (senddata ulong[65] at
 *          [fb+108], DWCstNodeInfo peerNodeInfo at [fb+68], SOCSockAddrIn
 *          remoteaddr at [fb+20]) and the real prototypes of all 47 callees.
 *          Upstream lever dead: dwc_match.c is Nintendo DWC, not GameSpy, and
 *          neither sdk/TwlDWC/ nor vendor/*.zip ships .c for this library (the
 *          GameSpy clone in scratch/U2/gs holds no DWC match source).  The pin
 *          is right (dsi/1.1p1, rule 4e); the budget was the bound.
 *
 *          Dispatcher, measured off the object listing:
 *            if (command == 0x53) { suspend = 1; goto 0x021711F4; }
 *            else if (command > 0x53) -> the 0x54/0x55/0x70/0x82/0x83 chain
 *            else if (command == 0x40) goto 0x02171094;
 *            else switch (command) over 0..0x10, table at 0x02170354:
 *              0:D 1:D 2:0x021703F4 3:0x021706DC 4:0x02170920 5:0x021709B0
 *              6:0x02170AF4 7:0x02170B94 8:0x02170C98 9:0x02170DBC
 *              A:0x02170D58 B:0x02170EF0 C:D D:0x02170F50 E,F:0x02170FC4
 *              10:0x02170FE8      (D = the shared tail 0x021713BC)
 *            0x41..0x51 -> D; 0x52 -> 0x021710E4; 0x54 -> 0x02171274;
 *            0x55 -> 0x021712D0; 0x70 -> 0x021712D8; 0x82 -> 0x021712EC;
 *            0x83 -> 0x021713B4, which is DWCi_ProcessMatchPollingPacket(data)
 *            and falls through into the tail.
 *          The shared tail at 0x021713BC is `return 1`, not `return 0`; the
 *          only `return 0` in the function is at 0x021706D0.
 *
 *          Frame, from the DWARF locals matched against the image: fb == sp,
 *          `unsigned long senddata[65]` at fb+0x6C is the top of the 0x170
 *          frame (0x6C+0x104 = 0x170), `DWCstNodeInfo peerNodeInfo` at
 *          fb+0x1C and again at fb+0x44 (both filled by MI_CpuFill8(p,0,0x28)),
 *          `SOCSockAddrIn remoteaddr` at fb+0x14; the image's stores to
 *          [sp,#0x6c], [sp,#0x44] and [sp,#0x1c] confirm the three offsets.
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

static int func_021702A0(unsigned char command, int srcPid,
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
