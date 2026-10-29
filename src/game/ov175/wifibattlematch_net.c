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

int WIFIBATTLEMATCH_NET_Create(void *a,void *b,void *obj,void *d)
{
    GF_OVERLAY_Load((sptr)ov177_id);
    switch(((struct WifiBattleMatchParams *)obj)->save->commMode) {
    case 1: return d_021E2C74.create(a,b,obj,d);
    case 0: return d_021E2C80.create(a,b,obj,d);
    default: GF_PANIC_Fail(d_021E2DE0,0,d_021E2DE0); return 0;
    }
}

int WIFIBATTLEMATCH_NET_Close(void *a,void *b,void *obj,void *d)
{
    int result;
    switch(((struct WifiBattleMatchParams *)obj)->save->commMode) {
    case 1: result=d_021E2C74.close(a,b,obj,d); break;
    case 0: result=d_021E2C80.close(a,b,obj,d); break;
    default: GF_PANIC_Fail(d_021E2DE0,0,d_021E2DE0); break;
    }
    GFL_USE_StopAllSe();
    GF_OVERLAY_Unload((sptr)ov177_id);
    return result;
}

int WIFIBATTLEMATCH_NET_Other(void *a,void *b,void *obj,void *d) {switch(((struct WifiBattleMatchParams *)obj)->save->commMode) {case 1:return d_021E2C74.other(a,b,obj,d);case 0:return d_021E2C80.other(a,b,obj,d);default:GF_PANIC_Fail(d_021E2DE0,0,d_021E2DE0);return 0;}}

/*
 * prototype: 0203159C's matched void body leaves allocated r0 live;
 *   caller captures r0 at 021D4348 as its cleared 0x100-byte buffer.
 */
int WIFIBATTLEMATCH_NET_TaskCreate(void *sys, int *state, struct WifiBattleMatchParams *params)
{
    struct WifiBattleMatchNetTask *task;
    GF_OVERLAY_Load((sptr)ov067_id);
    GF_OVERLAY_Load((sptr)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 87, 0x35000);
    task = PROCSYS_AllocProcWork(sys, sizeof(*task), 87);
    MI_CpuFill8(task, 0, sizeof(*task));
    task->ctx = params;
    task->graphic = WIFIBATTLEMATCH_GRAPHIC_Create(1, 87);
    task->view = WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera(task->graphic), 2, 87);
    WIFIBATTLEMATCH_NET_CopyBoxSave(params->profile, task);
    task->font = GF_FONT_Create(23, 0, 0, 0, 87);
    task->printQue = PRINTSYS_QUE_Create(87);
    task->msgBank = MSGDATA_CreateFromArchive(0, 2, 210, 87);
    task->wordSet = WORDSET_Create(8, 64, 87);
    task->net = WIFIBATTLEMATCH_NET_CreateNetContext(task->ctx->profileId, params->save->gameData, params->heap, 87);
    task->util = WIFIBATTLEMATCH_UTIL_Create(0, 15, 14, 10, task->printQue, task->font, 87);
    task->callbackA = WIFIBATTLEMATCH_UTIL_CreateCallback(task, WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState, 87);
    task->waitStream = WIFIBATTLEMATCH_UTIL_CreateCallback(task, 0, 87);
    task->actorArray = WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera(task->graphic), task->view, 87);
    WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
    if (params->state != 0) {
        if (params->mode == 0) {
            WIFIBATTLEMATCH_NET_SetupBoxAndWait(task, 0);
        } else if (params->mode == 1) {
            if (params->state == 1)
                WIFIBATTLEMATCH_NET_IncBsubwayStat(params->bsubwaySave, params->save->battleType, params->saveBlock->head);
            WIFIBATTLEMATCH_NET_SetupBoxAndWait(task, 1);
        }
    }
    WIFIBATTLEMATCH_NET_RestartNet(task->net, 1);
    return 1;
}

int WIFIBATTLEMATCH_NET_TaskDestroy(struct Proc *sys,int unused,int unused2,struct WifiBattleMatchNetTask *task)
{
    WIFIBATTLEMATCH_NET_RestartNet(task->net,0);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray(task->actorArray);
    WIFIBATTLEMATCH_UTIL_DeleteCallback(task->waitStream);
    WIFIBATTLEMATCH_UTIL_DeleteCallback(task->callbackA);
    WIFIBATTLEMATCH_UTIL_Delete(task->util);
    if(task->net) WIFIBATTLEMATCH_NET_DeleteNetContext(task->net);
    WIFIBATTLEMATCH_NET_DeleteRegCard(task);
    WIFIBATTLEMATCH_NET_DeleteBoxRecord(task);
    WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
    WORDSET_Delete(task->wordSet);
    MSGDATA_Delete(task->msgBank);
    PRINTSYS_QUE_Delete(task->printQue);
    GF_FONT_Delete(task->font);
    WIFIBATTLEMATCH_VIEW_Delete(task->view);
    WIFIBATTLEMATCH_GRAPHIC_Delete(task->graphic);
    PROCSYS_FreeProcWork(sys);
    GFL_HEAP_DeleteChecked(0x57);
    GF_OVERLAY_Unload((sptr)ov114_id);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return 1;
}

/*
 * Extent tail 021D458A..021D458C is two zero alignment bytes before 021D458C.
 */
int WIFIBATTLEMATCH_NET_TaskMain(unsigned sys,int *state,int unused,struct WifiBattleMatchNetTask *task)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2:
        WIFIBATTLEMATCH_UTIL_InvokeCallback(task->callbackA);
        if(WIFIBATTLEMATCH_UTIL_IsCallbackNull(task->callbackA)) *state=3;
        if(task->net) WIFIBATTLEMATCH_NET_Noop(task->net);
        break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    WIFIBATTLEMATCH_GRAPHIC_Draw(task->graphic);
    PRINTSYS_QUE_Main(task->printQue);
    WIFIBATTLEMATCH_UTIL_Main(task->util);
    WIFIBATTLEMATCH_VIEW_Noop(task->actorArray);
    WIFIBATTLEMATCH_VIEW_UpdateAnimation(task->view);
    if(task->boxWindow) WIFIBATTLEMATCH_VIEW_UpdatePokeList(task->boxWindow,task->printQue);
    if(task->recordWindow) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(task->recordWindow,task->printQue);
    return 0;
}

void WIFIBATTLEMATCH_NET_TaskStepRouteByEntryState(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    switch(params->state) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
    case 1:
        if(params->mode==0) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave);
        else if(params->mode==1) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave);
        break;
    case 3:
        if(params->mode==0) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        else if(params->mode==1) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepMainMenu(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    int result;
    switch (*state) {
    case 0: WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0); *state = 1; break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 25, 1);
        *state = 7; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2); break;
    case 2: WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 1); *state = 3; break;
    case 3:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
            switch (result) {
            case 0: params->mode = 1; WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer); break;
            case 1: params->mode = 0; WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer); break;
            case 2: params->mode = 3; *state = 4; break;
            }
        }
        break;
    case 4:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 30, 1);
        *state = 7; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 5); break;
    case 5: WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0); *state = 6; break;
    case 6:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
            switch (result) {
            case 0: params->netState = 0; WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupB); break;
            case 1: *state = 1; break;
            }
        }
        break;
    case 7: if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingCheckPartyOnServer(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    u32 result;
    switch (*state) {
    case 0:
        if (BLOCK20_SAVEDATA_GetPending((const struct CgearSaveBlock *)GAME_SYNC_GetBlock((struct SaveControl *)(GAME_DATA_GetSaveControl(params->save->gameData))))) *state = 1;
        else *state = 6;
        break;
    case 1: WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 41, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2); break;
    case 2: WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 24, 2); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 3); break;
    case 3: MI_CpuFill8(params->session, 0, 8); WIFIBATTLEMATCH_NET_CreateHttpRap(task->net, 87); *state = 4; break;
    case 4:
        switch (WIFIBATTLEMATCH_NET_HttpRapProcess(task->net)) {
        case 0: break;
        case 1: WIFIBATTLEMATCH_NET_GetRapPair(task->net, (WifibattlematchNetPair *)task->ctx->session); *state = 5; break;
        case 3: MI_CpuFill8(task->ctx->session, 0, 8); WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 2:
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
            case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task); WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
            }
            break;
        }
        break;
    case 5: if (params->session->flag6) *state = 9; else *state = 6; break;
    case 6: WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 55, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12); break;
    case 9:
        WIFIBATTLEMATCH_NET_SetWaitCallback(task, WIFIBATTLEMATCH_NET_TaskStepPostPartyData); *state = 10;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
        case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task); WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 10:
        result = WIFIBATTLEMATCH_NET_PollWaitResult(task);
        if (result == 0) *state = 13;
        else if (result == 1) *state = 11;
        else if (result == 3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
        if (result != 0xffff) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
            case 1: WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task); WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu); break;
            case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
            }
        }
        break;
    case 11: WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 120, 1); *state = 14; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12); break;
    case 12: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupB); break;
    case 13: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord); break;
    case 14: if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    int result;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 24, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1); *state = 11; break;
    case 1:
        if (*params->statPtr == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(task->net, -1, 0, params->statRecord);
            *state = 2;
        }
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_GdbGetMyRecords(task->net);
        if (result == 1) {
            *task->ctx->statPtr = 1800;
            task->statValue = WIFIBATTLEMATCH_NET_GetSetBsubwayStat(params->bsubwaySave, params->save->battleType, task);
            WIFIBATTLEMATCH_NET_CopyBsubwayStat(params->profile, task);
            *task->ctx->recLast = task->ctx->statRecord[21];
            *state = 3;
        }
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                *task->ctx->statPtr = 1800;
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
                *task->ctx->statPtr = 1800;
                break;
            }
        }
        break;
    case 3:
        if (WIFIBATTLEMATCH_NET_GetNetId(task->net) == 0) {
            WIFIBATTLEMATCH_NET_GdbClearRecord(task->net); *state = 4;
        } else *state = 5;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_GdbCreateRecord(task->net);
        if (result == 1) *state = 1;
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                *task->ctx->statPtr = 1800;
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
                *task->ctx->statPtr = 1800;
                break;
            }
        }
        break;
    case 5:
        if (task->boxWindow == 0) *state = 8;
        else if (task->statValue) *state = 6;
        else *state = 10;
        task->statValue = 0;
        break;
    case 6: *state = 7; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsBoxAnimDone(task)) {
            WIFIBATTLEMATCH_NET_DeleteBoxRecord(task); *state = 8;
        }
        break;
    case 8: WIFIBATTLEMATCH_NET_SetupBoxRecord(task, 0); *state = 9; break;
    case 9: if (WIFIBATTLEMATCH_NET_IsBoxReady(task)) *state = 10; break;
    case 10: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake); break;
    case 11: if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

#define CTX(base) ((u32 *)(base)[16])

#define TIMER(base) (*(u32 *)((base) + 0xe0))

#define TIMEOUT(base) (*(u32 *)((base) + 0xe8))

void WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired, fixed;
    char *incoming, *data;
    int bad;
    u32 size;
    u32 buf[4];
    struct MsgBank *bank;
    struct Strbuf *str;
    if (*state >= 2 && *state < 8) enable = 1;
    if (*state < 6 || *state > 7) allow = 1; else allow = 0;
    result = WIFIBATTLEMATCH_NET_HandleCancel(task, enable, allow);
    if (result == 3) {
        *state = 22;
        return;
    }
    switch (*state) {
    case 0:
        task->cancelStep = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 33, 0);
        *state = 1; break;
    case 1:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        WIFIBATTLEMATCH_NET_CopyBoxRecord((u32 *)((u32 *)buf), task);
        WIFIBATTLEMATCH_NET_SetMatchKey(task->net, 2, 1, params->save->battleType, (int *)buf);
        *state = 2; break;
    case 2:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        result = WIFIBATTLEMATCH_NET_StartMatchmaking(task->net);
        if (result == 1) { task->timeout = 0; *state = 3; }
        else if (result == 2) *state = 1;
        break;
    case 3:
        if (result == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData(task->net, params->profile)) { task->timeout = 0; *state = 4; }
            timed = 1;
        }
        break;
    case 4:
        if (WIFIBATTLEMATCH_NET_TakeRegData(task->net, &incoming)) {
            data = (char *)params->record;
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
                MSGDATA_Delete(bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) { data[0x1d] = 0; fixed++; }
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
                fixed++;
            }
            if (!NATION_AREA_IsValidNationArea((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0; fixed++;
            }
            if (!PMSI_PARAM_IsValid((struct PmsData *)(data + 0x38), 0x8057)) { PMSI_PARAM_InitSentence((struct PmsData *)(data + 0x38), 1); fixed++; }
            if (fixed == 0) TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData));
            task->timeout = 0; *state = 5;
        }
        timed = 1; break;
    case 5:
        if (WIFIBATTLEMATCH_NET_VerifyPartySignature(params->record, 0x57)) *state = 6;
        else {
            WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingMatchmake);
        }
        break;
    case 6:
        WIFIBATTLEMATCH_NET_StartProfanityCheck(task->net, params->record, 0x57); *state = 7; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess(task->net, &bad)) {
            *task->ctx->resultPtr = bad; *state = 8;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 8:
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange(task->net, 21); task->timeout = 0; *state = 9;
        }
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(task->net) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange(task->net)) *state = 10;
        timed = 1; break;
    case 10:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(task->net, 22); task->timeout = 0; *state = 11; break;
    case 11:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(task->net)) *state = 12;
        timed = 1; break;
    case 12:
        WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 34, 1);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 13); break;
    case 13:
        if (task->postTimer++ > 120) {
            task->postTimer = 0; WIFIBATTLEMATCH_NET_CreateRegCardWindow(task, params->record); BG_SYS_SetPlaneVisible(0, 0); *state = 14;
        }
        break;
    case 14: if (WIFIBATTLEMATCH_NET_IsRegCardReady(task)) *state = 15; break;
    case 15: if (task->postTimer++ > 0) { task->postTimer = 0; *state = 16; } break;
    case 16:
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        WIFIBATTLEMATCH_NET_SetupMatchReport(task->net, 0, 2, 0, (u32 *)0, 0);
        task->processState = 0;
        task->reportResult = 0;
        *state = 17;
        break;
    case 17:
        if (task->processState == 0) task->processState = WIFIBATTLEMATCH_NET_ScProcess(task->net, (u32 *)(&task->reportResult));
        if (task->processState == 1) *state = 18;
        if (task->processState != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
            case 1: WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 18:
        DWC_RAPCOMMON_DestroySubHeap(); *state = 19; break;
    case 19:
        BG_SYS_SetPlaneVisible(0, 1); WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 36, 2);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 20); break;
    case 20:
        if (task->postTimer++ > 60) { task->postTimer = 0; params->netState = 1; WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys); }
        break;
    case 21:
        WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
        params->state = 2;
        if (task->reportResult != 0) {
            task->reportFlag = 1;
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave);
        } else {
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        }
        break;
    case 22:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 39, 1);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 23); break;
    case 23:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0); *state = 24; break;
    case 24:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result == -1) break;
        WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
        switch (result) {
        case 0: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit); break;
        case 1: *state = 25; break;
        }
        break;
    case 25:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 38, 1);
        *state = 30; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 26); break;
    case 26:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0); *state = 27; break;
    case 27:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result == -1) break;
        WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
        switch (result) {
        case 0: *state = 0; break;
        case 1: *state = 22; break;
        }
        break;
    case 28: if (WIFIBATTLEMATCH_NET_SendSessionQuery(task->net)) *state = 29; break;
    case 29: WIFIBATTLEMATCH_NET_DisconnectWifi(task->net); *state = 0; break;
    case 30: if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
    if (timed) {
        expired = 0;
        if (task->timeout++ > 2400) { task->timeout = 0; expired = 1; }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(task->net)) expired = 1;
        if (expired) *state = 28;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
    }
}

/*
 * DA36C receives the live context in r0 here despite its no-argument body.
 */
void WIFIBATTLEMATCH_NET_TaskStepRatingReportAndSave(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    Rec84 rec;
    void *list;
    int result;
    switch (*state) {
    case 0:
        if (params->state == 2 && task->reportFlag == 0) {
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
            return;
        }
        task->reportFlag = 0;
        GFL_HEAP_CreateChildHeap(1, 0x86, 0x60000);
        DWC_RAPCOMMON_CreateSubHeap(9, 0x60000, 1000, 0x86);
        DWC_RAPCOMMON_SetHeapTag(0x86);
        *state = 1;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 37, 2);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2);
        break;
    case 2:
        WIFIBATTLEMATCH_NET_SetupMatchReport(task->net, 1, 2, params->save->battleType, (u32 *)params->saveBlock, params->state == 2);
        task->processState = 0;
        task->reportResult = 0;
        *state = 3;
        break;
    case 3:
        if (task->processState == 0) {
            task->processState = WIFIBATTLEMATCH_NET_ScProcess(task->net, (u32 *)((u32 *)(&task->reportResult)));
            if (task->processState != 0 && task->reportResult != 0)
                WIFIBATTLEMATCH_UTIL_SetSaveState(params->save->gameData, params->saveBlock->head);
        }
        if (task->processState == 1) {
            params->saveBlock->reportState = WIFIBATTLEMATCH_NET_GetReportState(task->net);
            *state = 4;
        }
        if (task->processState != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
            case 1: WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
            case 2: case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 4:
        DWC_RAPCOMMON_DestroySubHeap();
        if (params->state == 2) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError);
        else *state = 5;
        break;
    case 5:
        list = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData));
        MET_TRAINERS_Insert(list, MYSTATUS_GetId((struct MyStatus *)params->record));
        *state = 6;
        WIFIBATTLEMATCH_NET_ClearCancelFlag(task->net);
        break;
    case 6:
        if (WIFIBATTLEMATCH_NET_StopMatchmaking(task->net)) {
            if (*task->ctx->statPtr == 0) *state = 8;
            else {
                WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 42, 2);
                *state = 14;
                WIFIBATTLEMATCH_UTIL_SetRequest(sys, 7);
            }
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4: *state = 7; break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 7:
        if (*params->statPtr == 0) *state = 8;
        break;
    case 8:
        MI_CpuFill8(&rec, 0, 0x54);
        rec.data = *task->ctx->recData;
        rec.last = *task->ctx->recLast;
        WIFIBATTLEMATCH_NET_SetupGdbUpload(task->net, 3, (struct WifibattlematchNetRecord *)(&rec));
        *state = 9;
        break;
    case 9:
        result = WIFIBATTLEMATCH_NET_GdbUpdateRecord(task->net);
        if (result == 1) {
            *task->ctx->statPtr = 0x708;
            *state = 10;
        }
        if (result != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
                *task->ctx->statPtr = 0x708;
                break;
            case 1:
                *task->ctx->statPtr = 0x708;
                *state = 10;
                break;
            }
        }
        break;
    case 10:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 88, 1);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 11);
        break;
    case 11:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 40, 2);
        *state = 14;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 12);
        break;
    case 12:
        GAME_DATA_SaveStart(params->save->gameData);
        *state = 13;
        break;
    case 13:
        switch (GAME_DATA_SaveMain(params->save->gameData)) {
        case 0: case 1: break;
        case 2: case 3:
            params->netState = 2;
            WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys);
            break;
        }
        break;
    case 14:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingCheckNetError(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    switch(state[0]) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(task->net,0,(void *)1)) {
        case 0: state[0]=1; break;
        case 1: case 4: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry); break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 3: break;
        }
        break;
    case 1: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry); break;
    case 2: if(WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    int result;
    switch (*state) {
    case 0:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 0: case 1: case 4: *state = 1; break;
        case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        case 3: break;
        }
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 0x26, 1);
        *state = 4;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 2);
        break;
    case 2:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0);
        *state = 3;
        break;
    case 3:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingFetchGdbRecord); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit); break;
            }
        }
        break;
    case 4:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepRatingConfirmQuit(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    int result;
    switch(state[0]) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util,task->msgBank,0x27,1);
        state[0]=3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
            switch(result) {
            case 0: WIFIBATTLEMATCH_NET_DisconnectWifi(task->net); WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepRatingAskRetry); break;
            }
        }
        break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
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
void WIFIBATTLEMATCH_NET_TaskStepRatingSaveAndUploadQuit(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 40, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        *state = 7;
        break;
    case 1:
        GAME_DATA_SaveStart(params->save->gameData);
        *state = 2;
        break;
    case 2:
        if (GAME_DATA_SaveMain(params->save->gameData) == 2) *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 37, 2);
        *state = 7;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 4);
        break;
    case 4:
        if (*params->statPtr == 0) {
            WIFIBATTLEMATCH_NET_SetupGdbUpload(task->net, 2, 0);
            *state = 5;
        }
        break;
    case 5:
        if (WIFIBATTLEMATCH_NET_GdbUpdateRecord(task->net)) {
            *task->ctx->statPtr = 0x708;
            *state = 6;
            WIFIBATTLEMATCH_NET_HandleNetError(task->net, (void *)1, 0);
        }
        break;
    case 6:
        WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
        params->netState = 0;
        WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupB);
        break;
    case 7:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeCheckPartyOnServer(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    unsigned int waitResult;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 26, 1);
        WIFIBATTLEMATCH_NET_SetupBoxRecord(task, 1);
        *state = 1;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_IsBoxReady(task)) *state = 2;
        break;
    case 2:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 24, 2);
        *state = 4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_SetWaitCallback(task, WIFIBATTLEMATCH_NET_TaskStepPostPartyData);
        *state = 5;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
            break;
        }
        break;
    case 5:
        waitResult = WIFIBATTLEMATCH_NET_PollWaitResult(task);
        if (waitResult == 0) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake);
        else if (waitResult == 1) *state = 6;
        else if (waitResult == 3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
        if (waitResult != 0xffff) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_NET_DeleteBoxAndWait(task);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu);
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA);
                break;
            }
        }
        break;
    case 6:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 120, 1);
        *state = 7;
        break;
    case 7:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupB);
        break;
    }
}

/*
 * DC1A0's live return is tested here; DA434/DA36C receive the context r0.
 */
void WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    int timed = 0;
    int enable = 0, allow, result, i, empty, expired;
    char *incoming, *data;
    int bad;
    u32 size;
    u32 buf[4];
    struct MsgBank *bank;
    struct Strbuf *str;
    if (*state >= 3 && *state < 13) enable = 1;
    if (*state < 11 || *state > 12) allow = 1; else allow = 0;
    result = WIFIBATTLEMATCH_NET_HandleCancel(task, enable, allow);
    if (result == 3) {
        WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit);
        return;
    }
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_NET_CopyBsubwayStat(params->profile, task); *state = 1; break;
    case 1:
        task->cancelStep = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 33, 0);
        *state = 2; break;
    case 2:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        WIFIBATTLEMATCH_NET_CopyBoxRecord((u32 *)((u32 *)buf), task);
        WIFIBATTLEMATCH_NET_SetMatchKey(task->net, 3, 0, params->save->battleType, (int *)buf);
        *state = 3; break;
    case 3:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepMainMenu);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); return;
        }
        result = WIFIBATTLEMATCH_NET_StartMatchmaking(task->net);
        if (result == 1) { task->timeout = 0; *state = 6; }
        else if (result == 2) *state = 2;
        break;
    case 4: case 5: break;
    case 6:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(task->net, 20); *state = 7; task->timeout = 0; break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(task->net)) { task->timeout = 0; *state = 8; }
        timed = 1; break;
    case 8:
        if (result == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegData(task->net, params->profile)) { task->timeout = 0; *state = 9; }
            timed = 1;
        }
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_TakeRegData(task->net, &incoming)) {
            data = (char *)params->record;
            size = POKE_REGULATION_GetDataSize() + 0xd4;
            MI_CpuCopy8(incoming, data, size);
            empty = 1;
            for (i = 0; i < 8; i++) if (((u16 *)data)[i] == STRBUF_GetEosChar()) empty = 0;
            if (empty) {
                bank = MSGDATA_CreateFromArchive(0, 2, 0xd2, 0x8057);
                str = MSGDATA_AllocString(bank, 0x8057);
                STRBUF_ToChars(str, (u16 *)data, 8);
                STRBUF_Delete(str);
                MSGDATA_Delete(bank);
            }
            if ((u8)data[0x1d] != 0 && (u8)data[0x1d] != 1) data[0x1d] = 0;
            if ((u8)data[0x1c] >= 16) {
                if ((u8)data[0x1d] == 0) data[0x1c] = 0; else data[0x1c] = 8;
            }
            if (!NATION_AREA_IsValidNationArea((u8)data[0x18], (u8)data[0x19], (u8)data[0x1a])) {
                data[0x18] = 0; data[0x19] = 0;
            }
            if (!PMSI_PARAM_IsValid((struct PmsData *)(data + 0x38), 0x8057)) PMSI_PARAM_InitSentence((struct PmsData *)(data + 0x38), 1);
            task->timeout = 0; *state = 10;
        }
        timed = 1; break;
    case 10:
        if (WIFIBATTLEMATCH_NET_VerifyPartySignature(params->record, 0x57)) *state = 11;
        else {
            WIFIBATTLEMATCH_NET_DisconnectWifi(task->net);
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake);
        }
        break;
    case 11:
        WIFIBATTLEMATCH_NET_StartProfanityCheck(task->net, params->record, 0x57); *state = 12; break;
    case 12:
        if (WIFIBATTLEMATCH_NET_ProfanityProcess(task->net, &bad)) {
            *task->ctx->resultPtr = bad; *state = 13;
        }
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 13:
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetTimingSyncRange(task->net, 21); task->timeout = 0; *state = 14;
        }
        break;
    case 14:
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(task->net) == 0 && WIFIBATTLEMATCH_NET_IsTimingSyncRange(task->net)) *state = 15;
        timed = 1; break;
    case 15:
        WIFIBATTLEMATCH_NET_SetTimingSyncRange(task->net, 22); task->timeout = 0; *state = 16; break;
    case 16:
        timed = 1;
        if (WIFIBATTLEMATCH_NET_IsTimingSyncRange(task->net)) *state = 17;
        break;
    case 17:
        WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
        GFL_USE_PlaySeDefaultVolume(0x63a); WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 34, 1);
        *state = 25; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 18); break;
    case 18:
        if (task->postTimer++ > 120) {
            task->postTimer = 0; WIFIBATTLEMATCH_NET_CreateRegCardWindow(task, params->record); BG_SYS_SetPlaneVisible(0, 0); *state = 19;
        }
        break;
    case 19: if (WIFIBATTLEMATCH_NET_IsRegCardReady(task)) *state = 20; break;
    case 20: if (task->postTimer++ > 300) { task->postTimer = 0; *state = 21; } break;
    case 21:
        BG_SYS_SetPlaneVisible(0, 1); WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 36, 2);
        *state = 25; WIFIBATTLEMATCH_UTIL_SetRequest(sys, 22); break;
    case 22:
        if (task->postTimer++ > 60) { task->postTimer = 0; params->netState = 1; WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys); }
        break;
    case 23: if (WIFIBATTLEMATCH_NET_SendSessionQuery(task->net)) *state = 24; break;
    case 24: WIFIBATTLEMATCH_NET_DisconnectWifi(task->net); *state = 1; break;
    case 25: if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
    if (timed) {
        expired = 0;
        if (task->timeout++ > 2400) { task->timeout = 0; expired = 1; }
        if (WIFIBATTLEMATCH_NET_TakeSessionResult(task->net)) expired = 1;
        if (expired) *state = 23;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry);
            WIFIBATTLEMATCH_NET_ClearError(task); return;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(task->actorArray, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
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
void WIFIBATTLEMATCH_NET_TaskStepFreeFinishAndSave(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    void *list;
    switch (*state) {
    case 0:
        if (params->state == 2) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt);
        else *state = 3;
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 43, 2);
        *state = 11;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        task->postTimer = 0;
        break;
    case 1:
        if (WIFIBATTLEMATCH_NET_SendRegValue(task->net, (char *)params->saveBlock + 0x10)) *state = 2;
        break;
    case 2:
        if (WIFIBATTLEMATCH_NET_TakeRegValue(task->net, &params->saveBlock->reportState)) *state = 4;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4: task->postTimer = 0; *state = 7; break;
        case 2: task->postTimer = 0; WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 4:
        list = MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData));
        MET_TRAINERS_Insert(list, MYSTATUS_GetId((struct MyStatus *)params->record));
        WIFIBATTLEMATCH_UTIL_SetSaveState(params->save->gameData, params->saveBlock->head);
        WIFIBATTLEMATCH_NET_ClearCancelFlag(task->net);
        *state = 5;
        break;
    case 5:
        task->postTimer++;
        if (WIFIBATTLEMATCH_NET_StopMatchmaking(task->net)) *state = 6;
        switch (WIFIBATTLEMATCH_NET_HandleNetError(task->net, 0, (void *)1)) {
        case 1: case 4: task->postTimer = 0; *state = 7; break;
        case 2: task->postTimer = 0; WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupA); break;
        }
        break;
    case 6:
        if (task->postTimer++ > 30) { task->postTimer = 0; *state = 7; }
        break;
    case 7:
        *state = 8;
        break;
    case 8:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util, task->msgBank, 40, 2);
        *state = 11;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 9);
        break;
    case 9:
        GAME_DATA_SaveStart(params->save->gameData);
        *state = 10;
        break;
    case 10:
        switch (GAME_DATA_SaveMain(params->save->gameData)) {
        case 0: case 1: break;
        case 2: case 3: params->netState = 2; WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys); break;
        }
        break;
    case 11:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeToRetryPrompt(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    switch(state[0]) {
    case 0: state[0]=1; break;
    case 1: state[0]=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry); break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    int result;
    switch(state[0]) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util,task->msgBank,0x26,1);
        state[0]=3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);
        break;
    case 1: WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0); state[0]=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
            switch(result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit); break;
            }
        }
        break;
    case 3: if(WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskStepFreeConfirmQuit(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    struct WifiBattleMatchParams *params = task->ctx;
    int result;
    switch(*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(task->util,task->msgBank,39,1); *state=5; WIFIBATTLEMATCH_UTIL_SetRequest(sys,1); break;
    case 1: WIFIBATTLEMATCH_NET_SetupChoiceMenu(task, 0); *state=2; break;
    case 2:
        result=WIFIBATTLEMATCH_NET_PollChoiceMenu(task);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteChoiceMenu(task);
            switch(result) {
            case 0: params->netState=0; *state=3; break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskStepFreeAskRetry); break;
            }
        }
        break;
    case 3: WIFIBATTLEMATCH_UTIL_PrintMessage(task->util,task->msgBank,43,2); *state=5; WIFIBATTLEMATCH_UTIL_SetRequest(sys,4); break;
    case 4: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_TaskCleanupB); break;
    case 5: if(WIFIBATTLEMATCH_UTIL_GetBusy(task->util)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_TaskCleanupA(WifibattlematchCallback *obj, int *unused, void *taskArg) {  struct WifiBattleMatchNetTask *task = taskArg;(task->ctx)->netState=3; if(task->net) { WIFIBATTLEMATCH_NET_DeleteNetContext(task->net); task->net=0; } GFL_NET_ERR_WaitLinkClosed(); WIFIBATTLEMATCH_UTIL_ClearCallback((void *)(obj)); }

/*
 * (it is an unlabelled leaf in the overlapping window: ov093/ov170/ov177 hold
 * code or a pool word at that address but none traces a function start), so
 * no evidence class attests it.  Every concrete byte matches; --suggest-split
 * cannot help because the site is a direct `bl` with no second caller.
 */
void WIFIBATTLEMATCH_NET_TaskCleanupB(WifibattlematchCallback *a, int *pp, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    if (*pp != 0)
        return;
    if (task->net != 0) {
        WIFIBATTLEMATCH_NET_DeleteNetContext(task->net);
        task->net = 0;
    }
    WIFIBATTLEMATCH_UTIL_ClearCallback((void *)(a));
}

void WIFIBATTLEMATCH_NET_TaskStepPostPartyData(WifibattlematchCallback *sys, int *state, void *taskArg)
{
    struct WifiBattleMatchNetTask *task = taskArg;
    char *base=*(char * *)&(task->ctx)->profile;
    int result;
    switch(*state) {
    case 0:
        task->postTimer=0;
        MI_CpuFill8(&task->postFlag,0,0x9c);
        (*state)++;
        break;
    case 1:
        WIFIBATTLEMATCH_NET_SetupPostData(task->net,base+0xd4,1);
        (*state)++;
        break;
    case 2:
        result=WIFIBATTLEMATCH_NET_HttpRapPost(task->net,&task->postFlag);
        if(result==1) *state=3;
        else if(result==2) { task->waitResult=2; *state=4; }
        else if(result==3) { task->waitResult=3; *state=4; }
        break;
    case 3:
        if(task->postFlag==0) {
            MI_CpuCopy8(&task->postData[0x1B],base+0x54,0x80);
            task->waitResult=0; *state=4;
        } else { task->waitResult=1; *state=4; }
        break;
    case 4: WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys); break;
    }
}

void WIFIBATTLEMATCH_NET_SetupBoxRecord(struct WifiBattleMatchNetTask *task, u32 mode)
{
    uptr sys;
    int flag; struct Unit *base;
    BoxWindowDesc desc;
    if(task->boxWindow==0) {
        sys=(uptr)GAME_DATA_GetMyStatus(task->ctx->save->gameData);
        base=WIFIBATTLEMATCH_GRAPHIC_GetCamera(task->graphic);
        MI_CpuFill8((void *)&desc,0,20);
        if(mode==0) {
            desc.kind=task->ctx->save->battleType; flag=1;
            desc.count=BSUBWAY_SAVEDATA_GetStat(task->ctx->bsubwaySave,task->ctx->save->battleType+5,0);
            desc.a=BSUBWAY_SAVEDATA_GetStat(task->ctx->bsubwaySave,task->ctx->save->battleType+5,1);
            desc.b=BSUBWAY_SAVEDATA_GetStat(task->ctx->bsubwaySave,task->ctx->save->battleType+5,2);
            desc.total=desc.a+desc.b;
            if(desc.count==0 && desc.total==0) desc.count=1500;
        } else if(mode==1) {
            desc.kind=task->ctx->save->battleType; flag=0; desc.count=0;
            desc.a=BSUBWAY_SAVEDATA_GetStat(task->ctx->bsubwaySave,task->ctx->save->battleType,1);
            desc.b=BSUBWAY_SAVEDATA_GetStat(task->ctx->bsubwaySave,task->ctx->save->battleType,2);
            desc.total=desc.a+desc.b;
        }
        desc.name=MYSTATUS_GetTrainerView((const struct MyStatus *)sys);
        task->boxWindow=WIFIBATTLEMATCH_VIEW_CreateMainWindow((const WifiBattleMatchViewMainInfo *)&desc,flag,(void *)sys,(void *)base,task->view,task->font,task->printQue,task->msgBank,task->wordSet,87);
    }
}

/*
 * Release path for the ov175 object's 0x18 block pointer: free it
 *     through 0x021E5D40 and clear the field.  Null-safe, so a second call is a
 *     no-op.
 */
void WIFIBATTLEMATCH_NET_DeleteBoxRecord(struct WifiBattleMatchNetTask *obj)
{
    struct WifibattlematchViewWork *boxWindow = obj->boxWindow;

    if (boxWindow != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteMainWindow((void *)boxWindow);
        obj->boxWindow = 0;
    }
}

/*
 * Thunk: hands the +0x18 block to 0x021E64C8 and returns its result.  No
 *     lr save anywhere, so the compiler emitted the call as a pooled
 *     `ldr r3; bx r3` tail jump.
 */
u32 WIFIBATTLEMATCH_NET_IsBoxReady(struct WifiBattleMatchNetTask *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindow(obj->boxWindow);
}

/*
 * Thunk: hands the +0x18 block to 0x021E65FC and returns its result, the
 *     poll partner of WIFIBATTLEMATCH_NET_IsBoxReady on the same field.
 */
u32 WIFIBATTLEMATCH_NET_IsBoxAnimDone(struct WifiBattleMatchNetTask *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(obj->boxWindow);
}

void WIFIBATTLEMATCH_NET_SetupBoxAndWait(struct WifiBattleMatchNetTask *obj, u32 arg)
{
    WIFIBATTLEMATCH_NET_SetupBoxRecord(obj, arg);
    while (WIFIBATTLEMATCH_NET_IsBoxReady(obj) == 0)
        ;
}

/*
 * Only when the +0x18 pointer is live: spin on WIFIBATTLEMATCH_NET_IsBoxAnimDone until it
 *     reports ready, then hand the object to the WIFIBATTLEMATCH_NET_DeleteBoxRecord release path.
 */
void WIFIBATTLEMATCH_NET_DeleteBoxAndWait(struct WifiBattleMatchNetTask *obj)
{
    if (obj->boxWindow != 0) {
        while (WIFIBATTLEMATCH_NET_IsBoxAnimDone(obj) == 0)
            ;
        WIFIBATTLEMATCH_NET_DeleteBoxRecord(obj);
    }
}

/*
 * mode: original assigns constructor selectors only for mode 0 or 1.
 */
void WIFIBATTLEMATCH_NET_CreateRegCardWindow(struct WifiBattleMatchNetTask *task,const void *arg)
{
    u32 animB,animA;
    if (task->recordWindow == 0) {
        struct Unit *base = WIFIBATTLEMATCH_GRAPHIC_GetCamera(task->graphic);
        u32 mode = task->ctx->mode;
        if (mode == 0) { animA=1; animB=2; }
        else if (mode == 1) { animA=0; animB=3; }
        task->recordWindow=WIFIBATTLEMATCH_VIEW_CreateRecordWindow((const WifiBattleMatchViewRecord *)arg,base,task->view,task->font,task->printQue,task->msgBank,task->wordSet,animB,animA,0,87);
    }
}

/*
 * Release path for the ov175 object's 0x1c pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void WIFIBATTLEMATCH_NET_DeleteRegCard(struct WifiBattleMatchNetTask *obj)
{
    struct WifiBattleMatchViewRecordWork *recordWindow = obj->recordWindow;

    if (recordWindow != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteRecordWindow((char *)recordWindow);
        obj->recordWindow = 0;
    }
}

/*
 * Unlabelled blocker leaf for WIFIBATTLEMATCH_NET_TaskStepFreeMatchmake; parent confirmed unowned.
 */
int WIFIBATTLEMATCH_NET_IsRegCardReady(struct WifiBattleMatchNetTask *task)
{
    return WIFIBATTLEMATCH_VIEW_StepRecordWindow(task->recordWindow);
}

int WIFIBATTLEMATCH_NET_GetSetBsubwayStat(void *save, u32 kind, struct WifiBattleMatchNetTask *obj)
{
    int *statRecord;
    u32 statA;
    u32 statB;
    u32 statC;
    int changed;
    switch (kind) {
    case 0:
        statRecord = obj->ctx->statRecord;
        statA = statRecord[3];
        statB = statRecord[0x40 / 4];
        statC = statRecord[0x3C / 4];
        break;
    case 1:
        statRecord = obj->ctx->statRecord;
        statA = statRecord[0];
        statB = statRecord[0x28 / 4];
        statC = statRecord[0x24 / 4];
        break;
    case 2:
        statRecord = obj->ctx->statRecord;
        statA = statRecord[0x10 / 4];
        statB = statRecord[0x48 / 4];
        statC = statRecord[0x44 / 4];
        break;
    case 3:
        statRecord = obj->ctx->statRecord;
        statA = statRecord[1];
        statB = statRecord[0x30 / 4];
        statC = statRecord[0x2C / 4];
        break;
    case 4:
        statRecord = obj->ctx->statRecord;
        statA = statRecord[2];
        statB = statRecord[0x38 / 4];
        statC = statRecord[0x34 / 4];
        break;
    }
    changed = (statA != BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)save, kind + 5, 0) || statB != BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)save, kind + 5, 1) || statC != BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)save, kind + 5, 2));
    BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)save, kind + 5, 0, statA);
    BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)save, kind + 5, 1, statB);
    BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)save, kind + 5, 2, statC);
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
void WIFIBATTLEMATCH_NET_IncBsubwayStat(void *a, int b, u32 c)
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

void WIFIBATTLEMATCH_NET_SetupChoiceMenu(struct WifiBattleMatchNetTask *task,int mode)
{
    WifibattlematchMenuDesc desc;
    if (task->menu==0) {
        MI_CpuFill8(&desc,0,sizeof(desc));
        desc.msgBank=task->msgBank; desc.font=task->font; desc.printQue=task->printQue;
        desc.a=0; desc.b=15; desc.c=13; desc.d=1;
        switch(mode) {
        case 0:
            desc.items[0]=31; desc.items[1]=32; desc.count=2;
            desc.enabled=1; desc.kind=1;
            break;
        case 1:
            desc.items[0]=27; desc.items[1]=28; desc.items[2]=29;
            desc.count=3; desc.enabled=1; desc.kind=2;
            break;
        }
        task->menuMode=mode;
        task->menu=WIFIBATTLEMATCH_UTIL_ShowMenu(&desc,87);
    }
}

void WIFIBATTLEMATCH_NET_DeleteChoiceMenu(struct WifiBattleMatchNetTask *obj)
{
    struct WifibattlematchMenu *menu = obj->menu;

    if (menu != 0) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu((struct WifibattlematchMenu *)menu);
        obj->menu = 0;
    }
}

/*
 * Query brother of WIFIBATTLEMATCH_NET_DeleteChoiceMenu: returns the +0x28 block's handler
 *     result through 0x021E8A00, or -1 when the field is empty.
 */
int WIFIBATTLEMATCH_NET_PollChoiceMenu(struct WifiBattleMatchNetTask *obj)
{
    struct WifibattlematchMenu *menu = obj->menu;

    if (menu != 0)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu((struct WifibattlematchMenu *)menu);
    return -1;
}

void WIFIBATTLEMATCH_NET_CopyBoxRecord(void *recordArg, struct WifiBattleMatchNetTask *task)
{
    u32 *record = recordArg;
    struct WifiBattleMatchParams *ctx;
    u32 *stats;
    MI_CpuFill8(record,0,16);
    ctx=task->ctx; stats=(u32 *)ctx->statRecord;
    record[1]=stats[8]; record[2]=0;
    stats=(u32 *)ctx->statRecord;
    record[3]=stats[13]+(stats[14]+(stats[11]+(stats[12]+(stats[17]+(stats[18]+(stats[9]+(stats[10]+(stats[16]+stats[15]))))))));
    switch(ctx->save->battleType) {
    case 0: record[0]=((u32 *)ctx->statRecord)[3]; break;
    case 1: record[0]=((u32 *)ctx->statRecord)[0]; break;
    case 2: record[0]=((u32 *)ctx->statRecord)[4]; break;
    case 3: record[0]=((u32 *)ctx->statRecord)[1]; break;
    case 4: record[0]=((u32 *)ctx->statRecord)[2]; break;
    }
}

void WIFIBATTLEMATCH_NET_CopyBoxSave(void *recordArg, struct WifiBattleMatchNetTask *task)
{
    u32 *record = recordArg;
    struct GameData *save=task->ctx->save->gameData;
    struct SaveControl *profile=GAME_DATA_GetSaveControl(save);
    uptr blob;
    struct WifiBattleMatchParams *ctx;
    record[17]=100;
    blob=(uptr)GAME_DATA_GetMyStatus((void *)save);
    MI_CpuCopy8((void *)blob,record,MYSTATUS_GetSize());
    GREETING_SAVEDATA_GetSentence((struct QuadRecord *)(GREETING_SAVEDATA_GetFromSaveThunk(profile)),0,(struct QuadRecord *)((char *)(record+14)));
    ctx=task->ctx;
    if(ctx->mode==0) {
        record[10]=BSUBWAY_SAVEDATA_GetStat(ctx->bsubwaySave,ctx->save->battleType+5,1);
        ctx=task->ctx;
        record[11]=BSUBWAY_SAVEDATA_GetStat(ctx->bsubwaySave,ctx->save->battleType+5,2);
    } else {
        record[10]=BSUBWAY_SAVEDATA_GetStat(ctx->bsubwaySave,ctx->save->battleType,1);
        ctx=task->ctx;
        record[11]=BSUBWAY_SAVEDATA_GetStat(ctx->bsubwaySave,ctx->save->battleType,2);
    }
    record[18]=WIFILIST_GetGsProfileId((void *)GAME_DATA_GetWifiList((const struct GameData *)save));
}

/*
 * extent: two-byte alignment padding at 021D6786.
 */
void WIFIBATTLEMATCH_NET_CopyBsubwayStat(void *recordArg, struct WifiBattleMatchNetTask *task)
{
    u32 *record = recordArg;
    struct WifiBattleMatchParams *params = task->ctx;
    if (params->mode == 0) {
        record[10] = BSUBWAY_SAVEDATA_GetStat(params->bsubwaySave, params->save->battleType + 5, 1);
        params = task->ctx;
        record[11] = BSUBWAY_SAVEDATA_GetStat(params->bsubwaySave, params->save->battleType + 5, 2);
        params = task->ctx;
        record[13] = BSUBWAY_SAVEDATA_GetStat(params->bsubwaySave, params->save->battleType + 5, 0);
    } else {
        record[10] = BSUBWAY_SAVEDATA_GetStat(params->bsubwaySave, params->save->battleType, 1);
        params = task->ctx;
        record[11] = BSUBWAY_SAVEDATA_GetStat(params->bsubwaySave, params->save->battleType, 2);
    }
}

/*
 * Closes the +0x38 stream handle through 0x021E8AA0 and parks the +0x3c
 *     result word at its "no data" sentinel 0xFFFF.
 */
void WIFIBATTLEMATCH_NET_SetWaitCallback(struct WifiBattleMatchNetTask *obj, WifibattlematchCallbackFn fn)
{
    WIFIBATTLEMATCH_UTIL_SetCallback(obj->waitStream, fn);
    obj->waitResult = 0xFFFF;
}

u32 WIFIBATTLEMATCH_NET_PollWaitResult(struct WifiBattleMatchNetTask *obj)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(obj->waitStream);
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull(obj->waitStream) != 0)
        return obj->waitResult;
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
int WIFIBATTLEMATCH_NET_VerifyPartySignature(void *recordArg, u16 heapId)
{
    char *record=recordArg;
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
        NHTTP_RAP_EvilCheckSetElement(buf,entry,POKE_TOOL_GetPartyParamSize(),i);
    }
    size=POKE_TOOL_GetPartyParamSize();
    ret=NHTTP_RAP_VerifySignature(buf,size,POKEPARTY_GetCount(list),record+0x54,heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}

int WIFIBATTLEMATCH_NET_HandleCancel(struct WifiBattleMatchNetTask *obj, int trigger, int go)
{
    int result;

    switch (obj->cancelStep) {
    case 0:
        if (trigger != 0 && (KEY_GetTrg() & 2))
            obj->cancelStep = obj->cancelStep + 1;
        else return 0;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(obj->util, obj->msgBank, 0x23, 1);
        obj->cancelStep = obj->cancelStep + 1;
        break;
    case 2:
        if (!WIFIBATTLEMATCH_UTIL_GetBusy(obj->util))
            break;
        obj->cancelStep = obj->cancelStep + 1;
        break;
    case 3:
        WIFIBATTLEMATCH_NET_SetupChoiceMenu(obj, 0);
        obj->cancelStep = obj->cancelStep + 1;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_PollChoiceMenu(obj);
        if (result == -1)
            break;
        WIFIBATTLEMATCH_NET_DeleteChoiceMenu(obj);
        switch (result) {
        case 0:
            obj->cancelStep = 5;
            break;
        case 1:
            WIFIBATTLEMATCH_UTIL_PrintMessage(obj->util, obj->msgBank, 0x21, 0);
            obj->cancelStep = 0;
            return 2;
        }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage(obj->util, obj->msgBank, 0x2b, 2);
        obj->cancelStep = obj->cancelStep + 1;
        break;
    case 6:
        if (go == 0)
            break;
        WIFIBATTLEMATCH_NET_SendSessionQuery(obj->net);
        obj->cancelStep = obj->cancelStep + 1;
        WIFIBATTLEMATCH_VIEW_SetActorVisible(obj->actorArray, 0);
        WIFIBATTLEMATCH_NET_DisconnectWifi(obj->net);
        if (!GFL_NET_ERR_GetErrorLevel() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        obj->cancelStep = 0;
        return 3;
    }
    return 1;
}

/*
 * Clears the word at +0xe4 (the last-read length) and then tail-calls the
 *     +0x28 release path WIFIBATTLEMATCH_NET_DeleteChoiceMenu, which is why nothing is saved.
 */
void WIFIBATTLEMATCH_NET_ClearError(struct WifiBattleMatchNetTask *obj)
{
    obj->cancelStep = 0;
    WIFIBATTLEMATCH_NET_DeleteChoiceMenu(obj);
}

/*
 * PROCSYS_AllocProcWork's r0 is read after the call, requiring a returning declaration.
 */
int WIFIBATTLEMATCH_NET_CompCreate(void *sys,int unused,struct WifiBattleMatchParams *params)
{
    struct WifiBattleMatchCompWork *comp;
    GF_OVERLAY_Load((sptr)ov067_id); GF_OVERLAY_Load((sptr)ov114_id);
    GFL_HEAP_CreateChildHeap(1,87,0x30000);
    comp=PROCSYS_AllocProcWork(sys,sizeof(*comp),87); MI_CpuFill8(comp,0,sizeof(*comp));
    comp->ctx=params;
    comp->card=REGULATION_GetCard((struct RegulationCard *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(params->save->gameData)))),0);
    comp->sprite=WIFIBATTLEMATCH_GRAPHIC_Create(1,87);
    comp->anim=WIFIBATTLEMATCH_VIEW_Create(WIFIBATTLEMATCH_GRAPHIC_GetCamera(comp->sprite),0,87);
    comp->font=GF_FONT_Create(0x17,0,0,0,87);
    comp->fontAlt=GF_FONT_Create(0x17,3,0,0,87);
    comp->printQue=PRINTSYS_QUE_Create(87); comp->msgBank=MSGDATA_CreateFromArchive(0,2,0xd2,87);
    comp->wordSet=WORDSET_Create(8,0x40,87);
    comp->net=WIFIBATTLEMATCH_NET_CreateNetContext(comp->ctx->profileId,params->save->gameData,params->heap,87);
    comp->textObj=WIFIBATTLEMATCH_UTIL_Create(0, 15, 14, 10, comp->printQue, comp->font, 87);
    comp->proc2=WIFIBATTLEMATCH_UTIL_CreateCallback(comp, WIFIBATTLEMATCH_NET_CompStepRouteByEntryState,87);
    comp->waitStream=WIFIBATTLEMATCH_UTIL_CreateCallback(comp, 0,87);
    comp->animMgr=WIFIBATTLEMATCH_VIEW_CreateActorArray((void *)WIFIBATTLEMATCH_GRAPHIC_GetCamera(comp->sprite),comp->anim,87);
    WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr,0);
    comp->party=POKEPARTY_Create(87); WIFIBATTLEMATCH_NET_RestartNet(comp->net,1);
    return 1;
}

int WIFIBATTLEMATCH_NET_CompDestroy(struct Proc *sys,u32 unused,u32 arg,struct WifiBattleMatchCompWork *comp)
{
    GFL_HEAP_Free(comp->party);
    WIFIBATTLEMATCH_NET_RestartNet(comp->net,0);
    WIFIBATTLEMATCH_VIEW_DeleteActorArray(comp->animMgr);
    WIFIBATTLEMATCH_UTIL_DeleteCallback(comp->waitStream); WIFIBATTLEMATCH_UTIL_DeleteCallback(comp->proc2);
    WIFIBATTLEMATCH_UTIL_Delete(comp->textObj);
    if(comp->net) WIFIBATTLEMATCH_NET_DeleteNetContext(comp->net);
    WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(comp); WIFIBATTLEMATCH_NET_DeleteCompRegCard(comp); WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(comp); WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
    WORDSET_Delete(comp->wordSet); MSGDATA_Delete(comp->msgBank);
    PRINTSYS_QUE_Delete(comp->printQue); GF_FONT_Delete(comp->fontAlt); GF_FONT_Delete(comp->font);
    WIFIBATTLEMATCH_VIEW_Delete(comp->anim); WIFIBATTLEMATCH_GRAPHIC_Delete(comp->sprite);
    PROCSYS_FreeProcWork(sys); GFL_HEAP_DeleteChecked(87);
    GF_OVERLAY_Unload((sptr)ov114_id); GF_OVERLAY_Unload((sptr)ov067_id);
    return 1;
}

int WIFIBATTLEMATCH_NET_CompMain(unsigned sys,int *state,int unused,struct WifiBattleMatchCompWork *comp)
{
    switch(*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if(FADE_IsActive()==0) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_InvokeCallback(comp->proc2); if(WIFIBATTLEMATCH_UTIL_IsCallbackNull(comp->proc2)) *state=3; break;
    case 3: FADE_Start(3,0,16,0); *state=4; break;
    case 4: if(FADE_IsActive()==0) return 1; break;
    }
    WIFIBATTLEMATCH_GRAPHIC_Draw(comp->sprite); PRINTSYS_QUE_Main(comp->printQue); WIFIBATTLEMATCH_UTIL_Main(comp->textObj);
    WIFIBATTLEMATCH_VIEW_Noop(comp->animMgr); WIFIBATTLEMATCH_VIEW_UpdateAnimation(comp->anim); WIFIBATTLEMATCH_NET_Noop(comp->net);
    if(comp->tradeIcon) WIFIBATTLEMATCH_VIEW_UpdatePokeList(comp->tradeIcon,comp->printQue);
    if(comp->regCard) WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(comp->regCard,comp->printQue);
    if(comp->window) WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(comp->window,comp->printQue);
    return 0;
}

void WIFIBATTLEMATCH_NET_CompStepRouteByEntryState(WifibattlematchCallback *sys, int *unused, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    switch (comp->ctx->state) {
    case 0: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepFetchRapPair); break;
    case 2:
        WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
    case 1:
        WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(comp);
        WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult);
        break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(comp); WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle); break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepFetchRapPair(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *ctx = comp->ctx;
    int result;
    switch(*state) {
    case 0:
        if(BLOCK20_SAVEDATA_GetPending((const struct CgearSaveBlock *)GAME_SYNC_GetBlock((struct SaveControl *)(GAME_DATA_GetSaveControl(ctx->save->gameData))))) *state=1;
        else *state=5;
        break;
    case 1: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x36,2); *state=2; break;
    case 2: MI_CpuFill8(ctx->session,0,8); WIFIBATTLEMATCH_NET_CreateHttpRap(comp->net,87); *state=3; break;
    case 3:
        result=WIFIBATTLEMATCH_NET_HttpRapProcess(comp->net);
        if(result==1) { WIFIBATTLEMATCH_NET_GetRapPair(comp->net, (WifibattlematchNetPair *)comp->ctx->session); *state=4; }
        else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        else if(result!=0) {
            result=WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0);
            switch(result) {case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup); break;}
        }
        break;
    case 4: if(ctx->session->flag6) *state=7; else *state=5; break;
    case 5: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x37,1); *state=6; break;
    case 6: if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj)) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompExit); break;
    case 7: if(*ctx->statPtr==0) {WIFIBATTLEMATCH_NET_ClearErrorFlags(comp->net); *state=8;} break;
    case 8:
        result=WIFIBATTLEMATCH_NET_StepGdbEnsureRecord(comp->net);
        if(result==1) { *comp->ctx->statPtr=0x708; *state=9; }
        if(result!=0) {
            result=WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0);
            switch(result) {case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup); break;}
        }
        break;
    case 9: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepReconcileEntryState); break;
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
#define COMP_PARAMS(base) ((base)->ctx)

void WIFIBATTLEMATCH_NET_CompStepReconcileEntryState(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
#ifdef __MWERKS__
    enum { CTX_OFFSET=0x104 } offset=CTX_OFFSET;
    struct RegulationCard *aux=*(struct RegulationCard **)((char *)comp+(offset+4));
    struct WifiBattleMatchParams *ctx=*(struct WifiBattleMatchParams **)((char *)comp+offset);
#else
    struct RegulationCard *aux=comp->card;
    struct WifiBattleMatchParams *ctx=comp->ctx;
#endif
    int result;
    unsigned char regState;
    u32 tmp; uptr save, party;
    void *box;
    WifibattlematchNetRequest request1,request7,request40;
    switch(*state) {
    case 0: if(ctx->session->flag4==1) *state=1; else *state=3; break;
    case 1: {
        MI_CpuFill8(&request1,0,8); request1.b=0; request1.a=COMP_PARAMS(comp)->session->flag4;
        request1.id=WIFIBATTLEMATCH_NET_GetGsProfileId(comp->net); COMP_PARAMS(comp)->session->subState=0;
        WIFIBATTLEMATCH_NET_SetupHttpRap(comp->net, (const W *)&request1, 87); *state=2; break;
    }
    case 2:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(comp->net);
        if(result==1) *state=11; else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        if(result!=0) switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)) {case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 3:
        if(COMP_PARAMS(comp)->session->subState==REGULATION_Card_GetValue(aux,10)) *state=4;
        else if(REGULATION_Card_GetValue(aux,10)==4 || REGULATION_Card_GetValue(aux,10)==5) *state=7;
        else *state=4;
        break;
    case 4:
        regState=ctx->session->subState;
        if(regState==3) *state=5; else if((unsigned char)(regState+0xfc)<=1) *state=6; else *state=11; break;
    case 5:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x39,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,46);*state=56;break;
    case 6:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x39,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,46);*state=56;break;
    case 7: {
        MI_CpuFill8((void *)&request7,0,8); request7.b=REGULATION_Card_GetValue(aux,10); request7.id=WIFIBATTLEMATCH_NET_GetGsProfileId(comp->net);
        COMP_PARAMS(comp)->session->subState=REGULATION_Card_GetValue(aux,10);
        WIFIBATTLEMATCH_NET_SetupHttpRap(comp->net, (const W *)&request7, 87);*state=8;break;
    }
    case 8:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(comp->net);if(result==1)*state=9;else if(result==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 9:*state=6;break;
    case 10:
        result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(comp->net);if(result==1){*(u32 *)COMP_PARAMS(comp)->statPtr=0x708;*state=6;}
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 11:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x5b,2);WIFIBATTLEMATCH_UTIL_SetRequest(sys,12);*state=56;break;
    case 12:WIFIBATTLEMATCH_NET_SetupDownload(comp->net,*(u32 *)ctx->session);*state=13;break;
    case 13:
        result=WIFIBATTLEMATCH_NET_DownloadProcess(comp->net);
        if(result==1){WIFIBATTLEMATCH_NET_GetRegCardName(comp->net,comp->cardRecord);if(REGULATION_Card_IsCrcValid((struct RegulationCard *)((struct BattleCompetitionSave *)(comp->cardRecord))))*state=14;else *state=15;}
        else if(result==2)*state=15;
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 15:if(REGULATION_Card_GetValue(aux,2)==0)*state=18;else *state=16;break;
    case 16:
        result=WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0);
        switch(result){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;case 0:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepCheckPeriod);*state=17;break;}break;
    case 17:
        result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);if(result!=0xffff)*state=46;if(result==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 18:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3b,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,55);*state=56;break;
    case 14:
        regState=ctx->session->subState;if(regState==0)*state=19;else if(regState==1)*state=53;else if(regState==2)*state=54;else *state=55;break;
    case 19:if(REGULATION_Card_GetValue(aux,2)==0)*state=42;else *state=20;break;
    case 20:
        WIFIBATTLEMATCH_NET_SetupCompStatusWindow(comp);
        if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl(ctx->save->gameData)),1))WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,0);else WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,1);
        *state=21;break;
    case 21:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp))*state=22;break;
    case 22:if(BATTLE_BOX_IsLocked(BATTLE_BOX_GetFromSave((void *)GAME_DATA_GetSaveControl(ctx->save->gameData)),1))*state=23;else *state=29;break;
    case 23:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3d,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,24);*state=56;break;
    case 24:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);*state=25;break;
    case 25:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=35;break;case 1:*state=26;break;}}break;
    case 26:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3e,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,27);*state=56;break;
    case 27:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);*state=28;break;
    case 28:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=55;break;case 1:*state=23;break;}}break;
    case 29:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3c,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,30);*state=56;break;
    case 30:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);*state=31;break;
    case 31:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=35;break;case 1:*state=32;break;}}break;
    case 32:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3e,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,33);*state=56;break;
    case 33:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);*state=34;break;
    case 34:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);if(result!=-1){WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);switch(result){case 0:*state=55;break;case 1:*state=29;break;}}break;
    case 35:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(comp))*state=36;break;
    case 36:WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(comp);*state=42;break;
    case 37:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x46,2);WIFIBATTLEMATCH_UTIL_SetRequest(sys,38);*state=56;break;
    case 38:if(*(u32 *)ctx->statPtr==0){MI_CpuFill8((void *)((char *)ctx->sub+0x18),0,0x534);WIFIBATTLEMATCH_NET_SetupGdbUpload(comp->net,0,(void *)((char *)COMP_PARAMS(comp)->sub+0x18));*state=39;}break;
    case 39:
        result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(comp->net);if(result==1){*(u32 *)COMP_PARAMS(comp)->statPtr=0x708;*state=40;}
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 40:{
        MI_CpuFill8(&request40,0,8);request40.a=0;request40.b=1;request40.id=WIFIBATTLEMATCH_NET_GetGsProfileId(comp->net);
        COMP_PARAMS(comp)->session->subState=1;WIFIBATTLEMATCH_NET_SetupHttpRap(comp->net, (const W *)&request40, 87);*state=41;break;
    }
    case 41:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(comp->net);if(result==1)*state=53;else if(result==3)WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 42:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3a,2);WIFIBATTLEMATCH_UTIL_SetRequest(sys,43);*state=56;break;
    case 43:
        save=(uptr)GAME_DATA_GetSaveControl(ctx->save->gameData);box=BATTLE_BOX_GetFromSave((void *)save);
        party=(uptr)REGULATION_GetParty((struct BattleCompetitionSave *)BATTLE_COMPETITION_GetFromSave((struct SaveControl *)((void *)save)),0);
        MI_CpuCopy8((const void *)(comp->cardRecord),comp->card,0x160);
        BATTLE_BOX_ClearLockFlags((struct BattleBoxSave *)box,1);REGULATION_Card_SetValue(comp->card,10,1);
        BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)((BsubwayStatRow *)ctx->bsubwaySave),10,0,0);BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)((BsubwayStatRow *)ctx->bsubwaySave),10,1,0);BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)((BsubwayStatRow *)ctx->bsubwaySave),10,2,0);
        REGULATION_InitParty((struct RegulationParty *)party);GAME_DATA_SaveStart(ctx->save->gameData);*state=44;break;
    case 44:result=GAME_DATA_SaveMain(ctx->save->gameData);if(result==2)*state=37;else if(result==3)*state=45;break;
    case 45:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x40,1);WIFIBATTLEMATCH_UTIL_SetRequest(sys,55);*state=56;break;
    case 46:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x5a,2);WIFIBATTLEMATCH_UTIL_SetRequest(sys,47);*state=56;break;
    case 47:if(*(u32 *)ctx->statPtr==0){WIFIBATTLEMATCH_NET_GdbRequest(comp->net,-1,1,ctx->sub);*state=48;}break;
    case 48:
        result=WIFIBATTLEMATCH_NET_GdbGetMyRecords(comp->net);if(result==1){*(u32 *)COMP_PARAMS(comp)->statPtr=0x708;*state=49;}
        if(result!=0)switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0)){case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}break;
    case 49:if(COMP_PARAMS(comp)->sub->keyA!=BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)ctx->bsubwaySave,10,0))*state=50;else *state=55;break;
    case 50:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x3a,2);WIFIBATTLEMATCH_UTIL_SetRequest(sys,51);*state=56;break;
    case 51:WIFIBATTLEMATCH_NET_GetSetCompStat(comp,(void *)ctx->sub);GAME_DATA_SaveStart(ctx->save->gameData);*state=52;break;
    case 52:if(GAME_DATA_SaveMain(ctx->save->gameData)==2)*state=55;break;
    case 53:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepRegisterParty);break;
    case 54:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);break;
    case 55:ctx->netState=0;WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompExit);break;
    case 56:if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}
#undef COMP_PARAMS

#undef W

#define W(base, k) (*(u32 *)((base) + (k)))

void WIFIBATTLEMATCH_NET_CompStepRegisterParty(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *ctx = comp->ctx;
    int result,index,count,empty;
    char *record;
    void *box;
    u32 mask; uptr save, party;
    WifibattlematchNetRequest request;
    switch(*state) {
    case 0: WIFIBATTLEMATCH_NET_SetupCompStatusWindow(comp); WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,2); WIFIBATTLEMATCH_NET_SetupCompPartyWindow(comp); *state=1; break;
    case 1: result=1; result &= WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp); result &= WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(comp); if(result) *state=2; break;
    case 2: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x41,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,3); *state=30; break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp,2); *state=4; break;
    case 4: result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp); if(result!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) {case 0:*state=12;break;case 1:*state=5;break;}} break;
    case 5: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x44,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,6); *state=30; break;
    case 6: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp,0); *state=7; break;
    case 7: result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp); if(result!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) {case 0:*state=8;break;case 1:*state=2;break;}} break;
    case 8: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x45,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,9); *state=30; break;
    case 9: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp,0); *state=10; break;
    case 10: result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp); if(result!=-1) {WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) {case 0:*state=11;break;case 1:*state=2;break;}} break;
    case 11: if(WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(comp)) {WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(comp); *state=29;} break;
    case 12:
        record=(char *)ctx->profile; WIFIBATTLEMATCH_NET_CopyCompBox((struct WifiBattleMatchStatRecord *)record,comp);
        if(POKEPARTY_GetBattleReadyCount((struct Party *)(record+0xd4))==0) *state=14;
        else {mask=0; if(POKE_REGULATION_CheckParty((const struct Regulation *)((void *)REGULATION_NoOp(comp->card)),(struct Party *)(record+0xd4),(u32 *)&mask)==0) *state=15; else *state=13;}
        break;
    case 13: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x49,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 14: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x61,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 15: if(WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(comp)) {WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(comp); *state=16;} break;
    case 16: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x46,2); WIFIBATTLEMATCH_UTIL_SetRequest(sys,17); *state=30; break;
    case 17:
        WIFIBATTLEMATCH_NET_SetupPostData(comp->net,(ctx->profile+0xd4),1);
        MI_CpuFill8(&comp->responseFlag,0,0x9c); *state=18; break;
    case 18:
        result=WIFIBATTLEMATCH_NET_HttpRapPost(comp->net,(u8 *)(&comp->responseFlag));
        if(result==1) {
            count=POKEPARTY_GetCount((const struct Party *)((ctx->profile+0xd4))); empty=0;
            for(index=0;index<count;index++) if(((u32 *)comp->pad_48)[index]==0) empty++;
            if(comp->responseFlag==0 && empty==count) *state=20; else *state=19;
        } else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 19: WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x47,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,29); *state=30; break;
    case 20: if(*ctx->statPtr==0) {WIFIBATTLEMATCH_NET_SetupGdbUpload(comp->net,0,(struct WifibattlematchNetRecord *)(ctx->profile+0xd4));*state=21;} break;
    case 21:
        result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(comp->net);
        if(result==1) {*comp->ctx->statPtr=0x708; *state=22;}
        if(result!=0) switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;}
        break;
    case 22:
        save=(uptr)GAME_DATA_GetSaveControl(ctx->save->gameData); box=BATTLE_BOX_GetFromSave((void *)save);
        party=(uptr)REGULATION_GetParty((struct BattleCompetitionSave *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)((void *)save))),0);
        save=(uptr)BATTLE_BOX_CreateParty((struct BoxMonGroup *)box,0x8056); BATTLE_BOX_SetLockFlags((struct BattleBoxSave *)box, 1);
        REGULATION_Card_SetValue(comp->card,10,2); REGULATION_BuildParty((struct RegulationParty *)party,(struct Party *)save); GFL_HEAP_Free((void *)save);
        *state=23; break;
    case 23: GAME_DATA_SaveStart(ctx->save->gameData); *state=24; break;
    case 24: result=GAME_DATA_SaveMain(ctx->save->gameData); if(result==2) *state=25; else if(result==3) *state=29; break;
    case 25:
        MI_CpuFill8(&request,0,8); request.b=2; request.id=WIFIBATTLEMATCH_NET_GetGsProfileId(comp->net);
        comp->ctx->session->subState=2;
        WIFIBATTLEMATCH_NET_SetupHttpRap(comp->net,(const W *)&request,87); *state=26; break;
    case 26:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(comp->net); if(result==1) *state=27; else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {case 1:*state=0;break;case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;} break;
    case 27: WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,0); WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,0x48,1); WIFIBATTLEMATCH_UTIL_SetRequest(sys,28); *state=30; break;
    case 28: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu); break;
    case 29: ctx->netState=0; WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit); break;
    case 30: if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepMainMenu(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *params = comp->ctx;
    int result;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {
        case 0:*state=1;break;
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:if(comp->tradeIcon==0) {
            WIFIBATTLEMATCH_NET_SetupCompStatusWindow(comp);WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,0);*state=2;
        } else *state=3;
        break;
    case 2:if(WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp)) *state=3;break;
    case 3:BG_SYS_SetPlaneVisible(0,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,74,1);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);*state=16;break;
    case 4:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 3);*state=5;break;
    case 5:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch(result) {
            case 0:*state=10;break;
            case 1:*state=7;break;
            case 2:*state=6;break;
            }
        }break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepConfirmQuit);break;
    case 7:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepWithdrawEntry);*state=8;break;
    case 8:result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if(result==1 || result==2) *state=1;
        else if(result==0) *state=9;
        else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 9:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 10:WIFIBATTLEMATCH_NET_CopyCompBox((struct WifiBattleMatchStatRecord *)params->profile,comp);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,24,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,11);*state=16;break;
    case 11:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepPostPartyData);*state=12;break;
    case 12:result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if(result==0) *state=13;
        else if(result==1) *state=13;
        else if(result==3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {
        case 1:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 13:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMatchmake);break;
    case 14:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,120,1);
        *state=16;WIFIBATTLEMATCH_UTIL_SetRequest(sys,15);break;
    case 15:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 16:if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
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
void WIFIBATTLEMATCH_NET_CompStepMatchmake(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
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
    sptr i;
    struct RegulationCard *cardPtr;
    int trig = 0;
    u8 *record;
    void *msg;

    w18 = comp->ctx;
    flag = 0;
    stepState = *state;
    if (stepState >= 0xc && stepState < 0x1b)
        trig = 1;
    res = WIFIBATTLEMATCH_NET_CompHandleCancel(comp, trig,
                        !((stepState >= 0x19 && stepState <= 0x1a) || (stepState >= 0x11 && stepState <= 0x12)));
    if (res == 3) {
        *state = 0x28;
        return;
    }

    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x18, 2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        *state = 0x35;
        break;
    case 1:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 2;
            break;
        }
        break;
    case 2:
        i = WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if (i == 0)
            *state = 4;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 3:
        WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);
        break;
    case 4:
        if (*comp->ctx->statPtr == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(comp->net, -1, 1, comp->ctx->sub);
            *state = 5;
        }
        break;
    case 5:
        i = WIFIBATTLEMATCH_NET_GdbGetMyRecords(comp->net);
        if (i == 1) {
            record = w18->profile;
            *comp->ctx->statPtr = 0;
            WIFIBATTLEMATCH_NET_CopyCompSave((struct WifiBattleMatchStatRecord *)record, comp);
            *comp->ctx->recLast = comp->ctx->sub->recSeed;
            if (WIFIBATTLEMATCH_NET_GetSetCompStat(comp, comp->ctx->sub) != 0)
                *state = 6;
            else
                *state = 0xa;
        }
        if (i != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
            case 1:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);
                WIFIBATTLEMATCH_NET_CompClearError(comp);
                break;
            case 2:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 6:
        *state = 7;
        break;
    case 7:
        if (WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(comp) != 0) {
            WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(comp);
            *state = 8;
        }
        break;
    case 8:
        WIFIBATTLEMATCH_NET_SetupCompStatusWindow(comp);
        *state = 9;
        break;
    case 9:
        if (WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(comp) != 0)
            *state = 0xa;
        break;
    case 0xa:
        comp->stepCounter = 0;
        WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x55, 0);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0xb);
        break;
    case 0xb:
        cardPtr = comp->card;
        MI_CpuFill8((void *)&buf, 0, sizeof(buf));
        buf.keyA = comp->ctx->sub->keyA;
        buf.keyB = comp->ctx->sub->keyB;
        buf.keyC = REGULATION_Card_GetValue(cardPtr, 2);
        buf.keyD = comp->ctx->sub->keyDBase + comp->ctx->sub->keyDDelta;
        WIFIBATTLEMATCH_NET_SetMatchKey(comp->net, 0, 0, w18->save->battleType, (int *)(&buf));
        comp->regFlag = 0;
        comp->timeout = 0;
        *state = 0xc;
        break;
    case 0xc:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
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
            if (WIFIBATTLEMATCH_NET_SendRegData(comp->net, w18->profile) != 0) {
                *state = 0xe;
                comp->rapFlag = 0;
            }
        } else {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
            case 4:
                comp->stepCounter = 0;
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
                WIFIBATTLEMATCH_NET_CompClearError(comp);
                break;
            case 2:
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
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
                PMSI_PARAM_InitSentence((struct PmsData *)(record + 0x38), 1);
                bad++;
            }
            if (bad == 0)
                TRADE_HISTORY_GetFromSave(GAME_DATA_GetSaveControl(w18->save->gameData));
            *state = 0xf;
        }
        flag = 1;
        break;
    case 0xf:
        TouchParty(w18->profile, b28);
        TouchParty(w18->record, b20);
        if (((struct WifiBattleMatchStatRecord *)w18->profile)->cardValue == ((struct WifiBattleMatchStatRecord *)w18->record)->cardValue
            && ((struct WifiBattleMatchStatRecord *)w18->profile)->crc == ((struct WifiBattleMatchStatRecord *)w18->record)->crc)
            *state = 0x10;
        else
            *state = 0x33;
        break;
    case 0x10:
        mask = 0;
        if (POKE_REGULATION_CheckParty((const struct Regulation *)((void *)REGULATION_NoOp(comp->card)), (struct Party *)(w18->record + 0xd4), (u32 *)&mask) == 0) {
            *state = 0x11;
        } else {
            comp->regFlag++;
            *state = 0x16;
        }
        break;
    case 0x11:
        if (*comp->ctx->statPtr == 0) {
            WIFIBATTLEMATCH_NET_GdbRequest(comp->net, ((struct WifiBattleMatchStatRecord *)comp->ctx->record)->netId, 3, comp->party);
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
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
                WIFIBATTLEMATCH_NET_CompClearError(comp);
                break;
            case 2:
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
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
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
        break;
    case 0x15:
        if (WIFIBATTLEMATCH_NET_CompareParty(comp->party, (struct Party *)(comp->ctx->record + 0xd4)) == 0)
            comp->regFlag++;
        if (WIFIBATTLEMATCH_NET_VerifyCompSignature(comp->ctx->record, comp->ctx->record + 0xd4, 0x57) == 0)
            comp->regFlag++;
        *state = 0x16;
        break;
    case 0x16:
        if (res == 0) {
            if (WIFIBATTLEMATCH_NET_SendRegFlag(comp->net, &comp->regFlag) != 0) {
                *state = 0x17;
                comp->rapFlag = 0;
            }
        } else {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
            case 4:
                comp->stepCounter = 0;
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
                WIFIBATTLEMATCH_NET_CompClearError(comp);
                break;
            case 2:
                WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x17:
        if (WIFIBATTLEMATCH_NET_TakeRegFlag(comp->net, &comp->timeout) != 0)
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
        WIFIBATTLEMATCH_NET_StartProfanityCheck(comp->net, w18->record, 0x57);
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
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
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
        WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
        GFL_USE_PlaySeDefaultVolume(0x63a);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x57, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x20);
        comp->timer = 0;
        break;
    case 0x20:
        if (comp->timer++ > 0x78) {
            comp->timer = 0;
            BG_SYS_SetPlaneVisible(0, 0);
            WIFIBATTLEMATCH_NET_StartRegCardAnim(comp, (const WifiBattleMatchViewRecord *)w18->record);
            *state = 0x21;
        }
        break;
    case 0x21:
        if (WIFIBATTLEMATCH_NET_IsCompRegCardReady(comp) != 0)
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
            comp->reportResult = WIFIBATTLEMATCH_NET_ScProcess(comp->net, (u32 *)(&comp->reportState));
        if (comp->reportResult == 1)
            *state = 0x25;
        if (comp->reportResult != 0) {
            switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, (void *)1)) {
            case 1:
                WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
            case 2:
            case 4:
                DWC_RAPCOMMON_DestroySubHeap();
                WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
                break;
            }
        }
        break;
    case 0x25:
        DWC_RAPCOMMON_DestroySubHeap();
        BG_SYS_SetPlaneVisible(0, 1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x24, 2);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x26);
        break;
    case 0x26:
        if (comp->timer++ > 0x3c) {
            comp->timer = 0;
            w18->netState = 1;
            WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys);
        }
        break;
    case 0x27:
        WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
        WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
        w18->state = 2;
        comp->gdbFlag = 1;
        if (comp->reportState != 0)
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult);
        else
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
        break;
    case 0x28:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x4e, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x29);
        break;
    case 0x29:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);
        *state = 0x2a;
        break;
    case 0x2a:
        i = WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if (i != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch (i) {
            case 0:
                WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit);
                break;
            case 1:
                *state = 0x2b;
                break;
            }
        }
        break;
    case 0x2b:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x26, 1);
        *state = 0x35;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 0x2c);
        break;
    case 0x2c:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);
        *state = 0x2d;
        break;
    case 0x2d:
        i = WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if (i != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
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
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 0x30;
            break;
        }
        break;
    case 0x30:
        i = WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if (i == 0)
            *state = 0xa;
        else if (i == 1 || i == 2)
            *state = 3;
        else if (i == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMainMenu);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
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
        if (WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj) != 0)
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
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);
            WIFIBATTLEMATCH_NET_CompClearError(comp);
            break;
        case 2:
            WIFIBATTLEMATCH_VIEW_SetActorVisible(comp->animMgr, 0);
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
            break;
        }
    }
}

void WIFIBATTLEMATCH_NET_CompStepReportAndUploadResult(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *params = comp->ctx;
    Rec84 rec;
    void *list;
    int result;
    switch(*state) {
    case 0:if(params->state==2 && comp->gdbFlag==0) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle);
        else {
            comp->gdbFlag=0;
            GFL_HEAP_CreateChildHeap(1,134,0x60000);
            DWC_RAPCOMMON_CreateSubHeap(9,0x60000,1000,134);
            DWC_RAPCOMMON_SetHeapTag(134);*state=1;
        }break;
    case 1:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,70,2);
        *state=13;WIFIBATTLEMATCH_UTIL_SetRequest(sys,2);break;
    case 2:WIFIBATTLEMATCH_NET_SetupMatchReport(comp->net, 1, 0, params->save->battleType, (u32 *)params->saveBlock, params->state==2);
        comp->reportResult=0;comp->reportState=0;*state=3;break;
    case 3:
        if(comp->reportResult==0) {
            comp->reportResult=WIFIBATTLEMATCH_NET_ScProcess(comp->net, (u32 *)((u32 *)(&comp->reportState)));
            if(comp->reportResult!=0 && comp->reportState!=0)
                WIFIBATTLEMATCH_UTIL_SetSaveState(params->save->gameData,params->saveBlock->head);
        }
        if(comp->reportResult==1) {
            (params->saveBlock)->reportState=WIFIBATTLEMATCH_NET_GetReportState(comp->net);*state=4;
        }
        if(comp->reportResult!=0) {
            switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,(void *)1)) {
            case 1:WIFIBATTLEMATCH_NET_DisconnectWifi(comp->net);
            case 2:case 4:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);DWC_RAPCOMMON_DestroySubHeap();break;
            }
        }break;
    case 4:DWC_RAPCOMMON_DestroySubHeap();
        if(params->state==2)WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle);
        else *state=5;break;
    case 5:list=MET_TRAINERS_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData));
        MET_TRAINERS_Insert(list,MYSTATUS_GetId((struct MyStatus *)params->record));
        WIFIBATTLEMATCH_NET_ClearCancelFlag(comp->net);*state=6;break;
    case 6:if(WIFIBATTLEMATCH_NET_StopMatchmaking(comp->net)) *state=7;
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,(void *)1)) {
        case 1:case 4:*state=7;break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 7:if(*params->statPtr==0) {
        MI_CpuFill8(&rec,0,84);
        rec.data=**(Rec80 * *)&(comp->ctx)->recData;
        rec.last=**(u32 * *)&(comp->ctx)->recLast;
        WIFIBATTLEMATCH_NET_SetupGdbUpload(comp->net,3,(struct WifibattlematchNetRecord *)(&rec));*state=8;
        }break;
    case 8:result=WIFIBATTLEMATCH_NET_GdbUpdateRecord(comp->net);
        if(result==1) {
            **(u32 * *)&(comp->ctx)->statPtr=1800;*state=9;
        }
        if(result!=0) {
            switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0)) {
            case 1:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry);break;
            case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
            }
        }break;
    case 9:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,88,1);
        *state=13;WIFIBATTLEMATCH_UTIL_SetRequest(sys,10);break;
    case 10:params->netState=2;WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys);break;
    case 13:if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepSaveAfterBattle(WifibattlematchCallback *a, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    int result;
    u32 waitResult;
    struct WifiBattleMatchParams *params = comp->ctx;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x28, 2);
        *state = 5;
        WIFIBATTLEMATCH_UTIL_SetRequest(a, 1);
        return;
    case 1:
        WIFIBATTLEMATCH_NET_GetSetCompStat(comp, params->sub);
        GAME_DATA_SaveStart(params->save->gameData);
        *state = 2;
        return;
    case 2:
        result = GAME_DATA_SaveMain(params->save->gameData);
        if (result == 2) {
            *state = 3;
            return;
        }
        if (result == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);
        return;
    case 3:
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompStepAskRetry);
            return;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompCleanup);
            return;
        case 0:
            WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp, WIFIBATTLEMATCH_NET_CompStepCheckPeriod);
            *state = 4;
            return;
        }
        return;
    case 4:
        waitResult = WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if (waitResult == 0)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompStepAskRetry);
        else if (waitResult - 1 <= 1)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);
        else if (waitResult == 3)
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompCleanup);
        switch (WIFIBATTLEMATCH_NET_HandleNetError(comp->net, 0, 0)) {
        case 1:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompStepAskRetry);
            return;
        case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(a, WIFIBATTLEMATCH_NET_CompCleanup);
            return;
        }
        return;
    case 5:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj))
            WIFIBATTLEMATCH_UTIL_CommitRequest(a);
        return;
    }
}

/*
 * Lever: the two-value tail dispatch is a switch; if (v==1 || v==2) folds into a range and compiles 316/320 bytes.
 */
void WIFIBATTLEMATCH_NET_CompStepAskRetry(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    int result;
    switch(*state) {
    case 0:
        switch(WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,(void *)1)) {
        case 0:case 1:case 4:*state=1;break;
        case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
        }break;
    case 1:BG_SYS_SetPlaneVisible(0,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,92,1);
        *state=7;WIFIBATTLEMATCH_UTIL_SetRequest(sys,2);break;
    case 2:WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 4);*state=3;break;
    case 3:result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch(result) {
            case 0:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepMatchmake);break;
            case 1:*state=4;break;
            case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepConfirmQuit);break;
            }
        }break;
    case 4:WIFIBATTLEMATCH_NET_SetCompWaitCallback(comp,WIFIBATTLEMATCH_NET_CompStepWithdrawEntry);*state=5;break;
    case 5:result=WIFIBATTLEMATCH_NET_GetCompWaitResult(comp);
        if(result==1 || result==2) *state=1;
        else if(result==0) *state=6;
        result=WIFIBATTLEMATCH_NET_HandleNetError(comp->net,0,0);
        switch(result) {
        case 1:case 2:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);break;
        }
        break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit);break;
    case 7:if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepConfirmQuit(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    int result;
    switch (*state) {
    case 0:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj, comp->msgBank, 0x4e, 1);
        *state = 3;
        WIFIBATTLEMATCH_UTIL_SetRequest(sys, 1);
        break;
    case 1:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp, 0);
        *state = 2;
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if (result != -1) {
            WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp);
            switch (result) {
            case 0: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit); break;
            case 1: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepAskRetry); break;
            }
        }
        break;
    case 3:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *params = comp->ctx;
    switch(*state) {
    case 0:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,40,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,1);*state=7;break;
    case 1:GAME_DATA_SaveStart(params->save->gameData);*state=2;break;
    case 2:if(GAME_DATA_SaveMain(params->save->gameData)==2) *state=3;break;
    case 3:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,37,2);
        WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);*state=7;break;
    case 4:if(*params->statPtr==0) {WIFIBATTLEMATCH_NET_SetupGdbUpload(comp->net,2,0);*state=5;}break;
    case 5:if(WIFIBATTLEMATCH_NET_GdbUpdateRecord(comp->net)) {
        **(u32 * *)&(comp->ctx)->statPtr=1800;*state=6;
        WIFIBATTLEMATCH_NET_HandleNetError(comp->net,(void *)1,0);
    }break;
    case 6:WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompExit);break;
    case 7:if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

/*
 * follower: 021D905C tail-call stub included; function_starts seed 021D905C.
 */
void WIFIBATTLEMATCH_NET_CompStepCheckPeriodThenSaveQuit(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    int result;
    switch (*state) {
    case 0:
        result = WIFIBATTLEMATCH_NET_HandleNetError(comp->net, (void *)1, 0);
        switch (result) {
        case 1: case 2:
            WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
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
        if (result == 3) WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup);
        result = WIFIBATTLEMATCH_NET_HandleNetError(comp->net, (void *)1, 0);
        switch (result) {
        case 1: case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompCleanup); break;
        }
        break;
    case 2: WIFIBATTLEMATCH_UTIL_SetCallback(sys, WIFIBATTLEMATCH_NET_CompStepSaveAndUploadQuit); break;
    case 3:
        if (WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys);
        break;
    }
}

void WIFIBATTLEMATCH_NET_CompExit(WifibattlematchCallback *sys, int *unusedState, void *unusedWork)
{
    WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys);
}

void WIFIBATTLEMATCH_NET_CompCleanup(WifibattlematchCallback *obj, int *unused, void *compArg) {  struct WifiBattleMatchCompWork *comp = compArg;(comp->ctx)->netState=3; if(comp->net) { WIFIBATTLEMATCH_NET_DeleteNetContext(comp->net); comp->net=0; } GFL_NET_ERR_WaitLinkClosed(); WIFIBATTLEMATCH_UTIL_ClearCallback((void *)(obj)); }

/*
 * Lever: byte range test uses (u8)(value + 255), preserving adds #255.
 * Extent: final 021D9342..021D9344 is zero alignment padding.
 */
void WIFIBATTLEMATCH_NET_CompStepCheckPeriod(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *params = comp->ctx;
    struct RTCDate startDate;
    struct RTCDate endDate;
    struct RTCDate nowDate;
    struct RTCTime nowTime;
    WifibattlematchNetRequest req;
    struct RegulationCard *reg;
    struct BattleBoxSave *box;
    int got;
    int startDay,endDay,nowDay,result;
    switch(*state) {
    case 0:*state=1;break;
    case 1:reg=comp->card;
        if(!GFL_NET_GetRunState())GFL_NET_ERR_HaltIfActive();
        got=DWC_GetDateTime((int *)&nowDate,(int *)&nowTime);
        if(got)RTC_ConvertSecondToDateTime(&nowDate,&nowTime,RTC_ConvertDateTimeToSecond(&nowDate,&nowTime));
        startDate.year=REGULATION_Card_GetValue((struct RegulationCard *)reg,4);
        startDate.month=REGULATION_Card_GetValue((struct RegulationCard *)reg,5);
        startDate.day=REGULATION_Card_GetValue((struct RegulationCard *)reg,6);startDate.week=0;
        endDate.year=REGULATION_Card_GetValue((struct RegulationCard *)reg,7);
        endDate.month=REGULATION_Card_GetValue((struct RegulationCard *)reg,8);
        endDate.day=REGULATION_Card_GetValue((struct RegulationCard *)reg,9);endDate.week=0;
        startDay=RTC_ConvertDateToDay(&startDate);
        endDay=RTC_ConvertDateToDay(&endDate);
        nowDay=RTC_ConvertDateToDay(&nowDate);
        if(got && nowDay<startDay) {comp->waitResult=2;*state=2;}
        else if(got && startDay<=nowDay && nowDay<=endDay) {comp->waitResult=0;*state=13;}
        else {comp->waitResult=1;*state=3;}
        break;
    case 2:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,96,1);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,13);break;
    case 3:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,80,1);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,4);break;
    case 4:if((u8)(params->session->subState+255)<=1) *state=5;
        else *state=13;break;
    case 5:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,40,2);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,6);break;
    case 6:box=BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData));
        comp->boxLocked=BATTLE_BOX_IsLocked(box, 1);
        BATTLE_BOX_ClearLockFlags((struct BattleBoxSave *)box, 1);
        REGULATION_Card_SetValue(comp->card,10,3);
        GAME_DATA_SaveStart(params->save->gameData);*state=7;break;
    case 7:if(GAME_DATA_SaveMain(params->save->gameData)==2) *state=8;break;
    case 8:BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData));
        if(comp->boxLocked!=0) *state=9;else *state=10;break;
    case 9:WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,81,1);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,10);break;
    case 10:WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,70,2);
        *state=14;WIFIBATTLEMATCH_UTIL_SetRequest(sys,11);break;
    case 11:MI_CpuFill8(&req,0,8);req.b=3;
        req.id=WIFIBATTLEMATCH_NET_GetGsProfileId(comp->net);
        comp->ctx->session->subState=3;
        WIFIBATTLEMATCH_NET_SetupHttpRap(comp->net,(const W *)&req,87);*state=12;break;
    case 12:result=WIFIBATTLEMATCH_NET_HttpRapSend(comp->net);
        if(result==1) *state=13;
        else if(result==3) {comp->waitResult=3;*state=13;}
        break;
    case 13:WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys);break;
    case 14:if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj))WIFIBATTLEMATCH_UTIL_CommitRequest(sys);break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepWithdrawEntry(WifibattlematchCallback *sys, int *state, void *compArg) {
    struct WifiBattleMatchCompWork *comp = compArg;
    struct WifiBattleMatchParams *params = comp->ctx;
    int result;
    WifibattlematchNetRequest request;
    switch(*state) {
    case 0:
        result=(params->session)->subState;
        if((u8)(result+255)<=1) { comp->waitResult=1; *state=2; }
        else { comp->waitResult=2; *state=1; }
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,82,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,15); break;
    case 2:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,83,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,3); break;
    case 3: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp,5); *state=4; break;
    case 4:
        result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) { WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) { case 0:*state=5;break; case 1:*state=15;break; } }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,84,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,6); break;
    case 6: WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(comp,5); *state=7; break;
    case 7:
        result=WIFIBATTLEMATCH_NET_PollCompChoiceMenu(comp);
        if(result!=-1) { WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(comp); switch(result) { case 0:*state=8;break; case 1:*state=15;break; } }
        break;
    case 8:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,40,2);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,9); break;
    case 9:
        BATTLE_BOX_ClearLockFlags((struct BattleBoxSave *)(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(params->save->gameData))), 1);
        REGULATION_Card_SetValue(comp->card,10,4);
        GAME_DATA_SaveStart(params->save->gameData); *state=10; break;
    case 10:
        result=GAME_DATA_SaveMain(params->save->gameData);
        if(result==2) { comp->waitResult=0; *state=11; }
        else if(result==3) *state=15;
        break;
    case 11:
        WIFIBATTLEMATCH_NET_DrawCompStatusWindow(comp,1);
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,81,1);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,12); break;
    case 12:
        WIFIBATTLEMATCH_UTIL_PrintMessage(comp->textObj,comp->msgBank,70,2);
        *state=16; WIFIBATTLEMATCH_UTIL_SetRequest(sys,13); break;
    case 13:
        MI_CpuFill8(&request,0,8); request.b=4;
        request.id=WIFIBATTLEMATCH_NET_GetGsProfileId(comp->net);
        ((struct WifiBattleMatchSession *)(*(char * *)&(comp->ctx)->session))->subState=4;
        WIFIBATTLEMATCH_NET_SetupHttpRap(comp->net,(const W *)&request,87); *state=14; break;
    case 14:
        result=WIFIBATTLEMATCH_NET_HttpRapSend(comp->net);
        if(result==1) *state=15;
        else if(result==3) { comp->waitResult=3; *state=15; }
        break;
    case 15: WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys); break;
    case 16: if(WIFIBATTLEMATCH_UTIL_GetBusy(comp->textObj)) WIFIBATTLEMATCH_UTIL_CommitRequest(sys); break;
    }
}

void WIFIBATTLEMATCH_NET_CompStepPostPartyData(WifibattlematchCallback *sys, int *state, void *compArg)
{
    struct WifiBattleMatchCompWork *comp = compArg;
    char *save;
    int result;
    save = *(char * *)&(comp->ctx)->profile;
    switch (*state) {
    case 0: *state = 1; break;
    case 1:
        MI_CpuFill8(&comp->responseFlag, 0, 0x9c);
        WIFIBATTLEMATCH_NET_SetupPostData(comp->net, save + 0xd4, 1);
        *state = 2;
        break;
    case 2:
        result = WIFIBATTLEMATCH_NET_HttpRapPost(comp->net, (u8 *)(&comp->responseFlag));
        if (result == 1) *state = 3;
        else if (result == 2) { comp->waitResult = 2; *state = 4; }
        else if (result == 3) { comp->waitResult = 3; *state = 4; }
        break;
    case 3:
        if (comp->responseFlag == 0) {
            WIFIBATTLEMATCH_NET_CopyCompResponse(save, &comp->responseFlag);
            comp->waitResult = 0;
            *state = 4;
        } else {
            comp->waitResult = 1;
            *state = 4;
        }
        break;
    case 4: WIFIBATTLEMATCH_UTIL_ClearCallback((void *)sys); break;
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
void WIFIBATTLEMATCH_NET_SetupCompStatusWindow(struct WifiBattleMatchCompWork *obj)
{
    struct Profile prof;
    uptr sys;
    struct Unit *id;
    uptr kind;
    u32 cardValA;
    u32 cardValB;
    struct RegulationCard *card;
    u32 cardValC;

    if (obj->tradeIcon == 0) {
        card = obj->card;
        sys = (uptr)GAME_DATA_GetMyStatus(obj->ctx->save->gameData);
        id = WIFIBATTLEMATCH_GRAPHIC_GetCamera(obj->sprite);
        kind = (uptr)REGULATION_GetParty((struct BattleCompetitionSave *)(BATTLE_COMPETITION_GetFromSave((struct SaveControl *)(GAME_DATA_GetSaveControl(obj->ctx->save->gameData)))), 0);
        MI_CpuFill8((void *)&prof, 0, sizeof(prof));
        MI_CpuCopy8((const void *)(REGULATION_Card_GetCupName((struct RegulationCard *)((struct BattleCompetitionSave *)card))), (void *)&prof, 0x92);
        cardValA = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 6);
        cardValB = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 5);
        cardValC = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 4);
        prof.date1 = (cardValC << 24) | ((cardValB << 24) >> 8) | ((cardValA << 24) >> 16);
        cardValA = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 9);
        cardValB = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 8);
        cardValC = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 7);
        prof.date2 = (cardValC << 24) | ((cardValB << 24) >> 8) | ((cardValA << 24) >> 16);
        prof.statusFlag = MYSTATUS_GetTrainerView((const struct MyStatus *)sys);
        prof.hA0 = BSUBWAY_SAVEDATA_GetStat(obj->ctx->bsubwaySave, 10, 0);
        cardValA = BSUBWAY_SAVEDATA_GetStat(obj->ctx->bsubwaySave, 10, 1);
        prof.uA4 = cardValA + BSUBWAY_SAVEDATA_GetStat(obj->ctx->bsubwaySave, 10, 2);
        prof.hAA = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 11);
        if (prof.uA4 == 0 && prof.hA0 == 0)
            prof.hA0 = 1500;
        obj->tradeIcon = WIFIBATTLEMATCH_VIEW_CreateStatusWindow((char *)(&prof), 0, (void *)sys, (void *)id, obj->anim, obj->font, obj->printQue, obj->msgBank, obj->wordSet, (void *)kind, 0, 0x57);
    }
}

/*
 * Release path for the +0x1c block pointer, freed through 0x021E5EF8
 *     and cleared; a second call is a no-op.  The callee address is shared by
 *     two overlays, so the symbols: line names the ov177 function that the
 *     image's call to it there fixes.
 */
void WIFIBATTLEMATCH_NET_DeleteCompStatusWindow(struct WifiBattleMatchCompWork *obj)
{
    struct WifibattlematchViewWork *tradeIcon = obj->tradeIcon;

    if (tradeIcon != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteStatusWindow((void *)tradeIcon);
        obj->tradeIcon = 0;
    }
}

u32 WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(struct WifiBattleMatchCompWork *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindow(obj->tradeIcon);
}

/*
 * Thunk: hands the +0x1c block to 0x021E65FC (ov177) and returns its result.
 */
int WIFIBATTLEMATCH_NET_IsCompStatusWindowIdle(struct WifiBattleMatchCompWork *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(obj->tradeIcon);
}

/*
 * Start-op for the ov175 object's +0x1c stream: WIFIBATTLEMATCH_NET_SetupCompStatusWindow, then spin
 *     on WIFIBATTLEMATCH_NET_IsCompStatusWindowReady until it reports ready.  Mirrors WIFIBATTLEMATCH_NET_SetupBoxAndWait.
 */
void WIFIBATTLEMATCH_NET_SetupCompStatusWindowAndWait(struct WifiBattleMatchCompWork *obj)
{
    WIFIBATTLEMATCH_NET_SetupCompStatusWindow(obj);
    while (WIFIBATTLEMATCH_NET_IsCompStatusWindowReady(obj) == 0)
        ;
}

/*
 * If the +0x1c block is live, forward it to 0x021E5F24 together with the
 *     function's own second argument, the +0x14 and +0x10 words and the +8
 *     word, plus the literal 0x57.  Six arguments, so the last two ride on the
 *     stack; the two-word frame exists only for them.
 */
void WIFIBATTLEMATCH_NET_DrawCompStatusWindow(struct WifiBattleMatchCompWork *obj, u32 arg)
{
    if (obj->tradeIcon != 0)
        WIFIBATTLEMATCH_VIEW_DrawStatusWindow(obj->tradeIcon, arg, obj->msgBank,obj->printQue, obj->font, 0x57);
}

/*
 * Lazy create: when the handle at +0x20 is empty, builds it through the eleven-argument ov177 constructor from the +0x0/+0x4/+0x8/+0x10/+0x14/+0x18 words and the heap id at +0x108.
 */
void WIFIBATTLEMATCH_NET_StartRegCardAnim(struct WifiBattleMatchCompWork *obj, const WifiBattleMatchViewRecord *arg)
{
    if (obj->regCard == 0) {
        struct Unit *base = WIFIBATTLEMATCH_GRAPHIC_GetCamera(obj->sprite);
        obj->regCard = WIFIBATTLEMATCH_VIEW_CreateRecordWindow(arg, base, obj->anim, obj->font, obj->printQue, obj->msgBank, obj->wordSet, 0, 1,
                               REGULATION_Card_GetValue(obj->card, 0xb), 0x57);
    }
}

/*
 * Release path for the ov175 object's 0x20 pointer: free it through
 *     0x021E7710 and clear the field, null-safe.
 */
void WIFIBATTLEMATCH_NET_DeleteCompRegCard(struct WifiBattleMatchCompWork *obj)
{
    struct WifiBattleMatchViewRecordWork *regCard = obj->regCard;

    if (regCard != 0) {
        WIFIBATTLEMATCH_VIEW_DeleteRecordWindow((char *)regCard);
        obj->regCard = 0;
    }
}

/*
 * Thunk: hands the +0x20 block to 0x021E777C (ov177) and returns its result.
 */
u32 WIFIBATTLEMATCH_NET_IsCompRegCardReady(struct WifiBattleMatchCompWork *obj)
{
    return WIFIBATTLEMATCH_VIEW_StepRecordWindow(obj->regCard);
}

/*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 */
void WIFIBATTLEMATCH_NET_SetupCompPartyWindow(struct WifiBattleMatchCompWork *ctx)
{
    struct Unit *window;
    if (ctx->window == 0) {
        window = WIFIBATTLEMATCH_GRAPHIC_GetCamera(ctx->sprite);
        ctx->window = WIFIBATTLEMATCH_VIEW_CreatePartyWindow((void *)(BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(ctx->ctx->save->gameData))), (void *)window, ctx->anim, ctx->fontAlt, ctx->printQue, ctx->msgBank, 87);
    }
}

/*
 * Free-and-null on the +0x24 block: hands it to 0x021E82BC (ov177) and
 *  *  clears the field, so a second call is harmless.
 */
void WIFIBATTLEMATCH_NET_DeleteCompPartyWindow(struct WifiBattleMatchCompWork *obj)
{
    struct WifiBattleMatchViewPartyWork *window = obj->window;
    if (window != 0) {
        WIFIBATTLEMATCH_VIEW_DeletePartyWindow((char *)window);
        obj->window = 0;
    }
}

int WIFIBATTLEMATCH_NET_IsCompPartyWindowReady(struct WifiBattleMatchCompWork *comp)
{
    return WIFIBATTLEMATCH_VIEW_StepPartyWindow(comp->window);
}

int WIFIBATTLEMATCH_NET_IsCompPartyWindowIdle(struct WifiBattleMatchCompWork *comp)
{
    return WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(comp->window);
}

void WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(struct WifiBattleMatchCompWork *comp, int mode) {
    WifibattlematchMenuDesc d;
    if (comp->compSprite == 0) {
        MI_CpuFill8(&d, 0, sizeof(d));
        d.msgBank=comp->msgBank; d.font=comp->font; d.printQue=comp->printQue;
        d.a=0; d.b=15; d.c=13; d.d=1;
        switch (mode) {
        case 5: d.row=1;
        case 0:
            d.items[0]=52; d.items[1]=53; d.count=2; d.enabled=1; d.kind=1;
            comp->compSprite=WIFIBATTLEMATCH_UTIL_ShowMenu((const WifibattlematchMenuDesc *)&d,87); break;
        case 1:
            d.items[0]=47; d.items[1]=48; d.items[2]=49; d.count=3; d.enabled=1; d.kind=2;
            comp->compSprite=WIFIBATTLEMATCH_UTIL_ShowMenu((const WifibattlematchMenuDesc *)&d,87); break;
        case 2:
            d.items[0]=66; d.items[1]=67; d.count=2; d.enabled=1; d.kind=1;
            comp->compSprite=WIFIBATTLEMATCH_UTIL_ShowMenu((const WifibattlematchMenuDesc *)&d,87); break;
        case 3:
            d.items[0]=75; d.items[1]=76; d.items[2]=77; d.count=3; d.enabled=1; d.kind=2;
            comp->compSprite=WIFIBATTLEMATCH_UTIL_CreateMenu((const WifibattlematchMenuDesc *)&d,3,6,26,6,87); break;
        case 4:
            d.items[0]=93; d.items[1]=94; d.items[2]=95; d.count=3; d.enabled=1; d.kind=2;
            comp->compSprite=WIFIBATTLEMATCH_UTIL_CreateMenu((const WifibattlematchMenuDesc *)&d,3,6,26,6,87); break;
        }
    }
}

void WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(struct WifiBattleMatchCompWork *obj)
{
    struct WifibattlematchMenu *compSprite = obj->compSprite;

    if (compSprite != 0) {
        WIFIBATTLEMATCH_UTIL_DeleteMenu((struct WifibattlematchMenu *)compSprite);
        obj->compSprite = 0;
    }
}

/*
 * Field query: if the +0x30 pointer is live, hand it to the ov175-adjacent
 *     routine at 0x021E8A00 and return its result, else -1.  WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu is
 *     the matching free path for the same field.
 */
int WIFIBATTLEMATCH_NET_PollCompChoiceMenu(struct WifiBattleMatchCompWork *obj)
{
    struct WifibattlematchMenu *compSprite = obj->compSprite;

    if (compSprite != 0)
        return WIFIBATTLEMATCH_UTIL_UpdateMenu((struct WifibattlematchMenu *)compSprite);
    return -1;
}

void WIFIBATTLEMATCH_NET_SetCompWaitCallback(struct WifiBattleMatchCompWork *obj, WifibattlematchCallbackFn fn)
{
    WIFIBATTLEMATCH_UTIL_SetCallback(obj->waitStream, fn);
    obj->waitResult = 0xFFFF;
}

/*
 * Reads back the +0x3c stream: 0x021E8A80 for pending data, 0x021E8A90
 *     for a byte read, returning the +0x40 word or the 0xFFFF sentinel.
 *     Mirrors WIFIBATTLEMATCH_NET_PollWaitResult.
 */
u32 WIFIBATTLEMATCH_NET_GetCompWaitResult(struct WifiBattleMatchCompWork *obj)
{
    WIFIBATTLEMATCH_UTIL_InvokeCallback(obj->waitStream);
    if (WIFIBATTLEMATCH_UTIL_IsCallbackNull(obj->waitStream) != 0)
        return obj->waitResult;
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

void WIFIBATTLEMATCH_NET_CopyCompBox(struct WifiBattleMatchStatRecord *dest, struct WifiBattleMatchCompWork *ctx)
{
    void *records;
    MI_CpuFill8((void *)dest, 0, 212);
    records = BATTLE_BOX_CreateParty((struct BoxMonGroup *)BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(ctx->ctx->save->gameData)), 87);
    POKEPARTY_Init((struct Party *)((char *)dest + 212));
    MI_CpuCopy8((const void *)records, (void *)((char *)dest + 212), POKE_REGULATION_GetDataSize());
    GFL_HEAP_Free(records);
    dest->boxValue = 100;
}

/*
 * Fills a profile record from the save data reached through +0x104: name, a 0x38 record, three words of the +0x34 block, the +0x34 id, a derived word and two values of the +0x108 block.
 *
 *     (MI_CpuCopy8 with size 0x20) with no witness. Seed and match it and this
 *     file is EXACT.
 */
void WIFIBATTLEMATCH_NET_CopyCompSave(struct WifiBattleMatchStatRecord *dst, struct WifiBattleMatchCompWork *obj)
{
    struct SaveControl *saveCtrl = GAME_DATA_GetSaveControl(obj->ctx->save->gameData);
    struct RegulationCard *card;

    MYSTATUS_Copy((struct MyStatus *)GAME_DATA_GetMyStatus(obj->ctx->save->gameData), (struct MyStatus *)dst);
    GREETING_SAVEDATA_GetSentence(GREETING_SAVEDATA_GetFromSaveThunk(saveCtrl), 0, (struct QuadRecord *)dst->quadRecord);
    {
        const struct WifiBattleMatchParams *s = obj->ctx;
        dst->keyDBase = s->sub->keyDBase;
        dst->keyDDelta = s->sub->keyDDelta;
        dst->keyA = s->sub->keyA;
    }
    dst->netId = WIFIBATTLEMATCH_NET_GetNetId(obj->net);
    dst->gsProfileId = WIFILIST_GetGsProfileId((void *)GAME_DATA_GetWifiList(obj->ctx->save->gameData));
    card = obj->card;
    dst->cardValue = REGULATION_Card_GetValue((struct RegulationCard *)((struct BattleCompetitionSave *)card), 2);
    dst->crc = REGULATION_Card_CalcCrc((struct RegulationCard *)((struct BattleCompetitionSave *)card));
}

/*
 * leaf: copy128 bytes from response+0x1c to save+0x54.
 */
void WIFIBATTLEMATCH_NET_CopyCompResponse(void *saveArg, void *responseArg)
{
    char *save = saveArg;
    char *response = responseArg;
    MI_CpuCopy8(response + 0x1c, save + 0x54, 128);
}

u32 WIFIBATTLEMATCH_NET_VerifyCompSignature(void *objArg, void *list, u32 heapId)
{
    char *obj = objArg;
    int heap = (heapId & 0x7fff) | 0x8000;
    u32 size = POKE_TOOL_GetPartyParamSize();
    void *buf = NHTTP_RAP_EvilCheckAllocArray(size, POKEPARTY_GetCount(list), (u16)heap);
    int i;
    u32 ret;

    for (i = 0; i < (int)POKEPARTY_GetCount(list); i++) {
        void *entry = POKEPARTY_GetMember(list, i);
        NHTTP_RAP_EvilCheckSetElement(buf, entry, POKE_TOOL_GetPartyParamSize(), i);
    }
    size = POKE_TOOL_GetPartyParamSize();
    ret = NHTTP_RAP_VerifySignature(buf, size, POKEPARTY_GetCount(list), obj + 0x54, (u16)heap);
    NHTTP_RAP_EvilCheckFreeArray(buf);
    return ret;
}

int WIFIBATTLEMATCH_NET_CompareParty(struct Party *a, struct Party *b)
{
    u32 count = POKEPARTY_GetCount(a);
    u32 i;

    if (count == POKEPARTY_GetCount(b)) {
        for (i = 0; i < count; i++) {
            struct PokemonParam *ea = POKEPARTY_GetMember(a, i);
            struct PokemonParam *eb = POKEPARTY_GetMember(b, i);
            u8 *pa = (unsigned char *)POKE_TOOL_CastToBoxParam(ea);
            u8 *pb = (unsigned char *)POKE_TOOL_CastToBoxParam(eb);
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
int WIFIBATTLEMATCH_NET_CompHandleCancel(struct WifiBattleMatchCompWork *obj, int trigger, int go)
{
    int result;

    switch (obj->stepCounter) {
    case 0:
        if (trigger == 0)
            break;
        if (!(KEY_GetTrg() & 2))
            break;
        obj->stepCounter = obj->stepCounter + 1;
        break;
    case 1:
        WIFIBATTLEMATCH_UTIL_PrintMessage(obj->textObj, obj->msgBank, 0x23, 1);
        obj->stepCounter = obj->stepCounter + 1;
        break;
    case 2:
        if (!WIFIBATTLEMATCH_UTIL_GetBusy(obj->textObj))
            break;
        obj->stepCounter = obj->stepCounter + 1;
        break;
    case 3:
        WIFIBATTLEMATCH_NET_SetupCompChoiceMenu(obj, 0);
        obj->stepCounter = obj->stepCounter + 1;
        break;
    case 4:
        result = WIFIBATTLEMATCH_NET_PollCompChoiceMenu(obj);
        if (result == -1)
            break;
        WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(obj);
        switch (result) {
        case 0:
            obj->stepCounter = 5;
            break;
        case 1:
            WIFIBATTLEMATCH_UTIL_PrintMessage(obj->textObj, obj->msgBank, 0x21, 0);
            obj->stepCounter = 0;
            return 2;
        }
        break;
    case 5:
        WIFIBATTLEMATCH_UTIL_PrintMessage(obj->textObj, obj->msgBank, 0x2b, 2);
        obj->stepCounter = obj->stepCounter + 1;
        break;
    case 6:
        if (go == 0)
            break;
        WIFIBATTLEMATCH_NET_SendSessionQuery(obj->net);
        obj->stepCounter = obj->stepCounter + 1;
        WIFIBATTLEMATCH_VIEW_SetActorVisible(obj->animMgr, 0);
        WIFIBATTLEMATCH_NET_DisconnectWifi(obj->net);
        if (!GFL_NET_ERR_GetErrorLevel() && GFL_NET_GetRunState())
            DWC_CloseAllConnectionsHard();
        break;
    case 7:
        obj->stepCounter = 0;
        return 3;
    }
    switch (obj->stepCounter) {
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
void WIFIBATTLEMATCH_NET_CompClearError(struct WifiBattleMatchCompWork *obj)
{
    obj->stepCounter = 0;
    WIFIBATTLEMATCH_NET_DeleteCompChoiceMenu(obj);
}

/*
 * Syncs three words of a record (+0x10, +0x8, +0xc) into slots 0..2 of table 10 of the save block at +0x104; returns 1 when any of them differed from what was stored.
 *
 * Both callees 0x0200DFD8 and 0x0200DFE4 resolve since seeds_2 labelled and
 *     matched them (src/matched/unit_0200DFD8.c).
 */
int WIFIBATTLEMATCH_NET_GetSetCompStat(struct WifiBattleMatchCompWork *obj, struct WifibattlematchNetSub *rec)
{
    int changed = 0;

    if (rec->keyA != BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)((obj->ctx)->bsubwaySave), 10, 0)
        || rec->keyDBase != BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)((obj->ctx)->bsubwaySave), 10, 1)
        || rec->keyDDelta != BSUBWAY_SAVEDATA_GetStat((BsubwayStatRow *)((obj->ctx)->bsubwaySave), 10, 2))
        changed = 1;
    BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)((obj->ctx)->bsubwaySave), 10, 0, rec->keyA);
    BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)((obj->ctx)->bsubwaySave), 10, 1, rec->keyDBase);
    BSUBWAY_SAVEDATA_SetStat((BsubwayStatRow *)((obj->ctx)->bsubwaySave), 10, 2, rec->keyDDelta);
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
struct WifiBattleMatchNetCtx *WIFIBATTLEMATCH_NET_CreateNetContext(struct WifiBattleMatchReportBlock *netId, struct GameData *save, char *heapId, u16 heap) {
    struct WifiBattleMatchNetCtx *ctx;
    struct WifiList *wifiList;
    ctx = GFL_HEAP_Alloc(heap, sizeof(*ctx), 0, d_021E2EE0, 0x2b0);
    MI_CpuFill8(ctx, 0, sizeof(*ctx));
    wifiList = GAME_DATA_GetWifiList(save);
    ctx->gsProfileId = wifiList;
    ctx->scId = WIFILIST_GetWork(wifiList);
    ctx->statusBuf = MYSTATUS_GetProfileId(GAME_DATA_GetMyStatus(save));
    ctx->save = save;
    ctx->heap = heapId;
    ctx->netIdPtr = netId;
    ctx->initWord = 0x573;
    ctx->recBuf = GFL_HEAP_Alloc(heap, 0x260, 0, d_021E2EE0, 0x2c0);
    MI_CpuFill8(ctx->recBuf, 0, 0x260);
    if (!GFL_NET_GetRunState()) GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
            GFL_USE_StopAllSe();
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
            GFL_USE_StopAllSe();
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
        GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
        break;
    case 2:
        obj->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyInt;
        break;
    case 3:
        obj->evalFn = WIFIBATTLEMATCH_NET_GetMatchKeyDefault;
        break;
    default:
        GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x751);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->state = 5;
        break;
    case 5:
        result = DWC_ScGetLoginCertificate((GSLoginCertificate **)((void **)((char *)&ctx->netIdPtr->players[0])));
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x761);
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
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x773);
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
            WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err, 1, 0x78f);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (ctx->reportResult != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, ctx->reportResult, 0x797);
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
                WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x7cd);
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
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x7dd);
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
            WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err, 1, 0x7f2);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (ctx->reportResult != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, ctx->reportResult, 0x7fa);
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
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x86d);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        ctx->state = 0x14;
        break;
    case 20:
        (ctx->pendingCount)++;
        result = DWC_ScSubmitReportAsync(ctx->netIdPtr->players[0].report, ctx->reportCount, WIFIBATTLEMATCH_NET_OnReportResultC, 100, (void *)ctx);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, result, 0x87c);
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
            WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err, 1, 0x890);
            WIFIBATTLEMATCH_NET_ShutdownReport(ctx);
            return 2;
        }
        DWC_ScProcess();
        if (ctx->reportResult != 0) {
            WIFIBATTLEMATCH_NET_SetErrorB(&ctx->err, ctx->reportResult, 0x898);
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
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
                GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
    default: GF_PANIC_Fail(d_021E2EF8,0,d_021E2EF8); break;
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
        GF_PANIC_Fail((const char *)(g_021E2EF8), 0, (const char *)((sptr)g_021E2EF8));
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
            WIFIBATTLEMATCH_NET_SetResultA(&obj->err, result, 0xdef);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        obj->state = 1;
        break;
    case 1:
        if (obj->fieldCount >= 0x26)
            GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
        if (obj->gdbTarget == -1)
            result = DWC_GdbGetMyRecordsAsync((char *)d_021E2F1C, (char **)obj->gdbName, obj->fieldCount, WIFIBATTLEMATCH_NET_GdbSortByName, (void *)obj);
        else
            result = DWC_GdbGetRecordsAsync((char *)d_021E2F1C, (int *)(&obj->gdbTarget), 1, (char **)obj->gdbName, obj->fieldCount, WIFIBATTLEMATCH_NET_GdbSortByName, (void *)obj);
        if (result != 0) {
            WIFIBATTLEMATCH_NET_SetResultA(&obj->err, result, 0xe0a);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        obj->state = 2;
        obj->pollCount = 0;
        break;
    case 2:
        if ((obj->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&obj->err, 1, 0xe17);
            obj->state = 6;
            break;
        }
        DWC_GdbProcess();
        result = DWC_GdbGetState();
        if (result == 0 || result == 4) {
            WIFIBATTLEMATCH_NET_SetResultB(&obj->err, result, 0xe26);
            obj->state = 6;
        } else if (result == 1) {
            obj->state = 3;
        }
        break;
    case 3:
        result = DWC_GdbGetAsyncResult();
        if (result == 0) {
            WIFIBATTLEMATCH_NET_SetResultC(&obj->err, result, 0xe39);
            obj->state = 6;
        } else if (result != 1) {
            WIFIBATTLEMATCH_NET_SetResultC(&obj->err, result, 0xe3f);
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
            WIFIBATTLEMATCH_NET_SetResultA(&obj->err, result, 0xe5e);
            WIFIBATTLEMATCH_NET_GdbShutdown(obj);
            return 2;
        }
        break;
    case 7:
        if ((obj->pollCount)++ > 0xe10) {
            WIFIBATTLEMATCH_NET_SetErrorA(&obj->err, 1, 0xe6a);
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
    if(ctx->netIdPtr->head==0)GF_PANIC_Fail((const char *)(d_021E2EF8),0,(const char *)((sptr)d_021E2EF8));
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
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,0x1161);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        ctx->state=1;break;
    case 1:
        if(ctx->fieldCount>=0x26)GF_PANIC_Fail(d_021E2EF8,0,d_021E2EF8);
        result=DWC_GdbUpdateRecordAsync((char *)d_021E2F1C,ctx->netIdPtr->head,ctx->recBuf,ctx->fieldCount);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,0x116e);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        ctx->pollCount=0;ctx->state=2;break;
    case 2:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,0x117b);ctx->state=6;break;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_SetResultB(&ctx->err,result,0x1186);ctx->state=6;}
        else if(result==1)ctx->state=3;
        break;
    case 3:
        result=DWC_GdbGetAsyncResult();
        if(result==0) {WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,0x1199);ctx->state=6;}
        else if(result!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,0x11a0);return 2;}
        else ctx->state=4;
        break;
    case 4:
        WIFIBATTLEMATCH_NET_GdbShutdown(ctx);ctx->state=5;
    case 5:return 1;
    case 6:
        result=DWC_GdbCancelRequest();
        if(result==0) {ctx->pollCount=0;ctx->state=7;}
        else {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,0x11be);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        break;
    case 7:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,0x11ca);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
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
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,0x1215);return 2;}
        ctx->state=1;break;
    case 1:
        result=DWC_GdbCreateRecordAsync((char *)d_021E2F1C,ctx->recBuf,ctx->fieldCount,(int *)&ctx->netIdPtr->head);
        if(result!=0) {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,0x1223);return 2;}
        ctx->pollCount=0;ctx->state=2;break;
    case 2:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,0x122f);ctx->state=4;break;}
        DWC_GdbProcess();result=DWC_GdbGetState();
        if(result==0||result==4) {WIFIBATTLEMATCH_NET_SetResultB(&ctx->err,result,0x123b);ctx->state=4;}
        else if(result==1)ctx->state=3;
        break;
    case 3:
        result=DWC_GdbGetAsyncResult();
        if(result==0) {WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,0x124f);ctx->state=4;}
        else if(result!=1) {WIFIBATTLEMATCH_NET_GdbShutdown(ctx);WIFIBATTLEMATCH_NET_SetResultC(&ctx->err,result,0x1256);return 2;}
        else {
            if(ctx->netIdPtr->head==0)WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,2,0x125c);
            WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 1;
        }
        break;
    case 4:
        result=DWC_GdbCancelRequest();
        if(result==0) {ctx->pollCount=0;ctx->state=5;}
        else {WIFIBATTLEMATCH_NET_SetResultA(&ctx->err,result,0x126f);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
        break;
    case 5:
        if((ctx->pollCount)++>0xe10) {WIFIBATTLEMATCH_NET_SetErrorA(&ctx->err,1,0x127b);WIFIBATTLEMATCH_NET_GdbShutdown(ctx);return 2;}
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
        GF_PANIC_Fail((const char *)(g_021E2EF8), 0, (const char *)((sptr)g_021E2EF8));
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
    if(ctx->rapHandle!=0) GF_PANIC_Fail(d_021E2EF8,0,d_021E2EF8);
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
        GF_PANIC_Fail(d_021E2EF8, 0, d_021E2EF8);
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
            WIFIBATTLEMATCH_NET_SetResultD(&ctx->err,status,0x16a0);
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
            WIFIBATTLEMATCH_NET_SetResultD(&ctx->err,status,0x17a4);
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
