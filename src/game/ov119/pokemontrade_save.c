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
 *   func_02008FEC 0x02008FEC thumb
 *   MAIL_FindEmptySlot 0x02009020 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
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
 *   func_02017E1C 0x02017E1C thumb
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02008574  0x02008574  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_SAVE_DrawOfferCardWindow  0x021E1B14  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferCardWindow  0x021E2438  thumb  ov119
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_02045CAC 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_SAVE_ShowSummaryMon 0x021E219C thumb ov119
 *   func_02040588 0x02040588 arm
 *   POKETRADE_SAVE_CloseSummaryPage 0x021E1CE8 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   POKETRADE_SAVE_OpenSummaryScreen 0x021E1D68 thumb ov119
 *   POKETRADE_SAVE_CloseTaskMenu 0x021E12F8 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_0207D658 0x0207D658 arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos 0x021E0FF4 thumb ov119
 *   POKETRADE_SAVE_CloseSummaryWindow 0x021E2484 thumb ov119
 *   POKETRADE_SAVE_DrawSummaryPage 0x021E1E00 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   POKETRADE_2D_DeleteMarkingIcon 0x021E5EF8 thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 *   POKETRADE_SAVE_OpenMessageWindow 0x021E0EF4 thumb ov119
 *   POKETRADE_2D_SetupSubBgs 0x021E5680 thumb ov119
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   func_02049B40 0x02049B40 arm
 *   POKETRADE_2D_RegisterIconSpriteResources 0x021E58A0 thumb ov119
 *   POKETRADE_2D_CreateBoxIconActors 0x021E467C thumb ov119
 *   POKETRADE_2D_LoadMainGfxAndMessageWindow 0x021E3F74 thumb ov119
 *   func_02012944 0x02012944 thumb
 *   func_020076A4 0x020076A4 thumb
 *   POKETRADE_3D_RemoveCurrentUnit 0x021E3230 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows 0x021E2680 thumb ov119
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   POKETRADE_SAVE_DeleteMessageResources 0x021E11A8 thumb ov119
 *   POKETRADE_SAVE_DeletePartnerOfferCard 0x021E293C thumb ov119
 *   POKETRADE_2D_ExitSubBgs 0x021E57A4 thumb ov119
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_020056A0 0x020056A0 thumb
 *   POKETRADE_SAVE_StepSaveCancelNotice 0x021E0B34 thumb ov119
 *   POKETRADE_SAVE_CreateMessageResources 0x021E10D8 thumb ov119
 *   POKETRADE_2D_CreateFontResource 0x021E3FE4 thumb ov119
 *   POKETRADE_3D_CreateTouchbar 0x021E3C20 thumb ov119
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   FADE_Start 0x0204E720 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02048AD0 0x02048AD0 arm
 *   func_02030EAC 0x02030EAC arm
 *   POKETRADE_SAVE_OpenTaskMenuWindow 0x021E2984 thumb ov119
 *   POKETRADE_SAVE_IsTouchOutsideArea 0x021E2A80 thumb ov119
 *   POKETRADE_SAVE_CloseTaskMenuWindow 0x021E2A1C thumb ov119
 *   func_020275E4  0x020275E4  thumb
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
 *   func_02045B38 0x02045B38 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MCSS_SetPosition   0x02015C48  thumb
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_0200960C 0x0200960C thumb
 *   GAME_SYNC_GetBlockSize  0x02009454  thumb
 *   gSaveControlAllocTag     0x021E8130  data  ov119
 *   ZUKAN_SAVE_GetSize  0x0200C9EC  thumb
 *   TRADE_HISTORY_GetSize  0x02009D9C  thumb
 *   GAME_DATA_GetSaveBlock1F  0x02012F14  thumb
 *   func_02009D9C 0x02009D9C thumb
 *   func_02008FFC 0x02008FFC thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008C20 0x02008C20 thumb
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   GAME_DATA_GetPlayTime 0x02012FCC thumb
 *   func_020086F8 0x020086F8 thumb
 *   func_02007AEC 0x02007AEC thumb
 *   func_02007AF4 0x02007AF4 thumb
 *   GAME_DATA_GetBoxSave 0x02012F98 thumb
 *   func_02007B5C 0x02007B5C thumb
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
 *   func_02008EAC  0x02008EAC  thumb
 *   TRADE_HISTORY_AddPartner   0x02009DE8  thumb
 *   WIFI_HISTORY_GetCountryRegionState   0x0200949C  thumb
 *   WIFI_HISTORY_SetCountryRegionState   0x020094D8  thumb
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *   func_0202F190  0x0202F190  thumb
 *   RECORD_AddOne   0x02008DF0  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   TRADE_HISTORY_IncrementTradeCount   0x02009EB0  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKEPARTY_SetMember   0x0201AB48  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sub_0201283C   0x0201283C  thumb
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
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   POKETRADE_PROC_StepResetForNewRound 0x021DACE4 thumb ov119
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   func_020275E8 0x020275E8 thumb
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275EC 0x020275EC thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_02027720 0x02027720 thumb
 *   func_0202772C 0x0202772C thumb
 *   func_02027738 0x02027738 thumb
 *   func_02027740 0x02027740 thumb
 *   BMP_Clear 0x02043B5C arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_02028470 0x02028470 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   STRBUF_Create 0x020457B0 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   TCBL_Create 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_0200566C 0x0200566C thumb
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
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
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   G3D_SYSTEM_SetProjection 0x02046858 arm
 *   gLightSet 0x021E799C data a4
 *   gLightSetHandle 0x021F4560 data a4
 *   gProjectionConfig 0x021E7B1C data a4
 *   gProjectionParams 0x020A1DF8 data a2
 *   func_02048C4C 0x02048C4C arm
 *   func_02048AFC 0x02048AFC arm
 *   func_02048B44 0x02048B44 arm
 *   func_02048B6C 0x02048B6C arm
 *   func_02048B20 0x02048B20 arm
 *   func_02048B60 0x02048B60 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   ICA_ANIME_SetCameraPos 0x02011CF0 thumb
 *   ICA_ANIME_SetCameraTarget 0x02011D0C thumb
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   ICA_ANIME_Get 0x02011610 thumb
 *   BUTTON_MAN_SetEmitterPos 0x02051838 arm
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
 *   WORDSET_Callback_EF40  0x0201EF40  thumb  arm9
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb  arm9
 *   WORDSET_SetSlotFromMsgB6  0x0201EF8C  thumb  arm9
 */
#include "pokemontrade_types.h"

extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);

extern struct Sub02008F80Obj *func_02008FEC(void *sys);

extern int MAIL_FindEmptySlot(void *obj, int v);

extern void GFL_USE_SetBgmPlayerParam(void *p);

extern int GFL_USE_PushBgm(void);

extern void GFL_USE_CancelChangeAndPlayBgm(int,int);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void MI_CpuFill8(void *,int,int);

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern struct Sub02009470Obj *func_02009470(void *sys);

extern u8 func_0200856C(const struct Sub0200852CObj *obj);

extern u8 func_02008570(const struct Sub0200852CObj *obj);

extern u8 func_02008564(const struct Sub0200852CObj *obj);

extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);

extern void func_02040588(unsigned char which, unsigned char enable);

extern int TOUCHPANEL_HitTrg(const void *);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern void POKETRADE_2D_SetupSubBgs(char *p);

extern void CLACT_ExitSystem(void);

extern void POKETRADE_2D_ExitSubBgs(int);

extern int GFL_USE_PopBgm(void);

extern void func_02048AD0(struct Light *l);

extern void func_02030EAC(struct Node *n);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern void POKETRADE_2D_SetDisplayConfig(int);

#define W(p, o) (*(int *)((p) + (o)))

#define H(p, o) (*(u16 *)((p) + (o)))

#define T(p)    (*(Trade **)((p) + 8))

#define P(k) (*(void **)(p+(k)))

#define Q ((void **)(p+0x844))

#define WININ (*(volatile u16 *)0x04001048)

#define WINOUT (*(volatile u16 *)0x0400104a)

#define DISPCNT (*(volatile u32 *)0x04001000)

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

struct R;

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




typedef struct {u32 heap;u8 count;u8 pad[3];const void *items;u32 flag;u8 x,y,a,b;} SpriteTemplate;


typedef struct { int v[5]; } T5;

typedef struct {int a,b;} IntPair;

typedef struct { int v[2]; } IntVec2;

typedef struct { int a,b,c,d; } IntQuad;

typedef struct {int a,b;} Pair;

typedef struct {u32 a,b,c,d;} U32Quad;

typedef int BOOL;

typedef struct {int a,b,c,d,e,f,g,h;} IntOctet;

typedef struct {int x,y,z;} IntVec3;

typedef int fx32;


typedef struct { fx32 m[3][3]; } MtxFx33;

typedef struct { VecFx32 trans; VecFx32 scale; MtxFx33 rot; } Transform;

typedef struct {
    char pad0[0x90];
    u32 anim90;
    u32 anim94;
    u32 anim98;
    u32 anim9c;
    void *objA0;
    void *objA4;
    void *objA8;
    void *objAC;
} AnimSlot;

typedef struct {
    char pad0[0xc];
    AnimSlot *sub;
    char pad10[0x83c - 0x10];
    void *x83c;
} DrawState3D;

typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } Shading;

extern void func_02045CAC(struct MsgBank *,unsigned,void *);

extern void POKETRADE_PROC_SetStep(void *,int);

extern void func_0207D658(u32,int,int);

extern u32 WIPE_SYS_EndCheck(void);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern int POKETRADE_PROC_IsNetSession(void *);

extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);

extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);

extern u32 func_02017E1C(void *,u32,u32);

extern void POKE_TOOL_SetPartyValue(void *,u32,u32);

extern u32 FILE_UTIL_Check136C(u16);

extern void *MAIL_Create(int);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 func_020307B0(void *p);

extern void BG_SYS_SetSubVisiblePlanes(u32 planes);

extern void POKETRADE_PROC_StepBeginWipeOut(void *);

extern int POKETRADE_PROC_IsHostSide(void *);

extern void func_02041B6C(u32 bit);

extern void MI_CpuCopy8(const void *,void *,unsigned);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MCSS_SetPosition(void *p, u32 *src);

extern void GFL_USE_FadeInBgmFull(u32 a);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void GFL_USE_FadeOutBgm(u32 a);

extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);

extern void *POKETRADE_PROC_GetSideMon(void *,int);

extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);

extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);

extern u8 *func_02012944(void *p);

extern void MYSTATUS_Copy(void *,void *);

extern u8 func_02009628(const struct Sub02009470Obj *obj);

extern u8 WIFI_HISTORY_GetVisitedCountryCount(const struct Sub02009470Obj *obj);

extern u8 func_0200960C(const struct Sub02009470Obj *obj);

extern u32 GAME_SYNC_GetBlockSize(void);

extern u32 ZUKAN_SAVE_GetSize(void);

extern void *ZUKAN_SAVE_GetFromGameData(void *p);

extern u32 TRADE_HISTORY_GetSize(void);

extern void *GAME_DATA_GetSaveBlock1F(void **h);

extern unsigned func_02009D9C(void);

extern void *GAME_DATA_GetTrainerRecord(int *p);

extern int GAME_DATA_GetPlayTime(int p0);

extern struct Sub02007AC8Entry *func_02007AF4(void **save, u32 box);

extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);

extern u32 func_02008FFC(void);

extern u32 func_02008C20(void);

extern u32 func_02007AEC(void);

extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);

extern void func_020086F8(struct PlayTime *p, const struct PlayTimeStamp *in);

extern void func_02007B5C(struct PerapVoice *p);

extern void *PERAPVOICE_IsRecorded(void **p);

extern void PERAPVOICE_ClearRecorded(struct PerapVoice *p);

extern u32 POKEPARTY_GetCount(void *p);

extern void *POKEPARTY_GetMember(void *p, u32 idx);

extern u32 MAIL_GetBoxSize(void);

extern struct Sub02008F80Obj *MAIL_GetBox(void *sys);

extern u32 RECORD_GetSize(void);

extern void PLAYTIME_GetStamp(const struct PlayTime *p, struct PlayTimeStamp *out);

extern u8 BOX_SAVEDATA_GetUsableBoxCount(void *save);

extern struct Party *POKEPARTY_Create(u32 heap);

extern u32 BOX_SAVEDATA_GetBoxPageSize(void);

extern struct Sub02007AC8Entry *BOX_SAVEDATA_GetBoxPokemon(void **save, u32 box);

extern void MAIL_SetSlot(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);

extern void func_02008EAC(struct Sub02008EACObj *obj);

extern u32 func_02025C1C(u32 a, u32 b, u32 c);

extern u32 func_02025C30(u32 a, u32 b, u32 c);

extern void TRADE_HISTORY_AddPartner(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);

extern u32 WIFI_HISTORY_GetCountryRegionState(const struct Sub02009470Obj *obj, int row, int col);

extern void WIFI_HISTORY_SetCountryRegionState(struct Sub02009470Obj *obj, int row, int col, int value);

extern void POKE_TOOL_HealFull(void *mon);

extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern u32 RECORD_AddOne(struct Sub02008C20Obj *obj, int i);

extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);

extern void TRADE_HISTORY_IncrementTradeCount(struct Sub02009D9CObj *obj);

extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);

extern void *POKE_TOOL_GetBoxParam(void *mon);

extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);

extern u32 sub_0201283C(const struct BigObj *p);

extern void WIFILIST_AddFriendBattleRecord(struct Sub020097BCObj *obj, int i, int a, int b, int c);

extern int WIFILIST_FindFriendByStatus(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);

extern void POKEPARTY_InitEx(struct Party *p, int capacity);

extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);

extern u8 func_020076A4(void *);

extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void FADE_Start(u32 a, int b, int c, int d);

extern void *GFL_NET_SAVE_CreateWithCallback(u32 heap, u32 a1, u32 a2, u32 a3);

extern u32 GFL_NET_SAVE_CheckFinished(struct Sub0201088CObj *p);

extern void GFL_NET_SAVE_Delete(struct Sub0201088CObj *p);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern void BG_SYS_SetMainVisiblePlanes(u32 planes);

extern void POKETRADE_2D_RegisterIconSpriteResources(int);

extern void POKETRADE_PROC_StepResetForNewRound(char *p);

extern void CLACT_DeleteActor(struct Obj *p);

extern void UI_SCENE_FreeActorGfx(unsigned int *p);

extern u32 func_020275E4(void);

extern u32 func_020275E8(void);

extern u32 func_020275F8(u32);

extern u32 func_020275FC(u32);

extern u32 func_02027600(u32);

extern u8 func_020275EC(int i);

extern void UI_SCENE_LoadActorGfx(void *,Descriptor *,int,u16);

extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern int func_02027720(int);

extern int func_0202772C(int);

extern int func_02027738(int,int);

extern int func_02027740(int,int);

extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern u32 BMP_WIN_Create(u32 layer, u8 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void GF_FONT_SetTextColor(u32,u32,u32);

extern signed char MSG_SPEED_GetWait(void);

extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);

extern void func_02028470(u8 *,u32);

extern void PRINTSYS_Print(void *,short,short,void *,void *);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void TIME_ICON_Delete(u8 *p);

extern u8 *TIME_ICON_CreateNode(u32 a, void *b, u8 c, u8 d, u16 e);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern u32 PRINTSYS_QUE_Create(void *p);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern void *func_02028590(u32,u32,u32,u32);

extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);

extern void func_0200566C(void);

extern int APP_KEYCURSOR_Delete(int a0);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void APP_TASKMENU_WIN_Delete(u8 *p);

extern unsigned int APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 GF_FONT_Delete(void *ptr);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void TCBL_Destroy(struct S02031140 *p);

extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);

extern int func_02028484(struct Blk *blk, void *h);

extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

extern void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon);

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void PRINTSYS_PrintColor(void *,short,short,int,int,int);

extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);

extern void WORDSET_SetSlotFromMsgCB(struct WordSet *p, u32 i, u32 v);

extern u8 func_02018598(void *p);

extern void WORDSET_SetSlotFromMsgB6(struct WordSet *p, u32 i, u32 v);

extern int POKETRADE_PROC_IsWifiMode(char *p);

extern void CLACT_SetActorBgPriority(void *,u32);

extern void POKETRADE_2D_DeleteTouchbarActors(int a);

extern void POKETRADE_2D_DeleteMarkingIcon(void *p);

extern void POKETRADE_2D_DeleteSummaryIcons(void *p);

extern void POKETRADE_2D_LoadMainPalette(int p);

extern void POKETRADE_2D_CreateTouchbarActors(char *p);

extern void func_020056A0(void (*)(void *,void *),void *,int);

extern void POKETRADE_2D_UploadWindowPalette(char *,int,u32);

extern void POKETRADE_2D_CreateMarkingIcon(char *,int,void *);

extern void POKETRADE_2D_CreatePokerusIcon(char *,int,int,void *);

extern void MCSS_ResetVanishFlag(void *);

extern void MCSS_SetVanishFlag(void *);

extern void POKETRADE_2D_CreateSummaryIcons(char *,void *,int);

extern void POKETRADE_2D_CreateOfferWindows(char *);

extern void POKETRADE_2D_CreateOfferIconActor(char *,int,int,void *,int,u32);

extern void POKETRADE_2D_UpdateOfferWindowActors(int p);

extern void POKETRADE_2D_DeleteOfferWindowActors(int p);

extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);

extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);

extern int POKETRADE_NEGO_HasOffer(char *);

extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);

extern void func_02048C58(struct LightSlot *slots);

extern void G3D_SYSTEM_SetProjection(const u32 *src);

extern void func_02048C4C(void *);

extern void func_02048AFC(void *,IntVec3 *);

extern void func_02048B44(void *,IntVec3 *);

extern void func_02048B6C(struct Light *l, const u32 *in);

extern void func_02048B20(void *,IntVec3 *);

extern void func_02048B60(struct Light *l, const u32 *in);

extern void MTX_Identity33_(MtxFx33 *m);

extern void ICA_ANIME_SetCameraPos(void *a0, void *a1);

extern void ICA_ANIME_SetCameraTarget(void *a0, void *a1);

extern void G3X_SetFog(int, int, int, int);

extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);

extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);

extern u32 ICA_ANIME_Get(struct IcaAnime *t, struct Rec12 *out);

extern void BUTTON_MAN_SetEmitterPos(void *obj, VecFx32 *v);

void POKETRADE_SAVE_FreeIfSet(u32 *p);

void POKETRADE_SAVE_SetWaitCounter(u8 *p, u32 v);

void POKETRADE_SAVE_PopBgmFadeIn60(void *p);

void POKETRADE_SAVE_PopBgm(void *p);

void POKETRADE_SAVE_PopBgmFadeIn24(void *p);

void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);

void POKETRADE_SAVE_StepEventMessage1(char *p);

void POKETRADE_SAVE_StepEventMessage2(char *p);

void POKETRADE_SAVE_StepWaitFade1(char *p);

void POKETRADE_SAVE_StepWaitFade2(char *p);

void POKETRADE_SAVE_StepWaitSyncRange(void *p);

void POKETRADE_SAVE_SendTradeSummary(char *p);

void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId);

void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf);

void *POKETRADE_SAVE_BackupZukan(void *src, u16 heapId);

void POKETRADE_SAVE_RestoreZukan(void *h, void *buf);

void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId);

void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst);

void POKETRADE_SAVE_FreeBackups(char *p);

void POKETRADE_SAVE_RestoreBackups(char *p);

int POKETRADE_SAVE_ConsumePerapVoice(char *p, void *party, int idx);

void POKETRADE_SAVE_ApplyTradeResult(char *p);

void POKETRADE_SAVE_StepAfterTrade(char *p);

void POKETRADE_SAVE_StepWaitEvolutionMessage(char *p);

void POKETRADE_SAVE_StepRegisterReceived(char *p);

void POKETRADE_SAVE_StepCheckEvolution(char *p);

void POKETRADE_SAVE_StepSaveCancelNotice(char *p);

void POKETRADE_SAVE_StepBeginSyncRange24(void *p);

void POKETRADE_SAVE_StepWaitSyncRange24(void *p);

void POKETRADE_SAVE_StepStartSave(char *p);

void POKETRADE_SAVE_StepWaitSaveDone(char *p);

void POKETRADE_SAVE_StepBeginWipeOut(char *p);

void POKETRADE_SAVE_StepRebuildSceneAfterWipe(char *p);

void POKETRADE_SAVE_DeleteTypeIconActor(char *p);

void POKETRADE_SAVE_CreateTypeIconActor(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b);

void POKETRADE_SAVE_DeleteStatusIconActor(char *p);

void POKETRADE_SAVE_CreateStatusIconActor(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c);

void POKETRADE_SAVE_OpenMessageWindow(char *p,int flag,int x,int y,int w,int h);

void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag);

void POKETRADE_SAVE_OpenMessageWindowTop(void *p);

void POKETRADE_SAVE_ShowTimeIcon(char *p);

void POKETRADE_SAVE_CloseMessageWindow(char *p);

void POKETRADE_SAVE_CloseMessageWindowClear(char *p);

void POKETRADE_SAVE_CreateMessageResources(char *p);

void POKETRADE_SAVE_DeleteMessageResources(char *p);

int POKETRADE_SAVE_IsMessagePrintDone(char *p);

void POKETRADE_SAVE_CloseTaskMenu(char *p);

void POKETRADE_SAVE_OpenTaskMenuAt(char *p,int *ids,int count,int x,int y);

void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);

void POKETRADE_SAVE_PrintNickname(void *a,void *b,int x,int y,int flag,int mode,char *p);

void POKETRADE_SAVE_PrintDexNumber(void *a,void *b,int x,int y,int flag,char *p);

void POKETRADE_SAVE_PrintSpeciesName(void *a,void *b,int x,int y,int flag,char *p);

void POKETRADE_SAVE_PrintLevel(void *a,void *b,int x,int y,char *p);

void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,char *p,int mode,int guard);

void POKETRADE_SAVE_PrintStatLabels(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_PrintHeldItem(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_PrintHpValues(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_PrintStatValues(int a, int b, int c, int d, char *p);

void POKETRADE_SAVE_PrintAbilityLabel(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_PrintMoveNames(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_PrintNatureName(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_PrintExperience(int a,int b,int x,int y,char *p);

void POKETRADE_SAVE_DrawOfferCardWindow(char *p,int i,void *mon);

void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);

void POKETRADE_SAVE_DeleteTypeIcons(char *p);

void POKETRADE_SAVE_CloseSummaryPage(void *p, int a1);

void POKETRADE_SAVE_OpenSummaryScreen(char *p,void *a);

void POKETRADE_SAVE_DrawSummaryPage(char *p,int mode,void *mon);

void POKETRADE_SAVE_PrepareSummaryWindow(char *p, void *a, int b, int a3);

void POKETRADE_SAVE_CreateTypeIcons(char *p,void *mon,IntQuad *t);

void POKETRADE_SAVE_ToggleTypeIconSet(char *p,int a);

void POKETRADE_SAVE_ShowSummaryMon(char *p,void *mon,int side,int flag);

void POKETRADE_SAVE_DeleteOfferCardWindow(char *p,int i);

void POKETRADE_SAVE_CloseSummaryWindow(char *p,int a);

void POKETRADE_SAVE_DrawOfferListWindows(char *p, int a1);

void POKETRADE_SAVE_DeleteOfferListWindows(char *p);

void POKETRADE_SAVE_SetupWindowRegsSummary(void *a0);

void POKETRADE_SAVE_DrawPartnerOfferCard(char *p,int i,void *mon);

void POKETRADE_SAVE_DeletePartnerOfferCard(char *p,int i);

void *POKETRADE_SAVE_OpenTaskMenuWindow(char *p,int a);

void POKETRADE_SAVE_CloseTaskMenuWindow(char *p,int a,int b);

int POKETRADE_SAVE_IsTouchOutsideArea(void *a0);

void POKETRADE_SAVE_VBlankSetupWindowRegs(void *a,char *p);

void POKETRADE_SAVE_Init3DProjection(int a);

void POKETRADE_SAVE_Free3DLightSet(void);

void POKETRADE_SAVE_SetCameraSummary(char *p);

void POKETRADE_SAVE_SetCameraTrade(char *p);

void POKETRADE_SAVE_Update3DParticles(char *p);

void POKETRADE_SAVE_Setup3DDrawState(DrawState3D *w, Transform *t);

void POKETRADE_3D_AddUnitAndInit(void *p, int a);

void POKETRADE_3D_RemoveCurrentUnit(void *p);

void POKETRADE_3D_AddPokemonMcss(TradeWork *p, int idx, int side, void *mon, int flag);

void POKETRADE_3D_DeleteMcssSlot(void *p, int idx);

void POKETRADE_3D_DrawRotatingCube(const u8 *p);

void POKETRADE_3D_CreateTouchbar(char *p);

void POKETRADE_2D_InitClactSystemSub(void *p);

void POKETRADE_2D_LoadBackgroundGfx(char *p);

void POKETRADE_2D_LoadSubBackgroundGfx(char *p);

void POKETRADE_2D_NoOp(void *p);

void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p);

void POKETRADE_2D_CreateFontResource(char *p);

void POKETRADE_2D_LoadSummaryBackground(char *p, int a1, int a2);

void POKETRADE_2D_CreateBoxWindows(char *p);

void POKETRADE_2D_CreateBoxIconActors(char *p);

void POKETRADE_2D_ExitSummaryBgs(int p);

extern const char gSaveControlAllocTag[];

extern const char gSaveBufferAllocTag[];

extern const char gMailBufferAllocTag[];

extern const T5 gStatValueLabels;

extern const IntPair gOfferCardWindowPosA,gOfferCardWindowPosB,gOfferCardWindowPosC;

extern const IntVec2 gSummaryPagePosA, gSummaryPagePosB;

extern const IntQuad gTypeIconSetA,gTypeIconSetB;

extern const Pair gPartnerOfferCardPosA,gPartnerOfferCardPosB,gPartnerOfferCardPosC;

extern const U32Quad gPartnerOfferColors;

extern const char gOutsideAreaHitRect[];

extern const IntOctet gProjectionConfig;

extern char gLightSet[];

extern void *gLightSetHandle;

extern short gProjectionParams[];

extern char gDrawLightTable[];

#define I(p, o) (*(void **)((p) + (o)))

void POKETRADE_SAVE_FreeIfSet(u32 *p) { if (p) { func_020307B0((void *)((u32)p)); } }

void POKETRADE_SAVE_SetWaitCounter(u8 *p, u32 v) { (*(unsigned int *)&((TradeWork *)p)->waitCounter) = v; }

/*
 * Decrement the +0x11f8 guard byte (both its condition and the store use
 * that same pool word) and pulse the 0x3c delay. Non-SDK dep of
 * POKETRADE_SAVE_ResetClactAndBeginEvent's case-5/6 arms.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_SAVE_PopBgmFadeIn60(void *p)
{
    u8 *b = p;

    if (((TradeWork *)b)->sceneState != 0) {
        GFL_USE_PopBgm();
        ((TradeWork *)b)->sceneState -= 1;
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}

void POKETRADE_SAVE_PopBgm(void *p)
{
    u8 *b = p;

    GFL_USE_PopBgm();
    ((TradeWork *)b)->sceneState -= 1;
}

void POKETRADE_SAVE_PopBgmFadeIn24(void *p)
{
    u8 *b = p;

    GFL_USE_PopBgm();
    ((TradeWork *)b)->sceneState -= 1;
    GFL_USE_SetBgmPlayerParam(0);
    GFL_USE_FadeInBgmFull(0x18);
}

/*
 * Slot-state teardown/rebuild, dispatched on *(p+0x118c): 5 and 6 run the
 * shared +8 slot teardown and hand POKETRADE_PROC_SetStep either POKETRADE_PROC_StepBeginWipeOut or
 * NULL; the default path increments the +0x11f8 byte and hands
 * POKETRADE_SAVE_StepEventMessage1. Target of func_021D6C78's ABS32 callback argument (ov119).
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p)
{
    u8 *b = p;
    int st;

    CLACT_DeleteUnit((*(void * *)&((TradeWork *)b)->clactSystem));
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemSub(p);
    (*(void * *)&((TradeWork *)b)->clactSystem) = CLACT_CreateUnit(0x154, 0, ((TradeWork *)b)->heapId);
    st = ((TradeWork *)b)->tradeState;
    if (st == 5) {
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        ((TradeWork *)b)->request->state = 3;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
    } else if (st == 6) {
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        ((TradeWork *)b)->request->state = 3;
        POKETRADE_PROC_SetStep(p, 0);
    } else {
        POKETRADE_SAVE_CreateMessageResources(p);
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        (((TradeWork *)b)->sceneState)++;
        GFL_USE_FadeOutBgm(6);
        ((TradeWork *)b)->waitCounter = 0;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepEventMessage1);
    }
}

/*
 * lever: Repeat the message call in each arm; an id local factors the argument loads and is 20 bytes short.
 */
void POKETRADE_SAVE_StepEventMessage1(char *p)
{
    void *mon;
    int z,state;
    if(((TradeWork *)p)->waitCounter<6) return;
    GFL_USE_CancelChangeAndPlayBgm(0x518,0xffff);
    GFL_USE_FadeInBgmFull(6);
    state=((TradeWork *)p)->tradeState;
    if(state==7) func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),153,(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));
    else if(state==8) func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),156,(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));
    else if(((TradeWork *)p)->offlineFlag) func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),131,(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));
    else func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),48,(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));
    if(POKETRADE_PROC_IsHostSide(p)) mon=POKETRADE_PROC_GetSideMon(p,0);
    else mon=POKETRADE_PROC_GetSideMon(p,1);
    WORDSET_SetSlotMonSpecies((*(void * *)&((TradeWork *)p)->wordSet),1,mon);
    z=0;
    WORDSET_SetSlotMyStatus((struct WordSet *)(((TradeWork *)p)->wordSet),0,(void *)(((TradeWork *)p)->playerStatus));
    WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->messageText),(void *)((*(int *)&((TradeWork *)p)->messageTemplate)));
    (*(int *)&((TradeWork *)p)->fontBgHandle)=(int)BMP_MENUWORK_LoadFrameGfx((void *)6,15,0,((TradeWork *)p)->heapId);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p,1,0);
    POKETRADE_SAVE_SetWaitCounter((u8 *)p,0);
    func_02040588(6,1);
    ((TradeWork *)p)->waitCounter=z;
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepEventMessage2);
}

/*
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 */
void POKETRADE_SAVE_StepEventMessage2(char *p)
{
    void *a;
    if (((TradeWork *)p)->waitCounter < 0xC8) {
        return;
    }
    if (POKETRADE_PROC_IsHostSide(p)) {
        a = POKETRADE_PROC_GetSideMon(p, 0);
    } else {
        a = POKETRADE_PROC_GetSideMon(p, 1);
    }
    WORDSET_SetSlotMonSpecies((*(void * *)&((TradeWork *)p)->wordSet), 1, a);
    WORDSET_SetSlotMyStatus((*(void * *)&((TradeWork *)p)->wordSet), 0, (void *)(((TradeWork *)p)->playerStatus));
    if (((TradeWork *)p)->tradeState != 7 && ((TradeWork *)p)->tradeState != 8) {
        if (((TradeWork *)p)->offlineFlag) {
            func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x84, ((TradeWork *)p)->messageTemplate);
            WORDSET_CopyTaggedText((*(void * *)&((TradeWork *)p)->wordSet), (*(void * *)&((TradeWork *)p)->messageText), ((TradeWork *)p)->messageTemplate);
            POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
        } else {
            func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x31, ((TradeWork *)p)->messageTemplate);
            WORDSET_CopyTaggedText((*(void * *)&((TradeWork *)p)->wordSet), (*(void * *)&((TradeWork *)p)->messageText), ((TradeWork *)p)->messageTemplate);
            POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
        }
    }
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepWaitFade1);
}

void POKETRADE_SAVE_StepWaitFade1(char *p)
{
    if (((TradeWork *)p)->waitCounter >= 0x10e) {
        POKETRADE_SAVE_PopBgmFadeIn24(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepWaitFade2);
    }
}

void POKETRADE_SAVE_StepWaitFade2(char *p)
{
    if (((TradeWork *)p)->waitCounter >= 0x1a4) {
        POKETRADE_SAVE_SetWaitCounter((u8 *)p, 0);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepAfterTrade);
    }
}

void POKETRADE_SAVE_StepWaitSyncRange(void *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, 8)) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepRegisterReceived);
    }
}

void POKETRADE_SAVE_SendTradeSummary(char *p)
{
    struct Packet packet;
    void *saved,*first,*second;
    saved=func_02009470(GAME_DATA_GetSaveControl(((TradeWork *)p)->gameData));
    if(POKETRADE_PROC_IsHostSide(p)) {
        first=POKETRADE_PROC_GetSideMon(p,0);
        second=POKETRADE_PROC_GetSideMon(p,1);
    } else {
        first=POKETRADE_PROC_GetSideMon(p,1);
        second=POKETRADE_PROC_GetSideMon(p,0);
    }
    MYSTATUS_Copy(func_02012944(((TradeWork *)p)->gameData),&packet);
    packet.first=func_02017E1C(first,5,0);
    packet.second=func_02017E1C(second,5,0);
    packet.a=func_02009628(saved);
    packet.b=WIFI_HISTORY_GetVisitedCountryCount(saved);
    packet.mode=func_0200960C(saved);
    if(POKETRADE_PROC_IsNetSession(p)) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc12,40,(u32)(&packet))) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),23,8);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepWaitSyncRange);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginWipeOut);
}

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId)
{
    void *h = GAME_DATA_GetSaveControl(sys);
    void *buf = GFL_HEAP_Alloc(heapId, GAME_SYNC_GetBlockSize(), 0, gSaveControlAllocTag, 0x1A0);

    GFL_STD_MemCopy(func_02009470(h), buf, GAME_SYNC_GetBlockSize());
    return buf;
}

void POKETRADE_SAVE_RestoreSaveControl(void *sys, void *buf)
{
    void *src = func_02009470(GAME_DATA_GetSaveControl(sys));
    MI_CpuCopy8(buf, src, GAME_SYNC_GetBlockSize());
    func_020307B0(buf);
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
    func_020307B0(buf);
}

void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, TRADE_HISTORY_GetSize(), 0, gSaveControlAllocTag, 0x1DA);

    GFL_STD_MemCopy(GAME_DATA_GetSaveBlock1F(sys), buf, TRADE_HISTORY_GetSize());
    return buf;
}

void POKETRADE_SAVE_RestoreBlock1F(void **h, void *dst)
{
    void *src = GAME_DATA_GetSaveBlock1F(h);
    MI_CpuCopy8(dst, src, func_02009D9C());
    func_020307B0(dst);
}

void POKETRADE_SAVE_FreeBackups(char *p)
{
    int zero;
    if (((TradeWork *)p)->saveControlBackup) func_020307B0(((TradeWork *)p)->saveControlBackup);
    if (((TradeWork *)p)->trainerRecordBackup) func_020307B0(((TradeWork *)p)->trainerRecordBackup);
    if (((TradeWork *)p)->savedSaveControl) func_020307B0(((TradeWork *)p)->savedSaveControl);
    if (((TradeWork *)p)->savedZukan) func_020307B0(((TradeWork *)p)->savedZukan);
    if (((TradeWork *)p)->savedBlock1F) func_020307B0(((TradeWork *)p)->savedBlock1F);
    if (((TradeWork *)p)->partyBackup) func_020307B0(((TradeWork *)p)->partyBackup);
    if (((TradeWork *)p)->boxBackup) func_020307B0(((TradeWork *)p)->boxBackup);
    zero=0;
    MI_CpuFill8(p+0x60c,zero,36);
    p[0x11f7]=zero;
}

void POKETRADE_SAVE_RestoreBackups(char *p)
{
    void *dest,*src;
    u32 n;
    dest=((TradeWork *)p)->saveControlBackup;
    if(dest) {
        src=((TradeWork *)p)->gameData;
        GAME_DATA_GetSaveControl(src);
        src=func_02008FEC(src);
        n=func_02008FFC();
        MI_CpuCopy8(dest,src,n);
        func_020307B0(dest);
    }
    dest=((TradeWork *)p)->trainerRecordBackup;
    if(dest) {
        src=GAME_DATA_GetTrainerRecord(((TradeWork *)p)->gameData);
        n=func_02008C20();
        MI_CpuCopy8(dest,src,n);
        func_020307B0(dest);
    }
    if(((TradeWork *)p)->savedSaveControl) POKETRADE_SAVE_RestoreSaveControl(((TradeWork *)p)->gameData,((TradeWork *)p)->savedSaveControl);
    if(((TradeWork *)p)->savedZukan) POKETRADE_SAVE_RestoreZukan(((TradeWork *)p)->gameData,((TradeWork *)p)->savedZukan);
    if(((TradeWork *)p)->savedBlock1F) POKETRADE_SAVE_RestoreBlock1F(((TradeWork *)p)->gameData,((TradeWork *)p)->savedBlock1F);
    if(((TradeWork *)p)->partyBackup) {
        POKEPARTY_Copy(((TradeWork *)p)->partyBackup,((TradeWork *)p)->partyData);
        func_020086F8((void *)GAME_DATA_GetPlayTime((int)(((TradeWork *)p)->gameData)),(const struct PlayTimeStamp *)(p+0x628));
        func_020307B0(((TradeWork *)p)->partyBackup);
        *(int *)&((TradeWork *)p)->partyBackup=0;
    }
    if(((TradeWork *)p)->boxBackup) {
        n=func_02007AEC();
        src=func_02007AF4((*(void * *)&((TradeWork *)p)->boxManager),((TradeWork *)p)->request->box);
        MI_CpuCopy8(((TradeWork *)p)->boxBackup,src,n);
        func_020307B0(((TradeWork *)p)->boxBackup);
    }
    if(((TradeWork *)p)->boxSaveDirty) func_02007B5C((struct PerapVoice *)GAME_DATA_GetBoxSave(((TradeWork *)p)->gameData));
    MI_CpuFill8(p+0x60c,0,0x24);
}

int POKETRADE_SAVE_ConsumePerapVoice(char *p, void *party, int idx)
{
    int count = 0;
    int i, n;
    void *voice = GAME_DATA_GetBoxSave(((TradeWork *)p)->gameData);

    if (!PERAPVOICE_IsRecorded(voice))
        return count;
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        if (func_02017E1C(POKEPARTY_GetMember(party, i), 5, 0) == 0x1B9)
            count++;
    }
    if (count != 1)
        return 0;
    count = 0;
    if (func_02017E1C(POKEPARTY_GetMember(party, idx), 5, 0) == 0x1B9) {
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
void POKETRADE_SAVE_ApplyTradeResult(char *p)
{
    void *mon;
    void *obj;
    void *list[2];
    int i;
    int out;

    if (POKETRADE_PROC_IsHostSide(p) == 0) {
        I(p, 0x60C) = copy_a(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x610) = copy_b(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x614) = POKETRADE_SAVE_BackupSaveControl(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x618) = POKETRADE_SAVE_BackupZukan(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x61C) = POKETRADE_SAVE_BackupBlock1F(I(p, 0x82C), H(p, 0x5F4));
        PLAYTIME_GetStamp((void *)GAME_DATA_GetPlayTime((int)I(p, 0x82C)), (struct PlayTimeStamp *)(p + 0x628));
        if (T(p)->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            I(p, 0x620) = POKEPARTY_Create(H(p, 0x5F4));
            POKEPARTY_Copy(I(p, 0x838), I(p, 0x620));
            W(p, 0x62C) = POKETRADE_SAVE_ConsumePerapVoice(p, I(p, 0x838), T(p)->slot);
        } else {
            I(p, 0x624) = GFL_HEAP_Alloc(H(p, 0x5F4), BOX_SAVEDATA_GetBoxPageSize(), 0, gSaveControlAllocTag, 0x271);
            GFL_STD_MemCopy(BOX_SAVEDATA_GetBoxPokemon(I(p, 0x828), T(p)->box), I(p, 0x624), BOX_SAVEDATA_GetBoxPageSize());
        }
    } else {
        Trade *t = T(p);
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828)))
            POKETRADE_SAVE_ConsumePerapVoice(p, I(p, 0x838), t->slot);
        p[0x11F7] = 1;
    }

    {
        Trade *t = T(p);
        if (t->box != BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            mon = POKEPARTY_GetMember(t->party, 0);
            if (FILE_UTIL_Check136C(func_02017E1C(mon, 6, 0))) {
                void *o = MAIL_GetBox(I(p, 0x82C));
                int idx = MAIL_FindEmptySlot(o, 0);
                if (idx != -1) {
                    void *buf = MAIL_Create(H(p, 0x5F4));
                    func_02017E1C(mon, 0xA7, (u32)buf);
                    MAIL_SetSlot(o, 0, idx, buf);
                    func_02008EAC(buf);
                    POKE_TOOL_SetPartyValue(mon, 0xA7, (u32)buf);
                    POKE_TOOL_SetPartyValue(mon, 6, 0);
                    func_020307B0(buf);
                }
            }
        }
    }

    {
        u8 a = func_0200856C(I(p, 0x834));
        u8 b = func_02008570(I(p, 0x834));
        u32 ra = func_02025C1C(a, b, func_02008564(I(p, 0x834)));
        u32 rb = func_02025C30(a, b, func_02008564(I(p, 0x834)));
        if (a != ra || b != rb)
            func_02008574(I(p, 0x834), 0, 0);
    }

    TRADE_HISTORY_AddPartner(GAME_DATA_GetSaveBlock1F(I(p, 0x82C)), I(p, 0x834));
    obj = func_02009470(GAME_DATA_GetSaveControl(I(p, 0x82C)));
    list[0] = I(p, 0x830);
    list[1] = I(p, 0x834);
    for (i = 0; i < 2; i++) {
        void *q = list[i];
        if (q) {
            u8 row = func_0200856C(q);
            u8 col = func_02008570(q);
            func_02008564(q);
            if (!WIFI_HISTORY_GetCountryRegionState(obj, row, col))
                WIFI_HISTORY_SetCountryRegionState(obj, row, col, 1);
        }
    }

    mon = POKEPARTY_GetMember(T(p)->party, 0);
    obj = GAME_DATA_GetTrainerRecord(I(p, 0x82C));
    POKE_TOOL_HealFull(mon);
    if (func_02017E1C(mon, 0x4C, 0) == 0)
        POKE_TOOL_SetPartyValue(mon, 9, (u32)((void *)0x46));
    if (func_02017E1C(mon, 0x4C, 0))
        func_0202F190(mon, 6, (u32)I(p, 0x830), 0x7533, H(p, 0x5F4));
    switch (W(p, 0x118C)) {
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
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(I(p, 0x82C)), mon);
    if (W(p, 0x118C) == 3)
        TRADE_HISTORY_IncrementTradeCount(GAME_DATA_GetSaveBlock1F(I(p, 0x82C)));
    if (func_02017E1C(mon, 5, 0) == 0x1EC && func_02017E1C(mon, 0x6F, 0) == 1) {
        POKE_TOOL_ChangeForm(mon, 0);
        ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(I(p, 0x82C)), mon);
    }
    {
        Trade *t = T(p);
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            POKEPARTY_SetMember(I(p, 0x838), t->slot, mon);
        } else {
            t = T(p);
            func_020075B0(I(p, 0x828), t->box, t->slot, POKE_TOOL_GetBoxParam(mon));
        }
    }
    switch (W(p, 0x118C)) {
    case 2:
        WIFILIST_AddFriendBattleRecord((void *)sub_0201283C(I(p, 0x82C)), T(p)->count - 1, 0, 0, 1);
        break;
    case 0:
    case 1:
        if (WIFILIST_FindFriendByStatus((void *)sub_0201283C(I(p, 0x82C)), I(p, 0x834), (u32 *)(&out)))
            WIFILIST_AddFriendBattleRecord((void *)sub_0201283C(I(p, 0x82C)), out, 0, 0, 1);
        break;
    }
}

void POKETRADE_SAVE_StepAfterTrade(char *p)
{
    int state;
    POKETRADE_3D_DeleteMcssSlot(p,0);POKETRADE_3D_DeleteMcssSlot(p,1);
    POKETRADE_3D_DeleteMcssSlot(p,2);POKETRADE_3D_DeleteMcssSlot(p,3);
    state=((TradeWork *)p)->tradeState;
    if(state==4 || (unsigned)(state-7)<=1) {
        ((TradeWork *)p)->request->state=3;
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);
        return;
    }
    if((unsigned)(state-1)<=2) {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_SendTradeSummary);
        return;
    } else {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepRegisterReceived);
        return;
    }
}

void POKETRADE_SAVE_StepWaitEvolutionMessage(char *p)
{
    if (POKETRADE_SAVE_IsMessagePrintDone(p) && ((TradeWork *)p)->waitCounter > 0xB4) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepCheckEvolution);
    }
}

void POKETRADE_SAVE_StepRegisterReceived(char *p)
{
    int i;
    void *mon;
    int z;
    struct TradeRequest *t;
    if(POKETRADE_PROC_IsHostSide(p)) {
        i=((TradeWork *)p)->offerCount%3;
        mon=POKETRADE_PROC_GetSideMon(p,0);
        ((TradeWork *)p)->request->box=((TradeWork *)p)->offerBox[0][i];
        ((TradeWork *)p)->request->slot=((TradeWork *)p)->offerSlot[0][i];
    } else {
        mon=POKETRADE_PROC_GetSideMon(p,1);
        ((TradeWork *)p)->request->box=((TradeWork *)p)->selectedBox;
        ((TradeWork *)p)->request->slot=((TradeWork *)p)->selectedSlot;
    }
    POKEPARTY_InitEx(((TradeWork *)p)->request->party,6);
    POKEPARTY_Add(((TradeWork *)p)->request->party,mon);
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(((TradeWork *)p)->gameData),mon);
    t=((TradeWork *)p)->request;
    if(t->box!=func_020076A4((*(void * *)&((TradeWork *)p)->boxManager))) {
        z=0;
        if(FILE_UTIL_Check136C(func_02017E1C(POKEPARTY_GetMember(t->party,0),6,0))) {
            func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),106,(void *)(((TradeWork *)p)->messageText));
            POKETRADE_SAVE_OpenMessageWindowTop(p);
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepWaitEvolutionMessage);
            ((TradeWork *)p)->waitCounter=z;
            return;
        }
    }
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepCheckEvolution);
}

/*
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 */
void POKETRADE_SAVE_StepCheckEvolution(char *p)
{
    void *a,*b;
    u32 out,result;
    if(*(int *)&((TradeWork *)p)->gameData==0) {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginWipeOut);
        goto exit;
    }
    else {
    if(*(int *)&((TradeWork *)p)->request!=0) {
        if(POKETRADE_PROC_IsHostSide(p)) {a=POKETRADE_PROC_GetSideMon(p,0);b=POKETRADE_PROC_GetSideMon(p,1);}
        else {a=POKETRADE_PROC_GetSideMon(p,1);b=POKETRADE_PROC_GetSideMon(p,0);}
        result=SHINKA_CHECK_CheckEvolution(0,a,1,(u32)b,GAME_DATA_GetSeason(((TradeWork *)p)->gameData),&out,((TradeWork *)p)->heapId);
        if(result) {
            ((TradeWork *)p)->request->state=1;
            ((TradeWork *)p)->request->evolveResult=result;
            ((TradeWork *)p)->request->evolveOut=out;
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);
            POKETRADE_SAVE_PopBgm(p);
            return;
        }
    }
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),50,(void *)(((TradeWork *)p)->messageText));
    POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginSyncRange24);
    }
exit:
    POKETRADE_SAVE_PopBgmFadeIn60(p);
}

void POKETRADE_SAVE_StepSaveCancelNotice(char *p) {POKETRADE_SAVE_CreateMessageResources(p);func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),50,(void *)(((TradeWork *)p)->messageText));*(int *)&((TradeWork *)p)->fontBgHandle=(int)BMP_MENUWORK_LoadFrameGfx((void *)6,15,0,((TradeWork *)p)->heapId);POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);POKETRADE_SAVE_SetWaitCounter((u8 *)p,0);func_02040588(6,1);GFL_NET_RestartWithDefaultTimeout(1,((TradeWork *)p)->heapId);FADE_Start(3,16,0,2);POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginSyncRange24);}

void POKETRADE_SAVE_StepBeginSyncRange24(void *p)
{
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepWaitSyncRange24);
}

void POKETRADE_SAVE_StepWaitSyncRange24(void *p)
{
    if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x18, 8)) {
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepStartSave);
    }
}

void POKETRADE_SAVE_StepStartSave(char *p) {if(POKETRADE_SAVE_IsMessagePrintDone(p)) {if(POKETRADE_PROC_IsNetSession(p)) {POKETRADE_SAVE_ApplyTradeResult(p);((TradeWork *)p)->netSave=(int)GFL_NET_SAVE_CreateWithCallback(((TradeWork *)p)->heapId,*(int *)&((TradeWork *)p)->gameData,(u32)POKETRADE_SAVE_FreeBackups,(u32)p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepWaitSaveDone);return;}POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginWipeOut);}}

/*
 * 2026-10-02: byte-correct; the call to the tail-call stub 0x02010934 (inside
 * matched unit_0201088C) now resolves since that stub was seeded as a start.
 */
void POKETRADE_SAVE_StepWaitSaveDone(char *p)
{
    if (GFL_NET_SAVE_CheckFinished((*(void * *)&((TradeWork *)p)->netSave))) {
        POKETRADE_SAVE_RestoreBackups(p);
        GFL_NET_SAVE_Delete((*(void * *)&((TradeWork *)p)->netSave));
        ((TradeWork *)p)->netSave = 0;
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepBeginWipeOut);
    }
}

void POKETRADE_SAVE_StepBeginWipeOut(char *p) {int z;WIPE_SYS_Start(0,0,0,0,6,1,((TradeWork *)p)->heapId);z=0;((TradeWork *)p)->waitCounter=z;p[0x11f7]=z;POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepRebuildSceneAfterWipe);}

void POKETRADE_SAVE_StepRebuildSceneAfterWipe(char *p)
{
    if(((TradeWork *)p)->waitCounter>=6 && WIPE_SYS_EndCheck()) {
        if(((TradeWork *)p)->fontBgHandle) BG_SYS_DeleteHalf((int)6,(u16)(((TradeWork *)p)->fontBgHandle),(u16)(((TradeWork *)p)->fontBgHandle>>16));
        *(int *)&((TradeWork *)p)->fontBgHandle=0;
        BG_SYS_SetMainVisiblePlanes((int)0);BG_SYS_SetSubVisiblePlanes((int)0);
        CLACT_DeleteUnit((*(void * *)&((TradeWork *)p)->clactSystem));
        (*(void * *)&((TradeWork *)p)->clactSystem)=CLACT_CreateUnit(0x154,0,((TradeWork *)p)->heapId);
        POKETRADE_SAVE_CloseMessageWindow(p);POKETRADE_2D_ExitSubBgs((int)p);POKETRADE_2D_ExitSummaryBgs((int)p);
        POKETRADE_2D_SetDisplayConfig(0);POKETRADE_2D_SetupSubBgs(p);POKETRADE_2D_RegisterIconSpriteResources((int)p);
        POKETRADE_2D_CreateBoxIconActors(p);POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_LoadBackgroundGfx(p);
        POKETRADE_2D_CreateFontResource(p);POKETRADE_2D_LoadMainGfxAndMessageWindow(p);POKETRADE_3D_AddUnitAndInit(p,0);
        BG_SYS_SetMainVisiblePlanes((int)31);BG_SYS_SetSubVisiblePlanes((int)30);POKETRADE_3D_CreateTouchbar(p);
        GFL_NET_RestartWithDefaultTimeout(1,((TradeWork *)p)->heapId);
        ((TradeWork *)p)->netExitCount=0;
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetForNewRound);
    }
}

void POKETRADE_SAVE_DeleteTypeIconActor(char *p)
{
    if (((struct UiScene *)p)->actor) {
        CLACT_DeleteActor(((struct UiScene *)p)->actor);
        *(int *)&((struct UiScene *)p)->actor = 0;
        UI_SCENE_FreeActorGfx((unsigned int *)p);
    }
}

void POKETRADE_SAVE_CreateTypeIconActor(char *p,void *mon,int index,int slot,int x,int y,int a,u16 b) {Descriptor d;u8 v;int z=0;v=func_02017E1C(mon,index+174,0);d.a=a;d.b=z;d.c=func_020275E4();d.d=func_020275E8();d.e=func_020275F8(v);d.f=func_020275FC(2);d.g=func_02027600(2);d.h=8;d.i=z;d.j=3;UI_SCENE_LoadActorGfx(p,&d,slot,b);((struct UiScene *)p)->actor=(void *)UI_SCENE_CreateActor(p,slot,x,y,z,b);CLACT_SetActorPaletteOffset((struct Obj *)(((struct UiScene *)p)->actor),func_020275EC(v),1);}

void POKETRADE_SAVE_DeleteStatusIconActor(char *p)
{
    if (((struct UiScene *)p)->actor) {
        CLACT_DeleteActor(((struct UiScene *)p)->actor);
        *(int *)&((struct UiScene *)p)->actor = 0;
        UI_SCENE_FreeActorGfx((unsigned int *)p);
    }
}

/*
 * extent: two zero alignment bytes at 0x021E0EF2, labelled next function 0x021E0EF4.
 */
void POKETRADE_SAVE_CreateStatusIconActor(char *p,void *mon,int slot,int x,int y,int a,u16 b,int c) {Descriptor d;int v;v=func_02017E1C(mon,152,0);POKETRADE_SAVE_DeleteStatusIconActor(p);d.a=a;d.b=0;d.c=func_020275E4();d.d=func_02027720(v);d.e=func_0202772C(v);d.f=func_02027738(v,2);d.g=func_02027740(v,2);d.h=c;d.i=0;d.j=1;UI_SCENE_LoadActorGfx(p,&d,slot,b);*(int *)&((struct UiScene *)p)->actor=UI_SCENE_CreateActor(p,slot,x,y,0,b);}

/*
 * prototype: 0201F73C arg2 is u16 because 021E0FC4..021E0FC6 truncates the loaded full word before the call.
 * prototype: 0201CCE4 forwarding wrapper leaves r0 live; caller stores it at 021E0F94 despite legacy void declaration.
 */
void POKETRADE_SAVE_OpenMessageWindow(char *p,int flag,int x,int y,int w,int h)
{
    void *v;
    POKETRADE_SAVE_CloseMessageWindow(p);
    func_02049B40(23,5,4,448,32,((TradeWork *)p)->heapId);
    v=(void *)BMP_WIN_Create(6,(u8)x,(u8)y,(u8)w,h,(u32)14,(u32)0);
    (*(void * *)&((TradeWork *)p)->messageWin)=v;
    BMP_Clear(BMP_WIN_GetBmp(v),15);
    GF_FONT_SetTextColor(1,2,15);
    if(flag==0) {
        (*(unsigned int *)&((TradeWork *)p)->printStream)=PRINTSYS_PrintStream((u32)v,0,0,*(u32 *)&((TradeWork *)p)->messageText,*(u32 *)&((TradeWork *)p)->font,MSG_SPEED_GetWait(),(*(unsigned int *)&((TradeWork *)p)->tcbl),2,((TradeWork *)p)->heapId,15);
        func_02028470((u8 *)p+0x11d4,2);
    } else {
        PRINTSYS_Print(BMP_WIN_GetBmp(v),0,0,(*(void * *)&((TradeWork *)p)->messageText),((TradeWork *)p)->font);
    }
    BMP_MENUWORK_DrawWindow(v,1,(u16)(((TradeWork *)p)->fontBgHandle),15);
    BMP_WIN_TransferChars(v);BMP_WIN_MakeScreen(v);func_02041B6C(6);
}

void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int flag)
{
    if (flag) {
        POKETRADE_SAVE_OpenMessageWindow(p, a, 1, 0x12, 0x1E, 4);
        return;
    }
    POKETRADE_SAVE_OpenMessageWindow(p, a, 1, 1, 0x1E, 4);
}

void POKETRADE_SAVE_OpenMessageWindowTop(void *p) { POKETRADE_SAVE_OpenMessageWindowAtPos(p, 0, 0); }

void POKETRADE_SAVE_ShowTimeIcon(char *p)
{
    if (((TradeWork *)p)->timeIcon) {
        TIME_ICON_Delete(((TradeWork *)p)->timeIcon);
        ((TradeWork *)p)->timeIcon = 0;
    }
    ((TradeWork *)p)->timeIcon = TIME_ICON_CreateNode((u32)(((TradeWork *)p)->tcbl), (*(void * *)&((TradeWork *)p)->messageWin), 0xF, 0x10, ((TradeWork *)p)->heapId);
}

void POKETRADE_SAVE_CloseMessageWindow(char *p)
{
    if (((TradeWork *)p)->timeIcon) {
        TIME_ICON_Delete(((TradeWork *)p)->timeIcon);
        ((TradeWork *)p)->timeIcon = 0;
    }
    if ((*(void * *)&((TradeWork *)p)->messageWin)) {
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->messageWin));
        (*(void * *)&((TradeWork *)p)->messageWin) = 0;
    }
}

void POKETRADE_SAVE_CloseMessageWindowClear(char *p) { if(*(int *)&((TradeWork *)p)->timeIcon) {TIME_ICON_Delete((u8 *)(*(int *)&((TradeWork *)p)->timeIcon));*(int *)&((TradeWork *)p)->timeIcon=0;} if(((TradeWork *)p)->messageWin) {BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->messageWin));func_02041B6C(6);BMP_MENUWORK_DrawWindowBorder((void *)(((TradeWork *)p)->messageWin),2);BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->messageWin));((TradeWork *)p)->messageWin=0;} }

void POKETRADE_SAVE_CreateMessageResources(char *p)
{
    (*(void * *)&((TradeWork *)p)->wordSet)=GF_FONT_Create_EC64(((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->messageBank)=func_02045B38(0,2,159,((TradeWork *)p)->heapId);
    ((TradeWork *)p)->font=GF_FONT_Create(23,0,0,0,((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->infoTextOut)=STRBUF_Create(128,((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->infoTextIn)=STRBUF_Create(128,((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->messageText)=STRBUF_Create(128,((TradeWork *)p)->heapId);
    ((TradeWork *)p)->messageTemplate=STRBUF_Create(128,((TradeWork *)p)->heapId);
    ((TradeWork *)p)->printQueue=(void *)PRINTSYS_QUE_Create((void *)(((TradeWork *)p)->heapId));
    GF_FONT_SetTextColor(1,2,15);
    ((TradeWork *)p)->tcbl=TCBL_Create(((TradeWork *)p)->heapId,((TradeWork *)p)->heapId,2,0);
    ((TradeWork *)p)->keyCursor=func_02028590(15,1,0,((TradeWork *)p)->heapId);
    ((TradeWork *)p)->taskMenuRes=APP_TASKMENU_RES_Create(6,9,*(u32 *)&((TradeWork *)p)->font,*(u32 *)&((TradeWork *)p)->printQueue,((TradeWork *)p)->heapId);
}

void POKETRADE_SAVE_DeleteMessageResources(char *p)
{
    int i;
    func_0200566C();
    if(*(int *)&((TradeWork *)p)->tcbl) {
        APP_KEYCURSOR_Delete((int)(((TradeWork *)p)->keyCursor));
        POKETRADE_SAVE_CloseMessageWindow(p);
        POKETRADE_SAVE_CloseTaskMenu(p);
        if(((TradeWork *)p)->printStream) {PRINTSYS_PrintStreamDelete((struct Rec3 *)(((TradeWork *)p)->printStream));((TradeWork *)p)->printStream=0;}
        if(((TradeWork *)p)->taskMenuWindow) {APP_TASKMENU_WIN_Delete(((TradeWork *)p)->taskMenuWindow);((TradeWork *)p)->taskMenuWindow=0;}
        if(((TradeWork *)p)->taskMenuRes) {APP_TASKMENU_RES_Delete(((TradeWork *)p)->taskMenuRes);((TradeWork *)p)->taskMenuRes=0;}
        if((*(void * *)&((TradeWork *)p)->subWin)) {BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->subWin));(*(void * *)&((TradeWork *)p)->subWin)=0;}
        for(i=0;i<2;i++) {if(*(void **)(p+i*4+0x5bc)) {BMP_WIN_Delete(*(void **)(p+i*4+0x5bc));*(void **)(p+i*4+0x5bc)=0;}}
        WORDSET_DeleteStrbufED04((*(void * *)&((TradeWork *)p)->wordSet));
        MSGDATA_Delete((*(void * *)&((TradeWork *)p)->messageBank));
        GF_FONT_Delete(((TradeWork *)p)->font);
        STRBUF_Delete((*(void * *)&((TradeWork *)p)->infoTextOut));
        STRBUF_Delete((*(void * *)&((TradeWork *)p)->infoTextIn));
        STRBUF_Delete((*(void * *)&((TradeWork *)p)->messageText));
        STRBUF_Delete(((TradeWork *)p)->messageTemplate);
        PRINTSYS_QUE_Clear((struct PrintSys *)(*(unsigned *)&((TradeWork *)p)->printQueue));
        PRINTSYS_QUE_Delete((struct PrintSys *)(*(unsigned *)&((TradeWork *)p)->printQueue));
        TCBL_Destroy(((TradeWork *)p)->tcbl);
        *(int *)&((TradeWork *)p)->tcbl=0;
    }
}

int POKETRADE_SAVE_IsMessagePrintDone(char *p) {int v=1;if(((TradeWork *)p)->printStream) {if(((TradeWork *)p)->messageWin)APP_KEYCURSOR_Update((struct Ctx *)(*(int *)&((TradeWork *)p)->keyCursor),(void *)(((TradeWork *)p)->printStream),(void *)(((TradeWork *)p)->messageWin));v=func_02028484((struct Blk *)(p+0x11d4),(void *)(((TradeWork *)p)->printStream));if(v) {if(((TradeWork *)p)->printStream) {PRINTSYS_PrintStreamDelete((struct Rec3 *)(((TradeWork *)p)->printStream));((TradeWork *)p)->printStream=0;}}}return v;}

void POKETRADE_SAVE_CloseTaskMenu(char *p)
{
    if ((*(void * *)&((TradeWork *)p)->taskMenu)) {
        *(volatile unsigned short *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu((*(void * *)&((TradeWork *)p)->taskMenu));
        (*(void * *)&((TradeWork *)p)->taskMenu) = 0;
    }
}

void POKETRADE_SAVE_OpenTaskMenuAt(char *p,int *ids,int count,int x,int y)
{
    SpriteTemplate t;
    int i;
    t.heap=((TradeWork *)p)->heapId;
    t.count=count;
    t.items=p+0x650;
    t.flag=1;
    t.x=x;t.y=y;t.a=13;t.b=3;
    for(i=0;i<count;i++) {
        *(void **)(p+(u32)i*12+0x650)=STRBUF_Create(100,((TradeWork *)p)->heapId);
        func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank),ids[i],*(void **)(p+(u32)i*12+0x650));
        *(u16 *)(p+(u32)i*12+0x654)=0x39e3;
        if(ids[i]==5) *(int *)(p+(u32)i*12+0x658)=1;
        else *(int *)(p+(u32)i*12+0x658)=0;
    }
    (*(void * *)&((TradeWork *)p)->taskMenu)=APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t),((TradeWork *)p)->taskMenuRes);
    for(i=0;i<count;i++) STRBUF_Delete(*(void **)(p+(u32)i*12+0x650));
}

void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count)
{
    if (count == 1) {
        POKETRADE_SAVE_OpenTaskMenuAt(p, ids, count, 0x20, 0x15);
        return;
    }
    POKETRADE_SAVE_OpenTaskMenuAt(p, ids, count, 0x20, 0x18);
}

void POKETRADE_SAVE_PrintNickname(void *a,void *b,int x,int y,int flag,int mode,char *p) {if(!flag) {if(mode) {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),28,(void *)(((TradeWork *)p)->infoTextIn));WORDSET_SetSlotMonName((*(void * *)&((TradeWork *)p)->wordSet),0,a);}else {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),29,(void *)(((TradeWork *)p)->infoTextIn));WORDSET_SetSlotMonSpecies((*(void * *)&((TradeWork *)p)->wordSet),0,a);}WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));}else {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),105,(void *)(((TradeWork *)p)->infoTextOut));}PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->infoTextOut),(void *)(*(int *)&((TradeWork *)p)->font));}

void POKETRADE_SAVE_PrintDexNumber(void *a,void *b,int x,int y,int flag,char *p) {int v;u16 *t;if(!flag) {v=func_02017E1C(a,171,0);if(!((TradeWork *)p)->nationalDexEnabled) {t=POKE_PERSONAL_LoadFormTable(((TradeWork *)p)->heapId,0);v=t[v];func_020307B0(t);}if(v==999) {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),162,(void *)(((TradeWork *)p)->infoTextOut));}else {WORDSET_SetSlotNumber((struct WordSet *)(((TradeWork *)p)->wordSet),1,v,3,1,1);func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),27,(void *)(((TradeWork *)p)->infoTextIn));WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));}PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->infoTextOut),(void *)(*(int *)&((TradeWork *)p)->font));}}

void POKETRADE_SAVE_PrintSpeciesName(void *a,void *b,int x,int y,int flag,char *p) {if(!flag) {func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),28,(void *)(((TradeWork *)p)->infoTextIn));WORDSET_SetSlotMonName((*(void * *)&((TradeWork *)p)->wordSet),0,a);WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->infoTextOut),(void *)(*(int *)&((TradeWork *)p)->font));}}

void POKETRADE_SAVE_PrintLevel(void *a,void *b,int x,int y,char *p) {func_02017E1C(a,171,0);func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),18,(void *)(((TradeWork *)p)->infoTextIn));WORDSET_SetSlotNumber((struct WordSet *)(((TradeWork *)p)->wordSet),0,func_02017E1C(a,158,0),3,1,1);WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));PRINTSYS_Print(b,x,y,(void *)(((TradeWork *)p)->infoTextOut),(void *)(*(int *)&((TradeWork *)p)->font));}

void POKETRADE_SAVE_PrintGender(void *a,void *b,int x,int y,char *p,int mode,int guard) {int v,w,id,color;v=func_02017E1C(a,110,0);w=func_02017E1C(a,173,0);id=func_02017E1C(a,5,0);if(v<=1 && w!=0 && !(guard && id==29) && !(guard && id==32)) {if(mode) {if(v==1)color=0x31a0;else color=0x39e0;}else {if(v==1)color=0xc80;else color=0x14c0;}func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),v+46,(void *)(((TradeWork *)p)->infoTextOut));PRINTSYS_PrintColor(b,x,y,((TradeWork *)p)->infoTextOut,*(int *)&((TradeWork *)p)->font,color);}}

void POKETRADE_SAVE_PrintStatLabels(int a,int b,int x,int y,char *p)
{
    int i;
    for(i=0;i<6;i++) {
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),30+i,(void *)(((TradeWork *)p)->infoTextOut));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y+16*i,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
    }
}

void POKETRADE_SAVE_PrintHeldItem(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),43,(void *)(((TradeWork *)p)->infoTextIn));
    v=func_02017E1C((void *)a,6,0);
    if(v) {
        WORDSET_Callback_EF40((struct WordSet *)(((TradeWork *)p)->wordSet),0,v);
        WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
    }
}

void POKETRADE_SAVE_PrintHpValues(int a,int b,int x,int y,char *p)
{
    int v,w;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),39,(void *)(((TradeWork *)p)->infoTextIn));
    v=func_02017E1C((void *)a,160,0);
    w=func_02017E1C((void *)a,161,0);
    WORDSET_SetSlotNumber((struct WordSet *)(((TradeWork *)p)->wordSet),0,v,3,1,1);
    WORDSET_SetSlotNumber((struct WordSet *)(((TradeWork *)p)->wordSet),1,w,3,1,1);
    WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
}

void POKETRADE_SAVE_PrintStatValues(int a, int b, int c, int d, char *p)
{
    int i = 0;
    T5 t = gStatValueLabels;
    for (; i < 5; i++) {
        func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank), 0x28, (*(void * *)&((TradeWork *)p)->infoTextIn));
        WORDSET_SetSlotNumber((*(void * *)&((TradeWork *)p)->wordSet), 0, func_02017E1C((void *)a, t.v[i], 0), 3, 1, 1);
        WORDSET_CopyTaggedText((*(void * *)&((TradeWork *)p)->wordSet), (*(void * *)&((TradeWork *)p)->infoTextOut), (*(void * *)&((TradeWork *)p)->infoTextIn));
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b), (short)c, (short)(d + i * 16), (*(void * *)&((TradeWork *)p)->infoTextOut), ((TradeWork *)p)->font);
    }
}

void POKETRADE_SAVE_PrintAbilityLabel(int a,int b,int x,int y,char *p)
{
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),44,(void *)(((TradeWork *)p)->infoTextOut));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
}

void POKETRADE_SAVE_PrintMoveNames(int a,int b,int x,int y,char *p)
{
    int i,v;
    for(i=0;i<4;i++) {
        v=func_02017E1C((void *)a,54+i,0);
        if(v) {
            func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),45,(void *)(((TradeWork *)p)->infoTextIn));
            WORDSET_SetSlotFromMsgCB((struct WordSet *)(((TradeWork *)p)->wordSet),0,v);
            WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));
            PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y+16*i,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
        }
    }
}

void POKETRADE_SAVE_PrintNatureName(int a,int b,int x,int y,char *p)
{
    int s;
    s=(int)func_02045B38(0,2,24,((TradeWork *)p)->heapId);
    func_02045CAC((struct MsgBank *)s,func_02018598((void *)a),(void *)(((TradeWork *)p)->infoTextOut));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
    MSGDATA_Delete((struct Rec *)s);
}

void POKETRADE_SAVE_PrintExperience(int a,int b,int x,int y,char *p)
{
    int v;
    func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank),42,(void *)(((TradeWork *)p)->infoTextIn));
    v=func_02017E1C((void *)a,10,0);
    WORDSET_SetSlotFromMsgB6((struct WordSet *)(((TradeWork *)p)->wordSet),0,v);
    WORDSET_CopyTaggedText((struct WordSet *)(((TradeWork *)p)->wordSet),(void *)(((TradeWork *)p)->infoTextOut),(void *)(((TradeWork *)p)->infoTextIn));
    PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b),x,y,(*(void * *)&((TradeWork *)p)->infoTextOut),((TradeWork *)p)->font);
}

/*
 * lever: retain the pre-increment byte index and independent old/base locals;
 * splitting old's base assignment and naming the else-side p+0x8c4
 * address settles the early r4/r7 allocation. No signature mutation.
 */
void POKETRADE_SAVE_DrawOfferCardWindow(char *p,int i,void *mon)
{
    IntPair a=gOfferCardWindowPosA;
    IntPair b=gOfferCardWindowPosB;
    IntPair c=gOfferCardWindowPosC;
    u32 flag;
    const char *old;
    u32 index;
    char *tmp;
    flag=func_02017E1C(mon,76,0);
    func_02049B40(23,5,0,448,32,((TradeWork *)p)->heapId);
    old=p;
    old=old+0x5bc;
    index=i*4;
    if(*(const int *)(old+index))BMP_WIN_Delete((struct Descriptor *)(*(const int *)(old+index)));
    *(int *)(p+0x5bc+index)=(int)BMP_WIN_Create(3,(u8)(*(int *)((char *)&a+index)),1,14,20,14,0);
    GF_FONT_SetTextColor(15,2,0);
    {
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x5bc+index));
        POKETRADE_SAVE_PrintNickname(mon,window,16,0,flag,POKETRADE_PROC_IsWifiMode(p),p);
    }
    if(flag==0) {
        char *items=p+0x5bc;
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index));
        POKETRADE_SAVE_PrintGender(mon,window,80,0,p,0,POKETRADE_PROC_IsWifiMode(p));
        GF_FONT_SetTextColor(15,2,0);
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index)),16,19,p);
        POKETRADE_SAVE_PrintHeldItem((int)mon,*(int *)(items+index),16,128,p);
        i++;
        POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4+i*20,mon,((TradeWork *)p)->clactSystem,*(int *)((char *)&b+index)+16,16,0,((TradeWork *)p)->heapId,*(int *)((char *)&c+index));
        CLACT_SetActorBgPriority(*(void **)(p+i*20+0x8d4),1);
    } else {
        tmp=p+0x8c4;
        POKETRADE_SAVE_DeleteStatusIconActor(tmp+(i+1)*20);
    }
    BMP_WIN_TransferChars((struct Descriptor *)*(const int *)(old+index));
    BMP_WIN_MakeScreen((struct Cfg *)(*(const int *)(old+index)));
    func_02041B6C(3);
}

void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p)
{
    char *q = p + 0x8C4;
    int i;
    for (i = 0; i < 3; i++) {
        POKETRADE_SAVE_DeleteStatusIconActor(q + i * 0x14);
    }
}

void POKETRADE_SAVE_DeleteTypeIcons(char *p)
{
    char *q;
    int i = 0;
    q = p + 0x900;
    for (; i < 4; i++) {
        POKETRADE_SAVE_DeleteTypeIconActor(q + i * 0x14);
    }
}

void POKETRADE_SAVE_CloseSummaryPage(void *p, int a1)
{
    unsigned int v;

    POKETRADE_2D_DeleteMarkingIcon((char *)p + 0x964);
    POKETRADE_2D_DeleteMarkingIcon((char *)p + 0x978);
    POKETRADE_2D_DeleteSummaryIcons(p);
    if (a1 != 0) {
        v = *(volatile unsigned int *)0x04001000;
        v &= 0xFFFF1FFF;
        *(volatile unsigned int *)0x04001000 = v;
    }
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    POKETRADE_SAVE_DeleteTypeIcons(p);
    POKETRADE_2D_DeleteMarkingIcon((char *)p + 0x950);
    POKETRADE_2D_DeleteTouchbarActors((int)p);
    POKETRADE_3D_DeleteMcssSlot(p, 0);
    POKETRADE_3D_DeleteMcssSlot(p, 1);
    BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->subWin));
    BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->subWin));
    ((TradeWork *)p)->subWin = 0;
    POKETRADE_2D_NoOp(p);
}

#undef I

#undef I

#undef I

#undef I

#undef I

#undef I

#undef I

#undef I

#undef I

#define I(k) (*(int *)(p+(k)))

void POKETRADE_SAVE_OpenSummaryScreen(char *p,void *a)
{
    func_02040588(3,0);
    POKETRADE_3D_RemoveCurrentUnit(p);
    POKETRADE_SAVE_CloseMessageWindowClear(p);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,0);
    POKETRADE_SAVE_DeleteOfferCardWindow(p,1);
    POKETRADE_2D_LoadMainPalette((int)p);
    POKETRADE_SAVE_ShowSummaryMon(p,a,0,1);
    if(POKETRADE_PROC_IsHostSide(p)==0) {
        POKETRADE_2D_CreateTouchbarActors(p);
        POKETRADE_2D_LoadSubBackgroundGfx(p);
        BG_SYS_SetMainVisiblePlanes(29);
        BG_SYS_SetSubVisiblePlanes(31);
        func_0207D658(0x04001050,26,-8);
        p[0x11f9]=1;
        func_020056A0((void (*)(void *, void *))POKETRADE_SAVE_VBlankSetupWindowRegs,p,0);
    }
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),1,1);
}

/*
 * initialization: side is assigned 0/1 by the original signed p+f54 comparison; both IntVec2.v[2] snapshots are initialized by complete table copies.
 * arithmetic: ROM b={0,128} makes b.v[side]+16 equal 16/144; mode is forwarded unchanged and no input domain is added.
 * interface: 020450F0's second argument is explicitly narrowed to u8 at 021E1E5A/60; its own body accepts u32.
 */
void POKETRADE_SAVE_DrawSummaryPage(char *p,int mode,void *mon)
{
    IntVec2 a=gSummaryPagePosA;
    IntVec2 b=gSummaryPagePosB;
    int side=0;
    u32 flag;
    if(I(0xf54)<128) side=1;
    POKETRADE_2D_UploadWindowPalette(p,11,4);
    if(P(0x6b4)) BMP_WIN_Delete(P(0x6b4));
    I(0x6b4)=BMP_WIN_Create(6,(u8)a.v[side],0,16,18,11,0);
    GF_FONT_SetTextColor(14,15,0);
    flag=func_02017E1C(mon,76,0);
    if(mode==0) {
        POKETRADE_SAVE_PrintNickname(mon,BMP_WIN_GetBmp(P(0x6b4)),32,0,flag,0,p);
        if(flag==0) {
            POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(P(0x6b4)),32,16,p);
            POKETRADE_SAVE_PrintStatLabels((int)mon,I(0x6b4),8,32,p);
            POKETRADE_SAVE_PrintHeldItem((int)mon,I(0x6b4),24,128,p);
            POKETRADE_SAVE_PrintHpValues((int)mon,I(0x6b4),64,32,p);
            POKETRADE_SAVE_PrintStatValues((int)mon,I(0x6b4),80,48,p);
            POKETRADE_SAVE_PrintGender(mon,BMP_WIN_GetBmp(P(0x6b4)),96,0,p,0,0);
            POKETRADE_2D_CreateMarkingIcon(p,side,mon);
            POKETRADE_2D_CreatePokerusIcon(p,side,0,mon);
            POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4,mon,I(0x9c4),b.v[side]+16,16,1,((TradeWork *)p)->heapId,13);
        } else {
            POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4);
        }
    } else {
        POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4);
        POKETRADE_2D_DeleteMarkingIcon(p+0x950);
        POKETRADE_2D_DeleteMarkingIcon(p+0x964);
        POKETRADE_2D_DeleteMarkingIcon(p+0x978);
        if(flag==0) {
            POKETRADE_SAVE_PrintAbilityLabel((int)mon,I(0x6b4),8,0,p);
            POKETRADE_SAVE_PrintMoveNames((int)mon,I(0x6b4),16,16,p);
            func_02045CAC(P(0x720),36,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),8,80,P(0x730),P(0x728));
            POKETRADE_SAVE_PrintNatureName((int)mon,I(0x6b4),16,96,p);
            func_02045CAC(P(0x720),37,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),8,112,P(0x730),P(0x728));
            POKETRADE_SAVE_PrintExperience((int)mon,I(0x6b4),16,128,p);
        }
    }
    POKETRADE_2D_LoadSummaryBackground(p,side,mode);
    BMP_WIN_MakeScreen(P(0x6b4));
    BMP_WIN_TransferChars(P(0x6b4));
    func_02041B6C(6);
}

void POKETRADE_SAVE_PrepareSummaryWindow(char *p, void *a, int b, int a3)
{
    POKETRADE_3D_DeleteMcssSlot(p, b);
    if ((*(void * *)&((TradeWork *)p)->subWin)) {
        BMP_WIN_Delete((*(void * *)&((TradeWork *)p)->subWin));
    }
}

void POKETRADE_SAVE_CreateTypeIcons(char *p,void *mon,IntQuad *t)
{
    u32 a,b;
    POKETRADE_SAVE_DeleteTypeIconActor(p+0x900+t->a*20);
    POKETRADE_SAVE_DeleteTypeIconActor(p+0x900+t->b*20);
    POKETRADE_SAVE_CreateTypeIconActor(p+0x900+t->a*20,mon,0,((TradeWork *)p)->clactSystem,176,95,0,((TradeWork *)p)->heapId);
    a=func_02017E1C(mon,174,0);
    b=func_02017E1C(mon,175,0);
    if(a!=b)
        POKETRADE_SAVE_CreateTypeIconActor(p+0x900+t->b*20,mon,1,((TradeWork *)p)->clactSystem,210,95,0,((TradeWork *)p)->heapId);
    if(*(void **)(p+t->c*20+0x910))
        CLACT_SetActorDrawEnable(*(void **)(p+t->c*20+0x910),0);
    if(*(void **)(p+t->d*20+0x910))
        CLACT_SetActorDrawEnable(*(void **)(p+t->d*20+0x910),0);
}

void POKETRADE_SAVE_ToggleTypeIconSet(char *p,int a)
{
    if(((TradeWork *)p)->summaryFlag) {
        IntQuad t;
        t=gTypeIconSetA;
        POKETRADE_SAVE_CreateTypeIcons((char *)p, (void *)a, &t);
        ((TradeWork *)p)->summaryFlag=0;
    } else {
        IntQuad t;
        t=gTypeIconSetB;
        POKETRADE_SAVE_CreateTypeIcons((char *)p, (void *)a, &t);
        ((TradeWork *)p)->summaryFlag=1;
    }
}

#undef I

#undef I

#undef I

#undef I

#undef I

#undef I

#define I(k) (*(int *)(p+(k)))

/*
 * control: the pool-hole call POKETRADE_3D_AddPokemonMcss is written in both arms (x==0, then flag != 0); the compiler cross-jumps the first copy into a b.
 */
void POKETRADE_SAVE_ShowSummaryMon(char *p,void *mon,int side,int flag)
{
    u32 flag76;
    u32 v[3];
    int i;
    flag76=func_02017E1C(mon,76,0);
    POKETRADE_SAVE_PrepareSummaryWindow(p,mon,side,flag);
    func_02049B40(23,5,0,448,32,((TradeWork *)p)->heapId);
    if(Q[side]==0)
        POKETRADE_3D_AddPokemonMcss((TradeWork *)p,side,1,mon,0);
    else if(flag!=0)
        POKETRADE_3D_AddPokemonMcss((TradeWork *)p,side,1,mon,0);
    v[0]=0xe<<14;
    v[1]=1<<14;
    v[2]=0;
    MCSS_SetPosition(Q[side],v);
    MCSS_ResetVanishFlag(Q[side]);
    if(((TradeWork *)p)->mcssPokemon[1-side])
        MCSS_SetVanishFlag(((TradeWork *)p)->mcssPokemon[1-side]);
    GF_FONT_SetTextColor(15,2,0);
    i=0;
    P(0x6b4)=(void *)BMP_WIN_Create(3,1,0,31,24,14,0);
    POKETRADE_SAVE_PrintNickname(mon,BMP_WIN_GetBmp(P(0x6b4)),16,0,flag76,0,p);
    if(flag76==0) {
        POKETRADE_SAVE_PrintDexNumber(mon,BMP_WIN_GetBmp(P(0x6b4)),0,16,flag76,p);
        POKETRADE_SAVE_PrintSpeciesName(mon,BMP_WIN_GetBmp(P(0x6b4)),56,16,flag76,p);
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp(P(0x6b4)),96,i,p);
        POKETRADE_SAVE_PrintGender(mon,BMP_WIN_GetBmp(P(0x6b4)),80,i,p,i,i);
        POKETRADE_SAVE_PrintStatLabels((int)mon,(int)P(0x6b4),0,32,p);
        for(i=0;i<2;i++) {
            func_02045CAC(P(0x720),i+36,P(0x730));
            PRINTSYS_Print(BMP_WIN_GetBmp(P(0x6b4)),0,i*16+0x88,P(0x730),P(0x728));
        }
        POKETRADE_SAVE_PrintHpValues((int)mon,(int)P(0x6b4),56,32,p);
        POKETRADE_SAVE_PrintStatValues((int)mon,(int)P(0x6b4),72,48,p);
        POKETRADE_SAVE_PrintNatureName((int)mon,(int)P(0x6b4),56,136,p);
        POKETRADE_SAVE_PrintExperience((int)mon,(int)P(0x6b4),56,152,p);
        POKETRADE_SAVE_PrintHeldItem((int)mon,(int)P(0x6b4),40,168,p);
        POKETRADE_SAVE_PrintAbilityLabel((int)mon,(int)P(0x6b4),152,113,p);
        POKETRADE_SAVE_PrintMoveNames((int)mon,(int)P(0x6b4),152,128,p);
        POKETRADE_SAVE_ToggleTypeIconSet(p,(int)mon);
        POKETRADE_2D_CreateMarkingIcon(p,2,mon);
        POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4,mon,I(0x9c4),12,7,0,((TradeWork *)p)->heapId,12);
    } else {
        if(P(0x960)) CLACT_SetActorDrawEnable(P(0x960),i);
        POKETRADE_SAVE_DeleteTypeIcons(p);
        POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    }
    POKETRADE_2D_CreateSummaryIcons(p,mon,flag76);
    POKETRADE_2D_CreatePokerusIcon(p,0,1,mon);
    BMP_WIN_MakeScreen(P(0x6b4));
    BMP_WIN_TransferChars(P(0x6b4));
    func_02041B6C(3);
}

void POKETRADE_SAVE_DeleteOfferCardWindow(char *p,int i)
{
    if (*(int *)(p+0x5bc+4*i)) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x5bc+4*i)),0);
        BMP_WIN_ClearScreen((struct Descriptor *)(*(int *)(p+0x5bc+4*i)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5bc+4*i)));
        func_02041B6C(3);
        *(int *)(p+0x5bc+4*i)=0;
        POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4+20*(i+1));
    }
}

void POKETRADE_SAVE_CloseSummaryWindow(char *p,int a)
{
    POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4);
    POKETRADE_2D_DeleteMarkingIcon(p+0x950);
    POKETRADE_2D_DeleteMarkingIcon(p+0x964);
    POKETRADE_2D_DeleteMarkingIcon(p+0x978);
    if (((TradeWork *)p)->subWin) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)((TradeWork *)p)->subWin),0);
        if(a) {
            BMP_WIN_ClearScreen((struct Descriptor *)(((TradeWork *)p)->subWin));
            BMP_WIN_TransferChars((struct Descriptor *)((TradeWork *)p)->subWin);
        }
        BMP_WIN_Delete((struct Descriptor *)(((TradeWork *)p)->subWin));
        ((TradeWork *)p)->subWin=0;
    }
}

/*
 * zero: the literal 0 arguments of the first loop are hoisted and spilled to the slot k then reuses; k=0 is written just before the second GF_FONT_SetTextColor call, not before the loop.
 */
void POKETRADE_SAVE_DrawOfferListWindows(char *p, int a1)
{
    void *arr[2];
    void *mon;
    u32 flag76;
    char *q1,*q2;
    int j,n;
    int k;
    POKETRADE_2D_CreateOfferWindows(p);
    arr[0]=P(0x834);
    arr[1]=P(0x830);
    GF_FONT_SetTextColor(15,2,0);
    for(j=0;j<2;j++) {
        func_02045CAC(P(0x720),128,P(0x734));
        WORDSET_SetSlotMyStatus(P(0x724),0,arr[j]);
        WORDSET_CopyTaggedText(P(0x724),P(0x730),P(0x734));
        PRINTSYS_Print(*(void **)(p+j*16+0x10f4),0,0,P(0x730),P(0x728));
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
                flag76=func_02017E1C(mon,76,0);
                POKETRADE_2D_CreateOfferIconActor(p,k,n,mon,0,1);
                POKETRADE_SAVE_PrintNickname(mon,*(void **)(q2+n*4+0x10f8),0,0,flag76,POKETRADE_PROC_IsWifiMode(p),p);
                if(flag76==0) {
                    POKETRADE_SAVE_PrintGender(mon,*(void **)(q2+n*4+0x10f8),56,16,p,0,POKETRADE_PROC_IsWifiMode(p));
                    POKETRADE_SAVE_PrintLevel(mon,*(void **)(q2+n*4+0x10f8),0,16,p);
                }
            }
        }
    }
    POKETRADE_2D_UpdateOfferWindowActors((int)p);
}

void POKETRADE_SAVE_DeleteOfferListWindows(char *p)
{
    int i;
    for (i=0;i<4;i++) {
        char *q = p+i*4;
        if (((TradeWork *)q)->windowF) {
            BMP_WIN_Delete(((TradeWork *)q)->windowF);
            ((TradeWork *)q)->windowF=0;
        }
    }
    POKETRADE_2D_DeleteOfferWindowActors((int)p);
}

void POKETRADE_SAVE_SetupWindowRegsSummary(void *a0)
{
    u32 v;

    func_0207D658(0x04001050, 0x1A, -8);

    v = (*(volatile u16 *)0x04001048 & ~0x3F) | 0x1F;
    *(volatile u16 *)0x04001048 = v | 0x20;
    *(volatile u16 *)0x04001040 = 0x00FF;
    *(volatile u16 *)0x04001044 = 0x00C0;
    v = (*(volatile u16 *)0x04001048 & ~0x3F00) | 0x1F00;
    *(volatile u16 *)0x04001048 = v | 0x2000;
    *(volatile u16 *)0x04001042 = 0xFF00;
    *(volatile u16 *)0x04001046 = 0x00C0;
    v = (*(volatile u16 *)0x0400104A & ~0x3F) | 0x1F;
    *(volatile u16 *)0x0400104A = v;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & 0xFFFF1FFF) | 0x6000;
}

/*
 * lever: each final handle index is recomputed through a 32-bit long local;
 * an int copy CSEs the shift and shortens the function by four bytes.
 */
void POKETRADE_SAVE_DrawPartnerOfferCard(char *p,int i,void *mon)
{
    Pair a=gPartnerOfferCardPosA;
    Pair b=gPartnerOfferCardPosB;
    U32Quad colors=gPartnerOfferColors;
    Pair c=gPartnerOfferCardPosC;
    u32 flag;
    int layer,idx2;
    u32 col,col2;
    int index;
    char *items,*items2;
    flag=func_02017E1C(mon,76,0);
    index=i*4;
    if(*(int *)(p+i*4+0x5c4)) {
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5c4)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+i*4+0x5cc)));
    }
    layer=*(int *)((char *)&a+index);
    items=p+0x5c4;
    *(int *)(items+index)=BMP_WIN_Create(1,layer,0,14,5,5,0);
    items2=p+0x5cc;
    *(int *)(items2+index)=BMP_WIN_Create(1,layer,17,13,2,5,0);
    idx2=i*2;
    col=((u32 *)&colors)[idx2];
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index)),(u8)(col|(col<<4)));
    col2=((u32 *)&colors)[idx2+1];
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items2+index)),(u8)(col2|(col2<<4)));
    GF_FONT_SetTextColor(1,2,(u8)col);
    {
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(items+index));
        POKETRADE_SAVE_PrintNickname(mon,window,16,4,flag,POKETRADE_PROC_IsWifiMode(p),p);
    }
    if(flag==0) {
        char *first=p+0x5c4;
        void *window=BMP_WIN_GetBmp((struct Descriptor *)*(int *)(first+index));
        POKETRADE_SAVE_PrintGender(mon,window,80,4,p,1,POKETRADE_PROC_IsWifiMode(p));
        POKETRADE_SAVE_PrintLevel(mon,BMP_WIN_GetBmp((struct Descriptor *)*(int *)(first+index)),16,19,p);
        GF_FONT_SetTextColor(1,2,(u8)col2);
        POKETRADE_SAVE_PrintHeldItem((int)mon,*(int *)(items2+index),0,0,p);
        POKETRADE_SAVE_CreateStatusIconActor(p+0x8c4+(i+1)*20,mon,((TradeWork *)p)->clactSystem,*(int *)((char *)&b+index)+16,16,0,((TradeWork *)p)->heapId,*(int *)((char *)&c+index));
    } else POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    {
        char *first=p+0x5c4;
        char *second=p+0x5cc;
        long endindex=(long)i*4;
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)(first+endindex));
        BMP_WIN_TransferChars((struct Descriptor *)*(int *)(second+endindex));
        BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(first+endindex)));
        BMP_WIN_MakeScreen((struct Cfg *)(*(int *)(second+endindex)));
    }
    func_02041B6C(1);
    *(u8 *)(p+i+0x11e2)=120;
}

void POKETRADE_SAVE_DeletePartnerOfferCard(char *p,int i)
{
    if (*(int *)(p+0x5c4+4*i)) {
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5c4+4*i)));
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(p+0x5cc+4*i)));
        POKETRADE_SAVE_DeleteStatusIconActor(p+0x8c4+20*(i+1));
        *(int *)(p+0x5c4+4*i)=0;
        *(int *)(p+0x5cc+4*i)=0;
    }
}

void *POKETRADE_SAVE_OpenTaskMenuWindow(char *p,int a) {
    void *t;
    t=STRBUF_Create(100,((TradeWork *)p)->heapId);
    ((TradeWork *)p)->messageBuffer=t;
    func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank),a,t);
    ((TradeWork *)p)->magicValue=0x39e3;
    ((TradeWork *)p)->magicValue2=0;
    ((TradeWork *)p)->taskMenuWindow=APP_TASKMENU_WIN_CreateEx((u32)(((TradeWork *)p)->taskMenuRes),(u32)(p+0x650),8,21,16,3,0,1,((TradeWork *)p)->heapId);
    STRBUF_Delete(((TradeWork *)p)->messageBuffer);
    CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->cursorActor),0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),8,0);
    return ((TradeWork *)p)->taskMenuWindow;
}

void POKETRADE_SAVE_CloseTaskMenuWindow(char *p,int a,int b) {
    if (!PRINTSYS_QUE_IsFinished(((TradeWork *)p)->printQueue)) PRINTSYS_QUE_Clear(((TradeWork *)p)->printQueue);
    if(a) CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->cursorActor),1);
    if(b) TOUCHBAR_SetButtonVisible((unsigned char *)(((TradeWork *)p)->touchbar),8,POKETRADE_NEGO_HasOffer(p));
    if(((TradeWork *)p)->taskMenuWindow) {
        APP_TASKMENU_WIN_Delete(((TradeWork *)p)->taskMenuWindow);
        ((TradeWork *)p)->taskMenuWindow=0;
        func_02041B6C(6);
    }
}

int POKETRADE_SAVE_IsTouchOutsideArea(void *a0)
{
    if (TOUCHPANEL_HitTrg(gOutsideAreaHitRect) == 0) return 1;
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
    *(volatile u16 *)0x04001042=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001046=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

static inline void Position0(int x1,int y1,int x2,int y2) {
    *(volatile u16 *)0x04001040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04001044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

static inline void Visible(int window) {DISPCNT=(DISPCNT&~0xe000)|(window<<13);}

/*
 * volatile: WININ re-read at 021E2A9E and 021E2AB6; WINOUT and DISPCNT hardware read-modify-write, WIN0/1 positions hardware stores.
 */
void POKETRADE_SAVE_VBlankSetupWindowRegs(void *a,char *p) {
    W1Inside(0x10,0);
    Position1(0x30,0,0xd0,0x20);
    W0Inside(0x11,0);
    Position0(0xe0,0xa9,0xff,0xc0);
    Outside(0x1f,1);
    Visible(3);
    p[0x11f9]=0;
    func_02030EAC(a);
}

void POKETRADE_SAVE_Init3DProjection(int a) {
    IntOctet c;
    gLightSetHandle=func_02048BC4((const struct LightSet *)gLightSet,a);
    func_02048C58(gLightSetHandle);
    c=gProjectionConfig;
    c.b=gProjectionParams[12]; c.c=gProjectionParams[13];
    G3D_SYSTEM_SetProjection((const u32 *)(&c));
}

void POKETRADE_SAVE_Free3DLightSet(void)
{
    func_02048C4C(gLightSetHandle);
}

void POKETRADE_SAVE_SetCameraSummary(char *p) {
    IntVec3 a;
    IntVec3 b;
    a.x=0; a.y=0x2b000; a.z=0xf1000;
    b.x=0; b.y=0x2b000; b.z=0;
    func_02048AFC(((TradeWork *)p)->subCamera,&a);
    func_02048B44(((TradeWork *)p)->subCamera,&b);
    a.z-=0x1000;
    func_02048B6C(((TradeWork *)p)->subCamera,(const u32 *)(&a.z));
    b.x=0; b.y=0x1000; b.z=0;
    func_02048B20(((TradeWork *)p)->subCamera,&b);
}

void POKETRADE_SAVE_SetCameraTrade(char *p) {
    IntVec3 a;
    IntVec3 b;
    int c=0x1f40000;
    int d=0x1000;
    a.x=0; a.y=0x3000; a.z=0xf000;
    b.x=0; b.y=0; b.z=0;
    func_02048AFC(((TradeWork *)p)->subCamera,&a);
    func_02048B44(((TradeWork *)p)->subCamera,&b);
    func_02048B60(((TradeWork *)p)->subCamera,(const u32 *)(&d));
    func_02048B6C(((TradeWork *)p)->subCamera,(const u32 *)(&c));
    b.x=0; b.y=0x10000; b.z=0x1000;
    func_02048B20(((TradeWork *)p)->subCamera,&b);
}

void POKETRADE_SAVE_Update3DParticles(char *p) {POKETRADE_3D_DrawRotatingCube((const u8 *)p);}

static inline void shading(Shading s) { *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3002) | (s << 1)); }

static inline void antialias(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10); else *(volatile u16 *)0x04000060 &= (u16)~0x3010; }

static inline void alphatest(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 4); else *(volatile u16 *)0x04000060 &= (u16)~0x3004; }

static inline void blend(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8); else *(volatile u16 *)0x04000060 &= (u16)~0x3008; }

static inline void edge(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x20); else *(volatile u16 *)0x04000060 &= (u16)~0x3020; }

/*
 * volatile: 0x04000060 reread at 021E2C9C, 021E2CAA, 021E2CB6, 021E2CC0, 021E2CC8; 0x04000580 hardware store at 021E2CEC.
 */
void POKETRADE_SAVE_Setup3DDrawState(DrawState3D *w, Transform *t)
{
    unsigned i;
    VecFx32 v1;
    VecFx32 v2;
    t->trans.x = 0;
    t->trans.y = 0;
    t->trans.z = 0;
    t->scale.x = 0x1000;
    t->scale.y = 0x1000;
    t->scale.z = 0x1000;
    MTX_Identity33_(&t->rot);
    if (w->sub != 0) {
        if (w->sub->objA8 == 0) ICA_ANIME_SetCameraPos(w->x83c, (void *)w->sub->anim90);
        if (w->sub->objAC == 0) ICA_ANIME_SetCameraTarget(w->x83c, (void *)w->sub->anim94);
    }
    func_02048AD0(w->x83c);
    shading(SHADING_HIGHLIGHT); antialias(1); alphatest(0); blend(0); edge(0);
    G3X_SetFog(1, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((u8)i, (const u16 *)(gDrawLightTable + i * 8));
    if (w->sub != 0) {
        if (w->sub->objA0 != 0) {
            ICA_ANIME_Get((struct IcaAnime *)w->sub->anim98, (struct Rec12 *)&v1);
            BUTTON_MAN_SetEmitterPos(w->sub->objA0, &v1);
        }
        if (w->sub->objA4 != 0) {
            ICA_ANIME_Get((struct IcaAnime *)w->sub->anim9c, (struct Rec12 *)&v2);
            BUTTON_MAN_SetEmitterPos(w->sub->objA4, &v2);
        }
    }
}
