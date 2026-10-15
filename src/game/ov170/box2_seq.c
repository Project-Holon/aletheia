/*
 * file:     box2_seq.c
 * unit:     yes
 * function: BOX2_SEQ_StateMenuSelect, BOX2_SEQ_StateMenuSwap, BOX2_SEQ_StateMenuMain, BOX2_SEQ_StateMachineMove, BOX2_SEQ_StateExitBox, BOX2_SEQ_OpenBoxUp, BOX2_SEQ_OpenBoxDown, BOX2_SEQ_OpenBoxLeft, BOX2_SEQ_OpenBoxRight, BOX2_SEQ_StateMachineScroll, BOX2_SEQ_UpdatePrintQueue, BOX2_SEQ_CreateBox2Main, BOX2_SEQ_DeleteBox2Main, BOX2_SEQ_StateWaitWipe, BOX2_SEQ_StateWaitFade, BOX2_SEQ_StateWaitCount, BOX2_SEQ_StateRunStep, BOX2_SEQ_StateWaitInput, BOX2_SEQ_StateTaskMenu, BOX2_SEQ_StateCheckTaskMenu, BOX2_SEQ_StateDispatchFont, BOX2_SEQ_StateDispatchStep, BOX2_SEQ_DeleteBox2Ui, BOX2_SEQ_StateWaitPrint, BOX2_SEQ_StateSetMenu, BOX2_SEQ_StateItemMenu, BOX2_SEQ_SetBox2Main, BOX2_SEQ_StateCloseBox, BOX2_SEQ_StateBoxMenu, BOX2_SEQ_StateOpenSummary, BOX2_SEQ_SetBox2Ui, BOX2_SEQ_StateSummary, BOX2_SEQ_StateSummaryInput, BOX2_SEQ_StateSummaryClose, BOX2_SEQ_StateSwapMenu, BOX2_SEQ_StateSwapConfirm, BOX2_SEQ_StateSwapApply, BOX2_SEQ_StateSwapFinish, BOX2_SEQ_StateMoveMove, BOX2_SEQ_StateMoveFinish, BOX2_SEQ_SetBox2UiB, BOX2_SEQ_StateOpenSummaryB, BOX2_SEQ_StateSummaryB, BOX2_SEQ_StateMoveInput, BOX2_SEQ_StateMoveClose, BOX2_SEQ_StateMoveCloseB, BOX2_SEQ_StateItemMenuB, BOX2_SEQ_StateOpenItemB, BOX2_SEQ_SetBox2UiC, BOX2_SEQ_StateSwapMenuB, BOX2_SEQ_StateItemMoveB, BOX2_SEQ_StateMoveFinishB, BOX2_SEQ_SetBox2UiD, BOX2_SEQ_StateOpenItemC, BOX2_SEQ_StateMenuCursor, BOX2_SEQ_StateItemMenuC, BOX2_SEQ_SetBox2MainB, BOX2_SEQ_StateCloseBoxB, BOX2_SEQ_StateOpenBoxC, BOX2_SEQ_DeleteBox2UiB, BOX2_SEQ_StateItemMenuD, BOX2_SEQ_SetBox2MainC, BOX2_SEQ_StateCursorMove, BOX2_SEQ_StateSummaryC, BOX2_SEQ_StateListScroll, BOX2_SEQ_StateScrollBox, BOX2_SEQ_StateOpenItemD, BOX2_SEQ_StateOpenItemE, BOX2_SEQ_StateItemMenuE, BOX2_SEQ_SetBox2UiE, BOX2_SEQ_DeleteBox2UiC, BOX2_SEQ_StateCloseBoxC, BOX2_SEQ_StateMenuItems, BOX2_SEQ_StateSelectItem, BOX2_SEQ_StateSummaryD, BOX2_SEQ_StateItemMenuF, BOX2_SEQ_StateCloseItem, BOX2_SEQ_StateMoveItemScroll, BOX2_SEQ_StateMoveItemB, BOX2_SEQ_StateCloseItemB, BOX2_SEQ_StatePlaceItem, BOX2_SEQ_StateCursorMoveB, BOX2_SEQ_SetBox2UiF, BOX2_SEQ_StateMoveItemC, BOX2_SEQ_StatePlaceItemB, BOX2_SEQ_StateMoveItemD, BOX2_SEQ_StateCursorMoveC, BOX2_SEQ_StatePushSlot, BOX2_SEQ_StateSwapMenuC, BOX2_SEQ_SetBox2MainD, BOX2_SEQ_StateCloseItemC, BOX2_SEQ_StateSwapMenuD, BOX2_SEQ_SetBox2MainE, BOX2_SEQ_StateSwapFinishB, BOX2_SEQ_StateCloseItemD, BOX2_SEQ_StateExitToField, BOX2_SEQ_StateSwapMenuE, BOX2_SEQ_StateCloseMenu, BOX2_SEQ_StateSummaryE, BOX2_SEQ_StateDeleteHandle, BOX2_SEQ_StateMoveItemE, BOX2_SEQ_StateCloseZoom, BOX2_SEQ_StateMoveItemF, BOX2_SEQ_StateOpenZoom, BOX2_SEQ_StateZoomMenu, BOX2_SEQ_StateClosePmVoice, BOX2_SEQ_StateMoveMenu, BOX2_SEQ_StateMoveMenuB, BOX2_SEQ_StatePmVoiceMenu, BOX2_SEQ_StatePmVoiceConfirm, BOX2_SEQ_StateSetMiniIcon, BOX2_SEQ_StateMoveMenuC, BOX2_SEQ_StateClosePmVoiceB, BOX2_SEQ_StateFadeBox, BOX2_SEQ_StateCloseItemE, BOX2_SEQ_HideCursorSlot, BOX2_SEQ_ReturnAfterClear, BOX2_SEQ_StartWipeWhite, BOX2_SEQ_StartWipeBlack, BOX2_SEQ_SetSeqThird, BOX2_SEQ_SetSeqSecond, BOX2_SEQ_SetState, BOX2_SEQ_OpenYesNo, BOX2_SEQ_StateUseItem, BOX2_SEQ_StateUseItemWait, BOX2_SEQ_StateUseItemDone, BOX2_SEQ_StateUseItemMenu, BOX2_SEQ_StatePlayCry, BOX2_SEQ_StateCloseItemMenu, BOX2_SEQ_SaveMenuPosAndExit, BOX2_SEQ_StatePmVoiceClose, BOX2_SEQ_StateEnterItemMenu, BOX2_SEQ_GotoBox2Main, BOX2_SEQ_GetBgFrameY, BOX2_SEQ_GotoBox2MainWithSlot, BOX2_SEQ_GotoBox2Ui, BOX2_SEQ_StatePmVoiceMenuB, BOX2_SEQ_StatePmVoiceMenuC, BOX2_SEQ_StatePmVoiceMenuD, BOX2_SEQ_StatePmVoiceOpen, BOX2_SEQ_StatePmVoiceOpenB, BOX2_SEQ_StatePmVoiceOpenC, BOX2_SEQ_StatePmVoiceOpenD, BOX2_SEQ_GotoRightPanelA, BOX2_SEQ_GotoRightPanelB, BOX2_SEQ_SelectSlotA, BOX2_SEQ_SelectSlotB, BOX2_SEQ_SelectSlotC, BOX2_SEQ_GotoSlotHandlerA, BOX2_SEQ_SelectPartySlotA, BOX2_SEQ_SelectPartySlotB, BOX2_SEQ_SelectPartySlotC, BOX2_SEQ_GotoSlotHandlerB, BOX2_SEQ_SelectSlotD, BOX2_SEQ_HideSlotWindow, BOX2_SEQ_SelectBoxSlot, BOX2_SEQ_ScrollListToSlot, BOX2_SEQ_Create, BOX2_SEQ_Delete, BOX2_SEQ_DrawGridSlot, BOX2_SEQ_SetCursorMove, BOX2_SEQ_SelectGridSlot, BOX2_SEQ_DrawGridSlotB, BOX2_SEQ_UpdateGridCursor, BOX2_SEQ_MoveGridCursor, BOX2_SEQ_DeleteGridSlot, BOX2_SEQ_SetCursorMoveB, BOX2_SEQ_CreateB, BOX2_SEQ_DeleteB, BOX2_SEQ_StopLeftBar, BOX2_SEQ_StopRightBar, BOX2_SEQ_RestartLeftBar, BOX2_SEQ_DrawListSlot, BOX2_SEQ_CreateC, BOX2_SEQ_ResetEntry, BOX2_SEQ_ResetEntryB, BOX2_SEQ_SetActorAnim, BOX2_SEQ_CheckTradableMon, BOX2_SEQ_ToggleHandSlot, BOX2_SEQ_GotoSceneA, BOX2_SEQ_DeleteSlotWindows, BOX2_SEQ_GotoBox2MainPlaySe, BOX2_SEQ_GotoBox2MainNoSe, BOX2_SEQ_InitBmpWins, BOX2_SEQ_DeleteBmpWins, BOX2_SEQ_SetDirtyBit, BOX2_SEQ_FlushDirtyBmpWins, BOX2_SEQ_UpdateTextWins, BOX2_SEQ_MakeScreen, BOX2_SEQ_ClearScreen, BOX2_SEQ_PrintTextWin, BOX2_SEQ_PrintTextWinEx, BOX2_SEQ_CreateMsgBank, BOX2_SEQ_PrintMsgWin, BOX2_SEQ_InitBmpWin, BOX2_SEQ_FillTextWinEntry, BOX2_SEQ_FillTextWin, BOX2_SEQ_DrawCellEntry, BOX2_SEQ_DrawSpriteEntry, BOX2_SEQ_DrawTileEntry, BOX2_SEQ_DrawMoveEntry, BOX2_SEQ_DrawSwapEntry, BOX2_SEQ_DrawItemEntry, BOX2_SEQ_DrawMsgEntry, BOX2_SEQ_DeleteTextEntries, BOX2_SEQ_ClearTextWin, BOX2_SEQ_DrawWindowFrame, BOX2_SEQ_DrawFrameColor, BOX2_SEQ_DrawFrameDefault, BOX2_SEQ_AddBmpWinFrame, BOX2_SEQ_AddTextFrame, BOX2_SEQ_AddMsgFrame, BOX2_SEQ_AddNameFrame, BOX2_SEQ_DrawBoxName, BOX2_SEQ_DrawOffsetName, BOX2_SEQ_DrawMonName, BOX2_SEQ_ChangeFramePalette, BOX2_SEQ_PutNameFrame, BOX2_SEQ_DrawFrameList, BOX2_SEQ_ClearMessageWindow, BOX2_SEQ_ShowWindowObject, BOX2_SEQ_HideWindowObject, BOX2_SEQ_PrintMessageMsg, BOX2_SEQ_PrintMessageB, BOX2_SEQ_PrintWordset, BOX2_SEQ_PrintMessage, BOX2_SEQ_PrintMessageC, BOX2_SEQ_PrintWordsetB, BOX2_SEQ_PrintMessageD, BOX2_SEQ_PrintWordsetBB64, BOX2_SEQ_PrintMessageE, BOX2_SEQ_PrintMonName, BOX2_SEQ_PrintIndexedMessage, BOX2_SEQ_PrintPrompt, BOX2_SEQ_PrintPromptB, BOX2_SEQ_PrintMenuRow, BOX2_SEQ_PrintBoxMonName, BOX2_SEQ_PrintYesNo, BOX2_SEQ_CreateBox2UiScene, BOX2_SEQ_DeleteBox2UiScene, BOX2_SEQ_InitClact, BOX2_SEQ_LoadBoxGraphics, BOX2_SEQ_ReleaseBoxGraphics, BOX2_SEQ_CreateBox2Actors, BOX2_SEQ_CreateActorFromDesc, BOX2_SEQ_DeleteActorSlot, BOX2_SEQ_DeleteAllActors, BOX2_SEQ_DrawActors, BOX2_SEQ_SetActorAnimSeq, BOX2_SEQ_SetActorAutoAnim, BOX2_SEQ_IsActorAnimActive, BOX2_SEQ_SetActorDrawEnable, BOX2_SEQ_GetActorDrawEnable, BOX2_SEQ_SetActorBgPriority, BOX2_SEQ_SetActorDrawPriority, BOX2_SEQ_SetActorObjMode, BOX2_SEQ_AddActorSurfacePos, BOX2_SEQ_GetActorSurfacePos, BOX2_SEQ_RegisterBoxChars, BOX2_SEQ_RegisterBoxCharsB, BOX2_SEQ_RegisterIconRes, BOX2_SEQ_CreateBoxSlotActors, BOX2_SEQ_LoadGraphicResource, BOX2_SEQ_LoadMonIcon, BOX2_SEQ_SetSlotIconPal, BOX2_SEQ_LoadIconResource, BOX2_SEQ_ShowSlotIcon, BOX2_SEQ_ShowAllSlotIcons, BOX2_SEQ_ShowPartyIcons, BOX2_SEQ_GetSlotPos, BOX2_SEQ_HidePartialSlots, BOX2_SEQ_HideSlotsC61C, BOX2_SEQ_HideSlotsC688, BOX2_SEQ_HideSlotsC6F4, BOX2_SEQ_SetSlotDrawPriority, BOX2_SEQ_SetSlotDrawPriorityB, BOX2_SEQ_ShiftSlotIcons, BOX2_SEQ_MoveActorToWindow, BOX2_SEQ_ResetActorAffine, BOX2_SEQ_ShrinkActor, BOX2_SEQ_GrowActor, BOX2_SEQ_HideActor, BOX2_SEQ_ResetActorTransform, BOX2_SEQ_SetSlotActorsMode, BOX2_SEQ_SetSlotActors, BOX2_SEQ_SetSlotActorMode, BOX2_SEQ_SetActorMode1, BOX2_SEQ_SwapSlotActors, BOX2_SEQ_SwapSlotActorsB, BOX2_SEQ_RefreshHandSlot, BOX2_SEQ_InitIconSlots, BOX2_SEQ_LoadMonIconActor, BOX2_SEQ_LoadBoxScreen, BOX2_SEQ_CreateHandSlotActors, BOX2_SEQ_ShowHandSlot, BOX2_SEQ_ShowHandSlotB, BOX2_SEQ_LoadIconPalette, BOX2_SEQ_SetSlotCharacter, BOX2_SEQ_SetActorAffineMode, BOX2_SEQ_MoveActor, BOX2_SEQ_MoveActorToSlot, BOX2_SEQ_MoveActorToSlotB, BOX2_SEQ_CreateHandSlotActorsB, BOX2_SEQ_ShowHandSlots, BOX2_SEQ_LayoutHandSlots, BOX2_SEQ_CreateCursorObjects, BOX2_SEQ_SetWindow9, BOX2_SEQ_SetCursorFrame, BOX2_SEQ_SetCursorDraw, BOX2_SEQ_RefreshCursorSlot, BOX2_SEQ_MoveCursorActor, BOX2_SEQ_SetSlotDim, BOX2_SEQ_SetSlotDimB, BOX2_SEQ_MoveCursorToSlot
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
 *   func_020078C4 0x020078C4 thumb
 *   BOX2_SEQ_UpdatePrintQueue  0x021E1E34  thumb  ov170
 *   BOX2_SEQ_FlushDirtyBmpWins  0x021EAB04  thumb  ov170
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4  0x020490F4  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02045EC0 0x02045EC0 arm
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   func_020355D8 0x020355D8 arm
 *   BOX2_SEQ_SetActorAutoAnim 0x021EBFCC thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BGWINFRM_GetSize 0x0202CFC0 thumb
 *   BGWINFRM_GetBgFrame 0x0202CF8C thumb
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb  ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_UI_SetMiniIconVisible  0x021EE008  thumb  ov170
 *   BOX2_UI_DeleteSlotIcon  0x021EDF5C  thumb  ov170
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   func_02017E88 0x02017E88 thumb
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
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_SwapSlotActorsB 0x021ECBD8 thumb
 *   func_02030734 0x02030734 arm
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
 *   func_0200785C 0x0200785C thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
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
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_SEQ_RefreshHandSlot 0x021ECC1C thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb
 *   BOX2_MAIN_IsWrappedDistance 0x021DD210 thumb
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb ov170
 *   BOX2_MAIN_CompareSlots 0x021DDE80 thumb
 *   BOX2_MAIN_PlaceMonSceneFromBox 0x021DEA3C thumb
 *   BOX2_MAIN_IsSwapScene 0x021DEAFC thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_MAIN_PlaceTargetMonScene 0x021DEA4C thumb
 *   BOX2_MAIN_IsMoveScene 0x021DEB08 thumb ov170
 *   CURSOR_MOVE_GetCurrent 0x020260E0 thumb
 *   BOX2_UI_AddSlotIcon 0x021EDD38 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   d_021EFA7C 0x021EFA7C data a4
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
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
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   BOX2_MAIN_CreateVBlankTask 0x021DC94C thumb ov170
 *   str_021F140C 0x021F140C data a1
 *   ov067_id 0x00000043 data a1
 *   BOX2_MAIN_DeleteVBlankTask  0x021DC964  thumb  ov170
 *   BOX2_MAIN_DeleteTaskMenu  0x021DCF30  thumb  ov170
 *   BOX2_UI_DeleteSound  0x021EE3CC  thumb  ov170
 *   BOX2_UI_DeleteWindowFrames  0x021EF310  thumb  ov170
 *   BOX2_MAIN_DeleteFormTable  0x021DD8F8  thumb  ov170
 *   BOX2_MAIN_DeleteTextSystem  0x021DCE80  thumb  ov170
 *   BOX2_MAIN_DeletePalAnm  0x021DCDD8  thumb  ov170
 *   BOX2_MAIN_DeleteBgSys  0x021DCB48  thumb  ov170
 *   func_020306F0  0x020306F0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   PALANM_GetFadeRequestBits   0x02021ED8  thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   d_021EFA4C 0x021EFA4C data a4
 *   BOX2_MAIN_IsTaskMenuFinished  0x021DCFC0  thumb  ov170
 *   g_021EFA28  0x021EFA28  data  ov170
 *   d_021EFA2C 0x021EFA2C data a4
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
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
 *   BOX2_MAIN_PlayCursorSound 0x021DD238 thumb
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
 *   func_020355C4 0x020355C4 arm
 *   BOX2_UI_UpdateCursorInputB 0x021EE57C thumb
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb ov170
 *   BOX2_MAIN_StateMachineClose 0x021E0068 thumb ov170
 *   BOX2_UI_UpdateCursorInputA 0x021EE474 thumb
 *   BOX2_MAIN_SceneWaitCursor 0x021E0778 thumb
 *   BOX2_UI_PlaceCursorAtIcon 0x021EE520 thumb
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   KEY_GetRepeat 0x0203633C arm
 *   func_020077B8 0x020077B8 thumb
 *   func_020076D0 0x020076D0 thumb
 *   BOX2_UI_PlaceCursorAtMon 0x021EE544 thumb
 *   BOX2_MAIN_SceneOpenBox 0x021E087C thumb
 *   BOX2_UI_UpdateCursorInputE 0x021EEA48 thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_UI_UpdateCursorInputF 0x021EEB40 thumb
 *   BOX2_UI_CursorInputPage 0x021EEEA4 thumb
 *   BOX2_MAIN_GetBoxValue 0x021DD908 thumb ov170
 *   BOX2_UI_ResetSlotFrames 0x021EF508 thumb
 *   BOX2_MAIN_ChangeBoxForm 0x021DEF98 thumb ov170
 *   BOX2_MAIN_SetHandSlots 0x021DF110 thumb ov170
 *   BOX2_UI_PutTopBarThenClose 0x021EF6A8 thumb ov170
 *   BOX2_MAIN_UpdateWindowMove 0x021E01A8 thumb ov170
 *   BOX2_MAIN_SetBodySlots 0x021DF11C thumb ov170
 *   BOX2_UI_RepenTopBar 0x021EF6CC thumb ov170
 *   BOX2_MAIN_HasOtherTradable 0x021DD694 thumb ov170
 *   func_02017E1C 0x02017E1C thumb
 *   BOX2_MAIN_StepScroll 0x021DE7C8 thumb ov170
 *   BOX2_MAIN_DeleteScroll 0x021DE7B4 thumb ov170
 *   BOX2_MAIN_ClearSlot 0x021DD314 thumb
 *   BOX2_MAIN_StateMachineOpen 0x021E002C thumb
 *   d_021EF908 0x021EF908 data a4
 *   func_02007A80 0x02007A80 thumb
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
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   BOX2_MAIN_LoadBoxPalette 0x021DED58 thumb ov170
 *   func_02007838 0x02007838 thumb
 *   BOX2_MAIN_InitSeq  0x021DC9A0  thumb  ov170
 *   BOX2_MAIN_RestartSeq  0x021DC9B8  thumb  ov170
 *   BOX2_MAIN_OpenTaskMenu 0x021DCF58 thumb
 *   func_02007E50 0x02007E50 thumb
 *   BOX2_MAIN_SetBoxForm 0x021DEFF8 thumb ov170
 *   BOX2_MAIN_ResetMovers 0x021DE728 thumb ov170
 *   BOX2_MAIN_PlayMonCry  0x021DE898  thumb  ov170
 *   BOX2_MAIN_UpdateWindowFrame  0x021DD090  thumb  ov170
 *   data_021EFA10 0x021EFA10 data a1
 *   BOX2_UI_PutListFrames 0x021EF4E4 thumb
 *   func_02007F1C 0x02007F1C thumb
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
 *   func_0201F250 0x0201F250 thumb
 *   BMP_Clear 0x02043B5C arm
 *   func_0201EEA4 0x0201EEA4 thumb
 *   func_0201EF14 0x0201EF14 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201EF98 0x0201EF98 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   func_02049DB4 0x02049DB4 arm
 *   BMP_CreateFromBuffer 0x020436FC arm
 *   BMP_Blit 0x020439A0 arm
 *   BMP_Delete 0x020437AC arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   BGWINFRM_AddFrame 0x0202CA3C thumb
 *   BGWINFRM_PutBmpWin 0x0202CEBC thumb
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201F7A8  0x0201F7A8  thumb  ov170
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
 *   func_02027618 0x02027618 thumb
 *   func_02027614 0x02027614 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   d_021EFD04 0x021EFD04 data a4
 *   func_020079BC 0x020079BC thumb
 *   MIi_CpuCopy32 0x02082A90 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   d_021EFD4C 0x021EFD4C data a2
 *   d_021EFCE0 0x021EFCE0 data a1
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_SetActorScale 0x0204B5AC arm
 *   CLACT_SetActorAffineOrigin 0x0204B588 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   d_021EFD80 0x021EFD80 data a4
 *   func_020275F8 0x020275F8 thumb
 *   func_020275FC 0x020275FC thumb
 *   func_02027600 0x02027600 thumb
 *   func_020275E8 0x020275E8 thumb
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202776C 0x0202776C thumb
 *   func_02027770 0x02027770 thumb
 *   func_02027774 0x02027774 thumb
 *   func_02027768 0x02027768 thumb
 *   d_021EFD34 0x021EFD34 data a4
 *   func_020275EC 0x020275EC thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   func_02020F08 0x02020F08 thumb
 *   func_02049E34 0x02049E34 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   func_02049F34 0x02049F34 arm
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
 *   BOX2_MAIN_Check09E0 0x021E09E0 thumb ov170
 *   BOX2_MAIN_Check0A40 0x021E0A40 thumb ov170
 *   BOX2_MAIN_StateMachineCoin 0x021E0ABC thumb ov170
 *   BOX2_MAIN_Check0ED4 0x021E0ED4 thumb ov170
 *   BOX2_MAIN_Check0F4C 0x021E0F4C thumb ov170
 *   BOX2_MAIN_MoveCursorTo 0x021E0FB0 thumb ov170
 *   BOX2_MAIN_StateMachineSlide 0x021E0FD8 thumb ov170
 *   BOX2_MAIN_Check122C 0x021E122C thumb ov170
 */
#include "box2_types.h"
#include "../../matched/include/Obj08237.h"
#include "../../matched/include/Obj23881.h"
#include "../../matched/include/Obj23882.h"
#include "../../matched/include/Obj23883.h"
#include "../../matched/include/Obj23884.h"
#include "../../matched/include/Obj23885.h"
#include "../../matched/include/Obj23886.h"
#include "../../matched/include/Obj18463.h"
#include "../../matched/include/Obj12157.h"
#include "../../matched/include/Obj09224.h"
#include "../../matched/include/Obj10654.h"
#include "../../matched/include/Obj23887.h"
#include "../../matched/include/Obj23888.h"
#include "../../matched/include/Obj23889.h"
#include "../../matched/include/Obj23890.h"
#include "../../matched/include/Obj23891.h"
#include "../../matched/include/Obj23892.h"
#include "../../matched/include/Obj23893.h"
#include "../../matched/include/Obj23894.h"
#include "../../matched/include/Obj23895.h"
#include "../../matched/include/Obj23896.h"
#include "../../matched/include/Obj23897.h"
#include "../../matched/include/Obj23898.h"
#include "../../matched/include/Obj23899.h"
#include "../../matched/include/Obj23900.h"
#include "../../matched/include/Obj23901.h"
#include "../../matched/include/Obj23902.h"
#include "../../matched/include/Obj23904.h"
#include "../../matched/include/Obj23905.h"
#include "../../matched/include/Obj23906.h"
#include "../../matched/include/Obj23907.h"
#include "../../matched/include/Obj23908.h"
#include "../../matched/include/Obj23909.h"
#include "../../matched/include/Obj23910.h"
#include "../../matched/include/Obj23911.h"
#include "../../matched/include/Obj23912.h"
#include "../../matched/include/Obj23913.h"
#include "../../matched/include/Obj23914.h"
#include "../../matched/include/Obj23915.h"
#include "../../matched/include/Obj23916.h"
#include "../../matched/include/Obj23917.h"
#include "../../matched/include/Obj23918.h"
#include "../../matched/include/Obj23919.h"
#include "../../matched/include/Obj23920.h"
#include "../../matched/include/Obj23921.h"
#include "../../matched/include/Obj23922.h"
#include "../../matched/include/Obj23923.h"
#include "../../matched/include/Obj23924.h"
#include "../../matched/include/Obj23925.h"
#include "../../matched/include/Obj23926.h"
#include "../../matched/include/Obj23927.h"
#include "../../matched/include/Obj18467.h"
#include "../../matched/include/Obj23928.h"
#include "../../matched/include/Obj23929.h"
#include "../../matched/include/Obj23930.h"
#include "../../matched/include/Obj23931.h"
#include "../../matched/include/Obj23932.h"
#include "../../matched/include/Obj23933.h"
#include "../../matched/include/Obj23934.h"
#include "../../matched/include/Obj23935.h"
#include "../../matched/include/Obj23936.h"
#include "../../matched/include/Obj23937.h"
#include "../../matched/include/Obj23938.h"
#include "../../matched/include/Obj23940.h"
#include "../../matched/include/Obj18468.h"
#include "../../matched/include/Obj18469.h"
#include "../../matched/include/Obj18470.h"
#include "../../matched/include/Obj23942.h"
#include "../../matched/include/Obj23943.h"
#include "../../matched/include/Obj23944.h"
#include "../../matched/include/Obj05869.h"
#include "../../matched/include/Obj23945.h"
#include "../../matched/include/Obj23946.h"
#include "../../matched/include/Obj23947.h"
#include "../../matched/include/Obj23948.h"
#include "../../matched/include/Obj23949.h"
#include "../../matched/include/Obj23950.h"
#include "../../matched/include/Obj23951.h"
#include "../../matched/include/Obj23952.h"
#include "../../matched/include/Obj23953.h"
#include "../../matched/include/Obj23954.h"
#include "../../matched/include/Obj23957.h"
#include "../../matched/include/Obj18479.h"
#include "../../matched/include/Obj18480.h"
#include "../../matched/include/Obj18488.h"
#include "../../matched/include/Obj18489.h"
#include "../../matched/include/Obj18491.h"
#include "../../matched/include/Obj18493.h"
#include "../../matched/include/Obj18495.h"
#include "../../matched/include/Obj23958.h"
#include "../../matched/include/Obj12168.h"
#include "../../matched/include/Obj23959.h"
#include "../../matched/include/Obj23961.h"
#include "../../matched/include/Obj18507.h"
#include "../../matched/include/Obj08242.h"
#include "../../matched/include/Obj23962.h"
#include "../../matched/include/Obj00414.h"
#include "../../matched/include/Obj23964.h"
#include "../../matched/include/Obj02053.h"
#include "../../matched/include/Obj06549.h"
#include "../../matched/include/Obj23969.h"
#include "../../matched/include/Obj23970.h"
#include "../../matched/include/Obj23971.h"
#include "../../matched/include/Obj23973.h"
#include "../../matched/include/Obj23974.h"
#include "../../matched/include/Obj23975.h"
#include "../../matched/include/Obj23977.h"
#include "../../matched/include/Obj23978.h"
#include "../../matched/include/Obj23979.h"
#include "../../matched/include/Obj23980.h"
#include "../../matched/include/Obj23981.h"
#include "../../matched/include/Obj23982.h"
#include "../../matched/include/Obj23983.h"
#include "../../matched/include/Obj23984.h"
#include "../../matched/include/Obj23985.h"
#include "../../matched/include/Obj23986.h"
#include "../../matched/include/Obj23987.h"
#include "../../matched/include/Obj23988.h"
#include "../../matched/include/Obj23989.h"
#include "../../matched/include/Obj18517.h"
#include "../../matched/include/Obj18518.h"
#include "../../matched/include/Obj23990.h"
#include "../../matched/include/Obj23991.h"
#include "../../matched/include/Obj23992.h"
#include "../../matched/include/Obj23993.h"
#include "../../matched/include/Obj23994.h"
#include "../../matched/include/Obj23995.h"
#include "../../matched/include/Obj23996.h"
#include "../../matched/include/Obj23997.h"
#include "../../matched/include/Obj24001.h"
#include "../../matched/include/Obj24002.h"
#include "../../matched/include/Obj24003.h"
#include "../../matched/include/Obj24004.h"
#include "../../matched/include/Obj24005.h"
#include "../../matched/include/Obj24008.h"
#include "../../matched/include/Obj24010.h"
#include "../../matched/include/Obj24012.h"
#include "../../matched/include/Obj24013.h"
#include "../../matched/include/Obj24014.h"
#include "../../matched/include/Obj24015.h"
#include "../../matched/include/Obj24016.h"
#include "../../matched/include/Obj05439.h"
#include "../../matched/include/Obj04547.h"
#include "../../matched/include/Obj24017.h"
#include "../../matched/include/Obj14276.h"
#include "../../matched/include/Obj08247.h"
#include "../../matched/include/Obj24020.h"
#include "../../matched/include/Obj24021.h"
#include "../../matched/include/Obj24022.h"

extern int func_020078C4(void *save, u32 box);


struct Bank;

struct CharBuf;

struct Descriptor;

extern void *func_020490F4(u32 id, u32 heap);

extern u32 func_020307B0(void *p);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern u32 CURSOR_MOVE_GetState(struct Sound *obj);

extern void func_020355D8(u8 v);

extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);

extern void BGWINFRM_GetSize(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);

extern u8 BGWINFRM_GetBgFrame(struct WinMgr *mgr, u32 idx);

extern void BOX2_UI_DeleteSlotIcon(BoxTask *p);

extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);

extern void BOX2_UI_DrawSlot(BoxTask *p, int i);

extern void *POKE_TOOL_GetBoxParam(void *);

extern void BOX2_UI_DrawSlotByName(char *p, int a);

extern unsigned FILE_UTIL_Check136C(unsigned short v);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void func_0200785C(void *save, unsigned box, void *dest);

extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);

extern int BOX2_MAIN_ShiftWindowRight(BoxTask *p);

extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);

extern int TOUCHPANEL_GetCont(void);

extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);

extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);

extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);

extern void BOX2_UI_CloseInfoBar(struct WinMgr *mgr);

extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);

extern int BOX2_UI_GetPageButtonHit(void);

extern void BOX2_UI_SlideBarIn(struct WinMgr *mgr);

extern void CURSOR_MOVE_ClearSkipBit(struct Sound *obj, u32 idx);

extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);

extern int BOX2_UI_IsListClosed(struct WinMgr *mgr);

extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);

extern int BOX2_UI_GetPartySlotPoint(int a, int b);

extern void BOX2_UI_MoveCursor(char **p, int idx, int v);

extern int BOX2_UI_GetCloseButtonHit(void);

extern void BOX2_UI_OpenBar(struct WinMgr *mgr);

extern int BOX2_MAIN_IsSeqIdle(BoxTask *p);

extern int BOX2_MAIN_IsSeqStep(BoxTask *p);

extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);

extern void BOX2_UI_CloseBar(struct WinMgr *mgr);

extern int BOX2_UI_UpdateBarMove(BoxTask *p);

extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);

extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);

extern const unsigned char d_021EF79C[];

extern const unsigned char d_021EF7B4[];
























extern int BOX2_MAIN_MoveCursorWithMon(BoxTask *p, unsigned a, unsigned b);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern int BOX2_MAIN_HitBoxGrid(short x, int y);

extern int BOX2_MAIN_FindMoverSlot(BoxTask *p, unsigned id);

extern void BOX2_MAIN_StopSeq(BoxTask *p, int dir);

extern void BOX2_MAIN_MoveCursorActor(BoxTask *p, int x, int y);

extern int BOX2_MAIN_WaitCursorMove(BoxTask *p);

extern void BOX2_MAIN_ResetBoxView(BoxTask *p);

extern int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);

extern void BOX2_UI_DeleteSlotObjects(BoxTask *p, int a, int b, int c);

extern void BOX2_UI_SetMiniIconVisible(BoxTask *p, int a, int b);

extern int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);

extern int BOX2_MAIN_GetBoxFormId(BoxTask *p, int box);

extern void BOX2_MAIN_SetBoxScroll(BoxTask *p, void *a, int dir);

extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);







#define ABS(x) ((x) < 0 ? -(x) : (x))










#define HEAP 0x804C



struct Ov170Ctx;

struct Cfg;

struct StrObj;

struct Bmp;

struct Obj020437AC;

struct Obj;

struct Actor;

struct Slots_021EBF34;

struct Vec2;

struct PtS;

struct Pair;

struct Pt;

struct Sub0204A9D0;

struct Struct36;








struct BoxCountWork {
    char pad[0xA18C];
    int count;
};

typedef struct { int (*a)(char *); int (*b)(char *); } Pair;

typedef struct { void (*callback)(u8 *); u32 value; u32 next; } Dispatch;

typedef short s16_021E09E0;

typedef struct {
    short left;
    short dir;
} Scroll;

typedef struct { u8 lo:4; u8 hi:4; } Nib_021E09E0;

typedef struct {
    unsigned char lo : 4;
    unsigned char hi : 4;
} Nib_021E65E4;

typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags_021E65E4;

typedef struct { unsigned short a; unsigned short b; } Ent;

typedef struct { u8 pad[0x1c]; u8 lo : 4; u8 hi : 4; } Flags_021E8340;

typedef signed short s16_021E65E4;

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

typedef struct { unsigned value; unsigned char pad[14]; unsigned char low:7; unsigned char flag:1; } Entry_021EADB4;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EAE74;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EAF20;

typedef struct { unsigned char pad[18]; unsigned char low:7,high:1; } Entry_021EAFBC;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB098;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry_021EB114;

typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; unsigned char kind : 4; unsigned char enabled : 1; unsigned char rest : 3; } Entry_021EB208;

typedef struct {
    void *obj;
    int pad;
} Item;

typedef struct {
    unsigned char pad[0x94];
    Item items[14];
} Work;

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
} Desc;

typedef struct {
    Desc a[13];
    Desc b[6];
    Desc c[6];
    Desc d[3];
} DescTable;

struct Slots_021EBF34 { char pad[0x9E74]; int arr[1]; };

typedef struct { short x; short y; } Pos_021EC548;

typedef struct { unsigned char a; unsigned char b; } Off;

typedef struct {
    int pad[9];
    int x24;
} Top;

typedef struct {unsigned char low:7;unsigned char high:1;} Flag;

struct Slot { unsigned char a[0x1c]; unsigned char f : 4; };

typedef struct {
    int w[9];
} Struct36;

extern void BOX2_MAIN_SetMoverEntry(BoxTask *p, void *a);

extern int BOX2_MAIN_SceneApplyScroll(BoxTask *p);

extern int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b);

extern void BOX2_MAIN_PlaceMonSceneFromBox(int a, int b, int c, int d);

extern int BOX2_MAIN_IsSwapScene(int a);

extern int BOX2_MAIN_IsWindowMoving(BoxTask *p);

extern void BOX2_MAIN_PlaceTargetMonScene(BoxTask *p, int a, int b);

extern int BOX2_MAIN_IsMoveScene(unsigned char *p);

extern void BOX2_UI_ToggleSlotPair(char *w, int a);

extern u8 CURSOR_MOVE_GetCurrent(struct Sound *obj);

extern void BOX2_UI_AddSlotIcon(BoxTask *p, int d);

extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);

extern int func_02034AC4(int);

extern void BG_SYS_SetMainVisiblePlanes(unsigned);

extern void BG_SYS_SetSubVisiblePlanes(unsigned);

extern void func_0204363C(unsigned);

extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);

extern void KEY_GetRepeatSpeed(u32 *outA, u32 *outB);

extern int KEY_SetRepeatSpeed(int a0, int a1);

extern void BOX2_MAIN_ResetGraphics(void);

extern void BOX2_MAIN_InitBgSys(u8 *);

extern void BOX2_MAIN_CreatePalAnm(BoxTask *p);

extern void BOX2_MAIN_LoadBgData(struct Ov170Ctx *ctx);

extern void BOX2_MAIN_CreateTextSystem(char *);

extern void BOX2_MAIN_LoadFormTable(char *p);

extern void BOX2_UI_InitWindowFrames(char *);

extern void BOX2_UI_DrawAllSlots(int p);

extern void BOX2_UI_CreateCursor(char **);

extern void BOX2_MAIN_CreateTaskMenu(char *);

extern void BOX2_MAIN_SetDisplayControl(int);

extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);

extern void BOX2_MAIN_CreateVBlankTask(BoxTask *p);

extern void BOX2_MAIN_DeleteVBlankTask(BoxTask *p);

extern void BOX2_MAIN_DeleteTaskMenu(BoxTask *p);

extern void BOX2_UI_DeleteSound(int *p);

extern void BOX2_UI_DeleteWindowFrames(char *p);

extern void BOX2_MAIN_DeleteFormTable(BoxTask *p);

extern void BOX2_MAIN_DeleteTextSystem(char *p);

extern void BOX2_MAIN_DeletePalAnm(int *p);

extern void BOX2_MAIN_DeleteBgSys(void *p);

extern void ARC_TOOL_DeleteHandle(void *a);

extern void func_020306F0(unsigned int a);

extern void func_02034A5C(int a);

extern u32 WIPE_SYS_EndCheck(void);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern int TOUCHPANEL_GetTrg(void);

extern u32 KEY_GetTrg(void);

extern void APP_TASKMENU_UpdateMenu(void *);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

extern int BOX2_MAIN_IsTaskMenuFinished(BoxTask *p);

extern void BOX2_MAIN_ChangeBoxFormPreserve(BoxTask *p, int b);

extern void BOX2_UI_ShowWindowA(char *);

extern u32 POKEPARTY_GetCount(void *p);

extern void BOX2_UI_ShowWindowB(char *);

extern int BOX2_UI_GetBackButtonPoint(unsigned *a, unsigned *b);

extern void BOX2_MAIN_SelectBox(BoxTask *p, int a);

extern unsigned BOX2_UI_GetPartySlotHit(void);

extern unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern int BOX2_UI_IsListOpen(struct WinMgr *mgr);

extern void BOX2_MAIN_RefreshCursorBox(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputC(BoxTask *p);

extern void BOX2_MAIN_ClearCursorBox(unsigned char *p);

extern void BOX2_UI_MoveCursorBetweenIcons(char *w, int k, int v);

extern void BOX2_MAIN_UpdateBoxSlots(unsigned char *);

extern void BOX2_MAIN_PlayCursorSound(BoxTask *p);

extern void BOX2_UI_SelectSlot(BoxTask *p, unsigned r);

extern int BOX2_UI_GetExitButtonPoint(unsigned *a, unsigned *b);

extern unsigned BOX2_UI_CursorInputLeft(BoxTask *p);

extern void BOX2_UI_PutBottomBarOpen(struct WinMgr *mgr);

extern unsigned BOX2_UI_GetHandSlotHit(void);

extern unsigned BOX2_UI_UpdateCursorInputD(BoxTask *p);

extern u8 func_020355C4(void);

extern void BOX2_UI_HideWindowA(char *w);

extern void BOX2_UI_HideWindowB(char *w);

extern unsigned BOX2_UI_CursorInputRight(BoxTask *p);

extern unsigned BOX2_UI_GetBodySlotHit(void);

extern void BOX2_UI_SlideBarOut(struct WinMgr *mgr);

extern unsigned BOX2_UI_UpdateCursorInputG(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputH(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputB(BoxTask *p);

extern int BOX2_MAIN_SceneWaitScroll(BoxTask *p);

extern int BOX2_MAIN_StateMachineClose(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputA(BoxTask *p);

extern int BOX2_MAIN_SceneWaitCursor(BoxTask *p);

extern void BOX2_UI_PlaceCursorAtIcon(BoxTask *p, unsigned idx);

extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);

extern unsigned int KEY_GetRepeat(void);

extern int func_020077B8(void *save, u32 box);

extern int func_020076D0(void *save, int *pbox, int *pslot);

extern void BOX2_UI_PlaceCursorAtMon(BoxTask *p, unsigned int i);

extern int BOX2_MAIN_SceneOpenBox(BoxTask *p);

extern unsigned BOX2_UI_UpdateCursorInputE(BoxTask *p);

extern void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);

extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);

extern int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);

extern void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);

extern unsigned BOX2_UI_UpdateCursorInputF(BoxTask *p);

extern unsigned BOX2_UI_CursorInputPage(BoxTask *p);

extern int BOX2_MAIN_GetBoxValue(char *p, u32 a);

extern void BOX2_UI_ResetSlotFrames(struct WinMgr *mgr);

extern int BOX2_MAIN_ChangeBoxForm(char *p, int a, unsigned b);

extern void BOX2_MAIN_SetHandSlots(char *p, int b);

extern void BOX2_UI_PutTopBarThenClose(struct WinMgr *mgr);

extern int BOX2_MAIN_UpdateWindowMove(char *p);

extern void BOX2_MAIN_SetBodySlots(char *p, int b);

extern void BOX2_UI_RepenTopBar(struct WinMgr *mgr);

extern int BOX2_MAIN_HasOtherTradable(void ***, unsigned);

extern void *POKEPARTY_GetMember(void *, unsigned);

extern unsigned func_02017E1C(void *, unsigned, unsigned);

extern unsigned func_02017E88(void *, unsigned, unsigned);

extern int BOX2_MAIN_StepScroll(BoxTask *p);

extern void BOX2_MAIN_DeleteScroll(BoxTask *p);

extern void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);

extern int BOX2_MAIN_StateMachineOpen(unsigned char *p);

extern int func_02007A80(void *save, unsigned bits);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

extern u32 func_020056BC(void);

extern int PALANM_RequestFade(void *, u16, u16, s16_021E65E4, u8, u8, u16, void *);

extern void BOX2_MAIN_LoadBoxPalette(char *, int);

extern void func_02007838(void *save, u32 box, u8 v);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern void BOX2_MAIN_InitSeq(char *, int);

extern void BOX2_MAIN_RestartSeq(char *);

extern void BOX2_MAIN_OpenTaskMenu(BoxTask *p, int sel);

extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);

extern void BOX2_MAIN_SetBoxForm(BoxTask *p, unsigned b);

extern void BOX2_MAIN_ResetMovers(BoxTask *p);

extern void BOX2_MAIN_PlayMonCry(int *q);

extern void BOX2_MAIN_UpdateWindowFrame(char *, int);

extern void BOX2_UI_PutListFrames(struct WinMgr *mgr);

extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);

extern void BOX2_MAIN_RefreshBoxUi(BoxTask *p);

extern void BOX2_MAIN_SceneMoveCursor(BoxTask *p);

extern int BOX2_MAIN_StateMachineScroll(BoxTask *p);

extern int BOX2_MAIN_StateMachinePen(BoxTask *p);

extern int BOX2_MAIN_StateMachinePick(BoxTask *p);

extern int BOX2_MAIN_StateMachineMove(BoxTask *p);

extern void BOX2_UI_PutTopBarOpen(struct WinMgr *mgr);

extern void BOX2_UI_PutTopBarClosed(struct WinMgr *mgr);

extern void CURSOR_MOVE_SetSkipBit(struct Sound *obj, u32 idx);

extern void BMP_WIN_Init(u16 heapId);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void func_02041B6C(unsigned int);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void func_0201F250(struct WordSet *ws, void *dst, void *src);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void func_0201EEA4(struct WordSet *p, u32 i, void *mon);

extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern void func_0201EF98(struct WordSet *p, u32 i, u32 v);

extern void func_0201EF8C(struct WordSet *p, u32 i, u32 v);

extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);

extern u8 BMP_WIN_GetPosX(struct Descriptor *p);

extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

extern u8 BMP_WIN_GetWidth(struct Descriptor *p);

extern u8 BMP_WIN_GetHeight(struct Descriptor *p);

extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern struct Bmp *BMP_CreateFromBuffer(void *pixels, u32 width, u32 height, u32 depth, u16 heap);

extern void BMP_Blit(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);

extern void BMP_Delete(struct Obj020437AC *p);

extern unsigned func_020275E4(void);

extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);

extern void BGWINFRM_AddFrame(void *,unsigned,unsigned,unsigned,unsigned);

extern void BGWINFRM_PutBmpWin(void *,unsigned,void *);

extern void PRINTSYS_PrintColor(void *x, short y, short z, void *s, void *w, unsigned short v);

extern void BMP_OAM_UploadChars(struct Obj *o);

extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);

extern void func_0201F73C(void *a0, int a1, int a2, int a3);

extern void func_0201F7A8(void *, int);

extern void BOX2_UI_HideSlots678(BoxTask *p);

extern void BOX2_UI_CreateBmpOam(char *p);

extern void BG_SYS_SetMainPlaneVisible(unsigned, unsigned);

extern void BG_SYS_SetSubPlaneVisible(unsigned, unsigned);

extern void BOX2_UI_DeleteBmpOam(char *);

extern void CLACT_ExitSystem(void);

extern unsigned BOX2_MAIN_GetDispVram(void);

extern void CLACT_InitSystem(Template *,unsigned,unsigned);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern void BOX2_UI_CreatePartyActors(char *);

extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);

extern void CLACT_SetActorVisible(struct Actor *a, u32 v);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern u32 CLACT_GetActorAutoAnim(struct Obj *p);

extern void CLACT_AddActorAnimFrame(struct Obj *p, u32 arg);

extern void CLACT_DrawSystem(void);

extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_SetActorAutoAnim(struct Obj *, unsigned int);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

extern void CLACT_SetActorBgPriority(int, int);

extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern unsigned func_02027618(void);

extern unsigned func_02027614(void);

extern u32 func_0202761C(u32 a);

extern u32 func_02027620(u32 a);

extern int func_0201BC3C(void);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern int func_0201BC40(void);

extern int func_0201BCB4(void);

extern u32 POKE_TOOL_GetGraphicIndex(void *mon);

extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern int func_020079BC(void **save, u32 box, u32 slot, int field, int arg);

extern void MIi_CpuCopy32(const void *src, void *dst, unsigned size);

extern int POKE_TOOL_GetIconPalette(void *a0);

extern u16 CLACT_GetActorCharacterIndex(u8 *p);

extern void CLACT_TransferCharacterPart(int a, void *b, u32 c, int d, int e);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);

extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);

extern void CLACT_SetActorAffineOrigin(struct Actor *actor, const struct Pt *src);

extern int POKEGRA_OpenHandle(int);

extern u32 func_02017DBC(struct Sav *p);

extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);

extern int POKEGRA_RegisterPalettePP(int,void *,int,int,u32,u16);

extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);

extern u32 func_02017DE4(struct Sav *p, u32 f);

extern unsigned int func_020275F8(unsigned int a);

extern u32 func_020275FC(u32 a);

extern u32 func_02027600(u32 a);

extern unsigned func_020275E8(void);

extern int func_0202774C(int a);

extern int func_02027750(int a);

extern int func_02027754(int a);

extern int func_02027748(void);

extern int func_0202776C(int a);

extern int func_02027770(int a);

extern int func_02027774(int a);

extern int func_02027768(void);

extern u8 func_020275EC(int i);

extern unsigned FILE_UTIL_Get(unsigned,unsigned);

extern unsigned func_02020F08(void);

extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void CLACT_TransferCharacter(int a, struct Sub0204A9D0 *b);

extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);

extern u16 CLACT_GetActorPaletteIndex(u8 *p);

extern void CLACT_TransferPalette(void *dst, void *src, unsigned flag);

extern int CLACT_GetActorDrawPriority(int a0);

extern u32 CLACT_GetActorBgPriority(u8 *a0);

extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);

extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);

int BOX2_MAIN_Check09E0(BoxTask *p);

int BOX2_MAIN_Check0A40(BoxTask *p);

int BOX2_MAIN_StateMachineCoin(BoxTask *p);

int BOX2_MAIN_Check0ED4(BoxTask *p);

int BOX2_MAIN_Check0F4C(BoxTask *p);

void BOX2_MAIN_MoveCursorTo(char *w, int x, int y);

int BOX2_MAIN_StateMachineSlide(BoxTask *p);

int BOX2_MAIN_Check122C(BoxTask *p);

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

int BOX2_SEQ_StateMoveItemE(BoxTask *p);

int BOX2_SEQ_StateCloseZoom(unsigned char *p);

int BOX2_SEQ_StateMoveItemF(BoxTask *p);

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

int BOX2_SEQ_StatePlayCry(BoxTask *p);

int BOX2_SEQ_StateCloseItemMenu(BoxTask *p);

void BOX2_SEQ_SaveMenuPosAndExit(BoxTask *p);

int BOX2_SEQ_StatePmVoiceClose(BoxTask *p);

void BOX2_SEQ_StateEnterItemMenu(unsigned char *p);

int BOX2_SEQ_GotoBox2Main(BoxTask *p, int a, int b);

int BOX2_SEQ_GetBgFrameY(BoxTask *p,int a,int b);

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

int BOX2_SEQ_ResetEntry(char *p, int a);

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

void BOX2_SEQ_FillTextWinEntry(unsigned char *w,Entry_021EADB4 *e,unsigned i);

void BOX2_SEQ_FillTextWin(char *p, void **q, int i);

void BOX2_SEQ_DrawCellEntry(char *p, Entry_021EAE74 *e, unsigned i);

void BOX2_SEQ_DrawSpriteEntry(char *p, Entry_021EAF20 *e, unsigned i);

void BOX2_SEQ_DrawTileEntry(char *p,const Entry_021EAFBC *e,u32 i);

void BOX2_SEQ_DrawMoveEntry(char *p, unsigned char *e, int i);

void BOX2_SEQ_DrawSwapEntry(char *p, unsigned char *e, int i);

void BOX2_SEQ_DrawItemEntry(char *p, unsigned char *e, int i);

void BOX2_SEQ_DrawMsgEntry(char *p, Entry_021EB208 *e, int i);

void BOX2_SEQ_DeleteTextEntries(BoxTask *p, int a);

void BOX2_SEQ_ClearTextWin(Work *w);

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

void BOX2_SEQ_InitClact(void *a0);

void BOX2_SEQ_LoadBoxGraphics(char *p);

void BOX2_SEQ_ReleaseBoxGraphics(char *p);

void BOX2_SEQ_CreateBox2Actors(unsigned char *p);

void *BOX2_SEQ_CreateActorFromDesc(char *w, const Desc *s);

void BOX2_SEQ_DeleteActorSlot(struct Slots_021EBF34 *p, int i);

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

void BOX2_SEQ_ShowHandSlotB(char *p,unsigned char *q);

void BOX2_SEQ_LoadIconPalette(u8*p);

void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item);

void BOX2_SEQ_SetActorAffineMode(char *p, int on);

void BOX2_SEQ_MoveActor(int a, int b, int c);

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

extern const Pair d_021EFA4C[];

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

extern const Desc d_021EFD04;

extern const Pos_021EC548 d_021EFD4C[];

extern const Off d_021EFCE0[];

extern const DescTable d_021EFD80;

extern const Desc d_021EFD34;

extern const Desc d_021EFE70;

extern const signed char d_021EFCD0[];

extern const signed char d_021EFCC8[];




int BOX2_SEQ_StateMenuSelect(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(p))->work) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 1);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 1);
        b->state++;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
        b->state++;
        break;
    case 2:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 7);
        b->state++;
    case 3:
        if (b->timer == 4) {
            b->timer = 0;
            b->state++;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(p))->work), 4, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), 4, (short)t[1], (short)(t[0] + 2), (short)0);
        b->timer++;
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x666);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 8);
        b->state++;
    case 5:
        if (b->timer == 4) {
            BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(p))->work));
            BOX2_SEQ_ShowHandSlots(((char *)((BoxTask *)(p))->work));
            b->timer = 0;
            b->state = 0;
            return 0;
        }
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(p))->work), 4, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), 4, (short)t[1], (short)(t[0] - 2), (short)0);
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(p))->work), 10, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), 10, (short)t[1], (short)(t[0] - 2), (short)0);
        b->timer++;
        break;
    }
    return 1;
}

int BOX2_SEQ_StateMenuSwap(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(p))->work) + 0x58);
    short t[2];
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 7);
        b->state = 1;
    case 1:
        if (b->timer == 4) {
            b->timer = 0;
            b->state = 2;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(p))->work), 10, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), 10, (short)t[1], (short)(t[0] + 2), (short)0);
        b->timer++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x667);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 2);
        b->state = 3;
        break;
    case 3:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) == 0) {
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 0);
            b->state = 4;
        }
        break;
    case 4:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_SEQ_StateMenuMain(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(p))->work) + 0x58);
    switch (b->state) {
    case 0:
        if (p->heldSlot != 0xFF && p->heldSlot != p->curBox) {
            int dir = BOX2_MAIN_IsWrappedDistance((unsigned char *)p, p->curBox, p->heldSlot);
            p->curBox = p->heldSlot;
            BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
            BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), dir);
            if (dir == 0)
                b->state = 2;
            else
                b->state = 3;
            break;
        }
    case 1:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 7);
        BOX2_MAIN_PlaceTargetMonScene((BoxTask *)p, *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16E), 2);
        b->state = 4;
        break;
    case 2:
        if (BOX2_MAIN_IsSeqIdle(p) == 0)
            b->state = 1;
        break;
    case 3:
        if (BOX2_MAIN_IsSeqStep(p) == 0)
            b->state = 1;
        break;
    case 4:
        if (BOX2_MAIN_IsMoveScene((unsigned char *)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 5;
        }
        break;
    case 5:
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 2);
        b->state = 6;
        break;
    case 6:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) == 0) {
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 0);
            b->state = 7;
        }
        break;
    case 7:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        b->state = 0;
        return 0;
    }
    return 1;
}

/*
 * Twin of src/matched/ov170_func_021E0ABC.c.
 */
int BOX2_SEQ_StateMachineMove(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(p))->work) + 0x58);
    int busy = BOX2_UI_UpdateListPacks((((BoxTask *)(p))->work->winMgr));
    int wait = BOX2_UI_UpdateBarMove((BoxTask *)p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAnim((BoxTask *)p, (short)(((BoxTask *)(p))->work->counter));
        if ((((BoxTask *)(p))->work->counter) != 0) {
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
            BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 1);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 1);
            b->state = 1;
        } else {
            BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
            b->state = 11;
        }
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) == 1)
            break;
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
        BOX2_SEQ_ShowHandSlots(((char *)((BoxTask *)(p))->work));
        b->state = 2;
    case 2:
        if (BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 1)
            BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            if (wait == 1 || BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 1)
                flag = 1;
            else
                flag = 0;
            if (wait == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
                r = (unsigned short)BOX2_MAIN_HitBoxGrid(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA180), (short)(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA184)));
                if (r == 0xFF)
                    r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA180), *(int *)(((char *)((BoxTask *)(p))->work) + 0xA184), d_021EF79C);
            } else {
                r = (unsigned short)BOX2_MAIN_HitPartySlots(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA180), *(int *)(((char *)((BoxTask *)(p))->work) + 0xA184), d_021EF7B4);
            }
            first = r;
            if (r == 0xFF)
                r = p->cursorSlot;
            else if (BOX2_MAIN_CompareSlots((unsigned char *)p, p->cursorSlot, r) == 0)
                r = p->cursorSlot;
            if (flag == 1) {
                BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 2);
                b->state = 7;
            } else {
                BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 1);
                if (r == p->cursorSlot && (FILE_UTIL_Check136C((((BoxTask *)(p))->work->counter)) == 0 || first == p->cursorSlot))
                    BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 0 && BOX2_UI_GetPageButtonHit() == 0) {
            BOX2_UI_SlideBarIn((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
            CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 0x27);
            CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 0x28);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 1);
            p->barFlag = 1;
            *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = p->cursorSlot;
            *(int *)(((char *)((BoxTask *)(p))->work) + 0x68) = 0x42;
        }
        if (b->timer == 0) {
            int dir = BOX2_UI_GetCloseButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq((BoxTask *)p, 0);
                b->state = 3;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq((BoxTask *)p, 1);
                b->state = 4;
            }
        }
        BOX2_MAIN_MoveCursorTo(((char *)((BoxTask *)(p))->work), x, y);
        break;
    case 3:
        if (BOX2_MAIN_IsSeqIdle(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(((char *)((BoxTask *)(p))->work), x, y);
        break;
    case 4:
        if (BOX2_MAIN_IsSeqStep(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(((char *)((BoxTask *)(p))->work), x, y);
        break;
    case 7:
    case 8:
        if (BOX2_MAIN_IsSwapScene((int)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            if (b->state == 7) {
                b->state = 9;
            } else if (b->state == 8) {
                if ((((BoxTask *)(p))->work->counter) != 0) {
                    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
                    BOX2_SEQ_ShowHandSlots(((char *)((BoxTask *)(p))->work));
                }
                BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
                b->state = 11;
            }
        }
        break;
    case 9:
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 2);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        b->state = 10;
        break;
    case 10:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 0);
            BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
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

int BOX2_SEQ_StateExitBox(BoxTask *p)
{
    char *w = *(char * *)&p->work;
    char *b = w + 0x58;
    switch (((struct Obj08237 *)b)->fC) {
    case 0:
        if (!BOX2_SEQ_IsActorAnimActive((char *)w, 10)) {
            unsigned old = p->cursorSlot;
            p->cursorSlot = **(unsigned short * *)&((struct Obj08237 *)b)->f8;
            BOX2_MAIN_PlaceMonSceneFromBox((int)p, old, old, 1);
            ((struct Obj08237 *)b)->fC = 1;
        }
        break;
    case 1:
        if (!BOX2_MAIN_IsSwapScene((int)p)) {
            ((struct Obj08237 *)b)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_SEQ_OpenBoxUp(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&p->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(((struct Obj23881 *)(*(char * *)&p->work))->f70);
        if (r >= 0x22 && r <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, r - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)p, (short)-b->timer);
    return 1;
}

int BOX2_SEQ_OpenBoxDown(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&p->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(((struct Obj23882 *)(*(char * *)&p->work))->f70);
        if (r >= 0x22 && r <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, r - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)p, (short)b->timer);
    return 1;
}

int BOX2_SEQ_OpenBoxLeft(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&p->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(((struct Obj23883 *)(*(char * *)&p->work))->f70);
        if (r >= 1 && r <= 4)
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, r - 1, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)p, (short)-b->timer);
    return 1;
}

int BOX2_SEQ_OpenBoxRight(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(*(char * *)&p->work + 0x58);
    if (b->timer == 5) {
        unsigned r = CURSOR_MOVE_GetCurrent(((struct Obj23884 *)(*(char * *)&p->work))->f70);
        if (r >= 1 && r <= 4)
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, r - 1, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        b->timer = 0;
        return 0;
    }
    b->timer++;
    BOX2_UI_AddSlotIcon((BoxTask *)p, (short)b->timer);
    return 1;
}

/*
 * Sibling of src/matched/ov170_func_021DFA30.c.
 */
int BOX2_SEQ_StateMachineScroll(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)(((char *)((BoxTask *)(p))->work) + 0x58);
    int busy;
    unsigned r;
    unsigned x;
    unsigned y;
    if (BGWINFRM_IsMoving((((BoxTask *)(p))->work->winMgr), 8) == 1)
        busy = BOX2_MAIN_IsWindowBusy((unsigned char *)p);
    else
        busy = 0;
    r = BOX2_UI_UpdateListPacks((((BoxTask *)(p))->work->winMgr));
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 1)
                r = BOX2_MAIN_HitPartySlots(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA180), *(int *)(((char *)((BoxTask *)(p))->work) + 0xA184), d_021EF79C);
            if (r == 0xFF)
                r = BOX2_MAIN_HitBoxGrid(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA180), (short)(*(int *)(((char *)((BoxTask *)(p))->work) + 0xA184)));
            if (p->params->mode == 4 && p->params->linkMode == 1) {
                r = 0xFF;
                *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA173) = 5;
            }
            if (BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, r) == 0)
                r = 0xFF;
            if (BOX2_UI_IsListClosed((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            if (r != 0xFF)
                p->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)p, 0x24);
            if (BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 0 && busy == 0)
                BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
            if (r == 0xFF && p->curBox != p->heldSlot) {
                r = BOX2_MAIN_IsWrappedDistance((unsigned char *)p, p->curBox, p->heldSlot);
                p->curBox = p->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), r);
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
        if (busy == 0 && r == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 0 && p->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
            p->phase = 2;
            BOX2_UI_PutBottomBarClosed((((BoxTask *)(p))->work->winMgr));
            BOX2_UI_CloseBar((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_HidePartialSlots((char **)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 2);
            *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = p->cursorSlot;
            *(int *)(((char *)((BoxTask *)(p))->work) + 0x68) = 0x17;
        }
        if (b->timer == 0) {
            int dir = BOX2_UI_GetCloseButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq((BoxTask *)p, 0);
                b->state = 6;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq((BoxTask *)p, 1);
                b->state = 7;
            }
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 4:
        if (BOX2_MAIN_IsSeqIdle(p) == 0)
            b->state = 2;
        break;
    case 5:
        if (BOX2_MAIN_IsSeqStep(p) == 0)
            b->state = 2;
        break;
    case 2:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 3;
        }
        break;
    case 3:
        if (busy == 0 && r == 0)
            b->state = 0x10;
        break;
    case 6:
        if (BOX2_MAIN_IsSeqIdle(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 7:
        if (BOX2_MAIN_IsSeqStep(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry((BoxTask *)p, b->entry);
        if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(p))->work->winMgr)) == 0 && BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 0) {
            BOX2_SEQ_MoveCursorToSlot(((char *)((BoxTask *)(p))->work), p->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            CURSOR_MOVE_SetCurrent(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), p->cursorSlot);
            BOX2_UI_SetCursorPos((char **)p, p->cursorSlot);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}

extern int (*const d_021EFA7C[])(char *);

int BOX2_SEQ_UpdatePrintQueue(BoxTask *p, int *state)
{
    if (!*(char * *)&p->work || !((struct Obj23885 *)(*(char * *)&p->work))->f8C || PRINTSYS_QUE_IsFinished(((struct Obj23886 *)(*(char * *)&p->work))->f8C))
        *state = d_021EFA7C[*state]((char *)p);
    if (*state == 0x69)
        return 0;
    if (*(char * *)&p->work) {
        BOX2_SEQ_UpdateTextWins((unsigned char *)(*(char * *)&p->work));
        BOX2_SEQ_DrawActors(*(char * *)&p->work);
    }
    return 1;
}

/*
 *   src/matched/arm9/unit_0204361C.c contains its body but omits it from
 *   the function list. Its header should list BG_SYS_ResetSubDisplay,func_0204363C,
 *   func_02043658 and its shard must be regenerated by the owner.
 *   Verified standalone EXACT, dsi/1.1p1 -O4,p ARM c99, 28 bytes:
 *   typedef unsigned short u16;
 *   typedef unsigned int u32;
 *   void func_0204363C(u32 swap) {
 *       *(volatile u16 *)0x04000304 =
 *           (*(volatile u16 *)0x04000304 & ~0x8000) | (swap << 15);
 *   }
 *   scratchpad/overlay-goal-20261002-w62/B4/blocker-1.log is the verdict.
 *   tu --suggest-split remains MATCH; no viable partition.
 * volatile: hardware halfword writes at 021E1E9C and 021E1EA0.
 * prototype: DC9E0 takes the explicitly loaded p despite its unused input.
 */
int BOX2_SEQ_CreateBox2Main(u8 *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    func_0204363C(0);
    GFL_HEAP_CreateChildHeap(1,0x4C,0x80000);
    ((char *)((BoxTask *)(p))->work)=func_02030734(0x4C,0xA19C,1,str_021F140C,0x2B5);
    *(void **)(((char *)((BoxTask *)(p))->work)+0x1B0)=func_020490F4(7,0x4C);
    KEY_GetRepeatSpeed((u32 *)(((char *)((BoxTask *)(p))->work)+0x4C),(u32 *)(((char *)((BoxTask *)(p))->work)+0x50));
    KEY_SetRepeatSpeed(6,6);
    BOX2_MAIN_ResetGraphics();
    BOX2_MAIN_InitBgSys((u8 *)p);
    BOX2_MAIN_CreatePalAnm((BoxTask *)p);
    BOX2_MAIN_LoadBgData((struct Ov170Ctx *)p);
    BOX2_MAIN_CreateTextSystem((char *)p);
    BOX2_MAIN_LoadFormTable((char *)p);
    BOX2_SEQ_InitBmpWins((BoxTask *)p);
    BOX2_SEQ_CreateBox2UiScene((BoxTask *)p);
    BOX2_SEQ_ShowAllSlotIcons((BoxTask *)p);
    BOX2_SEQ_ShowPartyIcons((BoxTask *)p);
    BOX2_MAIN_SetBoxScroll((BoxTask *)p,(void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p,p[0x14]),2);
    BOX2_UI_InitWindowFrames((char *)p);
    BOX2_SEQ_PrintMsgWin((BoxTask *)p);
    BOX2_SEQ_InitBmpWin((BoxTask *)p);
    BOX2_UI_DrawAllSlots((int)p);
    BOX2_UI_CreateCursor((char **)p);
    BOX2_MAIN_CreateTaskMenu((char *)p);
    BOX2_MAIN_SetDisplayControl(1);
    GFL_NET_RestartWithDefaultTimeout(1,0x4C);
    BOX2_MAIN_CreateVBlankTask((BoxTask *)p);
    return *(int *)(p+0x28);
}

int BOX2_SEQ_DeleteBox2Main(BoxTask *p)
{
    BOX2_MAIN_DeleteVBlankTask((BoxTask *)p);
    BOX2_MAIN_DeleteTaskMenu((BoxTask *)p);
    BOX2_UI_DeleteSound((int *)p);
    BOX2_UI_DeleteWindowFrames((char *)p->work);
    BOX2_SEQ_DeleteBox2UiScene((char *)p->work);
    BOX2_SEQ_DeleteBmpWins((char *)p);
    BOX2_MAIN_DeleteFormTable((BoxTask *)p);
    BOX2_MAIN_DeleteTextSystem((char *)p);
    BOX2_MAIN_DeletePalAnm((int *)p);
    BOX2_MAIN_DeleteBgSys((void *)p);
    KEY_SetRepeatSpeed(*(u32 *)(*(u32 *)&p->work + 0x4c), *(u32 *)(*(u32 *)&p->work + 0x50));
    ARC_TOOL_DeleteHandle((void *)*(u32 *)(*(u32 *)&p->work + 0x1b0));
    func_020307B0((void *)p->work);
    func_020306F0(0x4c);
    *(u32 *)&p->work = 0;
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return *(u32 *)&p->state;
}

/*
 * Query the current mode; when it is 1 return the 0xA188 word of
 *   the p+0x2c object, else 2.
 */
int BOX2_SEQ_StateWaitWipe(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return *(int *)(((struct Obj18463 *)p)->f2C + 0xA188);
    return 2;
}

int BOX2_SEQ_StateWaitFade(void *p)
{
    if (PALANM_GetFadeRequestBits((const char *)(*(int *)(((struct Obj12157 *)p)->f2C + 0x6c))) == 0)
        return ((BoxTask *)p)->state;
    return 3;
}

int BOX2_SEQ_StateWaitCount(void *p)
{
    struct BoxCountWork *w = (struct BoxCountWork *)((struct Obj12157 *)p)->f2C;
    int v = w->count;
    if (v == 0)
        return ((BoxTask *)p)->state;
    w->count = v - 1;
    return 4;
}















int BOX2_SEQ_StateRunStep(char *p)
{
    int (*f)(char *) = *(int (**)(char *))(((struct Obj09224 *)p)->f2C + 0x58);
    if (f != 0 && f(p) == 0) {
        *(int *)(((struct Obj09224 *)p)->f2C + 0x58) = 0;
        return *(int *)(((struct Obj09224 *)p)->f2C + 0x68);
    }
    return 5;
}

int BOX2_SEQ_StateWaitInput(BoxTask *p)
{
    if (TOUCHPANEL_GetTrg() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_020355D8(1);
        return p->state;
    }
    if (KEY_GetTrg() & 3) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_020355D8(0);
        return p->state;
    }
    return 6;
}

int BOX2_SEQ_StateTaskMenu(char *p)
{
    APP_TASKMENU_UpdateMenu(*(void **)(((char *)((BoxTask *)(p))->work) + 0x1A0));
    if (APP_TASKMENU_IsFinish(*(void **)(((char *)((BoxTask *)(p))->work) + 0x1A0)) == 1) {
        int r = APP_TASKMENU_GetCursorPos(*(void **)(((char *)((BoxTask *)(p))->work) + 0x1A0));
        APP_TASKMENU_CloseMenu(*(void **)(((char *)((BoxTask *)(p))->work) + 0x1A0));
        KEY_SetRepeatSpeed(6, 6);
        if (r == 0)
            return d_021EFA4C[*(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0x1A4)].a(p);
        else
            return d_021EFA4C[*(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0x1A4)].b(p);
    }
    return 7;
}

int BOX2_SEQ_StateCheckTaskMenu(int p)
{
    if (BOX2_MAIN_IsTaskMenuFinished((BoxTask *)p) == 0)
        return ((BoxTask *)p)->state;
    return 8;
}

extern struct Ent { void (*fn)(void *); int a; int b; } g_021EFA28[];

/*
 * Dispatch through the 12-byte table at 0x021EFA28 keyed by p[0x12].
 *   CLOSES the operand-order residue: the image's `ldr r1,[r1,r3]` (base first)
 *   comes out of a pointer VARIABLE holding the element address; writing the
 *   subscript as a direct member access makes mwccarm encode `[r3,r1]`.
 */
int BOX2_SEQ_StateDispatchFont(unsigned char *p)
{
    struct Ent *e = &g_021EFA28[p[0x12]];
    e->fn(p);
    return 10;
}

int BOX2_SEQ_StateDispatchStep(u8 *p){if(((BoxTask *)p)->subState!=1){(*(void (**)(u8 *))((u32)&d_021EFA2C.callback+p[0x12]*12))(p);((struct Obj10654 *)p)->f28=*(u32 *)((u32)&d_021EFA2C.value+p[0x12]*12);return 0;}return 10;}











int BOX2_SEQ_DeleteBox2Ui(BoxTask *p)
{
    GFL_USE_PlaySeDefaultVolume(0x55C);
    switch(((struct Obj23887 *)(*(char * *)&p->params))->f24) {
    case 0:
        BOX2_SEQ_RestartLeftBar((int)p);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
        BOX2_SEQ_SetSlotActors((char *)p,1,1);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,30);
        (((BoxTask *)(p))->work->nextState)=0x31;
        break;
    case 1:
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,0);
        (((BoxTask *)(p))->work->nextState)=0x2C;
        break;
    case 2:
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,0);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        (((BoxTask *)(p))->work->nextState)=0x11;
        break;
    case 3:
        BOX2_SEQ_SetSlotActors((char *)p,0x81,1);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,0);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        (((BoxTask *)(p))->work->nextState)=0x39;
        break;
    case 4:
        if(POKEPARTY_GetCount(((struct Obj23888 *)(*(char * *)&p->params))->f8)==0) {
            BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,0);
            BOX2_UI_MoveCursor((char **)p,13,0);
            (((BoxTask *)(p))->work->nextState)=0x23;
        } else {
            BOX2_SEQ_RestartLeftBar((int)p);
            BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
            BOX2_SEQ_SetSlotActors((char *)p,1,1);
            BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,30);
            BOX2_UI_MoveCursor((char **)p,14,0);
            (((BoxTask *)(p))->work->nextState)=0x27;
        }
        break;
    case 5:
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,0);
        BOX2_SEQ_SetSlotActors((char *)p,0x81,1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p,0,1,1);
        (((BoxTask *)(p))->work->nextState)=0x4B;
        break;
    }
    return BOX2_SEQ_StateWaitPrint((int)p);
}

/*
 * candidate BOX2_SEQ_StateWaitPrint: guard then dispatch
 */
int BOX2_SEQ_StateWaitPrint(int p)
{
    if (PRINTSYS_QUE_IsFinished((const struct PrintSys *)(*(int *)(*(int *)&((BoxTask *)p)->work + 0x8c))) == 0)
        return 0xc;
    BOX2_SEQ_StartWipeWhite((void *)p, *(int *)(*(int *)&((BoxTask *)p)->work + 0xA198));
}

int BOX2_SEQ_StateSetMenu(unsigned char *p)
{
    func_020307B0(((struct Obj23889 *)(*(char * *)&((BoxTask *)p)->work))->f60);
    if ((*(unsigned char **)(p + 0x2C))[0xA172] == 1) {
        if (((struct Obj23890 *)(*(char * *)&((BoxTask *)p)->params))->f24 == 3) {
            if (((struct Obj23891 *)(*(char * *)&((BoxTask *)p)->work))->fA16C == 0)
                BOX2_SEQ_PrintPromptB((BoxTask *)p, 0, 0x18);
            else
                BOX2_SEQ_PrintPromptB((BoxTask *)p, 1, 0x18);
        } else {
            BOX2_SEQ_PrintPrompt((BoxTask *)p, p[0x16], 1, 0x18);
        }
        (*(char **)(p + 0x2C))[0xA172] = 0;
    }
    return ((BoxTask *)p)->state;
}

/*
 * Two-step machine on the work word at 0xA194: step 0 opens the menu for
 * the current mode and fades, step 1 picks the next state from the mode.
 */
int BOX2_SEQ_StateItemMenu(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        switch ((((BoxTask *)(p))->params->mode)) {
        case 1:
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9B4, 5);
            break;
        case 0:
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF950, 5);
            break;
        case 2:
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
            break;
        case 3:
            BOX2_SEQ_SetActorAnim((BoxTask *)p, (*(short *)&((BoxTask *)(p))->work->counter));
            break;
        case 4:
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF918, 4);
            break;
        case 5:
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x1B);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF8EC, 2);
            break;
        }
        if (*(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA170) == 1) {
            *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA170) = 0;
            if ((((BoxTask *)(p))->params->mode) == 3) {
                if (p->cursorSlot >= 0x1E) {
                    BOX2_SEQ_SetSlotActors((char *)p, 0x82, 0);
                } else {
                    BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
                    BOX2_SEQ_SetSlotActors((char *)p, 0x81, 0);
                }
            } else {
                if (p->cursorSlot >= 0x1E) {
                    BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
                } else {
                    BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
                    BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
                }
            }
        }
        BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0xE);
    case 1:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
        switch ((((BoxTask *)(p))->params->mode)) {
        case 1:
            BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
            return 0x2C;
        case 0:
            BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
            return 0x31;
        case 2:
            BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
            if (p->cursorSlot < 0x1E)
                return 0x11;
            return 0x1B;
        case 3:
            if (*(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C) == 0)
                BOX2_SEQ_PrintPromptB((BoxTask *)p, 0, 0x18);
            else
                BOX2_SEQ_PrintPromptB((BoxTask *)p, 1, 0x18);
            if (p->cursorSlot < 0x1E)
                return 0x39;
            return 0x46;
        case 4:
            BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
            if (p->cursorSlot < 0x1E)
                return 0x23;
            return 0x27;
        case 5:
            BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
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
int BOX2_SEQ_SetBox2Main(unsigned char *p)
{
    unsigned x, y;
    Scroll *s;
    unsigned old;
    int d;

    if (BOX2_UI_GetBackButtonPoint(&x, &y) == 0) {
        func_020307B0((((BoxTask *)(p))->work->scroll));
        return (((BoxTask *)(p))->state);
    }
    s = (((BoxTask *)(p))->work->scroll);
    old = (((BoxTask *)(p))->work->cursorY);
    (((BoxTask *)(p))->work->cursorY) = y;
    d = old - y;
    if (ABS(d) >= 3) {
        s->left = ABS(d) / 8;
        if (y < old) {
            s->dir = 1;
            BOX2_MAIN_SelectBox((BoxTask *)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(p))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxUp, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxLeft, 0xF);
        }
        if (y > old) {
            s->dir = -1;
            BOX2_MAIN_SelectBox((BoxTask *)p, -1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(p))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxDown, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxRight, 0xF);
        }
    }
    if (s->left != 0) {
        s->left--;
        if (s->dir == 1) {
            BOX2_MAIN_SelectBox((BoxTask *)p, 1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(p))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxUp, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxLeft, 0xF);
        }
        if (s->dir == -1) {
            BOX2_MAIN_SelectBox((BoxTask *)p, -1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            if ((((BoxTask *)(p))->state) == 0x15)
                return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxDown, 0xF);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxRight, 0xF);
        }
    }
    return 0xF;
}



















/*
 * State handler (table entry at 0x021EFABC) that forwards to
 * BOX2_SEQ_StatePlayCry.
 */
int BOX2_SEQ_StateCloseBox(unsigned char *p)
{
    return BOX2_SEQ_StatePlayCry((BoxTask *)p);
}

int BOX2_SEQ_StateBoxMenu(BoxTask *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        p->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)p, 0x14);
    }
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            return BOX2_SEQ_SelectSlotA((BoxTask *)p, r);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            BOX2_UI_ShowWindowA((char *)p->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x11);
        }
        return 0x11;
    }
    r = BOX2_UI_UpdateCursorInputC((BoxTask *)p);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 1, 0x11);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 1, 0x11);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1A));
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->barOpenFlag = 0;
        p->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x14));
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 0;
        p->heldSlot = p->curBox;
        p->pickedSlot = 0x25;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 1, 0x4F);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 0;
        p->pickedSlot = 0x26;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x55));
    case 0x28:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x59));
    case 0x29: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x13);
    }
    case 0x2A:
        p->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)p, 0x14);
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 1, 0x11);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 1, 0x11);
        }
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27 && v != 0x28 && v != 0x29)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x11));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x13);
        }
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 0x24, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
            return BOX2_SEQ_GotoSlotHandlerA((BoxTask *)p, r, 0x11);
        }
        break;
    }
    return 0x11;
}

int BOX2_SEQ_StateOpenSummary(BoxTask *p)
{
    BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
    BOX2_SEQ_Delete(p);
    CURSOR_MOVE_SetCurrent(((struct Obj23892 *)(*(char * *)&p->work))->f70, 0x24);
    BOX2_UI_SetCursorPos((char **)p, 0x24);
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
    BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
    return 0x11;
}

/*
 * Re-key the p+0x2c+0x74 object, clear the frame, retag 0x18,
 *   forward the status bytes, refresh, then store state 0x11 with the
 *   0x021E070D thumb pointer as the selector.  Six-member wrapper family
 *   (see BOX2_SEQ_SetBox2UiB / BOX2_SEQ_SetBox2UiC / BOX2_SEQ_SetBox2UiD / BOX2_SEQ_SetBox2UiE /
 *   BOX2_SEQ_SetBox2UiF): only the mid call, the selector and the state differ.
 */
void BOX2_SEQ_SetBox2Ui(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowA((char *)(*(int *)&p->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)p, 0x11));
}

int BOX2_SEQ_StateSummary(u8 *p)
{
    switch(*(int *)(((char *)((BoxTask *)(p))->work)+0xA194)) {
    case 0:
        p[0x19]=p[0x14];
        if((((BoxTask *)(p))->listState)==1) {
            p[0x17]=255;
            p[0x16]=CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(p))->work)+0x70));
            if(p[0x16]>=30) {
                p[0x16]=0;
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p[0x16]);
            }
        } else {
            p[0x17]=p[0x14];
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work),24);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work),p[0x16]);
        }
        BOX2_SEQ_SetCursorDraw((char **)p,0);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74));
        (*(int *)(((char *)((BoxTask *)(p))->work)+0xA194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_IsWindowMoving,20);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(p))->work)+0xA194))++;
        return BOX2_SEQ_ResetEntry((char *)p,20);
    case 2:
        BOX2_UI_MoveCursor((char **)p,4,p[0x16]);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p,6);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p,0,1,0);
        *(int *)(((char *)((BoxTask *)(p))->work)+0xA168)=p[0x16];
        *(int *)(((char *)((BoxTask *)(p))->work)+0xA194)=0;
        if((((BoxTask *)(p))->listState)==1) {
            if(!BOX2_MAIN_GetPartyValueAt((void ***)p,p[0x16],p[0x14],0xA9,0))
                BOX2_UI_DeleteSlotObjects((BoxTask *)p,0,1,2);
            BOX2_SEQ_SetWindow9((BoxTask *)p,13,1);
            return 21;
        }
        if((((BoxTask *)(p))->listState)==2) BOX2_SEQ_SetWindow9((BoxTask *)p,13,1);
        else BOX2_SEQ_SetWindow9((BoxTask *)p,14,1);
        return BOX2_SEQ_SelectBoxSlot((BoxTask *)p,p[0x16]);
    }
    return 20;
}

























int BOX2_SEQ_StateSummaryInput(BoxTask *p)
{
    unsigned r;
    unsigned x;
    unsigned y;
    if (p->exitFlag == 1) {
        p->listState = 0;
        p->exitFlag = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x16);
    }
    if ((KEY_GetTrg() & 4) && p->listState != 0 && p->handMode == 0) {
        BOX2_MAIN_PlayCursorSound((BoxTask *)p);
        p->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x16);
    }
    if (p->handMode == 0) {
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
                CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
                return BOX2_SEQ_SelectSlotD((BoxTask *)p, r, 0x15);
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
            BOX2_UI_SelectSlot((BoxTask *)p, r);
            *(int *)((char *)p->work + 0xA168) = r;
            BOX2_UI_SetCursorPos((char **)p, r);
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            return 0x15;
        }
    }
    if (BOX2_UI_GetExitButtonPoint(&x, &y) == 1) {
        *(unsigned *)((char *)p->work + 0xA184) = y;
        p->state = 0x15;
        BOX2_SEQ_CreateC((BoxTask *)p);
        return 0xF;
    }
    r = BOX2_UI_CursorInputLeft((BoxTask *)p);
    switch (r) {
    case 0x1E:
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        if (p->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        BOX2_UI_SelectSlot((BoxTask *)p, 0x1E);
        *(int *)((char *)p->work + 0xA168) = 0x1E;
        if (p->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x15);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        BOX2_UI_SelectSlot((BoxTask *)p, 0x1E);
        *(int *)((char *)p->work + 0xA168) = 0x1E;
        if (p->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x15);
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (p->handMode == 0)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x19));
    case 0x28:
        if (p->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v >= 0x1E || BOX2_MAIN_GetPartyValueAt((void ***)p, v, p->curBox, 0xA9, 0) == 0)
                break;
            p->cursorSlot = v;
            p->heldSlot = p->curBox;
            p->menuMode = 2;
        } else {
            p->menuMode = 3;
            p->listCursorId = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        }
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 8, 1, 0x4F);
    case 0x29:
        if (p->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x16));
    case 0x2A:
        if (p->listState == 0 || p->handMode != 0)
            break;
        p->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x16);
    case -2:
        if (p->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)p, 0xFF, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x16));
    case -8:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x22)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)p, -1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxDown, 0x15);
    case -7:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x25)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)p, 1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxUp, 0x15);
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x15);
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x1E)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x15);
    case -3: {
        unsigned char v;
        GFL_USE_PlaySeDefaultVolume(0x548);
        v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (p->handMode == 0) {
            if (v < 0x1E)
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
            else
                BOX2_MAIN_ResetBoxView((BoxTask *)p);
        }
        if (v >= 0x22 && v <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, v - 0x22, 1);
        else
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x15));
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)p, -1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxDown, 0x15);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)p, 1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxUp, 0x15);
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, r - 0x22, 1);
        if (p->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)p, r + 2, 0x15);
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        *(unsigned char *)((char *)p->work + 0xA17F) = p->prevBox + r - 0x22;
        if (*(unsigned char *)((char *)p->work + 0xA17F) >= p->boxLimit)
            *(unsigned char *)((char *)p->work + 0xA17F) -= p->boxLimit;
        if (*(unsigned char *)((char *)p->work + 0xA17F) != p->curBox)
            return BOX2_SEQ_DrawListSlot((BoxTask *)p, 0);
        break;
    case -1:
        break;
    default:
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        if (p->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)p, r, 0x15);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            p->cursorSlot = r;
            p->heldSlot = p->curBox;
            BOX2_SEQ_SwapSlotActors((char *)p->work, p->cursorSlot);
            return BOX2_SEQ_SelectBoxSlot((BoxTask *)p, p->cursorSlot);
        }
        break;
    }
    return 0x15;
}









int BOX2_SEQ_StateSummaryClose(u8 *p)
{
    unsigned n;
    switch(*(int *)(((char *)((BoxTask *)(p))->work)+0xA194)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p,0);
        BOX2_UI_SetMiniIconVisible((BoxTask *)p,0,0);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p,0,0,1);
        if(CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(p))->work)+0x70))>=30) BOX2_MAIN_ResetBoxView((BoxTask *)p);
        (*(int *)(((char *)((BoxTask *)(p))->work)+0xA194))++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_ResetEntryB((BoxTask *)p,22);
    case 1:
        if(p[0x1B]==1) {
            BOX2_UI_PutBottomBarClosed(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74));
            BOX2_UI_CloseBar(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74));
            (*(int *)(((char *)((BoxTask *)(p))->work)+0xA194))++;
            return BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_IsWindowBusy,22);
        }
        n=CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(p))->work)+0x70));
        if(n>=30) n=0;
        BOX2_UI_MoveCursor((char **)p,3,n);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p,6);
        BOX2_SEQ_SetWindow9((BoxTask *)p,14,1);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,n);
        *(int *)(((char *)((BoxTask *)(p))->work)+0xA194)=0;
        return 17;
    case 2:
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        *(int *)(((char *)((BoxTask *)(p))->work)+0xA194)=0;
        return 33;
    }
    return 22;
}










/*
 * Re-entry of the box menu: restores the cursor, redraws the box and picks
 * the message for the current mode.
 */
int BOX2_SEQ_StateSwapMenu(unsigned char *p)
{
    unsigned char sel;
    int arg;
    BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
    p[0x18] = 0;
    p[0x17] = 0xFF;
    if ((((BoxTask *)(p))->work->result) == 0) {
        sel = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
    } else {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p[0x16]);
        BOX2_UI_SetCursorPos((char **)p, p[0x16]);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        sel = p[0x16];
    }
    *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = sel;
    BOX2_SEQ_Delete((BoxTask *)p);
    if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
        if ((((BoxTask *)(p))->state) == 0x20) {
            BOX2_UI_MoveCursor((char **)p, 4, sel);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, sel);
            (((BoxTask *)(p))->state) = 0x15;
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x1E && BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0)) {
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, sel);
            arg = 0;
        } else {
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            arg = 2;
        }
    } else if (BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
        if ((((BoxTask *)(p))->state) == 0x15) {
            sel = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (sel > 0x20)
                sel = p[0x16];
            BOX2_UI_MoveCursor((char **)p, 6, sel);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, sel);
            (((BoxTask *)(p))->state) = 0x20;
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0))
                arg = 0;
            else
                arg = 2;
        } else if (sel < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0)) {
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, sel);
            arg = 0;
        } else {
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            arg = 2;
        }
    } else if (sel < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)p, sel, p[0x14], 0xA9, 0)) {
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, sel);
        arg = 0;
    } else {
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        arg = 2;
    }
    if (((Nib_021E09E0 *)(p + 0x1C))->lo == 0) {
        ((Nib_021E09E0 *)(p + 0x1C))->hi = 1;
        arg = p[0x21];
    }
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, arg);
    switch ((((BoxTask *)(p))->work->result)) {
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMenuRow((char *)p, 2, 0x18);
        return 0x18;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMenuRow((char *)p, 3, 0x18);
        return 0x18;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMenuRow((char *)p, 4, 0x18);
        return 0x18;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintYesNo((char *)p, 0);
        return 0x18;
    }
    if (((struct Obj23893 *)(*(char * *)&((BoxTask *)p)->params))->f24 == 2) {
        if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(p))->work->winMgr)) == 1)
            BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        else
            BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
    }
    return (((BoxTask *)(p))->state);
}










int BOX2_SEQ_StateSwapConfirm(BoxTask *p)
{
    int n;
    if (BOX2_SEQ_StateWaitInput(p) == 6)
        return 0x18;
    if (CURSOR_MOVE_GetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70)) == 1)
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 1);
    if ((unsigned char)((char *)((BoxTask *)(p))->work)[0xA173] == 5)
        n = 0x1B;
    else
        n = 0x18;
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), n);
    BOX2_MAIN_RefreshCursorBox(p);
    if (((struct Obj23894 *)(*(char * *)&p->params))->f24 == 2) {
        if (BOX2_UI_IsInfoBarOpen(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74)) == 1)
            BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        else
            BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
    }
    ((char *)((BoxTask *)(p))->work)[0xA173] = 0;
    return p->state;
}










int BOX2_SEQ_StateSwapApply(u8 *p)
{
    switch(*(int *)(((char *)((BoxTask *)(p))->work)+0xA194)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work),4,0);
        BOX2_UI_SetMiniIconVisible((BoxTask *)p,0,0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(p))->work)+0xA194))++;
        return BOX2_SEQ_ResetEntryB((BoxTask *)p,25);
    case 1:
        BOX2_UI_PutBottomBarClosed(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74));
        BOX2_UI_CloseBar(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74));
        if(p[0x18]==1) BOX2_SEQ_HidePartialSlots((char **)p,1);
        else BOX2_SEQ_HidePartialSlots((char **)p,0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(p))->work)+0xA194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_IsWindowBusy,25);
    case 2:
        BOX2_UI_MoveCursor((char **)p,6,30);
        BOX2_UI_SelectSlot((BoxTask *)p,30);
        if(p[0x18]==0) BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,30);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        *(int *)(((char *)((BoxTask *)(p))->work)+0xA168)=30;
        *(int *)(((char *)((BoxTask *)(p))->work)+0xA194)=0;
        return 32;
    }
    return 25;
}






















int BOX2_SEQ_StateSwapFinish(BoxTask *p)
{
    switch (*(int *)(((char *)((BoxTask *)(p))->work) + 0xA194)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_PutBottomBarOpen(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        BOX2_UI_CloseBar(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        BOX2_SEQ_HidePartialSlots((char **)p, 0);
        if (((struct Obj23895 *)(*(char * *)&p->params))->f24 == 3)
            BOX2_SEQ_SetSlotActors((char *)p, 0x82, 1);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (*(int *)(((char *)((BoxTask *)(p))->work) + 0xA194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x1A);
    case 1:
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA194) = 0;
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, 0x1E);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        if (((struct Obj23896 *)(*(char * *)&p->params))->f24 == 3) {
            BOX2_UI_MoveCursor((char **)p, 8, 0);
            return 0x46;
        } else {
            BOX2_UI_MoveCursor((char **)p, 5, 0);
            return 0x1B;
        }
    }
    return 0x1A;
}















/*
 * Sibling of src/matched/ov170_func_021E2650.c.  The image computes r + 0x1E
 * separately for BOX2_MAIN_ChangeBoxFormPreserve and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int BOX2_SEQ_StateMoveMove(BoxTask *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        p->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)p, 0x1F);
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotA((unsigned char *)p, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            BOX2_UI_ShowWindowB((char *)p->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x1B);
        }
        return 0x1B;
    }
    r = BOX2_UI_UpdateCursorInputD((BoxTask *)p);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1C));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1C));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->barOpenFlag = 1;
        p->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->heldSlot = p->curBox;
        p->menuMode = 1;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 1, 0x4F);
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 1;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
    case 12:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x55));
    case 13:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x59));
    case 14: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x1D);
    }
    case 15:
        p->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)p, 0x1F);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 6)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x1B));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x1D);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 9, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 9);
            return BOX2_SEQ_GotoSlotHandlerB((BoxTask *)p, r + 0x1E, 0x1B);
        }
        break;
    }
    return 0x1B;
}
















int BOX2_SEQ_StateMoveFinish(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_UI_OpenBar((((BoxTask *)(p))->work->winMgr));
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x1c);
    case 1:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        if (((struct Obj23897 *)(*(char * *)&p->params))->f24 == 3) {
            BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
            BOX2_UI_MoveCursor((char **)p, 7, 0x21);
            return 0x39;
        } else {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_MoveCursor((char **)p, 3, 0x21);
            return 0x11;
        }
    }
    return 0x1c;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowB and state 0x1b.
 */
void BOX2_SEQ_SetBox2UiB(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowB((char *)(*(int *)&p->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)p, 0x1B));
}

int BOX2_SEQ_StateOpenSummaryB(BoxTask *p)
{
    GFL_USE_PlaySeDefaultVolume(0x667);
    BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
    BOX2_SEQ_Delete(p);
    CURSOR_MOVE_SetCurrent(((struct Obj23898 *)(*(char * *)&p->work))->f70, 9);
    BOX2_UI_SetCursorPos((char **)p, 9);
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
    BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
    return 0x1b;
}

























/*
 * Three-step state machine on the work word at 0xA194: restore the cursor,
 * close the prompt, then redraw the box.  The dispatch and the step-1
 * increment read the work pointer through a local loaded once at the top; with
 * the macro on both, the 0xA194 offset is CSEd into the increment and takes r4.
 */
int BOX2_SEQ_StateSummaryB(BoxTask *p)
{
    char *w = ((char *)((BoxTask *)(p))->work);
    switch (((BoxWork *)w)->seqStep) {
    case 0:
        if ((((BoxTask *)(p)))->listState == 1) {
            p->heldSlot = 0xFF;
            p->cursorSlot = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (BOX2_UI_IsTopBarClosed((((BoxTask *)(p))->work->winMgr)) == 1) {
                if (p->cursorSlot >= 6)
                    p->cursorSlot = 0x1E;
                else
                    p->cursorSlot += 0x1E;
            } else if (p->cursorSlot >= 0x1E) {
                p->cursorSlot = 0;
            }
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
        } else {
            if (BOX2_UI_IsTopBarClosed((((BoxTask *)(p))->work->winMgr)) == 1)
                p->heldSlot = 0xFF;
            else
                p->heldSlot = p->curBox;
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
            BOX2_MAIN_RefreshCursorBox(p);
            BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
        }
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x1F);
    case 1:
        if (*(int *)(((char *)((BoxTask *)(p))->params) + 0x24) == 4 && *(int *)(((char *)((BoxTask *)(p))->params) + 0x14) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintYesNo((char *)p, 0);
            (((BoxTask *)(p)))->listState = 0;
            (((BoxTask *)(p))->work->seqStep) = 0;
            (((BoxTask *)(p))->state) = 0x2B;
            return 6;
        }
        (((BoxWork *)w)->seqStep)++;
        if (BOX2_UI_IsTopBarClosed((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_SlideBarIn((((BoxTask *)(p))->work->winMgr));
        } else {
            BOX2_UI_PutBottomBarClosed((((BoxTask *)(p))->work->winMgr));
            BOX2_UI_CloseBar((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_HidePartialSlots((char **)p, 0);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x1F);
    case 2:
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 0);
        BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = p->cursorSlot;
        (((BoxTask *)(p))->work->seqStep) = 0;
        if ((((BoxTask *)(p)))->listState == 1) {
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 0xA9, 0) == 0)
                BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 2);
            if (*(int *)(((char *)((BoxTask *)(p))->params) + 0x24) == 4) {
                BOX2_UI_HideWindowA(((char *)((BoxTask *)(p))->work));
                BOX2_UI_HideWindowB(((char *)((BoxTask *)(p))->work));
                CURSOR_MOVE_ClearSkipBit((((BoxTask *)(p))->work->sound), 0x27);
            }
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xD, 1);
            return 0x20;
        }
        if ((((BoxTask *)(p)))->listState == 2)
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xD, 1);
        else
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
        BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
        return BOX2_SEQ_HideSlotWindow((BoxTask *)p, p->cursorSlot);
    }
    return 0x1F;
}

















int BOX2_SEQ_StateMoveInput(BoxTask *p)
{
    unsigned r;
    if (p->exitFlag == 1) {
        p->listState = 0;
        p->exitFlag = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x21);
    }
    if ((KEY_GetTrg() & 4) && p->listState != 0 && p->handMode == 0) {
        BOX2_MAIN_PlayCursorSound((BoxTask *)p);
        p->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x21);
    }
    if (p->handMode == 0) {
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
                return BOX2_SEQ_SelectSlotD((BoxTask *)p, r, 0x20);
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
            BOX2_UI_SelectSlot((BoxTask *)p, r);
            *(int *)((char *)p->work + 0xA168) = r;
            BOX2_UI_SetCursorPos((char **)p, r);
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            return 0x20;
        }
        r = BOX2_UI_GetBodySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
                GFL_USE_PlaySeDefaultVolume(0x666);
                TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
                return BOX2_SEQ_SelectSlotD((BoxTask *)p, r + 0x1E, 0x20);
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r + 0x1E);
            BOX2_UI_SelectSlot((BoxTask *)p, r + 0x1E);
            *(int *)((char *)p->work + 0xA168) = r + 0x1E;
            BOX2_UI_SetCursorPos((char **)p, r + 0x1E);
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            return 0x20;
        }
    }
    r = BOX2_UI_CursorInputRight((BoxTask *)p);
    switch (r) {
    case 0x24:
        if (p->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
        BOX2_UI_SetCursorPos((char **)p, 0x24);
        BOX2_UI_SelectSlot((BoxTask *)p, 0x24);
        *(int *)((char *)p->work + 0xA168) = 0x24;
        if (p->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x20);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
        BOX2_UI_SetCursorPos((char **)p, 0x24);
        BOX2_UI_SelectSlot((BoxTask *)p, 0x24);
        *(int *)((char *)p->work + 0xA168) = 0x24;
        if (p->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x20);
    case 0x27:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (p->handMode == 0)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0xB, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x22));
    case 0x28:
        if (p->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v >= 0x24 || BOX2_MAIN_GetPartyValueAt((void ***)p, v, p->curBox, 0xA9, 0) == 0)
                break;
            p->cursorSlot = v;
            p->heldSlot = p->curBox;
            p->menuMode = 4;
        } else {
            p->menuMode = 5;
            p->listCursorId = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        }
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 8, 1, 0x4F);
    case 0x29:
        if (p->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x21));
    case 0x2A:
        if (p->listState == 0 || p->handMode != 0)
            break;
        p->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x21);
    case -2:
        if (p->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)p, 0xFF, 0x20);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x21));
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x20);
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x20);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v < 0x24)
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
            else
                BOX2_MAIN_ResetBoxView((BoxTask *)p);
        }
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x20));
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (p->handMode == 1)
            return BOX2_SEQ_ScrollListToSlot((BoxTask *)p, r, 0x20);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            p->cursorSlot = r;
            p->heldSlot = p->curBox;
            BOX2_SEQ_SwapSlotActors((char *)p->work, p->cursorSlot);
            return BOX2_SEQ_HideSlotWindow((BoxTask *)p, p->cursorSlot);
        }
        break;
    }
    return 0x20;
}

int BOX2_SEQ_StateMoveClose(BoxTask *p)
{
    u8 index;
    u8 selection;
    switch (*(u32 *)(((u8 *)((BoxTask *)(p))->work) + 0xa194)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable((char *)((u8 *)((BoxTask *)(p))->work), 4, 0);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
        if (p->barOpenFlag == 0) {
            BOX2_UI_OpenBar(*(struct WinMgr **)(((u8 *)((BoxTask *)(p))->work) + 116));
            *(u32 *)(((u8 *)((BoxTask *)(p))->work) + 0xa194) = 2;
        } else {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            BOX2_UI_ToggleSlotPair((char *)((u8 *)((BoxTask *)(p))->work), 0);
            BOX2_UI_SlideBarOut(*(struct WinMgr **)(((u8 *)((BoxTask *)(p))->work) + 116));
            *(u32 *)(((u8 *)((BoxTask *)(p))->work) + 0xa194) = 1;
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 33);
    case 1:
        *(u32 *)(((u8 *)((BoxTask *)(p))->work) + 0xa194) = 0;
        index = CURSOR_MOVE_GetCurrent(*(void **)(((u8 *)((BoxTask *)(p))->work) + 112));
        if (index < 30 || index >= 36)
            selection = 0;
        else
            selection = index - 30;
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, selection + 30);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 1);
        if (((struct Obj23899 *)(*(u8 * *)&p->params))->f24 == 2) {
            BOX2_UI_MoveCursor((char **)p, 5, selection);
            return 27;
        }
        BOX2_UI_ShowWindowB((char *)((u8 *)((BoxTask *)(p))->work));
        BOX2_UI_MoveCursor((char **)p, 14, selection);
        return 39;
    case 2:
        *(u32 *)(((u8 *)((BoxTask *)(p))->work) + 0xa194) = 0;
        index = CURSOR_MOVE_GetCurrent(*(void **)(((u8 *)((BoxTask *)(p))->work) + 112));
        if (index >= 30)
            index = 0;
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, index);
        BOX2_UI_ShowWindowA((char *)((u8 *)((BoxTask *)(p))->work));
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 1);
        if (((struct Obj23900 *)(*(u8 * *)&p->params))->f24 == 4) {
            BOX2_UI_MoveCursor((char **)p, 13, index);
            return 35;
        }
        BOX2_UI_MoveCursor((char **)p, 3, index);
        return 17;
    }
    return 33;
}















int BOX2_SEQ_StateMoveCloseB(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_UI_OpenBar((((BoxTask *)(p))->work->winMgr));
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x22);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x669);
        p->prevBox = p->curBox;
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_ResetEntry((char *)p, 0x22);
    case 2:
        BOX2_UI_MoveCursor((char **)p, 4, 0x27);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xa168) = 0x27;
        (((BoxTask *)(p))->work->seqStep) = 0;
        return 0x15;
    }
    return 0x22;
}

























int BOX2_SEQ_StateItemMenuB(BoxTask *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        p->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)p, 0x1F);
    }
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF918, 4);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            p->barOpenFlag = 0;
            return BOX2_SEQ_SelectSlotB((BoxTask *)p, r);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            BOX2_UI_ShowWindowA((char *)p->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x23);
        }
        return 0x23;
    }
    r = BOX2_UI_UpdateCursorInputG((BoxTask *)p);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 1, 0x23);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 1, 0x23);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x26));
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->barOpenFlag = 0;
        p->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1F));
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 0;
        p->heldSlot = p->curBox;
        p->pickedSlot = 0x25;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, 0x4F);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 0;
        p->pickedSlot = 0x26;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
    case 0x27: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x25);
    }
    case 0x28:
        p->barOpenFlag = 0;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)p, 0x1F);
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 1, 0x23);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 1, 0x23);
        }
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x23));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x25);
        }
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF918, 4);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 0x24, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
            return BOX2_SEQ_GotoSlotHandlerA((BoxTask *)p, r, 0x23);
        }
        break;
    }
    return 0x23;
}

int BOX2_SEQ_StateOpenItemB(BoxTask *p)
{
    GFL_USE_PlaySeDefaultVolume(0x667);
    BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
    BOX2_SEQ_Delete(p);
    CURSOR_MOVE_SetCurrent(((struct Obj23901 *)(*(char * *)&p->work))->f70, 0x24);
    BOX2_UI_SetCursorPos((char **)p, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
    BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
    return 0x23;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowA and state 0x23.
 */
void BOX2_SEQ_SetBox2UiC(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowA((char *)(*(int *)&p->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)p, 0x23));
}




















int BOX2_SEQ_StateSwapMenuB(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_PutBottomBarOpen((((BoxTask *)(p))->work->winMgr));
        BOX2_UI_CloseBar((((BoxTask *)(p))->work->winMgr));
        BOX2_SEQ_HidePartialSlots((char **)p, 0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x26);
    case 1:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, 0x1e);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        BOX2_UI_MoveCursor((char **)p, 0xe, 0);
        return 0x27;
    }
    return 0x26;
}























/*
 * Sibling of src/matched/ov170_func_021E2650.c and ov170_func_021E376C.c.
 * The image computes r + 0x1E
 * separately for BOX2_MAIN_ChangeBoxFormPreserve and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int BOX2_SEQ_StateItemMoveB(BoxTask *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        p->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)p, 0x1F);
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF918, 4);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotB((BoxTask *)p, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            BOX2_UI_ShowWindowB((char *)p->work);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x27);
        }
        return 0x27;
    }
    r = BOX2_UI_UpdateCursorInputH((BoxTask *)p);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0xA, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x28));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x28));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->barOpenFlag = 1;
        p->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 1;
        p->heldSlot = p->curBox;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, 0x4F);
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->menuMode = 1;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
    case 12: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x29);
    }
    case 13:
        p->barOpenFlag = 1;
        return BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)p, 0x1F);
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x29);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x28));
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 6)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x27));
    }
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF918, 4);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 9, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 9);
            return BOX2_SEQ_GotoSlotHandlerB((BoxTask *)p, r + 0x1E, 0x27);
        }
        break;
    }
    return 0x27;
}






















int BOX2_SEQ_StateMoveFinishB(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_UI_OpenBar((((BoxTask *)(p))->work->winMgr));
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x28);
    case 1:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        BOX2_UI_MoveCursor((char **)p, 0xd, 0x21);
        return 0x23;
    }
    return 0x28;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowB and state 0x27.
 */
void BOX2_SEQ_SetBox2UiD(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowB((char *)(*(int *)&p->work));
    BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x21E070D, BOX2_SEQ_SetState((BoxTask *)p, 0x27));
}

/*
 *   void CURSOR_MOVE_SetCurrent(unsigned char *p, unsigned value) {
 *       p[13] = value; p[14] = 255; p[15] = 255;
 *   }
 */
int BOX2_SEQ_StateOpenItemC(u8 *p){BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);BOX2_SEQ_Delete((BoxTask *)p);CURSOR_MOVE_SetCurrent(*(void **)(*(char **)(p+0x2c)+0x70),9);BOX2_UI_SetCursorPos((char **)p,9);BOX2_UI_DeleteSlotObjects((BoxTask *)p,0,0,1);BOX2_SEQ_PrintPrompt((BoxTask *)p,p[0x16],1,24);return 39;}



















int BOX2_SEQ_StateMenuCursor(BoxTask *p)
{
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x1b);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_MAIN_RefreshCursorBox(p);
    if (func_020355C4() == 0)
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 1);
    if (BOX2_UI_IsTopBarClosed((((BoxTask *)(p))->work->winMgr)) == 1) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot - 0x1e);
        BOX2_UI_SetCursorPos((char **)p, p->cursorSlot - 0x1e);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        return 0x27;
    } else {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot);
        BOX2_UI_SetCursorPos((char **)p, p->cursorSlot);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        return 0x23;
    }
}





















int BOX2_SEQ_StateItemMenuC(BoxTask *p)
{
    unsigned r;
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9B4, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            return BOX2_SEQ_SelectSlotC((BoxTask *)p, r);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x2C);
        }
        return 0x2C;
    }
    r = BOX2_UI_UpdateCursorInputB((BoxTask *)p);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x2C);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x2C);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 1, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x2E));
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->heldSlot = p->curBox;
        p->pickedSlot = 0x24;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, 0x4F);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x55));
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x59));
    case 0x27: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x2D);
    }
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x2C);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x2C);
        }
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
        else if (v != 0x23 && v != 0x24 && v != 0x25 && v != 0x26 && v != 0x27)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x2C));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x2D);
        }
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9B4, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 0x23, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x23);
            return BOX2_SEQ_GotoSlotHandlerA((BoxTask *)p, r, 0x2C);
        }
        break;
    }
    return 0x2C;
}

void BOX2_SEQ_SetBox2MainB(u8 *p){BOX2_UI_OpenListPack(*(struct WinMgr * *)&((struct Obj23902 *)(*(char * *)&((BoxTask *)p)->work))->f74);BOX2_SEQ_SetSlotDim((char **)p,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)p)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)p);BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_SceneWaitScroll,BOX2_SEQ_SetState((BoxTask *)p,44));}




















int BOX2_SEQ_StateCloseBoxB(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x2e);
    case 1:
        if (POKEPARTY_GetCount(((void **)p->params)[2]) != 6)
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x2f);
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintPrompt((BoxTask *)p, 0, 2, 0x18);
        p->state = 0xe;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
    }
    return 0x2e;
}

int BOX2_SEQ_StateOpenBoxC(u8 *p)
{
    switch (*(u32 *)(*(u8 **)(p + 44) + 0xa194)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_SEQ_HideSlotsC61C((BoxTask *)p);
        BOX2_UI_PutBottomBarClosed((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        BOX2_UI_CloseBar((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        p[26] = 2;
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 47);
    case 1:
        p[23] = p[20];
        BOX2_SEQ_SwapSlotActors(*(char **)(p + 44), p[22]);
        BOX2_SEQ_Create((void *)p);
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineClose, 47);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
        BOX2_SEQ_Delete((BoxTask *)p);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        BOX2_UI_OpenBar((struct WinMgr *)(*(int *)(*(u8 **)(p + 44) + 116)));
        (*(u32 *)(*(u8 **)(p + 44) + 0xa194))++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 47);
    case 3:
        CURSOR_MOVE_SetCurrent(*(void **)(*(u8 **)(p + 44) + 112), p[22]);
        BOX2_UI_SetCursorPos((char **)p, p[22]);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        p[22] = 255;
        *(u32 *)(*(u8 **)(p + 44) + 0xa194) = 0;
        return 44;
    }
    return 47;
}











int BOX2_SEQ_DeleteBox2UiB(BoxTask *p)
{
    unsigned r = *(unsigned *)(*(char **)(((char *)((BoxTask *)(p))->work) + 0x60) + 0xac);
    BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
    BOX2_SEQ_Delete(p);
    BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
    if (p->cursorSlot != 0xff) {
        BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
        r = 0x23;
    }
    CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
    BOX2_UI_SetCursorPos((char **)p, r);
    return 0x2c;
}





















int BOX2_SEQ_StateItemMenuD(BoxTask *p)
{
    unsigned r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 0)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF950, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            return BOX2_SEQ_SelectPartySlotC((BoxTask *)p, r + 0x1E);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r + 0x3C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x31);
        }
        return 0x31;
    }
    r = BOX2_UI_UpdateCursorInputA((BoxTask *)p);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 1, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x34));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->pickedSlot = 9;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, 0x4F);
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x55));
    case 11:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x59));
    case 12: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x32);
    }
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 6)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v + 0x1E);
        else if (v != 8 && v != 9 && v != 10 && v != 11 && v != 12)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x31));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x32);
        }
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF950, 5);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 8, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 8);
            return BOX2_SEQ_GotoSlotHandlerB((BoxTask *)p, r + 0x1E, 0x31);
        }
        break;
    }
    return 0x31;
}

void BOX2_SEQ_SetBox2MainC(u8 *p){BOX2_UI_OpenListPack(*(struct WinMgr * *)&((struct Obj23904 *)(*(char * *)&((BoxTask *)p)->work))->f74);BOX2_SEQ_SetSlotDim((char **)p,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)p)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)p);BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_SceneWaitScroll,BOX2_SEQ_SetState((BoxTask *)p,49));}

























/*
 * Refresh the tag-derived index, re-key, arm, retag 0x18, forward,
 *   and report 0x31.
 */
int BOX2_SEQ_StateCursorMove(BoxTask *p)
{
    CURSOR_MOVE_SetCurrent((struct Sound *)(*(int *)(*(int *)&p->work + 0x70)),
                  (unsigned char)(p->cursorSlot - 0x1e));
    BOX2_UI_SetCursorPos((char **)p, p->cursorSlot - 0x1e);
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    return 0x31;
}

/*
 * Five-step machine on the work word at 0xA194: fade out, confirm the
 * party slot (or back out to state 0x33), fade, swap, then reopen.
 */
int BOX2_SEQ_StateSummaryC(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x34);
    case 1:
        switch (BOX2_SEQ_CheckTradableMon((unsigned char *)p)) {
        case 0:
            p->handMode = 1;
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
            BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), 0x24, 0);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
            BOX2_UI_SetCursorPos((char **)p, p->cursorSlot - 0x1E);
            (((BoxTask *)(p))->work->seqStep)++;
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneWaitCursor, 0x34);
        case 1:
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_PrintMonName((BoxTask *)p, 6, 0x18);
            (((BoxTask *)(p))->state) = 0x33;
            (((BoxTask *)(p))->work->seqStep) = 0;
            return 6;
        case 2:
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_PrintPrompt((BoxTask *)p, 0, 5, 0x18);
            (((BoxTask *)(p))->state) = 0x33;
            (((BoxTask *)(p))->work->seqStep) = 0;
            return 6;
        }
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_UI_OpenBar((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x34);
    case 3:
        BOX2_UI_PlaceCursorAtIcon((BoxTask *)p, p->cursorSlot - 0x1E);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneApplyScroll, 0x34);
    case 4:
        func_020307B0(*(void **)(((char *)((BoxTask *)(p))->work) + 0x60));
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_PrintPrompt((BoxTask *)p, 0, 3, 0x1A);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
        BOX2_UI_MoveCursor((char **)p, 1, 0);
        (((BoxTask *)(p))->work->seqStep) = 0;
        return 0x35;
    }
    return 0x34;
}

/*
 * Party list input: L and R page the list when nothing is picked; a pick
 * of the first two rows opens the slot (or refuses it), the others page,
 * jump or cancel.
 */
int BOX2_SEQ_StateListScroll(BoxTask *p)
{
    unsigned r;
    unsigned b, a;

    r = CURSOR_MOVE_PollRepeatInput((((BoxTask *)(p))->work->sound));
    if (r == (unsigned)-1) {
        if (KEY_GetRepeat() & 0x200) {
            BOX2_MAIN_PlayCursorSound(p);
            r = 2;
        } else if (KEY_GetRepeat() & 0x100) {
            BOX2_MAIN_PlayCursorSound(p);
            r = 3;
        }
    }
    switch (r) {
    case 0:
    case 1:
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0);
        if (func_020077B8(*(void **)(((char *)((BoxTask *)(p))->params) + 4), p->curBox) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintPrompt((BoxTask *)p, 0, 4, 0x18);
            (((BoxTask *)(p))->state) = 0x37;
            return 6;
        }
        a = p->curBox;
        b = 0;
        func_020076D0(*(void **)(((char *)((BoxTask *)(p))->params) + 4), (int *)(&a), (int *)(&b));
        *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA17E) = b;
        p->phase = 0;
        p->heldSlot = p->curBox;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x36);
    case 2:
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0);
    case (unsigned)-6:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x35);
    case 3:
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0);
    case (unsigned)-5:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x35);
    case 4:
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA17E) = 0xFF;
        p->heldSlot = p->curBox;
        p->phase = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x36));
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
int BOX2_SEQ_StateScrollBox(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        if (p->work->targetBox == 0xFF) {
            BOX2_UI_PlaceCursorAtMon((BoxTask *)p, p->cursorSlot);
            (((BoxTask *)(p))->work->seqStep) = 1;
        } else {
            BOX2_UI_PlaceCursorAtMon((BoxTask *)p, p->work->targetBox);
            (((BoxTask *)(p))->work->seqStep) = 4;
        }
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneApplyScroll, 0x36);
    case 1:
        func_020307B0(*(void **)(((char *)((BoxTask *)(p))->work) + 0x60));
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_UI_CloseBar((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep) = 2;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x36);
    case 2:
        BOX2_SEQ_Create((void *)p);
        (((BoxTask *)(p))->work->seqStep) = 6;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneOpenBox, 0x36);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_UI_CloseBar((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep) = 7;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x36);
    case 4:
        func_020307B0(*(void **)(((char *)((BoxTask *)(p))->work) + 0x60));
        BOX2_SEQ_Create((void *)p);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        (((BoxTask *)(p))->work->seqStep) = 5;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_Check09E0, 0x36);
    case 5:
        BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
        BOX2_SEQ_Delete(p);
        BOX2_MAIN_ResetBoxView(p);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        (((BoxTask *)(p))->work->seqStep) = 3;
        break;
    case 6:
        BOX2_SEQ_Delete(p);
    case 7:
        p->handMode = 0;
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
        BOX2_UI_MoveCursor((char **)p, 0, p->cursorSlot - 0x1E);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
        (((BoxTask *)(p))->work->seqStep) = 0;
        return 0x31;
    }
    return 0x36;
}

int BOX2_SEQ_StateOpenItemD(u8 *p){BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)p)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)p);BOX2_SEQ_PrintPrompt((BoxTask *)p,0,3,26);BOX2_UI_DeleteSlotObjects((BoxTask *)p,0,1,1);return 53;}





















int BOX2_SEQ_StateOpenItemE(unsigned char *p)
{
    BOX2_MAIN_UpdateBoxSlots((unsigned char *)p);
    BOX2_SEQ_Delete((BoxTask *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
    if (p[0x16] == 0xff) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0);
        BOX2_UI_SetCursorPos((char **)p, 0);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, 0x1e);
    } else {
        BOX2_SEQ_PrintPrompt((BoxTask *)p, p[0x16], 1, 0x18);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 8);
        BOX2_UI_SetCursorPos((char **)p, 8);
    }
    return 0x31;
}
















int BOX2_SEQ_StateItemMenuE(BoxTask *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        r = BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)p, 0x3F);
        if (p->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v < 0x1E)
                p->cursorSlot = v;
            else
                p->cursorSlot = 0;
        }
        return r;
    }
    r = BOX2_UI_GetPartySlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            return BOX2_SEQ_DrawGridSlot((BoxTask *)p, r);
        }
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, r, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
            return BOX2_SEQ_SetBox2UiE((BoxTask *)p);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        return 0x39;
    }
    r = BOX2_UI_UpdateCursorInputE((BoxTask *)p);
    switch (r) {
    case 0x1E:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 1, 0x39);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 1, 0x39);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 10, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1A));
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 0x23:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case 0x24:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x3F));
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (*(unsigned short *)((char *)p->work + 0xA16C) == 0) {
            p->menuMode = 0;
            p->pickedSlot = 0x25;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
        }
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
    case 0x26: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x3A);
    }
    case 0x27:
        r = BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)p, 0x3F);
        if (p->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v < 0x1E)
                p->cursorSlot = v;
            else
                p->cursorSlot = 0;
        }
        return r;
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 1, 0x39);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 1, 0x39);
        }
        break;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
        else if (v != 0x24 && v != 0x25 && v != 0x26)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x39));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x3A);
        }
        p->params->swapMode = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return BOX2_SEQ_SetCursorMove((BoxTask *)p, r);
        }
        break;
    }
    return 0x39;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowA, state 0x39 and
 *   0x021E0E51 as the selector.
 */
int BOX2_SEQ_SetBox2UiE(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowA((char *)(*(int *)&p->work));
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x21E0E51, BOX2_SEQ_SetState((BoxTask *)p, 0x39));
}















int BOX2_SEQ_DeleteBox2UiC(BoxTask *p)
{
    if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 0xa) == 1)
        return 0x3b;
    BOX2_SEQ_SetActorAnim((BoxTask *)p, 0);
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 0xa, 0);
    BOX2_SEQ_PrintPromptB((BoxTask *)p, 3, 0x18);
    if (p->cursorSlot < 0x1e) {
        BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
    } else {
        BOX2_SEQ_SetSlotActors((char *)p, 0x82, 1);
    }
    *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xa16c) = 0;
    p->state = 0x3d;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
}

void BOX2_SEQ_StateCloseBoxC(u8 *p){BOX2_SEQ_SetSlotDim((char **)p,0);BOX2_SEQ_ShowWindowObject(*(char * *)&((BoxTask *)p)->work,24);BOX2_MAIN_RefreshCursorBox((BoxTask *)p);if(p[0x16]<30)BOX2_UI_ShowWindowA(*(char * *)&((BoxTask *)p)->work);else BOX2_UI_ShowWindowB(*(char * *)&((BoxTask *)p)->work);BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_Check0F4C,61);}























int BOX2_SEQ_StateMenuItems(BoxTask *p)
{
    int r;
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    if (p->cursorSlot < 0x1e) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot);
        BOX2_UI_SetCursorPos((char **)p, p->cursorSlot);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        r = 0x39;
    } else {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot - 0x1e);
        BOX2_UI_SetCursorPos((char **)p, p->cursorSlot - 0x1e);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        r = 0x46;
    }
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    BOX2_SEQ_SetWindow9((BoxTask *)p, 0xe, 1);
    return r;
}

int BOX2_SEQ_StateSelectItem(u8 *p){int sel;sel=37;if(*(u16 *)(*(char **)(p+0x2c)+0xa16c)!=0)sel=36;CURSOR_MOVE_SetCurrent(*(void **)(*(char **)(p+0x2c)+0x70),sel);BOX2_UI_SetCursorPos((char **)p,sel);BOX2_SEQ_SetCursorDraw((char **)p,1);return 57;}





















/*
 * Three-step machine on the work word at 0xA194: close the held view,
 * fade, then reopen the menu for the current nibble mode.
 */
int BOX2_SEQ_StateSummaryD(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        (((BoxTask *)(p))->work->seqStep)++;
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        if (BOX2_UI_IsTopBarClosed((((BoxTask *)(p))->work->winMgr)) == 1)
            p->barFlag = 1;
        else
            p->barFlag = 0;
        if ((((BoxTask *)(p)))->listState == 1) {
            p->heldSlot = 0xFF;
            *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C) = 0;
            BOX2_MAIN_RefreshCursorBox(p);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
        } else {
            if ((((BoxTask *)(p)))->listState == 2 && *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C) == 0) {
                p->heldSlot = 0xFF;
                (((BoxTask *)(p)))->listState = 1;
            }
            BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
            BOX2_MAIN_RefreshCursorBox(p);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_Check0ED4, 0x3F);
        }
    case 1:
        (((BoxTask *)(p))->work->seqStep)++;
        if (BOX2_UI_IsTopBarClosed((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_SlideBarIn((((BoxTask *)(p))->work->winMgr));
        } else {
            BOX2_UI_PutBottomBarClosed((((BoxTask *)(p))->work->winMgr));
            BOX2_UI_CloseBar((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_HidePartialSlots((char **)p, 0);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x3F);
    case 2:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 0x82, 1);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        CURSOR_MOVE_ClearSkipBit((((BoxTask *)(p))->work->sound), 0x27);
        CURSOR_MOVE_ClearSkipBit((((BoxTask *)(p))->work->sound), 0x28);
        if ((((BoxTask *)(p)))->listState == 1) {
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xD, 1);
            return 0x40;
        }
        if ((((BoxTask *)(p)))->listState == 2)
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xD, 1);
        else
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 1);
        return BOX2_SEQ_DrawGridSlotB((BoxTask *)p, p->cursorSlot);
    }
    return 0x3F;
}




























/*
 * Sibling of src/matched/ov170_func_021E3E84.c.
 */
int BOX2_SEQ_StateItemMenuF(BoxTask *p)
{
    unsigned r;
    if (p->exitFlag == 1) {
        p->listState = 0;
        p->exitFlag = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x41);
    }
    if ((KEY_GetTrg() & 4) && p->listState != 0 && p->handMode == 0) {
        BOX2_MAIN_PlayCursorSound((BoxTask *)p);
        p->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x41);
    }
    if (p->handMode == 0) {
        r = BOX2_UI_GetBodySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
                BOX2_SEQ_SetActorDrawEnable((char *)p->work, 4, 0);
                return BOX2_SEQ_SelectGridSlot((BoxTask *)p, r + 0x1E);
            }
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r + 0x1E);
            return 0x40;
        }
        r = BOX2_UI_GetPartySlotHit();
        if (r != -1) {
            CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
            if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
                BOX2_SEQ_SetActorDrawEnable((char *)p->work, 4, 0);
                return BOX2_SEQ_SelectGridSlot((BoxTask *)p, r);
            }
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
            return 0x40;
        }
    }
    r = BOX2_UI_CursorInputRight((BoxTask *)p);
    switch (r) {
    case 0x24:
        if (p->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x54C);
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5D);
    case 0x25:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
        BOX2_UI_SetCursorPos((char **)p, 0x24);
        if (p->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x40);
    case 0x26:
        GFL_USE_PlaySeDefaultVolume(0x548);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
        BOX2_UI_SetCursorPos((char **)p, 0x24);
        if (p->handMode == 0)
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        else
            BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x40);
    case 0x29:
        if (p->handMode != 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x41));
    case 0x2A:
        if (p->listState == 0 || p->handMode != 0)
            break;
        p->listState = 0;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x41);
    case -2:
        if (p->handMode == 1)
            return BOX2_SEQ_MoveGridCursor((BoxTask *)p, 0xFF);
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x41));
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x40);
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) != 0x24)
            break;
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x40);
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->handMode == 0) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v < 0x24)
                BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
            else
                BOX2_MAIN_ResetBoxView((BoxTask *)p);
        }
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x40));
    case -1:
    case -7:
    case -8:
    case 0x27:
    case 0x28:
        break;
    default:
        if (p->handMode == 1)
            return BOX2_SEQ_MoveGridCursor((BoxTask *)p, r);
        return BOX2_SEQ_DrawGridSlotB((BoxTask *)p, r);
    }
    return 0x40;
}

int BOX2_SEQ_StateCloseItem(BoxTask *p)
{
    u8 index;
    u8 selection;
    switch (((struct Obj23905 *)(*(u8 * *)&p->work))->fA194) {
    case 0:
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&p->work, 4, 0);
        if (p->barFlag == 0) {
            BOX2_UI_OpenBar(*(struct WinMgr * *)&((struct Obj23906 *)(*(u8 * *)&p->work))->f74);
        } else {
            BOX2_UI_ToggleSlotPair(*(char * *)&p->work, 0);
            BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            BOX2_UI_SlideBarOut(*(struct WinMgr * *)&((struct Obj23907 *)(*(u8 * *)&p->work))->f74);
        }
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((struct Obj23908 *)(*(u8 * *)&p->work))->fA194)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 65);
    case 1:
        ((struct Obj23909 *)(*(u8 * *)&p->work))->fA194 = 0;
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
        if (p->barFlag == 0) {
            index = CURSOR_MOVE_GetCurrent(((struct Obj23910 *)(*(u8 * *)&p->work))->f70);
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            BOX2_UI_MoveCursor((char **)p, 7, index);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, index);
            BOX2_UI_ShowWindowA(*(char * *)&p->work);
            return 57;
        } else {
            index = CURSOR_MOVE_GetCurrent(((struct Obj23911 *)(*(u8 * *)&p->work))->f70);
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            BOX2_UI_MoveCursor((char **)p, 8, selection);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, selection + 30);
            BOX2_UI_ShowWindowB(*(char * *)&p->work);
            return 70;
        }
    }
    return 65;
}










/*
 * Drop of a held item onto a slot: put it back when dropped where it was
 * picked up, otherwise swap the two slots' items.
 */
int BOX2_SEQ_StateMoveItemScroll(BoxTask *p)
{
    Entry *o;
    if ((((BoxTask *)(p)))->listState == 0)
        (((BoxTask *)(p)))->exitFlag = 1;
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    o = *(Entry **)(((char *)((BoxTask *)(p))->work) + 0x60);
    if (o->idx == p->cursorSlot && (p->heldSlot == 0xFF || p->heldSlot == p->curBox)) {
        unsigned short from = o->slot;
        BOX2_SEQ_DeleteB(p);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
        if (FILE_UTIL_Check136C((((BoxTask *)(p))->work->counter)) == 1 && from != p->cursorSlot) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintMessageC((char *)p, 0x18);
            (((BoxTask *)(p))->state) = 0x44;
            return 6;
        }
        return 0x40;
    } else {
        unsigned short item;
        if (p->heldSlot == p->curBox || p->cursorSlot >= 0x1E)
            BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), p->cursorSlot, 1);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), o->idx, 0);
        item = BOX2_MAIN_GetPartyValueAt((void ***)p, o->idx, p->curBox, 6, 0);
        BOX2_MAIN_SetBoxValueAt((int)p, o->idx, p->curBox, 6, (((BoxTask *)(p))->work->counter));
        if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, o->idx)) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)p, o->idx);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, o->idx, (((BoxTask *)(p))->work->cursorTable[o->idx]));
        }
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, o->idx);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), o->idx);
        (((BoxTask *)(p))->work->counter) = item;
        BOX2_MAIN_SetBoxValueAt((int)p, p->cursorSlot, p->heldSlot, 6, (((BoxTask *)(p))->work->counter));
        if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->heldSlot, p->cursorSlot)) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)p, p->cursorSlot);
            if (p->heldSlot == 0xFF || p->heldSlot == p->curBox)
                BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, p->cursorSlot, (((BoxTask *)(p))->work->cursorTable[p->cursorSlot]));
        }
        if ((((BoxTask *)(p))->work->counter) == 0) {
            p->cursorSlot = o->idx;
            BOX2_SEQ_DeleteB(p);
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
            return 0x40;
        }
        BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->counter));
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 1);
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 1);
        BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(p))->work));
        GFL_USE_PlaySeDefaultVolume(0x666);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_Check122C, 0x43);
    }
}

int BOX2_SEQ_StateMoveItemB(BoxTask *p)
{
    unsigned short *o;
    unsigned char old;
    unsigned short slot, item;
    unsigned char r;
    if (((Flags_021E65E4 *)p)->lo == 0)
        ((Flags_021E65E4 *)p)->hi = 1;
    o = *(unsigned short **)(((char *)((BoxTask *)(p))->work) + 0x60);
    BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), o[0], 0);
    old = p->cursorSlot;
    slot = o[1];
    p->cursorSlot = o[0];
    BOX2_SEQ_DeleteB(p);
    item = *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C);
    *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C) = 0;
    if (FILE_UTIL_Check136C(item) == 1 && slot != old) {
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_PrintMessageC((char *)p, 0x18);
        p->state = 0x44;
        return 6;
    }
    BOX2_SEQ_SetCursorDraw((char **)p, 1);
    r = CURSOR_MOVE_GetCurrent(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70));
    if (r < 0x24)
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
    return 0x40;
}

/*
 *   unsigned CURSOR_MOVE_GetState(unsigned char *p) { return *(unsigned *)(p+4); }
 */
int BOX2_SEQ_StateCloseItemB(u8 *p){BOX2_SEQ_HideWindowObject(*(char **)(p+0x2c),24);BOX2_MAIN_RefreshCursorBox((BoxTask *)p);if(CURSOR_MOVE_GetState(*(void **)(*(char **)(p+0x2c)+0x70))==1)BOX2_SEQ_SetActorDrawEnable(*(char **)(p+0x2c),4,1);return 64;}










/*
 * Twin of BOX2_SEQ_StateMoveItemScroll driven by the work fields: moves the held item from
 * slot 0xA16E to slot 0xA17E, swapping with what is there.
 */
int BOX2_SEQ_StatePlaceItem(BoxTask *p)
{
    unsigned short item;
    if ((((BoxTask *)(p)))->listState == 0)
        (((BoxTask *)(p)))->exitFlag = 1;
    if ((((BoxTask *)(p))->work->targetBox) == (((BoxTask *)(p))->work->cursorIndex) && (p->heldSlot == 0xFF || p->heldSlot == p->curBox)) {
        (((BoxTask *)(p))->work->counter) = 0;
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
        return 0x40;
    }
    if (p->heldSlot == p->curBox || (((BoxTask *)(p))->work->cursorIndex) >= 0x1E)
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->cursorIndex), 1);
    BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->targetBox), 0);
    item = BOX2_MAIN_GetPartyValueAt((void ***)p, (((BoxTask *)(p))->work->targetBox), p->curBox, 6, 0);
    BOX2_MAIN_SetBoxValueAt((int)p, (((BoxTask *)(p))->work->targetBox), p->curBox, 6, (((BoxTask *)(p))->work->counter));
    if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, (((BoxTask *)(p))->work->targetBox))) == 1) {
        BOX2_MAIN_RecalcPartyParam((void **)p, (((BoxTask *)(p))->work->targetBox));
        BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, (((BoxTask *)(p))->work->targetBox), (((BoxTask *)(p))->work->cursorTable[(((BoxTask *)(p))->work->targetBox)]));
    }
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (((BoxTask *)(p))->work->targetBox));
    (((BoxTask *)(p))->work->counter) = item;
    BOX2_MAIN_SetBoxValueAt((int)p, (((BoxTask *)(p))->work->cursorIndex), p->heldSlot, 6, (((BoxTask *)(p))->work->counter));
    if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->heldSlot, (((BoxTask *)(p))->work->cursorIndex))) == 1) {
        BOX2_MAIN_RecalcPartyParam((void **)p, (((BoxTask *)(p))->work->cursorIndex));
        if (p->heldSlot == 0xFF || p->heldSlot == p->curBox)
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, (((BoxTask *)(p))->work->cursorIndex), (((BoxTask *)(p))->work->cursorTable[(((BoxTask *)(p))->work->cursorIndex)]));
    }
    if ((((BoxTask *)(p))->work->counter) == 0) {
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
        return 0x40;
    }
    BOX2_SEQ_CreateB((void *)p);
    (*(Entry **)(((char *)((BoxTask *)(p))->work) + 0x60))->idx = (((BoxTask *)(p))->work->targetBox);
    BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->counter));
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
    BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 1);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 1);
    BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(p))->work));
    GFL_USE_PlaySeDefaultVolume(0x666);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_Check122C, 0x43);
}











/*
 * Sibling of src/matched/ov170_func_021E5E68.c and ov170_func_021E376C.c.
 */
int BOX2_SEQ_StateCursorMoveB(BoxTask *p)
{
    unsigned r;
    if (KEY_GetTrg() & 4) {
        r = BOX2_SEQ_GotoBox2MainPlaySe((BoxTask *)p, 0x3F);
        if (p->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v < 6)
                p->cursorSlot = v + 0x1E;
            else
                p->cursorSlot = 0x1E;
        }
        return r;
    }
    r = BOX2_UI_GetHandSlotHit();
    if (r != -1) {
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x666);
            TOUCHPANEL_GetPointTrg((u32 *)((char *)p->work + 0xA180), (u32 *)((char *)p->work + 0xA184));
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, (int)r + 0x1E);
            return BOX2_SEQ_DeleteGridSlot((BoxTask *)p, r + 0x1E);
        }
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, (unsigned char)r, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r + 0x1E);
            return BOX2_SEQ_SetBox2UiF((BoxTask *)p);
        }
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), r);
        BOX2_UI_SetCursorPos((char **)p, r);
        return 0x46;
    }
    r = BOX2_UI_UpdateCursorInputF((BoxTask *)p);
    switch (r) {
    case 6:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 10, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1C));
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x556);
        p->params->swapMode = 1;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 7, 8, 0x10);
    case 8:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1C));
    case 9:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        p->listState = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x3F));
    case 10:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (*(unsigned short *)((char *)p->work + 0xA16C) == 0) {
            p->menuMode = 1;
            p->pickedSlot = 10;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
        }
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x50));
    case 11: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot - 0x1E;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x47);
    }
    case 12:
        r = BOX2_SEQ_GotoBox2MainNoSe((BoxTask *)p, 0x3F);
        if (p->listState == 1) {
            unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
            if (v < 6)
                p->cursorSlot = v + 0x1E;
            else
                p->cursorSlot = 0x1E;
        }
        return r;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 6)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v + 0x1E);
        else if (v == 6)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x46));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot - 0x1E;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x47);
        }
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x1C));
    case -1:
    case -5:
    case -6:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r + 0x1E, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return BOX2_SEQ_SetCursorMoveB((BoxTask *)p, r + 0x1E);
        }
        break;
    }
    return 0x46;
}

/*
 * Wrapper family member: BOX2_UI_ShowWindowB, state 0x46 and
 *   0x021E0E51 as the selector.
 */
int BOX2_SEQ_SetBox2UiF(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject((char *)(*(int *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowB((char *)(*(int *)&p->work));
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x21E0E51, BOX2_SEQ_SetState((BoxTask *)p, 0x46));
}

int BOX2_SEQ_StateMoveItemC(u8 *p)
{
    u16 *pair = *(u16 **)(((u8 *)((BoxTask *)(p))->work) + 96);
    u16 item = *(u16 *)(((u8 *)((BoxTask *)(p))->work) + 0xa16c);
    u16 second;
    if (item == 0) {
        BOX2_SEQ_DeleteB((BoxTask *)p);
        BOX2_SEQ_PrintPromptB((BoxTask *)p, 0, 24);
        CURSOR_MOVE_SetCurrent(*(void **)(((u8 *)((BoxTask *)(p))->work) + 112), 10);
        BOX2_UI_SetCursorPos((char **)p, 10);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        return 70;
    }
    if (pair[0] == p[22]) {
        second = pair[1];
        BOX2_SEQ_DeleteB((BoxTask *)p);
        CURSOR_MOVE_SetCurrent(*(void **)(((u8 *)((BoxTask *)(p))->work) + 112), 9);
        BOX2_UI_SetCursorPos((char **)p, 9);
        if (FILE_UTIL_Check136C(*(u16 *)(((u8 *)((BoxTask *)(p))->work) + 0xa16c)) == 1 && second != p[22]) {
            BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(p))->work), p[22], 0);
            BOX2_SEQ_PrintPromptB((BoxTask *)p, 7, 24);
            GFL_USE_PlaySeDefaultVolume(0x557);
            *(int *)(p + 40) = 14;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
        }
        BOX2_SEQ_PrintPromptB((BoxTask *)p, 1, 24);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        return 70;
    }
    if (FILE_UTIL_Check136C(item) == 1) {
        BOX2_SEQ_DeleteB((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(p))->work), p[22], 0);
        BOX2_SEQ_PrintPromptB((BoxTask *)p, 7, 24);
        GFL_USE_PlaySeDefaultVolume(0x557);
        CURSOR_MOVE_SetCurrent(*(void **)(((u8 *)((BoxTask *)(p))->work) + 112), 9);
        BOX2_UI_SetCursorPos((char **)p, 9);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        *(int *)(p + 40) = 14;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
    }
    BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(p))->work), pair[0], 0);
    BOX2_SEQ_SetSlotActorMode((char *)((u8 *)((BoxTask *)(p))->work), p[22], 1);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_SetActorAffineMode((char *)((u8 *)((BoxTask *)(p))->work), 1);
    BOX2_SEQ_SetActorAnimSeq((char *)((u8 *)((BoxTask *)(p))->work), 10, 2);
    return 73;
}









/*
 * Item swap on drop (template 021E6A60): moves the held item onto the
 * target slot, returns the target's old item to the source, and either
 * finishes or keeps the new item held.
 */
int BOX2_SEQ_StatePlaceItemB(BoxTask *p)
{
    Entry *o;
    unsigned short item;

    if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) == 1)
        return 0x49;
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 0);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 0);
    o = *(Entry **)(((char *)((BoxTask *)(p))->work) + 0x60);
    item = BOX2_MAIN_GetPartyValueAt((void ***)p, o->idx, p->curBox, 6, 0);
    BOX2_MAIN_SetBoxValueAt((int)p, o->idx, p->curBox, 6, (((BoxTask *)(p))->work->counter));
    if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, o->idx)) == 1) {
        BOX2_MAIN_RecalcPartyParam((void * *)p, o->idx);
        BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, o->idx, (((BoxTask *)(p))->work->cursorTable[o->idx]));
    }
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, o->idx);
    (((BoxTask *)(p))->work->counter) = item;
    BOX2_MAIN_SetBoxValueAt((int)p, p->cursorSlot, p->heldSlot, 6, (((BoxTask *)(p))->work->counter));
    if (p->heldSlot == 0xFF || p->heldSlot == p->curBox) {
        if (BOX2_MAIN_CanPlaceInBox((void **)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot)) == 1) {
            BOX2_MAIN_RecalcPartyParam((void * *)p, p->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, p->cursorSlot, (((BoxTask *)(p))->work->cursorTable[p->cursorSlot]));
        }
    }
    if ((((BoxTask *)(p))->work->counter) == 0) {
        p->cursorSlot = o->idx;
        BOX2_SEQ_DeleteB(p);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot - 0x1E);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 1);
        return 0x46;
    }
    GFL_USE_PlaySeDefaultVolume(0x666);
    BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->counter));
    BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
    BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 1);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 10, 1);
    BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(p))->work));
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_StateExitBox, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x4A));
}

int BOX2_SEQ_StateMoveItemD(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x667);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), **(unsigned short **)(((char *)((BoxTask *)(p))->work) + 0x60), 0);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 10, 2);
        CURSOR_MOVE_SetCurrent(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), p->cursorSlot - 0x1E);
        BOX2_SEQ_DeleteB(p);
        (((BoxTask *)(p))->work->seqStep)++;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive(((char *)((BoxTask *)(p))->work), 10) == 1)
            break;
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 1);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        return 0x46;
    }
    return 0x4A;
}


















int BOX2_SEQ_StateCursorMoveC(BoxTask *p)
{
    unsigned r = BOX2_UI_CursorInputPage((BoxTask *)p);
    switch (r) {
    case 0x1E:
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        break;
    case 0x1F:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x4B);
    case 0x20:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ClearCursorBox((unsigned char *)p);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x1E);
        BOX2_UI_SetCursorPos((char **)p, 0x1E);
        return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x4B);
    case 0x21:
        GFL_USE_PlaySeDefaultVolume(0x551);
        p->params->swapMode = 0;
        p->params->savedBox = 0xFF;
        p->params->savedSlot = 0xFF;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case 0x22:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x4D));
    case 0x23: {
        unsigned char k;
        GFL_USE_PlaySeDefaultVolume(0x551);
        k = p->cursorSlot;
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x4E);
    }
    case -6:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelA((BoxTask *)p, 0, 0x4B);
        }
        break;
    case -5:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 0x1E) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_ClearCursorBox((unsigned char *)p);
            return BOX2_SEQ_GotoRightPanelB((BoxTask *)p, 0, 0x4B);
        }
        break;
    case -4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    case -3: {
        unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
        if (v < 0x1E)
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
        else if (v != 0x22 && v != 0x23)
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x4B));
    }
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            unsigned char k = p->cursorSlot;
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, k, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), k);
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, 0x4E);
        }
        p->params->swapMode = 0;
        p->params->savedBox = 0xFF;
        p->params->savedSlot = 0xFF;
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, 0x68);
    case -1:
    case -7:
    case -8:
        break;
    default:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, r, p->curBox, 0xA9, 0)) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            p->cursorSlot = r;
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF8EC, 2);
            BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
            BOX2_SEQ_RefreshCursorSlot((BoxTask *)p);
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x22);
            if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1)
                return BOX2_SEQ_StatePushSlot((char *)p);
            BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 0x22, r);
            BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)p, 0x4C));
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, r);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x4B);
        }
        break;
    }
    return 0x4B;
}

/*
 * Push the 0x16 field through the 0x18 selector; return 75.
 */
int BOX2_SEQ_StatePushSlot(char *p)
{
    BOX2_SEQ_PrintPrompt((BoxTask *)p, (unsigned char)p[0x16], 1, 0x18);
    return 0x4b;
}

int BOX2_SEQ_StateSwapMenuC(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x4D);
    case 1:
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 0x4C, 0) != 0) {
            BOX2_SEQ_PrintMenuRow((char *)p, 4, 0x18);
            p->state = 0xE;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
        }
        if (BOX2_MAIN_GetBoxValue((char *)p, p->cursorSlot) == 0) {
            BOX2_SEQ_PrintMenuRow((char *)p, 6, 0x1B);
            p->state = 0xE;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
        }
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
        BOX2_SEQ_PrintBoxMonName((unsigned char *)p);
        (((BoxTask *)(p))->work->seqStep) = 0;
        return BOX2_SEQ_OpenYesNo((BoxTask *)p, 5);
    }
    return 0x4D;
}

void BOX2_SEQ_SetBox2MainD(BoxTask *p)
{
    BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)p, 0x4B));
}

int BOX2_SEQ_StateCloseItemC(unsigned char *p)
{
    return BOX2_SEQ_GotoBox2Ui((BoxTask *)p, 0);
}










/*
 * Item menu "give": checks the slot, then asks to swap or confirms.  A
 * four-step machine on the work word at 0xA194 (template 021E3C88).
 */
int BOX2_SEQ_StateSwapMenuD(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0: {
        unsigned item;
        if (*(int *)(((char *)((BoxTask *)(p))->params) + 0x24) == 4 && *(int *)(((char *)((BoxTask *)(p))->params) + 0x14) == 1) {
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            (((BoxTask *)(p))->work->seqStep) = 3;
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x50);
        }
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 0x4C, 0) == 0) {
            item = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
            if (item == 0)
                return BOX2_SEQ_GotoBox2Ui((BoxTask *)p, 1);
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 0);
            BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
            if (FILE_UTIL_Check136C(item) == 1) {
                BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
                (((BoxTask *)(p))->work->seqStep) = 1;
                return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x50);
            }
            if (p->cursorSlot < 0x1E)
                BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            else
                BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
            BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
            *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA170) = 1;
            BOX2_UI_ResetSlotFrames((((BoxTask *)(p))->work->winMgr));
            BOX2_SEQ_PrintWordset((BoxTask *)p, item, 0x18);
            if (*(int *)(((char *)((BoxTask *)(p))->params) + 0x24) == 3)
                return BOX2_SEQ_OpenYesNo((BoxTask *)p, 2);
            return BOX2_SEQ_OpenYesNo((BoxTask *)p, 0);
        }
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep) = 2;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x50);
    }
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintMessage((unsigned char *)p, 0x18);
        (((BoxTask *)(p))->state) = 0xE;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintPromptB((BoxTask *)p, 5, 0x18);
        (((BoxTask *)(p))->state) = 0xE;
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintYesNo((char *)p, 1);
        (((BoxTask *)(p))->state) = 0x2B;
        return 6;
    }
    return 0x50;
}

int BOX2_SEQ_SetBox2MainE(BoxTask *p)
{
    if (p->heldSlot != 0xFF)
        BOX2_MAIN_ChangeBoxForm((char *)p, p->heldSlot, p->cursorSlot);
    else
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
    BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
    if (((Flags_021E65E4 *)p)->lo == 0)
        BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
    else
        BOX2_SEQ_SetWindow9((BoxTask *)p, 0xD, 1);
    switch (((struct Obj23912 *)(*(char * *)&p->params))->f24) {
    case 0:
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenB((BoxTask *)p);
        break;
    case 1:
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpen((unsigned char *)p);
        break;
    case 2:
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenC((BoxTask *)p);
        break;
    case 4:
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenD((BoxTask *)p);
        break;
    case 3:
        break;
    }
    return BOX2_SEQ_StateWaitPrint((int)p);
}















int BOX2_SEQ_StateSwapFinishB(BoxTask *p)
{
    BOX2_MAIN_ResetBoxView(p);
    switch (((struct Obj23913 *)(*(char * *)&p->params))->f24) {
    case 1:
        BOX2_UI_MoveCursor((char **)p, 2, 0x1E);
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = 0x2C;
        break;
    case 2:
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        BOX2_UI_MoveCursor((char **)p, 3, 0x1E);
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = 0x11;
        break;
    case 3:
        BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        BOX2_UI_MoveCursor((char **)p, 7, 0x1E);
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = 0x39;
        break;
    case 4:
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        BOX2_UI_MoveCursor((char **)p, 0xD, 0x1E);
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = 0x1E;
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA198) = 0x23;
        break;
    case 0:
        break;
    }
    return BOX2_SEQ_StateWaitPrint((int)p);
}

int BOX2_SEQ_StateCloseItemD(u8 *p){switch(((struct Obj23914 *)(*(char * *)&((BoxTask *)p)->params))->f24){case 2:((struct Obj23915 *)(*(char * *)&((BoxTask *)p)->work))->fA198=BOX2_SEQ_StatePmVoiceMenuB((BoxTask *)p);break;case 3:((struct Obj23916 *)(*(char * *)&((BoxTask *)p)->work))->fA198=BOX2_SEQ_StatePmVoiceMenuC((BoxTask *)p);break;case 4:((struct Obj23917 *)(*(char * *)&((BoxTask *)p)->work))->fA198=BOX2_SEQ_StatePmVoiceMenuD((BoxTask *)p);break;}return BOX2_SEQ_StateWaitPrint((int)p);}

/*
 * candidate BOX2_SEQ_StateExitToField: state machine step
 */
void BOX2_SEQ_StateExitToField(BoxTask *p)
{
    int v;
    BOX2_SEQ_PrintWordsetBB64((BoxTask *)p, p->subResult, 0x18);
    v = *(int *)(*(int *)&p->params + 0x24);
    if (v == 3)
        p->state = 0x3c;
    else
        p->state = 0xe;
    BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
}

int BOX2_SEQ_StateSwapMenuE(BoxTask *p)
{
    switch (((struct Obj23918 *)(*(u8 * *)&p->work))->fA194) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&p->work, 4, 0);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 0);
        BOX2_SEQ_ShowWindowObject(*(char * *)&p->work, 24);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
        BOX2_UI_OpenListPack(*(struct WinMgr * *)&((struct Obj23919 *)(*(u8 * *)&p->work))->f74);
        (((struct Obj23920 *)(*(u8 * *)&p->work))->fA194)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 85);
    case 1:
        ((struct Obj23921 *)(*(u8 * *)&p->work))->fA174 = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 11, 0);
        BOX2_MAIN_SetHandSlots((char *)p, ((struct Obj23922 *)(*(u8 * *)&p->work))->fA174);
        BOX2_UI_PutTopBarThenClose(*(struct WinMgr * *)&((struct Obj23923 *)(*(u8 * *)&p->work))->f74);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((struct Obj23924 *)(*(u8 * *)&p->work))->fA194)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)((int (*)(u8 *))BOX2_MAIN_UpdateWindowMove), 85);
    case 2:
        BOX2_UI_MoveCursor((char **)p, 9, 0);
        BOX2_UI_ToggleSlotPair(*(char * *)&p->work, 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
        BOX2_SEQ_SetSlotActorMode(*(char * *)&p->work, p->cursorSlot, 0);
        BOX2_SEQ_PrintMessageE((char *)p, 24);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 86);
    }
    return 85;
}

int BOX2_SEQ_StateCloseMenu(BoxTask *p)
{
    u8 mask;
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(((struct Obj23925 *)(*(u8 * *)&p->work))->f70)) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 0);
        break;
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 1);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 2);
        break;
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 3);
        break;
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 4);
        break;
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        BOX2_SEQ_ToggleHandSlot((int)p, 5);
        break;
    case 6:
        mask = ((struct Obj23926 *)(*(u8 * *)&p->work))->fA174;
        BOX2_MAIN_SetBoxValueAt((int)p, p->cursorSlot, p->curBox, 11, mask);
        BOX2_MAIN_SetBodySlots((char *)p, (unsigned)mask);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GetBgFrameY((BoxTask *)p, 0, 87);
    case 7:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GetBgFrameY((BoxTask *)p, 1, 87);
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GetBgFrameY((BoxTask *)p, 1, 87);
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, 88);
    case (unsigned)-4:
        GFL_USE_PlaySeDefaultVolume(0x548);
        break;
    }
    return 86;
}

int BOX2_SEQ_StateSummaryE(BoxTask *p)
{
    switch (((struct Obj23927 *)(*(char * *)&p->params))->f24) {
    case 0:
        BOX2_UI_MoveCursor((char **)p, 0, 10);
        break;
    case 1:
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_UI_MoveCursor((char **)p, 2, 0x25);
        break;
    case 2:
    default:
        if (p->cursorSlot < 0x1E) {
            BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
            BOX2_UI_MoveCursor((char **)p, 3, 0x27);
        } else {
            BOX2_UI_MoveCursor((char **)p, 5, 0xC);
        }
        break;
    }
    BOX2_SEQ_SetCursorDraw((char **)p, 0);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    if (p->cursorSlot < 0x1E)
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
    BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
    BOX2_UI_RepenTopBar(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
    GFL_USE_PlaySeDefaultVolume(0x669);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)((int (*)(unsigned char *))BOX2_MAIN_UpdateWindowMove), BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0xE));
}

/*
 * Forward and then return a status constant.
 */
int BOX2_SEQ_StateDeleteHandle(BoxTask *p)
{
    func_020307B0(((struct Obj18467 *)(*(char * *)&p->work))->f60);
    return 0x56;
}

int BOX2_SEQ_StateMoveItemE(BoxTask *p)
{
    unsigned slot;
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 0);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x59);
    case 1:
        if (p->cursorSlot >= 30) {
            BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
            BOX2_SEQ_SetSlotActorMode((char *)((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
            slot = p->cursorSlot - 30;
            if (BOX2_MAIN_HasOtherTradable((void ***)p, slot) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                BOX2_SEQ_PrintMonName((BoxTask *)p, 6, 24);
                *(u8 *)(((char *)((BoxTask *)(p))->work) + 0xA170) = 1;
                p->state = 14;
                return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
            }
            if (FILE_UTIL_Check136C(func_02017E1C(POKEPARTY_GetMember(((struct Obj23928 *)(*(char * *)&p->params))->f8, slot), 6, 0)) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x557);
                BOX2_SEQ_PrintPrompt((BoxTask *)p, 0, 5, 24);
                *(u8 *)(((char *)((BoxTask *)(p))->work) + 0xA170) = 1;
                p->state = 14;
                return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
            }
        } else {
            BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
            BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
            BOX2_SEQ_SetSlotActorMode((char *)((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
        }
        if (func_02017E88((void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot), 0x4c, 0) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            BOX2_SEQ_PrintMonName((BoxTask *)p, 3, 24);
            *(u8 *)(((char *)((BoxTask *)(p))->work) + 0xA170) = 1;
            p->state = 14;
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
        }
        BOX2_SEQ_PrintMonName((BoxTask *)p, 0, 24);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, BOX2_SEQ_OpenYesNo((BoxTask *)p, 1));
    }
    return 0x59;
}

int BOX2_SEQ_StateCloseZoom(unsigned char *p)
{
    BOX2_MAIN_StepScroll((BoxTask *)p);
    if (BOX2_SEQ_ShrinkActor((((BoxTask *)(p))->work->scroll)) == 0) {
        if (((unsigned char *)(((BoxTask *)(p))->work->scroll))[6] != 0)
            return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5C);
        BOX2_SEQ_HideActor((int *)(((BoxTask *)(p))->work->scroll));
        BOX2_MAIN_DeleteScroll((BoxTask *)p);
        return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5B);
    }
    return 0x5A;
}

/*
 * Four-step machine on the work word at 0xA194 for releasing a Pokemon:
 * two confirmation messages, then the release itself (box slot in place,
 * party slot with a fade), then the view is restored.
 */
int BOX2_SEQ_StateMoveItemF(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_PrintMonName((BoxTask *)p, 1, 0x18);
        (((BoxTask *)(p))->state) = 0x5B;
        (((BoxTask *)(p))->work->seqStep)++;
        return 6;
    case 1:
        BOX2_SEQ_PrintMonName((BoxTask *)p, 2, 0x18);
        (((BoxTask *)(p))->state) = 0x5B;
        (((BoxTask *)(p))->work->seqStep)++;
        return 6;
    case 2:
        BOX2_MAIN_ClearSlot((char **)p, p->curBox, p->cursorSlot);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_MAIN_ResetBoxView(p);
        if (p->cursorSlot < 0x1E) {
            BOX2_UI_DrawSlot((BoxTask *)p, p->curBox);
            BOX2_UI_DrawSlotByName((char *)p, p->curBox);
            if ((((BoxTask *)(p))->params->mode) == 1) {
                (((BoxTask *)(p))->state) = 0x2C;
            } else {
                (((BoxTask *)(p))->state) = 0x11;
                BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
            }
            CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot);
            BOX2_UI_SetCursorPos((char **)p, p->cursorSlot);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
            BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
            p->cursorSlot = 0xFF;
            (((BoxTask *)(p))->work->seqStep) = 0;
            return (((BoxTask *)(p))->state);
        }
        BOX2_SEQ_Create((void *)p);
        p->phase = 1;
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineOpen, 0x5B);
    case 3:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_SEQ_Delete(p);
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot - 0x1E);
        BOX2_UI_SetCursorPos((char **)p, p->cursorSlot - 0x1E);
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        p->cursorSlot = 0xFF;
        if ((((BoxTask *)(p))->params->mode) == 0)
            return 0x31;
        BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        return 0x1B;
    }
    return 0x5B;
}







int BOX2_SEQ_StateOpenZoom(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        if (BOX2_SEQ_GrowActor((((BoxTask *)(p))->work->scroll)) != 0)
            break;
        BOX2_SEQ_ResetActorTransform((int *)(((BoxTask *)(p))->work->scroll));
        BOX2_MAIN_DeleteScroll(p);
        BOX2_SEQ_RefreshCursorSlot(p);
        BOX2_SEQ_PrintMonName((BoxTask *)p, 4, 0x18);
        p->state = 0x5C;
        (((BoxTask *)(p))->work->seqStep)++;
        return 6;
    case 1:
        BOX2_SEQ_PrintMonName((BoxTask *)p, 5, 0x18);
        p->state = 0x5C;
        (((BoxTask *)(p))->work->seqStep)++;
        return 6;
    case 2:
        (((BoxTask *)(p))->work->seqStep) = 0;
        return BOX2_SEQ_StateUseItemDone((BoxTask *)p);
    }
    return 0x5C;
}

/*
 * Return r0 from BOX2_SEQ_GetActorDrawEnable and BOX2_SEQ_ResetEntryB is read by this caller.
 * Lever: low-nibble bitfield assignment emits bics #15; a byte mask
 * emits ands #240 and changes four concrete bytes at +0x120..+0x124.
 */
int BOX2_SEQ_StateZoomMenu(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        (((BoxTask *)(p))->work->seqStep)++;
        BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(p))->work), 4, 0);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 0);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
        if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            if (BOX2_SEQ_GetActorDrawEnable((char *)((char *)((BoxTask *)(p))->work), 10) == 1)
                BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(p))->work), 10, 0);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(p))->work), 24);
            BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
            BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x5d);
        } else if (BOX2_UI_IsInfoBarOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
            BOX2_UI_HideWindowA(((char *)((BoxTask *)(p))->work));
            return BOX2_SEQ_ResetEntryB((BoxTask *)p, 0x5d);
        } else if (BOX2_UI_IsTopBarOpen((((BoxTask *)(p))->work->winMgr)) == 1) {
            BOX2_UI_HideWindowB(((char *)((BoxTask *)(p))->work));
            BOX2_UI_OpenBar((((BoxTask *)(p))->work->winMgr));
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowBusy, 0x5d);
        } else {
            BOX2_UI_HideWindowA(((char *)((BoxTask *)(p))->work));
        }
    case 1:
        BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF908, 4);
        BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x5d);
    case 2:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_PrintIndexedMessage((unsigned char *)p, 0, 24);
        BOX2_UI_MoveCursor((char **)p, 10, 0);
        ((Flags_021E8340 *)p)->lo = 0;
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
        return 0x5e;
    }
    return 0x5d;
}

int BOX2_SEQ_StateClosePmVoice(BoxTask *p)
{
    unsigned v = CURSOR_MOVE_PollRepeatInput(((struct Obj23929 *)(*(u8 * *)&p->work))->f70);
    switch (v) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x60));
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ((struct Obj23930 *)(*(u8 * *)&p->work))->fA17C = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, 0x67);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5f));
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5f));
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x5e));
    }
    return 0x5e;
}

int BOX2_SEQ_StateMoveMenu(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(p))->work), 24);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x5f);
    case 1:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 1);
        if (((struct Obj23931 *)(*(char * *)&p->params))->f24 == 2) {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work));
            BOX2_UI_MoveCursor((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23932 *)(*(char * *)&p->params))->f24 == 1) {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_MoveCursor((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23933 *)(*(char * *)&p->params))->f24 == 3) {
            BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
            BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work));
            BOX2_UI_MoveCursor((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23934 *)(*(char * *)&p->params))->f24 == 4) {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work));
            BOX2_UI_MoveCursor((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x5f;
}

int BOX2_SEQ_StateMoveMenuB(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA17A) = 1;
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x60);
    case 1:
        p->prevBox = p->curBox;
        (((BoxTask *)(p))->work->seqStep)++;
        GFL_USE_PlaySeDefaultVolume(0x669);
        return BOX2_SEQ_ResetEntry((char *)p, 0x60);
    case 2:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 1);
        BOX2_UI_MoveCursor((char **)p, 0xC, 1);
        *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = 1;
        BOX2_SEQ_PrintIndexedMessage((unsigned char *)p, 1, 0x19);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 1, 1);
        return 0x61;
    }
    return 0x60;
}
















/*
 * List input for the box menu: a touch pick stores the slot and leaves,
 * otherwise the list result selects a page, a jump, or a cancel.
 */
int BOX2_SEQ_StatePmVoiceMenu(BoxTask *p)
{
    unsigned x, y;
    unsigned r;

    if (BOX2_UI_GetExitButtonPoint(&x, &y) == 1) {
        *(unsigned *)(((char *)((BoxTask *)(p))->work) + 0xA184) = y;
        (((BoxTask *)(p))->state) = 0x61;
        BOX2_SEQ_CreateC(p);
        CURSOR_MOVE_SetState((((BoxTask *)(p))->work->sound), 0);
        return 0xF;
    }
    r = CURSOR_MOVE_PollRepeatInput((((BoxTask *)(p))->work->sound));
    switch (r) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)p, -1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxRight, 0x61);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_MAIN_SelectBox((BoxTask *)p, 1);
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxLeft, 0x61);
    case 1:
    case 2:
    case 3:
    case 4:
        (((BoxTask *)(p))->work->currentBox) = p->prevBox + r - 1;
        if ((((BoxTask *)(p))->work->currentBox) >= p->boxLimit)
            (((BoxTask *)(p))->work->currentBox) -= p->boxLimit;
        if ((((BoxTask *)(p))->work->currentBox) != p->curBox) {
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
            return BOX2_SEQ_DrawListSlot((BoxTask *)p, 1);
        }
        GFL_USE_PlaySeDefaultVolume(0x548);
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, r - 1, 1);
        break;
    case 6:
    case (unsigned)-2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2MainWithSlot((BoxTask *)p, 6, 9, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x62));
    case (unsigned)-3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x61));
    case (unsigned)-8:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 1) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_SelectBox((BoxTask *)p, -1);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxRight, 0x61);
        }
        break;
    case (unsigned)-7:
        if (CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)) == 4) {
            GFL_USE_PlaySeDefaultVolume(0x548);
            BOX2_MAIN_SelectBox((BoxTask *)p, 1);
            return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_OpenBoxLeft, 0x61);
        }
        break;
    }
    return 0x61;
}

/*
 * Return from BOX2_SEQ_ResetEntryB is used despite its legacy void declaration.
 */
int BOX2_SEQ_StatePmVoiceConfirm(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        *(u8 *)(((char *)((BoxTask *)(p))->work) + 0xA17A) = 0;
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(p))->work), 25);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
        BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
        GFL_USE_PlaySeDefaultVolume(0x669);
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_ResetEntryB((BoxTask *)p, 0x62);
    case 1:
        (((BoxTask *)(p))->work->seqStep) = 0;
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 1);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
        BOX2_SEQ_SetWindow9((BoxTask *)p, 14, 1);
        if (((struct Obj23935 *)(*(char * *)&p->params))->f24 == 2) {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work));
            BOX2_UI_MoveCursor((char **)p, 3, 30);
            return 17;
        } else if (((struct Obj23936 *)(*(char * *)&p->params))->f24 == 1) {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_MoveCursor((char **)p, 2, 30);
            return 44;
        } else if (((struct Obj23937 *)(*(char * *)&p->params))->f24 == 3) {
            BOX2_SEQ_SetSlotActors((char *)p, 0x81, 1);
            BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work));
            BOX2_UI_MoveCursor((char **)p, 7, 30);
            return 57;
        } else if (((struct Obj23938 *)(*(char * *)&p->params))->f24 == 4) {
            BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
            BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work));
            BOX2_UI_MoveCursor((char **)p, 13, 30);
            return 35;
        }
    }
    return 0x62;
}

int BOX2_SEQ_StateSetMiniIcon(BoxTask *p)
{
    BOX2_UI_SetMiniIconVisible((BoxTask *)p, CURSOR_MOVE_GetCurrent((struct Sound *)(*(int *)(*(int *)&p->work + 0x70))) - 1, 1);
    return 0x61;
}

/*
 * Three-step machine on the work word at 0xA194 for the box-list menu:
 * fade out, open the menu for list kind 0xA17C (two kinds pick the long
 * menu when a save flag is set), then print the prompt and lock the list.
 */
int BOX2_SEQ_StateMoveMenuC(BoxTask *p)
{
    int flag;

    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox(p);
        BOX2_UI_OpenListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x64);
    case 1:
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            if (func_02007A80((((BoxTask *)(p))->params->boxSave), 1) == 1)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9C8, 6);
            else
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF93C, 5);
        } else if ((((BoxTask *)(p))->work->selectKind) == 1) {
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF964, 5);
        } else if ((((BoxTask *)(p))->work->selectKind) == 2) {
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF978, 5);
        } else if ((((BoxTask *)(p))->work->selectKind) == 3) {
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF98C, 5);
        } else if ((((BoxTask *)(p))->work->selectKind) == 4) {
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9A0, 5);
        } else if ((((BoxTask *)(p))->work->selectKind) == 5) {
            if (func_02007A80((((BoxTask *)(p))->params->boxSave), 2) == 1)
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9E0, 6);
            else
                BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF928, 5);
        } else if ((((BoxTask *)(p))->work->selectKind) == 6) {
            BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9F8, 6);
        }
        BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
        (((BoxTask *)(p))->work->seqStep)++;
        return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsWindowMoving, 0x64);
    case 2:
        (((BoxTask *)(p))->work->seqStep) = 0;
        if ((((BoxTask *)(p))->work->selectKind) == 0)
            BOX2_SEQ_PrintIndexedMessage((unsigned char *)p, 2, 0x18);
        else
            BOX2_SEQ_PrintIndexedMessage((unsigned char *)p, 3, 0x18);
        flag = 0;
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            if (func_02007A80((((BoxTask *)(p))->params->boxSave), 1) == 0)
                flag = 1;
        } else if ((((BoxTask *)(p))->work->selectKind) == 5) {
            if (func_02007A80((((BoxTask *)(p))->params->boxSave), 2) == 0)
                flag = 1;
        } else if ((((BoxTask *)(p))->work->selectKind) != 6) {
            flag = 1;
        }
        if (flag == 1) {
            BOX2_UI_MoveCursor((char **)p, 0xB, 1);
            CURSOR_MOVE_ClearSkipBit((((BoxTask *)(p))->work->sound), 0);
        } else {
            BOX2_UI_MoveCursor((char **)p, 0xB, 0);
        }
        return 0x65;
    }
    return 0x64;
}

int BOX2_SEQ_StateClosePmVoiceB(BoxTask *p)
{
    switch ((unsigned)CURSOR_MOVE_PollRepeatInput(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70))) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            (((BoxTask *)(p))->work->selectKind) = 5;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 0, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)p, 0);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            (((BoxTask *)(p))->work->selectKind) = 1;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 1, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)p, 1);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            (((BoxTask *)(p))->work->selectKind) = 2;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 2, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)p, 2);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            (((BoxTask *)(p))->work->selectKind) = 3;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 3, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)p, 3);
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if ((((BoxTask *)(p))->work->selectKind) == 0) {
            (((BoxTask *)(p))->work->selectKind) = 4;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        if ((((BoxTask *)(p))->work->selectKind) == 5 && func_02007A80(((void **)p->params)[1], 2) == 1) {
            (((BoxTask *)(p))->work->selectKind) = 6;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        if ((((BoxTask *)(p))->work->selectKind) == 6) {
            (((BoxTask *)(p))->work->selectKind) = 5;
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 4, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
        }
        return BOX2_SEQ_GotoSceneA((BoxTask *)p, 4);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if ((((BoxTask *)(p))->work->selectKind) == 0)
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5F));
        (((BoxTask *)(p))->work->selectKind) = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
    case 0xFFFFFFFE:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if ((((BoxTask *)(p))->work->selectKind) == 0)
            return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x5F));
        (((BoxTask *)(p))->work->selectKind) = 0;
        return BOX2_SEQ_GotoBox2Main((BoxTask *)p, 5, BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 0x64));
    case 0xFFFFFFFD:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((BoxTask *)p, BOX2_SEQ_SetState((BoxTask *)p, 0x65));
    }
    return 0x65;
}

















int BOX2_SEQ_StateFadeBox(BoxTask *p)
{
    switch ((((BoxTask *)(p))->work->seqStep)) {
    case 0:
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
        PALANM_CopyHwPaletteToSlot(*(void **)(((char *)((BoxTask *)(p))->work) + 0x6c), 0, 0, 0x200);
        PALANM_RequestFade(*(void **)(((char *)((BoxTask *)(p))->work) + 0x6c), 1, 0xc000, 0, 0, 16, 0x7fff, (void *)func_020056BC());
        p->state = 0x66;
        (((BoxTask *)(p))->work->seqStep)++;
        return 3;
    case 1:
        BOX2_MAIN_LoadBoxPalette((char *)p, *(u8 *)(((char *)((BoxTask *)(p))->work) + 0xA17B));
        func_02007838(((struct Obj23940 *)(*(char * *)&p->params))->f4, p->curBox, *(u8 *)(((char *)((BoxTask *)(p))->work) + 0xA17B));
        BOX2_UI_DrawSlot((BoxTask *)p, p->curBox);
        (((BoxTask *)(p))->work->seqStep)++;
        break;
    case 2:
        PALANM_RequestFade(*(void **)(((char *)((BoxTask *)(p))->work) + 0x6c), 1, 0xc000, 0, 16, 0, 0x7fff, (void *)func_020056BC());
        p->state = 0x66;
        (((BoxTask *)(p))->work->seqStep)++;
        return 3;
    case 3:
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        (((BoxTask *)(p))->work->seqStep) = 0;
        return 0x65;
    }
    return 0x66;
}

int BOX2_SEQ_StateCloseItemE(unsigned char *p)
{
    return BOX2_SEQ_GotoBox2Ui((BoxTask *)p, 2);
}

void BOX2_SEQ_HideCursorSlot(u8 *p){BOX2_SEQ_SetActorDrawEnable(*(char * *)&((BoxTask *)p)->work,4,0);BOX2_SEQ_SetWindow9((BoxTask *)p,14,0);BOX2_SEQ_PrintMessageB((char *)p,24);BOX2_SEQ_DeleteSlotWindows((BoxTask *)p);BOX2_SEQ_OpenYesNo((BoxTask *)p,4);}

/*
 * Clear the pooled-offset word and return the argument.
 */
int BOX2_SEQ_ReturnAfterClear(BoxTask *p, int v)
{
    ((struct Obj18468 *)(*(char * *)&p->work))->fA194 = 0;
    return v;
}

/*
 * Sibling of BOX2_SEQ_StartWipeBlack: the seven-argument setup call then
 * the state word at +0xA188 of the sub-object, return 2.
 */
int BOX2_SEQ_StartWipeWhite(void *p, int a)
{
    WIPE_SYS_Start(0, 1, 1, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18469 *)p)->f2C + 0xA188) = a;
    return 2;
}

/*
 * Same body as BOX2_SEQ_StartWipeWhite with the first four arguments zero;
 * the state word goes to +0xA188, return 2.
 */
int BOX2_SEQ_StartWipeBlack(void *p, int a)
{
    WIPE_SYS_Start(0, 0, 0, 0, 6, 1, 0x4c);
    *(int *)(((struct Obj18470 *)p)->f2C + 0xA188) = a;
    return 2;
}

/*
 * Store the third argument, then reset the sub-object.
 */
int BOX2_SEQ_SetSeqThird(BoxTask *p, int a, int b)
{
    *(int *)(*(int *)&p->work + 0x68) = b;
    BOX2_MAIN_InitSeq(*(char * *)&p->work, a);
    return 5;
}

/*
 * Store the second argument, then re-seat the sub-object.
 */
int BOX2_SEQ_SetSeqSecond(BoxTask *p, int a)
{
    *(int *)(*(int *)&p->work + 0x68) = a;
    BOX2_MAIN_RestartSeq(*(char * *)&p->work);
    return 5;
}

/*
 * Store v at +0x28, return 13.
 */
int BOX2_SEQ_SetState(BoxTask *p, int v)
{
    p->state = v;
    return 0xd;
}





/*
 * Opens the yes/no menu with the cursor on sel and enters state 7.
 */
int BOX2_SEQ_OpenYesNo(BoxTask *p, int sel)
{
    *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0x1A4) = sel;
    if (sel == 1)
        BOX2_MAIN_OpenTaskMenu((BoxTask *)p, 1);
    else
        BOX2_MAIN_OpenTaskMenu((BoxTask *)p, 0);
    KEY_SetRepeatSpeed(*(unsigned *)(((char *)((BoxTask *)(p))->work) + 0x4C), *(unsigned *)(((char *)((BoxTask *)(p))->work) + 0x50));
    return 7;
}











int BOX2_SEQ_StateUseItem(BoxTask *p)
{
    unsigned item;
    void *mon;
    item = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    if (func_02007E50(((struct Obj23942 *)(*(char * *)&p->params))->fC, item, 1, 0x4C) == 1) {
        mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot);
        BOX2_SEQ_PrintWordsetB((char *)p, item, 0x18);
        BOX2_MAIN_SetBoxValueAt((int)p, p->cursorSlot, p->curBox, 6, 0);
        if (BOX2_MAIN_CanPlaceInBox((void **)p, mon) == 1) {
            BOX2_MAIN_RecalcPartyParam((void **)p, p->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, p->cursorSlot, *(unsigned char *)(((char *)((BoxTask *)(p))->work) + p->cursorSlot + 0x3DD2));
        }
        BOX2_MAIN_SetBoxForm((BoxTask *)p, p->cursorSlot);
    } else {
        GFL_USE_PlaySeDefaultVolume(0x557);
        BOX2_SEQ_PrintMessageD((char *)p, 0x18);
    }
    if (func_020355C4() == 1) {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 0);
    } else {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
    }
    p->state = 0xE;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, 6);
}











int BOX2_SEQ_StateUseItemWait(BoxTask *p)
{
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    BOX2_MAIN_ResetMovers((BoxTask *)p);
    BOX2_SEQ_ResetActorAffine(*(char **)(((char *)((BoxTask *)(p))->work) + 0xA190));
    if (func_020355C4() == 1) {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 0);
    } else {
        CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 1);
        BOX2_SEQ_SetCursorDraw((char **)p, 0);
    }
    return 0x5A;
}











int BOX2_SEQ_StateUseItemDone(BoxTask *p) {
 BOX2_SEQ_SetSlotDim((char **)p,1); BOX2_SEQ_HideWindowObject(((char *)((BoxTask *)(p))->work),0x18); BOX2_MAIN_RefreshCursorBox(p);
 if(p->cursorSlot<0x1E) { BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetSlotActors((char *)p,1,0); }
 else BOX2_SEQ_SetSlotActors((char *)p,2,0);
 if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),0);
 else { CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),1); BOX2_SEQ_SetCursorDraw((char **)p,0); }
 return BOX2_SEQ_SetSeqThird((BoxTask *)p,(int)BOX2_MAIN_IsWindowMoving,BOX2_SEQ_ReturnAfterClear((BoxTask *)p,0xE));
}











int BOX2_SEQ_StateUseItemMenu(BoxTask *p)
{
    void *mon;
    if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),0);
    else { CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),1); BOX2_SEQ_SetCursorDraw((char **)p,0); }
    if(func_02007E50(((struct Obj23943 *)(*(char * *)&p->params))->fC,*(unsigned short *)(((char *)((BoxTask *)(p))->work)+0xa16c),1,0x4c)==1) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)p,p->curBox,p->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((int)p,p->cursorSlot,p->curBox,6,0);
        if(BOX2_MAIN_CanPlaceInBox((void **)p,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void **)p,p->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p,p->curBox,p->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(p))->work)+p->cursorSlot+0x3dd2));
        }
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_SEQ_SetSlotDim((char **)p,0);
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work),0x18); BOX2_MAIN_RefreshCursorBox(p); BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        BOX2_SEQ_SetActorAffineMode(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work),0xa,2);
        return 0x3b;
    }
    GFL_USE_PlaySeDefaultVolume(0x557); BOX2_SEQ_PrintPromptB((BoxTask *)p,6,0x18);
    p->state=0xe;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)p,6);
}

/*
 * Set the id, re-key the queue, store 0x69 as the frame, then
 *   arm the flag.
 */
int BOX2_SEQ_StatePlayCry(BoxTask *p)
{
    GFL_USE_PlaySeDefaultVolume(0x55D);
    BOX2_MAIN_PlayMonCry((int *)p);
    p->state = 0x69;
    return BOX2_SEQ_StartWipeBlack((void *)p, 1);
}











/*
 * trailing extent: two-byte zero alignment at 021E93F2.
 */
int BOX2_SEQ_StateCloseItemMenu(BoxTask *p)
{
    BOX2_SEQ_ShowWindowObject((char *)((char *)((BoxTask *)(p))->work),0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),0);
    else CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),1);
    BOX2_SEQ_SetWindow9((BoxTask *)p,0xe,1);
    switch(((struct Obj23944 *)(*(char * *)&p->params))->f24) {
    case 0: BOX2_SEQ_SetSlotActors((char *)p,2,0); return 0x31;
    case 1: BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetSlotActors((char *)p,1,0); return 0x2c;
    case 2:
        if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)p,2,0); BOX2_UI_ShowWindowB((char *)((char *)((BoxTask *)(p))->work)); return 0x1b;
        }
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetSlotActors((char *)p,1,0); BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work)); return 0x11;
    case 3:
        if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)p,0x82,0); BOX2_UI_ShowWindowB((char *)((char *)((BoxTask *)(p))->work)); return 0x46;
        }
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetSlotActors((char *)p,0x81,0); BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work)); return 0x39;
    case 4:
        if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74))==1) {
            BOX2_SEQ_SetSlotActors((char *)p,2,0); BOX2_UI_ShowWindowB((char *)((char *)((BoxTask *)(p))->work)); return 0x27;
        }
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetSlotActors((char *)p,1,0); BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work)); return 0x23;
    case 5: BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),1); BOX2_SEQ_SetSlotActors((char *)p,0x81,1); return 0x4b;
    }
    return 0x11;
}

/*
 * candidate BOX2_SEQ_SaveMenuPosAndExit: copy two bytes into a sub object
 */
void BOX2_SEQ_SaveMenuPosAndExit(BoxTask *p)
{
    BOX2_MAIN_PlayMonCry((int *)((int)p));
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2a) = p->curBox;
    *(unsigned char *)(((struct Obj05869 *)p)->f0 + 0x2b) = p->cursorSlot;
    p->state = 0x69;
    BOX2_SEQ_StartWipeBlack((void *)((int)p), 1);
}











int BOX2_SEQ_StatePmVoiceClose(BoxTask *p) {
 BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work),0x1B); BOX2_MAIN_RefreshCursorBox(p);
 CURSOR_MOVE_SetCurrent(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),p->cursorSlot);
 BOX2_SEQ_SetSlotActors((char *)p,0x81,1); BOX2_SEQ_SetSlotDim((char **)p,0);
 if(func_020355C4()==1) CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),0);
 else CURSOR_MOVE_SetState(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),1);
 return 0x4B;
}

void BOX2_SEQ_StateEnterItemMenu(unsigned char *p){if(func_020355C4()==1)CURSOR_MOVE_SetState(((struct Obj23945 *)(*(unsigned char * *)&((BoxTask *)p)->work))->f70,0);else {CURSOR_MOVE_SetState(((struct Obj23946 *)(*(unsigned char * *)&((BoxTask *)p)->work))->f70,1);BOX2_SEQ_SetCursorDraw((char **)p,0);}BOX2_SEQ_StateItemMenu((BoxTask *)p);}

/*
 * Forward, then store the third argument at 0x28.
 */
int BOX2_SEQ_GotoBox2Main(BoxTask *p, int a, int b)
{
    BOX2_MAIN_UpdateWindowFrame((char *)p, a);
    p->state = b;
    return 8;
}

int BOX2_SEQ_GetBgFrameY(BoxTask *p,int a,int b) {
 ((BoxWorkView *)(char *)p->work)->flag=1;
 ((BoxWorkView *)(char *)p->work)->id=BGWINFRM_GetBgFrame(*(struct WinMgr * *)&((struct Obj23947 *)((char *)(char *)p->work))->f74,7);
 ((BoxWorkView *)(char *)p->work)->lo=13;
 ((BoxWorkView *)(char *)p->work)->hi=12;
 ((BoxWorkView *)(char *)p->work)->state=0;
 ((BoxWorkView *)(char *)p->work)->count=0;
 if(a==0) ((BoxWorkView *)(char *)p->work)->y=14;
 else ((BoxWorkView *)(char *)p->work)->y=17;
 ((BoxWorkView *)(char *)p->work)->x=21;
 ((BoxWorkView *)(char *)p->work)->w=11;
 ((BoxWorkView *)(char *)p->work)->h=3;
 p->state=b;
 return 8;
}










int BOX2_SEQ_GotoBox2MainWithSlot(BoxTask *p, int id, int lo, int arg)
{
    ((BoxWorkView *)(char *)p->work)->flag = 0;
    ((BoxWorkView *)(char *)p->work)->id = (unsigned char)id;
    ((BoxWorkView *)(char *)p->work)->lo = (unsigned char)lo;
    ((BoxWorkView *)(char *)p->work)->hi = 0;
    ((BoxWorkView *)(char *)p->work)->state = 0;
    ((BoxWorkView *)(char *)p->work)->count = 0;
    ((BoxWorkView *)(char *)p->work)->x = 0;
    ((BoxWorkView *)(char *)p->work)->y = 0;
    ((BoxWorkView *)(char *)p->work)->w = 0;
    ((BoxWorkView *)(char *)p->work)->h = 0;
    p->state = arg;
    return 8;
}

/*
 * Enters state 9 with reason v.
 */
int BOX2_SEQ_GotoBox2Ui(BoxTask *p, unsigned char v)
{
    if (CURSOR_MOVE_GetState(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70)) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    p->state = 9;
    p->pad_12 = v;
    return BOX2_SEQ_StartWipeBlack((void *)p, 1);
}









int BOX2_SEQ_StatePmVoiceMenuB(BoxTask *p)
{
    int next;
    void *mon;
    switch(p->menuMode) {
    case 0: BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work)); next=0x11; break;
    case 1:
        BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
        BOX2_UI_MoveCursor((char **)p,5,0xb); BOX2_UI_ShowWindowB((char *)((char *)((BoxTask *)(p))->work)); next=0x1b; break;
    }
    BOX2_SEQ_RefreshCursorSlot(p);
    if((((BoxTask *)(p))->subResult)==0) {
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_SEQ_DrawFrameList((BoxTask *)p, data_021EFA10, 6);
        BOX2_UI_PutListFrames(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74)); BOX2_SEQ_PrintPrompt((BoxTask *)p,p->cursorSlot,1,0x18);
        return next;
    }
    if(FILE_UTIL_Check136C((((BoxTask *)(p))->subResult))==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)p,p->curBox,p->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((int)p,p->cursorSlot,p->curBox,6,(((BoxTask *)(p))->subResult));
        if(BOX2_MAIN_CanPlaceInBox((void **)p,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void * *)p, p->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p,p->curBox,p->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(p))->work)+p->cursorSlot+0x3dd2));
        }
        func_02007F1C(((struct Obj23948 *)(*(char * *)&p->params))->fC,(((BoxTask *)(p))->subResult),1,0x804c);
    }
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_SEQ_SetCursorDraw((char **)p,0);
    return 0x54;
}








int BOX2_SEQ_StatePmVoiceMenuC(BoxTask *p)
{
    int next;
    void *mon;
    switch(p->menuMode) {
    case 0: BOX2_SEQ_MoveActorToSlot((char *)((char *)((BoxTask *)(p))->work),p->cursorSlot,0); next=0x39; break;
    case 1:
        BOX2_SEQ_StopLeftBar((int)p); BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
        BOX2_SEQ_MoveActorToSlot((char *)((char *)((BoxTask *)(p))->work),p->cursorSlot,1); BOX2_UI_MoveCursor((char **)p,8,0xa); next=0x46; break;
    }
    BOX2_SEQ_SetActorAnim((BoxTask *)p,*(short *)&p->subResult);
    if((((BoxTask *)(p))->subResult)==0) {
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_UI_PutListFrames(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74));
        BOX2_SEQ_PrintPromptB((BoxTask *)p,0,0x18);
        if(p->menuMode==0) BOX2_SEQ_SetSlotActors((char *)p,0x81,1);
        else { BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_SEQ_SetSlotActors((char *)p,0x82,1); }
        return next;
    }
    if(FILE_UTIL_Check136C((((BoxTask *)(p))->subResult))==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)p,p->curBox,p->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((int)p,p->cursorSlot,p->curBox,6,(((BoxTask *)(p))->subResult));
        if(BOX2_MAIN_CanPlaceInBox((void **)p,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void **)p,p->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p,p->curBox,p->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(p))->work)+p->cursorSlot+0x3dd2));
        }
        func_02007F1C(((struct Obj23949 *)(*(char * *)&p->params))->fC,(((BoxTask *)(p))->subResult),1,0x804c);
        *(unsigned short *)(((char *)((BoxTask *)(p))->work)+0xa16c)=(((BoxTask *)(p))->subResult);
        BOX2_SEQ_SetSlotCharacter(((char *)((BoxTask *)(p))->work),*(unsigned short *)(((char *)((BoxTask *)(p))->work)+0xa16c));
        BOX2_SEQ_SetActorDrawEnable((char *)((char *)((BoxTask *)(p))->work),0xa,1); BOX2_SEQ_CreateHandSlotActorsB(((char *)((BoxTask *)(p))->work)); BOX2_SEQ_ShowHandSlots((char *)((char *)((BoxTask *)(p))->work));
    }
    if(p->menuMode==0) { BOX2_SEQ_SetSlotActors((char *)p,0x81,1); BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work)); }
    else { BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_SEQ_SetSlotActors((char *)p,0x82,1); BOX2_UI_ShowWindowB((char *)((char *)((BoxTask *)(p))->work)); }
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_SEQ_SetCursorDraw((char **)p,0);
    return 0x54;
}







int BOX2_SEQ_StatePmVoiceMenuD(BoxTask *p)
{
    int next;
    void *mon;
    switch(p->menuMode) {
    case 0: BOX2_UI_ShowWindowA((char *)((char *)((BoxTask *)(p))->work)); next=0x23; break;
    case 1:
        BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
        BOX2_UI_MoveCursor((char **)p,0xe,0xb); BOX2_UI_ShowWindowB((char *)((char *)((BoxTask *)(p))->work)); next=0x27; break;
    }
    BOX2_SEQ_RefreshCursorSlot(p);
    if((((BoxTask *)(p))->subResult)==0) {
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_SEQ_DrawFrameList((BoxTask *)p, data_021EF918, 4);
        BOX2_UI_PutListFrames(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74)); BOX2_SEQ_PrintPrompt((BoxTask *)p,p->cursorSlot,1,0x18);
        return next;
    }
    if(FILE_UTIL_Check136C((((BoxTask *)(p))->subResult))==0) {
        mon=(void *)BOX2_MAIN_GetMonAt((void ***)p,p->curBox,p->cursorSlot);
        BOX2_MAIN_SetBoxValueAt((int)p,p->cursorSlot,p->curBox,6,(((BoxTask *)(p))->subResult));
        if(BOX2_MAIN_CanPlaceInBox((void **)p,mon)==1) {
            BOX2_MAIN_RecalcPartyParam((void * *)p, p->cursorSlot);
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p,p->curBox,p->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(p))->work)+p->cursorSlot+0x3dd2));
        }
        func_02007F1C(((struct Obj23950 *)(*(char * *)&p->params))->fC,(((BoxTask *)(p))->subResult),1,0x804c);
    }
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,p->cursorSlot); BOX2_SEQ_SetCursorDraw((char **)p,0);
    return 0x54;
}










int BOX2_SEQ_StatePmVoiceOpen(unsigned char *p){BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF9B4, 5);BOX2_UI_PutListFrames((struct WinMgr *)(((struct Obj23951 *)(*(unsigned char * *)&((BoxTask *)p)->work))->f74));BOX2_SEQ_PrintPrompt((BoxTask *)p,p[22],1,24);BOX2_SEQ_RefreshCursorSlot((BoxTask *)p);return 44;}

int BOX2_SEQ_StatePmVoiceOpenB(BoxTask *p) {
 BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF950, 5);
 BOX2_UI_PutListFrames((struct WinMgr *)((int)(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74))));
 BOX2_SEQ_PrintPrompt((BoxTask *)p,p->cursorSlot,1,0x18);
 BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
 BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_RefreshCursorSlot((BoxTask *)p); return 0x31;
}















/*
 * Leaves a box-menu mode (p[0x13]): restores the windows the mode changed
 * and returns the next menu state.
 */
int BOX2_SEQ_StatePmVoiceOpenC(BoxTask *p)
{
    switch (p->menuMode) {
    case 0:
        BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
        BOX2_UI_PutListFrames((struct WinMgr *)((int)((((BoxTask *)(p))->work->winMgr))));
        BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
        BOX2_SEQ_RefreshCursorSlot((BoxTask *)p);
        return 0x11;
    case 1:
        BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EFA10, 6);
        BOX2_UI_PutListFrames((struct WinMgr *)((int)((((BoxTask *)(p))->work->winMgr))));
        BOX2_SEQ_PrintPrompt((BoxTask *)p, p->cursorSlot, 1, 0x18);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work), 0);
        BOX2_UI_MoveCursor((char **)p, 5, 10);
        BOX2_SEQ_StopLeftBar((int)p);
        BOX2_SEQ_RefreshCursorSlot((BoxTask *)p);
        return 0x1B;
    case 2:
        if (p->barOpenFlag == 1)
            BOX2_SEQ_HideSlotsC61C((BoxTask *)p);
        BOX2_UI_MoveCursor((char **)p, 4, p->cursorSlot);
        BOX2_MAIN_RefreshBoxUi(p);
        while (BOX2_MAIN_ShiftWindowRight(p) != 0)
            ;
        BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        p->cursorSlot = 0xFF;
        return 0x15;
    case 3:
        if (p->cursorSlot >= 0x1E) {
            BOX2_SEQ_HideSlotsC61C((BoxTask *)p);
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
        } else if (p->curBox == p->heldSlot) {
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
        } else {
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->heldSlot, p->cursorSlot, (((BoxTask *)(p))->work->cursorActorId));
        }
        BOX2_MAIN_SceneMoveCursor((BoxTask *)p);
        BOX2_SEQ_SetSlotDimB((char **)p, 0x24);
        BOX2_UI_MoveCursor((char **)p, 4, p->listCursorId);
        BOX2_MAIN_RefreshBoxUi(p);
        while (BOX2_MAIN_ShiftWindowRight(p) != 0)
            ;
        BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
        if (p->listCursorId >= 0x22 && p->listCursorId <= 0x25)
            BOX2_UI_SetMiniIconVisible((BoxTask *)p, p->listCursorId - 0x22, 1);
        BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
        return 0x15;
    case 4:
        BOX2_SEQ_StopRightBar((int)p);
        BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        p->cursorSlot = 0xFF;
        return 0x20;
    case 5:
        BOX2_SEQ_StopRightBar((int)p);
        if (p->cursorSlot < 0x1E && p->curBox != p->heldSlot)
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->heldSlot, p->cursorSlot, (((BoxTask *)(p))->work->cursorActorId));
        else
            BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
        BOX2_MAIN_SceneMoveCursor((BoxTask *)p);
        BOX2_SEQ_SetSlotDimB((char **)p, 0x24);
        BOX2_UI_MoveCursor((char **)p, 6, p->listCursorId);
        BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
        BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
        return 0x20;
    }
    return 0;
}
















int BOX2_SEQ_StatePmVoiceOpenD(BoxTask *p)
{
    switch(p->menuMode) {
    case 0:
        BOX2_SEQ_DrawFrameList((BoxTask *)p, data_021EF918, 4);
        BOX2_UI_PutListFrames((struct WinMgr *)((int)(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74)))); BOX2_SEQ_PrintPrompt((BoxTask *)p,p->cursorSlot,1,0x18);
        BOX2_UI_MoveCursor((char **)p,0xd,0x25); BOX2_SEQ_RefreshCursorSlot((BoxTask *)p); return 0x23;
    case 1:
        BOX2_SEQ_DrawFrameList((BoxTask *)p, data_021EF918, 4);
        BOX2_UI_PutListFrames((struct WinMgr *)((int)(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74)))); BOX2_SEQ_PrintPrompt((BoxTask *)p,p->cursorSlot,1,0x18);
        BOX2_SEQ_SetSlotActors((char *)p,1,1); BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
        BOX2_UI_MoveCursor((char **)p,0xe,0xa); BOX2_SEQ_StopLeftBar((int)p); BOX2_SEQ_RefreshCursorSlot((BoxTask *)p); return 0x27;
    case 4:
        BOX2_SEQ_StopRightBar((int)p); BOX2_UI_MoveCursor((char **)p,6,p->cursorSlot);
        CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),0x27);
        p->cursorSlot=0xff; return 0x20;
    case 5:
        BOX2_SEQ_StopRightBar((int)p);
        if(p->cursorSlot<0x1e && p->curBox!=p->heldSlot)
            BOX2_SEQ_ShowSlotIcon((BoxTask *)p,p->heldSlot,p->cursorSlot,*(unsigned char *)(((char *)((BoxTask *)(p))->work)+0x3df6));
        else BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work),p->cursorSlot);
        BOX2_MAIN_SceneMoveCursor((BoxTask *)p); BOX2_SEQ_SetSlotDimB((char **)p,0x24);
        BOX2_UI_MoveCursor((char **)p,6,p->listCursorId); CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(p))->work)+0x70),0x27);
        BOX2_SEQ_MoveCursorActor((BoxTask *)p,0x24); return 0x20;
    }
    return 0;
}
















int BOX2_SEQ_GotoRightPanelA(BoxTask *p, int a, int n)
{
    BOX2_MAIN_StopSeq((BoxTask *)p, 0);
    if (BOX2_UI_IsListOpen(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74)) == 1) {
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
        if (a == 1)
            BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsSeqIdle, n);
}














int BOX2_SEQ_GotoRightPanelB(BoxTask *p, int a, int n)
{
    BOX2_MAIN_StopSeq((BoxTask *)p, 1);
    if (BOX2_UI_IsListOpen(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74)) == 1) {
        BOX2_UI_OpenListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
        BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
        BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
        if (a == 1)
            BOX2_UI_ShowWindowA(((char *)((BoxTask *)(p))->work));
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_IsSeqStep, n);
}

int BOX2_SEQ_SelectSlotA(BoxTask *p, int i)
{
    p->barOpenFlag = 0;
    p->listState = 0;
    p->cursorSlot = i;
    p->heldSlot = p->curBox;
    BOX2_SEQ_SetSlotDrawPriority((char *)p->work, p->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors((char *)p->work, p->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_SEQ_Create((void *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowA((char *)p->work);
    p->state = 0x15;
    p->phase = 0;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineScroll, 0x12);
}

int BOX2_SEQ_SelectSlotB(BoxTask *p, int i)
{
    p->cursorSlot = i;
    p->heldSlot = p->curBox;
    p->barOpenFlag = 0;
    BOX2_SEQ_SetSlotDrawPriority((char *)p->work, p->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors((char *)p->work, p->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_SEQ_Create((void *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    p->phase = 0;
    p->state = 0x20;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_StateMachineScroll, 0x24);
}

int BOX2_SEQ_SelectSlotC(BoxTask *p, int a)
{
    u8 old = p->curBox;
    p->cursorSlot = a;
    p->heldSlot = old;
    BOX2_SEQ_SetSlotDrawPriority((char *)(*(u32 *)&p->work), p->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors((char *)(*(u32 *)&p->work), p->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_UI_ToggleSlotPair((char *)(*(u32 *)&p->work), 0);
    BOX2_SEQ_HideSlotsC61C((BoxTask *)p);
    BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
    BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
    BOX2_SEQ_SetSlotActorMode((char *)(*(u32 *)&p->work), 0x24, 0);
    BOX2_SEQ_Create((void *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject((char *)(*(u32 *)&p->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    p->phase = 2;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)((void (*)(void))BOX2_MAIN_StateMachinePen), 0x30);
}

int BOX2_SEQ_GotoSlotHandlerA(BoxTask *p, int i, int v)
{
    p->cursorSlot = i;
    *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA172) = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), (unsigned char)p->cursorSlot, 1);
    BOX2_SEQ_RefreshCursorSlot((BoxTask *)p);
    BOX2_UI_CloseListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)p, v));
}

int BOX2_SEQ_SelectPartySlotA(unsigned char *p, int i)
{
    p[0x16] = i;
    ((Nib_021E65E4 *)(p + 0x1C))->lo = 0;
    p[0x17] = p[0x14];
    p[0x1B] = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), p[0x16], 0);
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p[0x16]);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    POKEPARTY_GetMember(((struct Obj23952 *)(*(char * *)&((BoxTask *)p)->params))->f8, i - 0x1E);
    BOX2_SEQ_Create((void *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    BOX2_UI_ShowWindowB(((char *)((BoxTask *)(p))->work));
    ((BoxTask *)p)->state = 0x20;
    p[0x1A] = 1;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachinePick, 0x1E);
}

int BOX2_SEQ_SelectPartySlotB(BoxTask *p, int i)
{
    p->heldSlot = p->curBox;
    p->cursorSlot = i;
    p->barOpenFlag = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    POKEPARTY_GetMember(((struct Obj23953 *)(*(char * *)&p->params))->f8, i - 0x1E);
    BOX2_SEQ_Create((void *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    p->state = 0x20;
    p->phase = 1;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachinePick, 0x2A);
}

int BOX2_SEQ_SelectPartySlotC(BoxTask *p, int i)
{
    p->cursorSlot = i;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), p->cursorSlot, 0);
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_SEQ_SetSlotActors((char *)p, 2, 1);
    BOX2_SEQ_SetSlotActorMode(((char *)((BoxTask *)(p))->work), 0x24, 0);
    POKEPARTY_GetMember(((struct Obj23954 *)(*(char * *)&p->params))->f8, i - 0x1E);
    BOX2_SEQ_Create((void *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    BOX2_SEQ_ShowWindowObject(((char *)((BoxTask *)(p))->work), 0x18);
    BOX2_MAIN_RefreshCursorBox(p);
    p->phase = 1;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineMove, 0x38);
}

int BOX2_SEQ_GotoSlotHandlerB(BoxTask *p, int i, int v)
{
    p->cursorSlot = i;
    *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA172) = 1;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), (unsigned char)p->cursorSlot, 1);
    BOX2_SEQ_RefreshCursorSlot((BoxTask *)p);
    BOX2_UI_CloseListPack(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work) + 0x74));
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneWaitScroll, BOX2_SEQ_SetState((BoxTask *)p, v));
}

int BOX2_SEQ_SelectSlotD(BoxTask *p, int i, int v)
{
    p->heldSlot = p->curBox;
    p->cursorSlot = i;
    *(int *)(((char *)((BoxTask *)(p))->work) + 0xA168) = i;
    BOX2_SEQ_SwapSlotActors(((char *)((BoxTask *)(p))->work), p->cursorSlot);
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 2);
    BOX2_SEQ_Create((void *)p);
    p->state = v;
    p->phase = 2;
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineScroll, 0x17);
}













int BOX2_SEQ_HideSlotWindow(BoxTask *p, unsigned char i)
{
    p->handMode = 1;
    p->cursorSlot = i;
    BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 0);
    if (p->params->mode == 4) {
        BOX2_UI_HideWindowA(((char *)((BoxTask *)(p))->work));
        BOX2_UI_HideWindowB(((char *)((BoxTask *)(p))->work));
        CURSOR_MOVE_ClearSkipBit(*(void **)(((char *)((BoxTask *)(p))->work) + 0x70), 0x27);
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneWaitCursor, 0x20);
}

/*
 * Arm the flag, store the state byte, zero the 0x24 queue entry,
 *   re-stage it, publish (2,1,0) and set selector 0x021E0779.
 */
int BOX2_SEQ_SelectBoxSlot(BoxTask *p, int a)
{
    p->handMode = 1;
    p->cursorSlot = a;
    BOX2_SEQ_SetSlotDrawPriority((char *)(*(int *)&p->work), 0x24, 0);
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, 0x24);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 0);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x021E0779, 0x15);
}

int BOX2_SEQ_ScrollListToSlot(BoxTask *p, unsigned i, int v)
{
    if (i >= 0x1E && i >= 0x24 && i != 0xFF) {
        unsigned k = p->prevBox + i - 0x24;
        if (k >= p->boxLimit)
            k -= p->boxLimit;
        if (k == p->curBox) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            return 0x15;
        }
        if (func_020077B8(p->params->boxSave, k) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x557);
            return 0x15;
        }
    }
    ((struct Obj23957 *)(*(char * *)&p->work))->fA17E = i;
    p->phase = 2;
    p->state = v;
    BOX2_SEQ_Create((void *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_SceneOpenBox, 0x17);
}

/*
 * Allocate (0x4c, 0xb8, 1) into the 0x021F140C buffer and store
 * the handle at sub-object +0x60.
 */
void BOX2_SEQ_Create(void *p)
{
    int v = (int)func_02030734(0x4c, 0xb8, 1, (const char *)0x021F140C, 0x2130);
    *(int *)(((struct Obj18479 *)p)->f2C + 0x60) = v;
}

/*
 * Tail call func_020307B0 with the word at +0x2c/+0x60.
 */
void BOX2_SEQ_Delete(BoxTask *p)
{
    func_020307B0(((struct Obj18480 *)(*(char * *)&p->work))->f60);
}












int BOX2_SEQ_DrawGridSlot(BoxTask *p, int i)
{
    short t[2];
    p->cursorSlot = i;
    p->heldSlot = p->curBox;
    p->work->cancelFlag = 1;
    (((BoxTask *)(p))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    BOX2_UI_ResetSlotFrames((((BoxTask *)(p))->work->winMgr));
    BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    if ((((BoxTask *)(p))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)p->work, p->cursorSlot, 0);
        BOX2_SEQ_SetSlotCharacter((char *)p->work, (((BoxTask *)(p))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)p->work);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    } else if (BOX2_SEQ_GetActorDrawEnable((char *)p->work, 10) == 1) {
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
    }
    BOX2_SEQ_GetSlotPos(p->cursorSlot, &t[1], &t[0], 0);
    *(int *)((char *)p->work + 0xA180) = t[1] + 8;
    *(int *)((char *)p->work + 0xA184) = t[0] + 8;
    BOX2_SEQ_CreateB((void *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineCoin, BOX2_SEQ_SetState((BoxTask *)p, 0x3E));
}

int BOX2_SEQ_SetCursorMove(BoxTask *p, int i)
{
    p->cursorSlot = i;
    p->heldSlot = p->curBox;
    p->work->cancelFlag = 1;
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
    (((BoxTask *)(p))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    BOX2_SEQ_SetActorAnim((BoxTask *)p, (short)(((BoxTask *)(p))->work->counter));
    BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
    if ((((BoxTask *)(p))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)p->work, p->cursorSlot, 0);
        BOX2_SEQ_SetSlotCharacter((char *)p->work, (((BoxTask *)(p))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)p->work);
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 0x24, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x24);
    } else {
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 0x25, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 0x25);
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_Check0A40, BOX2_SEQ_SetState((BoxTask *)p, 0x39));
}










int BOX2_SEQ_SelectGridSlot(BoxTask *p, unsigned i)
{
    short t[2];
    p->cursorSlot = i;
    p->heldSlot = i < 0x1E ? p->curBox : 0xFF;
    (((BoxTask *)(p))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    if ((((BoxTask *)(p))->work->counter) == 0) {
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), p->cursorSlot);
        return 0x40;
    }
    GFL_USE_PlaySeDefaultVolume(0x666);
    BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
    BOX2_SEQ_MoveActorToSlot((char *)p->work, p->cursorSlot, 2);
    BOX2_SEQ_SetSlotCharacter((char *)p->work, (((BoxTask *)(p))->work->counter));
    BOX2_SEQ_CreateHandSlotActorsB((char *)p->work);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 1);
    BOX2_SEQ_GetSlotPos(p->cursorSlot, &t[1], &t[0], 2);
    *(int *)((char *)p->work + 0xA180) = t[1] + 8;
    *(int *)((char *)p->work + 0xA184) = t[0] + 8;
    BOX2_SEQ_CreateB((void *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_StateMachineSlide, 0x42);
}

int BOX2_SEQ_DrawGridSlotB(BoxTask *p, unsigned i)
{
    p->cursorSlot = i;
    *(unsigned short *)((char *)p->work + 0xA16E) = i;
    p->heldSlot = i < 0x1E ? p->curBox : 0xFF;
    (((BoxTask *)(p))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    if ((((BoxTask *)(p))->work->counter) == 0)
        return 0x40;
    p->handMode = 1;
    BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
    BOX2_SEQ_MoveActorToSlotB((char *)p->work, p->cursorSlot, 2);
    BOX2_SEQ_SetSlotCharacter((char *)p->work, (((BoxTask *)(p))->work->counter));
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 1);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_StateMenuSelect, 0x40);
}

int BOX2_SEQ_UpdateGridCursor(BoxTask *p)
{
    unsigned char v = CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound));
    if (v < 0x24)
        BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, v);
    else
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
    BOX2_SEQ_CreateB((void *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_StateMenuMain, 0x43);
}










int BOX2_SEQ_MoveGridCursor(BoxTask *p, unsigned i)
{
    short t[2];
    (((BoxTask *)(p))->work->targetBox) = i;
    p->handMode = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)p->work, 4, &t[1], &t[0], 0);
    BOX2_SEQ_AddActorSurfacePos((char *)p->work, 10, (short)t[1], (short)(t[0] + 8), (short)0);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    if ((((BoxTask *)(p))->work->targetBox) == 0xFF)
        return BOX2_SEQ_UpdateGridCursor((BoxTask *)p);
    if (BOX2_MAIN_CompareSlots((unsigned char *)p, p->cursorSlot, i) == 0)
        return BOX2_SEQ_UpdateGridCursor((BoxTask *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_StateMenuSwap, 0x45);
}

int BOX2_SEQ_DeleteGridSlot(BoxTask *p, int i)
{
    short t[2];
    p->cursorSlot = i;
    p->heldSlot = 0xFF;
    (((BoxTask *)(p))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    BOX2_UI_ResetSlotFrames((((BoxTask *)(p))->work->winMgr));
    BOX2_SEQ_ShowWindowObject((char *)p->work, 0x18);
    BOX2_MAIN_RefreshCursorBox((BoxTask *)p);
    if ((((BoxTask *)(p))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)p->work, p->cursorSlot, 1);
        BOX2_SEQ_SetSlotCharacter((char *)p->work, (((BoxTask *)(p))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)p->work);
        BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
    } else if (BOX2_SEQ_GetActorDrawEnable((char *)p->work, 10) == 1) {
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
    }
    BOX2_SEQ_GetSlotPos(p->cursorSlot, &t[1], &t[0], 1);
    *(int *)((char *)p->work + 0xA180) = t[1] + 8;
    *(int *)((char *)p->work + 0xA184) = t[0] + 8;
    BOX2_SEQ_CreateB((void *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_SEQ_StateMachineMove, 0x48);
}









int BOX2_SEQ_SetCursorMoveB(BoxTask *p, int i)
{
    p->cursorSlot = i;
    p->heldSlot = p->curBox;
    p->work->cancelFlag = 1;
    BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p, p->cursorSlot);
    (((BoxTask *)(p))->work->counter) = BOX2_MAIN_GetPartyValueAt((void ***)p, p->cursorSlot, p->curBox, 6, 0);
    BOX2_SEQ_SetActorAnim((BoxTask *)p, (short)(((BoxTask *)(p))->work->counter));
    BOX2_UI_CloseListPack((((BoxTask *)(p))->work->winMgr));
    if ((((BoxTask *)(p))->work->counter) != 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)p->work, 10, 0);
        BOX2_SEQ_MoveActorToSlot((char *)p->work, p->cursorSlot, 1);
        BOX2_SEQ_SetSlotCharacter((char *)p->work, (((BoxTask *)(p))->work->counter));
        BOX2_SEQ_CreateHandSlotActorsB((char *)p->work);
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 9, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 9);
    } else {
        BOX2_UI_MoveCursorBetweenIcons((char *)p->work, 10, CURSOR_MOVE_GetCurrent((((BoxTask *)(p))->work->sound)));
        CURSOR_MOVE_SetCurrent((((BoxTask *)(p))->work->sound), 10);
    }
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)BOX2_MAIN_Check0A40, BOX2_SEQ_SetState((BoxTask *)p, 0x46));
}

/*
 * Sibling of BOX2_SEQ_Create with (0x1c, 0) and the 0x228F buffer.
 */
void BOX2_SEQ_CreateB(void *p)
{
    int v = (int)func_02030734(0x4c, 0x1c, 0, (const char *)0x021F140C, 0x228F);
    *(int *)(((struct Obj18488 *)p)->f2C + 0x60) = v;
}

void BOX2_SEQ_DeleteB(BoxTask *p)
{
    func_020307B0(((struct Obj18489 *)(*(char * *)&p->work))->f60);
}








/*
 * Stop one 0x74 sub-object, then the plain stop.
 */
void BOX2_SEQ_StopLeftBar(int p)
{
    BOX2_UI_PutTopBarOpen(*(struct WinMgr **)(((struct Obj18491 *)p)->f2C + 0x74));
    BOX2_SEQ_HideSlotsC688((BoxTask *)p);
}

/*
 * Resume one 0x74 sub-object, then the plain resume.
 */
void BOX2_SEQ_StopRightBar(int p)
{
    BOX2_UI_PutTopBarClosed(*(struct WinMgr **)(((struct Obj18493 *)p)->f2C + 0x74));
    BOX2_SEQ_HideSlotsC6F4((BoxTask *)p);
}

/*
 * Plain stop, then stop the 0x74 sub-object.
 */
void BOX2_SEQ_RestartLeftBar(int p)
{
    BOX2_SEQ_HideSlotsC688((BoxTask *)p);
    BOX2_UI_PutTopBarOpen(*(struct WinMgr **)(((struct Obj18495 *)p)->f2C + 0x74));
}

int BOX2_SEQ_DrawListSlot(BoxTask *p, int sel)
{
    int (*cb)(unsigned char *);
    int r = BOX2_MAIN_IsWrappedDistance((unsigned char *)p, p->curBox, *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA17F));
    p->curBox = *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0xA17F);
    BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
    BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), r);
    if (r == 1)
        cb = (int (*)(unsigned char *))BOX2_MAIN_IsSeqStep;
    else
        cb = (int (*)(unsigned char *))BOX2_MAIN_IsSeqIdle;
    switch (sel) {
    case 0:
        p->state = 0x15;
        break;
    case 1:
        p->state = 0x63;
        break;
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, (int)cb, p->state);
}

void BOX2_SEQ_CreateC(BoxTask *p)
{
    unsigned short *q = func_02030734(0x804C, 4, 0, d_021F140C, 0x2305);
    q[0] = 0;
    q[1] = 0;
    *(unsigned short * *)&((struct Obj23958 *)(*(char * *)&p->work))->fA190 = q;
}

/*
 * Reset the entry then store the field with the dispatcher
 *   thumb-pointer 0x021E01C5 as its second argument.
 */
int BOX2_SEQ_ResetEntry(char *p, int a)
{
    BOX2_MAIN_RefreshBoxUi((BoxTask *)p);
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x021E01C5, a);
}











/*
 * Same forward as BOX2_SEQ_ResetEntry but after restarting the queue.
 */
int BOX2_SEQ_ResetEntryB(BoxTask *p, int a)
{
    BOX2_UI_CloseInfoBar(*(struct WinMgr **)(*(int *)&p->work + 0x74));
    return BOX2_SEQ_SetSeqThird((BoxTask *)p, 0x021E01E1, a);
}

void BOX2_SEQ_SetActorAnim(BoxTask *p, int v)
{
    if (v != 0) {
        if (p->cursorSlot < 0x1E)
            CURSOR_MOVE_SetSkipBit((((BoxTask *)(p))->work->sound), 0x24);
        else
            CURSOR_MOVE_SetSkipBit((((BoxTask *)(p))->work->sound), 9);
        BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF8FC, 3);
    } else {
        if (p->cursorSlot < 0x1E)
            CURSOR_MOVE_ClearSkipBit((((BoxTask *)(p))->work->sound), 0x24);
        else
            CURSOR_MOVE_ClearSkipBit((((BoxTask *)(p))->work->sound), 9);
        BOX2_SEQ_DrawFrameList((BoxTask *)p, d_021EF8F4, 2);
    }
}

/*
 * Busy 1 for the 0x16 field below 0x1e, else run the panel query and
 *   answer 2 for a hit, 0 otherwise.  `p` must be unsigned char *
 *   (ldrb, not ldrsb) and the result must be the CONSTANTS 1/2/0 with
 *   an early return -- an `int r = 0; ... return r;` keeps r live from
 *   the top, which pushes i from r4 to r6 and widens the push set.
 */
int BOX2_SEQ_CheckTradableMon(unsigned char *p)
{
    int i = p[0x16] - 0x1e;
    if (BOX2_MAIN_HasOtherTradable((void ***)p, i) == 0)
        return 1;
    if (FILE_UTIL_Check136C((unsigned short)func_02017E1C(
            POKEPARTY_GetMember(*(void **)(((struct Obj12168 *)p)->f0 + 8), i), 6, 0)) == 1)
        return 2;
    return 0;
}

/*
 * candidate BOX2_SEQ_ToggleHandSlot: xor bit
 */
void BOX2_SEQ_ToggleHandSlot(int p, int bit)
{
    *(int *)(*(int *)&((BoxTask *)p)->work + 0xA174) ^= 1 << bit;
    BOX2_MAIN_SetHandSlots((char *)p, *(int *)(*(int *)&((BoxTask *)p)->work + 0xA174));
}

int BOX2_SEQ_GotoSceneA(BoxTask *p,int a) {
 if((unsigned char)((char *)((BoxTask *)(p))->work)[0xA17C]<=4 || ((unsigned char)((char *)((BoxTask *)(p))->work)[0xA17C]==5 && func_02007A80(((struct Obj23959 *)(*(char * *)&p->params))->f4,2)==0))
  ((char *)((BoxTask *)(p))->work)[0xA17B]=((unsigned char)((char *)((BoxTask *)(p))->work)[0xA17C]-1)*4+a-1;
 else ((char *)((BoxTask *)(p))->work)[0xA17B]=((unsigned char)((char *)((BoxTask *)(p))->work)[0xA17C]-1)*4+a;
 return BOX2_SEQ_GotoBox2Main((BoxTask *)p,a,BOX2_SEQ_ReturnAfterClear((BoxTask *)p,0x66));
}

void BOX2_SEQ_DeleteSlotWindows(BoxTask *p) {
 switch(((struct Obj23961 *)(*(char * *)&p->params))->f24) {
 case 0: BOX2_SEQ_SetSlotActors((char *)p,2,1); return;
 case 1: case 3: BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0); BOX2_SEQ_SetSlotActors((char *)p,1,1); return;
 case 2: case 4: case 5:
  BOX2_UI_ToggleSlotPair(((char *)((BoxTask *)(p))->work),0);
  if(BOX2_UI_IsTopBarClosed(*(struct WinMgr **)(((char *)((BoxTask *)(p))->work)+0x74))==1) {
   BOX2_SEQ_SetSlotActors((char *)p,2,1); return;
  } else { BOX2_SEQ_SetSlotActors((char *)p,1,1); return; }
 }
}

int BOX2_SEQ_GotoBox2MainPlaySe(BoxTask *p, int v)
{
    GFL_USE_PlaySeDefaultVolume(0x54C);
    if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1)
        p->listState = 2;
    else
        p->listState = 1;
    p->exitFlag = 0;
    BOX2_MAIN_PlayCursorSound((BoxTask *)p);
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, v);
}

int BOX2_SEQ_GotoBox2MainNoSe(BoxTask *p, int v)
{
    GFL_USE_PlaySeDefaultVolume(0x54C);
    if (BOX2_UI_IsListOpen((((BoxTask *)(p))->work->winMgr)) == 1)
        p->listState = 2;
    else
        p->listState = 1;
    p->exitFlag = 0;
    return BOX2_SEQ_ReturnAfterClear((BoxTask *)p, v);
}

void BOX2_SEQ_InitBmpWins(BoxTask *p) {
 const unsigned char *x; unsigned i;
 BMP_WIN_Init(0x4C);
 x=d_021EFC20;
 for(i=0;i<28;i++,x+=6)
  *(void **)(((char *)((BoxTask *)(p))->work)+0x94+i*8)=(void *)BMP_WIN_Create(x[0],x[1],x[2],x[3],x[4],x[5],1);
}

/*
 * Walk 0x1c 8-byte records at p+0x2c+0x94, release each, then
 *   release the pool.  Unsigned counter for the image's blo.
 */
void BOX2_SEQ_DeleteBmpWins(char *p)
{
    unsigned i;
    for (i = 0; i < 0x1c; i++)
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(((struct Obj18507 *)p)->f2C + i * 8 + 0x94)));
    BMP_WIN_Exit();
}

/*
 * Set bit i of the 0x174-byte bitmap hung off p.
 *   Unsigned index, or mwccarm emits asr instead of the image's lsr.
 */
void BOX2_SEQ_SetDirtyBit(unsigned char *p, unsigned i)
{
    unsigned char *q = p + 0x174;
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
 PRINTSYS_QUE_Main(((struct Obj08242 *)w)->f8C);
 for(i=0;i<28;i++) {
  print=((struct Obj08242 *)w)->f8C;
  if(w[0x98+i*8]) {
   if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)print,BMP_WIN_GetBmp(*(void **)(w+i*8+0x94)))==0) {
    BMP_WIN_TransferChars(*(void **)(w+i*8+0x94));
    w[0x98+i*8]=0;
   }
  }
 }
}

/*
 * Release both children of the object and then a global one.
 */
void BOX2_SEQ_MakeScreen(void **p)
{
    BMP_WIN_MakeScreen(*p);
    func_02041B6C(BMP_WIN_GetBgLayer(*p));
}

void BOX2_SEQ_ClearScreen(void **p)
{
    BMP_WIN_ClearScreen(*p);
    func_02041B6C(BMP_WIN_GetBgLayer(*p));
}

void BOX2_SEQ_PrintTextWin(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color) {
 void *s; unsigned print;
 s=func_02045EC0(bank,idx);
 print=((struct Obj23962 *)w)->f8C;
 PRINTSYS_PrintQueColor((void *)print,(u32)BMP_WIN_GetBmp(*(void **)(w+0x94+i*8)),(short)x,(short)y,(u32)s,font,color);
 *(w+i*8+0x98)=1;
 STRBUF_Delete(s);
}

/*
 * Expands message idx of bank into the work string buffer and prints it into
 * message window i; marks the window dirty.
 */
void BOX2_SEQ_PrintTextWinEx(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color)
{
    u32 print;
    void *s;
    s = func_02045EC0(bank, idx);
    func_0201F250(((struct Obj00414 *)w)->f84, (void *)(*(u32 *)&((struct Obj00414 *)w)->f88), s);
    print = ((struct Obj00414 *)w)->f8C;
    PRINTSYS_PrintQueColor((void *)print, (u32)BMP_WIN_GetBmp(*(void **)(w + i * 8 + 0x94)), (short)x, (short)y, *(u32 *)&((struct Obj00414 *)w)->f88, font, color);
    *(unsigned char *)(w + i * 8 + 0x98) = 1;
    STRBUF_Delete(s);
}

/*
 * Call func_02045B38 with fixed arguments.
 */
void *BOX2_SEQ_CreateMsgBank(void)
{
    return func_02045B38(0, 2, 0xa, 0x4c);
}

void BOX2_SEQ_PrintMsgWin(BoxTask *p) {
 unsigned char *w; void *bank;
 w=(unsigned char *)((char *)((BoxTask *)(p))->work);
 BMP_Clear(BMP_WIN_GetBmp(((BoxWork *)w)->windows[0].obj),0);
 bank=BOX2_SEQ_CreateMsgBank();
 BOX2_SEQ_PrintTextWin(w,0,bank,((struct Obj23964 *)(*(char * *)&p->params))->f24+0x25,0,8,((BoxWork *)w)->heapId,0x440);
 MSGDATA_Delete(bank);
 BOX2_SEQ_MakeScreen((void **)(((char *)((BoxTask *)(p))->work)+0x94));
}

void BOX2_SEQ_InitBmpWin(BoxTask *p)
{
    u8 *q = *(u8 * *)&p->work;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((BoxWork *)q)->iconSlots[0].obj)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((BoxWork *)q)->iconSlots[1].obj)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((BoxWork *)q)->iconSlots[2].obj)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((BoxWork *)q)->iconSlots[3].obj)), 0);
    BOX2_SEQ_PrintTextWin(q, 0xa, (void *)(((struct Obj02053 *)q)->f80), 0x6d, 0, 0, ((BoxWork *)q)->heapId, 0x440);
    BOX2_SEQ_PrintTextWin(q, 0xb, (void *)(((struct Obj02053 *)q)->f80), 0x64, 0, 0, ((BoxWork *)q)->heapId, 0x440);
    BOX2_SEQ_PrintTextWin(q, 0xc, (void *)(((struct Obj02053 *)q)->f80), 0x65, 0, 0, ((BoxWork *)q)->heapId, 0x440);
    BOX2_SEQ_PrintTextWin(q, 0xd, (void *)(((struct Obj02053 *)q)->f80), 0x66, 0, 0, ((BoxWork *)q)->heapId, 0x440);
}

void BOX2_SEQ_FillTextWinEntry(unsigned char *w,Entry_021EADB4 *e,unsigned i) {
 void **windows;
 windows=(void **)(w+0x94);
 BMP_Clear(BMP_WIN_GetBmp(windows[i*2]),0);
 if(!e->flag) {
  func_0201EEA4(((struct Obj00414 *)w)->f84,0,(void *)e->value);
  BOX2_SEQ_PrintTextWinEx((char *)w,i,((struct Obj00414 *)w)->f80,0,0,0,((struct Obj00414 *)w)->f78,0x440);
 } else { BOX2_SEQ_SetDirtyBit((unsigned char *)w,i); return; }
 BOX2_SEQ_MakeScreen(windows+i*2);
}

void BOX2_SEQ_FillTextWin(char *p, void **q, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    func_0201EF14(((BoxWork *)p)->font, 0, *q);
    BOX2_SEQ_PrintTextWinEx(p, i, ((BoxWork *)p)->fontRes, 1, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

void BOX2_SEQ_DrawCellEntry(char *p, Entry_021EAE74 *e, unsigned i)
{
    unsigned n;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag) {
        BOX2_SEQ_PrintTextWinEx(p, i, ((BoxWork *)p)->fontRes, 107, 0, 0, ((BoxWork *)p)->heapId, 0x440);
        n = func_0201D304(((BoxWork *)p)->msgData, ((BoxWork *)p)->heapId, 0);
        func_0201EFA4(((BoxWork *)p)->font, 0, e->low, 3, 0, 1);
        BOX2_SEQ_PrintTextWinEx(p, i, ((BoxWork *)p)->fontRes, 103, n, 0, ((BoxWork *)p)->heapId, 0x440);
    } else {
        BOX2_SEQ_SetDirtyBit((unsigned char *)p, i); return;
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

/*
 * trailing: two-byte zero alignment padding at 0x021EAFBA.
 */
void BOX2_SEQ_DrawSpriteEntry(char *p, Entry_021EAF20 *e, unsigned i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (!e->flag && e->enabled == 1) {
        if (e->kind == 0) {
            BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((BoxWork *)p)->fontRes, 95, 0, 0, ((BoxWork *)p)->heapId, 0x14c0);
        } else if (e->kind == 1) {
            BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((BoxWork *)p)->fontRes, 96, 0, 0, ((BoxWork *)p)->heapId, 0xc80);
        } else {
            BOX2_SEQ_SetDirtyBit((unsigned char *)p, i); return;
        }
    } else {
        BOX2_SEQ_SetDirtyBit((unsigned char *)p, i); return;
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

void BOX2_SEQ_DrawTileEntry(char *p,const Entry_021EAFBC *e,u32 i)
{
    u16 n;
    u32 text;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(((char *)((BoxTask *)(p))->work)+i*8+148)),0);
    if (e->high == 0) {
        if (*(u32 *)(((char *)((BoxTask *)(p))->work)+380) == 1)
            n = ((struct Obj06549 *)e)->f4;
        else
            n = *(u16 *)(*(char **)(((char *)((BoxTask *)(p))->work)+384)+((struct Obj06549 *)e)->f4*2);
        if (n != 999) {
            BOX2_SEQ_PrintTextWinEx(((char *)((BoxTask *)(p))->work),i,*(void **)(((char *)((BoxTask *)(p))->work)+128),108,0,0,*(u32 *)(((char *)((BoxTask *)(p))->work)+120),1088);
            text=func_0201D304(*(void **)(((char *)((BoxTask *)(p))->work)+136),*(u32 *)(((char *)((BoxTask *)(p))->work)+120),0);
            func_0201EFA4(*(void **)(((char *)((BoxTask *)(p))->work)+132),0,n,3,2,1);
            BOX2_SEQ_PrintTextWinEx(((char *)((BoxTask *)(p))->work),i,*(void **)(((char *)((BoxTask *)(p))->work)+128),104,text,0,*(u32 *)(((char *)((BoxTask *)(p))->work)+120),1088);
        } else { BOX2_SEQ_SetDirtyBit((unsigned char *)((char *)((BoxTask *)(p))->work),i); return; }
    } else { BOX2_SEQ_SetDirtyBit((unsigned char *)((char *)((BoxTask *)(p))->work),i); return; }
    BOX2_SEQ_MakeScreen((void **)(((char *)((BoxTask *)(p))->work)+148+i*8));
}

void BOX2_SEQ_DrawMoveEntry(char *p, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry_021EB098 *)e)->flag) {
        func_0201EF98(((BoxWork *)p)->font, 0, e[15]);
        BOX2_SEQ_PrintTextWinEx(p, i, ((BoxWork *)p)->fontRes, 98, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((BoxWork *)p)->fontRes, 106, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

void BOX2_SEQ_DrawSwapEntry(char *p, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (!((Entry_021EB114 *)e)->flag) {
        func_0201EF8C(((BoxWork *)p)->font, 0, e[14]);
        BOX2_SEQ_PrintTextWinEx(p, i, ((BoxWork *)p)->fontRes, 97, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((BoxWork *)p)->fontRes, 106, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

void BOX2_SEQ_DrawItemEntry(char *p, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (((struct Obj06549 *)e)->f6 != 0) {
        WORDSET_Callback_EF40(((BoxWork *)p)->font, 0, ((struct Obj06549 *)e)->f6);
        BOX2_SEQ_PrintTextWinEx(p, i, ((BoxWork *)p)->fontRes, 99, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((BoxWork *)p)->fontRes, 105, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}

/*
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`windows = (void **)p;` before `windows = (void **)(p + 0x94);`). Game
 * code has no line table, so these were stand-ins. The plain single
 * assignment gives EXACT in --lang c99 and --lang c: the output bytes do not
 * change. Older text in this header that asks for the double assignment is
 * superseded.
 */
void BOX2_SEQ_DrawMsgEntry(char *p, Entry_021EB208 *e, int i)
{
    void **windows;
    unsigned j;
    void *bank;
    windows = (void **)(p + 0x94);
    BMP_Clear(BMP_WIN_GetBmp(windows[i * 2]), 0);
    j = 0;
    bank = func_02045B38(0, 2, 203, 0x804c);
    if (!e->flag) {
        for (; j < 4; j++) {
            BOX2_SEQ_PrintTextWin((unsigned char *)p, i, bank, *(unsigned short *)((char *)e + 0x14 + j * 2), 0, j * 16, ((BoxWork *)p)->heapId, 0x440);
        }
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((BoxWork *)p)->fontRes, 106, 0, 0, ((BoxWork *)p)->heapId, 0x440);
    }
    MSGDATA_Delete(bank);
    BOX2_SEQ_MakeScreen(windows + i * 2);
}













void BOX2_SEQ_DeleteTextEntries(BoxTask *p, int a)
{
    BOX2_SEQ_FillTextWinEntry((unsigned char *)((char *)p->work), (Entry_021EADB4 *)a, 1);
    BOX2_SEQ_FillTextWin((char *)p->work, (void **)a, 2);
    BOX2_SEQ_DrawCellEntry((char *)p->work, (Entry_021EAE74 *)a, 3);
    BOX2_SEQ_DrawSpriteEntry((char *)p->work, (Entry_021EAF20 *)a, 4);
    BOX2_SEQ_DrawTileEntry((char *)p, (const Entry_021EAFBC *)a, 5);
    BOX2_SEQ_DrawMoveEntry((char *)p->work, (unsigned char *)a, 6);
    BOX2_SEQ_DrawSwapEntry((char *)p->work, (unsigned char *)a, 7);
    BOX2_SEQ_DrawItemEntry((char *)p->work, (unsigned char *)a, 8);
    BOX2_SEQ_DrawMsgEntry((char *)p->work, (Entry_021EB208 *)a, 9);
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)p->work + 0xe4));
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)p->work + 0xec));
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)p->work + 0xf4));
    BOX2_SEQ_MakeScreen((void **)((u8 *)(char *)p->work + 0xfc));
}

void BOX2_SEQ_ClearTextWin(Work *w)
{
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
void BOX2_SEQ_DrawWindowFrame(BoxTask *p, int idx, unsigned msg, unsigned short frame, unsigned short col, int icon)
{
    void *win = *(void **)(((char *)((BoxTask *)(p))->work) + 0x94 + idx * 8);
    void *bmp = BMP_WIN_GetBmp((struct Descriptor *)win);
    unsigned char w;
    unsigned char h;
    Chr *chr;
    void *res;
    char *raw;
    void *t;
    unsigned char i;
    void *str;

    BMP_WIN_GetBgLayer(win);
    BMP_WIN_GetPosX((struct Descriptor *)win);
    BMP_WIN_GetPosY((struct Descriptor *)win);
    w = BMP_WIN_GetWidth((struct Descriptor *)win);
    h = BMP_WIN_GetHeight((struct Descriptor *)win);
    BMP_Clear(bmp, 4);
    res = func_02049DB4(0x74, 0x3E, 1, (u32)(&chr), HEAP);
    raw = chr->raw;
    frame *= 0x20;

    t = BMP_CreateFromBuffer(raw + frame, 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, 0, 0, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x40), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, 0, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xC0), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, 0, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x100), 8, 8, 0x20, HEAP);
    BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x60), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        BMP_Blit(t, bmp, 0, 0, 0, i * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xA0), 8, 8, 0x20, HEAP);
    for (i = 1; i < h - 1; i++)
        BMP_Blit(t, bmp, 0, 0, (w - 1) * 8, i * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0x20), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        BMP_Blit(t, bmp, 0, 0, i * 8, 0, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    t = BMP_CreateFromBuffer(raw + (frame + 0xE0), 8, 8, 0x20, HEAP);
    for (i = 1; i < w - 1; i++)
        BMP_Blit(t, bmp, 0, 0, i * 8, (h - 1) * 8, 8, 8, 0xFFFF);
    BMP_Delete((struct Obj020437AC *)t);

    func_020307B0((void *)res);

    if (icon == 1) {
        res = func_02049DB4(func_020275E4(), 0x20, 0, (u32)(&chr), HEAP);
        t = BMP_CreateFromBuffer(chr->raw + 0x120, 0x10, 8, 0x20, HEAP);
        BMP_Blit(t, bmp, 0, 0, (w - 3) * 8, 8, 0x10, 8, 5);
        BMP_Delete((struct Obj020437AC *)t);
        func_020307B0((void *)res);
    }

    str = func_02045EC0(*(void **)(((char *)((BoxTask *)(p))->work) + 0x80), msg);
    TOUCHBAR_PrintAligned((u8 *)(((char *)((BoxTask *)(p))->work) + 0x94 + idx * 8), (void *)(*(void **)(((char *)((BoxTask *)(p))->work) + 0x8C)), w * 8 / 2, 4, (u32)str,
                  *(unsigned *)(((char *)((BoxTask *)(p))->work) + 0x78), col, 2);
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

void BOX2_SEQ_AddTextFrame(BoxWork *p)
{
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&p->winMgr, 0, p->iconSlots[4].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&p->winMgr, 1, p->iconSlots[5].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&p->winMgr, 2, p->iconSlots[6].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&p->winMgr, 3, p->iconSlots[7].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&p->winMgr, 4, p->iconSlots[8].obj);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&p->winMgr, 5, p->iconSlots[9].obj);
}

void BOX2_SEQ_AddMsgFrame(unsigned char *p){if(((struct Obj23969 *)(*(unsigned char * *)&((BoxTask *)p)->params))->f24==4)BOX2_SEQ_DrawFrameDefault((int)p,22,71);else BOX2_SEQ_DrawFrameDefault((int)p,22,69);BOX2_SEQ_AddBmpWinFrame(((struct Obj23970 *)(*(unsigned char * *)&((BoxTask *)p)->work))->f74,10,((struct Obj23971 *)(*(unsigned char * *)&((BoxTask *)p)->work))->f144);}

/*
 * Stage 0x17/0x46 then hand the 0x14C word over with index 0xb.
 */
void BOX2_SEQ_AddNameFrame(BoxTask *p)
{
    BOX2_SEQ_DrawFrameDefault((int)p, 0x17, 0x46);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr **)(*(int *)&p->work + 0x74), 0xb,
                  (void *)(*(int *)(*(int *)&p->work + 0x14C)));
}

void BOX2_SEQ_DrawBoxName(char **p, unsigned box, int i)
{
    void *s = STRBUF_Create(0x14, 0x804C);
    unsigned n;
    func_0200785C(((void **)p[0])[1], box, s);
    BMP_Clear(*(void **)(p[11] + i * 8 + 8), 0);
    n = func_0201D304(s, ((struct Obj23973 *)(p[11]))->f78, 0);
    n = (0x60 - n) / 2;
    PRINTSYS_PrintColor(*(void **)(p[11] + i * 8 + 8), n, 0, s, ((struct Obj23974 *)(p[11]))->f78, 0x440);
    STRBUF_Delete(s);
    BMP_OAM_UploadChars(*(void **)(p[11] + i * 8 + 4));
}























/*
 * Wrap the 0x19 counter and forward it with p.
 */
void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    BOX2_SEQ_DrawBoxName((char **)p, v, 0);
}

void BOX2_SEQ_DrawMonName(char **p, unsigned a, int i)
{
    void *s = func_02045EC0(((struct Obj23975 *)(p[11]))->f80, 0x1E);
    unsigned n = func_020078C4((void *)(((unsigned *)p[0])[1]), a);
    func_0201EFA4(((struct Obj23977 *)(p[11]))->f84, 0, n, 2, 0, 1);
    func_0201F250(((struct Obj23978 *)(p[11]))->f84, ((struct Obj23979 *)(p[11]))->f88, s);
    BMP_Clear(*(void **)(p[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        PRINTSYS_PrintColor(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23980 *)(p[11]))->f88, ((struct Obj23981 *)(p[11]))->f7C, 0x1480);
    else
        PRINTSYS_PrintColor(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23982 *)(p[11]))->f88, ((struct Obj23983 *)(p[11]))->f7C, 0x440);
    STRBUF_Delete(s);
    BMP_OAM_UploadChars(*(void **)(p[11] + i * 8 + 4));
}

/*
 * trailing: two-byte zero alignment padding at 0x021EB95A.
 */
void BOX2_SEQ_ChangeFramePalette(BoxTask *p)
{
    BOX2_SEQ_DrawFrameColor((int)p, 20, 84, 0);
    BOX2_SEQ_DrawFrameColor((int)p, 21, 85, 1);
    BGWINFRM_ChangePalette(*(struct WinMgr * *)&((struct Obj23984 *)(*(char * *)&p->work))->f74, 7, 0, 9, 11, 3, 12);
    BGWINFRM_ChangePalette(*(struct WinMgr * *)&((struct Obj23985 *)(*(char * *)&p->work))->f74, 7, 0, 12, 11, 3, 12);
}

void BOX2_SEQ_PutNameFrame(char *p){BGWINFRM_PutBmpWin((struct WinMgr *)(((struct Obj23986 *)(*(char * *)&((BoxTask *)p)->work))->f74),7,(void *)(((struct Obj23987 *)(*(char * *)&((BoxTask *)p)->work))->f134));BGWINFRM_PutBmpWin((struct WinMgr *)(((struct Obj23988 *)(*(char * *)&((BoxTask *)p)->work))->f74),7,(void *)(((struct Obj23989 *)(*(char * *)&((BoxTask *)p)->work))->f13C));BOX2_SEQ_ChangeFramePalette((BoxTask *)p);}

void BOX2_SEQ_DrawFrameList(BoxTask *p, const void *e, unsigned n)
{
    unsigned short w;
    unsigned short h;
    unsigned i = 0;
    BGWINFRM_GetSize((((BoxTask *)(p))->work->winMgr), 0, &w, &h);
    for (i = 0; i < n; i++) {
        const Ent *x = &((const Ent *)e)[n - 1 - i];
        if (x->b == 0)
            BOX2_SEQ_DrawFrameColor((int)p, 0x13 - i, x->a, 0);
        else
            BOX2_SEQ_DrawFrameColor((int)p, 0x13 - i, x->a, 1);
        BGWINFRM_ChangePalette((((BoxTask *)(p))->work->winMgr), 5 - i, 0, 0, w, h, 0xC);
    }
    for (; n < 6; n++) {
        unsigned k = 0x13 - n;
        BMP_Clear(BMP_WIN_GetBmp(*(void **)(((char *)((BoxTask *)(p))->work) + k * 8 + 0x94)), 0);
        BOX2_SEQ_SetDirtyBit((unsigned char *)((char *)((BoxTask *)(p))->work), k);
    }
}

/*
 * Clears a message window to colour 15 and draws its frame.
 */
void BOX2_SEQ_ClearMessageWindow(BoxTask *p, void *win)
{
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)win), 0xF);
    func_0201F73C(win, 2, (unsigned short)*(int *)(((char *)((BoxTask *)(p))->work) + 0x178), 10);
}

/*
 * Forward the i-th entry word with flag 1.
 */
void BOX2_SEQ_ShowWindowObject(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 1);
}

/*
 * Forward the i-th entry word with flag 0.
 */
void BOX2_SEQ_HideWindowObject(char *p, int i)
{
    func_0201F7A8(*(void **)(p + i * 8 + 0x94), 0);
}

/*
 * Prints message msg of the box-menu bank into message window i.
 */
void BOX2_SEQ_PrintMessageMsg(BoxTask *p, int msg, int i)
{
    void *bank = BOX2_SEQ_CreateMsgBank();
    BOX2_SEQ_ClearMessageWindow((BoxTask *)p, *(void **)(((char *)((BoxTask *)(p))->work) + i * 8 + 0x94));
    BOX2_SEQ_PrintTextWinEx(((char *)((BoxTask *)(p))->work), i, bank, msg, 0, 0, *(u32 *)(((char *)((BoxTask *)(p))->work) + 0x78), 0x44F);
    BOX2_SEQ_MakeScreen((void **)(((char *)((BoxTask *)(p))->work) + 0x94 + i * 8));
    MSGDATA_Delete(bank);
    BOX2_UI_HideSlots678(p);
}

/*
 * Sibling of BOX2_SEQ_PrintMessageC: index 0x34 when state is 5, else 0xb.
 */
void BOX2_SEQ_PrintMessageB(char *p, int b)
{
    if (*(int *)(((struct Obj18517 *)p)->f0 + 0x24) == 5)
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x34, b);
    else
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0xb, b);
}

/*
 * Puts item v into word slot 0 and prints message 0x15 into window i.
 */
void BOX2_SEQ_PrintWordset(BoxTask *p, u32 v, int i)
{
    WORDSET_Callback_EF40(*(void **)(((char *)((BoxTask *)(p))->work) + 0x84), 0, v);
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x15, i);
}

/*
 * Prints message 0x16 into window i.
 */
void BOX2_SEQ_PrintMessage(unsigned char *p, int i)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x16, i);
}

/*
 * Forward with index 43.
 */
void BOX2_SEQ_PrintMessageC(char *p, int b)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x2b, b);
}

/*
 * Stage 0x84 of the p+0x2c object with (0, arg1), then index 0xe
 *   with the third argument.
 */
void BOX2_SEQ_PrintWordsetB(char *p, int a, int b)
{
    WORDSET_Callback_EF40((struct WordSet *)(*(int *)(((struct Obj18518 *)p)->f2C + 0x84)), 0, a);
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0xe, b);
}

/*
 * Forward with index 13.
 */
void BOX2_SEQ_PrintMessageD(char *p, int b)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0xd, b);
}

void BOX2_SEQ_PrintWordsetBB64(BoxTask *p, unsigned v, int i)
{
    if (v == 0) {
        WORDSET_Callback_EF40(((struct Obj23990 *)(*(char * *)&p->work))->f84, 0, 0x70);
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x2c, i);
    } else if (FILE_UTIL_Check136C(v) == 1) {
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x30, i);
    } else {
        WORDSET_Callback_EF40(((struct Obj23991 *)(*(char * *)&p->work))->f84, 0, v);
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 15, i);
    }
}

/*
 * Forward with index 32.
 */
void BOX2_SEQ_PrintMessageE(char *p, int b)
{
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x20, b);
}

/*
 * The image leaves the message undefined for kinds above six.
 */
void BOX2_SEQ_PrintMonName(BoxTask *p, unsigned kind, int i)
{
    int msg;
    switch (kind) {
    case 0: msg = 2; break;
    case 1: msg = 3;
        func_0201EF14(((struct Obj23992 *)(*(char * *)&p->work))->f84, 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot));
        break;
    case 2: msg = 4;
        func_0201EF14(((struct Obj23993 *)(*(char * *)&p->work))->f84, 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot));
        break;
    case 3: msg = 0x1c; break;
    case 4: msg = 0x1d;
        func_0201EF14(((struct Obj23994 *)(*(char * *)&p->work))->f84, 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot));
        break;
    case 5: msg = 0x1e; break;
    case 6: msg = 6; break;
    }
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, msg, i);
}

void BOX2_SEQ_PrintIndexedMessage(unsigned char *p,int n,int i){switch(n){case 0:n=7;break;case 1:n=8;break;case 2:n=9;break;case 3:n=10;break;}BOX2_SEQ_PrintMessageMsg((BoxTask *)p,n,i);}

/*
 * Picks the prompt for a menu kind (kind 1 first names the Pokemon in the
 * current slot) and prints it into window i.  An out-of-range kind prints
 * whatever msg holds; the image does not initialise it.
 */
void BOX2_SEQ_PrintPrompt(BoxTask *p, int sel, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x10;
        break;
    case 1:
        msg = 0;
        func_0201EF14(*(void **)(((char *)((BoxTask *)(p))->work) + 0x84), 0, (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, p->cursorSlot));
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
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, msg, i);
}











/*
 * Item-menu prompt for a kind; kinds 1 to 3 name the held item first.  An
 * out-of-range kind prints whatever msg holds; the image does not initialise it.
 */
void BOX2_SEQ_PrintPromptB(BoxTask *p, int kind, int i)
{
    int msg;
    switch (kind) {
    case 0:
        msg = 0x1A;
        break;
    case 1:
        msg = 0x17;
        WORDSET_Callback_EF40(*(void **)(((char *)((BoxTask *)(p))->work) + 0x84), 0, *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C));
        break;
    case 2:
        msg = 0x18;
        WORDSET_Callback_EF40(*(void **)(((char *)((BoxTask *)(p))->work) + 0x84), 0, *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C));
        break;
    case 3:
        msg = 0x19;
        WORDSET_Callback_EF40(*(void **)(((char *)((BoxTask *)(p))->work) + 0x84), 0, *(unsigned short *)(((char *)((BoxTask *)(p))->work) + 0xA16C));
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
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, msg, i);
}

/*
 * Maps a menu row to its message index, then tail-calls the printer.
 */
void BOX2_SEQ_PrintMenuRow(char *p, int row, int b)
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
    BOX2_SEQ_PrintMessageMsg((BoxTask *)p, row, b);
}

void BOX2_SEQ_PrintBoxMonName(unsigned char *p){void *m=(void *)BOX2_MAIN_GetMonAt((void ***)p,p[20],p[22]);func_0201EF14((struct WordSet *)(((struct Obj23995 *)(*(unsigned char * *)&((BoxTask *)p)->work))->f84), 0, m);BOX2_SEQ_PrintMessageMsg((BoxTask *)p,50,27);}

/*
 * Index 0x35 when the flag is clear, 0x36 when set.
 */
void BOX2_SEQ_PrintYesNo(char *p, int b)
{
    if (b == 0)
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x35, 0x1b);
    else
        BOX2_SEQ_PrintMessageMsg((BoxTask *)p, 0x36, 0x1b);
}

/*
 * trailing: two-byte zero alignment padding at 0x021EBDD6.
 */
void BOX2_SEQ_CreateBox2UiScene(BoxTask *p)
{
    BOX2_SEQ_InitClact((char *)p->work);
    BOX2_SEQ_LoadBoxGraphics((char *)p->work);
    BOX2_SEQ_CreateBox2Actors((unsigned char *)p);
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, p->slot6Mode, p->slot7Mode, p->slot8Mode);
    BOX2_UI_CreateBmpOam((char *)p->work);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}

/*
 * Three teardown steps then the SDK pool release.
 */
void BOX2_SEQ_DeleteBox2UiScene(char *p)
{
    BOX2_UI_DeleteBmpOam((char *)p);
    BOX2_SEQ_DeleteAllActors((BoxWork *)p);
    BOX2_SEQ_ReleaseBoxGraphics((char *)p);
    CLACT_ExitSystem();
}

void BOX2_SEQ_InitClact(void *a0){Template t=d_021EFD64;unsigned n=BOX2_MAIN_GetDispVram();CLACT_InitSystem(&t,n,76);}

void BOX2_SEQ_LoadBoxGraphics(char *p){BOX2_SEQ_RegisterBoxChars((char *)p);BOX2_SEQ_RegisterBoxCharsB((BoxWork *)p);BOX2_SEQ_RegisterIconRes((BoxWork *)p);BOX2_SEQ_LoadIconPalette((u8 *)p);BOX2_SEQ_InitIconSlots((BoxWork *)p);BOX2_SEQ_LoadBoxScreen(p);}

void BOX2_SEQ_ReleaseBoxGraphics(char *p)
{
    unsigned i;
    for (i = 0; i < 0x45; i++)
        if (*(int *)(p + i * 4 + 0x9FF4) != -1)
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x9FF4));
    for (i = 0; i < 0xB; i++)
        if (*(int *)(p + i * 4 + 0xA108) != -1)
            CLACT_ReleasePalette(*(int *)(p + i * 4 + 0xA108));
    for (i = 0; i < 0xC; i++)
        if (*(int *)(p + i * 4 + 0xA134) != -1)
            CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0xA134));
}

void BOX2_SEQ_CreateBox2Actors(unsigned char *p){((struct Obj23996 *)(*(char * *)&((BoxTask *)p)->work))->f9E70=CLACT_CreateUnit(180,0,76);BOX2_UI_CreatePartyActors(*(char * *)&((BoxTask *)p)->work);BOX2_SEQ_CreateBoxSlotActors(*(char * *)&((BoxTask *)p)->work);BOX2_SEQ_CreateCursorObjects((BoxTask *)p);BOX2_SEQ_CreateHandSlotActors(*(char * *)&((BoxTask *)p)->work);}

void *BOX2_SEQ_CreateActorFromDesc(char *w, const Desc *s)
{
    void *r = CLACT_CreateActor(((struct Obj23997 *)w)->f9E70, (unsigned int)*(void **)(w + s->a * 4 + 0x9FF4),
                            (unsigned int)*(void **)(w + s->b * 4 + 0xA108), (unsigned int)*(void **)(w + s->c * 4 + 0xA134),
                            s, s->d, 0x4C);
    CLACT_SetActorVisible(r, 0);
    return r;
}

/*
 * Release slot i of the 0x9E74 array when non-null.
 *   CLOSES the register-order residue: `struct Slots_021EBF34 { char pad[0x9E74]; int arr[1]; }`
 *   with `p->arr[i]` gives the image's r4 = p+0x9E74 / r5 = i*4; a plain
 *   `char *p` plus `p + i * 4 + 0x9E74` puts the index in r1 and the constant
 *   in r5 instead.
 */
void BOX2_SEQ_DeleteActorSlot(struct Slots_021EBF34 *p, int i)
{
    if (p->arr[i] != 0) {
        CLACT_DeleteActor((struct Obj *)p->arr[i]);
        p->arr[i] = 0;
    }
}

/*
 * Release all 0x60 slots of the 0x9E70 pool, then release the pool
 *   head itself.
 */
void BOX2_SEQ_DeleteAllActors(BoxWork *p)
{
    unsigned i;
    for (i = 0; i < 0x60; i++)
        BOX2_SEQ_DeleteActorSlot((struct Slots_021EBF34 *)p, i);
    CLACT_DeleteUnit((struct Bank *)(p->clactUnit));
}

/*
 * Sweep 0x2d slots of the 0x9E74 array, restarting each live one.
 *   The element address must be a named `int *row = (int *)(p + i*4)`
 *   and the offset written as the WORD index row[0x279d]: that is what
 *   puts i in r4, the row in r5 and 0x9E74 in r7 (the flat spelling
 *   swaps r4/r5).
 */
void BOX2_SEQ_DrawActors(char *p)
{
    unsigned i;
    for (i = 0; i < 0x2d; i++) {
        int *row = (int *)(p + i * 4);
        if (row[0x279d] != 0 && CLACT_GetActorAutoAnim((struct Obj *)row[0x279d]) != 1)
            CLACT_AddActorAnimFrame((struct Obj *)row[0x279d], 0x1000);
    }
    CLACT_DrawSystem();
}

/*
 * Stop and re-issue slot i of the 0x9E74 array; the word is
 *   re-read for the second call.  Writing the array offset before the index
 *   term is what puts the pool constant in r2 and the index in r6.
 */
void BOX2_SEQ_SetActorAnimSeq(char *p, int i, int v)
{
    CLACT_SetActorAnimFrame((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), 0);
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned short)v);
}

/*
 * Release-and-flag slot i of the 0x9E74 array.
 */
void BOX2_SEQ_SetActorAutoAnim(char *p, int i, int v)
{
    BOX2_SEQ_SetActorAnimSeq((char *)p, i, v);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p + i * 4 + 0x9E74), 1);
}

/*
 * Forward the i-th word of the pooled table.
 */
u32 BOX2_SEQ_IsActorAnimActive(char *p, int i)
{
    return CLACT_IsActorAnimActive((struct Actor *)(*(int *)(p + i * 4 + 0x9E74)));
}

/*
 * Release slot i of the 0x9E74 array when it is non-null.
 */
void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v)
{
    int x = *(int *)(p + i * 4 + 0x9E74);
    if (x != 0)
        CLACT_SetActorDrawEnable((struct Obj *)x, v);
}

u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i)
{
    return CLACT_GetActorDrawEnable((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)));
}

/*
 * Tail call with the table word at the pooled offset.
 */
void BOX2_SEQ_SetActorBgPriority(char *p, int i, int c)
{
    CLACT_SetActorBgPriority(*(int *)(p + i * 4 + 0x9E74), (unsigned char)c);
}










void BOX2_SEQ_SetActorDrawPriority(char *p, int i, int c)
{
    CLACT_SetActorDrawPriority((struct Node *)(*(int *)(p + i * 4 + 0x9E74)), (unsigned char)c);
}

void BOX2_SEQ_SetActorObjMode(char *p,unsigned i,int b){if(b==1)CLACT_SetActorObjMode(*(void **)((unsigned)p+i*4+0x9e74),1);else CLACT_SetActorObjMode(*(void **)((unsigned)p+i*4+0x9e74),0);}

/*
 * Stage two shorts on the stack and hand the 0x9E74 array slot to the
 *   SDK call.  Two spellings (array and struct) both give the image's
 *   store order, because the index term is computed between the stores.
 */
void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c)
{
    unsigned short t[2];
    t[0] = a;
    t[1] = b;
    CLACT_AddActorSurfacePos((struct Obj *)(*(int *)(p + i * 4 + 0x9E74)), (const struct Vec2 *)t, c);
}

void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space)
{
    short t[2];
    CLACT_GetActorSurfacePos((struct Actor *)*(int *)(p + i * 4 + 0x9E74), (struct PtS *)t, space);
    *a = t[0];
    *b = t[1];
}

void BOX2_SEQ_RegisterBoxChars(char *p)
{
    void *h;
    unsigned i,j;
    h=func_020490F4(116,76);
    for(j=0;j<6;j++) (*(void **)((char *)(p+j*4) + (0xA0D8)))=(void *)CLACT_RegisterCharacter(h,71,1,0,76);
    (*(void **)((char *)(p) + (0xA11C)))=(void *)CLACT_RegisterPalette(h,72,0,0,76);
    (*(void **)((char *)(p) + (0xA148)))=(void *)CLACT_RegisterCellAnim(h,73,74,76);
    for(i=0;i<37;i++) (*(void **)((char *)(p+i*4) + (0x9FF4)))=(void *)CLACT_RegisterCharacter(h,75,1,0,76);
    (*(void **)((char *)(p) + (0xA0F0)))=(void *)CLACT_RegisterCharacter(h,67,1,0,76);
    (*(void **)((char *)(p) + (0xA120)))=(void *)CLACT_RegisterPalette(h,70,0,192,76);
    (*(void **)((char *)(p) + (0xA14C)))=(void *)CLACT_RegisterCellAnim(h,68,69,76);
    (*(void **)((char *)(p) + (0xA0F4)))=(void *)CLACT_RegisterCharacter(h,64,1,0,76);
    (*(void **)((char *)(p) + (0xA150)))=(void *)CLACT_RegisterCellAnim(h,65,66,76);
    (*(void **)((char *)(p) + (0xA090)))=(void *)CLACT_RegisterCharacter(h,76,1,0,76);
    (*(void **)((char *)(p) + (0xA140)))=(void *)CLACT_RegisterCellAnim(h,77,78,76);
    ARC_TOOL_DeleteHandle(h);
}

void BOX2_SEQ_RegisterBoxCharsB(BoxWork *p)
{
    void *h = func_020490F4(func_020275E4(), 0x4C);
    p->iconCellRes = (void *)CLACT_RegisterCharacter(h, func_02027618(), 0, 0, 0x4C);
    p->iconCharRes = (void *)CLACT_RegisterPalette(h, func_02027614(), 0, 0x100, 0x4C);
    p->iconObjects = (void *)CLACT_RegisterCellAnim(h, func_0202761C(2), func_02027620(2), 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

void BOX2_SEQ_RegisterIconRes(BoxWork *p)
{
    void *h = func_020490F4(7, 0x4C);
    p->iconAnimRes = (void *)CLACT_RegisterPaletteCompressed(h, func_0201BC3C(), 0, 0x60, 0x4C);
    p->iconPlttImage = (void *)CLACT_RegisterCellAnim(h, func_0201BC40(), func_0201BCB4(), 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

void BOX2_SEQ_CreateBoxSlotActors(char *p)
{
    Desc d;
    Desc base = d_021EFD04;
    unsigned i;
    for (i = 0; i < 0x25; i++) {
        d = base;
        d.x += (short)((i % 6) * 24);
        d.y += (short)((i / 6) * 24);
        d.b6 = 0x75 - i * 2;
        d.a = i;
        *(void **)(p + i * 4 + 0x9F40) = BOX2_SEQ_CreateActorFromDesc(p, (const Desc *)&d);
        *(unsigned char *)(p + i + 0x3DD2) = i + 0x33;
    }
}

/*
 * Forward with a resolved handle and the object table entry.
 */
void *BOX2_SEQ_LoadGraphicResource(char *p, void *b, void *c)
{
    return func_02049E74((void *)(((BoxWork *)p)->arcHandle), POKE_TOOL_GetGraphicIndex(b), 0, (u32)c, 0x4c);
}

void BOX2_SEQ_LoadMonIcon(char **p, int box)
{
    unsigned i;
    void *m;
    void *r;
    void *buf;
    for (i = 0; i < 0x1E; i++) {
        if (func_020079BC(((void **)p[0])[1], box, i, 0xA9, 0) == 0) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else if (((struct Obj24001 *)(p[0]))->f24 != 3 && ((unsigned char *)p)[0x14] == ((unsigned char *)p)[0x17]
                   && ((unsigned char *)p)[0x16] == i) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else {
            m = (void *)BOX2_MAIN_GetMonAt((void ***)p, box, i);
            r = BOX2_SEQ_LoadGraphicResource(p[11], m, &buf);
            MIi_CpuCopy32(((struct Obj24002 *)buf)->f14, p[11] + 0x1B4 + i * 0x200, 0x200);
            func_020307B0((void *)r);
            *(unsigned char *)(p[11] + i + 0x3DB4) = POKE_TOOL_GetIconPalette(m);
            *(int *)(p[11] + i * 4 + 0x3DF8) = 1;
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
void BOX2_SEQ_SetSlotIconPal(char *p, int a, int i, int b)
{
    int v = CLACT_GetActorCharacterIndex((u8 *)(*(int *)(p + 0x9E74 + i * 4)));
    CLACT_TransferCharacterPart(v, (void *)a, 0x200, 0, 0);
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p + 0x9E74 + i * 4)), (unsigned char)b, 1);
}

/*
 * Loads an icon resource for a, uploads it and frees the file.
 */
void BOX2_SEQ_LoadIconResource(BoxTask *p, void *a, int i)
{
    void *d;
    void *res = BOX2_SEQ_LoadGraphicResource(((char *)((BoxTask *)(p))->work), a, &d);
    BOX2_SEQ_SetSlotIconPal(((char *)((BoxTask *)(p))->work), ((struct Obj24003 *)d)->f14, i, POKE_TOOL_GetIconPalette(a));
    func_020307B0((void *)res);
}

/*
 * Hides window win, and when slot (box, pos) holds something shows its icon
 * there again.  The image narrows both the slot and the box to 16 bits
 * before BOX2_MAIN_GetPartyValueAt, so its box parameter is declared unsigned short here;
 * the callee body only forwards it and cannot show the width.
 */
void BOX2_SEQ_ShowSlotIcon(BoxTask *p, int box, int pos, int win)
{
    char *w = ((char *)((BoxTask *)(p))->work);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 0);
    if (BOX2_MAIN_GetPartyValueAt((void ***)p, pos, (unsigned short)box, 0xA9, 0)) {
        BOX2_SEQ_LoadIconResource((BoxTask *)p, (void *)BOX2_MAIN_GetMonAt((void ***)p, box, pos), win);
        BOX2_SEQ_SetActorDrawEnable((char *)w, win, 1);
    }
}

/*
 * Loop 0x1e entries forwarding (p[0x14], i, i+0x33).
 */
void BOX2_SEQ_ShowAllSlotIcons(BoxTask *p)
{
    unsigned i;
    for (i = 0; i < 0x1e; i++)
        BOX2_SEQ_ShowSlotIcon((BoxTask *)p, p->curBox, i, i + 0x33);
}

void BOX2_SEQ_ShowPartyIcons(BoxTask *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24004 *)(*(char * *)&p->params))->f8);
    unsigned i;
    for (i = 0; i < n; i++) {
        BOX2_SEQ_LoadIconResource((BoxTask *)p, POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(((struct Obj24005 *)(*(char * *)&p->params))->f8, i)),
                       *(unsigned char *)(*(char * *)&p->work + i + 0x3DF0));
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&p->work, *(unsigned char *)(*(char * *)&p->work + i + 0x3DF0), 0);
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

void BOX2_SEQ_HidePartialSlots(char **p, int flag)
{
    unsigned n = POKEPARTY_GetCount(((void **)p[0])[2]);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int k = *(unsigned char *)(p[11] + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(p[11], k, d_021EFD4C[i].x, d_021EFD4C[i].y, 0);
        BOX2_SEQ_SetSlotDrawPriority(p[11], i + 0x1E, 1);
        if (i < n && (flag == 0 || ((unsigned char *)p)[0x16] != i + 0x1E))
            BOX2_SEQ_SetActorDrawEnable(p[11], k, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(p[11], k, 0);
    }
}

/*
 * Lays out the six party-slot windows and shows the ones the party fills.
 * The window id is an int local: as unsigned char the load is scheduled after
 * the table address and 34 bytes move.
 */
void BOX2_SEQ_HideSlotsC61C(BoxTask *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24008 *)(*(char * *)&p->params))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(((char *)((BoxTask *)(p))->work) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), win, (short)(d_021EFD4C[i].x + 0x98), (short)d_021EFD4C[i].y, (short)0);
        BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 0);
    }
}

void BOX2_SEQ_HideSlotsC688(BoxTask *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24010 *)(*(char * *)&p->params))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(((char *)((BoxTask *)(p))->work) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), win, (short)d_021EFD4C[i].x, (short)(d_021EFD4C[i].y - 0x90), (short)0);
        BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 0);
    }
}

void BOX2_SEQ_HideSlotsC6F4(BoxTask *p)
{
    unsigned n = POKEPARTY_GetCount(((struct Obj24012 *)(*(char * *)&p->params))->f8);
    unsigned i;
    for (i = 0; i < 6; i++) {
        int win = *(unsigned char *)(((char *)((BoxTask *)(p))->work) + i + 0x3DF0);
        BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), win, (short)(d_021EFD4C[i].x + 0x98), (short)(d_021EFD4C[i].y - 0x90), (short)0);
        BOX2_SEQ_SetSlotDrawPriority(((char *)((BoxTask *)(p))->work), i + 0x1E, 1);
        if (i < n)
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 1);
        else
            BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), win, 0);
    }
}









void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        BOX2_SEQ_SetActorBgPriority((char *)p, c, 0);
        BOX2_SEQ_SetActorDrawPriority((char *)p, c, 0x14);
        return;
    }
    if (i < 0x1E || i == 0x24)
        BOX2_SEQ_SetActorBgPriority((char *)p, c, 3);
    else
        BOX2_SEQ_SetActorBgPriority((char *)p, c, 1);
    BOX2_SEQ_SetActorDrawPriority((char *)p, c, 0x75 - i * 2);
}

void BOX2_SEQ_SetSlotDrawPriorityB(char *p, int i, unsigned j, int flag)
{
    unsigned char c = *(unsigned char *)(p + i + 0x3DD2);
    if (flag == 0) {
        BOX2_SEQ_SetActorBgPriority((char *)p, c, 0);
        BOX2_SEQ_SetActorDrawPriority((char *)p, c, 0x14);
        return;
    }
    if (j < 0x1E)
        BOX2_SEQ_SetActorBgPriority((char *)p, c, 3);
    else
        BOX2_SEQ_SetActorBgPriority((char *)p, c, 1);
    BOX2_SEQ_SetActorDrawPriority((char *)p, c, 0x75 - j * 2);
}

void BOX2_SEQ_ShiftSlotIcons(char **p, short dx)
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
        k = *(unsigned char *)(p[11] + i + 0x3DD2);
        BOX2_SEQ_GetActorSurfacePos(p[11], k, &t[1], &t[0], 0);
        t[1] += dx;
        if (t[1] == lim) {
            t[1] = reset;
            BOX2_SEQ_SetSlotIconPal(p[11], (int)(p[11] + 0x1B4 + i * 0x200), k, *(unsigned char *)(p[11] + i + 0x3DB4));
            BOX2_SEQ_SetActorDrawEnable(p[11], k, *(int *)(p[11] + i * 4 + 0x3DF8));
            if (((struct Obj24013 *)(p[11]))->fA17A == 0 && (((struct Obj24014 *)(p[0]))->f24 == 3 || ((struct Obj24015 *)(p[0]))->f24 == 5))
                BOX2_SEQ_SetActorMode1((char *)p, i);
        }
        BOX2_SEQ_AddActorSurfacePos(p[11], k, t[1], t[0], 0);
    }
}

void BOX2_SEQ_MoveActorToWindow(BoxTask *p)
{
    signed char buf[2];
    unsigned short i;
    short x, y;
    BGWINFRM_GetPos(*(struct WinMgr * *)&((struct Obj24016 *)(*(char * *)&p->work))->f74, 8, &buf[1], &buf[0]);
    x = buf[0] * 8;
    y = buf[1] * 8;
    for (i = 0; i < 6; i++)
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&p->work, *(unsigned char *)(*(char * *)&p->work + i + 0x3DF0),
                      (short)(y + d_021EFCE0[i].a), (short)(x + d_021EFCE0[i].b), (short)0);
}

void BOX2_SEQ_ResetActorAffine(char *p)
{
    int pair[2];
    unsigned short shape[2];
    *(float *)(p + 8) = 4096.0f;
    p[7] = 0;
    CLACT_SetActorAffineMode(*(void **)p, 1);
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(*(void **)p, (struct Pair *)pair);
    shape[0] = 0;
    shape[1] = 8;
    CLACT_SetActorAffineOrigin(*(void **)p, (const struct Pt *)shape);
}

int BOX2_SEQ_ShrinkActor(char *p)
{
    int pair[2];
    (((struct Obj05439 *)p)->f7)++;
    *(float *)(p + 8) -= 102.0f;
    if ((unsigned char)p[7] == 40)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(*(void **)p, (struct Pair *)pair);
    return 1;
}

int BOX2_SEQ_GrowActor(char *p)
{
    int pair[2];
    ((struct Obj04547 *)p)->f7 -= 2;
    *(float *)(p + 8) += 102.0f;
    *(float *)(p + 8) += 102.0f;
    if ((unsigned char)p[7] == 0)
        return 0;
    pair[0] = (int)*(float *)(p + 8);
    pair[1] = (int)*(float *)(p + 8);
    CLACT_SetActorScale(*(void **)p, (struct Pair *)pair);
    return 1;
}

/*
 * Zero*p through the pool, then run the sibling teardown.
 */
void BOX2_SEQ_HideActor(int *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)*p, 0);
    BOX2_SEQ_ResetActorTransform((int *)p);
}

/*
 * Program the two 0x1000 spans of the frame handle and zero its head.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * CLACT_SetActorScale.c, shard pkt_0204B5AC), so the call at +0022 attests as
 * `matched`.  Every concrete byte matches; the extent ran long because the
 * follower has no func_ label.
 */
void BOX2_SEQ_ResetActorTransform(int *p)
{
    struct { unsigned short a[2]; int b[2]; } s;
    s.a[0] = 0;
    s.a[1] = 0;
    CLACT_SetActorAffineOrigin((struct Actor *)(*p), (const struct Pt *)s.a);
    s.b[0] = 0x1000;
    s.b[1] = 0x1000;
    CLACT_SetActorScale((struct Obj *)(*p), (struct Pair *)s.b);
    CLACT_SetActorAffineMode((struct Actor *)(*p), 0);
}

void BOX2_SEQ_SetSlotActorsMode(BoxTask *p, int flag, int i, unsigned end, int mode)
{
    if (mode == 1) {
        if (((struct Obj24017 *)(*(char * *)&p->params))->f24 == 5) {
            for (; i < end; i++) {
                if (BOX2_MAIN_GetBoxValue((char *)p, i) == 1 && BOX2_MAIN_GetPartyValueAt((void ***)p, i, p->curBox, 0x4C, 0) == 0)
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->cursorTable[i]), 0);
                else
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->cursorTable[i]), 1);
            }
        } else {
            for (; i < end; i++) {
                if (BOX2_MAIN_GetPartyValueAt((void ***)p, i, p->curBox, 6, 0) == 0)
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->cursorTable[i]), 1);
                else
                    BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->cursorTable[i]), 0);
            }
        }
    } else {
        for (; i < end; i++)
            BOX2_SEQ_SetActorObjMode(((char *)((BoxTask *)(p))->work), (((BoxTask *)(p))->work->cursorTable[i]), flag);
    }
}

/*
 * Dispatch flag bits 1 and 2 to the two range halves, with bit
 *   0x80 selecting the sub-range selector.  Matches on the tst-based ternary.
 */
void BOX2_SEQ_SetSlotActors(char *p, int f, int c)
{
    int t = (f & 0x80) ? 1 : 0;
    if (f & 1)
        BOX2_SEQ_SetSlotActorsMode((BoxTask *)p, c, 0, 0x1e, t);
    if (f & 2)
        BOX2_SEQ_SetSlotActorsMode((BoxTask *)p, c, 0x1e, 0x25, t);
}

/*
 * Forward the byte at the pooled table offset.  The callee takes three
 * arguments, so the forwarded byte is argument 1 and the passing flag
 * stays in r2 untouched; that is what forces the sum into r3.
 */
void BOX2_SEQ_SetSlotActorMode(char *p, int i, int f)
{
    BOX2_SEQ_SetActorObjMode((char *)p, *(unsigned char *)(p + i + 0x3DD2), f);
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

void BOX2_SEQ_SwapSlotActorsB(unsigned char *p, int i)
{
    short xy[2];
    unsigned char t;
    BOX2_SEQ_GetActorSurfacePos((char *)p, p[0x3DF6], &xy[1], &xy[0], 0);
    t = (p + 0x3DD2)[i];
    (p + 0x3DD2)[i] = p[0x3DF6];
    p[0x3DF6] = t;
    BOX2_SEQ_AddActorSurfacePos((char *)p, p[0x3DF6], xy[1], xy[0], 0);
}







void BOX2_SEQ_RefreshHandSlot(BoxTask *p)
{
    short xy[2];
    int k;
    if (p->handMode == 0)
        return;
    BOX2_SEQ_GetActorSurfacePos(((char *)((BoxTask *)(p))->work), 4, &xy[1], &xy[0], 0);
    if ((*(Top * *)&p->params)->x24 == 3) {
        k = 0xA;
        xy[0] += 8;
    } else {
        k = *(unsigned char *)(((char *)((BoxTask *)(p))->work) + 0x3DF6);
        xy[0] += 4;
    }
    BOX2_SEQ_AddActorSurfacePos(((char *)((BoxTask *)(p))->work), k, xy[1], xy[0], 0);
    if ((*(Top * *)&p->params)->x24 == 3) {
        BOX2_SEQ_LayoutHandSlots(((char *)((BoxTask *)(p))->work));
        return;
    }
    if (*(void **)(((char *)((BoxTask *)(p))->work) + 0x9FD4) == 0)
        BOX2_SEQ_RefreshCursorSlot(p);
    BOX2_SEQ_MoveCursorToSlot(((char *)((BoxTask *)(p))->work), 0x24);
}

/*
 * candidate BOX2_SEQ_InitIconSlots: clear six ints
 */
void BOX2_SEQ_InitIconSlots(BoxWork *p)
{
    p->iconChar[0] = -1;
    p->iconCell[0] = -1;
    p->iconAnim[0] = -1;
    p->iconChar[1] = -1;
    p->iconCell[1] = -1;
    p->iconAnim[1] = -1;
}

/*
 * prototype: 0202D7C8 reads and forwards only r0; legacy r1-r3 omitted.
 * prototype: 0202D8D0 stack mode is full-width in this caller, with no
 * truncation; its callee forwards the same low-halfword value.
 */
void BOX2_SEQ_LoadMonIconActor(char *p,void **mon,int index)
{
    int *bmp,*cell,*anim;
    int other;
    int mode;
    int archive,state;
    if (*(u16 *)(((char *)((BoxTask *)(p))->work)+0xA164)==0) {
        bmp=(int *)(((char *)((BoxTask *)(p))->work)+0xA088);cell=(int *)(((char *)((BoxTask *)(p))->work)+0xA10C);
        anim=(int *)(((char *)((BoxTask *)(p))->work)+0xA138);mode=96;other=index+1;
    } else {
        bmp=(int *)(((char *)((BoxTask *)(p))->work)+0xA08C);cell=(int *)(((char *)((BoxTask *)(p))->work)+0xA110);
        anim=(int *)(((char *)((BoxTask *)(p))->work)+0xA13C);mode=128;other=index;index++;
    }
    if (*(void **)((((char *)((BoxTask *)(p))->work)+index*4)+0x9E74)) {
        CLACT_DeleteActor(*(void **)((((char *)((BoxTask *)(p))->work)+index*4)+0x9E74));
        CLACT_ReleaseCharacter(*bmp);CLACT_ReleasePalette(*cell);CLACT_ReleaseCellAnim(*anim);
    }
    archive=POKEGRA_OpenHandle(76);
    state=func_02017DBC(*mon);
    *bmp=POKEGRA_RegisterCgrPP(archive,*mon,0,1,76);
    *cell=POKEGRA_RegisterPalettePP(archive,*mon,0,1,mode,76);
    *anim=POKEGRA_RegisterCellAnimPP((u32)*mon,0,2,1,76);
    func_02017DE4(*mon,state);ARC_TOOL_DeleteHandle((void *)archive);
    *(void **)((((char *)((BoxTask *)(p))->work)+index*4)+0x9E74)=BOX2_SEQ_CreateActorFromDesc(((char *)((BoxTask *)(p))->work), &((const Desc *)&d_021EFD80)[(u32)index]);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work),index,1);
    if (*(void **)((((char *)((BoxTask *)(p))->work)+other*4)+0x9E74)) BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work),other,0);
    *(u16 *)(((char *)((BoxTask *)(p))->work)+0xA164)^=1;
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

    h = func_020490F4(func_020275E4(), 0x804C);
    for (i = 0; i < 0x11; i++)
        *(void **)(w + i * 4 + 0xA094) = (void *)CLACT_RegisterCharacter(h, func_020275F8((unsigned char)i), (int)0, (int)1, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA144))) = (void *)CLACT_RegisterCellAnim(h, func_020275FC(2), func_02027600(2), 0x4C);
    (*(void **)((char *)(w) + (0xA118))) = (void *)CLACT_RegisterPalette(h, func_020275E8(), 1, 0, 0x4C);
    (*(void **)((char *)(w) + (0xA100))) = (void *)CLACT_RegisterCharacter(h, func_0202774C(2), (int)0, (int)1, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA15C))) = (void *)CLACT_RegisterCellAnim(h, func_02027750(2), func_02027754(2), 0x4C);
    (*(void **)((char *)(w) + (0xA12C))) = (void *)CLACT_RegisterPalette(h, func_02027748(), 1, 0xA0, 0x4C);
    (*(void **)((char *)(w) + (0xA104))) = (void *)CLACT_RegisterCharacter(h, func_0202776C(2), (int)0, (int)1, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA160))) = (void *)CLACT_RegisterCellAnim(h, func_02027770(2), func_02027774(2), 0x4C);
    (*(void **)((char *)(w) + (0xA130))) = (void *)CLACT_RegisterPalette(h, func_02027768(), 1, 0xC0, 0x4C);
    (*(void **)((char *)(w) + (0xA0FC))) = (void *)CLACT_RegisterCharacter(h, func_0202774C(2), (int)0, (int)0, (unsigned)0x4C);
    (*(void **)((char *)(w) + (0xA158))) = (void *)CLACT_RegisterCellAnim(h, func_02027750(2), func_02027754(2), 0x4C);
    (*(void **)((char *)(w) + (0xA128))) = (void *)CLACT_RegisterPalette(h, func_02027748(), 0, 0x1A0, 0x4C);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Verified scratch-only with one --thumb, no --region: EXACT, 12 bytes.
 * symbols for blocker: _PokeTypePltOffset 0x0209FCF8 data a1
 * extern const unsigned char _PokeTypePltOffset[];
 * unsigned func_020275EC(unsigned char i) { return _PokeTypePltOffset[i]; }
 */
void BOX2_SEQ_CreateHandSlotActors(char *p)
{
    Desc d = d_021EFD34;
    unsigned i;
    for (i = 0; i < 0x11; i++) {
        d.a = i + 0x28;
        *(void **)(p + i * 4 + 0x9EE4) = BOX2_SEQ_CreateActorFromDesc(p, (const Desc *)&d);
        CLACT_SetActorPaletteOffset(*(void **)(p + i * 4 + 0x9EE4), (unsigned)func_020275EC((unsigned char)i), 1);
        BOX2_SEQ_SetActorDrawEnable((char *)p, i + 0x1C, 0);
    }
}




void BOX2_SEQ_ShowHandSlot(char *p, int a, int b)
{
    int k = a + 0x1c;
    BOX2_SEQ_SetActorDrawEnable((char *)p, k, 1);
    BOX2_SEQ_AddActorSurfacePos((char *)p, k, 0x58, 0x38, 1);
    if (b != 0 && a != b) {
        k = b + 0x1c;
        BOX2_SEQ_SetActorDrawEnable((char *)p, k, 1);
        BOX2_SEQ_AddActorSurfacePos((char *)p, k, 0x7a, 0x38, 1);
    }
}

/*
 * lever: Byte bitfield access reproduces the original ldrb/lsl24/lsr31
 * at 0x021ED042..0x021ED046; a mask test emitted movs/tst instead.
 */
void BOX2_SEQ_ShowHandSlotB(char *p,unsigned char *q){unsigned i;for(i=28;i<45;i++)BOX2_SEQ_SetActorDrawEnable((char *)p,i,0);if(!((Flag *)(q+18))->high)BOX2_SEQ_ShowHandSlot((char *)p,q[12],q[13]);}

void BOX2_SEQ_LoadIconPalette(u8*p){void*h;h=func_020490F4(25,76);*(void* *)&((BoxWork *)p)->iconPlttRes=(void *)CLACT_RegisterPalette(h,FILE_UTIL_Get(0,2),0,0x180,76);ARC_TOOL_DeleteHandle(h);}

void BOX2_SEQ_SetSlotCharacter(char *w, unsigned item)
{
    void *a;
    void *b;
    void *q;
    q = func_02049E34(func_02020F08(), FILE_UTIL_Get(item, 1), 0, (u32)(&a), 0x4C);
    CLACT_TransferCharacter(CLACT_GetActorCharacterIndex(((struct Obj14276 *)w)->f9E9C), a);
    func_020307B0((void *)q);
    q = func_02049F34(func_02020F08(), FILE_UTIL_Get(item, 2), (u32)(&b), 0x4C);
    CLACT_TransferPalette((void *)CLACT_GetActorPaletteIndex(((struct Obj14276 *)w)->f9E9C), b, 1);
    func_020307B0((void *)q);
}

void BOX2_SEQ_SetActorAffineMode(char *p, int on)
{
    unsigned short s[2];
    if (on == 1) {
        CLACT_SetActorAffineMode((struct Actor *)(((BoxWork *)(p))->cursorActor), 1);
        s[0] = 0xC;
        s[1] = 0xC;
        CLACT_SetActorAffineOrigin((struct Actor *)(((BoxWork *)(p))->cursorActor), (const struct Pt *)s);
    } else {
        s[0] = 0;
        s[1] = 0;
        CLACT_SetActorAffineOrigin((struct Actor *)(((BoxWork *)(p))->cursorActor), (const struct Pt *)s);
        CLACT_SetActorAffineMode((struct Actor *)(((BoxWork *)(p))->cursorActor), 0);
    }
}

/*
 * One range call with the sub-range selector.
 */
void BOX2_SEQ_MoveActor(int a, int b, int c)
{
    BOX2_SEQ_AddActorSurfacePos((char *)a, 10, b, c, 0);
}

/*
 * Twin of BOX2_SEQ_MoveActorToSlotB with both shorts biased by 8.
 */
void BOX2_SEQ_MoveActorToSlot(char *p, int a, int c)
{
    short t[2];
    BOX2_SEQ_GetSlotPos(a, t + 1, t, c);
    BOX2_SEQ_MoveActor((int)p, (short)(t[1] + 8), (short)(t[0] + 8));
}

/*
 * Read the 2-short record for the sub-range then push it back with
 *   the first element biased by 4.
 */
void BOX2_SEQ_MoveActorToSlotB(char *p, int a, int c)
{
    short t[2];
    BOX2_SEQ_GetSlotPos(a, t + 1, t, c);
    BOX2_SEQ_MoveActor((int)p, t[1], (short)(t[0] + 4));
}

static inline void setup(Desc *dp, void **res)
{
    dp->b6 = CLACT_GetActorDrawPriority((int)(*res)) + 1;
    dp->b7 = CLACT_GetActorBgPriority(*res);
}

/*
 * Sibling of src/matched/ov/ov170_func_021ED594.c: builds (or moves) the
 * eight frame pieces around window 10 while the count at 0xA16C is nonzero.
 * The index is an int compared against 8u (docs/idioms/a-signed-index-under-an-unsigned-bound-keeps-the-window-sum-uncached.md).
 */
void BOX2_SEQ_CreateHandSlotActorsB(char *w)
{
    int j;
    Desc d;
    short xy[2];
    if (((struct Obj08247 *)w)->fA16C == 0)
        return;
    j = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)w, 10, &xy[1], &xy[0], 0);
    if (((struct Obj08247 *)w)->f9FD4 == 0) {
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
        int n6 = CLACT_GetActorDrawPriority((int)(((struct Obj08247 *)w)->f9E9C));
        int n7 = CLACT_GetActorBgPriority(((struct Obj08247 *)w)->f9E9C);
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
void BOX2_SEQ_ShowHandSlots(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        BOX2_SEQ_SetActorDrawEnable((char *)p, i + 0x58, 1);
}

void BOX2_SEQ_LayoutHandSlots(char *w)
{
    short xy[2];
    unsigned i;
    if (((struct Obj24020 *)w)->f9FD4 != 0) {
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
void BOX2_SEQ_CreateCursorObjects(BoxTask *p)
{
    char *w = ((char *)((BoxTask *)(p))->work);
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
        *(void **)(w + i * 4 + 0x9EA8) = BOX2_SEQ_CreateActorFromDesc(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x138)));
        *(void **)(w + i * 4 + 0x9EC0) = BOX2_SEQ_CreateActorFromDesc(w, (const Desc *)((const char *)&d_021EFD80 + (i * 0x18 + 0x1C8)));
    }
    (((BoxWork *)(w))->actors[25]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[0]);
    (((BoxWork *)(w))->actors[26]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[1]);
    (((BoxWork *)(w))->actors[27]) = BOX2_SEQ_CreateActorFromDesc(w, &d_021EFD80.d[2]);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 5, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 10, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 0x19, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 0x1A, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)w, 0x1B, 0);
    BOX2_SEQ_SetWindow9((BoxTask *)p, 0xE, 1);
}

/*
 * Sets window 9's frame and mode; outside modes 2, 3 and 4 the mode is
 * cleared again.
 */
void BOX2_SEQ_SetWindow9(BoxTask *p, int a, int b)
{
    int kind;
    BOX2_SEQ_SetActorAnimSeq(((char *)((BoxTask *)(p))->work), 9, a);
    BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 9, b);
    kind = ((struct Obj24021 *)(*(char * *)&p->params))->f24;
    if (kind != 2 && kind != 4 && kind != 3)
        BOX2_SEQ_SetActorDrawEnable(((char *)((BoxTask *)(p))->work), 9, 0);
}

/*
 * Offset by four when the low nibble of 0x1c is set.
 */
void BOX2_SEQ_SetCursorFrame(BoxTask *p, int b)
{
    if (((struct Slot *)p)->f)
        b += 4;
    BOX2_SEQ_SetActorAnimSeq(*(char * *)&p->work, 4, b);
}

void BOX2_SEQ_SetCursorDraw(char **p, int flag)
{
    if (flag == 1) {
        if (CURSOR_MOVE_GetState(((struct Obj24022 *)(p[11]))->f70) == 1)
            BOX2_SEQ_SetActorDrawEnable(p[11], 4, 1);
    } else {
        BOX2_SEQ_SetActorDrawEnable(p[11], 4, 0);
    }
}

/*
 * Forward with the byte field at +0x16.
 */
void BOX2_SEQ_RefreshCursorSlot(BoxTask *p)
{
    BOX2_SEQ_MoveCursorActor((BoxTask *)p, p->cursorSlot);
}

void BOX2_SEQ_MoveCursorActor(BoxTask *p, unsigned i)
{
    char *w;
    unsigned c;
    unsigned short j;
    Desc d;
    Struct36 buf;
    short xy[2];
    if (i == 0xFF)
        return;
    w = *(char * *)&p->work;
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
        CLACT_GetActorImageProxy(((void **)(w + 0x9E74))[c], (struct Struct36 *)(&buf));
        n6 = CLACT_GetActorDrawPriority((int)(((void **)(w + 0x9E74))[c]));
        n7 = CLACT_GetActorBgPriority(((void **)(w + 0x9E74))[c]);
        for (; j < 8; j++) {
            CLACT_SetActorImageProxy(*(void **)(w + j * 4 + 0x9FD4), (const struct Struct36 *)(&buf));
            BOX2_SEQ_AddActorSurfacePos((char *)w, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
            BOX2_SEQ_SetActorDrawPriority((char *)w, j + 0x58, n6 + 1);
            BOX2_SEQ_SetActorBgPriority((char *)w, j + 0x58, n7);
            BOX2_SEQ_SetActorDrawEnable((char *)w, j + 0x58, 1);
        }
    }
}

void BOX2_SEQ_SetSlotDim(char **p, int v)
{
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0) {
            BOX2_SEQ_SetActorDrawEnable(p[11], j + 0x58, v);
            if (v == 1 && ((unsigned char *)p)[0x16] != 0xFF) {
                unsigned char k = *(unsigned char *)(p[11] + ((unsigned char *)p)[0x16] + 0x3DD2);
                BOX2_SEQ_SetActorDrawPriority(p[11], j + 0x58, CLACT_GetActorDrawPriority(*(int *)(p[11] + k * 4 + 0x9E74)) + 1);
                BOX2_SEQ_SetActorBgPriority(p[11], j + 0x58, CLACT_GetActorBgPriority((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74))));
            }
        }
    }
}

void BOX2_SEQ_SetSlotDimB(char **p, int i)
{
    unsigned char k = *(unsigned char *)(p[11] + i + 0x3DD2);
    int a = CLACT_GetActorDrawPriority(*(int *)(p[11] + k * 4 + 0x9E74));
    int b = CLACT_GetActorBgPriority((u8 *)(*(int *)(p[11] + k * 4 + 0x9E74)));
    int j;
    for (j = 0; j < 8u; j++) {
        if (*(int *)(p[11] + j * 4 + 0x9FD4) != 0 && ((unsigned char *)p)[0x16] != 0xFF) {
            BOX2_SEQ_SetActorDrawPriority(p[11], j + 0x58, a + 1);
            BOX2_SEQ_SetActorBgPriority(p[11], j + 0x58, b);
        }
    }
}

void BOX2_SEQ_MoveCursorToSlot(char *p, int i)
{
    short xy[2];
    int j;
    if (i == 0xFF)
        return;
    j = 0;
    BOX2_SEQ_GetActorSurfacePos((char *)p, *(unsigned char *)(p + i + 0x3DD2), &xy[1], &xy[0], j);
    for (; j < 8u; j++)
        BOX2_SEQ_AddActorSurfacePos((char *)p, j + 0x58, (short)(xy[1] + d_021EFCD0[j]), (short)(xy[0] + d_021EFCC8[j]), (short)0);
}
