/*
 * file:     dwc_match.c
 * unit:     yes
 * function: DWC_CancelMatch, DWC_IsValidCancelMatch, DWC_AddMatchKeyInt, DWC_AddMatchKeyString, DWC_GetMatchIntValue, DWC_GetSuspendMatch, DWCi_MatchInit, DWCi_QR2Startup, DWCi_ConnectToAnybodyAsync, DWCi_SetupGameServer, func_0216D27C, DWCi_SendStateChanged, func_0216D57C, DWCi_GT2UnrecognizedMessageCallback, DWCi_GT2ConnectAttemptCallback, DWCi_MakeGT2ConnectString, DWCi_GT2ConnectedCallback, func_0216EAB8, DWCi_StopResendingMatchCommand, DWCi_StopMatch, DWCi_ClearQR2Key, DWCi_ProcessMatchSynPacket, DWCi_ProcessMatchSynPacketSub_Hybrid, DWCi_ProcessMatchSynPacketSub, DWCi_CheckDeadAIDBitmap, DWCi_ProcessMatchPollingPacket, DWCi_ProcessMatchClosing, func_0216F1E8, DWCi_GPSetServerStatus, func_0216F334, DWCi_IsShutdownMatch, func_0216F388, DWCi_SetMatchCommonParam, DWCi_CloseMatch, DWCi_SBUpdateAsync, DWCi_GetDefaultMatchFilter, IsPrivateAddr, func_0216FC34, DWCi_DoNatNegotiationAsync, DWCi_CanSendMatchCommandDirect, DWCi_SendMatchCommand, DWCi_EncodeBinaryMsgCommand, DWCi_SendSBMsgCommand, DWCi_SendGPBuddyMsgCommand, DWCi_ProcessRecvMatchCommand, DWCi_CheckResvCommand, func_02171524, DWCi_ProcessResvOK, DWCi_HandleMatchCommandError, DWCi_SendResvCommand, DWCi_SendResvCommandToFriend, DWCi_RetryReserving, DWCi_CancelReservation, DWCi_CancelPreConnectedServerProcessWithResetLevel, func_021720D8, DWCi_CancelPreConnectedClientProcess, DWCi_PostProcessConnection, DWCi_PostProcessConnectionSYNFinish, func_0217253C, DWCi_PostProcessConnectionSYNFinishFullmesh, DWCi_PostProcessSVConnectionHybrid, DWCi_PostProcessSVConnectionFullmesh, DWCi_DoCancelMatch, DWCi_FinishCancelMatch, DWCi_InvalidateReservation, func_02172BB8, DWCi_RestartFromTimeout, DWCi_ResumeMatch, DWCi_CloseCancelHostAsync, DWCi_CloseAllConnectionsByTimeout, DWCi_CloseShutdownClientSC, DWCi_SendMatchSynPacket, func_021732F8, DWCi_ServerSynTimeoutExec, DWCi_SendTypeMatchAck, DWCi_SendCancelMatchSynCommand, func_021736AC, func_021738EC, DWCi_GetNewMatchKey, DWCi_ClearGameMatchKeys, DWCi_IsFriendByIdxList, DWCi_CheckDWCServer, DWCi_GetAIDFromProfileID, DWCi_GetAIDBitmask, DWCi_InitClWaitTimeout, func_02173D28, DWCi_HandleSBError, DWCi_HandleQR2Error, DWCi_HandleNNError, DWCi_HandleNNResult, func_02173FB4, DWCi_SBCallback, DWCi_DebugPrintServerList, DWCi_EvaluateServers, DWCi_RandomizeServers, DWCi_QR2ServerKeyCallback, DWCi_QR2PlayerKeyCallback, DWCi_QR2TeamKeyCallback, DWCi_QR2KeyListCallback, DWCi_QR2CountCallback, DWCi_QR2AddErrorCallback, func_02174D04, DWCi_QR2NatnegCallback, func_02174E10, DWCi_QR2ClientMsgCallback, DWCi_NNProgressCallback, func_02174FE8, DWCi_ProcessNNFailure, DWCi_SendServerDownQuery, DWCi_IsBackupMine, DWCi_CreateGroupID, DWCi_SetConnectionAttemptParam, DWCi_SetupGameServer_InterChange, DWCi_ConnectToGameServerAsync_InterChange, DWCi_GetNumConnectionHost, DWCi_SendServerPolling, DWCi_ProcessRequestMatch, DWCi_StartMatch, DWCi_RequestSuspendMatchInit, DWCi_RequestSuspendMatchProcess, DWCi_RequestSuspendMatch, DWCi_IsServerSuspendEnabled, DWCi_IsServerChanging, DWCi_SetMatchCnt, func_02175F3C, DWCi_SetMatchStatus, DWCi_SetHostStatus, func_02175FB8, DWCi_IsServerChangeEnabled, DWCi_ResetLastSomeDataRecvTimeByAidAll, DWCi_NodeInfoList_Clear, DWCi_NodeInfoList_GetCount, DWCi_NodeInfoList_InsertToTop, DWCi_NodeInfoList_Append, DWCi_NodeInfoList_RemoveAID, DWCi_NodeInfoList_RemoveProfileID, DWCi_NodeInfoList_GetMyNodeInfo, DWCi_NodeInfoList_GetServerNodeInfo, DWCi_NodeInfoList_GetNodeInfoForIndex, DWCi_NodeInfoList_GetNodeInfoForProfileID, DWCi_NodeInfoList_GetNodeInfoForAID, DWCi_NodeInfoList_GetFreeAID, func_02176500, DWCi_TempNewNodeInfo_Clear, DWCi_TempNewNodeInfo_IsValid, DWCi_NodeInfo_Clear, DWCi_NodeInfo_IsValid, DWCi_GetNextMeshMakeTryTick, DWCi_StopMeshMaking, DWCi_IsFirstServer, DWCi_IsServerLocked, DWCi_GetTopologyType, func_02176870, DWCi_AutoSuspendComplete, DWCi_SuspendComplete, DWCi_IsFullMesh, DWCi_GetNodeInfoCount, DWCi_IsLockedBuddyStatus, DWCi_GetResvDenyReasonString, disp_match_state, DWCi_SetMatchmakeProfileId, DWCi_RegisterMatchmakeKeys, func_02176B34
 * address:  0x0216C858
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 * Empty stub; nothing but a return.
 * sdk:      DWCi_QR2KeyListCallback (dwc_match.o)
 * sdk:      DWCi_QR2CountCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 * notes:    a stub the listing printed as data; DWCi_QR2Startup's relocation
 *           at +0x17C (ABS32 DWCi_QR2CountCallback) is the pool word at
 *           0x0216CF08.  Seeded in layout/function_starts.txt.
 *   DWCi_HandleQR2Error  0x02173E30  arm  ov009
 * sdk:      DWCi_NNProgressCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 * notes:    a 4-byte `bx lr`; DWCi_DoNatNegotiationAsync's relocation at +0xB8
 *           (ABS32 DWCi_NNProgressCallback) is the pool word at
 *           0x0216FEEC.  Seeded in layout/function_starts.txt.
 * dwc_match.o of the DWC match library: suspend requests, the node-info list,
 * the match control block accessors.
 *
 * symbols:
 *   DWCi_DoCancelMatch      0x021728B8 arm
 *   DWCi_IsError      0x02059F38 arm
 *   DWC_GetState      0x0216B994 arm
 *   g_021AAA40     0x021AAA40  data  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_02094798  0x02094798  arm
 *   func_0219D158  0x0219D158  arm  ov009
 *   g_021AAA44                   0x021AAA44 data
 *   g_021AAA41                   0x021AAA41 data
 *   g_021AAA42                   0x021AAA42 data
 *   g_021AAA48                   0x021AAA48 data
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02059F38  0x02059F38  arm
 *   func_0219F058  0x0219F058  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0216F388  0x0216F388  arm  ov009
 *   gt2GetSocketSOCKET  0x02195E60  arm  ov009
 *   gt2GetLocalPort  0x02195E40  arm  ov009
 *   qr2_init_socketA  0x0219AEB4  arm  ov009
 *   qr2_shutdown  0x0219B540  arm  ov009
 *   func_0219B1AC  0x0219B1AC  arm  ov009
 *   func_0219B134  0x0219B134  arm  ov009
 *   func_0219B170  0x0219B170  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_02174D04  0x02174D04  arm  ov009
 *   DWC_Free                0x0205A1B0  arm
 *   DWC_Alloc               0x0205A16C  arm
 *   MI_CpuCopy8             0x02082D44  arm
 *   func_0219EC74           0x0219EC74  arm  ov009
 *   g_021AAA20              0x021AAA20  data
 *   g_021A2044              0x021A2044  data
 *   func_02175F84  0x02175F84  arm  ov009
 *   func_02175530  0x02175530  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   qr2_think         0x0219B1E8 arm
 *   gt2Think                         0x02195af0 arm
 *   OS_GetTick                       0x020870d0 arm
 *   _ll_udiv                         0x0209c00c arm
 *   DWCi_StopMatch                   0x0216eb68 arm
 *   DWCi_RetryReserving              0x02171e34 arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_SetMatchStatus              0x02175f4c arm
 *   DWCi_HandleMatchCommandError     0x021719a4 arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653c arm
 *   DWCi_SBUpdateAsync               0x0216f770 arm
 *   DWCi_HandleSBError               0x02173d9c arm
 *   DWCi_CancelPreConnectedClientProcess 0x02172124 arm
 *   DWCi_StopResendingMatchCommand   0x0216eb48 arm
 *   DWCi_SendMatchCommand            0x0216ff2c arm
 *   DWCi_IsBackupMine                0x021754fc arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637c arm
 *   DWCi_GetGT2Connection            0x0216baf4 arm
 *   DWCi_GetAIDFromProfileID         0x02173c84 arm
 *   DWCi_IsServerChangeEnabled       0x02175fc8 arm
 *   DWCi_SendServerDownQuery         0x02175458 arm
 *   qr2_send_statechanged            0x0219b490 arm
 *   DWCi_InitClWaitTimeout           0x02173cfc arm
 *   DWCi_NodeInfoList_GetCount       0x0217603c arm
 *   DWCi_CloseConnectionHard         0x0216bea4 arm
 *   DWCi_SetupGameServer_InterChange 0x021755d4 arm
 *   DWCi_ResetLastSomeDataRecvTimeByAidAll 0x02175fe4 arm
 *   DWCi_AutoSuspendComplete         0x0217689c arm
 *   DWCi_GetTopologyType             0x02176860 arm
 *   DWCi_NodeInfoList_GetMyNodeInfo  0x02176344 arm
 *   DWCi_GetNextMeshMakeTryTick      0x02176594 arm
 *   ServerBrowserThink               0x0219efd0 arm
 *   ServerBrowserFree                0x0219ed4c arm
 *   ServerBrowserState               0x0219f024 arm
 *   NNThink                          0x0219a4a4 arm
 *   NNFreeNegotiateList              0x0219922c arm
 *   DWCi_RequestSuspendMatchProcess  0x02175c64 arm
 *   DWCi_SendServerPolling           0x0217576c arm
 *   s_anybodyServerSearchRatio       0x021a203c data
 *   s_bInNNThink                     0x021aaa20 data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   qr2_parse_queryA   0x0219C7C0  arm  ov009
 *   func_020923F0   0x020923F0  arm
 *   func_0219AB8C   0x0219AB8C  arm  ov009
 *   g_021A5A7C      0x021A5A7C  data
 *   gt2Reject                        0x02195B38 arm
 *   strtoul                          0x02095EAC arm
 *   DWCi_GT2GetConnectionListIdx     0x0216BB6C arm
 *   gt2Accept                        0x02195B2C arm
 *   DWCi_GetGT2ConnectionByIdx       0x0216BBCC arm
 *   DWCi_GetConnectionInfoByIdx      0x0216BC2C arm
 *   DWCi_ResetLastSomeDataRecvTimeByAid 0x02177748 arm
 *   gt2SetConnectionData             0x02195E70 arm
 *   g_021A204C                       0x021A204C data
 *   g_021A2058                       0x021A2058 data
 *   g_021A2064                       0x021A2064 data
 *   OS_SNPrintf       0x02084F80 arm
 *   g_021A207C        0x021A207C data
 *   gt2AddressToString               0x02198620 arm
 *   gt2Connect                       0x02195B44 arm
 *   DWCi_HandleGT2Error              0x02173FB4 arm
 *   strlen         0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 *   DWCi_SetError  0x02059F54  arm
 *   func_02169038  0x02169038  arm  ov009
 *   DWCi_IsFullMesh                        0x0217695C arm
 *   DWCi_ProcessMatchSynPacketSub_FullMesh 0x0216F008 arm
 *   DWCi_ProcessMatchSynPacketSub_Hybrid   0x0216EC84 arm
 *   DWCi_NodeInfoList_InsertToTop    0x0217604C arm
 *   DWCi_GetMathRand32               0x021685CC arm
 *   DWCi_SendTypeMatchAck            0x021735A4 arm
 *   DWC_IsServerMyself  0x0216BA08  arm  ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_02172BB8                0x02172BB8 arm   ov009
 *   d_021A207C  0x021A207C  data
 *   d_021A2080  0x021A2080  data
 *   d_021A2084  0x021A2084  data
 *   d_021A2088  0x021A2088  data
 *   d_021A208C  0x021A208C  data
 *   func_02168454  0x02168454  arm  ov009
 *   func_0216848C  0x0216848C  arm  ov009
 *   func_021690D0  0x021690D0  arm  ov009
 *   DWCi_SetMatchCnt         0x02175F1C arm
 *   DWCi_ClearGameMatchKeys  0x02173B18 arm
 *   DWCi_GetHostStatus            0x02175FB8  arm  ov009
 *   DWCi_NodeInfoList_Clear       0x0217601C  arm  ov009
 *   func_0219ED4C  0x0219ED4C  arm  ov009
 *   func_02176B34  0x02176B34  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_0219F00C  0x0219F00C  arm  ov009
 *   func_0219EED4  0x0219EED4  arm  ov009
 *   stGameMatchKeys          0x021AAA40  data
 *   d_021A2090     0x021A2090  data
 *   d_021A209C     0x021A209C  data
 *   d_021A20A4     0x021A20A4  data
 *   d_021A20AC     0x021A20AC  data
 *   d_021A20D4     0x021A20D4  data
 *   d_021A20E0     0x021A20E0  data
 *   OS_SNPrintf  0x02084F80  arm
 *   g_021A20E0     0x021A20E0  data
 *   g_021A20F0     0x021A20F0  data
 *   g_021A209C     0x021A209C  data
 *   g_021A20A4     0x021A20A4  data
 *   g_021A2170     0x021A2170  data
 *   g_021A217C     0x021A217C  data
 *   g_021A2108     0x021A2108  data
 *   g_021A2164     0x021A2164  data
 *   ServerBrowserGetMyPublicIPAddr   0x0219F0D8 arm
 *   SOC_GetHostID                    0x0215F7B0 arm
 *   IsPrivateAddr                    0x0216FBB8 arm
 *   DWCi_DoNatNegotiationAsync       0x0216FE34 arm
 *   func_02198620  0x02198620  arm  ov009
 *   func_0219EF60  0x0219EF60  arm  ov009
 *   func_02199DFC  0x02199DFC  arm  ov009
 *   func_02174FE8  0x02174FE8  arm  ov009
 *   DWCi_GetGT2ConnectionByProfileID  0x0216BBDC  arm  ov009
 *   func_02177848  0x02177848  arm  ov009
 *   func_021861A8  0x021861A8  arm  ov009
 *   DWC_Base64Encode  0x02059B40  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_0219EF08  0x0219EF08  arm  ov009
 *   d_021A2190  0x021A2190  data
 *   d_021A2198  0x021A2198  data
 *   d_021A21A0  0x021A21A0  data
 *   func_021864CC  0x021864CC  arm  ov009
 *   DWC_CloseAllConnectionsHard                  0x0216b65c arm ov009
 *   DWCi_CheckResvCommand                        0x021713cc arm ov009
 *   DWCi_CloseAllConnectionsByTimeout            0x02172e7c arm ov009
 *   DWCi_GetFriendListIndex                      0x02169038 arm ov009
 *   DWCi_GetGT2NumConnection                     0x02176978 arm ov009
 *   DWCi_GetResvDenyReasonString                 0x021769e0 arm ov009
 *   DWCi_HandleNNError                           0x02173ef8 arm ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID    0x021763ac arm ov009
 *   DWCi_NodeInfoList_GetServerNodeInfo          0x02176358 arm ov009
 *   DWCi_ProcessMatchPollingPacket               0x0216f058 arm ov009
 *   DWCi_ProcessRequestMatch                     0x021758c4 arm ov009
 *   DWCi_ProcessResvOK                           0x02171884 arm ov009
 *   DWCi_TempNewNodeInfo_IsValid                 0x02176554 arm ov009
 *   gpIsBuddy                                    0x021861a8 arm ov009
 *   gt2CloseAllConnectionsHard                   0x02195de4 arm ov009
 *   func_02171524                0x02171524 arm   ov009
 *   DWCi_IsServerLocked              0x021767f4 arm
 *   DWCi_IsFriendByIdxList           0x02173b74 arm
 *   DWCi_GetNumEntry                 0x02175760 arm
 *   DWC_GetSuspendMatch              0x0216cb90 arm
 *   _s32_div_f                       0x0209C0A4 arm
 *   DWCi_GetUserData                 0x0216A39C arm
 *   DWC_GetGsProfileId               0x020598EC arm
 *   DWCi_Acc_IsValidFriendData       0x020596F0 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   gpGetBuddyStatus                 0x02185FD4 arm
 *   DWCi_IsLockedBuddyStatus         0x02176984 arm
 *   func_02171C08                0x02171C08 arm   ov009
 *   DWCi_CancelPreConnectedServerProcessWithResetLevel 0x02171FD4 arm
 *   DWCi_PostProcessSVConnectionFullmesh  0x0217273C  arm
 *   DWCi_PostProcessSVConnectionHybrid    0x02172604  arm
 *   DWCi_NodeInfo_IsValid                 0x02176580  arm
 *   DWCi_NodeInfo_Clear                   0x0217656C  arm
 *   DWCi_GPSetServerStatus                0x0216F20C  arm
 *   DWCi_HandleGPError                    0x02173D28  arm
 *   ServerBrowserClear                    0x0219F00C  arm
 *   DWCi_PostProcessConnectionSYNFinishFullmesh 0x021725EC arm
 *   DWCi_NodeInfoList_Append             0x021760FC arm
 *   DWCi_NodeInfoList_GetNodeInfoForAID  0x02176410 arm
 *   func_0217253C  0x0217253C  arm  ov009
 *   func_02173064                0x02173064 arm   ov009
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   DWCi_FinishCancelMatch        0x02172A58  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   gt2CloseAllConnections  0x02195DE4  arm  ov009
 *   DWCi_SendReliable                0x02176EB0 arm
 *   DWCi_ServerSynTimeoutExec        0x0217352C arm
 *   func_021720D8  0x021720D8  arm  ov009
 *   DWCi_SendCancelMatchSynCommand   0x02173614 arm
 *   DWCi_CloseShutdownClientSC       0x02172EAC arm
 *   d_021AAA40     0x021AAA40  data
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   g_021A21A4     0x021A21A4  data
 *   g_021A21B0     0x021A21B0  data
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   DWCi_SBPrintServerData                     0x0217478C arm ov009
 *   ServerBrowserCount                         0x0219F068 arm ov009
 *   ServerBrowserGetServer                     0x0219F058 arm ov009
 *   ServerBrowserRemoveServer                  0x0219EFA8 arm ov009
 *   SBServerGetPublicInetAddress               0x0219E1EC arm ov009
 *   SBServerGetPublicQueryPort                 0x0219E1F4 arm ov009
 *   SBServerGetPrivateInetAddress              0x0219E238 arm ov009
 *   SBServerGetPrivateQueryPort                0x0219E240 arm ov009
 *   SBServerHasPrivateAddress                  0x0219E220 arm ov009
 *   DWCi_StartMatch                            0x02175AA4 arm ov009
 *   DWCi_NodeInfoList_GetFreeAID               0x02176474 arm ov009
 *   DWCi_EvaluateServers                       0x02174790 arm ov009
 *   DWCi_RandomizeServers                      0x02174930 arm ov009
 *   SBServerGetIntValueA                       0x0219E120 arm ov009
 *   DWCi_ConnectToGameServerAsync_InterChange  0x02175698 arm ov009
 *   DWCi_CancelReservation                     0x02171F68 arm ov009
 *   DWCi_ConnectToGameServerAsync              0x0216D27C arm ov009
 *   @24369         0x021A2188  data
 *   func_0219F068  0x0219F068  arm  ov009
 *   func_0219EFA8  0x0219EFA8  arm  ov009
 *   func_0219E084  0x0219E084  arm  ov009
 *   func_0219F078  0x0219F078  arm  ov009
 *   g_021A19C0     0x021A19C0 data
 *   g_021A21BC     0x021A21BC data
 *   func_0219B628  0x0219B628 arm   ov009
 *   func_0219B660  0x0219B660 arm   ov009
 *   qr2_keybuffer_add  0x0219B5EC  arm  ov009
 *   func_0216FC34  0x0216FC34  arm  ov009
 *   DWCi_ProcessRecvMatchCommand    0x021702A0 arm
 *   MI_CpuCopy8                0x02082D44 arm
 *   func_020949F4                0x020949F4 arm
 *   g_021A2188                   0x021A2188 data
 *   DWCi_HandleNNResult              0x02173f54 arm
 *   DWCi_ProcessNNFailure            0x021753d8 arm
 *   DWC_GetNumConnectionHost 0x0216B804 arm
 *   func_02177748  0x02177748  arm  ov009
 *   func_021684CC  0x021684CC  arm
 *   sub_02095EAC   0x02095EAC  arm
 *   g_021A21C8     0x021A21C8  data
 *   g_021A21E8     0x021A21E8  data
 *   g_021A2208     0x021A2208  data
 *   g_021A222C     0x021A222C  data
 *   g_021A224C     0x021A224C  data
 *   g_021A2280     0x021A2280  data
 *   g_021A22C4     0x021A22C4  data
 *   g_021A22F0     0x021A22F0  data
 *   g_021A2324     0x021A2324  data
 *   g_021A2340     0x021A2340  data
 *   g_021A20D4     0x021A20D4  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_MatchAnchorA.h"
#include "../../matched/include/G_Magic6.h"
#include "dwc_match_ctl_types.h"

#define KEYID(i)  (g_021AAA40[i].keyID)
#define KEYF1(i)  (g_021AAA40[i].isStr)
#define KEYF2(i)  (g_021AAA40[i].pad)
#define KEYSTR(i) (g_021AAA40[i].keyString)
#define KEYVAL(i) (g_021AAA40[i].value)
#define TICK_MS(t) (((t) * 64) / 33514)
#define MCP ((char *)DWCi_GetMatchCnt())
#define NULL ((void *)0)
#define SOC_HtoNs(s) ((u16)((((s) >> 8) & 0x00ff) | (((s) << 8) & 0xff00)))
#define RETRY() do { MC()->sbUpdateFlag = 2; tick = OS_GetTick(); MC()->sbUpdateTick = tick; } while (0)
struct SOCSockAddrIn;
struct ServerBrowser;
struct DWCstBinaryMessage;
struct SBServer;
struct GT2Socket { void *pad; };

typedef enum { E0 = 0, E6 = 6 } EFld;

typedef enum { SBFalse, SBTrue } SBBool;

typedef enum { sbe_noError, sbe_socketError, sbe_dnsError, sbe_connectError, sbe_dataError, sbe_allocError, sbe_paramError, sbe_duplicateUpdateError } SBError;

static SBError DWCi_SBUpdateAsync(int profileID);
static void DWCi_DoCancelMatch(void);
static int DWCi_CloseShutdownClientSC(u32 bitmap);
static int DWCi_EvaluateServers(int sort);
static int DWCi_ProcessRequestMatch(u8 AID, int suspend, int immediate);

typedef struct {
    char id[5];
} MatchId;

typedef struct {
    MatchId id;
    unsigned char pad[3];
    unsigned char command;
    unsigned char len;
    unsigned short port;
    int ip;
    int pid;
    unsigned int data[32];
} MatchCtrl;

struct GPBuddyStatus
{
    int f0;
    int f4;
    u8 pad[0x214 - 8];
};

typedef struct GTI2Socket GTI2Socket;

enum E { E_OK, E_A, E_B, E_C, E_D, E_E, E_NET };

/* callees */
extern int DWCi_IsError(void);
extern int DWC_GetState(void);
extern int func_020948E0(const char *s1, const char *s2);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern int func_0209477C(const u8 *s);
extern void *func_0205A16C(int name, u32 size);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219D158(int keyid, char *key);
extern int func_02059F38(void);
extern int DWC_GetAIDBitmap(void);
extern unsigned char DWC_GetMyAID(void);
extern int func_0216F388(int flag);
extern int gt2GetSocketSOCKET(void *socket);
extern unsigned short gt2GetLocalPort(void *socket);
extern void func_0219B1AC(void *qrec, void *cb);
extern void func_0219B134(void *qrec, void *cb);
extern void func_0219B170(void *qrec, void *cb);
extern void func_02174D04();
extern void DWC_Free(int name, void *ptr, unsigned int size);
extern void *DWC_Alloc(int name, unsigned int size);
extern void func_02175F84(int a0);
extern int func_02175530(void);
extern int func_021719D0(int profileID, int delay);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned int size);
extern unsigned long long OS_GetTick(void);
extern void DWCi_StopMatch(int error, int errorCode);
extern int DWCi_RetryReserving(int resendPid);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_HandleSBError(int error);
int DWCi_CancelPreConnectedClientProcess(void);
extern void DWCi_StopResendingMatchCommand(void);
int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int DWCi_IsBackupMine(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void *DWCi_GetGT2Connection(unsigned char aid);
extern unsigned char DWCi_GetAIDFromProfileID(int profileID, int idxOnly);
extern int DWCi_IsServerChangeEnabled(void);
extern int DWCi_SendServerDownQuery(void);
extern void qr2_send_statechanged(void *qrec);
extern void DWCi_InitClWaitTimeout(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern void DWCi_SetupGameServer_InterChange(int init);
extern void DWCi_ResetLastSomeDataRecvTimeByAidAll(void);
extern void DWCi_AutoSuspendComplete(void);
extern int DWCi_GetTopologyType(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern u64 DWCi_GetNextMeshMakeTryTick(void);
extern int ServerBrowserThink(void *sb);
extern void ServerBrowserFree(void *sb);
extern int ServerBrowserState(void *sb);
extern void NNThink(void);
extern void NNFreeNegotiateList(void);
extern int DWCi_RequestSuspendMatchProcess(void);
extern int DWCi_SendServerPolling(int immediate);
extern void MIi_CpuClear32(unsigned int data, void *destp, unsigned int size);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void gt2Reject(void * connection, void * message, int code);
extern unsigned int strtoul(const char * s, char ** end, int base);
extern int DWCi_GT2GetConnectionListIdx(void);
extern int gt2Accept(void * connection, void * flag);
extern void ** DWCi_GetGT2ConnectionByIdx(int index);
extern struct DWCstConnectionInfo * DWCi_GetConnectionInfoByIdx(int index);
extern void DWCi_ResetLastSomeDataRecvTimeByAid(u8 aid);
extern void gt2SetConnectionData(void * connection, void * data);
extern int OS_SNPrintf(char *dst, unsigned int len, const char *fmt, ...);
extern char *gt2AddressToString(unsigned int ip, unsigned short port, char *string);
extern int gt2Connect(void *socket, void **connection, char *remoteAddress, unsigned char *message, int len, int timeout, void *callbacks, int blocking);
extern int DWCi_HandleGT2Error(int result);
extern int func_02059CBC(const char *src, int srclen, void *dst, int dstlen);
extern void DWCi_SetError(int error, int errorCode);
extern int func_02169038(int pid);
extern int DWCi_IsFullMesh(void);
extern void DWCi_ProcessMatchSynPacketSub_FullMesh(unsigned char aid, unsigned short type, unsigned char *data);
extern void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data);
extern unsigned int DWCi_GetMathRand32(unsigned int max);
extern void DWCi_SendTypeMatchAck(void);
extern void func_0219B490(void *qrec);
extern void *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, void *callback, void *instance);
extern void qr2_think(qr2_implementation_s *qr2Obj);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned int size);
extern struct SBServer *func_0219F058(struct SBServer *sb, int index);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern void qr2_shutdown(qr2_implementation_s *qrec);
extern void qr2_parse_queryA(qr2_implementation_s *qr2, unsigned char *message, int len, SOCSockAddrIn *saddr);
extern void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
extern int DWCi_NodeInfoList_InsertToTop(DWCstNodeInfo *newNode);
extern void gt2Think(void *socket);
extern int qr2_init_socketA(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key, int ispublic, int natnegotiate, void *server_key_callback, void *player_key_callback, void *team_key_callback, void *key_list_callback, void *playerteam_count_callback, void *adderror_callback, void *userdata);
extern int DWC_IsServerMyself(void);
extern void NNCancel(int cookie);
extern void func_02195DE4(int *p);
extern unsigned long long func_020870D0(void);
extern void func_02172BB8(int level);
extern int func_02168454(const char *key, const char *value, char *string, char sep);
extern int func_0216848C(const char *key, const char *value, char *string, char sep);
extern int func_021690D0(int status, const char *statusString, const char *locString);
void DWCi_SetMatchCnt(DWCstMatchControl *a);
extern void DWCi_ClearGameMatchKeys(void);
extern int DWCi_GetHostStatus(void);
extern void DWCi_NodeInfoList_Clear(void);
extern void func_0219ED4C(struct ServerBrowser *sb);
extern void func_02176B34(void);
extern u32 func_021685CC(u32 max);
extern void func_0219F00C(void *p);
extern int func_0219EED4(struct ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
extern u32 ServerBrowserGetMyPublicIPAddr(void * sb);
extern long SOC_GetHostID(void);
extern int IsPrivateAddr(u32 addr);
int DWCi_DoNatNegotiationAsync(DWCstNNInfo *nnInfo);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_0219EF60(struct ServerBrowser *sb, char *ip, unsigned short port, int cookie);
extern int func_02199DFC(int sock, int cookie, int clientindex, void *progress, void *completed, void *userdata);
extern void func_02174FE8(void);
extern int func_02177848(unsigned char from, unsigned char to, const void *data, int size, int flag);
extern int func_021861A8(void *conn, int pid);
extern int DWC_Base64Encode(const void *src, int srclen, char *dst, int dstlen);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
extern int func_0219EF08(struct ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
extern int func_021864CC(void **connection, int profile, char *message);
extern u8 DWCi_CheckResvCommand(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType,
                                int connectGroupID, u32 topologyType,
                                u8 *newClientUserData, int meshReserve);
int DWCi_ProcessResvOK(int profileID);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_GetFriendListIndex(int profileID);
extern char *DWCi_GetResvDenyReasonString(u8 denyReason);
extern int DWCi_HandleNNError(int error);
extern int gpIsBuddy(void *connection, int profile);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern void *DWCi_GetGT2ConnectionByProfileID(int profileID, int idx);
extern void gt2CloseAllConnectionsHard(void *socket);
extern int DWCi_GetGT2NumConnection(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern void DWCi_CloseAllConnectionsByTimeout(void);
extern int DWC_CloseAllConnectionsHard(void);
extern u8 func_02171524(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);
extern int DWCi_IsServerLocked(void);
extern int DWCi_IsFriendByIdxList(int profileID);
extern int DWCi_GetNumEntry(void);
extern int DWC_GetSuspendMatch(void);
extern void * DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(void * userdata, void * frienddata);
extern int DWCi_Acc_IsValidFriendData(void * frienddata);
extern int gpGetBuddyIndex(void * connection, int profile, int * index);
extern int gpGetBuddyStatus(void * connection, int index, struct GPBuddyStatus * status);
unsigned char DWCi_IsLockedBuddyStatus(char *a0);
extern void _s32_div_f(void);
extern int func_02171C08(int delay, int init, int resendPid);
extern int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel);
int DWCi_PostProcessSVConnectionFullmesh(void);
int DWCi_PostProcessSVConnectionHybrid(void);
int DWCi_NodeInfo_IsValid(const DWCstNodeInfo *p);
extern void DWCi_NodeInfo_Clear(DWCstNodeInfo *node);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWCi_HandleGPError(int result);
extern void ServerBrowserClear(void *sb);
extern void DWCi_PostProcessConnectionSYNFinishFullmesh(void);
extern int DWCi_NodeInfoList_Append(DWCstNodeInfo *newNode);
extern DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void func_0217253C(void);
extern void func_02173064(u8 aid, u16 type);
extern void func_02199FB4(int cookie);
extern void DWCi_FinishCancelMatch(void);
extern void func_02195DC4(int a);
extern void gt2CloseAllConnections(int conn);
extern int DWCi_SendReliable(u16 type, u8 aid, void * buffer, int size);
int DWCi_ServerSynTimeoutExec(void);
extern int func_021720D8(int id);
extern int DWCi_SendCancelMatchSynCommand(int profileID, u8 command);
extern int func_02168FF0(int idx);
extern void func_0216A3B8(int dwcError, int errorCode);
extern void DWCi_SBPrintServerData(void *server);
extern int ServerBrowserCount(void *sb);
extern void *ServerBrowserGetServer(void *sb, int index);
extern void ServerBrowserRemoveServer(void *sb, void *server);
extern u32 SBServerGetPublicInetAddress(void *server);
extern unsigned short SBServerGetPublicQueryPort(void *server);
extern u32 SBServerGetPrivateInetAddress(void *server);
extern unsigned short SBServerGetPrivateQueryPort(void *server);
extern int SBServerHasPrivateAddress(void *server);
extern int DWCi_StartMatch(void);
extern unsigned char DWCi_NodeInfoList_GetFreeAID(void);
extern void DWCi_RandomizeServers(void);
extern int SBServerGetIntValueA(void *server, char *key, int idefault);
void DWCi_ConnectToGameServerAsync_InterChange(void);
extern int DWCi_CancelReservation(int pid);
extern void DWCi_ConnectToGameServerAsync(int topology, int serverPid,
    void *a, void *b, void *c, void *d, void *e, void *f, void *g);
extern int func_0219F068(void *sb);
extern void func_0219EFA8(struct ServerBrowser *sb, struct SBServer *server);
extern void func_0219E084(void *server, char *keyname, int value);
extern void func_0219F078(struct ServerBrowser *sb, int ascending, char *sortkey, int comparemode);
extern int func_0219B628(void *outbuf, int value);
extern int func_0219B660(void *outbuf, char *value);
extern int qr2_keybuffer_add(char *p, int v);
extern int func_0216FC34(int type, int cookie, void *param);
extern int DWCi_ProcessRecvMatchCommand(unsigned char command, int srcPid,
    unsigned int srcIP, unsigned short srcPort, unsigned int *data, int len);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern int DWCi_HandleNNResult(int result);
extern int DWCi_ProcessNNFailure(int ignoreError);
extern void DWC_GetNumConnectionHost(void);
extern void func_02177748(int aid);
extern int func_021684CC(char *key, char *value, char *string, char separator);
extern u32 sub_02095EAC(u32 a0, u32 *a1, u32 mode);
int DWC_CancelMatch(void);
int DWC_IsValidCancelMatch(void);
u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc);
u8 DWC_AddMatchKeyString(u8 keyID, char *keyString, char *valueSrc);
int DWC_GetMatchIntValue(int index, char *key, int idefault);
int DWCi_MatchInit(DWCstMatchControl *matchCnt, void **pGpObj, void **pGt2Socket, void *gt2Callbacks, char *gameName, char *secretKey, int friendKeyListArg, int friendKeyListLenArg);
int DWCi_QR2Startup(int profileID);
void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
void DWCi_SetupGameServer(int topology, u8 numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void func_0216D27C(int topology, int serverPid, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void DWCi_SendStateChanged(struct qr2_implementation_s *qr2Obj);
void DWCi_MatchProcess(int fullSpec);
int DWCi_GT2UnrecognizedMessageCallback(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
void DWCi_GT2ConnectAttemptCallback(void * userdata, void * connection, unsigned int ip, unsigned short port, int latency, unsigned char * message, int len);
void DWCi_MakeGT2ConnectString(char *buf, int bufLen);
void DWCi_GT2ConnectedCallback(void * connection, int result);
extern void func_0216EAB8(int unused, int profileID, char *message);
void DWCi_ClearQR2Key(void);
void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
void DWCi_ProcessMatchSynPacketSub(unsigned char aid, unsigned short type, unsigned char *data);
void DWCi_CheckDeadAIDBitmap(unsigned int bitmap);
void DWCi_ProcessMatchPollingPacket(const Poll *p);
int DWCi_ProcessMatchClosing(int error, int errorCode);
void DWCi_ProcessMatchSCClosing(int clientPid);
void DWCi_ShutdownMatch(void);
int DWCi_IsShutdownMatch(void);
void DWCi_ResetMatchParam(int level);
void DWCi_SetMatchCommonParam(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
void DWCi_CloseMatch(void);
int DWCi_GetDefaultMatchFilter(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
int DWCi_NNStartupAsync(int isQR2, int cookie, DWCstNodeInfo * node);
int DWCi_CanSendMatchCommandDirect(unsigned char command, int pid);
void DWCi_EncodeBinaryMsgCommand(DWCstBinaryMessage *message, unsigned char command, unsigned int *data, int len);
int DWCi_SendSBMsgCommand(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len);
int DWCi_SendGPBuddyMsgCommand(void *conn, unsigned char command, int pid, const char *data);
unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, unsigned char *newClientUserData, int meshReserve);
int DWCi_SendResvCommand(int profileID, int delay);
int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
int DWCi_CancelPreConnectedServerProcess(int clientPid);
void DWCi_PostProcessConnection(int type);
void DWCi_PostProcessConnectionSYNFinish(void);
void DWCi_PostProcessConnectionSYNFinishHybrid(void);
int DWCi_InvalidateReservation(void);
void DWCi_RestartFromCancel(int level);
void DWCi_RestartFromTimeout(void);
int DWCi_ResumeMatch(void);
int DWCi_CloseCancelHostAsync(int profileID);
void DWCi_SendMatchSynPacket(u8 aid, u16 type);
int DWCi_ProcessMatchSynTimeout(void);
int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data);
int DWCi_ProcessCancelMatchSynTimeout(void);
u8 DWCi_GetNewMatchKey(void);
int DWCi_CheckDWCServer(void *server);
unsigned int DWCi_GetAIDBitmask(int valid);
int func_02173D28(int error);
int DWCi_HandleQR2Error(int error);
int func_02173FB4(int result);
void DWCi_SBCallback(void *sb, int reason, void *server);
void DWCi_DebugPrintServerList(void);
void DWCi_QR2ServerKeyCallback(int keyid, void *outbuf);
void DWCi_QR2PlayerKeyCallback(void);
void DWCi_QR2TeamKeyCallback(void);
void DWCi_QR2KeyListCallback(int keytype, void *keybuffer);
int DWCi_QR2CountCallback(void);
int DWCi_QR2AddErrorCallback(int error);
void DWCi_QR2PublicAddrCallback(unsigned int ip, unsigned short port);
void DWCi_QR2NatnegCallback(int cookie);
void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
void DWCi_QR2ClientMsgCallback(char *data, int len);
void DWCi_NNProgressCallback(void);
void DWCi_NNCompletedCallback(int result, int unused, struct SOCSockAddrIn *remoteaddr, struct DWCstNNInfo *nnInfo);
unsigned int DWCi_CreateGroupID(void);
void DWCi_SetConnectionAttemptParam(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
void DWCi_GetNumConnectionHost(void);
void DWCi_RequestSuspendMatchInit(int suspend, void (*callback)(int, int, void *), void *suspendResultParam);
int DWCi_IsServerSuspendEnabled(void);
int DWCi_IsServerChanging(void);
DWCstMatchControl *DWCi_GetMatchCnt(void);
void DWCi_SetHostStatus(int host);
unsigned char func_02175FB8(void);
int DWCi_NodeInfoList_RemoveAID(unsigned char aid);
int DWCi_NodeInfoList_RemoveProfileID(int profileID);
int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
int DWCi_IsFirstServer(void);
void DWCi_ClearMeshMakingTempInfo(void);
void DWCi_SuspendComplete(int result);
int DWCi_GetNodeInfoCount(void);
void disp_match_state(int a, int b);
void DWCi_SetMatchmakeProfileId(int v);
void DWCi_RegisterMatchmakeKeys(void);
void DWCi_NNFreeNegotiateList(void);
extern DWCstGameMatchKeyData g_021AAA40[154];
extern struct NNThinkGlobal g_021AAA20;
extern struct MatchAnchorA s_anybodyServerSearchRatio;
extern struct Magic6 g_021A5A7C;
extern char g_021A2044[];
extern char g_021A204C[];
extern char g_021A2058[];
extern char g_021A2064[];
extern char g_021A207C[];
extern char d_021A207C[];
extern char d_021A2080[];
extern char d_021A2084[];
extern char d_021A2088[];
extern char d_021A208C[];
extern struct NNThinkGlobal s_bInNNThink;
extern DWCstGameMatchKeyData stGameMatchKeys[154];
extern char d_021A2090[];
extern char d_021A209C[];
extern char d_021A20A4[];
extern char d_021A20AC[];
extern char d_021A20D4[];
extern char d_021A20E0[];
extern char g_021A20E0[];
extern char g_021A20F0[];
extern char g_021A209C[];
extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A217C[];
extern char g_021A2108[];
extern char g_021A2164[];
extern char d_021A2190[];
extern char d_021A2198[];
extern char d_021A21A0[];
extern u8 d_021AAA40[];
extern char g_021A21A4[];
extern char g_021A21B0[];
extern int g_021A19C0[6];
extern char g_021A21BC[];
extern char g_021A2188[];
extern char g_021A21C8[];
extern char g_021A21E8[];
extern char g_021A2208[];
extern char g_021A222C[];
extern char g_021A224C[];
extern char g_021A2280[];
extern char g_021A22C4[];
extern char g_021A22F0[];
extern char g_021A2324[];
extern char g_021A2340[];
extern char g_021A20D4[];

#define MC() DWCi_GetMatchCnt()


int DWC_CancelMatch(void)
{
    int bRet;

    if (DWC_IsValidCancelMatch()) {
        DWCi_DoCancelMatch();
        bRet = 1;
    } else {
        DWCi_GetMatchCnt();
        bRet = 0;
    }
    DWCi_GetMatchCnt()->cancelFromConnection = 0;
    return bRet;
}


int DWC_IsValidCancelMatch(void)
{
    if (DWCi_IsError())
        return 0;
    if (DWCi_GetMatchCnt() == 0 ||
        DWC_GetState() != 4 ||
        DWCi_GetMatchCnt()->cancelState != 0)
        return 0;
    return 1;
}


/*
 * DWC_AddMatchKeyInt (dwc_match.o): resolve/create the match-key slot at
 * 0x021AAA40 (12-byte stride: f0 key id, f1 flag, f2 u16, f4 string ptr,
 * f8 int), free the old string, strdup the new one and record the int.
 *
 * BLOCKER (codegen only, size correct at 296): the whole body is logically
 * right but mwcc allocates the three parameters differently -- original
 * keeps a0=r7, a1=r6, a2=r5 with the index in r4 and rematerialises a zero
 * into r2; this front end hoists a zero into r4 and maps a0=r8, a1=r7,
 * a2=r6 with the index in r5.  Every branch target and constant is right;
 * only the register file assignment differs.  Not a witness problem.
 *
 * lane W7 (2026-09-30): applied the unsigned guard the U22 note identified
 * (`(unsigned)a0 >= 0x64u`); the image's first key test is now the image word
 * (`blo`), but the +1 register roll from the hoisted zero is unchanged: still
 * 296/296 with 134 concrete bytes differing and 13/13 relocations resolved.
 * Measured and rejected this wave: computed-zero spellings (a2^a2, a2&0),
 * a separate `key` local, an i-through-pointer local, f4 through a char*,
 * and a global const zero (304 B / 158).  The hoisted `mov r4,#0` (global-CSE
 * of the shared f1/f2 zero into a callee-saved register) remains the sole
 * blocker and is a 1.1p1 allocator behaviour.  Note for the human: the twin
 * 0x0216CA04 lane (T5/U10) pinned this DWC object family to ../2.0/base, where
 * the image allocates index->r4 with no hoisted zero; this lane is bound to
 * dsi/1.1p1 per the wave brief, so the row stays DIFF here.
 *
 * lane U22 (2026-09-30): one CONCRETE byte is wrong in the draft, not just
 * registers.  The image's first key test is +0020 `cmp r7,#0x64; blo` --
 * cond 0x3 (unsigned LO, word 0F 00 00 3A) -- while the parked `a0 >= 0x64`
 * on a signed int emits cond 0xB (`blt`, word 0F 00 00 BA).  Spelling the
 * guard `(unsigned)a0 >= 0x64u` produces the image's word, so the original
 * keys off an unsigned comparison.  The rest is the +1 register roll: ours
 * materialises a shared zero into the callee-saved r4 at +0014 (the image
 * rematerialises `mov r2,#0` at the stores) and that live zero pushes
 * keyID->r8, keyString->r7, valueSrc->r6 with index->r5, against the image's
 * r7/r6/r5 with index->r4.  Measured and not moving the roll: u8 return and
 * u8 params, int* valueSrc, inline indexing (`g[a0-0x64]`), unsigned index,
 * `(u8)0`/`(u16)0` typed zero stores, swap of the two zero stores, zero
 * stores before the f0 store, decl order.  The hoisted zero is the only
 * thing standing between the draft and EXACT on this row and its twin
 * 0x0216CA04.
 *
 * lane W8 (2026-09-30): re-confirmed under dsi/1.1p1.  This is exactly the
 * documented front-end wall of docs/idioms/a-repeated-small-constant-takes-a-
 * callee-saved-register.md: the shared `0` (the `return 0` at +005C and the
 * f1/f2 stores) is pooled into callee-saved r4 at +0014, crossing two calls,
 * which steals the first callee-saved slot and shifts every register +1.  The
 * idiom's own correction says the only known lever is a 2.0 pin.  Measured
 * this wave and no effect on the roll: an enum-typed zero for the stores
 * (docs/idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-
 * folded.md), assigned both immediately before the stores and first at entry.
 * Cross-check (informational, lead from the twin): under ../2.0/base the whole
 * allocation matches the image (index->r4, no pooled zero) but the size is 300
 * vs 296 -- the twin's one-redundant-copy tail residue (49 concrete) -- so no
 * in-tree compiler reaches EXACT and the row is parked for the object's front
 * end, not a source shape.
 *
 * lane W8b (2026-10-01): re-verified under dsi/1.1p1: identical 296/296, 134
 * concrete, 13/13 relocs.  Re-read the zero idioms; all the named-local zero
 * idioms (a-zero-stored-passed-and-returned-is-a-named-local,
 * a-returned-zero-keeps-r0-out-of-the-rotation,
 * a-repeated-constant-pools-only-within-one-block...) move the benchmark in
 * the opposite direction -- they force a pooled named zero -- and none
 * suppresses 1.1p1's callee-saved hoist.  The image rematerialises `mov r2,#0`
 * (stores) and `mov r0,#0` (returns); 1.1p1 alone pools them into r4.  Wall
 * unchanged.
 *
 * lane W8c (2026-10-01): re-verified under dsi/1.1p1, 296/296, 134 concrete,
 * 13/13 relocs.  Measured this wave and still no effect on the +1 roll: a
 * chained store `f1 = f2 = 0` (300 B / 239 concrete -- worse) and a
 * `do { f0/f1/f2 stores } while (0)` block fence (296 B / 134 -- unchanged).
 * The shared zero at +0014 is 1.1p1 global-CSE across the func_020948E0 call
 * into callee-saved r4; the image rematerialises `mov r2,#0` at the stores and
 * `mov r0,#0` per return.  Confirmed wall.
 *
 * 2026-10-01 (lane02): 134 -> 132 B. Body retyped from DWARF (u8 keyID and
 *   return, int *valueSrc, strcmp(keyString-field, keyString) and
 *   DWC_Free(4, ptr) with their real second arguments). The pooled zero is
 *   still the whole residue. Measured: dropping one zero store still pools,
 *   dropping both stops it (the returns alone never pool); int return and
 *   split NULL guards do not help.
 *
 * 2026-10-01 (w3 lane17): 132 B, unchanged. Mechanism measured: 1.1p1 hoists
 *   the zero to entry when 5 blocks use it (null, strcmp, get-fail and
 *   alloc-fail returns plus the stores) and at least one use is not a return
 *   value; changing any one of the four returns to a non-zero closes every register
 *   (1 B left, the constant), so the residue is exactly this count. The vendor
 *   .debug_line (dwc_match.o) puts one statement per line exactly as this
 *   body (573 guard+return, 579 strcmp test, 583 return, 590/591 get-fail,
 *   595-598 stores, 609 return), so no zero is missing from the source.
 *   Flat: stGameMatchKeys as the object's file static (it is LOCAL in its own
 *   .bss), house string.h with strcmp, enum-typed callee params, static
 *   GetNewMatchKey, || then/else swap, merged get-fail test after the join,
 *   int index from the call, empty DWC_Printf, 12 opt pragmas, all dsi pins.
 *   A goto to one shared `return 0` or an enum local returned at alloc-fail
 *   removes the hoist but changes other bytes. Twin 0216CA04 has the same count.
 *
 * 2026-10-01 (w4): 132 B, unchanged. The hoist is a pure block count, not
 *   very-busy/PRE: with get-fail returning keyID (no zero on that path) plus
 *   one extra zero block elsewhere it still hoists; the zero need not be in
 *   entry (null guard returning 1 + 5 other blocks hoists); extra non-zero
 *   blocks or removing any call do not change it. No late fold exists on 1.1p1:
 *   `return keyID` / `(keyID = f()) == 0` / `keyID >> 8` / `(u8)NULL` /
 *   `keyID > 0xff` either fold early (still hoist) or leave popeq/real ops
 *   (`return keyID` = everything EXACT except the image's moveq r0,#0, 4 B).
 *   const params, optimizer pragmas (common_subs, propagation, lifetimes,
 *   loop_invariants, dead_*, peephole, scheduling, levels) do not close it.
 *   Vendor .debug_line confirms five literal zero sites (573, 583, 591,
 *   597/598, 609), so 1.1p1 needs four; residue is a front-end count rule.
 */
u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && g_021AAA40[keyID - 0x64].keyID != 0) {
        if (g_021AAA40[keyID - 0x64].keyString != 0 && func_020948E0(g_021AAA40[keyID - 0x64].keyString, keyString) != 0)
            return 0;
    } else {
        keyID = DWCi_GetNewMatchKey();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    g_021AAA40[index].keyID = keyID;
    g_021AAA40[index].isStr = 0;
    g_021AAA40[index].pad = 0;
    if (g_021AAA40[index].keyString != 0)
        func_0205A1B0(4, g_021AAA40[index].keyString, 0);
    g_021AAA40[index].keyString = func_0205A16C(4, func_0209477C((const u8 *)keyString) + 1);
    if (g_021AAA40[index].keyString == 0) {
        DWCi_StopMatch(9, -80001);
        return 0;
    }
    func_02094798(g_021AAA40[index].keyString, keyString);
    g_021AAA40[index].value = valueSrc;
    func_0219D158(keyID, g_021AAA40[index].keyString);
    return keyID;
}


/*
 * sdk:      DWC_AddMatchKeyString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * notes:    closed by DWC_Free's hidden third argument (size 0), see the w4 note.
 *
 * lane T5 (2026-09-30).  PIN LEVER: the DWC object was built with a 2.0-tree
 * compiler, not dsi/1.1p1.  Under `--cc 2.0/base` (also 2.0/sp1, 2.0/sp1p2) the
 * whole register allocation matches the image from +0004 to +0x2C
 * (movs r6,r1 / mov r5,r2 / mov r7,r0 / cmp r7,#0x64 / sub r2,r7,#0x64 /
 * mul r3,r2,r0) and the residue drops from 133 to 42 concrete bytes; every dsi
 * compiler and every flag set tried gives 133.  Residue under 2.0/base is a
 * single redundant instruction in the tail argument set-up, 304 vs 300 bytes:
 *   +00FC  image `mov r0, r7` then `ldr r1, [r8, r4]`  | ours `mov r0, r8`
 *          then `ldr r1, [r0, r4]` then `mov r0, r7`   (one extra register copy,
 *          and the 12-word pool shifts +4 from +0114 on).
 * Measured flat under 2.0/base: explicit struct-member spelling of the tail two
 * statements, an element-pointer local (&g_021AAA40[index]) in three positions,
 * the call before the value store, a keyString local, and an all-element-pointer
 * body (8 spellings) - 42, 42, 50, 55, 103, 131, 140, 147 bytes.
 *
 * lane U10 (2026-09-30).  Pin confirmed and made the header's compiler field:
 * ../2.0/base.  All ten tools/mwccarm/mwccarm/2.0 subdirectories (base, sp1,
 * sp1p2, sp1p5, sp1p6, sp1p7, sp2, sp2p2, sp2p3, sp2p4) compile this source
 * byte-identically, 304 B / 42 concrete diffs against the image's 300; every
 * one of the nine dsi front ends gives 300 B / 133.  So the register
 * allocation from +0004 to +0x2C is the 2.0 tree's and the row is 2.0-pinned
 * on its own bytes; the object's stamp (4.0.0.1025) has no build in the tree.
 * RESIDUE (not closed, 4 bytes, 42 concrete diffs): every one of those 42 is
 * a pool displacement that moved with the extra instruction.  The body is the
 * image's instruction for instruction except one redundant copy at +00FC:
 *   image  +00FC `mov r0, r7`   +0104 `ldr r1, [r8, r4]`
 *   ours   +00FC `mov r0, r8`   +0104 `ldr r1, [r0, r4]`   +0108 `mov r0, r7`
 * i.e. this front end hoists a copy of the keyString base into r0 and folds
 * the load onto it, where the image hoists the keyID copy and loads straight
 * off r8.  19 spellings this lane, all 304/42: the call spelled with
 * g_021AAA40[index].keyString; a char *ks local assigned after the store; a
 * char *ks = KEYSTR(index) hoisted above the store; an element-pointer local
 * for the store and one for both the store and the call; a char *v temp for
 * valueSrc; a char **pv pointer for the value store; (volatile char **) on the
 * value store; two nested blocks; (char *) casts on both the store and the
 * load; a u8 k = keyID local; KEYSTR(keyID - 0x64) instead of KEYSTR(index);
 * the call before the store; the comma operator; (char *)valueSrc.  The role
 * of the last statement's load argument is exact: replacing it with a
 * non-load (w8/w9) yields 300 B / 7 diffs, i.e. the whole 4-byte gap is that
 * one hoisted copy.  DWC_AddMatchKeyInt (0x0216C8DC, same object, same tail
 * shape) moves 296/134 -> 300/50 under the same pin and parks on the same
 * class of residue, so this is the object's front end, not this body.
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov009_func_0216CA04.c \
 *       --func DWC_AddMatchKeyString --addr 0x0216CA04 --region ov009 --arm \
 *       --lang c99 --cc ../2.0/base
 *
 * lane W8 (2026-09-30).  Re-confirmed both pins on the current source, no
 * spelling changes.  Under the wave brief's dsi/1.1p1 it stays 300 B / 133
 * concrete diffs and the whole gap is the allocator's global-CSE of the
 * shared zero into a callee-saved register (mov r4,#0 at +0014, reused by the
 * +005C return and the +00A0 strh), which rolls keyID/keyString/valueSrc/index
 * up one register.  That is the documented front-end wall
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md
 * (the twin 0x0216C8DC parks on the same wall).  Under ../2.0/base the
 * allocation is the image's from +0004 to +0x2C and the lone residue is the
 * tail base copy at +00FC, unchanged from the T5/U10 notes; ../2.0/sp2
 * measures the same 304 B / 42.  Parked: the C is right, both front ends put
 * one extra/scheduling instruction in the tail that no source lever reaches.
 *
 * lane W8 #2 (2026-10-01).  Re-verified on the current source under both pins:
 * dsi/1.1p1 -> 300 B / 133 concrete (the shared-zero hoist, idiom
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md);
 * ../2.0/base -> 304 B / 42 concrete, every one a pool displacement from the
 * single +00FC `mov r0,r8`.  The +00FC copy is our front end materialising the
 * g_021AAA40 base in r0 to address the call's keyString load (`ldr r1,[r0,r4]`)
 * and then moving keyID into r0, where the image addresses straight off r8.
 * Filed as docs/idioms/a-front-end-hoists-a-base-copy-to-fold-an-argument-load.md.
 * No new source lever; parked unchanged.
 *
 * lane03 (2026-10-01): the dsi/1.1p1 shared-zero hoist is a USE COUNT: the body
 * has five literal zeros (four `return 0` and the KEYF2 strh). Replacing any
 * one of the five with a non-zero literal drops the hoist and leaves 1 B (the
 * altered literal itself), so the 1.1p1 body is right and needs one fewer
 * zero literal. Measured inert: `return keyID` on the new-key path (173 B, the
 * image has `moveq r0,#0`), a shared `fail:` label for any one return (296 B,
 * 1.1p1 does not duplicate the return block), enum-typed/(E) zero on the strh.
 *
 * w3 lane16 (2026-10-01): 1.1p1 is the object's compiler (six dwc_match.o
 * siblings EXACT on 1.1p1, five of them DIFF on ../2.0/base). The 1.1p1 hoist
 * counts BLOCKS holding a zero, not uses: 5 blocks hoist, 4 do not (6 uses in
 * 4 blocks: no hoist; a second zero in an existing block: still hoists).
 * Compare zeros do not count. Inert: house string.h strlen/strcpy (+strcmp),
 * void *value field, casts/enum/static const/inline/local for each zero site,
 * (u16)/0L/(char)/!1/keyID-keyID (all fold early), braces, nesting, else-if,
 * ternary condition, test after the if/else. goto-sharing two returns drops
 * the hoist (strcmp-fail -> new-key return: 300 B / 21 B, layout only) but
 * 1.1p1 never predicates or duplicates a shared return, so the image's five
 * private zero sites need a fifth zero that is not a literal at pool time.
 *
 * w4 (2026-10-01): EXACT on dsi/1.1p1 (the ../2.0/base pin was wrong). Closed
 * by a hidden call argument: DWC_Free takes a third `u32 size` (as in the
 * matched arm9 callers, e.g. func_0205A200) and the call passes 0. That zero
 * argument shares r2 with the KEYF2 strh zero, which stops 1.1p1 from hoisting
 * a shared zero into r4 (toy test: any zero use reachable from the strh in a
 * scratch register breaks the hoist). The image leaves r2 = 0 live into the call.
 */
u8 DWC_AddMatchKeyString(u8 keyID, char *keyString, char *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && KEYID(keyID - 0x64) != 0) {
        if (KEYSTR(keyID - 0x64) != 0 && func_020948E0(KEYSTR(keyID - 0x64), keyString) != 0)
            return 0;
    } else {
        keyID = DWCi_GetNewMatchKey();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    KEYID(index) = keyID;
    KEYF1(index) = 1;
    KEYF2(index) = 0;
    if (KEYSTR(index) != 0)
        func_0205A1B0(4, KEYSTR(index), 0);
    KEYSTR(index) = func_0205A16C(4, func_0209477C((const u8 *)keyString) + 1);
    if (KEYSTR(index) == 0) {
        DWCi_StopMatch(9, -80001);
        return 0;
    }
    func_02094798(KEYSTR(index), keyString);
    KEYVAL(index) = valueSrc;
    func_0219D158(keyID, KEYSTR(index));
    return keyID;
}


/*
 * sdk:      DWC_GetMatchIntValue (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int DWC_GetMatchIntValue(int index, char *key, int idefault)
{
    struct SBServer *server;

    if (DWCi_GetMatchCnt() == 0 || func_02059F38() != 0) {
        return idefault;
    }
    server = func_0219F058(DWCi_GetMatchCnt()->sbObj, index);
    if (server != 0) {
        idefault = func_0219E120(server, key, idefault);
    }
    return idefault;
}


/*
 * sdk:      DWC_GetSuspendMatch (dwc_match.o)
 */
int DWC_GetSuspendMatch(void)
{
    int bNew = -1;
    unsigned int bitmap;

    if (!DWCi_GetMatchCnt())
        return 0;
    if (!func_02175FB8())
        return 0;
    bitmap = DWCi_GetMatchCnt()->suspendBitmap;
    bitmap &= DWC_GetAIDBitmap();
    if (!DWCi_IsServerSuspendEnabled())
        bitmap &= ~(1 << DWC_GetMyAID());
    if ((bitmap ^ DWC_GetAIDBitmap()) == 0)
        bNew = 1;
    else if ((bitmap & DWC_GetAIDBitmap()) == 0)
        bNew = 0;
    if (bNew != -1)
        DWCi_GetMatchCnt()->suspendMatch = bNew == 1;
    return DWCi_GetMatchCnt()->suspendMatch;
}


/*
 * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by
 * DWCi_GetMatchCnt(), every field through a fresh getter call.  The +0x5f0/+0x5f4
 * pair is the one place a local reuses one getter result.
 */
int DWCi_MatchInit(DWCstMatchControl *matchCnt, void **pGpObj, void **pGt2Socket, void *gt2Callbacks, char *gameName, char *secretKey, int friendKeyListArg, int friendKeyListLenArg)
{
    DWCstMatchControl *q;

    DWCi_SetMatchCnt(matchCnt);
    DWCi_GetMatchCnt()->pGpObj = pGpObj;
    DWCi_GetMatchCnt()->pGt2Socket = pGt2Socket;
    DWCi_GetMatchCnt()->gt2Callbacks = gt2Callbacks;
    DWCi_GetMatchCnt()->qr2Obj = 0;
    DWCi_GetMatchCnt()->qr2IP = 0;
    DWCi_GetMatchCnt()->qr2Port = 0;
    DWCi_GetMatchCnt()->sbObj = 0;
    DWCi_SetMatchStatus(0);
    DWCi_GetMatchCnt()->qr2Flag19 = 0;
    DWCi_GetMatchCnt()->profileID = 0;
    DWCi_GetMatchCnt()->gameName = gameName;
    DWCi_GetMatchCnt()->secretKey = secretKey;
    DWCi_GetMatchCnt()->friendKeyList = (u8 *)friendKeyListArg;
    DWCi_GetMatchCnt()->friendKeyListLen = friendKeyListLenArg;
    MI_CpuFill8(DWCi_GetMatchCnt()->friendListIndex, 0, 0x40);
    DWCi_GetMatchCnt()->friendListIndexCount = 0;
    DWCi_GetMatchCnt()->matchedCallback = 0;
    DWCi_GetMatchCnt()->matchedParam = 0;
    DWCi_GetMatchCnt()->evalCallback = 0;
    DWCi_GetMatchCnt()->evalParam = 0;
    DWCi_GetMatchCnt()->serverDownBuff = 0;
    DWCi_GetMatchCnt()->serverDownBase = 0;
    DWCi_GetMatchCnt()->groupID = 0;
    DWCi_GetMatchCnt()->searchGroupIDRetryHostCount = 0;
    DWCi_GetMatchCnt()->connectGroupID = 0;
    DWCi_GetMatchCnt()->qr2MatchTypeExt = 0;
    DWCi_GetMatchCnt()->qr2HostState = 0;
    q = DWCi_GetMatchCnt();
    q->sbUpdateRequestTick = 0;
    DWCi_GetMatchCnt()->matchSessionID = 0;
    DWCi_GetMatchCnt()->serverLockEnabled = 1;
    DWCi_GetMatchCnt()->cancelFromConnection = 0;
    DWCi_GetMatchCnt()->retryCountMax = 0;
    DWCi_GetMatchCnt()->topologyType = 0;
    DWCi_NodeInfoList_Clear();
    DWCi_TempNewNodeInfo_Clear();
    DWCi_ClearGameMatchKeys();
    return func_0216F388(0);
}


/*
 * notes:    the three callback stubs (0x02174C2C PlayerKey, 0x02174C30 TeamKey, 0x02174CF0 Count) were seeded and catalogued by w7_nm from this function's ABS32 pool words
 *
 * sdk:      DWCi_QR2Startup (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int DWCi_QR2Startup(int profileID)
{
    int i;
    int qr2Error;

    if (DWCi_GetMatchCnt()->qr2Obj != 0)
        return 0;
    for (i = 0; i < 1; i++) {
        qr2Error = qr2_init_socketA(&DWCi_GetMatchCnt()->qr2Obj,
                                 gt2GetSocketSOCKET(*DWCi_GetMatchCnt()->pGt2Socket),
                                 gt2GetLocalPort(*DWCi_GetMatchCnt()->pGt2Socket),
                                 DWCi_GetMatchCnt()->gameName,
                                 DWCi_GetMatchCnt()->secretKey,
                                 1, 1,
                                 DWCi_QR2ServerKeyCallback, DWCi_QR2PlayerKeyCallback, DWCi_QR2TeamKeyCallback,
                                 DWCi_QR2KeyListCallback, DWCi_QR2CountCallback, DWCi_QR2AddErrorCallback,
                                 0);
        if (qr2Error == 0)
            break;
        qr2_shutdown(DWCi_GetMatchCnt()->qr2Obj);
        DWCi_GetMatchCnt()->qr2Obj = 0;
        if (qr2Error != 3 || i == 0) {
            DWCi_HandleQR2Error(qr2Error);
            return qr2Error;
        }
    }
    DWCi_GetMatchCnt()->qr2IP = 0;
    DWCi_GetMatchCnt()->qr2Port = 0;
    func_0219B1AC(DWCi_GetMatchCnt()->qr2Obj, func_02174D04);
    func_0219B134(DWCi_GetMatchCnt()->qr2Obj, DWCi_QR2NatnegCallback);
    func_0219B170(DWCi_GetMatchCnt()->qr2Obj, DWCi_QR2ClientMsgCallback);
    DWCi_RegisterMatchmakeKeys();
    func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    return qr2Error;
}


void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    int sbError;
    unsigned int addFilterLenMax;
    char filter[511];

    if (g_021AAA20.addFilter != 0) {
        DWC_Free(4, g_021AAA20.addFilter, 0);
        g_021AAA20.addFilter = 0;
    }
    if (addFilter != 0) {
        addFilterLenMax = 0x1ff - DWCi_GetDefaultMatchFilter(filter, -1, 32, 3, 3) - func_0209477C((const u8 *)g_021A2044);
        g_021AAA20.addFilter = DWC_Alloc(4, addFilterLenMax);
        if (g_021AAA20.addFilter == 0) {
            DWCi_StopMatch(9, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, g_021AAA20.addFilter, addFilterLenMax);
        (g_021AAA20.addFilter + addFilterLenMax)[-1] = 0;
    }
    DWCi_SetMatchCommonParam(0, numEntry, matchedCallback, matchedParam);
    DWCi_GetMatchCnt()->newClientCallback = newClientCallback;
    DWCi_GetMatchCnt()->newClientParam = newClientParam;
    DWCi_GetMatchCnt()->evalCallback = (DWCEvalCallback)evalCallback;
    DWCi_GetMatchCnt()->evalParam = evalParam;
    DWCi_GetMatchCnt()->topologyType = topology;
    DWCi_SetConnectionAttemptParam(attemptCallback, connectionUserData, attemptParam);
    DWCi_SetMatchStatus(0x16);
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        DWCi_GetMatchCnt()->sbObj = func_0219EC74(DWCi_GetMatchCnt()->gameName, DWCi_GetMatchCnt()->gameName, DWCi_GetMatchCnt()->secretKey, 0, 20, 1, 0, DWCi_SBCallback, 0);
    }
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        if (DWCi_HandleSBError(5))
            return;
    }
    DWCi_GPSetServerStatus(3);
    if (DWCi_GetMatchCnt()->qr2Obj == 0) {
        if (DWCi_QR2Startup(DWCi_GetMatchCnt()->profileID))
            return;
    } else {
        func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    }
    sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID);
    DWCi_HandleSBError(sbError);
}


void DWCi_SetupGameServer(int topology, u8 numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam)
{
    DWCi_SetMatchCommonParam(2, numEntry, matchedCallback, matchedParam);
    DWCi_GetMatchCnt()->newClientCallback = newClientCallback;
    DWCi_GetMatchCnt()->newClientParam = newClientParam;
    DWCi_GetMatchCnt()->topologyType = topology;
    DWCi_SetConnectionAttemptParam(attemptCallback, connectionUserData, attemptParam);
    DWCi_SetMatchStatus(0x16);
    if (func_02173D28(DWCi_GPSetServerStatus(6)) != 0)
        return;
    func_02175F84(2);
    DWCi_GetMatchCnt()->isFirstServer = 1;
    if (DWCi_GetMatchCnt()->qr2Obj == 0) {
        if (DWCi_QR2Startup(DWCi_GetMatchCnt()->profileID) != 0)
            return;
    }
    DWCi_GetMatchCnt()->groupID = func_02175530();
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        DWCi_GetMatchCnt()->sbObj = func_0219EC74(DWCi_GetMatchCnt()->gameName,
                                                  DWCi_GetMatchCnt()->gameName,
                                                  DWCi_GetMatchCnt()->secretKey, 0, 0x14, 1, 0,
                                                  DWCi_SBCallback, 0);
    }
    func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    DWCi_HandleSBError(DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID));
}


/*
 * sdk:      DWCi_ConnectToGameServerAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
void func_0216D27C(int topology, int serverPid, void *matchedCallback, void *matchedParam,
                   void *newClientCallback, void *newClientParam, void *attemptCallback,
                   u8 *connectionUserData, void *attemptParam)
{
    DWCstNodeInfo tempNodeInfoBackup;
    DWCstNodeInfo myNodeInfoBackup;
    DWCstNodeInfo serverNodeInfo;
    u8 scResvRetryCount;

    if (DWCi_GetMatchCnt()->connectGroupID != 0) {
        tempNodeInfoBackup = DWCi_GetMatchCnt()->tempNewNodeInfo;
        myNodeInfoBackup = *DWCi_NodeInfoList_GetMyNodeInfo();
        scResvRetryCount = DWCi_GetMatchCnt()->scResvRetryCount;
    }
    DWCi_SetMatchCommonParam(3, 0, matchedCallback, matchedParam);
    DWCi_GetMatchCnt()->topologyType = topology;
    if (DWCi_GetMatchCnt()->connectGroupID == 0) {
        MI_CpuFill8(&serverNodeInfo, 0, 0x28);
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt()->tempNewNodeInfo.aid = 0xff;
        DWCi_GetMatchCnt()->tempNewNodeInfo.profileID = serverPid;
    } else {
        DWCi_GetMatchCnt()->tempNewNodeInfo = tempNodeInfoBackup;
        DWCi_NodeInfoList_InsertToTop(&myNodeInfoBackup);
        MI_CpuCopy8(myNodeInfoBackup.connUserData, DWCi_GetMatchCnt()->connUserData, 4);
        DWCi_GetMatchCnt()->scResvRetryCount = scResvRetryCount;
    }
    DWCi_GetMatchCnt()->newClientCallback = newClientCallback;
    DWCi_GetMatchCnt()->newClientParam = newClientParam;
    DWCi_SetConnectionAttemptParam(attemptCallback, connectionUserData, attemptParam);
    DWCi_GetMatchCnt()->qr2Flag18 = 1;
    DWCi_GetMatchCnt()->serverProfileID = DWCi_GetMatchCnt()->profileID;
    func_02175F84(1);
    if (DWCi_GetMatchCnt()->connectGroupID == 0)
        DWCi_SetMatchStatus(0x16);
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        DWCi_GetMatchCnt()->sbObj = func_0219EC74(
            DWCi_GetMatchCnt()->gameName,
            DWCi_GetMatchCnt()->gameName,
            DWCi_GetMatchCnt()->secretKey, 0, 0x14, 1, 0, DWCi_SBCallback, 0);
    }
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        if (DWCi_HandleSBError(5) != 0)
            return;
    }
    if (func_02173D28(DWCi_GPSetServerStatus(5)) != 0)
        return;
    if (DWCi_GetMatchCnt()->qr2Obj == 0) {
        if (DWCi_QR2Startup(DWCi_GetMatchCnt()->profileID) != 0)
            return;
    } else {
        func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    }
    if (DWCi_GetMatchCnt()->connectGroupID == 0) {
        DWCi_HandleSBError(DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID));
        return;
    }
    func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    DWCi_SetMatchStatus(3);
    DWCi_HandleMatchCommandError(func_021719D0(serverPid, 0));
}


void DWCi_SendStateChanged(struct qr2_implementation_s *qr2Obj)
{
    if (qr2Obj == 0)
        return;
    qr2_think(qr2Obj);
    if (qr2Obj->userstatechangerequested != 0)
        return;
    switch (DWCi_GetMatchCnt()->qr2MatchType) {
    case 0:
    case 2:
    case 3:
        DWCi_GetMatchCnt();
        break;
    }
}


/* clWaitTime rewound so the next poll fires 6000 ms after now (30000 ms timeout) */
static inline void DWCi_SetClWaitTime(u64 now)
{
    DWCi_GetMatchCnt()->clWaitTime = now - (u64)24000 * 33514 / 64;
}


void DWCi_MatchProcess(int fullSpec)
{
    u32 sbInterval;
    DWCstNodeInfo *node;
    DWCstMatchControl *mc;
    u8 idx;

    if (DWCi_GetMatchCnt() == 0 || DWCi_IsError())
        return;

    if (!fullSpec) {
        if (DWCi_GetMatchCnt()->qr2Obj)
            qr2_think(DWCi_GetMatchCnt()->qr2Obj);
        if (DWCi_GetMatchCnt()->pGt2Socket)
            gt2Think(*DWCi_GetMatchCnt()->pGt2Socket);
        return;
    }

    if (DWCi_GetMatchCnt()->state == 0)
        return;

    switch (DWCi_GetMatchCnt()->state) {
    case 3:
        if (DWCi_GetMatchCnt()->cmdTimeoutTime &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdTimeoutStartTick) > DWCi_GetMatchCnt()->cmdTimeoutTime) {
            DWCi_GetMatchCnt()->cmdTimeoutTime = 0;
            if (DWCi_GetMatchCnt()->connectGroupID) {
                DWCi_GetMatchCnt();
                DWCi_GetMatchCnt()->scResvRetryCount++;
                if (DWCi_GetMatchCnt()->scResvRetryCount > DWCi_GetMatchCnt()->retryCountMax) {
                    DWCi_StopMatch(0x16, -80432);
                    return;
                }
                DWCi_RetryReserving(0);
                return;
            }
            if (DWCi_StopMeshMaking() == 1) {
                DWCi_SetMatchStatus(1);
                break;
            }
            if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3) {
                DWCi_GetMatchCnt();
                DWCi_GetMatchCnt()->scResvRetryCount++;
                if (DWCi_GetMatchCnt()->scResvRetryCount > DWCi_GetMatchCnt()->retryCountMax) {
                    DWCi_StopMatch(0x16, -80430);
                    return;
                }
                if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID, 0)))
                    return;
            } else if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
                DWCi_TempNewNodeInfo_Clear();
                if (!DWCi_RetryReserving(0))
                    return;
            } else {
                DWCi_TempNewNodeInfo_Clear();
                if (!DWCi_RetryReserving(0))
                    return;
            }
        }
        if (DWCi_GetMatchCnt()->cmdResendFlag &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdResendTick) >= 3000) {
            if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID, 0)))
                return;
        }
        break;

    case 2:
    case 4:
    case 22:
        if (DWCi_GetMatchCnt()->sbUpdateFlag > 0) {
            if (DWCi_GetMatchCnt()->state == 2) {
                if (DWCi_GetMatchCnt()->sbUpdateFlag == 1 || DWCi_GetMatchCnt()->serverBrowserUpdateCount <= 1)
                    sbInterval = 4000;
                else
                    sbInterval = 12000;
            } else {
                if (DWCi_GetMatchCnt()->state == 22)
                    sbInterval = 4000;
                else if (DWCi_GetMatchCnt()->sbUpdateFlag == 1)
                    sbInterval = 4000;
                else
                    sbInterval = 12000;
            }
            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->sbUpdateTick) > sbInterval) {
                if (DWCi_HandleSBError(DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->reqProfileID)))
                    return;
                DWCi_GetMatchCnt()->sbUpdateFlag = 0;
            }
        }
        break;

    case 6:
        if (DWCi_GetMatchCnt()->nnFinishTime) {
            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->nnFinishTime) > 25000) {
                DWCi_GetMatchCnt()->nnFinishTime = 0;
                if (DWCi_StopMeshMaking() == 1) {
                    DWCi_SetMatchStatus(1);
                } else if (!((int (*)(int))DWCi_CancelPreConnectedClientProcess)(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
                    DWCi_TempNewNodeInfo_Clear();
                    return;
                }
            }
        } else if (DWCi_GetMatchCnt()->cmdCnt.command == 6) {
            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 6000) {
                if (DWCi_StopMeshMaking() == 1) {
                    DWCi_StopResendingMatchCommand();
                    DWCi_SetMatchStatus(1);
                } else {
                    DWCi_GetMatchCnt()->cmdCnt.count++;
                    if (DWCi_GetMatchCnt()->cmdCnt.count > 5) {
                        DWCi_StopResendingMatchCommand();
                        if (!((int (*)(int))DWCi_CancelPreConnectedClientProcess)(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
                            DWCi_TempNewNodeInfo_Clear();
                            return;
                        }
                    } else if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(6,
                                   DWCi_GetMatchCnt()->cmdCnt.profileID,
                                   DWCi_GetMatchCnt()->cmdCnt.ip,
                                   DWCi_GetMatchCnt()->cmdCnt.port,
                                   DWCi_GetMatchCnt()->cmdCnt.data,
                                   DWCi_GetMatchCnt()->cmdCnt.len))) {
                        return;
                    }
                }
            }
        }
        break;

    case 14:
        if (DWCi_GetMatchCnt()->cmdCnt.command == 2) {
            if ((DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 &&
                 TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 6000) ||
                (DWCi_GetMatchCnt()->qr2MatchTypeExt != 0 &&
                 TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 19000)) {
                DWCi_StopResendingMatchCommand();
                if (DWCi_StopMeshMaking() == 1) {
                    DWCi_SetMatchStatus(1);
                } else if (!DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
                    return;
                }
            }
        }
        break;

    case 16:
        if (DWCi_GetMatchCnt()->cmdCnt.command == 8 &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 30000) {
            DWCi_GetMatchCnt()->cmdCnt.count++;
            if (DWCi_GetMatchCnt()->cmdCnt.count > 0) {
                DWCi_StopResendingMatchCommand();
                if (!DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID))
                    return;
            }
        }
        break;

    case 1:
        if (DWC_GetState() == 4 && DWCi_GetMatchCnt()->needServerPoll &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 30000) {
            node = &DWCi_GetMatchCnt()->tempNewNodeInfo;
            if (DWCi_GetMatchCnt()->clWaitTimeoutCount >= 5) {
                if (!((int (*)(int))DWCi_CancelPreConnectedClientProcess)(node->profileID))
                    return;
            } else {
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x40, node->profileID, node->publicInetAddress,
                                                                       node->publicQueryPort, 0, 0)))
                    return;
                DWCi_GetMatchCnt()->clWaitTimeoutCount++;
                DWCi_SetClWaitTime(OS_GetTick());
            }
        }
        break;

    case 9:
        DWCi_StopMeshMaking();
        mc = DWCi_GetMatchCnt();
        mc->serverDownBuff = 0;
        mc->serverDownQueryCount = 0;
        mc->serverDownNakCount = 0;
        if (!DWCi_IsBackupMine() && !DWCi_GetGT2Connection(DWCi_NodeInfoList_GetNodeInfoForIndex(0)->aid)) {
            DWCi_StopMatch(0x16, -80431);
            return;
        }
        idx = DWCi_GetAIDFromProfileID(mc->profileID, 1);
        mc->serverDownBuff |= 1 << idx;
        if (DWCi_IsBackupMine()) {
            if (!DWCi_IsServerChangeEnabled()) {
                DWCi_StopMatch(0x16, -80431);
            } else {
                DWCi_SendServerDownQuery();
                DWCi_SetMatchStatus(10);
                qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
                DWCi_InitClWaitTimeout();
            }
        } else {
            qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
            DWCi_SetMatchStatus(10);
            DWCi_InitClWaitTimeout();
        }
        break;

    case 10:
        if (DWCi_IsBackupMine()) {
            u32 noResponseHosts;
            int i;

            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 5000) {
                DWCi_SendServerDownQuery();
                if (++DWCi_GetMatchCnt()->serverDownQueryCount > 5) {
                    noResponseHosts = ~(DWCi_GetMatchCnt()->serverDownBuff & DWCi_GetMatchCnt()->serverDownBase);
                    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
                        DWCstNodeInfo *info = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                        if (noResponseHosts & (1 << info->aid))
                            DWCi_CloseConnectionHard(info->aid);
                    }
                    DWCi_GetMatchCnt()->serverDownBuff = DWCi_GetMatchCnt()->serverDownBase;
                }
            }
            if (!(DWCi_GetMatchCnt()->serverDownBuff ^ DWCi_GetMatchCnt()->serverDownBase))
                DWCi_SetMatchStatus(11);
        } else if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 60000) {
            DWCi_StopMatch(0x16, -80431);
        }
        break;

    case 11:
        if (DWCi_IsBackupMine()) {
            if (!DWCi_IsServerChangeEnabled()) {
                DWCi_StopMatch(0x16, -80431);
            } else {
                DWCi_SetupGameServer_InterChange(0);
                DWCi_GetMatchCnt()->serverPollingTime = 0;
                DWCi_ResetLastSomeDataRecvTimeByAidAll();
                DWCi_AutoSuspendComplete();
                qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
            }
        } else if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 20000) {
            DWCi_SetMatchStatus(1);
        }
        break;

    case 12:
        if (DWCi_GetMatchCnt()->sbUpdateFlag > 0 &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->sbUpdateTick) > 8000) {
            if (++DWCi_GetMatchCnt()->searchGroupIDRetryHostCount > 15) {
                DWCi_StopMatch(0x16, -80432);
            } else {
                if (DWCi_HandleSBError(DWCi_SBUpdateAsync(0)))
                    return;
                DWCi_GetMatchCnt()->sbUpdateFlag = 0;
            }
        }
        break;

    default:
        break;
    }

    if (DWCi_GetMatchCnt()->state == 14 || DWCi_GetMatchCnt()->state == 5) {
        if (DWCi_GetMatchCnt()->nnFailedTime &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->nnFailedTime) > 10000) {
            DWCi_NNCompletedCallback(1, 0, 0, &DWCi_GetMatchCnt()->nnInfo);
        }
    }

    if (DWCi_GetTopologyType() == 0 && DWCi_GetMatchCnt()->inMeshMaking == 0 && DWCi_GetMatchCnt()->state == 1 &&
        DWCi_GetMatchCnt()->tempNewClientInfo.profileID == 0 && DWCi_NodeInfoList_GetCount() > 2) {
        int i;

        for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
            DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            void *connection;

            if (DWCi_NodeInfoList_GetMyNodeInfo() == pNodeInfo)
                continue;
            connection = DWCi_GetGT2Connection(pNodeInfo->aid);
            if (connection)
                continue;
            if (pNodeInfo->nextMeshMakeTryTick == 0)
                pNodeInfo->nextMeshMakeTryTick = DWCi_GetNextMeshMakeTryTick();
            if (OS_GetTick() > pNodeInfo->nextMeshMakeTryTick &&
                pNodeInfo->nnTryCount <= s_anybodyServerSearchRatio.meshMakeNNRetryMax) {
                pNodeInfo->nextMeshMakeTryTick = DWCi_GetNextMeshMakeTryTick();
                DWCi_GetMatchCnt()->tempNewNodeInfo = *pNodeInfo;
                DWCi_GetMatchCnt()->inMeshMaking = 1;
                if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(pNodeInfo->profileID, 0))) {
                    DWCi_GetMatchCnt()->inMeshMaking = 0;
                    DWCi_TempNewNodeInfo_Clear();
                } else {
                    DWCi_ClearMeshMakingTempInfo();
                    DWCi_SetMatchStatus(3);
                }
                break;
            }
        }
    }

    if (DWCi_GetMatchCnt()->sbObj) {
        g_021AAA20.sbCallbackLevel = 0;
        g_021AAA20.needSbFree = 0;
        g_021AAA20.bInNNThink = 1;
        ServerBrowserThink(DWCi_GetMatchCnt()->sbObj);
        if (g_021AAA20.needSbFree) {
            ServerBrowserFree(DWCi_GetMatchCnt()->sbObj);
            DWCi_GetMatchCnt()->sbObj = 0;
        }
        if (DWCi_GetMatchCnt()->sbObj && ServerBrowserState(DWCi_GetMatchCnt()->sbObj) != 0 &&
            DWCi_GetMatchCnt()->sbUpdateRequestTick && OS_GetTick() > DWCi_GetMatchCnt()->sbUpdateRequestTick) {
            DWCi_StopMatch(6, -85010);
        }
    }

    g_021AAA20.bNNFreeNegotiateList = 0;
    g_021AAA20.bInNNThink = 1;
    DWCi_SendStateChanged(DWCi_GetMatchCnt()->qr2Obj);
    NNThink();
    g_021AAA20.bInNNThink = 0;
    if (g_021AAA20.bNNFreeNegotiateList == 1) {
        g_021AAA20.bNNFreeNegotiateList = 0;
        NNFreeNegotiateList();
    }

    if (DWCi_GetMatchCnt()->pGt2Socket)
        gt2Think(*DWCi_GetMatchCnt()->pGt2Socket);

    if (DWCi_GetMatchCnt()->state == 21 &&
        TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->closedTime) > 3000) {
        if (DWCi_ResumeMatch())
            return;
    }

    DWCi_RequestSuspendMatchProcess();
    DWCi_SendServerPolling(0);
    if (!DWCi_ProcessMatchSynTimeout())
        return;
    DWCi_ProcessCancelMatchSynTimeout();
}


/*
 * sdk:      DWCi_GT2UnrecognizedMessageCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_GT2UnrecognizedMessageCallback(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len)
{
    SOCSockAddrIn saddr;

    if (len == 0 || message == 0)
        return 0;
    MIi_CpuClear32(0, &saddr, 8);
    saddr.family = 2;
    saddr.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    saddr.addr.addr = ip;
    ip = message[0];
    if ((ip == 0xFE && message[1] == 0xFD) || ip == 0x5C) {
        if (DWCi_GetMatchCnt()->qr2Obj != 0)
            qr2_parse_queryA(DWCi_GetMatchCnt()->qr2Obj, message, len, &saddr);
    } else if (func_020923F0(message, (const u8 *)((char *)&g_021A5A7C), 6) == 0) {
        func_0219AB8C((char *)message, len, &saddr);
    } else {
        return 0;
    }
    return 1;
}


void DWCi_GT2ConnectAttemptCallback(void * userdata, void * connection,
                                    unsigned int ip, unsigned short port,
                                    int latency, unsigned char * message, int len)
{
    int index;
    int remotePid = 0;
    DWCstConnectionInfo * pConInfo;
    DWCstMatchControl * m;
    void ** pGt2Con;

    if (DWCi_GetMatchCnt() != 0 && DWCi_GetMatchCnt()->state == 5)
        return;
    if (DWCi_GetMatchCnt() != 0 && DWCi_GetMatchCnt()->state == 6 &&
        DWCi_GetMatchCnt()->cancelState == 0)
        goto process;
    gt2Reject(connection, g_021A204C, -1);
    return;

process:
    if (message != 0 && len != 0)
        remotePid = strtoul((char *)message, 0, 10);
    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        gt2Reject(connection, g_021A2058, -1);
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_StopResendingMatchCommand();
            DWCi_SetMatchStatus(1);
            return;
        }
        DWCi_StopMatch(6, 0xfffeabc4);
        return;
    }
    if (DWCi_GetMatchCnt()->tempNewNodeInfo.gt2IP == ip) {
        if ((unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)) ==
            DWCi_GetMatchCnt()->tempNewNodeInfo.gt2Port)
            goto accept;
    }
    if (remotePid == DWCi_GetMatchCnt()->tempNewNodeInfo.profileID) {
        DWCi_GetMatchCnt()->tempNewNodeInfo.gt2IP = ip;
        DWCi_GetMatchCnt()->tempNewNodeInfo.gt2Port = ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
        goto accept;
    }
    gt2Reject(connection, g_021A2064, -1);
    return;

accept:
    DWCi_GetMatchCnt()->nnFinishTime = 0;
    if (gt2Accept(connection, DWCi_GetMatchCnt()->gt2Callbacks) == 0) {
        DWCi_StopMatch(6, 0xfffec5e6);
        return;
    }
    DWCi_StopResendingMatchCommand();
    if (DWCi_GetMatchCnt()->inMeshMaking == 0 && DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GetMatchCnt()->hostLatency =
            (latency >> 1) >= 0xffff ? 0xffff : (latency >> 1);
    }
    pGt2Con = DWCi_GetGT2ConnectionByIdx(index);
    pConInfo = DWCi_GetConnectionInfoByIdx(index);
    *pGt2Con = connection;
    pConInfo->index = index;
    pConInfo->aid = DWCi_GetMatchCnt()->tempNewNodeInfo.aid;
    pConInfo->profileID = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
    DWCi_ResetLastSomeDataRecvTimeByAid(pConInfo->aid);
    gt2SetConnectionData(connection, pConInfo);
    DWCi_PostProcessConnection(2);
}


void DWCi_MakeGT2ConnectString(char *buf, int bufLen)
{
    OS_SNPrintf(buf, bufLen, g_021A207C, DWCi_GetMatchCnt()->profileID);
}


void DWCi_GT2ConnectedCallback(void * connection, int result)
{
    DWCstConnectionInfo * pConInfo;
    void ** pGt2Con;
    char pidStr[24];
    int gt2Result;
    int index;

    if (DWCi_GetMatchCnt() != 0) {
        if (DWCi_GetMatchCnt()->state == 6)
            goto entry;
        if (DWCi_GetMatchCnt()->state == 0xf)
            goto entry;
    }
    if (DWCi_GetMatchCnt()->backupState != 0xf)
        return;
entry:
    if (result != 0) {
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            return;
        }
        if (DWCi_GetMatchCnt()->backupState == 0xf) {
            DWCi_ClearMeshMakingTempInfo();
            return;
        }
        if (result == 5)
            return;
        if (result == 6) {
            DWCi_GetMatchCnt()->gt2RetryCount++;
            if (DWCi_GetMatchCnt()->gt2RetryCount > 5) {
                DWCi_GetMatchCnt()->gt2RetryCount = 0;
                DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID);
                return;
            }
            DWCi_MakeGT2ConnectString(pidStr, 0x18);
            gt2Result = gt2Connect(*(void **)DWCi_GetMatchCnt()->pGt2Socket, 0,
                gt2AddressToString(DWCi_GetMatchCnt()->tempNewNodeInfo.gt2IP,
                                   DWCi_GetMatchCnt()->tempNewNodeInfo.gt2Port, 0),
                (u8 *)pidStr, -1, 0x1388, DWCi_GetMatchCnt()->gt2Callbacks, 0);
            if (gt2Result == 1) {
                DWCi_HandleGT2Error(gt2Result);
                return;
            }
            if (gt2Result == 0)
                return;
            DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID);
            return;
        }
        DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID);
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
    pConInfo->index = index;
    if (DWCi_GetMatchCnt()->backupState != 0xf) {
        pConInfo->aid = DWCi_GetMatchCnt()->tempNewNodeInfo.aid;
        pConInfo->profileID = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
    } else {
        pConInfo->aid = DWCi_GetMatchCnt()->backupAid;
        pConInfo->profileID = DWCi_GetMatchCnt()->backupProfileID;
    }
    DWCi_ResetLastSomeDataRecvTimeByAid(pConInfo->aid);
    gt2SetConnectionData(connection, pConInfo);
    if (DWCi_GetMatchCnt()->state == 0xf ||
        DWCi_GetMatchCnt()->backupState == 0xf)
        DWCi_PostProcessConnection(0);
    else
        DWCi_PostProcessConnection(1);
}


/*
 * sdk:      DWCi_MatchGPRecvBuddyMsgCallback (dwc_match.o)
 */
extern void func_0216EAB8(int unused, int profileID, char *message)
{
    unsigned int data[128];
    int msgLen;
    int dataLen;

    msgLen = strlen(message);
    if (msgLen - 1 == 0) {
        dataLen = 0;
    } else {
        int len = func_02059CBC(message + 1, msgLen - 1, data, 512);

        if (len == -1)
            return;
        if (len % 4 != 0)
            return;
        if (len > 512)
            return;
        dataLen = len / 4;
    }
    DWCi_ProcessRecvMatchCommand(*(unsigned char *)message, profileID, 0, 0, data, dataLen);
}


/*
 * Arms both module flags.
 */
void DWCi_StopResendingMatchCommand(void)
{
    DWCi_GetMatchCnt()->cmdCnt.command = 0xff;
    DWCi_GetMatchCnt()->cmdCnt.count = 0;
}


/*
 * DWCi_StopMatch: closes every connection, records the error and reports the failure to the match callback.
 */
void DWCi_StopMatch(int error, int errorCode)
{
    int self;
    int isServer;

    if (DWCi_GetMatchCnt() == 0 || error == 0) {
        return;
    }
    DWCi_CloseAllConnectionsByTimeout();
    DWCi_SetError(error, errorCode);
    self = 1;
    DWCi_GPSetServerStatus(self);
    if (DWCi_GetMatchCnt()->peerProfileID != 0) {
        self = 0;
    }
    (DWCi_GetMatchCnt()->matchedCallback)(
        error, 0, self, DWCi_GetMatchCnt()->qr2MatchType == 2,
        func_02169038(DWCi_GetMatchCnt()->peerProfileID), DWCi_GetMatchCnt()->matchedParam);
    DWCi_CloseMatch();
}


void DWCi_ClearQR2Key(void)
{
    if (DWC_GetState() != 3)
        return;
    DWCi_GetMatchCnt()->qr2NumEntry = 0;
    DWCi_GetMatchCnt()->groupID = 0;
    qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}


void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data)
{
    if (DWCi_IsFullMesh())
        DWCi_ProcessMatchSynPacketSub_FullMesh(aid, type, data);
    else
        DWCi_ProcessMatchSynPacketSub_Hybrid(aid, type, data);
}


void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data)
{
    DWCstNodeInfo tempNodeInfo;
    DWCstNodeInfo tempNodeInfo2;
    int i;
    u32 *entry;
    int clientCount;

    switch (type) {
    case 2:
        if (MC()->state != 1)
            return;
        if (*(u32 *)data == 1) {
            MC()->peerProfileID = 0;
            MC()->tempNewClientInfo.profileID = 0;
            {
                u32 v = *(u32 *)(data + 4);

                MC()->matchSessionID = v;
            }
            if (DWCi_IsFullMesh())
                DWCi_NodeInfoList_InsertToTop(&MC()->tempNewNodeInfo);
        } else {
            u32 w;
            u32 *p = (u32 *)data;

            MI_CpuFill8(&tempNodeInfo, 0, sizeof(tempNodeInfo));
            w = p[1];
            tempNodeInfo.aid = (u8)w;
            tempNodeInfo.hasPrivateAddress = (u8)(w >> 16);
            tempNodeInfo.profileID = p[2];
            tempNodeInfo.publicInetAddress = p[3];
            tempNodeInfo.privateInetAddress = p[4];
            tempNodeInfo.publicQueryPort = (u16)(p[5] >> 16);
            tempNodeInfo.privateQueryPort = (u16)p[5];
            memcpy(&tempNodeInfo.connUserData, data + 0x18, 4);
            MC()->tempNewClientInfo = tempNodeInfo;
            w = p[7];
            MC()->matchSessionID = w;
            MC()->peerProfileID = tempNodeInfo.profileID;
        }
        {
            int latency;

            if (DWCi_NodeInfoList_GetCount() == 1)
                latency = 0x15f90;
            else
                latency = DWCi_NodeInfoList_GetCount() * 0x2ee0;
            MC()->clWaitTime = latency;
        }
        MC()->clWaitTimeoutCount = 0;
        DWCi_SetMatchStatus(8);
        DWCi_SendMatchSynPacket(aid, 3);
        return;
    case 3: {
        u16 onewayGT2Latency;
        u32 bitmask;

        if (MC()->state == 0x13) {
            onewayGT2Latency = (u16)(data[0] | (data[1] << 8));
            MC()->synAckBitmap |= 1 << aid;
            if (MC()->hostLatency < onewayGT2Latency)
                MC()->hostLatency = onewayGT2Latency;
            bitmask = DWCi_GetAIDBitmask(0);
            if (bitmask != MC()->synAckBitmap)
                return;
            {
                DWCstMatchControl *mc = MC();

                mc->matchSessionID = DWCi_GetMathRand32(0 - 2) + 1;
            }
            DWCi_SendTypeMatchAck();
            MC()->synResendCount = 0;
            {
                unsigned long long tick = OS_GetTick();

                MC()->synAckTick = tick;
            }
        } else {
            DWCi_SendMatchSynPacket(aid, 4);
        }
        return;
    }
    case 4:
        if (MC()->state != 8)
            return;
        clientCount = *(int *)data;
        if (clientCount != 0) {
            u32 v;

            for (i = 0; i < clientCount; i++) {
                entry = (u32 *)(data + 4) + (clientCount - 1 - i) * 6;

                MI_CpuFill8(&tempNodeInfo2, 0, sizeof(tempNodeInfo2));
                tempNodeInfo2.aid = (u8)entry[0];
                tempNodeInfo2.hasPrivateAddress = (u8)(entry[0] >> 16);
                tempNodeInfo2.profileID = entry[1];
                tempNodeInfo2.publicInetAddress = entry[2];
                tempNodeInfo2.privateInetAddress = entry[3];
                tempNodeInfo2.privateQueryPort = (u16)entry[4];
                tempNodeInfo2.publicQueryPort = (u16)(entry[4] >> 16);
                memcpy(&tempNodeInfo2.connUserData, (u8 *)entry + 0x14, 4);
                DWCi_NodeInfoList_InsertToTop(&tempNodeInfo2);
            }
            v = ((u32 *)data + clientCount * 6)[1];
            MC()->matchSessionID = v;
            DWCi_NodeInfoList_InsertToTop(&MC()->tempNewNodeInfo);
            DWCi_TempNewNodeInfo_Clear();
        } else {
            u32 v = *(u32 *)(data + 4);

            MC()->matchSessionID = v;
        }
        DWCi_PostProcessConnection(3);
        return;
    default:
        return;
    }
}


void DWCi_ProcessMatchSynPacketSub(unsigned char aid, unsigned short type, unsigned char *data)
{
    DWCi_ProcessMatchSynPacketSub_Hybrid(aid, type, data);
}

#undef MC
#define MC() DWCi_GetMatchCnt()


/*
 * Hard-closes every aid present now but absent from the given bitmap.
 */
void DWCi_CheckDeadAIDBitmap(unsigned int bitmap)
{
    unsigned int cur = DWC_GetAIDBitmap();
    unsigned int diff = cur & (cur ^ bitmap);
    unsigned char i;

    if (diff == 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        if (diff & (1 << i)) {
            DWCi_CloseConnectionHard(i);
        }
    }
}


/*
 * DWCi_ProcessMatchPollingPacket: on a client, closes the aids a server poll no longer lists.
 */
void DWCi_ProcessMatchPollingPacket(const Poll *p)
{
    int pid = p->pid;
    unsigned int bitmap = p->bitmap;
    int id = p->id;
    DWCstNodeInfo *node;

    if (DWC_IsServerMyself() != 0) {
        return;
    }
    if (id != DWCi_GetMatchCnt()->matchSessionID) {
        return;
    }
    node = DWCi_NodeInfoList_GetServerNodeInfo();
    if (node == 0) {
        return;
    }
    if (node->profileID != pid) {
        return;
    }
    DWCi_CheckDeadAIDBitmap(bitmap);
}


/*
 * sdk:      DWCi_ProcessMatchClosing (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_ProcessMatchClosing(int error, int errorCode)
{
    u64 tick;

    if (DWC_GetState() != 4)
        return 0;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchType == 2)
        return 1;
    if (error != 0) {
        DWCi_StopMatch(error, errorCode - 80000);
        return 1;
    }
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->cancelState == 1 || ((DWCstMatchControl *)DWCi_GetMatchCnt())->closeState == 1)
        return 1;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie != 0) {
        NNCancel(((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie);
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie = 0;
    }
    if (DWCi_NodeInfoList_GetCount() > 1) {
        if (((DWCstMatchControl *)DWCi_GetMatchCnt())->closeState == 0) {
            ((DWCstMatchControl *)DWCi_GetMatchCnt())->closeState = 2;
            func_02195DE4((int *)(*((DWCstMatchControl *)DWCi_GetMatchCnt())->pGt2Socket));
        }
    } else if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchTypeExt == 3) {
        DWCi_StopMatch(0x16, -80430);
    } else if (((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 1) {
        DWCi_SetMatchStatus(0x15);
        tick = func_020870D0();
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->closedTime = tick;
    } else {
        func_02172BB8(1);
    }
    return 1;
}


void DWCi_ProcessMatchSCClosing(int clientPid)
{
    if (DWCi_GetMatchCnt()->closeState == 1)
        return;
    DWCi_CancelPreConnectedServerProcess(clientPid);
}


/*
 * Builds the match key-value status string and hands it to DWCi_SetGPStatus.
 */
int DWCi_GPSetServerStatus(int status)
{
    char value[12];
    char str[0x27];
    int n;

    OS_SNPrintf(value, 12, d_021A207C, *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x17) + 1);
    func_02168454(d_021A2080, value, str, '/');
    n = DWCi_NodeInfoList_GetCount();
    if (*(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x15) == 2 && n == 0) {
        n = 1;
    }
    OS_SNPrintf(value, 12, d_021A207C, n);
    func_0216848C(d_021A2084, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, 0x5a);
    func_0216848C(d_021A2088, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, DWCi_IsServerLocked() ? 1 : 0);
    func_0216848C(d_021A208C, value, str, '/');
    return func_021690D0(status, str, 0);
}


void DWCi_ShutdownMatch(void)
{
    DWCi_SetMatchCnt(0);
    if (s_bInNNThink.addFilter != 0) {
        DWC_Free(4, s_bInNNThink.addFilter, 0);
        s_bInNNThink.addFilter = 0;
    }
    DWCi_ClearGameMatchKeys();
}


/*
 * Set when the module block is absent.
 */
int DWCi_IsShutdownMatch(void)
{
    return DWCi_GetMatchCnt() == 0;
}


void DWCi_ResetMatchParam(int level)
{
	*(u8 *)(MCP + 0xc) = 0;
	*(u8 *)(MCP + 0x5f8) = 0;
	*(u16 *)(MCP + 0x5fa) = DWCi_GetMathRand32(0x10000);
	*(u32 *)(MCP + 0x5fc) = 0;
	*(u64 *)(MCP + 0x600) = 0;
	*(u64 *)(MCP + 0x608) = 0;
	*(u8 *)(MCP + 0x620) = 0;
	*(u8 *)(MCP + 0x62a) = 0;
	*(u8 *)(MCP + 0x62b) = 0;
	*(u8 *)(MCP + 0x62c) = 0;
	*(u8 *)(MCP + 0x62d) = 0;
	*(u8 *)(MCP + 0x628) = 0;
	*(u8 *)(MCP + 0x629) = 0;
	*(u16 *)(MCP + 0x632) = 0;
	*(u64 *)(MCP + 0x658) = 0;
	*(u64 *)(MCP + 0x668) = 0;
	MIi_CpuClear32(0, MCP + 0x6d8, 0x98);
	*(u32 *)(MCP + 0x5a4) = 0;
	DWCi_ClearMeshMakingTempInfo();
	if (level == 2) {
		if (DWCi_GetHostStatus() == 2) {
			DWCi_SetMatchStatus(0xd);
			return;
		}
		if (DWCi_GetHostStatus() == 1)
			DWCi_SetMatchStatus(1);
		return;
	}
	*(u8 *)(MCP + 0x18) = 0;
	*(u32 *)(MCP + 0x5dc) = 0;
	*(u32 *)(MCP + 0x5e4) = 0;
	*(u16 *)(MCP + 0x630) = 0;
	*(u8 *)(MCP + 0x621) = 0;
	*(u32 *)(MCP + 0x638) = 0;
	*(u64 *)(MCP + 0x63c) = 0;
	*(u32 *)(MCP + 0x644) = 0;
	*(u64 *)(MCP + 0x648) = 0;
	*(u32 *)(MCP + 0x650) = 0;
	*(u32 *)(MCP + 0x67c) = 0;
	MIi_CpuClear32(0, MCP + 0x610, 0xc);
	*(u32 *)(MCP + 0x788) = 0;
	*(u32 *)(MCP + 0x78c) = 0;
	*(u8 *)(MCP + 0x794) = 0;
	*(u8 *)(MCP + 0x7a8) = 1;
	*(u32 *)(MCP + 0x7ac) = 0;
	*(u8 *)(MCP + 0x16) = 0;
	*(u8 *)(MCP + 0xd) = 0;
	*(u32 *)(MCP + 0x7b8) = 0;
	*(u32 *)(MCP + 0x7c0) = 0;
	DWCi_NodeInfoList_Clear();
	DWCi_TempNewNodeInfo_Clear();
	*(u32 *)(MCP + 0x57c) = 0;
	if (level == 1) {
		if (*(u8 *)(MCP + 0x15) == 0 || *(u8 *)(MCP + 0x15) == 1)
			DWCi_SetMatchStatus(0x16);
		return;
	}
	*(u8 *)(MCP + 0x14) = 0;
	*(u8 *)(MCP + 0x17) = 0;
	*(u8 *)(MCP + 0x4c) = 0;
	*(u32 *)(MCP + 0x680) = 0;
	*(u8 *)(MCP + 0x62e) = 0;
	*(u64 *)(MCP + 0x670) = 0;
	*(u32 *)(MCP + 0x778) = 0;
	*(u32 *)(MCP + 0x77c) = 0;
	MI_CpuFill8(MCP + 0x7bc, 0, 4);
}


/*
 * sdk:      DWCi_SetMatchCommonParam (dwc_match.o)
 */
void DWCi_SetMatchCommonParam(unsigned char matchType, unsigned char numEntry, void *callback, void *param)
{
    func_0216F388(0);
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x14) = matchType;
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x17) = numEntry;
    *(void **)((char *)DWCi_GetMatchCnt() + 0x770) = callback;
    *(void **)((char *)DWCi_GetMatchCnt() + 0x774) = param;
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x5f9) = 0;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x2c) = 0xff;
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x30) = 0;
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x16) = 0;
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x7a8) = 1;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x7ac) = 0;
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x17) = numEntry;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x1c) = 0;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x28) = 0;
    *(unsigned long long *)((char *)DWCi_GetMatchCnt() + 0x20) = 0;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x48) = 0;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x7c4) = 1;
    *(unsigned long long *)((char *)DWCi_GetMatchCnt() + 0x7cc) = 0;
    *(int *)((char *)DWCi_GetMatchCnt() + 0x634) = 0;
}


/*
 * Resets the match state: frees the server browser and negotiation data and clears the node lists.
 */
void DWCi_CloseMatch(void)
{
    if (DWCi_GetMatchCnt() == 0) {
        return;
    }
    if (*(void **)((char *)DWCi_GetMatchCnt() + 0x5e0) != 0) {
        if (*(int *)(((char *)&g_021AAA20) + 0x14) != 0) {
            *(int *)(((char *)&g_021AAA20) + 0x10) = 1;
        } else {
            func_0219ED4C(*(void **)((char *)DWCi_GetMatchCnt() + 0x5e0));
            *(void **)((char *)DWCi_GetMatchCnt() + 0x5e0) = 0;
        }
    }
    func_02176B34();
    DWCi_SetMatchStatus(0);
    if (*(void **)(((char *)&g_021AAA20) + 0xc) != 0) {
        DWC_Free(4, *(void **)(((char *)&g_021AAA20) + 0xc), 0);
        *(void **)(((char *)&g_021AAA20) + 0xc) = 0;
    }
    DWCi_ClearGameMatchKeys();
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x4c) = 1;
    DWCi_NodeInfoList_Clear();
    DWCi_TempNewNodeInfo_Clear();
    *(int *)((char *)DWCi_GetMatchCnt() + 0x7c4) = 1;
    DWCi_GPSetServerStatus(1);
}




/*
 * 2026-10-01 (lane 05): rebuilt from the vendor listing, 868/868 bytes and
 *           6 concrete bytes (was 212 via permuter scaffolding).  Fixes: the
 *           ratio tests are -2 then -1 (not -1 then 0) with a signed rand
 *           compare; s_bInNNThink+0xc is a char * static passed as the
 *           SNPrintf argument; cases 3/4/0x16 and 9-11 print profileID (the
 *           parameter, still in r4) with fmt d_021A209C/d_021A20A4;
 *           searchHostType is set only in case 2; sbBlock/sbError are enums
 *           (DWARF); a real u64 tick across DWCi_GetMatchCnt; the key loop
 *           stores then increments; declarations in DWARF order.  Stand-in:
 *           the enum `n` (6 before the byte stores, then the retry counter)
 *           is not in the DWARF but is what keeps `mov sl,#6; add r7,sl,#3`
 *           and the do-while counter (an int folds both away; a 6-trip
 *           unrollable loop is not unrolled by 1.1p1).  Residue: the three
 *           DWCi_GetDefaultMatchFilter argument loads (image ldr r1 / ldrb r2
 *           / ldrb r3, ours ldrb r3 first); const members inert.
 * 2026-10-01 (wave 2 lane 20): EXACT.  The three argument loads read
 *           through `(volatile DWCstMatchControl *)` casts, which pins them
 *           in source (argument) order as the 4.0.0.1025 image has them;
 *           volatile on fewer than two of them leaves the 6 B residue.
 *
 * sdk:      DWCi_SBUpdateAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
static SBError DWCi_SBUpdateAsync(int profileID)
{
    char filter[511];
    u8 basicFields[204];
    int len;
    int numBasicFields;
    int i;
    SBError sbError;
    SBBool sbBlock;
    u8 searchHostType;
    EFld n;

    n = E6;
    basicFields[0] = 8;
    basicFields[1] = 0xa;
    basicFields[2] = 0x32;
    basicFields[3] = 0x33;
    basicFields[4] = 0x34;
    basicFields[5] = 0x35;
    basicFields[6] = 0x36;
    basicFields[7] = 0x37;
    basicFields[8] = 0x38;
    numBasicFields = n + 3;
    sbBlock = SBTrue;
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        for (i = 0; i < 154; i++) {
            if (stGameMatchKeys[i].keyID) {
                basicFields[numBasicFields] = stGameMatchKeys[i].keyID;
                numBasicFields++;
            }
        }
    }
    switch (DWCi_GetMatchCnt()->state) {
    case 2:
        if ((*(int *)&s_anybodyServerSearchRatio) == -2) {
            searchHostType = (u8)(DWCi_GetMatchCnt()->serverFind == 1 ? 2 : 3);
            DWCi_GetMatchCnt()->serverFind = 0;
        } else if ((*(int *)&s_anybodyServerSearchRatio) == -1) {
            searchHostType = (u8)(DWCi_GetMatchCnt()->serverFind ? 2 : 0);
            DWCi_GetMatchCnt()->serverFind ^= 1;
        } else {
            searchHostType = (u8)((int)func_021685CC(100) < (*(int *)&s_anybodyServerSearchRatio) ? 2 : 0);
        }
        len = DWCi_GetDefaultMatchFilter(filter, ((volatile DWCstMatchControl *)DWCi_GetMatchCnt())->profileID, ((volatile DWCstMatchControl *)DWCi_GetMatchCnt())->qr2NumEntry, ((volatile DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchTypeExt, searchHostType);
        if (s_bInNNThink.addFilter) {
            OS_SNPrintf(filter + len, 511 - len, d_021A2090, s_bInNNThink.addFilter);
            filter[510] = 0;
        }
        DWCi_GetMatchCnt()->serverBrowserUpdateCount++;
        break;
    case 3:
    case 4:
    case 0x16:
        OS_SNPrintf(filter, 511, d_021A209C, d_021A20A4, profileID);
        DWCi_GetMatchCnt()->reqProfileID = profileID;
        break;
    case 9:
    case 10:
    case 11:
        OS_SNPrintf(filter, 511, d_021A209C, d_021A20A4, profileID);
        sbBlock = SBFalse;
        break;
    case 12:
        OS_SNPrintf(filter, 511, d_021A20AC, d_021A20D4, DWCi_GetMatchCnt()->groupID, d_021A20E0, 2, d_021A20A4, DWCi_GetMatchCnt()->profileID);
        break;
    }

    func_0219F00C(DWCi_GetMatchCnt()->sbObj);
    n = E0;
    do {
        sbError = func_0219EED4(DWCi_GetMatchCnt()->sbObj, sbBlock, SBFalse, basicFields, numBasicFields, filter, DWCi_GetMatchCnt()->state == 0x16 ? 1 : 6);
        if (sbError == 0 || sbError != 2)
            break;
        n++;
    } while (n < 1);
    if (sbError == 0) {
        u64 tick = OS_GetTick();
        DWCi_GetMatchCnt()->sbUpdateRequestTick = tick + 0xefb5f7;
    }
    return sbError;
}


/*
 * sdk:      DWCi_GetDefaultMatchFilter (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_GetDefaultMatchFilter(char *filter, int profileID, unsigned char numEntry, unsigned char matchType,
                  unsigned char hostState)
{
    char tempFilter[511];

    if (hostState == 3)
        OS_SNPrintf(tempFilter, 511, g_021A20F0, g_021A20E0, 0, g_021A20E0, 2);
    else
        OS_SNPrintf(tempFilter, 511, g_021A209C, g_021A20E0, hostState);
    OS_SNPrintf(filter, 511, g_021A2108, g_021A2164, 90, g_021A20A4, profileID, numEntry, numEntry,
                  g_021A2170, matchType, g_021A217C, 0, tempFilter);
    return func_0209477C((const u8 *)filter);
}


/*
 * sdk:      IsPrivateAddr (dwc_match.o)
 */
int IsPrivateAddr(unsigned int addr_in_netorder)
{
    unsigned int addr_in_hostorder;
    unsigned char a, b;

    addr_in_hostorder = ((addr_in_netorder >> 24) & 0xff) | ((addr_in_netorder >> 8) & 0xff00) | ((addr_in_netorder << 8) & 0xff0000) | ((addr_in_netorder << 24) & 0xff000000);
    a = (addr_in_hostorder & 0xff000000) >> 24;
    b = (addr_in_hostorder & 0xff0000) >> 16;
    if (a == 10)
        return 1;
    if (a == 172 && b >= 16 && b <= 31)
        return 1;
    if (a == 192 && b == 168)
        return 1;
    return 0;
}


int DWCi_NNStartupAsync(int isQR2, int cookie, DWCstNodeInfo * node)
{
    u32 senddata[2];
    int nnValid;
    int nnError = 0;
    int result;

    NNCancel(DWCi_GetMatchCnt()->nnInfo.cookie);

    if (isQR2 == 0) {
        cookie = (DWCi_GetMatchCnt()->profileID & 0xffff) |
                 (DWCi_GetMatchCnt()->nnCookieSeed << 16);
        if (node->hasPrivateAddress != 0) {
            if (node->publicInetAddress != ServerBrowserGetMyPublicIPAddr(DWCi_GetMatchCnt()->sbObj)) {
                nnValid = 1;
            } else {
                node->gt2IP = node->privateInetAddress;
                node->gt2Port = node->privateQueryPort;
                nnValid = 0;
            }
        } else {
            if (IsPrivateAddr(SOC_GetHostID())) {
                nnValid = 1;
            } else {
                node->gt2IP = node->publicInetAddress;
                node->gt2Port = node->publicQueryPort;
                nnValid = 0;
            }
        }
        if (nnValid) {
            DWCi_GetMatchCnt()->nnCookieSeed = DWCi_GetMathRand32(0x10000);
            DWCi_GetMatchCnt()->nnInfo.cookie = cookie;
        } else {
            senddata[0] = SOC_GetHostID();
            senddata[1] = gt2GetLocalPort(*DWCi_GetMatchCnt()->pGt2Socket);
            result = DWCi_SendMatchCommand(6, node->profileID, node->publicInetAddress, node->publicQueryPort, senddata, 2);
            DWCi_GetMatchCnt()->cmdCnt.count = 0;
            if (result != 0)
                return 2;
            DWCi_GetMatchCnt()->nnInfo.cookie = 0;
        }
        DWCi_GetMatchCnt()->nnInfo.clientindex = 0;
        DWCi_GetMatchCnt()->nnInfo.retryCount = 0;
        DWCi_GetMatchCnt()->nnInfo.port = node->publicQueryPort;
        DWCi_GetMatchCnt()->nnInfo.ip = node->publicInetAddress;
    } else {
        DWCi_GetMatchCnt()->nnInfo.clientindex = 1;
        DWCi_GetMatchCnt()->nnInfo.retryCount = 0;
        DWCi_GetMatchCnt()->nnInfo.port = 0;
        DWCi_GetMatchCnt()->nnInfo.ip = 0;
        DWCi_GetMatchCnt()->nnInfo.cookie = cookie;
        nnValid = 1;
    }

    if (nnValid) {
        nnError = DWCi_DoNatNegotiationAsync(&DWCi_GetMatchCnt()->nnInfo);
    } else {
        DWCstMatchControl * cnt;

        DWCi_NNCompletedCallback(0, gt2GetSocketSOCKET(*DWCi_GetMatchCnt()->pGt2Socket), 0,
                                 &DWCi_GetMatchCnt()->nnInfo);
        cnt = DWCi_GetMatchCnt();
        cnt->nnFinishTime = 0;
    }
    return nnError;
}


/*
 * sdk:      DWCi_DoNatNegotiationAsync (dwc_match.o)
 *
 * notes:    closed (w5_nm): the progress-callback pointer 0x02174FE4 (bx lr leaf,
 *           DWCi_NNProgressCallback) now has a seed, a catalog row and a stub
 *           (src/matched/ov_sdk/ov009_func_02174FE4.c), so it attests as sdk.
 */
int DWCi_DoNatNegotiationAsync(DWCstNNInfo *nnInfo)
{
    int i;
    int nnError;
    int sbError;

    if (nnInfo->clientindex == 0) {
        sbError = func_0219EF60((struct ServerBrowser *)(*(int *)((char *)DWCi_GetMatchCnt() + 0x5e0)), func_02198620(nnInfo->ip, 0, 0), nnInfo->port, nnInfo->cookie);
        if (DWCi_HandleSBError(sbError))
            return 2;
    }
    for (i = 0; i < 1; i++) {
        nnError = func_02199DFC(gt2GetSocketSOCKET((void *)(**(int **)((char *)DWCi_GetMatchCnt() + 4))), nnInfo->cookie, nnInfo->clientindex, DWCi_NNProgressCallback, func_02174FE8, nnInfo);
        if (nnError == 0)
            return nnError;
        if (nnError != 3)
            return nnError;
    }
    return nnError;
}


/*
 * Whether a profile id has both a gt2 connection and a node record.
 */
int DWCi_CanSendMatchCommandDirect(unsigned char command, int pid)
{
    int r = 1;

    if (DWCi_GetGT2ConnectionByProfileID(pid, r) == 0) {
        return 0;
    }
    if (DWCi_NodeInfoList_GetNodeInfoForProfileID(pid) == 0) {
        r = 0;
    }
    return r;
}


/*
 * DWCi_SendMatchCommand: sends a match command over gt2, as a GP buddy message, or through the server browser.
 */
int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    char buf[0x200];
    unsigned char *node;
    int result;
    int n;
    unsigned long long t;

    if (DWCi_CanSendMatchCommandDirect(command, pid) != 0) {
        node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForProfileID(pid);
        DWCi_EncodeBinaryMsgCommand((struct DWCstBinaryMessage *)(&ctrl), command, (unsigned int *)data, len);
        func_02177848(DWC_GetMyAID(), node[0x16], &ctrl, ctrl.len + 0x14, 0);
        result = 0;
    } else if (func_021861A8(*(void **)DWCi_GetMatchCnt(), pid) != 0) {
        n = 0;
        if (data != 0 && len != 0) {
            n = DWC_Base64Encode(data, len * 4, buf, 0x200);
        }
        buf[n] = 0;
        result = DWCi_SendGPBuddyMsgCommand(*(void **)DWCi_GetMatchCnt(), command, pid, buf);
    } else {
        if (ip == 0) {
            node = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForProfileID(pid);
            port = *(unsigned short *)(node + 0xc);
            ip = *(unsigned int *)(node + 4);
        }
        result = DWCi_SendSBMsgCommand(command, ip, port, data, len);
    }
    if (command == 2 || command == 6 || command == 8 || command == 9) {
        *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x6d8) = command;
        *(unsigned short *)((char *)DWCi_GetMatchCnt() + 0x6da) = port;
        *(unsigned int *)((char *)DWCi_GetMatchCnt() + 0x6dc) = ip;
        *(int *)((char *)DWCi_GetMatchCnt() + 0x760) = pid;
        *(int *)((char *)DWCi_GetMatchCnt() + 0x764) = len;
        t = OS_GetTick();
        *(unsigned long long *)((char *)DWCi_GetMatchCnt() + 0x768) = t;
        if (data != 0 && len != 0) {
            MIi_CpuCopy32(data, (char *)DWCi_GetMatchCnt() + 0x6e0, len * 4);
        }
    }
    return result;
}


/*
 * sdk:      DWCi_EncodeBinaryMsgCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * The 5-byte identifier copy is an inlined `strcpy` of the 4-character
 * keyword literal (vendor template @24369 at 0x021A2188) into the 4-byte
 * identifier; the version word at +4 then overwrites the NUL. Spelling it as a
 * struct copy from an extern gave the same instructions with the pool base in
 * r0 instead of ip (20 B); through strcpy the registers match.
 */
void DWCi_EncodeBinaryMsgCommand(DWCstBinaryMessage *message, unsigned char command, unsigned int *data, int len)
{
    if (data == 0 || len == 0) {
        len = 0;
    } else {
        MIi_CpuCopy32(data, message->data, len * 4);
    }
    strcpy(message->header.identifier, "\xbbI\xccM");
    message->header.version = 0x5a;
    message->header.command = command;
    message->header.size = len * 4;
    message->header.qr2Port = *(unsigned short *)((char *)DWCi_GetMatchCnt() + 0x5d4);
    message->header.qr2IP = *(unsigned int *)((char *)DWCi_GetMatchCnt() + 0x5d8);
    message->header.profileID = *(int *)((char *)DWCi_GetMatchCnt() + 0x678);
}


/*
 * Sends a match command to a host through the server browser.
 */
int DWCi_SendSBMsgCommand(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    int i;
    int res;

    DWCi_EncodeBinaryMsgCommand((struct DWCstBinaryMessage *)(&ctrl), command, (unsigned int *)data, len);
    for (i = 0; i < 1; i++) {
        res = func_0219EF08(*(void **)((char *)DWCi_GetMatchCnt() + 0x5e0), func_02198620(ip, 0, 0), port, (char *)(&ctrl), ctrl.len + 0x14);
        if (res == 0) {
            return res;
        }
        if (res != 2) {
            return res;
        }
    }
    return res;
}


/*
 * Sends a match command to a buddy as a GP buddy message.
 */
int DWCi_SendGPBuddyMsgCommand(void *conn, unsigned char command, int pid, const char *data)
{
    char msg[0x200];
    char *p;
    int len;

    len = OS_SNPrintf(msg, 0x200, d_021A2190, d_021A2198, 0x5a, d_021A21A0);
    msg[len] = command;
    p = msg + 1;
    p[len] = 0;
    p += len;
    if (data != 0) {
        len = func_0209477C((const u8 *)data);
        MI_CpuCopy8(data, p, len);
        p[len] = 0;
    }
    return func_021864CC(conn, pid, msg);
}


/* SDK inlines (calls in the Debug build of dwc_match.o, inlined in Rom):
 * the tick is read before DWCi_GetMatchCnt, as `MC()->x = DWCi_Np_GetTick()`
 * inlines; DWCi_LEtoHl is the identity on the DS */
static inline u32 DWCi_LEtoHl(u32 x) { return x; }


static inline u64 DWCi_Np_GetTick(void) { return OS_GetTick(); }


/*
 * sdk:      DWCi_ProcessRecvMatchCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * 2026-10-01 (ov SDK wave 2, lane 03): full rewrite from the vendor listing
 *   and DWARF.  Compiles to the full 4396 bytes, 228/228 relocations, every
 *   branch target and frame offset right; 1089 of 1099 instructions identical.
 *   What it took: the jump table starts at index 0 (the old header numbered
 *   cases from 1, so every case was off by one); `case 0x41: break;` gives
 *   the 0x53 pivot; OS_GetTick stores need a u64 temp (call before
 *   DWCi_GetMatchCnt); data[] loads the image does before a GetMatchCnt call
 *   need their own statement; `result = MC()->field; if (result == x)` gives
 *   the field-first cmp (cases 2 and 16); in case 2 data_idx = 1 goes after
 *   MI_CpuFill8 (the early `mov sl,#1` is a pooled constant) and data[11]
 *   lives in the u32 `ip`.
 * residue: case 0x52 only (10 instructions, register names only): the image
 *   gives the pooled constant 1 r6 and bAck r7, we give r7/r6.  Inert:
 *   bAck type/name/scope/initialiser/inner block, every top-level var as
 *   bAck, idx type, ternary spellings (!!, != 0, == 0 ? 0 : 1, ? 1 : bAck),
 *   shift spellings (1U, (u32)1, inline helper), result binding, nested if,
 *   self-assignments at all 12 statement boundaries, empty DWC_Printf
 *   remnants, sendCommand temp.  A standalone micro-repro gives the same
 *   order, so the vendor shape differs in something not visible here.
 * 2026-10-01 (w3 lane24): still 12 B.  SET_TICK's u64 `tick` locals are not
 *   in the vendor DWARF; replaced by inline setters taking the tick (same
 *   bytes, DWARF closer).  Our -g DWARF vs vendor: bAck is r6 here, r0 there;
 *   `bAck = DWCi_IsBackupMine()` reproduces r0 but not the colours.  New
 *   inert spellings: idx/bAck declaration swap, unprototyped GetAID (vendor
 *   DWARF gives it one parameter, yet r1 = 1 is passed), embedded
 *   `GetNodeInfoForIndex(bAck = 0)`, a top-level local holding the 1 (all
 *   eight), `||`-merged early returns (653 B), bAck types incl. long/u64,
 *   `register`, dsi 1.1/1.2/1.2p1/1.2p2/1.3 (all 12 B).  Micro-repro finding:
 *   1.1p1 always colours the user variable bAck before the select temp that
 *   coalesces with the pooled 1 (a `? 2 : 0` or if-statement form puts the
 *   bare constant first); the image orders {1, temp} first.  Read as the
 *   4.0.0.1025 allocator tie (see the 0217D280 / 021D3638 idioms).
 * 2026-10-01 (w4): EXACT.  The Debug build (sdk/TwlDWC/lib/ARM9-TS/Debug,
 *   -O0, non-inlined) of dwc_match.o gives the case 0x52 source: an
 *   `if (srcPid != ...) bAck = FALSE; else bAck = (... & (1 << idx)) != 0;`
 *   pair (the -O0 code is the same for `!= 0` and `? 1 : 0`); at -O4 that
 *   if/else with `!= 0` colours the pooled 1 before bAck.  Neither half alone
 *   moves it (`!= 0` was inert with `bAck = 0; if (==)`).  Also from the Debug
 *   object: the dead `serverAidBitmap = DWCi_LEtoHl(data[0])` local, the
 *   separate `result = DWCi_SendMatchCommand(...)` statement, and the
 *   DWCi_Np_GetTick inline (all byte-neutral, kept for source fidelity).
 */
int DWCi_ProcessRecvMatchCommand(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len)
{
    u8 sendCommand;
    u8 aid;
    u16 port;
    u32 ip;
    u32 senddata[65];
    int profileID;
    int sendlen = 0;
    int result;
    int i;
    int nnError;
    SOCSockAddrIn remoteaddr;

    if (MC() == NULL || MC()->state == 0)
        return 1;

    if (DWC_GetState() == 4 && MC()->state == 1 &&
        DWCi_NodeInfoList_GetCount() > 0 &&
        srcPid == DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID)
        DWCi_InitClWaitTimeout();

    switch (command) {
    case 1: {
        DWCstNodeInfo peerNodeInfo;
        DWCstNodeInfo *pMyNodeInfo;
        int peerConnectGroupID;
        int meshReserve;
        DWCstNodeInfo *pNodeInfo;
        u32 matchType;
        u32 topologyType;

        meshReserve = 0;
        matchType = data[0];
        MI_CpuFill8(&peerNodeInfo, 0, sizeof(DWCstNodeInfo));
        peerNodeInfo.aid = 0xff;
        peerNodeInfo.profileID = srcPid;
        peerNodeInfo.publicInetAddress = data[1];
        peerNodeInfo.publicQueryPort = (u16)data[2];
        peerNodeInfo.privateInetAddress = data[3];
        peerNodeInfo.privateQueryPort = (u16)data[4];
        peerNodeInfo.hasPrivateAddress = (u8)data[5];
        peerConnectGroupID = (int)data[6];
        topologyType = data[7];
        memcpy(peerNodeInfo.connUserData, &data[8], 4);
        profileID = (int)data[9];
        if (len >= 11 && data[10] == 1)
            meshReserve = 1;

        sendCommand = DWCi_CheckResvCommand(peerNodeInfo.profileID, peerNodeInfo.publicInetAddress,
                                            peerNodeInfo.publicQueryPort, matchType,
                                            peerConnectGroupID ? 1 : 0, topologyType,
                                            peerNodeInfo.connUserData, meshReserve);
        if (sendCommand == 2) {
            DWCi_TempNewNodeInfo_Clear();
            MC()->tempNewNodeInfo = peerNodeInfo;
            if (DWCi_HandleMatchCommandError(((int (*)(int, unsigned int, unsigned short))DWCi_ProcessResvOK)(srcPid, srcIP, srcPort)))
                return 0;
            if (MC()->inMeshMaking) {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(MC()->tempNewNodeInfo.profileID);
                MC()->tempNewNodeInfo.aid = pNodeInfo->aid;
            }
            if (MC()->inMeshMaking == 0 && MC()->qr2MatchType == 2 && MC()->state != 0xe &&
                ((MC()->qr2MatchTypeExt != 0 && MC()->qr2MatchTypeExt != 1) || MC()->connectionEstablished) &&
                MC()->newClientCallback != NULL)
                MC()->newClientCallback(DWCi_GetFriendListIndex(srcPid), MC()->newClientParam);
            pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
            sendlen = 0;
            senddata[sendlen++] = MC()->qr2NumEntry;
            senddata[sendlen++] = pMyNodeInfo->aid;
            senddata[sendlen++] = pMyNodeInfo->profileID;
            senddata[sendlen++] = pMyNodeInfo->publicInetAddress;
            senddata[sendlen++] = pMyNodeInfo->publicQueryPort;
            senddata[sendlen++] = pMyNodeInfo->privateInetAddress;
            senddata[sendlen++] = pMyNodeInfo->privateQueryPort;
            senddata[sendlen++] = pMyNodeInfo->hasPrivateAddress;
            senddata[sendlen++] = *(u32 *)pMyNodeInfo->connUserData;
            senddata[sendlen++] = MC()->groupID;
            senddata[sendlen++] = MC()->tempNewNodeInfo.aid;
            senddata[sendlen++] = profileID;
            senddata[sendlen++] = DWCi_NodeInfoList_GetCount();
            senddata[sendlen++] = MC()->inMeshMaking ? 1 : 0;
            MC();
            DWCi_SetMatchStatus(0xe);
        } else if (sendCommand == 3) {
            DWCi_GetResvDenyReasonString(MC()->denyReason);
            senddata[0] = MC()->denyReason;
            sendlen = 1;
        }
        if (sendCommand != 0xff) {
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(sendCommand, peerNodeInfo.profileID,
                                                                   peerNodeInfo.publicInetAddress,
                                                                   peerNodeInfo.publicQueryPort,
                                                                   senddata, sendlen)))
                return 0;
        }
        break;
    }
    case 2: {
        DWCstNodeInfo peerNodeInfo;
        DWCstNodeInfo *pMyNodeInfo;
        u8 data_idx;
        profileID = data[0];
        if (MC()->state != 3)
            break;
        if (srcPid != MC()->reqProfileID || srcPid != (int)data[2])
            break;
        ip = (int)data[11];
        result = MC()->connectNonce;
        if (result != ip)
            break;
        if (len >= 14) {
            ip = data[13] == 1 ? 1 : 0;
            if (ip != MC()->inMeshMaking)
                break;
        }
        MC()->replyWaiting = 0;
        MC()->cmdTimeoutTime = 0;
        MC()->cmdResendFlag = 0;
        MI_CpuFill8(&peerNodeInfo, 0, sizeof(DWCstNodeInfo));
        data_idx = 1;
        peerNodeInfo.aid = (u8)data[data_idx++];
        peerNodeInfo.profileID = (int)data[data_idx++];
        peerNodeInfo.publicInetAddress = data[data_idx++];
        peerNodeInfo.publicQueryPort = (u16)data[data_idx++];
        peerNodeInfo.privateInetAddress = data[data_idx++];
        peerNodeInfo.privateQueryPort = (u16)data[data_idx++];
        peerNodeInfo.hasPrivateAddress = (u8)data[data_idx++];
        memcpy(peerNodeInfo.connUserData, &data[data_idx++], 4);
        ip = data[data_idx++];
        if (MC()->inMeshMaking == 0)
            DWCi_NodeInfoList_GetMyNodeInfo()->aid = (u8)data[data_idx++];
        MC()->tempNewNodeInfo = peerNodeInfo;
        if (MC()->qr2MatchType == 3) {
            MC()->groupID = ip;
            MC()->qr2NumEntry = (u8)profileID;
        }
        if (MC()->qr2MatchTypeExt == 1 && MC()->evalCallback && MC()->inMeshMaking == 0 && MC()->connectGroupID == 0) {
            int sbError;

            DWCi_SetMatchStatus(4);
            sbError = DWCi_SBUpdateAsync(srcPid);
            if (DWCi_HandleSBError(sbError))
                return 0;
        } else {
            DWCi_SetMatchStatus(5);
            ip = DWCi_NNStartupAsync(0, 0, &MC()->tempNewNodeInfo);
            if (DWCi_HandleNNError(ip))
                return 0;
        }
        break;
    }
    case 3: {
        u32 reason;

        if (MC()->state != 3)
            break;
        if (srcPid != MC()->reqProfileID)
            break;
        reason = data[0];
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->connectGroupID || MC()->qr2MatchTypeExt == 3) {
            int error;

            error = reason != 0x10 ? 0x15 : 0xc;
            DWCi_StopMatch(error, 0);
            return 0;
        }
        return DWCi_RetryReserving(MC()->reqProfileID);
    }
    case 4:
        if (MC()->state != 3)
            break;
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->connectGroupID) {
            if (srcPid != MC()->reqProfileID)
                break;
            if (!gpIsBuddy(MC()->pGpObj, srcPid))
                break;
            MC()->retryCountMax = 1;
            MC()->scResvRetryCount = 0;
            MC()->cmdTimeoutTime = 12000;
            MC()->cmdTimeoutStartTick = DWCi_Np_GetTick();
        } else {
            if (srcPid != MC()->reqProfileID)
                break;
            MC()->cmdTimeoutStartTick = DWCi_Np_GetTick();
            MC()->replyWaiting = 0;
            if (MC()->qr2MatchTypeExt == 0) {
                DWCi_TempNewNodeInfo_Clear();
                DWCi_SetMatchStatus(2);
                MC()->sbUpdateFlag = 1;
                MC()->sbUpdateTick = DWCi_Np_GetTick();
            } else if (MC()->qr2MatchTypeExt == 1) {
                DWCi_TempNewNodeInfo_Clear();
                DWCi_SendResvCommandToFriend(1, 0, 0);
            } else if (MC()->qr2MatchTypeExt == 3) {
                MC()->retryCountMax = 1;
                MC()->scResvRetryCount = 0;
                MC()->cmdTimeoutTime = 12000;
                MC()->cmdTimeoutStartTick = DWCi_Np_GetTick();
            }
        }
        break;
    case 5:
        if (MC()->qr2Flag18 == 0)
            break;
        if (srcPid != MC()->serverProfileID)
            break;
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->qr2MatchType == 2 && DWCi_TempNewNodeInfo_IsValid() == 1 &&
            DWCi_GetGT2ConnectionByProfileID(MC()->tempNewNodeInfo.profileID, 0) &&
            srcPid == MC()->tempNewNodeInfo.profileID)
            gt2CloseAllConnectionsHard(*MC()->pGt2Socket);
        if (!DWCi_CancelPreConnectedServerProcess(srcPid))
            return 0;
        break;
    case 6:
        ip = data[0];
        port = (u16)data[1];
        if (!DWCi_TempNewNodeInfo_IsValid())
            break;
        if (!DWCi_IsFullMesh() && MC()->qr2MatchType == 3 && MC()->inMeshMaking == 0)
            break;
        if (MC()->state == 1) {
            DWCi_SetMatchStatus(5);
        } else {
            if (MC()->state != 5 && MC()->state != 0xe)
                break;
            if (srcPid != MC()->serverProfileID)
                break;
        }
        MC()->cmdCnt.command = 0xff;
        remoteaddr.addr.addr = ip;
        remoteaddr.port = SOC_HtoNs(port);
        MC()->nnInfo.clientindex = 1;
        DWCi_NNCompletedCallback(0, gt2GetSocketSOCKET(*MC()->pGt2Socket), &remoteaddr, &MC()->nnInfo);
        MC()->nnFinishTime = 0;
        break;
    case 7:
        if (DWCi_StopMeshMaking() == 1)
            DWCi_SetMatchStatus(1);
        if (MC()->state != 1)
            break;
        if (srcPid != DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID)
            break;
        profileID = (int)data[0];
        aid = (u8)data[1];
        if (MC()->tempNewClientInfo.profileID)
            break;
        MC()->serverDownBuff = 0;
        if (DWCi_IsFullMesh()) {
            MC()->tempNewNodeInfo.profileID = profileID;
            MC()->tempNewNodeInfo.aid = aid;
        } else {
            MC()->tempNewClientInfo.profileID = profileID;
        }
        if (MC()->newClientCallback != NULL)
            MC()->newClientCallback(DWCi_GetFriendListIndex(profileID), MC()->newClientParam);
        break;
    case 9: {
        DWCstNodeInfo *nodeInfo;

        nodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(DWCi_GetGT2NumConnection() - 1 - MC()->linkProgress);
        if (MC()->state != 0x10)
            break;
        if (nodeInfo == NULL || nodeInfo->profileID != (int)data[0])
            break;
        MC()->linkProgress++;
        DWCi_PostProcessConnection(0);
        break;
    }
    case 8: {
        DWCstNodeInfo *tmpNode;
        u32 senddata1[1];

        if (MC()->state != 1)
            break;
        if (srcPid != MC()->tempNewNodeInfo.profileID)
            break;
        profileID = (int)data[0];
        tmpNode = &MC()->tempNewNodeInfo;
        aid = (u8)data[2];
        if (DWCi_GetGT2Connection(aid)) {
            senddata1[0] = (u32)profileID;
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(9, srcPid, tmpNode->publicInetAddress,
                                                                   tmpNode->publicQueryPort,
                                                                   senddata1, 1)))
                return 0;
        } else {
            MC()->tempNewClientInfo = MC()->tempNewNodeInfo;
            tmpNode->profileID = profileID;
            tmpNode->aid = aid;
            tmpNode->publicInetAddress = data[3];
            tmpNode->publicQueryPort = (u16)data[4];
            tmpNode->privateInetAddress = data[5];
            tmpNode->privateQueryPort = (u16)data[6];
            tmpNode->hasPrivateAddress = (u8)data[7];
            memcpy(tmpNode->connUserData, &data[8], 4);
            DWCi_SetMatchStatus(5);
            MC()->cmdTimeoutTime = 0;
            MC()->cmdResendFlag = 0;
            DWCi_NNStartupAsync(0, 0, tmpNode);
        }
        break;
    }
    case 10:
        if (MC()->state != 1)
            break;
        if (srcPid != DWCi_NodeInfoList_GetServerNodeInfo()->profileID)
            break;
        profileID = (int)data[0];
        aid = (u8)data[1];
        if (profileID != MC()->tempNewNodeInfo.profileID || aid != MC()->tempNewNodeInfo.aid) {
            MC()->tempNewNodeInfo.aid = aid;
            MC()->tempNewNodeInfo.profileID = profileID;
        }
        break;
    case 12:
        if (srcPid != MC()->tempNewNodeInfo.profileID)
            break;
        if (MC()->qr2MatchTypeExt == 0 || MC()->qr2MatchTypeExt == 1) {
            if (!((int (*)(int))DWCi_CancelPreConnectedClientProcess)(srcPid))
                return 0;
        } else if (MC()->qr2MatchType == 3) {
            MC()->peerProfileID = srcPid;
            DWCi_CloseAllConnectionsByTimeout();
            DWCi_RestartFromCancel(0);
        }
        break;
    case 13:
    case 14:
    case 15:
        if (!DWCi_ProcessCancelMatchSynCommand(srcPid, command, data[0]))
            return 0;
        break;
    case 16: {
        DWCstNodeInfo *pNodeInfo;
        u8 beforeCloseState;

        pNodeInfo = DWCi_NodeInfoList_GetServerNodeInfo();
        if (pNodeInfo == NULL)
            return 1;
        if (srcPid != pNodeInfo->profileID)
            return 1;
        beforeCloseState = MC()->closeState;
        MC()->closeState = 1;
        for (i = 0; i < len; i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID((int)data[i]);
            if (pNodeInfo == NULL) {
                profileID = (int)data[i];
                result = MC()->tempNewClientInfo.profileID;
                if (result == profileID) {
                    DWCi_CloseConnectionHard(MC()->tempNewClientInfo.aid);
                    MC()->tempNewClientInfo.profileID = 0;
                    continue;
                }
            }
            if (pNodeInfo != NULL)
                DWCi_CloseConnectionHard(pNodeInfo->aid);
        }
        MC()->closeState = beforeCloseState;
        break;
    }
    case 0x40:
        if (!DWCi_TempNewNodeInfo_IsValid())
            break;
        if (srcPid != MC()->tempNewNodeInfo.profileID)
            break;
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x41, srcPid, srcIP, srcPort, NULL, 0)))
            return 0;
        break;
    case 0x41:
        break;
    case 0x52: {
        u32 serverAidBitmap;
        u8 idx;
        int bAck;

        if (!MC()->connectionEstablished)
            break;
        if (DWCi_IsBackupMine())
            return 0;
        idx = DWCi_GetAIDFromProfileID(MC()->profileID, 1);
        if (idx == 0xff)
            return 0;
        if (DWCi_GetAIDFromProfileID(srcPid, 1) == 0xff)
            return 0;
        serverAidBitmap = DWCi_LEtoHl(data[0]);
        if (srcPid != DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID) {
            bAck = 0;
        } else {
            bAck = (MC()->serverDownBuff & (1 << idx)) != 0;
        }
        result = DWCi_SendMatchCommand(bAck ? 0x53 : 0x54, srcPid, srcIP, srcPort, NULL, 0);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
        MC()->clWaitTime = DWCi_Np_GetTick();
        if (bAck && MC()->state == 0xa) {
            DWCi_SetMatchStatus(1);
            DWCi_ResetLastSomeDataRecvTimeByAidAll();
        }
        break;
    }
    case 0x53: {
        u8 idx;

        if (!MC()->connectionEstablished)
            break;
        if (!DWCi_IsBackupMine())
            break;
        idx = DWCi_GetAIDFromProfileID(srcPid, 1);
        if (idx == 0xff)
            return 0;
        MC()->serverDownBuff |= 1 << idx;
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x53, srcPid, srcIP, srcPort, NULL, 0)))
            return 0;
        break;
    }
    case 0x54:
        if (!MC()->connectionEstablished)
            break;
        i = DWCi_NodeInfoList_GetCount();
        if (++MC()->serverDownNakCount > i * 5)
            DWC_CloseAllConnectionsHard();
        else
            MC()->clWaitTime = DWCi_Np_GetTick();
        break;
    case 0x55:
        MC();
        break;
    case 0x70:
        DWCi_SBUpdateAsync(0);
        DWCi_InitClWaitTimeout();
        DWCi_SetMatchStatus(0xc);
        break;
    case 0x82: {
        u8 fromSV;
        u8 suspend;
        u8 AID;

        fromSV = (u8)data[1];
        suspend = (u8)data[2];
        if (DWCi_NodeInfoList_GetNodeInfoForProfileID((int)data[0]) == NULL)
            break;
        if (DWCi_GetHostStatus() == 2) {
            AID = (u8)data[3];
            if (fromSV != 1)
                DWCi_ProcessRequestMatch(AID, suspend, 1);
        } else if (DWCi_GetHostStatus() == 1) {
            if (fromSV == 0)
                break;
            if (len == 2) {
                if (MC()->suspendReqPending == 1)
                    break;
                MC()->suspendReqPending = 1;
                MC()->suspendRetryDelayMs = 8000;
                MC()->suspendRequestTick = DWCi_Np_GetTick();
            } else {
                MC()->suspendReqPending = 1;
                ip = data[3];
                MC()->suspendBitmap = ip;
            }
        }
        break;
    }
    case 0x83:
        DWCi_ProcessMatchPollingPacket((const Poll *)data);
        break;
    }
    return 1;
}


/*
 * sdk:      DWCi_CheckResvCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
u8 DWCi_CheckResvCommand(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve)
{
    DWCstNodeInfo *pMyNodeInfo;
    u8 sendCommand;
    u64 tick;

    ((DWCstMatchControl *)DWCi_GetMatchCnt())->denyReason = 1;
    switch (DWCi_GetHostStatus()) {
    case 1:
        if (DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(profileID)) {
            if (((DWCstMatchControl *)DWCi_GetMatchCnt())->inMeshMaking == 0) {
                if (((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 1) {
                    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewClientInfo.profileID != 0) {
                        sendCommand = 4;
                    } else {
                        ((DWCstMatchControl *)DWCi_GetMatchCnt())->inMeshMaking = 1;
                        DWCi_ClearMeshMakingTempInfo();
                        goto send;
                    }
                } else {
                    sendCommand = 4;
                }
            } else {
                if (((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 3) {
                    pMyNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetMyNodeInfo();
                    if (profileID == ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.profileID) {
                        if (pMyNodeInfo->profileID >= profileID) {
                            sendCommand = 0xff;
                        } else {
                        send:
                            sendCommand = 2;
                            tick = func_020870D0();
                            ((DWCstMatchControl *)DWCi_GetMatchCnt())->cmdCnt.sendTime = tick;
                        }
                    } else {
                        sendCommand = 4;
                    }
                } else {
                    sendCommand = 4;
                }
            }
        } else {
            sendCommand = 3;
            ((DWCstMatchControl *)DWCi_GetMatchCnt())->denyReason = 0x14;
        }
        break;
    case 0:
    case 2:
        sendCommand = func_02171524(profileID, qr2IP, qr2Port, matchType, connectGroupID, topologyType, newClientUserData, meshReserve);
        break;
    }
    return sendCommand;
}


unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port,
                                        u32 matchType, int connectGroupID,
                                        u32 topologyType,
                                        unsigned char *newClientUserData,
                                        int meshReserve)
{
    unsigned char sendCommand;

    if (DWCi_IsServerLocked() != 0) {
        DWCi_GetMatchCnt()->denyReason = 0x13;
        return 3;
    }
    if (meshReserve != 0) {
        DWCi_GetMatchCnt()->denyReason = 0x18;
        return 3;
    }
    if (connectGroupID != 0)
        goto main;

    if ((matchType == 0 && DWCi_GetMatchCnt()->qr2MatchTypeExt != 0) ||
        (matchType == 1 && DWCi_GetMatchCnt()->qr2MatchTypeExt != 1) ||
        (matchType == 3 && DWCi_GetMatchCnt()->qr2MatchTypeExt != 2)) {
        DWCi_GetMatchCnt()->denyReason = 0x12;
        return 3;
    }

    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID) != 0) {
            if (DWCi_GetFriendListIndex(profileID) != -1)
                goto isfriend;
        }
        return 0xff;
    isfriend:
        if (DWCi_IsFriendByIdxList(profileID) != 0)
            goto main;
        DWCi_GetMatchCnt()->denyReason = 0x15;
        return 3;
    }
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID) != 0) {
            if (DWCi_GetFriendListIndex(profileID) != -1)
                goto main;
        }
        return 0xff;
    }

main:
    if (DWCi_GetMatchCnt()->qr2NumEntry + 1 == DWCi_GetNumEntry()) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->denyReason = 0x10;
        goto done;
    }
    if (DWCi_GetMatchCnt()->state == 0x16) {
        sendCommand = 4;
        goto done;
    }
    if (DWC_GetSuspendMatch() != 0 || DWCi_GetMatchCnt()->suspendActive != 0) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->denyReason = 0x11;
        goto done;
    }
    if (topologyType != DWCi_GetMatchCnt()->topologyType) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->denyReason = 0x12;
        goto done;
    }
    if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID) != 0) {
        sendCommand = 0xff;
        goto done;
    }
    if (DWCi_GetMatchCnt()->state == 0xd ||
        DWCi_GetMatchCnt()->state == 2 ||
        DWCi_GetMatchCnt()->state == 3) {
        if ((DWCi_GetMatchCnt()->qr2IP != 0 || DWCi_GetMatchCnt()->qr2Port != 0) &&
            (qr2IP != 0 || qr2Port != 0))
            goto lookup;
    }
    if (DWCi_GetMatchCnt()->state == 0xe &&
        profileID == DWCi_GetMatchCnt()->serverProfileID) {
        sendCommand = 0xff;
        goto done;
    }
    sendCommand = 4;
    goto done;

lookup:
    if (DWCi_GetMatchCnt()->qr2MatchType != 2 &&
        DWCi_GetMatchCnt()->reqProfileID != 0) {
        if (profileID == DWCi_GetMatchCnt()->reqProfileID) {
            if (DWCi_GetMatchCnt()->profileID < profileID)
                sendCommand = 2;
            else
                sendCommand = 0xff;
        } else {
            sendCommand = 3;
            DWCi_GetMatchCnt()->denyReason = 0x17;
        }
        goto done;
    }
    sendCommand = 2;
    goto done;

done:
    if (sendCommand == 2) {
        if (DWCi_GetMatchCnt()->attemptCallback != 0) {
            if (DWCi_GetMatchCnt()->attemptCallback(newClientUserData, DWCi_GetMatchCnt()->attemptParam) == 0) {
                DWCi_GetMatchCnt()->denyReason = 0x16;
                return 3;
            }
        }
        if (DWCi_GetHostStatus() == 0)
            DWCi_SetupGameServer_InterChange(1);
    }
    return sendCommand;

err12:
    DWCi_GetMatchCnt()->denyReason = 0x12;
    return 3;
}


/*
 * sdk:      DWCi_ProcessResvOK (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_ProcessResvOK(int profileID)
{
    u32 senddata[16];
    int result;
    int i;
    u8 aid;
    DWCstNodeInfo *pMyNodeInfo;
    DWCstNodeInfo *pNodeInfo;

    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Flag18 != 0 && profileID == ((DWCstMatchControl *)DWCi_GetMatchCnt())->serverProfileID)
        return 0;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Flag18 = 1;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->serverProfileID = profileID;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->cmdResendFlag = 0;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->cmdTimeoutTime = 0;
    qr2_send_statechanged(((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Obj);
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->reqProfileID = 0;
    aid = DWCi_NodeInfoList_GetFreeAID();
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.aid = aid;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->inMeshMaking == 0) {
        senddata[0] = ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.profileID;
        senddata[1] = ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.aid;
        pMyNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetMyNodeInfo();
        for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            if (pMyNodeInfo->profileID != pNodeInfo->profileID) {
                result = DWCi_SendMatchCommand(7, pNodeInfo->profileID, pNodeInfo->publicInetAddress, pNodeInfo->publicQueryPort, (const unsigned int *)senddata, 2);
                if (result != 0)
                    return result;
            }
        }
    }
    return 0;
}


/*
 * DWCi_HandleMatchCommandError: dispatches to the server-browsing or command error handler.
 */
int DWCi_HandleMatchCommandError(int error)
{
    if (*(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x15) == 0) {
        return DWCi_HandleSBError(error);
    }
    return func_02173D28(error);
}


int DWCi_SendResvCommand(int profileID, int delay)
{
    u32 senddata[16];
    u32 remoteQR2ip = 0;
    u16 remoteQR2port = 0;
    DWCstNodeInfo * pMyNodeInfo;
    unsigned long long tick;
    int result;

    if (delay != 0)
        goto setTimer;
    if (DWCi_GetMatchCnt()->qr2IP != 0 || DWCi_GetMatchCnt()->qr2Port != 0)
        goto send;

setTimer:
    DWCi_GetMatchCnt()->cmdResendFlag = 1;
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->cmdResendTick = tick;
    DWCi_GetMatchCnt()->reqProfileID = 0;
    return 0;

send:
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0) {
        remoteQR2ip = DWCi_GetMatchCnt()->tempNewNodeInfo.publicInetAddress;
        remoteQR2port = DWCi_GetMatchCnt()->tempNewNodeInfo.publicQueryPort;
        DWCi_GetMatchCnt()->reqProfileID = profileID;
    } else {
        DWCi_GetMatchCnt()->reqProfileID = profileID;
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID) == 0) {
            remoteQR2ip = DWCi_GetMatchCnt()->tempNewNodeInfo.publicInetAddress;
            remoteQR2port = DWCi_GetMatchCnt()->tempNewNodeInfo.publicQueryPort;
        }
    }
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3 ||
        (DWCi_GetMatchCnt()->connectGroupID != 0 &&
         gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID))) {
        DWCi_GetMatchCnt()->retryCountMax = 0;
        DWCi_GetMatchCnt()->cmdTimeoutTime = 0x7530;
    } else {
        DWCi_GetMatchCnt()->retryCountMax = 5;
        DWCi_GetMatchCnt()->cmdTimeoutTime = 0x2ee0;
    }
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->cmdTimeoutStartTick = tick;
    DWCi_GetMatchCnt()->cmdResendFlag = 0;
    pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
    senddata[0] = DWCi_GetMatchCnt()->qr2MatchTypeExt;
    senddata[1] = pMyNodeInfo->publicInetAddress;
    senddata[2] = pMyNodeInfo->publicQueryPort;
    senddata[3] = pMyNodeInfo->privateInetAddress;
    senddata[4] = pMyNodeInfo->privateQueryPort;
    senddata[5] = pMyNodeInfo->hasPrivateAddress;
    senddata[6] = DWCi_GetMatchCnt()->connectGroupID;
    senddata[7] = DWCi_GetMatchCnt()->topologyType;
    senddata[8] = *(u32 *)DWCi_GetMatchCnt()->connUserData;
    DWCi_GetMatchCnt()->connectNonce = DWCi_GetMathRand32((u32)-2) + 1;
    senddata[9] = DWCi_GetMatchCnt()->connectNonce;
    senddata[10] = DWCi_GetMatchCnt()->inMeshMaking != 0;
    result = DWCi_SendMatchCommand(1, profileID, remoteQR2ip, remoteQR2port, senddata, 0xb);
    return result;
}


int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid)
{
    int found = 0;
    int profileID;
    int i;
    int gpResult;
    struct GPBuddyStatus status;
    int buddyIdx;
    unsigned long long tick;

    if (init == 0) {
        DWCi_GetMatchCnt()->connectCursor++;
        DWCi_GetMatchCnt()->connectCursor =
            DWCi_GetMatchCnt()->connectCursor % DWCi_GetMatchCnt()->friendListIndexCount;
    }
    DWCi_GetMatchCnt()->qr2MatchType = 3;
    i = 0;
    if (DWCi_GetMatchCnt()->friendListIndexCount > 0) {
        do {
            profileID = DWC_GetGsProfileId(
                DWCi_GetUserData(),
                DWCi_GetMatchCnt()->friendKeyList +
                    DWCi_GetMatchCnt()->friendListIndex[DWCi_GetMatchCnt()->connectCursor] * 12);
            if (profileID == 0 || profileID == -1)
                goto next;
            if (DWCi_Acc_IsValidFriendData(
                    DWCi_GetMatchCnt()->friendKeyList +
                    DWCi_GetMatchCnt()->friendListIndex[DWCi_GetMatchCnt()->connectCursor] * 12) == 0)
                goto next;
            if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID) != 0)
                goto next;
            gpResult = gpGetBuddyIndex(DWCi_GetMatchCnt()->pGpObj, profileID, &buddyIdx);
            gpResult |= gpGetBuddyStatus(DWCi_GetMatchCnt()->pGpObj, buddyIdx, &status);
            if (!(DWCi_IsLockedBuddyStatus((char *)(&status)) == 0 &&
                  gpResult == 0 && status.f4 == 4))
                goto next;
            found = 1;
            break;
        next:
            i++;
            DWCi_GetMatchCnt()->connectCursor =
                (i + DWCi_GetMatchCnt()->connectCursor) % DWCi_GetMatchCnt()->friendListIndexCount;
        } while (i < DWCi_GetMatchCnt()->friendListIndexCount);
    }
    if (found) {
        if (profileID == resendPid)
            delay = 1;
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt()->tempNewNodeInfo.aid = 0xff;
        DWCi_GetMatchCnt()->tempNewNodeInfo.profileID = profileID;
        return DWCi_SendResvCommand(profileID, delay);
    }
    DWCi_GetMatchCnt()->cmdTimeoutTime = 0xbb8;
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->cmdTimeoutStartTick = tick;
    DWCi_GetMatchCnt()->cmdResendFlag = 0;
    return 0;
}


/*
 * sdk:      DWCi_RetryReserving (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_RetryReserving(int resendPid)
{
    int result;
    int sbError;
    u64 tick;

    ((DWCstMatchControl *)DWCi_GetMatchCnt())->reqProfileID = 0;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->replyWaiting = 0;
    tick = func_020870D0();
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->cmdTimeoutStartTick = tick;
    DWCi_TempNewNodeInfo_Clear();
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->connectGroupID != 0) {
        DWCi_SetMatchStatus(0xc);
        sbError = DWCi_HandleSBError(DWCi_SBUpdateAsync(0));
        if (sbError != 0)
            return 0;
    } else if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchTypeExt == 0) {
        DWCi_SetMatchStatus(2);
        if (resendPid != 0) {
            ((DWCstMatchControl *)DWCi_GetMatchCnt())->sbUpdateFlag = 1;
            tick = func_020870D0();
            ((DWCstMatchControl *)DWCi_GetMatchCnt())->sbUpdateTick = tick;
        } else {
            sbError = DWCi_HandleSBError(DWCi_SBUpdateAsync(0));
            if (sbError != 0)
                return 0;
        }
    } else if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchTypeExt == 1) {
        result = DWCi_HandleMatchCommandError(func_02171C08(1, 0, resendPid));
        if (result != 0)
            return 0;
    } else if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchTypeExt == 3) {
        DWCi_StopMatch(6, -80410);
        return 0;
    }
    return 1;
}


/*
 * Sends command 5 to the new node recorded in the temporary node info.
 */
int DWCi_CancelReservation(int arg)
{
    int result;

    if (DWCi_TempNewNodeInfo_IsValid() == 0) {
        return 0;
    }
    result = DWCi_SendMatchCommand(5, *(int *)((char *)DWCi_GetMatchCnt() + 0x554), *(unsigned int *)((char *)DWCi_GetMatchCnt() + 0x558),
                           *(unsigned short *)((char *)DWCi_GetMatchCnt() + 0x560), 0, 0);
    *(int *)((char *)DWCi_GetMatchCnt() + 0x67c) = 0;
    return result;
}


/*
 * sdk:      DWCi_CancelPreConnectedServerProcessWithResetLevel (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel)
{
    DWCstNodeInfo *pNodeInfo;
    int i;

    if (DWCi_TempNewNodeInfo_IsValid())
        DWCi_TempNewNodeInfo_Clear();
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->cmdCnt.command = 0xff;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie != 0) {
        NNCancel(((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie);
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie = 0;
    }
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->reqProfileID = 0;
    if (DWCi_GetHostStatus() == 2) {
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Flag18 = 0;
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->serverProfileID = 0;
        DWCi_SetMatchStatus(0x11);
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->cancelAckBitmap = 0;
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->maxCancelLatency = 0;
        DWCi_CloseCancelHostAsync(clientPid);
        for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(i);
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


int DWCi_CancelPreConnectedServerProcess(int clientPid)
{
    int resetLevel = 2;

    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 ||
        DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        if (DWCi_GetMatchCnt()->connectionEstablished == 0)
            resetLevel = 1;
    }
    return DWCi_CancelPreConnectedServerProcessWithResetLevel(clientPid, resetLevel);
}


/*
 * sdk:      DWCi_CancelPreConnectedClientProcess (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_CancelPreConnectedClientProcess(void)
{
    int result = 1;

    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->connectGroupID != 0)
        goto stop;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchTypeExt == 3) {
    stop:
        if (DWCi_NodeInfoList_GetCount() > 1)
            DWCi_CloseAllConnectionsByTimeout();
        if (((DWCstMatchControl *)DWCi_GetMatchCnt())->connectGroupID != 0)
            DWCi_StopMatch(0x16, -80432);
        else
            DWCi_StopMatch(0x16, -80430);
        return 0;
    }
    if (DWCi_StopMeshMaking() == 1)
        return result;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewClientInfo.profileID != 0)
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewClientInfo.profileID = 0;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie != 0) {
        NNCancel(((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie);
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie = 0;
    }
    if (DWCi_IsFullMesh()) {
        if (((DWCstMatchControl *)DWCi_GetMatchCnt())->needServerPoll != 0)
            goto restart;
    }
    if (DWCi_TempNewNodeInfo_IsValid()) {
        if (DWCi_GetGT2ConnectionByProfileID(((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.profileID, 1) != 0)
            goto restart;
    }
    if (DWCi_NodeInfoList_GetCount() > 1) {
    restart:
        DWCi_RestartFromTimeout();
    } else {
        DWCi_SetMatchStatus(3);
        result = DWCi_RetryReserving(0);
    }
    return result;
}


void DWCi_PostProcessConnection(int type)
{
    u32 senddata[1];
    int result;
    DWCstMatchControl *p;

    switch (type)
    {
    case 0:
        if (DWCi_IsFullMesh())
            DWCi_PostProcessSVConnectionFullmesh();
        else
            DWCi_PostProcessSVConnectionHybrid();
        break;
    case 1:
        DWCi_SetMatchStatus(1);
        if (DWCi_GetMatchCnt()->qr2MatchType == 3)
            DWCi_GetMatchCnt()->peerProfileID = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
        break;
    case 2:
        DWCi_SetMatchStatus(1);
        if (DWCi_StopMeshMaking() == 1)
        {
            DWCi_ClearMeshMakingTempInfo();
            break;
        }
        DWCi_SetHostStatus(1);
        DWCi_GetMatchCnt()->qr2MatchType = 3;
        if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 1)
        {
            DWCi_GetMatchCnt()->qr2Flag18 = 1;
            DWCi_GetMatchCnt()->serverProfileID = DWCi_GetMatchCnt()->profileID;
        }
        DWCi_InitClWaitTimeout();
        if (DWCi_IsFullMesh())
        {
            if (DWCi_NodeInfo_IsValid(&DWCi_GetMatchCnt()->tempNewClientInfo))
            {
                DWCstNodeInfo *pNodeInfo;
                DWCstMatchControl *p;

                pNodeInfo = &DWCi_GetMatchCnt()->tempNewNodeInfo;
                senddata[0] = pNodeInfo->profileID;
                DWCi_NodeInfoList_InsertToTop(pNodeInfo);
                DWCi_GetMatchCnt()->tempNewNodeInfo =
                    DWCi_GetMatchCnt()->tempNewClientInfo;
                p = DWCi_GetMatchCnt();
                pNodeInfo = &p->tempNewNodeInfo;
                result = DWCi_SendMatchCommand(9,
                    p->tempNewNodeInfo.profileID,
                    pNodeInfo->publicInetAddress,
                    pNodeInfo->publicQueryPort,
                    senddata, 1);
                DWCi_NodeInfo_Clear(&DWCi_GetMatchCnt()->tempNewClientInfo);
                if (DWCi_HandleMatchCommandError(result))
                    return;
            }
            DWCi_GetMatchCnt()->needServerPoll = 1;
        }
        break;
    case 3:
        DWCi_GetMatchCnt()->connectionEstablished = 1;
        DWCi_PostProcessConnectionSYNFinish();
        DWCi_GetMatchCnt()->connectGroupID = 0;
        qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
        {
            int flag = (DWCi_GetMatchCnt()->peerProfileID == 0);
            DWCstMatchControl *p = DWCi_GetMatchCnt();
            result = DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID);
            p->matchedCallback(0, 0, flag, 0, result, DWCi_GetMatchCnt()->matchedParam);
        }
        if (DWCi_GetMatchCnt()->qr2MatchType == 2)
        {
            if (DWCi_HandleGPError(DWCi_GPSetServerStatus(-1)))
                return;
            DWCi_SetMatchStatus(0xd);
        }
        else
        {
            DWCi_GPSetServerStatus(2);
            DWCi_SetMatchStatus(1);
        }
        DWCi_GetMatchCnt()->peerProfileID = 0;
        DWCi_GetMatchCnt()->cancelState = 0;
        DWCi_ResetLastSomeDataRecvTimeByAidAll();
        break;
    }

    if (DWCi_GetMatchCnt()->sbObj != 0)
    {
        ServerBrowserClear(DWCi_GetMatchCnt()->sbObj);
        p = DWCi_GetMatchCnt();
        *(unsigned long long *)&p->sbUpdateRequestTick = 0;
    }
}


void DWCi_PostProcessConnectionSYNFinish(void)
{
    DWCi_GetMatchCnt()->nnFailureCount = 0;
    if (DWCi_IsFullMesh())
        DWCi_PostProcessConnectionSYNFinishFullmesh();
    else
        DWCi_PostProcessConnectionSYNFinishHybrid();
}


void DWCi_PostProcessConnectionSYNFinishHybrid(void)
{
    DWCstMatchControl *p;

    if (DWCi_GetMatchCnt()->qr2MatchType == 2) {
        if (DWCi_TempNewNodeInfo_IsValid() == 0)
            return;
        DWCi_NodeInfoList_Append(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_NodeInfoList_InsertToTop(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    p = DWCi_GetMatchCnt();
    {
        DWCstNodeInfo *newNode = &p->tempNewClientInfo;
        DWCstNodeInfo *n;

        if (newNode->profileID == 0)
            return;
        n = DWCi_NodeInfoList_GetNodeInfoForProfileID(newNode->profileID);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        n = DWCi_NodeInfoList_GetNodeInfoForAID(newNode->aid);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        DWCi_NodeInfoList_Append(newNode);
        newNode->profileID = 0;
    }
}


/*
 * Clears the byte at +0x62f of the module block.
 */
void DWCi_PostProcessConnectionSYNFinishFullmesh(void)
{
    func_0217253C();

    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x62f) = 0;
}


/*
 * sdk:      DWCi_PostProcessSVConnectionHybrid (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_PostProcessSVConnectionHybrid(void)
{
    int sbClear = 0;
    int i;
    u64 tick;

    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->inMeshMaking != 0 || ((DWCstMatchControl *)DWCi_GetMatchCnt())->backupState == 0xf) {
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Flag18 = 0;
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->serverProfileID = 0;
        DWCi_SetMatchStatus(1);
        DWCi_StopMeshMaking();
        return sbClear;
    }
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Flag18 = 0;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->serverProfileID = 0;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->connectionEstablished == 0 && DWCi_NodeInfoList_GetCount() == 1) {
        tick = func_020870D0();
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->serverPollingTime = tick;
    }
    qr2_send_statechanged(((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2Obj);
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchType == 2)
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->peerProfileID = ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.profileID;
    DWCi_SetMatchStatus(0x13);
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->synAckBitmap = 0;
    for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++)
        func_02173064(DWCi_NodeInfoList_GetNodeInfoForIndex(i)->aid, 2);
    func_02173064(((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.aid, 2);
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchType != 2)
        sbClear = 1;
    return sbClear;
}


int DWCi_PostProcessSVConnectionFullmesh(void)
{
    unsigned int senddata[16];
    int result;
    DWCstNodeInfo tmpNewNodeInfo;
    unsigned char linkProgress;
    DWCstNodeInfo *pNodeInfo;
    DWCstNodeInfo *pNew;

    result = 0;
    tmpNewNodeInfo = DWCi_GetMatchCnt()->tempNewNodeInfo;
    pNew = &tmpNewNodeInfo;
    if (DWCi_GetMatchCnt()->linkProgress < DWCi_GetNodeInfoCount() - 1) {
        linkProgress = DWCi_GetNodeInfoCount() - 1 - DWCi_GetMatchCnt()->linkProgress;
        DWCi_SetMatchStatus(0x10);
        pNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(linkProgress);
        senddata[0] = pNodeInfo->profileID;
        senddata[1] = linkProgress;
        senddata[2] = pNodeInfo->aid;
        senddata[3] = pNodeInfo->publicInetAddress;
        senddata[4] = pNodeInfo->publicQueryPort;
        senddata[5] = pNodeInfo->privateInetAddress;
        senddata[6] = pNodeInfo->privateQueryPort;
        senddata[7] = pNodeInfo->hasPrivateAddress;
        senddata[8] = *(unsigned int *)pNodeInfo->connUserData;
    } else {
        DWCi_GetMatchCnt()->linkProgress = result;
        return DWCi_PostProcessSVConnectionHybrid();
    }
    if (DWCi_GetMatchCnt()->state != 0x13) {
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(8, pNew->profileID, pNew->publicInetAddress,
                                       pNew->publicQueryPort, (const unsigned int *)senddata, 9)))
            return result;
        pNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(linkProgress);
        senddata[0] = pNew->profileID;
        senddata[1] = pNew->aid;
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(10, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                                       pNodeInfo->publicQueryPort, (const unsigned int *)senddata, 2)))
            return result;
        DWCi_GetMatchCnt()->cmdCnt.count = result;
    }
    return 0;
}


/*
 * sdk:      DWCi_DoCancelMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The DWARF declares DWCi_CancelReservation(void); every call site here loads
 * r0 = 0 first, so the file passes the argument.
 */
static void DWCi_DoCancelMatch(void)
{
    int anyGT2ConnectionExist;
    int result;

    ((DWCstMatchControl *)DWCi_GetMatchCnt())->peerProfileID = 0;
    anyGT2ConnectionExist = 0;
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 22) {
        DWCi_FinishCancelMatch();
        return;
    }
    if (DWCi_GT2GetConnectionListIdx())
        anyGT2ConnectionExist = 1;
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->cancelState = 1;

    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->qr2MatchType == 3) {
        if (((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie) {
            func_02199FB4(((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie);
            ((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie = 0;
        }
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->cancelState = 1;
        if (anyGT2ConnectionExist) {
            func_02195DE4((int *)(*((DWCstMatchControl *)DWCi_GetMatchCnt())->pGt2Socket));
        } else {
            result = DWCi_HandleMatchCommandError(DWCi_CancelReservation(0));
            if (result)
                return;
        }
        DWCi_FinishCancelMatch();
        return;
    }

    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 3 || ((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 4 ||
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 5 || ((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 6 ||
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 14 || ((DWCstMatchControl *)DWCi_GetMatchCnt())->state == 15) {
        if (((DWCstMatchControl *)DWCi_GetMatchCnt())->reqProfileID) {
            result = DWCi_HandleMatchCommandError(DWCi_CancelReservation(0));
            if (result)
                return;
        }
        result = DWCi_HandleMatchCommandError(DWCi_InvalidateReservation());
        if (result)
            return;
    }
    if (((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie) {
        func_02199FB4(((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie);
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->nnInfo.cookie = 0;
    }
    if (anyGT2ConnectionExist) {
        ((DWCstMatchControl *)DWCi_GetMatchCnt())->cancelState = 1;
        func_02195DE4((int *)(*((DWCstMatchControl *)DWCi_GetMatchCnt())->pGt2Socket));
    }
    DWCi_FinishCancelMatch();
}


/*
 * sdk:      DWCi_FinishCancelMatch (dwc_match.o)
 */
void DWCi_FinishCancelMatch(void)
{
    int gpResult;
    int a = 1;
    int b;

    gpResult = DWCi_GPSetServerStatus(a);
    if (func_02173D28(gpResult))
        return;
    DWCi_CloseMatch();
    if (*(int *)((char *)DWCi_GetMatchCnt() + 0x680) == 0) {
        if (*(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x14) != 2)
            a = 0;
    }
    b = *(int *)((char *)DWCi_GetMatchCnt() + 0x680) == 0;
    {
        char *m = (char *)DWCi_GetMatchCnt();

        (*(int (**)(int, int, int, int, int, int))(m + 0x770))(0, 1, b, a, func_02169038(*(int *)((char *)DWCi_GetMatchCnt() + 0x680)), *(int *)((char *)DWCi_GetMatchCnt() + 0x774));
    }
    *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x62a) = 0;
}


/*
 * sdk:      DWCi_InvalidateReservation (dwc_match.o)
 */
int DWCi_InvalidateReservation(void)
{
    int result;
    unsigned int senddata = 0;

    result = 0;
    if (*(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x18) != 0 && *(int *)((char *)DWCi_GetMatchCnt() + 0x5dc) != 0
        && *(int *)((char *)DWCi_GetMatchCnt() + 0x5dc) != *(int *)((char *)DWCi_GetMatchCnt() + 0x678)) {
        result = DWCi_SendMatchCommand(12, *(int *)((char *)DWCi_GetMatchCnt() + 0x5dc), *(int *)((char *)DWCi_GetMatchCnt() + 0x558), *(unsigned short *)((char *)DWCi_GetMatchCnt() + 0x560), (const unsigned int *)(&senddata), 1);
        *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x18) = 0;
        *(int *)((char *)DWCi_GetMatchCnt() + 0x5dc) = 0;
        DWCi_TempNewNodeInfo_Clear();
    }
    return result;
}


void DWCi_RestartFromCancel(int level)
{
	int sbError;
	int b;

	if (level == 0) {
		DWCi_FinishCancelMatch();
		return;
	}
	DWCi_ResetMatchParam(level);
	if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 3) {
		b = DWCi_GetMatchCnt()->peerProfileID == 0;
		DWCi_GetMatchCnt()->matchedCallback(0, 1, b, 0,
		        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID),
		        DWCi_GetMatchCnt()->matchedParam);
		return;
	}
	if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0) {
		if (DWCi_GetMatchCnt()->connectionEstablished != 0) {
			b = DWCi_GetMatchCnt()->peerProfileID == 0;
			DWCi_GetMatchCnt()->matchedCallback(0, 1, b, 0,
			        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID),
			        DWCi_GetMatchCnt()->matchedParam);
		}
		if (level == 1) {
			DWCi_SetHostStatus(0);
			DWCi_SetMatchStatus(0x16);
			sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID);
			DWCi_HandleSBError(sbError);
		}
		return;
	}
	if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
		if (DWCi_GetMatchCnt()->connectionEstablished != 0) {
			b = DWCi_GetMatchCnt()->peerProfileID == 0;
			DWCi_GetMatchCnt()->matchedCallback(0, 1, b, 0,
			        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID),
			        DWCi_GetMatchCnt()->matchedParam);
		}
		if (level == 1) {
			DWCi_SetHostStatus(0);
			DWCi_GetMatchCnt()->connectGroupID = 0;
			DWCi_SetMatchStatus(0x16);
			sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID);
			DWCi_HandleSBError(sbError);
		}
		return;
	}
}


void DWCi_RestartFromTimeout(void)
{
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2)
        return;
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3)
        return;
    DWCi_CloseAllConnectionsByTimeout();
    DWCi_RestartFromCancel(1);
}


int DWCi_ResumeMatch(void)
{
    DWCi_GetMatchCnt()->qr2Flag18 = 0;
    DWCi_GetMatchCnt()->serverProfileID = 0;
    DWCi_GetMatchCnt()->closeState = 0;
    DWCi_RestartFromCancel(1);
    return 0;
}


/*
 * sdk:      DWCi_CloseCancelHostAsync (dwc_match.o)
 */
int DWCi_CloseCancelHostAsync(int profileID)
{
    int **connection;
    int ret;

    *(int *)((char *)DWCi_GetMatchCnt() + 0x680) = profileID;
    connection = (int **)DWCi_GetGT2ConnectionByProfileID(profileID, 0);
    if (connection) {
        *(char *)((char *)DWCi_GetMatchCnt() + 0x629) = 1;
        func_02195DC4((int)(*connection));
        *(char *)((char *)DWCi_GetMatchCnt() + 0x629) = 0;
        DWCi_NodeInfoList_RemoveProfileID(profileID);
        ret = 1;
    } else {
        DWCi_NodeInfoList_RemoveProfileID(profileID);
        ret = 0;
    }
    return ret;
}


/*
 * DWCi_CloseAllConnectionsByTimeout: closes every gt2 connection with the closing flag raised.
 */
void DWCi_CloseAllConnectionsByTimeout(void)
{
    ((char *)DWCi_GetMatchCnt())[0x629] = 1;
    gt2CloseAllConnections(**(int **)((char *)DWCi_GetMatchCnt() + 4));
    ((char *)DWCi_GetMatchCnt())[0x629] = 0;
}


/*
 * sdk:      DWCi_CloseShutdownClientSC (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The DWARF declares DWCi_GetAIDFromProfileID with one parameter; the call site
 * loads r1 = 0, so the file passes it. The list stores index first and increment
 * after (validPid[len] = x; len++;); the post-increment form colors the counts
 * differently and adds a copy in the new-node block.
 */
static int DWCi_CloseShutdownClientSC(u32 bitmap)
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

    for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
        DWCstNodeInfo *nodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForIndex(i);

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

    if (DWCi_TempNewNodeInfo_IsValid()) {
        DWCstNodeInfo *nodeInfo = &((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo;

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
        nodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetNodeInfoForProfileID(validPid[i]);
        if (DWCi_TempNewNodeInfo_IsValid() && nodeInfo == 0 &&
            validPid[i] == ((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.profileID)
            nodeInfo = &((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo;
        if (nodeInfo) {
            result = DWCi_SendMatchCommand(0x10, validPid[i], nodeInfo->publicInetAddress,
                                   nodeInfo->publicQueryPort, (const unsigned int *)senddata, senddataLen);
            if (DWCi_HandleMatchCommandError(result))
                bRet = 0;
        }
    }

    ((DWCstMatchControl *)DWCi_GetMatchCnt())->closeState = 1;
    if (bShutdownNewNode) {
        DWCi_CloseConnectionHard(((DWCstMatchControl *)DWCi_GetMatchCnt())->tempNewNodeInfo.aid);
        DWCi_TempNewNodeInfo_Clear();
    }
    for (i = 0; i < senddataLen; i++) {
        aid = DWCi_GetAIDFromProfileID(senddata[i], 0);
        if (aid != 0xff)
            DWCi_CloseConnectionHard(aid);
    }
    ((DWCstMatchControl *)DWCi_GetMatchCnt())->closeState = 0;
    return bRet;
}


void DWCi_SendMatchSynPacket(u8 aid, u16 type)
{
    u8 buf[8];
    DWCstNodeInfo * pNodeInfo;
    int clientCount;
    u8 i;
    u32 * pSendBuf;
    int sendCount;
    int sendSize;

    sendSize = 4;
    pSendBuf = (u32 *)buf;

    switch (type) {
    case 2:
        if (DWCi_TempNewNodeInfo_IsValid() != 0 &&
            aid == DWCi_GetMatchCnt()->tempNewNodeInfo.aid) {
            pSendBuf[0] = 1;
            break;
        }
        sendSize = 0x1c;
        pSendBuf = DWC_Alloc(4, sendSize);
        if (pSendBuf == 0)
            return;
        pSendBuf[0] = 0;
        pNodeInfo = &DWCi_GetMatchCnt()->tempNewNodeInfo;
        pSendBuf[1] = ((pNodeInfo->hasPrivateAddress << 16) & 0xffff0000) | pNodeInfo->aid;
        pSendBuf[2] = pNodeInfo->profileID;
        pSendBuf[3] = pNodeInfo->publicInetAddress;
        pSendBuf[4] = pNodeInfo->privateInetAddress;
        pSendBuf[5] = ((pNodeInfo->publicQueryPort << 16) & 0xffff0000) | pNodeInfo->privateQueryPort;
        pSendBuf[6] = *(u32 *)pNodeInfo->connUserData;
        break;
    case 3:
        {
            u8 *senddata = (u8 *)pSendBuf;
            senddata[0] = DWCi_GetMatchCnt()->hostLatency;
            senddata[1] = DWCi_GetMatchCnt()->hostLatency >> 8;
        }
        break;
    case 4:
        if (DWCi_TempNewNodeInfo_IsValid() == 0 ||
            aid != DWCi_GetMatchCnt()->tempNewNodeInfo.aid)
            goto fourElse;
        if (DWCi_IsFullMesh() != 0)
            clientCount = 0;
        else
            clientCount = DWCi_NodeInfoList_GetCount() - 1;
        if (clientCount == 0) {
            {
                u8 *senddata = (u8 *)pSendBuf;
                senddata[0] = 0;
                senddata[1] = 0;
                senddata[2] = 0;
                senddata[3] = 0;
            }
            pSendBuf[1] = DWCi_GetMatchCnt()->matchSessionID;
            sendSize = 8;
            break;
        }
        sendSize = clientCount * 0x18 + 8;
        pSendBuf = DWC_Alloc(4, sendSize);
        if (pSendBuf == 0)
            return;
        pSendBuf[0] = clientCount;
        sendCount = 1;
        for (i = 0; i < clientCount; i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i + 1);
            pSendBuf[sendCount++] = ((pNodeInfo->hasPrivateAddress << 16) & 0xffff0000) | pNodeInfo->aid;
            pSendBuf[sendCount++] = pNodeInfo->profileID;
            pSendBuf[sendCount++] = pNodeInfo->publicInetAddress;
            pSendBuf[sendCount++] = pNodeInfo->privateInetAddress;
            pSendBuf[sendCount++] = ((pNodeInfo->publicQueryPort << 16) & 0xffff0000) | pNodeInfo->privateQueryPort;
            pSendBuf[sendCount++] = *(u32 *)pNodeInfo->connUserData;
        }
        pSendBuf[sendCount] = DWCi_GetMatchCnt()->matchSessionID;
        break;
    fourElse:
        {
            u8 *senddata = (u8 *)pSendBuf;
            senddata[0] = 0;
            senddata[1] = 0;
            senddata[2] = 0;
            senddata[3] = 0;
        }
        sendSize = 8;
        pSendBuf[1] = DWCi_GetMatchCnt()->matchSessionID;
        break;
    }
    DWCi_SendReliable(type, aid, pSendBuf, sendSize);
    if (pSendBuf != (u32 *)buf)
        DWC_Free(4, pSendBuf, 0);
    {
        unsigned long long tick = OS_GetTick();
        DWCi_GetMatchCnt()->synAckTick = tick;
    }
}


DWCstMatchControl;


int DWCi_ProcessMatchSynTimeout(void)
{
    DWCstNodeInfo * node;
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->state == 8 ||
        DWCi_GetMatchCnt()->state == 0x13 ||
        DWCi_GetMatchCnt()->state == 0x17 ||
        DWCi_GetMatchCnt()->state == 0x14) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->synAckTick;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->state) {
    case 8:
        if (passTime <= DWCi_GetMatchCnt()->clWaitTime)
            break;
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt()->tempNewClientInfo.profileID = 0;
        node = DWCi_NodeInfoList_GetServerNodeInfo();
        if (((int (*)(int))DWCi_CancelPreConnectedClientProcess)(node->profileID) == 0)
            return 0;
        break;
    case 0x13:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->synResendCount++;
        if (DWCi_GetMatchCnt()->synResendCount > 5) {
            DWCi_GetMatchCnt()->synResendCount = 0;
            passTime = OS_GetTick();
            DWCi_GetMatchCnt()->synAckTick = passTime;
            DWCi_ServerSynTimeoutExec();
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                node = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                if (DWCi_GetMatchCnt()->synAckBitmap & (1 << node->aid))
                    continue;
                DWCi_SendMatchSynPacket(node->aid, 2);
            }
            node = &DWCi_GetMatchCnt()->tempNewNodeInfo;
            if (!(DWCi_GetMatchCnt()->synAckBitmap & (1 << node->aid)))
                DWCi_SendMatchSynPacket(node->aid, 2);
        }
        break;
    case 0x17:
        if (passTime <= 0xbb8)
            break;
        DWCi_SendTypeMatchAck();
        break;
    case 0x14:
        if (passTime <= DWCi_GetMatchCnt()->hostLatency)
            break;
        DWCi_PostProcessConnection(3);
        break;
    }
    return 1;
}


/*
 * sdk:      DWCi_ServerSynTimeoutExec (dwc_match.o)
 */
int DWCi_ServerSynTimeoutExec(void)
{
    if (!DWCi_CloseShutdownClientSC(*(int *)((char *)DWCi_GetMatchCnt() + 0x650)))
        return 0;
    if (DWCi_NodeInfoList_GetCount() > 1 || DWCi_TempNewNodeInfo_IsValid()) {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)((char *)DWCi_GetMatchCnt() + 0x658) = t;
        DWCi_SetMatchStatus(23);
    } else if (!func_021720D8(*(int *)((char *)DWCi_GetMatchCnt() + 0x680))) {
        return 0;
    }
    return 1;
}


/*
 * sdk:      DWCi_SendTypeMatchAck (dwc_match.o)
 */
void DWCi_SendTypeMatchAck(void)
{
    int i;

    if (DWCi_GetHostStatus() != 2)
        return;
    for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++)
        func_02173064(DWCi_NodeInfoList_GetNodeInfoForIndex(i)->aid, 4);
    if (DWCi_TempNewNodeInfo_IsValid())
        func_02173064(*(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x56a), 4);
    DWCi_SetMatchStatus(20);
}


int DWCi_SendCancelMatchSynCommand(int profileID, unsigned char command)
{
    DWCstNodeInfo *pNodeInfo;
    int result;
    int len;
    unsigned int senddata[1];

    if (command != 13) {
        len = 0;
    } else {
        senddata[0] = *(unsigned int *)((char *)DWCi_GetMatchCnt() + 0x680);
        len = 1;
    }
    pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID);
    if (!pNodeInfo)
        return 0;
    result = DWCi_SendMatchCommand(command, profileID, pNodeInfo->publicInetAddress, pNodeInfo->publicQueryPort, (const unsigned int *)senddata, len);
    if (DWCi_HandleMatchCommandError(result))
        return 0;
    {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)((char *)DWCi_GetMatchCnt() + 0x660) = t;
    }
    return 1;
}


int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data)
{
    DWCstNodeInfo * pNodeInfo;
    int i;
    unsigned long long latency;
    unsigned long long baseTime;
    u32 bitmask;
    u8 aid;

    if (DWC_GetState() != 5)
        return 1;

    switch (command) {
    case 0xd:
        if (DWCi_GetMatchCnt()->state != 7) {
            DWCi_SetMatchStatus(7);
            DWCi_GetMatchCnt()->peerProfileID = data;
            if (DWCi_GetMatchCnt()->tempNewClientInfo.profileID != 0)
                DWCi_GetMatchCnt()->tempNewClientInfo.profileID = 0;
            DWCi_TempNewNodeInfo_Clear();
        }
        if (DWCi_SendCancelMatchSynCommand(profileID, 0xe) != 0)
            break;
        return 0;
    case 0xe:
        if (DWCi_GetMatchCnt()->state == 0x11) {
            baseTime = OS_GetTick();
            if ((baseTime - DWCi_GetMatchCnt()->cancelStartTick) * 64 / 0x82ea / 2 > 0x12c) {
                latency = (baseTime - DWCi_GetMatchCnt()->cancelStartTick) * 64 / 0x82ea / 2 - 0x12c;
                if (latency > DWCi_GetMatchCnt()->maxCancelLatency)
                    DWCi_GetMatchCnt()->maxCancelLatency = latency;
            }
            aid = DWCi_GetAIDFromProfileID(profileID, 0);
            if (aid != 0xff)
                DWCi_GetMatchCnt()->cancelAckBitmap |= 1 << aid;
            bitmask = DWCi_GetAIDBitmask(1);
            if (bitmask != DWCi_GetMatchCnt()->cancelAckBitmap)
                break;
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xf) == 0)
                    return 0;
            }
            DWCi_SetMatchStatus(0x12);
        } else if (DWCi_SendCancelMatchSynCommand(profileID, 0xf) == 0) {
            return 0;
        }
        break;
    case 0xf:
        if (DWCi_GetMatchCnt()->state == 7)
            DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}


int DWCi_ProcessCancelMatchSynTimeout(void)
{
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->state == 7 ||
        DWCi_GetMatchCnt()->state == 0x11 ||
        DWCi_GetMatchCnt()->state == 0x12) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->cancelStartTick;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->state) {
    case 7: {
        DWCstNodeInfo * pNodeInfo;

        if (passTime <= 0x1770)
            break;
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        if (DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xe) == 0)
            return 0;
        break;
    }
    case 0x11:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->cancelSynResendCount++;
        if (DWCi_GetMatchCnt()->cancelSynResendCount > 5) {
            if (DWCi_CloseShutdownClientSC(DWCi_GetMatchCnt()->cancelAckBitmap) == 0)
                return 0;
            if (DWCi_NodeInfoList_GetCount() > 1) {
                DWCi_GetMatchCnt()->cancelSynResendCount = 0;
                passTime = OS_GetTick();
                DWCi_GetMatchCnt()->cancelStartTick = passTime;
            } else {
                DWCi_RestartFromCancel(2);
            }
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                DWCstNodeInfo * pNodeInfo =
                    DWCi_NodeInfoList_GetNodeInfoForIndex(i);

                if (DWCi_GetMatchCnt()->cancelAckBitmap & (1 << pNodeInfo->aid))
                    continue;
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xd) == 0)
                    return 0;
            }
        }
        break;
    case 0x12:
        if (passTime <= DWCi_GetMatchCnt()->maxCancelLatency)
            break;
        DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}


/*
 * Finds the first empty record (stride 0xc) among 0x9a entries and returns
 * its biased index; 0 when none is free.
 */
u8 DWCi_GetNewMatchKey(void)
{
    u8 i;

    for (i = 0; i < 0x9a; i++) {
        if (d_021AAA40[i * 0xc] == 0)
            return (i + 0x64) & 0xff;
    }
    return 0;
}


/*
 * DWCi_ClearGameMatchKeys: frees every game match key value and clears the key table.
 */
void DWCi_ClearGameMatchKeys(void)
{
    int i;

    for (i = 0; i < 0x9a; i++) {
        if (g_021AAA40[i].keyString != 0) {
            DWC_Free(4, g_021AAA40[i].keyString, 0);
        }
    }
    MIi_CpuClear32(0, g_021AAA40, sizeof(DWCstGameMatchKeyData) * 0x9a);
}


/*
 * sdk:      DWCi_IsFriendByIdxList (dwc_match.o)
 */
int DWCi_IsFriendByIdxList(int profileID)
{
    int i;
    int id;

    if (*(int *)((char *)DWCi_GetMatchCnt() + 0x68c) == 0)
        return 0;
    for (i = 0; i < *(int *)((char *)DWCi_GetMatchCnt() + 0x6d4); i++) {
        id = func_02168FF0(*(unsigned char *)((char *)DWCi_GetMatchCnt() + i + 0x694));
        if (id > 0 && id == profileID)
            return 1;
    }
    return 0;
}


/*
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 */
int DWCi_CheckDWCServer(void *server)
{
    if (func_0219E120(server, g_021A21A4, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A21B0, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2170, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2164, -1) == -1)
        return 0;
    return func_0219E120(server, g_021A20A4, 0);
}


/*
 * Byte at +0x16 of the block, or 0xff when there is none.
 */
u8 DWCi_GetAIDFromProfileID(int profileID, int idxOnly)
{
    unsigned char *p = (unsigned char *)DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID);

    if (p == 0)
        return 0xff;
    return *(unsigned char *)(p + 0x16);
}


/*
 * sdk:      DWCi_GetAIDBitmask (dwc_match.o)
 */
unsigned int DWCi_GetAIDBitmask(int valid)
{
    unsigned int bitmask = 0;
    int i;

    for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++)
        bitmask |= 1 << *(unsigned char *)((char *)DWCi_NodeInfoList_GetNodeInfoForIndex(i) + 0x16);
    if (valid == 0)
        bitmask |= 1 << *(unsigned char *)((char *)DWCi_GetMatchCnt() + 0x56a);
    return bitmask;
}


/*
 * DWCi_InitClWaitTimeout: clears the wait flag and stamps the current tick.
 */
void DWCi_InitClWaitTimeout(void)
{
    unsigned long long t;

    ((char *)DWCi_GetMatchCnt())[0x62e] = 0;
    t = OS_GetTick();
    *(unsigned long long *)((char *)DWCi_GetMatchCnt() + 0x670) = t;
}


/*
 * Maps a match-command error to a DWC error and stops the match.
 */
int func_02173D28(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 9;
        errorCode = -2;
        break;
    case 3:
        dwcError = 6;
        errorCode = -10;
        break;
    case 4:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    DWCi_StopMatch(dwcError, errorCode + -81000);
    return error;
}


/*
 * DWCi_HandleSBError: maps a server browsing error to a DWC error and stops the match.
 */
int DWCi_HandleSBError(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -30;
        break;
    case 3:
        dwcError = 6;
        errorCode = -20;
        break;
    case 4:
        dwcError = 6;
        errorCode = -40;
        break;
    case 5:
        dwcError = 9;
        errorCode = -1;
        break;
    case 6:
        dwcError = 9;
        errorCode = -2;
        break;
    }
    DWCi_StopMatch(dwcError, errorCode + -85000);
    return error;
}


/*
 * sdk:      DWCi_HandleQR2Error (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_HandleQR2Error(int error)
{
    int errorCode;
    int dwcError;

    if (error == 0)
        return 0;
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -60;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    case 4:
        dwcError = 6;
        errorCode = -80;
        break;
    case 5:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    switch (DWC_GetState()) {
    case 2:
        func_0216A3B8(dwcError, errorCode - 64000);
        break;
    case 4:
        DWCi_StopMatch(dwcError, errorCode - 84000);
        break;
    default:
        DWCi_SetError(dwcError, errorCode - 94000);
        break;
    }
    return error;
}


/*
 * DWCi_HandleNNError: maps a NAT negotiation error to a DWC error and stops the match.
 */
int DWCi_HandleNNError(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 6;
        errorCode = -50;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    }
    DWCi_StopMatch(dwcError, errorCode + -86000);
    return error;
}


int DWCi_HandleNNResult(int result)
{
    enum E dwcError;

    if (result == 0)
        return 0;
    switch (result) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        dwcError = E_NET;
        break;
    }
    if (dwcError != E_OK)
        DWCi_StopMatch(dwcError, -86009);
    return result;
}


/*
 * sdk:      DWCi_HandleGT2Error (dwc_match.o)
 */
int func_02173FB4(int result)
{
    int dwcError;
    int errorCode;

    if (result == 0)
        return 0;
    switch (result) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
    case 5:
        dwcError = 0;
        errorCode = 0;
        result = 0;
        break;
    case 3:
        dwcError = 6;
        errorCode = -10;
        break;
    case 4:
        dwcError = 6;
        errorCode = -30;
        break;
    case 6:
        dwcError = 6;
        errorCode = -70;
        break;
    case 7:
        dwcError = 6;
        errorCode = -80;
        break;
    }
    if (dwcError != 0)
        DWCi_StopMatch(dwcError, errorCode + -87000);
    return result;
}


/*
 * notes:    the retry tail (state 2 and a fresh timeout tick) is written out at the end of
 *           cases 0x16, 4 and 0xC; the compiler cross-jumps the identical copies, which
 *           leaves the one-instruction jump stubs the image has. The counter, running
 *           maximum and per-server count of the case 0xC scan are block locals of its
 *           sbCount > 1 arm; declaration order in the function block fixes the rest of
 *           the register assignment. The bare MC() call and the unused
 *           ServerBrowserGetServer(sb, 0) call in case 4 are in the image and kept.
 *
 * sdk:      DWCi_SBCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
void DWCi_SBCallback(void *sb, int reason, void *server)
{
    int sbCount;
    void *targetServer;
    int i;
    int profileID;
    u64 tick;
    DWCstNodeInfo tmpNodeInfo;

    s_bInNNThink.sbCallbackLevel++;

    if (MC()->sbUpdateRequestTick != 0) {
        if (reason == 4 || reason == 5) {
            MC()->sbUpdateRequestTick = 0;
        } else {
            tick = OS_GetTick();
            MC()->sbUpdateRequestTick = tick + (u64)0xEFB5F7;
        }
    }

    switch (reason) {
    case 0:
        DWCi_SBPrintServerData(server);
        break;
    case 4:
        MC()->sbUpdateRequestTick = 0;
        for (i = 0; i < ServerBrowserCount(sb); i++) {
            server = ServerBrowserGetServer(sb, i);
            if (DWCi_CheckDWCServer(server) == 0) {
                ServerBrowserRemoveServer(sb, server);
                i--;
            }
        }
        switch (MC()->state) {
        case 0x16: {
            int j;

            j = 0;
            if (ServerBrowserCount(sb) > 0) {
                do {
                    server = ServerBrowserGetServer(sb, j);
                    if (MC()->qr2IP != 0 &&
                        MC()->qr2IP == SBServerGetPublicInetAddress(server) &&
                        MC()->qr2Port != 0 &&
                        MC()->qr2Port == SBServerGetPublicQueryPort(server))
                        break;
                    j++;
                } while (j < ServerBrowserCount(sb));
            }
            if (j < ServerBrowserCount(sb)) {
                MI_CpuFill8(&tmpNodeInfo, 0, 0x28);
                tmpNodeInfo.profileID = MC()->profileID;
                tmpNodeInfo.aid = 0xFF;
                tmpNodeInfo.publicInetAddress = MC()->qr2IP;
                tmpNodeInfo.publicQueryPort = MC()->qr2Port;
                tmpNodeInfo.privateInetAddress = SBServerGetPrivateInetAddress(server);
                tmpNodeInfo.privateQueryPort = SBServerGetPrivateQueryPort(server);
                tmpNodeInfo.hasPrivateAddress = SBServerHasPrivateAddress(server);
                MI_CpuCopy8(MC()->connUserData, &tmpNodeInfo.connUserData, 4);
                if (MC()->qr2MatchTypeExt == 0) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->qr2MatchTypeExt == 1) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->qr2MatchTypeExt == 2) {
                    tmpNodeInfo.aid = DWCi_NodeInfoList_GetFreeAID();
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->qr2MatchTypeExt == 3) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                }
                goto end;
            }
            RETRY();
            goto end;
        }
        case 2:
            DWCi_EvaluateServers(1);
            DWCi_RandomizeServers();
            if (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                DWCi_TempNewNodeInfo_Clear();
                MC()->tempNewNodeInfo.profileID = SBServerGetIntValueA(server, g_021A20A4, 0);
                MC()->tempNewNodeInfo.aid = 0xFF;
                MC()->tempNewNodeInfo.publicInetAddress = SBServerGetPublicInetAddress(server);
                MC()->tempNewNodeInfo.publicQueryPort = SBServerGetPublicQueryPort(server);
                MC()->tempNewNodeInfo.privateInetAddress = SBServerGetPrivateInetAddress(server);
                MC()->tempNewNodeInfo.privateQueryPort = SBServerGetPrivateQueryPort(server);
                MC()->tempNewNodeInfo.hasPrivateAddress = SBServerHasPrivateAddress(server);
                ((void (*)(int))DWCi_ConnectToGameServerAsync_InterChange)(MC()->tempNewNodeInfo.profileID);
            } else {
                MC()->sbUpdateFlag = 2;
                tick = OS_GetTick();
                MC()->sbUpdateTick = tick;
                DWCi_TempNewNodeInfo_Clear();
            }
            goto end;
        case 4:
            while (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                if (SBServerGetPublicInetAddress(server) == MC()->tempNewNodeInfo.publicInetAddress &&
                    SBServerGetPublicQueryPort(server) == MC()->tempNewNodeInfo.publicQueryPort)
                    break;
                ServerBrowserRemoveServer(sb, server);
            }
            if (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                profileID = SBServerGetIntValueA(server, g_021A20A4, 0);
                if (MC()->qr2MatchTypeExt == 1) {
                    MC();
                    if (profileID != MC()->reqProfileID ||
                        DWCi_EvaluateServers(0) == 0) {
                        if (DWCi_HandleMatchCommandError(
                                DWCi_CancelReservation(MC()->reqProfileID)) != 0)
                            goto end;
                        DWCi_SetMatchStatus(3);
                        DWCi_TempNewNodeInfo_Clear();
                        DWCi_HandleMatchCommandError(
                            DWCi_SendResvCommandToFriend(0, 0, MC()->reqProfileID));
                        goto end;
                    }
                }
                DWCi_SetMatchStatus(5);
                ServerBrowserGetServer(sb, 0);
                DWCi_HandleNNError(DWCi_NNStartupAsync(0, 0,
                    (DWCstNodeInfo *)&MC()->tempNewNodeInfo.profileID));
                goto end;
            }
            RETRY();
            goto end;
        case 0xC:
            sbCount = ServerBrowserCount(sb);
            if (sbCount != 0) {
                if (sbCount > 1) {
                    int k;
                    int max_numplayers;
                    int numplayers;

                    max_numplayers = -1;
                    for (k = 0; k < sbCount; k++) {
                        server = ServerBrowserGetServer(sb, k);
                        numplayers = SBServerGetIntValueA(server, g_021A21A4, -1);
                        if (max_numplayers < numplayers) {
                            targetServer = server;
                            max_numplayers = numplayers;
                        }
                    }
                } else {
                    targetServer = ServerBrowserGetServer(sb, 0);
                }
                DWCi_TempNewNodeInfo_Clear();
                MC()->tempNewNodeInfo.profileID = SBServerGetIntValueA(targetServer, g_021A20A4, 0);
                MC()->tempNewNodeInfo.aid = 0xFF;
                MC()->tempNewNodeInfo.publicInetAddress = SBServerGetPublicInetAddress(targetServer);
                MC()->tempNewNodeInfo.publicQueryPort = SBServerGetPublicQueryPort(targetServer);
                MC()->tempNewNodeInfo.privateInetAddress = SBServerGetPrivateInetAddress(targetServer);
                MC()->tempNewNodeInfo.privateQueryPort = SBServerGetPrivateQueryPort(targetServer);
                MC()->tempNewNodeInfo.hasPrivateAddress = SBServerHasPrivateAddress(targetServer);
                MC()->qr2MatchTypeExt = SBServerGetIntValueA(targetServer, g_021A2170, -1);
                {
                    int topology = DWCi_GetTopologyType();

                    profileID = SBServerGetIntValueA(targetServer, g_021A20A4, 0);
                    DWCi_ConnectToGameServerAsync(topology, profileID,
                        (void *)MC()->matchedCallback, (void *)MC()->matchedParam,
                        (void *)MC()->newClientCallback, (void *)MC()->newClientParam,
                        (void *)MC()->attemptCallback, MC()->connUserData,
                        (void *)MC()->attemptParam);
                }
                goto end;
            }
            RETRY();
            goto end;
        default:
            goto end;
        }
        break;
    }
end:
    s_bInNNThink.sbCallbackLevel--;
}

void DWCi_DebugPrintServerList(void)
{
}


/*
 * sdk:      DWCi_EvaluateServers (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
static int DWCi_EvaluateServers(int sort)
{
    int eval;
    int deleteFlag = 0;
    int localDelete;
    int profileID;
    int i;
    void *server;

    for (i = 0; i < func_0219F068(DWCi_GetMatchCnt()->sbObj); i++) {
        server = func_0219F058(DWCi_GetMatchCnt()->sbObj, i);
        if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0) {
            profileID = func_0219E120(server, d_021A20A4, 0);
            localDelete = 0;
            if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID)) {
                func_0219EFA8(DWCi_GetMatchCnt()->sbObj, server);
                i--;
                localDelete = 1;
            }
            if (localDelete)
                continue;
        }
        if (DWCi_GetMatchCnt()->evalCallback) {
            eval = DWCi_GetMatchCnt()->evalCallback(i, DWCi_GetMatchCnt()->evalParam);
            if (eval > 0) {
                if (eval > 0x7fffff)
                    eval = 0x7fffff;
                func_0219E084(server, g_021A21BC, (eval << 8) | func_021685CC(0x100));
            } else {
                func_0219EFA8(DWCi_GetMatchCnt()->sbObj, server);
                deleteFlag = 1;
                i--;
            }
        } else {
            func_0219E084(server, g_021A21BC, func_021685CC(0x80));
        }
    }
    if (sort && func_0219F068(DWCi_GetMatchCnt()->sbObj))
        func_0219F078(DWCi_GetMatchCnt()->sbObj, 0, g_021A21BC, 0);
    if (deleteFlag && func_0219F068(DWCi_GetMatchCnt()->sbObj) == 0)
        return 0;
    return 1;
}


/*
 * sdk:      DWCi_RandomizeServers (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void DWCi_RandomizeServers(void)
{
    unsigned int rand;
    int tmpEval;
    int maxEval;
    int sum;
    int i;
    unsigned int eval[6];
    void *server;

    maxEval = 0;
    sum = 0;
    if (func_0219F068(DWCi_GetMatchCnt()->sbObj) <= 1)
        return;
    for (i = 0; i < func_0219F068(DWCi_GetMatchCnt()->sbObj); i++) {
        server = func_0219F058(DWCi_GetMatchCnt()->sbObj, i);
        tmpEval = func_0219E120(server, g_021A21BC, -1);
        if (tmpEval > maxEval)
            maxEval = tmpEval;
        sum += g_021A19C0[i];
    }
    rand = func_021685CC(100);
    for (i = 0; i < func_0219F068(DWCi_GetMatchCnt()->sbObj); i++) {
        unsigned int prev;
        if (i == func_0219F068(DWCi_GetMatchCnt()->sbObj) - 1)
            break;
        prev = (i > 0) ? eval[i - 1] : 0;
        tmpEval = g_021A19C0[i] * 100 / sum;
        tmpEval += prev;
        eval[i] = tmpEval;
        if (rand < tmpEval)
            break;
    }
    if (maxEval < 0x7fffffff)
        maxEval++;
    server = func_0219F058(DWCi_GetMatchCnt()->sbObj, i);
    func_0219E084(server, g_021A21BC, maxEval);
    func_0219F078(DWCi_GetMatchCnt()->sbObj, 0, g_021A21BC, 0);
}


/*
 * sdk:      DWCi_QR2ServerKeyCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void DWCi_QR2ServerKeyCallback(int keyid, void *outbuf)
{
    int suspendMatch;
    int numPlayers;
    int index;

    switch (keyid) {
    case 8:
        numPlayers = DWCi_NodeInfoList_GetCount() - 1;
        if (numPlayers < 0)
            numPlayers = 0;
        func_0219B628(outbuf, numPlayers);
        return;
    case 10:
        func_0219B628(outbuf, DWCi_GetMatchCnt()->qr2NumEntry);
        return;
    case 50:
        func_0219B628(outbuf, DWCi_GetMatchCnt()->profileID);
        return;
    case 51:
        func_0219B628(outbuf, DWCi_GetMatchCnt()->qr2MatchTypeExt);
        return;
    case 52:
        func_0219B628(outbuf, 90);
        return;
    case 53:
        func_0219B628(outbuf, 1);
        return;
    case 54:
        if (func_02175FB8() == 2)
            suspendMatch = DWCi_GetMatchCnt()->groupID;
        else
            suspendMatch = 0;
        func_0219B628(outbuf, suspendMatch);
        return;
    case 55:
        func_0219B628(outbuf, DWCi_GetMatchCnt()->qr2HostState);
        return;
    case 56:
        func_0219B628(outbuf, DWCi_GetMatchCnt()->suspendMatch);
        return;
    }
    index = keyid - 100;
    if (index < 0 || index >= 154)
        return;
    if (g_021AAA40[index].keyID == 0)
        return;
    if (g_021AAA40[index].isStr != 0)
        func_0219B660(outbuf, (char *)g_021AAA40[index].value);
    else
        func_0219B628(outbuf, *(int *)g_021AAA40[index].value);
}


/*
 * sdk:      DWCi_QR2PlayerKeyCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * notes:    a stub the listing printed as data; DWCi_QR2Startup's relocation
 *           at +0x170 (ABS32 DWCi_QR2PlayerKeyCallback) is the pool word at
 *           0x0216CEFC.  Seeded in layout/function_starts.txt.
 */
void DWCi_QR2PlayerKeyCallback(void)
{
}


/*
 * sdk:      DWCi_QR2TeamKeyCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * notes:    a stub the listing printed as data; DWCi_QR2Startup's relocation
 *           at +0x174 (ABS32 DWCi_QR2TeamKeyCallback) is the pool word at
 *           0x0216CF00.  Seeded in layout/function_starts.txt.
 */
void DWCi_QR2TeamKeyCallback(void)
{
}


void DWCi_QR2KeyListCallback(int keytype, void *keybuffer)
{
    int i;

    switch (keytype) {
    case 0:
        qr2_keybuffer_add(keybuffer, 8);
        qr2_keybuffer_add(keybuffer, 10);
        qr2_keybuffer_add(keybuffer, 0x32);
        qr2_keybuffer_add(keybuffer, 0x33);
        qr2_keybuffer_add(keybuffer, 0x34);
        qr2_keybuffer_add(keybuffer, 0x35);
        qr2_keybuffer_add(keybuffer, 0x36);
        qr2_keybuffer_add(keybuffer, 0x37);
        qr2_keybuffer_add(keybuffer, 0x38);
        for (i = 0; i < 154; i++) {
            if (g_021AAA40[i].keyID != 0)
                qr2_keybuffer_add(keybuffer, g_021AAA40[i].keyID);
        }
        break;
    case 1:
        break;
    case 2:
        break;
    }
}


int DWCi_QR2CountCallback(void)
{
    return 0;
}


int DWCi_QR2AddErrorCallback(int error)
{
    return DWCi_HandleQR2Error(error);
}


void DWCi_QR2PublicAddrCallback(unsigned int ip, unsigned short port)
{
    DWCi_GetMatchCnt()->qr2IP = ip;
    DWCi_GetMatchCnt()->qr2Port = port;
}


/*
 * sdk:      DWCi_QR2NatnegCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void DWCi_QR2NatnegCallback(int cookie)
{
    int nnError;

    if (DWC_IsServerMyself() == 0 && DWCi_GetMatchCnt()->tempNewClientInfo.profileID != 0)
        return;
    if (DWCi_GetMatchCnt()->state == 1) {
        if (DWCi_IsFullMesh() == 0)
            return;
        DWCi_SetMatchStatus(5);
    } else if (DWCi_GetMatchCnt()->state != 5 && DWCi_GetMatchCnt()->state != 14) {
        return;
    }
    if (cookie == DWCi_GetMatchCnt()->nnLastCookie) {
        DWCi_GetMatchCnt()->nnSameCookieCount++;
    } else {
        DWCi_GetMatchCnt()->nnSameCookieCount = 0;
        DWCi_GetMatchCnt()->nnLastCookie = cookie;
    }
    DWCi_GetMatchCnt()->nnFailedTime = 0;
    nnError = func_0216FC34(1, cookie, &DWCi_GetMatchCnt()->tempNewNodeInfo);
    if (DWCi_HandleNNError(nnError) != 0)
        return;
    DWCi_GetMatchCnt()->cmdCnt.command = 0xFF;
}


void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len)
{
    unsigned int payload[32];
    DWCstBinaryMessageHeader binaryCommand;

    if (DWC_GetState() == 4 ||
        (DWC_GetState() == 5 && (DWCi_GetMatchCnt()->qr2MatchType == 2 ||
                                 DWCi_GetMatchCnt()->qr2MatchType == 3))) {
        MI_CpuCopy8(data, &binaryCommand, 0x14);
        binaryCommand.profileID = (unsigned int)(binaryCommand.profileID);
        if (binaryCommand.version != 0x5a || len != binaryCommand.size + 0x14)
            return;
        MI_CpuCopy8((char *)data + 0x14, payload, binaryCommand.size);
        DWCi_ProcessRecvMatchCommand(binaryCommand.command, binaryCommand.profileID,
            binaryCommand.qr2IP, binaryCommand.qr2Port, payload, binaryCommand.size >> 2);
    }
}


/*
 * sdk:      DWCi_QR2ClientMsgCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * note: volatile in this file is a matching device (it forces the reload the
 *   original performs); the vendor DWARF declares the object without volatile.
 */
void DWCi_QR2ClientMsgCallback(char *data, int len)
{
    DWCstBinaryMessageHeader sbMsg;
    u32 payload[32];
    int boolResult;
    int offset = 0;

    if (DWC_GetState() != 4) {
        if (DWC_GetState() != 5)
            return;
        if (DWCi_GetMatchCnt()->qr2MatchType != 2 && DWCi_GetMatchCnt()->qr2MatchType != 3)
            return;
    }
    while (offset + 0x14 <= len) {
        MI_CpuCopy8(data, &sbMsg, 0x14);
        *(volatile int *)&sbMsg.profileID = sbMsg.profileID;
        if (func_020949F4((const u8 *)sbMsg.identifier, (const u8 *)g_021A2188, 4) != 0 || sbMsg.version != 0x5a)
            return;
        MI_CpuCopy8(data + 0x14, payload, sbMsg.size);
        boolResult = DWCi_ProcessRecvMatchCommand(sbMsg.command, sbMsg.profileID, sbMsg.qr2IP, sbMsg.qr2Port, payload, sbMsg.size >> 2);
        if (boolResult == 0)
            return;
        offset += sbMsg.size + 0x14;
    }
}

void DWCi_NNProgressCallback(void)
{
}

#undef MC

#define MC DWCi_GetMatchCnt()


void DWCi_NNCompletedCallback(int result, int unused, struct SOCSockAddrIn *remoteaddr,
                              struct DWCstNNInfo *nnInfo)
{
    char pidStr[24];
    int status;
    unsigned long long tick;
    int gt2Result;

    if (MC->state != 5 && MC->state != 0xe)
        return;
    if (nnInfo == 0)
        return;

    if (result == 0) {
        if (nnInfo->clientindex != 0) {
        MC->tempNewNodeInfo.gt2IP = remoteaddr->addr.addr;
        {
            int p = remoteaddr->port;
            MC->tempNewNodeInfo.gt2Port = ((p >> 8) & 0xff) | ((p << 8) & 0xff00);
        }
        MC->nnSameCookieCount = 0;
        MC->nnLastCookie = 0;
        MC->nnFailedTime = 0;
        if (MC->state == 0xe)
            DWCi_SetMatchStatus(0xf);
        else
            DWCi_SetMatchStatus(6);
        MC->gt2RetryCount = 0;
        DWCi_MakeGT2ConnectString(pidStr, 0x18);
        gt2Result = gt2Connect(*MC->pGt2Socket, 0, gt2AddressToString(MC->tempNewNodeInfo.gt2IP, MC->tempNewNodeInfo.gt2Port, 0),
                               (unsigned char *)pidStr, -1, 5000, MC->gt2Callbacks, 0);
        if (MC->inMeshMaking != 0 && gt2Result != 0) {
            DWCi_NodeInfoList_GetNodeInfoForProfileID(MC->tempNewNodeInfo.profileID)->nnTryCount++;
            DWCi_StopMeshMaking();
            DWCi_SetMatchStatus(1);
            return;
        }
        if (gt2Result == 1) {
            DWCi_HandleGT2Error(gt2Result);
            return;
        }
        if (gt2Result == 0)
            return;
        DWCi_CancelPreConnectedServerProcess(MC->tempNewNodeInfo.profileID);
        return;
        }

        if (remoteaddr != 0) {
            MC->tempNewNodeInfo.gt2IP = remoteaddr->addr.addr;
            {
                int p = remoteaddr->port;
                MC->tempNewNodeInfo.gt2Port = ((p >> 8) & 0xff) | ((p << 8) & 0xff00);
            }
        }
        tick = OS_GetTick();
        MC->nnFinishTime = tick;
        DWCi_SetMatchStatus(6);
        return;
    }

    if (nnInfo->cookie == 0)
        return;
    if (MC->inMeshMaking != 0) {
        DWCi_NodeInfoList_GetNodeInfoForProfileID(MC->tempNewNodeInfo.profileID)->nnTryCount++;
        DWCi_StopMeshMaking();
        DWCi_SetMatchStatus(1);
        return;
    }
    status = DWCi_HandleNNResult(result);
    if (status != 2 && status != 1 && status != 3)
        return;
    if (nnInfo->clientindex == 0) {
        if (status == 1 || status == 3 || (status == 2 && nnInfo->retryCount >= 1)) {
            NNCancel(MC->nnInfo.cookie);
            nnInfo->cookie = 0;
            if (DWCi_ProcessNNFailure(0) == 0)
                return;
            ((int (*)(int))DWCi_CancelPreConnectedClientProcess)(MC->tempNewNodeInfo.profileID);
            return;
        }
        nnInfo->retryCount++;
        DWCi_HandleNNError(DWCi_DoNatNegotiationAsync(nnInfo));
        return;
    }
    tick = OS_GetTick();
    MC->nnFailedTime = tick;
    if (status != 1 && status != 3) {
        if (status != 2)
            return;
        if (MC->nnSameCookieCount < 1)
            return;
    }
    NNCancel(MC->nnInfo.cookie);
    nnInfo->cookie = 0;
    if (MC->qr2MatchTypeExt == 3 || MC->qr2MatchTypeExt == 2) {
        if (DWCi_ProcessNNFailure(1) == 0)
            return;
    } else {
        if (DWCi_ProcessNNFailure(0) == 0)
            return;
    }
    MC->nnSameCookieCount = 0;
    MC->nnLastCookie = 0;
    MC->nnFailedTime = 0;
    DWCi_CancelPreConnectedServerProcess(MC->tempNewNodeInfo.profileID);
}


/*
 * sdk:      DWCi_ProcessNNFailure (dwc_match.o)
 */
int DWCi_ProcessNNFailure(int ignoreError)
{
    if (ignoreError)
        return 1;
    if (MC->qr2MatchTypeExt != 3)
        MC->nnFailureCount += 1;
    if (MC->qr2MatchTypeExt == 3 || MC->connectGroupID != 0 || MC->nnFailureCount >= 5) {
        DWCi_StopMatch(6, -86420);
        return 0;
    }
    return 1;
}


/*
 * sdk:      DWCi_SendServerDownQuery (dwc_match.o)
 */
int DWCi_SendServerDownQuery(void)
{
    int i;
    int result;
    int hostCount;
    unsigned int aidBitmap;
    DWCstNodeInfo *pNodeInfo;
    unsigned char command;

    DWCi_GetMatchCnt();
    hostCount = DWCi_NodeInfoList_GetCount();
    for (i = 1; i < hostCount; i++) {
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
        aidBitmap = DWC_GetAIDBitmap();
        if (MC->serverDownBuff & (1 << pNodeInfo->aid))
            command = 0x55;
        else
            command = 0x52;
        result = DWCi_SendMatchCommand(command, pNodeInfo->profileID, pNodeInfo->publicInetAddress, pNodeInfo->publicQueryPort, (const unsigned int *)(&aidBitmap), 1);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
    }
    DWCi_InitClWaitTimeout();
    return 1;
}


/*
 * DWCi_IsBackupMine: whether node 0 is this host's own profile.
 */
int DWCi_IsBackupMine(void)
{
    int r = 0;
    int *node = (int *)DWCi_NodeInfoList_GetNodeInfoForIndex(r);

    if (node != 0 && *node == MC->profileID) {
        r = 1;
    }
    return r;
}


unsigned int DWCi_CreateGroupID(void)
{
    return DWCi_GetMatchCnt()->profileID + DWCi_GetMathRand32(10000000) + 100000000;
}


/*
 * sdk:      DWCi_SetConnectionAttemptParam (dwc_match.o)
 */
void DWCi_SetConnectionAttemptParam(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    MC->attemptCallback = (int (*)(unsigned char *, int))attemptCallback;
    if (connectionUserData)
        memcpy(MC->connUserData, connectionUserData, 4);
    else
        memset(MC->connUserData, 0, 4);
    MC->attemptParam = (int)attemptParam;
}


/*
 * sdk:      DWCi_SetupGameServer_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void DWCi_SetupGameServer_InterChange(int init)
{
    DWCstNodeInfo *pMyNodeInfo;
    int matchType;
    int gpResult;

    if (init) {
        MC->groupID = func_02175530();
        pMyNodeInfo = (DWCstNodeInfo *)DWCi_NodeInfoList_GetMyNodeInfo();
        pMyNodeInfo->aid = 0;
        MC->isFirstServer = 1;
    }
    MC->qr2MatchType = 2;
    DWCi_SetMatchStatus(13);
    func_02175F84(2);
    MC->serverProfileID = 0;
    MC->qr2Flag18 = 0;
    if (MC->qr2MatchTypeExt == 0) {
        matchType = 3;
    } else if (MC->qr2MatchTypeExt == 1) {
        matchType = 4;
    } else {
        matchType = 6;
    }
    if (MC->qr2MatchTypeExt == 3)
        MC->qr2MatchTypeExt = 2;
    gpResult = DWCi_GPSetServerStatus(matchType);
    func_02173D28(gpResult);
    MC->reqProfileID = 0;
}


/*
 * sdk:      DWCi_ConnectToGameServerAsync_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void DWCi_ConnectToGameServerAsync_InterChange(void)
{
    int result;

    MC->qr2MatchType = 3;
    if (MC->sbObj == 0) {
        MC->sbObj = func_0219EC74(MC->gameName, MC->gameName,
                                              MC->secretKey, 0, 20, 1, 0,
                                              DWCi_SBCallback, 0);
    }
    if (MC->sbObj == 0) {
        if (DWCi_HandleSBError(5))
            return;
    }
    DWCi_SetMatchStatus(3);
    result = func_021719D0(MC->tempNewNodeInfo.profileID, 0);
    DWCi_HandleMatchCommandError(result);
}


void DWCi_GetNumConnectionHost(void)
{
    DWC_GetNumConnectionHost();
}


static int DWCi_RequestSuspendMatch(int suspend);


int DWCi_SendServerPolling(int immediate)
{
    u32 sendData[3];
    DWCstNodeInfo *pNodeInfo;
    int result;
    int i;
    u64 tick;

    if (!DWC_IsServerMyself())
        return 1;
    if (DWCi_GetMatchCnt()->state == 0x13 || DWCi_GetMatchCnt()->state == 0x14)
        return 1;
    if (immediate == 0) {
        tick = OS_GetTick();
        if (((tick - DWCi_GetMatchCnt()->serverPollingTime) * 64) / 33514 <= 15000)
            goto done;
    }
    sendData[0] = DWCi_GetMatchCnt()->profileID;
    sendData[1] = DWC_GetAIDBitmap();
    sendData[2] = DWCi_GetMatchCnt()->matchSessionID;
    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
        if (pNodeInfo != DWCi_NodeInfoList_GetMyNodeInfo()) {
            result = DWCi_SendMatchCommand(0x83, pNodeInfo->profileID, pNodeInfo->publicInetAddress, pNodeInfo->publicQueryPort, sendData, 3);
            if (DWCi_HandleMatchCommandError(result))
                return -1;
        }
    }
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->serverPollingTime = tick;
done:
    return 1;
}


static int DWCi_ProcessRequestMatch(u8 AID, int suspend, int immediate)
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
    pServerNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
    oldbitmap = DWCi_GetMatchCnt()->suspendBitmap;
    if (suspend)
        DWCi_GetMatchCnt()->suspendBitmap |= result << AID;
    else
        DWCi_GetMatchCnt()->suspendBitmap &= ~(result << AID);
    if (oldbitmap != DWCi_GetMatchCnt()->suspendBitmap)
        DWCi_GPSetServerStatus(-1);
    bitmap = DWCi_GetMatchCnt()->suspendBitmap;
    if (!DWCi_IsServerSuspendEnabled())
        bitmap &= ~(result << DWC_GetMyAID());
    sm = DWC_GetSuspendMatch();
    bRet = 1;
    if (!((suspend && sm) || (!suspend && !sm)))
        bRet = 0;
    if (immediate == 1) {
        DWCstNodeInfo *pNodeInfo;

        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForAID(AID);
        senddata[sendlen++] = DWCi_GetMatchCnt()->profileID;
        senddata[sendlen++] = result;
        if (bRet) {
            if (DWCi_GetMatchCnt()->suspendReqPending != 0) {
                senddata[sendlen++] = suspend;
                senddata[sendlen++] = bitmap;
            }
        }
        result = DWCi_SendMatchCommand(0x82, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                               pNodeInfo->publicQueryPort, senddata, sendlen);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
    }
    if (bRet) {
        if (DWCi_GetMatchCnt()->suspendReqPending != 1) {
            DWCi_GetMatchCnt()->suspendReqPending = 1;
            senddata[0] = DWCi_GetMatchCnt()->profileID;
            senddata[1] = 1;
            senddata[2] = suspend;
            senddata[3] = bitmap;
            for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
                DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);

                if (pNodeInfo != pServerNodeInfo) {
                    result = DWCi_SendMatchCommand(0x82, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                                           pNodeInfo->publicQueryPort, senddata, 4);
                    if (DWCi_HandleMatchCommandError(result))
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
int DWCi_StartMatch(void)
{
    int result;
    int sbError;

    if (DWCi_GetMatchCnt()->sbObj != 0)
        func_0219F00C(DWCi_GetMatchCnt()->sbObj);
    if (DWCi_GetMatchCnt()->connectGroupID != 0) {
        DWCi_SetMatchStatus(0xc);
    } else if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0) {
        DWCi_SetMatchStatus(2);
    } else if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        DWCi_SetMatchStatus(3);
        result = 1;
        if (DWCi_HandleMatchCommandError(func_02171C08(0, 1, 0)))
            result = 0;
        return result;
    } else if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2) {
        DWCi_SetMatchStatus(0xd);
        DWCi_GetMatchCnt()->connectionEstablished = 1;
        return 1;
    } else if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
            DWCi_SetMatchStatus(3);
            result = DWCi_HandleMatchCommandError(func_021719D0(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID, 0));
            if (result)
                return 0;
        }
        return 1;
    }
    DWCi_GetMatchCnt()->reqProfileID = 0;
    sbError = DWCi_HandleSBError(DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->reqProfileID));
    result = 0;
    if (sbError == 0)
        result = 1;
    return result;
}


/*
 * sdk:      DWCi_RequestSuspendMatchInit (dwc_match.o)
 */
void DWCi_RequestSuspendMatchInit(int suspend, void (*callback)(int, int, void *), void *suspendResultParam)
{
    DWCi_GetMatchCnt()->suspendReqPending = 0;
    DWCi_GetMatchCnt()->suspendRequest = suspend;
    DWCi_GetMatchCnt()->suspendCallback = callback;
    DWCi_GetMatchCnt()->suspendResultParam = suspendResultParam;
    DWCi_GetMatchCnt()->suspendRequestTick = 0;
    {
        u64 tick = OS_GetTick();
        DWCi_GetMatchCnt()->suspendStartTick = tick;
    }
    DWCi_GetMatchCnt()->suspendActive = 1;
}


/*
 * sdk:      DWCi_RequestSuspendMatchProcess (dwc_match.o)
 */
int DWCi_RequestSuspendMatchProcess(void)
{
    int ret;
    int suspend;

    if (DWCi_GetMatchCnt()->suspendActive == 0)
        return 0;
    if (DWCi_GetMatchCnt()->suspendRestart != 0) {
        DWCi_RequestSuspendMatchInit(DWCi_GetMatchCnt()->suspendRequest, DWCi_GetMatchCnt()->suspendCallback, DWCi_GetMatchCnt()->suspendResultParam);
        DWCi_GetMatchCnt()->suspendRestart = 0;
    }
    suspend = DWCi_GetMatchCnt()->suspendRequest;
    if (suspend == 0xff)
        return 0;
    ret = DWC_GetSuspendMatch();
    if ((suspend != 0 && ret != 0) || (suspend == 0 && ret == 0)) {
        DWCi_SuspendComplete(0);
        return 1;
    }
    DWCi_RequestSuspendMatch(suspend);
    return 1;
}


/*
 * sdk:      DWCi_RequestSuspendMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The object reads the tick before it calls func_02175F3C for the store, which
 * a block-local copy reproduces (the DWARF lists no tick variable).
 */
static int DWCi_RequestSuspendMatch(int suspend)
{
    DWCstNodeInfo *pServerNodeInfo;
    DWCstNodeInfo *pMyNodeInfo;
    u32 senddata[4];
    int result;

    if (func_02175FB8() == 2)
        return DWCi_ProcessRequestMatch(DWCi_NodeInfoList_GetMyNodeInfo()->aid, suspend, 0);
    if (DWCi_GetMatchCnt()->state != 1)
        return 1;
    if (DWCi_GetMatchCnt()->suspendReqPending) {
        if (((OS_GetTick() - DWCi_GetMatchCnt()->suspendRequestTick) * 64) / 33514 < DWCi_GetMatchCnt()->suspendRetryDelayMs)
            return 1;
    }
    if (((OS_GetTick() - DWCi_GetMatchCnt()->suspendRequestTick) * 64) / 33514 > 3000) {
        pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
        pServerNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        senddata[0] = DWCi_GetMatchCnt()->profileID;
        senddata[1] = 0;
        senddata[2] = suspend;
        senddata[3] = pMyNodeInfo->aid;
        result = DWCi_SendMatchCommand(0x82, pServerNodeInfo->profileID, pServerNodeInfo->publicInetAddress,
                               pServerNodeInfo->publicQueryPort, senddata, 4);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
        {
            u64 now = OS_GetTick();
            DWCi_GetMatchCnt()->suspendRequestTick = now;
        }
        DWCi_GetMatchCnt()->suspendRetryDelayMs = 3000;
    }
    return 1;
}


/*
 * sdk:      DWCi_IsServerSuspendEnabled (dwc_match.o)
 */
int DWCi_IsServerSuspendEnabled(void)
{
    if (DWC_IsServerMyself()) {
        if (DWCi_GetMatchCnt()->state == 13 || DWCi_GetMatchCnt()->state == 22)
            return 1;
        return 0;
    }
    return 1;
}


/*
 * True while the match state is 9, 10 or 11.
 */
int DWCi_IsServerChanging(void)
{
    unsigned int v = DWCi_GetMatchCnt()->state - 9;
    return v <= 2;
}


/*
 * Stores the match control block and the tick it was stored at.
 */
void DWCi_SetMatchCnt(DWCstMatchControl *a)
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
DWCstMatchControl *DWCi_GetMatchCnt(void)
{
    return g_021AAA20.pMatch;
}


/*
 * DWCi_SetMatchStatus: records the new match state, logging a change first.
 */
void DWCi_SetMatchStatus(int state)
{
    if (g_021AAA20.pMatch->state != state) {
        disp_match_state(g_021AAA20.pMatch->state, state);
    }
    g_021AAA20.pMatch->state = state;
}


void DWCi_SetHostStatus(int host)
{
    g_021AAA20.pMatch->qr2HostState = host;
    if (DWCi_GetMatchCnt()->qr2Obj != 0)
        qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}


unsigned char func_02175FB8(void)
{
    return DWCi_GetMatchCnt()->qr2HostState;
}


/*
 * Cleared when the word at +0x7b0 of the module block is one.
 */
int DWCi_IsServerChangeEnabled(void)
{
    return DWCi_GetMatchCnt()->topologyType != 1;
}


/*
 * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record.
 */
void DWCi_ResetLastSomeDataRecvTimeByAidAll(void)
{
    int i;

    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        func_02177748(DWCi_NodeInfoList_GetNodeInfoForIndex(i)->aid);
    }
}


/*
 * Clears the node count and the node list.
 */
void DWCi_NodeInfoList_Clear(void)
{
    MI_CpuFill8(&DWCi_GetMatchCnt()->nodeCount, 0, 0x504);
}


/*
 * Word at +0x50 of the block func_02175F3C returns.
 */
int DWCi_NodeInfoList_GetCount(void)
{
    return DWCi_GetMatchCnt()->nodeCount;
}


/*
 * sdk:      DWCi_NodeInfoList_InsertToTop (dwc_match.o)
 */
int DWCi_NodeInfoList_InsertToTop(DWCstNodeInfo *newNode)
{
    int i;

    if (DWCi_GetMatchCnt()->nodeCount == 32)
        return 0;
    for (i = DWCi_GetMatchCnt()->nodeCount; i > 0; i--)
        DWCi_GetMatchCnt()->nodeInfoList[i] = DWCi_GetMatchCnt()->nodeInfoList[i - 1];
    DWCi_GetMatchCnt()->nodeInfoList[0] = *newNode;
    DWCi_GetMatchCnt()->nodeCount += 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_Append (dwc_match.o)
 */
int DWCi_NodeInfoList_Append(DWCstNodeInfo *newNode)
{
    if (DWCi_GetMatchCnt()->nodeCount == 32)
        return 0;
    DWCi_GetMatchCnt()->nodeInfoList[DWCi_GetMatchCnt()->nodeCount] = *newNode;
    DWCi_GetMatchCnt()->nodeCount += 1;
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
int DWCi_NodeInfoList_RemoveAID(unsigned char aid)
{
    int removeAidIndex;
    int i;
    DWCstMatchControl *d;
    DWCstMatchControl *s;

    if (DWCi_GetMatchCnt()->nodeCount == 0) return 0;
    for (removeAidIndex = 0; removeAidIndex < DWCi_GetMatchCnt()->nodeCount;
         removeAidIndex++) {
        if (aid == DWCi_GetMatchCnt()->nodeInfoList[removeAidIndex].aid)
            break;
    }
    if (removeAidIndex == DWCi_GetMatchCnt()->nodeCount) return 0;
    for (i = removeAidIndex; i < DWCi_GetMatchCnt()->nodeCount - 1; ) {
        u8 *a = (u8 *)DWCi_GetMatchCnt();
        u8 *b = (u8 *)DWCi_GetMatchCnt();
        d = (DWCstMatchControl *)(a + i * 0x28);
        i++;
        s = (DWCstMatchControl *)(b + i * 0x28);
        d->nodeInfoList[0] = s->nodeInfoList[0];
    }
    DWCi_GetMatchCnt()->nodeCount -= 1;
    return 1;
}


/*
 * sdk:      DWCi_NodeInfoList_RemoveProfileID (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int DWCi_NodeInfoList_RemoveProfileID(int profileID)
{
    int removeIndex;

    if (DWCi_GetMatchCnt()->nodeCount == 0)
        return 0;
    for (removeIndex = 0; removeIndex < DWCi_GetMatchCnt()->nodeCount; removeIndex++) {
        if (profileID == DWCi_GetMatchCnt()->nodeInfoList[removeIndex].profileID)
            break;
    }
    if (removeIndex == DWCi_GetMatchCnt()->nodeCount)
        return 0;
    for (; removeIndex < DWCi_GetMatchCnt()->nodeCount - 1; removeIndex++)
        DWCi_GetMatchCnt()->nodeInfoList[removeIndex] = DWCi_GetMatchCnt()->nodeInfoList[removeIndex + 1];
    DWCi_GetMatchCnt()->nodeCount--;
    return 1;
}


/*
 * DWCi_NodeInfoList_GetMyNodeInfo: the node record of this host.
 */
DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void)
{
    return DWCi_NodeInfoList_GetNodeInfoForProfileID(DWCi_GetMatchCnt()->profileID);
}


/*
 * The first node record, or null when the list is empty.
 */
DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void)
{
    DWCstMatchControl *p = DWCi_GetMatchCnt();
    if (p->nodeCount < 1) return 0;
    return DWCi_GetMatchCnt()->nodeInfoList;
}


/*
 * DWCi_NodeInfoList_GetNodeInfoForIndex: the node record at an index, or null past the count.
 */
DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index)
{
    if (index >= DWCi_GetMatchCnt()->nodeCount) {
        return 0;
    }
    return &DWCi_GetMatchCnt()->nodeInfoList[index];
}


/*
 * DWCi_NodeInfoList_GetNodeInfoForProfileID: the node record whose profile id matches, or null.
 */
DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid)
{
    int i;

    for (i = 0; i < DWCi_GetMatchCnt()->nodeCount; i++) {
        if (pid == DWCi_GetMatchCnt()->nodeInfoList[i].profileID) {
            return &DWCi_GetMatchCnt()->nodeInfoList[i];
        }
    }
    return 0;
}


/*
 * sdk:      DWCi_NodeInfoList_GetNodeInfoForAID (dwc_match.o)
 *
 * Extra open callee of DWCi_DeleteAID (0x0216BCA4).
 */
DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid)
{
    int i;

    for (i = 0; i < DWCi_GetMatchCnt()->nodeCount; i++) {
        if (aid == DWCi_GetMatchCnt()->nodeInfoList[i].aid)
            return &DWCi_GetMatchCnt()->nodeInfoList[i];
    }
    return 0;
}


/*
 * sdk:      DWCi_NodeInfoList_GetFreeAID (dwc_match.o)
 */
unsigned char DWCi_NodeInfoList_GetFreeAID(void)
{
    unsigned char i;
    int j;

    if (DWCi_GetMatchCnt()->nodeCount == 32)
        return 0xff;
    for (i = 0; i < 32; i++) {
        for (j = 0; j < DWCi_GetMatchCnt()->nodeCount; j++) {
            if (i == DWCi_GetMatchCnt()->nodeInfoList[j].aid)
                break;
        }
        if (j == DWCi_GetMatchCnt()->nodeCount)
            return i;
    }
    return 0xff;
}


int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID)
{
    DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID);

    if (pNodeInfo == 0)
        return 0;
    if (pNodeInfo == DWCi_NodeInfoList_GetMyNodeInfo())
        return 0;
    return DWCi_GetGT2Connection(pNodeInfo->aid) == 0;
}


/*
 * Clears the new-node record.
 */
void DWCi_TempNewNodeInfo_Clear(void)
{
    DWCi_NodeInfo_Clear(&DWCi_GetMatchCnt()->tempNewNodeInfo);
}


/*
 * True when the new-node record is in use.
 */
int DWCi_TempNewNodeInfo_IsValid(void)
{
    return DWCi_NodeInfo_IsValid(&DWCi_GetMatchCnt()->tempNewNodeInfo);
}


/*
 * Clears a node record.
 */
void DWCi_NodeInfo_Clear(DWCstNodeInfo *p)
{
    MI_CpuFill8(p, 0, 0x28);
}


/*
 * True when the node record has a profile id.
 */
int DWCi_NodeInfo_IsValid(const DWCstNodeInfo *p)
{
    return p->profileID != 0;
}


/*
 * sdk:      DWCi_GetNextMeshMakeTryTick (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
unsigned long long DWCi_GetNextMeshMakeTryTick(void)
{
    int existGT2Count;
    int i;
    int myNodeIndex;
    DWCstNodeInfo *pMyNodeInfo;
    unsigned long long tick;
    DWCstNodeInfo *pNodeInfo;

    pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
    tick = OS_GetTick();
    tick += 0x17F898;
    existGT2Count = 0;
    myNodeIndex = 0;
    if (DWCi_NodeInfoList_GetCount() > 2) {
        for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
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
    tick += ((unsigned long long)((DWCi_NodeInfoList_GetCount() - 1 - myNodeIndex) * 6000) * 33514) >> 6;
    return tick;
}


/*
 * DWCi_StopMeshMaking: abandons the mesh step in progress, cancelling any NAT negotiation.
 */
int DWCi_StopMeshMaking(void)
{
    if (DWCi_GetMatchCnt()->inMeshMaking == 0) {
        return 0;
    }
    DWCi_GetMatchCnt()->inMeshMaking = 0;
    DWCi_GetMatchCnt()->backupState = DWCi_GetMatchCnt()->state;
    if (DWCi_TempNewNodeInfo_IsValid() != 0) {
        *(DWCstNodeInfo *)&DWCi_GetMatchCnt()->backupProfileID = DWCi_GetMatchCnt()->tempNewNodeInfo;
    } else {
        MI_CpuFill8(&DWCi_GetMatchCnt()->backupProfileID, 0, 0x28);
    }
    if (DWCi_GetMatchCnt()->nnInfo.cookie != 0) {
        func_02199FB4(DWCi_GetMatchCnt()->nnInfo.cookie);
        DWCi_GetMatchCnt()->nnInfo.cookie = 0;
        DWCi_GetMatchCnt()->nnSameCookieCount = 0;
        DWCi_GetMatchCnt()->nnLastCookie = 0;
        DWCi_GetMatchCnt()->nnFailedTime = 0;
    }
    if (DWCi_GetMatchCnt()->state == 3 || DWCi_GetMatchCnt()->state == 5 ||
        DWCi_GetMatchCnt()->state == 6 || DWCi_GetMatchCnt()->state == 14 ||
        DWCi_GetMatchCnt()->state == 15) {
        if (DWCi_GetMatchCnt()->reqProfileID != 0) {
            if (DWCi_HandleMatchCommandError(DWCi_CancelReservation(0)) != 0) {
                DWCi_TempNewNodeInfo_Clear();
                return 1;
            }
        }
        DWCi_GetMatchCnt()->qr2Flag18 = 0;
        DWCi_GetMatchCnt()->serverProfileID = 0;
    }
    DWCi_TempNewNodeInfo_Clear();
    return 1;
}


/*
 * Word at +0x7c4 of the block func_02175F3C returns.
 */
int DWCi_IsFirstServer(void)
{
    return DWCi_GetMatchCnt()->isFirstServer;
}


/*
 * Whether this host is the server of a running match that has not been the first server.
 */
int DWCi_IsServerLocked(void)
{
    if (DWCi_GetMatchCnt()->serverLockEnabled == 0) {
        return 0;
    }
    if (DWC_IsServerMyself() != 0 &&
        (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 3 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 2) &&
        DWCi_IsFirstServer() == 0) {
        return 1;
    }
    return 0;
}


/*
 * Word at +0x7b0 of the block func_02175F3C returns.
 */
int DWCi_GetTopologyType(void)
{
    return DWCi_GetMatchCnt()->topologyType;
}


void DWCi_ClearMeshMakingTempInfo(void)
{
    DWCi_GetMatchCnt()->backupState = 0;
    MI_CpuFill8(&DWCi_GetMatchCnt()->backupProfileID, 0, 0x28);
}


void DWCi_AutoSuspendComplete(void)
{
    if (DWCi_GetMatchCnt()->suspendRequest == 0xff)
        return;
    if (DWCi_GetMatchCnt()->suspendRequest == 1)
        DWCi_GetMatchCnt()->suspendBitmap = DWC_GetAIDBitmap();
    else
        DWCi_GetMatchCnt()->suspendBitmap = 0;
    DWCi_SuspendComplete(0);
}


/*
 * sdk:      DWCi_SuspendComplete (dwc_match.o)
 */
void DWCi_SuspendComplete(int result)
{
    if (DWCi_GetMatchCnt()->suspendCallback != 0)
        DWCi_GetMatchCnt()->suspendCallback(result, DWCi_GetMatchCnt()->suspendRequest, DWCi_GetMatchCnt()->suspendResultParam);
    if (result == 0)
        qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
    DWCi_GetMatchCnt()->suspendRequest = 0xff;
    DWCi_GetMatchCnt()->suspendActive = 0;
}


/*
 * Set when the word at +0x7b0 of the module block is two.
 */
int DWCi_IsFullMesh(void)
{
    return DWCi_GetMatchCnt()->topologyType == 2;
}


int DWCi_GetNodeInfoCount(void)
{
    return DWCi_NodeInfoList_GetCount();
}


unsigned char DWCi_IsLockedBuddyStatus(char *a0)
{
    char buf[4] = {0};
    unsigned char r = 0;

    if (func_021684CC((char *)0x021A208Cu, buf, a0 + 8, 0x2F) > 0)
        r = (unsigned char)sub_02095EAC((u32)buf, 0, 10);
    return r;
}


/*
 * sdk:      DWCi_GetResvDenyReasonString (dwc_match.o)
 */
char *DWCi_GetResvDenyReasonString(unsigned char denyReason)
{
    switch (denyReason) {
    case 0x10:
        return g_021A21C8;
    case 0x11:
        return g_021A21E8;
    case 0x12:
        return g_021A2208;
    case 0x13:
        return g_021A222C;
    case 0x14:
        return g_021A224C;
    case 0x15:
        return g_021A2280;
    case 0x16:
        return g_021A22C4;
    case 0x17:
        return g_021A22F0;
    case 0x18:
        return g_021A2324;
    default:
        return g_021A2340;
    }
}


/*
 * Stores both words the call returns into the module state block.
 */
void disp_match_state(int a, int b)
{
    unsigned long long v = func_020870D0();

    *(int *)(((char *)&g_021AAA20) + 0x18) = (int)v;
    *(int *)(((char *)&g_021AAA20) + 0x1c) = (int)(v >> 32);
}


/*
 * Stores the argument at +0x678 of the module block.
 */
void DWCi_SetMatchmakeProfileId(int v)
{
    DWCi_GetMatchCnt()->profileID = v;
}


/*
 * sdk:      DWCi_RegisterMatchmakeKeys (dwc_match.o)
 */
void DWCi_RegisterMatchmakeKeys(void)
{
    func_0219D158(0x32, g_021A20A4);
    func_0219D158(0x33, g_021A2170);
    func_0219D158(0x34, g_021A2164);
    func_0219D158(0x35, g_021A21BC);
    func_0219D158(0x36, g_021A20D4);
    func_0219D158(0x37, g_021A20E0);
    func_0219D158(0x38, g_021A217C);
}


void DWCi_NNFreeNegotiateList(void)
{
    NNCancel(DWCi_GetMatchCnt()->nnInfo.cookie);
    if (g_021AAA20.bInNNThink != 0) {
        g_021AAA20.bNNFreeNegotiateList = 1;
    } else {
        NNFreeNegotiateList();
    }
}
