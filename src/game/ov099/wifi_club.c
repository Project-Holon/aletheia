/*
 * file:     wifi_club.c
 * unit:     yes
 * function: WIFICLUB_GetMessageIdByIndex, WIFICLUB_OpenYesNoMenu, WIFICLUB_PollYesNoMenu, WIFICLUB_SetPartnerNameWord, WIFICLUB_DeleteWindow, WIFICLUB_DeleteTimeIcon, WIFICLUB_ClearTalkWindow, WIFICLUB_UpdateTalkStream, WIFICLUB_PrintTalkMessage, WIFICLUB_ShowStreamedMessage, WIFICLUB_ShowMessage, WIFICLUB_ShowNoticeWindow, WIFICLUB_SetMenuListColors, WIFICLUB_CreateMenuList, WIFICLUB_CreateMainMenu, WIFICLUB_CreateAnswerMenu, WIFICLUB_DrawPlayerInfoWindow, WIFICLUB_DrawHeaderWindow, WIFICLUB_DeleteAllWindows, WIFICLUB_CreateTextBuffers, WIFICLUB_DeleteTextBuffers, WIFICLUB_OpenPartnerPanel, WIFICLUB_OpenPartnerPanelWithBg, WIFICLUB_CreateTrainerActor, WIFICLUB_DeleteTrainerActor, WIFICLUB_CreateTouchBar, WIFICLUB_DeleteTouchBar, WIFICLUB_LoadPanelGraphics, WIFICLUB_DrawPartnerPanel, WIFICLUB_GetVisitorMessageId, WIFICLUB_SetupRuleMenu, WIFICLUB_CreateKindMenu, WIFICLUB_CreateLevelMenu, WIFICLUB_CreateOptionMenu, WIFICLUB_DrawPartyListWindow, WIFICLUB_DeletePartyListWindow, WIFICLUB_CreatePartyIcons, WIFICLUB_LoadPartyIcons, WIFICLUB_DeletePartyIcons, WIFICLUB_ShowPartyIconHalf, WIFICLUB_FreezePartyIcons, WIFICLUB_CreateRuleChoiceMenu, WIFICLUB_ShowRuleWindow, WIFICLUB_DeleteRuleWindow, WIFICLUB_ResetTimeIcon, WIFICLUB_DeleteMenuAndIcons, WIFICLUB_StartVoiceChat, WIFICLUB_StateStartInvite, WIFICLUB_StateOpenInviteYesNo, WIFICLUB_StateInviteYesNo, WIFICLUB_StateRestartInvite, WIFICLUB_StateOpenMainMenu, WIFICLUB_StateMainMenu, WIFICLUB_StateOpenNoticeYesNo, WIFICLUB_StateNoticeYesNo, WIFICLUB_StateOpenVoiceYesNo, WIFICLUB_StateVoiceYesNo, WIFICLUB_StateWaitKeyRetry, WIFICLUB_ShowScenePrompt, WIFICLUB_StateOpenSceneYesNo, WIFICLUB_StateSceneYesNo, WIFICLUB_StateKeyThenExit, WIFICLUB_StateSyncAsGuest, WIFICLUB_StateCountdownExit, WIFICLUB_StateExitAccepted, WIFICLUB_StateExitDeclined, WIFICLUB_StateExitRuleFail, WIFICLUB_StateStartScene, WIFICLUB_StateOpenRuleMenu, WIFICLUB_StateRuleMenu, WIFICLUB_StateOpenKindMenu, WIFICLUB_StateKindMenu, WIFICLUB_StateOpenLevelMenu, WIFICLUB_StateLevelMenu, WIFICLUB_StateOpenOptionMenu, WIFICLUB_StateOptionMenu, WIFICLUB_CheckPartyAgainstRules, WIFICLUB_LoadSavedRegulation, WIFICLUB_FreeRegulation, WIFICLUB_CheckSavedRegulation, WIFICLUB_LoadPickedRegulation, WIFICLUB_LoadOwnRegulation, WIFICLUB_ApplyRuleId, WIFICLUB_StateCheckRules, WIFICLUB_StateRuleViolationKey, WIFICLUB_StateViolationListKey, WIFICLUB_StateRuleTextKey, WIFICLUB_StateShowRuleSet, WIFICLUB_StateRuleSetKey, WIFICLUB_StateShowRulePreview, WIFICLUB_StateRulePreviewDone, WIFICLUB_StateRulePreviewKey, WIFICLUB_StateOpenEntryPrompt, WIFICLUB_StatePollEntryPrompt, WIFICLUB_StateCancelOnKey, WIFICLUB_StateCheckEntryRules, WIFICLUB_StateCancelOnKeyAfterMessage, WIFICLUB_StateRegisterEntryParty, WIFICLUB_StateOpenPartyMenu, WIFICLUB_StateUpdatePartyMenu, WIFICLUB_StateSendRegisteredParty, WIFICLUB_StateSyncAfterPartySend, WIFICLUB_StateShowRuleMatchMessage, WIFICLUB_StateWaitRuleMessageTimer, WIFICLUB_ApplyChosenRule, WIFICLUB_StateShowPartyViolations, WIFICLUB_StateShowBoxPartyViolations, WIFICLUB_StateCloseViolationList, WIFICLUB_StateBranchOnSeat, WIFICLUB_StateOpenWaitPrompt, WIFICLUB_StatePollWaitPrompt, WIFICLUB_StateWaitSyncAndResume, WIFICLUB_StateWaitSyncAndReturnToIdle, WIFICLUB_StateStartLeaveSync, WIFICLUB_StateShowLeaveMessageParent, WIFICLUB_StateDisableAutoExitA, WIFICLUB_StateShowLeaveMessageByRoleA, WIFICLUB_StateDisableAutoExitB, WIFICLUB_StateShowLeaveMessageByRoleB, WIFICLUB_StateReturnToIdle, WIFICLUB_StateShowLeaveMessageBySeat, WIFICLUB_StateResetNetOptions, WIFICLUB_StateShowRuleChoiceMessage, WIFICLUB_StateOpenRuleChoicePrompt, WIFICLUB_StatePollRuleChoicePrompt, WIFICLUB_StateSendSeatRequest, WIFICLUB_StateSendModeToPeer, WIFICLUB_StateStartReplySync, WIFICLUB_StateSendReplyCode, WIFICLUB_StateShowDisconnectNotice, WIFICLUB_StateBranchOnSeatAfterNotify, WIFICLUB_StateOpenLeavePrompt, WIFICLUB_StatePollLeavePrompt, WIFICLUB_StateWaitSyncAndContinue, WIFICLUB_StateHandlePeerPhase, WIFICLUB_StateCloseMessageOnKey, WIFICLUB_StateApplyRuleSelection, WIFICLUB_LoadFriendRoster, WIFICLUB_GetFirstFriendEntry, WIFICLUB_CopyFriendEntry, WIFICLUB_StartNetSession, WIFICLUB_GetStatusKind, WIFICLUB_GetStatusPhase, WIFICLUB_IsBusyPhase, WIFICLUB_IsActivePhase, WIFICLUB_IsKindActive, WIFICLUB_ShouldEnterWaitMode, WIFICLUB_HasEnoughPartyMembers, WIFICLUB_HasRuleViolation, WIFICLUB_ChangeNetMode, WIFICLUB_InitScreen, WIFICLUB_ExitScreen, WIFICLUB_VBlankTask, WIFICLUB_InitVram, WIFICLUB_InitBackgrounds, WIFICLUB_AddPeerActor, WIFICLUB_RemovePeerActor, WIFICLUB_ClearPeerActors, WIFICLUB_FindPeerActor, WIFICLUB_LoadBgResources, WIFICLUB_FreeBgResources, WIFICLUB_DrawTileBlock, WIFICLUB_GetPhaseIconTile, WIFICLUB_DrawPhaseIcon, WIFICLUB_GetIconPalette, WIFICLUB_BeginIdle, WIFICLUB_ExitHook, WIFICLUB_InitPlanesAndText, WIFICLUB_TaskHook, WIFICLUB_InitSprites, WIFICLUB_StateEnterClub, WIFICLUB_StateResetBgScroll, WIFICLUB_PublishOwnStatus, WIFICLUB_BuildOwnStatus, WIFICLUB_RefreshVisibleList, WIFICLUB_SyncActorsWithPeers, WIFICLUB_OnFatalError, WIFICLUB_StateWaitIntroMessage, WIFICLUB_StateOpenExitPrompt, WIFICLUB_StatePollExitPrompt, WIFICLUB_StateRestartMatch, WIFICLUB_StateWatchLogin, WIFICLUB_StateWatchLoginAndSave, WIFICLUB_StateWaitSave, WIFICLUB_StateWatchConnection, WIFICLUB_StateShowSaveNotice, WIFICLUB_StateWaitSaveNotice, WIFICLUB_CreateTitleWindows, WIFICLUB_IsFriendRequestFromPeer, WIFICLUB_StateHandleNetError, WIFICLUB_ResetClubScreen, WIFICLUB_StateReturnToClub, WIFICLUB_IsNetStateConnected, WIFICLUB_HasNewClientAid, WIFICLUB_IsNetStateDisconnecting, WIFICLUB_SyncPresenceLists, WIFICLUB_DropActorsOfMissingPeers, WIFICLUB_RequestSelectionRefresh, WIFICLUB_UpdatePeerActors, WIFICLUB_ReleaseSlotActors, WIFICLUB_StateLobbyMain, WIFICLUB_StateLobbyConnected, WIFICLUB_StateCheckPeerSelection, WIFICLUB_StateWaitKeyReturnToLobby, WIFICLUB_StateWaitPeerReply, WIFICLUB_StateStartMessageDismiss, WIFICLUB_StateWaitMessage, WIFICLUB_StateSyncTimingStart, WIFICLUB_UpdateVchatIndicator, WIFICLUB_StateVchatInvite, WIFICLUB_StateVchatAnswerWait, WIFICLUB_StateVchatYesNo, WIFICLUB_StateSendVchatReady, WIFICLUB_StateWaitVchatEnd, WIFICLUB_StateLeaveSyncWait, WIFICLUB_StateDisconnectSync, WIFICLUB_StateLeaveDelay, WIFICLUB_StateErrorMessageWait, WIFICLUB_StateDisconnectAckWait, WIFICLUB_StateLeaveTimeout, WIFICLUB_StateLeaveCancel, WIFICLUB_StateUnusedA, WIFICLUB_StateUnusedB, WIFICLUB_StateUnusedC, WIFICLUB_StateCountdownThenConfirm, WIFICLUB_StateStartPrompt, WIFICLUB_StateWaitPrompt, WIFICLUB_StatePollPrompt, WIFICLUB_StateOpenPartnerMenu, WIFICLUB_StateShowPartnerMenuMessage, WIFICLUB_ClosePartnerMenu, WIFICLUB_StatePartnerMenu, WIFICLUB_StateSendChoiceAfterDelay, WIFICLUB_StateOpenMenuChoicePrompt, WIFICLUB_StatePollMenuChoicePrompt, WIFICLUB_StateOpenRequestPrompt, WIFICLUB_StatePollRequestPrompt, WIFICLUB_StateWaitKeyDisconnectToLobby, WIFICLUB_StateDisconnectToLobby, WIFICLUB_StateSelectionMenu, WIFICLUB_StateShowPartnerStatusMessage, WIFICLUB_StateOpenAnswerMenu, WIFICLUB_TryStartPartnerRequest, WIFICLUB_StateWaitPartnerResponse, WIFICLUB_StatePollCancelRequestPrompt, WIFICLUB_StateAnswerMenu, WIFICLUB_DisableVoiceChat, WIFICLUB_StatePartnerMenuResult, WIFICLUB_StateRequestJoinPartner, WIFICLUB_StateWaitJoinAnswer, WIFICLUB_ReturnSecondArgA, WIFICLUB_ReturnSecondArgB, WIFICLUB_StateLeaveLinkToLobby, WIFICLUB_StateOnPartnerConnected, WIFICLUB_HandleNetFailure, WIFICLUB_StateWaitNegotiation, WIFICLUB_RecvFriendTrainerCard, WIFICLUB_RecvSceneResult, WIFICLUB_GetSeatPartyBuffer, WIFICLUB_RecvResumeState, WIFICLUB_RecvRuleId, WIFICLUB_RecvPeerChoice, WIFICLUB_StateSendTrainerCard, WIFICLUB_StateSendChoiceMessage, WIFICLUB_StateCheckPeerPhase, WIFICLUB_StateWaitSyncEnableAutoExit, WIFICLUB_IsTalkFinishedOrClosed, WIFICLUB_StateBranchOnPartnerPhase, WIFICLUB_StateBeginIdleAfterNet, WIFICLUB_StateWaitKeyOrNetUp, WIFICLUB_StateClearTalkToLobby, WIFICLUB_StateOpenQuitYesNo, WIFICLUB_StatePollQuitYesNo, WIFICLUB_StateExitNetwork, WIFICLUB_StateCountdownToLobby, WIFICLUB_StateOpenRetryYesNo, WIFICLUB_StatePollRetryYesNo, WIFICLUB_StateOpenSeatYesNo, WIFICLUB_StatePollSeatYesNo, WIFICLUB_ResolveNetRunState, WIFICLUB_SetOwnStatusAndPublish, WIFICLUB_SetOwnStatusKindPhase, WIFICLUB_ToggleOwnSeat, WIFICLUB_ResetOwnSeatStatus, WIFICLUB_ClosePartnerPanel, WIFICLUB_ClosePanelIfSlotSelected, WIFICLUB_ClosePanelIfTouchActive, WIFICLUB_IsSlotPanelOpen, WIFICLUB_OpenSlotPanel, WIFICLUB_CloseSlotPanel, WIFICLUB_UpdateSlotPanel, WIFICLUB_RedrawSlotPanelIfPending, WIFICLUB_IsSlotPanelDismissed, WIFICLUB_GetSelectedSlotPlusOne, WIFICLUB_ResetSlotSelection, WIFICLUB_OnSlotButtonEvent, WIFICLUB_TickSlotBlink, WIFICLUB_CreateSlotPanelWindows, WIFICLUB_DeleteSlotPanelWindows, WIFICLUB_AddTileOffsetToTileMap, WIFICLUB_SetSlotState, WIFICLUB_ClearSlotState, WIFICLUB_GetSlotState, WIFICLUB_OpenPanelOrRedrawPage, WIFICLUB_RequestPanelRedraw, WIFICLUB_EmptyHook, WIFICLUB_RedrawSlotPanels, WIFICLUB_DrawSlotFrame, WIFICLUB_PrintSlotName, WIFICLUB_DrawSlotStatusIcons, WIFICLUB_SetFriendNameWord, WIFICLUB_GetFriendStatus, WIFICLUB_GetFriendConnectionStatus, WIFICLUB_AddNetCommandsAndCheckFriend, WIFICLUB_EnableTouchBar, WIFICLUB_DisableTouchBar, WIFICLUB_UpdateBgmFade, WIFICLUB_StartBgmFade, WIFICLUB_InitBgmVolume, WIFICLUB_ProcInit, WIFICLUB_ProcMain, WIFICLUB_ProcExit, WIFICLUB_GetStatusActionState, WIFICLUB_SetStatusActionState, WIFICLUB_GetStatusActionArg, WIFICLUB_SetStatusActionArg, WIFICLUB_GetStatusSeatFlag, WIFICLUB_SetStatusSeatFlag, WIFICLUB_IsPeerAddrOfStatus, WIFICLUB_CountChangeAndCopyPeerAddr, WIFICLUB_CopyZeroToDeviceAddr, WIFICLUB_RunPeerAddrRoutine, WIFICLUB_GetStatusModeFlag, WIFICLUB_SetStatusModeFlag, WIFICLUB_GetStatusChangeCount
 * address:  0x021BA81C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gWifiClubMessageIdTable  0x021C39E0  data  a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   gWifiClubYesNoWindowTemplate 0x021C371A data a2
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   func_02009864  0x02009864  thumb
 *   func_020099E4  0x020099E4  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_CTRL_Update  0x02028484  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02020D0C  0x02020D0C  thumb
 *   BMP_MENULIST_SetColors  0x02020268  thumb
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   BMP_MENULIST_Create 0x0201FF30 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02020CF8 0x02020CF8 thumb
 *   gWifiClubMainMenuHeader  0x021C3B00  data
 *   gWifiClubMainMenuItems  0x021C3A50  data
 *   gWifiClubAnswerMenuHeaderTemplate 0x021C37A0 data a4
 *   gWifiClubAnswerMenuItems 0x021C3730 data a4
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   func_02008730 0x02008730 thumb
 *   func_02008510 0x02008510 thumb
 *   func_02008550 0x02008550 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_MENULIST_Delete 0x0202020C thumb
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   STRBUF_Create  0x020457B0  arm
 *   unit_0201C440  0x0201C440  thumb
 *   TCBL_Create  0x0203101C  arm
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_DecodeTileSource  0x02040AF0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   gWifiClubTrainerSpritePos     0x021C37D4  data   ov099  a2
 *   CURSOR_MOVE_GetTableGroup  0x02025C88  thumb
 *   POKEGRA_OpenTrainerHandle  0x0202DA04  thumb
 *   POKEGRA_RegisterTrainerCgr  0x0202DA48  thumb
 *   POKEGRA_RegisterTrainerPalette  0x0202DA18  thumb
 *   POKEGRA_RegisterTrainerCellAnim  0x0202DA6C  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   gWifiClubTouchBarTable     0x021C388C  data   ov099  a4
 *   MI_CpuFill8  0x02082BCC  arm
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   TOUCHBAR_SetButtonKeyMask  0x021B6578  thumb  ov067
 *   TOUCHBAR_Delete  0x021B639C  thumb  ov067
 *   func_020490F4  0x020490F4  arm
 *   func_02049990  0x02049990  arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   gWifiClubVisitorMessageIds     0x021C398C  data   ov099
 *   gWifiClubMenuItemTable  0x021C3A70  data  a4
 *   gWifiClubRuleMenuHeader  0x021C3B68  data  a4
 *   gWifiClubRuleMenuItems  0x021C3AD0  data  a4
 *   gWifiClubMenuHeaderSlot  0x021C3B30  data
 *   data_021C3B34  0x021C3B34  data
 *   gWifiClubKindMenuItems  0x021C3A78  data
 *   gWifiClubLevelMenuItems  0x021C3A00  data
 *   gWifiClubOptionMenuItems  0x021C3A18  data
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKE_TOOL_GetGraphicIndex 0x0201BA68 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcIdSub  0x0201BC78  thumb
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   unit_0204B92C  0x0204B92C  arm
 *   unit_0204B3DC  0x0204B3DC  arm
 *   gWifiClubRuleChoiceItems 0x021C39F0 data a4
 *   func_02020D10 0x02020D10 thumb
 *   POKE_REGULATION_CreateText 0x0201A4D4 thumb
 *   REGULATION_CreateCupName 0x0200AE3C thumb
 *   POKE_REGULATION_DeleteText 0x0201A570 thumb
 *   TIME_ICON_CreateNode  0x0202EE8C  thumb
 *   DWC_RAP_SetVchatEnabled  0x02156BC4  thumb  ov009
 *   DWC_RAP_EnableLocalVchat  0x02156330  thumb  ov009
 *   DWC_RAP_StartVchatDefaultHeap  0x021563C0  thumb  ov009
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_NotifyUserEvent  0x0203D1E8  arm
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_MENULIST_Main 0x020200CC thumb
 *   APP_ENV_HasParentalControlBits 0x0202EB14 thumb
 *   APP_ENV_IsRunOnTwl 0x0202EB0C thumb
 *   WIFICLUBACTOR_TickBlink  0x021B9B64  thumb  ov099
 *   KEY_GetTrg 0x020362DC arm
 *   gWifiClubSceneMessageIds     0x021C37DC  data  a4
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   POKE_REGULATION_CheckParty 0x0201A090 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BATTLE_BOX_GetFromSave 0x0200BAC8 thumb
 *   BATTLE_BOX_HasMon 0x0200BBA8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   gWifiClubRuleIdTable     0x021C3A30  data  a4
 *   func_020307B0  0x020307B0  arm
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   BMP_MENULIST_GetPos 0x020202FC thumb
 *   POKE_REGULATION_GetDataSize  0x0201A918  thumb
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   REGULATION_GetRuleValue  0x0200AE54  thumb
 *   d_021C38EC     0x021C38EC  data  ov099  a4
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_GetInitParam 0x0203D798 arm
 *   d_021C390C 0x021C390C data ov099 a4
 *   GAME_DATA_GetField1A0  0x0201283C  thumb
 *   func_02009860  0x02009860  thumb
 *   func_020099C8  0x020099C8  thumb
 *   func_02009C24  0x02009C24  thumb
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_CopyInitParam  0x0203D844  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   d_021C3B9C     0x021C3B9C  data
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   POKEPARTY_GetNonEggCount 0x0201AA1C thumb
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_020056A0 0x020056A0 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   WIFICLUBACTOR_IsReady 0x021B96CC thumb ov099
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   data_021C3AA0  0x021C3AA0  data
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_InitSlot 0x020414C4 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   d_021C37F4 0x021C37F4 data a4
 *   d_021C396C 0x021C396C data a4
 *   d_021C382C 0x021C382C data a4
 *   d_021C384C 0x021C384C data a4
 *   d_021C386C 0x021C386C data a4
 *   d_021C38AC 0x021C38AC data a4
 *   d_021C38CC 0x021C38CC data a4
 *   d_021C392C 0x021C392C data a4
 *   d_021C394C 0x021C394C data a4
 *   WIFICLUBACTOR_Exit 0x021B9670 thumb ov099
 *   WIFICLUBACTOR_GetActorId  0x021B9A50  thumb  ov099
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049E74 0x02049E74 arm
 *   func_02049EF4 0x02049EF4 arm
 *   BG_SYS_DeleteHalf  0x0203FB44  arm
 *   func_02042FB0  0x02042FB0  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   d_021C3740  0x021C3740  data  a4
 *   d_021C375C  0x021C375C  data  a4
 *   d_021C3AA0  0x021C3AA0  data  a4
 *   func_02009B80 0x02009B80 thumb
 *   DWC_RAP_IsDisconnected 0x02156D84 thumb ov009
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   GFL_USE_GetTargetBgmNo 0x02005C4C thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   sub_0204047C  0x0204047C  arm
 *   DWC_RAP_SetOwnStatus  0x0215683C  thumb  ov009
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200856C 0x0200856C thumb
 *   func_02008570 0x02008570 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200853C 0x0200853C thumb
 *   WIFICLUBACTOR_SetActorMode 0x021B9B00 thumb ov099
 *   func_02009918 0x02009918 thumb
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_IsIdle 0x0203D210 arm
 *   CLACT_FlushOamIfPending 0x0204A698 arm
 *   GFL_NET_STATE_WifiStartMatch 0x0203C8A8 arm
 *   DWC_RAP_IsUserDataChanged 0x02156C84 thumb ov009
 *   GFL_NET_STATE_IsWifiLoginState 0x0203C600 arm
 *   GFL_NET_STATE_IsFatalError 0x0203CB00 arm
 *   GFL_NET_STATE_GetWifiState 0x0203C3EC arm
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   DWC_RAP_ClearUserDataChanged 0x02156C98 thumb ov009
 *   GFL_NET_STATE_IsWifiLoginOrConnected 0x0203C628 arm
 *   GFL_NET_STATE_IsWifiDisconnectFinal 0x0203C5EC arm
 *   GFL_NET_IsConnectMember 0x0203D1C0 arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_02009A34 0x02009A34 thumb
 *   DWC_RAP_SetAcceptFriendCallback 0x02155664 thumb ov009
 *   func_02009A54 0x02009A54 thumb
 *   WIFICLUBACTOR_Init 0x021B95A0 thumb ov099
 *   WIFICLUBACTOR_SpawnCursorActor 0x021B9900 thumb ov099
 *   DWC_RAP_GetNewClientAid  0x02156B8C  thumb  ov009
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   WIFICLUBACTOR_StartDespawn 0x021B99F4 thumb ov099
 *   WIFICLUBACTOR_SpawnSlotActor 0x021B9968 thumb ov099
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   WIFICLUBACTOR_ResumeActorSprite  0x021B98E4  thumb  ov099
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   func_02005728 0x02005728 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   DWC_RAP_GetCanceledPeerIndex 0x02156BA8 thumb ov009
 *   DWC_RAP_GetVchatEnabled 0x02156B70 thumb ov009
 *   WIFICLUBACTOR_RestartBlink 0x021B9B54 thumb ov099
 *   WIFICLUBACTOR_GetMode 0x021B98FC thumb ov099
 *   WIFICLUBACTOR_ShowMarkerAtActor 0x021B989C thumb ov099
 *   WIFICLUBACTOR_HideMarker 0x021B98F0 thumb ov099
 *   WIFICLUBACTOR_Update 0x021B96D0 thumb ov099
 *   WIFICLUBACTOR_StartBlinkOnTile 0x021B9B24 thumb ov099
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   DWC_RAP_GetVchatState 0x02156B68 thumb ov009
 *   DWC_RAP_IsVchatActive 0x021563EC thumb ov009
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   WIFICLUBACTOR_RestoreActorUpdate 0x021B9AE0 thumb ov099
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   WIFICLUBACTOR_GetActorFacing 0x021B9A60 thumb ov099
 *   WIFICLUBACTOR_StartTurn 0x021B9A70 thumb ov099
 *   d_021C3804 0x021C3804 data a4
 *   d_021C3818 0x021C3818 data a4
 *   DWC_RAP_GetResult 0x02156D5C thumb ov009
 *   WIFICLUBACTOR_AddNetCommands 0x021BA7D8 thumb ov099
 *   GFL_NET_HANDLE_IsNegotiationDone 0x020399B8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_HANDLE_CheckNegotiation 0x02039ACC arm
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   sub_0203CD98  0x0203CD98  arm
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   d_021C377C 0x021C377C data a4
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   WIFICLUBACTOR_GetCursorTileAttr 0x021B9800 thumb ov099
 *   WIFICLUBACTOR_GetCursorTileBelowAttr 0x021B984C thumb ov099
 *   BUTTON_MAN_UpdateSlots 0x02051C88 arm
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone  0x021B6448  thumb  ov067
 *   d_021C3720     0x021C3720  data   ov099
 *   func_02049658  0x02049658  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   DWC_RAP_GetFriendStatusData  0x02156860  thumb  ov009
 *   DWC_RAP_GetFriendStatus  0x02156874  thumb  ov009
 *   sub_0203C2B0  0x0203C2B0  arm
 *   WIFICLUBACTOR_SetMode  0x021B98F8  thumb  ov099
 *   GFL_USE_SetBgmTrackVolume 0x02005F24 thumb
 *   GFL_USE_SetPlayerVolumes  0x02005CBC  thumb
 *   PM_VOICE_SetMasterVolume  0x02006734  thumb
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   GFL_NET_SetUserArg 0x0203D668 arm
 *   func_0200873C 0x0200873C thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   func_0200FB24 0x0200FB24 thumb
 *   CLACT_DrawSystem 0x0204A600 arm
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   TCBL_Main 0x020310C4 arm
 *   gWifiClubStateHandlers 0x021C3C0C data a4
 *   WIFICLUBACTOR_RemoveNetCommands 0x021BA7F8 thumb ov099
 *   REGULATION_Copy 0x0200AE08 thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   MYSTATUS_GetSize  0x02008468  thumb  arm9
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   MISC_SAVEDATA_InsertRecentValue  0x0200ED54  thumb  arm9
 *   GFL_NET_ERR_UpdateFriendRecord  0x0200F4E4  thumb  arm9
 *   GAME_DATA_GetPlayerStatusById  0x02012950  thumb  arm9
 */
#include "wifi_club_work.h"
#include "wifi_club.h"
#include "wifi_club_types.h"

struct GameData;
struct PokeParty;
struct BmpWin;
struct PrintQueue;
struct BmpMenuList;
struct NetHandle;
struct Regulation;
struct BmpData;
struct ClactInitParam;
struct ClactUnit;
struct FriendEntry;
struct FriendRoster;
struct GfFont;
struct MsgData;
struct PlayerProfile;
struct Task;
struct ClactRenderer;
struct VramBankConfig;
struct WordSet;
typedef struct WifiClubSpritePos { u16 x, y, animSeq, priority; } WifiClubSpritePos;

typedef struct WifiClubTouchBarTable { s32 words[8]; } WifiClubTouchBarTable;

typedef struct WifiClubStatusMessageTable { s32 messageId[16]; } WifiClubStatusMessageTable;

typedef struct WifiClubTouchBarSetup {
    WifiClubTouchBarTable *table;  /* 0x00 */
    u32 buttonCount;               /* 0x04 */
    void *clactUnit;               /* 0x08 */
    u32 paletteSlot;               /* 0x0C */
    u32 originX;                   /* 0x10 */
    u32 originY;                   /* 0x14 */
    s32 priority;                  /* 0x18 */
    s32 reserved1C;                /* 0x1C */
} WifiClubTouchBarSetup;

typedef struct GflNetHandle GflNetHandle;

/* Second menu header, reached through the symbol that sits 4 bytes before it. */
typedef struct WifiClubMenuHeaderSlot { u32 reserved; WifiClubMenuListHeader header; } WifiClubMenuHeaderSlot;

typedef struct WifiClubIconPos { u16 x, y, z; u8 animSeq, priority; } WifiClubIconPos;

typedef struct WifiClubSceneMessages { u32 messageId[3]; } WifiClubSceneMessages;

typedef int (*WifiClubStateHandler)(WifiClubWork *work, int state);

extern void GF_FONT_SetDefaultTextColor(void);
extern void *BMP_MENU_CreateYesNo(const void *, u16, u8, u8, u16);
extern u32 BMP_MENU_ProcessYesNo(void *);
extern u32 func_02009864(const void *friendList, u32 index, u32 field);
extern void func_020099E4(void *friendList, int index, StrBuf *dest);
extern void WORDSET_SetSlotTag(WordSet *wordSet, u32 index, StrBuf *src, u32 n, u32 f, u32 c);
extern void BMP_MENUWORK_DrawWindowBorder(BmpWin *win, u32 kind);
extern u32 BMP_WIN_Delete(struct BmpWin *window);
extern void TIME_ICON_Delete(u8 *icon);
extern u32 PRINTSYS_QUE_IsFinished(const PrintQue *);
extern void PRINTSYS_QUE_Clear(PrintQue *);
extern void PRINTSYS_PrintStreamDelete(PrintStream *stream);
extern void APP_KEYCURSOR_Update(void *keyCursor, PrintStream *stream, BmpWin *win);
extern s32 PRINTSYS_CTRL_Update(void *streamWait, PrintStream *stream);
extern signed char MSG_SPEED_GetWait(void);
extern BmpWin *BMP_WIN_Create(u32 layer, u8 x, u8 y, u32 width, u8 height, u8 palette, u8 slot);
extern void func_02045CAC(MsgData *bank, u32 index, StrBuf *dest);
extern void WORDSET_CopyTaggedText(WordSet *ws, StrBuf *dst, StrBuf *src);
extern void *BMP_WIN_GetBmp(struct BmpWin *window);
extern void BMP_Clear(struct BmpData *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(BmpWin *win, int a1, int a2, int a3);
extern void PRINTSYS_Print(void *bmp, s16 x, s16 y, StrBuf *str, void *font);
extern PrintStream *PRINTSYS_PrintStream(BmpWin *win, u32 x, u32 y, StrBuf *str, void *font, u32 speed, void *tcbl, u32 prio, u32 heapId, u32 palette);
extern void PRINTSYS_CTRL_Init(void *streamWait, u32 v);
extern void BMP_WIN_TransferChars(struct BmpWin *window);
extern void BMP_WIN_MakeScreen(BmpWin *win);
extern void func_02041B6C(u32 bit);
extern void func_02049B40(u32 archiveId, u32 fileId, u32 type, u32 offset, u32 size, u16 heapId);
extern void BMP_WIN_ClearScreen(BmpWin *win);
extern WifiClubWork *func_02020D0C(void *menuList);
extern void BMP_MENULIST_SetColors(void *menuList, u8 a, u8 b, u8 c);
extern void *BMP_MENUWORK_Create(u32, u32);
extern void BMP_MENUWORK_AddMsgItem(void *menuWork, MsgData *bank, u32 messageId, u32 value, u32 heapId);
extern void *BMP_MENULIST_Create(WifiClubMenuListHeader *header, u16 a, u16 b, u32 heapId);
extern u32 PRINTSYS_QUE_Main(PrintQue *);
extern void func_02020CF8(void *menuList, int heapId);
extern void *func_02008730(void *saveData);
extern StrBuf *func_02008510(void *myStatus, int heapId);
extern u8 func_02008550(const struct PlayerProfile *obj);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void STRBUF_Delete(StrBuf *);
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void BG_SYS_PushTile(u32);
extern void BMP_MENULIST_Delete(struct BmpMenuList *menu, u16 *cursorPos, u16 *listPos);
extern u32 BMP_MENUWORK_Delete(void *p);
extern void BMP_MENU_DeleteYesNo(void *menu);
extern StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern PrintQue *unit_0201C440(int heapId);
extern void *TCBL_Create(u16 heapId, u16 tag, u32 count, u32 workSize);
extern void *APP_KEYCURSOR_CreateDefault(int a, int b, int c, int d);
extern int APP_KEYCURSOR_Delete(void *keyCursor);
extern void TCBL_Destroy(void *tcbl);
extern void PRINTSYS_QUE_Delete(PrintQue *);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);
extern void BG_SYS_FreeSlot(u32);
extern u32 CURSOR_MOVE_GetTableGroup(u32 x);
extern void *POKEGRA_OpenTrainerHandle(int a0);
extern s32 POKEGRA_RegisterTrainerCgr(void *a, int b, int c, u16 d);
extern s32 POKEGRA_RegisterTrainerPalette(void *a, u32 b, u32 c, u32 d, u16 e);
extern s32 POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *CLACT_CreateActor(void *owner, s32 charRes, s32 palRes, s32 cellRes, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_DeleteActor(void *actor);
extern void CLACT_ReleaseCharacter(s32 i);
extern void CLACT_ReleasePalette(s32 i);
extern void CLACT_ReleaseCellAnim(s32 i);
extern void MI_CpuFill8(void *,int,int);
extern void *TOUCHBAR_Create(WifiClubTouchBarSetup *setup, int heap);
extern void TOUCHBAR_SetButtonKeyMask(void *touchBar, unsigned int id, int v);
extern void TOUCHBAR_Delete(void *touchBar);
extern void *func_020490F4(u32 archiveId, u32 heapId);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void PRINTSYS_PrintColor(void *bmp, int x, s16 y, StrBuf *str, void *font, u32 color);
extern void WORDSET_SetSlotNumber(WordSet *wordSet, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 param, u32 unused);
extern void *POKE_TOOL_GetBoxParam(void *mon);
extern u32 POKE_TOOL_GetGraphicIndex(void *boxMon);
extern s32 CLACT_RegisterCharacter(void *archive, u32 b, u32 c, u32 a3, u16 flags);
extern int POKE_TOOL_GetIconPalette(void *boxMon);
extern void CLACT_SetActorPaletteOffset(void *actor, u32 v, u32 flag);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *archive, u32 a1, u32 a2, u32 a3, u16 a4);
extern int POKE_TOOL_GetIconCellArcIdSub(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern s32 CLACT_RegisterCellAnim(void *archive, u32 first, u32 second, u32 mode);
extern void CLACT_SetActorAutoAnim(void *actor, unsigned int v);
extern void CLACT_SetActorDrawEnable(void *actor, unsigned int v);
extern void unit_0204B92C(void *actor, unsigned int v);
extern void unit_0204B3DC(void *actor, unsigned int v);
extern void func_02020D10(void *menuList, u32 v);
extern StrBuf **POKE_REGULATION_CreateText(void *regulationData, WordSet *wordSet, u16 heapId, u32 flag);
extern StrBuf *REGULATION_CreateCupName(void *regulationData, u32 heapId);
extern void POKE_REGULATION_DeleteText(StrBuf **text);
extern u8 *TIME_ICON_CreateNode(void *tcbl, BmpWin *win, u8 c, u8 d, u16 e);
extern void DWC_RAP_SetVchatEnabled(int);
extern int DWC_RAP_EnableLocalVchat(void);
extern void DWC_RAP_StartVchatDefaultHeap(int a);
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_NotifyUserEvent(unsigned int unused, void *arg);
extern int GFL_NET_IsParentAid();
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct NetHandle *handle, unsigned int syncId, unsigned int range);
extern u32 PRINTSYS_QUE_IsExistTarget(PrintQue *queue, void *bmp);
extern s32 BMP_MENULIST_Main(void *menuList);
extern int APP_ENV_HasParentalControlBits(void);
extern unsigned int APP_ENV_IsRunOnTwl(void);
extern u32 KEY_GetTrg(void);
extern void *GAME_DATA_GetMyParty(const struct GameData *p);
extern int POKE_REGULATION_CheckParty(void *regulationData, void *party, u32 *mask);
extern void *GAME_DATA_GetSaveControl(void *gameData);
extern void *BATTLE_BOX_GetFromSave(void *saveControl);
extern u32 BATTLE_BOX_HasMon(void *obj);
extern void *func_0200BAF4(void *obj, int heapId);
extern u32 func_020307B0(void *p);
extern void *POKE_REGULATION_Load(u32 ruleId, int heapId);
extern void GF_FONT_SetDefaultTextColor(void);
extern void POKEPARTY_Copy(const struct PokeParty *src, struct PokeParty *dst);
extern void BMP_MENULIST_GetPos(struct BmpMenuList *menu, u16 *cursorPos, u16 *listPos);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(struct NetHandle *handle, u32 targetId, u32 command, u32 size, void *data, u32 priority, u32 flags, u32 reliable);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct NetHandle *handle, u32 syncId, u32 range);
extern u32 REGULATION_GetRuleValue(struct Regulation *regulation, u32 ruleId);
extern void GFL_NET_SetAutoExit(u8 enable);
extern int GFL_NET_SetLoginOption(int);
extern int GFL_NET_SendToHandle(struct NetHandle *handle, u32 command, u32 size, u32 data);
extern void *GFL_NET_GetInitParam(void);
extern void *GAME_DATA_GetField1A0(void *gameData);
extern struct FriendRoster *func_02009860(struct FriendRoster *obj);
extern struct FriendEntry *func_020099C8(struct FriendRoster *obj, int i);
extern void func_02009C24(struct FriendRoster *obj, int src, int dest);
extern int OS_IsRunOnTwl(void);
extern void GFL_NET_StartSession(WifiClubNetInit *init, u32 flags, u32 userData);
extern void GFL_NET_CopyInitParam(void *dst);
extern u32 GAME_DATA_GetBoxManager(const struct GameData *p);
extern u32 POKEPARTY_GetNonEggCount(void *);
extern void GFL_NET_SetWaitMode(int);
extern void func_02030EAC(struct Task *n);
extern void BG_SYS_SetMainVisiblePlanes(u32);
extern void BG_SYS_SetSubVisiblePlanes(u32);
extern WordSet *WORDSET_CreateDefault(u32 heapId);
extern struct MsgData *func_02045B38(u32 resident, u32 archiveId, u32 fileId, u32 heapId);
extern struct GfFont *GF_FONT_Create(int archive, int fileId, int type, int flags, u32 heapId);
extern void BMP_SetDisplaySwap(u32);
extern void BMP_WIN_Init(u16);
extern void *func_020056A0(u32, u32, u32);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void CLACT_DeleteRenderer(void *p);
extern unsigned int CLACT_DeleteUnit(struct ClactUnit *bank);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern unsigned int MSGDATA_Delete(struct MsgData *rec);
extern unsigned int WORDSET_DeleteStrbufED04(WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_SetVramBanks(const struct VramBankConfig *c);
extern void BG_SYS_Create(u16);
extern void BG_SYS_SetGraphicsMode(WifiClubDispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const WifiClubBgTemplate *tmpl, u32 type);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern void BG_SYS_InitSlot(u32 idx);
extern void BG_SYS_SetVisibleLayer(int, u16);
extern void func_02049B68(void *archive, u32 type, u32 index, u32 offset, u32 size, u16 heapId);
extern u32 func_02049740(void *archive, u32 type, u32 index, u32 offset, u32 size, u16 heapId);
extern void *func_02049E74(void *archive, u32 type, u32 index, u32 outData, u16 heapId);
extern void *func_02049EF4(void *archive, u32 type, u32 index, void **outData, u16 heapId);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void WIPE_SYS_Start(void *unused, u32 type, u32 direction, u32 color, u32 frames, u32 step, u32 heapId);
extern void *BMP_MENUWORK_LoadFrameGfx(void *kind, u32 size, u32 flags, u32 heapId);
extern void CLACT_InitSystem(const struct ClactInitParam *cfg, u32 arg, u32 heapId);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct ClactRenderer *CLACT_CreateRenderer(u8 *param, u32 type, u32 heapId);
extern void CLACT_SetUnitRenderer(struct ClactUnit *bank, void *p);
extern void func_02009B80(struct FriendRoster *obj, int i);
extern int DWC_RAP_IsDisconnected(void);
extern void DWC_RAP_StopVchat(void);
extern u32 GFL_USE_GetTargetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void sub_0204047C(int idx, unsigned short val);
extern int DWC_RAP_SetOwnStatus(WifiClubPlayerStatus *status, int size);
extern u8 *GAME_DATA_GetMyStatus(void *);
extern u8 func_02008554(const struct PlayerProfile *obj);
extern u8 func_0200856C(const struct PlayerProfile *obj);
extern u8 func_02008570(const struct PlayerProfile *obj);
extern u32 func_02008530(const struct PlayerProfile *obj);
extern u32 func_0200853C(const struct PlayerProfile *obj);
extern void func_02009918(struct FriendRoster *obj, u32 i, u32 field, u32 value);
extern int GFL_NET_Exit(int force);
extern u32 GFL_NET_IsIdle(void);
extern void CLACT_FlushOamIfPending(void);
extern void GFL_NET_STATE_WifiStartMatch(void);
extern unsigned char DWC_RAP_IsUserDataChanged(void);
extern int GFL_NET_STATE_IsWifiLoginState(void);
extern int GFL_NET_STATE_IsFatalError(void);
extern int GFL_NET_STATE_GetWifiState(void);
extern int GAME_DATA_SaveStart(int gameData);
extern int GAME_DATA_SaveMain(u8 *p);
extern void DWC_RAP_ClearUserDataChanged(int v);
extern int GFL_NET_STATE_IsWifiLoginOrConnected(void);
extern int GFL_NET_STATE_IsWifiDisconnectFinal(void);
extern u32 GFL_NET_IsConnectMember(u32 aid);
extern void GFL_NET_STATE_WifiDisconnect(u32 force);
extern u32 func_02009A34(struct FriendRoster *obj);
extern void DWC_RAP_SetAcceptFriendCallback(void (*callback)(void));
extern u32 func_02009A54(struct FriendRoster *obj);
extern int DWC_RAP_GetNewClientAid(void);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, unsigned int n);
extern int MI_CpuCopy8(void *,void *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u32 WIPE_SYS_EndCheck(void);
extern void GFL_NET_STATE_SetError(int, u32, u32, u32);
extern u32 func_02005728(u32);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern int DWC_RAP_GetCanceledPeerIndex(void);
extern s16 DWC_RAP_GetVchatEnabled(void);
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern int DWC_RAP_GetVchatState(void *);
extern int DWC_RAP_IsVchatActive(void);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern u32 POKEPARTY_GetAliveNonEggCount(void *);
extern unsigned DWC_RAP_GetResult(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);
extern u32 GFL_NET_GetHandleNetID(struct NetHandle *p);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern void *GAME_DATA_GetPlayerStatusById(void *gameData, u32 index);
extern void MYSTATUS_Copy(void *, void *);
extern void *MISC_SAVEDATA_GetBlock44(void *);
extern void MISC_SAVEDATA_InsertRecentValue(void *l, u32 val);
extern int MYSTATUS_GetSize(void);
extern int GFL_NET_ERR_UpdateFriendRecord(void *o);
extern int GFL_NET_GetRunState(void);
extern void func_02009B3C(void *obj);
extern int sub_0203CD98(void);
extern void *BUTTON_MAN_Create(const void *table, void *callback, void *userData, int heap);
extern void BUTTON_MAN_Delete(void *);
extern s32 BUTTON_MAN_UpdateSlots(void *c);
extern void TOUCHBAR_Update(void *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *p);
extern unsigned int KEY_GetCont(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, const void *a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern WifiClubPlayerStatus *DWC_RAP_GetFriendStatusData(int i);
extern unsigned char DWC_RAP_GetFriendStatus(int i);
extern int sub_0203C2B0(int a);
extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);
extern void GFL_USE_SetPlayerVolumes(u32 value, u32 mask);
extern void PM_VOICE_SetMasterVolume(int v);
extern void GFL_HEAP_CreateChildHeap(u32, u32, u32);
extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);
extern void GFL_NET_SetUserArg(u32 arg);
extern void *func_0200873C(void *sys);
extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);
extern int DWC_RAPCOMMON_HandleNetError(int,int);
extern unsigned int func_0200FB24(void);
extern void WIPE_SetBrightnessFadeOut(unsigned int,unsigned int);
extern void CLACT_DrawSystem(void *);
extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *);
extern void TCBL_Main(void *p);
extern void REGULATION_Copy(const void *src, void *dest);
extern void func_020315D4(void *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void OS_GetMacAddress(void *);
u32 WIFICLUB_GetMessageIdByIndex(int i);
void WIFICLUB_OpenYesNoMenu(WifiClubWork *work);
u32 WIFICLUB_PollYesNoMenu(WifiClubWork *work);
void WIFICLUB_SetPartnerNameWord(WifiClubWork *work, int friendIndex);
BmpWin *WIFICLUB_DeleteWindow(BmpWin *win);
void WIFICLUB_DeleteTimeIcon(WifiClubWork *work);
void WIFICLUB_ClearTalkWindow(WifiClubWork *work);
int WIFICLUB_UpdateTalkStream(WifiClubWork *work);
void WIFICLUB_PrintTalkMessage(WifiClubWork *work, int messageId, int useAltBank, int stream);
void WIFICLUB_ShowStreamedMessage(WifiClubWork *work, int messageId, int useAltBank);
void WIFICLUB_ShowMessage(WifiClubWork *work, int messageId, int useAltBank);
void WIFICLUB_ShowNoticeWindow(WifiClubWork *work, int messageId);
void WIFICLUB_SetMenuListColors(void *menuList, int menuKind);
void WIFICLUB_CreateMenuList(WifiClubWork *work, WifiClubMenuListHeader *header, WifiClubMenuItem *items, int count, int menuKind, u32 width);
void WIFICLUB_CreateMainMenu(WifiClubWork *work);
void WIFICLUB_CreateAnswerMenu(WifiClubWork *work);
void WIFICLUB_DrawPlayerInfoWindow(WifiClubWork *work);
void WIFICLUB_DrawHeaderWindow(WifiClubWork *work);
void WIFICLUB_DeleteAllWindows(WifiClubWork *work);
void WIFICLUB_CreateTextBuffers(WifiClubWork *work);
void WIFICLUB_DeleteTextBuffers(WifiClubWork *work);
void WIFICLUB_OpenPartnerPanel(WifiClubWork *work, int panelPlane);
void WIFICLUB_OpenPartnerPanelWithBg(WifiClubWork *work, int panelPlane);
void WIFICLUB_CreateTrainerActor(WifiClubWork *work, int friendIndex, int heapId);
void WIFICLUB_DeleteTrainerActor(WifiClubWork *work);
void WIFICLUB_CreateTouchBar(WifiClubWork *work, int heapId);
void WIFICLUB_DeleteTouchBar(WifiClubWork *work);
void WIFICLUB_LoadPanelGraphics(WifiClubWork *work);
void WIFICLUB_DrawPartnerPanel(WifiClubWork *work, int panelPlane);
int WIFICLUB_GetVisitorMessageId(u32 kind, unsigned int variant, int *unused);
void WIFICLUB_SetupRuleMenu(WifiClubWork *work, int useSession);
void WIFICLUB_CreateKindMenu(WifiClubWork *work);
void WIFICLUB_CreateLevelMenu(WifiClubWork *work);
void WIFICLUB_CreateOptionMenu(WifiClubWork *work);
void WIFICLUB_DrawPartyListWindow(WifiClubWork *work, void *party);
void WIFICLUB_DeletePartyListWindow(WifiClubWork *work);
void WIFICLUB_CreatePartyIcons(WifiClubWork *work, void *party, int base, void *archive);
void WIFICLUB_LoadPartyIcons(WifiClubWork *work, void *partyA, void *partyB);
void WIFICLUB_DeletePartyIcons(WifiClubWork *work);
void WIFICLUB_ShowPartyIconHalf(WifiClubWork *work, int showFirstHalf);
void WIFICLUB_FreezePartyIcons(WifiClubWork *work);
void WIFICLUB_CreateRuleChoiceMenu(WifiClubWork *work);
void WIFICLUB_ShowRuleWindow(WifiClubWork *work, int mask, u32 ruleFlag, int mode);
void WIFICLUB_DeleteRuleWindow(WifiClubWork *work);
void WIFICLUB_ResetTimeIcon(WifiClubWork *work);
void WIFICLUB_DeleteMenuAndIcons(WifiClubWork *work);
void WIFICLUB_StartVoiceChat(WifiClubWork *work);
int WIFICLUB_StateStartInvite(WifiClubWork *work, int result);
int WIFICLUB_StateOpenInviteYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateInviteYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateRestartInvite(WifiClubWork *work, int result);
int WIFICLUB_StateOpenMainMenu(WifiClubWork *work, int result);
int WIFICLUB_StateMainMenu(WifiClubWork *work, int result);
int WIFICLUB_StateOpenNoticeYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateNoticeYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateOpenVoiceYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateVoiceYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateWaitKeyRetry(WifiClubWork *work, int result);
int WIFICLUB_ShowScenePrompt(WifiClubWork *work, int result);
int WIFICLUB_StatePickScene4(WifiClubWork *work, int result);
int WIFICLUB_StatePickScene5(WifiClubWork *work, int result);
int WIFICLUB_StatePickScene6(WifiClubWork *work, int result);
int WIFICLUB_StateOpenSceneYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateSceneYesNo(WifiClubWork *work, int result);
int WIFICLUB_StateKeyThenExit(WifiClubWork *work, int result);
int WIFICLUB_StateSyncAsGuest(WifiClubWork *work, int result);
int WIFICLUB_StateCountdownExit(WifiClubWork *work, int result);
int WIFICLUB_StateExitAccepted(WifiClubWork *work, int result);
int WIFICLUB_StateExitDeclined(WifiClubWork *work, int result);
int WIFICLUB_StateExitRuleFail(WifiClubWork *work, int result);
int WIFICLUB_StateStartScene(WifiClubWork *work, int result);
int WIFICLUB_StateOpenRuleMenu(WifiClubWork *work, int result);
int WIFICLUB_StateRuleMenu(WifiClubWork *work, int result);
int WIFICLUB_StateOpenKindMenu(WifiClubWork *work, int result);
int WIFICLUB_StateKindMenu(WifiClubWork *work, int result);
int WIFICLUB_StateOpenLevelMenu(WifiClubWork *work, int result);
int WIFICLUB_StateLevelMenu(WifiClubWork *work, int result);
int WIFICLUB_StateOpenOptionMenu(WifiClubWork *work, int result);
int WIFICLUB_StateOptionMenu(WifiClubWork *work, int result);
int WIFICLUB_CheckPartyAgainstRules(void *regulationData, void *gameData, u32 *mask);
void *WIFICLUB_LoadSavedRegulation(void *gameData);
void WIFICLUB_FreeRegulation(void *p);
int WIFICLUB_CheckSavedRegulation(void *regulationData, void *savedRegulation, int *mask);
u32 WIFICLUB_LoadPickedRegulation(WifiClubWork *work, int mode);
u32 WIFICLUB_LoadOwnRegulation(WifiClubWork *work);
void WIFICLUB_ApplyRuleId(WifiClubWork *work, u32 ruleId);
int WIFICLUB_StateCheckRules(WifiClubWork *work, int result);
int WIFICLUB_StateRuleViolationKey(WifiClubWork *work, int result);
int WIFICLUB_StateViolationListKey(WifiClubWork *work, int result);
int WIFICLUB_StateRuleTextKey(WifiClubWork *work, int result);
int WIFICLUB_StateShowRuleSet(WifiClubWork *work, int result);
int WIFICLUB_StateRuleSetKey(WifiClubWork *work, int result);
int WIFICLUB_StateShowRulePreview(WifiClubWork *work, int result);
int WIFICLUB_StateRulePreviewDone(WifiClubWork *work, int result);
int WIFICLUB_StateRulePreviewKey(WifiClubWork *work, int result);
int WIFICLUB_StateRulePreviewClose(WifiClubWork *work, int result);
int WIFICLUB_StateIdle(WifiClubWork *work, int result);
int WIFICLUB_StateOpenEntryPrompt(WifiClubWork *work, int state);
int WIFICLUB_StatePollEntryPrompt(WifiClubWork *work, int state);
int WIFICLUB_StateCancelOnKey(WifiClubWork *work, int state);
int WIFICLUB_StateCheckEntryRules(WifiClubWork *work, int state);
int WIFICLUB_StateCancelOnKeyAfterMessage(WifiClubWork *work, int state);
int WIFICLUB_StateRegisterEntryParty(WifiClubWork *work, int state);
int WIFICLUB_StateOpenPartyMenu(WifiClubWork *work, int state);
int WIFICLUB_StateUpdatePartyMenu(WifiClubWork *work, int state);
int WIFICLUB_StateSendRegisteredParty(WifiClubWork *work, int state);
int WIFICLUB_StateSyncAfterPartySend(WifiClubWork *work, int state);
int WIFICLUB_StateShowRuleMatchMessage(WifiClubWork *work, int state);
int WIFICLUB_StateWaitRuleMessageTimer(WifiClubWork *work, int state);
int WIFICLUB_ApplyChosenRule(WifiClubWork *work);
int WIFICLUB_StateShowPartyViolations(WifiClubWork *work, int state);
int WIFICLUB_StateShowBoxPartyViolations(WifiClubWork *work, int state);
int WIFICLUB_StateCloseViolationList(WifiClubWork *work, int state);
int WIFICLUB_StateBranchOnSeat(WifiClubWork *work, int state);
int WIFICLUB_StateOpenWaitPrompt(WifiClubWork *work, int state);
int WIFICLUB_StatePollWaitPrompt(WifiClubWork *work, int state);
int WIFICLUB_StateWaitSyncAndResume(WifiClubWork *work, int state);
int WIFICLUB_StateWaitSyncAndReturnToIdle(WifiClubWork *work, int state);
int WIFICLUB_StateStartLeaveSync(WifiClubWork *work, int state);
int WIFICLUB_StateShowLeaveMessageParent(WifiClubWork *work, int state);
int WIFICLUB_StateDisableAutoExitA(WifiClubWork *work, int state);
int WIFICLUB_StateShowLeaveMessageByRoleA(WifiClubWork *work, int state);
int WIFICLUB_StateDisableAutoExitB(WifiClubWork *work, int state);
int WIFICLUB_StateShowLeaveMessageByRoleB(WifiClubWork *work, int state);
int WIFICLUB_StateReturnToIdle(WifiClubWork *work, int state);
int WIFICLUB_StateShowLeaveMessageBySeat(WifiClubWork *work, int state);
int WIFICLUB_StateResetNetOptions(WifiClubWork *work, int state);
int WIFICLUB_StateShowRuleChoiceMessage(WifiClubWork *work, int state);
int WIFICLUB_StateOpenRuleChoicePrompt(WifiClubWork *work, int state);
int WIFICLUB_StatePollRuleChoicePrompt(WifiClubWork *work, int state);
int WIFICLUB_StateShowMenuReject(WifiClubWork *work, int state);
int WIFICLUB_StateSendSeatRequest(WifiClubWork *work, int state);
int WIFICLUB_StateSendModeToPeer(WifiClubWork *work, int state);
int WIFICLUB_StateShowDeclineMessage(WifiClubWork *work, int state);
int WIFICLUB_StateStartReplySync(WifiClubWork *work, int state);
int WIFICLUB_StateSendReplyCode(WifiClubWork *work, int state);
int WIFICLUB_StateShowDisconnectNotice(WifiClubWork *work, int state);
int WIFICLUB_StateBranchOnSeatAfterNotify(WifiClubWork *work, int state);
int WIFICLUB_StateOpenLeavePrompt(WifiClubWork *work, int state);
int WIFICLUB_StatePollLeavePrompt(WifiClubWork *work, int state);
int WIFICLUB_StateWaitSyncAndContinue(WifiClubWork *work, int state);
int WIFICLUB_StateHandlePeerPhase(WifiClubWork *work, int state);
int WIFICLUB_StateCloseMessageOnKey(WifiClubWork *work, int state);
int WIFICLUB_StateApplyRuleSelection(WifiClubWork *work, int state);
void WIFICLUB_LoadFriendRoster(WifiClubWork *work);
void WIFICLUB_GetFirstFriendEntry(WifiClubWork *work);
void WIFICLUB_CopyFriendEntry(int srcIndex, int destIndex, WifiClubWork *work);
void WIFICLUB_StartNetSession(WifiClubWork *work, int startSession);
int WIFICLUB_GetStatusKind(WifiClubWork *work, WifiClubPlayerStatus *status);
int WIFICLUB_GetStatusPhase(WifiClubWork *work, WifiClubPlayerStatus *status);
int WIFICLUB_IsBusyPhase(int phase);
int WIFICLUB_IsActivePhase(int phase);
BOOL WIFICLUB_IsKindActive(int phase);
BOOL WIFICLUB_ShouldEnterWaitMode(int kind, void *value);
int WIFICLUB_HasEnoughPartyMembers(WifiClubWork *work);
int WIFICLUB_HasRuleViolation(WifiClubWork *work);
void WIFICLUB_ChangeNetMode(WifiClubWork *work, int kind, int value);
void WIFICLUB_InitScreen(WifiClubWork *work);
void WIFICLUB_ExitScreen(WifiClubWork *work);
void WIFICLUB_VBlankTask(void);
void WIFICLUB_InitVram(void);
void WIFICLUB_InitBackgrounds(u16 heapId);
void WIFICLUB_AddPeerActor(WifiClubWork *work, void *actor);
void WIFICLUB_RemovePeerActor(WifiClubWork *work, void *actor);
void WIFICLUB_ClearPeerActors(WifiClubWork *work);
void *WIFICLUB_FindPeerActor(WifiClubWork *work, int key);
void WIFICLUB_LoadBgResources(WifiClubBgLoad *bgLoad, int archive, int heapId);
void WIFICLUB_FreeBgResources(WifiClubBgLoad *bgLoad);
void WIFICLUB_DrawTileBlock(WifiClubBgLoad *bgLoad, int layer, u8 x, u8 y, unsigned int tileIndex, int unused);
int WIFICLUB_GetPhaseIconTile(unsigned int phase, int side);
void WIFICLUB_DrawPhaseIcon(WifiClubBgLoad *bgLoad, int layer, u8 x, u8 y, int side, unsigned int phase, int tileBase);
int WIFICLUB_GetIconPalette(int layer);
int WIFICLUB_BeginIdle(WifiClubWork *work, int fadeIn);
void WIFICLUB_ExitHook(WifiClubWork *work);
void WIFICLUB_InitPlanesAndText(WifiClubWork *work, int archive);
void WIFICLUB_TaskHook(void *task);
void WIFICLUB_InitSprites(WifiClubWork *work, void *archive);
int WIFICLUB_StateEnterClub(WifiClubWork *work, int state);
int WIFICLUB_StateResetBgScroll(WifiClubWork *work, int state);
void WIFICLUB_PublishOwnStatus(WifiClubWork *work);
void WIFICLUB_BuildOwnStatus(WifiClubWork *work, int kind, int value);
int WIFICLUB_RefreshVisibleList(WifiClubWork *work);
int WIFICLUB_SyncActorsWithPeers(WifiClubWork *work);
void WIFICLUB_OnFatalError(WifiClubWork *work);
int WIFICLUB_StateWaitIntroMessage(WifiClubWork *work, int state);
int WIFICLUB_StateOpenExitPrompt(WifiClubWork *work, int state);
int WIFICLUB_StatePollExitPrompt(WifiClubWork *work, int state);
int WIFICLUB_StateRestartMatch(WifiClubWork *work, int state);
int WIFICLUB_StateWatchLogin(WifiClubWork *work, int state);
int WIFICLUB_StateWatchLoginAndSave(WifiClubWork *work, int state);
int WIFICLUB_StateWaitSave(WifiClubWork *work, int state);
int WIFICLUB_StateWatchConnection(WifiClubWork *work, int state);
int WIFICLUB_StateShowSaveNotice(WifiClubWork *work, int state);
int WIFICLUB_StateWaitSaveNotice(WifiClubWork *work, int state);
void WIFICLUB_CreateTitleWindows(WifiClubWork *work);
BOOL WIFICLUB_IsFriendRequestFromPeer(void *friendIndex, WifiClubFriendRequest *request);
int WIFICLUB_StateHandleNetError(WifiClubWork *work, int state);
void WIFICLUB_ResetClubScreen(WifiClubWork *work);
int WIFICLUB_StateReturnToClub(WifiClubWork *work, int state);
BOOL WIFICLUB_IsNetStateConnected(WifiClubWork *work);
BOOL WIFICLUB_HasNewClientAid(WifiClubWork *work);
BOOL WIFICLUB_IsNetStateDisconnecting(WifiClubWork *work);
int WIFICLUB_SyncPresenceLists(WifiClubWork *work);
void WIFICLUB_DropActorsOfMissingPeers(WifiClubWork *work);
void WIFICLUB_RequestSelectionRefresh(WifiClubWork *work, int selector);
void WIFICLUB_UpdatePeerActors(WifiClubWork *work, int selector);
void WIFICLUB_ReleaseSlotActors(WifiClubWork *work);
int WIFICLUB_StateLobbyMain(WifiClubWork *work, int procState);
int WIFICLUB_StateLobbyConnected(WifiClubWork *work,int procState);
int WIFICLUB_StateCheckPeerSelection(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitKeyReturnToLobby(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitPeerReply(WifiClubWork *work, int procState);
int WIFICLUB_StateStartMessageDismiss(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitMessage(WifiClubWork *work, int procState);
int WIFICLUB_StateSyncTimingStart(WifiClubWork *work, int procState);
void WIFICLUB_UpdateVchatIndicator(WifiClubWork *work);
int WIFICLUB_StateVchatInvite(WifiClubWork *work, int procState);
int WIFICLUB_StateVchatAnswerWait(WifiClubWork *work, int procState);
int WIFICLUB_StateVchatYesNo(WifiClubWork *work, int procState);
int WIFICLUB_StateSendVchatReady(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitVchatEnd(WifiClubWork *work, int procState);
int WIFICLUB_StateLeaveSyncWait(WifiClubWork *work, int procState);
int WIFICLUB_StateDisconnectSync(WifiClubWork *work, int procState);
int WIFICLUB_StateLeaveDelay(WifiClubWork *work, int procState);
int WIFICLUB_StateErrorMessageWait(WifiClubWork *work, int procState);
int WIFICLUB_StateDisconnectAckWait(WifiClubWork *work, int procState);
int WIFICLUB_StateLeaveTimeout(WifiClubWork *work, int procState);
int WIFICLUB_StateLeaveCancel(WifiClubWork *work, int procState);
int WIFICLUB_StateUnusedA(int unused, int procState);
int WIFICLUB_StateUnusedB(int unused, int procState);
int WIFICLUB_StateUnusedC(int unused, int procState);
int WIFICLUB_StateCountdownThenConfirm(WifiClubWork *work, int procState);
int WIFICLUB_StateStartPrompt(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitPrompt(WifiClubWork *work, int procState);
int WIFICLUB_StatePollPrompt(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenPartnerMenu(WifiClubWork *work, int procState);
int WIFICLUB_StateShowPartnerMenuMessage(WifiClubWork *work, int procState);
void WIFICLUB_ClosePartnerMenu(WifiClubWork *work);
int WIFICLUB_StatePartnerMenu(WifiClubWork *work, int procState);
int WIFICLUB_StateSendChoiceAfterDelay(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenMenuChoicePrompt(WifiClubWork *work, int procState);
int WIFICLUB_StatePollMenuChoicePrompt(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenRequestPrompt(WifiClubWork *work, int procState);
int WIFICLUB_StatePollRequestPrompt(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitKeyDisconnectToLobby(WifiClubWork *work, int procState);
int WIFICLUB_StateDisconnectToLobby(WifiClubWork *work, int procState);
int WIFICLUB_StateSelectionMenu(WifiClubWork *work, int procState);
int WIFICLUB_StateShowPartnerStatusMessage(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenAnswerMenu(WifiClubWork *work, int procState);
int WIFICLUB_TryStartPartnerRequest(WifiClubWork *work);
int WIFICLUB_StateWaitPartnerResponse(WifiClubWork *work, int procState);
int WIFICLUB_StatePollCancelRequestPrompt(WifiClubWork *work, int procState);
int WIFICLUB_StateAnswerMenu(WifiClubWork *work, int procState);
void WIFICLUB_DisableVoiceChat(void);
int WIFICLUB_StatePartnerMenuResult(WifiClubWork *work, int procState);
int WIFICLUB_StateRequestJoinPartner(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitJoinAnswer(WifiClubWork *work, int procState);
int WIFICLUB_ReturnSecondArgA(int unused, int value);
int WIFICLUB_ReturnSecondArgB(int unused, int value);
int WIFICLUB_StateLeaveLinkToLobby(WifiClubWork *work, int procState);
int WIFICLUB_StateUnusedD(WifiClubWork *work, int procState);
int WIFICLUB_StateUnusedE(WifiClubWork *work, int procState);
int WIFICLUB_StateOnPartnerConnected(WifiClubWork *work, int procState);
int WIFICLUB_HandleNetFailure(WifiClubWork *work);
int WIFICLUB_StateWaitNegotiation(WifiClubWork *work, int procState);
void WIFICLUB_RecvFriendTrainerCard(int friendIndex, int unused, void *receivedStatus, WifiClubWork *work, int handle);
void WIFICLUB_NoOpNetCommand(void);
void WIFICLUB_RecvSceneResult(int unusedA, int unusedB, int unusedC, WifiClubWork *work, int handle);
u32 WIFICLUB_GetSeatPartyBuffer(int seat, WifiClubWork *work);
void WIFICLUB_RecvResumeState(int unusedA, int unusedB, u8 *payload, WifiClubWork *work, int handle);
void WIFICLUB_RecvRuleId(int unusedA, int unusedB, int *ruleId, WifiClubWork *work, int handle);
void WIFICLUB_RecvPeerChoice(int slot, int unused, WifiClubPeerChoice *choice, WifiClubWork *work);
int WIFICLUB_StateSendTrainerCard(WifiClubWork *work, int procState);
int WIFICLUB_StateSendChoiceMessage(WifiClubWork *work, int procState);
int WIFICLUB_StateCheckPeerPhase(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitSyncEnableAutoExit(WifiClubWork *work, int procState);
BOOL WIFICLUB_IsTalkFinishedOrClosed(WifiClubWork *work);
int WIFICLUB_StateBranchOnPartnerPhase(WifiClubWork *work, int procState);
int WIFICLUB_StateBeginIdleAfterNet(WifiClubWork *work, int procState);
int WIFICLUB_StateGotoWaitKey(WifiClubWork *work, int procState);
int WIFICLUB_StateWaitKeyOrNetUp(WifiClubWork *work, int procState);
int WIFICLUB_StateClearTalkToLobby(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenQuitYesNo(WifiClubWork *work, int procState);
int WIFICLUB_StatePollQuitYesNo(WifiClubWork *work, int procState);
int WIFICLUB_StateExitNetwork(WifiClubWork *work, int procState);
int WIFICLUB_StateCountdownToLobby(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenRetryYesNo(WifiClubWork *work, int procState);
int WIFICLUB_StatePollRetryYesNo(WifiClubWork *work, int procState);
int WIFICLUB_StateOpenSeatYesNo(WifiClubWork *work, int procState);
int WIFICLUB_StatePollSeatYesNo(WifiClubWork *work, int procState);
int WIFICLUB_ResolveNetRunState(int unused, int defaultState);
void WIFICLUB_SetOwnStatusAndPublish(WifiClubWork *work, int kind, int phase);
void WIFICLUB_SetOwnStatusKindPhase(WifiClubWork *work, int kind, int phase);
u8 WIFICLUB_ToggleOwnSeat(WifiClubWork *work);
void WIFICLUB_ResetOwnSeatStatus(WifiClubWork *work);
void WIFICLUB_ClosePartnerPanel(WifiClubWork *work, int panelPlane);
void WIFICLUB_ClosePanelIfSlotSelected(WifiClubWork *work, int slotId, int procState);
void WIFICLUB_ClosePanelIfTouchActive(WifiClubWork *work, int procState);
BOOL WIFICLUB_IsSlotPanelOpen(WifiClubWork *work);
void WIFICLUB_OpenSlotPanel(WifiClubWork *work, int narc, int heapId);
void WIFICLUB_CloseSlotPanel(WifiClubWork *work);
u8 WIFICLUB_UpdateSlotPanel(WifiClubWork *work, int heapId);
void WIFICLUB_RedrawSlotPanelIfPending(WifiClubWork *work);
int WIFICLUB_IsSlotPanelDismissed(WifiClubWork *work);
u8 WIFICLUB_GetSelectedSlotPlusOne(WifiClubWork *work);
void WIFICLUB_ResetSlotSelection(WifiClubWork *work);
void WIFICLUB_OnSlotButtonEvent(u32 buttonIndex, int event, WifiClubWork *work);
void WIFICLUB_TickSlotBlink(WifiClubWork *work);
void WIFICLUB_CreateSlotPanelWindows(WifiClubWork *work, void *narc, int heapId);
void WIFICLUB_DeleteSlotPanelWindows(WifiClubWork *work);
void WIFICLUB_AddTileOffsetToTileMap(u16 *tileMap, u16 tileOffset);
void WIFICLUB_SetSlotState(WifiClubWork *work, int slotNumber, u8 state);
void WIFICLUB_ClearSlotState(WifiClubWork *work, int slotNumber);
u8 WIFICLUB_GetSlotState(WifiClubWork *work, int slotNumber);
void WIFICLUB_OpenPanelOrRedrawPage(WifiClubWork *work, int panelArg);
void WIFICLUB_RequestPanelRedraw(WifiClubWork *work);
void WIFICLUB_EmptyHook(WifiClubWork *work);
void WIFICLUB_RedrawSlotPanels(WifiClubWork *work);
void WIFICLUB_DrawSlotFrame(WifiClubWork *work, u32 tileX, u32 tileY, u32 panelStyle, u8 frame);
void WIFICLUB_PrintSlotName(WifiClubWork *work, void *window, int slotNumber, int frame, int slotIndex);
void WIFICLUB_DrawSlotStatusIcons(WifiClubWork *work, void *pairWins, int slotNumber, int isSelected, int tileX, int tileY);
void WIFICLUB_SetFriendNameWord(WifiClubWork *work, int friendIndex);
WifiClubPlayerStatus *WIFICLUB_GetFriendStatus(int friendIndex);
unsigned char WIFICLUB_GetFriendConnectionStatus(int friendIndex);
int WIFICLUB_AddNetCommandsAndCheckFriend(WifiClubWork *work, int friendIndex);
void WIFICLUB_EnableTouchBar(WifiClubWork *work, int showMessage);
void WIFICLUB_DisableTouchBar(WifiClubWork *work);
int WIFICLUB_UpdateBgmFade(WifiClubWork *work);
void WIFICLUB_StartBgmFade(WifiClubWork *work, int targetVolume);
void WIFICLUB_InitBgmVolume(WifiClubWork *work, int entryKind);
int WIFICLUB_ProcInit(void *procObj, int unused, WifiClubSession *session);
int WIFICLUB_ProcMain(int procTask, int *procState, int unused, WifiClubWork *work);
int WIFICLUB_ProcExit(void *procTask, int unused, WifiClubSession *session, WifiClubWork *work);
u8 WIFICLUB_GetStatusActionState(WifiClubPlayerStatus *status);
void WIFICLUB_SetStatusActionState(WifiClubPlayerStatus *status, u8 actionState);
u8 WIFICLUB_GetStatusActionArg(WifiClubPlayerStatus *status);
void WIFICLUB_SetStatusActionArg(WifiClubPlayerStatus *status, u8 actionArg);
u8 WIFICLUB_GetStatusSeatFlag(WifiClubPlayerStatus *status);
void WIFICLUB_SetStatusSeatFlag(WifiClubPlayerStatus *status, u8 seatFlag);
BOOL WIFICLUB_IsPeerAddrOfStatus(WifiClubPlayerStatus *status, WifiClubPlayerStatus *peerStatus);
void WIFICLUB_CountChangeAndCopyPeerAddr(WifiClubPlayerStatus *status, WifiClubPlayerStatus *peer);
int WIFICLUB_CopyZeroToDeviceAddr(WifiClubPlayerStatus *status);
void WIFICLUB_RunPeerAddrRoutine(WifiClubPlayerStatus *status);
int WIFICLUB_GetStatusModeFlag(WifiClubPlayerStatus *status);
void WIFICLUB_SetStatusModeFlag(WifiClubPlayerStatus *status, u8 modeFlag);
u8 WIFICLUB_GetStatusChangeCount(WifiClubPlayerStatus *status);
extern u32 gWifiClubMessageIdTable[];
extern const u8 gWifiClubYesNoWindowTemplate[];
extern WifiClubMenuListHeader gWifiClubMainMenuHeader;
extern WifiClubMenuItem gWifiClubMainMenuItems[];
extern WifiClubMenuListHeader gWifiClubAnswerMenuHeaderTemplate;
extern const WifiClubMenuItem gWifiClubAnswerMenuItems[];
extern const WifiClubSpritePos gWifiClubTrainerSpritePos;
extern const WifiClubTouchBarTable gWifiClubTouchBarTable;
extern const WifiClubStatusMessageTable gWifiClubVisitorMessageIds;
extern WifiClubMenuListHeader gWifiClubRuleMenuHeader;
extern WifiClubMenuItem gWifiClubMenuItemTable[];
extern WifiClubMenuItem gWifiClubRuleMenuItems[];
extern WifiClubMenuHeaderSlot gWifiClubMenuHeaderSlot;
extern WifiClubMenuItem gWifiClubKindMenuItems[];
extern WifiClubMenuItem gWifiClubLevelMenuItems[];
extern WifiClubMenuItem gWifiClubOptionMenuItems[];
extern WifiClubMenuItem gWifiClubRuleChoiceItems[];
extern const WifiClubSceneMessages gWifiClubSceneMessageIds;
extern const u32 gWifiClubRuleIdTable[];
extern const WifiClubRuleTable d_021C38EC;
extern const WifiClubRuleTable d_021C390C;
extern WifiClubNetInit d_021C3B9C;
extern u8 data_021C3AA0[];
extern const WifiClubDispConfig d_021C37F4;
extern const WifiClubBgTemplate d_021C396C, d_021C382C, d_021C384C, d_021C386C;
extern const WifiClubBgTemplate d_021C38AC, d_021C38CC, d_021C392C, d_021C394C;
extern u8 d_021C3740[];
extern u8 d_021C375C[];
extern u8 d_021C3AA0[];
extern WifiClubMessageTable d_021C3804, d_021C3818;
extern const int d_021C377C[];
extern const u8 d_021C3720[];
extern const WifiClubStateHandler gWifiClubStateHandlers[];



u32 WIFICLUB_GetMessageIdByIndex(int i)
{
    return gWifiClubMessageIdTable[i];
}


void WIFICLUB_OpenYesNoMenu(WifiClubWork *work)
{
    GF_FONT_SetDefaultTextColor();
    work->yesNoMenu = BMP_MENU_CreateYesNo(&gWifiClubYesNoWindowTemplate, work->windowFrameBase, 14, 0, 0x21);
}


u32 WIFICLUB_PollYesNoMenu(WifiClubWork *work)
{
    u32 result = BMP_MENU_ProcessYesNo(work->yesNoMenu);
    if (result != 0xFFFFFFFF)
        work->yesNoMenu = 0;
    return result;
}


void WIFICLUB_SetPartnerNameWord(WifiClubWork *work, int friendIndex)
{
    int sex;

    if (friendIndex != -1) {
        sex = func_02009864(work->friendList, friendIndex, 9);
        func_020099E4(work->friendList, friendIndex, work->rawText);
        WORDSET_SetSlotTag(work->wordSet, 0, work->rawText, sex, 1, 2);
    }
}


BmpWin *WIFICLUB_DeleteWindow(BmpWin *win)
{
    if (win != 0) {
        BMP_MENUWORK_DrawWindowBorder(win, 0);
        BMP_WIN_Delete(win);
    }

    return 0;
}


void WIFICLUB_DeleteTimeIcon(WifiClubWork *work)
{
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
}


void WIFICLUB_ClearTalkWindow(WifiClubWork *work)
{
    WIFICLUB_DeleteTimeIcon(work);
    if (PRINTSYS_QUE_IsFinished(work->msgPrintQueue) == 0)
        PRINTSYS_QUE_Clear(work->msgPrintQueue);
    if (work->printStream != 0) {
        PRINTSYS_PrintStreamDelete(work->printStream);
        work->printStream = 0;
    }
    work->talkWin = WIFICLUB_DeleteWindow(work->talkWin);
}


int WIFICLUB_UpdateTalkStream(WifiClubWork *work)
{
    int finished = 1;
    if (work->printStream != 0) {
        if (work->talkWin != 0) {
            APP_KEYCURSOR_Update(work->keyCursor, work->printStream, work->talkWin);
        }
        finished = PRINTSYS_CTRL_Update(work->streamWait, work->printStream);
        if (finished != 0 && work->printStream != 0) {
            PRINTSYS_PrintStreamDelete(work->printStream);
            work->printStream = 0;
        }
    }
    return finished;
}


void WIFICLUB_PrintTalkMessage(WifiClubWork *work, int messageId, int useAltBank, int stream)
{
    MSG_SPEED_GetWait();
    WIFICLUB_DeleteTimeIcon(work);
    work->talkWin = WIFICLUB_DeleteWindow(work->talkWin);
    if (PRINTSYS_QUE_IsFinished(work->msgPrintQueue) == 0)
        PRINTSYS_QUE_Clear(work->msgPrintQueue);
    if (work->printStream != 0) {
        PRINTSYS_PrintStreamDelete(work->printStream);
        work->printStream = 0;
    }
    work->talkWin = BMP_WIN_Create(2, 2, 0x13, 0x1B, 4, 0xF, 1);
    if (useAltBank)
        func_02045CAC(work->msgBankAlt, messageId, work->rawText);
    else
        func_02045CAC(work->msgBank, messageId, work->rawText);
    WORDSET_CopyTaggedText(work->wordSet, work->printText, work->rawText);
    BMP_Clear(BMP_WIN_GetBmp(work->talkWin), 0xFF);
    BMP_MENUWORK_DrawWindow(work->talkWin, 1, (u16)work->windowFrameBase, 0xE);
    if (stream == 0) {
        PRINTSYS_Print(BMP_WIN_GetBmp(work->talkWin), 0, 0, work->printText, work->textFont);
    } else {
        u32 speed = MSG_SPEED_GetWait();
        work->printStream = PRINTSYS_PrintStream(work->talkWin, 0, 0, work->printText, work->textFont, speed, work->tcbl, 2, 0x21, 0xF);
        PRINTSYS_CTRL_Init(work->streamWait, 2);
    }
    BMP_WIN_TransferChars(work->talkWin);
    BMP_WIN_MakeScreen(work->talkWin);
    func_02041B6C(2);
}


void WIFICLUB_ShowStreamedMessage(WifiClubWork *work, int messageId, int useAltBank)
{
    work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
    WIFICLUB_PrintTalkMessage(work, messageId, useAltBank, 1);
}


/*
 * note: Two bytes of alignment padding follow at 0x021BAB02.
 */
void WIFICLUB_ShowMessage(WifiClubWork *work, int messageId, int useAltBank)
{
    work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
    GF_FONT_SetDefaultTextColor();
    WIFICLUB_PrintTalkMessage(work, messageId, useAltBank, 0);
}


void WIFICLUB_ShowNoticeWindow(WifiClubWork *work, int messageId)
{
    WIFICLUB_DeleteTimeIcon(work);
    work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
    work->talkWin = WIFICLUB_DeleteWindow(work->talkWin);
    work->noticeWin = BMP_WIN_Create(2, 4, 4, 23, 16, 15, 1);
    func_02049B40(23, 5, 0, 480, 32, 33);
    BMP_Clear(BMP_WIN_GetBmp(work->noticeWin), 255);
    BMP_WIN_ClearScreen(work->noticeWin);
    BMP_WIN_MakeScreen(work->noticeWin);
    BMP_MENUWORK_DrawWindow(work->noticeWin, 1, (u16)work->windowFrameBase, 14);
    func_02045CAC(work->msgBankAlt, messageId, work->rawText);
    WORDSET_CopyTaggedText(work->wordSet, work->printText, work->rawText);
    GF_FONT_SetDefaultTextColor();
    PRINTSYS_Print(BMP_WIN_GetBmp(work->noticeWin), 4, 4, work->printText, work->textFont);
    BMP_WIN_TransferChars(work->noticeWin);
}


void WIFICLUB_SetMenuListColors(void *menuList, int menuKind)
{
    WifiClubWork *work = func_02020D0C(menuList);

    if (WIFICLUB_GetStatusSeatFlag(work->localStatus) == 0) {
        switch (menuKind) {
        case 4:
        case 5:
            BMP_MENULIST_SetColors(menuList, 2, 15, 2);
            break;
        default:
            BMP_MENULIST_SetColors(menuList, 1, 15, 2);
            break;
        }
    } else {
        BMP_MENULIST_SetColors(menuList, 1, 15, 2);
    }
}


void WIFICLUB_CreateMenuList(WifiClubWork *work, WifiClubMenuListHeader *header, WifiClubMenuItem *items, int count, int menuKind, u32 width)
{
    int i;
    int y;
    PRINTSYS_QUE_Clear(work->menuPrintQueue);
    GF_FONT_SetDefaultTextColor();
    work->menuWork = BMP_MENUWORK_Create(count, 0x21);
    for (i = 0; i < count; i++)
        BMP_MENUWORK_AddMsgItem(work->menuWork, work->msgBank, items[i].messageId, items[i].value, 0x21);
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    y = 5;
    if (menuKind == 5)
        y = 13;
    work->menuWin = BMP_WIN_Create(2, (u8)(31 - width), (u8)y, (u8)width, (u32)count * 2, 15, 1);
    BMP_WIN_MakeScreen(work->menuWin);
    BMP_MENUWORK_DrawWindow(work->menuWin, 2, (u16)work->menuFrameBase, 14);
    header->menuWork = work->menuWork;
    header->win = work->menuWin;
    header->printQueue = work->menuPrintQueue;
    header->pending = &work->menuPending;
    header->font = work->textFont;
    header->owner = work;
    work->menuList = BMP_MENULIST_Create(header, 0, work->menuCursor[menuKind], 0x21);
    if (PRINTSYS_QUE_IsFinished(work->menuPrintQueue) == 0) {
        do {
            PRINTSYS_QUE_Main(work->menuPrintQueue);
        } while (PRINTSYS_QUE_IsFinished(work->menuPrintQueue) == 0);
    }
    func_02020CF8(work->menuList, 0x21);
    func_02041B6C(2);
}


void WIFICLUB_CreateMainMenu(WifiClubWork *work)
{
    WIFICLUB_CreateMenuList(work, &gWifiClubMainMenuHeader, gWifiClubMainMenuItems, 5, 4, 0x11);
}


/*
 * prototype-evidence: C23B8 forwards the visibly supplied index to ov009
 *   56860, whose full body returns the address consumed here; BDD48's
 *   result is explicitly narrowed to u16 here, so its extern is wide.
 *   F878/20CF8 retain visibly supplied unused trailing heap arguments.
 * layout-evidence: the template copy is 13 words; count/rows occupy +10/+12.
 */
void WIFICLUB_CreateAnswerMenu(WifiClubWork *work)
{
    int itemCount;
    WifiClubMenuListHeader header;
    WifiClubPlayerStatus *status;
    u16 kind;
    u32 i;
    itemCount = 2;
    header = gWifiClubAnswerMenuHeaderTemplate;
    status = WIFICLUB_GetFriendStatus(WIFICLUBACTOR_GetPickResult(&work->actorSys) - 1);
    kind = (u16)WIFICLUB_GetStatusKind(work, status);
    WIFICLUB_GetStatusSeatFlag(status);
    WIFICLUB_GetStatusSeatFlag(work->localStatus);
    work->menuWork = BMP_MENUWORK_Create(2, 33);
    for (i = 0; i < 2; i++) {
        if (i == 0 && kind != 2 && kind != 5 && kind != 1) {
            header.rows--;
            header.count--;
            itemCount--;
        } else {
            BMP_MENUWORK_AddMsgItem(work->menuWork, work->msgBank, gWifiClubAnswerMenuItems[i].messageId, gWifiClubAnswerMenuItems[i].value, 33);
        }
    }
    work->menuWin = BMP_WIN_Create(2, 16, (u8)((3 - itemCount) * 2 + 11), 15, itemCount * 2, 15, 1);
    BMP_MENUWORK_DrawWindow(work->menuWin, 2, (u16)work->windowFrameBase, 14);
    header.menuWork = work->menuWork;
    header.win = work->menuWin;
    header.printQueue = work->menuPrintQueue;
    header.pending = &work->menuPending;
    header.font = work->textFont;
    work->menuList = BMP_MENULIST_Create(&header, 0, 0, 33);
    if (PRINTSYS_QUE_IsFinished(work->menuPrintQueue) == 0) {
        do {
            PRINTSYS_QUE_Main(work->menuPrintQueue);
        } while (PRINTSYS_QUE_IsFinished(work->menuPrintQueue) == 0);
    }
    func_02020CF8(work->menuList, 33);
    BMP_WIN_MakeScreen(work->menuWin);
    func_02041B6C(2);
}


void WIFICLUB_DrawPlayerInfoWindow(WifiClubWork *work)
{
    void *myStatus;
    StrBuf *name;
    u32 kind;
    int variant;
    int messageId;
    int unused;
    int sex;
    int icon;
    myStatus = func_02008730(work->saveData);
    if (work->playerInfoWin == 0)
        return;
    GF_FONT_SetDefaultTextColor();
    name = func_02008510(myStatus, 33);
    BMP_Clear(BMP_WIN_GetBmp(work->playerInfoWin), 255);
    if (func_02008550(myStatus) == 0)
        GF_FONT_SetTextColor(5, 6, 0);
    else
        GF_FONT_SetTextColor(3, 4, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(work->playerInfoWin), 32, 0, name, work->textFont);
    STRBUF_Delete(name);
    kind = WIFICLUB_GetStatusKind(work, work->localStatus);
    variant = WIFICLUB_GetStatusPhase(work, work->localStatus);
    messageId = WIFICLUB_GetVisitorMessageId(kind, variant, &unused);
    if (variant == 4 && kind == 4) {
        if (DWC_RAP_GetTargetFriendIndex() == -1) {
            func_02045CAC(work->msgBank, messageId, work->rawText);
        } else {
            sex = func_02009864(work->friendList, DWC_RAP_GetTargetFriendIndex(), 9);
            if (sex == 0)
                GF_FONT_SetTextColor(5, 6, 0);
            else if (sex == 1)
                GF_FONT_SetTextColor(3, 4, 0);
            func_020099E4(work->friendList, DWC_RAP_GetTargetFriendIndex(), work->rawText);
        }
    } else {
        func_02045CAC(work->msgBank, messageId, work->rawText);
    }
    PRINTSYS_Print(BMP_WIN_GetBmp(work->playerInfoWin), 102, 0, work->rawText, work->textFont);
    WIFICLUB_DrawPhaseIcon(&work->bgLoad, 1, 2, 1, kind, variant, 48);
    if (WIFICLUB_GetStatusSeatFlag(work->localStatus)) icon = 15;
    else icon = 11;
    WIFICLUB_DrawTileBlock(&work->bgLoad, 1, 26, 1, icon + 48, 0);
    BMP_WIN_ClearScreen(work->playerInfoWin);
    BMP_WIN_MakeScreen(work->playerInfoWin);
    BMP_WIN_TransferChars(work->playerInfoWin);
    BG_SYS_PushTile(3);
}


void WIFICLUB_DrawHeaderWindow(WifiClubWork *work)
{
    WIFICLUB_DeleteWindow(work->headerWin);
    work->headerWin = BMP_WIN_Create(3, 5, 1, 0x16, 2, 0xf, 1);
    BMP_WIN_MakeScreen(work->headerWin);
    func_02045CAC(work->msgBank, 0x12, work->shortText);
    PRINTSYS_Print(BMP_WIN_GetBmp(work->headerWin), 0, 0, work->shortText, work->textFont);
    BMP_WIN_TransferChars(work->headerWin);
}


void WIFICLUB_DeleteAllWindows(WifiClubWork *work)
{
    WIFICLUB_ClearTalkWindow(work);
    if (work->menuWin) {
        BMP_WIN_Delete(work->menuWin);
        BMP_MENULIST_Delete(work->menuList, 0, 0);
        BMP_MENUWORK_Delete(work->menuWork);
        work->menuWork = 0;
    }
    if (work->headerWin) { BMP_WIN_Delete(work->headerWin); work->headerWin = 0; }
    if (work->talkWin) { BMP_WIN_Delete(work->talkWin); work->talkWin = 0; }
    if (work->extraWin) { BMP_WIN_Delete(work->extraWin); work->extraWin = 0; }
    if (work->playerInfoWin) { BMP_WIN_Delete(work->playerInfoWin); work->playerInfoWin = 0; }
    if (work->partyWin) { BMP_WIN_Delete(work->partyWin); work->partyWin = 0; }
    if (work->noticeWin) {
        BMP_WIN_ClearScreen(work->noticeWin);
        func_02041B6C(2);
        WIFICLUB_DeleteWindow(work->noticeWin);
        work->noticeWin = 0;
    }
    if (work->subMenuList) { BMP_MENULIST_Delete(work->subMenuList, 0, 0); work->subMenuList = 0; }
    if (work->subMenuWork) { BMP_MENUWORK_Delete(work->subMenuWork); work->subMenuWork = 0; }
    if (work->yesNoMenu) { BMP_MENU_DeleteYesNo(work->yesNoMenu); work->yesNoMenu = 0; }
}


/*
 * Creates the text buffers (printText, extraText, rawText: 0x17C bytes each; shortText: 0xB4),
 * the two print queues, the stream controller and the key cursor.
 */
void WIFICLUB_CreateTextBuffers(WifiClubWork *work)
{
    work->printText = STRBUF_Create(0x17C, 0x21);
    work->extraText = STRBUF_Create(0x17C, 0x21);
    work->rawText = STRBUF_Create(0x17C, 0x21);
    work->shortText = STRBUF_Create(0xB4, 0x21);
    work->msgPrintQueue = unit_0201C440(0x21);
    work->menuPrintQueue = unit_0201C440(0x21);
    work->tcbl = TCBL_Create(0x21, 0x21, 2, 0);
    work->keyCursor = APP_KEYCURSOR_CreateDefault(0xF, 1, 0, 0x21);
}


void WIFICLUB_DeleteTextBuffers(WifiClubWork *work)
{
    WIFICLUB_DeleteTouchBar(work);
    WIFICLUB_DeleteTrainerActor(work);
    APP_KEYCURSOR_Delete(work->keyCursor);
    STRBUF_Delete(work->shortText);
    STRBUF_Delete(work->printText);
    STRBUF_Delete(work->extraText);
    if (work->printStream != 0) {
        PRINTSYS_PrintStreamDelete(work->printStream);
        work->printStream = 0;
    }
    STRBUF_Delete(work->rawText);
    TCBL_Destroy(work->tcbl);
    PRINTSYS_QUE_Clear(work->msgPrintQueue);
    PRINTSYS_QUE_Clear(work->menuPrintQueue);
    PRINTSYS_QUE_Delete(work->msgPrintQueue);
    PRINTSYS_QUE_Delete(work->menuPrintQueue);
    work->msgPrintQueue = 0;
}


void WIFICLUB_OpenPartnerPanel(WifiClubWork *work, int panelPlane)
{
    func_02009864(work->friendList, work->selectedSlotPlusOne - 1, 9);
    BMP_Clear(BMP_WIN_GetBmp(work->nameWin), 0);
    WIFICLUB_DrawPartnerPanel(work, panelPlane);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(8, 1);
}


void WIFICLUB_OpenPartnerPanelWithBg(WifiClubWork *work, int panelPlane)
{
    WifiClubPanelScreen *screen;

    func_02009864(work->friendList, work->selectedSlotPlusOne - 1, 9);
    screen = (WifiClubPanelScreen *)work->panelScreenData;
    BG_SYS_DecodeTileSource(6, screen->data, screen->dataSize, 0);
    BG_SYS_FreeSlot(7);
    BMP_Clear(BMP_WIN_GetBmp(work->statWin), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->nameWin), 0);
    WIFICLUB_DrawPartnerPanel(work, panelPlane);
    func_02041B6C(7);
    BMP_WIN_TransferChars(work->statWin);
    BMP_WIN_TransferChars(work->nameWin);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(8, 1);
}


void WIFICLUB_CreateTrainerActor(WifiClubWork *work, int friendIndex, int heapId)
{
    WifiClubSpritePos pos;
    int trainerId;
    void *archive;

    pos = gWifiClubTrainerSpritePos;
    if (work->trainerActor != 0)
        WIFICLUB_DeleteTrainerActor(work);
    trainerId = func_02009864(work->friendList, friendIndex, 8);
    trainerId = CURSOR_MOVE_GetTableGroup(trainerId);
    archive = POKEGRA_OpenTrainerHandle((u16)heapId);
    work->trainerChar = POKEGRA_RegisterTrainerCgr(archive, trainerId, 1, heapId);
    work->trainerPalette = POKEGRA_RegisterTrainerPalette(archive, trainerId, 1, 0, heapId);
    work->trainerCellAnim = POKEGRA_RegisterTrainerCellAnim(trainerId, 2, 1, heapId);
    ARC_TOOL_DeleteHandle(archive);
    work->trainerActor = CLACT_CreateActor(work->clactUnit, work->trainerChar, work->trainerPalette, work->trainerCellAnim, &pos, 1, heapId);
}


void WIFICLUB_DeleteTrainerActor(WifiClubWork *work)
{
    if (work->trainerActor != 0) {
        CLACT_DeleteActor(work->trainerActor);
        CLACT_ReleaseCharacter(work->trainerChar);
        CLACT_ReleasePalette(work->trainerPalette);
        CLACT_ReleaseCellAnim(work->trainerCellAnim);
        work->trainerActor = 0;
    }
}


void WIFICLUB_CreateTouchBar(WifiClubWork *work, int heapId)
{
    WifiClubTouchBarTable table;
    WifiClubTouchBarSetup setup;
    void *touchBar;

    table = gWifiClubTouchBarTable;
    if (work->touchBar == 0) {
        MI_CpuFill8(&setup, 0, 0x20);
        setup.table = &table;
        setup.buttonCount = 1;
        setup.clactUnit = work->clactUnit;
        setup.reserved1C = 0;
        setup.paletteSlot = 4;
        setup.originX = 0xC;
        setup.originY = 0xC;
        setup.priority = 2;
        touchBar = TOUCHBAR_Create(&setup, heapId);
        work->touchBar = touchBar;
        TOUCHBAR_SetButtonKeyMask(touchBar, 1, 0);
    }
}


void WIFICLUB_DeleteTouchBar(WifiClubWork *work)
{
    void *touchBar = work->touchBar;

    if (touchBar != 0) {
        TOUCHBAR_Delete(touchBar);
        work->touchBar = 0;
    }
}


void WIFICLUB_LoadPanelGraphics(WifiClubWork *work)
{
    void *archive = func_020490F4(0x21, 0x21);

    func_02049990(archive, 0x16, 4, 0, (unsigned short)work->fileIndex, 0, 0, 0x21);
    ARC_TOOL_DeleteHandle(archive);
}


void WIFICLUB_DrawPartnerPanel(WifiClubWork *work, int panelPlane)
{
    int index;
    WifiClubPlayerStatus *status;
    unsigned kind, variant;
    int unused;
    int messageId;
    GF_FONT_SetDefaultTextColor();
    index = work->selectedSlotPlusOne - 1;
    func_02009864(work->friendList, index, 9);
    GF_FONT_SetTextColor(15, 2, 0);
    WIFICLUB_SetFriendNameWord(work, index);
    func_02045CAC(work->msgBank, 33, work->rawText);
    WORDSET_CopyTaggedText(work->detailWordSet, work->shortText, work->rawText);
    PRINTSYS_Print(BMP_WIN_GetBmp(work->nameWin), 25, 0, work->shortText, work->textFont);
    status = WIFICLUB_GetFriendStatus(index);
    kind = WIFICLUB_GetStatusKind(work, status);
    variant = WIFICLUB_GetStatusPhase(work, status);
    messageId = WIFICLUB_GetVisitorMessageId(kind, variant, &unused);
    if (messageId >= 141 && messageId <= 144) messageId -= 81;
    func_02045CAC(work->msgBank, messageId, work->rawText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->nameWin), 96, 0, work->rawText, work->textFont, 0x3c40);
    func_02045CAC(work->msgBank, 35, work->shortText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 104, 0, work->shortText, work->textFont, 0x3c40);
    WORDSET_SetSlotNumber(work->detailWordSet, 0, func_02009864(work->friendList, index, 2), 4, 1, 1);
    func_02045CAC(work->msgBank, 36, work->rawText);
    WORDSET_CopyTaggedText(work->detailWordSet, work->shortText, work->rawText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 176, 24, work->shortText, work->textFont, 0x3c40);
    WORDSET_SetSlotNumber(work->detailWordSet, 0, func_02009864(work->friendList, index, 3), 4, 1, 1);
    func_02045CAC(work->msgBank, 37, work->rawText);
    WORDSET_CopyTaggedText(work->detailWordSet, work->shortText, work->rawText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 176, 40, work->shortText, work->textFont, 0x3c40);
    func_02045CAC(work->msgBank, 38, work->shortText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 104, 64, work->shortText, work->textFont, 0x3c40);
    WORDSET_SetSlotNumber(work->detailWordSet, 0, func_02009864(work->friendList, index, 4), 4, 1, 1);
    func_02045CAC(work->msgBank, 39, work->rawText);
    WORDSET_CopyTaggedText(work->detailWordSet, work->shortText, work->rawText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 188, 64, work->shortText, work->textFont, 0x3c40);
    func_02045CAC(work->msgBank, 42, work->shortText);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 8, 96, work->shortText, work->textFont, 0x3c40);
    messageId = func_02009864(work->friendList, index, 7);
    if (messageId) {
        WORDSET_SetSlotNumber(work->detailWordSet, 2, messageId, 2, 0, 1);
        WORDSET_SetSlotNumber(work->detailWordSet, 0, func_02009864(work->friendList, index, 5), 4, 1, 1);
        WORDSET_SetSlotNumber(work->detailWordSet, 1, func_02009864(work->friendList, index, 6), 2, 0, 1);
        func_02045CAC(work->msgBank, 44, work->rawText);
        WORDSET_CopyTaggedText(work->detailWordSet, work->shortText, work->rawText);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->statWin), 152, 96, work->shortText, work->textFont, 0x3c40);
    }
    BMP_WIN_MakeScreen(work->statWin);
    BMP_WIN_TransferChars(work->statWin);
    BMP_WIN_MakeScreen(work->nameWin);
    BMP_WIN_TransferChars(work->nameWin);
    func_02041B6C(7);
    WIFICLUB_DrawPhaseIcon(&work->bgLoad, 6, 2, 1, kind, variant, 32);
    WIFICLUB_DrawTileBlock(&work->bgLoad, 6, 28, 1, WIFICLUB_GetStatusModeFlag(status) ? 47 : 43, 0);
    WIFICLUB_CreateTrainerActor(work, index, panelPlane);
    WIFICLUB_CreateTouchBar(work, (u16)panelPlane);
    BG_SYS_SetSubPlaneVisible(16, 1);
}


int WIFICLUB_GetVisitorMessageId(u32 kind, unsigned int variant, int *unused)
{
    WifiClubStatusMessageTable table;

    GF_FONT_SetTextColor(1, 2, 0);
    GF_FONT_SetTextColor(1, 2, 0);
    table = gWifiClubVisitorMessageIds;
    if (variant > 15)
        variant = 15;
    return table.messageId[variant];
}



/* Finishes the menu text transfer once the print queue has drained. */
static inline void FlushMenuText(WifiClubWork *work)
{
    PrintQue *queue;
    queue = work->msgPrintQueue;
    if (work->menuPending.pending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(queue, BMP_WIN_GetBmp(work->menuPending.win)) == 0) {
            BMP_WIN_TransferChars(work->menuPending.win);
            work->menuPending.pending = 0;
        }
    }
}


void WIFICLUB_SetupRuleMenu(WifiClubWork *work, int useSession)
{
    if (useSession) {
        WifiClubSession *session = work->session;
        gWifiClubMenuItemTable[12].messageId = session->ruleKind + 0x83;
        gWifiClubMenuItemTable[13].messageId = session->ruleLevel + 0x87;
        gWifiClubMenuItemTable[14].messageId = 0x8A - session->ruleOption;
    } else {
        gWifiClubMenuItemTable[12].messageId = work->ruleKind + 0x83;
        gWifiClubMenuItemTable[13].messageId = work->ruleLevel + 0x87;
        gWifiClubMenuItemTable[14].messageId = 0x8A - work->session->regulationId;
    }
    WIFICLUB_CreateMenuList(work, &gWifiClubRuleMenuHeader, gWifiClubRuleMenuItems, 6, 0, 0x1E);
}


/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 5 / 1 / 0x11.
 */
void WIFICLUB_CreateKindMenu(WifiClubWork *work)
{
    gWifiClubMenuHeaderSlot.header.count = 5;
    gWifiClubMenuHeaderSlot.header.rows = 5;
    WIFICLUB_CreateMenuList(work, &gWifiClubMenuHeaderSlot.header, gWifiClubKindMenuItems, 5, 1, 0x11);
}


/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 3 / 2 / 0x11.
 */
void WIFICLUB_CreateLevelMenu(WifiClubWork *work)
{
    gWifiClubMenuHeaderSlot.header.count = 3;
    gWifiClubMenuHeaderSlot.header.rows = 3;
    WIFICLUB_CreateMenuList(work, &gWifiClubMenuHeaderSlot.header, gWifiClubLevelMenuItems, 3, 2, 0x11);
}


/*
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 3 / 3 / 0x14.
 */
void WIFICLUB_CreateOptionMenu(WifiClubWork *work)
{
    gWifiClubMenuHeaderSlot.header.count = 3;
    gWifiClubMenuHeaderSlot.header.rows = 3;
    WIFICLUB_CreateMenuList(work, &gWifiClubMenuHeaderSlot.header, gWifiClubOptionMenuItems, 3, 3, 0x14);
}


/*
 * Draws the party list window: one name per slot, with a gender mark for monsters that have one.
 * The window pointer is bound to a local before the gender-zero call; that keeps the image's call sites.
 */
void WIFICLUB_DrawPartyListWindow(WifiClubWork *work, void *party)
{
    StrBuf *nameText, *templateText;
    void *mon;
    int count, i, x;
    u32 species, gender, nickname, form;
    BmpWin *win;
    if (work->partyWin == 0)
        work->partyWin = BMP_WIN_Create(2, 1, 5, 30, 6, 15, 1);
    BMP_MENUWORK_DrawWindow(work->partyWin, 2, (u16)work->windowFrameBase, 14);
    nameText = STRBUF_Create(0x40, 0x21);
    templateText = STRBUF_Create(0x40, 0x21);
    BMP_Clear(BMP_WIN_GetBmp(work->partyWin), 255);
    BMP_WIN_ClearScreen(work->partyWin);
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, 0x4c, 0) == 0) {
            species = POKE_TOOL_GetPartyValue(mon, 0, 0);
            form = POKE_TOOL_GetPartyValue(mon, 0xad, 0);
            nickname = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
            gender = POKE_TOOL_GetPartyValue(mon, 0x6e, 0);
            func_02045CAC(work->msgBank, 0x74, templateText);
            WORDSET_SetSlotNumber(work->wordSet, 0, nickname, 3, 0, 1);
            WORDSET_CopyTaggedText(work->wordSet, nameText, templateText);
            x = i * 40;
            PRINTSYS_Print(BMP_WIN_GetBmp(work->partyWin), x + 1, 32, nameText, work->nameFont);
            if (gender != 2 && ((species != 0x1d && species != 0x20) || form != 0)) {
                if (gender == 0) {
                    func_02045CAC(work->msgBank, 0x75, templateText);
                    win = work->partyWin;
                } else {
                    func_02045CAC(work->msgBank, 0x76, templateText);
                    win = work->partyWin;
                }
                PRINTSYS_Print(BMP_WIN_GetBmp(win), x + 30, 16, templateText, work->textFont);
            }
        }
    }
    STRBUF_Delete(nameText);
    STRBUF_Delete(templateText);
    BMP_WIN_MakeScreen(work->partyWin);
    BMP_WIN_TransferChars(work->partyWin);
    func_02041B6C(2);
}


/*
 * Three-step release of the pointer at +0x1A0; the field is re-read for each
 * step, which is why the listing reloads it between the calls.
 */
void WIFICLUB_DeletePartyListWindow(WifiClubWork *work)
{
    if (work->partyWin != 0) {
        BMP_WIN_ClearScreen(work->partyWin);
        BMP_MENUWORK_DrawWindowBorder(work->partyWin, 1);
        BMP_WIN_Delete(work->partyWin);
        work->partyWin = 0;
    }
}


void WIFICLUB_CreatePartyIcons(WifiClubWork *work, void *party, int base, void *archive)
{
    int i, count;
    void *mon;
    WifiClubIconPos pos;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(party, i));
        pos.x = i * 40 + 22;
        pos.y = 54;
        pos.z = 0;
        pos.animSeq = 0;
        pos.priority = 0;
        work->partyIconChar[base + i] = CLACT_RegisterCharacter(archive, POKE_TOOL_GetGraphicIndex(mon), 0, 0, 0x21);
        work->partyIconActor[base + i] = CLACT_CreateActor(work->clactUnit, work->partyIconChar[base + i], work->partyIconPalette, work->partyIconCellAnim, &pos, 0, 0x21);
        CLACT_SetActorPaletteOffset(work->partyIconActor[base + i], POKE_TOOL_GetIconPalette(mon), 1);
    }
}


void WIFICLUB_LoadPartyIcons(WifiClubWork *work, void *partyA, void *partyB)
{
    void *archive;
    int cellAnimFile;
    archive = func_020490F4(7, 0x21);
    work->partyIconPalette = CLACT_RegisterPaletteCompressed(archive, POKE_TOOL_GetIconPaletteArcId(), 0, 0x160, 0x21);
    cellAnimFile = POKE_TOOL_GetIconCellArcIdSub();
    work->partyIconCellAnim = CLACT_RegisterCellAnim(archive, cellAnimFile, POKE_TOOL_GetIconCellEntryId(), 0x21);
    WIFICLUB_CreatePartyIcons(work, partyA, 0, archive);
    WIFICLUB_CreatePartyIcons(work, partyB, 6, archive);
    WIFICLUB_FreezePartyIcons(work);
    ARC_TOOL_DeleteHandle(archive);
}


void WIFICLUB_DeletePartyIcons(WifiClubWork *work)
{
    int i;
    if (work->partyIconActor[0] != 0) {
        for (i = 0; i < 12; i++) {
            if (work->partyIconActor[i] != 0) {
                CLACT_DeleteActor(work->partyIconActor[i]);
                CLACT_ReleaseCharacter(work->partyIconChar[i]);
            }
            work->partyIconActor[i] = 0;
        }
        CLACT_ReleasePalette(work->partyIconPalette);
        CLACT_ReleaseCellAnim(work->partyIconCellAnim);
    }
}


/*
 * Shows or hides the party icons: the first six follow the flag, the last six the opposite.
 * Each half is written out in full, one call pair per arm, as the image has it.
 */
void WIFICLUB_ShowPartyIconHalf(WifiClubWork *work, int showFirstHalf)
{
    int i;
    for (i = 0; i < 6; i++) {
        if (work->partyIconActor[i] != 0) {
            if (showFirstHalf != 0) {
                CLACT_SetActorAutoAnim(work->partyIconActor[i], 1);
                CLACT_SetActorDrawEnable(work->partyIconActor[i], 1);
            } else {
                CLACT_SetActorAutoAnim(work->partyIconActor[i], 0);
                CLACT_SetActorDrawEnable(work->partyIconActor[i], 0);
            }
        }
    }
    for (i = 6; i < 12; i++) {
        if (work->partyIconActor[i] != 0) {
            if (showFirstHalf != 0) {
                CLACT_SetActorAutoAnim(work->partyIconActor[i], 0);
                CLACT_SetActorDrawEnable(work->partyIconActor[i], 0);
            } else {
                CLACT_SetActorAutoAnim(work->partyIconActor[i], 1);
                CLACT_SetActorDrawEnable(work->partyIconActor[i], 1);
            }
        }
    }
}


void WIFICLUB_FreezePartyIcons(WifiClubWork *work)
{
    int i;
    for (i = 0; i < 12; i++) {
        if (work->partyIconActor[i] != 0) {
            unit_0204B92C(work->partyIconActor[i], 0);
            unit_0204B3DC(work->partyIconActor[i], 0);
        }
    }
}


void WIFICLUB_CreateRuleChoiceMenu(WifiClubWork *work)
{
    gWifiClubMenuHeaderSlot.header.count = 2;
    gWifiClubMenuHeaderSlot.header.rows = 2;
    WIFICLUB_CreateMenuList(work, &gWifiClubMenuHeaderSlot.header, gWifiClubRuleChoiceItems, 2, 5, 18);
    func_02020D10(work->menuList, 1);
}


void WIFICLUB_ShowRuleWindow(WifiClubWork *work, int mask, u32 ruleFlag, int mode)
{
    int base;
    int i;
    u32 color;
    StrBuf *text;
    base = 4;
    ruleFlag = (ruleFlag == 1) ? 1 : 0;
    work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
    if (mode == 1) work->noticeWin = BMP_WIN_Create(2, 2, 5, 26, 12, 15, 1); else work->noticeWin = BMP_WIN_Create(2, 2, 5, 26, 16, 15, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->noticeWin), 255);
    BMP_WIN_ClearScreen(work->noticeWin);
    BMP_WIN_MakeScreen(work->noticeWin);
    BMP_MENUWORK_DrawWindow(work->noticeWin, 1, (u16)work->windowFrameBase, 14);
    GF_FONT_SetDefaultTextColor();
    work->regulationText = POKE_REGULATION_CreateText(work->regulationData, work->wordSet, 33, ruleFlag);
    if (mode == 0) {
        text = REGULATION_CreateCupName(work->regulationData, 33);
        PRINTSYS_Print(BMP_WIN_GetBmp(work->noticeWin), 0, 0, text, work->textFont);
        STRBUF_Delete(text);
    } else if (mode != 1) {
        func_02045CAC(work->msgBank, (mode == 2) ? 0x66 : 0x67, work->rawText);
        PRINTSYS_Print(BMP_WIN_GetBmp(work->noticeWin), 0, 0, work->rawText, work->textFont);
    }
    if (mode == 1) base = 0;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) color = 0x41; else color = 0x11;
        color <<= 6;
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->noticeWin), 0, (s16)((base + i * 2) * 8), work->regulationText[i + 1], work->textFont, color);
        PRINTSYS_PrintColor(BMP_WIN_GetBmp(work->noticeWin), 0x70, (s16)((base + i * 2) * 8), work->regulationText[i + 7], work->textFont, color);
    }
    BMP_WIN_TransferChars(work->noticeWin);
}


void WIFICLUB_DeleteRuleWindow(WifiClubWork *work)
{
    POKE_REGULATION_DeleteText(work->regulationText);
    work->regulationText = 0;
    work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
}


/*
 * Replaces the time icon of the talk window with a fresh one.
 */
void WIFICLUB_ResetTimeIcon(WifiClubWork *work)
{
    if (work->timeIcon != 0) {
        TIME_ICON_Delete(work->timeIcon);
        work->timeIcon = 0;
    }
    work->timeIcon = TIME_ICON_CreateNode(work->tcbl, work->talkWin, 0xF, 0x10, 0x21);
}


void WIFICLUB_DeleteMenuAndIcons(WifiClubWork *work)
{
    if (work->menuWin != 0) {
        WIFICLUB_DeletePartyIcons(work);
        WIFICLUB_DeletePartyListWindow(work);
        work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
        BMP_MENULIST_Delete(work->menuList, 0, 0);
        BMP_MENUWORK_Delete(work->menuWork);
        work->menuWork = 0;
    }
}


void WIFICLUB_StartVoiceChat(WifiClubWork *work)
{
    WifiClubSession *session = work->session;
    if (session->voiceChat[0] != 0 && session->voiceChat[1] != 0) {
        DWC_RAP_SetVchatEnabled(1);
        DWC_RAP_StartVchatDefaultHeap(DWC_RAP_EnableLocalVchat());
        WIFICLUB_StartBgmFade(work, 0x2A);
        WIFICLUB_SetStatusModeFlag(work->localStatus, 1);
    } else {
        WIFICLUB_SetStatusModeFlag(work->localStatus, 0);
    }
}


/*
 * Invite start: the parent seat shows the invite message and waits for the yes/no menu;
 * the child seat shows the wait message and starts the time icon.
 */
int WIFICLUB_StateStartInvite(WifiClubWork *work, int result)
{
    int zero;
    GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
    zero = 0;
    if (GFL_NET_IsParentAid() == 0) {
        work->connectionMode = 3;
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 0x5F, zero);
        work->state = WIFICLUB_STATE_OPEN_INVITE_YES_NO;
    } else {
        work->connectionMode = 4;
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 0x7E, zero);
        WIFICLUB_ResetTimeIcon(work);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0xA);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    }
    return result;
}


/*
 * Early-returns the selector when the guard is false, else runs the setup and stamps 0x43.
 */
int WIFICLUB_StateOpenInviteYesNo(WifiClubWork *work, int result)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return result;
    }
    WIFICLUB_OpenYesNoMenu(work);
    work->state = WIFICLUB_STATE_INVITE_YES_NO;
    return result;
}


int WIFICLUB_StateInviteYesNo(WifiClubWork *work, int result)
{
    int answer;
    GF_FONT_SetDefaultTextColor();
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1)
        return result;
    if (answer == 0)
        work->exitCode = 0x44;
    else
        work->exitCode = 0x4A;
    WIFICLUB_ClearTalkWindow(work);
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return result;
}


int WIFICLUB_StateRestartInvite(WifiClubWork *work, int result)
{
    GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)0);
    if (GFL_NET_IsParentAid() != 0) {
        work->connectionMode = 3;
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 0x60, 0);
        work->state = WIFICLUB_STATE_OPEN_MAIN_MENU;
    } else {
        work->connectionMode = 4;
        WIFICLUB_ShowStreamedMessage(work, 0x4C, 0);
        WIFICLUB_ResetTimeIcon(work);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0xA);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    }
    return result;
}


/*
 * Early-returns the selector when the guard is false, else runs the second setup and stamps 0x46.
 */
int WIFICLUB_StateOpenMainMenu(WifiClubWork *work, int result)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return result;
    }
    WIFICLUB_CreateMainMenu(work);
    work->state = WIFICLUB_STATE_MAIN_MENU;
    return result;
}


/*
 * Main menu state. Choices 4 and 5 are ignored while this console is not the seat owner.
 */
int WIFICLUB_StateMainMenu(WifiClubWork *work, int result)
{
    int choice;
    FlushMenuText(work);
    choice = BMP_MENULIST_Main(work->menuList);
    switch (choice) {
    case 4: case 5:
        if (work->session->ownSeat == 0) return result;
        break;
    }
    if (choice != -1) WIFICLUB_ClearTalkWindow(work);
    switch (choice) {
    case -1: return result;
    case -2:
        work->exitCode = 0x9b;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
        break;
    case 4:
        if (work->session->voiceChat[1] == 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x8c, 0);
            work->state = WIFICLUB_STATE_WAIT_KEY_RETRY;
        } else {
            work->exitCode = 0x4b;
            work->state = WIFICLUB_STATE_START_REPLY_SYNC;
        }
        break;
    case 5:
        if (work->session->voiceChat[1] == 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x8c, 0);
            work->state = WIFICLUB_STATE_WAIT_KEY_RETRY;
        } else if (APP_ENV_HasParentalControlBits() == 0 && APP_ENV_IsRunOnTwl() != 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x95, 0);
            work->state = WIFICLUB_STATE_OPEN_NOTICE_YES_NO;
        } else {
            work->exitCode = 0x4c;
            work->state = WIFICLUB_STATE_START_REPLY_SYNC;
        }
        break;
    case 6:
        if (WIFICLUB_HasEnoughPartyMembers(work) == 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x79, 0);
            work->state = WIFICLUB_STATE_WAIT_KEY_RETRY;
        } else if (work->session->voiceChat[0] != work->session->voiceChat[1]) {
            work->noticeKind = 6;
            work->state = WIFICLUB_STATE_SHOW_RULE_CHOICE_MESSAGE;
        } else {
            work->exitCode = 0x4d;
            work->state = WIFICLUB_STATE_START_REPLY_SYNC;
        }
        break;
    case 7: work->state = WIFICLUB_STATE_OPEN_RULE_MENU; break;
    }
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[4]);
    BMP_MENUWORK_Delete(work->menuWork);
    return result;
}


int WIFICLUB_StateOpenNoticeYesNo(WifiClubWork *work, int result)
{
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_NOTICE_YES_NO;
    }
    return result;
}


/*
 * Notice yes/no answer: both answers send an exit code, 0x4C for yes and 0x9B for no.
 */
int WIFICLUB_StateNoticeYesNo(WifiClubWork *work, int result)
{
    int answer;
    answer = WIFICLUB_PollYesNoMenu(work);
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (answer == -1) {
        return result;
    }
    if (answer == 0) {
        work->exitCode = 0x4c;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    } else {
        work->exitCode = 0x9b;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return result;
}


/*
 * Re-arms, then runs the setup and stamps 0xA7 when the guard answers true.
 */
int WIFICLUB_StateOpenVoiceYesNo(WifiClubWork *work, int result)
{
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_VOICE_YES_NO;
    }
    return result;
}


int WIFICLUB_StateVoiceYesNo(WifiClubWork *work, int result)
{
    int answer;
    answer = WIFICLUB_PollYesNoMenu(work);
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (answer == -1) {
        return result;
    }
    if (answer == 0) {
        work->state = WIFICLUB_STATE_EXIT_ACCEPTED;
        WIFICLUB_ClearTalkWindow(work);
    } else {
        work->exitCode = 0x90;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return result;
}


/*
 * note: Two bytes of alignment padding follow at 0x021BC542.
 * prototype-evidence: r1 is forwarded unchanged from entry into BA928.
 */
int WIFICLUB_StateWaitKeyRetry(WifiClubWork *work, int result)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) return result;
    if (KEY_GetTrg() != 0) work->state = WIFICLUB_STATE_RESTART_INVITE;
    return result;
}


/*
 * Scene pick follow-up shared by the three stubs below: the parent shows the scene message
 * (message id table indexed by the picked scene) and the child waits for the sync.
 */
int WIFICLUB_ShowScenePrompt(WifiClubWork *work, int result)
{
    WifiClubSceneMessages messages = gWifiClubSceneMessageIds;
    if (GFL_NET_IsParentAid() == 0) {
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, messages.messageId[work->menuAction - 0x4b], 0);
        work->state = WIFICLUB_STATE_OPEN_SCENE_YES_NO;
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x4c, 0);
        WIFICLUB_ResetTimeIcon(work);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    }
    return result;
}


int WIFICLUB_StatePickScene4(WifiClubWork *work, int result)
{
    work->menuAction = WIFICLUB_STATE_PICK_SCENE4;
    return WIFICLUB_ShowScenePrompt(work, result);
}


int WIFICLUB_StatePickScene5(WifiClubWork *work, int result)
{
    work->menuAction = WIFICLUB_STATE_PICK_SCENE5;
    return WIFICLUB_ShowScenePrompt(work, result);
}


int WIFICLUB_StatePickScene6(WifiClubWork *work, int result)
{
    work->menuAction = WIFICLUB_STATE_PICK_SCENE6;
    return WIFICLUB_ShowScenePrompt(work, result);
}


int WIFICLUB_StateOpenSceneYesNo(WifiClubWork *work, int result)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return result;
    }
    WIFICLUB_OpenYesNoMenu(work);
    work->state = WIFICLUB_STATE_SCENE_YES_NO;
    return result;
}


/*
 * Scene yes/no answer. Each branch writes the state itself.
 */
int WIFICLUB_StateSceneYesNo(WifiClubWork *work, int result)
{
    int answer;
    GF_FONT_SetDefaultTextColor();
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1) {
        return result;
    }
    if (answer == 0) {
        if (WIFICLUB_HasEnoughPartyMembers(work) == 0 && work->menuAction == 0x4d) {
            WIFICLUB_ShowStreamedMessage(work, 0x79, 0);
            work->state = WIFICLUB_STATE_KEY_THEN_EXIT;
        } else if (APP_ENV_HasParentalControlBits() == 0 && APP_ENV_IsRunOnTwl() != 0
                   && work->menuAction == 0x4c) {
            WIFICLUB_ShowStreamedMessage(work, 0x95, 0);
            work->state = WIFICLUB_STATE_OPEN_VOICE_YES_NO;
        } else {
            work->state = WIFICLUB_STATE_EXIT_ACCEPTED;
            WIFICLUB_ClearTalkWindow(work);
        }
    } else {
        work->exitCode = 0x90;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return result;
}


int WIFICLUB_StateKeyThenExit(WifiClubWork *work, int result)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0)
        return result;
    if (KEY_GetTrg() == 0)
        return result;
    if (work->connectionMode - 3 <= 1u)
        work->exitCode = 0x90;
    else
        work->exitCode = 0x97;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return result;
}


int WIFICLUB_StateSyncAsGuest(WifiClubWork *work, int result)
{
    if (GFL_NET_IsParentAid() != 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x73, 0);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x72, 0);
        work->counter = 0x78;
        work->state = WIFICLUB_STATE_COUNTDOWN_EXIT;
    }
    return result;
}


/*
 * Ages the counter at +0x1E0 into the guard call, then stamps the byte at
 * +0x1353 and selector 0x8A when it has gone negative; returns the selector.
 * The guard call takes the aged value, not the selector.
 */
int WIFICLUB_StateCountdownExit(WifiClubWork *work, int result)
{
    --work->counter;
    WIFICLUB_UpdateTalkStream(work);
    if (work->counter < 0) {
        work->exitCode = 0x79;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return result;
}


int WIFICLUB_StateExitAccepted(WifiClubWork *work, int result)
{
    work->exitCode = 0x51;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return result;
}


int WIFICLUB_StateExitDeclined(WifiClubWork *work, int result)
{
    work->exitCode = 0x4a;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return result;
}


int WIFICLUB_StateExitRuleFail(WifiClubWork *work, int result)
{
    work->exitCode = 0x84;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return result;
}


int WIFICLUB_StateStartScene(WifiClubWork *work, int result)
{
    int sceneKind;
    int action;
    WIFICLUB_CopyZeroToDeviceAddr(work->localStatus);
    work->sceneReady = 0;
    action = work->menuAction;
    switch (action) {
    case 0x4b:
        sceneKind = 4;
        break;
    case 0x4c:
        sceneKind = 5;
        break;
    case 0x4d:
        sceneKind = 6;
        break;
    }
    switch (action) {
    case 0x4b:
        WIFICLUB_StartVoiceChat(work);
        WIFICLUB_ShowMessage(work, 0x7b, 0);
        WIFICLUB_SetOwnStatusAndPublish(work, 4, 4);
        WIFICLUB_StartBgmFade(work, 0);
        work->sceneResult = 0;
        work->state = WIFICLUB_STATE_SYNC_TIMING_START;
        break;
    case 0x4c:
        WIFICLUB_ClearTalkWindow(work);
        work->sceneKind = sceneKind;
        result = 2;
        break;
    case 0x4d:
        WIFICLUB_StartVoiceChat(work);
        WIFICLUB_ClearTalkWindow(work);
        work->sceneKind = sceneKind;
        result = 2;
        break;
    }
    WIFICLUB_SetOwnStatusAndPublish(work, 4, sceneKind);
    return result;
}


/*
 * Runs the setup for selector 0x54 with the true flag and stamps it 0x1CC bytes in.
 */
int WIFICLUB_StateOpenRuleMenu(WifiClubWork *work, int result)
{
    WIFICLUB_SetupRuleMenu(work, 1);
    work->state = WIFICLUB_STATE_RULE_MENU;
    return result;
}


int WIFICLUB_StateRuleMenu(WifiClubWork *work, int result)
{
    int choice;
    FlushMenuText(work);
    choice = BMP_MENULIST_Main(work->menuList);
    if (choice == -1) return result;
    WIFICLUB_ClearTalkWindow(work);
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[0]);
    BMP_MENUWORK_Delete(work->menuWork);
    if (choice == -2) {
        if (work->connectionMode == 3 || work->connectionMode == 4) {
            WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
            WIFICLUB_ShowStreamedMessage(work, 0x60, 0);
            work->state = WIFICLUB_STATE_OPEN_MAIN_MENU;
        } else {
            work->state = WIFICLUB_STATE_OPEN_PARTNER_MENU;
        }
    } else {
        if (work->connectionMode == 3 || work->connectionMode == 4) {
            work->state = choice;
        } else if (choice == 0x5b) {
            work->state = WIFICLUB_STATE_APPLY_RULE_SELECTION;
        } else {
            work->state = choice;
        }
    }
    return result;
}


int WIFICLUB_StateOpenKindMenu(WifiClubWork *work, int result)
{
    WIFICLUB_CreateKindMenu(work);
    work->state = WIFICLUB_STATE_KIND_MENU;
    return result;
}


/*
 * Twins: WIFICLUB_StateLevelMenu (+0x22 byte, +0x134e halfword) and WIFICLUB_StateOptionMenu
 * (stores 1 - r at +0x20).
 */
int WIFICLUB_StateKindMenu(WifiClubWork *work, int result)
{
    int choice;
    FlushMenuText(work);
    choice = BMP_MENULIST_Main(work->menuList);
    if (choice != -2) {
        if (choice == -1) {
            return result;
        }
        work->ruleKind = choice;
        work->session->ruleKind = choice;
    }
    work->state = WIFICLUB_STATE_OPEN_RULE_MENU;
    WIFICLUB_ClearTalkWindow(work);
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[1]);
    BMP_MENUWORK_Delete(work->menuWork);
    return result;
}


int WIFICLUB_StateOpenLevelMenu(WifiClubWork *work, int result)
{
    WIFICLUB_CreateLevelMenu(work);
    work->state = WIFICLUB_STATE_LEVEL_MENU;
    return result;
}


/*
 * Twin of WIFICLUB_StateKindMenu (+0x22 byte, +0x134e halfword, +0x238 out slot).
 */
int WIFICLUB_StateLevelMenu(WifiClubWork *work, int result)
{
    int choice;
    FlushMenuText(work);
    choice = BMP_MENULIST_Main(work->menuList);
    if (choice != -2) {
        if (choice == -1) {
            return result;
        }
        work->ruleLevel = choice;
        work->session->ruleLevel = choice;
    }
    work->state = WIFICLUB_STATE_OPEN_RULE_MENU;
    WIFICLUB_ClearTalkWindow(work);
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[2]);
    BMP_MENUWORK_Delete(work->menuWork);
    return result;
}


int WIFICLUB_StateOpenOptionMenu(WifiClubWork *work, int result)
{
    WIFICLUB_CreateOptionMenu(work);
    work->state = WIFICLUB_STATE_OPTION_MENU;
    return result;
}


/*
 * Twin of WIFICLUB_StateKindMenu: stores 1 - r at +0x20 of the record at +0x248 and
 * hands +0x23a to BMP_MENULIST_Delete.
 */
int WIFICLUB_StateOptionMenu(WifiClubWork *work, int result)
{
    int choice;
    FlushMenuText(work);
    choice = BMP_MENULIST_Main(work->menuList);
    if (choice != -2) {
        if (choice == -1) {
            return result;
        }
        work->session->ruleOption = 1 - choice;
    }
    work->state = WIFICLUB_STATE_OPEN_RULE_MENU;
    WIFICLUB_ClearTalkWindow(work);
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[3]);
    BMP_MENUWORK_Delete(work->menuWork);
    return result;
}


int WIFICLUB_CheckPartyAgainstRules(void *regulationData, void *gameData, u32 *mask)
{
    *mask = 0;
    return POKE_REGULATION_CheckParty(regulationData, GAME_DATA_GetMyParty(gameData), mask);
}


/*
 * note: Two bytes of alignment padding follow at 0x021BCBAE.
 */
void *WIFICLUB_LoadSavedRegulation(void *gameData)
{
    void *obj = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    if (BATTLE_BOX_HasMon(obj) == 0) return 0;
    return func_0200BAF4(obj, 0x21);
}


/*
 * Free-like guard: calls GFL_HEAP_Free only for a non-null pointer.
 */
void WIFICLUB_FreeRegulation(void *p)
{
    if (p != 0) {
        func_020307B0(p);
    }
}


/*
 * Returns 4 or whatever POKE_REGULATION_CheckParty answers, and writes 0 or -1 through
 * the third argument.
 */
int WIFICLUB_CheckSavedRegulation(void *regulationData, void *savedRegulation, int *mask)
{
    int result = 4;
    *mask = 0;
    if (savedRegulation != 0) {
        result = POKE_REGULATION_CheckParty(regulationData, savedRegulation, (u32 *)mask);
    } else {
        *mask = -1;
    }
    return result;
}


/*
 * Loads the regulation for the rule picked by this console (mode 0) or by the session (mode 1)
 * and returns its id, with bit 31 set for a custom rule.
 * WIFICLUB_LoadOwnRegulation below is the mode 0 entry.
 */
u32 WIFICLUB_LoadPickedRegulation(WifiClubWork *work, int mode)
{
    int kind, level, customFlag;
    WifiClubSession *session;
    u32 ruleId;
    switch (mode) {
    case 0:
    default:
        kind = work->ruleKind;
        level = work->ruleLevel;
        customFlag = work->session->regulationId;
        break;
    case 1:
        session = work->session;
        kind = session->ruleKind;
        level = session->ruleLevel;
        customFlag = session->ruleOption;
        break;
    }
    ruleId = gWifiClubRuleIdTable[kind + level * 4];
    if (work->regulationData != 0) {
        func_020307B0(work->regulationData);
    }
    work->regulationData = POKE_REGULATION_Load(ruleId, 0x21);
    if (customFlag != 0) {
        ruleId |= 0x80000000;
    }
    return ruleId;
}


u32 WIFICLUB_LoadOwnRegulation(WifiClubWork *work)
{
    return WIFICLUB_LoadPickedRegulation(work, 0);
}


void WIFICLUB_ApplyRuleId(WifiClubWork *work, u32 ruleId)
{
    u32 id;
    int i;
    work->session->regulationId = (ruleId & 0x80000000) != 0;
    id = ruleId & 0x0fffffff;
    for (i = 0; i < 8u; i++) {
        if (id == gWifiClubRuleIdTable[i]) {
            work->ruleKind = i % 4;
            work->ruleLevel = i / 4;
        }
    }
}


int WIFICLUB_StateCheckRules(WifiClubWork *work, int result)
{
    int mode;
    WifiClubSession *session;
    mode = work->connectionMode;
    if (mode == 3 || mode == 1) {
        WIFICLUB_LoadPickedRegulation(work, 1);
    } else {
        WIFICLUB_LoadPickedRegulation(work, 0);
    }
    if (WIFICLUB_HasRuleViolation(work) == 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
        work->state = WIFICLUB_STATE_RULE_VIOLATION_KEY;
        return result;
    }
    work->noticeKind = 7;
    session = work->session;
    if (session->voiceChat[0] != session->voiceChat[1]) {
        work->state = WIFICLUB_STATE_SHOW_RULE_CHOICE_MESSAGE;
    } else {
        work->state = WIFICLUB_STATE_SEND_MODE_TO_PEER;
    }
    WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
    if (work->connectionMode - 3 <= 1u) {
        WIFICLUB_ShowStreamedMessage(work, 0xE, 0);
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x4C, 0);
    }
    WIFICLUB_ResetTimeIcon(work);
    return result;
}


int WIFICLUB_StateRuleViolationKey(WifiClubWork *work, int result)
{
    u32 mask;
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return result;
    }
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_CheckPartyAgainstRules(work->regulationData, work->gameData, &mask);
        WIFICLUB_ShowRuleWindow(work, mask, work->session->regulationId, 2);
        work->state = WIFICLUB_STATE_VIOLATION_LIST_KEY;
    }
    return result;
}


int WIFICLUB_StateViolationListKey(WifiClubWork *work, int result)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(work);
        if (work->savedRegulation != 0) {
            int mask;
            WIFICLUB_CheckSavedRegulation(work->regulationData, work->savedRegulation, &mask);
            WIFICLUB_ShowRuleWindow(work, mask, work->session->regulationId, 3);
            work->state = WIFICLUB_STATE_RULE_TEXT_KEY;
        } else {
            switch (work->connectionMode) {
            case 3:
                work->state = WIFICLUB_STATE_OPEN_RULE_MENU;
                break;
            case 2:
                work->exitCode = 0x97;
                work->state = WIFICLUB_STATE_START_REPLY_SYNC;
                break;
            case 4:
                work->exitCode = 0x90;
                work->state = WIFICLUB_STATE_START_REPLY_SYNC;
                break;
            default:
                work->state = WIFICLUB_STATE_DISCONNECT_TO_LOBBY;
                break;
            }
        }
    }
    return result;
}


int WIFICLUB_StateRuleTextKey(WifiClubWork *work, int result)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(work);
        WIFICLUB_ClearTalkWindow(work);
        switch (work->connectionMode) {
        case 3:
            work->state = WIFICLUB_STATE_OPEN_RULE_MENU;
            break;
        case 2:
            work->exitCode = 0x97;
            work->state = WIFICLUB_STATE_START_REPLY_SYNC;
            break;
        case 4:
            work->exitCode = 0x90;
            work->state = WIFICLUB_STATE_START_REPLY_SYNC;
            break;
        default:
            work->state = WIFICLUB_STATE_DISCONNECT_TO_LOBBY;
            break;
        }
    }
    return result;
}


int WIFICLUB_StateShowRuleSet(WifiClubWork *work, int result)
{
    WIFICLUB_LoadPickedRegulation(work, 1);
    WIFICLUB_ShowRuleWindow(work, 0, work->session->ruleOption, 0);
    work->state = WIFICLUB_STATE_RULE_SET_KEY;
    return result;
}


int WIFICLUB_StateRuleSetKey(WifiClubWork *work, int result)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(work);
        work->state = WIFICLUB_STATE_OPEN_RULE_MENU;
    }
    return result;
}


int WIFICLUB_StateShowRulePreview(WifiClubWork *work, int result)
{
    if (GFL_NET_IsParentAid() == 0) {
        WIFICLUB_LoadOwnRegulation(work);
        WIFICLUB_ShowRuleWindow(work, 0, work->session->regulationId, 1);
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_PrintTalkMessage(work, work->ruleKind + 0x69 + (work->ruleLevel << 2), 0, 1);
        work->state = WIFICLUB_STATE_RULE_PREVIEW_DONE;
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x4C, 0);
        WIFICLUB_ResetTimeIcon(work);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0xA);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    }
    return result;
}


int WIFICLUB_StateRulePreviewDone(WifiClubWork *work, int result)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return result;
    }
    work->state = WIFICLUB_STATE_RULE_PREVIEW_KEY;
    return result;
}


int WIFICLUB_StateRulePreviewKey(WifiClubWork *work, int result)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(work);
        work->state = WIFICLUB_STATE_RULE_PREVIEW_CLOSE;
    }
    return result;
}


int WIFICLUB_StateRulePreviewClose(WifiClubWork *work, int result)
{
    work->state = WIFICLUB_STATE_OPEN_ENTRY_PROMPT;
    return result;
}


int WIFICLUB_StateIdle(WifiClubWork *work, int result)
{
    return result;
}


/* Opens the entry yes/no prompt, then waits for the answer. */
int WIFICLUB_StateOpenEntryPrompt(WifiClubWork *work, int state)
{
    WIFICLUB_OpenYesNoMenu(work);
    work->state = WIFICLUB_STATE_POLL_ENTRY_PROMPT;
    return state;
}


/*
 * Polls the entry prompt: yes goes on to the party check, no (or an unusable mode)
 * returns to the menu with a message.
 */
int WIFICLUB_StatePollEntryPrompt(WifiClubWork *work, int state)
{
    int promptAnswer;

    GF_FONT_SetDefaultTextColor();
    promptAnswer = WIFICLUB_PollYesNoMenu(work);
    if (promptAnswer == -1) {
        return state;
    }
    if (promptAnswer == 0) {
        work->state = WIFICLUB_STATE_CHECK_ENTRY_RULES;
        WIFICLUB_ClearTalkWindow(work);
    } else {
        if ((unsigned)(work->connectionMode - 1) <= 1) {
            work->exitCode = 0x4A;
            WIFICLUB_ShowStreamedMessage(work, 0x4A, 0);
        } else {
            work->exitCode = 0x90;
        }
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return state;
}


/* Waits for a key press, then shows the cancel message and returns to the menu. */
int WIFICLUB_StateCancelOnKey(WifiClubWork *work, int state)
{
    if (KEY_GetTrg() != 0) {
        work->exitCode = 0x6E;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return state;
}


/*
 * Checks the party against the rules; shows the failure message for the current mode
 * or goes on.
 */
int WIFICLUB_StateCheckEntryRules(WifiClubWork *work, int state)
{
    WIFICLUB_LoadOwnRegulation(work);
    if (WIFICLUB_HasRuleViolation(work) == 0) {
        switch (work->connectionMode) {
        case 3:
            work->state = WIFICLUB_STATE_CANCEL_ON_KEY_AFTER_MESSAGE;
            WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
            return state;
        case 2:
        case 4:
            work->state = WIFICLUB_STATE_RULE_VIOLATION_KEY;
            WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
            return state;
        default:
            work->state = WIFICLUB_STATE_KEY_THEN_EXIT;
            WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
            return state;
        }
    }
    work->exitCode = 0x64;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return state;
}


/*
 * When the message has ended and a key is pressed, shows the cancel message and
 * returns to the menu.
 */
int WIFICLUB_StateCancelOnKeyAfterMessage(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) return state;
    if (KEY_GetTrg() == 0) return state;
    work->exitCode = 0x6e;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return state;
}


/*
 * Copies the valid party into the seat buffer of this console, or shows the rule
 * violation message.
 */
int WIFICLUB_StateRegisterEntryParty(WifiClubWork *work, int state)
{
    int seat;
    int violationMask;

    seat = 0;
    if (GFL_NET_IsParentAid() == 0) {
        seat = 1;
    }
    if (WIFICLUB_CheckSavedRegulation(work->regulationData, work->savedRegulation, &violationMask) != 0
        && work->savedRegulation == 0) {
        POKEPARTY_Copy(GAME_DATA_GetMyParty(work->gameData),
                      work->session->seatParty[seat]);
        work->state = WIFICLUB_STATE_SEND_REGISTERED_PARTY;
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x71, 0);
        work->state = WIFICLUB_STATE_OPEN_PARTY_MENU;
    }
    return state;
}


/* After the message, builds the choice list of own party and box party. */
int WIFICLUB_StateOpenPartyMenu(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return state;
    }
    work->menuPosition = 2;
    WIFICLUB_CreateRuleChoiceMenu(work);
    WIFICLUB_LoadPartyIcons(work, GAME_DATA_GetMyParty(work->gameData), work->savedRegulation);
    work->state = WIFICLUB_STATE_UPDATE_PARTY_MENU;
    return state;
}


/*
 * Runs the party choice list, previews the party under the cursor and registers the
 * chosen one if it passes the rules.
 */
int WIFICLUB_StateUpdatePartyMenu(WifiClubWork *work, int state)
{
    int seat;
    void *printQueue;
    int menuResult;
    int violationMask;
    u16 menuPos[2];

    seat = 0;
    printQueue = work->msgPrintQueue;
    if (work->menuPending.pending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printQueue, BMP_WIN_GetBmp((struct BmpWin *)work->menuPending.win)) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)work->menuPending.win);
            work->menuPending.pending = 0;
        }
    }
    menuResult = BMP_MENULIST_Main(work->menuList);
    BMP_MENULIST_GetPos(work->menuList, &menuPos[1], &menuPos[0]);
    if (menuPos[0] != work->menuPosition) {
        work->menuPosition = menuPos[0];
        if (menuPos[0] == 0) {
            WIFICLUB_DrawPartyListWindow(work, GAME_DATA_GetMyParty(work->gameData));
            WIFICLUB_ShowPartyIconHalf(work, 1);
        } else {
            WIFICLUB_DrawPartyListWindow(work, work->savedRegulation);
            WIFICLUB_ShowPartyIconHalf(work, 0);
        }
    }
    if (GFL_NET_IsParentAid() == 0) {
        seat = 1;
    }
    switch (menuResult) {
    case -1:
        return state;
    case -2:
        return state;
    case 0:
        if (WIFICLUB_CheckPartyAgainstRules(work->regulationData, work->gameData, (u32 *)&violationMask) != 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
            work->state = WIFICLUB_STATE_SHOW_PARTY_VIOLATIONS;
            WIFICLUB_DeleteMenuAndIcons(work);
            return state;
        }
        POKEPARTY_Copy(GAME_DATA_GetMyParty(work->gameData), work->session->seatParty[seat]);
        work->state = WIFICLUB_STATE_SEND_REGISTERED_PARTY;
        break;
    case 1:
        if (WIFICLUB_CheckSavedRegulation(work->regulationData, work->savedRegulation, &violationMask) != 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
            work->state = WIFICLUB_STATE_SHOW_BOX_PARTY_VIOLATIONS;
            WIFICLUB_DeleteMenuAndIcons(work);
            return state;
        }
        POKEPARTY_Copy(work->savedRegulation, work->session->seatParty[seat]);
        work->state = WIFICLUB_STATE_SEND_REGISTERED_PARTY;
        break;
    }
    WIFICLUB_DeleteMenuAndIcons(work);
    WIFICLUB_ClearTalkWindow(work);
    return state;
}


/* Sends the registered party to the peer. */
int WIFICLUB_StateSendRegisteredParty(WifiClubWork *work, int state)
{
    int seat;
    struct NetHandle *handle;

    seat = 0;
    if (GFL_NET_IsParentAid() == 0) {
        seat = 1;
    }
    handle = GFL_NET_HANDLE_GetCurrentHandle();
    if (GFL_NET_SendData(handle, 0xFF, 0xA07, POKE_REGULATION_GetDataSize(),
                      work->session->seatParty[seat], 0, 0, 1) != 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x4C, 0);
        WIFICLUB_ResetTimeIcon(work);
        work->state = WIFICLUB_STATE_SYNC_AFTER_PARTY_SEND;
    }
    return state;
}


/* After the message, starts the timing sync that follows the party exchange. */
int WIFICLUB_StateSyncAfterPartySend(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 10);
        work->state = WIFICLUB_STATE_SHOW_RULE_MATCH_MESSAGE;
    }
    return state;
}


/* When the peer reached the sync, shows the message that matches the two rule choices. */
int WIFICLUB_StateShowRuleMatchMessage(WifiClubWork *work, int state)
{
    int leftRule;
    int rightRule;
    int messageId;

    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x11, 0xA) != 0) {
        leftRule = REGULATION_GetRuleValue((struct Regulation *)(work->regulationData), 2);
        rightRule = REGULATION_GetRuleValue((struct Regulation *)(work->regulationData), 3);
        if (leftRule == 3 && rightRule == 3) {
            messageId = 0x92;
        } else if (leftRule == 4 && rightRule == 4) {
            messageId = 0x93;
        } else if (leftRule == 6 && rightRule == 6) {
            messageId = 0x94;
        } else {
            messageId = 0x91;
        }
        WIFICLUB_ShowStreamedMessage(work, messageId, 0);
        WIFICLUB_ResetTimeIcon(work);
        work->counter = 0x78;
        work->state = WIFICLUB_STATE_WAIT_RULE_MESSAGE_TIMER;
    }
    return state;
}


/* Counts down the message timer, then goes on. */
int WIFICLUB_StateWaitRuleMessageTimer(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        int timer = work->counter;

        work->counter = timer - 1;

        if (timer < 0) {
            work->state = WIFICLUB_STATE_WIFICLUB_APPLY_CHOSEN_RULE;
        }
    }

    return state;
}


/*
 * Resets the player status, looks up the rule chosen in the menu and announces it.
 * Returns the new state.
 */
int WIFICLUB_ApplyChosenRule(WifiClubWork *work)
{
    WifiClubRuleTable ruleTable;
    u32 ruleId;

    WIFICLUB_CopyZeroToDeviceAddr(work->localStatus);
    work->sceneReady = 0;
    ruleTable = d_021C38EC;
    ruleId = ruleTable.v[work->ruleLevel + work->ruleKind * 2];
    work->sceneKind = ruleId;
    WIFICLUB_StartVoiceChat(work);
    WIFICLUB_ClearTalkWindow(work);
    WIFICLUB_SetOwnStatusAndPublish(work, 4, ruleId);
    return 2;
}


/* On a key press, lists the rules the own party breaks. */
int WIFICLUB_StateShowPartyViolations(WifiClubWork *work, int state)
{
    int violationMask;
    if (WIFICLUB_UpdateTalkStream(work) == 0) return state;
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_CheckPartyAgainstRules(work->regulationData, work->gameData, (u32 *)&violationMask);
        WIFICLUB_ShowRuleWindow(work, violationMask, work->session->regulationId, 2);
        work->state = WIFICLUB_STATE_CLOSE_VIOLATION_LIST;
    }
    return state;
}


/* On a key press, lists the rules the box party breaks. */
int WIFICLUB_StateShowBoxPartyViolations(WifiClubWork *work, int state)
{
    int violationMask;
    if (WIFICLUB_UpdateTalkStream(work) == 0) return state;
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_CheckSavedRegulation(work->regulationData, work->savedRegulation, &violationMask);
        WIFICLUB_ShowRuleWindow(work, violationMask, work->session->regulationId, 3);
        work->state = WIFICLUB_STATE_CLOSE_VIOLATION_LIST;
    }
    return state;
}


/* On a key press, closes the violation list and returns to the party menu message. */
int WIFICLUB_StateCloseViolationList(WifiClubWork *work, int state)
{
    if (KEY_GetTrg() != 0) {
        WIFICLUB_DeleteRuleWindow(work);
        WIFICLUB_ShowStreamedMessage(work, 0x71, 0);
        work->state = WIFICLUB_STATE_OPEN_PARTY_MENU;
    }
    return state;
}


/* After the message: the child waits for the parent, the parent syncs. */
int WIFICLUB_StateBranchOnSeat(WifiClubWork *work, int state)
{
    int messageDone;
    messageDone = WIFICLUB_UpdateTalkStream(work);
    if (messageDone == 0) return state;
    if (GFL_NET_IsParentAid() == 0) {
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 0x77, 0);
        work->state = WIFICLUB_STATE_OPEN_WAIT_PROMPT;
    } else {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    }
    return state;
}


/* Opens the wait prompt after the message ended. */
int WIFICLUB_StateOpenWaitPrompt(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return state;
    }

    WIFICLUB_OpenYesNoMenu(work);
    work->state = WIFICLUB_STATE_POLL_WAIT_PROMPT;
    return state;
}


/* Polls the wait prompt and returns to the menu with the matching message. */
int WIFICLUB_StatePollWaitPrompt(WifiClubWork *work, int state)
{
    int promptAnswer;
    GF_FONT_SetDefaultTextColor();
    promptAnswer = WIFICLUB_PollYesNoMenu(work);
    if (promptAnswer == -1) return state;
    if (promptAnswer == 0) work->exitCode = 0x44;
    else work->exitCode = 0x4a;
    WIFICLUB_ClearTalkWindow(work);
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return state;
}


/* Waits for the timing sync and resumes the saved state. */
int WIFICLUB_StateWaitSyncAndResume(WifiClubWork *work, int state)
{
    int resumeState;
    WIFICLUB_UpdateTalkStream(work);
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 10) != 0) {
        resumeState = work->resumeState;
        if (resumeState != 0) work->state = resumeState;
        else work->state = WIFICLUB_STATE_LEAVE_CANCEL;
        work->resumeState = 0;
    }
    return state;
}


/* Waits for the timing sync, then returns to the idle state. */
int WIFICLUB_StateWaitSyncAndReturnToIdle(WifiClubWork *work, int state)
{
    WIFICLUB_UpdateTalkStream(work);
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10) != 0) {
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RESUME;
    }
    return state;
}


/* Starts the timing sync that precedes leaving the room. */
int WIFICLUB_StateStartLeaveSync(WifiClubWork *work, int state)
{
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 10);
    work->connectionMode = 0;
    work->state = WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_PARENT;
    return state;
}


/* Once the sync is done, shows the leave message of the parent or the child. */
int WIFICLUB_StateShowLeaveMessageParent(WifiClubWork *work, int state)
{
    int noFlag;
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x19, 10) == 0) return state;
    noFlag = 0;
    GFL_NET_SetAutoExit(0);
    if (GFL_NET_IsParentAid(GFL_NET_SetLoginOption(0)) != 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x7c, noFlag);
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x7d, noFlag);
    }
    work->state = WIFICLUB_STATE_RESET_NET_OPTIONS;
    return state;
}


/* Clears the net auto exit and login option. */
int WIFICLUB_StateDisableAutoExitA(WifiClubWork *work, int state)
{
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    work->state = WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_BY_ROLE_A;
    return state;
}


/* Shows the leave message chosen by the role. */
int WIFICLUB_StateShowLeaveMessageByRoleA(WifiClubWork *work, int state)
{
    u32 role = (unsigned int)work->connectionMode;

    if (role - 2 <= 1) {
        WIFICLUB_ShowStreamedMessage(work, 0x7D, 0);
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x7C, 0);
    }

    work->connectionMode = 0;
    work->state = WIFICLUB_STATE_RESET_NET_OPTIONS;
    return state;
}


/* Clears the net auto exit and login option. */
int WIFICLUB_StateDisableAutoExitB(WifiClubWork *work, int state)
{
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    work->state = WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_BY_ROLE_B;
    return state;
}


/* Shows the leave message chosen by the role (reversed choice). */
int WIFICLUB_StateShowLeaveMessageByRoleB(WifiClubWork *work, int state)
{
    u32 role = (unsigned int)work->connectionMode;

    if (role - 2 <= 1) {
        WIFICLUB_ShowStreamedMessage(work, 0x7C, 0);
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x7D, 0);
    }

    work->connectionMode = 0;
    work->state = WIFICLUB_STATE_RESET_NET_OPTIONS;
    return state;
}


/* Goes back to the idle state. */
int WIFICLUB_StateReturnToIdle(WifiClubWork *work, int state)
{
    work->state = WIFICLUB_STATE_LEAVE_CANCEL;
    return state;
}


/* Shows the leave message of the parent or the child seat. */
int WIFICLUB_StateShowLeaveMessageBySeat(WifiClubWork *work, int state)
{
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    if (GFL_NET_IsParentAid() != 0) WIFICLUB_ShowStreamedMessage(work, 0x73, 0);
    else WIFICLUB_ShowStreamedMessage(work, 0x72, 0);
    work->state = WIFICLUB_STATE_RESET_NET_OPTIONS;
    return state;
}


/* Clears auto exit and login option and the message timer. */
int WIFICLUB_StateResetNetOptions(WifiClubWork *work, int state)
{
    int noFlag = 0;
    GFL_NET_SetAutoExit(noFlag);
    GFL_NET_SetLoginOption(noFlag);
    work->counter = noFlag;
    work->state = WIFICLUB_STATE_LEAVE_TIMEOUT;
    return state;
}


/* Shows the rule choice message picked by the peer voice chat flag. */
int WIFICLUB_StateShowRuleChoiceMessage(WifiClubWork *work, int state)
{
    u8 peerVoiceChat = work->session->voiceChat[1];
    int messageId;

    if (peerVoiceChat != 0) {
        messageId = 0x48;
    } else {
        messageId = 0x49;
    }

    WIFICLUB_ShowStreamedMessage(work, messageId, 0);
    work->state = WIFICLUB_STATE_OPEN_RULE_CHOICE_PROMPT;
    return state;
}


/* Opens the rule choice prompt after the message ended. */
int WIFICLUB_StateOpenRuleChoicePrompt(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return state;
    }

    WIFICLUB_OpenYesNoMenu(work);
    work->state = WIFICLUB_STATE_POLL_RULE_CHOICE_PROMPT;
    return state;
}


/* Polls the rule choice prompt. */
int WIFICLUB_StatePollRuleChoicePrompt(WifiClubWork *work, int state)
{
    int promptAnswer;
    GF_FONT_SetDefaultTextColor();
    promptAnswer = WIFICLUB_PollYesNoMenu(work);
    if (promptAnswer == -1) return state;
    if (promptAnswer == 0) {
        work->state = WIFICLUB_STATE_SEND_SEAT_REQUEST;
    } else {
        work->state = WIFICLUB_STATE_SHOW_MENU_REJECT;
    }
    WIFICLUB_ClearTalkWindow(work);
    return state;
}


/* Shows the reject message and returns to the menu. */
int WIFICLUB_StateShowMenuReject(WifiClubWork *work, int state)
{
    work->exitCode = 0x4a;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return state;
}


/* Handlers and helpers defined in this file. */

/* Sends the seat request to the peer and waits for the reply. */
int WIFICLUB_StateSendSeatRequest(WifiClubWork *work, int state)
{
    WifiClubSeatRequest request;
    request.phase = WIFICLUB_GetStatusPhase(work, work->localStatus);
    request.peerSeat = 1 - work->session->ownSeat;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa03, 4, (unsigned)&request) != 0) {
        work->state = WIFICLUB_STATE_SEND_MODE_TO_PEER;
        WIFICLUB_SetStatusModeFlag(work->localStatus, request.peerSeat);
    }
    return state;
}


/* Sends the chosen mode to the peer, or rejects an unusable mode. */
int WIFICLUB_StateSendModeToPeer(WifiClubWork *work, int state)
{
    int selectedMode;
    if (work->noticeKind == 6) {
        work->exitCode = 0x4d;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    } else {
        if (work->connectionMode == 3 || work->connectionMode == 1) {
            selectedMode = WIFICLUB_LoadPickedRegulation(work, 1);
        } else {
            selectedMode = WIFICLUB_LoadPickedRegulation(work, 0);
        }
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa06, 4, (u32)(&selectedMode)) != 0) {
            work->state = WIFICLUB_STATE_SHOW_DECLINE_MESSAGE;
        }
    }
    return state;
}


/* Shows the decline message and returns to the menu. */
int WIFICLUB_StateShowDeclineMessage(WifiClubWork *work, int state)
{
    work->exitCode = 0x5e;
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return state;
}


/* Starts the timing sync before the reply is sent. */
int WIFICLUB_StateStartReplySync(WifiClubWork *work, int state)
{
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1B, 0x0A);
    work->state = WIFICLUB_STATE_SEND_REPLY_CODE;

    return state;
}


/* After the sync, sends the reply code to the peer. */
int WIFICLUB_StateSendReplyCode(WifiClubWork *work, int state)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10) != 0) {
        if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa05, 1, (u32)&work->exitCode) != 0) {
            work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RESUME;
        }
    }
    return state;
}


/* Resets the seat role and shows the disconnect notice for the parent or the child. */
int WIFICLUB_StateShowDisconnectNotice(WifiClubWork *work, int state)
{
    int noFlag;
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    noFlag = 0;
    work->connectionMode = noFlag;
    GFL_NET_SetAutoExit(0);
    if (GFL_NET_IsParentAid(GFL_NET_SetLoginOption(0)) != 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x73, noFlag);
    } else {
        WIFICLUB_ShowStreamedMessage(work, 0x7c, noFlag);
    }
    work->state = WIFICLUB_STATE_RESET_NET_OPTIONS;
    return state;
}


/* Notifies the net layer, then the child waits and the parent syncs. */
int WIFICLUB_StateBranchOnSeatAfterNotify(WifiClubWork *work, int state)
{
    int noFlag;
    noFlag = 0;
    if (GFL_NET_IsParentAid(GFL_NET_NotifyUserEvent((unsigned int)GFL_NET_HANDLE_GetCurrentHandle(), 0)) == 0) {
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 0x77, noFlag);
        work->state = WIFICLUB_STATE_OPEN_LEAVE_PROMPT;
    } else {
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 0x4c, noFlag);
        WIFICLUB_ResetTimeIcon(work);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 10);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
    }
    return state;
}


/* Opens the leave prompt after the message ended. */
int WIFICLUB_StateOpenLeavePrompt(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) {
        return state;
    }

    WIFICLUB_OpenYesNoMenu(work);
    work->state = WIFICLUB_STATE_POLL_LEAVE_PROMPT;
    return state;
}


/* Polls the leave prompt and returns to the menu. */
int WIFICLUB_StatePollLeavePrompt(WifiClubWork *work, int state)
{
    int promptAnswer;
    GF_FONT_SetDefaultTextColor();
    promptAnswer = WIFICLUB_PollYesNoMenu(work);
    if (promptAnswer == -1) return state;
    if (promptAnswer == 0) work->exitCode = 0x44;
    else work->exitCode = 0xa8;
    WIFICLUB_ClearTalkWindow(work);
    work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    return state;
}


/* Waits for the timing sync, then continues. */
int WIFICLUB_StateWaitSyncAndContinue(WifiClubWork *work, int state)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 0xA) == 0) {
        return state;
    }

    work->state = WIFICLUB_STATE_BRANCH_ON_SEAT_AFTER_NOTIFY;
    return state;
}


/*
 * Reacts to the phase the peer reported: start, join, or the normal party and rule
 * check.
 */
int WIFICLUB_StateHandlePeerPhase(WifiClubWork *work, int state)
{
    u16 peerPhase;
    int violationMask;
    peerPhase = (u16)WIFICLUB_GetStatusPhase(work, work->localStatus);
    switch (peerPhase) {
    case 4:
        GFL_NET_GetInitParam();
        WIFICLUB_StartVoiceChat(work);
        WIFICLUB_StartBgmFade(work, 0);
        WIFICLUB_ShowMessage(work, 0x7b, 0);
        work->sceneResult = 0;
        work->state = WIFICLUB_STATE_SYNC_TIMING_START;
        return state;
    case 5:
        work->sceneKind = peerPhase;
        return 2;
    case 6:
        WIFICLUB_StartVoiceChat(work);
        work->sceneKind = peerPhase;
        return 2;
    default:
        GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
        if (GFL_NET_IsParentAid()) {
            if (WIFICLUB_CheckPartyAgainstRules(work->regulationData, work->gameData, (u32 *)(&violationMask)) &&
                WIFICLUB_CheckSavedRegulation(work->regulationData, work->savedRegulation, &violationMask)) {
                WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
                work->state = WIFICLUB_STATE_CLOSE_MESSAGE_ON_KEY;
                return state;
            }
            work->state = WIFICLUB_STATE_CHECK_RULES;
        } else {
            GFL_NET_HANDLE_SetTimingSyncRange((void *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 0xa);
            work->state = WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE;
        }
        return state;
    }
}


/*
 * After the message ended and a key is pressed, closes the prompt and returns to the
 * menu.
 */
int WIFICLUB_StateCloseMessageOnKey(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) return state;
    if (KEY_GetTrg() != 0) {
        WIFICLUB_ClearTalkWindow(work);
        work->exitCode = 0x4a;
        work->state = WIFICLUB_STATE_START_REPLY_SYNC;
    }
    return state;
}


/* Applies the rule selected in the menu or shows the failure message. */
int WIFICLUB_StateApplyRuleSelection(WifiClubWork *work, int state)
{
    WifiClubRuleTable ruleTable;
    WIFICLUB_LoadPickedRegulation(work, 1);
    if (WIFICLUB_HasRuleViolation(work) == 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
        work->state = WIFICLUB_STATE_RULE_VIOLATION_KEY;
        return state;
    }
    ruleTable = d_021C390C;
    WIFICLUB_SetOwnStatusAndPublish(work, 2, (u16)ruleTable.v[work->ruleLevel + work->ruleKind * 2]);
    WIFICLUB_AddNetCommandsAndCheckFriend(work, -1);
    work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
    WIFICLUB_EnableTouchBar(work, 1);
    return state;
}


/* Loads the friend roster from the game data. */
void WIFICLUB_LoadFriendRoster(WifiClubWork *work)
{
    func_02009860((struct FriendRoster *)GAME_DATA_GetField1A0(work->gameData));
}


/* Looks up the first entry of the friend roster. */
void WIFICLUB_GetFirstFriendEntry(WifiClubWork *work)
{
    func_020099C8((struct FriendRoster *)GAME_DATA_GetField1A0(work->gameData), 0);
}


/* Copies a friend roster entry. */
void WIFICLUB_CopyFriendEntry(int srcIndex, int destIndex, WifiClubWork *work)
{
    func_02009C24((struct FriendRoster *)GAME_DATA_GetField1A0(work->gameData), srcIndex, destIndex);
}


/*
 * Sets the net heap size for DS or DSi and starts the session, or only copies the init
 * parameters.
 */
void WIFICLUB_StartNetSession(WifiClubWork *work, int startSession)
{
    if (OS_IsRunOnTwl())
        d_021C3B9C.heapSize = 0x79000;
    else
        d_021C3B9C.heapSize = 0x5e400;
    if (startSession)
        GFL_NET_StartSession(&d_021C3B9C, 0, (u32)work);
    else
        GFL_NET_CopyInitParam(&d_021C3B9C);
}


/* Returns the kind byte of a visitor status. */
int WIFICLUB_GetStatusKind(WifiClubWork *work, WifiClubPlayerStatus *status)
{
    return WIFICLUB_GetStatusActionState(status);
}


/* Returns the phase byte of a visitor status. */
int WIFICLUB_GetStatusPhase(WifiClubWork *work, WifiClubPlayerStatus *status)
{
    return WIFICLUB_GetStatusActionArg(status);
}


/* True for phases 7 to 14. */
int WIFICLUB_IsBusyPhase(int phase)
{
    switch (phase) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
        return 1;

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    default:
        return 0;
    }
}


/* True for phases 4 to 14. */
int WIFICLUB_IsActivePhase(int phase) {
    if (phase < 15 && phase > 3) return 1;
    return 0;
}


/* True when the kind is 2. */
BOOL WIFICLUB_IsKindActive(int phase)
{
    if (phase == 2) {
        return 1;
    }

    return 0;
}


/* True for net mode 4 with a busy phase. */
BOOL WIFICLUB_ShouldEnterWaitMode(int kind, void *value)
{
    if (WIFICLUB_IsBusyPhase((int)value) != 0 && kind == 4) {
        return 1;
    }

    return 0;
}


/* True when the party holds at least two non-egg Pokemon. */
int WIFICLUB_HasEnoughPartyMembers(WifiClubWork *work)
{
    GAME_DATA_GetBoxManager(work->gameData);
    if ((int)POKEPARTY_GetNonEggCount(GAME_DATA_GetMyParty(work->gameData)) >= 2) return 1;
    return 0;
}


/* Returns 0 when both the party and the box party pass the rules, else 1. */
int WIFICLUB_HasRuleViolation(WifiClubWork *work)
{
    int violationMask;
    if (WIFICLUB_CheckPartyAgainstRules(work->regulationData, work->gameData, (u32 *)&violationMask)
        && WIFICLUB_CheckSavedRegulation(work->regulationData, work->savedRegulation, &violationMask)) {
        return 0;
    }
    return 1;
}


/* Switches the net wait mode for the new mode and notifies the net layer. */
void WIFICLUB_ChangeNetMode(WifiClubWork *work, int kind, int value)
{
    if (kind == 1) {
        GFL_NET_SetWaitMode(0);
        WIFICLUB_StartNetSession(work, 0);
    } else {
        if (WIFICLUB_ShouldEnterWaitMode(kind, (void *)value)) GFL_NET_SetWaitMode(1);
    }
    switch (kind) {
    case 2:
    case 5:
        GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        return;
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    default:
        GFL_NET_NotifyUserEvent((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        break;
    }
}


/* Sets up display, text, message data, fonts, backgrounds and sprites of the club. */
void WIFICLUB_InitScreen(WifiClubWork *work)
{
    void *archive;
    if (work->updateTask != 0) func_02030EAC(work->updateTask);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u32 *)0x04000000 &= 0xffffe0ff;
    *(volatile u32 *)0x04001000 &= 0xffffe0ff;
    archive = func_020490F4(0x21, 0x21);
    work->wordSet = WORDSET_CreateDefault(0x21);
    work->msgBank = func_02045B38(0, 2, 0xd1, 0x21);
    work->msgBankAlt = func_02045B38(0, 2, 0xe8, 0x21);
    work->textFont = GF_FONT_Create(0x17, 0, 0, 0, 0x21);
    work->nameFont = GF_FONT_Create(0x17, 3, 0, 0, 0x21);
    BMP_SetDisplaySwap(1);
    WIFICLUB_InitVram();
    WIFICLUB_InitBackgrounds(0x21);
    BMP_WIN_Init(0x21);
    WIFICLUB_InitPlanesAndText(work, (int)archive);
    work->updateTask = func_020056A0((u32)WIFICLUB_VBlankTask, (u32)work, 1);
    WIFICLUB_TaskHook(work->updateTask);
    WIFICLUB_InitSprites(work, archive);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    ARC_TOOL_DeleteHandle(archive);
}


/* Frees everything WIFICLUB_InitScreen created. */
void WIFICLUB_ExitScreen(WifiClubWork *work)
{
    if (work->updateTask != 0) func_02030EAC(work->updateTask);
    WIFICLUB_DeleteTrainerActor(work);
    WIFICLUB_DeleteTouchBar(work);
    WIFICLUB_LoadPanelGraphics(work);
    if (WIFICLUBACTOR_IsReady((&work->actorSys)) == 1) WIFICLUB_ClearPeerActors(work);
    if (WIFICLUB_IsSlotPanelOpen(work) == 1) WIFICLUB_CloseSlotPanel(work);
    WIFICLUB_FreeBgResources((&work->bgLoad));
    CLACT_DeleteRenderer(work->clactRenderer);
    CLACT_DeleteUnit(work->clactUnit);
    CLACT_ExitSystem();
    WIFICLUB_DeleteAllWindows(work);
    WIFICLUB_ExitHook(work);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MSGDATA_Delete(work->msgBankAlt);
    MSGDATA_Delete(work->msgBank);
    WORDSET_DeleteStrbufED04(work->wordSet);
    GF_FONT_Delete(work->nameFont);
    GF_FONT_Delete(work->textFont);
}


/* V-blank task: updates the sprite system. */
void WIFICLUB_VBlankTask(void)
{
    CLACT_VBlankSystem();
}


/* Sets the VRAM bank layout. */
void WIFICLUB_InitVram(void)
{
    BG_SYS_SetVramBanks((const struct VramBankConfig *)data_021C3AA0);
}


/* Sets the display config and the eight background layers. */
void WIFICLUB_InitBackgrounds(u16 heapId)
{
    WifiClubDispConfig dispConfig;
    WifiClubBgTemplate bg0, bg1, bg2, bg3, bg4, bg5, bg6, bg7;
    int i;
    BG_SYS_Create(heapId);
    dispConfig = d_021C37F4;
    BG_SYS_SetGraphicsMode(&dispConfig);
    bg0 = d_021C396C;
    i = 0;
    BG_SYS_InitBgLayer(0, &bg0, 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    bg1 = d_021C382C;
    BG_SYS_InitBgLayer(1, &bg1, 0);
    BG_SYS_FreeSlot(1);
    BG_SYS_PushTile(1);
    bg2 = d_021C384C;
    BG_SYS_InitBgLayer(2, &bg2, 0);
    BG_SYS_Init(2, 0, 1, 0);
    BG_SYS_FreeSlot(2);
    BG_SYS_PushTile(2);
    bg3 = d_021C386C;
    BG_SYS_InitBgLayer(3, &bg3, 0);
    BG_SYS_FreeSlot(3);
    BG_SYS_PushTile(3);
    bg4 = d_021C38AC;
    BG_SYS_InitBgLayer(4, &bg4, 0);
    BG_SYS_FreeSlot(4);
    bg5 = d_021C38CC;
    BG_SYS_InitBgLayer(5, &bg5, 0);
    BG_SYS_FreeSlot(5);
    bg6 = d_021C392C;
    BG_SYS_InitBgLayer(6, &bg6, 0);
    BG_SYS_FreeSlot(6);
    bg7 = d_021C394C;
    BG_SYS_InitBgLayer(7, &bg7, 0);
    BG_SYS_FreeSlot(7);
    for (; i < 7; i++) BG_SYS_InitSlot((u8)i);
    BG_SYS_SetVisibleLayer(0, 3);
    BG_SYS_SetVisibleLayer(1, 1);
    BG_SYS_SetVisibleLayer(3, 1);
    BG_SYS_SetVisibleLayer(2, 0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}


/* Stores an actor in the first free peer slot. */
void WIFICLUB_AddPeerActor(WifiClubWork *work, void *actor)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (work->peerSlots[i] == 0) {
            work->peerSlots[i] = actor;
            return;
        }
    }
}


/* Clears the slot that holds the actor. */
void WIFICLUB_RemovePeerActor(WifiClubWork *work, void *actor)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (work->peerSlots[i] == actor) {
            work->peerSlots[i] = 0;
            return;
        }
    }
}


/* Shuts the actor system down and clears every peer slot and the shown-state arrays. */
void WIFICLUB_ClearPeerActors(WifiClubWork *work)
{
    int i;
    WIFICLUBACTOR_Exit((&work->actorSys));
    for (i = 0; i < WIFICLUB_PEER_SLOT_COUNT; i++) {
        *(int *)((unsigned int)work + (unsigned int)i * 4 + 0x814) = 0;
        WIFICLUB_ClearSlotState(work, i + 1);
    }
    MI_CpuFill8(work->shownActorState, 0, WIFICLUB_SLOT_COUNT);
}


/* Returns the actor with the given id, or null. */
void *WIFICLUB_FindPeerActor(WifiClubWork *work, int key)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        if (work->peerSlots[i] != 0 &&
            WIFICLUBACTOR_GetActorId(work->peerSlots[i]) == key) {
            return work->peerSlots[i];
        }
    }
    return 0;
}


/* Loads the background resources of the club screen. */
void WIFICLUB_LoadBgResources(WifiClubBgLoad *bgLoad, int archive, int heapId)
{
    func_02049B68((void *)archive, 4, 0, 0x100, 0x80, heapId);
    func_02049B68((void *)archive, 4, 4, 0x100, 0x80, heapId);
    bgLoad->mainRegion = func_02049740((void *)archive, 13, 1, 0, 0, heapId);
    bgLoad->subRegion = func_02049740((void *)archive, 13, 6, 0, 0, heapId);
    if (bgLoad->cellHandle == 0) {
        bgLoad->cellHandle = func_02049E74((void *)archive, 13, 0, (u32)&bgLoad->cellData, heapId);
    }
    if (bgLoad->screenHandle == 0) {
        bgLoad->screenHandle = func_02049EF4((void *)archive, 21, 0, &bgLoad->screenData, heapId);
    }
}


/* Frees the screen and cell resources and the two tile regions. */
void WIFICLUB_FreeBgResources(WifiClubBgLoad *bgLoad)
{
    if (bgLoad->screenHandle != 0) {
        func_020307B0(bgLoad->screenHandle);
        bgLoad->screenHandle = 0;
    }
    if (bgLoad->cellHandle != 0) {
        func_020307B0(bgLoad->cellHandle);
        bgLoad->cellHandle = 0;
    }
    BG_SYS_DeleteHalf(1, (u16)bgLoad->mainRegion, (u16)(bgLoad->mainRegion >> 16));
    BG_SYS_DeleteHalf(6, (u16)bgLoad->subRegion, (u16)(bgLoad->subRegion >> 16));
}


/* Writes a 2x2 tile block of the screen resource to the map of a layer. */
void WIFICLUB_DrawTileBlock(WifiClubBgLoad *bgLoad, int layer, u8 x, u8 y, unsigned int tileIndex, int unused)
{
    int row;
    unsigned int stride;
    u16 *tiles;
    int i, j;
    int paletteIndex;
    tiles = (u16 *)(*(char **)&bgLoad->screenData + 0xC);
    paletteIndex = WIFICLUB_GetIconPalette(layer);
    row = (tileIndex >> 4) * 2;
    stride = (unsigned int)**(u16 **)&bgLoad->screenData >> 3;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02042FB0(layer, j + x, i + y, (paletteIndex << 12) + (tiles + (tileIndex & 0xF) * 2)[(row + i) * stride + j]);
        }
    }
    func_02041B6C((u8)layer);
}


/* Maps a visitor phase and side to the icon tile block (15 is blank). */
int WIFICLUB_GetPhaseIconTile(unsigned int phase, int side)
{
    int tileIndex = 15;
    switch (phase) {
    case 4:
        if (side == 2) tileIndex = 4;
        else tileIndex = 3;
        break;
    case 5:
        if (side == 2) tileIndex = 6;
        else tileIndex = 5;
        break;
    case 6:
        if (side == 2) tileIndex = 10;
        else tileIndex = 9;
        break;
    case 2: tileIndex = 2; break;
    case 0: tileIndex = 15; break;
    case 3: tileIndex = 1; break;
    default:
        if (WIFICLUB_IsBusyPhase(phase) != 0) {
            if (side == 2) tileIndex = 8;
            else tileIndex = 7;
        } else if (phase >= 15) {
            tileIndex = 14;
        }
        break;
    }
    return tileIndex;
}


/* Draws the icon of a visitor phase. */
void WIFICLUB_DrawPhaseIcon(WifiClubBgLoad *bgLoad, int layer, u8 x, u8 y, int side, unsigned int phase, int tileBase)
{
    int tileIndex;
    tileIndex = WIFICLUB_GetPhaseIconTile(phase, side);
    WIFICLUB_DrawTileBlock(bgLoad, layer, x, y, tileIndex + tileBase, 0);
}


/* Returns the palette index of the icon blocks. */
int WIFICLUB_GetIconPalette(int layer)
{
    return 8;
}


/* Optionally fades in, refreshes the own seat status and returns the idle state. */
int WIFICLUB_BeginIdle(WifiClubWork *work, int fadeIn)
{
    if (fadeIn != 0)
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x21);
    WIFICLUB_SetStatusSeatFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_SetStatusModeFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_DisableVoiceChat();
    return 9;
}


/* Empty hook. */
void WIFICLUB_ExitHook(WifiClubWork *work)
{
}


/* Shows the planes, loads the background resources and creates the text buffers. */
void WIFICLUB_InitPlanesAndText(WifiClubWork *work, int archive)
{
    u32 k = 0xF;
    BG_SYS_SetMainPlaneVisible(0xF, 1);
    BG_SYS_SetSubPlaneVisible(0xD, 1);
    WIFICLUB_LoadBgResources((&work->bgLoad), archive, 0x21);
    func_02049B40(0x17, 5, 0, k << 5, 0x20, 0x21);
    work->menuFrameBase = (u32)BMP_MENUWORK_LoadFrameGfx((void *)2, 0xE, 0, 0x21);
    work->windowFrameBase = (u32)BMP_MENUWORK_LoadFrameGfx((void *)2, 0xE, 0, 0x21);
    work->textBufferC = BMP_MENUWORK_LoadFrameGfx((void *)1, 0xE, 0, 0x21);
}


/* Empty task hook. */
void WIFICLUB_TaskHook(void *task)
{
}


/* Starts the sprite system with one unit and one renderer. */
void WIFICLUB_InitSprites(WifiClubWork *work, void *archive)
{
    CLACT_InitSystem((const struct ClactInitParam *)d_021C3740, (u32)d_021C3AA0, 0x21);
    work->clactUnit = CLACT_CreateUnit(0x64, 0, 0x21);
    work->clactRenderer = CLACT_CreateRenderer(d_021C375C, 2, 0x21);
    CLACT_SetUnitRenderer(work->clactUnit, work->clactRenderer);
}


/*
 * Chooses the first state of the visit from the friend match flag and the connection,
 * and starts the club music.
 */
int WIFICLUB_StateEnterClub(WifiClubWork *work, int state)
{
    if (work->session->isFriendMatch) {
        WIFICLUB_InitBgmVolume(work, 4);
        func_02009B80(work->friendList, DWC_RAP_GetTargetFriendIndex());
        if ((unsigned)(work->connectionMode - 3) <= 1 && !DWC_RAP_IsDisconnected()) {
            DWC_RAP_StopVchat();
            WIFICLUB_ResetClubScreen(work);
            work->selectedPlusOne = work->session->visitedSeat;
            WIFICLUB_SetOwnStatusAndPublish(work, 4, 3);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 0xa);
            work->state = WIFICLUB_STATE_WAIT_SYNC_AND_CONTINUE;
        } else {
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x12, 0xa);
            work->state = WIFICLUB_STATE_LEAVE_SYNC_WAIT;
        }
    } else {
        work->state = WIFICLUB_STATE_HANDLE_NET_ERROR;
        WIFICLUB_InitBgmVolume(work, 1);
    }
    if (GFL_USE_GetTargetBgmNo() != 0x424) GFL_USE_CancelChangeAndPlayBgm(0x424, 0xffff);
    return state;
}


/* Resets the layer scroll values and goes to the intro state. */
int WIFICLUB_StateResetBgScroll(WifiClubWork *work, int state)
{
    sub_0204047C(0, 3);
    sub_0204047C(1, 1);
    sub_0204047C(3, 1);
    sub_0204047C(2, 0);
    work->state = WIFICLUB_STATE_WATCH_LOGIN;
    return state;
}


/* Hands the own status to the Wi-Fi layer. */
void WIFICLUB_PublishOwnStatus(WifiClubWork *work)
{
    DWC_RAP_SetOwnStatus(work->localStatus, 0x20);
}


/* Fills the own visitor status from the trainer profile and publishes it. */
void WIFICLUB_BuildOwnStatus(WifiClubWork *work, int kind, int value)
{
    void *profile;
    u8 genderValue;
    profile = GAME_DATA_GetMyStatus(work->gameData);
    work->localStatus->iconKind = 0x15;
    work->localStatus->visitorKind = 2;
    genderValue = (int)func_02008550(profile);
    work->localStatus->gender = genderValue;
    work->localStatus->avatarStyle = func_02008554(profile);
    WIFICLUB_SetOwnStatusKindPhase(work, kind, value);
    work->localStatus->colorA = func_0200856C(profile);
    work->localStatus->colorB = func_02008570(profile);
    WIFICLUB_SetStatusSeatFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_SetStatusModeFlag(work->localStatus, work->session->ownSeat);
    work->localStatus->idB = func_02008530(profile);
    work->localStatus->idA = func_0200853C(profile);
    WIFICLUB_PublishOwnStatus(work);
}


/* Rebuilds the list of visitors that are shown; returns how many. */
int WIFICLUB_RefreshVisibleList(WifiClubWork *work)
{
    int count = 0;
    int i;
    unsigned kind;
    for (i = 0; i < 32; i++) {
        work->visibleList[i] = 0;
        if (work->mapIndexPlusOne > i && WIFICLUB_GetFriendConnectionStatus(i)) {
            kind = WIFICLUB_GetStatusKind(work, WIFICLUB_GetFriendStatus(i));
            if (kind != 0 && kind < 6) {
                work->visibleList[count] = i + 1;
                count++;
            } else if (WIFICLUB_GetSlotState(work, i + 1)) {
                WIFICLUB_ClearSlotState(work, i + 1);
            }
        }
    }
    return count;
}


/* Updates the actors of the visitors whose status changed; returns how many changed. */
int WIFICLUB_SyncActorsWithPeers(WifiClubWork *work)
{
    int count = 0;
    int i;
    WifiClubPlayerStatus *peer;
    void *actor;
    u8 kind, phase;
    int wasActive, isActive;
    for (i = 0; i < 32; i++) {
        peer = WIFICLUB_GetFriendStatus(i);
        kind = (u8)WIFICLUB_GetStatusKind(work, peer);
        phase = (u8)WIFICLUB_GetStatusPhase(work, peer);
        if (WIFICLUB_GetFriendConnectionStatus(i) == 0) kind = 0;
        if (kind != work->shownActorState[i] ||
            phase != work->shownActorFlags[i] ||
            work->shownActorExtra[i] != WIFICLUB_GetStatusSeatFlag(peer)) {
            actor = WIFICLUB_FindPeerActor(work, i + 1);
            if (actor != 0) {
                wasActive = WIFICLUB_IsKindActive(work->shownActorState[i]);
                isActive = WIFICLUB_IsKindActive(kind);
                if (wasActive == 1 && isActive == 0) WIFICLUBACTOR_SetActorMode((&work->actorSys), actor, 0);
                else if (wasActive == 0 && isActive == 1) WIFICLUBACTOR_SetActorMode((&work->actorSys), actor, 1);
                func_02009918(work->friendList, i, 8, peer->avatarStyle);
                func_02009918(work->friendList, i, 9, peer->gender);
                func_02009918(work->friendList, i, 1, peer->idA);
                func_02009918(work->friendList, i, 0, peer->idB);
            }
            work->shownActorState[i] = kind;
            work->shownActorFlags[i] = phase;
            work->shownActorExtra[i] = WIFICLUB_GetStatusSeatFlag(peer);
            count++;
        }
    }
    return count;
}


/* Empty error hook. */
void WIFICLUB_OnFatalError(WifiClubWork *work)
{
}


/* Waits for the intro delay, then on A or B shows the first message. */
int WIFICLUB_StateWaitIntroMessage(WifiClubWork *work, int state)
{
    int n = work->counter;
    if (n > 0) {
        work->counter = n - 1;
        return state;
    }
    if (KEY_GetTrg() & 3) {
        work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
        WIFICLUB_ShowStreamedMessage(work, 0x37, 0);
        work->state = WIFICLUB_STATE_OPEN_EXIT_PROMPT;
    }
    return state;
}


/* Opens the exit prompt after the message ended. */
int WIFICLUB_StateOpenExitPrompt(WifiClubWork *work, int state)
{
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_EXIT_PROMPT;
    }

    return state;
}


/* Polls the exit prompt: leave the club or go back. */
int WIFICLUB_StatePollExitPrompt(WifiClubWork *work, int state)
{
    int promptAnswer;
    int noFlag;
    promptAnswer = WIFICLUB_PollYesNoMenu(work);
    if (promptAnswer == -1) return state;
    if (promptAnswer == 0) {
        GFL_NET_Exit(0);
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        work->state = WIFICLUB_STATE_RESTART_MATCH;
    } else {
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        noFlag = 0;
        GFL_NET_Exit(0);
        work->sceneKind = noFlag;
        work->state = WIFICLUB_STATE_WIFICLUB_RESOLVE_NET_RUN_STATE;
    }
    WIFICLUB_ClearTalkWindow(work);
    return state;
}


/* When the net layer is idle, rebuilds the screen and restarts the match. */
int WIFICLUB_StateRestartMatch(WifiClubWork *work, int state)
{
    void *archive;
    if (GFL_NET_IsIdle() == 0) {
        if (WIFICLUBACTOR_IsReady((&work->actorSys)) == 1) {
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x21);
            WIFICLUB_ClearPeerActors(work);
            CLACT_FlushOamIfPending();
        }
        if (WIFICLUB_IsSlotPanelOpen(work) == 1) WIFICLUB_CloseSlotPanel(work);
        work->headerWin = WIFICLUB_DeleteWindow(work->headerWin);
        BG_SYS_FreeSlot(3);
        archive = func_020490F4(0x21, 0x21);
        WIFICLUB_InitPlanesAndText(work, (int)archive);
        ARC_TOOL_DeleteHandle(archive);
        work->ready = 1;
        if (work->subMenuWork != 0) {
            BMP_WIN_Delete(work->partyWin);
            BMP_MENULIST_Delete(work->subMenuList, 0, 0);
            work->subMenuList = 0;
            BMP_MENUWORK_Delete(work->subMenuWork);
            work->subMenuWork = 0;
        }
        MI_CpuFill8(work->visibleList, 0, 0x20);
        MI_CpuFill8(work->pendingList, 0, 0x20);
        MI_CpuFill8(work->shownActorState, 0, 0x20);
        MI_CpuFill8(work->shownActorFlags, 0, 0x20);
        MI_CpuFill8(work->shownActorExtra, 0, 0x20);
        WIFICLUB_DrawHeaderWindow(work);
        WIFICLUB_StartNetSession(work, 0);
        GFL_NET_STATE_WifiStartMatch();
        WIFICLUB_ShowStreamedMessage(work, 0x17, 1);
        work->state = WIFICLUB_STATE_RESET_BG_SCROLL;
    }
    return state;
}


/*
 * Watches the login: handles changed user data and enters the club when the login is
 * done.
 */
int WIFICLUB_StateWatchLogin(WifiClubWork *work, int state)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return state;
    if (DWC_RAP_IsUserDataChanged()) {
        work->state = WIFICLUB_STATE_WATCH_LOGIN_AND_SAVE;
        WIFICLUB_ShowStreamedMessage(work, 0x1e, 1);
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (work->busyFlag) {
            work->state = WIFICLUB_STATE_SHOW_SAVE_NOTICE;
        } else {
            WIFICLUB_BuildOwnStatus(work, 1, 2);
            WIFICLUB_RefreshVisibleList(work);
            work->state = WIFICLUB_BeginIdle(work, 0);
        }
    } else {
        if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) WIFICLUB_OnFatalError(work);
    }
    return state;
}


/* Like WIFICLUB_StateWatchLogin, but starts the save when the user data changed. */
int WIFICLUB_StateWatchLoginAndSave(WifiClubWork *work, int state)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return state;
    if (DWC_RAP_IsUserDataChanged()) {
        GAME_DATA_SaveStart((int)(work->gameData));
        work->state = WIFICLUB_STATE_WAIT_SAVE;
        return state;
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (work->busyFlag) {
            work->state = WIFICLUB_STATE_SHOW_SAVE_NOTICE;
        } else {
            WIFICLUB_BuildOwnStatus(work, 1, 2);
            WIFICLUB_RefreshVisibleList(work);
            work->state = WIFICLUB_BeginIdle(work, 0);
        }
    } else {
        if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) WIFICLUB_OnFatalError(work);
    }
    return state;
}


/* Runs the save, then continues with the login check. */
int WIFICLUB_StateWaitSave(WifiClubWork *work, int state)
{
    int saveResult;
    if (DWC_RAP_IsUserDataChanged()) {
        saveResult = GAME_DATA_SaveMain(work->gameData);
        switch (saveResult) {
        default:
            DWC_RAP_ClearUserDataChanged(saveResult);
            break;
        case 0:
        case 1:
            return state;
        }
    }
    if (GFL_NET_STATE_IsWifiLoginState()) {
        if (work->busyFlag != 0) {
            work->state = WIFICLUB_STATE_SHOW_SAVE_NOTICE;
        } else {
            WIFICLUB_BuildOwnStatus(work, 1, 2);
            WIFICLUB_RefreshVisibleList(work);
            work->state = WIFICLUB_BeginIdle(work, 0);
        }
    } else if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) {
        WIFICLUB_OnFatalError(work);
    }
    return state;
}


/* Waits for the delay, frees the regulation text, then follows the connection state. */
int WIFICLUB_StateWatchConnection(WifiClubWork *work, int state)
{
    if (work->counter > 0) {
        work->counter -= 1;
        return state;
    }
    if (work->regulationText) {
        POKE_REGULATION_DeleteText(work->regulationText);
        work->regulationText = 0;
    }
    if (GFL_NET_STATE_IsFatalError() || GFL_NET_STATE_GetWifiState() == 3) {
        WIFICLUB_OnFatalError(work);
    } else {
        if (GFL_NET_STATE_IsWifiLoginOrConnected()) {
            if (WIFICLUBACTOR_IsReady((&work->actorSys)) == 1) WIFICLUB_ClearPeerActors(work);
            work->state = WIFICLUB_BeginIdle(work, 0);
            goto done;
        } else {
            if (GFL_NET_STATE_GetWifiState() < 4 && !GFL_NET_STATE_IsWifiDisconnectFinal() && GFL_NET_IsConnectMember(0xff)) goto done;
            GFL_NET_STATE_WifiDisconnect(1);
            if (WIFICLUBACTOR_IsReady((&work->actorSys)) == 1) WIFICLUB_ClearPeerActors(work);
        }
        work->state = WIFICLUB_BeginIdle(work, 0);
    }
done:
    return state;
}


/* Closes the prompt and shows the save notice. */
int WIFICLUB_StateShowSaveNotice(WifiClubWork *work, int state)
{
    WIFICLUB_ClearTalkWindow(work);
    if (APP_ENV_IsRunOnTwl()) {
        WIFICLUB_ShowNoticeWindow(work, 44);
    } else {
        WIFICLUB_ShowNoticeWindow(work, 19);
    }
    work->state = WIFICLUB_STATE_WAIT_SAVE_NOTICE;
    work->busyFlag = 0;
    return state;
}


/* On A or B, enters the club or shows the lock message. */
int WIFICLUB_StateWaitSaveNotice(WifiClubWork *work, int state)
{
    if (KEY_GetTrg() & 3) {
        if (!func_02009A34(work->friendList)) {
            WIFICLUB_ShowStreamedMessage(work, 0x1a, 1);
            work->state = WIFICLUB_STATE_EXIT_NETWORK;
            work->counter = 1;
        } else {
            WIFICLUB_BuildOwnStatus(work, 1, 2);
            WIFICLUB_RefreshVisibleList(work);
            work->state = WIFICLUB_BeginIdle(work, 0);
            work->noticeWin = WIFICLUB_DeleteWindow(work->noticeWin);
        }
    }
    return state;
}


/* Creates the two title windows and clears them. */
void WIFICLUB_CreateTitleWindows(WifiClubWork *work)
{
    if (work->playerInfoWin) BMP_WIN_Delete(work->playerInfoWin);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x21);
    work->headerWin = WIFICLUB_DeleteWindow(work->headerWin);
    work->playerInfoWin = (void *)BMP_WIN_Create(3, 1, 1, 0x1c, 2, 0xf, 1);
    work->headerWin = (void *)BMP_WIN_Create(2, 1, 1, 0x1c, 2, 0xf, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->playerInfoWin), 0xff);
    BMP_WIN_TransferChars(work->playerInfoWin);
    BMP_Clear(BMP_WIN_GetBmp(work->headerWin), 0xff);
    BMP_WIN_TransferChars(work->headerWin);
    BMP_MENUWORK_DrawWindow(work->headerWin, 1, (u16)(work->windowFrameBase), 0xe);
}


/* Callback: true when the requester matches the status of the peer slot. */
BOOL WIFICLUB_IsFriendRequestFromPeer(void *friendIndex, WifiClubFriendRequest *request)
{
    WifiClubPlayerStatus *x = request->status;
    WifiClubPlayerStatus *y = WIFICLUB_GetFriendStatus((int)friendIndex);

    WIFICLUB_GetStatusActionState(x);
    WIFICLUB_GetStatusActionState(y);

    if (WIFICLUB_GetStatusActionArg(x) == WIFICLUB_GetStatusActionArg(y)) {
        return 1;
    }

    return 0;
}


/* On a net error or login, goes to the error state. */
int WIFICLUB_StateHandleNetError(WifiClubWork *work, int state)
{
    if (!GFL_NET_STATE_IsFatalError() && !GFL_NET_STATE_IsWifiLoginOrConnected()) return state;
    work->state = WIFICLUB_STATE_RETURN_TO_CLUB;
    return state;
}


/* Rebuilds windows, actor system and lists for a fresh club visit. */
void WIFICLUB_ResetClubScreen(WifiClubWork *work)
{
    void *archive;
    int kind, gender;
    DWC_RAP_SetAcceptFriendCallback((void (*)(void))WIFICLUB_IsFriendRequestFromPeer);
    archive = func_020490F4(WIFICLUB_HEAP_ID, WIFICLUB_HEAP_ID);
    WIFICLUB_ResetOwnSeatStatus(work);
    WIFICLUB_ClosePartnerMenu(work);
    MI_CpuFill8(work->pendingList, 0, WIFICLUB_SLOT_COUNT);
    if (work->subMenuWork) {
        BMP_WIN_Delete(work->partyWin);
        BMP_MENULIST_Delete(work->subMenuList, 0, 0);
        work->subMenuList = 0;
        BMP_MENUWORK_Delete(work->subMenuWork);
        work->subMenuWork = 0;
    }
    if (!WIFICLUBACTOR_IsReady((&work->actorSys))) {
        gender = func_02008550((const struct PlayerProfile *)GAME_DATA_GetMyStatus(work->gameData));
        kind = 16;
        if (gender) kind = 17;
        work->mapIndexPlusOne = func_02009A54(work->friendList);
        WIFICLUBACTOR_Init((&work->actorSys), WIFICLUB_HEAP_ID, (u32)archive, kind, work->mapIndexPlusOne, WIFICLUB_HEAP_ID,
                      (u32)work->clactUnit, (u32)work->clactRenderer);
        WIFICLUB_AddPeerActor(work, WIFICLUBACTOR_SpawnCursorActor((&work->actorSys), kind));
    }
    if (!WIFICLUB_IsSlotPanelOpen(work)) WIFICLUB_OpenSlotPanel(work, (int)archive, WIFICLUB_HEAP_ID);
    WIFICLUB_CopyZeroToDeviceAddr(work->localStatus);
    work->sceneReady = 0;
    WIFICLUB_OpenPanelOrRedrawPage(work, WIFICLUB_HEAP_ID);
    WIFICLUB_ClearTalkWindow(work);
    WIFICLUB_RefreshVisibleList(work);
    WIFICLUB_CreateTitleWindows(work);
    WIFICLUB_StartNetSession(work, 0);
    work->partnerIndex = -1;
    ARC_TOOL_DeleteHandle(archive);
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, WIFICLUB_HEAP_ID);
}


/* Resets the screen and the net options, then goes to the club idle state. */
int WIFICLUB_StateReturnToClub(WifiClubWork *work, int state)
{
    WIFICLUB_ResetClubScreen(work);
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    WIFICLUB_ChangeNetMode(work, 1, 2);
    work->state = WIFICLUB_STATE_LOBBY_MAIN;
    WIFICLUB_DisableTouchBar(work);
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    return state;
}












/*
 * Returns TRUE when the Wi-Fi state is 1 (connected).
 */
BOOL WIFICLUB_IsNetStateConnected(WifiClubWork *work)
{
    if (GFL_NET_STATE_GetWifiState() == 1) {
        return 1;
    }

    return 0;
}



/*
 * Returns TRUE when a new client has joined (its association id is not -1).
 */
BOOL WIFICLUB_HasNewClientAid(WifiClubWork *work)
{
    if (DWC_RAP_GetNewClientAid() != -1) {
        return 1;
    }

    return 0;
}



/*
 * Returns TRUE when the Wi-Fi state is 3, 4 or 5 (the link is closing).
 * A switch with case labels 3, 4 and 5 gives the original branch layout.
 */
BOOL WIFICLUB_IsNetStateDisconnecting(WifiClubWork *work)
{
    int v = GFL_NET_STATE_GetWifiState();

    switch (v) {
    case 3:
    case 4:
    case 5:
        return 1;
    }
    return 0;
}



/*
 * Compares the visible list with the pending list of member ids.
 * Spawns an actor for each new member and removes the actor of each missing member.
 * Plays a sound when the visitors changed. Returns the result of the list refresh.
 * The last two ifs repeat the same call on purpose: the compiler needs both branches.
 */
int WIFICLUB_SyncPresenceLists(WifiClubWork *work)
{
    int refreshResult=WIFICLUB_RefreshVisibleList(work);
    int removed=0;
    int added=0;
    int i,j,found;
    void *actor;
    WifiClubPlayerStatus *status;
    if(GF_STANDARD_CompareBytes((const u8 *)work->visibleList,(const u8 *)work->pendingList,32)){
        for(i=0;i<32;i++){
            found=0;
            for(j=0;j<32;j++){
                if(work->visibleList[j]==work->pendingList[i]){found=1;break;}
            }
            if(!found && work->pendingList[i]){
                actor=WIFICLUB_FindPeerActor(work,work->pendingList[i]);
                if(actor){
                    WIFICLUBACTOR_StartDespawn(&work->actorSys,actor);
                    WIFICLUB_RemovePeerActor(work,actor);
                    WIFICLUB_ClearSlotState(work,work->pendingList[i]);
                    WIFICLUB_ClosePanelIfSlotSelected(work,work->pendingList[i],33);
                    added=1;
                }else{
                    WIFICLUB_ClearSlotState(work,work->pendingList[i]);
                }
            }
            found=0;
            for(j=0;j<32;j++){
                if(work->visibleList[i]==work->pendingList[j]){found=1;break;}
            }
            if(!found && work->visibleList[i]){
                status=WIFICLUB_GetFriendStatus(work->visibleList[i]-1);
                actor=WIFICLUBACTOR_SpawnSlotActor(&work->actorSys,status->avatarStyle,work->visibleList[i]);
                if(actor){
                    WIFICLUB_SetSlotState(work,work->visibleList[i],2);
                    WIFICLUB_AddPeerActor(work,actor);
                    removed=1;
                }else{
                    WIFICLUB_SetSlotState(work,work->visibleList[i],1);
                }
            }
        }
        MI_CpuCopy8(work->visibleList,work->pendingList,32);
        if(removed || added)WIFICLUB_RequestPanelRedraw(work);
        if(removed==1){GFL_USE_PlaySeDefaultVolume(0x676);}
        else if(added==1){GFL_USE_PlaySeDefaultVolume(0x676);}
    }
    return refreshResult;
}



/*
 * Removes the actors of visible members that have no peer actor any more.
 * Plays a sound when it removed one.
 */
void WIFICLUB_DropActorsOfMissingPeers(WifiClubWork *work)
{
    int changed = 0;
    int i;
    void *actor;
    WifiClubPlayerStatus *status;
    for (i = 0; i < 32; i++) {
        if (work->visibleList[i] && !WIFICLUB_FindPeerActor(work, work->visibleList[i])) {
            status = WIFICLUB_GetFriendStatus(work->visibleList[i] - 1);
            actor = WIFICLUBACTOR_SpawnSlotActor(&work->actorSys, status->avatarStyle, work->visibleList[i]);
            if (actor) {
                WIFICLUB_SetSlotState(work, work->visibleList[i], 2);
                WIFICLUB_AddPeerActor(work, actor);
                work->shownActorState[i] = 0;
                work->shownActorFlags[i] = 0;
                work->shownActorExtra[i] = 0;
                changed = 1;
            }
        }
    }
    if (changed == 1) GFL_USE_PlaySeDefaultVolume(0x676);
}



/*
 * Runs when the peer actors are in sync.
 * Opens the partner panel for the selector, or marks the touch panel dirty.
 */
void WIFICLUB_RequestSelectionRefresh(WifiClubWork *work, int selector)
{
    if (WIFICLUB_SyncActorsWithPeers(work) <= 0) {
        return;
    }

    if (work->touchPhase != 0) {
        WIFICLUB_OpenPartnerPanel(work, selector);
        return;
    }

    work->touchDirty = 1;
    WIFICLUB_RedrawSlotPanels(work);
}



/*
 * Per-frame update of the visitor actors: syncs the member lists,
 * refreshes the selection, then drops stale actors.
 */
void WIFICLUB_UpdatePeerActors(WifiClubWork *work, int selector)
{
    WIFICLUB_SyncPresenceLists(work);
    WIFICLUB_RequestSelectionRefresh(work, selector);
    WIFICLUB_DropActorsOfMissingPeers(work);
}



/*
 * Resumes the sprite of every peer actor slot that holds an actor.
 * The slot value is the second argument of the call, so the compiler loads it into r1.
 */
void WIFICLUB_ReleaseSlotActors(WifiClubWork *work)
{
    int i;

    for (i = 0; i < 0x21; i++) {
        void *peerActor = work->peerSlots[i];

        if (peerActor != 0) {
            WIFICLUBACTOR_ResumeActorSprite((int)&work->actorSys, peerActor);
        }
    }
}



/*
 * State handler: the club room while no partner is chosen.
 * Handles errors and timeouts, the cursor and key input, member status changes,
 * a joining client and a lost connection, then acts on the actor update result.
 * The next state is written to work->state. Returns procState unchanged.
 */
int WIFICLUB_StateLobbyMain(WifiClubWork *work, int procState)
{
    u32 action = 0, statusKind;
    int index, i, pickedMemberId, changeCount;
    void *actor;
    work->seatReply = 0;
    if (WIPE_SYS_EndCheck() == 0) return procState;
    if (GFL_NET_STATE_IsFatalError()) { WIFICLUB_OnFatalError(work); return procState; }
    if (work->partnerIndex != -1) {
        if (++work->waitFrames > 0xe10) { GFL_NET_STATE_SetError(0, 0, 0, 0x3f1); return procState; }
    }
    if (GFL_NET_STATE_GetWifiState() == 4) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_LEAVE_CANCEL;
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        return procState;
    }
    WIFICLUB_UpdatePeerActors(work, 33);
    WIFICLUB_RedrawSlotPanelIfPending(work);
    WIFICLUBACTOR_RestartBlink(&work->actorSys);
    if (WIFICLUBACTOR_GetMode(&work->actorSys) == 0) {
        if (DWC_RAP_GetNewClientAid() == -1 && (KEY_GetTrg() & 0x400)) {
            if (WIFICLUB_ToggleOwnSeat(work)) WIFICLUB_ShowMessage(work, 57, 0);
            else WIFICLUB_ShowMessage(work, 58, 0);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            WIFICLUB_DrawPlayerInfoWindow(work);
            work->state = WIFICLUB_STATE_WAIT_KEY_RETURN_TO_LOBBY;
            WIFICLUB_ClosePanelIfTouchActive(work, 33);
            return procState;
        }
        pickedMemberId = WIFICLUB_UpdateSlotPanel(work, 33);
        actor = WIFICLUB_FindPeerActor(work, pickedMemberId);
        if (pickedMemberId != 0) {
            if (actor != 0) WIFICLUBACTOR_ShowMarkerAtActor(&work->actorSys, actor);
            else { WIFICLUB_ReleaseSlotActors(work); WIFICLUBACTOR_HideMarker(&work->actorSys); }
        } else { WIFICLUB_ReleaseSlotActors(work); WIFICLUBACTOR_HideMarker(&work->actorSys); }
    }
    for (i = 0; i < 32; i++) {
        index = func_02005728(32);
        if (WIFICLUB_IsPeerAddrOfStatus(work->localStatus, WIFICLUB_GetFriendStatus(index)) != 0) {
            changeCount = WIFICLUB_GetStatusChangeCount(WIFICLUB_GetFriendStatus(index));
            if (changeCount != work->session->memberChangeCount[index]) {
                WIFICLUB_GetStatusKind(work, WIFICLUB_GetFriendStatus(index));
                WIFICLUB_GetStatusPhase(work, WIFICLUB_GetFriendStatus(index));
                work->selectedPlusOne = index + 1;
                GFL_USE_PlaySeInSlot((void *)0x806, 0);
                work->state = WIFICLUB_STATE_CHECK_PEER_SELECTION;
                return procState;
            }
        }
    }
    if (WIFICLUB_IsNetStateConnected(work) && work->partnerIndex != -1) {
        GFL_USE_PlaySeInSlot((void *)0x806, 0);
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
        work->state = WIFICLUB_STATE_ON_PARTNER_CONNECTED;
        return procState;
    }
    if (work->partnerIndex == -1 && DWC_RAP_GetNewClientAid() != -1) {
        index = DWC_RAP_GetNewClientAid();
        work->partnerIndex = index;
        WIFICLUB_SetPartnerNameWord(work, index);
        if (!work->sceneReady) WIFICLUB_ShowStreamedMessage(work, 46, 0);
        work->waitFrames = 0;
    } else if (work->partnerIndex != -1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        WIFICLUB_SetStatusModeFlag(work->localStatus, WIFICLUB_GetStatusSeatFlag((work->localStatus)));
        WIFICLUB_SetPartnerNameWord(work, work->partnerIndex);
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        GFL_NET_STATE_WifiDisconnect(1);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    if (WIFICLUB_IsNetStateDisconnecting(work) && work->partnerIndex != -1) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetCanceledPeerIndex());
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    if (DWC_RAP_GetVchatEnabled() == 1 && DWC_RAP_GetNewClientAid() == -1) {
        DWC_RAP_SetVchatEnabled(0);
        WIFICLUB_SetStatusModeFlag(work->localStatus, WIFICLUB_GetStatusSeatFlag((work->localStatus)));
    }
    statusKind = WIFICLUB_GetStatusKind(work, work->localStatus);
    if (work->partnerIndex == -1) {
        if ((KEY_GetTrg() & 2) && WIFICLUB_IsKindActive(statusKind)) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            work->state = WIFICLUB_STATE_START_PROMPT;
            WIFICLUB_ClosePartnerPanel(work, 33);
            return procState;
        }
        action = WIFICLUBACTOR_Update(&work->actorSys);
        WIFICLUBACTOR_TickBlink(&work->actorSys);
    }
    switch (action) {
    case 0: return procState;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (WIFICLUB_IsKindActive(statusKind)) work->state = WIFICLUB_STATE_START_PROMPT;
        else {
            work->sceneKind = 0;
            work->state = WIFICLUB_STATE_OPEN_QUIT_YES_NO;
            WIFICLUB_ShowStreamedMessage(work, 25, 1);
        }
        WIFICLUB_ClosePanelIfTouchActive(work, 33);
        return procState;
    case 3:
        if (statusKind == 1) {
            work->connectionMode = 1;
            GFL_USE_PlaySeDefaultVolume(0x54c);
            WIFICLUBACTOR_StartBlinkOnTile(&work->actorSys);
            work->state = WIFICLUB_STATE_OPEN_PARTNER_MENU;
            WIFICLUB_ClosePanelIfTouchActive(work, 33);
            work->sceneReady = 0;
            return procState;
        }
        break;
    case 2:
        if (statusKind == 1) {
            index = WIFICLUBACTOR_GetPickResult(&work->actorSys);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            MI_CpuCopy8(WIFICLUB_GetFriendStatus(index - 1), &work->ownStatus, 32);
            work->state = WIFICLUB_STATE_SHOW_PARTNER_STATUS_MESSAGE;
            WIFICLUB_ClosePanelIfTouchActive(work, 33);
            return procState;
        }
        break;
    }
    return procState;
}



/*
 * State handler: the club room while a partner is connected or joining.
 * Like the lobby handler, but without the error and member status checks.
 */
int WIFICLUB_StateLobbyConnected(WifiClubWork *work,int procState)
{
    unsigned action=0,statusKind;
    int index;
    if(work->partnerIndex!=-1){
        if(++work->waitFrames>0xe10){GFL_NET_STATE_SetError(0,0,0,0x3f1);return procState;}
    }
    WIFICLUB_UpdateTalkStream(work);
    work->seatReply=0;
    WIFICLUB_UpdatePeerActors(work,33);
    WIFICLUB_RedrawSlotPanelIfPending(work);
    WIFICLUBACTOR_RestartBlink(&work->actorSys);
    if(WIFICLUB_IsNetStateConnected(work) && work->partnerIndex!=-1){
        GFL_USE_PlaySeInSlot((void *)0x806,0);
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
        work->state=WIFICLUB_STATE_ON_PARTNER_CONNECTED;
        return procState;
    }
    if(WIFICLUB_IsNetStateDisconnecting(work) && work->partnerIndex!=-1){
        WIFICLUB_SetPartnerNameWord(work,DWC_RAP_GetCanceledPeerIndex());
        WIFICLUB_ShowStreamedMessage(work,15,0);
        work->state=WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    if(work->partnerIndex==-1 && DWC_RAP_GetNewClientAid()!=-1){
        index=DWC_RAP_GetNewClientAid();
        work->partnerIndex=index;
        WIFICLUB_SetPartnerNameWord(work,index);
        if(!work->sceneReady)WIFICLUB_ShowStreamedMessage(work,46,0);
        work->waitFrames=0;
    }else if(DWC_RAP_GetCanceledPeerIndex()!=-1){
        WIFICLUB_SetPartnerNameWord(work,DWC_RAP_GetCanceledPeerIndex());
        WIFICLUB_ShowStreamedMessage(work,15,0);
        work->state=WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    statusKind=WIFICLUB_GetStatusKind(work,work->localStatus);
    if(work->partnerIndex==-1){
        if((KEY_GetTrg()&2) && WIFICLUB_IsKindActive(statusKind)){
            GFL_USE_PlaySeDefaultVolume(0x54c);
            work->state=WIFICLUB_STATE_START_PROMPT;
            WIFICLUB_ClosePanelIfTouchActive(work,33);
            return procState;
        }
        action=WIFICLUBACTOR_Update(&work->actorSys);
        WIFICLUBACTOR_TickBlink(&work->actorSys);
    }
    switch(action){
    case 0:return procState;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if(WIFICLUB_IsKindActive(statusKind)){
            work->state=WIFICLUB_STATE_START_PROMPT;
        }else{
            work->sceneKind=0;
            work->state=WIFICLUB_STATE_OPEN_QUIT_YES_NO;
            WIFICLUB_ShowStreamedMessage(work,25,1);
        }
        WIFICLUB_ClosePanelIfTouchActive(work,33);
        return procState;
    case 3:
        if(statusKind==1){
            work->connectionMode=1;
            GFL_USE_PlaySeDefaultVolume(0x54c);
            WIFICLUBACTOR_StartBlinkOnTile(&work->actorSys);
            work->state=WIFICLUB_STATE_OPEN_PARTNER_MENU;
            WIFICLUB_ClosePanelIfTouchActive(work,33);
            return procState;
        }
        break;
    case 2:
        if(statusKind==1){
            index=WIFICLUBACTOR_GetPickResult(&work->actorSys);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            MI_CpuCopy8(WIFICLUB_GetFriendStatus(index-1),&work->ownStatus,32);
            work->state=WIFICLUB_STATE_SHOW_PARTNER_STATUS_MESSAGE;
            WIFICLUB_ClosePanelIfTouchActive(work,33);
            return procState;
        }
        break;
    }
    return procState;
}



/*
 * State handler: checks the member picked by the cursor.
 * Waits for the sound slot, then starts the request when the member is valid.
 * The member change count is stored with base + index + 0x24 arithmetic to avoid an indexed store.
 */
int WIFICLUB_StateCheckPeerSelection(WifiClubWork *work, int procState)
{
    int memberIndex = work->selectedPlusOne - 1;
    if (GFL_USE_IsSeSlotBusy(0)) return procState;
    work->session->memberChangeCount[memberIndex] = WIFICLUB_GetStatusChangeCount(WIFICLUB_GetFriendStatus(memberIndex));
    if (memberIndex >= 0 && memberIndex < 32 && WIFICLUB_AddNetCommandsAndCheckFriend(work, memberIndex)) {
        work->idleTimer = 0xe10;
        WIFICLUB_ChangeNetMode(work, 4, 3);
        WIFICLUB_SetOwnStatusAndPublish(work, 4, 3);
        WIFICLUB_ClosePartnerPanel(work, 0x21);
        WIFICLUB_SetPartnerNameWord(work, memberIndex);
        work->idleTimer = 0xe10;
        WIFICLUB_ShowMessage(work, 0x5e, 0);
        WIFICLUB_ResetTimeIcon(work);
        work->state = WIFICLUB_STATE_WAIT_JOIN_ANSWER;
        work->lastPicked = work->selectedPlusOne;
        return procState;
    }
    work->state = WIFICLUB_STATE_LOBBY_MAIN;
    return procState;
}



/*
 * State handler: waits for any key, then returns to the lobby.
 */
int WIFICLUB_StateWaitKeyReturnToLobby(WifiClubWork *work, int procState)
{
    if (KEY_GetTrg()) {
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        WIFICLUB_DisableTouchBar(work);
        WIFICLUB_ClearTalkWindow(work);
    }
    return procState;
}



/*
 * State handler: waits for the picked member to answer the request.
 * Times out, handles a lost member, and enters the room when connected.
 */
int WIFICLUB_StateWaitPeerReply(WifiClubWork *work, int procState)
{
    void *peerStatus;
    unsigned statusKind;
    peerStatus = WIFICLUB_GetFriendStatus(work->selectedPlusOne - 1);
    WIFICLUB_GetStatusSeatFlag(peerStatus);
    statusKind = WIFICLUB_GetStatusKind(work, peerStatus);
    work->idleTimer -= 1;
    if (work->idleTimer < 0) {
        work->state = WIFICLUB_STATE_LEAVE_LINK_TO_LOBBY;
    } else if (statusKind != 1 && statusKind != 2) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 0xd, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
    } else if (GFL_NET_STATE_GetWifiState() == 1) {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_CopyZeroToDeviceAddr(work->localStatus);
        work->sceneReady = 0;
        WIFICLUB_SetOwnStatusAndPublish(work, 4, 4);
        work->sceneResult = 0;
        work->state = WIFICLUB_STATE_SYNC_TIMING_START;
        WIFICLUB_StartBgmFade(work, 0);
        WIFICLUB_ShowMessage(work, 0x7b, 0);
    }
    return procState;
}



/*
 * State handler: shows the message for the target friend and goes to the next state.
 * The extent ends with two-byte alignment padding.
 */
int WIFICLUB_StateStartMessageDismiss(WifiClubWork *work, int procState)
{
    WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
    WIFICLUB_ShowStreamedMessage(work, 11, 0);
    WIFICLUB_SetOwnStatusAndPublish(work, 4, 4);
    work->state = WIFICLUB_STATE_WAIT_MESSAGE;
    return procState;
}



/*
 * State handler: waits for the message to end.
 * On a key press it cancels. Otherwise it starts the timing sync.
 */
int WIFICLUB_StateWaitMessage(WifiClubWork *work, int procState)
{
    if (GFL_NET_STATE_IsFatalError()) {
        WIFICLUB_OnFatalError(work);
        return procState;
    }
    if (DWC_RAP_GetTargetFriendIndex() < 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x10, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    if (WIFICLUB_UpdateTalkStream(work)) {
        if (KEY_GetTrg() & 3) {
            WIFICLUB_ClearTalkWindow(work);
            WIFICLUB_ShowMessage(work, 0x7b, 0);
            WIFICLUB_SetOwnStatusAndPublish(work, 4, 4);
            WIFICLUB_StartBgmFade(work, 0);
            work->sceneResult = 0;
            work->state = WIFICLUB_STATE_SYNC_TIMING_START;
        } else {
            WIFICLUB_StateSyncTimingStart(work, procState);
        }
    }
    return procState;
}



/*
 * State handler: starts the timing sync for the target friend.
 */
int WIFICLUB_StateSyncTimingStart(WifiClubWork *work, int procState)
{
    GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 19, 10);
    func_02009B80(work->friendList, DWC_RAP_GetTargetFriendIndex());
    work->state = WIFICLUB_STATE_VCHAT_INVITE;
    return procState;
}



/*
 * Draws the voice chat indicator tile block (a different tile when voice chat is active).
 */
void WIFICLUB_UpdateVchatIndicator(WifiClubWork *work)
{
    if (DWC_RAP_GetVchatState(work)) {
        WIFICLUB_DrawTileBlock(&work->bgLoad, 1, 2, 1, 0x3c, 0);
    } else {
        WIFICLUB_DrawTileBlock(&work->bgLoad, 1, 2, 1, 0x33, 0);
    }
}



/*
 * State handler: waits while the voice chat invite is pending.
 * A cancel key opens a message. A scene result ends the invite.
 */
int WIFICLUB_StateVchatInvite(WifiClubWork *work, int procState)
{
    void *targetStatus = WIFICLUB_GetFriendStatus(DWC_RAP_GetTargetFriendIndex());
    WIFICLUB_GetStatusKind(work, targetStatus);
    WIFICLUB_GetStatusPhase(work, targetStatus);
    WIFICLUB_UpdatePeerActors(work, 0x21);
    WIFICLUB_RedrawSlotPanelIfPending(work);
    if (KEY_GetTrg() & 2) {
        WIFICLUB_ShowStreamedMessage(work, 0x11, 0);
        work->state = WIFICLUB_STATE_VCHAT_ANSWER_WAIT;
    } else if (work->sceneResult) {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 0x10, 0);
        work->counter = 0x3c;
        work->state = WIFICLUB_STATE_LEAVE_DELAY;
    } else {
        WIFICLUB_UpdateVchatIndicator(work);
    }
    return procState;
}



/*
 * State handler: waits for the voice chat message to end,
 * then ends the invite or opens the yes/no menu.
 */
int WIFICLUB_StateVchatAnswerWait(WifiClubWork *work, int procState)
{
    WIFICLUB_UpdateVchatIndicator(work);
    if (WIFICLUB_UpdateTalkStream(work)) {
        if (work->sceneResult) {
            WIFICLUB_ClearTalkWindow(work);
            WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
            WIFICLUB_ShowStreamedMessage(work, 0x10, 0);
            work->counter = 0x3c;
            work->state = WIFICLUB_STATE_LEAVE_DELAY;
        } else {
            WIFICLUB_OpenYesNoMenu(work);
            work->state = WIFICLUB_STATE_VCHAT_YES_NO;
        }
    }
    return procState;
}



/*
 * State handler: polls the voice chat yes/no menu and picks the next state from the answer.
 */
int WIFICLUB_StateVchatYesNo(WifiClubWork *work, int procState)
{
    int answer;
    WIFICLUB_UpdateVchatIndicator(work);
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1) {
        if (work->sceneResult) {
            WIFICLUB_ClearTalkWindow(work);
            BMP_MENU_DeleteYesNo(work->yesNoMenu);
            work->yesNoMenu = 0;
            WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
            WIFICLUB_ShowStreamedMessage(work, 0x10, 0);
            work->counter = 0x3c;
            work->state = WIFICLUB_STATE_LEAVE_DELAY;
        }
    } else if (answer == 0) {
        work->state = WIFICLUB_STATE_SEND_VCHAT_READY;
    } else {
        WIFICLUB_ShowMessage(work, 0x7b, 0);
        work->state = WIFICLUB_STATE_SYNC_TIMING_START;
    }
    return procState;
}



/*
 * State handler: sends the voice chat ready message and starts the timing sync.
 */
int WIFICLUB_StateSendVchatReady(WifiClubWork *work, int procState)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa08, 0, 0)) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x12, 0xa);
        work->state = WIFICLUB_STATE_LEAVE_SYNC_WAIT;
    }
    return procState;
}



/*
 * State handler: waits until voice chat ends, then starts the timing sync.
 * The extent ends with two-byte alignment padding.
 */
int WIFICLUB_StateWaitVchatEnd(WifiClubWork *work, int procState)
{
    if (!DWC_RAP_IsVchatActive()) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 24, 10);
        work->state = WIFICLUB_STATE_WAIT_SYNC_AND_CONTINUE;
    }
    return procState;
}



/*
 * State handler: waits for the leave sync.
 * Parent and child seats stop voice chat and go to one state.
 * Other modes disable auto exit and start the next sync.
 */
int WIFICLUB_StateLeaveSyncWait(WifiClubWork *work, int procState)
{
    work->sceneResult = 0;
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 18, 10)
        || GFL_NET_HANDLE_GetNegotiationNum() != 2) {
        if ((unsigned)(work->connectionMode - 3) <= 1) {
            DWC_RAP_StopVchat();
            WIFICLUB_StartBgmFade(work, 127);
            WIFICLUB_ClearTalkWindow(work);
            WIFICLUB_SetOwnStatusAndPublish(work, 3, 3);
            work->state = WIFICLUB_STATE_WAIT_VCHAT_END;
        } else {
            WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
            GFL_NET_SetAutoExit(0);
            GFL_NET_SetLoginOption(0);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 21, 10);
            work->state = WIFICLUB_STATE_DISCONNECT_SYNC;
        }
    }
    return procState;
}



/*
 * State handler: waits for the timing sync, then disconnects and clears the partner.
 */
int WIFICLUB_StateDisconnectSync(WifiClubWork *work, int procState)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 21, 10)
        || GFL_NET_HANDLE_GetNegotiationNum() != 2) {
        GFL_NET_STATE_WifiDisconnect(1);
        work->partnerIndex = -1;
        work->counter = 20;
        WIFICLUB_ClearTalkWindow(work);
        work->state = WIFICLUB_STATE_WATCH_CONNECTION;
    }
    return procState;
}


/*
 * Waits for the talk window to finish, counts down, then starts the leave
 * timing sync and moves to the leave sync wait.
 */
int WIFICLUB_StateLeaveDelay(WifiClubWork *work, int procState)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    if (--work->counter < 0) {
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 18, 10);
        work->state = WIFICLUB_STATE_LEAVE_SYNC_WAIT;
    }
    return procState;
}


/*
 * Shows the error message and waits for a key press or a timeout. Then it
 * disconnects and goes back to the lobby (or to the retry wait if the actor
 * layer is not ready).
 */
int WIFICLUB_StateErrorMessageWait(WifiClubWork *work, int procState)
{
    if (GFL_NET_STATE_IsFatalError()) { WIFICLUB_OnFatalError(work); return procState; }
    if (WIFICLUB_GetStatusKind(work, work->localStatus) != 1) WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    if (!WIFICLUB_UpdateTalkStream(work)) { work->counter = 30; return procState; }
    --work->counter;
    if ((KEY_GetTrg() & 3) || !work->counter) {
        WIFICLUB_ClearTalkWindow(work);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_StartNetSession(work, 0);
        if (!WIFICLUBACTOR_IsReady(&work->actorSys)) {
            work->counter = 20;
            work->state = WIFICLUB_STATE_WATCH_CONNECTION;
        } else {
            WIFICLUB_ResetOwnSeatStatus(work);
            WIFICLUB_DrawPlayerInfoWindow(work);
            work->partnerIndex = -1;
            work->state = WIFICLUB_STATE_LOBBY_MAIN;
            WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, WIFICLUB_FindPeerActor(work, WIFICLUBACTOR_GetPickResult(&work->actorSys)));
            WIFICLUB_DisableTouchBar(work);
        }
    }
    return procState;
}


/*
 * Waits for the talk window, then for an A or B press. Then it disconnects
 * and moves to the retry wait.
 */
int WIFICLUB_StateDisconnectAckWait(WifiClubWork *work, int procState)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    if (KEY_GetTrg() & 3) {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        work->counter = 20;
        work->state = WIFICLUB_STATE_WATCH_CONNECTION;
    }
    return procState;
}


/*
 * Waits 240 frames, then disconnects. Goes back to the lobby, or to the idle
 * state if the actor layer is not ready.
 */
int WIFICLUB_StateLeaveTimeout(WifiClubWork *work, int procState)
{
    if (++work->counter <= 240) return procState;
    WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, WIFICLUB_FindPeerActor(work, WIFICLUBACTOR_GetPickResult(&work->actorSys)));
    WIFICLUB_ClearTalkWindow(work);
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    GFL_NET_STATE_WifiDisconnect(1);
    WIFICLUB_StartNetSession(work, 0);
    if (!WIFICLUBACTOR_IsReady(&work->actorSys)) {
        work->state = WIFICLUB_BeginIdle(work, 0);
    } else {
        WIFICLUB_ResetOwnSeatStatus(work);
        WIFICLUB_DrawPlayerInfoWindow(work);
        work->partnerIndex = -1;
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        WIFICLUB_DisableTouchBar(work);
    }
    return procState;
}


/*
 * Same as the error message wait, but without the status check: a key press
 * or the timeout disconnects and goes back to the lobby or to the idle state.
 */
int WIFICLUB_StateLeaveCancel(WifiClubWork *work, int procState)
{
    if (GFL_NET_STATE_IsFatalError()) { WIFICLUB_OnFatalError(work); return procState; }
    if (!WIFICLUB_UpdateTalkStream(work)) { work->counter = 30; return procState; }
    --work->counter;
    if ((KEY_GetTrg() & 3) || !work->counter) {
        WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, WIFICLUB_FindPeerActor(work, WIFICLUBACTOR_GetPickResult(&work->actorSys)));
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_StartNetSession(work, 0);
        if (!WIFICLUBACTOR_IsReady(&work->actorSys)) {
            work->state = WIFICLUB_BeginIdle(work, 0);
        } else {
            WIFICLUB_ResetOwnSeatStatus(work);
            WIFICLUB_DrawPlayerInfoWindow(work);
            work->partnerIndex = -1;
            work->state = WIFICLUB_STATE_LOBBY_MAIN;
            WIFICLUB_DisableTouchBar(work);
        }
    }
    return procState;
}


/* Handler table entry that does nothing: returns the proc state. */
int WIFICLUB_StateUnusedA(int unused, int procState) { return procState; }


/* Handler table entry that does nothing: returns the proc state. */
int WIFICLUB_StateUnusedB(int unused, int procState) { return procState; }


/* Handler table entry that does nothing: returns the proc state. */
int WIFICLUB_StateUnusedC(int unused, int procState) { return procState; }


/*
 * Counts the delay down. When it ends, an A or B press shows a message and
 * moves to the next state.
 */
int WIFICLUB_StateCountdownThenConfirm(WifiClubWork *work, int procState)
{
    if (work->counter > 0) { --work->counter; return procState; }
    if (KEY_GetTrg() & 3) {
        WIFICLUB_ShowStreamedMessage(work, 26, 1);
        work->state = WIFICLUB_STATE_EXIT_NETWORK;
        work->counter = 1;
    }
    return procState;
}


/* Starts the leave prompt: shows message 7 in the talk window. */
int WIFICLUB_StateStartPrompt(WifiClubWork *work, int procState)
{
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    WIFICLUB_ShowStreamedMessage(work, 7, 0);
    work->state = WIFICLUB_STATE_WAIT_PROMPT;
    return procState;
}


/* Waits for the leave prompt message, then opens its yes/no menu. */
int WIFICLUB_StateWaitPrompt(WifiClubWork *work, int procState)
{
    WIFICLUBACTOR_TickBlink(&work->actorSys);

    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_PROMPT;
    }

    return procState;
}


/*
 * Polls the leave prompt yes/no menu. Yes disconnects and goes back to the
 * lobby. No shows message 6. A new client joining closes the menu.
 */
int WIFICLUB_StatePollPrompt(WifiClubWork *work, int procState)
{
    int answer = WIFICLUB_PollYesNoMenu(work);
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (work->partnerIndex == -1 && DWC_RAP_GetNewClientAid() != -1) {
        if (answer == -1) { BMP_MENU_DeleteYesNo(work->yesNoMenu); work->yesNoMenu = 0; }
        answer = 1;
    }
    if (answer == -1) return procState;
    if (answer == 0) {
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_StartNetSession(work, 0);
        WIFICLUB_DisableTouchBar(work);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
    } else {
        WIFICLUB_ShowMessage(work, 6, 0);
        work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
    }
    return procState;
}


/* Opens the partner menu and moves to the message state. */
int WIFICLUB_StateOpenPartnerMenu(WifiClubWork *work, int procState)
{
    WIFICLUB_CreateMainMenu(work);
    work->state = WIFICLUB_STATE_SHOW_PARTNER_MENU_MESSAGE;
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    return procState;
}


/* Shows message 5 above the partner menu. */
int WIFICLUB_StateShowPartnerMenuMessage(WifiClubWork *work, int procState)
{
    WIFICLUB_ShowStreamedMessage(work, 5, 0);
    work->state = WIFICLUB_STATE_PARTNER_MENU;
    return procState;
}


/* Closes the partner menu: deletes its window, list and item work. */
void WIFICLUB_ClosePartnerMenu(WifiClubWork *work)
{
    if (work->menuWin) {
        work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
        BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[4]);
        BMP_MENUWORK_Delete(work->menuWork);
        WIFICLUB_ClearTalkWindow(work);
    }
}


/*
 * Polls the partner menu. Choice 7 opens the rule menu, choices 4 to 6 start
 * a request (some need the second seat), cancel goes back to the lobby.
 * Other choices are sent to the peer after a short delay.
 */
int WIFICLUB_StatePartnerMenu(WifiClubWork *work, int procState)
{
    u32 choice;
    WifiClubSession *session;
    POKEPARTY_GetAliveNonEggCount(work->party);
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    choice = BMP_MENULIST_Main(work->menuList);
    switch (choice) {
    case (u32)-1:
        return procState;
    case (u32)-2:
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        WIFICLUB_ClosePartnerMenu(work);
        WIFICLUB_DisableTouchBar(work);
        return procState;
    case 7:
        WIFICLUB_ClosePartnerMenu(work);
        session = work->session;
        work->ruleKind = session->ruleKind;
        work->ruleLevel = session->ruleLevel;
        session->regulationId = session->ruleOption;
        WIFICLUB_SetupRuleMenu(work, 1);
        work->state = WIFICLUB_STATE_RULE_MENU;
        return procState;
    case 4:
        if (work->session->ownSeat == 0) return procState;
        WIFICLUB_ClosePartnerMenu(work);
        WIFICLUB_AddNetCommandsAndCheckFriend(work, -1);
        work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
        break;
    case 6:
        if (WIFICLUB_HasEnoughPartyMembers(work) == 0) {
            work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
            BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[4]);
            BMP_MENUWORK_Delete(work->menuWork);
            WIFICLUB_ClearTalkWindow(work);
            WIFICLUB_ShowStreamedMessage(work, 0x79, 0);
            work->state = WIFICLUB_STATE_WAIT_KEY_DISCONNECT_TO_LOBBY;
            return procState;
        } else {
            WIFICLUB_ClosePartnerMenu(work);
            WIFICLUB_AddNetCommandsAndCheckFriend(work, -1);
            work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
        }
        break;
    case 5:
        if (work->session->ownSeat == 0) return procState;
        if (APP_ENV_HasParentalControlBits() == 0 && APP_ENV_IsRunOnTwl() != 0) {
            WIFICLUB_ClosePartnerMenu(work);
            WIFICLUB_ShowStreamedMessage(work, 0x95, 0);
            work->state = WIFICLUB_STATE_OPEN_MENU_CHOICE_PROMPT;
            return procState;
        } else {
            WIFICLUB_ClosePartnerMenu(work);
            WIFICLUB_AddNetCommandsAndCheckFriend(work, -1);
            work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
        }
        break;
    case 0: case 1: case 2: case 3: default:
        break;
    }
    WIFICLUB_EnableTouchBar(work, 1);
    work->counter = 0;
    work->choice = choice;
    work->state = WIFICLUB_STATE_SEND_CHOICE_AFTER_DELAY;
    return procState;
}


/*
 * Counts down the delay. When it ends, sends the stored menu choice to the
 * peer and moves to the lobby connected state.
 * The decrement is the loop condition itself: the image tests the flags of the subtraction.
 */
int WIFICLUB_StateSendChoiceAfterDelay(WifiClubWork *work, int procState)
{
    if (--work->counter < 0) {
        WIFICLUB_SetOwnStatusAndPublish(work, 2, work->choice);
        work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
    }

    return procState;
}


/* Waits for the menu choice message, then opens its yes/no menu. */
int WIFICLUB_StateOpenMenuChoicePrompt(WifiClubWork *work, int procState)
{
    WIFICLUBACTOR_TickBlink(&work->actorSys);

    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_MENU_CHOICE_PROMPT;
    }

    return procState;
}


/*
 * Polls the menu choice yes/no menu. Yes sends choice 5 to the peer. No goes
 * back to the lobby.
 */
int WIFICLUB_StatePollMenuChoicePrompt(WifiClubWork *work, int procState)
{
    int answer;
    answer = WIFICLUB_PollYesNoMenu(work);
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (answer == -1) return procState;
    if (answer == 0) {
        WIFICLUB_AddNetCommandsAndCheckFriend(work, -1);
        WIFICLUB_SetOwnStatusAndPublish(work, 2, 5);
        WIFICLUB_EnableTouchBar(work, 1);
        work->state = WIFICLUB_STATE_LOBBY_CONNECTED;
    } else {
        WIFICLUB_DisableTouchBar(work);
        WIFICLUB_ClearTalkWindow(work);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
    }
    return procState;
}


/* Waits for the request message, then opens its yes/no menu. */
int WIFICLUB_StateOpenRequestPrompt(WifiClubWork *work, int procState)
{
    WIFICLUBACTOR_TickBlink(&work->actorSys);

    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_REQUEST_PROMPT;
    }

    return procState;
}


/*
 * Polls the request yes/no menu. Yes accepts the partner and shows message 72
 * or 73 by status kind. No goes back to the lobby.
 * The own status pointer is set first: the compiler needs it before the first call.
 */
int WIFICLUB_StatePollRequestPrompt(WifiClubWork *work, int procState)
{
    int pickedIndex;
    int answer;
    void *actor;
    WifiClubPlayerStatus *ownStatus;
    ownStatus = &work->ownStatus;
    pickedIndex = WIFICLUBACTOR_GetPickResult(&work->actorSys);
    answer = WIFICLUB_PollYesNoMenu(work);
    actor = WIFICLUB_FindPeerActor(work, pickedIndex);
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (answer == -1) return procState;
    if (answer == 0) {
        work->connectionMode = 2;
        if (WIFICLUB_GetStatusSeatFlag(ownStatus) == WIFICLUB_GetStatusSeatFlag(work->localStatus)) {
            work->state = WIFICLUB_STATE_REQUEST_JOIN_PARTNER;
        } else {
            if (WIFICLUB_GetStatusSeatFlag(work->localStatus)) WIFICLUB_ShowStreamedMessage(work, 73, 0);
            else WIFICLUB_ShowStreamedMessage(work, 72, 0);
            work->state = WIFICLUB_STATE_OPEN_SEAT_YES_NO;
        }
    } else {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        work->partnerIndex = -1;
        WIFICLUB_DisableTouchBar(work);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        if (actor) WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, actor);
    }
    return procState;
}


/*
 * Waits for the talk window, then for any key. Then it disconnects and goes
 * back to the lobby.
 */
int WIFICLUB_StateWaitKeyDisconnectToLobby(WifiClubWork *work, int procState)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    if (KEY_GetTrg()) {
        WIFICLUB_ClearTalkWindow(work);
        GFL_NET_STATE_WifiDisconnect(1);
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        work->partnerIndex = -1;
        WIFICLUB_DisableTouchBar(work);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
    }
    return procState;
}


/* Disconnects at once and goes back to the lobby. */
int WIFICLUB_StateDisconnectToLobby(WifiClubWork *work, int procState) { WIFICLUB_ClearTalkWindow(work); GFL_NET_STATE_WifiDisconnect(1); WIFICLUB_SetOwnStatusAndPublish(work, 1, 2); work->partnerIndex = -1; WIFICLUB_DisableTouchBar(work); work->state = WIFICLUB_STATE_LOBBY_MAIN; return procState; }


/*
 * Polls the selection menu. A choice is sent to the peer and the lobby state
 * follows. Cancel goes back to the partner menu.
 */
int WIFICLUB_StateSelectionMenu(WifiClubWork *work, int procState)
{
    int choice;
    WIFICLUBACTOR_TickBlink(&work->actorSys);
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    choice = BMP_MENULIST_Main(work->menuList);
    switch (choice) {
    case -1: return procState;
    case -2:
        GFL_USE_PlaySeDefaultVolume(1356);
        work->state = WIFICLUB_STATE_OPEN_PARTNER_MENU;
        break;
    default:
        GFL_USE_PlaySeDefaultVolume(1356);
        WIFICLUB_SetOwnStatusAndPublish(work, 2, choice);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        WIFICLUB_ClearTalkWindow(work);
        break;
    }
    if (work->state == WIFICLUB_STATE_LOBBY_MAIN) { WIFICLUB_AddNetCommandsAndCheckFriend(work, -1); WIFICLUB_EnableTouchBar(work, 1); }
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, &work->menuCursor[work->menuKind]);
    BMP_MENUWORK_Delete(work->menuWork);
    return procState;
}


/*
 * Picks a message for the chosen partner from the status kind and phase,
 * then shows it. Status kind 1 starts the request at once.
 * The own status pointer is set first: the compiler needs it before the first call.
 */
int WIFICLUB_StateShowPartnerStatusMessage(WifiClubWork *work, int procState)
{
    WifiClubMessageTable kind2Messages, kind4Messages;
    int selector, pickedIndex, message, facing;
    void *actor;
    u16 statusKind, statusPhase;
    WifiClubPlayerStatus *ownStatus;
    ownStatus = &work->ownStatus;
    selector = 0;
    GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), 0);
    pickedIndex = WIFICLUBACTOR_GetPickResult(&work->actorSys);
    actor = WIFICLUB_FindPeerActor(work, pickedIndex);
    facing = WIFICLUBACTOR_GetActorFacing(WIFICLUB_FindPeerActor(work, 0));
    WIFICLUBACTOR_StartTurn(&work->actorSys, actor, facing);
    statusKind = (u16)WIFICLUB_GetStatusKind(work, ownStatus);
    statusPhase = (u16)WIFICLUB_GetStatusPhase(work, ownStatus);
    WIFICLUB_SetPartnerNameWord(work, pickedIndex - 1);
    if (statusPhase == 6) selector = 1;
    else if (statusPhase == 5) selector = 2;
    else if (statusPhase == 4) selector = 3;
    else if (WIFICLUB_IsBusyPhase(statusPhase)) selector = 4;
    switch (statusKind) {
    case 0:
        message = 0x59;
        break;
    case 1:
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        WIFICLUB_TryStartPartnerRequest(work);
        return procState;
    case 2:
        kind2Messages = d_021C3804;
        message = kind2Messages.v[selector];
        break;
    case 4:
        kind4Messages = d_021C3818;
        message = kind4Messages.v[selector];
        break;
    case 5:
        message = 0x59;
        break;
    case 3:
    default:
        message = 0x59;
        break;
    }
    WIFICLUB_ShowStreamedMessage(work, message, 0);
    work->state = WIFICLUB_STATE_OPEN_ANSWER_MENU;
    return procState;
}


/*
 * Waits for the message, then opens the answer menu for the chosen partner
 * by status kind. Other kinds restore the actor and move on.
 * The own status pointer is set first: the compiler needs it before the first call.
 */
int WIFICLUB_StateOpenAnswerMenu(WifiClubWork *work, int procState)
{
    void *actor;
    unsigned statusKind;
    int statusPhase;
    WifiClubPlayerStatus *ownStatus;
    ownStatus = &work->ownStatus;
    if (GFL_NET_STATE_IsFatalError()) { WIFICLUB_OnFatalError(work); return procState; }
    actor = WIFICLUB_FindPeerActor(work, WIFICLUBACTOR_GetPickResult(&work->actorSys));
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    statusKind = WIFICLUB_GetStatusKind(work, ownStatus);
    statusPhase = WIFICLUB_GetStatusPhase(work, ownStatus);
    switch (statusKind) {
    case 1: WIFICLUB_CreateAnswerMenu(work); work->state = WIFICLUB_STATE_ANSWER_MENU; break;
    case 2: case 5:
        if (WIFICLUB_IsActivePhase(statusPhase)) { WIFICLUB_CreateAnswerMenu(work); work->state = WIFICLUB_STATE_PARTNER_MENU_RESULT; break; }
    case 0: case 3: case 4: default:
        WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, actor);
        work->state = WIFICLUB_STATE_WAIT_KEY_DISCONNECT_TO_LOBBY;
        break;
    }
    return procState;
}


/*
 * Starts a request to the picked partner. Returns 0 if the partner status
 * kind does not allow it, otherwise 1 (the request or the refusal message
 * has started).
 */
int WIFICLUB_TryStartPartnerRequest(WifiClubWork *work)
{
    int pickedIndex;
    int peerIndex;
    WifiClubPlayerStatus *peerStatus;
    u32 statusKind;
    pickedIndex = WIFICLUBACTOR_GetPickResult(&work->actorSys);
    work->selectedPlusOne = pickedIndex;
    if (pickedIndex != 0) {
        POKEPARTY_GetAliveNonEggCount(work->party);
        peerIndex = pickedIndex - 1;
        peerStatus = WIFICLUB_GetFriendStatus(peerIndex);
        statusKind = WIFICLUB_GetStatusKind(work, peerStatus);
        WIFICLUB_GetStatusSeatFlag(peerStatus);
        if (statusKind == 6) return 0;
        if (WIFICLUB_AddNetCommandsAndCheckFriend(work, -1)) {
            WIFICLUB_CountChangeAndCopyPeerAddr(work->localStatus, WIFICLUB_GetFriendStatus(peerIndex));
            work->idleTimer = 0xe10;
            WIFICLUB_ChangeNetMode(work, 3, 3);
            WIFICLUB_SetOwnStatusAndPublish(work, 3, 3);
            WIFICLUB_SetPartnerNameWord(work, pickedIndex - 1);
            work->sceneReady = pickedIndex;
            WIFICLUB_ShowMessage(work, 14, 0);
            WIFICLUB_ResetTimeIcon(work);
            work->state = WIFICLUB_STATE_WAIT_PARTNER_RESPONSE;
        } else {
            WIFICLUB_SetPartnerNameWord(work, pickedIndex - 1);
            WIFICLUB_ShowStreamedMessage(work, 13, 0);
            work->state = WIFICLUB_STATE_LEAVE_CANCEL;
        }
    }
    return 1;
}


static inline int Step(int *dst, int old)
{
    int n;
    n = (int)((u32)old + 1);
    *dst = n;
    return n;
}


/*
 * Waits for the partner to answer the request. Sends the status again every
 * 900 frames. After 3600 frames, or if the partner is gone, it shows the
 * refusal message. B asks if the request should stop.
 * The counter is incremented as unsigned and stored first: the compiler needs it for the signed modulo.
 */
int WIFICLUB_StateWaitPartnerResponse(WifiClubWork *work, int procState)
{
    u32 counter;
    WIFICLUB_UpdateTalkStream(work);
    if (DWC_RAP_GetNewClientAid() != -1) work->state = WIFICLUB_STATE_LOBBY_MAIN;
    if (WIFICLUB_GetFriendConnectionStatus(work->selectedPlusOne - 1) == 0) {
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    counter = work->counter + 1u;
    work->counter = counter;
    if ((int)counter % 900 == 0) {
        WIFICLUB_CountChangeAndCopyPeerAddr(work->localStatus, WIFICLUB_GetFriendStatus(work->selectedPlusOne - 1));
        WIFICLUB_SetOwnStatusAndPublish(work, 3, 3);
    }
    if (work->counter > 3600) {
        WIFICLUB_SetPartnerNameWord(work, work->selectedPlusOne - 1);
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    if ((u32)KEY_GetTrg() == 2) {
        WIFICLUB_ShowStreamedMessage(work, 0x47, 0);
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_CANCEL_REQUEST_PROMPT;
    }
    return procState;
}


/*
 * Polls the yes/no menu that asks to stop the request. Yes shows message 74.
 * No shows message 14 and waits again for the partner.
 */
int WIFICLUB_StatePollCancelRequestPrompt(WifiClubWork *work, int procState)
{
    int answer;
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1) return procState;
    if (answer == 0) {
        WIFICLUB_ShowStreamedMessage(work, 74, 0);
        work->state = WIFICLUB_STATE_LEAVE_CANCEL;
    } else {
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUB_ShowStreamedMessage(work, 14, 0);
        WIFICLUB_ResetTimeIcon(work);
        work->state = WIFICLUB_STATE_WAIT_PARTNER_RESPONSE;
    }
    return procState;
}


/*
 * Polls the answer menu. Choice 1 starts the request, choice 2 goes to the
 * next state, cancel goes back to the lobby. It also closes the menu if the
 * partner status changes or a network error occurs.
 */
int WIFICLUB_StateAnswerMenu(WifiClubWork *work, int procState)
{
    int statusChanged;
    s32 choice;
    int pickedIndex;
    WifiClubActor *actor;
    WifiClubPlayerStatus *peerStatus;
    int peerPhase;
    statusChanged = 0;
    choice = BMP_MENULIST_Main(work->menuList);
    pickedIndex = WIFICLUBACTOR_GetPickResult(&work->actorSys);
    actor = WIFICLUB_FindPeerActor(work, pickedIndex);
    if (GFL_NET_STATE_IsFatalError()) {
        work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
        BMP_MENULIST_Delete(work->menuList, 0, 0);
        BMP_MENUWORK_Delete(work->menuWork);
        if (actor)
            WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, actor);
        WIFICLUB_OnFatalError(work);
        return procState;
    }
    switch (choice) {
    case -1:
        if (actor == 0) {
            BMP_MENULIST_Delete(work->menuList, 0, 0);
            WIFICLUB_SetPartnerNameWord(work, pickedIndex - 1);
            WIFICLUB_ShowStreamedMessage(work, 13, 0);
            work->state = WIFICLUB_STATE_LEAVE_CANCEL;
            statusChanged = 1;
        } else {
            peerStatus = WIFICLUB_GetFriendStatus(pickedIndex - 1);
            WIFICLUB_GetStatusKind(work, peerStatus);
            statusChanged = WIFICLUB_GetStatusSeatFlag(peerStatus);
            peerPhase = WIFICLUB_GetStatusPhase(work, peerStatus);
            if (peerPhase != WIFICLUB_GetStatusPhase(work, &work->ownStatus) || statusChanged != WIFICLUB_GetStatusSeatFlag(&work->ownStatus)) {
                WIFICLUB_SetPartnerNameWord(work, pickedIndex - 1);
                WIFICLUB_ShowStreamedMessage(work, 13, 0);
                work->state = WIFICLUB_STATE_LEAVE_CANCEL;
                statusChanged = 1;
            } else {
                return procState;
            }
        }
        break;
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        break;
    default:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        if (choice == 1) {
            work->state = WIFICLUB_STATE_LOBBY_MAIN;
            WIFICLUB_TryStartPartnerRequest(work);
        } else if (choice == 2) {
            work->state = WIFICLUB_STATE_GOTO_WAIT_KEY;
        }
        break;
    }
    if (statusChanged == 0)
        WIFICLUB_ClearTalkWindow(work);
    work->menuWin = WIFICLUB_DeleteWindow(work->menuWin);
    BMP_MENULIST_Delete(work->menuList, 0, 0);
    BMP_MENUWORK_Delete(work->menuWork);
    if (actor)
        WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, actor);
    return procState;
}







/* Turns voice chat off. */
void WIFICLUB_DisableVoiceChat(void) { DWC_RAP_SetVchatEnabled(0); }








/*
 * Handles the result of the partner action menu. It plays the confirm sound,
 * reads the status of the picked partner and chooses the next state: join, rule
 * choice, or back to the lobby.
 * The status pointer is set at the top: the compiler needs it to build 0x24C once.
 */
int WIFICLUB_StatePartnerMenuResult(WifiClubWork *work, int procState)
{
    int menuResult;
    int phase;
    WifiClubActor *pickedActor;
    WifiClubPlayerStatus *ownStatus;
    u16 pickedActorId;

    ownStatus = &work->ownStatus;
    menuResult = BMP_MENULIST_Main(work->menuList);
    if (WIFICLUB_HasNewClientAid(work)) {
        menuResult = -2;
    }
    pickedActorId = WIFICLUBACTOR_GetPickResult(&work->actorSys);
    work->selectedPlusOne = pickedActorId;
    pickedActor = WIFICLUB_FindPeerActor(work, pickedActorId);
    if (GFL_NET_STATE_IsFatalError()) {
        work->menuWin = WIFICLUB_DeleteWindow((void *)(work->menuWin));
        BMP_MENULIST_Delete(work->menuList, 0, 0);
        BMP_MENUWORK_Delete(work->menuWork);
        if (pickedActor) {
            WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, pickedActor);
        }
        WIFICLUB_OnFatalError(work);
        return procState;
    }
    if (menuResult != -1) {
        WIFICLUB_ClearTalkWindow(work);
        work->menuWin = WIFICLUB_DeleteWindow((void *)(work->menuWin));
        BMP_MENULIST_Delete(work->menuList, 0, 0);
        BMP_MENUWORK_Delete(work->menuWork);
    }
    switch (menuResult) {
    case -1:
        return procState;
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        goto end;
    }
    GFL_USE_PlaySeDefaultVolume(0x54c);
    phase = WIFICLUB_GetStatusPhase(work, ownStatus);
    if (phase == 5 && !APP_ENV_HasParentalControlBits() && APP_ENV_IsRunOnTwl()) {
        WIFICLUB_ShowStreamedMessage(work, 0x95, 0);
        work->state = WIFICLUB_STATE_OPEN_REQUEST_PROMPT;
        return procState;
    }
    if (phase == 6 && !WIFICLUB_HasEnoughPartyMembers(work)) {
        WIFICLUB_ShowStreamedMessage(work, 0x79, 0);
        work->state = WIFICLUB_STATE_WAIT_KEY_DISCONNECT_TO_LOBBY;
        goto end;
    }
    if (WIFICLUB_IsBusyPhase(phase)) {
        work->ruleKind = (phase - 7) / 2;
        work->ruleLevel = (phase - 7) % 2;
        WIFICLUB_LoadOwnRegulation(work);
        if (!WIFICLUB_HasRuleViolation(work)) {
            WIFICLUB_ShowStreamedMessage(work, 0x68, 0);
            work->state = WIFICLUB_STATE_WAIT_KEY_DISCONNECT_TO_LOBBY;
        }
    }
    work->connectionMode = 2;
    phase = WIFICLUB_GetStatusSeatFlag(ownStatus);
    if (phase == WIFICLUB_GetStatusSeatFlag(work->localStatus)) {
        work->state = WIFICLUB_STATE_REQUEST_JOIN_PARTNER;
    } else {
        if (WIFICLUB_GetStatusSeatFlag(work->localStatus)) {
            WIFICLUB_ShowStreamedMessage(work, 0x49, 0);
        } else {
            WIFICLUB_ShowStreamedMessage(work, 0x48, 0);
        }
        work->state = WIFICLUB_STATE_OPEN_SEAT_YES_NO;
    }
end:
    if (pickedActor) {
        WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, pickedActor);
    }
    return procState;
}







/*
 * Runs when the player picks a partner who is waiting. If the partner status
 * matches ours, it starts the connection. Otherwise it shows a refusal message.
 * Signed int locals keep the compiler from hoisting the index minus one.
 */
int WIFICLUB_StateRequestJoinPartner(WifiClubWork *work, int procState)
{
    int selectedIndex;
    void *partnerStatus;
    int partnerKind, partnerPhase, partnerSeat;
    selectedIndex = work->selectedPlusOne;
    POKEPARTY_GetAliveNonEggCount(work->party);
    if (work->selectedPlusOne == 0) {
        WIFICLUB_ShowStreamedMessage(work, 0x4a, 0);
        work->state = WIFICLUB_STATE_LEAVE_CANCEL;
    }
    partnerStatus = WIFICLUB_GetFriendStatus(selectedIndex - 1);
    partnerKind = WIFICLUB_GetStatusKind(work, partnerStatus);
    partnerPhase = WIFICLUB_GetStatusPhase(work, partnerStatus);
    partnerSeat = WIFICLUB_GetStatusSeatFlag(partnerStatus);
    if (partnerKind != WIFICLUB_GetStatusKind(work, &work->ownStatus) ||
        partnerPhase != WIFICLUB_GetStatusPhase(work, &work->ownStatus) ||
        partnerSeat != WIFICLUB_GetStatusSeatFlag(&work->ownStatus) || partnerKind == 6) {
        WIFICLUB_SetPartnerNameWord(work, selectedIndex - 1);
        WIFICLUB_ShowStreamedMessage(work, 13, 0);
        work->state = WIFICLUB_STATE_LEAVE_CANCEL;
        return procState;
    }
    WIFICLUB_GetFriendConnectionStatus(selectedIndex - 1);
    if (WIFICLUB_AddNetCommandsAndCheckFriend(work, selectedIndex - 1)) {
        work->idleTimer = 0xe10;
        WIFICLUB_ChangeNetMode(work, 3, partnerPhase);
        WIFICLUB_SetOwnStatusAndPublish(work, 3, partnerPhase);
        WIFICLUB_SetPartnerNameWord(work, selectedIndex - 1);
        WIFICLUB_ShowMessage(work, 14, 0);
        WIFICLUB_ResetTimeIcon(work);
        work->selectedPlusOne = selectedIndex;
        work->state = WIFICLUB_STATE_WAIT_JOIN_ANSWER;
    } else {
        WIFICLUB_SetPartnerNameWord(work, selectedIndex - 1);
        WIFICLUB_ShowStreamedMessage(work, 13, 0);
        work->state = WIFICLUB_STATE_LEAVE_CANCEL;
    }
    return procState;
}







/*
 * Waits for the partner to answer the join request. It ends on a timeout, on a
 * network error or when the link comes up.
 */
int WIFICLUB_StateWaitJoinAnswer(WifiClubWork *work, int procState)
{
    WifiClubActor *peerActor;
    WIFICLUB_UpdateTalkStream(work);
    if (--work->idleTimer < 0) {
        peerActor = WIFICLUB_FindPeerActor(work, WIFICLUBACTOR_GetPickResult(&work->actorSys));
        if (peerActor) WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, peerActor);
        work->state = WIFICLUB_STATE_LEAVE_LINK_TO_LOBBY;
    } else if (GFL_NET_STATE_GetWifiState() == 5) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
    } else if (DWC_RAP_GetResult() == 5) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 12, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
    } else if (DWC_RAP_GetResult() == 4 || GFL_NET_STATE_IsWifiDisconnectFinal() != 0) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
    } else if (GFL_NET_STATE_GetWifiState() == 1) {
        WIFICLUB_CopyZeroToDeviceAddr(work->localStatus);
        WIFICLUB_PublishOwnStatus(work);
        WIFICLUB_GetStatusKind(work, (work->localStatus));
        work->state = WIFICLUB_STATE_WAIT_NEGOTIATION;
        WIFICLUB_ClearTalkWindow(work);
        WIFICLUBACTOR_AddNetCommands(work);
        work->counter = 30;
        GFL_NET_SetAutoExit(1);
        GFL_NET_SetLoginOption(1);
    }
    return procState;
}






/* Returns its second argument. */
int WIFICLUB_ReturnSecondArgA(int unused, int value) { return value; }






/* Returns its second argument. */
int WIFICLUB_ReturnSecondArgB(int unused, int value) { return value; }





/* Leaves the partner link and goes back to the lobby state. */
int WIFICLUB_StateLeaveLinkToLobby(WifiClubWork *work, int procState) {
    WIFICLUB_ResetOwnSeatStatus(work);
    WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
    GFL_NET_STATE_WifiDisconnect(1);
    work->partnerIndex = -1;
    work->state = WIFICLUB_STATE_LOBBY_MAIN;
    WIFICLUB_DisableTouchBar(work);
    WIFICLUB_ClearTalkWindow(work);
    return procState;
}





/* State with no action. */
int WIFICLUB_StateUnusedD(WifiClubWork *work, int procState) { return procState; }





/* State with no action. */
int WIFICLUB_StateUnusedE(WifiClubWork *work, int procState) { return procState; }





/*
 * Runs when a partner has connected. It waits for the sound slot to end, then
 * reads the partner status and starts the sync, or shows a refusal message.
 */
int WIFICLUB_StateOnPartnerConnected(WifiClubWork *work, int procState)
{
    int zero = 0;
    void *partnerStatus;
    if (GFL_USE_IsSeSlotBusy(0) != 0) return procState;
    if (WIFICLUB_GetFriendConnectionStatus(DWC_RAP_GetTargetFriendIndex()) == 0) {
        WIFICLUB_SetPartnerNameWord(work, work->partnerIndex);
        WIFICLUB_ShowStreamedMessage(work, 15, zero);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
        return procState;
    }
    partnerStatus = WIFICLUB_GetFriendStatus(DWC_RAP_GetTargetFriendIndex());
    WIFICLUB_GetStatusKind(work, work->localStatus);
    WIFICLUB_GetStatusKind(work, partnerStatus);
    WIFICLUB_GetStatusSeatFlag(work->localStatus);
    work->selectedPlusOne = DWC_RAP_GetTargetFriendIndex() + 1;
    if (work->sceneReady == 0) {
        WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_ShowStreamedMessage(work, 8, zero);
    }
    WIFICLUBACTOR_AddNetCommands(work);
    work->state = WIFICLUB_STATE_WAIT_NEGOTIATION;
    work->counter = 30;
    return procState;
}





/*
 * Checks the network for a failure. On a lost link it shows the message and sets
 * state 19. Returns 1 when the failure was handled, 0 when the link is fine.
 */
int WIFICLUB_HandleNetFailure(WifiClubWork *work)
{
    if (GFL_NET_STATE_GetWifiState() >= 3) {
        WIFICLUB_SetPartnerNameWord(work, work->partnerIndex);
        WIFICLUB_ShowStreamedMessage(work, 15, 0);
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
    } else {
        if (GFL_NET_STATE_IsFatalError() != 0) WIFICLUB_OnFatalError(work);
        else return 0;
    }
    work->pendingFlag = 0;
    return 1;
}





/*
 * Waits for the link to be negotiated. Once both sides agree, it clears the
 * member ids and moves on to the sync states.
 */
int WIFICLUB_StateWaitNegotiation(WifiClubWork *work, int procState)
{
    WIFICLUB_UpdateTalkStream(work);
    if (GFL_NET_STATE_GetWifiState() >= 4 || GFL_NET_STATE_IsWifiDisconnectFinal() != 0) {
        if (work->pendingFlag != 0) {
            WIFICLUB_ShowStreamedMessage(work, 0x44, 0);
        } else {
            WIFICLUB_SetPartnerNameWord(work, work->partnerIndex);
            WIFICLUB_ShowStreamedMessage(work, 15, 0);
        }
        work->pendingFlag = 0;
        work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
    } else if (WIFICLUB_HandleNetFailure(work) == 0) {
        if (work->counter > 1) --work->counter;
        if (work->counter == 0) {
            if (GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetCurrentHandle()) != 0) {
                MI_CpuFill8(work->memberIds, 0, 0x40);
                GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 14, 10);
                work->pendingFlag = 0;
                WIFICLUB_ShowStreamedMessage(work, 0x45, 0);
                WIFICLUB_ResetTimeIcon(work);
                work->state = WIFICLUB_STATE_SEND_TRAINER_CARD;
            }
        } else if (work->counter == 1) {
            if (GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) != 0) {
                if (GFL_NET_HANDLE_CheckNegotiation() == 1) work->counter = 0;
            } else if (GFL_NET_HANDLE_GetNegotiationNum() != 0 && GFL_NET_HANDLE_CheckNegotiation() == 1) {
                work->counter = 0;
            }
        }
    }
    return procState;
}





/*
 * Net command: receives the trainer card of a friend. It stores the card in the
 * friend slot and records it in the save data.
 */
void WIFICLUB_RecvFriendTrainerCard(int friendIndex, int unused, void *receivedStatus, WifiClubWork *work, int handle)
{
    void *friendStatus;
    void *friendRecords;
    if (handle == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        friendStatus = GAME_DATA_GetPlayerStatusById(work->gameData, friendIndex);
        MYSTATUS_Copy(receivedStatus, friendStatus);
        friendRecords = MISC_SAVEDATA_GetBlock44(work->saveData);
        MISC_SAVEDATA_InsertRecentValue(friendRecords, func_02008530(friendStatus));
    }
}





/* Net command with no action. */
void WIFICLUB_NoOpNetCommand(void) {}






/* Net command: marks the scene result when the sender is the current handle. */
void WIFICLUB_RecvSceneResult(int unusedA, int unusedB, int unusedC, WifiClubWork *work, int handle)
{
    if ((int)GFL_NET_HANDLE_GetCurrentHandle() == handle) {
        work->sceneResult = 1;
    }
}





/* Net command buffer getter: returns the party snapshot of one seat. */
u32 WIFICLUB_GetSeatPartyBuffer(int seat, WifiClubWork *work)
{
    return (u32)work->session->seatParty[seat];
}









/*
 * Net command: receives the state to resume in. In state 0x48 it stores the
 * value and starts a sync. In any other state it sets state 21.
 */
void WIFICLUB_RecvResumeState(int unusedA, int unusedB, u8 *payload, WifiClubWork *work, int handle)
{
    if (handle == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        if (work->state == WIFICLUB_STATE_WAIT_SYNC_AND_RESUME) {
            work->resumeState = *payload;
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 10);
        } else {
            work->state = WIFICLUB_STATE_LEAVE_CANCEL;
        }
    }
}










/* Net command: applies the received rule id when the sender is the current handle. */
void WIFICLUB_RecvRuleId(int unusedA, int unusedB, int *ruleId, WifiClubWork *work, int handle)
{
    if (handle == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
        WIFICLUB_ApplyRuleId(work, *ruleId);
    }
}










/* Net command: stores the member id and voice chat flag of one slot and applies the rule. */
void WIFICLUB_RecvPeerChoice(int slot, int unused, WifiClubPeerChoice *choice, WifiClubWork *work)
{
    work->memberIds[slot] = choice->memberId;
    work->session->voiceChat[slot] = choice->voiceChat;
    WIFICLUB_ApplyRuleId(work, choice->value);
}









/* Sends the own trainer card to the peer after the sync. Ends in state 135. */
int WIFICLUB_StateSendTrainerCard(WifiClubWork *work, int procState)
{
    int handle;
    unsigned statusSize;
    void *statusData;
    if (WIFICLUB_HandleNetFailure(work) == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 14, 10) != 0) {
            handle = (int)GFL_NET_HANDLE_GetCurrentHandle();
            statusSize = MYSTATUS_GetSize();
            statusData = GAME_DATA_GetMyStatus(work->gameData);
            if (GFL_NET_SendToHandle((void *)handle, (u16)0xa04, (u16)statusSize, (u32)statusData) != 0) {
                WIFICLUB_ClearTalkWindow(work);
                work->state = WIFICLUB_STATE_SEND_CHOICE_MESSAGE;
            }
        }
    }
    return procState;
}









/* Sends the own phase, seat and rule to the peer. Ends in state 43. */
int WIFICLUB_StateSendChoiceMessage(WifiClubWork *work, int procState)
{
    WifiClubChoiceMessage request;
    WIFICLUB_GetStatusKind(work, work->localStatus);
    request.phase = WIFICLUB_GetStatusPhase(work, work->localStatus);
    if (work->seatReply != 0) {
        request.seat = work->seatReply - 1;
        work->seatReply = 0;
    } else {
        request.seat = work->session->ownSeat;
    }
    request.value = WIFICLUB_LoadPickedRegulation(work, 1);
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xa03, 8, (u32)(&request)) != 0)
        work->state = WIFICLUB_STATE_CHECK_PEER_PHASE;
    return procState;
}









/*
 * Compares the phase of the peer with the phase in the member table. On a match
 * it starts the next sync. Otherwise it shows a refusal message.
 * The callee result is bound to a narrow local before the compare.
 */
int WIFICLUB_StateCheckPeerPhase(WifiClubWork *work, int procState)
{
    int seatIndex = 0;
    u16 phase;
    if (GFL_NET_IsParentAid() != 0) seatIndex = 1;
    if (WIFICLUB_HandleNetFailure(work) == 0) {
        if (((u16 *)work->memberIds)[seatIndex] != 0) {
            phase = WIFICLUB_GetStatusPhase(work, work->localStatus);
            if (phase == ((u16 *)work->memberIds)[seatIndex]) {
                GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 15, 10);
                work->state = WIFICLUB_STATE_WAIT_SYNC_ENABLE_AUTO_EXIT;
            } else {
                WIFICLUB_SetPartnerNameWord(work, DWC_RAP_GetTargetFriendIndex());
                WIFICLUB_ShowStreamedMessage(work, 13, 0);
                work->state = WIFICLUB_STATE_ERROR_MESSAGE_WAIT;
            }
        }
    }
    return procState;
}









/* Waits for the sync, then turns on auto exit and starts the next sync. Ends in state 45. */
int WIFICLUB_StateWaitSyncEnableAutoExit(WifiClubWork *work, int procState)
{
    if (WIFICLUB_HandleNetFailure(work) == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 15, 10) != 0) {
            GFL_NET_SetAutoExit(1);
            GFL_NET_SetLoginOption(1);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 18, 10);
            work->state = WIFICLUB_STATE_BRANCH_ON_PARTNER_PHASE;
        }
    }
    return procState;
}









/* Returns 1 when the talk message has ended or the talk window is not open. */
BOOL WIFICLUB_IsTalkFinishedOrClosed(WifiClubWork *work)
{
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        return 1;
    }

    if (work->talkWin == 0) {
        return 1;
    }

    return 0;
}








/*
 * Waits for the last sync and the end of the talk message. Then it reads the
 * partner phase: phase 3 goes to state 65, any other phase is published first.
 */
int WIFICLUB_StateBranchOnPartnerPhase(WifiClubWork *work, int procState)
{
    void *partnerStatus;
    unsigned partnerPhase;
    if (WIFICLUB_HandleNetFailure(work) == 0) {
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 18, 10) != 0) {
            if (WIFICLUB_IsTalkFinishedOrClosed(work) == 1) {
                GFL_NET_ERR_UpdateFriendRecord(func_020099C8(GAME_DATA_GetField1A0(work->gameData), 0));
                WIFICLUB_ClearTalkWindow(work);
                partnerStatus = WIFICLUB_GetFriendStatus(DWC_RAP_GetTargetFriendIndex());
                WIFICLUB_GetStatusKind(work, partnerStatus);
                partnerPhase = WIFICLUB_GetStatusPhase(work, partnerStatus);
                if (partnerPhase == 3) {
                    work->state = WIFICLUB_STATE_START_INVITE;
                } else {
                    WIFICLUB_SetOwnStatusAndPublish(work, 4, partnerPhase);
                    work->state = WIFICLUB_STATE_HANDLE_PEER_PHASE;
                }
            }
        }
    }
    return procState;
}








/* Resets the sub screen setting and starts the idle state. */
int WIFICLUB_StateBeginIdleAfterNet(WifiClubWork *work, int procState)
{
    BG_SYS_FreeSlot(3);
    work->closeFlag = 0;
    work->state = WIFICLUB_BeginIdle(work, 0);
    return procState;
}








/* Sets state 47. */
int WIFICLUB_StateGotoWaitKey(WifiClubWork *work, int procState) { work->state = WIFICLUB_STATE_WAIT_KEY_OR_NET_UP; return procState; }








/* Waits for the talk message. Sets state 48 when the net is connected or on a key press. */
int WIFICLUB_StateWaitKeyOrNetUp(WifiClubWork *work, int procState)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    if (WIFICLUB_IsNetStateConnected(work)) work->state = WIFICLUB_STATE_CLEAR_TALK_TO_LOBBY;
    if (KEY_GetTrg() & 3) work->state = WIFICLUB_STATE_CLEAR_TALK_TO_LOBBY;
    return procState;
}








/* Clears the talk window and sets state 0x0B. */
int WIFICLUB_StateClearTalkToLobby(WifiClubWork *work, int procState)
{
    WIFICLUB_ClearTalkWindow(work);
    work->state = WIFICLUB_STATE_LOBBY_MAIN;
    return procState;
}








/* Opens the yes/no menu after the talk message and sets state 0x32. */
int WIFICLUB_StateOpenQuitYesNo(WifiClubWork *work, int procState)
{
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_QUIT_YES_NO;
    }

    return procState;
}







/* Reads the yes/no answer. Yes shows a message and goes to state 51. No goes back to the lobby. */
int WIFICLUB_StatePollQuitYesNo(WifiClubWork *work, int procState)
{
    int answer;
    if (WIFICLUB_UpdateTalkStream(work) == 0) return procState;
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1) return procState;
    if (answer == 0) {
        work->yesNoMenu = 0;
        WIFICLUB_ShowStreamedMessage(work, 26, 1);
        work->state = WIFICLUB_STATE_EXIT_NETWORK;
        work->counter = 1;
    } else {
        work->yesNoMenu = 0;
        WIFICLUB_ClearTalkWindow(work);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
        WIFICLUB_DisableTouchBar(work);
    }
    return procState;
}







/*
 * Closes the network connection and shows a message when it has stopped.
 * The compiler needs the zero for GFL_NET_Exit live in r0.
 */
int WIFICLUB_StateExitNetwork(WifiClubWork *work, int procState)
{
    if (WIFICLUB_UpdateTalkStream(work) == 0) return procState;
    if (work->counter == 1) {
        work->counter = 0;
        GFL_NET_Exit(0);
    }
    if (GFL_NET_GetRunState() == 0) {
        func_02009B3C(work->friendList);
        WIFICLUB_ShowStreamedMessage(work, 27, 1);
        work->state = WIFICLUB_STATE_COUNTDOWN_TO_LOBBY;
        work->counter = 30;
    }
    return procState;
}






/* Counts down after the message. Then it clears the scene kind and returns to state 26. */
int WIFICLUB_StateCountdownToLobby(WifiClubWork *work, int procState)
{
    if (!WIFICLUB_UpdateTalkStream(work)) return procState;
    if (--work->counter == 0) {
        work->sceneKind = 0;
        work->state = WIFICLUB_STATE_WIFICLUB_RESOLVE_NET_RUN_STATE;
        WIFICLUB_ClearTalkWindow(work);
    }
    return procState;
}






/* Waits for the sync, turns off auto exit and opens the yes/no menu. Ends in state 54. */
int WIFICLUB_StateOpenRetryYesNo(WifiClubWork *work, int procState)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 16, 10) == 0) return procState;
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(1);
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_RETRY_YES_NO;
    }
    return procState;
}







/* Reads the yes/no answer. Yes keeps the link. No disconnects and goes to state 57. */
int WIFICLUB_StatePollRetryYesNo(WifiClubWork *work, int procState)
{
    int answer;
    if (WIFICLUB_UpdateTalkStream(work) == 0) return procState;
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1) return procState;
    if (answer == 0) {
        WIFICLUB_ShowStreamedMessage(work, 76, 0);
        WIFICLUB_ResetTimeIcon(work);
        work->pendingFlag = 1;
        work->state = WIFICLUB_STATE_WAIT_NEGOTIATION;
        work->counter = 30;
    } else {
        WIFICLUB_ClearTalkWindow(work);
        GFL_NET_STATE_WifiDisconnect(1);
        work->counter = 20;
        work->state = WIFICLUB_STATE_WATCH_CONNECTION;
    }
    return procState;
}








/* Opens the yes/no menu after the talk message and sets state 0x38. */
int WIFICLUB_StateOpenSeatYesNo(WifiClubWork *work, int procState)
{
    if (WIFICLUB_UpdateTalkStream(work) != 0) {
        WIFICLUB_OpenYesNoMenu(work);
        work->state = WIFICLUB_STATE_POLL_SEAT_YES_NO;
    }

    return procState;
}







/*
 * Reads the yes/no answer for the seat change. Yes flips the seat and goes to
 * state 118. No goes back to the lobby.
 * WIFICLUB_GetStatusSeatFlag returns u8: this removes a second narrowing in the compiled code.
 */
int WIFICLUB_StatePollSeatYesNo(WifiClubWork *work, int procState)
{
    WifiClubActor *peerActor;
    int answer;
    peerActor = WIFICLUB_FindPeerActor(work, WIFICLUBACTOR_GetPickResult(&work->actorSys));
    GF_FONT_SetDefaultTextColor();
    answer = WIFICLUB_PollYesNoMenu(work);
    if (answer == -1) return procState;
    if (answer == 0) {
        WIFICLUB_SetStatusSeatFlag(work->localStatus, 1 - WIFICLUB_GetStatusSeatFlag(work->localStatus));
        WIFICLUB_SetStatusModeFlag(work->localStatus, WIFICLUB_GetStatusSeatFlag(work->localStatus));
        work->seatReply = 2 - work->session->ownSeat;
        work->state = WIFICLUB_STATE_REQUEST_JOIN_PARTNER;
    } else {
        work->connectionMode = 0;
        WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
        work->partnerIndex = -1;
        if (peerActor != 0) WIFICLUBACTOR_RestoreActorUpdate(&work->actorSys, peerActor);
        WIFICLUB_ResetOwnSeatStatus(work);
        WIFICLUB_DrawPlayerInfoWindow(work);
        work->state = WIFICLUB_STATE_LOBBY_MAIN;
    }
    WIFICLUB_ClearTalkWindow(work);
    return procState;
}








/* Returns the default state, or 2 when the net run state is 0. */
int WIFICLUB_ResolveNetRunState(int unused, int defaultState)
{
    int state = defaultState;

    if (sub_0203CD98() == 0) {
        state = 2;
    }

    return state;
}







/* Sets the own status kind and phase, then publishes it to the peers. */
void WIFICLUB_SetOwnStatusAndPublish(WifiClubWork *work, int kind, int phase)
{
    if (work->localStatus != 0) {
        if (kind == 1 && phase == 2) WIFICLUB_CopyZeroToDeviceAddr(work->localStatus);
        if (kind == 4 && phase < 3) func_02009B80(work->friendList, DWC_RAP_GetTargetFriendIndex());
        WIFICLUB_SetOwnStatusKindPhase(work, kind, phase);
        WIFICLUB_PublishOwnStatus(work);
    }
}







/*
 * Sets the kind and phase of the own status when they changed. It also changes
 * the net mode and the music volume, then redraws the info window.
 */
void WIFICLUB_SetOwnStatusKindPhase(WifiClubWork *work, int kind, int phase)
{
    int oldKind;
    int oldPhase;
    if (work->localStatus != 0) {
        oldKind = WIFICLUB_GetStatusKind(work, work->localStatus);
        oldPhase = WIFICLUB_GetStatusPhase(work, work->localStatus);
        if (oldKind != kind || oldPhase != phase) {
            WIFICLUB_ChangeNetMode(work, kind, phase);
            WIFICLUB_SetStatusActionState(work->localStatus, kind);
            WIFICLUB_SetStatusActionArg(work->localStatus, phase);
            if (!(phase == 5 && kind == 4)) {
                if (kind != 4) WIFICLUB_StartBgmFade(work, 127);
            }
        }
        WIFICLUB_DrawPlayerInfoWindow(work);
    }
}








/* Flips the own seat, stores it in the own status and publishes it. Returns the seat flag. */
u8 WIFICLUB_ToggleOwnSeat(WifiClubWork *work)
{
    work->session->ownSeat = 1 - work->session->ownSeat;
    WIFICLUB_SetStatusSeatFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_SetStatusModeFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_PublishOwnStatus(work);
    return WIFICLUB_GetStatusSeatFlag(work->localStatus);
}






/* Sets the music volume to 127 and writes the own seat back to the own status. */
void WIFICLUB_ResetOwnSeatStatus(WifiClubWork *work)
{
    WIFICLUB_StartBgmFade(work, 127);
    WIFICLUB_SetStatusSeatFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_SetStatusModeFlag(work->localStatus, work->session->ownSeat);
    WIFICLUB_PublishOwnStatus(work);
    WIFICLUB_GetStatusSeatFlag(work->localStatus);
}







/*
 * Closes the partner panel. It deletes the trainer actor, the touch bar and the
 * panel graphics, then re-opens the panel layer.
 */
void WIFICLUB_ClosePartnerPanel(WifiClubWork *work, int panelPlane)
{
    WIFICLUB_DeleteTrainerActor(work);
    WIFICLUB_DeleteTouchBar(work);
    WIFICLUB_LoadPanelGraphics(work);
    WIFICLUB_ResetSlotSelection(work);
    WIFICLUB_ReleaseSlotActors(work);
    WIFICLUBACTOR_HideMarker(&work->actorSys);
    WIFICLUB_OpenPanelOrRedrawPage(work, panelPlane);
}







/*
 * Closes the partner panel when the given slot id is the selected slot.
 */
void WIFICLUB_ClosePanelIfSlotSelected(WifiClubWork *work, int slotId, int procState)
{
    if (slotId == WIFICLUB_GetSelectedSlotPlusOne(work)) {
        WIFICLUB_ClosePartnerPanel(work, procState);
    }
}


/*
 * Closes the partner panel when a touch selection is active.
 * procState is live into the call, so the compiler loads the touchPhase offset in r2.
 */
void WIFICLUB_ClosePanelIfTouchActive(WifiClubWork *work, int procState)
{
    if (work->touchPhase != 0) {
        WIFICLUB_ClosePartnerPanel(work, procState);
    }
}


/*
 * Returns true when the button manager of the slot panel exists.
 */
BOOL WIFICLUB_IsSlotPanelOpen(WifiClubWork *work)
{
    if ((unsigned int)work->buttonMan != 0) {
        return 1;
    }

    return 0;
}


/*
 * Opens the slot panel: creates the button manager and word set, then builds
 * the windows and draws the first page.
 */
void WIFICLUB_OpenSlotPanel(WifiClubWork *work, int narc, int heapId)
{
    MI_CpuFill8(&work->detailWordSet, 0, 0xf4);
    BG_SYS_SetSubPlaneVisible(7, 1);
    BG_SYS_SetSubPlaneVisible(8, 0);
    work->buttonMan = BUTTON_MAN_Create(d_021C377C, WIFICLUB_OnSlotButtonEvent, work, heapId);
    work->detailWordSet = WORDSET_CreateDefault((u16)heapId);
    WIFICLUB_CreateSlotPanelWindows(work, (void *)narc, heapId);
    work->touchDirty = 1;
    WIFICLUB_EmptyHook(work);
    WIFICLUB_RedrawSlotPanels(work);
}


/*
 * Closes the slot panel: deletes the windows, the button manager and the word set.
 */
void WIFICLUB_CloseSlotPanel(WifiClubWork *work)
{
    if (WIFICLUB_IsSlotPanelOpen(work)) {
        WIFICLUB_DeleteSlotPanelWindows(work);
        BUTTON_MAN_Delete(work->buttonMan);
        work->buttonMan = 0;
        WORDSET_DeleteStrbufED04(work->detailWordSet);
        work->detailWordSet = 0;
        BG_SYS_SetSubPlaneVisible(1, 1);
        BG_SYS_SetSubPlaneVisible(14, 0);
    }
}


/*
 * Runs one frame of the slot panel. Follows the cursor to a new page, starts
 * the partner panel after the blink, and closes on a key or touch bar press.
 * Returns the selected slot plus one (0 when none).
 */
u8 WIFICLUB_UpdateSlotPanel(WifiClubWork *work, int heapId)
{
    u32 cursorAttr, belowAttr;
    cursorAttr = WIFICLUBACTOR_GetCursorTileAttr(&work->actorSys);
    belowAttr = WIFICLUBACTOR_GetCursorTileBelowAttr(&work->actorSys);
    if (belowAttr >= 3 && belowAttr <= 6) cursorAttr = belowAttr;
    if (cursorAttr >= 3 && cursorAttr <= 6 && work->page != cursorAttr - 3) {
        work->page = cursorAttr - 3;
        WIFICLUB_EmptyHook(work);
        work->pageRedraw = 1;
        work->touchDirty = 1;
    }
    if (work->touchPhase == 1) {
        work->touchPhase = 2;
        WIFICLUB_OpenPartnerPanelWithBg(work, heapId);
    }
    if (work->touchPhase == 0) {
        WIFICLUB_DeleteTrainerActor(work);
        WIFICLUB_DeleteTouchBar(work);
        WIFICLUB_LoadPanelGraphics(work);
        BUTTON_MAN_UpdateSlots(work->buttonMan);
        WIFICLUB_TickSlotBlink(work);
        if (work->pageRedraw == 1) {
            WIFICLUB_RedrawSlotPanels(work);
            work->pageRedraw = 0;
        }
    }
    /* The compiler needs the byte addition of 254 here (adds #0xfe) instead of a subtraction. */
    if ((u8)(work->touchPhase + 254) <= 1 && WIFICLUB_IsSlotPanelDismissed(work) == 1) {
        work->selectedSlotPlusOne = 0;
        work->cursorSlot = 0;
        work->pageRedraw = 1;
        work->touchDirty = 1;
        WIFICLUB_ClosePartnerPanel(work, heapId);
        work->touchPhase = 0;
        work->touchDirty = 1;
    }
    return work->selectedSlotPlusOne;
}


/*
 * Redraws the slot panel once when no touch selection is active and a redraw is pending.
 */
void WIFICLUB_RedrawSlotPanelIfPending(WifiClubWork *work)
{
    if (work->touchPhase != 0) {
        return;
    }

    if (work->pageRedraw != 1) {
        return;
    }

    WIFICLUB_RedrawSlotPanels(work);
    work->pageRedraw = 0;
}


/*
 * Returns 1 when the player dismisses the partner panel (touch bar button or
 * a key press). Returns 0 while the panel is in touchPhase 3.
 */
int WIFICLUB_IsSlotPanelDismissed(WifiClubWork *work)
{
    if (work->touchPhase == 3)
        return 0;
    if (work->touchBar != 0) {
        TOUCHBAR_Update(work->touchBar);
        if (TOUCHBAR_GetPressedButtonIdIfDone(work->touchBar) == 1)
            return 1;
    }
    if ((KEY_GetCont() & 0xf0) || (KEY_GetTrg() & 0x403))
        return 1;
    return 0;
}


/*
 * Returns the selected slot plus one (0 when no slot is selected).
 */
u8 WIFICLUB_GetSelectedSlotPlusOne(WifiClubWork *work)
{
    return work->selectedSlotPlusOne;
}


/*
 * Clears the slot selection and the touch state when the slot panel is open.
 */
void WIFICLUB_ResetSlotSelection(WifiClubWork *work)
{
    if (WIFICLUB_IsSlotPanelOpen(work) != 1) {
        return;
    }

    work->selectedSlotPlusOne = 0;
    work->cursorSlot = 0;
    work->touchPhase = 0;
    work->pageRedraw = 1;
    work->touchDirty = 1;
}


/*
 * Button manager callback. Selects the slot of the pressed button when it is
 * active (state 2), nothing is selected yet and the event is 0. Plays the select sound.
 */
void WIFICLUB_OnSlotButtonEvent(u32 buttonIndex, int event, WifiClubWork *work)
{
    u32 slotIndex;
    slotIndex = buttonIndex + (work->page << 3);
    /* Byte offset 0x8cc is the buttonState table. */
    if (*(u8 *)((u32)work + slotIndex + 0x8cc) == 2 && work->selectedSlotPlusOne == 0 && event == 0) {
        work->selectedSlotPlusOne = slotIndex + 1;
        GFL_USE_PlaySeDefaultVolume(1356);
    }
}


/*
 * Advances the blink of the selected slot by one step. After 16 steps it
 * clears the cursor and sets touchPhase to 1.
 */
void WIFICLUB_TickSlotBlink(WifiClubWork *work)
{
    if (work->selectedSlotPlusOne) {
        work->cursorSlot = d_021C3720[work->blinkStep];
        work->blinkStep++;
        work->pageRedraw = 1;
        if (work->blinkStep >= 16) {
            work->blinkStep = 0;
            work->cursorSlot = 0;
            work->touchPhase = 1;
        }
    }
}


/*
 * Loads the panel graphics from the archive and creates the bitmap windows:
 * eight slot windows (4 rows, 2 columns), two pair windows per slot, the name
 * window and the status window.
 * The window loop keeps row and column as separate locals to match the register use.
 */
void WIFICLUB_CreateSlotPanelWindows(WifiClubWork *work, void *narc, int heapId)
{
    int i;
    int j;
    int column;
    int row;

    i = 0;
    func_02049B68(narc, 6, 4, 0, 0x100, heapId);
    work->fileIndex = func_02049740(narc, 0xe, 4, 0, i, heapId);
    func_02049658(narc, 0xf, 6, 0x80, i, i, heapId);
    func_02049990(narc, 0x16, 4, 0, (u16)work->fileIndex, i, i, heapId);
    work->panelCharFile = func_02049EF4(narc, 0x17, 0, (void **)&work->panelCharData, heapId);
    WIFICLUB_AddTileOffsetToTileMap(work->panelCharData, 0x80);
    work->panelScreenFile = func_02049EF4(narc, 0x19, 0, (void **)&work->panelScreenData, heapId);
    WIFICLUB_AddTileOffsetToTileMap((u16 *)work->panelScreenData, 0x80);
    func_02049B40(0x17, 5, 4, 0xf << 5, 0x20, heapId);
    for (i = 0; i < 8; i++) {
        row = i % 4;
        column = i / 4;
        work->slotWin[i] = BMP_WIN_Create(7, (column << 4) + 4, row * 6 + 1, 9, 3, 0xf, 1);
        BMP_Clear(BMP_WIN_GetBmp(work->slotWin[i]), 0);
        BMP_WIN_TransferChars(work->slotWin[i]);

        for (j = 0; j < 2; j++) {
            work->pairWin[i][j] = BMP_WIN_Create(5, (column << 4) + 1 + j * 12, row * 6 + 1, 2, 3, 0xf, 1);
            BMP_Clear(BMP_WIN_GetBmp(work->pairWin[i][j]), 0);
            BMP_WIN_TransferChars(work->pairWin[i][j]);
        }
    }
    work->nameWin = BMP_WIN_Create(7, 1, 1, 0x1e, 2, 0xf, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->nameWin), 0);
    BMP_WIN_MakeScreen(work->nameWin);
    BMP_WIN_TransferChars(work->nameWin);
    work->statWin = BMP_WIN_Create(7, 1, 5, 0x1e, 0x11, 0xf, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->statWin), 0);
    BMP_WIN_MakeScreen(work->statWin);
    BMP_WIN_TransferChars(work->statWin);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(7);
}


/*
 * Deletes the bitmap windows of the slot panel and frees the two loaded files.
 */
void WIFICLUB_DeleteSlotPanelWindows(WifiClubWork *work)
{
    int i;
    int j;
    for (i = 0; i < 8; i++) {
        BMP_WIN_Delete(work->slotWin[i]);
        for (j = 0; j < 2; j++) BMP_WIN_Delete(work->pairWin[i][j]);
    }
    BMP_WIN_Delete(work->nameWin);
    BMP_WIN_Delete(work->statWin);
    func_020307B0(work->panelCharFile);
    func_020307B0(work->panelScreenFile);
}


/*
 * Adds tileOffset to each halfword of the tile map. The map has a 12 byte
 * header: two halfwords with the width and height in pixels (shifted right by
 * three to get tiles), then the tile data from +0x0C.
 * The header halfwords are read into locals first and shifted as u32: the
 * compiler needs this order and the cast to get lsrs and the same registers.
 */
void WIFICLUB_AddTileOffsetToTileMap(u16 *tileMap, u16 tileOffset)
{
    u16 *tiles = (u16 *)((u8 *)tileMap + 0xC);
    u16 pixelWidth = tileMap[0];
    u16 pixelHeight = tileMap[1];
    int i, j;
    int width = (u32)pixelWidth >> 3;
    int height = (u32)pixelHeight >> 3;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            tiles[i * width + j] += tileOffset;
        }
    }
}














/*
 * Sets the state of one panel slot (slotNumber is 1-based) and asks for a page redraw.
 */
void WIFICLUB_SetSlotState(WifiClubWork *work, int slotNumber, u8 state)
{
    /* Byte offset 0x8CB + slotNumber is buttonState[slotNumber - 1]. */
    *((u8 *)work + slotNumber + 0x8CB) = state;
    work->pageRedraw = 1;
}


/*
 * Clears the state of one panel slot (slotNumber is 1-based) and asks for a page redraw.
 */
void WIFICLUB_ClearSlotState(WifiClubWork *work, int slotNumber)
{
    *((u8 *)work + slotNumber + 0x8CB) = 0;
    work->pageRedraw = 1;
}


/*
 * Returns the state of one panel slot (slotNumber is 1-based). Zero means empty.
 */
u8 WIFICLUB_GetSlotState(WifiClubWork *work, int slotNumber)
{
    return *((u8 *)work + slotNumber + 0x8CB);
}


/*
 * Opens the partner panel when touch is active. Otherwise it marks the
 * panel dirty and redraws the page.
 */
void WIFICLUB_OpenPanelOrRedrawPage(WifiClubWork *work, int panelArg)
{
    if (work->touchPhase != 0) {
        WIFICLUB_OpenPartnerPanelWithBg(work, panelArg);
        return;
    }

    work->touchDirty = 1;
    WIFICLUB_RedrawSlotPanels(work);
}


/*
 * Marks the panel dirty and asks for a page redraw on the next update.
 */
void WIFICLUB_RequestPanelRedraw(WifiClubWork *work)
{
    work->touchDirty = 1;
    work->pageRedraw = 1;
}


/*
 * Empty hook. The original is a bare return.
 */
void WIFICLUB_EmptyHook(WifiClubWork *work)
{
}


/*
 * Redraws the eight slot panels of the current page on the sub screen.
 * It redraws all panels when the dirty flag is set, else only the
 * selected and hovered ones.
 */
void WIFICLUB_RedrawSlotPanels(WifiClubWork *work)
{
    int i;
    int forceRedraw;
    int slotNumber;
    int panelStyle;
    int frame;
    int col;
    int row;
    int isHighlighted;

    if (work->touchDirty == 1) {
        work->touchDirty = 0;
        forceRedraw = 1;
        BG_SYS_FreeSlot(7);
    } else {
        forceRedraw = 0;
    }
    for (i = 0; i < 8; i++) {
        slotNumber = i + work->page * 8 + 1;
        if (*((u8 *)work + 0x8CB + slotNumber) != 0) {
            if (func_02009864(work->friendList, slotNumber - 1, 9) == 0) {
                panelStyle = 0;
            } else {
                panelStyle = 1;
            }
        } else {
            panelStyle = 2;
        }
        col = i / 4;
        row = i % 4;
        if (slotNumber == work->selectedSlotPlusOne) {
            frame = work->cursorSlot;
        } else {
            frame = 0;
        }
        if (slotNumber == work->selectedSlotPlusOne || slotNumber == work->hoverSlotPlusOne) {
            isHighlighted = 1;
        } else {
            isHighlighted = 0;
        }
        if (forceRedraw == 1 || isHighlighted == 1) {
            WIFICLUB_DrawSlotFrame(work, (u8)(col * 16), (u8)(row * 6), (u8)panelStyle, (u8)frame);
            if (panelStyle != 2) {
                WIFICLUB_PrintSlotName(work, work->slotWin[i], slotNumber, frame, i);
                BMP_WIN_MakeScreen(work->slotWin[i]);
                WIFICLUB_DrawSlotStatusIcons(work, work->pairWin[i], slotNumber, frame, col * 16, row * 6);
            } else {
                int j;
                BMP_Clear(BMP_WIN_GetBmp(work->slotWin[i]), 0);
                BMP_WIN_TransferChars(work->slotWin[i]);
                for (j = 0; j < 2; j++) {
                    BMP_Clear(BMP_WIN_GetBmp(work->pairWin[i][j]), 0);
                    BMP_WIN_TransferChars(work->pairWin[i][j]);
                }
            }
        }
    }
    func_02041B6C(7);
    func_02041B6C(6);
    BG_SYS_SetSubPlaneVisible(2, 1);
    BG_SYS_SetSubPlaneVisible(8, 1);
}


/*
 * Copies the frame graphic of one slot panel from the panel character data to the sub screen.
 */
void WIFICLUB_DrawSlotFrame(WifiClubWork *work, u32 tileX, u32 tileY, u32 panelStyle, u8 frame)
{
    u16 srcX;
    u16 srcY;
    if (panelStyle == 2) {
        srcX = 0;
        srcY = 0x12;
    } else {
        srcX = (u16)(panelStyle << 4);
        srcY = (u16)(frame * 6);
    }
    BG_SYS_DrawTileEx(6, tileX, tileY, 0x10, 6, (u8 *)work->panelCharData + 0xC, srcX, srcY, 0x20, 0x18);
}


/*
 * Prints the friend name of one slot panel into its window.
 */
void WIFICLUB_PrintSlotName(WifiClubWork *work, void *window, int slotNumber, int frame, int slotIndex)
{
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    WIFICLUB_SetFriendNameWord(work, slotNumber - 1);
    func_02045CAC(work->msgBank, 33, work->rawText);
    WORDSET_CopyTaggedText(work->detailWordSet, work->shortText, work->rawText);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 2, 8, work->shortText, work->textFont);
    BMP_WIN_TransferChars(window);
}


/*
 * Draws the phase icon and the status icon of one slot panel.
 * The icon tiles move by 16 when the panel is the selected one.
 */
void WIFICLUB_DrawSlotStatusIcons(WifiClubWork *work, void *pairWins, int slotNumber, int isSelected, int tileX, int tileY)
{
    int offset;
    void *status;
    int kind;
    int phase;
    int iconTile;
    offset = 0;
    if (isSelected != 0) offset = 16;
    status = WIFICLUB_GetFriendStatus(slotNumber - 1);
    kind = WIFICLUB_GetStatusKind(work, status);
    phase = WIFICLUB_GetStatusPhase(work, status);
    WIFICLUB_DrawPhaseIcon(&work->bgLoad, 6, (u8)(tileX + 2), (u8)(tileY + 2), kind, (int)phase, offset);
    if (WIFICLUB_GetStatusModeFlag(status)) iconTile = 15;
    else iconTile = 11;
    WIFICLUB_DrawTileBlock(&work->bgLoad, 6, tileX + 12, tileY + 2, (int)(iconTile + offset), 0);
    func_02041B6C(7);
}


/*
 * Loads the name of one friend and sets it as word 0 of the detail word set.
 * Does nothing for friend index -1.
 */
void WIFICLUB_SetFriendNameWord(WifiClubWork *work, int friendIndex)
{
    int gender;
    if (friendIndex != -1) {
        gender = func_02009864(work->friendList, friendIndex, 9);
        func_020099E4(work->friendList, friendIndex, work->rawText);
        WORDSET_SetSlotTag(work->detailWordSet, 0, work->rawText, gender, 1, 2);
    }
}


/*
 * Returns the status record of one friend (an ov009 function).
 */
WifiClubPlayerStatus *WIFICLUB_GetFriendStatus(int friendIndex) { return DWC_RAP_GetFriendStatusData(friendIndex); }


/*
 * Tail call thunk into ov009. Returns the connection status of one friend.
 */
unsigned char WIFICLUB_GetFriendConnectionStatus(int friendIndex)
{
    return DWC_RAP_GetFriendStatus(friendIndex);
}


/*
 * Adds the net commands, then runs an arm9 check on the friend index.
 */
int WIFICLUB_AddNetCommandsAndCheckFriend(WifiClubWork *work, int friendIndex)
{
    WIFICLUBACTOR_AddNetCommands(work);
    return sub_0203C2B0(friendIndex);
}


/*
 * Turns the touch bar on once. Shows the first message when showMessage is 1.
 */
void WIFICLUB_EnableTouchBar(WifiClubWork *work, int showMessage)
{
    if (work->touchBarOn != 0) {
        return;
    }

    work->touchBarOn = 1;
    WIFICLUBACTOR_SetMode(&work->actorSys, 1);

    if (showMessage == 1) {
        WIFICLUB_ShowMessage(work, 6, 0);
    }
}


/*
 * Turns the touch bar off when it is on. Clears the talk window and the connection mode.
 */
void WIFICLUB_DisableTouchBar(WifiClubWork *work)
{
    if (work->touchBarOn != 1) {
        return;
    }

    work->touchBarOn = 0;
    WIFICLUB_ClearTalkWindow(work);
    WIFICLUBACTOR_SetMode(&work->actorSys, 0);
    work->connectionMode = 0;
}


/*
 * Steps the background music volume fade by one frame.
 * Returns 1 when no fade is running, else 0.
 */
int WIFICLUB_UpdateBgmFade(WifiClubWork *work)
{
    int remaining;
    int target;
    int diff;
    if (work->bgmFadeFrames != 0) {
        --work->bgmFadeFrames;
        remaining = work->bgmFadeFrames;
        if (remaining != 0) {
            target = work->bgmVolumeTarget;
            diff = target - work->bgmVolumeFrom;
            if (diff < 0) work->bgmVolume = target + (-diff / 6) * remaining;
            else work->bgmVolume = target - (diff / 6) * remaining;
            GFL_USE_SetBgmTrackVolume(0xffff, work->bgmVolume);
            return 0;
        }
        work->bgmVolume = work->bgmVolumeTarget;
        GFL_USE_SetBgmTrackVolume(0xffff, work->bgmVolumeTarget);
    }
    return 1;
}


/*
 * Starts a 6 frame fade of the background music volume to targetVolume.
 */
void WIFICLUB_StartBgmFade(WifiClubWork *work, int targetVolume)
{
    if (work->bgmVolumeTarget != targetVolume) {
        work->bgmVolumeFrom = work->bgmVolume;
        work->bgmFadeFrames = 6;
        work->bgmVolumeTarget = targetVolume;
        GFL_USE_SetPlayerVolumes(targetVolume, 0x3f);
        PM_VOICE_SetMasterVolume(targetVolume);
    }
}


/*
 * Sets the start volume of the background music: 0x2A for kind 4, else 0x7F.
 */
void WIFICLUB_InitBgmVolume(WifiClubWork *work, int entryKind)
{
    if (entryKind == 4) {
        work->bgmVolumeTarget = 0x2A;
    } else {
        work->bgmVolumeTarget = 0x7F;
    }

    work->bgmVolumeFrom = work->bgmVolumeTarget;
}


/*
 * Proc init handler. Allocates and fills the work area (0x1360 bytes) from the
 * session record, builds the screen and restarts the net layer when it runs.
 */
int WIFICLUB_ProcInit(void *procObj, int unused, WifiClubSession *session)
{
    WifiClubWork *work;
    GFL_HEAP_CreateChildHeap(1, 0x8021, 0xa4000);
    work = PROCSYS_AllocProcWork(procObj, 0x1360, 0x21);
    MI_CpuFill8(work, 0, 0x1360);
    GFL_NET_SetUserArg((u32)work);
    work->localStatus = session->localStatus;
    work->saveData = session->saveData;
    work->gameData = session->gameData;
    work->savedRegulation = WIFICLUB_LoadSavedRegulation(work->gameData);
    work->party = GAME_DATA_GetMyParty(work->gameData);
    work->friendList = GAME_DATA_GetField1A0(work->gameData);
    work->myStatus = func_0200873C(session->saveData);
    work->entryMode = session->isFriendMatch;
    work->connectionMode = session->connectionMode;
    if (session->isFriendMatch == 1) {
        session->isFriendMatch = 0;
        WIFICLUB_InitBgmVolume(work, 4);
    } else if (session->isFriendMatch != 0) {
        WIFICLUB_InitBgmVolume(work, 4);
    } else {
        WIFICLUB_InitBgmVolume(work, 1);
    }
    work->sceneKind = 0;
    work->partnerIndex = -1;
    work->session = session;
    BG_SYS_SetMainPlaneVisible(15, 0);
    BG_SYS_SetSubPlaneVisible(15, 0);
    WIFICLUB_CreateTextBuffers(work);
    work->state = WIFICLUB_STATE_ENTER_CLUB;
    WIFICLUB_InitScreen(work);
    if (session->isFriendMatch == 0) WIFICLUB_BuildOwnStatus(work, 1, 2);
    if (GFL_NET_GetRunState() != 0) {
        WIFICLUBACTOR_AddNetCommands(work);
        GFL_NET_RestartWithDefaultTimeout(1, 0x21);
    }
    return 1;
}


/*
 * Proc main handler, runs every frame. Handles net errors, calls the handler of
 * the current state and runs the sprite and print queues.
 * Returns 1 when the proc ends.
 */
int WIFICLUB_ProcMain(int procTask, int *procState, int unused, WifiClubWork *work)
{
    u8 fontLetter, fontShadow, fontBack;
    WifiClubStateHandler handler;
    if (GFL_NET_GetRunState() != 0) {
        switch (DWC_RAPCOMMON_HandleNetError(1, 1)) {
        case 4:
            WIFICLUB_DeleteMenuAndIcons(work);
            WIFICLUB_DeleteAllWindows(work);
            GFL_NET_SetAutoExit(0);
            GFL_NET_SetLoginOption(0);
            WIFICLUB_SetOwnStatusAndPublish(work, 1, 2);
            work->counter = 20;
            work->state = WIFICLUB_STATE_WATCH_CONNECTION;
            return 0;
        case 2:
            WIPE_SetBrightnessFadeOut(0, 0);
            WIPE_SetBrightnessFadeOut(1, 0);
            work->sceneKind = 1;
            return 1;
        }
    }
    if (func_0200FB24() == 0) {
        handler = gWifiClubStateHandlers[work->state];
        if (handler != 0) {
            *procState = handler(work, *procState);
            if (*procState == 2) {
                WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x21);
                return 1;
            }
        }
    }
    if (work->clactUnit != 0) CLACT_DrawSystem(work->clactUnit);
    if (work->msgPrintQueue != 0) {
        GF_FONT_GetTextColor(&fontLetter, &fontShadow, &fontBack);
        GF_FONT_SetTextColor(1, 2, 15);
        TCBL_Main(work->tcbl);
        GF_FONT_SetTextColor(fontLetter, fontShadow, fontBack);
        PRINTSYS_QUE_Main(work->msgPrintQueue);
    }
    if (work->menuPrintQueue != 0) PRINTSYS_QUE_Main(work->menuPrintQueue);
    WIFICLUB_UpdateBgmFade(work);
    return 0;
}


/*
 * Proc exit handler. Waits for the music fade and the wipe, writes the results
 * back to the session record and frees the work area.
 * Returns 1 when done.
 */
int WIFICLUB_ProcExit(void *procTask, int unused, WifiClubSession *session, WifiClubWork *work)
{
    if (!WIFICLUB_UpdateBgmFade(work)) return 0;
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) WIFICLUBACTOR_RemoveNetCommands(work);
    session->connectionMode = work->connectionMode;
    if (work->regulationData) {
        REGULATION_Copy(work->regulationData, session->regulation);
        func_020307B0(work->regulationData);
        work->regulationData = 0;
    }
    WIFICLUB_DeleteMenuAndIcons(work);
    WIFICLUB_ExitScreen(work);
    session->visitedSeat = work->selectedPlusOne;
    session->isFriendMatch = work->sceneKind;
    if (GFL_NET_GetRunState()) session->targetFriendIndex = DWC_RAP_GetTargetFriendIndex();
    WIFICLUB_FreeRegulation(work->savedRegulation);
    WIFICLUB_DeleteTextBuffers(work);
    func_020315D4(procTask);
    GFL_HEAP_DeleteChecked(33);
    return 1;
}


/*
 * Returns the action state of a status record.
 */
u8 WIFICLUB_GetStatusActionState(WifiClubPlayerStatus *status)
{
    return status->actionState;
}


/*
 * Sets the action state of a status record.
 */
void WIFICLUB_SetStatusActionState(WifiClubPlayerStatus *status, u8 actionState)
{
    status->actionState = actionState;
}


/*
 * Returns the action argument of a status record.
 */
u8 WIFICLUB_GetStatusActionArg(WifiClubPlayerStatus *status)
{
    return status->actionArg;
}


/*
 * Sets the action argument of a status record.
 */
void WIFICLUB_SetStatusActionArg(WifiClubPlayerStatus *status, u8 actionArg)
{
    status->actionArg = actionArg;
}


/*
 * Returns the seat flag (bit 1 of the byte at +0x1B) of a status record.
 * The bitfield in an unsigned char gives the matching ldrb and shifts.
 */
u8 WIFICLUB_GetStatusSeatFlag(WifiClubPlayerStatus *status)
{
    return status->seatFlag;
}


/*
 * Sets the seat flag of a status record.
 */
void WIFICLUB_SetStatusSeatFlag(WifiClubPlayerStatus *status, u8 seatFlag)
{
    status->seatFlag = seatFlag;
}


/*
 * Returns 1 when the peer address of status equals the device address of peerStatus.
 */
BOOL WIFICLUB_IsPeerAddrOfStatus(WifiClubPlayerStatus *status, WifiClubPlayerStatus *peerStatus)
{
    if (GF_STANDARD_CompareBytes(status->peerAddr, peerStatus->deviceAddr, 6) == 0) {
        return 1;
    }
    return 0;
}


/*
 * Counts one change on status and runs an arm9 routine on the peer address of
 * peer and the device address of status.
 */
void WIFICLUB_CountChangeAndCopyPeerAddr(WifiClubPlayerStatus *status, WifiClubPlayerStatus *peer)
{
    status->changeCount++;
    MI_CpuCopy8(peer->peerAddr, status->deviceAddr, 6);
}


/*
 * Runs the same arm9 routine with a zero address and the device address of status.
 */
int WIFICLUB_CopyZeroToDeviceAddr(WifiClubPlayerStatus *status)
{
    u8 zeroAddr[6] = {0, 0, 0, 0, 0, 0};
    return MI_CpuCopy8(zeroAddr, status->deviceAddr, 6);
}


/*
 * Runs an arm9 routine on the peer address of status.
 */
void WIFICLUB_RunPeerAddrRoutine(WifiClubPlayerStatus *status) { OS_GetMacAddress(status->peerAddr); }


/*
 * Returns the mode flag (bit 4 of the byte at +0x1B) of a status record.
 */
int WIFICLUB_GetStatusModeFlag(WifiClubPlayerStatus *status)
{
    return status->modeFlag;
}


/*
 * Sets the mode flag of a status record.
 */
void WIFICLUB_SetStatusModeFlag(WifiClubPlayerStatus *status, u8 modeFlag)
{
    status->modeFlag = modeFlag;
}


/*
 * Returns the change count of a status record.
 */
u8 WIFICLUB_GetStatusChangeCount(WifiClubPlayerStatus *status)
{
    return status->changeCount;
}
