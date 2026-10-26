/*
 * file:     pokemontrade_save.c
 * unit:     yes
 * function: POKETRADE_SAVE_FreeIfSet, POKETRADE_SAVE_SetWaitCounter, POKETRADE_SAVE_PopBgmFadeIn60, POKETRADE_SAVE_PopBgm, POKETRADE_SAVE_PopBgmFadeIn24, POKETRADE_SAVE_ResetClactAndBeginEvent, POKETRADE_SAVE_StepEventMessage1, POKETRADE_SAVE_StepEventMessage2, POKETRADE_SAVE_StepWaitFade1, POKETRADE_SAVE_StepWaitFade2, POKETRADE_SAVE_StepWaitSyncRange, POKETRADE_SAVE_SendTradeSummary, POKETRADE_SAVE_BackupSaveControl, POKETRADE_SAVE_RestoreSaveControl, POKETRADE_SAVE_BackupZukan, POKETRADE_SAVE_RestoreZukan, POKETRADE_SAVE_BackupBlock1F, POKETRADE_SAVE_RestoreBlock1F, POKETRADE_SAVE_FreeBackups, POKETRADE_SAVE_RestoreBackups, POKETRADE_SAVE_ConsumePerapVoice, POKETRADE_SAVE_ApplyTradeResult, POKETRADE_SAVE_StepAfterTrade, POKETRADE_SAVE_StepWaitEvolutionMessage, POKETRADE_SAVE_StepRegisterReceived, POKETRADE_SAVE_StepCheckEvolution, POKETRADE_SAVE_StepSaveCancelNotice, POKETRADE_SAVE_StepBeginSyncRange24, POKETRADE_SAVE_StepWaitSyncRange24, POKETRADE_SAVE_StepStartSave, POKETRADE_SAVE_StepWaitSaveDone, POKETRADE_SAVE_StepBeginWipeOut, POKETRADE_SAVE_StepRebuildSceneAfterWipe, POKETRADE_SAVE_DeleteTypeIconActor, POKETRADE_SAVE_CreateTypeIconActor, POKETRADE_SAVE_DeleteStatusIconActor, POKETRADE_SAVE_CreateStatusIconActor, POKETRADE_SAVE_OpenMessageWindow, POKETRADE_SAVE_OpenMessageWindowAtPos, POKETRADE_SAVE_OpenMessageWindowTop, POKETRADE_SAVE_ShowTimeIcon, POKETRADE_SAVE_CloseMessageWindow, POKETRADE_SAVE_CloseMessageWindowClear, POKETRADE_SAVE_CreateMessageResources, POKETRADE_SAVE_DeleteMessageResources, POKETRADE_SAVE_IsMessagePrintDone, POKETRADE_SAVE_CloseTaskMenu, POKETRADE_SAVE_OpenTaskMenuAt, POKETRADE_SAVE_OpenTaskMenu, POKETRADE_SAVE_PrintNickname, POKETRADE_SAVE_PrintDexNumber, POKETRADE_SAVE_PrintSpeciesName, POKETRADE_SAVE_PrintLevel, POKETRADE_SAVE_PrintGender, POKETRADE_SAVE_PrintStatLabels, POKETRADE_SAVE_PrintHeldItem, POKETRADE_SAVE_PrintHpValues, POKETRADE_SAVE_PrintStatValues, POKETRADE_SAVE_PrintAbilityLabel, POKETRADE_SAVE_PrintMoveNames, POKETRADE_SAVE_PrintNatureName, POKETRADE_SAVE_PrintExperience, POKETRADE_SAVE_DrawOfferCardWindow, POKETRADE_SAVE_DeleteOfferStatusIcons, POKETRADE_SAVE_DeleteTypeIcons, POKETRADE_SAVE_CloseSummaryPage, POKETRADE_SAVE_OpenSummaryScreen, POKETRADE_SAVE_DrawSummaryPage, POKETRADE_SAVE_PrepareSummaryWindow, POKETRADE_SAVE_CreateTypeIcons, POKETRADE_SAVE_ToggleTypeIconSet, POKETRADE_SAVE_ShowSummaryMon, POKETRADE_SAVE_DeleteOfferCardWindow, POKETRADE_SAVE_CloseSummaryWindow, POKETRADE_SAVE_DrawOfferListWindows, POKETRADE_SAVE_DeleteOfferListWindows, POKETRADE_SAVE_SetupWindowRegsSummary, POKETRADE_SAVE_DrawPartnerOfferCard, POKETRADE_SAVE_DeletePartnerOfferCard, POKETRADE_SAVE_OpenTaskMenuWindow, POKETRADE_SAVE_CloseTaskMenuWindow, POKETRADE_SAVE_IsTouchOutsideArea, POKETRADE_SAVE_VBlankSetupWindowRegs, POKETRADE_SAVE_Init3DProjection, POKETRADE_SAVE_Free3DLightSet, POKETRADE_SAVE_SetCameraSummary, POKETRADE_SAVE_SetCameraTrade, POKETRADE_SAVE_Update3DParticles, POKETRADE_SAVE_Setup3DDrawState
 * address:  0x021DFD24
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
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   MAIL_GetBox 0x02008FEC thumb
 *   MAIL_FindEmptySlot 0x02009020 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetBgmPaused 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MI_CpuFill8 0x02082BCC arm
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   WIFI_HISTORY_GetBlock  0x02009470  thumb
 *   MYSTATUS_GetNation  0x0200856C  thumb
 *   MYSTATUS_GetArea  0x02008570  thumb
 *   MYSTATUS_GetLanguage  0x02008564  thumb
 *   MYSTATUS_SetNationAndArea  0x02008574  thumb
 *   NATION_AREA_SanitizeNation  0x02025C1C  thumb
 *   NATION_AREA_SanitizeArea  0x02025C30  thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_SAVE_DrawOfferCardWindow  0x021E1B14  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferCardWindow  0x021E2438  thumb  ov119
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   POKETRADE_SAVE_CloseSummaryPage 0x021E1CE8 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   POKETRADE_SAVE_OpenSummaryScreen 0x021E1D68 thumb ov119
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   POKETRADE_SAVE_CloseSummaryWindow 0x021E2484 thumb ov119
 *   POKETRADE_SAVE_DrawSummaryPage 0x021E1E00 thumb ov119
 *   GFL_HEAP_Free 0x020307B0 arm
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 *   POKETRADE_SAVE_OpenMessageWindow 0x021E0EF4 thumb ov119
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   BOX_SAVEDATA_GetUsableBoxCount 0x020076A4 thumb
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows 0x021E2680 thumb ov119
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   POKETRADE_SAVE_DeleteMessageResources 0x021E11A8 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_2D_ExitSubBgs 0x021E57A4 thumb ov119
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   POKETRADE_SAVE_StepSaveCancelNotice 0x021E0B34 thumb ov119
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   FADE_Start 0x0204E720 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   POKETRADE_SAVE_OpenTaskMenuWindow 0x021E2984 thumb ov119
 *   POKETRADE_SAVE_IsTouchOutsideArea 0x021E2A80 thumb ov119
 *   POKETRADE_SAVE_CloseTaskMenuWindow 0x021E2A1C thumb ov119
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   POKETRADE_2D_SetDisplayConfig 0x021E57E8 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   MAIL_Create 0x02008F08 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MCSS_SetPosition   0x02015C48  thumb
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   WIFI_HISTORY_GetRatingLevel 0x0200960C thumb
 *   GAME_SYNC_GetBlockSize  0x02009454  thumb
 *   gSaveControlAllocTag     0x021E8130  data  ov119
 *   ZUKAN_SAVE_GetSize  0x0200C9EC  thumb
 *   TRADE_HISTORY_GetSize  0x02009D9C  thumb
 *   GAME_DATA_GetTradeHistory  0x02012F14  thumb
 *   TRADE_HISTORY_GetSize 0x02009D9C thumb
 *   MAIL_GetBoxSize 0x02008FFC thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   RECORD_GetSize 0x02008C20 thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   PLAYTIME_SetStamp 0x020086F8 thumb
 *   BOX_SAVEDATA_GetBoxDataSize 0x02007AEC thumb
 *   BOX_SAVEDATA_GetBoxPokemon 0x02007AF4 thumb
 *   GAME_DATA_GetPerapVoiceSave 0x02012F98 thumb
 *   PERAPVOICE_SetRecorded 0x02007B5C thumb
 *   PERAPVOICE_IsRecorded   0x02007B50  thumb
 *   PERAPVOICE_ClearRecorded   0x02007B54  thumb
 *   MAIL_GetBoxSize   0x02008FFC  thumb
 *   MAIL_GetBox   0x02008FEC  thumb
 *   RECORD_GetSize   0x02008C20  thumb
 *   PLAYTIME_GetStamp   0x020086F0  thumb
 *   BOX_SAVEDATA_GetUsableBoxCount   0x020076A4  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   BOX_SAVEDATA_GetBoxPageSize   0x02007A9C  thumb
 *   BOX_SAVEDATA_GetBoxPokemon   0x02007AF4  thumb
 *   MAIL_SetSlot   0x0200903C  thumb
 *   MAIL_Init  0x02008EAC  thumb
 *   TRADE_HISTORY_AddPartner   0x02009DE8  thumb
 *   WIFI_HISTORY_GetCountryRegionState   0x0200949C  thumb
 *   WIFI_HISTORY_SetCountryRegionState   0x020094D8  thumb
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   RECORD_AddOne   0x02008DF0  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   TRADE_HISTORY_IncrementTradeCount   0x02009EB0  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKEPARTY_SetMember   0x0201AB48  thumb
 *   BOX_SAVEDATA_SetPokemon  0x020075B0  thumb
 *   GAME_DATA_GetWifiList   0x0201283C  thumb
 *   WIFILIST_AddFriendBattleRecord   0x02009BB8  thumb
 *   WIFILIST_FindFriendByStatus   0x02009D1C  thumb
 *   gSaveBufferAllocTag     0x021E8108  data  ov119
 *   gMailBufferAllocTag     0x021E811C  data  ov119
 *   POKEPARTY_InitEx 0x0201A954 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   GFL_NET_SAVE_CreateWithCallback 0x020108C4 thumb
 *   GFL_NET_SAVE_CheckFinished 0x02010904 thumb
 *   GFL_NET_SAVE_Delete 0x02010934 thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   POKETRADE_PROC_StepResetForNewRound 0x021DACE4 thumb ov119
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   APP_ICON_GetBallThrowCellFileId 0x02027720 thumb
 *   APP_ICON_GetBallThrowAnimFileId 0x0202772C thumb
 *   APP_ICON_GetBallOpenCellFileId 0x02027738 thumb
 *   APP_ICON_GetBallOpenPaletteFileId 0x02027740 thumb
 *   BMP_Clear 0x02043B5C arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   PRINTSYS_CTRL_Init 0x02028470 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   APP_KEYCURSOR_CreateDefault 0x02028590 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   GFL_USE_ClearVBlankHook 0x0200566C thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   WORDSET_SetSlotMonSpeciesName 0x0201EE84 thumb
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   gStatValueLabels 0x021E7984 data a4
 *   gOfferCardWindowPosA 0x021E7934 data a4
 *   gOfferCardWindowPosB 0x021E7914 data a4
 *   gOfferCardWindowPosC 0x021E794C data a4
 *   POKETRADE_PROC_IsWifiMode 0x021D8ADC thumb ov119
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   POKETRADE_2D_DeleteTouchbarActors  0x021E5BE4  thumb  ov119
 *   POKETRADE_2D_DeleteSummaryIcons  0x021E625C  thumb  ov119
 *   POKETRADE_2D_LoadMainPalette 0x021E5958 thumb ov119
 *   POKETRADE_2D_CreateTouchbarActors 0x021E5998 thumb ov119
 *   gSummaryPagePosA 0x021E7944 data a4
 *   gSummaryPagePosB 0x021E793C data a4
 *   POKETRADE_2D_UploadWindowPalette 0x021E6294 thumb ov119
 *   POKETRADE_2D_CreateMarkingIcon 0x021E5DFC thumb ov119
 *   POKETRADE_2D_CreatePokerusIcon 0x021E5F14 thumb ov119
 *   gTypeIconSetA 0x021E7954 data a4
 *   gTypeIconSetB 0x021E7964 data a4
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   POKETRADE_2D_CreateSummaryIcons 0x021E60BC thumb ov119
 *   POKETRADE_2D_CreateOfferWindows 0x021E6CB8 thumb ov119
 *   POKETRADE_2D_UpdateOfferWindowActors 0x021E6E7C thumb ov119
 *   POKETRADE_2D_DeleteOfferWindowActors 0x021E6DEC thumb
 *   gPartnerOfferCardPosA 0x021E7924 data a4
 *   gPartnerOfferCardPosB 0x021E791C data a4
 *   gPartnerOfferColors 0x021E7974 data a4
 *   gPartnerOfferCardPosC 0x021E790C data a4
 *   APP_TASKMENU_WIN_CreateEx 0x0202800C thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   POKETRADE_NEGO_HasOffer 0x021DD2F4 thumb ov119
 *   gOutsideAreaHitRect 0x021E792C data
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   gLightSet 0x021E799C data a4
 *   gLightSetHandle 0x021F4560 data a4
 *   gProjectionConfig 0x021E7B1C data a4
 *   gProjectionParams 0x020A1DF8 data a2
 *   G3D_LIGHT_DeleteSlots 0x02048C4C arm
 *   G3D_CAMERA_SetEye 0x02048AFC arm
 *   G3D_CAMERA_SetCamTarget 0x02048B44 arm
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   G3D_CAMERA_SetCamUp 0x02048B20 arm
 *   G3D_CAMERA_SetNear 0x02048B60 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   ICA_ANIME_SetCameraPos 0x02011CF0 thumb
 *   ICA_ANIME_SetCameraTarget 0x02011D0C thumb
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   ICA_ANIME_GetTranslate 0x02011610 thumb
 *   PARTICLE_EMITTER_SetEmitPos 0x02051838 arm
 *   gDrawLightTable 0x021E79C8 data a4
 *   MYSTATUS_Copy  0x02008494  thumb  arm9
 *   POKETRADE_3D_AddPokemonMcss 0x021E35A0 thumb ov119
 *   POKETRADE_3D_DrawRotatingCube 0x021E3A40 thumb ov119
 *   POKETRADE_2D_InitClactSystemSub 0x021E3E60 thumb ov119
 *   POKETRADE_2D_LoadSubBackgroundGfx 0x021E3F30 thumb ov119
 *   POKETRADE_2D_NoOp 0x021E3F70 thumb ov119
 *   POKETRADE_2D_LoadSummaryBackground 0x021E40EC thumb ov119
 *   POKETRADE_2D_ExitSummaryBgs 0x021E53CC thumb ov119
 *   WIFI_HISTORY_GetVisitedCountryCount  0x02009584  thumb  arm9
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb  arm9
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb  arm9
 *   WORDSET_SetSlotFromMsgB6  0x0201EF8C  thumb  arm9
 *   POKE_TOOL_GetNature  0x02018598  thumb  arm9
 *   WIFI_HISTORY_GetGreetingSet  0x02009628  thumb  arm9
 */
#include "pokemontrade_types.h"
#include "../sdk_ioreg.h"

#include "../ov067/touchbar.h"

#include "../arm9/mail.h"

#include "../arm9/gfl_use.h"


#include "../arm9/clact.h"

#include "../arm9/mi_memory.h"
struct GFLNetHandle;

#include "../arm9/net_handle.h"
struct GameData;
struct SaveControl;

#include "../arm9/game_data.h"
struct WifiHistory;

#include "../arm9/wifi_history.h"
struct MyStatus;

#include "../arm9/mystatus.h"


#include "../arm9/bg_sys.h"

#include "../arm9/touchpanel.h"
struct Strbuf;
struct WordSet;

#include "../arm9/wordset.h"

struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"

#include "pokemontrade_2d.h"


struct G3dCamera;

#include "../arm9/g3d_camera.h"
struct TcbTask;

#include "../arm9/tcb_list.h"
struct BmpWin;
struct Bmp;

#include "../arm9/bmp_win.h"

struct BmpWin;


#define WININ (*(volatile u16 *)REG_DB_WININ_ADDR)

#define WINOUT (*(volatile u16 *)REG_DB_WINOUT_ADDR)

#define DISPCNT (*(volatile u32 *)REG_DB_DISPCNT_ADDR)

struct PerapVoice;

struct PlayTime;

struct PlayTimeStamp;

struct Rec534;

struct Sub02007AC8Entry;

struct Party;

struct PartyMon;

struct Sub02008EACObj;

struct Sub020097BCObj;

struct Sub02009D9CObj;

struct Sub020075B0Entry;

struct Sub02008C20Obj;

struct Sub0201088CObj;

struct GfFont;

struct TaskMenuRes;

struct Rec3;

struct S02031140;

struct TaskMenuState;

struct Blk;

struct TaskMenuTmpl;

struct LightSet;

struct LightSlot;

struct Rec12;

struct Packet {
    u32 prefix[8];
    u16 first,second;
    u8 a,b;
    u8 mode:3;
    u8 :5;
};

typedef struct {
    u8   pad0[0x1C];
    void *party;
    u8   pad20[8];
    u16  box;
    u16  slot;
    u16  count;
} Trade;


typedef struct { int v[5]; } T5;


typedef struct { int v[2]; } IntVec2;

typedef struct { int a,b,c,d; } IntQuad;

typedef struct {int a,b;} PokemontradeSavePair;

typedef struct {u32 a,b,c,d;} U32Quad;

#include "../types.h"

typedef struct {int a,b,c,d,e,f,g,h;} IntOctet;


#include "../sdk_fx.h"

typedef struct { VecFx32 trans; VecFx32 scale; MtxFx33 rot; } PokemontradeTransform;


struct MsgBank;

#include "../arm9/msgdata.h"

#include "pokemontrade_proc.h"

#include "../arm9/g2.h"

#include "../arm9/wipe.h"


#include "../arm9/net.h"


#include "../arm9/poke_tool.h"
struct PokemonParam;


#include "../arm9/file_util.h"
struct Mail;


struct Strbuf;

#include "../arm9/strbuf.h"

#include "../arm9/gfl_heap_wrap.h"


struct McssWork;

#include "../arm9/mcss.h"


#include "../arm9/bmp_menuwork.h"


#include "../arm9/game_sync.h"

#include "../arm9/zukan_save.h"


#include "../arm9/trade_history.h"


#include "../arm9/record.h"

#include "../arm9/box_savedata.h"

#include "../arm9/pokeparty.h"

#include "../arm9/playtime.h"

#include "../arm9/perapvoice.h"


struct BoxPokemon;


#include "../arm9/bmp_oam.h"

struct TradeHistory;


#include "../arm9/poke_tool_ext.h"

#include "../arm9/save_event.h"

struct ZukanSave;

struct TradeHistory;


struct BoxPokemon;


struct FieldState;

struct WifiList;

#include "../arm9/wifilist.h"


#include "../arm9/shinka_check.h"


#include "../arm9/fade.h"

#include "../arm9/net_save.h"
struct NetSaveTask;


#include "../ov067/ui_scene.h"

#include "../arm9/app_icon.h"


#include "../arm9/arc_util.h"

struct Bmp;

typedef short s16_p07;
#include "../arm9/bmp.h"

#include "../arm9/gf_font.h"

#include "../arm9/msg_speed.h"

#include "../arm9/printsys.h"

#include "../arm9/app_keycursor.h"


struct TimeIcon;

#include "../arm9/time_icon.h"
struct TcblList;


struct PrintQueue;

struct TcblSystem;

#include "../arm9/tcbl.h"
struct KeyCursor;

struct GFont;


struct TextPrinter;

struct TaskMenuWin;


struct PrintStreamCtrl;

struct TaskMenuInitWork;


#include "../arm9/poke_personal.h"


struct TcbTask;


struct TaskMenuItem;


#include "pokemontrade_nego.h"

#include "../arm9/g3d_light.h"

struct G3dProjection;

#include "../arm9/g3d_system.h"


#include "../arm9/fx_mtx33.h"
struct IcaAnime;

#include "../arm9/ica_anime.h"


#include "../arm9/g3x.h"

struct G3dLight;


#include "../arm9/particle.h"

void POKETRADE_SAVE_FreeIfSet(void *p);

void POKETRADE_SAVE_SetWaitCounter(TradeWork *p, u32 v);

void POKETRADE_SAVE_PopBgmFadeIn60(TradeWork *p);

void POKETRADE_SAVE_PopBgm(TradeWork *p);

void POKETRADE_SAVE_PopBgmFadeIn24(TradeWork *p);

void POKETRADE_SAVE_ResetClactAndBeginEvent(TradeWork *p);

void POKETRADE_SAVE_StepEventMessage1(TradeWork *p);

void POKETRADE_SAVE_StepEventMessage2(TradeWork *p);

void POKETRADE_SAVE_StepWaitFade1(TradeWork *p);

void POKETRADE_SAVE_StepWaitFade2(TradeWork *p);

void POKETRADE_SAVE_StepWaitSyncRange(TradeWork *p);

void POKETRADE_SAVE_SendTradeSummary(TradeWork *p);

void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId);

void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf);

void *POKETRADE_SAVE_BackupZukan(void *src, u16 heapId);

void POKETRADE_SAVE_RestoreZukan(void *h, void *buf);

void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId);

void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst);

void POKETRADE_SAVE_FreeBackups(void *arg);

void POKETRADE_SAVE_RestoreBackups(TradeWork *p);

int POKETRADE_SAVE_ConsumePerapVoice(TradeWork *p, void *party, int idx);

void POKETRADE_SAVE_ApplyTradeResult(TradeWork *p);

void POKETRADE_SAVE_StepAfterTrade(TradeWork *p);

void POKETRADE_SAVE_StepWaitEvolutionMessage(TradeWork *p);

void POKETRADE_SAVE_StepRegisterReceived(TradeWork *p);

void POKETRADE_SAVE_StepCheckEvolution(TradeWork *p);

void POKETRADE_SAVE_StepSaveCancelNotice(TradeWork *p);

void POKETRADE_SAVE_StepBeginSyncRange24(TradeWork *p);

void POKETRADE_SAVE_StepWaitSyncRange24(TradeWork *p);

void POKETRADE_SAVE_StepStartSave(TradeWork *p);

void POKETRADE_SAVE_StepWaitSaveDone(TradeWork *p);

void POKETRADE_SAVE_StepBeginWipeOut(TradeWork *p);

void POKETRADE_SAVE_StepRebuildSceneAfterWipe(TradeWork *p);

void POKETRADE_SAVE_DeleteTypeIconActor(TradeIconSlot *p);

void POKETRADE_SAVE_CreateTypeIconActor(TradeIconSlot *p,void *mon,int index,struct Unit *slot,int x,int y,int a,u16 b);

void POKETRADE_SAVE_DeleteStatusIconActor(TradeIconSlot *p);

void POKETRADE_SAVE_CreateStatusIconActor(TradeIconSlot *p,void *mon,struct Unit *slot,int x,int y,int a,u16 b,int c);

void POKETRADE_SAVE_OpenMessageWindow(TradeWork *p,int flag,int x,int y,int w,int h);

void POKETRADE_SAVE_OpenMessageWindowAtPos(TradeWork *p, int a, int flag);

void POKETRADE_SAVE_OpenMessageWindowTop(TradeWork *p);

void POKETRADE_SAVE_ShowTimeIcon(TradeWork *p);

void POKETRADE_SAVE_CloseMessageWindow(TradeWork *p);

void POKETRADE_SAVE_CloseMessageWindowClear(TradeWork *p);

void POKETRADE_SAVE_CreateMessageResources(TradeWork *p);

void POKETRADE_SAVE_DeleteMessageResources(TradeWork *p);

int POKETRADE_SAVE_IsMessagePrintDone(TradeWork *p);

void POKETRADE_SAVE_CloseTaskMenu(TradeWork *p);

void POKETRADE_SAVE_OpenTaskMenuAt(TradeWork *p,int *ids,int count,int x,int y);

void POKETRADE_SAVE_OpenTaskMenu(TradeWork *p, int *ids, int count);

void POKETRADE_SAVE_PrintNickname(void *a,void *b,int x,int y,int flag,int mode,TradeWork *p);

void POKETRADE_SAVE_PrintDexNumber(void *a,void *b,int x,int y,int flag,TradeWork *p);

void POKETRADE_SAVE_PrintSpeciesName(void *a,void *b,int x,int y,int flag,TradeWork *p);

void POKETRADE_SAVE_PrintLevel(void *a,void *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,TradeWork *p,int mode,int guard);

void POKETRADE_SAVE_PrintStatLabels(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintHeldItem(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintHpValues(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintStatValues(void *a, struct BmpWin *b, int c, int d, TradeWork *p);

void POKETRADE_SAVE_PrintAbilityLabel(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintMoveNames(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintNatureName(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_PrintExperience(void *a,struct BmpWin *b,int x,int y,TradeWork *p);

void POKETRADE_SAVE_DrawOfferCardWindow(TradeWork *p,int i,void *mon);

void POKETRADE_SAVE_DeleteOfferStatusIcons(TradeWork *p);

void POKETRADE_SAVE_DeleteTypeIcons(TradeWork *p);

void POKETRADE_SAVE_CloseSummaryPage(TradeWork *p, int disableSubWindows);

void POKETRADE_SAVE_OpenSummaryScreen(TradeWork *p,void *a);

void POKETRADE_SAVE_DrawSummaryPage(TradeWork *p,int mode,void *mon);

void POKETRADE_SAVE_PrepareSummaryWindow(TradeWork *p, void *a, int b, int unusedFlag);

void POKETRADE_SAVE_CreateTypeIcons(TradeWork *p,void *mon,IntQuad *t);

void POKETRADE_SAVE_ToggleTypeIconSet(TradeWork *p,void *a);

void POKETRADE_SAVE_ShowSummaryMon(TradeWork *p,void *mon,int side,int flag);

void POKETRADE_SAVE_DeleteOfferCardWindow(TradeWork *p,int i);

void POKETRADE_SAVE_CloseSummaryWindow(TradeWork *p,int a);

void POKETRADE_SAVE_DrawOfferListWindows(TradeWork *p, int unused);

void POKETRADE_SAVE_DeleteOfferListWindows(TradeWork *p);

void POKETRADE_SAVE_SetupWindowRegsSummary(void *unused);

void POKETRADE_SAVE_DrawPartnerOfferCard(TradeWork *p,int i,void *mon);

void POKETRADE_SAVE_DeletePartnerOfferCard(TradeWork *p,int i);

void *POKETRADE_SAVE_OpenTaskMenuWindow(TradeWork *p,int a);

void POKETRADE_SAVE_CloseTaskMenuWindow(TradeWork *p,int a,int b);

int POKETRADE_SAVE_IsTouchOutsideArea(void *unused);

void POKETRADE_SAVE_VBlankSetupWindowRegs(struct TcbTask *a, void *pArg);

void POKETRADE_SAVE_Init3DProjection(u16 a);

void POKETRADE_SAVE_Free3DLightSet(void);

void POKETRADE_SAVE_SetCameraSummary(TradeWork *p);

void POKETRADE_SAVE_SetCameraTrade(TradeWork *p);

void POKETRADE_SAVE_Update3DParticles(TradeWork *p);

void POKETRADE_SAVE_Setup3DDrawState(TradeWork *w, PokemontradeTransform *t);

#include "pokemontrade_3d.h"


extern const char gSaveControlAllocTag[];

extern const char gSaveBufferAllocTag[];

extern const char gMailBufferAllocTag[];

extern const T5 gStatValueLabels;

extern const PokemontradeIntPair gOfferCardWindowPosA,gOfferCardWindowPosB,gOfferCardWindowPosC;

extern const IntVec2 gSummaryPagePosA, gSummaryPagePosB;

extern const IntQuad gTypeIconSetA,gTypeIconSetB;

extern const PokemontradeSavePair gPartnerOfferCardPosA,gPartnerOfferCardPosB,gPartnerOfferCardPosC;

extern const U32Quad gPartnerOfferColors;

extern const char gOutsideAreaHitRect[];

extern const IntOctet gProjectionConfig;

extern char gLightSet[];

extern void *gLightSetHandle;

extern short gProjectionParams[];

extern char gDrawLightTable[];


void POKETRADE_SAVE_FreeIfSet(void *p) { if (p) { GFL_HEAP_Free(p); } }

void POKETRADE_SAVE_SetWaitCounter(TradeWork *p, u32 v) { (p->waitCounter) = v; }

/*
 * Decrement the +0x11f8 guard byte (both its condition and the store use
 * that same pool word) and pulse the 0x3c delay. Non-SDK dep of
 * POKETRADE_SAVE_ResetClactAndBeginEvent's case-5/6 arms.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_SAVE_PopBgmFadeIn60(TradeWork *p)
{
    TradeWork *b = p;

    if (b->sceneState != 0) {
        GFL_USE_PopBgm();
        b->sceneState -= 1;
        GFL_USE_SetBgmPaused(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}

void POKETRADE_SAVE_PopBgm(TradeWork *p)
{
    TradeWork *b = p;

    GFL_USE_PopBgm();
    b->sceneState -= 1;
}

void POKETRADE_SAVE_PopBgmFadeIn24(TradeWork *p)
{
    TradeWork *b = p;

    GFL_USE_PopBgm();
    b->sceneState -= 1;
    GFL_USE_SetBgmPaused(0);
    GFL_USE_FadeInBgmFull(0x18);
}

/*
 * Slot-state teardown/rebuild, dispatched on *(p+0x118c): 5 and 6 run the
 * shared +8 slot teardown and hand POKETRADE_PROC_SetStep either POKETRADE_PROC_StepBeginWipeOut or
 * NULL; the default path increments the +0x11f8 byte and hands
 * POKETRADE_SAVE_StepEventMessage1. Target of ov118 POKETRADE_DEMO_MIDDLE_StepEndScene's ABS32 callback argument.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_SAVE_ResetClactAndBeginEvent(TradeWork *p)
{
    TradeWork *b = p;
    int st;

    CLACT_DeleteUnit((*(void * *)&b->clactSystem));
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemSub(p);
    (*(void * *)&b->clactSystem) = CLACT_CreateUnit(0x154, 0, b->heapId);
    st = b->tradeState;
    if (st == 5) {
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        b->request->state = 3;
        POKETRADE_PROC_SetStep(p, POKETRADE_PROC_StepBeginWipeOut);
    } else if (st == 6) {
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        b->request->state = 3;
        POKETRADE_PROC_SetStep(p, 0);
    } else {
        POKETRADE_SAVE_CreateMessageResources(p);
        GFL_USE_SetBgmPaused((u32)1);
        GFL_USE_PushBgm();
        (b->sceneState)++;
        GFL_USE_FadeOutBgm(6);
        b->waitCounter = 0;
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepEventMessage1);
    }
}

/*
 * lever: Repeat the message call in each arm; an id local factors the argument loads and is 20 bytes short.
 */
void POKETRADE_SAVE_StepEventMessage1(TradeWork *p)
{
    void *mon;
    int z,state;
    if(p->waitCounter<6) return;
    GFL_USE_CancelChangeAndPlayBgm(0x518,0xffff);
    GFL_USE_FadeInBgmFull(6);
    state=p->tradeState;
    if(state==7) MSGDATA_ReadString((struct MsgBank *)(p->messageBank),153,(void *)((p->messageTemplate)));
    else if(state==8) MSGDATA_ReadString((struct MsgBank *)(p->messageBank),156,(void *)((p->messageTemplate)));
    else if(p->ownSameMon) MSGDATA_ReadString((struct MsgBank *)(p->messageBank),131,(void *)((p->messageTemplate)));
    else MSGDATA_ReadString((struct MsgBank *)(p->messageBank),48,(void *)((p->messageTemplate)));
    if(POKETRADE_PROC_IsHostSide(p)) mon=POKETRADE_PROC_GetSideMon(p,0);
    else mon=POKETRADE_PROC_GetSideMon(p,1);
    WORDSET_SetSlotMonNickname((*(void * *)&p->wordSet),1,mon);
    z=0;
    WORDSET_SetSlotMyStatus((struct WordSet *)(p->wordSet),0,(void *)(p->playerStatus));
    WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->messageText),(void *)((p->messageTemplate)));
    (p->fontBgHandle)=BMP_MENUWORK_LoadFrameGfx(6,15,0,p->heapId);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);
    POKETRADE_SAVE_SetWaitCounter(p,0);
    BG_SYS_SetPlaneVisible(6,1);
    p->waitCounter=z;
    POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepEventMessage2);
}

/*
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 */
void POKETRADE_SAVE_StepEventMessage2(TradeWork *p)
{
    void *a;
    if (p->waitCounter < 0xC8) {
        return;
    }
    if (POKETRADE_PROC_IsHostSide(p)) {
        a = POKETRADE_PROC_GetSideMon(p, 0);
    } else {
        a = POKETRADE_PROC_GetSideMon(p, 1);
    }
    WORDSET_SetSlotMonNickname((*(void * *)&p->wordSet), 1, a);
    WORDSET_SetSlotMyStatus((*(void * *)&p->wordSet), 0, (void *)(p->playerStatus));
    if (p->tradeState != 7 && p->tradeState != 8) {
        if (p->ownSameMon) {
            MSGDATA_ReadString((*(void * *)&p->messageBank), 0x84, p->messageTemplate);
            WORDSET_CopyTaggedText((*(void * *)&p->wordSet), (*(void * *)&p->messageText), p->messageTemplate);
            POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
        } else {
            MSGDATA_ReadString((*(void * *)&p->messageBank), 0x31, p->messageTemplate);
            WORDSET_CopyTaggedText((*(void * *)&p->wordSet), (*(void * *)&p->messageText), p->messageTemplate);
            POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
        }
    }
    POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepWaitFade1);
}

void POKETRADE_SAVE_StepWaitFade1(TradeWork *p)
{
    if (p->waitCounter >= 0x10e) {
        POKETRADE_SAVE_PopBgmFadeIn24(p);
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepWaitFade2);
    }
}

void POKETRADE_SAVE_StepWaitFade2(TradeWork *p)
{
    if (p->waitCounter >= 0x1a4) {
        POKETRADE_SAVE_SetWaitCounter(p, 0);
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepAfterTrade);
    }
}

void POKETRADE_SAVE_StepWaitSyncRange(TradeWork *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, 8)) {
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepRegisterReceived);
    }
}

void POKETRADE_SAVE_SendTradeSummary(TradeWork *p)
{
    struct Packet packet;
    void *saved,*first,*second;
    saved=WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(p->gameData));
    if(POKETRADE_PROC_IsHostSide(p)) {
        first=POKETRADE_PROC_GetSideMon(p,0);
        second=POKETRADE_PROC_GetSideMon(p,1);
    } else {
        first=POKETRADE_PROC_GetSideMon(p,1);
        second=POKETRADE_PROC_GetSideMon(p,0);
    }
    MYSTATUS_Copy((struct MyStatus *)(GAME_DATA_GetMyStatus(p->gameData)),(struct MyStatus *)(&packet));
    packet.first=POKE_TOOL_GetPartyValue(first,5,0);
    packet.second=POKE_TOOL_GetPartyValue(second,5,0);
    packet.a=WIFI_HISTORY_GetGreetingSet(saved);
    packet.b=WIFI_HISTORY_GetVisitedCountryCount(saved);
    packet.mode=WIFI_HISTORY_GetRatingLevel(saved);
    if(POKETRADE_PROC_IsNetSession(p)) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc12,40,(void *)(&packet))) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),23,8);
            POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepWaitSyncRange);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepBeginWipeOut);
}

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId)
{
    void *h = GAME_DATA_GetSaveControl(sys);
    void *buf = GFL_HEAP_Alloc(heapId, GAME_SYNC_GetBlockSize(), 0, gSaveControlAllocTag, 0x1A0);

    GFL_STD_MemCopy(WIFI_HISTORY_GetBlock(h), buf, GAME_SYNC_GetBlockSize());
    return buf;
}

void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf)
{
    void *src = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(sys));
    MI_CpuCopy8(buf, src, GAME_SYNC_GetBlockSize());
    GFL_HEAP_Free(buf);
}

void *POKETRADE_SAVE_BackupZukan(void *src, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, ZUKAN_SAVE_GetSize(), 0, gSaveControlAllocTag, 0x1BD);

    GFL_STD_MemCopy(ZUKAN_SAVE_GetFromGameData(src), buf, ZUKAN_SAVE_GetSize());
    return buf;
}

void POKETRADE_SAVE_RestoreZukan(void *h, void *buf)
{
    void *src = ZUKAN_SAVE_GetFromGameData(h);
    MI_CpuCopy8(buf, src, ZUKAN_SAVE_GetSize());
    GFL_HEAP_Free(buf);
}

void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, TRADE_HISTORY_GetSize(), 0, gSaveControlAllocTag, 0x1DA);

    GFL_STD_MemCopy(GAME_DATA_GetTradeHistory(sys), buf, TRADE_HISTORY_GetSize());
    return buf;
}

void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst)
{
    void *src = GAME_DATA_GetTradeHistory((struct GameData *)h);
    MI_CpuCopy8(dst, src, TRADE_HISTORY_GetSize());
    GFL_HEAP_Free(dst);
}

void POKETRADE_SAVE_FreeBackups(void *arg)
{
    TradeWork *p = arg;
    int zero;
    if (p->backup.saveControlBackup) GFL_HEAP_Free(p->backup.saveControlBackup);
    if (p->backup.trainerRecordBackup) GFL_HEAP_Free(p->backup.trainerRecordBackup);
    if (p->backup.savedSaveControl) GFL_HEAP_Free(p->backup.savedSaveControl);
    if (p->backup.savedZukan) GFL_HEAP_Free(p->backup.savedZukan);
    if (p->backup.savedBlock1F) GFL_HEAP_Free(p->backup.savedBlock1F);
    if (p->backup.partyBackup) GFL_HEAP_Free(p->backup.partyBackup);
    if (p->backup.boxBackup) GFL_HEAP_Free(p->backup.boxBackup);
    zero=0;
    MI_CpuFill8(&p->backup,zero,sizeof(p->backup));
    p->wipeStarted=zero;
}

void POKETRADE_SAVE_RestoreBackups(TradeWork *p)
{
    void *dest,*src;
    u32 n;
    dest=p->backup.saveControlBackup;
    if(dest) {
        src=p->gameData;
        GAME_DATA_GetSaveControl(src);
        src=MAIL_GetBox(src);
        n=MAIL_GetBoxSize();
        MI_CpuCopy8(dest,src,n);
        GFL_HEAP_Free(dest);
    }
    dest=p->backup.trainerRecordBackup;
    if(dest) {
        src=GAME_DATA_GetTrainerRecord(p->gameData);
        n=RECORD_GetSize();
        MI_CpuCopy8(dest,src,n);
        GFL_HEAP_Free(dest);
    }
    if(p->backup.savedSaveControl) POKETRADE_SAVE_RestoreSaveControl(p->gameData,p->backup.savedSaveControl);
    if(p->backup.savedZukan) POKETRADE_SAVE_RestoreZukan(p->gameData,p->backup.savedZukan);
    if(p->backup.savedBlock1F) POKETRADE_SAVE_RestoreBlock1F(p->gameData,p->backup.savedBlock1F);
    if(p->backup.partyBackup) {
        POKEPARTY_Copy(p->backup.partyBackup,p->partyData);
        PLAYTIME_SetStamp((void *)GAME_DATA_GetPlayTime((struct GameData *)(p->gameData)),&p->backup.playTimeStamp);
        GFL_HEAP_Free(p->backup.partyBackup);
        p->backup.partyBackup=0;
    }
    if(p->backup.boxBackup) {
        n=BOX_SAVEDATA_GetBoxDataSize();
        src=BOX_SAVEDATA_GetBoxPokemon((*(void * *)&p->boxManager),p->request->box);
        MI_CpuCopy8(p->backup.boxBackup,src,n);
        GFL_HEAP_Free(p->backup.boxBackup);
    }
    if(p->backup.boxSaveDirty) PERAPVOICE_SetRecorded((struct PerapVoice *)GAME_DATA_GetPerapVoiceSave(p->gameData));
    MI_CpuFill8(&p->backup,0,sizeof(p->backup));
}

int POKETRADE_SAVE_ConsumePerapVoice(TradeWork *p, void *party, int idx)
{
    int count = 0;
    int i, n;
    void *voice = GAME_DATA_GetPerapVoiceSave(p->gameData);

    if (!PERAPVOICE_IsRecorded(voice))
        return count;
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, i), 5, 0) == 0x1B9)
            count++;
    }
    if (count != 1)
        return 0;
    count = 0;
    if (POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, idx), 5, 0) == 0x1B9) {
        PERAPVOICE_ClearRecorded(voice);
        return 1;
    }
    return count;
}

static inline void *copy_a(void *sys, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, MAIL_GetBoxSize(), 0, gMailBufferAllocTag, 0x163);

    GFL_STD_MemCopy(MAIL_GetBox(sys), buf, MAIL_GetBoxSize());
    return buf;
}

static inline void *copy_b(void *sys, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, RECORD_GetSize(), 0, gSaveBufferAllocTag, 0x182);

    GFL_STD_MemCopy(GAME_DATA_GetTrainerRecord(sys), buf, RECORD_GetSize());
    return buf;
}

/*
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * pokemontrade_save.c.  The first two buffer copies are inlined statics
 * (their arguments are spilled before the body, and each carries its own
 * copy of the __FILE__ string); the rest call the out-of-line copies.
 * Every copy goes through the GFL_STD_MemCopy inline wrapper, whose
 * arguments are evaluated last to first: the size call, then the
 * destination load, then the source call.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_SAVE_ApplyTradeResult(TradeWork *p)
{
    void *mon;
    void *obj;
    void *list[2];
    int i;
    int out;

    if (POKETRADE_PROC_IsHostSide(p) == 0) {
        p->backup.saveControlBackup = copy_a(p->gameData, p->heapId);
        p->backup.trainerRecordBackup = copy_b(p->gameData, p->heapId);
        p->backup.savedSaveControl = POKETRADE_SAVE_BackupSaveControl(p->gameData, p->heapId);
        p->backup.savedZukan = POKETRADE_SAVE_BackupZukan(p->gameData, p->heapId);
        p->backup.savedBlock1F = POKETRADE_SAVE_BackupBlock1F(p->gameData, p->heapId);
        PLAYTIME_GetStamp((void *)GAME_DATA_GetPlayTime((struct GameData *)p->gameData), &p->backup.playTimeStamp);
        if (p->request->box == BOX_SAVEDATA_GetUsableBoxCount(p->boxManager)) {
            p->backup.partyBackup = POKEPARTY_Create(p->heapId);
            POKEPARTY_Copy(p->partyData, p->backup.partyBackup);
            p->backup.boxSaveDirty = POKETRADE_SAVE_ConsumePerapVoice(p, p->partyData, p->request->slot);
        } else {
            p->backup.boxBackup = GFL_HEAP_Alloc(p->heapId, BOX_SAVEDATA_GetBoxPageSize(), 0, gSaveControlAllocTag, 0x271);
            GFL_STD_MemCopy(BOX_SAVEDATA_GetBoxPokemon(p->boxManager, p->request->box), p->backup.boxBackup, BOX_SAVEDATA_GetBoxPageSize());
        }
    } else {
        struct TradeRequest *t = p->request;
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(p->boxManager))
            POKETRADE_SAVE_ConsumePerapVoice(p, p->partyData, t->slot);
        p->wipeStarted = 1;
    }

    {
        struct TradeRequest *t = p->request;
        if (t->box != BOX_SAVEDATA_GetUsableBoxCount(p->boxManager)) {
            mon = POKEPARTY_GetMember(t->party, 0);
            if (FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(mon, 6, 0))) {
                void *o = MAIL_GetBox(p->gameData);
                int idx = MAIL_FindEmptySlot(o, 0);
                if (idx != -1) {
                    void *buf = MAIL_Create(p->heapId);
                    POKE_TOOL_GetPartyValue(mon, 0xA7, (uptr)buf);
                    MAIL_SetSlot(o, 0, idx, buf);
                    MAIL_Init(buf);
                    POKE_TOOL_SetPartyValue(mon, 0xA7, (uptr)buf);
                    POKE_TOOL_SetPartyValue(mon, 6, 0);
                    GFL_HEAP_Free(buf);
                }
            }
        }
    }

    {
        u8 a = MYSTATUS_GetNation(p->playerStatus);
        u8 b = MYSTATUS_GetArea(p->playerStatus);
        u32 ra = NATION_AREA_SanitizeNation(a, b, MYSTATUS_GetLanguage(p->playerStatus));
        u32 rb = NATION_AREA_SanitizeArea(a, b, MYSTATUS_GetLanguage(p->playerStatus));
        if (a != ra || b != rb)
            MYSTATUS_SetNationAndArea(p->playerStatus, 0, 0);
    }

    TRADE_HISTORY_AddPartner(GAME_DATA_GetTradeHistory(p->gameData), p->playerStatus);
    obj = WIFI_HISTORY_GetBlock(GAME_DATA_GetSaveControl(p->gameData));
    list[0] = p->trainerRecord;
    list[1] = p->playerStatus;
    for (i = 0; i < 2; i++) {
        void *q = list[i];
        if (q) {
            u8 row = MYSTATUS_GetNation(q);
            u8 col = MYSTATUS_GetArea(q);
            MYSTATUS_GetLanguage(q);
            if (!WIFI_HISTORY_GetCountryRegionState(obj, row, col))
                WIFI_HISTORY_SetCountryRegionState(obj, row, col, 1);
        }
    }

    mon = POKEPARTY_GetMember(p->request->party, 0);
    obj = GAME_DATA_GetTrainerRecord(p->gameData);
    POKE_TOOL_HealFull(mon);
    if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0)
        POKE_TOOL_SetPartyValue((struct PokemonParam *)mon, 9, (uptr)((void *)0x46));
    if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0))
        SAVE_EVENT_Write((void *)mon, 6, (const struct MyStatus *)(p->trainerRecord), 0x7533, p->heapId);
    switch (p->tradeState) {
    case 2:
    case 3:
        RECORD_AddOne(obj, 0x10);
        break;
    case 1:
        RECORD_AddOne(obj, 0xC);
        break;
    case 0:
        RECORD_AddOne(obj, 0x24);
        break;
    }
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(p->gameData), mon);
    if (p->tradeState == 3)
        TRADE_HISTORY_IncrementTradeCount(GAME_DATA_GetTradeHistory(p->gameData));
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x1EC && POKE_TOOL_GetPartyValue(mon, 0x6F, 0) == 1) {
        POKE_TOOL_ChangeForm(mon, 0);
        ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(p->gameData), mon);
    }
    {
        struct TradeRequest *t = p->request;
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(p->boxManager)) {
            POKEPARTY_SetMember(p->partyData, t->slot, mon);
        } else {
            t = p->request;
            BOX_SAVEDATA_SetPokemon(p->boxManager, t->box, t->slot, POKE_TOOL_GetBoxParam(mon));
        }
    }
    switch (p->tradeState) {
    case 2:
        WIFILIST_AddFriendBattleRecord((void *)GAME_DATA_GetWifiList(p->gameData), p->request->count - 1, 0, 0, 1);
        break;
    case 0:
    case 1:
        if (WIFILIST_FindFriendByStatus((void *)GAME_DATA_GetWifiList(p->gameData), p->playerStatus, (u32 *)(&out)))
            WIFILIST_AddFriendBattleRecord((void *)GAME_DATA_GetWifiList(p->gameData), out, 0, 0, 1);
        break;
    }
}

void POKETRADE_SAVE_StepAfterTrade(TradeWork *p)
{
    int state;
    POKETRADE_3D_DeleteMcssSlot(p,0);POKETRADE_3D_DeleteMcssSlot(p,1);
    POKETRADE_3D_DeleteMcssSlot(p,2);POKETRADE_3D_DeleteMcssSlot(p,3);
    state=p->tradeState;
    if(state==4 || (unsigned)(state-7)<=1) {
        p->request->state=3;
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginWipeOut);
        return;
    }
    if((unsigned)(state-1)<=2) {
        POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_SendTradeSummary);
        return;
    } else {
        POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepRegisterReceived);
        return;
    }
}

void POKETRADE_SAVE_StepWaitEvolutionMessage(TradeWork *p)
{
    if (POKETRADE_SAVE_IsMessagePrintDone(p) && p->waitCounter > 0xB4) {
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepCheckEvolution);
    }
}

void POKETRADE_SAVE_StepRegisterReceived(TradeWork *p)
{
    int i;
    void *mon;
    int z;
    struct TradeRequest *t;
    if(POKETRADE_PROC_IsHostSide(p)) {
        i=p->offerCount%3;
        mon=POKETRADE_PROC_GetSideMon(p,0);
        p->request->box=p->offerBox[0][i];
        p->request->slot=p->offerSlot[0][i];
    } else {
        mon=POKETRADE_PROC_GetSideMon(p,1);
        p->request->box=p->selectedBox;
        p->request->slot=p->selectedSlot;
    }
    POKEPARTY_InitEx(p->request->party,6);
    POKEPARTY_Add(p->request->party,mon);
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(p->gameData),mon);
    t=p->request;
    if(t->box!=BOX_SAVEDATA_GetUsableBoxCount((*(void * *)&p->boxManager))) {
        z=0;
        if(FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(t->party,0),6,0))) {
            MSGDATA_ReadString((struct MsgBank *)(p->messageBank),106,(void *)(p->messageText));
            POKETRADE_SAVE_OpenMessageWindowTop(p);
            POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepWaitEvolutionMessage);
            p->waitCounter=z;
            return;
        }
    }
    POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepCheckEvolution);
}

/*
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 */
void POKETRADE_SAVE_StepCheckEvolution(TradeWork *p)
{
    void *a,*b;
    u32 out,result;
    if(p->gameData==0) {
        POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepBeginWipeOut);
        goto exit;
    }
    else {
    if(p->request!=0) {
        if(POKETRADE_PROC_IsHostSide(p)) {a=POKETRADE_PROC_GetSideMon(p,0);b=POKETRADE_PROC_GetSideMon(p,1);}
        else {a=POKETRADE_PROC_GetSideMon(p,1);b=POKETRADE_PROC_GetSideMon(p,0);}
        result=SHINKA_CHECK_CheckEvolution(0,a,1,(uptr)b,GAME_DATA_GetSeason(p->gameData),&out,p->heapId);
        if(result) {
            p->request->state=1;
            p->request->evolveResult=result;
            p->request->evolveOut=out;
            POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepBeginWipeOut);
            POKETRADE_SAVE_PopBgm(p);
            return;
        }
    }
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),50,(void *)(p->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepBeginSyncRange24);
    }
exit:
    POKETRADE_SAVE_PopBgmFadeIn60(p);
}

void POKETRADE_SAVE_StepSaveCancelNotice(TradeWork *p) {POKETRADE_SAVE_CreateMessageResources(p);MSGDATA_ReadString((struct MsgBank *)(p->messageBank),50,(void *)(p->messageText));p->fontBgHandle=BMP_MENUWORK_LoadFrameGfx(6,15,0,p->heapId);POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);POKETRADE_SAVE_SetWaitCounter(p,0);BG_SYS_SetPlaneVisible(6,1);GFL_NET_RefreshWmIconAtTopRight(1,p->heapId);FADE_Start(3,16,0,2);POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepBeginSyncRange24);}

void POKETRADE_SAVE_StepBeginSyncRange24(TradeWork *p)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8);
    POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepWaitSyncRange24);
}

void POKETRADE_SAVE_StepWaitSyncRange24(TradeWork *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8)) {
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepStartSave);
    }
}

void POKETRADE_SAVE_StepStartSave(TradeWork *p) {if(POKETRADE_SAVE_IsMessagePrintDone(p)) {if(POKETRADE_PROC_IsNetSession(p)) {POKETRADE_SAVE_ApplyTradeResult(p);p->netSave=GFL_NET_SAVE_CreateWithCallback(p->heapId,p->gameData,POKETRADE_SAVE_FreeBackups,p);POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepWaitSaveDone);return;}POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepBeginWipeOut);}}

/*
 * 2026-10-02: byte-correct; the call to the tail-call stub 0x02010934 (inside
 * matched unit_0201088C) now resolves since that stub was seeded as a start.
 */
void POKETRADE_SAVE_StepWaitSaveDone(TradeWork *p)
{
    if (GFL_NET_SAVE_CheckFinished(p->netSave)) {
        POKETRADE_SAVE_RestoreBackups(p);
        GFL_NET_SAVE_Delete(p->netSave);
        p->netSave = 0;
        POKETRADE_PROC_SetStep(p, POKETRADE_SAVE_StepBeginWipeOut);
    }
}

void POKETRADE_SAVE_StepBeginWipeOut(TradeWork *p) {int z;WIPE_SYS_Start(0,0,0,0,6,1,p->heapId);z=0;p->waitCounter=z;p->wipeStarted=z;POKETRADE_PROC_SetStep(p,POKETRADE_SAVE_StepRebuildSceneAfterWipe);}

void POKETRADE_SAVE_StepRebuildSceneAfterWipe(TradeWork *p)
{
    if(p->waitCounter>=6 && WIPE_SYS_EndCheck()) {
        if(p->fontBgHandle) BG_SYS_FreeTileRun((int)6,(u16)(p->fontBgHandle),(u16)(p->fontBgHandle>>16));
        p->fontBgHandle=0;
        BG_SYS_SetMainVisiblePlanes((int)0);BG_SYS_SetSubVisiblePlanes((int)0);
        CLACT_DeleteUnit((*(void * *)&p->clactSystem));
        (*(void * *)&p->clactSystem)=CLACT_CreateUnit(0x154,0,p->heapId);
        POKETRADE_SAVE_CloseMessageWindow(p);POKETRADE_2D_ExitSubBgs(p);POKETRADE_2D_ExitSummaryBgs(p);
        POKETRADE_2D_SetDisplayConfig(0);POKETRADE_2D_SetupSubBgs(p);POKETRADE_2D_RegisterIconSpriteResources(p);
        POKETRADE_2D_CreateBoxIconActors(p);POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_LoadBackgroundGfx(p);
        POKETRADE_2D_CreateFontResource(p);POKETRADE_2D_LoadMainGfxAndMessageWindow(p);POKETRADE_3D_AddUnitAndInit(p,0);
        BG_SYS_SetMainVisiblePlanes((int)31);BG_SYS_SetSubVisiblePlanes((int)30);POKETRADE_3D_CreateTouchbar(p);
        GFL_NET_RefreshWmIconAtTopRight(1,p->heapId);
        p->netExitCount=0;
        POKETRADE_PROC_SetStep(p,POKETRADE_PROC_StepResetForNewRound);
    }
}

void POKETRADE_SAVE_DeleteTypeIconActor(TradeIconSlot *p)
{
    if (p->actor) {
        CLACT_DeleteActor((struct ClactActor *)(p->actor));
        p->actor = 0;
        UI_SCENE_FreeActorGfx(&p->gfx);
    }
}

void POKETRADE_SAVE_CreateTypeIconActor(TradeIconSlot *p,void *mon,int index,struct Unit *slot,int x,int y,int a,u16 b) {ActorGfxDesc d;u8 v;int z=0;v=POKE_TOOL_GetPartyValue(mon,index+174,0);d.screen=a;d.flags=z;d.arcId=APP_ICON_GetArchiveId();d.charId=APP_ICON_GetTouchBarFileId();d.plttId=APP_ICON_GetTypeCellFileId(v);d.cellId=APP_ICON_GetTypePaletteFileId(2);d.animId=APP_ICON_GetTypeAnimFileId(2);d.plttSlot=8;d.charBase=z;d.charSize=3;UI_SCENE_LoadActorGfx(&p->gfx,&d,(void *)(slot),b);p->actor=(struct ClactActor *)UI_SCENE_CreateActor( &p->gfx, (void *)(slot), (u8)x, (u8)y,z,b);CLACT_SetActorPaletteOffset((struct ClactActor *)(p->actor),APP_ICON_GetTypePaletteOffset(v),1);}

void POKETRADE_SAVE_DeleteStatusIconActor(TradeIconSlot *p)
{
    if (p->actor) {
        CLACT_DeleteActor((struct ClactActor *)(p->actor));
        p->actor = 0;
        UI_SCENE_FreeActorGfx(&p->gfx);
    }
}

/*
 * extent: two zero alignment bytes at 0x021E0EF2, labelled next function 0x021E0EF4.
 */
void POKETRADE_SAVE_CreateStatusIconActor(TradeIconSlot *p,void *mon,struct Unit *slot,int x,int y,int a,u16 b,int c) {ActorGfxDesc d;int v;v=POKE_TOOL_GetPartyValue(mon,152,0);POKETRADE_SAVE_DeleteStatusIconActor(p);d.screen=a;d.flags=0;d.arcId=APP_ICON_GetArchiveId();d.charId=APP_ICON_GetBallThrowCellFileId(v);d.plttId=APP_ICON_GetBallThrowAnimFileId(v);d.cellId=APP_ICON_GetBallOpenCellFileId(v,2);d.animId=APP_ICON_GetBallOpenPaletteFileId(v,2);d.plttSlot=c;d.charBase=0;d.charSize=1;UI_SCENE_LoadActorGfx(&p->gfx,&d,(void *)(slot),b);p->actor=(struct ClactActor *)UI_SCENE_CreateActor(&p->gfx,(void *)(slot),(u8)x,(u8)y,0,b);}

/*
 * prototype: 0201F73C arg2 is u16 because 021E0FC4..021E0FC6 truncates the loaded full word before the call.
 * prototype: 0201CCE4 forwarding wrapper leaves r0 live; caller stores it at 021E0F94 despite legacy void declaration.
 */
void POKETRADE_SAVE_OpenMessageWindow(TradeWork *p,int flag,int x,int y,int w,int h)
{
    void *v;
    POKETRADE_SAVE_CloseMessageWindow(p);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,p->heapId);
    v=(void *)BMP_WIN_Create(6,(u8)x,(u8)y,(u8)w,h,(u32)14,(u32)0);
    (*(void * *)&p->messageWin)=v;
    BMP_Clear(BMP_WIN_GetBmp(v),15);
    GF_FONT_SetTextColor(1,2,15);
    if(flag==0) {
        p->printStream=PRINTSYS_PrintStream((struct BmpWin *)v,0,0,(void *)p->messageText,p->font,MSG_SPEED_GetWait(),p->tcbl,2,p->heapId,15);
        PRINTSYS_CTRL_Init((PrintStreamCtrl *)p->printCtrl,2);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(v),0,0,(*(void * *)&p->messageText),p->font);
    }
    BMP_MENUWORK_DrawWindow(v,1,(u16)(p->fontBgHandle),15);
    BMP_WIN_TransferChars(v);BMP_WIN_MakeScreen(v);BG_SYS_MarkTileDirty(6);
}

void POKETRADE_SAVE_OpenMessageWindowAtPos(TradeWork *p, int a, int flag)
{
    if (flag) {
        POKETRADE_SAVE_OpenMessageWindow(p, a, 1, 0x12, 0x1E, 4);
        return;
    }
    POKETRADE_SAVE_OpenMessageWindow(p, a, 1, 1, 0x1E, 4);
}

void POKETRADE_SAVE_OpenMessageWindowTop(TradeWork *p) { POKETRADE_SAVE_OpenMessageWindowAtPos(p, 0, 0); }

void POKETRADE_SAVE_ShowTimeIcon(TradeWork *p)
{
    if (p->timeIcon) {
        TIME_ICON_Delete(p->timeIcon);
        p->timeIcon = 0;
    }
    p->timeIcon = TIME_ICON_CreateNode((struct TcblList *)(p->tcbl), (*(void * *)&p->messageWin), 0xF, 0x10, p->heapId);
}

void POKETRADE_SAVE_CloseMessageWindow(TradeWork *p)
{
    if (p->timeIcon) {
        TIME_ICON_Delete(p->timeIcon);
        p->timeIcon = 0;
    }
    if ((*(void * *)&p->messageWin)) {
        BMP_WIN_Delete((*(void * *)&p->messageWin));
        (*(void * *)&p->messageWin) = 0;
    }
}

void POKETRADE_SAVE_CloseMessageWindowClear(TradeWork *p) { if(p->timeIcon) {TIME_ICON_Delete((struct TimeIcon *)(p->timeIcon));p->timeIcon=0;} if(p->messageWin) {BMP_WIN_ClearScreen((struct BmpWin *)(p->messageWin));BG_SYS_MarkTileDirty(6);BMP_MENUWORK_DrawWindowBorder((void *)(p->messageWin),2);BMP_WIN_Delete((struct BmpWin *)(p->messageWin));p->messageWin=0;} }

void POKETRADE_SAVE_CreateMessageResources(TradeWork *p)
{
    (*(void * *)&p->wordSet)=WORDSET_CreateDefault(p->heapId);
    (*(void * *)&p->messageBank)=MSGDATA_CreateFromArchive(0,2,159,p->heapId);
    p->font=GF_FONT_Create(23,0,0,0,p->heapId);
    (*(void * *)&p->infoTextOut)=STRBUF_Create(128,p->heapId);
    (*(void * *)&p->infoTextIn)=STRBUF_Create(128,p->heapId);
    (*(void * *)&p->messageText)=STRBUF_Create(128,p->heapId);
    p->messageTemplate=STRBUF_Create(128,p->heapId);
    p->printQueue=(void *)PRINTSYS_QUE_Create((u32)(p->heapId));
    GF_FONT_SetTextColor(1,2,15);
    p->tcbl=TCBL_Create(p->heapId,p->heapId,2,0);
    p->keyCursor=APP_KEYCURSOR_CreateDefault(15,1,0,p->heapId);
    p->taskMenuRes=APP_TASKMENU_RES_Create(6,9,(struct GFont *)(p->font),(struct PrintQueue *)(p->printQueue),p->heapId);
}

void POKETRADE_SAVE_DeleteMessageResources(TradeWork *p)
{
    int i;
    GFL_USE_ClearVBlankHook();
    if(p->tcbl) {
        APP_KEYCURSOR_Delete((struct KeyCursor *)(p->keyCursor));
        POKETRADE_SAVE_CloseMessageWindow(p);
        POKETRADE_SAVE_CloseTaskMenu(p);
        if(p->printStream) {PRINTSYS_PrintStreamDelete((struct TextPrinter *)(p->printStream));p->printStream=0;}
        if(p->taskMenuWindow) {APP_TASKMENU_WIN_Delete(p->taskMenuWindow);p->taskMenuWindow=0;}
        if(p->taskMenuRes) {APP_TASKMENU_RES_Delete(p->taskMenuRes);p->taskMenuRes=0;}
        if((*(void * *)&p->subWin)) {BMP_WIN_Delete((*(void * *)&p->subWin));(*(void * *)&p->subWin)=0;}
        for(i=0;i<2;i++) {if(p->statusWin[i]) {BMP_WIN_Delete(p->statusWin[i]);p->statusWin[i]=0;}}
        WORDSET_Delete((*(void * *)&p->wordSet));
        MSGDATA_Delete((*(void * *)&p->messageBank));
        GF_FONT_Delete(p->font);
        STRBUF_Delete((*(void * *)&p->infoTextOut));
        STRBUF_Delete((*(void * *)&p->infoTextIn));
        STRBUF_Delete((*(void * *)&p->messageText));
        STRBUF_Delete(p->messageTemplate);
        PRINTSYS_QUE_Clear((struct PrintQueue *)(p->printQueue));
        PRINTSYS_QUE_Delete((struct PrintQueue *)(p->printQueue));
        TCBL_Destroy(p->tcbl);
        p->tcbl=0;
    }
}

int POKETRADE_SAVE_IsMessagePrintDone(TradeWork *p) {int v=1;if(p->printStream) {if(p->messageWin)APP_KEYCURSOR_Update((struct KeyCursor *)(p->keyCursor),(void *)(p->printStream),(void *)(p->messageWin));v=PRINTSYS_CTRL_Update((struct PrintStreamCtrl *)p->printCtrl,(void *)(p->printStream));if(v) {if(p->printStream) {PRINTSYS_PrintStreamDelete((struct TextPrinter *)(p->printStream));p->printStream=0;}}}return v;}

void POKETRADE_SAVE_CloseTaskMenu(TradeWork *p)
{
    if ((*(void * *)&p->taskMenu)) {
        *(volatile unsigned short *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu((*(void * *)&p->taskMenu));
        (*(void * *)&p->taskMenu) = 0;
    }
}

void POKETRADE_SAVE_OpenTaskMenuAt(TradeWork *p,int *ids,int count,int x,int y)
{
    TaskMenuInitWork t;
    int i;
    t.heapId=p->heapId;
    t.itemNum=count;
    t.itemWork=p->taskMenuItems;
    t.posType=1;
    t.charPosX=x;t.charPosY=y;t.width=13;t.height=3;
    for(i=0;i<count;i++) {
        p->taskMenuItems[(u32)i].str=STRBUF_Create(100,p->heapId);
        MSGDATA_ReadString((*(void * *)&p->messageBank),ids[i],p->taskMenuItems[(u32)i].str);
        p->taskMenuItems[(u32)i].msgColor=0x39e3;
        if(ids[i]==5) p->taskMenuItems[(u32)i].type=1;
        else p->taskMenuItems[(u32)i].type=0;
    }
    (*(void * *)&p->taskMenu)=APP_TASKMENU_OpenMenu(&t,p->taskMenuRes);
    for(i=0;i<count;i++) STRBUF_Delete(p->taskMenuItems[(u32)i].str);
}

void POKETRADE_SAVE_OpenTaskMenu(TradeWork *p, int *ids, int count)
{
    if (count == 1) {
        POKETRADE_SAVE_OpenTaskMenuAt(p, ids, count, 0x20, 0x15);
        return;
    }
    POKETRADE_SAVE_OpenTaskMenuAt(p, ids, count, 0x20, 0x18);
}

void POKETRADE_SAVE_PrintNickname(void *a,void *b,int x,int y,int flag,int mode,TradeWork *p) {if(!flag) {if(mode) {MSGDATA_ReadString((struct MsgBank *)(p->messageBank),28,(void *)(p->infoTextIn));WORDSET_SetSlotMonSpeciesName((*(void * *)&p->wordSet),0,a);}else {MSGDATA_ReadString((struct MsgBank *)(p->messageBank),29,(void *)(p->infoTextIn));WORDSET_SetSlotMonNickname((*(void * *)&p->wordSet),0,a);}WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));}else {MSGDATA_ReadString((struct MsgBank *)(p->messageBank),105,(void *)(p->infoTextOut));}PRINTSYS_Print(b,(s16)x,y,(void *)(p->infoTextOut),(void *)(p->font));}

void POKETRADE_SAVE_PrintDexNumber(void *a,void *b,int x,int y,int flag,TradeWork *p) {int v;u16 *t;if(!flag) {v=POKE_TOOL_GetPartyValue(a,171,0);if(!p->nationalDexEnabled) {t=POKE_PERSONAL_LoadFormTable(p->heapId,0);v=t[v];GFL_HEAP_Free(t);}if(v==999) {MSGDATA_ReadString((struct MsgBank *)(p->messageBank),162,(void *)(p->infoTextOut));}else {WORDSET_SetSlotNumber((struct WordSet *)(p->wordSet),1,v,3,1,1);MSGDATA_ReadString((struct MsgBank *)(p->messageBank),27,(void *)(p->infoTextIn));WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));}PRINTSYS_Print(b,(s16)x,y,(void *)(p->infoTextOut),(void *)(p->font));}}

void POKETRADE_SAVE_PrintSpeciesName(void *a,void *b,int x,int y,int flag,TradeWork *p) {if(!flag) {MSGDATA_ReadString((struct MsgBank *)(p->messageBank),28,(void *)(p->infoTextIn));WORDSET_SetSlotMonSpeciesName((*(void * *)&p->wordSet),0,a);WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));PRINTSYS_Print(b,(s16)x,y,(void *)(p->infoTextOut),(void *)(p->font));}}

void POKETRADE_SAVE_PrintLevel(void *a,void *b,int x,int y,TradeWork *p) {POKE_TOOL_GetPartyValue(a,171,0);MSGDATA_ReadString((struct MsgBank *)(p->messageBank),18,(void *)(p->infoTextIn));WORDSET_SetSlotNumber((struct WordSet *)(p->wordSet),0,POKE_TOOL_GetPartyValue(a,158,0),3,1,1);WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));PRINTSYS_Print(b,(s16)x,y,(void *)(p->infoTextOut),(void *)(p->font));}

void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,TradeWork *p,int mode,int guard) {int v,w,id;u16 color;v=POKE_TOOL_GetPartyValue(a,110,0);w=POKE_TOOL_GetPartyValue(a,173,0);id=POKE_TOOL_GetPartyValue(a,5,0);if(v<=1 && w!=0 && !(guard && id==29) && !(guard && id==32)) {if(mode) {if(v==1)color=0x31a0;else color=0x39e0;}else {if(v==1)color=0xc80;else color=0x14c0;}MSGDATA_ReadString((struct MsgBank *)(p->messageBank),v+46,(void *)(p->infoTextOut));PRINTSYS_PrintColor(b,(s16)x,y,(void *)p->infoTextOut,p->font,color);}}

void POKETRADE_SAVE_PrintStatLabels(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    int i;
    for(i=0;i<6;i++) {
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank),30+i,(void *)(p->infoTextOut));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x, (s16)(y+16*i),(*(void * *)&p->infoTextOut),p->font);
    }
}

void POKETRADE_SAVE_PrintHeldItem(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    int v;
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),43,(void *)(p->infoTextIn));
    v=POKE_TOOL_GetPartyValue(a,6,0);
    if(v) {
        WORDSET_SetSlotFromMsg36((struct WordSet *)(p->wordSet),0,v);
        WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x,y,(*(void * *)&p->infoTextOut),p->font);
    }
}

void POKETRADE_SAVE_PrintHpValues(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    int v,w;
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),39,(void *)(p->infoTextIn));
    v=POKE_TOOL_GetPartyValue(a,160,0);
    w=POKE_TOOL_GetPartyValue(a,161,0);
    WORDSET_SetSlotNumber((struct WordSet *)(p->wordSet),0,v,3,1,1);
    WORDSET_SetSlotNumber((struct WordSet *)(p->wordSet),1,w,3,1,1);
    WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x,y,(*(void * *)&p->infoTextOut),p->font);
}

void POKETRADE_SAVE_PrintStatValues(void *a, struct BmpWin *b, int c, int d, TradeWork *p)
{
    int i = 0;
    T5 t = gStatValueLabels;
    for (; i < 5; i++) {
        MSGDATA_ReadString((*(void * *)&p->messageBank), 0x28, (*(void * *)&p->infoTextIn));
        WORDSET_SetSlotNumber((*(void * *)&p->wordSet), 0, POKE_TOOL_GetPartyValue(a, t.v[i], 0), 3, 1, 1);
        WORDSET_CopyTaggedText((*(void * *)&p->wordSet), (*(void * *)&p->infoTextOut), (*(void * *)&p->infoTextIn));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (short)c, (short)(d + i * 16), (*(void * *)&p->infoTextOut), p->font);
    }
}

void POKETRADE_SAVE_PrintAbilityLabel(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),44,(void *)(p->infoTextOut));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x,y,(*(void * *)&p->infoTextOut),p->font);
}

void POKETRADE_SAVE_PrintMoveNames(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    int i,v;
    for(i=0;i<4;i++) {
        v=POKE_TOOL_GetPartyValue(a,54+i,0);
        if(v) {
            MSGDATA_ReadString((struct MsgBank *)(p->messageBank),45,(void *)(p->infoTextIn));
            WORDSET_SetSlotFromMsgCB((struct WordSet *)(p->wordSet),0,v);
            WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x,y+16*i,(*(void * *)&p->infoTextOut),p->font);
        }
    }
}

void POKETRADE_SAVE_PrintNatureName(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    struct MsgBank *s;
    s=MSGDATA_CreateFromArchive(0,2,24,p->heapId);
    MSGDATA_ReadString(s,POKE_TOOL_GetNature(a),(void *)(p->infoTextOut));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x,y,(*(void * *)&p->infoTextOut),p->font);
    MSGDATA_Delete(s);
}

void POKETRADE_SAVE_PrintExperience(void *a,struct BmpWin *b,int x,int y,TradeWork *p)
{
    int v;
    MSGDATA_ReadString((struct MsgBank *)(p->messageBank),42,(void *)(p->infoTextIn));
    v=POKE_TOOL_GetPartyValue(a,10,0);
    WORDSET_SetSlotFromMsgB6((struct WordSet *)(p->wordSet),0,v);
    WORDSET_CopyTaggedText((struct WordSet *)(p->wordSet),(void *)(p->infoTextOut),(void *)(p->infoTextIn));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct BmpWin *)b), (s16)x,y,(*(void * *)&p->infoTextOut),p->font);
}

/*
 * lever: retain the pre-increment byte index and independent old/base locals;
 * splitting old's base assignment and naming the else-side p+0x8c4
 * address settles the early r4/r7 allocation. No signature mutation.
 */

void POKETRADE_SAVE_DrawOfferCardWindow(TradeWork *work,int i,void *mon)
{
    char *p = (char *)work;
    PokemontradeIntPair a=gOfferCardWindowPosA;
    PokemontradeIntPair b=gOfferCardWindowPosB;
    PokemontradeIntPair c=gOfferCardWindowPosC;
    u32 flag;
    const char *old;
    u32 index;
    u32 pindex;
    char *tmp;
    flag=POKE_TOOL_GetPartyValue(mon,76,0);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,448,32,((TradeWork *)p)->heapId);
    old=p;
    old=old+(int)BW_OFFSETOF(TradeWork, statusWin);
    index=i*4;
    pindex=i*(int)sizeof(void *);
    if(*(struct BmpWin * const *)(old+pindex))BMP_WIN_Delete((*(struct BmpWin * const *)(old+pindex)));
    *(struct BmpWin **)((char *)((TradeWork *)p)->statusWin+pindex)=BMP_WIN_Create(3,(u8)(*(int *)((char *)&a+index)),1,14,20,14,0);
    GF_FONT_SetTextColor(15,2,0);
    {
        void *window=BMP_WIN_GetBmp(*(struct BmpWin **)((char *)((TradeWork *)p)->statusWin+pindex));
        POKETRADE_SAVE_PrintNickname(mon,window,16,0,flag,POKETRADE_PROC_IsWifiMode(work),work);
    }
    if(flag==0) {
        char *items=(char *)((TradeWork *)p)->statusWin;
        void *window=BMP_WIN_GetBmp(*(struct BmpWin **)(items+pindex));
        POKETRADE_SAVE_PrintGender(mon,window,80,0,work,0,POKETRADE_PROC_IsWifiMode(work));
        GF_FONT_SetTextColor(15,2,0);
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(*(struct BmpWin **)(items+pindex)),16,19,work);
        POKETRADE_SAVE_PrintHeldItem(mon,*(struct BmpWin **)(items+pindex),16,128,work);
        i++;
        POKETRADE_SAVE_CreateStatusIconActor(((TradeIconSlot *)((char *)((TradeWork *)p)->statusIcon+i*(int)sizeof(TradeIconSlot))),mon,((TradeWork *)p)->clactSystem,*(int *)((char *)&b+index)+16,16,0,((TradeWork *)p)->heapId,*(int *)((char *)&c+index));
        CLACT_SetActorBgPriority(*(void **)((char *)&work->statusIcon[0].actor+i*(int)sizeof(TradeIconSlot)),1);
    } else {
        tmp=(char *)((TradeWork *)p)->statusIcon;
        POKETRADE_SAVE_DeleteStatusIconActor((TradeIconSlot *)(tmp+(i+1)*(int)sizeof(TradeIconSlot)));
    }
    BMP_WIN_TransferChars(*(struct BmpWin * const *)(old+pindex));
    BMP_WIN_MakeScreen((*(struct BmpWin * const *)(old+pindex)));
    BG_SYS_MarkTileDirty(3);
}

void POKETRADE_SAVE_DeleteOfferStatusIcons(TradeWork *p)
{
    TradeIconSlot *q = p->statusIcon;
    int i;
    for (i = 0; i < 3; i++) {
        POKETRADE_SAVE_DeleteStatusIconActor(q + i);
    }
}

void POKETRADE_SAVE_DeleteTypeIcons(TradeWork *p)
{
    TradeIconSlot *q;
    int i = 0;
    q = p->typeIcon;
    for (; i < 4; i++) {
        POKETRADE_SAVE_DeleteTypeIconActor(q + i);
    }
}

void POKETRADE_SAVE_CloseSummaryPage(TradeWork *p, int disableSubWindows)
{
    unsigned int v;

    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[1]);
    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[2]);
    POKETRADE_2D_DeleteSummaryIcons(p);
    if (disableSubWindows != 0) {
        v = *(volatile unsigned int *)REG_DB_DISPCNT_ADDR;
        v &= 0xFFFF1FFF;
        *(volatile unsigned int *)0x04001000 = v;
    }
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    POKETRADE_SAVE_DeleteTypeIcons(p);
    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[0]);
    POKETRADE_2D_DeleteTouchbarActors(p);
    POKETRADE_3D_DeleteMcssSlot(p, 0);
    POKETRADE_3D_DeleteMcssSlot(p, 1);
    BMP_WIN_ClearScreen((struct BmpWin *)(p->subWin));
    BMP_WIN_Delete((struct BmpWin *)(p->subWin));
    p->subWin = 0;
    POKETRADE_2D_NoOp(p);
}


void POKETRADE_SAVE_OpenSummaryScreen(TradeWork *p,void *a)
{
    BG_SYS_SetPlaneVisible(3,0);
    POKETRADE_3D_RemoveCurrentUnit(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,0);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,1);
    POKETRADE_2D_LoadMainPalette(p);
    POKETRADE_SAVE_ShowSummaryMon(p,a,0,1);
    if(POKETRADE_PROC_IsHostSide(p)==0) {
        POKETRADE_2D_CreateTouchbarActors(p);
        POKETRADE_2D_LoadSubBackgroundGfx(p);
        BG_SYS_SetMainVisiblePlanes(29);
        BG_SYS_SetSubVisiblePlanes(31);
        G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR,26,-8);
        p->wipeDone=1;
        GFL_USE_AddMainTask(POKETRADE_SAVE_VBlankSetupWindowRegs,p,0);
    }
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),1,1);
}

/*
 * initialization: side is assigned 0/1 by the original signed p+f54 comparison; both IntVec2.v[2] snapshots are initialized by complete table copies.
 * arithmetic: ROM b={0,128} makes b.v[side]+16 equal 16/144; mode is forwarded unchanged and no input domain is added.
 * interface: 020450F0's second argument is explicitly narrowed to u8 at 021E1E5A/60; its own body accepts u32.
 */
void POKETRADE_SAVE_DrawSummaryPage(TradeWork *p,int mode,void *mon)
{
    IntVec2 a=gSummaryPagePosA;
    IntVec2 b=gSummaryPagePosB;
    int side=0;
    u32 flag;
    if(p->iconPosX<128) side=1;
    POKETRADE_2D_UploadWindowPalette(p,11,4);
    if(p->subWin) BMP_WIN_Delete(p->subWin);
    p->subWin=BMP_WIN_Create(6,(u8)a.v[side],0,16,18,11,0);
    GF_FONT_SetTextColor(14,15,0);
    flag=POKE_TOOL_GetPartyValue(mon,76,0);
    if(mode==0) {
        POKETRADE_SAVE_PrintNickname(mon,BMP_WIN_GetBmp(p->subWin),32,0,flag,0,p);
        if(flag==0) {
            POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(p->subWin),32,16,p);
            POKETRADE_SAVE_PrintStatLabels(mon,p->subWin,8,32,p);
            POKETRADE_SAVE_PrintHeldItem(mon,p->subWin,24,128,p);
            POKETRADE_SAVE_PrintHpValues(mon,p->subWin,64,32,p);
            POKETRADE_SAVE_PrintStatValues(mon,p->subWin,80,48,p);
            POKETRADE_SAVE_PrintGender(mon,BMP_WIN_GetBmp(p->subWin),96,0,p,0,0);
            POKETRADE_2D_CreateMarkingIcon(p,side,mon);
            POKETRADE_2D_CreatePokerusIcon(p,side,0,mon);
            POKETRADE_SAVE_CreateStatusIconActor(&p->statusIcon[0],mon,p->clactSystem,b.v[side]+16,16,1,p->heapId,13);
        } else {
            POKETRADE_SAVE_DeleteStatusIconActor(&p->statusIcon[0]);
        }
    } else {
        POKETRADE_SAVE_DeleteStatusIconActor(&p->statusIcon[0]);
        POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[0]);
        POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[1]);
        POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[2]);
        if(flag==0) {
            POKETRADE_SAVE_PrintAbilityLabel(mon,p->subWin,8,0,p);
            POKETRADE_SAVE_PrintMoveNames(mon,p->subWin,16,16,p);
            MSGDATA_ReadString(p->messageBank,36,p->infoTextOut);
            PRINTSYS_Print(BMP_WIN_GetBmp(p->subWin),8,80,p->infoTextOut,p->font);
            POKETRADE_SAVE_PrintNatureName(mon,p->subWin,16,96,p);
            MSGDATA_ReadString(p->messageBank,37,p->infoTextOut);
            PRINTSYS_Print(BMP_WIN_GetBmp(p->subWin),8,112,p->infoTextOut,p->font);
            POKETRADE_SAVE_PrintExperience(mon,p->subWin,16,128,p);
        }
    }
    POKETRADE_2D_LoadSummaryBackground(p,side,mode);
    BMP_WIN_MakeScreen(p->subWin);
    BMP_WIN_TransferChars(p->subWin);
    BG_SYS_MarkTileDirty(6);
}

void POKETRADE_SAVE_PrepareSummaryWindow(TradeWork *p, void *unusedData, int b, int unusedFlag)
{
    POKETRADE_3D_DeleteMcssSlot(p, b);
    if ((*(void * *)&p->subWin)) {
        BMP_WIN_Delete((*(void * *)&p->subWin));
    }
}

void POKETRADE_SAVE_CreateTypeIcons(TradeWork *p,void *mon,IntQuad *t)
{
    u32 a,b;
    POKETRADE_SAVE_DeleteTypeIconActor(&p->typeIcon[t->a]);
    POKETRADE_SAVE_DeleteTypeIconActor(&p->typeIcon[t->b]);
    POKETRADE_SAVE_CreateTypeIconActor(&p->typeIcon[t->a],mon,0,p->clactSystem,176,95,0,p->heapId);
    a=POKE_TOOL_GetPartyValue(mon,174,0);
    b=POKE_TOOL_GetPartyValue(mon,175,0);
    if(a!=b)
        POKETRADE_SAVE_CreateTypeIconActor(&p->typeIcon[t->b],mon,1,p->clactSystem,210,95,0,p->heapId);
    if(p->typeIcon[t->c].actor)
        CLACT_SetActorDrawEnable(p->typeIcon[t->c].actor,0);
    if(p->typeIcon[t->d].actor)
        CLACT_SetActorDrawEnable(p->typeIcon[t->d].actor,0);
}

void POKETRADE_SAVE_ToggleTypeIconSet(TradeWork *p,void *a)
{
    if(p->summaryFlag) {
        IntQuad t;
        t=gTypeIconSetA;
        POKETRADE_SAVE_CreateTypeIcons(p, a, &t);
        p->summaryFlag=0;
    } else {
        IntQuad t;
        t=gTypeIconSetB;
        POKETRADE_SAVE_CreateTypeIcons(p, a, &t);
        p->summaryFlag=1;
    }
}


/*
 * control: the pool-hole call POKETRADE_3D_AddPokemonMcss is written in both arms (x==0, then flag != 0); the compiler cross-jumps the first copy into a b.
 */
void POKETRADE_SAVE_ShowSummaryMon(TradeWork *p,void *mon,int side,int flag)
{
    u32 flag76;
    u32 v[3];
    int i;
    flag76=POKE_TOOL_GetPartyValue(mon,76,0);
    POKETRADE_SAVE_PrepareSummaryWindow(p,mon,side,flag);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,448,32,p->heapId);
    if(p->mcssPokemon[side]==0)
        POKETRADE_3D_AddPokemonMcss((TradeWork *)p,side,1,mon,0);
    else if(flag!=0)
        POKETRADE_3D_AddPokemonMcss((TradeWork *)p,side,1,mon,0);
    v[0]=0xe<<14;
    v[1]=1<<14;
    v[2]=0;
    MCSS_SetPosition(p->mcssPokemon[side],v);
    MCSS_ResetVanishFlag(p->mcssPokemon[side]);
    if(p->mcssPokemon[1-side])
        MCSS_SetVanishFlag(p->mcssPokemon[1-side]);
    GF_FONT_SetTextColor(15,2,0);
    i=0;
    p->subWin=(void *)BMP_WIN_Create(3,1,0,31,24,14,0);
    POKETRADE_SAVE_PrintNickname(mon,BMP_WIN_GetBmp(p->subWin),16,0,flag76,0,p);
    if(flag76==0) {
        POKETRADE_SAVE_PrintDexNumber(mon,BMP_WIN_GetBmp(p->subWin),0,16,flag76,p);
        POKETRADE_SAVE_PrintSpeciesName(mon,BMP_WIN_GetBmp(p->subWin),56,16,flag76,p);
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(p->subWin),96,i,p);
        POKETRADE_SAVE_PrintGender(mon,BMP_WIN_GetBmp(p->subWin),80,i,p,i,i);
        POKETRADE_SAVE_PrintStatLabels(mon,p->subWin,0,32,p);
        for(i=0;i<2;i++) {
            MSGDATA_ReadString(p->messageBank,i+36,p->infoTextOut);
            PRINTSYS_Print(BMP_WIN_GetBmp(p->subWin),0,i*16+0x88,p->infoTextOut,p->font);
        }
        POKETRADE_SAVE_PrintHpValues(mon,p->subWin,56,32,p);
        POKETRADE_SAVE_PrintStatValues(mon,p->subWin,72,48,p);
        POKETRADE_SAVE_PrintNatureName(mon,p->subWin,56,136,p);
        POKETRADE_SAVE_PrintExperience(mon,p->subWin,56,152,p);
        POKETRADE_SAVE_PrintHeldItem(mon,p->subWin,40,168,p);
        POKETRADE_SAVE_PrintAbilityLabel(mon,p->subWin,152,113,p);
        POKETRADE_SAVE_PrintMoveNames(mon,p->subWin,152,128,p);
        POKETRADE_SAVE_ToggleTypeIconSet(p,mon);
        POKETRADE_2D_CreateMarkingIcon(p,2,mon);
        POKETRADE_SAVE_CreateStatusIconActor(&p->statusIcon[0],mon,p->clactSystem,12,7,0,p->heapId,12);
    } else {
        if(p->markingIcon[0].actor) CLACT_SetActorDrawEnable(p->markingIcon[0].actor,i);
        POKETRADE_SAVE_DeleteTypeIcons(p);
        POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    }
    POKETRADE_2D_CreateSummaryIcons(p,mon,flag76);
    POKETRADE_2D_CreatePokerusIcon(p,0,1,mon);
    BMP_WIN_MakeScreen(p->subWin);
    BMP_WIN_TransferChars(p->subWin);
    BG_SYS_MarkTileDirty(3);
}

void POKETRADE_SAVE_DeleteOfferCardWindow(TradeWork *p,int i)
{
    if (p->statusWin[i]) {
        BMP_Clear(BMP_WIN_GetBmp(p->statusWin[i]),0);
        BMP_WIN_ClearScreen(p->statusWin[i]);
        BMP_WIN_Delete(p->statusWin[i]);
        BG_SYS_MarkTileDirty(3);
        p->statusWin[i]=0;
        POKETRADE_SAVE_DeleteStatusIconActor(&p->statusIcon[i+1]);
    }
}

void POKETRADE_SAVE_CloseSummaryWindow(TradeWork *p,int a)
{
    POKETRADE_SAVE_DeleteStatusIconActor(&p->statusIcon[0]);
    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[0]);
    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[1]);
    POKETRADE_2D_DeleteMarkingIcon(&p->markingIcon[2]);
    if (p->subWin) {
        BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)p->subWin),0);
        if(a) {
            BMP_WIN_ClearScreen((struct BmpWin *)(p->subWin));
            BMP_WIN_TransferChars((struct BmpWin *)p->subWin);
        }
        BMP_WIN_Delete((struct BmpWin *)(p->subWin));
        p->subWin=0;
    }
}

/*
 * zero: the literal 0 arguments of the first loop are hoisted and spilled to the slot k then reuses; k=0 is written just before the second GF_FONT_SetTextColor call, not before the loop.
 */
void POKETRADE_SAVE_DrawOfferListWindows(TradeWork *work, int unused)
{
#ifdef __MWERKS__
    char *p = (char *)work;
    void *arr[2];
    void *mon;
    u32 flag76;
    char *q1,*q2;
    int j,n;
    int k;
    POKETRADE_2D_CreateOfferWindows(work);
    arr[0]=(*(void **)(p+0x834));
    arr[1]=(*(void **)(p+0x830));
    GF_FONT_SetTextColor(15,2,0);
    for(j=0;j<2;j++) {
        MSGDATA_ReadString((*(void **)(p+0x720)),128,(*(void **)(p+0x734)));
        WORDSET_SetSlotMyStatus((*(void **)(p+0x724)),0,arr[j]);
        WORDSET_CopyTaggedText((*(void **)(p+0x724)),(*(void **)(p+0x730)),(*(void **)(p+0x734)));
        PRINTSYS_Print(*(void **)(p+j*16+0x10f4),0,0,(*(void **)(p+0x730)),(*(void **)(p+0x728)));
    }
    k=0;
    GF_FONT_SetTextColor(15,2,k);
    for(;k<2;k++) {
        GF_FONT_SetTextColor(1,2,0);
        q1=p+(1-k)*12;
        q2=p+k*16;
        for(n=0;n<3;n++) {
            mon=((TradeWork *)q1)->offerMon[0][n];
            if(*(int *)(q1+n*4+0xfa4)!=-1) {
                flag76=POKE_TOOL_GetPartyValue(mon,76,0);
                POKETRADE_2D_CreateOfferIconActor(work,k,n,mon,0,1);
                POKETRADE_SAVE_PrintNickname(mon,*(void **)(q2+n*4+0x10f8),0,0,flag76,POKETRADE_PROC_IsWifiMode(work),work);
                if(flag76==0) {
                    POKETRADE_SAVE_PrintGender(mon,*(void **)(q2+n*4+0x10f8),56,16,work,0,POKETRADE_PROC_IsWifiMode(work));
                    POKETRADE_SAVE_PrintLevel(mon,*(void **)(q2+n*4+0x10f8),0,16,work);
                }
            }
        }
    }
    POKETRADE_2D_UpdateOfferWindowActors(work);
#else
    TradeWork *p = work;
    void *arr[2];
    void *mon;
    u32 flag76;
    int j,n;
    int k;
    POKETRADE_2D_CreateOfferWindows(p);
    arr[0]=p->playerStatus;
    arr[1]=p->trainerRecord;
    GF_FONT_SetTextColor(15,2,0);
    for(j=0;j<2;j++) {
        MSGDATA_ReadString(p->messageBank,128,p->infoTextIn);
        WORDSET_SetSlotMyStatus(p->wordSet,0,arr[j]);
        WORDSET_CopyTaggedText(p->wordSet,p->infoTextOut,p->infoTextIn);
        PRINTSYS_Print(p->windowBmp[j*4],0,0,p->infoTextOut,p->font);
    }
    k=0;
    GF_FONT_SetTextColor(15,2,k);
    for(;k<2;k++) {
        GF_FONT_SetTextColor(1,2,0);
        for(n=0;n<3;n++) {
            mon=p->offerMon[1-k][n];
            if(p->offerSlot[1-k][n]!=-1) {
                flag76=POKE_TOOL_GetPartyValue(mon,76,0);
                POKETRADE_2D_CreateOfferIconActor(p,k,n,mon,0,1);
                POKETRADE_SAVE_PrintNickname(mon,p->windowBmp[k*4+n+1],0,0,flag76,POKETRADE_PROC_IsWifiMode(p),p);
                if(flag76==0) {
                    POKETRADE_SAVE_PrintGender(mon,p->windowBmp[k*4+n+1],56,16,p,0,POKETRADE_PROC_IsWifiMode(p));
                    POKETRADE_SAVE_PrintLevel(mon,p->windowBmp[k*4+n+1],0,16,p);
                }
            }
        }
    }
    POKETRADE_2D_UpdateOfferWindowActors(p);
#endif
}

void POKETRADE_SAVE_DeleteOfferListWindows(TradeWork *p)
{
    int i;
    for (i=0;i<4;i++) {
        if (p->offerListWin[i]) {
            BMP_WIN_Delete(p->offerListWin[i]);
            p->offerListWin[i]=0;
        }
    }
    POKETRADE_2D_DeleteOfferWindowActors(p);
}

void POKETRADE_SAVE_SetupWindowRegsSummary(void *unused)
{
    u32 v;

    G2x_SetBlendBrightness_(REG_DB_BLDCNT_ADDR, 0x1A, -8);

    v = (*(volatile u16 *)REG_DB_WININ_ADDR & ~0x3F) | 0x1F;
    *(volatile u16 *)REG_DB_WININ_ADDR = v | 0x20;
    *(volatile u16 *)REG_DB_WIN0H_ADDR = 0x00FF;
    *(volatile u16 *)REG_DB_WIN0V_ADDR = 0x00C0;
    v = (*(volatile u16 *)REG_DB_WININ_ADDR & ~0x3F00) | 0x1F00;
    *(volatile u16 *)REG_DB_WININ_ADDR = v | 0x2000;
    *(volatile u16 *)REG_DB_WIN1H_ADDR = 0xFF00;
    *(volatile u16 *)REG_DB_WIN1V_ADDR = 0x00C0;
    v = (*(volatile u16 *)REG_DB_WINOUT_ADDR & ~0x3F) | 0x1F;
    *(volatile u16 *)REG_DB_WINOUT_ADDR = v;
    *(volatile u32 *)REG_DB_DISPCNT_ADDR =
        (*(volatile u32 *)REG_DB_DISPCNT_ADDR & 0xFFFF1FFF) | 0x6000;
}

/*
 * lever: each final handle index is recomputed through a 32-bit long local;
 * an int copy CSEs the shift and shortens the function by four bytes.
 */
void POKETRADE_SAVE_DrawPartnerOfferCard(TradeWork *work,int i,void *mon)
{
    char *p = (char *)work;
    PokemontradeSavePair a=gPartnerOfferCardPosA;
    PokemontradeSavePair b=gPartnerOfferCardPosB;
    U32Quad colors=gPartnerOfferColors;
    PokemontradeSavePair c=gPartnerOfferCardPosC;
    u32 flag;
    int layer,idx2;
    u32 col,col2;
    int index;
    int pindex;
    char *items,*items2;
    flag=POKE_TOOL_GetPartyValue(mon,76,0);
    index=i*4;
    pindex=i*(int)sizeof(void *);
    if(*(struct BmpWin **)((char *)work->levelWin+i*(int)sizeof(void *))) {
        BMP_WIN_Delete((*(struct BmpWin **)((char *)work->levelWin+i*(int)sizeof(void *))));
        BMP_WIN_Delete((*(struct BmpWin **)((char *)work->itemWin+i*(int)sizeof(void *))));
    }
    layer=*(int *)((char *)&a+index);
    items=(char *)work->levelWin;
    *(void **)(items+pindex)=BMP_WIN_Create(1,(u8)layer,0,14,5,5,0);
    items2=(char *)work->itemWin;
    *(void **)(items2+pindex)=BMP_WIN_Create(1,(layer & 0xff),17,13,2,5,0);
    idx2=i*2;
    col=((u32 *)&colors)[idx2];
    BMP_Clear(BMP_WIN_GetBmp(*(struct BmpWin **)(items+pindex)),(u8)(col|(col<<4)));
    col2=((u32 *)&colors)[idx2+1];
    BMP_Clear(BMP_WIN_GetBmp(*(struct BmpWin **)(items2+pindex)),(u8)(col2|(col2<<4)));
    GF_FONT_SetTextColor(1,2,(u8)col);
    {
        void *window=BMP_WIN_GetBmp(*(struct BmpWin **)(items+pindex));
        POKETRADE_SAVE_PrintNickname(mon,window,16,4,flag,POKETRADE_PROC_IsWifiMode(work),work);
    }
    if(flag==0) {
        char *first=(char *)work->levelWin;
        void *window=BMP_WIN_GetBmp(*(struct BmpWin **)(first+pindex));
        POKETRADE_SAVE_PrintGender(mon,window,80,4,work,1,POKETRADE_PROC_IsWifiMode(work));
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(*(struct BmpWin **)(first+pindex)),16,19,work);
        GF_FONT_SetTextColor(1,2,(u8)col2);
        POKETRADE_SAVE_PrintHeldItem(mon,*(struct BmpWin **)(items2+pindex),0,0,work);
        POKETRADE_SAVE_CreateStatusIconActor(&work->statusIcon[i+1],mon,((TradeWork *)p)->clactSystem,*(int *)((char *)&b+index)+16,16,0,((TradeWork *)p)->heapId,*(int *)((char *)&c+index));
    } else POKETRADE_SAVE_DeleteOfferStatusIcons(work);
    {
        char *first=(char *)work->levelWin;
        char *second=(char *)work->itemWin;
        long endindex=(long)i*(int)sizeof(void *);
        BMP_WIN_TransferChars(*(struct BmpWin **)(first+endindex));
        BMP_WIN_TransferChars(*(struct BmpWin **)(second+endindex));
        BMP_WIN_MakeScreen((*(struct BmpWin **)(first+endindex)));
        BMP_WIN_MakeScreen((*(struct BmpWin **)(second+endindex)));
    }
    BG_SYS_MarkTileDirty(1);
    work->slotTimer[i]=120;
}

void POKETRADE_SAVE_DeletePartnerOfferCard(TradeWork *p,int i)
{
    if (p->levelWin[i]) {
        BMP_WIN_Delete(p->levelWin[i]);
        BMP_WIN_Delete(p->itemWin[i]);
        POKETRADE_SAVE_DeleteStatusIconActor(&p->statusIcon[i+1]);
        p->levelWin[i]=0;
        p->itemWin[i]=0;
    }
}

void *POKETRADE_SAVE_OpenTaskMenuWindow(TradeWork *p,int a) {
    void *t;
    t=STRBUF_Create(100,p->heapId);
    p->taskMenuItems[0].str=t;
    MSGDATA_ReadString((*(void * *)&p->messageBank),a,t);
    p->taskMenuItems[0].msgColor=0x39e3;
    p->taskMenuItems[0].type=0;
    p->taskMenuWindow=APP_TASKMENU_WIN_CreateEx((struct TaskMenuRes *)(p->taskMenuRes),p->taskMenuItems,8,21,16,3,0,1,p->heapId);
    STRBUF_Delete((struct Strbuf *)(p->taskMenuItems[0].str));
    CLACT_SetActorDrawEnable((struct ClactActor *)((*(void * *)&p->cursorActor)),0);
    TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),8,0);
    return p->taskMenuWindow;
}

void POKETRADE_SAVE_CloseTaskMenuWindow(TradeWork *p,int a,int b) {
    if (!PRINTSYS_QUE_IsFinished(p->printQueue)) PRINTSYS_QUE_Clear((struct PrintQueue *)(p->printQueue));
    if(a) CLACT_SetActorDrawEnable((struct ClactActor *)((*(void * *)&p->cursorActor)),1);
    if(b) TOUCHBAR_SetButtonVisible((TouchBar *)((unsigned char *)(p->touchbar)),8,POKETRADE_NEGO_HasOffer(p));
    if(p->taskMenuWindow) {
        APP_TASKMENU_WIN_Delete(p->taskMenuWindow);
        p->taskMenuWindow=0;
        BG_SYS_MarkTileDirty(6);
    }
}

int POKETRADE_SAVE_IsTouchOutsideArea(void *unused)
{
    if (TOUCHPANEL_HitTrg((const TouchHitTable *)gOutsideAreaHitRect) == 0) return 1;
    return 0;
}

static inline void W1Inside(int wnd,BOOL effect) {
    u32 tmp=(WININ & ~0x3f00)|((u32)wnd<<8);
    if(effect) tmp|=0x2000;
    WININ=(u16)tmp;
}

static inline void W0Inside(int wnd,BOOL effect) {
    u32 tmp=(WININ & ~0x3f)|((u32)wnd);
    if(effect) tmp|=0x20;
    WININ=(u16)tmp;
}

static inline void Outside(int wnd,BOOL effect) {
    u32 tmp=(WINOUT & ~0x3f)|((u32)wnd);
    if(effect) tmp|=0x20;
    WINOUT=(u16)tmp;
}

static inline void Position1(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)REG_DB_WIN1H_ADDR=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)REG_DB_WIN1V_ADDR=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

static inline void Position0(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)REG_DB_WIN0H_ADDR=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)REG_DB_WIN0V_ADDR=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

static inline void Visible(int window) {DISPCNT=(DISPCNT&~0xe000)|(window<<13);}

/*
 * volatile: WININ re-read at 021E2A9E and 021E2AB6; WINOUT and DISPCNT hardware read-modify-write, WIN0/1 positions hardware stores.
 */
void POKETRADE_SAVE_VBlankSetupWindowRegs(struct TcbTask *a, void *pArg) {
    TradeWork *p = pArg;
    W1Inside(0x10,0);
    Position1(0x30,0,0xd0,0x20);
    W0Inside(0x11,0);
    Position0(0xe0,0xa9,0xff,0xc0);
    Outside(0x1f,1);
    Visible(3);
    p->wipeDone=0;
    TCB_DeleteTask(a);
}

void POKETRADE_SAVE_Init3DProjection(u16 a) {
    IntOctet c;
    gLightSetHandle=G3D_LIGHT_CreateSlots((const struct LightSetDesc *)gLightSet,a);
    G3D_LIGHT_ApplySlots(gLightSetHandle);
    c=gProjectionConfig;
    c.b=gProjectionParams[12]; c.c=gProjectionParams[13];
    G3D_SYSTEM_SetProjection((struct G3dProjection *)(&c));
}

void POKETRADE_SAVE_Free3DLightSet(void)
{
    G3D_LIGHT_DeleteSlots(gLightSetHandle);
}

void POKETRADE_SAVE_SetCameraSummary(TradeWork *p) {
    VecFx32 a;
    VecFx32 b;
    a.x=0; a.y=0x2b000; a.z=0xf1000;
    b.x=0; b.y=0x2b000; b.z=0;
    G3D_CAMERA_SetEye((struct G3dCamera *)(p->subCamera),(const VecFx32 *)&a);
    G3D_CAMERA_SetCamTarget((struct G3dCamera *)(p->subCamera),(const VecFx32 *)&b);
    a.z-=0x1000;
    G3D_CAMERA_SetFar((struct G3dCamera *)(p->subCamera),(const u32 *)((u32 *)(&a.z)));
    b.x=0; b.y=0x1000; b.z=0;
    G3D_CAMERA_SetCamUp((struct G3dCamera *)(p->subCamera),(const VecFx32 *)&b);
}

void POKETRADE_SAVE_SetCameraTrade(TradeWork *p) {
    VecFx32 a;
    VecFx32 b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    G3D_CAMERA_SetEye((struct G3dCamera *)(p->subCamera),(const VecFx32 *)&a);
    G3D_CAMERA_SetCamTarget((struct G3dCamera *)(p->subCamera),(const VecFx32 *)&b);
    G3D_CAMERA_SetNear(p->subCamera,(u32 *)(&d));
    G3D_CAMERA_SetFar((struct G3dCamera *)(p->subCamera),(const u32 *)((u32 *)(&c)));
    b.x=0; b.y=0x10000; b.z=0x1000;
    G3D_CAMERA_SetCamUp((struct G3dCamera *)(p->subCamera),(const VecFx32 *)&b);
}

void POKETRADE_SAVE_Update3DParticles(TradeWork *p) {POKETRADE_3D_DrawRotatingCube(p);}

static inline void shading(PokemontradeShading s) { *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3002) | (s << 1)); }

static inline void antialias(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 0x10); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3010; }

static inline void alphatest(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 4); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3004; }

static inline void blend(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 8); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3008; }

static inline void edge(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 0x20); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3020; }

/*
 * volatile: 0x04000060 reread at 021E2C9C, 021E2CAA, 021E2CB6, 021E2CC0, 021E2CC8; 0x04000580 hardware store at 021E2CEC.
 */
void POKETRADE_SAVE_Setup3DDrawState(TradeWork *w, PokemontradeTransform *t)
{
    unsigned i;
    VecFx32 emitterPosA;
    VecFx32 emitterPosB;
    t->trans.x = 0;
    t->trans.y = 0;
    t->trans.z = 0;
    t->scale.x = 0x1000;
    t->scale.y = 0x1000;
    t->scale.z = 0x1000;
    MTX_Identity33_(&t->rot);
    if (w->particleManager != 0) {
        if (w->particleManager->streamFrame[0] == 0) ICA_ANIME_SetCameraPos(w->subCamera, (struct IcaAnime *)w->particleManager->icaStream[0]);
        if (w->particleManager->streamFrame[1] == 0) ICA_ANIME_SetCameraTarget(w->subCamera, (struct IcaAnime *)w->particleManager->icaStream[1]);
    }
    G3D_CAMERA_Reset(w->subCamera);
    shading(SHADING_HIGHLIGHT); antialias(1); alphatest(0); blend(0); edge(0);
    G3X_SetFog(1, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((u8)i, (struct G3dLight *)(gDrawLightTable + i * 8));
    if (w->particleManager != 0) {
        if (w->particleManager->emitter[0] != 0) {
            ICA_ANIME_GetTranslate((struct IcaAnime *)w->particleManager->icaStream[2], (struct VecFx32 *)&emitterPosA);
            PARTICLE_EMITTER_SetEmitPos(w->particleManager->emitter[0], &emitterPosA);
        }
        if (w->particleManager->emitter[1] != 0) {
            ICA_ANIME_GetTranslate((struct IcaAnime *)w->particleManager->icaStream[3], (struct VecFx32 *)&emitterPosB);
            PARTICLE_EMITTER_SetEmitPos(w->particleManager->emitter[1], &emitterPosB);
        }
    }
}
