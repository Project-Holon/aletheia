/*
 * function:DWCi_MatchProcess
 * address: 0x0216D57C
 * packet:  pkt_ov009_0216D57C
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
 *          Vendor extent 3908 bytes.
 *
 * U63 (measured 2026-09-30): the parked body still compiles to 1028 bytes of
 * the 3908-byte extent (241 differing instruction slots); the per-case guard
 * conditions and argument expressions are still absent. Parked as a partial.
 *
 * W8 (measured 2026-10-01): the 5 `DWCi_HandleMatchCommandError` sites were
 * unresolved because TWO `symbols:` lines carried that name, 0x021719A4 and
 * 0x021779A4; the 0x021779A4 line (a different, contested ov014 address) was
 * shadowing the real one. The vendor object targets 0x021719A4 at all five
 * sites, so the 0x021779A4 line was removed and all 204 relocation sites now
 * resolve (was 199/204). The body is unchanged, so this is still a partial.
 *
 * W8b (2026-10-01, 15-min lane): the parked body is a placeholder call
 * sequence, NOT the real control flow, so it cannot be nudged to EXACT; the
 * real function needs a from-scratch rewrite from the vendor listing
 * (`python tools/sdkobj.py 0x0216D57C --region ov009`), which is ~1300
 * instructions / 3908 bytes extent / 3195 concrete bytes. Structural map now
 * established from that listing (state field is mc->0x61C, NOT mc->0x15):
 *
 *   entry:   ret=1 (r4), zero (r7); early-out if !GetMatchCnt() || IsError();
 *            fullSpec==0 -> qr2_think(mc->0x10)/gt2Think(mc->0x04); then
 *            if (mc->0x61C==0) return; switch(mc->0x61C) dense 0..0x16:
 *     idx:   0,1          -> default 0x216E0F4
 *            2            -> 0x216DCB4   3,5,22 -> 0x216D8A4
 *            4            -> 0x216D684   7      -> 0x216D97C
 *            10           -> 0x216DDB4   11     -> 0x216DE7C
 *            12           -> 0x216DFC8   13     -> 0x216E05C
 *            15           -> 0x216DB28   17     -> 0x216DC1C
 *            others       -> 0x216E0F4
 *   Each case is 150-550 bytes of tick arithmetic (64-bit OS_GetTick diff
 *   via _ll_udiv, shift 6 / udiv by pool divisor) and null-guarded reads of
 *   distinct mc offsets (0x5e4,0x608/0x60c,0x638/0x63c/0x640,0x644,
 *   0x648/0x64c,0x670/0x674,0x6d8/0x6d9,0x760/0x764,0x768/0x76c,0x798,
 *   0x7ac,0x7b6). sbInterval = (case==2 && mc->0x5e4==1) || mc->0x7ac<=1
 *   ? 0xFA0 : <pool>; SBUpdateAsync(mc->0x67C) -> HandleSBError(result).
 *   Status: DIFF, blocker = full body not yet rewritten.
 *
 * The exact spec is available: `python tools/sdkobj.py 0x0216D57C --region
 * ov009` prints the vendor object's own listing (0 concrete mismatches of
 * 3195 concrete bytes, i.e. byte-identical to the image) with every PC24
 * target resolved, plus the DWARF prototype, the complete local list and
 * struct layouts. True callee names the placeholder func_ names map to:
 *   func_0209C00C = _ll_udiv
 *   func_02176870 = DWCi_ClearMeshMakingTempInfo
 *   func_0219EFD0 = ServerBrowserThink
 *   func_0219ED4C = ServerBrowserFree
 *   func_0219F024 = ServerBrowserState
 *   func_0216D540 = DWCi_SendStateChanged
 *   func_0219A4A4 = NNThink
 *   func_0219922C = NNFreeNegotiateList
 *   func_02172DE8 = DWCi_ResumeMatch
 *   func_02175C64 = DWCi_RequestSuspendMatchProcess
 *   func_0217576C = DWCi_SendServerPolling
 *   func_021732F8 = DWCi_ProcessMatchSynTimeout
 * DWARF locals (reverse declaration order): pNodeInfo(r6), connection(r0),
 * i(r5), info(r0), noResponseHosts(r6), mc(r5), idx(r0), node(r6),
 * sbError(r0), result(r0), sbInterval(r5); param fullSpec(r5).
 *
 * sdk:      DWCi_MatchProcess (libdwcmatch.TWL.HYB.a dwc_match.o)
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

void DWCi_MatchProcess(int fullSpec)
{
    if (DWCi_GetMatchCnt() == 0)
        return;
    if (DWCi_IsError())
        return;
    if (fullSpec == 0) {
        if (((void **)((char *)DWCi_GetMatchCnt() + 0x10))[0] != 0)
            qr2_think(((void **)((char *)DWCi_GetMatchCnt() + 0x10))[0]);
        if (((void **)((char *)DWCi_GetMatchCnt() + 0x4))[0] != 0)
            gt2Think(*(void **)((char *)DWCi_GetMatchCnt() + 0x4));
        return;
    }
    if (((int *)((char *)DWCi_GetMatchCnt() + 0x61C))[0] == 0)
        return;
    switch (((int *)((char *)DWCi_GetMatchCnt() + 0x61C))[0]) {

    case 3:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_StopMatch();
        DWCi_RetryReserving();
        DWCi_StopMeshMaking();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        DWCi_StopMatch();
        DWCi_GetMatchCnt();
        DWCi_SendResvCommand();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        DWCi_TempNewNodeInfo_Clear();
        DWCi_RetryReserving();
        DWCi_TempNewNodeInfo_Clear();
        DWCi_RetryReserving();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_SendResvCommand();
        DWCi_HandleMatchCommandError();
        break;
    case 2:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_SBUpdateAsync();
        DWCi_HandleSBError();
        break;
    case 4:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_SBUpdateAsync();
        DWCi_HandleSBError();
        break;
    case 6:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_StopMeshMaking();
        DWCi_GetMatchCnt();
        DWCi_CancelPreConnectedClientProcess();
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_StopMeshMaking();
        DWCi_StopResendingMatchCommand();
        DWCi_GetMatchCnt();
        DWCi_StopResendingMatchCommand();
        DWCi_GetMatchCnt();
        DWCi_CancelPreConnectedClientProcess();
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        break;
    case 14:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_StopResendingMatchCommand();
        DWCi_StopMeshMaking();
        DWCi_GetMatchCnt();
        DWCi_CancelPreConnectedServerProcess();
        break;
    case 16:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_StopResendingMatchCommand();
        DWCi_GetMatchCnt();
        DWCi_CancelPreConnectedServerProcess();
        break;
    case 1:
        DWC_GetState();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_CancelPreConnectedClientProcess();
        DWCi_SendMatchCommand();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        break;
    case 9:
        DWCi_StopMeshMaking();
        DWCi_GetMatchCnt();
        DWCi_IsBackupMine();
        DWCi_NodeInfoList_GetNodeInfoForIndex();
        DWCi_GetGT2Connection();
        DWCi_StopMatch();
        DWCi_GetAIDFromProfileID();
        DWCi_IsBackupMine();
        DWCi_IsServerChangeEnabled();
        DWCi_StopMatch();
        DWCi_SendServerDownQuery();
        DWCi_SetMatchStatus();
        DWCi_GetMatchCnt();
        qr2_send_statechanged();
        DWCi_InitClWaitTimeout();
        DWCi_GetMatchCnt();
        qr2_send_statechanged();
        DWCi_SetMatchStatus();
        break;
    case 10:
        DWCi_IsBackupMine();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_SendServerDownQuery();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetCount();
        DWCi_NodeInfoList_GetNodeInfoForIndex();
        DWCi_CloseConnectionHard();
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        break;
    case 11:
        DWCi_IsBackupMine();
        DWCi_IsServerChangeEnabled();
        DWCi_SetupGameServer_InterChange();
        DWCi_GetMatchCnt();
        DWCi_ResetLastSomeDataRecvTimeByAidAll();
        DWCi_AutoSuspendComplete();
        DWCi_GetMatchCnt();
        qr2_send_statechanged();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        break;
    case 12:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_SBUpdateAsync();
        DWCi_HandleSBError();
        DWCi_GetMatchCnt();
        break;
    default:
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        DWCi_GetMatchCnt();
        DWCi_NNCompletedCallback();
        DWCi_GetTopologyType();
        DWCi_GetMatchCnt();
        DWCi_NodeInfoList_GetCount();
        DWCi_NodeInfoList_GetNodeInfoForIndex();
        DWCi_NodeInfoList_GetMyNodeInfo();
        DWCi_GetGT2Connection();
        DWCi_GetNextMeshMakeTryTick();
        OS_GetTick();
        DWCi_GetNextMeshMakeTryTick();
        DWCi_GetMatchCnt();
        DWCi_SendResvCommand();
        DWCi_HandleMatchCommandError();
        DWCi_GetMatchCnt();
        DWCi_TempNewNodeInfo_Clear();
        func_02176870();
        DWCi_SetMatchStatus();
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt();
        func_0219EFD0();
        DWCi_GetMatchCnt();
        func_0219ED4C();
        DWCi_GetMatchCnt();
        func_0219F024();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        DWCi_StopMatch();
        DWCi_GetMatchCnt();
        func_0216D540();
        func_0219A4A4();
        func_0219922C();
        DWCi_GetMatchCnt();
        gt2Think();
        DWCi_GetMatchCnt();
        OS_GetTick();
        DWCi_GetMatchCnt();
        func_0209C00C();
        func_02172DE8();
        func_02175C64();
        func_0217576C();
        func_021732F8();
        DWCi_ProcessCancelMatchSynTimeout();
        break;
    }
}
