/*
 * file:     itemmenu.c
 * unit:     yes
 * function: ITEMMENU_SetTask, ITEMMENU_ForceRedrawList, ITEMMENU_RedrawList, ITEMMENU_GetSlot, ITEMMENU_GetSellTotal, ITEMMENU_GetCursorIndex, ITEMMENU_GetItemCount, ITEMMENU_RegisterItemName, ITEMMENU_RegisterItemNameCounted, ITEMMENU_SwapSlots, ITEMMENU_MoveSlot, ITEMMENU_SwitchPocketCursor, ITEMMENU_MoveCursorDown, ITEMMENU_MoveCursorUp, ITEMMENU_HandleScrollbarTouch, ITEMMENU_HandleMoveModeKeys, ITEMMENU_HandleListKeys, ITEMMENU_HandleListTouch, ITEMMENU_IsBackButtonTouched, ITEMMENU_TaskFinishClose, ITEMMENU_TaskListInput, ITEMMENU_IsRepelItem, ITEMMENU_GetFieldUseKind, ITEMMENU_UseRepel, ITEMMENU_TaskWaitMessage, ITEMMENU_ShowKeyItemRefusal, ITEMMENU_ShowMessageThenWait, ITEMMENU_TryStartUse, ITEMMENU_TryStartGive, ITEMMENU_TryStartRegister, ITEMMENU_TryStartCheck, ITEMMENU_TryStartToss, ITEMMENU_TryStartSort, ITEMMENU_TryStartPlant, ITEMMENU_TryStartSell, ITEMMENU_FindUseRange, ITEMMENU_HandleActionMenuChoice, ITEMMENU_TaskSelectItem, ITEMMENU_TaskBagMain, ITEMMENU_TaskActionMenuInput, ITEMMENU_TaskOpenActionMenu, ITEMMENU_TaskRegisterResultMessage, ITEMMENU_TaskStartRegisterResult, ITEMMENU_TaskUseNoticeMessage, ITEMMENU_TaskReturnToListAfterMessage, ITEMMENU_TaskBeginReturnToList, ITEMMENU_TaskTossConfirmInput, ITEMMENU_TaskOpenTossConfirm, ITEMMENU_TaskTossAskQuantity, ITEMMENU_TaskTossQuantityInput, ITEMMENU_TaskGiveItem, ITEMMENU_TaskSellQuantityInput, ITEMMENU_TaskSellAskConfirm, ITEMMENU_TaskSellConfirmInput, ITEMMENU_TaskWaitMessageDismiss, ITEMMENU_TaskReturnToListFromQuantity, ITEMMENU_RemoveSelectedItems, ITEMMENU_ShowQuantityWindows, ITEMMENU_HideQuantityWindows, ITEMMENU_HandleQuantityInput, ITEMMENU_CompareSortEntries, ITEMMENU_SortPocket, ITEMMENU_ShowInputGuardError, ITEMMENU_SortAndRedraw, ITEMMENU_RefreshInputGuard, ITEMMENU_SetCursorActive, ITEMMENU_IsBrowseMode, ITEMMENU_ToggleRegisteredItem, ITEMMENU_GetPocketSortFlag, ITEMMENU_TogglePocketSortFlag, ITEMMENU_UpdatePocketSortIcon, ITEMMENU_CheckItemFilter, ITEMMENU_BuildActionList, ITEMMENU_OpenActionMenu, ITEMMENU_IsItemRegistered, ITEMMENU_HandleTouchTarget, ITEMMENU_VBlankCallback, ITEMMENU_TaskStartFadeIn, ITEMMENU_TaskWaitFadeIn, ITEMMENU_Init, ITEMMENU_Main, ITEMMENU_Exit, ITEMMENU_ReturnToBagMain, ITEMMENU_ReturnToListInput, ITEMMENU_CreateBlinkPalAnm, ITEMMENU_DeleteBlinkPalAnm, ITEMMENU_TaskSelectItemFlash, ITEMMENU_StartSideButtonPress, ITEMMENU_TaskWaitSideButtonPress, ITEMMENU_StartPocketTabPress, ITEMMENU_TaskWaitPocketTabPress, ITEMMENU_GetYesNoTouchChoice, ITEMMENU_TaskReopenListFromQuantity, ITEMMENU_TaskReturnFromQuantity, ITEMMENU_AllocPalAnmSlots, ITEMMENU_FreePalAnmSlots, ITEMMENU_TaskInputGuardMessage, ITEMMENU_TaskWaitMessageThenList, ITEMMENU_IsCheckModeAllowed, ITEMMENU_ReturnToBagMainAlias, ITEMMENU_InitDisplayBanks, ITEMMENU_ResetDisplayLayers, ITEMMENU_LoadBagGraphics, ITEMMENU_LoadTabGraphics, ITEMMENU_SetupGraphics, ITEMMENU_ApplyBgPalettes, ITEMMENU_SetLayersVisible, ITEMMENU_SetMoveTypeIconsVisible, ITEMMENU_DrawMoveInfo, ITEMMENU_HideMoveInfo, ITEMMENU_FreeGraphics, ITEMMENU_PrintMenuTitle, ITEMMENU_InitWindows, ITEMMENU_DestroyMovingCursor, ITEMMENU_CreateMovingCursor, ITEMMENU_FreeActionMenuResources, ITEMMENU_LoadPocketGraphics, ITEMMENU_CreateCursorActors, ITEMMENU_GetRowColorKind, ITEMMENU_PrintItemList, ITEMMENU_SnapSelectorToCursor, ITEMMENU_UploadSlotGraphics, ITEMMENU_UpdateCursorFromTouch, ITEMMENU_MoveCursorToRow, ITEMMENU_CreateSideButtonActors, ITEMMENU_CreateTabActors, ITEMMENU_SelectTab, ITEMMENU_ClearMessageWindow, ITEMMENU_OpenPopupList, ITEMMENU_LoadBgPaletteMode, ITEMMENU_PrintMoveInfoText, ITEMMENU_ShowMessage, ITEMMENU_ShowMessageDefault, ITEMMENU_ShowItemUseMessage, ITEMMENU_IsMessageFinished, ITEMMENU_PrintPocketName, ITEMMENU_HideSideWindows, ITEMMENU_PrintPocketCount, ITEMMENU_PrintMoney, ITEMMENU_EnterQuantityMode, ITEMMENU_LeaveQuantityMode, ITEMMENU_OpenYesNoList, ITEMMENU_CloseYesNoList, ITEMMENU_LoadSellPalette, ITEMMENU_PrintQuantityPrice, ITEMMENU_PocketToSortFlag, ITEMMENU_UpdateSlotActorPosition, ITEMMENU_UpdateSideButtons, ITEMMENU_SetBackButtonAnim, ITEMMENU_UpdateInputGuardAnim, ITEMMENU_UpdateSideButtonsForMode, ITEMMENU_MoveActorToPoint, ITEMMENU_PrintToWindow, ITEMMENU_FlushWindowAt, ITEMMENU_FlushDirtyWindows
 * address:  0x021B6100
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   ITEMMENU_DrawMoveInfo 0x021B9850 thumb ov070
 *   ITEMMENU_HideMoveInfo 0x021B9AAC thumb ov070
 *   ITEMMENU_PrintItemList 0x021BA218 thumb ov070
 *   ITEMMENU_UpdatePocketSortIcon 0x021B81F4 thumb ov070
 *   MYITEM_SAVEDATA_GetSlot 0x020081DC thumb
 *   FILE_UTIL_GetItemParam 0x02020FE4 thumb
 *   MYITEM_SAVEDATA_CountUsedSlots 0x02007F7C thumb
 *   MYITEM_SAVEDATA_CountUsedSlotsInPocket 0x02007FA0 thumb
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 *   WORDSET_SetSlotFromBank 0x0201EF6C thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   MYITEM_SAVEDATA_SetLastFieldPocket  0x02008298  thumb
 *   MYITEM_SAVEDATA_SetFieldPocketCursor  0x02008288  thumb
 *   MYITEM_SAVEDATA_GetFieldPocketCursor  0x02008270  thumb
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   ITEMMENU_PrintPocketCount  0x021BAF38  thumb  ov070
 *   ITEMMENU_SelectTab  0x021BA96C  thumb  ov070
 *   ITEMMENU_LoadBgPaletteMode  0x021BAAA4  thumb  ov070
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   SCROLLBAR_GetValueFromPos  0x0202EDE4  thumb
 *   ITEMMENU_UpdateCursorFromTouch  0x021BA654  thumb  ov070
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   ITEMMENU_UpdateSideButtonsForMode 0x021BB5DC thumb ov070
 *   ITEMMENU_ReturnToBagMain 0x021B8AF4 thumb ov070
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   MYITEM_SAVEDATA_CopyPocket  0x02007CC8  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   MOVE_POKEMON_SAVE_IsCooldownDone  0x0200D58C  thumb
 *   MOVE_POKEMON_SAVE_SetCooldown  0x0200D55C  thumb
 *   ITEMMENU_RemoveSelectedItems  0x021B7D20  thumb  ov070
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   ITEMMENU_ShowMessage  0x021BACF0  thumb  ov070
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   FIELD_SKILL_USE_FLAGS_IsSkillUsable  0x02028754  thumb
 *   gItemMenuUseRanges  0x021BB9C4  data  a4
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   GAME_BEACON_SetItemUse  0x02027324  thumb
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *   PALANM_IsOutsideReservedIdRange  0x020213E0  thumb
 *   FILE_UTIL_IsMailItem  0x0202136C  thumb
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   FILE_UTIL_GetMachineMove  0x020212B0  thumb
 *   WORDSET_SetSlotFromMsgCB  0x0201EF34  thumb
 *   FILE_UTIL_GetMachineIndex  0x02021350  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_AddMoney  0x0200C278  thumb
 *   MYITEM_SAVEDATA_RemoveItem  0x02007F1C  thumb
 *   MYITEM_SAVEDATA_GetItemQuantity  0x02007FB8  thumb
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   sQuantityTouchRects     0x021BB960  data  a1
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MYITEM_SAVEDATA_CopyPocket   0x02007CC8  thumb
 *   FILE_UTIL_CreateItemArcHandle  0x02020F14  thumb
 *   FILE_UTIL_LoadArcMember  0x02020F20  thumb
 *   FILE_UTIL_GetItemRecordParam  0x02021014  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   sHeapSiteName     0x021BBBC0  data  ov070  a1
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   ITEM_GetRegisterFlagId  0x0202E448  thumb
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   FILE_UTIL_LoadItemRecord  0x02020F34  thumb
 *   sActionMsgIds 0x021BB998 data ov070 a4
 *   sDefaultActionIds 0x021BB95C data a1
 *   sTabPockets     0x021BB984  data  a4
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   TCBL_Main  0x020310C4  arm
 *   TCB_DeleteTask  0x02030EAC  arm
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb
 *   TCBL_Destroy  0x02031140  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   BG_SYS_FreeTileRun  0x0203FB44  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BG_SYS_FreeTiles  0x02040DA8  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   APP_KEYCURSOR_Delete  0x02028604  thumb
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   BUTTON_MAN_Delete  0x02051C6C  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   BLINK_PALANM_LoadPalettes  0x0202E9AC  thumb
 *   BLINK_PALANM_Delete 0x0202EA20 thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   sBackButtonHitRect 0x021BB978 data a4
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   GAME_DATA_GetIntrudeCount 0x02012B70 thumb
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_FreeSlot  0x020414AC  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   BG_SYS_Init  0x02040C14  arm
 *   sBgLayer0Template     0x021BBB40  data  a4
 *   sBgLayer1Template     0x021BBB60  data  a4
 *   sBgLayer2Template     0x021BBB80  data  a4
 *   sBgLayer3Template     0x021BBB20  data  a4
 *   sBgLayer4Template     0x021BBAC0  data  a4
 *   sBgLayer5Template     0x021BBAE0  data  a4
 *   sBgLayer6Template     0x021BBB00  data  a4
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   sVramBankConfig  0x021BBBE0  data a4
 *   sClactSystemConfig  0x021BBA8C  data  ov070
 *   sDispConfig  0x021BBAB0  data a4
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   FILE_UTIL_GetId  0x0202130C  thumb
 *   FILE_UTIL_ReadStringAlt  0x02020FB4  thumb
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   BMP_Delete  0x020437AC  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   FILE_UTIL_Get  0x02020E60  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BMP_Create  0x02043678  arm
 *   FILE_UTIL_IsMachineItem  0x02021288  thumb
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   sRowStyleFlags     0x021BBA79  data  ov070  a1
 *   PRINTSYS_PrintColor  0x0201C7D0  thumb
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   CLACT_GetCharacterVramAddress  0x0204ABBC  arm
 *   BMP_GetPixels  0x020437D4  arm
 *   BMP_GetByteSize  0x020437EC  arm
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOBJ  0x0207E780  arm
 *   SCROLLBAR_GetPosFromValue  0x0202EE0C  thumb
 *   sSideButtonAnimSeqs     0x021BBAA8  data  ov070  a1
 *   sSideButtonXPositions     0x021BBA6C  data  a1
 *   sArrowAnimSeqs     0x021BBA68  data  a1
 *   sArrowYPositions     0x021BBA64  data  ov070  a1
 *   sTabSoftPriorities     0x021BBA74  data  a1
 *   sTabPositions     0x021BBBCC  data  a2
 *   sTabAnimSeqs     0x021BBA81  data  a1
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   STRBUF_Create  0x020457B0  arm
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt  0x020499D4  arm
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   MSG_SPEED_GetWait  0x02012FFC  thumb
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   KEY_GetCont  0x0203630C  arm
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   WORDSET_SetSlotFromMsg37  0x0201F14C  thumb
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   MISC_GetMoney 0x0200C274 thumb
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_DrawTile  0x02041090  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb
 *   PALANM_RequestFade  0x0202173C  thumb
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   CLACT_GetActorDrawEnable  0x0204B3F4  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   KEY_GetRepeatSpeed  0x02036370  arm  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm  arm9
 *   TCBL_Create  0x0203101C  arm  arm9
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm  arm9
 *   CLACT_InitSystem  0x0204A48C  arm  arm9
 *   CLACT_CreateUnit  0x0204B100  arm  arm9
 *   BUTTON_MAN_Create  0x02051B84  arm  arm9
 *   PRINTSYS_QUE_CreateEx  0x0201C450  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   BG_SYS_Create  0x0203F8F4  arm  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb  arm9
 *   BMP_MENUWORK_LoadFrameGfx  0x0201F5DC  thumb  arm9
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm  arm9
 *   APP_ICON_GetArchiveId  0x020275E4  thumb  arm9
 *   APP_ICON_GetTouchBarFileId  0x020275E8  thumb  arm9
 *   APP_ICON_GetTypePaletteOffset  0x020275EC  thumb  arm9
 *   APP_ICON_GetTypeCellFileId  0x020275F8  thumb  arm9
 *   APP_ICON_GetTypePaletteFileId  0x020275FC  thumb  arm9
 *   APP_ICON_GetTypeAnimFileId  0x02027600  thumb  arm9
 *   APP_ICON_GetMoveKindPaletteOffset  0x02027604  thumb  arm9
 *   APP_ICON_GetMoveKindCellFileId  0x02027610  thumb  arm9
 *   APP_KEYCURSOR_CreateDefault  0x02028590  thumb  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   MSGDATA_CreateFromArchive  0x02045B38  arm  arm9
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm  arm9
 *   MYITEM_SAVEDATA_CompactAllPockets  0x0200816C  thumb  arm9
 *   MYITEM_SAVEDATA_GetLastFieldPocket  0x02008284  thumb  arm9
 *   sButtonHitTable              0x021BBA04  data
 */

#include "../arm9/arc_tool.h"
#include "../sdk_ioreg.h"
#include "../arm9/game_data.h"
#include "../arm9/mystatus.h"
#include "../arm9/ui.h"
#include "itemmenu_types.h"

#define reg_GX_POWCNT (*(volatile u16 *)REG_POWCNT1_ADDR)
#define REG_GX_POWCNT_DSEL_MASK 0x8000
#define REG_GX_POWCNT_DSEL_SHIFT 15
struct MsgBank;
struct WordSet;
struct TaskMenu;
struct PrintSys;
struct ButtonMan;
struct KeyCursor;
struct MiscSave;
struct ItemData;
struct Tcbl;
struct BagCursor;
struct TcbTask;
struct Tcbl;
struct TaskMenuRes;
struct Strbuf;
struct Proc;
struct Actor;
struct PaletteFade;
struct GameData;
struct MyStatus;
struct ClactUnit;
struct ClactSystemConfig;
struct VramBankConfig;
struct Bmp;
struct ItemmenuSurfacePos;
struct ItemmenuTaskMenuTmpl;
struct TextStream;
#include "../types.h"

union TouchHitTable;
#include "../arm9/clact.h"
#include "../arm9/printsys.h"
typedef struct HitRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} HitRect;

typedef struct ItemmenuTouchHitTable {
    HitRect rects[3];
} ItemmenuTouchHitTable;

typedef struct SortEntry {
    BagSlot item;
    u32 key;
} SortEntry;

typedef struct ActionMsgIds { int msgIds[11]; } ActionMsgIds;

typedef struct ActionIds { unsigned char ids[4]; } ActionIds;

typedef struct PocketTable {
    int pockets[5];
} PocketTable;

typedef struct ItemMenuResult {
    u8 reserved[0x34];
    u32 nextState;
    u32 selectedItemId;
} ItemMenuResult;

#include "../sdk_gx.h"

#include "../arm9/bg_sys.h"

typedef struct ActorTemplate {
    short x, y;
    unsigned short animSeq;
    u8 softPriority, bgPriority;
} ActorTemplate;

#include "itemmenu.h"

typedef struct ItemmenuSurfacePos {
    unsigned short x, y;
} ItemmenuSurfacePos;

typedef struct ByteTable5 {
    u8 values[5];
} ByteTable5;

typedef struct ByteTable2 {
    u8 values[2];
} ByteTable2;

typedef struct ItemmenuTaskMenuTmpl {
    int heapId;
    u8 itemNum;
    u8 pad[3];
    void *items;
    int posType;
    u8 charPosX;
    u8 charPosY;
    u8 width;
    u8 height;
} ItemmenuTaskMenuTmpl;

typedef struct ScreenImage {
    u16 width;
    u16 height;
    u16 reserved[4];
    u16 data[1];
} ScreenImage;

typedef short FadeStep;

typedef struct ItemMenuArgs {
    void *saveData;
    void *optionsSave;
    void *myStatus;
    struct BagCursor *bagCursor;
    void *bag;
    int actionPermissions[6];
    int bagMode;
    int bagFilter;
} ItemMenuArgs;
struct TaskMenuWork;

#include "../arm9/app_taskmenu.h"
#include "../arm9/game_beacon.h"
#ifdef __MWERKS__
#define FILE_UTIL_GetItemParam FILE_UTIL_GetItemParamHeader
#define FILE_UTIL_Get FILE_UTIL_GetHeader
#endif
#include "../arm9/file_util.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef FILE_UTIL_GetItemParam
extern u32 FILE_UTIL_GetItemParam(u16 a, u32 sel, u32 id);
#undef FILE_UTIL_Get
extern u32 FILE_UTIL_Get(unsigned short, int);
#endif
struct FieldSkillUseFlags;
#include "../arm9/app_keycursor.h"
#include "../arm9/msgdata.h"
#include "../arm9/wordset.h"
#include "../arm9/palanm.h"
extern unsigned int FILE_UTIL_IsMailItem(u16 v);
struct PrintQueue;
extern int TOUCHPANEL_GetCont(void);
struct ButtonMan;
extern s32 BUTTON_MAN_UpdateSlots(struct ButtonMan *c);
#include "../arm9/blink_palanm.h"
#include "../arm9/key.h"
extern void GFL_USE_PlaySeDefaultVolume(unsigned int se);
#include "../arm9/mi_memory.h"
extern int GFL_USE_IsAnySeBusy(void);
extern int TOUCHPANEL_GetTrg(void);
extern u16 FILE_UTIL_GetMachineMove(u16 id);
extern u8 FILE_UTIL_GetMachineIndex(u16 id);
#include "../arm9/beacon.h"
struct MyItem;
extern u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *bag, u16 itemId, u16 quantity, u16 heapId);
extern u32 MYITEM_SAVEDATA_GetItemQuantity(struct MyItem *bag, u16 itemId, u16 heapId);
extern int TOUCHPANEL_HitCont(const union TouchHitTable *p);
#include "../arm9/gfl_heap_wrap.h"
extern void MYITEM_SAVEDATA_CopyPocket(struct MyItem *bag, void *buffer, u32 pocket, s32 toBuffer);
extern void *FILE_UTIL_CreateItemArcHandle(u32 a);
struct ArcFile;
extern void *FILE_UTIL_LoadArcMember(struct ArcFile *arc, u32 item, u32 heap);
struct ItemRecord;
extern u32 FILE_UTIL_GetItemRecordParam(struct ItemRecord *record, u32 prop);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(SortEntry *, SortEntry *), void *buf);
#include "../arm9/pms_draw.h"
extern void *FILE_UTIL_LoadItemRecord(unsigned int item, unsigned int which, unsigned int heap);
#include "../arm9/wipe.h"
struct TcblSystem;
#include "../arm9/tcbl.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
extern void MYITEM_SAVEDATA_SetLastFieldPocket(struct BagCursor *p, u16 v);
extern void MYITEM_SAVEDATA_SetFieldPocketCursor(struct BagCursor *p, int i, s16 a, s16 b);
#include "../arm9/strbuf.h"
#include "../arm9/bmp_win.h"
struct GfFont;
#include "../arm9/gf_font.h"
extern void BUTTON_MAN_Delete(struct ButtonMan *bm);
#include "../arm9/procsys.h"
extern int TOUCHPANEL_HitTrg(const union TouchHitTable *p);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, s32 c, u32 d, s32 e, u16 f);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);
#ifdef __MWERKS__
#define ARC_UTIL_UploadBgPaletteAddFromHandle ARC_UTIL_UploadBgPaletteAddFromHandleHeader
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef ARC_UTIL_UploadBgPaletteAddFromHandle
extern void ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
#endif
struct DispVramCfg;
struct SysInit;
#include "../arm9/bmp_menuwork.h"
extern void ARC_UTIL_UploadPaletteFromHandle(void *arc, u32 memberIdx, u32 kind, u32 offset, u32 dest, u32 size, u16 flags);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
#include "../arm9/app_icon.h"
extern int WAZA_TOOL_GetDamageType(u16);
extern u8 WAZA_TOOL_GetType(u16 move);
#include "../arm9/bmp.h"
extern u32 FILE_UTIL_GetId(u32 id);
extern void FILE_UTIL_ReadStringAlt(void *dst, u32 entry, u32 heap);
extern u32 FILE_UTIL_IsMachineItem(u32 id);
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
#include "../arm9/comm_history.h"
struct TaskMenuInitWork;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
#ifdef __MWERKS__
#define WAZA_TOOL_GetParam WAZA_TOOL_GetParamHeader
#endif
#include "../arm9/waza_tool.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef WAZA_TOOL_GetParam
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
#endif
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
#include "../arm9/msg_speed.h"
struct TextPrinter;
extern void *ARC_UTIL_LoadHandleMember(void *narc, u32 fileID, u32 decompress, u16 heapID);
#include "../arm9/nns_g2d_load.h"
struct TcbList;
extern struct TcbList *GFL_USE_GetMainTaskList(void);
#include "../arm9/g2.h"
#include "../arm9/gfl_heap.h"
#ifdef __MWERKS__
/* original prototypes: the DS code calls CompactAllPockets with a second argument and reads the pocket as int */
extern int MYITEM_SAVEDATA_GetLastFieldPocket(struct BagCursor *p);
extern void MYITEM_SAVEDATA_CompactAllPockets();
#else
#include "../arm9/myitem_savedata.h"
#endif
extern void MYITEM_SAVEDATA_GetFieldPocketCursor(struct BagCursor *p, int i, s16 *a, s16 *b);
#include "../arm9/button_man.h"
#ifdef __MWERKS__
#define GFL_USE_AddMainTask GFL_USE_AddMainTaskHeader
#endif
#include "../arm9/gfl_use.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef GFL_USE_AddMainTask
extern struct TcbTask *GFL_USE_AddMainTask();
#endif
struct GFont;
#include "../arm9/net.h"
void ITEMMENU_HandleActionMenuChoice(ItemMenuWork *work);
void ITEMMENU_TaskSelectItem(ItemMenuWork *work);
void ITEMMENU_TaskBagMain(struct ItemMenuWork *work);
void ITEMMENU_TaskActionMenuInput(ItemMenuWork *work);
void ITEMMENU_TaskOpenActionMenu(ItemMenuWork *work);
void ITEMMENU_TaskRegisterResultMessage(ItemMenuWork *work);
void ITEMMENU_TaskStartRegisterResult(ItemMenuWork *work);
void ITEMMENU_TaskUseNoticeMessage(ItemMenuWork *work);
void ITEMMENU_TaskReturnToListAfterMessage(ItemMenuWork *work);
void ITEMMENU_TaskBeginReturnToList(ItemMenuWork *work);
void ITEMMENU_TaskTossConfirmInput(ItemMenuWork *work);
void ITEMMENU_TaskOpenTossConfirm(ItemMenuWork *work);
void ITEMMENU_TaskTossAskQuantity(ItemMenuWork *work);
void ITEMMENU_TaskTossQuantityInput(ItemMenuWork *work);
void ITEMMENU_TaskGiveItem(ItemMenuWork *work);
void ITEMMENU_TaskSellQuantityInput(ItemMenuWork *work);
void ITEMMENU_TaskSellAskConfirm(ItemMenuWork *work);
void ITEMMENU_TaskSellConfirmInput(ItemMenuWork *work);
void ITEMMENU_TaskWaitMessageDismiss(ItemMenuWork *work);
void ITEMMENU_TaskReturnToListFromQuantity(ItemMenuWork *work);
void ITEMMENU_RemoveSelectedItems(ItemMenuWork *work, int x);
void ITEMMENU_ShowQuantityWindows(ItemMenuWork *work, int v);
void ITEMMENU_HideQuantityWindows(ItemMenuWork *work);
int ITEMMENU_HandleQuantityInput(ItemMenuWork *work);
int ITEMMENU_CompareSortEntries(SortEntry *a, SortEntry *b);
void ITEMMENU_SortPocket(ItemMenuWork *work);
void ITEMMENU_ShowInputGuardError(ItemMenuWork *work);
void ITEMMENU_SortAndRedraw(ItemMenuWork *work);
void ITEMMENU_RefreshInputGuard(ItemMenuWork *work);
void ITEMMENU_SetCursorActive(ItemMenuWork *work, int flag);
int ITEMMENU_IsBrowseMode(ItemMenuWork *work);
int ITEMMENU_ToggleRegisteredItem(ItemMenuWork *work, int k);
int ITEMMENU_GetPocketSortFlag(int x);
void ITEMMENU_TogglePocketSortFlag(ItemMenuWork *work);
void ITEMMENU_UpdatePocketSortIcon(ItemMenuWork *work);
void ITEMMENU_CheckItemFilter(ItemMenuWork *work, void *rec, u16 *p, u8 *out);
void ITEMMENU_BuildActionList(ItemMenuWork *work, unsigned char *q);
void ITEMMENU_OpenActionMenu(ItemMenuWork *work);
int ITEMMENU_IsItemRegistered(ItemMenuWork *work, int value);
void ITEMMENU_HandleTouchTarget(u32 idx, s32 flag, void *);
void ITEMMENU_VBlankCallback(struct TcbTask *unusedArg, void *arg);
void ITEMMENU_TaskStartFadeIn(ItemMenuWork *work);
void ITEMMENU_TaskWaitFadeIn(ItemMenuWork *work);
int ITEMMENU_Init(void *proc, int st, ItemMenuArgs *a);
int ITEMMENU_Main(int a, int b, int c, ItemMenuWork *work);
int ITEMMENU_Exit(void *proc, int b, ItemMenuResult *par, ItemMenuWork *work);
void ITEMMENU_ReturnToBagMain(ItemMenuWork *work);
void ITEMMENU_ReturnToListInput(ItemMenuWork *work);
void ITEMMENU_CreateBlinkPalAnm(ItemMenuWork *work);
void ITEMMENU_DeleteBlinkPalAnm(ItemMenuWork *work);
void ITEMMENU_TaskSelectItemFlash(ItemMenuWork *work);
void ITEMMENU_StartSideButtonPress(ItemMenuWork *work, int a, ItemMenuTaskFn callback);
void ITEMMENU_TaskWaitSideButtonPress(ItemMenuWork *work);
void ITEMMENU_StartPocketTabPress(ItemMenuWork *work, int u, int a, ItemMenuTaskFn callback);
void ITEMMENU_TaskWaitPocketTabPress(ItemMenuWork *work);
int ITEMMENU_GetYesNoTouchChoice(void);
void ITEMMENU_TaskReopenListFromQuantity(ItemMenuWork *work);
void ITEMMENU_TaskReturnFromQuantity(ItemMenuWork *work);
void ITEMMENU_AllocPalAnmSlots(ItemMenuWork *work);
void ITEMMENU_FreePalAnmSlots(ItemMenuWork *work);
void ITEMMENU_TaskInputGuardMessage(ItemMenuWork *work);
void ITEMMENU_TaskWaitMessageThenList(ItemMenuWork *work);
int ITEMMENU_IsCheckModeAllowed(ItemMenuWork *work, int value);
void ITEMMENU_ReturnToBagMainAlias(ItemMenuWork *work);
void ITEMMENU_InitDisplayBanks(void);
void ITEMMENU_ResetDisplayLayers(void);
void ITEMMENU_LoadBagGraphics(ItemMenuWork *work, void *archive);
void ITEMMENU_LoadTabGraphics(ItemMenuWork *work, void *bg);
void ITEMMENU_SetupGraphics(ItemMenuWork *work);
void ITEMMENU_ApplyBgPalettes(ItemMenuWork *work);
void ITEMMENU_SetLayersVisible(void *p, int v);
void ITEMMENU_SetMoveTypeIconsVisible(ItemMenuWork *work, int mode);
void ITEMMENU_DrawMoveInfo(ItemMenuWork *work);
void ITEMMENU_HideMoveInfo(ItemMenuWork *work);
void ITEMMENU_FreeGraphics(ItemMenuWork *work);
void ITEMMENU_PrintMenuTitle(ItemMenuWork *work);
void ITEMMENU_InitWindows(ItemMenuWork *work);
void ITEMMENU_DestroyMovingCursor(ItemMenuWork *work);
void ITEMMENU_CreateMovingCursor(ItemMenuWork *work, int id);
void ITEMMENU_FreeActionMenuResources(ItemMenuWork *work);
void ITEMMENU_LoadPocketGraphics(ItemMenuWork *work);
void ITEMMENU_CreateCursorActors(ItemMenuWork *work);
int ITEMMENU_GetRowColorKind(u16 x);
void ITEMMENU_PrintItemList(ItemMenuWork *work);
void ITEMMENU_SnapSelectorToCursor(ItemMenuWork *work);
void ITEMMENU_UploadSlotGraphics(ItemMenuWork *work);
void ITEMMENU_UpdateCursorFromTouch(ItemMenuWork *work);
void ITEMMENU_MoveCursorToRow(ItemMenuWork *work);
void ITEMMENU_CreateSideButtonActors(ItemMenuWork *work);
void ITEMMENU_CreateTabActors(ItemMenuWork *work);
void ITEMMENU_SelectTab(ItemMenuWork *work, unsigned sel);
void ITEMMENU_ClearMessageWindow(ItemMenuWork *work);
void ITEMMENU_OpenPopupList(ItemMenuWork *work, int *tbl, int n);
void ITEMMENU_LoadBgPaletteMode(ItemMenuWork *work, int mode);
void ITEMMENU_PrintMoveInfoText(ItemMenuWork *work, int x);
void ITEMMENU_ShowMessage(ItemMenuWork *work, int mode);
void ITEMMENU_ShowMessageDefault(ItemMenuWork *work);
void ITEMMENU_ShowItemUseMessage(ItemMenuWork *work, unsigned v);
int ITEMMENU_IsMessageFinished(ItemMenuWork *work);
void ITEMMENU_PrintPocketName(ItemMenuWork *work);
void ITEMMENU_HideSideWindows(ItemMenuWork *work);
void ITEMMENU_PrintPocketCount(ItemMenuWork *work, int val);
void ITEMMENU_PrintMoney(ItemMenuWork *work);
void ITEMMENU_EnterQuantityMode(ItemMenuWork *work);
void ITEMMENU_LeaveQuantityMode(ItemMenuWork *work);
void ITEMMENU_OpenYesNoList(ItemMenuWork *work);
void ITEMMENU_CloseYesNoList(ItemMenuWork *work);
void ITEMMENU_LoadSellPalette(ItemMenuWork *work);
void ITEMMENU_FlushDirtyWindows(ItemMenuWork *work);
void ITEMMENU_PrintQuantityPrice(ItemMenuWork *work, int val);
int ITEMMENU_PocketToSortFlag(int x);
void ITEMMENU_UpdateSlotActorPosition(ItemMenuWork *work, u32 val);
void ITEMMENU_UpdateSideButtons(ItemMenuWork *work, int mode);
void ITEMMENU_SetBackButtonAnim(ItemMenuWork *work, int v);
void ITEMMENU_UpdateInputGuardAnim(ItemMenuWork *work);
void ITEMMENU_UpdateSideButtonsForMode(ItemMenuWork *work, int mode);
int ITEMMENU_MoveActorToPoint(ItemMenuWork *work);
void ITEMMENU_PrintToWindow(ItemMenuWork *work, ItemMenuWindow *slot, void *str, u16 x, TextCoord y, u16 color);
void ITEMMENU_FlushWindowAt(ItemMenuWindow *slot);
extern ItemmenuTouchHitTable sQuantityTouchRects;
extern char sHeapSiteName[];
extern ActionMsgIds sActionMsgIds;
extern ActionIds sDefaultActionIds;
extern const PocketTable sTabPockets;
extern const char sBackButtonHitRect[];
extern const struct BgTemplate sBgLayer0Template;
extern const struct BgTemplate sBgLayer1Template;
extern const struct BgTemplate sBgLayer2Template;
extern const struct BgTemplate sBgLayer3Template;
extern const struct BgTemplate sBgLayer4Template;
extern const struct BgTemplate sBgLayer5Template;
extern const struct BgTemplate sBgLayer6Template;
extern u8 sVramBankConfig[];
extern u8 sClactSystemConfig[];
extern const struct DispConfig sDispConfig;
extern const u8 sRowStyleFlags[];
extern const ByteTable5 sSideButtonAnimSeqs;
extern const ByteTable5 sSideButtonXPositions;
extern const ByteTable2 sArrowAnimSeqs;
extern const ByteTable2 sArrowYPositions;
extern unsigned char sTabSoftPriorities[];
extern short sTabPositions[][2];
extern unsigned char sTabAnimSeqs[];
extern char sButtonHitTable[];
/* Item id range with the handler that uses items of that range. */
typedef struct ItemUseRange {
    u16 firstItemId;
    u16 itemCount;
    void (*useHandler)(void *);
} ItemUseRange;
struct BagSlot;
/* Message ids of the bag message bank. */
#define ITEMMENU_MSG_CANT_USE_KEY_ITEM 0x38
#define ITEMMENU_MSG_CANT_USE_IN_CONTEXT 0x39
#define ITEMMENU_MSG_CANT_USE_NOW 0x3A
#define ITEMMENU_MSG_REPEL_USED 0x3F
#define ITEMMENU_MSG_REPEL_STILL_ACTIVE 0x40
extern BagSlot *MYITEM_SAVEDATA_GetSlot(struct MyItem *bag, u32 pocket, u32 index);
extern unsigned int MYITEM_SAVEDATA_CountUsedSlots(const BagSlot *items, unsigned int maxCount);
extern u32 MYITEM_SAVEDATA_CountUsedSlotsInPocket(struct MyItem *bag, u32 pocket);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outX, u32 *outY);
struct SaveControl;
#include "../arm9/move_pokemon_save.h"
struct MovePokemonSave;
void ITEMMENU_SetTask(ItemMenuWork *work, ItemMenuTaskFn taskFn);
void ITEMMENU_ForceRedrawList(ItemMenuWork *work);
void ITEMMENU_RedrawList(ItemMenuWork *work);
BagSlot *ITEMMENU_GetSlot(ItemMenuWork *work, int index);
int ITEMMENU_GetSellTotal(int itemId, int count, unsigned int heapId);
int ITEMMENU_GetCursorIndex(ItemMenuWork *work);
int ITEMMENU_GetItemCount(ItemMenuWork *work);
void ITEMMENU_RegisterItemName(ItemMenuWork *work, int slot, unsigned int itemId);
void ITEMMENU_RegisterItemNameCounted(ItemMenuWork *work, int slot, unsigned int itemId, int isPlural, int flags);
void ITEMMENU_SwapSlots(ItemMenuWork *work, int indexA, int indexB);
void ITEMMENU_MoveSlot(ItemMenuWork *work, int fromIndex, int toIndex);
void ITEMMENU_SwitchPocketCursor(ItemMenuWork *work, int prevPocket, int nextPocket);
int ITEMMENU_MoveCursorDown(ItemMenuWork *work, int itemCount, int canWrap);
int ITEMMENU_MoveCursorUp(ItemMenuWork *work, int itemCount, int canWrap);
u32 ITEMMENU_HandleScrollbarTouch(ItemMenuWork *work);
int ITEMMENU_HandleMoveModeKeys(ItemMenuWork *work);
int ITEMMENU_HandleListKeys(ItemMenuWork *work);
int ITEMMENU_HandleListTouch(ItemMenuWork *work);
int ITEMMENU_IsBackButtonTouched(void);
void ITEMMENU_TaskFinishClose(ItemMenuWork *work);
void ITEMMENU_TaskListInput(ItemMenuWork *work);
int ITEMMENU_IsRepelItem(u16 itemId);
int ITEMMENU_GetFieldUseKind(u16 itemId);
void ITEMMENU_UseRepel(ItemMenuWork *work);
void ITEMMENU_TaskWaitMessage(ItemMenuWork *work);
void ITEMMENU_ShowKeyItemRefusal(ItemMenuWork *work);
void ITEMMENU_ShowMessageThenWait(ItemMenuWork *work);
u32 ITEMMENU_TryStartUse(ItemMenuWork *work);
u32 ITEMMENU_TryStartGive(ItemMenuWork *work);
u32 ITEMMENU_TryStartRegister(ItemMenuWork *work);
u32 ITEMMENU_TryStartCheck(ItemMenuWork *work);
u32 ITEMMENU_TryStartToss(ItemMenuWork *work);
u32 ITEMMENU_TryStartSort(ItemMenuWork *work);
u32 ITEMMENU_TryStartPlant(ItemMenuWork *work);
u32 ITEMMENU_TryStartSell(ItemMenuWork *work);
int ITEMMENU_FindUseRange(u16 itemId);
extern const ItemUseRange gItemMenuUseRanges[8];

/* Sets the task function of the screen and the key repeat speed. */
void ITEMMENU_SetTask(ItemMenuWork *work, ItemMenuTaskFn taskFn)
{
    work->taskFn = taskFn;
    KEY_SetRepeatSpeed(work->keyRepeatDelay, work->keyRepeatInterval);
}

/* Forces the list to be drawn again. */
void ITEMMENU_ForceRedrawList(ItemMenuWork *work)
{
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
}

void ITEMMENU_RedrawList(ItemMenuWork *work)
{
    if (UI_GetInputMode() == 0)
        ITEMMENU_DrawMoveInfo(work);
    else
        ITEMMENU_HideMoveInfo(work);
    ITEMMENU_PrintItemList(work);
    ITEMMENU_UpdatePocketSortIcon(work);
    work->listDirty = 1;
}

/* Slot of the shown pocket: the work copy while an item is being moved,
 * the bag otherwise. */
BagSlot *ITEMMENU_GetSlot(ItemMenuWork *work, int index)
{
    if (work->usingWorkCopy) return &work->items[index];
    return MYITEM_SAVEDATA_GetSlot(work->bag, (u16)(work->currentPocket), (u16)index);
}

/*
 * extent: two bytes of zero alignment follow the 26-byte function.
 * lever: enum quotient preserves its r1 web and the copy to return r0.
 * The signed quotient is multiplied with unsigned modular arithmetic.
 */
int ITEMMENU_GetSellTotal(int itemId, int count, unsigned int heapId)
{
    typedef enum { HALF_ZERO } Half;
    Half unitPrice;
    unitPrice = (Half)((int)FILE_UTIL_GetItemParam((u16)itemId, 0, heapId) / 2);
    return (int)((unsigned int)unitPrice * (unsigned int)count);
}

/* Index of the selected entry in the whole list. */
int ITEMMENU_GetCursorIndex(ItemMenuWork *work)
{
    return (int)((unsigned int)work->cursorRow + (unsigned int)work->scrollOffset + 1U);
}

int ITEMMENU_GetItemCount(ItemMenuWork *work)
{
    if (work->usingWorkCopy) return MYITEM_SAVEDATA_CountUsedSlots(work->items, ITEMMENU_POCKET_ITEM_COUNT);
    return MYITEM_SAVEDATA_CountUsedSlotsInPocket(work->bag, work->currentPocket);
}

void ITEMMENU_RegisterItemName(ItemMenuWork *work, int slot, unsigned int itemId)
{
    WORDSET_SetSlotFromMsg36(work->wordSet, slot, itemId);
}

/*
 * Extent ends in two zero alignment bytes.
 */
void ITEMMENU_RegisterItemNameCounted(ItemMenuWork *work, int slot, unsigned int itemId, int isPlural, int flags)
{
    WORDSET_SetSlotFromBank(work->wordSet, slot, itemId, isPlural, flags);
}

void ITEMMENU_SwapSlots(ItemMenuWork *work, int indexA, int indexB)
{
    int savedSlot;
    MI_CpuCopy8(&work->items[indexA], &savedSlot, 4);
    MI_CpuCopy8(&work->items[indexB], &work->items[indexA], 4);
    MI_CpuCopy8(&savedSlot, &work->items[indexB], 4);
}

/* Moves an entry to a new place by swapping it step by step. */
void ITEMMENU_MoveSlot(ItemMenuWork *work, int fromIndex, int toIndex)
{
    if (fromIndex == toIndex) return;
    if (fromIndex < toIndex) {
        for (; fromIndex < toIndex; fromIndex++) ITEMMENU_SwapSlots(work, fromIndex, fromIndex + 1);
    } else {
        for (; fromIndex > toIndex; fromIndex--) ITEMMENU_SwapSlots(work, fromIndex, fromIndex - 1);
    }
}

/* Stores the cursor of the old pocket and loads the cursor of the new one. */
void ITEMMENU_SwitchPocketCursor(ItemMenuWork *work, int prevPocket, int nextPocket)
{
    s16 loaded[2];

    MYITEM_SAVEDATA_SetLastFieldPocket(work->bagCursor, prevPocket);
    MYITEM_SAVEDATA_SetFieldPocketCursor(work->bagCursor, (u16)prevPocket, work->cursorRow, work->scrollOffset + 1);
    MYITEM_SAVEDATA_GetFieldPocketCursor(work->bagCursor, (u16)nextPocket, &loaded[1], &loaded[0]);
    work->cursorRow = loaded[1];
    work->scrollOffset = loaded[0] - 1;
    ITEMMENU_MoveCursorToRow(work);
    ITEMMENU_PrintPocketCount(work, nextPocket);
    ITEMMENU_SelectTab(work, nextPocket);
    ITEMMENU_LoadBgPaletteMode(work, nextPocket);
}

/* Cursor one entry down. Six rows are visible; the list scrolls once the
 * cursor is on the last row. Returns 1 when the cursor moved. */
int ITEMMENU_MoveCursorDown(ItemMenuWork *work, int itemCount, int canWrap)
{
    int prevRow, prevScroll;

    if (itemCount == 0)
        return 0;
    prevRow = work->cursorRow;
    prevScroll = work->scrollOffset;
    if (prevRow == 5 && prevScroll + 7 < itemCount) {
        work->scrollOffset = work->scrollOffset + 1;
    } else if (prevRow != 5 && prevRow + 1 < itemCount) {
        work->cursorRow = work->cursorRow + 1;
    } else if (canWrap == 1) {
        work->scrollOffset = -1;
        work->cursorRow = 0;
    }
    return prevRow != work->cursorRow || prevScroll != work->scrollOffset;
}

/* Cursor one entry up, wrapping to the end of the list when allowed. */
int ITEMMENU_MoveCursorUp(ItemMenuWork *work, int itemCount, int canWrap)
{
    int prevRow, prevScroll, lastScroll;

    if (itemCount == 0)
        return 0;
    prevRow = work->cursorRow;
    prevScroll = work->scrollOffset;
    if (prevRow == 0 && prevScroll != -1) {
        work->scrollOffset = work->scrollOffset - 1;
    } else if (prevRow != 0) {
        work->cursorRow = work->cursorRow - 1;
    } else if (canWrap == 1) {
        lastScroll = itemCount - 7;
        work->scrollOffset = lastScroll;
        if (lastScroll < -1)
            work->scrollOffset = -1;
        if ((work->cursorRow = 5) >= itemCount)
            work->cursorRow = itemCount - 1;
    }
    return prevRow != work->cursorRow || prevScroll != work->scrollOffset;
}

/* Touch on the scroll bar at the right edge of the list. */
u32 ITEMMENU_HandleScrollbarTouch(ItemMenuWork *work)
{
    u32 touchX, touchY, prevScroll;
    int itemCount;

    itemCount = ITEMMENU_GetItemCount(work);
    if (itemCount >= 7 && TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchX >= 0x100 || touchX < 0xE0)
            return 0;
        if (work->isTouchActive == 0) {
            if (TOUCHPANEL_GetTrg() == 1) {
                if (touchY < 0x10 || touchY >= 0x98)
                    return 0;
                work->isTouchActive = 1;
            } else
                return 0;
        }
        ITEMMENU_SetCursorActive(work, 0);
        prevScroll = work->scrollOffset;
        work->scrollOffset = SCROLLBAR_GetValueFromPos(itemCount - 6, touchY, 0x1A, 0x8E, 0) - 1;
        ITEMMENU_UpdateCursorFromTouch(work);
        if (work->scrollOffset != prevScroll) {
            GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_CURSOR);
            return 1;
        }
    }
    return 0;
}

/* Key input while an item is being moved: the entry follows the cursor. */
int ITEMMENU_HandleMoveModeKeys(ItemMenuWork *work)
{
    int moved = 0;
    int startIndex, itemCount;
    u32 steps;

    startIndex = ITEMMENU_GetCursorIndex(work);
    itemCount = ITEMMENU_GetItemCount(work);
    if (KEY_GetRepeat() & ITEMMENU_KEY_DOWN) {
        moved = ITEMMENU_MoveCursorDown(work, itemCount, 1);
    } else if (KEY_GetRepeat() & ITEMMENU_KEY_UP) {
        moved = ITEMMENU_MoveCursorUp(work, itemCount, 1);
    } else if (KEY_GetRepeat() & ITEMMENU_KEY_R) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorDown(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    } else if (KEY_GetRepeat() & ITEMMENU_KEY_L) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorUp(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    }
    if (moved) {
        itemCount = ITEMMENU_GetCursorIndex(work);
        GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_CURSOR);
        ITEMMENU_MoveSlot(work, startIndex, itemCount);
    }
    return moved;
}

/* Key input in the plain list: up, down, and six entries with L and R. */
int ITEMMENU_HandleListKeys(ItemMenuWork *work)
{
    int moved = 0;
    int itemCount;
    u32 steps;

    itemCount = ITEMMENU_GetItemCount(work);
    if (KEY_GetRepeat() & ITEMMENU_KEY_DOWN) {
        moved = ITEMMENU_MoveCursorDown(work, itemCount, 1);
    } else if (KEY_GetRepeat() & ITEMMENU_KEY_UP) {
        moved = ITEMMENU_MoveCursorUp(work, itemCount, 1);
    } else if (KEY_GetRepeat() & ITEMMENU_KEY_R) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorDown(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    } else if (KEY_GetRepeat() & ITEMMENU_KEY_L) {
        steps = moved;
        do {
            if (ITEMMENU_MoveCursorUp(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    }
    return moved;
}

/* Touch on a list row: moves the cursor to it. Rows are 0x18 pixels high. */
int ITEMMENU_HandleListTouch(ItemMenuWork *work)
{
    u32 touchX, touchY;
    int itemCount, startIndex;
    u32 targetRow;
    int rowDistance;
    u32 step;

    if (TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchX < 0x90 || touchX > 0xE7 || touchY < 0xC || touchY > 0x9B)
            return 0;
        targetRow = (touchY - 0xC) / 0x18;
        if ((u32)work->cursorRow == targetRow)
            return 0;
        itemCount = ITEMMENU_GetItemCount(work);
        startIndex = ITEMMENU_GetCursorIndex(work);
        rowDistance = (u32)work->cursorRow - targetRow;
        if (rowDistance < 0)
            rowDistance = -rowDistance;
        if ((u32)work->cursorRow < targetRow) {
            for (step = 0; step < rowDistance; step++) {
                if (ITEMMENU_MoveCursorDown(work, itemCount, 0) == 0)
                    break;
            }
        } else if ((u32)work->cursorRow > targetRow) {
            for (step = 0; step < rowDistance; step++) {
                if (ITEMMENU_MoveCursorUp(work, itemCount, 0) == 0)
                    break;
            }
        }
        if (step == 0)
            return 0;
        ITEMMENU_MoveSlot(work, startIndex, ITEMMENU_GetCursorIndex(work));
        ITEMMENU_SetCursorActive(work, 0);
        return 1;
    }
    return 0;
}

/* Touch on the back button in the bottom right corner. */
int ITEMMENU_IsBackButtonTouched(void)
{
    unsigned int touchX;
    unsigned int touchY;
    if (TOUCHPANEL_GetPointTrg(&touchX, &touchY) == 1 && touchX >= 0xE0 && touchX <= 0xF7 && touchY >= 0xA8 && touchY <= 0xBF) return 1;
    return 0;
}

/* Task run after the closing transition. */
void ITEMMENU_TaskFinishClose(ItemMenuWork *work)
{
    ITEMMENU_UpdateSideButtonsForMode(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}

/* Main task of the item list: touch, A, B and cursor keys. */
void ITEMMENU_TaskListInput(ItemMenuWork *work)
{
    int startIndex;

    BLINK_PALANM_Update(work->blinkPalAnm);
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printSys) == 0)
        return;
    startIndex = ITEMMENU_GetCursorIndex(work);
    if (ITEMMENU_HandleScrollbarTouch(work)) {
        ITEMMENU_MoveSlot(work, startIndex, ITEMMENU_GetCursorIndex(work));
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        return;
    }
    if (TOUCHPANEL_GetCont() == 0) {
        work->isTouchActive = 0;
        if (work->isDraggingItem == 1) {
            GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_SELECT);
            work->isDraggingItem = 0;
            MYITEM_SAVEDATA_CopyPocket(work->bag, work->items, work->currentPocket, 0);
            CLACT_SetActorAnimSeq((struct ClactActor *)work->selectorActor, 1);
            ITEMMENU_UpdateSideButtonsForMode(work, 1);
            work->usingWorkCopy = 0;
            ITEMMENU_SetCursorActive(work, 0);
            ITEMMENU_ReturnToBagMain(work);
            return;
        }
    }
    if (work->isTouchActive == 1)
        return;
    if (KEY_GetTrg() & (ITEMMENU_KEY_A | ITEMMENU_KEY_SELECT)) {
        GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_SELECT);
        MYITEM_SAVEDATA_CopyPocket(work->bag, work->items, work->currentPocket, 0);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->selectorActor, 1);
        ITEMMENU_UpdateSideButtonsForMode(work, 1);
        work->usingWorkCopy = 0;
        ITEMMENU_SetCursorActive(work, 1);
        ITEMMENU_ReturnToBagMain(work);
        return;
    }
    if (KEY_GetTrg() & ITEMMENU_KEY_B) {
        GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_CANCEL);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->selectorActor, 1);
        work->usingWorkCopy = 0;
        ITEMMENU_SetCursorActive(work, 1);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskFinishClose);
        return;
    }
    if (ITEMMENU_IsBackButtonTouched() == 1) {
        GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_CANCEL);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->selectorActor, 1);
        work->usingWorkCopy = 0;
        ITEMMENU_SetCursorActive(work, 0);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskFinishClose);
        return;
    }
    if (ITEMMENU_HandleListTouch(work)) {
        work->isDraggingItem = 1;
        ITEMMENU_MoveCursorToRow(work);
        GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_CURSOR);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        return;
    }
    if (ITEMMENU_HandleMoveModeKeys(work)) {
        ITEMMENU_MoveCursorToRow(work);
        GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_CURSOR);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
    }
}

/* The three repel items (ids 0x4C, 0x4D and 0x4F). */
int ITEMMENU_IsRepelItem(u16 itemId)
{
    int isRepel = 0;
    itemId = (u16)(itemId + 0xFFB4);
    if (itemId <= 3 && ((1 << itemId) & 0xB)) isRepel = 1;
    return isRepel;
}

/* 1 for the repel items, 2 for items 0x268 and 0x269, 0 for all others. */
int ITEMMENU_GetFieldUseKind(u16 itemId)
{
    if (ITEMMENU_IsRepelItem(itemId)) return 1;
    if (itemId == 0x268 || itemId == 0x269) return 2;
    return 0;
}

/* Uses a repel: starts it when none is active, then waits for the message. */
void ITEMMENU_UseRepel(ItemMenuWork *work)
{
    void *repelState;
    u8 steps;

    if (ITEMMENU_IsRepelItem(work->selectedItemId)) {
        repelState = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(work->saveData));
        if (MOVE_POKEMON_SAVE_IsCooldownDone(repelState)) {
            steps = FILE_UTIL_GetItemParam(work->selectedItemId, 2, work->heapId);
            MOVE_POKEMON_SAVE_SetCooldown(repelState, steps);
            ITEMMENU_RemoveSelectedItems(work, 1);
            MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_REPEL_USED, work->tempString);
            WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
            ITEMMENU_RegisterItemName(work, 1, work->selectedItemId);
            WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
            ITEMMENU_ShowMessage(work, 1);
            GFL_USE_PlaySeDefaultVolume(ITEMMENU_SE_REGISTER);
        } else {
            MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_REPEL_STILL_ACTIVE, work->tempString);
            WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
            ITEMMENU_ShowMessage(work, 1);
        }
        ITEMMENU_SetTask(work, ITEMMENU_TaskWaitMessage);
    }
}

/* Task: waits until the message is read, then returns to the list. */
void ITEMMENU_TaskWaitMessage(ItemMenuWork *work)
{
    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if ((KEY_GetTrg() & (ITEMMENU_KEY_A | ITEMMENU_KEY_B)) == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    BG_SYS_ClearSlot(3);
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    work->listDirty = 1;
    ITEMMENU_MoveCursorToRow(work);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}

/* Shows the refusal message for the items 0x268 and 0x269. */
void ITEMMENU_ShowKeyItemRefusal(ItemMenuWork *work)
{
    if ((unsigned int)work->selectedItemId - 0x268 <= 1) {
        MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_KEY_ITEM, work->tempString);
        WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessage(work, 1);
        ITEMMENU_SetTask(work, ITEMMENU_TaskWaitMessage);
    }
}

/* Starts the message already prepared and waits for the player. */
void ITEMMENU_ShowMessageThenWait(ItemMenuWork *work) { ITEMMENU_ShowMessage(work, 1); ITEMMENU_SetTask(work, ITEMMENU_TaskWaitMessage); }

/* Action 0 (use). Enters the state when allowed, else shows the refusal. */
u32 ITEMMENU_TryStartUse(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 0)) {
            work->nextState = 0xA;
            ITEMMENU_SetTask(work, 0);
            return 1;
        }
        MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    } else if (work->usageContext == 1) {
        if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 0)) {
            work->nextState = 0xB;
            ITEMMENU_SetTask(work, 0);
            return 1;
        }
        MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_IN_CONTEXT, work->tempString);
        WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    }
    return 0;
}

/* Action 1 (give). */
u32 ITEMMENU_TryStartGive(ItemMenuWork *work)
{
    u32 started = 1;

    if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 1)) {
        work->nextState = 7;
        ITEMMENU_SetTask(work, 0);
        return started;
    }
    MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 2 (register). */
u32 ITEMMENU_TryStartRegister(ItemMenuWork *work)
{
    if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 2)) {
        work->nextState = 8;
        ITEMMENU_SetTask(work, 0);
        return 1;
    }
    MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 6 (check). */
u32 ITEMMENU_TryStartCheck(ItemMenuWork *work)
{
    if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 6)) {
        work->nextState = 0x11;
        ITEMMENU_SetTask(work, 0);
        return 1;
    }
    MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 4 (toss): asks for a quantity first. */
u32 ITEMMENU_TryStartToss(ItemMenuWork *work)
{
    if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 4)) {
        work->nextState = 0xF;
        ITEMMENU_SetTask(work, 0);
        ITEMMENU_RemoveSelectedItems(work, 1);
        return 1;
    }
    MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 5 (sort). */
u32 ITEMMENU_TryStartSort(ItemMenuWork *work)
{
    if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 5)) {
        work->nextState = 0x10;
        ITEMMENU_SetTask(work, 0);
        return 1;
    }
    MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
    return 0;
}

/* Action 9 (plant), only in usage context 0. */
u32 ITEMMENU_TryStartPlant(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 9)) {
            work->nextState = 0x14;
            ITEMMENU_SetTask(work, 0);
            return 1;
        }
        MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    }
    return 0;
}

/* Action 3 (sell): asks for a quantity first, only in usage context 0. */
u32 ITEMMENU_TryStartSell(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 3)) {
            work->nextState = 0xE;
            ITEMMENU_SetTask(work, 0);
            ITEMMENU_RemoveSelectedItems(work, 1);
            return 1;
        }
        MSGDATA_ReadString(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
        return 0;
    }
    return 0;
}

/*
 * Unlabelled leaf (push {r4,r5}, no lr) called twice by ITEMMENU_HandleActionMenuChoice:
 * finds the entry of the 8-entry range table at 0x021BB9C4 whose
 * [firstItemId, firstItemId + itemCount) holds itemId, or -1.
 */
int ITEMMENU_FindUseRange(u16 itemId)
{
    u32 rangeIndex;
    const ItemUseRange *range;

    for (rangeIndex = 0; rangeIndex < 8; rangeIndex++) {
        range = &gItemMenuUseRanges[rangeIndex];
        if (itemId >= range->firstItemId && itemId < range->firstItemId + range->itemCount)
            return rangeIndex;
    }
    return -1;
}

/*
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is gItemMenuUseRanges[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 */
void ITEMMENU_HandleActionMenuChoice(ItemMenuWork *work)
{
    int closeMenu = 0;
    u32 actionId;
    int fieldUseKind;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)work->menuList)) {
        actionId = work->menuActionTable[APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)work->menuList)];
        work->usageContext = actionId;
        switch (actionId) {
        case 0:
            ITEMMENU_SetBackButtonAnim(work, 0);
            if (work->currentPocket != 4)
                GAME_BEACON_SetItemUse(work->selectedItemId);
            if (work->currentPocket == 2) {
                ITEMMENU_SetTask(work, ITEMMENU_TaskUseNoticeMessage);
            } else if (FILE_UTIL_GetItemParam(work->selectedItemId, 0x1D, work->heapId) == 1) {
                work->nextState = 0xC;
                ITEMMENU_SetTask(work, 0);
            } else if (ITEMMENU_FindUseRange(work->selectedItemId) >= 0) {
                gItemMenuUseRanges[ITEMMENU_FindUseRange(work->selectedItemId)].useHandler(work);
            } else {
                fieldUseKind = ITEMMENU_GetFieldUseKind(work->selectedItemId);
                if (fieldUseKind == 1) {
                    ITEMMENU_SetTask(work, ITEMMENU_UseRepel);
                } else if (fieldUseKind == 2) {
                    ITEMMENU_SetTask(work, ITEMMENU_ShowKeyItemRefusal);
                } else {
                    work->nextState = 5;
                    ITEMMENU_SetTask(work, 0);
                }
            }
            break;
        case 1:
            ITEMMENU_SetBackButtonAnim(work, 0);
            if (FIELD_SKILL_USE_FLAGS_IsSkillUsable(work->actionPermissions, 0)) {
                work->nextState = 0xB;
                ITEMMENU_SetTask(work, 0);
            } else {
                MSGDATA_ReadString(work->msgBank, 0x39, work->tempString);
                WORDSET_SetSlotMyStatus(work->wordSet, 0, work->myStatus);
                WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
                ITEMMENU_SetTask(work, ITEMMENU_ShowMessageThenWait);
            }
            break;
        case 3:
            ITEMMENU_SetTask(work, ITEMMENU_TaskTossAskQuantity);
            break;
        case 4:
        case 5:
            if (ITEMMENU_IsBrowseMode(work) == 1) {
                ITEMMENU_ToggleRegisteredItem(work, work->cursorRow);
                ITEMMENU_RedrawList(work);
                ITEMMENU_UpdateSideButtons(work, 1);
                CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
                ITEMMENU_ReturnToBagMain(work);
            }
            break;
        case 2:
            ITEMMENU_SetBackButtonAnim(work, 0);
            if (work->selectedItemId >= 0x89 && work->selectedItemId <= 0x94) {
                work->nextState = 0x13;
                ITEMMENU_SetTask(work, 0);
            }
            break;
        case 8:
            if (UI_GetInputMode() == 1)
                ITEMMENU_HideMoveInfo(work);
            ITEMMENU_SetCursorActive(work, UI_GetInputMode() == 0);
            ITEMMENU_UpdateSideButtons(work, 1);
            CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
            ITEMMENU_ReturnToBagMain(work);
            break;
        case 9:
            work->nextState = 1;
            ITEMMENU_SetTask(work, 0);
            break;
        case 6:
            work->nextState = 2;
            ITEMMENU_SetBackButtonAnim(work, 0);
            ITEMMENU_SetTask(work, 0);
            break;
        case 7:
            break;
        }
        closeMenu = 1;
    }
    if (closeMenu) {
        ITEMMENU_ClearMessageWindow(work);
        APP_TASKMENU_CloseMenu((struct TaskMenuWork *)work->menuList);
        work->menuList = 0;
    }
}

void ITEMMENU_TaskSelectItem(ItemMenuWork *work)
{
    u16 *itemIdPtr;
    int mode;

    itemIdPtr = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    work->selectedItemId = 0;
    if (itemIdPtr != 0)
        work->selectedItemId = *itemIdPtr;
    mode = work->bagMode;
    if (mode == 2) {
        if (FILE_UTIL_GetItemParam(work->selectedItemId, 3, work->heapId) == 0 && PALANM_IsOutsideReservedIdRange(work->selectedItemId) == 1) {
            if (FILE_UTIL_IsMailItem(work->selectedItemId) != 0)
                work->nextState = 0x12;
            else
                work->nextState = 3;
            ITEMMENU_SetTask(work, 0);
            return;
        }
        MSGDATA_ReadString(work->msgBank, 0x2F, work->tempString);
        ITEMMENU_RegisterItemName(work, 0, work->selectedItemId);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_UpdateSideButtons(work, 0);
        ITEMMENU_SetBackButtonAnim(work, 0);
        ITEMMENU_SetTask(work, ITEMMENU_TaskReturnToListAfterMessage);
    } else if (mode == 5) {
        work->nextState = 1;
        ITEMMENU_SetTask(work, 0);
    } else if (mode == 4) {
        ITEMMENU_SetTask(work, ITEMMENU_TaskGiveItem);
    } else {
        ITEMMENU_OpenActionMenu(work);
        ITEMMENU_ShowItemUseMessage(work, work->selectedItemId);
        ITEMMENU_ShowMessageDefault(work);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 0);
        ITEMMENU_SetTask(work, ITEMMENU_HandleActionMenuChoice);
    }
}

void ITEMMENU_TaskBagMain(struct ItemMenuWork *work)
{
    unsigned int keys;
    int previousPocket;

    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printSys) == 0)
        return;
    if (TOUCHPANEL_GetCont() == 0)
        work->isTouchActive = 0;
    BUTTON_MAN_UpdateSlots(work->taskSys);
    BLINK_PALANM_Update(work->blinkPalAnm);
    if (work->taskFn != ITEMMENU_TaskBagMain)
        return;
    if (ITEMMENU_HandleScrollbarTouch(work) != 0) {
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        return;
    }
    if (work->isTouchActive == 1)
        return;
    if (UI_GetInputMode() == 1) {
        keys = KEY_GetTrg();
        if (keys == 0)
            return;
        if (ITEMMENU_GetItemCount(work) != 0) {
            if ((keys & 0xC0A) == 0) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                ITEMMENU_DrawMoveInfo(work);
                ITEMMENU_SetCursorActive(work, 1);
                return;
            }
        } else {
            ITEMMENU_SetCursorActive(work, 1);
            if (keys & 0xCD)
                return;
        }
    }
    if (KEY_GetTrg() & 2) {
        work->nextState = 1;
        work->selectedItemId = 0;
        UI_SetInputMode(0);
        ITEMMENU_StartSideButtonPress(work, 4, 0);
        return;
    }
    if (KEY_GetTrg() & 0x400) {
        if (work->bagMode == 2)
            return;
        work->nextState = 0;
        work->selectedItemId = 0;
        UI_SetInputMode(0);
        ITEMMENU_StartSideButtonPress(work, 3, 0);
        return;
    }
    if (KEY_GetTrg() & 0x800) {
        if (ITEMMENU_IsBrowseMode(work) != 1)
            return;
        if (work->currentPocket == 4) {
            ITEMMENU_ToggleRegisteredItem(work, work->cursorRow);
            ITEMMENU_RedrawList(work);
        } else {
            ITEMMENU_TogglePocketSortFlag(work);
        }
        if (UI_GetInputMode() != 1)
            return;
        ITEMMENU_DrawMoveInfo(work);
        ITEMMENU_SetCursorActive(work, 1);
        return;
    }
    if ((KEY_GetTrg() & 8) && work->currentPocket != 2 && work->currentPocket != 3 && ITEMMENU_GetItemCount(work) > 1) {
        ITEMMENU_ShowInputGuardError(work);
        ITEMMENU_SetCursorActive(work, 1);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_SetTask(work, ITEMMENU_TaskInputGuardMessage);
        return;
    }
    if (KEY_GetTrg() & 1) {
        if (ITEMMENU_GetItemCount(work) > 0) {
            ITEMMENU_SetTask(work, ITEMMENU_TaskSelectItemFlash);
            return;
        }
    } else if (KEY_GetTrg() & 4) {
        if (work->currentPocket != 2 && work->currentPocket != 3 && ITEMMENU_GetItemCount(work) > 1) {
            MI_CpuFill8(work->items, 0, 0x4D8);
            MYITEM_SAVEDATA_CopyPocket(work->bag, work->items, work->currentPocket, 1);
            CLACT_SetActorAnimSeq((struct ClactActor *)work->selectorActor, 2);
            ITEMMENU_UpdateSideButtonsForMode(work, 0);
            work->usingWorkCopy = 1;
            ITEMMENU_ReturnToListInput(work);
        }
        return;
    } else if (ITEMMENU_HandleListKeys(work) != 0) {
        ITEMMENU_MoveCursorToRow(work);
        GFL_USE_PlaySeDefaultVolume(0x548);
        ITEMMENU_RedrawList(work);
        return;
    }
    if (KEY_GetRepeat() & 0x10) {
        previousPocket = work->currentPocket;
        work->currentPocket = previousPocket + 1;
        if (work->currentPocket >= 5)
            work->currentPocket = 0;
        UI_SetInputMode(0);
        ITEMMENU_StartPocketTabPress(work, previousPocket, 1, ITEMMENU_ReturnToBagMainAlias);
        return;
    }
    if (KEY_GetRepeat() & 0x20) {
        previousPocket = work->currentPocket;
        work->currentPocket = previousPocket - 1;
        if (work->currentPocket < 0)
            work->currentPocket = 4;
        UI_SetInputMode(0);
        ITEMMENU_StartPocketTabPress(work, previousPocket, 0, ITEMMENU_ReturnToBagMainAlias);
    }
}

void ITEMMENU_TaskActionMenuInput(ItemMenuWork *work)
{
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)work->menuList) == 0)
        return;
    if (APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)work->menuList) == 0) {
        ITEMMENU_ClearMessageWindow(work);
        work->nextState = 6;
        ITEMMENU_SetTask(work, 0);
    } else {
        ITEMMENU_ClearMessageWindow(work);
        BG_SYS_ClearSlot(3);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
        ITEMMENU_UpdateSideButtons(work, 1);
        if (UI_GetInputMode() == 1) {
            ITEMMENU_HideMoveInfo(work);
            ITEMMENU_SetCursorActive(work, 0);
        } else {
            ITEMMENU_SetCursorActive(work, 1);
        }
        ITEMMENU_ReturnToBagMain(work);
    }
    ITEMMENU_CloseYesNoList(work);
}

void ITEMMENU_TaskOpenActionMenu(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) { ITEMMENU_OpenYesNoList(work); ITEMMENU_SetTask(work,ITEMMENU_TaskActionMenuInput); } }

void ITEMMENU_TaskRegisterResultMessage(ItemMenuWork *work)
{
    if (GFL_USE_IsAnySeBusy() == 1)
        return;
    if ((KEY_GetTrg() & 3) == 0 && TOUCHPANEL_GetTrg() == 0)
        return;
    MSGDATA_ReadString(work->msgBank, 0x3E, work->tempString);
    WORDSET_SetSlotFromMsgCB(work->wordSet, 0, FILE_UTIL_GetMachineMove(work->selectedItemId));
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessage(work, 1);
    ITEMMENU_SetTask(work, ITEMMENU_TaskOpenActionMenu);
}

void ITEMMENU_TaskStartRegisterResult(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) { GFL_USE_PlaySeDefaultVolume(0x55C); ITEMMENU_SetTask(work,ITEMMENU_TaskRegisterResultMessage); } }

void ITEMMENU_TaskUseNoticeMessage(ItemMenuWork *work)
{
    if (FILE_UTIL_GetMachineIndex(work->selectedItemId) == 0xFF)
        MSGDATA_ReadString(work->msgBank, 0x3C, work->messageString);
    else
        MSGDATA_ReadString(work->msgBank, 0x3D, work->messageString);
    ITEMMENU_ShowMessage(work, 1);
    ITEMMENU_SetTask(work, ITEMMENU_TaskStartRegisterResult);
}

void ITEMMENU_TaskReturnToListAfterMessage(ItemMenuWork *work)
{
    if ((KEY_GetTrg() & 3) || TOUCHPANEL_GetTrg() != 0) {
        BG_SYS_ClearSlot(3);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        work->listDirty = 1;
        ITEMMENU_MoveCursorToRow(work);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
        ITEMMENU_UpdateSideButtons(work, 1);
        ITEMMENU_ReturnToBagMain(work);
    }
}

void ITEMMENU_TaskBeginReturnToList(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) ITEMMENU_SetTask(work,ITEMMENU_TaskReturnToListAfterMessage); }

void ITEMMENU_TaskTossConfirmInput(ItemMenuWork *work)
{
    int choice;
    int cursorActive;

    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)work->menuList) == 0)
        return;
    choice = APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)work->menuList);
    ITEMMENU_CloseYesNoList(work);
    BG_SYS_ClearSlot(3);
    if (choice == 0) {
        GFL_USE_PlaySeDefaultVolume(0x647);
        ITEMMENU_RemoveSelectedItems(work, work->listCount);
        MSGDATA_ReadString(work->msgBank, 0x36, work->tempString);
        ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, work->listCount > 1, 0);
        WORDSET_SetSlotNumber(work->wordSet, 1, work->listCount, 3, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_SetTask(work, ITEMMENU_TaskBeginReturnToList);
    } else {
        CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
        cursorActive = 1;
        ITEMMENU_UpdateSideButtons(work, 1);
        if (UI_GetInputMode() != 0)
            cursorActive = 0;
        ITEMMENU_SetCursorActive(work, cursorActive);
        ITEMMENU_ReturnToBagMain(work);
    }
}

void ITEMMENU_TaskOpenTossConfirm(ItemMenuWork *work) { if (ITEMMENU_IsMessageFinished(work)) { ITEMMENU_OpenYesNoList(work); ITEMMENU_SetTask(work,ITEMMENU_TaskTossConfirmInput); } }

void ITEMMENU_TaskTossAskQuantity(ItemMenuWork *work)
{
    work->listCount = 1;
    ITEMMENU_ShowQuantityWindows(work, 1);
    MSGDATA_ReadString(work->msgBank, 0x35, work->tempString);
    ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, 1, 0);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessageDefault(work);
    ITEMMENU_SetTask(work, ITEMMENU_TaskTossQuantityInput);
}

void ITEMMENU_TaskTossQuantityInput(ItemMenuWork *work)
{
    int choice;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (ITEMMENU_HandleQuantityInput(work) == 1)
        return;
    choice = ITEMMENU_GetYesNoTouchChoice();
    if (choice == -1) {
        if (KEY_GetTrg() & 1) {
            choice = 0;
            UI_SetInputMode(0);
        } else if (KEY_GetTrg() & 2) {
            UI_SetInputMode(0);
            choice = 1;
        }
    }
    if (choice == 0) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        ITEMMENU_HideQuantityWindows(work);
        MSGDATA_ReadString(work->msgBank, 0x37, work->tempString);
        ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, work->listCount > 1, 0);
        WORDSET_SetSlotNumber(work->wordSet, 1, work->listCount, 3, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_SetTask(work, ITEMMENU_TaskOpenTossConfirm);
        return;
    }
    if (choice == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskReopenListFromQuantity);
    }
}

void ITEMMENU_TaskGiveItem(ItemMenuWork *work)
{
    unsigned int canHold;
    unsigned int isKeyItem;

    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 0);
    canHold = FILE_UTIL_GetItemParam(work->selectedItemId, 0, work->heapId);
    isKeyItem = FILE_UTIL_GetItemParam(work->selectedItemId, 3, work->heapId);
    if (canHold == 0 || isKeyItem != 0) {
        ITEMMENU_UpdateSideButtons(work, 0);
        MSGDATA_ReadString(work->msgBank, 0x4D, work->tempString);
        ITEMMENU_RegisterItemName(work, 0, work->selectedItemId);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_SetBackButtonAnim(work, 0);
        ITEMMENU_SetTask(work, ITEMMENU_TaskWaitMessageDismiss);
        return;
    }
    work->listCount = 1;
    ITEMMENU_EnterQuantityMode(work);
    ITEMMENU_UpdateSideButtons(work, 0);
    if (ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work))->quantity == 1) {
        ITEMMENU_SetTask(work, ITEMMENU_TaskSellAskConfirm);
        return;
    }
    ITEMMENU_ShowQuantityWindows(work, 2);
    MSGDATA_ReadString(work->msgBank, 0x4E, work->tempString);
    ITEMMENU_RegisterItemName(work, 0, work->selectedItemId);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessageDefault(work);
    ITEMMENU_SetTask(work, ITEMMENU_TaskSellQuantityInput);
}

void ITEMMENU_TaskSellQuantityInput(ItemMenuWork *work)
{
    int choice;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (ITEMMENU_HandleQuantityInput(work) == 1)
        return;
    choice = ITEMMENU_GetYesNoTouchChoice();
    if (choice == -1) {
        if (KEY_GetTrg() & 1) {
            choice = 0;
            UI_SetInputMode(0);
        } else if (KEY_GetTrg() & 2) {
            UI_SetInputMode(0);
            choice = 1;
        }
    }
    if (choice == 0) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        ITEMMENU_HideQuantityWindows(work);
        ITEMMENU_SetTask(work, ITEMMENU_TaskSellAskConfirm);
        return;
    }
    if (choice == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        ITEMMENU_StartSideButtonPress(work, 4, ITEMMENU_TaskReturnFromQuantity);
    }
}

void ITEMMENU_TaskSellAskConfirm(ItemMenuWork *work)
{
    int sellTotal;

    ITEMMENU_OpenYesNoList(work);
    sellTotal = ITEMMENU_GetSellTotal(work->selectedItemId, work->listCount, work->heapId);
    MSGDATA_ReadString(work->msgBank, 0x4F, work->tempString);
    WORDSET_SetSlotNumber(work->wordSet, 0, sellTotal, 7, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_ShowMessageDefault(work);
    ITEMMENU_SetTask(work, ITEMMENU_TaskSellConfirmInput);
}

void ITEMMENU_TaskSellConfirmInput(ItemMenuWork *work)
{
    int choice;
    int sellTotal;

    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (APP_TASKMENU_IsFinish((struct TaskMenuWork *)work->menuList) == 0)
        return;
    choice = APP_TASKMENU_GetCursorPos((struct TaskMenuWork *)work->menuList);
    ITEMMENU_CloseYesNoList(work);
    switch (choice) {
    case 0:
        sellTotal = ITEMMENU_GetSellTotal(work->selectedItemId, work->listCount, work->heapId);
        ITEMMENU_RemoveSelectedItems(work, work->listCount);
        MISC_AddMoney(GAME_DATA_GetMiscSave(work->saveData), sellTotal);
        GFL_USE_PlaySeDefaultVolume(0x655);
        ITEMMENU_PrintMoney(work);
        MSGDATA_ReadString(work->msgBank, 0x50, work->tempString);
        ITEMMENU_RegisterItemNameCounted(work, 0, work->selectedItemId, work->listCount > 1, 0);
        WORDSET_SetSlotNumber(work->wordSet, 1, sellTotal, 7, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_ShowMessageDefault(work);
        ITEMMENU_SetTask(work, ITEMMENU_TaskWaitMessageDismiss);
        break;
    case 1:
        ITEMMENU_SetCursorActive(work, UI_GetInputMode() == 0);
        ITEMMENU_SetTask(work, ITEMMENU_TaskReturnToListFromQuantity);
        break;
    }
}

void ITEMMENU_TaskWaitMessageDismiss(ItemMenuWork *work)
{
    if (ITEMMENU_IsMessageFinished(work) == 0)
        return;
    if (KEY_GetTrg() & 3) {
        ITEMMENU_SetCursorActive(work, 1);
        ITEMMENU_SetTask(work, ITEMMENU_TaskReturnToListFromQuantity);
        return;
    }
    if (TOUCHPANEL_GetTrg() != 0) {
        ITEMMENU_SetCursorActive(work, 0);
        ITEMMENU_SetTask(work, ITEMMENU_TaskReturnToListFromQuantity);
    }
}

void ITEMMENU_TaskReturnToListFromQuantity(ItemMenuWork *work)
{
    BG_SYS_ClearSlot(3);
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    work->listDirty = 1;
    ITEMMENU_MoveCursorToRow(work);
    ITEMMENU_LeaveQuantityMode(work);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}

void ITEMMENU_RemoveSelectedItems(ItemMenuWork *work, int removeCount)
{
    int newPosition;

    ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    MYITEM_SAVEDATA_RemoveItem(work->bag, work->selectedItemId, removeCount, work->heapId);
    if (MYITEM_SAVEDATA_GetItemQuantity(work->bag, work->selectedItemId, work->heapId) != 0)
        return;
    if (ITEMMENU_GetItemCount(work) + 1 < 7) {
        newPosition = work->cursorRow - 1;
        if (newPosition <= 0)
            newPosition = 0;
        work->cursorRow = newPosition;
    } else {
        newPosition = work->scrollOffset - 1;
        if (newPosition < -1)
            newPosition = -1;
        work->scrollOffset = newPosition;
    }
}

void ITEMMENU_ShowQuantityWindows(ItemMenuWork *work, int v) { work->listMode=v; ITEMMENU_LoadSellPalette(work); ITEMMENU_PrintQuantityPrice(work,work->listCount); CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[5], 1); CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[6], 1); }

void ITEMMENU_HideQuantityWindows(ItemMenuWork *work) { BG_SYS_ClearSlot(3); CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[5], 0); CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[6], 0); }

/*
 * Quantity selector input: touch buttons (hit table sQuantityTouchRects, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 */
int ITEMMENU_HandleQuantityInput(ItemMenuWork *work)
{
    ItemmenuTouchHitTable touchTable;
    BagSlot *slot;
    int previousCount;
    int touchedButton;
    int changed;
    int direction;

    changed = 0;
    previousCount = work->listCount;
    slot = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    touchTable = sQuantityTouchRects;
    touchedButton = TOUCHPANEL_HitCont((union TouchHitTable *)(&touchTable));
    if (touchedButton != -1) {
        work->repeatCount++;
        changed = 1;
    } else {
        work->repeatCount = 0;
    }
    if (work->repeatCount == 1 || work->repeatCount > 30) {
        switch (touchedButton) {
        case 0:
            if (work->repeatCount > 120)
                work->listCount += 10;
            else
                work->listCount += 1;
            direction = 0;
            break;
        case 1:
            if (work->repeatCount > 120)
                work->listCount -= 10;
            else
                work->listCount -= 1;
            direction = 1;
            break;
        }
    }
    if (touchedButton == -1) {
        if (KEY_GetRepeat() & 0x40) {
            work->listCount += 1;
            direction = 0;
            changed = 1;
        } else if (KEY_GetRepeat() & 0x80) {
            work->listCount -= 1;
            direction = 1;
            changed = 1;
        } else if (KEY_GetRepeat() & 0x10) {
            work->listCount += 10;
            direction = 0;
            changed = 1;
        } else if (KEY_GetRepeat() & 0x20) {
            work->listCount -= 10;
            direction = 1;
            changed = 1;
        }
    }
    if (slot->quantity < work->listCount)
        work->listCount = 1;
    else if (work->listCount < 1)
        work->listCount = slot->quantity;
    if (work->listCount != previousCount) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (direction == 0)
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[5], 0xB);
        else
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[6], 0xA);
        ITEMMENU_PrintQuantityPrice(work, work->listCount);
    }
    return changed;
}

int ITEMMENU_CompareSortEntries(SortEntry *left, SortEntry *right)
{
    if (left->key == right->key)
        return 0;
    if (left->key > right->key)
        return 1;
    return -1;
}

void ITEMMENU_SortPocket(ItemMenuWork *work)
{
    int i;
    SortEntry *ents;
    BagSlot *items;
    int itemCount;
    struct ArcFile *itemArchive;
    struct ItemRecord *itemData;
    u32 iconKind;
    SortEntry *entry;

    ents = GFL_HEAP_Alloc(work->heapId, 0x9B0, 0, sHeapSiteName, 0xB35);
    items = GFL_HEAP_Alloc(work->heapId, 0x4D8, 0, sHeapSiteName, 0xB36);
    MYITEM_SAVEDATA_CopyPocket(work->bag, items, work->currentPocket, 1);
    itemCount = ITEMMENU_GetItemCount(work);
    itemArchive = FILE_UTIL_CreateItemArcHandle(work->heapId);
    for (i = 0; i < itemCount; i++) {
        itemData = FILE_UTIL_LoadArcMember(itemArchive, items[i].itemId, work->heapId);
        entry = &ents[i];
        iconKind = FILE_UTIL_GetItemRecordParam(itemData, 0xF);
        entry->key = (iconKind << 28) + (FILE_UTIL_GetItemRecordParam(itemData, 0x11) << 16) + items[i].itemId;
        entry->item = items[i];
        GFL_HEAP_Free(itemData);
    }
    ARC_TOOL_DeleteHandle(itemArchive);
    MATH_QSort(ents, itemCount, 8, ITEMMENU_CompareSortEntries, 0);
    for (i = 0; i < itemCount; i++) {
        items[i] = ents[i].item;
    }
    MYITEM_SAVEDATA_CopyPocket(work->bag, items, work->currentPocket, 0);
    GFL_HEAP_Free(items);
    GFL_HEAP_Free(ents);
}

void ITEMMENU_ShowInputGuardError(ItemMenuWork *work) { GFL_USE_PlaySeDefaultVolume(0x663); CLACT_SetActorAnimSeq((struct ClactActor *)(((work->inputGuard))), 2); }

void ITEMMENU_SortAndRedraw(ItemMenuWork *work) { ITEMMENU_SortPocket(work); work->shownItemId=0xFFFF; ITEMMENU_RedrawList(work); }

void ITEMMENU_RefreshInputGuard(ItemMenuWork *work)
{
    ITEMMENU_UpdateInputGuardAnim(work);
}

void ITEMMENU_SetCursorActive(ItemMenuWork *work, int flag)
{
    if (work->usingWorkCopy == 1)
        flag = 1;
    if (flag)
        UI_SetInputMode(0);
    else
        UI_SetInputMode(1);
    if (ITEMMENU_GetItemCount(work) == 0)
        flag = 0;
    if (flag == 0) {
        ITEMMENU_UpdateSlotActorPosition(work, 0);
    } else {
        ITEMMENU_UpdateSlotActorPosition(work, 1);
        BLINK_PALANM_ResetPhase(work->blinkPalAnm);
    }
    ITEMMENU_SetMoveTypeIconsVisible(work, flag);
}

int ITEMMENU_IsBrowseMode(ItemMenuWork *work) { int v = work->bagMode; if (v==0 || v==1 || v==3) return 1; return 0; }

int ITEMMENU_ToggleRegisteredItem(ItemMenuWork *work, int row)
{
    u16 *itemIdPtr;
    int registerSlot;

    row += work->scrollOffset + 1;
    if (work->currentPocket == 4) {
        if (ITEMMENU_GetItemCount(work) <= row)
            return 0;
        itemIdPtr = (void *)ITEMMENU_GetSlot(work, row);
        registerSlot = ITEM_GetRegisterFlagId(*itemIdPtr);
        if (registerSlot == 0x19)
            return 0;
        if (ITEMMENU_IsItemRegistered(work, *itemIdPtr) == 1)
            GAME_DATA_SetRecentId(work->saveData, registerSlot, 0);
        else
            GAME_DATA_SetRecentId(work->saveData, registerSlot, 1);
        GFL_USE_PlaySeDefaultVolume(0x646);
        work->shownItemId = 0xFFFF;
        return 1;
    }
    return 0;
}

int ITEMMENU_GetPocketSortFlag(int pocket)
{
    int ITEMMENU_PocketToSortFlag(int);
    return ITEMMENU_PocketToSortFlag(pocket);
}

void ITEMMENU_TogglePocketSortFlag(ItemMenuWork *work) { int a; int v; a=ITEMMENU_GetPocketSortFlag(work->currentPocket); v=GAME_DATA_ContainsRecentId(work->saveData,a); GAME_DATA_SetRecentId(work->saveData,a,v^1); GFL_USE_PlaySeDefaultVolume(0x646); ITEMMENU_UpdatePocketSortIcon(work); }

void ITEMMENU_UpdatePocketSortIcon(ItemMenuWork *work) { if (work->usingWorkCopy!=1) CLACT_SetActorAnimSeq((struct ClactActor *)(((work->sideActor[2]))), (unsigned int)GAME_DATA_ContainsRecentId(work->saveData,ITEMMENU_GetPocketSortFlag(work->currentPocket))+6u); }

void ITEMMENU_CheckItemFilter(ItemMenuWork *work, void *itemData, u16 *itemIdPtr, u8 *filterKind)
{
    if (FILE_UTIL_GetItemRecordParam(itemData, 6) != 0) {
        if (FILE_UTIL_IsMailItem(*itemIdPtr) == 1)
            *filterKind = 2;
        else if (*itemIdPtr == 0x1C2 && work->bagFilter == 1)
            *filterKind = 1;
        else
            *filterKind = 0;
    }
    if ((u16)(*itemIdPtr + 0xFD98) <= 1)
        *filterKind = 0;
}

void ITEMMENU_BuildActionList(ItemMenuWork *work, unsigned char *actions)
{
    unsigned short *itemIdPtr = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    if (itemIdPtr != 0 && *itemIdPtr != 0) {
        void *itemData = FILE_UTIL_LoadItemRecord(*itemIdPtr, 0, work->heapId);
        unsigned char pocket = work->currentPocket;
        ITEMMENU_CheckItemFilter(work, itemData, itemIdPtr, actions);
        if (ITEMMENU_IsCheckModeAllowed(work, pocket) == 0 && actions[0] != 2) {
            actions[0] = 0xFF;
        }
        if (FILE_UTIL_GetItemRecordParam(itemData, 3) == 0) {
            if (PALANM_IsOutsideReservedIdRange(*itemIdPtr) == 1) {
                actions[1] = 6;
            }
            if (pocket != 2) {
                actions[2] = 3;
            }
        }
        if (FILE_UTIL_GetItemRecordParam(itemData, 4) != 0) {
            if (ITEMMENU_IsItemRegistered(work, *itemIdPtr) == 1) {
                actions[2] = 5;
            } else {
                actions[2] = 4;
            }
        }
        actions[3] = 8;
        GFL_HEAP_Free(itemData);
    }
}

/*
 * lever: ITEMMENU_OpenPopupList reads the count in r2; passing j keeps it in r2.
 */
void ITEMMENU_OpenActionMenu(ItemMenuWork *work)
{
    ActionMsgIds msgIdTable = sActionMsgIds;
    ActionIds actionIds = sDefaultActionIds;
    int msgIds[4];
    int j;
    int i;
    ITEMMENU_BuildActionList(work, (unsigned char *)(&actionIds));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int actionId = actionIds.ids[i];
        if (actionId != 0xFF) {
            work->menuActionTable[j] = actionId;
            msgIds[j] = msgIdTable.msgIds[actionIds.ids[i]];
            j++;
        }
    }
    ITEMMENU_OpenPopupList(work, msgIds, j);
}

int ITEMMENU_IsItemRegistered(ItemMenuWork *work, int value)
{
    return GAME_DATA_ContainsRecentId(work->saveData, (int)ITEM_GetRegisterFlagId((u16)value));
}

/*
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table sTabPockets, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of ITEMMENU_TaskBagMain's key handling.
 */
void ITEMMENU_HandleTouchTarget(u32 idx, s32 flag, void *arg)
{
    ItemMenuWork *work = arg;
    int tab;
    int count;
    int previousPocket;
    int savedRow;
    int cursorIndex;
    PocketTable pocketTable;

    tab = -1;
    count = ITEMMENU_GetItemCount(work);
    if (flag != 0)
        return;
    if (idx < 5) {
        pocketTable = sTabPockets;
        if (work->currentPocket != pocketTable.pockets[idx]) {
            tab = pocketTable.pockets[idx];
            ITEMMENU_SetCursorActive(work, 0);
        }
    } else if (idx == 5) {
        ITEMMENU_SetCursorActive(work, 0);
        previousPocket = work->currentPocket;
        work->currentPocket = previousPocket - 1;
        if (work->currentPocket < 0)
            work->currentPocket = 4;
        ITEMMENU_StartPocketTabPress(work, previousPocket, 0, ITEMMENU_ReturnToBagMainAlias);
        return;
    } else if (idx == 6) {
        ITEMMENU_SetCursorActive(work, 0);
        previousPocket = work->currentPocket;
        work->currentPocket = previousPocket + 1;
        if (work->currentPocket >= 5)
            work->currentPocket = 0;
        ITEMMENU_StartPocketTabPress(work, previousPocket, 1, ITEMMENU_ReturnToBagMainAlias);
        return;
    } else if (idx == 7) {
        if (work->currentPocket != 2 && work->currentPocket != 3 && ITEMMENU_GetItemCount(work) > 1) {
            ITEMMENU_ShowInputGuardError(work);
            ITEMMENU_SetCursorActive(work, 0);
            work->shownItemId = 0xFFFF;
            ITEMMENU_RedrawList(work);
            ITEMMENU_SetTask(work, ITEMMENU_TaskInputGuardMessage);
        }
    } else if (idx == 8) {
        if (ITEMMENU_IsBrowseMode(work) == 1) {
            ITEMMENU_TogglePocketSortFlag(work);
            ITEMMENU_SetCursorActive(work, 0);
            work->shownItemId = 0xFFFF;
            ITEMMENU_RedrawList(work);
        }
    } else if (idx == 9) {
        if (work->bagMode != 2) {
            work->nextState = 0;
            work->selectedItemId = 0;
            ITEMMENU_StartSideButtonPress(work, 3, 0);
            UI_SetInputMode(1);
        }
    } else if (idx == 10) {
        work->nextState = 1;
        work->selectedItemId = 0;
        ITEMMENU_StartSideButtonPress(work, 4, 0);
        UI_SetInputMode(1);
    } else if (idx >= 11 && idx < 17) {
        if (work->taskFn != ITEMMENU_TaskBagMain)
            return;
        savedRow = work->cursorRow;
        cursorIndex = ITEMMENU_GetCursorIndex(work);
        if (ITEMMENU_GetItemCount(work) == 0)
            return;
        if (work->cursorRow != idx - 11) {
            work->cursorRow = idx - 11;
            if (count <= ITEMMENU_GetCursorIndex(work)) {
                work->cursorRow = savedRow;
                return;
            }
        }
        ITEMMENU_MoveSlot(work, cursorIndex, ITEMMENU_GetCursorIndex(work));
        ITEMMENU_SetCursorActive(work, 0);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
        ITEMMENU_DrawMoveInfo(work);
        ITEMMENU_SetTask(work, ITEMMENU_TaskSelectItemFlash);
        return;
    } else if (idx >= 17) {
        if (ITEMMENU_IsBrowseMode(work) == 1 && ITEMMENU_ToggleRegisteredItem(work, idx - 17) == 1) {
            ITEMMENU_SetCursorActive(work, 0);
            ITEMMENU_RedrawList(work);
        }
    }
    if (tab != -1) {
        previousPocket = work->currentPocket;
        work->currentPocket = tab;
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        ITEMMENU_SwitchPocketCursor(work, previousPocket, work->currentPocket);
        ITEMMENU_RefreshInputGuard(work);
        ITEMMENU_SetCursorActive(work, 0);
        work->shownItemId = 0xFFFF;
        ITEMMENU_RedrawList(work);
    }
}

void ITEMMENU_VBlankCallback(struct TcbTask *unusedArg, void *arg)
{
    ItemMenuWork *work = arg;
    int state = work->screenState;
    if (state == 1) {
        ITEMMENU_SetLayersVisible(work, 1);
        work->screenState = 0;
    } else if (state == 2) {
        ITEMMENU_SetLayersVisible(work, 0);
        work->screenState = 0;
    }
    PALANM_TransferPalettes(work->palAnmSlot);
    CLACT_VBlankSystem();
}

void ITEMMENU_TaskStartFadeIn(ItemMenuWork *work)
{
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printSys)) {
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, work->heapId);
        GFL_USE_PlaySeDefaultVolume(0x79F);
        ITEMMENU_SetTask(work, ITEMMENU_TaskWaitFadeIn);
    }
}

/*
 * blocked:
 */
void ITEMMENU_TaskWaitFadeIn(ItemMenuWork *work)
{
    int isWipeDone = WIPE_SYS_EndCheck();
    int isActorMoving = ITEMMENU_MoveActorToPoint(work);
    if (isWipeDone == 1 && isActorMoving == 0) {
        CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
        ITEMMENU_ReturnToBagMain(work);
    }
}

int ITEMMENU_Init(void *proc, int subState, ItemMenuArgs *args)
{
    ItemMenuWork *work; u16 i; s16 scrollPos, cursorPos;
    GFL_HEAP_CreateChildHeap(1, 0xe, 0x34000);
    work = PROCSYS_AllocProcWork(proc, sizeof(ItemMenuWork), 0xe);
    MI_CpuFill8(work, 0, sizeof(ItemMenuWork));
    KEY_GetRepeatSpeed(&work->keyRepeatDelay, &work->keyRepeatInterval);
    work->heapId = 0xe;
    work->currentPage = 1;
    work->saveData = args->saveData; work->myStatus = args->myStatus; work->optionsSave = args->optionsSave;
    work->bagCursor = args->bagCursor; work->bag = args->bag;
    work->actionPermissions = args->actionPermissions;
    work->bagMode = args->bagMode; work->bagFilter = args->bagFilter;
#ifdef __MWERKS__
    MYITEM_SAVEDATA_CompactAllPockets(work->bag, work->bagFilter);
#else
    MYITEM_SAVEDATA_CompactAllPockets(work->bag);
#endif
    work->currentPocket = MYITEM_SAVEDATA_GetLastFieldPocket(work->bagCursor);
    for (i = 0; i < 5; i++) {
        int itemCount;
        MYITEM_SAVEDATA_GetFieldPocketCursor(work->bagCursor, i, &scrollPos, &cursorPos);
        itemCount = (u16)MYITEM_SAVEDATA_CountUsedSlotsInPocket(work->bag, i);
        for (;;) {
            if (scrollPos == 0 && cursorPos == 0) break;
            if (cursorPos + 5 >= itemCount && cursorPos != 0) { cursorPos--; continue; }
            if (scrollPos + cursorPos < itemCount) break;
            if (cursorPos != 0) cursorPos--; else scrollPos--;
        }
        if (i == work->currentPocket) { work->cursorRow = scrollPos; work->scrollOffset = cursorPos - 1; }
        MYITEM_SAVEDATA_SetFieldPocketCursor(work->bagCursor, i, scrollPos, cursorPos);
    }
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 3, work->heapId);
    work->tempString = STRBUF_Create(0xc8, work->heapId);
    work->messageString = STRBUF_Create(0xc8, work->heapId);
    work->listStrings = STRBUF_Create(0x40, work->heapId);
    work->wordSet = WORDSET_CreateDefault(work->heapId);
    work->printSys = (struct PrintSys *)PRINTSYS_QUE_CreateEx(0x40 << 6, work->heapId);
    work->itemDescWindow = APP_KEYCURSOR_CreateDefault(0xf, 1, 1, work->heapId);
    work->menuTaskArg = GF_FONT_Create(0x17, 0, 0, 0, work->heapId);
    ITEMMENU_SetupGraphics(work);
    ITEMMENU_InitWindows(work);
    ITEMMENU_LoadPocketGraphics(work);
    ITEMMENU_CreateTabActors(work);
    ITEMMENU_ForceRedrawList(work);
    ITEMMENU_CreateCursorActors(work);
    work->taskSys = BUTTON_MAN_Create((u8 *)sButtonHitTable, ITEMMENU_HandleTouchTarget, work, work->heapId);
    ITEMMENU_CreateBlinkPalAnm(work);
    ITEMMENU_AllocPalAnmSlots(work);
    work->unitList = GFL_USE_AddMainTask(ITEMMENU_VBlankCallback, work, 0);
    work->touchTask = (struct Tcbl *)TCBL_Create(work->heapId, work->heapId, 1, 0);
    ITEMMENU_PrintPocketName(work);
    work->taskMenuState = APP_TASKMENU_RES_Create(3, 9, (struct GFont *)work->menuTaskArg, (struct PrintQueue *)work->printSys, work->heapId);
    GFL_NET_RefreshWmIconAtTopRight(1, work->heapId);
    ITEMMENU_SetCursorActive(work, UI_GetInputMode() ? 0 : 1);
    ITEMMENU_ResetDisplayLayers();
    ITEMMENU_SetTask(work, ITEMMENU_TaskStartFadeIn);
    return 1;
}

int ITEMMENU_Main(int procArg, int subState, int unusedArg, ItemMenuWork *work)
{
    ItemMenuTaskFn currentTask = work->taskFn;
    if (currentTask == 0) {
        WIPE_SYS_Start(0, 0, 0, 0, 6, 1, work->heapId);
        return 1;
    }
    work->shownItemId = work->scrollOffset;
    currentTask(work);
    if (work->listDirty != 0) {
        ITEMMENU_SnapSelectorToCursor(work);
        work->listDirty = 0;
    }
    if (work->busyCount != 0) {
        ITEMMENU_UploadSlotGraphics(work);
        work->busyCount = 0;
    }
    ITEMMENU_FreeActionMenuResources(work);
    ITEMMENU_FlushDirtyWindows(work);
    TCBL_Main((struct TcblSystem *)work->touchTask);
    return 0;
}

int ITEMMENU_Exit(void *proc, int subState, ItemMenuResult *parentArgs, ItemMenuWork *work)
{
    if (WIPE_SYS_EndCheck() != 1)
        return 0;
    if (PRINTSYS_QUE_IsFinished((struct PrintQueue *)work->printSys) == 0)
        return 0;
    TCB_DeleteTask(work->unitList);
    MYITEM_SAVEDATA_SetLastFieldPocket(work->bagCursor, work->currentPocket);
    MYITEM_SAVEDATA_SetFieldPocketCursor(work->bagCursor, (u16)work->currentPocket, work->cursorRow, work->scrollOffset + 1);
    APP_TASKMENU_RES_Delete(work->taskMenuState);
    ITEMMENU_FreeGraphics(work);
    ITEMMENU_ApplyBgPalettes(work);
    TCBL_Destroy((struct TcblSystem *)work->touchTask);
    MSGDATA_Delete(work->msgBank);
    STRBUF_Delete(work->tempString);
    STRBUF_Delete(work->messageString);
    STRBUF_Delete(work->listStrings);
    WORDSET_Delete(work->wordSet);
    ITEMMENU_HideSideWindows(work);
    if (work->messageWindows[0].window != 0) {
        BG_SYS_FreeTileRun(3, (unsigned short)work->keyRepeatPacked, (unsigned short)(work->keyRepeatPacked >> 16));
        BMP_WIN_Delete(work->messageWindows[0].window);
    }
    BG_SYS_FreeTiles(3, 1, 0);
    GF_FONT_Delete((void *)work->menuTaskArg);
    APP_KEYCURSOR_Delete(work->itemDescWindow);
    PRINTSYS_QUE_Clear((struct PrintQueue *)work->printSys);
    PRINTSYS_QUE_Delete((struct PrintQueue *)work->printSys);
    ITEMMENU_FreePalAnmSlots(work);
    ITEMMENU_DeleteBlinkPalAnm(work);
    BUTTON_MAN_Delete(work->taskSys);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    parentArgs->nextState = work->nextState;
    parentArgs->selectedItemId = work->selectedItemId;
    KEY_SetRepeatSpeed(work->keyRepeatDelay, work->keyRepeatInterval);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0xE);
    return 1;
}

void ITEMMENU_ReturnToBagMain(ItemMenuWork *work)
{
    ITEMMENU_SetTask(work, ITEMMENU_TaskBagMain);
    KEY_SetRepeatSpeed(3, 6);
}

void ITEMMENU_ReturnToListInput(ItemMenuWork *work)
{
    ITEMMENU_SetTask(work, ITEMMENU_TaskListInput);
    KEY_SetRepeatSpeed(3, 6);
}

void ITEMMENU_CreateBlinkPalAnm(ItemMenuWork *work)
{
    void *archive;
    *(struct BlinkPalAnm * *)&work->blinkPalAnm =
        BLINK_PALANM_Create(0x10, 0x10, 0xFFFE, work->heapId);
    archive = ARC_TOOL_CreateHandle(0x58, work->heapId);
    BLINK_PALANM_LoadPalettes(*(struct BlinkPalAnm * *)&work->blinkPalAnm, archive, 0x15, 0x10, 0x20);
    ARC_TOOL_DeleteHandle(archive);
}

void ITEMMENU_DeleteBlinkPalAnm(ItemMenuWork *work)
{
    BLINK_PALANM_Delete(*(struct BlinkPalAnm * *)&work->blinkPalAnm);
}

void ITEMMENU_TaskSelectItemFlash(ItemMenuWork *work)
{
    switch (work->fadeStep) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54C);
    case 3:
        ITEMMENU_UpdateSlotActorPosition(work, 0);
        work->fadeStep += 1;
        return;
    case 1:
    case 4:
    case 6:
        work->fadeTimer += 1;
        if (work->fadeTimer == 4) {
            work->fadeTimer = 0;
            work->fadeStep += 1;
        }
        return;
    case 2:
    case 5:
        ITEMMENU_UpdateSlotActorPosition(work, 2);
        work->fadeStep += 1;
        return;
    case 7:
        work->fadeStep = 0;
        ITEMMENU_UpdateSlotActorPosition(work, 1);
        BLINK_PALANM_ResetPhase(work->blinkPalAnm);
        BLINK_PALANM_Update(work->blinkPalAnm);
        ITEMMENU_SetTask(work, ITEMMENU_TaskSelectItem);
        return;
    }
}

void ITEMMENU_StartSideButtonPress(ItemMenuWork *work, int button, ItemMenuTaskFn callback)
{
    int animSeq;
    if (button == 4) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        animSeq = 9;
    } else if (button == 3) {
        GFL_USE_PlaySeDefaultVolume(0x556);
        animSeq = 8;
    } else if (button == 1) {
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        animSeq = 0xD;
    } else if (button == 0) {
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        animSeq = 0xC;
    }
    work->fadeStep = button;
    CLACT_SetActorAnimFrame((struct ClactActor *)work->sideActor[work->fadeStep], 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[work->fadeStep], (unsigned short)animSeq);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->sideActor[work->fadeStep], 1);
    work->fadeCallback = callback;
    ITEMMENU_SetTask(work, ITEMMENU_TaskWaitSideButtonPress);
}

void ITEMMENU_TaskWaitSideButtonPress(ItemMenuWork *work)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)work->sideActor[work->fadeStep]) == 0) {
        work->fadeStep = 0;
        ITEMMENU_SetTask(work, work->fadeCallback);
    }
}

void ITEMMENU_StartPocketTabPress(ItemMenuWork *work, int previousPocket, int isNextTab, ItemMenuTaskFn callback)
{
    int animSeq;
    ITEMMENU_SwitchPocketCursor(work, previousPocket, work->currentPocket);
    ITEMMENU_RefreshInputGuard(work);
    ITEMMENU_UpdatePocketSortIcon(work);
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    if (isNextTab == 1) {
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        animSeq = 0xD;
    } else if (isNextTab == 0) {
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        animSeq = 0xC;
    }
    work->fadeStep = isNextTab;
    work->fadeTimer = 6;
    CLACT_SetActorAnimFrame((struct ClactActor *)work->sideActor[work->fadeStep], 0);
    CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[work->fadeStep], (unsigned short)animSeq);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->sideActor[work->fadeStep], 1);
    work->fadeCallback = callback;
    ITEMMENU_SetTask(work, ITEMMENU_TaskWaitPocketTabPress);
}

void ITEMMENU_TaskWaitPocketTabPress(ItemMenuWork *work)
{
    if (work->fadeTimer == 0) {
        work->fadeStep = 0;
        ITEMMENU_SetTask(work, work->fadeCallback);
    } else {
        work->fadeTimer -= 1;
    }
}

/*
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 */
int ITEMMENU_GetYesNoTouchChoice(void)
{
    int result;
    result = TOUCHPANEL_HitTrg((union TouchHitTable *)sBackButtonHitRect);
    if (result != -1)
        UI_SetInputMode(1);
    return result;
}

void ITEMMENU_TaskReopenListFromQuantity(ItemMenuWork *work)
{
    int flag;
    ITEMMENU_HideQuantityWindows(work);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    flag = 1;
    if (UI_GetInputMode())
        flag = 0;
    ITEMMENU_SetCursorActive(work, flag);
    ITEMMENU_ReturnToBagMain(work);
}

void ITEMMENU_TaskReturnFromQuantity(ItemMenuWork *work)
{
    int cursorActive;
    ITEMMENU_HideQuantityWindows(work);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    cursorActive = 1;
    if (UI_GetInputMode()) {
        cursorActive = 0;
    }
    ITEMMENU_SetCursorActive(work, cursorActive);
    ITEMMENU_SetTask(work, ITEMMENU_TaskReturnToListFromQuantity);
}

void ITEMMENU_AllocPalAnmSlots(ItemMenuWork *work)
{
    work->palAnmSlot = PALANM_Create(work->heapId);
    PALANM_AllocSlotBuffers(work->palAnmSlot, 2, 0x200, work->heapId);
    PALANM_AllocSlotBuffers(work->palAnmSlot, 0, 0x20, work->heapId);
    PALANM_CopyHwPaletteToSlot(work->palAnmSlot, 0, 0, 0x20);
}

/*
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 */
void ITEMMENU_FreePalAnmSlots(ItemMenuWork *work)
{
    PALANM_FreeSlotBuffers(work->palAnmSlot, 0);
    PALANM_FreeSlotBuffers(work->palAnmSlot, 2);
    PALANM_Delete(work->palAnmSlot);
}

void ITEMMENU_TaskInputGuardMessage(ItemMenuWork *work)
{
    if (CLACT_IsActorAnimActive((struct ClactActor *)work->inputGuard) == 0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)work->inputGuard, 0);
        ITEMMENU_SortAndRedraw(work);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 0);
        MSGDATA_ReadString(work->msgBank, 0x8A, work->messageString);
        ITEMMENU_ShowMessage(work, 0);
        ITEMMENU_SetBackButtonAnim(work, 0);
        ITEMMENU_UpdateSideButtons(work, 0);
        ITEMMENU_SetTask(work, ITEMMENU_TaskWaitMessageThenList);
    }
}

void ITEMMENU_TaskWaitMessageThenList(ItemMenuWork *work)
{
    if (KEY_GetTrg() & 3) {
        ITEMMENU_SetCursorActive(work, 1);
    } else if (TOUCHPANEL_GetTrg()) {
        ITEMMENU_SetCursorActive(work, 0);
    } else {
        return;
    }
    work->shownItemId = 0xFFFF;
    ITEMMENU_RedrawList(work);
    ITEMMENU_ClearMessageWindow(work);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
    ITEMMENU_UpdateSideButtons(work, 1);
    ITEMMENU_ReturnToBagMain(work);
}

int ITEMMENU_IsCheckModeAllowed(ItemMenuWork *work, int value)
{
    if (work->bagMode == 3 || work->bagMode == 1)
        return 0;
    if (GAME_DATA_GetIntrudeCount(work->saveData) == 1 && value == 4)
        return 0;
    return 1;
}

/*
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after ITEMMENU_IsCheckModeAllowed;
 * installed as a callback by ITEMMENU_TaskBagMain and at 0x021B85E0.
 */
void ITEMMENU_ReturnToBagMainAlias(ItemMenuWork *work)
{
    ITEMMENU_ReturnToBagMain(work);
}

static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                          (sel << REG_GX_POWCNT_DSEL_SHIFT));
}

/*
 * BG setup: GX_SetDispSelect(0), then seven 32-byte BG templates copied
 * to the stack and handed to BG_SYS_InitBgLayer for BGs 0-6, each followed by
 * its clear/enable calls.
 *
 * volatile: 0x04000304 (POWCNT1, read-modify-write at 0x021B8FA0/0x021B8FA8)
 */
void ITEMMENU_InitDisplayBanks(void)
{
    struct BgTemplate layer0Template;
    struct BgTemplate layer1Template;
    struct BgTemplate layer2Template;
    struct BgTemplate layer3Template;
    struct BgTemplate layer4Template;
    struct BgTemplate layer5Template;
    struct BgTemplate layer6Template;

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    layer0Template = sBgLayer0Template;
    BG_SYS_InitBgLayer(0, &layer0Template, 0);
    BG_SYS_FreeSlot(0);
    BG_SYS_PushTile(0);
    BG_SYS_SetPlaneVisible(0, 0);

    layer1Template = sBgLayer1Template;
    BG_SYS_InitBgLayer(1, &layer1Template, 0);
    BG_SYS_FreeSlot(1);
    BG_SYS_PushTile(1);
    BG_SYS_SetPlaneVisible(1, 0);

    layer2Template = sBgLayer2Template;
    BG_SYS_InitBgLayer(2, &layer2Template, 0);
    BG_SYS_FreeSlot(2);
    BG_SYS_PushTile(2);
    BG_SYS_SetPlaneVisible(2, 0);

    layer3Template = sBgLayer3Template;
    BG_SYS_InitBgLayer(3, &layer3Template, 0);
    BG_SYS_Init(3, 0, 1, 0);
    BG_SYS_FreeSlot(3);
    BG_SYS_PushTile(3);
    BG_SYS_SetPlaneVisible(3, 0);

    layer4Template = sBgLayer4Template;
    BG_SYS_InitBgLayer(4, &layer4Template, 0);
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_PushTile(4);

    layer5Template = sBgLayer5Template;
    BG_SYS_InitBgLayer(5, &layer5Template, 0);
    BG_SYS_SetPlaneVisible(5, 0);

    layer6Template = sBgLayer6Template;
    BG_SYS_InitBgLayer(6, &layer6Template, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    BG_SYS_Init(6, 0, 1, 0);
    BG_SYS_ClearSlot(6);
}

void ITEMMENU_ResetDisplayLayers(void)
{
    BG_SYS_SetPlaneVisible(0, 1);
    BG_SYS_SetPlaneVisible(1, 1);
    BG_SYS_SetPlaneVisible(2, 1);
    BG_SYS_SetPlaneVisible(3, 1);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_SetPlaneVisible(6, 1);
}

void ITEMMENU_LoadBagGraphics(ItemMenuWork *work, void *archive)
{
    int paletteFileId, charFileId, screenFileId, charBase;
    int gender = MYSTATUS_GetSex(work->myStatus);
    if (gender == 0) {
        paletteFileId = 4;
        charFileId = 3;
        screenFileId = 5;
    } else if (gender == 1) {
        paletteFileId = 1;
        charFileId = 0;
        screenFileId = 2;
    }
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, paletteFileId, 0, 0, 0x20, work->heapId);
    charBase = ARC_UTIL_RegisterObjCharFromHandle(archive, charFileId, 0, 0, 0, work->heapId);
    work->frameCounter = charBase;
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, screenFileId, 0, 0, (unsigned short)charBase, 0, 0, work->heapId);
}

void ITEMMENU_LoadTabGraphics(ItemMenuWork *work, void *archive)
{
    int paletteFileId, charFileId, cellFileId, animFileId;
    int gender = MYSTATUS_GetSex(work->myStatus);
    if (gender == 0) {
        paletteFileId = 0x10;
        charFileId = 0xf;
        cellFileId = 0xe;
        animFileId = 0xd;
    } else if (gender == 1) {
        paletteFileId = 0xc;
        charFileId = 0xb;
        cellFileId = 0xa;
        animFileId = 9;
    }
    work->tabCharRes = CLACT_RegisterPaletteEx(archive, paletteFileId, 0, 0xc0, 0, 4, work->heapId);
    work->tabPaletteRes = CLACT_RegisterCharacter(archive, charFileId, 0, 0, work->heapId);
    work->tabCellRes = CLACT_RegisterCellAnim((void *)archive, cellFileId, animFileId, work->heapId);
}

static inline void LoadIcons(ItemMenuWork *work)
{
    void *archive;
    u32 cellFileId;
    u32 i;

    archive = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), work->heapId);
    work->cursorCharRes2 = CLACT_RegisterPaletteEx(archive, APP_ICON_GetTouchBarFileId(), 1, 0x80, 0, 3, work->heapId);
    cellFileId = APP_ICON_GetTypePaletteFileId(2);
    work->cursorPaletteRes2 = CLACT_RegisterCellAnim(archive, cellFileId, APP_ICON_GetTypeAnimFileId(2), work->heapId);
    for (i = 0; i < 3; i++)
        work->slotCharRes[i] = CLACT_RegisterCharacter(archive, APP_ICON_GetMoveKindCellFileId((u8)i), 0, 1, work->heapId);
    for (i = 0; i < 17; i++)
        work->typeIconRes[i] = CLACT_RegisterCharacter(archive, APP_ICON_GetTypeCellFileId((u8)i), 0, 1, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
}

void ITEMMENU_SetupGraphics(ItemMenuWork *work)
{
    struct DispConfig dispConfig;
    ActorTemplate damageClassTemplate;
    ActorTemplate typeIconTemplate;
    ActorTemplate inputGuardTemplate;
    void *archive;
    u32 charBase;
    u32 i;

    *(volatile u16 *)REG_BLDCNT_ADDR = 0;
    BG_SYS_Create(work->heapId);
    BMP_WIN_Init(work->heapId);
    GF_FONT_InitTextColor();
    BG_SYS_SetVramBanks((struct DispVram *)sVramBankConfig);
    CLACT_InitSystem((struct ClactSysInit *)sClactSystemConfig, (struct DispVramCfg *)sVramBankConfig, work->heapId);
    dispConfig = sDispConfig;
    BG_SYS_SetGraphicsMode(&dispConfig);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    ITEMMENU_InitDisplayBanks();
    GF_FONT_SetDefaultTextColor();
    work->keyRepeatPacked = BMP_MENUWORK_LoadFrameGfx(3, 13, 0, work->heapId);
    archive = ARC_TOOL_CreateHandle(0x58, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 8, 4, 0, 0, work->heapId);
    if (MYSTATUS_GetSex(work->myStatus) == 0)
        ARC_UTIL_UploadPaletteFromHandle(archive, 8, 4, 0x20, 0, 0x20, work->heapId);
    charBase = ARC_UTIL_RegisterObjCharFromHandle(archive, 6, 4, 0, 0, work->heapId);
    work->bgPaletteA = charBase;
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 7, 4, 0, (u16)charBase, 0, 0, work->heapId);
    ITEMMENU_LoadBagGraphics(work, archive);
    charBase = ARC_UTIL_RegisterObjCharFromHandle(archive, 0x11, 5, 0, 0, work->heapId);
    work->bgPaletteB = charBase;
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 0x17, 5, 0, (u16)charBase, 0, 0, work->heapId);
    ITEMMENU_LoadTabGraphics(work, archive);
    work->bgPaletteD = ARC_UTIL_RegisterObjCharFromHandle(archive, 0x21, 3, 0, 0, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0x22, 0, 0x60, 0x20, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0x180, 0x20, work->heapId);
    work->clactSys = CLACT_CreateUnit(0x34, 0, work->heapId);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    archive = ARC_TOOL_CreateHandle(0x53, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive, 0x1B, 0, 0x100, 0x20, work->heapId);
    charBase = ARC_UTIL_RegisterObjCharFromHandle(archive, 0x1C, 1, 0, 0, work->heapId);
    work->bgPaletteC = charBase;
    ARC_UTIL_UploadBgPaletteAddFromHandle(archive, 0x1D, 1, 0, (u16)charBase + 0x8000, 0, 0, work->heapId);
    BG_SYS_PushTile(1);
    work->iconCharRes = CLACT_RegisterPaletteEx(archive, 0x13, 0, 0x140, 0, 3, work->heapId);
    work->iconPaletteRes = CLACT_RegisterCharacter(archive, 0x14, 0, 0, work->heapId);
    work->iconCellRes = CLACT_RegisterCellAnim(archive, 0x17, 0x1A, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    ITEMMENU_CreateSideButtonActors(work);
    LoadIcons(work);
    damageClassTemplate.x = 0x50;
    damageClassTemplate.y = 0xB8;
    damageClassTemplate.softPriority = 1;
    damageClassTemplate.bgPriority = 1;
    damageClassTemplate.animSeq = 0;
    for (i = 0; i < 3; i++) {
        work->damageClassActors[i] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->slotCharRes[i], work->cursorCharRes2, work->cursorPaletteRes2, (struct ActorInitParam *)(&damageClassTemplate), 1, work->heapId);
        CLACT_SetActorPaletteOffset((struct ClactActor *)work->damageClassActors[i], APP_ICON_GetMoveKindPaletteOffset((u8)i), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->damageClassActors[i], 0);
    }
    typeIconTemplate.x = 0x52;
    typeIconTemplate.y = 0xA5;
    typeIconTemplate.softPriority = 1;
    typeIconTemplate.bgPriority = 1;
    typeIconTemplate.animSeq = 0;
    for (i = 0; i < 17; i++) {
        work->typeActors[i] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->typeIconRes[i], work->cursorCharRes2, work->cursorPaletteRes2, (struct ActorInitParam *)(&typeIconTemplate), 1, work->heapId);
        CLACT_SetActorPaletteOffset((struct ClactActor *)work->typeActors[i], APP_ICON_GetTypePaletteOffset((u8)i), 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->typeActors[i], 0);
    }
    archive = ARC_TOOL_CreateHandle(0x58, work->heapId);
    work->cursorCharRes = CLACT_RegisterPaletteEx(archive, 0x27, 0, 0x80, 0, 2, work->heapId);
    work->cursorPaletteRes = CLACT_RegisterCharacter(archive, 0x26, 0, 0, work->heapId);
    work->cursorCellRes = CLACT_RegisterCellAnim(archive, 0x25, 0x24, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    inputGuardTemplate.softPriority = 10;
    inputGuardTemplate.bgPriority = 1;
    inputGuardTemplate.x = 0x92;
    inputGuardTemplate.y = 0xB0;
    inputGuardTemplate.animSeq = 0;
    work->inputGuard = (struct Actor *)CLACT_CreateActor(work->clactSys, work->cursorPaletteRes, work->cursorCharRes, work->cursorCellRes, (struct ActorInitParam *)(&inputGuardTemplate), 0, work->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->inputGuard, 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)((work->inputGuard)), 1);
    ITEMMENU_UpdateInputGuardAnim(work);
}

void ITEMMENU_ApplyBgPalettes(ItemMenuWork *work)
{
    unsigned packedPalette;
    packedPalette = work->bgPaletteA;
    BG_SYS_FreeTileRun(4, (unsigned short)packedPalette, (unsigned short)(packedPalette >> 16));
    packedPalette = work->bgPaletteB;
    BG_SYS_FreeTileRun(5, (unsigned short)packedPalette, (unsigned short)(packedPalette >> 16));
    packedPalette = work->bgPaletteD;
    BG_SYS_FreeTileRun(3, (unsigned short)packedPalette, (unsigned short)(packedPalette >> 16));
    packedPalette = work->frameCounter;
    BG_SYS_FreeTileRun(0, (unsigned short)packedPalette, (unsigned short)(packedPalette >> 16));
    packedPalette = work->bgPaletteC;
    BG_SYS_FreeTileRun(1, (unsigned short)packedPalette, (unsigned short)(packedPalette >> 16));
}

void ITEMMENU_SetLayersVisible(void *p, int v) { BG_SYS_SetPlaneVisible(5, v); BG_SYS_SetPlaneVisible(6, v); }

/*
 * blocked: WAZA_TOOL_GetDamageType (arm9 unlabelled leaf, the integrator's; 12 bytes, tail stub)
 * has no witness outside this function. Verified C for the leaf (EXACT,
 * thumb, arm9, no region):
 *   extern int WAZA_TOOL_GetParam(int, int);   // symbols: WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   int WAZA_TOOL_GetDamageType(int a) { return WAZA_TOOL_GetParam(a, 2); }
 */
void ITEMMENU_SetMoveTypeIconsVisible(ItemMenuWork *work, int mode)
{
    u16 moveId;
    if (mode == 1) {
        work->screenState = 1;
    } else {
        work->screenState = 2;
    }
    if (work->movingCursorActor != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->movingCursorActor, mode);
    }
    moveId = FILE_UTIL_GetMachineMove(ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work))->itemId);
    if (moveId != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)(work->damageClassActors[WAZA_TOOL_GetDamageType(moveId)]), mode);
        CLACT_SetActorDrawEnable((struct ClactActor *)(work->typeActors[WAZA_TOOL_GetType(moveId)]), mode);
    }
}

void ITEMMENU_DrawMoveInfo(ItemMenuWork *work)
{
    u32 i;
    u32 j;
    u16 *slotPtr;
    u16 moveId;
    u8 machineIndex;

    j = 0;
    for (i = 0; i < 3; i++)
        CLACT_SetActorDrawEnable((struct ClactActor *)work->damageClassActors[i], 0);
    for (j = 0; j < 17; j++)
        CLACT_SetActorDrawEnable((struct ClactActor *)work->typeActors[j], 0);
    slotPtr = (void *)ITEMMENU_GetSlot(work, ITEMMENU_GetCursorIndex(work));
    if (slotPtr == 0 || *slotPtr == 0) {
        ITEMMENU_SetMoveTypeIconsVisible(work, 0);
        return;
    }
    ITEMMENU_SetMoveTypeIconsVisible(work, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window), 0);
    moveId = FILE_UTIL_GetMachineMove(*slotPtr);
    if (moveId == 0) {
        MSGDATA_ReadString(work->msgBank, 0x86, work->tempString);
        ITEMMENU_RegisterItemName(work, 0, *slotPtr);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT], work->messageString, 0, (TextCoord)4, 0x3DC0);
        if (work->currentPocket != 4) {
            MSGDATA_ReadString(work->msgBank, 0x83, work->tempString);
            WORDSET_SetSlotNumber(work->wordSet, 0, slotPtr[1], 3, 0, 1);
            WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
            ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE], work->messageString, 0, (TextCoord)4, 0x3DC0);
        } else {
            BMP_WIN_TransferChars(work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
        }
        BMP_WIN_ClearScreen((work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    } else {
        machineIndex = FILE_UTIL_GetMachineIndex(*slotPtr);
        if (machineIndex == 0xFF) {
            MSGDATA_ReadString(work->msgBank, 0x45, work->tempString);
            WORDSET_SetSlotNumber(work->wordSet, 0, FILE_UTIL_GetId(*slotPtr) + 1, 2, 2, 1);
        } else {
            MSGDATA_ReadString(work->msgBank, 0x47, work->tempString);
            WORDSET_SetSlotNumber(work->wordSet, 0, machineIndex + 1, 2, 2, 1);
        }
        WORDSET_SetSlotFromMsgCB(work->wordSet, 1, moveId);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT], work->messageString, 0, (TextCoord)4, 0x3DC0);
        ITEMMENU_PrintMoveInfoText(work, moveId);
        BMP_WIN_TransferChars(work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
    }
    FILE_UTIL_ReadStringAlt(work->tempString, *slotPtr, work->heapId);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_DESC], work->tempString, 0, (TextCoord)4, 0x3DC0);
    ITEMMENU_FlushWindowAt(&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT]);
    ITEMMENU_FlushWindowAt(&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE]);
    ITEMMENU_FlushWindowAt(&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC]);
    ITEMMENU_CreateMovingCursor(work, *slotPtr);
}

void ITEMMENU_HideMoveInfo(ItemMenuWork *work)
{
    unsigned i;
    unsigned j;
    ITEMMENU_SetMoveTypeIconsVisible(work, 0);
    BMP_WIN_ClearScreen((work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    for (i = 0; i < 3; i++) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->damageClassActors[i], 0);
    }
    for (j = 0; j < 0x11; j++) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->typeActors[j], 0);
    }
}

void ITEMMENU_FreeGraphics(ItemMenuWork *work)
{
    int i;
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window));
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window));
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window));
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_MENU_0].window));
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_MENU_3].window));
    BMP_WIN_Delete((work->listWindows[ITEMMENU_WINDOW_MENU_4].window));
    CLACT_DeleteActor((struct ClactActor *)work->cursorActor);
    if (work->movingCursorActor != 0) {
        CLACT_DeleteActor((struct ClactActor *)work->movingCursorActor);
        CLACT_ReleaseCharacter(work->cellAnimRes);
        CLACT_ReleasePalette(work->cellRes);
    }
    CLACT_ReleaseCellAnim(work->cellTransRes);
    for (i = 0; i < 8; i++) {
        BMP_Delete(work->slotBitmap[i]);
    }
    CLACT_DeleteUnit(work->clactSys);
    CLACT_ExitSystem();
}

void ITEMMENU_PrintMenuTitle(ItemMenuWork *work) { MSGDATA_ReadString(work->msgBank, 0x87, work->tempString); ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_MENU_4], work->tempString, 0, (TextCoord)4, 0x3DC0); }

void ITEMMENU_InitWindows(ItemMenuWork *work)
{
    void *bg;

    work->listWindows[ITEMMENU_WINDOW_MENU_4].window = BMP_WIN_Create(3, 0x12, 9, 0xc, 3, 3, 1);
    ITEMMENU_PrintMenuTitle(work);
    BMP_WIN_ClearScreen((work->listWindows[ITEMMENU_WINDOW_MENU_4].window));
    work->listWindows[ITEMMENU_WINDOW_MENU_0].window = BMP_WIN_Create(3, 0x11, 0xd, 0xb, 2, 3, 1);
    work->listWindows[ITEMMENU_WINDOW_MENU_3].window = BMP_WIN_Create(3, 0x11, 0xf, 0xb, 2, 3, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window = BMP_WIN_Create(6, 0, 0x13, 0x20, 5, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window = BMP_WIN_Create(6, 7, 5, 0x12, 3, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window = BMP_WIN_Create(6, 0x14, 8, 6, 3, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window = BMP_WIN_Create(6, 2, 0xc, 0x1d, 7, 0, 1);
    BMP_WIN_MakeScreen((work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window));
    BMP_WIN_MakeScreen((work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window));
    BMP_WIN_MakeScreen((work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window));
    BMP_WIN_MakeScreen((work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    bg = ARC_TOOL_CreateHandle(0x19, work->heapId);
    work->cellTransRes = CLACT_RegisterCellAnim(bg, 1, 0, work->heapId);
    ARC_TOOL_DeleteHandle(bg);
    MSGDATA_ReadString(work->msgBank, 0x66, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_NAME], work->tempString, 8, (TextCoord)4, 0x3DC0);
    MSGDATA_ReadString(work->msgBank, 0x5d, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_NAME], work->tempString, 8, (TextCoord)0x18, 0x3DC0);
    MSGDATA_ReadString(work->msgBank, 0x5b, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_NAME], work->tempString, 0x70, (TextCoord)4, 0x3DC0);
    MSGDATA_ReadString(work->msgBank, 0x5c, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_NAME], work->tempString, 0x70, (TextCoord)0x18, 0x3DC0);
    MSGDATA_ReadString(work->msgBank, 0x5a, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_ITEM_NAME], work->tempString, 0xd0, (TextCoord)4, 0x3DC0);
    if (UI_GetInputMode() == 0) {
        ITEMMENU_DrawMoveInfo(work);
    }
}

void ITEMMENU_DestroyMovingCursor(ItemMenuWork *work) { if (work->movingCursorActor) { CLACT_DeleteActor((struct ClactActor *)work->movingCursorActor); CLACT_ReleaseCharacter(work->cellAnimRes); CLACT_ReleasePalette(work->cellRes); *(void * *)&work->movingCursorActor = 0; } }

void ITEMMENU_CreateMovingCursor(ItemMenuWork *work, int id)
{
    void *archive;
    ActorTemplate actorTemplate;
    if (work->movingCursorActor != 0) {
        ITEMMENU_DestroyMovingCursor(work);
    }
    archive = ARC_TOOL_CreateHandle(0x19, work->heapId);
    work->cellRes = CLACT_RegisterPaletteEx(archive, FILE_UTIL_Get(id, 2), 1, 0, 0, 1, work->heapId);
    work->cellAnimRes = CLACT_RegisterCharacter(archive, FILE_UTIL_Get(id, 1), 0, 1, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
    actorTemplate.x = 0x84;
    actorTemplate.y = 0x50;
    actorTemplate.animSeq = 0;
    actorTemplate.softPriority = 0;
    actorTemplate.bgPriority = 0;
    work->movingCursorActor = (struct Actor *)CLACT_CreateActor(work->clactSys, work->cellAnimRes, work->cellRes, work->cellTransRes, (struct ActorInitParam *)(&actorTemplate), 1, work->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->movingCursorActor, 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->movingCursorActor, 1);
}

void ITEMMENU_FreeActionMenuResources(ItemMenuWork *work) { CLACT_DrawSystem(); if (work->menuList) APP_TASKMENU_UpdateMenu((struct TaskMenuWork *)work->menuList); }

void ITEMMENU_LoadPocketGraphics(ItemMenuWork *work)
{
    void *archive;
    int i;

    archive = ARC_TOOL_CreateHandle(0x58, work->heapId);
    work->pocketCharRes = CLACT_RegisterPaletteEx(archive, 0x20, 0, 0x1a0, 0, 1, work->heapId);
    work->pocketPaletteRes = CLACT_RegisterCharacter(archive, 0x1f, 0, 0, work->heapId);
    work->pocketCellRes = CLACT_RegisterCellAnim(archive, 0x1e, 0x1d, work->heapId);
    work->bagCharRes = CLACT_RegisterPaletteEx(archive, 0x1c, 0, 0x60, 0, 1, work->heapId);
    work->bagPaletteRes = CLACT_RegisterCharacter(archive, 0x1b, 0, 0, work->heapId);
    work->bagCellRes = CLACT_RegisterCellAnim(archive, 0x1a, 0x19, work->heapId);
    for (i = 0; i < 8; i++) {
        work->slotBitmap[i] = BMP_Create(0xc, 2, 0x20, work->heapId);
        work->slotPaletteRes[i] =CLACT_RegisterCharacter(archive, 0x14, 0, 0, work->heapId);
    }
    MYSTATUS_GetSex(work->myStatus);
    work->barCharRes = CLACT_RegisterPaletteEx(archive, 0x15, 0, 0, 0, 3, work->heapId);
    work->bagAnimRes = CLACT_RegisterCellAnim(archive, 0x13, 0x12, work->heapId);
    ARC_TOOL_DeleteHandle(archive);
}

void ITEMMENU_CreateCursorActors(ItemMenuWork *work)
{
    ActorTemplate cursorTemplate;
    ActorTemplate selectorTemplate;
    ActorTemplate slotTemplate;
    int i;

    cursorTemplate.x = 0xf8;
    cursorTemplate.y = 0x1a;
    cursorTemplate.softPriority = 1;
    cursorTemplate.bgPriority = 2;
    cursorTemplate.animSeq = 0;
    work->cursorActor = (struct Actor *)CLACT_CreateActor(work->clactSys, work->bagPaletteRes, work->bagCharRes, work->bagCellRes, (struct ActorInitParam *)(&cursorTemplate), 0, work->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->cursorActor, 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->cursorActor, 1);
    ITEMMENU_MoveCursorToRow(work);
    selectorTemplate.x = 0x8c;
    selectorTemplate.y = 0x30;
    selectorTemplate.softPriority = 1;
    selectorTemplate.bgPriority = 2;
    selectorTemplate.animSeq = 1;
    work->selectorActor = (struct Actor *)CLACT_CreateActor(work->clactSys, work->bagPaletteRes, work->bagCharRes, work->bagCellRes, (struct ActorInitParam *)(&selectorTemplate), 0, work->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->selectorActor, 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->selectorActor, 1);
    for (i = 0; i < 8; i++) {
        slotTemplate.x = 0x8c;
        slotTemplate.y = i * 0x18;
        slotTemplate.softPriority = 0xa;
        slotTemplate.bgPriority = 3;
        slotTemplate.animSeq = 0;
        work->slotActorA[i] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->slotPaletteRes[i], work->barCharRes, work->bagAnimRes, (struct ActorInitParam *)(&slotTemplate), 0, work->heapId);
        slotTemplate.x -= 0x18;
        slotTemplate.animSeq = 1;
        work->slotActorC[i] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->pocketPaletteRes, work->pocketCharRes, work->pocketCellRes, (struct ActorInitParam *)(&slotTemplate), 0, work->heapId);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorA[i], 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 0);
    }
}

int ITEMMENU_GetRowColorKind(u16 itemId)
{
    if (FILE_UTIL_IsMachineItem(itemId) == 1) {
        switch (FILE_UTIL_GetMachineMove(itemId)) {
        case 0xF:
        case 0x13:
        case 0x39:
        case 0x46:
        case 0x7F:
        case 0x123:
            return 1;
        }
    }
    return 0;
}

void ITEMMENU_PrintItemList(ItemMenuWork *work)
{
    struct ArcFile *itemArchive;
    int i;
    int itemIndex;
    u16 *itemIdPtr;
    struct ItemRecord *itemData;
    u32 iconKind;
    u16 color;
    u16 moveId;
    struct BmpWin *windowHandle;

    if (ITEMMENU_GetItemCount(work) == 0) {
        ITEMMENU_FlushWindowAt(&work->listWindows[ITEMMENU_WINDOW_MENU_4]);
    } else {
        windowHandle = work->listWindows[ITEMMENU_WINDOW_MENU_4].window;
        BMP_WIN_ClearScreen(windowHandle);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(windowHandle));
    }
    if (work->shownItemId == work->scrollOffset) {
        return;
    }
    itemArchive = FILE_UTIL_CreateItemArcHandle(work->heapId);
    for (i = 0; i < 8; i++) {
        work->slotAnimIndex[i] = 0;
        itemIndex = work->scrollOffset + i;
        if (itemIndex < 0) {
            continue;
        }
        itemIdPtr = (void *)ITEMMENU_GetSlot(work, itemIndex);
        if (itemIdPtr == 0 || *itemIdPtr == 0) {
            continue;
        }
        itemData = FILE_UTIL_LoadArcMember(itemArchive, *itemIdPtr, work->heapId);
        iconKind = FILE_UTIL_GetItemRecordParam(itemData, 0xf);
        if (sRowStyleFlags[i] == 0) {
            if (ITEMMENU_GetRowColorKind(*itemIdPtr) == 1) {
                color = 0x18AD;
            } else {
                color = 0x82D;
            }
        } else {
            if (ITEMMENU_GetRowColorKind(*itemIdPtr) == 1) {
                color = 0x20ED;
            } else {
                color = 0x106D;
            }
        }
        BMP_Clear(work->slotBitmap[i], 0xd);
        MSGDATA_ReadString(work->msgBank, 0x82, work->tempString);
        moveId = FILE_UTIL_GetMachineMove(*itemIdPtr);
        if (moveId == 0) {
            ITEMMENU_RegisterItemName(work, 0, *itemIdPtr);
        } else {
            WORDSET_SetSlotFromMsgCB(work->wordSet, 0, moveId);
        }
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        PRINTSYS_PrintColor((void *)(work->slotBitmap[i]), 0, 0, work->messageString, (void *)(work->menuTaskArg), color);
        if (iconKind == 4) {
            work->slotAnimIndex[i] = 4;
        } else if (iconKind == 5) {
            work->slotAnimIndex[i] = 5;
        } else if (iconKind == 1) {
            work->slotAnimIndex[i] = 6;
        } else if (FILE_UTIL_GetMachineIndex(*itemIdPtr) != 0xff) {
            work->slotAnimIndex[i] = 8;
        } else if (FILE_UTIL_GetId(*itemIdPtr) != 0xff) {
            work->slotAnimIndex[i] = 7;
        } else if (FILE_UTIL_GetItemRecordParam(itemData, 4) == 0) {
            work->slotAnimIndex[i] = 3;
        } else if (ITEMMENU_IsItemRegistered(work, *itemIdPtr) == 0) {
            work->slotAnimIndex[i] = 2;
        } else {
            work->slotAnimIndex[i] = 1;
        }
        GFL_HEAP_Free(itemData);
    }
    ARC_TOOL_DeleteHandle(itemArchive);
    work->busyCount = 1;
}

void ITEMMENU_SnapSelectorToCursor(ItemMenuWork *work)
{
    ItemmenuSurfacePos surfacePos;
    ITEMMENU_UpdateSlotActorPosition(work, 0);
    CLACT_GetActorSurfacePos((struct ClactActor *)work->selectorActor, (struct ClactVec2 *)(&surfacePos), 0xFFFF);
    surfacePos.y = (work->cursorRow + 1) * 0x18;
    CLACT_AddActorSurfacePos((struct ClactActor *)work->selectorActor, (struct ClactVec2 *)(&surfacePos), 0xFFFF);
    if (UI_GetInputMode() == 0) {
        ITEMMENU_UpdateSlotActorPosition(work, 1);
    }
    BLINK_PALANM_ResetPhase(work->blinkPalAnm);
    CLACT_SetActorDrawEnable((struct ClactActor *)work->cursorActor, ITEMMENU_GetItemCount(work) >= 7);
    CLACT_SetActorAnimIndex((struct ClactActor *)work->selectorActor, 0);
    CLACT_SetActorAnimIndex((struct ClactActor *)work->cursorActor, 0);
}

void ITEMMENU_UploadSlotGraphics(ItemMenuWork *work)
{
    int i;
    u8 *srcChars;
    u8 *dstPixels;

    for (i = 0; i < 8; i++) {
        srcChars = (u8 *)CLACT_GetCharacterVramAddress(work->slotPaletteRes[i], 0);
        dstPixels = BMP_GetPixels((void *)work->slotBitmap[i]);
        DC_FlushRange(dstPixels, BMP_GetByteSize((void *)work->slotBitmap[i]));
        GX_LoadOBJ(dstPixels + 0x100, (uptr)(srcChars + 0x80), 0x80);
        GX_LoadOBJ(dstPixels + 0x280, (uptr)(srcChars + 0x100), 0x80);
        GX_LoadOBJ(dstPixels, (uptr)(srcChars + 0x300), 0x100);
        GX_LoadOBJ(dstPixels + 0x180, (uptr)(srcChars + 0x400), 0x100);
        if (work->slotAnimIndex[i] != 0) {
            if (work->currentPocket == 4) {
                if (ITEMMENU_IsBrowseMode(work) == 1 && work->slotAnimIndex[i] != 3) {
                    CLACT_SetActorAnimSeq((struct ClactActor *)work->slotActorC[i], work->slotAnimIndex[i] - 1);
                    CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 1);
                } else {
                    CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 0);
                }
            } else if (work->currentPocket == 0 && work->slotAnimIndex[i] >= 4) {
                CLACT_SetActorAnimSeq((struct ClactActor *)work->slotActorC[i], work->slotAnimIndex[i] - 1);
                CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 1);
            } else if (work->currentPocket == 2 && work->slotAnimIndex[i] >= 7) {
                CLACT_SetActorAnimSeq((struct ClactActor *)work->slotActorC[i], work->slotAnimIndex[i] - 1);
                CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 1);
            } else {
                CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 0);
            }
            CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorA[i], 1);
        } else {
            CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorC[i], 0);
            CLACT_SetActorDrawEnable((struct ClactActor *)work->slotActorA[i], 0);
        }
    }
}

void ITEMMENU_UpdateCursorFromTouch(ItemMenuWork *work)
{
    unsigned touchX;
    unsigned touchY;
    ItemmenuSurfacePos surfacePos;
    if (TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchY < 0x1A) {
            touchY = 0x1A;
        } else if (touchY > 0x8E) {
            touchY = 0x8E;
        }
        CLACT_GetActorSurfacePos((struct ClactActor *)work->cursorActor, (struct ClactVec2 *)(&surfacePos), 0xFFFF);
        surfacePos.y = touchY;
        CLACT_AddActorSurfacePos((struct ClactActor *)work->cursorActor, (struct ClactVec2 *)(&surfacePos), 0xFFFF);
    }
}

void ITEMMENU_MoveCursorToRow(ItemMenuWork *work)
{
    ItemmenuSurfacePos surfacePos;
    int itemCount = ITEMMENU_GetItemCount(work);
    if (itemCount >= 7) {
        CLACT_GetActorSurfacePos((struct ClactActor *)work->cursorActor, (struct ClactVec2 *)(&surfacePos), 0xFFFF);
        surfacePos.y = SCROLLBAR_GetPosFromValue(itemCount - 6, work->scrollOffset + 1, 0x1A, 0x8E, 0);
        CLACT_AddActorSurfacePos((struct ClactActor *)work->cursorActor, (struct ClactVec2 *)(&surfacePos), 0xFFFF);
    }
}

void ITEMMENU_CreateSideButtonActors(ItemMenuWork *work)
{
    ActorTemplate actorTemplate;
    ByteTable5 sideAnimSeqs;
    ByteTable5 sideXPositions;
    ByteTable2 arrowAnimSeqs;
    ByteTable2 arrowYPositions;
    u8 i;

    actorTemplate.softPriority = 0xa;
    actorTemplate.bgPriority = 1;
    sideAnimSeqs = sSideButtonAnimSeqs;
    sideXPositions = sSideButtonXPositions;
    for (i = 0; i < 5; i++) {
        actorTemplate.x = sideXPositions.values[i];
        actorTemplate.y = 0xa8;
        actorTemplate.animSeq = sideAnimSeqs.values[i];
        if (i == 2) {
            actorTemplate.y += 4;
        }
        work->sideActor[i] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->iconPaletteRes, work->iconCharRes, work->iconCellRes, (struct ActorInitParam *)(&actorTemplate), 0, work->heapId);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[i], 1);
    }
    CLACT_SetActorAutoAnim((struct ClactActor *)work->sideActor[0], 1);
    CLACT_SetActorAutoAnim((struct ClactActor *)work->sideActor[1], 1);
    if (ITEMMENU_IsBrowseMode(work) == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[2], 0);
    }
    if (work->bagMode == 2) {
        CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[3], 0);
    }
    arrowAnimSeqs = sArrowAnimSeqs;
    arrowYPositions = sArrowYPositions;
    for (i = 0; i < 2; i++) {
        actorTemplate.x = 0xe8;
        actorTemplate.y = arrowYPositions.values[i];
        actorTemplate.animSeq = arrowAnimSeqs.values[i];
        actorTemplate.bgPriority = 0;
        work->sideActor[(u8)(i + 5)] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->iconPaletteRes, work->iconCharRes, work->iconCellRes, (struct ActorInitParam *)(&actorTemplate), 0, work->heapId);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->sideActor[(u8)(i + 5)], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)work->sideActor[(u8)(i + 5)], 0);
    }
}

/*
 * Creates five sprites from three small tables.  The work area must be a
 * struct with the resource triple as an array (args res[1], res[0], res[2]):
 * the same fields spelled as `*(int *)(p + 0x594)` offsets colour the x/y
 * loads into different registers (23 bytes of DIFF).  The tables stay
 * non-const: a const coordinate table lets its load float above the two
 * record stores.
 * The data symbols are declared without an ovNNN token (the hint is
 * contested for 0x021BBA74 and 0x021BBBCC; sole-ref/data resolves them).
 */
void ITEMMENU_CreateTabActors(ItemMenuWork *work)
{
    unsigned i;
    ActorTemplate actorTemplate;
    for (i = 0; i < 5; i++) {
        actorTemplate.softPriority = sTabSoftPriorities[i];
        actorTemplate.bgPriority = 1;
        actorTemplate.x = sTabPositions[i][0] - 0x10;
        actorTemplate.y = sTabPositions[i][1];
        actorTemplate.animSeq = sTabAnimSeqs[i * 2 + 1];
        work->tabActor[i] = (struct Actor *)CLACT_CreateActor(work->clactSys, work->tabPaletteRes, work->tabCharRes, work->tabCellRes, (struct ActorInitParam *)(&actorTemplate), 0, work->heapId);
        CLACT_SetActorAutoAnim((struct ClactActor *)work->tabActor[i], 1);
    }
}

void ITEMMENU_SelectTab(ItemMenuWork *work, unsigned selectedTab)
{
    unsigned i;
    for (i = 0; i < 5; i++) {
        if (i == selectedTab) {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->tabActor[i], sTabAnimSeqs[i * 2]);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->tabActor[i], sTabAnimSeqs[i * 2 + 1]);
        }
    }
}

void ITEMMENU_ClearMessageWindow(ItemMenuWork *work) { BMP_MENUWORK_DrawWindowBorder(work->messageWindows[0].window, 1); }

void ITEMMENU_OpenPopupList(ItemMenuWork *work, int *msgIds, int entryCount)
{
    ItemmenuTaskMenuTmpl menuTemplate;
    int i;
    void *labelString;
    ItemMenuWork *rowView;

    menuTemplate.heapId = work->heapId;
    menuTemplate.itemNum = entryCount;
    menuTemplate.items = &work->listEntries[0].text;
    menuTemplate.posType = 1;
    menuTemplate.charPosX = 0x20;
    menuTemplate.charPosY = 0x18;
    menuTemplate.width = 0xD;
    menuTemplate.height = 3;
    for (i = 0; i < entryCount; i++) {
        /* rowView is the work area shifted by one row (0xC bytes) per entry, so its
         * listEntries[0] is entry i: the byte address is formed before the
         * row offset, as the array form listEntries[i] does not match. */
        rowView = (ItemMenuWork *)((char *)work + i * sizeof(ItemMenuListEntry));
        labelString = STRBUF_Create(0x64, work->heapId);
        rowView->listEntries[0].text = labelString;
        MSGDATA_ReadString(work->msgBank, msgIds[i], labelString);
        rowView->listEntries[0].color = 0x39E0;
        rowView->listEntries[0].extra = 0;
    }
    work->listEntries[i - 1].extra = 1;
    work->menuList = (struct TaskMenu *)APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&menuTemplate), work->taskMenuState);
    for (i = 0; i < entryCount; i++) {
        STRBUF_Delete(*(struct Strbuf **)&work->listEntries[i].text);
    }
    ITEMMENU_UpdateSideButtons(work, 0);
}

void ITEMMENU_LoadBgPaletteMode(ItemMenuWork *work, int mode)
{
    void *archive = ARC_TOOL_CreateHandle(0x58, work->heapId);

    if (mode != 2) {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(archive, 0x17, 5, 0, (u16)work->bgPaletteB, 0, 0, work->heapId);
    } else {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(archive, 0x18, 5, 0, (u16)work->bgPaletteB, 0, 0, work->heapId);
    }
    ARC_TOOL_DeleteHandle(archive);
}

void ITEMMENU_PrintMoveInfoText(ItemMenuWork *work, int moveId)
{
    int maxPp;
    int power;
    int accuracy;
    ItemMenuWindow *infoWindow;

    infoWindow = &work->listWindows[0];

    CLACT_SetActorDrawEnable((struct ClactActor *)(work->damageClassActors[WAZA_TOOL_GetDamageType((u16)moveId)]), 1);
    CLACT_SetActorDrawEnable((struct ClactActor *)(work->typeActors[WAZA_TOOL_GetType((u16)moveId)]), 1);
    maxPp = (int)WAZA_TOOL_GetMaxPP(moveId, 0);
    power = (int)WAZA_TOOL_GetParam(moveId, 3);
    accuracy = (int)WAZA_TOOL_GetParam(moveId, 4);
    BMP_FillRect(BMP_WIN_GetBmp(infoWindow->window), 0xB0, 0, 0x20, 0x28, 0);
    BMP_FillRect(BMP_WIN_GetBmp(infoWindow->window), 0xE8, 0, 0x18, 0x18, 0);
    if (power <= 1) {
        MSGDATA_ReadString(work->msgBank, 0x17, work->tempString);
        ITEMMENU_PrintToWindow(work, infoWindow, work->tempString, 0xB0, (TextCoord)4, 0x3DC0);
    } else {
        MSGDATA_ReadString(work->msgBank, 0x5F, work->tempString);
        WORDSET_SetSlotNumber(work->wordSet, 0, power, 3, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, infoWindow, work->messageString, 0xB0, (TextCoord)4, 0x3DC0);
    }
    if (accuracy == 0 || (int)WAZA_TOOL_IsAlwaysHit(moveId) == 1) {
        MSGDATA_ReadString(work->msgBank, 0x17, work->tempString);
        ITEMMENU_PrintToWindow(work, infoWindow, work->tempString, 0xB0, (TextCoord)0x18, 0x3DC0);
    } else {
        MSGDATA_ReadString(work->msgBank, 0x5F, work->tempString);
        WORDSET_SetSlotNumber(work->wordSet, 0, accuracy, 3, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, infoWindow, work->messageString, 0xB0, (TextCoord)0x18, 0x3DC0);
    }
    MSGDATA_ReadString(work->msgBank, 0x5E, work->tempString);
    WORDSET_SetSlotNumber(work->wordSet, 0, maxPp, 2, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_PrintToWindow(work, infoWindow, work->messageString, 0xE8, (TextCoord)4, 0x3DC0);
    ITEMMENU_FlushWindowAt(infoWindow);
}

/*
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through PRINTSYS_PrintStream (mode 1) or through ITEMMENU_PrintToWindow, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
 */
void ITEMMENU_ShowMessage(ItemMenuWork *work, int mode)
{
    ItemMenuWindow *win;

    if (work->messageWindows[0].window == 0) {
        work->messageWindows[0].window = BMP_WIN_Create(3, 1, 1, 0x1E, 4, 0xC, 1);
    }
    BMP_Clear(BMP_WIN_GetBmp(work->messageWindows[0].window), 0xF);
    BMP_WIN_TransferChars(work->messageWindows[0].window);
    win = &work->messageWindows[0];
    if (mode == 1) {
        work->messageWindow = (struct TextStream *)PRINTSYS_PrintStream(work->messageWindows[0].window, 0, 0, work->messageString,
                                            work->menuTaskArg, MSG_SPEED_GetWait(),
                                            work->touchTask, 2, work->heapId, 0xF);
    } else {
        ITEMMENU_PrintToWindow(work, win, work->messageString, 0, 0, 0x44F);
    }
    BMP_MENUWORK_DrawWindow(win->window, 1, (u16)work->keyRepeatPacked, 0xD);
    ITEMMENU_FlushWindowAt(win);
}

/*
 * Tail call to ITEMMENU_ShowMessage(p, 0).
 */
void ITEMMENU_ShowMessageDefault(ItemMenuWork *work)
{
    ITEMMENU_ShowMessage(work, 0);
}

void ITEMMENU_ShowItemUseMessage(ItemMenuWork *work, unsigned v) { MSGDATA_ReadString(work->msgBank, 0x2B, work->tempString); ITEMMENU_RegisterItemName(work, 0, v); WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString); }

int ITEMMENU_IsMessageFinished(ItemMenuWork *work)
{
    int streamState;

    if (work->messageWindow != 0) {
        streamState = PRINTSYS_PrintStreamGetState((struct TextPrinter *)work->messageWindow);
        APP_KEYCURSOR_Update(work->itemDescWindow, (struct TextPrinter *)work->messageWindow, work->messageWindows[0].window);
        switch (streamState) {
        case 2:
            PRINTSYS_PrintStreamDelete((struct TextPrinter *)work->messageWindow);
            work->messageWindow = 0;
            work->messageWindowOpen = 0;
            break;
        case 1:
            if (work->messageWindowOpen == 0) {
                if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x547);
                    PRINTSYS_PrintStreamReleasePause((struct TextPrinter *)work->messageWindow);
                    work->messageWindowOpen = 1;
                }
            }
            break;
        case 0:
            if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                PRINTSYS_PrintStreamShortWait((struct TextPrinter *)work->messageWindow, 0);
            }
            work->messageWindowOpen = 0;
            break;
        }
        return 0;
    }
    return 1;
}

void ITEMMENU_PrintPocketName(ItemMenuWork *work)
{
    work->messageWindows[1].window = BMP_WIN_Create(2, 3, 0x15, 0xC, 3, 0xC, 1);
    work->listWindows[ITEMMENU_WINDOW_MENU_1].window = BMP_WIN_Create(2, 1, 0x15, 8, 3, 0xC, 1);
    work->listWindows[ITEMMENU_WINDOW_MENU_2].window = BMP_WIN_Create(2, 9, 0x15, 9, 3, 0xC, 1);
    ITEMMENU_PrintPocketCount(work, work->currentPocket);
    ITEMMENU_SelectTab(work, work->currentPocket);
}

void ITEMMENU_HideSideWindows(ItemMenuWork *work) { BMP_WIN_Delete(work->messageWindows[1].window); BMP_WIN_Delete(work->listWindows[ITEMMENU_WINDOW_MENU_2].window); BMP_WIN_Delete(work->listWindows[ITEMMENU_WINDOW_MENU_1].window); }

void ITEMMENU_PrintPocketCount(ItemMenuWork *work, int itemCount)
{
    int freeWidth;

    BMP_Clear(BMP_WIN_GetBmp(work->messageWindows[1].window), 0);
    MSGDATA_ReadString(work->msgBank, 0x8B, work->tempString);
    WORDSET_SetSlotFromMsg37(work->wordSet, 0, itemCount);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    freeWidth = 0x60 - PRINTSYS_MeasureWidestLine(work->messageString, work->menuTaskArg, 0);
    ITEMMENU_PrintToWindow(work, &work->messageWindows[1], work->messageString, (unsigned short)(freeWidth >> 1), 4, 0x3C40);
    ITEMMENU_FlushWindowAt(&work->messageWindows[1]);
}

void ITEMMENU_PrintMoney(ItemMenuWork *work)
{
    BMP_Clear(BMP_WIN_GetBmp(work->listWindows[ITEMMENU_WINDOW_MENU_2].window), 0);
    BMP_Clear(BMP_WIN_GetBmp(work->listWindows[ITEMMENU_WINDOW_MENU_1].window), 0);
    MSGDATA_ReadString(work->msgBank, 0x51, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_MENU_1], work->tempString, 0, 4, 0x3C40);
    ITEMMENU_FlushWindowAt(&work->listWindows[ITEMMENU_WINDOW_MENU_1]);
    MSGDATA_ReadString(work->msgBank, 0x52, work->tempString);
    WORDSET_SetSlotNumber(work->wordSet, 0, MISC_GetMoney(GAME_DATA_GetMiscSave(work->saveData)), 7, 1, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_PrintToWindow(work, &work->listWindows[ITEMMENU_WINDOW_MENU_2], work->messageString, 0, 4, 0x3C40);
    ITEMMENU_FlushWindowAt(&work->listWindows[ITEMMENU_WINDOW_MENU_2]);
}

void ITEMMENU_EnterQuantityMode(ItemMenuWork *work) { CLACT_SetActorDrawEnable((struct ClactActor *)((work->sideActor[0])), 0); CLACT_SetActorDrawEnable((struct ClactActor *)((work->sideActor[1])), 0); BMP_WIN_ClearScreen(work->messageWindows[1].window); ITEMMENU_PrintMoney(work); }

void ITEMMENU_LeaveQuantityMode(ItemMenuWork *work) { CLACT_SetActorDrawEnable((struct ClactActor *)((work->sideActor[0])), 1); CLACT_SetActorDrawEnable((struct ClactActor *)((work->sideActor[1])), 1); BMP_WIN_ClearScreen(work->listWindows[ITEMMENU_WINDOW_MENU_2].window); BMP_WIN_ClearScreen(work->listWindows[ITEMMENU_WINDOW_MENU_1].window); ITEMMENU_PrintPocketCount(work, work->currentPocket); }

void ITEMMENU_OpenYesNoList(ItemMenuWork *work)
{
    ItemmenuTaskMenuTmpl menuTemplate;
    int heapId;
    void *labelString;

    heapId = work->heapId;
    menuTemplate.heapId = heapId;
    menuTemplate.itemNum = 2;
    menuTemplate.items = work->listEntries;
    menuTemplate.posType = 1;
    menuTemplate.charPosX = 0x20;
    menuTemplate.charPosY = 0xC;
    menuTemplate.width = 8;
    menuTemplate.height = 3;
    labelString = STRBUF_Create(0x64, heapId);
    work->listEntries[0].text = labelString;
    MSGDATA_ReadString(work->msgBank, 0x84, (void *)labelString);
    work->listEntries[0].color = 0x39E0;
    work->listEntries[0].extra = 0;
    labelString = STRBUF_Create(0x64, work->heapId);
    work->listEntries[1].text = labelString;
    MSGDATA_ReadString(work->msgBank, 0x85, (void *)labelString);
    work->listEntries[1].color = 0x39E0;
    work->listEntries[1].extra = 0;
    work->menuList = (struct TaskMenu *)APP_TASKMENU_OpenMenu((struct TaskMenuInitWork *)(&menuTemplate), work->taskMenuState);
    STRBUF_Delete((struct Strbuf *)(work->listEntries[0].text));
    STRBUF_Delete((struct Strbuf *)(work->listEntries[1].text));
    ITEMMENU_SetBackButtonAnim(work, 0);
    ITEMMENU_UpdateSideButtons(work, 0);
}

void ITEMMENU_CloseYesNoList(ItemMenuWork *work) { APP_TASKMENU_CloseMenu((struct TaskMenuWork *)work->menuList); work->menuList = 0; }

void ITEMMENU_LoadSellPalette(ItemMenuWork *work)
{
    void *archive;
    void *screenData;
    ScreenImage *screenImage;
    int i;
    u16 *tiles;
    int tileCount;

    archive = ARC_TOOL_CreateHandle(0x58, work->heapId);
    screenData = ARC_UTIL_LoadHandleMember(archive, 0x23, 0, work->heapId);
    i = 0;
    if (NNS_G2dGetUnpackedScreenData(screenData, (void **)(&screenImage))) {
        tiles = screenImage->data;
        tileCount = ((unsigned)screenImage->width >> 3) * ((unsigned)screenImage->height >> 3);
        for (; i < tileCount; i++) {
            tiles[i] += (u16)((u16)(int)work->bgPaletteD | 0x3000);
        }
        BG_SYS_DrawTile(3, (void *)screenImage->data, 0x10, 0xC, (unsigned)screenImage->width >> 3, (unsigned)screenImage->height >> 3);
        BG_SYS_MarkTileDirty(3);
    }
    GFL_HEAP_Free(screenData);
    ARC_TOOL_DeleteHandle(archive);
}

void ITEMMENU_PrintQuantityPrice(ItemMenuWork *work, int quantity)
{
    int sellTotal;
    ItemMenuWindow *priceWindow;
    ItemMenuWindow *quantityWindow;

    quantityWindow = &work->listWindows[ITEMMENU_WINDOW_MENU_0];

    BMP_Clear(BMP_WIN_GetBmp(quantityWindow->window), 5);
    MSGDATA_ReadString(work->msgBank, 0x83, work->tempString);
    WORDSET_SetSlotNumber(work->wordSet, 0, quantity, 3, 0, 1);
    WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
    ITEMMENU_PrintToWindow(work, quantityWindow, work->messageString, 0, 0, 0x3DC5);
    ITEMMENU_FlushWindowAt(quantityWindow);
    if (work->listMode == 2) {
        priceWindow = &work->listWindows[ITEMMENU_WINDOW_MENU_3];
        sellTotal = ITEMMENU_GetSellTotal(work->selectedItemId, work->listCount, work->heapId);
        BMP_Clear(BMP_WIN_GetBmp(priceWindow->window), 5);
        MSGDATA_ReadString(work->msgBank, 0x54, work->tempString);
        WORDSET_SetSlotNumber(work->wordSet, 0, sellTotal, 7, 0, 1);
        WORDSET_CopyTaggedText(work->wordSet, work->messageString, work->tempString);
        ITEMMENU_PrintToWindow(work, priceWindow, work->messageString, 0, 0, 0x3DC5);
        ITEMMENU_FlushWindowAt(priceWindow);
    }
}

int ITEMMENU_PocketToSortFlag(int pocket)
{
    switch (pocket) {
    case 0:
        return 10;
    case 3:
        return 13;
    case 1:
        return 11;
    case 2:
        return 12;
    case 4:
        return 14;
    }
    return pocket;
}

void ITEMMENU_UpdateSlotActorPosition(ItemMenuWork *work, u32 paletteOffset)
{
    short selectorPos[2];
    short slotPos[2];
    unsigned i;

    CLACT_GetActorSurfacePos((struct ClactActor *)work->selectorActor, (struct ClactVec2 *)selectorPos, 0);
    for (i = 0; i < 8; i++) {
        CLACT_GetActorSurfacePos((struct ClactActor *)work->slotActorA[i], (struct ClactVec2 *)slotPos, 0);
        if (slotPos[1] == selectorPos[1]) {
            break;
        }
    }
    CLACT_SetActorPaletteOffset((struct ClactActor *)work->slotActorA[i], (u8)paletteOffset, 0);
}

void ITEMMENU_UpdateSideButtons(ItemMenuWork *work, int page)
{
    int isSortFlagSet;

    if (work->currentPage == page) {
        return;
    }
    work->currentPage = page;
    isSortFlagSet = GAME_DATA_ContainsRecentId((struct GameData *)work->saveData, ITEMMENU_PocketToSortFlag(work->currentPocket));
    if (page == 1) {
        PALANM_RequestFade((PaletteFade *)work->palAnmSlot, 4, 0x23CF, 0, 0, 0, 0, GFL_USE_GetMainTaskList());
        PALANM_RequestFade((PaletteFade *)work->palAnmSlot, 1, 1, 0, 0, 0, 0, GFL_USE_GetMainTaskList());
        G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 6, 0);
        ITEMMENU_UpdateInputGuardAnim(work);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[0], 4);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[1], 5);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[3], 0);
        if (isSortFlagSet == 1) {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 7);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 6);
        }
        ITEMMENU_SetBackButtonAnim(work, 1);
    } else {
        PALANM_CopyHwPaletteToSlot(work->palAnmSlot, 2, 0, 0x200);
        PALANM_RequestFade((PaletteFade *)work->palAnmSlot, 4, 0x23CF, 0, 8, 8, 0, GFL_USE_GetMainTaskList());
        PALANM_RequestFade((PaletteFade *)work->palAnmSlot, 1, 1, 0, 8, 8, 0, GFL_USE_GetMainTaskList());
        if (work->bagMode == 4 && CLACT_GetActorDrawEnable((struct ClactActor *)work->sideActor[0]) == 0) {
            G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 2, -8);
        } else {
            G2x_SetBlendBrightness_(REG_BLDCNT_ADDR, 6, -8);
        }
        CLACT_SetActorAnimSeq((struct ClactActor *)work->inputGuard, 4);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[0], 0x12);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[1], 0x13);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[3], 0xE);
        if (isSortFlagSet == 1) {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 0x16);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 0x15);
        }
    }
}

void ITEMMENU_SetBackButtonAnim(ItemMenuWork *work, int v) { if (v == 1) CLACT_SetActorAnimSeq((struct ClactActor *)((work->sideActor[4])), 1); else CLACT_SetActorAnimSeq((struct ClactActor *)((work->sideActor[4])), 15); }

void ITEMMENU_UpdateInputGuardAnim(ItemMenuWork *work) { if (work->currentPocket == 2 || work->currentPocket == 3 || ITEMMENU_GetItemCount(work) <= 1) CLACT_SetActorAnimSeq((struct ClactActor *)((work->inputGuard)), 4); else CLACT_SetActorAnimSeq((struct ClactActor *)((work->inputGuard)), 0); }

void ITEMMENU_UpdateSideButtonsForMode(ItemMenuWork *work, int mode)
{
    int isSortFlagSet = GAME_DATA_ContainsRecentId(work->saveData, ITEMMENU_PocketToSortFlag(work->currentPocket));

    if (mode == 1) {
        ITEMMENU_UpdateInputGuardAnim(work);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[0], 4);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[1], 5);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[3], 0);
        if (isSortFlagSet == 1) {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 7);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 6);
        }
    } else {
        CLACT_SetActorAnimSeq((struct ClactActor *)work->inputGuard, 4);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[0], 0x12);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[1], 0x13);
        CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[3], 0xE);
        if (isSortFlagSet == 1) {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 0x16);
        } else {
            CLACT_SetActorAnimSeq((struct ClactActor *)work->sideActor[2], 0x15);
        }
    }
}

/*
 * lever: expand q at the first call but retain q for the second call.
 */
#ifdef __MWERKS__
int ITEMMENU_MoveActorToPoint(ItemMenuWork *work)
{
    const char *workBytes = (const char *)work;
    unsigned i;
    short actorPos[2];
    const char *actorBytes;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        actorBytes = workBytes + off;
        CLACT_GetActorSurfacePos(*(struct ClactActor **)(workBytes + off + 0x6AC), (struct ClactVec2 *)actorPos, 0xFFFF);
        if (actorPos[0] == *((short *)(((char *)sTabPositions) + off))) {
            return 0;
        }
        actorPos[0] = actorPos[0] + 4;
        CLACT_AddActorSurfacePos(*(struct ClactActor **)(actorBytes + 0x6AC), (const struct ClactVec2 *)actorPos, 0xFFFF);
    }
    return 1;
}
#else
int ITEMMENU_MoveActorToPoint(ItemMenuWork *work)
{
    unsigned i;
    short actorPos[2];
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        CLACT_GetActorSurfacePos((struct ClactActor *)work->tabActor[i], (struct ClactVec2 *)actorPos, 0xFFFF);
        if (actorPos[0] == *((short *)(((char *)sTabPositions) + off))) {
            return 0;
        }
        actorPos[0] = actorPos[0] + 4;
        CLACT_AddActorSurfacePos((struct ClactActor *)work->tabActor[i], (const struct ClactVec2 *)actorPos, 0xFFFF);
    }
    return 1;
}
#endif

void ITEMMENU_PrintToWindow(ItemMenuWork *work, ItemMenuWindow *slot, void *str, u16 x, TextCoord y, u16 color)
{
    void *print = work->printSys;

    PRINTSYS_PrintQueColor(print, BMP_WIN_GetBmp(slot->window), (TextCoord)x, y, str, work->menuTaskArg, color);
    slot->isDirty = 1;
}

void ITEMMENU_FlushWindowAt(ItemMenuWindow *slot)
{
    BMP_WIN_MakeScreen(slot->window);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(slot->window));
}

/* Window whose text was printed: once the print system has finished with its
 * buffer, flushes the window to VRAM and clears the dirty flag. */
static inline void flushWindow(ItemMenuWork *work, ItemMenuWindow *slot)
{
    void *printSys = work->printSys;
    if (slot->isDirty != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printSys, (void *)(BMP_WIN_GetBmp(slot->window))) == 0) {
            BMP_WIN_TransferChars(slot->window);
            slot->isDirty = 0;
        }
    }
}

void ITEMMENU_FlushDirtyWindows(ItemMenuWork *work)
{
    PRINTSYS_QUE_Main((struct PrintQueue *)work->printSys);
    flushWindow(work, &work->listWindows[0]);
    flushWindow(work, &work->listWindows[1]);
    flushWindow(work, &work->listWindows[2]);
    flushWindow(work, &work->listWindows[3]);
    flushWindow(work, &work->listWindows[4]);
    flushWindow(work, &work->listWindows[5]);
    flushWindow(work, &work->listWindows[6]);
    flushWindow(work, &work->listWindows[7]);
    flushWindow(work, &work->listWindows[8]);
    flushWindow(work, &work->messageWindows[0]);
    flushWindow(work, &work->messageWindows[1]);
}
