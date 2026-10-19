/*
 * file:     monolith_tool.c
 * unit:     yes
 * function: MONOLITH_TOOL_Init, MONOLITH_TOOL_Main, MONOLITH_TOOL_Exit, MONOLITH_TOOL_InitDisplay, MONOLITH_TOOL_DeleteBg, MONOLITH_TOOL_InitBmpWin, MONOLITH_TOOL_ExitBmpWin, MONOLITH_TOOL_InitPalAnm, MONOLITH_TOOL_FreePalAnm, MONOLITH_TOOL_InitBackgrounds, MONOLITH_TOOL_FreeBackgrounds, MONOLITH_TOOL_LoadGraphics, MONOLITH_TOOL_FreeSubBgChar, MONOLITH_TOOL_InitText, MONOLITH_TOOL_FreeText, MONOLITH_TOOL_InitActors, MONOLITH_TOOL_FreeActors, MONOLITH_TOOL_LoadActorResources, MONOLITH_TOOL_FreeActorResources, MONOLITH_TOOL_VBlankTask, MONOLITH_TOOL_LoadSlotRecords, MONOLITH_TOOL_CreateButton, MONOLITH_TOOL_FreeButton, MONOLITH_TOOL_SetButtonVisible, MONOLITH_TOOL_IsButtonUploaded, MONOLITH_TOOL_HighlightButtonPulse, MONOLITH_TOOL_HighlightButtonFlash, MONOLITH_TOOL_SetButtonPulse, MONOLITH_TOOL_SetButtonFlash, MONOLITH_TOOL_ResetHighlights, MONOLITH_TOOL_GetHighlightMode, MONOLITH_TOOL_UpdateHighlight, MONOLITH_TOOL_SetHighlightMode, MONOLITH_TOOL_GetHighlightColorA, MONOLITH_TOOL_GetHighlightColorB, MONOLITH_TOOL_GetHighlightColorCount, MONOLITH_TOOL_CreateLabel, MONOLITH_TOOL_FreeLabel, MONOLITH_TOOL_UpdateLabel, MONOLITH_TOOL_GetTitleSpecies, MONOLITH_TOOL_GetSlotIconStates, MONOLITH_TOOL_CreateSlotIcon, MONOLITH_TOOL_DeleteSlotIcon, MONOLITH_TOOL_UpdateSlotIconState, MONOLITH_TOOL_CreateCursor, MONOLITH_TOOL_DeleteCursor, MONOLITH_TOOL_CreateBlink, MONOLITH_TOOL_DeleteBlink, MONOLITH_TOOL_UpdateBlink, MONOLITH_TOOL_StartBlink, MONOLITH_TOOL_IsBlinkActive, MONOLITH_TOOL_CreateActorAt, MONOLITH_TOOL_DeleteActorAt, MONOLITH_TOOL_Noop, MONOLITH_TOOL_CreateTaskMenuRes, MONOLITH_TOOL_DeleteTaskMenuRes, MONOLITH_TOOL_OpenTaskMenu, MONOLITH_TOOL_CloseTaskMenu, MONOLITH_TOOL_UpdateTaskMenu, MONOLITH_TOOL_DrawSlotCounts, MONOLITH_TOOL_SLOT_SELECT_Init, MONOLITH_TOOL_SLOT_SELECT_Main, MONOLITH_TOOL_SLOT_SELECT_Exit, MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds, MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds, MONOLITH_TOOL_SLOT_SELECT_LoadGraphics, MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow, MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow, MONOLITH_TOOL_SLOT_SELECT_ShowMessage, MONOLITH_TOOL_SLOT_SELECT_IsMessageDone, MONOLITH_TOOL_SLOT_SELECT_HideMessage, MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons, MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons, MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons, MONOLITH_TOOL_SLOT_SELECT_MoveCursor, MONOLITH_TOOL_SLOT_SELECT_CreateButtons, MONOLITH_TOOL_SLOT_SELECT_FreeButtons, MONOLITH_TOOL_SLOT_SELECT_UpdateButtons, MONOLITH_TOOL_SLOT_SELECT_CreateCursor, MONOLITH_TOOL_SLOT_SELECT_FreeCursor, MONOLITH_TOOL_SLOT_SELECT_UpdateCursor, MONOLITH_TOOL_SLOT_SELECT_SetMode, MONOLITH_TOOL_TITLE_Init, MONOLITH_TOOL_TITLE_Main, MONOLITH_TOOL_TITLE_Exit, MONOLITH_TOOL_TITLE_InitBackgrounds, MONOLITH_TOOL_TITLE_FreeBackgrounds, MONOLITH_TOOL_TITLE_LoadGraphics, MONOLITH_TOOL_TITLE_CreateSlotIcons, MONOLITH_TOOL_TITLE_FreeSlotIcons, MONOLITH_TOOL_TITLE_UpdateSlotIcons, MONOLITH_TOOL_MENU_Create, MONOLITH_TOOL_MENU_Update, MONOLITH_TOOL_MENU_Destroy, MONOLITH_TOOL_MENU_CreateButtons, MONOLITH_TOOL_MENU_FreeButtons, MONOLITH_TOOL_MENU_UpdateButtons, MONOLITH_TOOL_MENU_CreateCursor, MONOLITH_TOOL_MENU_FreeCursor, MONOLITH_TOOL_MENU_UpdateCursor, MONOLITH_TOOL_MENU_InitBackgrounds, MONOLITH_TOOL_MENU_FreeBackgrounds, MONOLITH_TOOL_MENU_CreateWindow, MONOLITH_TOOL_MENU_FreeWindow, MONOLITH_TOOL_MENU_ShowMessage, MONOLITH_TOOL_MENU_IsMessageDone, MONOLITH_TOOL_MENU_HideMessage, MONOLITH_TOOL_SUMMARY_Create, MONOLITH_TOOL_SUMMARY_Update, MONOLITH_TOOL_SUMMARY_Destroy, MONOLITH_TOOL_SUMMARY_InitBackgrounds, MONOLITH_TOOL_SUMMARY_FreeBackgrounds, MONOLITH_TOOL_SUMMARY_LoadGraphics, MONOLITH_TOOL_SUMMARY_CreateWindows, MONOLITH_TOOL_SUMMARY_DeleteWindows, MONOLITH_TOOL_SUMMARY_CreateLabel, MONOLITH_TOOL_SUMMARY_FreeLabel, MONOLITH_TOOL_SUMMARY_Draw, MONOLITH_TOOL_STATS_Create, MONOLITH_TOOL_STATS_Update, MONOLITH_TOOL_STATS_Destroy, MONOLITH_TOOL_STATS_InitBackgrounds, MONOLITH_TOOL_STATS_FreeBackgrounds, MONOLITH_TOOL_STATS_LoadGraphics, MONOLITH_TOOL_STATS_CreateWindows, MONOLITH_TOOL_STATS_DeleteWindows, MONOLITH_TOOL_STATS_Draw, MONOLITH_TOOL_STATS_CreateCursor, MONOLITH_TOOL_STATS_FreeCursor, MONOLITH_TOOL_STATS_UpdateCursor, MONOLITH_TOOL_LIST_Init, MONOLITH_TOOL_LIST_Main, MONOLITH_TOOL_LIST_Exit, MONOLITH_TOOL_LIST_InitBackgrounds, MONOLITH_TOOL_LIST_FreeBackgrounds, MONOLITH_TOOL_LIST_LoadGraphics, MONOLITH_TOOL_LIST_FreeBgChar, MONOLITH_TOOL_LIST_InitWindows, MONOLITH_TOOL_LIST_FreeWindows, MONOLITH_TOOL_LIST_DrawTitle, MONOLITH_TOOL_LIST_ShowMessage, MONOLITH_TOOL_LIST_ShowFormattedMessage, MONOLITH_TOOL_LIST_IsMessageDone, MONOLITH_TOOL_LIST_HideMessage, MONOLITH_TOOL_LIST_FitBackground, MONOLITH_TOOL_LIST_BuildEntryList, MONOLITH_TOOL_LIST_FreeEntryBitmaps, MONOLITH_TOOL_LIST_DrawEntryNames, MONOLITH_TOOL_CreateRowGrids, MONOLITH_TOOL_DeleteRowGrids, MONOLITH_TOOL_CreateBackButton, MONOLITH_TOOL_LIST_FreeBackButton, MONOLITH_TOOL_LIST_UpdateBackButton, MONOLITH_TOOL_CreateMarker, MONOLITH_TOOL_DeleteMarker, MONOLITH_TOOL_UpdateMarker, MONOLITH_TOOL_CreateScrollArrows, MONOLITH_TOOL_DeleteScrollArrows, MONOLITH_TOOL_UpdateScrollArrows, MONOLITH_TOOL_ProcessListInput, MONOLITH_TOOL_SetCursor, MONOLITH_TOOL_SetRowHighlight, MONOLITH_TOOL_SetRowHighlightSelected, MONOLITH_TOOL_SetRowHighlightNormal, MONOLITH_TOOL_ClearPrevHighlight, MONOLITH_TOOL_ApplyCursorChange, MONOLITH_TOOL_ScrollBy, MONOLITH_TOOL_UpdateBgScroll, MONOLITH_TOOL_UpdateRows, MONOLITH_TOOL_TaskUploadRows, MONOLITH_TOOL_GetRowAtY, MONOLITH_TOOL_InitInfoScreen, MONOLITH_TOOL_MainInfoScreen, MONOLITH_TOOL_ExitInfoScreen, MONOLITH_TOOL_SetupInfoBgs, MONOLITH_TOOL_HideInfoBgs, MONOLITH_TOOL_LoadInfoPalette, MONOLITH_TOOL_CreateInfoWindows, MONOLITH_TOOL_DeleteInfoWindows, MONOLITH_TOOL_DrawInfoHeader, MONOLITH_TOOL_DrawActiveEntry, MONOLITH_TOOL_DrawSelectedEntry
 * address:  0x021B6100
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   BMP_SetDisplaySwap  0x0204363C  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   PROCSYS_Create  0x02031324  arm
 *   PRINTSYS_CTRL_Init  0x02028470  thumb
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   INTRUDE_COMM_SendBusyBegin  0x0217440C  thumb  ov011
 *   INTRUDE_COMM_SendBusyEnd  0x0217446C  thumb  ov011
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_DrawSystem  0x0204A600  arm
 *   d_021BA774     0x021BA774  data  a4
 *   PROCSYS_Delete  0x0203133C  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BG_SYS_SetVramBanks  0x020433E0  arm
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   d_021BA7D4     0x021BA7D4  data  ov071  a4
 *   d_021BA764     0x021BA764  data  a4
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   BMP_WIN_Init  0x02045088  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   d_021BA794     0x021BA794  data  a4
 *   d_021BA7B4     0x021BA7B4  data  a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   PALANM_LoadHandlePaletteToSlotAt  0x02021660  thumb
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   PALANM_LoadHandlePaletteToSlot  0x020216B4  thumb
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   BG_SYS_CreateRun  0x0203FA08  arm
 *   APP_ICON_LoadTouchBar  0x02027634  thumb
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   TCBL_Create  0x0203101C  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   ACTOR_TOOL_Create  0x02025318  thumb
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   ACTOR_TOOL_Delete 0x02025358 thumb
 *   ACTOR_TOOL_LoadCharPalAnm  0x02025470  thumb
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ACTOR_TOOL_LoadCharSimplePalAnm  0x020254BC  thumb
 *   ACTOR_TOOL_FreeChar 0x02025518 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   ARC_TOOL_GetMemberSize  0x020490A8  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BMP_Create  0x02043678  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   d_021BA80C     0x021BA80C  data  a2
 *   d_021BA814     0x021BA814  data  a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   SAVEDATA_PanicFail  0x02034714  arm
 *   PALANM_GetColor  0x02021F3C  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   d_021BABE0     0x021BABE0  data  a1
 *   d_021BA82C     0x021BA82C  data  a4
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatusByNetId 0x021583EC thumb ov010
 *   GAME_DATA_GetBattleRecSlotByNetId 0x021583CC thumb ov010
 *   d_021BA844     0x021BA844  data  a2
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   d_021BA854     0x021BA854  data  a4
 *   d_021BA84C     0x021BA84C  data  a4
 *   d_021BA804     0x021BA804  data  a4
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   BG_SYS_DrawTile  0x02041090  arm
 *   d_021BABE4     0x021BABE4  data  a1
 *   d_021BA8A0     0x021BA8A0  data  a4
 *   INTRUDE_COMM_HasUnlockFlags 0x02158590 thumb ov010
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   func_020355D8x 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 *   INTRUDE_COMM_AcceptSession 0x02175B4C thumb ov011
 *   INTRUDE_COMM_TakeJoinReply 0x021761EC thumb ov011
 *   INTRUDE_CMD_SendJoinRequest 0x02173E2C thumb ov011
 *   d_021BA87C 0x021BA87C data a4
 *   d_021BA85C 0x021BA85C data a1
 *   d_021BA862 0x021BA862 data a1
 *   d_021BAA4C 0x021BAA4C data a4
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   d_021BA8DC     0x021BA8DC  data  a4
 *   d_021BA8FC     0x021BA8FC  data  a4
 *   BMP_MENUWORK_LoadChar  0x0201F554  thumb
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   d_021BABF4     0x021BABF4  data  a1
 *   PRINTSYS_CTRL_Update  0x02028484  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   UI_GetInputMode  0x020355C4  arm
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   STRBUF_SetStringN  0x02045994  arm
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   d_021BA928 0x021BA928 data a4
 *   d_021BA948     0x021BA948  data  a4
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9F8     0x021BA9F8  data  a4
 *   d_021BA9C8     0x021BA9C8  data  a4
 *   d_021BA9A4     0x021BA9A4  data  a4
 *   d_021BA984 0x021BA984 data a4
 *   d_021BABF8     0x021BABF8  data  a1
 *   d_021BAA64     0x021BAA64  data  a4
 *   d_021BAA84     0x021BAA84  data  a4
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   d_021BAAA4     0x021BAAA4  data  a4
 *   d_021BAAB8     0x021BAAB8  data  ov071  a4
 *   d_021BAAD8     0x021BAAD8  data  ov071  a4
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   _ll_sdiv       0x0209BE5C  arm
 *   TOWN_MAP_SPOT_CountVisited  0x0216FEAC  thumb  ov010
 *   WORDSET_SetSlotFromMsgA0 0x0201F184 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   INTRUDE_GetFromSave 0x0200BE48 thumb
 *   INTRUDE_SetMonolithLevel 0x0200BF08 thumb
 *   GAME_DATA_GetOwnNetId 0x02012B58 thumb
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 *   INTRUDE_COMM_SendPairMessage 0x02174660 thumb ov011
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   KEY_GetCont 0x0203630C arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 *   d_021BAB28     0x021BAB28  data  ov071  a4
 *   d_021BAB48     0x021BAB48  data  ov071  a4
 *   d_021BAB68     0x021BAB68  data  a4
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   TOWN_MAP_SPOT_Classify  0x0216FE2C  thumb  ov010
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   d_021BAAF8     0x021BAAF8  data  a2
 *   gMonolithRowGridParam     0x021BAB10  data  a4
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BMP_OAM_SetPos  0x0202590C  thumb
 *   BMP_CopyPixels  0x02043814  arm
 *   gMonolithInfoBgTemplate0     0x021BAB94  data  a4
 *   gMonolithInfoBgTemplate2     0x021BABB4  data  a4
 *   INTRUDE_GetMonolithLevel  0x0200BF10  thumb
 */

struct Proc;
struct Ctx;
struct PrintSys;
struct Tcbl;
struct Node;
struct PalAnmSlot;
struct S020314B8;
struct DispConfig;
struct DispVram;
struct BgTemplate;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Bank;
struct Cfg;
struct Bitmap;
struct BmpOamGrid;
struct Sys;
struct Strbuf;
struct Actor;
struct Chan02021FD8;
struct TaskMenuRes;
struct TaskMenuState;
struct TaskMenu;
struct TaskMenuTmpl;
struct Rec3;
struct BmpWin;
struct Blk;
struct Vec2;
struct Sub0200852CObj;
struct BigObj;
struct Big;
struct Rec1B0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

#include "monolith_tool_types.h"

typedef struct {
    int topProc;
    int subProc;
} Pair;

/* CLACT system init config, same layout as arm9 struct SysInit. */
struct SysInit {
    short surface_pos[4];
    u8 oam_main_base;
    u8 oam_main_count;
    u8 oam_sub_base;
    u8 oam_sub_count;
    u32 n_transfers;
    u16 n_chars;
    u16 n_pltts;
    u16 n_cells;
    u16 n_spare;
    u16 n_main_blocks;
    u16 n_sub_blocks;
};

typedef signed int     s32;

typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } Slot;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

typedef signed short s16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct Pair {
    int x, y;
};

struct MonolithToolActorPos {
    s16 x;
    s16 y;
    u16 animSeq;
    u8 reserved6;
    u8 reserved7;
};

struct MonolithToolGridParam {
    void *bitmap;
    s16 x;
    s16 y;
    u32 palette;
    u32 reservedC;
    u8 reserved10;
    u8 reserved11;
    u16 subScreenA;
    u32 subScreenB;
};

typedef struct {
    u16 v;
    u8 state;
    u8 dir;
    u8 timer;
    u8 cnt;
    u8 pad[2];
} Ent;

struct MonolithToolIconPos {
    u16 x, y, animSeq, reserved6;
};

typedef enum { V4 = 4, V5 = 5 } Value;

struct MonolithToolCursorPos {
    u16 x, y, animSeq, reserved6;
};

typedef struct { void *text; u16 color; int flags; } Item;

/* Task menu template, same layout and field names as ov070 struct TaskMenuTmpl. */
struct TaskMenuTmpl {
    int heapId;
    u8 itemNum;
    u8 pad[3];
    void *items;
    int posType;
    u8 charPosX;
    u8 charPosY;
    u8 width;
    u8 height;
};

typedef signed char s8;

/* Hit area of one menu entry, passed to TOUCHPANEL_HitTrg. */
typedef struct {
    u8 hitBox[0x14];
} Menu;

typedef long long s64;

typedef enum { FALSE, TRUE } BoolFlag;

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void G2x_SetBlendAlpha_(u32, u32, u32, u32, u32);
extern void BMP_SetDisplaySwap(u32 a);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void *GPOWER_LoadPowerTable(u32 heap);
extern void *PROCSYS_Create(int heapId);
extern void PRINTSYS_CTRL_Init(u8 *p, u32 v);
extern u32 GFL_USE_AddMainTask(void (*cb)(void), void *arg, int pri);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 INTRUDE_COMM_SendBusyBegin(void);
extern u32 INTRUDE_COMM_SendBusyEnd(void);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 GAME_COMM_GetCounter(void *obj);
extern u32 GAME_COMM_GetKind(void *obj);
extern void PROCSYS_Push(int h, int id, int a, void *b);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern u32 PROCSYS_Main(void *h);
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void CLACT_DrawSystem(void);
extern void PROCSYS_Delete(struct S020314B8 *p);
extern void TCB_DeleteTask(struct Node *n);
extern void GPOWER_FreePowerTable(void *p);
extern void ARC_TOOL_DeleteHandle(void *a);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(u32 heap);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_Create(u16 heapId);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void MIi_CpuClear32(int, int, int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *, u32);
extern u32 PALANM_Delete(void *ctx);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_FreeLayerBuf(u32);
extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 BG_SYS_CreateRun(u32 layer, u32 size, u32 top);
extern void APP_ICON_LoadTouchBar(void *arc, int id, u32 heap, int base, u32 pal);
extern void BG_SYS_PushTile(u32 a);
extern void BG_SYS_DeleteHalf(u32, u32, u32);
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct Tcbl *);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern void BMP_OAM_DeleteSys(void *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void ACTOR_TOOL_Delete(void *);
extern void ACTOR_TOOL_FreeChar(u32, u32, u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct PalAnmSlot *);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern u32 GFL_HEAP_Free(void *p);
extern struct Bitmap *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern struct Actor *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern struct BmpOamGrid *BMP_OAM_Create(struct Sys *sys, const struct MonolithToolGridParam *param);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_PrintQue(struct PrintSys *printSys, struct Bitmap *bitmap, u32 x, u32 y, struct Strbuf *text, u32 font);
extern void STRBUF_Delete(struct Strbuf *vec);
extern void CLACT_DeleteActor(struct Actor *);
extern void BMP_OAM_Delete(struct BmpOamGrid *);
extern void BMP_Delete(struct Bitmap *);
extern void CLACT_SetActorDrawEnable(struct Actor *, u32);
extern void BMP_OAM_SetEnabled(u8 *, u32);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *, void *);
extern void BMP_OAM_UploadChars(struct BmpOamGrid *);
extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);
extern u16 PALANM_GetColor(int base, int idx, int which, u16 pos);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
extern int GAME_DATA_GetBattleRecSlotByNetId(void *a0, int a1);
extern void CLACT_SetActorAutoAnim(struct Actor *, unsigned int);
extern void CLACT_ChangeActorAnimSeq(struct Actor *p, u16 v);
extern void CLACT_SetActorPaletteOffset(struct Actor *o, u32 v, u32 flag);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, u32 font, u32 printQue, u16 heap);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *res);
extern void APP_TASKMENU_UpdateMenu(void *);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void BG_SYS_Delete(void);
extern void BMP_WIN_Init(u16 heapId);
extern void BMP_WIN_Exit(void);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern unsigned int PALANM_SetAutoTransfer(struct PalAnmSlot *slots, int v);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetTileEntry(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern u8 *ACTOR_TOOL_Create(u32 heapId, u8 bank0Count, u8 bank1Count);
extern void *BMP_OAM_CreateSys(unsigned int heapId, void *clact);
extern u32 ACTOR_TOOL_LoadCharPalAnm(u32 palSlots, u32 tool, u32 src, u32 resId, u32 bank, u32 len, u32 flags);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 ACTOR_TOOL_LoadCharSimplePalAnm(u32 palSlots, u32 tool, u32 src, u32 resId, u32 bank, u32 len, u32 flags);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_DrawTile(u32 index, u32 src, u32 dx, u32 dy, u8 cw, u8 ch);
extern int INTRUDE_COMM_HasUnlockFlags(void *);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_HitTrg(const void *);
extern void UI_SetInputMode(int);
extern void func_020355D8x(int);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern int INTRUDE_COMM_IsSessionActive(u8 *);
extern void INTRUDE_COMM_AcceptSession(u8 *,u8 *);
extern u8 INTRUDE_COMM_TakeJoinReply(char *p);
extern int INTRUDE_CMD_SendJoinRequest(char *a, int b);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void BMP_MENUWORK_LoadChar(u32 a, u32 b, u32 c, u32 d);
extern u8 BMP_MENUWORK_GetPlttFileId(int i);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 slot);
extern void *BMP_WIN_GetBmp(struct BmpWin *p);
extern void BMP_Clear(struct Bitmap *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct BmpWin *window);
extern void BMP_MENUWORK_DrawWindow(void *win, int commitMode, int tileBase, int palette);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *win, u32 x, u32 y, void *str, u32 font, u32 wait, void *tcbl, u32 priority, u32 heap, u32 fillColor);
extern s32 PRINTSYS_CTRL_Update(struct Blk *blk, void *h);
extern void BMP_WIN_TransferChars(struct BmpWin *d);
extern u32 BMP_WIN_Delete(struct BmpWin *d);
extern void CLACT_AddActorSurfacePos(struct Actor *p, const struct Vec2 *delta, u32 which);
extern u8 UI_GetInputMode(void);
extern const void *MYSTATUS_GetName(const void *p);
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);
extern u8 MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern unsigned int KEY_GetRepeat(void);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
extern void INTRUDE_COMM_SetWordSetRequest(MonolithToolSlotInfo *, void *, void *, int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int TOWN_MAP_SPOT_CountVisited(MonolithEntry *table, MonolithCounts *counts, u8 *rankData);
extern int TOUCHPANEL_GetCont(void);
extern u32 KEY_GetCont(void);
extern void WORDSET_SetSlotFromMsgA0(struct WordSet *p, u32 i, s32 v);
extern int INTRUDE_COMM_SendPairMessage(int,...);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern int GFL_USE_IsBgmPlaying(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *INTRUDE_GetFromSave(void *sys);
extern void INTRUDE_SetMonolithLevel(struct Rec1B0 *p, u32 v);
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
extern void GAME_COMM_PushPairMessage(u32,u32,u32);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern int TOWN_MAP_SPOT_Classify(MonolithEntry *table, int index, MonolithCounts *counts, u8 *rankData);
extern void PRINTSYS_PrintColor(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern void BG_SYS_FillTileMap(u8 layer, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern void BG_SYS_SetFlagField06(u32 layerBit);
extern void BG_SYS_ResetSlot(unsigned layer, unsigned axis, unsigned offset);
extern void BMP_OAM_SetPos(struct BmpOamGrid *grid, s16 x, s16 y);
extern void BMP_CopyPixels(struct Bitmap *dst, const struct Bitmap *src);
extern u8 INTRUDE_GetMonolithLevel(void *saveBlock);
extern const struct MonolithToolGridParam gMonolithRowGridParam;
extern const struct BgTemplate gMonolithInfoBgTemplate0;
extern const struct BgTemplate gMonolithInfoBgTemplate2;
int MONOLITH_TOOL_Init(struct Proc *ctx, int unused, MonolithToolSetup *setup);
int MONOLITH_TOOL_Main(int a, int *seq, void **pwk, MonolithToolWork *work);
int MONOLITH_TOOL_Exit(int a, int b, int c, MonolithToolWork *work);
void MONOLITH_TOOL_InitDisplay(void);
void MONOLITH_TOOL_DeleteBg(void);
void MONOLITH_TOOL_InitBmpWin(void);
void MONOLITH_TOOL_ExitBmpWin(void);
unsigned int MONOLITH_TOOL_InitPalAnm(MonolithToolWork *work);
void MONOLITH_TOOL_FreePalAnm(MonolithToolWork *work);
void MONOLITH_TOOL_InitBackgrounds(void);
void MONOLITH_TOOL_FreeBackgrounds(void);
void MONOLITH_TOOL_LoadGraphics(MonolithToolWork *work, MonolithToolWork *work2);
void MONOLITH_TOOL_FreeSubBgChar(MonolithToolWork *work);
void MONOLITH_TOOL_InitText(MonolithToolWork *work);
void MONOLITH_TOOL_FreeText(MonolithToolWork *work);
void MONOLITH_TOOL_InitActors(MonolithToolWork *work);
void MONOLITH_TOOL_FreeActors(MonolithToolWork *work);
void MONOLITH_TOOL_LoadActorResources(MonolithToolWork *work);
void MONOLITH_TOOL_FreeActorResources(MonolithToolWork *work);
void MONOLITH_TOOL_VBlankTask(void *unused, MonolithToolWork *work);
void MONOLITH_TOOL_LoadSlotRecords(MonolithToolWork *work, MonolithToolSetup *setup);
void MONOLITH_TOOL_CreateButton(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet);
void MONOLITH_TOOL_FreeButton(MonolithToolButton *button);
void MONOLITH_TOOL_SetButtonVisible(MonolithToolButton *button, int visible);
int MONOLITH_TOOL_IsButtonUploaded(MonolithToolWork *work, MonolithToolButton *button);
void MONOLITH_TOOL_HighlightButtonPulse(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void MONOLITH_TOOL_HighlightButtonFlash(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void MONOLITH_TOOL_SetButtonPulse(MonolithToolProcArgs *args, int pulse, int slot);
void MONOLITH_TOOL_SetButtonFlash(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_ResetHighlights(MonolithToolProcArgs *args);
u8 MONOLITH_TOOL_GetHighlightMode(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_UpdateHighlight(MonolithToolProcArgs *args, int slot);
void MONOLITH_TOOL_SetHighlightMode(MonolithToolProcArgs *args, int mode, int slot);
int MONOLITH_TOOL_GetHighlightColorA(unsigned int x);
int MONOLITH_TOOL_GetHighlightColorB(unsigned int x);
int MONOLITH_TOOL_GetHighlightColorCount(int slot);
void MONOLITH_TOOL_CreateLabel(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet);
void MONOLITH_TOOL_FreeLabel(MonolithToolLabel *label);
int MONOLITH_TOOL_UpdateLabel(MonolithToolWork *work, MonolithToolLabel *label);
void *MONOLITH_TOOL_GetTitleSpecies(MonolithToolProcArgs *args);
MonolithCounts *MONOLITH_TOOL_GetSlotIconStates(MonolithToolProcArgs *args);
int MONOLITH_TOOL_CreateSlotIcon(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex);
void MONOLITH_TOOL_DeleteSlotIcon(void *p);
void MONOLITH_TOOL_UpdateSlotIconState(void *p, MonolithCounts *counts, int i);
int MONOLITH_TOOL_CreateCursor(MonolithToolWork *work, const int *pos, int resIndex);
void MONOLITH_TOOL_DeleteCursor(void *p);
void MONOLITH_TOOL_CreateBlink(MonolithToolWork *work, MonolithToolBlink *blink);
void MONOLITH_TOOL_DeleteBlink(MonolithToolBlink *blink);
void MONOLITH_TOOL_UpdateBlink(MonolithToolBlink *p);
void MONOLITH_TOOL_StartBlink(MonolithToolBlink *blink);
int MONOLITH_TOOL_IsBlinkActive(MonolithToolBlink *blink);
struct Actor *MONOLITH_TOOL_CreateActorAt(MonolithToolWork *work, int x, int y, int animSeq);
void MONOLITH_TOOL_DeleteActorAt(void *p);
void MONOLITH_TOOL_Noop(void *a);
struct TaskMenuRes *MONOLITH_TOOL_CreateTaskMenuRes(u32 *p, int a, u16 heap);
void MONOLITH_TOOL_DeleteTaskMenuRes(void *p);
void *MONOLITH_TOOL_OpenTaskMenu(int *p, void *res, u32 heap);
void MONOLITH_TOOL_CloseTaskMenu(void *p);
int MONOLITH_TOOL_UpdateTaskMenu(MonolithToolWork *work, int unused, void *p, int *q);
void MONOLITH_TOOL_DrawSlotCounts(void *a, int flag, int bg);
int MONOLITH_TOOL_SLOT_SELECT_Init(void *ctx, int *state, MonolithToolProcArgs *args);
int MONOLITH_TOOL_SLOT_SELECT_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
int MONOLITH_TOOL_SLOT_SELECT_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds(void);
void MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds(void);
void MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(MonolithToolProcArgs *args, MonolithToolWork *work);
void MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(MonolithToolSlotSelect *screen, MonolithToolWork *work);
void MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_ShowMessage(MonolithToolSlotSelect *screen, MonolithToolWork *work, int msgId);
int MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(MonolithToolWork *work, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_HideMessage(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args);
void MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args);
void MONOLITH_TOOL_SLOT_SELECT_MoveCursor(MonolithToolSlotSelect *screen,int slot);
void MONOLITH_TOOL_SLOT_SELECT_CreateButtons(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_FreeButtons(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(MonolithToolProcArgs *args,MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_CreateCursor(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_FreeCursor(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(MonolithToolSlotSelect *screen);
void MONOLITH_TOOL_SLOT_SELECT_SetMode(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen, unsigned char mode);
int MONOLITH_TOOL_TITLE_Init(void *ctx, int *state, MonolithToolProcArgs *args);
int MONOLITH_TOOL_TITLE_Main(int unused,int *state,MonolithToolProcArgs *args,MonolithToolTitle *screen);
int MONOLITH_TOOL_TITLE_Exit(void *proc,int unused,MonolithToolProcArgs *args,MonolithToolTitle *screen);
void MONOLITH_TOOL_TITLE_InitBackgrounds(void);
void MONOLITH_TOOL_TITLE_FreeBackgrounds(void);
void MONOLITH_TOOL_TITLE_LoadGraphics(MonolithToolProcArgs *args,MonolithToolWork *work);
void MONOLITH_TOOL_TITLE_CreateSlotIcons(MonolithToolTitle *screen, MonolithToolProcArgs *args);
void MONOLITH_TOOL_TITLE_FreeSlotIcons(MonolithToolTitle *screen);
void MONOLITH_TOOL_TITLE_UpdateSlotIcons(MonolithToolTitle *screen,MonolithToolProcArgs *args);
int MONOLITH_TOOL_MENU_Create(struct Proc *ctx, int unused, MonolithToolProcArgs *args);
int MONOLITH_TOOL_MENU_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolMenu *screen);
int MONOLITH_TOOL_MENU_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_CreateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_FreeButtons(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_UpdateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_CreateCursor(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_FreeCursor(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_UpdateCursor(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_InitBackgrounds(void);
void MONOLITH_TOOL_MENU_FreeBackgrounds(void);
void MONOLITH_TOOL_MENU_CreateWindow(MonolithToolMenu *screen, MonolithToolWork *work);
void MONOLITH_TOOL_MENU_FreeWindow(MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_ShowMessage(MonolithToolMenu *screen, MonolithToolWork *work, unsigned msgId);
int MONOLITH_TOOL_MENU_IsMessageDone(MonolithToolWork *work, MonolithToolMenu *screen);
void MONOLITH_TOOL_MENU_HideMessage(MonolithToolMenu *screen);
int MONOLITH_TOOL_SUMMARY_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen);
int MONOLITH_TOOL_SUMMARY_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen);
int MONOLITH_TOOL_SUMMARY_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_InitBackgrounds(void);
void MONOLITH_TOOL_SUMMARY_FreeBackgrounds(void);
void MONOLITH_TOOL_SUMMARY_LoadGraphics(MonolithToolWork *work);
void MONOLITH_TOOL_SUMMARY_CreateWindows(int unused, MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_DeleteWindows(MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_CreateLabel(MonolithToolWork *work, MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_FreeLabel(MonolithToolSummary *screen);
void MONOLITH_TOOL_SUMMARY_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolSummary *screen, u8 *saveData, unsigned slot);
int MONOLITH_TOOL_STATS_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen);
int MONOLITH_TOOL_STATS_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen);
int MONOLITH_TOOL_STATS_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_InitBackgrounds(void);
void MONOLITH_TOOL_STATS_FreeBackgrounds(void);
void MONOLITH_TOOL_STATS_LoadGraphics(MonolithToolWork *work);
void MONOLITH_TOOL_STATS_CreateWindows(int unused, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_DeleteWindows(MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_CreateCursor(MonolithToolProcArgs *args, MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_FreeCursor(MonolithToolStats *screen);
void MONOLITH_TOOL_STATS_UpdateCursor(MonolithToolStats *screen);
int MONOLITH_TOOL_LIST_Init(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_LIST_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_LIST_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_InitBackgrounds(void);
void MONOLITH_TOOL_LIST_FreeBackgrounds(void);
void MONOLITH_TOOL_LIST_LoadGraphics(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeBgChar(MonolithListWork *work);
void MONOLITH_TOOL_LIST_InitWindows(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeWindows(MonolithListWork *work);
void MONOLITH_TOOL_LIST_DrawTitle(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_ShowMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
void MONOLITH_TOOL_LIST_ShowFormattedMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
int MONOLITH_TOOL_LIST_IsMessageDone(MonolithToolWork *toolWork, MonolithListWork *work);
void MONOLITH_TOOL_LIST_HideMessage(MonolithListWork *work);
void MONOLITH_TOOL_LIST_FitBackground(MonolithListWork *work);
void MONOLITH_TOOL_LIST_BuildEntryList(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_LIST_FreeEntryBitmaps(MonolithListWork *work);
int MONOLITH_TOOL_LIST_DrawEntryNames(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_CreateRowGrids(MonolithListWork *work, MonolithToolWork *toolWork);
void MONOLITH_TOOL_DeleteRowGrids(MonolithListWork *work);
void MONOLITH_TOOL_CreateBackButton(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_LIST_FreeBackButton(MonolithListWork *work);
void MONOLITH_TOOL_LIST_UpdateBackButton(MonolithToolWork *toolWork, MonolithListWork *work);
void MONOLITH_TOOL_CreateMarker(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_DeleteMarker(MonolithListWork *work);
void MONOLITH_TOOL_UpdateMarker(MonolithListWork *work);
void MONOLITH_TOOL_CreateScrollArrows(MonolithToolProcArgs *args, MonolithListWork *work);
void MONOLITH_TOOL_DeleteScrollArrows(MonolithListWork *work);
void MONOLITH_TOOL_UpdateScrollArrows(MonolithListWork *work);
int MONOLITH_TOOL_ProcessListInput(MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_SetCursor(MonolithListWork *work, int index, int inputMode);
void MONOLITH_TOOL_SetRowHighlight(MonolithListWork *work, int index, int palette);
void MONOLITH_TOOL_SetRowHighlightSelected(MonolithListWork *work, int index);
void MONOLITH_TOOL_SetRowHighlightNormal(MonolithListWork *work, int index);
void MONOLITH_TOOL_ClearPrevHighlight(MonolithListWork *work);
void MONOLITH_TOOL_ApplyCursorChange(MonolithToolProcArgs *args, MonolithListWork *work);
int MONOLITH_TOOL_ScrollBy(MonolithListWork *work, int delta);
void MONOLITH_TOOL_UpdateBgScroll(MonolithListWork *work);
void MONOLITH_TOOL_UpdateRows(MonolithListWork *work);
void MONOLITH_TOOL_TaskUploadRows(void *task, MonolithListWork *work);
int MONOLITH_TOOL_GetRowAtY(MonolithListWork *work, unsigned y);
int MONOLITH_TOOL_InitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int MONOLITH_TOOL_MainInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int MONOLITH_TOOL_ExitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
void MONOLITH_TOOL_SetupInfoBgs(void);
void MONOLITH_TOOL_HideInfoBgs(void);
void MONOLITH_TOOL_LoadInfoPalette(MonolithToolWork *toolWork);
void MONOLITH_TOOL_CreateInfoWindows(MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DeleteInfoWindows(MonolithInfoWork *work);
void MONOLITH_TOOL_DrawInfoHeader(MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DrawActiveEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
void MONOLITH_TOOL_DrawSelectedEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
extern Pair d_021BA774[];
extern char d_021BA7D4;
extern char d_021BA764;
extern char d_021BA794;
extern char d_021BA7B4;
extern struct SysInit gClActorInitParam;
extern const struct MonolithToolActorPos d_021BA80C;
extern const struct MonolithToolGridParam d_021BA814;
extern char d_021BABE0[];
extern const struct MonolithToolGridParam d_021BA82C;
extern struct MonolithToolIconPos d_021BA844;
extern const struct MonolithToolCursorPos d_021BA854;
extern const struct MonolithToolCursorPos d_021BA84C;
extern const struct MonolithToolCursorPos d_021BA804;
extern const char d_021BABE4[];
extern const struct Pair d_021BA8A0[];
extern const u32 d_021BA87C[];
extern const u8 d_021BA85C[],d_021BA862[][4];
extern const u32 d_021BAA4C[];
extern char d_021BA8DC[];
extern char d_021BA8FC[];
extern char d_021BABF4[];
extern const char d_021BA928[];
extern const char d_021BA948[];
extern unsigned d_021BA978[];
extern Menu d_021BA9F8[];
extern int d_021BA9C8[][4];
extern int d_021BA9A4[][3];
extern const char d_021BA984[];
extern char d_021BABF8[];
extern char d_021BAA64[];
extern char d_021BAA84[];
extern char d_021BAAA4[];
extern char d_021BAAB8[];
extern char d_021BAAD8[];
extern const u32 d_021BAAFC[];
extern char d_021BABFC[];
extern char d_021BAB28[];
extern char d_021BAB48[];
extern struct Config d_021BAB68;
extern u16 d_021BAAF8[];



int MONOLITH_TOOL_Init(struct Proc *ctx, int unused, MonolithToolSetup *setup)
{
    MonolithToolWork *work;


    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    G2x_SetBlendAlpha_(0x04000050, 4, 8, 0xF, 0xF);
    G2x_SetBlendAlpha_(0x04001050, 4, 8, 0xF, 0xF);
    BMP_SetDisplaySwap(1);
    GFL_HEAP_CreateChildHeap(1, 0x61, 0x70000);
    work = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolWork), 0x61);
    MI_CpuFill8(work, 0, sizeof(MonolithToolWork));
    work->selection.selected = MONOLITH_ENTRY_NONE;
    MONOLITH_TOOL_LoadSlotRecords(work, setup);
    work->archive = ARC_TOOL_CreateHandle(0x27, 0x61);
    MONOLITH_TOOL_InitDisplay();
    MONOLITH_TOOL_InitBmpWin();
    MONOLITH_TOOL_InitPalAnm(work);
    MONOLITH_TOOL_InitBackgrounds();
    MONOLITH_TOOL_LoadGraphics(work, work);
    MONOLITH_TOOL_InitText(work);
    MONOLITH_TOOL_InitActors(work);
    MONOLITH_TOOL_LoadActorResources(work);
    work->entryTable = GPOWER_LoadPowerTable(0x61);
    work->topProcSys = (int)PROCSYS_Create(0x61);
    work->subProcSys = (int)PROCSYS_Create(0x61);
    PRINTSYS_CTRL_Init(work->scratchList, 6);
    work->vblankTask = GFL_USE_AddMainTask((void (*)(void))MONOLITH_TOOL_VBlankTask, work, 0xA);
    GFL_NET_RestartWithDefaultTimeout(0, 0x61);
    work->procArgs.setup = setup;
    work->procArgs.work = work;
    work->procArgs.param = &work->selection;
    return 1;
}



int MONOLITH_TOOL_Main(int a, int *seq, void **pwk, MonolithToolWork *work)
{
    void *h;
    u8 *r;
    int s1;
    int s2;
    u8 k;

    h = (void *)GAMESYSTEM_GetGameComm(*pwk);
    r = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)h);
    switch (*seq) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 1:
        if (r == 0 || GFL_NET_ERR_GetErrorLevel() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyBegin() == 1)
            (*seq)++;
        break;
    case 2:
        if (WIPE_SYS_EndCheck() == 1)
            (*seq)++;
        break;
    case 3:
        if (GFL_NET_ERR_GetErrorLevel() != 0 || (r == 0 && GAME_COMM_GetCounter(h) != 0) || (r == 0 && GAME_COMM_GetKind(h) == 2))
            work->procArgs.abortRequested = 1;
        if (work->procArgs.abortRequested == 0) {
            if (work->topProcStarted == 0) {
                PROCSYS_Push(work->topProcSys, -1, d_021BA774[work->currentScreen].topProc, &work->procArgs);
                work->topProcStarted = 1;
            }
            if (work->subProcStarted == 0) {
                GF_FONT_SetTextColor(0xF, 2, 0);
                PROCSYS_Push(work->subProcSys, -1, d_021BA774[work->currentScreen].subProc, &work->procArgs);
                work->subProcStarted = 1;
            }
        }
        s2 = PROCSYS_Main((void *)work->subProcSys);
        k = work->procArgs.requestedScreen;
        if (k == 4 || (s2 != 1 && work->procArgs.abortRequested == 1)) {
            work->procArgs.topProcDone = 1;
        } else if (work->currentScreen != k && d_021BA774[work->currentScreen].topProc != d_021BA774[k].topProc) {
            work->procArgs.topProcDone = 1;
        }
        s1 = PROCSYS_Main((void *)work->topProcSys);
        if (s1 == 1 && s2 == 1)
            break;
        if (work->procArgs.abortRequested == 1 || work->procArgs.requestedScreen == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            work->currentScreen = work->procArgs.requestedScreen;
            if (s1 != 1) {
                work->topProcStarted = 0;
                work->procArgs.topProcDone = 0;
            }
            if (s2 != 1)
                work->subProcStarted = 0;
        }
        break;
    case 4:
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || GFL_NET_ERR_GetErrorLevel() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyEnd() == 1)
            (*seq)++;
        break;
    case 6:
        if (WIPE_SYS_EndCheck() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    TCBL_Main(work->taskList);
    PRINTSYS_QUE_Main(work->printSys);
    CLACT_DrawSystem();
    return 0;
}

/*
 * Byte-correct. Blocker: GPOWER_FreePowerTable (arm9 unlabelled tail-call stub,
 * the integrator's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: GFL_HEAP_Free 0x020307B0 arm):
 *   void GPOWER_FreePowerTable(void *p) { void GFL_HEAP_Free(void *); GFL_HEAP_Free(p); }
 */
int MONOLITH_TOOL_Exit(int a, int b, int c, MonolithToolWork *work)
{

    PROCSYS_Delete((struct S020314B8 *)work->topProcSys);
    PROCSYS_Delete((struct S020314B8 *)work->subProcSys);
    TCB_DeleteTask((struct Node *)work->vblankTask);
    GPOWER_FreePowerTable(work->entryTable);
    MONOLITH_TOOL_FreeActorResources(work);
    MONOLITH_TOOL_FreeActors(work);
    MONOLITH_TOOL_FreeText(work);
    MONOLITH_TOOL_FreeSubBgChar(work);
    MONOLITH_TOOL_FreeBackgrounds();
    MONOLITH_TOOL_FreePalAnm(work);
    MONOLITH_TOOL_ExitBmpWin();
    MONOLITH_TOOL_DeleteBg();
    ARC_TOOL_DeleteHandle(work->archive);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    PROCSYS_FreeProcWork((struct Proc *)a);
    GFL_HEAP_DeleteChecked(0x61);
    return 1;
}

void MONOLITH_TOOL_InitDisplay(void)
{

    BG_SYS_SetVramBanks((const struct DispVram *)(&d_021BA7D4));
    BG_SYS_Create(0x61);
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d_021BA764));
    MIi_CpuClear32(0, 0x06000000, 0x80000);
    MIi_CpuClear32(0, 0x06200000, 0x20000);
    MIi_CpuClear32(0, 0x06400000, 0x40000);
    MIi_CpuClear32(0, 0x06600000, 0x20000);
}



/*
 * Three ARM9 thunks that share a literal-pool tail-call shape.
 */
void MONOLITH_TOOL_DeleteBg(void)
{
    BG_SYS_Delete();
}



void MONOLITH_TOOL_InitBmpWin(void)
{
    BMP_WIN_Init(0x61);
}



void MONOLITH_TOOL_ExitBmpWin(void)
{
    BMP_WIN_Exit();
}



unsigned int MONOLITH_TOOL_InitPalAnm(MonolithToolWork *work)
{
    work->palAnm = PALANM_Create(0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 2, 0x1c0, 0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 3, 0x1c0, 0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 0, 0x1c0, 0x61);
    PALANM_AllocSlotBuffers(work->palAnm, 1, 0x1c0, 0x61);
    return PALANM_SetAutoTransfer(work->palAnm, 1);
}







void MONOLITH_TOOL_FreePalAnm(MonolithToolWork *work)
{
    PALANM_FreeSlotBuffers(work->palAnm, 2);
    PALANM_FreeSlotBuffers(work->palAnm, 3);
    PALANM_FreeSlotBuffers(work->palAnm, 0);
    PALANM_FreeSlotBuffers(work->palAnm, 1);
    PALANM_Delete(work->palAnm);
}



void MONOLITH_TOOL_InitBackgrounds(void)
{
    int i;

    BG_SYS_InitBgLayer((int)3, (const struct BgTemplate *)(&d_021BA794), (int)0);
    BG_SYS_InitBgLayer((int)7, (const struct BgTemplate *)(&d_021BA7B4), (int)0);
    BG_SYS_SetTileEntry(3, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(7, 0, 0, 0, 0x20, 0x20, 0x11);
    for (i = 0; i <= 7; i++) {
        BG_SYS_SetPlaneVisible((u8)i, (int)0);
    }
    BG_SYS_SetPlaneVisible((u8)3, (int)1);
    BG_SYS_SetPlaneVisible((u8)7, (int)1);
}







void MONOLITH_TOOL_FreeBackgrounds(void)
{
    BG_SYS_SetPlaneVisible(3, 0);
    BG_SYS_SetPlaneVisible(7, 0);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(7);
}








void MONOLITH_TOOL_LoadGraphics(MonolithToolWork *work, MonolithToolWork *work2)
{
    void *h;

    PALANM_LoadHandlePaletteToSlotAt(work2->palAnm, work2->archive, 0x10, 0x61, 0, 0x1c0, 0, 0);
    PALANM_LoadHandlePaletteToSlotAt(work2->palAnm, work2->archive, 0x11, 0x61, 1, 0x1c0, 0, 0);
    ARC_UTIL_UploadBgCharFromHandle(work2->archive, 0xf, 3, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgPaletteFromHandle(work2->archive, 0xa, 3, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgCharFromHandle(work2->archive, 0xe, 7, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgPaletteFromHandle(work2->archive, 4, 7, 0, 0, 1, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work2->palAnm, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    PALANM_LoadArcPaletteToSlotAt(work2->palAnm, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = ARC_TOOL_CreateHandle(0x53, 0x61);
    work->subBgCharOffset = BG_SYS_CreateRun(7, 0x80, 1);
    ARC_UTIL_UploadBgCharFromHandle(h, 0x1c, 7, work->subBgCharOffset, 0x80, 0, 0x61);
    APP_ICON_LoadTouchBar(h, 7, 0x61, work->subBgCharOffset, 0xc);
    PALANM_LoadHandlePaletteToSlot(work2->palAnm, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_PushTile(7);
    BG_SYS_PushTile(3);
    BG_SYS_PushTile(7);
}







void MONOLITH_TOOL_FreeSubBgChar(MonolithToolWork *work)
{
    BG_SYS_DeleteHalf(7, work->subBgCharOffset, 0x80);
}



void MONOLITH_TOOL_InitText(MonolithToolWork *work)
{
    GF_FONT_SetTextColor(0xf, 2, 0);
    work->taskList = TCBL_Create(0x61, 0x61, 4, 0x20);
    work->font = GF_FONT_Create(0x17, 0, 0, 0, 0x61);
    work->printSys = (struct PrintSys *)PRINTSYS_QUE_Create((void *)0x61);
    work->wordSet = WORDSET_CreateDefault(0x61);
    work->msgBank[0] = MSGDATA_CreateFromArchive(0, 2, 0x43, 0x61);
    work->msgBank[1] = MSGDATA_CreateFromArchive(0, 2, 0xa0, 0x61);
    work->msgBank[2] = MSGDATA_CreateFromArchive(0, 2, 0xa1, 0x61);
    work->msgBank[3] = MSGDATA_CreateFromArchive(0, 2, 0x45, 0x61);
}







void MONOLITH_TOOL_FreeText(MonolithToolWork *work)
{
    MSGDATA_Delete(work->msgBank[0]);
    MSGDATA_Delete(work->msgBank[1]);
    MSGDATA_Delete(work->msgBank[2]);
    MSGDATA_Delete(work->msgBank[3]);
    WORDSET_DeleteStrbufED04(work->wordSet);
    PRINTSYS_QUE_Clear(work->printSys);
    PRINTSYS_QUE_Delete(work->printSys);
    GF_FONT_Delete(work->font);
    TCBL_Destroy(work->taskList);
}



void MONOLITH_TOOL_InitActors(MonolithToolWork *work)
{
    struct SysInit s;

    s = gClActorInitParam;
    s.oam_main_base = 4;
    s.oam_main_count = 0x7c;
    s.oam_sub_base = 4;
    s.oam_sub_count = 0x7c;
    s.n_chars = 0x60;
    s.n_cells = 0x40;
    CLACT_InitSystem((const struct Cfg *)(&s), (u32)(&d_021BA7D4), 0x61);
    work->unitBank = CLACT_CreateUnit(0x60, 0, 0x61);
    CLACT_SetUnitDefaultRenderer(work->unitBank);
    work->actorTool = ACTOR_TOOL_Create(0x61, 0x10, 0x10);
    work->actorToolUnit = BMP_OAM_CreateSys(0x61, work->unitBank);
}







/*
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 */
void MONOLITH_TOOL_FreeActors(MonolithToolWork *work)
{
    BG_SYS_SetMainPlaneVisible(0x10, 0);
    BG_SYS_SetSubPlaneVisible(0x10, 0);
    BMP_OAM_DeleteSys(work->actorToolUnit);
    CLACT_DeleteUnit(work->unitBank);
    CLACT_ExitSystem();
    ACTOR_TOOL_Delete(work->actorTool);
}



void MONOLITH_TOOL_LoadActorResources(MonolithToolWork *work)
{
    void *tmp;
    int i;
    int flag;

    tmp = ARC_TOOL_CreateHandle(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        work->actorRes[i].charPalAnm = ACTOR_TOOL_LoadCharPalAnm((u32)work->palAnm, (u32)work->actorTool, (u32)work->archive, 3, flag, 3, 0x61);
        work->actorRes[i].cellRes = CLACT_RegisterCharacter(work->archive, 0, 1, flag, 0x61);
        work->actorRes[i].animRes = CLACT_RegisterCellAnim(work->archive, 1, 2, 0x61);
        work->actorRes[i].simplePalAnm = ACTOR_TOOL_LoadCharSimplePalAnm((u32)work->palAnm, (u32)work->actorTool, (u32)tmp, 5, flag, 1, 0x61);
    }
    ARC_TOOL_DeleteHandle(tmp);
}







/*
 * extent: two-byte alignment padding at 0x021B699A.
 * Enum counter preserves the first iteration's cmp/branch.
 */
void MONOLITH_TOOL_FreeActorResources(MonolithToolWork *work)
{
    Slot i;
    int flag;

    i = SLOT_FIRST;
    do {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        ACTOR_TOOL_FreeChar((u32)work->actorTool, work->actorRes[i].charPalAnm, flag);
        CLACT_ReleaseCharacter(work->actorRes[i].cellRes);
        CLACT_ReleaseCellAnim(work->actorRes[i].animRes);
        ACTOR_TOOL_FreeChar((u32)work->actorTool, work->actorRes[i].simplePalAnm, flag);
        i++;
    } while (i < SLOT_COUNT);
}






void MONOLITH_TOOL_VBlankTask(void *unused, MonolithToolWork *work)
{
    CLACT_VBlankSystem();
    PALANM_TransferPalettes(work->palAnm);
}







void MONOLITH_TOOL_LoadSlotRecords(MonolithToolWork *work, MonolithToolSetup *setup)
{
    MonolithToolSlotRecord *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (setup->useSlotRecords != 0) {
        tbl = ARC_TOOL_LoadMember(0x25, 0, 0x61);
        n = ARC_TOOL_GetMemberSize(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = setup->slotIndex[i];
            if (idx >= n) {
                idx = 0;
            }
            work->slotRecord[i] = tbl[idx];
        }
        GFL_HEAP_Free(tbl);
    }
}







/*
 * The 0/1 flag keeps its bne-to-one polarity only as an enum ternary
 * (a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md);
 * `case 2:` shares its arm with `default:` (the dead `cmp r6, #2; b`).
 */
void MONOLITH_TOOL_CreateButton(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet)
{
    struct MonolithToolActorPos pos = d_021BA80C;
    struct MonolithToolGridParam param = d_021BA814;
    u32 widthTiles;
    void *bitmap;
    void *text;
    void *expanded;
    int onSubScreen;

    switch (sizeClass) {
    case 0:
        widthTiles = 0x16;
        pos.animSeq = 0;
        param.x = x - 0x58;
        break;
    case 1:
        widthTiles = 0x12;
        pos.animSeq = 1;
        param.x = x - 0x48;
        break;
    case 2:
    default:
        widthTiles = 0xc;
        pos.animSeq = 8;
        param.x = x - 0x30;
        break;
    }
    bitmap = BMP_Create(widthTiles, 2, 0x20, 0x61);
    button->bitmap = bitmap;
    pos.x = x;
    pos.y = y;
    param.y = y - 8;
    param.bitmap = bitmap;
    param.palette = work->actorRes[resIndex].simplePalAnm;
    onSubScreen = resIndex == 0 ? B_FALSE : B_TRUE;
    param.subScreenB = onSubScreen;
    param.subScreenA = onSubScreen;
    button->actor = CLACT_CreateActor((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, &pos, onSubScreen, 0x61);
    button->grid = BMP_OAM_Create(work->actorToolUnit, &param);
    text = MSGDATA_AllocString(work->msgBank[3], msgId);
    if (wordSet) {
        expanded = STRBUF_Create(0x80, 0x61);
        WORDSET_CopyTaggedText(wordSet, expanded, text);
        PRINTSYS_PrintQue(work->printSys, button->bitmap, 0, 0, expanded, (u32)work->font);
        STRBUF_Delete(expanded);
    } else {
        PRINTSYS_PrintQue(work->printSys, button->bitmap, 0, 0, text, (u32)work->font);
    }
    STRBUF_Delete(text);
    button->on = 1;
}






void MONOLITH_TOOL_FreeButton(MonolithToolButton *button)
{
    CLACT_DeleteActor(button->actor);
    BMP_OAM_Delete(button->grid);
    BMP_Delete(button->bitmap);
    button->actor = 0;
    button->grid = 0;
    button->bitmap = 0;
}






/*
 * extent: two-byte alignment padding at 0x021B6B6E.
 */
void MONOLITH_TOOL_SetButtonVisible(MonolithToolButton *button, int visible)
{
    CLACT_SetActorDrawEnable(button->actor, visible);
    BMP_OAM_SetEnabled(button->grid, visible);
}






int MONOLITH_TOOL_IsButtonUploaded(MonolithToolWork *work, MonolithToolButton *button)
{
    if (button->on == 1) {
        if (PRINTSYS_QUE_IsExistTarget(work->printSys, button->bitmap) == 0) {
            BMP_OAM_UploadChars(button->grid);
            button->on = 0;
            return 1;
        }
    }
    return 0;
}



void MONOLITH_TOOL_HighlightButtonPulse(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == selected) {
            CLACT_SetActorPaletteOffset((struct Actor *)button[i].actor, 1, 1);
            MONOLITH_TOOL_SetHighlightMode(args, 1, slot);
        } else {
            CLACT_SetActorPaletteOffset((struct Actor *)button[i].actor, 0, 1);
        }
    }
    if (selected == 0xff) {
        MONOLITH_TOOL_SetHighlightMode(args, 0, slot);
    }
}



void MONOLITH_TOOL_HighlightButtonFlash(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == selected) {
            CLACT_SetActorPaletteOffset((struct Actor *)button[i].actor, 1, 1);
            MONOLITH_TOOL_SetHighlightMode(args, 2, slot);
        } else {
            CLACT_SetActorPaletteOffset((struct Actor *)button[i].actor, 0, 1);
        }
    }
}






void MONOLITH_TOOL_SetButtonPulse(MonolithToolProcArgs *args, int pulse, int slot)
{
    if (pulse == 1) {
        MONOLITH_TOOL_SetHighlightMode(args, 1, slot);
    } else {
        MONOLITH_TOOL_SetHighlightMode(args, 0, slot);
    }
}



void MONOLITH_TOOL_SetButtonFlash(MonolithToolProcArgs *args, int slot)
{
    MONOLITH_TOOL_SetHighlightMode(args, 2, slot);
}






void MONOLITH_TOOL_ResetHighlights(MonolithToolProcArgs *args) { int i; for(i=0;i<4;i++) MI_CpuFill8(&args->highlight[i],0,8); }







u8 MONOLITH_TOOL_GetHighlightMode(MonolithToolProcArgs *args, int slot)
{
    return args->highlight[slot].mode;
}







/*
 * sites to PALANM_GetColor stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } Slot;
 *   u16 PALANM_GetColor(Slot *s, int idx, int which, u16 pos)
 *   {
 *       if (which == 1) {
 *           return s[idx].a[pos];
 *       }
 *       if (which == 0) {
 *           return s[idx].b[pos];
 *       }
 *       return 0;
 *   }
 *
 * note 2026-10-05 (D8 lane16): witness PALANM_GetColor filed as src/matched/arm9/PALANM_GetColor.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
 */
void MONOLITH_TOOL_UpdateHighlight(MonolithToolProcArgs *args, int slot)
{
    MonolithToolHighlight *highlight;
    int firstColor, srcColor, colorCount;
    int i;
    int level;
    highlight = &args->highlight[slot];
    if (slot >= 4) {
        SAVEDATA_PanicFail(d_021BABE0, (int)0, d_021BABE0);
    }
    firstColor = MONOLITH_TOOL_GetHighlightColorA((int)slot);
    srcColor = MONOLITH_TOOL_GetHighlightColorB((int)slot);
    colorCount = MONOLITH_TOOL_GetHighlightColorCount(slot);
    switch (highlight->mode) {
    case 1:
        level = highlight->level;
        if (highlight->fadeDown == 0) {
            level += 0x80;
            if (level >= 0x1100) {
                level = 0x1000;
                highlight->fadeDown ^= 1;
            }
        } else {
            level -= 0x80;
            if (level <= 0) {
                level = 0x100;
                highlight->fadeDown ^= 1;
            }
        }
        highlight->level = level;
        for (i = 0; i < colorCount; i++) {
            PALANM_BlendChannel((struct Chan02021FD8 *)args->work->palAnm, (int)slot, (u16)(firstColor + i), (u16)1, level >> 8,
                          PALANM_GetColor((int)args->work->palAnm, slot, 1, srcColor + i));
        }
        break;
    case 2:
        if (highlight->timer == 0) {
            highlight->timer = 3;
            if (highlight->level == 0) {
                highlight->level = 0x1000;
            } else {
                highlight->level = 0;
                highlight->flashCount++;
                if (highlight->flashCount > 1) {
                    MONOLITH_TOOL_SetHighlightMode(args, 0, slot);
                }
            }
            for (i = 0; i < colorCount; i++) {
                PALANM_BlendChannel((struct Chan02021FD8 *)args->work->palAnm, (int)slot, (u16)(firstColor + i), (u16)1, highlight->level >> 8,
                              PALANM_GetColor((int)args->work->palAnm, slot, 1, srcColor + i));
            }
        } else {
            highlight->timer--;
        }
        break;
    }
}



void MONOLITH_TOOL_SetHighlightMode(MonolithToolProcArgs *args, int mode, int slot)
{
    MonolithToolHighlight *highlight;
    highlight = &args->highlight[slot];
    MI_CpuFill8(highlight, 0, 8);
    highlight->mode = mode;
    PALANM_BlendChannel((struct Chan02021FD8 *)args->work->palAnm, (int)slot, (u16)MONOLITH_TOOL_GetHighlightColorA(slot), (u16)MONOLITH_TOOL_GetHighlightColorCount(slot), 0, 0);
}






/*
 * Two bounded constant selectors and a constant return.
 */
int MONOLITH_TOOL_GetHighlightColorA(unsigned int x)
{
    return x <= 1 ? 0x32 : 0x12;
}







int MONOLITH_TOOL_GetHighlightColorB(unsigned int x)
{
    return x <= 1 ? 0x42 : 0x22;
}







int MONOLITH_TOOL_GetHighlightColorCount(int slot)
{
    return 3;
}







/*
 * The 0/1 flag is written in each if/else arm (param.f14 and param.f12 stores), so the
 * param address stays in r0 across the diamond and tail merging rebuilds the join. Callee
 * types from matched definitions (02043678 returns Bmp *, 020255A0 Grid *, 02045EC0 void *,
 * 020457B0 U16Vec *). Twin ov071 021B6A0C. final push 2026-10-05 G7L5.
 */
void MONOLITH_TOOL_CreateLabel(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet)
{
    struct MonolithToolGridParam param = d_021BA82C;
    void *bitmap;
    void *text;
    void *expanded;
    bitmap = BMP_Create(widthTiles, heightTiles, 0x20, 0x61);
    label->bitmap = bitmap;
    param.x = x - (widthTiles / 2) * 8;
    param.y = y - (heightTiles / 2) * 8;
    param.bitmap = bitmap;
    param.palette = work->actorRes[resIndex].simplePalAnm;
    if (resIndex == 0) {
        param.subScreenB = 0;
        param.subScreenA = 0;
    } else {
        param.subScreenB = 1;
        param.subScreenA = 1;
    }
    label->grid = BMP_OAM_Create(work->actorToolUnit, &param);
    text = MSGDATA_AllocString(work->msgBank[3], msgId);
    if (wordSet) {
        expanded = STRBUF_Create(0x80, 0x61);
        WORDSET_CopyTaggedText(wordSet, expanded, text);
        PRINTSYS_PrintQue(work->printSys, label->bitmap, 0, 0, expanded, (u32)work->font);
        STRBUF_Delete(expanded);
    } else {
        PRINTSYS_PrintQue(work->printSys, label->bitmap, 0, 0, text, (u32)work->font);
    }
    STRBUF_Delete(text);
    label->on = 1;
}






void MONOLITH_TOOL_FreeLabel(MonolithToolLabel *label) { BMP_OAM_Delete(label->grid); BMP_Delete(label->bitmap); label->grid = 0; label->bitmap = 0; }






int MONOLITH_TOOL_UpdateLabel(MonolithToolWork *work, MonolithToolLabel *label) { if(label->on==1) { if(PRINTSYS_QUE_IsExistTarget(work->printSys, label->bitmap)==0) { BMP_OAM_UploadChars(label->grid); label->on=0; return 1; } } return 0; }





void *MONOLITH_TOOL_GetTitleSpecies(MonolithToolProcArgs *args)
{
    MonolithToolSetup *setup = args->setup;
    return (void *)GAME_DATA_GetMyStatusByNetId(GAMESYSTEM_GetGameData(setup->gameCtx), setup->areaId);
}





MonolithCounts *MONOLITH_TOOL_GetSlotIconStates(MonolithToolProcArgs *args)
{
    MonolithToolSetup *setup = args->setup;
    return (void *)GAME_DATA_GetBattleRecSlotByNetId(GAMESYSTEM_GetGameData(setup->gameCtx), setup->areaId);
}






/*
 * The flag is a u16 local assigned from a ternary over enum constants: every
 * int-constant spelling (ternary, if/else, e != 0) is folded to a boolean and
 * comes out with the opposite branch polarity (beq to 0, not bne to 1).
 * const on d lets both d[] loads go ahead of the stores into s.
 */
int MONOLITH_TOOL_CreateSlotIcon(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex)
{
    struct MonolithToolIconPos iconPos;
    int actor;
    u16 onSubScreen;
    u8 *states;
    iconPos = d_021BA844;
    onSubScreen = resIndex == 0 ? B_FALSE : B_TRUE;
    iconPos.x = pos[0];
    iconPos.y = pos[1];
    states = counts->slotIconState;
    if (states[slot] == 1) {
        iconPos.animSeq = 5;
    }
    actor = (int)CLACT_CreateActor((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, &iconPos, onSubScreen, 0x61);
    if (states[slot] == 0) {
        CLACT_SetActorDrawEnable((struct Actor *)actor, 0);
    }
    CLACT_SetActorAutoAnim((struct Actor *)actor, 1);
    return actor;
}



/*
 * Tail call to CLACT_DeleteActor.
 */
void MONOLITH_TOOL_DeleteSlotIcon(void *p)
{
    CLACT_DeleteActor(p);
}





void MONOLITH_TOOL_UpdateSlotIconState(void *p, MonolithCounts *counts, int i) { Value v; if(counts->slotIconState[i]==1) v=V5; else if(counts->slotIconState[i]==2) v=V4; else {CLACT_SetActorDrawEnable(p,0);return;} CLACT_SetActorDrawEnable(p,1);CLACT_ChangeActorAnimSeq(p,v); }






int MONOLITH_TOOL_CreateCursor(MonolithToolWork *work, const int *pos, int resIndex)
{
    struct MonolithToolCursorPos cursorPos;
    int onSubScreen;
    cursorPos = d_021BA854;
    onSubScreen = 0;
    if (resIndex != 0)
        onSubScreen = 1;
    cursorPos.x = pos[0];
    cursorPos.y = pos[1];
    return (int)CLACT_CreateActor((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, &cursorPos, (u16)onSubScreen, 0x61);
}



void MONOLITH_TOOL_DeleteCursor(void *p)
{
    CLACT_DeleteActor(p);
}






void MONOLITH_TOOL_CreateBlink(MonolithToolWork *work, MonolithToolBlink *blink)
{
    struct MonolithToolCursorPos cursorPos;
    int actor;
    cursorPos = d_021BA84C;
    actor = (int)CLACT_CreateActor((void *)work->unitBank, work->actorRes[1].cellRes, work->actorRes[1].charPalAnm, work->actorRes[1].animRes, &cursorPos, 1, 0x61);
    CLACT_SetActorAutoAnim((struct Actor *)actor, 1);
    blink->actor = actor;
}



/*
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * CLACT_DeleteActor with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 */
void MONOLITH_TOOL_DeleteBlink(MonolithToolBlink *blink)
{
    CLACT_DeleteActor((void *)blink->actor);
}






void MONOLITH_TOOL_UpdateBlink(MonolithToolBlink *p)
{
    if (p->active == 1) {
        if (p->frame % 5 == 0) {
            CLACT_SetActorPaletteOffset((struct Actor *)p->actor, p->phase, 1);
            p->phase ^= 1;
            if (p->frame / 5 == 3)
                p->active = 0;
        }
        p->frame++;
    }
}






/*
 * Byte initialiser and its getter.
 */
void MONOLITH_TOOL_StartBlink(MonolithToolBlink *blink)
{
    blink->active = 1;
    blink->frame = 0;
    blink->phase = 1;
}






int MONOLITH_TOOL_IsBlinkActive(MonolithToolBlink *blink)
{
    return blink->active;
}






struct Actor *MONOLITH_TOOL_CreateActorAt(MonolithToolWork *work, int x, int y, int animSeq)
{
    struct MonolithToolCursorPos cursorPos;
    struct Actor *actor;
    cursorPos = d_021BA804;
    cursorPos.x = x;
    cursorPos.y = y;
    cursorPos.animSeq = animSeq;
    actor = CLACT_CreateActor((void *)work->unitBank, work->actorRes[1].cellRes, work->actorRes[1].charPalAnm, work->actorRes[1].animRes, &cursorPos, 1, 0x61);
    CLACT_SetActorAutoAnim(actor, 1);
    return actor;
}



/*
 * ARM9 tail call followed by an empty function.
 */
void MONOLITH_TOOL_DeleteActorAt(void *p)
{
    CLACT_DeleteActor(p);
}






void MONOLITH_TOOL_Noop(void *a)
{
}






struct TaskMenuRes *MONOLITH_TOOL_CreateTaskMenuRes(u32 *p, int a, u16 heap)
{
    return APP_TASKMENU_RES_Create((u8)a, 14, p[3], p[2], heap);
}



/*
 * Tail call to APP_TASKMENU_RES_Delete.
 */
void MONOLITH_TOOL_DeleteTaskMenuRes(void *p)
{
    APP_TASKMENU_RES_Delete(p);
}






void *MONOLITH_TOOL_OpenTaskMenu(int *work, void *res, u32 heap)
{
    Item it[2];
    struct TaskMenuTmpl t;
    void *menu;

    it[0].text = MSGDATA_AllocString((void *)work[0x28 / 4], 0x1e);
    it[1].text = MSGDATA_AllocString((void *)work[0x28 / 4], 0x1f);
    it[0].color = 0x39E0;
    it[1].color = 0x39E0;
    it[0].flags = 0;
    it[1].flags = 0;
    t.heapId = heap;
    t.itemNum = 2;
    t.items = it;
    t.posType = 0;
    t.charPosX = 0x18;
    t.charPosY = 0xc;
    t.width = 8;
    t.height = 3;
    menu = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), res);
    STRBUF_Delete(it[0].text);
    STRBUF_Delete(it[1].text);
    return menu;
}



/*
 * Tail call to APP_TASKMENU_CloseMenu.
 */
void MONOLITH_TOOL_CloseTaskMenu(void *menu)
{
    APP_TASKMENU_CloseMenu(menu);
}





int MONOLITH_TOOL_UpdateTaskMenu(MonolithToolWork *work, int unused, void *menu, int *outConfirmed) { APP_TASKMENU_UpdateMenu(menu); if(APP_TASKMENU_IsFinish(menu)==1) { *outConfirmed=APP_TASKMENU_GetCursorPos(menu)==0 ? 1 : 0;return 1;} return 0; }






void MONOLITH_TOOL_DrawSlotCounts(void *a, int flag, int bg)
{
    MonolithCounts *c;
    u16 *buf;
    int y;
    int n, m;
    int left, right;
    int i;

    c = MONOLITH_TOOL_GetSlotIconStates((MonolithToolProcArgs *)a);
    y = 0x14;
    if (flag) {
        y = 0xe;
    }
    n = c->current;
    m = c->limit;
    if (n == m) {
        left = 0x78;
        right = 0x78;
    } else {
        left = n * 0xf0 / (n + m);
        if (m > 0) {
            right = 0xf0 - left;
        } else {
            right = 0;
            left = 0xf0;
        }
    }
    if (n > 0 && left == 0) {
        right--;
    } else if (m > 0 && right == 0) {
        right++;
    }
    buf = GFL_HEAP_Alloc(0x61, 0x3c, 1, d_021BABE4, 0x474);
    for (i = 0; right > 0; i++) {
        if (right >= 8) {
            buf[i] = 1;
            right -= 8;
        } else {
            buf[i] = 9 - right;
            right = 0;
        }
    }
    for (; i < 30; i++) {
        buf[i] = 9;
    }
    for (i = 0; i < 30; i++) {
        buf[i] |= 0x1000;
    }
    BG_SYS_DrawTile((u8)bg, (u32)buf, (u8)1, (u8)y, 30, 1);
    GFL_HEAP_Free(buf);
}






int MONOLITH_TOOL_SLOT_SELECT_Init(void *ctx, int *state, MonolithToolProcArgs *args)
{
    MonolithToolSlotSelect *screen;

    switch (state[0]) {
    case 0:
        screen = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolSlotSelect), 0x61);
        MI_CpuFill8(screen, 0, sizeof(MonolithToolSlotSelect));
        screen->backMode = 0;
        MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds();
        MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(args, args->work);
        MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(screen, args->work);
        MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(screen, args);
        MONOLITH_TOOL_SLOT_SELECT_CreateButtons(args, screen);
        MONOLITH_TOOL_SLOT_SELECT_CreateCursor(args, screen);
        screen->cursorActor = (void *)MONOLITH_TOOL_CreateCursor(args->work, (const int *)&d_021BA8A0[args->param->slot], 1);
        state[0]++;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetSubPlaneVisible(0x10, 1);
        return 1;
    }
    return 0;
}





#pragma opt_lifetimes off





#pragma opt_common_subs off





int MONOLITH_TOOL_SLOT_SELECT_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
 u16 *nameDst;
 u16 *nameSrc;
 u8 *intrude;
 int keyState,touchResult,result;
 u32 slot;
 u8 nextSlot;
 const u8 *neighbors;
 intrude=(u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(args->setup->gameCtx));
 MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(screen,args); MONOLITH_TOOL_SLOT_SELECT_MoveCursor(screen,args->param->slot);MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(args,screen);MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(screen);
 if(args->abortRequested==1 && *state==3) return 1;
 switch(*state) {
 case 0:
  if(intrude!=0 && INTRUDE_COMM_IsSessionActive(intrude+0x1ac)==1) MONOLITH_TOOL_SLOT_SELECT_SetMode(args,screen,1);
  *state=1;break;
 case 1:
  if(INTRUDE_COMM_HasUnlockFlags(GAMESYSTEM_GetGameData(args->setup->gameCtx))==0) MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x16);
  else MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x12);
  ++*state;break;
 case 2:
  if(MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(args->work,screen)!=1) break;
  if(TOUCHPANEL_GetTrg()==0 && (KEY_GetTrg()&3)==0) break;
  MONOLITH_TOOL_SLOT_SELECT_HideMessage(screen);GFL_USE_PlaySeDefaultVolume(0x547);
  if(TOUCHPANEL_GetTrg()!=0) {screen->buttonHighlight=1;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0xff,3);}
  else {screen->buttonHighlight=0;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0,3);}
  if(screen->backMode==0) *state=3;else *state=4;
  break;
 case 3:
  keyState=KEY_GetTrg();touchResult=TOUCHPANEL_HitTrg(d_021BA87C);
  if(intrude!=0 && INTRUDE_COMM_IsSessionActive(intrude+0x1ac)==1) {MONOLITH_TOOL_SLOT_SELECT_SetMode(args,screen,1);screen->linkLost=1;*state=4;break;}
  if(keyState>0 && screen->buttonHighlight==1) {screen->buttonHighlight=0;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0,3);GFL_USE_PlaySeDefaultVolume(0x548);break;}
  if(keyState&0xf0) {
   nextSlot=0xff;
   for(slot=0;(slot<6)?1:0;slot++) if(d_021BA85C[slot]==args->param->slot) break;
   slot=args->param->slot;
   if(keyState&0x40) {neighbors=d_021BA862[slot];nextSlot=neighbors[0];}
   else if(keyState&0x80) {neighbors=d_021BA862[slot];nextSlot=neighbors[1];}
   else if(keyState&0x20) {neighbors=d_021BA862[slot];nextSlot=neighbors[2];}
   else if(keyState&0x10) {neighbors=d_021BA862[slot];nextSlot=neighbors[3];}
   if(nextSlot!=0xff) slot=nextSlot;
   args->param->slot=slot;GFL_USE_PlaySeDefaultVolume(0x548);
  }
  if(touchResult>=0 && touchResult<6) {args->param->slot=touchResult;screen->buttonHighlight=1;MONOLITH_TOOL_HighlightButtonPulse(args,&screen->button[0],1,0xff,3);GFL_USE_PlaySeDefaultVolume(0x548);break;}
  if(touchResult==6 || (keyState&1)) {
   UI_SetInputMode(touchResult==6);
   if(INTRUDE_COMM_HasUnlockFlags(GAMESYSTEM_GetGameData(args->setup->gameCtx))==0) {
    result=d_021BAA4C[args->param->slot];
    if(result!=2 && result!=1) {*state=9;break;}
   }
   MONOLITH_TOOL_HighlightButtonFlash(args,&screen->button[0],1,0,3);GFL_USE_PlaySeDefaultVolume(0x736);*state=5;
  } else if(touchResult==7 || (keyState&2)) {
   MONOLITH_TOOL_StartBlink(&screen->cursorBlink);UI_SetInputMode(touchResult==7);GFL_USE_PlaySeDefaultVolume(0x551);*state=11;
  }
  break;
 case 4: {
  int keyState4,touchResult4;
  keyState4=KEY_GetTrg();touchResult4=TOUCHPANEL_HitTrg(d_021BA87C);
  if(touchResult4==7 || (keyState4&2)) {func_020355D8x(touchResult4==7);GFL_USE_PlaySeDefaultVolume(0x551);*state=11;}
  break;}

 case 5:
  screen->joinRecord=args->work->slotRecord[d_021BAA4C[args->param->slot]];
  screen->playerGender=args->setup->playerGender;
  nameDst=screen->playerName;
  nameSrc=args->setup->playerName;
  for(slot=10;slot!=0;slot--) {*nameDst=*nameSrc;nameDst++;nameSrc++;}
  if(intrude!=0 && INTRUDE_CMD_SendJoinRequest((char *)intrude,(int)&screen->joinRecord)!=1) break;
  *state=6;break;
 case 6:
  if(intrude==0) {*state=3;break;}
  result=INTRUDE_COMM_TakeJoinReply((char *)(intrude+0x1ac));
  if(result==1) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x10);*state=7;}
  else if(result==2) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x11);*state=8;}
  else if(result==3) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x15);*state=8;}
  else if(result==4) {MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x14);*state=8;}
  break;
 case 7:case 8:
  if(MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(args->work,screen)!=1) break;
  if(*state==7) {
  } else if(*state==8) {
   if(TOUCHPANEL_GetTrg()==0 && !(KEY_GetTrg()&3)) break;
  } else break;
  if(*state==7 && intrude!=0 && INTRUDE_COMM_IsSessionActive(intrude+0x1ac)==0) break;
  MONOLITH_TOOL_SLOT_SELECT_HideMessage(screen);GFL_USE_PlaySeDefaultVolume(0x547);
  if(*state==7) {if(intrude!=0) INTRUDE_COMM_AcceptSession(intrude,intrude+0x1ac);screen->joined=1;*state=11;}
  else *state=11;
  break;
 case 9:MONOLITH_TOOL_SLOT_SELECT_ShowMessage(screen,args->work,0x17);++*state;break;
 case 10:
  if(MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(args->work,screen)==1 && (TOUCHPANEL_GetTrg()!=0 || (KEY_GetTrg()&3)!=0)) {MONOLITH_TOOL_SLOT_SELECT_HideMessage(screen);*state=3;}
  break;
 case 11:
  if(MONOLITH_TOOL_GetHighlightMode(args,3)==2) break;
  if(MONOLITH_TOOL_IsBlinkActive(&screen->cursorBlink)!=0) break;
  if(screen->joined==1) args->requestedScreen=4;else args->requestedScreen=0;
  return 1;
 }
 return 0;
}





#pragma opt_lifetimes reset





#pragma opt_common_subs reset






int MONOLITH_TOOL_SLOT_SELECT_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    if (PRINTSYS_QUE_IsFinished(args->work->printSys) == 0)
        return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    if (screen->msgPrinter != 0)
        PRINTSYS_PrintStreamDelete(screen->msgPrinter);
    if (screen->msgString != 0)
        STRBUF_Delete(screen->msgString);
    MONOLITH_TOOL_DeleteCursor(screen->cursorActor);
    MONOLITH_TOOL_SLOT_SELECT_FreeCursor(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeButtons(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(screen);
    MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds();
    PROCSYS_FreeProcWork(proc);
    return 1;
}






void MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BA8DC, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)d_021BA8FC, 0);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetPlaneVisible(5, 0);
}





void MONOLITH_TOOL_SLOT_SELECT_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(5,0); BG_SYS_SetPlaneVisible(6,0); BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(6); }





void MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(MonolithToolProcArgs *args, MonolithToolWork *work) {ARC_UTIL_UploadBgPaletteFromHandle(work->archive,6,6,0,0,1,0x61);MONOLITH_TOOL_DrawSlotCounts(args,1,6);BG_SYS_PushTile(6);}






void MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(MonolithToolSlotSelect *screen, MonolithToolWork *work)
{
    BMP_MENUWORK_LoadChar(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    screen->msgWindow = (void *)BMP_WIN_Create(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear(BMP_WIN_GetBmp(screen->msgWindow), 0xff);
    BMP_WIN_MakeScreen(screen->msgWindow);
    BMP_MENUWORK_DrawWindow(screen->msgWindow, 0, 1, 0xb);
}



void MONOLITH_TOOL_SLOT_SELECT_FreeMsgWindow(MonolithToolSlotSelect *screen)
{
    BMP_WIN_Delete(screen->msgWindow);
}






void MONOLITH_TOOL_SLOT_SELECT_ShowMessage(MonolithToolSlotSelect *screen, MonolithToolWork *work, int msgId)
{
    if (screen->msgPrinter != 0)
        SAVEDATA_PanicFail(d_021BABF4, 0, d_021BABF4);
    GF_FONT_SetTextColor(1, 2, 15);
    screen->msgString = MSGDATA_AllocString((void *)work->msgBank[3], msgId);
    screen->msgPrinter = PRINTSYS_PrintStream(screen->msgWindow, 0, 0, screen->msgString, (int)work->font, MSG_SPEED_GetWait(), (void *)work->taskList, 10, 0x61, 15);
    BG_SYS_SetPlaneVisible(5, 1);
}





int MONOLITH_TOOL_SLOT_SELECT_IsMessageDone(MonolithToolWork *work, MonolithToolSlotSelect *screen) { return PRINTSYS_CTRL_Update((struct Blk *)work->scratchList, screen->msgPrinter); }






void MONOLITH_TOOL_SLOT_SELECT_HideMessage(MonolithToolSlotSelect *screen)
{
    void *window;
    window = BMP_WIN_GetBmp(screen->msgWindow);
    if (screen->msgPrinter == 0)
        SAVEDATA_PanicFail(d_021BABF4, 0, d_021BABF4);
    PRINTSYS_PrintStreamDelete(screen->msgPrinter);
    screen->msgPrinter = 0;
    STRBUF_Delete(screen->msgString);
    screen->msgString = 0;
    BG_SYS_SetPlaneVisible(5, 0);
    BMP_Clear(window, 0xff);
    BMP_WIN_TransferChars(screen->msgWindow);
    GF_FONT_SetTextColor(15, 2, 0);
}



void MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args)
{
    int i;
    MonolithCounts *counts = MONOLITH_TOOL_GetSlotIconStates(args);
    for (i = 0; i < 6; i++) {
        int icon;
        unsigned recordIndex = d_021BAA4C[i];
        icon = MONOLITH_TOOL_CreateSlotIcon(args->work, counts, i, (const int *)&d_021BA8A0[recordIndex], 1);
        screen->slotIcon[i] = (void *)icon;
    }
}










void MONOLITH_TOOL_SLOT_SELECT_FreeSlotIcons(MonolithToolSlotSelect *screen) { int i; for(i=0;i<6;i++) MONOLITH_TOOL_DeleteSlotIcon(screen->slotIcon[i]); }










void MONOLITH_TOOL_SLOT_SELECT_UpdateSlotIcons(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args) { MonolithCounts *counts;int i;counts=MONOLITH_TOOL_GetSlotIconStates(args);for(i=0;i<6;i++)MONOLITH_TOOL_UpdateSlotIconState(screen->slotIcon[i],counts,i);}










void MONOLITH_TOOL_SLOT_SELECT_MoveCursor(MonolithToolSlotSelect *screen,int slot) { u16 pos[2];pos[0]=d_021BA8A0[slot].x;pos[1]=d_021BA8A0[slot].y;CLACT_AddActorSurfacePos(screen->cursorActor,(const struct Vec2 *)pos,1);}











void MONOLITH_TOOL_SLOT_SELECT_CreateButtons(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_ResetHighlights(args);
    MONOLITH_TOOL_CreateButton(args->work, &screen->button[0], 1, 1, 0x80, 0x90, 14, 0);
    if (UI_GetInputMode() == 0) {
        MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], 1, 0, 3);
    } else {
        MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], 1, 0xff, 3);
        screen->buttonHighlight = 1;
    }
    MONOLITH_TOOL_CreateButton(args->work, &screen->button[1], 1, 1, 0x80, 0x90, 15, 0);
    MONOLITH_TOOL_SetButtonVisible(&screen->button[1], 0);
}










void MONOLITH_TOOL_SLOT_SELECT_FreeButtons(MonolithToolSlotSelect *screen) { int i; for (i=0;i<2;i++) MONOLITH_TOOL_FreeButton(&screen->button[i]); }










void MONOLITH_TOOL_SLOT_SELECT_UpdateButtons(MonolithToolProcArgs *args,MonolithToolSlotSelect *screen) { int i; MONOLITH_TOOL_UpdateHighlight(args,3); for(i=0;i<2;i++) MONOLITH_TOOL_IsButtonUploaded(args->work,&screen->button[i]); }








/*
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x24).
 */
void MONOLITH_TOOL_SLOT_SELECT_CreateCursor(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_CreateBlink(args->work, &screen->cursorBlink);
}








/*
 * Tail call to MONOLITH_TOOL_DeleteBlink with the pointer advanced by 0x24.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/MONOLITH_TOOL_DeleteBlink.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void MONOLITH_TOOL_SLOT_SELECT_FreeCursor(MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_DeleteBlink(&screen->cursorBlink);
}








/*
 * Tail call to MONOLITH_TOOL_UpdateBlink((char *)p + 0x24).
 */
void MONOLITH_TOOL_SLOT_SELECT_UpdateCursor(MonolithToolSlotSelect *screen)
{
    MONOLITH_TOOL_UpdateBlink(&screen->cursorBlink);
}











void MONOLITH_TOOL_SLOT_SELECT_SetMode(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen, unsigned char mode)
{
    if (mode == 0) {
        MONOLITH_TOOL_SetButtonVisible(&screen->button[0], 1);
        MONOLITH_TOOL_SetButtonVisible(&screen->button[1], 0);
    } else {
        args->param->slot = 6;
        MONOLITH_TOOL_SetButtonVisible(&screen->button[0], 0);
        MONOLITH_TOOL_SetButtonVisible(&screen->button[1], 1);
    }
    screen->backMode = mode;
}








int MONOLITH_TOOL_TITLE_Init(void *ctx, int *state, MonolithToolProcArgs *args)
{
    MonolithToolTitle *screen;
    void *monsterName;
    void *name;
    int species;
    switch (*state) {
    case 0:
        screen = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolTitle), 0x61);
        MI_CpuFill8(screen, 0, sizeof(MonolithToolTitle));
        MONOLITH_TOOL_TITLE_InitBackgrounds();
        MONOLITH_TOOL_TITLE_LoadGraphics(args, args->work);
        species = (int)MONOLITH_TOOL_GetTitleSpecies(args);
        name = STRBUF_Create(8, 0x61);
        STRBUF_SetStringN(name, MYSTATUS_GetName((const void *)species), 8);
        WORDSET_SetSlotTag((struct WordSet *)args->work->wordSet, 0, name, MYSTATUS_GetOutfitVariant((const struct Sub0200852CObj *)species), 1, 2);
        STRBUF_Delete(name);
        MONOLITH_TOOL_CreateLabel(args->work, &screen->nameLabel, 0, 0x80, 0xc, 0x1e, 2, 0, (void *)args->work->wordSet);
        MONOLITH_TOOL_TITLE_CreateSlotIcons(screen, args);
        *state = *state + 1;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(2, 1);
        BG_SYS_SetMainPlaneVisible(0x10, 1);
        return 1;
    }
    return 0;
}










int MONOLITH_TOOL_TITLE_Main(int unused,int *state,MonolithToolProcArgs *args,MonolithToolTitle *screen) { if(args->topProcDone==1) return 1; MONOLITH_TOOL_UpdateLabel(args->work,&screen->nameLabel); MONOLITH_TOOL_TITLE_UpdateSlotIcons(screen,args); switch(*state) { case 0:return 0; default:return 0; } }










int MONOLITH_TOOL_TITLE_Exit(void *proc,int unused,MonolithToolProcArgs *args,MonolithToolTitle *screen) { if(PRINTSYS_QUE_IsFinished(args->work->printSys)==0) return 0; BG_SYS_SetMainVisiblePlanes(8); MONOLITH_TOOL_TITLE_FreeSlotIcons(screen); MONOLITH_TOOL_FreeLabel(&screen->nameLabel); MONOLITH_TOOL_TITLE_FreeBackgrounds(); PROCSYS_FreeProcWork(proc); return 1; }









void MONOLITH_TOOL_TITLE_InitBackgrounds(void) { BG_SYS_InitBgLayer(2,(const struct BgTemplate *)d_021BA928,0); BG_SYS_SetTileEntry(2,0,0,0,0x20,0x20,0x11); }









void MONOLITH_TOOL_TITLE_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(2, 0); BG_SYS_FreeLayerBuf(2); }









void MONOLITH_TOOL_TITLE_LoadGraphics(MonolithToolProcArgs *args,MonolithToolWork *work) { ARC_UTIL_UploadBgPaletteFromHandle(work->archive,11,2,0,0,1,0x61); MONOLITH_TOOL_DrawSlotCounts(args,0,2); BG_SYS_PushTile(2); }








void MONOLITH_TOOL_TITLE_CreateSlotIcons(MonolithToolTitle *screen, MonolithToolProcArgs *args)
{
    int i;
    MonolithCounts *counts = MONOLITH_TOOL_GetSlotIconStates(args);
    for (i = 0; i < 6; i++) {
        int icon;
        unsigned recordIndex = d_021BAA4C[i];
        icon = MONOLITH_TOOL_CreateSlotIcon(args->work, counts, i, (const int *)(d_021BA948 + recordIndex * 8), 0);
        screen->slotIcon[i] = (void *)icon;
    }
}









void MONOLITH_TOOL_TITLE_FreeSlotIcons(MonolithToolTitle *screen) { int i; for(i=0;i<6;i++) MONOLITH_TOOL_DeleteSlotIcon(screen->slotIcon[i]); }









void MONOLITH_TOOL_TITLE_UpdateSlotIcons(MonolithToolTitle *screen,MonolithToolProcArgs *args) { int i; MonolithCounts *counts; counts=MONOLITH_TOOL_GetSlotIconStates(args); for(i=0;i<6;i++) MONOLITH_TOOL_UpdateSlotIconState(screen->slotIcon[i],counts,i); }








int MONOLITH_TOOL_MENU_Create(struct Proc *ctx, int unused, MonolithToolProcArgs *args)
{
    void *gameData = GAMESYSTEM_GetGameData(args->setup->gameCtx);
    MonolithToolMenu *screen = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolMenu), 0x61);

    MI_CpuFill8(screen, 0, sizeof(MonolithToolMenu));
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(gameData), 0x980) == 0) {
        screen->kind = 2;
    } else if (args->setup->useSlotRecords == 1) {
        screen->kind = 1;
    } else {
        screen->kind = 0;
    }
    MONOLITH_TOOL_MENU_InitBackgrounds();
    MONOLITH_TOOL_MENU_CreateWindow(screen, args->work);
    MONOLITH_TOOL_MENU_CreateButtons(args, screen);
    MONOLITH_TOOL_MENU_CreateCursor(args, screen);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    return 1;
}










int MONOLITH_TOOL_MENU_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    u8 *saveData;
    int touchResult;
    u32 keys;
    int touch;

    saveData = (u8 *)INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(args->setup->gameCtx));
    MONOLITH_TOOL_MENU_UpdateButtons(args, screen);
    MONOLITH_TOOL_MENU_UpdateCursor(screen);
    if (args->abortRequested == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        touchResult = TOUCHPANEL_HitTrg(&d_021BA9F8[screen->kind]);
        if (touchResult != -1) {
            screen->selected = touchResult;
            screen->result = d_021BA9C8[screen->kind][touchResult];
            UI_SetInputMode(1);
            screen->touchArmed = 0;
            (*state)++;
            break;
        }
        keys = KEY_GetRepeat();
        touch = KEY_GetTrg();
        if (touch > 0 && screen->touchArmed == 1) {
            UI_SetInputMode(0);
            screen->touchArmed = 0;
            MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x548);
            break;
        }
        if (touch & 1) {
            screen->result = d_021BA9C8[screen->kind][screen->selected];
            (*state)++;
        } else if (touch & 2) {
            screen->result = 3;
            (*state)++;
        } else if (keys & 0x80) {
            screen->selected++;
            if (screen->selected >= d_021BA978[screen->kind]) {
                screen->selected = 0;
            }
            MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if (keys & 0x40) {
            screen->selected--;
            if (screen->selected < 0) {
                screen->selected = d_021BA978[screen->kind] - 1;
            }
            MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x548);
        }
        break;
    case 1:
        if (screen->result == 0) {
            if (args->setup->useSlotRecords == 0) {
                (*state)--;
                break;
            }
            if (saveData != 0 && INTRUDE_COMM_IsSessionActive(saveData + 0x1ac) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                MONOLITH_TOOL_MENU_ShowMessage(screen, args->work, 4);
                *state = 3;
                break;
            }
        }
        if (screen->result != 3) {
            MONOLITH_TOOL_HighlightButtonFlash(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            GFL_USE_PlaySeDefaultVolume(0x54c);
        } else {
            MONOLITH_TOOL_StartBlink(&screen->cursorBlink);
            GFL_USE_PlaySeDefaultVolume(0x551);
        }
        (*state)++;
        break;
    case 2:
        if (screen->result != 3) {
            if (MONOLITH_TOOL_GetHighlightMode(args, 3) != 2) {
                args->requestedScreen = screen->result + 1;
                return 1;
            }
        } else {
            if (MONOLITH_TOOL_IsBlinkActive(&screen->cursorBlink) == 0) {
                args->requestedScreen = screen->result + 1;
                return 1;
            }
        }
        break;
    case 3:
        if (MONOLITH_TOOL_MENU_IsMessageDone(args->work, screen) == 1) {
            if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 3) != 0) {
                MONOLITH_TOOL_MENU_HideMessage(screen);
                GFL_USE_PlaySeDefaultVolume(0x547);
                *state = 0;
            }
        }
        break;
    }
    return 0;
}








int MONOLITH_TOOL_MENU_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolMenu *screen)
{

    if (PRINTSYS_QUE_IsFinished(args->work->printSys) == 0) {
        return 0;
    }
    BG_SYS_SetSubVisiblePlanes(8);
    if (screen->messageBox != 0) {
        PRINTSYS_PrintStreamDelete(screen->messageBox);
    }
    if (screen->messageText != 0) {
        STRBUF_Delete(screen->messageText);
    }
    MONOLITH_TOOL_MENU_FreeButtons(screen);
    MONOLITH_TOOL_MENU_FreeCursor(screen);
    MONOLITH_TOOL_MENU_FreeWindow(screen);
    MONOLITH_TOOL_MENU_FreeBackgrounds();
    PROCSYS_FreeProcWork(proc);
    return 1;
}









void MONOLITH_TOOL_MENU_CreateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    unsigned i;
    unsigned kind;

    MONOLITH_TOOL_ResetHighlights(args);
    for (i = 0; i < d_021BA978[screen->kind]; i++) {
        kind = screen->kind;
        if (kind == 1) {
            MONOLITH_TOOL_CreateButton(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i + 1, 0);
        } else if (kind == 0) {
            MONOLITH_TOOL_CreateButton(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i + 2, 0);
        } else if (kind == 2) {
            MONOLITH_TOOL_CreateButton(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i == 0 ? 1 : 3, 0);
        }
    }
    if (UI_GetInputMode() == 0) {
        MONOLITH_TOOL_HighlightButtonPulse(args, &screen->button[0], d_021BA978[screen->kind], 0, 3);
        screen->touchArmed = 0;
    } else {
        screen->touchArmed = 1;
    }
}








void MONOLITH_TOOL_MENU_FreeButtons(MonolithToolMenu *screen) { unsigned i; for(i=0;i<d_021BA978[screen->kind];i++) MONOLITH_TOOL_FreeButton(&screen->button[i]); }







void MONOLITH_TOOL_MENU_UpdateButtons(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    unsigned i;

    MONOLITH_TOOL_UpdateHighlight(args, 3);
    for (i = 0; i < d_021BA978[screen->kind]; i++) {
        MONOLITH_TOOL_IsButtonUploaded(args->work, &screen->button[i]);
    }
}







/*
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x34).
 */
void MONOLITH_TOOL_MENU_CreateCursor(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    MONOLITH_TOOL_CreateBlink(args->work, &screen->cursorBlink);
}







void MONOLITH_TOOL_MENU_FreeCursor(MonolithToolMenu *screen)
{
    MONOLITH_TOOL_DeleteBlink(&screen->cursorBlink);
}







void MONOLITH_TOOL_MENU_UpdateCursor(MonolithToolMenu *screen)
{
    MONOLITH_TOOL_UpdateBlink(&screen->cursorBlink);
}








void MONOLITH_TOOL_MENU_InitBackgrounds(void) { BG_SYS_InitBgLayer(5,(const struct BgTemplate *)d_021BA984,0); BG_SYS_SetTileEntry(5,0,0,0,0x20,0x20,0x11); BG_SYS_SetPlaneVisible(5,0); }








void MONOLITH_TOOL_MENU_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(5, 0); BG_SYS_FreeLayerBuf(5); }







void MONOLITH_TOOL_MENU_CreateWindow(MonolithToolMenu *screen, MonolithToolWork *work)
{

    BMP_MENUWORK_LoadChar(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    screen->window = (void *)BMP_WIN_Create(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear((struct Bitmap *)((int)BMP_WIN_GetBmp((struct BmpWin *)screen->window)), 0xff);
    BMP_WIN_MakeScreen(screen->window);
    BMP_MENUWORK_DrawWindow(screen->window, 0, 1, 0xb);
}






/*
 * Tail call to BMP_WIN_Delete on the pointer loaded from offset 0x3c.
 */
void MONOLITH_TOOL_MENU_FreeWindow(MonolithToolMenu *screen)
{
    BMP_WIN_Delete(screen->window);
}






void MONOLITH_TOOL_MENU_ShowMessage(MonolithToolMenu *screen, MonolithToolWork *work, unsigned msgId)
{
    if (screen->messageBox != 0) {
        SAVEDATA_PanicFail(d_021BABF8, 0, d_021BABF8);
    }
    GF_FONT_SetTextColor(1, 2, 0xf);
    screen->messageText = MSGDATA_AllocString(work->msgBank[3], msgId);
    screen->messageBox = PRINTSYS_PrintStream(screen->window, 0, 0, (void *)screen->messageText, (unsigned)work->font, MSG_SPEED_GetWait(),
                           (void *)work->taskList, 10, 0x61, 0xf);
    BG_SYS_SetPlaneVisible(5, 1);
}








int MONOLITH_TOOL_MENU_IsMessageDone(MonolithToolWork *work, MonolithToolMenu *screen)
{
    return PRINTSYS_CTRL_Update((struct Blk *)work->scratchList, screen->messageBox);
}






void MONOLITH_TOOL_MENU_HideMessage(MonolithToolMenu *screen)
{
    unsigned r = (unsigned)BMP_WIN_GetBmp(screen->window);

    if (screen->messageBox == 0) {
        SAVEDATA_PanicFail(d_021BABF8, 0, d_021BABF8);
    }
    PRINTSYS_PrintStreamDelete(screen->messageBox);
    screen->messageBox = 0;
    STRBUF_Delete(screen->messageText);
    screen->messageText = 0;
    BG_SYS_SetPlaneVisible(5, 0);
    BMP_Clear((struct Bitmap *)r, 0xff);
    BMP_WIN_TransferChars(screen->window);
    GF_FONT_SetTextColor(0xf, 2, 0);
}






int MONOLITH_TOOL_SUMMARY_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    MonolithToolSummary *created;
    int busy;
    int i;

    switch (*state) {
    case 0:
        created = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolSummary), 0x61);
        MI_CpuFill8(created, 0, sizeof(MonolithToolSummary));
        MONOLITH_TOOL_SUMMARY_InitBackgrounds();
        MONOLITH_TOOL_SUMMARY_LoadGraphics(args->work);
        MONOLITH_TOOL_SUMMARY_CreateWindows((int)args->work, created);
        MONOLITH_TOOL_SUMMARY_CreateLabel(args->work, created);
        created->shownSlot = 0xff;
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *printSys = args->work->printSys;
            if (screen->text[i].on != 0) {
                if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)((unsigned)BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                    BMP_WIN_TransferChars(screen->text[i].window);
                    screen->text[i].on = 0;
                }
            }
            if ((!screen->text[i].on) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(0, 1);
            BG_SYS_SetPlaneVisible(2, 1);
            BG_SYS_SetMainPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * Both tail returns are 0; the load of *p survives only through a
 * `switch` with a `default`, and `(!s[0xc]) == 1` keeps the boolean.
 */
int MONOLITH_TOOL_SUMMARY_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    int saveData;
    int idleCount;
    int i;

    saveData = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(args->setup->gameCtx));
    idleCount = 0;
    if (args->topProcDone == 1) {
        return 1;
    }
    MONOLITH_TOOL_UpdateLabel(args->work, &screen->nameLabel);
    for (i = 0; i < 2; i++) {
        void *printSys = args->work->printSys;
        if (screen->text[i].on != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)((unsigned)BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                BMP_WIN_TransferChars(screen->text[i].window);
                screen->text[i].on = 0;
            }
        }
        if ((!screen->text[i].on) == 1) {
            idleCount++;
        }
    }
    if (idleCount == 2) {
        unsigned slot = args->param->slot;
        if (screen->shownSlot != slot) {
            MONOLITH_TOOL_SUMMARY_Draw(args, args->work, screen, (u8 *)saveData, slot);
            screen->shownSlot = args->param->slot;
        }
    }
    switch (*state) {
    case 0:
        return 0;
    default:
        return 0;
    }
}







int MONOLITH_TOOL_SUMMARY_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    if (PRINTSYS_QUE_IsFinished(args->work->printSys) == 0) return 0;
    BG_SYS_SetMainVisiblePlanes(8);
    MONOLITH_TOOL_SUMMARY_DeleteWindows(screen);
    MONOLITH_TOOL_SUMMARY_FreeBackgrounds();
    MONOLITH_TOOL_SUMMARY_FreeLabel(screen);
    PROCSYS_FreeProcWork(proc);
    return 1;
}






void MONOLITH_TOOL_SUMMARY_InitBackgrounds(void)
{

    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)d_021BAA64, 0);
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)d_021BAA84, 0);
    BG_SYS_SetTileEntry(0, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
}







void MONOLITH_TOOL_SUMMARY_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(0,0); BG_SYS_SetPlaneVisible(2,0); BG_SYS_FreeLayerBuf(0); BG_SYS_FreeLayerBuf(2); }






void MONOLITH_TOOL_SUMMARY_LoadGraphics(MonolithToolWork *work) { ARC_UTIL_UploadBgPaletteFromHandle(work->archive,12,2,0,0,1,0x61); BG_SYS_PushTile(0); BG_SYS_PushTile(2); }





void MONOLITH_TOOL_SUMMARY_CreateWindows(int unused, MonolithToolSummary *screen)
{
    int i;

    screen->window[0] = (void *)BMP_WIN_Create(0, 2, 0, 0x1c, 3, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[0]);
    BMP_WIN_MakeScreen(screen->window[0]);
    screen->window[1] = (void *)BMP_WIN_Create(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[1]);
    BMP_WIN_MakeScreen(screen->window[1]);
    for (i = 0; i < 2; i++) {
        screen->text[i].window = screen->window[i];
        screen->text[i].on = 0;
    }
    BG_SYS_PushTile(0);
}






void MONOLITH_TOOL_SUMMARY_DeleteWindows(MonolithToolSummary *screen) { BMP_WIN_Delete(screen->window[0]); BMP_WIN_Delete(screen->window[1]); }






void MONOLITH_TOOL_SUMMARY_CreateLabel(MonolithToolWork *work, MonolithToolSummary *screen) { MONOLITH_TOOL_CreateLabel(work, &screen->nameLabel, 1, 0x80, 0xb4, 0x1c, 2, 0x13, 0); }





/*
 * Tail call to MONOLITH_TOOL_FreeLabel((char *)p + 0x18).
 */
void MONOLITH_TOOL_SUMMARY_FreeLabel(MonolithToolSummary *screen)
{
    MONOLITH_TOOL_FreeLabel(&screen->nameLabel);
}





/*
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 */
void MONOLITH_TOOL_SUMMARY_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolSummary *screen, u8 *saveData, unsigned slot)
{
    void *numberText;
    u8 *src;
    MonolithToolSlotInfo *info;
    u32 detailId;
    void *labelText;
    void *detailText;
    void *printSys;

    numberText = STRBUF_Create(0x100, 0x61);
    BMP_Clear(BMP_WIN_GetBmp(screen->window[0]), 0);
    BMP_Clear(BMP_WIN_GetBmp(screen->window[1]), 0);
    if (slot == 6 && saveData != 0 && INTRUDE_COMM_IsSessionActive(saveData + 0x1AC) == 1) {
        info = (MonolithToolSlotInfo *)INTRUDE_COMM_GetActiveSessionRequest(saveData + 0x1AC);
        src = (u8 *)info + 0x18;
    } else {
        if (slot > 6) {
            slot = 0;
        }
        info = (MonolithToolSlotInfo *)&work->slotRecord[d_021BAA4C[slot]];
        src = (u8 *)args->setup + 0x18;
    }
    detailId = info->detailId;
    labelText = MSGDATA_AllocString(work->msgBank[0], info->labelId);
    detailText = MSGDATA_AllocString(work->msgBank[0], detailId);
    INTRUDE_COMM_SetWordSetRequest(info, src, work->wordSet, 0x61);
    WORDSET_CopyTaggedText(work->wordSet, numberText, detailText);
    printSys = work->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(screen->text[0].window), 0, 4, labelText, (u32)work->font);
    screen->text[0].on = 1;
    printSys = work->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(screen->text[1].window), 0, 0, numberText, (u32)work->font);
    screen->text[1].on = 1;
    STRBUF_Delete(labelText);
    STRBUF_Delete(detailText);
    STRBUF_Delete(numberText);
}





/*
 * Twin of MONOLITH_TOOL_SUMMARY_Create (six handle slots at +0x18 instead of two at +8).
 */
int MONOLITH_TOOL_STATS_Create(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    MonolithToolStats *created;
    int busy;
    int i;

    switch (*state) {
    case 0:
        created = PROCSYS_AllocProcWork(ctx, sizeof(MonolithToolStats), 0x61);
        MI_CpuFill8(created, 0, sizeof(MonolithToolStats));
        MONOLITH_TOOL_STATS_InitBackgrounds();
        MONOLITH_TOOL_STATS_LoadGraphics(args->work);
        MONOLITH_TOOL_STATS_CreateWindows((int)args->work, created);
        MONOLITH_TOOL_STATS_CreateCursor(args, created);
        MONOLITH_TOOL_STATS_Draw(args, args->work, created);
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *printSys = args->work->printSys;
            if (screen->text[i].on != 0) {
                if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)((unsigned)BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                    BMP_WIN_TransferChars(screen->text[i].window);
                    screen->text[i].on = 0;
                }
            }
            if ((!screen->text[i].on) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(4, 1);
            BG_SYS_SetPlaneVisible(6, 1);
            BG_SYS_SetSubPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}





/*
 * `UI_SetInputMode(0)`/`UI_SetInputMode(1)` in the arms of `if (t & 2)`: the
 * two calls tail-merge into one `blx` with the then-arm's `movs r0, #0`
 * falling through; every ternary or `!` spelling of the argument emits
 * `bne` to the 1 instead (same size, polarity flipped).
 */
int MONOLITH_TOOL_STATS_Update(int unused, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    int i;
    int touch;

    if (args->abortRequested == 1) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        void *printSys = args->work->printSys;
        if (screen->text[i].on != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)((unsigned)BMP_WIN_GetBmp(screen->text[i].window))) == 0) {
                BMP_WIN_TransferChars(screen->text[i].window);
                screen->text[i].on = 0;
            }
        }
    }
    MONOLITH_TOOL_STATS_UpdateCursor(screen);
    switch (*state) {
    case 0:
        touch = KEY_GetTrg();
        if (TOUCHPANEL_HitTrg(d_021BAAA4) != -1 || (touch & 2) != 0) {
            MONOLITH_TOOL_StartBlink(&screen->cursorBlink);
            if (touch & 2) {
                UI_SetInputMode(0);
            } else {
                UI_SetInputMode(1);
            }
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = *state + 1;
        }
        break;
    case 1:
        if (MONOLITH_TOOL_IsBlinkActive(&screen->cursorBlink) == 0) {
            args->requestedScreen = 0;
            return 1;
        }
        break;
    }
    return 0;
}






int MONOLITH_TOOL_STATS_Destroy(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    if (PRINTSYS_QUE_IsFinished(args->work->printSys) == 0) return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    MONOLITH_TOOL_STATS_FreeCursor(screen);
    MONOLITH_TOOL_STATS_DeleteWindows(screen);
    MONOLITH_TOOL_STATS_FreeBackgrounds();
    PROCSYS_FreeProcWork(proc);
    return 1;
}







void MONOLITH_TOOL_STATS_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021BAAB8, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)d_021BAAD8, 0);
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
}






void MONOLITH_TOOL_STATS_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(4,0); BG_SYS_SetPlaneVisible(6,0); BG_SYS_FreeLayerBuf(4); BG_SYS_FreeLayerBuf(6); }






void MONOLITH_TOOL_STATS_LoadGraphics(MonolithToolWork *work) { ARC_UTIL_UploadBgPaletteFromHandle(work->archive,5,6,0,0,1,0x61); BG_SYS_PushTile(6); BG_SYS_PushTile(4); }




/*
 * Six-window twin of MONOLITH_TOOL_SUMMARY_CreateWindows.
 */
void MONOLITH_TOOL_STATS_CreateWindows(int unused, MonolithToolStats *screen)
{
    int i;

    screen->window[0] = (void *)BMP_WIN_Create(4, 2, 0x0, 0x1e, 0x3, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[0]);
    BMP_WIN_MakeScreen(screen->window[0]);
    screen->window[1] = (void *)BMP_WIN_Create(4, 2, 0x5, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[1]);
    BMP_WIN_MakeScreen(screen->window[1]);
    screen->window[2] = (void *)BMP_WIN_Create(4, 2, 0x8, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[2]);
    BMP_WIN_MakeScreen(screen->window[2]);
    screen->window[3] = (void *)BMP_WIN_Create(4, 2, 0xe, 0x1e, 0x4, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[3]);
    BMP_WIN_MakeScreen(screen->window[3]);
    screen->window[4] = (void *)BMP_WIN_Create(4, 2, 0x10, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[4]);
    BMP_WIN_MakeScreen(screen->window[4]);
    screen->window[5] = (void *)BMP_WIN_Create(4, 2, 0x12, 0x1e, 0x2, 0xd, 1);
    BMP_WIN_TransferChars((struct BmpWin *)screen->window[5]);
    BMP_WIN_MakeScreen(screen->window[5]);
    for (i = 0; i < 6; i++) {
        screen->text[i].window = screen->window[i];
        screen->text[i].on = 0;
    }
    BG_SYS_PushTile(4);
}






void MONOLITH_TOOL_STATS_DeleteWindows(MonolithToolStats *screen) { int i; for (i=0;i<6;i++) BMP_WIN_Delete(screen->window[i]); }







static inline void drawText(MonolithToolWork *work, void *window, u32 x, u32 y, void *text)
{
    void *printSys = work->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(window), x, y, text, (u32)work->font);
}







/*
 * Each window draw is a `static inline` (drawText) whose `printSys` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 */
void MONOLITH_TOOL_STATS_Draw(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolStats *screen)
{
    MonolithCounts *counts;
    s64 seconds;
    u32 hours;
    u32 minutes;
    void *labelText;
    void *lineText;

    MONOLITH_TOOL_GetTitleSpecies(args);
    counts = MONOLITH_TOOL_GetSlotIconStates(args);
    labelText = STRBUF_Create(0x100, 0x61);
    lineText = STRBUF_Create(0x100, 0x61);
    MSGDATA_ReadString(work->msgBank[3], 0xd, labelText);
    drawText(work, screen->text[0].window, 0, 4, labelText);
    screen->text[0].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 5, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, counts->limit + counts->current, 5, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[1].window, 0, 0, lineText);
    screen->text[1].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 9, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, counts->limit, 4, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[2].window, 0, 0, lineText);
    screen->text[2].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 8, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, counts->current, 4, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[2].window, 0x78, 0, lineText);
    screen->text[2].on = 1;
    seconds = args->setup->playSeconds;
    hours = seconds / 60 / 60;
    if (hours > 999) {
        hours = 999;
        minutes = 59;
    } else {
        seconds -= hours * 3600;
        minutes = seconds / 60;
    }
    MSGDATA_ReadString(work->msgBank[3], 0xb, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, hours, 3, 1, 1);
    WORDSET_SetSlotNumber(work->wordSet, 1, minutes, 2, 2, 1);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[3].window, 0, 0, lineText);
    screen->text[3].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 0xc, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, args->setup->recordCount, 5, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[4].window, 0, 0, lineText);
    screen->text[4].on = 1;
    MSGDATA_ReadString(work->msgBank[3], 0xa, labelText);
    WORDSET_SetSlotNumber(work->wordSet, 0, TOWN_MAP_SPOT_CountVisited(work->entryTable, MONOLITH_TOOL_GetSlotIconStates(args), args->setup->rankData), 4, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, lineText, labelText);
    drawText(work, screen->text[5].window, 0, 0, lineText);
    screen->text[5].on = 1;
    STRBUF_Delete(labelText);
    STRBUF_Delete(lineText);
}




/*
 * Tail call to MONOLITH_TOOL_CreateBlink(word at 0x4, a + 0x48).
 */
void MONOLITH_TOOL_STATS_CreateCursor(MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    MONOLITH_TOOL_CreateBlink(args->work, &screen->cursorBlink);
}




/*
 * Tail call to MONOLITH_TOOL_DeleteBlink with the pointer advanced by 0x48.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/MONOLITH_TOOL_DeleteBlink.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void MONOLITH_TOOL_STATS_FreeCursor(MonolithToolStats *screen)
{
    MONOLITH_TOOL_DeleteBlink(&screen->cursorBlink);
}




/*
 * Tail call to MONOLITH_TOOL_UpdateBlink((char *)p + 0x48).
 */
void MONOLITH_TOOL_STATS_UpdateCursor(MonolithToolStats *screen)
{
    MONOLITH_TOOL_UpdateBlink(&screen->cursorBlink);
}







int MONOLITH_TOOL_LIST_Init(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work)
{
    int busy;
    struct PrintSys *printSys;
    Bool finished;

    switch (*state) {
    case 0:
        work = PROCSYS_AllocProcWork(proc, sizeof(MonolithListWork), 0x61);
        MI_CpuFill8(work, 0, sizeof(MonolithListWork));
        work->scrollPos = 0x800;
        work->chosenEntry = MONOLITH_CURSOR_NONE;
        work->prevCursor = MONOLITH_CURSOR_NONE;
        work->lastCursor = MONOLITH_CURSOR_NONE;
        MONOLITH_TOOL_ResetHighlights(args);
        work->entryNameBank = MSGDATA_CreateFromArchive(0, 2, 0xa0, 0x61);
        MONOLITH_TOOL_LIST_InitBackgrounds();
        MONOLITH_TOOL_LIST_LoadGraphics(work, args->work);
        MONOLITH_TOOL_LIST_InitWindows(work, args->work);
        MONOLITH_TOOL_UpdateBgScroll(work);
        MONOLITH_TOOL_CreateMarker(args, work);
        MONOLITH_TOOL_CreateRowGrids(work, args->work);
        MONOLITH_TOOL_CreateBackButton(args, work);
        MONOLITH_TOOL_CreateScrollArrows(args, work);
        MONOLITH_TOOL_LIST_DrawTitle(args, work);
        work->taskMenuUnit = MONOLITH_TOOL_CreateTaskMenuRes((u32 *)args->work, 4, 0x61);
        args->param->selected = MONOLITH_ENTRY_NONE;
        work->task = GFL_USE_AddMainTask((void (*)(void))MONOLITH_TOOL_TaskUploadRows, work, 3);
        MONOLITH_TOOL_LIST_BuildEntryList(args, work, args->work);
        MONOLITH_TOOL_LIST_FitBackground(work);
        *state = *state + 1;
        break;
    case 1:
        if (MONOLITH_TOOL_LIST_DrawEntryNames(work, args->work) == 1) {
            MONOLITH_TOOL_UpdateRows(work);
            work->uploadPending = 1;
            if (UI_GetInputMode() == 0) {
                MONOLITH_TOOL_SetCursor(work, 1, 0);
            } else {
                MONOLITH_TOOL_SetCursor(work, MONOLITH_CURSOR_NONE, 0);
            }
            *state = *state + 1;
        }
        break;
    case 2:
        busy = 0;
        printSys = args->work->printSys;
        if (work->statusPending != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->statusWindow)) == 0) {
                BMP_WIN_TransferChars(work->statusWindow);
                work->statusPending = 0;
            }
        }
        finished = work->statusPending == 0 ? B_TRUE : B_FALSE;
        if (finished == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(4, 1);
            BG_SYS_SetPlaneVisible(5, 1);
            BG_SYS_SetPlaneVisible(6, 1);
            BG_SYS_SetSubPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * extent: final halfword at 021B94CA is alignment padding.
 * lever: state9 writes its state10 tail twice, one reached by goto, preserving the cross-jump.
 */
int MONOLITH_TOOL_LIST_Main(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work)
{
    u32 initial, mask, save;
    int active, result;
    struct PrintSys *printSys;

    initial = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(args->setup->gameCtx));
    MONOLITH_TOOL_UpdateHighlight(args, 1);
    MONOLITH_TOOL_UpdateHighlight(args, 3);
    MONOLITH_TOOL_UpdateMarker(work);
    MONOLITH_TOOL_LIST_UpdateBackButton(args->work, work);
    printSys = args->work->printSys;
    if (work->statusPending != 0 && PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->statusWindow)) == 0) {
        BMP_WIN_TransferChars(work->statusWindow);
        work->statusPending = 0;
    }
    if (args->abortRequested == 1 && *state == 4) return 1;
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        MONOLITH_TOOL_LIST_ShowMessage(work, args->work, 0x25);
        ++*state;
        break;
    case 2:
        if (MONOLITH_TOOL_LIST_IsMessageDone(args->work, work) == 1 && (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 3))) {
            MONOLITH_TOOL_LIST_HideMessage(work);
            GFL_USE_PlaySeDefaultVolume(0x547);
            if (TOUCHPANEL_GetTrg() == 0) MONOLITH_TOOL_SetCursor(work, 1, 0);
            else MONOLITH_TOOL_SetCursor(work, MONOLITH_CURSOR_NONE, 0);
            ++*state;
        }
        break;
    case 3:
        if (TOUCHPANEL_GetCont() == 0 && !(KEY_GetCont() & 3)) *state = 4;
        break;
    case 4:
        mask = KEY_GetTrg();
        active = TOUCHPANEL_HitTrg(d_021BAAFC);
        if (active == 0 || (mask & 2)) {
            MONOLITH_TOOL_StartBlink(&work->marker);
            if (active == 0) UI_SetInputMode(TRUE);
            else UI_SetInputMode(FALSE);
            GFL_USE_PlaySeDefaultVolume(0x551);
            *state = 17;
            break;
        }
        MONOLITH_TOOL_ProcessListInput(args, work);
        MONOLITH_TOOL_ClearPrevHighlight(work);
        if (MONOLITH_TOOL_ScrollBy(work, work->scrollVelocity + work->scrollRequest) == 1) {
            MONOLITH_TOOL_UpdateBgScroll(work);
            MONOLITH_TOOL_UpdateRows(work);
            work->uploadPending = 1;
        }
        MONOLITH_TOOL_ApplyCursorChange(args, work);
        if (work->cursor == MONOLITH_CURSOR_NONE) {
            args->param->selected = MONOLITH_ENTRY_NONE;
        } else {
            args->param->selected = work->entryIds[work->cursor];
            args->param->mode = work->entryDisabled[work->cursor];
            if (work->entryDisabled[work->cursor] == 0) {
                MONOLITH_TOOL_SetButtonVisible(&work->backButton, 1);
                goto selected;
            }
        }
        MONOLITH_TOOL_SetButtonVisible(&work->backButton, 0);
selected:
        if (work->chosenEntry != MONOLITH_CURSOR_NONE) {
            GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_CONFIRM);
            *state = 5;
        }
        break;
    case 5:
        if (MONOLITH_TOOL_GetHighlightMode(args, 1) != 2 && MONOLITH_TOOL_GetHighlightMode(args, 3) != 2) {
            MONOLITH_TOOL_LIST_ShowMessage(work, args->work, 0x20);
            ++*state;
        }
        break;
    case 6:
        if (MONOLITH_TOOL_LIST_IsMessageDone(args->work, work) == 1) {
            if (work->yesNoMenu != 0) SAVEDATA_PanicFail((const char *)d_021BABFC, 0, (const char *)d_021BABFC);
            work->yesNoMenu = MONOLITH_TOOL_OpenTaskMenu((int *)args->work, work->taskMenuUnit, 0x61);
            ++*state;
        }
        break;
    case 7:
        if (MONOLITH_TOOL_UpdateTaskMenu(args->work, 4, work->yesNoMenu, &result) == 1) {
            MONOLITH_TOOL_CloseTaskMenu(work->yesNoMenu);
            work->yesNoMenu = 0;
            MONOLITH_TOOL_LIST_HideMessage(work);
            if (result == 1) *state = 8;
            else {
                work->chosenEntry = MONOLITH_CURSOR_NONE;
                MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
                MONOLITH_TOOL_HighlightButtonPulse(args, &work->backButton, 1, 0xff, 3);
                *state = 4;
            }
        }
        break;
    case 8:
        if (MONOLITH_TOOL_GetHighlightMode(args, 1) != 2 && MONOLITH_TOOL_GetHighlightMode(args, 3) != 2) {
            WORDSET_SetSlotFromMsgA0(args->work->wordSet, 0, work->entryIds[work->chosenEntry]);
            MONOLITH_TOOL_LIST_ShowFormattedMessage(work, args->work, 0x23);
            *state = 9;
        }
        break;
    case 9:
        if (initial == 0) goto write10;
        if (INTRUDE_COMM_SendPairMessage(args->setup->areaId) == 1) {
            *state = 10;
            break;
        }
        break;
write10:
        *state = 10;
        break;
    case 10:
        if (MONOLITH_TOOL_LIST_IsMessageDone(args->work, work) == 1) {
            GFL_USE_FadeOutBgm(6);
            ++*state;
        }
        break;
    case 11:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            ++*state;
        }
        break;
    case 12:
        GFL_USE_CancelChangeAndPlayBgm(0x531, 0xffff);
        ++*state;
        break;
    case 13:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            GFL_USE_FadeInBgmFull(6);
            ++*state;
        }
        break;
    case 14:
        if (GFL_USE_IsBgmFading() == 0) *state = 15;
        break;
    case 15:
        if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 3)) {
            MONOLITH_TOOL_LIST_HideMessage(work);
            INTRUDE_SetMonolithLevel((struct Rec1B0 *)INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(args->setup->gameCtx))), work->entryIds[work->chosenEntry]);
            save = GAMESYSTEM_GetGameComm(args->setup->gameCtx);
            GAME_COMM_PushPairMessage(save, GAME_DATA_GetOwnNetId(GAMESYSTEM_GetGameData(args->setup->gameCtx)), args->setup->areaId);
            work->chosenEntry = MONOLITH_CURSOR_NONE;
            MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
            MONOLITH_TOOL_HighlightButtonPulse(args, &work->backButton, 1, 0xff, 3);
            if (TOUCHPANEL_GetTrg() != 0) *state = 16;
            else *state = 17;
        }
        break;
    case 16:
        if (TOUCHPANEL_GetCont() == 0) *state = 17;
        break;
    case 17:
        if (MONOLITH_TOOL_GetHighlightMode(args, 1) != 2 && MONOLITH_TOOL_GetHighlightMode(args, 3) != 2 && MONOLITH_TOOL_IsBlinkActive(&work->marker) == 0) {
            args->requestedScreen = 0;
            return 1;
        }
        break;
    }
    MONOLITH_TOOL_UpdateScrollArrows(work);
    return 0;
}







int MONOLITH_TOOL_LIST_Exit(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work)
{
    if (PRINTSYS_QUE_IsFinished(args->work->printSys) == 0)
        return 0;
    BG_SYS_SetSubVisiblePlanes(8);
    TCB_DeleteTask((struct Node *)work->task);
    if (work->messagePrinter != 0)
        PRINTSYS_PrintStreamDelete(work->messagePrinter);
    if (work->messageText != 0)
        STRBUF_Delete(work->messageText);
    MONOLITH_TOOL_LIST_FreeEntryBitmaps(work);
    if (work->yesNoMenu != 0)
        MONOLITH_TOOL_CloseTaskMenu(work->yesNoMenu);
    MONOLITH_TOOL_DeleteTaskMenuRes(work->taskMenuUnit);
    MONOLITH_TOOL_LIST_FreeBackButton(work);
    MONOLITH_TOOL_DeleteRowGrids(work);
    MONOLITH_TOOL_DeleteMarker(work);
    MONOLITH_TOOL_DeleteScrollArrows(work);
    MONOLITH_TOOL_LIST_FreeBgChar(work);
    MONOLITH_TOOL_LIST_FreeWindows(work);
    MONOLITH_TOOL_LIST_FreeBackgrounds();
    MSGDATA_Delete(work->entryNameBank);
    PROCSYS_FreeProcWork(proc);
    return 1;
}







void MONOLITH_TOOL_LIST_InitBackgrounds(void)
{
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)d_021BAB28, 0);
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)d_021BAB48, 0);
    BG_SYS_InitBgLayer(6, (const struct BgTemplate *)((char *)&d_021BAB68), 0);
    BG_SYS_SetTileEntry(4, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(5, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(6, 0, 0, 0, 0x20, 0x20, 0x11);
}






void MONOLITH_TOOL_LIST_FreeBackgrounds(void) { BG_SYS_SetPlaneVisible(4,0); BG_SYS_SetPlaneVisible(5,0); BG_SYS_SetPlaneVisible(6,0); BG_SYS_FreeLayerBuf(4); BG_SYS_FreeLayerBuf(5); BG_SYS_FreeLayerBuf(6); }







void MONOLITH_TOOL_LIST_LoadGraphics(MonolithListWork *work, MonolithToolWork *toolWork)
{
    void *res;

    ARC_UTIL_UploadBgPaletteFromHandle(toolWork->archive, 7, 6, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgCharFromHandle(toolWork->archive, 0xe, 5, 0, 0, 1, 0x61);
    ARC_UTIL_UploadBgPaletteFromHandle(toolWork->archive, 9, 5, 0, 0, 1, 0x61);
    res = ARC_TOOL_CreateHandle(0x53, 0x61);
    work->bgCharOffset = BG_SYS_CreateRun(5, 0x80, 1);
    ARC_UTIL_UploadBgCharFromHandle(res, 0x1c, 5, work->bgCharOffset, 0x80, 0, 0x61);
    APP_ICON_LoadTouchBar(res, 5, 0x61, work->bgCharOffset, 0xc);
    ARC_TOOL_DeleteHandle(res);
    BG_SYS_PushTile(5);
    BG_SYS_PushTile(6);
}






void MONOLITH_TOOL_LIST_FreeBgChar(MonolithListWork *work) { BG_SYS_DeleteHalf(5, work->bgCharOffset, 0x80); }







void MONOLITH_TOOL_LIST_InitWindows(MonolithListWork *work, MonolithToolWork *toolWork)
{
    BMP_MENUWORK_LoadChar(4, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(toolWork->palAnm, 5, BMP_MENUWORK_GetPlttFileId(0), 0x61, 1, 0x20, 0xb0, 0);
    work->messageWindow = BMP_WIN_Create(4, 1, 0x13, 0x1e, 4, 0xd, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->messageWindow), 0xff);
    work->titleWindow = BMP_WIN_Create(4, 0, 0, 0x20, 3, 0xd, 1);
    BMP_WIN_MakeScreen(work->titleWindow);
    BG_SYS_PushTile(4);
    work->statusWindow = work->titleWindow;
    work->statusPending = 0;
}






void MONOLITH_TOOL_LIST_FreeWindows(MonolithListWork *work) { int i; for (i=0;i<2;i++) BMP_WIN_Delete((&work->messageWindow)[i]); }





void MONOLITH_TOOL_LIST_DrawTitle(MonolithToolProcArgs *args, MonolithListWork *work)
{
    struct Strbuf *text;
    MonolithToolWork *toolWork;
    struct PrintSys *printSys;

    text = MSGDATA_AllocString(args->work->msgBank[3], 0x22);
    toolWork = args->work;
    printSys = toolWork->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(work->statusWindow), 0x18, 4, text, (u32)toolWork->font);
    work->statusPending = 1;
    STRBUF_Delete(text);
}





void MONOLITH_TOOL_LIST_ShowMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId)
{
    if (work->messagePrinter != 0)
        SAVEDATA_PanicFail(d_021BABFC, 0, d_021BABFC);
    GF_FONT_SetTextColor(1, 2, 0xf);
    work->messageText = MSGDATA_AllocString(toolWork->msgBank[3], msgId);
    work->messagePrinter = PRINTSYS_PrintStream(work->messageWindow, 0, 0, work->messageText, (u32)toolWork->font, MSG_SPEED_GetWait(), toolWork->taskList, 0xa, 0x61, 0xf);
    BMP_WIN_MakeScreen(work->messageWindow);
    BMP_MENUWORK_DrawWindow(work->messageWindow, 1, 1, 0xb);
}





void MONOLITH_TOOL_LIST_ShowFormattedMessage(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId)
{
    struct Strbuf *format;

    if (work->messagePrinter != 0)
        SAVEDATA_PanicFail(d_021BABFC, 0, d_021BABFC);
    GF_FONT_SetTextColor(1, 2, 0xf);
    format = MSGDATA_AllocString(toolWork->msgBank[3], msgId);
    work->messageText = STRBUF_Create(0x100, 0x61);
    WORDSET_CopyTaggedText(toolWork->wordSet, work->messageText, format);
    STRBUF_Delete(format);
    work->messagePrinter = PRINTSYS_PrintStream(work->messageWindow, 0, 0, work->messageText, (u32)toolWork->font, MSG_SPEED_GetWait(), toolWork->taskList, 0xa, 0x61, 0xf);
    BMP_WIN_MakeScreen(work->messageWindow);
    BMP_MENUWORK_DrawWindow(work->messageWindow, 1, 1, 0xb);
}




/*
 * leaf: unlabelled tail stub called by MONOLITH_TOOL_LIST_Main; parent confirmed unowned.
 */
int MONOLITH_TOOL_LIST_IsMessageDone(MonolithToolWork *toolWork, MonolithListWork *work)
{
    return PRINTSYS_CTRL_Update((struct Blk *)toolWork->scratchList, work->messagePrinter);
}





void MONOLITH_TOOL_LIST_HideMessage(MonolithListWork *work)
{
    struct Bitmap *bitmap;

    bitmap = BMP_WIN_GetBmp(work->messageWindow);
    if (work->messagePrinter == 0)
        SAVEDATA_PanicFail(d_021BABFC, 0, d_021BABFC);
    PRINTSYS_PrintStreamDelete(work->messagePrinter);
    work->messagePrinter = 0;
    STRBUF_Delete(work->messageText);
    work->messageText = 0;
    BMP_MENUWORK_DrawWindowBorder(work->messageWindow, 0);
    BMP_Clear(bitmap, 0xff);
    BMP_WIN_TransferChars(work->messageWindow);
    GF_FONT_SetTextColor(0xf, 2, 0);
}





void MONOLITH_TOOL_LIST_FitBackground(MonolithListWork *work)
{
    int count;
    int offset;

    count = work->entryCount;
    if (count - 2 < 7) {
        offset = (count - 1) * 32 / 8;
        BG_SYS_SetTileEntry(6, 0, 0, (u8)offset, 0x20, 0x20 - offset, 0x11);
        BG_SYS_PushTile(6);
    }
}





void MONOLITH_TOOL_LIST_BuildEntryList(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork)
{
    Idx i = 0;
    int n;
    int kind;
    MonolithCounts *counts;

    GAMESYSTEM_GetGameData(args->setup->gameCtx);
    counts = MONOLITH_TOOL_GetSlotIconStates(args);
    work->entryIds[0] = i;
    work->entryDisabled[0] = 1;
    work->entryBitmaps[0] = BMP_Create(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < MONOLITH_ENTRY_NONE; i++) {
        kind = TOWN_MAP_SPOT_Classify(toolWork->entryTable, i, counts, args->setup->rankData);
        if (kind != 2) {
            work->entryIds[n] = i;
            work->entryDisabled[n] = kind;
            work->entryBitmaps[n] = BMP_Create(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    work->entryIds[n] = 0;
    work->entryDisabled[n] = 1;
    work->entryBitmaps[n] = BMP_Create(0x17, 2, 0x20, 0x61);
    work->entryCount = n + 1;
}




void MONOLITH_TOOL_LIST_FreeEntryBitmaps(MonolithListWork *work) { int i; for (i = 0; i < work->entryCount; i++) BMP_Delete(work->entryBitmaps[i]); }





int MONOLITH_TOOL_LIST_DrawEntryNames(MonolithListWork *work, MonolithToolWork *toolWork)
{
    int count;
    int i;
    struct Strbuf *text;

    count = 0;
    text = STRBUF_Create(0x20, 0x61);
    i = work->loadedCount;
    if (i < work->entryCount) {
        do {
            if (i >= 1 && i < work->entryCount - 1) {
                MSGDATA_ReadString(work->entryNameBank, work->entryIds[i], text);
                PRINTSYS_PrintColor(work->entryBitmaps[i], 0, 0, text, (void *)toolWork->font,
                              d_021BAAF8[work->entryDisabled[i]]);
            }
            count++;
            if (count >= 3)
                break;
            i++;
        } while (i < work->entryCount);
    }
    STRBUF_Delete(text);
    work->loadedCount = i;
    return work->loadedCount >= work->entryCount;
}


void MONOLITH_TOOL_CreateRowGrids(MonolithListWork *work, MonolithToolWork *toolWork)
{
    int i;
    struct MonolithToolGridParam param;

    param = gMonolithRowGridParam;
    param.palette = toolWork->actorRes[1].simplePalAnm;
    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        work->rowBitmaps[i] = BMP_Create(0x17, 2, 0x20, 0x61);
        param.bitmap = work->rowBitmaps[i];
        work->rowGrids[i] = BMP_OAM_Create(toolWork->actorToolUnit, &param);
    }
}

void MONOLITH_TOOL_DeleteRowGrids(MonolithListWork *work)
{
    int i;

    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        BMP_OAM_Delete(work->rowGrids[i]);
        BMP_Delete(work->rowBitmaps[i]);
    }
}

void MONOLITH_TOOL_CreateBackButton(MonolithToolProcArgs *args, MonolithListWork *work)
{
    MONOLITH_TOOL_CreateButton(args->work, &work->backButton, 1, 2, 0x40, 0xb4, 0x24, 0);
    if (UI_GetInputMode() == 1)
        MONOLITH_TOOL_SetButtonVisible(&work->backButton, 0);
}

void MONOLITH_TOOL_LIST_FreeBackButton(MonolithListWork *work)
{
    MONOLITH_TOOL_FreeButton(&work->backButton);
}

void MONOLITH_TOOL_LIST_UpdateBackButton(MonolithToolWork *toolWork, MonolithListWork *work)
{
    MONOLITH_TOOL_IsButtonUploaded(toolWork, &work->backButton);
}

void MONOLITH_TOOL_CreateMarker(MonolithToolProcArgs *args, MonolithListWork *work)
{
    MONOLITH_TOOL_CreateBlink(args->work, &work->marker);
}

void MONOLITH_TOOL_DeleteMarker(MonolithListWork *work)
{
    MONOLITH_TOOL_DeleteBlink(&work->marker);
}

void MONOLITH_TOOL_UpdateMarker(MonolithListWork *work)
{
    MONOLITH_TOOL_UpdateBlink(&work->marker);
}

void MONOLITH_TOOL_CreateScrollArrows(MonolithToolProcArgs *args, MonolithListWork *work)
{
    work->scrollUpArrow = MONOLITH_TOOL_CreateActorAt(args->work, 0x80, 0x1c, 9);
    work->scrollDownArrow = MONOLITH_TOOL_CreateActorAt(args->work, 0x80, 0xa4, 10);
    CLACT_SetActorDrawEnable(work->scrollUpArrow, 0);
    CLACT_SetActorDrawEnable(work->scrollDownArrow, 0);
}

void MONOLITH_TOOL_DeleteScrollArrows(MonolithListWork *work)
{
    MONOLITH_TOOL_DeleteActorAt(work->scrollUpArrow);
    MONOLITH_TOOL_DeleteActorAt(work->scrollDownArrow);
}

void MONOLITH_TOOL_UpdateScrollArrows(MonolithListWork *work)
{
    if (work->scrollPos <= 0x800)
        CLACT_SetActorDrawEnable(work->scrollUpArrow, 0);
    else
        CLACT_SetActorDrawEnable(work->scrollUpArrow, 1);
    if ((work->scrollPos >> 8) >= work->entryCount * MONOLITH_ROW_HEIGHT - 200)
        CLACT_SetActorDrawEnable(work->scrollDownArrow, 0);
    else
        CLACT_SetActorDrawEnable(work->scrollDownArrow, 1);
    MONOLITH_TOOL_Noop(work->scrollUpArrow);
    MONOLITH_TOOL_Noop(work->scrollDownArrow);
}

/*
 * `touching = 0` in the key branch is what keeps r7 as the zero stored to
 * scrollVelocity/touchFrames and passed to UI_SetInputMode; `work->scrollRequest
 * = chosen` (not 0) reloads the spilled result as in the image.
 */
int MONOLITH_TOOL_ProcessListInput(MonolithToolProcArgs *args, MonolithListWork *work)
{
    int chosen;
    int selectedRow;
    u32 touchX;
    u32 touchY;
    int touching;
    int contentY;
    int row;
    int rowRemainder;
    int dragDistance;
    int tappedRow;

    chosen = 0;
    selectedRow = MONOLITH_CURSOR_NONE;
    work->scrollRequest = chosen;
    touching = TOUCHPANEL_GetPointCont(&touchX, &touchY);
    if (work->touchFrames == 0) {
        if (touchX < 0x18 || touchX > 0xe0) {
            touching = 0;
        }
    }
    if (KEY_GetCont() & (MONOLITH_KEY_A | MONOLITH_KEY_B | MONOLITH_KEY_UP | MONOLITH_KEY_DOWN)) {
        contentY = (work->scrollPos >> 8) + 0x18;
        row = contentY / MONOLITH_ROW_HEIGHT;
        rowRemainder = contentY % MONOLITH_ROW_HEIGHT;
        touching = 0;
        work->scrollVelocity = touching;
        work->touchFrames = touching;
        if (work->cursor == MONOLITH_CURSOR_NONE) {
            if (rowRemainder != 0) {
                row++;
            }
            if (row < 1) {
                row = 1;
            }
            if (row >= work->entryCount - 2) {
                MONOLITH_TOOL_SetCursor(work, work->entryCount - 2, MONOLITH_INPUT_KEY);
            } else {
                MONOLITH_TOOL_SetCursor(work, row, MONOLITH_INPUT_KEY);
            }
            GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
            return 0;
        }
        if (KEY_GetTrg() & MONOLITH_KEY_A) {
            MONOLITH_TOOL_SetCursor(work, work->cursor, MONOLITH_INPUT_KEY);
            UI_SetInputMode(0);
            if (work->entryDisabled[work->cursor] == 0) {
                GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_CONFIRM);
            }
            return 1;
        }
        if (KEY_GetRepeat() & MONOLITH_KEY_UP) {
            if (rowRemainder != 0) {
                row++;
            }
            if (MONOLITH_TOOL_SetCursor(work, work->cursor - 1, MONOLITH_INPUT_KEY) == 1) {
                GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
            }
            if (work->cursor < row) {
                work->scrollRequest = -0x2000;
            }
            return 0;
        }
        if (KEY_GetRepeat() & MONOLITH_KEY_DOWN) {
            row = ((work->scrollPos >> 8) + 0xa8) / MONOLITH_ROW_HEIGHT;
            if (MONOLITH_TOOL_SetCursor(work, work->cursor + 1, MONOLITH_INPUT_KEY) == 1) {
                GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
            }
            if (work->cursor >= row) {
                work->scrollRequest = 0x2000;
            }
            return 0;
        }
    }
    if (work->touchFrames == 0) {
        if (touching == 1) {
            if (touchY > 0x18 && touchY < 0xa8) {
                work->touchFrames = 1;
                work->touchY = touchY;
                work->touchStartY = touchY;
                MONOLITH_TOOL_SetCursor(work, MONOLITH_CURSOR_NONE, MONOLITH_INPUT_NONE);
            } else if (TOUCHPANEL_GetTrg() == 1 && work->cursor != MONOLITH_CURSOR_NONE
                       && touchX >= 0x10 && touchX <= 0x70 && touchY >= 0xac && touchY <= 0xbc) {
                chosen = 1;
                selectedRow = work->cursor;
                UI_SetInputMode(1);
            }
        } else if (work->scrollVelocity != 0) {
            if (work->scrollVelocity > 0) {
                work->scrollVelocity -= 0xc0;
                if (work->scrollVelocity < 0) {
                    work->scrollVelocity = 0;
                }
            } else {
                work->scrollVelocity += 0xc0;
                if (work->scrollVelocity > 0) {
                    work->scrollVelocity = 0;
                }
            }
        }
    } else if (touching == 0) {
        work->touchFrames = 0;
        if (work->touchStartY != MONOLITH_CURSOR_NONE) {
            dragDistance = work->touchY - work->touchStartY;
            if (dragDistance < 0) {
                dragDistance = -dragDistance;
            }
            if (dragDistance < 4) {
                tappedRow = MONOLITH_TOOL_GetRowAtY(work, work->touchY);
                if (tappedRow != MONOLITH_CURSOR_NONE) {
                    chosen = 1;
                    selectedRow = tappedRow;
                    GFL_USE_PlaySeDefaultVolume(MONOLITH_SE_MOVE);
                }
            }
        }
    } else {
        work->scrollVelocity = (work->touchY - touchY) << 8;
        work->touchY = touchY;
        work->touchFrames++;
        if (work->touchStartY != MONOLITH_CURSOR_NONE) {
            dragDistance = touchY - work->touchStartY;
            if (dragDistance < 0) {
                dragDistance = -dragDistance;
            }
            if (dragDistance > 4) {
                work->touchStartY = MONOLITH_CURSOR_NONE;
            }
        }
    }
    if (chosen == 1) {
        work->scrollVelocity = 0;
        MONOLITH_TOOL_SetCursor(work, selectedRow, MONOLITH_INPUT_TOUCH);
    }
    return chosen;
}

int MONOLITH_TOOL_SetCursor(MonolithListWork *work, int index, int inputMode)
{
    int prev;

    if (index != MONOLITH_CURSOR_NONE) {
        if (index >= work->entryCount - 1 || index < 1) {
            return 0;
        }
    }
    prev = work->cursor;
    work->prevCursor = prev;
    work->lastCursor = prev;
    work->cursor = index;
    work->cursorChanged = 1;
    work->inputMode = inputMode;
    return 1;
}

void MONOLITH_TOOL_SetRowHighlight(MonolithListWork *work, int index, int palette)
{
    int scrollPixels;
    int firstRow;
    int rowOffset;
    int bgOffset;
    int rowOnScreen;

    if (index != MONOLITH_CURSOR_NONE) {
        scrollPixels = work->scrollPos >> 8;
        firstRow = scrollPixels / MONOLITH_ROW_HEIGHT;
        rowOffset = scrollPixels % MONOLITH_ROW_HEIGHT;
        bgOffset = scrollPixels % 64;
        rowOnScreen = index - firstRow;
        if (rowOnScreen >= 0 && rowOnScreen < firstRow + MONOLITH_ROW_GRIDS) {
            BG_SYS_FillTileMap(6, 3, ((rowOnScreen * MONOLITH_ROW_HEIGHT + bgOffset - rowOffset) % 256) / 8, 0x19, 4, palette);
        }
    }
}

/*
 * Two thunks passing a constant third argument.
 */
void MONOLITH_TOOL_SetRowHighlightSelected(MonolithListWork *work, int index)
{
    MONOLITH_TOOL_SetRowHighlight(work, index, 3);
}

void MONOLITH_TOOL_SetRowHighlightNormal(MonolithListWork *work, int index)
{
    MONOLITH_TOOL_SetRowHighlight(work, index, 0);
}

void MONOLITH_TOOL_ClearPrevHighlight(MonolithListWork *work)
{
    if (work->cursorChanged == 1)
        MONOLITH_TOOL_SetRowHighlightNormal(work, work->prevCursor);
}

void MONOLITH_TOOL_ApplyCursorChange(MonolithToolProcArgs *args, MonolithListWork *work)
{
    int cursor;
    int inputMode;

    if (work->cursorChanged == 1) {
        MONOLITH_TOOL_SetRowHighlightSelected(work, work->cursor);
        cursor = work->cursor;
        if (cursor == MONOLITH_CURSOR_NONE) {
            MONOLITH_TOOL_SetButtonPulse(args, 0, 1);
        } else {
            inputMode = work->inputMode;
            if ((inputMode == MONOLITH_INPUT_TOUCH && cursor == work->lastCursor)
                || (inputMode == MONOLITH_INPUT_KEY && cursor == work->prevCursor)) {
                if (work->entryDisabled[cursor] == 0) {
                    work->chosenEntry = cursor;
                    if (work->inputMode == MONOLITH_INPUT_KEY) {
                        MONOLITH_TOOL_SetButtonFlash(args, 1);
                    } else {
                        MONOLITH_TOOL_HighlightButtonFlash(args, &work->backButton, 1, 0, 3);
                    }
                } else if (inputMode == MONOLITH_INPUT_TOUCH) {
                    MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
                }
            } else {
                MONOLITH_TOOL_SetButtonPulse(args, 1, 1);
            }
        }
        BG_SYS_SetFlagField06(6);
        work->cursorChanged = 0;
    }
}

int MONOLITH_TOOL_ScrollBy(MonolithListWork *work, int delta)
{
    int limit;
    int oldPos;

    oldPos = work->scrollPos;
    limit = work->entryCount * MONOLITH_ROW_HEIGHT - 8;
    if (limit <= 0xc0) {
        return 0;
    }
    work->scrollPos = oldPos + delta;
    if (work->scrollPos < 0x800) {
        work->scrollPos = 0x800;
    } else if (work->scrollPos > (limit - 0xc0) << 8) {
        work->scrollPos = (limit - 0xc0) << 8;
    }
    if ((work->scrollPos >> 8) != (oldPos >> 8)) {
        return 1;
    }
    return 0;
}

void MONOLITH_TOOL_UpdateBgScroll(MonolithListWork *work)
{
    BG_SYS_ResetSlot(6, 3, (work->scrollPos >> 8) % 64);
}

void MONOLITH_TOOL_UpdateRows(MonolithListWork *work)
{
    int scrollPixels = work->scrollPos >> 8;
    int gridY = 8 - scrollPixels % MONOLITH_ROW_HEIGHT;
    int firstRow = scrollPixels / MONOLITH_ROW_HEIGHT;
    int i;

    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        BMP_OAM_SetPos(work->rowGrids[i], 0x20, gridY + i * MONOLITH_ROW_HEIGHT);
        if (work->entryBitmaps[firstRow + i] != 0) {
            BMP_CopyPixels(work->entryBitmaps[firstRow + i], work->rowBitmaps[i]);
        }
    }
}

void MONOLITH_TOOL_TaskUploadRows(void *task, MonolithListWork *work)
{
    int i;

    if (work->uploadPending == 1) {
        for (i = 0; i < MONOLITH_ROW_GRIDS; i++)
            BMP_OAM_UploadChars(work->rowGrids[i]);
        work->uploadPending = 0;
    }
}

int MONOLITH_TOOL_GetRowAtY(MonolithListWork *work, unsigned y)
{
    int row = ((work->scrollPos >> 8) + y) >> 5;

    if (row >= work->entryCount)
        row = MONOLITH_CURSOR_NONE;
    return row;
}

int MONOLITH_TOOL_InitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    MonolithInfoWork *newWork;
    int busy;
    int i;
    struct PrintSys *printSys;
    Bool finished;

    switch (*state) {
    case 0:
        newWork = PROCSYS_AllocProcWork(proc, 0x28, 0x61);
        MI_CpuFill8(newWork, 0, 0x28);
        newWork->shownEntry = MONOLITH_ENTRY_NONE;
        MONOLITH_TOOL_SetupInfoBgs();
        MONOLITH_TOOL_LoadInfoPalette(args->work);
        MONOLITH_TOOL_CreateInfoWindows(args->work, newWork);
        MONOLITH_TOOL_DrawInfoHeader(args->work, newWork);
        MONOLITH_TOOL_DrawActiveEntry(args, args->work, newWork);
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            printSys = args->work->printSys;
            if (work->slots[i].pending != 0) {
                if (PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->slots[i].window)) == 0) {
                    BMP_WIN_TransferChars(work->slots[i].window);
                    work->slots[i].pending = 0;
                }
            }
            finished = work->slots[i].pending == 0 ? B_TRUE : B_FALSE;
            if (finished == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            BG_SYS_SetPlaneVisible(0, 1);
            BG_SYS_SetPlaneVisible(2, 1);
            BG_SYS_SetMainPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

int MONOLITH_TOOL_MainInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    int i;
    u8 idle[3];
    struct PrintSys *printSys;

    if (args->topProcDone == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        printSys = args->work->printSys;
        if (work->slots[i].pending != 0) {
            if (PRINTSYS_QUE_IsExistTarget(printSys, BMP_WIN_GetBmp(work->slots[i].window)) == 0) {
                BMP_WIN_TransferChars(work->slots[i].window);
                work->slots[i].pending = 0;
            }
        }
        idle[i] = work->slots[i].pending == 0;
    }
    if (*state == 0) {
        if (args->param->activeDirty == 1 && idle[1] == 1) {
            MONOLITH_TOOL_DrawActiveEntry(args, args->work, work);
            args->param->activeDirty = 0;
        }
        if (args->param->selected != work->shownEntry && idle[2] == 1) {
            MONOLITH_TOOL_DrawSelectedEntry(args, args->work, work);
            work->shownEntry = args->param->selected;
        }
        return 0;
    }
    return 0;
}

int MONOLITH_TOOL_ExitInfoScreen(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    if (PRINTSYS_QUE_IsFinished(args->work->printSys) == 0)
        return 0;
    BG_SYS_SetMainVisiblePlanes(8);
    MONOLITH_TOOL_DeleteInfoWindows(work);
    MONOLITH_TOOL_HideInfoBgs();
    PROCSYS_FreeProcWork(proc);
    return 1;
}

void MONOLITH_TOOL_SetupInfoBgs(void)
{
    BG_SYS_InitBgLayer(0, &gMonolithInfoBgTemplate0, 0);
    BG_SYS_InitBgLayer(2, &gMonolithInfoBgTemplate2, 0);
    BG_SYS_SetTileEntry(0, 0, 0, 0, 0x20, 0x20, 0x11);
    BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0x20, 0x11);
}

void MONOLITH_TOOL_HideInfoBgs(void)
{
    BG_SYS_SetPlaneVisible(0, 0);
    BG_SYS_SetPlaneVisible(2, 0);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(2);
}

void MONOLITH_TOOL_LoadInfoPalette(MonolithToolWork *toolWork)
{
    ARC_UTIL_UploadBgPaletteFromHandle(toolWork->archive, 13, 2, 0, 0, 1, 0x61);
    BG_SYS_PushTile(0);
    BG_SYS_PushTile(2);
}

void MONOLITH_TOOL_CreateInfoWindows(MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    int i;

    work->windows[0] = BMP_WIN_Create(0, 2, 0, 0x1c, 3, 0xd, 1);
    BMP_WIN_TransferChars(work->windows[0]);
    BMP_WIN_MakeScreen(work->windows[0]);
    work->windows[1] = BMP_WIN_Create(0, 2, 4, 0x1c, 8, 0xd, 1);
    BMP_WIN_TransferChars(work->windows[1]);
    BMP_WIN_MakeScreen(work->windows[1]);
    work->windows[2] = BMP_WIN_Create(0, 2, 0xf, 0x1c, 9, 0xd, 1);
    BMP_WIN_TransferChars(work->windows[2]);
    BMP_WIN_MakeScreen(work->windows[2]);
    for (i = 0; i < 3; i++) {
        work->slots[i].window = work->windows[i];
        work->slots[i].pending = 0;
    }
    BG_SYS_PushTile(0);
}

void MONOLITH_TOOL_DeleteInfoWindows(MonolithInfoWork *work)
{
    int i;

    for (i = 0; i < 3; i++)
        BMP_WIN_Delete(work->windows[i]);
}

/*
 * note: trailing two-byte alignment padding.
 */
void MONOLITH_TOOL_DrawInfoHeader(MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    struct Strbuf *text;
    struct PrintSys *printSys;

    text = MSGDATA_AllocString(toolWork->msgBank[3], 38);
    printSys = toolWork->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(work->slots[0].window), 0, 4, text, (u32)toolWork->font);
    work->slots[0].pending = 1;
    STRBUF_Delete(text);
}

void MONOLITH_TOOL_DrawActiveEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    struct Strbuf *name;
    struct Strbuf *desc;
    u32 activeEntry;
    struct PrintSys *printSys;

    activeEntry = INTRUDE_GetMonolithLevel(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(args->setup->gameCtx))));
    BMP_Clear(BMP_WIN_GetBmp(work->windows[1]), 0);
    if (activeEntry == MONOLITH_ENTRY_NONE) {
        name = MSGDATA_AllocString(toolWork->msgBank[3], 0x27);
    } else {
        name = MSGDATA_AllocString(toolWork->msgBank[1], toolWork->entryTable[activeEntry].nameMsgId);
        desc = MSGDATA_AllocString(toolWork->msgBank[2], toolWork->entryTable[activeEntry].descMsgId);
        printSys = toolWork->printSys;
        PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(work->slots[1].window), 0, 0x10, desc, (u32)toolWork->font);
        work->slots[1].pending = 1;
        STRBUF_Delete(desc);
    }
    printSys = toolWork->printSys;
    PRINTSYS_PrintQue(printSys, BMP_WIN_GetBmp(work->slots[1].window), 0, 0, name, (u32)toolWork->font);
    work->slots[1].pending = 1;
    STRBUF_Delete(name);
}


/*
 * Lever: a 12-byte MonolithEntry subscript retains the second-path scale in r0;
 * byte indexing instead adds a copy and shifts the remainder by 2 bytes.
 * Extent after 0x021BA756 is alignment and rodata, not a code follower.
 */
static inline void PrintText(MonolithToolWork *toolWork, struct BmpWin *window, u32 x, u32 y, struct Strbuf *text)
{
    struct PrintSys *queue = toolWork->printSys;
    PRINTSYS_PrintQue(queue, BMP_WIN_GetBmp(window), x, y, text, (u32)toolWork->font);
}

void MONOLITH_TOOL_DrawSelectedEntry(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    u32 selected;
    struct Strbuf *desc, *format, *line;
    MonolithCounts *counts;
    u32 msgId;
    u32 cost;

    selected = args->param->selected;
    BMP_Clear(BMP_WIN_GetBmp(work->windows[2]), 0);
    if (selected != MONOLITH_ENTRY_NONE) {
        if (args->param->mode == 0) {
            WORDSET_SetSlotNumber(toolWork->wordSet, 0, toolWork->entryTable[selected].number, 4, 0, 1);
            desc = MSGDATA_AllocString(toolWork->msgBank[2], toolWork->entryTable[selected].descMsgId);
            format = MSGDATA_AllocString(toolWork->msgBank[3], 0x28);
            line = STRBUF_Create(0x40, 0x61);
            WORDSET_CopyTaggedText(toolWork->wordSet, line, format);
            PrintText(toolWork, work->slots[2].window, 0, 4, desc);
            work->slots[2].pending = 1;
            PrintText(toolWork, work->slots[2].window, 0x70, 0x34, line);
            work->slots[2].pending = 1;
            STRBUF_Delete(desc);
            STRBUF_Delete(format);
            STRBUF_Delete(line);
        } else {
            counts = MONOLITH_TOOL_GetSlotIconStates(args);
            cost = toolWork->entryTable[selected].costA;
            if ((int)cost > counts->current) {
                msgId = 0x29;
            } else {
                cost = toolWork->entryTable[selected].costB;
                msgId = 0x2a;
            }
            WORDSET_SetSlotNumber(toolWork->wordSet, 0, cost, 3, 0, 1);
            WORDSET_SetSlotNumber(toolWork->wordSet, 1, counts->current, 3, 0, 1);
            WORDSET_SetSlotNumber(toolWork->wordSet, 2, counts->limit, 3, 0, 1);
            format = MSGDATA_AllocString(toolWork->msgBank[3], msgId);
            line = STRBUF_Create(0x80, 0x61);
            WORDSET_CopyTaggedText(toolWork->wordSet, line, format);
            PrintText(toolWork, work->slots[2].window, 0, 4, line);
            work->slots[2].pending = 1;
            STRBUF_Delete(line);
            STRBUF_Delete(format);
        }
    } else {
        BMP_WIN_TransferChars(work->windows[2]);
    }
}
