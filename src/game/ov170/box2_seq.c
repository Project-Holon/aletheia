/*
 * file:     box2_seq.c
 * unit:     yes
 * function: BOX2_SEQ_StateMenuSelect, BOX2_SEQ_StateMenuSwap, BOX2_SEQ_StateMenuMain, BOX2_SEQ_StateMachineMove, BOX2_SEQ_StateExitBox, BOX2_SEQ_OpenBoxUp, BOX2_SEQ_OpenBoxDown, BOX2_SEQ_OpenBoxLeft, BOX2_SEQ_OpenBoxRight, BOX2_SEQ_StateMachineScroll, BOX2_SEQ_UpdatePrintQueue, BOX2_SEQ_CreateBox2Main, BOX2_SEQ_DeleteBox2Main, BOX2_SEQ_StateWaitWipe, BOX2_SEQ_StateWaitFade, BOX2_SEQ_StateWaitCount, BOX2_SEQ_StateRunStep, BOX2_SEQ_StateWaitInput, BOX2_SEQ_StateTaskMenu, BOX2_SEQ_StateCheckTaskMenu, BOX2_SEQ_StateDispatchFont, BOX2_SEQ_StateDispatchStep, BOX2_SEQ_DeleteBox2Ui, BOX2_SEQ_StateWaitPrint, BOX2_SEQ_StateSetMenu, BOX2_SEQ_StateItemMenu, BOX2_SEQ_SetBox2Main, BOX2_SEQ_StateCloseBox, BOX2_SEQ_StateBoxMenu, BOX2_SEQ_StateOpenSummary, BOX2_SEQ_SetBox2Ui, BOX2_SEQ_StateSummary, BOX2_SEQ_StateSummaryInput, BOX2_SEQ_StateSummaryClose, BOX2_SEQ_StateSwapMenu, BOX2_SEQ_StateSwapConfirm, BOX2_SEQ_StateSwapApply, BOX2_SEQ_StateSwapFinish, BOX2_SEQ_StateMoveMove, BOX2_SEQ_StateMoveFinish, BOX2_SEQ_SetBox2UiB, BOX2_SEQ_StateOpenSummaryB, BOX2_SEQ_StateSummaryB, BOX2_SEQ_StateMoveInput, BOX2_SEQ_StateMoveClose, BOX2_SEQ_StateMoveCloseB, BOX2_SEQ_StateItemMenuB, BOX2_SEQ_StateOpenItemB, BOX2_SEQ_SetBox2UiC, BOX2_SEQ_StateSwapMenuB, BOX2_SEQ_StateItemMoveB, BOX2_SEQ_StateMoveFinishB, BOX2_SEQ_SetBox2UiD, BOX2_SEQ_StateOpenItemC, BOX2_SEQ_StateMenuCursor, BOX2_SEQ_StateItemMenuC, BOX2_SEQ_SetBox2MainB, BOX2_SEQ_StateCloseBoxB, BOX2_SEQ_StateOpenBoxC, BOX2_SEQ_DeleteBox2UiB, BOX2_SEQ_StateItemMenuD, BOX2_SEQ_SetBox2MainC, BOX2_SEQ_StateCursorMove, BOX2_SEQ_StateSummaryC, BOX2_SEQ_StateListScroll, BOX2_SEQ_StateScrollBox, BOX2_SEQ_StateOpenItemD, BOX2_SEQ_StateOpenItemE, BOX2_SEQ_StateItemMenuE, BOX2_SEQ_SetBox2UiE, BOX2_SEQ_DeleteBox2UiC, BOX2_SEQ_StateCloseBoxC, BOX2_SEQ_StateMenuItems, BOX2_SEQ_StateSelectItem, BOX2_SEQ_StateSummaryD, BOX2_SEQ_StateItemMenuF, BOX2_SEQ_StateCloseItem, BOX2_SEQ_StateMoveItemScroll, BOX2_SEQ_StateMoveItemB, BOX2_SEQ_StateCloseItemB, BOX2_SEQ_StatePlaceItem, BOX2_SEQ_StateCursorMoveB, BOX2_SEQ_SetBox2UiF, BOX2_SEQ_StateMoveItemC, BOX2_SEQ_StatePlaceItemB, BOX2_SEQ_StateMoveItemD, BOX2_SEQ_StateCursorMoveC, BOX2_SEQ_StatePushSlot, BOX2_SEQ_StateSwapMenuC, BOX2_SEQ_SetBox2MainD, BOX2_SEQ_StateCloseItemC, BOX2_SEQ_StateSwapMenuD, BOX2_SEQ_SetBox2MainE, BOX2_SEQ_StateSwapFinishB, BOX2_SEQ_StateCloseItemD, BOX2_SEQ_StateExitToField, BOX2_SEQ_StateSwapMenuE, BOX2_SEQ_StateCloseMenu, BOX2_SEQ_StateSummaryE, BOX2_SEQ_StateDeleteHandle, BOX2_SEQ_StateConfirmRelease, BOX2_SEQ_StateCloseZoom, BOX2_SEQ_StateReleaseMon, BOX2_SEQ_StateOpenZoom, BOX2_SEQ_StateZoomMenu, BOX2_SEQ_StateClosePmVoice, BOX2_SEQ_StateMoveMenu, BOX2_SEQ_StateMoveMenuB, BOX2_SEQ_StatePmVoiceMenu, BOX2_SEQ_StatePmVoiceConfirm, BOX2_SEQ_StateSetMiniIcon, BOX2_SEQ_StateMoveMenuC, BOX2_SEQ_StateClosePmVoiceB, BOX2_SEQ_StateFadeBox, BOX2_SEQ_StateCloseItemE, BOX2_SEQ_HideCursorSlot, BOX2_SEQ_ReturnAfterClear, BOX2_SEQ_StartWipeWhite, BOX2_SEQ_StartWipeBlack, BOX2_SEQ_SetSeqThird, BOX2_SEQ_SetSeqSecond, BOX2_SEQ_SetState, BOX2_SEQ_OpenYesNo, BOX2_SEQ_StateUseItem, BOX2_SEQ_StateUseItemWait, BOX2_SEQ_StateUseItemDone, BOX2_SEQ_StateUseItemMenu, BOX2_SEQ_StateExitBoxWithSe, BOX2_SEQ_StateCloseItemMenu, BOX2_SEQ_SaveMenuPosAndExit, BOX2_SEQ_StatePmVoiceClose, BOX2_SEQ_StateEnterItemMenu, BOX2_SEQ_GotoBox2Main, BOX2_SEQ_SetupFrameFadeAndWait, BOX2_SEQ_GotoBox2MainWithSlot, BOX2_SEQ_GotoBox2Ui, BOX2_SEQ_StatePmVoiceMenuB, BOX2_SEQ_StatePmVoiceMenuC, BOX2_SEQ_StatePmVoiceMenuD, BOX2_SEQ_StatePmVoiceOpen, BOX2_SEQ_StatePmVoiceOpenB, BOX2_SEQ_StatePmVoiceOpenC, BOX2_SEQ_StatePmVoiceOpenD, BOX2_SEQ_GotoRightPanelA, BOX2_SEQ_GotoRightPanelB, BOX2_SEQ_SelectSlotA, BOX2_SEQ_SelectSlotB, BOX2_SEQ_SelectSlotC, BOX2_SEQ_GotoSlotHandlerA, BOX2_SEQ_SelectPartySlotA, BOX2_SEQ_SelectPartySlotB, BOX2_SEQ_SelectPartySlotC, BOX2_SEQ_GotoSlotHandlerB, BOX2_SEQ_SelectSlotD, BOX2_SEQ_HideSlotWindow, BOX2_SEQ_SelectBoxSlot, BOX2_SEQ_ScrollListToSlot, BOX2_SEQ_Create, BOX2_SEQ_Delete, BOX2_SEQ_DrawGridSlot, BOX2_SEQ_SetCursorMove, BOX2_SEQ_SelectGridSlot, BOX2_SEQ_DrawGridSlotB, BOX2_SEQ_UpdateGridCursor, BOX2_SEQ_MoveGridCursor, BOX2_SEQ_DeleteGridSlot, BOX2_SEQ_SetCursorMoveB, BOX2_SEQ_CreateB, BOX2_SEQ_DeleteB, BOX2_SEQ_StopLeftBar, BOX2_SEQ_StopRightBar, BOX2_SEQ_RestartLeftBar, BOX2_SEQ_DrawListSlot, BOX2_SEQ_CreateC, BOX2_SEQ_RefreshBoxUiAndWait, BOX2_SEQ_ResetEntryB, BOX2_SEQ_SetActorAnim, BOX2_SEQ_CheckTradableMon, BOX2_SEQ_ToggleHandSlot, BOX2_SEQ_GotoSceneA, BOX2_SEQ_DeleteSlotWindows, BOX2_SEQ_GotoBox2MainPlaySe, BOX2_SEQ_GotoBox2MainNoSe, BOX2_SEQ_InitBmpWins, BOX2_SEQ_DeleteBmpWins, BOX2_SEQ_SetDirtyBit, BOX2_SEQ_FlushDirtyBmpWins, BOX2_SEQ_UpdateTextWins, BOX2_SEQ_MakeScreen, BOX2_SEQ_ClearScreen, BOX2_SEQ_PrintTextWin, BOX2_SEQ_PrintTextWinEx, BOX2_SEQ_CreateMsgBank, BOX2_SEQ_PrintMsgWin, BOX2_SEQ_InitBmpWin, BOX2_SEQ_FillTextWinEntry, BOX2_SEQ_FillTextWin, BOX2_SEQ_DrawCellEntry, BOX2_SEQ_DrawSpriteEntry, BOX2_SEQ_DrawTileEntry, BOX2_SEQ_DrawMoveEntry, BOX2_SEQ_DrawSwapEntry, BOX2_SEQ_DrawItemEntry, BOX2_SEQ_DrawMsgEntry, BOX2_SEQ_DeleteTextEntries, BOX2_SEQ_ClearTextWin, BOX2_SEQ_DrawWindowFrame, BOX2_SEQ_DrawFrameColor, BOX2_SEQ_DrawFrameDefault, BOX2_SEQ_AddBmpWinFrame, BOX2_SEQ_AddTextFrame, BOX2_SEQ_AddMsgFrame, BOX2_SEQ_AddNameFrame, BOX2_SEQ_DrawBoxName, BOX2_SEQ_DrawOffsetName, BOX2_SEQ_DrawMonName, BOX2_SEQ_ChangeFramePalette, BOX2_SEQ_PutNameFrame, BOX2_SEQ_DrawFrameList, BOX2_SEQ_ClearMessageWindow, BOX2_SEQ_ShowWindowObject, BOX2_SEQ_HideWindowObject, BOX2_SEQ_PrintMessageMsg, BOX2_SEQ_PrintMessageB, BOX2_SEQ_PrintWordset, BOX2_SEQ_PrintMessage, BOX2_SEQ_PrintMessageC, BOX2_SEQ_PrintWordsetB, BOX2_SEQ_PrintMessageD, BOX2_SEQ_PrintWordsetBB64, BOX2_SEQ_PrintMessageE, BOX2_SEQ_PrintMonName, BOX2_SEQ_PrintIndexedMessage, BOX2_SEQ_PrintPrompt, BOX2_SEQ_PrintPromptB, BOX2_SEQ_PrintMenuRow, BOX2_SEQ_PrintBoxMonName, BOX2_SEQ_PrintYesNo, BOX2_SEQ_CreateBox2UiScene, BOX2_SEQ_DeleteBox2UiScene, BOX2_SEQ_InitClact, BOX2_SEQ_LoadBoxGraphics, BOX2_SEQ_ReleaseBoxGraphics, BOX2_SEQ_CreateBox2Actors, BOX2_SEQ_CreateActorFromDesc, BOX2_SEQ_DeleteActorSlot, BOX2_SEQ_DeleteAllActors, BOX2_SEQ_DrawActors, BOX2_SEQ_SetActorAnimSeq, BOX2_SEQ_SetActorAutoAnim, BOX2_SEQ_IsActorAnimActive, BOX2_SEQ_SetActorDrawEnable, BOX2_SEQ_GetActorDrawEnable, BOX2_SEQ_SetActorBgPriority, BOX2_SEQ_SetActorDrawPriority, BOX2_SEQ_SetActorObjMode, BOX2_SEQ_AddActorSurfacePos, BOX2_SEQ_GetActorSurfacePos, BOX2_SEQ_RegisterBoxChars, BOX2_SEQ_RegisterBoxCharsB, BOX2_SEQ_RegisterIconRes, BOX2_SEQ_CreateBoxSlotActors, BOX2_SEQ_LoadGraphicResource, BOX2_SEQ_LoadMonIcon, BOX2_SEQ_SetSlotIconPal, BOX2_SEQ_LoadIconResource, BOX2_SEQ_ShowSlotIcon, BOX2_SEQ_ShowAllSlotIcons, BOX2_SEQ_ShowPartyIcons, BOX2_SEQ_GetSlotPos, BOX2_SEQ_HidePartialSlots, BOX2_SEQ_HideSlotsC61C, BOX2_SEQ_HideSlotsC688, BOX2_SEQ_HideSlotsC6F4, BOX2_SEQ_SetSlotDrawPriority, BOX2_SEQ_SetSlotDrawPriorityB, BOX2_SEQ_ShiftSlotIcons, BOX2_SEQ_MoveActorToWindow, BOX2_SEQ_ResetActorAffine, BOX2_SEQ_ShrinkActor, BOX2_SEQ_GrowActor, BOX2_SEQ_HideActor, BOX2_SEQ_ResetActorTransform, BOX2_SEQ_SetSlotActorsMode, BOX2_SEQ_SetSlotActors, BOX2_SEQ_SetSlotActorMode, BOX2_SEQ_SetActorMode1, BOX2_SEQ_SwapSlotActors, BOX2_SEQ_SwapSlotActorsB, BOX2_SEQ_RefreshHandSlot, BOX2_SEQ_InitIconSlots, BOX2_SEQ_LoadMonIconActor, BOX2_SEQ_LoadBoxScreen, BOX2_SEQ_CreateHandSlotActors, BOX2_SEQ_ShowHandSlot, BOX2_SEQ_ShowHandSlotB, BOX2_SEQ_LoadIconPalette, BOX2_SEQ_SetSlotCharacter, BOX2_SEQ_SetActorAffineMode, BOX2_SEQ_MoveActor, BOX2_SEQ_MoveActorToSlot, BOX2_SEQ_MoveActorToSlotB, BOX2_SEQ_CreateHandSlotActorsB, BOX2_SEQ_ShowHandSlots, BOX2_SEQ_LayoutHandSlots, BOX2_SEQ_CreateCursorObjects, BOX2_SEQ_SetWindow9, BOX2_SEQ_SetCursorFrame, BOX2_SEQ_SetCursorDraw, BOX2_SEQ_RefreshCursorSlot, BOX2_SEQ_MoveCursorActor, BOX2_SEQ_SetSlotDim, BOX2_SEQ_SetSlotDimB, BOX2_SEQ_MoveCursorToSlot
 * address:  0x021E1324
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_021DC860.c, box2_main.c, unit_021E002C.c, unit_021E01B0.c, unit_021E01C4.c, unit_021E0470.c, box2_seq.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   BOX_SAVEDATA_CountPokemonInBox 0x020078C4 thumb
 *   BOX2_SEQ_UpdatePrintQueue  0x021E1E34  thumb  ov170
 *   BOX2_SEQ_FlushDirtyBmpWins  0x021EAB04  thumb  ov170
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   BOX2_SEQ_SetActorAutoAnim 0x021EBFCC thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BGWINFRM_GetSize 0x0202CFC0 thumb
 *   BGWINFRM_GetBgFrame 0x0202CF8C thumb
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb  ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_UI_SetMiniIconVisible  0x021EE008  thumb  ov170
 *   BOX2_UI_UpdateCurrentBoxMarker  0x021EDF5C  thumb  ov170
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   BOX2_UI_DrawSlotByName 0x021EDB34 thumb ov170
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb ov170
 *   BOX2_SEQ_SetSlotDrawPriorityB 0x021EC7B8 thumb
 *   BOX2_SEQ_GetSlotPos 0x021EC548 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_SwapSlotActorsB 0x021ECBD8 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BOX2_SEQ_MoveActorToSlot 0x021ED164 thumb ov170
 *   BOX2_SEQ_MoveActorToSlotB 0x021ED198 thumb ov170
 *   BOX2_SEQ_MoveActor 0x021ED14C thumb ov170
 *   BOX2_SEQ_LayoutHandSlots 0x021ED310 thumb ov170
 *   BOX2_SEQ_DrawBoxName 0x021EB7E8 thumb
 *   BOX2_SEQ_LoadMonIconActor  0x021ECCCC  thumb  ov170
 *   BOX2_SEQ_ShowHandSlotB  0x021ED028  thumb  ov170
 *   BOX2_SEQ_DeleteTextEntries  0x021EB2A4  thumb  ov170
 *   BOX2_SEQ_ClearTextWin 0x021EB324 thumb
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb  ov170
 *   BOX_SAVEDATA_GetBoxName 0x0200785C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_StepScrollToPrevBox 0x021E00C4 thumb
 *   BOX2_MAIN_StepScrollToNextBox 0x021E0128 thumb
 *   BOX2_MAIN_ShiftWindowRight 0x021E01C4 thumb
 *   BOX2_SEQ_OpenBoxUp 0x021E19D4 thumb
 *   BOX2_SEQ_OpenBoxDown 0x021E1A28 thumb
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_UI_GetPartySlotPoint 0x021EF180 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_UI_PutBottomBarClosed 0x021EF35C thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_UI_OpenBar 0x021EF3A0 thumb
 *   BOX2_UI_UpdateBarMove 0x021EF400 thumb
 *   BOX2_UI_IsTopBarOpen 0x021EF45C thumb
 *   BOX2_UI_CloseListPack 0x021EF534 thumb
 *   BOX2_UI_OpenListPack 0x021EF57C thumb
 *   BOX2_UI_UpdateListPacks 0x021EF5C4 thumb
 *   BOX2_UI_IsListClosed 0x021EF60C thumb
 *   BOX2_UI_ShowWindowA 0x021EF670 thumb
 *   BOX2_UI_HideWindowA 0x021EF680 thumb
 *   BOX2_UI_ShowWindowB 0x021EF68C thumb
 *   BOX2_UI_HideWindowB 0x021EF69C thumb
 *   BOX2_UI_CloseInfoBar 0x021EF75C thumb
 *   BOX2_UI_IsInfoBarOpen 0x021EF770 thumb
 *   BOX2_UI_GetPageButtonHit 0x021EF248 thumb
 *   BOX2_UI_SlideBarIn 0x021EF3D8 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   BOX2_UI_IsTopBarClosed 0x021EF480 thumb
 *   d_021EF7B4 0x021EF7B4 data a1
 *   d_021EF79C 0x021EF79C data a1
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb ov170
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb ov170
 *   BOX2_MAIN_MoveCursorWithMon 0x021DE158 thumb ov170
 *   BOX2_SEQ_ShiftSlotIcons 0x021EC804 thumb
 *   BOX2_MAIN_StepToAdjacentBox 0x021DD16C thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_SEQ_RefreshHandSlot 0x021ECC1C thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_MAIN_GetBoxWallpaper 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb ov170
 *   BOX2_MAIN_CompareSlots 0x021DDE80 thumb
 *   BOX2_MAIN_StartHandMotionToBoxSlot 0x021DEA3C thumb
 *   BOX2_MAIN_StepHandMotionToSlot 0x021DEAFC thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_MAIN_StartHandMotionToTargetBoxSlot 0x021DEA4C thumb
 *   BOX2_MAIN_StepHandMotionToSlotB 0x021DEB08 thumb ov170
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_UI_AddSlotIcon 0x021EDD38 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   d_021EFA7C 0x021EFA7C data a4
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   KEY_GetRepeatSpeed 0x02036370 arm
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   BOX2_MAIN_ResetGraphics 0x021DC9C4 thumb ov170
 *   BOX2_MAIN_InitBgSys 0x021DC9E0 thumb ov170
 *   BOX2_MAIN_CreatePalAnm 0x021DCDB8 thumb ov170
 *   BOX2_MAIN_LoadBgData 0x021DCB8C thumb ov170
 *   BOX2_MAIN_CreateTextSystem 0x021DCE14 thumb ov170
 *   BOX2_MAIN_LoadFormTable 0x021DD8D0 thumb ov170
 *   BOX2_UI_InitWindowFrames 0x021EF274 thumb ov170
 *   BOX2_UI_DrawAllSlots 0x021EDB1C thumb ov170
 *   BOX2_UI_CreateCursor 0x021EE2C4 thumb ov170
 *   BOX2_MAIN_CreateTaskMenu 0x021DCEC0 thumb ov170
 *   BOX2_MAIN_SetDisplayControl 0x021DCDF0 thumb ov170
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   BOX2_MAIN_CreateVBlankTask 0x021DC94C thumb ov170
 *   str_021F140C 0x021F140C data a1
 *   ov067_id 0x00000043 data a1
 *   BOX2_MAIN_DeleteVBlankTask  0x021DC964  thumb  ov170
 *   BOX2_MAIN_DeleteTaskMenu  0x021DCF30  thumb  ov170
 *   BOX2_UI_DeleteCursorMove  0x021EE3CC  thumb  ov170
 *   BOX2_UI_DeleteWindowFrames  0x021EF310  thumb  ov170
 *   BOX2_MAIN_DeleteFormTable  0x021DD8F8  thumb  ov170
 *   BOX2_MAIN_DeleteTextSystem  0x021DCE80  thumb  ov170
 *   BOX2_MAIN_DeletePalAnm  0x021DCDD8  thumb  ov170
 *   BOX2_MAIN_DeleteBgSys  0x021DCB48  thumb  ov170
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   PALANM_GetFadeRequestBits   0x02021ED8  thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   d_021EFA4C 0x021EFA4C data a4
 *   BOX2_MAIN_StepWindowFrameFade  0x021DCFC0  thumb  ov170
 *   g_021EFA28  0x021EFA28  data  ov170
 *   d_021EFA2C 0x021EFA2C data a4
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   d_021EF9B4 0x021EF9B4 data
 *   d_021EF950 0x021EF950 data
 *   d_021EFA10 0x021EFA10 data
 *   d_021EF918 0x021EF918 data
 *   d_021EF8EC 0x021EF8EC data
 *   BOX2_UI_GetBackButtonPoint 0x021EF1FC thumb
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   BOX2_UI_GetPartySlotHit 0x021EF170 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   BOX2_UI_IsListOpen 0x021EF5E8 thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_UI_UpdateCursorInputC 0x021EE65C thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_UI_MoveCursorBetweenIcons 0x021EEF74 thumb
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_MAIN_ActivateKeyCursor 0x021DD238 thumb
 *   BOX2_UI_SelectSlot 0x021EE754 thumb
 *   BOX2_UI_GetExitButtonPoint 0x021EF1D4 thumb
 *   BOX2_UI_CursorInputLeft 0x021EE850 thumb
 *   BOX2_UI_PutBottomBarOpen 0x021EF34C thumb ov170
 *   BOX2_UI_GetHandSlotHit 0x021EF194 thumb
 *   BOX2_UI_UpdateCursorInputD 0x021EE8A8 thumb
 *   BOX2_UI_CursorInputRight 0x021EE96C thumb
 *   BOX2_UI_GetBodySlotHit 0x021EF1A4 thumb
 *   BOX2_UI_SlideBarOut 0x021EF3EC thumb ov170
 *   BOX2_UI_UpdateCursorInputG 0x021EECE4 thumb
 *   BOX2_UI_UpdateCursorInputH 0x021EEDE0 thumb
 *   UI_GetInputMode 0x020355C4 arm
 *   BOX2_UI_UpdateCursorInputB 0x021EE57C thumb
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb ov170
 *   BOX2_MAIN_StateMachineClose 0x021E0068 thumb ov170
 *   BOX2_UI_UpdateCursorInputA 0x021EE474 thumb
 *   BOX2_MAIN_SceneWaitCursor 0x021E0778 thumb
 *   BOX2_UI_PlaceCursorAtIcon 0x021EE520 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   BOX_SAVEDATA_CountFreeSlotsInBox 0x020077B8 thumb
 *   BOX_SAVEDATA_FindFreeSlot 0x020076D0 thumb
 *   BOX2_UI_PlaceCursorAtMon 0x021EE544 thumb
 *   BOX2_MAIN_SceneOpenBox 0x021E087C thumb
 *   BOX2_UI_UpdateCursorInputE 0x021EEA48 thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_SyncItemForm 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_UI_UpdateCursorInputF 0x021EEB40 thumb
 *   BOX2_UI_CursorInputPage 0x021EEEA4 thumb
 *   BOX2_MAIN_GetBoxValue 0x021DD908 thumb ov170
 *   BOX2_UI_ResetSlotFrames 0x021EF508 thumb
 *   BOX2_MAIN_RefreshMonInfo 0x021DEF98 thumb ov170
 *   BOX2_MAIN_SetHandSlots 0x021DF110 thumb ov170
 *   BOX2_UI_PutTopBarThenClose 0x021EF6A8 thumb ov170
 *   BOX2_MAIN_UpdateWindowMove 0x021E01A8 thumb ov170
 *   BOX2_MAIN_SetBodySlots 0x021DF11C thumb ov170
 *   BOX2_UI_RepenTopBar 0x021EF6CC thumb ov170
 *   BOX2_MAIN_HasOtherTradable 0x021DD694 thumb ov170
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   BOX2_MAIN_StepScroll 0x021DE7C8 thumb ov170
 *   BOX2_MAIN_DeleteScroll 0x021DE7B4 thumb ov170
 *   BOX2_MAIN_ClearSlot 0x021DD314 thumb
 *   BOX2_MAIN_StateMachineOpen 0x021E002C thumb
 *   d_021EF908 0x021EF908 data a4
 *   BOX_SAVEDATA_CheckFlags 0x02007A80 thumb
 *   d_021EF9C8 0x021EF9C8 data
 *   d_021EF93C 0x021EF93C data
 *   d_021EF964 0x021EF964 data
 *   d_021EF978 0x021EF978 data
 *   d_021EF98C 0x021EF98C data
 *   d_021EF9A0 0x021EF9A0 data
 *   d_021EF9E0 0x021EF9E0 data
 *   d_021EF928 0x021EF928 data
 *   d_021EF9F8 0x021EF9F8 data
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   BOX2_MAIN_LoadBoxPalette 0x021DED58 thumb ov170
 *   BOX_SAVEDATA_SetWallpaper 0x02007838 thumb
 *   BOX2_MAIN_InitSeq  0x021DC9A0  thumb  ov170
 *   BOX2_MAIN_RestartSeq  0x021DC9B8  thumb  ov170
 *   BOX2_MAIN_OpenTaskMenu 0x021DCF58 thumb
 *   MYITEM_SAVEDATA_AddItem 0x02007E50 thumb
 *   BOX2_MAIN_SetBoxForm 0x021DEFF8 thumb ov170
 *   BOX2_MAIN_ResetMovers 0x021DE728 thumb ov170
 *   BOX2_MAIN_ClearPerapVoiceIfNoChatot  0x021DE898  thumb  ov170
 *   BOX2_MAIN_SetupWindowFrameFade  0x021DD090  thumb  ov170
 *   data_021EFA10 0x021EFA10 data a1
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb
 *   MYITEM_SAVEDATA_RemoveItem 0x02007F1C thumb
 *   data_021EF918 0x021EF918 data a1
 *   BOX2_MAIN_RefreshBoxUi 0x021DD1E8 thumb
 *   BOX2_MAIN_SceneMoveCursor 0x021E072C thumb
 *   BOX2_MAIN_StateMachineScroll 0x021DFA30 thumb
 *   BOX2_MAIN_StateMachinePen  0x021E0470  thumb  ov170
 *   BOX2_MAIN_StateMachinePick 0x021DF484 thumb
 *   BOX2_MAIN_StateMachineMove 0x021E0200 thumb
 *   BOX2_UI_PutTopBarOpen  0x021EF32C  thumb  ov170
 *   BOX2_UI_PutTopBarClosed  0x021EF33C  thumb  ov170
 *   d_021F140C 0x021F140C data a1
 *   CURSOR_MOVE_SetSkipBit 0x0202614C thumb
 *   d_021EF8FC 0x021EF8FC data a1
 *   d_021EF8F4 0x021EF8F4 data a1
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_021EFC20 0x021EFC20 data a1
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   BMP_WIN_ClearScreen  0x020456F8  arm  arm9
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_Clear 0x02043B5C arm
 *   WORDSET_SetSlotMonNameAlt 0x0201EEA4 thumb
 *   WORDSET_SetSlotMonNicknameAlt 0x0201EF14 thumb
 *   PRINTSYS_MeasureWidestLine 0x0201D304 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotFromMsg18 0x0201EF98 thumb
 *   WORDSET_SetSlotFromMsgB6 0x0201EF8C thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   ARC_UTIL_LoadBgCharDataFromArchive 0x02049DB4 arm
 *   BMP_CreateFromBuffer 0x020436FC arm
 *   BMP_Blit 0x020439A0 arm
 *   BMP_Delete 0x020437AC arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  ov170
 *   BOX2_UI_HideSlots678 0x021EE0FC thumb
 *   BOX2_UI_CreateBmpOam 0x021EE120 thumb ov170
 *   BOX2_UI_DeleteBmpOam  0x021EE200  thumb  ov170
 *   BOX2_MAIN_GetDispVram 0x021DC9D8 thumb ov170
 *   CLACT_InitSystem 0x0204A48C arm
 *   d_021EFD64 0x021EFD64 data a4
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BOX2_UI_CreatePartyActors 0x021ED824 thumb ov170
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm  arm9
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm  arm9
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   d_021EFD04 0x021EFD04 data a4
 *   BOX_SAVEDATA_GetPokemonValue 0x020079BC thumb
 *   MIi_CpuCopy32 0x02082A90 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   d_021EFD4C 0x021EFD4C data a2
 *   d_021EFCE0 0x021EFCE0 data a1
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAffineOrigin 0x0204B588 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   d_021EFD80 0x021EFD80 data a4
 *   APP_ICON_GetTypeCellFileId 0x020275F8 thumb
 *   APP_ICON_GetTypePaletteFileId 0x020275FC thumb
 *   APP_ICON_GetTypeAnimFileId 0x02027600 thumb
 *   APP_ICON_GetTouchBarFileId 0x020275E8 thumb
 *   APP_ICON_GetEffectCellFileId 0x0202774C thumb
 *   APP_ICON_GetEffectPaletteFileId 0x02027750 thumb
 *   APP_ICON_GetEffectAnimFileId 0x02027754 thumb
 *   APP_ICON_GetBallOpenAnimFileId 0x02027748 thumb
 *   APP_ICON_GetGearExtraFileId 0x0202776C thumb
 *   APP_ICON_GetGearFrameFileId 0x02027770 thumb
 *   APP_ICON_GetGearAnim2FileId 0x02027774 thumb
 *   APP_ICON_GetGearDataFileId 0x02027768 thumb
 *   d_021EFD34 0x021EFD34 data a4
 *   APP_ICON_GetTypePaletteOffset 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   FILE_UTIL_GetItemCount 0x02020F08 thumb
 *   ARC_UTIL_LoadScreenDataFromArchive 0x02049E34 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   CLACT_GetActorPaletteIndex 0x0204B7F8 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   CLACT_GetActorDrawPriority 0x0204B838 arm
 *   CLACT_GetActorBgPriority 0x0204B864 arm
 *   d_021EFE70 0x021EFE70 data a1
 *   d_021EFCD0 0x021EFCD0 data a1
 *   d_021EFCC8 0x021EFCC8 data a1
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   CLACT_TransferCharacterPart  0x0204AA94  arm  arm9
 *   CLACT_SetActorDrawPriority  0x0204B800  arm  arm9
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_AddActorAnimFrame  0x0204B8D4  arm  arm9
 *   CLACT_GetActorAutoAnim  0x0204B944  arm  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   CLACT_SetActorBgPriority  0x0204B84C  arm  arm9
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *   CLACT_AddActorSurfacePos  0x0204B404  arm  arm9
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm  arm9
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *   BOX2_MAIN_StateMachineRunSwap 0x021E09E0 thumb ov170
 *   BOX2_MAIN_StateMachineShowHandScroll 0x021E0A40 thumb ov170
 *   BOX2_MAIN_StateMachineDrag 0x021E0ABC thumb ov170
 *   BOX2_MAIN_StateMachineHideHandWindow 0x021E0ED4 thumb ov170
 *   BOX2_MAIN_StateMachineHideHand 0x021E0F4C thumb ov170
 *   BOX2_MAIN_MoveCursorTo 0x021E0FB0 thumb ov170
 *   BOX2_MAIN_StateMachineDragNoBar 0x021E0FD8 thumb ov170
 *   BOX2_MAIN_StateMachineReturnHeld 0x021E122C thumb ov170
 *   ARC_UTIL_LoadScreenDataFromHandle  0x02049E74  arm  arm9
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fsub                        0x0209CB8C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "box2_types.h"
#include "../ov067/touchbar.h"
#include "../arm9/clact.h"
/* The DS code passes the palette offset as a word (the original prototype); the header takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define POKEGRA_RegisterPalettePP POKEGRA_RegisterPalettePP_header
#endif
#include "../arm9/pokegra.h"
#ifdef __MWERKS__
#undef POKEGRA_RegisterPalettePP
extern int POKEGRA_RegisterPalettePP(int handle, void *pp, int dir, int drawType, u32 palOffset, unsigned short heapId);
#endif

#include "../arm9/box_savedata.h"


struct Unit;

struct Bmp;

struct BmpWin;

#include "../arm9/arc_tool.h"

#include "../arm9/gfl_heap_wrap.h"

#include "../arm9/msgdata.h"

#include "../arm9/strbuf.h"




struct Cursor;
extern u32 CURSOR_MOVE_GetState(struct Cursor *obj);

#include "../arm9/ui.h"

#include "../arm9/bgwinfrm.h"



extern void BOX2_UI_UpdateCurrentBoxMarker(BoxTask *p);

extern void CURSOR_MOVE_SetState(struct Cursor *obj, u32 state);

extern void BOX2_UI_DrawSlot(BoxTask *p, int i);

#include "../arm9/poke_tool.h"

extern void BOX2_UI_DrawSlotByName(char *p, int a);

#include "../arm9/file_util.h"




extern int BOX2_MAIN_ShiftWindowRight(BoxTask *p);

extern int BOX2_UI_UpdateListPacks(struct BgWinFrmWork *mgr);

#include "../arm9/touchpanel.h"

extern void BOX2_UI_OpenListPack(struct BgWinFrmWork *mgr);


extern int BOX2_UI_IsInfoBarOpen(struct BgWinFrmWork *mgr);

extern void BOX2_UI_CloseInfoBar(struct BgWinFrmWork *mgr);

extern int BOX2_UI_IsTopBarOpen(struct BgWinFrmWork *mgr);

extern int BOX2_UI_GetPageButtonHit(void);

extern void BOX2_UI_SlideBarIn(struct BgWinFrmWork *mgr);

extern void CURSOR_MOVE_ClearSkipBit(struct Cursor *obj, u32 idx);

extern int BOX2_UI_IsTopBarClosed(struct BgWinFrmWork *mgr);

extern int BOX2_UI_IsListClosed(struct BgWinFrmWork *mgr);

extern void BOX2_UI_CloseListPack(struct BgWinFrmWork *mgr);

extern int BOX2_UI_GetPartySlotPoint(int a, int b);

extern void BOX2_UI_MoveCursor(char **p, int idx, int v);

extern int BOX2_UI_GetCloseButtonHit(void);

extern void BOX2_UI_OpenBar(struct BgWinFrmWork *mgr);

extern int BOX2_MAIN_StepScrollToPrevBox(BoxTask *p);

extern int BOX2_MAIN_StepScrollToNextBox(BoxTask *p);

extern void BOX2_UI_PutBottomBarClosed(struct BgWinFrmWork *mgr);

extern void BOX2_UI_CloseBar(struct BgWinFrmWork *mgr);

extern int BOX2_UI_UpdateBarMove(BoxTask *p);

extern void CURSOR_MOVE_SetCurrent(struct Cursor *obj, u8 sel);

extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);

extern const unsigned char d_021EF79C[];

extern const unsigned char d_021EF7B4[];
























extern int BOX2_MAIN_MoveCursorWithMon(BoxTask *p, unsigned a, unsigned b);

#include "../arm9/gfl_use.h"

extern int BOX2_MAIN_HitBoxGrid(short x, int y);

extern int BOX2_MAIN_FindMoverSlot(BoxTask *p, unsigned id);

extern void BOX2_MAIN_StepToAdjacentBox(BoxTask *p, int dir);

extern void BOX2_MAIN_MoveCursorActor(BoxTask *p, int x, int y);

extern int BOX2_MAIN_WaitCursorMove(BoxTask *p);

extern void BOX2_MAIN_ResetBoxView(BoxTask *p);

extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);

extern void BOX2_UI_DeleteSlotObjects(BoxTask *p, int a, int b, int c);

extern void BOX2_UI_SetMiniIconVisible(BoxTask *p, int a, int b);

extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);

extern int BOX2_MAIN_GetBoxWallpaper(BoxTask *p, int box);

extern void BOX2_MAIN_SetBoxScroll(BoxTask *p, void *a, int dir);

extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);







#define ABS(x) ((x) < 0 ? -(x) : (x))










#define HEAP 0x804C



struct Ov170Ctx;

struct BmpWin;

struct Strbuf;

struct Bmp;

struct Bmp;

struct Obj;

struct ClactActor;

struct BoxActorSlotTable;

struct ClactVec2;

struct ClactVec2;

struct Box2SeqPair;

struct Pt16;

struct NNSG2dCharacterData;

struct Struct36;








struct BoxCountWork {
    char pad[0xA18C];
    int count;
};

typedef struct { int (*a)(char *); int (*b)(char *); } Box2SeqPair;

typedef struct { void (*callback)(u8 *); u32 value; u32 next; } Dispatch;

typedef struct {
    short left;
    short dir;
} Scroll;

typedef struct { unsigned short a; unsigned short b; } Ent;

/* One text-window entry. Views differed only in how many trailing
   fields they named; the status byte is 0x12 (low/flag) and 0x13
   (kind/enabled/rest). */
typedef struct BoxSeqEntry {
    unsigned value;              /* 0x00 */
    unsigned char pad_4[0x0E];   /* 0x04 */
    unsigned char low : 7;       /* 0x12 */
    unsigned char flag : 1;      /* 0x12 */
    unsigned char kind : 4;      /* 0x13 */
    unsigned char enabled : 1;   /* 0x13 */
    unsigned char rest : 3;      /* 0x13 */
} BoxSeqEntry;

typedef struct BoxWorkView {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} BoxWorkView;








typedef struct {
    void *obj;
    int pad;
} Box2SeqItem;

typedef struct {
    unsigned char pad[0x94];
    Box2SeqItem items[14];
} Box2SeqWork;

typedef struct {
    unsigned char pad[0x14];
    char *raw;
} Chr;

typedef struct {unsigned a,b,c,d,e,f,g;} Template;

typedef struct {
    short x;
    short y;
    unsigned char pad4[2];
    unsigned char b6;
    unsigned char b7;
    int a;
    int b;
    int c;
    unsigned short e;
    unsigned short d;
} Box2SeqDesc;

typedef struct {
    Box2SeqDesc a[13];
    Box2SeqDesc b[6];
    Box2SeqDesc c[6];
    Box2SeqDesc d[3];
} DescTable;

struct BoxActorSlotTable { char pad[0x9E74]; int arr[1]; };

typedef struct { short x; short y; } BoxPos;

typedef struct { unsigned char a; unsigned char b; } Off;

typedef struct {
    int pad[9];
    int mode;
} Top;

typedef struct {unsigned char low:7;unsigned char high:1;} Flag;

struct Box2SeqSlot { unsigned char a[0x1c]; unsigned char f : 4; };

typedef struct {
    int w[9];
} Struct36;
struct BoxMover;
struct BoxTask;

extern void BOX2_MAIN_SetMoverEntry(struct BoxTask *task, struct BoxMover *e);

extern int BOX2_MAIN_SceneApplyScroll(BoxTask *p);

extern int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b);

extern void BOX2_MAIN_StartHandMotionToBoxSlot(int a, int b, int c, int d);

extern int BOX2_MAIN_StepHandMotionToSlot(int a);

extern int BOX2_MAIN_IsWindowMoving(BoxTask *p);

extern void BOX2_MAIN_StartHandMotionToTargetBoxSlot(BoxTask *p, int a, int b);

extern int BOX2_MAIN_StepHandMotionToSlotB(unsigned char *p);


extern u8 CURSOR_MOVE_GetCurrent(struct Cursor *obj);

extern void BOX2_UI_AddSlotIcon(BoxTask *p, int d);

struct PrintQueue;
/* The DS code was built against a prototype with a halfword x (the header has a word x). The host build uses the header. */
#ifdef __MWERKS__
#define PRINTSYS_PrintColor PRINTSYS_PrintColor_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintColor
extern void PRINTSYS_PrintColor(struct Bmp *bmp, s16 x, s16 y, struct Strbuf *str, struct GfFont *font, u16 color);
#endif

#include "../arm9/gf_overlay.h"

#include "../arm9/bg_sys.h"



#include "../arm9/gfl_heap.h"

#include "../arm9/key.h"


extern void BOX2_MAIN_ResetGraphics(void);

extern void BOX2_MAIN_InitBgSys(u8 *);

extern void BOX2_MAIN_CreatePalAnm(BoxTask *p);

extern void BOX2_MAIN_LoadBgData(struct Ov170Ctx *ctx);

extern void BOX2_MAIN_CreateTextSystem(char *);

extern void BOX2_MAIN_LoadFormTable(char *p);

extern void BOX2_UI_InitWindowFrames(struct BoxTask *task);

extern void BOX2_UI_DrawAllSlots(u8 *task);

extern void BOX2_UI_CreateCursor(char **);

extern void BOX2_MAIN_CreateTaskMenu(char *);

extern void BOX2_MAIN_SetDisplayControl(int);

#include "../arm9/net.h"

extern void BOX2_MAIN_CreateVBlankTask(BoxTask *p);

extern void BOX2_MAIN_DeleteVBlankTask(BoxTask *p);

extern void BOX2_MAIN_DeleteTaskMenu(BoxTask *p);

extern void BOX2_UI_DeleteCursorMove(int *p);
struct BoxWork;

extern void BOX2_UI_DeleteWindowFrames(struct BoxWork *work);

extern void BOX2_MAIN_DeleteFormTable(BoxTask *p);

extern void BOX2_MAIN_DeleteTextSystem(char *p);

extern void BOX2_MAIN_DeletePalAnm(int *p);

extern void BOX2_MAIN_DeleteBgSys(void *p);




#include "../arm9/wipe.h"

#include "../arm9/arc_util.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/myitem_savedata.h"
#include "../arm9/poke_tool_ext.h"
#include "../arm9/pokeparty.h"



#include "../arm9/app_taskmenu.h"




extern int BOX2_MAIN_StepWindowFrameFade(BoxTask *p);

extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(BoxTask *p, int b);




extern int BOX2_UI_GetBackButtonPoint(unsigned *a, unsigned *b);

extern void BOX2_MAIN_SelectBox(BoxTask *p, int a);

extern unsigned BOX2_UI_GetPartySlotHit(void);



extern int BOX2_UI_IsListOpen(struct BgWinFrmWork *mgr);

extern void BOX2_MAIN_RefreshCursorBox(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputC(BoxTask *p);

extern void BOX2_MAIN_ClearCursorBox(unsigned char *p);

extern void BOX2_UI_MoveCursorBetweenIcons(struct BoxWork *q, s32 a, s32 b);


extern void BOX2_MAIN_ActivateKeyCursor(BoxTask *p);

extern void BOX2_UI_SelectSlot(BoxTask *p, unsigned r);

extern int BOX2_UI_GetExitButtonPoint(unsigned *a, unsigned *b);

extern unsigned BOX2_UI_CursorInputLeft(BoxTask *p);

extern void BOX2_UI_PutBottomBarOpen(struct BgWinFrmWork *mgr);

extern unsigned BOX2_UI_GetHandSlotHit(void);

extern unsigned BOX2_UI_UpdateCursorInputD(BoxTask *p);


extern void BOX2_UI_HideWindowA(struct BoxWork *work);

extern void BOX2_UI_HideWindowB(struct BoxWork *work);

extern unsigned BOX2_UI_CursorInputRight(BoxTask *p);

extern unsigned BOX2_UI_GetBodySlotHit(void);

extern void BOX2_UI_SlideBarOut(struct BgWinFrmWork *mgr);

extern unsigned BOX2_UI_UpdateCursorInputG(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputH(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputB(BoxTask *p);

extern int BOX2_MAIN_SceneWaitScroll(BoxTask *p);

extern int BOX2_MAIN_StateMachineClose(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputA(BoxTask *p);

extern int BOX2_MAIN_SceneWaitCursor(BoxTask *p);

extern void BOX2_UI_PlaceCursorAtIcon(BoxTask *p, unsigned idx);

extern int CURSOR_MOVE_PollRepeatInput(struct Cursor *obj);




extern void BOX2_UI_PlaceCursorAtMon(BoxTask *p, unsigned int i);

extern int BOX2_MAIN_SceneOpenBox(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputE(BoxTask *p);


extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);

extern int BOX2_MAIN_SyncItemForm(void **pp, void *mon);

extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);

extern unsigned BOX2_UI_UpdateCursorInputF(BoxTask *p);

extern unsigned BOX2_UI_CursorInputPage(BoxTask *p);

extern int BOX2_MAIN_GetBoxValue(char *p, u32 a);

extern void BOX2_UI_ResetSlotFrames(struct BgWinFrmWork *mgr);

extern int BOX2_MAIN_RefreshMonInfo(char *p, int a, unsigned b);

extern void BOX2_MAIN_SetHandSlots(char *p, int b);

extern void BOX2_UI_PutTopBarThenClose(struct BgWinFrmWork *mgr);

extern int BOX2_MAIN_UpdateWindowMove(char *p);

extern void BOX2_MAIN_SetBodySlots(char *p, int b);

extern void BOX2_UI_RepenTopBar(struct BgWinFrmWork *mgr);

extern int BOX2_MAIN_HasOtherTradable(void ***, unsigned);
struct Party;
struct PokemonParam;




extern int BOX2_MAIN_StepScroll(BoxTask *p);

extern void BOX2_MAIN_DeleteScroll(BoxTask *p);

extern void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);

extern int BOX2_MAIN_StateMachineOpen(unsigned char *p);


#include "../arm9/palanm.h"



extern void BOX2_MAIN_LoadBoxPalette(struct BoxTask *task, s32 a);



extern void BOX2_MAIN_InitSeq(struct BoxWork *work, s32 v);

extern void BOX2_MAIN_RestartSeq(struct BoxWork *work);

extern void BOX2_MAIN_OpenTaskMenu(BoxTask *p, int sel);


extern void BOX2_MAIN_SetBoxForm(BoxTask *p, unsigned b);

extern void BOX2_MAIN_ResetMovers(BoxTask *p);

extern void BOX2_MAIN_ClearPerapVoiceIfNoChatot(int *q);

extern void BOX2_MAIN_SetupWindowFrameFade(struct BoxTask *task, u32 idx);

extern void BOX2_UI_PutListFrames(struct BgWinFrmWork *mgr);
struct MyItem;


extern void BOX2_MAIN_RefreshBoxUi(BoxTask *p);

extern void BOX2_MAIN_SceneMoveCursor(BoxTask *p);

extern int BOX2_MAIN_StateMachineScroll(BoxTask *p);

extern int BOX2_MAIN_StateMachinePen(BoxTask *p);

extern int BOX2_MAIN_StateMachinePick(BoxTask *p);

extern int BOX2_MAIN_StateMachineMove(BoxTask *p);

extern void BOX2_UI_PutTopBarOpen(struct BgWinFrmWork *mgr);

extern void BOX2_UI_PutTopBarClosed(struct BgWinFrmWork *mgr);

extern void CURSOR_MOVE_SetSkipBit(struct Cursor *obj, u32 idx);

#include "../arm9/bmp_win.h"











struct GfFont;

struct WordSet;

#include "../arm9/wordset.h"

typedef short s16_p07;
#include "../arm9/bmp.h"
















#include "../arm9/app_icon.h"




struct BmpOam;

#include "../arm9/bmp_oam.h"




extern void BOX2_UI_HideSlots678(BoxTask *p);

extern void BOX2_UI_CreateBmpOam(struct BoxWork *work);



extern void BOX2_UI_DeleteBmpOam(char *);

extern void CLACT_ExitSystem(void);



extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern struct Unit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);



extern void CLACT_SetActorVisible(struct ClactActor *a, u32 v);


extern u32 CLACT_DeleteUnit(struct Unit *bank);



extern void CLACT_DrawSystem(void);




extern u32 CLACT_IsActorAnimActive(struct ClactActor *a);




extern void CLACT_SetActorDrawPriority(struct ClactActor *node, u32 val);

extern void CLACT_SetActorObjMode(struct ClactActor *actor, u32 value);


extern void CLACT_GetActorSurfacePos(struct ClactActor *actor, struct ClactVec2 *out, u16 space);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);






extern int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);






#include "../arm9/mi_memory.h"


#include "../ov170/box2_main.h"
#include "../ov170/box2_ui.h"

extern void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e);


extern void CLACT_SetActorAffineMode(struct ClactActor *actor, u32 value);


extern void CLACT_SetActorAffineOrigin(struct ClactActor *actor, const struct Pt16 *src);



extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);




















extern void CLACT_TransferCharacter(int a, struct NNSG2dCharacterData *b);



struct PaletteData;
extern void CLACT_TransferPalette(u32 idx, struct PaletteData *dest, u32 count);





int BOX2_MAIN_StateMachineRunSwap(BoxTask *p);

int BOX2_MAIN_StateMachineShowHandScroll(BoxTask *p);

int BOX2_MAIN_StateMachineDrag(BoxTask *p);

int BOX2_MAIN_StateMachineHideHandWindow(BoxTask *p);

int BOX2_MAIN_StateMachineHideHand(BoxTask *p);

void BOX2_MAIN_MoveCursorTo(struct BoxWork *w, s32 x, s32 y);

int BOX2_MAIN_StateMachineDragNoBar(BoxTask *p);

int BOX2_MAIN_StateMachineReturnHeld(BoxTask *p);

int BOX2_SEQ_StateMenuSelect(BoxTask *p);

int BOX2_SEQ_StateMenuSwap(BoxTask *p);

int BOX2_SEQ_StateMenuMain(BoxTask *p);

int BOX2_SEQ_StateMachineMove(BoxTask *p);

int BOX2_SEQ_StateExitBox(BoxTask *p);

int BOX2_SEQ_OpenBoxUp(BoxTask *p);

int BOX2_SEQ_OpenBoxDown(BoxTask *p);

int BOX2_SEQ_OpenBoxLeft(BoxTask *p);

int BOX2_SEQ_OpenBoxRight(BoxTask *p);

int BOX2_SEQ_StateMachineScroll(BoxTask *p);

int BOX2_SEQ_UpdatePrintQueue(BoxTask *p, int *state);

int BOX2_SEQ_CreateBox2Main(u8 *p);

int BOX2_SEQ_DeleteBox2Main(BoxTask *p);

int BOX2_SEQ_StateWaitWipe(char *p);

int BOX2_SEQ_StateWaitFade(void *p);

int BOX2_SEQ_StateWaitCount(void *p);

int BOX2_SEQ_StateRunStep(char *p);

int BOX2_SEQ_StateWaitInput(BoxTask *p);

int BOX2_SEQ_StateTaskMenu(char *p);

int BOX2_SEQ_StateCheckTaskMenu(int p);

int BOX2_SEQ_StateDispatchFont(unsigned char *p);

int BOX2_SEQ_StateDispatchStep(u8 *p);

int BOX2_SEQ_DeleteBox2Ui(BoxTask *p);

int BOX2_SEQ_StateWaitPrint(int p);

int BOX2_SEQ_StateSetMenu(unsigned char *p);

int BOX2_SEQ_StateItemMenu(BoxTask *p);

int BOX2_SEQ_SetBox2Main(unsigned char *p);

int BOX2_SEQ_StateCloseBox(unsigned char *p);

int BOX2_SEQ_StateBoxMenu(BoxTask *p);

int BOX2_SEQ_StateOpenSummary(BoxTask *p);

void BOX2_SEQ_SetBox2Ui(BoxTask *p);

int BOX2_SEQ_StateSummary(u8 *p);

int BOX2_SEQ_StateSummaryInput(BoxTask *p);

int BOX2_SEQ_StateSummaryClose(u8 *p);

int BOX2_SEQ_StateSwapMenu(unsigned char *p);

int BOX2_SEQ_StateSwapConfirm(BoxTask *p);

int BOX2_SEQ_StateSwapApply(u8 *p);

int BOX2_SEQ_StateSwapFinish(BoxTask *p);

int BOX2_SEQ_StateMoveMove(BoxTask *p);

int BOX2_SEQ_StateMoveFinish(BoxTask *p);

void BOX2_SEQ_SetBox2UiB(BoxTask *p);

int BOX2_SEQ_StateOpenSummaryB(BoxTask *p);

int BOX2_SEQ_StateSummaryB(BoxTask *p);

int BOX2_SEQ_StateMoveInput(BoxTask *p);

int BOX2_SEQ_StateMoveClose(BoxTask *p);

int BOX2_SEQ_StateMoveCloseB(BoxTask *p);

int BOX2_SEQ_StateItemMenuB(BoxTask *p);

int BOX2_SEQ_StateOpenItemB(BoxTask *p);

void BOX2_SEQ_SetBox2UiC(BoxTask *p);

int BOX2_SEQ_StateSwapMenuB(BoxTask *p);

int BOX2_SEQ_StateItemMoveB(BoxTask *p);

int BOX2_SEQ_StateMoveFinishB(BoxTask *p);

void BOX2_SEQ_SetBox2UiD(BoxTask *p);

int BOX2_SEQ_StateOpenItemC(u8 *p);

int BOX2_SEQ_StateMenuCursor(BoxTask *p);

int BOX2_SEQ_StateItemMenuC(BoxTask *p);

void BOX2_SEQ_SetBox2MainB(u8 *p);

int BOX2_SEQ_StateCloseBoxB(BoxTask *p);

int BOX2_SEQ_StateOpenBoxC(u8 *p);

int BOX2_SEQ_DeleteBox2UiB(BoxTask *p);

int BOX2_SEQ_StateItemMenuD(BoxTask *p);

void BOX2_SEQ_SetBox2MainC(u8 *p);

int BOX2_SEQ_StateCursorMove(BoxTask *p);

int BOX2_SEQ_StateSummaryC(BoxTask *p);

int BOX2_SEQ_StateListScroll(BoxTask *p);

int BOX2_SEQ_StateScrollBox(BoxTask *p);

int BOX2_SEQ_StateOpenItemD(u8 *p);

int BOX2_SEQ_StateOpenItemE(unsigned char *p);

int BOX2_SEQ_StateItemMenuE(BoxTask *p);

int BOX2_SEQ_SetBox2UiE(BoxTask *p);

int BOX2_SEQ_DeleteBox2UiC(BoxTask *p);

void BOX2_SEQ_StateCloseBoxC(u8 *p);

int BOX2_SEQ_StateMenuItems(BoxTask *p);

int BOX2_SEQ_StateSelectItem(u8 *p);

int BOX2_SEQ_StateSummaryD(BoxTask *p);

int BOX2_SEQ_StateItemMenuF(BoxTask *p);

int BOX2_SEQ_StateCloseItem(BoxTask *p);

int BOX2_SEQ_StateMoveItemScroll(BoxTask *p);

int BOX2_SEQ_StateMoveItemB(BoxTask *p);

int BOX2_SEQ_StateCloseItemB(u8 *p);

int BOX2_SEQ_StatePlaceItem(BoxTask *p);

int BOX2_SEQ_StateCursorMoveB(BoxTask *p);

int BOX2_SEQ_SetBox2UiF(BoxTask *p);

int BOX2_SEQ_StateMoveItemC(u8 *p);

int BOX2_SEQ_StatePlaceItemB(BoxTask *p);

int BOX2_SEQ_StateMoveItemD(BoxTask *p);

int BOX2_SEQ_StateCursorMoveC(BoxTask *p);

int BOX2_SEQ_StatePushSlot(char *p);

int BOX2_SEQ_StateSwapMenuC(BoxTask *p);

void BOX2_SEQ_SetBox2MainD(BoxTask *p);

int BOX2_SEQ_StateCloseItemC(unsigned char *p);

int BOX2_SEQ_StateSwapMenuD(BoxTask *p);

int BOX2_SEQ_SetBox2MainE(BoxTask *p);

int BOX2_SEQ_StateSwapFinishB(BoxTask *p);

int BOX2_SEQ_StateCloseItemD(u8 *p);

void BOX2_SEQ_StateExitToField(BoxTask *p);

int BOX2_SEQ_StateSwapMenuE(BoxTask *p);

int BOX2_SEQ_StateCloseMenu(BoxTask *p);

int BOX2_SEQ_StateSummaryE(BoxTask *p);

int BOX2_SEQ_StateDeleteHandle(BoxTask *p);

int BOX2_SEQ_StateConfirmRelease(BoxTask *p);

int BOX2_SEQ_StateCloseZoom(unsigned char *p);

int BOX2_SEQ_StateReleaseMon(BoxTask *p);

int BOX2_SEQ_StateOpenZoom(BoxTask *p);

int BOX2_SEQ_StateZoomMenu(BoxTask *p);

int BOX2_SEQ_StateClosePmVoice(BoxTask *p);

int BOX2_SEQ_StateMoveMenu(BoxTask *p);

int BOX2_SEQ_StateMoveMenuB(BoxTask *p);

int BOX2_SEQ_StatePmVoiceMenu(BoxTask *p);

int BOX2_SEQ_StatePmVoiceConfirm(BoxTask *p);

int BOX2_SEQ_StateSetMiniIcon(BoxTask *p);

int BOX2_SEQ_StateMoveMenuC(BoxTask *p);

int BOX2_SEQ_StateClosePmVoiceB(BoxTask *p);

int BOX2_SEQ_StateFadeBox(BoxTask *p);

int BOX2_SEQ_StateCloseItemE(unsigned char *p);

void BOX2_SEQ_HideCursorSlot(u8 *p);

int BOX2_SEQ_ReturnAfterClear(BoxTask *p, int v);

int BOX2_SEQ_StartWipeWhite(void *p, int a);

int BOX2_SEQ_StartWipeBlack(void *p, int a);

int BOX2_SEQ_SetSeqThird(BoxTask *p, int a, int b);

int BOX2_SEQ_SetSeqSecond(BoxTask *p, int a);

int BOX2_SEQ_SetState(BoxTask *p, int v);

int BOX2_SEQ_OpenYesNo(BoxTask *p, int sel);

int BOX2_SEQ_StateUseItem(BoxTask *p);

int BOX2_SEQ_StateUseItemWait(BoxTask *p);

int BOX2_SEQ_StateUseItemDone(BoxTask *p);

int BOX2_SEQ_StateUseItemMenu(BoxTask *p);

int BOX2_SEQ_StateExitBoxWithSe(BoxTask *p);

int BOX2_SEQ_StateCloseItemMenu(BoxTask *p);

void BOX2_SEQ_SaveMenuPosAndExit(BoxTask *p);

int BOX2_SEQ_StatePmVoiceClose(BoxTask *p);

void BOX2_SEQ_StateEnterItemMenu(unsigned char *p);

int BOX2_SEQ_GotoBox2Main(BoxTask *p, int a, int b);

int BOX2_SEQ_SetupFrameFadeAndWait(BoxTask *p,int a,int b);

int BOX2_SEQ_GotoBox2MainWithSlot(BoxTask *p, int id, int lo, int arg);

int BOX2_SEQ_GotoBox2Ui(BoxTask *p, unsigned char v);

int BOX2_SEQ_StatePmVoiceMenuB(BoxTask *p);

int BOX2_SEQ_StatePmVoiceMenuC(BoxTask *p);

int BOX2_SEQ_StatePmVoiceMenuD(BoxTask *p);

int BOX2_SEQ_StatePmVoiceOpen(unsigned char *p);

int BOX2_SEQ_StatePmVoiceOpenB(BoxTask *p);

int BOX2_SEQ_StatePmVoiceOpenC(BoxTask *p);

int BOX2_SEQ_StatePmVoiceOpenD(BoxTask *p);

int BOX2_SEQ_GotoRightPanelA(BoxTask *p, int a, int n);

int BOX2_SEQ_GotoRightPanelB(BoxTask *p, int a, int n);

int BOX2_SEQ_SelectSlotA(BoxTask *p, int i);

int BOX2_SEQ_SelectSlotB(BoxTask *p, int i);

int BOX2_SEQ_SelectSlotC(BoxTask *p, int a);

int BOX2_SEQ_GotoSlotHandlerA(BoxTask *p, int i, int v);

int BOX2_SEQ_SelectPartySlotA(unsigned char *p, int i);

int BOX2_SEQ_SelectPartySlotB(BoxTask *p, int i);

int BOX2_SEQ_SelectPartySlotC(BoxTask *p, int i);

int BOX2_SEQ_GotoSlotHandlerB(BoxTask *p, int i, int v);

int BOX2_SEQ_SelectSlotD(BoxTask *p, int i, int v);

int BOX2_SEQ_HideSlotWindow(BoxTask *p, unsigned char i);

int BOX2_SEQ_SelectBoxSlot(BoxTask *p, int a);

int BOX2_SEQ_ScrollListToSlot(BoxTask *p, unsigned i, int v);

void BOX2_SEQ_Create(void *p);

void BOX2_SEQ_Delete(BoxTask *p);

int BOX2_SEQ_DrawGridSlot(BoxTask *p, int i);

int BOX2_SEQ_SetCursorMove(BoxTask *p, int i);

int BOX2_SEQ_SelectGridSlot(BoxTask *p, unsigned i);

int BOX2_SEQ_DrawGridSlotB(BoxTask *p, unsigned i);

int BOX2_SEQ_UpdateGridCursor(BoxTask *p);

int BOX2_SEQ_MoveGridCursor(BoxTask *p, unsigned i);

int BOX2_SEQ_DeleteGridSlot(BoxTask *p, int i);

int BOX2_SEQ_SetCursorMoveB(BoxTask *p, int i);

void BOX2_SEQ_CreateB(void *p);

void BOX2_SEQ_DeleteB(BoxTask *p);

void BOX2_SEQ_StopLeftBar(int p);

void BOX2_SEQ_StopRightBar(int p);

void BOX2_SEQ_RestartLeftBar(int p);

int BOX2_SEQ_DrawListSlot(BoxTask *p, int sel);

void BOX2_SEQ_CreateC(BoxTask *p);

int BOX2_SEQ_RefreshBoxUiAndWait(char *p, int a);

int BOX2_SEQ_ResetEntryB(BoxTask *p, int a);

void BOX2_SEQ_SetActorAnim(BoxTask *p, int v);

int BOX2_SEQ_CheckTradableMon(unsigned char *p);

void BOX2_SEQ_ToggleHandSlot(int p, int bit);

int BOX2_SEQ_GotoSceneA(BoxTask *p,int a);

void BOX2_SEQ_DeleteSlotWindows(BoxTask *p);

int BOX2_SEQ_GotoBox2MainPlaySe(BoxTask *p, int v);

int BOX2_SEQ_GotoBox2MainNoSe(BoxTask *p, int v);

void BOX2_SEQ_InitBmpWins(BoxTask *p);

void BOX2_SEQ_DeleteBmpWins(char *p);

void BOX2_SEQ_SetDirtyBit(unsigned char *p, unsigned i);

void BOX2_SEQ_FlushDirtyBmpWins(unsigned char *w);

void BOX2_SEQ_UpdateTextWins(unsigned char *w);

void BOX2_SEQ_MakeScreen(void **p);

void BOX2_SEQ_ClearScreen(void **p);

void BOX2_SEQ_PrintTextWin(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color);

void BOX2_SEQ_PrintTextWinEx(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);

void *BOX2_SEQ_CreateMsgBank(void);

void BOX2_SEQ_PrintMsgWin(BoxTask *p);

void BOX2_SEQ_InitBmpWin(BoxTask *p);

void BOX2_SEQ_FillTextWinEntry(unsigned char *w,BoxSeqEntry *e,unsigned i);

void BOX2_SEQ_FillTextWin(char *p, void **q, int i);

void BOX2_SEQ_DrawCellEntry(char *p, BoxSeqEntry *e, unsigned i);

void BOX2_SEQ_DrawSpriteEntry(char *p, BoxSeqEntry *e, unsigned i);

void BOX2_SEQ_DrawTileEntry(char *p,const BoxSeqEntry *e,u32 i);

void BOX2_SEQ_DrawMoveEntry(char *p, unsigned char *e, int i);

void BOX2_SEQ_DrawSwapEntry(char *p, unsigned char *e, int i);

void BOX2_SEQ_DrawItemEntry(char *p, unsigned char *e, int i);

void BOX2_SEQ_DrawMsgEntry(char *p, BoxSeqEntry *e, int i);

void BOX2_SEQ_DeleteTextEntries(BoxTask *p, void *a);

void BOX2_SEQ_ClearTextWin(BoxWork *work);

void BOX2_SEQ_DrawWindowFrame(BoxTask *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon);

void BOX2_SEQ_DrawFrameColor(int a, int b, int c, int d);

void BOX2_SEQ_DrawFrameDefault(int a, int b, int c);

void BOX2_SEQ_AddBmpWinFrame(void *m,unsigned i,void *d);

void BOX2_SEQ_AddTextFrame(BoxWork *p);

void BOX2_SEQ_AddMsgFrame(unsigned char *p);

void BOX2_SEQ_AddNameFrame(BoxTask *p);

void BOX2_SEQ_DrawBoxName(char **p, unsigned box, int i);

void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i);

void BOX2_SEQ_DrawMonName(char **p, unsigned a, int i);

void BOX2_SEQ_ChangeFramePalette(BoxTask *p);

void BOX2_SEQ_PutNameFrame(char *p);

void BOX2_SEQ_DrawFrameList(BoxTask *p, const void *e, unsigned n);

void BOX2_SEQ_ClearMessageWindow(BoxTask *p, void *win);

void BOX2_SEQ_ShowWindowObject(char *p, int i);

void BOX2_SEQ_HideWindowObject(char *p, int i);

void BOX2_SEQ_PrintMessageMsg(BoxTask *p, int msg, int i);

void BOX2_SEQ_PrintMessageB(char *p, int b);

void BOX2_SEQ_PrintWordset(BoxTask *p, u32 v, int i);

void BOX2_SEQ_PrintMessage(unsigned char *p, int i);

void BOX2_SEQ_PrintMessageC(char *p, int b);

void BOX2_SEQ_PrintWordsetB(char *p, int a, int b);

void BOX2_SEQ_PrintMessageD(char *p, int b);

void BOX2_SEQ_PrintWordsetBB64(BoxTask *p, unsigned v, int i);

void BOX2_SEQ_PrintMessageE(char *p, int b);

void BOX2_SEQ_PrintMonName(BoxTask *p, unsigned kind, int i);

void BOX2_SEQ_PrintIndexedMessage(unsigned char *p,int n,int i);

void BOX2_SEQ_PrintPrompt(BoxTask *p, int sel, int kind, int i);

void BOX2_SEQ_PrintPromptB(BoxTask *p, int kind, int i);

void BOX2_SEQ_PrintMenuRow(char *p, int row, int b);

void BOX2_SEQ_PrintBoxMonName(unsigned char *p);

void BOX2_SEQ_PrintYesNo(char *p, int b);

void BOX2_SEQ_CreateBox2UiScene(BoxTask *p);

void BOX2_SEQ_DeleteBox2UiScene(char *p);

void BOX2_SEQ_InitClact(void *work);

void BOX2_SEQ_LoadBoxGraphics(char *p);

void BOX2_SEQ_ReleaseBoxGraphics(char *p);

void BOX2_SEQ_CreateBox2Actors(unsigned char *p);

void *BOX2_SEQ_CreateActorFromDesc(char *w, const Box2SeqDesc *s);

void BOX2_SEQ_DeleteActorSlot(struct BoxActorSlotTable *p, int i);

void BOX2_SEQ_DeleteAllActors(BoxWork *p);

void BOX2_SEQ_DrawActors(char *p);

void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v);

void BOX2_SEQ_SetActorAutoAnim(char *p, int i, int v);

u32 BOX2_SEQ_IsActorAnimActive(char *p, int i);

void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);

u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i);

void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c);

void BOX2_SEQ_SetActorDrawPriority(char *p, int i, int c);

void BOX2_SEQ_SetActorObjMode(char *p,unsigned i,int b);

void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);

void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);

void BOX2_SEQ_RegisterBoxChars(char *p);

void BOX2_SEQ_RegisterBoxCharsB(BoxWork *p);

void BOX2_SEQ_RegisterIconRes(BoxWork *p);

void BOX2_SEQ_CreateBoxSlotActors(char *p);

void *BOX2_SEQ_LoadGraphicResource(char *p, void *b, void *c);

void BOX2_SEQ_LoadMonIcon(char **p, int box);

void BOX2_SEQ_SetSlotIconPal(char *p, int a, int i, int b);

void BOX2_SEQ_LoadIconResource(BoxTask *p, void *a, int i);

void BOX2_SEQ_ShowSlotIcon(BoxTask *p, int box, int pos, int win);

void BOX2_SEQ_ShowAllSlotIcons(BoxTask *p);

void BOX2_SEQ_ShowPartyIcons(BoxTask *p);

void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);

void BOX2_SEQ_HidePartialSlots(char **p, int flag);

void BOX2_SEQ_HideSlotsC61C(BoxTask *p);

void BOX2_SEQ_HideSlotsC688(BoxTask *p);

void BOX2_SEQ_HideSlotsC6F4(BoxTask *p);

void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);

void BOX2_SEQ_SetSlotDrawPriorityB(char *p, int i, unsigned j, int flag);

void BOX2_SEQ_ShiftSlotIcons(char **p, short dx);

void BOX2_SEQ_MoveActorToWindow(BoxTask *p);

void BOX2_SEQ_ResetActorAffine(char *p);

int BOX2_SEQ_ShrinkActor(char *p);

int BOX2_SEQ_GrowActor(char *p);

void BOX2_SEQ_HideActor(int *p);

void BOX2_SEQ_ResetActorTransform(int *p);

void BOX2_SEQ_SetSlotActorsMode(BoxTask *p, int flag, int i, unsigned end, int mode);

void BOX2_SEQ_SetSlotActors(char *p, int f, int c);

void BOX2_SEQ_SetSlotActorMode(char *p, int i, int f);

void BOX2_SEQ_SetActorMode1(char *a, int b);

void BOX2_SEQ_SwapSlotActors(char *w, unsigned i);

void BOX2_SEQ_SwapSlotActorsB(unsigned char *p, int i);

void BOX2_SEQ_RefreshHandSlot(BoxTask *p);

void BOX2_SEQ_InitIconSlots(BoxWork *p);

void BOX2_SEQ_LoadMonIconActor(char *p,void **mon,int index);

void BOX2_SEQ_LoadBoxScreen(char *w);

void BOX2_SEQ_CreateHandSlotActors(char *p);

void BOX2_SEQ_ShowHandSlot(char *p, int a, int b);

void BOX2_SEQ_ShowHandSlotB(struct BoxWork *p, unsigned char *q);

void BOX2_SEQ_LoadIconPalette(u8*p);

void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item);

void BOX2_SEQ_SetActorAffineMode(char *p, int on);

void BOX2_SEQ_MoveActor(void *a, int b, int c);

void BOX2_SEQ_MoveActorToSlot(char *p, int a, int c);

void BOX2_SEQ_MoveActorToSlotB(char *p, int a, int c);

void BOX2_SEQ_CreateHandSlotActorsB(char *w);

void BOX2_SEQ_ShowHandSlots(char *p);

void BOX2_SEQ_LayoutHandSlots(char *w);

void BOX2_SEQ_CreateCursorObjects(BoxTask *p);

void BOX2_SEQ_SetWindow9(BoxTask *p, int a, int b);

void BOX2_SEQ_SetCursorFrame(BoxTask *p, int b);

void BOX2_SEQ_SetCursorDraw(char **p, int flag);

void BOX2_SEQ_RefreshCursorSlot(BoxTask *p);

void BOX2_SEQ_MoveCursorActor(BoxTask *p, unsigned i);

void BOX2_SEQ_SetSlotDim(char **p, int v);

void BOX2_SEQ_SetSlotDimB(char **p, int i);

void BOX2_SEQ_MoveCursorToSlot(char *p, int i);

extern const char str_021F140C[];

extern const char ov067_id[];

extern const Box2SeqPair d_021EFA4C[];

extern Dispatch d_021EFA2C;

extern const unsigned char d_021EF9B4[];

extern const unsigned char d_021EF950[];

extern const unsigned char d_021EFA10[];

extern const unsigned char d_021EF918[];

extern const unsigned char d_021EF8EC[];

extern Ent d_021EF908[];

extern const unsigned char d_021EF9C8[];

extern const unsigned char d_021EF93C[];

extern const unsigned char d_021EF964[];

extern const unsigned char d_021EF978[];

extern const unsigned char d_021EF98C[];

extern const unsigned char d_021EF9A0[];

extern const unsigned char d_021EF9E0[];

extern const unsigned char d_021EF928[];

extern const unsigned char d_021EF9F8[];

extern const unsigned char data_021EFA10[];

extern const unsigned char data_021EF918[];

extern const char d_021F140C[];

extern const unsigned char d_021EF8FC[];

extern const unsigned char d_021EF8F4[];

extern const unsigned char d_021EFC20[];

extern const Template d_021EFD64;

extern const Box2SeqDesc d_021EFD04;

extern const BoxPos d_021EFD4C[];

extern const Off d_021EFCE0[];

extern const DescTable d_021EFD80;

extern const Box2SeqDesc d_021EFD34;

extern const Box2SeqDesc d_021EFE70;

extern const signed char d_021EFCD0[];

extern const signed char d_021EFCC8[];




int BOX2_SEQ_StateMenuSelect(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(task))->work) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 1);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 1);
        b->state++;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
        b->state++;
        break;
    case 2:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 7);
        b->state++;
    case 3:
        if (b->timer == 4) {
            b->timer = 0;
            b->state++;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(task))->work), 4, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), 4, (short)t[1], (short)(t[0] + 2), (short)0);
        b->timer++;
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x666);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 8);
        b->state++;
    case 5:
        if (b->timer == 4) {
            BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(task))->work));
            BOX2_SEQ_ShowHandSlots(((char *)((BoxTask *)(task))->work));
            b->timer = 0;
            b->state = 0;
            return 0;
        }
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(task))->work), 4, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), 4, (short)t[1], (short)(t[0] - 2), (short)0);
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(task))->work), 10, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), 10, (short)t[1], (short)(t[0] - 2), (short)0);
        b->timer++;
        break;
    }
    return 1;
}

int BOX2_SEQ_StateMenuSwap(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(task))->work) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 7);
        b->state = 1;
    case 1:
        if (b->timer == 4) {
            b->timer = 0;
            b->state = 2;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(task))->work), 10, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), 10, (short)t[1], (short)(t[0] + 2), (short)0);
        b->timer++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x667);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 2);
        b->state = 3;
        break;
    case 3:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) == 0) {
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 0);
            b->state = 4;
        }
        break;
    case 4:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_SEQ_StateMenuMain(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(task))->work) + 0x58);
    switch (b->state) {
    case 0:
        if (task->heldSlot != 0xFF && task->heldSlot != task->curBox) {
            int dir = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, task->heldSlot);
            task->curBox = task->heldSlot;
            BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
            BOX2_MAIN_SetBoxScroll((BoxTask *)task, (void *)BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), dir);
            if (dir == 0)
                b->state = 2;
            else
                b->state = 3;
            break;
        }
    case 1:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 7);
        BOX2_MAIN_StartHandMotionToTargetBoxSlot((BoxTask *)task, *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16E), 2);
        b->state = 4;
        break;
    case 2:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0)
            b->state = 1;
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0)
            b->state = 1;
        break;
    case 4:
        if (BOX2_MAIN_StepHandMotionToSlotB((unsigned char *)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 5;
        }
        break;
    case 5:
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 2);
        b->state = 6;
        break;
    case 6:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) == 0) {
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 0);
            b->state = 7;
        }
        break;
    case 7:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}

/*
 * Twin of src/matched/BOX2_MAIN_StateMachineDrag.c.
 */
int BOX2_SEQ_StateMachineMove(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(task))->work) + 0x58);
    int busy = BOX2_UI_UpdateListPacks((((BoxTask *)(task))->work->winMgr));
    int wait = BOX2_UI_UpdateBarMove((BoxTask *)task);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAnim((BoxTask *)task, (short)(((BoxTask *)(task))->work->counter));
        if ((((BoxTask *)(task))->work->counter) != 0) {
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
            BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 1);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 1);
            b->state = 1;
        } else {
            BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
            b->state = 11;
        }
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) == 1)
            break;
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
        BOX2_SEQ_ShowHandSlots(((char *)((BoxTask *)(task))->work));
        b->state = 2;
    case 2:
        if (BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 1)
            BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            if (wait == 1 || BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 1)
                flag = 1;
            else
                flag = 0;
            if (wait == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
                r = (unsigned short)BOX2_MAIN_HitBoxGrid(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA180), (short)(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA184)));
                if (r == 0xFF)
                    r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA180), *(int *)(((char *)((BoxTask *)(task))->work) + 0xA184), d_021EF79C);
            } else {
                r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA180), *(int *)(((char *)((BoxTask *)(task))->work) + 0xA184), d_021EF7B4);
            }
            first = r;
            if (r == 0xFF)
                r = task->cursorSlot;
            else if (BOX2_MAIN_CompareSlots((unsigned char *)task, task->cursorSlot, r) == 0)
                r = task->cursorSlot;
            if (flag == 1) {
                BOX2_MAIN_StartHandMotionToBoxSlot((sptr)task, first, r, 2);
                b->state = 7;
            } else {
                BOX2_MAIN_StartHandMotionToBoxSlot((sptr)task, first, r, 1);
                if (r == task->cursorSlot && (FILE_UTIL_IsMailItem((((BoxTask *)(task))->work->counter)) == 0 || first == task->cursorSlot))
                    BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 0 && BOX2_UI_GetPageButtonHit() == 0) {
            BOX2_UI_SlideBarIn((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
            CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 0x27);
            CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 0x28);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 1);
            task->barFlag = 1;
            *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = task->cursorSlot;
            *(int *)(((char *)((BoxTask *)(task))->work) + 0x68) = 0x42;
        }
        if (b->timer == 0) {
            int dir = BOX2_UI_GetCloseButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 0);
                b->state = 3;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 1);
                b->state = 4;
            }
        }
        BOX2_MAIN_MoveCursorTo((struct BoxWork *)(((char *)((BoxTask *)(task))->work)), x, y);
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo((struct BoxWork *)(((char *)((BoxTask *)(task))->work)), x, y);
        break;
    case 4:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo((struct BoxWork *)(((char *)((BoxTask *)(task))->work)), x, y);
        break;
    case 7:
    case 8:
        if (BOX2_MAIN_StepHandMotionToSlot((sptr)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            if (b->state == 7) {
                b->state = 9;
            } else if (b->state == 8) {
                if ((((BoxTask *)(task))->work->counter) != 0) {
                    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
                    BOX2_SEQ_ShowHandSlots(((char *)((BoxTask *)(task))->work));
                }
                BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
                b->state = 11;
            }
        }
        break;
    case 9:
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 2);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        b->state = 10;
        break;
    case 10:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 0);
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
            b->state = 11;
        }
        break;
    case 11:
        if (busy == 0 && wait == 0) {
            b->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_SEQ_StateExitBox(BoxTask *task)
{
    char *w = *(char * *)&task->work;
    char *b = w + 0x58;
    switch (((BoxSeq *)(b))->state) {
    case 0:
        if (!BOX2_SEQ_IsActorAnimActive((char *)w, 10)) {
            unsigned old = task->cursorSlot;
            task->cursorSlot = **(unsigned short * *)&((BoxSeq *)(b))->entry;
            BOX2_MAIN_StartHandMotionToBoxSlot((sptr)task, old, old, 1);
            ((BoxSeq *)(b))->state = 1;
        }
        break;
    case 1:
        if (!BOX2_MAIN_StepHandMotionToSlot((sptr)task)) {
            ((BoxSeq *)(b))->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_SEQ_OpenBoxUp(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&task->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(task->work->cursorMove);
        if (r >= 0x22 && r <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, r - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)task, (short)-b->timer);
    return 1;
}

int BOX2_SEQ_OpenBoxDown(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&task->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(task->work->cursorMove);
        if (r >= 0x22 && r <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, r - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)task, (short)b->timer);
    return 1;
}

int BOX2_SEQ_OpenBoxLeft(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&task->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(task->work->cursorMove);
        if (r >= 1 && r <= 4)
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, r - 1, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)task, (short)-b->timer);
    return 1;
}

int BOX2_SEQ_OpenBoxRight(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&task->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(task->work->cursorMove);
        if (r >= 1 && r <= 4)
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, r - 1, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)task, (short)b->timer);
    return 1;
}

/*
 * Sibling of src/matched/BOX2_MAIN_StateMachineScroll.c.
 */
int BOX2_SEQ_StateMachineScroll(BoxTask *task)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(task))->work) + 0x58);
    int busy;
    unsigned r;
    unsigned x;
    unsigned y;
    if (BGWINFRM_IsMoving((((BoxTask *)(task))->work->winMgr), 8) == 1)
        busy = BOX2_MAIN_IsWindowBusy((unsigned char *)task);
    else
        busy = 0;
    r = BOX2_UI_UpdateListPacks((((BoxTask *)(task))->work->winMgr));
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 1)
                r = BOX2_MAIN_HitPartySlots(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA180), *(int *)(((char *)((BoxTask *)(task))->work) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = BOX2_MAIN_HitBoxGrid(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA180), (short)(*(int *)(((char *)((BoxTask *)(task))->work) + 0xA184)));
            if (task->params->mode == 4 && task->params->linkMode == 1) {
                r = 0xFF;
                *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA173) = 5;
            }
            if (BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, r) == 0)
                r = 0xFF;
            if (BOX2_UI_IsListClosed((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_SetSlotDim((char **)task, 0);
            if (r != 0xFF)
                task->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)task, 0x24);
            if (BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 0 && busy == 0)
                BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
            if (r == 0xFF && task->curBox != task->heldSlot) {
                r = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, task->heldSlot);
                task->curBox = task->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)task, (void *)BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), r);
                if (r == 0)
                    b->state = 4;
                else
                    b->state = 5;
            } else {
                b->state = 2;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 0 && task->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
            task->phase = 2;
            BOX2_UI_PutBottomBarClosed((((BoxTask *)(task))->work->winMgr));
            BOX2_UI_CloseBar((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_HidePartialSlots((char **)task, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 2);
            *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = task->cursorSlot;
            *(int *)(((char *)((BoxTask *)(task))->work) + 0x68) = 0x17;
        }
        if (b->timer == 0) {
            int dir = BOX2_UI_GetCloseButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 0);
                b->state = 6;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 1);
                b->state = 7;
            }
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 4:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0)
            b->state = 2;
        break;
    case 5:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0)
            b->state = 2;
        break;
    case 2:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 7:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry((BoxTask *)task, b->entry);
        if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(task))->work->winMgr)) == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 0) {
            BOX2_SEQ_MoveCursorToSlot(((char *)((BoxTask *)(task))->work), task->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)task, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            CURSOR_MOVE_SetCurrent(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), task->cursorSlot);
            BOX2_UI_SetCursorPos((char **)task, task->cursorSlot);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}

extern int (*const d_021EFA7C[])(char *);

int BOX2_SEQ_UpdatePrintQueue(BoxTask *task, int *state)
{
    if (!*(char * *)&task->work || !task->work->printQue || PRINTSYS_QUE_IsFinished(task->work->printQue))
        *state = d_021EFA7C[*state]((char *)task);
    if (*state == 0x69)
        return 0;
    if (*(char * *)&task->work) {
        BOX2_SEQ_UpdateTextWins((unsigned char *)(*(char * *)&task->work));
        BOX2_SEQ_DrawActors(*(char * *)&task->work);
    }
    return 1;
}

/*
 *   src/matched/arm9/unit_0204361C.c contains its body but omits it from
 *   the function list. Its header should list BG_SYS_ResetSubDisplay,BG_SYS_SetLcdSwap,
 *   BMP_GetVisiblePlane and its shard must be regenerated by the owner.
 *   Verified standalone EXACT, dsi/1.1p1 -O4,p ARM c99, 28 bytes:
 *   typedef unsigned short u16;
 *   typedef unsigned int u32;
 *   void BG_SYS_SetLcdSwap(u32 swap) {
 *       *(volatile u16 *)0x04000304 =
 *           (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 *   scratchpad/overlay-goal-20261002-w62/B4/blocker-1.log is the verdict.
 *   tu --suggest-split remains MATCH; no viable partition.
 * volatile: hardware halfword writes at 021E1E9C and 021E1EA0.
 * prototype: DC9E0 takes the explicitly loaded p despite its unused input.
 */
int BOX2_SEQ_CreateBox2Main(u8 *task)
{
    GF_OVERLAY_Load((sptr)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    BG_SYS_SetLcdSwap(0);
    GFL_HEAP_CreateChildHeap(1,0x4C,0x80000);
    ((BoxTask *)(task))->work=GFL_HEAP_Alloc(0x4C,0xA19C,1,str_021F140C,0x2B5);
    *(void **)(((char *)((BoxTask *)(task))->work)+0x1B0)=ARC_TOOL_CreateHandle(7,0x4C);
    KEY_GetRepeatSpeed((u32 *)(((char *)((BoxTask *)(task))->work)+0x4C),(u32 *)(((char *)((BoxTask *)(task))->work)+0x50));
    KEY_SetRepeatSpeed(6,6);
    BOX2_MAIN_ResetGraphics();
    BOX2_MAIN_InitBgSys((u8 *)task);
    BOX2_MAIN_CreatePalAnm((BoxTask *)task);
    BOX2_MAIN_LoadBgData((struct Ov170Ctx *)task);
    BOX2_MAIN_CreateTextSystem((char *)task);
    BOX2_MAIN_LoadFormTable((char *)task);
    BOX2_SEQ_InitBmpWins((BoxTask *)task);
    BOX2_SEQ_CreateBox2UiScene((BoxTask *)task);
    BOX2_SEQ_ShowAllSlotIcons((BoxTask *)task);
    BOX2_SEQ_ShowPartyIcons((BoxTask *)task);
    BOX2_MAIN_SetBoxScroll((BoxTask *)task,(void *)BOX2_MAIN_GetBoxWallpaper((BoxTask *)task,task[0x14]),2);
    BOX2_UI_InitWindowFrames((struct BoxTask *)task);
    BOX2_SEQ_PrintMsgWin((BoxTask *)task);
    BOX2_SEQ_InitBmpWin((BoxTask *)task);
    BOX2_UI_DrawAllSlots(task);
    BOX2_UI_CreateCursor((char **)task);
    BOX2_MAIN_CreateTaskMenu((char *)task);
    BOX2_MAIN_SetDisplayControl(1);
    GFL_NET_RefreshWmIconAtTopRight(1,0x4C);
    BOX2_MAIN_CreateVBlankTask((BoxTask *)task);
    return *(int *)(task+0x28);
}

int BOX2_SEQ_DeleteBox2Main(BoxTask *task)
{
    BOX2_MAIN_DeleteVBlankTask((BoxTask *)task);
    BOX2_MAIN_DeleteTaskMenu((BoxTask *)task);
    BOX2_UI_DeleteCursorMove((int *)task);
    BOX2_UI_DeleteWindowFrames((struct BoxWork *)task->work);
    BOX2_SEQ_DeleteBox2UiScene((char *)task->work);
    BOX2_SEQ_DeleteBmpWins((char *)task);
    BOX2_MAIN_DeleteFormTable((BoxTask *)task);
    BOX2_MAIN_DeleteTextSystem((char *)task);
    BOX2_MAIN_DeletePalAnm((int *)task);
    BOX2_MAIN_DeleteBgSys((void *)task);
    KEY_SetRepeatSpeed(*(u32 *)(*(u32 *)&task->work + 0x4c), *(u32 *)(*(u32 *)&task->work + 0x50));
    ARC_TOOL_DeleteHandle((void *)*(u32 *)(*(u32 *)&task->work + 0x1b0));
    GFL_HEAP_Free((void *)task->work);
    GFL_HEAP_DeleteChecked(0x4c);
    *(u32 *)&task->work = 0;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return *(u32 *)&task->state;
}

/*
 * Query the current mode; when it is 1 return the 0xA188 word of
 *   the p+0x2c object, else 2.
 */
int BOX2_SEQ_StateWaitWipe(char *task)
{
    if (WIPE_SYS_EndCheck() == 1)
        return *(int *)((char *)((BoxTask *)task)->work + 0xA188);
    return 2;
}

int BOX2_SEQ_StateWaitFade(void *task)
{
    if (PALANM_GetFadeRequestBits((const struct PaletteFade *)(const char *)(*(int *)((char *)((BoxTask *)task)->work + 0x6c))) == 0)
        return ((BoxTask *)task)->state;
    return 3;
}

int BOX2_SEQ_StateWaitCount(void *task)
{
    struct BoxCountWork *w = (struct BoxCountWork *)(char *)((BoxTask *)task)->work;
    int v = w->count;
    if (v == 0)
        return ((BoxTask *)task)->state;
    w->count = v - 1;
    return 4;
}















int BOX2_SEQ_StateRunStep(char *task)
{
    int (*f)(char *) = *(int (**)(char *))((char *)((BoxTask *)task)->work + 0x58);
    if (f != 0 && f(task) == 0) {
        *(int *)((char *)((BoxTask *)task)->work + 0x58) = 0;
        return *(int *)((char *)((BoxTask *)task)->work + 0x68);
    }
    return 5;
}

int BOX2_SEQ_StateWaitInput(BoxTask *task)
{
    if (TOUCHPANEL_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        UI_SetInputMode(1);
        return task->state;
    }
    if (KEY_GetTrg() & 3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        UI_SetInputMode(0);
        return task->state;
    }
    return 6;
}

int BOX2_SEQ_StateTaskMenu(char *task)
{
    APP_TASKMENU_UpdateMenu(*(void **)(((char *)((BoxTask *)(task))->work) + 0x1A0));
    if (APP_TASKMENU_IsFinish(*(void **)(((char *)((BoxTask *)(task))->work) + 0x1A0)) == 1) {
        int r = APP_TASKMENU_GetCursorPos(*(void **)(((char *)((BoxTask *)(task))->work) + 0x1A0));
        APP_TASKMENU_CloseMenu(*(void **)(((char *)((BoxTask *)(task))->work) + 0x1A0));
        KEY_SetRepeatSpeed(6, 6);
        if (r == 0)
            return d_021EFA4C[*(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0x1A4)].a(task);
        else
            return d_021EFA4C[*(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0x1A4)].b(task);
    }
    return 7;
}

int BOX2_SEQ_StateCheckTaskMenu(int task)
{
    if (BOX2_MAIN_StepWindowFrameFade((BoxTask *)task) == 0)
        return ((BoxTask *)task)->state;
    return 8;
}

extern struct Ent { void (*fn)(void *); int a; int b; } g_021EFA28[];

/*
 * Dispatch through the 12-byte table at 0x021EFA28 keyed by p[0x12].
 *   CLOSES the operand-order residue: the image's `ldr r1,[r1,r3]` (base first)
 *   comes out of a pointer VARIABLE holding the element address; writing the
 *   subscript as a direct member access makes mwccarm encode `[r3,r1]`.
 */
int BOX2_SEQ_StateDispatchFont(unsigned char *task)
{
    struct Ent *e = &g_021EFA28[task[0x12]];
    e->fn(task);
    return 10;
}

int BOX2_SEQ_StateDispatchStep(u8 *task){if(((BoxTask *)task)->subState!=1){(*(void (**)(u8 *))((uptr)&d_021EFA2C.callback+task[0x12]*12))(task);((BoxTask *)task)->state=*(u32 *)((uptr)&d_021EFA2C.value+task[0x12]*12);return 0;}return 10;}











int BOX2_SEQ_DeleteBox2Ui(BoxTask *task)
{
    GFL_USE_PlaySeDefaultVolume(0x55C);
    switch(task->params->mode) {
    case 0:
        BOX2_SEQ_RestartLeftBar((sptr)task);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
        BOX2_SEQ_SetSlotActors((char *)task,1,1);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,30);
        (((BoxTask *)(task))->work->nextState)=0x31;
        break;
    case 1:
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,0);
        (((BoxTask *)(task))->work->nextState)=0x2C;
        break;
    case 2:
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,0);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        (((BoxTask *)(task))->work->nextState)=0x11;
        break;
    case 3:
        BOX2_SEQ_SetSlotActors((char *)task,0x81,1);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,0);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        (((BoxTask *)(task))->work->nextState)=0x39;
        break;
    case 4:
        if(POKEPARTY_GetCount(task->params->party)==0) {
            BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,0);
            BOX2_UI_MoveCursor((char **)task,13,0);
            (((BoxTask *)(task))->work->nextState)=0x23;
        } else {
            BOX2_SEQ_RestartLeftBar((sptr)task);
            BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
            BOX2_SEQ_SetSlotActors((char *)task,1,1);
            BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,30);
            BOX2_UI_MoveCursor((char **)task,14,0);
            (((BoxTask *)(task))->work->nextState)=0x27;
        }
        break;
    case 5:
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,0);
        BOX2_SEQ_SetSlotActors((char *)task,0x81,1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task,0,1,1);
        (((BoxTask *)(task))->work->nextState)=0x4B;
        break;
    }
    return BOX2_SEQ_StateWaitPrint((sptr)task);
}

/*
 * candidate BOX2_SEQ_StateWaitPrint: guard then dispatch
 */
int BOX2_SEQ_StateWaitPrint(int task)
{
    if (PRINTSYS_QUE_IsFinished((const struct PrintQueue *)(*(int *)(*(int *)&((BoxTask *)task)->work + 0x8c))) == 0)
        return 0xc;
    return BOX2_SEQ_StartWipeWhite((void *)task, *(int *)(*(int *)&((BoxTask *)task)->work + 0xA198));
}

int BOX2_SEQ_StateSetMenu(unsigned char *task)
{
    GFL_HEAP_Free(((BoxTask *)task)->work->seq.entry);
    if ((*(unsigned char **)(task + 0x2C))[0xA172] == 1) {
        if (((BoxTask *)task)->params->mode == 3) {
            if (((BoxTask *)task)->work->counter == 0)
                BOX2_SEQ_PrintPromptB((BoxTask *)task, 0, 0x18);
            else
                BOX2_SEQ_PrintPromptB((BoxTask *)task, 1, 0x18);
        } else {
            BOX2_SEQ_PrintPrompt((BoxTask *)task, task[0x16], 1, 0x18);
        }
        (*(char **)(task + 0x2C))[0xA172] = 0;
    }
    return ((BoxTask *)task)->state;
}

/*
 * Two-step machine on the work word at 0xA194: step 0 opens the menu for
 * the current mode and fades, step 1 picks the next state from the mode.
 */
int BOX2_SEQ_StateItemMenu(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        switch ((((BoxTask *)(task))->params->mode)) {
        case 1:
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9B4, 5);
            break;
        case 0:
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF950, 5);
            break;
        case 2:
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
            break;
        case 3:
            BOX2_SEQ_SetActorAnim((BoxTask *)task, (*(short *)&((BoxTask *)(task))->work->counter));
            break;
        case 4:
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF918, 4);
            break;
        case 5:
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x1B);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF8EC, 2);
            break;
        }
        if (*(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA170) == 1) {
            *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA170) = 0;
            if ((((BoxTask *)(task))->params->mode) == 3) {
                if (task->cursorSlot >= 0x1E) {
                    BOX2_SEQ_SetSlotActors((char *)task, 0x82, 0);
                } else {
                    BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
                    BOX2_SEQ_SetSlotActors((char *)task, 0x81, 0);
                }
            } else {
                if (task->cursorSlot >= 0x1E) {
                    BOX2_SEQ_SetSlotActors((char *)task, 2, 0);
                } else {
                    BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
                    BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
                }
            }
        }
        BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0xE);
    case 1:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
        switch ((((BoxTask *)(task))->params->mode)) {
        case 1:
            BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
            return 0x2C;
        case 0:
            BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
            return 0x31;
        case 2:
            BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
            if (task->cursorSlot < 0x1E)
                return 0x11;
            return 0x1B;
        case 3:
            if (*(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C) == 0)
                BOX2_SEQ_PrintPromptB((BoxTask *)task, 0, 0x18);
            else
                BOX2_SEQ_PrintPromptB((BoxTask *)task, 1, 0x18);
            if (task->cursorSlot < 0x1E)
                return 0x39;
            return 0x46;
        case 4:
            BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
            if (task->cursorSlot < 0x1E)
                return 0x23;
            return 0x27;
        case 5:
            BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
            return 0x4B;
        }
        break;
    }
    return 0xE;
}

/*
 * Touch-drag paging of the box list: a drag of three or more pixels
 * starts a scroll of |d| / 8 steps in its direction; each later call
 * spends one step until the count runs out.
 */
int BOX2_SEQ_SetBox2Main(unsigned char *task)
{
    unsigned x, y;
    Scroll *s;
    unsigned old;
    int d;

    if (BOX2_UI_GetBackButtonPoint(&x, &y) == 0) {
        GFL_HEAP_Free((((BoxTask *)(task))->work->scroll));
        return (((BoxTask *)(task))->state);
    }
    s = (((BoxTask *)(task))->work->scroll);
    old = (((BoxTask *)(task))->work->cursorY);
    (((BoxTask *)(task))->work->cursorY) = y;
    d = old - y;
    if (ABS(d) >= 3) {
        s->left = ABS(d) / 8;
        if (y < old) {
            s->dir = 1;
            BOX2_MAIN_SelectBox((BoxTask *)task, 1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(task))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxUp, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxLeft, 0xF);
        }
        if (y > old) {
            s->dir = -1;
            BOX2_MAIN_SelectBox((BoxTask *)task, -1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(task))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxDown, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxRight, 0xF);
        }
    }
    if (s->left != 0) {
        s->left--;
        if (s->dir == 1) {
            BOX2_MAIN_SelectBox((BoxTask *)task, 1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(task))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxUp, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxLeft, 0xF);
        }
        if (s->dir == -1) {
            BOX2_MAIN_SelectBox((BoxTask *)task, -1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(task))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxDown, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxRight, 0xF);
        }
    }
    return 0xF;
}



















/*
 * State handler (table entry at 0x021EFABC) that forwards to
 * BOX2_SEQ_StateExitBoxWithSe.
 */
int BOX2_SEQ_StateCloseBox(unsigned char *task)
{
    return BOX2_SEQ_StateExitBoxWithSe((BoxTask *)task);
}

int BOX2_SEQ_StateBoxMenu(BoxTask *task)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        task->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)task, 0x14);
    }
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            return BOX2_SEQ_SelectSlotA((BoxTask *)task, r);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)task->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x11);
        }
        return 0x11;
    }
    r = BOX2_UI_UpdateCursorInputC((BoxTask *)task);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 1, 0x11);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 1, 0x11);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1A));
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->barOpenFlag = 0;
        task->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x14));
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 0;
        task->heldSlot = task->curBox;
        task->pickedSlot = 0x25;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 1, 0x4F);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 0;
        task->pickedSlot = 0x26;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x55));
    case 0x28:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x59));
    case 0x29: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x13);
    }
    case 0x2A:
        task->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)task, 0x14);
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 1, 0x11);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 1, 0x11);
        }
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 0x1E)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27 && v != 0x28 && v != 0x29)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x11));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x13);
        }
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 0x24, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
            return BOX2_SEQ_GotoSlotHandlerA((BoxTask *)task, r, 0x11);
        }
        break;
    }
    return 0x11;
}

int BOX2_SEQ_StateOpenSummary(BoxTask *task)
{
    BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
    BOX2_SEQ_Delete(task);
    CURSOR_MOVE_SetCurrent(task->work->cursorMove, 0x24);
    BOX2_UI_SetCursorPos((char **)task, 0x24);
    BOX2_SEQ_SetCursorDraw((char **)task, 1);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
    BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
    return 0x11;
}

/*
 * Re-key the p+0x2c+0x74 object, clear the frame, retag 0x18,
 *   forward the status bytes, refresh, then store state 0x11 with the
 *   0x021E070D thumb pointer as the selector.  Six-member wrapper family
 *   (see BOX2_SEQ_SetBox2UiB / BOX2_SEQ_SetBox2UiC / BOX2_SEQ_SetBox2UiD / BOX2_SEQ_SetBox2UiE /
 *   BOX2_SEQ_SetBox2UiF): only the mid call, the selector and the state differ.
 */
void BOX2_SEQ_SetBox2Ui(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowA((struct BoxWork *)(char *)(*(int *)&task->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)task, 0x11));
}

int BOX2_SEQ_StateSummary(u8 *task)
{
    switch(*(int *)(((char *)((BoxTask *)(task))->work)+0xA194)) {
    case 0:
        task[0x19]=task[0x14];
        if((((BoxTask *)(task))->listState)==1) {
            task[0x17]=255;
            task[0x16]=CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(task))->work)+0x70));
            if(task[0x16]>=30) {
                task[0x16]=0;
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task[0x16]);
            }
        } else {
            task[0x17]=task[0x14];
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work),24);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work),task[0x16]);
        }
        BOX2_SEQ_SetCursorDraw((char **)task,0);
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74));
        (*(int *)(((char *)((BoxTask *)(task))->work)+0xA194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_IsWindowMoving,20);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(task))->work)+0xA194))++;
        return BOX2_SEQ_RefreshBoxUiAndWait((char *)task,20);
    case 2:
        BOX2_UI_MoveCursor((char **)task,4,task[0x16]);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task,6);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task,0,1,0);
        *(int *)(((char *)((BoxTask *)(task))->work)+0xA168)=task[0x16];
        *(int *)(((char *)((BoxTask *)(task))->work)+0xA194)=0;
        if((((BoxTask *)(task))->listState)==1) {
            if(!BOX2_MAIN_GetPartyValueAt((void ***)task,task[0x16],task[0x14],0xA9,0))
                BOX2_UI_DeleteSlotObjects((BoxTask *)task,0,1,2);
            BOX2_SEQ_SetWindow9((BoxTask *)task,13,1);
            return 21;
        }
        if((((BoxTask *)(task))->listState)==2) BOX2_SEQ_SetWindow9((BoxTask *)task,13,1);
        else BOX2_SEQ_SetWindow9((BoxTask *)task,14,1);
        return BOX2_SEQ_SelectBoxSlot((BoxTask *)task,task[0x16]);
    }
    return 20;
}

























int BOX2_SEQ_StateSummaryInput(BoxTask *task)
{
    unsigned r;
    unsigned x;
    unsigned y;
    if (task->exitFlag == 1) {
        task->listState = 0;
        task->exitFlag = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x16);
    }
    if ((KEY_GetTrg() & 4) && task->listState != 0 && task->handMode == 0) {
        BOX2_MAIN_ActivateKeyCursor((BoxTask *)task);
        task->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x16);
    }
    if (task->handMode == 0) {
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
                CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
                return BOX2_SEQ_SelectSlotD((BoxTask *)task, r, 0x15);
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
            BOX2_UI_SelectSlot((BoxTask *)task, r);
            *(int *)((char *)task->work + 0xA168) = r;
            BOX2_UI_SetCursorPos((char **)task, r);
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            return 0x15;
        }
    }
    if (BOX2_UI_GetExitButtonPoint(&x, &y) == 1) {
        *(unsigned *)((char *)task->work + 0xA184) = y;
        task->state = 0x15;
        BOX2_SEQ_CreateC((BoxTask *)task);
        return 0xF;
    }
    r = BOX2_UI_CursorInputLeft((BoxTask *)task);
    switch (r) {
    case 0x1E:
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        if (task->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        BOX2_UI_SelectSlot((BoxTask *)task, 0x1E);
        *(int *)((char *)task->work + 0xA168) = 0x1E;
        if (task->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x15);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        BOX2_UI_SelectSlot((BoxTask *)task, 0x1E);
        *(int *)((char *)task->work + 0xA168) = 0x1E;
        if (task->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x15);
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (task->handMode == 0)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x19));
    case 0x28:
        if (task->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v >= 0x1E || BOX2_MAIN_GetPartyValueAt((void ***)task, v, task->curBox, 0xA9, 0) == 0)
                break;
            task->cursorSlot = v;
            task->heldSlot = task->curBox;
            task->menuMode = 2;
        } else {
            task->menuMode = 3;
            task->listCursorId = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        }
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 8, 1, 0x4F);
    case 0x29:
        if (task->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x16));
    case 0x2A:
        if (task->listState == 0 || task->handMode != 0)
            break;
        task->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x16);
    case -2:
        if (task->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)task, 0xFF, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x16));
    case -8:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x22)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)task, -1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxDown, 0x15);
    case -7:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x25)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)task, 1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxUp, 0x15);
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x15);
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x15);
    case -3: {
        unsigned char v;
        GFL_USE_PlaySeDefaultVolume(0x548);
        v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (task->handMode == 0) {
            if (v < 0x1E)
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
            else
                BOX2_MAIN_ResetBoxView((BoxTask *)task);
        }
        if (v >= 0x22 && v <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, v - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x15));
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)task, -1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxDown, 0x15);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)task, 1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxUp, 0x15);
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, r - 0x22, 1);
        if (task->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)task, r + 2, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        *(unsigned char *)((char *)task->work + 0xA17F) = task->prevBox + r - 0x22;
        if (*(unsigned char *)((char *)task->work + 0xA17F) >= task->boxLimit)
            *(unsigned char *)((char *)task->work + 0xA17F) -= task->boxLimit;
        if (*(unsigned char *)((char *)task->work + 0xA17F) != task->curBox)
            return BOX2_SEQ_DrawListSlot((BoxTask *)task, 0);
        break;
    case -1:
        break;
    default:
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        if (task->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)task, r, 0x15);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            task->cursorSlot = r;
            task->heldSlot = task->curBox;
            BOX2_SEQ_SwapSlotActors((char *)task->work, task->cursorSlot);
            return BOX2_SEQ_SelectBoxSlot((BoxTask *)task, task->cursorSlot);
        }
        break;
    }
    return 0x15;
}









int BOX2_SEQ_StateSummaryClose(u8 *task)
{
    unsigned n;
    switch(*(int *)(((char *)((BoxTask *)(task))->work)+0xA194)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)task,0);
        BOX2_UI_SetMiniIconVisible((BoxTask *)task,0,0);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task,0,0,1);
        if(CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(task))->work)+0x70))>=30) BOX2_MAIN_ResetBoxView((BoxTask *)task);
        (*(int *)(((char *)((BoxTask *)(task))->work)+0xA194))++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_ResetEntryB((BoxTask *)task,22);
    case 1:
        if(task[0x1B]==1) {
            BOX2_UI_PutBottomBarClosed(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74));
            BOX2_UI_CloseBar(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74));
            (*(int *)(((char *)((BoxTask *)(task))->work)+0xA194))++;
            return BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_IsWindowBusy,22);
        }
        n=CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(task))->work)+0x70));
        if(n>=30) n=0;
        BOX2_UI_MoveCursor((char **)task,3,n);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task,6);
        BOX2_SEQ_SetWindow9((BoxTask *)task,14,1);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,n);
        *(int *)(((char *)((BoxTask *)(task))->work)+0xA194)=0;
        return 17;
    case 2:
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        *(int *)(((char *)((BoxTask *)(task))->work)+0xA194)=0;
        return 33;
    }
    return 22;
}










/*
 * Re-entry of the box menu: restores the cursor, redraws the box and picks
 * the message for the current mode.
 */
int BOX2_SEQ_StateSwapMenu(unsigned char *task)
{
    unsigned char sel;
    int arg;
    BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
    task[0x18] = 0;
    task[0x17] = 0xFF;
    if ((((BoxTask *)(task))->work->result) == 0) {
        sel = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
    } else {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task[0x16]);
        BOX2_UI_SetCursorPos((char **)task, task[0x16]);
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        sel = task[0x16];
    }
    *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = sel;
    BOX2_SEQ_Delete((BoxTask *)task);
    if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
        if ((((BoxTask *)(task))->state) == 0x20) {
            BOX2_UI_MoveCursor((char **)task, 4, sel);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, sel);
            (((BoxTask *)(task))->state) = 0x15;
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, sel, task[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x1E && BOX2_MAIN_GetPartyValueAt((void ***)task, sel, task[0x14], 0xA9, 0)) {
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, sel);
            arg = 0;
        } else {
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            arg = 2;
        }
    } else if (BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
        if ((((BoxTask *)(task))->state) == 0x15) {
            sel = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (sel > 0x20)
                sel = task[0x16];
            BOX2_UI_MoveCursor((char **)task, 6, sel);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, sel);
            (((BoxTask *)(task))->state) = 0x20;
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, sel, task[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)task, sel, task[0x14], 0xA9, 0)) {
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, sel);
            arg = 0;
        } else {
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            arg = 2;
        }
    } else if (sel < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)task, sel, task[0x14], 0xA9, 0)) {
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, sel);
        arg = 0;
    } else {
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        arg = 2;
    }
    if (((BoxTask *)task)->listState == 0) {
        ((BoxTask *)task)->exitFlag = 1;
        arg = task[0x21];
    }
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, arg);
    switch ((((BoxTask *)(task))->work->result)) {
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_PrintMenuRow((char *)task, 2, 0x18);
        return 0x18;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_PrintMenuRow((char *)task, 3, 0x18);
        return 0x18;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_PrintMenuRow((char *)task, 4, 0x18);
        return 0x18;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_PrintYesNo((char *)task, 0);
        return 0x18;
    }
    if (((BoxTask *)task)->params->mode == 2) {
        if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(task))->work->winMgr)) == 1)
            BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        else
            BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
    }
    return (((BoxTask *)(task))->state);
}










int BOX2_SEQ_StateSwapConfirm(BoxTask *task)
{
    int n;
    if (BOX2_SEQ_StateWaitInput(task) == 6)
        return 0x18;
    if (CURSOR_MOVE_GetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70)) == 1)
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 1);
    if ((unsigned char)((char *)((BoxTask *)(task))->work)[0xA173] == 5)
        n = 0x1B;
    else
        n = 0x18;
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), n);
    BOX2_MAIN_RefreshCursorBox(task);
    if (task->params->mode == 2) {
        if (BOX2_UI_IsInfoBarOpen(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74)) == 1)
            BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        else
            BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
    }
    ((char *)((BoxTask *)(task))->work)[0xA173] = 0;
    return task->state;
}










int BOX2_SEQ_StateSwapApply(u8 *task)
{
    switch(*(int *)(((char *)((BoxTask *)(task))->work)+0xA194)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work),4,0);
        BOX2_UI_SetMiniIconVisible((BoxTask *)task,0,0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(task))->work)+0xA194))++;
        return BOX2_SEQ_ResetEntryB((BoxTask *)task,25);
    case 1:
        BOX2_UI_PutBottomBarClosed(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74));
        BOX2_UI_CloseBar(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74));
        if(task[0x18]==1) BOX2_SEQ_HidePartialSlots((char **)task,1);
        else BOX2_SEQ_HidePartialSlots((char **)task,0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(task))->work)+0xA194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_IsWindowBusy,25);
    case 2:
        BOX2_UI_MoveCursor((char **)task,6,30);
        BOX2_UI_SelectSlot((BoxTask *)task,30);
        if(task[0x18]==0) BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,30);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        *(int *)(((char *)((BoxTask *)(task))->work)+0xA168)=30;
        *(int *)(((char *)((BoxTask *)(task))->work)+0xA194)=0;
        return 32;
    }
    return 25;
}






















int BOX2_SEQ_StateSwapFinish(BoxTask *task)
{
    switch (*(int *)(((char *)((BoxTask *)(task))->work) + 0xA194)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_UI_PutBottomBarOpen(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        BOX2_UI_CloseBar(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        BOX2_SEQ_HidePartialSlots((char **)task, 0);
        if (task->params->mode == 3)
            BOX2_SEQ_SetSlotActors((char *)task, 0x82, 1);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(task))->work) + 0xA194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x1A);
    case 1:
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA194) = 0;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, 0x1E);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        if (task->params->mode == 3) {
            BOX2_UI_MoveCursor((char **)task, 8, 0);
            return 0x46;
        } else {
            BOX2_UI_MoveCursor((char **)task, 5, 0);
            return 0x1B;
        }
    }
    return 0x1A;
}















/*
 * Sibling of src/matched/BOX2_SEQ_StateBoxMenu.c.  The image computes r + 0x1E
 * separately for BOX2_MAIN_RefreshCurrentBoxMonInfo and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int BOX2_SEQ_StateMoveMove(BoxTask *task)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        task->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)task, 0x1F);
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotA((unsigned char *)task, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            BOX2_UI_ShowWindowB((struct BoxWork *)(char *)task->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x1B);
        }
        return 0x1B;
    }
    r = BOX2_UI_UpdateCursorInputD((BoxTask *)task);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1C));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1C));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->barOpenFlag = 1;
        task->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->heldSlot = task->curBox;
        task->menuMode = 1;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 1, 0x4F);
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 1;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
    case 12:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x55));
    case 13:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x59));
    case 14: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x1D);
    }
    case 15:
        task->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)task, 0x1F);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 6)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x1B));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x1D);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 9, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 9);
            return BOX2_SEQ_GotoSlotHandlerB((BoxTask *)task, r + 0x1E, 0x1B);
        }
        break;
    }
    return 0x1B;
}
















int BOX2_SEQ_StateMoveFinish(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_UI_OpenBar((((BoxTask *)(task))->work->winMgr));
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x1c);
    case 1:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        if (task->params->mode == 3) {
            BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
            BOX2_UI_MoveCursor((char **)task, 7, 0x21);
            return 0x39;
        } else {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_MoveCursor((char **)task, 3, 0x21);
            return 0x11;
        }
    }
    return 0x1c;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowB and state 0x1b.
 */
void BOX2_SEQ_SetBox2UiB(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowB((struct BoxWork *)(char *)(*(int *)&task->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)task, 0x1B));
}

int BOX2_SEQ_StateOpenSummaryB(BoxTask *task)
{
    GFL_USE_PlaySeDefaultVolume(0x667);
    BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
    BOX2_SEQ_Delete(task);
    CURSOR_MOVE_SetCurrent(task->work->cursorMove, 9);
    BOX2_UI_SetCursorPos((char **)task, 9);
    BOX2_SEQ_SetCursorDraw((char **)task, 1);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
    BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
    return 0x1b;
}

























/*
 * Three-step state machine on the work word at 0xA194: restore the cursor,
 * close the prompt, then redraw the box.  The dispatch and the step-1
 * increment read the work pointer through a local loaded once at the top; with
 * the macro on both, the 0xA194 offset is CSEd into the increment and takes r4.
 */
int BOX2_SEQ_StateSummaryB(BoxTask *task)
{
    char *w = ((char *)((BoxTask *)(task))->work);
    switch (((BoxWork *)w)->seqStep) {
    case 0:
        if ((((BoxTask *)(task)))->listState == 1) {
            task->heldSlot = 0xFF;
            task->cursorSlot = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (BOX2_UI_IsTopBarClosed((((BoxTask *)(task))->work->winMgr)) == 1) {
                if (task->cursorSlot >= 6)
                    task->cursorSlot = 0x1E;
                else
                    task->cursorSlot += 0x1E;
            } else if (task->cursorSlot >= 0x1E) {
                task->cursorSlot = 0;
            }
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
        } else {
            if (BOX2_UI_IsTopBarClosed((((BoxTask *)(task))->work->winMgr)) == 1)
                task->heldSlot = 0xFF;
            else
                task->heldSlot = task->curBox;
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
            BOX2_MAIN_RefreshCursorBox(task);
            BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
        }
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x1F);
    case 1:
        if (*(int *)(((char *)((BoxTask *)(task))->params) + 0x24) == 4 && *(int *)(((char *)((BoxTask *)(task))->params) + 0x14) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintYesNo((char *)task, 0);
            (((BoxTask *)(task)))->listState = 0;
            (((BoxTask *)(task))->work->seqStep) = 0;
            (((BoxTask *)(task))->state) = 0x2B;
            return 6;
        }
        (((BoxWork *)w)->seqStep)++;
        if (BOX2_UI_IsTopBarClosed((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_SlideBarIn((((BoxTask *)(task))->work->winMgr));
        } else {
            BOX2_UI_PutBottomBarClosed((((BoxTask *)(task))->work->winMgr));
            BOX2_UI_CloseBar((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_HidePartialSlots((char **)task, 0);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x1F);
    case 2:
        BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 0);
        BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = task->cursorSlot;
        (((BoxTask *)(task))->work->seqStep) = 0;
        if ((((BoxTask *)(task)))->listState == 1) {
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 0xA9, 0) == 0)
                BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 2);
            if (*(int *)(((char *)((BoxTask *)(task))->params) + 0x24) == 4) {
                BOX2_UI_HideWindowA((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
                BOX2_UI_HideWindowB((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
                CURSOR_MOVE_ClearSkipBit((((BoxTask *)(task))->work->cursorMove), 0x27);
            }
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xD, 1);
            return 0x20;
        }
        if ((((BoxTask *)(task)))->listState == 2)
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xD, 1);
        else
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
        BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
        return BOX2_SEQ_HideSlotWindow((BoxTask *)task, task->cursorSlot);
    }
    return 0x1F;
}

















int BOX2_SEQ_StateMoveInput(BoxTask *task)
{
    unsigned r;
    if (task->exitFlag == 1) {
        task->listState = 0;
        task->exitFlag = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x21);
    }
    if ((KEY_GetTrg() & 4) && task->listState != 0 && task->handMode == 0) {
        BOX2_MAIN_ActivateKeyCursor((BoxTask *)task);
        task->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x21);
    }
    if (task->handMode == 0) {
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
                return BOX2_SEQ_SelectSlotD((BoxTask *)task, r, 0x20);
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
            BOX2_UI_SelectSlot((BoxTask *)task, r);
            *(int *)((char *)task->work + 0xA168) = r;
            BOX2_UI_SetCursorPos((char **)task, r);
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            return 0x20;
        }
        r = BOX2_UI_GetBodySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
                return BOX2_SEQ_SelectSlotD((BoxTask *)task, r + 0x1E, 0x20);
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r + 0x1E);
            BOX2_UI_SelectSlot((BoxTask *)task, r + 0x1E);
            *(int *)((char *)task->work + 0xA168) = r + 0x1E;
            BOX2_UI_SetCursorPos((char **)task, r + 0x1E);
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            return 0x20;
        }
    }
    r = BOX2_UI_CursorInputRight((BoxTask *)task);
    switch (r) {
    case 0x24:
        if (task->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
        BOX2_UI_SetCursorPos((char **)task, 0x24);
        BOX2_UI_SelectSlot((BoxTask *)task, 0x24);
        *(int *)((char *)task->work + 0xA168) = 0x24;
        if (task->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x20);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
        BOX2_UI_SetCursorPos((char **)task, 0x24);
        BOX2_UI_SelectSlot((BoxTask *)task, 0x24);
        *(int *)((char *)task->work + 0xA168) = 0x24;
        if (task->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x20);
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (task->handMode == 0)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0xB, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x22));
    case 0x28:
        if (task->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v >= 0x24 || BOX2_MAIN_GetPartyValueAt((void ***)task, v, task->curBox, 0xA9, 0) == 0)
                break;
            task->cursorSlot = v;
            task->heldSlot = task->curBox;
            task->menuMode = 4;
        } else {
            task->menuMode = 5;
            task->listCursorId = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        }
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 8, 1, 0x4F);
    case 0x29:
        if (task->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x21));
    case 0x2A:
        if (task->listState == 0 || task->handMode != 0)
            break;
        task->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x21);
    case -2:
        if (task->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)task, 0xFF, 0x20);
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x21));
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x20);
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x20);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (task->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v < 0x24)
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
            else
                BOX2_MAIN_ResetBoxView((BoxTask *)task);
        }
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x20));
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (task->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)task, r, 0x20);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            task->cursorSlot = r;
            task->heldSlot = task->curBox;
            BOX2_SEQ_SwapSlotActors((char *)task->work, task->cursorSlot);
            return BOX2_SEQ_HideSlotWindow((BoxTask *)task, task->cursorSlot);
        }
        break;
    }
    return 0x20;
}

int BOX2_SEQ_StateMoveClose(BoxTask *task)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(((u8 *)((BoxTask *)(task))->work) + 0xa194)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable((char *)((u8 *)((BoxTask *)(task))->work), 4, 0);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
        if (task->barOpenFlag == 0) {
            BOX2_UI_OpenBar(*(struct BgWinFrmWork **)(((u8 *)((BoxTask *)(task))->work) + 116));
            *(u32 *)(((u8 *)((BoxTask *)(task))->work) + 0xa194) = 2;
        } else {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
            BOX2_UI_ToggleSlotPair((struct BoxWork *)(char *)((u8 *)((BoxTask *)(task))->work), 0);
            BOX2_UI_SlideBarOut(*(struct BgWinFrmWork **)(((u8 *)((BoxTask *)(task))->work) + 116));
            *(u32 *)(((u8 *)((BoxTask *)(task))->work) + 0xa194) = 1;
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 33);
    case 1:
        *(u32 *)(((u8 *)((BoxTask *)(task))->work) + 0xa194) = 0;
        index = CURSOR_MOVE_GetCurrent(*(void **)(((u8 *)((BoxTask *)(task))->work) + 112));
        if (index < 30 || index >= 36)
            selection = 0;
        else
            selection = index - 30;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, selection + 30);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 1);
        if (task->params->mode == 2) {
            BOX2_UI_MoveCursor((char **)task, 5, selection);
            return 27;
        }
        BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((u8 *)((BoxTask *)(task))->work));
        BOX2_UI_MoveCursor((char **)task, 14, selection);
        return 39;
    case 2:
        *(u32 *)(((u8 *)((BoxTask *)(task))->work) + 0xa194) = 0;
        index = CURSOR_MOVE_GetCurrent(*(void **)(((u8 *)((BoxTask *)(task))->work) + 112));
        if (index >= 30)
            index = 0;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, index);
        BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((u8 *)((BoxTask *)(task))->work));
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 1);
        if (task->params->mode == 4) {
            BOX2_UI_MoveCursor((char **)task, 13, index);
            return 35;
        }
        BOX2_UI_MoveCursor((char **)task, 3, index);
        return 17;
    }
    return 33;
}















int BOX2_SEQ_StateMoveCloseB(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_UI_OpenBar((((BoxTask *)(task))->work->winMgr));
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x22);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x669);
        task->prevBox = task->curBox;
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_RefreshBoxUiAndWait((char *)task, 0x22);
    case 2:
        BOX2_UI_MoveCursor((char **)task, 4, 0x27);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xa168) = 0x27;
        (((BoxTask *)(task))->work->seqStep) = 0;
        return 0x15;
    }
    return 0x22;
}

























int BOX2_SEQ_StateItemMenuB(BoxTask *task)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        task->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)task, 0x1F);
    }
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF918, 4);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            task->barOpenFlag = 0;
            return BOX2_SEQ_SelectSlotB((BoxTask *)task, r);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)task->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x23);
        }
        return 0x23;
    }
    r = BOX2_UI_UpdateCursorInputG((BoxTask *)task);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 1, 0x23);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 1, 0x23);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x26));
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->barOpenFlag = 0;
        task->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1F));
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 0;
        task->heldSlot = task->curBox;
        task->pickedSlot = 0x25;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, 0x4F);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 0;
        task->pickedSlot = 0x26;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
    case 0x27: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x25);
    }
    case 0x28:
        task->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)task, 0x1F);
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 1, 0x23);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 1, 0x23);
        }
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 0x1E)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x23));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x25);
        }
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF918, 4);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 0x24, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
            return BOX2_SEQ_GotoSlotHandlerA((BoxTask *)task, r, 0x23);
        }
        break;
    }
    return 0x23;
}

int BOX2_SEQ_StateOpenItemB(BoxTask *task)
{
    GFL_USE_PlaySeDefaultVolume(0x667);
    BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
    BOX2_SEQ_Delete(task);
    CURSOR_MOVE_SetCurrent(task->work->cursorMove, 0x24);
    BOX2_UI_SetCursorPos((char **)task, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
    BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
    return 0x23;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowA and state 0x23.
 */
void BOX2_SEQ_SetBox2UiC(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowA((struct BoxWork *)(char *)(*(int *)&task->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)task, 0x23));
}




















int BOX2_SEQ_StateSwapMenuB(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_UI_PutBottomBarOpen((((BoxTask *)(task))->work->winMgr));
        BOX2_UI_CloseBar((((BoxTask *)(task))->work->winMgr));
        BOX2_SEQ_HidePartialSlots((char **)task, 0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x26);
    case 1:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, 0x1e);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_UI_MoveCursor((char **)task, 0xe, 0);
        return 0x27;
    }
    return 0x26;
}























/*
 * Sibling of src/matched/BOX2_SEQ_StateBoxMenu.c and BOX2_SEQ_StateMoveMove.c.
 * The image computes r + 0x1E
 * separately for BOX2_MAIN_RefreshCurrentBoxMonInfo and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int BOX2_SEQ_StateItemMoveB(BoxTask *task)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        task->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)task, 0x1F);
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF918, 4);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotB((BoxTask *)task, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            BOX2_UI_ShowWindowB((struct BoxWork *)(char *)task->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x27);
        }
        return 0x27;
    }
    r = BOX2_UI_UpdateCursorInputH((BoxTask *)task);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x28));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x28));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->barOpenFlag = 1;
        task->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 1;
        task->heldSlot = task->curBox;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, 0x4F);
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->menuMode = 1;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
    case 12: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x29);
    }
    case 13:
        task->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)task, 0x1F);
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x29);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x28));
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 6)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x27));
    }
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF918, 4);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 9, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 9);
            return BOX2_SEQ_GotoSlotHandlerB((BoxTask *)task, r + 0x1E, 0x27);
        }
        break;
    }
    return 0x27;
}






















int BOX2_SEQ_StateMoveFinishB(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_UI_OpenBar((((BoxTask *)(task))->work->winMgr));
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x28);
    case 1:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_UI_MoveCursor((char **)task, 0xd, 0x21);
        return 0x23;
    }
    return 0x28;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowB and state 0x27.
 */
void BOX2_SEQ_SetBox2UiD(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowB((struct BoxWork *)(char *)(*(int *)&task->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)task, 0x27));
}

/*
 *   void CURSOR_MOVE_SetCurrent(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 */
int BOX2_SEQ_StateOpenItemC(u8 *task){BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);BOX2_SEQ_Delete((BoxTask *)task);CURSOR_MOVE_SetCurrent(*(void **)(*(char **)(task+0x2c)+0x70),9);BOX2_UI_SetCursorPos((char **)task,9);BOX2_UI_DeleteSlotObjects((BoxTask *)task,0,0,1);BOX2_SEQ_PrintPrompt((BoxTask *)task,task[0x16],1,24);return 39;}



















int BOX2_SEQ_StateMenuCursor(BoxTask *task)
{
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x1b);
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_MAIN_RefreshCursorBox(task);
    if (UI_GetInputMode() == 0)
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 1);
    if (BOX2_UI_IsTopBarClosed((((BoxTask *)(task))->work->winMgr)) == 1) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot - 0x1e);
        BOX2_UI_SetCursorPos((char **)task, task->cursorSlot - 0x1e);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        return 0x27;
    } else {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot);
        BOX2_UI_SetCursorPos((char **)task, task->cursorSlot);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        return 0x23;
    }
}





















int BOX2_SEQ_StateItemMenuC(BoxTask *task)
{
    unsigned r;
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9B4, 5);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            return BOX2_SEQ_SelectSlotC((BoxTask *)task, r);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x2C);
        }
        return 0x2C;
    }
    r = BOX2_UI_UpdateCursorInputB((BoxTask *)task);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x2C);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x2C);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 1, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x2E));
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->heldSlot = task->curBox;
        task->pickedSlot = 0x24;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, 0x4F);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x55));
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x59));
    case 0x27: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x2D);
    }
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x2C);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x2C);
        }
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 0x1E)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
        else if (v != 0x23 && v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x2C));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x2D);
        }
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9B4, 5);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 0x23, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x23);
            return BOX2_SEQ_GotoSlotHandlerA((BoxTask *)task, r, 0x2C);
        }
        break;
    }
    return 0x2C;
}

void BOX2_SEQ_SetBox2MainB(u8 *task){BOX2_UI_OpenListPack(*(struct BgWinFrmWork * *)&((BoxTask *)task)->work->winMgr);BOX2_SEQ_SetSlotDim((char **)task,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)task)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)task);BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_SceneWaitScroll,BOX2_SEQ_SetState((BoxTask *)task,44));}




















int BOX2_SEQ_StateCloseBoxB(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x2e);
    case 1:
        if (POKEPARTY_GetCount(((void **)task->params)[2]) != 6)
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x2f);
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintPrompt((BoxTask *)task, 0, 2, 0x18);
        task->state = 0xe;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
    }
    return 0x2e;
}

int BOX2_SEQ_StateOpenBoxC(u8 *task)
{
    switch (*(u32 *)(*(u8 **)(task + 44) + 0xa194)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_SEQ_HideSlotsC61C((BoxTask *)task);
        BOX2_UI_PutBottomBarClosed((struct BgWinFrmWork *)(*(int *)(*(u8 **)(task + 44) + 116)));
        BOX2_UI_CloseBar((struct BgWinFrmWork *)(*(int *)(*(u8 **)(task + 44) + 116)));
        task[26] = 2;
        (*(u32 *)(*(u8 **)(task + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 47);
    case 1:
        task[23] = task[20];
        BOX2_SEQ_SwapSlotActors(*(char **)(task + 44), task[22]);
        BOX2_SEQ_Create((void *)task);
        (*(u32 *)(*(u8 **)(task + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineClose, 47);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
        BOX2_SEQ_Delete((BoxTask *)task);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        BOX2_UI_OpenBar((struct BgWinFrmWork *)(*(int *)(*(u8 **)(task + 44) + 116)));
        (*(u32 *)(*(u8 **)(task + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 47);
    case 3:
        CURSOR_MOVE_SetCurrent(*(void **)(*(u8 **)(task + 44) + 112), task[22]);
        BOX2_UI_SetCursorPos((char **)task, task[22]);
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        task[22] = 255;
        *(u32 *)(*(u8 **)(task + 44) + 0xa194) = 0;
        return 44;
    }
    return 47;
}











int BOX2_SEQ_DeleteBox2UiB(BoxTask *task)
{
    unsigned r = *(unsigned *)(*(char **)(((char *)((BoxTask *)(task))->work) + 0x60) + 0xac);
    BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
    BOX2_SEQ_Delete(task);
    BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
    if (task->cursorSlot != 0xff) {
        BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
        r = 0x23;
    }
    CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
    BOX2_UI_SetCursorPos((char **)task, r);
    return 0x2c;
}





















int BOX2_SEQ_StateItemMenuD(BoxTask *task)
{
    unsigned r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF950, 5);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotC((BoxTask *)task, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r + 0x3C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x31);
        }
        return 0x31;
    }
    r = BOX2_UI_UpdateCursorInputA((BoxTask *)task);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 1, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x34));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->pickedSlot = 9;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, 0x4F);
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x55));
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x59));
    case 12: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x32);
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 6)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v + 0x1E);
        else if (v != 8 && v != 9 && v != 10 && v != 11 && v != 12)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x31));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x32);
        }
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF950, 5);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 8, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 8);
            return BOX2_SEQ_GotoSlotHandlerB((BoxTask *)task, r + 0x1E, 0x31);
        }
        break;
    }
    return 0x31;
}

void BOX2_SEQ_SetBox2MainC(u8 *task){BOX2_UI_OpenListPack(*(struct BgWinFrmWork * *)&((BoxTask *)task)->work->winMgr);BOX2_SEQ_SetSlotDim((char **)task,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)task)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)task);BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_SceneWaitScroll,BOX2_SEQ_SetState((BoxTask *)task,49));}

























/*
 * Refresh the tag-derived index, re-key, arm, retag 0x18, forward,
 *   and report 0x31.
 */
int BOX2_SEQ_StateCursorMove(BoxTask *task)
{
    CURSOR_MOVE_SetCurrent((struct Cursor *)(*(int *)(*(int *)&task->work + 0x70)),
                  (unsigned char)(task->cursorSlot - 0x1e));
    BOX2_UI_SetCursorPos((char **)task, task->cursorSlot - 0x1e);
    BOX2_SEQ_SetCursorDraw((char **)task, 1);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    return 0x31;
}

/*
 * Five-step machine on the work word at 0xA194: fade out, confirm the
 * party slot (or back out to state 0x33), fade, swap, then reopen.
 */
int BOX2_SEQ_StateSummaryC(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(task);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x34);
    case 1:
        switch (BOX2_SEQ_CheckTradableMon((unsigned char *)task)) {
        case 0:
            task->handMode = 1;
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
            BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), 0x24, 0);
            BOX2_SEQ_SetCursorDraw((char **)task, 1);
            BOX2_UI_SetCursorPos((char **)task, task->cursorSlot - 0x1E);
            (((BoxTask *)(task))->work->seqStep)++;
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneWaitCursor, 0x34);
        case 1:
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_PrintMonName((BoxTask *)task, 6, 0x18);
            (((BoxTask *)(task))->state) = 0x33;
            (((BoxTask *)(task))->work->seqStep) = 0;
            return 6;
        case 2:
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_PrintPrompt((BoxTask *)task, 0, 5, 0x18);
            (((BoxTask *)(task))->state) = 0x33;
            (((BoxTask *)(task))->work->seqStep) = 0;
            return 6;
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_UI_OpenBar((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x34);
    case 3:
        BOX2_UI_PlaceCursorAtIcon((BoxTask *)task, task->cursorSlot - 0x1E);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneApplyScroll, 0x34);
    case 4:
        GFL_HEAP_Free(*(void **)(((char *)((BoxTask *)(task))->work) + 0x60));
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_PrintPrompt((BoxTask *)task, 0, 3, 0x1A);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
        BOX2_UI_MoveCursor((char **)task, 1, 0);
        (((BoxTask *)(task))->work->seqStep) = 0;
        return 0x35;
    }
    return 0x34;
}

/*
 * Party list input: L and R page the list when nothing is picked; a pick
 * of the first two rows opens the slot (or refuses it), the others page,
 * jump or cancel.
 */
int BOX2_SEQ_StateListScroll(BoxTask *task)
{
    unsigned r;
    unsigned b, a;

    r = CURSOR_MOVE_PollRepeatInput((((BoxTask *)(task))->work->cursorMove));
    if (r == (unsigned)-1) {
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_ActivateKeyCursor(task);
            r = 2;
        } else if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_ActivateKeyCursor(task);
            r = 3;
        }
    }
    switch (r) {
    case 0:
    case 1:
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX_SAVEDATA_CountFreeSlotsInBox(*(void **)(((char *)((BoxTask *)(task))->params) + 4), task->curBox) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintPrompt((BoxTask *)task, 0, 4, 0x18);
            (((BoxTask *)(task))->state) = 0x37;
            return 6;
        }
        a = task->curBox;
        b = 0;
        BOX_SAVEDATA_FindFreeSlot(*(void **)(((char *)((BoxTask *)(task))->params) + 4), (int *)(&a), (int *)(&b));
        *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA17E) = b;
        task->phase = 0;
        task->heldSlot = task->curBox;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x36);
    case 2:
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0);
    case (unsigned)-6:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x35);
    case 3:
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0);
    case (unsigned)-5:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x35);
    case 4:
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA17E) = 0xFF;
        task->heldSlot = task->curBox;
        task->phase = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x36));
    case (unsigned)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case (unsigned)-8:
    case (unsigned)-7:
    case (unsigned)-3:
    case (unsigned)-1:
        break;
    }
    return 0x35;
}

/*
 * Eight-step machine on the work word at 0xA194 for the party swap:
 * fade, take the slot (from the held box slot at 0xA17E if any), fade
 * back and restore the box view.
 */
int BOX2_SEQ_StateScrollBox(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        if (task->work->targetBox == 0xFF) {
            BOX2_UI_PlaceCursorAtMon((BoxTask *)task, task->cursorSlot);
            (((BoxTask *)(task))->work->seqStep) = 1;
        } else {
            BOX2_UI_PlaceCursorAtMon((BoxTask *)task, task->work->targetBox);
            (((BoxTask *)(task))->work->seqStep) = 4;
        }
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(task);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneApplyScroll, 0x36);
    case 1:
        GFL_HEAP_Free(*(void **)(((char *)((BoxTask *)(task))->work) + 0x60));
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_UI_CloseBar((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep) = 2;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x36);
    case 2:
        BOX2_SEQ_Create((void *)task);
        (((BoxTask *)(task))->work->seqStep) = 6;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneOpenBox, 0x36);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_UI_CloseBar((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep) = 7;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x36);
    case 4:
        GFL_HEAP_Free(*(void **)(((char *)((BoxTask *)(task))->work) + 0x60));
        BOX2_SEQ_Create((void *)task);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        (((BoxTask *)(task))->work->seqStep) = 5;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineRunSwap, 0x36);
    case 5:
        BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
        BOX2_SEQ_Delete(task);
        BOX2_MAIN_ResetBoxView(task);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)task, 2, 0);
        (((BoxTask *)(task))->work->seqStep) = 3;
        break;
    case 6:
        BOX2_SEQ_Delete(task);
    case 7:
        task->handMode = 0;
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
        BOX2_UI_MoveCursor((char **)task, 0, task->cursorSlot - 0x1E);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
        (((BoxTask *)(task))->work->seqStep) = 0;
        return 0x31;
    }
    return 0x36;
}

int BOX2_SEQ_StateOpenItemD(u8 *task){BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)task)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)task);BOX2_SEQ_PrintPrompt((BoxTask *)task,0,3,26);BOX2_UI_DeleteSlotObjects((BoxTask *)task,0,1,1);return 53;}





















int BOX2_SEQ_StateOpenItemE(unsigned char *task)
{
    BOX2_MAIN_UpdateBoxSlots((struct BoxTask *)(unsigned char *)task);
    BOX2_SEQ_Delete((BoxTask *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
    if (task[0x16] == 0xff) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0);
        BOX2_UI_SetCursorPos((char **)task, 0);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, 0x1e);
    } else {
        BOX2_SEQ_PrintPrompt((BoxTask *)task, task[0x16], 1, 0x18);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 8);
        BOX2_UI_SetCursorPos((char **)task, 8);
    }
    return 0x31;
}
















int BOX2_SEQ_StateItemMenuE(BoxTask *task)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        r = BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)task, 0x3F);
        if (task->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v < 0x1E)
                task->cursorSlot = v;
            else
                task->cursorSlot = 0;
        }
        return r;
    }
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            return BOX2_SEQ_DrawGridSlot((BoxTask *)task, r);
        }
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, r, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
            return BOX2_SEQ_SetBox2UiE((BoxTask *)task);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        return 0x39;
    }
    r = BOX2_UI_UpdateCursorInputE((BoxTask *)task);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 1, 0x39);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 1, 0x39);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 10, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1A));
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x3F));
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (*(unsigned short *)((char *)task->work + 0xA16C) == 0) {
            task->menuMode = 0;
            task->pickedSlot = 0x25;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
        }
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
    case 0x26: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x3A);
    }
    case 0x27:
        r = BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)task, 0x3F);
        if (task->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v < 0x1E)
                task->cursorSlot = v;
            else
                task->cursorSlot = 0;
        }
        return r;
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 1, 0x39);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 1, 0x39);
        }
        break;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 0x1E)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x39));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x3A);
        }
        task->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return BOX2_SEQ_SetCursorMove((BoxTask *)task, r);
        }
        break;
    }
    return 0x39;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowA, state 0x39 and
 *   0x021E0E51 as the selector.
 */
int BOX2_SEQ_SetBox2UiE(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowA((struct BoxWork *)(char *)(*(int *)&task->work));
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x21E0E51, BOX2_SEQ_SetState((BoxTask *)task, 0x39));
}















int BOX2_SEQ_DeleteBox2UiC(BoxTask *task)
{
    if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 0xa) == 1)
        return 0x3b;
    BOX2_SEQ_SetActorAnim((BoxTask *)task, 0);
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 0xa, 0);
    BOX2_SEQ_PrintPromptB((BoxTask *)task, 3, 0x18);
    if (task->cursorSlot < 0x1e) {
        BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
    } else {
        BOX2_SEQ_SetSlotActors((char *)task, 0x82, 1);
    }
    *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xa16c) = 0;
    task->state = 0x3d;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
}

void BOX2_SEQ_StateCloseBoxC(u8 *task){BOX2_SEQ_SetSlotDim((char **)task,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)task)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)task);if(task[0x16]<30)BOX2_UI_ShowWindowA((struct BoxWork *)*(char * *)&((BoxTask *)task)->work);else BOX2_UI_ShowWindowB((struct BoxWork *)*(char * *)&((BoxTask *)task)->work);BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_StateMachineHideHand,61);}























int BOX2_SEQ_StateMenuItems(BoxTask *task)
{
    int r;
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(task);
    if (task->cursorSlot < 0x1e) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot);
        BOX2_UI_SetCursorPos((char **)task, task->cursorSlot);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        r = 0x39;
    } else {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot - 0x1e);
        BOX2_UI_SetCursorPos((char **)task, task->cursorSlot - 0x1e);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        r = 0x46;
    }
    BOX2_SEQ_SetCursorDraw((char **)task, 1);
    BOX2_SEQ_SetWindow9((BoxTask *)task, 0xe, 1);
    return r;
}

int BOX2_SEQ_StateSelectItem(u8 *task){int sel;sel=37;if(*(u16 *)(*(char **)(task+0x2c)+0xa16c)!=0)sel=36;CURSOR_MOVE_SetCurrent(*(void **)(*(char **)(task+0x2c)+0x70),sel);BOX2_UI_SetCursorPos((char **)task,sel);BOX2_SEQ_SetCursorDraw((char **)task,1);return 57;}





















/*
 * Three-step machine on the work word at 0xA194: close the held view,
 * fade, then reopen the menu for the current nibble mode.
 */
int BOX2_SEQ_StateSummaryD(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        (((BoxTask *)(task))->work->seqStep)++;
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        if (BOX2_UI_IsTopBarClosed((((BoxTask *)(task))->work->winMgr)) == 1)
            task->barFlag = 1;
        else
            task->barFlag = 0;
        if ((((BoxTask *)(task)))->listState == 1) {
            task->heldSlot = 0xFF;
            *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C) = 0;
            BOX2_MAIN_RefreshCursorBox(task);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
        } else {
            if ((((BoxTask *)(task)))->listState == 2 && *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C) == 0) {
                task->heldSlot = 0xFF;
                (((BoxTask *)(task)))->listState = 1;
            }
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
            BOX2_MAIN_RefreshCursorBox(task);
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineHideHandWindow, 0x3F);
        }
    case 1:
        (((BoxTask *)(task))->work->seqStep)++;
        if (BOX2_UI_IsTopBarClosed((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_SlideBarIn((((BoxTask *)(task))->work->winMgr));
        } else {
            BOX2_UI_PutBottomBarClosed((((BoxTask *)(task))->work->winMgr));
            BOX2_UI_CloseBar((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_HidePartialSlots((char **)task, 0);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x3F);
    case 2:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
        BOX2_SEQ_SetSlotActors((char *)task, 0x82, 1);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        CURSOR_MOVE_ClearSkipBit((((BoxTask *)(task))->work->cursorMove), 0x27);
        CURSOR_MOVE_ClearSkipBit((((BoxTask *)(task))->work->cursorMove), 0x28);
        if ((((BoxTask *)(task)))->listState == 1) {
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xD, 1);
            return 0x40;
        }
        if ((((BoxTask *)(task)))->listState == 2)
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xD, 1);
        else
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 1);
        return BOX2_SEQ_DrawGridSlotB((BoxTask *)task, task->cursorSlot);
    }
    return 0x3F;
}




























/*
 * Sibling of src/matched/BOX2_SEQ_StateMoveInput.c.
 */
int BOX2_SEQ_StateItemMenuF(BoxTask *task)
{
    unsigned r;
    if (task->exitFlag == 1) {
        task->listState = 0;
        task->exitFlag = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x41);
    }
    if ((KEY_GetTrg() & 4) && task->listState != 0 && task->handMode == 0) {
        BOX2_MAIN_ActivateKeyCursor((BoxTask *)task);
        task->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x41);
    }
    if (task->handMode == 0) {
        r = BOX2_UI_GetBodySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
                BOX2_SEQ_SetActorDrawEnable((char *)task->work, 4, 0);
                return BOX2_SEQ_SelectGridSlot((BoxTask *)task, r + 0x1E);
            }
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r + 0x1E);
            return 0x40;
        }
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
                BOX2_SEQ_SetActorDrawEnable((char *)task->work, 4, 0);
                return BOX2_SEQ_SelectGridSlot((BoxTask *)task, r);
            }
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
            return 0x40;
        }
    }
    r = BOX2_UI_CursorInputRight((BoxTask *)task);
    switch (r) {
    case 0x24:
        if (task->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5D);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
        BOX2_UI_SetCursorPos((char **)task, 0x24);
        if (task->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x40);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
        BOX2_UI_SetCursorPos((char **)task, 0x24);
        if (task->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x40);
    case 0x29:
        if (task->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x41));
    case 0x2A:
        if (task->listState == 0 || task->handMode != 0)
            break;
        task->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x41);
    case -2:
        if (task->handMode == 1)
            return BOX2_SEQ_MoveGridCursor((BoxTask *)task, 0xFF);
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x41));
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x40);
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x40);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (task->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v < 0x24)
                BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
            else
                BOX2_MAIN_ResetBoxView((BoxTask *)task);
        }
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x40));
    case -1:
    case -7:
    case -8:
    case 0x27:
    case 0x28:
        break;
    default:
        if (task->handMode == 1)
            return BOX2_SEQ_MoveGridCursor((BoxTask *)task, r);
        return BOX2_SEQ_DrawGridSlotB((BoxTask *)task, r);
    }
    return 0x40;
}

int BOX2_SEQ_StateCloseItem(BoxTask *task)
{
    u8 index;
    u8 selection;
    switch (task->work->seqStep) {
    case 0:
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&task->work, 4, 0);
        if (task->barFlag == 0) {
            BOX2_UI_OpenBar(*(struct BgWinFrmWork * *)&task->work->winMgr);
        } else {
            BOX2_UI_ToggleSlotPair((struct BoxWork *)*(char * *)&task->work, 0);
            BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
            BOX2_UI_SlideBarOut(*(struct BgWinFrmWork * *)&task->work->winMgr);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        (task->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 65);
    case 1:
        task->work->seqStep = 0;
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
        if (task->barFlag == 0) {
            index = CURSOR_MOVE_GetCurrent(task->work->cursorMove);
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            BOX2_UI_MoveCursor((char **)task, 7, index);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, index);
            BOX2_UI_ShowWindowA((struct BoxWork *)*(char * *)&task->work);
            return 57;
        } else {
            index = CURSOR_MOVE_GetCurrent(task->work->cursorMove);
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            BOX2_UI_MoveCursor((char **)task, 8, selection);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, selection + 30);
            BOX2_UI_ShowWindowB((struct BoxWork *)*(char * *)&task->work);
            return 70;
        }
    }
    return 65;
}










/*
 * Drop of a held item onto a slot: put it back when dropped where it was
 * picked up, otherwise swap the two slots' items.
 */
int BOX2_SEQ_StateMoveItemScroll(BoxTask *task)
{
    Box2Entry *o;
    if ((((BoxTask *)(task)))->listState == 0)
        (((BoxTask *)(task)))->exitFlag = 1;
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    o = *(Box2Entry **)(((char *)((BoxTask *)(task))->work) + 0x60);
    if (o->idx == task->cursorSlot && (task->heldSlot == 0xFF || task->heldSlot == task->curBox)) {
        unsigned short from = o->slot;
        BOX2_SEQ_DeleteB(task);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
        if (FILE_UTIL_IsMailItem((((BoxTask *)(task))->work->counter)) == 1 && from != task->cursorSlot) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintMessageC((char *)task, 0x18);
            (((BoxTask *)(task))->state) = 0x44;
            return 6;
        }
        return 0x40;
    } else {
        unsigned short item;
        if (task->heldSlot == task->curBox || task->cursorSlot >= 0x1E)
            BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), task->cursorSlot, 1);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), o->idx, 0);
        item = BOX2_MAIN_GetPartyValueAt((void ***)task, o->idx, task->curBox, 6, 0);
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, o->idx, task->curBox, 6, (((BoxTask *)(task))->work->counter));
        if (BOX2_MAIN_SyncItemForm((void **)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, o->idx)) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)task, o->idx);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, o->idx, (((BoxTask *)(task))->work->cursorTable[o->idx]));
        }
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, o->idx);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), o->idx);
        (((BoxTask *)(task))->work->counter) = item;
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, task->cursorSlot, task->heldSlot, 6, (((BoxTask *)(task))->work->counter));
        if (BOX2_MAIN_SyncItemForm((void **)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->heldSlot, task->cursorSlot)) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)task, task->cursorSlot);
            if (task->heldSlot == 0xFF || task->heldSlot == task->curBox)
                BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, task->cursorSlot, (((BoxTask *)(task))->work->cursorTable[task->cursorSlot]));
        }
        if ((((BoxTask *)(task))->work->counter) == 0) {
            task->cursorSlot = o->idx;
            BOX2_SEQ_DeleteB(task);
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
            return 0x40;
        }
        BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->counter));
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 1);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 1);
        BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(task))->work));
        GFL_USE_PlaySeDefaultVolume(0x666);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineReturnHeld, 0x43);
    }
}

int BOX2_SEQ_StateMoveItemB(BoxTask *task)
{
    unsigned short *o;
    unsigned char old;
    unsigned short slot, item;
    unsigned char r;
    if (((BoxTask *)task)->listState == 0)
        ((BoxTask *)task)->exitFlag = 1;
    o = *(unsigned short **)(((char *)((BoxTask *)(task))->work) + 0x60);
    BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), o[0], 0);
    old = task->cursorSlot;
    slot = o[1];
    task->cursorSlot = o[0];
    BOX2_SEQ_DeleteB(task);
    item = *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C);
    *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C) = 0;
    if (FILE_UTIL_IsMailItem(item) == 1 && slot != old) {
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_PrintMessageC((char *)task, 0x18);
        task->state = 0x44;
        return 6;
    }
    BOX2_SEQ_SetCursorDraw((char **)task, 1);
    r = CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70));
    if (r < 0x24)
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
    return 0x40;
}

/*
 *   unsigned CURSOR_MOVE_GetState(unsigned char *p) { return *(unsigned *)(p+4); }
 */
int BOX2_SEQ_StateCloseItemB(u8 *task){BOX2_SEQ_HideWindowObject(*(char **)(task+0x2c),24);BOX2_MAIN_RefreshCursorBox((BoxTask *)task);if(CURSOR_MOVE_GetState(*(void **)(*(char **)(task+0x2c)+0x70))==1)BOX2_SEQ_SetActorDrawEnable(*(char **)(task+0x2c),4,1);return 64;}










/*
 * Twin of BOX2_SEQ_StateMoveItemScroll driven by the work fields: moves the held item from
 * slot 0xA16E to slot 0xA17E, swapping with what is there.
 */
int BOX2_SEQ_StatePlaceItem(BoxTask *task)
{
    unsigned short item;
    if ((((BoxTask *)(task)))->listState == 0)
        (((BoxTask *)(task)))->exitFlag = 1;
    if ((((BoxTask *)(task))->work->targetBox) == (((BoxTask *)(task))->work->cursorIndex) && (task->heldSlot == 0xFF || task->heldSlot == task->curBox)) {
        (((BoxTask *)(task))->work->counter) = 0;
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
        return 0x40;
    }
    if (task->heldSlot == task->curBox || (((BoxTask *)(task))->work->cursorIndex) >= 0x1E)
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->cursorIndex), 1);
    BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->targetBox), 0);
    item = BOX2_MAIN_GetPartyValueAt((void ***)task, (((BoxTask *)(task))->work->targetBox), task->curBox, 6, 0);
    BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, (((BoxTask *)(task))->work->targetBox), task->curBox, 6, (((BoxTask *)(task))->work->counter));
    if (BOX2_MAIN_SyncItemForm((void **)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, (((BoxTask *)(task))->work->targetBox))) == 1) {
        BOX2_MAIN_RecalcPartyParam((void **)task, (((BoxTask *)(task))->work->targetBox));
        BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, (((BoxTask *)(task))->work->targetBox), (((BoxTask *)(task))->work->cursorTable[(((BoxTask *)(task))->work->targetBox)]));
    }
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (((BoxTask *)(task))->work->targetBox));
    (((BoxTask *)(task))->work->counter) = item;
    BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, (((BoxTask *)(task))->work->cursorIndex), task->heldSlot, 6, (((BoxTask *)(task))->work->counter));
    if (BOX2_MAIN_SyncItemForm((void **)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->heldSlot, (((BoxTask *)(task))->work->cursorIndex))) == 1) {
        BOX2_MAIN_RecalcPartyParam((void **)task, (((BoxTask *)(task))->work->cursorIndex));
        if (task->heldSlot == 0xFF || task->heldSlot == task->curBox)
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, (((BoxTask *)(task))->work->cursorIndex), (((BoxTask *)(task))->work->cursorTable[(((BoxTask *)(task))->work->cursorIndex)]));
    }
    if ((((BoxTask *)(task))->work->counter) == 0) {
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
        return 0x40;
    }
    BOX2_SEQ_CreateB((void *)task);
    (*(Box2Entry **)(((char *)((BoxTask *)(task))->work) + 0x60))->idx = (((BoxTask *)(task))->work->targetBox);
    BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->counter));
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
    BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 1);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 1);
    BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(task))->work));
    GFL_USE_PlaySeDefaultVolume(0x666);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineReturnHeld, 0x43);
}











/*
 * Sibling of src/matched/BOX2_SEQ_StateItemMenuE.c and BOX2_SEQ_StateMoveMove.c.
 */
int BOX2_SEQ_StateCursorMoveB(BoxTask *task)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        r = BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)task, 0x3F);
        if (task->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v < 6)
                task->cursorSlot = v + 0x1E;
            else
                task->cursorSlot = 0x1E;
        }
        return r;
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)task->work + 0xA180), (u32 *)((char *)task->work + 0xA184));
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, (int)r + 0x1E);
            return BOX2_SEQ_DeleteGridSlot((BoxTask *)task, r + 0x1E);
        }
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, (unsigned char)r, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r + 0x1E);
            return BOX2_SEQ_SetBox2UiF((BoxTask *)task);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), r);
        BOX2_UI_SetCursorPos((char **)task, r);
        return 0x46;
    }
    r = BOX2_UI_UpdateCursorInputF((BoxTask *)task);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 10, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1C));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        task->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1C));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        task->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x3F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (*(unsigned short *)((char *)task->work + 0xA16C) == 0) {
            task->menuMode = 1;
            task->pickedSlot = 10;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
        }
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x50));
    case 11: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x47);
    }
    case 12:
        r = BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)task, 0x3F);
        if (task->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
            if (v < 6)
                task->cursorSlot = v + 0x1E;
            else
                task->cursorSlot = 0x1E;
        }
        return r;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 6)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x46));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x47);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r + 0x1E, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return BOX2_SEQ_SetCursorMoveB((BoxTask *)task, r + 0x1E);
        }
        break;
    }
    return 0x46;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowB, state 0x46 and
 *   0x021E0E51 as the selector.
 */
int BOX2_SEQ_SetBox2UiF(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowB((struct BoxWork *)(char *)(*(int *)&task->work));
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x21E0E51, BOX2_SEQ_SetState((BoxTask *)task, 0x46));
}

int BOX2_SEQ_StateMoveItemC(u8 *task)
{
    u16 *pair = *(u16 **)(((u8 *)((BoxTask *)(task))->work) + 96);
    u16 item = *(u16 *)(((u8 *)((BoxTask *)(task))->work) + 0xa16c);
    u16 second;
    if (item == 0) {
        BOX2_SEQ_DeleteB((BoxTask *)task);
        BOX2_SEQ_PrintPromptB((BoxTask *)task, 0, 24);
        CURSOR_MOVE_SetCurrent(*(void **)(((u8 *)((BoxTask *)(task))->work) + 112), 10);
        BOX2_UI_SetCursorPos((char **)task, 10);
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        return 70;
    }
    if (pair[0] == task[22]) {
        second = pair[1];
        BOX2_SEQ_DeleteB((BoxTask *)task);
        CURSOR_MOVE_SetCurrent(*(void **)(((u8 *)((BoxTask *)(task))->work) + 112), 9);
        BOX2_UI_SetCursorPos((char **)task, 9);
        if (FILE_UTIL_IsMailItem(*(u16 *)(((u8 *)((BoxTask *)(task))->work) + 0xa16c)) == 1 && second != task[22]) {
            BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(task))->work), task[22], 0);
            BOX2_SEQ_PrintPromptB((BoxTask *)task, 7, 24);
            GFL_USE_PlaySeDefaultVolume(0x557);
            *(int *)(task + 40) = 14;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
        }
        BOX2_SEQ_PrintPromptB((BoxTask *)task, 1, 24);
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        return 70;
    }
    if (FILE_UTIL_IsMailItem(item) == 1) {
        BOX2_SEQ_DeleteB((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(task))->work), task[22], 0);
        BOX2_SEQ_PrintPromptB((BoxTask *)task, 7, 24);
        GFL_USE_PlaySeDefaultVolume(0x557);
        CURSOR_MOVE_SetCurrent(*(void **)(((u8 *)((BoxTask *)(task))->work) + 112), 9);
        BOX2_UI_SetCursorPos((char **)task, 9);
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        *(int *)(task + 40) = 14;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
    }
    BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(task))->work), pair[0], 0);
    BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(task))->work), task[22], 1);
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_SetActorAffineMode((char *)((u8 *)((BoxTask *)(task))->work), 1);
    BOX2_SEQ_SetActorAnimSeq((char *)((u8 *)((BoxTask *)(task))->work), 10, 2);
    return 73;
}









/*
 * Item swap on drop (template 021E6A60): moves the held item onto the
 * target slot, returns the target's old item to the source, and either
 * finishes or keeps the new item held.
 */
int BOX2_SEQ_StatePlaceItemB(BoxTask *task)
{
    Box2Entry *o;
    unsigned short item;

    if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) == 1)
        return 0x49;
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 0);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 0);
    o = *(Box2Entry **)(((char *)((BoxTask *)(task))->work) + 0x60);
    item = BOX2_MAIN_GetPartyValueAt((void ***)task, o->idx, task->curBox, 6, 0);
    BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, o->idx, task->curBox, 6, (((BoxTask *)(task))->work->counter));
    if (BOX2_MAIN_SyncItemForm((void **)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, o->idx)) == 1) {
        BOX2_MAIN_RecalcPartyParam((void * *)task, o->idx);
        BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, o->idx, (((BoxTask *)(task))->work->cursorTable[o->idx]));
    }
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, o->idx);
    (((BoxTask *)(task))->work->counter) = item;
    BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, task->cursorSlot, task->heldSlot, 6, (((BoxTask *)(task))->work->counter));
    if (task->heldSlot == 0xFF || task->heldSlot == task->curBox) {
        if (BOX2_MAIN_SyncItemForm((void **)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot)) == 1) {
            BOX2_MAIN_RecalcPartyParam((void * *)task, task->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, task->cursorSlot, (((BoxTask *)(task))->work->cursorTable[task->cursorSlot]));
        }
    }
    if ((((BoxTask *)(task))->work->counter) == 0) {
        task->cursorSlot = o->idx;
        BOX2_SEQ_DeleteB(task);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot - 0x1E);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 1);
        return 0x46;
    }
    GFL_USE_PlaySeDefaultVolume(0x666);
    BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->counter));
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
    BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 1);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 10, 1);
    BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(task))->work));
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_StateExitBox, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x4A));
}

int BOX2_SEQ_StateMoveItemD(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x667);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), **(unsigned short **)(((char *)((BoxTask *)(task))->work) + 0x60), 0);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 10, 2);
        CURSOR_MOVE_SetCurrent(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), task->cursorSlot - 0x1E);
        BOX2_SEQ_DeleteB(task);
        (((BoxTask *)(task))->work->seqStep)++;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(task))->work), 10) == 1)
            break;
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 1);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        return 0x46;
    }
    return 0x4A;
}


















int BOX2_SEQ_StateCursorMoveC(BoxTask *task)
{
    unsigned r = BOX2_UI_CursorInputPage((BoxTask *)task);
    switch (r) {
    case 0x1E:
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        break;
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x4B);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)task);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x1E);
        BOX2_UI_SetCursorPos((char **)task, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x4B);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x551);
        task->params->swapMode = 0;
        task->params->savedBox = 0xFF;
        task->params->savedSlot = 0xFF;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x4D));
    case 0x23: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = task->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x4E);
    }
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)task, 0, 0x4B);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)task);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)task, 0, 0x4B);
        }
        break;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
        if (v < 0x1E)
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
        else if (v != 0x22 && v != 0x23)
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x4B));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            unsigned char k = task->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, 0x4E);
        }
        task->params->swapMode = 0;
        task->params->savedBox = 0xFF;
        task->params->savedSlot = 0xFF;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, r, task->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            task->cursorSlot = r;
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF8EC, 2);
            BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
            BOX2_SEQ_RefreshCursorSlot((BoxTask *)task);
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x22);
            if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1)
                return BOX2_SEQ_StatePushSlot((char *)task);
            BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 0x22, r);
            BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)task, 0x4C));
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, r);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x4B);
        }
        break;
    }
    return 0x4B;
}

/*
 * Push the 0x16 field through the 0x18 selector; return 75.
 */
int BOX2_SEQ_StatePushSlot(char *task)
{
    BOX2_SEQ_PrintPrompt((BoxTask *)task, (unsigned char)task[0x16], 1, 0x18);
    return 0x4b;
}

int BOX2_SEQ_StateSwapMenuC(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x4D);
    case 1:
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 0x4C, 0) != 0) {
            BOX2_SEQ_PrintMenuRow((char *)task, 4, 0x18);
            task->state = 0xE;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
        }
        if (BOX2_MAIN_GetBoxValue((char *)task, task->cursorSlot) == 0) {
            BOX2_SEQ_PrintMenuRow((char *)task, 6, 0x1B);
            task->state = 0xE;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
        }
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
        BOX2_SEQ_PrintBoxMonName((unsigned char *)task);
        (((BoxTask *)(task))->work->seqStep) = 0;
        return BOX2_SEQ_OpenYesNo((BoxTask *)task, 5);
    }
    return 0x4D;
}

void BOX2_SEQ_SetBox2MainD(BoxTask *task)
{
    BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(task);
    BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)task, 0x4B));
}

int BOX2_SEQ_StateCloseItemC(unsigned char *task)
{
    return BOX2_SEQ_GotoBox2Ui((BoxTask *)task, 0);
}










/*
 * Item menu "give": checks the slot, then asks to swap or confirms.  A
 * four-step machine on the work word at 0xA194 (template 021E3C88).
 */
int BOX2_SEQ_StateSwapMenuD(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0: {
        unsigned item;
        if (*(int *)(((char *)((BoxTask *)(task))->params) + 0x24) == 4 && *(int *)(((char *)((BoxTask *)(task))->params) + 0x14) == 1) {
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            (((BoxTask *)(task))->work->seqStep) = 3;
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x50);
        }
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 0x4C, 0) == 0) {
            item = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
            if (item == 0)
                return BOX2_SEQ_GotoBox2Ui((BoxTask *)task, 1);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 0);
            BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
            if (FILE_UTIL_IsMailItem(item) == 1) {
                BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
                (((BoxTask *)(task))->work->seqStep) = 1;
                return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x50);
            }
            if (task->cursorSlot < 0x1E)
                BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
            else
                BOX2_SEQ_SetSlotActors((char *)task, 2, 1);
            BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
            *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA170) = 1;
            BOX2_UI_ResetSlotFrames((((BoxTask *)(task))->work->winMgr));
            BOX2_SEQ_PrintWordset((BoxTask *)task, item, 0x18);
            if (*(int *)(((char *)((BoxTask *)(task))->params) + 0x24) == 3)
                return BOX2_SEQ_OpenYesNo((BoxTask *)task, 2);
            return BOX2_SEQ_OpenYesNo((BoxTask *)task, 0);
        }
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep) = 2;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x50);
    }
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintMessage((unsigned char *)task, 0x18);
        (((BoxTask *)(task))->state) = 0xE;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintPromptB((BoxTask *)task, 5, 0x18);
        (((BoxTask *)(task))->state) = 0xE;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintYesNo((char *)task, 1);
        (((BoxTask *)(task))->state) = 0x2B;
        return 6;
    }
    return 0x50;
}

int BOX2_SEQ_SetBox2MainE(BoxTask *task)
{
    if (task->heldSlot != 0xFF)
        BOX2_MAIN_RefreshMonInfo((char *)task, task->heldSlot, task->cursorSlot);
    else
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
    BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
    if (((BoxTask *)task)->listState == 0)
        BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
    else
        BOX2_SEQ_SetWindow9((BoxTask *)task, 0xD, 1);
    switch (task->params->mode) {
    case 0:
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenB((BoxTask *)task);
        break;
    case 1:
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpen((unsigned char *)task);
        break;
    case 2:
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenC((BoxTask *)task);
        break;
    case 4:
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenD((BoxTask *)task);
        break;
    case 3:
        break;
    }
    return BOX2_SEQ_StateWaitPrint((sptr)task);
}















int BOX2_SEQ_StateSwapFinishB(BoxTask *task)
{
    BOX2_MAIN_ResetBoxView(task);
    switch (task->params->mode) {
    case 1:
        BOX2_UI_MoveCursor((char **)task, 2, 0x1E);
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = 0x2C;
        break;
    case 2:
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_UI_MoveCursor((char **)task, 3, 0x1E);
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = 0x11;
        break;
    case 3:
        BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_UI_MoveCursor((char **)task, 7, 0x1E);
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = 0x39;
        break;
    case 4:
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_UI_MoveCursor((char **)task, 0xD, 0x1E);
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA198) = 0x23;
        break;
    case 0:
        break;
    }
    return BOX2_SEQ_StateWaitPrint((sptr)task);
}

int BOX2_SEQ_StateCloseItemD(u8 *task){switch(((BoxTask *)task)->params->mode){case 2:((BoxTask *)task)->work->nextState=BOX2_SEQ_StatePmVoiceMenuB((BoxTask *)task);break;case 3:((BoxTask *)task)->work->nextState=BOX2_SEQ_StatePmVoiceMenuC((BoxTask *)task);break;case 4:((BoxTask *)task)->work->nextState=BOX2_SEQ_StatePmVoiceMenuD((BoxTask *)task);break;}return BOX2_SEQ_StateWaitPrint((sptr)task);}

/*
 * candidate BOX2_SEQ_StateExitToField: state machine step
 */
void BOX2_SEQ_StateExitToField(BoxTask *task)
{
    int v;
    BOX2_SEQ_PrintWordsetBB64((BoxTask *)task, task->subResult, 0x18);
    v = *(int *)(*(int *)&task->params + 0x24);
    if (v == 3)
        task->state = 0x3c;
    else
        task->state = 0xe;
    BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
}

int BOX2_SEQ_StateSwapMenuE(BoxTask *task)
{
    switch (task->work->seqStep) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&task->work, 4, 0);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 0);
        BOX2_SEQ_ShowWindowObject(*(char * *)&task->work, 24);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork * *)&task->work->winMgr);
        (task->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 85);
    case 1:
        task->work->selectMask = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 11, 0);
        BOX2_MAIN_SetHandSlots((char *)task, task->work->selectMask);
        BOX2_UI_PutTopBarThenClose(*(struct BgWinFrmWork * *)&task->work->winMgr);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (task->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)((int (*)(u8 *))BOX2_MAIN_UpdateWindowMove), 85);
    case 2:
        BOX2_UI_MoveCursor((char **)task, 9, 0);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)*(char * *)&task->work, 0);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)task, 2, 1);
        BOX2_SEQ_SetSlotActorMode(*(char * *)&task->work, task->cursorSlot, 0);
        BOX2_SEQ_PrintMessageE((char *)task, 24);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 86);
    }
    return 85;
}

int BOX2_SEQ_StateCloseMenu(BoxTask *task)
{
    u8 mask;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(task->work->cursorMove)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((sptr)task, 0);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((sptr)task, 1);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((sptr)task, 2);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((sptr)task, 3);
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((sptr)task, 4);
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((sptr)task, 5);
        break;
    case 6:
        mask = task->work->selectMask;
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, task->cursorSlot, task->curBox, 11, mask);
        BOX2_MAIN_SetBodySlots((char *)task, (unsigned)mask);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_SetupFrameFadeAndWait((BoxTask *)task, 0, 87);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_SetupFrameFadeAndWait((BoxTask *)task, 1, 87);
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_SetupFrameFadeAndWait((BoxTask *)task, 1, 87);
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, 88);
    case (unsigned)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    }
    return 86;
}

int BOX2_SEQ_StateSummaryE(BoxTask *task)
{
    switch (task->params->mode) {
    case 0:
        BOX2_UI_MoveCursor((char **)task, 0, 10);
        break;
    case 1:
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_UI_MoveCursor((char **)task, 2, 0x25);
        break;
    case 2:
    default:
        if (task->cursorSlot < 0x1E) {
            BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
            BOX2_UI_MoveCursor((char **)task, 3, 0x27);
        } else {
            BOX2_UI_MoveCursor((char **)task, 5, 0xC);
        }
        break;
    }
    BOX2_SEQ_SetCursorDraw((char **)task, 0);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(task);
    if (task->cursorSlot < 0x1E)
        BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
    BOX2_SEQ_SetSlotActors((char *)task, 2, 0);
    BOX2_UI_RepenTopBar(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
    GFL_USE_PlaySeDefaultVolume(0x669);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)((int (*)(unsigned char *))BOX2_MAIN_UpdateWindowMove), BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0xE));
}

/*
 * Forward and then return a status constant.
 */
int BOX2_SEQ_StateDeleteHandle(BoxTask *task)
{
    GFL_HEAP_Free(task->work->seq.entry);
    return 0x56;
}

int BOX2_SEQ_StateConfirmRelease(BoxTask *task)
{
    unsigned slot;
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 0);
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x59);
    case 1:
        if (task->cursorSlot >= 30) {
            BOX2_SEQ_SetSlotActors((char *)task, 2, 1);
            BOX2_SEQ_SetSlotActorMode((char *)((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
            slot = task->cursorSlot - 30;
            if (BOX2_MAIN_HasOtherTradable((void ***)task, slot) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                BOX2_SEQ_PrintMonName((BoxTask *)task, 6, 24);
                *(u8 *)(((char *)((BoxTask *)(task))->work) + 0xA170) = 1;
                task->state = 14;
                return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
            }
            if (FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(task->params->party, slot), 6, 0)) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                BOX2_SEQ_PrintPrompt((BoxTask *)task, 0, 5, 24);
                *(u8 *)(((char *)((BoxTask *)(task))->work) + 0xA170) = 1;
                task->state = 14;
                return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
            }
        } else {
            BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
            BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
            BOX2_SEQ_SetSlotActorMode((char *)((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
        }
        if (POKE_TOOL_GetBoxValue((void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot), 0x4c, 0) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintMonName((BoxTask *)task, 3, 24);
            *(u8 *)(((char *)((BoxTask *)(task))->work) + 0xA170) = 1;
            task->state = 14;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
        }
        BOX2_SEQ_PrintMonName((BoxTask *)task, 0, 24);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, BOX2_SEQ_OpenYesNo((BoxTask *)task, 1));
    }
    return 0x59;
}

int BOX2_SEQ_StateCloseZoom(unsigned char *task)
{
    BOX2_MAIN_StepScroll((BoxTask *)task);
    if (BOX2_SEQ_ShrinkActor((((BoxTask *)(task))->work->scroll)) == 0) {
        if (((unsigned char *)(((BoxTask *)(task))->work->scroll))[6] != 0)
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5C);
        BOX2_SEQ_HideActor((int *)(((BoxTask *)(task))->work->scroll));
        BOX2_MAIN_DeleteScroll((BoxTask *)task);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5B);
    }
    return 0x5A;
}

/*
 * Four-step machine on the work word at 0xA194 for releasing a Pokemon:
 * two confirmation messages, then the release itself (box slot in place,
 * party slot with a fade), then the view is restored.
 */
int BOX2_SEQ_StateReleaseMon(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_PrintMonName((BoxTask *)task, 1, 0x18);
        (((BoxTask *)(task))->state) = 0x5B;
        (((BoxTask *)(task))->work->seqStep)++;
        return 6;
    case 1:
        BOX2_SEQ_PrintMonName((BoxTask *)task, 2, 0x18);
        (((BoxTask *)(task))->state) = 0x5B;
        (((BoxTask *)(task))->work->seqStep)++;
        return 6;
    case 2:
        BOX2_MAIN_ClearSlot((char **)task, task->curBox, task->cursorSlot);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_MAIN_ResetBoxView(task);
        if (task->cursorSlot < 0x1E) {
            BOX2_UI_DrawSlot((BoxTask *)task, task->curBox);
            BOX2_UI_DrawSlotByName((char *)task, task->curBox);
            if ((((BoxTask *)(task))->params->mode) == 1) {
                (((BoxTask *)(task))->state) = 0x2C;
            } else {
                (((BoxTask *)(task))->state) = 0x11;
                BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot);
            BOX2_UI_SetCursorPos((char **)task, task->cursorSlot);
            BOX2_SEQ_SetCursorDraw((char **)task, 1);
            BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
            task->cursorSlot = 0xFF;
            (((BoxTask *)(task))->work->seqStep) = 0;
            return (((BoxTask *)(task))->state);
        }
        BOX2_SEQ_Create((void *)task);
        task->phase = 1;
        BOX2_SEQ_SetSlotActors((char *)task, 2, 0);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineOpen, 0x5B);
    case 3:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_SEQ_Delete(task);
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot - 0x1E);
        BOX2_UI_SetCursorPos((char **)task, task->cursorSlot - 0x1E);
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        task->cursorSlot = 0xFF;
        if ((((BoxTask *)(task))->params->mode) == 0)
            return 0x31;
        BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        return 0x1B;
    }
    return 0x5B;
}







int BOX2_SEQ_StateOpenZoom(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        if (BOX2_SEQ_GrowActor((((BoxTask *)(task))->work->scroll)) != 0)
            break;
        BOX2_SEQ_ResetActorTransform((int *)(((BoxTask *)(task))->work->scroll));
        BOX2_MAIN_DeleteScroll(task);
        BOX2_SEQ_RefreshCursorSlot(task);
        BOX2_SEQ_PrintMonName((BoxTask *)task, 4, 0x18);
        task->state = 0x5C;
        (((BoxTask *)(task))->work->seqStep)++;
        return 6;
    case 1:
        BOX2_SEQ_PrintMonName((BoxTask *)task, 5, 0x18);
        task->state = 0x5C;
        (((BoxTask *)(task))->work->seqStep)++;
        return 6;
    case 2:
        (((BoxTask *)(task))->work->seqStep) = 0;
        return BOX2_SEQ_StateUseItemDone((BoxTask *)task);
    }
    return 0x5C;
}

/*
 * Return r0 from BOX2_SEQ_GetActorDrawEnable and BOX2_SEQ_ResetEntryB is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int BOX2_SEQ_StateZoomMenu(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        (((BoxTask *)(task))->work->seqStep)++;
        BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(task))->work), 4, 0);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 0);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
        if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            if (BOX2_SEQ_GetActorDrawEnable((char *)((char *)((BoxTask *)(task))->work), 10) == 1)
                BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(task))->work), 10, 0);
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(task))->work), 24);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
            BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x5d);
        } else if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
            BOX2_UI_HideWindowA((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
            return BOX2_SEQ_ResetEntryB((BoxTask *)task, 0x5d);
        } else if (BOX2_UI_IsTopBarOpen((((BoxTask *)(task))->work->winMgr)) == 1) {
            BOX2_UI_HideWindowB((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
            BOX2_UI_OpenBar((((BoxTask *)(task))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowBusy, 0x5d);
        } else {
            BOX2_UI_HideWindowA((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
        }
    case 1:
        BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF908, 4);
        BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x5d);
    case 2:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_PrintIndexedMessage((unsigned char *)task, 0, 24);
        BOX2_UI_MoveCursor((char **)task, 10, 0);
        ((BoxTask *)task)->listState = 0;
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
        return 0x5e;
    }
    return 0x5d;
}

int BOX2_SEQ_StateClosePmVoice(BoxTask *task)
{
    unsigned v = CURSOR_MOVE_PollRepeatInput(task->work->cursorMove);
    switch (v) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x60));
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        task->work->selectKind = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, 0x67);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5f));
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5f));
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x5e));
    }
    return 0x5e;
}

int BOX2_SEQ_StateMoveMenu(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(task))->work), 24);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x5f);
    case 1:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 1);
        if (task->params->mode == 2) {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work));
            BOX2_UI_MoveCursor((char **)task, 3, 30);
            return 17;
        } else if (task->params->mode == 1) {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_MoveCursor((char **)task, 2, 30);
            return 44;
        } else if (task->params->mode == 3) {
            BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work));
            BOX2_UI_MoveCursor((char **)task, 7, 30);
            return 57;
        } else if (task->params->mode == 4) {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work));
            BOX2_UI_MoveCursor((char **)task, 13, 30);
            return 35;
        }
    }
    return 0x5f;
}

int BOX2_SEQ_StateMoveMenuB(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA17A) = 1;
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x60);
    case 1:
        task->prevBox = task->curBox;
        (((BoxTask *)(task))->work->seqStep)++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_RefreshBoxUiAndWait((char *)task, 0x60);
    case 2:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 1);
        BOX2_UI_MoveCursor((char **)task, 0xC, 1);
        *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = 1;
        BOX2_SEQ_PrintIndexedMessage((unsigned char *)task, 1, 0x19);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 1, 1);
        return 0x61;
    }
    return 0x60;
}
















/*
 * List input for the box menu: a touch pick stores the slot and leaves,
 * otherwise the list result selects a page, a jump, or a cancel.
 */
int BOX2_SEQ_StatePmVoiceMenu(BoxTask *task)
{
    unsigned x, y;
    unsigned r;

    if (BOX2_UI_GetExitButtonPoint(&x, &y) == 1) {
        *(unsigned *)(((char *)((BoxTask *)(task))->work) + 0xA184) = y;
        (((BoxTask *)(task))->state) = 0x61;
        BOX2_SEQ_CreateC(task);
        CURSOR_MOVE_SetState((((BoxTask *)(task))->work->cursorMove), 0);
        return 0xF;
    }
    r = CURSOR_MOVE_PollRepeatInput((((BoxTask *)(task))->work->cursorMove));
    switch (r) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)task, -1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxRight, 0x61);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)task, 1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxLeft, 0x61);
    case 1:
    case 2:
    case 3:
    case 4:
        (((BoxTask *)(task))->work->currentBox) = task->prevBox + r - 1;
        if ((((BoxTask *)(task))->work->currentBox) >= task->boxLimit)
            (((BoxTask *)(task))->work->currentBox) -= task->boxLimit;
        if ((((BoxTask *)(task))->work->currentBox) != task->curBox) {
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
            return BOX2_SEQ_DrawListSlot((BoxTask *)task, 1);
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, r - 1, 1);
        break;
    case 6:
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)task, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x62));
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x61));
    case (unsigned)-8:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_SelectBox((BoxTask *)task, -1);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxRight, 0x61);
        }
        break;
    case (unsigned)-7:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)) == 4) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_SelectBox((BoxTask *)task, 1);
            return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_OpenBoxLeft, 0x61);
        }
        break;
    }
    return 0x61;
}

/*
 * Return from BOX2_SEQ_ResetEntryB is used despite its legacy void declaration.
 */
int BOX2_SEQ_StatePmVoiceConfirm(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        *(u8 *)(((char *)((BoxTask *)(task))->work) + 0xA17A) = 0;
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(task))->work), 25);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
        BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_ResetEntryB((BoxTask *)task, 0x62);
    case 1:
        (((BoxTask *)(task))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
        BOX2_SEQ_SetWindow9((BoxTask *)task, 14, 1);
        if (task->params->mode == 2) {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work));
            BOX2_UI_MoveCursor((char **)task, 3, 30);
            return 17;
        } else if (task->params->mode == 1) {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_MoveCursor((char **)task, 2, 30);
            return 44;
        } else if (task->params->mode == 3) {
            BOX2_SEQ_SetSlotActors((char *)task, 0x81, 1);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work));
            BOX2_UI_MoveCursor((char **)task, 7, 30);
            return 57;
        } else if (task->params->mode == 4) {
            BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
            BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work));
            BOX2_UI_MoveCursor((char **)task, 13, 30);
            return 35;
        }
    }
    return 0x62;
}

int BOX2_SEQ_StateSetMiniIcon(BoxTask *task)
{
    BOX2_UI_SetMiniIconVisible((BoxTask *)task, CURSOR_MOVE_GetCurrent((struct Cursor *)(*(int *)(*(int *)&task->work + 0x70))) - 1, 1);
    return 0x61;
}

/*
 * Three-step machine on the work word at 0xA194 for the box-list menu:
 * fade out, open the menu for list kind 0xA17C (two kinds pick the long
 * menu when a save flag is set), then print the prompt and lock the list.
 */
int BOX2_SEQ_StateMoveMenuC(BoxTask *task)
{
    int flag;

    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(task);
        BOX2_UI_OpenListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x64);
    case 1:
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            if (BOX_SAVEDATA_CheckFlags((((BoxTask *)(task))->params->boxSave), 1) == 1)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9C8, 6);
            else
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF93C, 5);
        } else if ((((BoxTask *)(task))->work->selectKind) == 1) {
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF964, 5);
        } else if ((((BoxTask *)(task))->work->selectKind) == 2) {
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF978, 5);
        } else if ((((BoxTask *)(task))->work->selectKind) == 3) {
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF98C, 5);
        } else if ((((BoxTask *)(task))->work->selectKind) == 4) {
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9A0, 5);
        } else if ((((BoxTask *)(task))->work->selectKind) == 5) {
            if (BOX_SAVEDATA_CheckFlags((((BoxTask *)(task))->params->boxSave), 2) == 1)
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9E0, 6);
            else
                BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF928, 5);
        } else if ((((BoxTask *)(task))->work->selectKind) == 6) {
            BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9F8, 6);
        }
        BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
        (((BoxTask *)(task))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_IsWindowMoving, 0x64);
    case 2:
        (((BoxTask *)(task))->work->seqStep) = 0;
        if ((((BoxTask *)(task))->work->selectKind) == 0)
            BOX2_SEQ_PrintIndexedMessage((unsigned char *)task, 2, 0x18);
        else
            BOX2_SEQ_PrintIndexedMessage((unsigned char *)task, 3, 0x18);
        flag = 0;
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            if (BOX_SAVEDATA_CheckFlags((((BoxTask *)(task))->params->boxSave), 1) == 0)
                flag = 1;
        } else if ((((BoxTask *)(task))->work->selectKind) == 5) {
            if (BOX_SAVEDATA_CheckFlags((((BoxTask *)(task))->params->boxSave), 2) == 0)
                flag = 1;
        } else if ((((BoxTask *)(task))->work->selectKind) != 6) {
            flag = 1;
        }
        if (flag == 1) {
            BOX2_UI_MoveCursor((char **)task, 0xB, 1);
            CURSOR_MOVE_ClearSkipBit((((BoxTask *)(task))->work->cursorMove), 0);
        } else {
            BOX2_UI_MoveCursor((char **)task, 0xB, 0);
        }
        return 0x65;
    }
    return 0x64;
}

int BOX2_SEQ_StateClosePmVoiceB(BoxTask *task)
{
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70))) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            (((BoxTask *)(task))->work->selectKind) = 5;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 0, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)task, 0);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            (((BoxTask *)(task))->work->selectKind) = 1;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 1, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)task, 1);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            (((BoxTask *)(task))->work->selectKind) = 2;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)task, 2);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            (((BoxTask *)(task))->work->selectKind) = 3;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)task, 3);
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(task))->work->selectKind) == 0) {
            (((BoxTask *)(task))->work->selectKind) = 4;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        if ((((BoxTask *)(task))->work->selectKind) == 5 && BOX_SAVEDATA_CheckFlags(((void **)task->params)[1], 2) == 1) {
            (((BoxTask *)(task))->work->selectKind) = 6;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        if ((((BoxTask *)(task))->work->selectKind) == 6) {
            (((BoxTask *)(task))->work->selectKind) = 5;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)task, 4);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if ((((BoxTask *)(task))->work->selectKind) == 0)
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5F));
        (((BoxTask *)(task))->work->selectKind) = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
    case 0xFFFFFFFE:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if ((((BoxTask *)(task))->work->selectKind) == 0)
            return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x5F));
        (((BoxTask *)(task))->work->selectKind) = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)task, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 0x64));
    case 0xFFFFFFFD:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)task, BOX2_SEQ_SetState((BoxTask *)task, 0x65));
    }
    return 0x65;
}

















int BOX2_SEQ_StateFadeBox(BoxTask *task)
{
    switch ((((BoxTask *)(task))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
        PALANM_CopyHwPaletteToSlot(*(void **)(((char *)((BoxTask *)(task))->work) + 0x6c), 0, 0, 0x200);
        PALANM_RequestFade(*(void **)(((char *)((BoxTask *)(task))->work) + 0x6c), 1, 0xc000, 0, 0, 16, 0x7fff, (void *)GFL_USE_GetMainTaskList());
        task->state = 0x66;
        (((BoxTask *)(task))->work->seqStep)++;
        return 3;
    case 1:
        BOX2_MAIN_LoadBoxPalette((struct BoxTask *)task, *(u8 *)(((char *)((BoxTask *)(task))->work) + 0xA17B));
        BOX_SAVEDATA_SetWallpaper(task->params->boxSave, task->curBox, *(u8 *)(((char *)((BoxTask *)(task))->work) + 0xA17B));
        BOX2_UI_DrawSlot((BoxTask *)task, task->curBox);
        (((BoxTask *)(task))->work->seqStep)++;
        break;
    case 2:
        PALANM_RequestFade(*(void **)(((char *)((BoxTask *)(task))->work) + 0x6c), 1, 0xc000, 0, 16, 0, 0x7fff, (void *)GFL_USE_GetMainTaskList());
        task->state = 0x66;
        (((BoxTask *)(task))->work->seqStep)++;
        return 3;
    case 3:
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        (((BoxTask *)(task))->work->seqStep) = 0;
        return 0x65;
    }
    return 0x66;
}

int BOX2_SEQ_StateCloseItemE(unsigned char *task)
{
    return BOX2_SEQ_GotoBox2Ui((BoxTask *)task, 2);
}

void BOX2_SEQ_HideCursorSlot(u8 *task){BOX2_SEQ_SetActorDrawEnable(*(char * *)&((BoxTask *)task)->work,4,0);BOX2_SEQ_SetWindow9((BoxTask *)task,14,0);BOX2_SEQ_PrintMessageB((char *)task,24);BOX2_SEQ_DeleteSlotWindows((BoxTask *)task);BOX2_SEQ_OpenYesNo((BoxTask *)task,4);}

/*
 * Clear the pooled-offset word and return the argument.
 */
int BOX2_SEQ_ReturnAfterClear(BoxTask *task, int v)
{
    task->work->seqStep = 0;
    return v;
}

/*
 * Sibling of BOX2_SEQ_StartWipeBlack: the seven-argument setup call then
 * the state word at +0xA188 of the sub-object, return 2.
 */
int BOX2_SEQ_StartWipeWhite(void *task, int a)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4c);
    *(int *)((char *)((BoxTask *)task)->work + 0xA188) = a;
    return 2;
}

/*
 * Same body as BOX2_SEQ_StartWipeWhite with the first four arguments zero;
 * the state word goes to +0xA188, return 2.
 */
int BOX2_SEQ_StartWipeBlack(void *task, int a)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x4c);
    *(int *)((char *)((BoxTask *)task)->work + 0xA188) = a;
    return 2;
}

/*
 * Store the third argument, then reset the sub-object.
 */
int BOX2_SEQ_SetSeqThird(BoxTask *task, int a, int b)
{
    *(int *)(*(int *)&task->work + 0x68) = b;
    BOX2_MAIN_InitSeq((struct BoxWork *)(*(char * *)&task->work), a);
    return 5;
}

/*
 * Store the second argument, then re-seat the sub-object.
 */
int BOX2_SEQ_SetSeqSecond(BoxTask *task, int a)
{
    *(int *)(*(int *)&task->work + 0x68) = a;
    BOX2_MAIN_RestartSeq((struct BoxWork *)(*(char * *)&task->work));
    return 5;
}

/*
 * Store v at +0x28, return 13.
 */
int BOX2_SEQ_SetState(BoxTask *task, int v)
{
    task->state = v;
    return 0xd;
}





/*
 * Opens the yes/no menu with the cursor on sel and enters state 7.
 */
int BOX2_SEQ_OpenYesNo(BoxTask *task, int sel)
{
    *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0x1A4) = sel;
    if (sel == 1)
        BOX2_MAIN_OpenTaskMenu((BoxTask *)task, 1);
    else
        BOX2_MAIN_OpenTaskMenu((BoxTask *)task, 0);
    KEY_SetRepeatSpeed(*(unsigned *)(((char *)((BoxTask *)(task))->work) + 0x4C), *(unsigned *)(((char *)((BoxTask *)(task))->work) + 0x50));
    return 7;
}











int BOX2_SEQ_StateUseItem(BoxTask *task)
{
    unsigned item;
    void *mon;
    item = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    if (MYITEM_SAVEDATA_AddItem(task->params->config, item, 1, 0x4C) == 1) {
        mon = (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot);
        BOX2_SEQ_PrintWordsetB((char *)task, item, 0x18);
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task, task->cursorSlot, task->curBox, 6, 0);
        if (BOX2_MAIN_SyncItemForm((void **)task, mon) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)task, task->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, task->cursorSlot, *(unsigned char *)(((char *)((BoxTask *)(task))->work) + task->cursorSlot + 0x3DD2));
        }
        BOX2_MAIN_SetBoxForm((BoxTask *)task, task->cursorSlot);
    } else {
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintMessageD((char *)task, 0x18);
    }
    if (UI_GetInputMode() == 1) {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 0);
    } else {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 1);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
    }
    task->state = 0xE;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, 6);
}











int BOX2_SEQ_StateUseItemWait(BoxTask *task)
{
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(task);
    BOX2_MAIN_ResetMovers((BoxTask *)task);
    BOX2_SEQ_ResetActorAffine(*(char **)(((char *)((BoxTask *)(task))->work) + 0xA190));
    if (UI_GetInputMode() == 1) {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 0);
    } else {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 1);
        BOX2_SEQ_SetCursorDraw((char **)task, 0);
    }
    return 0x5A;
}











int BOX2_SEQ_StateUseItemDone(BoxTask *task) {
 BOX2_SEQ_SetSlotDim((char **)task,1); BOX2_SEQ_HideWindowObject(((char *)((BoxTask *)(task))->work),0x18); BOX2_MAIN_RefreshCursorBox(task);
 if(task->cursorSlot<0x1E) { BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetSlotActors((char *)task,1,0); }
 else BOX2_SEQ_SetSlotActors((char *)task,2,0);
 if(UI_GetInputMode()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),0);
 else { CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),1); BOX2_SEQ_SetCursorDraw((char **)task,0); }
 return BOX2_SEQ_SetSeqThird((BoxTask *)task,(sptr)BOX2_MAIN_IsWindowMoving,BOX2_SEQ_ReturnAfterClear((BoxTask *)task,0xE));
}











int BOX2_SEQ_StateUseItemMenu(BoxTask *task)
{
    void *mon;
    if(UI_GetInputMode()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),0);
    else { CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),1); BOX2_SEQ_SetCursorDraw((char **)task,0); }
    if(MYITEM_SAVEDATA_AddItem(task->params->config,*(unsigned short *)(((char *)((BoxTask *)(task))->work)+0xa16c),1,0x4c)==1) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)task,task->curBox,task->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task,task->cursorSlot,task->curBox,6,0);
        if(BOX2_MAIN_SyncItemForm((void **)task,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void **)task,task->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task,task->curBox,task->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(task))->work)+task->cursorSlot+0x3dd2));
        }
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_SEQ_SetSlotDim((char **)task,0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work),0x18); BOX2_MAIN_RefreshCursorBox(task); BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work),0xa,2);
        return 0x3b;
    }
    GFL_USE_PlaySeDefaultVolume(0x557); BOX2_SEQ_PrintPromptB((BoxTask *)task,6,0x18);
    task->state=0xe;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)task,6);
}

/*
 * Set the id, re-key the queue, store 0x69 as the frame, then
 *   arm the flag.
 */
int BOX2_SEQ_StateExitBoxWithSe(BoxTask *task)
{
    GFL_USE_PlaySeDefaultVolume(0x55D);
    BOX2_MAIN_ClearPerapVoiceIfNoChatot((int *)task);
    task->state = 0x69;
    return BOX2_SEQ_StartWipeBlack((void *)task, 1);
}











/*
 * trailing extent: two-byte zero alignment at 021E93F2.
 */
int BOX2_SEQ_StateCloseItemMenu(BoxTask *task)
{
    BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(task))->work),0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    if(UI_GetInputMode()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),0);
    else CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),1);
    BOX2_SEQ_SetWindow9((BoxTask *)task,0xe,1);
    switch(task->params->mode) {
    case 0: BOX2_SEQ_SetSlotActors((char *)task,2,0); return 0x31;
    case 1: BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetSlotActors((char *)task,1,0); return 0x2c;
    case 2:
        if(BOX2_UI_IsTopBarClosed(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)task,2,0); BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); return 0x1b;
        }
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetSlotActors((char *)task,1,0); BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); return 0x11;
    case 3:
        if(BOX2_UI_IsTopBarClosed(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)task,0x82,0); BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); return 0x46;
        }
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetSlotActors((char *)task,0x81,0); BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); return 0x39;
    case 4:
        if(BOX2_UI_IsTopBarClosed(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)task,2,0); BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); return 0x27;
        }
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetSlotActors((char *)task,1,0); BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); return 0x23;
    case 5: BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),1); BOX2_SEQ_SetSlotActors((char *)task,0x81,1); return 0x4b;
    }
    return 0x11;
}

/*
 * candidate BOX2_SEQ_SaveMenuPosAndExit: copy two bytes into a sub object
 */
void BOX2_SEQ_SaveMenuPosAndExit(BoxTask *task)
{
    BOX2_MAIN_ClearPerapVoiceIfNoChatot((int *)((sptr)task));
    task->params->savedBox = task->curBox;
    task->params->savedSlot = task->cursorSlot;
    task->state = 0x69;
    BOX2_SEQ_StartWipeBlack((void *)((sptr)task), 1);
}











int BOX2_SEQ_StatePmVoiceClose(BoxTask *task) {
 BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work),0x1B); BOX2_MAIN_RefreshCursorBox(task);
 CURSOR_MOVE_SetCurrent(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),task->cursorSlot);
 BOX2_SEQ_SetSlotActors((char *)task,0x81,1); BOX2_SEQ_SetSlotDim((char **)task,0);
 if(UI_GetInputMode()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),0);
 else CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),1);
 return 0x4B;
}

void BOX2_SEQ_StateEnterItemMenu(unsigned char *task){if(UI_GetInputMode()==1)CURSOR_MOVE_SetState(((BoxTask *)task)->work->cursorMove,0);else {CURSOR_MOVE_SetState(((BoxTask *)task)->work->cursorMove,1);BOX2_SEQ_SetCursorDraw((char **)task,0);}BOX2_SEQ_StateItemMenu((BoxTask *)task);}

/*
 * Forward, then store the third argument at 0x28.
 */
int BOX2_SEQ_GotoBox2Main(BoxTask *task, int a, int b)
{
    BOX2_MAIN_SetupWindowFrameFade((struct BoxTask *)task, a);
    task->state = b;
    return 8;
}

int BOX2_SEQ_SetupFrameFadeAndWait(BoxTask *task,int a,int b) {
 ((BoxWorkView *)(char *)task->work)->flag=1;
 ((BoxWorkView *)(char *)task->work)->id=BGWINFRM_GetBgFrame(*(struct BgWinFrmWork * *)&task->work->winMgr,7);
 ((BoxWorkView *)(char *)task->work)->lo=13;
 ((BoxWorkView *)(char *)task->work)->hi=12;
 ((BoxWorkView *)(char *)task->work)->state=0;
 ((BoxWorkView *)(char *)task->work)->count=0;
 if(a==0) ((BoxWorkView *)(char *)task->work)->y=14;
 else ((BoxWorkView *)(char *)task->work)->y=17;
 ((BoxWorkView *)(char *)task->work)->x=21;
 ((BoxWorkView *)(char *)task->work)->w=11;
 ((BoxWorkView *)(char *)task->work)->h=3;
 task->state=b;
 return 8;
}










int BOX2_SEQ_GotoBox2MainWithSlot(BoxTask *task, int id, int lo, int arg)
{
    ((BoxWorkView *)(char *)task->work)->flag = 0;
    ((BoxWorkView *)(char *)task->work)->id = (unsigned char)id;
    ((BoxWorkView *)(char *)task->work)->lo = (unsigned char)lo;
    ((BoxWorkView *)(char *)task->work)->hi = 0;
    ((BoxWorkView *)(char *)task->work)->state = 0;
    ((BoxWorkView *)(char *)task->work)->count = 0;
    ((BoxWorkView *)(char *)task->work)->x = 0;
    ((BoxWorkView *)(char *)task->work)->y = 0;
    ((BoxWorkView *)(char *)task->work)->w = 0;
    ((BoxWorkView *)(char *)task->work)->h = 0;
    task->state = arg;
    return 8;
}

/*
 * Enters state 9 with reason v.
 */
int BOX2_SEQ_GotoBox2Ui(BoxTask *task, unsigned char v)
{
    if (CURSOR_MOVE_GetState(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70)) == 1)
        UI_SetInputMode(0);
    else
        UI_SetInputMode(1);
    task->state = 9;
    task->pad_12 = v;
    return BOX2_SEQ_StartWipeBlack((void *)task, 1);
}









int BOX2_SEQ_StatePmVoiceMenuB(BoxTask *task)
{
    int next;
    void *mon;
    switch(task->menuMode) {
    case 0: BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); next=0x11; break;
    case 1:
        BOX2_SEQ_StopLeftBar((sptr)task); BOX2_SEQ_SetSlotActors((char *)task,1,1); BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
        BOX2_UI_MoveCursor((char **)task,5,0xb); BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); next=0x1b; break;
    }
    BOX2_SEQ_RefreshCursorSlot(task);
    if((((BoxTask *)(task))->subResult)==0) {
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_SEQ_DrawFrameList((BoxTask *)task, data_021EFA10, 6);
        BOX2_UI_PutListFrames(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74)); BOX2_SEQ_PrintPrompt((BoxTask *)task,task->cursorSlot,1,0x18);
        return next;
    }
    if(FILE_UTIL_IsMailItem((((BoxTask *)(task))->subResult))==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)task,task->curBox,task->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task,task->cursorSlot,task->curBox,6,(((BoxTask *)(task))->subResult));
        if(BOX2_MAIN_SyncItemForm((void **)task,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void * *)task, task->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task,task->curBox,task->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(task))->work)+task->cursorSlot+0x3dd2));
        }
        MYITEM_SAVEDATA_RemoveItem(task->params->config,(((BoxTask *)(task))->subResult),1,0x804c);
    }
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_SEQ_SetCursorDraw((char **)task,0);
    return 0x54;
}








int BOX2_SEQ_StatePmVoiceMenuC(BoxTask *task)
{
    int next;
    void *mon;
    switch(task->menuMode) {
    case 0: BOX2_SEQ_MoveActorToSlot((char *)((char *)((BoxTask *)(task))->work),task->cursorSlot,0); next=0x39; break;
    case 1:
        BOX2_SEQ_StopLeftBar((sptr)task); BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
        BOX2_SEQ_MoveActorToSlot((char *)((char *)((BoxTask *)(task))->work),task->cursorSlot,1); BOX2_UI_MoveCursor((char **)task,8,0xa); next=0x46; break;
    }
    BOX2_SEQ_SetActorAnim((BoxTask *)task,*(short *)&task->subResult);
    if((((BoxTask *)(task))->subResult)==0) {
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_UI_PutListFrames(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74));
        BOX2_SEQ_PrintPromptB((BoxTask *)task,0,0x18);
        if(task->menuMode==0) BOX2_SEQ_SetSlotActors((char *)task,0x81,1);
        else { BOX2_SEQ_SetSlotActors((char *)task,1,1); BOX2_SEQ_SetSlotActors((char *)task,0x82,1); }
        return next;
    }
    if(FILE_UTIL_IsMailItem((((BoxTask *)(task))->subResult))==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)task,task->curBox,task->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task,task->cursorSlot,task->curBox,6,(((BoxTask *)(task))->subResult));
        if(BOX2_MAIN_SyncItemForm((void **)task,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void **)task,task->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task,task->curBox,task->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(task))->work)+task->cursorSlot+0x3dd2));
        }
        MYITEM_SAVEDATA_RemoveItem(task->params->config,(((BoxTask *)(task))->subResult),1,0x804c);
        *(unsigned short *)(((char *)((BoxTask *)(task))->work)+0xa16c)=(((BoxTask *)(task))->subResult);
        BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(task))->work),*(unsigned short *)(((char *)((BoxTask *)(task))->work)+0xa16c));
        BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(task))->work),0xa,1); BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(task))->work)); BOX2_SEQ_ShowHandSlots((char *)((char *)((BoxTask *)(task))->work));
    }
    if(task->menuMode==0) { BOX2_SEQ_SetSlotActors((char *)task,0x81,1); BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); }
    else { BOX2_SEQ_SetSlotActors((char *)task,1,1); BOX2_SEQ_SetSlotActors((char *)task,0x82,1); BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); }
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_SEQ_SetCursorDraw((char **)task,0);
    return 0x54;
}







int BOX2_SEQ_StatePmVoiceMenuD(BoxTask *task)
{
    int next;
    void *mon;
    switch(task->menuMode) {
    case 0: BOX2_UI_ShowWindowA((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); next=0x23; break;
    case 1:
        BOX2_SEQ_StopLeftBar((sptr)task); BOX2_SEQ_SetSlotActors((char *)task,1,1); BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
        BOX2_UI_MoveCursor((char **)task,0xe,0xb); BOX2_UI_ShowWindowB((struct BoxWork *)(char *)((char *)((BoxTask *)(task))->work)); next=0x27; break;
    }
    BOX2_SEQ_RefreshCursorSlot(task);
    if((((BoxTask *)(task))->subResult)==0) {
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_SEQ_DrawFrameList((BoxTask *)task, data_021EF918, 4);
        BOX2_UI_PutListFrames(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74)); BOX2_SEQ_PrintPrompt((BoxTask *)task,task->cursorSlot,1,0x18);
        return next;
    }
    if(FILE_UTIL_IsMailItem((((BoxTask *)(task))->subResult))==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)task,task->curBox,task->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((struct BoxTask *)(sptr)task,task->cursorSlot,task->curBox,6,(((BoxTask *)(task))->subResult));
        if(BOX2_MAIN_SyncItemForm((void **)task,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void * *)task, task->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task,task->curBox,task->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(task))->work)+task->cursorSlot+0x3dd2));
        }
        MYITEM_SAVEDATA_RemoveItem(task->params->config,(((BoxTask *)(task))->subResult),1,0x804c);
    }
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,task->cursorSlot); BOX2_SEQ_SetCursorDraw((char **)task,0);
    return 0x54;
}










int BOX2_SEQ_StatePmVoiceOpen(unsigned char *task){BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF9B4, 5);BOX2_UI_PutListFrames((struct BgWinFrmWork *)(((BoxTask *)task)->work->winMgr));BOX2_SEQ_PrintPrompt((BoxTask *)task,task[22],1,24);BOX2_SEQ_RefreshCursorSlot((BoxTask *)task);return 44;}

int BOX2_SEQ_StatePmVoiceOpenB(BoxTask *task) {
 BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF950, 5);
 BOX2_UI_PutListFrames((struct BgWinFrmWork *)((sptr)(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74))));
 BOX2_SEQ_PrintPrompt((BoxTask *)task,task->cursorSlot,1,0x18);
 BOX2_SEQ_SetSlotActors((char *)task,1,1); BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
 BOX2_SEQ_StopLeftBar((sptr)task); BOX2_SEQ_RefreshCursorSlot((BoxTask *)task); return 0x31;
}















/*
 * Leaves a box-menu mode (p[0x13]): restores the windows the mode changed
 * and returns the next menu state.
 */
int BOX2_SEQ_StatePmVoiceOpenC(BoxTask *task)
{
    switch (task->menuMode) {
    case 0:
        BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
        BOX2_UI_PutListFrames((struct BgWinFrmWork *)((sptr)((((BoxTask *)(task))->work->winMgr))));
        BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
        BOX2_SEQ_RefreshCursorSlot((BoxTask *)task);
        return 0x11;
    case 1:
        BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EFA10, 6);
        BOX2_UI_PutListFrames((struct BgWinFrmWork *)((sptr)((((BoxTask *)(task))->work->winMgr))));
        BOX2_SEQ_PrintPrompt((BoxTask *)task, task->cursorSlot, 1, 0x18);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work), 0);
        BOX2_UI_MoveCursor((char **)task, 5, 10);
        BOX2_SEQ_StopLeftBar((sptr)task);
        BOX2_SEQ_RefreshCursorSlot((BoxTask *)task);
        return 0x1B;
    case 2:
        if (task->barOpenFlag == 1)
            BOX2_SEQ_HideSlotsC61C((BoxTask *)task);
        BOX2_UI_MoveCursor((char **)task, 4, task->cursorSlot);
        BOX2_MAIN_RefreshBoxUi(task);
        while (BOX2_MAIN_ShiftWindowRight(task) != 0)
            ;
        BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        task->cursorSlot = 0xFF;
        return 0x15;
    case 3:
        if (task->cursorSlot >= 0x1E) {
            BOX2_SEQ_HideSlotsC61C((BoxTask *)task);
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
        } else if (task->curBox == task->heldSlot) {
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
        } else {
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->heldSlot, task->cursorSlot, (((BoxTask *)(task))->work->cursorActorId));
        }
        BOX2_MAIN_SceneMoveCursor((BoxTask *)task);
        BOX2_SEQ_SetSlotDimB((char **)task, 0x24);
        BOX2_UI_MoveCursor((char **)task, 4, task->listCursorId);
        BOX2_MAIN_RefreshBoxUi(task);
        while (BOX2_MAIN_ShiftWindowRight(task) != 0)
            ;
        BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        if (task->listCursorId >= 0x22 && task->listCursorId <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)task, task->listCursorId - 0x22, 1);
        BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
        return 0x15;
    case 4:
        BOX2_SEQ_StopRightBar((sptr)task);
        BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        task->cursorSlot = 0xFF;
        return 0x20;
    case 5:
        BOX2_SEQ_StopRightBar((sptr)task);
        if (task->cursorSlot < 0x1E && task->curBox != task->heldSlot)
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->heldSlot, task->cursorSlot, (((BoxTask *)(task))->work->cursorActorId));
        else
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
        BOX2_MAIN_SceneMoveCursor((BoxTask *)task);
        BOX2_SEQ_SetSlotDimB((char **)task, 0x24);
        BOX2_UI_MoveCursor((char **)task, 6, task->listCursorId);
        BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
        BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
        return 0x20;
    }
    return 0;
}
















int BOX2_SEQ_StatePmVoiceOpenD(BoxTask *task)
{
    switch(task->menuMode) {
    case 0:
        BOX2_SEQ_DrawFrameList((BoxTask *)task, data_021EF918, 4);
        BOX2_UI_PutListFrames((struct BgWinFrmWork *)((sptr)(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74)))); BOX2_SEQ_PrintPrompt((BoxTask *)task,task->cursorSlot,1,0x18);
        BOX2_UI_MoveCursor((char **)task,0xd,0x25); BOX2_SEQ_RefreshCursorSlot((BoxTask *)task); return 0x23;
    case 1:
        BOX2_SEQ_DrawFrameList((BoxTask *)task, data_021EF918, 4);
        BOX2_UI_PutListFrames((struct BgWinFrmWork *)((sptr)(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74)))); BOX2_SEQ_PrintPrompt((BoxTask *)task,task->cursorSlot,1,0x18);
        BOX2_SEQ_SetSlotActors((char *)task,1,1); BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
        BOX2_UI_MoveCursor((char **)task,0xe,0xa); BOX2_SEQ_StopLeftBar((sptr)task); BOX2_SEQ_RefreshCursorSlot((BoxTask *)task); return 0x27;
    case 4:
        BOX2_SEQ_StopRightBar((sptr)task); BOX2_UI_MoveCursor((char **)task,6,task->cursorSlot);
        CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),0x27);
        task->cursorSlot=0xff; return 0x20;
    case 5:
        BOX2_SEQ_StopRightBar((sptr)task);
        if(task->cursorSlot<0x1e && task->curBox!=task->heldSlot)
            BOX2_SEQ_ShowSlotIcon((BoxTask *)task,task->heldSlot,task->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(task))->work)+0x3df6));
        else BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work),task->cursorSlot);
        BOX2_MAIN_SceneMoveCursor((BoxTask *)task); BOX2_SEQ_SetSlotDimB((char **)task,0x24);
        BOX2_UI_MoveCursor((char **)task,6,task->listCursorId); CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(task))->work)+0x70),0x27);
        BOX2_SEQ_MoveCursorActor((BoxTask *)task,0x24); return 0x20;
    }
    return 0;
}
















int BOX2_SEQ_GotoRightPanelA(BoxTask *task, int a, int n)
{
    BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 0);
    if (BOX2_UI_IsListOpen(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74)) == 1) {
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
        if (a == 1)
            BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StepScrollToPrevBox, n);
}














int BOX2_SEQ_GotoRightPanelB(BoxTask *task, int a, int n)
{
    BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 1);
    if (BOX2_UI_IsListOpen(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74)) == 1) {
        BOX2_UI_OpenListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
        if (a == 1)
            BOX2_UI_ShowWindowA((struct BoxWork *)((char *)((BoxTask *)(task))->work));
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StepScrollToNextBox, n);
}

int BOX2_SEQ_SelectSlotA(BoxTask *task, int i)
{
    task->barOpenFlag = 0;
    task->listState = 0;
    task->cursorSlot = i;
    task->heldSlot = task->curBox;
    BOX2_SEQ_SetSlotDrawPriority((char *)task->work, task->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors((char *)task->work, task->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_SEQ_Create((void *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowA((struct BoxWork *)(char *)task->work);
    task->state = 0x15;
    task->phase = 0;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineScroll, 0x12);
}

int BOX2_SEQ_SelectSlotB(BoxTask *task, int i)
{
    task->cursorSlot = i;
    task->heldSlot = task->curBox;
    task->barOpenFlag = 0;
    BOX2_SEQ_SetSlotDrawPriority((char *)task->work, task->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors((char *)task->work, task->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_SEQ_Create((void *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    task->phase = 0;
    task->state = 0x20;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_StateMachineScroll, 0x24);
}

int BOX2_SEQ_SelectSlotC(BoxTask *task, int a)
{
    u8 old = task->curBox;
    task->cursorSlot = a;
    task->heldSlot = old;
    BOX2_SEQ_SetSlotDrawPriority((char *)(*(u32 *)&task->work), task->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors((char *)(*(u32 *)&task->work), task->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_UI_ToggleSlotPair((struct BoxWork *)(char *)(*(u32 *)&task->work), 0);
    BOX2_SEQ_HideSlotsC61C((BoxTask *)task);
    BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
    BOX2_SEQ_SetSlotActors((char *)task, 2, 1);
    BOX2_SEQ_SetSlotActorMode((char *)(*(u32 *)&task->work), 0x24, 0);
    BOX2_SEQ_Create((void *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)(*(u32 *)&task->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    task->phase = 2;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)((void (*)(void))BOX2_MAIN_StateMachinePen), 0x30);
}

int BOX2_SEQ_GotoSlotHandlerA(BoxTask *task, int i, int v)
{
    task->cursorSlot = i;
    *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA172) = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), (unsigned char)task->cursorSlot, 1);
    BOX2_SEQ_RefreshCursorSlot((BoxTask *)task);
    BOX2_UI_CloseListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)task, v));
}

int BOX2_SEQ_SelectPartySlotA(unsigned char *task, int i)
{
    task[0x16] = i;
    ((BoxTask *)task)->listState = 0;
    task[0x17] = task[0x14];
    task[0x1B] = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), task[0x16], 0);
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task[0x16]);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    POKEPARTY_GetMember(((BoxTask *)task)->params->party, i - 0x1E);
    BOX2_SEQ_Create((void *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    BOX2_UI_ShowWindowB((struct BoxWork *)((char *)((BoxTask *)(task))->work));
    ((BoxTask *)task)->state = 0x20;
    task[0x1A] = 1;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachinePick, 0x1E);
}

int BOX2_SEQ_SelectPartySlotB(BoxTask *task, int i)
{
    task->heldSlot = task->curBox;
    task->cursorSlot = i;
    task->barOpenFlag = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    POKEPARTY_GetMember(task->params->party, i - 0x1E);
    BOX2_SEQ_Create((void *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(task);
    task->state = 0x20;
    task->phase = 1;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachinePick, 0x2A);
}

int BOX2_SEQ_SelectPartySlotC(BoxTask *task, int i)
{
    task->cursorSlot = i;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), task->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_SEQ_SetSlotActors((char *)task, 2, 1);
    BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(task))->work), 0x24, 0);
    POKEPARTY_GetMember(task->params->party, i - 0x1E);
    BOX2_SEQ_Create((void *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(task))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(task);
    task->phase = 1;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineMove, 0x38);
}

int BOX2_SEQ_GotoSlotHandlerB(BoxTask *task, int i, int v)
{
    task->cursorSlot = i;
    *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA172) = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), (unsigned char)task->cursorSlot, 1);
    BOX2_SEQ_RefreshCursorSlot((BoxTask *)task);
    BOX2_UI_CloseListPack(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work) + 0x74));
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)task, v));
}

int BOX2_SEQ_SelectSlotD(BoxTask *task, int i, int v)
{
    task->heldSlot = task->curBox;
    task->cursorSlot = i;
    *(int *)(((char *)((BoxTask *)(task))->work) + 0xA168) = i;
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(task))->work), task->cursorSlot);
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 2);
    BOX2_SEQ_Create((void *)task);
    task->state = v;
    task->phase = 2;
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineScroll, 0x17);
}













int BOX2_SEQ_HideSlotWindow(BoxTask *task, unsigned char i)
{
    task->handMode = 1;
    task->cursorSlot = i;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 0);
    if (task->params->mode == 4) {
        BOX2_UI_HideWindowA((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
        BOX2_UI_HideWindowB((struct BoxWork *)(((char *)((BoxTask *)(task))->work)));
        CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(task))->work) + 0x70), 0x27);
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneWaitCursor, 0x20);
}

/*
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */
int BOX2_SEQ_SelectBoxSlot(BoxTask *task, int a)
{
    task->handMode = 1;
    task->cursorSlot = a;
    BOX2_SEQ_SetSlotDrawPriority((char *)(*(int *)&task->work), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 0);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x021E0779, 0x15);
}

int BOX2_SEQ_ScrollListToSlot(BoxTask *task, unsigned i, int v)
{
    if (i >= 0x1E && i >= 0x24 && i != 0xFF) {
        unsigned k = task->prevBox + i - 0x24;
        if (k >= task->boxLimit)
            k -= task->boxLimit;
        if (k == task->curBox) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            return 0x15;
        }
        if (BOX_SAVEDATA_CountFreeSlotsInBox(task->params->boxSave, k) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            return 0x15;
        }
    }
    task->work->targetBox = i;
    task->phase = 2;
    task->state = v;
    BOX2_SEQ_Create((void *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_SceneOpenBox, 0x17);
}

/*
 * Allocate (0x4c, 0xb8, 1) into the 0x021F140C buffer and store
 * the handle at sub-object +0x60.
 */
void BOX2_SEQ_Create(void *task)
{
    int v = (sptr)GFL_HEAP_Alloc(0x4c, 0xb8, 1, (const char *)0x021F140C, 0x2130);
    *(int *)((char *)((BoxTask *)task)->work + 0x60) = v;
}

/*
 * Tail call GFL_HEAP_Free with the word at +0x2c/+0x60.
 */
void BOX2_SEQ_Delete(BoxTask *task)
{
    GFL_HEAP_Free(task->work->seq.entry);
}












int BOX2_SEQ_DrawGridSlot(BoxTask *task, int i)
{
    short t[2];
    task->cursorSlot = i;
    task->heldSlot = task->curBox;
    task->work->cancelFlag = 1;
    (((BoxTask *)(task))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    BOX2_UI_ResetSlotFrames((((BoxTask *)(task))->work->winMgr));
    BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    if ((((BoxTask *)(task))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)task->work, task->cursorSlot, 0);
        BOX2_SEQ_SetSlotCharacter((char *)task->work, (((BoxTask *)(task))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)task->work);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    } else if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
    }
    BOX2_SEQ_GetSlotPos(task->cursorSlot, &t[1], &t[0], 0);
    *(int *)((char *)task->work + 0xA180) = t[1] + 8;
    *(int *)((char *)task->work + 0xA184) = t[0] + 8;
    BOX2_SEQ_CreateB((void *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineDrag, BOX2_SEQ_SetState((BoxTask *)task, 0x3E));
}

int BOX2_SEQ_SetCursorMove(BoxTask *task, int i)
{
    task->cursorSlot = i;
    task->heldSlot = task->curBox;
    task->work->cancelFlag = 1;
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
    (((BoxTask *)(task))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    BOX2_SEQ_SetActorAnim((BoxTask *)task, (short)(((BoxTask *)(task))->work->counter));
    BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
    if ((((BoxTask *)(task))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)task->work, task->cursorSlot, 0);
        BOX2_SEQ_SetSlotCharacter((char *)task->work, (((BoxTask *)(task))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)task->work);
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 0x24, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x24);
    } else {
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 0x25, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 0x25);
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineShowHandScroll, BOX2_SEQ_SetState((BoxTask *)task, 0x39));
}










int BOX2_SEQ_SelectGridSlot(BoxTask *task, unsigned i)
{
    short t[2];
    task->cursorSlot = i;
    task->heldSlot = i < 0x1E ? task->curBox : 0xFF;
    (((BoxTask *)(task))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    if ((((BoxTask *)(task))->work->counter) == 0) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), task->cursorSlot);
        return 0x40;
    }
    GFL_USE_PlaySeDefaultVolume(0x666);
    BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
    BOX2_SEQ_MoveActorToSlot((char *)task->work, task->cursorSlot, 2);
    BOX2_SEQ_SetSlotCharacter((char *)task->work, (((BoxTask *)(task))->work->counter));
    BOX2_SEQ_CreateHandSlotActorsB((char *)task->work);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 1);
    BOX2_SEQ_GetSlotPos(task->cursorSlot, &t[1], &t[0], 2);
    *(int *)((char *)task->work + 0xA180) = t[1] + 8;
    *(int *)((char *)task->work + 0xA184) = t[0] + 8;
    BOX2_SEQ_CreateB((void *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineDragNoBar, 0x42);
}

int BOX2_SEQ_DrawGridSlotB(BoxTask *task, unsigned i)
{
    task->cursorSlot = i;
    *(unsigned short *)((char *)task->work + 0xA16E) = i;
    task->heldSlot = i < 0x1E ? task->curBox : 0xFF;
    (((BoxTask *)(task))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    if ((((BoxTask *)(task))->work->counter) == 0)
        return 0x40;
    task->handMode = 1;
    BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
    BOX2_SEQ_MoveActorToSlotB((char *)task->work, task->cursorSlot, 2);
    BOX2_SEQ_SetSlotCharacter((char *)task->work, (((BoxTask *)(task))->work->counter));
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 1);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_StateMenuSelect, 0x40);
}

int BOX2_SEQ_UpdateGridCursor(BoxTask *task)
{
    unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove));
    if (v < 0x24)
        BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, v);
    else
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
    BOX2_SEQ_CreateB((void *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_StateMenuMain, 0x43);
}










int BOX2_SEQ_MoveGridCursor(BoxTask *task, unsigned i)
{
    short t[2];
    (((BoxTask *)(task))->work->targetBox) = i;
    task->handMode = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)task->work, 4, &t[1], &t[0], 0);
    BOX2_SEQ_AddActorSurfacePos((char *)task->work, 10, (short)t[1], (short)(t[0] + 8), (short)0);
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    if ((((BoxTask *)(task))->work->targetBox) == 0xFF)
        return BOX2_SEQ_UpdateGridCursor((BoxTask *)task);
    if (BOX2_MAIN_CompareSlots((unsigned char *)task, task->cursorSlot, i) == 0)
        return BOX2_SEQ_UpdateGridCursor((BoxTask *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_StateMenuSwap, 0x45);
}

int BOX2_SEQ_DeleteGridSlot(BoxTask *task, int i)
{
    short t[2];
    task->cursorSlot = i;
    task->heldSlot = 0xFF;
    (((BoxTask *)(task))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    BOX2_UI_ResetSlotFrames((((BoxTask *)(task))->work->winMgr));
    BOX2_SEQ_ShowWindowObject((char *)task->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)task);
    if ((((BoxTask *)(task))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)task->work, task->cursorSlot, 1);
        BOX2_SEQ_SetSlotCharacter((char *)task->work, (((BoxTask *)(task))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)task->work);
        BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
    } else if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
    }
    BOX2_SEQ_GetSlotPos(task->cursorSlot, &t[1], &t[0], 1);
    *(int *)((char *)task->work + 0xA180) = t[1] + 8;
    *(int *)((char *)task->work + 0xA184) = t[0] + 8;
    BOX2_SEQ_CreateB((void *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_SEQ_StateMachineMove, 0x48);
}









int BOX2_SEQ_SetCursorMoveB(BoxTask *task, int i)
{
    task->cursorSlot = i;
    task->heldSlot = task->curBox;
    task->work->cancelFlag = 1;
    BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task, task->cursorSlot);
    (((BoxTask *)(task))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)task, task->cursorSlot, task->curBox, 6, 0);
    BOX2_SEQ_SetActorAnim((BoxTask *)task, (short)(((BoxTask *)(task))->work->counter));
    BOX2_UI_CloseListPack((((BoxTask *)(task))->work->winMgr));
    if ((((BoxTask *)(task))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)task->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)task->work, task->cursorSlot, 1);
        BOX2_SEQ_SetSlotCharacter((char *)task->work, (((BoxTask *)(task))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)task->work);
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 9, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 9);
    } else {
        BOX2_UI_MoveCursorBetweenIcons((struct BoxWork *)task->work, 10, CURSOR_MOVE_GetCurrent((((BoxTask *)(task))->work->cursorMove)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(task))->work->cursorMove), 10);
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)BOX2_MAIN_StateMachineShowHandScroll, BOX2_SEQ_SetState((BoxTask *)task, 0x46));
}

/*
 * Sibling of BOX2_SEQ_Create with (0x1c, 0) and the 0x228F buffer.
 */
void BOX2_SEQ_CreateB(void *task)
{
    int v = (sptr)GFL_HEAP_Alloc(0x4c, 0x1c, 0, (const char *)0x021F140C, 0x228F);
    *(int *)((char *)((BoxTask *)task)->work + 0x60) = v;
}

void BOX2_SEQ_DeleteB(BoxTask *task)
{
    GFL_HEAP_Free(task->work->seq.entry);
}








/*
 * Stop one 0x74 sub-object, then the plain stop.
 */
void BOX2_SEQ_StopLeftBar(int task)
{
    BOX2_UI_PutTopBarOpen(*(struct BgWinFrmWork **)((char *)((BoxTask *)task)->work + 0x74));
    BOX2_SEQ_HideSlotsC688((BoxTask *)task);
}

/*
 * Resume one 0x74 sub-object, then the plain resume.
 */
void BOX2_SEQ_StopRightBar(int task)
{
    BOX2_UI_PutTopBarClosed(*(struct BgWinFrmWork **)((char *)((BoxTask *)task)->work + 0x74));
    BOX2_SEQ_HideSlotsC6F4((BoxTask *)task);
}

/*
 * Plain stop, then stop the 0x74 sub-object.
 */
void BOX2_SEQ_RestartLeftBar(int task)
{
    BOX2_SEQ_HideSlotsC688((BoxTask *)task);
    BOX2_UI_PutTopBarOpen(*(struct BgWinFrmWork **)((char *)((BoxTask *)task)->work + 0x74));
}

int BOX2_SEQ_DrawListSlot(BoxTask *task, int sel)
{
    int (*cb)(unsigned char *);
    int r = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA17F));
    task->curBox = *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0xA17F);
    BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
    BOX2_MAIN_SetBoxScroll((BoxTask *)task, (void *)BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), r);
    if (r == 1)
        cb = (int (*)(unsigned char *))BOX2_MAIN_StepScrollToNextBox;
    else
        cb = (int (*)(unsigned char *))BOX2_MAIN_StepScrollToPrevBox;
    switch (sel) {
    case 0:
        task->state = 0x15;
        break;
    case 1:
        task->state = 0x63;
        break;
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, (sptr)cb, task->state);
}

void BOX2_SEQ_CreateC(BoxTask *task)
{
    unsigned short *q = GFL_HEAP_Alloc(0x804C, 4, 0, d_021F140C, 0x2305);
    q[0] = 0;
    q[1] = 0;
    *(unsigned short * *)&task->work->scroll = q;
}

/*
 * Reset the entry then store the field with the dispatcher
 *   thumb-pointer 0x021E01C5 as its second argument.
 */
int BOX2_SEQ_RefreshBoxUiAndWait(char *task, int a)
{
    BOX2_MAIN_RefreshBoxUi((BoxTask *)task);
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x021E01C5, a);
}











/*
 * Same forward as BOX2_SEQ_RefreshBoxUiAndWait but after restarting the queue.
 */
int BOX2_SEQ_ResetEntryB(BoxTask *task, int a)
{
    BOX2_UI_CloseInfoBar(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74));
    return BOX2_SEQ_SetSeqThird((BoxTask *)task, 0x021E01E1, a);
}

void BOX2_SEQ_SetActorAnim(BoxTask *task, int v)
{
    if (v != 0) {
        if (task->cursorSlot < 0x1E)
            CURSOR_MOVE_SetSkipBit((((BoxTask *)(task))->work->cursorMove), 0x24);
        else
            CURSOR_MOVE_SetSkipBit((((BoxTask *)(task))->work->cursorMove), 9);
        BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF8FC, 3);
    } else {
        if (task->cursorSlot < 0x1E)
            CURSOR_MOVE_ClearSkipBit((((BoxTask *)(task))->work->cursorMove), 0x24);
        else
            CURSOR_MOVE_ClearSkipBit((((BoxTask *)(task))->work->cursorMove), 9);
        BOX2_SEQ_DrawFrameList((BoxTask *)task, d_021EF8F4, 2);
    }
}

/*
 * Busy 1 for the 0x16 field below 0x1e, else run the panel query and
 *   answer 2 for a hit, 0 otherwise.  `p` must be unsigned char *
 *   (ldrb, not ldrsb) and the result must be the CONSTANTS 1/2/0 with
 *   an early return -- an `int r = 0; ... return r;` keeps r live from
 *   the top, which pushes i from r4 to r6 and widens the push set.
 */
int BOX2_SEQ_CheckTradableMon(unsigned char *task)
{
    int i = task[0x16] - 0x1e;
    if (BOX2_MAIN_HasOtherTradable((void ***)task, i) == 0)
        return 1;
    if (FILE_UTIL_IsMailItem((unsigned short)POKE_TOOL_GetPartyValue(
            POKEPARTY_GetMember(((BoxTask *)task)->params->party, i), 6, 0)) == 1)
        return 2;
    return 0;
}

/*
 * candidate BOX2_SEQ_ToggleHandSlot: xor bit
 */
void BOX2_SEQ_ToggleHandSlot(int task, int bit)
{
    *(int *)(*(int *)&((BoxTask *)task)->work + 0xA174) ^= 1 << bit;
    BOX2_MAIN_SetHandSlots((char *)task, *(int *)(*(int *)&((BoxTask *)task)->work + 0xA174));
}

int BOX2_SEQ_GotoSceneA(BoxTask *task,int a) {
 if((unsigned char)((char *)((BoxTask *)(task))->work)[0xA17C]<=4 || ((unsigned char)((char *)((BoxTask *)(task))->work)[0xA17C]==5 && BOX_SAVEDATA_CheckFlags(task->params->boxSave,2)==0))
  ((char *)((BoxTask *)(task))->work)[0xA17B]=((unsigned char)((char *)((BoxTask *)(task))->work)[0xA17C]-1)*4+a-1;
 else ((char *)((BoxTask *)(task))->work)[0xA17B]=((unsigned char)((char *)((BoxTask *)(task))->work)[0xA17C]-1)*4+a;
 return BOX2_SEQ_GotoBox2Main((BoxTask *)task,a,BOX2_SEQ_ReturnAfterClear((BoxTask *)task,0x66));
}

void BOX2_SEQ_DeleteSlotWindows(BoxTask *task) {
 switch(task->params->mode) {
 case 0: BOX2_SEQ_SetSlotActors((char *)task,2,1); return;
 case 1: case 3: BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0); BOX2_SEQ_SetSlotActors((char *)task,1,1); return;
 case 2: case 4: case 5:
  BOX2_UI_ToggleSlotPair((struct BoxWork *)((char *)((BoxTask *)(task))->work),0);
  if(BOX2_UI_IsTopBarClosed(*(struct BgWinFrmWork **)(((char *)((BoxTask *)(task))->work)+0x74))==1) {
   BOX2_SEQ_SetSlotActors((char *)task,2,1); return;
  } else { BOX2_SEQ_SetSlotActors((char *)task,1,1); return; }
 }
}

int BOX2_SEQ_GotoBox2MainPlaySe(BoxTask *task, int v)
{
    GFL_USE_PlaySeDefaultVolume(0x54C);
    if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1)
        task->listState = 2;
    else
        task->listState = 1;
    task->exitFlag = 0;
    BOX2_MAIN_ActivateKeyCursor((BoxTask *)task);
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, v);
}

int BOX2_SEQ_GotoBox2MainNoSe(BoxTask *task, int v)
{
    GFL_USE_PlaySeDefaultVolume(0x54C);
    if (BOX2_UI_IsListOpen((((BoxTask *)(task))->work->winMgr)) == 1)
        task->listState = 2;
    else
        task->listState = 1;
    task->exitFlag = 0;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)task, v);
}

void BOX2_SEQ_InitBmpWins(BoxTask *task) {
 const unsigned char *x; unsigned i;
 BMP_WIN_Init(0x4C);
 x=d_021EFC20;
 for(i=0;i<28;i++,x+=6)
  *(void **)(((char *)((BoxTask *)(task))->work)+0x94+i*8)=(void *)BMP_WIN_Create(x[0],x[1],x[2],x[3],x[4],x[5],1);
}

/*
 * Walk 0x1c 8-byte records at p+0x2c+0x94, release each, then
 *   release the pool.  Unsigned counter for the image's blo.
 */
void BOX2_SEQ_DeleteBmpWins(char *task)
{
    unsigned i;
    for (i = 0; i < 0x1c; i++)
        BMP_WIN_Delete((struct BmpWin *)(*(int *)((char *)((BoxTask *)task)->work + i * 8 + 0x94)));
    BMP_WIN_Exit();
}

/*
 * Set bit i of the 0x174-byte bitmap hung off p.
 *   Unsigned index, or mwccarm emits asr instead of the image's lsr.
 */
void BOX2_SEQ_SetDirtyBit(unsigned char *work, unsigned i)
{
    unsigned char *q = work + 0x174;
    q[i >> 3] |= (unsigned char)(1 << (i & 7));
}

void BOX2_SEQ_FlushDirtyBmpWins(unsigned char *w) {
 unsigned i; unsigned char mask; unsigned char index;
 for(i=0;i<28;i++) {
  if(*(void **)(w+0x94+i*8)!=0) {
   mask=1<<(i&7); index=i>>3;
   if(w[0x174+index]&mask) {
    BMP_WIN_TransferChars(*(void **)(w+0x94+i*8));
    w[0x174+index]^=mask;
   }
  }
 }
}

void BOX2_SEQ_UpdateTextWins(unsigned char *w) {
 unsigned i; void *print;
 PRINTSYS_QUE_Main(((BoxWork *)w)->printQue);
 for(i=0;i<28;i++) {
  print=((BoxWork *)w)->printQue;
  if(w[0x98+i*8]) {
   if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)print,BMP_WIN_GetBmp(*(void **)(w+i*8+0x94)))==0) {
    BMP_WIN_TransferChars(*(void **)(w+i*8+0x94));
    w[0x98+i*8]=0;
   }
  }
 }
}

/*
 * Release both children of the object and then a global one.
 */
void BOX2_SEQ_MakeScreen(void **win)
{
    BMP_WIN_MakeScreen(*win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(*win));
}

void BOX2_SEQ_ClearScreen(void **win)
{
    BMP_WIN_ClearScreen(*win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(*win));
}

void BOX2_SEQ_PrintTextWin(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color) {
 void *s; unsigned print;
 s=MSGDATA_AllocString(bank,idx);
 print=(uptr)((BoxWork *)w)->printQue;
 PRINTSYS_PrintQueColor((void *)print,BMP_WIN_GetBmp(*(void **)(w+0x94+i*8)),(short)x,(short)y,s,(struct GfFont *)font,color);
 *(w+i*8+0x98)=1;
 STRBUF_Delete(s);
}

/*
 * Expands message idx of bank into the work string buffer and prints it into
 * message window i; marks the window dirty.
 */
void BOX2_SEQ_PrintTextWinEx(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color)
{
    uptr print;
    void *s;
    s = MSGDATA_AllocString(bank, idx);
    WORDSET_CopyTaggedText(((BoxWork *)w)->wordSet, (void *)(*(u32 *)&((BoxWork *)w)->strbuf), s);
    print = (uptr)((BoxWork *)w)->printQue;
    PRINTSYS_PrintQueColor((void *)print, BMP_WIN_GetBmp(*(void **)(w + i * 8 + 0x94)), (short)x, (short)y, (struct Strbuf *)(*(u32 *)&((BoxWork *)w)->strbuf), (struct GfFont *)font, color);
    *(unsigned char *)(w + i * 8 + 0x98) = 1;
    STRBUF_Delete(s);
}

/*
 * Call MSGDATA_CreateFromArchive with fixed arguments.
 */
void *BOX2_SEQ_CreateMsgBank(void)
{
    return MSGDATA_CreateFromArchive(0, 2, 0xa, 0x4c);
}

void BOX2_SEQ_PrintMsgWin(BoxTask *task) {
 unsigned char *w; void *bank;
 w=(unsigned char *)((char *)((BoxTask *)(task))->work);
 BMP_Clear(BMP_WIN_GetBmp(((BoxWork *)w)->windows[0].obj),0);
 bank=BOX2_SEQ_CreateMsgBank();
 BOX2_SEQ_PrintTextWin(w,0,bank,task->params->mode+0x25,0,8,((BoxWork *)w)->font,0x440);
 MSGDATA_Delete(bank);
 BOX2_SEQ_MakeScreen((void **)(((char *)((BoxTask *)(task))->work)+0x94));
}

void BOX2_SEQ_InitBmpWin(BoxTask *task)
{
    u8 *q = *(u8 * *)&task->work;

    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((BoxWork *)q)->iconSlots[0].obj)), 0);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((BoxWork *)q)->iconSlots[1].obj)), 0);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((BoxWork *)q)->iconSlots[2].obj)), 0);
    BMP_Clear((struct Bmp *)((uptr)BMP_WIN_GetBmp((struct BmpWin *)((BoxWork *)q)->iconSlots[3].obj)), 0);
    BOX2_SEQ_PrintTextWin(q, 0xa, (void *)(((BoxWork *)(q))->msgBank), 0x6d, 0, 0, ((BoxWork *)q)->font, 0x440);
    BOX2_SEQ_PrintTextWin(q, 0xb, (void *)(((BoxWork *)(q))->msgBank), 0x64, 0, 0, ((BoxWork *)q)->font, 0x440);
    BOX2_SEQ_PrintTextWin(q, 0xc, (void *)(((BoxWork *)(q))->msgBank), 0x65, 0, 0, ((BoxWork *)q)->font, 0x440);
    BOX2_SEQ_PrintTextWin(q, 0xd, (void *)(((BoxWork *)(q))->msgBank), 0x66, 0, 0, ((BoxWork *)q)->font, 0x440);
}

void BOX2_SEQ_FillTextWinEntry(unsigned char *w,BoxSeqEntry *e,unsigned i) {
 void **windows;
 windows=(void **)(w+0x94);
 BMP_Clear(BMP_WIN_GetBmp(windows[i*2]),0);
 if(!e->flag) {
  WORDSET_SetSlotMonNameAlt(((BoxWork *)w)->wordSet,0,(void *)e->value);
  BOX2_SEQ_PrintTextWinEx((char *)w,i,((BoxWork *)w)->msgBank,0,0,0,((BoxWork *)w)->font,0x440);
 } else { BOX2_SEQ_SetDirtyBit((unsigned char *)w,i); return; }
 BOX2_SEQ_MakeScreen(windows+i*2);
}

void BOX2_SEQ_FillTextWin(char *work, void **q, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(work + 0x94 + i * 8)), 0);
    WORDSET_SetSlotMonNicknameAlt(((BoxWork *)work)->wordSet, 0, *q);
    BOX2_SEQ_PrintTextWinEx(work, i, ((BoxWork *)work)->msgBank, 1, 0, 0, ((BoxWork *)work)->font, 0x440);
    BOX2_SEQ_MakeScreen((void **)(work + 0x94 + i * 8));
}

void BOX2_SEQ_DrawCellEntry(char *work, BoxSeqEntry *e, unsigned i)
{
    unsigned n;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(work + 0x94 + i * 8)), 0);
    if (!e->flag) {
        BOX2_SEQ_PrintTextWinEx(work, i, ((BoxWork *)work)->msgBank, 107, 0, 0, ((BoxWork *)work)->font, 0x440);
        n = PRINTSYS_MeasureWidestLine(((BoxWork *)work)->strbuf, (struct GfFont *)(((BoxWork *)work)->font), 0);
        WORDSET_SetSlotNumber(((BoxWork *)work)->wordSet, 0, e->low, 3, 0, 1);
        BOX2_SEQ_PrintTextWinEx(work, i, ((BoxWork *)work)->msgBank, 103, n, 0, ((BoxWork *)work)->font, 0x440);
    } else {
        BOX2_SEQ_SetDirtyBit((unsigned char *)work, i); return;
    }
    BOX2_SEQ_MakeScreen((void **)(work + 0x94 + i * 8));
}

/*
 * trailing: two-byte zero alignment padding at 0x021EAFBA.
 */
void BOX2_SEQ_DrawSpriteEntry(char *work, BoxSeqEntry *e, unsigned i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(work + 0x94 + i * 8)), 0);
    if (!e->flag && e->enabled == 1) {
        if (e->kind == 0) {
            BOX2_SEQ_PrintTextWin((unsigned char *)work, i, ((BoxWork *)work)->msgBank, 95, 0, 0, ((BoxWork *)work)->font, 0x14c0);
        } else if (e->kind == 1) {
            BOX2_SEQ_PrintTextWin((unsigned char *)work, i, ((BoxWork *)work)->msgBank, 96, 0, 0, ((BoxWork *)work)->font, 0xc80);
        } else {
            BOX2_SEQ_SetDirtyBit((unsigned char *)work, i); return;
        }
    } else {
        BOX2_SEQ_SetDirtyBit((unsigned char *)work, i); return;
    }
    BOX2_SEQ_MakeScreen((void **)(work + 0x94 + i * 8));
}

void BOX2_SEQ_DrawTileEntry(char *task,const BoxSeqEntry *e,u32 i)
{
    u16 n;
    u32 text;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(((char *)((BoxTask *)(task))->work)+i*8+148)),0);
    if (e->flag == 0) {
        if (*(u32 *)(((char *)((BoxTask *)(task))->work)+380) == 1)
            n = ((BoxTextEntry *)(e))->idx;
        else
            n = *(u16 *)(*(char **)(((char *)((BoxTask *)(task))->work)+384)+((BoxTextEntry *)(e))->idx*2);
        if (n != 999) {
            BOX2_SEQ_PrintTextWinEx(((char *)((BoxTask *)(task))->work),i,*(void **)(((char *)((BoxTask *)(task))->work)+128),108,0,0,*(u32 *)(((char *)((BoxTask *)(task))->work)+120),1088);
            text=PRINTSYS_MeasureWidestLine(*(void **)(((char *)((BoxTask *)(task))->work)+136),(struct GfFont *)(*(u32 *)(((char *)((BoxTask *)(task))->work)+120)),0);
            WORDSET_SetSlotNumber(*(void **)(((char *)((BoxTask *)(task))->work)+132),0,n,3,2,1);
            BOX2_SEQ_PrintTextWinEx(((char *)((BoxTask *)(task))->work),i,*(void **)(((char *)((BoxTask *)(task))->work)+128),104,text,0,*(u32 *)(((char *)((BoxTask *)(task))->work)+120),1088);
        } else { BOX2_SEQ_SetDirtyBit((unsigned char *)((char *)((BoxTask *)(task))->work),i); return; }
    } else { BOX2_SEQ_SetDirtyBit((unsigned char *)((char *)((BoxTask *)(task))->work),i); return; }
    BOX2_SEQ_MakeScreen((void **)(((char *)((BoxTask *)(task))->work)+148+i*8));
}

void BOX2_SEQ_DrawMoveEntry(char *work, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(work + 0x94 + i * 8)), 0);
    if (!((BoxSeqEntry *)e)->flag) {
        WORDSET_SetSlotFromMsg18(((BoxWork *)work)->wordSet, 0, e[15]);
        BOX2_SEQ_PrintTextWinEx(work, i, ((BoxWork *)work)->msgBank, 98, 0, 0, ((BoxWork *)work)->font, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)work, i, ((BoxWork *)work)->msgBank, 106, 0, 0, ((BoxWork *)work)->font, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(work + 0x94 + i * 8));
}

void BOX2_SEQ_DrawSwapEntry(char *work, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(work + 0x94 + i * 8)), 0);
    if (!((BoxSeqEntry *)e)->flag) {
        WORDSET_SetSlotFromMsgB6(((BoxWork *)work)->wordSet, 0, e[14]);
        BOX2_SEQ_PrintTextWinEx(work, i, ((BoxWork *)work)->msgBank, 97, 0, 0, ((BoxWork *)work)->font, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)work, i, ((BoxWork *)work)->msgBank, 106, 0, 0, ((BoxWork *)work)->font, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(work + 0x94 + i * 8));
}

void BOX2_SEQ_DrawItemEntry(char *work, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(work + 0x94 + i * 8)), 0);
    if (((BoxTextEntry *)(e))->value != 0) {
        WORDSET_SetSlotFromMsg36(((BoxWork *)work)->wordSet, 0, ((BoxTextEntry *)(e))->value);
        BOX2_SEQ_PrintTextWinEx(work, i, ((BoxWork *)work)->msgBank, 99, 0, 0, ((BoxWork *)work)->font, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)work, i, ((BoxWork *)work)->msgBank, 105, 0, 0, ((BoxWork *)work)->font, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(work + 0x94 + i * 8));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`windows = (void **)p;` before `windows = (void **)(p + 0x94);`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void BOX2_SEQ_DrawMsgEntry(char *work, BoxSeqEntry *e, int i)
{
    void **windows;
    unsigned j;
    void *bank;
    windows = (void **)(work + 0x94);
    BMP_Clear(BMP_WIN_GetBmp(windows[i * 2]), 0);
    j = 0;
    bank = MSGDATA_CreateFromArchive(0, 2, 203, 0x804c);
    if (!e->flag) {
        for (; j < 4; j++) {
            BOX2_SEQ_PrintTextWin((unsigned char *)work, i, bank, *(unsigned short *)((char *)e + 0x14 + j * 2), 0, j * 16, ((BoxWork *)work)->font, 0x440);
        }
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)work, i, ((BoxWork *)work)->msgBank, 106, 0, 0, ((BoxWork *)work)->font, 0x440);
    }
    MSGDATA_Delete(bank);
    BOX2_SEQ_MakeScreen(windows + i * 2);
}













void BOX2_SEQ_DeleteTextEntries(BoxTask *task, void *a)
{
    BOX2_SEQ_FillTextWinEntry((unsigned char *)((char *)task->work), (BoxSeqEntry *)a, 1);
    BOX2_SEQ_FillTextWin((char *)task->work, (void **)a, 2);
    BOX2_SEQ_DrawCellEntry((char *)task->work, (BoxSeqEntry *)a, 3);
    BOX2_SEQ_DrawSpriteEntry((char *)task->work, (BoxSeqEntry *)a, 4);
    BOX2_SEQ_DrawTileEntry((char *)task, (const BoxSeqEntry *)a, 5);
    BOX2_SEQ_DrawMoveEntry((char *)task->work, (unsigned char *)a, 6);
    BOX2_SEQ_DrawSwapEntry((char *)task->work, (unsigned char *)a, 7);
    BOX2_SEQ_DrawItemEntry((char *)task->work, (unsigned char *)a, 8);
    BOX2_SEQ_DrawMsgEntry((char *)task->work, (BoxSeqEntry *)a, 9);
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)task->work + 0xe4));
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)task->work + 0xec));
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)task->work + 0xf4));
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)task->work + 0xfc));
}

void BOX2_SEQ_ClearTextWin(BoxWork *work)
{
    Box2SeqWork *w = (Box2SeqWork *)work;
    unsigned i;
    for (i = 1; i <= 9; i++) {
        BOX2_SEQ_ClearScreen((void **)(&w->items[i]));
        BMP_Clear(BMP_WIN_GetBmp(w->items[i].obj), 0);
        BOX2_SEQ_SetDirtyBit((unsigned char *)w, i);
    }
    BOX2_SEQ_ClearScreen((void **)(&w->items[10]));
    BOX2_SEQ_ClearScreen((void **)(&w->items[11]));
    BOX2_SEQ_ClearScreen((void **)(&w->items[12]));
    BOX2_SEQ_ClearScreen((void **)(&w->items[13]));
}

/*
 * Draws a window frame from 8x8 tiles, then centres a message in it.  The
 * window size locals are u8 like the getters that return them: as int
 * locals the w - 1 and h - 1 loop guards stop sharing the corner offsets'
 * common subexpressions and the function comes out 20 bytes short.
 */
void BOX2_SEQ_DrawWindowFrame(BoxTask *task, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon)
{
    void *win = *(void **)(((char *)((BoxTask *)(task))->work) + 0x94 + idx * 8);
    void *bmp = BMP_WIN_GetBmp((struct BmpWin *)win);
    unsigned char w;
    unsigned char h;
    Chr *chr;
    void *res;
    char *raw;
    void *t;
    unsigned char i;
    void *str;

    BMP_WIN_GetBgLayer(win);
    BMP_WIN_GetPosX((struct BmpWin *)win);
    BMP_WIN_GetPosY((struct BmpWin *)win);
    w = BMP_WIN_GetWidth((struct BmpWin *)win);
    h = BMP_WIN_GetHeight((struct BmpWin *)win);
    BMP_Clear(bmp, 4);
    res = ARC_UTIL_LoadBgCharDataFromArchive(0x74, 0x3E, 1, (&chr), HEAP);
    raw = chr->raw;
    frame *= 0x20;

    t = BMP_CreateFromBuffer(raw + frame, 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, 0, 0, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x40), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, 0, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xC0), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, 0, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x100), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x60), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        BMP_Blit(t, bmp, 0, 0, 0, i * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xA0), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, i * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x20), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        BMP_Blit(t, bmp, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xE0), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        BMP_Blit(t, bmp, 0, 0, i * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Bmp *)t);

    GFL_HEAP_Free((void *)res);

    if (icon == 1) {
        res = ARC_UTIL_LoadBgCharDataFromArchive(APP_ICON_GetArchiveId(), 0x20, 0, (&chr), HEAP);
        t = BMP_CreateFromBuffer(chr->raw + 0x120, 0x10, 8, 0x20, HEAP);
        BMP_Blit(t, bmp, 0, 0, (w - 3) * 8, 8, 0x10, 8, 5);
        BMP_Delete((struct Bmp *)t);
        GFL_HEAP_Free((void *)res);
    }

    str = MSGDATA_AllocString((struct MsgBank *)(*(void **)(((char *)((BoxTask *)(task))->work) + 0x80)), msg);
    TOUCHBAR_PrintAligned((TouchBarWindow *)((u8 *)(((char *)((BoxTask *)(task))->work) + 0x94 + idx * 8)), (void *)(*(void **)(((char *)((BoxTask *)(task))->work) + 0x8C)), w * 8 / 2, 4, (uptr)str,
                  *(unsigned *)(((char *)((BoxTask *)(task))->work) + 0x78), col, 2);
    STRBUF_Delete(str);
}

/*
 * Range call with a fixed span and the caller's fourth value.
 */
void BOX2_SEQ_DrawFrameColor(int a, int b, int c, int d)
{
    BOX2_SEQ_DrawWindowFrame((BoxTask *)a, b, c, 0, 0x3d80, d);
}

/*
 * Same range call with both tail slots fixed.
 */
void BOX2_SEQ_DrawFrameDefault(int a, int b, int c)
{
    BOX2_SEQ_DrawWindowFrame((BoxTask *)a, b, c, 0, 0xf6 << 6, 0);
}

void BOX2_SEQ_AddBmpWinFrame(void *m,unsigned i,void *d){unsigned bg=BMP_WIN_GetBgLayer(d);unsigned w=BMP_WIN_GetWidth(d);unsigned h=BMP_WIN_GetHeight(d);BGWINFRM_AddFrame((void *)m,i,bg,w,h);BGWINFRM_PutBmpWin((void *)m,i,d);}

void BOX2_SEQ_AddTextFrame(BoxWork *work)
{
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork * *)&work->winMgr, 0, work->iconSlots[4].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork * *)&work->winMgr, 1, work->iconSlots[5].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork * *)&work->winMgr, 2, work->iconSlots[6].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork * *)&work->winMgr, 3, work->iconSlots[7].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork * *)&work->winMgr, 4, work->iconSlots[8].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork * *)&work->winMgr, 5, work->iconSlots[9].obj);
}

void BOX2_SEQ_AddMsgFrame(unsigned char *task){if(((BoxTask *)task)->params->mode==4)BOX2_SEQ_DrawFrameDefault((sptr)task,22,71);else BOX2_SEQ_DrawFrameDefault((sptr)task,22,69);BOX2_SEQ_AddBmpWinFrame(((BoxTask *)task)->work->winMgr,10,((BoxTask *)task)->work->infoWin);}

/*
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */
void BOX2_SEQ_AddNameFrame(BoxTask *task)
{
    BOX2_SEQ_DrawFrameDefault((sptr)task, 0x17, 0x46);
    BOX2_SEQ_AddBmpWinFrame(*(struct BgWinFrmWork **)(*(int *)&task->work + 0x74), 0xb,
                  (void *)(*(int *)(*(int *)&task->work + 0x14C)));
}

void BOX2_SEQ_DrawBoxName(char **work, unsigned box, int i)
{
    void *s = STRBUF_Create(0x14, 0x804C);
    unsigned n;
    BOX_SAVEDATA_GetBoxName(((void **)work[0])[1], box, s);
    BMP_Clear(*(void **)(work[11] + i * 8 + 8), 0);
    n = PRINTSYS_MeasureWidestLine(s, (struct GfFont *)(((BoxWork *)work[11])->font), 0);
    n = (0x60 - n) / 2;
    PRINTSYS_PrintColor(*(void **)(work[11] + i * 8 + 8), n, 0, s, (void *)((BoxWork *)work[11])->font, 0x440);
    STRBUF_Delete(s);
    BMP_OAM_UploadChars(*(void **)(work[11] + i * 8 + 4));
}























/*
 * Wrap the 0x19 counter and forward it with p.
 */
void BOX2_SEQ_DrawOffsetName(unsigned char *task, int i)
{
    unsigned v = i + task[0x19];
    if (v >= task[0x15])
        v -= task[0x15];
    BOX2_SEQ_DrawBoxName((char **)task, v, 0);
}

void BOX2_SEQ_DrawMonName(char **work, unsigned a, int i)
{
    void *s = MSGDATA_AllocString(((BoxWork *)work[11])->msgBank, 0x1E);
    unsigned n = BOX_SAVEDATA_CountPokemonInBox((void *)(((unsigned *)work[0])[1]), a);
    WORDSET_SetSlotNumber(((BoxWork *)work[11])->wordSet, 0, n, 2, 0, 1);
    WORDSET_CopyTaggedText(((BoxWork *)work[11])->wordSet, ((BoxWork *)work[11])->strbuf, s);
    BMP_Clear(*(void **)(work[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        PRINTSYS_PrintColor(*(void **)(work[11] + i * 8 + 8), 0, 0, ((BoxWork *)work[11])->strbuf, ((BoxWork *)work[11])->fontAlt, 0x1480);
    else
        PRINTSYS_PrintColor(*(void **)(work[11] + i * 8 + 8), 0, 0, ((BoxWork *)work[11])->strbuf, ((BoxWork *)work[11])->fontAlt, 0x440);
    STRBUF_Delete(s);
    BMP_OAM_UploadChars(*(void **)(work[11] + i * 8 + 4));
}

/*
 * trailing: two-byte zero alignment padding at 0x021EB95A.
 */
void BOX2_SEQ_ChangeFramePalette(BoxTask *task)
{
    BOX2_SEQ_DrawFrameColor((sptr)task, 20, 84, 0);
    BOX2_SEQ_DrawFrameColor((sptr)task, 21, 85, 1);
    BGWINFRM_ChangePalette(*(struct BgWinFrmWork * *)&task->work->winMgr, 7, 0, 9, 11, 3, 12);
    BGWINFRM_ChangePalette(*(struct BgWinFrmWork * *)&task->work->winMgr, 7, 0, 12, 11, 3, 12);
}

void BOX2_SEQ_PutNameFrame(char *task){BGWINFRM_PutBmpWin((struct BgWinFrmWork *)(((BoxTask *)task)->work->winMgr),7,(void *)(((BoxTask *)task)->work->portraitWin));BGWINFRM_PutBmpWin((struct BgWinFrmWork *)(((BoxTask *)task)->work->winMgr),7,(void *)(((BoxTask *)task)->work->nameWin));BOX2_SEQ_ChangeFramePalette((BoxTask *)task);}

void BOX2_SEQ_DrawFrameList(BoxTask *task, const void *e, unsigned n)
{
    unsigned short w;
    unsigned short h;
    unsigned i = 0;
    BGWINFRM_GetSize((((BoxTask *)(task))->work->winMgr), 0, &w, &h);
    for (i = 0; i < n; i++) {
        const Ent *x = &((const Ent *)e)[n - 1 - i];
        if (x->b == 0)
            BOX2_SEQ_DrawFrameColor((sptr)task, 0x13 - i, x->a, 0);
        else
            BOX2_SEQ_DrawFrameColor((sptr)task, 0x13 - i, x->a, 1);
        BGWINFRM_ChangePalette((((BoxTask *)(task))->work->winMgr), 5 - i, 0, 0, w, h, 0xC);
    }
    for (; n < 6; n++) {
        unsigned k = 0x13 - n;
        BMP_Clear(BMP_WIN_GetBmp(*(void **)(((char *)((BoxTask *)(task))->work) + k * 8 + 0x94)), 0);
        BOX2_SEQ_SetDirtyBit((unsigned char *)((char *)((BoxTask *)(task))->work), k);
    }
}

/*
 * Clears a message window to colour 15 and draws its frame.
 */
void BOX2_SEQ_ClearMessageWindow(BoxTask *task, void *win)
{
    BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)win), 0xF);
    BMP_MENUWORK_DrawWindow(win, 2, (unsigned short)*(int *)(((char *)((BoxTask *)(task))->work) + 0x178), 10);
}

/*
 * Forward the i-th entry word with flag 1.
 */
void BOX2_SEQ_ShowWindowObject(char *work, int i)
{
    BMP_MENUWORK_DrawWindowBorder(*(void **)(work + i * 8 + 0x94), 1);
}

/*
 * Forward the i-th entry word with flag 0.
 */
void BOX2_SEQ_HideWindowObject(char *work, int i)
{
    BMP_MENUWORK_DrawWindowBorder(*(void **)(work + i * 8 + 0x94), 0);
}

/*
 * Prints message msg of the box-menu bank into message window i.
 */
void BOX2_SEQ_PrintMessageMsg(BoxTask *task, int msg, int i)
{
    void *bank = BOX2_SEQ_CreateMsgBank();
    BOX2_SEQ_ClearMessageWindow((BoxTask *)task, *(void **)(((char *)((BoxTask *)(task))->work) + i * 8 + 0x94));
    BOX2_SEQ_PrintTextWinEx(((char *)((BoxTask *)(task))->work), i, bank, msg, 0, 0, *(u32 *)(((char *)((BoxTask *)(task))->work) + 0x78), 0x44F);
    BOX2_SEQ_MakeScreen((void **)(((char *)((BoxTask *)(task))->work) + 0x94 + i * 8));
    MSGDATA_Delete(bank);
    BOX2_UI_HideSlots678(task);
}

/*
 * Sibling of BOX2_SEQ_PrintMessageC: index 0x34 when state is 5, else 0xb.
 */
void BOX2_SEQ_PrintMessageB(char *task, int b)
{
    if (((BoxTask *)task)->params->mode == 5)
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x34, b);
    else
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0xb, b);
}

/*
 * Puts item v into word slot 0 and prints message 0x15 into window i.
 */
void BOX2_SEQ_PrintWordset(BoxTask *task, u32 v, int i)
{
    WORDSET_SetSlotFromMsg36(*(void **)(((char *)((BoxTask *)(task))->work) + 0x84), 0, v);
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x15, i);
}

/*
 * Prints message 0x16 into window i.
 */
void BOX2_SEQ_PrintMessage(unsigned char *task, int i)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x16, i);
}

/*
 * Forward with index 43.
 */
void BOX2_SEQ_PrintMessageC(char *task, int b)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x2b, b);
}

/*
 * Stage 0x84 of the p+0x2c object with (0, arg1), then index 0xe
 *   with the third argument.
 */
void BOX2_SEQ_PrintWordsetB(char *task, int a, int b)
{
    WORDSET_SetSlotFromMsg36((struct WordSet *)(*(int *)((char *)((BoxTask *)task)->work + 0x84)), 0, a);
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0xe, b);
}

/*
 * Forward with index 13.
 */
void BOX2_SEQ_PrintMessageD(char *task, int b)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0xd, b);
}

void BOX2_SEQ_PrintWordsetBB64(BoxTask *task, unsigned v, int i)
{
    if (v == 0) {
        WORDSET_SetSlotFromMsg36(task->work->wordSet, 0, 0x70);
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x2c, i);
    } else if (FILE_UTIL_IsMailItem(v) == 1) {
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x30, i);
    } else {
        WORDSET_SetSlotFromMsg36(task->work->wordSet, 0, v);
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 15, i);
    }
}

/*
 * Forward with index 32.
 */
void BOX2_SEQ_PrintMessageE(char *task, int b)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x20, b);
}

/*
 * The image leaves the message undefined for kinds above six.
 */
void BOX2_SEQ_PrintMonName(BoxTask *task, unsigned kind, int i)
{
    int msg;
    switch (kind) {
    case 0: msg = 2; break;
    case 1: msg = 3;
        WORDSET_SetSlotMonNicknameAlt(task->work->wordSet, 0, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot));
        break;
    case 2: msg = 4;
        WORDSET_SetSlotMonNicknameAlt(task->work->wordSet, 0, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot));
        break;
    case 3: msg = 0x1c; break;
    case 4: msg = 0x1d;
        WORDSET_SetSlotMonNicknameAlt(task->work->wordSet, 0, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot));
        break;
    case 5: msg = 0x1e; break;
    case 6: msg = 6; break;
    }
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, msg, i);
}

void BOX2_SEQ_PrintIndexedMessage(unsigned char *task,int n,int i){switch(n){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;case 3:n=10;break;}BOX2_SEQ_PrintMessageMsg((BoxTask *)task,n,i);}

/*
 * Picks the prompt for a menu kind (kind 1 first names the Pokemon in the
 * current slot) and prints it into window i.  An out-of-range kind prints
 * whatever msg holds; the image does not initialise it.
 */
void BOX2_SEQ_PrintPrompt(BoxTask *task, int sel, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x10;
        break;
    case 1:
        msg = 0;
        WORDSET_SetSlotMonNicknameAlt(*(void **)(((char *)((BoxTask *)(task))->work) + 0x84), 0, (void *)BOX2_MAIN_GetMonAt((void ***)task, task->curBox, task->cursorSlot));
        break;
    case 2:
        msg = 5;
        break;
    case 3:
        msg = 0x11;
        break;
    case 4:
        msg = 0xC;
        break;
    case 5:
        msg = 0x1B;
        break;
    }
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, msg, i);
}











/*
 * Item-menu prompt for a kind; kinds 1 to 3 name the held item first.  An
 * out-of-range kind prints whatever msg holds; the image does not initialise it.
 */
void BOX2_SEQ_PrintPromptB(BoxTask *task, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x1A;
        break;
    case 1:
        msg = 0x17;
        WORDSET_SetSlotFromMsg36(*(void **)(((char *)((BoxTask *)(task))->work) + 0x84), 0, *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C));
        break;
    case 2:
        msg = 0x18;
        WORDSET_SetSlotFromMsg36(*(void **)(((char *)((BoxTask *)(task))->work) + 0x84), 0, *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C));
        break;
    case 3:
        msg = 0x19;
        WORDSET_SetSlotFromMsg36(*(void **)(((char *)((BoxTask *)(task))->work) + 0x84), 0, *(unsigned short *)(((char *)((BoxTask *)(task))->work) + 0xA16C));
        break;
    case 4:
        msg = 0x16;
        break;
    case 5:
        msg = 0x1F;
        break;
    case 6:
        msg = 0xD;
        break;
    case 7:
        msg = 0x2F;
        break;
    }
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, msg, i);
}

/*
 * Maps a menu row to its message index, then tail-calls the printer.
 */
void BOX2_SEQ_PrintMenuRow(char *task, int row, int b)
{
    switch (row) {
    case 2:
        row = 0x2d;
        break;
    case 3:
        row = 0x2e;
        break;
    case 4:
        row = 0x31;
        break;
    case 6:
        row = 0x33;
        break;
    }
    BOX2_SEQ_PrintMessageMsg((BoxTask *)task, row, b);
}

void BOX2_SEQ_PrintBoxMonName(unsigned char *task){void *m=(void *)BOX2_MAIN_GetMonAt((void ***)task,task[20],task[22]);WORDSET_SetSlotMonNicknameAlt((struct WordSet *)(((BoxTask *)task)->work->wordSet), 0, m);BOX2_SEQ_PrintMessageMsg((BoxTask *)task,50,27);}

/*
 * Index 0x35 when the flag is clear, 0x36 when set.
 */
void BOX2_SEQ_PrintYesNo(char *task, int b)
{
    if (b == 0)
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x35, 0x1b);
    else
        BOX2_SEQ_PrintMessageMsg((BoxTask *)task, 0x36, 0x1b);
}

/*
 * trailing: two-byte zero alignment padding at 0x021EBDD6.
 */
void BOX2_SEQ_CreateBox2UiScene(BoxTask *task)
{
    BOX2_SEQ_InitClact((char *)task->work);
    BOX2_SEQ_LoadBoxGraphics((char *)task->work);
    BOX2_SEQ_CreateBox2Actors((unsigned char *)task);
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, task->slot6Mode, task->slot7Mode, task->slot8Mode);
    BOX2_UI_CreateBmpOam((struct BoxWork *)task->work);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

/*
 * Three teardown steps then the SDK pool release.
 */
void BOX2_SEQ_DeleteBox2UiScene(char *work)
{
    BOX2_UI_DeleteBmpOam((char *)work);
    BOX2_SEQ_DeleteAllActors((BoxWork *)work);
    BOX2_SEQ_ReleaseBoxGraphics((char *)work);
    CLACT_ExitSystem();
}

void BOX2_SEQ_InitClact(void *work){Template t=d_021EFD64;unsigned n=(uptr)BOX2_MAIN_GetDispVram();CLACT_InitSystem((const struct ClactSysInit *)&t,(struct DispVramCfg *)n,76);}

void BOX2_SEQ_LoadBoxGraphics(char *work){BOX2_SEQ_RegisterBoxChars((char *)work);BOX2_SEQ_RegisterBoxCharsB((BoxWork *)work);BOX2_SEQ_RegisterIconRes((BoxWork *)work);BOX2_SEQ_LoadIconPalette((u8 *)work);BOX2_SEQ_InitIconSlots((BoxWork *)work);BOX2_SEQ_LoadBoxScreen(work);}

void BOX2_SEQ_ReleaseBoxGraphics(char *work)
{
    unsigned i;
    for (i = 0; i < 0x45; i++)
        if (*(int *)(work + i * 4 + 0x9FF4) != -1)
            CLACT_ReleaseCharacter(*(int *)(work + i * 4 + 0x9FF4));
    for (i = 0; i < 0xB; i++)
        if (*(int *)(work + i * 4 + 0xA108) != -1)
            CLACT_ReleasePalette(*(int *)(work + i * 4 + 0xA108));
    for (i = 0; i < 0xC; i++)
        if (*(int *)(work + i * 4 + 0xA134) != -1)
            CLACT_ReleaseCellAnim(*(int *)(work + i * 4 + 0xA134));
}

void BOX2_SEQ_CreateBox2Actors(unsigned char *task){((BoxTask *)task)->work->clactUnit=CLACT_CreateUnit(180,0,76);BOX2_UI_CreatePartyActors((struct BoxWork *)*(char * *)&((BoxTask *)task)->work);BOX2_SEQ_CreateBoxSlotActors(*(char * *)&((BoxTask *)task)->work);BOX2_SEQ_CreateCursorObjects((BoxTask *)task);BOX2_SEQ_CreateHandSlotActors(*(char * *)&((BoxTask *)task)->work);}

void *BOX2_SEQ_CreateActorFromDesc(char *w, const Box2SeqDesc *s)
{
    void *r = CLACT_CreateActor((struct Unit *)(((BoxWork *)w)->clactUnit), (uptr)*(void **)(w + s->a * 4 + 0x9FF4),
                            (uptr)*(void **)(w + s->b * 4 + 0xA108), (uptr)*(void **)(w + s->c * 4 + 0xA134),
                            (const struct ActorInitParam *)s, s->d, 0x4C);
    CLACT_SetActorVisible(r, 0);
    return r;
}

/*
 * Release slot i of the 0x9E74 array when non-null.
 *   CLOSES the register-order residue: `struct BoxActorSlotTable { char pad[0x9E74]; int arr[1]; }`
 *   with `p->arr[i]` gives the image's r4 = p+0x9E74 / r5 = i*4; a plain
 *   `char *p` plus `p + i * 4 + 0x9E74` puts the index in r1 and the constant
 *   in r5 instead.
 */
void BOX2_SEQ_DeleteActorSlot(struct BoxActorSlotTable *table, int i)
{
    if (table->arr[i] != 0) {
        CLACT_DeleteActor((struct ClactActor *)((struct Obj *)table->arr[i]));
        table->arr[i] = 0;
    }
}

/*
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */
void BOX2_SEQ_DeleteAllActors(BoxWork *work)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        BOX2_SEQ_DeleteActorSlot((struct BoxActorSlotTable *)work, i);
    CLACT_DeleteUnit((struct Unit *)(work->clactUnit));
}

/*
 * Sweep 0x2d slots of the 0x9E74 array, restarting each live one.
 *   The element address must be a named `int *row = (int *)(p + i*4)`
 *   and the offset written as the WORD index row[0x279d]: that is what
 *   puts i in r4, the row in r5 and 0x9E74 in r7 (the flat spelling
 *   swaps r4/r5).
 */
void BOX2_SEQ_DrawActors(char *work)
{
    unsigned i;
    for (i = 0; i < 0x2d; i++) {
        int *row = (int *)(work + i * 4);
        if (row[0x279d] != 0 && CLACT_GetActorAutoAnim((struct ClactActor *)((struct Obj *)row[0x279d])) != 1)
            CLACT_AddActorAnimFrame((struct ClactActor *)((struct Obj *)row[0x279d]), 0x1000);
    }
    CLACT_DrawSystem();
}

/*
 * Stop and re-issue slot i of the 0x9E74 array; the word is
 *   re-read for the second call.  Writing the array offset before the index
 *   term is what puts the pool constant in r2 and the index in r6.
 */
void BOX2_SEQ_SetActorAnimSeq(char *work, int i, int v)
{
    CLACT_SetActorAnimFrame((struct ClactActor *)((struct Obj *)(*(int *)(work + 0x9E74 + i * 4))), 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)((struct Obj *)(*(int *)(work + 0x9E74 + i * 4))), (unsigned short)v);
}

/*
 * Release-and-flag slot i of the 0x9E74 array.
 */
void BOX2_SEQ_SetActorAutoAnim(char *work, int i, int v)
{
    BOX2_SEQ_SetActorAnimSeq((char *)work, i, v);
    CLACT_SetActorAutoAnim((struct ClactActor *)((struct Obj *)*(int *)(work + i * 4 + 0x9E74)), 1);
}

/*
 * Forward the i-th word of the pooled table.
 */
u32 BOX2_SEQ_IsActorAnimActive(char *work, int i)
{
    return CLACT_IsActorAnimActive((struct ClactActor *)(*(int *)(work + i * 4 + 0x9E74)));
}

/*
 * Release slot i of the 0x9E74 array when it is non-null.
 */
void BOX2_SEQ_SetActorDrawEnable(char *work, int i, int v)
{
    int x = *(int *)(work + i * 4 + 0x9E74);
    if (x != 0)
        CLACT_SetActorDrawEnable((struct ClactActor *)((struct Obj *)x), v);
}

u32 BOX2_SEQ_GetActorDrawEnable(char *work, int i)
{
    return CLACT_GetActorDrawEnable((struct ClactActor *)((struct Obj *)(*(int *)(work + i * 4 + 0x9E74))));
}

/*
 * Tail call with the table word at the pooled offset.
 */
void BOX2_SEQ_SetActorBgPriority(char *work, int i, int c)
{
    CLACT_SetActorBgPriority((struct ClactActor *)(*(int *)(work + i * 4 + 0x9E74)), (unsigned char)c);
}










void BOX2_SEQ_SetActorDrawPriority(char *work, int i, int c)
{
    CLACT_SetActorDrawPriority((struct ClactActor *)(*(int *)(work + i * 4 + 0x9E74)), (unsigned char)c);
}

void BOX2_SEQ_SetActorObjMode(char *work,unsigned i,int b){if(b==1)CLACT_SetActorObjMode(*(void **)((uptr)work+i*4+0x9e74),1);else CLACT_SetActorObjMode(*(void **)((uptr)work+i*4+0x9e74),0);}

/*
 * Stage two shorts on the stack and hand the 0x9E74 array slot to the
 *   SDK call.  Two spellings (array and struct) both give the image's
 *   store order, because the index term is computed between the stores.
 */
void BOX2_SEQ_AddActorSurfacePos(char *work, int i, int a, int b, unsigned short c)
{
    unsigned short t[2];
    t[0] = a;
    t[1] = b;
    CLACT_AddActorSurfacePos((struct ClactActor *)((struct Obj *)(*(int *)(work + i * 4 + 0x9E74))), (const struct ClactVec2 *)t, c);
}

void BOX2_SEQ_GetActorSurfacePos(char *work, int i, short *a, short *b, unsigned short space)
{
    short t[2];
    CLACT_GetActorSurfacePos((struct ClactActor *)*(int *)(work + i * 4 + 0x9E74), (struct ClactVec2 *)t, space);
    *a = t[0];
    *b = t[1];
}

void BOX2_SEQ_RegisterBoxChars(char *work)
{
    void *h;
    unsigned i,j;
    h=ARC_TOOL_CreateHandle(116,76);
    for(j=0;j<6;j++) (*(void **)((char *)(work+j*4) + (0xA0D8)))=(void *)CLACT_RegisterCharacter(h,71,1,0,76);
    (*(void **)((char *)(work) + (0xA11C)))=(void *)CLACT_RegisterPalette(h,72,0,0,76);
    (*(void **)((char *)(work) + (0xA148)))=(void *)CLACT_RegisterCellAnim(h,73,74,76);
    for(i=0;i<37;i++) (*(void **)((char *)(work+i*4) + (0x9FF4)))=(void *)CLACT_RegisterCharacter(h,75,1,0,76);
    (*(void **)((char *)(work) + (0xA0F0)))=(void *)CLACT_RegisterCharacter(h,67,1,0,76);
    (*(void **)((char *)(work) + (0xA120)))=(void *)CLACT_RegisterPalette(h,70,0,192,76);
    (*(void **)((char *)(work) + (0xA14C)))=(void *)CLACT_RegisterCellAnim(h,68,69,76);
    (*(void **)((char *)(work) + (0xA0F4)))=(void *)CLACT_RegisterCharacter(h,64,1,0,76);
    (*(void **)((char *)(work) + (0xA150)))=(void *)CLACT_RegisterCellAnim(h,65,66,76);
    (*(void **)((char *)(work) + (0xA090)))=(void *)CLACT_RegisterCharacter(h,76,1,0,76);
    (*(void **)((char *)(work) + (0xA140)))=(void *)CLACT_RegisterCellAnim(h,77,78,76);
    ARC_TOOL_DeleteHandle(h);
}

void BOX2_SEQ_RegisterBoxCharsB(BoxWork *work)
{
    void *h = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x4C);
    work->iconCellRes = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x4C);
    work->iconCharRes = (void *)CLACT_RegisterPalette(h, APP_ICON_GetMoveKindPaletteFileId(), 0, 0x100, 0x4C);
    work->iconObjects = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetStatusCellFileId(2), APP_ICON_GetStatusPaletteFileId(2), 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

void BOX2_SEQ_RegisterIconRes(BoxWork *work)
{
    void *h = ARC_TOOL_CreateHandle(7, 0x4C);
    work->iconAnimRes = (void *)CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), 0, 0x60, 0x4C);
    work->iconPlttImage = (void *)CLACT_RegisterCellAnim(h, POKE_TOOL_GetIconCellArcId(), POKE_TOOL_GetIconCellEntryId(), 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

void BOX2_SEQ_CreateBoxSlotActors(char *work)
{
    Box2SeqDesc d;
    Box2SeqDesc base = d_021EFD04;
    unsigned i;
    for (i = 0; i < 0x25; i++) {
        d = base;
        d.x += (short)((i % 6) * 24);
        d.y += (short)((i / 6) * 24);
        d.b6 = 0x75 - i * 2;
        d.a = i;
        *(void **)(work + i * 4 + 0x9F40) = BOX2_SEQ_CreateActorFromDesc(work, (const Box2SeqDesc *)&d);
        *(unsigned char *)(work + i + 0x3DD2) = i + 0x33;
    }
}

/*
 * Forward with a resolved handle and the object table entry.
 */
void *BOX2_SEQ_LoadGraphicResource(char *work, void *b, void *c)
{
    return ARC_UTIL_LoadScreenDataFromHandle((void *)(((BoxWork *)work)->arcHandle), POKE_TOOL_GetGraphicIndex(b), 0, (void *)(uptr)c, 0x4c);
}

void BOX2_SEQ_LoadMonIcon(char **task, int box)
{
    unsigned i;
    void *m;
    void *r;
    void *buf;
    for (i = 0; i < 0x1E; i++) {
        if (BOX_SAVEDATA_GetPokemonValue(((void **)task[0])[1], box, i, 0xA9, 0) == 0) {
            *(int *)(task[11] + i * 4 + 0x3DF8) = 0;
        } else if (((BoxParam *)task[0])->mode != 3 && ((unsigned char *)task)[0x14] == ((unsigned char *)task)[0x17]
                   && ((unsigned char *)task)[0x16] == i) {
            *(int *)(task[11] + i * 4 + 0x3DF8) = 0;
        } else {
            m = (void *)BOX2_MAIN_GetMonAt((void ***)task, box, i);
            r = BOX2_SEQ_LoadGraphicResource(task[11], m, &buf);
            MIi_CpuCopy32(((BoxArcRes *)(buf))->data, task[11] + 0x1B4 + i * 0x200, 0x200);
            GFL_HEAP_Free((void *)r);
            *(unsigned char *)(task[11] + i + 0x3DB4) = POKE_TOOL_GetIconPalette(m);
            *(int *)(task[11] + i * 4 + 0x3DF8) = 1;
        }
    }
}

/*
 * Stop the slot, re-key it and restart it.  Two facts pin this one:
 *   the second call's FIRST argument is the first call's RESULT (r0 is
 *   never overwritten), and the result must be a named local -- the
 *   nested spelling moves a and b to r6/r7 (r6=a) instead of the image's
 *   r7=a / r6=b, a 1-byte miss at +0x18.
 */
void BOX2_SEQ_SetSlotIconPal(char *work, int a, int i, int b)
{
    int v = CLACT_GetActorCharacterIndex((struct ClactActor *)((u8 *)(*(int *)(work + 0x9E74 + i * 4))));
    CLACT_TransferCharacterPart(v, (void *)a, 0x200, 0, 0);
    CLACT_SetActorPaletteOffset((struct ClactActor *)((struct Obj *)(*(int *)(work + 0x9E74 + i * 4))), (unsigned char)b, 1);
}

/*
 * Loads an icon resource for a, uploads it and frees the file.
 */
void BOX2_SEQ_LoadIconResource(BoxTask *task, void *a, int i)
{
    void *d;
    void *res = BOX2_SEQ_LoadGraphicResource(((char *)((BoxTask *)(task))->work), a, &d);
    BOX2_SEQ_SetSlotIconPal(((char *)((BoxTask *)(task))->work), (sptr)((BoxArcRes *)(d))->data, i, POKE_TOOL_GetIconPalette(a));
    GFL_HEAP_Free((void *)res);
}

/*
 * Hides window win, and when slot (box, pos) holds something shows its icon
 * there again.  The image narrows both the slot and the box to 16 bits
 * before BOX2_MAIN_GetPartyValueAt, so its box parameter is declared unsigned short here;
 * the callee body only forwards it and cannot show the width.
 */
void BOX2_SEQ_ShowSlotIcon(BoxTask *task, int box, int pos, int win)
{
    char *w = ((char *)((BoxTask *)(task))->work);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 0);
    if (BOX2_MAIN_GetPartyValueAt((void ***)task, pos, (unsigned short)box, 0xA9, 0)) {
        BOX2_SEQ_LoadIconResource((BoxTask *)task, (void *)BOX2_MAIN_GetMonAt((void ***)task, box, pos), win);
        BOX2_SEQ_SetActorDrawEnable((char *)w, win, 1);
    }
}

/*
 * Loop 0x1e entries forwarding (p[0x14], i, i+0x33).
 */
void BOX2_SEQ_ShowAllSlotIcons(BoxTask *task)
{
    unsigned i;
    for (i = 0; i < 0x1e; i++)
        BOX2_SEQ_ShowSlotIcon((BoxTask *)task, task->curBox, i, i + 0x33);
}

void BOX2_SEQ_ShowPartyIcons(BoxTask *task)
{
    unsigned n = POKEPARTY_GetCount(task->params->party);
    unsigned i;
    for (i = 0; i < n; i++) {
        BOX2_SEQ_LoadIconResource((BoxTask *)task, POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(task->params->party, i)),
                       *(unsigned char *)(*(char * *)&task->work + i + 0x3DF0));
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&task->work, *(unsigned char *)(*(char * *)&task->work + i + 0x3DF0), 0);
    }
}

void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode)
{
    if (i < 0x1E) {
        *x = (i % 6 + 1) * 0x18;
        *y = (i / 6) * 0x18 + 0x30;
        return;
    }
    i -= 0x1E;
    *x = d_021EFD4C[i].x;
    *y = d_021EFD4C[i].y - 0x90;
    if (mode == 2)
        *x += 0x98;
}

void BOX2_SEQ_HidePartialSlots(char **task, int flag)
{
    unsigned n = POKEPARTY_GetCount(((void **)task[0])[2]);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int k = *(unsigned char *)(task[11] + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(task[11], k, d_021EFD4C[i].x, d_021EFD4C[i].y, 0);
        BOX2_SEQ_SetSlotDrawPriority(task[11], i + 0x1E, 1);
        if (i < n && (flag == 0 || ((unsigned char *)task)[0x16] != i + 0x1E))
            BOX2_SEQ_SetActorDrawEnable(task[11], k, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(task[11], k, 0);
    }
}

/*
 * Lays out the six party-slot windows and shows the ones the party fills.
 * The window id is an int local: as unsigned char the load is scheduled after
 * the table address and 34 bytes move.
 */
void BOX2_SEQ_HideSlotsC61C(BoxTask *task)
{
    unsigned n = POKEPARTY_GetCount(task->params->party);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(((char *)((BoxTask *)(task))->work) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), win, (short)(d_021EFD4C[i].x + 0x98), (short)d_021EFD4C[i].y, (short)0);
        BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 0);
    }
}

void BOX2_SEQ_HideSlotsC688(BoxTask *task)
{
    unsigned n = POKEPARTY_GetCount(task->params->party);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(((char *)((BoxTask *)(task))->work) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), win, (short)d_021EFD4C[i].x, (short)(d_021EFD4C[i].y - 0x90), (short)0);
        BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 0);
    }
}

void BOX2_SEQ_HideSlotsC6F4(BoxTask *task)
{
    unsigned n = POKEPARTY_GetCount(task->params->party);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(((char *)((BoxTask *)(task))->work) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), win, (short)(d_021EFD4C[i].x + 0x98), (short)(d_021EFD4C[i].y - 0x90), (short)0);
        BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(task))->work), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), win, 0);
    }
}









void BOX2_SEQ_SetSlotDrawPriority(char *work, unsigned i, int flag)
{
    unsigned char c = *(unsigned char *)(work + i + 0x3DD2);
    if (flag == 0) {
        BOX2_SEQ_SetActorBgPriority((char *)work, c, 0);
        BOX2_SEQ_SetActorDrawPriority((char *)work, c, 0x14);
        return;
    }
    if (i < 0x1E || i == 0x24)
        BOX2_SEQ_SetActorBgPriority((char *)work, c, 3);
    else
        BOX2_SEQ_SetActorBgPriority((char *)work, c, 1);
    BOX2_SEQ_SetActorDrawPriority((char *)work, c, 0x75 - i * 2);
}

void BOX2_SEQ_SetSlotDrawPriorityB(char *work, int i, unsigned j, int flag)
{
    unsigned char c = *(unsigned char *)(work + i + 0x3DD2);
    if (flag == 0) {
        BOX2_SEQ_SetActorBgPriority((char *)work, c, 0);
        BOX2_SEQ_SetActorDrawPriority((char *)work, c, 0x14);
        return;
    }
    if (j < 0x1E)
        BOX2_SEQ_SetActorBgPriority((char *)work, c, 3);
    else
        BOX2_SEQ_SetActorBgPriority((char *)work, c, 1);
    BOX2_SEQ_SetActorDrawPriority((char *)work, c, 0x75 - j * 2);
}

void BOX2_SEQ_ShiftSlotIcons(char **work, short dx)
{
    short t[2];
    short reset;
    short lim;
    unsigned short i;
    unsigned char k;
    if (dx >= 0) {
        lim = 0xB0;
        reset = -8;
    } else {
        lim = -8;
        reset = 0xB0;
    }
    for (i = 0; i < 0x1E; i++) {
        k = *(unsigned char *)(work[11] + i + 0x3DD2);
        BOX2_SEQ_GetActorSurfacePos(work[11], k, &t[1], &t[0], 0);
        t[1] += dx;
        if (t[1] == lim) {
            t[1] = reset;
            BOX2_SEQ_SetSlotIconPal(work[11], (sptr)(work[11] + 0x1B4 + i * 0x200), k, *(unsigned char *)(work[11] + i + 0x3DB4));
            BOX2_SEQ_SetActorDrawEnable(work[11], k, *(int *)(work[11] + i * 4 + 0x3DF8));
            if (((BoxWork *)work[11])->busyFlag == 0 && (((BoxParam *)work[0])->mode == 3 || ((BoxParam *)work[0])->mode == 5))
                BOX2_SEQ_SetActorMode1((char *)work, i);
        }
        BOX2_SEQ_AddActorSurfacePos(work[11], k, t[1], t[0], 0);
    }
}

void BOX2_SEQ_MoveActorToWindow(BoxTask *task)
{
    signed char buf[2];
    unsigned short i;
    short x, y;
    BGWINFRM_GetPos(*(struct BgWinFrmWork * *)&task->work->winMgr, 8, &buf[1], &buf[0]);
    x = buf[0] * 8;
    y = buf[1] * 8;
    for (i = 0; i < 6; i++)
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&task->work, *(unsigned char *)(*(char * *)&task->work + i + 0x3DF0),
                      (short)(y + d_021EFCE0[i].a), (short)(x + d_021EFCE0[i].b), (short)0);
}

void BOX2_SEQ_ResetActorAffine(char *actorScale)
{
    int pair[2];
    unsigned short shape[2];
    *(float *)(actorScale + 8) = 4096.0f;
    actorScale[7] = 0;
    CLACT_SetActorAffineMode((struct ClactActor *)(*(void **)actorScale), 1);
    pair[0] = (int)*(float *)(actorScale + 8);
    pair[1] = (int)*(float *)(actorScale + 8);
    CLACT_SetActorScale((struct ClactActor *)(*(void **)actorScale), (struct Pair32 *)((struct Box2SeqPair *)pair));
    shape[0] = 0;
    shape[1] = 8;
    CLACT_SetActorAffineOrigin(*(void **)actorScale, (const struct Pt16 *)shape);
}

int BOX2_SEQ_ShrinkActor(char *actorScale)
{
    int pair[2];
    (((BoxActorScale *)(actorScale))->step)++;
    *(float *)(actorScale + 8) -= 102.0f;
    if ((unsigned char)actorScale[7] == 40)
        return 0;
    pair[0] = (int)*(float *)(actorScale + 8);
    pair[1] = (int)*(float *)(actorScale + 8);
    CLACT_SetActorScale((struct ClactActor *)(*(void **)actorScale), (struct Pair32 *)((struct Box2SeqPair *)pair));
    return 1;
}

int BOX2_SEQ_GrowActor(char *actorScale)
{
    int pair[2];
    ((BoxActorScale *)(actorScale))->step -= 2;
    *(float *)(actorScale + 8) += 102.0f;
    *(float *)(actorScale + 8) += 102.0f;
    if ((unsigned char)actorScale[7] == 0)
        return 0;
    pair[0] = (int)*(float *)(actorScale + 8);
    pair[1] = (int)*(float *)(actorScale + 8);
    CLACT_SetActorScale((struct ClactActor *)(*(void **)actorScale), (struct Pair32 *)((struct Box2SeqPair *)pair));
    return 1;
}

/*
 * Zero*p through the pool, then run the sibling teardown.
 */
void BOX2_SEQ_HideActor(int *actor)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)((struct Obj *)*actor), 0);
    BOX2_SEQ_ResetActorTransform((int *)actor);
}

/*
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * CLACT_SetActorScale.c, shard pkt_0204B5AC), so the call at +0022 attests as
 * `matched`.  Every concrete byte matches; the extent ran long because the
 * follower has no func_ label.
 */
void BOX2_SEQ_ResetActorTransform(int *actor)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    CLACT_SetActorAffineOrigin((struct ClactActor *)(*actor), (const struct Pt16 *)s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    CLACT_SetActorScale((struct ClactActor *)((struct Obj *)(*actor)), (struct Pair32 *)((struct Box2SeqPair *)s.b));
    CLACT_SetActorAffineMode((struct ClactActor *)(*actor), 0);
}

void BOX2_SEQ_SetSlotActorsMode(BoxTask *task, int flag, int i, unsigned end, int mode)
{
    if (mode == 1) {
        if (task->params->mode == 5) {
            for (; i < end; i++) {
                if (BOX2_MAIN_GetBoxValue((char *)task, i) == 1 && BOX2_MAIN_GetPartyValueAt((void ***)task, i, task->curBox, 0x4C, 0) == 0)
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->cursorTable[i]), 0);
                else
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->cursorTable[i]), 1);
            }
        } else {
            for (; i < end; i++) {
                if (BOX2_MAIN_GetPartyValueAt((void ***)task, i, task->curBox, 6, 0) == 0)
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->cursorTable[i]), 1);
                else
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->cursorTable[i]), 0);
            }
        }
    } else {
        for (; i < end; i++)
            BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(task))->work), (((BoxTask *)(task))->work->cursorTable[i]), flag);
    }
}

/*
 * Dispatch flag bits 1 and 2 to the two range halves, with bit
 *   0x80 selecting the sub-range selector.  Matches on the tst-based ternary.
 */
void BOX2_SEQ_SetSlotActors(char *task, int f, int c)
{
    int t = (f & 0x80) ? 1 : 0;
    if (f & 1)
        BOX2_SEQ_SetSlotActorsMode((BoxTask *)task, c, 0, 0x1e, t);
    if (f & 2)
        BOX2_SEQ_SetSlotActorsMode((BoxTask *)task, c, 0x1e, 0x25, t);
}

/*
 * Forward the byte at the pooled table offset.  The callee takes three
 * arguments, so the forwarded byte is argument 1 and the passing flag
 * stays in r2 untouched; that is what forces the sum into r3.
 */
void BOX2_SEQ_SetSlotActorMode(char *work, int i, int f)
{
    BOX2_SEQ_SetActorObjMode((char *)work, *(unsigned char *)(work + i + 0x3DD2), f);
}

/*
 * One range call with the selector pair fixed.
 */
void BOX2_SEQ_SetActorMode1(char *a, int b)
{
    BOX2_SEQ_SetSlotActorsMode((BoxTask *)a, 1, b, b + 1, 1);
}

void BOX2_SEQ_SwapSlotActors(char *w, unsigned i)
{
    short xy[2];
    unsigned char *tbl = (unsigned char *)(w + 0x3DD2);
    unsigned char t;
    BOX2_SEQ_GetActorSurfacePos((char *)w, tbl[i], &xy[1], &xy[0], 0);
    t = w[0x3DF6];
    w[0x3DF6] = tbl[i];
    tbl[i] = t;
    BOX2_SEQ_AddActorSurfacePos((char *)w, tbl[i], xy[1], xy[0], 0);
    BOX2_SEQ_SetSlotDrawPriority((char *)w, i, 1);
}

void BOX2_SEQ_SwapSlotActorsB(unsigned char *work, int i)
{
    short xy[2];
    unsigned char t;
    BOX2_SEQ_GetActorSurfacePos((char *)work, work[0x3DF6], &xy[1], &xy[0], 0);
    t = (work + 0x3DD2)[i];
    (work + 0x3DD2)[i] = work[0x3DF6];
    work[0x3DF6] = t;
    BOX2_SEQ_AddActorSurfacePos((char *)work, work[0x3DF6], xy[1], xy[0], 0);
}







void BOX2_SEQ_RefreshHandSlot(BoxTask *task)
{
    short xy[2];
    int k;
    if (task->handMode == 0)
        return;
    BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(task))->work), 4, &xy[1], &xy[0], 0);
    if ((*(Top * *)&task->params)->mode == 3) {
        k = 0xA;
        xy[0] += 8;
    } else {
        k = *(unsigned char *)(((char *)((BoxTask *)(task))->work) + 0x3DF6);
        xy[0] += 4;
    }
    BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(task))->work), k, xy[1], xy[0], 0);
    if ((*(Top * *)&task->params)->mode == 3) {
        BOX2_SEQ_LayoutHandSlots(((char *)((BoxTask *)(task))->work));
        return;
    }
    if (*(void **)(((char *)((BoxTask *)(task))->work) + 0x9FD4) == 0)
        BOX2_SEQ_RefreshCursorSlot(task);
    BOX2_SEQ_MoveCursorToSlot(((char *)((BoxTask *)(task))->work), 0x24);
}

/*
 * candidate BOX2_SEQ_InitIconSlots: clear six ints
 */
void BOX2_SEQ_InitIconSlots(BoxWork *work)
{
    work->iconChar[0] = -1;
    work->iconCell[0] = -1;
    work->iconAnim[0] = -1;
    work->iconChar[1] = -1;
    work->iconCell[1] = -1;
    work->iconAnim[1] = -1;
}

/*
 * prototype: 0202D7C8 reads and forwards only r0; legacy r1-r3 omitted.
 * prototype: 0202D8D0 stack mode is full-width in this caller, with no
 * truncation; its callee forwards the same low-halfword value.
 */
void BOX2_SEQ_LoadMonIconActor(char *task,void **mon,int index)
{
    int *bmp,*cell,*anim;
    int other;
    int mode;
    sptr archive; int state;
    if (*(u16 *)(((char *)((BoxTask *)(task))->work)+0xA164)==0) {
        bmp=(int *)(((char *)((BoxTask *)(task))->work)+0xA088);cell=(int *)(((char *)((BoxTask *)(task))->work)+0xA10C);
        anim=(int *)(((char *)((BoxTask *)(task))->work)+0xA138);mode=96;other=index+1;
    } else {
        bmp=(int *)(((char *)((BoxTask *)(task))->work)+0xA08C);cell=(int *)(((char *)((BoxTask *)(task))->work)+0xA110);
        anim=(int *)(((char *)((BoxTask *)(task))->work)+0xA13C);mode=128;other=index;index++;
    }
    if (*(void **)((((char *)((BoxTask *)(task))->work)+index*4)+0x9E74)) {
        CLACT_DeleteActor((struct ClactActor *)(*(void **)((((char *)((BoxTask *)(task))->work)+index*4)+0x9E74)));
        CLACT_ReleaseCharacter(*bmp);CLACT_ReleasePalette(*cell);CLACT_ReleaseCellAnim(*anim);
    }
    archive=(sptr)POKEGRA_OpenHandle(76);
    state=POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)(*mon));
    *bmp=POKEGRA_RegisterCgrPP(archive,(void *)(*mon),0,1,76);
    *cell=POKEGRA_RegisterPalettePP(archive,(void *)(*mon),0,1,mode,76);
    *anim=POKEGRA_RegisterCellAnimPP((void *)((uptr)*mon),0,2,1,76);
    POKE_TOOL_EncodeBoxParam(*mon,state);ARC_TOOL_DeleteHandle((void *)archive);
    *(void **)((((char *)((BoxTask *)(task))->work)+index*4)+0x9E74)=BOX2_SEQ_CreateActorFromDesc(((char *)((BoxTask *)(task))->work), &((const Box2SeqDesc *)&d_021EFD80)[(u32)index]);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work),index,1);
    if (*(void **)((((char *)((BoxTask *)(task))->work)+other*4)+0x9E74)) BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work),other,0);
    *(u16 *)(((char *)((BoxTask *)(task))->work)+0xA164)^=1;
}





/*
 * Loads the box screen graphics from the shared archive into the work
 * slots at 0xA094 (seventeen palettes) and 0xA0FC..0xA160 (character,
 * cell and animation resources), then closes the archive.
 */
void BOX2_SEQ_LoadBoxScreen(char *w)
{
    void *h;
    unsigned i;

    h = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x804C);
    for (i = 0; i < 0x11; i++)
        *(void **)(w + i * 4 + 0xA094) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetTypeCellFileId((unsigned char)i), (int)0, (int)1, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA144))) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetTypePaletteFileId(2), APP_ICON_GetTypeAnimFileId(2), 0x4C);
    (*(void **)((char *)(w) + (0xA118))) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetTouchBarFileId(), 1, 0, 0x4C);
    (*(void **)((char *)(w) + (0xA100))) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetEffectCellFileId(2), (int)0, (int)1, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA15C))) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetEffectPaletteFileId(2), APP_ICON_GetEffectAnimFileId(2), 0x4C);
    (*(void **)((char *)(w) + (0xA12C))) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetBallOpenAnimFileId(), 1, 0xA0, 0x4C);
    (*(void **)((char *)(w) + (0xA104))) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetGearExtraFileId(2), (int)0, (int)1, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA160))) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetGearFrameFileId(2), APP_ICON_GetGearAnim2FileId(2), 0x4C);
    (*(void **)((char *)(w) + (0xA130))) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetGearDataFileId(), 1, 0xC0, 0x4C);
    (*(void **)((char *)(w) + (0xA0FC))) = (void *)CLACT_RegisterCharacter(h, APP_ICON_GetEffectCellFileId(2), (int)0, (int)0, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA158))) = (void *)CLACT_RegisterCellAnim(h, APP_ICON_GetEffectPaletteFileId(2), APP_ICON_GetEffectAnimFileId(2), 0x4C);
    (*(void **)((char *)(w) + (0xA128))) = (void *)CLACT_RegisterPalette(h, APP_ICON_GetBallOpenAnimFileId(), 0, 0x1A0, 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Verified scratch-only with one --thumb, no --region: EXACT, 12 bytes.
 * symbols for blocker: _PokeTypePltOffset 0x0209FCF8 data a1
 * extern const unsigned char _PokeTypePltOffset[];
 * unsigned APP_ICON_GetTypePaletteOffset(unsigned char i) { return _PokeTypePltOffset[i]; }
 */
void BOX2_SEQ_CreateHandSlotActors(char *work)
{
    Box2SeqDesc d = d_021EFD34;
    unsigned i;
    for (i = 0; i < 0x11; i++) {
        d.a = i + 0x28;
        *(void **)(work + i * 4 + 0x9EE4) = BOX2_SEQ_CreateActorFromDesc(work, (const Box2SeqDesc *)&d);
        CLACT_SetActorPaletteOffset(*(void **)(work + i * 4 + 0x9EE4), (unsigned)APP_ICON_GetTypePaletteOffset((unsigned char)i), 1);
        BOX2_SEQ_SetActorDrawEnable((char *)work, i + 0x1C, 0);
    }
}




void BOX2_SEQ_ShowHandSlot(char *work, int a, int b)
{
    int k = a + 0x1c;
    BOX2_SEQ_SetActorDrawEnable((char *)work, k, 1);
    BOX2_SEQ_AddActorSurfacePos((char *)work, k, 0x58, 0x38, 1);
    if (b != 0 && a != b) {
        k = b + 0x1c;
        BOX2_SEQ_SetActorDrawEnable((char *)work, k, 1);
        BOX2_SEQ_AddActorSurfacePos((char *)work, k, 0x7a, 0x38, 1);
    }
}

/*
 * lever: Byte bitfield access reproduces the original ldrb/lsl24/lsr31
 * at 0x021ED042..0x021ED046; a mask test emitted movs/tst instead.
 */
void BOX2_SEQ_ShowHandSlotB(struct BoxWork *work, unsigned char *q){unsigned i;for(i=28;i<45;i++)BOX2_SEQ_SetActorDrawEnable((char *)work,i,0);if(!((Flag *)(q+18))->high)BOX2_SEQ_ShowHandSlot((char *)work,q[12],q[13]);}

void BOX2_SEQ_LoadIconPalette(u8*work){void*h;h=ARC_TOOL_CreateHandle(25,76);*(void* *)&((BoxWork *)work)->iconPlttRes=(void *)CLACT_RegisterPalette(h,FILE_UTIL_Get(0,2),0,0x180,76);ARC_TOOL_DeleteHandle(h);}

void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = ARC_UTIL_LoadScreenDataFromArchive(FILE_UTIL_GetItemCount(), FILE_UTIL_Get(item, 1), 0, (void *)(uptr)(&a), 0x4C);
    CLACT_TransferCharacter(CLACT_GetActorCharacterIndex(((BoxWork *)w)->cursorActor), a);
    GFL_HEAP_Free((void *)q);
    q = ARC_UTIL_LoadPaletteBlockFromArchive(FILE_UTIL_GetItemCount(), FILE_UTIL_Get(item, 2), (void *)(uptr)(&b), 0x4C);
    CLACT_TransferPalette(CLACT_GetActorPaletteIndex(((BoxWork *)w)->cursorActor), b, 1);
    GFL_HEAP_Free((void *)q);
}

void BOX2_SEQ_SetActorAffineMode(char *work, int on)
{
    unsigned short s[2];
    if (on == 1) {
        CLACT_SetActorAffineMode((struct ClactActor *)(((BoxWork *)(work))->cursorActor), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        CLACT_SetActorAffineOrigin((struct ClactActor *)(((BoxWork *)(work))->cursorActor), (const struct Pt16 *)s);
    } else {
        s[0] = 0;
        s[1] = 0;
        CLACT_SetActorAffineOrigin((struct ClactActor *)(((BoxWork *)(work))->cursorActor), (const struct Pt16 *)s);
        CLACT_SetActorAffineMode((struct ClactActor *)(((BoxWork *)(work))->cursorActor), 0);
    }
}

/*
 * One range call with the sub-range selector.
 */
void BOX2_SEQ_MoveActor(void *a, int b, int c)
{
    BOX2_SEQ_AddActorSurfacePos((char *)a, 10, b, c, 0);
}

/*
 * Twin of BOX2_SEQ_MoveActorToSlotB with both shorts biased by 8.
 */
void BOX2_SEQ_MoveActorToSlot(char *actor, int a, int c)
{
    short t[2];
    BOX2_SEQ_GetSlotPos(a, t + 1, t, c);
    BOX2_SEQ_MoveActor(actor, (short)(t[1] + 8), (short)(t[0] + 8));
}

/*
 * Read the 2-short record for the sub-range then push it back with
 *   the first element biased by 4.
 */
void BOX2_SEQ_MoveActorToSlotB(char *actor, int a, int c)
{
    short t[2];
    BOX2_SEQ_GetSlotPos(a, t + 1, t, c);
    BOX2_SEQ_MoveActor(actor, t[1], (short)(t[0] + 4));
}

static inline void setup(Box2SeqDesc *dp, void **res)
{
    dp->b6 = CLACT_GetActorDrawPriority((struct ClactActor *)((sptr)(*res))) + 1;
    dp->b7 = CLACT_GetActorBgPriority(*res);
}

/*
 * Sibling of src/matched/ov/BOX2_SEQ_MoveCursorActor.c: builds (or moves) the
 * eight frame pieces around window 10 while the count at 0xA16C is nonzero.
 * The index is an int compared against 8u (docs/idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md).
 */
void BOX2_SEQ_CreateHandSlotActorsB(char *w)
{
    int j;
    Box2SeqDesc d;
    short xy[2];
    if (((BoxWork *)w)->counter == 0)
        return;
    j = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)w, 10, &xy[1], &xy[0], 0);
    if (((BoxWork *)w)->actorResource == 0) {
        d = d_021EFE70;
        setup(&d, (void **)(w + 0x9E9C));
        d.a = 0x27;
        d.b = 6;
        d.e = 1;
        for (; j < 8u; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = BOX2_SEQ_CreateActorFromDesc(w, &d);
            CLACT_SetActorPaletteOffset(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
            BOX2_SEQ_SetActorDrawEnable((char *)w, j + 0x58, 0);
        }
    } else {
        int n6 = CLACT_GetActorDrawPriority((struct ClactActor *)((sptr)(((BoxWork *)w)->cursorActor)));
        int n7 = CLACT_GetActorBgPriority(((BoxWork *)w)->cursorActor);
        for (; j < 8u; j++) {
            BOX2_SEQ_AddActorSurfacePos((char *)w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            BOX2_SEQ_SetActorDrawPriority((char *)w, j + 0x58, n6 + 1);
            BOX2_SEQ_SetActorBgPriority((char *)w, j + 0x58, n7);
            BOX2_SEQ_SetActorDrawEnable((char *)w, j + 0x58, 0);
        }
    }
}

/*
 * Loop 8 entries forwarding (i+0x58, 1).
 */
void BOX2_SEQ_ShowHandSlots(char *work)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        BOX2_SEQ_SetActorDrawEnable((char *)work, i + 0x58, 1);
}

void BOX2_SEQ_LayoutHandSlots(char *w)
{
    short xy[2];
    unsigned i;
    if (((BoxWork *)w)->actorResource != 0) {
        i = 0;
        BOX2_SEQ_GetActorSurfacePos((char *)w, 0xA, &xy[1], &xy[0], 0);
        for (; i < 8; i++)
            BOX2_SEQ_AddActorSurfacePos((char *)w, i + 0x58, (short)(xy[1] + d_021EFCD0[i]), (short)(xy[0] + d_021EFCC8[i]), (short)0);
    }
}

/*
 * Builds the cell objects of the box screen from the descriptor table
 * at 0x021EFD80 into the work slots at 0x9E74, hides five of them, then
 * refreshes the cursor.  The loop rows are addressed as a byte offset
 * (i * 0x18 + 0x138) from the table base: both the member form .b[i] and
 * the index form [i + 13] fold the row offset into the literal instead.
 */
void BOX2_SEQ_CreateCursorObjects(BoxTask *task)
{
    char *w = ((char *)((BoxTask *)(task))->work);
    unsigned i;

    (((BoxWork *)(w))->actors[0]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[0]);
    (((BoxWork *)(w))->actors[1]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[1]);
    (((BoxWork *)(w))->actors[2]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[2]);
    (((BoxWork *)(w))->actors[3]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[3]);
    (((BoxWork *)(w))->actors[4]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[4]);
    (((BoxWork *)(w))->actors[5]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[5]);
    (((BoxWork *)(w))->actors[10]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[10]);
    (((BoxWork *)(w))->actors[6]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[6]);
    (((BoxWork *)(w))->actors[7]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[7]);
    (((BoxWork *)(w))->actors[8]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[8]);
    (((BoxWork *)(w))->actors[9]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.a[9]);
    for (i = 0; i < 6; i++) {
        *(void **)(w + i * 4 + 0x9EA8) = BOX2_SEQ_CreateActorFromDesc(w, (const Box2SeqDesc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x138)));
        *(void **)(w + i * 4 + 0x9EC0) = BOX2_SEQ_CreateActorFromDesc(w, (const Box2SeqDesc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x1C8)));
    }
    (((BoxWork *)(w))->actors[25]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[0]);
    (((BoxWork *)(w))->actors[26]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[1]);
    (((BoxWork *)(w))->actors[27]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[2]);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 5, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 10, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 0x19, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 0x1A, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 0x1B, 0);
    BOX2_SEQ_SetWindow9((BoxTask *)task, 0xE, 1);
}

/*
 * Sets window 9's frame and mode; outside modes 2, 3 and 4 the mode is
 * cleared again.
 */
void BOX2_SEQ_SetWindow9(BoxTask *task, int a, int b)
{
    int kind;
    BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(task))->work), 9, a);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 9, b);
    kind = task->params->mode;
    if (kind != 2 && kind != 4 && kind != 3)
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(task))->work), 9, 0);
}

/*
 * Offset by four when the low nibble of 0x1c is set.
 */
void BOX2_SEQ_SetCursorFrame(BoxTask *task, int b)
{
    if (((struct Box2SeqSlot *)task)->f)
        b += 4;
    BOX2_SEQ_SetActorAnimSeq(*(char * *)&task->work, 4, b);
}

void BOX2_SEQ_SetCursorDraw(char **work, int flag)
{
    if (flag == 1) {
        if (CURSOR_MOVE_GetState(((BoxWork *)work[11])->cursorMove) == 1)
            BOX2_SEQ_SetActorDrawEnable(work[11], 4, 1);
    } else {
        BOX2_SEQ_SetActorDrawEnable(work[11], 4, 0);
    }
}

/*
 * Forward with the byte field at +0x16.
 */
void BOX2_SEQ_RefreshCursorSlot(BoxTask *task)
{
    BOX2_SEQ_MoveCursorActor((BoxTask *)task, task->cursorSlot);
}

void BOX2_SEQ_MoveCursorActor(BoxTask *task, unsigned i)
{
    char *w;
    unsigned c;
    unsigned short j;
    Box2SeqDesc d;
    Struct36 buf;
    short xy[2];
    if (i == 0xFF)
        return;
    w = *(char * *)&task->work;
    c = *(unsigned char *)(w + i + 0x3DD2);
    j = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)w, c, &xy[1], &xy[0], 0);
    if (((BoxWork *)w)->actorResource == 0) {
        d = d_021EFD04;
        setup(&d, &((void **)(w + 0x9E74))[c]);
        d.a = c - 0x33;
        d.b = 6;
        d.e = 1;
        for (; j < 8; j++) {
            d.x = xy[1] + d_021EFCD0[j];
            d.y = xy[0] + d_021EFCC8[j];
            *(void **)(w + j * 4 + 0x9FD4) = BOX2_SEQ_CreateActorFromDesc(w, &d);
            CLACT_SetActorPaletteOffset(*(void **)(w + j * 4 + 0x9FD4), (unsigned char)d.e, 1);
        }
    } else {
        int n6;
        int n7;
        CLACT_GetActorImageProxy((const char *)(((void **)(w + 0x9E74))[c]), (struct ImageProxy *)((struct Struct36 *)(&buf)));
        n6 = CLACT_GetActorDrawPriority((struct ClactActor *)((sptr)(((void **)(w + 0x9E74))[c])));
        n7 = CLACT_GetActorBgPriority((struct ClactActor *)(((void **)(w + 0x9E74))[c]));
        for (; j < 8; j++) {
            CLACT_SetActorImageProxy((char *)(*(void **)(w + j * 4 + 0x9FD4)), (const struct ImageProxy *)((const struct Struct36 *)(&buf)));
            BOX2_SEQ_AddActorSurfacePos((char *)w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            BOX2_SEQ_SetActorDrawPriority((char *)w, j + 0x58, n6 + 1);
            BOX2_SEQ_SetActorBgPriority((char *)w, j + 0x58, n7);
            BOX2_SEQ_SetActorDrawEnable((char *)w, j + 0x58, 1);
        }
    }
}

void BOX2_SEQ_SetSlotDim(char **task, int v)
{
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(task[11] + j * 4 + 0x9FD4) != 0) {
            BOX2_SEQ_SetActorDrawEnable((char *)task[11], j + 0x58, v);
            if (v == 1 && ((unsigned char *)task)[0x16] != 0xFF) {
                unsigned char k = *(unsigned char *)(task[11] + ((unsigned char *)task)[0x16] + 0x3DD2);
                BOX2_SEQ_SetActorDrawPriority((char *)task[11], j + 0x58, CLACT_GetActorDrawPriority((struct ClactActor *)(*(int *)(task[11] + k * 4 + 0x9E74))) + 1);
                BOX2_SEQ_SetActorBgPriority((char *)task[11], j + 0x58, CLACT_GetActorBgPriority((struct ClactActor *)((u8 *)(*(int *)(task[11] + k * 4 + 0x9E74)))));
            }
        }
    }
}

void BOX2_SEQ_SetSlotDimB(char **task, int i)
{
    unsigned char k = *(unsigned char *)(task[11] + i + 0x3DD2);
    int a = CLACT_GetActorDrawPriority((struct ClactActor *)(*(int *)(task[11] + k * 4 + 0x9E74)));
    int b = CLACT_GetActorBgPriority((struct ClactActor *)((u8 *)(*(int *)(task[11] + k * 4 + 0x9E74))));
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(task[11] + j * 4 + 0x9FD4) != 0 && ((unsigned char *)task)[0x16] != 0xFF) {
            BOX2_SEQ_SetActorDrawPriority(task[11], j + 0x58, a + 1);
            BOX2_SEQ_SetActorBgPriority(task[11], j + 0x58, b);
        }
    }
}

void BOX2_SEQ_MoveCursorToSlot(char *work, int i)
{
    short xy[2];
    int j;
    if (i == 0xFF)
        return;
    j = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)work, *(unsigned char *)(work + i + 0x3DD2), &xy[1], &xy[0], j);
    for (; j < 8u; j++)
        BOX2_SEQ_AddActorSurfacePos((char *)work, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
}
