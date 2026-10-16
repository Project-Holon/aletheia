/*
 * file:     startmenu.c
 * unit:     yes
 * function: STARTMENU_TitleDemoInit, STARTMENU_TitleDemoUpdateTimer, STARTMENU_TitleDemoCheckInput, STARTMENU_TitleDemoMain, STARTMENU_TitleDemoExit, STARTMENU_ResetDisplayState, STARTMENU_SetupDisplayBanks, STARTMENU_TitleDemoUpdateParts, STARTMENU_CaptureVblankTask, STARTMENU_CaptureInit, STARTMENU_CaptureRunTasks, STARTMENU_CaptureDelete, STARTMENU_CaptureSetBlend, STARTMENU_LogoInit, STARTMENU_LogoUpdate, STARTMENU_LogoDelete, STARTMENU_Demo3dInit, STARTMENU_Demo3dUpdate, STARTMENU_Demo3dDelete, STARTMENU_Demo3dSetFrame, STARTMENU_SpritesInit, STARTMENU_SpritesUpdate, STARTMENU_SpritesDelete, STARTMENU_MenuInit, STARTMENU_MenuMain, STARTMENU_MenuExit, STARTMENU_StateSetup, STARTMENU_StateWaitStart, STARTMENU_StateWaitFade, STARTMENU_StateSelectAnim, STARTMENU_StateWaitPrint, STARTMENU_StateSelectRow, STARTMENU_StateScroll, STARTMENU_StateConnectPrompt, STARTMENU_StateConfirmPrompt, STARTMENU_StateInfoMessage, STARTMENU_StateUnlockNotices, STARTMENU_VblankTask, STARTMENU_AddVblankTask, STARTMENU_RemoveVblankTask, STARTMENU_ClearGraphics, STARTMENU_SetupBackgrounds, STARTMENU_TeardownBackgrounds, STARTMENU_LoadGraphics, STARTMENU_CreateBlinkPalette, STARTMENU_DeleteBlinkPalette, STARTMENU_CreateTextSystem, STARTMENU_DeleteTextSystem, STARTMENU_CreateRowWindows, STARTMENU_DeleteRowWindows, STARTMENU_CreateActors, STARTMENU_DeleteActors, STARTMENU_CreateFrameManager, STARTMENU_DeleteFrameManager, STARTMENU_StartBrightnessEffect, STARTMENU_BuildRowList, STARTMENU_LoadRowBuffers, STARTMENU_FreeRowBuffers, STARTMENU_SetRowActorY, STARTMENU_LayoutRows, STARTMENU_DrawRowFrame, STARTMENU_PaintRowPalette, STARTMENU_RowTileY, STARTMENU_ScrollRowActors, STARTMENU_MoveCursor, STARTMENU_ShowRowActors, STARTMENU_DrawFrameBox, STARTMENU_ClearFrameBox, STARTMENU_OpenConfirmWindow, STARTMENU_CloseDescWindow, STARTMENU_OpenInfoWindow, STARTMENU_CloseInfoWindow, STARTMENU_OpenNoticeWindow, STARTMENU_StartMessage, STARTMENU_HideMessageWindow, STARTMENU_UpdateMessage, STARTMENU_OpenYesNoMenu, STARTMENU_BeginFadeOut, STARTMENU_BeginFadeIn, STARTMENU_BeginSelectAnim, STARTMENU_RefreshSaveStatus, STARTMENU_ChangeToIntroProc, STARTMENU_ReplaceWithBattleFlagProcWithSave, STARTMENU_ReplaceWithBattleFlagProcNoSave, STARTMENU_NewGameIntroInit, STARTMENU_NewGameIntroMain, STARTMENU_NewGameIntroEnd, STARTMENU_BattleFlagProcInit, STARTMENU_BattleFlagProcMain, STARTMENU_BattleFlagProcEnd, STARTMENU_SetNewPlayerNameAndGender, STARTMENU_ConfigPromptInit, STARTMENU_ConfigPromptEnd, STARTMENU_ConfigPromptMain, STARTMENU_ConfigPromptSetupGraphics, STARTMENU_InitBgLayer, STARTMENU_ConfigPromptDrawQuestion, STARTMENU_ConfigPromptDeleteWindows, STARTMENU_ConfigPromptHighlightChoice, STARTMENU_ConfigPromptReadInput, STARTMENU_ConfigPromptPulseColor, STARTMENU_LogoScreenInit, STARTMENU_LogoScreenMain, STARTMENU_LogoScreenEnd, STARTMENU_SaveEraseInit, STARTMENU_SaveEraseMain, STARTMENU_SaveEraseEnd, STARTMENU_SaveEraseStepSetup, STARTMENU_SaveEraseStepShowPrompt, STARTMENU_SaveEraseStepOpenFirstYesNo, STARTMENU_SaveEraseStepFirstConfirm, STARTMENU_SaveEraseStepOpenSecondYesNo, STARTMENU_SaveEraseStepSecondConfirm, STARTMENU_SaveEraseUpdateTimeIcon, STARTMENU_SaveEraseStepErase, STARTMENU_SaveEraseStepTeardown, STARTMENU_SaveEraseClearVram, STARTMENU_SaveEraseSetupGraphics, STARTMENU_SaveEraseExitGraphics, STARTMENU_SaveEraseAllocResources, STARTMENU_SaveEraseFreeResources, STARTMENU_SaveEraseCreateWindow, STARTMENU_SaveEraseDeleteWindow, STARTMENU_SaveEraseVblankTask, STARTMENU_SaveEraseStartVblankTask, STARTMENU_SaveEraseStopVblankTask, STARTMENU_SaveEraseStartMessage, STARTMENU_SaveEraseUpdateMessage, STARTMENU_SaveEraseOpenYesNo, STARTMENU_SaveEraseStartFadeIn, STARTMENU_SaveEraseStartFadeOut
 * address:  0x021B95A0
 * region:   ov088
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   FADE_Start  0x0204E720  arm
 *   BMP_SetDisplaySwap  0x0204363C  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   ICA_ANIME_GetFrame  0x0201160C  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   PM_VOICE_Play  0x02006984  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   FADE_IsActive  0x0204E804  arm
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb
 *   PM_VOICE_IsSlotActive  0x02006BD0  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4  ov168
 *   ov088_id       0x00000058  data  a1
 *   ov168_id       0x000000A8  data  a1
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   d_021BD508     0x021BD508  data  a4  ov088
 *   d_021BD420     0x021BD420  data  a4  ov088
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   G3D_SYSTEM_Init  0x02046440  arm
 *   GF_FONT_InitTextColor  0x0201DD60  thumb
 *   TCBL_Create  0x0203101C  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   BG_SYS_ResetSubDisplay  0x0204361C  arm
 *   TCBL_Main  0x020310C4  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   TCBL_Destroy  0x02031140  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02049624  0x02049624  arm
 *   ARC_UTIL_UploadBgPaletteFromArchive  0x0204989C  arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021BD470     0x021BD470  data  ov088  a4
 *   d_021BD490     0x021BD490  data  ov088  a4
 *   d_021BD430     0x021BD430  data  ov088  a4
 *   d_021BD450     0x021BD450  data  a4
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   G3D_UTIL_Create  0x02047CFC  arm
 *   G3D_UTIL_AddUnit  0x02047E88  arm
 *   G3D_UTIL_GetUnitObjIdx  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   G3D_CAMERA_Create  0x02048A24  arm
 *   ICA_ANIME_CreateStream  0x02011510  thumb
 *   G3D_LIGHT_CreateSlots  0x02048BC4  arm
 *   G3D_LIGHT_ApplySlots  0x02048C58  arm
 *   BG_SYS_SetLowBit  0x0204044C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_021BD410     0x021BD410  data  ov088  a4
 *   d_021BD3EC     0x021BD3EC  data  ov088  a4
 *   d_021BD3F8     0x021BD3F8  data  ov088  a4
 *   d_021BD404     0x021BD404  data  ov088  a4
 *   d_021BD3DC     0x021BD3DC  data  a4
 *   ICA_ANIME_IncFrameNoLoop  0x020115C0  thumb
 *   ICA_ANIME_SetCameraStatus  0x02011B8C  thumb
 *   G3D_CAMERA_Reset  0x02048AD0  arm
 *   func_02047964  0x02047964  arm
 *   G3D_SYSTEM_ApplyLookAt  0x020479D8  arm
 *   G3D_SYSTEM_DrawObject  0x02047A60  arm
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   d_021BD538     0x021BD538  data  ov088  a4
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   G3D_CAMERA_Delete  0x02048AC4  arm
 *   func_02048C4C  0x02048C4C  arm
 *   G3D_UTIL_RemoveUnit  0x020480E4  arm
 *   G3D_UTIL_Delete  0x02047E54  arm
 *   ICA_ANIME_SetFrame  0x020115EC  thumb
 *   G3D_SYSTEM_SetObjectAnimeFrame  0x0204784C  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterPalette  0x0204ABF0  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   BLOCK20_SAVEDATA_GetBlock  0x02009210  thumb
 *   GAME_DATA_GetEventWorkFromSave  0x02012FE4  thumb
 *   gStartMenuStateTable     0x021BD63C  data  ov088  a4
 *   GAME_BEACON_RegisterClearCallback  0x020274C8  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 *   d_021DF538     0x021DF538  data  ov121  a4
 *   d_02213C4C     0x02213C4C  data  a4
 *   d_0209DEF0     0x0209DEF0  data  a4
 *   d_021D77AC     0x021D77AC  data  ov016  a4
 *   d_021F6D78     0x021F6D78  data  ov107  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov121_id       0x00000079  data
 *   ov199_id       0x000000C7  data
 *   ov016_id       0x00000010  data
 *   ov107_id       0x0000006B  data
 *   GAME_SYNC_GetBlock  0x02009448  thumb
 *   func_020092EC  0x020092EC  thumb
 *   BEACON_SetSlotState  0x0200C2F0  thumb
 *   GFL_NET_IsIdle  0x0203D210  arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   func_020090E0  0x020090E0  thumb
 *   BMP_MENU_ProcessYesNo  0x0201FEBC  thumb
 *   APP_ENV_InitParentalControl  0x0202EB44  thumb
 *   APP_ENV_IsRunOnTwl  0x0202EB0C  thumb
 *   BG_SYS_LoadPlttEntry  0x02040EBC  arm
 *   gStartMenuUnlockNotices     0x021BD784  data  ov088  a4
 *   BG_SYS_Update  0x020419E4  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm
 *   d_021BD60C     0x021BD60C  data  ov088  a4
 *   d_021BD678     0x021BD678  data  a4
 *   d_021BD724     0x021BD724  data  a4
 *   d_021BD764     0x021BD764  data  a4
 *   d_021BD6C4     0x021BD6C4  data  a4
 *   d_021BD6E4     0x021BD6E4  data  a4
 *   d_021BD744     0x021BD744  data  a4
 *   d_021BD6A4     0x021BD6A4  data  a4
 *   d_021BD704     0x021BD704  data  a4
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   BLINK_PALANM_LoadPalettes  0x0202E9AC  thumb
 *   BLINK_PALANM_Delete  0x0202EA20  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   ZONEDATA_Init  0x020139B0  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200890C  0x0200890C  thumb
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   ZONEDATA_Exit  0x02013A48  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   ZUKAN_SAVE_GetBlock  0x0200CA10  thumb
 *   ZUKAN_SAVE_CountSeen  0x0200D0AC  thumb
 *   BEACON_CountFlags  0x0200C258  thumb
 *   gStartMenuWindowTemplates     0x021BD7C4  data  a1
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   d_021BD688     0x021BD688  data  a4
 *   d_021BD5DC     0x021BD5DC  data  a4
 *   d_021BD5E4     0x021BD5E4  data  a4
 *   d_021BD5D4     0x021BD5D4  data  a4
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   gStartMenuRowInfo     0x021BD5EC  data  a4
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   func_020071EC  0x020071EC  thumb
 *   BEACON_GetSlotState  0x0200C308  thumb
 *   func_02049EF4  0x02049EF4  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BGWINFRM_GetFrameBuffer  0x0202CF84  thumb
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   BG_SYS_ClearLayerEx  0x02041570  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   BMP_MENU_CreateYesNo  0x0201FDA0  thumb
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_020071E8  0x020071E8  thumb
 *   d_021BD818     0x021BD818  data  a4
 *   gStartMenuBattleFlagProcData     0x021BD824  data  a4
 *   SAVE_CONTROL_INTR_Create  0x021BD25C  thumb  ov088
 *   func_02007220  0x02007220  thumb
 *   MYSTATUS_Create  0x0200846C  thumb
 *   CONFIG_Create  0x020082EC  thumb
 *   NAMEIN_SETUP_CreateArgs  0x0216BFD4  thumb  ov010
 *   PROCSYS_Create  0x02031324  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GFL_USE_LoadWaveArcSet  0x02005A98  thumb
 *   PM_VOICE_Prepare  0x020069D4  thumb
 *   ov194_id       0x000000C2  data
 *   ov204_id       0x000000CC  data
 *   gNameInWaveArcCount     0x021F557C  data  ov194  a4
 *   gNameInWaveArcIds     0x021F558C  data  ov194  a4
 *   gIntroWaveArcCount     0x021BFD20  data  ov204  a4
 *   gIntroWaveArcIds     0x021BFD30  data  ov204  a4
 *   SAVE_CONTROL_INTR_Update  0x021BD2F4  thumb  ov088
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   gIntroProcData     0x021BFD24  data  ov204  a4
 *   gNameInProcData     0x021F5580  data  ov194  a4
 *   func_02005B04  0x02005B04  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_Copy  0x02008314  thumb
 *   PROCSYS_Delete  0x0203133C  arm
 *   func_02007210  0x02007210  thumb
 *   SAVE_OUTSIDE_Load  0x021DFC20  thumb  ov228
 *   SAVE_OUTSIDE_IsLoaded  0x021DFE90  thumb  ov228
 *   SAVE_OUTSIDE_CopyPayload  0x021DFEB0  thumb  ov228
 *   SAVE_OUTSIDE_Free  0x021DFDB8  thumb  ov228
 *   GAMESYSTEM_SetupInitWork  0x02011EEC  thumb
 *   NAMEIN_SETUP_FreeArgs  0x0216C0C0  thumb  ov010
 *   ov228_id       0x000000E4  data
 *   d_0209DF9C     0x0209DF9C  data  a4
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   CONFIG_SetBattleFlag  0x02008450  thumb
 *   d_021BD830     0x021BD830  data  a4
 *   CONFIG_GetBattleFlag  0x02008448  thumb
 *   BEACON_GetSlotStates  0x0200C31C  thumb
 *   SAVE_CONTROL_Reload  0x020070C8  thumb
 *   CONFIG_ApplyAppliedFlag  0x02008414  thumb
 *   BEACON_SetSlotStates  0x0200C324  thumb
 *   func_020084E4  0x020084E4  thumb
 *   func_0200854C  0x0200854C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0200852C  0x0200852C  thumb
 *   GF_STANDARD_Rand  0x0203F0A8  arm
 *   func_02008558  0x02008558  thumb
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 *   d_021BD8B8     0x021BD8B8  data  ov088  a4
 *   d_021BD848     0x021BD848  data  a4
 *   d_021BD858     0x021BD858  data  a4
 *   d_021BD878     0x021BD878  data  a4
 *   d_021BD898     0x021BD898  data  a4
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   d_021BD83C     0x021BD83C  data  a1
 *   FX_SinCosTable_   0x020A1B38  data
 *   NNS_GfdRegisterNewVramTransferTask  0x02061CA4  arm
 *   d_021BD944     0x021BD944  data  a4
 *   d_021BD8F4     0x021BD8F4  data  a4
 *   d_021BD904     0x021BD904  data  a4
 *   d_021BD924     0x021BD924  data  a4
 *   TIME_ICON_Update  0x0202F0B0  thumb
 *   d_021BDA20     0x021BDA20  data  a4
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   func_02005654  0x02005654  thumb
 *   SAVE_OUTSIDE_ClearFlash  0x021DFF18  thumb  ov228
 *   func_02007230  0x02007230  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_EraseExtraSave  0x02007400  thumb
 *   SAVE_CONTROL_DeleteExtraSave  0x020072A4  thumb
 *   func_0200566C  0x0200566C  thumb
 *   OS_ResetSystem  0x02087BCC  arm
 *   d_021BD9B0     0x021BD9B0  data  a4
 *   d_021BD980     0x021BD980  data  a4
 *   d_021BD990     0x021BD990  data  a4
 *   func_020461E4  0x020461E4  arm
 *   func_020461D4  0x020461D4  arm
 *   MSG_SPEED_GetWaitForSpeed  0x02013080  thumb
 *   UI_SetIntrDataGlobal  0x020351F8  arm
 *   d_021BDA0C     0x021BDA0C  data  ov088  a4
 *   d_021BD3B9     0x021BD3B9  data  ov088  a1
 *   SAVE_CONTROL_StartSave  0x02007150  thumb
 *   func_02008764  0x02008764  thumb
 *   func_02007218  0x02007218  thumb
 *   func_02007214  0x02007214  thumb
 *   func_0200721C  0x0200721C  thumb
 *   BACKUP_SYSTEM_IsFlashBusy  0x02031E70  arm
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   SAVE_CONTROL_INTR_Delete  0x021BD29C  thumb  ov088
 */

#define reg_G3X_DISP3DCNT (*(volatile u16 *)0x04000060)
#define REG_G3X_DISP3DCNT_GO_MASK  0x00002000
#define REG_G3X_DISP3DCNT_RO_MASK  0x00001000
#define REG_G3X_DISP3DCNT_AAE_MASK 0x00000010
#define REG_G3X_DISP3DCNT_ABE_MASK 0x00000008
#define REG_G3X_DISP3DCNT_ATE_MASK 0x00000004
struct Proc;
struct IcaAnime;
struct Proc;
struct DispConfig;
struct DispVram;
struct Tcbl;
struct Node;
struct S02031140;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct PrintSys;
struct Rec;
struct G3dSys;
struct LightSet;
struct LightSlot;
struct IcaAnime;
struct Light;
struct Arg;
struct Ctx;
struct AnmCtl;
struct Bank;
struct ClactActor;
struct SaveControl;
struct MyStatus;
struct Sub02009210Obj;
struct Sub020071CCCtrl;
struct Sub02009448Obj;
struct Blk34;
struct Row;
struct CodeIn;
struct Sub020090B0Obj;
struct BgTemplate;
struct PalAnmSlot;
struct WordSet;
struct PlayTime;
struct Sub02008828Obj;
struct Blk37;
struct Sub02008828Rec;
struct WinMgr;
struct Sub020071E4Ctrl;
struct Actor;
struct PtS;
struct Vec2;
struct Rec3;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed char s8;

#include "startmenu_types.h"

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

typedef long long      s64;

typedef int            fx32;

typedef int            BOOL;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short animSeq;
    unsigned char priority;
    unsigned char palOffset;
} ClactInitData;

typedef int (*StateFn)(StartMenuWork *);

typedef struct {
    u32 flagMask;
    u32 msgId;
} NoticeEntry;

typedef unsigned long OsIrqWord;

typedef struct DispConfigBlock {
    u32 w[4];
} DispConfigBlock;

typedef struct BgTemplateBlock {
    u32 w[8];
} BgTemplateBlock;

/* VRAM bank configuration words. */
typedef struct DispVramBlock {
    u32 w[12];
} DispVramBlock;

struct WindowTemplateEntry {
    u8 bgId, x, y, width, height, palette;
};

typedef struct ClactResConfig {
    u32 w[7];
} ClactResConfig;

struct RowInfo {
    u16 frameId;
    u16 height;
};

typedef struct {
    s16 x;
    s16 y;
} SpritePos;


typedef struct YesNoWindowTemplate {
    unsigned char bgId;
    unsigned char x;
    unsigned char y;
    unsigned char palette;
    unsigned short tileOffset;
} YesNoWindowTemplate;

extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int heap, unsigned int size);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *p, int v, int n);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern void BMP_SetDisplaySwap(u32 swap);
extern void BG_SYS_SetPlaneVisible(u32 which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern u32 ICA_ANIME_GetFrame(struct IcaAnime *p);
extern u32   KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int  FADE_IsActive(void);
extern void GFL_USE_PlayFanfare(void *arg);
extern u32  PM_VOICE_IsSlotActive(u32 a);
extern int  GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void PROCSYS_FreeProcWork(struct Proc *a);
extern void GFL_HEAP_DeleteChecked(unsigned int a);
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void CLACT_VBlankSystem(void);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, int);
extern void GF_FONT_InitTextColor(void);
extern void *TCBL_Create(int, int, int, int);
extern void *GFL_USE_AddMainTask(void *, void *, int);
extern void BG_SYS_ResetSubDisplay(void);
void TCBL_Main(struct Tcbl *p);
extern void TCB_DeleteTask(struct Node *n);
extern void TCBL_Destroy(struct S02031140 *p);
extern void G3D_SYSTEM_Exit(void);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void BG_SYS_PushTile(u32 layer);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void BG_SYS_SetTileEntry(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u32 a6);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32   G3D_UTIL_Create(u32 a, u32 b, u32 heap);
extern u16   G3D_UTIL_AddUnit(u32 a, const void *b);
extern u32 G3D_UTIL_GetUnitObjIdx(u8 *a0, int i);
extern u32   func_02048A18(u32 a, u16 b);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern fx32  FX_Div(fx32 numer, fx32 denom);
extern void *G3D_CAMERA_Create(int a, int s, int c, int d, int e, int f, int g, int h,
                           VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern void *ICA_ANIME_CreateStream(u32 heap, u32 a1, u32 a2, u32 a3);
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *s, u32 heap);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *slots);
extern void BG_SYS_SetLowBit(u32 mode);
extern u32 ICA_ANIME_IncFrameNoLoop(struct IcaAnime *p, s32 v);
extern void ICA_ANIME_SetCameraStatus(void *, void *);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void func_02047964(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);
extern void G3D_SYSTEM_DrawEnd(void);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void func_02048C4C(int);
extern void G3D_UTIL_RemoveUnit(struct Ctx *c, u32 i);
extern void G3D_UTIL_Delete(struct Rec *p);
extern void ICA_ANIME_SetFrame(struct IcaAnime *p, s32 v);
extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);
extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern int CLACT_RegisterCharacter(void *, int, int, int, int);
extern int CLACT_RegisterPalette(void *, int, int, int, int);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int CLACT_CreateActor(int, int, int, int, ClactInitData *, int, int);
extern void CLACT_SetActorAutoAnim(struct ClactActor *p, u32 v);
extern void ARC_TOOL_DeleteHandle(void *);
void CLACT_DrawSystem(void);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern struct SaveControl *func_020070A4(void);
extern struct MyStatus *func_02008730(void *sys);
extern void *BEACON_GetBlock(void *sys);
extern struct Sub02009210Obj *BLOCK20_SAVEDATA_GetBlock(void *sys);
extern void *GAME_DATA_GetEventWorkFromSave(struct Sub020071CCCtrl *a0);
extern void GAME_BEACON_RegisterClearCallback(void);
extern void STARTMENU_ReplaceWithBattleFlagProcNoSave(void);
extern void STARTMENU_ReplaceWithBattleFlagProcWithSave(void);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Sub02009448Obj *GAME_SYNC_GetBlock(void *sys);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void BEACON_SetSlotState(struct Blk34 *p, u32 i, u8 v);
extern u32 GFL_NET_IsIdle(void);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern s32 BLINK_PALANM_Update(struct Row *p);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern unsigned int KEY_GetRepeat(void);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern u32 BMP_MENU_ProcessYesNo(u8 *);
extern int APP_ENV_InitParentalControl(void);
extern u32 APP_ENV_IsRunOnTwl(void);
extern void BG_SYS_LoadPlttEntry(u32 a0, u32 a1);
extern void BG_SYS_Update(void);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct CodeIn *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void BLINK_PALANM_LoadPalettes(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 BLINK_PALANM_Delete(struct PalAnmSlot *p);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern u32 APP_KEYCURSOR_CreateDefault(u32, u32, u32, u32);
extern int APP_KEYCURSOR_Delete(int a0);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void WORDSET_SetSlotFromMsg59(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02008550(const struct MyStatus *obj);
extern void ZONEDATA_Init(u32 heap);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 *func_02008848(void *);
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void ZONEDATA_Exit(void);
extern struct PlayTime *func_02008748(void *sys);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *ZUKAN_SAVE_GetBlock(void *);
extern u32 ZUKAN_SAVE_CountSeen(struct Blk37 *p, u32 heap);
extern u32 BEACON_CountFlags(struct Blk34 *p);
extern void CLACT_SetActorDrawEnable(struct ClactActor *p, u32 v);
extern void CLACT_DeleteActor(struct ClactActor *p);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void G2x_SetBlendAlpha_(void *reg, int a, int b, int c, int d);
extern u8 func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 BEACON_GetSlotState(struct Blk34 *p, u32 i);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u16 e);
extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern u32 GFL_HEAP_Free(void *p);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct ClactActor *p, const struct Vec2 *delta, u32 which);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void BG_SYS_SetFlagField06(u32);
extern void BG_SYS_FillTileMap(u32, u32, u8, u8, u8, u32);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern signed char MSG_SPEED_GetWait(void);
extern u32 PRINTSYS_PrintStream(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                         u32 a8, u16 a9, u16 a10);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void *BMP_MENU_CreateYesNo(YesNoWindowTemplate *win, int base, int pal, int pos, int heap);
extern void WIPE_SYS_Start(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern u32 func_020071E8(const struct Sub020071E4Ctrl *ctrl);
int STARTMENU_TitleDemoInit(struct Proc *a0);
void STARTMENU_TitleDemoUpdateTimer(TitleDemoWork *work);
void STARTMENU_TitleDemoCheckInput(TitleDemoWork *work);
int STARTMENU_TitleDemoMain(int a0, int a1, int a2, TitleDemoWork *work);
int STARTMENU_TitleDemoExit(int a0, int a1, int a2, int *a3);
void STARTMENU_ResetDisplayState(void);
void STARTMENU_SetupDisplayBanks(void);
void STARTMENU_TitleDemoUpdateParts(TitleDemoWork *work);
void STARTMENU_CaptureVblankTask(void *task, TitleDemoCapture *capture);
void STARTMENU_CaptureInit(TitleDemoCapture *capture, int heap);
void STARTMENU_CaptureRunTasks(TitleDemoCapture *capture, int unused);
void STARTMENU_CaptureDelete(TitleDemoCapture *capture);
void STARTMENU_CaptureSetBlend(TitleDemoCapture *capture, unsigned short a, unsigned short b);
void STARTMENU_LogoInit(TitleDemoLogo *logo, u32 heap);
void STARTMENU_LogoUpdate(TitleDemoLogo *logo, int unused);
void STARTMENU_LogoDelete(TitleDemoLogo *logo);
void STARTMENU_Demo3dInit(TitleDemo3d *demo3d, u32 heap);
void STARTMENU_Demo3dUpdate(TitleDemo3d *demo3d, int unused);
void STARTMENU_Demo3dDelete(TitleDemo3d *demo3d);
void STARTMENU_Demo3dSetFrame(TitleDemo3d *demo3d, int x);
void STARTMENU_SpritesInit(TitleDemoSprites *sprites, int heap);
void STARTMENU_SpritesUpdate(TitleDemoSprites *sprites, int unused);
void STARTMENU_SpritesDelete(TitleDemoSprites *sprites);
int STARTMENU_MenuInit(struct Proc *a);
int STARTMENU_MenuMain(int a0, int a1, int a2, StartMenuWork *work);
int STARTMENU_MenuExit(int a0, int a1, int a2, StartMenuWork *work);
int STARTMENU_StateSetup(StartMenuWork *work);
int STARTMENU_StateWaitStart(StartMenuWork *work);
int STARTMENU_StateWaitFade(StartMenuWork *work);
int STARTMENU_StateSelectAnim(StartMenuWork *work);
int STARTMENU_StateWaitPrint(StartMenuWork *work);
int STARTMENU_StateSelectRow(StartMenuWork *work);
int STARTMENU_StateScroll(StartMenuWork *work);
int STARTMENU_StateConnectPrompt(StartMenuWork *work);
int STARTMENU_StateConfirmPrompt(StartMenuWork *work);
int STARTMENU_StateInfoMessage(StartMenuWork *work);
int STARTMENU_StateUnlockNotices(StartMenuWork *work);
int STARTMENU_StateBeginFadeIn(StartMenuWork *work);
void STARTMENU_VblankTask(void);
void STARTMENU_AddVblankTask(StartMenuWork *work);
void STARTMENU_RemoveVblankTask(StartMenuWork *work);
void STARTMENU_ClearGraphics(void);
void STARTMENU_SetupBackgrounds(void);
void STARTMENU_TeardownBackgrounds(void);
void STARTMENU_LoadGraphics(void);
void STARTMENU_CreateBlinkPalette(StartMenuWork *work);
void STARTMENU_DeleteBlinkPalette(StartMenuWork *work);
void STARTMENU_CreateTextSystem(StartMenuWork *work);
void STARTMENU_DeleteTextSystem(StartMenuWork *work);
void STARTMENU_CreateRowWindows(StartMenuWork *work);
void STARTMENU_DeleteRowWindows(StartMenuWork *work);
void STARTMENU_CreateActors(StartMenuWork *work);
void STARTMENU_DeleteActors(StartMenuWork *work);
void STARTMENU_CreateFrameManager(StartMenuWork *work);
void STARTMENU_DeleteFrameManager(StartMenuWork *work);
void STARTMENU_StartBrightnessEffect(void);
void STARTMENU_BuildRowList(StartMenuWork *work);
void STARTMENU_LoadRowBuffers(StartMenuWork *work);
void STARTMENU_FreeRowBuffers(StartMenuWork *work);
void STARTMENU_SetRowActorY(StartMenuWork *work, u32 idx, s16 y);
void STARTMENU_LayoutRows(StartMenuWork *work);
void STARTMENU_DrawRowFrame(StartMenuWork *work, u32 i, u32 arg);
void STARTMENU_PaintRowPalette(StartMenuWork *work, u8 row, int y, int pal);
int STARTMENU_RowTileY(StartMenuWork *work, int y);
void STARTMENU_ScrollRowActors(StartMenuWork *work, int d);
int STARTMENU_MoveCursor(StartMenuWork *work, int d);
void STARTMENU_ShowRowActors(StartMenuWork *work, int flag);
void STARTMENU_DrawFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg);
void STARTMENU_ClearFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg);
void STARTMENU_OpenConfirmWindow(StartMenuWork *work);
void STARTMENU_CloseDescWindow(StartMenuWork *work, int mode);
void STARTMENU_OpenInfoWindow(StartMenuWork *work);
void STARTMENU_CloseInfoWindow(StartMenuWork *work);
void STARTMENU_OpenNoticeWindow(StartMenuWork *work);
void STARTMENU_StartMessage(StartMenuWork *work, u32 a1);
void STARTMENU_HideMessageWindow(StartMenuWork *work);
int STARTMENU_UpdateMessage(StartMenuWork *work);
void STARTMENU_OpenYesNoMenu(StartMenuWork *work);
int STARTMENU_BeginFadeOut(StartMenuWork *work, int v);
int STARTMENU_BeginFadeIn(StartMenuWork *work, int v);
int STARTMENU_BeginSelectAnim(StartMenuWork *work, int v);
int STARTMENU_RefreshSaveStatus(StartMenuWork *work);
void STARTMENU_ChangeToIntroProc(void);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];
extern char d_021BD508[];
extern char d_021BD420[];
extern const BgTemplate d_021BD470;
extern const BgTemplate d_021BD490;
extern const BgTemplate d_021BD430;
extern const BgTemplate d_021BD450;
extern const s16 FX_SinCosTable_[];
extern const u32 d_021BD410[];
extern VecFx32 d_021BD3EC;
extern VecFx32 d_021BD3F8;
extern VecFx32 d_021BD404;
extern const u32 d_021BD3DC[];
extern char d_021BD538[];
extern char gClActorInitParam[];
extern StateFn gStartMenuStateTable[];
extern char d_021BDA00[];
extern char d_021DF538[];
extern char d_02213C4C[];
extern char d_0209DEF0[];
extern char d_021D77AC[];
extern char d_021F6D78[];
extern char d_021BD574[];
extern char ov121_id[];
extern char ov199_id[];
extern char ov016_id[];
extern char ov107_id[];
extern const NoticeEntry gStartMenuUnlockNotices[8];
extern char SDK_AUTOLOAD_DTCM_START[];
extern char d_021BD60C[];
extern DispConfigBlock d_021BD678;
extern BgTemplateBlock d_021BD724;
extern BgTemplateBlock d_021BD764;
extern BgTemplateBlock d_021BD6C4;
extern BgTemplateBlock d_021BD6E4;
extern BgTemplateBlock d_021BD744;
extern BgTemplateBlock d_021BD6A4;
extern BgTemplateBlock d_021BD704;
extern const struct WindowTemplateEntry gStartMenuWindowTemplates[];
extern ClactResConfig d_021BD688;
extern char d_021BD5DC[];
extern char d_021BD5E4[];
extern char d_021BD5D4[];
extern const struct RowInfo gStartMenuRowInfo[];
extern char d_021BD818[];

#define reg_G2_BLDCNT      (*(volatile u16 *)0x04000050)
#define reg_G2S_DB_BLDCNT  (*(volatile u16 *)0x04001050)
#define reg_GX_DISPCNT     (*(volatile u32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(volatile u32 *)0x04001000)
struct Sub02008700Obj;
struct S020314B8;
struct Ctrl;
struct Sub020072A4Ctrl;
struct Sub02007168;
/* Three world coordinates (x, y, z) of the player. */
typedef struct LocationPos {
    u32 x, y, z;
} LocationPos;

/* Player location block of the save data: map, position and facing. */
typedef struct SaveLocation {
    u16 mapId;
    u16 pad02;
    LocationPos position;
    u32 spawnX, spawnY;
    s16 facing;
    s16 spawnFlags;
} SaveLocation;
typedef unsigned long long u64;
typedef enum { Z0 } Zero;

extern void func_02005B04(const u32 *arg);
extern void MYSTATUS_Copy(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void CONFIG_Copy(void *, void *);
extern void PROCSYS_Delete(struct S020314B8 *p);
extern u8 func_02007210(const struct Sub020071E4Ctrl *ctrl);
extern int GF_OVERLAY_Load(signed int overlayId);
extern void GF_OVERLAY_Unload(int overlayId);
extern void *SAVE_OUTSIDE_Load(u32 heap);
extern u8 SAVE_OUTSIDE_IsLoaded(u8 *p);
extern void SAVE_OUTSIDE_CopyPayload(char *p, void *ctrl);
extern void SAVE_OUTSIDE_Free(void *);
extern void *GAMESYSTEM_SetupInitWork(u32 a0, u16 a1, LocationPos *position, int a3);
extern int NAMEIN_SETUP_FreeArgs(int);
extern void PROCSYS_PushGlobal(u32 a0, u32 a1, u32 a2);
extern void CONFIG_SetBattleFlag(struct Config *config, int on);
extern unsigned int CONFIG_GetBattleFlag(const struct Config *config);
extern u8 BEACON_GetSlotStates(struct Blk34 *p);
extern int SAVE_CONTROL_Reload(char *self);
extern u8 CONFIG_ApplyAppliedFlag(const struct Config *config);
extern void BEACON_SetSlotStates(struct Blk34 *p, u8 v);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void func_0200854C(int, int);
extern u32 func_02005728(u32 range);
extern void func_0200852C(struct MyStatus *obj, u32 value);
extern u32 GF_STANDARD_Rand(void);
extern void func_02008558(struct MyStatus *obj, u8 value);
extern void CONFIG_SetAppliedFlag(struct Config *config, unsigned int on);
extern void BG_SYS_FreeSlot(int a);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern int TOUCHPANEL_HitTrg(const void *p);
extern s32 NNS_GfdRegisterNewVramTransferTask(void *p, u32 a, u32 b, s32 size);
extern void TIME_ICON_Update(u8 *p);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern int func_02005654(int a, int b);
extern void SAVE_OUTSIDE_ClearFlash(u32 heap);
extern void *func_02007230(struct Sub020071E4Ctrl *ctrl);
extern u32 SAVE_CONTROL_LoadExtraSave(struct Ctrl *ctrl, u32 id, u8 heap);
extern void SAVE_CONTROL_EraseExtraSave(char *a0, u32 a1, u32 a2);
extern void SAVE_CONTROL_DeleteExtraSave(struct Sub020072A4Ctrl *ctrl, u32 id);
extern void func_0200566C(void);
extern void OS_ResetSystem(u32 parameter);
extern u8 func_020461E4(void);
extern void func_020461D4(u8);
extern signed char MSG_SPEED_GetWaitForSpeed(u32 idx);
extern void UI_SetIntrDataGlobal(u32 a, u32 b);
int SAVE_CONTROL_StartSave(int a0);
void func_02008764(void *);
u8 func_02007218(const struct Sub020071E4Ctrl *ctrl);
void func_02007214(void *, u32);
void func_0200721C(void *, u32);
extern int BACKUP_SYSTEM_IsFlashBusy(void);
extern u32 SAVE_CONTROL_MainSave(struct Sub02007168 *p);
int STARTMENU_NewGameIntroEnd(struct Proc *proc, int *seq, void *procWork, NewGameIntroWork *work);
int STARTMENU_BattleFlagProcInit(struct Proc *a0);
int STARTMENU_BattleFlagProcMain(void *proc, int *seq, int mode, NewGameIntroWork *work);
int STARTMENU_BattleFlagProcEnd(struct Proc *proc, int seq, int mode, NewGameIntroWork *work);
void STARTMENU_SetNewPlayerNameAndGender(struct MyStatus *myStatus, struct Strbuf *name, int gender);
int STARTMENU_ConfigPromptInit(struct Proc *proc, int seq, int *procWork);
int STARTMENU_ConfigPromptEnd(int proc, int seq, int procWork, ConfigPromptWork *work);
int STARTMENU_ConfigPromptMain(int proc, int seq, NewGameStartArg *startArg, ConfigPromptWork *work);
void STARTMENU_ConfigPromptSetupGraphics(ConfigPromptWork *work);
void STARTMENU_InitBgLayer(const void *bgTemplate, int bgId);
void STARTMENU_ConfigPromptDrawQuestion(ConfigPromptWork *work);
void STARTMENU_ConfigPromptDeleteWindows(ConfigPromptWork *work);
void STARTMENU_ConfigPromptHighlightChoice(ConfigPromptWork *work);
int STARTMENU_ConfigPromptReadInput(ConfigPromptWork *work);
s32 STARTMENU_ConfigPromptPulseColor(ConfigPromptWork *work);
int STARTMENU_LogoScreenInit(struct Proc *proc);
int STARTMENU_LogoScreenMain(int proc, int seq, int *variant, LogoScreenWork *work);
int STARTMENU_LogoScreenEnd(int proc);
int STARTMENU_SaveEraseInit(struct Proc *proc);
int STARTMENU_SaveEraseMain(int proc, int *seq, int procWork, SaveEraseWork *work);
int STARTMENU_SaveEraseEnd(int proc);
void STARTMENU_SaveEraseStepSetup(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseStepShowPrompt(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseStepOpenFirstYesNo(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseStepFirstConfirm(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseStepOpenSecondYesNo(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseStepSecondConfirm(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseUpdateTimeIcon(void);
void STARTMENU_SaveEraseStepErase(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseStepTeardown(SaveEraseWork *work, int *seq);
void STARTMENU_SaveEraseClearVram(void);
void STARTMENU_SaveEraseSetupGraphics(void);
void STARTMENU_SaveEraseExitGraphics(void);
void STARTMENU_SaveEraseAllocResources(SaveEraseWork *work);
void STARTMENU_SaveEraseFreeResources(SaveEraseWork *work);
void STARTMENU_SaveEraseCreateWindow(SaveEraseWork *work);
void STARTMENU_SaveEraseDeleteWindow(SaveEraseWork *work);
void STARTMENU_SaveEraseVblankTask(void);
void STARTMENU_SaveEraseStartVblankTask(SaveEraseWork *work);
void STARTMENU_SaveEraseStopVblankTask(SaveEraseWork *work);
void STARTMENU_SaveEraseStartMessage(SaveEraseWork *work, u32 messageId);
int STARTMENU_SaveEraseUpdateMessage(SaveEraseWork *work);
void STARTMENU_SaveEraseOpenYesNo(SaveEraseWork *work);
void STARTMENU_SaveEraseStartFadeIn(void);
void STARTMENU_SaveEraseStartFadeOut(void);
extern u8 ov228_id[];
extern char d_0209DF9C[];
extern char d_021BD830[];
extern char d_021BD8B8[];
extern char d_021BD848[];
extern char d_021BD858[];
extern char d_021BD878[];
extern char d_021BD898[];
extern TouchHitTable d_021BD83C;
extern const u8 d_021BD944[];
extern const u8 d_021BD8F4[];
extern const u8 d_021BD904[];
extern const u8 d_021BD924[];
extern void *d_021BDA20;
extern DispVramBlock d_021BD9B0;
extern DispConfigBlock d_021BD980;
extern BgTemplateBlock d_021BD990;
struct SaveControl;
struct ProcSys;
struct ProcData;
struct Config;
struct MyStatus;
struct WaveArcSet;
struct Strbuf;
extern struct SaveControlIntr *SAVE_CONTROL_INTR_Create(int heapId, struct SaveControl *saveControl);
extern void *func_02007220(struct SaveControl *saveControl);
extern struct MyStatus *MYSTATUS_Create(int heapId);
extern struct Config *CONFIG_Create(int heapId);
extern NameInArgs *NAMEIN_SETUP_CreateArgs(unsigned short heapId, int kind, short species, short traits, int maxLen, struct Strbuf *initialName, void *pokedex);
extern struct ProcSys *PROCSYS_Create(int heapId);
extern struct WaveArcSet *GFL_USE_LoadWaveArcSet(const u32 *ids, u32 count);
extern int PM_VOICE_Prepare(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8);
extern u32 SAVE_CONTROL_INTR_Update(struct SaveControlIntr *saveIntr);
extern unsigned int PROCSYS_Main(struct ProcSys *procSys);
extern void PROCSYS_Push(struct ProcSys *procSys, u32 overlayId, const struct ProcData *data, void *procWork);
int STARTMENU_NewGameIntroInit(struct Proc *proc);
int STARTMENU_NewGameIntroMain(void *proc, int *seq, void *procWork, NewGameIntroWork *work);
extern const struct ProcData gStartMenuBattleFlagProcData;
extern u8 ov194_id[];
extern u8 ov204_id[];
extern u32 gNameInWaveArcCount;
extern u32 gNameInWaveArcIds[];
extern u32 gIntroWaveArcCount;
extern u32 gIntroWaveArcIds[];
extern const struct ProcData gIntroProcData;
extern const struct ProcData gNameInProcData;
extern void SAVE_CONTROL_INTR_Delete(void *p);







int STARTMENU_TitleDemoInit(struct Proc *allocator)
{
    TitleDemoWork *work;

    GFL_HEAP_CreateChildHeap(1, 0x16, 0x120000);
    work = PROCSYS_AllocProcWork(allocator, 0x98, 0x16);
    MI_CpuFill8(work, 0, 0x98);
    work->heapId = 0x16;
    return 1;
}






void STARTMENU_TitleDemoUpdateTimer(TitleDemoWork *work)
{
    if (work->frameCount == 0x29A) {
        FADE_Start(12, 16, 0, 3);
        BMP_SetDisplaySwap(1);
        BG_SYS_SetPlaneVisible(6, 0);
        BG_SYS_SetSubPlaneVisible(16, 0);
        BG_SYS_SetMainPlaneVisible(8, 0);
        work->phase = 1;
    }
    if (work->phase == 2 && ICA_ANIME_GetFrame((struct IcaAnime *)work->demo3d.anime) == 0x015F3000)
        STARTMENU_Demo3dSetFrame(&work->demo3d, 0x14B5);
    work->frameCount += 1;
    if (work->frameCount > 0x1248) {
        work->result = 1;
        work->state = 5;
    }
}






void STARTMENU_TitleDemoCheckInput(TitleDemoWork *work)
{
    if ((KEY_GetTrg() & 0xB) && work->phase == 1) {
        BMP_SetDisplaySwap(0);
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetPlaneVisible(3, 1);
        BG_SYS_SetSubPlaneVisible(0x10, 1);
        STARTMENU_Demo3dSetFrame(&work->demo3d, 0x14B5);
        work->phase = 2;
        return;
    }
    if (KEY_GetTrg() & 9) {
        work->result = 0;
        work->state = 4;
        work->fanfareHandle = (void *)PM_VOICE_Play(0x283, 0, 0x40, 0, 0, 0, 0, 0);
        STARTMENU_Demo3dSetFrame(&work->demo3d, 0x1389);
        BMP_SetDisplaySwap(0);
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetSubPlaneVisible(0x10, 0);
        FADE_Start(0xC, 0x10, 0, 3);
        GFL_USE_FadeOutBgm(4);
        STARTMENU_CaptureSetBlend(&work->capture, 8, 8);
        return;
    }
    if (KEY_GetCont() == 0x46) {
        work->result = 2;
        work->state = 5;
    } else if (KEY_GetCont() == 0xC80) {
        work->result = 3;
        work->state = 5;
    }
}






int STARTMENU_TitleDemoMain(int unusedArg0, int unusedArg1, int unusedArg2, TitleDemoWork *work)
{
    switch (work->state) {
    case 0:
        STARTMENU_ResetDisplayState();
        STARTMENU_SetupDisplayBanks();
        work->state = 1;
        break;
    case 1:
        STARTMENU_CaptureInit(&work->capture, work->heapId);
        STARTMENU_LogoInit(&work->logo, work->heapId);
        STARTMENU_Demo3dInit(&work->demo3d, work->heapId);
        STARTMENU_SpritesInit(&work->sprites, work->heapId);
        FADE_Start(3, 0x10, 0, 2);
        work->frameCount = 0;
        work->state = 2;
        GFL_USE_PlayFanfare((void *)0x3EF);
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            work->state = 3;
        }
        STARTMENU_TitleDemoUpdateParts(work);
        break;
    case 3:
        STARTMENU_TitleDemoUpdateParts(work);
        STARTMENU_TitleDemoCheckInput(work);
        STARTMENU_TitleDemoUpdateTimer(work);
        break;
    case 4:
        if (PM_VOICE_IsSlotActive((unsigned int)work->fanfareHandle) == 0) {
            work->state = 5;
        }
        STARTMENU_TitleDemoUpdateParts(work);
        break;
    case 5:
        FADE_Start(3, 0, 0x10, 2);
        work->state = 6;
        STARTMENU_TitleDemoUpdateParts(work);
        GFL_USE_FadeOutBgm(0x10);
        break;
    case 6:
        if (FADE_IsActive() == 0 && GFL_USE_IsBgmFading() == 0) {
            GFL_USE_CancelChangeAndStopBgm();
            work->state = 7;
        }
        STARTMENU_TitleDemoUpdateParts(work);
        break;
    case 7:
        STARTMENU_SpritesDelete(&work->sprites);
        STARTMENU_Demo3dDelete(&work->demo3d);
        STARTMENU_LogoDelete(&work->logo);
        STARTMENU_CaptureDelete(&work->capture);
        return 1;
    case 8:
        return 1;
    }
    return 0;
}






int STARTMENU_TitleDemoExit(int procCtx, int unusedArg1, int unusedArg2, int *procArgs)
{
    int target = procArgs[1];

    PROCSYS_FreeProcWork((struct Proc *)procCtx);
    GFL_HEAP_DeleteChecked(0x16);
    if (target == 0) {
        PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD66C, 0);
    } else if (target == 2) {
        PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD974, 0);
    } else if (target == 3) {
        PROCSYS_ReplaceGlobal((u32)ov168_id, (u32)d_02184904, 0);
    }
    return 1;
}






void STARTMENU_ResetDisplayState(void)
{
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
}






void STARTMENU_SetupDisplayBanks(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BD508);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BD420);
}






void STARTMENU_TitleDemoUpdateParts(TitleDemoWork *work)
{
    STARTMENU_CaptureRunTasks(&work->capture, work->heapId);
    STARTMENU_LogoUpdate(&work->logo, work->heapId);
    STARTMENU_Demo3dUpdate(&work->demo3d, work->heapId);
    STARTMENU_SpritesUpdate(&work->sprites, work->heapId);
}






void STARTMENU_CaptureVblankTask(void *task, TitleDemoCapture *capture)
{
    CLACT_VBlankSystem();
    *(volatile unsigned int *)0x04000064 = (short)capture->captureEva | (0xC0330000 | ((short)capture->captureEvb << 8));
}






void STARTMENU_CaptureInit(TitleDemoCapture *capture, int heap)
{
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    G3D_SYSTEM_Init(0, 2, 0, 2, 0x1000, heap, 0);
    GF_FONT_InitTextColor();
    capture->taskList = (int)TCBL_Create(heap, heap, 4, 0x20);
    capture->vblankTask = (int)GFL_USE_AddMainTask((void *)STARTMENU_CaptureVblankTask, capture, 5);
    BMP_SetDisplaySwap(0);
    BG_SYS_ResetSubDisplay();
    capture->captureEva = 12;
    capture->captureEvb = 4;
}











void STARTMENU_CaptureRunTasks(TitleDemoCapture *capture, int unused)
{
    TCBL_Main((struct Tcbl *)capture->taskList);
}











void STARTMENU_CaptureDelete(TitleDemoCapture *capture)
{
    BMP_SetDisplaySwap(1);
    BG_SYS_ResetSubDisplay();
    TCB_DeleteTask((struct Node *)capture->vblankTask);
    TCBL_Destroy((struct S02031140 *)capture->taskList);
    G3D_SYSTEM_Exit();
    BMP_WIN_Exit();
    BG_SYS_Delete();
}










void STARTMENU_CaptureSetBlend(TitleDemoCapture *capture, unsigned short a, unsigned short b)
{
    capture->captureEva = a;
    capture->captureEvb = b;
}











void STARTMENU_LogoInit(TitleDemoLogo *logo, u32 heap)
{
    int textWidth;

    BG_SYS_InitBgLayer(3, &d_021BD470, 0);
    BG_SYS_InitBgLayer(5, &d_021BD490, 0);
    BG_SYS_InitBgLayer(7, &d_021BD430, 0);
    BG_SYS_InitBgLayer(6, &d_021BD450, 0);
    func_02049624(0x1A, 9, 3, 0, 0, 1, heap);
    ARC_UTIL_UploadBgPaletteFromArchive(0x1A, 10, 3, 0, 0, 1, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x1A, 8, 0, 0, 0, heap);
    BG_SYS_PushTile(3);
    BG_SYS_SetPlaneVisible(3, 1);
    func_02049624(0x1A, 0, 7, 0, 0x8000, 1, heap);
    ARC_UTIL_UploadBgPaletteFromArchive(0x1A, 1, 7, 0, 0, 1, heap);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x1A, 2, 4, 0, 0, heap);
    BG_SYS_PushTile(7);
    BG_SYS_SetPlaneVisible(7, 1);
    ARC_UTIL_UploadBgPaletteFromArchive(0x1A, 3, 6, 0, 0, 1, heap);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_Init(5, 0, 1, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    logo->textWindow = BMP_WIN_Create(5, 0, 0x13, 0x20, 2, 0xA, 0);
    logo->textBitmap = (u32)BMP_WIN_GetBmp((struct Descriptor *)logo->textWindow);
    BMP_Clear((struct CharBuf *)logo->textBitmap, 0);
    BMP_WIN_MakeScreen((struct Cfg *)logo->textWindow);
    BMP_WIN_TransferChars((struct Descriptor *)logo->textWindow);
    logo->windowDirty = 0;
    logo->textWindowCopy = logo->textWindow;
    BG_SYS_PushTile(5);
    logo->font = (u32)GF_FONT_Create(0x17, 0, 0, 0, heap);
    logo->printer = PRINTSYS_QUE_Create((void *)heap);
    logo->msgBank = (u32)MSGDATA_CreateFromArchive(0, 2, 0xB5, heap);
    logo->titleText = (u32)STRBUF_Create(0x40, heap);
    func_02045CAC((struct MsgBank *)logo->msgBank, 1, (void *)logo->titleText);
    textWidth = GF_FONT_MeasureWidestLine((struct StrObj *)logo->titleText, logo->font, 0);
    PRINTSYS_PrintQueColor((void *)logo->printer, logo->textBitmap, (s16)(0x80 - textWidth / 2), (s16)0, logo->titleText, logo->font, 0x440);
    logo->ready = 1;
}











void STARTMENU_LogoUpdate(TitleDemoLogo *logo, int unused)
{
    BG_SYS_SetPlaneVisible(5, 0);
    BG_SYS_ResetSlot(6, 0, logo->bgScroll / 2);
    if (GPOWER_GetSpecialPowerId() == 0x15) {
        logo->bgScroll++;
    } else {
        logo->bgScroll--;
    }
}











void STARTMENU_LogoDelete(TitleDemoLogo *logo)
{
    STRBUF_Delete((struct U16Vec *)logo->titleText);
    MSGDATA_Delete((struct Rec *)logo->msgBank);
    PRINTSYS_QUE_Delete((struct PrintSys *)logo->printer);
    GF_FONT_Delete((void *)logo->font);
    BMP_WIN_Delete((struct Descriptor *)logo->textWindow);
}











static inline void G3X_AntiAlias(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_AAE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_AAE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}











static inline void G3X_AlphaTest(BOOL enable, int ref)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ATE_MASK);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ATE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}











static inline void G3X_AlphaBlend(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ABE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ABE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}











static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}











/*
 * Levers: the four ortho bounds bound to locals before the G3D_CAMERA_Create
 * call (inline in the argument list they evaluate in another order); the
 * sin/cos pair read as FX_SinCosTable_[0x2AA]/[0x2AB] (pool word base +
 * 0x540); d_021BD3DC without its ov088 token (contested hint).
 * volatile: 0x04000060 (DISP3DCNT) read-modify-written by the G3X_AntiAlias,
 *           G3X_AlphaTest and G3X_AlphaBlend inlines at 0x021B9D80-0x021B9D9C
 */
void STARTMENU_Demo3dInit(TitleDemo3d *demo3d, u32 heap)
{
    int base;
    fx32 sinValue;
    fx32 cosValue;
    fx32 scaledSin;
    fx32 top;
    fx32 bottom;
    fx32 left;
    fx32 right;

    demo3d->renderer = G3D_UTIL_Create(7, 3, heap);
    demo3d->modelId = G3D_UTIL_AddUnit(demo3d->renderer, d_021BD410);
    base = G3D_UTIL_GetUnitObjIdx((u8 *)demo3d->renderer, demo3d->modelId);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(demo3d->renderer, base), 0);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(demo3d->renderer, base), 1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(demo3d->renderer, base + 1), 0);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(demo3d->renderer, base + 2), 0);

    cosValue = FX_SinCosTable_[0x2AB];
    sinValue = FX_SinCosTable_[0x2AA];
    scaledSin = FX_Mul(sinValue, 0x19A);
    top = FX_Div(scaledSin, cosValue);
    bottom = -FX_Div(scaledSin, cosValue);
    right = FX_Div(FX_Mul(FX_Div(0x223, 0x1000), sinValue), cosValue);
    left = -FX_Div(FX_Mul(FX_Div(0x223, 0x1000), sinValue), cosValue);
    demo3d->camera = G3D_CAMERA_Create(1, top, bottom, left, right,
                           0x19A, 0x800000, 0x19A,
                           &d_021BD3EC, &d_021BD3F8, &d_021BD404, heap);
    demo3d->anime = (u32)ICA_ANIME_CreateStream(heap, 0xA0, 0xE9, 0xA);
    demo3d->lightSet = (u32)G3D_LIGHT_CreateSlots((const struct LightSet *)d_021BD3DC, heap);
    G3D_LIGHT_ApplySlots((struct LightSlot *)demo3d->lightSet);
    BG_SYS_SetLowBit(1);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
}










void STARTMENU_Demo3dUpdate(TitleDemo3d *demo3d, int unused)
{
    int base;
    unsigned modelIndex;
    void *modelHandle;
    base = G3D_UTIL_GetUnitObjIdx((void *)demo3d->renderer, demo3d->modelId);
    ICA_ANIME_IncFrameNoLoop((void *)demo3d->anime, 0x1000);
    ICA_ANIME_SetCameraStatus((void *)demo3d->camera, (void *)demo3d->anime);
    G3D_CAMERA_Reset((void *)demo3d->camera);
    func_02047964();
    G3D_SYSTEM_ApplyLookAt();
    for (modelIndex = 0; modelIndex < 3; modelIndex++) {
        modelHandle = (void *)func_02048A18((u32)((void *)demo3d->renderer), (unsigned short)(base + modelIndex));
        G3D_SYSTEM_DrawObject(modelHandle, (struct Arg *)d_021BD538);
    }
    G3D_SYSTEM_DrawEnd();
    for (modelIndex = 0; modelIndex < 3; modelIndex++) {
        modelHandle = (void *)func_02048A18((u32)((void *)demo3d->renderer), (unsigned short)(base + modelIndex));
        G3D_SYSTEM_LoopObjectAnimeFrame(modelHandle, 0, 0x1000);
        if (modelIndex == 0)
            G3D_SYSTEM_LoopObjectAnimeFrame(modelHandle, 1, 0x1000);
    }
}










/*
 * note:     listing extent (40) runs 2 bytes past the compiled function (38);
 *           trailing alignment padding, no byte difference.
 */
void STARTMENU_Demo3dDelete(TitleDemo3d *demo3d)
{
    ICA_ANIME_Delete((struct IcaAnime *)demo3d->anime);
    G3D_CAMERA_Delete((void *)demo3d->camera);
    func_02048C4C(demo3d->lightSet);
    G3D_UTIL_RemoveUnit((struct Ctx *)demo3d->renderer, demo3d->modelId);
    G3D_UTIL_Delete((struct Rec *)demo3d->renderer);
}










void STARTMENU_Demo3dSetFrame(TitleDemo3d *demo3d, int frame)
{
    int frameValue;
    int base;
    unsigned modelIndex;
    void *modelHandle;
    frameValue = frame << 12;
    ICA_ANIME_SetFrame((void *)demo3d->anime, frameValue);
    base = G3D_UTIL_GetUnitObjIdx((void *)demo3d->renderer, demo3d->modelId);
    for (modelIndex = 0; modelIndex < 3; modelIndex++) {
        modelHandle = (void *)func_02048A18((u32)((void *)demo3d->renderer), (unsigned short)(base + modelIndex));
        G3D_SYSTEM_SetObjectAnimeFrame(modelHandle, 0, &frameValue);
        if (modelIndex == 0)
            G3D_SYSTEM_SetObjectAnimeFrame(modelHandle, 1, &frameValue);
    }
}









void STARTMENU_SpritesInit(TitleDemoSprites *sprites, int heap)
{
    ClactInitData initData;
    void *archive;
    archive = ARC_TOOL_CreateHandle(0x1a, heap);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam, (unsigned int)d_021BD508, heap);
    sprites->unit = (int)CLACT_CreateUnit(0x40, 0, heap);
    CLACT_SetUnitDefaultRenderer((void *)sprites->unit);
    sprites->charRes = CLACT_RegisterCharacter(archive, 5, 1, 1, heap);
    sprites->paletteRes = CLACT_RegisterPalette(archive, 4, 1, 0, heap);
    sprites->cellRes = CLACT_RegisterCellAnim(archive, 6, 7, heap);
    initData.x = 0x80;
    initData.y = 0x60;
    initData.animSeq = 0;
    initData.palOffset = 0;
    initData.priority = 0;
    sprites->actor = CLACT_CreateActor(sprites->unit, sprites->charRes, sprites->paletteRes, sprites->cellRes, &initData, 1, heap);
    CLACT_SetActorAutoAnim((struct ClactActor *)sprites->actor, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    ARC_TOOL_DeleteHandle(archive);
}









void STARTMENU_SpritesUpdate(TitleDemoSprites *sprites, int unused)
{
    CLACT_DrawSystem();
}









void STARTMENU_SpritesDelete(TitleDemoSprites *sprites)
{
    CLACT_ReleaseCharacter(sprites->charRes);
    CLACT_ReleasePalette(sprites->paletteRes);
    CLACT_ReleaseCellAnim(sprites->cellRes);
    CLACT_DeleteUnit((struct Bank *)sprites->unit);
    CLACT_ExitSystem();
}









int STARTMENU_MenuInit(struct Proc *allocator)
{
    StartMenuWork *work;
    GFL_HEAP_CreateChildHeap(1, 0xb, 0x80000);
    work = PROCSYS_AllocProcWork(allocator, 0x150, 0xb);
    MI_CpuFill8(work, 0, 0x150);
    work->saveData = (void *)func_020070A4();
    work->playerData = (void *)func_02008730(work->saveData);
    work->unlockData = (void *)BEACON_GetBlock(work->saveData);
    work->connectData = (void *)BLOCK20_SAVEDATA_GetBlock(work->saveData);
    work->eventWork = (void *)GAME_DATA_GetEventWorkFromSave((struct Sub020071CCCtrl *)work->saveData);
    return 1;
}









int STARTMENU_MenuMain(int unusedArg0, int unusedArg1, int unusedArg2, StartMenuWork *work)
{
    int nextState = gStartMenuStateTable[work->state](work);
    work->state = nextState;
    if (nextState == 12) {
        return 1;
    }
    TCBL_Main((struct Tcbl *)(work->taskList));
    CLACT_DrawSystem();
    return 0;
}









int STARTMENU_MenuExit(int procCtx, int unusedArg1, int unusedArg2, StartMenuWork *work)
{
    u8 selectedRow = work->selectedRow;
    u8 hasSave = work->connectResult;
    char *procArgs;

    PROCSYS_FreeProcWork((struct Proc *)procCtx);
    GFL_HEAP_DeleteChecked(0xb);
    switch (selectedRow) {
    case 0:
        GAME_BEACON_RegisterClearCallback();
        if (hasSave == 0)
            STARTMENU_ReplaceWithBattleFlagProcNoSave();
        else
            STARTMENU_ReplaceWithBattleFlagProcWithSave();
        break;
    case 1:
        GAME_BEACON_RegisterClearCallback();
        STARTMENU_ChangeToIntroProc();
        break;
    case 2:
        PROCSYS_ReplaceGlobal((int)ov121_id, (u32)d_021DF538, 0);
        break;
    case 3:
        procArgs = GFL_HEAP_Alloc(1, 0x14, 0, d_021BDA00, 0x200);
        MI_CpuFill8(procArgs, 0, 0x14);
        ((StartMenuOv199Args *)procArgs)->selection = 0;
        ((StartMenuOv199Args *)procArgs)->fromTitleMenu = 1;
        PROCSYS_ReplaceGlobal((int)ov199_id, (u32)d_02213C4C, (u32)procArgs);
        break;
    case 4:
        PROCSYS_ReplaceGlobal(-1, (u32)d_0209DEF0, 0);
        break;
    case 5:
        PROCSYS_ReplaceGlobal((int)ov016_id, (u32)d_021D77AC, 0);
        break;
    case 6:
        PROCSYS_ReplaceGlobal((int)ov168_id, (u32)d_02184904, 0);
        break;
    case 7:
        procArgs = GFL_HEAP_Alloc(1, 8, 1, d_021BDA00, 0x216);
        ((StartMenuOv107Args *)procArgs)->fromTitleMenu = 1;
        PROCSYS_ReplaceGlobal((int)ov107_id, (u32)d_021F6D78, (u32)procArgs);
        break;
    default:
        PROCSYS_ReplaceGlobal((int)ov088_id, (u32)d_021BD574, 0);
        break;
    }
    return 1;
}









int STARTMENU_StateSetup(StartMenuWork *work)
{
    unsigned short z;
    if (func_020092EC((const struct Sub02009210Obj *)GAME_SYNC_GetBlock((void *)work->saveData)) == 1)
        BEACON_SetSlotState((struct Blk34 *)work->unlockData, 2, 2);
    z = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(unsigned short *)0x04000050 = z;
    *(unsigned short *)0x04001050 = z;
    BMP_SetDisplaySwap(1);
    STARTMENU_ClearGraphics();
    STARTMENU_SetupBackgrounds();
    STARTMENU_LoadGraphics();
    STARTMENU_CreateTextSystem(work);
    STARTMENU_BuildRowList(work);
    STARTMENU_LoadRowBuffers(work);
    STARTMENU_CreateRowWindows(work);
    STARTMENU_CreateActors(work);
    STARTMENU_CreateFrameManager(work);
    STARTMENU_LayoutRows(work);
    STARTMENU_CreateBlinkPalette(work);
    STARTMENU_StartBrightnessEffect();
    STARTMENU_AddVblankTask(work);
    return 4;
}









int STARTMENU_StateWaitStart(StartMenuWork *work)
{
    unsigned s;
    s = work->subState;
    switch (s) {
    case 0:
        work->subState = s + 1;
    case 1:
        if (GFL_NET_IsIdle() != 0) {
            STARTMENU_RemoveVblankTask(work);
            STARTMENU_DeleteBlinkPalette(work);
            STARTMENU_DeleteFrameManager(work);
            STARTMENU_DeleteActors(work);
            STARTMENU_DeleteRowWindows(work);
            STARTMENU_FreeRowBuffers(work);
            STARTMENU_DeleteTextSystem(work);
            STARTMENU_TeardownBackgrounds();
            *(unsigned short *)0x04000050 = 0;
            *(unsigned short *)0x04001050 = 0;
            BG_SYS_SetMainVisiblePlanes(0);
            BG_SYS_SetSubVisiblePlanes(0);
            return 12;
        }
    }
    return 1;
}









int STARTMENU_StateWaitFade(StartMenuWork *work)
{
    if (WIPE_SYS_EndCheck() == 1) {
        return work->nextStateAfterFade;
    }
    return 2;
}









int STARTMENU_StateSelectAnim(StartMenuWork *work)
{
    switch (work->selectAnimPhase) {
    case 0:
    case 2:
        if (work->selectAnimTimer == 0) {
            STARTMENU_PaintRowPalette(work, work->rowIds[work->cursorIndex],
                          STARTMENU_RowTileY(work, work->cursorTileY), 3);
            work->selectAnimTimer = 4;
            work->selectAnimPhase = work->selectAnimPhase + 1;
        } else {
            work->selectAnimTimer -= 1;
        }
        break;
    case 1:
    case 3:
        if (work->selectAnimTimer == 0) {
            STARTMENU_PaintRowPalette(work, work->rowIds[work->cursorIndex],
                          STARTMENU_RowTileY(work, work->cursorTileY), 1);
            work->selectAnimTimer = 4;
            work->selectAnimPhase = work->selectAnimPhase + 1;
        } else {
            work->selectAnimTimer -= 1;
        }
        break;
    case 4:
        return work->nextStateAfterAnim;
    }
    return 3;
}









/*
 * note:     listing extent (112) runs 2 bytes past the compiled function (110);
 *           trailing alignment padding, no byte difference.
 */
int STARTMENU_StateWaitPrint(StartMenuWork *work)
{
    unsigned i;
    void *t;
    PRINTSYS_QUE_Main(work->printSys);
    for (i = 0; i < 14; i++) {
        t = work->printSys;
        if (work->windows[i].textPending != 0 && PRINTSYS_QUE_IsExistTarget(t, BMP_WIN_GetBmp(work->windows[i].window)) == 0) {
            BMP_WIN_TransferChars(work->windows[i].window);
            work->windows[i].textPending = 0;
        }
    }
    if (PRINTSYS_QUE_IsFinished(work->printSys) == 1) {
        if (STARTMENU_RefreshSaveStatus(work) == 1)
            return 10;
        return STARTMENU_BeginFadeOut(work, 5);
    }
    return 4;
}









int STARTMENU_StateSelectRow(StartMenuWork *work)
{
    BLINK_PALANM_Update(work->blinkPalAnm);
    if (KEY_GetTrg() & 1) {
        GFL_USE_PlaySeDefaultVolume(0x54c);
        switch (work->rowIds[work->cursorIndex]) {
        case 0:
            work->selectedRow = work->rowIds[work->cursorIndex];
            return STARTMENU_BeginSelectAnim(work, 7);
        case 1:
            return STARTMENU_BeginSelectAnim(work, 8);
        case 2:
            work->selectedRow = work->rowIds[work->cursorIndex];
            return STARTMENU_BeginSelectAnim(work, 11);
        case 3:
            BEACON_SetSlotState((struct Blk34 *)(work->unlockData), 1, 2);
            work->selectedRow = work->rowIds[work->cursorIndex];
            return STARTMENU_BeginSelectAnim(work, 11);
        case 4:
            BEACON_SetSlotState((struct Blk34 *)(work->unlockData), 2, 2);
            work->selectedRow = work->rowIds[work->cursorIndex];
            return STARTMENU_BeginSelectAnim(work, 11);
        case 7:
            BEACON_SetSlotState((struct Blk34 *)(work->unlockData), 3, 2);
            work->selectedRow = work->rowIds[work->cursorIndex];
            return STARTMENU_BeginSelectAnim(work, 11);
        case 5:
            return STARTMENU_BeginSelectAnim(work, 9);
        case 6:
            work->selectedRow = work->rowIds[work->cursorIndex];
            return STARTMENU_BeginSelectAnim(work, 11);
        }
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        work->selectedRow = 8;
        return STARTMENU_BeginFadeIn(work, 1);
    }
    if (KEY_GetRepeat() & 0x40) {
        if (STARTMENU_MoveCursor(work, -1) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 6;
        }
    }
    if (KEY_GetRepeat() & 0x80) {
        if (STARTMENU_MoveCursor(work, 1) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 6;
        }
    }
    return 5;
}









int STARTMENU_StateScroll(StartMenuWork *work)
{
    if (work->scrollStep == 3) {
        work->scrollStep = 0;
        work->scrollSpeed = 0;
        BLINK_PALANM_ResetPhase((struct CodeIn *)(work->blinkPalAnm));
        STARTMENU_PaintRowPalette(work, work->rowIds[work->cursorIndex],
                      STARTMENU_RowTileY(work, work->cursorTileY), 2);
        return 5;
    }
    work->scrollPixels += work->scrollSpeed;
    if (work->scrollPixels < 0)
        work->scrollPixels += 0x200;
    else if (work->scrollPixels >= 0x200)
        work->scrollPixels -= 0x200;
    BG_SYS_ResetSlot(1, 3, work->scrollPixels);
    BG_SYS_ResetSlot(2, 3, work->scrollPixels);
    STARTMENU_ScrollRowActors(work, -work->scrollSpeed);
    work->scrollStep = work->scrollStep + 1;
    return 6;
}









/*
 * The two 0/-2 result tests are small switches: their compare chain puts
 * both bodies after a shared `b` to the tail, which the outer switch's
 * out-of-range `bhi` reuses. The countdown is `-= 1` (re-reads the byte).
 */
int STARTMENU_StateConnectPrompt(StartMenuWork *work)
{
    void *printSys;
    u32 menuResult;
    switch (work->subState) {
    case 0:
        BG_SYS_SetMainPlaneVisible(6, 0);
        STARTMENU_ShowRowActors(work, 0);
        if (func_020090E0(work->connectData) == 0) {
            work->connectResult = 1;
            work->subState = 0;
            return STARTMENU_BeginFadeIn(work, 1);
        }
        work->delay = 8;
        work->subState = work->subState + 1;
        break;
    case 1:
        if (work->delay != 0) {
            work->delay -= 1;
            break;
        }
        STARTMENU_StartMessage(work, 0x1a);
        STARTMENU_OpenInfoWindow(work);
        work->subState = work->subState + 1;
        break;
    case 2:
        if (STARTMENU_UpdateMessage(work) == 0) {
            STARTMENU_OpenYesNoMenu(work);
            work->subState = work->subState + 1;
        }
        break;
    case 3:
        menuResult = BMP_MENU_ProcessYesNo(work->yesNoMenu);
        switch (menuResult) {
        case 0:
            if (APP_ENV_InitParentalControl() == 0) {
                STARTMENU_StartMessage(work, 0x11);
                work->subState = 5;
            } else {
                work->connectResult = 0;
                work->subState = 4;
            }
            break;
        case (u32)-2:
            STARTMENU_StartMessage(work, 0x1b);
            work->subState = 7;
            break;
        }
        break;
    case 4:
        STARTMENU_CloseInfoWindow(work);
        STARTMENU_HideMessageWindow(work);
        work->subState = 0;
        return STARTMENU_BeginFadeIn(work, 1);
    case 5:
        if (STARTMENU_UpdateMessage(work) == 0)
            work->subState = work->subState + 1;
        break;
    case 6:
        if (KEY_GetTrg() & 3) {
            work->connectResult = 1;
            work->subState = 4;
        }
        break;
    case 7:
        if (STARTMENU_UpdateMessage(work) == 0) {
            STARTMENU_OpenYesNoMenu(work);
            work->subState = work->subState + 1;
        }
        break;
    case 8:
        menuResult = BMP_MENU_ProcessYesNo(work->yesNoMenu);
        switch (menuResult) {
        case 0:
            work->connectResult = 1;
            work->subState = 4;
            break;
        case (u32)-2:
            STARTMENU_StartMessage(work, 0x1a);
            work->subState = 2;
            break;
        }
        break;
    }
    PRINTSYS_QUE_Main(work->printSys);
    printSys = work->printSys;
    if (work->descWindowOpen != 0 && PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->descWindow)) == 0) {
        BMP_WIN_TransferChars(work->descWindow);
        work->descWindowOpen = 0;
    }
    return 7;
}









int STARTMENU_StateConfirmPrompt(StartMenuWork *work)
{
    void *printSys;
    switch (work->subState) {
    case 0:
        if (work->rowIds[0] == 1) {
            work->selectedRow = 1;
            work->subState = 0;
            return STARTMENU_BeginFadeIn(work, 1);
        }
        STARTMENU_OpenConfirmWindow(work);
        work->subState = work->subState + 1;
        break;
    case 1:
        if (PRINTSYS_QUE_IsFinished(work->printSys) == 1)
            work->subState = work->subState + 1;
        break;
    case 2:
        if (KEY_GetTrg() & 1) {
            GFL_USE_PlaySeDefaultVolume(0x54c);
            STARTMENU_CloseDescWindow(work, 1);
            work->selectedRow = 1;
            work->subState = 0;
            return STARTMENU_BeginFadeIn(work, 1);
        }
        if (KEY_GetTrg() & 2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            STARTMENU_CloseDescWindow(work, 0);
            STARTMENU_PaintRowPalette(work, work->rowIds[work->cursorIndex],
                          STARTMENU_RowTileY(work, work->cursorTileY), 2);
            work->subState = 0;
            return 5;
        }
        break;
    }
    PRINTSYS_QUE_Main(work->printSys);
    printSys = work->printSys;
    if (work->descWindowOpen != 0 && PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->descWindow)) == 0) {
        BMP_WIN_TransferChars(work->descWindow);
        work->descWindowOpen = 0;
    }
    return 8;
}









int STARTMENU_StateInfoMessage(StartMenuWork *work)
{
    void *printSys;
    if (APP_ENV_IsRunOnTwl() == 1) {
        switch (work->subState) {
        case 0:
            STARTMENU_OpenNoticeWindow(work);
            work->subState = work->subState + 1;
            break;
        case 1:
            if (PRINTSYS_QUE_IsFinished(work->printSys) == 1)
                work->subState = work->subState + 1;
            break;
        case 2:
            if (KEY_GetTrg() & 3) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                STARTMENU_CloseDescWindow(work, 0);
                STARTMENU_PaintRowPalette(work, work->rowIds[work->cursorIndex],
                              STARTMENU_RowTileY(work, work->cursorTileY), 2);
                work->subState = 0;
                return 5;
            }
            break;
        }
        PRINTSYS_QUE_Main(work->printSys);
        printSys = work->printSys;
        if (work->descWindowOpen != 0 && PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->descWindow)) == 0) {
            BMP_WIN_TransferChars(work->descWindow);
            work->descWindowOpen = 0;
        }
        return 9;
    }
    work->selectedRow = work->rowIds[work->cursorIndex];
    return 11;
}









/*
 * 0x021BA984 is an unlabelled tail-call stub (function_starts seed);
 * verified with tu over 0x021BA880..0x021BA990 (272 bytes).
 */
int STARTMENU_StateUnlockNotices(StartMenuWork *work)
{
    u32 i;
    switch (work->subState) {
    case 0:
        BG_SYS_SetMainPlaneVisible(0x1e, 0);
        BG_SYS_SetSubPlaneVisible(0x17, 0);
        BG_SYS_LoadPlttEntry(0, 0x7d8c);
        BG_SYS_LoadPlttEntry(4, 0x7d8c);
        work->subState = work->subState + 1;
        return STARTMENU_BeginFadeOut(work, 10);
    case 1:
        for (;;) {
            i = work->noticeIndex;
            if (i >= 8) {
                STARTMENU_HideMessageWindow(work);
                work->subState = 3;
                return STARTMENU_BeginFadeIn(work, 10);
            }
            if ((gStartMenuUnlockNotices[i].flagMask & work->saveStatus) == 0) {
                work->noticeIndex += 1;
                continue;
            }
            STARTMENU_StartMessage(work, gStartMenuUnlockNotices[i].msgId);
            work->noticeIndex += 1;
            work->subState = work->subState + 1;
            break;
        }
        break;
    case 2:
        if (STARTMENU_UpdateMessage(work) == 0 && (KEY_GetTrg() & 3)) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            work->subState = 1;
        }
        break;
    case 3:
        BG_SYS_SetMainPlaneVisible(0x1e, 1);
        BG_SYS_SetSubPlaneVisible(0x17, 1);
        work->subState = 0;
        return STARTMENU_BeginFadeOut(work, 5);
    }
    return 10;
}









int STARTMENU_StateBeginFadeIn(StartMenuWork *work)
{
    return STARTMENU_BeginFadeIn(work, 1);
}









/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile OsIrqWord *)((OsIrqWord)SDK_AUTOLOAD_DTCM_START + 0x3FF8))









void STARTMENU_VblankTask(void)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    OSi_IRQ_CHECK_FLAG |= 1;
}









void STARTMENU_AddVblankTask(StartMenuWork *work)
{
    work->vblankTask = (int)GFL_USE_AddMainTask((void *)STARTMENU_VblankTask, work, 0);
}









void STARTMENU_RemoveVblankTask(StartMenuWork *work)
{
    TCB_DeleteTask((struct Node *)work->vblankTask);
}








void STARTMENU_ClearGraphics(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BD60C);
}








void STARTMENU_SetupBackgrounds(void)
{
    DispConfigBlock dispConfig;
    BgTemplateBlock bg0Template;
    BgTemplateBlock bg1Template;
    BgTemplateBlock bg2Template;
    BgTemplateBlock bg3Template;
    BgTemplateBlock bg4Template;
    BgTemplateBlock bg5Template;
    BgTemplateBlock bg6Template;

    BG_SYS_Create(0xb);
    dispConfig = d_021BD678;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&dispConfig));
    bg0Template = d_021BD724;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&bg0Template), 0);
    bg1Template = d_021BD764;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&bg1Template), 0);
    bg2Template = d_021BD6C4;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&bg2Template), 0);
    bg3Template = d_021BD6E4;
    BG_SYS_InitBgLayer(3, (const struct BgTemplate *)(&bg3Template), 0);
    bg4Template = d_021BD744;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&bg4Template), 0);
    bg5Template = d_021BD6A4;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&bg5Template), 0);
    bg6Template = d_021BD704;
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)(&bg6Template), 0);
    BG_SYS_SetMainPlaneVisible(0xf, 1);
    BG_SYS_SetSubPlaneVisible(7, 1);
}








/*
 * EXACT*: inferred extent runs two bytes long; the follower at 0x021BAB62 is
 * an unlabelled leaf (no lr save) that disasm.py did not label.
 */
void STARTMENU_TeardownBackgrounds(void)
{
    BG_SYS_SetMainPlaneVisible(0xf, 0);
    BG_SYS_SetSubPlaneVisible(7, 0);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}








void STARTMENU_LoadGraphics(void)
{
    void *archive;
    archive = ARC_TOOL_CreateHandle(0x23, 0x800B);
    func_02049B68(archive, 4, 0, 0, 0xc0, 0xb);
    ARC_UTIL_UploadBgCharFromHandle(archive, 3, 2, 0, 0, 1, 0xb);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 2, 3, 0, 0, 1, 0xb);
    func_02049B68(archive, 5, 4, 0, 0xc0, 0xb);
    ARC_UTIL_UploadBgCharFromHandle(archive, 1, 5, 0, 0, 1, 0xb);
    ARC_UTIL_UploadBgPaletteFromHandle(archive, 0, 6, 0, 0, 1, 0xb);
    ARC_TOOL_DeleteHandle(archive);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, 0xb);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x1e0, 0x20, 0xb);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1e0, 0x20, 0xb);
}








void STARTMENU_CreateBlinkPalette(StartMenuWork *work)
{
    void *archive;
    archive = ARC_TOOL_CreateHandle(0x23, 0x800B);
    work->blinkPalAnm = (void *)BLINK_PALANM_Create(0x20, 0x10, 2, 0xb);
    BLINK_PALANM_LoadPalettes((struct CodeIn *)(work->blinkPalAnm), archive, 4, 0x20, 0x30);
    ARC_TOOL_DeleteHandle(archive);
}








void STARTMENU_DeleteBlinkPalette(StartMenuWork *work)
{
    BLINK_PALANM_Delete((struct PalAnmSlot *)(work->blinkPalAnm));
}








void STARTMENU_CreateTextSystem(StartMenuWork *work)
{
    work->msgBank = (void *)MSGDATA_CreateFromArchive(0, 2, 0xb3, 0xb);
    work->font = (u32)GF_FONT_Create(0x17, 0, 0, 0, 0xb);
    work->wordSet = (void *)WORDSET_CreateDefault(0xb);
    work->printSys = (void *)PRINTSYS_QUE_Create((void *)0xb);
    work->stringBuf = (void *)STRBUF_Create(0x400, 0xb);
    work->taskList = (u32)TCBL_Create(0xb, 0xb, 1, 4);
    work->msgBoxFrame = (void *)APP_KEYCURSOR_CreateDefault(0xf, 1, 0, 0xb);
}








void STARTMENU_DeleteTextSystem(StartMenuWork *work)
{
    APP_KEYCURSOR_Delete((int)work->msgBoxFrame);
    TCBL_Destroy((struct S02031140 *)work->taskList);
    STRBUF_Delete((struct U16Vec *)work->stringBuf);
    PRINTSYS_QUE_Delete((struct PrintSys *)work->printSys);
    WORDSET_DeleteStrbufED04((struct WordSet *)work->wordSet);
    GF_FONT_Delete((void *)work->font);
    MSGDATA_Delete((struct Rec *)work->msgBank);
}








void STARTMENU_CreateRowWindows(StartMenuWork *work)
{
    u32 i;
    void *msgStr;
    void *zoneName;
    void *playerInfo;
    void *printSys;
    u16 locationBuf[14];

    BMP_WIN_Init(11);
    for (i = 0; i < 14; i++) {
        work->windows[i].window = (void *)BMP_WIN_Create(gStartMenuWindowTemplates[i].bgId, gStartMenuWindowTemplates[i].x, gStartMenuWindowTemplates[i].y,
                                       gStartMenuWindowTemplates[i].width, gStartMenuWindowTemplates[i].height, gStartMenuWindowTemplates[i].palette, 1);
    }

    msgStr = MSGDATA_AllocString(work->msgBank, 0);
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[0].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    work->windows[0].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 12);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->playerData);
    WORDSET_CopyTaggedText(work->wordSet, work->stringBuf, msgStr);
    if (func_02008550(work->playerData) == 0) {
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[1].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0xC80);
        work->windows[1].textPending = 1;
    } else {
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[1].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x14C0);
        work->windows[1].textPending = 1;
    }
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 16);
    ZONEDATA_Init(0x800B);
    if (ZONEDATA_CheckEventFlag(work->eventWork, 0x966) == 1) {
        zoneName = (void *)ZONEDATA_GetPlaceNameId(func_02008848(func_02008854(work->saveData))[2]);
    } else {
        func_0200890C(work->saveData, (struct Sub02008828Rec *)locationBuf);
        zoneName = (void *)ZONEDATA_GetPlaceNameId(locationBuf[0]);
    }
    ZONEDATA_Exit();
    WORDSET_SetSlotFromMsg59(work->wordSet, 0, (u32)zoneName);
    WORDSET_CopyTaggedText(work->wordSet, work->stringBuf, msgStr);
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[2].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
    work->windows[2].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 9);
    playerInfo = func_02008748(work->saveData);
    WORDSET_SetSlotNumber(work->wordSet, 0, func_0200864C(playerInfo), 3, 0, 1);
    WORDSET_SetSlotNumber(work->wordSet, 1, func_02008650(playerInfo), 2, 2, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->stringBuf, msgStr);
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[3].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
    work->windows[3].textPending = 1;
    STRBUF_Delete(msgStr);

    if (ZONEDATA_CheckEventFlag(work->eventWork, 0x962) == 1) {
        msgStr = MSGDATA_AllocString(work->msgBank, 10);
        WORDSET_SetSlotNumber(work->wordSet, 0, ZUKAN_SAVE_CountSeen(ZUKAN_SAVE_GetBlock(work->saveData), 11), 3, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->stringBuf, msgStr);
        printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[4].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
        work->windows[4].textPending = 1;
        STRBUF_Delete(msgStr);
    }

    msgStr = MSGDATA_AllocString(work->msgBank, 11);
    WORDSET_SetSlotNumber(work->wordSet, 0, BEACON_CountFlags(BEACON_GetBlock(work->saveData)), 2, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->stringBuf, msgStr);
    printSys = work->printSys;
    PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[5].window), 0, 0, (u32)work->stringBuf, (u32)work->font, 0x440);
    work->windows[5].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 1);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[6].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[6].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 2);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[7].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[7].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 4);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[8].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[8].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 5);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[9].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[9].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 3);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[10].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[10].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 7);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[11].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[11].textPending = 1;
    STRBUF_Delete(msgStr);

    msgStr = MSGDATA_AllocString(work->msgBank, 6);
    {
        void *printSys = work->printSys;
        PRINTSYS_PrintQueColor(printSys, (u32)BMP_WIN_GetBmp(work->windows[12].window), 0, 4, (u32)msgStr, (u32)work->font, 0x440);
    }
    work->windows[12].textPending = 1;
    STRBUF_Delete(msgStr);
}








/*
 * Releases the fourteen 8-byte-stride handles at +0x80 created by
 * STARTMENU_CreateRowWindows, then the shared resource.
 */
void STARTMENU_DeleteRowWindows(StartMenuWork *work)
{
    unsigned i;
    for (i = 0; i < 14; i++)
        BMP_WIN_Delete(work->windows[i].window);
    BMP_WIN_Exit();
}







void STARTMENU_CreateActors(StartMenuWork *work)
{
    ClactResConfig resConfig;
    void *archive;
    u32 i;

    resConfig = d_021BD688;
    CLACT_InitSystem((const struct Cfg *)(&resConfig), (u32)d_021BD60C, 0xb);
    archive = ARC_TOOL_CreateHandle(0x1f, 0x800b);
    if (func_02008550((const struct MyStatus *)work->playerData) == 0) {
        work->actorCharRes[0] = CLACT_RegisterCharacter(archive, 5, 0, 0, 0xb);
        work->actorPaletteRes[0] = CLACT_RegisterPalette(archive, 4, 0, 0, 0xb);
        work->actorCellRes[0] = CLACT_RegisterCellAnim(archive, 0, 1, 0xb);
    } else {
        work->actorCharRes[0] = CLACT_RegisterCharacter(archive, 7, 0, 0, 0xb);
        work->actorPaletteRes[0] = CLACT_RegisterPalette(archive, 6, 0, 0, 0xb);
        work->actorCellRes[0] = CLACT_RegisterCellAnim(archive, 2, 3, 0xb);
    }
    ARC_TOOL_DeleteHandle(archive);
    archive = ARC_TOOL_CreateHandle(0x23, 0x800b);
    work->actorCharRes[1] = CLACT_RegisterCharacter(archive, 8, 1, 0, 0xb);
    work->actorPaletteRes[1] = CLACT_RegisterPalette(archive, 9, 0, 0x20, 0xb);
    work->actorCellRes[1] = CLACT_RegisterCellAnim(archive, 0xa, 0xb, 0xb);
    work->actorCharRes[2] = CLACT_RegisterCharacter(archive, 0xc, 1, 0, 0xb);
    work->actorPaletteRes[2] = CLACT_RegisterPalette(archive, 0xd, 0, 0x40, 0xb);
    work->actorCellRes[2] = CLACT_RegisterCellAnim(archive, 0xe, 0xf, 0xb);
    ARC_TOOL_DeleteHandle(archive);
    work->clactUnit = (void *)CLACT_CreateUnit(6, 0, 0xb);
    work->rowActors[0] = (void *)CLACT_CreateActor((int)((void *)work->clactUnit), work->actorCharRes[0], work->actorPaletteRes[0], work->actorCellRes[0], (ClactInitData *)d_021BD5DC, 0, 0xb);
    CLACT_SetActorDrawEnable((void *)work->rowActors[0], 0);
    for (i = 1; i <= 4; i++) {
        work->rowActors[i] = (void *)CLACT_CreateActor((int)((void *)work->clactUnit), work->actorCharRes[1], work->actorPaletteRes[1], work->actorCellRes[1], (ClactInitData *)d_021BD5E4, 0, 0xb);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->rowActors[i], 1);
        CLACT_SetActorDrawEnable((void *)work->rowActors[i], 0);
    }
    work->rowActors[5] = (void *)CLACT_CreateActor((int)((void *)work->clactUnit), work->actorCharRes[2], work->actorPaletteRes[2], work->actorCellRes[2], (ClactInitData *)d_021BD5D4, 0, 0xb);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}







void STARTMENU_DeleteActors(StartMenuWork *work)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        CLACT_DeleteActor(work->rowActors[i]);
    CLACT_DeleteUnit(work->clactUnit);
    for (i = 0; i < 3; i++)
        CLACT_ReleaseCharacter((u32)(work->actorCharRes[i]));
    for (i = 0; i < 3; i++)
        CLACT_ReleasePalette((u32)(work->actorPaletteRes[i]));
    for (i = 0; i < 3; i++)
        CLACT_ReleaseCellAnim((u32)(work->actorCellRes[i]));
    CLACT_ExitSystem();
}







/*
 * Builds an 8-window bgwinfrm manager at +0x118, initialises each window
 * from a 4-byte table (height from its halfword at +2), then binds the
 * thirteen resources at +0x80..+0xe0 (stride 8) to windows 0,0,0,0,0,0,1..7.
 */
void STARTMENU_CreateFrameManager(StartMenuWork *work)
{
    u32 i;

    work->frameManager = BGWINFRM_Create(0, 8, 0xb);
    for (i = 0; i < 8; i++)
        BGWINFRM_AddFrame(work->frameManager, i, 1, 0x1a, gStartMenuRowInfo[i].height);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[0].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[1].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[2].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[3].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[4].window);
    BGWINFRM_PutBmpWin(work->frameManager, 0, work->windows[5].window);
    BGWINFRM_PutBmpWin(work->frameManager, 1, work->windows[6].window);
    BGWINFRM_PutBmpWin(work->frameManager, 2, work->windows[7].window);
    BGWINFRM_PutBmpWin(work->frameManager, 3, work->windows[8].window);
    BGWINFRM_PutBmpWin(work->frameManager, 4, work->windows[9].window);
    BGWINFRM_PutBmpWin(work->frameManager, 5, work->windows[10].window);
    BGWINFRM_PutBmpWin(work->frameManager, 6, work->windows[11].window);
    BGWINFRM_PutBmpWin(work->frameManager, 7, work->windows[12].window);
}







/*
 * Tail-calls the release of the handle kept at +0x118.
 */
void STARTMENU_DeleteFrameManager(StartMenuWork *work)
{
    BGWINFRM_Delete(work->frameManager);
}







void STARTMENU_StartBrightnessEffect(void)
{
    G2x_SetBlendAlpha_((void *)0x04000050, 4, 8, 16, 3);
    G2x_SetBlendAlpha_((void *)0x04001050, 2, 4, 16, 3);
}





void STARTMENU_BuildRowList(StartMenuWork *work)
{
    unsigned i = 0;
    if (func_020071EC(work->saveData) == 1) {
        work->rowIds[0] = 0;
        i++;
    }
    work->rowIds[i] = 1;
    (&work->rowIds[1])[i] = 2;
    i += 2;
    if (BEACON_GetSlotState(work->unlockData, 1)) {
        work->rowIds[i] = 3;
        i++;
    }
    if (BEACON_GetSlotState(work->unlockData, 2)) {
        work->rowIds[i] = 4;
        i++;
    }
    work->rowIds[i] = 5;
    (&work->rowIds[1])[i] = 6;
    i += 2;
    if (BEACON_GetSlotState(work->unlockData, 3)) {
        work->rowIds[i] = 7;
        i++;
    }
    while (i < 8) {
        work->rowIds[i] = 8;
        i++;
    }
}





void STARTMENU_LoadRowBuffers(StartMenuWork *work)
{
    void *archive = ARC_TOOL_CreateHandle(0x23, 0x800B);
    u32 i;
    for (i = 0; i < 8; i++) {
        u32 rowBytes = gStartMenuRowInfo[i].height * 0x34;
        void *fileData;
        void *fileHandle;
        work->rowBuffers[i] = (void *)GFL_HEAP_Alloc(0xb, rowBytes, 0, d_021BDA00, 0x7e9);
        fileHandle = func_02049EF4(archive, gStartMenuRowInfo[i].frameId, 1, &fileData, 0xb);
        MIi_CpuCopy16((char *)fileData + 0xc, work->rowBuffers[i], rowBytes);
        GFL_HEAP_Free(fileHandle);
    }
    ARC_TOOL_DeleteHandle(archive);
}






/*
 * Frees the eight row buffers at +0xF8 allocated by STARTMENU_LoadRowBuffers.
 */
void STARTMENU_FreeRowBuffers(StartMenuWork *work)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        GFL_HEAP_Free(work->rowBuffers[i]);
}






void STARTMENU_SetRowActorY(StartMenuWork *work, u32 actorIndex, s16 y)
{
    SpritePos position;
    CLACT_GetActorSurfacePos(work->rowActors[actorIndex], (struct PtS *)&position, 0);
    position.y = y;
    CLACT_AddActorSurfacePos(work->rowActors[actorIndex], (const struct Vec2 *)(&position), 0);
}






/*
 * Lays out the up-to-eight menu rows listed at +0x120 (8 terminates),
 * stacking them by the heights in gStartMenuRowInfo and positioning the row
 * sprites.  Row order is filled in by ov088_func_021BB4B4.c.
 */
void STARTMENU_LayoutRows(StartMenuWork *work)
{
    u32 i;
    s8 tileY;
    u8 rowId;
    void *rowActor;

    i = 0;
    work->cursorIndex = 0;
    work->scrollPixels = 0;
    tileY = 2;
    work->cursorTileY = 2;
    for (i = 0; i < 8; i++) {
        if ((u8)work->rowIds[i] == 8)
            break;
        STARTMENU_DrawRowFrame(work, (u8)work->rowIds[i], tileY);
        rowId = work->rowIds[i];
        if (rowId == 0) {
            rowActor = work->rowActors[0];
        } else if (rowId == 5) {
            STARTMENU_SetRowActorY(work, 5, tileY * 8 + gStartMenuRowInfo[rowId].height * 8 / 2);
            rowActor = work->rowActors[5];
        } else if (rowId == 3) {
            if (BEACON_GetSlotState(work->unlockData, 1) != 1)
                goto next;
            STARTMENU_SetRowActorY(work, 2, tileY * 8 + gStartMenuRowInfo[(u8)work->rowIds[i]].height * 8 / 2);
            rowActor = work->rowActors[2];
        } else if (rowId == 4) {
            if (BEACON_GetSlotState(work->unlockData, 2) != 1)
                goto next;
            STARTMENU_SetRowActorY(work, 3, tileY * 8 + gStartMenuRowInfo[(u8)work->rowIds[i]].height * 8 / 2);
            rowActor = work->rowActors[3];
        } else if (rowId == 7) {
            if (BEACON_GetSlotState(work->unlockData, 3) != 1)
                goto next;
            STARTMENU_SetRowActorY(work, 4, tileY * 8 + gStartMenuRowInfo[(u8)work->rowIds[i]].height * 8 / 2);
            rowActor = work->rowActors[4];
        } else {
            goto next;
        }
        CLACT_SetActorDrawEnable(rowActor, 1);
    next:
        tileY += (s8)gStartMenuRowInfo[(u8)work->rowIds[i]].height;
    }
    STARTMENU_SetRowActorY(work, 0, 0x40);
    STARTMENU_PaintRowPalette(work, (u8)work->rowIds[0], (s8)work->cursorTileY, 2);
}






void STARTMENU_DrawRowFrame(StartMenuWork *work, u32 rowId, u32 tileY)
{
    u8 tileYByte = tileY;
    u16 rowHeight = gStartMenuRowInfo[rowId].height;
    u32 frameBuffer;
    BG_SYS_DrawTileEx(2, 3, tileYByte, 0x1a, rowHeight, (u32)(work->rowBuffers[rowId]), 0, 0, 0x1a, rowHeight);
    frameBuffer = BGWINFRM_GetFrameBuffer(work->frameManager, rowId);
    BG_SYS_DrawTileEx(1, 3, tileYByte, 0x1a, rowHeight, (u32)((void *)frameBuffer), 0, 0, 0x1a, rowHeight);
    BG_SYS_SetFlagField06(1);
    BG_SYS_SetFlagField06(2);
}






/*
 * Redraws menu row `row` (height from the row table gStartMenuRowInfo) at tile
 * row y on bg layer 2 with palette pal, then commits the layer.
 */
void STARTMENU_PaintRowPalette(StartMenuWork *work, u8 row, int tileY, int palette)
{
    BG_SYS_FillTileMap(2, 3, tileY, 0x1a, gStartMenuRowInfo[row].height, palette);
    BG_SYS_SetFlagField06(2);
}






int STARTMENU_RowTileY(StartMenuWork *work, int y)
{
    return (s8)(y + work->scrollPixels / 8);
}





/*
 * Shifts the six sprites at +0x1c..+0x30 vertically by d.
 */
void STARTMENU_ScrollRowActors(StartMenuWork *work, int deltaY)
{
    u32 i;
    SpritePos position;
    for (i = 0; i < 6; i++) {
        CLACT_GetActorSurfacePos((struct Actor *)work->rowActors[i], (struct PtS *)&position, 0);
        position.y += (s16)deltaY;
        CLACT_AddActorSurfacePos((struct ClactActor *)(work->rowActors[i]), (const struct Vec2 *)(&position), 0);
    }
}






int STARTMENU_MoveCursor(StartMenuWork *work, int d)
{
    u8 oldRowId;
    u16 rowHeight;
    s8 newTileY;
    u8 newRowId;
    s8 newIndex;
    u8 oldIndex;

    oldIndex = work->cursorIndex;
    oldRowId = work->rowIds[oldIndex];
    work->scrollStep = 0;
    if (d < 0) {
        if (oldIndex == 0)
            return 0;
        newIndex = oldIndex + d;
        rowHeight = gStartMenuRowInfo[(u8)work->rowIds[newIndex]].height;
        newTileY = (s8)work->cursorTileY - rowHeight;
        STARTMENU_PaintRowPalette(work, oldRowId, STARTMENU_RowTileY(work, (s8)work->cursorTileY), 1);
        if ((u8)work->rowIds[0] == 0) {
            if (newTileY < 2) {
                if (newIndex == 0) {
                    work->scrollSpeed = -(((rowHeight - ((s8)work->cursorTileY - 2)) / 3) * 8);
                    work->cursorTileY = 2;
                } else {
                    work->scrollSpeed = -((rowHeight / 3) * 8);
                }
            } else {
                work->cursorTileY = newTileY;
            }
        } else {
            work->cursorTileY = newTileY;
        }
    } else {
        if (oldIndex + d >= 8)
            return 0;
        if ((u8)work->rowIds[(oldIndex + d)] == 8)
            return 0;
        newRowId = work->rowIds[(s8)(oldIndex + d)];
        newTileY = (s8)work->cursorTileY + gStartMenuRowInfo[oldRowId].height;
        STARTMENU_PaintRowPalette(work, oldRowId, STARTMENU_RowTileY(work, (s8)work->cursorTileY), 1);
        if ((u8)work->rowIds[0] == 0) {
            if (newTileY == 0x18) {
                work->scrollSpeed = (gStartMenuRowInfo[newRowId].height / 3) * 8;
            } else if (newTileY + gStartMenuRowInfo[newRowId].height > 0x18) {
                work->scrollSpeed = (gStartMenuRowInfo[newRowId].height / 3) * 8;
            } else {
                work->cursorTileY = newTileY;
            }
        } else {
            work->cursorTileY = newTileY;
        }
    }
    work->cursorIndex += (u8)d;
    return 1;
}





void STARTMENU_ShowRowActors(StartMenuWork *work, int flag)
{
    unsigned i;
    if (flag == 0) {
        for (i = 0; i <= 5; i++)
            CLACT_SetActorDrawEnable(work->rowActors[i], flag);
        return;
    }
    CLACT_SetActorDrawEnable(work->rowActors[0], 1);
    for (i = 0; i < 8; i++) {
        u8 rowId = work->rowIds[i];
        if (rowId == 8)
            return;
        if (rowId == 3) {
            if (BEACON_GetSlotState(work->unlockData, 1) == 1)
                CLACT_SetActorDrawEnable(work->rowActors[2], 1);
        } else if (rowId == 4) {
            if (BEACON_GetSlotState(work->unlockData, 2) == 1)
                CLACT_SetActorDrawEnable(work->rowActors[3], 1);
        } else if (rowId == 7) {
            if (BEACON_GetSlotState(work->unlockData, 3) == 1)
                CLACT_SetActorDrawEnable(work->rowActors[4], 1);
        } else if (rowId == 5) {
            CLACT_SetActorDrawEnable(work->rowActors[5], 1);
        }
    }
}





void STARTMENU_DrawFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bgLayer)
{
    u32 layer = *(u32 *)&bgLayer;

    BG_SYS_SetTileEntry(layer, 1, x, y, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 3, x + w - 1, y, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 7, x, y + h - 1, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 9, x + w - 1, y + h - 1, 1, 1, 1);
    BG_SYS_SetTileEntry(layer, 2, x + 1, y, w - 2, 1, 1);
    BG_SYS_SetTileEntry(layer, 8, x + 1, y + h - 1, w - 2, 1, 1);
    BG_SYS_SetTileEntry(layer, 4, x, y + 1, 1, h - 2, 1);
    BG_SYS_SetTileEntry(layer, 6, x + w - 1, y + 1, 1, h - 2, 1);
    BG_SYS_SetTileEntry(layer, 5, x + 1, y + 1, w - 2, h - 2, 1);
    BG_SYS_SetFlagField06(layer);
}



void STARTMENU_ClearFrameBox(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    BG_SYS_SetTileEntry(*(u8 *)&bg, 0, x, y, w, h, 0);
    BG_SYS_SetFlagField06(*(u8 *)&bg);
}




static inline void PrintMessageLine(StartMenuWork *work, u32 id, u32 pixelY, u16 color)
{
    u32 msgStr = (u32)MSGDATA_AllocString((struct MsgBank *)(work->msgBank), id);
    u32 printSys = (unsigned int)work->printSys;
    PRINTSYS_PrintQueColor((void *)printSys, (u32)BMP_WIN_GetBmp((struct Descriptor *)work->descWindow), 0, pixelY, msgStr, work->font, color);
    work->descWindowOpen = 1;
    STRBUF_Delete((struct U16Vec *)msgStr);
}




/*
 * Four identical print blocks are one static inline helper: it loads
 * p+0x68 before the bitmap call and keeps 0x440 rematerialised per site.
 */
void STARTMENU_OpenConfirmWindow(StartMenuWork *work)
{
    work->descWindow = (void *)BMP_WIN_Create(0, 2, 2, 0x1e, 0x14, 5, 1);
    PrintMessageLine(work, 0x16, 0, 0x14c0);
    PrintMessageLine(work, 0x17, 0x18, 0x440);
    PrintMessageLine(work, 0x18, 0x80, 0x440);
    PrintMessageLine(work, 0x19, 0x90, 0x440);

    BMP_WIN_MakeScreen((struct Cfg *)(work->descWindow));
    BG_SYS_SetFlagField06(0);
    STARTMENU_DrawFrameBox(0x20, 1, 0x20, 0x16, 2);
    BG_SYS_ResetSlot(1, 0, 0x100);
    BG_SYS_ResetSlot(1, 3, 0);
    BG_SYS_ResetSlot(2, 0, 0x100);
    BG_SYS_ResetSlot(2, 3, 0);
    STARTMENU_ShowRowActors(work, 0);
}




void STARTMENU_CloseDescWindow(StartMenuWork *work, int mode)
{
    BMP_WIN_Delete(work->descWindow);
    if (mode != 1) {
        STARTMENU_ClearFrameBox(0x20, 1, 0x20, 0x16, 2);
        BG_SYS_ClearLayerEx(0, 0);
        BG_SYS_ResetSlot(1, 0, 0);
        BG_SYS_ResetSlot(1, 3, work->scrollPixels);
        BG_SYS_ResetSlot(2, 0, 0);
        BG_SYS_ResetSlot(2, 3, work->scrollPixels);
        if (work->rowIds[0] == 0)
            STARTMENU_ShowRowActors(work, 1);
    }
}




void STARTMENU_OpenInfoWindow(StartMenuWork *work)
{
    work->descWindow = (void *)BMP_WIN_Create(4, 2, 3, 0x1e, 0x13, 5, 1);
    PrintMessageLine(work, 0x14, 0, 0x14c0);
    PrintMessageLine(work, 0x15, 0x18, 0x440);
    BMP_WIN_MakeScreen((struct Cfg *)(work->descWindow));
    BG_SYS_SetFlagField06(4);
    STARTMENU_DrawFrameBox(0, 1, 0x20, 0x16, 5);
}




/*
 * 0x021BBE3C is an unlabelled tail-call stub (function_starts seed).
 * Twin of STARTMENU_OpenConfirmWindow (same PrintMessageLine inline).
 */
void STARTMENU_CloseInfoWindow(StartMenuWork *work)
{
    BMP_WIN_Delete(work->descWindow);
}




void STARTMENU_OpenNoticeWindow(StartMenuWork *work)
{
    u32 noticeBank = (u32)MSGDATA_CreateFromArchive(0, 2, 0xe8, 0x800b);
    u32 msgStr;
    u32 printSys;

    work->descWindow = (void *)BMP_WIN_Create(0, 2, 2, 0x1e, 0x14, 5, 1);
    msgStr = (u32)MSGDATA_AllocString((struct MsgBank *)noticeBank, 0x20);
    printSys = (unsigned int)work->printSys;
    PRINTSYS_PrintQueColor((void *)printSys, (u32)BMP_WIN_GetBmp((struct Descriptor *)work->descWindow), 0, 0, msgStr, work->font, 0x440);
    work->descWindowOpen = 1;
    STRBUF_Delete((struct U16Vec *)msgStr);
    MSGDATA_Delete((struct Rec *)noticeBank);

    BMP_WIN_MakeScreen((struct Cfg *)(work->descWindow));
    BG_SYS_SetFlagField06(0);
    STARTMENU_DrawFrameBox(0x20, 1, 0x20, 0x16, 2);
    BG_SYS_ResetSlot(1, 0, 0x100);
    BG_SYS_ResetSlot(1, 3, 0);
    BG_SYS_ResetSlot(2, 0, 0x100);
    BG_SYS_ResetSlot(2, 3, 0);
    STARTMENU_ShowRowActors(work, 0);
}




void STARTMENU_StartMessage(StartMenuWork *work, u32 msgId)
{
    void *window;
    func_02045CAC((struct MsgBank *)(work->msgBank), msgId, (void *)(work->stringBuf));
    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)work->windows[13].window), 0xf);
    BMP_MENUWORK_DrawWindow(work->windows[13].window, 2, 1, 0xe);
    work->printJob = (void *)PRINTSYS_PrintStream((u32)work->windows[13].window, 0, 0, (u32)work->stringBuf,
                                       work->font, MSG_SPEED_GetWait(),
                                       work->taskList, 0xa, 0xb, 0xf);
    work->printAdvanceLatched = 0;
    window = work->windows[13].window;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(window));
}




void STARTMENU_HideMessageWindow(StartMenuWork *work)
{
    BMP_MENUWORK_DrawWindowBorder(work->windows[13].window, 1);
}




int STARTMENU_UpdateMessage(StartMenuWork *work)
{
    if (work->printJob == 0)
        return 0;
    APP_KEYCURSOR_Update(work->msgBoxFrame, work->printJob, work->windows[13].window);
    switch (PRINTSYS_PrintStreamGetState(work->printJob)) {
    case 0:
        if (KEY_GetCont() & 3)
            PRINTSYS_PrintStreamShortWait(work->printJob, 0);
        work->printAdvanceLatched = 0;
        break;
    case 1:
        if (work->printAdvanceLatched == 0) {
            if (KEY_GetTrg() & 3) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(work->printJob);
                work->printAdvanceLatched = 1;
            }
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(work->printJob);
        work->printJob = 0;
        work->printAdvanceLatched = 0;
        return 0;
    }
    return 1;
}




/*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 */
void STARTMENU_OpenYesNoMenu(StartMenuWork *work)
{
    YesNoWindowTemplate windowTemplate;

    windowTemplate.bgId = 0;
    windowTemplate.x = 0x18;
    windowTemplate.y = 0xD;
    windowTemplate.palette = 0xF;
    windowTemplate.tileOffset = 0;
    work->yesNoMenu = BMP_MENU_CreateYesNo(&windowTemplate, 1, 0xE, 0, 0xB);
}




int STARTMENU_BeginFadeOut(StartMenuWork *work, int v)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0xb);
    work->nextStateAfterFade = v;
    return 2;
}




/*
 * EXACT*: extent runs long; the follower at 0x021BC0AC is an unlabelled leaf
 * (function_starts seed).
 */
int STARTMENU_BeginFadeIn(StartMenuWork *work, int v)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0xb);
    work->nextStateAfterFade = v;
    return 2;
}




int STARTMENU_BeginSelectAnim(StartMenuWork *work, int v)
{
    work->selectAnimTimer = 0;
    work->selectAnimPhase = 0;
    work->nextStateAfterAnim = v;
    return 3;
}




int STARTMENU_RefreshSaveStatus(StartMenuWork *work)
{
    int status = func_020071E8(work->saveData);
    work->saveStatus = status;
    return status != 0;
}




void STARTMENU_ChangeToIntroProc(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD818, 0);
}




void STARTMENU_ReplaceWithBattleFlagProcWithSave(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)&gStartMenuBattleFlagProcData, 1);
}


void STARTMENU_ReplaceWithBattleFlagProcNoSave(void)
{
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)&gStartMenuBattleFlagProcData, 2);
}


/*
 * The ov194 id is held in a local (the original keeps it in r7 across the
 * copy loop and reuses it for the unload); the ov204 id is spelled
 * directly and reloaded from the pool for each call.
 */
int STARTMENU_NewGameIntroInit(struct Proc *proc)
{
    u32 waveArcIds[30];
    struct SaveControl *saveControl;
    NewGameIntroWork *work;
    u32 nameInCount, introCount, i;
    u32 voiceHandle;
    void *nameInOverlayId;

    saveControl = func_020070A4();
    work = PROCSYS_AllocProcWork(proc, 0x5c, 1);
    work->saveIntr = SAVE_CONTROL_INTR_Create(1, saveControl);
    func_02007220(saveControl);
    work->myStatus = MYSTATUS_Create(1);
    work->config = CONFIG_Create(1);
    work->startArg.startMode = 0;
    work->startArg.config = work->config;
    work->startArg.myStatus = work->myStatus;
    work->nameInArgs = NAMEIN_SETUP_CreateArgs(1, 0, 0, 0, 7, 0, 0);
    work->procSys = PROCSYS_Create(1);

    nameInOverlayId = ov194_id;
    GF_OVERLAY_Load((int)nameInOverlayId);
    nameInCount = gNameInWaveArcCount;
    for (i = 0; i < nameInCount; i++)
        waveArcIds[i] = gNameInWaveArcIds[i];
    GF_OVERLAY_Unload((int)nameInOverlayId);

    GF_OVERLAY_Load((int)ov204_id);
    introCount = gIntroWaveArcCount;
    for (i = 0; i < introCount; i++)
        waveArcIds[nameInCount + i] = gIntroWaveArcIds[i];
    GF_OVERLAY_Unload((int)ov204_id);

    work->waveArcSet = GFL_USE_LoadWaveArcSet(waveArcIds, nameInCount + introCount);
    voiceHandle = PM_VOICE_Prepare(0x23c, 0, 0x40, 0, 0, 0, 0, 0);
    work->voiceHandle = voiceHandle;
    work->introParam.myStatus = work->myStatus;
    work->introParam.config = work->config;
    work->introParam.phase = 1;
    work->introParam.saveIntr = work->saveIntr;
    work->introParam.voiceHandle = voiceHandle;
    return 1;
}


/*
 * Case bodies are laid out in source order, and the original places
 * case 6 before case 5 (jump table at 0x021BC254).
 * Sequence: intro (ov204), name entry (ov194), intro again; the intro sets
 * retryNameEntry to send the player back to the name entry.
 */
int STARTMENU_NewGameIntroMain(void *proc, int *seq, void *procWork, NewGameIntroWork *work)
{
    int busy;

    SAVE_CONTROL_INTR_Update(work->saveIntr);
    busy = PROCSYS_Main(work->procSys);
    switch (*seq) {
    case 0:
        PROCSYS_Push(work->procSys, (u32)ov204_id, &gIntroProcData, &work->introParam);
        *seq = 1;
        break;
    case 1:
        if (busy != 1)
            *seq = 2;
        break;
    case 2:
        work->nameInArgs->species = func_02008550(work->startArg.myStatus);
        work->nameInArgs->saveIntr = work->saveIntr;
        PROCSYS_Push(work->procSys, (u32)ov194_id, &gNameInProcData, work->nameInArgs);
        *seq = 3;
        break;
    case 3:
        if (busy != 1)
            *seq = 4;
        break;
    case 4:
        STARTMENU_SetNewPlayerNameAndGender(work->myStatus, work->nameInArgs->name, func_02008550(work->myStatus));
        work->introParam.phase = 7;
        PROCSYS_Push(work->procSys, (u32)ov204_id, &gIntroProcData, &work->introParam);
        *seq = 6;
        break;
    case 6:
        if (busy != 1)
            *seq = 5;
        break;
    case 5:
        if (work->introParam.retryNameEntry == 0)
            *seq = 7;
        else
            *seq = 2;
        break;
    case 7:
        return 1;
    }
    return 0;
}










int STARTMENU_NewGameIntroEnd(struct Proc *proc, int *seq, void *procWork, NewGameIntroWork *work)
{
    void *saveControl = func_020070A4();
    void *ov228Work;
    void *gameSystemWork;
    LocationPos pos = {0, 0, 0};
    func_02005B04((const u32 *)work->waveArcSet);
    SAVE_CONTROL_INTR_Delete(work->saveIntr);
    MYSTATUS_Copy(work->myStatus, func_02008730(saveControl));
    CONFIG_Copy(work->config, func_0200873C(saveControl));
    GFL_HEAP_Free(work->myStatus);
    GFL_HEAP_Free(work->config);
    PROCSYS_Delete((struct S020314B8 *)work->procSys);
    if (func_02007210(saveControl) == 1) {
        GF_OVERLAY_Load((int)ov228_id);
        ov228Work = SAVE_OUTSIDE_Load(1);
        if (SAVE_OUTSIDE_IsLoaded(ov228Work) == 1)
            SAVE_OUTSIDE_CopyPayload(ov228Work, saveControl);
        SAVE_OUTSIDE_Free(ov228Work);
        GF_OVERLAY_Unload((int)ov228_id);
    }
    gameSystemWork = GAMESYSTEM_SetupInitWork(0, 0, &pos, 0);
    NAMEIN_SETUP_FreeArgs((int)work->nameInArgs);
    PROCSYS_FreeProcWork(proc);
    PROCSYS_ReplaceGlobal(-1, (u32)d_0209DF9C, (u32)gameSystemWork);
    return 1;
}








int STARTMENU_BattleFlagProcInit(struct Proc *proc)
{
    NewGameIntroWork *work = PROCSYS_AllocProcWork(proc, 0x5c, 1);

    work->startArg.startMode = 1;
    work->startArg.config = (struct Config *)func_0200873C(func_020070A4());
    work->saveOptions = BEACON_GetBlock(func_020070A4());
    work->startArg.myStatus = 0;
    return 1;
}








int STARTMENU_BattleFlagProcMain(void *proc, int *seq, int mode, NewGameIntroWork *work)
{
    switch (*seq) {
    case 0:
        if (mode == 0) {
            PROCSYS_PushGlobal(-1, (u32)d_021BD830, (u32)work);
        } else if (mode == 1) {
            CONFIG_SetBattleFlag(work->startArg.config, 0);
        } else if (mode == 2) {
            CONFIG_SetBattleFlag(work->startArg.config, 1);
        }
        *seq = *seq + 1;
        break;
    case 1:
        return 1;
    }
    return 1;
}








int STARTMENU_BattleFlagProcEnd(struct Proc *proc, int seq, int mode, NewGameIntroWork *work)
{
    SaveLocation location;
    void *saveControl;
    u32 battleFlag;
    u8 savedOption;

    saveControl = func_020070A4();
    battleFlag = CONFIG_GetBattleFlag(work->startArg.config);
    savedOption = BEACON_GetSlotStates(work->saveOptions);
    SAVE_CONTROL_Reload(saveControl);
    CONFIG_ApplyAppliedFlag((const struct Config *)func_0200873C(saveControl));
    func_0200890C(saveControl, (struct Sub02008828Rec *)(&location));
    PROCSYS_ReplaceGlobal(-1, (u32)d_0209DF9C, (u32)GAMESYSTEM_SetupInitWork(1, location.mapId, &location.position, location.facing));
    CONFIG_SetBattleFlag(work->startArg.config, battleFlag);
    BEACON_SetSlotStates(work->saveOptions, savedOption);
    PROCSYS_FreeProcWork(proc);
    return 1;
}








void STARTMENU_SetNewPlayerNameAndGender(struct MyStatus *myStatus, struct Strbuf *name, int gender)
{
    u64 tick;
    u32 currentValue;
    func_020084E4((u16 *)myStatus, (struct U16Vec *)name);
    func_0200854C((int)myStatus, gender);
    func_0200852C(myStatus, func_02005728(-1));
    tick = GF_STANDARD_Rand();
    currentValue = func_02008550(myStatus);
    func_02008558(myStatus, (u8)((u32)((tick * 8) >> 32) + currentValue * 8));
}








/*
 * EXACT*: inferred extent runs two bytes long; the follower is an unlabelled
 * padding pair.
 */
int STARTMENU_ConfigPromptInit(struct Proc *proc, int seq, int *procWork)
{
    ConfigPromptWork *work;
    GFL_HEAP_CreateChildHeap(1, 0x39, 0x80000);
    work = PROCSYS_AllocProcWork(proc, 0x1c, 0x39);
    if (*procWork == 0)
        work->question = 0;
    else
        work->question = 2;
    work->pulsePhase = 0;
    STARTMENU_ConfigPromptSetupGraphics(work);
    STARTMENU_ConfigPromptDrawQuestion(work);
    return 1;
}







int STARTMENU_ConfigPromptEnd(int proc, int seq, int procWork, ConfigPromptWork *work)
{
    STARTMENU_ConfigPromptDeleteWindows(work);
    GF_FONT_Delete(work->font);
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_Delete();
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_DeleteChecked(0x39);
    return 1;
}

int STARTMENU_ConfigPromptMain(int proc, int seq, NewGameStartArg *startArg, ConfigPromptWork *work)
{
    int choice;

    switch (work->question) {
    case 0:
        choice = STARTMENU_ConfigPromptReadInput(work);
        if (choice != 0) {
            if (choice == 1)
                CONFIG_SetAppliedFlag(startArg->config, 0);
            else
                CONFIG_SetAppliedFlag(startArg->config, 1);
            STARTMENU_ConfigPromptDeleteWindows(work);
            work->question = 1;
            STARTMENU_ConfigPromptDrawQuestion(work);
        }
        break;
    case 1:
        choice = STARTMENU_ConfigPromptReadInput(work);
        if (choice != 0) {
            if (choice == 1)
                func_0200854C((int)startArg->myStatus, 0);
            else
                func_0200854C((int)startArg->myStatus, 1);
            STARTMENU_ConfigPromptDeleteWindows(work);
            work->question = 2;
            STARTMENU_ConfigPromptDrawQuestion(work);
        }
        break;
    case 2:
        choice = STARTMENU_ConfigPromptReadInput(work);
        if (choice != 0) {
            if (choice == 1)
                CONFIG_SetBattleFlag(startArg->config, 1);
            else
                CONFIG_SetBattleFlag(startArg->config, 0);
            WIPE_SYS_Start(0, 0, 0, 0, 0xc, 1, 0x39);
            work->question = 3;
        }
        break;
    case 3:
        if (WIPE_SYS_EndCheck() == 1)
            return 1;
        break;
    }
    STARTMENU_ConfigPromptPulseColor(work);
    return 0;
}

/*
 * The POWCNT clear is spelled `& ~0x8000` (the SDK display-select inline):
 * the original pools 0xFFFF7FFF, where `&= 0x7FFF` derives the mask from
 * the -16 already in a register.  The four ov088 data hints were contested
 * or unwitnessed with the ov088 token; without it they resolve as sole-ref.
 */
void STARTMENU_ConfigPromptSetupGraphics(ConfigPromptWork *work)
{
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BD8B8);
    BG_SYS_Create(0x39);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BD848);
    *(u16 *)0x04000304 = (u16)(*(u16 *)0x04000304 & ~0x8000);
    STARTMENU_InitBgLayer(d_021BD858, 3);
    STARTMENU_InitBgLayer(d_021BD878, 1);
    STARTMENU_InitBgLayer(d_021BD898, 5);
    BMP_WIN_Init(0x39);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0, 0x20, 0x39);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0, 0x20, 0x39);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x39);
    BMP_MENUWORK_LoadCharAndPltt(1, 1, 3, 0, 0x39);
    BMP_MENUWORK_LoadCharAndPltt(1, 0x1f, 4, 0, 0x39);
    BMP_MENUWORK_LoadCharAndPltt(5, 1, 1, 0, 0x39);
    *(u16 *)0x05000000 = 0x7D8C;
    *(u16 *)0x05000400 = 0x7D8C;
    FADE_Start(3, 0x10, 0, 0);
}

void STARTMENU_InitBgLayer(const void *bgTemplate, int bgId)
{
    BG_SYS_InitBgLayer(bgId, bgTemplate, 0);
    BG_SYS_SetPlaneVisible(bgId, 1);
    BG_SYS_FreeSlot(bgId);
    BG_SYS_PushTile(bgId);
}

void STARTMENU_ConfigPromptDrawQuestion(ConfigPromptWork *work)
{
    u32 msgArc;
    u32 text;
    u8 i;

    msgArc = (u32)MSGDATA_CreateFromArchive(0, 2, 0xab, 0x39);
    work->selectedChoice = 0;
    work->questionWin = (void *)BMP_WIN_Create((int)5, (int)1, (u8)0x13, (int)0x1d, (int)4, (int)0, (int)1);
    BMP_WIN_MakeScreen((struct Cfg *)work->questionWin);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)work->questionWin)), 0xf);
    text = (u32)MSGDATA_AllocString((struct MsgBank *)msgArc, work->question);
    BMP_MENUWORK_DrawWindow(work->questionWin, 0, 1, 1);
    PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)work->questionWin)), 2, 2, (void *)text, work->font);
    STRBUF_Delete((struct U16Vec *)text);
    BMP_WIN_TransferChars((struct Descriptor *)work->questionWin);
    for (i = 0; i < 2; i++) {
        work->choiceWin[i] = (void *)BMP_WIN_Create((int)1, (int)6, (u8)(i * 4 + 0xc), (int)0x14, (int)2, (int)0, (int)1);
        BMP_WIN_MakeScreen((struct Cfg *)work->choiceWin[i]);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)work->choiceWin[i])), 0xf);
        text = (u32)MSGDATA_AllocString((struct MsgBank *)msgArc, i + 5 + work->question * 2);
        PRINTSYS_Print((void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)work->choiceWin[i])), 2, 2, (void *)text, work->font);
        STRBUF_Delete((struct U16Vec *)text);
        BMP_WIN_TransferChars((struct Descriptor *)work->choiceWin[i]);
    }
    MSGDATA_Delete((struct Rec *)msgArc);
    STARTMENU_ConfigPromptHighlightChoice(work);
}

void STARTMENU_ConfigPromptDeleteWindows(ConfigPromptWork *work)
{
    u8 i;

    BMP_WIN_Delete(work->questionWin);
    for (i = 0; i < 2; i++)
        BMP_WIN_Delete(work->choiceWin[i]);
}

void STARTMENU_ConfigPromptHighlightChoice(ConfigPromptWork *work)
{
    unsigned char i;

    for (i = 0; i < 2; i++) {
        if (i == work->selectedChoice)
            BMP_MENUWORK_DrawWindow(work->choiceWin[i], 0, 1, 3);
        else
            BMP_MENUWORK_DrawWindow(work->choiceWin[i], 0, 31, 4);
    }
}

int STARTMENU_ConfigPromptReadInput(ConfigPromptWork *work)
{
    int result;
    u32 keys;
    int touched;
    TouchHitTable hitTable;

    if ((KEY_GetTrg() & 0x40) || (KEY_GetTrg() & 0x80)) {
        if (work->selectedChoice == 0)
            work->selectedChoice = 1;
        else
            work->selectedChoice = 0;
        STARTMENU_ConfigPromptHighlightChoice(work);
        GFL_USE_PlaySeDefaultVolume(0x548);
    }
    keys = KEY_GetTrg();
    result = 1;
    if (keys & result) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (work->selectedChoice != 0)
            result = 2;
        return result;
    }
    hitTable = d_021BD83C;
    touched = TOUCHPANEL_HitTrg(&hitTable);
    if (touched != -1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return touched == 0 ? 1 : 2;
    }
    return 0;
}

s32 STARTMENU_ConfigPromptPulseColor(ConfigPromptWork *work)
{
    s32 nextPhase = work->pulsePhase + 0x400;
    s32 sineValue;
    s16 halfSine;
    u32 blue, green, red;

    if (nextPhase >= 0x10000)
        work->pulsePhase = work->pulsePhase - 0xFC00;
    else
        work->pulsePhase = nextPhase;
    sineValue = FX_SinCosTable_[(work->pulsePhase >> 4) * 2 + 1] + 0x1000;
    halfSine = sineValue / 2;
    blue = (u8)(0x1d + (-(halfSine * 8) >> 12));
    red = (u8)(0x19 + (halfSine * -0x14 >> 12));
    green = (u8)(0x1e + (halfSine * -0xf >> 12));
    work->pulseColor = red | (green << 5) | (blue << 10);
    return NNS_GfdRegisterNewVramTransferTask((void *)0xf, 0x6c, (u32)(&work->pulseColor), 2);
}

int STARTMENU_LogoScreenInit(struct Proc *proc)
{
    GFL_HEAP_CreateChildHeap(1, 0x16, 0x70000);
    MI_CpuFill8(PROCSYS_AllocProcWork(proc, 8, 0x16), 0, 8);
    return 1;
}

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}







static inline void GXS_SetVisibleWnd(int window)
{
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & ~0xE000 | (window << 13);
}







/*
 * Case 1's fade call takes its zero from an enum local set at the top of
 * the arm: the enum is not folded, so the zero stays in r5 (the register
 * the stack-argument zeros use) through to `adds r2, r5, #0`. A literal 0,
 * an int local set to 0, and int-typed func_02049624 parameters all give
 * `movs r2, #0` scheduled after r0/r1 (6 bytes out); the permuter (300,
 * --types) found nothing.
 * volatile: DISPCNT 0x04000000 and DB_DISPCNT 0x04001000 read-modify-written by the SDK inlines GX_SetVisibleWnd/GXS_SetVisibleWnd (0x021BCA3A, 0x021BCA46)
 */
int STARTMENU_LogoScreenMain(int proc, int seq, int *variant, LogoScreenWork *work)
{
    Zero zero;

    switch (work->state) {
    case 0:
        BG_SYS_SetMainVisiblePlanes(0);
        BG_SYS_SetSubVisiblePlanes(0);
        reg_G2_BLDCNT = 0;
        reg_G2S_DB_BLDCNT = 0;
        GX_SetVisibleWnd(0);
        GXS_SetVisibleWnd(0);
        BG_SYS_SetVramBanks((const struct DispVram *)d_021BD944);
        BG_SYS_Create(0x16);
        BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BD8F4);
        BG_SYS_InitBgLayer(1, (const struct BgTemplate *)d_021BD904, 0);
        BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BD924, 0);
        if (*variant == 1) {
            GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
            work->state = 7;
        } else {
            GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, 16);
            GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, 16);
            work->state = 1;
        }
        break;
    case 1:
        zero = Z0;
        func_02049624(0x1a, 0xc, 1, 0, 0, 1, 0x16);
        ARC_UTIL_UploadBgPaletteFromArchive(0x1a, 0xd, 1, 0, 0, 1, 0x16);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x1a, 0xb, 0, 0, 0, 0x16);
        func_02049624(0x1a, 0xc, 5, 0, 0, 1, 0x16);
        ARC_UTIL_UploadBgPaletteFromArchive(0x1a, 0xe, 5, 0, 0, 1, 0x16);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0x1a, 0xb, 4, 0, 0, 0x16);
        BG_SYS_SetPlaneVisible(1, 1);
        BG_SYS_SetPlaneVisible(5, 1);
        BMP_SetDisplaySwap(1);
        BG_SYS_ResetSubDisplay();
        FADE_Start(0xc, 0x10, zero, 2);
        work->state = 2;
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            work->state = 3;
            work->timer = 0;
        }
        break;
    case 3:
        if (++work->timer > 0x5a)
            work->state = 4;
        if (KEY_GetTrg() & 0xb)
            work->state = 4;
        break;
    case 4:
        FADE_Start(3, 0, 0x10, 2);
        work->state = 5;
        break;
    case 5:
        if (FADE_IsActive() == 0) {
            work->state = 6;
            work->timer = 0;
        }
        break;
    case 6:
        if (++work->timer > 0x1e) {
            work->state = 7;
            work->timer = 0;
        }
        break;
    case 7:
        func_02049624(0xa4, 1, 1, 0, 0x8000, 0, 0x16);
        ARC_UTIL_UploadBgPaletteFromArchive(0xa4, 2, 1, 0, 0, 0, 0x16);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0xa4, 0, 0, 0, 0, 0x16);
        func_02049624(0xa4, 3, 5, 0, 0x8000, 0, 0x16);
        ARC_UTIL_UploadBgPaletteFromArchive(0xa4, 4, 5, 0, 0, 0, 0x16);
        ARC_UTIL_UploadPaletteFromArchiveWhole(0xa4, 0, 4, 0, 0, 0x16);
        BG_SYS_PushTile(1);
        BG_SYS_PushTile(5);
        BG_SYS_SetPlaneVisible(1, 1);
        BG_SYS_SetPlaneVisible(5, 1);
        BMP_SetDisplaySwap(1);
        BG_SYS_ResetSubDisplay();
        FADE_Start(3, 0x10, 0, 2);
        work->state = 8;
        break;
    case 8:
        if (FADE_IsActive() == 0)
            work->state = 9;
        break;
    case 9:
        if (++work->timer > 0x5a) {
            work->state = 10;
            work->timer = 0;
        }
        break;
    case 10:
        FADE_Start(3, 0, 0x10, 2);
        work->state = 0xb;
        break;
    case 11:
        if (FADE_IsActive() == 0)
            work->state = 0xc;
        break;
    case 12:
        if (++work->timer > 0x1e)
            work->state = 0xd;
        break;
    case 13:
        BG_SYS_Delete();
        return 1;
    }
    return 0;
}







int STARTMENU_LogoScreenEnd(int proc)
{
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_DeleteChecked(0x16);
    return 1;
}

int STARTMENU_SaveEraseInit(struct Proc *proc)
{
    GFL_HEAP_CreateChildHeap(1, 0x81, 0x30000);
    MI_CpuFill8(PROCSYS_AllocProcWork(proc, 0x2c, 0x81), 0, 0x2c);
    return 1;
}

/*
 * EXACT*: the extent runs two bytes long (trailing padding pair).
 */
int STARTMENU_SaveEraseMain(int proc, int *seq, int procWork, SaveEraseWork *work)
{
    switch (*seq) {
    case 0:
        STARTMENU_SaveEraseStepSetup(work, seq);
        break;
    case 1:
        STARTMENU_SaveEraseStepShowPrompt(work, seq);
        break;
    case 2:
        STARTMENU_SaveEraseStepOpenFirstYesNo(work, seq);
        break;
    case 3:
        STARTMENU_SaveEraseStepFirstConfirm(work, seq);
        break;
    case 4:
        STARTMENU_SaveEraseStepOpenSecondYesNo(work, seq);
        break;
    case 5:
        STARTMENU_SaveEraseStepSecondConfirm(work, seq);
        break;
    case 6:
        STARTMENU_SaveEraseStepErase(work, seq);
        break;
    case 7:
        STARTMENU_SaveEraseStepTeardown(work, seq);
        break;
    case 8:
        return 1;
    }
    return 0;
}

int STARTMENU_SaveEraseEnd(int proc)
{
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_DeleteChecked(0x81);
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}

void STARTMENU_SaveEraseStepSetup(SaveEraseWork *work, int *seq)
{
    STARTMENU_SaveEraseClearVram();
    STARTMENU_SaveEraseSetupGraphics();
    STARTMENU_SaveEraseAllocResources(work);
    STARTMENU_SaveEraseCreateWindow(work);
    STARTMENU_SaveEraseStartVblankTask(work);
    STARTMENU_SaveEraseStartFadeIn();
    *seq = 1;
}

void STARTMENU_SaveEraseStepShowPrompt(SaveEraseWork *work, int *seq)
{
    if (WIPE_SYS_EndCheck() == 1) {
        STARTMENU_SaveEraseStartMessage(work, 0);
        *seq = 2;
    }
}

void STARTMENU_SaveEraseStepOpenFirstYesNo(SaveEraseWork *work, int *seq)
{
    if (STARTMENU_SaveEraseUpdateMessage(work) == 0) {
        STARTMENU_SaveEraseOpenYesNo(work);
        *seq = 3;
    }
}

void STARTMENU_SaveEraseStepFirstConfirm(SaveEraseWork *work, int *seq)
{
    int result = BMP_MENU_ProcessYesNo(work->yesNoMenu);

    if (result == 0)
        goto answeredYes;
    if (result == -2)
        goto cancelled;
    return;
answeredYes:
    STARTMENU_SaveEraseStartMessage(work, 1);
    *seq = 4;
    return;
cancelled:
    STARTMENU_SaveEraseStartFadeOut();
    *seq = 7;
}

void STARTMENU_SaveEraseStepOpenSecondYesNo(SaveEraseWork *work, int *seq)
{
    if (STARTMENU_SaveEraseUpdateMessage(work) == 0) {
        STARTMENU_SaveEraseOpenYesNo(work);
        *seq = 5;
    }
}

/*
 * EXACT*: the extent runs 20 bytes long; the follower at 0x021BCE70 is an
 * unlabelled tail-call stub (ldr r0,[pc]; ldr r3,[pc]; ldr r0,[r0]; bx r3).
 * The switch value is unsigned so that case 0xFFFFFFFE sorts after case 0.
 */
void STARTMENU_SaveEraseStepSecondConfirm(SaveEraseWork *work, int *seq)
{
    unsigned result = BMP_MENU_ProcessYesNo(work->yesNoMenu);
    switch (result) {
    case 0:
        STARTMENU_SaveEraseStartMessage(work, 2);
        *seq = 6;
        break;
    case 0xFFFFFFFE:
        STARTMENU_SaveEraseStartFadeOut();
        *seq = 7;
        break;
    }
}

void STARTMENU_SaveEraseUpdateTimeIcon(void)
{
    TIME_ICON_Update(d_021BDA20);
}

void STARTMENU_SaveEraseStepErase(SaveEraseWork *work, int *seq)
{
    void *saveControl;
    u32 slot;

    if (STARTMENU_SaveEraseUpdateMessage(work) == 0) {
        d_021BDA20 = TIME_ICON_Create(0, work->window, 0xf, 0x10, 0x81);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(work->window));
        func_02005654((int)STARTMENU_SaveEraseUpdateTimeIcon, 0);
        saveControl = func_020070A4();
        GF_OVERLAY_Load((u32)ov228_id);
        SAVE_OUTSIDE_ClearFlash(0x81);
        GF_OVERLAY_Unload((u32)ov228_id);
        func_02007230(saveControl);
        for (slot = 0; slot < 9; slot++) {
            if (SAVE_CONTROL_LoadExtraSave(saveControl, slot, 0x81) == 1)
                SAVE_CONTROL_EraseExtraSave(saveControl, slot, 0x81);
            SAVE_CONTROL_DeleteExtraSave(saveControl, slot);
        }
        func_0200566C();
        OS_ResetSystem(0);
    }
}

void STARTMENU_SaveEraseStepTeardown(SaveEraseWork *work, int *seq)
{
    if (WIPE_SYS_EndCheck() == 1) {
        STARTMENU_SaveEraseStopVblankTask(work);
        STARTMENU_SaveEraseDeleteWindow(work);
        STARTMENU_SaveEraseFreeResources(work);
        STARTMENU_SaveEraseExitGraphics();
        *seq = 8;
    }
}

void STARTMENU_SaveEraseClearVram(void)
{
    DispVramBlock vramBanks = d_021BD9B0;

    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)(&vramBanks));
}

void STARTMENU_SaveEraseSetupGraphics(void)
{
    DispConfigBlock dispConfig;
    BgTemplateBlock bgTemplate;

    BG_SYS_Create(0x81);
    dispConfig = d_021BD980;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&dispConfig));
    bgTemplate = d_021BD990;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&bgTemplate), 0);
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_LoadPlttEntry(0, 0x7D8C);
    BG_SYS_LoadPlttEntry(4, 0x7D8C);
}

void STARTMENU_SaveEraseExitGraphics(void)
{
    BG_SYS_SetMainPlaneVisible(1, 0);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}

void STARTMENU_SaveEraseAllocResources(SaveEraseWork *work)
{
    work->savedAppliedFlag = func_020461E4();
    func_020461D4(0);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 1, 0x81);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x81);
    work->stringBuf = STRBUF_Create(0x400, 0x81);
    work->taskList = TCBL_Create(0x81, 0x81, 1, 4);
    work->msgBoxFrame = (void *)APP_KEYCURSOR_CreateDefault(0xf, 1, 0, 0x81);
}

void STARTMENU_SaveEraseFreeResources(SaveEraseWork *work)
{
    APP_KEYCURSOR_Delete((int)work->msgBoxFrame);
    TCBL_Destroy(work->taskList);
    STRBUF_Delete(work->stringBuf);
    GF_FONT_Delete(work->font);
    MSGDATA_Delete(work->msgBank);
    func_020461D4(work->savedAppliedFlag);
}

void STARTMENU_SaveEraseCreateWindow(SaveEraseWork *work)
{
    int heapId = 0x81;
    int width = 0x1e;
    BMP_WIN_Init(0x81);
    work->window = (void *)BMP_WIN_Create(0, 1, 0x13, width, 4, 0xf, 1);
    BMP_MENUWORK_LoadCharAndPltt(0, 1, 0xe, 0, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, width << 4, 0x20, heapId);
}

void STARTMENU_SaveEraseDeleteWindow(SaveEraseWork *work)
{
    BMP_WIN_Delete(work->window);
    BMP_WIN_Exit();
}

void STARTMENU_SaveEraseVblankTask(void)
{
    BG_SYS_Update();
    *(volatile unsigned int *)((char *)&SDK_AUTOLOAD_DTCM_START + 0x3FF8) |= 1;
}

void STARTMENU_SaveEraseStartVblankTask(SaveEraseWork *work)
{
    work->vblankTask = GFL_USE_AddMainTask(STARTMENU_SaveEraseVblankTask, work, 0);
}

void STARTMENU_SaveEraseStopVblankTask(SaveEraseWork *work)
{
    TCB_DeleteTask((struct Node *)work->vblankTask);
}

void STARTMENU_SaveEraseStartMessage(SaveEraseWork *work, u32 messageId)
{
    void *window;

    func_02045CAC((struct MsgBank *)work->msgBank, messageId, work->stringBuf);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)work->window)), 15);
    BMP_MENUWORK_DrawWindow(work->window, 2, 1, 14);
    work->printJob = (void *)PRINTSYS_PrintStream((u32)work->window, 0, 0, (u32)work->stringBuf, (u32)work->font, MSG_SPEED_GetWaitForSpeed(0), (u32)work->taskList, 10, 0x81, 15);
    work->printAdvanceLatched = 0;
    window = work->window;
    BMP_WIN_TransferChars((struct Descriptor *)window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)window));
}

int STARTMENU_SaveEraseUpdateMessage(SaveEraseWork *work)
{
    TCBL_Main(work->taskList);
    APP_KEYCURSOR_Update(work->msgBoxFrame, work->printJob, work->window);
    switch (PRINTSYS_PrintStreamGetState(work->printJob)) {
    case 0:
        work->printAdvanceLatched = 0;
        break;
    case 1:
        if (work->printAdvanceLatched == 0) {
            if (KEY_GetTrg() & 3) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(work->printJob);
                work->printAdvanceLatched = 1;
            }
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(work->printJob);
        work->printAdvanceLatched = 0;
        return 0;
    }
    return 1;
}

void STARTMENU_SaveEraseOpenYesNo(SaveEraseWork *work)
{
    YesNoWindowTemplate windowTemplate;
    windowTemplate.bgId = 0;
    windowTemplate.x = 0x18;
    windowTemplate.y = 0x0D;
    windowTemplate.palette = 0x0F;
    windowTemplate.tileOffset = 0;
    work->yesNoMenu = BMP_MENU_CreateYesNo(&windowTemplate, 1, 0x0E, 1, 0x81);
}

void STARTMENU_SaveEraseStartFadeIn(void)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x81);
}

void STARTMENU_SaveEraseStartFadeOut(void)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x81);
}
