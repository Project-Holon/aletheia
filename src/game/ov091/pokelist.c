/*
 * file:     pokelist.c
 * unit:     yes
 * function: POKELIST_Init, POKELIST_Exit, POKELIST_Main, POKELIST_InitWork, POKELIST_ExitWork, POKELIST_UpdatePhase, POKELIST_UpdatePaletteFade, POKELIST_UpdateWindowMaskTask, POKELIST_SetupDisplay, POKELIST_SetupBgPlanes, POKELIST_SetupLight, POKELIST_ShutdownDisplay, POKELIST_ShutdownBgPlane0, POKELIST_ShutdownLight, POKELIST_LoadBgPlane, POKELIST_CreateClactUnit, POKELIST_DeleteClactUnit, POKELIST_CreateFonts, POKELIST_DeleteFonts, POKELIST_LoadGraphics, POKELIST_FreeGraphics, POKELIST_StartMode, POKELIST_SetupModeScreen, POKELIST_ApplySelection, POKELIST_OpenContextMenu, POKELIST_UpdateInputStage, POKELIST_RefreshCursor, POKELIST_HandleCommand, POKELIST_UpdateSwapCommand, POKELIST_UpdateHealShareCommand, POKELIST_ConfirmBattleParty, POKELIST_UpdateCursorInput, POKELIST_ReadCursorKeys, POKELIST_HandleTouch, POKELIST_MoveCursorToPlate, POKELIST_MoveSwapMarkerToPlate, POKELIST_RunContextMenu, POKELIST_EnterMenuPhase, POKELIST_CloseContextMenu, POKELIST_DispatchMenuChoice, POKELIST_UpdateMessagePhase, POKELIST_ShowMessage, POKELIST_PollContextMenuChoice, POKELIST_OpenMenuWithCallback, POKELIST_UpdateSwapAnimation, POKELIST_StartSwapAnimation, POKELIST_FinishSwap, POKELIST_GetFieldMoveMenuIndex, POKELIST_IsItemMode, POKELIST_IsNotItemUseMode, POKELIST_HasBackButton, POKELIST_GetMoveLearnStatus, POKELIST_CheckEvolution, POKELIST_PrintTextMain, POKELIST_PrintTextSub, POKELIST_PrintTextSubDirect, POKELIST_PrintExpandedTextMain, POKELIST_PrintExpandedTextSub, POKELIST_PrintExpandedTextSubDirect, POKELIST_CloseMessageToList, POKELIST_EndMessageToExit, POKELIST_CloseMessageIfItemInBag, POKELIST_OpenGiveUpMoveMenu, POKELIST_OnGiveUpMoveChoice, POKELIST_OpenForgetMoveMenu, POKELIST_OnForgetMoveChoice, POKELIST_ShowMoveLearned, POKELIST_OnTakeItemChoice, POKELIST_StartHpTransfer, POKELIST_ShowHealResult, POKELIST_OnTakeMailChoice, POKELIST_OnMailItemChoice, POKELIST_EndMessageToEvolve, POKELIST_ForceSelectionEnd, POKELIST_FindMoveSlot, POKELIST_ReplaceMoveSlot, POKELIST_ApplyItemEffect, POKELIST_SetHeldItem, POKELIST_CheckBagItem, POKELIST_RemoveBagItem, POKELIST_ReturnBagItem
 * address:  0x021B6240
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02030734  0x02030734  arm
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_InitEx  0x0201A954  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   KEY_GetCont  0x0203630C  arm
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   func_02005728  0x02005728  thumb
 *   POKE_REGULATION_FindValidOrder  0x0201A59C  thumb
 *   func_020355D8  0x020355D8  arm
 *   d_021BED0C     0x021BED0C  data  a1
 *   d_021BEA78     0x021BEA78  data  a2
 *   d_021BEA84     0x021BEA84  data  a2
 *   d_021BEA90     0x021BEA90  data  a2
 *   d_021BEA9C     0x021BEA9C  data  a2
 *   func_020315D4  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   d_021BED80     0x021BED80  data  a1
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_020355C4  0x020355C4  arm
 *   FILE_UTIL_Get_12B0  0x020212B0  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   PLIST_PLATE_Create  0x021BA6A0  thumb  ov091
 *   PLIST_PLATE_CreateEmpty  0x021BA81C  thumb  ov091
 *   PLIST_PLATE_GetLabelState  0x021BB43C  thumb  ov091
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   PLIST_MENU_InitTimer  0x021BCCCC  thumb  ov091
 *   func_020056A0  0x020056A0  thumb
 *   PLIST_MESSAGE_Create  0x021BB594  thumb  ov091
 *   PLIST_MENU_Create  0x021BBA8C  thumb  ov091
 *   func_02041B6C  0x02041B6C  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   PLIST_MENU_DeleteTaskMenuWin  0x021BBE44  thumb  ov091
 *   PLIST_MENU_Delete  0x021BBAE0  thumb  ov091
 *   PLIST_MESSAGE_Destroy  0x021BB5FC  thumb  ov091
 *   BMP_WIN_Delete  0x020452E8  arm
 *   PLIST_PLATE_Delete  0x021BA890  thumb  ov091
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   PLIST_MENU_ExitTimer  0x021BCD80  thumb  ov091
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   POKELIST_UpdateSwapAnimation  0x021B981C  thumb  ov091
 *   POKELIST_RunContextMenu  0x021B9020  thumb  ov091
 *   POKELIST_UpdateMessagePhase  0x021B9750  thumb  ov091
 *   POKELIST_PollContextMenuChoice  0x021B97D4  thumb  ov091
 *   PLIST_PLATE_StartHpAnim  0x021BB30C  thumb  ov091
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PLIST_PLATE_StepHpAnim  0x021BB358  thumb  ov091
 *   PLIST_COMM_SendStatus  0x021B6184  thumb  ov090
 *   PLIST_MESSAGE_OpenWindow  0x021BB714  thumb  ov091
 *   PLIST_MESSAGE_PrintText  0x021BB7E8  thumb  ov091
 *   PLIST_MESSAGE_RequestPrompt  0x021BBA68  thumb  ov091
 *   PLIST_MENU_UpdateLevelUp  0x021BC6CC  thumb  ov091
 *   PLIST_BATTLE_StartEffect  0x021BD8B0  thumb  ov091
 *   PLIST_BATTLE_UpdateEffect  0x021BD9C8  thumb  ov091
 *   PLIST_BATTLE_FinishEffect  0x021BD8E4  thumb  ov091
 *   PLIST_COMM_StartSync  0x021B61E8  thumb  ov090
 *   PLIST_COMM_IsSyncDoneOrFinished  0x021B61FC  thumb  ov090
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   PLIST_PLATE_Update  0x021BA8CC  thumb  ov091
 *   PLIST_MESSAGE_Update  0x021BB644  thumb  ov091
 *   PLIST_MENU_UpdateTimer  0x021BCDE8  thumb  ov091
 *   PLIST_MENU_UpdateTaskMenuWin  0x021BBE50  thumb  ov091
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_02061CA4  0x02061CA4  arm
 *   d_021BEBFC     0x021BEBFC  data  a1
 *   d_021BEC04     0x021BEC04  data  a1
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   WIPE_SetBrightnessFadeOut  0x0202223C  thumb
 *   WIPE_ResetWndMask  0x02022224  thumb
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   func_0207D63C  0x0207D63C  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   NNS_GfdResetVramTransferTaskQueue  0x02061C30  arm
 *   d_021BEC3C     0x021BEC3C  data  a4
 *   d_021BEAEC     0x021BEAEC  data  a4
 *   d_021BEAFC     0x021BEAFC  data  a4
 *   d_021BEB1C     0x021BEB1C  data  a4
 *   d_021BEB3C     0x021BEB3C  data  a4
 *   d_021BEB5C     0x021BEB5C  data  a4
 *   d_021BEB9C     0x021BEB9C  data  a4
 *   d_021BEBBC     0x021BEBBC  data  a4
 *   d_021BEBDC     0x021BEBDC  data  a4
 *   gClActorInitParam     0x020A1448  data  a4
 *   GX_SetGraphicsMode 0x0207D4B0 arm
 *   d_021BEB7C 0x021BEB7C data a4
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   PARTICLE_InitManager  0x02050B80  arm
 *   d_021BEAB8     0x021BEAB8  data  a4
 *   d_021BEAD0     0x021BEAD0  data  a4
 *   d_021BEAC4     0x021BEAC4  data  a4
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B40  0x02049B40  arm
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049EF4  0x02049EF4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusExtraFileId  0x02027630  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   APP_ICON_GetNoneFileId  0x02027758  thumb
 *   APP_ICON_GetGearCellFileId  0x0202775C  thumb
 *   APP_ICON_GetGearPaletteFileId  0x02027760  thumb
 *   APP_ICON_GetGearAnimFileId  0x02027764  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   APP_ICON_GetItemCellFileId  0x02027694  thumb
 *   APP_ICON_GetItemPaletteFileId  0x02027698  thumb
 *   APP_ICON_GetItemAnimFileId  0x0202769C  thumb
 *   APP_ICON_GetItemFrameFileId  0x020276A0  thumb
 *   APP_ICON_GetSealCellFileId  0x020276B4  thumb
 *   APP_ICON_GetSealPaletteFileId  0x020276B8  thumb
 *   APP_ICON_GetSealAnimFileId  0x020276BC  thumb
 *   APP_ICON_GetSealFrameFileId  0x020276C0  thumb
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   PLIST_MENU_CreateButtonWindow 0x021BBDEC thumb ov091
 *   PLIST_MENU_ItemRestoresHp 0x021BC1B4 thumb ov091
 *   PLIST_MENU_FindItemTarget 0x021BC1D0 thumb ov091
 *   PLIST_MENU_ShowItemUsedThenClose 0x021BC2C8 thumb ov091
 *   POKELIST_CheckBagItem 0x021BA65C thumb ov091
 *   PLIST_MESSAGE_CloseWindow 0x021BB7A4 thumb ov091
 *   PLIST_PLATE_SetSelected 0x021BAFA0 thumb ov091
 *   PLIST_DEMO_CheckGiratinaToAltered 0x021BDC5C thumb ov091
 *   PLIST_DEMO_ApplyGiratinaAlteredForm 0x021BDCA0 thumb ov091
 *   POKELIST_OpenForgetMoveMenu 0x021B9F34 thumb ov091
 *   POKELIST_ShowMoveLearned 0x021BA004 thumb ov091
 *   POKELIST_CloseMessageToList 0x021B9E20 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_0200902C 0x0200902C thumb
 *   POKELIST_EnterMenuPhase 0x021B907C thumb ov091
 *   PLIST_MENU_IsSpecialItemKind 0x021BC17C thumb ov091
 *   PLIST_DEMO_CheckItemUsable 0x021BDD78 thumb ov091
 *   PLIST_MENU_StartItemUse 0x021BC350 thumb ov091
 *   PLIST_DEMO_UseItemOnMon 0x021BE2B4 thumb ov091
 *   PLIST_PLATE_SetMon 0x021BB200 thumb ov091
 *   PLIST_PLATE_Redraw 0x021BB2C0 thumb ov091
 *   POKELIST_RemoveBagItem 0x021BA670 thumb ov091
 *   PLIST_DEMO_CanUseGracidea 0x021BDCC0 thumb ov091
 *   PLIST_DEMO_ApplyShayminSkyForm 0x021BDD58 thumb ov091
 *   PLIST_MENU_ShowItemUsedThenContinue 0x021BC30C thumb ov091
 *   POKELIST_CheckEvolution 0x021B9BF4 thumb ov091
 *   POKELIST_ShowMessage 0x021B9788 thumb ov091
 *   POKELIST_SetHeldItem 0x021BA624 thumb ov091
 *   PLIST_MESSAGE_CreateWordSet 0x021BB97C thumb ov091
 *   PLIST_MESSAGE_SetWordSetPokemon 0x021BB99C thumb ov091
 *   PLIST_MESSAGE_SetWordSetItem 0x021BB9AC thumb ov091
 *   PLIST_MESSAGE_SetWordSetItemAlt 0x021BB9BC thumb ov091
 *   PLIST_MESSAGE_SetWordSetMove 0x021BB9CC thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet 0x021BB98C thumb ov091
 *   PLIST_MENU_ApplyArceusPlateForm 0x021BC24C thumb ov091
 *   PLIST_MENU_ApplyGenesectDriveForm 0x021BC288 thumb ov091
 *   PLIST_DEMO_CheckGiratinaToOrigin 0x021BDBF8 thumb ov091
 *   PLIST_DEMO_ApplyGiratinaOriginForm 0x021BDC3C thumb ov091
 *   POKELIST_GetMoveLearnStatus 0x021B9AC8 thumb ov091
 *   POKELIST_FindMoveSlot 0x021BA5B4 thumb ov091
 *   POKELIST_ApplyItemEffect 0x021BA60C thumb ov091
 *   POKELIST_EndMessageToExit 0x021B9E3C thumb ov091
 *   POKELIST_EndMessageToEvolve 0x021BA4E4 thumb ov091
 *   POKELIST_OpenTakeItemMenu 0x021BA098 thumb ov091
 *   POKELIST_OpenGiveUpMoveMenu 0x021B9EB0 thumb ov091
 *   PLIST_BATTLE_RefreshOpponentMessage  0x021BD4EC  thumb  ov091
 *   PLIST_PLATE_IsEgg  0x021BB468  thumb  ov091
 *   PLIST_MENU_GetItemUseMessage  0x021BC228  thumb  ov091
 *   PLIST_MENU_Open  0x021BBAF8  thumb  ov091
 *   MUSICAL_MCSS_GetMonValue  0x021F6744  thumb  ov112
 *   POKELIST_HasBackButton  0x021B9AB4  thumb  ov091
 *   PLIST_MENU_SetTaskMenuWinActive  0x021BBE5C  thumb  ov091
 *   POKELIST_MoveCursorToPlate  0x021B8F68  thumb  ov091
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   PLIST_MENU_ButtonWinSetDecide  0x021BBE68  thumb  ov091
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   POKELIST_StartSwapAnimation  0x021B9968  thumb  ov091
 *   PLIST_PLATE_GetHp  0x021BB464  thumb  ov091
 *   POKELIST_StartHpTransfer  0x021BA288  thumb  ov091
 *   _u32_div_f     0x0209C2B0  arm
 *   POKE_REGULATION_CheckSelection  0x02019E54  thumb
 *   PLIST_MESSAGE_SetWordSetNumber  0x021BB9EC  thumb  ov091
 *   POKELIST_HandleTouch 0x021B8DB4 thumb ov091
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   POKELIST_IsNotItemUseMode  0x021B9AA0  thumb  ov091
 *   PLIST_PLATE_IsOccupied  0x021BB3C4  thumb  ov091
 *   d_021BEAB0     0x021BEAB0  data  a1
 *   d_021BEAAA     0x021BEAAA  data  a1
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   d_021BEC2C     0x021BEC2C  data  ov091  a1
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   func_0207D658  0x0207D658  arm
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   POKELIST_RefreshCursor 0x021B8418 thumb ov091
 *   MOVE_POKEMON_IsSkillBlocked 0x0215EA14 thumb ov010
 *   ZONEDATA_IsNormalFieldZone 0x02013E04 thumb
 *   d_021BEC0C 0x021BEC0C data a4
 *   d_021BEC1C 0x021BEC1C data a4
 *   POKELIST_SetupModeScreen 0x021B7B98 thumb ov091
 *   POKELIST_OpenContextMenu 0x021B8180 thumb ov091
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   POKEPARTY_SwapMembers 0x0201AB8C thumb
 *   FILE_UTIL_GetId 0x0202130C thumb
 *   POKE_TOOL_CheckTmCompat 0x020188AC thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   MAIL_FindEmptySlot  0x02009020  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   func_0200903C  0x0200903C  thumb
 *   POKE_TOOL_AddMove 0x0201808C thumb
 *   POKE_TOOL_FindMoveSlot 0x02018238 thumb
 *   func_020181F4 0x020181F4 thumb
 *   POKE_TOOL_ReplaceMoveSlot 0x020182A0 thumb
 *   NATSUKI_Calc 0x0201B7A0 thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_02007E50 0x02007E50 thumb
 *   BG_SYS_DrawTileEx 0x020410D0 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   CLACT_SetSurfacePos 0x0204B09C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   gPlistPlateSourceName 0x021BED18 data ov091 a1
 *   gPlistPlateTileX 0x021BEC74 data ov091 a1
 *   gPlistPlateTileY 0x021BEC75 data ov091 a1
 *   gPlistPlatePaletteA 0x021BEC6C data ov091 a1
 *   gPlistPlatePaletteB 0x021BEC6D data ov091 a1
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   POKE_TOOL_GetStatusCondition  0x02017F90  thumb
 *   CLACT_GetActorAnimFrame  0x0204B8F4  arm
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb
 *   POKE_TOOL_GetIconPalette  0x0201BBE8  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMonSpecies  0x0201EEF4  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   gSpeciesNameBank     0x020A7370  data
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   BMP_Clear  0x02043B5C  arm
 *   POKE_REGULATION_CheckPokemon 0x02019DA4 thumb
 *   func_0202D034 0x0202D034 thumb
 *   CLACT_GetSurfacePos 0x0204B0C8 arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   TCBL_Create   0x0203101C  arm
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   sPlistMessageAllocSite     0x021BED28  data  ov091  a1
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   TCBL_Main 0x020310C4 arm
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 *   APP_KEYCURSOR_Animate 0x0202865C thumb
 *   TIME_ICON_CreateNode 0x0202EE8C thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   WORDSET_Callback_EF4C 0x0201EF4C thumb
 *   WORDSET_SetSlotFromMsgCB 0x0201EF34 thumb
 *   WORDSET_SetSlotFromMsgB4 0x0201F140 thumb
 *   APP_KEYCURSOR_DrawMark 0x02028618 thumb
 *   func_02049DB4  0x02049DB4  arm
 *   gPlistMenuAllocSite     0x021BED38  data  ov091  a1
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   gPlistMenuFixedItems     0x021BEC80  data  a4
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   gPlistMenuLabelMsgIds     0x021BEC8C  data  ov091  a4
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   FILE_UTIL_CreateArcTool0F34 0x02020F34 thumb
 *   FILE_UTIL_Get_1014 0x02021014 thumb
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   POKE_TOOL_GetPlateTypeForwarder 0x02019CF8 thumb
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   POKE_TOOL_GetBoxParamIndex  0x02019D00  thumb
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   gPlistStatParamIds 0x021BECE4 data ov091 a2
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_0201D304 0x0201D304 thumb
 *   POKE_TOOL_GetLevelUpMove 0x02018328 thumb
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   STRBUF_SetString 0x02045924 arm
 *   d_021BED48 0x021BED48 data ov091 a1
 *   POKELIST_ShutdownBgPlane0 0x021B7034 thumb ov091
 *   POKELIST_SetupLight 0x021B6F28 thumb ov091
 *   POKELIST_ShutdownLight 0x021B7040 thumb ov091
 *   POKELIST_SetupBgPlanes 0x021B6F0C thumb ov091
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   func_02047964 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   PM_VOICE_IsSlotActive 0x02006BD0 thumb
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   d_021BED58 0x021BED58 data ov091 a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   VM_GetTimeZoneLight  0x02011400  thumb
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   POKE_TOOL_IsPPRestorable 0x0201B920 thumb
 *   func_02018584 0x02018584 thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKE_TOOL_RestorePP 0x0201B970 thumb
 *   PLIST_DEMO_ApplyFriendshipItem 0x021BEA48 thumb ov091
 *   PLIST_PLATE_SetSlideOffset  0x021BB0C4  thumb
 *   PLIST_PLATE_ClearSlideTrail  0x021BB1A0  thumb
 *   PLIST_PLATE_GetCenterPos  0x021BB3D4  thumb
 *   PLIST_PLATE_GetTouchRect  0x021BB3FC  thumb
 *   PLIST_PLATE_SetLabelState  0x021BB440  thumb
 *   PLIST_PLATE_CheckSelection  0x021BB4A0  thumb
 *   PLIST_MESSAGE_StartStream  0x021BB860  thumb
 *   PLIST_MESSAGE_IsIdle  0x021BB8FC  thumb
 *   PLIST_MENU_OpenFixed  0x021BBB40  thumb
 *   PLIST_MENU_Close  0x021BBBA0  thumb
 *   PLIST_MENU_Update  0x021BBBD8  thumb
 *   PLIST_MENU_GetSelectedCommand  0x021BBBE4  thumb
 *   PLIST_MENU_BeginExitWait  0x021BC6C0  thumb
 */

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
#define reg_G2_WIN0H  (*(volatile u16 *)0x04000040)
#define reg_G2_WIN0V  (*(volatile u16 *)0x04000044)
#define reg_G2_WININ  (*(volatile u16 *)0x04000048)
#define reg_G2_WINOUT (*(volatile u16 *)0x0400004A)
#define reg_G2_BLDCNT (*(volatile u16 *)0x04000050)
#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
struct Party;
struct PartyMon;
struct Proc;
struct Proc;
struct TaskMenu;
struct Descriptor;
struct Node;
struct TaskMenuState;
struct Actor;
struct PrintSys;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Light;
struct BgTemplate;
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

#include "pokelist_types.h"

typedef struct {
    u16 v[5];
} PokelistNickname;

typedef signed int     s32;

typedef signed char s8;

typedef short s16;

typedef int BOOL;

typedef struct {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} PokelistRect;

typedef struct {
    PokelistRect r[4];
} PokelistButtonRects;

typedef struct {
    s16 x;
    s16 y;
} PokelistPos;

typedef struct {
    int v[4];
} PokelistMenuItems;

typedef struct {
    u32 w[12];
} PokelistVramBanks;

typedef struct {
    u32 w[7];
} PokelistClactConfig;

typedef enum { GX_DISP_SELECT_SUB_MAIN = 0, GX_DISP_SELECT_MAIN_SUB = 1 } GXDispSelect;

typedef struct {
    u16 x;
    u16 y;
    u16 animNo;
    u8 priority;
    u8 drawArea;
} PokelistActorTemplate;

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_InitEx(struct Party *p, s32 capacity);
extern void *POKE_TOOL_Create(u16 species, u16 level, u64 id, u16 heap);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32 func_020307B0(void *p);
extern u32 KEY_GetCont(void);
extern void *POKE_REGULATION_Load(int a, int b);
extern u32 func_02005728(u32 range);
extern int POKE_REGULATION_FindValidOrder(void *a0, void *a1, void *a2);
extern void func_020355D8(int a);
extern void func_020315D4(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern u32 POKEPARTY_GetCount(void *);
extern u8 func_020355C4(void);
extern u16 FILE_UTIL_Get_12B0(u16 id);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern struct PlistPlate *PLIST_PLATE_Create(PokelistWork *work, int k, void *mon);
extern struct PlistPlate *PLIST_PLATE_CreateEmpty(PokelistWork *work, int k);
extern struct TaskMenu *APP_TASKMENU_RES_Create(u16 a0, u16 a1, void *fontMain, void *printSys, u16 heap);
extern void PLIST_MENU_InitTimer(PokelistWork *work);
extern int func_020056A0(void (*cb)(void *, PokelistWork *), PokelistWork *work, int pri);
extern u32 *PLIST_MESSAGE_Create(PokelistWork *work);
extern u32 *PLIST_MENU_Create(PokelistWork *work);
extern void func_02041B6C(u32 id);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_02030EAC(struct Node *n);
extern void PLIST_MENU_DeleteTaskMenuWin(int x);
extern void PLIST_MENU_Delete(PokelistWork *work, unsigned char *b);
extern void PLIST_MESSAGE_Destroy(PokelistWork *work, int *s);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PLIST_MENU_ExitTimer(PokelistWork *work);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);
extern void PLIST_PLATE_StartHpAnim(PokelistWork *work, struct PlistPlate *s);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern int PLIST_PLATE_StepHpAnim(PokelistWork *work, struct PlistPlate *s);
extern u32 PLIST_COMM_SendStatus(PokelistArg *arg, u8 b, u16 a);
extern void PLIST_MESSAGE_OpenWindow(PokelistWork *work, u32 *s, u32 k);
extern void PLIST_MESSAGE_PrintText(PokelistWork *work, u32 *s, u32 x);
extern void PLIST_MESSAGE_RequestPrompt(PokelistWork *work, u8 *s);
extern void PLIST_MENU_UpdateLevelUp(PokelistWork *work);
extern void PLIST_BATTLE_StartEffect(PokelistWork *work);
extern void PLIST_BATTLE_UpdateEffect(PokelistWork *work);
extern void PLIST_BATTLE_FinishEffect(PokelistWork *work);
extern void PLIST_COMM_StartSync(PokelistArg *arg, int b);
extern int PLIST_COMM_IsSyncDoneOrFinished(PokelistArg *arg, int a);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void PLIST_PLATE_Update(PokelistWork *work, struct PlistPlate *s);
extern void PLIST_MESSAGE_Update(PokelistWork *work, u8 *s);
extern void PLIST_MENU_UpdateTimer(PokelistWork *work);
extern void PLIST_MENU_UpdateTaskMenuWin(int x);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);
extern void MIi_CpuCopy16(void *src, void *dst, u32 size);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void WIPE_SetBrightnessFadeOut(u32 a, u32 color);
extern void WIPE_ResetWndMask(int a);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heapId);
extern void BMP_WIN_Init(u16 heapId);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void NNS_GfdResetVramTransferTaskQueue(void);
extern void GX_SetGraphicsMode(int,int,int);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern int G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void func_02048AD0(struct Light *l);
extern void PARTICLE_InitManager(u32 heap);
extern void CLACT_ExitSystem(void);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void PARTICLE_ExitManager(void);
extern unsigned int G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void BG_SYS_FreeSlot(unsigned);
extern void BG_SYS_PushTile(u32 index);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *PRINTSYS_QUE_CreateEx(u16 n, u32 heap);
extern void GF_FONT_SetDefaultTextColor(void);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *h, u32 a1, u32 a2, void **out, u16 heap);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *h);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusExtraFileId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int APP_ICON_GetNoneFileId(void);
extern int APP_ICON_GetGearCellFileId(int a);
extern int APP_ICON_GetGearPaletteFileId(int a);
extern int APP_ICON_GetGearAnimFileId(int a);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32 a);
extern u32 APP_ICON_GetStatusPaletteFileId(u32 a);
extern u32 APP_ICON_GetItemCellFileId(void);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern u32 APP_ICON_GetItemAnimFileId(u32 a);
extern u32 APP_ICON_GetItemFrameFileId(u32 a);
extern u32 APP_ICON_GetSealCellFileId(void);
extern u32 APP_ICON_GetSealPaletteFileId(void);
extern u32 APP_ICON_GetSealAnimFileId(u32 a);
extern u32 APP_ICON_GetSealFrameFileId(u32 a);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 FILE_UTIL_Check136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern int PLIST_MENU_IsSpecialItemKind(PokelistWork *work, int id);
extern int PLIST_DEMO_CheckItemUsable(void *a, u32 id, int slot, u32 heap);
extern int PLIST_MENU_StartItemUse(PokelistWork *work,int);
extern int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern int PLIST_DEMO_CanUseGracidea(PokelistWork *work, u32 a1);
extern void PLIST_DEMO_ApplyShayminSkyForm(PokelistWork *work, void *m);
extern void PLIST_MENU_ShowItemUsedThenContinue(PokelistWork *work);
extern void PLIST_MESSAGE_CreateWordSet(PokelistWork *work, u32 s);
extern void PLIST_MESSAGE_SetWordSetPokemon(PokelistWork *work, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetItem(PokelistWork *work, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetItemAlt(PokelistWork *work, u32 b, u32 c, int d);
extern void PLIST_MESSAGE_SetWordSetMove(PokelistWork *work, int b, int c, int d);
extern void PLIST_MESSAGE_DestroyWordSet(PokelistWork *work, u32 s);
extern void PLIST_DEMO_ApplyGiratinaOriginForm(PokelistWork *work, void *m);
extern int PLIST_MENU_CreateButtonWindow(PokelistWork *work, int unused, int id, int r3, u8 a4, int a5);
extern int PLIST_MENU_ItemRestoresHp(PokelistWork *work, void *id);
extern int PLIST_MENU_FindItemTarget(PokelistWork *work);
extern void PLIST_MENU_ShowItemUsedThenClose(PokelistWork *work);
extern void PLIST_MESSAGE_CloseWindow(PokelistWork *work, u32 *s);
extern void PLIST_DEMO_ApplyGiratinaAlteredForm(PokelistWork *work, void *m);
extern void PLIST_BATTLE_RefreshOpponentMessage(PokelistWork *work);
extern int PLIST_MENU_GetItemUseMessage(PokelistWork *work, int id);
extern int MUSICAL_MCSS_GetMonValue(void *p);
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern void PLIST_MENU_ButtonWinSetDecide(int h, int f);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern int  POKE_REGULATION_CheckSelection(u32 a0, u32 a1, u32 a2);
extern void PLIST_MESSAGE_SetWordSetNumber(PokelistWork *work, int b, int c, int d, unsigned char e);
extern u32  KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern u32 ZONEDATA_IsNormalFieldZone(u32 id);
extern int TOUCHPANEL_GetTrg(void);
extern u32 FILE_UTIL_GetId(u32 id);
extern u32 POKE_TOOL_CheckTmCompat(void *p, int v);
extern int   MAIL_FindEmptySlot(void *obj, int v);
extern void *MAIL_Create(int a0);
extern void func_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern u32 POKE_TOOL_AddMove(void *,u32);
extern u32 POKE_TOOL_FindMoveSlot(void *,u16);
extern void func_020181F4(void *,u16,u32);
extern void POKE_TOOL_ReplaceMoveSlot(void *,u16,u32);
extern void NATSUKI_Calc(void *, int, int, int);
extern int TOUCHPANEL_HitTrg(const void *rects);
extern void CLACT_AddActorSurfacePos(struct Obj *actor, const PokelistPos *delta, u32 which);
extern void CLACT_SetActorBgPriority(struct Obj *actor, int animNo);
extern int MOVE_POKEMON_IsSkillBlocked(int moveIndex, const u8 *param);
extern u32 POKEPARTY_SwapMembers(void *party, u32 i, u32 j, u32 heap);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 mode, u32 param, u8 season, u32 *out, u16 heap);
extern void *func_02045EC0(void *msgBank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *window);
extern void PRINTSYS_PrintQueColor(void *printSys, void *bmp, s16 x, s16 y, void *text, void *font, u16 color);
extern void STRBUF_Delete(void *vec);
extern void PRINTSYS_PrintColor(void *bmp, s16 x, s16 y, void *text, void *font, u16 color);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(void *wordSet, void *dst, void *src);
extern u32 func_02007FB8(void *bag, u16 itemId, u16 heapId);
extern u32 func_02007F1C(void *bag, u16 itemId, u16 count, u16 heapId);
extern u32 func_02007E50(void *bag, u16 itemId, u16 count, u16 heapId);
extern void func_0207D63C(u32 r, int a, int b, int c, int d);
extern const PokelistMenuItems d_021BEC0C, d_021BEC1C;
extern PokelistButtonRects d_021BEC2C;
extern void PLIST_PLATE_SetSelected(PokelistWork *work, struct PlistPlate *plate, int selected);
extern void PLIST_PLATE_SetSlideOffset(PokelistWork *work, const struct PlistPlate *plate, int slideX);
extern void PLIST_PLATE_ClearSlideTrail(PokelistWork *work, struct PlistPlate *plate, int slideX);
extern void PLIST_PLATE_SetMon(PokelistWork *work, struct PlistPlate *plate, void *mon, int slideX);
extern void PLIST_PLATE_Redraw(PokelistWork *work, struct PlistPlate *plate);
extern int PLIST_PLATE_IsOccupied(PokelistWork *work, struct PlistPlate *plate);
extern void PLIST_PLATE_GetCenterPos(PokelistWork *work, struct PlistPlate *plate, PokelistPos *out);
extern void PLIST_PLATE_GetTouchRect(PokelistWork *work, struct PlistPlate *plate, PokelistRect *out);
extern int PLIST_PLATE_GetLabelState(struct PlistPlate *plate);
extern void PLIST_PLATE_SetLabelState(PokelistWork *work, struct PlistPlate *plate, int labelState);
extern unsigned short PLIST_PLATE_GetHp(PokelistWork *work, struct PlistPlate *plate);
extern int PLIST_PLATE_IsEgg(PokelistWork *work, struct PlistPlate *plate);
extern int PLIST_PLATE_CheckSelection(PokelistWork *work, struct PlistPlate *plate);
extern void PLIST_MESSAGE_StartStream(PokelistWork *work, u32 *msg, u32 messageId, u32 waitForKey);
extern int PLIST_MESSAGE_IsIdle(PokelistWork *work, u32 msg);
extern void PLIST_MENU_OpenFixed(PokelistWork *work, u32 menu);
extern void PLIST_MENU_Open(PokelistWork *work, u32 menu, int *items);
extern void PLIST_MENU_Close(PokelistWork *work, u32 menu);
extern void PLIST_MENU_Update(PokelistWork *work, u32 menu);
extern unsigned int PLIST_MENU_GetSelectedCommand(PokelistWork *work, u32 menu);
extern void PLIST_MENU_SetTaskMenuWinActive(int button, int active);
extern void PLIST_MENU_ApplyArceusPlateForm(PokelistWork *work, void *mon, int itemId);
extern void PLIST_MENU_ApplyGenesectDriveForm(PokelistWork *work, void *mon, int itemId);
extern void PLIST_MENU_BeginExitWait(PokelistWork *work);
extern int PLIST_DEMO_CheckGiratinaToOrigin(PokelistWork *work, void *mon);
extern int PLIST_DEMO_CheckGiratinaToAltered(PokelistWork *work, void *mon);
extern void PLIST_PLATE_Delete(PokelistWork *work, struct PlistPlate *plate);
int POKELIST_Init(struct Proc *procObj, int *seq, PokelistArg *arg, PokelistWork *work);
int POKELIST_Exit(int procObj, int procArg, int procState, PokelistWork *work);
int POKELIST_Main(int procObj, int procArg, int procState, PokelistWork *work);
int POKELIST_InitWork(PokelistWork *work);
int POKELIST_ExitWork(PokelistWork *work);
int POKELIST_UpdatePhase(PokelistWork *work);
void POKELIST_UpdatePaletteFade(PokelistWork *work);
void POKELIST_UpdateWindowMaskTask(void *tcb, PokelistWork *work);
void POKELIST_SetupDisplay(PokelistWork *work);
void POKELIST_SetupBgPlanes(PokelistWork *work);
void POKELIST_SetupLight(PokelistWork *work);
void POKELIST_ShutdownDisplay(PokelistWork *work);
void POKELIST_ShutdownBgPlane0(PokelistWork *work);
void POKELIST_ShutdownLight(PokelistWork *work);
void POKELIST_LoadBgPlane(const void *p, unsigned id,unsigned type);
void POKELIST_CreateClactUnit(PokelistWork *work);
void POKELIST_DeleteClactUnit(PokelistWork *work);
void POKELIST_CreateFonts(PokelistWork *work);
void POKELIST_DeleteFonts(PokelistWork *work);
void POKELIST_LoadGraphics(PokelistWork *work);
void POKELIST_FreeGraphics(PokelistWork *work);
void POKELIST_StartMode(PokelistWork *work);
void POKELIST_SetupModeScreen(PokelistWork *work);
void POKELIST_ApplySelection(PokelistWork *work);
void POKELIST_OpenContextMenu(PokelistWork *work);
void POKELIST_UpdateInputStage(PokelistWork *work);
void POKELIST_RefreshCursor(PokelistWork *work);
void POKELIST_HandleCommand(PokelistWork *work);
void POKELIST_UpdateSwapCommand(PokelistWork *work);
void POKELIST_UpdateHealShareCommand(PokelistWork *work);
void POKELIST_ConfirmBattleParty(PokelistWork *work);
void POKELIST_UpdateCursorInput(PokelistWork *work);
void POKELIST_ReadCursorKeys(PokelistWork *work);
void POKELIST_HandleTouch(PokelistWork *work);
void POKELIST_MoveCursorToPlate(PokelistWork *work, int plateIndex);
void POKELIST_MoveSwapMarkerToPlate(PokelistWork *work, int plateIndex);
void POKELIST_RunContextMenu(PokelistWork *work);
void POKELIST_EnterMenuPhase(PokelistWork *work);
void POKELIST_CloseContextMenu(PokelistWork *work);
void POKELIST_DispatchMenuChoice(PokelistWork *work);
void POKELIST_UpdateMessagePhase(PokelistWork *work);
void POKELIST_ShowMessage(PokelistWork *work, int messageId, int waitForKey, PokelistFn onDone);
void POKELIST_PollContextMenuChoice(PokelistWork *work);
void POKELIST_OpenMenuWithCallback(PokelistWork *work, PokelistMenuFn onChoice);
void POKELIST_UpdateSwapAnimation(PokelistWork *work);
void POKELIST_StartSwapAnimation(PokelistWork *work);
void POKELIST_FinishSwap(PokelistWork *work);
int POKELIST_GetFieldMoveMenuIndex(void *mon, int moveSlot);
int POKELIST_IsItemMode(PokelistWork *work);
int POKELIST_IsNotItemUseMode(PokelistWork *work);
int POKELIST_HasBackButton(PokelistWork *work);
int POKELIST_GetMoveLearnStatus(PokelistWork *work, void *mon, u8 partySlot);
u32 POKELIST_CheckEvolution(PokelistWork *work, void *mon, u32 param);
void POKELIST_PrintTextMain(PokelistWork *work, struct Descriptor *window, u32 messageId, int x, s16 y, u16 color);
void POKELIST_PrintTextSub(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color);
void POKELIST_PrintTextSubDirect(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color);
void POKELIST_PrintExpandedTextMain(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void POKELIST_PrintExpandedTextSub(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void POKELIST_PrintExpandedTextSubDirect(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color);
void POKELIST_CloseMessageToList(PokelistWork *work);
void POKELIST_EndMessageToExit(PokelistWork *work);
void POKELIST_CloseMessageIfItemInBag(PokelistWork *work);
void POKELIST_OpenGiveUpMoveMenu(PokelistWork *work);
void POKELIST_OnGiveUpMoveChoice(PokelistWork *work, int choice);
void POKELIST_OpenForgetMoveMenu(PokelistWork *work);
void POKELIST_OnForgetMoveChoice(PokelistWork *work, int choice);
void POKELIST_ShowMoveLearned(PokelistWork *work);
void POKELIST_OpenTakeItemMenu(PokelistWork *work);
void POKELIST_OnTakeItemChoice(PokelistWork *work, int choice);
void POKELIST_StartHpTransfer(PokelistWork *work);
void POKELIST_ShowHealResult(PokelistWork *work);
void POKELIST_OpenTakeMailMenu(PokelistWork *work);
void POKELIST_OnTakeMailChoice(PokelistWork *work, int choice);
void POKELIST_OpenMailItemMenu(PokelistWork *work);
void POKELIST_OnMailItemChoice(PokelistWork *work, int choice);
void POKELIST_EndMessageToEvolve(PokelistWork *work);
void POKELIST_ForceSelectionEnd(PokelistWork *work);
u32 POKELIST_FindMoveSlot(PokelistWork *work, void *mon);
void POKELIST_ReplaceMoveSlot(PokelistWork *work, void *mon, u32 slot);
void POKELIST_ApplyItemEffect(PokelistWork *work, void *mon);
void POKELIST_SetHeldItem(PokelistWork *work, void *mon, u16 itemId);
u32 POKELIST_CheckBagItem(PokelistWork *work, u16 itemId);
u32 POKELIST_RemoveBagItem(PokelistWork *work, u16 itemId);
u32 POKELIST_ReturnBagItem(PokelistWork *work, u16 itemId);
extern const char d_021BED0C[];
extern const PokelistNickname d_021BEA78;
extern const PokelistNickname d_021BEA84;
extern const u16 d_021BEA90[];
extern const u16 d_021BEA9C[];
extern u8 d_021BED80;
extern const PokelistBlend d_021BEBFC;
extern const PokelistBlend d_021BEC04;
extern s16 FX_SinCosTable_[];
extern PokelistVramBanks d_021BEC3C;
extern PokelistClactConfig gClActorInitParam;
extern char d_021BEAEC[];
extern char d_021BEAFC[];
extern char d_021BEB1C[];
extern char d_021BEB3C[];
extern char d_021BEB5C[];
extern char d_021BEB9C[];
extern char d_021BEBBC[];
extern char d_021BEBDC[];
extern char d_021BEB7C[];
extern char d_021BEAB8[];
extern char d_021BEAD0[];
extern char d_021BEAC4[];
extern const u8 d_021BEAB0[];
extern const u8 d_021BEAAA[];










/*
 * Byte-correct; the one wildcard is the arm9 call to 0x0201A354 (+0x10E).
 *   data run, the integrator's) has no witness outside this range. Verified C for it
 *   (from src/pending/ov/ov021_func_021B57CC.c, match.py one --thumb, EXACT,
 *   16 bytes):
 *     extern int ARC_TOOL_LoadMember();  (symbols: ARC_TOOL_LoadMember 0x02048F60 arm)
 *     int POKE_REGULATION_Load(int a, int b) { return ARC_TOOL_LoadMember(0x69, a, b); }
 *   Levers: the four 10-byte stack copies declared b, d, c, a (reverse of
 *   their frame order); t[4] spelled `k + 0xff11` (pool word, then +0xee
 *   for t[5]); `k = 0` before the b49 clear loop, which stores k.
 */
int POKELIST_Init(struct Proc *procObj, int *seq, PokelistArg *arg, PokelistWork *work)
{
    PokelistNickname b;
    PokelistNickname d;
    PokelistNickname c;
    PokelistNickname a;
    u8 i;
    u8 k;
    void *mon;
    PokelistRegulation *regulation;
    u16 *t;

    switch (*seq) {
    case 0:
        GFL_HEAP_CreateChildHeap(1, 0x17, 0x30000);
        work = PROCSYS_AllocProcWork(procObj, 0x284, 0x17);
        work->heapId = 0x17;
        if (arg == 0) {
            arg = func_02030734(0x17, 0x98, 1, d_021BED0C, 0x52);
            arg->party = POKEPARTY_Create(0x17);
            arg->selectedIndex = 0;
            POKEPARTY_InitEx(arg->party, 6);
            a = d_021BEA78;
            for (i = 0; i < 6; i++) {
                mon = POKE_TOOL_Create(d_021BEA90[i], d_021BEA9C[i], 0xffffffff, 0x17);
                b = a;
                POKE_TOOL_SetPartyValue(mon, 0x8e, (u32)&b);
                POKE_TOOL_SetPartyValue(mon, 0x9a, 0);
                POKEPARTY_Add(arg->party, mon);
                func_020307B0(mon);
            }
            arg->mode = 0;
            if (KEY_GetCont() & 0x100) {
                regulation = POKE_REGULATION_Load(0xf, 0x17);
                arg->regulation = regulation;
                regulation->minPartySize = 1;
                regulation->maxPartySize = 6;
                regulation->level = 1;
                regulation->levelRange = 0;
                regulation->mustPoke = 0;
                regulation->levelTotal = 0xc8;
                k = 0;
                for (i = 0; i < 6; i++)
                    arg->slotOrder[i] = 0;
                arg->mode = 0x16;
                for (k = 0; k < 3; k++) {
                    c = d_021BEA84;
                    arg->entries[k].party = POKEPARTY_Create(0x17);
                    for (i = 0; i < 6; i++) {
                        mon = POKE_TOOL_Create(func_02005728(0xfa), 0x64, 0xffffffff, 0x17);
                        d = c;
                        POKE_TOOL_SetPartyValue(mon, 0x8e, (u32)&d);
                        POKE_TOOL_SetPartyValue(mon, 0x9a, 0);
                        POKE_TOOL_SetPartyValue(mon, 6, func_02005728(2));
                        POKEPARTY_Add(arg->entries[k].party, mon);
                        func_020307B0(mon);
                    }
                    t = func_02030734(0x17, 0xc, 0, d_021BED0C, 0xae);
                    t[0] = 0x3077;
                    t[1] = 0x308c;
                    t[2] = 0x3044;
                    t[3] = 0x3084;
                    t[4] = k + 0xff11;
                    t[5] = 0xffff;
                    arg->entries[k].name = t;
                    arg->entries[k].gender = func_02005728(2);
                }
                arg->battleKind = 2;
                arg->timerShown = 1;
                arg->timerRunning = 1;
                arg->timeLeft = 0xff;
                arg->timerExpired = 0;
                POKE_REGULATION_FindValidOrder(regulation, arg->party, 0);
            } else if (KEY_GetCont() & 0x400) {
                arg->mode = 5;
                arg->itemId = 0x2c;
            } else if (KEY_GetCont() & 0x800) {
                arg->mode = 0x19;
            }
            func_020355D8(1);
        }
        work->arg = arg;
        *seq = 1;
    case 1:
        if (POKELIST_InitWork(work) == 1)
            return 1;
        break;
    }
    return 0;
}








int POKELIST_Exit(int procObj, int procArg, int procState, PokelistWork *work)
{
    u8 i;

    if (POKELIST_ExitWork(work) == 0)
        return 0;
    if (procState == 0) {
        for (i = 0; i < 3; i++) {
            if (work->arg->entries[i].party != 0)
                func_020307B0(work->arg->entries[i].party);
            if (work->arg->entries[i].name != 0)
                func_020307B0(work->arg->entries[i].name);
        }
        if (work->arg->regulation != 0)
            func_020307B0(work->arg->regulation);
        func_020307B0(work->arg->party);
        func_020307B0(work->arg);
    }
    func_020315D4((struct Proc *)procObj);
    GFL_HEAP_DeleteChecked(0x17);
    return 1;
}








int POKELIST_Main(int procObj, int procArg, int procState, PokelistWork *work)
{
    PokelistArg *arg;

    if (procState == 0) {
        arg = work->arg;
        if (arg->timerRunning == 1 && arg->timeLeft != 0) {
            d_021BED80++;
            if (d_021BED80 > 0x3c) {
                d_021BED80 = 0;
                arg->timeLeft = arg->timeLeft - 1;
            }
        }
    }
    if (POKELIST_UpdatePhase(work) == 1)
        return 1;
    return 0;
}








/*
 * The 0x160 table is indexed as `work + i * 4 + 0x160` (base plus scaled
 * index, then the field offset) and the list lookup goes through a temp:
 * that is what puts the row address after POKEPARTY_GetMember and keeps the
 * three 0x160 offsets as spilled loop invariants.
 */
int POKELIST_InitWork(PokelistWork *work)
{
    u8 n;
    u8 i;
    PokelistArg *arg;
    int e;

    n = POKEPARTY_GetCount(work->arg->party);
    work->touchMode = func_020355C4();
    work->menuChoice = 0x17;
    work->phase = 0;
    work->inputStage = 0;
    work->selectedSlot = 0;
    work->selectedMon = 0;
    work->swapSourceSlot = 9;
    work->healSourceSlot = 9;
    work->switchButtonEnabled = 0;
    work->fadeMode = 0;
    work->selectedCount = 0;
    work->fadeStep = 0;
    work->fadePhase = 0;
    work->reservedCounter = 0;
    work->waitFrames = 0;
    work->phaseCallback = 0;
    work->descriptor = 0;
    work->pressedButtonActor = 0;
    work->commandButtons[0] = 0;
    work->commandButtons[1] = 0;
    work->selectionConfirmed = 0;
    work->evolveCheckKind = 0;
    work->touchDragState = 0;
    work->reservedWord = 0;
    work->arg->closeRequested = 0;
    work->allowDisabledSelect = 1;
    work->healSoundPending = 0;
    for (i = 0; i < 0x17; i++)
        (&work->charRes[0])[i] = -1;
    work->restoreMode19 = work->arg->mode == 0x19 ? 1 : 0;
    arg = work->arg;
    if (arg->mode == 0x18) {
        arg->mode = 3;
        work->restoreMode18 = 1;
    } else {
        work->restoreMode18 = 0;
    }
    arg = work->arg;
    if (arg->mode == 0x1a) {
        arg->mode = 1;
        work->restoreMode1A = 1;
    } else {
        work->restoreMode1A = 0;
    }
    arg = work->arg;
    if (arg->mode == 6 && arg->moveId == 0)
        work->arg->moveId = FILE_UTIL_Get_12B0(arg->itemId);
    POKELIST_SetupDisplay(work);
    POKELIST_LoadGraphics(work);
    POKELIST_CreateFonts(work);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            e = (int)POKEPARTY_GetMember(work->arg->party, i);
            work->plates[i] = PLIST_PLATE_Create(work, i, (void *)e);
        } else
            work->plates[i] = PLIST_PLATE_CreateEmpty(work, i);
        if (PLIST_PLATE_GetLabelState(work->plates[i]) <= 5)
            work->selectedCount++;
    }
    work->taskMenu = (int)APP_TASKMENU_RES_Create(0, 1, work->fontMain, work->printSys, work->heapId);
    POKELIST_CreateClactUnit(work);
    if (POKELIST_IsItemMode(work) == 1)
        PLIST_MENU_InitTimer(work);
    work->updateTask = func_020056A0(POKELIST_UpdateWindowMaskTask, work, 8);
    work->messageWindow = (int)PLIST_MESSAGE_Create(work);
    work->contextMenu = (int)PLIST_MENU_Create(work);
    POKELIST_StartMode(work);
    func_02041B6C(3);
    func_02041B6C(2);
    func_02041B6C(7);
    GFL_NET_RestartWithDefaultTimeout(1, work->heapId);
    return 1;
}








int POKELIST_ExitWork(PokelistWork *work)
{
    u8 i;

    func_02030EAC((struct Node *)work->updateTask);
    if (POKELIST_IsItemMode(work) == 1) {
        PLIST_MENU_DeleteTaskMenuWin(work->commandButtons[0]);
        PLIST_MENU_DeleteTaskMenuWin(work->commandButtons[1]);
        work->commandButtons[0] = 0;
        work->commandButtons[1] = 0;
    }
    PLIST_MENU_Delete(work, (unsigned char *)work->contextMenu);
    PLIST_MESSAGE_Destroy(work, (int *)work->messageWindow);
    if (work->descriptor != 0)
        BMP_WIN_Delete((struct Descriptor *)work->descriptor);
    for (i = 0; i < 6; i++)
        PLIST_PLATE_Delete(work, work->plates[i]);
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)work->taskMenu);
    POKELIST_DeleteFonts(work);
    if (POKELIST_IsItemMode(work) == 1)
        PLIST_MENU_ExitTimer(work);
    POKELIST_DeleteClactUnit(work);
    POKELIST_FreeGraphics(work);
    POKELIST_ShutdownDisplay(work);
    if (work->restoreMode18 == 1)
        work->arg->mode = 0x18;
    if (work->restoreMode19 == 1)
        work->arg->mode = 0x19;
    if (work->restoreMode1A == 1)
        work->arg->mode = 0x1a;
    func_020355D8(work->touchMode);
    return 1;
}








/*
 * Case 20 is written before case 19: case 19's fallback repeats case 20's
 * body and mwcc tail-merges it into the earlier copy, which puts case 20's
 * code first in the original.
 */
int POKELIST_UpdatePhase(PokelistWork *work)
{
    u8 i;
    PokelistFn fn;

    switch (work->phase) {
    case 0:
        WIPE_SYS_Start((void *)2, 1, 1, 0, 6, 1, work->heapId);
        work->phase = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            work->phase = work->nextPhase;
        break;
    case 2:
    case 3:
    case 4:
        POKELIST_UpdateInputStage(work);
        break;
    case 5:
        POKELIST_UpdateSwapAnimation(work);
        break;
    case 6:
        POKELIST_RunContextMenu(work);
        break;
    case 7:
        POKELIST_UpdateMessagePhase(work);
        break;
    case 9:
        POKELIST_PollContextMenuChoice(work);
        break;
    case 10:
        PLIST_PLATE_StartHpAnim(work, work->plates[work->selectedSlot]);
        if (work->healSoundPending == 1) {
            work->healSoundPending = 0;
            GFL_USE_PlaySeDefaultVolume(0x56f);
        }
        work->phase = 0xb;
    case 11:
        if (PLIST_PLATE_StepHpAnim(work, work->plates[work->selectedSlot]) == 1) {
            fn = work->phaseCallback;
            if (fn != 0)
                fn(work);
            else
                work->phase = 0x15;
        }
        break;
    case 12:
        work->waitFrames++;
        if (work->waitFrames > 0x10) {
            if (work->restoreMode1A == 1) {
                if (PLIST_COMM_SendStatus(work->arg, 0, 0) == 1) {
                    work->phase = 0x11;
                    PLIST_MENU_DeleteTaskMenuWin(work->commandButtons[0]);
                    PLIST_MENU_DeleteTaskMenuWin(work->commandButtons[1]);
                    work->commandButtons[0] = 0;
                    work->commandButtons[1] = 0;
                    PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
                    PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0xb0);
                    PLIST_MESSAGE_RequestPrompt(work, (u8 *)work->messageWindow);
                }
            } else {
                work->phase = 0x13;
            }
        }
        break;
    case 13:
        PLIST_MENU_UpdateLevelUp(work);
        break;
    case 14:
        PLIST_BATTLE_StartEffect(work);
        break;
    case 15:
        PLIST_BATTLE_UpdateEffect(work);
        break;
    case 16:
        PLIST_BATTLE_FinishEffect(work);
        break;
    case 17:
        PLIST_COMM_StartSync(work->arg, 2);
        work->phase = 0x12;
        break;
    case 18:
        if (PLIST_COMM_IsSyncDoneOrFinished(work->arg, 2) == 1)
            work->phase = 0x13;
        break;
    case 20:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
        work->phase = 0x15;
        break;
    case 19:
        if (work->pressedButtonActor == 0 || CLACT_IsActorAnimActive((struct Actor *)work->pressedButtonActor) == 0) {
            WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
            work->phase = 0x15;
        }
        break;
    case 21:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    for (i = 0; i < 6; i++)
        PLIST_PLATE_Update(work, work->plates[i]);
    PLIST_MESSAGE_Update(work, (u8 *)work->messageWindow);
    POKELIST_UpdatePaletteFade(work);
    if (POKELIST_IsItemMode(work) == 1) {
        PLIST_MENU_UpdateTimer(work);
        PLIST_MENU_UpdateTaskMenuWin(work->commandButtons[0]);
        PLIST_MENU_UpdateTaskMenuWin(work->commandButtons[1]);
    }
    PRINTSYS_QUE_Main((struct PrintSys *)work->printSys);
    CLACT_DrawSystem();
    return 0;
}








/*
 * Palette fade (u8 step countdown at +0x100, brighten src[3][16] into dst, skipping
 * columns 2..4, then a sine blend of dst[i][2..4] between two 3-colour tables, then
 * func_02061CA4(15, 0xc0, dst, 0x60)).
 * note: final push 2026-10-05 G9L1, EXACT in c99 and c. Four source facts closed the draft
 * (182 B off): (1) the phase update stores in each if/else arm (work->phase = work->phase - 0xfc00
 * or work->phase = t), so the 0x102 offset stays live in r1 and v sits in r3; (2) each blended
 * channel is clamped into a shared int t (`...; r = t;`) and assigned to a u8 local, which
 * puts the byte truncation at the join as in the image; (3) the blend deltas are written
 * red first (ar, br, dr, then green, then blue); the scheduler still emits green first, but
 * the red values are born first and take the registers the image shows; (4) f is declared
 * after the counters, and b is u16 while a is int. Earlier notes: hi and lo are two PokelistBlend
 * locals, each delta is read three times (clamp), tried-and-failed forms in git history.
 * Callee 02061CA4 matches its 4-parameter definition.
 */
void POKELIST_UpdatePaletteFade(PokelistWork *work)
{
    u8 i;
    u8 i2;
    u8 j;
    u8 j2;
    u8 k;
    int f;
    PokelistBlend hi;
    PokelistBlend lo;

    MIi_CpuCopy16(work->palSrc, work->palDst, 0x60);
    if (work->fadeStep != 0) {
        work->fadeStep--;
        k = work->fadeStep;
        if (k > 6) {
            k = 12 - k;
        }
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 16; j++) {
                if (j >= 2 && j <= 4) {
                    continue;
                }
                {
                    u16 c = work->palSrc[i][j];
                    u8 g = (c & 0x3e0) >> 5;
                    u8 b = (c & 0x7c00) >> 10;
                    u8 r = c & 0x1f;
                    int t;
                    t = r + k * 2;
                    if (t > 31) t = 31;
                    r = t;
                    t = g + k * 2;
                    if (t > 31) t = 31;
                    g = t;
                    t = b + k * 2;
                    if (t > 31) t = 31;
                    b = t;
                    work->palDst[i][j] = r | (g << 5) | (b << 10);
                }
            }
        }
    }
    hi = d_021BEBFC;
    lo = d_021BEC04;
    if (work->fadeMode == 0) {
        int t = work->fadePhase + 0x400;
        if (t >= 0x10000) {
            work->fadePhase = work->fadePhase - 0xfc00;
        } else {
            work->fadePhase = t;
        }
    } else {
        work->fadePhase = 0xc000;
    }
    f = (FX_SinCosTable_[(work->fadePhase >> 4) * 2] + 0x1000) / 2;
    for (i2 = 0; i2 < 3; i2++) {
        for (j2 = 0; j2 < 3; j2++) {
            int a = hi.v[j2];
            u16 b = lo.v[j2];
            u8 ar = a & 0x1f;
            u8 br = b & 0x1f;
            s8 dr = ((br - ar) * f) >> 12;
            u8 ag = (a & 0x3e0) >> 5;
            u8 bg = (b & 0x3e0) >> 5;
            s8 dg = ((bg - ag) * f) >> 12;
            u8 ab = (a & 0x7c00) >> 10;
            u8 bb = (b & 0x7c00) >> 10;
            s8 db = ((bb - ab) * f) >> 12;
            u8 r, g, bl;
            int t;
            if (ar + dr > 31) t = 31; else if (ar + dr < 0) t = 0; else t = ar + dr;
            r = t;
            if (ag + dg > 31) t = 31; else if (ag + dg < 0) t = 0; else t = ag + dg;
            g = t;
            if (ab + db > 31) t = 31; else if (ab + db < 0) t = 0; else t = ab + db;
            bl = t;
            work->palDst[i2][j2 + 2] = r | (g << 5) | (bl << 10);
        }
    }
    func_02061CA4((void *)15, 0xc0, (u32)work->palDst, 0x60);
}








static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}








void POKELIST_UpdateWindowMaskTask(void *tcb, PokelistWork *work)
{
    if (work->fadeMode == 1)
        GX_SetVisibleWnd(1);
    else
        GX_SetVisibleWnd(0);
    CLACT_VBlankSystem();
}






static inline void GX_SetVisiblePlane(int plane)
{
    reg_GX_DISPCNT = (u32)((reg_GX_DISPCNT & ~0x1f00) | (plane << 8));
}






static inline void GXS_SetVisiblePlane(int plane)
{
    reg_GXS_DB_DISPCNT = (u32)((reg_GXS_DB_DISPCNT & ~0x1f00) | (plane << 8));
}






static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~0x8000) | (sel << 15));
}






void POKELIST_SetupDisplay(PokelistWork *work)
{
    PokelistVramBanks a;
    PokelistClactConfig b;

    a = d_021BEC3C;
    if (POKELIST_IsItemMode(work) == 1) {
        a.w[6] = 8;
        a.w[8] = 0;
    } else {
        a.w[6] = 0x100;
    }
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    WIPE_SetBrightnessFadeOut(0, 0);
    WIPE_SetBrightnessFadeOut(1, 0);
    WIPE_ResetWndMask(0);
    WIPE_ResetWndMask(1);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    BG_SYS_SetVramBanks((const struct DispVram *)(&a));
    BG_SYS_Create(work->heapId);
    BMP_WIN_Init(work->heapId);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BEAEC);
    POKELIST_LoadBgPlane(d_021BEBDC, 3, 0);
    POKELIST_LoadBgPlane(d_021BEBBC, 2, 0);
    POKELIST_LoadBgPlane(d_021BEB9C, 1, 0);
    POKELIST_LoadBgPlane(d_021BEB5C, 7, 0);
    POKELIST_LoadBgPlane(d_021BEB3C, 6, 0);
    POKELIST_LoadBgPlane(d_021BEB1C, 5, 0);
    POKELIST_LoadBgPlane(d_021BEAFC, 4, 0);
    POKELIST_SetupBgPlanes(work);
    func_0207D63C(0x04000050, 0x14, 8, 0x10, 10);
    func_0207D63C(0x04001050, 4, 8, 0x10, 10);
    BG_SYS_FillScrollArea(2, 0, 0x80);
    BG_SYS_FillScrollArea(1, 0, 0x80);
    b = gClActorInitParam;
    CLACT_InitSystem((const struct Cfg *)(&b), (u32)(&a), work->heapId);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    NNS_GfdResetVramTransferTaskQueue();
}




void POKELIST_SetupBgPlanes(PokelistWork *work) { GX_SetGraphicsMode(1,0,0); POKELIST_LoadBgPlane(d_021BEB7C,0,0); }





void POKELIST_SetupLight(PokelistWork *work)
{
    int r;

    GX_SetGraphicsMode(1, 0, 1);
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, work->heapId, 0);
    *(volatile u16 *)0x04000008 = *(volatile u16 *)0x04000008 & ~3;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x20;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    r = G3D_CAMERA_Create(2, 0, 0x50D7, 0, 0x6BCA, 0x1000, 0x80000, 0, d_021BEAB8, d_021BEAD0, d_021BEAC4, work->heapId);
    work->light = r;
    func_02048AD0((struct Light *)r);
    func_0207D63C(0x04000050, 4, 0x1e, 0x10, 10);
    PARTICLE_InitManager(work->heapId);
}





/*
 * `ldr ip,[pc,#4]; ldr r0,[pc,#4]; bx ip; .word 0x02061B5C; .word 0x02146B80`,
 * no witness outside this range.  Leaf C tried (DIFF only, the two loads and
 * the two pool words come out swapped, 8 bytes):
 *   extern void NNSi_GfdResetVramTransferTaskQueue(void *); extern char d_02146B80[];
 *   void NNS_GfdResetVramTransferTaskQueue(void) { NNSi_GfdResetVramTransferTaskQueue(d_02146B80); }
 *   (`return NNSi_GfdResetVramTransferTaskQueue((int)d_02146B80)` with int types: same DIFF)
 */
void POKELIST_ShutdownDisplay(PokelistWork *work)
{
    NNS_GfdResetVramTransferTaskQueue();
    CLACT_ExitSystem();
    POKELIST_ShutdownBgPlane0(work);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}




void POKELIST_ShutdownBgPlane0(PokelistWork *work)
{
    BG_SYS_FreeLayerBuf(0);
}



void POKELIST_ShutdownLight(PokelistWork *work) { PARTICLE_ExitManager(); G3D_CAMERA_Delete((void *)(work->light)); G3D_SYSTEM_Exit(); BG_SYS_FreeLayerBuf(0); func_0207D63C(0x04000050,20,8,16,10); }



void POKELIST_LoadBgPlane(const void *work, unsigned id,unsigned type) { BG_SYS_InitBgLayer(id,work,type); func_02040588(id,1); BG_SYS_FreeSlot(id); BG_SYS_PushTile(id); }




void POKELIST_CreateClactUnit(PokelistWork *work)
{
    PokelistActorTemplate cursorTemplate;
    PokelistActorTemplate buttonTemplate;
    struct Obj *x;
    struct Bank *bank;

    bank = CLACT_CreateUnit(10, 8, work->heapId);
    work->clactUnit = bank;
    CLACT_SetUnitDefaultRenderer(bank);
    cursorTemplate.x = 0;
    cursorTemplate.y = 0;
    cursorTemplate.animNo = 0;
    cursorTemplate.priority = 10;
    cursorTemplate.drawArea = 3;
    work->cursorActor = CLACT_CreateActor(work->clactUnit, work->palRes[0],
                                        work->charRes[0], work->cellRes[0], &cursorTemplate, 0, work->heapId);
    work->swapMarkerActor = CLACT_CreateActor(work->clactUnit, work->palRes[0],
                                        work->charRes[0], work->cellRes[0], &cursorTemplate, 0, work->heapId);
    CLACT_SetActorAutoAnim(work->cursorActor, 1);
    CLACT_SetActorAutoAnim(work->swapMarkerActor, 1);
    CLACT_SetActorDrawEnable(work->cursorActor, 0);
    CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
    buttonTemplate.x = 0xe0;
    buttonTemplate.y = 0xa8;
    buttonTemplate.animNo = 1;
    buttonTemplate.priority = 0;
    buttonTemplate.drawArea = 0;
    x = CLACT_CreateActor(work->clactUnit, work->palRes[2],
                      work->charRes[1], work->cellRes[2], &buttonTemplate, 0, work->heapId);
    work->backButtonActor = x;
    CLACT_SetActorAutoAnim(x, 1);
    buttonTemplate.x = 0xc4;
    buttonTemplate.animNo = 0;
    x = CLACT_CreateActor(work->clactUnit, work->palRes[2],
                      work->charRes[1], work->cellRes[2], &buttonTemplate, 0, work->heapId);
    work->switchButtonActor = x;
    CLACT_SetActorAutoAnim(x, 1);
}


void POKELIST_DeleteClactUnit(PokelistWork *work) { CLACT_DeleteActor(work->backButtonActor); CLACT_DeleteActor(work->switchButtonActor); CLACT_DeleteActor(work->cursorActor); CLACT_DeleteActor(work->swapMarkerActor); CLACT_DeleteUnit(work->clactUnit); }



void POKELIST_CreateFonts(PokelistWork *work)
{
    work->fontMain = GF_FONT_Create(0x17, 0, 0, 0, work->heapId);
    work->fontSub = GF_FONT_Create(0x17, 3, 0, 0, work->heapId);
    work->msgBank = func_02045B38(0, 2, 0x9d, work->heapId);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, work->heapId);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, work->heapId);
    work->printSys = PRINTSYS_QUE_CreateEx(0x1800, work->heapId);
    GF_FONT_SetDefaultTextColor();
}


void POKELIST_DeleteFonts(PokelistWork *work) { PRINTSYS_QUE_Clear((struct PrintSys *)(work->printSys)); PRINTSYS_QUE_Delete((struct PrintSys *)(work->printSys)); MSGDATA_Delete((struct Rec *)(work->msgBank)); GF_FONT_Delete(work->fontSub); GF_FONT_Delete(work->fontMain); }



/*
 * Graphics setup: loads BG/char/screen/palette data from archive 0x4c, the
 * 0x07 archive and the APP_ICON_GetArchiveId archive into work's handle table
 * (work+0x178..0x1d0), then copies palette RAM 0x050000C0 back to work+0x40.
 * The second-archive loads still pass the first (closed) handle to
 * func_02049B68/02049658/020498F4, as the original does.  The 0x158 store
 * goes through a local: stored directly, the allocator rematerialises the
 * shared 0xc0 offset base instead of reloading its [sp+0xc] spill slot.
 */
void POKELIST_LoadGraphics(PokelistWork *work)
{
    void *h;
    void *h2;
    void *t;

    h = func_020490F4(0x4c, work->heapId);
    func_02049B68(h, 6, 0, 0, 0, work->heapId);
    func_02049B68(h, 0, 0, 0x1a0, 0x20, work->heapId);
    func_02049658(h, 0xf, 3, 0, 0, 0, work->heapId);
    func_020498F4(h, 0x14, 3, 0, 0, 0, work->heapId);
    func_02049658(h, 0xc, 2, 0, 0, 0, work->heapId);
    t = func_02049EF4(h, 0x12, 0, &work->paletteData, work->heapId);
    work->paletteFile = t;
    func_02049B68(h, 5, 4, 0, 0, work->heapId);
    func_02049658(h, 0xe, 7, 0, 0, 0, work->heapId);
    func_020498F4(h, 0x13, 7, 0, 0, 0, work->heapId);
    work->charRes[0] = CLACT_RegisterPaletteEx(h, 4, 0, 0, 0, 3, work->heapId);
    work->palRes[0] = CLACT_RegisterCharacter(h, 0xb, 0, 0, work->heapId);
    work->palRes[1] = CLACT_RegisterCharacter(h, 8, 0, 0, work->heapId);
    work->cellRes[0] = CLACT_RegisterCellAnim(h, 0x17, 0x1a, work->heapId);
    work->cellRes[1] = CLACT_RegisterCellAnim(h, 0x16, 0x19, work->heapId);
    ARC_TOOL_DeleteHandle(h);

    h2 = func_020490F4(7, work->heapId);
    work->charRes[6] = CLACT_RegisterPaletteCompressed(h2, func_0201BC3C(), 0, 0xc0, work->heapId);
    work->cellRes[7] = CLACT_RegisterCellAnim(h2, func_0201BC40(), func_0201BCB4(), work->heapId);
    ARC_TOOL_DeleteHandle(h2);

    h2 = func_020490F4(APP_ICON_GetArchiveId(), work->heapId);
    func_02049B68(h, APP_ICON_GetStatusAnimFileId(), 0, 0x160, 0x20, work->heapId);
    func_02049658(h, APP_ICON_GetStatusFrameFileId(), 1, 0, 0, 0, work->heapId);
    func_020498F4(h, APP_ICON_GetStatusExtraFileId(), 1, 0, 0, 0, work->heapId);
    BG_SYS_FillTileMap(1, 0, 0, 0x40, 0x20, 0xb);
    work->charRes[5] = CLACT_RegisterPaletteEx(h2, APP_ICON_GetNoneFileId(), 0, 0xa0, 0, 1, work->heapId);
    work->palRes[6] = CLACT_RegisterCharacter(h2, APP_ICON_GetGearCellFileId(2), 0, 0, work->heapId);
    work->cellRes[6] = CLACT_RegisterCellAnim(h2, APP_ICON_GetGearPaletteFileId(2), APP_ICON_GetGearAnimFileId(2), work->heapId);
    work->charRes[1] = CLACT_RegisterPaletteEx(h2, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x120, 0, 3, work->heapId);
    work->palRes[2] = CLACT_RegisterCharacter(h2, APP_ICON_GetMoveKindAnimFileId(), 0, 0, work->heapId);
    work->cellRes[2] = CLACT_RegisterCellAnim(h2, APP_ICON_GetStatusCellFileId(2), APP_ICON_GetStatusPaletteFileId(2), work->heapId);
    work->charRes[2] = CLACT_RegisterPaletteEx(h2, APP_ICON_GetItemCellFileId(), 0, 0x60, 0, 1, work->heapId);
    work->palRes[3] = CLACT_RegisterCharacter(h2, APP_ICON_GetItemPaletteFileId(), 0, 0, work->heapId);
    work->cellRes[3] = CLACT_RegisterCellAnim(h2, APP_ICON_GetItemAnimFileId(2), APP_ICON_GetItemFrameFileId(2), work->heapId);
    work->charRes[4] = CLACT_RegisterPaletteEx(h2, APP_ICON_GetSealCellFileId(), 0, 0x80, 0, 1, work->heapId);
    work->palRes[5] = CLACT_RegisterCharacter(h2, APP_ICON_GetSealPaletteFileId(), 0, 0, work->heapId);
    work->cellRes[5] = CLACT_RegisterCellAnim(h2, APP_ICON_GetSealAnimFileId(2), APP_ICON_GetSealFrameFileId(2), work->heapId);
    ARC_TOOL_DeleteHandle(h2);
    MIi_CpuCopy16((void *)0x050000C0, (u8 *)work->palSrc, 0x60);
}



void POKELIST_FreeGraphics(PokelistWork *work)
{
    u8 i;

    func_020307B0(work->paletteFile);
    for (i = 0; i < 8; i++) {
        if ((&work->charRes[0])[i] != -1)
            CLACT_ReleasePalette((&work->charRes[0])[i]);
    }
    for (i = 8; i < 15; i++) {
        if ((&work->charRes[0])[i] != -1)
            CLACT_ReleaseCharacter((&work->charRes[0])[i]);
    }
    for (i = 15; i < 23; i++) {
        if ((&work->charRes[0])[i] != -1)
            CLACT_ReleaseCellAnim((&work->charRes[0])[i]);
    }
}

#undef W



/*
 * lever: one named offset shared across the case 7/8 branch join.
 */
void POKELIST_StartMode(PokelistWork *work)
{
    u32 old;
    int r,id,off;
    switch ((u32)work->arg->mode) {
    case 1:
        work->commandButtons[0]=PLIST_MENU_CreateButtonWindow(work,work->contextMenu,0,0x16,0x15,0);
        POKELIST_SetupModeScreen(work); work->nextPhase=2; return;
    case 22: case 23:
        work->commandButtons[0]=PLIST_MENU_CreateButtonWindow(work,work->contextMenu,0,0xc,0x15,0);
        work->commandButtons[1]=PLIST_MENU_CreateButtonWindow(work,work->contextMenu,1,0x16,0x15,1);
        POKELIST_SetupModeScreen(work); work->nextPhase=2; return;
    case 0: case 6: case 9: case 14: case 16: case 18: case 21: case 25:
        POKELIST_SetupModeScreen(work); work->nextPhase=2; return;
    case 3:
        work->switchButtonEnabled=0; POKELIST_SetupModeScreen(work); work->nextPhase=2; return;
    case 5:
        if (PLIST_MENU_ItemRestoresHp(work,(void *)work->arg->itemId)==1) {
            r=PLIST_MENU_FindItemTarget(work);
            if (r != -1) {
                work->selectedSlot=r; work->selectedMon=(u32)POKEPARTY_GetMember(work->arg->party,r);
                PLIST_MENU_StartItemUse(work,0);
                PLIST_DEMO_UseItemOnMon((void *)work->selectedMon,work->arg->itemId,(int)0,work->arg->itemUseParam,(u16)(work->heapId));
                PLIST_PLATE_Redraw(work,work->plates[work->selectedSlot]);
                work->healSoundPending=1; work->nextPhase=work->phase; work->phase=0;
                POKELIST_RemoveBagItem(work,work->arg->itemId); return;
            }
            PLIST_MENU_ShowItemUsedThenClose(work); work->nextPhase=work->phase; work->phase=0; return;
        }
        if (POKELIST_CheckBagItem(work,work->arg->itemId) != 0) {
            POKELIST_SetupModeScreen(work); work->nextPhase=2; return;
        }
        work->arg->exitCode=10;
        PLIST_MESSAGE_CloseWindow(work,(u32 *)work->messageWindow); PLIST_MESSAGE_CreateWordSet(work,work->messageWindow);
        PLIST_MESSAGE_SetWordSetItem(work,work->messageWindow,(u32)0,(u16)work->arg->itemId);
        POKELIST_ShowMessage(work,0xb3,1,POKELIST_EndMessageToExit);
        PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); work->nextPhase=work->phase; work->phase=0; return;
    case 7: case 8:
        work->selectedSlot=work->arg->selectedIndex; work->selectedMon=(u32)POKEPARTY_GetMember(work->arg->party,work->arg->selectedIndex);
        if (work->arg->moveSlot < 4) {
            old=func_02017E1C((void *)work->selectedMon,work->arg->moveSlot+0x36,0);
            off=0x150;
            PLIST_MESSAGE_CreateWordSet(work,(*(int *)((u8 *)work + off))); PLIST_MESSAGE_SetWordSetPokemon(work,(*(int *)((u8 *)work + off)),0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work,(u32)(*(int *)((u8 *)work + off)),(u32)1,(u16)old);
            POKELIST_ShowMessage(work,0x28,1,POKELIST_ShowMoveLearned);
        } else {
            off=0x150;
            PLIST_MESSAGE_CreateWordSet(work,(*(int *)((u8 *)work + off))); PLIST_MESSAGE_SetWordSetMove(work,(u32)(*(int *)((u8 *)work + off)),(u32)1,(u16)work->arg->moveId);
            POKELIST_ShowMessage(work,0x23,0,POKELIST_OpenForgetMoveMenu);
        }
        PLIST_MESSAGE_DestroyWordSet(work,(*(int *)((u8 *)work + off)));
        work->nextPhase=7; work->phase=0; work->switchButtonEnabled=0;
        PLIST_PLATE_SetSelected(work,work->plates[work->selectedSlot],1); return;
    case 10:
        work->selectedSlot=work->arg->selectedIndex; work->selectedMon=(u32)POKEPARTY_GetMember(work->arg->party,work->arg->selectedIndex);
        if (work->arg->itemId == 0) {
            work->arg->mode=0; POKELIST_SetupModeScreen(work); work->nextPhase=2;
        } else {
            old=func_02017E1C((void *)work->selectedMon,6,0);
            if (old == 0) {
                POKELIST_SetHeldItem(work,(void *)work->selectedMon,work->arg->itemId);
                PLIST_PLATE_Redraw(work,work->plates[work->selectedSlot]);
                PLIST_MESSAGE_CreateWordSet(work,work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
                PLIST_MESSAGE_SetWordSetItem(work,work->messageWindow,(u32)1,(u16)work->arg->itemId);
                PLIST_MENU_ApplyArceusPlateForm(work,(void *)work->selectedMon,(u16)work->arg->itemId);
                PLIST_MENU_ApplyGenesectDriveForm(work,(void *)work->selectedMon,work->arg->itemId);
                if (PLIST_DEMO_CheckGiratinaToOrigin(work,(void *)work->selectedMon)==1) {
                    PLIST_DEMO_ApplyGiratinaOriginForm(work,(void *)work->selectedMon); POKELIST_ShowMessage(work,0x56,1,POKELIST_EndMessageToEvolve); work->evolveCheckKind=1;
                } else POKELIST_ShowMessage(work,0x56,1,POKELIST_CloseMessageToList);
                PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); work->arg->mode=0;
            } else {
                PLIST_MESSAGE_CreateWordSet(work,work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
                PLIST_MESSAGE_SetWordSetItemAlt(work,work->messageWindow,1,(u16)old);
                POKELIST_ShowMessage(work,0x3a,0,POKELIST_OpenTakeItemMenu); PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow);
            }
        }
        work->nextPhase=7; work->phase=0; work->switchButtonEnabled=1;
        PLIST_PLATE_SetSelected(work,work->plates[work->selectedSlot],1); return;
    case 11: case 12:
        work->selectedSlot=work->arg->selectedIndex; work->selectedMon=(u32)POKEPARTY_GetMember(work->arg->party,work->arg->selectedIndex);
        old=func_02017E1C((void *)work->selectedMon,6,0);
        PLIST_MESSAGE_CreateWordSet(work,work->messageWindow);
        if (old == 0) {
            id=0x56;
            PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetItem(work,work->messageWindow,(u32)1,(u16)work->arg->itemId);
        } else {
            id=0x40;
            PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetItem(work,work->messageWindow,(u32)1,(u16)old);
            PLIST_MESSAGE_SetWordSetItem(work,work->messageWindow,(u32)2,(u16)work->arg->itemId);
        }
        POKELIST_SetHeldItem(work,(void *)work->selectedMon,work->arg->itemId);
        PLIST_PLATE_Redraw(work,work->plates[work->selectedSlot]);
        PLIST_MENU_ApplyArceusPlateForm(work,(void *)work->selectedMon,(u16)work->arg->itemId);
        PLIST_MENU_ApplyGenesectDriveForm(work,(void *)work->selectedMon,work->arg->itemId);
        if (PLIST_DEMO_CheckGiratinaToAltered(work,(void *)work->selectedMon)==1) {
            PLIST_DEMO_ApplyGiratinaAlteredForm(work,(void *)work->selectedMon); POKELIST_ShowMessage(work,id,1,POKELIST_EndMessageToEvolve); work->evolveCheckKind=2;
        } else if (work->arg->mode==11) POKELIST_ShowMessage(work,id,1,POKELIST_EndMessageToExit);
        else POKELIST_ShowMessage(work,id,1,POKELIST_CloseMessageToList);
        PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow);
        if (work->arg->mode==11) work->arg->exitCode=10; else work->arg->mode=0;
        work->nextPhase=7; work->phase=0; work->switchButtonEnabled=1;
        break;
    }
}



/*
 * EXACT*: the listing extent's last two bytes (0x021B7CC2) are alignment
 * padding before the next function, not a follower.
 */
void POKELIST_SetupModeScreen(PokelistWork *work)
{
    BG_SYS_PushTile(0);
    switch (work->arg->mode) {
    case 0:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 9);
        work->switchButtonEnabled = 1;
        break;
    case 1:
        PLIST_BATTLE_RefreshOpponentMessage(work);
        CLACT_SetActorDrawEnable(work->backButtonActor, 0);
        work->switchButtonEnabled = 0;
        break;
    case 22:
    case 23:
        work->switchButtonEnabled = 0;
        break;
    case 5:
    case 16:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0xd);
        work->switchButtonEnabled = 0;
        work->allowDisabledSelect = 0;
        break;
    case 9:
    case 14:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0xc);
        work->switchButtonEnabled = 0;
        work->allowDisabledSelect = 0;
        break;
    case 6:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0xe);
        work->switchButtonEnabled = 0;
        work->allowDisabledSelect = 0;
        break;
    case 18:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0x10);
        work->switchButtonEnabled = 0;
        break;
    case 3:
    case 25:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 9);
        work->switchButtonEnabled = 0;
        break;
    case 21:
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0xa3);
        CLACT_SetActorDrawEnable(work->backButtonActor, 0);
        work->switchButtonEnabled = 0;
        break;
    }
    POKELIST_RefreshCursor(work);
}


#undef W

#undef W


void POKELIST_ApplySelection(PokelistWork *work)
{
    u32 old,buf;
    int r;
    if (work->arg->closeRequested == 1) { work->phase=0x13; return; }
    switch ((u32)work->arg->mode) {
    case 0: case 1: case 18: case 21: case 22: case 23: case 25:
        POKELIST_EnterMenuPhase(work); BG_SYS_PushTile(0); POKELIST_OpenContextMenu(work); return;
    case 5:
        if (PLIST_MENU_IsSpecialItemKind(work,work->arg->itemId) == 1) {
            POKELIST_EnterMenuPhase(work); POKELIST_OpenContextMenu(work); return;
        }
        if (PLIST_DEMO_CheckItemUsable((void *)work->selectedMon,(u16)work->arg->itemId,0,(u16)(work->heapId)) == 1) {
            r=PLIST_MENU_StartItemUse(work,0);
            PLIST_DEMO_UseItemOnMon((void *)work->selectedMon,work->arg->itemId,(int)0,work->arg->itemUseParam,(u16)(work->heapId));
            if (r == 2) PLIST_PLATE_SetMon(work,work->plates[work->selectedSlot],(void *)work->selectedMon,0);
            else if (r == 19 || r == 13) {
                PLIST_PLATE_SetMon(work,work->plates[work->selectedSlot],(void *)work->selectedMon,0);
                GFL_USE_PlaySeDefaultVolume(0x56f);
            } else {
                PLIST_PLATE_Redraw(work,work->plates[work->selectedSlot]);
                GFL_USE_PlaySeDefaultVolume(0x56f);
            }
            POKELIST_RemoveBagItem(work,work->arg->itemId); return;
        }
        if (work->arg->itemId==0x1d2 && PLIST_DEMO_CanUseGracidea(work,work->selectedMon)==1) {
            PLIST_DEMO_ApplyShayminSkyForm(work,(void *)work->selectedMon); work->arg->exitCode=10; work->phase=14; work->evolveCheckKind=3; return;
        }
        PLIST_MENU_ShowItemUsedThenContinue(work); return;
    case 16:
        if (POKELIST_CheckEvolution(work,(void *)work->selectedMon,work->arg->itemId) != 0) {
            POKELIST_RemoveBagItem(work,work->arg->itemId); work->phase=19; work->arg->selectedIndex=work->selectedSlot; work->arg->exitCode=8;
        } else POKELIST_ShowMessage(work,0x51,1,POKELIST_EndMessageToExit);
        return;
    case 9:
        old=func_02017E1C((void *)work->selectedMon,6,0);
        if (old == 0) {
            if (FILE_UTIL_Check136C(work->arg->itemId) == 1) {
                work->phase=19; work->arg->selectedIndex=work->selectedSlot; work->arg->exitCode=6; return;
            }
            work->arg->exitCode=10;
            POKELIST_SetHeldItem(work,(void *)work->selectedMon,work->arg->itemId);
            PLIST_PLATE_Redraw(work,work->plates[work->selectedSlot]);
            PLIST_MESSAGE_CreateWordSet(work,work->messageWindow);
            PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetItem(work,work->messageWindow,1,work->arg->itemId);
            PLIST_MENU_ApplyArceusPlateForm(work,(void *)work->selectedMon,(u16)work->arg->itemId);
            PLIST_MENU_ApplyGenesectDriveForm(work,(void *)work->selectedMon,work->arg->itemId);
            if (PLIST_DEMO_CheckGiratinaToOrigin(work,(void *)work->selectedMon) == 1) {
                PLIST_DEMO_ApplyGiratinaOriginForm(work,(void *)work->selectedMon);
                POKELIST_ShowMessage(work,0x56,1,POKELIST_EndMessageToEvolve); work->evolveCheckKind=1;
            } else POKELIST_ShowMessage(work,0x56,1,POKELIST_EndMessageToExit);
            PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); return;
        }
        if (FILE_UTIL_Check136C(old)==1) {
            work->arg->exitCode=10; POKELIST_ShowMessage(work,0x39,1,POKELIST_EndMessageToExit); return;
        }
        PLIST_MESSAGE_CreateWordSet(work,work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
        PLIST_MESSAGE_SetWordSetItemAlt(work,work->messageWindow,1,(u16)old);
        POKELIST_ShowMessage(work,0x3a,0,POKELIST_OpenTakeItemMenu);
        PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); return;
    case 14:
        if (func_02017E1C((void *)work->selectedMon,6,0) == 0) {
            buf=(u32)func_02009050(work->arg->mailBox,0,work->arg->mailSlot,work->heapId);
            POKE_TOOL_SetPartyValue((void *)work->selectedMon,0xa7,buf); func_020307B0((void *)buf);
            POKE_TOOL_SetPartyValue((void *)work->selectedMon,6,work->arg->itemId);
            func_0200902C(work->arg->mailBox,0,work->arg->mailSlot);
            POKELIST_ShowMessage(work,0x62,1,POKELIST_EndMessageToExit);
        } else POKELIST_ShowMessage(work,0x63,1,POKELIST_EndMessageToExit);
        return;
    case 6:
        switch ((u32)POKELIST_GetMoveLearnStatus(work,(void *)work->selectedMon,work->arg->selectedIndex)) {
        case 0:
            work->arg->exitCode=10;
            PLIST_MESSAGE_CreateWordSet(work,work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work,work->messageWindow,1,work->arg->moveId);
            POKELIST_ShowMessage(work,0x29,1,POKELIST_EndMessageToExit); PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow);
            POKELIST_FindMoveSlot(work,(void *)work->selectedMon); POKELIST_ApplyItemEffect(work,(void *)work->selectedMon); return;
        case 1:
            PLIST_MESSAGE_CreateWordSet(work,work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work,work->messageWindow,1,work->arg->moveId);
            POKELIST_ShowMessage(work,0x20,0,POKELIST_OpenGiveUpMoveMenu); PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); return;
        case 2:
            work->arg->exitCode=10;
            PLIST_MESSAGE_CreateWordSet(work,work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work,work->messageWindow,1,work->arg->moveId);
            POKELIST_ShowMessage(work,0x2a,1,POKELIST_EndMessageToExit); PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); return;
        case 3:
            work->arg->exitCode=10;
            PLIST_MESSAGE_CreateWordSet(work,work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work,work->messageWindow,0,work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work,work->messageWindow,1,work->arg->moveId);
            POKELIST_ShowMessage(work,0x2b,1,POKELIST_EndMessageToExit); PLIST_MESSAGE_DestroyWordSet(work,work->messageWindow); return;
        }
        return;
    case 3:
        work->phase=19; work->arg->selectedIndex=work->selectedSlot; work->arg->exitCode=0; return;
    default:
        POKELIST_EnterMenuPhase(work); POKELIST_OpenContextMenu(work); return;
    }
}


#undef W

#undef W




/*
 * EXACT*: the extent's last two bytes (0x021B83D6) are alignment padding.
 * PLIST_MENU_Open is declared with a third argument: this caller loads
 * `add r2, sp, #0` (the 32-byte buf) before the bl.  The switch value is
 * signed (bgt/blt compare tree).
 */
void POKELIST_OpenContextMenu(PokelistWork *work)
{
    int buf[8];

    BG_SYS_PushTile(0);
    switch (work->arg->mode) {
    case 0:
        if (PLIST_PLATE_IsEgg(work, work->plates[work->selectedSlot]) == 1) {
            buf[1] = 3;
            buf[2] = 6;
            buf[0] = 0;
            buf[3] = 0x10;
        } else {
            buf[1] = 1;
            buf[2] = 3;
            buf[3] = 4;
            buf[0] = 0;
            buf[4] = 6;
            buf[5] = 0x10;
            if (FILE_UTIL_Check136C(func_02017E1C((void *)work->selectedMon, 6, 0)) == 1) {
                buf[3] = 5;
            }
        }
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0x12);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        break;
    case 1:
    case 22:
    case 23:
        if (PLIST_PLATE_IsEgg(work, work->plates[work->selectedSlot]) == 1) {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        } else {
            buf[0] = 8;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        }
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0x12);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        break;
    case 5:
        buf[0] = 2;
        buf[1] = 6;
        buf[2] = 0x10;
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, PLIST_MENU_GetItemUseMessage(work, work->arg->itemId));
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        break;
    case 18:
        if (PLIST_PLATE_IsEgg(work, work->plates[work->selectedSlot]) == 1) {
            buf[1] = 6;
            buf[0] = 0;
            buf[2] = 0x10;
        } else {
            buf[0] = 7;
            buf[2] = 6;
            buf[1] = 0;
            buf[3] = 0x10;
        }
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0x12);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        break;
    case 21:
        if (PLIST_PLATE_IsEgg(work, work->plates[work->selectedSlot]) == 1) {
            buf[0] = 0xb;
            buf[2] = 6;
            buf[3] = 0x10;
            buf[1] = 0;
            PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
            PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0xa2);
        } else {
            buf[1] = 6;
            buf[2] = 0x10;
            buf[0] = 0;
            PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
            PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
            PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
            PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0x12);
            PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        }
        break;
    case 25:
        if (MUSICAL_MCSS_GetMonValue((void *)work->selectedMon) == 1) {
            buf[0] = 0xb;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        } else {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        }
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 0x12);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        break;
    default:
        buf[0] = 0;
        buf[1] = 6;
        buf[2] = 0x10;
        break;
    }
    PLIST_MENU_Open(work, work->contextMenu, buf);
}



void POKELIST_UpdateInputStage(PokelistWork *work)
{
    switch (work->inputStage) {
    case 0:
        work->inputStage = 1;
        work->command = 4;
        break;
    case 1:
        POKELIST_UpdateCursorInput(work);
        break;
    case 2:
        if (work->phase == 3) {
            POKELIST_UpdateSwapCommand(work);
        } else if (work->phase == 4) {
            POKELIST_UpdateHealShareCommand(work);
        } else {
            POKELIST_HandleCommand(work);
        }
        break;
    }
}


#undef W

#undef W




/*
 * The extent's last two bytes are alignment padding (00 00), not a follower.
 */
void POKELIST_RefreshCursor(PokelistWork *work)
{
    work->selectedSlot = work->arg->selectedIndex;
    work->inputStage = 0;
    work->menuChoice = 0x17;
    if (POKELIST_IsItemMode(work) == 1) {
        PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[0], 0);
        PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[1], 0);
    }
    if (work->touchMode == 0) {
        if (work->selectedSlot <= 5) {
            POKELIST_MoveCursorToPlate(work, work->selectedSlot);
            PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 1);
        } else {
            PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
        }
    } else {
        CLACT_SetActorDrawEnable(work->cursorActor, 0);
        if (work->selectedSlot <= 5) {
            if (work->phase == 3) {
                PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 1);
            } else {
                PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 0);
            }
        } else {
            PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(work->selectedSlot - 6)], 0);
        }
    }
    CLACT_SetActorDrawEnable(work->switchButtonActor, work->switchButtonEnabled);
    if (POKELIST_IsItemMode(work) == 1 || POKELIST_HasBackButton(work) == 0) {
        CLACT_SetActorDrawEnable(work->backButtonActor, 0);
    } else {
        CLACT_SetActorDrawEnable(work->backButtonActor, 1);
    }
}


#undef W

#undef W




/*
 * Case bodies are laid out 3, 0, 1, 2: case 3 is written first.
 */
void POKELIST_HandleCommand(PokelistWork *work)
{
    u8 i;
    u8 k;
    int n;

    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (POKELIST_IsItemMode(work) == 1) {
        BG_SYS_SetTileEntry(0, 0, 0, 0x15, 0x20, 3, 0x10);
        for (i = 0; i < 6; i++) {
            work->arg->slotOrder[i] = 0;
        }
        for (k = 0; k < 6; k++) {
            n = PLIST_PLATE_GetLabelState(work->plates[k]);
            if (n <= 5) {
                work->arg->slotOrder[n] = k + 1;
            }
        }
    }
    switch (work->command) {
    case 3:
        CLACT_SetActorDrawEnable(work->cursorActor, 0);
        work->selectedMon = (int)POKEPARTY_GetMember(work->arg->party, work->selectedSlot);
        work->arg->selectedIndex = work->selectedSlot;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        POKELIST_ApplySelection(work);
        return;
    case 0:
        if (POKELIST_IsItemMode(work) == 1) {
            POKELIST_ConfirmBattleParty(work);
            return;
        }
        work->phase = 0x13;
        work->arg->selectedIndex = 6;
        work->arg->exitCode = 0;
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return;
    case 1:
        if (work->selectedSlot <= 5) {
            PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 0);
            CLACT_SetActorDrawEnable(work->cursorActor, 0);
        }
        if (POKELIST_IsItemMode(work) == 1) {
            PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[0], 0);
            PLIST_MENU_ButtonWinSetDecide(work->commandButtons[1], 1);
            work->phase = 0xc;
            work->selectedSlot = 7;
        } else {
            work->phase = 0x13;
            work->pressedButtonActor = work->backButtonActor;
            CLACT_SetActorAnimSeq(work->pressedButtonActor, 9);
        }
        work->arg->selectedIndex = 7;
        work->arg->exitCode = 0;
        GFL_USE_PlaySeDefaultVolume(0x551);
        return;
    case 2:
        if (work->selectedSlot <= 5) {
            PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 0);
            CLACT_SetActorDrawEnable(work->cursorActor, 0);
        }
        work->phase = 0x13;
        work->arg->selectedIndex = 8;
        work->arg->exitCode = 0;
        GFL_USE_PlaySeDefaultVolume(0x556);
        work->pressedButtonActor = work->switchButtonActor;
        CLACT_SetActorAnimSeq(work->pressedButtonActor, 8);
        return;
    }
}


#undef W

#undef W




void POKELIST_UpdateSwapCommand(PokelistWork *work)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (work->command == 3 && work->selectedSlot == work->swapSourceSlot) {
        work->command = 1;
    }
    if (work->command != 1) {
        if (work->command == 3) {
            POKELIST_StartSwapAnimation(work);
        }
    } else {
        work->selectedMon = 0;
        work->phase = 2;
        POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        PLIST_PLATE_SetSelected(work, work->plates[work->swapSourceSlot], 0);
        CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
        work->swapSourceSlot = 9;
        work->arg->selectedIndex = work->selectedSlot;
        POKELIST_SetupModeScreen(work);
        GFL_USE_PlaySeDefaultVolume(0x551);
    }
}


#undef W

#undef W




void POKELIST_UpdateHealShareCommand(PokelistWork *work)
{
    u32 a, b;
    void *o;
    u32 c, d, e;

    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (work->command == 3) {
        work->selectedMon = (u32)POKEPARTY_GetMember(work->arg->party, work->selectedSlot);
        a = func_02017E1C((void *)work->selectedMon, 0xa0, 0);
        b = func_02017E1C((void *)work->selectedMon, 0xa1, 0);
        if (work->selectedSlot == work->healSourceSlot || a == 0 || b == a) {
            POKELIST_ShowMessage(work, 0x64, 1, POKELIST_CloseMessageToList);
            POKELIST_MoveCursorToPlate(work, work->selectedSlot);
            PLIST_PLATE_SetSelected(work, work->plates[work->healSourceSlot], 0);
            PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 0);
            CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
            work->arg->selectedIndex = work->selectedSlot;
            return;
        }
        PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
        work->selectedMon = (u32)POKEPARTY_GetMember(work->arg->party, work->selectedSlot);
        work->phase = 10;
        work->displayHp = PLIST_PLATE_GetHp(work, work->plates[work->selectedSlot]);
        work->phaseCallback = (PokelistFn)POKELIST_StartHpTransfer;
        POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        PLIST_PLATE_SetSelected(work, work->plates[work->healSourceSlot], 0);
        CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
        o = POKEPARTY_GetMember(work->arg->party, work->healSourceSlot);
        c = func_02017E1C(o, 0xa1, 0);
        d = func_02017E1C(o, 0xa0, 0);
        e = c / 5;
        if (a + e > b) {
            POKE_TOOL_SetPartyValue(o, 0xa0, d - (b - a));
        } else {
            POKE_TOOL_SetPartyValue(o, 0xa0, d - e);
        }
        work->arg->selectedIndex = work->selectedSlot;
        work->selectedSlot = work->healSourceSlot;
        PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
        GFL_USE_PlaySeDefaultVolume(0x56f);
        return;
    }
    work->selectedMon = 0;
    work->phase = 2;
    POKELIST_MoveCursorToPlate(work, work->selectedSlot);
    PLIST_PLATE_SetSelected(work, work->plates[work->healSourceSlot], 0);
    CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
    work->healSourceSlot = 9;
    work->arg->selectedIndex = work->selectedSlot;
    POKELIST_SetupModeScreen(work);
    GFL_USE_PlaySeDefaultVolume(0x551);
}


#undef W

#undef W




/*
 * The six-byte buffer is a block-scope initialised array
 * (an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six assignments sink `add r7, sp, #4` below the stores.
 */
void POKELIST_ConfirmBattleParty(PokelistWork *work)
{
    PokelistRegulation *rule;
    u8 i;
    int n;
    int r;

    rule = work->arg->regulation;
    if (work->selectedSlot != 6) {
        if (work->selectedSlot <= 5) {
            PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 0);
            CLACT_SetActorDrawEnable(work->cursorActor, 0);
        }
        work->selectedSlot = 6;
    }
    work->arg->selectedIndex = 6;
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 6; i++) {
            n = PLIST_PLATE_GetLabelState(work->plates[i]);
            if (n <= 5) {
                buf[n] = i + 1;
            }
        }
        r = POKE_REGULATION_CheckSelection((u32)rule, (u32)work->arg->party, (u32)buf);
    }
    if (rule->minPartySize > work->selectedCount) {
        POKELIST_ShowMessage(work, rule->minPartySize + 0x56, 1, POKELIST_CloseMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        return;
    }
    if (rule->maxPartySize < work->selectedCount) {
        POKELIST_ShowMessage(work, rule->maxPartySize + 0x5c, 1, POKELIST_CloseMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        return;
    }
    if (r == 1) {
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetNumber(work, work->messageWindow, 0, rule->levelTotal, 3);
        POKELIST_ShowMessage(work, 0x92, 1, POKELIST_CloseMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        return;
    }
    if (r == 7) {
        POKELIST_ShowMessage(work, 0x94, 1, POKELIST_CloseMessageToList);
        GFL_USE_PlaySeDefaultVolume(0x557);
        return;
    }
    PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[1], 0);
    PLIST_MENU_ButtonWinSetDecide(work->commandButtons[0], 1);
    work->phase = 0xc;
    work->arg->selectedIndex = 6;
    work->arg->exitCode = 0;
    work->selectionConfirmed = 1;
    GFL_USE_PlaySeDefaultVolume(0x54c);
}


void POKELIST_UpdateCursorInput(PokelistWork *work) { POKELIST_ReadCursorKeys(work); if(work->command==4) POKELIST_HandleTouch(work); if(work->command!=4) work->inputStage=2; if(work->arg->closeRequested==1) { work->inputStage=2; work->command=1; } }


#undef W

#undef W




/*
 * The two byte tables resolve as sole-ref only without an overlay token
 * (with `ov091` the hint is reported contested).  The spilled locals sit
 * up @0, done @4, old @8, trg @0xc: declared trg, old, done, up.
 */
void POKELIST_ReadCursorKeys(PokelistWork *work)
{
    u32 trg;
    int old;
    int done;
    u32 up;
    u32 rep;
    int dir;
    int max;
    u8 cnt;
    int n;

    trg = KEY_GetTrg();
    rep = KEY_GetRepeat();
    if (work->touchMode == 1 && CLACT_GetActorDrawEnable(work->cursorActor) == 0) {
        if (trg != 0 && (trg & 0x402) == 0) {
            if (work->selectedSlot <= 5) {
                POKELIST_MoveCursorToPlate(work, work->selectedSlot);
                PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 1);
            } else {
                PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                CLACT_SetActorDrawEnable(work->cursorActor, 0);
            }
            GFL_USE_PlaySeDefaultVolume(0x548);
            work->touchMode = 0;
        }
    } else {
        dir = 0;
        if (trg != 0) {
            work->touchMode = 0;
        }
        up = rep & 0x40;
        if (up) {
            dir = -2;
        } else if (rep & 0x80) {
            dir = 2;
        } else if (rep & 0x20) {
            dir = -1;
        } else if (rep & 0x10) {
            dir = 1;
        } else if (trg & 1) {
            if (work->selectedSlot == 6) {
                work->command = 0;
            } else if (work->selectedSlot == 7) {
                work->command = 1;
            } else if (work->allowDisabledSelect == 0 && PLIST_PLATE_IsEgg(work, work->plates[work->selectedSlot]) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
            } else {
                work->command = 3;
            }
        }
        if (dir != 0) {
            old = work->selectedSlot;
            done = 0;
            if (POKELIST_IsItemMode(work) == 1) {
                if (POKELIST_IsNotItemUseMode(work) == 1) {
                    max = 7;
                } else {
                    max = 6;
                }
            } else {
                max = 5;
            }
            if ((u32)(work->selectedSlot - 6) <= 1 && (rep & 0xc0)) {
                cnt = POKEPARTY_GetCount(work->arg->party);
                if (up) {
                    if (work->selectedSlot == 7 || POKELIST_IsNotItemUseMode(work) == 0) {
                        work->selectedSlot = d_021BEAB0[cnt - 1];
                    } else {
                        work->selectedSlot = d_021BEAAA[cnt - 1];
                    }
                } else {
                    if (work->selectedSlot == 7 || POKELIST_IsNotItemUseMode(work) == 0) {
                        if (cnt > 1) {
                            work->selectedSlot = 1;
                        } else {
                            work->selectedSlot = 0;
                        }
                    } else {
                        work->selectedSlot = 0;
                    }
                }
            } else {
                do {
                    n = work->selectedSlot + dir;
                    if (n > max) {
                        if (max == 6 && dir > 1 && old != 6) {
                            work->selectedSlot = max;
                        } else {
                            work->selectedSlot = n - (max + 1);
                        }
                    } else if (n < 0) {
                        if (max == 6 && dir < 1) {
                            work->selectedSlot = max;
                        } else {
                            work->selectedSlot = dir + (work->selectedSlot + (max + 1));
                        }
                    } else {
                        work->selectedSlot += dir;
                    }
                    if (work->selectedSlot > 5 || PLIST_PLATE_IsOccupied(work, work->plates[work->selectedSlot]) == 1) {
                        done = 1;
                    }
                } while (done == 0);
            }
            if (old != work->selectedSlot) {
                if (work->selectedSlot <= 5) {
                    POKELIST_MoveCursorToPlate(work, work->selectedSlot);
                    PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 1);
                } else {
                    PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                    CLACT_SetActorDrawEnable(work->cursorActor, 0);
                }
                if (old <= 5) {
                    PLIST_PLATE_SetSelected(work, work->plates[old], 0);
                } else {
                    PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(old - 6)], 0);
                }
                work->fadeStep = 0xc;
            }
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
    }
    if (trg & 2) {
        if (POKELIST_IsItemMode(work) == 0 || POKELIST_IsNotItemUseMode(work) == 1) {
            if (POKELIST_HasBackButton(work) == 1) {
                work->command = 1;
                work->pressedButtonActor = work->backButtonActor;
                CLACT_SetActorAnimSeq(work->pressedButtonActor, 9);
                work->touchMode = 0;
            }
        }
    } else if ((trg & 0x400) && work->switchButtonEnabled == 1) {
        work->command = 2;
        work->pressedButtonActor = work->switchButtonActor;
        CLACT_SetActorAnimSeq(work->pressedButtonActor, 8);
        work->touchMode = 0;
    }
}

void POKELIST_HandleTouch(PokelistWork *work)
{
    PokelistRect rects[7];
    PokelistButtonRects buttonRects;
    u8 plateOfRect[6];
    u8 i;
    u8 count;
    int hit;
    int oldSlot;
    int buttonHit;

    count = 0;
    for (i = 0; i < 6; i++) {
        if (PLIST_PLATE_IsOccupied(work, work->plates[i]) == 1) {
            plateOfRect[count] = i;
            PLIST_PLATE_GetTouchRect(work, work->plates[i], &rects[count]);
            count++;
        }
    }
    rects[count].top = 0xff;
    hit = TOUCHPANEL_HitTrg(rects);
    if (hit != -1) {
        if (work->allowDisabledSelect == 0 && hit <= 5 && PLIST_PLATE_IsEgg(work, work->plates[hit]) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x557);
        } else {
            work->command = 3;
            oldSlot = work->selectedSlot;
            work->selectedSlot = plateOfRect[hit];
            if (oldSlot <= 5) {
                PLIST_PLATE_SetSelected(work, work->plates[oldSlot], 0);
            } else {
                PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(oldSlot - 6)], 0);
            }
            if (work->selectedSlot <= 5) {
                PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 1);
            } else {
                PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                CLACT_SetActorDrawEnable(work->cursorActor, 0);
            }
            work->fadeStep = 0xc;
        }
        work->touchMode = 1;
    }
    if (hit == -1) {
        buttonRects = d_021BEC2C;
        if (POKELIST_IsItemMode(work) == 1) {
            if (POKELIST_IsNotItemUseMode(work) == 1) {
                buttonRects.r[1].top = 0xa8;
                buttonRects.r[1].bottom = 0xc0;
                buttonRects.r[1].left = 0xb0;
                buttonRects.r[1].right = 0xff;
                buttonRects.r[0].top = 0xa8;
                buttonRects.r[0].bottom = 0xc0;
                buttonRects.r[0].left = 0x60;
                buttonRects.r[0].right = 0xb0;
            } else {
                buttonRects.r[0].top = 0xa8;
                buttonRects.r[0].bottom = 0xc0;
                buttonRects.r[0].left = 0xb0;
                buttonRects.r[0].right = 0xff;
            }
        } else {
            if (POKELIST_HasBackButton(work) == 1) {
                buttonRects.r[1].top = 0xa8;
                buttonRects.r[1].bottom = 0xc0;
                buttonRects.r[1].left = 0xe0;
                buttonRects.r[1].right = 0xf8;
            }
            if (work->switchButtonEnabled == 1) {
                buttonRects.r[2].top = 0xa8;
                buttonRects.r[2].bottom = 0xc0;
                buttonRects.r[2].left = 0xc8;
                buttonRects.r[2].right = 0xe0;
            }
        }
        buttonHit = TOUCHPANEL_HitTrg(&buttonRects);
        if (buttonHit != -1) {
            work->command = buttonHit;
            work->touchMode = 1;
        }
    }
}

void POKELIST_MoveCursorToPlate(PokelistWork *work, int plateIndex)
{
    PokelistPos pos;

    PLIST_PLATE_GetCenterPos(work, work->plates[plateIndex], &pos);
    CLACT_AddActorSurfacePos(work->cursorActor, &pos, 0);
    CLACT_SetActorDrawEnable(work->cursorActor, 1);
    CLACT_SetActorBgPriority(work->cursorActor, 3);
    if (plateIndex == 0) {
        CLACT_SetActorAnimSeq(work->cursorActor, 0);
    } else {
        CLACT_SetActorAnimSeq(work->cursorActor, 1);
    }
}

void POKELIST_MoveSwapMarkerToPlate(PokelistWork *work, int plateIndex)
{
    PokelistPos pos;

    PLIST_PLATE_GetCenterPos(work, work->plates[plateIndex], &pos);
    CLACT_AddActorSurfacePos(work->swapMarkerActor, &pos, 0);
    CLACT_SetActorDrawEnable(work->swapMarkerActor, 1);
    CLACT_SetActorBgPriority(work->swapMarkerActor, 2);
    if (plateIndex == 0) {
        CLACT_SetActorAnimSeq(work->swapMarkerActor, 2);
    } else {
        CLACT_SetActorAnimSeq(work->swapMarkerActor, 3);
    }
}

void POKELIST_RunContextMenu(PokelistWork *work)
{
    int choice;

    switch (work->inputStage) {
    case 0:
        POKELIST_EnterMenuPhase(work);
        work->inputStage = 1;
        break;
    case 1:
        PLIST_MENU_Update(work, work->contextMenu);
        choice = PLIST_MENU_GetSelectedCommand(work, work->contextMenu);
        if (choice != 0x17) {
            work->menuChoice = choice;
            work->inputStage = 2;
        }
        if (work->arg->closeRequested == 1) {
            work->inputStage = 2;
        }
        break;
    case 2:
        POKELIST_CloseContextMenu(work);
        POKELIST_DispatchMenuChoice(work);
        break;
    }
}

static inline void G2_SetBlendBrightness(int plane, int brightness)
{
    func_0207D658((u32)&reg_G2_BLDCNT, plane, brightness);
}

static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    reg_G2_WIN0H = (u16)(((x1 << 8) & 0xff00) | ((x2 << 0) & 0x00ff));
    reg_G2_WIN0V = (u16)(((y1 << 8) & 0xff00) | ((y2 << 0) & 0x00ff));
}

static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WININ & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WININ = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp;
    tmp = ((reg_G2_WINOUT & ~0x3f) | ((u32)wnd << 0));
    if (effect) {
        tmp |= (0x20 << 0);
    }
    reg_G2_WINOUT = (u16)tmp;
}

/*
 * volatile: WININ 0x04000048 and WINOUT 0x0400004A read-modify-written by the SDK inlines G2_SetWnd0InsidePlane/G2_SetWndOutsidePlane; WIN0H/WIN0V/BLDCNT hardware registers
 */
void POKELIST_EnterMenuPhase(PokelistWork *work)
{
    work->phase = 6;
    work->inputStage = 0;
    G2_SetBlendBrightness(0x1e, 8);
    G2_SetWnd0Position(0xe0, 0xa8, 0xf8, 0xc0);
    G2_SetWnd0InsidePlane(0x1f, 0);
    G2_SetWndOutsidePlane(0x1f, 1);
    work->fadeMode = 1;
    CLACT_SetActorDrawEnable(work->switchButtonActor, 0);
    CLACT_SetActorDrawEnable(work->backButtonActor, 0);
    func_02041B6C(0);
    func_020355D8(work->touchMode);
}

void POKELIST_CloseContextMenu(PokelistWork *work)
{
    PLIST_MENU_Close(work, work->contextMenu);
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (POKELIST_IsItemMode(work) == 1 || POKELIST_HasBackButton(work) == 0) {
        CLACT_SetActorDrawEnable(work->backButtonActor, 0);
    } else {
        CLACT_SetActorDrawEnable(work->backButtonActor, 1);
    }
    if (work->menuChoice != 4 && work->menuChoice != 5) {
        func_0207D63C(0x04000050, 0x14, 8, 0x10, 0xa);
        work->fadeMode = 0;
    }
    BG_SYS_ClearLayerEx(0, 0);
    work->touchMode = func_020355C4();
}

void POKELIST_DispatchMenuChoice(PokelistWork *work)
{
    struct {
        u32 maxHp;
        PokelistMenuItems itemsForChoice5;
        PokelistMenuItems itemsForChoice4;
    } local;
    u32 monValue;
    int result, level;
    u32 lastSelected;
    u8 i;
    PokelistRegulation *rule;

    if (work->arg->closeRequested == 1) {
        work->phase = 19;
        return;
    }
    switch (work->menuChoice) {
    case 6:
        POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        work->selectedMon = 0;
        work->phase = 2;
        POKELIST_SetupModeScreen(work);
        return;
    case 3:
        POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        POKELIST_MoveSwapMarkerToPlate(work, work->selectedSlot);
        work->swapSourceSlot = work->selectedSlot;
        work->phase = 3;
        work->selectedMon = 0;
        work->switchButtonEnabled = 0;
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 11);
        POKELIST_RefreshCursor(work);
        return;
    case 4:
        local.itemsForChoice4 = d_021BEC0C;
        POKELIST_EnterMenuPhase(work);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 19);
        PLIST_MENU_Open(work, work->contextMenu, local.itemsForChoice4.v);
        BG_SYS_PushTile(0);
        return;
    case 5:
        local.itemsForChoice5 = d_021BEC1C;
        POKELIST_EnterMenuPhase(work);
        PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 2);
        PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 19);
        PLIST_MENU_Open(work, work->contextMenu, local.itemsForChoice5.v);
        BG_SYS_PushTile(0);
        return;
    case 0:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 1;
        return;
    case 20:
        rule = work->arg->regulation;
        lastSelected = 0;
        result = PLIST_PLATE_CheckSelection(work, work->plates[work->selectedSlot]);
        if (result == 0) {
            PLIST_PLATE_SetLabelState(work, work->plates[work->selectedSlot], work->selectedCount);
            work->selectedCount = work->selectedCount + 1;
            POKELIST_SetupModeScreen(work);
            if (work->selectedCount == rule->maxPartySize) {
                lastSelected = 1;
            }
            work->phase = 2;
        } else if (result == 2) {
            POKELIST_ShowMessage(work, 0x90, 1, POKELIST_CloseMessageToList);
            GFL_USE_PlaySeDefaultVolume(0x557);
        } else if (result == 3) {
            POKELIST_ShowMessage(work, 0x91, 1, POKELIST_CloseMessageToList);
            GFL_USE_PlaySeDefaultVolume(0x557);
        } else if (result == 4) {
            POKELIST_ShowMessage(work, rule->maxPartySize + 0x5c, 1, POKELIST_CloseMessageToList);
            GFL_USE_PlaySeDefaultVolume(0x557);
        }
        work->selectedMon = 0;
        if (lastSelected == 1) {
            PLIST_PLATE_SetSelected(work, work->plates[work->selectedSlot], 0);
            work->selectedSlot = 6;
            if (work->touchMode == 0) {
                PLIST_MENU_SetTaskMenuWinActive(work->commandButtons[(u8)(work->selectedSlot - 6)], 1);
                CLACT_SetActorDrawEnable(work->cursorActor, 0);
                return;
            }
        } else if (work->touchMode == 0) {
            POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        }
        return;
    case 21:
        level = PLIST_PLATE_GetLabelState(work->plates[work->selectedSlot]);
        for (i = 0; i < 6; i++) {
            result = PLIST_PLATE_GetLabelState(work->plates[i]);
            if (result <= 5 && result > level) {
                PLIST_PLATE_SetLabelState(work, work->plates[i], result - 1);
            }
        }
        PLIST_PLATE_SetLabelState(work, work->plates[work->selectedSlot], 6);
        work->selectedCount = work->selectedCount - 1;
        if (work->touchMode == 0) {
            POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        }
        work->selectedMon = 0;
        work->phase = 2;
        POKELIST_SetupModeScreen(work);
        return;
    case 10:
        monValue = func_02017E1C((void *)work->selectedMon, 6, 0);
        PLIST_MENU_ApplyArceusPlateForm(work, (void *)work->selectedMon, 0);
        PLIST_MENU_ApplyGenesectDriveForm(work, (void *)work->selectedMon, 0);
        if (monValue == 0) {
            PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
            PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
            POKELIST_ShowMessage(work, 0x3d, 1, POKELIST_CloseMessageToList);
            PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
            return;
        }
        if (POKELIST_CheckBagItem(work, monValue) == 999) {
            POKELIST_ShowMessage(work, 0x3f, 1, POKELIST_CloseMessageToList);
            return;
        }
        POKELIST_SetHeldItem(work, (void *)work->selectedMon, 0);
        PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_SetWordSetItem(work, work->messageWindow, 1, (u16)monValue);
        if (PLIST_DEMO_CheckGiratinaToAltered(work, (void *)work->selectedMon) == 1) {
            PLIST_DEMO_ApplyGiratinaAlteredForm(work, (void *)work->selectedMon);
            POKELIST_ShowMessage(work, 0x3e, 1, POKELIST_EndMessageToEvolve);
            work->evolveCheckKind = 2;
        } else {
            POKELIST_ShowMessage(work, 0x3e, 1, POKELIST_CloseMessageToList);
        }
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        return;
    case 11:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 0;
        return;
    case 9:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 3;
        return;
    case 12:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 7;
        return;
    case 13:
        POKELIST_ShowMessage(work, 0x17, 0, POKELIST_OpenTakeMailMenu);
        return;
    case 7:
        work->phase = 19;
        work->arg->selectedIndex = work->selectedSlot;
        work->arg->exitCode = 0;
        return;
    case 16:
    case 17:
    case 18:
    case 19:
        if (work->arg->mode == 5) {
            if (PLIST_DEMO_CheckItemUsable((void *)work->selectedMon, work->arg->itemId, (u16)(work->menuChoice - 16), work->heapId) == 1) {
                monValue = func_02017E1C((void *)work->selectedMon, work->menuChoice + 0x26, 0);
                BG_SYS_PushTile(0);
                PLIST_MENU_StartItemUse(work, monValue);
                PLIST_DEMO_UseItemOnMon((void *)work->selectedMon, work->arg->itemId, (u16)(work->menuChoice - 16), work->arg->itemUseParam, work->heapId);
                PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
                POKELIST_RemoveBagItem(work, work->arg->itemId);
                GFL_USE_PlaySeDefaultVolume(0x56f);
            } else {
                PLIST_MENU_ShowItemUsedThenContinue(work);
            }
            return;
        }
        result = POKELIST_GetFieldMoveMenuIndex((void *)work->selectedMon, (u8)(work->menuChoice - 16));
        if ((u32)(result - 22) <= 1) {
            if (ZONEDATA_IsNormalFieldZone(work->arg->itemUseParam) == 0) {
                POKELIST_ShowMessage(work, 0x50, 1, POKELIST_CloseMessageToList);
                return;
            }
            local.maxHp = func_02017E1C((void *)work->selectedMon, 0xa1, 0);
            monValue = func_02017E1C((void *)work->selectedMon, 0xa0, 0);
            if (monValue > local.maxHp / 5) {
                POKELIST_MoveCursorToPlate(work, work->selectedSlot);
                POKELIST_MoveSwapMarkerToPlate(work, work->selectedSlot);
                work->healSourceSlot = work->selectedSlot;
                work->phase = 4;
                work->selectedMon = 0;
                work->switchButtonEnabled = 0;
                PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 0);
                PLIST_MESSAGE_PrintText(work, (u32 *)work->messageWindow, 17);
                POKELIST_RefreshCursor(work);
            } else {
                POKELIST_ShowMessage(work, 0x6b, 1, POKELIST_CloseMessageToList);
            }
            return;
        }
        switch (MOVE_POKEMON_IsSkillBlocked(result - 11, work->arg->fieldMoveParam)) {
        case 0:
            work->phase = 19;
            work->arg->selectedIndex = work->selectedSlot;
            work->arg->exitCode = result;
            return;
        case 1:
            POKELIST_ShowMessage(work, 0x50, 1, POKELIST_CloseMessageToList);
            return;
        case 2:
            POKELIST_ShowMessage(work, 0x38, 1, POKELIST_CloseMessageToList);
            return;
        case 3:
            POKELIST_ShowMessage(work, 0x9f, 1, POKELIST_CloseMessageToList);
            return;
        case 4:
            POKELIST_ShowMessage(work, 0x4f, 1, POKELIST_CloseMessageToList);
            return;
        }
        return;
    default:
        POKELIST_MoveCursorToPlate(work, work->selectedSlot);
        work->selectedMon = 0;
        work->phase = 2;
        POKELIST_SetupModeScreen(work);
        return;
    }
}

void POKELIST_UpdateMessagePhase(PokelistWork *work)
{
    if (PLIST_MESSAGE_IsIdle(work, work->messageWindow) == 1) {
        if (KEY_GetTrg() & 1) {
            work->touchMode = 0;
        }
        if (TOUCHPANEL_GetTrg() == 1) {
            work->touchMode = 1;
        }
        work->messageDoneCallback(work);
    }
}

void POKELIST_ShowMessage(PokelistWork *work, int messageId, int waitForKey, PokelistFn onDone)
{
    work->phase = 7;
    work->messageWaitKey = waitForKey;
    work->messageDoneCallback = onDone;
    PLIST_MESSAGE_OpenWindow(work, (u32 *)work->messageWindow, 3);
    PLIST_MESSAGE_StartStream(work, (u32 *)work->messageWindow, messageId, waitForKey);
    CLACT_SetActorDrawEnable(work->backButtonActor, 0);
    CLACT_SetActorDrawEnable(work->switchButtonActor, 0);
}

void POKELIST_PollContextMenuChoice(PokelistWork *work)
{
    int choice;

    PLIST_MENU_Update(work, work->contextMenu);
    choice = PLIST_MENU_GetSelectedCommand(work, work->contextMenu);
    if (choice != 0x17) {
        work->menuChoiceCallback(work, choice);
        PLIST_MENU_Close(work, work->contextMenu);
    }
}

/*
 * POKELIST_OpenMenuWithCallback is an unlabelled tail-call stub inside the extent.
 */
void POKELIST_OpenMenuWithCallback(PokelistWork *work, PokelistMenuFn onChoice)
{
    work->phase = 9;
    work->menuChoiceCallback = onChoice;
    PLIST_MENU_OpenFixed(work, work->contextMenu);
}

void POKELIST_UpdateSwapAnimation(PokelistWork *work)
{
    switch (work->inputStage) {
    case 3:
        PLIST_PLATE_ClearSlideTrail(work, work->plates[work->selectedSlot], work->swapAnimStep);
        PLIST_PLATE_ClearSlideTrail(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        work->swapAnimStep++;
        PLIST_PLATE_SetSlideOffset(work, work->plates[work->selectedSlot], work->swapAnimStep);
        PLIST_PLATE_SetSlideOffset(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        if (work->swapAnimStep >= 16) {
            POKEPARTY_SwapMembers(work->arg->party, work->selectedSlot, work->swapSourceSlot, work->heapId);
            PLIST_PLATE_SetMon(work, work->plates[work->selectedSlot], POKEPARTY_GetMember(work->arg->party, work->selectedSlot), work->swapAnimStep);
            PLIST_PLATE_SetMon(work, work->plates[work->swapSourceSlot], POKEPARTY_GetMember(work->arg->party, work->swapSourceSlot), work->swapAnimStep);
            work->inputStage = 4;
            GFL_USE_PlaySeDefaultVolume(0x642);
        }
        break;
    case 4:
        PLIST_PLATE_ClearSlideTrail(work, work->plates[work->selectedSlot], work->swapAnimStep);
        PLIST_PLATE_ClearSlideTrail(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        work->swapAnimStep--;
        PLIST_PLATE_SetSlideOffset(work, work->plates[work->selectedSlot], work->swapAnimStep);
        PLIST_PLATE_SetSlideOffset(work, work->plates[work->swapSourceSlot], work->swapAnimStep);
        if (work->swapAnimStep == 0)
            POKELIST_FinishSwap(work);
        break;
    }
}

void POKELIST_StartSwapAnimation(PokelistWork *work)
{
    work->phase = 5;
    work->inputStage = 3;
    work->swapAnimStep = 0;
    GFL_USE_PlaySeDefaultVolume(0x641);
    CLACT_SetActorDrawEnable(work->cursorActor, 0);
    CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
}

void POKELIST_FinishSwap(PokelistWork *work)
{
    work->selectedMon = 0;
    work->phase = 2;
    POKELIST_MoveCursorToPlate(work, work->selectedSlot);
    PLIST_PLATE_SetSelected(work, work->plates[work->swapSourceSlot], 0);
    CLACT_SetActorDrawEnable(work->swapMarkerActor, 0);
    work->swapSourceSlot = 9;
    work->arg->selectedIndex = work->selectedSlot;
    POKELIST_SetupModeScreen(work);
}

int POKELIST_GetFieldMoveMenuIndex(void *mon, int moveSlot)
{
    switch (func_02017E1C(mon, moveSlot + 0x36, 0)) {
    case 0xf:
        return 0xb;
    case 0x13:
        return 0xf;
    case 0x39:
        return 0xc;
    case 0x46:
        return 0xe;
    case 0x7f:
        return 0xd;
    case 0x94:
        return 0x10;
    case 0x64:
        return 0x11;
    case 0x5b:
        return 0x12;
    case 0xe6:
        return 0x13;
    case 0x1c0:
        return 0x14;
    case 0x123:
        return 0x15;
    case 0xd0:
        return 0x16;
    case 0x87:
        return 0x17;
    }
    return 0;
}

int POKELIST_IsItemMode(PokelistWork *work)
{
    u32 mode = work->arg->mode;
    if (mode == 1 || mode == 22 || mode == 23)
        return 1;
    return 0;
}

int POKELIST_IsNotItemUseMode(PokelistWork *work)
{
    if (work->arg->mode != 1)
        return 1;
    return 0;
}

int POKELIST_HasBackButton(PokelistWork *work)
{
    return work->arg->mode != 21;
}

int POKELIST_GetMoveLearnStatus(PokelistWork *work, void *mon, u8 partySlot)
{
    int hasEmptySlot = 0;
    u8 i;
    u32 moveA, moveB, moveC;
    u32 moveId;
    if (work->restoreMode18 == 1) {
        moveA = work->arg->moveId;
        if (moveA == 0xfffe) {
            moveA = 0x152;
            moveB = moveA - 0x1f;
            moveC = moveA - 0x1e;
        } else if (moveA == 0xfffd) {
            moveA = 0x280;
            moveA = moveA - 0x78;
            moveB = 0x280;
            moveB = moveB - 0x79;
            moveC = 0x280 - 0x7a;
        } else {
            moveB = moveA;
            moveC = moveA;
        }
        for (i = 0; i < 4; i++) {
            moveId = func_02017E1C(mon, i + 0x36, 0);
            if (moveId == moveA || moveId == moveB || moveId == moveC)
                return 3;
            if (moveId == 0)
                hasEmptySlot = 1;
        }
        if ((work->arg->learnableFlags & (1 << partySlot)) != 0) {
            if (hasEmptySlot == 1)
                return 0;
            return 1;
        } else
            return 2;
    } else {
        for (i = 0; i < 4; i++) {
            moveId = func_02017E1C(mon, i + 0x36, 0);
            if (moveId == work->arg->moveId)
                return 3;
            if (moveId == 0)
                hasEmptySlot = 1;
        }
        if (work->arg->itemId != 0) {
            u32 machineIndex = FILE_UTIL_GetId(work->arg->itemId);
            if (machineIndex != 0xff && POKE_TOOL_CheckTmCompat(mon, machineIndex) == 1) {
                int result = 0;
                if (hasEmptySlot != 1)
                    result = 1;
                return result;
            } else
                return 2;
        } else {
            int result = 0;
            if (hasEmptySlot != 1)
                result = 1;
            return result;
        }
    }
}

u32 POKELIST_CheckEvolution(PokelistWork *work, void *mon, u32 param)
{
    PokelistArg *arg = work->arg;
    return SHINKA_CHECK_CheckEvolution(arg->party, mon, 3, param, arg->season, 0, work->heapId);
}

void POKELIST_PrintTextMain(PokelistWork *work, struct Descriptor *window, u32 messageId, int x, s16 y, u16 color)
{
    void *text;
    text = func_02045EC0(work->msgBank, messageId);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(window), (s16)x, (s16)y, text, work->fontMain, color);
    STRBUF_Delete(text);
}

void POKELIST_PrintTextSub(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0(work->msgBank, messageId);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(window), (s16)x, (s16)y, text, work->fontSub, color);
    STRBUF_Delete(text);
}

void POKELIST_PrintTextSubDirect(PokelistWork *work, struct Descriptor *window, u32 messageId, u32 x, s16 y, u16 color)
{
    void *text = func_02045EC0(work->msgBank, messageId);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(window), x, y, text, work->fontSub, color);
    STRBUF_Delete(text);
}

void POKELIST_PrintExpandedTextMain(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color)
{
    void *expanded = STRBUF_Create(16, work->heapId);
    void *text = func_02045EC0(work->msgBank, messageId);
    WORDSET_CopyTaggedText(wordSet, expanded, text);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(window), x, y, expanded, work->fontMain, color);
    STRBUF_Delete(text);
    STRBUF_Delete(expanded);
}

void POKELIST_PrintExpandedTextSub(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color)
{
    void *expanded = STRBUF_Create(16, work->heapId);
    void *text = func_02045EC0(work->msgBank, messageId);
    WORDSET_CopyTaggedText(wordSet, expanded, text);
    PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(window), x, y, expanded, work->fontSub, color);
    STRBUF_Delete(text);
    STRBUF_Delete(expanded);
}

void POKELIST_PrintExpandedTextSubDirect(PokelistWork *work, struct Descriptor *window, void *wordSet, u32 messageId, s16 x, s16 y, u16 color)
{
    void *expanded = STRBUF_Create(16, work->heapId);
    void *text = func_02045EC0(work->msgBank, messageId);
    WORDSET_CopyTaggedText(wordSet, expanded, text);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(window), x, y, expanded, work->fontSub, color);
    STRBUF_Delete(text);
    STRBUF_Delete(expanded);
}

void POKELIST_CloseMessageToList(PokelistWork *work)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    work->phase = 2;
    POKELIST_SetupModeScreen(work);
}

void POKELIST_EndMessageToExit(PokelistWork *work)
{
    work->phase = 19;
}

void POKELIST_CloseMessageIfItemInBag(PokelistWork *work)
{
    if (POKELIST_CheckBagItem(work, work->arg->itemId)) {
        PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
        work->phase = 2;
        POKELIST_SetupModeScreen(work);
        return;
    }
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetItem(work, work->messageWindow, 0, work->arg->itemId);
    POKELIST_ShowMessage(work, 0xb3, 1, POKELIST_EndMessageToExit);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void POKELIST_OpenGiveUpMoveMenu(PokelistWork *work)
{
    POKELIST_OpenMenuWithCallback(work, POKELIST_OnGiveUpMoveChoice);
}

void POKELIST_OnGiveUpMoveChoice(PokelistWork *work, int choice)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (choice == 14) {
        PokelistArg *arg = work->arg;
        if (arg->mode == 5 || arg->mode == 8) {
            arg->exitCode = 5;
        } else {
            arg->exitCode = 4;
        }
        POKELIST_ShowMessage(work, 0x27, 1, POKELIST_EndMessageToExit);
        return;
    }
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 1, work->arg->moveId);
    POKELIST_ShowMessage(work, 0x23, 0, POKELIST_OpenForgetMoveMenu);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void POKELIST_OpenForgetMoveMenu(PokelistWork *work)
{
    POKELIST_OpenMenuWithCallback(work, POKELIST_OnForgetMoveChoice);
}

void POKELIST_OnForgetMoveChoice(PokelistWork *work, int choice)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (choice == 14) {
        work->arg->exitCode = 10;
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 1, work->arg->moveId);
        if (work->arg->mode == 5 || work->arg->mode == 8) {
            POKELIST_ShowMessage(work, 0x26, 1, PLIST_MENU_BeginExitWait);
        } else {
            POKELIST_ShowMessage(work, 0x26, 1, POKELIST_EndMessageToExit);
        }
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        return;
    }
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 1, work->arg->moveId);
    POKELIST_ShowMessage(work, 0x20, 0, POKELIST_OpenGiveUpMoveMenu);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void POKELIST_ShowMoveLearned(PokelistWork *work)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 1, work->arg->moveId);
    if (work->arg->mode == 5 || work->arg->mode == 8) {
        POKELIST_ShowMessage(work, 0x29, 1, PLIST_MENU_BeginExitWait);
    } else {
        POKELIST_ShowMessage(work, 0x29, 1, POKELIST_EndMessageToExit);
        POKELIST_ApplyItemEffect(work, (void *)work->selectedMon);
        work->arg->exitCode = 10;
    }
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
    POKELIST_ReplaceMoveSlot(work, (void *)work->selectedMon, work->arg->moveSlot);
}

void POKELIST_OpenTakeItemMenu(PokelistWork *work)
{
    POKELIST_OpenMenuWithCallback(work, POKELIST_OnTakeItemChoice);
}

void POKELIST_OnTakeItemChoice(PokelistWork *work, int choice)
{
    u32 heldItem;
    int evolveKindOne, evolveKindTwo;
    if (choice == 0xe) {
        heldItem = func_02017E1C((void *)work->selectedMon, 6, 0);
        if (POKELIST_CheckBagItem(work, heldItem) == 0x3e7) {
            if (work->arg->mode == 0xa) {
                work->arg->mode = 0;
                PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
                POKELIST_ShowMessage(work, 0x3f, 1, POKELIST_CloseMessageToList);
            } else {
                work->phase = 0x13;
                PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
                POKELIST_ShowMessage(work, 0x3f, 1, POKELIST_EndMessageToExit);
            }
        } else if (FILE_UTIL_Check136C(work->arg->itemId) == 1) {
            work->arg->selectedIndex = work->selectedSlot;
            work->phase = 0x13;
            work->arg->exitCode = 6;
        } else {
            PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
            POKELIST_SetHeldItem(work, (void *)work->selectedMon, work->arg->itemId);
            PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
            PLIST_MENU_ApplyArceusPlateForm(work, (void *)work->selectedMon, (u16)(work->arg->itemId));
            PLIST_MENU_ApplyGenesectDriveForm(work, (void *)work->selectedMon, work->arg->itemId);
            evolveKindOne = PLIST_DEMO_CheckGiratinaToOrigin(work, (void *)work->selectedMon);
            evolveKindTwo = PLIST_DEMO_CheckGiratinaToAltered(work, (void *)work->selectedMon);
            PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
            PLIST_MESSAGE_SetWordSetItem(work, work->messageWindow, 1, (u16)heldItem);
            PLIST_MESSAGE_SetWordSetItem(work, work->messageWindow, 2, (u16)(work->arg->itemId));
            if (work->arg->mode == 0xa) {
                work->arg->mode = 0;
                if (evolveKindOne == 1) {
                    PLIST_DEMO_ApplyGiratinaOriginForm(work, (void *)work->selectedMon);
                    POKELIST_ShowMessage(work, 0x40, 1, POKELIST_EndMessageToEvolve);
                    work->evolveCheckKind = 1;
                } else if (evolveKindTwo == 1) {
                    PLIST_DEMO_ApplyGiratinaAlteredForm(work, (void *)work->selectedMon);
                    POKELIST_ShowMessage(work, 0x40, 1, POKELIST_EndMessageToEvolve);
                    work->evolveCheckKind = 2;
                } else {
                    POKELIST_ShowMessage(work, 0x40, 1, POKELIST_CloseMessageToList);
                }
            } else {
                work->arg->exitCode = 0xa;
                if (evolveKindOne == 1) {
                    PLIST_DEMO_ApplyGiratinaOriginForm(work, (void *)work->selectedMon);
                    POKELIST_ShowMessage(work, 0x40, 1, POKELIST_EndMessageToEvolve);
                    work->evolveCheckKind = 1;
                } else if (evolveKindTwo == 1) {
                    PLIST_DEMO_ApplyGiratinaAlteredForm(work, (void *)work->selectedMon);
                    POKELIST_ShowMessage(work, 0x40, 1, POKELIST_EndMessageToEvolve);
                    work->evolveCheckKind = 2;
                } else {
                    POKELIST_ShowMessage(work, 0x40, 1, POKELIST_EndMessageToExit);
                }
            }
            PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        }
    } else {
        if (work->arg->mode == 0xa) {
            work->arg->mode = 0;
            PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
            work->phase = 2;
            POKELIST_SetupModeScreen(work);
        } else
            work->phase = 0x13;
    }
}

void POKELIST_StartHpTransfer(PokelistWork *work)
{
    void *sourceMon;
    void *targetMon;
    u32 sourceMaxHp, targetHp, targetMaxHp, newHp;
    sourceMon = POKEPARTY_GetMember(work->arg->party, work->healSourceSlot);
    func_02017E1C(sourceMon, 0xa0, 0);
    sourceMaxHp = func_02017E1C(sourceMon, 0xa1, 0);
    targetMon = POKEPARTY_GetMember(work->arg->party, work->arg->selectedIndex);
    targetHp = func_02017E1C((void *)work->selectedMon, 0xa0, 0);
    targetMaxHp = func_02017E1C((void *)work->selectedMon, 0xa1, 0);
    work->selectedSlot = work->arg->selectedIndex;
    newHp = targetHp + sourceMaxHp / 5;
    if (newHp > targetMaxHp) {
        POKE_TOOL_SetPartyValue(targetMon, 0xa0, targetMaxHp);
    } else {
        POKE_TOOL_SetPartyValue(targetMon, 0xa0, newHp);
    }
    work->phaseCallback = POKELIST_ShowHealResult;
    work->phase = 10;
    work->healSoundPending = 1;
}

void POKELIST_ShowHealResult(PokelistWork *work)
{
    u16 hpNow;
    u16 hpBefore;
    hpNow = PLIST_PLATE_GetHp(work, work->plates[work->arg->selectedIndex]);
    work->selectedSlot = work->arg->selectedIndex;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    hpBefore = work->displayHp;
    if (hpBefore) {
        PLIST_MESSAGE_SetWordSetNumber(work, work->messageWindow, 1, (u16)(hpNow - hpBefore), 3);
        POKELIST_ShowMessage(work, 0x2c, 1, POKELIST_CloseMessageToList);
    }
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void POKELIST_OpenTakeMailMenu(PokelistWork *work)
{
    POKELIST_OpenMenuWithCallback(work, POKELIST_OnTakeMailChoice);
}

void POKELIST_OnTakeMailChoice(PokelistWork *work, int choice)
{
    int mailSlot;
    void *mail;
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (choice == 14) {
        mailSlot = MAIL_FindEmptySlot(work->arg->mailBox, 0);
        if (mailSlot >= 0) {
            mail = MAIL_Create(work->heapId);
            func_02017E1C((void *)work->selectedMon, 0xa7, (u32)mail);
            func_0200903C(work->arg->mailBox, 0, mailSlot, mail);
            func_020307B0(mail);
            POKE_TOOL_SetPartyValue((void *)work->selectedMon, 6, 0);
            PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
            POKELIST_ShowMessage(work, 0x1a, 1, POKELIST_CloseMessageToList);
        } else {
            POKELIST_ShowMessage(work, 0x1e, 1, POKELIST_CloseMessageToList);
        }
        return;
    }
    POKELIST_ShowMessage(work, 0x1b, 0, POKELIST_OpenMailItemMenu);
}

void POKELIST_OpenMailItemMenu(PokelistWork *work)
{
    POKELIST_OpenMenuWithCallback(work, POKELIST_OnMailItemChoice);
}

void POKELIST_OnMailItemChoice(PokelistWork *work, int choice)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    if (choice == 0xe) {
        int heldItem = func_02017E1C((void *)work->selectedMon, 6, 0);
        if (POKELIST_CheckBagItem(work, heldItem) == 0x3e7) {
            POKELIST_ShowMessage(work, 0x3f, 1, POKELIST_CloseMessageToList);
            return;
        }
        POKELIST_ReturnBagItem(work, heldItem);
        POKE_TOOL_SetPartyValue((void *)work->selectedMon, 6, 0);
        PLIST_PLATE_Redraw(work, work->plates[work->selectedSlot]);
        POKELIST_ShowMessage(work, 0x1f, 1, POKELIST_CloseMessageToList);
    } else {
        PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
        work->phase = 2;
        POKELIST_SetupModeScreen(work);
    }
}

void POKELIST_EndMessageToEvolve(PokelistWork *work)
{
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    work->phase = 14;
}

void POKELIST_ForceSelectionEnd(PokelistWork *work)
{
    u8 i;
    u8 j;
    PokelistRegulation *rules;
    int phase;
    if (work->touchDragState != 0)
        return;
    phase = work->phase;
    if (phase == 0x13)
        return;
    if (phase == 0x15)
        return;
    if (phase == 0)
        return;
    if (phase == 1)
        return;
    if (phase == 6)
        POKELIST_CloseContextMenu(work);
    work->touchDragState = 1;
    if (work->reservedWord == 1)
        work->phase = 0x11;
    else
        work->phase = 0x14;
    work->arg->selectedIndex = 6;
    work->arg->exitCode = 0;
    if (work->selectionConfirmed != 0)
        return;
    for (i = 0; i < 6; i++)
        work->arg->slotOrder[i] = 0;
    rules = work->arg->regulation;
    if (POKE_REGULATION_FindValidOrder(rules, work->arg->party, work->arg->slotOrder) != 0)
        return;
    for (i = 0; i < 6; i++)
        work->arg->slotOrder[i] = 0;
    for (j = 0; j < rules->minPartySize; j++)
        work->arg->slotOrder[j] = j + 1;
}

u32 POKELIST_FindMoveSlot(PokelistWork *work, void *mon)
{
    PokelistArg *arg = work->arg;
    if (arg->mode == 5 || arg->mode == 8)
        return POKE_TOOL_AddMove(mon, arg->moveId);
    else
        return POKE_TOOL_FindMoveSlot(mon, arg->moveId);
}

/*
 * Verified blocker C (one --thumb, no region, EXACT, 8 bytes):
 * typedef unsigned char u8; typedef unsigned short u16;
 * extern void POKE_TOOL_ReplaceBoxMoveSlot(void *,u16,u8);
 * void POKE_TOOL_ReplaceMoveSlot(void *p,u16 move,u8 slot) { POKE_TOOL_ReplaceBoxMoveSlot(p,move,slot); }
 * Extent ends with two bytes alignment padding.
 *
 * 2026-10-05 (D8 lane 15): 020182A0 now filed EXACT as src/matched/arm9/POKE_TOOL_ReplaceMoveSlot.c.
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void POKELIST_ReplaceMoveSlot(PokelistWork *work, void *mon, u32 slot)
{
    PokelistArg *arg = work->arg;
    if (arg->mode == 5 || arg->mode == 8)
        func_020181F4(mon, arg->moveId, slot);
    else
        POKE_TOOL_ReplaceMoveSlot(mon, arg->moveId, slot);
}

void POKELIST_ApplyItemEffect(PokelistWork *work, void *mon)
{
    NATSUKI_Calc(mon, 7, work->arg->itemUseParam, work->heapId);
}

void POKELIST_SetHeldItem(PokelistWork *work, void *mon, u16 itemId)
{
    u32 oldItem = func_02017E1C(mon, 6, 0);
    if (oldItem)
        POKELIST_ReturnBagItem(work, oldItem);
    POKE_TOOL_SetPartyValue(mon, 6, itemId);
    if (itemId)
        POKELIST_RemoveBagItem(work, itemId);
}

u32 POKELIST_CheckBagItem(PokelistWork *work, u16 itemId)
{
    return func_02007FB8(work->arg->bag, itemId, work->heapId);
}

u32 POKELIST_RemoveBagItem(PokelistWork *work, u16 itemId)
{
    return func_02007F1C(work->arg->bag, itemId, 1, work->heapId);
}

u32 POKELIST_ReturnBagItem(PokelistWork *work, u16 itemId)
{
    return func_02007E50(work->arg->bag, itemId, 1, work->heapId);
}
