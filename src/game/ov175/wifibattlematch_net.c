/*
 * file:     wifibattlematch_net.c
 * unit:     yes
 * function: clear, release, WIFIBATTLEMATCH_NET_CreateNetContext, WIFIBATTLEMATCH_NET_DeleteNetContext, WIFIBATTLEMATCH_NET_Noop, WIFIBATTLEMATCH_NET_SetTimingSyncRange, WIFIBATTLEMATCH_NET_IsTimingSyncRange, WIFIBATTLEMATCH_NET_HandleNetError, WIFIBATTLEMATCH_NET_ClearErrorFlags, WIFIBATTLEMATCH_NET_StepGdbEnsureRecord, WIFIBATTLEMATCH_NET_SetMatchKey, WIFIBATTLEMATCH_NET_StartMatchmaking, WIFIBATTLEMATCH_NET_DisconnectWifi, WIFIBATTLEMATCH_NET_ClearCancelFlag, WIFIBATTLEMATCH_NET_StopMatchmaking, WIFIBATTLEMATCH_NET_SendSessionQuery, WIFIBATTLEMATCH_NET_TakeSessionResult, WIFIBATTLEMATCH_NET_GetDateTime, WIFIBATTLEMATCH_NET_AddMatchKey, WIFIBATTLEMATCH_NET_GetMatchKeyInt, WIFIBATTLEMATCH_NET_GetMatchKeyDefault, WIFIBATTLEMATCH_NET_GetMatchKeyValue, WIFIBATTLEMATCH_NET_SetupMatchReport, WIFIBATTLEMATCH_NET_ScProcess, WIFIBATTLEMATCH_NET_GetReportState, WIFIBATTLEMATCH_NET_OnReportResultA, WIFIBATTLEMATCH_NET_OnReportResultB, WIFIBATTLEMATCH_NET_OnReportResultC, WIFIBATTLEMATCH_NET_ShutdownReport, WIFIBATTLEMATCH_NET_SubmitReport, WIFIBATTLEMATCH_NET_ReportAddRecord, WIFIBATTLEMATCH_NET_ReportAddTeam, WIFIBATTLEMATCH_NET_ReportAddWin, WIFIBATTLEMATCH_NET_ReportAddLoss, WIFIBATTLEMATCH_NET_ReportAddDisconnectWin, WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss, WIFIBATTLEMATCH_NET_OnRecvPlayerData, WIFIBATTLEMATCH_NET_OnRecvStatus, WIFIBATTLEMATCH_NET_GetPlayerBuffer, WIFIBATTLEMATCH_NET_OnRecvFlagA, WIFIBATTLEMATCH_NET_OnRecvFlagB, WIFIBATTLEMATCH_NET_OnRecvFlagC, WIFIBATTLEMATCH_NET_OnRecvValue, WIFIBATTLEMATCH_NET_GdbRequest, WIFIBATTLEMATCH_NET_GdbGetMyRecords, WIFIBATTLEMATCH_NET_GdbShutdown, WIFIBATTLEMATCH_NET_SetupGdbRecord, WIFIBATTLEMATCH_NET_GdbSortByName, WIFIBATTLEMATCH_NET_GdbCopyFieldsA, WIFIBATTLEMATCH_NET_GdbCopyFieldsB, WIFIBATTLEMATCH_NET_GdbCopyFieldC, WIFIBATTLEMATCH_NET_GdbCopyFieldD, WIFIBATTLEMATCH_NET_GdbCopyFieldE, WIFIBATTLEMATCH_NET_SetupGdbUpload, WIFIBATTLEMATCH_NET_GdbUpdateRecord, WIFIBATTLEMATCH_NET_GdbClearRecord, WIFIBATTLEMATCH_NET_GdbCreateRecord, WIFIBATTLEMATCH_NET_GetNetId, WIFIBATTLEMATCH_NET_SendRegData, WIFIBATTLEMATCH_NET_TakeRegData, WIFIBATTLEMATCH_NET_SendRegDataAlt, WIFIBATTLEMATCH_NET_TakeRegBuffer, WIFIBATTLEMATCH_NET_SendRegFlag, WIFIBATTLEMATCH_NET_TakeRegFlag, WIFIBATTLEMATCH_NET_SendRegValue, WIFIBATTLEMATCH_NET_TakeRegValue, WIFIBATTLEMATCH_NET_SetupDownload, WIFIBATTLEMATCH_NET_DownloadProcess, WIFIBATTLEMATCH_NET_IsBufferZero, WIFIBATTLEMATCH_NET_CleanupDownload, WIFIBATTLEMATCH_NET_GetDownloadSize, WIFIBATTLEMATCH_NET_DownloadError, WIFIBATTLEMATCH_NET_GetRegCardName, WIFIBATTLEMATCH_NET_NdSetState, WIFIBATTLEMATCH_NET_NdCleanupState, WIFIBATTLEMATCH_NET_NdCancelState, WIFIBATTLEMATCH_NET_NdSetError, WIFIBATTLEMATCH_NET_CreateHttpRap, WIFIBATTLEMATCH_NET_HttpRapProcess, WIFIBATTLEMATCH_NET_GetRapPair, WIFIBATTLEMATCH_NET_SetupHttpRap, WIFIBATTLEMATCH_NET_HttpRapSend, WIFIBATTLEMATCH_NET_StartProfanityCheck, WIFIBATTLEMATCH_NET_ProfanityProcess, WIFIBATTLEMATCH_NET_SetupPostData, WIFIBATTLEMATCH_NET_HttpRapPost, WIFIBATTLEMATCH_NET_SetErrorA, WIFIBATTLEMATCH_NET_SetErrorB, WIFIBATTLEMATCH_NET_SetResultA, WIFIBATTLEMATCH_NET_SetResultB, WIFIBATTLEMATCH_NET_SetResultC, WIFIBATTLEMATCH_NET_SetResultD, WIFIBATTLEMATCH_NET_GetErrorMsg, WIFIBATTLEMATCH_NET_GetErrorCode, WIFIBATTLEMATCH_NET_MapErrorCode, WIFIBATTLEMATCH_NET_ClearStruct, WIFIBATTLEMATCH_NET_RestartNet, WIFIBATTLEMATCH_NET_GetGsProfileId, WIFIBATTLEMATCH_NET_GetRegNameA, WIFIBATTLEMATCH_NET_GetRegKindA, WIFIBATTLEMATCH_NET_GetRegNameB, WIFIBATTLEMATCH_NET_GetRegKindB, WIFIBATTLEMATCH_NET_LookupFieldEntry
 * address:  0x021D9DC8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   ov177_id 0x000000B1 data
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GF_PANIC_Fail 0x02034714 arm
 *   d_021E2C74 0x021E2C74 data a4
 *   d_021E2C80 0x021E2C80 data a4
 *   d_021E2DE0 0x021E2DE0 data
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   ov114_id 0x00000072 data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_GRAPHIC_Create 0x021E5440 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_GetCamera 0x021E5548 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_Create 0x021E567C thumb ov177
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_Create 0x0201EC74 thumb
 *   WIFIBATTLEMATCH_UTIL_Create 0x021E8568 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CreateCallback 0x021E8A3C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreateActorArray 0x021E7D20 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_SetActorVisible 0x021E7E0C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteActorArray 0x021E7DF0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_DeleteCallback 0x021E8A78 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_Delete 0x021E8628 thumb ov177
 *   WORDSET_Delete 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   WIFIBATTLEMATCH_VIEW_Delete 0x021E5868 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Delete 0x021E54E0 thumb ov177
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   WIFIBATTLEMATCH_UTIL_InvokeCallback 0x021E8A80 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_IsCallbackNull 0x021E8A90 thumb ov177
 *   WIFIBATTLEMATCH_GRAPHIC_Draw 0x021E5534 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_Main 0x021E867C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_Noop 0x021E7E08 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateAnimation 0x021E5980 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdatePokeList 0x021E64C0 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_UpdateRecordWindow 0x021E7774 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_PrintMessage 0x021E8738 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_SetRequest 0x021E8AB4 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_GetBusy 0x021E8844 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CommitRequest 0x021E8AB8 thumb ov177
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_SYNC_GetBlock 0x02009448 thumb
 *   BLOCK20_SAVEDATA_GetPending 0x020092EC thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_ToChars 0x02045A38 arm
 *   STRBUF_Delete 0x02045808 arm
 *   NATION_AREA_IsValidNationArea 0x02025BEC thumb
 *   PMSI_PARAM_IsValid 0x020245D4 thumb
 *   PMSI_PARAM_InitSentence 0x020242A4 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 *   DWC_RAPCOMMON_CreateSubHeap 0x02156E30 thumb
 *   DWC_RAPCOMMON_SetHeapTag 0x02156F50 thumb
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb
 *   TRADE_HISTORY_GetFromSave 0x02009EC8 thumb
 *   WIFIBATTLEMATCH_UTIL_SetSaveState 0x021E8AC0 thumb ov177
 *   MET_TRAINERS_GetFromSave 0x0200ED48 thumb
 *   MET_TRAINERS_Insert 0x0200ED54 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   GFL_NET_ERR_WaitLinkClosed 0x0200FBB0 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   BSUBWAY_SAVEDATA_GetStat 0x0200DFD8 thumb
 *   MYSTATUS_GetTrainerView 0x02008554 thumb
 *   WIFIBATTLEMATCH_VIEW_CreateMainWindow 0x021E5C20 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteMainWindow   0x021E5D40  thumb
 *   WIFIBATTLEMATCH_UTIL_DeleteMenu   0x021E89D0  thumb
 *   WIFIBATTLEMATCH_UTIL_UpdateMenu   0x021E8A00  thumb
 *   WIFIBATTLEMATCH_VIEW_DeleteStatusWindow   0x021E5EF8  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_DrawStatusWindow   0x021E5F24  thumb
 *   WIFIBATTLEMATCH_VIEW_StepMainWindow  0x021E64C8  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_StepMainWindowIdle  0x021E65FC  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_CreateRecordWindow 0x021E7520 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeleteRecordWindow   0x021E7710  thumb
 *   WIFIBATTLEMATCH_VIEW_StepRecordWindow 0x021E777C thumb ov177
 *   BSUBWAY_SAVEDATA_SetStat 0x0200DFE4 thumb
 *   BSUBWAY_SAVEDATA_IncStat  0x0200E008  thumb
 *   WIFIBATTLEMATCH_UTIL_ShowMenu 0x021E888C thumb ov177
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GREETING_SAVEDATA_GetFromSaveThunk 0x0200E6E8 thumb
 *   GREETING_SAVEDATA_GetSentence 0x0200E6FC thumb
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   WIFILIST_GetGsProfileId 0x02009CC0 thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   NHTTP_RAP_EvilCheckAllocArray 0x021B9A64 thumb ov114
 *   NHTTP_RAP_EvilCheckSetElement 0x021B9A94 thumb ov114
 *   NHTTP_RAP_VerifySignature 0x021B9A1C thumb ov114
 *   NHTTP_RAP_EvilCheckFreeArray 0x021B9A8C thumb ov114
 *   KEY_GetTrg                0x020362DC  arm
 *   GFL_NET_ERR_GetErrorLevel                0x0200FB24  thumb
 *   GFL_NET_GetRunState                0x0203CD98  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   BATTLE_COMPETITION_GetFromSave 0x0200B358 thumb
 *   REGULATION_GetCard 0x0200B1D4 thumb
 *   POKEPARTY_Create 0x0201A920 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   WIFIBATTLEMATCH_VIEW_UpdatePartyWindow 0x021E84F8 thumb ov177
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   REGULATION_NoOp 0x0200AE14 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   REGULATION_GetParty 0x0200B204 thumb
 *   BATTLE_BOX_CreateParty 0x0200BAF4 thumb
 *   BATTLE_BOX_SetLockFlags 0x0200BBC8 thumb
 *   REGULATION_Card_SetValue 0x0200B110 thumb
 *   REGULATION_BuildParty 0x0200B2A4 thumb
 *   REGULATION_Card_GetValue 0x0200B078 thumb
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   BATTLE_BOX_IsLocked 0x0200BBFC thumb
 *   BATTLE_BOX_ClearLockFlags 0x0200BBD8 thumb
 *   REGULATION_InitParty 0x0200B1F8 thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   BUTTON_MAN_ConvertUcs2ToSjis  0x02052274  arm
 *   DWC_GetDateTime 0x02167ED8 arm ov009
 *   RTC_ConvertDateTimeToSecond 0x02089004 arm
 *   RTC_ConvertSecondToDateTime 0x020891E0 arm
 *   RTC_ConvertDateToDay 0x02088F58 arm
 *   GFL_NET_ERR_HaltIfActive 0x0200FA84 thumb
 *   REGULATION_Card_GetCupName  0x0200B074  thumb
 *   WIFIBATTLEMATCH_VIEW_CreateStatusWindow  0x021E5D68  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_CreatePartyWindow 0x021E7E3C thumb ov177
 *   WIFIBATTLEMATCH_VIEW_DeletePartyWindow  0x021E82BC  thumb  ov177
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindow 0x021E8338 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt 0x021E8420 thumb ov177
 *   WIFIBATTLEMATCH_UTIL_CreateMenu 0x021E88B0 thumb ov177
 *   POKEPARTY_Init 0x0201A948 thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   REGULATION_Card_CalcCrc  0x0200B1C4  thumb
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb
 *   POKE_TOOL_GetBoxParamSize  0x020173E8  thumb
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   WIFILIST_GetWork 0x02009860 thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   d_021E2EE0 0x021E2EE0 data a4
 *   d_021E2EF8 0x021E2EF8 data a4
 *   d_021E2C90 0x021E2C90 data a4
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_SetAutoExit  0x0203D7B0  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_DATA_SaveCancel  0x02012E08  thumb
 *   GFL_NET_ERR_HaltWithMessage  0x0200F7C0  thumb
 *   DWC_RAPCOMMON_HandleNetError  0x02157170  thumb
 *   GFL_NET_STATE_ClearErrorMode  0x0203C968  arm
 *   GFL_NET_STATE_SetWifiError  0x0203CA04  arm
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   GFL_NET_ERR_ResetState  0x0200FBA0  thumb
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_ERR_RecordError  0x0200FAAC  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   STD_TSPrintf                 0x0208D7E0  arm
 *   d_021E2EFC                   0x021E2EFC  data
 *   DWC_RAP_StartMatchWithFilter  0x0215580C  thumb
 *   GFL_NET_STATE_WifiEnterRandomMatch  0x0203C304  arm
 *   DWC_RAP_SetVchatEnabled  0x02156BC4  thumb
 *   GFL_NET_STATE_WifiDisconnect  0x0203C554  arm
 *   GFL_NET_STATE_GetWifiState  0x0203C3EC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   GFL_NET_HANDLE_GetNegotiationNum  0x020399EC  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   DWC_RAP_IsStateInSession  0x02156CD0  thumb  ov009
 *   g_021E2C8C     0x021E2C8C  data
 *   DWC_AddMatchKeyInt  0x0216C8DC  arm  ov009
 *   d_021E2E10          0x021E2E10  data
 *   DWC_GetMatchIntValue  0x0216CB30  arm
 *   DWC_ScInitialize 0x021DEE3C arm ov175
 *   DWC_ScGetLoginCertificate 0x021DF490 arm ov175
 *   DWC_ScCreateSessionAsync 0x021DF018 arm ov175
 *   DWC_ScGetSessionId 0x021DF20C arm ov175
 *   DWC_ScProcess 0x021DEFDC arm ov175
 *   DWC_ScGetConnectionId 0x021DF224 arm ov175
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   DWC_ScSetSessionId 0x021DF1C8 arm ov175
 *   DWC_ScSetReportIntentionAsync 0x021DF09C arm ov175
 *   DWC_ScSubmitReportAsync 0x021DF130 arm ov175
 *   DWC_ScDestroyReport  0x021DF458  arm
 *   DWC_ScShutdown       0x021DEF58  arm
 *   DWC_ScCreateReport  0x021DF23C  arm
 *   DWC_ScReportBeginGlobalData  0x021DF298  arm
 *   DWC_ScReportBeginPlayerData  0x021DF2C8  arm
 *   DWC_ScReportBeginTeamData  0x021DF2F8  arm
 *   DWC_ScReportBeginNewPlayer  0x021DF328  arm
 *   DWC_ScReportSetPlayerData  0x021DF358  arm
 *   DWC_ScReportEnd  0x021DF3B0  arm
 *   DWC_ScReportAddIntValue 0x021DF3E8 arm ov175
 *   DWC_ScReportAddByteValue  0x021DF420  arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   g_021E2EF8  0x021E2EF8  data
 *   d_021E2DF4     0x021E2DF4  data
 *   d_021E2DEC     0x021E2DEC  data
 *   d_021E2DF0     0x021E2DF0  data
 *   DWC_GdbInitialize         0x021E10CC  arm
 *   DWC_GdbGetMyRecordsAsync  0x021E1618  arm
 *   DWC_GdbGetRecordsAsync    0x021E16F0  arm
 *   DWC_GdbProcess            0x021E1414  arm
 *   DWC_GdbGetState           0x021E1434  arm
 *   DWC_GdbGetAsyncResult     0x021E1454  arm
 *   DWC_GdbCancelRequest      0x021E11F0  arm
 *   d_021E2F1C                0x021E2F1C  data
 *   DWC_GdbShutdown  0x021E1340  arm
 *   d_021E2F2C 0x021E2F2C data a4
 *   d_021E2F38 0x021E2F38 data a4
 *   d_021E2F4C 0x021E2F4C data a4
 *   d_021E2F60 0x021E2F60 data a4
 *   GF_STANDARD_CompareString  0x0203F028  arm
 *   d_021E2F70     0x021E2F70  data
 *   d_021E2F7C 0x021E2F7C data a4
 *   d_021E2F8C 0x021E2F8C data a4
 *   d_021E2DF8 0x021E2DF8 data a4
 *   DWC_GdbInitialize 0x021E10CC arm ov175
 *   DWC_GdbUpdateRecordAsync 0x021E1540 arm ov175
 *   DWC_GdbProcess 0x021E1414 arm ov175
 *   DWC_GdbGetState 0x021E1434 arm ov175
 *   DWC_GdbGetAsyncResult 0x021E1454 arm ov175
 *   DWC_GdbCancelRequest 0x021E11F0 arm ov175
 *   DWC_GdbCreateRecordAsync 0x021E1464 arm ov175
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   STD_TSPrintf 0x0208D7E0 arm
 *   d_021E2FA4 0x021E2FA4 data a1
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   DWC_NdGetFileListAsync 0x021C5C38 arm ov114
 *   DWC_NdGetFileAsync 0x021C5CFC arm ov114
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 *   DWC_NdProcess 0x021C5AB8 arm ov114
 *   DWC_NdGetProgress 0x021C5E14 arm ov114
 *   d_021E4B80 0x021E4B80 data a4
 *   d_021E2FA8 0x021E2FA8 data a4
 *   d_021E2FB0 0x021E2FB0 data a4
 *   d_021E2FC4 0x021E2FC4 data a4
 *   NHTTP_RAP_DeleteConnection   0x021B9774  thumb  ov114
 *   NHTTP_RAP_Destroy   0x021B9838  thumb  ov114
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   MYSTATUS_CreateNameStrbuf              0x02008510  thumb
 *   STRBUF_GetChars              0x02045A90  arm
 *   STRBUF_GetLength              0x020458F8  arm
 *   DWC_CheckProfanityExAsync  0x0217BC44  arm  ov009
 *   DWC_CheckProfanityProcess  0x0217BC90  arm  ov009
 *   MYSTATUS_NameFromStrbuf  0x020084E4  thumb
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetRecord 0x021B9A14 thumb ov114
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   d_021E3270  0x021E3270  data
 *   d_021E3250  0x021E3250  data
 *   g_021E32C4   0x021E32C4  data
 *   g_021E32C8   0x021E32C8  data
 *   g_021E32E0   0x021E32E0  data
 *   g_021E32FC   0x021E32FC  data
 *   g_021E3318   0x021E3318  data
 *   g_021E3338   0x021E3338  data
 *   g_021E3354   0x021E3354  data
 *   g_021E3370   0x021E3370  data
 *   g_021E3390   0x021E3390  data
 *   g_021E33B0   0x021E33B0  data
 *   g_021E33D0   0x021E33D0  data
 *   g_021E33E8   0x021E33E8  data
 *   g_021E3400   0x021E3400  data
 *   g_021E3418   0x021E3418  data
 *   g_021E3430   0x021E3430  data
 *   g_021E3448   0x021E3448  data
 *   g_021E3460   0x021E3460  data
 *   g_021E347C   0x021E347C  data
 *   g_021E348C   0x021E348C  data
 *   g_021E34A4   0x021E34A4  data
 *   g_021E34C0   0x021E34C0  data
 *   g_021E34D4   0x021E34D4  data
 *   g_021E34F0   0x021E34F0  data
 *   g_021E3508   0x021E3508  data
 *   g_021E3520   0x021E3520  data
 *   g_021E3538   0x021E3538  data
 *   g_021E3550   0x021E3550  data
 *   g_021E356C   0x021E356C  data
 *   g_021E3584   0x021E3584  data
 *   g_021E359C   0x021E359C  data
 *   g_021E35B4   0x021E35B4  data
 *   g_021E35CC   0x021E35CC  data
 *   g_021E35E4   0x021E35E4  data
 *   g_021E3600   0x021E3600  data
 *   g_021E3618   0x021E3618  data
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../version.h"

#define P(base, k) (*(int *)((base) + (k)))
#define Q(base, k) (*(int *)((base) + (k)))
#define REC(base) ((u32 *)CTX(base)[2])
#define H(base) ((char *)W(base, 0x34))
#include "wifibattlematch_net_types.h"

#include "../arm9/gf_overlay.h"
#include "../arm9/gf_panic.h"
#include "../arm9/gfl_use.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../ov177/wifibattlematch_graphic.h"
#include "../arm9/gf_font.h"
#include "../arm9/printsys.h"
#include "../arm9/wordset.h"
#include "../ov177/wifibattlematch_util.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/fade.h"
struct SaveControl;
#include "../arm9/game_sync.h"
#include "../arm9/block20_savedata.h"
#include "../arm9/poke_regulation.h"
#include "../arm9/strbuf.h"
#include "../arm9/bmp_oam.h"
#include "../arm9/pmsi_param.h"
#include "../arm9/bg_sys.h"
struct TradeHistory;
#include "../arm9/trade_history.h"
#include "../arm9/met_trainers_savedata.h"
#include "../arm9/net_err.h"
typedef unsigned short StatRow;
#include "../arm9/bsubway_savedata.h"
struct WifibattlematchMenu;
#include "../arm9/config.h"
#include "../arm9/greeting_savedata.h"
#include "../arm9/poke_tool.h"
#include "../arm9/pokeparty.h"
#include "../ov114/nhttp_rap_evilcheck.h"
#include "../ov114/nhttp_rap.h"
#include "../arm9/key.h"
/* The DS code passes the auto exit and login option as words (the original prototypes); the header has byte parameters. The host build uses the header. */
#ifdef __MWERKS__
#define GFL_NET_SetAutoExit GFL_NET_SetAutoExit_header
#define GFL_NET_SetLoginOption GFL_NET_SetLoginOption_header
#endif
#include "../arm9/net.h"
#ifdef __MWERKS__
#undef GFL_NET_SetAutoExit
#undef GFL_NET_SetLoginOption
extern void GFL_NET_SetAutoExit(u32 autoExit);
extern void GFL_NET_SetLoginOption(u32 loginOption);
#endif
#include "../arm9/regulation.h"
struct WifiBattleMatchCompWork;
#include "../arm9/button_man.h"
#include "../ov009/dwc_nasfunc.h"
#include "../arm9/convert.h"
#include "../arm9/gf_standard.h"
#include "../arm9/net_command.h"
#include "../ov009/dwc_rap.h"
#include "../arm9/net_handle.h"
#include "../arm9/net_state.h"
#include "../arm9/std_sprintf.h"
#include "../arm9/net_system.h"
#include "../ov009/dwc_match.h"
#include "dwc_sc.h"
struct SCIReport;
struct GSLoginCertificate;
#include "dwc_gdb.h"
#include "../ov114/dwc_nd.h"
struct _NHTTPRapSession;
#include "../ov114/d_nhttp.h"
#include "../ov009/dwc_prof.h"
#include "../arm9/battle_box.h"
#include "../arm9/game_data.h"
#include "../arm9/msgdata.h"
#include "../arm9/mystatus.h"
#include "../arm9/wifilist.h"
#include "../ov009/dwc_main.h"
#include "../ov009/dwc_rapcommon.h"
#include "../ov177/wifibattlematch_view.h"
#include "wifibattlematch_net.h"
#include "../ov175/wifibattlematch_core.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021E2D20[];
extern const char str_ja_021E2D38[];
extern const char str_ja_021E2E38[];
extern const char str_ja_021E2E50[];
extern const char str_ja_021E2E74[];
extern const char str_ja_021E2E8C[];
extern const char str_ja_021E2F44[];
extern const char str_ja_021E2F98[];
#endif
extern const WifiBattleMatchNetTable d_021E2C74,d_021E2C80;
extern const char d_021E2DE0[];
extern const char ov177_id[];
extern const char ov067_id[], ov114_id[];
extern const char ov114_id[],ov067_id[];
extern const char d_021E2EE0[], d_021E2EF8[];
extern NetCommandEntry d_021E2C90[];
extern const char d_021E2EFC[];
extern u32 g_021E2C8C[];
extern const char *const d_021E2E10[];
extern u32 g_021E2EF8[];
extern char d_021E2DF4[];
extern char d_021E2DEC[];
extern char d_021E2DF0[];
extern const char d_021E2F1C[];
extern char d_021E2F2C[], d_021E2F4C[], d_021E2F60[];
extern const char d_021E2F38[];
extern const char d_021E2F70[];
extern const char d_021E2F7C[],d_021E2F8C[];
extern const char d_021E2F7C[];
extern char *const d_021E2DF8[];
extern const char d_021E2FA4[];
extern u8 d_021E4B80[];
extern char d_021E2FA8[],d_021E2FB0[],d_021E2FC4[];
extern char d_021E3270[];
extern char d_021E3250[];
extern u32 g_021E32C4[];
extern u32 g_021E32C8[];
extern u32 g_021E32E0[];
extern u32 g_021E32FC[];
extern u32 g_021E3318[];
extern u32 g_021E3338[];
extern u32 g_021E3354[];
extern u32 g_021E3370[];
extern u32 g_021E3390[];
extern u32 g_021E33B0[];
extern u32 g_021E33D0[];
extern u32 g_021E33E8[];
extern u32 g_021E3400[];
extern u32 g_021E3418[];
extern u32 g_021E3430[];
extern u32 g_021E3448[];
extern u32 g_021E3460[];
extern u32 g_021E347C[];
extern u32 g_021E348C[];
extern u32 g_021E34A4[];
extern u32 g_021E34C0[];
extern u32 g_021E34D4[];
extern u32 g_021E34F0[];
extern u32 g_021E3508[];
extern u32 g_021E3520[];
extern u32 g_021E3538[];
extern u32 g_021E3550[];
extern u32 g_021E356C[];
extern u32 g_021E3584[];
extern u32 g_021E359C[];
extern u32 g_021E35B4[];
extern u32 g_021E35CC[];
extern u32 g_021E35E4[];
extern u32 g_021E3600[];
extern u32 g_021E3618[];

#define W(base, k) (*(u32 *)((base) + (k)))


#define CTX(base) ((u32 *)(base)[16])

#define TIMER(base) (*(u32 *)((base) + 0xe0))

#define TIMEOUT(base) (*(u32 *)((base) + 0xe8))


#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER
#define TIMER(base) (*(u32 *)((base) + 0xe0))

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT

#undef TIMEOUT
#define TIMEOUT(base) (*(u32 *)((base) + 0xe8))


#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER

#undef TIMER
#define TIMER(base) (*(u32 *)((base) + 0xe0))


/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * The second call, at +0x0C, targets 0x021E8A90.  That address carries no
 * func_/sub_ label in ANY listing -- ov093 has a bare `bx lr` there and
 * ov177 has plain .word data -- so no class can attest it: four call
 * sites image-wide (ov175 x2, ov176 x3) are not enough without a traced
 * entry point.  Bytes are exact; only the relocation is unwitnessed.
 */


#undef CTX

#undef CTX

#undef CTX
#define CTX(base) (*(u32 **)((base)+offset))

/*
 * note: The listing stops at the epilogue label 021D76B8; the full body
 *       ends at 021D76D4 after its epilogue and pools, followed by our
 *       separately matched WIFIBATTLEMATCH_NET_CompStepRegisterParty.c.
 * lever: Enum context offset keeps 0x104 in r7; reload aux by literal 0x108.
 *        Distinct Request locals preserve the three eight-byte stack objects.
 *        The masked byte decrement is spelled as addition of 0xfc.
 */
#define COMP_PARAMS(base) ((base)->ctx)

#undef COMP_PARAMS

#undef W

#define W(base, k) (*(u32 *)((base) + (k)))


/*
 *   extern void GFL_NET_SYSTEM_SetWaitMode(int);
 *   void GFL_NET_SetWaitMode(int value) { GFL_NET_SYSTEM_SetWaitMode(value); }
 *   Its target stores its one word input at global +0x1ac; no extra input.
 *   Leaf returns *(u32 *)(p+0x1458) for kind 3 or 6, otherwise 0.
 * lever: u16 heap fixes allocator spill order; 02009860 leaves r0 live,
 *   and caller stores that return word despite the callee's void declaration.
 * note 2026-10-04 (lane 20, D2): leaf WIFIBATTLEMATCH_NET_GetDownloadSize is now filed EXACT as
 * src/matched/ov/WIFIBATTLEMATCH_NET_GetDownloadSize.c (24 bytes). The tool still says "no witness" for it until
 * the integrator runs the manifest. The other blocker, ARM9 GFL_NET_SetWaitMode (veneer-like 12-byte
 * tail call), is the arm9 label lane's. Body is byte-correct; expect EXACT after manifest + label.
 */
struct WifiBattleMatchNetCtx *WIFIBATTLEMATCH_NET_CreateNetContext(struct WifiBattleMatchReportBlock *netId, struct GameData *save, char *heapId, u16 heap) {
    struct WifiBattleMatchNetCtx *ctx;
    struct WifiList *wifiList;
    ctx = GFL_HEAP_Alloc(heap, sizeof(*ctx), 0, PM_LANG_JA(d_021E2EE0, str_ja_021E2E38), PM_SRC_LINE(0x2b0, 0x297));
    MI_CpuFill8(ctx, 0, sizeof(*ctx));
    wifiList = GAME_DATA_GetWifiList(save);
    ctx->gsProfileId = wifiList;
    ctx->scId = WIFILIST_GetWork(wifiList);
    ctx->statusBuf = MYSTATUS_GetProfileId(GAME_DATA_GetMyStatus(save));
    ctx->save = save;
    ctx->heap = heapId;
    ctx->netIdPtr = netId;
    ctx->initWord = 0x573;
    ctx->recBuf = GFL_HEAP_Alloc(heap, 0x260, 0, PM_LANG_JA(d_021E2EE0, str_ja_021E2E38), PM_SRC_LINE(0x2c0, 0x2a7));
    MI_CpuFill8(ctx->recBuf, 0, 0x260);
    if (!GFL_NET_GetRunState()) GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x2B0), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
    GFL_NET_COMMAND_AddCommandTable(0x2400, d_021E2C90, 6, ctx);
    GFL_NET_SetWaitMode(0);
    DWC_RAP_SetErrorCallback(WIFIBATTLEMATCH_NET_CleanupDownload, ctx);
    DWC_RAP_SetErrorHookCallback(WIFIBATTLEMATCH_NET_GetDownloadSize, ctx);
    return ctx;
}

void WIFIBATTLEMATCH_NET_DeleteNetContext(struct WifiBattleMatchNetCtx *ctx) { DWC_RAP_SetErrorHookCallback(0,0); DWC_RAP_SetErrorCallback(0,0); GFL_NET_COMMAND_DeleteCommandTable(0x2400); GFL_HEAP_Free(ctx->recBuf); GFL_HEAP_Free(ctx); }

/*
 * Empty stub sitting between the WIFIBATTLEMATCH_NET_DeleteNetContext teardown and
 *     WIFIBATTLEMATCH_NET_SetTimingSyncRange; nothing calls into it, disasm.py labelled it from its
 *     alignment padding.
 */
void WIFIBATTLEMATCH_NET_Noop(struct WifiBattleMatchNetCtx *unused)
{
}

/*
 * Stores the caller's word at +0x14 and forwards its low byte to
 *     0x02039C68 with the tick/state from 0x020399A8 and line 0x24.  The byte
 *     is re-read from the field after the first call, which is why the listing
 *     reloads +0x14.  WIFIBATTLEMATCH_NET_IsTimingSyncRange is the same shape for the flush path.
 */
void WIFIBATTLEMATCH_NET_SetTimingSyncRange(struct WifiBattleMatchNetCtx *obj, u32 v)
{
    obj->syncRange = v;
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)obj->syncRange, 0x24);
}

/*
 * Flush partner of WIFIBATTLEMATCH_NET_SetTimingSyncRange: sends the byte the object kept at
 *     +0x14 to 0x02039CB4 with the tick/state and line 0x24.
 */
int WIFIBATTLEMATCH_NET_IsTimingSyncRange(struct WifiBattleMatchNetCtx *obj)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)obj->syncRange, 0x24);
}

/*
 * Error poll: while the link is up, classifies the transport error through 0x02157170 (0..4); otherwise classifies the stored error record by its kind, and on a nonzero class shuts the screens down, runs the class action (1 reset, 2 fatal screen, 3 retry) and clears the record.
 */
int WIFIBATTLEMATCH_NET_HandleNetError(struct WifiBattleMatchNetCtx *ctx, void *a, void *b)
{
    u32 *rec = (u32 *)(&ctx->err);
    WifibattlematchNetRes r = RES_NONE;

    if (GFL_NET_GetRunState()) {
        if (GFL_NET_ERR_GetErrorLevel()) {
            GFL_NET_SetAutoExit(r);
            GFL_NET_SetLoginOption(r);
#if LANGUAGE != LANGUAGE_JAPANESE
            GFL_USE_StopAllSe();
#endif
            if (GAME_DATA_IsSaving(ctx->save)) {
                GAME_DATA_SaveCancel(ctx->save);
                GFL_NET_ERR_HaltWithMessage(0x29);
            }
        }
        switch (DWC_RAPCOMMON_HandleNetError((sptr)a, (sptr)b)) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = RES_1;
            break;
        case 2:
            r = RES_2;
            break;
        case 3:
            r = RES_3;
            break;
        case 4:
            r = RES_4;
            break;
        }
        return r;
    }
    if (r == RES_NONE) {
        switch (rec[7]) {
        case 0:
            r = RES_NONE;
            break;
        case 1:
            r = WIFIBATTLEMATCH_NET_GetErrorMsg(rec[0]);
            break;
        case 2:
            r = WIFIBATTLEMATCH_NET_GetErrorCode(rec[1], rec[2], rec[3]);
            break;
        case 3:
        case 4:
            r = RES_NONE;
            break;
        case 5:
            r = WIFIBATTLEMATCH_NET_MapErrorCode(rec[6]);
            break;
        default:
            r = RES_NONE;
            break;
        }
        if (r != RES_NONE) {
            GFL_NET_SetAutoExit(0);
            GFL_NET_SetLoginOption(0);
#if LANGUAGE != LANGUAGE_JAPANESE
            GFL_USE_StopAllSe();
#endif
            if (GAME_DATA_IsSaving(ctx->save)) {
                GAME_DATA_SaveCancel(ctx->save);
                GFL_NET_ERR_HaltWithMessage(0x29);
            }
        }
        switch (r) {
        case RES_1:
            GFL_NET_STATE_ClearErrorMode();
            GFL_NET_STATE_SetWifiError();
            GFL_NET_ERR_ShowSimpleScreen();
            GFL_NET_ERR_ResetState();
            break;
        case RES_2:
            if (!GFL_NET_ERR_GetErrorLevel()) {
                GFL_NET_STATE_SetError(0, 0, 0, 0x3F7);
                GFL_NET_ERR_RecordError();
            }
            GFL_NET_ERR_RequestScreen();
            break;
        case RES_3:
            GFL_NET_ERR_HaltIfActive();
            break;
        }
        if (r != RES_NONE)
            WIFIBATTLEMATCH_NET_ClearStruct(rec);
    }
    return r;
}

void WIFIBATTLEMATCH_NET_ClearErrorFlags(struct WifiBattleMatchNetCtx *ctx) { ctx->state=0; ctx->gdbState=0; }

int WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(struct WifiBattleMatchNetCtx *ctx)
{
    int result;
    switch (ctx->gdbState) {
    case 0:
        WIFIBATTLEMATCH_NET_GdbRequest(ctx, -1, 2, ctx->netIdPtr);
        ctx->gdbState = 1;
        break;
    case 1:
        result = WIFIBATTLEMATCH_NET_GdbGetMyRecords(ctx);
        if (result == 1) {
            if (ctx->netIdPtr->head != 0) ctx->gdbState = 4;
            else ctx->gdbState = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        WIFIBATTLEMATCH_NET_GdbClearRecord(ctx);
        ctx->gdbState = 3;
        break;
    case 3:
        result = WIFIBATTLEMATCH_NET_GdbCreateRecord(ctx);
        if (result == 1) ctx->gdbState = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}

/*
 * Sets up a matchmaking attempt: closes any connection, publishes the eight match keys (player count, group, 1, four record words, version and language), formats the filter string and picks the evaluation callback for the mode (1 asserts).
 */
void WIFIBATTLEMATCH_NET_SetMatchKey(struct WifiBattleMatchNetCtx *obj, int mode, int extra, int group, int *rec)
{
    int count = mode;

    if (mode == 1)
        count += extra;
    if (!GFL_NET_GetRunState())
        GFL_NET_ERR_HaltIfActive();
    DWC_CloseAllConnectionsHard();
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 0, count);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 1, group);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 2, 1);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 3, rec[0]);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 5, rec[1]);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 4, rec[2]);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 6, rec[3]);
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 7, PM_LANG_VERSION_KEY);
    STD_TSPrintf(obj->filter, d_021E2EFC, count, group, 1);
    obj->mmState = 0;
    obj->pollCount = 0;
    obj->retryCount = 0;
    MI_CpuFill8(&obj->recvPlayerData, 0, 0x18);
    switch (mode) {
    case 0:
        obj->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyValue;
        break;
    case 1:
        GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x424), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
        break;
    case 2:
        obj->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyInt;
        break;
    case 3:
        obj->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyDefault;
        break;
    default:
        GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x42D), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
        break;
    }
}

/*
 * Matchmaking step (state at +0x40): 0 starts the search with the evaluation callback, then waits for the match, the peer handshake (with a 3600-tick timeout counted at +0x1a4) and the link check; returns 1 when done, 2 on a fatal error and 0 while still running.
 */
int WIFIBATTLEMATCH_NET_StartMatchmaking(struct WifiBattleMatchNetCtx *obj)
{
    switch (obj->mmState) {
    case 0:
        if ((int)DWC_RAP_StartMatchWithFilter(obj->filter, 2, obj->evalFn, obj)) {
            GFL_NET_STATE_WifiEnterRandomMatch();
            DWC_RAP_SetVchatEnabled(0);
            obj->mmState = 1;
        } else {
            GFL_NET_STATE_WifiDisconnect(1);
            return 2;
        }
        break;
    case 1:
        obj->mmState = 2;
        break;
    case 2:
        switch (GFL_NET_STATE_GetWifiState()) {
        case 0:
            if ((u32)(GFL_NET_STATE_GetError()->gameCode - 0x3f0) > 1)
                break;
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            obj->mmState = 7;
            break;
        case 1:
            obj->retryCount = 0;
            obj->mmState = 3;
            GFL_NET_SetAutoExit(1);
            GFL_NET_SetLoginOption(1);
            break;
        default:
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            obj->mmState = 7;
            break;
        }
        break;
    case 3:
        if (GFL_NET_SYSTEM_GetCurrentAid()) {
            if (GFL_NET_HANDLE_CheckNegotiation())
                obj->mmState = 4;
            if ((obj->retryCount)++ > 0xe10) {
                WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
                obj->mmState = 7;
            }
        } else {
            obj->retryCount = 0;
            obj->mmState = 5;
        }
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24);
        obj->retryCount = 0;
        obj->mmState = 6;
        break;
    case 5:
        if ((obj->retryCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            obj->mmState = 7;
        } else if (GFL_NET_HANDLE_GetNegotiationNum() && GFL_NET_HANDLE_CheckNegotiation()) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24);
            obj->retryCount = 0;
            obj->mmState = 6;
        }
        break;
    case 6:
        if ((obj->retryCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            obj->mmState = 7;
        } else if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24)) {
            obj->mmState = 8;
        }
        break;
    case 7:
        if (WIFIBATTLEMATCH_NET_StopMatchmaking(obj)) {
            if ((u32)(GFL_NET_STATE_GetError()->gameCode - 0x3f0) <= 1) {
                GFL_NET_STATE_SetWifiError();
                GFL_NET_STATE_ClearErrorMode();
                GFL_NET_ERR_ResetState();
                GFL_NET_STATE_WifiDisconnect(1);
            }
            return 2;
        }
        break;
    case 8:
        GFL_NET_IsParentAid();
        return 1;
    }
    return 0;
}

/*
 * Three-call init/reset sequence: 0x0203D7B0(0), 0x0203D7BC(0) and
 *     0x0203C554(1).
 */
void WIFIBATTLEMATCH_NET_DisconnectWifi()
{
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    GFL_NET_STATE_WifiDisconnect(1);
}

/*
 * Leaf: clears the word at +0x154.
 */
void WIFIBATTLEMATCH_NET_ClearCancelFlag(struct WifiBattleMatchNetCtx *obj)
{
    obj->shutdownState = 0;
}

/*
 * Link shutdown sequence stepped by the word at +0x154: sync 0x18, wait for the sync (600 frame timeout on +0x1a0), stop the two link services, wait 30 frames on +0x134, restart the parent service, then report done (1).
 */
int WIFIBATTLEMATCH_NET_StopMatchmaking(struct WifiBattleMatchNetCtx *obj)
{
    switch (obj->shutdownState) {
    case 0:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(obj, 0x18);
        obj->pollCount = 0;
        (obj->shutdownState)++;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(obj) != 0)
            (obj->shutdownState)++;
        else if ((obj->pollCount)++ > 600)
            (obj->shutdownState)++;
        break;
    case 2:
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        obj->pendingCount = 0;
        (obj->shutdownState)++;
        break;
    case 3:
        if ((obj->pendingCount)++ > 30)
            (obj->shutdownState)++;
        break;
    case 4:
        GFL_NET_STATE_WifiDisconnect(1);
        (obj->shutdownState)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}

int WIFIBATTLEMATCH_NET_SendSessionQuery()
{
    if (DWC_RAP_IsStateInSession() != 0)
        return GFL_NET_SendToHandle((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), 0x2402, 4, (const void *)(g_021E2C8C));
    return 1;
}

u32 WIFIBATTLEMATCH_NET_TakeSessionResult(struct WifiBattleMatchNetCtx *obj)
{
    u32 sessionResult = obj->sessionResult;

    if (sessionResult != 0)
        obj->sessionResult = 0;
    return sessionResult;
}

/*
 * stack: four date words (including weekday), three time words.
 */
void WIFIBATTLEMATCH_NET_GetDateTime(unsigned char *dest)
{
    int date[4];
    int time[3];
    if (!GFL_NET_GetRunState()) GFL_NET_ERR_HaltIfActive();
    if (!DWC_GetDateTime(date, time)) GFL_NET_ERR_HaltIfActive();
    MI_CpuFill8(dest, 0, 6);
    dest[0] = date[0];
    dest[1] = date[1];
    dest[2] = date[2];
    dest[3] = time[0];
    dest[4] = time[1];
    dest[5] = time[2];
}

/*
 * Registers match key i: stores the value, copies the three-byte key name from the table at 0x021E2E10, and keeps the key id DWC_AddMatchKeyInt returns.
 */
void WIFIBATTLEMATCH_NET_AddMatchKey(struct WifiBattleMatchNetCtx *obj, int i, int value)
{
    struct MatchKey *matchKey = (struct MatchKey *)obj->matchKeys + i;

    matchKey->value = value;
    MI_CpuCopy8(d_021E2E10[i], matchKey->name, 3);
    matchKey->term = 0;
    matchKey->id = DWC_AddMatchKeyInt(matchKey->id, matchKey->name, &matchKey->value);
}

/*
 * Matchmaking evaluation callback that forwards to the key-distance scorer WIFIBATTLEMATCH_NET_GetMatchKeyValue (unlabelled; its address is a code pointer in WIFIBATTLEMATCH_NET_SetMatchKey's pool).
 */
int WIFIBATTLEMATCH_NET_GetMatchKeyInt(int index, void *param)
{
    return WIFIBATTLEMATCH_NET_GetMatchKeyValue(index, param);
}

/*
 * Matchmaking evaluation callback that scores every candidate 1000 (unlabelled; its address is a code pointer in WIFIBATTLEMATCH_NET_SetMatchKey's pool).
 */
int WIFIBATTLEMATCH_NET_GetMatchKeyDefault(int index, void *param)
{
    return 1000;
}

/*
 * Matchmaking evaluation callback: reads the candidate's keys 3..6; a candidate with none of them scores 0, one whose key 4 differs from ours scores 0, otherwise 1000 less the key 3 distance and 32 times the distance between the two key5*50/(key6+5) ratios, floored at 0.
 */
int WIFIBATTLEMATCH_NET_GetMatchKeyValue(int index, void *param)
{
    struct WifiBattleMatchNetCtx *ctx = param;
    int valueB, valueA, valueC, valueD;
    int quota1, quota2, diffA, diffQuota, score;

    valueA = DWC_GetMatchIntValue(index, ctx->matchKeys[3].name, -1);
    valueB = DWC_GetMatchIntValue(index, ctx->matchKeys[5].name, -1);
    valueC = DWC_GetMatchIntValue(index, ctx->matchKeys[6].name, -1);
    valueD = DWC_GetMatchIntValue(index, ctx->matchKeys[4].name, -1);

    if (valueA == -1 && valueB == -1 && valueD == -1 && valueC == -1)
        return 0;
    if (valueD == ((struct WifiBattleMatchNetCtx *)ctx)->matchKeys[4].value) {
        quota1 = valueB * 50 / (valueC + 5);
        quota2 = ((struct WifiBattleMatchNetCtx *)ctx)->matchKeys[5].value * 50 / (((struct WifiBattleMatchNetCtx *)ctx)->matchKeys[6].value + 5);
        diffA = valueA - ((struct WifiBattleMatchNetCtx *)ctx)->matchKeys[3].value;
        if (diffA < 0)
            diffA = -diffA;
        diffQuota = quota1 - quota2;
        if (diffQuota < 0)
            diffQuota = -diffQuota;
        score = 1000 - diffA - diffQuota * 32;
        if (score < 0)
            return 0;
        return score;
    }
    return 0;
}

/*
 * Arms a storage-server report: resets the report state words, stores mode and the result slot, and picks the report callback at +0x158 from mode (0: plain, 1 with a result slot, or 1 without one, which also stores a3 and the two record words) and kind (0 or 2; anything else asserts).
 */
void WIFIBATTLEMATCH_NET_SetupMatchReport(struct WifiBattleMatchNetCtx *obj, int mode, int kind, u32 teamArg, u32 *rec, u32 slot)
{
    obj->reportFlag = 0;
    obj->state = 0;
    obj->reportCount = 1;
    obj->regValueReady = 0;
    obj->recvPlayerData = 0;
    obj->reportKind = mode;
    obj->reportSlot = slot;
    obj->reportFieldA = 0;
    obj->reportFieldB = 0;
    obj->reportFieldC = 0;
    if (mode == 0) {
        switch (kind) {
        case 0:
            obj->reportFn = WIFIBATTLEMATCH_NET_ReportAddLoss;
            break;
        case 2:
            obj->reportFn = WIFIBATTLEMATCH_NET_ReportAddWin;
            break;
        default:
            GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x664), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
            break;
        }
    } else if (mode == 1) {
        if (slot != 0) {
            switch (kind) {
            case 0:
                obj->reportFn = WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss;
                break;
            case 2:
                obj->reportFn = WIFIBATTLEMATCH_NET_ReportAddDisconnectWin;
                break;
            default:
                GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x676), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
                break;
            }
        } else {
            GFL_NET_IsParentAid();
            obj->teamArg = teamArg;
            obj->teamRec0 = rec[0];
            obj->teamRec4 = rec[4];
            switch (kind) {
            case 0:
                obj->reportFn = WIFIBATTLEMATCH_NET_ReportAddTeam;
                break;
            case 2:
                obj->reportFn = WIFIBATTLEMATCH_NET_ReportAddRecord;
                break;
            default:
                GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x692), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
                break;
            }
        }
    }
}

int WIFIBATTLEMATCH_NET_ScProcess(struct WifiBattleMatchNetCtx *ctx, u32 *out)
{
    NetErrorInfo *s;
    int result;
    char *dst;
    void *src;

    if (out != 0)
        *out = ctx->reportFieldC;
    s = GFL_NET_STATE_GetError();
    if ((u32)s->gameCode - 0x3f0 <= 1)
        ctx->reportSlot = 1;
    if (GFL_NET_ERR_GetErrorLevel() == 1) {
        if (s->errorType == 6 || s->errorType == 3) {
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
    } else if (ctx->reportSlot == 0 && GFL_NET_ERR_GetErrorLevel() == 2) {
        WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
        return 2;
    }
    if (ctx->reportSlot != 0 && ctx->reportKind != 0 && ctx->reportFieldA == 0
        && ctx->state > 7 && ctx->state < 10) {
        ctx->reportFieldB = 0;
        ctx->state = 6;
    }

    switch (ctx->state) {
    case 0:
        if (ctx->reportSlot != 0) {
            ctx->state = 4;
            break;
        }
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x24);
        ctx->state = 1;
        break;
    case 1:
        if (ctx->reportSlot != 0) {
            ctx->state = 4;
            break;
        }
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x24) != 0 || ctx->reportSlot != 0)
            ctx->state = 2;
        break;
    case 2:
        if (ctx->reportSlot != 0) {
            ctx->state = 4;
            break;
        }
        if (WIFIBATTLEMATCH_NET_SendRegValue(ctx, &ctx->teamRec4) != 0 || ctx->reportSlot != 0)
            ctx->state = 3;
        break;
    case 3:
        if (ctx->reportSlot != 0) {
            ctx->state = 4;
            break;
        }
        if (WIFIBATTLEMATCH_NET_TakeRegValue(ctx, (u32 *)&ctx->takenRegValue) != 0 || ctx->reportSlot != 0)
            ctx->state = 4;
        break;
    case 4:
        ctx->pendingCount = 0;
        ctx->reportState = 1;
        result = DWC_ScInitialize(0xb5f, 0);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x751, 0x729));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->state = 5;
        break;
    case 5:
        result = DWC_ScGetLoginCertificate((GSLoginCertificate **)((void **)((char *)&ctx->netIdPtr->players[0])));
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x761, 0x739));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->state = 6;
        break;
    case 6:
        if (GFL_NET_IsParentAid() != 0 || ctx->reportSlot != 0) {
        (ctx->pendingCount)++;
        result = DWC_ScCreateSessionAsync(WIFIBATTLEMATCH_NET_OnReportResultA, 100, (void *)(ctx));
        ctx->reportFieldA = 1;
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x773, 0x74B));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->pollCount = 0;
        ctx->state = 7;
        } else
            ctx->state = 8;
        break;
    case 7:
        if (ctx->pendingCount == 0) {
            dst = (char *)ctx->netIdPtr->players[0].pad_08;
            src = DWC_ScGetSessionId();
            MI_CpuCopy8(src, dst, 0x28);
            ctx->state = 8;
            break;
        }
        if ((ctx->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err, 1, PM_SRC_LINE(0x78f, 0x767));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (ctx->reportResult != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, ctx->reportResult, PM_SRC_LINE(0x797, 0x76F));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        break;
    case 8:
        if (ctx->reportSlot != 0) {
            ctx->state = 0xb;
            break;
        }
        dst = (char *)ctx->netIdPtr->players[0].connectionId;
        src = DWC_ScGetConnectionId();
        MI_CpuCopy8(src, dst, 0x28);
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x24);
        ctx->state = 9;
        break;
    case 9:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x24) != 0 || ctx->reportSlot != 0)
            ctx->state = 0xa;
        break;
    case 10:
        if (GFL_NET_IsParentAid() != 0 || ctx->reportSlot != 0) {
            if (GFL_NET_SendToHandle((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), 0x2400, sizeof(struct WifiBattleMatchReportPlayer), (const void *)((char *)&ctx->netIdPtr->players[0])) != 0 || ctx->reportSlot != 0)
                ctx->state = 0xb;
        } else if (ctx->recvPlayerData != 0 || ctx->reportSlot != 0) {
            ctx->recvPlayerData = 0;
            result = DWC_ScSetSessionId((const char *)(((char *)ctx->netIdPtr->players[1].pad_08)));
            dst = (char *)ctx->netIdPtr->players[0].pad_08;
            src = DWC_ScGetSessionId();
            MI_CpuCopy8(src, dst, 0x28);
            if (result != 0) {
                WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x7cd, 0x7A5));
                WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
                return 2;
            }
            ctx->state = 0xb;
        }
        break;
    case 11:
        (ctx->pendingCount)++;
        result = DWC_ScSetReportIntentionAsync(ctx->reportCount, WIFIBATTLEMATCH_NET_OnReportResultB, 100, (void *)(ctx));
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x7dd, 0x7B5));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->pollCount = 0;
        ctx->state = 0xc;
        break;
    case 12:
        if (ctx->pendingCount == 0) {
            ctx->state = 0xd;
            break;
        }
        if ((ctx->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err, 1, PM_SRC_LINE(0x7f2, 0x7CA));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (ctx->reportResult != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, ctx->reportResult, PM_SRC_LINE(0x7fa, 0x7D2));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        break;
    case 13:
        if (ctx->reportSlot != 0) {
            ctx->state = 0x13;
            break;
        }
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x24);
        ctx->state = 0xe;
        break;
    case 14:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x24) != 0 || ctx->reportSlot != 0)
            ctx->state = 0xf;
        break;
    case 15:
        if (GFL_NET_IsParentAid() != 0) {
            if (GFL_NET_SendToHandle((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), 0x2400, sizeof(struct WifiBattleMatchReportPlayer), (const void *)((char *)&ctx->netIdPtr->players[0])) != 0 || ctx->reportSlot != 0)
                ctx->state = 0x10;
        } else if (ctx->recvPlayerData != 0 || ctx->reportSlot != 0) {
            if (ctx->reportSlot == 0)
                ctx->reportFieldB = 1;
            ctx->recvPlayerData = 0;
            ctx->state = 0x10;
        }
        break;
    case 16:
        if (GFL_NET_IsParentAid() == 0) {
            if (GFL_NET_SendToHandle((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), 0x2400, sizeof(struct WifiBattleMatchReportPlayer), (const void *)((char *)&ctx->netIdPtr->players[0])) != 0 || ctx->reportSlot != 0)
                ctx->state = 0x11;
        } else if (ctx->recvPlayerData != 0 || ctx->reportSlot != 0) {
            if (ctx->reportSlot == 0)
                ctx->reportFieldB = 1;
            ctx->recvPlayerData = 0;
            ctx->state = 0x11;
        }
        break;
    case 17:
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x24);
        ctx->state = 0x12;
        break;
    case 18:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x24) != 0 || ctx->reportSlot != 0)
            ctx->state = 0x13;
        break;
    case 19:
        result = WIFIBATTLEMATCH_NET_SubmitReport(&ctx->netIdPtr->players[0], &ctx->netIdPtr->players[1],(struct WifiBattleMatchTeam *)&ctx->teamArg, ctx->reportCount,
                          ctx->reportFn, ctx->reportSlot, ctx->reportKind, ctx->reportFieldB);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x86d, 0x845));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->state = 0x14;
        break;
    case 20:
        (ctx->pendingCount)++;
        result = DWC_ScSubmitReportAsync(ctx->netIdPtr->players[0].report, ctx->reportCount, WIFIBATTLEMATCH_NET_OnReportResultC, 100, (void *)ctx);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, PM_SRC_LINE(0x87c, 0x854));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->pollCount = 0;
        ctx->state = 0x15;
        break;
    case 21:
        if (ctx->pendingCount == 0) {
            ctx->state = 0x16;
            break;
        }
        if ((ctx->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err, 1, PM_SRC_LINE(0x890, 0x868));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (ctx->reportResult != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, ctx->reportResult, PM_SRC_LINE(0x898, 0x870));
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        break;
    case 22:
        ctx->reportFieldC = 1;
        WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
        ctx->state = 0x17;
        break;
    case 23:
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x24);
        ctx->state = 0x18;
        break;
    case 24:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x24) != 0 || ctx->reportSlot != 0)
            ctx->state = 0x19;
        break;
    case 25:
        return 1;
    }
    return 0;
}

u32 WIFIBATTLEMATCH_NET_GetReportState(struct WifiBattleMatchNetCtx *ctx) { return ctx->regValue; }

/*
 * Competition-server completion callback: records a nonzero result at +0x15c and drops the pending-request count at +0x134 (unlabelled; its address is a code pointer in WIFIBATTLEMATCH_NET_ScProcess's pool).
 */
void WIFIBATTLEMATCH_NET_OnReportResultA(int result, void *userArg)
{
    struct WifiBattleMatchNetCtx *obj = userArg;
    if (result != 0)
        obj->reportResult = result;
    (obj->pendingCount)--;
}

/*
 * Report-intention completion callback: on success copies the 0x28-byte session id into the report block (+0x34 of the record at +0x1464), otherwise records the result at +0x15c; then drops the pending-request count at +0x134.
 */
void WIFIBATTLEMATCH_NET_OnReportResultB(int result, void *userArg)
{
    struct WifiBattleMatchNetCtx *obj = userArg;
    char *player = (char *)&obj->netIdPtr->players[0];

    if (result == 0)
        MI_CpuCopy8(DWC_ScGetConnectionId(), ((struct WifiBattleMatchReportPlayer *)player)->connectionId, 0x28);
    else
        obj->reportResult = result;
    (obj->pendingCount)--;
}

void WIFIBATTLEMATCH_NET_OnReportResultC(int result, void *userArg)
{
    struct WifiBattleMatchNetCtx *obj = userArg;
    if (result != 0)
        obj->reportResult = result;
    (obj->pendingCount)--;
}

/*
 * Report teardown: when the state word at +0x170 is 1, destroys the report once the +0x12c step is past 0x13, shuts the storage client down once the +0x12c step is 4 or more, and clears the state word.
 */
void WIFIBATTLEMATCH_NET_ShutdownReport(struct WifiBattleMatchNetCtx *obj)
{
    if (obj->reportState == 1) {
        if (obj->state > 0x13)
            DWC_ScDestroyReport((struct SCIReport *)((obj->netIdPtr)->players[0].report));
        if (obj->state >= 4)
            DWC_ScShutdown();
        obj->reportState = 0;
    }
}

/*
 * One exchange round: bails with the first nonzero status of the four session checks, sends the local record (mode from the peer kind), runs the callback, optionally sends the peer's record back and runs the callback again, then closes with the flag.
 */
int WIFIBATTLEMATCH_NET_SubmitReport(struct WifiBattleMatchReportPlayer *ctx, struct WifiBattleMatchReportPlayer *other, struct WifiBattleMatchTeam *peer, u32 isAuthoritative, RoundFn cb, int flag, int have, int twoway)
{
    int result;
    int mode;
    int mode2;

    if ((result = DWC_ScCreateReport(1, 2, 0, &ctx->report)) != 0)
        return result;
    if ((result = DWC_ScReportBeginGlobalData(ctx->report)) != 0)
        return result;
    if ((result = DWC_ScReportBeginPlayerData(ctx->report)) != 0)
        return result;
    if ((result = DWC_ScReportBeginNewPlayer(ctx->report)) != 0)
        return result;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (peer->rec0) {
        case 1:
        case 4:
            mode = 0;
            break;
        case 0:
        case 3:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        default:
#if LANGUAGE == LANGUAGE_JAPANESE
            GF_PANIC_FailPrintf(str_ja_021E2E38, 0x95F, str_ja_021E2E74, peer->rec0);
#else
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
#endif
            break;
        }
    }
    if ((result = DWC_ScReportSetPlayerData(ctx->report, 0, ctx->connectionId, 0, mode, ctx->certificate, ctx->authHash)) != 0)
        return result;
    if ((result = cb(ctx, (const u32 *)peer, 1, flag)) != 0)
        return result;
    if ((result = DWC_ScReportBeginNewPlayer(ctx->report)) != 0)
        return result;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (peer->rec0) {
            case 1:
            case 4:
                mode2 = 1;
                break;
            case 0:
            case 3:
                mode2 = 0;
                break;
            case 2:
                mode2 = 2;
                break;
            default:
#if LANGUAGE == LANGUAGE_JAPANESE
                GF_PANIC_FailPrintf(str_ja_021E2E38, 0x9B1, str_ja_021E2E74, peer->rec0);
#else
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
#endif
                break;
            }
        }
        if ((result = DWC_ScReportSetPlayerData(ctx->report, 1, other->connectionId, 0, mode2, other->certificate, other->authHash)) != 0)
            return result;
        if ((result = cb(ctx, (const u32 *)peer, 0, flag)) != 0)
            return result;
    }
    if ((result = DWC_ScReportBeginTeamData(ctx->report)) != 0)
        return result;
    if (flag != 0)
        return DWC_ScReportEnd(ctx->report, isAuthoritative, 1);
    return DWC_ScReportEnd(ctx->report, isAuthoritative, 0);
}

int WIFIBATTLEMATCH_NET_ReportAddRecord(struct WifiBattleMatchReportPlayer *ctx,const u32 *record,int invert) {
    int first,second,flip=0,skip=0,present,result;
    present=record[2]!=0 || record[3]!=0;
    switch(record[1]) {
    case 0: case 3: first=0; second=1; flip=1; break;
    case 1: case 4: first=1; second=0; flip=1; break;
    case 2: first=0; second=0; skip=1; break;
    case 5: case 6: default: first=0; second=0; break;
    }
    if(!invert && flip) { first^=1; second^=1; }
    switch(record[0]) {
    case 0:
        if(!skip && (result=DWC_ScReportAddByteValue(ctx->report,15,1))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,5,first))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,6,second))) return result;
        break;
    case 1:
        if(!skip && (result=DWC_ScReportAddByteValue(ctx->report,16,1))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,8,first))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,7,second))) return result;
        break;
    case 2:
        if(!skip && (result=DWC_ScReportAddByteValue(ctx->report,18,1))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,11,first))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,12,second))) return result;
        break;
    case 3:
        if(!skip && (result=DWC_ScReportAddByteValue(ctx->report,17,1))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,9,first))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,10,second))) return result;
        break;
    case 4:
        if(!skip && (result=DWC_ScReportAddByteValue(ctx->report,19,1))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,13,first))) return result;
        if((result=DWC_ScReportAddIntValue(ctx->report,14,second))) return result;
        break;
    default: GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0xBC0), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50)); break;
    }
    if((result=DWC_ScReportAddIntValue(ctx->report,20,present!=0))) return result;
    return DWC_ScReportAddIntValue(ctx->report,27,-1);
}

/*
 * tail: 021DB216..021DB218 is two zero alignment bytes.
 */
int WIFIBATTLEMATCH_NET_ReportAddTeam(struct WifiBattleMatchReportPlayer *ctx, const u32 *input, int invert)
{
    int flip = 0, skip = 0;
    int first, second;
    int present = 1;
    int result;
    if (input[2] == 0 && input[3] == 0) present = 0;
    switch (input[1]) {
    case 0: case 3: first = 0; second = 1; flip = 1; break;
    case 1: case 4: first = 1; second = 0; flip = 1; break;
    case 2: first = 0; second = 0; skip = 1; break;
    case 5: case 6: default: first = 0; second = 0; break;
    }
    if (!invert && flip) { first ^= 1; second ^= 1; }
    if (!skip && (result = DWC_ScReportAddByteValue(ctx->report, 0x15, 1))) return result;
    if((result=DWC_ScReportAddIntValue(ctx->report, 0x16, first))) return result;
    if((result=DWC_ScReportAddIntValue(ctx->report, 0x17, second))) return result;
    if((result=DWC_ScReportAddIntValue(ctx->report, 0x18, present != 0))) return result;
    return DWC_ScReportAddIntValue(ctx->report, 0x1c, -1);
}

/*
 * Report callback: adds byte key 0x1a with value 1 to the report at +0x4.
 */
int WIFIBATTLEMATCH_NET_ReportAddWin(struct WifiBattleMatchReportPlayer *ctx)
{
    return DWC_ScReportAddIntValue(ctx->report, 0x1a, 1);
}

/*
 * Report callback: adds byte key 0x19 with value 1 to the report at +0x4.
 */
int WIFIBATTLEMATCH_NET_ReportAddLoss(struct WifiBattleMatchReportPlayer *ctx)
{
    return DWC_ScReportAddIntValue(ctx->report, 0x19, 1);
}

/*
 * Report callback: adds byte key 0x1b with value -1 to the report at +0x4.
 */
int WIFIBATTLEMATCH_NET_ReportAddDisconnectWin(struct WifiBattleMatchReportPlayer *ctx)
{
    return DWC_ScReportAddIntValue(ctx->report, 0x1b, -1);
}

int WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss(struct WifiBattleMatchReportPlayer *ctx)
{
    return DWC_ScReportAddIntValue(ctx->report, 0x1c, -1);
}

void WIFIBATTLEMATCH_NET_OnRecvPlayerData(int index,int unused,const void *src,struct WifiBattleMatchNetCtx *ctx,int owner) { if(owner==(sptr)GFL_NET_HANDLE_GetCurrentHandle() && index!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()))) { MI_CpuCopy8(src,(char *)&ctx->netIdPtr->players[1],sizeof(struct WifiBattleMatchReportPlayer)); ctx->recvPlayerData=1; } }

void WIFIBATTLEMATCH_NET_OnRecvStatus(int index, int unused, void *dest, struct WifiBattleMatchNetCtx *ctx, int owner)
{
    void *record;
    record = GAME_DATA_GetMyStatusPlayer(ctx->save, index);
    MI_CpuCopy8(dest, record, MYSTATUS_GetSize());
    if (owner == (sptr)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (index != GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())))
            ctx->regDataReady = 1;
    }
}

/*
 * Compare the caller's first word with the current 0x0203D1A4 handle of the 0x020399A8 block; a match releases the 0x021E2EF8 pair through 0x02034714, a mismatch yields the +0x218 sub-block.
 */
int WIFIBATTLEMATCH_NET_GetPlayerBuffer(int a, char *b)
{
    if (GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())) == a) {
        GF_PANIC_Fail(PM_LANG_JA((const char *)(g_021E2EF8), str_ja_021E2E38), PM_SRC_LINE(0, 0xCE4), PM_LANG_JA((const char *)((sptr)g_021E2EF8), str_ja_021E2E50));
        return 0;
    }
    return (sptr)(b + 0x218);
}

/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x140 word of the fourth argument.
 */
void WIFIBATTLEMATCH_NET_OnRecvFlagA(u32 a, u32 b, u32 c, struct WifiBattleMatchNetCtx *d, u32 e)
{
    if (e != (uptr)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    d->sessionResult = 1;
}

/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x144 word of the fourth argument.
 */
void WIFIBATTLEMATCH_NET_OnRecvFlagB(u32 a, u32 b, u32 c, struct WifiBattleMatchNetCtx *d, u32 e)
{
    if (e != (uptr)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    d->regBufferReady = 1;
}

/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the entry address from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x148 word of the fourth argument.
 */
void WIFIBATTLEMATCH_NET_OnRecvFlagC(u32 a, u32 b, u32 c, struct WifiBattleMatchNetCtx *d, u32 e)
{
    if (e != (uptr)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    d->regFlagReady = 1;
}

/*
 * Same guard as WIFIBATTLEMATCH_NET_OnRecvFlagA but it moves the word the third argument
 *     points at into the +0x150 slot of the fourth argument and sets +0x14c.
 */
void WIFIBATTLEMATCH_NET_OnRecvValue(u32 a, u32 b, u32 *c, struct WifiBattleMatchNetCtx *d, u32 e)
{
    u32 value = *c;

    if (e != (uptr)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    d->regValue = value;
    d->regValueReady = 1;
}

/*
 * Selects a request kind 0..4: stores the table and its count at +0x194/+0x198 and the step callback at +0x17c, after resetting the step word at +0x12c and storing the two arguments.
 */
void WIFIBATTLEMATCH_NET_GdbRequest(struct WifiBattleMatchNetCtx *obj, u32 target, int kind, void *arg)
{
    obj->state = 0;
    obj->gdbArg = arg;
    obj->gdbTarget = target;
    switch (kind) {
    case 0:
        obj->gdbName = WIFIBATTLEMATCH_NET_GetRegNameA();
        obj->fieldCount = WIFIBATTLEMATCH_NET_GetRegKindA();
        obj->gdbStep = WIFIBATTLEMATCH_NET_GdbCopyFieldsA;
        break;
    case 1:
        obj->gdbName = WIFIBATTLEMATCH_NET_GetRegNameB();
        obj->fieldCount = WIFIBATTLEMATCH_NET_GetRegKindB();
        obj->gdbStep = WIFIBATTLEMATCH_NET_GdbCopyFieldsB;
        break;
    case 2:
        obj->gdbName = d_021E2DF4;
        obj->fieldCount = 1;
        obj->gdbStep = WIFIBATTLEMATCH_NET_GdbCopyFieldC;
        break;
    case 3:
        obj->gdbName = d_021E2DEC;
        obj->fieldCount = 1;
        obj->gdbStep = WIFIBATTLEMATCH_NET_GdbCopyFieldD;
        break;
    case 4:
        obj->gdbName = d_021E2DF0;
        obj->fieldCount = 1;
        obj->gdbStep = WIFIBATTLEMATCH_NET_GdbCopyFieldE;
        break;
    }
}

int WIFIBATTLEMATCH_NET_GdbGetMyRecords(struct WifiBattleMatchNetCtx *obj)
{
    int result;

    switch (obj->state) {
    case 0:
        result = DWC_GdbInitialize(0xb5f, (DWCstAccUserData *)obj->scId, 0);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(&obj->err, result, PM_SRC_LINE(0xdef, 0xdc7));
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        obj->state = 1;
        break;
    case 1:
        if (obj->fieldCount >= 0x26)
            GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0xDD0), PM_LANG_JA(d_021E2EF8, str_ja_021E2E8C));
        if (obj->gdbTarget == -1)
            result = DWC_GdbGetMyRecordsAsync((char *)d_021E2F1C, (char **)obj->gdbName, obj->fieldCount, WIFIBATTLEMATCH_NET_GdbSortByName, (void *)obj);
        else
            result = DWC_GdbGetRecordsAsync((char *)d_021E2F1C, (int *)(&obj->gdbTarget), 1, (char **)obj->gdbName, obj->fieldCount, WIFIBATTLEMATCH_NET_GdbSortByName, (void *)obj);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(&obj->err, result, PM_SRC_LINE(0xe0a, 0xde2));
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        obj->state = 2;
        obj->pollCount = 0;
        break;
    case 2:
        if ((obj->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&obj->err, 1, PM_SRC_LINE(0xe17, 0xdef));
            obj->state = 6;
            break;
        }
        DWC_GdbProcess();
        result = DWC_GdbGetState();
        if (result == 0 || result == 4) {
            WIFIBATTLEMATCH_NET_SetResultB(&obj->err, result, PM_SRC_LINE(0xe26, 0xdfe));
            obj->state = 6;
        } else if (result == 1) {
            obj->state = 3;
        }
        break;
    case 3:
        result = DWC_GdbGetAsyncResult();
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetResultC(&obj->err, result, PM_SRC_LINE(0xe39, 0xe11));
            obj->state = 6;
        } else if (result != 1) {
            WIFIBATTLEMATCH_NET_SetResultC(&obj->err, result, PM_SRC_LINE(0xe3f, 0xe17));
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        } else {
            obj->state = 4;
        }
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(obj);
        obj->state = 5;
        break;
    case 5:
        return 1;
    case 6:
        result = DWC_GdbCancelRequest();
        if (result == 0) {
            obj->pollCount = 0;
            obj->state = 7;
        } else {
            WIFIBATTLEMATCH_NET_SetResultA(&obj->err, result, PM_SRC_LINE(0xe5e, 0xe36));
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        break;
    case 7:
        if ((obj->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&obj->err, 1, PM_SRC_LINE(0xe6a, 0xe42));
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        DWC_GdbProcess();
        result = DWC_GdbGetState();
        if (result == 0 || result == 4) {
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        if (result == 1)
            obj->state = 8;
        break;
    case 8:
        WIFIBATTLEMATCH_NET_GdbShutdown(obj);
        return 2;
    }
    return 0;
}

/*
 * Shuts the storage-server database client down (unlabelled; reached by bl from WIFIBATTLEMATCH_NET_GdbGetMyRecords).
 */
void WIFIBATTLEMATCH_NET_GdbShutdown(struct WifiBattleMatchNetCtx *obj)
{
    DWC_GdbShutdown();
}

void WIFIBATTLEMATCH_NET_SetupGdbRecord(struct WifiBattleMatchNetCtx *ctx)
{
    struct MyStatus *record;
    record = GAME_DATA_GetMyStatus(ctx->save);
    ctx->recBuf[0].mName = d_021E2F2C;
    ctx->recBuf[0].mType = SAKEFieldType_BINARY_DATA;
    ctx->recBuf[0].mValue.mBinaryData.mValue = (unsigned char *)record;
    ctx->recBuf[0].mValue.mBinaryData.mLength = 32;
    WIFIBATTLEMATCH_NET_GetDateTime(ctx->dateTime);
    ctx->recBuf[1].mName = (char *)d_021E2F38;
    ctx->recBuf[1].mType = SAKEFieldType_BINARY_DATA;
    ctx->recBuf[1].mValue.mBinaryData.mValue = ctx->dateTime;
    ctx->recBuf[1].mValue.mBinaryData.mLength = 6;
    ctx->recBuf[2].mName = d_021E2F4C;
    ctx->recBuf[2].mType = SAKEFieldType_INT;
    ctx->recBuf[2].mValue.mInt = ctx->statusBuf;
    ctx->recBuf[3].mName = d_021E2F60;
    ctx->recBuf[3].mType = SAKEFieldType_INT;
    ctx->recBuf[3].mValue.mInt = WIFIBATTLEMATCH_NET_GetGsProfileId(ctx);
    ctx->fieldCount = 4;
}

/*
 * Storage-server records callback: forwards the records to the user callback at +0x17c, then, when no record id is pending (+0x1b0 == -1), scans every field of every record for the id field and stores its value through the pointer at +0x1464.
 */
void WIFIBATTLEMATCH_NET_GdbSortByName(int count, SAKEField **recs, void *userArg)
{
    struct WifiBattleMatchNetCtx *obj = userArg;
    int i, j;
    SAKEField *f;

    obj->gdbStep(count, recs, obj->gdbArg, obj->fieldCount);
    if (obj->gdbTarget != -1)
        return;
    for (i = 0; i < count; i++) {
        for (j = 0; j < obj->fieldCount; j++) {
            f = &recs[i][j];
            if (GF_STANDARD_CompareString(f->mName, d_021E2F70) == 0)
                obj->netIdPtr->head = f->mValue.mInt;
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldsA(int count, SAKEField **fields, void *arg, int n) {
    struct RegDataA *ctx = arg;
    int i,j;
    SAKEField *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(9))) ctx->regField9=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(10))) ctx->regField10=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(12))) ctx->regField12=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(11))) ctx->regField11=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(13))) ctx->regField13=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(14))) ctx->regField14=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(15))) ctx->regField15=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(16))) ctx->regField16=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(17))) ctx->regField17=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(18))) ctx->regField18=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(19))) ctx->regField19=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(20))) ctx->regField20=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(21))) ctx->regField21=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(22))) ctx->regField22=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(23))) ctx->regField23=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(3))) ctx->regField3=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(24))) ctx->regField24=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,d_021E2F4C)) ctx->regExtraA=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,d_021E2F60)) ctx->regExtraB=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,d_021E2F7C)) ctx->regExtraC=f->mValue.mInt;
            else if(!GF_STANDARD_CompareString(f->mName,d_021E2F70)) ctx->regExtraD=f->mValue.mInt;
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldsB(int count, SAKEField **fields, void *arg, int n)
{
    struct RegDataB *ctx = arg;
    int i,j;
    const SAKEField *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(0x25))==0) ctx->regField37=f->mValue.mInt;
            else if(GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(0x26))==0) ctx->regField38=f->mValue.mInt;
            else if(GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(0x24))==0) ctx->regField36=f->mValue.mInt;
            else if(GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(0x28))==0) ctx->regField40=f->mValue.mInt;
            else if(GF_STANDARD_CompareString(f->mName,WIFIBATTLEMATCH_NET_LookupFieldEntry(0x27))==0) ctx->regField39=f->mValue.mInt;
            else if(GF_STANDARD_CompareString(f->mName,d_021E2F7C)==0) ctx->regField35=f->mValue.mInt;
            else if(GF_STANDARD_CompareString(f->mName,d_021E2F8C)==0) {
                const SAKEBinaryData *blob=&f->mValue.mBinaryData;
                MI_CpuCopy8(blob->mValue,(u8 *)ctx+24,blob->mLength);
            }
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldC(int count, SAKEField **recs, void *dst, int nfields)
{
    int i, j;
    SAKEField *f;
    for (i = 0; i < count; i++) {
        for (j = 0; j < nfields; j++) {
            f = &recs[i][j];
            if (GF_STANDARD_CompareString(f->mName, d_021E2F70) == 0)
                *(int *)dst = f->mValue.mInt;
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldD(int count, SAKEField **recs, void *dst, int nfields)
{
    int i,j;
    SAKEField *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->mName,d_021E2F8C)==0)
                MI_CpuCopy8(f->mValue.mBinaryData.mValue,dst,f->mValue.mBinaryData.mLength);
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldE(int count, SAKEField **recs, void *dst, int nfields)
{
    int i,j;
    SAKEField *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->mName,d_021E2F38)==0)
                MI_CpuCopy8(f->mValue.mBinaryData.mValue,dst,f->mValue.mBinaryData.mLength);
        }
    }
}

void WIFIBATTLEMATCH_NET_SetupGdbUpload(struct WifiBattleMatchNetCtx *ctx,u32 mode,struct WifibattlematchNetRecord *src)
{
    ctx->state=0;
    if(ctx->netIdPtr->head==0)GF_PANIC_Fail(PM_LANG_JA((const char *)(d_021E2EF8), str_ja_021E2E38),PM_SRC_LINE(0, 0x1036),PM_LANG_JA((const char *)((sptr)d_021E2EF8), str_ja_021E2F44));
    switch(mode) {
    case 0:
        ctx->recBuf[0].mName=(char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(36);
        ctx->recBuf[0].mType=SAKEFieldType_INT;
        ctx->recBuf[0].mValue.mInt=1500;
        ctx->recBuf[1].mName=(char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(39);
        ctx->recBuf[1].mType=SAKEFieldType_INT;
        ctx->recBuf[1].mValue.mInt=0;
        ctx->recBuf[2].mName=(char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(40);
        ctx->recBuf[2].mType=SAKEFieldType_INT;
        ctx->recBuf[2].mValue.mInt=0;
        ctx->recBuf[3].mName=(char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(38);
        ctx->recBuf[3].mType=SAKEFieldType_INT;
        ctx->recBuf[3].mValue.mInt=0;
        ctx->recBuf[4].mName=(char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(37);
        ctx->recBuf[4].mType=SAKEFieldType_INT;
        ctx->recBuf[4].mValue.mInt=0;
        ctx->recBuf[5].mName=(char *)d_021E2F8C;
        ctx->recBuf[5].mType=SAKEFieldType_BINARY_DATA;
        ctx->recBuf[5].mValue.mBinaryData.mValue=(unsigned char *)src;
        ctx->recBuf[5].mValue.mBinaryData.mLength=1332;
        ctx->fieldCount=6;
        break;
    case 1:
        WIFIBATTLEMATCH_NET_GetDateTime(ctx->dateTime);
        ctx->fieldCount=1;
        ctx->recBuf[0].mName=(char *)d_021E2F38;
        ctx->recBuf[0].mType=SAKEFieldType_BINARY_DATA;
        ctx->recBuf[0].mValue.mBinaryData.mValue=ctx->dateTime;
        ctx->recBuf[0].mValue.mBinaryData.mLength=6;
        break;
    case 2:WIFIBATTLEMATCH_NET_SetupGdbRecord(ctx);break;
    case 3:
        ctx->uploadRecord=*src;
        ctx->fieldCount=2;
        ctx->recBuf[0].mName=d_021E2DF8[ctx->uploadRecord.words[20]];
        ctx->recBuf[0].mType=SAKEFieldType_BINARY_DATA;
        ctx->recBuf[0].mValue.mBinaryData.mValue=(unsigned char *)&ctx->uploadRecord;
        ctx->recBuf[0].mValue.mBinaryData.mLength=80;
        ctx->recBuf[1].mName=(char *)d_021E2F7C;
        ctx->recBuf[1].mType=SAKEFieldType_BYTE;
        ctx->recBuf[1].mValue.mByte=(unsigned char)((ctx->uploadRecord.words[20]+1)%6);
        break;
    }
}

/*
 * lever: PC-relative slot audit binds error/cancel/timeout lines to 0x11a0,0x11be,0x11ca; fixing source constants removes three pool-byte mismatches.
 * extent: existing matched WIFIBATTLEMATCH_NET_GdbClearRecord.c covers the final16 bytes; keep this504-byte lead alone.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives live entry r0 in case 4 despite its unused parameter.
 */
int WIFIBATTLEMATCH_NET_GdbUpdateRecord(struct WifiBattleMatchNetCtx *ctx)
{
    long result;
    switch(ctx->state) {
    case 0:
        result=DWC_GdbInitialize(0xb5f, (DWCstAccUserData *)ctx->scId, 0);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,PM_SRC_LINE(0x1161, 0x1139));WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        ctx->state=1;break;
    case 1:
        if(ctx->fieldCount>=0x26)GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38),PM_SRC_LINE(0, 0x1142),PM_LANG_JA(d_021E2EF8, str_ja_021E2E8C));
        result=DWC_GdbUpdateRecordAsync((char *)d_021E2F1C,ctx->netIdPtr->head,ctx->recBuf,ctx->fieldCount);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,PM_SRC_LINE(0x116e, 0x1146));WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        ctx->pollCount=0;ctx->state=2;break;
    case 2:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,PM_SRC_LINE(0x117b, 0x1153));ctx->state=6;break;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_SetResultB(&ctx->err,result,PM_SRC_LINE(0x1186, 0x115E));ctx->state=6;}
        else if(result==1)ctx->state=3;
        break;
    case 3:
        result=DWC_GdbGetAsyncResult();
        if(result==0) {WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,PM_SRC_LINE(0x1199, 0x1171));ctx->state=6;}
        else if(result!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,PM_SRC_LINE(0x11a0, 0x1178));return 2;}
        else ctx->state=4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(ctx);ctx->state=5;
    case 5:return 1;
    case 6:
        result=DWC_GdbCancelRequest();
        if(result==0) {ctx->pollCount=0;ctx->state=7;}
        else {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,PM_SRC_LINE(0x11be, 0x1196));WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        break;
    case 7:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,PM_SRC_LINE(0x11ca, 0x11A2));WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        if(result==1)ctx->state=8;
        break;
    case 8:WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;
    }
    return 0;
}

/*
 * leaf: reset request step then prepare four database fields.
 */
void WIFIBATTLEMATCH_NET_GdbClearRecord(struct WifiBattleMatchNetCtx *ctx)
{
    ctx->state = 0;
    WIFIBATTLEMATCH_NET_SetupGdbRecord(ctx);
}

/*
 * lever: PC-relative pool audit binds source-line constants 125c/126f/127b to the success/cancel-error/timeout calls, fixing the prior three concrete pool bytes.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives p where the caller visibly prepares r0.
 */
int WIFIBATTLEMATCH_NET_GdbCreateRecord(struct WifiBattleMatchNetCtx *ctx)
{
    long result;
    switch(ctx->state) {
    case 0:
        result=DWC_GdbInitialize(0xb5f, (DWCstAccUserData *)ctx->scId, 0);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,PM_SRC_LINE(0x1215, 0x11ED));return 2;}
        ctx->state=1;break;
    case 1:
        result=DWC_GdbCreateRecordAsync((char *)d_021E2F1C,ctx->recBuf,ctx->fieldCount,(int *)&ctx->netIdPtr->head);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,PM_SRC_LINE(0x1223, 0x11FB));return 2;}
        ctx->pollCount=0;ctx->state=2;break;
    case 2:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,PM_SRC_LINE(0x122f, 0x1207));ctx->state=4;break;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_SetResultB(&ctx->err,result,PM_SRC_LINE(0x123b, 0x1213));ctx->state=4;}
        else if(result==1)ctx->state=3;
        break;
    case 3:
        result=DWC_GdbGetAsyncResult();
        if(result==0) {WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,PM_SRC_LINE(0x124f, 0x1227));ctx->state=4;}
        else if(result!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,PM_SRC_LINE(0x1256, 0x122E));return 2;}
        else {
            if(ctx->netIdPtr->head==0)WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,2,PM_SRC_LINE(0x125c, 0x1234));
            WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 1;
        }
        break;
    case 4:
        result=DWC_GdbCancelRequest();
        if(result==0) {ctx->pollCount=0;ctx->state=5;}
        else {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,PM_SRC_LINE(0x126f, 0x1247));WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        break;
    case 5:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,PM_SRC_LINE(0x127b, 0x1253));WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        if(result==1)ctx->state=6;
        break;
    case 6:WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;
    }
    return 0;
}

/*
 * Two-level dereference: the pointer the object holds at +0x1464, then
 *     the word it points at.  Both loads are register-offset, so the listing
 *     pools one plain literal 0x1464.
 */
u32 WIFIBATTLEMATCH_NET_GetNetId(struct WifiBattleMatchNetCtx *obj)
{
    return obj->netIdPtr->head;
}

/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2401, size + 0xd4, data, 1, 1, 1); size is 0x0201A918's constant.
 */
u32 WIFIBATTLEMATCH_NET_SendRegData(struct WifiBattleMatchNetCtx *obj, const void *data)
{
    u32 busy = GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), (u8)flag, 0x2401, POKE_REGULATION_GetDataSize() + 0xd4, data, 1, 1, 1);
}

/*
 * Take-and-clear: returns the word at +0x13c; when it is set, clears it and hands back the address of the +0x218 block through out.
 */
u32 WIFIBATTLEMATCH_NET_TakeRegData(struct WifiBattleMatchNetCtx *obj, char **out)
{
    u32 ready = obj->regDataReady;
    if (ready != 0) {
        obj->regDataReady = 0;
        *out = (char *)obj->regData;
    }
    return ready;
}

u32 WIFIBATTLEMATCH_NET_SendRegDataAlt(struct WifiBattleMatchNetCtx *ctx,const void *data)
{
    unsigned int busy=GFL_NET_GetHandleNetID((GFLNetHandle *)((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())));
    int flag=1;
    if(busy!=0) flag=0;
    return GFL_NET_SendData((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()),(unsigned char)flag,0x2403,POKE_REGULATION_GetDataSize(),data,1,1,1);
}

/*
 * Takes and clears the +0x144 block; when there was one, calls
 *     0x0201A918(0) and hands its result to 0x02082D44 together with the
 *     object's +0x218 port block and the caller's second argument.  Returns
 *     the block it took.
 */
u32 WIFIBATTLEMATCH_NET_TakeRegBuffer(struct WifiBattleMatchNetCtx *obj, void *arg)
{
    u32 ready = obj->regBufferReady;

    if (ready != 0) {
        obj->regBufferReady = 0;
        MI_CpuCopy8(obj->regData, arg, POKE_REGULATION_GetDataSize());
    }
    return ready;
}

/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x0201A918
 * The call at +0x14 targets 0x0201A918, which has no label in the ARM9
 * listings and no branch to it from outside this function, so it fails
 * both the `label` and `sole-ref/code` classes.  Bytes are exact.
 */

/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2404, 4, data, 1, 1, 1); flag is 1 unless 0x0203D1A4 reports the link busy.
 */
int WIFIBATTLEMATCH_NET_SendRegFlag(struct WifiBattleMatchNetCtx *obj, const void *data)
{
    u32 busy = GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), (u8)flag, 0x2404, 4, data, 1, 1, 1);
}

u32 WIFIBATTLEMATCH_NET_TakeRegFlag(struct WifiBattleMatchNetCtx *obj, void *arg)
{
    u32 ready = obj->regFlagReady;

    if (ready != 0) {
        obj->regFlagReady = 0;
        MI_CpuCopy8(obj->regData, arg, 4);
    }
    return ready;
}

/*
 * Tagged log/emit: the tick from 0x020399A8, the id 0x2405, a length of
 *     4 and the caller's pointer go to 0x0203D3A8, which is the four-argument
 *     form the listing loads straight into r2/r3.
 */
int WIFIBATTLEMATCH_NET_SendRegValue(struct WifiBattleMatchNetCtx *ignored, const void *ctx)
{
    return GFL_NET_SendToHandle((GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()), 0x2405, 4, ctx);
}

/*
 * Take-and-clear: returns the word at +0x14c; when it is set, clears it and hands back the word at +0x150 through out.
 */
u32 WIFIBATTLEMATCH_NET_TakeRegValue(struct WifiBattleMatchNetCtx *obj, u32 *out)
{
    u32 ready = obj->regValueReady;
    if (ready != 0) {
        obj->regValueReady = 0;
        *out = obj->regValue;
    }
    return ready;
}

void WIFIBATTLEMATCH_NET_SetupDownload(struct WifiBattleMatchNetCtx *ctx,unsigned a)
{
    ctx->state=0;
    ctx->downloadActive=0;
    MI_CpuFill8(ctx->ndAttr,0,10);
    MI_CpuFill8(ctx->fileList,0,0xb0);
    STD_TSPrintf((char *)ctx->ndAttr,d_021E2FA4,a);
}

/*
 * lever: case-local repeated error call+break reproduces merged error block and long-branch layout; tail goto displaced it.
 * extent: unlabelled28-byte zero-word test021DC5AC filed separately.
 */
int WIFIBATTLEMATCH_NET_DownloadProcess(struct WifiBattleMatchNetCtx *ctx)
{
    u32 count,percent;
    switch(ctx->state) {
    case 0:
        if(DWC_NdInitAsync(WIFIBATTLEMATCH_NET_NdSetError,d_021E2FA8,d_021E2FB0)==0)return 3;
        ctx->downloadActive=1;
        WIFIBATTLEMATCH_NET_NdSetState(ctx,1);break;
    case 1:
        if(DWC_NdSetAttr(d_021E2FC4,(char *)(ctx->ndAttr),(char *)d_021E2EF8)==0){WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);break;}
        ctx->state=2;break;
    case 2:
        if(DWC_NdGetFileListAsync(ctx->fileList,0,1)==0){WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);break;}
        WIFIBATTLEMATCH_NET_NdSetState(ctx,3);break;
    case 3:
        count=0xb0;
        if(WIFIBATTLEMATCH_NET_IsBufferZero((const unsigned int *)(ctx->fileList),0xb0)==0) {
            count+=0xb0;
            if(DWC_NdGetFileAsync(ctx->fileList,(char *)(ctx->regulationCard),count)==0){WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);break;}
            d_021E4B80[0]=0;*(u32 *)(d_021E4B80+4)=0;
            ctx->state=4;
        } else {
            if(DWC_NdCleanupAsync()==0) {ctx->downloadActive=0;return 2;}
            WIFIBATTLEMATCH_NET_NdSetState(ctx,7);
        }
        break;
    case 4:
        DWC_NdProcess();
        if((ctx->pollCount)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);WIFIBATTLEMATCH_NET_NdCancelState(ctx,8);}
        if(d_021E4B80[0]==0) {
            if(DWC_NdGetProgress((unsigned long *)((u32 *)(&ctx->downloadDone)),(unsigned long *)((u32 *)(&ctx->downloadTotal)))==1) {
                percent=(ctx->downloadDone*100)/ctx->downloadTotal;
                if(ctx->downloadPercent!=percent)ctx->downloadPercent=percent;
            }
        } else {
            if(*(u32 *)(d_021E4B80+4)!=0) {
                if(*(u32 *)(d_021E4B80+4)==8)GFL_NET_ERR_HaltIfActive();
                else WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);
            } else {
                if(DWC_NdCleanupAsync()==0) {ctx->downloadActive=0;return 3;}
                WIFIBATTLEMATCH_NET_NdSetState(ctx,5);
            }
        }
        break;
    case 5:ctx->state=6;break;
    case 6:
        if(REGULATION_Card_IsCrcValid((struct RegulationCard *)((struct BattleCompetitionSave *)(ctx->regulationCard)))!=0) {ctx->downloadActive=0;return 1;}
        ctx->downloadActive=0;return 2;
    case 7:ctx->downloadActive=0;return 2;
    case 8:ctx->downloadActive=0;return 3;
    case 100:
        DWC_NdProcess();
        if((ctx->pollCount)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);WIFIBATTLEMATCH_NET_NdCancelState(ctx,8);}
        if(*(u32 *)(d_021E4B80+4)!=0) {
            if(*(u32 *)(d_021E4B80+4)==8)GFL_NET_ERR_HaltIfActive();
            else WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);
        }
        if(d_021E4B80[0]!=0) {
            d_021E4B80[0]=0;
            if(*(u32 *)(d_021E4B80+4)==0)ctx->state=ctx->nextState;
        }
        break;
    case 200:
        DWC_NdProcess();
        if(d_021E4B80[1]!=0) {d_021E4B80[1]=0;ctx->state=ctx->nextState;}
        break;
    case 300:
        DWC_NdProcess();
        if(d_021E4B80[0]!=0) {d_021E4B80[0]=0;WIFIBATTLEMATCH_NET_NdCleanupState(ctx,ctx->nextState);}
        break;
    }
    return 0;
}

/*
 * lever: unlabelled zero-word test blocking matched caller021DC338.
 */
int WIFIBATTLEMATCH_NET_IsBufferZero(const u32 *buffer,u32 bytes)
{
    u32 i;
    for(i=0;i<(bytes>>2);i++)if(buffer[i]!=0)return 0;
    return 1;
}

/*
 * note:     the listing extent (72 B) runs into the neighbour's `mov r8,r8`
 *           pad and pool word; all 48 compiled bytes match.
 *
 * Kind 3 or 6 teardown of the +0x121c sub-object: its handle is unregistered
 * from both pools, the slot cleared, and the object recomputed.
 */
void WIFIBATTLEMATCH_NET_CleanupDownload(void *arg, u32 errorCode, u32 kind, int dwcError)
{
    struct WifiBattleMatchNetCtx *ctx = arg;
    if (kind != 3 && kind != 6)
        return;
    if (ctx->rapHandle != 0) {
        NHTTP_RAP_DeleteConnection(ctx->rapHandle);
        NHTTP_RAP_Destroy(ctx->rapHandle);
        ctx->rapHandle = 0;
    }
    WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
}

int WIFIBATTLEMATCH_NET_GetDownloadSize(void *arg, u32 errorCode, u32 kind, int dwcError)
{
    struct WifiBattleMatchNetCtx *ctx = arg;
    if (kind == 3 || kind == 6) return ctx->downloadActive;
    return 0;
}

/*
 * note:     the listing extent (148 B) covers the following leaf and pool
 *           words as well; every compiled byte of this 92-byte body matches.
 *
 * Thumb jump table over 0..9: the startup mode reports 0x34..0x3b from its own
 * single-return blocks, mode 0 runs the 0x02034714 job with the 0x021E2EF8
 * record on both the first and third argument and reports 0, and mode 9 shares
 * the default's 0x3c block (stacked `case 9: default:` labels, which is what
 * keeps the table at ten entries and the block count at nine).
 */
int WIFIBATTLEMATCH_NET_DownloadError(unsigned int a)
{
    switch (a) {
    case 0:
        GF_PANIC_Fail(PM_LANG_JA((const char *)(g_021E2EF8), str_ja_021E2E38), PM_SRC_LINE(0, 0x14C5), PM_LANG_JA((const char *)((sptr)g_021E2EF8), str_ja_021E2E50));
        return 0;
    case 1:
        return 0x34;
    case 2:
        return 0x35;
    case 3:
        return 0x36;
    case 4:
        return 0x37;
    case 5:
        return 0x38;
    case 6:
        return 0x39;
    case 7:
        return 0x3a;
    case 8:
        return 0x3b;
    case 9:
    default:
        return 0x3c;
    }
}

void WIFIBATTLEMATCH_NET_GetRegCardName(struct WifiBattleMatchNetCtx *ctx,void *out)
{
    MI_CpuCopy8(ctx->regulationCard,out,0x160);
}

/*
 * lever: unlabelled asynchronous state setter blocking matched caller021DC338.
 */
void WIFIBATTLEMATCH_NET_NdSetState(struct WifiBattleMatchNetCtx *ctx,int state)
{
    d_021E4B80[0]=0;
    *(u32 *)(d_021E4B80+4)=0;
    ctx->nextState=state;
    ctx->state=100;
    ctx->pollCount=0;
}

void WIFIBATTLEMATCH_NET_NdCleanupState(struct WifiBattleMatchNetCtx *ctx,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; ctx->nextState=state; ctx->state=200; if(DWC_NdCleanupAsync()==0) ctx->nextState=state; }

void WIFIBATTLEMATCH_NET_NdCancelState(struct WifiBattleMatchNetCtx *ctx,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; ctx->nextState=state; ctx->state=300; if(DWC_NdCancelAsync()==0) ctx->nextState=state; }

void WIFIBATTLEMATCH_NET_NdSetError(int reason,int kind,int serverError) { switch(kind) { case 0:case 1:case 2:case 3:case 4:case 5:case 7: break; case 6:case 8: GFL_NET_ERR_HaltIfActive(); break; } d_021E4B80[0]=1; *(u32 *)(d_021E4B80+4)=kind; d_021E4B80[1]=1; }

void WIFIBATTLEMATCH_NET_CreateHttpRap(struct WifiBattleMatchNetCtx *ctx,u16 heap)
{
    if(ctx->rapHandle!=0) GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38),PM_SRC_LINE(0, 0x157A),PM_LANG_JA(d_021E2EF8, str_ja_021E2F98));
    ctx->state=0;
    ctx->rapHandle=NHTTP_RAP_Create(heap,MYSTATUS_GetProfileId((const struct MyStatus *)GAME_DATA_GetMyStatus(ctx->save)),ctx->heap);
}

/*
 * checks: 1 copied own ov114/DC610 signatures and ARM9 blocker input reads; 2 existing DC8A0 Pair twin used; 3 Pair replaces scalar two-word copy; 4 aggregate-copy idioms applied; 5 fresh directory and ov175 neighbours read. Caller TU MATCH has no viable split; only ARM90200FB4C blocks it.
 * lever: Pair aggregate assignment fixes all four payload-copy register bytes; TU --suggest-split confirms MATCH, no viable cut.
 * extent: lead 292 bytes; following 20-byte DC8A0 is already B7's src/matched/ov/WIFIBATTLEMATCH_NET_GetRapPair.c.
 */
int WIFIBATTLEMATCH_NET_HttpRapProcess(struct WifiBattleMatchNetCtx *ctx)
{
    int query,status;
    const u8 *r;
    if(ctx->rapHandle==0)return 2;
    switch(ctx->state) {
    case 0:
        if(NHTTP_RAP_CreateRequest(5,ctx->rapHandle)!=0)ctx->state=1;
        break;
    case 1:
        if(NHTTP_RAP_StartConnection(ctx->rapHandle)==0) {ctx->state=2;break;}
        if(ctx->rapHandle!=0) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
        return 2;
    case 2:
        query=NHTTP_RAP_GetResultCode(ctx->rapHandle);
        status=NHTTP_RAP_PollConnection(ctx->rapHandle);
        if(status==0) {
            r=(const unsigned char *)NHTTP_RAP_GetRecvBuffer(ctx->rapHandle);
            if(query!=0x1f6) {
                if(query==0x1f7) {ctx->state=4;GFL_NET_ERR_RaiseFatal(62);return 0;}
            } else {ctx->state=4;GFL_NET_ERR_RaiseFatal(63);return 0;}
            ctx->rapPair=*(const WifibattlematchNetPair *)(r+0x80);
            if(*(u32 *)r==0)ctx->state=3;
            else {GFL_NET_ERR_RaiseFatal(WIFIBATTLEMATCH_NET_DownloadError(*(u32 *)r));ctx->state=4;}
        } else if(status!=15) {
            if(ctx->rapHandle!=0) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
            return 2;
        }
        break;
    case 4:
        MI_CpuFill8((void *)&ctx->rapPair,0,8);
        if(ctx->rapHandle!=0) {
            NHTTP_RAP_DeleteConnection(ctx->rapHandle);NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;
        }
        return 3;
    case 3:
        if(ctx->rapHandle!=0) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
        return 1;
    }
    return 0;
}

/*
 * Pair aggregate assignment preserves the forward load and store order.
 * leaf: coordinated transfer from B10's extent to unblock 021D6C54.
 */
void WIFIBATTLEMATCH_NET_GetRapPair(const struct WifiBattleMatchNetCtx *ctx,WifibattlematchNetPair *out)
{
    *out=ctx->rapPair;
}

void WIFIBATTLEMATCH_NET_SetupHttpRap(struct WifiBattleMatchNetCtx *ctx, const W *src, u16 x)
{
    if (ctx->rapHandle != 0)
        GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x1619), PM_LANG_JA(d_021E2EF8, str_ja_021E2F98));
    ctx->rapHandle = NHTTP_RAP_Create(x, MYSTATUS_GetProfileId((const struct MyStatus *)GAME_DATA_GetMyStatus(ctx->save)), ctx->heap);
    ctx->postData = *src;
    ctx->state = 0;
}

int WIFIBATTLEMATCH_NET_HttpRapSend(struct WifiBattleMatchNetCtx *ctx)
{
    int result;
    int status;
    u32 *data;
    if(ctx->rapHandle==0) return 2;
    switch(ctx->state) {
    case 0:
        if(NHTTP_RAP_CreateRequest(6,ctx->rapHandle)) {
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(ctx->rapHandle),&ctx->postData,8);
            ctx->state=1;
        }
        break;
    case 1:
        if(!NHTTP_RAP_StartConnection(ctx->rapHandle)) ctx->state=2;
        else {
            if(ctx->rapHandle) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
            return 2;
        }
        break;
    case 2:
        result=NHTTP_RAP_GetResultCode(ctx->rapHandle);
        status=NHTTP_RAP_PollConnection(ctx->rapHandle);
        if(status==0) {
            data=(u32 *)NHTTP_RAP_GetRecvBuffer(ctx->rapHandle);
            switch(result) {
            case 0x1f7: ctx->state=3;GFL_NET_ERR_RaiseFatal(0x3e);return 0;
            case 0x1f6: ctx->state=3;GFL_NET_ERR_RaiseFatal(0x3f);return 0;
            default:
                if(*data==0) ctx->state=4;
                else {GFL_NET_ERR_RaiseFatal(WIFIBATTLEMATCH_NET_DownloadError(*data));ctx->state=3;}
                break;
            }
        } else if(status!=15) {
            WIFIBATTLEMATCH_NET_SetResultD(&ctx->err,status,PM_SRC_LINE(0x16a0, 0x1678));
            if(ctx->rapHandle) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
            return 2;
        }
        break;
    case 3:
        if(ctx->rapHandle) {
            NHTTP_RAP_DeleteConnection(ctx->rapHandle);
            NHTTP_RAP_Destroy(ctx->rapHandle);
            ctx->rapHandle=0;
        }
        return 3;
    case 4:
        if(ctx->rapHandle) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
        return 1;
    }
    return 0;
}

/*
 * Starts a profanity check of the string in window a1: copies it into the 20-character buffer at +0x1468 (the terminator code 0x02045A98 returns becomes 0), and submits it with DWC_CheckProfanityExAsync (one word, results at +0x1484/+0x1488, region 0x80).
 */
void WIFIBATTLEMATCH_NET_StartProfanityCheck(struct WifiBattleMatchNetCtx *obj, void *win, u16 tag)
{
    uptr str;
    u16 *src;
    unsigned long i;

    obj->profanityWindow = win;
    str = (uptr)MYSTATUS_CreateNameStrbuf(win, obj->heapTag);
    MI_CpuFill8(obj->profanityText, 0, 0x28);
    obj->profanityTag = tag;
    src = STRBUF_GetChars((struct Strbuf *)str);
    for (i = 0; i < STRBUF_GetLength((struct Strbuf *)str) + 1; i++) {
        u16 ch = src[i];
        if (ch == STRBUF_GetEosChar())
            *(u16 *)(obj->profanityText + i * 2) = 0;
        else
            *(u16 *)(obj->profanityText + i * 2) = ch;
    }
    obj->profanityWords = (u16 *)(obj->profanityText);
    obj->profanityCount = 0;
    DWC_CheckProfanityExAsync((u16 **)(&obj->profanityWords), 1, 0, 0, (char *)&obj->profanityResult, (int *)(&obj->profanityCount), 0x80);
    STRBUF_Delete((struct Strbuf *)str);
}

/*
 * Polls the profanity check; once it has finished (state 2) reports whether the +0x1488 count is positive, and when it is, loads message 0x51 for the +0x124 id and hands it to the +0x1490 window.
 */
int WIFIBATTLEMATCH_NET_ProfanityProcess(struct WifiBattleMatchNetCtx *obj, int *out)
{
    int state = DWC_CheckProfanityProcess();
    int done = 1;

    if (state != 2)
        done = 0;
    if (done)
        *out = obj->profanityCount > 0 ? 1 : 0;
    if (done == 1 && *out == 1) {
        struct MsgBank *msg = MSGDATA_CreateFromArchive(0, 2, 0x51, obj->heapTag);
        struct Strbuf *str = MSGDATA_AllocString(msg, MSG_PROFANITY_NOTICE);
        MSGDATA_Delete(msg);
        MYSTATUS_NameFromStrbuf((u16 *)obj->profanityWindow, str);
        STRBUF_Delete(str);
    }
    return done;
}

void WIFIBATTLEMATCH_NET_SetupPostData(struct WifiBattleMatchNetCtx *ctx,void *party,int mode)
{
    int i;
    unsigned size;
    void *mon;
    i=0;
    ctx->state=0;
    ctx->rapHandle=NHTTP_RAP_Create(ctx->heapTag,MYSTATUS_GetProfileId((const struct MyStatus *)GAME_DATA_GetMyStatus(ctx->save)),ctx->heap);
    switch(mode) {
    case 0:
        NHTTP_RAP_AllocPostData(ctx->rapHandle,ctx->heapTag,POKE_TOOL_GetPartyParamSize(),0);
        NHTTP_RAP_AppendPostData(ctx->rapHandle,(const void *)(party),POKE_TOOL_GetPartyParamSize());
        ctx->postMonCount=1;
        break;
    case 1:
        size=POKE_TOOL_GetPartyParamSize();
        NHTTP_RAP_AllocPostData(ctx->rapHandle,ctx->heapTag,size*POKEPARTY_GetCount((const struct Party *)party),0);
        for(i=0;i<(int)POKEPARTY_GetCount((const struct Party *)party);i++) {
            mon=POKEPARTY_GetMember((struct Party *)party,i);
            NHTTP_RAP_AppendPostData(ctx->rapHandle,(const void *)(mon),POKE_TOOL_GetPartyParamSize());
        }
        ctx->postMonCount=POKEPARTY_GetCount(party);
        break;
    }
}

static inline void clear(struct WifiBattleMatchNetCtx *ctx)
{
    if(ctx->rapHandle) {
        NHTTP_RAP_Destroy(ctx->rapHandle);
        ctx->rapHandle=0;
        ctx->state=0;
    }
}

static inline void release(struct WifiBattleMatchNetCtx *ctx)
{
    if(ctx->rapHandle) {
        NHTTP_RAP_FreePostData(ctx->rapHandle);
        NHTTP_RAP_Destroy(ctx->rapHandle);
        NHTTP_RAP_DeleteConnection(ctx->rapHandle);
        ctx->rapHandle=0;
        ctx->state=0;
    }
}

/*
 * blocker-C: copied verified32B Thumb EXACT from ov116_func_021D7200.c header, prior scratch blocker-1.log, dsi/1.1p1 -O4,p.
 * extern unsigned char gNetErrWork[],g_021461BC[];
 * void GFL_NET_ERR_RaiseFatal(int a) {
 *   if(*(int *)(gNetErrWork+44)!=2) {
 *     *(int *)(gNetErrWork+96)=a;
 *     g_021461BC[26]=1;g_021461BC[25]=1;
 *     *(int *)(gNetErrWork+44)=2;
 *   }
 * }
 * Blocker symbols: gNetErrWork 0x0214617C data; g_021461BC 0x021461BC data.
 * abi: CE58 retains visibly loaded third argument despite its two-argument body; 9A14 reads live r1, the count last loaded by the loop.
 */
int WIFIBATTLEMATCH_NET_HttpRapPost(struct WifiBattleMatchNetCtx *ctx,u8 *out)
{
    int result;
    int status;
    u32 i;
    u8 *data;
    switch(ctx->state) {
    case 0:
        if(NHTTP_RAP_CreatePostRequest(ctx->rapHandle)) {
            if(!NHTTP_RAP_StartConnection(ctx->rapHandle)) (ctx->state)++;
            else {clear(ctx);return 2;}
        } else {clear(ctx);return 2;}
        break;
    case 1:
        result=NHTTP_RAP_GetResultCode(ctx->rapHandle);
        status=NHTTP_RAP_PollConnection(ctx->rapHandle);
        if(status==0) {
            switch(result) {
            case 400: GFL_NET_ERR_RaiseFatal(0x41);release(ctx);return 3;
            case 401: GFL_NET_ERR_RaiseFatal(0x42);release(ctx);return 3;
            case 408: GFL_NET_ERR_RaiseFatal(0x44);release(ctx);return 3;
            default: GFL_NET_ERR_RaiseFatal(0x43);release(ctx);return 3;
            case 200: (ctx->state)++;break;
            }
        } else if(status!=15) {
            WIFIBATTLEMATCH_NET_SetResultD(&ctx->err,status,PM_SRC_LINE(0x17a4, 0x177C));
            NHTTP_RAP_FreePostData(ctx->rapHandle);
            clear(ctx);
            return 2;
        }
        break;
    case 2:
        data=(unsigned char *)NHTTP_RAP_GetRecvBuffer(ctx->rapHandle);
        *out=NHTTP_RAP_RecordList_GetCount((NHTTPRapRecordList *)data);
        for(i=0;i<ctx->postMonCount;i++) *(u32 *)(out+4+i*4)=NHTTP_RAP_RecordList_GetValue((NHTTPRapRecordList *)(data),i);
        if(*out==0) MI_CpuCopy8((const void *)(NHTTP_RAP_RecordList_GetRecord((NHTTPRapRecordList *)data,ctx->postMonCount)),(void *)(out+0x1c),128);
        NHTTP_RAP_FreePostData(ctx->rapHandle);
        if(ctx->rapHandle) {NHTTP_RAP_Destroy(ctx->rapHandle);ctx->rapHandle=0;}
        return 1;
    }
    return 0;
}

/*
 * The +0x14 sibling of WIFIBATTLEMATCH_NET_SetResultD: stores the caller's word at +0x18,
 *     hard-codes 5 at +0x1c and then calls 0x0203C9AC(0, 0, 0, 0x3F5).
 */
void WIFIBATTLEMATCH_NET_SetErrorA(struct NetErrRecord *ctx, u32 v, int line)
{
    ctx->errCode = v;
    ctx->errKind = 5;
    GFL_NET_STATE_SetError(0, 0, 0, 0x3F5);
}

/*
 * Set the word at +0 and mark the object armed at +0x1c, then start the
 * 0x3f7 service with a zeroed first three arguments.
 */
void WIFIBATTLEMATCH_NET_SetErrorB(struct NetErrRecord *ctx, int v, int unused)
{
    ctx->errValue = v;
    ctx->errKind = 1;
    GFL_NET_STATE_SetError(0, 0, 0, 0x3f7);
}

/*
 * Two-word setter: stores the caller's word at +4 and hard-codes 2 at +0x1c.
 */
void WIFIBATTLEMATCH_NET_SetResultA(struct NetErrRecord *ctx, u32 v, int line)
{
    ctx->resultA = v;
    ctx->errKind = 2;
}

void WIFIBATTLEMATCH_NET_SetResultB(struct NetErrRecord *ctx, u32 v, int line)
{
    ctx->resultB = v;
    ctx->errKind = 2;
}

/*
 * Two-word setter: stores the caller's word at +0xc and hard-codes 2 at +0x1c.
 */
void WIFIBATTLEMATCH_NET_SetResultC(struct NetErrRecord *ctx, u32 v, int line)
{
    ctx->resultC = v;
    ctx->errKind = 2;
}

/*
 * Symbols:
 *   (none)
 *
 * Two-word setter on an ov175 context block: stores the caller's word at
 * +0x14 and hard-codes 4 at +0x1c.  A leaf with no prologue, so disasm.py
 * only found it through a branch target.
 */
void WIFIBATTLEMATCH_NET_SetResultD(struct NetErrRecord *ctx, u32 v, u32 unused)
{
    ctx->resultD = v;
    ctx->errKind = 4;
}

/*
 * Maps a code 0..14 to a class: 0 for code 0, 2 for codes 1 to 14; any other code asserts and yields 0.
 */
u32 WIFIBATTLEMATCH_NET_GetErrorMsg(int a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 2;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8:
        return 2;
    case 9:
        return 2;
    case 10:
        return 2;
    case 11:
        return 2;
    case 12:
        return 2;
    case 13:
        return 2;
    case 14:
        return 2;
    }
    GF_PANIC_Fail(PM_LANG_JA(d_021E2EF8, str_ja_021E2E38), PM_SRC_LINE(0, 0x187D), PM_LANG_JA(d_021E2EF8, str_ja_021E2E50));
    return 0;
}

/*
 * Three-level classifier: the first code decides when it can (1 or 2); codes 0 and 20 and unknown ones fall to the second, then the third; 0 when none decides.
 */
u32 WIFIBATTLEMATCH_NET_GetErrorCode(int a, int b, int c)
{
    switch (a) {
    case 0:
        break;
    case 1: case 2: case 3: case 4: case 5:
        return 2;
    case 6: case 7: case 8: case 9: case 10: case 11:
    case 12: case 13: case 14: case 15: case 16:
        return 1;
    case 17: case 18:
        return 2;
    case 19:
        return 1;
    case 20:
        break;
    case 21: case 22:
        return 2;
    }
    switch (b) {
    case 0:
        return 1;
    case 1: case 2: case 3:
        break;
    case 4:
        return 2;
    }
    switch (c) {
    case 0: case 1:
        break;
    case 2:
        return 2;
    case 3:
        return 2;
    case 4:
        return 1;
    case 5:
        return 2;
    case 6:
        return 2;
    case 7:
        return 2;
    case 8: case 9: case 10:
        return 2;
    case 11: case 12: case 13: case 14: case 15: case 16:
        return 1;
    case 17: case 18: case 19: case 20: case 21:
        return 1;
    case 22:
        return 2;
    case 23: case 24: case 25: case 26: case 27:
        return 1;
    case 28: case 29:
        return 2;
    case 30: case 31:
        return 2;
    }
    return 0;
}

/*
 * Maps 0, 1, 2 to themselves and everything else to 0.
 */
u32 WIFIBATTLEMATCH_NET_MapErrorCode(u32 v)
{
    switch (v) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}

/*
 * Tail call: clears the second and third arguments to 0 and 0x20 and
 *  *  hands r0 straight to 0x02082BCC (arm9); no lr save, so the call is a
 *  *  pooled `ldr r3; bx r3`.
 */
void WIFIBATTLEMATCH_NET_ClearStruct(void *ctx)
{
    MI_CpuFill8(ctx, 0, 0x20);
}

void WIFIBATTLEMATCH_NET_RestartNet(struct WifiBattleMatchNetCtx *ctx, int flag)
{
    if (flag == 0)
        return;
    GFL_NET_RefreshWmIconAtTopRight(1, ctx->heapTag);
}

/*
 * Tail call to the arm9 Thumb routine 0x02009CC0 with the object's
 *  *  +0x04 field; pooled `ldr r3; bx r3`, so nothing is saved.
 */
u32 WIFIBATTLEMATCH_NET_GetGsProfileId(struct WifiBattleMatchNetCtx *obj)
{
    return WIFILIST_GetGsProfileId((void *)(obj->gsProfileId));
}

/*
 * Returns the address of the ov175 table at 0x021E3270.
 */
char *WIFIBATTLEMATCH_NET_GetRegNameA(void)
{
    return d_021E3270;
}

/*
 * Constant getter: returns 0x15.
 */
u32 WIFIBATTLEMATCH_NET_GetRegKindA(void)
{
    return 0x15;
}

/*
 * Returns the address of the ov175 table at 0x021E3250.
 */
char *WIFIBATTLEMATCH_NET_GetRegNameB(void)
{
    return d_021E3250;
}

/*
 * Constant getter: returns 8.
 */
u32 WIFIBATTLEMATCH_NET_GetRegKindB(void)
{
    return 8;
}

const char *WIFIBATTLEMATCH_NET_LookupFieldEntry(int a)
{
    if (a <= 0)
        return (const char *)g_021E32C4;
    if (a == 0x1e)
        return (const char *)g_021E32C8;
    if (a == 0x14)
        return (const char *)g_021E32E0;
    if (a == 0x15)
        return (const char *)g_021E32FC;
    if (a == 0x17)
        return (const char *)g_021E3318;
    if (a == 0x13)
        return (const char *)g_021E3338;
    if (a == 0x16)
        return (const char *)g_021E3354;
    if (a == 0x24)
        return (const char *)g_021E3370;
    if (a == 0x19)
        return (const char *)g_021E3390;
    if (a == 0x1a)
        return (const char *)g_021E33B0;
    if (a == 0x1c)
        return (const char *)g_021E33D0;
    if (a == 0x23)
        return (const char *)g_021E33E8;
    if (a == 0x1d)
        return (const char *)g_021E3400;
    if (a == 0x1f)
        return (const char *)g_021E3418;
    if (a == 0x20)
        return (const char *)g_021E3430;
    if (a == 0x21)
        return (const char *)g_021E3448;
    if (a == 0x1b)
        return (const char *)g_021E3460;
    if (a == 0x18)
        return (const char *)g_021E347C;
    if (a == 0x27)
        return (const char *)g_021E348C;
    if (a == 0x4)
        return (const char *)g_021E34A4;
    if (a == 0x3)
        return (const char *)g_021E34C0;
    if (a == 0x28)
        return (const char *)g_021E34D4;
    if (a == 0xb)
        return (const char *)g_021E34F0;
    if (a == 0xc)
        return (const char *)g_021E3508;
    if (a == 0xe)
        return (const char *)g_021E3520;
    if (a == 0xd)
        return (const char *)g_021E3538;
    if (a == 0x12)
        return (const char *)g_021E3550;
    if (a == 0x11)
        return (const char *)g_021E356C;
    if (a == 0xa)
        return (const char *)g_021E3584;
    if (a == 0x9)
        return (const char *)g_021E359C;
    if (a == 0x10)
        return (const char *)g_021E35B4;
    if (a == 0xf)
        return (const char *)g_021E35CC;
    if (a == 0x26)
        return (const char *)g_021E35E4;
    if (a == 0x25)
        return (const char *)g_021E3600;
    if (a == 0x22)
        return (const char *)g_021E3618;
    return (const char *)g_021E32C4;
}
