/*
 * file:     wifibattlematch_net.c
 * unit:     yes
 * function: WIFIBATTLEMATCH_NET_Create, WIFIBATTLEMATCH_NET_Close, WIFIBATTLEMATCH_NET_Other, WIFIBATTLEMATCH_NET_TaskCreate, WIFIBATTLEMATCH_NET_TaskDestroy, WIFIBATTLEMATCH_NET_TaskMain, WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState, WIFIBATTLEMATCH_NET_TaskStepMainMenu, WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer, WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord, WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake, WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave, WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError, WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry, WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit, WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit, WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer, WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake, WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave, WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt, WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry, WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit, WIFIBATTLEMATCH_NET_TaskCleanupA, WIFIBATTLEMATCH_NET_TaskCleanupB, WIFIBATTLEMATCH_NET_TaskStepPostPartyData, WIFIBATTLEMATCH_NET_SetupBoxRecord, WIFIBATTLEMATCH_NET_DeleteBoxRecord, WIFIBATTLEMATCH_NET_IsBoxReady, WIFIBATTLEMATCH_NET_IsBoxAnimDone, WIFIBATTLEMATCH_NET_SetupBoxAndWait, WIFIBATTLEMATCH_NET_DeleteBoxAndWait, WIFIBATTLEMATCH_NET_CreateRegCardWindow, WIFIBATTLEMATCH_NET_DeleteRegCard, WIFIBATTLEMATCH_NET_IsRegCardReady, WIFIBATTLEMATCH_NET_GetSetBsubwayStat, WIFIBATTLEMATCH_NET_IncBsubwayStat, WIFIBATTLEMATCH_NET_SetupChoiceMenu, WIFIBATTLEMATCH_NET_DeleteChoiceMenu, WIFIBATTLEMATCH_NET_PollChoiceMenu, WIFIBATTLEMATCH_NET_CopyBoxRecord, WIFIBATTLEMATCH_NET_CopyBoxSave, WIFIBATTLEMATCH_NET_CopyBsubwayStat, WIFIBATTLEMATCH_NET_SetWaitCallback, WIFIBATTLEMATCH_NET_PollWaitResult, WIFIBATTLEMATCH_NET_VerifyPartySignature, WIFIBATTLEMATCH_NET_HandleCancel, WIFIBATTLEMATCH_NET_ClearError, WIFIBATTLEMATCH_NET_CompCreate, WIFIBATTLEMATCH_NET_CompDestroy, WIFIBATTLEMATCH_NET_CompMain, WIFIBATTLEMATCH_NET_CompStepRouteByEntryState, WIFIBATTLEMATCH_NET_CompStepFetchRapPair, WIFIBATTLEMATCH_NET_CompStepReconcileEntryState, WIFIBATTLEMATCH_NET_CompStepRegisterParty, WIFIBATTLEMATCH_NET_CompStepMainMenu, WIFIBATTLEMATCH_NET_CompStepMatchmake, WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult, WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle, WIFIBATTLEMATCH_NET_CompStepAskRetry, WIFIBATTLEMATCH_NET_CompStepConfirmQuit, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit, WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit, WIFIBATTLEMATCH_NET_CompExit, WIFIBATTLEMATCH_NET_CompCleanup, WIFIBATTLEMATCH_NET_CompStepCheckPeriod, WIFIBATTLEMATCH_NET_CompStepWithdrawEntry, WIFIBATTLEMATCH_NET_CompStepPostPartyData, WIFIBATTLEMATCH_NET_SetupCompStatusWindow, WIFIBATTLEMATCH_NET_DeleteCompStatusWindow, WIFIBATTLEMATCH_NET_IsCompStatusWindowReady, WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle, WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait, WIFIBATTLEMATCH_NET_DrawCompStatusWindow, WIFIBATTLEMATCH_NET_StartRegCardAnim, WIFIBATTLEMATCH_NET_DeleteCompRegCard, WIFIBATTLEMATCH_NET_IsCompRegCardReady, WIFIBATTLEMATCH_NET_SetupCompPartyWindow, WIFIBATTLEMATCH_NET_DeleteCompPartyWindow, WIFIBATTLEMATCH_NET_IsCompPartyWindowReady, WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle, WIFIBATTLEMATCH_NET_SetupCompChoiceMenu, WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu, WIFIBATTLEMATCH_NET_PollCompChoiceMenu, WIFIBATTLEMATCH_NET_SetCompWaitCallback, WIFIBATTLEMATCH_NET_GetCompWaitResult, WIFIBATTLEMATCH_NET_CopyCompBox, WIFIBATTLEMATCH_NET_CopyCompSave, WIFIBATTLEMATCH_NET_CopyCompResponse, WIFIBATTLEMATCH_NET_VerifyCompSignature, WIFIBATTLEMATCH_NET_CompareParty, WIFIBATTLEMATCH_NET_CompHandleCancel, WIFIBATTLEMATCH_NET_CompClearError, WIFIBATTLEMATCH_NET_GetSetCompStat, WIFIBATTLEMATCH_NET_CreateNetContext, WIFIBATTLEMATCH_NET_DeleteNetContext, WIFIBATTLEMATCH_NET_Noop, WIFIBATTLEMATCH_NET_SetTimingSyncRange, WIFIBATTLEMATCH_NET_IsTimingSyncRange, WIFIBATTLEMATCH_NET_HandleNetError, WIFIBATTLEMATCH_NET_ClearErrorFlags, WIFIBATTLEMATCH_NET_StepGdbEnsureRecord, WIFIBATTLEMATCH_NET_SetMatchKey, WIFIBATTLEMATCH_NET_StartMatchmaking, WIFIBATTLEMATCH_NET_DisconnectWifi, WIFIBATTLEMATCH_NET_ClearCancelFlag, WIFIBATTLEMATCH_NET_StopMatchmaking, WIFIBATTLEMATCH_NET_SendSessionQuery, WIFIBATTLEMATCH_NET_TakeSessionResult, WIFIBATTLEMATCH_NET_GetDateTime, WIFIBATTLEMATCH_NET_AddMatchKey, WIFIBATTLEMATCH_NET_GetMatchKeyInt, WIFIBATTLEMATCH_NET_GetMatchKeyDefault, WIFIBATTLEMATCH_NET_GetMatchKeyValue, WIFIBATTLEMATCH_NET_SetupMatchReport, WIFIBATTLEMATCH_NET_ScProcess, WIFIBATTLEMATCH_NET_GetReportState, WIFIBATTLEMATCH_NET_OnReportResultA, WIFIBATTLEMATCH_NET_OnReportResultB, WIFIBATTLEMATCH_NET_OnReportResultC, WIFIBATTLEMATCH_NET_ShutdownReport, WIFIBATTLEMATCH_NET_SubmitReport, WIFIBATTLEMATCH_NET_ReportAddRecord, WIFIBATTLEMATCH_NET_ReportAddTeam, WIFIBATTLEMATCH_NET_ReportAddWin, WIFIBATTLEMATCH_NET_ReportAddLoss, WIFIBATTLEMATCH_NET_ReportAddDisconnectWin, WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss, WIFIBATTLEMATCH_NET_OnRecvPlayerData, WIFIBATTLEMATCH_NET_OnRecvStatus, WIFIBATTLEMATCH_NET_GetPlayerBuffer, WIFIBATTLEMATCH_NET_OnRecvFlagA, WIFIBATTLEMATCH_NET_OnRecvFlagB, WIFIBATTLEMATCH_NET_OnRecvFlagC, WIFIBATTLEMATCH_NET_OnRecvValue, WIFIBATTLEMATCH_NET_GdbRequest, WIFIBATTLEMATCH_NET_GdbGetMyRecords, WIFIBATTLEMATCH_NET_GdbShutdown, WIFIBATTLEMATCH_NET_SetupGdbRecord, WIFIBATTLEMATCH_NET_GdbSortByName, WIFIBATTLEMATCH_NET_GdbCopyFieldsA, WIFIBATTLEMATCH_NET_GdbCopyFieldsB, WIFIBATTLEMATCH_NET_GdbCopyFieldC, WIFIBATTLEMATCH_NET_GdbCopyFieldD, WIFIBATTLEMATCH_NET_GdbCopyFieldE, WIFIBATTLEMATCH_NET_SetupGdbUpload, WIFIBATTLEMATCH_NET_GdbUpdateRecord, WIFIBATTLEMATCH_NET_GdbClearRecord, WIFIBATTLEMATCH_NET_GdbCreateRecord, WIFIBATTLEMATCH_NET_GetNetId, WIFIBATTLEMATCH_NET_SendRegData, WIFIBATTLEMATCH_NET_TakeRegData, WIFIBATTLEMATCH_NET_SendRegDataAlt, WIFIBATTLEMATCH_NET_TakeRegBuffer, WIFIBATTLEMATCH_NET_SendRegFlag, WIFIBATTLEMATCH_NET_TakeRegFlag, WIFIBATTLEMATCH_NET_SendRegValue, WIFIBATTLEMATCH_NET_TakeRegValue, WIFIBATTLEMATCH_NET_SetupDownload, WIFIBATTLEMATCH_NET_DownloadProcess, WIFIBATTLEMATCH_NET_IsBufferZero, WIFIBATTLEMATCH_NET_CleanupDownload, WIFIBATTLEMATCH_NET_GetDownloadSize, WIFIBATTLEMATCH_NET_DownloadError, WIFIBATTLEMATCH_NET_GetRegCardName, WIFIBATTLEMATCH_NET_NdSetState, WIFIBATTLEMATCH_NET_NdCleanupState, WIFIBATTLEMATCH_NET_NdCancelState, WIFIBATTLEMATCH_NET_NdSetError, WIFIBATTLEMATCH_NET_CreateHttpRap, WIFIBATTLEMATCH_NET_HttpRapProcess, WIFIBATTLEMATCH_NET_GetRapPair, WIFIBATTLEMATCH_NET_SetupHttpRap, WIFIBATTLEMATCH_NET_HttpRapSend, WIFIBATTLEMATCH_NET_StartProfanityCheck, WIFIBATTLEMATCH_NET_ProfanityProcess, WIFIBATTLEMATCH_NET_SetupPostData, WIFIBATTLEMATCH_NET_HttpRapPost, WIFIBATTLEMATCH_NET_SetErrorA, WIFIBATTLEMATCH_NET_SetErrorB, WIFIBATTLEMATCH_NET_SetResultA, WIFIBATTLEMATCH_NET_SetResultB, WIFIBATTLEMATCH_NET_SetResultC, WIFIBATTLEMATCH_NET_SetResultD, WIFIBATTLEMATCH_NET_GetErrorMsg, WIFIBATTLEMATCH_NET_GetErrorCode, WIFIBATTLEMATCH_NET_MapErrorCode, WIFIBATTLEMATCH_NET_ClearStruct, WIFIBATTLEMATCH_NET_RestartNet, WIFIBATTLEMATCH_NET_GetGsProfileId, WIFIBATTLEMATCH_NET_GetRegNameA, WIFIBATTLEMATCH_NET_GetRegKindA, WIFIBATTLEMATCH_NET_GetRegNameB, WIFIBATTLEMATCH_NET_GetRegKindB, WIFIBATTLEMATCH_NET_LookupFieldEntry
 * address:  0x021D4240
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
struct Proc;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct Proc;
struct Big;
struct Sub02009448Obj;
struct Sub02009210Obj;
struct U16Vec;
struct MsgRec;
struct PmsData;
struct L0200ED54;
struct Sub0200852CObj;
struct Record;
struct Work;
struct BigObj;
struct Rec0200E6FC;
struct Party;
struct Rec160;
struct Obj;
struct Rec1E;
struct RecBig;
struct Reg2;
struct Entry;
struct Link;
struct Rec44;
struct Sub24;
struct Field;
typedef int (*Callback)(int,int,int *,int);

typedef struct { Callback create,other,close; } Table;

#include "../types.h"

typedef struct { u32 w[20]; } Rec80;

typedef struct { Rec80 data; u32 last; } Rec84;

typedef unsigned int ul;

typedef struct { u32 kind; u16 count,pad; u32 name,total; u16 a,b; } BoxWindowDesc;

typedef struct { unsigned char a,b,c,d;u32 id;} Request;

typedef struct {char pad[0x104];u32 *ctx;u32 aux;} ObjectView;

typedef struct {char pad[0x48];u32 slots[6];} SlotView;

/* The match-key sub-record at WifiBattleMatchParams.sub (0x34).  CompStepF
 * fills Buf16 from it: keyA (stat 10,0), keyB and the two halves of keyD
 * (keyDBase = stat 10,1, keyDDelta = stat 10,2); GetSetCompStat compares the
 * same three words against the BSUBWAY competition stats. */
struct Sub {
    u32 head;       /* 0x00 first word of the record handed to GdbRequest */
    u32 keyB;       /* 0x04 match key id 5 */
    u32 keyDBase;   /* 0x08 BSUBWAY stat 10,1, first half of keyD */
    u32 keyDDelta;  /* 0x0C BSUBWAY stat 10,2, second half of keyD */
    u32 keyA;       /* 0x10 BSUBWAY stat 10,0, match key id 3 */
    u32 recSeed;    /* 0x14 seed stored into *recLast */
};

/* The match-parameters object handed to both WIFIBATTLEMATCH_NET_TaskCreate
 * (stored at task+0x40) and WIFIBATTLEMATCH_NET_CompCreate (stored at
 * comp+0x104).  Its caller is WIFIBATTLEMATCH_SYS_BuildMatchCommand
 * (0x02212854, src/game/ov199/wifibattlematch_sys.c), the buildFn of the
 * ov175 step-table entry; it allocates the object with
 * GFL_HEAP_Alloc(heap, 0x44, 0, d_02213D04, tag), MI_CpuFill8(p, 0, 0x44), and
 * fills p[0]..p[16] (17 words, offsets 0x00..0x40).  The size is 0x44 bytes.
 * The offsets below are the union of every view that reads it. */
struct WifiBattleMatchParams {
    u32 mode;                   /* 0x00 0 = rating match, 1 = free match */
    u32 netState;               /* 0x04 net sub-state, 3 on cleanup */
    u32 *save;                  /* 0x08 points at the save-control slot */
    u32 state;                  /* 0x0C step state (TaskStepA switch) */
    u32 bsubwaySave;            /* 0x10 handle for BSUBWAY_SAVEDATA_GetStat */
    u8 *profile;                /* 0x14 profile/save record */
    u8 *record;                 /* 0x18 second record block, byte-addressed */
    u32 heap;                   /* 0x1C heap id for CreateNetContext */
    u32 *statPtr;               /* 0x20 points at a stat word */
    u32 recData;                /* 0x24 first half of the result record */
    u32 *recLast;               /* 0x28 second half of the result record */
    u32 saveBlock;              /* 0x2C save/regulation block */
    u32 session;                /* 0x30 session/peer object (byte at +5) */
    struct Sub *sub;            /* 0x34 */
    u32 statRecord;             /* 0x38 record read by GetSetBsubwayStat */
    u32 profileId;              /* 0x3C passed as CreateNetContext's first arg */
    u32 *resultPtr;             /* 0x40 */
};

/* INV-C: the allocation site fixes the size at 0x44 bytes. */
typedef char WifiBattleMatchParams_size_check[(sizeof(struct WifiBattleMatchParams) == 0x44) ? 1 : -1];

/* The stat record reached through WifiBattleMatchParams.profile (0x14) and
 * .record (0x18).  The first 0x20 bytes are a MyStatus copy (MYSTATUS_Copy in
 * CopyCompSave), so 0x18..0x1D carry the MyStatus language/version/gender/
 * avatar/outfit bytes.  The named tail fields are the ones this file fills and
 * compares.  CopyCompBox zeroes 0xD4 bytes and appends the party data. */
struct WifiBattleMatchStatRecord {
    unsigned char pad_00[0x18];  /* 0x00 MyStatus name and id */
    unsigned char language;      /* 0x18 MyStatus language */
    unsigned char version;       /* 0x19 MyStatus version */
    unsigned char gender;        /* 0x1A MyStatus gender */
    unsigned char avatarId;      /* 0x1B MyStatus avatar id */
    unsigned char outfit;        /* 0x1C MyStatus outfit (clamped below 16) */
    unsigned char outfitVariant; /* 0x1D MyStatus outfit variant (0 or 1) */
    unsigned char pad_1E[0xA];   /* 0x1E..0x27 */
    unsigned int keyDBase;       /* 0x28 copy of Sub.keyDBase (Save.blk[2]) */
    unsigned int keyDDelta;      /* 0x2C copy of Sub.keyDDelta (Save.blk[3]) */
    unsigned char pad_30[4];     /* 0x30 */
    unsigned int keyA;           /* 0x34 copy of Sub.keyA (Save.blk[4]) */
    unsigned char quadRecord[8]; /* 0x38 MISC_SAVEDATA quad record / PMSI sentence */
    unsigned int cardValue;      /* 0x40 REGULATION_Card_GetValue(card, 2) */
    unsigned int boxValue;       /* 0x44 100 written by CopyCompBox */
    unsigned int gsProfileId;    /* 0x48 WIFILIST_GetGsProfileId */
    unsigned int netId;          /* 0x4C WIFIBATTLEMATCH_NET_GetNetId */
    unsigned int crc;            /* 0x50 REGULATION_Card_CalcCrc */
};

/* The save/regulation block reached through WifiBattleMatchParams.saveBlock
 * (0x2C).  Handed to SetupMatchReport as a word array and to SetSaveState. */
struct WifiBattleMatchSaveBlock {
    void *head;                  /* 0x00 first word, dereferenced by callers */
    unsigned char pad_04[0x10];  /* 0x04..0x13 */
    unsigned int reportState;    /* 0x14 written by GetReportState */
};

/* The session/peer object reached through WifiBattleMatchParams.session
 * (0x30); only its state byte at +5 is touched here. */
struct WifiBattleMatchSession {
    unsigned char pad_00[5];     /* 0x00..0x04 */
    unsigned char subState;      /* 0x05 session sub-state */
};

/* One 0x68-byte player record of the DWC report block reached through
 * WifiBattleMatchNetCtx.netIdPtr (0x1464).  SubmitReport receives record 0
 * (netIdPtr+4) as ctx and record 1 (netIdPtr+0x6c) as other.  The fields are
 * the arguments of DWC_ScReportSetPlayerData (dwc_sc.c): report handle,
 * login certificate, connection id block and auth hash. */
struct WifiBattleMatchReportPlayer {
    void *certificate;           /* 0x00 GSLoginCertificate (DWC_ScGetLoginCertificate) */
    unsigned int report;         /* 0x04 SCIReport handle (DWC_ScCreateReport) */
    unsigned char pad_08[0x28];  /* 0x08..0x2F */
    unsigned char connectionId[0x28]; /* 0x30 player connection id block */
    unsigned char authHash[0x10];     /* 0x58..0x67 player auth hash */
};

/* The three-word team record at WifiBattleMatchNetCtx + 0x180, handed to
 * SubmitReport as its peer argument. */
struct WifiBattleMatchTeam {
    unsigned int arg;            /* 0x00 */
    unsigned int rec0;           /* 0x04 */
    unsigned int rec4;           /* 0x08 */
};

/* The DWC report block reached through WifiBattleMatchNetCtx.netIdPtr
 * (0x1464): a header word followed by two 0x68-byte player records. */
struct WifiBattleMatchReportBlock {
    unsigned int head;                                 /* 0x00 */
    struct WifiBattleMatchReportPlayer players[2];     /* 0x04, 0x6C */
};

struct Buf16 {
    u32 keyA;   /* 0x00 */
    u32 keyB;   /* 0x04 */
    u32 keyC;   /* 0x08 */
    u32 keyD;   /* 0x0C */
};

#include "../sdk_rtc.h"

struct Profile {
    u8 name[0x94];
    u32 date1;         /* 0x94 card values 4,5,6 packed */
    u32 date2;         /* 0x98 card values 7,8,9 packed */
    u32 statusFlag;    /* 0x9C MYSTATUS_GetTrainerView */
    u16 hA0;           /* 0xA0 BSUBWAY stat 10,0 (default 1500) */
    u16 hA2;           /* 0xA2 */
    u32 uA4;           /* 0xA4 stat 10,1 + stat 10,2 */
    u16 hA8;           /* 0xA8 */
    u16 hAA;           /* 0xAA REGULATION_Card_GetValue(card, 11) */
};

typedef struct Work Work;

typedef struct WifibattlematchMenuDesc {
    u32 msgBank;        /* 0x00 message bank */
    u32 font;           /* 0x04 font */
    u32 printQue;       /* 0x08 PRINTSYS_QUE handle */
    u32 items[4];       /* 0x0C up to four item value ids */
    u32 count;          /* 0x1C item count */
    u16 a;              /* 0x20 */
    u16 b;              /* 0x22 */
    u16 c;              /* 0x24 */
    u16 d;              /* 0x26 */
    int enabled;        /* 0x28 cursor enabled */
    u16 kind;           /* 0x2C */
    u16 row;            /* 0x2E first row (BMP_MENULIST_Create third argument) */
} WifibattlematchMenuDesc;

typedef enum { RES_NONE, RES_1, RES_2, RES_3, RES_4 } Res;

typedef int (*EvalFn)(int index, void *param);

struct MatchKey {
    int  value;
    u8   id;
    u8   pad_05;
    char name[3];
    u8   term;
    u8   pad_0a[2];
};

typedef int (*ReportFn)(u32 *ctx);

typedef struct Sys {
    u32 reserved0;   /* 0x00 */
    u32 errorKind;   /* 0x04 */
    u32 reserved8;   /* 0x08 */
    u32 errorCode;   /* 0x0C */
} Sys;

typedef int (*RoundFn)(char *ctx, char *peer, int dir, int flag);

typedef void (*StepFn)(void);

struct Blob { const void *data; u32 size; };

union Payload { u32 value; void *ptr; struct Blob blob; };

struct Field { const char *name; u32 type; union Payload payload; };

typedef void (*RecordsFn)(int count, struct Field **recs, u32 a, int nfields);

struct Record {u32 words[21];};

typedef struct DWCstAccUserData DWCstAccUserData;

typedef struct {u32 a,b;} Pair;

typedef struct { char pad[0x1220]; u32 a,b; } Obj;

typedef struct { u32 a, b; } W;

struct WifiBattleMatchComp {
    void *sprite;               /* 0x00 */
    unsigned int anim;          /* 0x04 */
    unsigned int font;          /* 0x08 */
    int fontAlt;                /* 0x0C */
    unsigned int printQue;      /* 0x10 */
    unsigned int msgBank;       /* 0x14 */
    unsigned int wordSet;       /* 0x18 */
    unsigned int tradeIcon;     /* 0x1C */
    unsigned int regCard;       /* 0x20 */
    void *window;               /* 0x24 */
    unsigned int animMgr;       /* 0x28 */
    unsigned int textObj;       /* 0x2C */
    unsigned int compSprite;    /* 0x30 */
    void *net;                  /* 0x34 */
    unsigned int proc2;         /* 0x38 */
    unsigned int waitStream;    /* 0x3C */
    unsigned int waitResult;    /* 0x40 */
    unsigned char responseFlag; /* 0x44 */
    unsigned char pad_45[3];    /* 0x45 */
    unsigned char pad_48[0x98]; /* 0x48..0xDF nothing reads it here */
    unsigned int timer;         /* 0xE0 */
    unsigned int regFlag;       /* 0xE4 */
    unsigned int timeout;       /* 0xE8 */
    unsigned int stepCounter;   /* 0xEC */
    unsigned int rapFlag;       /* 0xF0 */
    unsigned int reportState;   /* 0xF4 */
    unsigned int reportResult;  /* 0xF8 */
    unsigned int party;         /* 0xFC */
    unsigned int gdbFlag;       /* 0x100 */
    struct WifiBattleMatchParams *ctx; /* 0x104 */
    unsigned int card;          /* 0x108 */
    unsigned char cardRecord[0x160]; /* 0x10C..0x26B downloaded regulation card record */
    int boxLocked;              /* 0x26C BATTLE_BOX_IsLocked result */
};

/* WIFIBATTLEMATCH_NET_CompCreate allocates 0x270 bytes. */
typedef char WifiBattleMatchComp_size_check[
    (sizeof(struct WifiBattleMatchComp) == 0x270) ? 1 : -1];

/* The 0x100-byte net task work object created by
 * WIFIBATTLEMATCH_NET_TaskCreate (PROCSYS_AllocProcWork(sys, 0x100, 87)).
 * It holds the graphics, fonts, the net context and the task's own state. */
struct WifiBattleMatchNetTask {
    void *graphic;              /* 0x00 */
    void *view;                 /* 0x04 */
    void *font;                 /* 0x08 */
    void *printQue;             /* 0x0C */
    unsigned int msgBank;       /* 0x10 message bank handle */
    void *wordSet;              /* 0x14 */
    unsigned int boxWindow;     /* 0x18 main window handle released by DeleteBoxRecord */
    unsigned int recordWindow;  /* 0x1C record window handle released by DeleteRegCard */
    void *actorArray;           /* 0x20 */
    void *util;                 /* 0x24 */
    unsigned int menu;          /* 0x28 menu handle released by DeleteSprite */
    unsigned char pad_2C[4];    /* 0x2C never read or written */
    void *net;                  /* 0x30 the net context */
    void *callbackA;            /* 0x34 */
    unsigned int waitStream;    /* 0x38 callback stream handle for GetWaitResult */
    unsigned int waitResult;    /* 0x3C */
    void *ctx;                  /* 0x40 the match-parameters object */
    unsigned char postFlag;     /* 0x44 first byte of the HTTP post buffer */
    unsigned char postData[0x9B]; /* 0x45..0xDF */
    unsigned int postTimer;     /* 0xE0 frame counter (TIMER macro) */
    unsigned int cancelStep;    /* 0xE4 step of the cancel sequence */
    unsigned int timeout;       /* 0xE8 timeout counter (TIMEOUT macro) */
    unsigned int pad_EC[2];     /* 0xEC..0xF3 nothing reads it here */
    unsigned int reportResult;  /* 0xF4 WIFIBATTLEMATCH_NET_ScProcess output */
    unsigned int reportFlag;    /* 0xF8 set once a report result was taken */
    unsigned int processState;  /* 0xFC WIFIBATTLEMATCH_NET_ScProcess return */
};

/* WIFIBATTLEMATCH_NET_TaskCreate allocates 0x100 bytes. */
typedef char WifiBattleMatchNetTask_size_check[
    (sizeof(struct WifiBattleMatchNetTask) == 0x100) ? 1 : -1];

/* One 0x10-byte entry of the storage-server description buffer at
 * WifiBattleMatchNetCtx.recBuf (offset 0x190). */
struct GdbUploadEntry {
    const char *name;           /* 0x00 */
    unsigned int type;          /* 0x04 */
    unsigned int value;         /* 0x08 */
    unsigned int size;          /* 0x0C */
};

/* The 0x5c-byte registration data block filled by
 * WIFIBATTLEMATCH_NET_GdbCopyFieldsA; the words hold the GDB fields that
 * WIFIBATTLEMATCH_NET_LookupFieldEntry names. */
struct RegDataA {
    unsigned int regField20;    /* 0x00 */
    unsigned int regField21;    /* 0x04 */
    unsigned int regField23;    /* 0x08 */
    unsigned int regField19;    /* 0x0C */
    unsigned int regField22;    /* 0x10 */
    unsigned int pad_14;        /* 0x14 */
    unsigned int regField24;    /* 0x18 */
    unsigned int pad_1C;        /* 0x1C */
    unsigned int regField3;     /* 0x20 */
    unsigned int regField11;    /* 0x24 */
    unsigned int regField12;    /* 0x28 */
    unsigned int regField14;    /* 0x2C */
    unsigned int regField13;    /* 0x30 */
    unsigned int regField18;    /* 0x34 */
    unsigned int regField17;    /* 0x38 */
    unsigned int regField10;    /* 0x3C */
    unsigned int regField9;     /* 0x40 */
    unsigned int regField16;    /* 0x44 */
    unsigned int regField15;    /* 0x48 */
    unsigned int regExtraA;     /* 0x4C */
    unsigned int regExtraB;     /* 0x50 */
    unsigned int regExtraC;     /* 0x54 */
    unsigned int regExtraD;     /* 0x58 */
};

/* The 0x18-byte sibling block filled by WIFIBATTLEMATCH_NET_GdbCopyFieldsB. */
struct RegDataB {
    unsigned int regField39;    /* 0x00 */
    unsigned int regField40;    /* 0x04 */
    unsigned int regField37;    /* 0x08 */
    unsigned int regField38;    /* 0x0C */
    unsigned int regField36;    /* 0x10 */
    unsigned int regField35;    /* 0x14 */
};

/* One 0x10-byte record field, as read back by
 * WIFIBATTLEMATCH_NET_GdbCopyFieldC. */
struct RegField {
    const char *name;           /* 0x00 */
    unsigned int pad_04;        /* 0x04 */
    unsigned int value;         /* 0x08 */
};

/* The error/result record at WifiBattleMatchNetCtx.err (offset 0x18).  The
 * WIFIBATTLEMATCH_NET_SetError/SetResult setters are handed the address of
 * this record (context + 0x18). */
struct NetErrRecord {
    unsigned int errValue;      /* 0x00 */
    unsigned int resultA;       /* 0x04 */
    unsigned int resultB;       /* 0x08 */
    unsigned int resultC;       /* 0x0C */
    unsigned int pad_10;        /* 0x10 */
    unsigned int resultD;       /* 0x14 */
    unsigned int errCode;       /* 0x18 */
    int errKind;                /* 0x1C */
};

/* The 0x149c matchmaking and storage-server context created by
 * WIFIBATTLEMATCH_NET_CreateNetContext. */
struct WifiBattleMatchNetCtx {
    unsigned int scId;               /* 0x000 WIFILIST_GetWork() */
    unsigned int gsProfileId;        /* 0x004 GAME_DATA_GetWifiList(save) */
    void *save;                      /* 0x008 */
    unsigned int statusBuf;          /* 0x00C MYSTATUS_GetProfileId(GAME_DATA_GetMyStatus(save)) */
    int heap;                        /* 0x010 */
    unsigned int syncRange;          /* 0x014 */
    struct NetErrRecord err;         /* 0x018..0x037 */
    unsigned char dateTime[8];       /* 0x038 WIFIBATTLEMATCH_NET_GetDateTime output */
    unsigned int mmState;            /* 0x040 */
    char filter[0x80];               /* 0x044..0x0C3 matchmaking filter string */
    struct MatchKey matchKeys[8];    /* 0x0C4..0x123 */
    unsigned short heapTag;          /* 0x124 */
    unsigned char pad_126[2];        /* 0x126..0x127 */
    int gdbState;                    /* 0x128 */
    unsigned int state;              /* 0x12C */
    unsigned int nextState;          /* 0x130 */
    unsigned int pendingCount;       /* 0x134 */
    unsigned int recvPlayerData;     /* 0x138 */
    int regDataReady;                /* 0x13C */
    unsigned int sessionResult;      /* 0x140 */
    unsigned int regBufferReady;     /* 0x144 */
    unsigned int regFlagReady;       /* 0x148 */
    unsigned int regValueReady;      /* 0x14C */
    unsigned int regValue;           /* 0x150 */
    unsigned int shutdownState;      /* 0x154 */
    void *reportFn;                  /* 0x158 */
    int reportResult;                /* 0x15C */
    unsigned int reportSlot;         /* 0x160 */
    unsigned int reportFieldA;       /* 0x164 */
    unsigned int reportFieldB;       /* 0x168 */
    unsigned int reportFieldC;       /* 0x16C */
    unsigned int reportState;        /* 0x170 */
    unsigned int postMonCount;       /* 0x174 */
    unsigned int gdbArg;             /* 0x178 */
    void *gdbStep;                   /* 0x17C */
    unsigned int teamArg;            /* 0x180 */
    unsigned int teamRec0;           /* 0x184 */
    unsigned int teamRec4;           /* 0x188 */
    unsigned int takenRegValue;      /* 0x18C WIFIBATTLEMATCH_NET_TakeRegValue output */
    void *recBuf;                    /* 0x190 0x260-byte description buffer */
    void *gdbName;                   /* 0x194 */
    int fieldCount;                  /* 0x198 */
    unsigned int initWord;           /* 0x19C written 0x573 by CreateNetContext, no reader */
    unsigned int pollCount;          /* 0x1A0 */
    unsigned int retryCount;         /* 0x1A4 */
    unsigned int reportCount;        /* 0x1A8 */
    int reportKind;                  /* 0x1AC */
    int gdbTarget;                   /* 0x1B0 */
    unsigned char pad_1B4[0x10];     /* 0x1B4..0x1C3 */
    unsigned char uploadRecord[0x50]; /* 0x1C4 struct Record copy for the GDB upload */
    unsigned int uploadKind;         /* 0x214 */
    unsigned char regData[0x1000];   /* 0x218..0x1217 regulation payload */
    void *evalFn;                    /* 0x1218 */
    void *rapHandle;                 /* 0x121C */
    Pair rapPair;                    /* 0x1220 matchmaking pair read by GetRapPair */
    W postData;                      /* 0x1228 HTTP post payload posted by HttpRapSend */
    unsigned char regulationCard[0x160]; /* 0x1230..0x138F */
    unsigned char fileList[0xB0];    /* 0x1390..0x143F */
    unsigned int downloadPercent;    /* 0x1440 */
    unsigned int downloadDone;       /* 0x1444 */
    unsigned int downloadTotal;      /* 0x1448 */
    unsigned char ndAttr[0xC];       /* 0x144C..0x1457 */
    int downloadActive;              /* 0x1458 */
    unsigned char pad_145C[8];       /* 0x145C..0x1463 */
    void *netIdPtr;                  /* 0x1464 */
    unsigned char profanityText[0x18]; /* 0x1468..0x147F 12-character profanity string */
    void *profanityWords;            /* 0x1480 */
    unsigned int profanityResult;    /* 0x1484 DWC_CheckProfanityExAsync result */
    int profanityCount;              /* 0x1488 */
    unsigned short profanityTag;     /* 0x148C */
    unsigned char pad_148E[2];       /* 0x148E..0x148F */
    unsigned int profanityWindow;    /* 0x1490 */
    unsigned int reportFlag;         /* 0x1494 */
    unsigned char pad_1498[4];       /* 0x1498..0x149B, to the 0x149c alloc */
};

extern int GF_OVERLAY_Load(s32 handle);
extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);
extern void GF_OVERLAY_Unload(int);
extern void GFL_USE_StopAllSe(void);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned, int);
extern int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *);
extern u32 *WIFIBATTLEMATCH_VIEW_Create(int unused, int mode, int heap);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, unsigned short heap);
extern void *WIFIBATTLEMATCH_UTIL_Create(unsigned, unsigned, unsigned, unsigned, void *, void *, unsigned);
extern int *WIFIBATTLEMATCH_UTIL_CreateCallback(int, int, int);
extern void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *, void *, unsigned);
extern void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **, int);
extern void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *actors);
extern void WIFIBATTLEMATCH_UTIL_DeleteCallback(void *callback);
extern void WIFIBATTLEMATCH_UTIL_Delete(char *util);
extern unsigned int WORDSET_Delete(struct WordSet *wordSet);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *printQue);
extern u32 GF_FONT_Delete(void *ptr);
extern void WIFIBATTLEMATCH_VIEW_Delete(int);
extern void WIFIBATTLEMATCH_GRAPHIC_Delete(char *graphic);
extern void PROCSYS_FreeProcWork(struct Proc *);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void WIFIBATTLEMATCH_UTIL_InvokeCallback(unsigned);
extern int WIFIBATTLEMATCH_UTIL_IsCallbackNull(int **stream);
extern void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *graphic);
extern void WIFIBATTLEMATCH_UTIL_Main(char *util);
extern void WIFIBATTLEMATCH_VIEW_Noop(int);
extern void WIFIBATTLEMATCH_VIEW_UpdateAnimation(int);
extern int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *,void *);
extern int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *window, void *mgr);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *stream, int v);
extern void WIFIBATTLEMATCH_UTIL_PrintMessage(int *, int, int, int);
extern void WIFIBATTLEMATCH_UTIL_SetRequest(u32, u32);
extern int WIFIBATTLEMATCH_UTIL_GetBusy(const int *);
extern void WIFIBATTLEMATCH_UTIL_CommitRequest(u32);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009448Obj *GAME_SYNC_GetBlock(void *);
extern u8 BLOCK20_SAVEDATA_GetPending(const struct Sub02009210Obj *);
extern int POKE_REGULATION_GetDataSize();
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u16 STRBUF_GetEosChar(void);
extern void *MSGDATA_AllocString(struct MsgBank *, u32);
extern void STRBUF_ToChars(struct U16Vec *, u16 *, unsigned int);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int NATION_AREA_IsValidNationArea(unsigned int, unsigned int, unsigned int);
extern unsigned int PMSI_PARAM_IsValid(struct PmsData *, unsigned int);
extern void PMSI_PARAM_InitSentence(void *, unsigned int);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int);
extern void DWC_RAPCOMMON_CreateSubHeap(int, int, int, int);
extern void DWC_RAPCOMMON_SetHeapTag(int);
extern void DWC_RAPCOMMON_DestroySubHeap(void);
extern void *TRADE_HISTORY_GetFromSave(void *sys);
extern void WIFIBATTLEMATCH_UTIL_SetSaveState(int, int);
extern void *MET_TRAINERS_GetFromSave(void *);
extern void MET_TRAINERS_Insert(struct L0200ED54 *, u32);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern int GAME_DATA_SaveStart(int);
extern int GAME_DATA_SaveMain(u8 *);
extern u32 GFL_NET_ERR_WaitLinkClosed(void);
extern u8 *GAME_DATA_GetMyStatus(void *save);
extern u32 BSUBWAY_SAVEDATA_GetStat(u32,u32,u32);
extern u8 MYSTATUS_GetTrainerView(const struct Sub0200852CObj *obj);
extern u32 WIFIBATTLEMATCH_VIEW_CreateMainWindow(BoxWindowDesc *,int,u32,int,u32,u32,u32,u32,u32,int);
extern void WIFIBATTLEMATCH_VIEW_DeleteMainWindow(u32 window);
extern u32 WIFIBATTLEMATCH_VIEW_StepMainWindow(u32 window);
extern u32 WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(u32 window);
extern u32 WIFIBATTLEMATCH_VIEW_CreateRecordWindow(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32);
extern void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(u32 window);
extern int WIFIBATTLEMATCH_VIEW_StepRecordWindow(void *);
extern void BSUBWAY_SAVEDATA_SetStat(u32, u32, u32, u32);
extern void BSUBWAY_SAVEDATA_IncStat(u8 *base, int a, int idx);
extern u32 WIFIBATTLEMATCH_UTIL_ShowMenu(void *, u32);
extern void WIFIBATTLEMATCH_UTIL_DeleteMenu(u32 menu);
extern int WIFIBATTLEMATCH_UTIL_UpdateMenu(u32 menu);
extern int MYSTATUS_GetSize(void);
extern void *GREETING_SAVEDATA_GetFromSaveThunk(u32 a);
extern void GREETING_SAVEDATA_GetSentence(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *gameData);
extern int WIFILIST_GetGsProfileId(void *list);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, u32 idx);
extern u8 *NHTTP_RAP_EvilCheckAllocArray(int a, int b, int c);
extern void NHTTP_RAP_EvilCheckSetElement(int buf, int a, u32 b, int n);
extern int NHTTP_RAP_VerifySignature(void *a, int b, int c, char *d, u16 e);
extern void NHTTP_RAP_EvilCheckFreeArray(void *);
extern u32 KEY_GetTrg(void);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern int GFL_NET_GetRunState(void);
extern void DWC_CloseAllConnectionsHard(void);
extern void *BATTLE_COMPETITION_GetFromSave(void *sys);
extern struct Rec160 *REGULATION_GetCard(struct Rec160 *arr, u32 index);
extern struct Party *POKEPARTY_Create(u32 heap);
extern u32 GFL_HEAP_Free(void *object);
extern int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *partyWindow, void *mgr);
extern u32 POKEPARTY_GetBattleReadyCount(void *party);
extern int REGULATION_NoOp();
extern int POKE_REGULATION_CheckParty(void *rules, void *party, u32 *mask);
extern void * BATTLE_BOX_GetFromSave(void *);
extern struct Rec1E *REGULATION_GetParty(struct RecBig *card, u32 index);
extern void *BATTLE_BOX_CreateParty(int box, int heap);
extern void BATTLE_BOX_SetLockFlags(void *box, u32 v);
extern void REGULATION_Card_SetValue(struct Reg2 *card, u32 id, s32 value);
extern void REGULATION_BuildParty(int,int);
extern s32 REGULATION_Card_GetValue(struct Reg2 *card, u32 id);
extern u32 REGULATION_Card_IsCrcValid(struct Reg2 *card);
extern u32 BATTLE_BOX_IsLocked(void *box, u32 mask);
extern void BATTLE_BOX_ClearLockFlags(void *box, int v);
extern void REGULATION_InitParty(struct Rec1E *);
extern void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n);
extern int DWC_GetDateTime(void *date, void *time);
extern void GFL_NET_ERR_HaltIfActive(void);
extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);
extern void RTC_ConvertSecondToDateTime(struct RTCDate *,struct RTCTime *,s64);
extern s32 RTC_ConvertDateToDay(struct RTCDate *date);
extern u8 *REGULATION_Card_GetCupName(struct Reg2 *card);
extern char *WIFIBATTLEMATCH_VIEW_CreateStatusWindow(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
extern void WIFIBATTLEMATCH_VIEW_DeleteStatusWindow(void *statusWindow);
extern void WIFIBATTLEMATCH_VIEW_DrawStatusWindow(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void *WIFIBATTLEMATCH_VIEW_CreatePartyWindow(void *, int, int, int, int, int, int);
extern void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *partyWindow);
extern int WIFIBATTLEMATCH_VIEW_StepPartyWindow(Work *);
extern int WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(Work *);
extern u32 WIFIBATTLEMATCH_UTIL_CreateMenu(WifibattlematchMenuDesc *, int, unsigned char, int, int, int);
extern void *POKEPARTY_Init(void *);
extern void MYSTATUS_Copy(void *src, void *dst);
extern u16 REGULATION_Card_CalcCrc(struct Reg2 *card);
extern u8 *POKE_TOOL_CastToBoxParam(u32 entry);
extern u32 POKE_TOOL_GetBoxParamSize(void);
extern int GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 WIFILIST_GetWork(u32 list);
extern u32 MYSTATUS_GetProfileId(const struct Sub0200852CObj *obj);
extern void GFL_NET_COMMAND_AddCommandTable(u32, u32, u32, u32);
extern void GFL_NET_SetWaitMode(int);
extern void DWC_RAP_SetErrorCallback(int, int);
extern void DWC_RAP_SetErrorHookCallback(int, int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *link, unsigned int lo, unsigned int hi);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *tick, unsigned int value, unsigned int line);
extern void GFL_NET_SetAutoExit(int a);
extern void GFL_NET_SetLoginOption(int a);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern void GAME_DATA_SaveCancel(char *save);
extern void GFL_NET_ERR_HaltWithMessage(u32 value);
extern int DWC_RAPCOMMON_HandleNetError(void *a, void *b);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void GFL_NET_ERR_ResetState(void);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern void GFL_NET_ERR_RecordError(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern int STD_TSPrintf(char *dst, const char *fmt, ...);
extern int DWC_RAP_StartMatchWithFilter(char *filter, int n, void *cb, char *obj);
extern u32 GFL_NET_STATE_WifiEnterRandomMatch(void);
extern void DWC_RAP_SetVchatEnabled(int v);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern int GFL_NET_STATE_GetWifiState(void);
extern u32 GFL_NET_STATE_GetError(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern u32 GFL_NET_IsParentAid(void);
extern int DWC_RAP_IsStateInSession(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u8 DWC_AddMatchKeyInt(u8 keyID, const char *keyString, const int *valueSrc);
extern int DWC_GetMatchIntValue(int index, const char *key, int idefault);
extern int DWC_ScInitialize(int theGameId, int ssl_type);
extern int DWC_ScGetLoginCertificate(void **cert);
extern int DWC_ScCreateSessionAsync(u32 callback, u32 timeoutMs, u32 userData);
extern void *DWC_ScGetSessionId(void);
extern s32 DWC_ScProcess(void);
extern void *DWC_ScGetConnectionId(void);
extern u32 DWC_ScSetSessionId(u32 a);
extern int DWC_ScSetReportIntentionAsync(u32 isAuthoritative, u32 callback, u32 timeoutMs, u32 userData);
extern int DWC_ScSubmitReportAsync(u32 report, u32 isAuthoritative, u32 callback, u32 timeoutMs, char *userData);
extern void DWC_ScDestroyReport(u32 report);
extern void DWC_ScShutdown(void);
extern int DWC_ScCreateReport(u32 headerVersion, u32 playerCount, u32 teamCount, u32 reportOut);
extern int DWC_ScReportBeginGlobalData(u32 *report);
extern int DWC_ScReportBeginPlayerData(u32 *report);
extern int DWC_ScReportBeginTeamData(u32 *report);
extern int DWC_ScReportBeginNewPlayer(u8 *report);
extern s32 DWC_ScReportSetPlayerData(s32 report, s32 playerIndex, s32 playerConnectionId, s32 playerTeamId, s32 playerResult, char *certificate, s32 authHash);
extern int DWC_ScReportEnd(u32 h, u32 a, int flag);
extern int DWC_ScReportAddIntValue(int,int,int);
extern int DWC_ScReportAddByteValue(int,int,int);
extern u32 GFL_NET_GetHandleNetID(struct Link *link);
extern struct Rec44 *GAME_DATA_GetMyStatusPlayer(struct Sub24 *save, u32 i);
extern int DWC_GdbInitialize(u32 gameId, u32 user, int ssl);
extern int DWC_GdbGetMyRecordsAsync(const char *table, void *fields, int nfields, void *cb, void *param);
extern int DWC_GdbGetRecordsAsync(const char *table, int *ids, int nids, void *fields, int nfields, void *cb, void *param);
extern void DWC_GdbProcess(void);
extern int DWC_GdbGetState(void);
extern int DWC_GdbGetAsyncResult(void);
extern int DWC_GdbCancelRequest(void);
extern void DWC_GdbShutdown(void);
extern int GF_STANDARD_CompareString(const char *s1, const char *s2);
extern int DWC_GdbUpdateRecordAsync(char *,int,void *,int);
extern int DWC_GdbCreateRecordAsync(char *,void *,int,int *);
extern u32 GFL_NET_SendData(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int STD_TSPrintf(char *,const char *,...);
extern int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int DWC_NdSetAttr(char *,char *,char *);
extern int DWC_NdGetFileListAsync(void *,unsigned int,unsigned int);
extern int DWC_NdGetFileAsync(void *,char *,unsigned int);
extern int DWC_NdCleanupAsync(void);
extern void DWC_NdProcess(void);
extern int DWC_NdGetProgress(u32 *,u32 *);
extern void NHTTP_RAP_DeleteConnection(u8 *conn);
extern void NHTTP_RAP_Destroy(u8 *rap);
extern int DWC_NdCancelAsync(void);
extern u8 *NHTTP_RAP_Create(int a, int b, int c);
extern int NHTTP_RAP_CreateRequest(int,u8 *);
extern int NHTTP_RAP_StartConnection(u8 *);
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern void GFL_NET_ERR_RaiseFatal(unsigned int x);
extern int NHTTP_RAP_GetConnection(char *);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned int length);
extern void *MYSTATUS_CreateNameStrbuf(void *a, int tag);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern int DWC_CheckProfanityExAsync(u16 **words, int wordsnum, char *reserved, int timeout,
                                     char *result, int *badwordsnum, int region);
extern int DWC_CheckProfanityProcess(void);
extern void MYSTATUS_NameFromStrbuf(u16 *out, struct U16Vec *vec);
extern void NHTTP_RAP_AllocPostData(u8 *,int,int,int);
extern void NHTTP_RAP_AppendPostData(u8 *,int,int);
extern int NHTTP_RAP_CreatePostRequest(u8 *);
extern void NHTTP_RAP_FreePostData(u8 *);
extern int NHTTP_RAP_RecordList_GetCount(u8 *list);
extern u32 NHTTP_RAP_RecordList_GetValue(u32 list, u32 i);
extern u8 *NHTTP_RAP_RecordList_GetRecord(u8 *,u32);
extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);
int WIFIBATTLEMATCH_NET_Create(int a,int b,int *obj,int d);
int WIFIBATTLEMATCH_NET_Close(int a,int b,int *obj,int d);
int WIFIBATTLEMATCH_NET_Other(int a,int b,int *obj,int d);
int WIFIBATTLEMATCH_NET_TaskCreate(void *sys, int *state, u32 *ctx);
int WIFIBATTLEMATCH_NET_TaskDestroy(int sys,int unused,int unused2,int *task);
int WIFIBATTLEMATCH_NET_TaskMain(unsigned sys,int *state,int unused,int *task);
void WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState(unsigned sys,int *state,int *task);
void WIFIBATTLEMATCH_NET_TaskStepMainMenu(u32 sys, int *state, u32 *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer(u32 sys, int *state, u32 *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord(u32 sys, int *state, u32 *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake(unsigned sys, int *state, char *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave(unsigned sys, int *state, char *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError(unsigned sys,int *state,int *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry(unsigned sys, int *state, int *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit(unsigned sys,int *state,int *task);
void WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit(unsigned sys, int *state, int *task);
void WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer(unsigned sys, int *state, int *task);
void WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake(unsigned sys, int *state, char *task);
void WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave(unsigned sys, int *state, char *task);
void WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt(unsigned sys,int *state,int *task);
void WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry(unsigned sys,int *state,int *task);
void WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit(u32 sys,int *state,u32 *task);
void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj,int unused,u8 *task);
void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *task);
void WIFIBATTLEMATCH_NET_TaskStepPostPartyData(u32 sys,int *state,char *task);
void WIFIBATTLEMATCH_NET_SetupBoxRecord(u32 *task, u32 mode);
void WIFIBATTLEMATCH_NET_DeleteBoxRecord(char *obj);
u32 WIFIBATTLEMATCH_NET_IsBoxReady(char *obj);
u32 WIFIBATTLEMATCH_NET_IsBoxAnimDone(char *obj);
void WIFIBATTLEMATCH_NET_SetupBoxAndWait(char *obj, u32 arg);
void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(char *obj);
void WIFIBATTLEMATCH_NET_CreateRegCardWindow(u32 *task,u32 arg);
void WIFIBATTLEMATCH_NET_DeleteRegCard(char *obj);
int WIFIBATTLEMATCH_NET_IsRegCardReady(char *task);
int WIFIBATTLEMATCH_NET_GetSetBsubwayStat(u32 save, u32 kind, u32 obj);
void WIFIBATTLEMATCH_NET_IncBsubwayStat(int a, int b, u32 c);
void WIFIBATTLEMATCH_NET_SetupChoiceMenu(u32 *task,int mode);
void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(char *obj);
int WIFIBATTLEMATCH_NET_PollChoiceMenu(char *obj);
void WIFIBATTLEMATCH_NET_CopyBoxRecord(u32 *record,u32 *task);
void WIFIBATTLEMATCH_NET_CopyBoxSave(u32 *record,u32 *task);
void WIFIBATTLEMATCH_NET_CopyBsubwayStat(u32 *record, u32 *task);
void WIFIBATTLEMATCH_NET_SetWaitCallback(char *obj, void *fn);
u32 WIFIBATTLEMATCH_NET_PollWaitResult(char *obj);
int WIFIBATTLEMATCH_NET_VerifyPartySignature(char *record, u16 heapId);
int WIFIBATTLEMATCH_NET_HandleCancel(char *obj, int trigger, int go);
void WIFIBATTLEMATCH_NET_ClearError(char *obj);
int WIFIBATTLEMATCH_NET_CompCreate(void *sys,int unused,u32 *ctx);
int WIFIBATTLEMATCH_NET_CompDestroy(u32 sys,u32 unused,u32 arg,char *comp);
int WIFIBATTLEMATCH_NET_CompMain(unsigned sys,int *state,int unused,int *comp);
void WIFIBATTLEMATCH_NET_CompStepRouteByEntryState(u32 sys,void *unused,char *comp);
void WIFIBATTLEMATCH_NET_CompStepFetchRapPair(u32 sys,int *state,u32 *comp);
void WIFIBATTLEMATCH_NET_CompStepReconcileEntryState(int *sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepRegisterParty(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepMainMenu(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepMatchmake(u32 sys, int *state, struct WifiBattleMatchComp *obj);
void WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle(int *a, int *state, char *ctx);
void WIFIBATTLEMATCH_NET_CompStepAskRetry(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepConfirmQuit(u32 sys, int *state, char *ctx);
void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit(u32 sys, int *state, char *ctx);
void WIFIBATTLEMATCH_NET_CompExit(u32 sys);
void WIFIBATTLEMATCH_NET_CompCleanup(void *obj,int unused,u8 *comp);
void WIFIBATTLEMATCH_NET_CompStepCheckPeriod(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepWithdrawEntry(u32 sys,int *state,char *comp);
void WIFIBATTLEMATCH_NET_CompStepPostPartyData(u32 sys, int *state, char *ctx);
void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct WifiBattleMatchComp *obj);
void WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(char *obj);
u32 WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(char *obj);
int WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(char *obj);
void WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(char *obj);
void WIFIBATTLEMATCH_NET_DrawCompStatusWindow(char *obj, u32 arg);
void WIFIBATTLEMATCH_NET_StartRegCardAnim(u32 *obj, u32 arg);
void WIFIBATTLEMATCH_NET_DeleteCompRegCard(char *obj);
u32 WIFIBATTLEMATCH_NET_IsCompRegCardReady(char *obj);
void WIFIBATTLEMATCH_NET_SetupCompPartyWindow(char *ctx);
void WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(char *obj);
int WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(char *comp);
int WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(char *comp);
void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(u32 *comp, int mode);
void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *obj);
int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(char *obj);
void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *obj, void *fn);
u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *obj);
void WIFIBATTLEMATCH_NET_CopyCompBox(char *dest, char *ctx);
void WIFIBATTLEMATCH_NET_CopyCompSave(char *dst, char *obj);
void WIFIBATTLEMATCH_NET_CopyCompResponse(char *save, char *response);
u32 WIFIBATTLEMATCH_NET_VerifyCompSignature(char *obj, void *list, u32 heapId);
int WIFIBATTLEMATCH_NET_CompareParty(u32 a, u32 b);
int WIFIBATTLEMATCH_NET_CompHandleCancel(char *obj, int trigger, int go);
void WIFIBATTLEMATCH_NET_CompClearError(char *obj);
int WIFIBATTLEMATCH_NET_GetSetCompStat(char *obj, u32 *rec);
char *WIFIBATTLEMATCH_NET_CreateNetContext(u32 a, void *save, u32 b, u16 heap);
void WIFIBATTLEMATCH_NET_DeleteNetContext(u8 *ctx);
void WIFIBATTLEMATCH_NET_Noop(int unused);
void WIFIBATTLEMATCH_NET_SetTimingSyncRange(char *obj, u32 v);
int WIFIBATTLEMATCH_NET_IsTimingSyncRange(char *obj);
int WIFIBATTLEMATCH_NET_HandleNetError(char *ctx, void *a, void *b);
void WIFIBATTLEMATCH_NET_ClearErrorFlags(u8 *ctx);
int WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(char *ctx);
void WIFIBATTLEMATCH_NET_SetMatchKey(char *obj, int mode, int extra, int group, int *rec);
int WIFIBATTLEMATCH_NET_StartMatchmaking(char *obj);
void WIFIBATTLEMATCH_NET_DisconnectWifi();
void WIFIBATTLEMATCH_NET_ClearCancelFlag(char *obj);
int WIFIBATTLEMATCH_NET_StopMatchmaking(char *obj);
int WIFIBATTLEMATCH_NET_SendSessionQuery();
u32 WIFIBATTLEMATCH_NET_TakeSessionResult(char *obj);
void WIFIBATTLEMATCH_NET_GetDateTime(unsigned char *dest);
void WIFIBATTLEMATCH_NET_AddMatchKey(char *obj, int i, int value);
int WIFIBATTLEMATCH_NET_GetMatchKeyInt(int index, void *param);
int WIFIBATTLEMATCH_NET_GetMatchKeyDefault(int index, void *param);
int WIFIBATTLEMATCH_NET_GetMatchKeyValue(int index, void *param);
void WIFIBATTLEMATCH_NET_SetupMatchReport(char *obj, int mode, int kind, u32 teamArg, u32 *rec, u32 slot);
int WIFIBATTLEMATCH_NET_ScProcess(char *ctx, u32 *out);
u32 WIFIBATTLEMATCH_NET_GetReportState(u8 *ctx);
void WIFIBATTLEMATCH_NET_OnReportResultA(int result, char *obj);
void WIFIBATTLEMATCH_NET_OnReportResultB(int result, char *obj);
void WIFIBATTLEMATCH_NET_OnReportResultC(int result, char *obj);
void WIFIBATTLEMATCH_NET_ShutdownReport(char *obj);
int WIFIBATTLEMATCH_NET_SubmitReport(char *ctx, char *other, char *peer, u32 isAuthoritative, RoundFn cb, int flag, int have, int twoway);
void WIFIBATTLEMATCH_NET_ReportAddRecord(int *ctx,const u32 *record,int invert);
void WIFIBATTLEMATCH_NET_ReportAddTeam(int *ctx, int *input, int invert);
int WIFIBATTLEMATCH_NET_ReportAddWin(u32 *ctx);
int WIFIBATTLEMATCH_NET_ReportAddLoss(u32 *ctx);
int WIFIBATTLEMATCH_NET_ReportAddDisconnectWin(u32 *ctx);
int WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss(u32 *ctx);
void WIFIBATTLEMATCH_NET_OnRecvPlayerData(int index,int unused,const void *src,u8 *ctx,int owner);
void WIFIBATTLEMATCH_NET_OnRecvStatus(int index, int unused, void *dest, char *ctx, int owner);
int WIFIBATTLEMATCH_NET_GetPlayerBuffer(int a, char *b);
void WIFIBATTLEMATCH_NET_OnRecvFlagA(u32 a, u32 b, u32 c, char *d, u32 e);
void WIFIBATTLEMATCH_NET_OnRecvFlagB(u32 a, u32 b, u32 c, char *d, u32 e);
void WIFIBATTLEMATCH_NET_OnRecvFlagC(u32 a, u32 b, u32 c, char *d, u32 e);
void WIFIBATTLEMATCH_NET_OnRecvValue(u32 a, u32 b, u32 *c, char *d, u32 e);
void WIFIBATTLEMATCH_NET_GdbRequest(char *obj, u32 target, int kind, u32 arg);
int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *obj);
void WIFIBATTLEMATCH_NET_GdbShutdown(char *obj);
void WIFIBATTLEMATCH_NET_SetupGdbRecord(char *ctx);
void WIFIBATTLEMATCH_NET_GdbSortByName(int count, struct Field **recs, char *obj);
void WIFIBATTLEMATCH_NET_GdbCopyFieldsA(int count,struct Field **fields,char *ctx,int n);
void WIFIBATTLEMATCH_NET_GdbCopyFieldsB(int count,struct Field **fields,u8 *ctx,int n);
void WIFIBATTLEMATCH_NET_GdbCopyFieldC(int count, char **rows, int *out, int width);
void WIFIBATTLEMATCH_NET_GdbCopyFieldD(int count,struct Field **recs,void *dst,int nfields);
void WIFIBATTLEMATCH_NET_GdbCopyFieldE(int count,struct Field **recs,void *dst,int nfields);
void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *ctx,u32 mode,struct Record *src);
int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *ctx);
void WIFIBATTLEMATCH_NET_GdbClearRecord(char *ctx);
int WIFIBATTLEMATCH_NET_GdbCreateRecord(char *ctx);
u32 WIFIBATTLEMATCH_NET_GetNetId(char *obj);
u32 WIFIBATTLEMATCH_NET_SendRegData(char *obj, u32 data);
u32 WIFIBATTLEMATCH_NET_TakeRegData(char *obj, char **out);
u32 WIFIBATTLEMATCH_NET_SendRegDataAlt(char *ctx,unsigned int data);
u32 WIFIBATTLEMATCH_NET_TakeRegBuffer(char *obj, u32 arg);
int WIFIBATTLEMATCH_NET_SendRegFlag(char *obj, u32 data);
u32 WIFIBATTLEMATCH_NET_TakeRegFlag(char *obj, u32 arg);
int WIFIBATTLEMATCH_NET_SendRegValue(u32 ignored, void *ctx);
u32 WIFIBATTLEMATCH_NET_TakeRegValue(char *obj, u32 *out);
void WIFIBATTLEMATCH_NET_SetupDownload(char *ctx,unsigned a);
int WIFIBATTLEMATCH_NET_DownloadProcess(u8 *ctx);
int WIFIBATTLEMATCH_NET_IsBufferZero(const u32 *buffer,u32 bytes);
void WIFIBATTLEMATCH_NET_CleanupDownload(void *ctx, int unused, int kind);
u32 WIFIBATTLEMATCH_NET_GetDownloadSize(char *ctx, int a, int kind);
int WIFIBATTLEMATCH_NET_DownloadError(unsigned int a);
void WIFIBATTLEMATCH_NET_GetRegCardName(const char *ctx,void *out);
void WIFIBATTLEMATCH_NET_NdSetState(u8 *ctx,int state);
void WIFIBATTLEMATCH_NET_NdCleanupState(u8 *ctx,int state);
void WIFIBATTLEMATCH_NET_NdCancelState(u8 *ctx,int state);
void WIFIBATTLEMATCH_NET_NdSetError(void *ctx,u32 kind);
void WIFIBATTLEMATCH_NET_CreateHttpRap(char *ctx,unsigned heap);
int WIFIBATTLEMATCH_NET_HttpRapProcess(u8 *ctx);
void WIFIBATTLEMATCH_NET_GetRapPair(const Obj *ctx,Pair *out);
void WIFIBATTLEMATCH_NET_SetupHttpRap(u8 *ctx, const W *src, int x);
int WIFIBATTLEMATCH_NET_HttpRapSend(char *ctx);
void WIFIBATTLEMATCH_NET_StartProfanityCheck(char *obj, unsigned long win, u16 tag);
int WIFIBATTLEMATCH_NET_ProfanityProcess(char *obj, int *out);
void WIFIBATTLEMATCH_NET_SetupPostData(char *ctx,void *party,int mode);
int WIFIBATTLEMATCH_NET_HttpRapPost(char *ctx,u8 *out);
void WIFIBATTLEMATCH_NET_SetErrorA(char *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetErrorB(char *ctx, int v, int unused);
void WIFIBATTLEMATCH_NET_SetResultA(char *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetResultB(char *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetResultC(char *ctx, u32 v, int line);
void WIFIBATTLEMATCH_NET_SetResultD(char *ctx, u32 v, u32 unused);
u32 WIFIBATTLEMATCH_NET_GetErrorMsg(int a);
u32 WIFIBATTLEMATCH_NET_GetErrorCode(int a, int b, int c);
u32 WIFIBATTLEMATCH_NET_MapErrorCode(u32 v);
void WIFIBATTLEMATCH_NET_ClearStruct(void *ctx);
void WIFIBATTLEMATCH_NET_RestartNet(char *ctx, int flag);
u32 WIFIBATTLEMATCH_NET_GetGsProfileId(char *obj);
char *WIFIBATTLEMATCH_NET_GetRegNameA(void);
u32 WIFIBATTLEMATCH_NET_GetRegKindA(void);
char *WIFIBATTLEMATCH_NET_GetRegNameB(void);
u32 WIFIBATTLEMATCH_NET_GetRegKindB(void);
int WIFIBATTLEMATCH_NET_LookupFieldEntry(int a);
extern const Table d_021E2C74,d_021E2C80;
extern const char d_021E2DE0[];
extern const char ov177_id[];
extern const char ov067_id[], ov114_id[];
extern const char ov114_id[],ov067_id[];
extern const char d_021E2EE0[], d_021E2EF8[];
extern const u32 d_021E2C90[];
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
extern const u32 d_021E2DF8[];
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

int WIFIBATTLEMATCH_NET_Create(int a,int b,int *obj,int d)
{
    GF_OVERLAY_Load((int)ov177_id);
    switch(((int *)obj[2])[2]) {
    case 1: return d_021E2C74.create(a,b,obj,d);
    case 0: return d_021E2C80.create(a,b,obj,d);
    default: GF_PANIC_Fail(d_021E2DE0,0,d_021E2DE0); return 0;
    }
}

int WIFIBATTLEMATCH_NET_Close(int a,int b,int *obj,int d)
{
    int result;
    switch(((int *)obj[2])[2]) {
    case 1: result=d_021E2C74.close(a,b,obj,d); break;
    case 0: result=d_021E2C80.close(a,b,obj,d); break;
    default: GF_PANIC_Fail(d_021E2DE0,0,d_021E2DE0); break;
    }
    GFL_USE_StopAllSe();
    GF_OVERLAY_Unload((int)ov177_id);
    return result;
}

int WIFIBATTLEMATCH_NET_Other(int a,int b,int *obj,int d) {switch(((int *)obj[2])[2]) {case 1:return d_021E2C74.other(a,b,obj,d);case 0:return d_021E2C80.other(a,b,obj,d);default:GF_PANIC_Fail(d_021E2DE0,0,d_021E2DE0);return 0;}}

/*
 * prototype: 0203159C's matched void body leaves allocated r0 live;
 *   caller captures r0 at 021D4348 as its cleared 0x100-byte buffer.
 */
int WIFIBATTLEMATCH_NET_TaskCreate(void *sys, int *state, u32 *ctx)
{
    u32 *task;
    GF_OVERLAY_Load((int)ov067_id);
    GF_OVERLAY_Load((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 87, 0x35000);
    task = PROCSYS_AllocProcWork(sys, 0x100, 87);
    MI_CpuFill8(task, 0, 0x100);
    task[16] = (u32)ctx;
    task[0] = (u32)WIFIBATTLEMATCH_GRAPHIC_Create(1, 87);
    task[1] = (u32)WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)task[0]), 2, 87);
    WIFIBATTLEMATCH_NET_CopyBoxSave((u32 *)((u32 *)ctx[5]), (u32 *)task);
    task[2] = (u32)GF_FONT_Create(23, 0, 0, 0, 87);
    task[3] = PRINTSYS_QUE_Create((void *)87);
    task[4] = (u32)MSGDATA_CreateFromArchive(0, 2, 210, 87);
    task[5] = (u32)WORDSET_Create(8, 64, 87);
    task[12] = (u32)WIFIBATTLEMATCH_NET_CreateNetContext(((u32 *)task[16])[15], (void *)(((u32 *)ctx[2])[0]), ctx[7], 87);
    task[9] = (u32)WIFIBATTLEMATCH_UTIL_Create(0, 15, 14, 10, (void *)task[3], (void *)task[2], 87);
    task[13] = (u32)WIFIBATTLEMATCH_UTIL_CreateCallback((int)task, (int)WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState, 87);
    task[14] = (u32)WIFIBATTLEMATCH_UTIL_CreateCallback((int)task, 0, 87);
    task[8] = (u32)WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)task[0]), (void *)task[1], 87);
    WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)task[8], 0);
    if (ctx[3] != 0) {
        if (ctx[0] == 0) {
            WIFIBATTLEMATCH_NET_SetupBoxAndWait((char *)task, 0);
        } else if (ctx[0] == 1) {
            if (ctx[3] == 1)
                WIFIBATTLEMATCH_NET_IncBsubwayStat(ctx[4], ((u32 *)ctx[2])[1], *(u32 *)ctx[11]);
            WIFIBATTLEMATCH_NET_SetupBoxAndWait((char *)task, 1);
        }
    }
    WIFIBATTLEMATCH_NET_RestartNet((char *)task[12], 1);
    return 1;
}

int WIFIBATTLEMATCH_NET_TaskDestroy(int sys,int unused,int unused2,int *task)
{
    WIFIBATTLEMATCH_NET_RestartNet((char *)task[12],0);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray((int *)task[8]);
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)task[14]);
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)task[13]);
    WIFIBATTLEMATCH_UTIL_Delete((char *)task[9]);
    if(task[12]) WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)task[12]);
    WIFIBATTLEMATCH_NET_DeleteRegCard((char *)task);
    WIFIBATTLEMATCH_NET_DeleteBoxRecord((char *)task);
    WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
    WORDSET_Delete((struct WordSet *)task[5]);
    MSGDATA_Delete((void *)task[4]);
    PRINTSYS_QUE_Delete((struct PrintSys *)task[3]);
    GF_FONT_Delete((void *)task[2]);
    WIFIBATTLEMATCH_VIEW_Delete(task[1]);
    WIFIBATTLEMATCH_GRAPHIC_Delete((char *)task[0]);
    PROCSYS_FreeProcWork((struct Proc *)sys);
    GFL_HEAP_DeleteChecked(0x57);
    GF_OVERLAY_Unload((int)ov114_id);
    GF_OVERLAY_Unload((int)ov067_id);
    return 1;
}

/*
 * Extent tail 021D458A..021D458C is two zero alignment bytes before 021D458C.
 */
int WIFIBATTLEMATCH_NET_TaskMain(unsigned sys,int *state,int unused,int *task)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2:
        WIFIBATTLEMATCH_UTIL_InvokeCallback(task[13]);
        if(WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)task[13])) *state=3;
        if(task[12]) WIFIBATTLEMATCH_NET_Noop(task[12]);
        break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    WIFIBATTLEMATCH_GRAPHIC_Draw((u8 *)task[0]);
    PRINTSYS_QUE_Main((struct PrintSys *)task[3]);
    WIFIBATTLEMATCH_UTIL_Main((char *)task[9]);
    WIFIBATTLEMATCH_VIEW_Noop(task[8]);
    WIFIBATTLEMATCH_VIEW_UpdateAnimation(task[1]);
    if(task[6]) WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)task[6],(void *)task[3]);
    if(task[7]) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow((void *)task[7],(void *)task[3]);
    return 0;
}

void WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState(unsigned sys,int *state,int *task)
{
    int *params=(int *)task[16];
    switch(params[3]) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)task[12]);
    case 1:
        if(params[0]==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave);
        else if(params[0]==1) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave);
        break;
    case 3:
        if(params[0]==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        else if(params[0]==1) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepMainMenu(u32 sys, int *state, u32 *task)
{
    u32 *params = (u32 *)task[16];
    int result;
    switch (*state) {
    case 0: WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)task[8], 0); *state = 1; break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 25, 1);
        *state = 7; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2); break;
    case 2: WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)task, 1); *state = 3; break;
    case 3:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)task);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
            switch (result) {
            case 0: params[0] = 1; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer); break;
            case 1: params[0] = 0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer); break;
            case 2: params[0] = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 30, 1);
        *state = 7; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 5); break;
    case 5: WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)task, 0); *state = 6; break;
    case 6:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)task);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
            switch (result) {
            case 0: params[1] = 0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer(u32 sys, int *state, u32 *task)
{
    u32 *params = (u32 *)task[16];
    u32 result;
    switch (*state) {
    case 0:
        if (BLOCK20_SAVEDATA_GetPending((const struct Sub02009210Obj *)GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl((struct Big *)*(u32 *)params[2])))) *state = 1;
        else *state = 6;
        break;
    case 1: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 41, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2); break;
    case 2: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 24, 2); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 3); break;
    case 3: MI_CpuFill8((void *)params[12], 0, 8); WIFIBATTLEMATCH_NET_CreateHttpRap((char *)task[12], 87); *state = 4; break;
    case 4:
        switch (WIFIBATTLEMATCH_NET_HttpRapProcess((u8 *)task[12])) {
        case 0: break;
        case 1: WIFIBATTLEMATCH_NET_GetRapPair((const Obj *)((char *)task[12]), (Pair *)((void *)((u32 *)task[16])[12])); *state = 5; break;
        case 3: MI_CpuFill8((void *)((u32 *)task[16])[12], 0, 8); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 2:
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
            case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
            }
            break;
        }
        break;
    case 5: if (((u8 *)params[12])[6]) *state = 9; else *state = 6; break;
    case 6: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 55, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12); break;
    case 9:
        WIFIBATTLEMATCH_NET_SetWaitCallback((char *)task, WIFIBATTLEMATCH_NET_TaskStepPostPartyData); *state = 10;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
        case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 10:
        result = WIFIBATTLEMATCH_NET_PollWaitResult((char *)task);
        if (result == 0) *state = 13;
        else if (result == 1) *state = 11;
        else if (result == 3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
        if (result != 0xffff) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
            case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
            }
        }
        break;
    case 11: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 120, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12); break;
    case 12: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
    case 13: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord); break;
    case 14: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord(u32 sys, int *state, u32 *task)
{
    u32 *params = (u32 *)task[16];
    int result;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 24, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1); *state = 11; break;
    case 1:
        if (*(u32 *)params[8] == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest((char *)task[12], -1, 0, params[14]);
            *state = 2;
        }
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_GdbGetMyRecords((char *)task[12]);
        if (result == 1) {
            *(u32 *)((u32 *)task[16])[8] = 1800;
            task[60] = WIFIBATTLEMATCH_NET_GetSetBsubwayStat(params[4], ((u32 *)params[2])[1], (u32)task);
            WIFIBATTLEMATCH_NET_CopyBsubwayStat((u32 *)((u32 *)params[5]), (u32 *)task);
            *(u32 *)((u32 *)task[16])[10] = ((u32 *)((u32 *)task[16])[14])[21];
            *state = 3;
        }
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                *(u32 *)((u32 *)task[16])[8] = 1800;
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                *(u32 *)((u32 *)task[16])[8] = 1800;
                break;
            }
        }
        break;
    case 3:
        if (WIFIBATTLEMATCH_NET_GetNetId((char *)task[12]) == 0) {
            WIFIBATTLEMATCH_NET_GdbClearRecord((char *)task[12]); *state = 4;
        } else *state = 5;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_GdbCreateRecord((char *)task[12]);
        if (result == 1) *state = 1;
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                *(u32 *)((u32 *)task[16])[8] = 1800;
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                *(u32 *)((u32 *)task[16])[8] = 1800;
                break;
            }
        }
        break;
    case 5:
        if (task[6] == 0) *state = 8;
        else if (task[60]) *state = 6;
        else *state = 10;
        task[60] = 0;
        break;
    case 6: *state = 7; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsBoxAnimDone((char *)task)) {
            WIFIBATTLEMATCH_NET_DeleteBoxRecord((char *)task); *state = 8;
        }
        break;
    case 8: WIFIBATTLEMATCH_NET_SetupBoxRecord((u32 *)((u32 *)task), 0); *state = 9; break;
    case 9: if (WIFIBATTLEMATCH_NET_IsBoxReady((char *)task)) *state = 10; break;
    case 10: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake); break;
    case 11: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

#define CTX(base) ((u32 *)(base)[16])

#define TIMER(base) (*(u32 *)((base) + 0xe0))

#define TIMEOUT(base) (*(u32 *)((base) + 0xe8))

void WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake(unsigned sys, int *state, char *task)
{
    char *params = (char *)P(task, 0x40);
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired, fixed;
    char *incoming, *data;
    int bad;
    u32 size;
    u32 buf[4];
    struct MsgBank *bank;
    struct U16Vec *str;
    if (*state >= 2 && *state < 8) enable = 1;
    if (*state < 6 || *state > 7) allow = 1; else allow = 0;
    result = WIFIBATTLEMATCH_NET_HandleCancel(task, enable, allow);
    if (result == 3) {
        *state = 22;
        return;
    }
    switch (*state) {
    case 0:
        P(task, 0xe4) = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 33, 0);
        *state = 1; break;
    case 1:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        WIFIBATTLEMATCH_NET_CopyBoxRecord((u32 *)((u32 *)buf), (u32 *)((u32 *)task));
        WIFIBATTLEMATCH_NET_SetMatchKey((void *)P(task, 0x30), 2, 1, ((int *)Q(params, 8))[1], (int *)buf);
        *state = 2; break;
    case 2:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        result = WIFIBATTLEMATCH_NET_StartMatchmaking((void *)P(task, 0x30));
        if (result == 1) { TIMEOUT(task) = 0; *state = 3; }
        else if (result == 2) *state = 1;
        break;
    case 3:
        if (result == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData((char *)P(task, 0x30), Q(params, 0x14))) { TIMEOUT(task) = 0; *state = 4; }
            timed = 1;
        }
        break;
    case 4:
        if (WIFIBATTLEMATCH_NET_TakeRegData((char *)P(task, 0x30), &incoming)) {
            data = (char *)Q(params, 0x18);
            size = POKE_REGULATION_GetDataSize() + 0xd4;
            MI_CpuCopy8(incoming, data, size);
            fixed = 0;
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == STRBUF_GetEosChar()) empty = 0;
            if (empty) {
                fixed++;
                bank = MSGDATA_CreateFromArchive(0, 2, 0xd2, 0x8057);
                str = MSGDATA_AllocString(bank, 0x8057);
                STRBUF_ToChars(str, (u16 *)data, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete((struct Rec *)bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) { data[0x1d] = 0; fixed++; }
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
                fixed++;
            }
            if (!NATION_AREA_IsValidNationArea((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0; fixed++;
            }
            if (!PMSI_PARAM_IsValid((struct PmsData *)(data + 0x38), 0x8057)) { PMSI_PARAM_InitSentence(data + 0x38, 1); fixed++; }
            if (fixed == 0) TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl(*(struct Big **)Q(params, 8)));
            TIMEOUT(task) = 0; *state = 5;
        }
        timed = 1; break;
    case 5:
        if (WIFIBATTLEMATCH_NET_VerifyPartySignature((char *)Q(params, 0x18), 0x57)) *state = 6;
        else {
            WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30)));
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake);
        }
        break;
    case 6:
        WIFIBATTLEMATCH_NET_StartProfanityCheck((char *)P(task, 0x30), Q(params, 0x18), 0x57); *state = 7; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess((char *)P(task, 0x30), &bad)) {
            *(int *)((int *)P(task, 0x40))[16] = bad; *state = 8;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 8:
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(task, 0x30), 21); TIMEOUT(task) = 0; *state = 9;
        }
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult((char *)P(task, 0x30)) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(task, 0x30))) *state = 10;
        timed = 1; break;
    case 10:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(task, 0x30), 22); TIMEOUT(task) = 0; *state = 11; break;
    case 11:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(task, 0x30))) *state = 12;
        timed = 1; break;
    case 12:
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 34, 1);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 13); break;
    case 13:
        if (TIMER(task)++ > 120) {
            TIMER(task) = 0; WIFIBATTLEMATCH_NET_CreateRegCardWindow((u32 *)((unsigned int *)task), Q(params, 0x18)); BG_SYS_SetPlaneVisible(0, 0); *state = 14;
        }
        break;
    case 14: if (WIFIBATTLEMATCH_NET_IsRegCardReady(task)) *state = 15; break;
    case 15: if (TIMER(task)++ > 0) { TIMER(task) = 0; *state = 16; } break;
    case 16:
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        WIFIBATTLEMATCH_NET_SetupMatchReport((char *)P(task, 0x30), 0, 2, 0, (u32 *)0, 0);
        P(task, 0xfc) = 0;
        P(task, 0xf4) = 0;
        *state = 17;
        break;
    case 17:
        if (P(task, 0xfc) == 0) P(task, 0xfc) = WIFIBATTLEMATCH_NET_ScProcess((void *)P(task, 0x30), (u32 *)(task + 0xf4));
        if (P(task, 0xfc) == 1) *state = 18;
        if (P(task, 0xfc) != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
            case 1: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30)));
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 18:
        DWC_RAPCOMMON_DestroySubHeap(); *state = 19; break;
    case 19:
        BG_SYS_SetPlaneVisible(0, 1); WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 36, 2);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 20); break;
    case 20:
        if (TIMER(task)++ > 60) { TIMER(task) = 0; Q(params, 4) = 1; WIFIBATTLEMATCH_UTIL_ClearCallback(sys); }
        break;
    case 21:
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30)));
        Q(params, 12) = 2;
        if (P(task, 0xf4) != 0) {
            P(task, 0xf8) = 1;
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave);
        } else {
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        }
        break;
    case 22:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 39, 1);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 23); break;
    case 23:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)task), 0); *state = 24; break;
    case 24:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result == -1) break;
        WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
        switch (result) {
        case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit); break;
        case 1: *state = 25; break;
        }
        break;
    case 25:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 38, 1);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 26); break;
    case 26:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)task), 0); *state = 27; break;
    case 27:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result == -1) break;
        WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
        switch (result) {
        case 0: *state = 0; break;
        case 1: *state = 22; break;
        }
        break;
    case 28: if (WIFIBATTLEMATCH_NET_SendSessionQuery(P(task, 0x30))) *state = 29; break;
    case 29: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30))); *state = 0; break;
    case 30: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)P(task, 0x24))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
    if (timed) {
        expired = 0;
        if (TIMEOUT(task)++ > 2400) { TIMEOUT(task) = 0; expired = 1; }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult((char *)P(task, 0x30))) expired = 1;
        if (expired) *state = 28;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
    }
}

/*
 * DA36C receives the live context in r0 here despite its no-argument body.
 */
void WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave(unsigned sys, int *state, char *task)
{
    char *params = (char *)P(task, 0x40);
    Rec84 rec;
    void *list;
    int result;
    switch (*state) {
    case 0:
        if (Q(params, 12) == 2 && P(task, 0xf8) == 0) {
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
            return;
        }
        P(task, 0xf8) = 0;
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        *state = 1;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 37, 2);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2);
        break;
    case 2:
        WIFIBATTLEMATCH_NET_SetupMatchReport((char *)P(task, 0x30), 1, 2, ((u32 *)Q(params, 8))[1], (u32 *)((u32 *)Q(params, 0x2c)), Q(params, 12) == 2);
        P(task, 0xfc) = 0;
        P(task, 0xf4) = 0;
        *state = 3;
        break;
    case 3:
        if (P(task, 0xfc) == 0) {
            P(task, 0xfc) = WIFIBATTLEMATCH_NET_ScProcess((void *)P(task, 0x30), (u32 *)((u32 *)(task + 0xf4)));
            if (P(task, 0xfc) != 0 && P(task, 0xf4) != 0)
                WIFIBATTLEMATCH_UTIL_SetSaveState(*(int *)Q(params, 8), *(int *)Q(params, 0x2c));
        }
        if (P(task, 0xfc) == 1) {
            ((u32 *)Q(params, 0x2c))[5] = WIFIBATTLEMATCH_NET_GetReportState((u8 *)P(task, 0x30));
            *state = 4;
        }
        if (P(task, 0xfc) != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
            case 1: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30)));
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 4:
        DWC_RAPCOMMON_DestroySubHeap();
        if (Q(params, 12) == 2) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        else *state = 5;
        break;
    case 5:
        list = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(*(struct Big **)Q(params, 8)));
        MET_TRAINERS_Insert(list, MYSTATUS_GetId((void *)Q(params, 0x18)));
        *state = 6;
        WIFIBATTLEMATCH_NET_ClearCancelFlag((char *)P(task, 0x30));
        break;
    case 6:
        if (WIFIBATTLEMATCH_NET_StopMatchmaking((char *)P(task, 0x30))) {
            if (*(int *)((int *)P(task, 0x40))[8] == 0) *state = 8;
            else {
                WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 42, 2);
                *state = 14;
                WIFIBATTLEMATCH_UTIL_SetRequest(sys, 7);
            }
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4: *state = 7; break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 7:
        if (*(int *)Q(params, 0x20) == 0) *state = 8;
        break;
    case 8:
        MI_CpuFill8(&rec, 0, 0x54);
        rec.data = *(Rec80 *)((int *)P(task, 0x40))[9];
        rec.last = *(u32 *)((int *)P(task, 0x40))[10];
        WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)P(task, 0x30), 3, (struct Record *)(&rec));
        *state = 9;
        break;
    case 9:
        result = WIFIBATTLEMATCH_NET_GdbUpdateRecord((char *)P(task, 0x30));
        if (result == 1) {
            *(int *)((int *)P(task, 0x40))[8] = 0x708;
            *state = 10;
        }
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, 0)) {
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                *(int *)((int *)P(task, 0x40))[8] = 0x708;
                break;
            case 1:
                *(int *)((int *)P(task, 0x40))[8] = 0x708;
                *state = 10;
                break;
            }
        }
        break;
    case 10:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 88, 1);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 11);
        break;
    case 11:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 40, 2);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12);
        break;
    case 12:
        GAME_DATA_SaveStart(*(int *)Q(params, 8));
        *state = 13;
        break;
    case 13:
        switch (GAME_DATA_SaveMain(*(u8 **)Q(params, 8))) {
        case 0: case 1: break;
        case 2: case 3:
            Q(params, 4) = 2;
            WIFIBATTLEMATCH_UTIL_ClearCallback(sys);
            break;
        }
        break;
    case 14:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)P(task, 0x24))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError(unsigned sys,int *state,int *task)
{
    switch(state[0]) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12],0,(void *)1)) {
        case 0: state[0]=1; break;
        case 1: case 4: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry); break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 3: break;
        }
        break;
    case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry); break;
    case 2: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry(unsigned sys, int *state, int *task)
{
    int result;
    switch (*state) {
    case 0:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, (void *)1)) {
        case 0: case 1: case 4: *state = 1; break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 3: break;
        }
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 0x26, 1);
        *state = 4;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2);
        break;
    case 2:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)((u32 *)task)), 0);
        *state = 3;
        break;
    case 3:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)task);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit); break;
            }
        }
        break;
    case 4:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit(unsigned sys,int *state,int *task)
{
    int result;
    switch(state[0]) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9],task[4],0x27,1);
        state[0]=3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)((u32 *)task)), 0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)task);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
            switch(result) {
            case 0: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)((int)((void *)task[12]))); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry); break;
            }
        }
        break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

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

/*
 * The original loads p[12] before the otherwise parameterless DA36C.
 */
void WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit(unsigned sys, int *state, int *task)
{
    char *params = (char *)task[16];
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 40, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        *state = 7;
        break;
    case 1:
        GAME_DATA_SaveStart(**(int * *)&((struct WifiBattleMatchParams *)params)->save);
        *state = 2;
        break;
    case 2:
        if (GAME_DATA_SaveMain((u8 *)**(int * *)&((struct WifiBattleMatchParams *)params)->save) == 2) *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 37, 2);
        *state = 7;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 4);
        break;
    case 4:
        if (**(int * *)&((struct WifiBattleMatchParams *)params)->statPtr == 0) {
            WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)task[12], 2, 0);
            *state = 5;
        }
        break;
    case 5:
        if (WIFIBATTLEMATCH_NET_GdbUpdateRecord((char *)task[12])) {
            **(int **)((char *)task[16] + 0x20) = 0x708;
            *state = 6;
            WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], (void *)1, 0);
        }
        break;
    case 6:
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)task[12]);
        ((struct WifiBattleMatchParams *)params)->netState = 0;
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB);
        break;
    case 7:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer(unsigned sys, int *state, int *task)
{
    unsigned int waitResult;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 26, 1);
        WIFIBATTLEMATCH_NET_SetupBoxRecord((u32 *)((u32 *)task), 1);
        *state = 1;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_IsBoxReady((char *)task)) *state = 2;
        break;
    case 2:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)task[9])) *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 24, 2);
        *state = 4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_SetWaitCallback((char *)task, WIFIBATTLEMATCH_NET_TaskStepPostPartyData);
        *state = 5;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
            break;
        }
        break;
    case 5:
        waitResult = WIFIBATTLEMATCH_NET_PollWaitResult((char *)task);
        if (waitResult == 0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake);
        else if (waitResult == 1) *state = 6;
        else if (waitResult == 3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
        if (waitResult != 0xffff) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)task[12], 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait((char *)task);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 6:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9], task[4], 120, 1);
        *state = 7;
        break;
    case 7:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)task[9])) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupB);
        break;
    }
}

/*
 * DC1A0's live return is tested here; DA434/DA36C receive the context r0.
 */
void WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake(unsigned sys, int *state, char *task)
{
    char *params = (char *)P(task, 0x40);
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired;
    char *incoming, *data;
    int bad;
    u32 size;
    u32 buf[4];
    struct MsgBank *bank;
    struct U16Vec *str;
    if (*state >= 3 && *state < 13) enable = 1;
    if (*state < 11 || *state > 12) allow = 1; else allow = 0;
    result = WIFIBATTLEMATCH_NET_HandleCancel(task, enable, allow);
    if (result == 3) {
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit);
        return;
    }
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_NET_CopyBsubwayStat((u32 *)((u32 *)Q(params, 0x14)), (u32 *)((u32 *)task)); *state = 1; break;
    case 1:
        P(task, 0xe4) = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 33, 0);
        *state = 2; break;
    case 2:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        WIFIBATTLEMATCH_NET_CopyBoxRecord((u32 *)((u32 *)buf), (u32 *)((u32 *)((u32 *)task)));
        WIFIBATTLEMATCH_NET_SetMatchKey((void *)P(task, 0x30), 3, 0, ((int *)Q(params, 8))[1], (int *)buf);
        *state = 3; break;
    case 3:
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        result = WIFIBATTLEMATCH_NET_StartMatchmaking((void *)P(task, 0x30));
        if (result == 1) { TIMEOUT(task) = 0; *state = 6; }
        else if (result == 2) *state = 2;
        break;
    case 4: case 5: break;
    case 6:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(task, 0x30), 20); *state = 7; TIMEOUT(task) = 0; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(task, 0x30))) { TIMEOUT(task) = 0; *state = 8; }
        timed = 1; break;
    case 8:
        if (result == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData((char *)P(task, 0x30), Q(params, 0x14))) { TIMEOUT(task) = 0; *state = 9; }
            timed = 1;
        }
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_TakeRegData((char *)P(task, 0x30), &incoming)) {
            data = (char *)Q(params, 0x18);
            size = POKE_REGULATION_GetDataSize() + 0xd4;
            MI_CpuCopy8(incoming, data, size);
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == STRBUF_GetEosChar()) empty = 0;
            if (empty) {
                bank = MSGDATA_CreateFromArchive(0, 2, 0xd2, 0x8057);
                str = MSGDATA_AllocString(bank, 0x8057);
                STRBUF_ToChars(str, (u16 *)data, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete((struct Rec *)bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) data[0x1d] = 0;
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
            }
            if (!NATION_AREA_IsValidNationArea((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0;
            }
            if (!PMSI_PARAM_IsValid((struct PmsData *)(data + 0x38), 0x8057)) PMSI_PARAM_InitSentence(data + 0x38, 1);
            TIMEOUT(task) = 0; *state = 10;
        }
        timed = 1; break;
    case 10:
        if (WIFIBATTLEMATCH_NET_VerifyPartySignature((char *)Q(params, 0x18), 0x57)) *state = 11;
        else {
            WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30)));
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake);
        }
        break;
    case 11:
        WIFIBATTLEMATCH_NET_StartProfanityCheck((char *)P(task, 0x30), Q(params, 0x18), 0x57); *state = 12; break;
    case 12:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess((char *)P(task, 0x30), &bad)) {
            *(int *)((int *)P(task, 0x40))[16] = bad; *state = 13;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 13:
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(task, 0x30), 21); TIMEOUT(task) = 0; *state = 14;
        }
        break;
    case 14:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult((char *)P(task, 0x30)) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(task, 0x30))) *state = 15;
        timed = 1; break;
    case 15:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange((char *)P(task, 0x30), 22); TIMEOUT(task) = 0; *state = 16; break;
    case 16:
        timed = 1;
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange((char *)P(task, 0x30))) *state = 17;
        break;
    case 17:
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
        GFL_USE_PlaySeDefaultVolume(0x63a); WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 34, 1);
        *state = 25; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 18); break;
    case 18:
        if (TIMER(task)++ > 120) {
            TIMER(task) = 0; WIFIBATTLEMATCH_NET_CreateRegCardWindow((u32 *)((unsigned int *)task), Q(params, 0x18)); BG_SYS_SetPlaneVisible(0, 0); *state = 19;
        }
        break;
    case 19: if (WIFIBATTLEMATCH_NET_IsRegCardReady(task)) *state = 20; break;
    case 20: if (TIMER(task)++ > 300) { TIMER(task) = 0; *state = 21; } break;
    case 21:
        BG_SYS_SetPlaneVisible(0, 1); WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 36, 2);
        *state = 25; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 22); break;
    case 22:
        if (TIMER(task)++ > 60) { TIMER(task) = 0; Q(params, 4) = 1; WIFIBATTLEMATCH_UTIL_ClearCallback(sys); }
        break;
    case 23: if (WIFIBATTLEMATCH_NET_SendSessionQuery(P(task, 0x30))) *state = 24; break;
    case 24: WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(P(task, 0x30))); *state = 1; break;
    case 25: if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)P(task, 0x24))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
    if (timed) {
        expired = 0;
        if (TIMEOUT(task)++ > 2400) { TIMEOUT(task) = 0; expired = 1; }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult((char *)P(task, 0x30))) expired = 1;
        if (expired) *state = 23;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)P(task, 0x20), 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
    }
}

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
 * Lever: source arm order is 0,3,1,2,4..11; numeric ordering differs
 * by 119 concrete bytes although the compiled size remains 476.
 * DC2C0's return r0 is tested here despite its legacy void declaration.
 */
void WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave(unsigned sys, int *state, char *task)
{
    char *params = (char *)P(task, 0x40);
    void *list;
    switch (*state) {
    case 0:
        if (((struct WifiBattleMatchParams *)params)->state == 2) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt);
        else *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 43, 2);
        *state = 11;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        TIMER(task) = 0;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_SendRegValue(P(task, 0x30), *(char * *)&((struct WifiBattleMatchParams *)params)->saveBlock + 0x10)) *state = 2;
        break;
    case 2:
        if (WIFIBATTLEMATCH_NET_TakeRegValue((char *)P(task, 0x30), (ul *)(*(char * *)&((struct WifiBattleMatchParams *)params)->saveBlock + 0x14))) *state = 4;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4: TIMER(task) = 0; *state = 7; break;
        case 2: TIMER(task) = 0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 4:
        list = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)**(int * *)&((struct WifiBattleMatchParams *)params)->save));
        MET_TRAINERS_Insert(list, MYSTATUS_GetId((void *)((struct WifiBattleMatchParams *)params)->record));
        WIFIBATTLEMATCH_UTIL_SetSaveState(**(int * *)&((struct WifiBattleMatchParams *)params)->save, **(int * *)&((struct WifiBattleMatchParams *)params)->saveBlock);
        WIFIBATTLEMATCH_NET_ClearCancelFlag((char *)P(task, 0x30));
        *state = 5;
        break;
    case 5:
        TIMER(task)++;
        if (WIFIBATTLEMATCH_NET_StopMatchmaking((char *)P(task, 0x30))) *state = 6;
        switch (WIFIBATTLEMATCH_NET_HandleNetError((char *)P(task, 0x30), 0, (void *)1)) {
        case 1: case 4: TIMER(task) = 0; *state = 7; break;
        case 2: TIMER(task) = 0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 6:
        if (TIMER(task)++ > 30) { TIMER(task) = 0; *state = 7; }
        break;
    case 7:
        *state = 8;
        break;
    case 8:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)P(task, 0x24), P(task, 0x10), 40, 2);
        *state = 11;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 9);
        break;
    case 9:
        GAME_DATA_SaveStart(**(int * *)&((struct WifiBattleMatchParams *)params)->save);
        *state = 10;
        break;
    case 10:
        switch (GAME_DATA_SaveMain((u8 *)**(int * *)&((struct WifiBattleMatchParams *)params)->save)) {
        case 0: case 1: break;
        case 2: case 3: ((struct WifiBattleMatchParams *)params)->netState = 2; WIFIBATTLEMATCH_UTIL_ClearCallback(sys); break;
        }
        break;
    case 11:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((int *)P(task, 0x24))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt(unsigned sys,int *state,int *task)
{
    switch(state[0]) {
    case 0: state[0]=1; break;
    case 1: state[0]=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry); break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry(unsigned sys,int *state,int *task)
{
    int result;
    switch(state[0]) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9],task[4],0x26,1);
        state[0]=3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)((unsigned int *)task)), 0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)task);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
            switch(result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit); break;
            }
        }
        break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit(u32 sys,int *state,u32 *task)
{
    u32 *params=(u32 *)task[16];
    int result;
    switch(*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9],task[4],39,1); *state=5; WIFIBATTLEMATCH_UTIL_SetRequest(sys,1); break;
    case 1: WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)task), 0); *state=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_PollChoiceMenu((char *)task);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu((char *)task);
            switch(result) {
            case 0: params[1]=0; *state=3; break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry); break;
            }
        }
        break;
    case 3: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)task[9],task[4],43,2); *state=5; WIFIBATTLEMATCH_UTIL_SetRequest(sys,4); break;
    case 4: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_TaskCleanupB); break;
    case 5: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)task[9])) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskCleanupA(void *obj,int unused,u8 *task) { ((struct WifiBattleMatchParams *)(*(u8 * *)&((struct WifiBattleMatchNetTask *)task)->ctx))->netState=3; if(((struct WifiBattleMatchNetTask *)task)->net) { WIFIBATTLEMATCH_NET_DeleteNetContext(((struct WifiBattleMatchNetTask *)task)->net); *(u32 *)&((struct WifiBattleMatchNetTask *)task)->net=0; } GFL_NET_ERR_WaitLinkClosed(); WIFIBATTLEMATCH_UTIL_ClearCallback((int)obj); }

/*
 * (it is an unlabelled leaf in the overlapping window: ov093/ov170/ov177 hold
 * code or a pool word at that address but none traces a function start), so
 * no evidence class attests it.  Every concrete byte matches; --suggest-split
 * cannot help because the site is a direct `bl` with no second caller.
 */
void WIFIBATTLEMATCH_NET_TaskCleanupB(void *a, u32 **pp, char *task)
{
    if (*pp != 0)
        return;
    if (((struct WifiBattleMatchNetTask *)task)->net != 0) {
        WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)(((struct WifiBattleMatchNetTask *)task)->net));
        ((struct WifiBattleMatchNetTask *)task)->net = 0;
    }
    WIFIBATTLEMATCH_UTIL_ClearCallback((int)a);
}

void WIFIBATTLEMATCH_NET_TaskStepPostPartyData(u32 sys,int *state,char *task)
{
    char *base=*(char * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchNetTask *)task)->ctx))->profile;
    int result;
    switch(*state) {
    case 0:
        ((struct WifiBattleMatchNetTask *)task)->postTimer=0;
        MI_CpuFill8(task+0x44,0,0x9c);
        (*state)++;
        break;
    case 1:
        WIFIBATTLEMATCH_NET_SetupPostData(((struct WifiBattleMatchNetTask *)task)->net,base+0xd4,1);
        (*state)++;
        break;
    case 2:
        result=WIFIBATTLEMATCH_NET_HttpRapPost(((struct WifiBattleMatchNetTask *)task)->net,(u8 *)(task+0x44));
        if(result==1) *state=3;
        else if(result==2) { ((struct WifiBattleMatchNetTask *)task)->waitResult=2; *state=4; }
        else if(result==3) { ((struct WifiBattleMatchNetTask *)task)->waitResult=3; *state=4; }
        break;
    case 3:
        if(((struct WifiBattleMatchNetTask *)task)->postFlag==0) {
            MI_CpuCopy8(task+0x60,base+0x54,0x80);
            ((struct WifiBattleMatchNetTask *)task)->waitResult=0; *state=4;
        } else { ((struct WifiBattleMatchNetTask *)task)->waitResult=1; *state=4; }
        break;
    case 4: WIFIBATTLEMATCH_UTIL_ClearCallback(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_SetupBoxRecord(u32 *task, u32 mode)
{
    u32 sys;
    int base,flag;
    BoxWindowDesc desc;
    if(task[6]==0) {
        sys=(u32)GAME_DATA_GetMyStatus((void *)REC(task)[0]);
        base=WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)task[0]);
        MI_CpuFill8(&desc,0,20);
        if(mode==0) {
            desc.kind=REC(task)[1]; flag=1;
            desc.count=BSUBWAY_SAVEDATA_GetStat(CTX(task)[4],REC(task)[1]+5,0);
            desc.a=BSUBWAY_SAVEDATA_GetStat(CTX(task)[4],REC(task)[1]+5,1);
            desc.b=BSUBWAY_SAVEDATA_GetStat(CTX(task)[4],REC(task)[1]+5,2);
            desc.total=desc.a+desc.b;
            if(desc.count==0 && desc.total==0) desc.count=1500;
        } else if(mode==1) {
            desc.kind=REC(task)[1]; flag=0; desc.count=0;
            desc.a=BSUBWAY_SAVEDATA_GetStat(CTX(task)[4],REC(task)[1],1);
            desc.b=BSUBWAY_SAVEDATA_GetStat(CTX(task)[4],REC(task)[1],2);
            desc.total=desc.a+desc.b;
        }
        desc.name=MYSTATUS_GetTrainerView((const struct Sub0200852CObj *)sys);
        task[6]=WIFIBATTLEMATCH_VIEW_CreateMainWindow(&desc,flag,sys,base,task[1],task[2],task[3],task[4],task[5],87);
    }
}

/*
 * Release path for the ov175 object's 0x18 block pointer: free it
 *     through 0x021E5D40 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
void WIFIBATTLEMATCH_NET_DeleteBoxRecord(char *obj)
{
    u32 boxWindow = ((struct WifiBattleMatchNetTask *)obj)->boxWindow;

    if (boxWindow != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteMainWindow(boxWindow);
        ((struct WifiBattleMatchNetTask *)obj)->boxWindow = 0;
    }
}

/*
 * Thunk: hands the +0x18 block to 0x021E64C8 and returns its result.  No
 *     lr save anywhere, so the compiler emitted the call as a pooled
 *     `ldr r3; bx r3` tail jump.
 */
u32 WIFIBATTLEMATCH_NET_IsBoxReady(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindow(((struct WifiBattleMatchNetTask *)obj)->boxWindow);
}

/*
 * Thunk: hands the +0x18 block to 0x021E65FC and returns its result, the
 *     poll partner of WIFIBATTLEMATCH_NET_IsBoxReady on the same field.
 */
u32 WIFIBATTLEMATCH_NET_IsBoxAnimDone(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(((struct WifiBattleMatchNetTask *)obj)->boxWindow);
}

void WIFIBATTLEMATCH_NET_SetupBoxAndWait(char *obj, u32 arg)
{
    WIFIBATTLEMATCH_NET_SetupBoxRecord((u32 *)((u32 *)obj), arg);
    while (WIFIBATTLEMATCH_NET_IsBoxReady(obj) == 0)
        ;
}

/*
 * Only when the +0x18 pointer is live: spin on WIFIBATTLEMATCH_NET_IsBoxAnimDone until it
 *     reports ready, then hand the object to the WIFIBATTLEMATCH_NET_DeleteBoxRecord release path.
 */
void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(char *obj)
{
    if (((struct WifiBattleMatchNetTask *)obj)->boxWindow != 0) {
        while (WIFIBATTLEMATCH_NET_IsBoxAnimDone(obj) == 0)
            ;
        WIFIBATTLEMATCH_NET_DeleteBoxRecord(obj);
    }
}

/*
 * mode: original assigns constructor selectors only for mode 0 or 1.
 */
void WIFIBATTLEMATCH_NET_CreateRegCardWindow(u32 *task,u32 arg)
{
    u32 animB,animA;
    if (task[7] == 0) {
        u32 base = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)task[0]);
        u32 mode = ((u32 *)task[16])[0];
        if (mode == 0) { animA=1; animB=2; }
        else if (mode == 1) { animA=0; animB=3; }
        task[7]=WIFIBATTLEMATCH_VIEW_CreateRecordWindow(arg,base,task[1],task[2],task[3],task[4],task[5],animB,animA,0,87);
    }
}

/*
 * Release path for the ov175 object's 0x1c pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void WIFIBATTLEMATCH_NET_DeleteRegCard(char *obj)
{
    u32 recordWindow = ((struct WifiBattleMatchNetTask *)obj)->recordWindow;

    if (recordWindow != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(recordWindow);
        ((struct WifiBattleMatchNetTask *)obj)->recordWindow = 0;
    }
}

/*
 * Unlabelled blocker leaf for WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake; parent confirmed unowned.
 */
int WIFIBATTLEMATCH_NET_IsRegCardReady(char *task)
{
    return WIFIBATTLEMATCH_VIEW_StepRecordWindow(*(struct Work * *)&((struct WifiBattleMatchNetTask *)task)->recordWindow);
}

int WIFIBATTLEMATCH_NET_GetSetBsubwayStat(u32 save, u32 kind, u32 obj)
{
    int *statRecord;
    u32 statA;
    u32 statB;
    u32 statC;
    int changed;
    switch (kind) {
    case 0:
        statRecord = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        statA = statRecord[3];
        statB = statRecord[0x40 / 4];
        statC = statRecord[0x3C / 4];
        break;
    case 1:
        statRecord = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        statA = statRecord[0];
        statB = statRecord[0x28 / 4];
        statC = statRecord[0x24 / 4];
        break;
    case 2:
        statRecord = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        statA = statRecord[0x10 / 4];
        statB = statRecord[0x48 / 4];
        statC = statRecord[0x44 / 4];
        break;
    case 3:
        statRecord = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        statA = statRecord[1];
        statB = statRecord[0x30 / 4];
        statC = statRecord[0x2C / 4];
        break;
    case 4:
        statRecord = *(int **)(*(u32 *)(obj + 0x40) + 0x38);
        statA = statRecord[2];
        statB = statRecord[0x38 / 4];
        statC = statRecord[0x34 / 4];
        break;
    }
    changed = (statA != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 0) || statB != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 1) || statC != BSUBWAY_SAVEDATA_GetStat(save, kind + 5, 2));
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 0, statA);
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 1, statB);
    BSUBWAY_SAVEDATA_SetStat(save, kind + 5, 2, statC);
    return changed;
}

/*
 * Thumb jump table over 0..4: modes 1 and 4 pass the constant 1, modes 0 and
 * 3 pass 2, mode 2 and everything above 4 do nothing.
 *
 * func_/sub_ label in asm/arm9/main.s and no other reference anywhere in the
 * listings, so the site reports "unresolved: 0200E008 (arm, from header) has
 * no witness outside 021D6524..021D6550".  Bytes and size are correct
 * (44 bytes, 2 relocation sites, both wildcarded); it needs an entry for the
 * arm9 target to promote.
 */
void WIFIBATTLEMATCH_NET_IncBsubwayStat(int a, int b, u32 c)
{
    switch (c) {
    case 1:
    case 4:
        BSUBWAY_SAVEDATA_IncStat((u8 *)a, b, 1);
        break;
    case 0:
    case 3:
        BSUBWAY_SAVEDATA_IncStat((u8 *)a, b, 2);
        break;
    }
}

void WIFIBATTLEMATCH_NET_SetupChoiceMenu(u32 *task,int mode)
{
    struct { u32 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } desc;
    if (task[10]==0) {
        MI_CpuFill8(&desc,0,48);
        desc.x0=task[4]; desc.x1=task[2]; desc.x2=task[3];
        desc.a=0; desc.b=15; desc.c=13; desc.d=1;
        switch(mode) {
        case 0:
            desc.x3=31; desc.x4=32; desc.x7=2;
            desc.enabled=1; desc.kind=1;
            break;
        case 1:
            desc.x3=27; desc.x4=28; desc.x5=29;
            desc.x7=3; desc.enabled=1; desc.kind=2;
            break;
        }
        task[11]=mode;
        task[10]=WIFIBATTLEMATCH_UTIL_ShowMenu(&desc,87);
    }
}

void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(char *obj)
{
    u32 menu = ((struct WifiBattleMatchNetTask *)obj)->menu;

    if (menu != 0) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu(menu);
        ((struct WifiBattleMatchNetTask *)obj)->menu = 0;
    }
}

/*
 * Query brother of WIFIBATTLEMATCH_NET_DeleteChoiceMenu: returns the +0x28 block's handler
 *     result through 0x021E8A00, or -1 when the field is empty.
 */
int WIFIBATTLEMATCH_NET_PollChoiceMenu(char *obj)
{
    u32 menu = ((struct WifiBattleMatchNetTask *)obj)->menu;

    if (menu != 0)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu(menu);
    return -1;
}

void WIFIBATTLEMATCH_NET_CopyBoxRecord(u32 *record,u32 *task)
{
    u32 *ctx,*stats;
    MI_CpuFill8(record,0,16);
    ctx=(u32 *)task[16]; stats=(u32 *)ctx[14];
    record[1]=stats[8]; record[2]=0;
    stats=(u32 *)ctx[14];
    record[3]=stats[13]+(stats[14]+(stats[11]+(stats[12]+(stats[17]+(stats[18]+(stats[9]+(stats[10]+(stats[16]+stats[15]))))))));
    switch(((u32 *)ctx[2])[1]) {
    case 0: record[0]=((u32 *)ctx[14])[3]; break;
    case 1: record[0]=((u32 *)ctx[14])[0]; break;
    case 2: record[0]=((u32 *)ctx[14])[4]; break;
    case 3: record[0]=((u32 *)ctx[14])[1]; break;
    case 4: record[0]=((u32 *)ctx[14])[2]; break;
    }
}

void WIFIBATTLEMATCH_NET_CopyBoxSave(u32 *record,u32 *task)
{
    u32 save=((u32 *)((u32 *)task[16])[2])[0];
    u32 profile=(u32)GAME_DATA_GetSaveControl((struct Big *)save);
    u32 blob;
    u32 *ctx;
    record[17]=100;
    blob=(u32)GAME_DATA_GetMyStatus((void *)save);
    MI_CpuCopy8((void *)blob,record,MYSTATUS_GetSize());
    GREETING_SAVEDATA_GetSentence(GREETING_SAVEDATA_GetFromSaveThunk(profile),0,(struct Rec0200E6FC *)((char *)(record+14)));
    ctx=(u32 *)task[16];
    if(ctx[0]==0) {
        record[10]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1]+5,1);
        ctx=(u32 *)task[16];
        record[11]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1]+5,2);
    } else {
        record[10]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1],1);
        ctx=(u32 *)task[16];
        record[11]=BSUBWAY_SAVEDATA_GetStat(ctx[4],((u32 *)ctx[2])[1],2);
    }
    record[18]=WIFILIST_GetGsProfileId((void *)GAME_DATA_GetWifiList((const struct BigObj *)save));
}

/*
 * extent: two-byte alignment padding at 021D6786.
 */
void WIFIBATTLEMATCH_NET_CopyBsubwayStat(u32 *record, u32 *task)
{
    u32 *params = (u32 *)task[16];
    if (params[0] == 0) {
        record[10] = BSUBWAY_SAVEDATA_GetStat(params[4], ((u32 *)params[2])[1] + 5, 1);
        params = (u32 *)task[16];
        record[11] = BSUBWAY_SAVEDATA_GetStat(params[4], ((u32 *)params[2])[1] + 5, 2);
        params = (u32 *)task[16];
        record[13] = BSUBWAY_SAVEDATA_GetStat(params[4], ((u32 *)params[2])[1] + 5, 0);
    } else {
        record[10] = BSUBWAY_SAVEDATA_GetStat(params[4], ((u32 *)params[2])[1], 1);
        params = (u32 *)task[16];
        record[11] = BSUBWAY_SAVEDATA_GetStat(params[4], ((u32 *)params[2])[1], 2);
    }
}

/*
 * Closes the +0x38 stream handle through 0x021E8AA0 and parks the +0x3c
 *     result word at its "no data" sentinel 0xFFFF.
 */
void WIFIBATTLEMATCH_NET_SetWaitCallback(char *obj, void *fn)
{
    WIFIBATTLEMATCH_UTIL_SetCallback((int *)(((struct WifiBattleMatchNetTask *)obj)->waitStream), (int)fn);
    ((struct WifiBattleMatchNetTask *)obj)->waitResult = 0xFFFF;
}

u32 WIFIBATTLEMATCH_NET_PollWaitResult(char *obj)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(((struct WifiBattleMatchNetTask *)obj)->waitStream);
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull((int * *)(((struct WifiBattleMatchNetTask *)obj)->waitStream)) != 0)
        return ((struct WifiBattleMatchNetTask *)obj)->waitResult;
    return 0xFFFF;
}

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

/*
 * lever: `int i` declared before the list pointer gives i r4 and list r5
 * (declaration-order-decides-which-register-a-local-gets.md); the earlier
 * DIFF was that r4/r5 swap alone.
 * leaf: +008A NHTTP_RAP_EvilCheckFreeArray resolves as matched through
 *   src/matched/ov/ov114_func_021B9A8C.c (pkt_ov114_021B9A8C), the
 *   unlabelled ov114 tail-call stub to 0x020307B0.
 */
int WIFIBATTLEMATCH_NET_VerifyPartySignature(char *record, u16 heapId)
{
    int i;
    u32 size;
    void *list=record+0xd4;
    int heap=(heapId&0x7fff)|0x8000;
    void *buf;
    u32 ret;
    size=POKE_TOOL_GetPartyParamSize();
    buf=NHTTP_RAP_EvilCheckAllocArray(size,POKEPARTY_GetCount(list),(u16)heap);
    for(i=0;i<(int)POKEPARTY_GetCount(list);i++) {
        void *entry=POKEPARTY_GetMember(list,i);
        NHTTP_RAP_EvilCheckSetElement((int)buf,(int)entry,POKE_TOOL_GetPartyParamSize(),i);
    }
    size=POKE_TOOL_GetPartyParamSize();
    ret=NHTTP_RAP_VerifySignature(buf,size,POKEPARTY_GetCount(list),record+0x54,heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}

int WIFIBATTLEMATCH_NET_HandleCancel(char *obj, int trigger, int go)
{
    int result;

    switch (((struct WifiBattleMatchNetTask *)obj)->cancelStep) {
    case 0:
        if (trigger != 0 && (KEY_GetTrg() & 2))
            ((struct WifiBattleMatchNetTask *)obj)->cancelStep = ((struct WifiBattleMatchNetTask *)obj)->cancelStep + 1;
        else return 0;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchNetTask *)obj)->util), ((struct WifiBattleMatchNetTask *)obj)->msgBank, 0x23, 1);
        ((struct WifiBattleMatchNetTask *)obj)->cancelStep = ((struct WifiBattleMatchNetTask *)obj)->cancelStep + 1;
        break;
    case 2:
        if (!WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchNetTask *)obj)->util)))
            break;
        ((struct WifiBattleMatchNetTask *)obj)->cancelStep = ((struct WifiBattleMatchNetTask *)obj)->cancelStep + 1;
        break;
    case 3:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu((u32 *)((u32 *)obj), 0);
        ((struct WifiBattleMatchNetTask *)obj)->cancelStep = ((struct WifiBattleMatchNetTask *)obj)->cancelStep + 1;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(obj);
        if (result == -1)
            break;
        WIFIBATTLEMATCH_NET_DeleteChoiceMenu(obj);
        switch (result) {
        case 0:
            ((struct WifiBattleMatchNetTask *)obj)->cancelStep = 5;
            break;
        case 1:
            WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchNetTask *)obj)->util), ((struct WifiBattleMatchNetTask *)obj)->msgBank, 0x21, 0);
            ((struct WifiBattleMatchNetTask *)obj)->cancelStep = 0;
            return 2;
        }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchNetTask *)obj)->util), ((struct WifiBattleMatchNetTask *)obj)->msgBank, 0x2b, 2);
        ((struct WifiBattleMatchNetTask *)obj)->cancelStep = ((struct WifiBattleMatchNetTask *)obj)->cancelStep + 1;
        break;
    case 6:
        if (go == 0)
            break;
        WIFIBATTLEMATCH_NET_SendSessionQuery(((struct WifiBattleMatchNetTask *)obj)->net);
        ((struct WifiBattleMatchNetTask *)obj)->cancelStep = ((struct WifiBattleMatchNetTask *)obj)->cancelStep + 1;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(((struct WifiBattleMatchNetTask *)obj)->actorArray), 0);
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(((struct WifiBattleMatchNetTask *)obj)->net));
        if (!GFL_NET_ERR_GetErrorLevel() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct WifiBattleMatchNetTask *)obj)->cancelStep = 0;
        return 3;
    }
    return 1;
}

/*
 * Clears the word at +0xe4 (the last-read length) and then tail-calls the
 *     +0x28 release path WIFIBATTLEMATCH_NET_DeleteChoiceMenu, which is why nothing is saved.
 */
void WIFIBATTLEMATCH_NET_ClearError(char *obj)
{
    ((struct WifiBattleMatchNetTask *)obj)->cancelStep = 0;
    WIFIBATTLEMATCH_NET_DeleteChoiceMenu(obj);
}

/*
 * PROCSYS_AllocProcWork's r0 is read after the call, requiring a returning declaration.
 */
int WIFIBATTLEMATCH_NET_CompCreate(void *sys,int unused,u32 *ctx)
{
    u32 *comp;
    GF_OVERLAY_Load((int)ov067_id); GF_OVERLAY_Load((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1,87,0x30000);
    comp=PROCSYS_AllocProcWork(sys,0x270,87); MI_CpuFill8(comp,0,0x270);
    comp[0x104/4]=(u32)ctx;
    comp[0x108/4]=(u32)REGULATION_GetCard(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),0);
    comp[0]=(u32)WIFIBATTLEMATCH_GRAPHIC_Create(1,87);
    comp[1]=(u32)(u32 *)WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)comp[0]),0,87);
    comp[2]=(u32)GF_FONT_Create(0x17,0,0,0,87);
    comp[3]=(u32)GF_FONT_Create(0x17,3,0,0,87);
    comp[4]=PRINTSYS_QUE_Create((void *)87); comp[5]=(u32)MSGDATA_CreateFromArchive(0,2,0xd2,87);
    comp[6]=(u32)WORDSET_Create(8,0x40,87);
    comp[0x34/4]=(u32)WIFIBATTLEMATCH_NET_CreateNetContext(((u32 *)comp[0x104/4])[0xf],(void *)(*(u32 *)ctx[2]),ctx[7],87);
    comp[0x2c/4]=(u32)WIFIBATTLEMATCH_UTIL_Create(0, 15, 14, 10, (void *)comp[4], (void *)comp[2], 87);
    comp[0x38/4]=(u32)WIFIBATTLEMATCH_UTIL_CreateCallback((int)comp,(int)WIFIBATTLEMATCH_NET_CompStepRouteByEntryState,87);
    comp[0x3c/4]=(u32)WIFIBATTLEMATCH_UTIL_CreateCallback((int)comp,0,87);
    comp[0x28/4]=(u32)WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)comp[0]),(void *)comp[1],87);
    WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp[0x28/4],0);
    comp[0xfc/4]=(u32)POKEPARTY_Create(87); WIFIBATTLEMATCH_NET_RestartNet((char *)comp[0x34/4],1);
    return 1;
}

int WIFIBATTLEMATCH_NET_CompDestroy(u32 sys,u32 unused,u32 arg,char *comp)
{
    GFL_HEAP_Free((void *)((struct WifiBattleMatchComp *)comp)->party);
    WIFIBATTLEMATCH_NET_RestartNet((char *)((u32 *)comp)[13],0);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray((int *)(((u32 *)comp)[10]));
    WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)(((u32 *)comp)[15])); WIFIBATTLEMATCH_UTIL_DeleteCallback((void *)(((u32 *)comp)[14]));
    WIFIBATTLEMATCH_UTIL_Delete((char *)(((u32 *)comp)[11]));
    if(((u32 *)comp)[13]) WIFIBATTLEMATCH_NET_DeleteNetContext((u8 *)(((u32 *)comp)[13]));
    WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(comp); WIFIBATTLEMATCH_NET_DeleteCompRegCard(comp); WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(comp); WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
    WORDSET_Delete((struct WordSet *)(((u32 *)comp)[6])); MSGDATA_Delete((struct Rec *)(((u32 *)comp)[5]));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((u32 *)comp)[4])); GF_FONT_Delete((void *)(((u32 *)comp)[3])); GF_FONT_Delete((void *)(((u32 *)comp)[2]));
    WIFIBATTLEMATCH_VIEW_Delete(((u32 *)comp)[1]); WIFIBATTLEMATCH_GRAPHIC_Delete((char *)(((u32 *)comp)[0]));
    PROCSYS_FreeProcWork((struct Proc *)sys); GFL_HEAP_DeleteChecked(87);
    GF_OVERLAY_Unload((int)ov114_id); GF_OVERLAY_Unload((int)ov067_id);
    return 1;
}

int WIFIBATTLEMATCH_NET_CompMain(unsigned sys,int *state,int unused,int *comp)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_InvokeCallback(comp[14]); if(WIFIBATTLEMATCH_UTIL_IsCallbackNull((int * *)((u32)((int **)comp[14])))) *state=3; break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    WIFIBATTLEMATCH_GRAPHIC_Draw((u8 *)comp[0]); PRINTSYS_QUE_Main((struct PrintSys *)comp[4]); WIFIBATTLEMATCH_UTIL_Main((char *)comp[11]);
    WIFIBATTLEMATCH_VIEW_Noop(comp[10]); WIFIBATTLEMATCH_VIEW_UpdateAnimation(comp[1]); WIFIBATTLEMATCH_NET_Noop(comp[13]);
    if(comp[7]) WIFIBATTLEMATCH_VIEW_UpdatePokeList((unsigned char *)comp[7],(void *)comp[4]);
    if(comp[8]) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow((void *)comp[8],(void *)comp[4]);
    if(comp[9]) WIFIBATTLEMATCH_VIEW_UpdatePartyWindow((char *)comp[9],(void *)comp[4]);
    return 0;
}

void WIFIBATTLEMATCH_NET_CompStepRouteByEntryState(u32 sys,void *unused,char *comp)
{
    switch (((u32 *)((struct WifiBattleMatchComp *)comp)->ctx)[3]) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepFetchRapPair); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi((void *)(((struct WifiBattleMatchComp *)comp)->net));
    case 1:
        WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(comp);
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult);
        break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(comp); WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle); break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepFetchRapPair(u32 sys,int *state,u32 *comp)
{
    u32 *ctx=(u32 *)comp[0x104/4];
    int result;
    switch(*state) {
    case 0:
        if(BLOCK20_SAVEDATA_GetPending((const struct Sub02009210Obj *)GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))))) *state=1;
        else *state=5;
        break;
    case 1: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp[0x2c/4],comp[5],0x36,2); *state=2; break;
    case 2: MI_CpuFill8((void *)ctx[0xc],0,8); WIFIBATTLEMATCH_NET_CreateHttpRap((char *)comp[0x34/4],87); *state=3; break;
    case 3:
        result=WIFIBATTLEMATCH_NET_HttpRapProcess((u8 *)comp[0x34/4]);
        if(result==1) { WIFIBATTLEMATCH_NET_GetRapPair((const Obj *)((char *)comp[0x34/4]), (Pair *)((void *)((u32 *)comp[0x104/4])[0xc])); *state=4; }
        else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        else if(result!=0) {
            result=WIFIBATTLEMATCH_NET_HandleNetError((char *)comp[0x34/4],(void *)1,0);
            switch(result) {case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup); break;}
        }
        break;
    case 4: if(*(unsigned char *)(ctx[0xc]+6)) *state=7; else *state=5; break;
    case 5: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp[0x2c/4],comp[5],0x37,1); *state=6; break;
    case 6: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)comp[0x2c/4])) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompExit); break;
    case 7: if(*(u32 *)ctx[8]==0) {WIFIBATTLEMATCH_NET_ClearErrorFlags((u8 *)comp[0x34/4]); *state=8;} break;
    case 8:
        result=WIFIBATTLEMATCH_NET_StepGdbEnsureRecord((char *)comp[0x34/4]);
        if(result==1) { *(u32 *)((u32 *)comp[0x104/4])[8]=0x708; *state=9; }
        if(result!=0) {
            result=WIFIBATTLEMATCH_NET_HandleNetError((char *)comp[0x34/4],(void *)1,0);
            switch(result) {case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup); break;}
        }
        break;
    case 9: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepReconcileEntryState); break;
    }
}

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
void WIFIBATTLEMATCH_NET_CompStepReconcileEntryState(int *sys,int *state,char *comp)
{
    enum { CTX_OFFSET=0x104 } offset=CTX_OFFSET;
    u32 aux=*(u32 *)(comp+(offset+4));
    u32 *ctx=CTX(comp);
    int result;
    unsigned char regState;
    u32 save,tmp,party;
    void *box;
    Request request1,request7,request40;
    switch(*state) {
    case 0: if(((unsigned char *)ctx[12])[4]==1) *state=1; else *state=3; break;
    case 1: {
        MI_CpuFill8(&request1,0,8); request1.b=0; request1.a=((unsigned char *)CTX(comp)[12])[4];
        request1.id=WIFIBATTLEMATCH_NET_GetGsProfileId(H(comp)); ((unsigned char *)CTX(comp)[12])[5]=0;
        WIFIBATTLEMATCH_NET_SetupHttpRap((u8 *)H(comp), (const W *)&request1, 87); *state=2; break;
    }
    case 2:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(H(comp));
        if(result==1) *state=11; else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        if(result!=0) switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)) {case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 3:
        if(((unsigned char *)CTX(comp)[12])[5]==REGULATION_Card_GetValue((struct Reg2 *)aux,10)) *state=4;
        else if(REGULATION_Card_GetValue((struct Reg2 *)aux,10)==4 || REGULATION_Card_GetValue((struct Reg2 *)aux,10)==5) *state=7;
        else *state=4;
        break;
    case 4:
        regState=((unsigned char *)ctx[12])[5];
        if(regState==3) *state=5; else if((unsigned char)(regState+0xfc)<=1) *state=6; else *state=11; break;
    case 5:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x39,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,46);*state=56;break;
    case 6:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x39,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,46);*state=56;break;
    case 7: {
        MI_CpuFill8(&request7,0,8); request7.b=REGULATION_Card_GetValue((struct Reg2 *)aux,10); request7.id=WIFIBATTLEMATCH_NET_GetGsProfileId(H(comp));
        ((unsigned char *)CTX(comp)[12])[5]=REGULATION_Card_GetValue((struct Reg2 *)aux,10);
        WIFIBATTLEMATCH_NET_SetupHttpRap((u8 *)H(comp), (const W *)&request7, 87);*state=8;break;
    }
    case 8:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(H(comp));if(result==1)*state=9;else if(result==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 9:*state=6;break;
    case 10:
        result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(H(comp));if(result==1){*(u32 *)CTX(comp)[8]=0x708;*state=6;}
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 11:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x5b,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,12);*state=56;break;
    case 12:WIFIBATTLEMATCH_NET_SetupDownload(H(comp),*(u32 *)ctx[12]);*state=13;break;
    case 13:
        result=WIFIBATTLEMATCH_NET_DownloadProcess((u8 *)H(comp));
        if(result==1){WIFIBATTLEMATCH_NET_GetRegCardName(H(comp),comp+0x10c);if(REGULATION_Card_IsCrcValid((struct Reg2 *)(comp+0x10c)))*state=14;else *state=15;}
        else if(result==2)*state=15;
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 15:if(REGULATION_Card_GetValue((struct Reg2 *)aux,2)==0)*state=18;else *state=16;break;
    case 16:
        result=WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0);
        switch(result){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;case 0:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepCheckPeriod);*state=17;break;}break;
    case 17:
        result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);if(result!=0xffff)*state=46;if(result==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 18:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3b,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,55);*state=56;break;
    case 14:
        regState=((unsigned char *)ctx[12])[5];if(regState==0)*state=19;else if(regState==1)*state=53;else if(regState==2)*state=54;else *state=55;break;
    case 19:if(REGULATION_Card_GetValue((struct Reg2 *)aux,2)==0)*state=42;else *state=20;break;
    case 20:
        WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct WifiBattleMatchComp *)comp);
        if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),1))WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,0);else WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,1);
        *state=21;break;
    case 21:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp))*state=22;break;
    case 22:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]))),1))*state=23;else *state=29;break;
    case 23:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3d,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,24);*state=56;break;
    case 24:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp, 0);*state=25;break;
    case 25:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=35;break;case 1:*state=26;break;}}break;
    case 26:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3e,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,27);*state=56;break;
    case 27:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp, 0);*state=28;break;
    case 28:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=55;break;case 1:*state=23;break;}}break;
    case 29:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3c,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,30);*state=56;break;
    case 30:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp, 0);*state=31;break;
    case 31:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=35;break;case 1:*state=32;break;}}break;
    case 32:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3e,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,33);*state=56;break;
    case 33:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp, 0);*state=34;break;
    case 34:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=55;break;case 1:*state=29;break;}}break;
    case 35:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(comp))*state=36;break;
    case 36:WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(comp);*state=42;break;
    case 37:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x46,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,38);*state=56;break;
    case 38:if(*(u32 *)ctx[8]==0){MI_CpuFill8((void *)(ctx[13]+0x18),0,0x534);WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)H(comp),0,(void *)(CTX(comp)[13]+0x18));*state=39;}break;
    case 39:
        result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(H(comp));if(result==1){*(u32 *)CTX(comp)[8]=0x708;*state=40;}
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 40:{
        MI_CpuFill8(&request40,0,8);request40.a=0;request40.b=1;request40.id=WIFIBATTLEMATCH_NET_GetGsProfileId(H(comp));
        ((unsigned char *)CTX(comp)[12])[5]=1;WIFIBATTLEMATCH_NET_SetupHttpRap((u8 *)H(comp), (const W *)&request40, 87);*state=41;break;
    }
    case 41:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(H(comp));if(result==1)*state=53;else if(result==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 42:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3a,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,43);*state=56;break;
    case 43:
        save=(u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2]));box=BATTLE_BOX_GetFromSave((void *)save);
        party=(u32)REGULATION_GetParty((struct RecBig *)BATTLE_COMPETITION_GetFromSave((void *)save),0);
        MI_CpuCopy8(comp+0x10c,(void *)W(comp, 0x108),0x160);
        BATTLE_BOX_ClearLockFlags(box,1);REGULATION_Card_SetValue((struct Reg2 *)W(comp, 0x108),10,1);
        BSUBWAY_SAVEDATA_SetStat(ctx[4],10,0,0);BSUBWAY_SAVEDATA_SetStat(ctx[4],10,1,0);BSUBWAY_SAVEDATA_SetStat(ctx[4],10,2,0);
        REGULATION_InitParty((struct Rec1E *)party);GAME_DATA_SaveStart(*(u32 *)ctx[2]);*state=44;break;
    case 44:result=GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2]);if(result==2)*state=37;else if(result==3)*state=45;break;
    case 45:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x40,1);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,55);*state=56;break;
    case 46:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x5a,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,47);*state=56;break;
    case 47:if(*(u32 *)ctx[8]==0){WIFIBATTLEMATCH_NET_GdbRequest(H(comp),-1,1,ctx[13]);*state=48;}break;
    case 48:
        result=WIFIBATTLEMATCH_NET_GdbGetMyRecords(H(comp));if(result==1){*(u32 *)CTX(comp)[8]=0x708;*state=49;}
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(H(comp),(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 49:if(((u32 *)CTX(comp)[13])[4]!=BSUBWAY_SAVEDATA_GetStat(ctx[4],10,0))*state=50;else *state=55;break;
    case 50:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x3a,2);WIFIBATTLEMATCH_UTIL_SetRequest((u32)sys,51);*state=56;break;
    case 51:WIFIBATTLEMATCH_NET_GetSetCompStat(comp,(void *)ctx[13]);GAME_DATA_SaveStart(*(u32 *)ctx[2]);*state=52;break;
    case 52:if(GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2])==2)*state=55;break;
    case 53:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompStepRegisterParty);break;
    case 54:WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompStepMainMenu);break;
    case 55:ctx[1]=0;WIFIBATTLEMATCH_UTIL_SetCallback(sys,(int)WIFIBATTLEMATCH_NET_CompExit);break;
    case 56:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)W(comp, 0x2c)))WIFIBATTLEMATCH_UTIL_CommitRequest((u32)sys);break;
    }
}

#undef W

#define W(base, k) (*(u32 *)((base) + (k)))

void WIFIBATTLEMATCH_NET_CompStepRegisterParty(u32 sys,int *state,char *comp)
{
    u32 *ctx=(u32 *)W(comp, 0x104);
    int result,index,count,empty;
    char *record;
    void *box;
    u32 save,party,mask;
    Request request;
    switch(*state) {
    case 0: WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct WifiBattleMatchComp *)comp); WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,2); WIFIBATTLEMATCH_NET_SetupCompPartyWindow(comp); *state=1; break;
    case 1: result=1; result &= WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp); result &= WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(comp); if(result) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x41,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,3); *state=30; break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp,2); *state=4; break;
    case 4: result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp); if(result!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) {case 0:*state=12;break;case 1:*state=5;break;}} break;
    case 5: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x44,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,6); *state=30; break;
    case 6: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp,0); *state=7; break;
    case 7: result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp); if(result!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) {case 0:*state=8;break;case 1:*state=2;break;}} break;
    case 8: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x45,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,9); *state=30; break;
    case 9: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp,0); *state=10; break;
    case 10: result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp); if(result!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) {case 0:*state=11;break;case 1:*state=2;break;}} break;
    case 11: if(WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(comp)) {WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(comp); *state=29;} break;
    case 12:
        record=(char *)ctx[5]; WIFIBATTLEMATCH_NET_CopyCompBox(record,comp);
        if(POKEPARTY_GetBattleReadyCount(record+0xd4)==0) *state=14;
        else {mask=0; if(POKE_REGULATION_CheckParty((void *)REGULATION_NoOp(W(comp, 0x108)),record+0xd4,&mask)==0) *state=15; else *state=13;}
        break;
    case 13: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x49,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 14: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x61,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 15: if(WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(comp)) {WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(comp); *state=16;} break;
    case 16: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x46,2); WIFIBATTLEMATCH_UTIL_SetRequest(sys,17); *state=30; break;
    case 17:
        WIFIBATTLEMATCH_NET_SetupPostData((char *)W(comp, 0x34),(void *)(ctx[5]+0xd4),1);
        MI_CpuFill8(comp+0x44,0,0x9c); *state=18; break;
    case 18:
        result=WIFIBATTLEMATCH_NET_HttpRapPost((char *)W(comp, 0x34),(u8 *)(comp+0x44));
        if(result==1) {
            count=POKEPARTY_GetCount((void *)(ctx[5]+0xd4)); empty=0;
            for(index=0;index<count;index++) if(((SlotView *)comp)->slots[index]==0) empty++;
            if(((struct WifiBattleMatchComp *)comp)->responseFlag==0 && empty==count) *state=20; else *state=19;
        } else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)W(comp, 0x34),0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 19: WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x47,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 20: if(*(u32 *)ctx[8]==0) {WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)W(comp, 0x34),0,(void *)(ctx[5]+0xd4));*state=21;} break;
    case 21:
        result=WIFIBATTLEMATCH_NET_GdbUpdateRecord((char *)W(comp, 0x34));
        if(result==1) {*(u32 *)((u32 *)W(comp, 0x104))[8]=0x708; *state=22;}
        if(result!=0) switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)W(comp, 0x34),0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 22:
        save=(u32)GAME_DATA_GetSaveControl((struct Big *)(*(u32 *)ctx[2])); box=BATTLE_BOX_GetFromSave((void *)save);
        party=(u32)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave((void *)save),0);
        save=(u32)BATTLE_BOX_CreateParty((int)box,0x8056); BATTLE_BOX_SetLockFlags(box, 1);
        REGULATION_Card_SetValue((struct Reg2 *)W(comp, 0x108),10,2); REGULATION_BuildParty(party,save); GFL_HEAP_Free((void *)save);
        *state=23; break;
    case 23: GAME_DATA_SaveStart(*(u32 *)ctx[2]); *state=24; break;
    case 24: result=GAME_DATA_SaveMain((unsigned char *)*(u32 *)ctx[2]); if(result==2) *state=25; else if(result==3) *state=29; break;
    case 25:
        MI_CpuFill8(&request,0,8); request.b=2; request.id=WIFIBATTLEMATCH_NET_GetGsProfileId((char *)W(comp, 0x34));
        ((unsigned char *)((u32 *)W(comp, 0x104))[12])[5]=2;
        WIFIBATTLEMATCH_NET_SetupHttpRap((u8 *)W(comp, 0x34),(const W *)&request,87); *state=26; break;
    case 26:
        result=WIFIBATTLEMATCH_NET_HttpRapSend((char *)W(comp, 0x34)); if(result==1) *state=27; else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError((char *)W(comp, 0x34),0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;} break;
    case 27: WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,0); WIFIBATTLEMATCH_UTIL_PrintMessage((int *)W(comp, 0x2c),W(comp, 0x14),0x48,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,28); *state=30; break;
    case 28: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMainMenu); break;
    case 29: ctx[1]=0; WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit); break;
    case 30: if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)W(comp, 0x2c))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepMainMenu(u32 sys,int *state,char *comp)
{
    char *params=*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx;
    int result;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,0)) {
        case 0:*state=1;break;
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:if(((struct WifiBattleMatchComp *)comp)->tradeIcon==0) {
            WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct WifiBattleMatchComp *)comp);WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,0);*state=2;
        } else *state=3;
        break;
    case 2:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp)) *state=3;break;
    case 3:BG_SYS_SetPlaneVisible(0,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,74,1);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);*state=16;break;
    case 4:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)((u32 *)comp), 3);*state=5;break;
    case 5:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch(result) {
            case 0:*state=10;break;
            case 1:*state=7;break;
            case 2:*state=6;break;
            }
        }break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepConfirmQuit);break;
    case 7:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepWithdrawEntry);*state=8;break;
    case 8:result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if(result==1 || result==2) *state=1;
        else if(result==0) *state=9;
        else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,0)) {
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 9:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 10:WIFIBATTLEMATCH_NET_CopyCompBox(*(char * *)&((struct WifiBattleMatchParams *)params)->profile,comp);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,24,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,11);*state=16;break;
    case 11:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepPostPartyData);*state=12;break;
    case 12:result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if(result==0) *state=13;
        else if(result==1) *state=13;
        else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,0)) {
        case 1:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMainMenu);break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 13:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMatchmake);break;
    case 14:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,120,1);
        *state=16;WIFIBATTLEMATCH_UTIL_SetRequest(sys,15);break;
    case 15:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 16:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj)))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

static inline void TouchParty(u8 *rec, u8 *buf)
{
    int i;

    BUTTON_MAN_ConvertUcs2ToSjis(rec, buf, 8);
    {
        void *party = rec + 0xd4;

        for (i = 0; i < (int)POKEPARTY_GetCount(party); i++)
            POKEPARTY_GetMember(party, i);
    }
}

/*
 * The ov175 link-battle main sequence: one step of a 54-state machine over
 *     *state (0..0x35) on the object in r2, with the frame's sys handle in r0.
 *     The listing cuts it at 0x021D885C, a bl-minted label on its own shared
 *     tail (the timeout and disconnect check); the real extent is
 *     0x021D7E18..0x021D8904, 2796 bytes.
 *
 * The six leaf calls that kept it at MATCH* (0x021E8AB4 x3, 0x021E8AB8,
 *     0x02156F50, 0x02009EC8) resolve since seeds_2 labelled and matched them.
 */
void WIFIBATTLEMATCH_NET_CompStepMatchmake(u32 sys, int *state, struct WifiBattleMatchComp *comp)
{
    struct Buf16 buf;
    char *rec38;
    u32 mask;
    u32 out;
    u8 b28[8];
    u8 b20[8];
    void *str;
    struct WifiBattleMatchParams *w18;
    int flag;
    int fresh;
    int bad;
    int stepState;
    int res;
    int i;
    int trig = 0;
    u8 *record;
    void *msg;

    w18 = comp->ctx;
    flag = 0;
    stepState = *state;
    if (stepState >= 0xc && stepState < 0x1b)
        trig = 1;
    res = WIFIBATTLEMATCH_NET_CompHandleCancel((char *)comp, trig,
                        !((stepState >= 0x19 && stepState <= 0x1a) || (stepState >= 0x11 && stepState <= 0x12)));
    if (res == 3) {
        *state = 0x28;
        return;
    }

    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp->textObj, comp->msgBank, 0x18, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        *state = 0x35;
        break;
    case 1:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepMainMenu);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback((char *)comp, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 2;
            break;
        }
        break;
    case 2:
        i = WIFIBATTLEMATCH_NET_GetCompWaitResult((char *)comp);
        if (i == 0)
            *state = 4;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepMainMenu);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);
        break;
    case 4:
        if (*comp->ctx->statPtr == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(comp->net, -1, 1, (u32)comp->ctx->sub);
            *state = 5;
        }
        break;
    case 5:
        i = WIFIBATTLEMATCH_NET_GdbGetMyRecords(comp->net);
        if (i == 1) {
            record = w18->profile;
            *comp->ctx->statPtr = 0;
            WIFIBATTLEMATCH_NET_CopyCompSave((char *)record, (char *)comp);
            *comp->ctx->recLast = comp->ctx->sub->recSeed;
            if (WIFIBATTLEMATCH_NET_GetSetCompStat((char *)comp, (u32 *)comp->ctx->sub) != 0)
                *state = 6;
            else
                *state = 0xa;
        }
        if (i != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepMainMenu);
                WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 6:
        *state = 7;
        break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle((char *)comp) != 0) {
            WIFIBATTLEMATCH_NET_DeleteCompStatusWindow((char *)comp);
            *state = 8;
        }
        break;
    case 8:
        WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct WifiBattleMatchComp *)comp);
        *state = 9;
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_IsCompStatusWindowReady((char *)comp) != 0)
            *state = 0xa;
        break;
    case 0xa:
        comp->stepCounter = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp->textObj, comp->msgBank, 0x55, 0);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0xb);
        break;
    case 0xb:
        i = comp->card;
        MI_CpuFill8(&buf, 0, sizeof(buf));
        buf.keyA = comp->ctx->sub->keyA;
        buf.keyB = comp->ctx->sub->keyB;
        buf.keyC = REGULATION_Card_GetValue((struct Reg2 *)i, 2);
        buf.keyD = comp->ctx->sub->keyDBase + comp->ctx->sub->keyDDelta;
        WIFIBATTLEMATCH_NET_SetMatchKey(comp->net, 0, 0, w18->save[1], (int *)(&buf));
        comp->regFlag = 0;
        comp->timeout = 0;
        *state = 0xc;
        break;
    case 0xc:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        i = WIFIBATTLEMATCH_NET_StartMatchmaking(comp->net);
        if (i == 1)
            *state = 0xd;
        else if (i == 2)
            *state = 0xb;
        break;
    case 0xd:
        if (res == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData(comp->net, (u32)w18->profile) != 0) {
                *state = 0xe;
                comp->rapFlag = 0;
            }
        } else {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
            case 4:
                comp->stepCounter = 0;
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu((char *)comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
                WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
                break;
            case 2:
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu((char *)comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0xe:
        if (WIFIBATTLEMATCH_NET_TakeRegData(comp->net, &rec38) != 0) {
            MI_CpuCopy8(rec38, w18->record, POKE_REGULATION_GetDataSize() + 0xd4);
            record = w18->record;
            bad = 0;
            fresh = 1;
            for (i = 0; i < 8; i++) {
                if (((u16 *)record)[i] == STRBUF_GetEosChar())
                    fresh = 0;
            }
            if (fresh) {
                bad++;
                msg = MSGDATA_CreateFromArchive(0, 2, 0xd2, 0x8057);
                str = MSGDATA_AllocString(msg, 0x8057);
                STRBUF_ToChars(str, (u16 *)record, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete(msg);
            }
            if (record[0x1d] != 0 && record[0x1d] != 1) {
                record[0x1d] = 0;
                bad++;
            }
            if ((u8)record[0x1c] >= 0x10) {
                record[0x1c] = record[0x1d] == 0 ? 0 : 8;
                bad++;
            }
            if (NATION_AREA_IsValidNationArea(record[0x18], record[0x19], record[0x1a]) == 0) {
                record[0x18] = 0;
                record[0x19] = 0;
                bad++;
            }
            if (PMSI_PARAM_IsValid((struct PmsData *)(record + 0x38), 0x8057) == 0) {
                PMSI_PARAM_InitSentence(record + 0x38, 1);
                bad++;
            }
            if (bad == 0)
                TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*w18->save)));
            *state = 0xf;
        }
        flag = 1;
        break;
    case 0xf:
        TouchParty(w18->profile, b28);
        TouchParty(w18->record, b20);
        if (((struct WifiBattleMatchStatRecord *)(w18->profile))->cardValue == ((struct WifiBattleMatchStatRecord *)(w18->record))->cardValue
            && ((struct WifiBattleMatchStatRecord *)(w18->profile))->crc == ((struct WifiBattleMatchStatRecord *)(w18->record))->crc)
            *state = 0x10;
        else
            *state = 0x33;
        break;
    case 0x10:
        mask = 0;
        if (POKE_REGULATION_CheckParty((void *)REGULATION_NoOp(comp->card), w18->record + 0xd4, (u32 *)&mask) == 0) {
            *state = 0x11;
        } else {
            comp->regFlag++;
            *state = 0x16;
        }
        break;
    case 0x11:
        if (*comp->ctx->statPtr == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(comp->net, ((struct WifiBattleMatchStatRecord *)(comp->ctx->record))->netId, 3, comp->party);
            *state = 0x12;
        }
        break;
    case 0x12:
        i = WIFIBATTLEMATCH_NET_GdbGetMyRecords(comp->net);
        if (i == 1) {
            *comp->ctx->statPtr = 0xe10;
            *state = 0x13;
        }
        if (i != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
            case 4:
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
                WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
                break;
            case 2:
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x13:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(comp->net, 0x17);
        *state = 0x14;
        break;
    case 0x14:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(comp->net) != 0)
            *state = 0x15;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
        case 1:
        case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x15:
        if (WIFIBATTLEMATCH_NET_CompareParty(comp->party, (u32)(comp->ctx->record + 0xd4)) == 0)
            comp->regFlag++;
        if (WIFIBATTLEMATCH_NET_VerifyCompSignature((char *)comp->ctx->record, comp->ctx->record + 0xd4, 0x57) == 0)
            comp->regFlag++;
        *state = 0x16;
        break;
    case 0x16:
        if (res == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegFlag(comp->net, (u32)(&comp->regFlag)) != 0) {
                *state = 0x17;
                comp->rapFlag = 0;
            }
        } else {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
            case 4:
                comp->stepCounter = 0;
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu((char *)comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
                WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
                break;
            case 2:
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu((char *)comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x17:
        if (WIFIBATTLEMATCH_NET_TakeRegFlag(comp->net, (u32)(&comp->timeout)) != 0)
            *state = 0x18;
        else
            flag = 1;
        break;
    case 0x18:
        if (comp->timeout == 0 && comp->regFlag == 0)
            *state = 0x19;
        else
            *state = 0x33;
        break;
    case 0x19:
        WIFIBATTLEMATCH_NET_StartProfanityCheck(comp->net, (u32)w18->record, 0x57);
        *state = 0x1a;
        break;
    case 0x1a:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess(comp->net, (int *)(&out)) != 0) {
            *comp->ctx->resultPtr = out;
            *state = 0x1b;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
        case 1:
        case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x1b:
        if (res == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange(comp->net, 0x15);
            comp->rapFlag = 0;
            *state = 0x1c;
        }
        break;
    case 0x1c:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(comp->net) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange(comp->net) != 0)
            *state = 0x1d;
        flag = 1;
        break;
    case 0x1d:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(comp->net, 0x16);
        *state = 0x1e;
        comp->rapFlag = 0;
        break;
    case 0x1e:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(comp->net) != 0)
            *state = 0x1f;
        flag = 1;
        break;
    case 0x1f:
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp->textObj, comp->msgBank, 0x57, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x20);
        comp->timer = 0;
        break;
    case 0x20:
        if (comp->timer++ > 0x78) {
            comp->timer = 0;
            BG_SYS_SetPlaneVisible(0, 0);
            WIFIBATTLEMATCH_NET_StartRegCardAnim((u32 *)comp, (u32)w18->record);
            *state = 0x21;
        }
        break;
    case 0x21:
        if (WIFIBATTLEMATCH_NET_IsCompRegCardReady((char *)comp) != 0)
            *state = 0x22;
        break;
    case 0x22:
        if (comp->timer++ != 0) {
            comp->timer = 0;
            *state = 0x23;
        }
        break;
    case 0x23:
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        WIFIBATTLEMATCH_NET_SetupMatchReport(comp->net, 0, 0, 0, 0, 0);
        comp->reportState = 0;
        *state = 0x24;
        comp->reportResult = 0;
        break;
    case 0x24:
        if (comp->reportResult == 0)
            comp->reportResult = WIFIBATTLEMATCH_NET_ScProcess((char *)comp->net, (u32 *)(&comp->reportState));
        if (comp->reportResult == 1)
            *state = 0x25;
        if (comp->reportResult != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
                WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
            case 2:
            case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x25:
        DWC_RAPCOMMON_DestroySubHeap();
        BG_SYS_SetPlaneVisible(0, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp->textObj, comp->msgBank, 0x24, 2);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x26);
        break;
    case 0x26:
        if (comp->timer++ > 0x3c) {
            comp->timer = 0;
            w18->netState = 1;
            WIFIBATTLEMATCH_UTIL_ClearCallback(sys);
        }
        break;
    case 0x27:
        WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
        w18->state = 2;
        comp->gdbFlag = 1;
        if (comp->reportState != 0)
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult);
        else
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
        break;
    case 0x28:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp->textObj, comp->msgBank, 0x4e, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x29);
        break;
    case 0x29:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)((u32 *)comp), 0);
        *state = 0x2a;
        break;
    case 0x2a:
        i = WIFIBATTLEMATCH_NET_PollCompChoiceMenu((char *)comp);
        if (i != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu((char *)comp);
            switch (i) {
            case 0:
                WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit);
                break;
            case 1:
                *state = 0x2b;
                break;
            }
        }
        break;
    case 0x2b:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)comp->textObj, comp->msgBank, 0x26, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x2c);
        break;
    case 0x2c:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)((u32 *)comp), 0);
        *state = 0x2d;
        break;
    case 0x2d:
        i = WIFIBATTLEMATCH_NET_PollCompChoiceMenu((char *)comp);
        if (i != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu((char *)comp);
            switch (i) {
            case 0:
                *state = 0x2e;
                break;
            case 1:
                *state = 0x28;
                break;
            }
        }
        break;
    case 0x2e:
        *state = 0x2f;
        break;
    case 0x2f:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepMainMenu);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback((char *)comp, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 0x30;
            break;
        }
        break;
    case 0x30:
        i = WIFIBATTLEMATCH_NET_GetCompWaitResult((char *)comp);
        if (i == 0)
            *state = 0xa;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepMainMenu);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x31:
        if (WIFIBATTLEMATCH_NET_SendSessionQuery(comp->net) != 0)
            *state = 0x32;
        break;
    case 0x32:
        WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
        *state = 0xa;
        break;
    case 0x33:
        WIFIBATTLEMATCH_NET_ClearCancelFlag(comp->net);
        *state = 0x34;
        comp->rapFlag = 0;
        break;
    case 0x34:
        flag = 1;
        if (WIFIBATTLEMATCH_NET_StopMatchmaking(comp->net) != 0)
            *state = 0xb;
        break;
    case 0x35:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)comp->textObj) != 0)
            WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }

    if (flag) {
        i = 0;
        if (comp->rapFlag++ > 0x4b0) {
            comp->rapFlag = 0;
            i = 1;
        }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(comp->net) != 0)
            i = 1;
        if (i) {
            WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
            if (GFL_NET_ERR_GetErrorLevel() == 0 && GFL_NET_GetRunState() != 0)
                DWC_CloseAllConnectionsHard();
            *state = 0xa;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
        case 1:
        case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError((char *)comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
    }
}

void WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult(u32 sys,int *state,char *comp)
{
    char *params=*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx;
    Rec84 rec;
    void *list;
    int result;
    switch(*state) {
    case 0:if(((struct WifiBattleMatchParams *)params)->state==2 && ((struct WifiBattleMatchComp *)comp)->gdbFlag==0) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle);
        else {
            ((struct WifiBattleMatchComp *)comp)->gdbFlag=0;
            GFL_HEAP_CreateChildHeap(1,134,0x60000);
            DWC_RAPCOMMON_CreateSubHeap(9,0x60000,1000,134);
            DWC_RAPCOMMON_SetHeapTag(134);*state=1;
        }break;
    case 1:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,70,2);
        *state=13;WIFIBATTLEMATCH_UTIL_SetRequest(sys,2);break;
    case 2:WIFIBATTLEMATCH_NET_SetupMatchReport((char *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->net), 1, 0, (*(u32 **)(params+8))[1], (u32 *)(*(u32 * *)&((struct WifiBattleMatchParams *)params)->saveBlock), ((struct WifiBattleMatchParams *)params)->state==2);
        ((struct WifiBattleMatchComp *)comp)->reportResult=0;((struct WifiBattleMatchComp *)comp)->reportState=0;*state=3;break;
    case 3:
        if(((struct WifiBattleMatchComp *)comp)->reportResult==0) {
            ((struct WifiBattleMatchComp *)comp)->reportResult=WIFIBATTLEMATCH_NET_ScProcess((char *)(((struct WifiBattleMatchComp *)comp)->net), (u32 *)((u32 *)(comp+244)));
            if(((struct WifiBattleMatchComp *)comp)->reportResult!=0 && ((struct WifiBattleMatchComp *)comp)->reportState!=0)
                WIFIBATTLEMATCH_UTIL_SetSaveState(**(int * *)&((struct WifiBattleMatchParams *)params)->save,**(int * *)&((struct WifiBattleMatchParams *)params)->saveBlock);
        }
        if(((struct WifiBattleMatchComp *)comp)->reportResult==1) {
            ((struct WifiBattleMatchSaveBlock *)(*(char * *)&((struct WifiBattleMatchParams *)params)->saveBlock))->reportState=WIFIBATTLEMATCH_NET_GetReportState((u8 *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->net));*state=4;
        }
        if(((struct WifiBattleMatchComp *)comp)->reportResult!=0) {
            switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,(void *)1)) {
            case 1:WIFIBATTLEMATCH_NET_DisconnectWifi(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);
            case 2:case 4:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);DWC_RAPCOMMON_DestroySubHeap();break;
            }
        }break;
    case 4:DWC_RAPCOMMON_DestroySubHeap();
        if(((struct WifiBattleMatchParams *)params)->state==2)WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle);
        else *state=5;break;
    case 5:list=MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct WifiBattleMatchParams *)params)->save));
        MET_TRAINERS_Insert(list,MYSTATUS_GetId((void *)((struct WifiBattleMatchParams *)params)->record));
        WIFIBATTLEMATCH_NET_ClearCancelFlag(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);*state=6;break;
    case 6:if(WIFIBATTLEMATCH_NET_StopMatchmaking(*(char * *)&((struct WifiBattleMatchComp *)comp)->net)) *state=7;
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,(void *)1)) {
        case 1:case 4:*state=7;break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 7:if(**(u32 * *)&((struct WifiBattleMatchParams *)params)->statPtr==0) {
        MI_CpuFill8(&rec,0,84);
        rec.data=**(Rec80 * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx))->recData;
        rec.last=**(u32 * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx))->recLast;
        WIFIBATTLEMATCH_NET_SetupGdbUpload((u8 *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->net),3,(struct Record *)(&rec));*state=8;
        }break;
    case 8:result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);
        if(result==1) {
            **(u32 * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx))->statPtr=1800;*state=9;
        }
        if(result!=0) {
            switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,0)) {
            case 1:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepAskRetry);break;
            case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
            }
        }break;
    case 9:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,88,1);
        *state=13;WIFIBATTLEMATCH_UTIL_SetRequest(sys,10);break;
    case 10:((struct WifiBattleMatchParams *)params)->netState=2;WIFIBATTLEMATCH_UTIL_ClearCallback(sys);break;
    case 13:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj)))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle(int *a, int *state, char *comp)
{
    int result;
    u32 waitResult;
    char *params = *(char **)(comp + 0x104);
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int **)(comp + 0x2C), *(int *)(comp + 0x14), 0x28, 2);
        *state = 5;
        WIFIBATTLEMATCH_UTIL_SetRequest((unsigned)a, 1);
        return;
    case 1:
        WIFIBATTLEMATCH_NET_GetSetCompStat(comp, *(void **)(params + 0x34));
        GAME_DATA_SaveStart(**(int **)(params + 8));
        *state = 2;
        return;
    case 2:
        result = GAME_DATA_SaveMain(**(u8 ***)(params + 8));
        if (result == 2) {
            *state = 3;
            return;
        }
        if (result == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);
        return;
    case 3:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(*(char **)(comp + 0x34), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
            return;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            return;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp, (void *)WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 4;
            return;
        }
        return;
    case 4:
        waitResult = WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if (waitResult == 0)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
        else if (waitResult - 1 <= 1)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);
        else if (waitResult == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(*(char **)(comp + 0x34), 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry);
            return;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            return;
        }
        return;
    case 5:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(*(int **)(comp + 0x2C)))
            WIFIBATTLEMATCH_UTIL_CommitRequest((unsigned)a);
        return;
    }
}

/*
 * Lever: the two-value tail dispatch is a switch; if (v==1 || v==2) folds into a range and compiles 316/320 bytes.
 */
void WIFIBATTLEMATCH_NET_CompStepAskRetry(u32 sys,int *state,char *comp)
{
    int result;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,(void *)1)) {
        case 0:case 1:case 4:*state=1;break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:BG_SYS_SetPlaneVisible(0,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,92,1);
        *state=7;WIFIBATTLEMATCH_UTIL_SetRequest(sys,2);break;
    case 2:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)((u32 *)comp), 4);*state=3;break;
    case 3:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch(result) {
            case 0:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepMatchmake);break;
            case 1:*state=4;break;
            case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepConfirmQuit);break;
            }
        }break;
    case 4:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepWithdrawEntry);*state=5;break;
    case 5:result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if(result==1 || result==2) *state=1;
        else if(result==0) *state=6;
        result=WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,0,0);
        switch(result) {
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompCleanup);break;
        }
        break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 7:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj)))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepConfirmQuit(u32 sys, int *state, char *comp)
{
    int result;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj), ((struct WifiBattleMatchComp *)comp)->msgBank, 0x4e, 1);
        *state = 3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        break;
    case 1:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)((u32 *)comp), 0);
        *state = 2;
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepAskRetry); break;
            }
        }
        break;
    case 3:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(u32 sys,int *state,char *comp)
{
    char *params=*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx;
    switch(*state) {
    case 0:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,40,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);*state=7;break;
    case 1:GAME_DATA_SaveStart((int)(**(void ** *)&((struct WifiBattleMatchParams *)params)->save));*state=2;break;
    case 2:if(GAME_DATA_SaveMain(**(void ** *)&((struct WifiBattleMatchParams *)params)->save)==2) *state=3;break;
    case 3:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,37,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);*state=7;break;
    case 4:if(**(u32 * *)&((struct WifiBattleMatchParams *)params)->statPtr==0) {WIFIBATTLEMATCH_NET_SetupGdbUpload(((struct WifiBattleMatchComp *)comp)->net,2,0);*state=5;}break;
    case 5:if(WIFIBATTLEMATCH_NET_GdbUpdateRecord(((struct WifiBattleMatchComp *)comp)->net)) {
        **(u32 * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx))->statPtr=1800;*state=6;
        WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct WifiBattleMatchComp *)comp)->net,(void *)1,0);
    }break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys,(int)WIFIBATTLEMATCH_NET_CompExit);break;
    case 7:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

/*
 * follower: 021D905C tail-call stub included; function_starts seed 021D905C.
 */
void WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit(u32 sys, int *state, char *comp)
{
    int result;
    switch (*state) {
    case 0:
        result = WIFIBATTLEMATCH_NET_HandleNetError(((struct WifiBattleMatchComp *)comp)->net, (void *)1, 0);
        switch (result) {
        case 1: case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 1;
            break;
        }
        break;
    case 1:
        result = WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if (result != 0xffff) *state = 2;
        if (result == 3) WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup);
        result = WIFIBATTLEMATCH_NET_HandleNetError(((struct WifiBattleMatchComp *)comp)->net, (void *)1, 0);
        switch (result) {
        case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompCleanup); break;
        }
        break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback((int *)sys, (int)WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit); break;
    case 3:
        if (WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj))) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_CompExit(u32 sys)
{
    WIFIBATTLEMATCH_UTIL_ClearCallback(sys);
}

void WIFIBATTLEMATCH_NET_CompCleanup(void *obj,int unused,u8 *comp) { ((struct WifiBattleMatchParams *)(*(u8 * *)&((struct WifiBattleMatchComp *)comp)->ctx))->netState=3; if(((struct WifiBattleMatchComp *)comp)->net) { WIFIBATTLEMATCH_NET_DeleteNetContext(((struct WifiBattleMatchComp *)comp)->net); *(u32 *)&((struct WifiBattleMatchComp *)comp)->net=0; } GFL_NET_ERR_WaitLinkClosed(); WIFIBATTLEMATCH_UTIL_ClearCallback((int)obj); }

/*
 * Lever: byte range test uses (u8)(value + 255), preserving adds #255.
 * Extent: final 021D9342..021D9344 is zero alignment padding.
 */
void WIFIBATTLEMATCH_NET_CompStepCheckPeriod(u32 sys,int *state,char *comp)
{
    char *params=*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx;
    struct RTCDate startDate;
    struct RTCDate endDate;
    struct RTCDate nowDate;
    struct RTCTime nowTime;
    Request req;
    struct Reg2 *reg;
    struct WifiBattleMatchComp *box;
    int got;
    int startDay,endDay,nowDay,result;
    switch(*state) {
    case 0:*state=1;break;
    case 1:reg=*(struct Reg2 * *)&((struct WifiBattleMatchComp *)comp)->card;
        if(!GFL_NET_GetRunState())GFL_NET_ERR_HaltIfActive();
        got=DWC_GetDateTime((int *)&nowDate,(int *)&nowTime);
        if(got)RTC_ConvertSecondToDateTime(&nowDate,&nowTime,RTC_ConvertDateTimeToSecond(&nowDate,&nowTime));
        startDate.year=REGULATION_Card_GetValue(reg,4);
        startDate.month=REGULATION_Card_GetValue(reg,5);
        startDate.day=REGULATION_Card_GetValue(reg,6);startDate.week=0;
        endDate.year=REGULATION_Card_GetValue(reg,7);
        endDate.month=REGULATION_Card_GetValue(reg,8);
        endDate.day=REGULATION_Card_GetValue(reg,9);endDate.week=0;
        startDay=RTC_ConvertDateToDay(&startDate);
        endDay=RTC_ConvertDateToDay(&endDate);
        nowDay=RTC_ConvertDateToDay(&nowDate);
        if(got && nowDay<startDay) {((struct WifiBattleMatchComp *)comp)->waitResult=2;*state=2;}
        else if(got && startDay<=nowDay && nowDay<=endDay) {((struct WifiBattleMatchComp *)comp)->waitResult=0;*state=13;}
        else {((struct WifiBattleMatchComp *)comp)->waitResult=1;*state=3;}
        break;
    case 2:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,96,1);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,13);break;
    case 3:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,80,1);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);break;
    case 4:if((u8)((*(u8 **)(params+48))[5]+255)<=1) *state=5;
        else *state=13;break;
    case 5:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,40,2);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,6);break;
    case 6:box=BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct WifiBattleMatchParams *)params)->save));
        ((struct WifiBattleMatchComp *)comp)->boxLocked=BATTLE_BOX_IsLocked(box, 1);
        BATTLE_BOX_ClearLockFlags(box, 1);
        REGULATION_Card_SetValue(*(struct Reg2 * *)&((struct WifiBattleMatchComp *)comp)->card,10,3);
        GAME_DATA_SaveStart(**(int * *)&((struct WifiBattleMatchParams *)params)->save);*state=7;break;
    case 7:if(GAME_DATA_SaveMain(**(void ** *)&((struct WifiBattleMatchParams *)params)->save)==2) *state=8;break;
    case 8:BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct WifiBattleMatchParams *)params)->save));
        if(((struct WifiBattleMatchComp *)comp)->boxLocked!=0) *state=9;else *state=10;break;
    case 9:WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,81,1);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,10);break;
    case 10:WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)comp)->textObj),((struct WifiBattleMatchComp *)comp)->msgBank,70,2);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,11);break;
    case 11:MI_CpuFill8(&req,0,8);req.b=3;
        req.id=WIFIBATTLEMATCH_NET_GetGsProfileId(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);
        (*(u8 **)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx+48))[5]=3;
        WIFIBATTLEMATCH_NET_SetupHttpRap(*(u8 * *)&((struct WifiBattleMatchComp *)comp)->net,(const W *)&req,87);*state=12;break;
    case 12:result=WIFIBATTLEMATCH_NET_HttpRapSend(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);
        if(result==1) *state=13;
        else if(result==3) {((struct WifiBattleMatchComp *)comp)->waitResult=3;*state=13;}
        break;
    case 13:WIFIBATTLEMATCH_UTIL_ClearCallback(sys);break;
    case 14:if(WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)comp)->textObj)))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepWithdrawEntry(u32 sys,int *state,char *comp) {
    char *params=*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx;
    int result;
    Request request;
    switch(*state) {
    case 0:
        result=((struct WifiBattleMatchSession *)(*(char * *)&((struct WifiBattleMatchParams *)params)->session))->subState;
        if((u8)(result+255)<=1) { ((struct WifiBattleMatchComp *)comp)->waitResult=1; *state=2; }
        else { ((struct WifiBattleMatchComp *)comp)->waitResult=2; *state=1; }
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj,((struct WifiBattleMatchComp *)comp)->msgBank,82,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,15); break;
    case 2:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj,((struct WifiBattleMatchComp *)comp)->msgBank,83,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,3); break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp,5); *state=4; break;
    case 4:
        result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) { WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) { case 0:*state=5;break; case 1:*state=15;break; } }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj,((struct WifiBattleMatchComp *)comp)->msgBank,84,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,6); break;
    case 6: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)comp,5); *state=7; break;
    case 7:
        result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) { WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) { case 0:*state=8;break; case 1:*state=15;break; } }
        break;
    case 8:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj,((struct WifiBattleMatchComp *)comp)->msgBank,40,2);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,9); break;
    case 9:
        BATTLE_BOX_ClearLockFlags(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(struct Big ** *)&((struct WifiBattleMatchParams *)params)->save)), 1);
        REGULATION_Card_SetValue((struct Reg2 *)(((struct WifiBattleMatchComp *)comp)->card),10,4);
        GAME_DATA_SaveStart(**(int * *)&((struct WifiBattleMatchParams *)params)->save); *state=10; break;
    case 10:
        result=GAME_DATA_SaveMain(**(u8 ** *)&((struct WifiBattleMatchParams *)params)->save);
        if(result==2) { ((struct WifiBattleMatchComp *)comp)->waitResult=0; *state=11; }
        else if(result==3) *state=15;
        break;
    case 11:
        WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj,((struct WifiBattleMatchComp *)comp)->msgBank,81,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,12); break;
    case 12:
        WIFIBATTLEMATCH_UTIL_PrintMessage(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj,((struct WifiBattleMatchComp *)comp)->msgBank,70,2);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,13); break;
    case 13:
        MI_CpuFill8(&request,0,8); request.b=4;
        request.id=WIFIBATTLEMATCH_NET_GetGsProfileId(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);
        ((struct WifiBattleMatchSession *)(*(char * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx))->session))->subState=4;
        WIFIBATTLEMATCH_NET_SetupHttpRap(*(u8 * *)&((struct WifiBattleMatchComp *)comp)->net,(const W *)&request,87); *state=14; break;
    case 14:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(*(char * *)&((struct WifiBattleMatchComp *)comp)->net);
        if(result==1) *state=15;
        else if(result==3) { ((struct WifiBattleMatchComp *)comp)->waitResult=3; *state=15; }
        break;
    case 15: WIFIBATTLEMATCH_UTIL_ClearCallback(sys); break;
    case 16: if(WIFIBATTLEMATCH_UTIL_GetBusy(*(int * *)&((struct WifiBattleMatchComp *)comp)->textObj)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepPostPartyData(u32 sys, int *state, char *comp)
{
    char *save;
    int result;
    save = *(char * *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)comp)->ctx))->profile;
    switch (*state) {
    case 0: *state = 1; break;
    case 1:
        MI_CpuFill8(comp + 0x44, 0, 0x9c);
        WIFIBATTLEMATCH_NET_SetupPostData(((struct WifiBattleMatchComp *)comp)->net, save + 0xd4, 1);
        *state = 2;
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_HttpRapPost(((struct WifiBattleMatchComp *)comp)->net, (u8 *)(comp + 0x44));
        if (result == 1) *state = 3;
        else if (result == 2) { ((struct WifiBattleMatchComp *)comp)->waitResult = 2; *state = 4; }
        else if (result == 3) { ((struct WifiBattleMatchComp *)comp)->waitResult = 3; *state = 4; }
        break;
    case 3:
        if (((struct WifiBattleMatchComp *)comp)->responseFlag == 0) {
            WIFIBATTLEMATCH_NET_CopyCompResponse(save, comp + 0x44);
            ((struct WifiBattleMatchComp *)comp)->waitResult = 0;
            *state = 4;
        } else {
            ((struct WifiBattleMatchComp *)comp)->waitResult = 1;
            *state = 4;
        }
        break;
    case 4: WIFIBATTLEMATCH_UTIL_ClearCallback(sys); break;
    }
}

/*
 * Opens the +0x1c profile exchange when none is open: builds a 0xac-byte
 *     profile (0x92 bytes copied from the +0x108 block, three packed byte
 *     triples, the play-time words from the +0x104 save), then hands it to
 *     0x021E5D68 with the +0x04..+0x18 words.
 *
 * The three calls to 0x0200DFD8 resolve since seeds_2 labelled and matched
 *     it (src/matched/unit_0200DFD8.c).
 */
void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct WifiBattleMatchComp *obj)
{
    struct Profile prof;
    u32 sys;
    u32 id;
    u32 kind;
    u32 cardValA;
    u32 cardValB;
    u32 card;
    u32 cardValC;

    if (obj->tradeIcon == 0) {
        card = obj->card;
        sys = (u32)GAME_DATA_GetMyStatus((void *)(*obj->ctx->save));
        id = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)obj->sprite);
        kind = (u32)REGULATION_GetParty(BATTLE_COMPETITION_GetFromSave(GAME_DATA_GetSaveControl((struct Big *)(*obj->ctx->save))), 0);
        MI_CpuFill8(&prof, 0, sizeof(prof));
        MI_CpuCopy8(REGULATION_Card_GetCupName((struct Reg2 *)card), &prof, 0x92);
        cardValA = REGULATION_Card_GetValue((struct Reg2 *)card, 6);
        cardValB = REGULATION_Card_GetValue((struct Reg2 *)card, 5);
        cardValC = REGULATION_Card_GetValue((struct Reg2 *)card, 4);
        prof.date1 = (cardValC << 24) | ((cardValB << 24) >> 8) | ((cardValA << 24) >> 16);
        cardValA = REGULATION_Card_GetValue((struct Reg2 *)card, 9);
        cardValB = REGULATION_Card_GetValue((struct Reg2 *)card, 8);
        cardValC = REGULATION_Card_GetValue((struct Reg2 *)card, 7);
        prof.date2 = (cardValC << 24) | ((cardValB << 24) >> 8) | ((cardValA << 24) >> 16);
        prof.statusFlag = MYSTATUS_GetTrainerView((const struct Sub0200852CObj *)sys);
        prof.hA0 = BSUBWAY_SAVEDATA_GetStat(obj->ctx->bsubwaySave, 10, 0);
        cardValA = BSUBWAY_SAVEDATA_GetStat(obj->ctx->bsubwaySave, 10, 1);
        prof.uA4 = cardValA + BSUBWAY_SAVEDATA_GetStat(obj->ctx->bsubwaySave, 10, 2);
        prof.hAA = REGULATION_Card_GetValue((struct Reg2 *)card, 11);
        if (prof.uA4 == 0 && prof.hA0 == 0)
            prof.hA0 = 1500;
        obj->tradeIcon = (u32)WIFIBATTLEMATCH_VIEW_CreateStatusWindow((char *)(&prof), 0, (void *)sys, (void *)id, (void *)obj->anim, obj->font, (void *)obj->printQue, (void *)obj->msgBank, (void *)obj->wordSet, (void *)kind, 0, 0x57);
    }
}

/*
 * Release path for the +0x1c block pointer, freed through 0x021E5EF8
 *     and cleared; a second call is a no-op.  The callee address is shared by
 *     two overlays, so the symbols: line names the ov177 function that the
 *     image's call to it there fixes.
 */
void WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(char *obj)
{
    u32 tradeIcon = ((struct WifiBattleMatchComp *)obj)->tradeIcon;

    if (tradeIcon != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteStatusWindow((void *)tradeIcon);
        ((struct WifiBattleMatchComp *)obj)->tradeIcon = 0;
    }
}

u32 WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindow(((struct WifiBattleMatchComp *)obj)->tradeIcon);
}

/*
 * Thunk: hands the +0x1c block to 0x021E65FC (ov177) and returns its result.
 */
int WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(((struct WifiBattleMatchComp *)obj)->tradeIcon);
}

/*
 * Start-op for the ov175 object's +0x1c stream: WIFIBATTLEMATCH_NET_SetupCompStatusWindow, then spin
 *     on WIFIBATTLEMATCH_NET_IsCompStatusWindowReady until it reports ready.  Mirrors WIFIBATTLEMATCH_NET_SetupBoxAndWait.
 */
void WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(char *obj)
{
    WIFIBATTLEMATCH_NET_SetupCompStatusWindow((struct WifiBattleMatchComp *)obj);
    while (WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(obj) == 0)
        ;
}

/*
 * If the +0x1c block is live, forward it to 0x021E5F24 together with the
 *     function's own second argument, the +0x14 and +0x10 words and the +8
 *     word, plus the literal 0x57.  Six arguments, so the last two ride on the
 *     stack; the two-word frame exists only for them.
 */
void WIFIBATTLEMATCH_NET_DrawCompStatusWindow(char *obj, u32 arg)
{
    if (((struct WifiBattleMatchComp *)obj)->tradeIcon != 0)
        WIFIBATTLEMATCH_VIEW_DrawStatusWindow(((struct WifiBattleMatchComp *)obj)->tradeIcon, arg, ((struct WifiBattleMatchComp *)obj)->msgBank,
                      ((struct WifiBattleMatchComp *)obj)->printQue, ((struct WifiBattleMatchComp *)obj)->font, 0x57);
}

/*
 * Lazy create: when the handle at +0x20 is empty, builds it through the eleven-argument ov177 constructor from the +0x0/+0x4/+0x8/+0x10/+0x14/+0x18 words and the heap id at +0x108.
 */
void WIFIBATTLEMATCH_NET_StartRegCardAnim(u32 *obj, u32 arg)
{
    if (obj[8] == 0) {
        u32 base = WIFIBATTLEMATCH_GRAPHIC_GetCamera((int *)obj[0]);
        obj[8] = WIFIBATTLEMATCH_VIEW_CreateRecordWindow(arg, base, obj[1], obj[2], obj[4], obj[5], obj[6], 0, 1,
                               REGULATION_Card_GetValue((struct Reg2 *)obj[0x42], 0xb), 0x57);
    }
}

/*
 * Release path for the ov175 object's 0x20 pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void WIFIBATTLEMATCH_NET_DeleteCompRegCard(char *obj)
{
    u32 regCard = ((struct WifiBattleMatchComp *)obj)->regCard;

    if (regCard != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(regCard);
        ((struct WifiBattleMatchComp *)obj)->regCard = 0;
    }
}

/*
 * Thunk: hands the +0x20 block to 0x021E777C (ov177) and returns its result.
 */
u32 WIFIBATTLEMATCH_NET_IsCompRegCardReady(char *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepRecordWindow((void *)(((struct WifiBattleMatchComp *)obj)->regCard));
}

/*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 */
void WIFIBATTLEMATCH_NET_SetupCompPartyWindow(char *ctx)
{
    int window;
    if (((struct WifiBattleMatchComp *)ctx)->window == 0) {
        window = WIFIBATTLEMATCH_GRAPHIC_GetCamera(*(int * *)&((struct WifiBattleMatchComp *)ctx)->sprite);
        ((struct WifiBattleMatchComp *)ctx)->window = WIFIBATTLEMATCH_VIEW_CreatePartyWindow(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)ctx)->ctx))->save)), window, *(int *)&((struct WifiBattleMatchComp *)ctx)->anim, ((struct WifiBattleMatchComp *)ctx)->fontAlt, *(int *)&((struct WifiBattleMatchComp *)ctx)->printQue, *(int *)&((struct WifiBattleMatchComp *)ctx)->msgBank, 87);
    }
}

/*
 * Free-and-null on the +0x24 block: hands it to 0x021E82BC (ov177) and
 *  *  clears the field, so a second call is harmless.
 */
void WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(char *obj)
{
    u32 window = (u32)((struct WifiBattleMatchComp *)obj)->window;
    if (window != 0) {
        WIFIBATTLEMATCH_VIEW_DeletePartyWindow((char *)window);
        ((struct WifiBattleMatchComp *)obj)->window = 0;
    }
}

int WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(char *comp)
{
    return WIFIBATTLEMATCH_VIEW_StepPartyWindow(*(Work * *)&((struct WifiBattleMatchComp *)comp)->window);
}

int WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(char *comp)
{
    return WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(*(Work * *)&((struct WifiBattleMatchComp *)comp)->window);
}

void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(u32 *comp, int mode) {
    WifibattlematchMenuDesc d;
    if (comp[12] == 0) {
        MI_CpuFill8(&d, 0, 48);
        d.msgBank=comp[5]; d.font=comp[2]; d.printQue=comp[4];
        d.a=0; d.b=15; d.c=13; d.d=1;
        switch (mode) {
        case 5: d.row=1;
        case 0:
            d.items[0]=52; d.items[1]=53; d.count=2; d.enabled=1; d.kind=1;
            comp[12]=WIFIBATTLEMATCH_UTIL_ShowMenu(&d,87); break;
        case 1:
            d.items[0]=47; d.items[1]=48; d.items[2]=49; d.count=3; d.enabled=1; d.kind=2;
            comp[12]=WIFIBATTLEMATCH_UTIL_ShowMenu(&d,87); break;
        case 2:
            d.items[0]=66; d.items[1]=67; d.count=2; d.enabled=1; d.kind=1;
            comp[12]=WIFIBATTLEMATCH_UTIL_ShowMenu(&d,87); break;
        case 3:
            d.items[0]=75; d.items[1]=76; d.items[2]=77; d.count=3; d.enabled=1; d.kind=2;
            comp[12]=WIFIBATTLEMATCH_UTIL_CreateMenu(&d,3,6,26,6,87); break;
        case 4:
            d.items[0]=93; d.items[1]=94; d.items[2]=95; d.count=3; d.enabled=1; d.kind=2;
            comp[12]=WIFIBATTLEMATCH_UTIL_CreateMenu(&d,3,6,26,6,87); break;
        }
    }
}

void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(char *obj)
{
    u32 compSprite = ((struct WifiBattleMatchComp *)obj)->compSprite;

    if (compSprite != 0) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu(compSprite);
        ((struct WifiBattleMatchComp *)obj)->compSprite = 0;
    }
}

/*
 * Field query: if the +0x30 pointer is live, hand it to the ov175-adjacent
 *     routine at 0x021E8A00 and return its result, else -1.  WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu is
 *     the matching free path for the same field.
 */
int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(char *obj)
{
    u32 compSprite = ((struct WifiBattleMatchComp *)obj)->compSprite;

    if (compSprite != 0)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu(compSprite);
    return -1;
}

void WIFIBATTLEMATCH_NET_SetCompWaitCallback(char *obj, void *fn)
{
    WIFIBATTLEMATCH_UTIL_SetCallback((int *)(((struct WifiBattleMatchComp *)obj)->waitStream), (int)fn);
    ((struct WifiBattleMatchComp *)obj)->waitResult = 0xFFFF;
}

/*
 * Reads back the +0x3c stream: 0x021E8A80 for pending data, 0x021E8A90
 *     for a byte read, returning the +0x40 word or the 0xFFFF sentinel.
 *     Mirrors WIFIBATTLEMATCH_NET_PollWaitResult.
 */
u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(char *obj)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(((struct WifiBattleMatchComp *)obj)->waitStream);
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull((int **)(((struct WifiBattleMatchComp *)obj)->waitStream)) != 0)
        return ((struct WifiBattleMatchComp *)obj)->waitResult;
    return 0xFFFF;
}

/*
 * NOT byte-correct: MATCH.  Every byte
 * matches and the only unmatched site is a
 * relocation with no witness.
 *
 * Blocking site: 0x021E8A90
 * Identical blocker to WIFIBATTLEMATCH_NET_PollWaitResult: the call at +0x0C targets 0x021E8A90,
 * which is not a traced function label in any overlay listing.
 */

void WIFIBATTLEMATCH_NET_CopyCompBox(char *dest, char *ctx)
{
    void *records;
    MI_CpuFill8(dest, 0, 212);
    records = BATTLE_BOX_CreateParty((int)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(**(void ** *)&((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)ctx)->ctx))->save)), 87);
    MI_CpuCopy8(records, dest + 212, POKE_REGULATION_GetDataSize(POKEPARTY_Init(dest + 212)));
    GFL_HEAP_Free(records);
    ((struct WifiBattleMatchStatRecord *)dest)->boxValue = 100;
}

/*
 * Fills a profile record from the save data reached through +0x104: name, a 0x38 record, three words of the +0x34 block, the +0x34 id, a derived word and two values of the +0x108 block.
 *
 *     (MI_CpuCopy8 with size 0x20) with no witness. Seed and match it and this
 *     file is EXACT.
 */
void WIFIBATTLEMATCH_NET_CopyCompSave(char *dst, char *obj)
{
    u32 saveCtrl = (u32)GAME_DATA_GetSaveControl((struct Big *)(*(*(struct WifiBattleMatchParams * *)&((struct WifiBattleMatchComp *)obj)->ctx)->save));
    u32 card;

    MYSTATUS_Copy(GAME_DATA_GetMyStatus((void *)(*(*(struct WifiBattleMatchParams * *)&((struct WifiBattleMatchComp *)obj)->ctx)->save)), dst);
    GREETING_SAVEDATA_GetSentence(GREETING_SAVEDATA_GetFromSaveThunk(saveCtrl), 0, (struct Rec0200E6FC *)(dst + 0x38));
    {
        const struct WifiBattleMatchParams *s = *(struct WifiBattleMatchParams * *)&((struct WifiBattleMatchComp *)obj)->ctx;
        ((struct WifiBattleMatchStatRecord *)dst)->keyDBase = s->sub->keyDBase;
        ((struct WifiBattleMatchStatRecord *)dst)->keyDDelta = s->sub->keyDDelta;
        ((struct WifiBattleMatchStatRecord *)dst)->keyA = s->sub->keyA;
    }
    ((struct WifiBattleMatchStatRecord *)dst)->netId = WIFIBATTLEMATCH_NET_GetNetId((char *)(*(u32 *)&((struct WifiBattleMatchComp *)obj)->net));
    ((struct WifiBattleMatchStatRecord *)dst)->gsProfileId = WIFILIST_GetGsProfileId((void *)GAME_DATA_GetWifiList((const struct BigObj *)(*(*(struct WifiBattleMatchParams * *)&((struct WifiBattleMatchComp *)obj)->ctx)->save)));
    card = ((struct WifiBattleMatchComp *)obj)->card;
    ((struct WifiBattleMatchStatRecord *)dst)->cardValue = REGULATION_Card_GetValue((struct Reg2 *)card, 2);
    ((struct WifiBattleMatchStatRecord *)dst)->crc = REGULATION_Card_CalcCrc((struct Reg2 *)card);
}

/*
 * leaf: copy128 bytes from response+0x1c to save+0x54.
 */
void WIFIBATTLEMATCH_NET_CopyCompResponse(char *save, char *response)
{
    MI_CpuCopy8(response + 0x1c, save + 0x54, 128);
}

u32 WIFIBATTLEMATCH_NET_VerifyCompSignature(char *obj, void *list, u32 heapId)
{
    int heap = (heapId & 0x7fff) | 0x8000;
    u32 size = POKE_TOOL_GetPartyParamSize();
    void *buf = NHTTP_RAP_EvilCheckAllocArray(size, POKEPARTY_GetCount(list), (u16)heap);
    int i;
    u32 ret;

    for (i = 0; i < (int)POKEPARTY_GetCount(list); i++) {
        void *entry = POKEPARTY_GetMember(list, i);
        NHTTP_RAP_EvilCheckSetElement((int)buf, (int)entry, POKE_TOOL_GetPartyParamSize(), i);
    }
    size = POKE_TOOL_GetPartyParamSize();
    ret = NHTTP_RAP_VerifySignature(buf, size, POKEPARTY_GetCount(list), obj + 0x54, (u16)heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}

int WIFIBATTLEMATCH_NET_CompareParty(u32 a, u32 b)
{
    u32 count = POKEPARTY_GetCount((void *)a);
    u32 i;

    if (count == POKEPARTY_GetCount((void *)b)) {
        for (i = 0; i < count; i++) {
            u32 ea = (u32)POKEPARTY_GetMember((void *)a, i);
            u32 eb = (u32)POKEPARTY_GetMember((void *)b, i);
            u8 *pa = POKE_TOOL_CastToBoxParam(ea);
            u8 *pb = POKE_TOOL_CastToBoxParam(eb);
            if (GF_STANDARD_CompareBytes(pa, pb, POKE_TOOL_GetBoxParamSize()) != 0)
                return 0;
        }
        return 1;
    }
    return 0;
}

/*
 * Quit-confirmation dialog step (state at +0xec): waits for the trigger and the button, prints the question, waits for the message, opens the yes/no window, then on yes prints the goodbye and closes the connection (returns 3 when finished), on no returns 2; returns 1 while the dialog is active and 0 when idle.
 *
 * Closed: the final state test is a switch, which keeps the `return 0` arm as the
 *     fall-through where every if/else spelling inverts it (EXACT* once the
 *     ov177 getter 0x021E8844 got its label).
 */
int WIFIBATTLEMATCH_NET_CompHandleCancel(char *obj, int trigger, int go)
{
    int result;

    switch (((struct WifiBattleMatchComp *)obj)->stepCounter) {
    case 0:
        if (trigger == 0)
            break;
        if (!(KEY_GetTrg() & 2))
            break;
        ((struct WifiBattleMatchComp *)obj)->stepCounter = ((struct WifiBattleMatchComp *)obj)->stepCounter + 1;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)obj)->textObj), ((struct WifiBattleMatchComp *)obj)->msgBank, 0x23, 1);
        ((struct WifiBattleMatchComp *)obj)->stepCounter = ((struct WifiBattleMatchComp *)obj)->stepCounter + 1;
        break;
    case 2:
        if (!WIFIBATTLEMATCH_UTIL_GetBusy((const int *)(((struct WifiBattleMatchComp *)obj)->textObj)))
            break;
        ((struct WifiBattleMatchComp *)obj)->stepCounter = ((struct WifiBattleMatchComp *)obj)->stepCounter + 1;
        break;
    case 3:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu((u32 *)((u32 *)obj), 0);
        ((struct WifiBattleMatchComp *)obj)->stepCounter = ((struct WifiBattleMatchComp *)obj)->stepCounter + 1;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_PollCompChoiceMenu(obj);
        if (result == -1)
            break;
        WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(obj);
        switch (result) {
        case 0:
            ((struct WifiBattleMatchComp *)obj)->stepCounter = 5;
            break;
        case 1:
            WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)obj)->textObj), ((struct WifiBattleMatchComp *)obj)->msgBank, 0x21, 0);
            ((struct WifiBattleMatchComp *)obj)->stepCounter = 0;
            return 2;
        }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage((int *)(((struct WifiBattleMatchComp *)obj)->textObj), ((struct WifiBattleMatchComp *)obj)->msgBank, 0x2b, 2);
        ((struct WifiBattleMatchComp *)obj)->stepCounter = ((struct WifiBattleMatchComp *)obj)->stepCounter + 1;
        break;
    case 6:
        if (go == 0)
            break;
        WIFIBATTLEMATCH_NET_SendSessionQuery(((struct WifiBattleMatchComp *)obj)->net);
        ((struct WifiBattleMatchComp *)obj)->stepCounter = ((struct WifiBattleMatchComp *)obj)->stepCounter + 1;
        WIFIBATTLEMATCH_VIEW_SetActorVisible((void **)(((struct WifiBattleMatchComp *)obj)->animMgr), 0);
        WIFIBATTLEMATCH_NET_DisconnectWifi(((struct WifiBattleMatchComp *)obj)->net);
        if (!GFL_NET_ERR_GetErrorLevel() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        ((struct WifiBattleMatchComp *)obj)->stepCounter = 0;
        return 3;
    }
    switch (((struct WifiBattleMatchComp *)obj)->stepCounter) {
    case 0:
        return 0;
    default:
        return 1;
    }
}

/*
 * Clears the +0xec last-read length and tail-calls the +0x30 release path
 *     WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu, so nothing is saved.  Mirrors WIFIBATTLEMATCH_NET_ClearError.
 */
void WIFIBATTLEMATCH_NET_CompClearError(char *obj)
{
    ((struct WifiBattleMatchComp *)obj)->stepCounter = 0;
    WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(obj);
}

/*
 * Syncs three words of a record (+0x10, +0x8, +0xc) into slots 0..2 of table 10 of the save block at +0x104; returns 1 when any of them differed from what was stored.
 *
 * Both callees 0x0200DFD8 and 0x0200DFE4 resolve since seeds_2 labelled and
 *     matched them (src/matched/unit_0200DFD8.c).
 */
int WIFIBATTLEMATCH_NET_GetSetCompStat(char *obj, u32 *rec)
{
    int changed = 0;

    if (rec[4] != BSUBWAY_SAVEDATA_GetStat(((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)obj)->ctx))->bsubwaySave, 10, 0)
        || rec[2] != BSUBWAY_SAVEDATA_GetStat(((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)obj)->ctx))->bsubwaySave, 10, 1)
        || rec[3] != BSUBWAY_SAVEDATA_GetStat(((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)obj)->ctx))->bsubwaySave, 10, 2))
        changed = 1;
    BSUBWAY_SAVEDATA_SetStat(((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)obj)->ctx))->bsubwaySave, 10, 0, rec[4]);
    BSUBWAY_SAVEDATA_SetStat(((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)obj)->ctx))->bsubwaySave, 10, 1, rec[2]);
    BSUBWAY_SAVEDATA_SetStat(((struct WifiBattleMatchParams *)(*(char * *)&((struct WifiBattleMatchComp *)obj)->ctx))->bsubwaySave, 10, 2, rec[3]);
    return changed;
}

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
char *WIFIBATTLEMATCH_NET_CreateNetContext(u32 netId, void *save, u32 heapId, u16 heap) {
    char *ctx;
    u32 wifiList;
    ctx = GFL_HEAP_Alloc(heap, 0x149c, 0, d_021E2EE0, 0x2b0);
    MI_CpuFill8(ctx, 0, 0x149c);
    wifiList = GAME_DATA_GetWifiList(save);
    *(u32 *)(ctx + 4) = wifiList;
    *(u32 *)ctx = WIFILIST_GetWork(wifiList);
    *(void **)(ctx + 0xc) = (void *)MYSTATUS_GetProfileId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(save));
    *(void **)(ctx + 8) = save;
    *(u32 *)(ctx + 0x10) = heapId;
    *(u32 *)(ctx + 0x1464) = netId;
    *(int *)(ctx + 0x19c) = 0x573;
    *(char **)(ctx + 0x190) = GFL_HEAP_Alloc(heap, 0x260, 0, d_021E2EE0, 0x2c0);
    MI_CpuFill8(*(void **)(ctx + 0x190), 0, 0x260);
    if (!GFL_NET_GetRunState()) GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
    GFL_NET_COMMAND_AddCommandTable(0x2400, (u32)d_021E2C90, 6, (u32)ctx);
    GFL_NET_SetWaitMode(0);
    DWC_RAP_SetErrorCallback((int)WIFIBATTLEMATCH_NET_CleanupDownload, (int)ctx);
    DWC_RAP_SetErrorHookCallback((int)WIFIBATTLEMATCH_NET_GetDownloadSize, (int)ctx);
    return ctx;
}

void WIFIBATTLEMATCH_NET_DeleteNetContext(u8 *ctx) { DWC_RAP_SetErrorHookCallback(0,0); DWC_RAP_SetErrorCallback(0,0); GFL_NET_COMMAND_DeleteCommandTable(0x2400); GFL_HEAP_Free(((struct WifiBattleMatchNetCtx *)ctx)->recBuf); GFL_HEAP_Free(ctx); }

/*
 * Empty stub sitting between the WIFIBATTLEMATCH_NET_DeleteNetContext teardown and
 *     WIFIBATTLEMATCH_NET_SetTimingSyncRange; nothing calls into it, disasm.py labelled it from its
 *     alignment padding.
 */
void WIFIBATTLEMATCH_NET_Noop(int unused)
{
}

/*
 * Stores the caller's word at +0x14 and forwards its low byte to
 *     0x02039C68 with the tick/state from 0x020399A8 and line 0x24.  The byte
 *     is re-read from the field after the first call, which is why the listing
 *     reloads +0x14.  WIFIBATTLEMATCH_NET_IsTimingSyncRange is the same shape for the flush path.
 */
void WIFIBATTLEMATCH_NET_SetTimingSyncRange(char *obj, u32 v)
{
    ((struct WifiBattleMatchNetCtx *)obj)->syncRange = v;
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)((struct WifiBattleMatchNetCtx *)obj)->syncRange, 0x24);
}

/*
 * Flush partner of WIFIBATTLEMATCH_NET_SetTimingSyncRange: sends the byte the object kept at
 *     +0x14 to 0x02039CB4 with the tick/state and line 0x24.
 */
int WIFIBATTLEMATCH_NET_IsTimingSyncRange(char *obj)
{
    return GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), (unsigned char)((struct WifiBattleMatchNetCtx *)obj)->syncRange, 0x24);
}

/*
 * Error poll: while the link is up, classifies the transport error through 0x02157170 (0..4); otherwise classifies the stored error record by its kind, and on a nonzero class shuts the screens down, runs the class action (1 reset, 2 fatal screen, 3 retry) and clears the record.
 */
int WIFIBATTLEMATCH_NET_HandleNetError(char *ctx, void *a, void *b)
{
    u32 *rec = (u32 *)(ctx + 0x18);
    Res r = RES_NONE;

    if (GFL_NET_GetRunState()) {
        if (GFL_NET_ERR_GetErrorLevel()) {
            GFL_NET_SetAutoExit(r);
            GFL_NET_SetLoginOption(r);
            GFL_USE_StopAllSe();
            if (GAME_DATA_IsSaving((const u8 *)(((struct WifiBattleMatchNetCtx *)ctx)->save))) {
                GAME_DATA_SaveCancel((char *)(((struct WifiBattleMatchNetCtx *)ctx)->save));
                GFL_NET_ERR_HaltWithMessage(0x29);
            }
        }
        switch (DWC_RAPCOMMON_HandleNetError(a, b)) {
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
            GFL_USE_StopAllSe();
            if (GAME_DATA_IsSaving((const u8 *)(((struct WifiBattleMatchNetCtx *)ctx)->save))) {
                GAME_DATA_SaveCancel((char *)(((struct WifiBattleMatchNetCtx *)ctx)->save));
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

void WIFIBATTLEMATCH_NET_ClearErrorFlags(u8 *ctx) { ((struct WifiBattleMatchNetCtx *)ctx)->state=0; ((struct WifiBattleMatchNetCtx *)ctx)->gdbState=0; }

int WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(char *ctx)
{
    int result;
    switch (((struct WifiBattleMatchNetCtx *)ctx)->gdbState) {
    case 0:
        WIFIBATTLEMATCH_NET_GdbRequest(ctx, -1, 2, *(unsigned int *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr);
        ((struct WifiBattleMatchNetCtx *)ctx)->gdbState = 1;
        break;
    case 1:
        result = WIFIBATTLEMATCH_NET_GdbGetMyRecords(ctx);
        if (result == 1) {
            if (**(int * *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr != 0) ((struct WifiBattleMatchNetCtx *)ctx)->gdbState = 4;
            else ((struct WifiBattleMatchNetCtx *)ctx)->gdbState = 2;
        } else if (result == 2) return 2;
        break;
    case 2:
        WIFIBATTLEMATCH_NET_GdbClearRecord(ctx);
        ((struct WifiBattleMatchNetCtx *)ctx)->gdbState = 3;
        break;
    case 3:
        result = WIFIBATTLEMATCH_NET_GdbCreateRecord(ctx);
        if (result == 1) ((struct WifiBattleMatchNetCtx *)ctx)->gdbState = 4;
        else if (result == 2) return 2;
        break;
    case 4: return 1;
    }
    return 0;
}

/*
 * Sets up a matchmaking attempt: closes any connection, publishes the eight match keys (player count, group, 1, four record words, version 0x20015), formats the filter string and picks the evaluation callback for the mode (1 asserts).
 */
void WIFIBATTLEMATCH_NET_SetMatchKey(char *obj, int mode, int extra, int group, int *rec)
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
    WIFIBATTLEMATCH_NET_AddMatchKey(obj, 7, 0x20000 | PM_VERSION_ID);
    STD_TSPrintf(obj + 0x44, d_021E2EFC, count, group, 1);
    ((struct WifiBattleMatchNetCtx *)obj)->mmState = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->pollCount = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->retryCount = 0;
    MI_CpuFill8(obj + 0x138, 0, 0x18);
    switch (mode) {
    case 0:
        *(EvalFn *)&((struct WifiBattleMatchNetCtx *)obj)->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyValue;
        break;
    case 1:
        GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
        break;
    case 2:
        *(EvalFn *)&((struct WifiBattleMatchNetCtx *)obj)->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyInt;
        break;
    case 3:
        *(EvalFn *)&((struct WifiBattleMatchNetCtx *)obj)->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyDefault;
        break;
    default:
        GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
        break;
    }
}

/*
 * Matchmaking step (state at +0x40): 0 starts the search with the evaluation callback, then waits for the match, the peer handshake (with a 3600-tick timeout counted at +0x1a4) and the link check; returns 1 when done, 2 on a fatal error and 0 while still running.
 */
int WIFIBATTLEMATCH_NET_StartMatchmaking(char *obj)
{
    switch (((struct WifiBattleMatchNetCtx *)obj)->mmState) {
    case 0:
        if (DWC_RAP_StartMatchWithFilter(obj + 0x44, 2, ((struct WifiBattleMatchNetCtx *)obj)->evalFn, obj)) {
            GFL_NET_STATE_WifiEnterRandomMatch();
            DWC_RAP_SetVchatEnabled(0);
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 1;
        } else {
            GFL_NET_STATE_WifiDisconnect(1);
            return 2;
        }
        break;
    case 1:
        ((struct WifiBattleMatchNetCtx *)obj)->mmState = 2;
        break;
    case 2:
        switch (GFL_NET_STATE_GetWifiState()) {
        case 0:
            if ((u32)(*(u32 *)(GFL_NET_STATE_GetError() + 0xc) - 0x3f0) > 1)
                break;
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 7;
            break;
        case 1:
            ((struct WifiBattleMatchNetCtx *)obj)->retryCount = 0;
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 3;
            GFL_NET_SetAutoExit(1);
            GFL_NET_SetLoginOption(1);
            break;
        default:
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 7;
            break;
        }
        break;
    case 3:
        if (GFL_NET_SYSTEM_GetCurrentAid()) {
            if (GFL_NET_HANDLE_CheckNegotiation())
                ((struct WifiBattleMatchNetCtx *)obj)->mmState = 4;
            if ((((struct WifiBattleMatchNetCtx *)obj)->retryCount)++ > 0xe10) {
                WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
                ((struct WifiBattleMatchNetCtx *)obj)->mmState = 7;
            }
        } else {
            ((struct WifiBattleMatchNetCtx *)obj)->retryCount = 0;
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 5;
        }
        break;
    case 4:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24);
        ((struct WifiBattleMatchNetCtx *)obj)->retryCount = 0;
        ((struct WifiBattleMatchNetCtx *)obj)->mmState = 6;
        break;
    case 5:
        if ((((struct WifiBattleMatchNetCtx *)obj)->retryCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 7;
        } else if (GFL_NET_HANDLE_GetNegotiationNum() && GFL_NET_HANDLE_CheckNegotiation()) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24);
            ((struct WifiBattleMatchNetCtx *)obj)->retryCount = 0;
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 6;
        }
        break;
    case 6:
        if ((((struct WifiBattleMatchNetCtx *)obj)->retryCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_ClearCancelFlag(obj);
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 7;
        } else if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0xf, 0x24)) {
            ((struct WifiBattleMatchNetCtx *)obj)->mmState = 8;
        }
        break;
    case 7:
        if (WIFIBATTLEMATCH_NET_StopMatchmaking(obj)) {
            if ((u32)(*(u32 *)(GFL_NET_STATE_GetError() + 0xc) - 0x3f0) <= 1) {
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
void WIFIBATTLEMATCH_NET_ClearCancelFlag(char *obj)
{
    ((struct WifiBattleMatchNetCtx *)obj)->shutdownState = 0;
}

/*
 * Link shutdown sequence stepped by the word at +0x154: sync 0x18, wait for the sync (600 frame timeout on +0x1a0), stop the two link services, wait 30 frames on +0x134, restart the parent service, then report done (1).
 */
int WIFIBATTLEMATCH_NET_StopMatchmaking(char *obj)
{
    switch (((struct WifiBattleMatchNetCtx *)obj)->shutdownState) {
    case 0:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(obj, 0x18);
        ((struct WifiBattleMatchNetCtx *)obj)->pollCount = 0;
        (((struct WifiBattleMatchNetCtx *)obj)->shutdownState)++;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(obj) != 0)
            (((struct WifiBattleMatchNetCtx *)obj)->shutdownState)++;
        else if ((((struct WifiBattleMatchNetCtx *)obj)->pollCount)++ > 600)
            (((struct WifiBattleMatchNetCtx *)obj)->shutdownState)++;
        break;
    case 2:
        GFL_NET_SetAutoExit(0);
        GFL_NET_SetLoginOption(0);
        ((struct WifiBattleMatchNetCtx *)obj)->pendingCount = 0;
        (((struct WifiBattleMatchNetCtx *)obj)->shutdownState)++;
        break;
    case 3:
        if ((((struct WifiBattleMatchNetCtx *)obj)->pendingCount)++ > 30)
            (((struct WifiBattleMatchNetCtx *)obj)->shutdownState)++;
        break;
    case 4:
        GFL_NET_STATE_WifiDisconnect(1);
        (((struct WifiBattleMatchNetCtx *)obj)->shutdownState)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}

int WIFIBATTLEMATCH_NET_SendSessionQuery()
{
    if (DWC_RAP_IsStateInSession() != 0)
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2402, 4, (u32)g_021E2C8C);
    return 1;
}

u32 WIFIBATTLEMATCH_NET_TakeSessionResult(char *obj)
{
    u32 sessionResult = ((struct WifiBattleMatchNetCtx *)obj)->sessionResult;

    if (sessionResult != 0)
        ((struct WifiBattleMatchNetCtx *)obj)->sessionResult = 0;
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
void WIFIBATTLEMATCH_NET_AddMatchKey(char *obj, int i, int value)
{
    struct MatchKey *matchKey = (struct MatchKey *)(obj + 0xc4) + i;

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
    char *ctx = param;
    int valueB, valueA, valueC, valueD;
    int quota1, quota2, diffA, diffQuota, score;

    valueA = DWC_GetMatchIntValue(index, ctx + 0xee, -1);
    valueB = DWC_GetMatchIntValue(index, ctx + 0x106, -1);
    valueC = DWC_GetMatchIntValue(index, ctx + 0x112, -1);
    valueD = DWC_GetMatchIntValue(index, ctx + 0xfa, -1);

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
void WIFIBATTLEMATCH_NET_SetupMatchReport(char *obj, int mode, int kind, u32 teamArg, u32 *rec, u32 slot)
{
    ((struct WifiBattleMatchNetCtx *)obj)->reportFlag = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->state = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->reportCount = 1;
    ((struct WifiBattleMatchNetCtx *)obj)->regValueReady = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->recvPlayerData = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->reportKind = mode;
    ((struct WifiBattleMatchNetCtx *)obj)->reportSlot = slot;
    ((struct WifiBattleMatchNetCtx *)obj)->reportFieldA = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->reportFieldB = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->reportFieldC = 0;
    if (mode == 0) {
        switch (kind) {
        case 0:
            *(ReportFn *)&((struct WifiBattleMatchNetCtx *)obj)->reportFn = WIFIBATTLEMATCH_NET_ReportAddLoss;
            break;
        case 2:
            *(ReportFn *)&((struct WifiBattleMatchNetCtx *)obj)->reportFn = WIFIBATTLEMATCH_NET_ReportAddWin;
            break;
        default:
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    } else if (mode == 1) {
        if (slot != 0) {
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct WifiBattleMatchNetCtx *)obj)->reportFn = WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss;
                break;
            case 2:
                *(ReportFn *)&((struct WifiBattleMatchNetCtx *)obj)->reportFn = WIFIBATTLEMATCH_NET_ReportAddDisconnectWin;
                break;
            default:
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        } else {
            GFL_NET_IsParentAid();
            ((struct WifiBattleMatchNetCtx *)obj)->teamArg = teamArg;
            ((struct WifiBattleMatchNetCtx *)obj)->teamRec0 = rec[0];
            ((struct WifiBattleMatchNetCtx *)obj)->teamRec4 = rec[4];
            switch (kind) {
            case 0:
                *(ReportFn *)&((struct WifiBattleMatchNetCtx *)obj)->reportFn = (ReportFn)WIFIBATTLEMATCH_NET_ReportAddTeam;
                break;
            case 2:
                *(ReportFn *)&((struct WifiBattleMatchNetCtx *)obj)->reportFn = (ReportFn)WIFIBATTLEMATCH_NET_ReportAddRecord;
                break;
            default:
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
    }
}

int WIFIBATTLEMATCH_NET_ScProcess(char *ctx, u32 *out)
{
    Sys *s;
    int result;
    char *dst;
    void *src;

    if (out != 0)
        *out = *(u32 *)(ctx + 0x16c);
    s = (Sys *)GFL_NET_STATE_GetError();
    if (s->errorCode - 0x3f0 <= 1)
        *(u32 *)(ctx + 0x160) = 1;
    if (GFL_NET_ERR_GetErrorLevel() == 1) {
        if (s->errorKind == 6 || s->errorKind == 3) {
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
    } else if (*(u32 *)(ctx + 0x160) == 0 && GFL_NET_ERR_GetErrorLevel() == 2) {
        WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
        return 2;
    }
    if (*(u32 *)(ctx + 0x160) != 0 && *(u32 *)(ctx + 0x1ac) != 0 && *(u32 *)(ctx + 0x164) == 0
        && *(u32 *)(ctx + 0x12c) > 7 && *(u32 *)(ctx + 0x12c) < 10) {
        *(u32 *)(ctx + 0x168) = 0;
        *(u32 *)(ctx + 0x12c) = 6;
    }

    switch (*(u32 *)(ctx + 0x12c)) {
    case 0:
        if (*(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x12c) = 4;
            break;
        }
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x24);
        *(u32 *)(ctx + 0x12c) = 1;
        break;
    case 1:
        if (*(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x12c) = 4;
            break;
        }
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 4, 0x24) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 2;
        break;
    case 2:
        if (*(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x12c) = 4;
            break;
        }
        if (WIFIBATTLEMATCH_NET_SendRegValue((u32)ctx, ctx + 0x188) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 3;
        break;
    case 3:
        if (*(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x12c) = 4;
            break;
        }
        if (WIFIBATTLEMATCH_NET_TakeRegValue(ctx, (u32 *)(ctx + 0x18c)) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 4;
        break;
    case 4:
        *(u32 *)(ctx + 0x134) = 0;
        *(u32 *)(ctx + 0x170) = 1;
        result = DWC_ScInitialize(0xb5f, 0);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x751);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        *(u32 *)(ctx + 0x12c) = 5;
        break;
    case 5:
        result = DWC_ScGetLoginCertificate((void **)(*(char **)(ctx + 0x1464) + 4));
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x761);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        *(u32 *)(ctx + 0x12c) = 6;
        break;
    case 6:
        if (GFL_NET_IsParentAid() != 0 || *(u32 *)(ctx + 0x160) != 0) {
        (*(u32 *)(ctx + 0x134))++;
        result = DWC_ScCreateSessionAsync((u32)WIFIBATTLEMATCH_NET_OnReportResultA, 100, (u32)ctx);
        *(u32 *)(ctx + 0x164) = 1;
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x773);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        *(u32 *)(ctx + 0x1a0) = 0;
        *(u32 *)(ctx + 0x12c) = 7;
        } else
            *(u32 *)(ctx + 0x12c) = 8;
        break;
    case 7:
        if (*(u32 *)(ctx + 0x134) == 0) {
            dst = *(char **)(ctx + 0x1464) + 0xc;
            src = DWC_ScGetSessionId();
            MI_CpuCopy8(src, dst, 0x28);
            *(u32 *)(ctx + 0x12c) = 8;
            break;
        }
        if ((*(u32 *)(ctx + 0x1a0))++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(ctx + 0x18, 1, 0x78f);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (*(u32 *)(ctx + 0x15c) != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, *(u32 *)(ctx + 0x15c), 0x797);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        break;
    case 8:
        if (*(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x12c) = 0xb;
            break;
        }
        dst = *(char **)(ctx + 0x1464) + 0x34;
        src = DWC_ScGetConnectionId();
        MI_CpuCopy8(src, dst, 0x28);
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x24);
        *(u32 *)(ctx + 0x12c) = 9;
        break;
    case 9:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x24) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 0xa;
        break;
    case 10:
        if (GFL_NET_IsParentAid() != 0 || *(u32 *)(ctx + 0x160) != 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2400, 0x68, *(u32 *)(ctx + 0x1464) + 4) != 0 || *(u32 *)(ctx + 0x160) != 0)
                *(u32 *)(ctx + 0x12c) = 0xb;
        } else if (*(u32 *)(ctx + 0x138) != 0 || *(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x138) = 0;
            result = DWC_ScSetSessionId((u32)(*(char **)(ctx + 0x1464) + 0x74));
            dst = *(char **)(ctx + 0x1464) + 0xc;
            src = DWC_ScGetSessionId();
            MI_CpuCopy8(src, dst, 0x28);
            if (result != 0) {
                WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x7cd);
                WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
                return 2;
            }
            *(u32 *)(ctx + 0x12c) = 0xb;
        }
        break;
    case 11:
        (*(u32 *)(ctx + 0x134))++;
        result = DWC_ScSetReportIntentionAsync(*(u32 *)(ctx + 0x1a8), (u32)WIFIBATTLEMATCH_NET_OnReportResultB, 100, (u32)ctx);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x7dd);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        *(u32 *)(ctx + 0x1a0) = 0;
        *(u32 *)(ctx + 0x12c) = 0xc;
        break;
    case 12:
        if (*(u32 *)(ctx + 0x134) == 0) {
            *(u32 *)(ctx + 0x12c) = 0xd;
            break;
        }
        if ((*(u32 *)(ctx + 0x1a0))++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(ctx + 0x18, 1, 0x7f2);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (*(u32 *)(ctx + 0x15c) != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, *(u32 *)(ctx + 0x15c), 0x7fa);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        break;
    case 13:
        if (*(u32 *)(ctx + 0x160) != 0) {
            *(u32 *)(ctx + 0x12c) = 0x13;
            break;
        }
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x24);
        *(u32 *)(ctx + 0x12c) = 0xe;
        break;
    case 14:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 2, 0x24) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 0xf;
        break;
    case 15:
        if (GFL_NET_IsParentAid() != 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2400, 0x68, *(u32 *)(ctx + 0x1464) + 4) != 0 || *(u32 *)(ctx + 0x160) != 0)
                *(u32 *)(ctx + 0x12c) = 0x10;
        } else if (*(u32 *)(ctx + 0x138) != 0 || *(u32 *)(ctx + 0x160) != 0) {
            if (*(u32 *)(ctx + 0x160) == 0)
                *(u32 *)(ctx + 0x168) = 1;
            *(u32 *)(ctx + 0x138) = 0;
            *(u32 *)(ctx + 0x12c) = 0x10;
        }
        break;
    case 16:
        if (GFL_NET_IsParentAid() == 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2400, 0x68, *(u32 *)(ctx + 0x1464) + 4) != 0 || *(u32 *)(ctx + 0x160) != 0)
                *(u32 *)(ctx + 0x12c) = 0x11;
        } else if (*(u32 *)(ctx + 0x138) != 0 || *(u32 *)(ctx + 0x160) != 0) {
            if (*(u32 *)(ctx + 0x160) == 0)
                *(u32 *)(ctx + 0x168) = 1;
            *(u32 *)(ctx + 0x138) = 0;
            *(u32 *)(ctx + 0x12c) = 0x11;
        }
        break;
    case 17:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x24);
        *(u32 *)(ctx + 0x12c) = 0x12;
        break;
    case 18:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 3, 0x24) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 0x13;
        break;
    case 19:
        result = WIFIBATTLEMATCH_NET_SubmitReport(*(char **)(ctx + 0x1464) + 4, *(char **)(ctx + 0x1464) + 0x6c, ctx + 0x180, *(u32 *)(ctx + 0x1a8),
                          *(RoundFn *)(ctx + 0x158), *(u32 *)(ctx + 0x160), *(u32 *)(ctx + 0x1ac), *(u32 *)(ctx + 0x168));
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x86d);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        *(u32 *)(ctx + 0x12c) = 0x14;
        break;
    case 20:
        (*(u32 *)(ctx + 0x134))++;
        result = DWC_ScSubmitReportAsync(*(u32 *)(*(char **)(ctx + 0x1464) + 8), *(u32 *)(ctx + 0x1a8), (u32)WIFIBATTLEMATCH_NET_OnReportResultC, 100, ctx);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, result, 0x87c);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        *(u32 *)(ctx + 0x1a0) = 0;
        *(u32 *)(ctx + 0x12c) = 0x15;
        break;
    case 21:
        if (*(u32 *)(ctx + 0x134) == 0) {
            *(u32 *)(ctx + 0x12c) = 0x16;
            break;
        }
        if ((*(u32 *)(ctx + 0x1a0))++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(ctx + 0x18, 1, 0x890);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (*(u32 *)(ctx + 0x15c) != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(ctx + 0x18, *(u32 *)(ctx + 0x15c), 0x898);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        break;
    case 22:
        *(u32 *)(ctx + 0x16c) = 1;
        WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
        *(u32 *)(ctx + 0x12c) = 0x17;
        break;
    case 23:
        GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x24);
        *(u32 *)(ctx + 0x12c) = 0x18;
        break;
    case 24:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 5, 0x24) != 0 || *(u32 *)(ctx + 0x160) != 0)
            *(u32 *)(ctx + 0x12c) = 0x19;
        break;
    case 25:
        return 1;
    }
    return 0;
}

u32 WIFIBATTLEMATCH_NET_GetReportState(u8 *ctx) { return ((struct WifiBattleMatchNetCtx *)ctx)->regValue; }

/*
 * Competition-server completion callback: records a nonzero result at +0x15c and drops the pending-request count at +0x134 (unlabelled; its address is a code pointer in WIFIBATTLEMATCH_NET_ScProcess's pool).
 */
void WIFIBATTLEMATCH_NET_OnReportResultA(int result, char *obj)
{
    if (result != 0)
        ((struct WifiBattleMatchNetCtx *)obj)->reportResult = result;
    (((struct WifiBattleMatchNetCtx *)obj)->pendingCount)--;
}

/*
 * Report-intention completion callback: on success copies the 0x28-byte session id into the report block (+0x34 of the record at +0x1464), otherwise records the result at +0x15c; then drops the pending-request count at +0x134.
 */
void WIFIBATTLEMATCH_NET_OnReportResultB(int result, char *obj)
{
    char *player = *(char * *)&((struct WifiBattleMatchNetCtx *)obj)->netIdPtr + 4;

    if (result == 0)
        MI_CpuCopy8(DWC_ScGetConnectionId(), player + 0x30, 0x28);
    else
        ((struct WifiBattleMatchNetCtx *)obj)->reportResult = result;
    (((struct WifiBattleMatchNetCtx *)obj)->pendingCount)--;
}

void WIFIBATTLEMATCH_NET_OnReportResultC(int result, char *obj)
{
    if (result != 0)
        ((struct WifiBattleMatchNetCtx *)obj)->reportResult = result;
    (((struct WifiBattleMatchNetCtx *)obj)->pendingCount)--;
}

/*
 * Report teardown: when the state word at +0x170 is 1, destroys the report once the +0x12c step is past 0x13, shuts the storage client down once the +0x12c step is 4 or more, and clears the state word.
 */
void WIFIBATTLEMATCH_NET_ShutdownReport(char *obj)
{
    if (((struct WifiBattleMatchNetCtx *)obj)->reportState == 1) {
        if (((struct WifiBattleMatchNetCtx *)obj)->state > 0x13)
            DWC_ScDestroyReport(((struct WifiBattleMatchReportBlock *)(*(char * *)&((struct WifiBattleMatchNetCtx *)obj)->netIdPtr))->players[0].report);
        if (((struct WifiBattleMatchNetCtx *)obj)->state >= 4)
            DWC_ScShutdown();
        ((struct WifiBattleMatchNetCtx *)obj)->reportState = 0;
    }
}

/*
 * One exchange round: bails with the first nonzero status of the four session checks, sends the local record (mode from the peer kind), runs the callback, optionally sends the peer's record back and runs the callback again, then closes with the flag.
 */
int WIFIBATTLEMATCH_NET_SubmitReport(char *ctx, char *other, char *peer, u32 isAuthoritative, RoundFn cb, int flag, int have, int twoway)
{
    int result;
    int mode;
    int mode2;

    if ((result = DWC_ScCreateReport(1, 2, 0, (u32)(ctx + 4))) != 0)
        return result;
    if ((result = DWC_ScReportBeginGlobalData((u32 *)(((struct WifiBattleMatchReportPlayer *)ctx)->report))) != 0)
        return result;
    if ((result = DWC_ScReportBeginPlayerData((u32 *)(((struct WifiBattleMatchReportPlayer *)ctx)->report))) != 0)
        return result;
    if ((result = DWC_ScReportBeginNewPlayer((u8 *)(((struct WifiBattleMatchReportPlayer *)ctx)->report))) != 0)
        return result;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (((struct WifiBattleMatchTeam *)peer)->rec0) {
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
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    }
    if ((result = DWC_ScReportSetPlayerData(((struct WifiBattleMatchReportPlayer *)ctx)->report, 0, (s32)(ctx + 0x30), 0, mode, (char *)(((struct WifiBattleMatchReportPlayer *)ctx)->certificate), (s32)(ctx + 0x58))) != 0)
        return result;
    if ((result = cb(ctx, peer, 1, flag)) != 0)
        return result;
    if ((result = DWC_ScReportBeginNewPlayer((u8 *)(((struct WifiBattleMatchReportPlayer *)ctx)->report))) != 0)
        return result;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (((struct WifiBattleMatchTeam *)peer)->rec0) {
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
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
        if ((result = DWC_ScReportSetPlayerData(((struct WifiBattleMatchReportPlayer *)ctx)->report, 1, (s32)(other + 0x30), 0, mode2, (char *)(((struct WifiBattleMatchReportPlayer *)other)->certificate), (s32)(other + 0x58))) != 0)
            return result;
        if ((result = cb(ctx, peer, 0, flag)) != 0)
            return result;
    }
    if ((result = DWC_ScReportBeginTeamData((u32 *)(((struct WifiBattleMatchReportPlayer *)ctx)->report))) != 0)
        return result;
    if (flag != 0)
        return DWC_ScReportEnd(((struct WifiBattleMatchReportPlayer *)ctx)->report, isAuthoritative, 1);
    return DWC_ScReportEnd(((struct WifiBattleMatchReportPlayer *)ctx)->report, isAuthoritative, 0);
}

void WIFIBATTLEMATCH_NET_ReportAddRecord(int *ctx,const u32 *record,int invert) {
    int first,second,flip=0,skip=0,present;
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
        if(!skip && DWC_ScReportAddByteValue(ctx[1],15,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],5,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],6,second)) return;
        break;
    case 1:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],16,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],8,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],7,second)) return;
        break;
    case 2:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],18,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],11,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],12,second)) return;
        break;
    case 3:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],17,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],9,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],10,second)) return;
        break;
    case 4:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],19,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],13,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],14,second)) return;
        break;
    default: GF_PANIC_Fail(d_021E2EF8,0,d_021E2EF8); break;
    }
    if(DWC_ScReportAddIntValue(ctx[1],20,present!=0)) return;
    DWC_ScReportAddIntValue(ctx[1],27,-1);
}

/*
 * tail: 021DB216..021DB218 is two zero alignment bytes.
 */
void WIFIBATTLEMATCH_NET_ReportAddTeam(int *ctx, int *input, int invert)
{
    int flip = 0, skip = 0;
    int first, second;
    int present = 1;
    if (input[2] == 0 && input[3] == 0) present = 0;
    switch (input[1]) {
    case 0: case 3: first = 0; second = 1; flip = 1; break;
    case 1: case 4: first = 1; second = 0; flip = 1; break;
    case 2: first = 0; second = 0; skip = 1; break;
    case 5: case 6: default: first = 0; second = 0; break;
    }
    if (!invert && flip) { first ^= 1; second ^= 1; }
    if (!skip && DWC_ScReportAddByteValue(ctx[1], 0x15, 1)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x16, first)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x17, second)) return;
    if (DWC_ScReportAddIntValue(ctx[1], 0x18, present != 0)) return;
    DWC_ScReportAddIntValue(ctx[1], 0x1c, -1);
}

/*
 * Report callback: adds byte key 0x1a with value 1 to the report at +0x4.
 */
int WIFIBATTLEMATCH_NET_ReportAddWin(u32 *ctx)
{
    return DWC_ScReportAddIntValue(ctx[1], 0x1a, 1);
}

/*
 * Report callback: adds byte key 0x19 with value 1 to the report at +0x4.
 */
int WIFIBATTLEMATCH_NET_ReportAddLoss(u32 *ctx)
{
    return DWC_ScReportAddIntValue(ctx[1], 0x19, 1);
}

/*
 * Report callback: adds byte key 0x1b with value -1 to the report at +0x4.
 */
int WIFIBATTLEMATCH_NET_ReportAddDisconnectWin(u32 *ctx)
{
    return DWC_ScReportAddIntValue(ctx[1], 0x1b, -1);
}

int WIFIBATTLEMATCH_NET_ReportAddDisconnectLoss(u32 *ctx)
{
    return DWC_ScReportAddIntValue(ctx[1], 0x1c, -1);
}

void WIFIBATTLEMATCH_NET_OnRecvPlayerData(int index,int unused,const void *src,u8 *ctx,int owner) { if(owner==(int)GFL_NET_HANDLE_GetCurrentHandle() && index!=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) { MI_CpuCopy8(src,*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr+0x6c,0x68); ((struct WifiBattleMatchNetCtx *)ctx)->recvPlayerData=1; } }

void WIFIBATTLEMATCH_NET_OnRecvStatus(int index, int unused, void *dest, char *ctx, int owner)
{
    void *record;
    record = GAME_DATA_GetMyStatusPlayer(((struct WifiBattleMatchNetCtx *)ctx)->save, index);
    MI_CpuCopy8(dest, record, MYSTATUS_GetSize());
    if (owner == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (index != GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())))
            ((struct WifiBattleMatchNetCtx *)ctx)->regDataReady = 1;
    }
}

/*
 * Compare the caller's first word with the current 0x0203D1A4 handle of the 0x020399A8 block; a match releases the 0x021E2EF8 pair through 0x02034714, a mismatch yields the +0x218 sub-block.
 */
int WIFIBATTLEMATCH_NET_GetPlayerBuffer(int a, char *b)
{
    if (GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) == a) {
        GF_PANIC_Fail((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
        return 0;
    }
    return (int)(b + 0x218);
}

/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x140 word of the fourth argument.
 */
void WIFIBATTLEMATCH_NET_OnRecvFlagA(u32 a, u32 b, u32 c, char *d, u32 e)
{
    if (e != (u32)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct WifiBattleMatchNetCtx *)d)->sessionResult = 1;
}

/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the tick from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x144 word of the fourth argument.
 */
void WIFIBATTLEMATCH_NET_OnRecvFlagB(u32 a, u32 b, u32 c, char *d, u32 e)
{
    if (e != (u32)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct WifiBattleMatchNetCtx *)d)->regBufferReady = 1;
}

/*
 * Guarded flag set: only when the caller's fifth argument (on the stack)
 * matches the entry address from 0x020399A8 and the first argument does NOT match
 * 0x0203D1A4 does it store 1 in the +0x148 word of the fourth argument.
 */
void WIFIBATTLEMATCH_NET_OnRecvFlagC(u32 a, u32 b, u32 c, char *d, u32 e)
{
    if (e != (u32)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct WifiBattleMatchNetCtx *)d)->regFlagReady = 1;
}

/*
 * Same guard as WIFIBATTLEMATCH_NET_OnRecvFlagA but it moves the word the third argument
 *     points at into the +0x150 slot of the fourth argument and sets +0x14c.
 */
void WIFIBATTLEMATCH_NET_OnRecvValue(u32 a, u32 b, u32 *c, char *d, u32 e)
{
    u32 value = *c;

    if (e != (u32)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (a == GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    ((struct WifiBattleMatchNetCtx *)d)->regValue = value;
    ((struct WifiBattleMatchNetCtx *)d)->regValueReady = 1;
}

/*
 * Selects a request kind 0..4: stores the table and its count at +0x194/+0x198 and the step callback at +0x17c, after resetting the step word at +0x12c and storing the two arguments.
 */
void WIFIBATTLEMATCH_NET_GdbRequest(char *obj, u32 target, int kind, u32 arg)
{
    ((struct WifiBattleMatchNetCtx *)obj)->state = 0;
    ((struct WifiBattleMatchNetCtx *)obj)->gdbArg = arg;
    ((struct WifiBattleMatchNetCtx *)obj)->gdbTarget = target;
    switch (kind) {
    case 0:
        *(char * *)&((struct WifiBattleMatchNetCtx *)obj)->gdbName = WIFIBATTLEMATCH_NET_GetRegNameA();
        ((struct WifiBattleMatchNetCtx *)obj)->fieldCount = WIFIBATTLEMATCH_NET_GetRegKindA();
        *(StepFn *)&((struct WifiBattleMatchNetCtx *)obj)->gdbStep = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldsA;
        break;
    case 1:
        *(char * *)&((struct WifiBattleMatchNetCtx *)obj)->gdbName = WIFIBATTLEMATCH_NET_GetRegNameB();
        ((struct WifiBattleMatchNetCtx *)obj)->fieldCount = WIFIBATTLEMATCH_NET_GetRegKindB();
        *(StepFn *)&((struct WifiBattleMatchNetCtx *)obj)->gdbStep = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldsB;
        break;
    case 2:
        *(char * *)&((struct WifiBattleMatchNetCtx *)obj)->gdbName = d_021E2DF4;
        ((struct WifiBattleMatchNetCtx *)obj)->fieldCount = 1;
        *(StepFn *)&((struct WifiBattleMatchNetCtx *)obj)->gdbStep = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldC;
        break;
    case 3:
        *(char * *)&((struct WifiBattleMatchNetCtx *)obj)->gdbName = d_021E2DEC;
        ((struct WifiBattleMatchNetCtx *)obj)->fieldCount = 1;
        *(StepFn *)&((struct WifiBattleMatchNetCtx *)obj)->gdbStep = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldD;
        break;
    case 4:
        *(char * *)&((struct WifiBattleMatchNetCtx *)obj)->gdbName = d_021E2DF0;
        ((struct WifiBattleMatchNetCtx *)obj)->fieldCount = 1;
        *(StepFn *)&((struct WifiBattleMatchNetCtx *)obj)->gdbStep = (StepFn)WIFIBATTLEMATCH_NET_GdbCopyFieldE;
        break;
    }
}

int WIFIBATTLEMATCH_NET_GdbGetMyRecords(char *obj)
{
    int result;

    switch (((struct WifiBattleMatchNetCtx *)obj)->state) {
    case 0:
        result = DWC_GdbInitialize(0xb5f, ((struct WifiBattleMatchNetCtx *)obj)->scId, 0);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(obj + 0x18, result, 0xdef);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        ((struct WifiBattleMatchNetCtx *)obj)->state = 1;
        break;
    case 1:
        if (((struct WifiBattleMatchNetCtx *)obj)->fieldCount >= 0x26)
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
        if (((struct WifiBattleMatchNetCtx *)obj)->gdbTarget == -1)
            result = DWC_GdbGetMyRecordsAsync(d_021E2F1C, ((struct WifiBattleMatchNetCtx *)obj)->gdbName, ((struct WifiBattleMatchNetCtx *)obj)->fieldCount, WIFIBATTLEMATCH_NET_GdbSortByName, obj);
        else
            result = DWC_GdbGetRecordsAsync(d_021E2F1C, (int *)(obj + 0x1b0), 1, ((struct WifiBattleMatchNetCtx *)obj)->gdbName, ((struct WifiBattleMatchNetCtx *)obj)->fieldCount, WIFIBATTLEMATCH_NET_GdbSortByName, obj);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(obj + 0x18, result, 0xe0a);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        ((struct WifiBattleMatchNetCtx *)obj)->state = 2;
        ((struct WifiBattleMatchNetCtx *)obj)->pollCount = 0;
        break;
    case 2:
        if ((((struct WifiBattleMatchNetCtx *)obj)->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(obj + 0x18, 1, 0xe17);
            ((struct WifiBattleMatchNetCtx *)obj)->state = 6;
            break;
        }
        DWC_GdbProcess();
        result = DWC_GdbGetState();
        if (result == 0 || result == 4) {
            WIFIBATTLEMATCH_NET_SetResultB(obj + 0x18, result, 0xe26);
            ((struct WifiBattleMatchNetCtx *)obj)->state = 6;
        } else if (result == 1) {
            ((struct WifiBattleMatchNetCtx *)obj)->state = 3;
        }
        break;
    case 3:
        result = DWC_GdbGetAsyncResult();
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetResultC(obj + 0x18, result, 0xe39);
            ((struct WifiBattleMatchNetCtx *)obj)->state = 6;
        } else if (result != 1) {
            WIFIBATTLEMATCH_NET_SetResultC(obj + 0x18, result, 0xe3f);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        } else {
            ((struct WifiBattleMatchNetCtx *)obj)->state = 4;
        }
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(obj);
        ((struct WifiBattleMatchNetCtx *)obj)->state = 5;
        break;
    case 5:
        return 1;
    case 6:
        result = DWC_GdbCancelRequest();
        if (result == 0) {
            ((struct WifiBattleMatchNetCtx *)obj)->pollCount = 0;
            ((struct WifiBattleMatchNetCtx *)obj)->state = 7;
        } else {
            WIFIBATTLEMATCH_NET_SetResultA(obj + 0x18, result, 0xe5e);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        break;
    case 7:
        if ((((struct WifiBattleMatchNetCtx *)obj)->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(obj + 0x18, 1, 0xe6a);
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
            ((struct WifiBattleMatchNetCtx *)obj)->state = 8;
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
void WIFIBATTLEMATCH_NET_GdbShutdown(char *obj)
{
    DWC_GdbShutdown();
}

void WIFIBATTLEMATCH_NET_SetupGdbRecord(char *ctx)
{
    void *record;
    record = GAME_DATA_GetMyStatus(((struct WifiBattleMatchNetCtx *)ctx)->save);
    *(char * *)&((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].name = d_021E2F2C;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].type = 8;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].value = (unsigned int)record;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].size = 32;
    WIFIBATTLEMATCH_NET_GetDateTime((unsigned char *)ctx + 0x38);
    *(char * *)&((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].name = (char *)d_021E2F38;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].type = 8;
    *(char * *)&((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].value = ctx + 0x38;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].size = 6;
    *(char * *)&((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[2].name = d_021E2F4C;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[2].type = 2;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[2].value = ((struct WifiBattleMatchNetCtx *)ctx)->statusBuf;
    *(char * *)&((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[3].name = d_021E2F60;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[3].type = 2;
    ((struct GdbUploadEntry *)(*(char * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[3].value = WIFIBATTLEMATCH_NET_GetGsProfileId(ctx);
    ((struct WifiBattleMatchNetCtx *)ctx)->fieldCount = 4;
}

/*
 * Storage-server records callback: forwards the records to the user callback at +0x17c, then, when no record id is pending (+0x1b0 == -1), scans every field of every record for the id field and stores its value through the pointer at +0x1464.
 */
void WIFIBATTLEMATCH_NET_GdbSortByName(int count, struct Field **recs, char *obj)
{
    int i, j;
    struct Field *f;

    (*(RecordsFn *)(obj + 0x17c))(count, recs, ((struct WifiBattleMatchNetCtx *)obj)->gdbArg, ((struct WifiBattleMatchNetCtx *)obj)->fieldCount);
    if (((struct WifiBattleMatchNetCtx *)obj)->gdbTarget != -1)
        return;
    for (i = 0; i < count; i++) {
        for (j = 0; j < ((struct WifiBattleMatchNetCtx *)obj)->fieldCount; j++) {
            f = &recs[i][j];
            if (GF_STANDARD_CompareString(f->name, d_021E2F70) == 0)
                **(u32 * *)&((struct WifiBattleMatchNetCtx *)obj)->netIdPtr = f->payload.value;
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldsA(int count,struct Field **fields,char *ctx,int n) {
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(9))) ((struct RegDataA *)ctx)->regField9=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(10))) ((struct RegDataA *)ctx)->regField10=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(12))) ((struct RegDataA *)ctx)->regField12=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(11))) ((struct RegDataA *)ctx)->regField11=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(13))) ((struct RegDataA *)ctx)->regField13=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(14))) ((struct RegDataA *)ctx)->regField14=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(15))) ((struct RegDataA *)ctx)->regField15=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(16))) ((struct RegDataA *)ctx)->regField16=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(17))) ((struct RegDataA *)ctx)->regField17=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(18))) ((struct RegDataA *)ctx)->regField18=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(19))) ((struct RegDataA *)ctx)->regField19=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(20))) ((struct RegDataA *)ctx)->regField20=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(21))) ((struct RegDataA *)ctx)->regField21=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(22))) ((struct RegDataA *)ctx)->regField22=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(23))) ((struct RegDataA *)ctx)->regField23=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(3))) ((struct RegDataA *)ctx)->regField3=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(24))) ((struct RegDataA *)ctx)->regField24=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F4C)) ((struct RegDataA *)ctx)->regExtraA=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F60)) ((struct RegDataA *)ctx)->regExtraB=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F7C)) ((struct RegDataA *)ctx)->regExtraC=f->payload.value;
            else if(!GF_STANDARD_CompareString(f->name,d_021E2F70)) ((struct RegDataA *)ctx)->regExtraD=f->payload.value;
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldsB(int count,struct Field **fields,u8 *ctx,int n)
{
    int i,j;
    const struct Field *f;
    for(i=0;i<count;i++) {
        for(j=0;j<n;j++) {
            f=&fields[i][j];
            if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x25))==0) ((struct RegDataB *)ctx)->regField37=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x26))==0) ((struct RegDataB *)ctx)->regField38=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x24))==0) ((struct RegDataB *)ctx)->regField36=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x28))==0) ((struct RegDataB *)ctx)->regField40=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(0x27))==0) ((struct RegDataB *)ctx)->regField39=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,d_021E2F7C)==0) ((struct RegDataB *)ctx)->regField35=f->payload.value;
            else if(GF_STANDARD_CompareString(f->name,d_021E2F8C)==0) {
                const struct Blob *blob=&f->payload.blob;
                MI_CpuCopy8(blob->data,ctx+24,blob->size);
            }
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldC(int count, char **rows, int *out, int width)
{
    int i, j;
    char *record;
    for (i = 0; i < count; i++) {
        for (j = 0; j < width; j++) {
            record = rows[i] + j * 16;
            if (GF_STANDARD_CompareString(*(char * *)&((struct RegField *)record)->name, d_021E2F70) == 0)
                *out = ((struct RegField *)record)->value;
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldD(int count,struct Field **recs,void *dst,int nfields)
{
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->name,d_021E2F8C)==0)
                MI_CpuCopy8(f->payload.ptr,dst,f->payload.blob.size);
        }
    }
}

void WIFIBATTLEMATCH_NET_GdbCopyFieldE(int count,struct Field **recs,void *dst,int nfields)
{
    int i,j;
    struct Field *f;
    for(i=0;i<count;i++){
        for(j=0;j<nfields;j++){
            f=&recs[i][j];
            if(GF_STANDARD_CompareString(f->name,d_021E2F38)==0)
                MI_CpuCopy8(f->payload.ptr,dst,f->payload.blob.size);
        }
    }
}

void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *ctx,u32 mode,struct Record *src)
{
    ((struct WifiBattleMatchNetCtx *)ctx)->state=0;
    if(**(u32 * *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr==0)GF_PANIC_Fail((const char *)((int)d_021E2EF8),0,(const char *)((int)d_021E2EF8));
    switch(mode) {
    case 0:
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].name=(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(36);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].type=2;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].value=1500;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].name=(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(39);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].type=2;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].value=0;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[2].name=(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(40);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[2].type=2;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[2].value=0;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[3].name=(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(38);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[3].type=2;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[3].value=0;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[4].name=(const char *)WIFIBATTLEMATCH_NET_LookupFieldEntry(37);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[4].type=2;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[4].value=0;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[5].name=d_021E2F8C;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[5].type=8;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[5].value=(u32)src;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[5].size=1332;
        ((struct WifiBattleMatchNetCtx *)ctx)->fieldCount=6;
        break;
    case 1:
        WIFIBATTLEMATCH_NET_GetDateTime(ctx+0x38);
        ((struct WifiBattleMatchNetCtx *)ctx)->fieldCount=1;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].name=d_021E2F38;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].type=8;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].value=(u32)(ctx+0x38);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].size=6;
        break;
    case 2:WIFIBATTLEMATCH_NET_SetupGdbRecord((char *)ctx);break;
    case 3:
        *(struct Record *)(ctx+0x1c4)=*src;
        ((struct WifiBattleMatchNetCtx *)ctx)->fieldCount=2;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].name=(const char *)d_021E2DF8[((struct WifiBattleMatchNetCtx *)ctx)->uploadKind];
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].type=8;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].value=(u32)(ctx+0x1c4);
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[0].size=80;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].name=(const char *)d_021E2F7C;
        ((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].type=0;
        *(unsigned char *)&((struct GdbUploadEntry *)(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->recBuf))[1].value = (unsigned char)((((struct WifiBattleMatchNetCtx *)ctx)->uploadKind+1)%6);
        break;
    }
}

/*
 * lever: PC-relative slot audit binds error/cancel/timeout lines to 0x11a0,0x11be,0x11ca; fixing source constants removes three pool-byte mismatches.
 * extent: existing matched WIFIBATTLEMATCH_NET_GdbClearRecord.c covers the final16 bytes; keep this504-byte lead alone.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives live entry r0 in case 4 despite its unused parameter.
 */
int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *ctx)
{
    long result;
    switch(((struct WifiBattleMatchNetCtx *)ctx)->state) {
    case 0:
        result=((int (*)(int,DWCstAccUserData *,int))DWC_GdbInitialize)(0xb5f,*(DWCstAccUserData * *)&((struct WifiBattleMatchNetCtx *)ctx)->scId,0);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(ctx+0x18,result,0x1161);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        ((struct WifiBattleMatchNetCtx *)ctx)->state=1;break;
    case 1:
        if(((struct WifiBattleMatchNetCtx *)ctx)->fieldCount>=0x26)GF_PANIC_Fail(d_021E2EF8,0,d_021E2EF8);
        result=DWC_GdbUpdateRecordAsync((char *)d_021E2F1C,**(int * *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr,((struct WifiBattleMatchNetCtx *)ctx)->recBuf,((struct WifiBattleMatchNetCtx *)ctx)->fieldCount);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(ctx+0x18,result,0x116e);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        ((struct WifiBattleMatchNetCtx *)ctx)->pollCount=0;((struct WifiBattleMatchNetCtx *)ctx)->state=2;break;
    case 2:
        if((((struct WifiBattleMatchNetCtx *)ctx)->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(ctx+0x18,1,0x117b);((struct WifiBattleMatchNetCtx *)ctx)->state=6;break;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_SetResultB(ctx+0x18,result,0x1186);((struct WifiBattleMatchNetCtx *)ctx)->state=6;}
        else if(result==1)((struct WifiBattleMatchNetCtx *)ctx)->state=3;
        break;
    case 3:
        result=DWC_GdbGetAsyncResult();
        if(result==0) {WIFIBATTLEMATCH_NET_SetResultC(ctx+0x18,result,0x1199);((struct WifiBattleMatchNetCtx *)ctx)->state=6;}
        else if(result!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);WIFIBATTLEMATCH_NET_SetResultC(ctx+0x18,result,0x11a0);return 2;}
        else ((struct WifiBattleMatchNetCtx *)ctx)->state=4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(ctx);((struct WifiBattleMatchNetCtx *)ctx)->state=5;
    case 5:return 1;
    case 6:
        result=DWC_GdbCancelRequest();
        if(result==0) {((struct WifiBattleMatchNetCtx *)ctx)->pollCount=0;((struct WifiBattleMatchNetCtx *)ctx)->state=7;}
        else {WIFIBATTLEMATCH_NET_SetResultA(ctx+0x18,result,0x11be);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        break;
    case 7:
        if((((struct WifiBattleMatchNetCtx *)ctx)->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(ctx+0x18,1,0x11ca);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        if(result==1)((struct WifiBattleMatchNetCtx *)ctx)->state=8;
        break;
    case 8:WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;
    }
    return 0;
}

/*
 * leaf: reset request step then prepare four database fields.
 */
void WIFIBATTLEMATCH_NET_GdbClearRecord(char *ctx)
{
    ((struct WifiBattleMatchNetCtx *)ctx)->state = 0;
    WIFIBATTLEMATCH_NET_SetupGdbRecord(ctx);
}

/*
 * lever: PC-relative pool audit binds source-line constants 125c/126f/127b to the success/cancel-error/timeout calls, fixing the prior three concrete pool bytes.
 * prototype: Setters retain caller-loaded line in r2; shutdown receives p where the caller visibly prepares r0.
 */
int WIFIBATTLEMATCH_NET_GdbCreateRecord(char *ctx)
{
    long result;
    switch(((struct WifiBattleMatchNetCtx *)ctx)->state) {
    case 0:
        result=((int (*)(int,DWCstAccUserData *,int))DWC_GdbInitialize)(0xb5f,*(DWCstAccUserData * *)&((struct WifiBattleMatchNetCtx *)ctx)->scId,0);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(ctx+0x18,result,0x1215);return 2;}
        ((struct WifiBattleMatchNetCtx *)ctx)->state=1;break;
    case 1:
        result=DWC_GdbCreateRecordAsync((char *)d_021E2F1C,((struct WifiBattleMatchNetCtx *)ctx)->recBuf,((struct WifiBattleMatchNetCtx *)ctx)->fieldCount,*(int * *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(ctx+0x18,result,0x1223);return 2;}
        ((struct WifiBattleMatchNetCtx *)ctx)->pollCount=0;((struct WifiBattleMatchNetCtx *)ctx)->state=2;break;
    case 2:
        if((((struct WifiBattleMatchNetCtx *)ctx)->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(ctx+0x18,1,0x122f);((struct WifiBattleMatchNetCtx *)ctx)->state=4;break;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_SetResultB(ctx+0x18,result,0x123b);((struct WifiBattleMatchNetCtx *)ctx)->state=4;}
        else if(result==1)((struct WifiBattleMatchNetCtx *)ctx)->state=3;
        break;
    case 3:
        result=DWC_GdbGetAsyncResult();
        if(result==0) {WIFIBATTLEMATCH_NET_SetResultC(ctx+0x18,result,0x124f);((struct WifiBattleMatchNetCtx *)ctx)->state=4;}
        else if(result!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);WIFIBATTLEMATCH_NET_SetResultC(ctx+0x18,result,0x1256);return 2;}
        else {
            if(**(u32 * *)&((struct WifiBattleMatchNetCtx *)ctx)->netIdPtr==0)WIFIBATTLEMATCH_NET_SetErrorA(ctx+0x18,2,0x125c);
            WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 1;
        }
        break;
    case 4:
        result=DWC_GdbCancelRequest();
        if(result==0) {((struct WifiBattleMatchNetCtx *)ctx)->pollCount=0;((struct WifiBattleMatchNetCtx *)ctx)->state=5;}
        else {WIFIBATTLEMATCH_NET_SetResultA(ctx+0x18,result,0x126f);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        break;
    case 5:
        if((((struct WifiBattleMatchNetCtx *)ctx)->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(ctx+0x18,1,0x127b);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        if(result==1)((struct WifiBattleMatchNetCtx *)ctx)->state=6;
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
u32 WIFIBATTLEMATCH_NET_GetNetId(char *obj)
{
    return *(u32 *)(((struct WifiBattleMatchNetCtx *)obj)->netIdPtr);
}

/*
 * Sends through the eight-argument link routine with arguments (link, flag, 0x2401, size + 0xd4, data, 1, 1, 1); size is 0x0201A918's constant.
 */
u32 WIFIBATTLEMATCH_NET_SendRegData(char *obj, u32 data)
{
    u32 busy = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), (u8)flag, 0x2401, POKE_REGULATION_GetDataSize() + 0xd4, data, 1, 1, 1);
}

/*
 * Take-and-clear: returns the word at +0x13c; when it is set, clears it and hands back the address of the +0x218 block through out.
 */
u32 WIFIBATTLEMATCH_NET_TakeRegData(char *obj, char **out)
{
    u32 ready = ((struct WifiBattleMatchNetCtx *)obj)->regDataReady;
    if (ready != 0) {
        ((struct WifiBattleMatchNetCtx *)obj)->regDataReady = 0;
        *out = obj + 0x218;
    }
    return ready;
}

u32 WIFIBATTLEMATCH_NET_SendRegDataAlt(char *ctx,unsigned int data)
{
    unsigned int busy=GFL_NET_GetHandleNetID((struct Link *)((unsigned int)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag=1;
    if(busy!=0) flag=0;
    return GFL_NET_SendData((unsigned int)GFL_NET_HANDLE_GetCurrentHandle(),(unsigned char)flag,0x2403,POKE_REGULATION_GetDataSize(),data,1,1,1);
}

/*
 * Takes and clears the +0x144 block; when there was one, calls
 *     0x0201A918(0) and hands its result to 0x02082D44 together with the
 *     object's +0x218 port block and the caller's second argument.  Returns
 *     the block it took.
 */
u32 WIFIBATTLEMATCH_NET_TakeRegBuffer(char *obj, u32 arg)
{
    u32 ready = ((struct WifiBattleMatchNetCtx *)obj)->regBufferReady;

    if (ready != 0) {
        ((struct WifiBattleMatchNetCtx *)obj)->regBufferReady = 0;
        MI_CpuCopy8(obj + 0x218, (void *)arg, POKE_REGULATION_GetDataSize());
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
int WIFIBATTLEMATCH_NET_SendRegFlag(char *obj, u32 data)
{
    u32 busy = GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle()));
    int flag = 1;

    if (busy != 0)
        flag = 0;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetCurrentHandle(), (u8)flag, 0x2404, 4, data, 1, 1, 1);
}

u32 WIFIBATTLEMATCH_NET_TakeRegFlag(char *obj, u32 arg)
{
    u32 ready = ((struct WifiBattleMatchNetCtx *)obj)->regFlagReady;

    if (ready != 0) {
        ((struct WifiBattleMatchNetCtx *)obj)->regFlagReady = 0;
        MI_CpuCopy8(obj + 0x218, (void *)arg, 4);
    }
    return ready;
}

/*
 * Tagged log/emit: the tick from 0x020399A8, the id 0x2405, a length of
 *     4 and the caller's pointer go to 0x0203D3A8, which is the four-argument
 *     form the listing loads straight into r2/r3.
 */
int WIFIBATTLEMATCH_NET_SendRegValue(u32 ignored, void *ctx)
{
    return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0x2405, 4, (u32)ctx);
}

/*
 * Take-and-clear: returns the word at +0x14c; when it is set, clears it and hands back the word at +0x150 through out.
 */
u32 WIFIBATTLEMATCH_NET_TakeRegValue(char *obj, u32 *out)
{
    u32 ready = ((struct WifiBattleMatchNetCtx *)obj)->regValueReady;
    if (ready != 0) {
        ((struct WifiBattleMatchNetCtx *)obj)->regValueReady = 0;
        *out = ((struct WifiBattleMatchNetCtx *)obj)->regValue;
    }
    return ready;
}

void WIFIBATTLEMATCH_NET_SetupDownload(char *ctx,unsigned a)
{
    ((struct WifiBattleMatchNetCtx *)ctx)->state=0;
    ((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;
    MI_CpuFill8(ctx+0x144c,0,10);
    MI_CpuFill8(ctx+0x1390,0,0xb0);
    STD_TSPrintf(ctx+0x144c,d_021E2FA4,a);
}

/*
 * lever: case-local repeated error call+break reproduces merged error block and long-branch layout; tail goto displaced it.
 * extent: unlabelled28-byte zero-word test021DC5AC filed separately.
 */
int WIFIBATTLEMATCH_NET_DownloadProcess(u8 *ctx)
{
    u32 count,percent;
    switch(((struct WifiBattleMatchNetCtx *)ctx)->state) {
    case 0:
        if(DWC_NdInitAsync((void (*)(int,  int,  int))WIFIBATTLEMATCH_NET_NdSetError,d_021E2FA8,d_021E2FB0)==0)return 3;
        ((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=1;
        WIFIBATTLEMATCH_NET_NdSetState(ctx,1);break;
    case 1:
        if(DWC_NdSetAttr(d_021E2FC4,(char *)(ctx+0x144c),(char *)d_021E2EF8)==0){WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);break;}
        ((struct WifiBattleMatchNetCtx *)ctx)->state=2;break;
    case 2:
        if(DWC_NdGetFileListAsync(ctx+0x1390,0,1)==0){WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);break;}
        WIFIBATTLEMATCH_NET_NdSetState(ctx,3);break;
    case 3:
        count=0xb0;
        if(WIFIBATTLEMATCH_NET_IsBufferZero((const unsigned int *)(ctx+0x1390),0xb0)==0) {
            count+=0xb0;
            if(DWC_NdGetFileAsync(ctx+0x1390,(char *)(ctx+0x1230),count)==0){WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);break;}
            d_021E4B80[0]=0;*(u32 *)(d_021E4B80+4)=0;
            ((struct WifiBattleMatchNetCtx *)ctx)->state=4;
        } else {
            if(DWC_NdCleanupAsync()==0) {((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;return 2;}
            WIFIBATTLEMATCH_NET_NdSetState(ctx,7);
        }
        break;
    case 4:
        DWC_NdProcess();
        if((((struct WifiBattleMatchNetCtx *)ctx)->pollCount)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);WIFIBATTLEMATCH_NET_NdCancelState(ctx,8);}
        if(d_021E4B80[0]==0) {
            if(DWC_NdGetProgress((u32 *)(ctx+0x1444),(u32 *)(ctx+0x1448))==1) {
                percent=(((struct WifiBattleMatchNetCtx *)ctx)->downloadDone*100)/((struct WifiBattleMatchNetCtx *)ctx)->downloadTotal;
                if(((struct WifiBattleMatchNetCtx *)ctx)->downloadPercent!=percent)((struct WifiBattleMatchNetCtx *)ctx)->downloadPercent=percent;
            }
        } else {
            if(*(u32 *)(d_021E4B80+4)!=0) {
                if(*(u32 *)(d_021E4B80+4)==8)GFL_NET_ERR_HaltIfActive();
                else WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);
            } else {
                if(DWC_NdCleanupAsync()==0) {((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;return 3;}
                WIFIBATTLEMATCH_NET_NdSetState(ctx,5);
            }
        }
        break;
    case 5:((struct WifiBattleMatchNetCtx *)ctx)->state=6;break;
    case 6:
        if(REGULATION_Card_IsCrcValid((struct Reg2 *)(ctx+0x1230))!=0) {((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;return 1;}
        ((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;return 2;
    case 7:((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;return 2;
    case 8:((struct WifiBattleMatchNetCtx *)ctx)->downloadActive=0;return 3;
    case 100:
        DWC_NdProcess();
        if((((struct WifiBattleMatchNetCtx *)ctx)->pollCount)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);WIFIBATTLEMATCH_NET_NdCancelState(ctx,8);}
        if(*(u32 *)(d_021E4B80+4)!=0) {
            if(*(u32 *)(d_021E4B80+4)==8)GFL_NET_ERR_HaltIfActive();
            else WIFIBATTLEMATCH_NET_NdCleanupState(ctx,8);
        }
        if(d_021E4B80[0]!=0) {
            d_021E4B80[0]=0;
            if(*(u32 *)(d_021E4B80+4)==0)((struct WifiBattleMatchNetCtx *)ctx)->state=((struct WifiBattleMatchNetCtx *)ctx)->nextState;
        }
        break;
    case 200:
        DWC_NdProcess();
        if(d_021E4B80[1]!=0) {d_021E4B80[1]=0;((struct WifiBattleMatchNetCtx *)ctx)->state=((struct WifiBattleMatchNetCtx *)ctx)->nextState;}
        break;
    case 300:
        DWC_NdProcess();
        if(d_021E4B80[0]!=0) {d_021E4B80[0]=0;WIFIBATTLEMATCH_NET_NdCleanupState(ctx,((struct WifiBattleMatchNetCtx *)ctx)->nextState);}
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
void WIFIBATTLEMATCH_NET_CleanupDownload(void *ctx, int unused, int kind)
{
    if (kind != 3 && kind != 6)
        return;
    if (((struct WifiBattleMatchNetCtx *)ctx)->rapHandle != 0) {
        NHTTP_RAP_DeleteConnection((u8 *)(((struct WifiBattleMatchNetCtx *)ctx)->rapHandle));
        NHTTP_RAP_Destroy((u8 *)(((struct WifiBattleMatchNetCtx *)ctx)->rapHandle));
        ((struct WifiBattleMatchNetCtx *)ctx)->rapHandle = 0;
    }
    WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
}

u32 WIFIBATTLEMATCH_NET_GetDownloadSize(char *ctx, int a, int kind)
{
    if (kind == 3 || kind == 6) return *(u32 *)(ctx + 0x1458);
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
        GF_PANIC_Fail((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
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

void WIFIBATTLEMATCH_NET_GetRegCardName(const char *ctx,void *out)
{
    MI_CpuCopy8(ctx+0x1230,out,0x160);
}

/*
 * lever: unlabelled asynchronous state setter blocking matched caller021DC338.
 */
void WIFIBATTLEMATCH_NET_NdSetState(u8 *ctx,int state)
{
    d_021E4B80[0]=0;
    *(u32 *)(d_021E4B80+4)=0;
    ((struct WifiBattleMatchNetCtx *)ctx)->nextState=state;
    ((struct WifiBattleMatchNetCtx *)ctx)->state=100;
    ((struct WifiBattleMatchNetCtx *)ctx)->pollCount=0;
}

void WIFIBATTLEMATCH_NET_NdCleanupState(u8 *ctx,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; ((struct WifiBattleMatchNetCtx *)ctx)->nextState=state; ((struct WifiBattleMatchNetCtx *)ctx)->state=200; if(DWC_NdCleanupAsync()==0) ((struct WifiBattleMatchNetCtx *)ctx)->nextState=state; }

void WIFIBATTLEMATCH_NET_NdCancelState(u8 *ctx,int state) { d_021E4B80[0]=0; *(u32 *)(d_021E4B80+4)=0; ((struct WifiBattleMatchNetCtx *)ctx)->nextState=state; ((struct WifiBattleMatchNetCtx *)ctx)->state=300; if(DWC_NdCancelAsync()==0) ((struct WifiBattleMatchNetCtx *)ctx)->nextState=state; }

void WIFIBATTLEMATCH_NET_NdSetError(void *ctx,u32 kind) { switch(kind) { case 0:case 1:case 2:case 3:case 4:case 5:case 7: break; case 6:case 8: GFL_NET_ERR_HaltIfActive(); break; } d_021E4B80[0]=1; *(u32 *)(d_021E4B80+4)=kind; d_021E4B80[1]=1; }

void WIFIBATTLEMATCH_NET_CreateHttpRap(char *ctx,unsigned heap)
{
    if(*(int *)&((struct WifiBattleMatchNetCtx *)ctx)->rapHandle!=0) GF_PANIC_Fail(d_021E2EF8,0,d_021E2EF8);
    ((struct WifiBattleMatchNetCtx *)ctx)->state=0;
    ((struct WifiBattleMatchNetCtx *)ctx)->rapHandle=NHTTP_RAP_Create(heap,MYSTATUS_GetProfileId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct WifiBattleMatchNetCtx *)ctx)->save)),((struct WifiBattleMatchNetCtx *)ctx)->heap);
}

/*
 * checks: 1 copied own ov114/DC610 signatures and ARM9 blocker input reads; 2 existing DC8A0 Pair twin used; 3 Pair replaces scalar two-word copy; 4 aggregate-copy idioms applied; 5 fresh directory and ov175 neighbours read. Caller TU MATCH has no viable split; only ARM90200FB4C blocks it.
 * lever: Pair aggregate assignment fixes all four payload-copy register bytes; TU --suggest-split confirms MATCH, no viable cut.
 * extent: lead 292 bytes; following 20-byte DC8A0 is already B7's src/matched/ov/WIFIBATTLEMATCH_NET_GetRapPair.c.
 */
int WIFIBATTLEMATCH_NET_HttpRapProcess(u8 *ctx)
{
    int query,status;
    const u8 *r;
    if(*(u8 **)(ctx+0x121c)==0)return 2;
    switch(*(u32 *)(ctx+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreateRequest(5,*(u8 **)(ctx+0x121c))!=0)*(u32 *)(ctx+0x12c)=1;
        break;
    case 1:
        if(NHTTP_RAP_StartConnection(*(u8 **)(ctx+0x121c))==0) {*(u32 *)(ctx+0x12c)=2;break;}
        if(*(u8 **)(ctx+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u32 *)(ctx+0x121c)=0;}
        return 2;
    case 2:
        query=NHTTP_RAP_GetResultCode(*(u8 **)(ctx+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(ctx+0x121c));
        if(status==0) {
            r=NHTTP_RAP_GetRecvBuffer(*(u8 **)(ctx+0x121c));
            if(query!=0x1f6) {
                if(query==0x1f7) {*(u32 *)(ctx+0x12c)=4;GFL_NET_ERR_RaiseFatal(62);return 0;}
            } else {*(u32 *)(ctx+0x12c)=4;GFL_NET_ERR_RaiseFatal(63);return 0;}
            *(Pair *)(ctx+0x1220)=*(const Pair *)(r+0x80);
            if(*(u32 *)r==0)*(u32 *)(ctx+0x12c)=3;
            else {GFL_NET_ERR_RaiseFatal(WIFIBATTLEMATCH_NET_DownloadError(*(u32 *)r));*(u32 *)(ctx+0x12c)=4;}
        } else if(status!=15) {
            if(*(u8 **)(ctx+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u32 *)(ctx+0x121c)=0;}
            return 2;
        }
        break;
    case 4:
        MI_CpuFill8(ctx+0x1220,0,8);
        if(*(u8 **)(ctx+0x121c)!=0) {
            NHTTP_RAP_DeleteConnection(*(u8 **)(ctx+0x121c));NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u32 *)(ctx+0x121c)=0;
        }
        return 3;
    case 3:
        if(*(u8 **)(ctx+0x121c)!=0) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u32 *)(ctx+0x121c)=0;}
        return 1;
    }
    return 0;
}

/*
 * Pair aggregate assignment preserves the forward load and store order.
 * leaf: coordinated transfer from B10's extent to unblock 021D6C54.
 */
void WIFIBATTLEMATCH_NET_GetRapPair(const Obj *ctx,Pair *out)
{
    *out=*(const Pair *)((const char *)ctx+0x1220);
}

void WIFIBATTLEMATCH_NET_SetupHttpRap(u8 *ctx, const W *src, int x)
{
    if (*(u32 *)(ctx + 0x121C) != 0)
        GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
    *(u8 **)(ctx + 0x121C) = NHTTP_RAP_Create(x, MYSTATUS_GetProfileId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(*(void **)(ctx + 8))), *(int *)(ctx + 0x10));
    *(W *)(ctx + 0x1228) = *src;
    *(u32 *)(ctx + 0x12C) = 0;
}

int WIFIBATTLEMATCH_NET_HttpRapSend(char *ctx)
{
    int result;
    int status;
    u32 *data;
    if(*(u8 **)(ctx+0x121c)==0) return 2;
    switch(*(u32 *)(ctx+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreateRequest(6,*(u8 **)(ctx+0x121c))) {
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(*(char **)(ctx+0x121c)),(void *)((u32)(ctx+0x1228)),8);
            *(u32 *)(ctx+0x12c)=1;
        }
        break;
    case 1:
        if(!NHTTP_RAP_StartConnection(*(u8 **)(ctx+0x121c))) *(u32 *)(ctx+0x12c)=2;
        else {
            if(*(u8 **)(ctx+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u8 **)(ctx+0x121c)=0;}
            return 2;
        }
        break;
    case 2:
        result=NHTTP_RAP_GetResultCode(*(u8 **)(ctx+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(ctx+0x121c));
        if(status==0) {
            data=(u32 *)NHTTP_RAP_GetRecvBuffer(*(u8 **)(ctx+0x121c));
            switch(result) {
            case 0x1f7: *(u32 *)(ctx+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3e);return 0;
            case 0x1f6: *(u32 *)(ctx+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3f);return 0;
            default:
                if(*data==0) *(u32 *)(ctx+0x12c)=4;
                else {GFL_NET_ERR_RaiseFatal(WIFIBATTLEMATCH_NET_DownloadError(*data));*(u32 *)(ctx+0x12c)=3;}
                break;
            }
        } else if(status!=15) {
            WIFIBATTLEMATCH_NET_SetResultD(ctx+0x18,status,0x16a0);
            if(*(u8 **)(ctx+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u8 **)(ctx+0x121c)=0;}
            return 2;
        }
        break;
    case 3:
        if(*(u8 **)(ctx+0x121c)) {
            NHTTP_RAP_DeleteConnection(*(u8 **)(ctx+0x121c));
            NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));
            *(u8 **)(ctx+0x121c)=0;
        }
        return 3;
    case 4:
        if(*(u8 **)(ctx+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u8 **)(ctx+0x121c)=0;}
        return 1;
    }
    return 0;
}

/*
 * Starts a profanity check of the string in window a1: copies it into the 20-character buffer at +0x1468 (the terminator code 0x02045A98 returns becomes 0), and submits it with DWC_CheckProfanityExAsync (one word, results at +0x1484/+0x1488, region 0x80).
 */
void WIFIBATTLEMATCH_NET_StartProfanityCheck(char *obj, unsigned long win, u16 tag)
{
    unsigned long str;
    u16 *src;
    unsigned long i;

    ((struct WifiBattleMatchNetCtx *)obj)->profanityWindow = win;
    str = (unsigned long)MYSTATUS_CreateNameStrbuf((void *)win, ((struct WifiBattleMatchNetCtx *)obj)->heapTag);
    MI_CpuFill8(obj + 0x1468, 0, 0x28);
    ((struct WifiBattleMatchNetCtx *)obj)->profanityTag = tag;
    src = STRBUF_GetChars((struct U16Vec *)str);
    for (i = 0; i < STRBUF_GetLength((struct U16Vec *)str) + 1; i++) {
        u16 ch = src[i];
        if (ch == STRBUF_GetEosChar())
            *(u16 *)(obj + 0x1468 + i * 2) = 0;
        else
            *(u16 *)(obj + 0x1468 + i * 2) = ch;
    }
    *(u16 * *)&((struct WifiBattleMatchNetCtx *)obj)->profanityWords = (u16 *)(obj + 0x1468);
    ((struct WifiBattleMatchNetCtx *)obj)->profanityCount = 0;
    DWC_CheckProfanityExAsync((u16 **)(obj + 0x1480), 1, 0, 0, obj + 0x1484, (int *)(obj + 0x1488), 0x80);
    STRBUF_Delete((struct U16Vec *)str);
}

/*
 * Polls the profanity check; once it has finished (state 2) reports whether the +0x1488 count is positive, and when it is, loads message 0x51 for the +0x124 id and hands it to the +0x1490 window.
 */
int WIFIBATTLEMATCH_NET_ProfanityProcess(char *obj, int *out)
{
    int state = DWC_CheckProfanityProcess();
    int done = 1;

    if (state != 2)
        done = 0;
    if (done)
        *out = ((struct WifiBattleMatchNetCtx *)obj)->profanityCount > 0 ? 1 : 0;
    if (done == 1 && *out == 1) {
        u32 msg = (u32)MSGDATA_CreateFromArchive(0, 2, 0x51, ((struct WifiBattleMatchNetCtx *)obj)->heapTag);
        u32 str = (u32)MSGDATA_AllocString((struct MsgBank *)msg, MSG_PROFANITY_NOTICE);
        MSGDATA_Delete((struct Rec *)msg);
        MYSTATUS_NameFromStrbuf((u16 *)((struct WifiBattleMatchNetCtx *)obj)->profanityWindow, (struct U16Vec *)str);
        STRBUF_Delete((struct U16Vec *)str);
    }
    return done;
}

void WIFIBATTLEMATCH_NET_SetupPostData(char *ctx,void *party,int mode)
{
    int i;
    unsigned size;
    void *mon;
    i=0;
    ((struct WifiBattleMatchNetCtx *)ctx)->state=0;
    *(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->rapHandle=NHTTP_RAP_Create(((struct WifiBattleMatchNetCtx *)ctx)->heapTag,(int)MYSTATUS_GetProfileId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(((struct WifiBattleMatchNetCtx *)ctx)->save)),((struct WifiBattleMatchNetCtx *)ctx)->heap);
    switch(mode) {
    case 0:
        NHTTP_RAP_AllocPostData(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->rapHandle,((struct WifiBattleMatchNetCtx *)ctx)->heapTag,POKE_TOOL_GetPartyParamSize(),0);
        NHTTP_RAP_AppendPostData(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->rapHandle,(int)party,POKE_TOOL_GetPartyParamSize());
        ((struct WifiBattleMatchNetCtx *)ctx)->postMonCount=1;
        break;
    case 1:
        size=POKE_TOOL_GetPartyParamSize();
        NHTTP_RAP_AllocPostData(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->rapHandle,((struct WifiBattleMatchNetCtx *)ctx)->heapTag,size*POKEPARTY_GetCount(party),0);
        for(i=0;i<(int)POKEPARTY_GetCount(party);i++) {
            mon=POKEPARTY_GetMember(party,i);
            NHTTP_RAP_AppendPostData(*(u8 * *)&((struct WifiBattleMatchNetCtx *)ctx)->rapHandle,(int)mon,POKE_TOOL_GetPartyParamSize());
        }
        ((struct WifiBattleMatchNetCtx *)ctx)->postMonCount=POKEPARTY_GetCount(party);
        break;
    }
}

static inline void clear(char *ctx)
{
    if(*(u8 **)(ctx+0x121c)) {
        NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));
        *(u8 **)(ctx+0x121c)=0;
        *(u32 *)(ctx+0x12c)=0;
    }
}

static inline void release(char *ctx)
{
    if(*(u8 **)(ctx+0x121c)) {
        NHTTP_RAP_FreePostData(*(u8 **)(ctx+0x121c));
        NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));
        NHTTP_RAP_DeleteConnection(*(u8 **)(ctx+0x121c));
        *(u8 **)(ctx+0x121c)=0;
        *(u32 *)(ctx+0x12c)=0;
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
int WIFIBATTLEMATCH_NET_HttpRapPost(char *ctx,u8 *out)
{
    int result;
    int status;
    u32 i;
    u8 *data;
    switch(*(u32 *)(ctx+0x12c)) {
    case 0:
        if(NHTTP_RAP_CreatePostRequest(*(u8 **)(ctx+0x121c))) {
            if(!NHTTP_RAP_StartConnection(*(u8 **)(ctx+0x121c))) (*(u32 *)(ctx+0x12c))++;
            else {clear(ctx);return 2;}
        } else {clear(ctx);return 2;}
        break;
    case 1:
        result=NHTTP_RAP_GetResultCode(*(u8 **)(ctx+0x121c));
        status=NHTTP_RAP_PollConnection(*(u8 **)(ctx+0x121c));
        if(status==0) {
            switch(result) {
            case 400: GFL_NET_ERR_RaiseFatal(0x41);release(ctx);return 3;
            case 401: GFL_NET_ERR_RaiseFatal(0x42);release(ctx);return 3;
            case 408: GFL_NET_ERR_RaiseFatal(0x44);release(ctx);return 3;
            default: GFL_NET_ERR_RaiseFatal(0x43);release(ctx);return 3;
            case 200: (*(u32 *)(ctx+0x12c))++;break;
            }
        } else if(status!=15) {
            WIFIBATTLEMATCH_NET_SetResultD(ctx+0x18,status,0x17a4);
            NHTTP_RAP_FreePostData(*(u8 **)(ctx+0x121c));
            clear(ctx);
            return 2;
        }
        break;
    case 2:
        data=NHTTP_RAP_GetRecvBuffer(*(u8 **)(ctx+0x121c));
        *out=NHTTP_RAP_RecordList_GetCount(data);
        for(i=0;i<*(u32 *)(ctx+0x174);i++) *(u32 *)(out+4+i*4)=NHTTP_RAP_RecordList_GetValue((u32)data,i);
        if(*out==0) MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(data,*(u32 *)(ctx+0x174)),out+0x1c,128);
        NHTTP_RAP_FreePostData(*(u8 **)(ctx+0x121c));
        if(*(u8 **)(ctx+0x121c)) {NHTTP_RAP_Destroy(*(u8 **)(ctx+0x121c));*(u8 **)(ctx+0x121c)=0;}
        return 1;
    }
    return 0;
}

/*
 * The +0x14 sibling of WIFIBATTLEMATCH_NET_SetResultD: stores the caller's word at +0x18,
 *     hard-codes 5 at +0x1c and then calls 0x0203C9AC(0, 0, 0, 0x3F5).
 */
void WIFIBATTLEMATCH_NET_SetErrorA(char *ctx, u32 v, int line)
{
    ((struct NetErrRecord *)ctx)->errCode = v;
    ((struct NetErrRecord *)ctx)->errKind = 5;
    GFL_NET_STATE_SetError(0, 0, 0, 0x3F5);
}

/*
 * Set the word at +0 and mark the object armed at +0x1c, then start the
 * 0x3f7 service with a zeroed first three arguments.
 */
void WIFIBATTLEMATCH_NET_SetErrorB(char *ctx, int v, int unused)
{
    ((struct NetErrRecord *)ctx)->errValue = v;
    ((struct NetErrRecord *)ctx)->errKind = 1;
    GFL_NET_STATE_SetError(0, 0, 0, 0x3f7);
}

/*
 * Two-word setter: stores the caller's word at +4 and hard-codes 2 at +0x1c.
 */
void WIFIBATTLEMATCH_NET_SetResultA(char *ctx, u32 v, int line)
{
    ((struct NetErrRecord *)ctx)->resultA = v;
    ((struct NetErrRecord *)ctx)->errKind = 2;
}

void WIFIBATTLEMATCH_NET_SetResultB(char *ctx, u32 v, int line)
{
    ((struct NetErrRecord *)ctx)->resultB = v;
    ((struct NetErrRecord *)ctx)->errKind = 2;
}

/*
 * Two-word setter: stores the caller's word at +0xc and hard-codes 2 at +0x1c.
 */
void WIFIBATTLEMATCH_NET_SetResultC(char *ctx, u32 v, int line)
{
    ((struct NetErrRecord *)ctx)->resultC = v;
    ((struct NetErrRecord *)ctx)->errKind = 2;
}

/*
 * Symbols:
 *   (none)
 *
 * Two-word setter on an ov175 context block: stores the caller's word at
 * +0x14 and hard-codes 4 at +0x1c.  A leaf with no prologue, so disasm.py
 * only found it through a branch target.
 */
void WIFIBATTLEMATCH_NET_SetResultD(char *ctx, u32 v, u32 unused)
{
    ((struct NetErrRecord *)ctx)->resultD = v;
    ((struct NetErrRecord *)ctx)->errKind = 4;
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
    GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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

void WIFIBATTLEMATCH_NET_RestartNet(char *ctx, int flag)
{
    if (flag == 0)
        return;
    GFL_NET_RefreshWmIconAtTopRight(1, ((struct WifiBattleMatchNetCtx *)ctx)->heapTag);
}

/*
 * Tail call to the arm9 Thumb routine 0x02009CC0 with the object's
 *  *  +0x04 field; pooled `ldr r3; bx r3`, so nothing is saved.
 */
u32 WIFIBATTLEMATCH_NET_GetGsProfileId(char *obj)
{
    return WIFILIST_GetGsProfileId((void *)(((struct WifiBattleMatchNetCtx *)obj)->gsProfileId));
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

int WIFIBATTLEMATCH_NET_LookupFieldEntry(int a)
{
    if (a <= 0)
        return (int)g_021E32C4;
    if (a == 0x1e)
        return (int)g_021E32C8;
    if (a == 0x14)
        return (int)g_021E32E0;
    if (a == 0x15)
        return (int)g_021E32FC;
    if (a == 0x17)
        return (int)g_021E3318;
    if (a == 0x13)
        return (int)g_021E3338;
    if (a == 0x16)
        return (int)g_021E3354;
    if (a == 0x24)
        return (int)g_021E3370;
    if (a == 0x19)
        return (int)g_021E3390;
    if (a == 0x1a)
        return (int)g_021E33B0;
    if (a == 0x1c)
        return (int)g_021E33D0;
    if (a == 0x23)
        return (int)g_021E33E8;
    if (a == 0x1d)
        return (int)g_021E3400;
    if (a == 0x1f)
        return (int)g_021E3418;
    if (a == 0x20)
        return (int)g_021E3430;
    if (a == 0x21)
        return (int)g_021E3448;
    if (a == 0x1b)
        return (int)g_021E3460;
    if (a == 0x18)
        return (int)g_021E347C;
    if (a == 0x27)
        return (int)g_021E348C;
    if (a == 0x4)
        return (int)g_021E34A4;
    if (a == 0x3)
        return (int)g_021E34C0;
    if (a == 0x28)
        return (int)g_021E34D4;
    if (a == 0xb)
        return (int)g_021E34F0;
    if (a == 0xc)
        return (int)g_021E3508;
    if (a == 0xe)
        return (int)g_021E3520;
    if (a == 0xd)
        return (int)g_021E3538;
    if (a == 0x12)
        return (int)g_021E3550;
    if (a == 0x11)
        return (int)g_021E356C;
    if (a == 0xa)
        return (int)g_021E3584;
    if (a == 0x9)
        return (int)g_021E359C;
    if (a == 0x10)
        return (int)g_021E35B4;
    if (a == 0xf)
        return (int)g_021E35CC;
    if (a == 0x26)
        return (int)g_021E35E4;
    if (a == 0x25)
        return (int)g_021E3600;
    if (a == 0x22)
        return (int)g_021E3618;
    return (int)g_021E32C4;
}
