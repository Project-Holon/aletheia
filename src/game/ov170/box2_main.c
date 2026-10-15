/*
 * file:     box2_main.c
 * unit:     yes
 * function: BOX2_MAIN_Init, BOX2_MAIN_Main, BOX2_MAIN_Exit, BOX2_MAIN_CreateVBlankTask, BOX2_MAIN_DeleteVBlankTask, BOX2_MAIN_VBlankHandler, BOX2_MAIN_InitSeq, BOX2_MAIN_SetSeqParam, BOX2_MAIN_RestartSeq, BOX2_MAIN_ResetGraphics, BOX2_MAIN_GetDispVram, BOX2_MAIN_InitBgSys, BOX2_MAIN_DeleteBgSys, BOX2_MAIN_LoadBgData, BOX2_MAIN_CreatePalAnm, BOX2_MAIN_DeletePalAnm, BOX2_MAIN_SetDisplayControl, BOX2_MAIN_CreateTextSystem, BOX2_MAIN_DeleteTextSystem, BOX2_MAIN_CreateTaskMenu, BOX2_MAIN_DeleteTaskMenu, BOX2_MAIN_OpenTaskMenu, BOX2_MAIN_IsTaskMenuFinished, BOX2_MAIN_UpdateWindowFrame, BOX2_MAIN_RefreshCursorBox, BOX2_MAIN_StopSeq, BOX2_MAIN_SelectBox, BOX2_MAIN_RefreshBoxUi, BOX2_MAIN_IsWrappedDistance, BOX2_MAIN_PlayCursorSound, BOX2_MAIN_GetPartyValueAt, BOX2_MAIN_SetBoxValueAt, BOX2_MAIN_GetMonAt, BOX2_MAIN_ClearSlot, BOX2_MAIN_MoveMonToParty, BOX2_MAIN_AddMonToParty, BOX2_MAIN_GetBoxMon, BOX2_MAIN_SwapPartyMembers, BOX2_MAIN_ShiftMemberToEnd, BOX2_MAIN_CompactParty, BOX2_MAIN_RegisterSeenAndForm, BOX2_MAIN_UpdateBoxSlots, BOX2_MAIN_WrapSlot, BOX2_MAIN_HasOtherTradable, BOX2_MAIN_ChangeFormAndRegister, BOX2_MAIN_CanPlaceInBox, BOX2_MAIN_MoveMonIntoBox, BOX2_MAIN_RecalcPartyParam, BOX2_MAIN_LoadFormTable, BOX2_MAIN_DeleteFormTable, BOX2_MAIN_GetBoxValue, BOX2_MAIN_WaitCursorMove, BOX2_MAIN_WaitBoxScroll, BOX2_MAIN_HandleMonPickup, BOX2_MAIN_ComparePartyValue, BOX2_MAIN_CompareSlots, BOX2_MAIN_AdvanceMover, BOX2_MAIN_UpdateMoverX, BOX2_MAIN_UpdateMoverY, BOX2_MAIN_StepMover, BOX2_MAIN_MoveCursorWithMon, BOX2_MAIN_SwapWithNeighbour, BOX2_MAIN_SetMoverTarget, BOX2_MAIN_FindMoverSlot, BOX2_MAIN_StartMover, BOX2_MAIN_SetMoverEntry, BOX2_MAIN_GetMinusOne, BOX2_MAIN_ResetMovers, BOX2_MAIN_DeleteScroll, BOX2_MAIN_StepScroll, BOX2_MAIN_PlayMonCry, BOX2_MAIN_PlaceMonScene, BOX2_MAIN_ClearFlagsScene, BOX2_MAIN_PlaceMonSceneFromBox, BOX2_MAIN_PlaceTargetMonScene, BOX2_MAIN_CheckSceneMode, BOX2_MAIN_IsSwapScene, BOX2_MAIN_IsMoveScene, BOX2_MAIN_WrapOffset, BOX2_MAIN_LoadBgCharTile, BOX2_MAIN_LoadBgPaletteTile, BOX2_MAIN_LoadBgTileSet, BOX2_MAIN_LoadBgTiles, BOX2_MAIN_SetBoxScroll, BOX2_MAIN_LoadBoxPalette, BOX2_MAIN_GetBoxFormId, BOX2_MAIN_CreateSummary, BOX2_MAIN_DeleteHandle, BOX2_MAIN_SetupSummary, BOX2_MAIN_ChangeBoxForm, BOX2_MAIN_ChangeBoxFormPreserve, BOX2_MAIN_SetBoxForm, BOX2_MAIN_ResetBoxView, BOX2_MAIN_ClearCursorBox, BOX2_MAIN_SetSceneSlots, BOX2_MAIN_SetHandSlots, BOX2_MAIN_SetBodySlots, BOX2_MAIN_HideSlots, BOX2_MAIN_SetupSummaryActors, BOX2_MAIN_HitRect, BOX2_MAIN_HitBoxGrid, BOX2_MAIN_HitPartySlots, BOX2_MAIN_HitPartyGrid, BOX2_MAIN_PushPartyScene, BOX2_MAIN_PushPartySceneB, BOX2_MAIN_PushBagScene, BOX2_MAIN_PopSubArgs, BOX2_MAIN_PushNameScene, BOX2_MAIN_PopNameScene, BOX2_MAIN_MoveCursorActor, BOX2_MAIN_StateMachinePick, BOX2_MAIN_StateMachineScroll, BOX2_MAIN_StateMachineOpen, BOX2_MAIN_StateMachineClose, BOX2_MAIN_IsSeqIdle, BOX2_MAIN_IsSeqStep, BOX2_MAIN_IsWindowMoving, BOX2_MAIN_UpdateWindowMove, BOX2_MAIN_IsWindowBusy, BOX2_MAIN_ShiftWindowRight, BOX2_MAIN_ShiftWindowLeft, BOX2_MAIN_StateMachineMove, BOX2_MAIN_StateMachinePen, BOX2_MAIN_SceneApplyScroll, BOX2_MAIN_SceneWaitScroll, BOX2_MAIN_SceneMoveCursor, BOX2_MAIN_SceneWaitCursor, BOX2_MAIN_SceneOpenBox, BOX2_MAIN_Check09E0, BOX2_MAIN_Check0A40, BOX2_MAIN_StateMachineCoin, BOX2_MAIN_Check0E50, BOX2_MAIN_Check0ED4, BOX2_MAIN_Check0F4C, BOX2_MAIN_MoveCursorTo, BOX2_MAIN_StateMachineSlide, BOX2_MAIN_Check122C
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
 *   func_02007698 0x02007698 thumb
 *   func_020076A4 0x020076A4 thumb
 *   func_020078C4 0x020078C4 thumb
 *   func_020076B4 0x020076B4 thumb
 *   PROCSYS_Create 0x02031324 arm
 *   BOX2_SEQ_UpdatePrintQueue  0x021E1E34  thumb  ov170
 *   func_02030EAC  0x02030EAC  arm  arm9
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
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   ARC_UTIL_LoadPaletteBlockFromArchive  0x02049F34  arm
 *   BG_SYS_LoadPltt  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   CURSOR_MOVE_GetState 0x020260F0 thumb
 *   func_020355D8 0x020355D8 arm
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
 *   BOX2_UI_DeleteSlotIcon  0x021EDF5C  thumb  ov170
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   BOX2_UI_PutInfoBar  0x021EF738  thumb  ov170
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02007A18 0x02007A18 thumb
 *   POKE_TOOL_Dummy 0x020185F0 thumb
 *   BOX2_UI_DrawSlot 0x021EDAB0 thumb ov170
 *   POKE_TOOL_CreateFromBoxParam 0x0201747C thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   func_020075B0 0x020075B0 thumb
 *   POKEPARTY_SetMember 0x0201AB48 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   BOX2_UI_DrawSlotByName 0x021EDB34 thumb ov170
 *   func_0200752C 0x0200752C thumb
 *   func_02007664 0x02007664 thumb
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   func_02007610 0x02007610 thumb
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb
 *   POKE_TOOL_GetPlateTypeForwarder 0x02019CF8 thumb
 *   POKE_TOOL_GetBoxParamIndex 0x02019D00 thumb
 *   BOX2_SEQ_ShowSlotIcon 0x021EC48C thumb ov170
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   func_020092AC 0x020092AC thumb
 *   BOX2_SEQ_SetSlotDrawPriorityB 0x021EC7B8 thumb
 *   BOX2_SEQ_GetSlotPos 0x021EC548 thumb
 *   BOX2_UI_IsTopBarMid 0x021EF4A4 thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 *   BOX2_SEQ_SetSlotDimB 0x021ED75C thumb
 *   BOX2_SEQ_MoveCursorToSlot 0x021ED7C4 thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_UI_FindSlotPos 0x021EDA70 thumb
 *   BOX2_SEQ_SwapSlotActorsB 0x021ECBD8 thumb
 *   func_02030734 0x02030734 arm
 *   d_021F1400 0x021F1400 data a1
 *   GAME_DATA_GetBoxSave  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
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
 *   func_0200781C  0x0200781C  thumb  ov170
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
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BOX2_SEQ_SetSlotDim  0x021ED6E4  thumb  ov170
 *   d_021EF798 0x021EF798 data a1
 *   BOX2_UI_GetGridSlotPoint  0x021EF224  thumb  ov170
 *   PROCSYS_Push 0x02031348 arm
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov131_id 0x00000083 data a1
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   ov070_id       0x00000046  data
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   func_0200785C 0x0200785C thumb
 *   NAMEIN_SETUP_CreateArgs 0x0216BFD4 thumb ov010
 *   gNameInProcData 0x021F5580 data a4 ov194
 *   ov194_id 0x000000C2 data a1
 *   func_02007898 0x02007898 thumb
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CURSOR_MOVE_SetCurrent 0x020260E4 thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   BOX2_MAIN_IsSeqIdle 0x021E00C4 thumb
 *   BOX2_MAIN_IsSeqStep 0x021E0128 thumb
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
 *   BOX2_MAIN_StopSeq 0x021DD16C thumb
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
 *   BOX2_MAIN_GetBoxFormId 0x021DEDCC thumb
 *   BOX2_MAIN_SetBoxScroll 0x021DEC98 thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb ov170
 *   BOX2_MAIN_CompareSlots 0x021DDE80 thumb
 *   BOX2_MAIN_PlaceMonSceneFromBox 0x021DEA3C thumb
 *   BOX2_MAIN_IsSwapScene 0x021DEAFC thumb
 *   BOX2_MAIN_IsWindowMoving 0x021E0190 thumb ov170
 *   BOX2_MAIN_ClearFlagsScene 0x021DE980 thumb
 *   BOX2_MAIN_PlaceTargetMonScene 0x021DEA4C thumb
 *   BOX2_MAIN_IsMoveScene 0x021DEB08 thumb ov170
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
 *   BOX2_MAIN_IsTaskMenuFinished  0x021DCFC0  thumb  ov170
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb ov170
 *   BOX2_MAIN_SelectBox 0x021DD1C4 thumb
 *   CURSOR_MOVE_SetState 0x020260F4 thumb
 *   BOX2_MAIN_GetPartyValueAt 0x021DD25C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_MAIN_ClearCursorBox 0x021DF0BC thumb
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb ov170
 *   BOX2_MAIN_PlayCursorSound 0x021DD238 thumb
 *   BOX2_MAIN_SceneWaitScroll 0x021E070C thumb ov170
 *   BOX2_MAIN_StateMachineClose 0x021E0068 thumb ov170
 *   BOX2_MAIN_SceneWaitCursor 0x021E0778 thumb
 *   BOX2_MAIN_SceneOpenBox 0x021E087C thumb
 *   BOX2_MAIN_SetBoxValueAt 0x021DD2B4 thumb
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb
 *   BOX2_MAIN_CanPlaceInBox 0x021DD718 thumb
 *   BOX2_MAIN_RecalcPartyParam 0x021DD8A8 thumb
 *   BOX2_MAIN_GetBoxValue 0x021DD908 thumb ov170
 *   BOX2_MAIN_ChangeBoxForm 0x021DEF98 thumb ov170
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
 *   BOX2_MAIN_PlayMonCry  0x021DE898  thumb  ov170
 *   BOX2_MAIN_UpdateWindowFrame  0x021DD090  thumb  ov170
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
 */
#include "box2_types.h"

struct ProcSys;

struct S020314B8;

struct Proc;

struct S02021D50;

struct DispVram;

typedef enum { B0=0, B8=8, B16=16 } Bound;

extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);

extern void *PROCSYS_AllocProcWork(struct ProcSys *obj, unsigned int size, unsigned int heap);

extern void MI_CpuFill8(void *,int,unsigned);

extern unsigned func_02007698(void *);

extern u8 func_020076A4(void *);

extern int func_020078C4(void *save, u32 box);

extern u8 func_020076B4(void *);

extern void *PROCSYS_Create(int a0);

extern unsigned int PROCSYS_Main(void *);

extern int BOX2_SEQ_UpdatePrintQueue(BoxTask *p, int *state);

extern void func_0200780C(void *save, u32 box);

extern void func_0203133C(struct S020314B8 *p);

extern void func_020315D4(struct Proc *p);

extern void GFL_HEAP_DeleteChecked(unsigned int heap);

extern int func_020056A0(void *, void *, int);

extern void func_02030EAC(struct Node *n);

extern void BOX2_SEQ_FlushDirtyBmpWins(BoxWork *w);

extern void BG_SYS_Update(void);

extern void CLACT_VBlankSystem(void);

extern void PALANM_TransferPalettes(struct S02021D50 *p);

extern void BG_SYS_ClearGraphicsMemory(u32 keep);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

int BOX2_MAIN_Init(void *manager, int unused, void **context);

int BOX2_MAIN_Main(int a, int b, int c, int *d);

int BOX2_MAIN_Exit(int a, int b, int c, int *d);

void BOX2_MAIN_CreateVBlankTask(BoxTask *p);

void BOX2_MAIN_DeleteVBlankTask(BoxTask *p);

void BOX2_MAIN_VBlankHandler(u32 a, BoxTask *p);

void BOX2_MAIN_InitSeq(BoxWork *p, int v);

void BOX2_MAIN_SetSeqParam(BoxWork *p, int v);

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
    p = PROCSYS_AllocProcWork(manager,0x30,75);
    MI_CpuFill8((void *)p,0,0x30);
    *(void ** *)&((BoxTask *)p)->params = context;
    p[0x14] = func_02007698(context[1]);
    p[0x15] = func_020076A4((*(void ***)p)[1]);
    p[0x17] = 255;
    ((BoxTask *)p)->state = 11;
    if ((u8)p[0x15] != 24) {
        if ((u8)p[0x15] == 8) max = B8;
        else if ((u8)p[0x15] == 16) max = B16;
        for (i=0;i<max;i++) {
            if (func_020078C4((*(void ***)p)[1],i) == 0) break;
        }
        if (i == max) p[0x15] = func_020076B4((*(void ***)p)[1]);
    }
    p[0x20] = 0;
    p[0x1f] = 0;
    p[0x21] = 1;
    ((BoxTask *)p)->procSys = PROCSYS_Create(75);
    return 1;
}

/*
 * Re-derive d[2] from d[1] then test the entry; 0 means accepted.
 */
int BOX2_MAIN_Main(int a, int b, int c, int *d)
{
    d[2] = PROCSYS_Main((void *)d[1]);
    if (BOX2_SEQ_UpdatePrintQueue((BoxTask *)d, (int *)b) == 0)
        return 1;
    return 0;
}

int BOX2_MAIN_Exit(int a, int b, int c, int *d)
{
    func_0200780C((void *)(*(int *)(*d + 4)), ((BoxTask *)d)->curBox);
    func_0203133C((struct S020314B8 *)d[1]);
    func_020315D4((struct Proc *)a);
    GFL_HEAP_DeleteChecked(0x4b);
    return 1;
}

/*
 * Seat the 0x54 handler word.
 */
void BOX2_MAIN_CreateVBlankTask(BoxTask *p)
{
    (*(int *)&p->work->vblankTask) = func_020056A0((void *)BOX2_MAIN_VBlankHandler, p, 0);
}

/*
 * Tail call func_02030EAC with the word at +0x2c/+0x54.
 */
void BOX2_MAIN_DeleteVBlankTask(BoxTask *p)
{
    func_02030EAC(p->work->vblankTask);
}

void BOX2_MAIN_VBlankHandler(u32 a, BoxTask *p)
{
    BOX2_SEQ_FlushDirtyBmpWins(p->work);
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)((*(u32 *)&p->work->palAnm)));
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3ff8) |= 1;
}

/*
 * Clear the two halfword fields at +0x64/+0x66, store v at +0x58 and zero +0x5c.
 */
void BOX2_MAIN_InitSeq(BoxWork *p, int v)
{
    p->seq.state = 0;
    p->seq.timer = 0;
    p->seq.resetValue = v;
    p->seq.param = 0;
}

/*
 * Store the second argument into the word field at +0x5c of the object.
 */
void BOX2_MAIN_SetSeqParam(BoxWork *p, int v)
{
    p->seq.param = v;
}

/*
 * Re-run the reset helper with the stored word.
 */
void BOX2_MAIN_RestartSeq(BoxWork *p)
{
    BOX2_MAIN_InitSeq((BoxWork *)p, p->seq.param);
}

/*
 * Two calls after setting the first argument.
 */
void BOX2_MAIN_ResetGraphics(void)
{
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((void *)0x021EF7CC);
}

/*
 * Constant-address getter.
 */
void *BOX2_MAIN_GetDispVram(void)
{
    return (void *)0x021EF7CC;
}





struct GfFont;

struct R;

struct TaskMenuState;

struct TaskMenuTmpl;

struct Sub020079BCEntry;

struct Party;

struct Mon;

struct PartyMon;

struct Sub020075B0Entry;

struct Sub02007454Entry;

struct Blk37;

struct Sub02007AC8Entry;

struct PerapVoice;

struct BigObj;

struct Big;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct { u32 f0; u32 f4; u32 f8; u8 *fC; } PlttData;

struct Ov170Ctx { char pad[0x2c]; char *f2c; };

typedef struct {
    u32 heapId;
    u8 count;
    u8 pad05[3];
    const void *items;
    u32 unk0c;
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

typedef struct BoxCursor {
    void *p;
    unsigned short index;
    unsigned char flags;
    unsigned char pad[5];
} BoxCursor;

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
typedef struct {
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

typedef struct {
    void *mon;
    void *f4;
    void *save;
    unsigned char kind, mode, count, slot, zero;
    char pad[7];
    void *f18;
    char pad1C[12];
    char pad28[16];
    int subResult;
} Request_021DF040;

typedef struct { void *task; void *text; } Request_021DF378;

extern void BG_SYS_Create(u16 heap);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_ClearSlot(u32 i);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_FreeLayerBuf(unsigned);

extern void BG_SYS_Delete(void);

extern void *func_020490F4(u32 id, u32 heap);

extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);

extern u32 func_02049740(void *, u32, u32, u32, u32, u16);

extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);

extern void func_02049B68(void *, u32, u32, u32, u32, u16);

extern u32 APP_ICON_GetArchiveId(void);

extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);

extern void BG_SYS_LoadPltt(u32 a, void *src, u32 size, u32 ofs);

extern u32 func_020307B0(void *p);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 APP_ICON_GetStatusFrameFileId(void);

extern u32 APP_ICON_GetStatusAnimFileId(void);

extern u32 APP_ICON_GetStatusDataFileId(void);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void func_02041B6C(u32);

extern u32 BG_SYS_GetBuf(int channel);

extern void *BMP_MENUWORK_LoadFrameGfx(void *a0, u32 a1, u32 a2, u32 a3);

extern void func_02049B40(u32, u32, u32, u32, u32, u16);

extern void *PALANM_Create(u32 heap);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern u32 PALANM_Delete(void *a0);

extern void func_0207D63C(int, int, int, int, int);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern void *PRINTSYS_QUE_CreateEx(unsigned short,unsigned);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *vec);

struct PrintBoxTask;
extern void PRINTSYS_QUE_Delete(struct PrintBoxTask *p);

extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 GF_FONT_Delete(void *ptr);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern u32 CURSOR_MOVE_GetState(struct Sound *obj);

extern void func_020355D8(u8 v);

extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

extern void APP_TASKMENU_SetCursorPos(u8 *p, int sel);

extern void BOX2_SEQ_SetActorAutoAnim(BoxWork *p, int i, int v);

u32 BOX2_SEQ_IsActorAnimActive(BoxWork *p, int i);

extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);

extern void BGWINFRM_GetSize(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);

extern u8 BGWINFRM_GetBgFrame(struct WinMgr *mgr, u32 idx);

extern void BOX2_UI_DeleteSlotObjects(BoxTask *p, int a, int b, int c);

extern void BOX2_UI_PutFadeFrame(struct WinMgr *mgr);

void BOX2_SEQ_SetActorAnimSeq(BoxWork *p, int i, int v);

void BOX2_SEQ_LoadMonIcon(char **p, int box);

extern void BOX2_UI_HideSlotIcon(BoxTask *p, int d);

extern void BOX2_UI_SetMiniIconVisible(BoxTask *p, int a, int b);

extern void BOX2_UI_RefreshBoxName(unsigned char *p);

extern void BOX2_UI_SetCloseButtonPos(BoxWork *);

extern void BOX2_UI_DeleteSlotIcon(BoxTask *p);

extern void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i);

extern void BOX2_UI_PutInfoBar(struct WinMgr *mgr);

extern void CURSOR_MOVE_SetState(struct Struct_02025CD0 *obj, u32 state);

extern unsigned POKEPARTY_GetCount(void *p);

extern void *POKEPARTY_GetMember(void *party, unsigned i);

extern unsigned POKE_TOOL_GetPartyValue(void *p, unsigned id, unsigned v);

extern unsigned func_02017E88(void *p, unsigned id, unsigned v);

extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

extern void POKE_TOOL_SetBoxValue(void *p, u32 id, u32 v);

extern int POKE_TOOL_Dummy(void *p);

extern void func_02007664(void *save, u32 box, u32 slot);

extern u32 POKEPARTY_RemoveMember(struct Party *p, s32 idx);

extern void BOX2_UI_DrawSlot(BoxTask *p, int i);

extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);

extern void *POKE_TOOL_GetBoxParam(void *);

extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);

extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);

extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);

extern u32 POKEPARTY_SwapMembers(struct Party *p, u32 i, u32 j, u32 heap);

extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);

extern void BOX2_UI_DrawSlotByName(char *p, int a);

extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

extern void *ZUKAN_SAVE_GetFromGameData(void *);

extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);

extern void func_02007610(void *save, unsigned b1, unsigned a, unsigned b2, unsigned c);

extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);

extern u16 POKE_TOOL_GetPlateTypeForwarder(u32 item);

extern u32 POKE_TOOL_GetBoxParamIndex(u32 item);

extern void BOX2_SEQ_ShowSlotIcon(BoxTask *p, int box, int pos, int win);

extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);

extern void POKE_TOOL_RecalcParam(void *p);

extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *);

extern u32 func_020092AC(const u8 *bits, int n);

extern void BOX2_SEQ_SetSlotDrawPriorityB(BoxWork *p, int i, unsigned j, int flag);

extern void BOX2_SEQ_GetSlotPos(unsigned i, short *x, short *y, int mode);

extern int BOX2_UI_IsTopBarMid(struct WinMgr *mgr);

void BOX2_SEQ_SetActorDrawEnable(BoxWork *p, int i, int v);

extern void BOX2_SEQ_AddActorSurfacePos(BoxWork *p, int i, int a, int b, unsigned short c);

extern void BOX2_SEQ_SetSlotDrawPriority(BoxWork *p, unsigned i, int flag);

extern void BOX2_SEQ_SetSlotDimB(char **p, int i);

extern void BOX2_SEQ_MoveCursorToSlot(BoxWork *w, int i);

extern unsigned FILE_UTIL_Check136C(unsigned short v);

extern void BOX2_SEQ_GetActorSurfacePos(BoxWork *w, int i, short *x, short *y, unsigned short z);

extern void BOX2_UI_FindSlotPos(BoxWork *a0, int a1, short *a2, short *a3);

extern void BOX2_SEQ_SwapSlotActorsB(BoxWork *p, int i);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct Sub02007AC8Entry *GAME_DATA_GetBoxSave(void *p);

extern void func_02007C34(struct PerapVoice *p, void *a);

extern void BOX2_SEQ_MoveActorToSlot(BoxWork *w, int i, int v);

extern void BOX2_SEQ_MoveActorToSlotB(BoxWork *w, int i, int v);

void BOX2_SEQ_MoveActor(BoxWork *a, int b, int c);

void BOX2_SEQ_LayoutHandSlots(BoxWork *w);

extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);

extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32,u32,u32,u32,u16);

extern void BG_SYS_DrawTile(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);

extern void BG_SYS_SetTileEntry(u32,int,u8,int,u8,u8,u8);

extern void BOX2_SEQ_DrawBoxName(char **p, unsigned box, int i);

extern void BOX2_UI_SetSlotOamEnabled(BoxWork *p, int i, int v);

extern int BOX2_UI_GetSlotOamEnabled(BoxWork *a, int i);

extern void BOX2_UI_MoveSlotOam(BoxWork *p, int i, int flag);

extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);

extern unsigned char func_0200781C(int save, unsigned int box);

extern unsigned char POKE_TOOL_GetBoxNature(void *mon);

extern unsigned char POKE_TOOL_GetBoxGender(void *mon);

extern u32 POKE_TOOL_IsBoxShiny(void *p);

extern u32 POKERUS_IsBoxInfected(void *mon);

extern u32 POKERUS_IsBoxCured(void *mon);

extern void BOX2_SEQ_LoadMonIconActor(char *p, void **mon, int index);

extern void BOX2_SEQ_ShowHandSlotB(BoxWork *p, unsigned char *q);

extern void BOX2_SEQ_DeleteTextEntries(BoxTask *p, int a);

extern void BG_SYS_ResetSlot(unsigned index, unsigned a, unsigned b);

extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);

extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);

extern void BOX2_SEQ_ClearTextWin(BoxWork *w);

void BOX2_SEQ_SetSlotDim(char **p, int v);

extern int BOX2_UI_GetGridSlotPoint(int, int);

extern void PROCSYS_Push(void *p, int a, const void *b, void *c);

extern void *BAG_PARAM_Create(const struct BigObj *a0, int a1, int a2, int a3);

extern void *GAME_DATA_GetSaveControl(struct Big *p);

extern void *BEACON_GetBlock(void *sys);

extern void func_0200785C(void *save, unsigned box, void *dest);

extern int *NAMEIN_SETUP_CreateArgs(unsigned short a0, int a1, short a2, short a3, int s0, int s1, int s2);

extern void func_02007898(void *save, u32 box, const void *src);

extern int NAMEIN_SETUP_FreeArgs(int);

extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);

int BOX2_MAIN_ShiftWindowRight(BoxTask *p);

extern int BOX2_UI_UpdateListPacks(struct WinMgr *mgr);

extern int TOUCHPANEL_GetCont(void);

extern void BOX2_UI_OpenListPack(struct WinMgr *mgr);

extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);

extern int BOX2_UI_IsInfoBarOpen(struct WinMgr *mgr);

extern void BOX2_UI_CloseInfoBar(struct WinMgr *mgr);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern int BOX2_UI_IsTopBarOpen(struct WinMgr *mgr);

extern int BOX2_UI_GetPageButtonHit(void);

extern void BOX2_UI_SlideBarIn(struct WinMgr *mgr);

void BOX2_SEQ_SetSlotActors(char *p, int f, int c);

extern void BOX2_UI_ToggleSlotPair(BoxWork *p, int v);

extern void CURSOR_MOVE_ClearSkipBit(struct Sound *obj, u32 idx);

extern int BOX2_UI_IsTopBarClosed(struct WinMgr *mgr);

extern int BOX2_UI_IsListClosed(struct WinMgr *mgr);

extern void BOX2_UI_CloseListPack(struct WinMgr *mgr);

extern int BOX2_UI_GetPartySlotPoint(int a, int b);

extern void BOX2_UI_MoveCursor(char **p, int idx, int v);

extern int BOX2_UI_GetCloseButtonHit(void);

extern int BOX2_UI_GetPageButtonHit2(void);

extern void BOX2_UI_OpenBar(struct WinMgr *mgr);

extern int BOX2_UI_GetExitButtonHit(void);

int BOX2_MAIN_IsSeqIdle(BoxTask *p);

int BOX2_MAIN_IsSeqStep(BoxTask *p);

extern int BOX2_SEQ_OpenBoxDown(BoxTask *p);

extern int BOX2_SEQ_OpenBoxUp(BoxTask *p);

int BOX2_MAIN_ShiftWindowLeft(BoxTask *p);

extern void BOX2_UI_PutBottomBarClosed(struct WinMgr *mgr);

extern void BOX2_UI_CloseBar(struct WinMgr *mgr);

void BOX2_SEQ_HidePartialSlots(char **p, int flag);

extern void BOX2_UI_HideWindowA(BoxWork *p);

extern void BOX2_UI_ShowWindowB(BoxWork *p);

extern int BOX2_UI_UpdateBarMove(BoxTask *p);

extern void BOX2_UI_HideWindowB(BoxWork *p);

extern void BOX2_UI_ShowWindowA(BoxWork *p);

extern void CURSOR_MOVE_SetCurrent(struct Sound *obj, u8 sel);

extern void BOX2_UI_SetCursorPos(char **p, unsigned idx);

extern void BOX2_SEQ_SetCursorDraw(char **p, int flag);

void BOX2_MAIN_InitBgSys(u8 *a0);

void BOX2_MAIN_DeleteBgSys(void *p);

void BOX2_MAIN_LoadBgData(struct Ov170Ctx *ctx);

void BOX2_MAIN_CreatePalAnm(BoxTask *p);

void BOX2_MAIN_DeletePalAnm(int *p);

void BOX2_MAIN_SetDisplayControl(int a);

void BOX2_MAIN_CreateTextSystem(char *p);

void BOX2_MAIN_DeleteTextSystem(char *p);

void BOX2_MAIN_CreateTaskMenu(char *p);

void BOX2_MAIN_DeleteTaskMenu(BoxTask *p);

void BOX2_MAIN_OpenTaskMenu(BoxTask *p, int sel);

int BOX2_MAIN_IsTaskMenuFinished(BoxTask *p);

void BOX2_MAIN_UpdateWindowFrame(BoxTask *p, unsigned idx);

void BOX2_MAIN_RefreshCursorBox(BoxTask *p);

void BOX2_MAIN_StopSeq(BoxTask *p, int dir);

void BOX2_MAIN_SelectBox(BoxTask *p, int a);

void BOX2_MAIN_RefreshBoxUi(BoxTask *p);

int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b);

void BOX2_MAIN_PlayCursorSound(BoxTask *p);

unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, unsigned short box, unsigned id, unsigned v);

void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e);

int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);

void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b);

void BOX2_MAIN_MoveMonToParty(unsigned char *p,unsigned short *q,unsigned short *t);

void BOX2_MAIN_AddMonToParty(unsigned char *p, unsigned short *q);

void BOX2_MAIN_GetBoxMon(BoxTask *p, unsigned char *a);

void BOX2_MAIN_SwapPartyMembers(char **p, char *q);

void BOX2_MAIN_ShiftMemberToEnd(int *p, unsigned char *a);

void BOX2_MAIN_CompactParty(unsigned char *p,unsigned a,unsigned b,unsigned c);

void BOX2_MAIN_RegisterSeenAndForm(unsigned char *p,unsigned a,unsigned b);

void BOX2_MAIN_UpdateBoxSlots(BoxTask *p);

int BOX2_MAIN_WrapSlot(unsigned char *p, unsigned i);

int BOX2_MAIN_HasOtherTradable(void ***p, unsigned skip);

void BOX2_MAIN_ChangeFormAndRegister(void **pp, void *a, u32 b);

int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon);

void BOX2_MAIN_MoveMonIntoBox(BoxTask *p,unsigned a,unsigned b,unsigned box);

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

void BOX2_MAIN_PlayMonCry(int *q);

void BOX2_MAIN_PlaceMonScene(BoxTask *p, int slot, unsigned idx, int mode, int flag);

void BOX2_MAIN_ClearFlagsScene(BoxTask *p, int mode);

void BOX2_MAIN_PlaceMonSceneFromBox(int a, int b, int c, int d);

void BOX2_MAIN_PlaceTargetMonScene(BoxTask *p, int a, int b);

int BOX2_MAIN_CheckSceneMode(BoxTask *p, int a);

int BOX2_MAIN_IsSwapScene(int a);

int BOX2_MAIN_IsMoveScene(unsigned char *p);

unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);

void BOX2_MAIN_LoadBgCharTile(u32 a, int b, void *c);

void BOX2_MAIN_LoadBgPaletteTile(int a, int b, int c);

void BOX2_MAIN_LoadBgTileSet(void *unused, void *unused2, int x, u32 base, u32 pal);

void BOX2_MAIN_LoadBgTiles(void *a, void *b, int c, void *d, int e);

void BOX2_MAIN_SetBoxScroll(BoxTask *p, void *a, int dir);

void BOX2_MAIN_LoadBoxPalette(BoxTask *p, int a);

int BOX2_MAIN_GetBoxFormId(BoxTask *p, int box);

Summary *BOX2_MAIN_CreateSummary(void *mon);

void BOX2_MAIN_DeleteHandle(void *s);

void BOX2_MAIN_SetupSummary(BoxTask *p, int a);

int BOX2_MAIN_ChangeBoxForm(char *p, int a, unsigned b);

void BOX2_MAIN_ChangeBoxFormPreserve(BoxTask *p, int b);

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
void BOX2_MAIN_InitBgSys(u8 *a0)
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

void BOX2_MAIN_DeleteBgSys(void *p)
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

void BOX2_MAIN_LoadBgData(struct Ov170Ctx *ctx)
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

    arc = func_020490F4(0x74, 0x4c);
    func_02049658((void *)arc, 0xc, 1, 0, 0, 1, 0x4c);
    func_02049740((void *)arc, 3, 2, 0, 1, 0x4c);
    func_020498F4((void *)arc, 2, 2, 0, 0, 1, 0x4c);
    func_02049658((void *)arc, 1, 3, 0, 0, 1, 0x4c);
    func_020498F4((void *)arc, 0, 3, 0, 0, 1, 0x4c);
    func_02049B68((void *)arc, 4, 0, 0, 0x80, 0x4c);
    func_02049658((void *)arc, 0x3e, 1, 1000, 0x300, 1, 0x4c);
    func_02049B68((void *)arc, 0x3f, 0, 0x180, 0x40, 0x4c);
    pal = ARC_UTIL_LoadPaletteBlockFromArchive(APP_ICON_GetArchiveId(), 0x1f, (u32)(&pd), 0x804c);
    src = pd->fC;
    ofs = 0x194;
    BG_SYS_LoadPltt(0, src + 0x34, 4, ofs);
    src += 0x14;
    ofs += 0x20;
    BG_SYS_LoadPltt(0, src, 4, ofs);
    func_020307B0((void *)pal);
    func_02049658((void *)arc, 6, 5, 0, 0, 1, 0x4c);
    func_020498F4((void *)arc, 5, 5, 0, 0, 1, 0x4c);
    func_02049658((void *)arc, 6, 6, 0, 0, 1, 0x4c);
    func_02049B68((void *)arc, 7, 4, 0, 0, 0x4c);
    ARC_TOOL_DeleteHandle((void *)arc);
    arc2 = func_020490F4(APP_ICON_GetArchiveId(), 0x4c);
    func_02049740((void *)arc2, APP_ICON_GetStatusFrameFileId(), 0, 0, 0, 0x4c);
    func_02049B68((void *)arc2, APP_ICON_GetStatusAnimFileId(), 0, 0xe0, 0x20, 0x4c);
    func_020498F4((void *)arc2, APP_ICON_GetStatusDataFileId(), 0, 0, 0, 0, 0x4c);
    BG_SYS_FillTileMap(0, 0, 0x15, 0x20, 3, 7);
    func_02041B6C(0);
    r6 = func_02049740((void *)arc2, APP_ICON_GetStatusFrameFileId(), 2, 0, 0, 0x4c);
    ARC_TOOL_DeleteHandle((void *)arc2);
    a = (u16 *)BG_SYS_GetBuf(0);
    b = (u16 *)BG_SYS_GetBuf(2);
    for (i = 0; i < 0x60u; i++) {
        *(u16 *)((char *)b + 0x540 + i * 2) = r6 + *(u16 *)((char *)a + 0x540 + i * 2);
    }
    func_02041B6C(2);
    *(int *)(ctx->f2c + 0x178) = (int)BMP_MENUWORK_LoadFrameGfx(0, 10, 0, 0x4c);
    func_02049B40(0x17, 5, 0, 0x160, 0x20, 0x4c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4c);
}

/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
void BOX2_MAIN_CreatePalAnm(BoxTask *p)
{
    int v = (int)PALANM_Create(0x4c);

    (*(int *)&p->work->palAnm) = v;
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)((*(int *)&p->work->palAnm)), 0, 0x200, 0x4c);
}

void BOX2_MAIN_DeletePalAnm(int *p)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)((*(int *)&((BoxTask *)p)->work->palAnm)), 0);
    PALANM_Delete((void *)((*(int *)&((BoxTask *)p)->work->palAnm)));
}

void BOX2_MAIN_SetDisplayControl(int a)
{
    if (a == 1)
        func_0207D63C(0x04000050, 0, 0x2a, 6, 0xa);
    else
        *(volatile unsigned short *)0x04000050 = 0;
}


void BOX2_MAIN_CreateTextSystem(char *p)
{
    (*(void **)((char *)((BoxTask *)(p))->work + (0x80))) = func_02045B38(0,2,9,0x4c);
    (*(void **)((char *)((BoxTask *)(p))->work + (0x78))) = GF_FONT_Create(0x17,0,1,0,0x4c);
    (*(void **)((char *)((BoxTask *)(p))->work + (0x7c))) = GF_FONT_Create(0x17,3,0,0,0x4c);
    (*(void **)((char *)((BoxTask *)(p))->work + (0x84))) = WORDSET_CreateDefault(0x4c);
    (*(void **)((char *)((BoxTask *)(p))->work + (0x8c))) = PRINTSYS_QUE_CreateEx(0x800,0x4c);
    (*(void **)((char *)((BoxTask *)(p))->work + (0x88))) = STRBUF_Create(0x400,0x4c);
}










/*
 * trailing: two bytes alignment padding at 0x021DCEBE.
 */
void BOX2_MAIN_DeleteTextSystem(char *p)
{
    STRBUF_Delete((*(void **)((char *)((BoxTask *)(p))->work + (0x88))));
    PRINTSYS_QUE_Delete((*(void **)((char *)((BoxTask *)(p))->work + (0x8c))));
    WORDSET_DeleteStrbufED04((*(void **)((char *)((BoxTask *)(p))->work + (0x84))));
    GF_FONT_Delete((*(void **)((char *)((BoxTask *)(p))->work + (0x7c))));
    GF_FONT_Delete((*(void **)((char *)((BoxTask *)(p))->work + (0x78))));
    MSGDATA_Delete((*(void **)((char *)((BoxTask *)(p))->work + (0x80))));
}

















void BOX2_MAIN_CreateTaskMenu(char *p)
{
    (*(void **)((char *)((BoxTask *)(p))->work + (0x184)))=func_02045EC0((*(void **)((char *)((BoxTask *)(p))->work + (0x80))),0x6e);
    (*(unsigned short *)((char *)((BoxTask *)(p))->work + (0x188)))=0x39e3;
    (*(void **)((char *)((BoxTask *)(p))->work + (0x18c)))=0;
    (*(void **)((char *)((BoxTask *)(p))->work + (0x190)))=func_02045EC0((*(void **)((char *)((BoxTask *)(p))->work + (0x80))),0x6f);
    (*(unsigned short *)((char *)((BoxTask *)(p))->work + (0x194)))=0x39e3;
    (*(void **)((char *)((BoxTask *)(p))->work + (0x198)))=0;
    (*(void **)((char *)((BoxTask *)(p))->work + (0x19c)))=APP_TASKMENU_RES_Create(0,8,(u32)(*(void **)((char *)((BoxTask *)(p))->work + (0x78))),(u32)(*(void **)((char *)((BoxTask *)(p))->work + (0x8c))),0x4c);
}

/*
 * lane O46
 */
void BOX2_MAIN_DeleteTaskMenu(BoxTask *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)((*(int *)&p->work->taskMenuRes)));
    STRBUF_Delete((struct U16Vec *)(*(int *)&p->work->taskMenuItems[12]));
    STRBUF_Delete((struct U16Vec *)((*(int *)&p->work->taskMenuItems[0])));
}









void BOX2_MAIN_OpenTaskMenu(BoxTask *p, int sel)
{
    MenuTmpl t;
    t.heapId = 0x4C;
    t.count = 2;
    t.items = (char *)p->work + 0x184;
    t.unk0c = 1;
    t.x = 0x20;
    t.y = 0x12;
    t.w = 8;
    t.h = 3;
    if (CURSOR_MOVE_GetState(p->work->sound) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    p->work->taskMenu = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), p->work->taskMenuRes);
    APP_TASKMENU_SetCursorPos((u8 *)p->work->taskMenu, sel);
}

int BOX2_MAIN_IsTaskMenuFinished(BoxTask *p)
{
    BoxFade *f = &p->work->fade;
    switch (f->state) {
    case 0:
        if (f->flag == 0) {
            BOX2_SEQ_SetActorAutoAnim((BoxWork *)p->work, f->id, f->lo);
        } else {
            BG_SYS_FillTileMap(f->id, f->x, f->y, f->w, f->h, f->lo);
            func_02041B6C(f->id);
        }
        f->state++;
        break;
    case 1:
        if (f->flag == 0) {
            if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, f->id) == 0)
                return 0;
        } else {
            f->count++;
            if (f->count == 4) {
                BG_SYS_FillTileMap(f->id, f->x, f->y, f->w, f->h, f->hi);
                func_02041B6C(f->id);
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

void BOX2_MAIN_UpdateWindowFrame(BoxTask *p, unsigned idx)
{
    unsigned short w;
    unsigned short h;
    signed char pos[2];
    BGWINFRM_GetPos(p->work->winMgr, idx, &pos[1], &pos[0]);
    BGWINFRM_GetSize(p->work->winMgr, idx, &w, &h);
    p->work->fade.flag = 1;
    p->work->fade.id = BGWINFRM_GetBgFrame(p->work->winMgr, idx);
    p->work->fade.lo = 0xD;
    p->work->fade.hi = 0xC;
    p->work->fade.state = 0;
    p->work->fade.count = 0;
    p->work->fade.x = pos[1];
    p->work->fade.y = pos[0];
    p->work->fade.w = w;
    p->work->fade.h = h;
}

void BOX2_MAIN_RefreshCursorBox(BoxTask *p)
{
    BOX2_UI_DeleteSlotObjects((BoxTask *)p, p->slot6Mode, p->slot7Mode,
                  p->slot8Mode);
    BOX2_UI_PutFadeFrame(p->work->winMgr);
}

void BOX2_MAIN_StopSeq(BoxTask *p, int dir)
{
    if (dir == 0) {
        p->curBox = p->curBox == 0 ? p->boxLimit - 1 : p->curBox - 1;
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 0, 2);
    } else {
        p->curBox = p->curBox == p->boxLimit - 1 ? 0 : p->curBox + 1;
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 1, 4);
    }
    BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
    BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), dir);
}

/*
 * Fold the signed delta into p[0x19] through the wrap helper,
 *   then refresh and re-key the queue.
 */
void BOX2_MAIN_SelectBox(BoxTask *p, int a)
{
    p->prevBox = BOX2_MAIN_WrapOffset((unsigned char *)p, (signed char)a);
    BOX2_UI_HideSlotIcon((BoxTask *)p, a);
    BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
}

/*
 * Five-step reset: fold the delta, rebuild the queue object,
 *   re-run the frame update, clear the flag and re-stage channel 9.
 */
void BOX2_MAIN_RefreshBoxUi(BoxTask *p)
{
    BOX2_UI_RefreshBoxName((unsigned char *)p);
    BOX2_UI_SetCloseButtonPos(p->work);
    BOX2_UI_DeleteSlotIcon((BoxTask *)p);
    BOX2_SEQ_DrawOffsetName((unsigned char *)p, 0);
    BOX2_UI_PutInfoBar(p->work->winMgr);
}

/*
 * True when the absolute difference of the two unsigned arguments
 * straddles half of the +0x15 counter, in the direction of the order.
 */
int BOX2_MAIN_IsWrappedDistance(unsigned char *p, unsigned a, unsigned b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    if (a > b)
        return d >= ((unsigned)p[0x15] >> 1);
    return d < ((unsigned)p[0x15] >> 1);
}

/*
 * Enable the pooled object when it reports zero.
 */
void BOX2_MAIN_PlayCursorSound(BoxTask *p)
{
    func_020355D8(0);
    if (CURSOR_MOVE_GetState(p->work->sound) == 0)
        CURSOR_MOVE_SetState(p->work->sound, 1);
}

unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, unsigned short box, unsigned id, unsigned v)
{
    if (a >= 0x1E) {
        if (a >= 0x1E)
            a -= 0x1E;
        if ((int)POKEPARTY_GetCount((*p)[2]) > a)
            return POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((*p)[2], a), id, v);
    } else if (a != 0xFF) {
        void *m = func_02007A18((*p)[1], box, a);
        if (m != 0)
            return func_02017E88((void *)m, id, v);
    }
    return 0;
}

/*
 * Open the range, then feed the handle to the second call.
 */
void BOX2_MAIN_SetBoxValueAt(int a, int b, int c, int d, int e)
{
    int r = BOX2_MAIN_GetMonAt((void ***)a, c, b);
    if (r)
        POKE_TOOL_SetBoxValue((void *)r, d, e);
}

int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b)
{
    if (a == 0xFF || b >= 0x1E) {
        if (b >= 0x1E)
            b -= 0x1E;
        if (POKEPARTY_GetCount((*p)[2]) > b)
            return POKE_TOOL_Dummy(POKEPARTY_GetMember((*p)[2], b));
    } else if (b != 0xFF) {
        return (int)func_02007A18((*p)[1], a, b);
    }
    return 0;
}

/*
 * Two ranges: below 30 forward all, at or above rebase.
 * The tested field is unsigned: a signed `b` compiles the inverted
 * branch as blo where the image has bhs.
 */
void BOX2_MAIN_ClearSlot(char **p, int a, unsigned b)
{
    if (b < 0x1eU)
        func_02007664((void *)(((BoxParam *)((*p)))->boxSave), a, b);
    else
        POKEPARTY_RemoveMember((struct Party *)(((BoxParam *)((*p)))->party), b - 0x1eU);
}

void BOX2_MAIN_MoveMonToParty(unsigned char *p,unsigned short *q,unsigned short *t)
{
    unsigned box;
    unsigned short slot;
    void *m;
    if (q[0] == 0x24) box=p[0x17]; else box=p[0x14];
    m=POKE_TOOL_CreateFromBoxParam((struct Mon *)BOX2_MAIN_GetMonAt((void ***)p,box,q[2]),0x804c);
    slot=t[2]-30;
    func_020075B0((*(void ***)p)[1],box,q[2],POKE_TOOL_GetBoxParam(POKEPARTY_GetMember((*(void ***)p)[2],slot)));
    POKEPARTY_SetMember((*(void ***)p)[2],slot,m);
    func_020307B0((void *)m);
    BOX2_UI_DrawSlot((BoxTask *)p,box);
}

void BOX2_MAIN_AddMonToParty(unsigned char *p, unsigned short *q)
{
    void *m;
    m = POKE_TOOL_CreateFromBoxParam((struct Mon *)BOX2_MAIN_GetMonAt((void ***)p,p[0x17],q[2]),0x804c);
    POKEPARTY_Add((*(void ***)p)[2],m);
    BOX2_MAIN_ClearSlot((char **)p,p[0x17],q[2]);
    func_020307B0((void *)m);
    BOX2_UI_DrawSlot((BoxTask *)p,p[0x17]);
}

/*
 * Rebuild the row then forward it and the two tag shorts; the
 *   three callers share p[0x14] as the id.
 */
void BOX2_MAIN_GetBoxMon(BoxTask *p, unsigned char *a)
{
    int x = (int)POKE_TOOL_GetBoxParam(POKEPARTY_GetMember(*(void **)(*(int *)&p->params + 8),
                                        ((BoxMonRef *)(a))->slot - 0x1e));
    func_020075B0((void *)(*(int *)(*(int *)&p->params + 4)), p->curBox,
                  ((BoxMonRef *)(a))->pos, (const struct Sub020075B0Entry *)x);
    BOX2_MAIN_ClearSlot((char **)p, p->curBox, ((BoxMonRef *)(a))->slot);
    BOX2_UI_DrawSlot((BoxTask *)p, p->curBox);
}

/*
 * Forward two biased halfword coordinates.
 */
void BOX2_MAIN_SwapPartyMembers(char **p, char *q)
{
    POKEPARTY_SwapMembers((struct Party *)(((BoxParam *)((*p)))->party), ((BoxMonRef *)(q))->slot - 0x1e,
                  ((BoxMonRef *)(q))->pos - 0x1e, 0x4c);
}

/*
 * Walk the p+8 object's entries from tag-0x1e to the current
 *   count, re-reading the count each step.
 */
void BOX2_MAIN_ShiftMemberToEnd(int *p, unsigned char *a)
{
    unsigned i = ((BoxMonRef *)(a))->slot - 0x1e;
    while (i < POKEPARTY_GetCount(*(void **)(*p + 8)) - 1) {
        POKEPARTY_SwapMembers((struct Party *)(*(int *)(*p + 8)), i, i + 1, 0x4c);
        i++;
    }
}

void BOX2_MAIN_CompactParty(unsigned char *p,unsigned a,unsigned b,unsigned c)
{
    void *m;
    unsigned box;
    m = (void *)BOX2_MAIN_GetMonAt((void ***)p,a,b);
    box = BOX2_MAIN_WrapSlot((unsigned char *)p,c);
    func_0200752C((*(void ***)p)[1],box,m);
    func_02007664((*(void ***)p)[1],a,b);
    BOX2_UI_DrawSlot((BoxTask *)p,a);
    BOX2_UI_DrawSlotByName((char *)p,a);
    BOX2_UI_DrawSlot((BoxTask *)p,box);
    BOX2_UI_DrawSlotByName((char *)p,box);
}

/*
 * lever: declaring m before box selects r7 for m and r6 for box.
 */
void BOX2_MAIN_RegisterSeenAndForm(unsigned char *p,unsigned a,unsigned b)
{
    void *m;
    unsigned box;
    box=BOX2_MAIN_WrapSlot((unsigned char *)p,b);
    m=POKEPARTY_GetMember((*(void ***)p)[2],a-30);
    if(POKE_TOOL_GetPartyValue((void *)m,5,0)==492){
        POKE_TOOL_ChangeForm((void *)m,0);
        BOX2_MAIN_RecalcPartyParam((void **)p,a);
        ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData((*(void ***)p)[0]),m);
    }
    func_0200752C((*(void ***)p)[1],box,POKE_TOOL_GetBoxParam((void *)m));
    BOX2_MAIN_ClearSlot((char **)p,p[0x14],a);
    BOX2_UI_DrawSlot((BoxTask *)p,box);
    BOX2_UI_DrawSlotByName((char *)p,box);
}

void BOX2_MAIN_UpdateBoxSlots(BoxTask *p)
{
    BoxMove *m = p->work->seq.entry;
    unsigned short n;
    if (m->a == 0xFF)
        return;
    n = POKEPARTY_GetCount(((void **)p->params)[2]);
    if (m->b >= 0x24) {
        if (m->a < 0x1E)
            BOX2_MAIN_CompactParty((unsigned char *)p, p->heldSlot, m->a, m->b - 0x24);
        else
            BOX2_MAIN_RegisterSeenAndForm((unsigned char *)p, m->a, m->b - 0x24);
        return;
    }
    if (m->a < 0x1E) {
        if (m->b < 0x1E) {
            func_02007610(((void **)p->params)[1], p->heldSlot, m->a, p->curBox, m->b);
            BOX2_UI_DrawSlot((BoxTask *)p, p->curBox);
            BOX2_UI_DrawSlotByName((char *)p, p->curBox);
            if (p->curBox != p->heldSlot) {
                BOX2_UI_DrawSlot((BoxTask *)p, p->heldSlot);
                BOX2_UI_DrawSlotByName((char *)p, p->heldSlot);
            }
            return;
        }
        if (m->b - 0x1E < n) {
            BOX2_MAIN_MoveMonToParty((unsigned char *)p, (short unsigned int *)(&m->e[0]), (short unsigned int *)(&m->e[1]));
            BOX2_MAIN_MoveMonIntoBox((BoxTask *)p, m->b, m->a, p->heldSlot);
        } else {
            BOX2_MAIN_AddMonToParty((unsigned char *)p, (short unsigned int *)(&m->e[0]));
            BOX2_MAIN_MoveMonIntoBox((BoxTask *)p, m->b, m->a, p->heldSlot);
        }
        return;
    }
    if (m->b < 0x1E) {
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, m->b, p->curBox, 0xA9, 0)) {
            BOX2_MAIN_MoveMonToParty((unsigned char *)p, (short unsigned int *)(&m->e[1]), (short unsigned int *)(&m->e[0]));
            BOX2_MAIN_MoveMonIntoBox((BoxTask *)p, m->b, m->a, p->curBox);
        } else {
            BOX2_MAIN_GetBoxMon((BoxTask *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
            BOX2_MAIN_MoveMonIntoBox((BoxTask *)p, m->b, m->a, p->curBox);
        }
        return;
    }
    if (m->b - 0x1E < n)
        BOX2_MAIN_SwapPartyMembers((char **)p, (char *)m);
    else
        BOX2_MAIN_ShiftMemberToEnd((int *)p, (unsigned char *)(&m->e[m->a - 0x1E]));
}

int BOX2_MAIN_WrapSlot(unsigned char *p, unsigned i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    return v;
}

int BOX2_MAIN_HasOtherTradable(void ***p, unsigned skip)
{
    unsigned i;
    for (i = 0; i < POKEPARTY_GetCount((*p)[2]); i++) {
        if (i != skip) {
            void *m = POKEPARTY_GetMember((*p)[2], i);
            if (POKE_TOOL_GetPartyValue((void *)m, 0x4C, 0) == 0 && POKE_TOOL_GetPartyValue((void *)m, 0xA0, 0) != 0)
                return 1;
        }
    }
    return 0;
}

void BOX2_MAIN_ChangeFormAndRegister(void **pp, void *a, u32 b)
{
    void *r;

    POKE_TOOL_ChangeBoxForm((int)a, b);
    r = POKE_TOOL_CreateFromBoxParam((struct Mon *)a, 0x4c);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData((void *)(*(u32 *)*pp)), r);
    func_020307B0((void *)r);
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
int BOX2_MAIN_CanPlaceInBox(void **pp, void *mon)
{
    u16 species = func_02017E88((void *)mon, 5, 0);
    if (species == 0x1ED) {
        u16 item = func_02017E88((void *)mon, 6, 0);
        u16 form = func_02017E88((void *)mon, 0x6F, 0);
        u16 want = POKE_TOOL_GetPlateTypeForwarder(item);
        if (form != want)
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x289) {
        u16 item = func_02017E88((void *)mon, 6, 0);
        u16 form = func_02017E88((void *)mon, 0x6F, 0);
        u16 want = POKE_TOOL_GetBoxParamIndex(item);
        if (form != want)
            BOX2_MAIN_ChangeFormAndRegister(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x1E7) {
        u16 item = func_02017E88((void *)mon, 6, 0);
        u16 old = func_02017E88((void *)mon, 0x6F, 0);
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
void BOX2_MAIN_MoveMonIntoBox(BoxTask *p,unsigned a,unsigned b,unsigned box)
{
    if(a<30 && b<30) return;
    if(a>=30 && b>=30) return;
    if(a>=30) a=b;
    if(BOX2_MAIN_GetPartyValueAt((void ***)p,a,box,5,0)!=492) return;
    if(BOX2_MAIN_GetPartyValueAt((void ***)p,a,box,0x6f,0)==0) return;
    BOX2_MAIN_ChangeFormAndRegister((void **)p,(void *)BOX2_MAIN_GetMonAt((void ***)p,box,a),0);
    BOX2_MAIN_RecalcPartyParam((void **)p,a);
    if(box==p->curBox)
        BOX2_SEQ_ShowSlotIcon((BoxTask *)p,box,a,*(unsigned char *)((char *)p->work +a+0x3dd2));
    if(p->cursorSlot==a) BOX2_MAIN_ChangeBoxFormPreserve((BoxTask *)p,a);
}

void BOX2_MAIN_RecalcPartyParam(void **pp, u32 idx)
{
    void *h;
    u32 v;

    if (idx < 0x1e)
        return;
    h = POKEPARTY_GetMember(((BoxParam *)(((char *)*pp)))->party, idx - 0x1e);
    v = POKE_TOOL_DecodePartyParam((struct Sav *)h);
    POKE_TOOL_RecalcParam((void *)h);
    POKE_TOOL_EncodePartyParam((struct Sav *)h, v);
}

void BOX2_MAIN_LoadFormTable(char *p) { ((BoxTask *)p)->work->formTable=POKE_PERSONAL_LoadFormTable(76,0);((BoxTask *)p)->work->nationalDexEnabled=ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(**(void ** *)&((BoxTask *)p)->params)); }

/*
 * Tail call func_020307B0 with the word at +0x2c/+0x180.
 */
void BOX2_MAIN_DeleteFormTable(BoxTask *p)
{
    func_020307B0((void *)p->work->formTable);
}

int BOX2_MAIN_GetBoxValue(char *p, u32 a) { u16 n;n=BOX2_MAIN_GetPartyValueAt((void ***)p,a,((BoxTask *)p)->curBox,5,0);return func_020092AC(*(u8 * *)&((BoxTask *)p)->params->extra,n); }

int BOX2_MAIN_WaitCursorMove(BoxTask *p)
{
    BoxMove *m = p->work->seq.entry;
    BoxMover *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            BOX2_SEQ_SetSlotDrawPriorityB((BoxWork *)p->work, e->id, e->slot, 1);
            k = *(unsigned char *)((char *)p->work + e->id + 0x3DD2);
            if (e->slot < 0x1E) {
                BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], p->phase);
            } else if (e->slot < 0x24) {
                BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], p->phase);
                if (p->phase == 2 && BOX2_UI_IsTopBarMid(p->work->winMgr) == 0)
                    t[0] += 0xC0;
            } else {
                if (e->id >= 0x1E) {
                    BOX2_SEQ_GetSlotPos(0x24, &t[1], &t[0], p->phase);
                    if (p->phase == 2 && BOX2_UI_IsTopBarMid(p->work->winMgr) == 0)
                        t[0] += 0xC0;
                } else {
                    BOX2_SEQ_GetSlotPos(e->id, &t[1], &t[0], p->phase);
                }
                BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, k, 0);
            }
            BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, k, t[1], t[0], 0);
            if (e->used == 2)
                BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, k, 0);
        }
        BOX2_SEQ_SetSlotDimB((char **)p, p->cursorSlot);
        BOX2_SEQ_MoveCursorToSlot(p->work, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)((char *)p->work + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, k, t[1], t[0], 0);
        BOX2_SEQ_SetSlotDrawPriority((BoxWork *)p->work, e->id, 0);
    }
    BOX2_SEQ_SetSlotDimB((char **)p, p->cursorSlot);
    BOX2_SEQ_MoveCursorToSlot(p->work, 0x24);
    return 1;
}

/*
 * Twin of src/matched/ov170_func_021DD930.c.
 */
int BOX2_MAIN_WaitBoxScroll(BoxTask *p)
{
    BoxMove *m = p->work->seq.entry;
    BoxMover *e;
    unsigned i;
    int k;
    short t[2];
    if (m->count == 8) {
        for (i = 0; i < 7; i++) {
            e = &m->e[i];
            if (e->used == 0)
                continue;
            k = *(unsigned char *)((char *)p->work + e->id + 0x3DD2);
            BOX2_SEQ_GetSlotPos(e->slot, &t[1], &t[0], p->phase);
            if (e->slot >= 0x1E)
                t[0] += 0x90;
            BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, k, t[1], t[0], 0);
        }
        BOX2_SEQ_MoveCursorToSlot(p->work, 0x24);
        return 0;
    }
    m->count++;
    for (i = 0; i < 7; i++) {
        e = &m->e[i];
        if (e->used == 0)
            continue;
        k = *(unsigned char *)((char *)p->work + e->id + 0x3DD2);
        t[1] = e->x + ((unsigned)(m->count * e->vx) >> 16) * e->dx;
        t[0] = e->y + ((unsigned)(m->count * e->vy) >> 16) * e->dy;
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, k, t[1], t[0], 0);
        BOX2_SEQ_SetSlotDrawPriority((BoxWork *)p->work, e->id, 0);
        break;
    }
    BOX2_SEQ_SetSlotDimB((char **)p, p->cursorSlot);
    BOX2_SEQ_MoveCursorToSlot(p->work, 0x24);
    return 1;
}

int BOX2_MAIN_HandleMonPickup(BoxTask *p, unsigned a, unsigned b)
{
    unsigned m;
    if (b >= 0x24) {
        int n = BOX2_MAIN_WrapSlot((unsigned char *)p, b - 0x24);
        if (n == p->curBox || func_020078C4((void *)p->params->boxSave, n) == 0x1E) {
            (((BoxTask *)(p))->work->result) = 1;
            return 0;
        }
        if (a >= 0x1E) {
            if (BOX2_MAIN_HasOtherTradable((void ***)p, a - 0x1E) == 0) {
                (((BoxTask *)(p))->work->result) = 3;
                return 0;
            }
            if (FILE_UTIL_Check136C(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((void *)p->params->party, a - 0x1E), 6, 0)) == 1) {
                (((BoxTask *)(p))->work->result) = 2;
                return 0;
            }
        }
        m = 0;
    } else {
        m = BOX2_MAIN_GetPartyValueAt((void ***)p, b, p->curBox, 0xA9, 0);
    }
    if (p->params->mode == 4) {
        if (p->params->linkMode == 1) {
            (((BoxTask *)(p))->work->result) = 5;
            return 0;
        }
        if (a < 0x1E && b >= 0x1E && b < 0x24 && BOX2_MAIN_GetPartyValueAt((void ***)p, a, p->heldSlot, 0x4C, 0) != 0) {
            (((BoxTask *)(p))->work->result) = 4;
            return 0;
        }
        if (a >= 0x1E && a < 0x24 && b < 0x1E && m != 0 && BOX2_MAIN_GetPartyValueAt((void ***)p, b, p->curBox, 0x4C, 0) != 0) {
            (((BoxTask *)(p))->work->result) = 4;
            return 0;
        }
    }
    if (a >= 0x1E) {
        if (BOX2_MAIN_HasOtherTradable((void ***)p, a - 0x1E) == 0) {
            if (m == 0) {
                if ((b < 0x1E || b >= 0x24) && p->params->mode != 4) {
                    (((BoxTask *)(p))->work->result) = 3;
                    return 0;
                }
            } else if (BOX2_MAIN_GetPartyValueAt((void ***)p, b, p->curBox, 0x4C, 0) != 0 && b < 0x1E && p->params->mode != 4) {
                (((BoxTask *)(p))->work->result) = 3;
                return 0;
            }
        }
        if (b < 0x1E && FILE_UTIL_Check136C(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((void *)p->params->party, a - 0x1E), 6, 0)) == 1) {
            (((BoxTask *)(p))->work->result) = 2;
            return 0;
        }
    } else if (b >= 0x1E && m != 0) {
        if (FILE_UTIL_Check136C(POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((void *)p->params->party, b - 0x1E), 6, 0)) == 1) {
            (((BoxTask *)(p))->work->result) = 2;
            return 0;
        }
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, a, p->heldSlot, 0x4C, 0) != 0 && BOX2_MAIN_HasOtherTradable((void ***)p, b - 0x1E) == 0 && p->params->mode != 4) {
            (((BoxTask *)(p))->work->result) = 3;
            return 0;
        }
    }
    (((BoxTask *)(p))->work->result) = 0;
    return 1;
}

/*
 * trailing: two bytes alignment padding at 0x021DDE7E.
 */
int BOX2_MAIN_ComparePartyValue(unsigned char *p,unsigned a,unsigned b)
{
    int result = 0;
    if (BOX2_MAIN_GetPartyValueAt((void ***)p,(unsigned short)b,p[0x14],0xa9,0))
        return result;
    if (!BOX2_MAIN_HasOtherTradable((void ***)p,a-30))
        return result;
    if (FILE_UTIL_Check136C((unsigned short)POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((*(void ***)p)[2],a-30),6,0)) != 1)
        result = 1;
    return result;
}

int BOX2_MAIN_CompareSlots(unsigned char *p, unsigned a, unsigned b)
{
    if (BOX2_MAIN_GetPartyValueAt((void ***)p, b, p[0x14], 0xA9, 0) == 0)
        return 0;
    if (BOX2_MAIN_GetPartyValueAt((void ***)p, b, p[0x14], 0x4C, 0) != 0)
        return 0;
    if (FILE_UTIL_Check136C(BOX2_MAIN_GetPartyValueAt((void ***)p, a, p[0x14], 6, 0)) == 1)
        return 0;
    if (FILE_UTIL_Check136C(BOX2_MAIN_GetPartyValueAt((void ***)p, b, p[0x14], 6, 0)) == 1)
        return 0;
    return 1;
}

void BOX2_MAIN_AdvanceMover(BoxTask *p, BoxMover *o)
{
    short t[2];
    BOX2_SEQ_GetActorSurfacePos(p->work, *(unsigned char *)((char *)p->work + o->id + 0x3DD2), &o->x, &o->y, 0);
    if (o->used != 2) {
        if (o->slot < 0x24)
            BOX2_SEQ_GetSlotPos(o->slot, &t[1], &t[0], p->phase);
        else
            BOX2_UI_FindSlotPos(p->work, o->slot - 0x24, &t[1], &t[0]);
    } else if (p->curBox > p->heldSlot) {
        BOX2_SEQ_GetActorSurfacePos(p->work, 0, &t[1], &t[0], 0);
    } else {
        BOX2_SEQ_GetActorSurfacePos(p->work, 1, &t[1], &t[0], 0);
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

void BOX2_MAIN_UpdateMoverX(BoxTask *p,BoxMover *o)
{
    short t[2];
    unsigned i;
    i=*(unsigned char *)((char *)p->work +o->slot+0x3dd2);
    BOX2_SEQ_GetActorSurfacePos(p->work,*(unsigned char *)((char *)p->work +o->id+0x3dd2),&o->x,&o->y,0);
    BOX2_SEQ_GetActorSurfacePos(p->work,i,&t[1],&t[0],0);
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

void BOX2_MAIN_UpdateMoverY(BoxTask *p, BoxMover *o)
{
    short t[2];
    BOX2_SEQ_GetActorSurfacePos(p->work, *(unsigned char *)((char *)p->work + o->id + 0x3DD2), &o->x, &o->y, 0);
    BOX2_SEQ_GetSlotPos(o->slot, &t[1], &t[0], p->phase);
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
void BOX2_MAIN_StepMover(BoxTask *p, int a, int b)
{
    unsigned short *q = p->work->seq.entry;
    q[0] = 0x24;
    q[1] = b;
    q[2] = a;
    q[3] = 1;
    BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)q);
    q[12] = (unsigned short)b;
    q[13] = a;
    q[14] = (unsigned short)b;
    q[15] = 1;
    BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(q + 12));
}

int BOX2_MAIN_MoveCursorWithMon(BoxTask *p, unsigned a, unsigned b)
{
    BoxMove *m = p->work->seq.entry;
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
        if (p->curBox == p->heldSlot) {
            m->e[1].id = t;
            m->e[1].slot = t;
            m->e[1].src = t;
            m->e[1].used = 1;
        }
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[0]));
        return 0;
    }
    if ((a == b && (a >= 0x1E || p->curBox == p->heldSlot)) || BOX2_MAIN_HandleMonPickup((BoxTask *)p, a, b) == 0) {
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
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[0]));
        return 0;
    }
    m->a = a;
    m->b = b;
    n = POKEPARTY_GetCount(((void **)p->params)[2]);
    if (b >= 0x24) {
        m->e[0].id = 0x24;
        m->e[0].slot = b;
        m->e[0].src = 0x24;
        m->e[0].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[0]));
        if (a >= 0x1E) {
            for (i = a - 0x1D; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                BOX2_MAIN_UpdateMoverY((BoxTask *)p, (BoxMover *)e);
            }
            e = &m->e[n];
            t = a;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_UpdateMoverY((BoxTask *)p, (BoxMover *)e);
        }
        return 1;
    }
    if (p->curBox != p->heldSlot && a < 0x1E) {
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
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[0]));
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[1]));
        return 1;
    }
    if (a < 0x1E) {
        if (b < 0x1E)
            BOX2_MAIN_StepMover((BoxTask *)p, a, b);
        else if (b - 0x1E < n)
            BOX2_MAIN_StepMover((BoxTask *)p, a, b);
        else
            BOX2_MAIN_StepMover((BoxTask *)p, a, n + 0x1E);
    } else if (b < 0x1E) {
        if (BOX2_MAIN_GetPartyValueAt((void ***)p, b, p->curBox, 0xA9, 0) != 0) {
            BOX2_MAIN_StepMover((BoxTask *)p, a, b);
        } else {
            unsigned k = a - 0x1E;
            for (i = k + 1; i < n; i++) {
                e = &m->e[i];
                t = i + 0x1E;
                e->id = t;
                e->slot = i + 0x1D;
                e->src = t;
                e->used = 1;
                BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)e);
            }
            m->e[k].id = 0x24;
            m->e[k].slot = b;
            m->e[k].src = a;
            m->e[k].used = 1;
            BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[k]));
            e = &m->e[n];
            t = b;
            e->id = t;
            e->slot = n + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)e);
        }
    } else if (b - 0x1E < n) {
        BOX2_MAIN_StepMover((BoxTask *)p, a, b);
    } else {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = n + 0x1D;
        m->e[k].src = a;
        m->e[k].used = 1;
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[k]));
    }
    return 1;
}

/*
 * Sibling of src/matched/ov170_func_021DE158.c.
 */
void BOX2_MAIN_SwapWithNeighbour(BoxTask *p, unsigned a, unsigned b)
{
    BoxMove *m = p->work->seq.entry;
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
    if (b == 0xFF || BOX2_MAIN_ComparePartyValue((unsigned char *)p, a, b) == 0) {
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
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)(&m->e[0]));
        return;
    }
    m->a = a;
    m->b = b;
    n = POKEPARTY_GetCount(((void **)p->params)[2]);
    if (b < 0x1E) {
        unsigned k = a - 0x1E;
        for (i = k + 1; i < n; i++) {
            e = &m->e[i];
            t = i + 0x1E;
            e->id = t;
            e->slot = i + 0x1D;
            e->src = t;
            e->used = 1;
            BOX2_MAIN_UpdateMoverX((BoxTask *)p, (BoxMover *)e);
        }
        m->e[k].id = 0x24;
        m->e[k].slot = b;
        m->e[k].src = a;
        m->e[k].used = 1;
        BOX2_MAIN_UpdateMoverX((BoxTask *)p, (BoxMover *)(&m->e[k]));
        e = &m->e[n];
        t = b;
        e->id = t;
        e->slot = n + 0x1D;
        e->src = t;
        e->used = 1;
        BOX2_MAIN_UpdateMoverX((BoxTask *)p, (BoxMover *)e);
    }
}






/*
 * Clears the seven move slots, then either starts a slide from a to b or,
 * when b is not a movable box, snaps to it.
 */
void BOX2_MAIN_SetMoverTarget(BoxTask *p, int a, int b)
{
    BoxMover *o = p->work->seq.entry;
    unsigned i;
    for (i = 0; i < 7; i++) {
        o[i].id = 0;
        o[i].slot = 0;
        o[i].src = 0;
        o[i].used = 0;
    }
    if (b == 0xFF || BOX2_MAIN_GetPartyValueAt((void ***)p, b, p->curBox, 0xA9, 0)) {
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
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)((BoxMover *)o));
    } else {
        ((BoxMove *)(o))->a = a;
        ((BoxMove *)(o))->b = b;
        BOX2_MAIN_StepMover((BoxTask *)p, a, POKEPARTY_GetCount(p->params->party) + 0x1E);
    }
}

int BOX2_MAIN_FindMoverSlot(BoxTask *p, unsigned id)
{
    BoxMover *e = p->work->seq.entry;
    unsigned i;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0 && id == e[i].id)
            return e[i].slot;
    }
    return ((unsigned char *)p)[0x16];
}

void BOX2_MAIN_StartMover(BoxTask *p,unsigned a)
{
    BoxMover *o;
    unsigned i;
    unsigned slot;
    o=p->work->seq.entry;
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
        BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)((BoxMover *)(&o[i])));
    }
    o[slot].slot=35;
    o[slot].used=1;
    BOX2_MAIN_AdvanceMover((BoxTask *)p, (BoxMover *)((BoxMover *)(&o[slot])));
}

void BOX2_MAIN_SetMoverEntry(BoxTask *p, BoxMover *e)
{
    unsigned char buf[7];
    unsigned short i;
    unsigned short save = 0xFFFF;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0)
            buf[i] = *(unsigned char *)((char *)p->work + e[i].src + 0x3DD2);
    }
    for (i = 0; i < 7; i++) {
        if (e[i].used == 0)
            continue;
        if (e[i].slot <= 0x24) {
            *(unsigned char *)((char *)p->work + e[i].slot + 0x3DD2) = buf[i];
            if (e[i].id == 0x24)
                save = e[i].slot;
        } else {
            p->work->cursorActorId = buf[i];
            if (e[i].id == 0x24)
                save = 0x24;
        }
    }
    if (save != 0xFFFF)
        BOX2_SEQ_SwapSlotActorsB((BoxWork *)p->work, save);
    for (i = 0; i < 0x24; i++)
        BOX2_SEQ_SetSlotDrawPriority((BoxWork *)p->work, i, 1);
}

/*
 * Return -1.
 */
int BOX2_MAIN_GetMinusOne(unsigned short a)
{
    return -1;
}





void BOX2_MAIN_ResetMovers(BoxTask *p)
{
    BoxCursor *s;
    void *m;
    unsigned i;
    int r;
    p->work->scroll=func_02030734(0x804c,12,0,d_021F1400,0xa70);
    s=p->work->scroll;
    s->p=*(void **)((char *)p->work +*(unsigned char *)((char *)p->work +p->cursorSlot+0x3dd2)*4+0x9e74);
    s->index=0;
    s->flags=0;
    m=(void *)BOX2_MAIN_GetMonAt((void ***)p,p->curBox,p->cursorSlot);
    for(i=0;i<4;i++){
        r=BOX2_MAIN_GetMinusOne((unsigned short)func_02017E88((void *)m,i+0x36,0));
        if(r!=-1){s->flags|=(unsigned char)(1<<r);return;}
    }
}

/*
 * Tail call func_020307B0 with the pooled-offset word.
 */
void BOX2_MAIN_DeleteScroll(BoxTask *p)
{
    func_020307B0((void *)p->work->scroll);
}

/*
 * lever: Spell the byte-mask update as plain assignment; compound assignment inserts an extra truncation pair.
 */
int BOX2_MAIN_StepScroll(BoxTask *p)
{
    BoxCursor *s=p->work->scroll;
    unsigned short n=s->index;
    unsigned j,i;
    void *m;
    int box,r,slot;
    if(n==726)return 0;
    for(j=0;j<15;j++){
        if(n<720){
            box=n/30;
            slot=n%30;
            if(box==p->curBox&&slot==p->cursorSlot) m=0;
            else m=(void *)BOX2_MAIN_GetMonAt((void ***)p,box,slot);
        }else{
            slot=n-720;
            if(slot==p->cursorSlot-30)m=0;
            else m=(void *)BOX2_MAIN_GetMonAt((void ***)p,255,slot);
        }
        if(m&&func_02017E88((void *)m,0xa9,0)!=0){
            for(i=0;i<4;i++){
                r=BOX2_MAIN_GetMinusOne((unsigned short)func_02017E88((void *)m,i+0x36,0));
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
 *   GAME_DATA_GetBoxSave ((void *)0x02012F98) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void BOX2_MAIN_PlayMonCry(int *q)
{
    int *r = *(int * *)&((BoxTask *)(q))->params;

    if ((((unsigned int)((BoxParam *)(r))->mode) - 4) > 1)
        func_02007C34((struct PerapVoice *)GAME_DATA_GetBoxSave((void *)(((BoxParam *)(r))->gameData)), (void *)(((BoxParam *)(r))->party));
}

void BOX2_MAIN_PlaceMonScene(BoxTask *p, int slot, unsigned idx, int mode, int flag)
{
    BoxMotor *o = p->work->seq.entry;
    short pos[2];
    short to[2];
    int d;
    BOX2_SEQ_GetActorSurfacePos(p->work,10,&pos[1],&pos[0],0);
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

void BOX2_MAIN_ClearFlagsScene(BoxTask *p, int mode)
{
    BoxMotor *o = p->work->seq.entry;
    short pos[2];
    short to[2];
    int d;
    BOX2_SEQ_GetActorSurfacePos(p->work, 10, &pos[1], &pos[0], 0);
    if (p->curBox > p->heldSlot)
        BOX2_SEQ_GetActorSurfacePos(p->work, 0, &to[1], &to[0], 0);
    else
        BOX2_SEQ_GetActorSurfacePos(p->work, 1, &to[1], &to[0], 0);
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
void BOX2_MAIN_PlaceMonSceneFromBox(int a, int b, int c, int d)
{
    BOX2_MAIN_PlaceMonScene((BoxTask *)a, b, c, d, 1);
}

void BOX2_MAIN_PlaceTargetMonScene(BoxTask *p, int a, int b)
{
    BOX2_MAIN_PlaceMonScene((BoxTask *)p, p->work->targetBox, a, b, 0);
}







/*
 * extent: final two bytes are zero alignment padding.
 */
int BOX2_MAIN_CheckSceneMode(BoxTask *p, int a)
{
    Motion *m;
    m = p->work->seq.entry;
    if (m->count == 8) {
        if (m->index != 255) {
            if (a == 1)
                BOX2_SEQ_MoveActorToSlot(p->work, m->index, m->value);
            else
                BOX2_SEQ_MoveActorToSlotB(p->work, m->index, m->value);
        }
        BOX2_SEQ_LayoutHandSlots(p->work);
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
    BOX2_SEQ_MoveActor(p->work, (short)(m->x >> 8), (short)(m->y >> 8));
    BOX2_SEQ_LayoutHandSlots(p->work);
    m->count++;
    return 1;
}

/*
 * Set the flag on the object.
 */
int BOX2_MAIN_IsSwapScene(int a)
{
    return BOX2_MAIN_CheckSceneMode((BoxTask *)a, 1);
}

/*
 * Steps the object with mode 0 (sibling of BOX2_MAIN_IsSwapScene, which passes 1).
 */
int BOX2_MAIN_IsMoveScene(unsigned char *p)
{
    return BOX2_MAIN_CheckSceneMode((BoxTask *)p, 0);
}

/*
 * Add the 3rd/4th parameter to the signed byte at +0x19 and fold the
 * +0x15 field in: add it when negative (signed), subtract it when the
 * result is at or above the unsigned byte.
 */
unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a)
{
    signed char v = (signed char)p[0x19] + a;
    if (v < 0)
        v = v + (signed char)p[0x15];
    else if (v >= p[0x15])
        v = v - (signed char)p[0x15];
    return v;
}

void BOX2_MAIN_LoadBgCharTile(u32 a, int b, void *c)
{
    void *out;
    void *r;

    r = ARC_UTIL_LoadBgCharDataFromArchive(0x74, b + 0xe, 1, (u32)(&out), 0x4c);
    BG_SYS_LoadTileData(3, (const void *)(((BoxArcTile *)(out))->data), ((BoxArcTile *)(out))->size, (u32)c);
    func_020307B0((void *)r);
}

/*
 * Tail wrapper: builds the 6-argument NitroSystem call with the
 *   two stack words 0x20 and 0x4c; third argument shifted left 5.
 */
void BOX2_MAIN_LoadBgPaletteTile(int a, int b, int c)
{
    func_02049B40(0x74, b + 0x26, 0, c << 5, 0x20, 0x4c);
}

/*
 * abi: Original truncates the tile column into r2 before both call kinds, so their column parameters are u8.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`data=(u32)sheet;` before `data=(u32)sheet+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT in
 * --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 */
void BOX2_MAIN_LoadBgTileSet(void *unused, void *unused2, int x, u32 base, u32 pal)
{
    u8 *sheet;
    void *handle;
    u16 value;
    u32 data;
    u8 row,yn;
    u16 *src;
    u32 cur,high;
    u8 col;
    handle=ARC_UTIL_LoadPaletteDataFromArchive(116,13,1,(u32)&sheet,76);
    data=(u32)sheet+12;
    row=0;
    high=pal<<12;
    do{
        src=(u16 *)data+row*21;
        cur=x;
        col=0;
        yn=row+1;
        do{
            value=(src[col]&4095)+high+base;
            BG_SYS_DrawTile(3,(u32)&value,(u8)cur,yn,1,1);
            ++cur;if(cur>=64)cur=0;
            ++col;
        }while(col<21);
        ++row;
    }while(row<20);
    func_020307B0((void *)handle);
    BG_SYS_SetTileEntry(3,0xe287,cur,0,2,20,17);
    BG_SYS_SetTileEntry(3,0xe2b0,cur,5,2,1,17);
}

void BOX2_MAIN_LoadBgTiles(void *a, void *b, int c, void *d, int e)
{
    BOX2_MAIN_LoadBgCharTile((int)a, (int)b, d);
    BOX2_MAIN_LoadBgPaletteTile((int)a, (int)b, e);
    BOX2_MAIN_LoadBgTileSet(a, b, c, (unsigned int)d, e);
    func_02041B6C(3);
}

void BOX2_MAIN_SetBoxScroll(BoxTask *p, void *a, int dir)
{
    int d, e, i;
    BoxWork *q;
    if (dir == 0) {
        p->work->scrollOffset -= 0x17;
        if (p->work->scrollOffset < 0)
            p->work->scrollOffset += 0x40;
    } else if (dir == 1) {
        p->work->scrollOffset += 0x17;
        if (p->work->scrollOffset >= 0x40)
            p->work->scrollOffset -= 0x40;
    }
    q = p->work;
    if (((BoxWork *)q)->scrollDir == 0) {
        d = 0x25C;
        e = 0xE;
    } else {
        d = 0xB8;
        e = 0xF;
    }
    ((BoxWork *)q)->scrollDir ^= 1;
    BOX2_MAIN_LoadBgTiles((void *)p, a, p->work->scrollOffset, (void *)d, e);
    if (dir == 2) {
        BOX2_SEQ_DrawBoxName((char **)p, (unsigned char)p->curBox, 7);
        BOX2_UI_SetSlotOamEnabled((BoxWork *)p->work, 8, 0);
        return;
    }
    i = 7;
    if (BOX2_UI_GetSlotOamEnabled(p->work, 7) == 1)
        i = 8;
    BOX2_SEQ_DrawBoxName((char **)p, (unsigned char)p->curBox, i);
    BOX2_UI_MoveSlotOam((BoxWork *)p->work, i, dir);
    BOX2_UI_SetSlotOamEnabled((BoxWork *)p->work, i, 1);
}








void BOX2_MAIN_LoadBoxPalette(BoxTask *p, int a)
{
    int offset;
    int bank;
    if (p->work->scrollDir == 0) {
        offset = 0x25C;
        bank = 14;
    } else {
        offset = 0xB8;
        bank = 15;
    }
    p->work->scrollDir ^= 1;
    BOX2_MAIN_LoadBgCharTile((unsigned int)p, a, (void *)offset);
    PALANM_LoadArcPaletteToSlot(p->work->palAnm, 0x74, a + 0x26, 0x4C, 0, 0x20, bank << 4);
    BOX2_MAIN_LoadBgTileSet(p, (void *)a, p->work->scrollOffset, offset, bank);
    func_02041B6C(3);
}

/*
 * Forward the second word of the head object.
 */
int BOX2_MAIN_GetBoxFormId(BoxTask *p, int box)
{
    return func_0200781C((int)p->params->boxSave, box);
}

/*
 * Allocates the 0x1C-byte summary of a Pokemon (species, form, PID,
 * markings, level, flags, four moves); NULL for an empty slot.
 */
Summary *BOX2_MAIN_CreateSummary(void *mon)
{
    Summary *s;
    unsigned i;

    if (func_02017E88((void *)mon, 0xA9, 0) != 0) {
        s = func_02030734(0x4C, 0x1C, 0, d_021F1400, 0xCD2);
        s->mon = mon;
        s->species = func_02017E88((void *)mon, 5, 0);
        s->form = func_02017E88((void *)mon, 6, 0);
        s->pid = func_02017E88((void *)mon, 0, 0);
        s->cC = func_02017E88((void *)mon, 0xAE, 0);
        s->cD = func_02017E88((void *)mon, 0xAF, 0);
        s->cE = func_02017E88((void *)mon, 0xA, 0);
        s->cF = POKE_TOOL_GetBoxNature(mon);
        s->item = func_02017E88((void *)mon, 0xB, 0);
        s->level = func_02017E88((void *)mon, 0x9E, 0);
        s->egg = (unsigned char)func_02017E88((void *)mon, 0x4C, 0);
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
            s->moves[i] = func_02017E88((void *)mon, 0x36 + i, 0);
    } else {
        s = 0;
    }
    return s;
}

void BOX2_MAIN_DeleteHandle(void *s)
{
    func_020307B0((void *)s);
}

/*
 * Six-step handover: stage 0xb, rebuild, refresh, push the 0x10
 *   tag word, re-tag, then release handle 3.
 */
void BOX2_MAIN_SetupSummary(BoxTask *p, int a)
{
    BOX2_SEQ_LoadMonIconActor((char *)p, (void **)a, 0xb);
    BOX2_SEQ_ShowHandSlotB((BoxWork *)p->work, (unsigned char *)a);
    BOX2_SEQ_DeleteTextEntries((BoxTask *)p, a);
    BOX2_MAIN_SetBodySlots((char *)p, ((Summary *)(a))->item);
    BOX2_MAIN_SetupSummaryActors(p->work, (Summary *)a);
    BG_SYS_ResetSlot(5, 3, 0);
}

int BOX2_MAIN_ChangeBoxForm(char *p, int a, unsigned b)
{
    void *mon;
    int state;
    void *s;
    mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, a, b);
    if (mon) {
        state = POKE_TOOL_DecodeBoxParam((struct Sav *)mon);
        s = BOX2_MAIN_CreateSummary(mon);
        if (s) {
            BOX2_MAIN_SetupSummary((BoxTask *)p, (int)s);
            BOX2_MAIN_DeleteHandle(s);
            POKE_TOOL_EncodeBoxParam((struct Sav *)mon, state);
        } else {
            BOX2_MAIN_ResetBoxView((BoxTask *)p);
            POKE_TOOL_EncodeBoxParam((struct Sav *)mon, state);
            return 0;
        }
    } else {
        BOX2_MAIN_ResetBoxView((BoxTask *)p);
        return 0;
    }
    return 1;
}

/*
 * Forward with the byte field at +0x14.
 */
void BOX2_MAIN_ChangeBoxFormPreserve(BoxTask *p, int b)
{
    BOX2_MAIN_ChangeBoxForm((char *)p, p->curBox, b);
}

void BOX2_MAIN_SetBoxForm(BoxTask *p, unsigned b)
{
    void *mon;
    void *s;
    int state;
    mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, p->curBox, b);
    state = POKE_TOOL_DecodeBoxParam((struct Sav *)mon);
    s = BOX2_MAIN_CreateSummary(mon);
    BOX2_SEQ_LoadMonIconActor((char *)p, s, 11);
    BOX2_SEQ_ShowHandSlotB((BoxWork *)p->work, s);
    BOX2_SEQ_DeleteTextEntries((BoxTask *)p, (int)s);
    BOX2_MAIN_DeleteHandle(s);
    POKE_TOOL_EncodeBoxParam((struct Sav *)mon, state);
}




void BOX2_MAIN_ResetBoxView(BoxTask *p)
{
    unsigned i;
    if (p->work->cursorActorDrawn != 0)
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 0xB, 0);
    if (p->work->cursorActorAnim != 0)
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 0xC, 0);
    for (i = 0x1C; i < 0x2D; i++)
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, i, 0);
    BOX2_SEQ_ClearTextWin(p->work);
    BOX2_MAIN_HideSlots((BoxWork *)p->work);
    BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 0x19, 0);
    BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 0x1A, 0);
    BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 0x1B, 0);
    BG_SYS_ResetSlot(5, 3, 0xC0);
}

/*
 * Reset, clear the state, mark the 0x16 field.
 */
void BOX2_MAIN_ClearCursorBox(unsigned char *p)
{
    BOX2_MAIN_ResetBoxView((BoxTask *)p);
    BOX2_SEQ_SetSlotDim((char **)p, 0);
    p[0x16] = 0xff;
}

void BOX2_MAIN_SetSceneSlots(char *p,int base,u32 bits) { u16 i,v;for(i=0;i<6;i++){if(bits & (1<<i))v=i*2+1;else v=i*2;BOX2_SEQ_SetActorAnimSeq(((BoxTask *)p)->work,base+i,v);BOX2_SEQ_SetActorDrawEnable(((BoxTask *)p)->work,base+i,1);} }

void BOX2_MAIN_SetHandSlots(char *p, int b)
{
    BOX2_MAIN_SetSceneSlots((char *)p, 0xd, b);
}

/*
 * Forward with index 19.
 */
void BOX2_MAIN_SetBodySlots(char *p, int b)
{
    BOX2_MAIN_SetSceneSlots((char *)p, 0x13, b);
}

/*
 * Seat the six 0x13 entries.
 */
void BOX2_MAIN_HideSlots(BoxWork *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p, i + 0x13, 0);
}

void BOX2_MAIN_SetupSummaryActors(BoxWork *w, Summary *s)
{
    if (s->shiny == 0 || s->egg == 1)
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 25, 0);
    else
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 25, 1);
    if (s->mark == 0) {
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 26, 0);
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 27, 0);
    } else if (s->mark == 1) {
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 26, 0);
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 27, 1);
    } else {
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 26, 1);
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)w, 27, 0);
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
int BOX2_MAIN_HitPartyGrid(BoxTask *p, short x, short y)
{
    int v = BOX2_UI_GetGridSlotPoint(p->work->cursorX,
                          p->work->cursorY);
    unsigned w;
    if (v == 0xff)
        return v;
    w = v - 0x24 + p->prevBox;
    if (w >= p->boxLimit)
        w -= p->boxLimit;
    if (w == p->curBox)
        return 0xff;
    return v;
}

int BOX2_MAIN_PushPartyScene(BoxTask *p)
{
    Request_021DF040 *r;
    unsigned mode;
    r = func_02030734(0x4B, 0x28, 0, d_021F1400, 0xEAC);
    if (p->cursorSlot < 30) {
        r->mon = (void *)BOX2_MAIN_GetMonAt((void ***)p, p->heldSlot, 0);
        r->kind = 2;
        r->count = 30;
        r->slot = p->cursorSlot;
    } else {
        r->mon = (*(void ***)p)[2];
        r->kind = 1;
        r->count = POKEPARTY_GetCount((*(void ***)p)[2]);
        r->slot = p->cursorSlot - 30;
    }
    mode = 0;
    r->zero = 0;
    r->save = (*(void ***)p)[0];
    r->f4 = (*(void ***)p)[6];
    r->f18 = (*(void ***)p)[7];
    if ((*(int **)p)[5] == 1) {
        r->mode = 6;
    } else {
        r->mode = 0;
    }
    PROCSYS_Push((void *)p->procSys, (int)ov131_id, gPokeStatusProcData, r);
    *(Request_021DF040 * *)&p->subArgs = r;
    return 0;
}

/*
 * Clamp p[0x16] to 0x1e below the limit of the p+0xc object's
 *   byte 0xf, then hand the object to the SDK.  The callee argument is the
 *   re-read expression, not the local, which is why the image re-loads it.
 */
int BOX2_MAIN_PushPartySceneB(BoxTask *p)
{
    int q = (int)((BoxTask *)(p))->subArgs;
    if (p->handMode == 0) {
        if (p->cursorSlot < 0x1e)
            p->cursorSlot = ((Request_021DF040 *)(q))->slot;
        else
            p->cursorSlot = ((Request_021DF040 *)(q))->slot + 0x1e;
    }
    func_020307B0((void *)(((BoxTask *)(p))->subArgs));
    return 0;
}

int BOX2_MAIN_PushBagScene(void **p)
{
    void *r = BAG_PARAM_Create((const struct BigObj *)(*(u32 *)p[0]), 0, 2, 0x4b);

    PROCSYS_Push(p[1], (u32)ov070_id, (void *)0x021bb96c, r);
    p[3] = r;
    return 0;
}

/*
 * Mirror a word into a halfword field, forward, return 0.
 */
int BOX2_MAIN_PopSubArgs(BoxTask *p)
{
    char *q = *(char * *)&p->subArgs;

    ((BoxTask *)(p))->subResult = ((Request_021DF040 *)(q))->subResult;
    func_020307B0((void *)q);
    return 0;
}

/*
 * data: callback descriptor belongs to ov194 loaded by PROCSYS_Push.
 */
int BOX2_MAIN_PushNameScene(BoxTask *p)
{
    int value;
    Request_021DF378 *r;
    value = (int)BEACON_GetBlock(GAME_DATA_GetSaveControl((*(void ***)p)[0]));
    r = func_02030734(0x4B, 8, 1, d_021F1400, 0xF1F);
    r->text = STRBUF_Create(20, 0x4B);
    func_0200785C((*(void ***)p)[1], p->curBox, r->text);
    r->task = NAMEIN_SETUP_CreateArgs(0x4B, 2, 0, 0, 8, (int)r->text, value);
    PROCSYS_Push((void *)p->procSys, (int)ov194_id, gNameInProcData, r->task);
    *(Request_021DF378 * *)&p->subArgs = r;
    return 0;
}



int BOX2_MAIN_PopNameScene(u8 *p){char **q;q=*(char ** *)&((BoxTask *)p)->subArgs;if(((BoxNameArgs *)((*q)))->done==0)func_02007898(((BoxTask *)p)->params->boxSave,p[0x14],((BoxNameArgs *)((*q)))->text);((BoxTask *)p)->subResult=((BoxNameArgs *)((*q)))->done;NAMEIN_SETUP_FreeArgs((int)*q);STRBUF_Delete((struct U16Vec *)q[1]);func_020307B0(((BoxTask *)p)->subArgs);return 0;}

void BOX2_MAIN_MoveCursorActor(BoxTask *p, int x, int y)
{
    BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, p->work->cursorActorId, (short)x, (short)((short)y - 8), 0);
    BOX2_SEQ_MoveCursorToSlot(p->work, 0x24);
    p->work->cursorX = x;
    p->work->cursorY = y;
}

int BOX2_MAIN_StateMachinePick(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    int busy = BOX2_UI_UpdateBarMove((BoxTask *)p);
    unsigned r = BOX2_UI_UpdateListPacks(p->work->winMgr);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(p->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            p->work->touchState = 0;
            b->timer = 0;
            r = 0xFF;
            if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
                BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
                r = BOX2_MAIN_HitPartyGrid((BoxTask *)p, p->work->cursorX, p->work->cursorY);
                if (r == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, r) == 0) {
                    BOX2_UI_CloseInfoBar(p->work->winMgr);
                    GFL_USE_PlaySeDefaultVolume(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1) {
                r = BOX2_MAIN_HitPartySlots(p->work->cursorX, p->work->cursorY, d_021EF79C);
                if (r == 0xFF)
                    r = BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY));
            }
            if (BOX2_UI_IsTopBarClosed(p->work->winMgr) == 1)
                r = BOX2_MAIN_HitPartySlots(p->work->cursorX, p->work->cursorY, d_021EF7B4);
            if ((*(int **)p)[9] == 4 && (*(int **)p)[5] == 1) {
                r = 0xFF;
                p->work->result = 5;
            }
            BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, r);
            if (BOX2_UI_IsListClosed(p->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            if (r != 0xFF)
                p->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)p, 0x24);
            if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0 && BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 0 && busy == 0)
                BOX2_UI_CloseListPack(p->work->winMgr);
            b->state = 2;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && r == 0) {
            if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0 && BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 0 && BOX2_UI_GetPageButtonHit() == 0) {
                p->heldSlot = 0xFF;
                p->phase = 2;
                BOX2_UI_SlideBarIn(p->work->winMgr);
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
                BOX2_UI_ToggleSlotPair((BoxWork *)p->work, 1);
                BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
                if ((*(int **)p)[9] == 4)
                    CURSOR_MOVE_ClearSkipBit(p->work->sound, 0x27);
                BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 2);
                p->work->heldSlot = p->cursorSlot;
                p->work->waitFrames = 0x17;
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
            if ((*(int **)p)[9] != 4) {
                if (BOX2_UI_GetPageButtonHit2() != -1) {
                    if (p->work->touchState == 0) {
                        if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
                            BOX2_UI_CloseInfoBar(p->work->winMgr);
                            BOX2_MAIN_UpdateWindowFrame((BoxTask *)p, 0xA);
                            GFL_USE_PlaySeDefaultVolume(0x54C);
                            GFL_USE_PlaySeDefaultVolume(0x669);
                            p->work->touchState = 1;
                            b->state = 0xB;
                        }
                        if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1) {
                            BOX2_UI_OpenBar(p->work->winMgr);
                            BOX2_MAIN_UpdateWindowFrame((BoxTask *)p, 0xB);
                            GFL_USE_PlaySeDefaultVolume(0x54C);
                            GFL_USE_PlaySeDefaultVolume(0x669);
                            p->work->touchState = 1;
                            b->state = 0xD;
                        }
                    }
                } else {
                    p->work->touchState = 0;
                }
            }
            if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
                int dir = BOX2_UI_GetExitButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_SelectBox((BoxTask *)p, -1);
                    b->state = 8;
                    b->timer = 0;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_SelectBox((BoxTask *)p, 1);
                    b->state = 9;
                    b->timer = 0;
                }
            }
            if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
                int k = BOX2_UI_GetGridSlotPoint(x, y);
                if (k != 0xFF)
                    BOX2_UI_SetMiniIconVisible((BoxTask *)p, k - 0x24, 1);
                else
                    BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
            }
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
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
    case 8:
        if (BOX2_SEQ_OpenBoxDown((BoxTask *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 9:
        if (BOX2_SEQ_OpenBoxUp((BoxTask *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 10:
        if (BOX2_MAIN_ShiftWindowRight(p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 11:
        BOX2_MAIN_IsTaskMenuFinished(p);
        if (BOX2_MAIN_ShiftWindowLeft(p) == 0) {
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            BOX2_SEQ_HidePartialSlots((char **)p, 1);
            BOX2_UI_HideWindowA((BoxWork *)p->work);
            BOX2_UI_ShowWindowB((BoxWork *)p->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xC;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 12:
        if (busy == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 13:
        BOX2_MAIN_IsTaskMenuFinished(p);
        if (busy == 0) {
            BOX2_MAIN_RefreshBoxUi(p);
            BOX2_UI_HideWindowB((BoxWork *)p->work);
            BOX2_UI_ShowWindowA((BoxWork *)p->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xA;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry((BoxTask *)p, (BoxMover *)b->entry);
        if (BOX2_UI_IsTopBarClosed(p->work->winMgr) == 1) {
            BOX2_SEQ_MoveCursorToSlot(p->work, p->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            CURSOR_MOVE_SetCurrent(p->work->sound, p->cursorSlot);
            BOX2_UI_SetCursorPos((char **)p, p->cursorSlot);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
        }
        b->state = 0;
        return 0;
    case 14:
        if (BOX2_MAIN_ShiftWindowLeft(p) == 0) {
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (busy == 0) {
            p->phase = 2;
            BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY)));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            b->state = 2;
        }
        break;
    }
    return 1;
}

int BOX2_MAIN_StateMachineScroll(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    int busy = 0;
    unsigned r;
    unsigned x;
    unsigned y;
    if (b->state != 0xA && b->state != 0xB && b->state != 0xE) {
        if (BGWINFRM_IsMoving(p->work->winMgr, 9) == 1)
            busy = BOX2_MAIN_ShiftWindowRight(p);
    }
    r = BOX2_UI_UpdateListPacks(p->work->winMgr);
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(p->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            p->work->touchState = 0;
            r = 0xFF;
            if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
                r = BOX2_MAIN_HitPartyGrid((BoxTask *)p, p->work->cursorX, p->work->cursorY);
                if (p->cursorSlot >= 0x1E && (r == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, r) == 0)) {
                    BOX2_UI_CloseInfoBar(p->work->winMgr);
                    BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
                    GFL_USE_PlaySeDefaultVolume(0x669);
                    b->state = 0xE;
                    break;
                }
            }
            if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1)
                r = BOX2_MAIN_HitPartySlots(p->work->cursorX, p->work->cursorY, d_021EF79C);
            if (r == 0xFF)
                r = BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY));
            if (BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, r) == 0)
                r = 0xFF;
            if (BOX2_UI_IsListClosed(p->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            if (r != 0xFF) {
                if (r >= 0x24)
                    p->cursorSlot = r - 2;
                else
                    p->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)p, 0x24);
            } else {
                BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
            }
            if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 0 && BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0 && busy == 0)
                BOX2_UI_CloseListPack(p->work->winMgr);
            if (r == 0xFF && p->cursorSlot < 0x1E && p->curBox != p->heldSlot) {
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
        if (busy == 0 && r == 0 && BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 0 && BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0) {
            if (p->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
                p->prevBox = p->curBox;
                BOX2_MAIN_RefreshBoxUi(p);
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_MoveCursor((char **)p, 4, p->cursorSlot);
                BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 2);
                p->work->heldSlot = p->cursorSlot;
                p->work->waitFrames = 0x17;
            }
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
        if (busy == 0 && r == 0) {
            if (BOX2_UI_GetPageButtonHit2() != -1) {
                if (p->work->touchState == 0) {
                    if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
                        BOX2_UI_CloseInfoBar(p->work->winMgr);
                        BOX2_MAIN_UpdateWindowFrame((BoxTask *)p, 0xA);
                        GFL_USE_PlaySeDefaultVolume(0x54C);
                        GFL_USE_PlaySeDefaultVolume(0x669);
                        p->work->touchState = 1;
                        b->state = 0xB;
                    }
                    if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1) {
                        BOX2_UI_OpenBar(p->work->winMgr);
                        BOX2_MAIN_UpdateWindowFrame((BoxTask *)p, 0xB);
                        GFL_USE_PlaySeDefaultVolume(0x54C);
                        GFL_USE_PlaySeDefaultVolume(0x669);
                        p->work->touchState = 1;
                        b->state = 0xD;
                    }
                }
            } else {
                p->work->touchState = 0;
            }
        }
        if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
            int dir = BOX2_UI_GetExitButtonHit();
            if (dir == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_SelectBox((BoxTask *)p, -1);
                b->state = 8;
                b->timer = 0;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_SelectBox((BoxTask *)p, 1);
                b->state = 9;
                b->timer = 0;
            }
        }
        if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
            int k = BOX2_UI_GetGridSlotPoint(x, y);
            if (k != 0xFF)
                BOX2_UI_SetMiniIconVisible((BoxTask *)p, k - 0x24, 1);
            else
                BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
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
    case 8:
        if (BOX2_SEQ_OpenBoxDown((BoxTask *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 9:
        if (BOX2_SEQ_OpenBoxUp((BoxTask *)p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 10:
        if (BOX2_MAIN_ShiftWindowRight(p) == 0)
            b->state = 1;
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 11:
        BOX2_MAIN_IsTaskMenuFinished(p);
        if (BOX2_MAIN_ShiftWindowLeft(p) == 0) {
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            BOX2_SEQ_HidePartialSlots((char **)p, 1);
            BOX2_UI_HideWindowA((BoxWork *)p->work);
            BOX2_UI_ShowWindowB((BoxWork *)p->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xC;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 12:
        if (BOX2_UI_UpdateBarMove((BoxTask *)p) == 0) {
            p->phase = 2;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 13:
        BOX2_MAIN_IsTaskMenuFinished(p);
        if (BOX2_UI_UpdateBarMove((BoxTask *)p) == 0) {
            BOX2_MAIN_RefreshBoxUi(p);
            BOX2_UI_HideWindowB((BoxWork *)p->work);
            BOX2_UI_ShowWindowA((BoxWork *)p->work);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xA;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 14:
        if (BOX2_MAIN_ShiftWindowLeft(p) == 0) {
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 0xF;
        }
        break;
    case 15:
        if (BOX2_UI_UpdateBarMove((BoxTask *)p) == 0) {
            BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY)));
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            b->state = 2;
        }
        break;
    case 16:
        BOX2_MAIN_SetMoverEntry((BoxTask *)p, (BoxMover *)b->entry);
        if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 0 && BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0) {
            BOX2_SEQ_MoveCursorToSlot(p->work, p->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
        } else {
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            CURSOR_MOVE_SetCurrent(p->work->sound, p->cursorSlot);
            BOX2_UI_SetCursorPos((char **)p, p->cursorSlot);
            BOX2_SEQ_SetCursorDraw((char **)p, 1);
        }
        b->state = 0;
        return 0;
    }
    return 1;
}


extern void BOX2_SEQ_ShiftSlotIcons(char **p, short dx);

extern void BOX2_UI_ShiftSlotOams(BoxWork *p, int d);

extern unsigned BOX2_UI_UpdateTopBarMove(BoxTask *p);

int BOX2_MAIN_StateMachineOpen(u8 *p);

int BOX2_MAIN_StateMachineClose(BoxTask *p);

int BOX2_MAIN_IsWindowMoving(BoxTask *p);

int BOX2_MAIN_UpdateWindowMove(char *p);

int BOX2_MAIN_StateMachineOpen(u8 *p){char *s;s=(char *)((BoxTask *)p)->work +0x58;switch(((BoxSeq *)s)->state){case 0:BOX2_MAIN_StartMover((BoxTask *)p,p[0x16]);(((BoxSeq *)s)->state)++;case 1:if(BOX2_MAIN_WaitCursorMove((BoxTask *)p)==0){BOX2_MAIN_SetMoverEntry((BoxTask *)p,*(BoxMover * *)&((BoxSeq *)s)->entry);((BoxSeq *)s)->state=0;return 0;}break;}return 1;}

/*
 * lever: bind the full party-count-plus-30 expression to an int local.
 */
int BOX2_MAIN_StateMachineClose(BoxTask *p)
{
    char *s;
    int count;
    s = (char *)p->work + 0x58;
    switch (((BoxSeq *)s)->state) {
    case 0:
        count = POKEPARTY_GetCount((*(void *** )p)[2]) + 30;
        BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, count);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        (((BoxSeq *)s)->state)++;
        break;
    case 1:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)p) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, ((BoxSeq *)s)->entry);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((BoxSeq *)s)->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_MAIN_IsSeqIdle(BoxTask *p)
{
    if (p->work->seq.timer == 0x17) {
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1)
            BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        p->work->seq.timer = 0;
        return 0;
    }
    BG_SYS_ResetSlot(3, 2, 8);
    BOX2_SEQ_ShiftSlotIcons((char **)p, 8);
    BOX2_UI_ShiftSlotOams((BoxWork *)p->work, 8);
    BOX2_UI_UpdateListPacks(p->work->winMgr);
    (p->work->seq.timer)++;
    return 1;
}

int BOX2_MAIN_IsSeqStep(BoxTask *p)
{
    if (p->work->seq.timer == 0x17) {
        BOX2_SEQ_SetCursorDraw((char **)p, 1);
        if (BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1)
            BOX2_UI_DeleteSlotIcon((BoxTask *)p);
        p->work->seq.timer = 0;
        return 0;
    }
    BG_SYS_ResetSlot(3, 1, 8);
    BOX2_SEQ_ShiftSlotIcons((char **)p, -8);
    BOX2_UI_ShiftSlotOams((BoxWork *)p->work, -8);
    BOX2_UI_UpdateListPacks(p->work->winMgr);
    (p->work->seq.timer)++;
    return 1;
}

/*
 * 1 when the p+0x2c+0x74 object is live.
 */
int BOX2_MAIN_IsWindowMoving(BoxTask *p)
{
    if (BOX2_UI_UpdateListPacks(p->work->winMgr) != 0)
        return 1;
    return 0;
}

/*
 * Tail forwarder; following code starts at 021E01B0.
 */
int BOX2_MAIN_UpdateWindowMove(char *p)
{
    return BOX2_UI_UpdateTopBarMove((BoxTask *)p);
}

int BOX2_MAIN_IsWindowBusy(unsigned char *p)
{
    return BOX2_UI_UpdateBarMove((BoxTask *)p) != 0;
}

extern u32 BGWINFRM_UpdateMove(struct WinMgr *mgr, u32 idx);

extern void BOX2_UI_MoveSlotIcon(char *, int);



int BOX2_MAIN_StateMachineMove(BoxTask *p);

int BOX2_MAIN_ShiftWindowRight(BoxTask *p)
{
    int v = BGWINFRM_UpdateMove(p->work->winMgr, 9);
    BOX2_UI_MoveSlotIcon((char *)p, 8);
    return v;
}

int BOX2_MAIN_ShiftWindowLeft(BoxTask *p)
{
    int x = BGWINFRM_UpdateMove(p->work->winMgr, 9);
    BOX2_UI_MoveSlotIcon((char *)p, -8);
    return x;
}

int BOX2_MAIN_StateMachineMove(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    unsigned r = BOX2_UI_UpdateListPacks(p->work->winMgr);
    int busy = BOX2_UI_UpdateBarMove((BoxTask *)p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(p->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (BOX2_UI_IsTopBarClosed(p->work->winMgr) == 0)
            BOX2_UI_ToggleSlotPair((BoxWork *)p->work, 1);
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            r = 0xFF;
            if (BOX2_UI_IsTopBarClosed(p->work->winMgr) == 0 && busy == 0)
                r = BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY));
            BOX2_MAIN_SwapWithNeighbour((BoxTask *)p, p->cursorSlot, r);
            if (BOX2_UI_IsListClosed(p->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            p->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)p, 0x24);
            if (p->cursorSlot < 0x1E) {
                b->state = 6;
            } else {
                if (BOX2_UI_IsTopBarClosed(p->work->winMgr) == 0)
                    GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_CloseBar(p->work->winMgr);
                BOX2_UI_CloseListPack(p->work->winMgr);
                b->state = 4;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (r == 0 && busy == 0) {
            if (BOX2_UI_IsTopBarClosed(p->work->winMgr) == 1) {
                if (BOX2_UI_GetPageButtonHit() == 0) {
                    p->heldSlot = 0xFF;
                    p->phase = 0;
                    BOX2_UI_OpenBar(p->work->winMgr);
                    GFL_USE_PlaySeDefaultVolume(0x669);
                }
            } else if (b->timer == 0) {
                int dir = BOX2_UI_GetCloseButtonHit();
                if (dir == 0) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StopSeq((BoxTask *)p, 0);
                    b->state = 2;
                } else if (dir == 1) {
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    BOX2_MAIN_StopSeq((BoxTask *)p, 1);
                    b->state = 3;
                }
            }
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 2:
        if (BOX2_MAIN_IsSeqIdle(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 3:
        if (BOX2_MAIN_IsSeqStep(p) == 0) {
            b->timer = 0x10;
            b->state = 1;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 4:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 5;
        }
        break;
    case 5:
        if (busy == 0 && r == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, b->entry);
            BOX2_SEQ_MoveCursorToSlot(p->work, p->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
            b->state = 8;
        }
        break;
    case 6:
        if (BOX2_MAIN_WaitBoxScroll((BoxTask *)p) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, b->entry);
            BOX2_MAIN_ResetBoxView(p);
            GFL_USE_PlaySeDefaultVolume(0x667);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_CloseBar(p->work->winMgr);
            p->cursorSlot = 0xFF;
            b->state = 7;
        }
        break;
    case 7:
        if (busy == 0)
            b->state = 8;
        break;
    case 8:
        BOX2_UI_ToggleSlotPair((BoxWork *)p->work, 0);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
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
extern void BOX2_SEQ_RefreshHandSlot(BoxTask *p);

void BOX2_SEQ_SetCursorFrame(BoxTask *p, int b);

int BOX2_MAIN_IsWindowBusy(unsigned char *p);

int BOX2_MAIN_StateMachinePen(BoxTask *p);

int BOX2_MAIN_SceneApplyScroll(BoxTask *p);

int BOX2_MAIN_SceneWaitScroll(BoxTask *p);

void BOX2_MAIN_SceneMoveCursor(BoxTask *p);

int BOX2_MAIN_SceneWaitCursor(BoxTask *p);

int BOX2_MAIN_SceneOpenBox(BoxTask *p);

/*
 * State machine in the 021DFA30 family (template 021E0ABC): pick a box with
 * the pen, slide the cursor there, then close.
 */
int BOX2_MAIN_StateMachinePen(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    int busy = BOX2_UI_UpdateListPacks(p->work->winMgr);
    int wait = BOX2_UI_UpdateBarMove((BoxTask *)p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        if (TOUCHPANEL_GetCont() == 1)
            BOX2_UI_OpenListPack(p->work->winMgr);
        b->state = 1;
        break;
    case 1:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            int r = 0xFF;
            if (BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1)
                r = BOX2_MAIN_HitPartySlots(p->work->cursorX, p->work->cursorY, d_021EF79C);
            BOX2_MAIN_SetMoverTarget((BoxTask *)p, p->cursorSlot, r);
            if (BOX2_UI_IsListClosed(p->work->winMgr) == 0)
                BOX2_SEQ_SetSlotDim((char **)p, 0);
            p->cursorSlot = BOX2_MAIN_FindMoverSlot((BoxTask *)p, 0x24);
            if (p->cursorSlot >= 0x1E) {
                b->state = 5;
                break;
            }
            if (wait == 1 || BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1) {
                GFL_USE_PlaySeDefaultVolume(0x669);
                BOX2_UI_OpenBar(p->work->winMgr);
            }
            b->state = 2;
            break;
        }
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0 && p->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 2, 1);
            p->work->heldSlot = p->cursorSlot;
        }
        BOX2_MAIN_MoveCursorActor((BoxTask *)p, x, y);
        break;
    case 2:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 3;
        }
        if (wait == 0)
            BOX2_UI_CloseListPack(p->work->winMgr);
        break;
    case 3:
        if (wait == 0) {
            BOX2_UI_CloseListPack(p->work->winMgr);
            b->state = 4;
        }
        break;
    case 4:
        if (busy == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, b->entry);
            BOX2_SEQ_MoveCursorToSlot(p->work, p->cursorSlot);
            BOX2_SEQ_SetSlotDim((char **)p, 1);
            b->state = 7;
        }
        break;
    case 5:
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)p) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, b->entry);
            GFL_USE_PlaySeDefaultVolume(0x667);
            GFL_USE_PlaySeDefaultVolume(0x669);
            p->cursorSlot = 0xFF;
            BOX2_UI_OpenBar(p->work->winMgr);
            b->state = 6;
        }
        break;
    case 6:
        if (wait == 0) {
            BOX2_MAIN_ResetBoxView(p);
            b->state = 7;
        }
        break;
    case 7:
        BOX2_SEQ_SetSlotActors((char *)p, 1, 0);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        b->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_MAIN_SceneApplyScroll(BoxTask *p)
{
    BoxScrollMotion *m;
    short xy[2];
    m = p->work->seq.entry;
    if (m->count == 0) {
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 4, m->x, m->y, 0);
        BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
        return 0;
    }
    m->count--;
    BOX2_SEQ_GetActorSurfacePos(p->work, 4, &xy[1], &xy[0], 0);
    if (m->directionX == 0)
        xy[1] += m->dx;
    else
        xy[1] -= m->dx;
    if (m->directionY == 0)
        xy[0] += m->dy;
    else
        xy[0] -= m->dy;
    BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, 4, xy[1], xy[0], 0);
    BOX2_SEQ_RefreshHandSlot((BoxTask *)p);
    return 1;
}

/*
 * 1 unless both queries come back zero.
 */
int BOX2_MAIN_SceneWaitScroll(BoxTask *p)
{
    if (BOX2_MAIN_SceneApplyScroll((BoxTask *)p) == 0 && BOX2_UI_UpdateListPacks(p->work->winMgr) == 0)
        return 0;
    return 1;
}

void BOX2_MAIN_SceneMoveCursor(BoxTask *p)
{
    short xy[2];
    BOX2_SEQ_SetCursorFrame((BoxTask *)p, 8);
    BOX2_SEQ_GetActorSurfacePos(p->work, 4, &xy[1], &xy[0], 0);
    BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work, p->work->cursorActorId, (short)xy[1], (short)(xy[0] + 4), (short)0);
    BOX2_SEQ_SetSlotDrawPriority((BoxWork *)p->work, 0x24, 0);
}

int BOX2_MAIN_SceneWaitCursor(BoxTask *p)
{
    char *s=(char *)p->work +0x58;
    short xy[2];
    int k;
    switch(((BoxSeq *)s)->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p,7);
        (((BoxSeq *)s)->state)++;
    case 1:
        if(((BoxSeq *)s)->timer==4) {
            ((BoxSeq *)s)->timer=0;
            (((BoxSeq *)s)->state)++;
            break;
        }
        BOX2_SEQ_GetActorSurfacePos(p->work,4,&xy[1],&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work,4,(short)xy[1],(short)(xy[0]+2),(short)0);
        (((BoxSeq *)s)->timer)++;
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x666);
        BOX2_SEQ_SetCursorFrame((BoxTask *)p,8);
        (((BoxSeq *)s)->state)++;
    case 3:
        if(((BoxSeq *)s)->timer==4) {
            ((BoxSeq *)s)->timer=0;
            ((BoxSeq *)s)->state=0;
            return 0;
        }
        BOX2_SEQ_GetActorSurfacePos(p->work,4,&xy[1],&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work,4,(short)xy[1],(short)(xy[0]-2),(short)0);
        k=p->work->cursorActorId;
        BOX2_SEQ_GetActorSurfacePos(p->work,k,&xy[1],&xy[0],0);
        BOX2_SEQ_AddActorSurfacePos((BoxWork *)p->work,k,(short)xy[1],(short)(xy[0]-2),(short)0);
        BOX2_SEQ_MoveCursorToSlot(p->work,0x24);
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
int BOX2_MAIN_SceneOpenBox(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    int r;

    switch (b->state) {
    case 0:
        if (p->cursorSlot >= 0x1E && BOX2_UI_IsInfoBarOpen(p->work->winMgr) == 1) {
            if (p->work->targetBox < 0x1E || p->work->targetBox == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, p->work->targetBox) == 0) {
                BOX2_UI_SetMiniIconVisible((BoxTask *)p, 0, 0);
                BOX2_UI_CloseInfoBar(p->work->winMgr);
                GFL_USE_PlaySeDefaultVolume(0x669);
                b->state = 5;
                break;
            }
        }
        if (p->cursorSlot < 0x1E && p->curBox != p->heldSlot) {
            if (p->work->targetBox == 0xFF || BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, p->work->targetBox) == 0) {
                r = BOX2_MAIN_IsWrappedDistance((unsigned char *)p, p->curBox, p->heldSlot);
                p->curBox = p->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), r);
                if (r == 0)
                    b->state = 2;
                else
                    b->state = 3;
                break;
            }
        }
    case 1:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 7);
        BOX2_MAIN_MoveCursorWithMon((BoxTask *)p, p->cursorSlot, p->work->targetBox);
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
        if (BOX2_MAIN_WaitCursorMove((BoxTask *)p) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, b->entry);
            BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
            BOX2_SEQ_SetSlotDim((char **)p, 0);
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 0;
            return 0;
        }
        break;
    case 5:
        if (BOX2_MAIN_ShiftWindowLeft(p) == 0) {
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            GFL_USE_PlaySeDefaultVolume(0x669);
            b->state = 6;
        }
        break;
    case 6:
        if (BOX2_MAIN_IsWindowBusy((unsigned char *)p) == 0)
            b->state = 1;
        break;
    }
    return 1;
}

typedef struct {
    unsigned short idx;
    unsigned short slot;
} BoxSlotRef;


int BOX2_MAIN_Check09E0(BoxTask *p);

int BOX2_MAIN_Check0A40(BoxTask *p);

int BOX2_MAIN_StateMachineCoin(BoxTask *p);

int BOX2_MAIN_Check0E50(BoxTask *p);

int BOX2_MAIN_Check0ED4(BoxTask *p);

int BOX2_MAIN_Check0F4C(BoxTask *p);

void BOX2_MAIN_MoveCursorTo(BoxWork *w, int x, int y);

int BOX2_MAIN_StateMachineSlide(BoxTask *p);

int BOX2_MAIN_Check122C(BoxTask *p);

void BOX2_SEQ_SetActorAnim(BoxTask *p, int v);

u32 BOX2_SEQ_GetActorDrawEnable(BoxWork *p, int i);

void BOX2_SEQ_SetActorAffineMode(BoxWork *p, int on);

void BOX2_SEQ_ShowHandSlots(BoxWork *p);



int BOX2_MAIN_Check09E0(BoxTask *p)
{
    char *s;
    s = (char *)p->work + 0x58;
    switch (((BoxSeq *)s)->state) {
    case 0:
        BOX2_SEQ_SetCursorFrame((BoxTask *)p, 7);
        BOX2_MAIN_SwapWithNeighbour((BoxTask *)p, p->cursorSlot, p->work->targetBox);
        ((BoxSeq *)s)->state = 1;
        break;
    case 1:
        if (BOX2_MAIN_WaitBoxScroll((BoxTask *)p) == 0) {
            BOX2_MAIN_SetMoverEntry((BoxTask *)p, ((BoxSeq *)s)->entry);
            BOX2_SEQ_SetCursorFrame((BoxTask *)p, 6);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((BoxSeq *)s)->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

int BOX2_MAIN_Check0A40(BoxTask *p)
{
    char *s;
    int a;
    int b;
    s = (char *)p->work + 0x58;
    switch (((BoxSeq *)s)->state) {
    case 0:
        if (p->work->counter) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
            BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 1);
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 1);
        }
        (((BoxSeq *)s)->state)++;
    case 1:
        a = BOX2_MAIN_SceneApplyScroll((BoxTask *)p);
        b = BOX2_UI_UpdateListPacks(p->work->winMgr);
        if (a == 0 && b == 0) {
            if (p->work->counter) {
                BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
                BOX2_SEQ_ShowHandSlots((BoxWork *)p->work);
            }
            ((BoxSeq *)s)->state = 0;
            return 0;
        }
        break;
    }
    return 1;
}

/*
 * Same state-machine family as src/matched/ov170_func_021DFA30.c.  The spill
 * slots of `first` and `flag` follow declaration order (later declaration,
 * lower address), and the two identical "fall back to p[0x16]" arms are an
 * if/else-if that the compiler tail-merges (bne then b), not one `||`.
 */
int BOX2_MAIN_StateMachineCoin(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    int busy = BOX2_UI_UpdateListPacks(p->work->winMgr);
    int wait = BOX2_UI_UpdateBarMove((BoxTask *)p);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAnim((BoxTask *)p, (short)(((BoxTask *)(p))->work->counter));
        if ((((BoxTask *)(p))->work->counter) != 0) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
            BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 1);
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 1);
            b->state = 1;
        } else {
            BOX2_UI_CloseListPack(p->work->winMgr);
            b->state = 11;
        }
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10) == 1)
            break;
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
        BOX2_SEQ_ShowHandSlots((BoxWork *)p->work);
        b->state = 2;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            int flag;
            unsigned r;
            int back;
            if (wait == 1 || BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1)
                flag = 1;
            else
                flag = 0;
            r = (unsigned short)BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY));
            if (wait == 0 && BOX2_UI_IsTopBarOpen(p->work->winMgr) == 1 && r == 0xFF)
                r = (unsigned short)BOX2_MAIN_HitPartySlots(p->work->cursorX, p->work->cursorY, d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p->cursorSlot;
                back = 1;
            } else if (BOX2_MAIN_CompareSlots((unsigned char *)p, p->cursorSlot, r) == 0) {
                r = p->cursorSlot;
                back = 1;
            }
            if (flag == 1) {
                BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 2);
                if (back == 1 && p->heldSlot != 0xFF && p->heldSlot != p->curBox) {
                    int dir = BOX2_MAIN_IsWrappedDistance((unsigned char *)p, p->curBox, p->heldSlot);
                    p->curBox = p->heldSlot;
                    BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
                    BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), dir);
                    if (dir == 0)
                        b->state = 5;
                    else
                        b->state = 6;
                } else {
                    b->state = 7;
                }
            } else {
                BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 0);
                BOX2_UI_CloseListPack(p->work->winMgr);
                b->state = 8;
            }
            b->timer = 0;
            break;
        }
        if (b->timer != 0)
            b->timer--;
        if (busy == 0 && wait == 0 && BOX2_UI_IsTopBarOpen(p->work->winMgr) == 0 && p->cursorSlot != BOX2_UI_GetPartySlotPoint(x, y)) {
            BOX2_UI_PutBottomBarClosed(p->work->winMgr);
            BOX2_UI_CloseBar(p->work->winMgr);
            BOX2_SEQ_HidePartialSlots((char **)p, 1);
            BOX2_SEQ_SetSlotActors((char *)p, 0x82, 1);
            GFL_USE_PlaySeDefaultVolume(0x669);
            BOX2_UI_MoveCursor((char **)p, 6, p->cursorSlot);
            CURSOR_MOVE_ClearSkipBit(p->work->sound, 0x27);
            CURSOR_MOVE_ClearSkipBit(p->work->sound, 0x28);
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 2, 1, 1);
            p->barFlag = 0;
            p->work->cancelFlag = 0;
            p->work->heldSlot = p->cursorSlot;
            p->work->waitFrames = 0x42;
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
        BOX2_MAIN_MoveCursorTo(p->work, x, y);
        break;
    case 3:
        if (BOX2_MAIN_IsSeqIdle(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(p->work, x, y);
        break;
    case 4:
        if (BOX2_MAIN_IsSeqStep(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(p->work, x, y);
        break;
    case 5:
        if (BOX2_MAIN_IsSeqIdle(p) == 0)
            b->state = 7;
        break;
    case 6:
        if (BOX2_MAIN_IsSeqStep(p) == 0)
            b->state = 7;
        break;
    case 7:
        if (BOX2_MAIN_IsSwapScene((int)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 9;
        }
        break;
    case 8:
        if (BOX2_MAIN_IsSwapScene((int)p) == 0) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            if ((((BoxTask *)(p))->work->counter) != 0) {
                BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
                BOX2_SEQ_ShowHandSlots((BoxWork *)p->work);
            }
            BOX2_UI_DeleteSlotObjects((BoxTask *)p, 0, 0, 1);
            b->state = 11;
        }
        break;
    case 9:
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 2);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        b->state = 10;
        break;
    case 10:
        if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 0);
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
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

int BOX2_MAIN_Check0E50(BoxTask *p)
{
    char *s;
    int a;
    int b;
    s = (char *)p->work + 0x58;
    switch (((BoxSeq *)s)->state) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable((BoxWork *)p->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
            BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 2);
        }
        (((BoxSeq *)s)->state)++;
    case 1:
        a = BOX2_MAIN_SceneApplyScroll((BoxTask *)p);
        b = BOX2_MAIN_IsWindowMoving((BoxTask *)p);
        if (a == 0 && b == 0)
            (((BoxSeq *)s)->state)++;
        break;
    case 2:
        if (BOX2_SEQ_GetActorDrawEnable((BoxWork *)p->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 0);
        }
        ((BoxSeq *)s)->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_MAIN_Check0ED4(BoxTask *p)
{
    char *b = (char *)p->work + 0x58;
    switch (((BoxSeq *)b)->state) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable((BoxWork *)p->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
            BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 2);
        }
        (((BoxSeq *)b)->state)++;
        /* fall through */
    case 1:
        if (!BOX2_MAIN_IsWindowMoving((BoxTask *)p))
            (((BoxSeq *)b)->state)++;
        break;
    case 2:
        if (BOX2_SEQ_GetActorDrawEnable((BoxWork *)p->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 0);
        }
        ((BoxSeq *)b)->state = 0;
        return 0;
    }
    return 1;
}

int BOX2_MAIN_Check0F4C(BoxTask *p)
{
    char *b = (char *)p->work + 0x58;
    switch (((BoxSeq *)b)->state) {
    case 0:
        if (BOX2_SEQ_GetActorDrawEnable((BoxWork *)p->work, 10) == 1) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
            BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 2);
        }
        (((BoxSeq *)b)->state)++;
        break;
    case 1:
        if (!BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10)) {
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 0);
        }
        ((BoxSeq *)b)->state = 0;
        return 0;
    }
    return 1;
}

void BOX2_MAIN_MoveCursorTo(BoxWork *w, int x, int y)
{
    BOX2_SEQ_MoveActor(w, (short)x, (short)y);
    BOX2_SEQ_LayoutHandSlots(w);
    w->cursorX = x;
    w->cursorY = y;
}

/*
 * Sibling of src/matched/ov170_func_021E0ABC.c.
 */
int BOX2_MAIN_StateMachineSlide(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    unsigned x;
    unsigned y;
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 1);
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 1);
        b->state = 1;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
        BOX2_SEQ_ShowHandSlots((BoxWork *)p->work);
        b->state = 2;
        break;
    case 2:
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            unsigned first;
            unsigned r;
            int back;
            r = (unsigned short)BOX2_MAIN_HitBoxGrid(p->work->cursorX, (short)(p->work->cursorY));
            if (r == 0xFF)
                r = (unsigned short)BOX2_MAIN_HitPartySlots(p->work->cursorX, p->work->cursorY, d_021EF79C);
            back = 0;
            first = r;
            if (r == 0xFF) {
                r = p->cursorSlot;
                back = 1;
            } else if (BOX2_MAIN_CompareSlots((unsigned char *)p, p->cursorSlot, r) == 0) {
                r = p->cursorSlot;
                back = 1;
            }
            BOX2_MAIN_PlaceMonSceneFromBox((int)p, first, r, 2);
            if (back == 1 && p->heldSlot != 0xFF && p->heldSlot != p->curBox) {
                int dir = BOX2_MAIN_IsWrappedDistance((unsigned char *)p, p->curBox, p->heldSlot);
                p->curBox = p->heldSlot;
                BOX2_SEQ_LoadMonIcon((char **)p, p->curBox);
                BOX2_MAIN_SetBoxScroll((BoxTask *)p, (void *)BOX2_MAIN_GetBoxFormId((BoxTask *)p, p->curBox), dir);
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
                BOX2_MAIN_StopSeq((BoxTask *)p, 0);
                b->state = 3;
            } else if (dir == 1) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                BOX2_MAIN_StopSeq((BoxTask *)p, 1);
                b->state = 4;
            }
        }
        BOX2_MAIN_MoveCursorTo(p->work, x, y);
        break;
    case 3:
        if (BOX2_MAIN_IsSeqIdle(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(p->work, x, y);
        break;
    case 4:
        if (BOX2_MAIN_IsSeqStep(p) == 0) {
            b->timer = 0x10;
            b->state = 2;
        }
        if (TOUCHPANEL_GetPointCont(&x, &y) == 1)
            BOX2_MAIN_MoveCursorTo(p->work, x, y);
        break;
    case 5:
    case 6:
        if (b->state == 5 && BOX2_MAIN_IsSeqIdle(p) == 0)
            b->state = 7;
        if (b->state == 6 && BOX2_MAIN_IsSeqStep(p) == 0)
            b->state = 7;
    case 7:
        if (BOX2_MAIN_IsSwapScene((int)p) == 0 && b->state == 7) {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 8;
        }
        break;
    case 8:
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 2);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        b->state = 9;
        break;
    case 9:
        if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10) == 0) {
            BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 0);
            BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
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
int BOX2_MAIN_Check122C(BoxTask *p)
{
    BoxSeq *b = (BoxSeq *)((char *)p->work + 0x58);
    switch (b->state) {
    case 0:
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 1);
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 1);
        b->state = 1;
        break;
    case 1:
        if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10) != 0)
            break;
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
        b->state = 2;
        break;
    case 2: {
        unsigned char old = p->cursorSlot;
        p->cursorSlot = ((BoxSlotRef *)b->entry)->idx;
        if (p->heldSlot != 0xFF && p->heldSlot != p->curBox)
            BOX2_MAIN_ClearFlagsScene((BoxTask *)p, 2);
        else
            BOX2_MAIN_PlaceMonSceneFromBox((int)p, old, old, 2);
        b->state = 3;
        break;
    }
    case 3:
        if (BOX2_MAIN_IsSwapScene((int)p) != 0)
            break;
        if (p->heldSlot != 0xFF && p->heldSlot != p->curBox) {
            b->state = 5;
        } else {
            GFL_USE_PlaySeDefaultVolume(0x667);
            b->state = 4;
        }
        break;
    case 4:
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 1);
        BOX2_SEQ_SetActorAnimSeq((BoxWork *)p->work, 10, 2);
        b->state = 5;
        break;
    case 5:
        if (BOX2_SEQ_IsActorAnimActive((BoxWork *)p->work, 10) != 0)
            break;
        BOX2_SEQ_SetActorDrawEnable((BoxWork *)p->work, 10, 0);
        BOX2_SEQ_SetActorAffineMode((BoxWork *)p->work, 0);
        b->state = 6;
        break;
    case 6:
        b->state = 0;
        return 0;
    }
    return 1;
}
