/*
 * file:     pokemontrade_proc.c
 * unit:     yes
 * function: POKETRADE_PROC_ResetTouchbarBackButton, POKETRADE_PROC_IsMailBoxFull, POKETRADE_PROC_ClearNetAutoExit, POKETRADE_PROC_IsMonValid, POKETRADE_PROC_GetStoredBoxIndex, POKETRADE_PROC_IsNetSession, POKETRADE_PROC_IncrementTimer, POKETRADE_PROC_IsHostSide, POKETRADE_PROC_IsWifiMode, POKETRADE_PROC_GetBoxIndexForSlot, POKETRADE_PROC_GetSlotIndexInBox, POKETRADE_PROC_RequestBoxRedraw, POKETRADE_PROC_UpdateDragState, POKETRADE_PROC_UpdateDragIcon, POKETRADE_PROC_ClearDragIcon, POKETRADE_PROC_ShowDragIcon, POKETRADE_PROC_BeginDrag, POKETRADE_PROC_LoadSlotMon, POKETRADE_PROC_LoadSlotMonAlt, POKETRADE_PROC_GetSlotMonPtr, POKETRADE_PROC_StepNone, POKETRADE_PROC_SetStep, POKETRADE_PROC_GetPlayerMonPtr, POKETRADE_PROC_GetPlayerMonPtrAlt, POKETRADE_PROC_GetNetIdOffset, POKETRADE_PROC_RecvPlayerMonA, POKETRADE_PROC_GetSideValue, POKETRADE_PROC_SetSideValue, POKETRADE_PROC_GetSideMon, POKETRADE_PROC_RecvMonCopy, POKETRADE_PROC_RecvMonChunkCommon, POKETRADE_PROC_RecvMonChunk0, POKETRADE_PROC_RecvMonChunk1, POKETRADE_PROC_RecvMonChunk2, POKETRADE_PROC_RecvOfferMonCommon, POKETRADE_PROC_RecvOfferMon0, POKETRADE_PROC_RecvOfferMon1, POKETRADE_PROC_RecvOfferMon2, POKETRADE_PROC_RecvPlayerFlag, POKETRADE_PROC_RecvPeerSelection, POKETRADE_PROC_RecvPeerValue, POKETRADE_PROC_RecvPeerFlags, POKETRADE_PROC_RecvPeerState, POKETRADE_PROC_RecvTradeSummary, POKETRADE_PROC_RecvStateByte, POKETRADE_PROC_RecvPeerByte, POKETRADE_PROC_RecvPeerWord, POKETRADE_PROC_RecvPeerWordB, POKETRADE_PROC_RecvPeerHalf, POKETRADE_PROC_RecvPeerByteB, POKETRADE_PROC_RecvIgnoredA, POKETRADE_PROC_RecvPeerByteC, POKETRADE_PROC_RecvIgnoredB, POKETRADE_PROC_RecvIgnoredC, POKETRADE_PROC_StepWaitWipeEnd, POKETRADE_PROC_StepBeginWipeOut, POKETRADE_PROC_SetSideMon, POKETRADE_PROC_ClearSideMon, POKETRADE_PROC_IsSelfMonReady, POKETRADE_PROC_IsSelectedOfferSlot, POKETRADE_PROC_IsMonBadEggOrInvalid, POKETRADE_PROC_IsCurrentSideMonInvalid, POKETRADE_PROC_IsOtherSideMonInvalid, POKETRADE_PROC_IsMonTradeable, POKETRADE_PROC_BuildPartyPacket, POKETRADE_PROC_ShowIntroMessage, POKETRADE_PROC_PlaceCursorIcon, POKETRADE_PROC_StepReturnFromSummary, POKETRADE_PROC_StepMain, POKETRADE_PROC_StepAfterSummaryWipe, POKETRADE_PROC_StepMainMenuChoice, POKETRADE_PROC_StepShowTradeSummary, POKETRADE_PROC_StepOpenMainMenu, POKETRADE_PROC_StepWaitSync20, POKETRADE_PROC_StepStartSync20, POKETRADE_PROC_StepIntro, POKETRADE_PROC_StepSendIntroReady, POKETRADE_PROC_StepMenuChoice, POKETRADE_PROC_StepOpenMenu, POKETRADE_PROC_StepSendPartyBoxSelected, POKETRADE_PROC_HideTouchbarButtons, POKETRADE_PROC_SetDragTarget, POKETRADE_PROC_PollGridTouch, POKETRADE_PROC_PollGridTouchDrag, POKETRADE_PROC_StepWaitKeyAfterMessage, POKETRADE_PROC_ShowCancelMessage, POKETRADE_PROC_ShowSelectMessage, POKETRADE_PROC_ShowPeerSummary, POKETRADE_PROC_StepAddSelectedOffer, POKETRADE_PROC_StepSendAddOffer, POKETRADE_PROC_StepApplyAddOffer, POKETRADE_PROC_StepSendApplyAddOffer, POKETRADE_PROC_StepWaitTouchReleasePeer, POKETRADE_PROC_StepPeerSummaryMenu, POKETRADE_PROC_StepOpenPeerSummary, POKETRADE_PROC_StepSendCursorChoice, POKETRADE_PROC_StepWaitCursorSync, POKETRADE_PROC_StepResolveCursorResult, POKETRADE_PROC_StepRebuildTradeScene, POKETRADE_PROC_StepRestoreBrowseScene, POKETRADE_PROC_StepWaitThenRestoreScene, POKETRADE_PROC_StepBeginWipeToRestore, POKETRADE_PROC_StepWaitSyncThenWipe, POKETRADE_PROC_StepSendTradeData, POKETRADE_PROC_StepBuildTradeRecord, POKETRADE_PROC_StepBuildMarkingTable, POKETRADE_PROC_StepSendBoxInfo, POKETRADE_PROC_StepLoadBoxIconGfx, POKETRADE_PROC_StepWaitNetSync22, POKETRADE_PROC_StepAfterWipeLoadBox, POKETRADE_PROC_StepRestartNetSession, POKETRADE_PROC_StepResetForNewRound, POKETRADE_PROC_StepWaitMessageThenResolve, POKETRADE_PROC_StepSendNewRound, POKETRADE_PROC_StepClearOffersNewRound, POKETRADE_PROC_StepWaitMessageThenClear, POKETRADE_PROC_StepShowWaitMessageA, POKETRADE_PROC_StepSendContinue, POKETRADE_PROC_StepSendStartRound, POKETRADE_PROC_StepSummaryMenuChoice, POKETRADE_PROC_SendSideMon, POKETRADE_PROC_StepOpenSummaryMenu, POKETRADE_PROC_StepShowSummaryMessage, POKETRADE_PROC_StepSlideInSubScreen, POKETRADE_PROC_FindMatchingBoxIcon, POKETRADE_PROC_StepCloseSubScreenDone, POKETRADE_PROC_StepExitSubScreen, POKETRADE_PROC_StepWaitCursorFade, POKETRADE_PROC_StepSubScreenList, POKETRADE_PROC_StepOpenSubScreen, POKETRADE_PROC_StepBeginOpenSubScreen, POKETRADE_PROC_GetSlotPosition, POKETRADE_PROC_IsSlotVisible, POKETRADE_PROC_PollGridKeys, POKETRADE_PROC_RedrawAndSyncGrid, POKETRADE_PROC_DragScrollGrid, POKETRADE_PROC_StepWaitBrowseRelease, POKETRADE_PROC_StepClearPeerSelection, POKETRADE_PROC_StepBeginBrowse, POKETRADE_PROC_StepResetGrid, POKETRADE_PROC_StepEnterBrowsing, POKETRADE_PROC_UpdateTouchbarButtons, POKETRADE_PROC_StepRebuildBrowseScene, POKETRADE_PROC_StepConfirmSendOffer, POKETRADE_PROC_StepSendOfferConfirm, POKETRADE_PROC_StepWaitIconFlight, POKETRADE_PROC_IsTradeTargetValid, POKETRADE_PROC_StepPeerSelectAction, POKETRADE_PROC_StepBrowseGrid, POKETRADE_PROC_StepTouchbarAction, POKETRADE_PROC_StepWaitKeyThenBrowse, POKETRADE_PROC_InitMcssSystem, POKETRADE_PROC_ExitMcssSystem, POKETRADE_PROC_InitDisplay, POKETRADE_PROC_ExitDisplay, POKETRADE_PROC_LoadSceneResources, POKETRADE_PROC_VBlank, POKETRADE_PROC_SetupGameData, POKETRADE_PROC_FreeMons, POKETRADE_PROC_SetupBoxCounts, POKETRADE_PROC_BuildTradeRecords, POKETRADE_PROC_DeleteAllResources, POKETRADE_PROC_ExitBgm, POKETRADE_PROC_AllocTradeWork, POKETRADE_PROC_InitTradeWork, POKETRADE_PROC_StartRequest2, POKETRADE_PROC_StartRequest0, POKETRADE_PROC_StartRequest1, POKETRADE_PROC_StartRequest3, POKETRADE_PROC_SetupMcssPokemon, POKETRADE_PROC_StartRequest4, POKETRADE_PROC_StartRequest7, POKETRADE_PROC_StartRequest8, POKETRADE_PROC_StartRequest6, POKETRADE_PROC_Main, POKETRADE_PROC_Exit, POKETRADE_PROC_ClampScrollColumn, POKETRADE_PROC_SetSyncRange, POKETRADE_PROC_UpdatePickedIcon, POKETRADE_PROC_CanTradeMon, POKETRADE_PROC_TickWifiTimer
 * address:  0x021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pokemontrade_proc.c, pokemontrade_3d.c by tools/splitfile.py.
 *
 * symbols:
 *   TOUCHBAR_ResetAndEnableButton 0x021B65B4 thumb ov067
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   MAIL_GetBox 0x02008FEC thumb
 *   MAIL_FindEmptySlot 0x02009020 thumb
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   POKETRADE_2D_DeleteFloatingIconActor  0x021E66E8  thumb  ov119
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   POKETRADE_2D_SetIconObjMode  0x021E4AB8  thumb  ov119
 *   POKETRADE_2D_CreateFloatingIconActor  0x021E64DC  thumb  ov119
 *   BOX_SAVEDATA_GetPokemon  0x02007A18  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 *   POKETRADE_NEGO_ShowOfferSlotMon 0x021DF918 thumb ov119
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 *   MYSTATUS_GetArea  0x02008570  thumb
 *   MYSTATUS_GetLanguage  0x02008564  thumb
 *   MYSTATUS_SetNationAndArea  0x02008574  thumb
 *   NATION_AREA_SanitizeNation  0x02025C1C  thumb
 *   NATION_AREA_SanitizeArea  0x02025C30  thumb
 *   COMM_HISTORY_InsertIfNationSet  0x0202EB7C  thumb
 *   POKETRADE_2D_DeleteOfferIconActor 0x021E62D4 thumb ov119
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   POKETRADE_NEGO_FlashMarker 0x021DF8A0 thumb ov119
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssFlipped  0x021E36A8  thumb  ov119
 *   POKETRADE_SAVE_DrawOfferCardWindow  0x021E1B14  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferCardWindow  0x021E2438  thumb  ov119
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   POKE_TOOL_HasNoHmMove 0x0202F738 thumb
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   UI_GetInputMode 0x020355C4 arm
 *   POKETRADE_2D_PlaceTouchbarActors 0x021E5B6C thumb ov119
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   gCursorIconPos0 0x021E7580 data a2
 *   gCursorIconPos1 0x021E757C data a2
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   POKETRADE_SAVE_CloseSummaryPage 0x021E1CE8 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   gMainMenuHitArea 0x021E75F0 data a4
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   POKETRADE_SAVE_OpenSummaryScreen 0x021E1D68 thumb ov119
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   gMainMenuLayout 0x021E75E4 data
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   gOpenMenuPos 0x021E7584 data a4
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   POKETRADE_2D_HitTestBoxIcons 0x021E51A4 thumb ov119
 *   POKETRADE_NEGO_StepSendOfferRemoval 0x021DF708 thumb ov119
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 *   POKETRADE_SAVE_CloseSummaryWindow 0x021E2484 thumb ov119
 *   POKETRADE_SAVE_DrawSummaryPage 0x021E1E00 thumb ov119
 *   GFL_HEAP_Free 0x020307B0 arm
 *   POKETRADE_NEGO_StepShowCancelMessage 0x021DF5D8 thumb ov119
 *   APP_TASKMENU_IsDecide 0x02027A20 thumb
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   APP_TASKMENU_SetCursorActive 0x02027A08 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 *   POKETRADE_2D_ClearSummaryBackground 0x021E4174 thumb ov119
 *   gPeerSummaryPos 0x021E7594 data a4
 *   POKETRADE_IRCDEMO_StepStartCompare 0x021D4B88 thumb ov117
 *   POKETRADE_DEMO_MIDDLE_StepStartCompare 0x021D6F2C thumb ov118
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   POKETRADE_NEGO_ExitMarkers 0x021DF904 thumb ov119
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   POKETRADE_NEGO_InitOfferMarkers 0x021DF78C thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_3D_UploadCubeTextures 0x021E31FC thumb ov119
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   POKETRADE_2D_BuildMarkingTablesFrom 0x021E3E00 thumb ov119
 *   POKETRADE_2D_LoadBoxIconGfx 0x021E5098 thumb ov119
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 *   gSummaryMenuPos 0x021E758C data a4
 *   POKETRADE_2D_GetScrollColumn 0x021E4DBC thumb ov119
 *   POKETRADE_2D_IsBoxIconMatch 0x021E4AA4 thumb ov119
 *   POKETRADE_2D_ClearSubScreen 0x021E5D84 thumb ov119
 *   POKETRADE_2D_FadePaletteAll 0x021E71E0 thumb ov119
 *   POKETRADE_2D_DeleteCursorActor 0x021E7058 thumb ov119
 *   POKETRADE_2D_ClearCursorIfDisabled 0x021E707C thumb ov119
 *   gSubScreenHitAreas 0x021E8044 data a1
 *   POKETRADE_2D_CreateCursorActor 0x021E6FD4 thumb ov119
 *   POKETRADE_SAVE_OpenMessageWindow 0x021E0EF4 thumb ov119
 *   POKETRADE_2D_LoadSubScreenGfx 0x021E5C64 thumb ov119
 *   KEY_GetRepeat 0x0203633C arm
 *   POKETRADE_2D_GetVisibleColumnRange 0x021E4E0C thumb ov119
 *   gScrollSnapPos 0x021E7FE0 data a4
 *   POKETRADE_2D_DrawBoxGridScreen 0x021E42B4 thumb ov119
 *   POKETRADE_2D_DrawBoxNames 0x021E4598 thumb ov119
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_NET_IsNetTypeWifi 0x0203D29C arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   POKETRADE_2D_UpdateIconFlight 0x021E665C thumb ov119
 *   KEY_GetCont 0x0203630C arm
 *   POKETRADE_NEGO_PollMarkerTouch 0x021DF7F0 thumb
 *   POKETRADE_2D_PlaceBoxIconActors 0x021E4A1C thumb
 *   POKETRADE_2D_StartIconFlight 0x021E6544 thumb
 *   POKETRADE_2D_InitG3DSystem 0x021E55BC thumb ov119
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   POKETRADE_2D_InitDisplayAndClact 0x021E53F8 thumb ov119
 *   POKETRADE_2D_SetupMainBgs 0x021E5430 thumb ov119
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   POKETRADE_2D_RegisterIconCharResources 0x021E4068 thumb ov119
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetMyStatusPlayer 0x02012950 thumb
 *   gGameDataAllocTag 0x021E80B0 data a4
 *   BOX_SAVEDATA_GetUsableBoxCount 0x020076A4 thumb
 *   POKETRADE_2D_DeleteAllOfferIconActors 0x021E64B8 thumb ov119
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_NEGO_ResetMarkers 0x021DF8E0 thumb ov119
 *   POKETRADE_2D_DeleteBoxWindows 0x021E4570 thumb ov119
 *   POKETRADE_2D_DeletePickedIconActor 0x021E69A4 thumb ov119
 *   POKETRADE_NEGO_UpdateOfferMarkers 0x021DF7D0 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows 0x021E2680 thumb ov119
 *   POKETRADE_2D_DeleteAllBoxIcons 0x021E4888 thumb ov119
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   POKETRADE_2D_DeleteOfferIcons 0x021E48E0 thumb ov119
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   POKETRADE_SAVE_DeleteMessageResources 0x021E11A8 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_2D_FreeBackgroundPalette 0x021E3F08 thumb ov119
 *   POKETRADE_2D_FreeMainResources 0x021E4000 thumb ov119
 *   POKETRADE_2D_ExitSubBgs 0x021E57A4 thumb ov119
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_HEAP_RegisterBlockHeap 0x02030678 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   gTradeWorkHeapName 0x021E8560 data a4
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gNetCommandTable 0x021E7614 data a4
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   POKETRADE_3D_Init3DScene 0x021E30EC thumb ov119
 *   POKETRADE_SAVE_StepSaveCancelNotice 0x021E0B34 thumb ov119
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   POKETRADE_3D_AddPokemonMcssPlain 0x021E36C8 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   FADE_Start 0x0204E720 arm
 *   POKETRADE_DEMO_UP_StepStartDownScene 0x021D59B0 thumb ov118
 *   POKETRADE_DEMO_UP_StepStartCompare 0x021D4AB4 thumb ov118
 *   BEACON_STATUS_IsLocked 0x020275DC thumb
 *   POKETRADE_NEGO_TickMarkerTimers 0x021DF868 thumb ov119
 *   CLACT_DrawSystem 0x0204A600 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   GF_FONT_GetTextColor 0x0201DE00 thumb
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   POKETRADE_NEGO_TickOfferSlotTimers 0x021DF978 thumb ov119
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   POKETRADE_3D_Update3DScene 0x021E31B4 thumb ov119
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_HaltWithMessage 0x0200F7C0 thumb
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   DWC_RAPCOMMON_DestroySubHeap 0x02156ED0 thumb ov009
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   BEACON_STATUS_DoNothing 0x020275E0 thumb
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   POKETRADE_3D_Delete3DScene 0x021E31BC thumb ov119
 *   TCB_DeleteTask 0x02030EAC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov114_id 0x00000072 data a1
 *   ov067_id 0x00000043 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 *   POKETRADE_2D_MovePickedIconActor 0x021E68F4 thumb ov119
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   POKE_REGULATION_IsInSpeciesTable 0x02019D84 thumb
 *   gTradeableSpecies 0x021E7718 data ov119 a4
 *   GFL_NET_GetRunState  0x0203CD98  arm  arm9
 *   POKETRADE_PROC_UpdatePickedIcon 0x021DD09C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_TickWifiTimer 0x021DD140 thumb ov119
 *   POKETRADE_PROC_ResetTouchbarBackButton 0x021D8980 thumb ov119
 *   POKETRADE_NEGO_ReleaseIconResources 0x021DD588 thumb ov119
 *   POKETRADE_NEGO_DeleteHeaderWindows 0x021DD9DC thumb ov119
 *   POKETRADE_NEGO_RegisterIconResources 0x021DD528 thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_IsMonValid 0x021D89EC thumb ov119
 *   POKETRADE_PROC_ClearNetAutoExit 0x021D89CC thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_NEGO_DrawOfferStatusLabel 0x021DD90C thumb ov119
 *   POKETRADE_PROC_StepShowWaitMessageA 0x021DAEF0 thumb ov119
 *   POKETRADE_PROC_StepRebuildBrowseScene 0x021DBBD0 thumb ov119
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_FindOfferIndex  0x021DD34C  thumb  ov119
 *   POKETRADE_NEGO_RemoveOffer  0x021DD4F4  thumb  ov119
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_PROC_StepResetForNewRound 0x021DACE4 thumb ov119
 *   POKETRADE_PROC_IsWifiMode 0x021D8ADC thumb ov119
 *   POKETRADE_NEGO_HasOffer 0x021DD2F4 thumb ov119
 *   POKETRADE_PROC_GetStoredBoxIndex 0x021D8A18 thumb ov119
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKETRADE_PROC_GetSlotMonPtr 0x021D8E24 thumb ov119
 *   POKETRADE_NEGO_FreeOfferMons 0x021DD174 thumb ov119
 *   POKETRADE_NEGO_ClearOfferSlots 0x021DD1B8 thumb ov119
 *   POKETRADE_NEGO_CanConfirmOffers 0x021DD2A8 thumb ov119
 *   POKETRADE_NEGO_StoreRemoteOffer 0x021DD380 thumb ov119
 *   POKETRADE_NEGO_FindFreeOfferIndex 0x021DD3D4 thumb ov119
 *   POKETRADE_NEGO_AddSelectedAsOffer 0x021DD5B4 thumb ov119
 *   POKETRADE_NEGO_DrawPlayerNames 0x021DD68C thumb ov119
 */
#include "pokemontrade_types.h"
#include "../sdk_ioreg.h"
#include "pokemontrade_2d.h"
#include "pokemontrade_nego.h"
#include "pokemontrade_save.h"

struct Mon;

struct Proc;

struct McssSys;

struct Proc;

#include "../types.h"

typedef struct PokemontradeProcPt { u16 x; u16 y; } PokemontradeProcPt;


typedef struct { int a,b; } PokemontradeProcPair;

typedef struct { u8 a,b,c,d; } PokemontradeProcRect;



#include "../ov067/touchbar.h"



#include "../arm9/mail.h"




#include "../arm9/net_state.h"

#include "../arm9/poke_tool.h"


#include "../arm9/gfl_use.h"





#include "../arm9/touchpanel.h"

#include "../arm9/clact.h"





#include "../arm9/mi_memory.h"


struct GameData;
struct BoxPokemon;

#include "../arm9/box_savedata.h"
struct PokemonParam;

struct Party;

#include "../arm9/pokeparty.h"




struct GFLNetHandle;

#include "../arm9/net_handle.h"

#include "../arm9/net.h"



struct SaveControl;

#include "../arm9/game_data.h"
struct WifiHistory;

#include "../arm9/wifi_history.h"
struct MyStatus;

#include "../arm9/mystatus.h"




#include "../arm9/bmp_oam.h"

struct HistoryEntry;
struct HistoryOwner;

#include "../arm9/comm_history.h"
struct TradeWork;


#include "../arm9/net_system.h"


#include "../arm9/wipe.h"


#include "pokemontrade_3d.h"





struct SaveData;

#include "../arm9/event_id.h"

#include "../arm9/file_util.h"



struct Strbuf;
struct MsgBank;

#include "../arm9/msgdata.h"



#include "../arm9/ui.h"



#include "../arm9/bg_sys.h"







#include "../arm9/key.h"




struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"




#include "../arm9/wordset.h"



struct GFLNetHandle;


#include "../arm9/g2.h"









#include "../arm9/gfl_heap_wrap.h"

struct TaskMenuWork;







#include "../ov117/pokemontrade_ircdemo.h"

#include "../ov118/pokemontrade_demo_middle.h"



#include "../ov009/dwc_rap.h"



































#include "../arm9/mcss.h"




#include "../arm9/g3d_camera.h"

#include "../arm9/g3d_system.h"


#include "../arm9/bmp_win.h"








#include "../arm9/arc_util.h"

























#include "../arm9/gfl_heap.h"


#include "../arm9/procsys.h"

#include "../arm9/gf_overlay.h"


#include "../arm9/zukan_save.h"
struct ZukanSave;



#include "../arm9/net_command.h"
struct TcbTask;







struct McssWork;


#include "../arm9/fade.h"

#include "../ov118/pokemontrade_demo_up.h"


#include "../arm9/beacon_status.h"

#include "../arm9/net_err.h"



#include "../arm9/gf_font.h"

struct TcblSystem;

#include "../arm9/tcbl.h"
struct PrintQueue;

#include "../arm9/printsys.h"


struct G3dCamera;







struct _NHTTPRapSession;

#include "../ov114/nhttp_rap.h"



#include "../ov009/dwc_rapcommon.h"






struct TcbTask;

#include "../arm9/tcb_list.h"







#include "../arm9/poke_regulation.h"
#include "../version.h"

void POKETRADE_PROC_ResetTouchbarBackButton(TradeWork *p);

int POKETRADE_PROC_IsMailBoxFull(TradeWork *p);

void POKETRADE_PROC_ClearNetAutoExit(TradeWork *p);

int POKETRADE_PROC_IsMonValid(const u8 *p);

u8 POKETRADE_PROC_GetStoredBoxIndex(TradeWork *p);

int POKETRADE_PROC_IsNetSession(TradeWork *p);

void POKETRADE_PROC_IncrementTimer(TradeWork *p);

int POKETRADE_PROC_IsHostSide(TradeWork *p);

int POKETRADE_PROC_IsWifiMode(TradeWork *p);

int POKETRADE_PROC_GetBoxIndexForSlot(int a, TradeWork *p);

int POKETRADE_PROC_GetSlotIndexInBox(int a, int b);

void POKETRADE_PROC_RequestBoxRedraw(TradeWork *p);

void POKETRADE_PROC_UpdateDragState(TradeWork *p);

void POKETRADE_PROC_UpdateDragIcon(TradeWork *p);

void POKETRADE_PROC_ClearDragIcon(TradeWork *p);

void POKETRADE_PROC_ShowDragIcon(TradeWork *p);

void POKETRADE_PROC_BeginDrag(TradeWork *p, struct ClactActor *x, int y, int z, void *mon);

void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, TradeWork *p);

void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, TradeWork *p);

char *POKETRADE_PROC_GetSlotMonPtr(int a, int b, TradeWork *p);

void POKETRADE_PROC_StepNone(void *unused);

void POKETRADE_PROC_SetStep(TradeWork *p, void (*v)(TradeWork *));

u32 POKETRADE_PROC_GetNetIdOffset(u32 a, u32 b);

void POKETRADE_PROC_RecvPlayerMonA(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

int POKETRADE_PROC_GetSideValue(TradeWork *p,int idx);

void POKETRADE_PROC_SetSideValue(TradeWork *p,int idx,int x);

void *POKETRADE_PROC_GetSideMon(TradeWork *p, int idx);

void POKETRADE_PROC_RecvMonCopy(int idx,int a,int b,TradeWork *p,void *id);

void POKETRADE_PROC_RecvMonChunkCommon(int a,int b,int c,TradeWork *p,void *e,int f);

void POKETRADE_PROC_RecvMonChunk0(int a, int b, int c, TradeWork *d, void *e);

void POKETRADE_PROC_RecvMonChunk1(int a, int b, int c, TradeWork *d, void *e);

void POKETRADE_PROC_RecvMonChunk2(int a, int b, int c, TradeWork *d, void *e);

void POKETRADE_PROC_RecvOfferMonCommon(u32 a, u32 b, u32 c, TradeWork *base, void *e);

void POKETRADE_PROC_RecvOfferMon0(u32 a, int b, u8 *c, TradeWork *d, void *e);

void POKETRADE_PROC_RecvOfferMon1(u32 a, int b, u8 *c, TradeWork *d, void *e);

void POKETRADE_PROC_RecvOfferMon2(u32 a, int b, u8 *c, TradeWork *d, void *e);

void POKETRADE_PROC_RecvPlayerFlag(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerSelection(u32 a, u32 b, u32 c, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerValue(u32 a, u32 b, u32 c, u32 d, void *e);

void POKETRADE_PROC_RecvPeerFlags(int a,int b,const u8 *c,TradeWork *p,void *e);

void POKETRADE_PROC_RecvPeerState(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvTradeSummary(int netId, int size, void *data, TradeWork *work, void *handle);

void POKETRADE_PROC_RecvStateByte(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerByte(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerWord(u32 a, u32 b, int *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerWordB(u32 a, u32 b, u32 c, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerHalf(u32 a, u32 b, short *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvPeerByteB(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvIgnoredA(u32 a, u32 b, u32 c, u32 d, void *e);

void POKETRADE_PROC_RecvPeerByteC(u32 a, u32 b, u8 *src, TradeWork *base, void *e);

void POKETRADE_PROC_RecvIgnoredB(u32 a, u32 b, u32 c, u32 d, void *e);

void POKETRADE_PROC_RecvIgnoredC(u32 a, u32 b, u32 c, u32 d, void *e);

void POKETRADE_PROC_StepWaitWipeEnd(TradeWork *p);

void POKETRADE_PROC_StepBeginWipeOut(TradeWork *p);

void POKETRADE_PROC_SetSideMon(TradeWork *p, int a, void *b);

void POKETRADE_PROC_ClearSideMon(TradeWork *p, int a);

int POKETRADE_PROC_IsSelfMonReady(TradeWork *p);

int POKETRADE_PROC_IsSelectedOfferSlot(TradeWork *p,int a,int b);

u32 POKETRADE_PROC_IsMonBadEggOrInvalid(void *mon);

int POKETRADE_PROC_IsCurrentSideMonInvalid(TradeWork *p);

u32 POKETRADE_PROC_IsOtherSideMonInvalid(TradeWork *p);

int POKETRADE_PROC_IsMonTradeable(TradeWork *p);

void POKETRADE_PROC_BuildPartyPacket(TradeWork *p);

void POKETRADE_PROC_ShowIntroMessage(TradeWork *p);

void POKETRADE_PROC_PlaceCursorIcon(TradeWork *p, int cursorIndex, int showSummary);

void POKETRADE_PROC_StepReturnFromSummary(TradeWork *p);

void POKETRADE_PROC_StepMain(TradeWork *p);

void POKETRADE_PROC_StepAfterSummaryWipe(TradeWork *p);

void POKETRADE_PROC_StepMainMenuChoice(TradeWork *p);

void POKETRADE_PROC_StepShowTradeSummary(TradeWork *p);

void POKETRADE_PROC_StepOpenMainMenu(TradeWork *p);

void POKETRADE_PROC_StepWaitSync20(TradeWork *p);

void POKETRADE_PROC_StepStartSync20(TradeWork *p);

void POKETRADE_PROC_StepIntro(TradeWork *p);

void POKETRADE_PROC_StepSendIntroReady(TradeWork *p);

void POKETRADE_PROC_StepMenuChoice(TradeWork *p);

void POKETRADE_PROC_StepOpenMenu(TradeWork *p);

void POKETRADE_PROC_StepSendPartyBoxSelected(TradeWork *p);

void POKETRADE_PROC_HideTouchbarButtons(TradeWork *p);

void POKETRADE_PROC_SetDragTarget(TradeWork *p,int a,int b);

int POKETRADE_PROC_PollGridTouch(TradeWork *p,int *a,int *b,int *c,int *d);

int POKETRADE_PROC_PollGridTouchDrag(TradeWork *p,int save);

void POKETRADE_PROC_StepWaitKeyAfterMessage(TradeWork *p);

void POKETRADE_PROC_ShowCancelMessage(TradeWork *p);

void POKETRADE_PROC_ShowSelectMessage(TradeWork *p);

void POKETRADE_PROC_ShowPeerSummary(TradeWork *p);

void POKETRADE_PROC_StepAddSelectedOffer(TradeWork *p);

void POKETRADE_PROC_StepSendAddOffer(TradeWork *p);

void POKETRADE_PROC_StepApplyAddOffer(TradeWork *p);

void POKETRADE_PROC_StepSendApplyAddOffer(TradeWork *p);

#if LANGUAGE != LANGUAGE_JAPANESE
void POKETRADE_PROC_StepWaitTouchReleasePeer(TradeWork *p);
#endif

void POKETRADE_PROC_StepPeerSummaryMenu(TradeWork *p);

void POKETRADE_PROC_StepOpenPeerSummary(TradeWork *p);

void POKETRADE_PROC_StepSendCursorChoice(TradeWork *p);

void POKETRADE_PROC_StepWaitCursorSync(TradeWork *p);

void POKETRADE_PROC_StepResolveCursorResult(TradeWork *p);

void POKETRADE_PROC_StepRebuildTradeScene(TradeWork *p);

void POKETRADE_PROC_StepRestoreBrowseScene(TradeWork *p);

void POKETRADE_PROC_StepWaitThenRestoreScene(TradeWork *p);

void POKETRADE_PROC_StepBeginWipeToRestore(TradeWork *p);

void POKETRADE_PROC_StepWaitSyncThenWipe(TradeWork *p);

void POKETRADE_PROC_StepSendTradeData(TradeWork *p);

void POKETRADE_PROC_StepBuildTradeRecord(TradeWork *p);

void POKETRADE_PROC_StepBuildMarkingTable(TradeWork *p);

void POKETRADE_PROC_StepSendBoxInfo(TradeWork *p);

void POKETRADE_PROC_StepLoadBoxIconGfx(TradeWork *p);

void POKETRADE_PROC_StepWaitNetSync22(TradeWork *p);

void POKETRADE_PROC_StepAfterWipeLoadBox(TradeWork *p);

void POKETRADE_PROC_StepRestartNetSession(TradeWork *p);

void POKETRADE_PROC_StepResetForNewRound(TradeWork *p);

void POKETRADE_PROC_StepWaitMessageThenResolve(TradeWork *p);

void POKETRADE_PROC_StepSendNewRound(TradeWork *p);

void POKETRADE_PROC_StepClearOffersNewRound(TradeWork *p);

void POKETRADE_PROC_StepWaitMessageThenClear(TradeWork *p);

void POKETRADE_PROC_StepShowWaitMessageA(TradeWork *p);

void POKETRADE_PROC_StepSendContinue(TradeWork *p);

void POKETRADE_PROC_StepSendStartRound(TradeWork *p);

void POKETRADE_PROC_StepSummaryMenuChoice(TradeWork *p);

int POKETRADE_PROC_SendSideMon(TradeWork *p);

void POKETRADE_PROC_StepOpenSummaryMenu(TradeWork *p);

void POKETRADE_PROC_StepShowSummaryMessage(TradeWork *p);

void POKETRADE_PROC_StepSlideInSubScreen(TradeWork *p);

int POKETRADE_PROC_FindMatchingBoxIcon(TradeWork *p,int kind);

void POKETRADE_PROC_StepCloseSubScreenDone(TradeWork *p);

void POKETRADE_PROC_StepExitSubScreen(TradeWork *p);

void POKETRADE_PROC_StepWaitCursorFade(TradeWork *p);

void POKETRADE_PROC_StepSubScreenList(TradeWork *p);

void POKETRADE_PROC_StepOpenSubScreen(TradeWork *p);

void POKETRADE_PROC_StepBeginOpenSubScreen(TradeWork *p);

int POKETRADE_PROC_GetSlotPosition(int a);

int POKETRADE_PROC_IsSlotVisible(TradeWork *p, int index);

void POKETRADE_PROC_PollGridKeys(TradeWork *p);

void POKETRADE_PROC_RedrawAndSyncGrid(TradeWork *p,int a,int b);

void POKETRADE_PROC_DragScrollGrid(TradeWork *p);

void POKETRADE_PROC_StepWaitBrowseRelease(TradeWork *p);

void POKETRADE_PROC_StepClearPeerSelection(TradeWork *p);

void POKETRADE_PROC_StepBeginBrowse(TradeWork *p);

void POKETRADE_PROC_StepResetGrid(TradeWork *p);

void POKETRADE_PROC_StepEnterBrowsing(TradeWork *p);

void POKETRADE_PROC_UpdateTouchbarButtons(TradeWork *p);

void POKETRADE_PROC_StepRebuildBrowseScene(TradeWork *p);

void POKETRADE_PROC_StepConfirmSendOffer(TradeWork *p);

void POKETRADE_PROC_StepSendOfferConfirm(TradeWork *p);

void POKETRADE_PROC_StepWaitIconFlight(TradeWork *p);

int POKETRADE_PROC_IsTradeTargetValid(TradeWork *p,int a,int b);

int POKETRADE_PROC_StepPeerSelectAction(TradeWork *p);

void POKETRADE_PROC_StepBrowseGrid(TradeWork *p);

void POKETRADE_PROC_StepTouchbarAction(TradeWork *p);

void POKETRADE_PROC_StepWaitKeyThenBrowse(TradeWork *p);

void POKETRADE_PROC_InitMcssSystem(TradeWork *p);

void POKETRADE_PROC_ExitMcssSystem(TradeWork *p);

void POKETRADE_PROC_InitDisplay(TradeWork *p);

void POKETRADE_PROC_ExitDisplay(void *unused);

void POKETRADE_PROC_LoadSceneResources(TradeWork *p);

void POKETRADE_PROC_VBlank(struct TcbTask *a, void *pArg);

void POKETRADE_PROC_SetupGameData(TradeWork *p,void *q,u16 r);

void POKETRADE_PROC_FreeMons(TradeWork *p, int unused);

void POKETRADE_PROC_SetupBoxCounts(TradeWork *p);

void POKETRADE_PROC_BuildTradeRecords(TradeWork *p,int n);

void POKETRADE_PROC_DeleteAllResources(TradeWork *p);

void POKETRADE_PROC_ExitBgm(TradeWork *p);

TradeWork *POKETRADE_PROC_AllocTradeWork(void *a,int t);

int POKETRADE_PROC_InitTradeWork(void *a,int b,char *q,TradeWork *p,int n);

int POKETRADE_PROC_StartRequest2(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest0(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest1(void *a,int b,char *c);

int POKETRADE_PROC_StartRequest3(void *a,int b,char *c);

void POKETRADE_PROC_SetupMcssPokemon(char *a, TradeWork *p);

int POKETRADE_PROC_StartRequest4(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest7(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest8(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest6(void *a, int b, char *c);

int POKETRADE_PROC_Main(int a,int b,int c,TradeWork *p);

int POKETRADE_PROC_Exit(void *owner,int unused,int keep,TradeWork *p);

void POKETRADE_PROC_ClampScrollColumn(TradeWork *p, int flag);

void POKETRADE_PROC_SetSyncRange(void *a, void *b, void *c);

void POKETRADE_PROC_UpdatePickedIcon(TradeWork *p);

int POKETRADE_PROC_CanTradeMon(TradeWork *p, void *a);

int POKETRADE_PROC_TickWifiTimer(TradeWork *p);

















extern const PokemontradeProcPt gCursorIconPos0;

extern const PokemontradeProcPt gCursorIconPos1;

extern const char gMainMenuHitArea[];

extern const PokemontradeIntTriple gMainMenuLayout;

extern const PokemontradeProcPair gOpenMenuPos;

extern const PokemontradeProcPair gPeerSummaryPos;

extern const PokemontradeProcPair gSummaryMenuPos;

extern PokemontradeProcRect gSubScreenHitAreas[];

extern const int gScrollSnapPos[];

extern char gGameDataAllocTag[];

extern char gTradeWorkHeapName[];

extern char ov067_id[],ov114_id[],ov117_id[],ov118_id[];

extern NetCommandEntry gNetCommandTable[];

extern char ov114_id[],ov067_id[],ov117_id[],ov118_id[];

extern const int gTradeableSpecies[];

/*
 * 2026-10-02: the first call's target 021B65B4 (thumb, ov067 window) was an
 *  unlabelled tail-call stub; seeded in layout/function_starts.txt and matched
 *  as src/matched/ov/ov067_func_021B65B4.c, so every call now resolves.
 */
void POKETRADE_PROC_ResetTouchbarBackButton(TradeWork *p)
{
    TOUCHBAR_ResetAndEnableButton((TouchBar *)p->touchbar, 1);
    TOUCHBAR_SetButtonVisible((TouchBar *)p->touchbar, 1, 1);
    TOUCHBAR_SetButtonEnabled(p->touchbar, 1, 1);
}

int POKETRADE_PROC_IsMailBoxFull(TradeWork *p)
{
    void *o = MAIL_GetBox(p->gameData);
    int r = 0;
    if (MAIL_FindEmptySlot(o, 0) == -1)
        r = 1;
    return r;
}

void POKETRADE_PROC_ClearNetAutoExit(TradeWork *p)
{
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    GFL_NET_STATE_WifiDisconnect(0);
    p->request->state = 3;
}

int POKETRADE_PROC_IsMonValid(const u8 *p)
{
    int n;
    int i;

    n = POKE_TOOL_GetPartyParamSize();
    if (p == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (p[i] != 0) {
            return 1;
        }
    }
    return 0;
}

u8 POKETRADE_PROC_GetStoredBoxIndex(TradeWork *p) { return p->storedBoxIndex; }

/*
 * True when the object has a session and its state index is in range.
 */
int POKETRADE_PROC_IsNetSession(TradeWork *p)
{
    int v;

    if (p->request == 0)
        return 0;
    v = p->tradeState;
    if (v >= 4)
        return 0;
    return GFL_NET_GetRunState() != 0;
}

void POKETRADE_PROC_IncrementTimer(TradeWork *p) {
 int v;
 if(p->repeatCounter!=0) {
 v=++p->repeatCounter;
 if(v==2) {GFL_USE_FadeOutBgm(6); return;}
 if(v==8) {
 GFL_USE_SetBgmPaused((u32)1); GFL_USE_PushBgm();
 ++p->sceneState;
 GFL_USE_CancelChangeAndPlayBgm(0x3f3,0xffff); GFL_USE_FadeInBgmFull(1);
 p->repeatCounter=0;
 }
 }
}

int POKETRADE_PROC_IsHostSide(TradeWork *p)
{
    unsigned int x = (p->tradeState);
    int r = 0;

    switch (x) {
    case 0:
    case 4:
    case 6:
    case 7:
    case 8:
        break;
    default:
        r = 1;
    }
    return r;
}

int POKETRADE_PROC_IsWifiMode(TradeWork *p)
{
    int r = 0;
    int v = p->tradeState;
    if (v == 3 || v == 9)
        r = 1;
    return r;
}

int POKETRADE_PROC_GetBoxIndexForSlot(int a, TradeWork *p)
{
    if (a >= 2)
        return (a - 2) / 6;
    return p->partyBoxId;
}

int POKETRADE_PROC_GetSlotIndexInBox(int a, int b)
{
    if (a >= 2) {
        return (a - 2) % 6 + b * 6;
    }
    if (b < 3)
        return a + b * 2;
    return -1;
}

void POKETRADE_PROC_RequestBoxRedraw(TradeWork *p)
{
    p->cursorRow += 1;
    p->redrawNeeded = 1;
    POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 0);
}

void POKETRADE_PROC_UpdateDragState(TradeWork *p)
{
    int o1, o2;
    int d;

    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    if (p->dragActor == 0)
        p->dragMoved = 0;
    if (p->dragActor != 0) {
        d = ((short)p->targetX - (short)p->offsetX) - o1;
        if (d < 0)
            d = -d;
        if (d > 2)
            p->dragMoved = 1;
        d = ((short)p->targetY - (short)p->offsetY) - o2;
        if (d < 0)
            d = -d;
        if (d > 2)
            p->dragMoved = 1;
        d = (short)p->targetX - o1;
        if (d < 0)
            d = -d;
        if (d > 6) {
            d = (short)p->targetY - o2;
            if (d < 0)
                d = -d;
            if (d > 6)
                p->dragHold = 0;
        }
    }
    if ((unsigned int)o2 >= 0x10 && (unsigned int)o2 < 0x90) {
        p->iconPosX = o1;
        p->iconPosY = o2;
    }
}

void POKETRADE_PROC_UpdateDragIcon(TradeWork *p) {
 int x,y; short pos[2];
 if(p->dragActor!=0) {
 if(TOUCHPANEL_GetPointCont((u32 *)((unsigned int *)(&x)),(u32 *)((unsigned int *)(&y)))!=0) {
 CLACT_GetActorSurfacePos((struct ClactActor *)((struct ClactActor *)p->dragActor),(struct ClactVec2 *)&p->originX,1);
 pos[0]=x+p->offsetX;
 pos[1]=y+p->offsetY;
 if(pos[1]>150) pos[1]=150;
 CLACT_AddActorSurfacePos((struct ClactActor *)((struct ClactActor *)(p->dragActor)),(const struct ClactVec2 *)pos,1);
 }
 }
}

/*
 * Clear the pending pointer and hand the object to the updater.
 */
void POKETRADE_PROC_ClearDragIcon(TradeWork *p)
{
    if (p->dragActor != 0)
        p->dragActor = 0;
    POKETRADE_2D_DeleteFloatingIconActor(p);
}

void POKETRADE_PROC_ShowDragIcon(TradeWork *p) {
 if(p->dragActor!=0) {
 CLACT_SetActorDrawPriority((struct ClactActor *)((struct ClactActor *)(p->dragActor)),16);
 CLACT_AddActorSurfacePos((struct ClactActor *)((struct ClactActor *)(p->dragActor)),(const struct ClactVec2 *)&p->targetX,1);
 CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->dragActor),1);
 p->highlightSlot=-1;
 p->highlightBox=-1;
 POKETRADE_PROC_ClearDragIcon(p); MI_CpuFill8(p->pad_4,0,2);
 }
}

void POKETRADE_PROC_BeginDrag(TradeWork *p, struct ClactActor *x, int y, int z, void *mon)
{
    int o1, o2;

    p->dragActor = x;
    CLACT_GetActorSurfacePos((struct ClactActor *)x, (struct ClactVec2 *)&p->targetX, 1);
    POKETRADE_2D_SetIconObjMode(p, p->dragActor, 1);
    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    p->offsetX = (s16)p->targetX - o1;
    p->offsetY = (s16)p->targetY - o2;
    POKETRADE_2D_CreateFloatingIconActor(p, y, z,
                  o1 + (s16)p->offsetX,
                  o2 + (s16)p->offsetY,
                  mon);
    p->dragActor = p->iconActorC;
}

void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, TradeWork *p)
{
    int n;
    void *res = 0;

    if (b == -1)
        goto out;
    n = p->partyBoxId;
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = POKE_TOOL_CreateFromBoxParam((struct PokemonParam *)BOX_SAVEDATA_GetPokemon((struct GameData *)a, b, c), p->heapId);
    } else {
        void *m = p->partyData;
        if (c >= (int)POKEPARTY_GetCount(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = POKE_TOOL_Create(1, 1, 1, p->heapId);
            int sz = POKE_TOOL_GetPartyParamSize();
            MI_CpuCopy8(POKEPARTY_GetMember(m, c), mon, sz);
            res = mon;
        }
    }
out:
    return res;
}

void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, TradeWork *p)
{
    void *m;
    int n;

    if (b != -1) {
        n = p->partyBoxId;
        if (b > n)
            return 0;
        if (b != n && c != -1)
            return BOX_SAVEDATA_GetPokemon(a, b, c);
        m = p->partyData;
        if (c < (int)POKEPARTY_GetCount(m) && c != -1)
            return POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(m, c));
    }
    return 0;
}

char *POKETRADE_PROC_GetSlotMonPtr(int a, int b, TradeWork *p)
{
    int n;

    if (a != -1) {
        n = p->partyBoxId;
        if (a > n)
            return 0;
        if (a != n && b != -1)
            return (char *)&p->records[a * 0x1e + 6 + b];
        if (b >= 0 && b < 6)
            return (char *)&p->records[b];
        return 0;
    }
    return 0;
}

/*
 * Empty stub.
 */
void POKETRADE_PROC_StepNone(void *unused)
{
}

void POKETRADE_PROC_SetStep(TradeWork *p, void (*v)(TradeWork *))
{
    p->stepFunc = v;
}

/*
 * Hidden leaf (no caller seen): slot lookup by index, 0 when out of range.
 */
void *POKETRADE_PROC_GetPlayerMonPtr(int i, TradeWork *p)
{
    if (i >= 0 && i < 2)
        return p->tradeBuf[i];
    return 0;
}

/*
 * Hidden leaf (no caller seen): same lookup as POKETRADE_PROC_GetPlayerMonPtr.
 */
void *POKETRADE_PROC_GetPlayerMonPtrAlt(int i, TradeWork *p)
{
    if (i >= 0 && i < 2)
        return p->tradeBuf[i];
    return 0;
}

u32 POKETRADE_PROC_GetNetIdOffset(u32 a, u32 b)
{
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
        return b + 0x10;
    return b + 0x2e6;
}

void POKETRADE_PROC_RecvPlayerMonA(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        u32 idx = (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) ? 0 : 1;
        base->labelState[idx] = *src;
    }
}

int POKETRADE_PROC_GetSideValue(TradeWork *p,int idx) {
 unsigned v=POKETRADE_PROC_IsNetSession(p);
 if(v==0) return p->sideValue[idx];
 if(GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()))==0) return p->sideValue[idx];
 return p->sideValue[1-idx];
}

void POKETRADE_PROC_SetSideValue(TradeWork *p,int idx,int x) {
 unsigned v=POKETRADE_PROC_IsNetSession(p);
 if(v==0) { p->sideValue[idx]=x; return; }
 if(GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()))==0) { p->sideValue[idx]=x; return; }
 p->sideValue[1-idx]=x;
}

/*
 * Addresses are Black-image addresses.
 */
void *POKETRADE_PROC_GetSideMon(TradeWork *p, int idx)
{
    u32 v = POKETRADE_PROC_IsNetSession(p);
    if (v == 0)
        return p->monBuf[idx];
    if (GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())) == 0)
        return p->monBuf[idx];
    return p->monBuf[1 - idx];
}

void POKETRADE_PROC_RecvMonCopy(int idx,int a,int b,TradeWork *p,void *id) {
 if(id==GFL_NET_HANDLE_GetCurrentHandle()) {
 int n=POKE_TOOL_GetPartyParamSize();
 MI_CpuCopy8(p->tradeBuf[idx],p->monBuf[idx],n);
 if(idx!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) {
 p->pendingSideMon=idx+1;
 p->stateFlags.byte=(p->stateFlags.byte&~0xf0)|0x10;
 }
 }
}

void POKETRADE_PROC_RecvMonChunkCommon(int a,int b,int c,TradeWork *p,void *e,int f) { int z;if(e==GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()))) {z=0;if(POKE_TOOL_GetPartyValue(p->tradeBuf[a],169,0)) {POKETRADE_NEGO_StoreRemoteOffer(p,f,p->tradeBuf[a]);POKETRADE_2D_CreateOfferIconActor(p,1,f,p->tradeBuf[a],1,z);POKETRADE_NEGO_ShowOfferSlotMon(p,1,p->tradeBuf[a]);}p->stateFlags.byte=(p->stateFlags.byte&~240)|16;} } }

/*
 * DWCi_EncSessionGetAsync: sixth argument is zero.
 */
void POKETRADE_PROC_RecvMonChunk0(int a, int b, int c, TradeWork *d, void *e)
{
    POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 0);
}

void POKETRADE_PROC_RecvMonChunk1(int a, int b, int c, TradeWork *d, void *e)
{
    POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 1);
}

/*
 * Third entry point of the encoder session getter.
 */
void POKETRADE_PROC_RecvMonChunk2(int a, int b, int c, TradeWork *d, void *e)
{
    POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 2);
}

void POKETRADE_PROC_RecvOfferMonCommon(u32 a, u32 b, u32 c, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (c == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            base->offerReceivedValue[0][b] = a;
        else
            base->offerReceivedValue[1][b] = a;
    }
}

/*
 * Encoder session getter on the byte pointed at by the third argument.
 */
void POKETRADE_PROC_RecvOfferMon0(u32 a, int b, u8 *c, TradeWork *d, void *e)
{
    POKETRADE_PROC_RecvOfferMonCommon(*c, 0, a, d, e);
}

void POKETRADE_PROC_RecvOfferMon1(u32 a, int b, u8 *c, TradeWork *d, void *e)
{
    POKETRADE_PROC_RecvOfferMonCommon(*c, 1, a, d, e);
}

void POKETRADE_PROC_RecvOfferMon2(u32 a, int b, u8 *c, TradeWork *d, void *e)
{
    POKETRADE_PROC_RecvOfferMonCommon(*c, 2, a, d, e);
}

void POKETRADE_PROC_RecvPlayerFlag(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        base->sideValue[a] = *src;
}

void POKETRADE_PROC_RecvPeerSelection(u32 a, u32 b, u32 c, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            base->stateFlags.byte = base->stateFlags.byte & ~0xf;
    }
}

void POKETRADE_PROC_RecvPeerValue(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            return;
    }
}

void POKETRADE_PROC_RecvPeerFlags(int a,int b,const u8 *c,TradeWork *p,void *e) {
 if(e==GFL_NET_HANDLE_GetCurrentHandle()) {
  if(a!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()))) {
   p->storedBoxIndex=c[0]; p->peerBoxValue=c[1];
   (*(unsigned short *)&p->scrollY)=p->storedBoxIndex*160+16;
  }
 }
}

void POKETRADE_PROC_RecvPeerState(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            base->peerState[1] = *src;
    }
}

void POKETRADE_PROC_RecvTradeSummary(int netId, int size, void *data, TradeWork *work, void *handle)
{
    u8 buf[0x28];
    u8 x, y;
    u32 r1, r2;
    void *saved;

    if (handle != GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (netId == GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    saved = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(work->gameData));
    MI_CpuCopy8(data, buf, 0x28);
    x = MYSTATUS_GetNation((struct MyStatus *)buf);
    y = MYSTATUS_GetArea((struct MyStatus *)buf);
    r1 = NATION_AREA_SanitizeNation(x, y, MYSTATUS_GetLanguage((struct MyStatus *)buf));
    r2 = NATION_AREA_SanitizeArea(x, y, MYSTATUS_GetLanguage((struct MyStatus *)buf));
    if (x == r1 && y == r2)
        MYSTATUS_SetNationAndArea((struct MyStatus *)buf, x, y);
    else
        MYSTATUS_SetNationAndArea((struct MyStatus *)buf, 0, 0);
    COMM_HISTORY_InsertIfNationSet((struct HistoryOwner *)saved, (struct HistoryEntry *)buf);
}

void POKETRADE_PROC_RecvStateByte(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        base->choice[a] = *src;
}

void POKETRADE_PROC_RecvPeerByte(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            base->netFlag = *src;
    }
}

void POKETRADE_PROC_RecvPeerWord(u32 a, u32 b, int *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) {
            POKETRADE_NEGO_RemoveOffer(base, 1, *src);
            POKETRADE_2D_DeleteOfferIconActor(base, 1, *src);
        }
    }
}

void POKETRADE_PROC_RecvPeerWordB(u32 a, u32 b, u32 c, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            POKETRADE_PROC_ClearSideMon(base, 1);
    }
}

void POKETRADE_PROC_RecvPeerHalf(u32 a, u32 b, short *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            base->scrollY = *src;
    }
}

void POKETRADE_PROC_RecvPeerByteB(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            POKETRADE_NEGO_FlashMarker(base, *src, 1);
    }
}

void POKETRADE_PROC_RecvIgnoredA(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        return;
}

void POKETRADE_PROC_RecvPeerByteC(u32 a, u32 b, u8 *src, TradeWork *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            (base->offerCount) = *src;
    }
}

void POKETRADE_PROC_RecvIgnoredB(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        return;
}

/*
 * Byte-identical twin of POKETRADE_PROC_RecvIgnoredA (same 12-byte predicate stub).
 */
void POKETRADE_PROC_RecvIgnoredC(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        return;
}

void POKETRADE_PROC_StepWaitWipeEnd(TradeWork *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        POKETRADE_PROC_SetStep(p, 0);
}

/*
 * Start a 7-argument timer/slot request (0,0,0,0,6,1,*(u16*)(p+0x5f4)) then
 * hand POKETRADE_PROC_SetStep the POKETRADE_PROC_StepWaitWipeEnd callback. Non-SDK dep of
 * POKETRADE_SAVE_ResetClactAndBeginEvent's case-5 arm.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_PROC_StepBeginWipeOut(TradeWork *p)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, p->heapId);
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepWaitWipeEnd);
}

/*
 * Start a transfer on the object when the length is non-zero.
 */
void POKETRADE_PROC_SetSideMon(TradeWork *p, int a, void *b)
{
    int t;

    if (b == 0)
        return;
    POKETRADE_3D_DeleteMcssSlot(p, a);
    t = POKETRADE_PROC_IsHostSide(p);
    POKETRADE_3D_AddPokemonMcssFlipped(p, a, 1 - a, b, 1, t);
    POKETRADE_SAVE_DrawOfferCardWindow(p, a, b);
}

/*
 * Arm or re-arm the three receivers depending on the object state.
 */
void POKETRADE_PROC_ClearSideMon(TradeWork *p, int a)
{
    int i;

    if (POKETRADE_PROC_IsHostSide(p) == 0) {
        POKETRADE_3D_DeleteMcssSlot(p, a);
        POKETRADE_SAVE_DeleteOfferCardWindow(p, a);
        return;
    }
    for (i = 0; i < 3; i++)
        POKETRADE_2D_DeleteOfferIconActor(p, a, i);
}

int POKETRADE_PROC_IsSelfMonReady(TradeWork *p) { int w; void *v; int z; if(POKETRADE_PROC_IsHostSide(p)==0) {v=POKETRADE_PROC_GetSideMon(p,0);w=POKETRADE_PROC_GetSideValue(p,0);} else {v=POKETRADE_PROC_GetSideMon(p,1);w=POKETRADE_PROC_GetSideValue(p,1);} z=0;if(POKE_TOOL_GetPartyValue(v,160,0)==0)return z;if(POKE_TOOL_GetPartyValue(v,76,0))return z;if(POKEPARTY_GetAliveNonEggCount((void *)((p->partyData)))==1 && w!=0)return 1;return 0; }

int POKETRADE_PROC_IsSelectedOfferSlot(TradeWork *p,int a,int b) { void *v=POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager),a,b,p); int r; if(p->tradeState) return 0; if(a!=p->partyBoxId) return 0; r=0; if(POKE_TOOL_GetBoxValue((void *)v,76,0)) return r; if(POKE_TOOL_HasNoHmMove((void *)v,r)==0) r=1; return r; }

u32 POKETRADE_PROC_IsMonBadEggOrInvalid(void *mon)
{
    u32 r = 0;
    if (POKE_TOOL_GetPartyValue(mon, 3, 0) == 1)
        return 1;
    if ((int)POKE_TOOL_GetPartyValue(mon, 5, r) > 0x28b)
        r = 1;
    return r;
}

/*
 * Select the alternate buffer when the object is idle.
 */
int POKETRADE_PROC_IsCurrentSideMonInvalid(TradeWork *p)
{
    int b = 0;

    if (POKETRADE_PROC_IsHostSide(p))
        b = 1;
    return POKETRADE_PROC_IsMonBadEggOrInvalid(POKETRADE_PROC_GetSideMon(p, b));
}

u32 POKETRADE_PROC_IsOtherSideMonInvalid(TradeWork *p)
{
    int r = 1;
    if (POKETRADE_PROC_IsHostSide(p) != 0)
        r = 0;
    return POKETRADE_PROC_IsMonBadEggOrInvalid(POKETRADE_PROC_GetSideMon(p, r));
}

int POKETRADE_PROC_IsMonTradeable(TradeWork *p) { void *v; int w; if(POKETRADE_PROC_IsHostSide(p)==0) {v=POKETRADE_PROC_GetSideMon(p,0); w=POKETRADE_PROC_GetSideValue(p,1);} else {v=POKETRADE_PROC_GetSideMon(p,1); w=POKETRADE_PROC_GetSideValue(p,0);} if(FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(v,6,0)) && p->peerBoxValue!=0 && w==0) return 1; return 0; }

void POKETRADE_PROC_BuildPartyPacket(TradeWork *p)
{
    u8 b[5];
    int r;
    int kind = POKETRADE_PROC_IsNetSession(p);

    if (POKETRADE_SAVE_IsMessagePrintDone(p) == 0)
        return;
    if (kind != 0) {
        if (POKETRADE_PROC_IsSelfMonReady(p)) {
            b[4] = 5;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[4]);
        } else if (POKETRADE_PROC_IsCurrentSideMonInvalid(p)) {
            b[3] = 7;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[3]);
        } else if (POKETRADE_PROC_IsOtherSideMonInvalid(p)) {
            b[2] = 8;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[2]);
        } else if (POKETRADE_PROC_IsMonTradeable(p)) {
            b[1] = 6;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[1]);
        } else {
            b[0] = 2;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[0]);
        }
        if (r == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepResolveCursorResult);
        return;
    }
    p->choice[0] = 2;
    p->choice[1] = 2;
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepResolveCursorResult);
}

void POKETRADE_PROC_ShowIntroMessage(TradeWork *p)
{
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 6, (void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_BuildPartyPacket);
}

/*
 * 2026-10-02: the 0204B404 call is written in each branch of the a1 test (tail-merged
 *  by the compiler, so the 0xf0c pool constant is not hoisted across blocks);
 *  020355C4 is a void getter called on its own; the 021D8FA4 result is a local.
 */
void POKETRADE_PROC_PlaceCursorIcon(TradeWork *p, int cursorIndex, int showSummary)
{
    PokemontradeProcPt t0, t1;
    if (cursorIndex == 0) {
        t0 = gCursorIconPos0;
        CLACT_AddActorSurfacePos((struct ClactActor *)((struct ClactActor *)(p->actorF0C)), (const struct ClactVec2 *)((const struct ClactVec2 *)(&t0)), 1);
    } else {
        t1 = gCursorIconPos1;
        CLACT_AddActorSurfacePos((struct ClactActor *)((struct ClactActor *)(p->actorF0C)), (const struct ClactVec2 *)((const struct ClactVec2 *)(&t1)), 1);
    }
    if (UI_GetInputMode()) {
        POKETRADE_2D_PlaceTouchbarActors(p, cursorIndex, 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->actorF0C), 0);
    } else {
        POKETRADE_2D_PlaceTouchbarActors(p, cursorIndex, 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->actorF0C), 1);
    }
    if (showSummary != 0) {
        void *v;

        v = POKETRADE_PROC_GetSideMon(p, p->cursorIndex);
        POKETRADE_SAVE_ShowSummaryMon(p, v, p->cursorIndex, 1);
    }
}

void POKETRADE_PROC_StepReturnFromSummary(TradeWork *p) { int z,one; if(WIPE_SYS_EndCheck()) {z=0;BG_SYS_SetPlaneVisible(3,0);one=1;POKETRADE_SAVE_CloseSummaryPage(p,1);BG_SYS_SetPlaneVisible(4,0);POKETRADE_2D_LoadBackgroundGfx(p);POKETRADE_3D_AddUnitAndInit(p,0);BG_SYS_MarkTileDirty(3);*(u16 *)REG_BLDCNT_ADDR=z;POKETRADE_PROC_SetSideMon(p,0,POKETRADE_PROC_GetSideMon(p,0));POKETRADE_PROC_SetSideMon(p,1,POKETRADE_PROC_GetSideMon(p,1));POKETRADE_PROC_RequestBoxRedraw(p);WIPE_SYS_Start((void *)3,1,1,0,6,one,p->heapId);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepShowTradeSummary); } }

static inline int poll(void) {int v=KEY_GetTrg();if(v)UI_SetInputMode(0);return v;}

/*
 * prototype: 02035C08 is declared int here: original consumes r0 after
 * its 02035BBC forwarding call; the matched void spelling leaves r0 live.
 * Full matched ARM9 02035BBC returns int through 02035ADC, or -1.
 * wrap: the 10a0 toggle uses full-width unsigned subtraction to preserve
 * the original SUB for every 32-bit field pattern without a domain claim.
 */
void POKETRADE_PROC_StepMain(TradeWork *p)
{
 int done=0;
 if(p->wipeDone==0 && WIPE_SYS_EndCheck()) {
  if(UI_GetInputMode() && poll()) {UI_SetInputMode(0);POKETRADE_PROC_PlaceCursorIcon(p,p->cursorIndex,0);return;}
  BG_SYS_SetPlaneVisible(3,1);
  switch(TOUCHPANEL_HitTrg((const TouchHitTable *)gMainMenuHitArea)) {
  case 0:
   if(p->cursorIndex!=0 || !UI_GetInputMode()) {
    p->cursorIndex=0;UI_SetInputMode(1);GFL_USE_PlaySeDefaultVolume(0x548);POKETRADE_PROC_PlaceCursorIcon(p,p->cursorIndex,1);
   }
   break;
  case 1:
   if(p->cursorIndex!=1 || !UI_GetInputMode()) {
    p->cursorIndex=1;UI_SetInputMode(1);GFL_USE_PlaySeDefaultVolume(0x548);POKETRADE_PROC_PlaceCursorIcon(p,p->cursorIndex,1);
   }
   break;
  case 2:done=1;break;
  }
  if(poll()==32 || poll()==16) {
   p->cursorIndex=1u-p->cursorIndex;GFL_USE_PlaySeDefaultVolume(0x548);UI_SetInputMode(0);POKETRADE_PROC_PlaceCursorIcon(p,p->cursorIndex,1);
  }
  TOUCHBAR_Update((TouchBar *)((*(void * *)&p->touchbar)));
  if(TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)(*(u8 * *)&p->touchbar))==1)done=1;
  if(done) {WIPE_SYS_Start((void *)3,0,0,0,6,1,p->heapId);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepReturnFromSummary);}
 }
}

void POKETRADE_PROC_StepAfterSummaryWipe(TradeWork *p) { if(WIPE_SYS_EndCheck()) { p->cursorIndex=0; POKETRADE_SAVE_OpenSummaryScreen(p,POKETRADE_PROC_GetSideMon(p,0));POKETRADE_PROC_RequestBoxRedraw(p);WIPE_SYS_Start((void *)3,1,1,0,6,1,p->heapId);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepMain); } }

void POKETRADE_PROC_StepMainMenuChoice(TradeWork *p) { int v; if(APP_TASKMENU_IsFinish((struct TaskMenuWork *)(p->taskMenu))) {v=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(p->taskMenu));POKETRADE_SAVE_CloseTaskMenu(p);POKETRADE_SAVE_CloseMessageWindowClear(p);p->taskMenu=0;switch(v) {case 0:POKETRADE_PROC_SetStep(p,POKETRADE_PROC_ShowIntroMessage);return;case 1:WIPE_SYS_Start((void *)3,0,0,0,6,1,p->heapId);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepAfterSummaryWipe);return;case 2:POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendNewRound);return;} } }

void POKETRADE_PROC_StepShowTradeSummary(TradeWork *p) { int i; MSGDATA_ReadString((struct MsgBank *)(p->messageBank),17,(struct Strbuf *)((void *)((p->messageTemplate))));for(i=0;i<2;i++) WORDSET_SetSlotMonNickname((struct WordSet *)((*(void * *)&p->wordSet)),i,(void *)POKETRADE_PROC_GetSideMon(p,i));WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(struct Strbuf *)((void *)(p->messageText)),(struct Strbuf *)((void *)((p->messageTemplate))));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepOpenMainMenu); }

void POKETRADE_PROC_StepOpenMainMenu(TradeWork *p) { if(POKETRADE_SAVE_IsMessagePrintDone(p)) { PokemontradeIntTriple t=gMainMenuLayout; POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),3); BG_SYS_SetMainVisiblePlanes(31); TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),1,0); POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepMainMenuChoice); } }

void POKETRADE_PROC_StepWaitSync20(TradeWork *p) {
 if(POKETRADE_PROC_IsNetSession(p)) {
  if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),20,8)) {
   POKETRADE_SAVE_CloseMessageWindowClear(p); POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginWipeOut);
  }
 } else { POKETRADE_SAVE_CloseMessageWindowClear(p); POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginWipeOut); }
}

void POKETRADE_PROC_StepStartSync20(TradeWork *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p) && p->waitCounter>30) {
  if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),20,8);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitSync20);
 }
}

void POKETRADE_PROC_StepIntro(TradeWork *p)
{
    int cmd;
    u32 other;
    u32 me;
    u32 a;

    me = GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle());
    other = 1 - me;
    if (POKETRADE_PROC_IsNetSession(p) == 0) {
        me = 0;
        other = 1;
    }
    if (POKETRADE_PROC_IsNetSession(p) != 0 && GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1a, 8) == 0) {
        POKETRADE_NEGO_CheckCancelTouch(p);
        return;
    }
    POKETRADE_NEGO_CloseCancelMenu(p, 1, 1);
    a = p->choice[me];
    if (a == 1 && p->choice[other] == 1) {
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepShowTradeSummary);
        return;
    }
    if (a == 4 && p->choice[other] == 4) {
        p->request->state = 3;
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x8d, (void *)(p->messageText));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_SAVE_ShowTimeIcon(p);
        p->waitCounter = 0;
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepStartSync20);
        return;
    }
    if (p->choice[other] == 4)
        cmd = 0x61;
    else if (a == 4)
        cmd = 0x66;
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank), cmd, (void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p->choice[0] = 0;
    p->choice[1] = 0;
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepShowWaitMessageA);
}

void POKETRADE_PROC_StepSendIntroReady(TradeWork *p) { int kind=POKETRADE_PROC_IsNetSession(p); u8 b; if(POKETRADE_SAVE_IsMessagePrintDone(p)) { if(kind==0) {p->choice[0]=1;p->choice[1]=1;POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepIntro);return;} b=1; if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)==0) return; GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepIntro); } }

void POKETRADE_PROC_StepMenuChoice(TradeWork *p) {
    int v;
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)(p->taskMenu))) {
        v=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(p->taskMenu));
        POKETRADE_SAVE_CloseTaskMenu(p);
        p->taskMenu=0;
        if (v==0) {
            MSGDATA_ReadString((struct MsgBank *)(p->messageBank),6,(void *)(p->messageText));
            POKETRADE_SAVE_OpenMessageWindowTop(p);
            POKETRADE_SAVE_ShowTimeIcon(p);
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendIntroReady);
            return;
        }
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepResetGrid);
    }
}

void POKETRADE_PROC_StepOpenMenu(TradeWork *p)
{
    if (POKETRADE_PROC_SendSideMon(p)) {
        PokemontradeProcPair t = gOpenMenuPos;
        POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
        G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR,0x1B,-8);
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepMenuChoice);
    }
}

void POKETRADE_PROC_StepSendPartyBoxSelected(TradeWork *p)
{
    int v = 0;
    if (p->selectedBox == p->partyBoxId) v=1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xC16,1,&v))
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepOpenMenu);
}

void POKETRADE_PROC_HideTouchbarButtons(TradeWork *p) {
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),7,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),8,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),9,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),1,0);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->cursorActor),0);
    POKETRADE_PROC_ClearDragIcon(p);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendPartyBoxSelected);
}

void POKETRADE_PROC_SetDragTarget(TradeWork *p,int a,int b) {
 p->cursorSlot=a;
 p->cursorColumn=b;
 POKETRADE_PROC_RequestBoxRedraw(p);
}

int POKETRADE_PROC_PollGridTouch(TradeWork *p,int *a,int *b,int *c,int *d) {
    int x, y, z; void *n;
    if(TOUCHPANEL_GetPointTrg((unsigned int *)(&x),(unsigned int *)(&y))==1) {
        if(POKETRADE_2D_HitTestBoxIcons(p,x+12,y+12,a,b,c,d,&z)) {
            n=POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager),*a,*b,p);
            if(n && POKE_TOOL_GetBoxValue((void *)n,0xA9,0)) return 1;
        }
    }
    return 0;
}

int POKETRADE_PROC_PollGridTouchDrag(TradeWork *p,int save)
{
 int x, y, a, b, c, result=0; void *e; struct ClactActor *hit;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))==1) {
  hit=POKETRADE_2D_HitTestBoxIcons(p,x+12,y+12,&p->highlightBox,&p->highlightSlot,&a,&b,&c);
  if(hit) {
   e=POKETRADE_PROC_LoadSlotMonAlt((void *)p->boxManager,p->highlightBox,p->highlightSlot,p);
   if(POKETRADE_PROC_IsTradeTargetValid(p,p->highlightBox,p->highlightSlot)) {
    GFL_USE_PlaySeDefaultVolume(0x626);
    if(!POKETRADE_PROC_IsHostSide(p)) {POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepClearPeerSelection);return 3;}
    p->peerSelectedBox=p->highlightBox;p->peerSelectedSlot=p->highlightSlot;POKETRADE_PROC_SetStep(p,POKETRADE_NEGO_StepSendOfferRemoval);return 3;
   }
   POKETRADE_PROC_ShowDragIcon(p);
   if(e && POKE_TOOL_GetBoxValue((void *)e,0xa9,0)) {
    if(POKETRADE_PROC_CanTradeMon(p,e)) {
     MSGDATA_ReadString((struct MsgBank *)p->messageBank,0x8e,(void *)p->messageText);POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitKeyAfterMessage);return 2;
    }
    POKETRADE_PROC_BeginDrag(p,hit,c,b,e);POKETRADE_PROC_SetDragTarget(p,a,b);
    if(save) {p->peerSelectedBox=p->highlightBox;p->peerSelectedSlot=p->highlightSlot;}
    POKETRADE_PROC_RequestBoxRedraw(p);result=1;
   }
  }
 }
 return result;
}

void POKETRADE_PROC_StepWaitKeyAfterMessage(TradeWork *p) {
    int v;
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        v=KEY_GetTrg();
        if(v) UI_SetInputMode(0);
        if(!v) {
            v=TOUCHPANEL_GetTrg();
            if(v) UI_SetInputMode(1);
            if(!v) return;
        }
        p->highlightBox=-1;
        p->highlightSlot=-1;
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
        p->cursorRow=-1;
        POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,1);
    }
}

void POKETRADE_PROC_ShowCancelMessage(TradeWork *p)
{
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x65, (void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p->cursorRow = -1;
    POKETRADE_2D_UpdateVisibleColumns(p->boxManager, p, 0);
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepWaitKeyAfterMessage);
}

void POKETRADE_PROC_ShowSelectMessage(TradeWork *p)
{
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x8E, (void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);
    p->cursorRow = -1;
    POKETRADE_2D_UpdateVisibleColumns(p->boxManager, p, 0);
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepWaitKeyAfterMessage);
}

void POKETRADE_PROC_ShowPeerSummary(TradeWork *p) {
    void *v=POKETRADE_PROC_LoadSlotMon(*(void ** *)&p->boxManager,p->peerSelectedBox,p->peerSelectedSlot,p);
    POKETRADE_SAVE_CloseSummaryWindow(p,0);
    POKETRADE_SAVE_DrawSummaryPage(p,p->cursorIndex,v);
    if (UI_GetInputMode()) POKETRADE_PROC_RequestBoxRedraw(p);
    GFL_HEAP_Free(v);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepPeerSummaryMenu);
}

void POKETRADE_PROC_StepAddSelectedOffer(TradeWork *p) {
 if(POKETRADE_NEGO_AddSelectedAsOffer(p,p->selectedSlot,p->selectedBox)) POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepRebuildBrowseScene);
}

void POKETRADE_PROC_StepSendAddOffer(TradeWork *p) {
    int v=0;
    int n;
    if(p->selectedBox==p->partyBoxId) v=1;
    n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,p->selectedSlot,p->selectedBox);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,&v)) {
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepAddSelectedOffer);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepAddSelectedOffer);
}

void POKETRADE_PROC_StepApplyAddOffer(TradeWork *p) {
 if(POKETRADE_NEGO_AddSelectedAsOffer(p,p->selectedSlot,p->selectedBox)) POKETRADE_PROC_SetStep(p,POKETRADE_NEGO_StepShowCancelMessage);
}

void POKETRADE_PROC_StepSendApplyAddOffer(TradeWork *p) {
    int v=0;
    int n;
    if(p->selectedBox==p->partyBoxId) v=1;
    n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,p->selectedSlot,p->selectedBox);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,&v)) {
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepApplyAddOffer);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepApplyAddOffer);
}

#if LANGUAGE != LANGUAGE_JAPANESE
void POKETRADE_PROC_StepWaitTouchReleasePeer(TradeWork *p) {
 int a,b;
 if(!TOUCHPANEL_GetPointCont((u32 *)(&a),(u32 *)(&b))) POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
}
#endif

void POKETRADE_PROC_StepPeerSummaryMenu(TradeWork *p)
{
    u32 x,y;
    int slot,column;
    int changed=0;
    int keep=1;
    int choice=keep-2;
    int active=0;
    int n;
    void *m;
    if(!APP_TASKMENU_IsDecide(p->taskMenu)) {
        n=TOUCHPANEL_GetTrg();
        if(n) UI_SetInputMode(keep);
        if(n) POKETRADE_PROC_ShowDragIcon(p);
        TOUCHBAR_Update(p->touchbar);
        if(TOUCHBAR_GetPressedButtonIdIfPressing(p->touchbar)==9 && UI_GetInputMode()) APP_TASKMENU_SetCursorActive(p->taskMenu,0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(p->touchbar)==9) {
            changed=1;
            (p->cursorIndex)=1U-(p->cursorIndex);
        }
        if(TOUCHPANEL_GetPointTrg(&x,&y)==1) {
            UI_SetInputMode(1);
            APP_TASKMENU_SetCursorActive(p->taskMenu,0);
            if(POKETRADE_PROC_PollGridTouch(p,&p->peerSelectedBox,&p->peerSelectedSlot,&slot,&column)) {
                p->cursorColumn=column;
                p->cursorSlot=slot;
                (p->iconPosX)=x;
                (p->iconPosY)=y;
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed=1;
            } else if(y>=16 && y<144) active=1;
        }
        if(changed) {
            POKETRADE_SAVE_CloseSummaryWindow(p,1);
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_ShowPeerSummary);
            return;
        }
        POKETRADE_PROC_UpdateDragIcon(p);
        if(!active && !TOUCHPANEL_GetCont() && p->prevTouch) {
            if(p->dragActor && p->dragMoved) {
                GFL_USE_PlaySeDefaultVolume(0x72a);
                choice=0;
                active=1;
            } else POKETRADE_PROC_ShowDragIcon(p);
        }
        POKETRADE_PROC_UpdateDragState(p);
        POKETRADE_PROC_UpdateDragIcon(p);
    }
    if(APP_TASKMENU_IsFinish(p->taskMenu)) {
        choice=APP_TASKMENU_GetCursorPos(p->taskMenu);
        active=1;
    }
    if(active) {
        if(choice==0) {
            m=POKETRADE_PROC_LoadSlotMonAlt((void *)p->boxManager,p->peerSelectedBox,p->peerSelectedSlot,p);
            if(POKETRADE_PROC_IsTradeTargetValid(p,p->peerSelectedBox,p->peerSelectedSlot) && POKETRADE_PROC_IsHostSide(p)) {
                p->selectedSlot=p->peerSelectedSlot;
                p->selectedBox=p->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendAddOffer);
            } else if(POKETRADE_PROC_IsSelectedOfferSlot(p,p->peerSelectedBox,p->peerSelectedSlot)) {
                POKETRADE_NEGO_SetOfferMarkersState(p,1);
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_ShowCancelMessage);
            } else if(POKETRADE_PROC_CanTradeMon(p,m)) {
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_ShowSelectMessage);
                POKETRADE_NEGO_SetOfferMarkersState(p,1);
            } else if(!POKETRADE_PROC_IsHostSide(p)) {
                p->selectedSlot=p->peerSelectedSlot;
                p->selectedBox=p->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_HideTouchbarButtons);
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),7,0);
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),8,0);
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),9,0);
                keep=0;
            } else if(POKETRADE_NEGO_CanConfirmOffers(p) && !UI_GetInputMode()) {
                p->selectedSlot=p->peerSelectedSlot;
                p->selectedBox=p->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendApplyAddOffer);
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),7,0);
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),8,0);
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),9,0);
                keep=0;
            } else {
                p->selectedSlot=p->peerSelectedSlot;
                p->selectedBox=p->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendAddOffer);
            }
        } else {
            POKETRADE_NEGO_SetOfferMarkersState(p,1);
#if LANGUAGE == LANGUAGE_JAPANESE
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
#else
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitTouchReleasePeer);
#endif
        }
        p->peerSelectedBox=-1;
        p->peerSelectedSlot=-1;
        if(keep) {
            POKETRADE_PROC_UpdateTouchbarButtons(p);
            CLACT_SetActorDrawEnable(p->cursorActor,1);
        }
        POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[0]);
        POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[1]);
        POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[2]);
        POKETRADE_SAVE_CloseSummaryWindow(p,1);
        BG_SYS_MarkTileDirty(6);
        POKETRADE_2D_ClearSummaryBackground(p);
        POKETRADE_SAVE_CloseTaskMenu(p);
        p->taskMenu=0;
    }
    p->prevTouch=TOUCHPANEL_GetCont();
}

void POKETRADE_PROC_StepOpenPeerSummary(TradeWork *p) {
    PokemontradeProcPair t;
    void *n;
    int zero=0;
    POKETRADE_NEGO_SetOfferMarkersState(p,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),1,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),7,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),9,1);
    t=gPeerSummaryPos;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
    n=POKETRADE_PROC_LoadSlotMon(*(void ** *)&p->boxManager,p->peerSelectedBox,p->peerSelectedSlot,p);
    p->cursorIndex=zero;
    POKETRADE_SAVE_DrawSummaryPage(p,0,n);
    GFL_HEAP_Free(n);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->cursorActor),0);
    POKETRADE_PROC_ShowDragIcon(p);
    POKETRADE_PROC_RequestBoxRedraw(p);
    if(UI_GetInputMode()) APP_TASKMENU_SetCursorActive((struct TaskMenuWork *)(p->taskMenu),zero);
    else APP_TASKMENU_SetCursorActive((struct TaskMenuWork *)(p->taskMenu),1);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepPeerSummaryMenu);
}

void POKETRADE_PROC_StepSendCursorChoice(TradeWork *p) {
 u8 b=p->cursorIndex;
 if(POKETRADE_PROC_IsNetSession(p)) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,1,&b)==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(POKETRADE_PROC_IsHostSide(p)==0) POKETRADE_PROC_SetStep(p,POKETRADE_IRCDEMO_StepStartCompare);
 else POKETRADE_PROC_SetStep(p,POKETRADE_DEMO_MIDDLE_StepStartCompare);
}

void POKETRADE_PROC_StepWaitCursorSync(TradeWork *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),13,8)) POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendCursorChoice);
}

void POKETRADE_PROC_StepResolveCursorResult(TradeWork *p) {
 int i, j, v;
 unsigned char a, b;
 i = GFL_NET_GetHandleNetID((struct GFLNetHandle *)(GFL_NET_HANDLE_GetCurrentHandle()));
 j = 1 - i;
 if(POKETRADE_PROC_IsNetSession(p) && GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),27,8)==0) {
  POKETRADE_NEGO_CheckCancelTouch(p);
  return;
 }
 POKETRADE_NEGO_CloseCancelMenu(p,1,1);
 a = p->choice[i];
 if(a==2 && p->choice[j]==2) {
  if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),13,8);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitCursorSync);
  return;
 }
 b = p->choice[j];
 if(b==5) v=0x61;
 else if(a==5) v=0x62;
 else if(b==7) v=0x63;
 else if(a==7) v=0x64;
 else if(b==8) v=0x64;
 else if(a==8) v=0x63;
 else if(b==9) v=0x61;
 else if(a==9) v=0x65;
 else if(b==6) v=0x61;
 else if(a==6) v=0x6f;
 else if(b==3) v=0x61;
 else if(a==3) v=0x66;
 MSGDATA_ReadString((struct MsgBank *)((p->messageBank)),v,(void *)((p->messageText)));
 POKETRADE_SAVE_OpenMessageWindowTop(p);
 p->choice[0]=0;
 p->choice[1]=0;
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepShowWaitMessageA);
}

void POKETRADE_PROC_StepRebuildTradeScene(TradeWork *p) {
 if(POKETRADE_PROC_IsHostSide(p)) {POKETRADE_PROC_StepResetGrid(p);POKETRADE_PROC_StepEnterBrowsing(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitKeyThenBrowse);}
 else {POKETRADE_PROC_StepResetGrid(p);POKETRADE_PROC_StepEnterBrowsing(p);}
 WIPE_SYS_Start(0,1,1,0,6,1,p->heapId);
 BG_SYS_SetMainVisiblePlanes(31);BG_SYS_SetSubVisiblePlanes(30);
}

void POKETRADE_PROC_StepRestoreBrowseScene(TradeWork *p)
{
 if(POKETRADE_PROC_IsNetSession(p) && !GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)) return;
 POKETRADE_SAVE_CloseMessageWindowClear(p);
 if(POKETRADE_PROC_IsHostSide(p)) {
  POKETRADE_NEGO_ClearOfferSlots(p);POKETRADE_NEGO_ExitMarkers(p);
  if(p->tradeState==2) DWC_RAP_SetVchatTalkLock(0);
  MSGDATA_ReadString((struct MsgBank *)(p->messageBank),134,(void *)(p->messageText));POKETRADE_SAVE_OpenMessageWindowTop(p);
  POKETRADE_NEGO_RegisterIconResources(p,0);POKETRADE_NEGO_DrawPlayerNames(p);
  p->labelStateA=0;p->labelStateB=0;
  POKETRADE_NEGO_InitOfferMarkers(p);POKETRADE_NEGO_SetOfferMarkersState(p,1);
  MI_CpuFill8(p->boxIconId,0,sizeof(p->boxIconId));MI_CpuFill8(p->boxIconB2,0,sizeof(p->boxIconB2));MI_CpuFill8(p->boxIconB3,0,sizeof(p->boxIconB3));
  POKETRADE_PROC_ShowDragIcon(p);
  if(p->taskMenu) {APP_TASKMENU_CloseMenu((struct TaskMenuWork *)(p->taskMenu));p->taskMenu=0;}
  POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_UpdateTouchbarButtons(p);
 }
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepRebuildTradeScene);POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
}

void POKETRADE_PROC_StepWaitThenRestoreScene(TradeWork *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p) && WIPE_SYS_EndCheck()) {
  POKETRADE_SAVE_CloseMessageWindowClear(p);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepRestoreBrowseScene);
 }
}

void POKETRADE_PROC_StepBeginWipeToRestore(TradeWork *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,p->heapId);
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitThenRestoreScene);
}

void POKETRADE_PROC_StepWaitSyncThenWipe(TradeWork *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)!=0) {
  POKETRADE_3D_UploadCubeTextures(p);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginWipeToRestore);
 }
}

void POKETRADE_PROC_StepSendTradeData(TradeWork *p) {
 if(POKETRADE_PROC_IsNetSession(p)) {
  if(GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0e,0x2d6,(void *)p->boxMarking,0,0,1)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,8);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitSyncThenWipe);
  }
 } else {POKETRADE_3D_UploadCubeTextures(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitSyncThenWipe);}
}

void POKETRADE_PROC_StepBuildTradeRecord(TradeWork *p) {
 POKETRADE_PROC_BuildTradeRecords(p,p->waitCounter-1);
 if(p->waitCounter>=24) POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendTradeData);
}

void POKETRADE_PROC_StepBuildMarkingTable(TradeWork *p) {
 if(POKETRADE_2D_BuildMarkingTablesFrom(p,p->waitCounter-1)) {
  p->waitCounter=0;
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBuildTradeRecord);
 }
}

void POKETRADE_PROC_StepSendBoxInfo(TradeWork *p) {
 u8 b[2];
 if(POKETRADE_PROC_IsNetSession(p)) {
  b[0]=p->partyBoxId;b[1]=POKETRADE_PROC_IsMailBoxFull(p);
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc10,2,(void *)b)) {p->waitCounter=0;POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBuildMarkingTable);}
 } else {
  p->storedBoxIndex=p->partyBoxId;(*(unsigned short *)&p->scrollY)=p->storedBoxIndex*160+16;
  p->waitCounter=0;POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBuildMarkingTable);
 }
}

void POKETRADE_PROC_StepLoadBoxIconGfx(TradeWork *p) {
 POKETRADE_2D_LoadBoxIconGfx(p,p->waitCounter-1);
 if(p->waitCounter>25) {
  POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,0);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendBoxInfo);
 }
}

void POKETRADE_PROC_StepWaitNetSync22(TradeWork *p) {
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),22,8)) {
  GFL_NET_SetAutoExit(1);
  GFL_NET_SetLoginOption(1);
  p->waitCounter=0;
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepLoadBoxIconGfx);
 }
}

void POKETRADE_PROC_StepAfterWipeLoadBox(TradeWork *p) {
 if(WIPE_SYS_EndCheck()) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),22,8);
   POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitNetSync22);
  } else { POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendBoxInfo); }
 }
}

void POKETRADE_PROC_StepRestartNetSession(TradeWork *p) {
 GFL_NET_RefreshWmIconAtTopRight(1,p->heapId);if(p->tradeState==2)DWC_RAP_SetVchatTalkLock(1);
 MSGDATA_ReadString((struct MsgBank *)(p->messageBank),6,(void *)(p->messageText));POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);POKETRADE_SAVE_ShowTimeIcon(p);
 BG_SYS_SetMainVisiblePlanes(16);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(0);
 WIPE_SYS_Start((void *)4,1,1,0,6,1,p->heapId);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepAfterWipeLoadBox);
}

void POKETRADE_PROC_StepResetForNewRound(TradeWork *p) {
 int i;
 GFL_NET_SYSTEM_GetCurrentAid();p->selectedBox=-1;p->selectedSlot=-1;p->filterIndex=0;p->dragActor=0;p->netFlag=0;
 POKETRADE_3D_DeleteMcssSlot(p,0);POKETRADE_3D_DeleteMcssSlot(p,1);if(POKETRADE_PROC_IsHostSide(p))POKETRADE_NEGO_ClearOfferSlots(p);
 MI_CpuFill8((void *)(p->monABuf),0,POKE_TOOL_GetPartyParamSize());MI_CpuFill8((void *)(p->monBBuf),0,POKE_TOOL_GetPartyParamSize());
 for(i=0;i<10;i++) {if(p->uiActor[i])CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->uiActor[i]),1);}
 POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepRestartNetSession);
}

void POKETRADE_PROC_StepWaitMessageThenResolve(TradeWork *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),27,8);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepResolveCursorResult);
 }
}

void POKETRADE_PROC_StepSendNewRound(TradeWork *p)
{
    u8 b = 3;

    if (POKETRADE_PROC_IsNetSession(p) == 0) {
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 0x61,
                      (void *)(p->messageText));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepShowWaitMessageA);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank), 6, (void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepWaitMessageThenResolve);
}

void POKETRADE_PROC_StepClearOffersNewRound(TradeWork *p) {
 int i;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {POKETRADE_NEGO_CheckCancelTouch(p);return;}
 POKETRADE_NEGO_CloseCancelMenu(p,1,1);POKETRADE_SAVE_CloseMessageWindowClear(p);
 p->choice[0]=0;p->choice[1]=0;p->labelState[0]=0;p->labelState[1]=0;
 for(i=0;i<6;i++) {
  p->offerSlot[i/3][i%3]=-1;
  if(p->offerMon[i/3][i%3])MI_CpuFill8(p->offerMon[i/3][i%3],0,POKE_TOOL_GetPartyParamSize());
 }
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepResetGrid);
}

void POKETRADE_PROC_StepWaitMessageThenClear(TradeWork *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),25,8);
  POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepClearOffersNewRound);
 }
}

static inline int poll_a(void) {int r=KEY_GetTrg();if(r)UI_SetInputMode(0);return r;}

static inline int poll_b(void) {int r=TOUCHPANEL_GetTrg();if(r)UI_SetInputMode(1);return r;}

void POKETRADE_PROC_StepShowWaitMessageA(TradeWork *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  if(poll_a() || poll_b()) {
   POKETRADE_SAVE_CloseMessageWindowClear(p);
   if(POKETRADE_PROC_IsNetSession(p)) {
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),50,(void *)(p->messageText));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitMessageThenClear);
   } else POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepResetGrid);
  }
 }
}

void POKETRADE_PROC_StepSendContinue(TradeWork *p) {
 GFLNetHandle *id=GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   b=2;
   if(GFL_NET_SendToHandle(id,0xc0f,1,&b)) POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepIntro);
  } else { POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepIntro); }
 }
}

void POKETRADE_PROC_StepSendStartRound(TradeWork *p) {
 u8 b;
 if(POKETRADE_PROC_IsNetSession(p)) {
  b=4;
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)) {
   MSGDATA_ReadString((struct MsgBank *)(p->messageBank),136,(void *)(p->messageText));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);
   GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendContinue);
  }
 } else {p->request->state=3;POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginWipeOut);}
}

/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, short derives -1 from zero.
 */
/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 */
void POKETRADE_PROC_StepSummaryMenuChoice(TradeWork *p) {
 int v;
 if(APP_TASKMENU_IsFinish((struct TaskMenuWork *)(p->taskMenu))) {
  v=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(p->taskMenu));POKETRADE_SAVE_CloseTaskMenu(p);p->taskMenu=0;
  switch(v) {
  case 0:POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSendStartRound);return;
  case 1:POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
   p->cursorRow=-1;POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,0);POKETRADE_2D_SetupSubBlend(p);return;
  }
 }
}

int POKETRADE_PROC_SendSideMon(TradeWork *p)
{
    void *t=POKETRADE_PROC_LoadSlotMon(*(void ** *)&p->boxManager,p->selectedBox,p->selectedSlot,p);
    if(POKETRADE_PROC_IsNetSession(p)) {
        GFLNetHandle *id=GFL_NET_HANDLE_GetCurrentHandle();
        if(GFL_NET_SendToHandle(id,(u16)0xc01,(u16)POKE_TOOL_GetPartyParamSize(),t)==0) {
            GFL_HEAP_Free(t);
            return 0;
        }
    }
    POKETRADE_PROC_SetSideMon(p,0,t);
    GFL_HEAP_Free(t);
    return 1;
}

void POKETRADE_PROC_StepOpenSummaryMenu(TradeWork *p)
{
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        PokemontradeProcPair t=gSummaryMenuPos;
        POKETRADE_SAVE_OpenTaskMenuAt(p,(int *)(&t),2,0x20,0xc);
        p->cursorRow=-1;
        POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,0);
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSummaryMenuChoice);
    }
}

void POKETRADE_PROC_StepShowSummaryMessage(TradeWork *p) {
 MSGDATA_ReadString((struct MsgBank *)((p->messageBank)),0x8c,(void *)((p->messageText)));
 POKETRADE_SAVE_OpenMessageWindowTop(p);
 p->redrawFlag=1;
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepOpenSummaryMenu);
}

void POKETRADE_PROC_StepSlideInSubScreen(TradeWork *p) {
 G2x_SetBlendBrightness_((uptr)((void *)REG_DB_BLDCNT_ADDR),27,-8);
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepShowSummaryMessage);
}

int POKETRADE_PROC_FindMatchingBoxIcon(TradeWork *p,int kind)
{
    int index=POKETRADE_2D_GetScrollColumn(p);
    int outer;
    for(outer=0;outer<p->slotCount;outer++) {
        int inner;
        index++;
        if(index>=p->slotCount) index=0;
        for(inner=0;inner<5;inner++) {
            int a=POKETRADE_PROC_GetBoxIndexForSlot(index,p);
            int b=POKETRADE_PROC_GetSlotIndexInBox(index,inner);
            void *obj=POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager),a,b,p);
            if(obj && POKETRADE_2D_IsBoxIconMatch(POKE_TOOL_GetBoxValue((void *)obj,0xab,0),kind) && !POKE_TOOL_GetBoxValue((void *)obj,0x4c,0)) {
                p->cursorRow+=1;
                p->scrollX=POKETRADE_PROC_GetSlotPosition(index)-0x20;
                p->redrawNeeded=1;
                POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
                return 1;
            }
        }
    }
    return 0;
}

void POKETRADE_PROC_StepCloseSubScreenDone(TradeWork *p) {
 BG_SYS_SetSubVisiblePlanes(30);
 POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
}

/*
 * volatile: hardware read/write at 021DB2AA/021DB2AE
 */
void POKETRADE_PROC_StepExitSubScreen(TradeWork *p)
{
    BG_SYS_SetSubVisiblePlanes(0x1a);
    POKETRADE_2D_ClearSubScreen(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    *(volatile unsigned *)0x04001000 &= 0xffff1fff;
    POKETRADE_NEGO_SetOfferMarkersState(p,1);
    POKETRADE_2D_FadePaletteAll(p,0);
    POKETRADE_PROC_UpdateTouchbarButtons(p);
    POKETRADE_2D_SetupSubBlend(p);
    POKETRADE_2D_DeleteCursorActor(p);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepCloseSubScreenDone);
}

void POKETRADE_PROC_StepWaitCursorFade(TradeWork *p) {
 if(POKETRADE_2D_ClearCursorIfDisabled(p)==0) POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepExitSubScreen);
}

/*
 * lever: non-const table keeps reads after the p+0x800 store (const: 16 bytes differ).
 * volatile: hardware read/write at 021DB358/021DB35C and 021DB3C6/021DB3CA.
 * prototype: 02035C08 returns the live r0 result of 02035BBC (full original
 * 02035BBC and matched forwarder read); caller uses it despite void header.
 */
void POKETRADE_PROC_StepSubScreenList(TradeWork *p)
{
    int index;
    BG_SYS_SetSubVisiblePlanes(31);
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        index=TOUCHPANEL_HitTrg((const TouchHitTable *)gSubScreenHitAreas);
        if(index!=-1) {
            (p->filterIndex)=(u32)index+1u;
            POKETRADE_2D_CreateCursorActor(p,gSubScreenHitAreas[index].c,gSubScreenHitAreas[index].a);
            if(POKETRADE_PROC_FindMatchingBoxIcon(p,index)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xffff1fff;
                POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitCursorFade);
                return;
            }
            MSGDATA_ReadString((struct MsgBank *)(p->messageBank),0x34,(void *)(p->messageText));
            POKETRADE_SAVE_OpenMessageWindow(p,1,1,1,0x1d,4);
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
        TOUCHBAR_Update((TouchBar *)((*(void * *)&p->touchbar)));
        if(TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)(*(u8 * *)&p->touchbar))==1) {
            BG_SYS_SetSubVisiblePlanes(0x1a);
            p->filterIndex=0;
            POKETRADE_2D_ClearSubScreen(p);
            POKETRADE_SAVE_CloseMessageWindowClear(p);
            *(volatile u32 *)REG_DB_DISPCNT_ADDR &= 0xffff1fff;
            POKETRADE_NEGO_SetOfferMarkersState(p,1);
            POKETRADE_2D_FadePaletteAll(p,0);
            POKETRADE_PROC_UpdateTouchbarButtons(p);
            POKETRADE_2D_SetupSubBlend(p);
            POKETRADE_2D_DeleteCursorActor(p);
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepExitSubScreen);
        }
    }
}

void POKETRADE_PROC_StepOpenSubScreen(TradeWork *p)
{
    POKETRADE_2D_LoadSubScreenGfx(p);
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),0x33,(void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindow(p,1,1,1,0x1d,4);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSubScreenList);
}

void POKETRADE_PROC_StepBeginOpenSubScreen(TradeWork *p)
{
    TOUCHBAR_SetButtonEnabled(p->touchbar,7,0);
    POKETRADE_NEGO_SetOfferMarkersState(p,0);
    G2x_SetBlendBrightness_((uptr)((void *)REG_DB_BLDCNT_ADDR),10,-8);
    POKETRADE_2D_FadePaletteAll(p,1);
    if(POKETRADE_NEGO_HasOffer(p))
        TOUCHBAR_SetButtonEnabled((p->touchbar),8,0);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepOpenSubScreen);
}

/*
 * Position of a slot: 0 and 1 are special, the rest on a 6-column grid.
 * Lever: the remainder is stored back into the same local as the dividend
 * (b = b % 6); a separate remainder local stays in r1 and changes colours.
 */
int POKETRADE_PROC_GetSlotPosition(int a)
{
    int b, q;

    if (a == 0)
        return 0;
    if (a == 1)
        return 0x30;
    b = a - 2;
    q = b / 6;
    b = b % 6;
    return q * 0xa0 + 0x60 + b * 0x1a;
}

int POKETRADE_PROC_IsSlotVisible(TradeWork *p, int index)
{
    int position = POKETRADE_PROC_GetSlotPosition(index);
    int start = p->scrollX;
    if (start < position && start + 0xe0 > position)
        return 1;
    position += p->gridOriginX;
    if (start < position && start + 0xe0 > position)
        return 1;
    return 0;
}

void POKETRADE_PROC_PollGridKeys(TradeWork *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = KEY_GetRepeat();
    if (p->dragActor != 0)
        return;
    if (k & 0x100) {
        UI_SetInputMode(0);
        for (i = 0; i < p->partyBoxId + 1; i++) {
            if (gScrollSnapPos[i] > p->scrollX) {
                p->scrollX = gScrollSnapPos[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            p->scrollX = gScrollSnapPos[0];
        }
        POKETRADE_PROC_ClampScrollColumn(p, changed);
    } else if (k & 0x200) {
        UI_SetInputMode(0);
        for (i = p->partyBoxId; i >= 0; i--) {
            if (gScrollSnapPos[i] < p->scrollX) {
                p->scrollX = gScrollSnapPos[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            p->scrollX = gScrollSnapPos[p->partyBoxId];
        }
        POKETRADE_PROC_ClampScrollColumn(p, changed);
    } else if (KEY_GetRepeat() == 0x40) {
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0)
            p->cursorSlot = v;
        if (--p->cursorColumn < 0) {
            if (p->cursorSlot < 2)
                p->cursorColumn = 2;
            else
                p->cursorColumn = 4;
        }
        p->cursorRow = p->cursorRow - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x80) {
        int x;
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0)
            p->cursorSlot = v;
        x = ++p->cursorColumn;
        if (p->cursorSlot < 2) {
            if (x >= 3)
                p->cursorColumn = 0;
        } else if (x >= 5)
            p->cursorColumn = 0;
        p->cursorRow = p->cursorRow - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x10) {
        UI_SetInputMode(0);
        p->cursorRow = p->cursorRow - 1;
        changed = 1;
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0) {
            p->cursorSlot = v;
        } else {
            p->cursorSlot = p->cursorSlot + 1;
            if (POKETRADE_PROC_IsSlotVisible(p, p->cursorSlot) == 0) {
                p->scrollX = POKETRADE_PROC_GetSlotPosition(p->cursorSlot + 1) - 0x100;
                p->cursorRow = -1;
            }
        }
        if (p->cursorSlot >= p->slotCount)
            p->cursorSlot = 0;
        if (p->cursorSlot < 2 && p->cursorColumn >= 3)
            p->cursorColumn = 2;
    } else if (KEY_GetRepeat() == 0x20) {
        UI_SetInputMode(0);
        p->cursorRow = p->cursorRow + 1;
        changed = 1;
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0) {
            p->cursorSlot = v;
        } else {
            p->cursorSlot = p->cursorSlot - 1;
            if (p->cursorSlot < 0)
                p->cursorSlot = p->slotCount - 1;
            if (POKETRADE_PROC_IsSlotVisible(p, p->cursorSlot) == 0) {
                p->scrollX = POKETRADE_PROC_GetSlotPosition(p->cursorSlot);
                p->cursorRow = -1;
            }
        }
        if (p->cursorSlot < 0)
            p->cursorSlot = p->slotCount - 1;
        if (p->cursorSlot < 2 && p->cursorColumn >= 3)
            p->cursorColumn = 2;
    }
    if (changed) {
        p->redrawNeeded = 1;
        GFL_USE_PlaySeDefaultVolume(0x548);
        POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 1);
    }
}

void POKETRADE_PROC_RedrawAndSyncGrid(TradeWork *p,int a,int b)
{
    if(p->scrollX<0) p->scrollX+=(short)p->gridOriginX;
    if(p->gridOriginX<=p->scrollX) p->scrollX-=(short)p->gridOriginX;
    POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,1);
    POKETRADE_2D_DrawBoxGridScreen(p);
    POKETRADE_2D_DrawBoxNames(p);
    if(GFL_USE_IsAnySeBusy()==0 && a) GFL_USE_PlaySeDefaultVolume(0x72b);
    if(POKETRADE_PROC_IsNetSession(p) && b) {
        if(GFL_NET_IsNetTypeWifi()) {
            if(p->scrollX%16==0) {
                GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(void *)&p->scrollX,0,1,1);
                return;
            }
        } else {
            GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(void *)&p->scrollX,0,1,1);
            return;
        }
    } else {
        if(POKETRADE_PROC_IsNetSession(p)==0) p->scrollY=p->scrollX;
    }
}

void POKETRADE_PROC_DragScrollGrid(TradeWork *p)
{
    int x,y,i;
    if(p->dragActor) return;
    if(TOUCHPANEL_GetPointCont((u32 *)(&x),(u32 *)(&y))) {
        if(p->dragging) {
            if((unsigned)x>=64 && (unsigned)x<192 && (unsigned)y>=168 && (unsigned)y<188) {
                int previous;
                CLACT_SetActorAutoAnim((struct ClactActor *)((struct ClactActor *)p->cursorActor),1);
                previous=p->dragX;
                p->dragVelocity=(x-previous)*2;
                p->dragX=x;
                p->scrollX-=p->dragVelocity;
                if(p->dragVelocity>12) POKETRADE_PROC_RedrawAndSyncGrid(p,1,1);
                else POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
            } else p->dragVelocity=0;
        }
        p->dragX=x;
    } else p->dragX=0;
    if(TOUCHPANEL_GetCont()==0 && p->dragVelocity!=0) {
        for(i=2;i!=0 && p->dragVelocity!=0;i--) {
            if(p->dragVelocity<0) p->dragVelocity++;
            if(p->dragVelocity>0) p->dragVelocity--;
        }
        p->scrollX-=p->dragVelocity;
        POKETRADE_PROC_RedrawAndSyncGrid(p,1,1);
    }
}

void POKETRADE_PROC_StepWaitBrowseRelease(TradeWork *p)
{
    if (TOUCHPANEL_GetCont() == 0)
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepBrowseGrid);
}

void POKETRADE_PROC_StepClearPeerSelection(TradeWork *p)
{
    POKETRADE_NEGO_FindOfferIndex(p,p->peerSelectedBox,p->peerSelectedSlot);
    if(POKETRADE_PROC_IsNetSession(p)) {
        if(!GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)) return;
    }
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),8,0);
    p->selectedSlot=-1;
    p->selectedBox=-1;
    p->highlightSlot=-1;
    p->highlightBox=-1;
    p->peerSelectedSlot=-1;
    p->peerSelectedBox=-1;
    POKETRADE_PROC_ClearSideMon(p,0);
    POKETRADE_PROC_RequestBoxRedraw(p);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepWaitBrowseRelease);
}

void POKETRADE_PROC_StepBeginBrowse(TradeWork *p)
{
    if (POKETRADE_PROC_IsNetSession(p)==0) {
        POKETRADE_PROC_ClearSideMon(p,1);
        POKETRADE_PROC_StepNone(p);
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepEnterBrowsing);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)!=0)
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepEnterBrowsing);
}

void POKETRADE_PROC_StepResetGrid(TradeWork *p)
{
    p->dragging=0;
    p->dragX=0;
    p->dragVelocity=0;
    MI_CpuFill8(p->boxIconId,0,sizeof(p->boxIconId));
    MI_CpuFill8(p->boxIconB2,0,sizeof(p->boxIconB2));
    MI_CpuFill8(p->boxIconB3,0,sizeof(p->boxIconB3));
    POKETRADE_PROC_ShowDragIcon(p);
    POKETRADE_NEGO_SetOfferMarkersState(p,1);
    if(p->taskMenu) {
        APP_TASKMENU_CloseMenu((struct TaskMenuWork *)(p->taskMenu));
        p->taskMenu=0;
    }
    POKETRADE_PROC_ClearSideMon(p,0);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginBrowse);
}

void POKETRADE_PROC_StepEnterBrowsing(TradeWork *p)
{
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),8,0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),7,1);
    TOUCHBAR_SetButtonEnabled((p->touchbar),7,1);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),9,0);
    POKETRADE_PROC_ResetTouchbarBackButton(p);
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->cursorActor),1);
    POKETRADE_2D_CreateBoxWindows(p);
    POKETRADE_2D_SetupSubBlend(p);
    p->selectedSlot=-1;
    p->selectedBox=-1;
    POKETRADE_PROC_RequestBoxRedraw(p);
    POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
}

void POKETRADE_PROC_UpdateTouchbarButtons(TradeWork *p)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct ClactActor *)p->cursorActor),1);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),8,POKETRADE_NEGO_HasOffer(p));
    TOUCHBAR_SetButtonEnabled((p->touchbar),8,POKETRADE_NEGO_HasOffer(p));
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),7,1);
    TOUCHBAR_SetButtonEnabled((p->touchbar),7,1);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),9,0);
    POKETRADE_PROC_ResetTouchbarBackButton(p);
    POKETRADE_PROC_RequestBoxRedraw(p);
}

void POKETRADE_PROC_StepRebuildBrowseScene(TradeWork *p) { POKETRADE_NEGO_SetOfferMarkersState(p,1); MI_CpuFill8(p->boxIconId,0,sizeof(p->boxIconId)); MI_CpuFill8(p->boxIconB2,0,sizeof(p->boxIconB2)); MI_CpuFill8(p->boxIconB3,0,sizeof(p->boxIconB3)); POKETRADE_PROC_ShowDragIcon(p); if(p->taskMenu) {APP_TASKMENU_CloseMenu((struct TaskMenuWork *)p->taskMenu); p->taskMenu=0;} POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_UpdateTouchbarButtons(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);}

void POKETRADE_PROC_StepConfirmSendOffer(TradeWork *p) {
 if(POKETRADE_PROC_IsHostSide(p)) { if(POKETRADE_NEGO_AddSelectedAsOffer(p,p->selectedSlot,p->selectedBox)==0) return; }
 else { if(POKETRADE_PROC_SendSideMon(p)==0) return; }
 p->peerSelectedBox=-1; p->peerSelectedSlot=-1;
 p->highlightSlot=-1; p->highlightBox=-1;
 POKETRADE_PROC_RequestBoxRedraw(p); POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);
}

void POKETRADE_PROC_StepSendOfferConfirm(TradeWork *p) {int same=0;if(p->selectedBox==p->partyBoxId)same=1;if(POKETRADE_PROC_IsHostSide(p)) {int n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,p->selectedSlot,p->selectedBox);if(n!=-1) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xc13),1,&same)) {POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepConfirmSendOffer);return;}} else {POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepConfirmSendOffer);return;}} else {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc16,1,&same))POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepConfirmSendOffer);}}

void POKETRADE_PROC_StepWaitIconFlight(TradeWork *p)
{
    if (POKETRADE_2D_UpdateIconFlight(p)) {
        if (POKETRADE_PROC_IsNetSession(p)) {
            POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepSendOfferConfirm);
            return;
        }
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepConfirmSendOffer);
    }
}

int POKETRADE_PROC_IsTradeTargetValid(TradeWork *p,int a,int b) {
 if(POKETRADE_PROC_IsHostSide(p)==0) {
  if(p->selectedSlot==b && p->selectedBox==a) return 1;
 } else { if(POKETRADE_NEGO_FindOfferIndex(p,a,b)!=-1) return 1; }
 return 0;
}

int POKETRADE_PROC_StepPeerSelectAction(TradeWork *p) {void *e=POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager),p->peerSelectedBox,p->peerSelectedSlot,p);if(POKETRADE_PROC_IsTradeTargetValid(p,p->peerSelectedBox,p->peerSelectedSlot)) {GFL_USE_PlaySeDefaultVolume(0x626);if(POKETRADE_PROC_IsHostSide(p)==0){POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepClearPeerSelection);return 1;}POKETRADE_PROC_SetStep(p,POKETRADE_NEGO_StepSendOfferRemoval);return 1;}if(e && POKE_TOOL_GetBoxValue((struct BoxPokemon *)e,0xa9,0)) {GFL_USE_PlaySeDefaultVolume(0x54b);TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)), 8, 0);POKETRADE_SAVE_CloseTaskMenu(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepOpenPeerSummary);return 1;}POKETRADE_PROC_ShowDragIcon(p);p->peerSelectedBox=-1;p->peerSelectedSlot=-1;return 0;}

/*
 * The bound block after POKETRADE_2D_GetScrollColumn closes only with its six locals
 * declared without initialisers and assigned afterwards; about a fifth of
 * the declaration orders then match (docs/notes/pkt_ov119_021DBE70.c.txt).
 */
void POKETRADE_PROC_StepBrowseGrid(TradeWork *p)
{
    int n;
    void *e;
    p->labelsReady = 1;
    if (TOUCHPANEL_GetCont()) {
        UI_SetInputMode(1);
        if (KEY_GetCont())
            return;
    }
    if (UI_GetInputMode() && poll_a()) {
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &n) == 0) {
            int v = n;
            p->cursorSlot = v;
            if (v < 2 && p->cursorColumn >= 3)
                p->cursorColumn = 2;
        } else if (POKETRADE_PROC_IsSlotVisible(p, p->cursorSlot) == 0) {
            int end;
            int a;
            int t;
            int cur;
            int b;
            int lim;
            t = POKETRADE_2D_GetScrollColumn(p);
            cur = p->cursorSlot;
            a = t + 5;
            b = t + 10;
            lim = p->slotCount;
            end = cur;
            if (b >= lim && cur < 0x14)
                end = cur + (lim + 1);
            if (a < end)
                p->scrollX = POKETRADE_PROC_GetSlotPosition(cur + 1) - 0x100;
            else
                p->scrollX = POKETRADE_PROC_GetSlotPosition(cur);
            p->cursorRow = -1;
            p->redrawNeeded = 1;
            POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 1);
            p->dragVelocity = 0;
            return;
        }
        POKETRADE_PROC_RequestBoxRedraw(p);
        p->dragVelocity = 0;
        return;
    }
    if (poll_a() || poll_b())
        p->dragVelocity = 0;
    if (poll_b()) {
        POKETRADE_PROC_ShowDragIcon(p);
        p->peerSelectedBox = -1;
        p->peerSelectedSlot = -1;
    }
    POKETRADE_PROC_UpdateDragState(p);
    POKETRADE_PROC_UpdateDragIcon(p);
    POKETRADE_PROC_PollGridKeys(p);
    POKETRADE_NEGO_PollMarkerTouch(p);
    if (poll_a() == 1) {
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &n) == 0) {
            int v = n;
            p->cursorSlot = v;
            if (v < 2) {
                if (p->cursorColumn >= 3)
                    p->cursorColumn = 0;
            } else if (p->cursorColumn >= 5)
                p->cursorColumn = 0;
        }
        e = POKETRADE_PROC_LoadSlotMonAlt((void *)p->boxManager, POKETRADE_PROC_GetBoxIndexForSlot(p->cursorSlot, p), POKETRADE_PROC_GetSlotIndexInBox(p->cursorSlot, p->cursorColumn), p);
        if (e && POKE_TOOL_GetBoxValue((void *)e, 0xA9, 0)) {
            if (POKETRADE_PROC_CanTradeMon(p, e)) {
                MSGDATA_ReadString((struct MsgBank *)p->messageBank, 0x8E, (void *)p->messageText);
                POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
                POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepWaitKeyAfterMessage);
                return;
            }
            p->peerSelectedBox = POKETRADE_PROC_GetBoxIndexForSlot(p->cursorSlot, p);
            p->peerSelectedSlot = POKETRADE_PROC_GetSlotIndexInBox(p->cursorSlot, p->cursorColumn);
            UI_SetInputMode(0);
            if (POKETRADE_PROC_IsHostSide(p) && POKETRADE_NEGO_FindOfferIndex(p, p->peerSelectedBox, p->peerSelectedSlot) != -1) {
                GFL_USE_PlaySeDefaultVolume(0x626);
                POKETRADE_PROC_SetStep(p, POKETRADE_NEGO_StepSendOfferRemoval);
                return;
            }
            POKETRADE_PROC_LoadSlotMonAlt((void *)p->boxManager, p->peerSelectedBox, p->peerSelectedSlot, p);
            POKETRADE_PROC_ShowDragIcon(p);
            POKETRADE_2D_PlaceBoxIconActors(p);
            POKETRADE_PROC_StepPeerSelectAction(p);
            return;
        }
    }
    switch (POKETRADE_PROC_PollGridTouchDrag(p, 0)) {
    case 3:
        return;
    case 2:
        break;
    case 1:
        UI_SetInputMode(1);
        p->dragHold = 1;
    default:
        if (!TOUCHPANEL_GetCont()) {
            if (p->dragging && p->dragMoved && p->dragActor) {
                p->dragging = 0;
                p->dragMoved = 0;
                if (POKETRADE_PROC_IsSelectedOfferSlot(p, p->highlightBox, p->highlightSlot)) {
                    p->highlightBox = -1;
                    p->highlightSlot = -1;
                    POKETRADE_PROC_ClearDragIcon(p);
                    POKETRADE_PROC_SetStep(p, POKETRADE_PROC_ShowCancelMessage);
                    return;
                }
                p->peerSelectedBox = p->highlightBox;
                p->peerSelectedSlot = p->highlightSlot;
                p->selectedSlot = p->highlightSlot;
                p->selectedBox = p->highlightBox;
                p->dragActor = 0;
                TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar), 8, 1);
                TOUCHBAR_SetButtonEnabled(p->touchbar, 8, 1);
                POKETRADE_2D_StartIconFlight(p);
                GFL_USE_PlaySeDefaultVolume(0x72A);
                POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepWaitIconFlight);
                return;
            }
            if (p->dragging && p->dragActor && p->dragHold) {
                p->peerSelectedBox = p->highlightBox;
                p->peerSelectedSlot = p->highlightSlot;
                POKETRADE_PROC_StepPeerSelectAction(p);
                return;
            }
            if (p->highlightSlot != -1 && p->highlightBox != -1) {
                POKETRADE_PROC_ShowDragIcon(p);
                POKETRADE_PROC_RequestBoxRedraw(p);
            } else {
                POKETRADE_PROC_ShowDragIcon(p);
            }
            p->dragging = 0;
            p->dragMoved = 0;
            CLACT_SetActorAutoAnim((struct ClactActor *)((struct ClactActor *)p->cursorActor), 0);
        }
        POKETRADE_PROC_DragScrollGrid(p);
        if (TOUCHPANEL_GetCont())
            p->dragging = 1;
        TOUCHBAR_Update((TouchBar *)((unsigned char *)p->touchbar));
        switch (TOUCHBAR_GetPressedButtonIdIfPressing((TouchBar *)((u8 *)p->touchbar))) {
        case 1:
        case 7:
        case 8:
            POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepTouchbarAction);
            break;
        }
        break;
    }
}

void POKETRADE_PROC_StepTouchbarAction(TradeWork *p){TOUCHBAR_Update((TouchBar *)((unsigned char *)(p->touchbar)));switch(TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)(*(u8 * *)&p->touchbar))) {case 1:POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepSlideInSubScreen);return;case 7:POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginOpenSubScreen);return;case 8:if(POKETRADE_PROC_IsHostSide(p)){if(POKETRADE_NEGO_HasOffer(p)){TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),7,0);TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),8,0);POKETRADE_PROC_ClearDragIcon(p);POKETRADE_PROC_SetStep(p,POKETRADE_NEGO_StepShowCancelMessage);return;}else{TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),7,1);TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),8,0);}}else{if(p->selectedSlot==-1){TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),7,1);TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)p->touchbar),8,0);}else{POKETRADE_PROC_SetStep(p,POKETRADE_PROC_HideTouchbarButtons);return;}}POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);return;}}

void POKETRADE_PROC_StepWaitKeyThenBrowse(TradeWork *p) {int hit=0;if(POKETRADE_SAVE_IsMessagePrintDone(p)) {if(poll_a()) {UI_SetInputMode(0);hit=1;}if(poll_b()){hit=1;UI_SetInputMode(1);}if(hit){POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBrowseGrid);p->cursorRow=-1;POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,1);}}}

void POKETRADE_PROC_InitMcssSystem(TradeWork *p)
{
    POKETRADE_2D_InitG3DSystem(p);
    p->mcssSystem = MCSS_Init(4, (u16)((p->heapId & 0x7FFF) | 0x8000));
    MCSS_SetTextureTransAdrs(p->mcssSystem, 3 << 16);
    MCSS_SetOrthoMode(p->mcssSystem);
}

void POKETRADE_PROC_ExitMcssSystem(TradeWork *p)
{
    POKETRADE_3D_DeleteMcssSlot(p, 0);
    POKETRADE_3D_DeleteMcssSlot(p, 1);
    MCSS_Exit(p->mcssSystem);
    p->mcssSystem = 0;
    G3D_CAMERA_Delete((*(void * *)&p->camera));
    G3D_SYSTEM_Exit();
}

void POKETRADE_PROC_InitDisplay(TradeWork *p)
{
    BG_SYS_Create(0x91);
    BMP_WIN_Init(p->heapId);
    POKETRADE_2D_InitDisplayAndClact(p);
    POKETRADE_2D_SetupMainBgs(p);
    POKETRADE_2D_SetupSubBgs(p);
}

void POKETRADE_PROC_ExitDisplay(void *unused)
{
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

void POKETRADE_PROC_LoadSceneResources(TradeWork *p) {POKETRADE_2D_RegisterIconCharResources(p);ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,p->heapId);POKETRADE_NEGO_ExitMarkers(p);if(p->tradeState<4)POKETRADE_2D_RegisterIconSpriteResources(p);POKETRADE_2D_CreateBoxIconActors(p);POKETRADE_2D_LoadMainGfxAndMessageWindow(p);POKETRADE_2D_LoadBackgroundGfx(p);POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_UpdateVisibleColumns(p->boxManager,p,0);}

void POKETRADE_PROC_VBlank(struct TcbTask *a, void *pArg)
{
    TradeWork *p = pArg;
    CLACT_VBlankSystem();
    if (p->redrawNeeded) {
        BG_SYS_ChangeScrollImmediate(7, 0, p->scrollSub);
        BG_SYS_ChangeScrollImmediate(5, 0, p->scrollSub);
        p->redrawNeeded = 0;
    }
}

void POKETRADE_PROC_SetupGameData(TradeWork *p,void *q,u16 r) {unsigned i;for(i=0;i<3;i++)p->tradeBuf[i]=GFL_HEAP_Alloc(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,PM_SRC_LINE(0xfde, 0xfcd));if(q){p->gameData=q;p->boxManager=(struct GameData *)GAME_DATA_GetBoxManager(q);p->trainerRecord=GAME_DATA_GetMyStatus(q);p->partyData=GAME_DATA_GetMyParty(q);if(p->playerStatus==0){if(POKETRADE_PROC_IsNetSession(p)){p->playerStatus=GAME_DATA_GetMyStatusPlayer(q,1-GFL_NET_SYSTEM_GetCurrentAid());return;}p->playerStatus=GAME_DATA_GetMyStatusPlayer(q,1);}}}

void POKETRADE_PROC_FreeMons(TradeWork *p, int unused)
{
    unsigned i;
    for (i = 0; i < 3; i++)
        GFL_HEAP_Free(p->tradeBuf[i]);
}

void POKETRADE_PROC_SetupBoxCounts(TradeWork *p)
{
    int v = BOX_SAVEDATA_GetUsableBoxCount((void *)(p->boxManager));
    p->slotCount = v * 6 + 2;
    p->partyBoxId = v;
    p->columnWrap = v * 0x14 + 0xC;
    p->gridOriginX = v * 0xA0 + 0x60;
}

/*
 * lever: output pointer declared before scalar locals; counter zero before base assignment.
 * arithmetic: signed n guard/callee argument; unsigned base/index preserve low-word MUL/ADD wrapping at 021DC6A6/021DC6A8/021DC6B2.
 */
void POKETRADE_PROC_BuildTradeRecords(TradeWork *p,int n)
{
    PokemontradeProcRecord *out=p->records;
    int i, v; void *mon;
    unsigned index,base;
    if(n==0) {
        MI_CpuFill8(out,0,sizeof(p->records));
        for(i=0;i<6;i++) {
            mon=POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager),p->partyBoxId,i,p);
            if(mon && POKE_TOOL_GetBoxValue((void *)mon,0xa9,0)) {
                v=POKE_TOOL_GetBoxValue((void *)mon,0xab,0);
                if(v) {
                    out[i].value=v;
                    out[i].a=POKE_TOOL_GetBoxValue((void *)mon,0x6f,0);
                    out[i].b=POKE_TOOL_GetBoxValue((void *)mon,0x6e,0);
                }
            }
        }
    }
    while(n<24) {
        i=0;
        base=(unsigned)n*30u+6u;
        for(;i<30;i++) {
            index=(unsigned)i+base;
            mon=POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager),n,i,p);
            if(mon && POKE_TOOL_GetBoxValue((void *)mon,0xa9,0)) {
                v=POKE_TOOL_GetBoxValue((void *)mon,0xab,0);
                if(v) {
                    out[index].value=v;
                    out[index].a=POKE_TOOL_GetBoxValue((void *)mon,0x6f,0);
                    out[index].b=POKE_TOOL_GetBoxValue((void *)mon,0x6e,0);
                }
            }
        }
        return;
    }
}

/*
 * volatile: 021DC726 reads hardware DISPCNT 0x04001000 before updating it.
 */
void POKETRADE_PROC_DeleteAllResources(TradeWork *p)
{
    int i;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    POKETRADE_2D_DeleteAllOfferIconActors(p);POKETRADE_3D_RemoveCurrentUnit(p);POKETRADE_NEGO_ReleaseIconResources(p);POKETRADE_NEGO_ResetMarkers(p);POKETRADE_NEGO_DeleteHeaderWindows(p);POKETRADE_2D_DeleteBoxWindows(p);
    POKETRADE_3D_DeleteMcssSlot(p,1);POKETRADE_2D_DeletePickedIconActor(p);POKETRADE_NEGO_UpdateOfferMarkers(p);POKETRADE_SAVE_DeleteOfferListWindows(p);POKETRADE_2D_DeleteAllBoxIcons(p);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,0);POKETRADE_SAVE_DeleteOfferCardWindow(p,1);
    if(p->touchbar) {TOUCHBAR_Delete(p->touchbar);p->touchbar=0;}
    POKETRADE_2D_DeleteOfferIcons(p);
    if(p->clactSystem) {CLACT_DeleteUnit((void *)p->clactSystem);p->clactSystem=0;}
    POKETRADE_SAVE_DeleteMessageResources(p);POKETRADE_NEGO_FreeOfferMons(p);
    POKETRADE_SAVE_DeletePartnerOfferCard(p,0);POKETRADE_SAVE_DeletePartnerOfferCard(p,1);POKETRADE_2D_FreeBackgroundPalette(p);POKETRADE_2D_FreeMainResources(p);POKETRADE_2D_ExitSubBgs(p);
    if(p->fade) {GFL_HEAP_Free(p->fade);p->fade=0;}
    for(i=0;i<4;i++) {
        if(p->slide[i]) {GFL_HEAP_Free(p->slide[i]);p->slide[i]=0;}
    }
}

void POKETRADE_PROC_ExitBgm(TradeWork *p)
{
    switch (p->sceneState) {
    case 0:
        break;
    case 2:
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
    case 1:
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(30);
    }
    p->sceneState = 0;
}

TradeWork *POKETRADE_PROC_AllocTradeWork(void *a,int t) {
 TradeWork *p;
 GFL_HEAP_RegisterBlockHeap(gTradeWorkHeapName,0xc000,0x91);
 GFL_HEAP_CreateChildHeap(1,31,t);
 p=PROCSYS_AllocProcWork(a,sizeof(TradeWork),0x91);
 MI_CpuFill8(p,0,sizeof(TradeWork));
 return p;
}

int POKETRADE_PROC_InitTradeWork(void *a,int b,char *q,TradeWork *p,int n)
{
    if(n<5) {GF_OVERLAY_Load((sptr)ov067_id);GF_OVERLAY_Load((sptr)ov114_id);}
    if(n==0 || n==4) GF_OVERLAY_Load((sptr)ov117_id);
    else GF_OVERLAY_Load((sptr)ov118_id);
    BG_SYS_SetLcdSwap(1);
    p->heapId=31;
    p->tradeState=n;
    p->request=(struct TradeRequest *)q;
    p->monABuf=GFL_HEAP_Alloc(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,PM_SRC_LINE(0x110b, 0x10fa));
    p->monBBuf=GFL_HEAP_Alloc(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,PM_SRC_LINE(0x110c, 0x10fb));
    p->subObjPaletteCopy=GFL_HEAP_Alloc(0x91,512,0,gGameDataAllocTag,PM_SRC_LINE(0x110d, 0x10fc));
    p->subBgPaletteCopy=GFL_HEAP_Alloc(0x91,512,0,gGameDataAllocTag,PM_SRC_LINE(0x110e, 0x10fd));
    p->nationalDexEnabled=ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(((struct TradeRequest *)q)->gameData));
    if(q) POKETRADE_PROC_SetupGameData(p,((struct TradeRequest *)q)->gameData,((struct TradeRequest *)q)->setupParam);
    POKETRADE_PROC_SetupBoxCounts(p);POKETRADE_PROC_InitMcssSystem(p);POKETRADE_PROC_InitDisplay(p);
    p->clactSystem=CLACT_CreateUnit(0x154,0,p->heapId);
    if(POKETRADE_PROC_IsNetSession(p)) {
        GFL_NET_COMMAND_AddCommandTable(0xc00,gNetCommandTable,24,p);
        GFL_NET_SetAutoExit(1);GFL_NET_SetLoginOption(1);
    }
    p->nodeA=GFL_USE_AddMainTask(POKETRADE_PROC_VBlank,p,0);
    p->dragActor=0;
    p->selectedSlot=-1;p->animIndex=-1;p->highlightSlot=-1;p->highlightBox=-1;p->peerSelectedBox=-1;p->peerSelectedSlot=-1;
    POKETRADE_3D_Init3DScene(p);
    if(((struct TradeRequest *)q)->state==1) {
        BG_SYS_SetMainVisiblePlanes(16);POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepSaveCancelNotice);((struct TradeRequest *)q)->state=0;return 1;
    }
    POKETRADE_SAVE_CreateMessageResources(p);POKETRADE_2D_CreateFontResource(p);
    if(p->tradeState<4) {POKETRADE_PROC_LoadSceneResources(p);POKETRADE_3D_CreateTouchbar(p);GFL_NET_RefreshWmIconAtTopRight(1,p->heapId);}
    POKETRADE_3D_AddUnitAndInit(p,0);BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepRestartNetSession);
    return 1;
}

/*
 * Send a two-descriptor request with the timer base 0xc6000.
 */
int POKETRADE_PROC_StartRequest2(void *a, int b, char *c)
{
    TradeWork *r = POKETRADE_PROC_AllocTradeWork(a, 0xc6000);

    return POKETRADE_PROC_InitTradeWork(a, b, c, r, 2);
}

/*
 * Send a one-descriptor request with the timer base 0xc6000.
 */
int POKETRADE_PROC_StartRequest0(void *a, int b, char *c)
{
    TradeWork *r = POKETRADE_PROC_AllocTradeWork(a, 0xc6000);

    return POKETRADE_PROC_InitTradeWork(a, b, c, r, 0);
}

int POKETRADE_PROC_StartRequest1(void *a,int b,char *c) {TradeWork *p=POKETRADE_PROC_AllocTradeWork(a,0xc6000);int i; for(i=0;i<2;i++) {p->peerMsgIndex[i]=0;p->ownMsgIndex[i]=1;} p->playerStatus=GAME_DATA_GetMyStatusPlayer((void *)((struct TradeRequest *)c)->gameData,1-GFL_NET_SYSTEM_GetCurrentAid());return POKETRADE_PROC_InitTradeWork(a,b,c,p,1);}

int POKETRADE_PROC_StartRequest3(void *a,int b,char *c) {const char *q=((struct TradeRequest *)c)->context;TradeWork *p=POKETRADE_PROC_AllocTradeWork(a,0xc6000);if(q) {if(((struct TradeContext *)q)->entryCount==2) {int i;for(i=0;i<2;i++) {const int *s=(const int *)(q+i*8);p->peerMsgIndex[i]=s[2];p->ownMsgIndex[i]=s[1];}} else {int j;for(j=0;j<2;j++){p->peerMsgIndex[j]=-1;p->ownMsgIndex[j]=-1;}}}return POKETRADE_PROC_InitTradeWork(a,b,c,p,3);}


void POKETRADE_PROC_SetupMcssPokemon(char *a, TradeWork *work)
{
    char *p = (char *)work;
    MI_CpuCopy8(((struct TradeRequest *)a)->monA,((TradeWork *)p)->monABuf,POKE_TOOL_GetPartyParamSize());
    MI_CpuCopy8(((struct TradeRequest *)a)->monB,((TradeWork *)p)->monBBuf,POKE_TOOL_GetPartyParamSize());
    POKETRADE_3D_AddPokemonMcssPlain(work,0,1,((struct TradeRequest *)a)->monA,1);
    POKETRADE_3D_AddPokemonMcssPlain(work,1,1,((struct TradeRequest *)a)->monB,1);
    MCSS_SetVanishFlag(*(void **)((char *)p + (POKETRADE_PROC_IsHostSide(work) == 0 ? (int)sizeof(void *) + (int)BW_OFFSETOF(TradeWork, mcssPokemon) : (int)BW_OFFSETOF(TradeWork, mcssPokemon))));
    ((TradeWork *)p)->trainerRecord=((struct TradeRequest *)a)->trainerValue;
    ((TradeWork *)p)->playerStatus=((struct TradeRequest *)a)->playerStatus;
    GFL_NET_RefreshWmIconAtTopRight(0,((TradeWork *)p)->heapId);
    FADE_Start(3,16,0,2);
}

int POKETRADE_PROC_StartRequest4(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0xc6000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)(a), b, c, p, 4);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, POKETRADE_IRCDEMO_StepStartCompare);
    return r;
}

int POKETRADE_PROC_StartRequest7(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)(a), b, c, p, 7);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, POKETRADE_DEMO_UP_StepStartDownScene);
    return r;
}

int POKETRADE_PROC_StartRequest8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)(a), b, c, p, 8);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, POKETRADE_DEMO_MIDDLE_StepStartCompare);
    return r;
}

int POKETRADE_PROC_StartRequest6(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)(a), b, c, p, 6);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, POKETRADE_DEMO_UP_StepStartCompare);
    return r;
}

int POKETRADE_PROC_Main(int a,int b,int c,TradeWork *p)
{
    int result=1;
    void (*callback)(TradeWork *)=p->stepFunc;
    int i;
    u8 rgb[3];
    if(BEACON_STATUS_IsLocked()) return 0;
    if(callback) {
        callback(p);
        p->waitCounter++;
        result=0;
        for(i=0;i<2;i++) POKETRADE_NEGO_DrawOfferStatusLabel(p,i,p->labelState[i],0);
    }
    if(p->pendingSideMon && p->sideMonSent==0) {
        POKETRADE_PROC_SetSideMon(p,1,p->monBuf[p->pendingSideMon-1]);p->pendingSideMon=0;
    }
    POKETRADE_PROC_IncrementTimer(p);POKETRADE_NEGO_TickMarkerTimers(p);CLACT_DrawSystem();
    if(p->taskMenu) APP_TASKMENU_UpdateMenu(p->taskMenu);
    if(p->taskMenuWindow) APP_TASKMENU_WIN_Update(p->taskMenuWindow);
    if(p->stateFlags.bits.replyPending) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc17,0,0)) p->stateFlags.bits.replyPending=0;
    }
    if(p->tcbl) {
        GF_FONT_GetTextColor(&rgb[2],&rgb[1],&rgb[0]);
        GF_FONT_SetTextColor(1,2,15);
        TCBL_Main(p->tcbl);
        GF_FONT_SetTextColor(rgb[2],rgb[1],rgb[0]);
        PRINTSYS_QUE_Main(p->printQueue);
    }
    POKETRADE_NEGO_TickOfferSlotTimers(p);G3D_SYSTEM_DrawStart();G3D_CAMERA_Reset((struct G3dCamera *)p->camera);G3D_SYSTEM_ApplyLookAt();
    MCSS_Main(p->mcssSystem);MCSS_Draw(p->mcssSystem);POKETRADE_3D_Update3DScene(p);G3D_SYSTEM_DrawEnd();
    if(POKETRADE_PROC_IsNetSession(p) && p->netSave==0 && GFL_NET_ERR_GetErrorLevel()) {
        if(p->wipeStarted) GFL_NET_ERR_HaltWithMessage(41);
        if(p->httpRap) {
            NHTTP_RAP_DeleteConnection(p->httpRap);NHTTP_RAP_Destroy(p->httpRap);p->httpRap=0;
            DWC_RAP_SetErrorCallback(0,0);DWC_RAPCOMMON_DestroySubHeap();
        }
        if(GFL_NET_IsNetTypeWifi()) DWC_RAPCOMMON_HandleNetError(1,1);
        else if(p->tradeState!=1) GFL_NET_ERR_RequestScreen();
        *(int *)((char *)p->request+8)=2;
        POKETRADE_PROC_ExitBgm(p);
        result=1;
        WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);
    }
    return result;
}

int POKETRADE_PROC_Exit(void *owner,int unused,int keep,TradeWork *p)
{
    int state=p->tradeState;
    if(WIPE_SYS_EndCheck()==0)return 0;
    GFL_HEAP_Free(p->subObjPaletteCopy);
    GFL_HEAP_Free(p->subBgPaletteCopy);
    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[0]);POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[1]);POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[2]);
    POKETRADE_2D_ClearSubScreen(p);POKETRADE_PROC_DeleteAllResources(p);BEACON_STATUS_DoNothing();
    if(POKETRADE_PROC_IsNetSession(p))GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    POKETRADE_3D_Delete3DScene(p);
    GFL_HEAP_Free(p->monABuf);GFL_HEAP_Free(p->monBBuf);
    TCB_DeleteTask(p->nodeA);
    POKETRADE_PROC_FreeMons(p,keep!=0);
    POKETRADE_PROC_ExitMcssSystem(p);POKETRADE_PROC_ExitDisplay(p);PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked(31);GFL_HEAP_DeleteChecked(145);
    if(state<5) {GF_OVERLAY_Unload((sptr)ov114_id);GF_OVERLAY_Unload((sptr)ov067_id);}
    GF_OVERLAY_Unload(state==0 || state==4 ?(sptr)ov117_id:(sptr)ov118_id);
    return 1;
}

void POKETRADE_PROC_ClampScrollColumn(TradeWork *p, int flag)
{
    int n;
    if (flag) {
        n = POKETRADE_2D_GetScrollColumn(p) + 2;
        if (n >= p->slotCount) n -= p->slotCount;
        if (p->scrollX == gScrollSnapPos[0]) n = 2;
        else if (p->scrollX == gScrollSnapPos[p->partyBoxId]) {
            n = 0;
            if (p->cursorColumn >= 3) p->cursorColumn = 2;
        }
        p->cursorSlot = n;
        p->cursorRow = -1;
    }
}

void POKETRADE_PROC_SetSyncRange(void *a, void *b, void *c)
{
    if (POKETRADE_PROC_IsNetSession(c))
        GFL_NET_HANDLE_SetTimingSyncRange(a, (uptr)b, 8);
}

void POKETRADE_PROC_UpdatePickedIcon(TradeWork *p)
{
    if (UI_GetInputMode()) {
        POKETRADE_2D_MovePickedIconActor(p, -1);
        return;
    }
    {
        int v = p->cursorIndex;
        if (v != -1)
            POKETRADE_2D_MovePickedIconActor(p, v);
    }
}

int POKETRADE_PROC_CanTradeMon(TradeWork *p, void *a)
{
    int v, lock, r;
    unsigned i;
    v = POKE_TOOL_GetBoxValue((void *)a,5,0);
    i = 0;
    if (p->tradeState == 3) {
        lock = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)a);
        for (; i < 15; i++) {
            r = POKE_TOOL_GetBoxValue((void *)a,gTradeableSpecies[i],0);
            if (r == 1) break;
        }
        POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)a,lock);
        if (r) return 1;
        if (POKE_REGULATION_IsInSpeciesTable(v)) return 1;
    }
    return 0;
}

int POKETRADE_PROC_TickWifiTimer(TradeWork *p)
{
    if (p->cancelTimer) {
        if (POKETRADE_PROC_IsWifiMode(p))
            p->cancelTimer = p->cancelTimer - 1;
        else
            p->cancelTimer = 0;
    }
    return p->cancelTimer == 0;
}
