/*
 * file:     box2_main.c
 * unit:     yes
 * function: BOX2_MAIN_Init, BOX2_MAIN_Main, BOX2_MAIN_Exit, BOX2_MAIN_CreateVBlankTask, BOX2_MAIN_DeleteVBlankTask, BOX2_MAIN_VBlankHandler, BOX2_MAIN_InitSeq, BOX2_MAIN_SetSeqParam, BOX2_MAIN_RestartSeq, BOX2_MAIN_ResetGraphics, BOX2_MAIN_GetDispVram, BOX2_MAIN_InitBgSys, BOX2_MAIN_DeleteBgSys, BOX2_MAIN_LoadBgData, BOX2_MAIN_CreatePalAnm, BOX2_MAIN_DeletePalAnm, BOX2_MAIN_SetDisplayControl, BOX2_MAIN_CreateTextSystem, BOX2_MAIN_DeleteTextSystem, BOX2_MAIN_CreateTaskMenu, BOX2_MAIN_DeleteTaskMenu, BOX2_MAIN_OpenTaskMenu, BOX2_MAIN_StepWindowFrameFade, BOX2_MAIN_SetupWindowFrameFade, BOX2_MAIN_RefreshCursorBox, BOX2_MAIN_StepToAdjacentBox, BOX2_MAIN_SelectBox, BOX2_MAIN_RefreshBoxUi, BOX2_MAIN_IsWrappedDistance, BOX2_MAIN_ActivateKeyCursor, BOX2_MAIN_GetPartyValueAt, BOX2_MAIN_SetBoxValueAt, BOX2_MAIN_GetMonAt, BOX2_MAIN_ClearSlot, BOX2_MAIN_SwapBoxAndPartyMon, BOX2_MAIN_AddMonToParty, BOX2_MAIN_DepositPartyMon, BOX2_MAIN_SwapPartyMembers, BOX2_MAIN_ShiftMemberToEnd, BOX2_MAIN_MoveMonToListedBox, BOX2_MAIN_MovePartyMonToListedBox, BOX2_MAIN_UpdateBoxSlots, BOX2_MAIN_WrapSlot, BOX2_MAIN_HasOtherTradable, BOX2_MAIN_ChangeFormAndRegister, BOX2_MAIN_SyncItemForm, BOX2_MAIN_ResetShayminFormInBox, BOX2_MAIN_RecalcPartyParam, BOX2_MAIN_LoadFormTable, BOX2_MAIN_DeleteFormTable, BOX2_MAIN_GetBoxValue, BOX2_MAIN_WaitCursorMove, BOX2_MAIN_WaitBoxScroll, BOX2_MAIN_HandleMonPickup, BOX2_MAIN_ComparePartyValue, BOX2_MAIN_CompareSlots, BOX2_MAIN_AdvanceMover, BOX2_MAIN_UpdateMoverX, BOX2_MAIN_UpdateMoverY, BOX2_MAIN_StepMover, BOX2_MAIN_MoveCursorWithMon, BOX2_MAIN_SwapWithNeighbour, BOX2_MAIN_SetMoverTarget, BOX2_MAIN_FindMoverSlot, BOX2_MAIN_StartMover, BOX2_MAIN_SetMoverEntry, BOX2_MAIN_GetMinusOne, BOX2_MAIN_ResetMovers, BOX2_MAIN_DeleteScroll, BOX2_MAIN_StepScroll, BOX2_MAIN_ClearPerapVoiceIfNoChatot, BOX2_MAIN_StartHandMotionToSlot, BOX2_MAIN_StartHandMotionToBoxArrow, BOX2_MAIN_StartHandMotionToBoxSlot, BOX2_MAIN_StartHandMotionToTargetBoxSlot, BOX2_MAIN_StepHandMotion, BOX2_MAIN_StepHandMotionToSlot, BOX2_MAIN_StepHandMotionToSlotB, BOX2_MAIN_WrapOffset, BOX2_MAIN_LoadBgCharTile, BOX2_MAIN_LoadBgPaletteTile, BOX2_MAIN_LoadBgTileSet, BOX2_MAIN_LoadBgTiles, BOX2_MAIN_SetBoxScroll, BOX2_MAIN_LoadBoxPalette, BOX2_MAIN_GetBoxWallpaper, BOX2_MAIN_CreateSummary, BOX2_MAIN_DeleteHandle, BOX2_MAIN_SetupSummary, BOX2_MAIN_RefreshMonInfo, BOX2_MAIN_RefreshCurrentBoxMonInfo, BOX2_MAIN_SetBoxForm, BOX2_MAIN_ResetBoxView, BOX2_MAIN_ClearCursorBox, BOX2_MAIN_SetSceneSlots, BOX2_MAIN_SetHandSlots, BOX2_MAIN_SetBodySlots, BOX2_MAIN_HideSlots, BOX2_MAIN_SetupSummaryActors, BOX2_MAIN_HitRect, BOX2_MAIN_HitBoxGrid, BOX2_MAIN_HitPartySlots, BOX2_MAIN_HitPartyGrid, BOX2_MAIN_PushPartyScene, BOX2_MAIN_PushPartySceneB, BOX2_MAIN_PushBagScene, BOX2_MAIN_PopSubArgs, BOX2_MAIN_PushNameScene, BOX2_MAIN_PopNameScene, BOX2_MAIN_MoveCursorActor, BOX2_MAIN_StateMachinePick, BOX2_MAIN_StateMachineScroll, BOX2_MAIN_StateMachineOpen, BOX2_MAIN_StateMachineClose, BOX2_MAIN_StepScrollToPrevBox, BOX2_MAIN_StepScrollToNextBox, BOX2_MAIN_IsWindowMoving, BOX2_MAIN_UpdateWindowMove, BOX2_MAIN_IsWindowBusy, BOX2_MAIN_ShiftWindowRight, BOX2_MAIN_ShiftWindowLeft, BOX2_MAIN_StateMachineMove, BOX2_MAIN_StateMachinePen, BOX2_MAIN_SceneApplyScroll, BOX2_MAIN_SceneWaitScroll, BOX2_MAIN_SceneMoveCursor, BOX2_MAIN_SceneWaitCursor, BOX2_MAIN_SceneOpenBox, BOX2_MAIN_StateMachineRunSwap, BOX2_MAIN_StateMachineShowHandScroll, BOX2_MAIN_StateMachineDrag, BOX2_MAIN_StateMachineHideHandScroll, BOX2_MAIN_StateMachineHideHandWindow, BOX2_MAIN_StateMachineHideHand, BOX2_MAIN_MoveCursorTo, BOX2_MAIN_StateMachineDragNoBar, BOX2_MAIN_StateMachineReturnHeld
 * address:  0x021DC860
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
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BOX_SAVEDATA_GetCurrentBox 0x02007698 thumb
 *   BOX_SAVEDATA_GetUsableBoxCount 0x020076A4 thumb
 *   BOX_SAVEDATA_CountPokemonInBox 0x020078C4 thumb
 *   BOX_SAVEDATA_UnlockBoxes 0x020076B4 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   BOX2_SEQ_UpdatePrintQueue  0x021E1E34  thumb  ov170
 *   TCB_DeleteTask  0x02030EAC  arm  arm9
 *   BOX2_SEQ_FlushDirtyBmpWins  0x021EAB04  thumb  ov170
 *   BG_SYS_Update  0x020419E4  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   BG_SYS_ClearGraphicsMemory  0x0204335C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   PROCSYS_Main  0x02031330  arm  arm9
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021EF7FC 0x021EF7FC data
 *   d_021EF82C 0x021EF82C data
 *   d_021EF8CC 0x021EF8CC data
 *   d_021EF86C 0x021EF86C data
 *   d_021EF88C 0x021EF88C data
 *   d_021EF80C 0x021EF80C data
 *   d_021EF8AC 0x021EF8AC data
 *   d_021EF84C 0x021EF84C data
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetCursorPos 0x02027CFC thumb
 *   BOX2_SEQ_SetActorAutoAnim 0x021EBFCC thumb
 *   BOX2_SEQ_IsActorAnimActive 0x021EBFEC thumb
 *   BGWINFRM_GetPos 0x0202CF98 thumb
 *   BGWINFRM_GetSize 0x0202CFC0 thumb
 *   BGWINFRM_GetBgFrame 0x0202CF8C thumb
 *   BOX2_UI_DeleteSlotObjects  0x021EE038  thumb  ov170
 *   BOX2_UI_PutFadeFrame  0x021EF660  thumb  ov170
 *   BOX2_SEQ_SetActorAnimSeq 0x021EBFA8 thumb
 *   BOX2_SEQ_LoadMonIcon 0x021EC35C thumb
 *   BOX2_UI_HideSlotIcon  0x021EDECC  thumb  ov170
 *   BOX2_UI_SetMiniIconVisible  0x021EE008  thumb  ov170
 *   BOX2_UI_RefreshBoxName  0x021ED904  thumb  ov170
 *   BOX2_UI_SetCloseButtonPos  0x021ED9B4  thumb  ov170
 *   BOX2_UI_UpdateCurrentBoxMarker  0x021EDF5C  thumb  ov170
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   BOX2_UI_PutInfoBar  0x021EF738  thumb  ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   BOX_SAVEDATA_GetPokemon 0x02007A18 thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   POKE_TOOL_CreateFromBoxParam 0x0201747C thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   BOX_SAVEDATA_SetPokemon 0x020075B0 thumb
 *   POKEPARTY_SetMember 0x0201AB48 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   BOX2_UI_DrawSlotByName 0x021EDB34 thumb ov170
 *   BOX_SAVEDATA_AddPokemonToBox 0x0200752C thumb
 *   BOX_SAVEDATA_ClearPokemon 0x02007664 thumb
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   BOX_SAVEDATA_SwapPokemon 0x02007610 thumb
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb
 *   POKE_TOOL_GetPlateTypeForwarder 0x02019CF8 thumb
 *   POKE_TOOL_GetBoxParamIndex 0x02019D00 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb ov170
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   BLOCK20_SAVEDATA_TestBit 0x020092AC thumb
 *   BOX2_SEQ_SetSlotDrawPriorityB 0x021EC7B8 thumb
 *   BOX2_SEQ_GetSlotPos 0x021EC548 thumb
 *   BOX2_UI_IsTopBarMid 0x021EF4A4 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   FILE_UTIL_IsMailItem 0x0202136C thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_UI_FindSlotPos 0x021EDA70 thumb
 *   BOX2_SEQ_SwapSlotActorsB 0x021ECBD8 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_021F1400 0x021F1400 data a1
 *   GAME_DATA_GetPerapVoiceSave  0x02012F98  thumb
 *   PERAPVOICE_ClearIfNoChatot  0x02007C34  thumb
 *   BOX2_SEQ_MoveActorToSlot 0x021ED164 thumb ov170
 *   BOX2_SEQ_MoveActorToSlotB 0x021ED198 thumb ov170
 *   BOX2_SEQ_MoveActor 0x021ED14C thumb ov170
 *   BOX2_SEQ_LayoutHandSlots 0x021ED310 thumb ov170
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   BG_SYS_LoadTileData  0x02040B1C  arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BOX2_SEQ_DrawBoxName 0x021EB7E8 thumb
 *   BOX2_UI_SetSlotOamEnabled 0x021EE224 thumb
 *   BOX2_UI_GetSlotOamEnabled 0x021EE234 thumb
 *   BOX2_UI_MoveSlotOam 0x021EE244 thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   BOX_SAVEDATA_GetWallpaper  0x0200781C  thumb  ov170
 *   POKE_TOOL_GetBoxNature 0x020185A0 thumb
 *   POKE_TOOL_GetBoxGender 0x02017F08 thumb
 *   POKE_TOOL_IsBoxShiny 0x02017EB4 thumb
 *   POKERUS_IsBoxInfected 0x0201B268 thumb
 *   POKERUS_IsBoxCured 0x0201B28C thumb
 *   BOX2_SEQ_LoadMonIconActor  0x021ECCCC  thumb  ov170
 *   BOX2_SEQ_ShowHandSlotB  0x021ED028  thumb  ov170
 *   BOX2_SEQ_DeleteTextEntries  0x021EB2A4  thumb  ov170
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   BOX2_SEQ_ClearTextWin 0x021EB324 thumb
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb  ov170
 *   d_021EF798 0x021EF798 data a1
 *   BOX2_UI_GetGridSlotPoint  0x021EF224  thumb  ov170
 *   PROCSYS_Push 0x02031348 arm
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   ov070_id       0x00000046  data
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_GetBlock 0x0200C0F0 thumb
 *   BOX_SAVEDATA_GetBoxName 0x0200785C thumb
 *   NAMEIN_SETUP_CreateArgs 0x0216BFD4 thumb ov010
 *   gNameInProcData 0x021F5580 data a4 ov194
 *   ov194_id 0x000000C2 data a1
 *   BOX_SAVEDATA_SetBoxName 0x02007898 thumb
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_StepScrollToPrevBox 0x021E00C4 thumb
 *   BOX2_MAIN_StepScrollToNextBox 0x021E0128 thumb
 *   BOX2_MAIN_ShiftWindowRight 0x021E01C4 thumb
 *   BOX2_MAIN_ShiftWindowLeft 0x021E01E0 thumb
 *   BOX2_SEQ_OpenBoxUp 0x021E19D4 thumb
 *   BOX2_SEQ_OpenBoxDown 0x021E1A28 thumb
 *   BOX2_SEQ_HidePartialSlots 0x021EC5A0 thumb
 *   BOX2_SEQ_SetCursorDraw 0x021ED55C thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_UI_SetCursorPos 0x021EE3E4 thumb
 *   BOX2_UI_GetPartySlotPoint 0x021EF180 thumb
 *   BOX2_UI_GetCloseButtonHit 0x021EF1B4 thumb
 *   BOX2_UI_GetExitButtonHit 0x021EF1C4 thumb
 *   BOX2_UI_GetPageButtonHit2 0x021EF264 thumb
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
 *   POKE_TOOL_SetBoxValue  0x02017E64  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   POKEPARTY_RemoveMember  0x0201A9C8  thumb  arm9
 *   POKEPARTY_SwapMembers  0x0201AB8C  thumb  arm9
 *   BOX2_MAIN_StartMover 0x021DE5F8 thumb ov170
 *   BOX2_MAIN_WaitCursorMove 0x021DD930 thumb ov170
 *   BOX2_MAIN_SetMoverEntry 0x021DE66C thumb ov170
 *   BOX2_MAIN_MoveCursorWithMon 0x021DE158 thumb ov170
 *   BOX2_SEQ_ShiftSlotIcons 0x021EC804 thumb
 *   BOX2_UI_ShiftSlotOams 0x021EE26C thumb
 *   BOX2_UI_UpdateTopBarMove 0x021EF6E0 thumb ov170
 *   BOX2_UI_MoveSlotIcon  0x021ED918  thumb  ov170
 *   BOX2_MAIN_StepToAdjacentBox 0x021DD16C thumb
 *   BOX2_MAIN_WaitBoxScroll 0x021DDAE8 thumb
 *   BOX2_MAIN_SwapWithNeighbour 0x021DE428 thumb
 *   BOX2_MAIN_FindMoverSlot 0x021DE5C8 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_MAIN_HitBoxGrid 0x021DF1DC thumb
 *   BOX2_MAIN_MoveCursorActor 0x021DF43C thumb
 *   BGWINFRM_UpdateMove  0x0202CDD4  thumb  arm9
 *   BOX2_MAIN_HitPartySlots 0x021DF228 thumb
 *   BOX2_MAIN_SetMoverTarget 0x021DE530 thumb
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
 *   BOX2_MAIN_StartHandMotionToBoxArrow 0x021DE980 thumb
 *   BOX2_MAIN_StartHandMotionToTargetBoxSlot 0x021DEA4C thumb
 *   BOX2_MAIN_StepHandMotionToSlotB 0x021DEB08 thumb ov170
 *   BOX2_MAIN_ResetGraphics 0x021DC9C4 thumb ov170
 *   BOX2_MAIN_InitBgSys 0x021DC9E0 thumb ov170
 *   BOX2_MAIN_CreatePalAnm 0x021DCDB8 thumb ov170
 *   BOX2_MAIN_LoadBgData 0x021DCB8C thumb ov170
 *   BOX2_MAIN_CreateTextSystem 0x021DCE14 thumb ov170
 *   BOX2_MAIN_LoadFormTable 0x021DD8D0 thumb ov170
 *   BOX2_MAIN_CreateTaskMenu 0x021DCEC0 thumb ov170
 *   BOX2_MAIN_SetDisplayControl 0x021DCDF0 thumb ov170
 *   BOX2_MAIN_CreateVBlankTask 0x021DC94C thumb ov170
 *   BOX2_MAIN_DeleteVBlankTask  0x021DC964  thumb  ov170
 *   BOX2_MAIN_DeleteTaskMenu  0x021DCF30  thumb  ov170
 *   BOX2_MAIN_DeleteFormTable  0x021DD8F8  thumb  ov170
 *   BOX2_MAIN_DeleteTextSystem  0x021DCE80  thumb  ov170
 *   BOX2_MAIN_DeletePalAnm  0x021DCDD8  thumb  ov170
 *   BOX2_MAIN_DeleteBgSys  0x021DCB48  thumb  ov170
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BOX2_MAIN_StepWindowFrameFade  0x021DCFC0  thumb  ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_MAIN_ActivateKeyCursor 0x021DD238 thumb
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb ov170
 *   BOX2_MAIN_StateMachineClose 0x021E0068 thumb ov170
 *   BOX2_MAIN_SceneWaitCursor 0x021E0778 thumb
 *   BOX2_MAIN_SceneOpenBox 0x021E087C thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_SyncItemForm 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_MAIN_GetBoxValue 0x021DD908 thumb ov170
 *   BOX2_MAIN_RefreshMonInfo 0x021DEF98 thumb ov170
 *   BOX2_MAIN_SetHandSlots 0x021DF110 thumb ov170
 *   BOX2_MAIN_UpdateWindowMove 0x021E01A8 thumb ov170
 *   BOX2_MAIN_SetBodySlots 0x021DF11C thumb ov170
 *   BOX2_MAIN_HasOtherTradable 0x021DD694 thumb ov170
 *   BOX2_MAIN_StepScroll 0x021DE7C8 thumb ov170
 *   BOX2_MAIN_DeleteScroll 0x021DE7B4 thumb ov170
 *   BOX2_MAIN_ClearSlot 0x021DD314 thumb
 *   BOX2_MAIN_StateMachineOpen 0x021E002C thumb
 *   BOX2_MAIN_LoadBoxPalette 0x021DED58 thumb ov170
 *   BOX2_MAIN_InitSeq  0x021DC9A0  thumb  ov170
 *   BOX2_MAIN_RestartSeq  0x021DC9B8  thumb  ov170
 *   BOX2_MAIN_OpenTaskMenu 0x021DCF58 thumb
 *   BOX2_MAIN_SetBoxForm 0x021DEFF8 thumb ov170
 *   BOX2_MAIN_ResetMovers 0x021DE728 thumb ov170
 *   BOX2_MAIN_ClearPerapVoiceIfNoChatot  0x021DE898  thumb  ov170
 *   BOX2_MAIN_SetupWindowFrameFade  0x021DD090  thumb  ov170
 *   BOX2_MAIN_RefreshBoxUi 0x021DD1E8 thumb
 *   BOX2_MAIN_SceneMoveCursor 0x021E072C thumb
 *   BOX2_MAIN_StateMachineScroll 0x021DFA30 thumb
 *   BOX2_MAIN_StateMachinePen  0x021E0470  thumb  ov170
 *   BOX2_MAIN_StateMachinePick 0x021DF484 thumb
 *   BOX2_MAIN_StateMachineMove 0x021E0200 thumb
 *   BOX2_MAIN_GetDispVram 0x021DC9D8 thumb ov170
 *   BOX2_SEQ_SetActorAnim 0x021EA878 thumb ov170
 *   BOX2_SEQ_GetActorDrawEnable 0x021EC01C thumb ov170
 *   BOX2_SEQ_SetActorAffineMode 0x021ED108 thumb ov170
 *   BOX2_SEQ_ShowHandSlots 0x021ED2F4 thumb ov170
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   PROCSYS_Delete  0x0203133C  arm  arm9
 *   PROCSYS_FreeProcWork  0x020315D4  arm  arm9
 *   BOX_SAVEDATA_SetCurrentBox  0x0200780C  thumb  arm9
 */
#include "box2_types.h"
#include "../version.h"
#include "../sdk_ioreg.h"
#include "../ov170/box2_seq.h"

struct Proc;

struct ProcSys;

struct Proc;

struct PaletteFade;

struct DispVram;
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/box_savedata.h"
#include "box2_seq.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/gfl_use.h"
#include "../arm9/tcb_list.h"
#include "../arm9/clact.h"
#include "../arm9/bg_sys.h"
#include "../arm9/app_taskmenu.h"
#include "../arm9/bag_param.h"
#include "../arm9/beacon.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/g2.h"
#include "../arm9/game_data.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
#include "../arm9/perapvoice.h"
#include "../arm9/pokeparty.h"
#include "../arm9/pokerus.h"
#include "../arm9/printsys.h"
#include "../arm9/ui.h"
#include "../arm9/arc_tool.h"
#include "../arm9/app_icon.h"
#include "../arm9/palanm.h"
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
#include "../arm9/cursor_move.h"
#include "../arm9/bgwinfrm.h"
#include "box2_ui.h"
#include "../arm9/poke_tool.h"
#include "../arm9/zukan_save.h"
#include "../arm9/poke_personal.h"
#include "../arm9/block20_savedata.h"
#include "../arm9/file_util.h"
#include "../arm9/touchpanel.h"
#include "../ov010/namein_setup.h"

typedef enum { B0=0, B8=8, B16=16 } Bound;



struct GameData;













struct TcbTask;







int BOX2_MAIN_Init(void *manager, int unused, void **context);

int BOX2_MAIN_Main(int a, int *b, int c, BoxTask *d);

int BOX2_MAIN_Exit(struct Proc *a, int b, int c, BoxTask *d);

void BOX2_MAIN_CreateVBlankTask(BoxTask *p);

void BOX2_MAIN_DeleteVBlankTask(BoxTask *p);

void BOX2_MAIN_VBlankHandler(struct TcbTask *tcb, void *work);

void BOX2_MAIN_InitSeq(BoxWork *p, BoxSeqStepFunc v);

void BOX2_MAIN_SetSeqParam(BoxWork *p, BoxSeqStepFunc v);

void BOX2_MAIN_RestartSeq(BoxWork *p);

void BOX2_MAIN_ResetGraphics(void);

void *BOX2_MAIN_GetDispVram(void);

extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];

int BOX2_MAIN_Init(void *manager, int unused, void **context)
{
    u8 *p;
    u16 max;
    u16 i;
    GFL_HEAP_CreateChildHeap(1,75,0x10000);
    p = PROCSYS_AllocProcWork(manager,sizeof(BoxTask),75);
    MI_CpuFill8((void *)p,0,sizeof(BoxTask));
    *(void ** *)&((BoxTask *)p)->params = context;
    ((BoxTask *)p)->curBox = BOX_SAVEDATA_GetCurrentBox(context[1]);
    ((BoxTask *)p)->boxLimit = BOX_SAVEDATA_GetUsableBoxCount(((BoxTask *)p)->params->boxSave);
    ((BoxTask *)p)->heldSlot = 255;
    ((BoxTask *)p)->state = 11;
    if (((BoxTask *)p)->boxLimit != 24) {
        if (((BoxTask *)p)->boxLimit == 8) max = B8;
        else if (((BoxTask *)p)->boxLimit == 16) max = B16;
        for (i=0;i<max;i++) {
            if (BOX_SAVEDATA_CountPokemonInBox(((BoxTask *)p)->params->boxSave,i) == 0) break;
        }
        if (i == max) ((BoxTask *)p)->boxLimit = BOX_SAVEDATA_UnlockBoxes(((BoxTask *)p)->params->boxSave);
    }
    ((BoxTask *)p)->slot7Mode = 0;
    ((BoxTask *)p)->slot6Mode = 0;
    ((BoxTask *)p)->slot8Mode = 1;
    ((BoxTask *)p)->procSys = PROCSYS_Create(75);
    return 1;
}

/*
 * Re-derive d[2] from d[1] then test the entry; 0 means accepted.
 */
int BOX2_MAIN_Main(int a, int *b, int c, BoxTask *d)
{
    d->subState = PROCSYS_Main((void *)d->procSys);
    if (BOX2_SEQ_UpdatePrintQueue((BoxTask *)d, b) == 0)
        return 1;
    return 0;
}

int BOX2_MAIN_Exit(struct Proc *a, int b, int c, BoxTask *d)
{
    BOX_SAVEDATA_SetCurrentBox(d->params->boxSave, d->curBox);
    PROCSYS_Delete((struct ProcSys *)d->procSys);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(0x4b);
    return 1;
}

/*
 * Seat the 0x54 handler word.
 */
void BOX2_MAIN_CreateVBlankTask(BoxTask *task)
{
    task->work->vblankTask = GFL_USE_AddMainTask(BOX2_MAIN_VBlankHandler, task, 0);
}

/*
 * Tail call TCB_DeleteTask with the word at +0x2c/+0x54.
 */
void BOX2_MAIN_DeleteVBlankTask(BoxTask *task)
{
    TCB_DeleteTask(task->work->vblankTask);
}

void BOX2_MAIN_VBlankHandler(struct TcbTask *tcb, void *work)
{
    BoxTask *task = work;

    BOX2_SEQ_FlushDirtyBmpWins((unsigned char *)task->work);
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((PaletteFade *)((struct PaletteFade *)((task->work->palAnm))));
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3ff8) |= 1;
}

/*
 * Clear the two halfword fields at +0x64/+0x66, store v at +0x58 and zero +0x5c.
 */
void BOX2_MAIN_InitSeq(BoxWork *work, BoxSeqStepFunc v)
{
    work->seq.state = 0;
    work->seq.timer = 0;
    work->seq.stepFunc = v;
    work->seq.restartFunc = 0;
}

/*
 * Store the second argument into the word field at +0x5c of the object.
 */
void BOX2_MAIN_SetSeqParam(BoxWork *work, BoxSeqStepFunc v)
{
    work->seq.restartFunc = v;
}

/*
 * Re-run the reset helper with the stored word.
 */
void BOX2_MAIN_RestartSeq(BoxWork *work)
{
    BOX2_MAIN_InitSeq((BoxWork *)work, work->seq.restartFunc);
}

/*
 * Two calls after setting the first argument.
 */
void BOX2_MAIN_ResetGraphics(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)((void *)0x021EF7CC));
}

/*
 * Constant-address getter.
 */
void *BOX2_MAIN_GetDispVram(void)
{
    return (void *)0x021EF7CC;
}





struct GfFont;

struct TaskMenuRes;

struct TaskMenuRes;

struct TaskMenuInitWork;

struct BoxPokemon;

struct Party;

struct PokemonParam;

struct PokemonParam;

struct BoxPokemon;

struct BoxPokemon;

struct ZukanSave;

struct Sub02007AC8Entry;

struct PerapVoice;

struct BigObj;

struct GameData;



typedef struct { u32 fmt; u32 bExtendedPlt; u32 szByte; u8 *pRawData; } PlttData;


typedef struct {
    u32 heapId;
    u8 count;
    u8 pad05[3];
    const void *items;
    u32 mode;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} MenuTmpl;

typedef struct BoxMover {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} BoxMover;

typedef struct BoxMove {
    BoxMover e[7];
    int count;
    unsigned a;
    unsigned b;
    unsigned req;
} BoxMove;

typedef struct BoxMotor {
    unsigned short idx;
    unsigned short slot;
    int mode;
    int x;
    int y;
    int vx;
    int vy;
    unsigned int left : 1;
    unsigned int up : 1;
} BoxMotor;

typedef struct {
    unsigned short index;
    unsigned short pad;
    int value, x, y, dx, dy;
    unsigned dirX:1;
    unsigned dirY:1;
    unsigned count:30;
} Motion;
typedef struct Summary {
    void *mon;
    unsigned short species;
    unsigned short form;
    unsigned pid;
    unsigned char cC;
    unsigned char cD;
    unsigned char cE;
    unsigned char cF;
    unsigned short item;
    unsigned char level : 7;
    unsigned char egg : 1;
    unsigned char gender : 4;
    unsigned char showgender : 1;
    unsigned char shiny : 1;
    unsigned char mark : 2;
    unsigned short moves[4];
} Summary;

#include "../ov131/p_status_types.h"
#include "../arm9/bag_param_types.h"

typedef struct { void *task; void *text; } NameInRequest;







































struct PrintQueue;







struct Cursor;






struct BgWinFrmWork;


































































































int BOX2_MAIN_ShiftWindowRight(BoxTask *p);























int BOX2_MAIN_StepScrollToPrevBox(BoxTask *p);

int BOX2_MAIN_StepScrollToNextBox(BoxTask *p);



int BOX2_MAIN_ShiftWindowLeft(BoxTask *p);












void BOX2_MAIN_InitBgSys(u8 *unused);

void BOX2_MAIN_DeleteBgSys(void *p);

void BOX2_MAIN_LoadBgData(BoxTask *ctx);

void BOX2_MAIN_CreatePalAnm(BoxTask *p);

void BOX2_MAIN_DeletePalAnm(int *p);

void BOX2_MAIN_SetDisplayControl(int a);

void BOX2_MAIN_CreateTextSystem(char *p);

void BOX2_MAIN_DeleteTextSystem(char *p);

void BOX2_MAIN_CreateTaskMenu(char *p);

void BOX2_MAIN_DeleteTaskMenu(BoxTask *p);

void BOX2_MAIN_OpenTaskMenu(BoxTask *p, int sel);

int BOX2_MAIN_StepWindowFrameFade(BoxTask *p);

void BOX2_MAIN_SetupWindowFrameFade(BoxTask *p, unsigned idx);

void BOX2_MAIN_RefreshCursorBox(BoxTask *p);

void BOX2_MAIN_StepToAdjacentBox(BoxTask *p, int dir);

void BOX2_MAIN_SelectBox(BoxTask *p, int a);

void BOX2_MAIN_RefreshBoxUi(BoxTask *p);

int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);

void BOX2_MAIN_ActivateKeyCursor(BoxTask *p);

unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, unsigned short box, unsigned id, unsigned v);
struct BoxTask;

void BOX2_MAIN_SetBoxValueAt(struct BoxTask *a, int b, int c, int d, int e);

void *BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);

void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);

void BOX2_MAIN_SwapBoxAndPartyMon(unsigned char *p,unsigned short *q,unsigned short *t);

void BOX2_MAIN_AddMonToParty(unsigned char *p, unsigned short *q);

void BOX2_MAIN_DepositPartyMon(BoxTask *p, unsigned char *a);

void BOX2_MAIN_SwapPartyMembers(char **p, char *q);

void BOX2_MAIN_ShiftMemberToEnd(BoxTask *p, unsigned char *a);

void BOX2_MAIN_MoveMonToListedBox(unsigned char *p,unsigned a,unsigned b,unsigned c);

void BOX2_MAIN_MovePartyMonToListedBox(unsigned char *p,unsigned a,unsigned b);

void BOX2_MAIN_UpdateBoxSlots(BoxTask *p);

int BOX2_MAIN_WrapSlot(unsigned char *p, unsigned i);

int BOX2_MAIN_HasOtherTradable(void ***p, unsigned skip);

void BOX2_MAIN_ChangeFormAndRegister(void **pp, void *a, u32 b);

int BOX2_MAIN_SyncItemForm(void **pp, void *mon);

void BOX2_MAIN_ResetShayminFormInBox(BoxTask *p,unsigned a,unsigned b,unsigned box);

void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx);

void BOX2_MAIN_LoadFormTable(char *p);

void BOX2_MAIN_DeleteFormTable(BoxTask *p);

int BOX2_MAIN_GetBoxValue(char *p, u32 a);

int BOX2_MAIN_WaitCursorMove(BoxTask *p);

int BOX2_MAIN_WaitBoxScroll(BoxTask *p);

int BOX2_MAIN_HandleMonPickup(BoxTask *p, unsigned a, unsigned b);

int BOX2_MAIN_ComparePartyValue(unsigned char *p,unsigned a,unsigned b);

int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b);

void BOX2_MAIN_AdvanceMover(BoxTask *p, BoxMover *o);

void BOX2_MAIN_UpdateMoverX(BoxTask *p,BoxMover *o);

void BOX2_MAIN_UpdateMoverY(BoxTask *p, BoxMover *o);

void BOX2_MAIN_StepMover(BoxTask *p, int a, int b);

int BOX2_MAIN_MoveCursorWithMon(BoxTask *p, unsigned a, unsigned b);

void BOX2_MAIN_SwapWithNeighbour(BoxTask *p, unsigned a, unsigned b);

void BOX2_MAIN_SetMoverTarget(BoxTask *p, int a, int b);

int BOX2_MAIN_FindMoverSlot(BoxTask *p, unsigned id);

void BOX2_MAIN_StartMover(BoxTask *p,unsigned a);

void BOX2_MAIN_SetMoverEntry(BoxTask *p, BoxMover *e);

int BOX2_MAIN_GetMinusOne(unsigned short a);

void BOX2_MAIN_ResetMovers(BoxTask *p);

void BOX2_MAIN_DeleteScroll(BoxTask *p);

int BOX2_MAIN_StepScroll(BoxTask *p);

void BOX2_MAIN_ClearPerapVoiceIfNoChatot(int *q);

void BOX2_MAIN_StartHandMotionToSlot(BoxTask *p, int slot, unsigned idx, int mode, int flag);

void BOX2_MAIN_StartHandMotionToBoxArrow(BoxTask *p, int mode);

void BOX2_MAIN_StartHandMotionToBoxSlot(BoxTask *a, int b, int c, int d);

void BOX2_MAIN_StartHandMotionToTargetBoxSlot(BoxTask *p, int a, int b);

int BOX2_MAIN_StepHandMotion(BoxTask *p, int a);

int BOX2_MAIN_StepHandMotionToSlot(BoxTask *a);

int BOX2_MAIN_StepHandMotionToSlotB(unsigned char *p);

unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);

void BOX2_MAIN_LoadBgCharTile(void *a, int b, u32 c);

void BOX2_MAIN_LoadBgPaletteTile(void *a, int b, int c);

void BOX2_MAIN_LoadBgTileSet(void *unused, int unused2, int x, u32 base, u32 pal);

void BOX2_MAIN_LoadBgTiles(void *a, int b, int c, u32 d, int e);

void BOX2_MAIN_SetBoxScroll(BoxTask *p, int a, int dir);

void BOX2_MAIN_LoadBoxPalette(BoxTask *p, int a);

int BOX2_MAIN_GetBoxWallpaper(BoxTask *p, int box);

Summary *BOX2_MAIN_CreateSummary(void *mon);

void BOX2_MAIN_DeleteHandle(void *s);

void BOX2_MAIN_SetupSummary(BoxTask *p, struct Summary *a);

int BOX2_MAIN_RefreshMonInfo(char *p, int a, unsigned b);

void BOX2_MAIN_RefreshCurrentBoxMonInfo(BoxTask *p, int b);

void BOX2_MAIN_SetBoxForm(BoxTask *p, unsigned b);

void BOX2_MAIN_ResetBoxView(BoxTask *p);

void BOX2_MAIN_ClearCursorBox(unsigned char *p);

void BOX2_MAIN_SetSceneSlots(char *p,int base,u32 bits);

void BOX2_MAIN_SetHandSlots(char *p, int b);

void BOX2_MAIN_SetBodySlots(char *p, int b);

void BOX2_MAIN_HideSlots(BoxWork *p);

void BOX2_MAIN_SetupSummaryActors(BoxWork *w, Summary *s);

int BOX2_MAIN_HitRect(int a, int b, unsigned char *r);

int BOX2_MAIN_HitBoxGrid(short x, int y);

int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r);

int BOX2_MAIN_HitPartyGrid(BoxTask *p, short x, short y);

int BOX2_MAIN_PushPartyScene(BoxTask *p);

int BOX2_MAIN_PushPartySceneB(BoxTask *p);

int BOX2_MAIN_PushBagScene(void **p);

int BOX2_MAIN_PopSubArgs(BoxTask *p);

int BOX2_MAIN_PushNameScene(BoxTask *p);

int BOX2_MAIN_PopNameScene(u8 *p);

void BOX2_MAIN_MoveCursorActor(BoxTask *p, int x, int y);

int BOX2_MAIN_StateMachinePick(BoxTask *p);

int BOX2_MAIN_StateMachineScroll(BoxTask *p);

extern const struct DispConfig d_021EF7FC;

extern const struct BgTemplate d_021EF82C;

extern const struct BgTemplate d_021EF8CC;

extern const struct BgTemplate d_021EF86C;

extern const struct BgTemplate d_021EF88C;

extern const struct BgTemplate d_021EF80C;

extern const struct BgTemplate d_021EF8AC;

extern const struct BgTemplate d_021EF84C;

extern const char d_021F1400[];

extern const unsigned char d_021EF798[];

extern const unsigned gPokeStatusProcData[];

extern const char ov131_id[];

extern u8 ov070_id[];

extern const unsigned gNameInProcData[];

extern const char ov194_id[];

extern const unsigned char d_021EF79C[];

extern const unsigned char d_021EF7B4[];

/*
 * Background setup of the box screen: display banks, seven layers from
 * the rodata templates (clearing 1, 4 and 6), then the plane masks.
 */
void BOX2_MAIN_InitBgSys(u8 *unused)
{
    struct DispConfig c;
    struct BgTemplate t0;
    struct BgTemplate t1;
    struct BgTemplate t2;
    struct BgTemplate t3;
    struct BgTemplate t4;
    struct BgTemplate t5;
    struct BgTemplate t6;

    BG_SYS_Create(0x4C);
    c = d_021EF7FC;
    BG_SYS_SetGraphicsMode(&c);
    t0 = d_021EF82C;
    BG_SYS_InitBgLayer(0, &t0, 0);
    t1 = d_021EF8CC;
    BG_SYS_InitBgLayer(1, &t1, 0);
    BG_SYS_ClearSlot(1);
    BG_SYS_InitRun(1, 0x20, 0, 0x4C);
    t2 = d_021EF86C;
    BG_SYS_InitBgLayer(2, &t2, 0);
    t3 = d_021EF88C;
    BG_SYS_InitBgLayer(3, &t3, 0);
    t4 = d_021EF80C;
    BG_SYS_InitBgLayer(4, &t4, 0);
    BG_SYS_ClearSlot(4);
    BG_SYS_InitRun(4, 0x20, 0, 0x4C);
    t5 = d_021EF8AC;
    BG_SYS_InitBgLayer(5, &t5, 0);
    t6 = d_021EF84C;
    BG_SYS_InitBgLayer(6, &t6, 0);
    BG_SYS_ClearSlot(6);
    BG_SYS_InitRun(6, 0x20, 0, 0x4C);
    BG_SYS_SetMainPlaneVisible(0xF, 1);
    BG_SYS_SetSubPlaneVisible(7, 1);
}

void BOX2_MAIN_DeleteBgSys(void *unused)
{
    BG_SYS_SetMainPlaneVisible(15, 0);
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

void BOX2_MAIN_LoadBgData(BoxTask *ctx)
{
    void *arc;
    void *arc2;
    void *pal;
    PlttData *pd;
    u8 *src;
    u32 ofs;
    u32 r6;
    u16 *a;
    u16 *b;
    u32 i;

    arc = ARC_TOOL_CreateHandle(0x74, 0x4c);
    ARC_UTIL_UploadBgCharFromHandle((void *)arc, 0xc, 1, 0, 0, 1, 0x4c);
    ARC_UTIL_RegisterObjCharFromHandle((void *)arc, 3, 2, 0, 1, 0x4c);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)arc, 2, 2, 0, 0, 1, 0x4c);
    ARC_UTIL_UploadBgCharFromHandle((void *)arc, 1, 3, 0, 0, 1, 0x4c);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)arc, 0, 3, 0, 0, 1, 0x4c);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)arc, 4, 0, 0, 0x80, 0x4c);
    ARC_UTIL_UploadBgCharFromHandle((void *)arc, 0x3e, 1, 1000, 0x300, 1, 0x4c);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)arc, 0x3f, 0, 0x180, 0x40, 0x4c);
    pal = ARC_UTIL_LoadPaletteBlockFromArchive(APP_ICON_GetArchiveId(), 0x1f, (void *)(&pd), 0x804c);
    src = pd->pRawData;
    ofs = 0x194;
    BG_SYS_LoadPltt(0, src + 0x34, 4, ofs);
    src += 0x14;
    ofs += 0x20;
    BG_SYS_LoadPltt(0, src, 4, ofs);
    GFL_HEAP_Free((void *)pal);
    ARC_UTIL_UploadBgCharFromHandle((void *)arc, 6, 5, 0, 0, 1, 0x4c);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)arc, 5, 5, 0, 0, 1, 0x4c);
    ARC_UTIL_UploadBgCharFromHandle((void *)arc, 6, 6, 0, 0, 1, 0x4c);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)arc, 7, 4, 0, 0, 0x4c);
    ARC_TOOL_DeleteHandle((void *)arc);
    arc2 = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x4c);
    ARC_UTIL_RegisterObjCharFromHandle((void *)arc2, APP_ICON_GetStatusFrameFileId(), 0, 0, 0, 0x4c);
    ARC_UTIL_UploadPaletteFromHandleWhole((void *)arc2, APP_ICON_GetStatusAnimFileId(), 0, 0xe0, 0x20, 0x4c);
    ARC_UTIL_UploadBgPaletteFromHandle((void *)arc2, APP_ICON_GetStatusDataFileId(), 0, 0, 0, 0, 0x4c);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 7);
    BG_SYS_MarkTileDirty(0);
    r6 = ARC_UTIL_RegisterObjCharFromHandle((void *)arc2, APP_ICON_GetStatusFrameFileId(), 2, 0, 0, 0x4c);
    ARC_TOOL_DeleteHandle((void *)arc2);
    a = (u16 *)BG_SYS_GetBuf(0);
    b = (u16 *)BG_SYS_GetBuf(2);
    for (i = 0; i < 0x60u; i++) {
        *(u16 *)((char *)b + 0x540 + i * 2) = r6 + *(u16 *)((char *)a + 0x540 + i * 2);
    }
    BG_SYS_MarkTileDirty(2);
    ctx->work->dexFormId = BMP_MENUWORK_LoadFrameGfx(0, 10, 0, 0x4c);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x160, 0x20, 0x4c);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0x1e0, 0x20, 0x4c);
}

/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
void BOX2_MAIN_CreatePalAnm(BoxTask *task)
{
    int v = (sptr)PALANM_Create(0x4c);

    (*(int *)&task->work->palAnm) = v;
    PALANM_AllocSlotBuffers((struct PaletteFade *)((task->work->palAnm)), 0, 0x200, 0x4c);
}

void BOX2_MAIN_DeletePalAnm(int *task)
{
    PALANM_FreeSlotBuffers((struct PaletteFade *)((((BoxTask *)task)->work->palAnm)), 0);
    PALANM_Delete((void *)((((BoxTask *)task)->work->palAnm)));
}

void BOX2_MAIN_SetDisplayControl(int a)
{
    if (a == 1)
        G2x_SetBlendAlpha_((unsigned int *)REG_BLDCNT_ADDR, 0, 0x2a, 6, 0xa);
    else
        *(volatile unsigned short *)0x04000050 = 0;
}


#if LANGUAGE == LANGUAGE_JAPANESE
#define BOX2_MAIN_MSG_ARCHIVE 0xc
#else
#define BOX2_MAIN_MSG_ARCHIVE 9
#endif

void BOX2_MAIN_CreateTextSystem(char *task)
{
    (((BoxTask *)task)->work->msgBank) = MSGDATA_CreateFromArchive(0,2,BOX2_MAIN_MSG_ARCHIVE,0x4c);
    ((BoxTask *)task)->work->font = GF_FONT_Create(0x17,0,1,0,0x4c);
    (((BoxTask *)task)->work->fontAlt) = GF_FONT_Create(0x17,3,0,0,0x4c);
    (((BoxTask *)task)->work->wordSet) = WORDSET_CreateDefault(0x4c);
    (((BoxTask *)task)->work->printQue) = PRINTSYS_QUE_CreateEx(0x800,0x4c);
    (((BoxTask *)task)->work->strbuf) = STRBUF_Create(0x400,0x4c);
}










/*
 * trailing: two bytes alignment padding at 0x021DCEBE.
 */
void BOX2_MAIN_DeleteTextSystem(char *task)
{
    STRBUF_Delete((((BoxTask *)task)->work->strbuf));
    PRINTSYS_QUE_Delete((((BoxTask *)task)->work->printQue));
    WORDSET_Delete((((BoxTask *)task)->work->wordSet));
    GF_FONT_Delete((((BoxTask *)task)->work->fontAlt));
    GF_FONT_Delete(((BoxTask *)task)->work->font);
    MSGDATA_Delete((((BoxTask *)task)->work->msgBank));
}

















void BOX2_MAIN_CreateTaskMenu(char *task)
{
    ((BoxTask *)task)->work->taskMenuItems[0].str = MSGDATA_AllocString((((BoxTask *)task)->work->msgBank),0x6e);
    ((BoxTask *)task)->work->taskMenuItems[0].msgColor = 0x39e3;
    ((BoxTask *)task)->work->taskMenuItems[0].type = 0;
    ((BoxTask *)task)->work->taskMenuItems[1].str = MSGDATA_AllocString((((BoxTask *)task)->work->msgBank),0x6f);
    ((BoxTask *)task)->work->taskMenuItems[1].msgColor = 0x39e3;
    ((BoxTask *)task)->work->taskMenuItems[1].type = 0;
    (((BoxTask *)task)->work->taskMenuRes)=APP_TASKMENU_RES_Create(0,8,(struct GFont *)((BoxTask *)task)->work->font,(struct PrintQueue *)(((BoxTask *)task)->work->printQue),0x4c);
}

/*
 * lane O46
 */
void BOX2_MAIN_DeleteTaskMenu(BoxTask *task)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuRes *)((task->work->taskMenuRes)));
    STRBUF_Delete((struct Strbuf *)task->work->taskMenuItems[1].str);
    STRBUF_Delete((struct Strbuf *)task->work->taskMenuItems[0].str);
}









void BOX2_MAIN_OpenTaskMenu(BoxTask *task, int sel)
{
    MenuTmpl t;
    t.heapId = 0x4C;
    t.count = 2;
    t.items = task->work->taskMenuItems;
    t.mode = 1;
    t.x = 0x20;
    t.y = 0x12;
    t.w = 8;
    t.h = 3;
    if (CURSOR_MOVE_GetState(task->work->cursorMove) == 1)
        UI_SetInputMode(0);
    else
        UI_SetInputMode(1);
    task->work->taskMenu = APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&t), task->work->taskMenuRes);
    APP_TASKMENU_SetCursorPos((TaskMenuWork *)task->work->taskMenu, sel);
}

int BOX2_MAIN_StepWindowFrameFade(BoxTask *task)
{
    BoxFade *f = &task->work->fade;
    switch (f->state) {
    case 0:
        if (f->flag == 0) {
            BOX2_SEQ_SetActorAutoAnim((char *)((BoxWork *)task->work), f->id, f->lo);
        } else {
            BG_SYS_FillTileMap(f->id, f->x, f->y, f->w, f->h, f->lo);
            BG_SYS_MarkTileDirty(f->id);
        }
        f->state++;
        break;
    case 1:
        if (f->flag == 0) {
            if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), f->id) == 0)
                return 0;
        } else {
            f->count++;
            if (f->count == 4) {
                BG_SYS_FillTileMap(f->id, f->x, f->y, f->w, f->h, f->hi);
                BG_SYS_MarkTileDirty(f->id);
                f->count = 0;
                f->state++;
            }
        }
        break;
    case 2:
        f->count++;
        if (f->count == 2)
            return 0;
        break;
    }
    return 1;
}

void BOX2_MAIN_SetupWindowFrameFade(BoxTask *task, unsigned idx)
{
    unsigned short w;
    unsigned short h;
    signed char pos[2];
    BGWINFRM_GetPos(task->work->winMgr, idx, &pos[1], &pos[0]);
    BGWINFRM_GetSize(task->work->winMgr, idx, &w, &h);
    task->work->fade.flag = 1;
    task->work->fade.id = BGWINFRM_GetBgFrame(task->work->winMgr, idx);
    task->work->fade.lo = 0xD;
    task->work->fade.hi = 0xC;
    task->work->fade.state = 0;
    task->work->fade.count = 0;
    task->work->fade.x = pos[1];
    task->work->fade.y = pos[0];
    task->work->fade.w = w;
    task->work->fade.h = h;
}

void BOX2_MAIN_RefreshCursorBox(BoxTask *task)
{
    BOX2_UI_DeleteSlotObjects((BoxTask *)task, task->slot6Mode, task->slot7Mode,
                  task->slot8Mode);
    BOX2_UI_PutFadeFrame(task->work->winMgr);
}

void BOX2_MAIN_StepToAdjacentBox(BoxTask *task, int dir)
{
    if (dir == 0) {
        task->curBox = task->curBox == 0 ? task->boxLimit - 1 : task->curBox - 1;
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 0, 2);
    } else {
        task->curBox = task->curBox == task->boxLimit - 1 ? 0 : task->curBox + 1;
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 1, 4);
    }
    BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
    BOX2_MAIN_SetBoxScroll((BoxTask *)task, BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), dir);
}

/*
 * Fold the signed delta into p[0x19] through the wrap helper,
 *   then refresh and re-key the queue.
 */
void BOX2_MAIN_SelectBox(BoxTask *task, int a)
{
    task->prevBox = BOX2_MAIN_WrapOffset((unsigned char *)task, (signed char)a);
    BOX2_UI_HideSlotIcon((BoxTask *)task, a);
    BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
}

/*
 * Five-step reset: fold the delta, rebuild the queue object,
 *   re-run the frame update, clear the flag and re-stage channel 9.
 */
void BOX2_MAIN_RefreshBoxUi(BoxTask *task)
{
    BOX2_UI_RefreshBoxName((unsigned char *)task);
    BOX2_UI_SetCloseButtonPos(task->work);
    BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
    BOX2_SEQ_DrawOffsetName((unsigned char *)task, 0);
    BOX2_UI_PutInfoBar(task->work->winMgr);
}

/*
 * True when the absolute difference of the two unsigned arguments
 * straddles half of the +0x15 counter, in the direction of the order.
 */
int BOX2_MAIN_IsWrappedDistance(unsigned char *task, unsigned a, unsigned b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    if (a > b)
        return d >= ((unsigned)((BoxTask *)task)->boxLimit >> 1);
    return d < ((unsigned)((BoxTask *)task)->boxLimit >> 1);
}

/*
 * Enable the pooled object when it reports zero.
 */
void BOX2_MAIN_ActivateKeyCursor(BoxTask *task)
{
    UI_SetInputMode(0);
    if (CURSOR_MOVE_GetState(task->work->cursorMove) == 0)
        CURSOR_MOVE_SetState(task->work->cursorMove, 1);
}

unsigned BOX2_MAIN_GetPartyValueAt(void ***task, unsigned short a, unsigned short box, unsigned id, unsigned v)
{
    if (a >= 0x1E) {
        if (a >= 0x1E)
            a -= 0x1E;
        if ((int)POKEPARTY_GetCount((*task)[2]) > a)
            return POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((*task)[2], a), id, v);
    } else if (a != 0xFF) {
        void *m = BOX_SAVEDATA_GetPokemon((*task)[1], box, a);
        if (m != 0)
            return POKE_TOOL_GetBoxValue((void *)m, id, v);
    }
    return 0;
}

/*
 * Open the range, then feed the handle to the second call.
 */
void BOX2_MAIN_SetBoxValueAt(struct BoxTask *a, int b, int c, int d, int e)
{
    void *r = BOX2_MAIN_GetMonAt((void ***)a, c, b);
    if (r)
        POKE_TOOL_SetBoxValue(r, d, e);
}

void *BOX2_MAIN_GetMonAt(void ***task, int a, unsigned b)
{
    if (a == 0xFF || b >= 0x1E) {
        if (b >= 0x1E)
            b -= 0x1E;
        if (POKEPARTY_GetCount((*task)[2]) > b)
            return POKE_TOOL_CastToBoxParam((struct PokemonParam *)(POKEPARTY_GetMember((*task)[2], b)));
    } else if (b != 0xFF) {
        return BOX_SAVEDATA_GetPokemon((*task)[1], a, b);
    }
    return 0;
}

/*
 * Two ranges: below 30 forward all, at or above rebase.
 * The tested field is unsigned: a signed `b` compiles the inverted
 * branch as blo where the image has bhs.
 */
void BOX2_MAIN_ClearSlot(char **task, int a, unsigned b)
{
    if (b < 0x1eU)
        BOX_SAVEDATA_ClearPokemon((void *)(((BoxParam *)((*task)))->boxSave), a, b);
    else
        POKEPARTY_RemoveMember((struct Party *)(((BoxParam *)((*task)))->party), b - 0x1eU);
}

void BOX2_MAIN_SwapBoxAndPartyMon(unsigned char *task,unsigned short *q,unsigned short *t)
{
    unsigned box;
    unsigned short slot;
    void *m;
    if (q[0] == 0x24) box=((BoxTask *)task)->heldSlot; else box=((BoxTask *)task)->curBox;
    m=POKE_TOOL_CreateFromBoxParam((struct PokemonParam *)BOX2_MAIN_GetMonAt((void ***)task,box,q[2]),0x804c);
    slot=t[2]-30;
    BOX_SAVEDATA_SetPokemon(((BoxTask *)task)->params->boxSave,box,q[2],POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(((BoxTask *)task)->params->party,slot)));
    POKEPARTY_SetMember(((BoxTask *)task)->params->party,slot,m);
    GFL_HEAP_Free((void *)m);
    BOX2_UI_DrawSlot((BoxTask *)task,box);
}

void BOX2_MAIN_AddMonToParty(unsigned char *task, unsigned short *q)
{
    void *m;
    m = POKE_TOOL_CreateFromBoxParam((struct PokemonParam *)BOX2_MAIN_GetMonAt((void ***)task,((BoxTask *)task)->heldSlot,q[2]),0x804c);
    POKEPARTY_Add(((BoxTask *)task)->params->party,m);
    BOX2_MAIN_ClearSlot((char **)task,((BoxTask *)task)->heldSlot,q[2]);
    GFL_HEAP_Free((void *)m);
    BOX2_UI_DrawSlot((BoxTask *)task,((BoxTask *)task)->heldSlot);
}

/*
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */
void BOX2_MAIN_DepositPartyMon(BoxTask *task, unsigned char *a)
{
    const struct BoxPokemon *x = POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(((BoxTask *)task)->params->party,
                                        ((BoxMonRef *)(a))->slot - 0x1e));
    BOX_SAVEDATA_SetPokemon((void *)(((BoxTask *)task)->params->boxSave), task->curBox,
                  ((BoxMonRef *)(a))->pos, x);
    BOX2_MAIN_ClearSlot((char **)task, task->curBox, ((BoxMonRef *)(a))->slot);
    BOX2_UI_DrawSlot((BoxTask *)task, task->curBox);
}

/*
 * Forward two biased halfword coordinates.
 */
void BOX2_MAIN_SwapPartyMembers(char **task, char *q)
{
    POKEPARTY_SwapMembers((struct Party *)(((BoxParam *)((*task)))->party), ((BoxMonRef *)(q))->slot - 0x1e,
                  ((BoxMonRef *)(q))->pos - 0x1e, 0x4c);
}

/*
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */
void BOX2_MAIN_ShiftMemberToEnd(BoxTask *task, unsigned char *a)
{
    unsigned i = ((BoxMonRef *)(a))->slot - 0x1e;
    while (i < POKEPARTY_GetCount(task->params->party) - 1) {
        POKEPARTY_SwapMembers((struct Party *)task->params->party, i, i + 1, 0x4c);
        i++;
    }
}

void BOX2_MAIN_MoveMonToListedBox(unsigned char *task,unsigned a,unsigned b,unsigned c)
{
    void *m;
    unsigned box;
    m = BOX2_MAIN_GetMonAt((void ***)task,a,b);
    box = BOX2_MAIN_WrapSlot((unsigned char *)task,c);
    BOX_SAVEDATA_AddPokemonToBox(((BoxTask *)task)->params->boxSave,box,m);
    BOX_SAVEDATA_ClearPokemon(((BoxTask *)task)->params->boxSave,a,b);
    BOX2_UI_DrawSlot((BoxTask *)task,a);
    BOX2_UI_DrawSlotByName((char *)task,a);
    BOX2_UI_DrawSlot((BoxTask *)task,box);
    BOX2_UI_DrawSlotByName((char *)task,box);
}

/*
 * lever: declaring m before box selects r7 for m and r6 for box.
 */
void BOX2_MAIN_MovePartyMonToListedBox(unsigned char *task,unsigned a,unsigned b)
{
    void *m;
    unsigned box;
    box=BOX2_MAIN_WrapSlot((unsigned char *)task,b);
    m=POKEPARTY_GetMember(((BoxTask *)task)->params->party,a-30);
    if(POKE_TOOL_GetPartyValue(m,5,0)==492){
        POKE_TOOL_ChangeForm((void *)m,0);
        BOX2_MAIN_RecalcPartyParam((void **)task,a);
        ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(((BoxTask *)task)->params->gameData),m);
    }
    BOX_SAVEDATA_AddPokemonToBox(((BoxTask *)task)->params->boxSave,box,POKE_TOOL_GetBoxParam((void *)m));
    BOX2_MAIN_ClearSlot((char **)task,((BoxTask *)task)->curBox,a);
    BOX2_UI_DrawSlot((BoxTask *)task,box);
    BOX2_UI_DrawSlotByName((char *)task,box);
}

void BOX2_MAIN_UpdateBoxSlots(BoxTask *task)
{
    BoxMove *m = task->work->seq.entry;
    unsigned short n;
    if (m->a == 0xFF)
        return;
    n = POKEPARTY_GetCount(task->params->party);
    if (m->b >= 0x24) {
        if (m->a < 0x1E)
            BOX2_MAIN_MoveMonToListedBox((unsigned char *)task, task->heldSlot, m->a, m->b - 0x24);
        else
            BOX2_MAIN_MovePartyMonToListedBox((unsigned char *)task, m->a, m->b - 0x24);
        return;
    }
    if (m->a < 0x1E) {
        if (m->b < 0x1E) {
            BOX_SAVEDATA_SwapPokemon(task->params->boxSave, task->heldSlot, m->a, task->curBox, m->b);
            BOX2_UI_DrawSlot((BoxTask *)task, task->curBox);
            BOX2_UI_DrawSlotByName((char *)task, task->curBox);
            if (task->curBox != task->heldSlot) {
                BOX2_UI_DrawSlot((BoxTask *)task, task->heldSlot);
                BOX2_UI_DrawSlotByName((char *)task, task->heldSlot);
            }
            return;
        }
        if (m->b - 0x1E < n) {
            BOX2_MAIN_SwapBoxAndPartyMon((unsigned char *)task, (short unsigned int *)(&m->e[0]), (short unsigned int *)(&m->e[1]));
            BOX2_MAIN_ResetShayminFormInBox((BoxTask *)task, m->b, m->a, task->heldSlot);
        } else {
            BOX2_MAIN_AddMonToParty((unsigned char *)task, (short unsigned int *)(&m->e[0]));
            BOX2_MAIN_ResetShayminFormInBox((BoxTask *)task, m->b, m->a, task->heldSlot);
        }
        return;
    }
    if (m->b < 0x1E) {
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, m->b, task->curBox, 0xA9, 0)) {
            BOX2_MAIN_SwapBoxAndPartyMon((unsigned char *)task, (short unsigned int *)(&m->e[1]), (short unsigned int *)(&m->e[0]));
            BOX2_MAIN_ResetShayminFormInBox((BoxTask *)task, m->b, m->a, task->curBox);
        } else {
            BOX2_MAIN_DepositPartyMon((BoxTask *)task, (unsigned char *)(&m->e[m->a - 0x1E]));
            BOX2_MAIN_ResetShayminFormInBox((BoxTask *)task, m->b, m->a, task->curBox);
        }
        return;
    }
    if (m->b - 0x1E < n)
        BOX2_MAIN_SwapPartyMembers((char **)task, (char *)m);
    else
        BOX2_MAIN_ShiftMemberToEnd((BoxTask *)task, (unsigned char *)(&m->e[m->a - 0x1E]));
}

int BOX2_MAIN_WrapSlot(unsigned char *task, unsigned i)
{
    unsigned v = i + ((BoxTask *)task)->prevBox;
    if (v >= ((BoxTask *)task)->boxLimit)
        v -= ((BoxTask *)task)->boxLimit;
    return v;
}

int BOX2_MAIN_HasOtherTradable(void ***task, unsigned skip)
{
    unsigned i;
    for (i = 0; i < POKEPARTY_GetCount((*task)[2]); i++) {
        if (i != skip) {
            void *m = POKEPARTY_GetMember((*task)[2], i);
            if (POKE_TOOL_GetPartyValue(m, 0x4C, 0) == 0 && POKE_TOOL_GetPartyValue(m, 0xA0, 0) != 0)
                return 1;
        }
    }
    return 0;
}

void BOX2_MAIN_ChangeFormAndRegister(void **pp, void *a, u32 b)
{
    void *r;

    POKE_TOOL_ChangeBoxForm((struct BoxPokemon *)(a), b);
    r = POKE_TOOL_CreateFromBoxParam((struct PokemonParam *)a, 0x4c);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData(((BoxTask *)pp)->params->gameData), r);
    GFL_HEAP_Free((void *)r);
}

/*
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/arm9/POKE_TOOL_GetPlateTypeForwarder.c (EXACT, Thumb forwarder to POKE_TOOL_GetPlateType).
 * Expected EXACT after the integrator's manifest refresh.
 *
 * Re-derives the form of a species whose form follows its held item
 * (0x1ED by plate, 0x289 by drive, 0x1E7 by the item 0x70) and applies it;
 * returns 1 when the form changed.
 *
 * Blocker (MATCH): the call to 0x02019CF8 has no witness.  0x02019CF8 is an
 * 8-byte Thumb tail-call thunk (ldr r3, =0x02019BBD; bx r3) that the arm9
 * listing decodes as ARM and nothing else calls; seeding it as a Thumb
 * function start promotes this file to EXACT.
 */
int BOX2_MAIN_SyncItemForm(void **pp, void *mon)
{
    u16 species = POKE_TOOL_GetBoxValue((void *)mon, 5, 0);
    if (species == 0x1ED) {
        u16 item = POKE_TOOL_GetBoxValue((void *)mon, 6, 0);
        u16 form = POKE_TOOL_GetBoxValue((void *)mon, 0x6F, 0);
        u32 want = POKE_TOOL_GetPlateTypeForwarder(item);
        if (form != want)
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x289) {
        u16 item = POKE_TOOL_GetBoxValue((void *)mon, 6, 0);
        u16 form = POKE_TOOL_GetBoxValue((void *)mon, 0x6F, 0);
        u16 want = POKE_TOOL_GetBoxParamIndex(item);
        if (form != want)
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x1E7) {
        u16 item = POKE_TOOL_GetBoxValue((void *)mon, 6, 0);
        u16 old = POKE_TOOL_GetBoxValue((void *)mon, 0x6F, 0);
        u16 form = old;
        if (old == 0) {
            if (item == 0x70) {
                BOX2_MAIN_ChangeFormAndRegister(pp, mon, 1);
                form = 1;
            }
        } else if (item != 0x70) {
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, 0);
            form = 0;
        }
        if (old != form)
            return 1;
    }
    return 0;
}

/*
 * lever: the repeated third-argument truncations require a u16 extern parameter.
 */
void BOX2_MAIN_ResetShayminFormInBox(BoxTask *task,unsigned a,unsigned b,unsigned box)
{
    if(a<30 && b<30) return;
    if(a>=30 && b>=30) return;
    if(a>=30) a=b;
    if(BOX2_MAIN_GetPartyValueAt((void ***)task,a,box,5,0)!=492) return;
    if(BOX2_MAIN_GetPartyValueAt((void ***)task,a,box,0x6f,0)==0) return;
    BOX2_MAIN_ChangeFormAndRegister((void **)task,BOX2_MAIN_GetMonAt((void ***)task,box,a),0);
    BOX2_MAIN_RecalcPartyParam((void **)task,a);
    if(box==task->curBox)
        BOX2_SEQ_ShowSlotIcon((BoxTask *)task,box,a,task->work->cursorTable[a]);
    if(task->cursorSlot==a) BOX2_MAIN_RefreshCurrentBoxMonInfo((BoxTask *)task,a);
}

void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx)
{
    void *h;
    u32 v;

    if (idx < 0x1e)
        return;
    h = POKEPARTY_GetMember(((BoxParam *)(((char *)*pp)))->party, idx - 0x1e);
    v = POKE_TOOL_DecodePartyParam((struct PokemonParam *)((struct Sav *)h));
    POKE_TOOL_RecalcParam((struct PokemonParam *)((void *)h));
    POKE_TOOL_EncodePartyParam((struct PokemonParam *)((struct Sav *)h), v);
}

void BOX2_MAIN_LoadFormTable(char *task) { ((BoxTask *)task)->work->formTable=POKE_PERSONAL_LoadFormTable(76,0);((BoxTask *)task)->work->nationalDexEnabled=ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(**(void ** *)&((BoxTask *)task)->params)); }

/*
 * Tail call GFL_HEAP_Free with the word at +0x2c/+0x180.
 */
void BOX2_MAIN_DeleteFormTable(BoxTask *task)
{
    GFL_HEAP_Free((void *)task->work->formTable);
}

int BOX2_MAIN_GetBoxValue(char *task, u32 a) { u16 n;n=BOX2_MAIN_GetPartyValueAt((void ***)task,a,((BoxTask *)task)->curBox,5,0);return BLOCK20_SAVEDATA_TestBit(*(u8 * *)&((BoxTask *)task)->params->pickerBuffer,n); }

int BOX2_MAIN_WaitCursorMove(BoxTask *task)
{
    BoxMove *m = task->work->seq.entry;
    BoxMover *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            BOX2_SEQ_SetSlotDrawPriorityB((char *)((BoxWork *)task->work), e->id, e->slot, 1);
            k = task->work->cursorTable[e->id];
            if (e->slot < 0x1E) {
                BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], task->phase);
            } else if (e->slot < 0x24) {
                BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], task->phase);
                if (task->phase == 2 && BOX2_UI_IsTopBarMid(task->work->winMgr) == 0)
                    t[0] += 0xC0;
            } else {
                if (e->id >= 0x1E) {
                    BOX2_SEQ_GetSlotPos(0x24, &t[1], &t[0], task->phase);
                    if (task->phase == 2 && BOX2_UI_IsTopBarMid(task->work->winMgr) == 0)
                        t[0] += 0xC0;
                } else {
                    BOX2_SEQ_GetSlotPos(e->id, (short *)&t[1], (short *)&t[0], task->phase);
                }
                BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), k, 0);
            }
            BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), k, t[1], t[0], 0);
            if (e->used == 2)
                BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), k, 0);
        }
        BOX2_SEQ_SetSlotDimB((char **)task, task->cursorSlot);
        BOX2_SEQ_MoveCursorToSlot((char *)task->work, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = task->work->cursorTable[e->id];
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), k, t[1], t[0], 0);
        BOX2_SEQ_SetSlotDrawPriority((char *)((BoxWork *)task->work), e->id, 0);
    }
    BOX2_SEQ_SetSlotDimB((char **)task, task->cursorSlot);
    BOX2_SEQ_MoveCursorToSlot((char *)task->work, 0x24);
    return 1;
}

/*
 * Twin of src/matched/BOX2_MAIN_WaitCursorMove.c.
 */
int BOX2_MAIN_WaitBoxScroll(BoxTask *task)
{
    BoxMove *m = task->work->seq.entry;
    BoxMover *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            k = task->work->cursorTable[e->id];
            BOX2_SEQ_GetSlotPos(e->slot, (short *)&t[1], (short *)&t[0], task->phase);
            if (e->slot >= 0x1E)
                t[0] += 0x90;
            BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), k, t[1], t[0], 0);
        }
        BOX2_SEQ_MoveCursorToSlot((char *)task->work, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = task->work->cursorTable[e->id];
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), k, t[1], t[0], 0);
        BOX2_SEQ_SetSlotDrawPriority((char *)((BoxWork *)task->work), e->id, 0);
        break;
    }
    BOX2_SEQ_SetSlotDimB((char **)task, task->cursorSlot);
    BOX2_SEQ_MoveCursorToSlot((char *)task->work, 0x24);
    return 1;
}

int BOX2_MAIN_HandleMonPickup(BoxTask *task, unsigned a, unsigned b)
{
    unsigned m;
    if (b >= 0x24) {
        int n = BOX2_MAIN_WrapSlot((unsigned char *)task, b - 0x24);
        if (n == task->curBox || BOX_SAVEDATA_CountPokemonInBox((void *)task->params->boxSave, n) == 0x1E) {
            (((BoxTask *)(task))->work->result) = 1;
            return 0;
        }
        if (a >= 0x1E) {
            if (BOX2_MAIN_HasOtherTradable((void ***)task, a - 0x1E) == 0) {
                (((BoxTask *)(task))->work->result) = 3;
                return 0;
            }
            if (FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((void *)task->params->party, a - 0x1E), 6, 0)) == 1) {
                (((BoxTask *)(task))->work->result) = 2;
                return 0;
            }
        }
        m = 0;
    } else {
        m = BOX2_MAIN_GetPartyValueAt((void ***)task, b, task->curBox, 0xA9, 0);
    }
    if (task->params->mode == 4) {
        if (task->params->linkMode == 1) {
            (((BoxTask *)(task))->work->result) = 5;
            return 0;
        }
        if (a < 0x1E && b >= 0x1E && b < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)task, a, task->heldSlot, 0x4C, 0) != 0) {
            (((BoxTask *)(task))->work->result) = 4;
            return 0;
        }
        if (a >= 0x1E && a < 0x24 && b < 0x1E && m != 0 && BOX2_MAIN_GetPartyValueAt((void ***)task, b, task->curBox, 0x4C, 0) != 0) {
            (((BoxTask *)(task))->work->result) = 4;
            return 0;
        }
    }
    if (a >= 0x1E) {
        if (BOX2_MAIN_HasOtherTradable((void ***)task, a - 0x1E) == 0) {
            if (m == 0) {
                if ((b < 0x1E || b >= 0x24) && task->params->mode != 4) {
                    (((BoxTask *)(task))->work->result) = 3;
                    return 0;
                }
            } else if (BOX2_MAIN_GetPartyValueAt((void ***)task, b, task->curBox, 0x4C, 0) != 0 && b < 0x1E && task->params->mode != 4) {
                (((BoxTask *)(task))->work->result) = 3;
                return 0;
            }
        }
        if (b < 0x1E && FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((void *)task->params->party, a - 0x1E), 6, 0)) == 1) {
            (((BoxTask *)(task))->work->result) = 2;
            return 0;
        }
    } else if (b >= 0x1E && m != 0) {
        if (FILE_UTIL_IsMailItem(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((void *)task->params->party, b - 0x1E), 6, 0)) == 1) {
            (((BoxTask *)(task))->work->result) = 2;
            return 0;
        }
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, a, task->heldSlot, 0x4C, 0) != 0 && BOX2_MAIN_HasOtherTradable((void ***)task, b - 0x1E) == 0 && task->params->mode != 4) {
            (((BoxTask *)(task))->work->result) = 3;
            return 0;
        }
    }
    (((BoxTask *)(task))->work->result) = 0;
    return 1;
}

/*
 * trailing: two bytes alignment padding at 0x021DDE7E.
 */
int BOX2_MAIN_ComparePartyValue(unsigned char *task,unsigned a,unsigned b)
{
    int result = 0;
    if (BOX2_MAIN_GetPartyValueAt((void ***)task,(unsigned short)b,((BoxTask *)task)->curBox,0xa9,0))
        return result;
    if (!BOX2_MAIN_HasOtherTradable((void ***)task,a-30))
        return result;
    if (FILE_UTIL_IsMailItem((unsigned short)POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(((BoxTask *)task)->params->party,a-30),6,0)) != 1)
        result = 1;
    return result;
}

int BOX2_MAIN_CompareSlots(unsigned char *task, unsigned a, unsigned b)
{
    if (BOX2_MAIN_GetPartyValueAt((void ***)task, b, ((BoxTask *)task)->curBox, 0xA9, 0) == 0)
        return 0;
    if (BOX2_MAIN_GetPartyValueAt((void ***)task, b, ((BoxTask *)task)->curBox, 0x4C, 0) != 0)
        return 0;
    if (FILE_UTIL_IsMailItem(BOX2_MAIN_GetPartyValueAt((void ***)task, a, ((BoxTask *)task)->curBox, 6, 0)) == 1)
        return 0;
    if (FILE_UTIL_IsMailItem(BOX2_MAIN_GetPartyValueAt((void ***)task, b, ((BoxTask *)task)->curBox, 6, 0)) == 1)
        return 0;
    return 1;
}

void BOX2_MAIN_AdvanceMover(BoxTask *task, BoxMover *o)
{
    short t[2];
    BOX2_SEQ_GetActorSurfacePos((char *)task->work, task->work->cursorTable[o->id], (short *)&o->x, (short *)&o->y, 0);
    if (o->used != 2) {
        if (o->slot < 0x24)
            BOX2_SEQ_GetSlotPos(o->slot, &t[1], &t[0], task->phase);
        else
            BOX2_UI_FindSlotPos(task->work, o->slot - 0x24, &t[1], &t[0]);
    } else if (task->curBox > task->heldSlot) {
        BOX2_SEQ_GetActorSurfacePos((char *)task->work, 0, (short *)&t[1], (short *)&t[0], 0);
    } else {
        BOX2_SEQ_GetActorSurfacePos((char *)task->work, 1, (short *)&t[1], (short *)&t[0], 0);
    }
    if (o->x <= t[1]) {
        o->dx = 1;
        o->vx = ((t[1] - o->x) << 16) / 8;
    } else {
        o->dx = -1;
        o->vx = ((o->x - t[1]) << 16) / 8;
    }
    if (o->y <= t[0]) {
        o->dy = 1;
        o->vy = ((t[0] - o->y) << 16) / 8;
    } else {
        o->dy = -1;
        o->vy = ((o->y - t[0]) << 16) / 8;
    }
}

void BOX2_MAIN_UpdateMoverX(BoxTask *task,BoxMover *o)
{
    short t[2];
    unsigned i;
    i=task->work->cursorTable[o->slot];
    BOX2_SEQ_GetActorSurfacePos((char *)task->work,task->work->cursorTable[o->id],(short *)&o->x,(short *)&o->y,0);
    BOX2_SEQ_GetActorSurfacePos((char *)task->work,i,(short *)&t[1],(short *)&t[0],0);
    if(o->x<=t[1]){
        o->dx=1;
        o->vx=((t[1]-o->x)<<16)/8;
    }else{
        o->dx=-1;
        o->vx=((o->x-t[1])<<16)/8;
    }
    if(o->y<=t[0]){
        o->dy=1;
        o->vy=((t[0]-o->y)<<16)/8;
    }else{
        o->dy=-1;
        o->vy=((o->y-t[0])<<16)/8;
    }
}

void BOX2_MAIN_UpdateMoverY(BoxTask *task, BoxMover *o)
{
    short t[2];
    BOX2_SEQ_GetActorSurfacePos((char *)task->work, task->work->cursorTable[o->id], (short *)&o->x, (short *)&o->y, 0);
    BOX2_SEQ_GetSlotPos(o->slot, &t[1], &t[0], task->phase);
    t[0] += 0xC0;
    if (o->x <= t[1]) {
        o->dx = 1;
        o->vx = ((t[1] - o->x) << 16) / 8;
    } else {
        o->dx = -1;
        o->vx = ((o->x - t[1]) << 16) / 8;
    }
    if (o->y <= t[0]) {
        o->dy = 1;
        o->vy = ((t[0] - o->y) << 16) / 8;
    } else {
        o->dy = -1;
        o->vy = ((o->y - t[0]) << 16) / 8;
    }
}

/*
 * Program the two 4-short descriptor pairs (0x24, arg2, arg1, 1)
 *   of the p+0x2c+0x60 block and publish each.
 */
void BOX2_MAIN_StepMover(BoxTask *task, int a, int b)
{
    unsigned short *q = task->work->seq.entry;
    q[0] = 0x24;
    q[1] = b;
    q[2] = a;
    q[3] = 1;
    BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)q);
    q[12] = (unsigned short)b;
    q[13] = a;
    q[14] = (unsigned short)b;
    q[15] = 1;
    BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(q + 12));
}

int BOX2_MAIN_MoveCursorWithMon(BoxTask *task, unsigned a, unsigned b)
{
    BoxMove *m = task->work->seq.entry;
    unsigned i;
    unsigned n;
    unsigned short t;
    BoxMover *e;
    for (i = 0; i < 7; i++) {
        m->e[i].id = 0;
        m->e[i].slot = 0;
        m->e[i].src = 0;
        m->e[i].used = 0;
    }
    m->req = b;
    if (b == 0xFF) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        if (task->curBox == task->heldSlot) {
            m->e[1].id = t;
            m->e[1].slot = t;
            m->e[1].src = t;
            m->e[1].used = 1;
        }
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[0]));
        return 0;
    }
    if ((a == b && (a >= 0x1E || task->curBox == task->heldSlot)) || BOX2_MAIN_HandleMonPickup((BoxTask *)task, a, b) == 0) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[0]));
        return 0;
    }
    m->a = a;
    m->b = b;
    n = POKEPARTY_GetCount(task->params->party);
    if (b >= 0x24) {
        m->e[0].id = 0x24;
        m->e[0].slot = b;
        m->e[0].src = 0x24;
        m->e[0].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[0]));
        if (a >= 0x1E) {
            for (i = a - 0x1D; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                BOX2_MAIN_UpdateMoverY((BoxTask *)task, (BoxMover *)e);
            }
            e = &m->e[n];
            t = a;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_UpdateMoverY((BoxTask *)task, (BoxMover *)e);
        }
        return 1;
    }
    if (task->curBox != task->heldSlot && a < 0x1E) {
        if (b >= 0x1E && b > n + 0x1E)
            b = n + 0x1E;
        m->e[0].id = 0x24;
        t = b;
        m->e[0].slot = t;
        m->e[0].src = a;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 2;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[0]));
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[1]));
        return 1;
    }
    if (a < 0x1E) {
        if (b < 0x1E)
            BOX2_MAIN_StepMover((BoxTask *)task, a, b);
        else if (b - 0x1E < n)
            BOX2_MAIN_StepMover((BoxTask *)task, a, b);
        else
            BOX2_MAIN_StepMover((BoxTask *)task, a, n + 0x1E);
    } else if (b < 0x1E) {
        if (BOX2_MAIN_GetPartyValueAt((void ***)task, b, task->curBox, 0xA9, 0) != 0) {
            BOX2_MAIN_StepMover((BoxTask *)task, a, b);
        } else {
            unsigned k = a - 0x1E;
            for (i = k + 1; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)e);
            }
            m->e[k].id = 0x24;
            m->e[k].slot = b;
            m->e[k].src = a;
            m->e[k].used = 1;
            BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[k]));
            e = &m->e[n];
            t = b;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)e);
        }
    } else if (b - 0x1E < n) {
        BOX2_MAIN_StepMover((BoxTask *)task, a, b);
    } else {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = n + 0x1D;
        m->e[k].src = a;
        m->e[k].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[k]));
    }
    return 1;
}

/*
 * Sibling of src/matched/BOX2_MAIN_MoveCursorWithMon.c.
 */
void BOX2_MAIN_SwapWithNeighbour(BoxTask *task, unsigned a, unsigned b)
{
    BoxMove *m = task->work->seq.entry;
    unsigned i;
    unsigned n;
    unsigned short t;
    BoxMover *e;
    for (i = 0; i < 7; i++) {
        m->e[i].id = 0;
        m->e[i].slot = 0;
        m->e[i].src = 0;
        m->e[i].used = 0;
    }
    if (b == 0xFF || BOX2_MAIN_ComparePartyValue((unsigned char *)task, a, b) == 0) {
        m->a = 0xFF;
        m->b = 0xFF;
        m->e[0].id = 0x24;
        t = a;
        m->e[0].slot = t;
        m->e[0].src = t;
        m->e[0].used = 1;
        m->e[1].id = t;
        m->e[1].slot = t;
        m->e[1].src = t;
        m->e[1].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)(&m->e[0]));
        return;
    }
    m->a = a;
    m->b = b;
    n = POKEPARTY_GetCount(task->params->party);
    if (b < 0x1E) {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_UpdateMoverX((BoxTask *)task, (BoxMover *)e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = b;
        m->e[k].src = a;
        m->e[k].used = 1;
        BOX2_MAIN_UpdateMoverX((BoxTask *)task, (BoxMover *)(&m->e[k]));
        e = &m->e[n];
        t = b;
        e->id = t;
        e->slot = n + 0x1D;
        e->src = t;
        e->used = 1;
        BOX2_MAIN_UpdateMoverX((BoxTask *)task, (BoxMover *)e);
    }
}






/*
 * Clears the seven move slots, then either starts a slide from a to b or,
 * when b is not a movable box, snaps to it.
 */
void BOX2_MAIN_SetMoverTarget(BoxTask *task, int a, int b)
{
    BoxMover *o = task->work->seq.entry;
    unsigned i;
    for (i = 0; i < 7; i++) {
        o[i].id = 0;
        o[i].slot = 0;
        o[i].src = 0;
        o[i].used = 0;
    }
    if (b == 0xFF || BOX2_MAIN_GetPartyValueAt((void ***)task, b, task->curBox, 0xA9, 0)) {
        ((BoxMove *)(o))->a = 0xFF;
        ((BoxMove *)(o))->b = 0xFF;
        o[0].id = 0x24;
        o[0].slot = a;
        o[0].src = a;
        o[0].used = 1;
        o[1].id = a;
        o[1].slot = a;
        o[1].src = a;
        o[1].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)((BoxMover *)o));
    } else {
        ((BoxMove *)(o))->a = a;
        ((BoxMove *)(o))->b = b;
        BOX2_MAIN_StepMover((BoxTask *)task, a, POKEPARTY_GetCount(task->params->party) + 0x1E);
    }
}

int BOX2_MAIN_FindMoverSlot(BoxTask *task, unsigned id)
{
    BoxMover *e = task->work->seq.entry;
    unsigned i;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0 && id == e[i].id)
            return e[i].slot;
    }
    return task->cursorSlot;
}

void BOX2_MAIN_StartMover(BoxTask *task,unsigned a)
{
    BoxMover *o;
    unsigned i;
    unsigned slot;
    o=task->work->seq.entry;
    slot=a-30;
    for(i=0;i<6;i++){
        o[i].id=i+30;
        o[i].slot=i+30;
        o[i].src=i+30;
        o[i].used=0;
    }
    o[i].used=0;
    for(i=slot+1;i<6;i++){
        o[i].slot=i+29;
        o[i].used=1;
        BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)((BoxMover *)(&o[i])));
    }
    o[slot].slot=35;
    o[slot].used=1;
    BOX2_MAIN_AdvanceMover((BoxTask *)task, (BoxMover *)((BoxMover *)(&o[slot])));
}

void BOX2_MAIN_SetMoverEntry(BoxTask *task, BoxMover *e)
{
    unsigned char buf[7];
    unsigned short i;
    unsigned short save = 0xFFFF;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0)
            buf[i] = task->work->cursorTable[e[i].src];
    }
    for (i = 0; i < 7; i++) {
        if (e[i].used == 0)
            continue;
        if (e[i].slot <= 0x24) {
            task->work->cursorTable[e[i].slot] = buf[i];
            if (e[i].id == 0x24)
                save = e[i].slot;
        } else {
            task->work->cursorTable[0x24] = buf[i];
            if (e[i].id == 0x24)
                save = 0x24;
        }
    }
    if (save != 0xFFFF)
        BOX2_SEQ_SwapSlotActorsB((unsigned char *)((BoxWork *)task->work), save);
    for (i = 0; i < 0x24; i++)
        BOX2_SEQ_SetSlotDrawPriority((char *)((BoxWork *)task->work), i, 1);
}

/*
 * Return -1.
 */
int BOX2_MAIN_GetMinusOne(unsigned short a)
{
    return -1;
}





void BOX2_MAIN_ResetMovers(BoxTask *task)
{
    BoxActorScale *s;
    void *m;
    unsigned i;
    int r;
    task->work->scroll=GFL_HEAP_Alloc(0x804c,sizeof(BoxActorScale),0,d_021F1400,0xa70);
    s=task->work->scroll;
    s->actor=((BoxTask *)task)->work->actors[task->work->cursorTable[task->cursorSlot]];
    s->index=0;
    s->flags=0;
    m=BOX2_MAIN_GetMonAt((void ***)task,task->curBox,task->cursorSlot);
    for(i=0;i<4;i++){
        r=BOX2_MAIN_GetMinusOne((unsigned short)POKE_TOOL_GetBoxValue((void *)m,i+0x36,0));
        if(r!=-1){s->flags|=(unsigned char)(1<<r);return;}
    }
}

/*
 * Tail call GFL_HEAP_Free with the pooled-offset word.
 */
void BOX2_MAIN_DeleteScroll(BoxTask *task)
{
    GFL_HEAP_Free((void *)task->work->scroll);
}

/*
 * lever: Spell the byte-mask update as plain assignment; compound assignment inserts an extra truncation pair.
 */
int BOX2_MAIN_StepScroll(BoxTask *task)
{
    BoxActorScale *s=task->work->scroll;
    unsigned short n=s->index;
    unsigned j,i;
    void *m;
    int box,r,slot;
    if(n==726)return 0;
    for(j=0;j<15;j++){
        if(n<720){
            box=n/30;
            slot=n%30;
            if(box==task->curBox&&slot==task->cursorSlot) m=0;
            else m=BOX2_MAIN_GetMonAt((void ***)task,box,slot);
        }else{
            slot=n-720;
            if(slot==task->cursorSlot-30)m=0;
            else m=BOX2_MAIN_GetMonAt((void ***)task,255,slot);
        }
        if(m&&POKE_TOOL_GetBoxValue((void *)m,0xa9,0)!=0){
            for(i=0;i<4;i++){
                r=BOX2_MAIN_GetMinusOne((unsigned short)POKE_TOOL_GetBoxValue((void *)m,i+0x36,0));
                if(r!=-1)s->flags=s->flags & (255^(1<<r));
            }
        }
        ++s->index;
        n=s->index;
        if(n==726)return 0;
    }
    return 1;
}

/*
 *   GAME_DATA_GetPerapVoiceSave ((void *)0x02012F98) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void BOX2_MAIN_ClearPerapVoiceIfNoChatot(int *q)
{
    int *r = *(int * *)&((BoxTask *)(q))->params;

    if ((((unsigned int)((BoxParam *)(r))->mode) - 4) > 1)
        PERAPVOICE_ClearIfNoChatot((struct PerapVoice *)GAME_DATA_GetPerapVoiceSave((void *)(((BoxParam *)(r))->gameData)), (void *)(((BoxParam *)(r))->party));
}

void BOX2_MAIN_StartHandMotionToSlot(BoxTask *task, int slot, unsigned idx, int mode, int flag)
{
    BoxMotor *o = task->work->seq.entry;
    short pos[2];
    short to[2];
    int d;
    BOX2_SEQ_GetActorSurfacePos((char *)task->work,10,(short *)&pos[1],(short *)&pos[0],0);
    BOX2_SEQ_GetSlotPos(idx,&to[1],&to[0],mode);
    if(flag==1){to[1]+=8;to[0]+=8;}else{to[0]+=4;}
    o->idx=idx;
    o->slot=slot;
    ((BoxMotorFlags *)(o))->flags&=3;
    o->mode=mode;
    {
        int tx=to[1];
        int px=pos[1];
        int ty;
        int py;
        if(px>tx){o->left=1;d=px-tx;}else{o->left=0;d=tx-px;}
        o->vx=(d<<8)/8;
        ty=to[0];
        py=pos[0];
        if(py>ty){((BoxMotorFlags *)(o))->flags|=2;d=py-ty;}
        else{((BoxMotorFlags *)(o))->flags&=~2;d=ty-py;}
        o->vy=(d<<8)/8;
        o->x=px<<8;
        o->y=py<<8;
    }
}

void BOX2_MAIN_StartHandMotionToBoxArrow(BoxTask *task, int mode)
{
    BoxMotor *o = task->work->seq.entry;
    short pos[2];
    short to[2];
    int d;
    BOX2_SEQ_GetActorSurfacePos((char *)task->work, 10, (short *)&pos[1], (short *)&pos[0], 0);
    if (task->curBox > task->heldSlot)
        BOX2_SEQ_GetActorSurfacePos((char *)task->work, 0, (short *)&to[1], (short *)&to[0], 0);
    else
        BOX2_SEQ_GetActorSurfacePos((char *)task->work, 1, (short *)&to[1], (short *)&to[0], 0);
    o->idx = 0xFF;
    o->slot = 0xFF;
    (*(unsigned *)((char *)(o) + 0x18)) &= 3;
    o->mode = mode;
    {
        int tx = to[1];
        int px = pos[1];
        int ty;
        int py;
        if (px > tx) {
            o->left = 1;
            d = px - tx;
        } else {
            o->left = 0;
            d = tx - px;
        }
        o->vx = (d << 8) / 8;
        ty = to[0];
        py = pos[0];
        if (py > ty) {
            (*(unsigned *)((char *)(o) + 0x18)) |= 2;
            d = py - ty;
        } else {
            (*(unsigned *)((char *)(o) + 0x18)) &= ~2;
            d = ty - py;
        }
        o->vy = (d << 8) / 8;
        o->x = px << 8;
        o->y = py << 8;
    }
}

/*
 * Same call with the fifth argument fixed to 1.
 */
void BOX2_MAIN_StartHandMotionToBoxSlot(BoxTask *a, int b, int c, int d)
{
    BOX2_MAIN_StartHandMotionToSlot(a, b, c, d, 1);
}

void BOX2_MAIN_StartHandMotionToTargetBoxSlot(BoxTask *task, int a, int b)
{
    BOX2_MAIN_StartHandMotionToSlot((BoxTask *)task, task->work->targetBox, a, b, 0);
}







/*
 * extent: final two bytes are zero alignment padding.
 */
int BOX2_MAIN_StepHandMotion(BoxTask *task, int a)
{
    Motion *m;
    m = task->work->seq.entry;
    if (m->count == 8) {
        if (m->index != 255) {
            if (a == 1)
                BOX2_SEQ_MoveActorToSlot((char *)task->work, m->index, m->value);
            else
                BOX2_SEQ_MoveActorToSlotB((char *)task->work, m->index, m->value);
        }
        BOX2_SEQ_LayoutHandSlots((char *)task->work);
        return 0;
    }
    if (m->dirX == 0)
        m->x += m->dx;
    else
        m->x -= m->dx;
    if (m->dirY == 0)
        m->y += m->dy;
    else
        m->y -= m->dy;
    BOX2_SEQ_MoveActor(task->work, (short)(m->x >> 8), (short)(m->y >> 8));
    BOX2_SEQ_LayoutHandSlots((char *)task->work);
    m->count++;
    return 1;
}

/*
 * Set the flag on the object.
 */
int BOX2_MAIN_StepHandMotionToSlot(BoxTask *a)
{
    return BOX2_MAIN_StepHandMotion(a, 1);
}

/*
 * Steps the object with mode 0 (sibling of BOX2_MAIN_StepHandMotionToSlot, which passes 1).
 */
int BOX2_MAIN_StepHandMotionToSlotB(unsigned char *task)
{
    return BOX2_MAIN_StepHandMotion((BoxTask *)task, 0);
}

/*
 * Add the 3rd/4th parameter to the signed byte at +0x19 and fold the
 * +0x15 field in: add it when negative (signed), subtract it when the
 * result is at or above the unsigned byte.
 */
unsigned char BOX2_MAIN_WrapOffset(unsigned char *task, int a)
{
    signed char v = (signed char)((BoxTask *)task)->prevBox + a;
    if (v < 0)
        v = v + (signed char)((BoxTask *)task)->boxLimit;
    else if (v >= ((BoxTask *)task)->boxLimit)
        v = v - (signed char)((BoxTask *)task)->boxLimit;
    return v;
}

void BOX2_MAIN_LoadBgCharTile(void *a, int b, u32 c)
{
    void *out;
    void *r;

    r = ARC_UTIL_LoadBgCharDataFromArchive(0x74, b + 0xe, 1, (void *)(&out), 0x4c);
    BG_SYS_LoadTileData(3, (const void *)(((BoxArcTile *)(out))->data), ((BoxArcTile *)(out))->size, c);
    GFL_HEAP_Free((void *)r);
}

/*
 * Tail wrapper: builds the 6-argument NitroSystem call with the
 *   two stack words 0x20 and 0x4c; third argument shifted left 5.
 */
void BOX2_MAIN_LoadBgPaletteTile(void *a, int b, int c)
{
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x74, b + 0x26, 0, c << 5, 0x20, 0x4c);
}

/*
 * abi: Original truncates the tile column into r2 before both call kinds, so their column parameters are u8.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`data=(u32)sheet;` before `data=(u32)sheet+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT in
 * --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 */
void BOX2_MAIN_LoadBgTileSet(void *unused, int unused2, int x, u32 base, u32 pal)
{
    u8 *sheet;
    void *handle;
    u16 value;
    uptr data;
    u8 row,yn;
    u16 *src;
    u32 cur,high;
    u8 col;
    handle=ARC_UTIL_LoadPaletteDataFromArchive(116,13,1,(void *)&sheet,76);
    data=(uptr)sheet+12;
    row=0;
    high=pal<<12;
    do{
        src=(u16 *)data+row*21;
        cur=x;
        col=0;
        yn=row+1;
        do{
            value=(src[col]&4095)+high+base;
            BG_SYS_DrawTile(3,&value,(u8)cur,yn,1,1);
            ++cur;if(cur>=64)cur=0;
            ++col;
        }while(col<21);
        ++row;
    }while(row<20);
    GFL_HEAP_Free((void *)handle);
    BG_SYS_SetTileEntry(3,0xe287,cur,0,2,20,17);
    BG_SYS_SetTileEntry(3,0xe2b0,cur,5,2,1,17);
}

void BOX2_MAIN_LoadBgTiles(void *a, int b, int c, u32 d, int e)
{
    BOX2_MAIN_LoadBgCharTile(a, b, d);
    BOX2_MAIN_LoadBgPaletteTile(a, b, e);
    BOX2_MAIN_LoadBgTileSet(a, b, c, d, e);
    BG_SYS_MarkTileDirty(3);
}

void BOX2_MAIN_SetBoxScroll(BoxTask *task, int a, int dir)
{
    u32 d; int e, i;
    BoxWork *q;
    if (dir == 0) {
        task->work->scrollOffset -= 0x17;
        if (task->work->scrollOffset < 0)
            task->work->scrollOffset += 0x40;
    } else if (dir == 1) {
        task->work->scrollOffset += 0x17;
        if (task->work->scrollOffset >= 0x40)
            task->work->scrollOffset -= 0x40;
    }
    q = task->work;
    if (((BoxWork *)q)->scrollDir == 0) {
        d = 0x25C;
        e = 0xE;
    } else {
        d = 0xB8;
        e = 0xF;
    }
    ((BoxWork *)q)->scrollDir ^= 1;
    BOX2_MAIN_LoadBgTiles(task, a, task->work->scrollOffset, d, e);
    if (dir == 2) {
        BOX2_SEQ_DrawBoxName((char **)task, (unsigned char)task->curBox, 7);
        BOX2_UI_SetSlotOamEnabled((BoxWork *)task->work, 8, 0);
        return;
    }
    i = 7;
    if (BOX2_UI_GetSlotOamEnabled(task->work, 7) == 1)
        i = 8;
    BOX2_SEQ_DrawBoxName((char **)task, (unsigned char)task->curBox, i);
    BOX2_UI_MoveSlotOam((BoxWork *)task->work, i, dir);
    BOX2_UI_SetSlotOamEnabled((BoxWork *)task->work, i, 1);
}








void BOX2_MAIN_LoadBoxPalette(BoxTask *task, int a)
{
    u32 offset;
    int bank;
    if (task->work->scrollDir == 0) {
        offset = 0x25C;
        bank = 14;
    } else {
        offset = 0xB8;
        bank = 15;
    }
    task->work->scrollDir ^= 1;
    BOX2_MAIN_LoadBgCharTile(task, a, offset);
    PALANM_LoadArcPaletteToSlot(task->work->palAnm, 0x74, a + 0x26, 0x4C, 0, 0x20, bank << 4);
    BOX2_MAIN_LoadBgTileSet(task, a, task->work->scrollOffset, offset, bank);
    BG_SYS_MarkTileDirty(3);
}

/*
 * Forward the second word of the head object.
 */
int BOX2_MAIN_GetBoxWallpaper(BoxTask *task, int box)
{
    return BOX_SAVEDATA_GetWallpaper((struct GameData *)(task->params->boxSave), box);
}

/*
 * Allocates the 0x1C-byte summary of a Pokemon (species, form, PID,
 * markings, level, flags, four moves); NULL for an empty slot.
 */
Summary *BOX2_MAIN_CreateSummary(void *mon)
{
    Summary *s;
    unsigned i;

    if (POKE_TOOL_GetBoxValue((void *)mon, 0xA9, 0) != 0) {
        s = GFL_HEAP_Alloc(0x4C, sizeof(Summary), 0, d_021F1400, 0xCD2);
        s->mon = mon;
        s->species = POKE_TOOL_GetBoxValue((void *)mon, 5, 0);
        s->form = POKE_TOOL_GetBoxValue((void *)mon, 6, 0);
        s->pid = POKE_TOOL_GetBoxValue((void *)mon, 0, 0);
        s->cC = POKE_TOOL_GetBoxValue((void *)mon, 0xAE, 0);
        s->cD = POKE_TOOL_GetBoxValue((void *)mon, 0xAF, 0);
        s->cE = POKE_TOOL_GetBoxValue((void *)mon, 0xA, 0);
        s->cF = POKE_TOOL_GetBoxNature(mon);
        s->item = POKE_TOOL_GetBoxValue((void *)mon, 0xB, 0);
        s->level = POKE_TOOL_GetBoxValue((void *)mon, 0x9E, 0);
        s->egg = (unsigned char)POKE_TOOL_GetBoxValue((void *)mon, 0x4C, 0);
        if (s->egg == 0)
            s->gender = POKE_TOOL_GetBoxGender(mon);
        else
            s->gender = 0;
        if (POKE_TOOL_IsBoxShiny((void *)mon) == 1)
            s->shiny = 1;
        else
            s->shiny = 0;
        if (POKERUS_IsBoxInfected(mon) == 1)
            s->mark = 1;
        else if (POKERUS_IsBoxCured(mon) == 1)
            s->mark = 2;
        else
            s->mark = 0;
        if (s->species != 0x1D && s->species != 0x20 && s->egg == 0)
            s->showgender = 1;
        else
            s->showgender = 0;
        for (i = 0; i < 4; i++)
            s->moves[i] = POKE_TOOL_GetBoxValue((void *)mon, 0x36 + i, 0);
    } else {
        s = 0;
    }
    return s;
}

void BOX2_MAIN_DeleteHandle(void *s)
{
    GFL_HEAP_Free((void *)s);
}

/*
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */
void BOX2_MAIN_SetupSummary(BoxTask *task, struct Summary *a)
{
    BOX2_SEQ_LoadMonIconActor((char *)task, (void **)a, 0xb);
    BOX2_SEQ_ShowHandSlotB((struct BoxWork *)((BoxWork *)task->work), (unsigned char *)a);
    BOX2_SEQ_DeleteTextEntries((BoxTask *)task, (void *)a);
    BOX2_MAIN_SetBodySlots((char *)task, ((Summary *)(a))->item);
    BOX2_MAIN_SetupSummaryActors(task->work, (Summary *)a);
    BG_SYS_ChangeScroll(5, 3, 0);
}

int BOX2_MAIN_RefreshMonInfo(char *task, int a, unsigned b)
{
    void *mon;
    int state;
    void *s;
    mon = BOX2_MAIN_GetMonAt((void ***)task, a, b);
    if (mon) {
        state = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)((struct Sav *)mon));
        s = BOX2_MAIN_CreateSummary(mon);
        if (s) {
            BOX2_MAIN_SetupSummary((BoxTask *)task, (struct Summary *)s);
            BOX2_MAIN_DeleteHandle(s);
            POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)((struct Sav *)mon), state);
        } else {
            BOX2_MAIN_ResetBoxView((BoxTask *)task);
            POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)((struct Sav *)mon), state);
            return 0;
        }
    } else {
        BOX2_MAIN_ResetBoxView((BoxTask *)task);
        return 0;
    }
    return 1;
}

/*
 * Forward with the byte field at +0x14.
 */
void BOX2_MAIN_RefreshCurrentBoxMonInfo(BoxTask *task, int b)
{
    BOX2_MAIN_RefreshMonInfo((char *)task, task->curBox, b);
}

void BOX2_MAIN_SetBoxForm(BoxTask *task, unsigned b)
{
    void *mon;
    void *s;
    int state;
    mon = BOX2_MAIN_GetMonAt((void ***)task, task->curBox, b);
    state = POKE_TOOL_DecodeBoxParam((struct BoxPokemon *)((struct Sav *)mon));
    s = BOX2_MAIN_CreateSummary(mon);
    BOX2_SEQ_LoadMonIconActor((char *)task, (void **)s, 11);
    BOX2_SEQ_ShowHandSlotB((struct BoxWork *)((BoxWork *)task->work), (unsigned char *)s);
    BOX2_SEQ_DeleteTextEntries((BoxTask *)task, (void *)(s));
    BOX2_MAIN_DeleteHandle(s);
    POKE_TOOL_EncodeBoxParam((struct BoxPokemon *)((struct Sav *)mon), state);
}




void BOX2_MAIN_ResetBoxView(BoxTask *task)
{
    unsigned i;
    if (task->work->actors[11] != 0)
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 0xB, 0);
    if (task->work->actors[12] != 0)
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 0xC, 0);
    for (i = 0x1C; i < 0x2D; i++)
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), i, 0);
    BOX2_SEQ_ClearTextWin(task->work);
    BOX2_MAIN_HideSlots((BoxWork *)task->work);
    BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 0x19, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 0x1A, 0);
    BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 0x1B, 0);
    BG_SYS_ChangeScroll(5, 3, 0xC0);
}

/*
 * Reset, clear the state, mark the 0x16 field.
 */
void BOX2_MAIN_ClearCursorBox(unsigned char *task)
{
    BOX2_MAIN_ResetBoxView((BoxTask *)task);
    BOX2_SEQ_SetSlotDim((char **)task, 0);
    ((BoxTask *)task)->cursorSlot = 0xff;
}

void BOX2_MAIN_SetSceneSlots(char *task,int base,u32 bits) { u16 i,v;for(i=0;i<6;i++){if(bits & (1<<i))v=i*2+1;else v=i*2;BOX2_SEQ_SetActorAnimSeq((char *)(((BoxTask *)task)->work),base+i,v);BOX2_SEQ_SetActorDrawEnable((char *)(((BoxTask *)task)->work),base+i,1);} }

void BOX2_MAIN_SetHandSlots(char *task, int bits)
{
    BOX2_MAIN_SetSceneSlots((char *)task, 0xd, bits);
}

/*
 * Forward with index 19.
 */
void BOX2_MAIN_SetBodySlots(char *task, int bits)
{
    BOX2_MAIN_SetSceneSlots((char *)task, 0x13, bits);
}

/*
 * Seat the six 0x13 entries.
 */
void BOX2_MAIN_HideSlots(BoxWork *work)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)work), i + 0x13, 0);
}

void BOX2_MAIN_SetupSummaryActors(BoxWork *w, Summary *s)
{
    if (s->shiny == 0 || s->egg == 1)
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 25, 0);
    else
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 25, 1);
    if (s->mark == 0) {
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 26, 0);
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 27, 0);
    } else if (s->mark == 1) {
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 26, 0);
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 27, 1);
    } else {
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 26, 1);
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)w), 27, 0);
    }
}

/*
 * Signed containment test: 1 when a is inside [r[0],r[1]] and b
 *   inside [r[2],r[3]).  Return-1 arm is the fall-through.
 */
int BOX2_MAIN_HitRect(int a, int b, unsigned char *r)
{
    if (a >= r[0] && a <= r[1] && b >= r[2] && b < r[3])
        return 1;
    return 0;
}

int BOX2_MAIN_HitBoxGrid(short x, int y)
{
    if (BOX2_MAIN_HitRect(x, y, (unsigned char *)d_021EF798) == 1) {
        if (x < 0xC)
            x = 0;
        else if (x >= 0x9C)
            x = 5;
        else
            x = (short)((x - 0xC) / 0x18);
        y -= 0x28;
        return x + (short)(y / 0x18) * 6;
    }
    return 0xFF;
}

/*
 * Scan the six 4-byte entries of the third argument; the first one that
 * BOX2_MAIN_HitRect accepts returns i + 0x1e, else 0xff.
 */
int BOX2_MAIN_HitPartySlots(short x, short y, const unsigned char *r)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        if (BOX2_MAIN_HitRect(x, y, (unsigned char *)((const int *)r + i)) == 1)
            return i + 0x1e;
    return 0xff;
}

/*
 * Wrap the -1/0xff query into the 0xc0..0xff window and hand the
 *   wrapped value back; 0xff is the error.  The three byte fields are
 *   unsigned char (ldrb) and the comparison is unsigned (blo).
 */
int BOX2_MAIN_HitPartyGrid(BoxTask *task, short x, short y)
{
    int v = BOX2_UI_GetGridSlotPoint(task->work->cursorX,
                          task->work->cursorY);
    unsigned w;
    if (v == 0xff)
        return v;
    w = v - 0x24 + task->prevBox;
    if (w >= task->boxLimit)
        w -= task->boxLimit;
    if (w == task->curBox)
        return 0xff;
    return v;
}

int BOX2_MAIN_PushPartyScene(BoxTask *task)
{
    PStatusProcParam *r;
    unsigned mode;
    r = GFL_HEAP_Alloc(0x4B, sizeof(PStatusProcParam), 0, d_021F1400, PM_SRC_LINE(0xEAC, 0xEA9));
    if (task->cursorSlot < 30) {
        r->ppd = BOX2_MAIN_GetMonAt((void ***)task, task->heldSlot, 0);
        r->ppt = 2;
        r->max = 30;
        r->pos = task->cursorSlot;
    } else {
        r->ppd = ((BoxTask *)task)->params->party;
        r->ppt = 1;
        r->max = POKEPARTY_GetCount(((BoxTask *)task)->params->party);
        r->pos = task->cursorSlot - 30;
    }
    mode = 0;
    r->page = 0;
    r->config = ((BoxTask *)task)->params->gameData;
    r->callerData = ((BoxTask *)task)->params->config;
    r->isNationalDex = ((BoxTask *)task)->params->natDex;
#if LANGUAGE == LANGUAGE_JAPANESE
    r->mode = mode;
#else
    if (((BoxTask *)task)->params->linkMode == 1) {
        r->mode = 6;
    } else {
        r->mode = 0;
    }
#endif
    PROCSYS_Push((void *)task->procSys, (sptr)ov131_id, (const struct ProcData *)gPokeStatusProcData, r);
    *(PStatusProcParam * *)&task->subArgs = r;
    return 0;
}

/*
 * Clamp p[0x16] to 0x1e below the limit of the p+0xc object's
 *   byte 0xf, then hand the object to the SDK.  The callee argument is the
 *   re-read expression, not the local, which is why the image re-loads it.
 */
int BOX2_MAIN_PushPartySceneB(BoxTask *task)
{
    PStatusProcParam *q = ((BoxTask *)(task))->subArgs;
    if (task->handMode == 0) {
        if (task->cursorSlot < 0x1e)
            task->cursorSlot = q->pos;
        else
            task->cursorSlot = q->pos + 0x1e;
    }
    GFL_HEAP_Free((void *)(((BoxTask *)(task))->subArgs));
    return 0;
}

int BOX2_MAIN_PushBagScene(void **task)
{
    void *r = BAG_PARAM_Create((const struct BigObj *)((BoxTask *)task)->params->gameData, 0, 2, 0x4b);

    PROCSYS_Push(((BoxTask *)task)->procSys, (uptr)ov070_id, (const struct ProcData *)(void *)0x021bb96c, r);
    ((BoxTask *)task)->subArgs = r;
    return 0;
}

/*
 * Mirror a word into a halfword field, forward, return 0.
 */
int BOX2_MAIN_PopSubArgs(BoxTask *task)
{
    char *q = *(char * *)&task->subArgs;

    ((BoxTask *)(task))->subResult = ((BagParam *)(q))->itemId;
    GFL_HEAP_Free((void *)q);
    return 0;
}

/*
 * data: callback descriptor belongs to ov194 loaded by PROCSYS_Push.
 */
int BOX2_MAIN_PushNameScene(BoxTask *task)
{
    void *value;
    NameInRequest *r;
    value = MISC_GetBlock(GAME_DATA_GetSaveControl(((BoxTask *)task)->params->gameData));
    r = GFL_HEAP_Alloc(0x4B, sizeof(NameInRequest), 1, d_021F1400, PM_SRC_LINE(0xF1F, 0xF13));
    r->text = STRBUF_Create(20, 0x4B);
    BOX_SAVEDATA_GetBoxName(((BoxTask *)task)->params->boxSave, task->curBox, r->text);
    r->task = NAMEIN_SETUP_CreateArgs(0x4B, 2, 0, 0, 8, (struct Strbuf *)r->text, value);
    PROCSYS_Push((void *)task->procSys, (sptr)ov194_id, (const struct ProcData *)gNameInProcData, r->task);
    *(NameInRequest * *)&task->subArgs = r;
    return 0;
}



int BOX2_MAIN_PopNameScene(u8 *task){char **q;q=*(char ** *)&((BoxTask *)task)->subArgs;if(((BoxNameArgs *)((*q)))->done==0)BOX_SAVEDATA_SetBoxName(((BoxTask *)task)->params->boxSave,((BoxTask *)task)->curBox,((BoxNameArgs *)((*q)))->text);((BoxTask *)task)->subResult=((BoxNameArgs *)((*q)))->done;NAMEIN_SETUP_FreeArgs((struct NameInArgs *)*q);STRBUF_Delete((struct Strbuf *)q[1]);GFL_HEAP_Free(((BoxTask *)task)->subArgs);return 0;}

void BOX2_MAIN_MoveCursorActor(BoxTask *task, int x, int y)
{
    BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), task->work->cursorTable[0x24], (short)x, (short)((short)y - 8), 0);
    BOX2_SEQ_MoveCursorToSlot((char *)task->work, 0x24);
    task->work->cursorX = x;
    task->work->cursorY = y;
}

int BOX2_MAIN_StateMachinePick(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    int busy = BOX2_UI_UpdateBarMove((BoxTask *)task);
    unsigned r = BOX2_UI_UpdateListPacks(task->work->winMgr);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(task->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            task->work->touchState = 0;
            b->timer = 0;
            r = 0xFF;
            if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
                BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
                r = BOX2_MAIN_HitPartyGrid((BoxTask *)task, task->work->cursorX, task->work->cursorY);
                if (r == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, r) == 0) {
                    BOX2_UI_CloseInfoBar(task->work->winMgr);
                    GFL_USE_PlaySeDefaultVolume(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1) {
                r = BOX2_MAIN_HitPartySlots(task->work->cursorX, task->work->cursorY, d_021EF79C);
                if (r == 0xFF)
                    r = BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY));
            }
            if (BOX2_UI_IsTopBarClosed(task->work->winMgr) == 1)
                r = BOX2_MAIN_HitPartySlots(task->work->cursorX, task->work->cursorY, d_021EF7B4);
            if (((BoxTask *)task)->params->mode == 4 && ((BoxTask *)task)->params->linkMode == 1) {
                r = 0xFF;
                task->work->result = 5;
            }
            BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, r);
            if (BOX2_UI_IsListClosed(task->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)task, 0);
            if (r != 0xFF)
                task->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)task, 0x24);
            if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0 && BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 0 && busy == 0)
                BOX2_UI_CloseListPack(task->work->winMgr);
            b->state = 2;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0) {
            if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0 && BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 0 && BOX2_UI_GetPageButtonHit() == 0) {
                task->heldSlot = 0xFF;
                task->phase = 2;
                BOX2_UI_SlideBarIn(task->work->winMgr);
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
                BOX2_UI_ToggleSlotPair((BoxWork *)task->work, 1);
                BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
                if (((BoxTask *)task)->params->mode == 4)
                    CURSOR_MOVE_ClearSkipBit(task->work->cursorMove, 0x27);
                BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 2);
                task->work->heldSlot = task->cursorSlot;
                task->work->waitFrames = 0x17;
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
            if (((BoxTask *)task)->params->mode != 4) {
                if (BOX2_UI_GetPageButtonHit2() != -1) {
                    if (task->work->touchState == 0) {
                        if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
                            BOX2_UI_CloseInfoBar(task->work->winMgr);
                            BOX2_MAIN_SetupWindowFrameFade((BoxTask *)task, 0xA);
                            GFL_USE_PlaySeDefaultVolume(0x54C);
                            GFL_USE_PlaySeDefaultVolume(0x669);
                            task->work->touchState = 1;
                            b->state = 0xB;
                        }
                        if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1) {
                            BOX2_UI_OpenBar(task->work->winMgr);
                            BOX2_MAIN_SetupWindowFrameFade((BoxTask *)task, 0xB);
                            GFL_USE_PlaySeDefaultVolume(0x54C);
                            GFL_USE_PlaySeDefaultVolume(0x669);
                            task->work->touchState = 1;
                            b->state = 0xD;
                        }
                    }
                } else {
                    task->work->touchState = 0;
                }
            }
            if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
                int dir = BOX2_UI_GetExitButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_SelectBox((BoxTask *)task, -1);
                    b->state = 8;
                    b->timer = 0;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_SelectBox((BoxTask *)task, 1);
                    b->state = 9;
                    b->timer = 0;
                }
            }
            if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
                int k = BOX2_UI_GetGridSlotPoint(x, y);
                if (k != 0xFF)
                    BOX2_UI_SetMiniIconVisible((BoxTask *)task, k - 0x24, 1);
                else
                    BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
            }
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
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
    case 8:
        if (BOX2_SEQ_OpenBoxDown((BoxTask *)task) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 9:
        if (BOX2_SEQ_OpenBoxUp((BoxTask *)task) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 10:
        if (BOX2_MAIN_ShiftWindowRight(task) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 11:
        BOX2_MAIN_StepWindowFrameFade(task);
        if (BOX2_MAIN_ShiftWindowLeft(task) == 0) {
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            BOX2_SEQ_HidePartialSlots((char **)task, 1);
            BOX2_UI_HideWindowA((BoxWork *)task->work);
            BOX2_UI_ShowWindowB((BoxWork *)task->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xC;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 12:
        if (busy == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 13:
        BOX2_MAIN_StepWindowFrameFade(task);
        if (busy == 0) {
            BOX2_MAIN_RefreshBoxUi(task);
            BOX2_UI_HideWindowB((BoxWork *)task->work);
            BOX2_UI_ShowWindowA((BoxWork *)task->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xA;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry((BoxTask *)task, (BoxMover *)b->entry);
        if (BOX2_UI_IsTopBarClosed(task->work->winMgr) == 1) {
            BOX2_SEQ_MoveCursorToSlot((char *)task->work, task->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)task, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            CURSOR_MOVE_SetCurrent(task->work->cursorMove, task->cursorSlot);
            BOX2_UI_SetCursorPos((char **)task, task->cursorSlot);
            BOX2_SEQ_SetCursorDraw((char **)task, 1);
        }
        b->state = 0;
        return 0;
    case 14:
        if (BOX2_MAIN_ShiftWindowLeft(task) == 0) {
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (busy == 0) {
            task->phase = 2;
            BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY)));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            b->state = 2;
        }
        break;
    }
    return 1;
}

int BOX2_MAIN_StateMachineScroll(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    int busy = 0;
    unsigned r;
    unsigned x;
    unsigned y;
    if (b->state != 0xA && b->state != 0xB && b->state != 0xE) {
        if (BGWINFRM_IsMoving(task->work->winMgr, 9) == 1)
            busy = BOX2_MAIN_ShiftWindowRight(task);
    }
    r = BOX2_UI_UpdateListPacks(task->work->winMgr);
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(task->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            task->work->touchState = 0;
            r = 0xFF;
            if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
                r = BOX2_MAIN_HitPartyGrid((BoxTask *)task, task->work->cursorX, task->work->cursorY);
                if (task->cursorSlot >= 0x1E && (r == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, r) == 0)) {
                    BOX2_UI_CloseInfoBar(task->work->winMgr);
                    BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
                    GFL_USE_PlaySeDefaultVolume(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1)
                r = BOX2_MAIN_HitPartySlots(task->work->cursorX, task->work->cursorY, d_021EF79C);
            if (r == 0xFF)
                r = BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY));
            if (BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, r) == 0)
                r = 0xFF;
            if (BOX2_UI_IsListClosed(task->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)task, 0);
            if (r != 0xFF) {
                if (r >= 0x24)
                    task->cursorSlot = r - 2;
                else
                    task->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)task, 0x24);
            } else {
                BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
            }
            if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 0 && BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0 && busy == 0)
                BOX2_UI_CloseListPack(task->work->winMgr);
            if (r == 0xFF && task->cursorSlot < 0x1E && task->curBox != task->heldSlot) {
                r = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, task->heldSlot);
                task->curBox = task->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)task, BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), r);
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
        if (busy == 0 && r == 0 && BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 0 && BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0) {
            if (task->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
                task->prevBox = task->curBox;
                BOX2_MAIN_RefreshBoxUi(task);
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_MoveCursor((char **)task, 4, task->cursorSlot);
                BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 2);
                task->work->heldSlot = task->cursorSlot;
                task->work->waitFrames = 0x17;
            }
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
        if (busy == 0 && r == 0) {
            if (BOX2_UI_GetPageButtonHit2() != -1) {
                if (task->work->touchState == 0) {
                    if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
                        BOX2_UI_CloseInfoBar(task->work->winMgr);
                        BOX2_MAIN_SetupWindowFrameFade((BoxTask *)task, 0xA);
                        GFL_USE_PlaySeDefaultVolume(0x54C);
                        GFL_USE_PlaySeDefaultVolume(0x669);
                        task->work->touchState = 1;
                        b->state = 0xB;
                    }
                    if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1) {
                        BOX2_UI_OpenBar(task->work->winMgr);
                        BOX2_MAIN_SetupWindowFrameFade((BoxTask *)task, 0xB);
                        GFL_USE_PlaySeDefaultVolume(0x54C);
                        GFL_USE_PlaySeDefaultVolume(0x669);
                        task->work->touchState = 1;
                        b->state = 0xD;
                    }
                }
            } else {
                task->work->touchState = 0;
            }
        }
        if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
            int dir = BOX2_UI_GetExitButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_SelectBox((BoxTask *)task, -1);
                b->state = 8;
                b->timer = 0;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_SelectBox((BoxTask *)task, 1);
                b->state = 9;
                b->timer = 0;
            }
        }
        if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
            int k = BOX2_UI_GetGridSlotPoint(x, y);
            if (k != 0xFF)
                BOX2_UI_SetMiniIconVisible((BoxTask *)task, k - 0x24, 1);
            else
                BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
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
    case 8:
        if (BOX2_SEQ_OpenBoxDown((BoxTask *)task) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 9:
        if (BOX2_SEQ_OpenBoxUp((BoxTask *)task) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 10:
        if (BOX2_MAIN_ShiftWindowRight(task) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 11:
        BOX2_MAIN_StepWindowFrameFade(task);
        if (BOX2_MAIN_ShiftWindowLeft(task) == 0) {
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            BOX2_SEQ_HidePartialSlots((char **)task, 1);
            BOX2_UI_HideWindowA((BoxWork *)task->work);
            BOX2_UI_ShowWindowB((BoxWork *)task->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xC;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 12:
        if (BOX2_UI_UpdateBarMove((BoxTask *)task) == 0) {
            task->phase = 2;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 13:
        BOX2_MAIN_StepWindowFrameFade(task);
        if (BOX2_UI_UpdateBarMove((BoxTask *)task) == 0) {
            BOX2_MAIN_RefreshBoxUi(task);
            BOX2_UI_HideWindowB((BoxWork *)task->work);
            BOX2_UI_ShowWindowA((BoxWork *)task->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xA;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 14:
        if (BOX2_MAIN_ShiftWindowLeft(task) == 0) {
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (BOX2_UI_UpdateBarMove((BoxTask *)task) == 0) {
            BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY)));
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            b->state = 2;
        }
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry((BoxTask *)task, (BoxMover *)b->entry);
        if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 0 && BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0) {
            BOX2_SEQ_MoveCursorToSlot((char *)task->work, task->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)task, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            CURSOR_MOVE_SetCurrent(task->work->cursorMove, task->cursorSlot);
            BOX2_UI_SetCursorPos((char **)task, task->cursorSlot);
            BOX2_SEQ_SetCursorDraw((char **)task, 1);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}





int BOX2_MAIN_StateMachineOpen(BoxTask *task);

int BOX2_MAIN_StateMachineClose(BoxTask *task);

int BOX2_MAIN_IsWindowMoving(BoxTask *task);

int BOX2_MAIN_UpdateWindowMove(BoxTask *task);

int BOX2_MAIN_StateMachineOpen(BoxTask *task){char *s;s=(char *)&((BoxTask *)task)->work->seq;switch(((BoxSeq *)s)->state){case 0:BOX2_MAIN_StartMover((BoxTask *)task,((BoxTask *)task)->cursorSlot);(((BoxSeq *)s)->state)++;case 1:if(BOX2_MAIN_WaitCursorMove((BoxTask *)task)==0){BOX2_MAIN_SetMoverEntry((BoxTask *)task,*(BoxMover * *)&((BoxSeq *)s)->entry);((BoxSeq *)s)->state=0;return 0;}break;}return 1;}

/*
 * lever: bind the full party-count-plus-30 expression to an int local.
 */
int BOX2_MAIN_StateMachineClose(BoxTask *task)
{
    char *s;
    int count;
    s = (char *)&task->work->seq;
    switch (((BoxSeq *)s)->state) {
    case 0:
        count = POKEPARTY_GetCount(((BoxTask *)task)->params->party) + 30;
        BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, count);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        (((BoxSeq *)s)->state)++;
        break;
    case 1:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)task) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, ((BoxSeq *)s)->entry);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((BoxSeq *)s)->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_MAIN_StepScrollToPrevBox(BoxTask *task)
{
    if (task->work->seq.timer == 0x17) {
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1)
            BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        task->work->seq.timer = 0;
        return 0;
    }
    BG_SYS_ChangeScroll(3, 2, 8);
    BOX2_SEQ_ShiftSlotIcons((char **)task, 8);
    BOX2_UI_ShiftSlotOams((BoxWork *)task->work, 8);
    BOX2_UI_UpdateListPacks(task->work->winMgr);
    (task->work->seq.timer)++;
    return 1;
}

int BOX2_MAIN_StepScrollToNextBox(BoxTask *task)
{
    if (task->work->seq.timer == 0x17) {
        BOX2_SEQ_SetCursorDraw((char **)task, 1);
        if (BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1)
            BOX2_UI_UpdateCurrentBoxMarker((BoxTask *)task);
        task->work->seq.timer = 0;
        return 0;
    }
    BG_SYS_ChangeScroll(3, 1, 8);
    BOX2_SEQ_ShiftSlotIcons((char **)task, -8);
    BOX2_UI_ShiftSlotOams((BoxWork *)task->work, -8);
    BOX2_UI_UpdateListPacks(task->work->winMgr);
    (task->work->seq.timer)++;
    return 1;
}

/*
 * 1 when the p+0x2c+0x74 object is live.
 */
int BOX2_MAIN_IsWindowMoving(BoxTask *task)
{
    if (BOX2_UI_UpdateListPacks(task->work->winMgr) != 0)
        return 1;
    return 0;
}

/*
 * Tail forwarder; following code starts at 021E01B0.
 */
int BOX2_MAIN_UpdateWindowMove(BoxTask *task)
{
    return BOX2_UI_UpdateTopBarMove((BoxTask *)task);
}

int BOX2_MAIN_IsWindowBusy(BoxTask *task)
{
    return BOX2_UI_UpdateBarMove((BoxTask *)task) != 0;
}





int BOX2_MAIN_StateMachineMove(BoxTask *task);

int BOX2_MAIN_ShiftWindowRight(BoxTask *task)
{
    int v = BGWINFRM_UpdateMove(task->work->winMgr, 9);
    BOX2_UI_MoveSlotIcon((struct BoxTask *)task, 8);
    return v;
}

int BOX2_MAIN_ShiftWindowLeft(BoxTask *task)
{
    int x = BGWINFRM_UpdateMove(task->work->winMgr, 9);
    BOX2_UI_MoveSlotIcon((struct BoxTask *)task, -8);
    return x;
}

int BOX2_MAIN_StateMachineMove(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    unsigned r = BOX2_UI_UpdateListPacks(task->work->winMgr);
    int busy = BOX2_UI_UpdateBarMove((BoxTask *)task);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(task->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (BOX2_UI_IsTopBarClosed(task->work->winMgr) == 0)
            BOX2_UI_ToggleSlotPair((BoxWork *)task->work, 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (BOX2_UI_IsTopBarClosed(task->work->winMgr) == 0 && busy == 0)
                r = BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY));
            BOX2_MAIN_SwapWithNeighbour((BoxTask *)task, task->cursorSlot, r);
            if (BOX2_UI_IsListClosed(task->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)task, 0);
            task->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)task, 0x24);
            if (task->cursorSlot < 0x1E) {
                b->state = 6;
            } else {
                if (BOX2_UI_IsTopBarClosed(task->work->winMgr) == 0)
                    GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_CloseBar(task->work->winMgr);
                BOX2_UI_CloseListPack(task->work->winMgr);
                b->state = 4;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (r == 0 && busy == 0) {
            if (BOX2_UI_IsTopBarClosed(task->work->winMgr) == 1) {
                if (BOX2_UI_GetPageButtonHit() == 0) {
                    task->heldSlot = 0xFF;
                    task->phase = 0;
                    BOX2_UI_OpenBar(task->work->winMgr);
                    GFL_USE_PlaySeDefaultVolume(0x669);
                }
            } else if (b->timer == 0) {
                int dir = BOX2_UI_GetCloseButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 0);
                    b->state = 2;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StepToAdjacentBox((BoxTask *)task, 1);
                    b->state = 3;
                }
            }
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 2:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 4:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 5;
        }
        break;
    case 5:
        if (busy == 0 && r == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, b->entry);
            BOX2_SEQ_MoveCursorToSlot((char *)task->work, task->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)task, 1);
            b->state = 8;
        }
        break;
    case 6:
        if (BOX2_MAIN_WaitBoxScroll((BoxTask *)task) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, b->entry);
            BOX2_MAIN_ResetBoxView(task);
            GFL_USE_PlaySeDefaultVolume(0x667);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_CloseBar(task->work->winMgr);
            task->cursorSlot = 0xFF;
            b->state = 7;
        }
        break;
    case 7:
        if (busy == 0)
            b->state = 8;
        break;
    case 8:
        BOX2_UI_ToggleSlotPair((BoxWork *)task->work, 0);
        BOX2_SEQ_SetSlotActors((char *)task, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)task, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}
typedef struct {
    unsigned char x, y, dx, dy;
    unsigned directionX:1;
    unsigned directionY:1;
    unsigned count:30;
} BoxScrollMotion;


int BOX2_MAIN_IsWindowBusy(BoxTask *task);

int BOX2_MAIN_StateMachinePen(BoxTask *task);

int BOX2_MAIN_SceneApplyScroll(BoxTask *task);

int BOX2_MAIN_SceneWaitScroll(BoxTask *task);

void BOX2_MAIN_SceneMoveCursor(BoxTask *task);

int BOX2_MAIN_SceneWaitCursor(BoxTask *task);

int BOX2_MAIN_SceneOpenBox(BoxTask *task);

/*
 * State machine in the 021DFA30 family (template 021E0ABC): pick a box with
 * the pen, slide the cursor there, then close.
 */
int BOX2_MAIN_StateMachinePen(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    int busy = BOX2_UI_UpdateListPacks(task->work->winMgr);
    int wait = BOX2_UI_UpdateBarMove((BoxTask *)task);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(task->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            int r = 0xFF;
            if (BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1)
                r = BOX2_MAIN_HitPartySlots(task->work->cursorX, task->work->cursorY, d_021EF79C);
            BOX2_MAIN_SetMoverTarget((BoxTask *)task, task->cursorSlot, r);
            if (BOX2_UI_IsListClosed(task->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)task, 0);
            task->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)task, 0x24);
            if (task->cursorSlot >= 0x1E) {
                b->state = 5;
                break;
            }
            if (wait == 1 || BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_OpenBar(task->work->winMgr);
            }
            b->state = 2;
            break;
        }
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0 && task->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 2, 1);
            task->work->heldSlot = task->cursorSlot;
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)task, x, y);
        break;
    case 2:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 3;
        }
        if (wait == 0)
            BOX2_UI_CloseListPack(task->work->winMgr);
        break;
    case 3:
        if (wait == 0) {
            BOX2_UI_CloseListPack(task->work->winMgr);
            b->state = 4;
        }
        break;
    case 4:
        if (busy == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, b->entry);
            BOX2_SEQ_MoveCursorToSlot((char *)task->work, task->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)task, 1);
            b->state = 7;
        }
        break;
    case 5:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)task) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, b->entry);
            GFL_USE_PlaySeDefaultVolume(0x667);
            GFL_USE_PlaySeDefaultVolume(0x669);
            task->cursorSlot = 0xFF;
            BOX2_UI_OpenBar(task->work->winMgr);
            b->state = 6;
        }
        break;
    case 6:
        if (wait == 0) {
            BOX2_MAIN_ResetBoxView(task);
            b->state = 7;
        }
        break;
    case 7:
        BOX2_SEQ_SetSlotActors((char *)task, 1, 0);
        BOX2_SEQ_SetSlotActors((char *)task, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_MAIN_SceneApplyScroll(BoxTask *task)
{
    BoxScrollMotion *m;
    short xy[2];
    m = task->work->seq.entry;
    if (m->count == 0) {
        BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), 4, m->x, m->y, 0);
        BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
        return 0;
    }
    m->count--;
    BOX2_SEQ_GetActorSurfacePos((char *)task->work, 4, (short *)&xy[1], (short *)&xy[0], 0);
    if (m->directionX == 0)
        xy[1] += m->dx;
    else
        xy[1] -= m->dx;
    if (m->directionY == 0)
        xy[0] += m->dy;
    else
        xy[0] -= m->dy;
    BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), 4, xy[1], xy[0], 0);
    BOX2_SEQ_RefreshHandSlot((BoxTask *)task);
    return 1;
}

/*
 * 1 unless both queries come back zero.
 */
int BOX2_MAIN_SceneWaitScroll(BoxTask *task)
{
    if (BOX2_MAIN_SceneApplyScroll((BoxTask *)task) == 0 && BOX2_UI_UpdateListPacks(task->work->winMgr) == 0)
        return 0;
    return 1;
}

void BOX2_MAIN_SceneMoveCursor(BoxTask *task)
{
    short xy[2];
    BOX2_SEQ_SetCursorFrame((BoxTask *)task, 8);
    BOX2_SEQ_GetActorSurfacePos((char *)task->work, 4, (short *)&xy[1], (short *)&xy[0], 0);
    BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work), task->work->cursorTable[0x24], (short)xy[1], (short)(xy[0] + 4), (short)0);
    BOX2_SEQ_SetSlotDrawPriority((char *)((BoxWork *)task->work), 0x24, 0);
}

int BOX2_MAIN_SceneWaitCursor(BoxTask *task)
{
    char *s=(char *)&task->work->seq;
    short xy[2];
    int k;
    switch(((BoxSeq *)s)->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task,7);
        (((BoxSeq *)s)->state)++;
    case 1:
        if(((BoxSeq *)s)->timer==4) {
            ((BoxSeq *)s)->timer=0;
            (((BoxSeq *)s)->state)++;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos((char *)task->work,4,(short *)&xy[1],(short *)&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work),4,(short)xy[1],(short)(xy[0]+2),(short)0);
        (((BoxSeq *)s)->timer)++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x666);
        BOX2_SEQ_SetCursorFrame((BoxTask *)task,8);
        (((BoxSeq *)s)->state)++;
    case 3:
        if(((BoxSeq *)s)->timer==4) {
            ((BoxSeq *)s)->timer=0;
            ((BoxSeq *)s)->state=0;
            return 0;
        }
        BOX2_SEQ_GetActorSurfacePos((char *)task->work,4,(short *)&xy[1],(short *)&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work),4,(short)xy[1],(short)(xy[0]-2),(short)0);
        k=task->work->cursorTable[0x24];
        BOX2_SEQ_GetActorSurfacePos((char *)task->work,k,(short *)&xy[1],(short *)&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos((char *)((BoxWork *)task->work),k,(short)xy[1],(short)(xy[0]-2),(short)0);
        BOX2_SEQ_MoveCursorToSlot((char *)task->work,0x24);
        (((BoxSeq *)s)->timer)++;
        break;
    }
    return 1;
}

/*
 * Drop callback while carrying a Pokemon (block at work + 0x58, template
 * BOX2_MAIN_StateMachineScroll): changes box if the cursor sits on another box, then
 * settles the carried icon; returns 0 once the drop is finished.
 */
int BOX2_MAIN_SceneOpenBox(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    int r;

    switch (b->state) {
    case 0:
        if (task->cursorSlot >= 0x1E && BOX2_UI_IsInfoBarOpen(task->work->winMgr) == 1) {
            if (task->work->targetBox < 0x1E || task->work->targetBox == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, task->work->targetBox) == 0) {
                BOX2_UI_SetMiniIconVisible((BoxTask *)task, 0, 0);
                BOX2_UI_CloseInfoBar(task->work->winMgr);
                GFL_USE_PlaySeDefaultVolume(0x669);
                b->state = 5;
                break;
            }
        }
        if (task->cursorSlot < 0x1E && task->curBox != task->heldSlot) {
            if (task->work->targetBox == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, task->work->targetBox) == 0) {
                r = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, task->heldSlot);
                task->curBox = task->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)task, BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), r);
                if (r == 0)
                    b->state = 2;
                else
                    b->state = 3;
                break;
            }
        }
    case 1:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 7);
        BOX2_MAIN_MoveCursorWithMon((BoxTask *)task, task->cursorSlot, task->work->targetBox);
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
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)task) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, b->entry);
            BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
            BOX2_SEQ_SetSlotDim((char **)task, 0);
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 0;
            return 0;
        }
        break;
    case 5:
        if (BOX2_MAIN_ShiftWindowLeft(task) == 0) {
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 6;
        }
        break;
    case 6:
        if (BOX2_MAIN_IsWindowBusy(task) == 0)
            b->state = 1;
        break;
    }
    return 1;
}

typedef struct {
    unsigned short idx;
    unsigned short slot;
} BoxSlotRef;


int BOX2_MAIN_StateMachineRunSwap(BoxTask *task);

int BOX2_MAIN_StateMachineShowHandScroll(BoxTask *task);

int BOX2_MAIN_StateMachineDrag(BoxTask *task);

int BOX2_MAIN_StateMachineHideHandScroll(BoxTask *task);

int BOX2_MAIN_StateMachineHideHandWindow(BoxTask *task);

int BOX2_MAIN_StateMachineHideHand(BoxTask *task);

void BOX2_MAIN_MoveCursorTo(BoxWork *w, int x, int y);

int BOX2_MAIN_StateMachineDragNoBar(BoxTask *task);

int BOX2_MAIN_StateMachineReturnHeld(BoxTask *task);







int BOX2_MAIN_StateMachineRunSwap(BoxTask *task)
{
    char *s;
    s = (char *)&task->work->seq;
    switch (((BoxSeq *)s)->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame((BoxTask *)task, 7);
        BOX2_MAIN_SwapWithNeighbour((BoxTask *)task, task->cursorSlot, task->work->targetBox);
        ((BoxSeq *)s)->state = 1;
        break;
    case 1:
        if (BOX2_MAIN_WaitBoxScroll((BoxTask *)task) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)task, ((BoxSeq *)s)->entry);
            BOX2_SEQ_SetCursorFrame((BoxTask *)task, 6);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((BoxSeq *)s)->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_MAIN_StateMachineShowHandScroll(BoxTask *task)
{
    char *s;
    int a;
    int b;
    s = (char *)&task->work->seq;
    switch (((BoxSeq *)s)->state) {
    case 0:
        if (task->work->counter) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
            BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 1);
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 1);
        }
        (((BoxSeq *)s)->state)++;
    case 1:
        a = BOX2_MAIN_SceneApplyScroll((BoxTask *)task);
        b = BOX2_UI_UpdateListPacks(task->work->winMgr);
        if (a == 0 && b == 0) {
            if (task->work->counter) {
                BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
                BOX2_SEQ_ShowHandSlots((char *)task->work);
            }
            ((BoxSeq *)s)->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

/*
 * Same state-machine family as src/matched/BOX2_MAIN_StateMachineScroll.c.  The spill
 * slots of `first` and `flag` follow declaration order (later declaration,
 * lower address), and the two identical "fall back to p[0x16]" arms are an
 * if/else-if that the compiler tail-merges (bne then b), not one `||`.
 */
int BOX2_MAIN_StateMachineDrag(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    int busy = BOX2_UI_UpdateListPacks(task->work->winMgr);
    int wait = BOX2_UI_UpdateBarMove((BoxTask *)task);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAnim((BoxTask *)task, (short)(((BoxTask *)(task))->work->counter));
        if ((((BoxTask *)(task))->work->counter) != 0) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
            BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 1);
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 1);
            b->state = 1;
        } else {
            BOX2_UI_CloseListPack(task->work->winMgr);
            b->state = 11;
        }
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10) == 1)
            break;
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
        BOX2_SEQ_ShowHandSlots((char *)task->work);
        b->state = 2;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            int back;
            if (wait == 1 || BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1)
                flag = 1;
            else
                flag = 0;
            r = (unsigned short)BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY));
            if (wait == 0 && BOX2_UI_IsTopBarOpen(task->work->winMgr) == 1 && r == 0xFF)
                r = (unsigned short)BOX2_MAIN_HitPartySlots(task->work->cursorX, task->work->cursorY, d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = task->cursorSlot;
                back = 1;
            } else if (BOX2_MAIN_CompareSlots((unsigned char *)task, task->cursorSlot, r) == 0) {
                r = task->cursorSlot;
                back = 1;
            }
            if (flag == 1) {
                BOX2_MAIN_StartHandMotionToBoxSlot((BoxTask *)task, first, r, 2);
                if (back == 1 && task->heldSlot != 0xFF && task->heldSlot != task->curBox) {
                    int dir = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, task->heldSlot);
                    task->curBox = task->heldSlot;
                    BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
                    BOX2_MAIN_SetBoxScroll((BoxTask *)task, BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), dir);
                    if (dir == 0)
                        b->state = 5;
                    else
                        b->state = 6;
                } else {
                    b->state = 7;
                }
            } else {
                BOX2_MAIN_StartHandMotionToBoxSlot((BoxTask *)task, first, r, 0);
                BOX2_UI_CloseListPack(task->work->winMgr);
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen(task->work->winMgr) == 0 && task->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
            BOX2_UI_PutBottomBarClosed(task->work->winMgr);
            BOX2_UI_CloseBar(task->work->winMgr);
            BOX2_SEQ_HidePartialSlots((char **)task, 1);
            BOX2_SEQ_SetSlotActors((char *)task, 0x82, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)task, 6, task->cursorSlot);
            CURSOR_MOVE_ClearSkipBit(task->work->cursorMove, 0x27);
            CURSOR_MOVE_ClearSkipBit(task->work->cursorMove, 0x28);
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 2, 1, 1);
            task->barFlag = 0;
            task->work->cancelFlag = 0;
            task->work->heldSlot = task->cursorSlot;
            task->work->waitFrames = 0x42;
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
        BOX2_MAIN_MoveCursorTo(task->work, x, y);
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(task->work, x, y);
        break;
    case 4:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(task->work, x, y);
        break;
    case 5:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0)
            b->state = 7;
        break;
    case 6:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0)
            b->state = 7;
        break;
    case 7:
        if (BOX2_MAIN_StepHandMotionToSlot((BoxTask *)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 9;
        }
        break;
    case 8:
        if (BOX2_MAIN_StepHandMotionToSlot((BoxTask *)task) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            if ((((BoxTask *)(task))->work->counter) != 0) {
                BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
                BOX2_SEQ_ShowHandSlots((char *)task->work);
            }
            BOX2_UI_DeleteSlotObjects((BoxTask *)task, 0, 0, 1);
            b->state = 11;
        }
        break;
    case 9:
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 2);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        b->state = 10;
        break;
    case 10:
        if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 0);
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
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

int BOX2_MAIN_StateMachineHideHandScroll(BoxTask *task)
{
    char *s;
    int a;
    int b;
    s = (char *)&task->work->seq;
    switch (((BoxSeq *)s)->state) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
            BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 2);
        }
        (((BoxSeq *)s)->state)++;
    case 1:
        a = BOX2_MAIN_SceneApplyScroll((BoxTask *)task);
        b = BOX2_MAIN_IsWindowMoving((BoxTask *)task);
        if (a == 0 && b == 0)
            (((BoxSeq *)s)->state)++;
        break;
    case 2:
        if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 0);
        }
        ((BoxSeq *)s)->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_MAIN_StateMachineHideHandWindow(BoxTask *task)
{
    char *b = (char *)&task->work->seq;
    switch (((BoxSeq *)b)->state) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
            BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 2);
        }
        (((BoxSeq *)b)->state)++;
        /* fall through */
    case 1:
        if (!BOX2_MAIN_IsWindowMoving((BoxTask *)task))
            (((BoxSeq *)b)->state)++;
        break;
    case 2:
        if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 0);
        }
        ((BoxSeq *)b)->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_MAIN_StateMachineHideHand(BoxTask *task)
{
    char *b = (char *)&task->work->seq;
    switch (((BoxSeq *)b)->state) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable((char *)task->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
            BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 2);
        }
        (((BoxSeq *)b)->state)++;
        break;
    case 1:
        if (!BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10)) {
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 0);
        }
        ((BoxSeq *)b)->state = 0;
        return 0;
    }
    return 1;
}

void BOX2_MAIN_MoveCursorTo(BoxWork *w, int x, int y)
{
    BOX2_SEQ_MoveActor(w, (short)x, (short)y);
    BOX2_SEQ_LayoutHandSlots((char *)w);
    w->cursorX = x;
    w->cursorY = y;
}

/*
 * Sibling of src/matched/BOX2_MAIN_StateMachineDrag.c.
 */
int BOX2_MAIN_StateMachineDragNoBar(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 1);
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
        BOX2_SEQ_ShowHandSlots((char *)task->work);
        b->state = 2;
        break;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            unsigned r;
            int back;
            r = (unsigned short)BOX2_MAIN_HitBoxGrid(task->work->cursorX, (short)(task->work->cursorY));
            if (r == 0xFF)
                r = (unsigned short)BOX2_MAIN_HitPartySlots(task->work->cursorX, task->work->cursorY, d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = task->cursorSlot;
                back = 1;
            } else if (BOX2_MAIN_CompareSlots((unsigned char *)task, task->cursorSlot, r) == 0) {
                r = task->cursorSlot;
                back = 1;
            }
            BOX2_MAIN_StartHandMotionToBoxSlot((BoxTask *)task, first, r, 2);
            if (back == 1 && task->heldSlot != 0xFF && task->heldSlot != task->curBox) {
                int dir = BOX2_MAIN_IsWrappedDistance((unsigned char *)task, task->curBox, task->heldSlot);
                task->curBox = task->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)task, task->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)task, BOX2_MAIN_GetBoxWallpaper((BoxTask *)task, task->curBox), dir);
                if (dir == 0)
                    b->state = 5;
                else
                    b->state = 6;
            } else {
                b->state = 7;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
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
        BOX2_MAIN_MoveCursorTo(task->work, x, y);
        break;
    case 3:
        if (BOX2_MAIN_StepScrollToPrevBox(task) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(task->work, x, y);
        break;
    case 4:
        if (BOX2_MAIN_StepScrollToNextBox(task) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(task->work, x, y);
        break;
    case 5:
    case 6:
        if (b->state == 5 && BOX2_MAIN_StepScrollToPrevBox(task) == 0)
            b->state = 7;
        if (b->state == 6 && BOX2_MAIN_StepScrollToNextBox(task) == 0)
            b->state = 7;
    case 7:
        if (BOX2_MAIN_StepHandMotionToSlot((BoxTask *)task) == 0 && b->state == 7) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 8;
        }
        break;
    case 8:
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 2);
        BOX2_SEQ_SetSlotDim((char **)task, 0);
        b->state = 9;
        break;
    case 9:
        if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 0);
            BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
            b->state = 10;
        }
        break;
    case 10:
        b->state = 0;
        return 0;
    }
    return 1;
}

/*
 * Callback of BOX2_SEQ_StateMoveItemScroll (state machine in the 021E1324 family): show
 * window 10, return the held item to its slot, then hide the window.
 */
int BOX2_MAIN_StateMachineReturnHeld(BoxTask *task)
{
    BoxSeq *b = &((BoxTask *)task)->work->seq;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 1);
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 1);
        b->state = 1;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
        b->state = 2;
        break;
    case 2: {
        unsigned char old = task->cursorSlot;
        task->cursorSlot = ((BoxSlotRef *)b->entry)->idx;
        if (task->heldSlot != 0xFF && task->heldSlot != task->curBox)
            BOX2_MAIN_StartHandMotionToBoxArrow((BoxTask *)task, 2);
        else
            BOX2_MAIN_StartHandMotionToBoxSlot((BoxTask *)task, old, old, 2);
        b->state = 3;
        break;
    }
    case 3:
        if (BOX2_MAIN_StepHandMotionToSlot((BoxTask *)task) != 0)
            break;
        if (task->heldSlot != 0xFF && task->heldSlot != task->curBox) {
            b->state = 5;
        } else {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 4;
        }
        break;
    case 4:
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 1);
        BOX2_SEQ_SetActorAnimSeq((char *)((BoxWork *)task->work), 10, 2);
        b->state = 5;
        break;
    case 5:
        if (BOX2_SEQ_IsActorAnimActive((char *)((BoxWork *)task->work), 10) != 0)
            break;
        BOX2_SEQ_SetActorDrawEnable((char *)((BoxWork *)task->work), 10, 0);
        BOX2_SEQ_SetActorAffineMode((char *)task->work, 0);
        b->state = 6;
        break;
    case 6:
        b->state = 0;
        return 0;
    }
    return 1;
}
