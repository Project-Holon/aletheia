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
extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);
extern void POKETRADE_2D_DeletePickedIconActor(char *p);
extern void POKETRADE_NEGO_UpdateOfferMarkers(void *p);
extern void POKETRADE_SAVE_DeleteOfferListWindows(char *p);



struct Mon;

struct Proc;

struct McssSys;

struct Proc;



typedef signed short s16;

typedef struct Pt { u16 x; u16 y; } Pt;

typedef struct {int a,b,c;} IntTriple;

typedef struct { int a,b; } Pair;


typedef struct { u8 a,b,c,d; } Rect;


typedef struct Record {u16 value;u8 a,b;} Record;




extern void TOUCHBAR_ResetAndEnableButton(u32 *p, u32 buttonId);

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);

extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);

extern struct Sub02008F80Obj *MAIL_GetBox(void *sys);

extern int MAIL_FindEmptySlot(void *obj, int v);

extern void GFL_NET_SetAutoExit(u8 autoExit);

extern void GFL_NET_SetLoginOption(u8 loginOption);

extern void GFL_NET_STATE_WifiDisconnect(u32 a);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern int GFL_NET_GetRunState(void);

extern void GFL_USE_FadeOutBgm(u32 a);

extern void GFL_USE_SetBgmPaused(u32 value);

extern int GFL_USE_PushBgm(void);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 trackMask);

extern void GFL_USE_FadeInBgmFull(u32 a);


extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void POKETRADE_2D_DeleteFloatingIconActor(void *p);

extern void CLACT_SetActorDrawPriority(struct Actor *actor, u32 priority);

extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int value);

extern void MI_CpuFill8(void *,int,int);

extern void POKETRADE_2D_SetIconObjMode(int unused, int actor, int enable);

extern void POKETRADE_2D_CreateFloatingIconActor(int p, int i, int j, int x, int y, void *q);
struct GameData;
struct BoxPokemon;

extern struct BoxPokemon *BOX_SAVEDATA_GetPokemon(struct GameData *gameData, u32 box, u32 slot);
struct PokemonParam;

extern struct PokemonParam *POKE_TOOL_CreateFromBoxParam(struct PokemonParam *src, u16 heapId);
struct Party;

extern u32 POKEPARTY_GetCount(struct Party *party);

extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);

extern struct PokemonParam *POKE_TOOL_Create(u16 species, u16 level, unsigned long long id, u16 heap);

extern void MI_CpuCopy8(void *dst, const void *src, int n);

extern struct BoxPokemon *POKE_TOOL_GetBoxParam(struct PokemonParam *pp);
struct GFLNetHandle;

extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);

extern u32 GFL_NET_GetHandleNetID(struct GFLNetHandle *handle);

extern unsigned int POKE_TOOL_GetPartyValue(struct PokemonParam *pp, unsigned int paramId, unsigned int arg);

extern void POKETRADE_2D_CreateOfferIconActor(char *p, int i, int j, void *mon, int selected, u32 visible);

extern void POKETRADE_NEGO_ShowOfferSlotMon(void *,int,void *);
struct SaveControl;

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
struct WifiHistory;

extern struct WifiHistory *WIFI_HISTORY_GetBlock(struct SaveControl *saveControl);
struct MyStatus;

extern u8 MYSTATUS_GetNation(struct MyStatus *mystatus);

extern u8 MYSTATUS_GetArea(struct MyStatus *mystatus);

extern u8 MYSTATUS_GetLanguage(struct MyStatus *mystatus);

extern void MYSTATUS_SetNationAndArea(struct MyStatus *mystatus, u8 nation, u8 area);

extern u32 NATION_AREA_SanitizeNation(u32 a, u32 b, u32 c);

extern u32 NATION_AREA_SanitizeArea(u32 a, u32 b, u32 c);
struct HistoryEntry;
struct HistoryOwner;

extern u32 COMM_HISTORY_InsertIfNationSet(struct HistoryOwner *owner, struct HistoryEntry *entry);
struct TradeWork;

extern void POKETRADE_2D_DeleteOfferIconActor(struct TradeWork *p, int a, int b);

extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);

extern void POKETRADE_NEGO_FlashMarker(void *, int, int);

extern u32 WIPE_SYS_EndCheck(void);

extern void WIPE_SYS_Start(void *divisionMode, unsigned int mainPattern, unsigned int subPattern, unsigned short color, unsigned int frames, unsigned int wait, unsigned int heapId);

extern void POKETRADE_3D_DeleteMcssSlot(void *p, int idx);

extern void POKETRADE_3D_AddPokemonMcssFlipped(void *p, int a, int b, void *c, int d, int e);

extern void POKETRADE_SAVE_DrawOfferCardWindow(char *p, int i, void *mon);

extern void POKETRADE_SAVE_DeleteOfferCardWindow(char *p, int i);

extern u32 POKEPARTY_GetAliveNonEggCount(struct Party *party);

extern u32 POKE_TOOL_GetBoxValue(struct BoxPokemon *box, unsigned int paramId, unsigned int arg);
struct SaveData;

extern int POKE_TOOL_HasNoHmMove(struct SaveData *save, int unused);

extern u32 FILE_UTIL_IsMailItem(u16 v);

extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);

extern int GFL_NET_SendToHandle(void *a, u16 b, u16 c, void *d);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, unsigned int timingLow, unsigned int timingHigh);
struct Strbuf;
struct MsgBank;

extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, struct Strbuf *dest);

extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);

extern void POKETRADE_SAVE_ShowTimeIcon(char *p);

extern u8 UI_GetInputMode(void);

extern void POKETRADE_2D_PlaceTouchbarActors(char *p, int b, int c);

extern void POKETRADE_SAVE_ShowSummaryMon(char *p, void *mon, int side, int flag);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void POKETRADE_SAVE_CloseSummaryPage(void *,int);

extern void POKETRADE_2D_LoadBackgroundGfx(char *p);

extern void POKETRADE_3D_AddUnitAndInit(void *,int);

extern void BG_SYS_MarkTileDirty(u32 bit);

extern int TOUCHPANEL_HitTrg(const void *);

extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);

extern u32 KEY_GetTrg(void);

extern void UI_SetInputMode(u8 v);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern void TOUCHBAR_Update(unsigned char *p);

extern void POKETRADE_SAVE_OpenSummaryScreen(char *p, void *a);
struct TaskMenuWork;

extern u32 APP_TASKMENU_IsFinish(struct TaskMenuWork *menu);

extern u8 APP_TASKMENU_GetCursorPos(struct TaskMenuWork *menu);

extern void POKETRADE_SAVE_CloseTaskMenu(char *p);

extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);

extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);

extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);

extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);

extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
struct GFLNetHandle;

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, u32 timingLow, u32 timingHigh);

extern void G2x_SetBlendBrightness_(u32 addr, int plane, int brightness);

extern unsigned int TOUCHPANEL_GetPointTrg(unsigned int *outA, unsigned int *outB);

extern int POKETRADE_2D_HitTestBoxIcons(char *p, int x, int y, int *outA, int *outB, int *outSlot, int *outColumn, int *outRow);

extern void POKETRADE_NEGO_StepSendOfferRemoval(void *p);

extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag);

extern int TOUCHPANEL_GetTrg(void);

extern void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);

extern void POKETRADE_SAVE_CloseSummaryWindow(char *p, int a);

extern void POKETRADE_SAVE_DrawSummaryPage(char *p, int mode, void *mon);

extern u32 GFL_HEAP_Free(void *p);

extern void POKETRADE_NEGO_StepShowCancelMessage(char *p);
struct TaskMenuWork;

extern unsigned APP_TASKMENU_IsDecide(struct TaskMenuWork *menu);

extern int TOUCHPANEL_GetCont(void);

extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);

extern void POKETRADE_2D_DeleteMarkingIcon(void *);

extern void POKETRADE_2D_ClearSummaryBackground(char *p);

extern void APP_TASKMENU_SetCursorActive(struct TaskMenuWork *menu, u32 isActive);

extern void POKETRADE_IRCDEMO_StepStartCompare(u8 *p);

extern void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *p);

extern void BG_SYS_SetSubVisiblePlanes(u32 planes);

extern void POKETRADE_NEGO_ExitMarkers(void *);

extern void DWC_RAP_SetVchatTalkLock(int);

extern void POKETRADE_NEGO_InitOfferMarkers(void *);

extern void APP_TASKMENU_CloseMenu(struct TaskMenuWork *menu);

extern void POKETRADE_2D_CreateBoxWindows(char *p);

extern void POKETRADE_2D_SetupSubBlend(void *);

extern void POKETRADE_3D_UploadCubeTextures(void *);

extern u32 GFL_NET_SendData(struct GFLNetHandle *handle, u32 sendId, u32 command, u32 size, void *data, u32 sendFlags, u32 skipIfQueued, u32 queueMode);

extern int POKETRADE_2D_BuildMarkingTablesFrom(char *,int);

extern void POKETRADE_2D_LoadBoxIconGfx(char *,int);

extern void GFL_NET_RefreshWmIconAtTopRight(u32 a, u32 b);

extern void WIPE_ResetBrightness(u32 which);

extern void POKETRADE_SAVE_OpenTaskMenuAt(char *p, int *ids, int count, int x, int y);

extern int POKETRADE_2D_GetScrollColumn(char *);

extern int POKETRADE_2D_IsBoxIconMatch(int,int);

extern void POKETRADE_2D_ClearSubScreen(char *p);

extern void POKETRADE_2D_FadePaletteAll(void *,int);

extern void POKETRADE_2D_DeleteCursorActor(void *);

extern int POKETRADE_2D_ClearCursorIfDisabled(void *);

extern void POKETRADE_2D_CreateCursorActor(char *,int,int);

extern void POKETRADE_SAVE_OpenMessageWindow(char *p, int flag, int x, int y, int w, int h);

extern void POKETRADE_2D_LoadSubScreenGfx(char *p);

extern unsigned int KEY_GetRepeat(void);

extern int POKETRADE_2D_GetVisibleColumnRange(char *, int *);

extern void POKETRADE_2D_DrawBoxGridScreen(char *);

extern void POKETRADE_2D_DrawBoxNames(char *);

extern int GFL_USE_IsAnySeBusy(void);

extern u32 GFL_NET_IsNetTypeWifi(void);

extern int POKETRADE_2D_UpdateIconFlight(char *p);

extern unsigned int KEY_GetCont(void);

extern void POKETRADE_NEGO_PollMarkerTouch(void *p);

extern void POKETRADE_2D_PlaceBoxIconActors(char *p);

extern void POKETRADE_2D_StartIconFlight(char *p);

extern void CLACT_SetActorAutoAnim(struct Actor *actor, u32 enable);

extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *p);

extern void POKETRADE_2D_InitG3DSystem(char *p);

extern void *MCSS_Init(int, unsigned short);

extern void MCSS_SetTextureTransAdrs(struct McssSys *sys, u32 adrs);

extern void MCSS_SetOrthoMode(struct McssSys *sys);

extern void MCSS_Exit(struct McssSys *sys);

extern u32 G3D_CAMERA_Delete(void *ptr);

extern void G3D_SYSTEM_Exit(void);

extern void BG_SYS_Create(u16 heapId);

extern void BMP_WIN_Init(unsigned short);

extern void POKETRADE_2D_InitDisplayAndClact(char *p);

extern void POKETRADE_2D_SetupMainBgs(void *);

extern void POKETRADE_2D_SetupSubBgs(char *p);

extern void CLACT_ExitSystem(void);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void POKETRADE_2D_RegisterIconCharResources(char *p);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(unsigned int archiveID, unsigned int memberIdx, unsigned int kind, unsigned int dest, unsigned int size, unsigned short flags);

extern void POKETRADE_2D_RegisterIconSpriteResources(char *p);

extern void POKETRADE_2D_CreateBoxIconActors(char *p);

extern void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p);

extern void CLACT_VBlankSystem(void);

extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);

extern void *GFL_HEAP_Alloc(unsigned,unsigned,int,const char *,u16);

extern unsigned int GAME_DATA_GetBoxManager(struct GameData *gd);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);

extern void *GAME_DATA_GetMyParty(struct GameData *gd);

extern struct MyStatus *GAME_DATA_GetMyStatusPlayer(struct GameData *gd, unsigned int playerId);

extern u8 BOX_SAVEDATA_GetUsableBoxCount(struct GameData *gameData);

extern void POKETRADE_2D_DeleteAllOfferIconActors(void *);

extern void POKETRADE_3D_RemoveCurrentUnit(void *);

extern void POKETRADE_NEGO_ResetMarkers(void *);

extern void POKETRADE_2D_DeleteBoxWindows(char *p);

extern void TOUCHBAR_Delete(u8 *p);

extern void POKETRADE_2D_DeleteOfferIcons(char *);

extern unsigned int CLACT_DeleteUnit(struct Bank *bank);

extern void POKETRADE_SAVE_DeleteMessageResources(char *);

extern void POKETRADE_SAVE_DeletePartnerOfferCard(char *p, int i);

extern void POKETRADE_2D_FreeBackgroundPalette(char *);

extern void POKETRADE_2D_FreeMainResources(char *);

extern void POKETRADE_2D_ExitSubBgs(char *p);

extern int GFL_USE_PopBgm(void);

extern void GFL_HEAP_RegisterBlockHeap(void *a, u32 b, u32 c);

extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);

extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);

extern int GF_OVERLAY_Load(int);

extern void BG_SYS_SetLcdSwap(unsigned int swap);

extern void *ZUKAN_SAVE_GetFromGameData(void *);
struct ZukanSave;

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *pZukan);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void GFL_NET_COMMAND_AddCommandTable(unsigned,unsigned,unsigned,unsigned);
struct Tcb;

extern struct Tcb *GFL_USE_AddMainTask(void (*)(void *,void *), void *work, unsigned int priority);

extern void POKETRADE_3D_Init3DScene(char *);

extern void POKETRADE_SAVE_StepSaveCancelNotice(char *p);

extern void POKETRADE_SAVE_CreateMessageResources(char *p);

extern void POKETRADE_2D_CreateFontResource(char *p);

extern void POKETRADE_3D_CreateTouchbar(char *p);

extern void POKETRADE_3D_AddPokemonMcssPlain(void *,int,int,void *,int);
struct McssWork;

extern void MCSS_SetVanishFlag(struct McssWork *work);

extern void FADE_Start(u32 a, int b, int c, int d);

extern void POKETRADE_DEMO_UP_StepStartDownScene(unsigned char *);

extern void POKETRADE_DEMO_UP_StepStartCompare(unsigned char *);

extern int BEACON_STATUS_IsLocked(void);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern void POKETRADE_NEGO_TickMarkerTimers(void *);

extern void CLACT_DrawSystem(void),APP_TASKMENU_UpdateMenu(void *),APP_TASKMENU_WIN_Update(u8 *);

extern void GF_FONT_GetTextColor(u8 *,u8 *,u8 *);

extern void GF_FONT_SetTextColor(u32,u32,u32);
struct TcblSystem;

extern void TCBL_Main(struct TcblSystem *tcbl);
struct PrintQueue;

extern u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);

extern void POKETRADE_NEGO_TickOfferSlotTimers(void *);

extern void G3D_SYSTEM_DrawStart(void);
struct G3dCamera;

extern void G3D_CAMERA_Reset(struct G3dCamera *camera);

extern void G3D_SYSTEM_ApplyLookAt(void);

extern void MCSS_Main(struct McssSys *sys);

extern void MCSS_Draw(struct McssSys *sys);

extern void POKETRADE_3D_Update3DScene(void *);

extern void G3D_SYSTEM_DrawEnd(void);

extern void GFL_NET_ERR_HaltWithMessage(unsigned);
struct _NHTTPRapSession;

extern void NHTTP_RAP_DeleteConnection(struct _NHTTPRapSession *session_p);

extern void NHTTP_RAP_Destroy(struct _NHTTPRapSession *session_p);

extern void DWC_RAP_SetErrorCallback(int,int);

extern void DWC_RAPCOMMON_DestroySubHeap(void);

extern int DWC_RAPCOMMON_HandleNetError(int hasSession, int keepError);

extern void GFL_NET_ERR_RequestScreen(void);

extern void WIPE_SetBrightnessFadeOut(unsigned,unsigned);

extern void BEACON_STATUS_DoNothing(void);

extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);

extern void POKETRADE_3D_Delete3DScene(char *);
struct TcbTask;

extern void TCB_DeleteTask(struct TcbTask *task);

extern void PROCSYS_FreeProcWork(struct Proc *);

extern void GFL_HEAP_DeleteChecked(unsigned int);

extern void GF_OVERLAY_Unload(int);

extern void POKETRADE_2D_MovePickedIconActor(void *p, int i);

extern u32 POKE_TOOL_DecodeBoxParam(struct BoxPokemon *box);

extern u32 POKE_TOOL_EncodeBoxParam(struct BoxPokemon *box, unsigned int didDecode);

extern int POKE_REGULATION_IsInSpeciesTable(unsigned short);

int POKETRADE_PROC_ResetTouchbarBackButton(char *p);

int POKETRADE_PROC_IsMailBoxFull(char *p);

void POKETRADE_PROC_ClearNetAutoExit(char *p);

int POKETRADE_PROC_IsMonValid(const u8 *p);

u8 POKETRADE_PROC_GetStoredBoxIndex(u8 *p);

int POKETRADE_PROC_IsNetSession(void *p);

void POKETRADE_PROC_IncrementTimer(void *p);

int POKETRADE_PROC_IsHostSide(void *p);

int POKETRADE_PROC_IsWifiMode(char *p);

int POKETRADE_PROC_GetBoxIndexForSlot(int a, char *p);

int POKETRADE_PROC_GetSlotIndexInBox(int a, int b);

void POKETRADE_PROC_RequestBoxRedraw(char *p);

void POKETRADE_PROC_UpdateDragState(void *p);

void POKETRADE_PROC_UpdateDragIcon(void *p);

void POKETRADE_PROC_ClearDragIcon(void *p);

void POKETRADE_PROC_ShowDragIcon(void *p);

void POKETRADE_PROC_BeginDrag(void *p, int x, int y, int z, int mon);

void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p);

void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);

char *POKETRADE_PROC_GetSlotMonPtr(int a, int b, char *p);

void POKETRADE_PROC_StepNone(void *unused);

void POKETRADE_PROC_SetStep(void *p, int v);

u32 POKETRADE_PROC_GetNetIdOffset(u32 a, u32 b);

void POKETRADE_PROC_RecvPlayerMonA(u32 a, u32 b, u8 *src, u8 *base, void *e);

int POKETRADE_PROC_GetSideValue(void *p,int idx);

void POKETRADE_PROC_SetSideValue(void *p,int idx,int x);

void *POKETRADE_PROC_GetSideMon(void *p, int idx);

void POKETRADE_PROC_RecvMonCopy(int idx,int a,int b,void *p,int id);

void POKETRADE_PROC_RecvMonChunkCommon(int a,int b,int c,u8 *p,int e,int f);

void POKETRADE_PROC_RecvMonChunk0(int a, int b, int c, u8 *d, int e);

void POKETRADE_PROC_RecvMonChunk1(int a, int b, int c, u8 *d, int e);

void POKETRADE_PROC_RecvMonChunk2(int a, int b, int c, u8 *d, int e);

void POKETRADE_PROC_RecvOfferMonCommon(u32 a, u32 b, u32 c, u8 *base, void *e);

void POKETRADE_PROC_RecvOfferMon0(u32 a, int b, int c, u8 *d, void *e);

void POKETRADE_PROC_RecvOfferMon1(u32 a, int b, int c, u8 *d, void *e);

void POKETRADE_PROC_RecvOfferMon2(u32 a, int b, int c, u8 *d, void *e);

void POKETRADE_PROC_RecvPlayerFlag(u32 a, u32 b, u8 *src, u8 *base, void *e);

void POKETRADE_PROC_RecvPeerSelection(u32 a, u32 b, u32 c, u8 *base, void *e);

void POKETRADE_PROC_RecvPeerValue(u32 a, u32 b, u32 c, u32 d, void *e);

void POKETRADE_PROC_RecvPeerFlags(int a,int b,const u8 *c,u8 *p,int e);

void POKETRADE_PROC_RecvPeerState(u32 a, u32 b, u8 *src, u8 *base, void *e);

void POKETRADE_PROC_RecvTradeSummary(void *p, int size, void *data, char *work, int handle);

void POKETRADE_PROC_RecvStateByte(u32 a, u32 b, u8 *src, u8 *base, void *e);

void POKETRADE_PROC_RecvPeerByte(u32 a, u32 b, u8 *src, u8 *base, void *e);

void POKETRADE_PROC_RecvPeerWord(u32 a, u32 b, int *src, void *base, void *e);

void POKETRADE_PROC_RecvPeerWordB(u32 a, u32 b, u32 c, void *base, void *e);

void POKETRADE_PROC_RecvPeerHalf(u32 a, u32 b, short *src, u8 *base, void *e);

void POKETRADE_PROC_RecvPeerByteB(u32 a, u32 b, u8 *src, void *base, void *e);

void POKETRADE_PROC_RecvIgnoredA(u32 a, u32 b, u32 c, u32 d, u32 e);

void POKETRADE_PROC_RecvPeerByteC(u32 a, u32 b, u8 *src, u8 *base, void *e);

void POKETRADE_PROC_RecvIgnoredB(u32 a, u32 b, u32 c, u32 d, u32 e);

void POKETRADE_PROC_RecvIgnoredC(u32 a, u32 b, u32 c, u32 d, u32 e);

void POKETRADE_PROC_StepWaitWipeEnd(void *p);

void POKETRADE_PROC_StepBeginWipeOut(void *p);

void POKETRADE_PROC_SetSideMon(void *p, int a, void *b);

void POKETRADE_PROC_ClearSideMon(void *p, int a);

int POKETRADE_PROC_IsSelfMonReady(char *p);

int POKETRADE_PROC_IsSelectedOfferSlot(char *p,int a,int b);

u32 POKETRADE_PROC_IsMonBadEggOrInvalid(void *mon);

int POKETRADE_PROC_IsCurrentSideMonInvalid(void *p);

u32 POKETRADE_PROC_IsOtherSideMonInvalid(void *p);

int POKETRADE_PROC_IsMonTradeable(unsigned char *p);

void POKETRADE_PROC_BuildPartyPacket(char *p);

void POKETRADE_PROC_ShowIntroMessage(char *p);

void POKETRADE_PROC_PlaceCursorIcon(char *p, int cursorIndex, int showSummary);

void POKETRADE_PROC_StepReturnFromSummary(char *p);

void POKETRADE_PROC_StepMain(char *p);

void POKETRADE_PROC_StepAfterSummaryWipe(char *p);

void POKETRADE_PROC_StepMainMenuChoice(char *p);

void POKETRADE_PROC_StepShowTradeSummary(char *p);

void POKETRADE_PROC_StepOpenMainMenu(char *p);

void POKETRADE_PROC_StepWaitSync20(void *p);

void POKETRADE_PROC_StepStartSync20(char *p);

void POKETRADE_PROC_StepIntro(char *p);

void POKETRADE_PROC_StepSendIntroReady(u8 *p);

void POKETRADE_PROC_StepMenuChoice(char *p);

void POKETRADE_PROC_StepOpenMenu(void *p);

void POKETRADE_PROC_StepSendPartyBoxSelected(char *p);

void POKETRADE_PROC_HideTouchbarButtons(char *p);

void POKETRADE_PROC_SetDragTarget(char *p,int a,int b);

int POKETRADE_PROC_PollGridTouch(char *p,int *a,int *b,int *c,int *d);

int POKETRADE_PROC_PollGridTouchDrag(char *p,int save);

void POKETRADE_PROC_StepWaitKeyAfterMessage(char *p);

void POKETRADE_PROC_ShowCancelMessage(char *p);

void POKETRADE_PROC_ShowSelectMessage(char *p);

void POKETRADE_PROC_ShowPeerSummary(char *p);

void POKETRADE_PROC_StepAddSelectedOffer(char *p);

void POKETRADE_PROC_StepSendAddOffer(char *p);

void POKETRADE_PROC_StepApplyAddOffer(char *p);

void POKETRADE_PROC_StepSendApplyAddOffer(char *p);

void POKETRADE_PROC_StepWaitTouchReleasePeer(void *p);

void POKETRADE_PROC_StepPeerSummaryMenu(char *p);

void POKETRADE_PROC_StepOpenPeerSummary(char *p);

void POKETRADE_PROC_StepSendCursorChoice(char *p);

void POKETRADE_PROC_StepWaitCursorSync(void *p);

void POKETRADE_PROC_StepResolveCursorResult(char *p);

void POKETRADE_PROC_StepRebuildTradeScene(char *p);

void POKETRADE_PROC_StepRestoreBrowseScene(char *p);

void POKETRADE_PROC_StepWaitThenRestoreScene(void *p);

void POKETRADE_PROC_StepBeginWipeToRestore(char *p);

void POKETRADE_PROC_StepWaitSyncThenWipe(void *p);

void POKETRADE_PROC_StepSendTradeData(char *p);

void POKETRADE_PROC_StepBuildTradeRecord(char *p);

void POKETRADE_PROC_StepBuildMarkingTable(char *p);

void POKETRADE_PROC_StepSendBoxInfo(char *p);

void POKETRADE_PROC_StepLoadBoxIconGfx(char *p);

void POKETRADE_PROC_StepWaitNetSync22(char *p);

void POKETRADE_PROC_StepAfterWipeLoadBox(void *p);

void POKETRADE_PROC_StepRestartNetSession(char *p);

void POKETRADE_PROC_StepResetForNewRound(char *p);

void POKETRADE_PROC_StepWaitMessageThenResolve(void *p);

void POKETRADE_PROC_StepSendNewRound(void *p);

void POKETRADE_PROC_StepClearOffersNewRound(char *p);

void POKETRADE_PROC_StepWaitMessageThenClear(void *p);

void POKETRADE_PROC_StepShowWaitMessageA(char *p);

void POKETRADE_PROC_StepSendContinue(void *p);

void POKETRADE_PROC_StepSendStartRound(char *p);

void POKETRADE_PROC_StepSummaryMenuChoice(char *p);

int POKETRADE_PROC_SendSideMon(char *p);

void POKETRADE_PROC_StepOpenSummaryMenu(char *p);

void POKETRADE_PROC_StepShowSummaryMessage(char *p);

void POKETRADE_PROC_StepSlideInSubScreen(void *p);

int POKETRADE_PROC_FindMatchingBoxIcon(char *p,int kind);

void POKETRADE_PROC_StepCloseSubScreenDone(void *p);

void POKETRADE_PROC_StepExitSubScreen(void *p);

void POKETRADE_PROC_StepWaitCursorFade(void *p);

void POKETRADE_PROC_StepSubScreenList(char *p);

void POKETRADE_PROC_StepOpenSubScreen(char *p);

void POKETRADE_PROC_StepBeginOpenSubScreen(char *p);

int POKETRADE_PROC_GetSlotPosition(int a);

int POKETRADE_PROC_IsSlotVisible(char *p, int index);

void POKETRADE_PROC_PollGridKeys(char *p);

void POKETRADE_PROC_RedrawAndSyncGrid(char *p,int a,int b);

void POKETRADE_PROC_DragScrollGrid(char *p);

void POKETRADE_PROC_StepWaitBrowseRelease(char *p);

void POKETRADE_PROC_StepClearPeerSelection(char *p);

void POKETRADE_PROC_StepBeginBrowse(void *p);

void POKETRADE_PROC_StepResetGrid(char *p);

void POKETRADE_PROC_StepEnterBrowsing(char *p);

void POKETRADE_PROC_UpdateTouchbarButtons(char *p);

void POKETRADE_PROC_StepRebuildBrowseScene(char *p);

void POKETRADE_PROC_StepConfirmSendOffer(char *p);

void POKETRADE_PROC_StepSendOfferConfirm(char *p);

void POKETRADE_PROC_StepWaitIconFlight(char *p);

int POKETRADE_PROC_IsTradeTargetValid(char *p,int a,int b);

int POKETRADE_PROC_StepPeerSelectAction(char *p);

void POKETRADE_PROC_StepBrowseGrid(char *p);

void POKETRADE_PROC_StepTouchbarAction(char *p);

void POKETRADE_PROC_StepWaitKeyThenBrowse(char *p);

void POKETRADE_PROC_InitMcssSystem(char *p);

void POKETRADE_PROC_ExitMcssSystem(char *p);

void POKETRADE_PROC_InitDisplay(char *p);

void POKETRADE_PROC_ExitDisplay(void *unused);

void POKETRADE_PROC_LoadSceneResources(char *p);

void POKETRADE_PROC_VBlank(int a, char *p);

void POKETRADE_PROC_SetupGameData(char *p,void *q,u16 r);

void POKETRADE_PROC_FreeMons(char *p, int unused);

void POKETRADE_PROC_SetupBoxCounts(char *p);

void POKETRADE_PROC_BuildTradeRecords(char *p,int n);

void POKETRADE_PROC_DeleteAllResources(char *p);

void POKETRADE_PROC_ExitBgm(char *p);

void *POKETRADE_PROC_AllocTradeWork(void *a,int t);

int POKETRADE_PROC_InitTradeWork(void *a,int b,char *q,char *p,int n);

void POKETRADE_PROC_StartRequest2(void *a, int b, int c);

void POKETRADE_PROC_StartRequest0(void *a, int b, int c);

void POKETRADE_PROC_StartRequest1(void *a,int b,char *c);

void POKETRADE_PROC_StartRequest3(void *a,int b,char *c);

void POKETRADE_PROC_SetupMcssPokemon(char *a, char *p);

int POKETRADE_PROC_StartRequest4(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest7(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest8(void *a, int b, char *c);

int POKETRADE_PROC_StartRequest6(void *a, int b, char *c);

int POKETRADE_PROC_Main(int a,int b,int c,char *p);

int POKETRADE_PROC_Exit(void *owner,int unused,int keep,char *p);

void POKETRADE_PROC_ClampScrollColumn(char *p, int flag);

void POKETRADE_PROC_SetSyncRange(void *a, void *b, void *c);

void POKETRADE_PROC_UpdatePickedIcon(char *p);

int POKETRADE_PROC_CanTradeMon(char *p, int a);

int POKETRADE_PROC_TickWifiTimer(char *p);

void POKETRADE_NEGO_FreeOfferMons(char *p);

void POKETRADE_NEGO_ClearOfferSlots(char *p);

int POKETRADE_NEGO_CheckCancelTouch(char *p);

void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);

int POKETRADE_NEGO_CanConfirmOffers(char *p);

int POKETRADE_NEGO_HasOffer(char *p);

int POKETRADE_NEGO_FindOfferIndex(char *p, int a, int b);

void POKETRADE_NEGO_StoreRemoteOffer(char *p,int i,void *src);

int POKETRADE_NEGO_FindFreeOfferIndex(const char *p, int n, int a, int b);

void POKETRADE_NEGO_RemoveOffer(TradeWork *p, int i, int j);

void POKETRADE_NEGO_RegisterIconResources(char *p,int n);

void POKETRADE_NEGO_ReleaseIconResources(char *p);

int POKETRADE_NEGO_AddSelectedAsOffer(char *p,int a,int b);

void POKETRADE_NEGO_DrawPlayerNames(char *p);

void POKETRADE_NEGO_DrawOfferStatusLabel(u8 *p,int i,int msg,int force);

void POKETRADE_NEGO_DeleteHeaderWindows(unsigned char *p);

extern const Pt gCursorIconPos0;

extern const Pt gCursorIconPos1;

extern const char gMainMenuHitArea[];

extern const IntTriple gMainMenuLayout;

extern const Pair gOpenMenuPos;

extern const Pair gPeerSummaryPos;

extern const Pair gSummaryMenuPos;

extern Rect gSubScreenHitAreas[];

extern const int gScrollSnapPos[];

extern char gGameDataAllocTag[];

extern char gTradeWorkHeapName[];

extern char ov067_id[],ov114_id[],ov117_id[],ov118_id[];

extern char gNetCommandTable[];

extern char ov114_id[],ov067_id[],ov117_id[],ov118_id[];

extern const int gTradeableSpecies[];

/*
 * 2026-10-02: the first call's target 021B65B4 (thumb, ov067 window) was an
 *  unlabelled tail-call stub; seeded in layout/function_starts.txt and matched
 *  as src/matched/ov/ov067_func_021B65B4.c, so every call now resolves.
 */
int POKETRADE_PROC_ResetTouchbarBackButton(char *p)
{
    TOUCHBAR_ResetAndEnableButton(*(u32 * *)&((TradeWork *)p)->touchbar, 1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(u32 * *)&((TradeWork *)p)->touchbar), 1, 1);
    return TOUCHBAR_SetButtonEnabled((unsigned char *)(*(u32 * *)&((TradeWork *)p)->touchbar), 1, 1);
}

int POKETRADE_PROC_IsMailBoxFull(char *p)
{
    void *o = MAIL_GetBox(((TradeWork *)p)->gameData);
    int r = 0;
    if (MAIL_FindEmptySlot(o, 0) == -1)
        r = 1;
    return r;
}

void POKETRADE_PROC_ClearNetAutoExit(char *p)
{
    GFL_NET_SetAutoExit(0);
    GFL_NET_SetLoginOption(0);
    GFL_NET_STATE_WifiDisconnect(0);
    ((TradeWork *)p)->request->state = 3;
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

u8 POKETRADE_PROC_GetStoredBoxIndex(u8 *p) { return ((TradeWork *)p)->storedBoxIndex; }

/*
 * True when the object has a session and its state index is in range.
 */
int POKETRADE_PROC_IsNetSession(void *p)
{
    int v;

    if (*(int *)&((TradeWork *)p)->request == 0)
        return 0;
    v = ((TradeWork *)p)->tradeState;
    if (v >= 4)
        return 0;
    return GFL_NET_GetRunState() != 0;
}

void POKETRADE_PROC_IncrementTimer(void *p) {
 int v;
 if(((TradeWork *)p)->repeatCounter!=0) {
 v=++((TradeWork *)p)->repeatCounter;
 if(v==2) {GFL_USE_FadeOutBgm(6); return;}
 if(v==8) {
 GFL_USE_SetBgmPaused((u32)1); GFL_USE_PushBgm();
 ++((TradeWork *)p)->sceneState;
 GFL_USE_CancelChangeAndPlayBgm(0x3f3,0xffff); GFL_USE_FadeInBgmFull(1);
 ((TradeWork *)p)->repeatCounter=0;
 }
 }
}

int POKETRADE_PROC_IsHostSide(void *p)
{
    unsigned int x = (*(unsigned int *)&((TradeWork *)p)->tradeState);
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

int POKETRADE_PROC_IsWifiMode(char *p)
{
    int r = 0;
    int v = ((TradeWork *)p)->tradeState;
    if (v == 3 || v == 9)
        r = 1;
    return r;
}

int POKETRADE_PROC_GetBoxIndexForSlot(int a, char *p)
{
    if (a >= 2)
        return (a - 2) / 6;
    return ((TradeWork *)p)->partyBoxId;
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

void POKETRADE_PROC_RequestBoxRedraw(char *p)
{
    ((TradeWork *)p)->cursorRow += 1;
    ((TradeWork *)p)->redrawNeeded = 1;
    POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 0);
}

void POKETRADE_PROC_UpdateDragState(void *p)
{
    int o1, o2;
    int d;

    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    if (((TradeWork *)p)->dragActor == 0)
        ((TradeWork *)p)->dragMoved = 0;
    if (((TradeWork *)p)->dragActor != 0) {
        d = ((short)((TradeWork *)p)->targetX - (short)((TradeWork *)p)->offsetX) - o1;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((TradeWork *)p)->dragMoved = 1;
        d = ((short)((TradeWork *)p)->targetY - (short)((TradeWork *)p)->offsetY) - o2;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((TradeWork *)p)->dragMoved = 1;
        d = (short)((TradeWork *)p)->targetX - o1;
        if (d < 0)
            d = -d;
        if (d > 6) {
            d = (short)((TradeWork *)p)->targetY - o2;
            if (d < 0)
                d = -d;
            if (d > 6)
                ((TradeWork *)p)->dragHold = 0;
        }
    }
    if ((unsigned int)o2 >= 0x10 && (unsigned int)o2 < 0x90) {
        ((TradeWork *)p)->iconPosX = o1;
        ((TradeWork *)p)->iconPosY = o2;
    }
}

void POKETRADE_PROC_UpdateDragIcon(void *p) {
 int x,y; short pos[2];
 if(((TradeWork *)p)->dragActor!=0) {
 if(TOUCHPANEL_GetPointCont((unsigned int *)(&x),(unsigned int *)(&y))!=0) {
 CLACT_GetActorSurfacePos((struct Actor *)((TradeWork *)p)->dragActor,(struct PtS *)((char *)p+0xf6c),1);
 pos[0]=x+((TradeWork *)p)->offsetX;
 pos[1]=y+((TradeWork *)p)->offsetY;
 if(pos[1]>150) pos[1]=150;
 CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->dragActor),(const struct Vec2 *)pos,1);
 }
 }
}

/*
 * Clear the pending pointer and hand the object to the updater.
 */
void POKETRADE_PROC_ClearDragIcon(void *p)
{
    if (((TradeWork *)p)->dragActor != 0)
        ((TradeWork *)p)->dragActor = 0;
    POKETRADE_2D_DeleteFloatingIconActor(p);
}

void POKETRADE_PROC_ShowDragIcon(void *p) {
 if(((TradeWork *)p)->dragActor!=0) {
 CLACT_SetActorDrawPriority((struct Actor *)(((TradeWork *)p)->dragActor),16);
 CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->dragActor),(const struct Vec2 *)((char *)p+0xf64),1);
 CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->dragActor,1);
 ((TradeWork *)p)->highlightSlot=-1;
 ((TradeWork *)p)->highlightBox=-1;
 POKETRADE_PROC_ClearDragIcon(p); MI_CpuFill8((char *)p+4,0,2);
 }
}

void POKETRADE_PROC_BeginDrag(void *p, int x, int y, int z, int mon)
{
    int o1, o2;

    ((TradeWork *)p)->dragActor = x;
    CLACT_GetActorSurfacePos((struct Actor *)x, (struct PtS *)((char *)p + 0xf64), 1);
    POKETRADE_2D_SetIconObjMode((int)p, ((TradeWork *)p)->dragActor, 1);
    if (TOUCHPANEL_GetPointCont((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    ((TradeWork *)p)->offsetX = (s16)((TradeWork *)p)->targetX - o1;
    ((TradeWork *)p)->offsetY = (s16)((TradeWork *)p)->targetY - o2;
    POKETRADE_2D_CreateFloatingIconActor((int)p, y, z,
                  o1 + (s16)((TradeWork *)p)->offsetX,
                  o2 + (s16)((TradeWork *)p)->offsetY,
                  (void *)mon);
    ((TradeWork *)p)->dragActor = ((TradeWork *)p)->iconActorC;
}

void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p)
{
    int n;
    void *res = 0;

    if (b == -1)
        goto out;
    n = ((TradeWork *)p)->partyBoxId;
    if (b > n)
        return 0;
    if (b != n && c != -1) {
        res = POKE_TOOL_CreateFromBoxParam((struct PokemonParam *)BOX_SAVEDATA_GetPokemon((struct GameData *)a, b, c), ((TradeWork *)p)->heapId);
    } else {
        void *m = ((TradeWork *)p)->partyData;
        if (c >= (int)POKEPARTY_GetCount(m))
            goto out;
        if (c == -1)
            goto out;
        {
            void *mon = POKE_TOOL_Create(1, 1, 1, ((TradeWork *)p)->heapId);
            int sz = POKE_TOOL_GetPartyParamSize();
            MI_CpuCopy8(POKEPARTY_GetMember(m, c), mon, sz);
            res = mon;
        }
    }
out:
    return res;
}

void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p)
{
    void *m;
    int n;

    if (b != -1) {
        n = ((TradeWork *)p)->partyBoxId;
        if (b > n)
            return 0;
        if (b != n && c != -1)
            return BOX_SAVEDATA_GetPokemon(a, b, c);
        m = ((TradeWork *)p)->partyData;
        if (c < (int)POKEPARTY_GetCount(m) && c != -1)
            return POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(m, c));
    }
    return 0;
}

char *POKETRADE_PROC_GetSlotMonPtr(int a, int b, char *p)
{
    int n;

    if (a != -1) {
        n = ((TradeWork *)p)->partyBoxId;
        if (a > n)
            return 0;
        if (a != n && b != -1)
            return p + 0x11fc + (a * 0x1e + 6 + b) * 4;
        if (b >= 0 && b < 6)
            return p + 0x11fc + b * 4;
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

void POKETRADE_PROC_SetStep(void *p, int v)
{
    ((TradeWork *)p)->stepFunc = v;
}

/*
 * Hidden leaf (no caller seen): slot lookup by index, 0 when out of range.
 */
int POKETRADE_PROC_GetPlayerMonPtr(int i, char *p)
{
    if (i >= 0 && i < 2)
        return *(int *)(p + i * 4 + 0x1064);
    return 0;
}

/*
 * Hidden leaf (no caller seen): same lookup as POKETRADE_PROC_GetPlayerMonPtr.
 */
int POKETRADE_PROC_GetPlayerMonPtrAlt(int i, char *p)
{
    if (i >= 0 && i < 2)
        return *(int *)(p + i * 4 + 0x1064);
    return 0;
}

u32 POKETRADE_PROC_GetNetIdOffset(u32 a, u32 b)
{
    if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
        return b + 0x10;
    return b + 0x2e6;
}

void POKETRADE_PROC_RecvPlayerMonA(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        u32 idx = (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) ? 0 : 1;
        *(base + idx + 0x11e8) = *src;
    }
}

int POKETRADE_PROC_GetSideValue(void *p,int idx) {
 unsigned v=POKETRADE_PROC_IsNetSession(p);
 if(v==0) return *(int *)((char *)p+idx*4+0x5e4);
 if(GFL_NET_GetHandleNetID((struct GFLNetHandle *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()))==0) return *(int *)((char *)p+idx*4+0x5e4);
 return *(int *)((char *)p+(1-idx)*4+0x5e4);
}

void POKETRADE_PROC_SetSideValue(void *p,int idx,int x) {
 unsigned v=POKETRADE_PROC_IsNetSession(p);
 if(v==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 if(GFL_NET_GetHandleNetID((struct GFLNetHandle *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()))==0) { *(int *)((char *)p+idx*4+0x5e4)=x; return; }
 *(int *)((char *)p+(1-idx)*4+0x5e4)=x;
}

/*
 * Addresses are Black-image addresses.
 */
void *POKETRADE_PROC_GetSideMon(void *p, int idx)
{
    u32 v = POKETRADE_PROC_IsNetSession(p);
    if (v == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    if (GFL_NET_GetHandleNetID((struct GFLNetHandle *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    return *(void **)((char *)p + (1 - idx) * 4 + 0x5DC);
}

void POKETRADE_PROC_RecvMonCopy(int idx,int a,int b,void *p,int id) {
 if(id==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
 int n=POKE_TOOL_GetPartyParamSize();
 MI_CpuCopy8(*(void **)((char *)p+idx*4+0x1064),*(void **)((char *)p+idx*4+0x5dc),n);
 if(idx!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) {
 ((TradeWork *)p)->pendingSideMon=idx+1;
 ((TradeWork *)p)->stateFlags.byte=(((TradeWork *)p)->stateFlags.byte&~0xf0)|0x10;
 }
 }
}

void POKETRADE_PROC_RecvMonChunkCommon(int a,int b,int c,u8 *p,int e,int f) { int z;if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) { if(a!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {z=0;if(POKE_TOOL_GetPartyValue((void *)*(int *)(p+0x1064+a*4),169,0)) {POKETRADE_NEGO_StoreRemoteOffer((char *)p,f,(void *)(*(int *)(p+0x1064+a*4)));POKETRADE_2D_CreateOfferIconActor((char *)p,1,f,(void *)(*(int *)(p+0x1064+a*4)),1,z);POKETRADE_NEGO_ShowOfferSlotMon(p,1,*(void **)(p+0x1064+a*4));}p[0x11fb]=(p[0x11fb]&~240)|16;} } }

/*
 * DWCi_EncSessionGetAsync: sixth argument is zero.
 */
void POKETRADE_PROC_RecvMonChunk0(int a, int b, int c, u8 *d, int e)
{
    POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 0);
}

void POKETRADE_PROC_RecvMonChunk1(int a, int b, int c, u8 *d, int e)
{
    POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 1);
}

/*
 * Third entry point of the encoder session getter.
 */
void POKETRADE_PROC_RecvMonChunk2(int a, int b, int c, u8 *d, int e)
{
    POKETRADE_PROC_RecvMonChunkCommon(a, b, c, d, e, 2);
}

void POKETRADE_PROC_RecvOfferMonCommon(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (c == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((TradeWork *)base)->offerReceivedValue[0][b] = a;
        else
            ((TradeWork *)base)->offerReceivedValue[1][b] = a;
    }
}



/*
 * Encoder session getter on the byte pointed at by the third argument.
 */
void POKETRADE_PROC_RecvOfferMon0(u32 a, int b, int c, u8 *d, void *e)
{
    POKETRADE_PROC_RecvOfferMonCommon(*(u8 *)c, 0, a, d, e);
}

void POKETRADE_PROC_RecvOfferMon1(u32 a, int b, int c, u8 *d, void *e)
{
    POKETRADE_PROC_RecvOfferMonCommon(*(u8 *)c, 1, a, d, e);
}

void POKETRADE_PROC_RecvOfferMon2(u32 a, int b, int c, u8 *d, void *e)
{
    POKETRADE_PROC_RecvOfferMonCommon(*(u8 *)c, 2, a, d, e);
}

void POKETRADE_PROC_RecvPlayerFlag(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        *(u32 *)(base + a * 4 + 0x5e4) = *src;
}

void POKETRADE_PROC_RecvPeerSelection(u32 a, u32 b, u32 c, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            ((TradeWork *)base)->stateFlags.byte = ((TradeWork *)base)->stateFlags.byte & ~0xf;
    }
}

void POKETRADE_PROC_RecvPeerValue(u32 a, u32 b, u32 c, u32 d, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a == GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            return;
    }
}

void POKETRADE_PROC_RecvPeerFlags(int a,int b,const u8 *c,u8 *p,int e) {
 if(e==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if(a!=GFL_NET_GetHandleNetID((struct GFLNetHandle *)((int)GFL_NET_HANDLE_GetCurrentHandle()))) {
   p[0x11f2]=c[0]; p[0x11f4]=c[1];
   (*(unsigned short *)&((TradeWork *)p)->scrollY)=p[0x11f2]*160+16;
  }
 }
}

void POKETRADE_PROC_RecvPeerState(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            base[0x11e7] = *src;
    }
}

void POKETRADE_PROC_RecvTradeSummary(void *netId, int size, void *data, char *work, int handle)
{
    u8 buf[0x28];
    u8 x, y;
    u32 r1, r2;
    void *saved;

    if (handle != (int)GFL_NET_HANDLE_GetCurrentHandle())
        return;
    if (netId == (void *)GFL_NET_GetHandleNetID((struct GFLNetHandle *)((u32)GFL_NET_HANDLE_GetCurrentHandle())))
        return;
    saved = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(((TradeWork *)work)->gameData));
    MI_CpuCopy8(data, buf, 0x28);
    x = MYSTATUS_GetNation((struct MyStatus *)buf);
    y = MYSTATUS_GetArea((struct MyStatus *)buf);
    r1 = NATION_AREA_SanitizeNation(x, y, MYSTATUS_GetLanguage((struct MyStatus *)buf));
    r2 = NATION_AREA_SanitizeArea(x, y, MYSTATUS_GetLanguage((struct MyStatus *)buf));
    if (x == r1 && y == r2)
        MYSTATUS_SetNationAndArea((struct MyStatus *)buf, x, y);
    else
        MYSTATUS_SetNationAndArea((struct MyStatus *)buf, 0, 0);
    (struct HistoryOwner *)(struct HistoryEntry *)COMM_HISTORY_InsertIfNationSet((struct HistoryOwner *)saved, (struct HistoryEntry *)buf);
}

void POKETRADE_PROC_RecvStateByte(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle())
        (base + a)[0x11e0] = *src;
}

void POKETRADE_PROC_RecvPeerByte(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            (*(unsigned int *)&((TradeWork *)base)->netFlag) = *src;
    }
}

void POKETRADE_PROC_RecvPeerWord(u32 a, u32 b, int *src, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle())) {
            POKETRADE_NEGO_RemoveOffer(base, 1, *src);
            POKETRADE_2D_DeleteOfferIconActor(base, 1, *src);
        }
    }
}

void POKETRADE_PROC_RecvPeerWordB(u32 a, u32 b, u32 c, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle()))
            POKETRADE_PROC_ClearSideMon(base, 1);
    }
}

void POKETRADE_PROC_RecvPeerHalf(u32 a, u32 b, short *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            ((TradeWork *)base)->scrollY = *src;
    }
}

void POKETRADE_PROC_RecvPeerByteB(u32 a, u32 b, u8 *src, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            POKETRADE_NEGO_FlashMarker(base, *src, 1);
    }
}

void POKETRADE_PROC_RecvIgnoredA(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}

void POKETRADE_PROC_RecvPeerByteC(u32 a, u32 b, u8 *src, u8 *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_SYSTEM_GetCurrentAid())
            (*(unsigned int *)&((TradeWork *)base)->offerCount) = *src;
    }
}

void POKETRADE_PROC_RecvIgnoredB(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}

/*
 * Byte-identical twin of POKETRADE_PROC_RecvIgnoredA (same 12-byte predicate stub).
 */
void POKETRADE_PROC_RecvIgnoredC(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if ((u32)GFL_NET_HANDLE_GetCurrentHandle() == e)
        return;
}

void POKETRADE_PROC_StepWaitWipeEnd(void *p)
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
void POKETRADE_PROC_StepBeginWipeOut(void *p)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, ((TradeWork *)p)->heapId);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitWipeEnd);
}

/*
 * Start a transfer on the object when the length is non-zero.
 */
void POKETRADE_PROC_SetSideMon(void *p, int a, void *b)
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
void POKETRADE_PROC_ClearSideMon(void *p, int a)
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

int POKETRADE_PROC_IsSelfMonReady(char *p) { int w; void *v; int z; if(POKETRADE_PROC_IsHostSide(p)==0) {v=POKETRADE_PROC_GetSideMon(p,0);w=POKETRADE_PROC_GetSideValue(p,0);} else {v=POKETRADE_PROC_GetSideMon(p,1);w=POKETRADE_PROC_GetSideValue(p,1);} z=0;if(POKE_TOOL_GetPartyValue(v,160,0)==0)return z;if(POKE_TOOL_GetPartyValue(v,76,0))return z;if(POKEPARTY_GetAliveNonEggCount((void *)((*(int *)&((TradeWork *)p)->partyData)))==1 && w!=0)return 1;return 0; }

int POKETRADE_PROC_IsSelectedOfferSlot(char *p,int a,int b) { int v=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager),a,b,p); int r; if(((TradeWork *)p)->tradeState) return 0; if(a!=((TradeWork *)p)->partyBoxId) return 0; r=0; if(POKE_TOOL_GetBoxValue((void *)v,76,0)) return r; if(POKE_TOOL_HasNoHmMove((void *)v,r)==0) r=1; return r; }

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
int POKETRADE_PROC_IsCurrentSideMonInvalid(void *p)
{
    int b = 0;

    if (POKETRADE_PROC_IsHostSide(p))
        b = 1;
    return POKETRADE_PROC_IsMonBadEggOrInvalid(POKETRADE_PROC_GetSideMon(p, b));
}

u32 POKETRADE_PROC_IsOtherSideMonInvalid(void *p)
{
    int r = 1;
    if (POKETRADE_PROC_IsHostSide(p) != 0)
        r = 0;
    return POKETRADE_PROC_IsMonBadEggOrInvalid(POKETRADE_PROC_GetSideMon(p, r));
}

int POKETRADE_PROC_IsMonTradeable(unsigned char *p) { void *v; int w; if(POKETRADE_PROC_IsHostSide(p)==0) {v=POKETRADE_PROC_GetSideMon(p,0); w=POKETRADE_PROC_GetSideValue(p,1);} else {v=POKETRADE_PROC_GetSideMon(p,1); w=POKETRADE_PROC_GetSideValue(p,0);} if(FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(v,6,0)) && p[0x11f4]!=0 && w==0) return 1; return 0; }

void POKETRADE_PROC_BuildPartyPacket(char *p)
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
        } else if (POKETRADE_PROC_IsMonTradeable((unsigned char *)p)) {
            b[1] = 6;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[1]);
        } else {
            b[0] = 2;
            r = GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b[0]);
        }
        if (r == 0)
            return;
        GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepResolveCursorResult);
        return;
    }
    p[0x11e0] = 2;
    p[0x11e1] = 2;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepResolveCursorResult);
}

void POKETRADE_PROC_ShowIntroMessage(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), 6, (void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_BuildPartyPacket);
}

/*
 * 2026-10-02: the 0204B404 call is written in each branch of the a1 test (tail-merged
 *  by the compiler, so the 0xf0c pool constant is not hoisted across blocks);
 *  020355C4 is a void getter called on its own; the 021D8FA4 result is a local.
 */
void POKETRADE_PROC_PlaceCursorIcon(char *p, int cursorIndex, int showSummary)
{
    Pt t0, t1;
    if (cursorIndex == 0) {
        t0 = gCursorIconPos0;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->actorF0C), (const struct Vec2 *)(&t0), 1);
    } else {
        t1 = gCursorIconPos1;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->actorF0C), (const struct Vec2 *)(&t1), 1);
    }
    if (UI_GetInputMode()) {
        POKETRADE_2D_PlaceTouchbarActors(p, cursorIndex, 0);
        CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->actorF0C, 0);
    } else {
        POKETRADE_2D_PlaceTouchbarActors(p, cursorIndex, 1);
        CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->actorF0C, 1);
    }
    if (showSummary != 0) {
        void *v;

        v = POKETRADE_PROC_GetSideMon(p, ((TradeWork *)p)->cursorIndex);
        POKETRADE_SAVE_ShowSummaryMon(p, v, ((TradeWork *)p)->cursorIndex, 1);
    }
}

void POKETRADE_PROC_StepReturnFromSummary(char *p) { int z,one; if(WIPE_SYS_EndCheck()) {z=0;BG_SYS_SetPlaneVisible(3,0);one=1;POKETRADE_SAVE_CloseSummaryPage(p,1);BG_SYS_SetPlaneVisible(4,0);POKETRADE_2D_LoadBackgroundGfx(p);POKETRADE_3D_AddUnitAndInit(p,0);BG_SYS_MarkTileDirty(3);*(u16 *)0x04000050=z;POKETRADE_PROC_SetSideMon(p,0,POKETRADE_PROC_GetSideMon(p,0));POKETRADE_PROC_SetSideMon(p,1,POKETRADE_PROC_GetSideMon(p,1));POKETRADE_PROC_RequestBoxRedraw(p);WIPE_SYS_Start((void *)3,1,1,0,6,one,((TradeWork *)p)->heapId);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepShowTradeSummary); } }

static inline int poll(void) {int v=KEY_GetTrg();if(v)UI_SetInputMode(0);return v;}

/*
 * prototype: 02035C08 is declared int here: original consumes r0 after
 * its 02035BBC forwarding call; the matched void spelling leaves r0 live.
 * Full matched ARM9 02035BBC returns int through 02035ADC, or -1.
 * wrap: the 10a0 toggle uses full-width unsigned subtraction to preserve
 * the original SUB for every 32-bit field pattern without a domain claim.
 */
void POKETRADE_PROC_StepMain(char *p)
{
 int done=0;
 if(((TradeWork *)p)->wipeDone==0 && WIPE_SYS_EndCheck()) {
  if(UI_GetInputMode() && poll()) {UI_SetInputMode(0);POKETRADE_PROC_PlaceCursorIcon(p,((TradeWork *)p)->cursorIndex,0);return;}
  BG_SYS_SetPlaneVisible(3,1);
  switch(TOUCHPANEL_HitTrg(gMainMenuHitArea)) {
  case 0:
   if(((TradeWork *)p)->cursorIndex!=0 || !UI_GetInputMode()) {
    ((TradeWork *)p)->cursorIndex=0;UI_SetInputMode(1);GFL_USE_PlaySeDefaultVolume(0x548);POKETRADE_PROC_PlaceCursorIcon(p,((TradeWork *)p)->cursorIndex,1);
   }
   break;
  case 1:
   if(((TradeWork *)p)->cursorIndex!=1 || !UI_GetInputMode()) {
    ((TradeWork *)p)->cursorIndex=1;UI_SetInputMode(1);GFL_USE_PlaySeDefaultVolume(0x548);POKETRADE_PROC_PlaceCursorIcon(p,((TradeWork *)p)->cursorIndex,1);
   }
   break;
  case 2:done=1;break;
  }
  if(poll()==32 || poll()==16) {
   *(unsigned *)&((TradeWork *)p)->cursorIndex=1u-*(unsigned *)&((TradeWork *)p)->cursorIndex;GFL_USE_PlaySeDefaultVolume(0x548);UI_SetInputMode(0);POKETRADE_PROC_PlaceCursorIcon(p,((TradeWork *)p)->cursorIndex,1);
  }
  TOUCHBAR_Update((*(void * *)&((TradeWork *)p)->touchbar));
  if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->touchbar)==1)done=1;
  if(done) {WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->heapId);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepReturnFromSummary);}
 }
}

void POKETRADE_PROC_StepAfterSummaryWipe(char *p) { if(WIPE_SYS_EndCheck()) { ((TradeWork *)p)->cursorIndex=0; POKETRADE_SAVE_OpenSummaryScreen(p,POKETRADE_PROC_GetSideMon(p,0));POKETRADE_PROC_RequestBoxRedraw(p);WIPE_SYS_Start((void *)3,1,1,0,6,1,((TradeWork *)p)->heapId);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepMain); } }

void POKETRADE_PROC_StepMainMenuChoice(char *p) { int v; if(APP_TASKMENU_IsFinish((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu))) {v=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu));POKETRADE_SAVE_CloseTaskMenu(p);POKETRADE_SAVE_CloseMessageWindowClear(p);((TradeWork *)p)->taskMenu=0;switch(v) {case 0:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowIntroMessage);return;case 1:WIPE_SYS_Start((void *)3,0,0,0,6,1,((TradeWork *)p)->heapId);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAfterSummaryWipe);return;case 2:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendNewRound);return;} } }

void POKETRADE_PROC_StepShowTradeSummary(char *p) { int i; MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),17,(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));for(i=0;i<2;i++) WORDSET_SetSlotMonNickname((*(void * *)&((TradeWork *)p)->wordSet),i,POKETRADE_PROC_GetSideMon(p,i));WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->messageText),(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenMainMenu); }

void POKETRADE_PROC_StepOpenMainMenu(char *p) { if(POKETRADE_SAVE_IsMessagePrintDone(p)) { IntTriple t=gMainMenuLayout; POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),3); BG_SYS_SetMainVisiblePlanes(31); TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepMainMenuChoice); } }

void POKETRADE_PROC_StepWaitSync20(void *p) {
 if(POKETRADE_PROC_IsNetSession(p)) {
  if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),20,8)) {
   POKETRADE_SAVE_CloseMessageWindowClear(p); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);
  }
 } else { POKETRADE_SAVE_CloseMessageWindowClear(p); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut); }
}

void POKETRADE_PROC_StepStartSync20(char *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p) && ((TradeWork *)p)->waitCounter>30) {
  if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),20,8);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitSync20);
 }
}

void POKETRADE_PROC_StepIntro(char *p)
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
    a = ((u8 *)p + me)[0x11e0];
    if (a == 1 && ((u8 *)p + other)[0x11e0] == 1) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepShowTradeSummary);
        return;
    }
    if (a == 4 && ((u8 *)p + other)[0x11e0] == 4) {
        ((TradeWork *)p)->request->state = 3;
        MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), 0x8d, (void *)(((TradeWork *)p)->messageText));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_SAVE_ShowTimeIcon(p);
        ((TradeWork *)p)->waitCounter = 0;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepStartSync20);
        return;
    }
    if (((u8 *)p + other)[0x11e0] == 4)
        cmd = 0x61;
    else if (a == 4)
        cmd = 0x66;
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), cmd, (void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    p[0x11e0] = 0;
    p[0x11e1] = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepShowWaitMessageA);
}

void POKETRADE_PROC_StepSendIntroReady(u8 *p) { int kind=POKETRADE_PROC_IsNetSession(p); u8 b; if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)) { if(kind==0) {p[0x11e0]=1;p[0x11e1]=1;POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro);return;} b=1; if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)==0) return; GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro); } }

void POKETRADE_PROC_StepMenuChoice(char *p) {
    int v;
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu))) {
        v=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu));
        POKETRADE_SAVE_CloseTaskMenu(p);
        ((TradeWork *)p)->taskMenu=0;
        if (v==0) {
            MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),6,(void *)(((TradeWork *)p)->messageText));
            POKETRADE_SAVE_OpenMessageWindowTop(p);
            POKETRADE_SAVE_ShowTimeIcon(p);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendIntroReady);
            return;
        }
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetGrid);
    }
}

void POKETRADE_PROC_StepOpenMenu(void *p)
{
    if (POKETRADE_PROC_SendSideMon(p)) {
        Pair t = gOpenMenuPos;
        POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
        G2x_SetBlendBrightness_(0x04001050,0x1B,-8);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepMenuChoice);
    }
}

void POKETRADE_PROC_StepSendPartyBoxSelected(char *p)
{
    int v = 0;
    if (((TradeWork *)p)->selectedBox == ((TradeWork *)p)->partyBoxId) v=1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xC16,1,&v))
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenMenu);
}

void POKETRADE_PROC_HideTouchbarButtons(char *p) {
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),7,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),8,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),9,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
    CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->cursorActor,0);
    POKETRADE_PROC_ClearDragIcon(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendPartyBoxSelected);
}

void POKETRADE_PROC_SetDragTarget(char *p,int a,int b) {
 ((TradeWork *)p)->cursorSlot=a;
 ((TradeWork *)p)->cursorColumn=b;
 POKETRADE_PROC_RequestBoxRedraw(p);
}

int POKETRADE_PROC_PollGridTouch(char *p,int *a,int *b,int *c,int *d) {
    int x,y,z,n;
    if(TOUCHPANEL_GetPointTrg((unsigned int *)(&x),(unsigned int *)(&y))==1) {
        if(POKETRADE_2D_HitTestBoxIcons(p,x+12,y+12,a,b,c,d,&z)) {
            n=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager),*a,*b,p);
            if(n && POKE_TOOL_GetBoxValue((void *)n,0xA9,0)) return 1;
        }
    }
    return 0;
}

int POKETRADE_PROC_PollGridTouchDrag(char *p,int save)
{
 int x,y,a,b,c,hit,e,result=0;
 if(TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y))==1) {
  hit=POKETRADE_2D_HitTestBoxIcons(p,x+12,y+12,(int *)(p+0xf80),(int *)(p+0xf7c),&a,&b,&c);
  if(hit) {
   e=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)((TradeWork *)p)->boxManager,((TradeWork *)p)->highlightBox,((TradeWork *)p)->highlightSlot,p);
   if(POKETRADE_PROC_IsTradeTargetValid(p,((TradeWork *)p)->highlightBox,((TradeWork *)p)->highlightSlot)) {
    GFL_USE_PlaySeDefaultVolume(0x626);
    if(!POKETRADE_PROC_IsHostSide(p)) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepClearPeerSelection);return 3;}
    ((TradeWork *)p)->peerSelectedBox=((TradeWork *)p)->highlightBox;((TradeWork *)p)->peerSelectedSlot=((TradeWork *)p)->highlightSlot;POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendOfferRemoval);return 3;
   }
   POKETRADE_PROC_ShowDragIcon(p);
   if(e && POKE_TOOL_GetBoxValue((void *)e,0xa9,0)) {
    if(POKETRADE_PROC_CanTradeMon(p,e)) {
     MSGDATA_ReadString((struct MsgBank *)((TradeWork *)p)->messageBank,0x8e,(void *)((TradeWork *)p)->messageText);POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitKeyAfterMessage);return 2;
    }
    POKETRADE_PROC_BeginDrag(p,hit,c,b,e);POKETRADE_PROC_SetDragTarget(p,a,b);
    if(save) {((TradeWork *)p)->peerSelectedBox=((TradeWork *)p)->highlightBox;((TradeWork *)p)->peerSelectedSlot=((TradeWork *)p)->highlightSlot;}
    POKETRADE_PROC_RequestBoxRedraw(p);result=1;
   }
  }
 }
 return result;
}

void POKETRADE_PROC_StepWaitKeyAfterMessage(char *p) {
    int v;
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        v=KEY_GetTrg();
        if(v) UI_SetInputMode(0);
        if(!v) {
            v=TOUCHPANEL_GetTrg();
            if(v) UI_SetInputMode(1);
            if(!v) return;
        }
        ((TradeWork *)p)->highlightBox=-1;
        ((TradeWork *)p)->highlightSlot=-1;
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
        ((TradeWork *)p)->cursorRow=-1;
        POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,1);
    }
}

void POKETRADE_PROC_ShowCancelMessage(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), 0x65, (void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    ((TradeWork *)p)->cursorRow = -1;
    POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager, p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitKeyAfterMessage);
}

void POKETRADE_PROC_ShowSelectMessage(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), 0x8E, (void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);
    ((TradeWork *)p)->cursorRow = -1;
    POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager, p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitKeyAfterMessage);
}

void POKETRADE_PROC_ShowPeerSummary(char *p) {
    int v=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((TradeWork *)p)->boxManager,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot,p);
    POKETRADE_SAVE_CloseSummaryWindow(p,0);
    POKETRADE_SAVE_DrawSummaryPage(p,((TradeWork *)p)->cursorIndex,(void *)v);
    if (UI_GetInputMode()) POKETRADE_PROC_RequestBoxRedraw(p);
    GFL_HEAP_Free((void *)v);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepPeerSummaryMenu);
}

void POKETRADE_PROC_StepAddSelectedOffer(char *p) {
 if(POKETRADE_NEGO_AddSelectedAsOffer(p,((TradeWork *)p)->selectedSlot,((TradeWork *)p)->selectedBox)) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRebuildBrowseScene);
}

void POKETRADE_PROC_StepSendAddOffer(char *p) {
    int v=0;
    int n;
    if(((TradeWork *)p)->selectedBox==((TradeWork *)p)->partyBoxId) v=1;
    n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,((TradeWork *)p)->selectedSlot,((TradeWork *)p)->selectedBox);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,&v)) {
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAddSelectedOffer);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAddSelectedOffer);
}

void POKETRADE_PROC_StepApplyAddOffer(char *p) {
 if(POKETRADE_NEGO_AddSelectedAsOffer(p,((TradeWork *)p)->selectedSlot,((TradeWork *)p)->selectedBox)) POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowCancelMessage);
}

void POKETRADE_PROC_StepSendApplyAddOffer(char *p) {
    int v=0;
    int n;
    if(((TradeWork *)p)->selectedBox==((TradeWork *)p)->partyBoxId) v=1;
    n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,((TradeWork *)p)->selectedSlot,((TradeWork *)p)->selectedBox);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,&v)) {
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepApplyAddOffer);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepApplyAddOffer);
}

void POKETRADE_PROC_StepWaitTouchReleasePeer(void *p) {
 int a,b;
 if(!TOUCHPANEL_GetPointCont((u32 *)(&a),(u32 *)(&b))) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
}

void POKETRADE_PROC_StepPeerSummaryMenu(char *p)
{
    u32 x,y;
    int slot,column;
    int changed=0;
    int keep=1;
    int choice=keep-2;
    int active=0;
    int n;
    if(!APP_TASKMENU_IsDecide(((TradeWork *)p)->taskMenu)) {
        n=TOUCHPANEL_GetTrg();
        if(n) UI_SetInputMode(keep);
        if(n) POKETRADE_PROC_ShowDragIcon(p);
        TOUCHBAR_Update(((TradeWork *)p)->touchbar);
        if(TOUCHBAR_GetPressedButtonIdIfPressing(((TradeWork *)p)->touchbar)==9 && UI_GetInputMode()) APP_TASKMENU_SetCursorActive(((TradeWork *)p)->taskMenu,0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(((TradeWork *)p)->touchbar)==9) {
            changed=1;
            (*(unsigned int *)&((TradeWork *)p)->cursorIndex)=1U-(*(unsigned int *)&((TradeWork *)p)->cursorIndex);
        }
        if(TOUCHPANEL_GetPointTrg(&x,&y)==1) {
            UI_SetInputMode(1);
            APP_TASKMENU_SetCursorActive(((TradeWork *)p)->taskMenu,0);
            if(POKETRADE_PROC_PollGridTouch(p,(int *)(p+0xf98),(int *)(p+0xf94),&slot,&column)) {
                ((TradeWork *)p)->cursorColumn=column;
                ((TradeWork *)p)->cursorSlot=slot;
                (*(unsigned int *)&((TradeWork *)p)->iconPosX)=x;
                (*(unsigned int *)&((TradeWork *)p)->iconPosY)=y;
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed=1;
            } else if(y>=16 && y<144) active=1;
        }
        if(changed) {
            POKETRADE_SAVE_CloseSummaryWindow(p,1);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowPeerSummary);
            return;
        }
        POKETRADE_PROC_UpdateDragIcon(p);
        if(!active && !TOUCHPANEL_GetCont() && ((TradeWork *)p)->prevTouch) {
            if(((TradeWork *)p)->dragActor && ((TradeWork *)p)->dragMoved) {
                GFL_USE_PlaySeDefaultVolume(0x72a);
                choice=0;
                active=1;
            } else POKETRADE_PROC_ShowDragIcon(p);
        }
        POKETRADE_PROC_UpdateDragState(p);
        POKETRADE_PROC_UpdateDragIcon(p);
    }
    if(APP_TASKMENU_IsFinish(((TradeWork *)p)->taskMenu)) {
        choice=APP_TASKMENU_GetCursorPos(((TradeWork *)p)->taskMenu);
        active=1;
    }
    if(active) {
        if(choice==0) {
            n=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)((TradeWork *)p)->boxManager,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot,p);
            if(POKETRADE_PROC_IsTradeTargetValid(p,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot) && POKETRADE_PROC_IsHostSide(p)) {
                ((TradeWork *)p)->selectedSlot=((TradeWork *)p)->peerSelectedSlot;
                ((TradeWork *)p)->selectedBox=((TradeWork *)p)->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendAddOffer);
            } else if(POKETRADE_PROC_IsSelectedOfferSlot(p,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot)) {
                POKETRADE_NEGO_SetOfferMarkersState(p,1);
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowCancelMessage);
            } else if(POKETRADE_PROC_CanTradeMon(p,n)) {
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_ShowSelectMessage);
                POKETRADE_NEGO_SetOfferMarkersState(p,1);
            } else if(!POKETRADE_PROC_IsHostSide(p)) {
                ((TradeWork *)p)->selectedSlot=((TradeWork *)p)->peerSelectedSlot;
                ((TradeWork *)p)->selectedBox=((TradeWork *)p)->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_HideTouchbarButtons);
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,7,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,8,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,9,0);
                keep=0;
            } else if(POKETRADE_NEGO_CanConfirmOffers(p) && !UI_GetInputMode()) {
                ((TradeWork *)p)->selectedSlot=((TradeWork *)p)->peerSelectedSlot;
                ((TradeWork *)p)->selectedBox=((TradeWork *)p)->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendApplyAddOffer);
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,7,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,8,0);
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,9,0);
                keep=0;
            } else {
                ((TradeWork *)p)->selectedSlot=((TradeWork *)p)->peerSelectedSlot;
                ((TradeWork *)p)->selectedBox=((TradeWork *)p)->peerSelectedBox;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendAddOffer);
            }
        } else {
            POKETRADE_NEGO_SetOfferMarkersState(p,1);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitTouchReleasePeer);
        }
        ((TradeWork *)p)->peerSelectedBox=-1;
        ((TradeWork *)p)->peerSelectedSlot=-1;
        if(keep) {
            POKETRADE_PROC_UpdateTouchbarButtons(p);
            CLACT_SetActorDrawEnable(((TradeWork *)p)->cursorActor,1);
        }
        POKETRADE_2D_DeleteMarkingIcon(p+0x950);
        POKETRADE_2D_DeleteMarkingIcon(p+0x964);
        POKETRADE_2D_DeleteMarkingIcon(p+0x978);
        POKETRADE_SAVE_CloseSummaryWindow(p,1);
        BG_SYS_MarkTileDirty(6);
        POKETRADE_2D_ClearSummaryBackground(p);
        POKETRADE_SAVE_CloseTaskMenu(p);
        ((TradeWork *)p)->taskMenu=0;
    }
    ((TradeWork *)p)->prevTouch=TOUCHPANEL_GetCont();
}

void POKETRADE_PROC_StepOpenPeerSummary(char *p) {
    Pair t;
    int n;
    int zero=0;
    POKETRADE_NEGO_SetOfferMarkersState(p,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),7,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),9,1);
    t=gPeerSummaryPos;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
    n=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((TradeWork *)p)->boxManager,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot,p);
    ((TradeWork *)p)->cursorIndex=zero;
    POKETRADE_SAVE_DrawSummaryPage(p,0,(void *)n);
    GFL_HEAP_Free((void *)n);
    CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->cursorActor,0);
    POKETRADE_PROC_ShowDragIcon(p);
    POKETRADE_PROC_RequestBoxRedraw(p);
    if(UI_GetInputMode()) APP_TASKMENU_SetCursorActive((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu),zero);
    else APP_TASKMENU_SetCursorActive((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu),1);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepPeerSummaryMenu);
}

void POKETRADE_PROC_StepSendCursorChoice(char *p) {
 u8 b=((TradeWork *)p)->cursorIndex;
 if(POKETRADE_PROC_IsNetSession(p)) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,1,&b)==0) return;}
 *(unsigned *)0x04001000 &= 0xffff1fff;
 if(POKETRADE_PROC_IsHostSide(p)==0) POKETRADE_PROC_SetStep(p,(int)POKETRADE_IRCDEMO_StepStartCompare);
 else POKETRADE_PROC_SetStep(p,(int)POKETRADE_DEMO_MIDDLE_StepStartCompare);
}

void POKETRADE_PROC_StepWaitCursorSync(void *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),13,8)) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendCursorChoice);
}

void POKETRADE_PROC_StepResolveCursorResult(char *p) {
 int i, j, v;
 unsigned char a, b;
 i = GFL_NET_GetHandleNetID((struct GFLNetHandle *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()));
 j = 1 - i;
 if(POKETRADE_PROC_IsNetSession(p) && GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),27,8)==0) {
  POKETRADE_NEGO_CheckCancelTouch(p);
  return;
 }
 POKETRADE_NEGO_CloseCancelMenu(p,1,1);
 a = (p+i)[0x11e0];
 if(a==2 && ((unsigned char *)(p+j))[0x11e0]==2) {
  if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),13,8);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitCursorSync);
  return;
 }
 b = (p+j)[0x11e0];
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
 MSGDATA_ReadString((struct MsgBank *)((*(unsigned int *)&((TradeWork *)p)->messageBank)),v,(void *)((*(unsigned int *)&((TradeWork *)p)->messageText)));
 POKETRADE_SAVE_OpenMessageWindowTop(p);
 p[0x11e0]=0;
 p[0x11e1]=0;
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepShowWaitMessageA);
}

void POKETRADE_PROC_StepRebuildTradeScene(char *p) {
 if(POKETRADE_PROC_IsHostSide(p)) {POKETRADE_PROC_StepResetGrid(p);POKETRADE_PROC_StepEnterBrowsing(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitKeyThenBrowse);}
 else {POKETRADE_PROC_StepResetGrid(p);POKETRADE_PROC_StepEnterBrowsing(p);}
 WIPE_SYS_Start(0,1,1,0,6,1,((TradeWork *)p)->heapId);
 BG_SYS_SetMainVisiblePlanes(31);BG_SYS_SetSubVisiblePlanes(30);
}

void POKETRADE_PROC_StepRestoreBrowseScene(char *p)
{
 if(POKETRADE_PROC_IsNetSession(p) && !GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)) return;
 POKETRADE_SAVE_CloseMessageWindowClear(p);
 if(POKETRADE_PROC_IsHostSide(p)) {
  POKETRADE_NEGO_ClearOfferSlots(p);POKETRADE_NEGO_ExitMarkers(p);
  if(((TradeWork *)p)->tradeState==2) DWC_RAP_SetVchatTalkLock(0);
  MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),134,(void *)(((TradeWork *)p)->messageText));POKETRADE_SAVE_OpenMessageWindowTop(p);
  POKETRADE_NEGO_RegisterIconResources(p,0);POKETRADE_NEGO_DrawPlayerNames(p);
  ((TradeWork *)p)->labelStateA=0;((TradeWork *)p)->labelStateB=0;
  POKETRADE_NEGO_InitOfferMarkers(p);POKETRADE_NEGO_SetOfferMarkersState(p,1);
  MI_CpuFill8(p+0xca0,0,0x78);MI_CpuFill8(p+0xd18,0,0x3c);MI_CpuFill8(p+0xd54,0,0x3c);
  POKETRADE_PROC_ShowDragIcon(p);
  if(((TradeWork *)p)->taskMenu) {APP_TASKMENU_CloseMenu((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu));((TradeWork *)p)->taskMenu=0;}
  POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_UpdateTouchbarButtons(p);
 }
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRebuildTradeScene);POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
}

void POKETRADE_PROC_StepWaitThenRestoreScene(void *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p) && WIPE_SYS_EndCheck()) {
  POKETRADE_SAVE_CloseMessageWindowClear(p);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRestoreBrowseScene);
 }
}

void POKETRADE_PROC_StepBeginWipeToRestore(char *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,((TradeWork *)p)->heapId);
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitThenRestoreScene);
}

void POKETRADE_PROC_StepWaitSyncThenWipe(void *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,8)!=0) {
  POKETRADE_3D_UploadCubeTextures(p);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeToRestore);
 }
}

void POKETRADE_PROC_StepSendTradeData(char *p) {
 if(POKETRADE_PROC_IsNetSession(p)) {
  if((struct GFLNetHandle *)(void *)GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0e,0x2d6,(void *)(p+16),0,0,1)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),18,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitSyncThenWipe);
  }
 } else {POKETRADE_3D_UploadCubeTextures(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitSyncThenWipe);}
}

void POKETRADE_PROC_StepBuildTradeRecord(char *p) {
 POKETRADE_PROC_BuildTradeRecords(p,((TradeWork *)p)->waitCounter-1);
 if(((TradeWork *)p)->waitCounter>=24) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendTradeData);
}

void POKETRADE_PROC_StepBuildMarkingTable(char *p) {
 if(POKETRADE_2D_BuildMarkingTablesFrom(p,((TradeWork *)p)->waitCounter-1)) {
  ((TradeWork *)p)->waitCounter=0;
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBuildTradeRecord);
 }
}

void POKETRADE_PROC_StepSendBoxInfo(char *p) {
 u8 b[2];
 if(POKETRADE_PROC_IsNetSession(p)) {
  b[0]=((TradeWork *)p)->partyBoxId;b[1]=POKETRADE_PROC_IsMailBoxFull(p);
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc10,2,(void *)b)) {((TradeWork *)p)->waitCounter=0;POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBuildMarkingTable);}
 } else {
  p[0x11f2]=((TradeWork *)p)->partyBoxId;(*(unsigned short *)&((TradeWork *)p)->scrollY)=((TradeWork *)p)->storedBoxIndex*160+16;
  ((TradeWork *)p)->waitCounter=0;POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBuildMarkingTable);
 }
}

void POKETRADE_PROC_StepLoadBoxIconGfx(char *p) {
 POKETRADE_2D_LoadBoxIconGfx(p,((TradeWork *)p)->waitCounter-1);
 if(((TradeWork *)p)->waitCounter>25) {
  POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,0);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendBoxInfo);
 }
}

void POKETRADE_PROC_StepWaitNetSync22(char *p) {
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),22,8)) {
  GFL_NET_SetAutoExit(1);
  GFL_NET_SetLoginOption(1);
  ((TradeWork *)p)->waitCounter=0;
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepLoadBoxIconGfx);
 }
}

void POKETRADE_PROC_StepAfterWipeLoadBox(void *p) {
 if(WIPE_SYS_EndCheck()) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),22,8);
   POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitNetSync22);
  } else { POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendBoxInfo); }
 }
}

void POKETRADE_PROC_StepRestartNetSession(char *p) {
 GFL_NET_RefreshWmIconAtTopRight(1,((TradeWork *)p)->heapId);if(((TradeWork *)p)->tradeState==2)DWC_RAP_SetVchatTalkLock(1);
 MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),6,(void *)(((TradeWork *)p)->messageText));POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);POKETRADE_SAVE_ShowTimeIcon(p);
 BG_SYS_SetMainVisiblePlanes(16);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(0);
 WIPE_SYS_Start((void *)4,1,1,0,6,1,((TradeWork *)p)->heapId);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAfterWipeLoadBox);
}

void POKETRADE_PROC_StepResetForNewRound(char *p) {
 int i;
 GFL_NET_SYSTEM_GetCurrentAid();((TradeWork *)p)->selectedBox=-1;((TradeWork *)p)->selectedSlot=-1;((TradeWork *)p)->filterIndex=0;((TradeWork *)p)->dragActor=0;((TradeWork *)p)->netFlag=0;
 POKETRADE_3D_DeleteMcssSlot(p,0);POKETRADE_3D_DeleteMcssSlot(p,1);if(POKETRADE_PROC_IsHostSide(p))POKETRADE_NEGO_ClearOfferSlots(p);
 MI_CpuFill8(((TradeWork *)p)->monABuf,0,POKE_TOOL_GetPartyParamSize());MI_CpuFill8(((TradeWork *)p)->monBBuf,0,POKE_TOOL_GetPartyParamSize());
 for(i=0;i<10;i++) {if(*(int *)(p+0xefc+4*i))CLACT_SetActorDrawEnable((struct Actor *)*(int *)(p+0xefc+4*i),1);}
 POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRestartNetSession);
}

void POKETRADE_PROC_StepWaitMessageThenResolve(void *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),27,8);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResolveCursorResult);
 }
}

void POKETRADE_PROC_StepSendNewRound(void *p)
{
    u8 b = 3;

    if (POKETRADE_PROC_IsNetSession(p) == 0) {
        MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), 0x61,
                      (void *)(((TradeWork *)p)->messageText));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p, 0x021DAEF1);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), 0xc00, 1, &b) == 0)
        return;
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x1b, 8);
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), 6, (void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p, 0x021DAD85);
}

void POKETRADE_PROC_StepClearOffersNewRound(char *p) {
 int i;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {POKETRADE_NEGO_CheckCancelTouch(p);return;}
 POKETRADE_NEGO_CloseCancelMenu(p,1,1);POKETRADE_SAVE_CloseMessageWindowClear(p);
 p[0x11e0]=0;p[0x11e1]=0;p[0x11e8]=0;p[0x11e9]=0;
 for(i=0;i<6;i++) {
  char *q=p+(i/3)*12+(i%3)*4;
  ((TradeWork *)q)->offerSlot[0][0]=-1;
  if(((TradeWork *)q)->offerMon[0][0])MI_CpuFill8(((TradeWork *)q)->offerMon[0][0],0,POKE_TOOL_GetPartyParamSize());
 }
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetGrid);
}

void POKETRADE_PROC_StepWaitMessageThenClear(void *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),25,8);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepClearOffersNewRound);
 }
}

static inline int poll_a(void) {int r=KEY_GetTrg();if(r)UI_SetInputMode(0);return r;}

static inline int poll_b(void) {int r=TOUCHPANEL_GetTrg();if(r)UI_SetInputMode(1);return r;}

void POKETRADE_PROC_StepShowWaitMessageA(char *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  if(poll_a() || poll_b()) {
   POKETRADE_SAVE_CloseMessageWindowClear(p);
   if(POKETRADE_PROC_IsNetSession(p)) {
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),50,(void *)(((TradeWork *)p)->messageText));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitMessageThenClear);
   } else POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetGrid);
  }
 }
}

void POKETRADE_PROC_StepSendContinue(void *p) {
 unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   b=2;
   if(GFL_NET_SendToHandle((void *)id,0xc0f,1,&b)) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro);
  } else { POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepIntro); }
 }
}

void POKETRADE_PROC_StepSendStartRound(char *p) {
 u8 b;
 if(POKETRADE_PROC_IsNetSession(p)) {
  b=4;
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,&b)) {
   MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),136,(void *)(((TradeWork *)p)->messageText));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);
   GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendContinue);
  }
 } else {((TradeWork *)p)->request->state=3;POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);}
}

/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, short derives -1 from zero.
 */
/*
 * lever: the 0x1080 halfword is signed; u16 pools 0xffff, s16 derives -1 from zero.
 */
void POKETRADE_PROC_StepSummaryMenuChoice(char *p) {
 int v;
 if(APP_TASKMENU_IsFinish((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu))) {
  v=APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu));POKETRADE_SAVE_CloseTaskMenu(p);((TradeWork *)p)->taskMenu=0;
  switch(v) {
  case 0:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendStartRound);return;
  case 1:POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
   ((TradeWork *)p)->cursorRow=-1;POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,0);POKETRADE_2D_SetupSubBlend(p);return;
  }
 }
}

int POKETRADE_PROC_SendSideMon(char *p)
{
    int t=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((TradeWork *)p)->boxManager,((TradeWork *)p)->selectedBox,((TradeWork *)p)->selectedSlot,p);
    if(POKETRADE_PROC_IsNetSession(p)) {
        unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
        if(GFL_NET_SendToHandle((void *)id,(u16)0xc01,(u16)POKE_TOOL_GetPartyParamSize(),(void *)t)==0) {
            GFL_HEAP_Free((void *)t);
            return 0;
        }
    }
    POKETRADE_PROC_SetSideMon(p,0,(void *)t);
    GFL_HEAP_Free((void *)t);
    return 1;
}

void POKETRADE_PROC_StepOpenSummaryMenu(char *p)
{
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        Pair t=gSummaryMenuPos;
        POKETRADE_SAVE_OpenTaskMenuAt(p,(int *)(&t),2,0x20,0xc);
        ((TradeWork *)p)->cursorRow=-1;
        POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,0);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSummaryMenuChoice);
    }
}

void POKETRADE_PROC_StepShowSummaryMessage(char *p) {
 MSGDATA_ReadString((struct MsgBank *)((*(unsigned int *)&((TradeWork *)p)->messageBank)),0x8c,(void *)((*(unsigned int *)&((TradeWork *)p)->messageText)));
 POKETRADE_SAVE_OpenMessageWindowTop(p);
 ((TradeWork *)p)->redrawFlag=1;
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenSummaryMenu);
}

void POKETRADE_PROC_StepSlideInSubScreen(void *p) {
 G2x_SetBlendBrightness_((u32)((void *)0x04001050),27,-8);
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepShowSummaryMessage);
}

int POKETRADE_PROC_FindMatchingBoxIcon(char *p,int kind)
{
    int index=POKETRADE_2D_GetScrollColumn(p);
    int outer;
    for(outer=0;outer<((TradeWork *)p)->slotCount;outer++) {
        int inner;
        index++;
        if(index>=((TradeWork *)p)->slotCount) index=0;
        for(inner=0;inner<5;inner++) {
            int a=POKETRADE_PROC_GetBoxIndexForSlot(index,p);
            int b=POKETRADE_PROC_GetSlotIndexInBox(index,inner);
            int obj=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager),a,b,p);
            if(obj && POKETRADE_2D_IsBoxIconMatch(POKE_TOOL_GetBoxValue((void *)obj,0xab,0),kind) && !POKE_TOOL_GetBoxValue((void *)obj,0x4c,0)) {
                ((TradeWork *)p)->cursorRow+=1;
                ((TradeWork *)p)->scrollX=POKETRADE_PROC_GetSlotPosition(index)-0x20;
                ((TradeWork *)p)->redrawNeeded=1;
                POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
                return 1;
            }
        }
    }
    return 0;
}

void POKETRADE_PROC_StepCloseSubScreenDone(void *p) {
 BG_SYS_SetSubVisiblePlanes(30);
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
}

/*
 * volatile: hardware read/write at 021DB2AA/021DB2AE
 */
void POKETRADE_PROC_StepExitSubScreen(void *p)
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
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepCloseSubScreenDone);
}

void POKETRADE_PROC_StepWaitCursorFade(void *p) {
 if(POKETRADE_2D_ClearCursorIfDisabled(p)==0) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepExitSubScreen);
}

/*
 * lever: non-const table keeps reads after the p+0x800 store (const: 16 bytes differ).
 * volatile: hardware read/write at 021DB358/021DB35C and 021DB3C6/021DB3CA.
 * prototype: 02035C08 returns the live r0 result of 02035BBC (full original
 * 02035BBC and matched forwarder read); caller uses it despite void header.
 */
void POKETRADE_PROC_StepSubScreenList(char *p)
{
    int index;
    BG_SYS_SetSubVisiblePlanes(31);
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        index=TOUCHPANEL_HitTrg(gSubScreenHitAreas);
        if(index!=-1) {
            (*(unsigned int *)&((TradeWork *)p)->filterIndex)=(u32)index+1u;
            POKETRADE_2D_CreateCursorActor(p,gSubScreenHitAreas[index].c,gSubScreenHitAreas[index].a);
            if(POKETRADE_PROC_FindMatchingBoxIcon(p,index)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                *(volatile u32 *)0x04001000 &= 0xffff1fff;
                POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitCursorFade);
                return;
            }
            MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),0x34,(void *)(((TradeWork *)p)->messageText));
            POKETRADE_SAVE_OpenMessageWindow(p,1,1,1,0x1d,4);
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
        TOUCHBAR_Update((*(void * *)&((TradeWork *)p)->touchbar));
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->touchbar)==1) {
            BG_SYS_SetSubVisiblePlanes(0x1a);
            ((TradeWork *)p)->filterIndex=0;
            POKETRADE_2D_ClearSubScreen(p);
            POKETRADE_SAVE_CloseMessageWindowClear(p);
            *(volatile u32 *)0x04001000 &= 0xffff1fff;
            POKETRADE_NEGO_SetOfferMarkersState(p,1);
            POKETRADE_2D_FadePaletteAll(p,0);
            POKETRADE_PROC_UpdateTouchbarButtons(p);
            POKETRADE_2D_SetupSubBlend(p);
            POKETRADE_2D_DeleteCursorActor(p);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepExitSubScreen);
        }
    }
}

void POKETRADE_PROC_StepOpenSubScreen(char *p)
{
    POKETRADE_2D_LoadSubScreenGfx(p);
    MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank),0x33,(void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindow(p,1,1,1,0x1d,4);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSubScreenList);
}

void POKETRADE_PROC_StepBeginOpenSubScreen(char *p)
{
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),7,0);
    POKETRADE_NEGO_SetOfferMarkersState(p,0);
    G2x_SetBlendBrightness_((u32)((void *)0x04001050),10,-8);
    POKETRADE_2D_FadePaletteAll(p,1);
    if(POKETRADE_NEGO_HasOffer(p))
        TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),8,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenSubScreen);
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

int POKETRADE_PROC_IsSlotVisible(char *p, int index)
{
    int position = POKETRADE_PROC_GetSlotPosition(index);
    int start = ((TradeWork *)p)->scrollX;
    if (start < position && start + 0xe0 > position)
        return 1;
    position += ((TradeWork *)p)->gridOriginX;
    if (start < position && start + 0xe0 > position)
        return 1;
    return 0;
}

void POKETRADE_PROC_PollGridKeys(char *p)
{
    int changed = 0;
    int i, v;
    unsigned int k = KEY_GetRepeat();
    if (((TradeWork *)p)->dragActor != 0)
        return;
    if (k & 0x100) {
        UI_SetInputMode(0);
        for (i = 0; i < ((TradeWork *)p)->partyBoxId + 1; i++) {
            if (gScrollSnapPos[i] > ((TradeWork *)p)->scrollX) {
                ((TradeWork *)p)->scrollX = gScrollSnapPos[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((TradeWork *)p)->scrollX = gScrollSnapPos[0];
        }
        POKETRADE_PROC_ClampScrollColumn(p, changed);
    } else if (k & 0x200) {
        UI_SetInputMode(0);
        for (i = ((TradeWork *)p)->partyBoxId; i >= 0; i--) {
            if (gScrollSnapPos[i] < ((TradeWork *)p)->scrollX) {
                ((TradeWork *)p)->scrollX = gScrollSnapPos[i];
                changed = 1;
                break;
            }
        }
        if (!changed) {
            changed = 1;
            ((TradeWork *)p)->scrollX = gScrollSnapPos[((TradeWork *)p)->partyBoxId];
        }
        POKETRADE_PROC_ClampScrollColumn(p, changed);
    } else if (KEY_GetRepeat() == 0x40) {
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0)
            ((TradeWork *)p)->cursorSlot = v;
        if (--((TradeWork *)p)->cursorColumn < 0) {
            if (((TradeWork *)p)->cursorSlot < 2)
                ((TradeWork *)p)->cursorColumn = 2;
            else
                ((TradeWork *)p)->cursorColumn = 4;
        }
        ((TradeWork *)p)->cursorRow = ((TradeWork *)p)->cursorRow - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x80) {
        int x;
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0)
            ((TradeWork *)p)->cursorSlot = v;
        x = ++((TradeWork *)p)->cursorColumn;
        if (((TradeWork *)p)->cursorSlot < 2) {
            if (x >= 3)
                ((TradeWork *)p)->cursorColumn = 0;
        } else if (x >= 5)
            ((TradeWork *)p)->cursorColumn = 0;
        ((TradeWork *)p)->cursorRow = ((TradeWork *)p)->cursorRow - 1;
        changed = 1;
    } else if (KEY_GetRepeat() == 0x10) {
        UI_SetInputMode(0);
        ((TradeWork *)p)->cursorRow = ((TradeWork *)p)->cursorRow - 1;
        changed = 1;
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0) {
            ((TradeWork *)p)->cursorSlot = v;
        } else {
            ((TradeWork *)p)->cursorSlot = ((TradeWork *)p)->cursorSlot + 1;
            if (POKETRADE_PROC_IsSlotVisible(p, ((TradeWork *)p)->cursorSlot) == 0) {
                ((TradeWork *)p)->scrollX = POKETRADE_PROC_GetSlotPosition(((TradeWork *)p)->cursorSlot + 1) - 0x100;
                ((TradeWork *)p)->cursorRow = -1;
            }
        }
        if (((TradeWork *)p)->cursorSlot >= ((TradeWork *)p)->slotCount)
            ((TradeWork *)p)->cursorSlot = 0;
        if (((TradeWork *)p)->cursorSlot < 2 && ((TradeWork *)p)->cursorColumn >= 3)
            ((TradeWork *)p)->cursorColumn = 2;
    } else if (KEY_GetRepeat() == 0x20) {
        UI_SetInputMode(0);
        ((TradeWork *)p)->cursorRow = ((TradeWork *)p)->cursorRow + 1;
        changed = 1;
        if (POKETRADE_2D_GetVisibleColumnRange(p, &v) == 0) {
            ((TradeWork *)p)->cursorSlot = v;
        } else {
            ((TradeWork *)p)->cursorSlot = ((TradeWork *)p)->cursorSlot - 1;
            if (((TradeWork *)p)->cursorSlot < 0)
                ((TradeWork *)p)->cursorSlot = ((TradeWork *)p)->slotCount - 1;
            if (POKETRADE_PROC_IsSlotVisible(p, ((TradeWork *)p)->cursorSlot) == 0) {
                ((TradeWork *)p)->scrollX = POKETRADE_PROC_GetSlotPosition(((TradeWork *)p)->cursorSlot);
                ((TradeWork *)p)->cursorRow = -1;
            }
        }
        if (((TradeWork *)p)->cursorSlot < 0)
            ((TradeWork *)p)->cursorSlot = ((TradeWork *)p)->slotCount - 1;
        if (((TradeWork *)p)->cursorSlot < 2 && ((TradeWork *)p)->cursorColumn >= 3)
            ((TradeWork *)p)->cursorColumn = 2;
    }
    if (changed) {
        ((TradeWork *)p)->redrawNeeded = 1;
        GFL_USE_PlaySeDefaultVolume(0x548);
        POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 1);
    }
}

void POKETRADE_PROC_RedrawAndSyncGrid(char *p,int a,int b)
{
    if(((TradeWork *)p)->scrollX<0) ((TradeWork *)p)->scrollX+=(short)((TradeWork *)p)->gridOriginX;
    if(((TradeWork *)p)->gridOriginX<=((TradeWork *)p)->scrollX) ((TradeWork *)p)->scrollX-=(short)((TradeWork *)p)->gridOriginX;
    POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,1);
    POKETRADE_2D_DrawBoxGridScreen(p);
    POKETRADE_2D_DrawBoxNames(p);
    if(GFL_USE_IsAnySeBusy()==0 && a) GFL_USE_PlaySeDefaultVolume(0x72b);
    if(POKETRADE_PROC_IsNetSession(p) && b) {
        if(GFL_NET_IsNetTypeWifi()) {
            if(((TradeWork *)p)->scrollX%16==0) {
                (struct GFLNetHandle *)(void *)GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(void *)(p+0x107c),0,1,1);
                return;
            }
        } else {
            (struct GFLNetHandle *)(void *)GFL_NET_SendData((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),255,0xc0c,2,(void *)(p+0x107c),0,1,1);
            return;
        }
    } else {
        if(POKETRADE_PROC_IsNetSession(p)==0) ((TradeWork *)p)->scrollY=((TradeWork *)p)->scrollX;
    }
}

void POKETRADE_PROC_DragScrollGrid(char *p)
{
    int x,y,i;
    if(((TradeWork *)p)->dragActor) return;
    if(TOUCHPANEL_GetPointCont((u32 *)(&x),(u32 *)(&y))) {
        if(((TradeWork *)p)->dragging) {
            if((unsigned)x>=64 && (unsigned)x<192 && (unsigned)y>=168 && (unsigned)y<188) {
                int previous;
                CLACT_SetActorAutoAnim((struct Actor *)((TradeWork *)p)->cursorActor,1);
                previous=((TradeWork *)p)->dragX;
                ((TradeWork *)p)->dragVelocity=(x-previous)*2;
                ((TradeWork *)p)->dragX=x;
                ((TradeWork *)p)->scrollX-=((TradeWork *)p)->dragVelocity;
                if(((TradeWork *)p)->dragVelocity>12) POKETRADE_PROC_RedrawAndSyncGrid(p,1,1);
                else POKETRADE_PROC_RedrawAndSyncGrid(p,0,1);
            } else ((TradeWork *)p)->dragVelocity=0;
        }
        ((TradeWork *)p)->dragX=x;
    } else ((TradeWork *)p)->dragX=0;
    if(TOUCHPANEL_GetCont()==0 && ((TradeWork *)p)->dragVelocity!=0) {
        for(i=2;i!=0 && ((TradeWork *)p)->dragVelocity!=0;i--) {
            if(((TradeWork *)p)->dragVelocity<0) ((TradeWork *)p)->dragVelocity++;
            if(((TradeWork *)p)->dragVelocity>0) ((TradeWork *)p)->dragVelocity--;
        }
        ((TradeWork *)p)->scrollX-=((TradeWork *)p)->dragVelocity;
        POKETRADE_PROC_RedrawAndSyncGrid(p,1,1);
    }
}

void POKETRADE_PROC_StepWaitBrowseRelease(char *p)
{
    if (TOUCHPANEL_GetCont() == 0)
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBrowseGrid);
}

void POKETRADE_PROC_StepClearPeerSelection(char *p)
{
    POKETRADE_NEGO_FindOfferIndex(p,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot);
    if(POKETRADE_PROC_IsNetSession(p)) {
        if(!GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)) return;
    }
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),8,0);
    ((TradeWork *)p)->selectedSlot=-1;
    ((TradeWork *)p)->selectedBox=-1;
    ((TradeWork *)p)->highlightSlot=-1;
    ((TradeWork *)p)->highlightBox=-1;
    ((TradeWork *)p)->peerSelectedSlot=-1;
    ((TradeWork *)p)->peerSelectedBox=-1;
    POKETRADE_PROC_ClearSideMon(p,0);
    POKETRADE_PROC_RequestBoxRedraw(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitBrowseRelease);
}

void POKETRADE_PROC_StepBeginBrowse(void *p)
{
    if (POKETRADE_PROC_IsNetSession(p)==0) {
        POKETRADE_PROC_ClearSideMon(p,1);
        POKETRADE_PROC_StepNone(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepEnterBrowsing);
        return;
    }
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)!=0)
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepEnterBrowsing);
}

void POKETRADE_PROC_StepResetGrid(char *p)
{
    ((TradeWork *)p)->dragging=0;
    ((TradeWork *)p)->dragX=0;
    ((TradeWork *)p)->dragVelocity=0;
    MI_CpuFill8(p+0xca0,0,0x78);
    MI_CpuFill8(p+0xd18,0,0x3c);
    MI_CpuFill8(p+0xd54,0,0x3c);
    POKETRADE_PROC_ShowDragIcon(p);
    POKETRADE_NEGO_SetOfferMarkersState(p,1);
    if(((TradeWork *)p)->taskMenu) {
        APP_TASKMENU_CloseMenu((struct TaskMenuWork *)(((TradeWork *)p)->taskMenu));
        ((TradeWork *)p)->taskMenu=0;
    }
    POKETRADE_PROC_ClearSideMon(p,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginBrowse);
}

void POKETRADE_PROC_StepEnterBrowsing(char *p)
{
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),8,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),7,1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),9,0);
    POKETRADE_PROC_ResetTouchbarBackButton(p);
    CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->cursorActor,1);
    POKETRADE_2D_CreateBoxWindows(p);
    POKETRADE_2D_SetupSubBlend(p);
    ((TradeWork *)p)->selectedSlot=-1;
    ((TradeWork *)p)->selectedBox=-1;
    POKETRADE_PROC_RequestBoxRedraw(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
}











void POKETRADE_PROC_UpdateTouchbarButtons(char *p)
{
    CLACT_SetActorDrawEnable((struct Actor *)((TradeWork *)p)->cursorActor,1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),8,POKETRADE_NEGO_HasOffer(p));
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),8,POKETRADE_NEGO_HasOffer(p));
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(((TradeWork *)p)->touchbar),7,1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),9,0);
    POKETRADE_PROC_ResetTouchbarBackButton(p);
    POKETRADE_PROC_RequestBoxRedraw(p);
}

void POKETRADE_PROC_StepRebuildBrowseScene(char *p) { POKETRADE_NEGO_SetOfferMarkersState(p,1); MI_CpuFill8(p+0xca0,0,0x78); MI_CpuFill8(p+0xd18,0,0x3c); MI_CpuFill8(p+0xd54,0,0x3c); POKETRADE_PROC_ShowDragIcon(p); if(((TradeWork *)p)->taskMenu) {APP_TASKMENU_CloseMenu((struct TaskMenuWork *)((TradeWork *)p)->taskMenu); ((TradeWork *)p)->taskMenu=0;} POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_UpdateTouchbarButtons(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);}

void POKETRADE_PROC_StepConfirmSendOffer(char *p) {
 if(POKETRADE_PROC_IsHostSide(p)) { if(POKETRADE_NEGO_AddSelectedAsOffer(p,((TradeWork *)p)->selectedSlot,((TradeWork *)p)->selectedBox)==0) return; }
 else { if(POKETRADE_PROC_SendSideMon(p)==0) return; }
 ((TradeWork *)p)->peerSelectedBox=-1; ((TradeWork *)p)->peerSelectedSlot=-1;
 ((TradeWork *)p)->highlightSlot=-1; ((TradeWork *)p)->highlightBox=-1;
 POKETRADE_PROC_RequestBoxRedraw(p); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
}

void POKETRADE_PROC_StepSendOfferConfirm(char *p) {int same=0;if(((TradeWork *)p)->selectedBox==((TradeWork *)p)->partyBoxId)same=1;if(POKETRADE_PROC_IsHostSide(p)) {int n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,((TradeWork *)p)->selectedSlot,((TradeWork *)p)->selectedBox);if(n!=-1) {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),n+0xc13,1,&same)) {POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepConfirmSendOffer);return;}} else {POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepConfirmSendOffer);return;}} else {if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc16,1,&same))POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepConfirmSendOffer);}}

void POKETRADE_PROC_StepWaitIconFlight(char *p)
{
    if (POKETRADE_2D_UpdateIconFlight(p)) {
        if (POKETRADE_PROC_IsNetSession(p)) {
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepSendOfferConfirm);
            return;
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepConfirmSendOffer);
    }
}

int POKETRADE_PROC_IsTradeTargetValid(char *p,int a,int b) {
 if(POKETRADE_PROC_IsHostSide(p)==0) {
  if(((TradeWork *)p)->selectedSlot==b && ((TradeWork *)p)->selectedBox==a) return 1;
 } else { if(POKETRADE_NEGO_FindOfferIndex(p,a,b)!=-1) return 1; }
 return 0;
}

int POKETRADE_PROC_StepPeerSelectAction(char *p) {int e=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager),((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot,p);if(POKETRADE_PROC_IsTradeTargetValid(p,((TradeWork *)p)->peerSelectedBox,((TradeWork *)p)->peerSelectedSlot)) {GFL_USE_PlaySeDefaultVolume(0x626);if(POKETRADE_PROC_IsHostSide(p)==0){POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepClearPeerSelection);return 1;}POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendOfferRemoval);return 1;}if(e && POKE_TOOL_GetBoxValue((void *)e,0xa9,0)) {GFL_USE_PlaySeDefaultVolume(0x54b);TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar), 8, 0);POKETRADE_SAVE_CloseTaskMenu(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenPeerSummary);return 1;}POKETRADE_PROC_ShowDragIcon(p);((TradeWork *)p)->peerSelectedBox=-1;((TradeWork *)p)->peerSelectedSlot=-1;return 0;}

/*
 * The bound block after POKETRADE_2D_GetScrollColumn closes only with its six locals
 * declared without initialisers and assigned afterwards; about a fifth of
 * the declaration orders then match (docs/notes/pkt_ov119_021DBE70.c.txt).
 */
void POKETRADE_PROC_StepBrowseGrid(char *p)
{
    int n;
    int e;
    p[0x11EA] = 1;
    if (TOUCHPANEL_GetCont()) {
        UI_SetInputMode(1);
        if (KEY_GetCont())
            return;
    }
    if (UI_GetInputMode() && poll_a()) {
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &n) == 0) {
            int v = n;
            ((TradeWork *)p)->cursorSlot = v;
            if (v < 2 && ((TradeWork *)p)->cursorColumn >= 3)
                ((TradeWork *)p)->cursorColumn = 2;
        } else if (POKETRADE_PROC_IsSlotVisible(p, ((TradeWork *)p)->cursorSlot) == 0) {
            int end;
            int a;
            int t;
            int cur;
            int b;
            int lim;
            t = POKETRADE_2D_GetScrollColumn(p);
            cur = ((TradeWork *)p)->cursorSlot;
            a = t + 5;
            b = t + 10;
            lim = ((TradeWork *)p)->slotCount;
            end = cur;
            if (b >= lim && cur < 0x14)
                end = cur + (lim + 1);
            if (a < end)
                ((TradeWork *)p)->scrollX = POKETRADE_PROC_GetSlotPosition(cur + 1) - 0x100;
            else
                ((TradeWork *)p)->scrollX = POKETRADE_PROC_GetSlotPosition(cur);
            ((TradeWork *)p)->cursorRow = -1;
            ((TradeWork *)p)->redrawNeeded = 1;
            POKETRADE_PROC_RedrawAndSyncGrid(p, 0, 1);
            ((TradeWork *)p)->dragVelocity = 0;
            return;
        }
        POKETRADE_PROC_RequestBoxRedraw(p);
        ((TradeWork *)p)->dragVelocity = 0;
        return;
    }
    if (poll_a() || poll_b())
        ((TradeWork *)p)->dragVelocity = 0;
    if (poll_b()) {
        POKETRADE_PROC_ShowDragIcon(p);
        ((TradeWork *)p)->peerSelectedBox = -1;
        ((TradeWork *)p)->peerSelectedSlot = -1;
    }
    POKETRADE_PROC_UpdateDragState(p);
    POKETRADE_PROC_UpdateDragIcon(p);
    POKETRADE_PROC_PollGridKeys(p);
    POKETRADE_NEGO_PollMarkerTouch(p);
    if (poll_a() == 1) {
        UI_SetInputMode(0);
        if (POKETRADE_2D_GetVisibleColumnRange(p, &n) == 0) {
            int v = n;
            ((TradeWork *)p)->cursorSlot = v;
            if (v < 2) {
                if (((TradeWork *)p)->cursorColumn >= 3)
                    ((TradeWork *)p)->cursorColumn = 0;
            } else if (((TradeWork *)p)->cursorColumn >= 5)
                ((TradeWork *)p)->cursorColumn = 0;
        }
        e = (int)POKETRADE_PROC_LoadSlotMonAlt((void *)((TradeWork *)p)->boxManager, POKETRADE_PROC_GetBoxIndexForSlot(((TradeWork *)p)->cursorSlot, p), POKETRADE_PROC_GetSlotIndexInBox(((TradeWork *)p)->cursorSlot, ((TradeWork *)p)->cursorColumn), p);
        if (e && POKE_TOOL_GetBoxValue((void *)e, 0xA9, 0)) {
            if (POKETRADE_PROC_CanTradeMon(p, e)) {
                MSGDATA_ReadString((struct MsgBank *)((TradeWork *)p)->messageBank, 0x8E, (void *)((TradeWork *)p)->messageText);
                POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
                POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitKeyAfterMessage);
                return;
            }
            ((TradeWork *)p)->peerSelectedBox = POKETRADE_PROC_GetBoxIndexForSlot(((TradeWork *)p)->cursorSlot, p);
            ((TradeWork *)p)->peerSelectedSlot = POKETRADE_PROC_GetSlotIndexInBox(((TradeWork *)p)->cursorSlot, ((TradeWork *)p)->cursorColumn);
            UI_SetInputMode(0);
            if (POKETRADE_PROC_IsHostSide(p) && POKETRADE_NEGO_FindOfferIndex(p, ((TradeWork *)p)->peerSelectedBox, ((TradeWork *)p)->peerSelectedSlot) != -1) {
                GFL_USE_PlaySeDefaultVolume(0x626);
                POKETRADE_PROC_SetStep(p, (int)POKETRADE_NEGO_StepSendOfferRemoval);
                return;
            }
            POKETRADE_PROC_LoadSlotMonAlt((void *)((TradeWork *)p)->boxManager, ((TradeWork *)p)->peerSelectedBox, ((TradeWork *)p)->peerSelectedSlot, p);
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
        ((TradeWork *)p)->dragHold = 1;
    default:
        if (!TOUCHPANEL_GetCont()) {
            if (((TradeWork *)p)->dragging && ((TradeWork *)p)->dragMoved && ((TradeWork *)p)->dragActor) {
                ((TradeWork *)p)->dragging = 0;
                ((TradeWork *)p)->dragMoved = 0;
                if (POKETRADE_PROC_IsSelectedOfferSlot(p, ((TradeWork *)p)->highlightBox, ((TradeWork *)p)->highlightSlot)) {
                    ((TradeWork *)p)->highlightBox = -1;
                    ((TradeWork *)p)->highlightSlot = -1;
                    POKETRADE_PROC_ClearDragIcon(p);
                    POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_ShowCancelMessage);
                    return;
                }
                ((TradeWork *)p)->peerSelectedBox = ((TradeWork *)p)->highlightBox;
                ((TradeWork *)p)->peerSelectedSlot = ((TradeWork *)p)->highlightSlot;
                ((TradeWork *)p)->selectedSlot = ((TradeWork *)p)->highlightSlot;
                ((TradeWork *)p)->selectedBox = ((TradeWork *)p)->highlightBox;
                ((TradeWork *)p)->dragActor = 0;
                TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar, 8, 1);
                TOUCHBAR_SetButtonEnabled((unsigned char *)((TradeWork *)p)->touchbar, 8, 1);
                POKETRADE_2D_StartIconFlight(p);
                GFL_USE_PlaySeDefaultVolume(0x72A);
                POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepWaitIconFlight);
                return;
            }
            if (((TradeWork *)p)->dragging && ((TradeWork *)p)->dragActor && ((TradeWork *)p)->dragHold) {
                ((TradeWork *)p)->peerSelectedBox = ((TradeWork *)p)->highlightBox;
                ((TradeWork *)p)->peerSelectedSlot = ((TradeWork *)p)->highlightSlot;
                POKETRADE_PROC_StepPeerSelectAction(p);
                return;
            }
            if (((TradeWork *)p)->highlightSlot != -1 && ((TradeWork *)p)->highlightBox != -1) {
                POKETRADE_PROC_ShowDragIcon(p);
                POKETRADE_PROC_RequestBoxRedraw(p);
            } else {
                POKETRADE_PROC_ShowDragIcon(p);
            }
            ((TradeWork *)p)->dragging = 0;
            ((TradeWork *)p)->dragMoved = 0;
            CLACT_SetActorAutoAnim((struct Actor *)((TradeWork *)p)->cursorActor, 0);
        }
        POKETRADE_PROC_DragScrollGrid(p);
        if (TOUCHPANEL_GetCont())
            ((TradeWork *)p)->dragging = 1;
        TOUCHBAR_Update((unsigned char *)((TradeWork *)p)->touchbar);
        switch (TOUCHBAR_GetPressedButtonIdIfPressing((u8 *)((TradeWork *)p)->touchbar)) {
        case 1:
        case 7:
        case 8:
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepTouchbarAction);
            break;
        }
        break;
    }
}













void POKETRADE_PROC_StepTouchbarAction(char *p){TOUCHBAR_Update((unsigned char *)(((TradeWork *)p)->touchbar));switch(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((TradeWork *)p)->touchbar)) {case 1:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSlideInSubScreen);return;case 7:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginOpenSubScreen);return;case 8:if(POKETRADE_PROC_IsHostSide(p)){if(POKETRADE_NEGO_HasOffer(p)){TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,7,0);TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,8,0);POKETRADE_PROC_ClearDragIcon(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowCancelMessage);return;}else{TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,7,1);TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,8,0);}}else{if(((TradeWork *)p)->selectedSlot==-1){TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,7,1);TOUCHBAR_SetButtonVisible((unsigned char *)((TradeWork *)p)->touchbar,8,0);}else{POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_HideTouchbarButtons);return;}}POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);return;}}

void POKETRADE_PROC_StepWaitKeyThenBrowse(char *p) {int hit=0;if(POKETRADE_SAVE_IsMessagePrintDone(p)) {if(poll_a()) {UI_SetInputMode(0);hit=1;}if(poll_b()){hit=1;UI_SetInputMode(1);}if(hit){POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);((TradeWork *)p)->cursorRow=-1;POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,1);}}}

void POKETRADE_PROC_InitMcssSystem(char *p)
{
    POKETRADE_2D_InitG3DSystem(p);
    ((TradeWork *)p)->mcssSystem = MCSS_Init(4, (((TradeWork *)p)->heapId & 0x7FFF) | 0x8000);
    MCSS_SetTextureTransAdrs(((TradeWork *)p)->mcssSystem, 3 << 16);
    MCSS_SetOrthoMode(((TradeWork *)p)->mcssSystem);
}

void POKETRADE_PROC_ExitMcssSystem(char *p)
{
    POKETRADE_3D_DeleteMcssSlot(p, 0);
    POKETRADE_3D_DeleteMcssSlot(p, 1);
    MCSS_Exit(((TradeWork *)p)->mcssSystem);
    ((TradeWork *)p)->mcssSystem = 0;
    G3D_CAMERA_Delete((*(void * *)&((TradeWork *)p)->camera));
    G3D_SYSTEM_Exit();
}

void POKETRADE_PROC_InitDisplay(char *p)
{
    BG_SYS_Create(0x91);
    BMP_WIN_Init(((TradeWork *)p)->heapId);
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

void POKETRADE_PROC_LoadSceneResources(char *p) {POKETRADE_2D_RegisterIconCharResources(p);ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,((TradeWork *)p)->heapId);POKETRADE_NEGO_ExitMarkers(p);if(((TradeWork *)p)->tradeState<4)POKETRADE_2D_RegisterIconSpriteResources(p);POKETRADE_2D_CreateBoxIconActors(p);POKETRADE_2D_LoadMainGfxAndMessageWindow(p);POKETRADE_2D_LoadBackgroundGfx(p);POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_UpdateVisibleColumns(((TradeWork *)p)->boxManager,p,0);}

void POKETRADE_PROC_VBlank(int a, char *p)
{
    CLACT_VBlankSystem();
    if (((TradeWork *)p)->redrawNeeded) {
        BG_SYS_ChangeScrollImmediate(7, 0, ((TradeWork *)p)->scrollSub);
        BG_SYS_ChangeScrollImmediate(5, 0, ((TradeWork *)p)->scrollSub);
        ((TradeWork *)p)->redrawNeeded = 0;
    }
}

void POKETRADE_PROC_SetupGameData(char *p,void *q,u16 r) {unsigned i;for(i=0;i<3;i++)*(int *)(p+0x1064+i*4)=(int)GFL_HEAP_Alloc(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,0xfde);if(q){((TradeWork *)p)->gameData=q;((TradeWork *)p)->boxManager=GAME_DATA_GetBoxManager(q);((TradeWork *)p)->trainerRecord=(int)GAME_DATA_GetMyStatus(q);((TradeWork *)p)->partyData=GAME_DATA_GetMyParty(q);if(((TradeWork *)p)->playerStatus==0){if(POKETRADE_PROC_IsNetSession(p)){((TradeWork *)p)->playerStatus=(int)GAME_DATA_GetMyStatusPlayer(q,1-GFL_NET_SYSTEM_GetCurrentAid());return;}((TradeWork *)p)->playerStatus=(int)GAME_DATA_GetMyStatusPlayer(q,1);}}}

void POKETRADE_PROC_FreeMons(char *p, int unused)
{
    unsigned i;
    for (i = 0; i < 3; i++)
        GFL_HEAP_Free((void *)(*(int *)(p + i * 4 + 0x1064)));
}

void POKETRADE_PROC_SetupBoxCounts(char *p)
{
    int v = BOX_SAVEDATA_GetUsableBoxCount((void *)(((TradeWork *)p)->boxManager));
    ((TradeWork *)p)->slotCount = v * 6 + 2;
    ((TradeWork *)p)->partyBoxId = v;
    ((TradeWork *)p)->columnWrap = v * 0x14 + 0xC;
    ((TradeWork *)p)->gridOriginX = v * 0xA0 + 0x60;
}

/*
 * lever: output pointer declared before scalar locals; counter zero before base assignment.
 * arithmetic: signed n guard/callee argument; unsigned base/index preserve low-word MUL/ADD wrapping at 021DC6A6/021DC6A8/021DC6B2.
 */
void POKETRADE_PROC_BuildTradeRecords(char *p,int n)
{
    Record *out=(Record *)(p+0x11fc);
    int i,mon,v;
    unsigned index,base;
    if(n==0) {
        MI_CpuFill8(out,0,0xb58);
        for(i=0;i<6;i++) {
            mon=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager),((TradeWork *)p)->partyBoxId,i,p);
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
            mon=(int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager),n,i,p);
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
void POKETRADE_PROC_DeleteAllResources(char *p)
{
    int i;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    POKETRADE_2D_DeleteAllOfferIconActors(p);POKETRADE_3D_RemoveCurrentUnit(p);POKETRADE_NEGO_ReleaseIconResources(p);POKETRADE_NEGO_ResetMarkers(p);POKETRADE_NEGO_DeleteHeaderWindows((unsigned char *)p);POKETRADE_2D_DeleteBoxWindows(p);
    POKETRADE_3D_DeleteMcssSlot(p,1);POKETRADE_2D_DeletePickedIconActor(p);POKETRADE_NEGO_UpdateOfferMarkers(p);POKETRADE_SAVE_DeleteOfferListWindows(p);POKETRADE_2D_DeleteAllBoxIcons(p);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,0);POKETRADE_SAVE_DeleteOfferCardWindow(p,1);
    if(((TradeWork *)p)->touchbar) {TOUCHBAR_Delete(((TradeWork *)p)->touchbar);((TradeWork *)p)->touchbar=0;}
    POKETRADE_2D_DeleteOfferIcons(p);
    if(((TradeWork *)p)->clactSystem) {CLACT_DeleteUnit((void *)((TradeWork *)p)->clactSystem);((TradeWork *)p)->clactSystem=0;}
    POKETRADE_SAVE_DeleteMessageResources(p);POKETRADE_NEGO_FreeOfferMons(p);
    POKETRADE_SAVE_DeletePartnerOfferCard(p,0);POKETRADE_SAVE_DeletePartnerOfferCard(p,1);POKETRADE_2D_FreeBackgroundPalette(p);POKETRADE_2D_FreeMainResources(p);POKETRADE_2D_ExitSubBgs(p);
    if(((TradeWork *)p)->gfxWorkBuf) {GFL_HEAP_Free(((TradeWork *)p)->gfxWorkBuf);((TradeWork *)p)->gfxWorkBuf=0;}
    for(i=0;i<4;i++) {
        char *q=p+i*4;
        if(((TradeWork *)q)->sceneBuf) {GFL_HEAP_Free(((TradeWork *)q)->sceneBuf);((TradeWork *)q)->sceneBuf=0;}
    }
}

void POKETRADE_PROC_ExitBgm(char *p)
{
    switch (((TradeWork *)p)->sceneState) {
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
    ((TradeWork *)p)->sceneState = 0;
}

void *POKETRADE_PROC_AllocTradeWork(void *a,int t) {
 void *p;
 GFL_HEAP_RegisterBlockHeap(gTradeWorkHeapName,0xc000,0x91);
 GFL_HEAP_CreateChildHeap(1,31,t);
 p=PROCSYS_AllocProcWork(a,0x1d54,0x91);
 MI_CpuFill8(p,0,0x1d54);
 return p;
}

int POKETRADE_PROC_InitTradeWork(void *a,int b,char *q,char *p,int n)
{
    if(n<5) {GF_OVERLAY_Load((int)ov067_id);GF_OVERLAY_Load((int)ov114_id);}
    if(n==0 || n==4) GF_OVERLAY_Load((int)ov117_id);
    else GF_OVERLAY_Load((int)ov118_id);
    BG_SYS_SetLcdSwap(1);
    ((TradeWork *)p)->heapId=31;
    ((TradeWork *)p)->tradeState=n;
    ((TradeWork *)p)->request=(struct TradeRequest *)q;
    ((TradeWork *)p)->monABuf=GFL_HEAP_Alloc(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,0x110b);
    ((TradeWork *)p)->monBBuf=GFL_HEAP_Alloc(0x91,POKE_TOOL_GetPartyParamSize(),1,gGameDataAllocTag,0x110c);
    ((TradeWork *)p)->subObjPaletteCopy=GFL_HEAP_Alloc(0x91,512,0,gGameDataAllocTag,0x110d);
    ((TradeWork *)p)->subBgPaletteCopy=GFL_HEAP_Alloc(0x91,512,0,gGameDataAllocTag,0x110e);
    ((TradeWork *)p)->nationalDexEnabled=ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(((struct TradeRequest *)q)->gameData));
    if(q) POKETRADE_PROC_SetupGameData(p,((struct TradeRequest *)q)->gameData,((struct TradeRequest *)q)->setupParam);
    POKETRADE_PROC_SetupBoxCounts(p);POKETRADE_PROC_InitMcssSystem(p);POKETRADE_PROC_InitDisplay(p);
    ((TradeWork *)p)->clactSystem=(int)CLACT_CreateUnit(0x154,0,((TradeWork *)p)->heapId);
    if(POKETRADE_PROC_IsNetSession(p)) {
        GFL_NET_COMMAND_AddCommandTable(0xc00,(unsigned)gNetCommandTable,24,(unsigned)p);
        GFL_NET_SetAutoExit(1);GFL_NET_SetLoginOption(1);
    }
    ((TradeWork *)p)->nodeA=GFL_USE_AddMainTask((void (*)(void *, void *))POKETRADE_PROC_VBlank,p,0);
    ((TradeWork *)p)->dragActor=0;
    ((TradeWork *)p)->selectedSlot=-1;((TradeWork *)p)->animIndex=-1;((TradeWork *)p)->highlightSlot=-1;((TradeWork *)p)->highlightBox=-1;((TradeWork *)p)->peerSelectedBox=-1;((TradeWork *)p)->peerSelectedSlot=-1;
    POKETRADE_3D_Init3DScene(p);
    if(((struct TradeRequest *)q)->state==1) {
        BG_SYS_SetMainVisiblePlanes(16);POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepSaveCancelNotice);((struct TradeRequest *)q)->state=0;return 1;
    }
    POKETRADE_SAVE_CreateMessageResources(p);POKETRADE_2D_CreateFontResource(p);
    if(((TradeWork *)p)->tradeState<4) {POKETRADE_PROC_LoadSceneResources(p);POKETRADE_3D_CreateTouchbar(p);GFL_NET_RefreshWmIconAtTopRight(1,((TradeWork *)p)->heapId);}
    POKETRADE_3D_AddUnitAndInit(p,0);BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRestartNetSession);
    return 1;
}

/*
 * Send a two-descriptor request with the timer base 0xc6000.
 */
void POKETRADE_PROC_StartRequest2(void *a, int b, int c)
{
    int r = (int)POKETRADE_PROC_AllocTradeWork(a, 0xc6000);

    POKETRADE_PROC_InitTradeWork(a, b, (char *)c, (char *)r, 2);
}

/*
 * Send a one-descriptor request with the timer base 0xc6000.
 */
void POKETRADE_PROC_StartRequest0(void *a, int b, int c)
{
    int r = (int)POKETRADE_PROC_AllocTradeWork(a, 0xc6000);

    POKETRADE_PROC_InitTradeWork(a, b, (char *)c, (char *)r, 0);
}

void POKETRADE_PROC_StartRequest1(void *a,int b,char *c) {char *p=POKETRADE_PROC_AllocTradeWork(a,0xc6000);int i; for(i=0;i<2;i++) {char *d=p+i*4;((TradeWork *)d)->peerMsgIndex=0;((TradeWork *)d)->ownMsgIndex=1;} ((TradeWork *)p)->playerStatus=(int)GAME_DATA_GetMyStatusPlayer((void *)*(int *)&((struct TradeRequest *)c)->gameData,1-GFL_NET_SYSTEM_GetCurrentAid());POKETRADE_PROC_InitTradeWork(a,b,c,p,1);}

void POKETRADE_PROC_StartRequest3(void *a,int b,char *c) {const char *q=((struct TradeRequest *)c)->context;char *p=POKETRADE_PROC_AllocTradeWork(a,0xc6000);if(q) {if(((struct TradeContext *)q)->entryCount==2) {int i;for(i=0;i<2;i++) {const int *s=(const int *)(q+i*8);char *d=p+i*4;((TradeWork *)d)->peerMsgIndex=s[2];((TradeWork *)d)->ownMsgIndex=s[1];}} else {int j;for(j=0;j<2;j++){char *d=p+j*4;((TradeWork *)d)->peerMsgIndex=-1;((TradeWork *)d)->ownMsgIndex=-1;}}}POKETRADE_PROC_InitTradeWork(a,b,c,p,3);}

void POKETRADE_PROC_SetupMcssPokemon(char *a, char *p)
{
    MI_CpuCopy8(((struct TradeRequest *)a)->monA,((TradeWork *)p)->monABuf,POKE_TOOL_GetPartyParamSize());
    MI_CpuCopy8(((struct TradeRequest *)a)->monB,((TradeWork *)p)->monBBuf,POKE_TOOL_GetPartyParamSize());
    POKETRADE_3D_AddPokemonMcssPlain(p,0,1,((struct TradeRequest *)a)->monA,1);
    POKETRADE_3D_AddPokemonMcssPlain(p,1,1,((struct TradeRequest *)a)->monB,1);
    MCSS_SetVanishFlag((void *)(*(unsigned *)(p+(POKETRADE_PROC_IsHostSide(p) == 0 ? 0x848 : 0x844))));
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
    r = POKETRADE_PROC_InitTradeWork((void *)((int)a), b, c, p, 4);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_IRCDEMO_StepStartCompare);
    return r;
}

int POKETRADE_PROC_StartRequest7(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)((int)a), b, c, p, 7);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepStartDownScene);
    return r;
}

int POKETRADE_PROC_StartRequest8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)((int)a), b, c, p, 8);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepStartCompare);
    return r;
}

int POKETRADE_PROC_StartRequest6(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct TradeRequest *)c)->gameData = ((struct TradeRequest *)c)->gameDataSource;
    r = POKETRADE_PROC_InitTradeWork((void *)((int)a), b, c, p, 6);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_UP_StepStartCompare);
    return r;
}

int POKETRADE_PROC_Main(int a,int b,int c,char *p)
{
    int result=1;
    void (*callback)(char *)=*(void (**)(char *))(p+0x5ec);
    int i;
    u8 rgb[3];
    if(BEACON_STATUS_IsLocked()) return 0;
    if(callback) {
        callback(p);
        ((TradeWork *)p)->waitCounter++;
        result=0;
        for(i=0;i<2;i++) POKETRADE_NEGO_DrawOfferStatusLabel((u8 *)p,i,*(u8 *)(p+i+0x11e8),0);
    }
    if(((TradeWork *)p)->pendingSideMon && ((TradeWork *)p)->sideMonSent==0) {
        POKETRADE_PROC_SetSideMon(p,1,*(void **)(p+(((TradeWork *)p)->pendingSideMon-1)*4+0x5dc));((TradeWork *)p)->pendingSideMon=0;
    }
    POKETRADE_PROC_IncrementTimer(p);POKETRADE_NEGO_TickMarkerTimers(p);CLACT_DrawSystem();
    if(((TradeWork *)p)->taskMenu) APP_TASKMENU_UpdateMenu(((TradeWork *)p)->taskMenu);
    if(((TradeWork *)p)->taskMenuWindow) APP_TASKMENU_WIN_Update(((TradeWork *)p)->taskMenuWindow);
    if(((TradeWork *)p)->stateFlags.bits.replyPending) {
        if(GFL_NET_SendToHandle((struct Entry *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()),0xc17,0,0)) ((TradeWork *)p)->stateFlags.bits.replyPending=0;
    }
    if(((TradeWork *)p)->tcbl) {
        GF_FONT_GetTextColor(&rgb[2],&rgb[1],&rgb[0]);
        GF_FONT_SetTextColor(1,2,15);
        TCBL_Main(((TradeWork *)p)->tcbl);
        GF_FONT_SetTextColor(rgb[2],rgb[1],rgb[0]);
        PRINTSYS_QUE_Main(((TradeWork *)p)->printQueue);
    }
    POKETRADE_NEGO_TickOfferSlotTimers(p);G3D_SYSTEM_DrawStart();G3D_CAMERA_Reset((struct G3dCamera *)((TradeWork *)p)->camera);G3D_SYSTEM_ApplyLookAt();
    MCSS_Main(((TradeWork *)p)->mcssSystem);MCSS_Draw(((TradeWork *)p)->mcssSystem);POKETRADE_3D_Update3DScene(p);G3D_SYSTEM_DrawEnd();
    if(POKETRADE_PROC_IsNetSession(p) && ((TradeWork *)p)->netSave==0 && GFL_NET_ERR_GetErrorLevel()) {
        if(((TradeWork *)p)->wipeStarted) GFL_NET_ERR_HaltWithMessage(41);
        if(((TradeWork *)p)->httpRap) {
            NHTTP_RAP_DeleteConnection(((TradeWork *)p)->httpRap);NHTTP_RAP_Destroy(((TradeWork *)p)->httpRap);((TradeWork *)p)->httpRap=0;
            DWC_RAP_SetErrorCallback(0,0);DWC_RAPCOMMON_DestroySubHeap();
        }
        if(GFL_NET_IsNetTypeWifi()) DWC_RAPCOMMON_HandleNetError(1,1);
        else if(((TradeWork *)p)->tradeState!=1) GFL_NET_ERR_RequestScreen();
        *(int *)((char *)((TradeWork *)p)->request+8)=2;
        POKETRADE_PROC_ExitBgm(p);
        result=1;
        WIPE_SetBrightnessFadeOut(0,0);WIPE_SetBrightnessFadeOut(1,0);
    }
    return result;
}

int POKETRADE_PROC_Exit(void *owner,int unused,int keep,char *p)
{
    int state=((TradeWork *)p)->tradeState;
    if(WIPE_SYS_EndCheck()==0)return 0;
    GFL_HEAP_Free(((TradeWork *)p)->subObjPaletteCopy);
    GFL_HEAP_Free(((TradeWork *)p)->subBgPaletteCopy);
    POKETRADE_2D_DeleteMarkingIcon(p+0x950);POKETRADE_2D_DeleteMarkingIcon(p+0x964);POKETRADE_2D_DeleteMarkingIcon(p+0x978);
    POKETRADE_2D_ClearSubScreen(p);POKETRADE_PROC_DeleteAllResources(p);BEACON_STATUS_DoNothing();
    if(POKETRADE_PROC_IsNetSession(p))GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    POKETRADE_3D_Delete3DScene(p);
    GFL_HEAP_Free(((TradeWork *)p)->monABuf);GFL_HEAP_Free(((TradeWork *)p)->monBBuf);
    TCB_DeleteTask(((TradeWork *)p)->nodeA);
    POKETRADE_PROC_FreeMons(p,keep!=0);
    POKETRADE_PROC_ExitMcssSystem(p);POKETRADE_PROC_ExitDisplay(p);PROCSYS_FreeProcWork(owner);
    GFL_HEAP_DeleteChecked(31);GFL_HEAP_DeleteChecked(145);
    if(state<5) {GF_OVERLAY_Unload((int)ov114_id);GF_OVERLAY_Unload((int)ov067_id);}
    GF_OVERLAY_Unload(state==0 || state==4 ?(int)ov117_id:(int)ov118_id);
    return 1;
}

void POKETRADE_PROC_ClampScrollColumn(char *p, int flag)
{
    int n;
    if (flag) {
        n = POKETRADE_2D_GetScrollColumn(p) + 2;
        if (n >= ((TradeWork *)p)->slotCount) n -= ((TradeWork *)p)->slotCount;
        if (((TradeWork *)p)->scrollX == gScrollSnapPos[0]) n = 2;
        else if (((TradeWork *)p)->scrollX == gScrollSnapPos[((TradeWork *)p)->partyBoxId]) {
            n = 0;
            if (((TradeWork *)p)->cursorColumn >= 3) ((TradeWork *)p)->cursorColumn = 2;
        }
        ((TradeWork *)p)->cursorSlot = n;
        ((TradeWork *)p)->cursorRow = -1;
    }
}

void POKETRADE_PROC_SetSyncRange(void *a, void *b, void *c)
{
    if (POKETRADE_PROC_IsNetSession(c))
        GFL_NET_HANDLE_SetTimingSyncRange(a, (unsigned int)b, 8);
}

void POKETRADE_PROC_UpdatePickedIcon(char *p)
{
    if (UI_GetInputMode()) {
        POKETRADE_2D_MovePickedIconActor(p, -1);
        return;
    }
    {
        int v = ((TradeWork *)p)->cursorIndex;
        if (v != -1)
            POKETRADE_2D_MovePickedIconActor(p, v);
    }
}

int POKETRADE_PROC_CanTradeMon(char *p, int a)
{
    int v, lock, r;
    unsigned i;
    v = POKE_TOOL_GetBoxValue((void *)a,5,0);
    i = 0;
    if (((TradeWork *)p)->tradeState == 3) {
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

int POKETRADE_PROC_TickWifiTimer(char *p)
{
    if (((TradeWork *)p)->cancelTimer) {
        if (POKETRADE_PROC_IsWifiMode(p))
            ((TradeWork *)p)->cancelTimer = ((TradeWork *)p)->cancelTimer - 1;
        else
            ((TradeWork *)p)->cancelTimer = 0;
    }
    return ((TradeWork *)p)->cancelTimer == 0;
}
