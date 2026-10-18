/*
 * file:     zukan_detail_form.c
 * unit:     yes
 * function: ZUKAN_DETAIL_FORM_SetHeapId, ZUKAN_DETAIL_FORM_Init, ZUKAN_DETAIL_FORM_Exit, ZUKAN_DETAIL_FORM_Main, ZUKAN_DETAIL_FORM_HandleKeyEvent, ZUKAN_DETAIL_FORM_DrawModels, ZUKAN_DETAIL_FORM_ApplyPendingDisplay, ZUKAN_DETAIL_FORM_BuildFormLabelText, ZUKAN_DETAIL_FORM_CreateTextWindows, ZUKAN_DETAIL_FORM_DeleteTextWindows, ZUKAN_DETAIL_FORM_CreatePrintQueues, ZUKAN_DETAIL_FORM_DeletePrintQueues, ZUKAN_DETAIL_FORM_UpdatePrintQueues, ZUKAN_DETAIL_FORM_FlushPrintWindow, ZUKAN_DETAIL_FORM_DrawSpeciesLabels, ZUKAN_DETAIL_FORM_DrawFormLabel, ZUKAN_DETAIL_FORM_DrawFormLabelMain, ZUKAN_DETAIL_FORM_DrawFormLabelSub, ZUKAN_DETAIL_FORM_UpdateBgScrollForState, ZUKAN_DETAIL_FORM_InitModelSystem, ZUKAN_DETAIL_FORM_ExitModelSystem, ZUKAN_DETAIL_FORM_AddModel, ZUKAN_DETAIL_FORM_DeleteModel, ZUKAN_DETAIL_FORM_CenterModelOffset, ZUKAN_DETAIL_FORM_GetModelPosition, ZUKAN_DETAIL_FORM_CreateModelItem, ZUKAN_DETAIL_FORM_DestroyModelItem, ZUKAN_DETAIL_FORM_InitAnimState, ZUKAN_DETAIL_FORM_RestartModelAnim, ZUKAN_DETAIL_FORM_SignalAnimDone, ZUKAN_DETAIL_FORM_StopModelAnim, ZUKAN_DETAIL_FORM_OnAnimStopRequest, ZUKAN_DETAIL_FORM_ToggleModelVisibility, ZUKAN_DETAIL_FORM_LoadIconResources, ZUKAN_DETAIL_FORM_ReleaseIconResources, ZUKAN_DETAIL_FORM_CreateIconActor, ZUKAN_DETAIL_FORM_DeleteIconActor, ZUKAN_DETAIL_FORM_BuildFormEntries, ZUKAN_DETAIL_FORM_RefreshFormEntries, ZUKAN_DETAIL_FORM_PlaceModelItem, ZUKAN_DETAIL_FORM_CreateCurrentIcon, ZUKAN_DETAIL_FORM_RebuildModels, ZUKAN_DETAIL_FORM_RebuildModelsSwapped, ZUKAN_DETAIL_FORM_RebuildModelsSingle, ZUKAN_DETAIL_FORM_RebuildSideModels, ZUKAN_DETAIL_FORM_SwapIconActor, ZUKAN_DETAIL_FORM_UpdateState, ZUKAN_DETAIL_FORM_HandleStateEvent, ZUKAN_DETAIL_FORM_CreateArrowActors, ZUKAN_DETAIL_FORM_DeleteArrowActors, ZUKAN_DETAIL_FORM_HandleTouchArrows, ZUKAN_DETAIL_FORM_UpdateArrowVisibility, ZUKAN_DETAIL_FORM_UpdateArrowAnim, ZUKAN_DETAIL_FORM_UpdateCursorMarkers, ZUKAN_DETAIL_FORM_UpdateScrollMarkers, ZUKAN_DETAIL_FORM_UpdateScrollInput, ZUKAN_DETAIL_FORM_HandleScrollTouch, ZUKAN_DETAIL_FORM_HandleScrollKey, ZUKAN_DETAIL_FORM_GetScrollSlotRange, ZUKAN_DETAIL_FORM_GetScrollSlotAtX, ZUKAN_DETAIL_FORM_CountEntriesBefore, ZUKAN_DETAIL_FORM_GetEntryIndex, ZUKAN_DETAIL_FORM_UpdateSlideLeft, ZUKAN_DETAIL_FORM_AdvanceSelection, ZUKAN_DETAIL_FORM_PlaceSideModels, ZUKAN_DETAIL_FORM_UpdateSlideRight, ZUKAN_DETAIL_FORM_UpdateSlideBoth, ZUKAN_DETAIL_FORM_RebuildSideItems, ZUKAN_DETAIL_FORM_SwapItems, ZUKAN_DETAIL_FORM_SetActorsNormalMode, ZUKAN_DETAIL_FORM_SetActorsAlphaMode, ZUKAN_DETAIL_FORM_GetModelOffsets, ZUKAN_DETAIL_FORM_ConvertModelPosition, ZUKAN_DETAIL_FORM_SelectModelPosition, ZUKAN_DETAIL_FORM_CopyModelPosition
 * address:  0x021C3B68
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_detail_headbar.c, zukan_detail_page.c, zukan_detail_voice.c, zukan_detail_form.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString        0x02045EC0  arm
 *   PRINTSYS_PrintQueColor        0x0201C724  thumb
 *   STRBUF_Delete        0x02045808  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   ZUKAN_DETAIL_HEADBAR_GetIconKind  0x021BE840  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind  0x021BE82C  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconSpecies  0x021BE844  thumb  ov208
 *   ZUKAN_DETAIL_HEADBAR_SetIconForm  0x021BE854  thumb  ov208
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode 0x021BDAAC thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   ZUKAN_DETAIL_HEADBAR_SetIconKind 0x021BE82C thumb
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState 0x021BDBA0 thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   ZUKAN_SAVE_GetSpindaPersonality 0x0200D288 thumb
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetCursorValue  0x021BC3B8  thumb  ov208
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc  0x021BC844  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots  0x021BC758  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeIn  0x021BC718  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull  0x021BC4F4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOut  0x021BC6D8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetMaxValue  0x021BC3BC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy  0x021BC6C8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOutAlt  0x021BC6F8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled  0x021BDAE8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone  0x021BC508  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_TickFlashEffect  0x021BC99C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades  0x021BC46C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdatePaletteAnim  0x021BC678  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_TransferPalettes 0x021BC6BC thumb ov208
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcIdSub  0x0201BC78  thumb
 *   POKE_TOOL_GetIconCellEntryIdSub  0x0201BCEC  thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable  0x021BDBAC  thumb  ov208
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Callback  0x0201EE60  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   G2x_SetBlendAlpha_ 0x0207D63C  arm
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget  0x021BC518  thumb  ov208
 *   ZUKAN_DETAIL_GRAPHIC_Reset3dState  0x021BCF4C  thumb  ov208
 *   POKEGRA_GetArcID 0x0202D060 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode  0x021BDAD0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode  0x021BDAAC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled  0x021BDAD4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind  0x021BDBB8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb
 *   TCB_Main 0x02030D28 arm
 *   ZUKAN_DETAIL_FORM_SetHeapId 0x021C3B68 thumb
 *   gSpeciesNameBank 0x020A7370 data a4
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry 0x021BC3C0 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb ov208
 *   ZUKAN_DETAIL_COMMON_GetFont 0x021BC3AC thumb ov208
 *   ZUKAN_DETAIL_FORM_CreatePrintQueues 0x021C4AC4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault 0x021BC610 thumb ov208
 *   ZUKAN_DETAIL_COMMON_FreeBgPalette 0x021BC97C thumb ov208
 *   ZUKAN_DETAIL_COMMON_SetBgScrollPacked 0x021BCA54 thumb ov208
 *   ZUKAN_DETAIL_FORM_DeleteArrowActors 0x021C66C8 thumb ov208
 *   ZUKAN_DETAIL_FORM_DeleteIconActor 0x021C53E0 thumb ov208
 *   ZUKAN_DETAIL_FORM_ReleaseIconResources 0x021C533C thumb ov208
 *   ZUKAN_DETAIL_FORM_DeleteTextWindows 0x021C4A48 thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetBgPriority 0x021BDCA4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeletePaletteAnim 0x021BC61C thumb ov208
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_FORM_DeletePrintQueues 0x021C4AF4 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   ZUKAN_DETAIL_GRAPHIC_Init3dSystem  0x021BCF58  thumb  ov208
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteRange  0x021BC9BC  thumb  ov208
 *   MCSS_CheckPaletteFade  0x0201600C  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb  ov208
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   ZUKAN_DETAIL_FORM_DestroyModelItem  0x021C51A0  thumb  ov208
 *   ZUKAN_DETAIL_FORM_ExitModelSystem  0x021C4FDC  thumb  ov208
 *   ZUKAN_DETAIL_GRAPHIC_Delete3dSystem  0x021BCF6C  thumb  ov208
 *   MCSS_Main  0x02014C08  thumb
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies 0x021BC3CC thumb ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies 0x021BC40C thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible 0x021BDBEC thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive 0x021BDC2C thumb ov208
 *   MCSS_Draw 0x02014D2C thumb
 *   ARC_UTIL_LoadMemberWithSize  0x0204A298  arm
 *   data_021C8830  0x021C8830  data
 *   data_021C8794  0x021C8794  data
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   ZUKAN_DETAIL_FORM_InitModelSystem 0x021C4F78 thumb ov208
 *   ZUKAN_DETAIL_FORM_StopModelAnim 0x021C5214 thumb ov208
 *   ZUKAN_DETAIL_FORM_LoadIconResources 0x021C52F0 thumb ov208
 *   ZUKAN_DETAIL_FORM_BuildFormEntries 0x021C53F4 thumb ov208
 *   ZUKAN_DETAIL_FORM_RefreshFormEntries 0x021C5664 thumb ov208
 *   ZUKAN_DETAIL_FORM_RebuildModels 0x021C580C thumb ov208
 *   ZUKAN_DETAIL_FORM_RebuildSideModels 0x021C5C64 thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateState 0x021C5D64 thumb ov208
 *   ZUKAN_DETAIL_FORM_HandleStateEvent 0x021C5F34 thumb ov208
 *   ZUKAN_DETAIL_FORM_CreateArrowActors 0x021C625C thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateArrowAnim 0x021C692C thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateScrollInput 0x021C6BB4 thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateSlideLeft 0x021C6E98 thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateSlideRight 0x021C75FC thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateSlideBoth 0x021C7860 thumb ov208
 *   ZUKAN_DETAIL_FORM_SetActorsNormalMode 0x021C7E74 thumb ov208
 *   ZUKAN_DETAIL_FORM_SetActorsAlphaMode 0x021C7EF8 thumb ov208
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   TCB_Noop 0x02030DA4 arm
 *   MCSS_Init  0x02014B08  thumb
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb
 *   MCSS_SetOrthoMode  0x02015BF0  thumb
 *   MCSS_OpenHandle  0x02014CB8  thumb
 *   MCSS_SetTaskSystem  0x02014CEC  thumb
 *   data_021C8E64  0x021C8E64  data
 *   MCSS_TOOL_SetSpindaSpotHook  0x020172AC  thumb
 *   MCSS_TOOL_MakeAddWorkFromParam  0x02017168  thumb
 *   MCSS_Add  0x020159C8  thumb
 *   MCSS_SetShadowVanishFlag  0x02015FF0  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   data_021C8804  0x021C8804  data
 *   MCSS_GetOfsX  0x02015F14  thumb
 *   MCSS_SetOfsPosition  0x02015C78  thumb
 *   MCSS_GetPosition  0x02015C30  thumb
 *   data_021C8E40  0x021C8E40  data
 *   MCSS_GetAnimCtrl  0x02015EE8  thumb
 *   NNS_G2dSetCellAnimationParam  0x02063000  arm
 *   NNS_G2dRestartMCAnimation 0x02064CBC arm
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   MCSS_RequestAnimeStopAtStart  0x02016380  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   ZUKAN_SAVE_GetFormCount  0x0200CC20  thumb
 *   ZUKAN_SAVE_HasSeenGenderForm  0x0200D144  thumb
 *   data_021C8810  0x021C8810  data
 *   data_021C87FC  0x021C87FC  data
 *   MCSS_SetPosition  0x02015C48  thumb
 *   ZUKAN_DETAIL_FORM_PlaceSideModels 0x021C7534 thumb ov208
 *   ZUKAN_DETAIL_FORM_DrawFormLabelSub  0x021C4EAC  thumb
 *   ZUKAN_DETAIL_FORM_ToggleModelVisibility  0x021C526C  thumb
 *   ZUKAN_DETAIL_FORM_RebuildModelsSingle  0x021C5B00  thumb
 *   ZUKAN_DETAIL_FORM_RestartModelAnim  0x021C51D4  thumb
 *   ZUKAN_DETAIL_FORM_AdvanceSelection  0x021C7448  thumb
 *   ZUKAN_DETAIL_FORM_RebuildSideItems  0x021C7CE8  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible  0x021BDBEC  thumb
 *   ZUKAN_DETAIL_FORM_GetModelPosition  0x021C50F8  thumb
 *   ZUKAN_DETAIL_FORM_UpdateBgScrollForState  0x021C4F30  thumb
 *   ZUKAN_DETAIL_FORM_UpdateScrollMarkers  0x021C6AFC  thumb
 *   ZUKAN_DETAIL_FORM_UpdateArrowVisibility  0x021C68D4  thumb
 *   data_021C87A0  0x021C87A0  data
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   ZUKAN_DETAIL_FORM_CopyModelPosition        0x021C80CC  thumb
 *   ZUKAN_DETAIL_FORM_SwapItems        0x021C7D80  thumb
 *   ZUKAN_DETAIL_FORM_SwapIconActor        0x021C5CF0  thumb
 *   ZUKAN_DETAIL_FORM_DrawFormLabelMain        0x021C4E54  thumb
 *   ZUKAN_SAVE_UpdateViewFlags        0x0200CA98  thumb
 *   data_021C87C0  0x021C87C0  data
 *   data_021C8854  0x021C8854  data
 *   ZUKAN_DETAIL_FORM_ConvertModelPosition 0x021C7FF8  thumb  ov208
 *   MCSS_Exit  0x02014BA8  thumb  arm9
 *   MCSS_CloseHandle  0x02014CD4  thumb  arm9
 *   MCSS_Del  0x02015BA4  thumb  arm9
 *   ZUKAN_DETAIL_FORM_DrawSpeciesLabels 0x021C4BB4 thumb ov208
 *   ZUKAN_DETAIL_FORM_DrawFormLabelMain 0x021C4E54 thumb ov208
 *   ZUKAN_DETAIL_FORM_DrawFormLabelSub 0x021C4EAC thumb ov208
 *   ZUKAN_DETAIL_FORM_UpdateBgScrollForState 0x021C4F30 thumb ov208
 */
#include "zukan_detail_shared_types.h"
#include "zukan_detail_form_types.h"

extern u32 GFL_HEAP_Free(void *p);

extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

extern void TCB_DeleteTask(struct Node *n);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern void UI_SetInputMode(u8 v);

extern u32 KEY_GetTrg(void);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern u32 KEY_GetRepeat(void);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(void *s);

extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);

extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);

extern u32  ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);

extern void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(u32 fade);

extern void ZUKAN_DETAIL_COMMON_StartFadeIn(u32 fade);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int sub, u32 blend);

extern void ZUKAN_DETAIL_COMMON_StartFadeOut(u32 fade);

extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(void *s, int b);

extern int  ZUKAN_DETAIL_COMMON_IsFadeBusy(u32 fade);

extern void ZUKAN_DETAIL_COMMON_StartFadeOutAlt(u32 fade);

extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(void *s, int v);

extern void ZUKAN_DETAIL_COMMON_TickFlashEffect(u32 win);

extern void ZUKAN_DETAIL_COMMON_UpdateBlendFades(u32 main, u32 sub);

extern void ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(u32 fade);

extern void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern int POKE_TOOL_GetIconPaletteArcId(void);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern int POKE_TOOL_GetIconCellArcIdSub(void);

extern int POKE_TOOL_GetIconCellEntryIdSub(void);

extern u32  POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern u32  POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

extern int POKEGRA_GetArcID(void);

extern void TCB_Main(struct Ctx *c);

extern void BG_SYS_SetFlagField06(u32 bit);

extern u32 PRINTSYS_QUE_Create(void *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

#define W(o) (*(u32 *)((u8 *)(u8 *)p + (o)))

#define PW(o) (*(void **)((u8 *)(u8 *)p + (o)))

#define OBJ(i) (*(u32 *)((u8 *)p + (i) * 0x44 + 0xc))

#define H(o) (*(u16 *)((u8 *)p + (o)))

struct McssFade;

struct McssSys;

typedef int            s32;

struct Ov208Sel {
    u16 next;
    u16 sel;
    u16 twos;
    u16 groups;
    u16 count;
};

struct Ov208WinTbl {
    u8 d[5][7];
};

typedef enum { YP_0 = 0, YP_MAX = 0x7fffffff } YPos;

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void *MSGDATA_AllocString(struct MsgBank *bank,u32 index);

extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s,u32 a,u32 b);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern u16 BMP_GetWidth(const struct Bmp *p);

extern void STRBUF_Delete(struct U16Vec *s);

extern void BMP_Clear(struct CharBuf *p, u8 v);

extern void CLACT_SetActorDrawEnable(struct Obj *p,u32 v);


extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);

extern void *GFL_HEAP_Alloc(u32 heap,u32 size,int clear,const char *file,u16 line);

extern void CLACT_SetActorObjMode(struct Actor *p,u32 value);

extern void G2x_SetBlendAlpha_(u32 reg,int p1,int p2,int ev1,int ev2);

extern void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(void *proc, u32 size, u32 heap);

extern void *ZUKAN_DETAIL_GRAPHIC_Reset3dState(void *a);

extern void *GFL_USE_AddMainTask(void (*fn)(int, char *), void *p, u32 c);

extern void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);

extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(void *a);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, void *a);

extern void *ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(u32 heap);

extern void ZUKAN_DETAIL_COMMON_FreeBgPalette(u32 a);

extern void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed);

void ZUKAN_DETAIL_FORM_DeleteIconActor(int a, int b);

extern void ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(void *s, u8 v);

extern void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(u32 a);

extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(u32 a);

extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(void *proc);

extern void BG_SYS_FillScrollArea(u32 bgId, u32 which, u32 value);

extern void BG_SYS_FreeSlot(u32 bgId);

extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);

extern void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(void *s, int x);

extern void MCSS_SetVanishFlag(void *p);

extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);

extern u32  ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs,
                                u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);

extern int MCSS_CheckPaletteFade(void *p);

extern int  ZUKAN_DETAIL_TOUCHBAR_GetMode(void *s);

extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(void *s, u32 mode, u32 kind, u32 flag);

extern void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(void *s, int v);

extern void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(void *s, u32 kind);

extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(void *s, u32 on);

extern int GAME_DATA_CheckSaveFlag(void *gd, int flag);

extern int  ZUKAN_DETAIL_HEADBAR_GetIconKind(void *icon);

extern void ZUKAN_DETAIL_HEADBAR_SetIconKind(void *icon, int kind);

extern void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(void *icon);

extern void MCSS_ResetVanishFlag(void *p);

extern void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(void *s);

extern void ZUKAN_DETAIL_HEADBAR_SetIconForm(void *icon);

void ZUKAN_DETAIL_FORM_DestroyModelItem(struct Ov208Mdl *p, int a);

extern void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(void *s);

extern void MCSS_Main(char *self);

extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(void *sys, int v);

extern int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(void *sys);

extern void MCSS_Draw(struct McssSys *sys);

extern void *ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern void WORDSET_SetSlotNumber(struct WordSet *ws, u32 a, u32 b, u32 c, u32 d, u32 e);

void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value);

int ZUKAN_DETAIL_FORM_Init(void *proc, int *seq, u16 *heap, u8 *unused, struct Ov208Ctx *key);

int ZUKAN_DETAIL_FORM_Exit(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

int ZUKAN_DETAIL_FORM_Main(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_HandleKeyEvent(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int ev);

void ZUKAN_DETAIL_FORM_DrawModels(u32 a, u32 b, u32 c, struct Ov208Form *p);

void ZUKAN_DETAIL_FORM_ApplyPendingDisplay(int unused, char *p);

void ZUKAN_DETAIL_FORM_BuildFormLabelText(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, u32 *outStr, u32 *outB, int *outC, int *outD, u16 idx);

void ZUKAN_DETAIL_FORM_CreateTextWindows(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_DeleteTextWindows(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_CreatePrintQueues(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_DeletePrintQueues(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_ExitModelSystem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_ReleaseIconResources(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_DeleteArrowActors(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdatePrintQueues(void *a0, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_FlushPrintWindow(void *a0, struct Ov208Form *p, struct Ov208Ctx *a2, int i);

void ZUKAN_DETAIL_FORM_DrawSpeciesLabels(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_DrawFormLabel(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int i, u32 print, u32 win, u32 *active, u16 idx);

void ZUKAN_DETAIL_FORM_DrawFormLabelMain(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_DrawFormLabelSub(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateBgScrollForState(void *unused, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_InitModelSystem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_StopModelAnim(struct Ov208Mdl *p);

void ZUKAN_DETAIL_FORM_LoadIconResources(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_BuildFormEntries(u16 *heap, struct Ov208Ctx *key, struct Ov208Ent *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next);

void ZUKAN_DETAIL_FORM_RefreshFormEntries(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_RebuildModels(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_RebuildSideModels(void *a0, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateState(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_HandleStateEvent(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx, int ev);

void ZUKAN_DETAIL_FORM_CreateArrowActors(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateArrowAnim(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateScrollInput(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateSlideLeft(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_FORM_UpdateSlideRight(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_FORM_UpdateSlideBoth(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx);

void ZUKAN_DETAIL_FORM_SetActorsNormalMode(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_SetActorsAlphaMode(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key);

extern struct MsgBank *gSpeciesNameBank;

extern const struct Ov208WinTbl data_021C8830;

extern const u16 data_021C8794[6];

void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value)
{
    *p = value;
}

int ZUKAN_DETAIL_FORM_Init(void *proc, int *seq, u16 *heap, u8 *unused, struct Ov208Ctx *key)
{
    struct Ov208Form *p;
    u8 i;
    p = ZUKAN_DETAIL_PROCSYS_AllocBuffer(proc, 0x6e4, *heap);
    i = 0;
    MI_CpuFill8(p, 0, 0x6e4);
    PW(0) = ZUKAN_DETAIL_GRAPHIC_Reset3dState(ZUKAN_DETAIL_COMMON_GetDisplay(key));
    PW(4) = ZUKAN_DETAIL_COMMON_GetFont(key);
    for (i = 0; i < 4; i++) {
        *(u32 *)((u8 *)p + i * 0x44 + 0xc) = 0;
        *(u32 *)((u8 *)p + i * 0x44 + 0x10) = 0;
    }
    for (i = 0; i < 2; i++)
        *(u32 *)((u8 *)p + 0x13c + i * 4) = 0;
    W(0x144) = 0;
    W(0x124) = 1;
    PW(0x6a0) = GFL_USE_AddMainTask(ZUKAN_DETAIL_FORM_ApplyPendingDisplay, p, 1);
    ZUKAN_DETAIL_FORM_CreatePrintQueues(heap, p, key);
    PW(0x6a4) = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    PW(0x6a8) = ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(PW(0x6a4));
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(PW(0x6a8));
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, PW(0x6a4));
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, PW(0x6a8));
    PW(0x6ac) = ZUKAN_DETAIL_COMMON_CreatePaletteAnimDefault(*heap);
    W(0x6b0) = 0;
    W(0x6b4) = 1;
    W(0x6b8) = 0;
    W(0x6d4) = 0;
    W(0x6d8) = 0;
    W(0x6dc) = 1;
    W(0x6e0) = 1;
    return 1;
}

int ZUKAN_DETAIL_FORM_Exit(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    void *sys;
    u8 i;
    sys = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(p->w5bc);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(p->w5b8);
    ZUKAN_DETAIL_COMMON_SetBgScrollPacked(7, p->w5b4);
    ZUKAN_DETAIL_FORM_DeleteArrowActors(heap, p, key);
    for (i = 0; i < 2; i++) {
        if (((struct Ov208Form *)p)->obj[i] != 0)
            ZUKAN_DETAIL_FORM_DeleteIconActor((int)(((struct Ov208Form *)p)->res[i]), (int)(((struct Ov208Form *)p)->obj[i]));
        ((struct Ov208Form *)p)->obj[i] = 0;
    }
    ZUKAN_DETAIL_FORM_ReleaseIconResources(heap, p, key);
    ZUKAN_DETAIL_FORM_DeleteTextWindows(heap, p, key);
    ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(sys, 0);
    ZUKAN_DETAIL_COMMON_DeletePaletteAnim(p->w6ac);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(p->w6a8);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(p->w6a4);
    ZUKAN_DETAIL_FORM_DeletePrintQueues(heap, p, key);
    TCB_DeleteTask((struct Node *)p->w6a0);
    ZUKAN_DETAIL_PROCSYS_FreeBuffer(proc);
    return 1;
}

int ZUKAN_DETAIL_FORM_Main(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    void *res;
    void *scene;
    void *icon;
    u8 i;
    int done;
    int settled;
    int ready;
    int idle;

    res = ZUKAN_DETAIL_COMMON_GetDisplay(key);
    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    icon = ZUKAN_DETAIL_COMMON_GetCursorValue(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                BG_SYS_FillScrollArea(i, 0, 0);
                BG_SYS_FillScrollArea(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        BG_SYS_SetVisibleLayer(0, 0);
        BG_SYS_SetVisibleLayer(2, 2);
        BG_SYS_SetVisibleLayer(3, 3);
        BG_SYS_SetVisibleLayer(6, 1);
        BG_SYS_SetVisibleLayer(4, 3);
        BG_SYS_SetVisibleLayer(7, 2);
        ZUKAN_DETAIL_TOUCHBAR_SetBgPriority(scene, 2);
        GX_SetGraphicsMode(1, 0, 1);
        ZUKAN_DETAIL_GRAPHIC_Init3dSystem(res, *heap);
        ZUKAN_DETAIL_FORM_InitModelSystem(heap, p, key);
        ZUKAN_DETAIL_FORM_CreateTextWindows((u16 *)heap, (struct Ov208Form *)p, key);
        ZUKAN_DETAIL_FORM_CreateArrowActors(heap, p, key);
        ZUKAN_DETAIL_FORM_RefreshFormEntries(heap, p, key);
        ZUKAN_DETAIL_FORM_LoadIconResources(heap, p, key);
        ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)((u8 *)p + W(0x144) * 4 + 0x13c)), 1);
        MCSS_SetVanishFlag((void *)W(0xc));
        MCSS_SetPaletteFade((struct McssFade *)W(0xc), 16, 16, 0, 0);
        if (W(0x94) != 0) {
            MCSS_SetVanishFlag((void *)W(0x94));
            MCSS_SetPaletteFade((struct McssFade *)W(0x94), 16, 16, 0, 0);
        }
        W(0x5b4) = ZUKAN_DETAIL_COMMON_LoadBgPaletteRange(0, *heap, 7, 1, 1, 0, 0x9f, 2, 12, 0x23, 0);
        W(0x5b8) = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, 3, 3, 1, 2);
        W(0x5bc) = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, 3, 4, 2, 3);
        ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(W(0x6ac));
        ZUKAN_DETAIL_COMMON_StartFadeIn(W(0x6ac));
        break;
    case 1:
        *seq = 2;
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(0, W(0x6a4));
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(1, W(0x6a8));
        ZUKAN_DETAIL_FORM_SetActorsNormalMode(heap, p, key);
        break;
    case 2:
        *seq = 3;
        break;
    case 3:
        done = 1;
        if (MCSS_CheckPaletteFade((void *)W(0xc)) != 0)
            done = 0;
        if (W(0x94) != 0 && MCSS_CheckPaletteFade((void *)W(0x94)) != 0)
            done = 0;
        if (done) {
            *seq = 4;
            ZUKAN_DETAIL_COMMON_StartFadeOut(W(0x6ac));
            if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) != 2) {
                ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 3, ZUKAN_DETAIL_COMMON_GetMaxValue(key) > 1);
                ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scene, 0);
            } else {
                ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scene, 3);
            }
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 0);
            ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scene, GAME_DATA_CheckSaveFlag(ZUKAN_DETAIL_COMMON_GetSource(key), 20));
            if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
                ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 3);
                ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
            }
            MCSS_ResetVanishFlag((void *)W(0xc));
            MCSS_SetPaletteFade((struct McssFade *)W(0xc), 16, 0, -2, 0);
            if (W(0x94) != 0) {
                MCSS_ResetVanishFlag((void *)W(0x94));
                MCSS_SetPaletteFade((struct McssFade *)W(0x94), 16, 0, -2, 0);
            }
        }
        break;
    case 4:
        done = 1;
        if (MCSS_CheckPaletteFade((void *)W(0xc)) != 0)
            done = 0;
        if (W(0x94) != 0 && MCSS_CheckPaletteFade((void *)W(0x94)) != 0)
            done = 0;
        if (ZUKAN_DETAIL_COMMON_IsFadeBusy(W(0x6ac)) == 0 && ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 2
            && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2 && done) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x6b0) != 0) {
            *seq = 6;
            for (i = 0; i < 4; i++) {
                if (OBJ(i) != 0)
                    MCSS_SetPaletteFade((struct McssFade *)OBJ(i), 0, 0, 0, 0);
            }
        } else {
            ZUKAN_DETAIL_FORM_UpdateState(heap, p, key);
        }
        break;
    case 6:
        settled = 1;
        for (i = 0; i < 4; i++) {
            if (OBJ(i) != 0 && MCSS_CheckPaletteFade((void *)OBJ(i)) != 0) {
                settled = 0;
                break;
            }
        }
        if (settled) {
            *seq = 7;
            ZUKAN_DETAIL_COMMON_StartFadeOutAlt(W(0x6ac));
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (W(0x6b0) == 2)
                ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(scene, 0);
            for (i = 0; i < 4; i++) {
                if (OBJ(i) != 0)
                    MCSS_SetPaletteFade((struct McssFade *)OBJ(i), 0, 16, -2, 0);
            }
        }
        break;
    case 7:
        ready = 0;
        idle = 1;
        for (i = 0; i < 4; i++) {
            if (OBJ(i) != 0 && MCSS_CheckPaletteFade((void *)OBJ(i)) != 0) {
                idle = 0;
                break;
            }
        }
        if (ZUKAN_DETAIL_COMMON_IsFadeBusy(W(0x6ac)) == 0 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0 && idle) {
            if (W(0x6b0) == 2) {
                if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 0)
                    ready = 1;
            } else {
                ready = 1;
            }
        }
        if (ready)
            *seq = 8;
        break;
    case 8:
        *seq = 9;
        ZUKAN_DETAIL_FORM_SetActorsAlphaMode(heap, p, key);
        ZUKAN_DETAIL_COMMON_SetBrightnessNone(0, PW(0x6a4));
        ZUKAN_DETAIL_COMMON_SetBrightnessNone(1, PW(0x6a8));
        break;
    case 9:
        for (i = 0; i < 4; i++)
            ZUKAN_DETAIL_FORM_DestroyModelItem((struct Ov208Mdl *)(&p->item[i]), (int)(W(8)));
        ZUKAN_DETAIL_FORM_ExitModelSystem(heap, p, key);
        ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(res);
        GX_SetGraphicsMode(1, 0, 0);
        return 1;
    }
    if (W(8) != 0) {
        TCB_Main((struct Ctx *)W(0x120));
        MCSS_Main((char *)W(8));
        for (i = 0; i < 4; i++)
            ZUKAN_DETAIL_FORM_StopModelAnim(&p->item[i]);
    }
    if (*seq >= 3) {
        ZUKAN_DETAIL_FORM_UpdateArrowAnim(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateSlideLeft(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateScrollInput(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateSlideRight(heap, p, key);
        ZUKAN_DETAIL_FORM_UpdateSlideBoth(heap, p, key);
        ZUKAN_DETAIL_COMMON_TickFlashEffect(W(0x5b8));
        ZUKAN_DETAIL_COMMON_TickFlashEffect(W(0x5bc));
    }
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(W(0x6a4), W(0x6a8));
    ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(W(0x6ac));
    ZUKAN_DETAIL_FORM_UpdatePrintQueues(heap, (struct Ov208Form *)p, key);
    return 0;
}

void ZUKAN_DETAIL_FORM_HandleKeyEvent(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int ev)
{
    struct Ov208Ent bufA[64];
    struct Ov208Ent bufB[64];
    struct Ov208Sel sA;
    struct Ov208Sel sB;
    u32 id;
    void *sys;
    int flag;
    u32 cur;
    u32 id2;
    u32 n;
    u32 k;
    if (p == 0)
        return;
    sys = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    flag = 0;
    W(0x698) = flag;
    W(0x6d4) = flag;
    switch (ev) {
    case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11:
    case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20:
        W(0x6b4) = flag;
        break;
    }
    switch (ev) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        flag = 1;
        W(0x6b4) = 1;
        break;
    }
    switch (ev) {
    case 0xc:
    case 0x1e:
        if (W(0x6b8) == 0) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(key);
            if (id != ZUKAN_DETAIL_COMMON_GetCurrentEntry(key))
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(key);
            cur = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            while (id != cur) {
                ZUKAN_DETAIL_FORM_BuildFormEntries(heap, key, bufA, &sA.count, &sA.groups, &sA.twos, &sA.sel, &sA.next);
                if (sA.count >= 2)
                    break;
                ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(key);
                cur = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            }
            if (id != cur) {
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
                if (sA.count >= 3)
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 1);
                else
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 0);
            }
        }
        break;
    case 0xd:
    case 0x1f:
        if (W(0x6b8) == 0) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(key);
            if (id != ZUKAN_DETAIL_COMMON_GetCurrentEntry(key))
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(key);
            id2 = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            while (id != id2) {
                ZUKAN_DETAIL_FORM_BuildFormEntries(heap, key, bufB, &sB.count, &sB.groups, &sB.twos, &sB.sel, &sB.next);
                if (sB.count >= 2)
                    break;
                ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(key);
                id2 = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
            }
            if (id != id2) {
                ZUKAN_DETAIL_FORM_RebuildModels(heap, p, key);
                if (sB.count >= 3)
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 1);
                else
                    ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(sys, 0);
            }
        }
        break;
    case 0x1c:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8)++;
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8)++;
                n = H(k);
                H(k + 8) = H(k + 8) % n;
            }
            ZUKAN_DETAIL_FORM_RebuildSideModels(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x1d:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8) += (u16)(n - 1);
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8) += (u16)(H(k) - 1);
                H(k + 8) = H(k + 8) % (u32)H(k);
            }
            ZUKAN_DETAIL_FORM_RebuildSideModels(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x20:
        if (H(0x548) >= 2) {
            ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 5);
            W(0x6d8) = 1;
            W(0x6dc) = 0;
            W(0x6e0) = 0;
        } else {
            W(0x6d8) = 1;
            W(0x6dc) = 1;
            W(0x6e0) = 0;
        }
        break;
    }
    switch (ev) {
    case 0:
        break;
    case 1:
    case 2:
        W(0x6b0) = 2;
        return;
    case 6:
    case 7:
    case 8:
        W(0x6b0) = 1;
        return;
    case 3:
    case 24:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 4:
    case 25:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 5:
        GAME_DATA_SetSaveFlag(ZUKAN_DETAIL_COMMON_GetSource(key), 0x14, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(sys));
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 22:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 23:
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    case 21:
        if (W(0x6b8) == 4)
            ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 6);
        return;
    case 26:
        if (W(0x6d8) != 0) {
            W(0x6e0) = 1;
            if (W(0x6dc) != 0) {
                W(0x6d8) = 0;
                ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
                return;
            }
        }
        return;
    default:
        if (flag != 0)
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sys);
        return;
    }
}

void ZUKAN_DETAIL_FORM_DrawModels(u32 a, u32 b, u32 c, struct Ov208Form *p)
{
    if (p != 0 && *(struct McssSys * *)&p->cam != 0)
        MCSS_Draw(*(struct McssSys * *)&p->cam);
}

void ZUKAN_DETAIL_FORM_ApplyPendingDisplay(int unused, char *p)
{
    ZUKAN_DETAIL_COMMON_TransferPalettes(*(char * *)&((struct Ov208Form *)p)->w6ac);
}

void ZUKAN_DETAIL_FORM_BuildFormLabelText(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, u32 *outStr, u32 *outB, int *outC, int *outD,
                         u16 idx)
{
    u32 str = 0;
    u32 b = 0;
    int c = 0;
    int d = 0;
    u16 k;
    u32 ws;
    u32 src;
    u16 n;
    u16 i;

    k = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    switch (*(u32 *)((u8 *)p + 0x148 + idx * 16)) {
    case 0:
        ws = (u32)WORDSET_CreateDefault(*heap);
        src = p->str[2];
        str = (u32)STRBUF_Create(0x40, *heap);
        WORDSET_Callback((struct WordSet *)ws, 0, k);
        WORDSET_CopyTaggedText((struct WordSet *)ws, (void *)str, (void *)src);
        WORDSET_DeleteStrbufED04((struct WordSet *)ws);
        c = 1;
        break;
    case 1:
        switch (*(u16 *)((u8 *)p + 0x150 + idx * 16)) {
        case 0:
            str = p->str[3];
            break;
        case 1:
            str = p->str[4];
            break;
        }
        break;
    case 2:
        n = *(u16 *)((u8 *)p + 0x150 + idx * 16);
        for (i = 0; i != n; i++) {
            k = (*(u16 **)((u8 *)p + 0x594))[k];
            if (k == 0)
                break;
        }
        str = (u32)MSGDATA_AllocString((struct MsgBank *)p->msg2, k);
        c = 1;
        break;
    }
    switch (*(u32 *)((u8 *)p + 0x14c + idx * 16)) {
    case 0:
    case 1:
        break;
    case 2:
        b = p->str[5];
        d = 0;
        break;
    }
    *outStr = str;
    *outB = b;
    *outC = c;
    *outD = d;
}

void ZUKAN_DETAIL_FORM_CreateTextWindows(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    struct Ov208WinTbl t;
    u32 size;
    u32 bmp;
    u32 s;
    u8 i;

    t = data_021C8830;
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 4, 0, 0, 0x20, *heap);
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 5; i++) {
        p->win[i] = BMP_WIN_Create(t.d[i][0], t.d[i][1], t.d[i][2], t.d[i][3], t.d[i][4],
                                  t.d[i][5], t.d[i][6]);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i])), 0);
        BMP_WIN_TransferChars((struct Descriptor *)p->win[i]);
    }
    p->msg = (u32)MSGDATA_CreateFromArchive(0, 2, 0xea, *heap);
    p->msg2 = (u32)MSGDATA_CreateFromArchive(0, 2, 0xf4, *heap);
    p->marc = (u32)ARC_UTIL_LoadMemberWithSize(0x62, 0, 0, *heap, &size);
    bmp = (u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[2]);
    s = (u32)MSGDATA_AllocString((struct MsgBank *)p->msg, 0xb8);
    PRINTSYS_PrintQueColor((void *)p->print[2], bmp, 0, 1, s, p->font, 0x3c40);
    STRBUF_Delete((struct U16Vec *)s);
    s = (u32)MSGDATA_AllocString((struct MsgBank *)p->msg, 0xb9);
    PRINTSYS_PrintQueColor((void *)p->print[2], bmp, 0, 0x11, s, p->font, 0x3c40);
    STRBUF_Delete((struct U16Vec *)s);
    p->active[2] = 1;
    ZUKAN_DETAIL_FORM_FlushPrintWindow(heap, (struct Ov208Form *)p, key, 2);
    for (i = 0; i < 6; i++)
        p->str[i] = (u32)MSGDATA_AllocString((struct MsgBank *)p->msg, data_021C8794[i]);
}

void ZUKAN_DETAIL_FORM_DeleteTextWindows(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;
    for(i=0;i<5;i++) {
        *(u32 *)((u8 *)p+i*4+0x568)=0;
        PRINTSYS_QUE_Clear(*(struct PrintSys **)((u8 *)p+i*4+0x57c));
        BMP_WIN_Delete(*(struct Descriptor **)((u8 *)p+i*4+0x554));
    }
    for(i=0;i<6;i++)STRBUF_Delete(*(struct U16Vec **)((u8 *)p+i*4+0x59c));
    MSGDATA_Delete(*(struct Rec * *)&p->msg);
    MSGDATA_Delete(*(struct Rec * *)&p->msg2);
    GFL_HEAP_Free((void *)p->marc);
}

void ZUKAN_DETAIL_FORM_CreatePrintQueues(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->print[i] = PRINTSYS_QUE_Create((void *)(*heap));
        p->active[i] = 0;
    }
}

void ZUKAN_DETAIL_FORM_DeletePrintQueues(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->active[i] = 0;
        PRINTSYS_QUE_Clear((struct PrintSys *)p->print[i]);
        PRINTSYS_QUE_Delete((struct PrintSys *)p->print[i]);
    }
}

void ZUKAN_DETAIL_FORM_UpdatePrintQueues(void *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 5; i++) {
        PRINTSYS_QUE_Main((struct PrintSys *)p->print[i]);
        ZUKAN_DETAIL_FORM_FlushPrintWindow((u16 *)a0, (struct Ov208Form *)((struct Ov208Form *)p), key, i);
    }
}

void ZUKAN_DETAIL_FORM_FlushPrintWindow(void *a0, struct Ov208Form *p, struct Ov208Ctx *a2, int i)
{
    u32 w;

    if (p->active[i] != 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)p->print[i], (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[i]))) == 0) {
        w = p->win[i];
        BMP_WIN_TransferChars((struct Descriptor *)w);
        BMP_WIN_MakeScreen((struct Cfg *)w);
        BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)w));
        p->active[i] = 0;
    }
}

void ZUKAN_DETAIL_FORM_DrawSpeciesLabels(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;
    u16 species;
    u16 width;
    struct Bmp *bmp;
    struct Bmp *bmp2;
    struct StrObj *text;
    struct WordSet *ws;
    struct WordSet *ws2;
    struct U16Vec *str;
    void *src;
    void *src2;
    for (i = 0; i <= 1; i++) {
        p->active[i] = 0;
        PRINTSYS_QUE_Clear((struct PrintSys *)p->print[i]);
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)p->win[i]), 0);
    }
    species = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    bmp = BMP_WIN_GetBmp((struct Descriptor *)p->win[0]);
    text = MSGDATA_AllocString(gSpeciesNameBank, species);
    width = GF_FONT_MeasureWidestLine(text, p->font, 0);
    PRINTSYS_PrintQueColor((void *)p->print[0], (u32)bmp, (s16)((u16)((BMP_GetWidth(bmp) - width) / 2)), (s16)1, (u32)text, p->font, 0x3c40);
    p->active[0] = 1;
    STRBUF_Delete((struct U16Vec *)text);
    bmp2 = BMP_WIN_GetBmp((struct Descriptor *)p->win[1]);
    ws = WORDSET_CreateDefault(*heap);
    src = (void *)p->str[0];
    str = STRBUF_Create(8, *heap);
    WORDSET_SetSlotNumber(ws, 0, p->f54a, 2, 1, 1);
    WORDSET_CopyTaggedText(ws, str, src);
    PRINTSYS_PrintQueColor((void *)p->print[1], (u32)bmp2, (s16)0, (s16)1, (u32)str, p->font, 0x3c40);
    STRBUF_Delete(str);
    WORDSET_DeleteStrbufED04(ws);
    ws2 = WORDSET_CreateDefault(*heap);
    src2 = (void *)p->str[1];
    str = STRBUF_Create(8, *heap);
    WORDSET_SetSlotNumber(ws2, 0, p->f54c, 2, 1, 1);
    WORDSET_CopyTaggedText(ws2, str, src2);
    PRINTSYS_PrintQueColor((void *)p->print[1], (u32)bmp2, (s16)0, (s16)0x11, (u32)str, p->font, 0x3c40);
    STRBUF_Delete(str);
    WORDSET_DeleteStrbufED04(ws2);
    p->active[1] = 1;
    for (i = 0; i <= 1; i++)
        ZUKAN_DETAIL_FORM_FlushPrintWindow(heap, (struct Ov208Form *)p, key, i);
}

void ZUKAN_DETAIL_FORM_DrawFormLabel(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int i, u32 print, u32 win,
                         u32 *active, u16 idx)
{
    u32 bmp;
    u16 width;
    u32 strA;
    u32 strB;
    int freeA;
    int freeB;
    int y;
    YPos y2;
    u16 w;

    bmp = (u32)BMP_WIN_GetBmp((struct Descriptor *)win);
    width = BMP_GetWidth((const struct Bmp *)bmp);
    ZUKAN_DETAIL_FORM_BuildFormLabelText((u16 *)heap, p, key, (u32 *)&strA, (u32 *)&strB, (int *)&freeA, (int *)&freeB, idx);
    y = 1;
    y2 = 0x11;
    if (strB == 0)
        y = 9;
    w = GF_FONT_MeasureWidestLine((struct StrObj *)strA, p->font, 0);
    PRINTSYS_PrintQueColor((void *)print, bmp, (s16)((u16)((width - w) / 2)), (s16)y, strA, p->font, 0x3c40);
    if (strB != 0) {
        w = GF_FONT_MeasureWidestLine((struct StrObj *)strB, p->font, 0);
        PRINTSYS_PrintQueColor((void *)print, bmp, (s16)((u16)((width - w) / 2)), (s16)y2, strB, p->font, 0x3c40);
    }
    if (strA != 0 && freeA != 0)
        STRBUF_Delete((struct U16Vec *)strA);
    if (strB != 0 && freeB != 0)
        STRBUF_Delete((struct U16Vec *)strB);
    *active = 1;
    ZUKAN_DETAIL_FORM_FlushPrintWindow(heap, (struct Ov208Form *)p, key, i);
}

void ZUKAN_DETAIL_FORM_DrawFormLabelMain(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    p->active[3] = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)p->print[3]);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[3])), 0);
    ZUKAN_DETAIL_FORM_DrawFormLabel(heap, p, key, 3, p->print[3], p->win[3], &p->active[3], p->sel);
}

void ZUKAN_DETAIL_FORM_DrawFormLabelSub(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    p->active[4] = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)p->print[4]);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->win[4])), 0);
    switch (p->state) {
    case 0:
        BMP_WIN_TransferChars((struct Descriptor *)p->win[4]);
        break;
    case 4:
        if (p->count >= 2)
            ZUKAN_DETAIL_FORM_DrawFormLabel(heap, p, key, 4, p->print[4], p->win[4], &p->active[4], p->sel2);
        break;
    }
}

void ZUKAN_DETAIL_FORM_UpdateBgScrollForState(void *unused, struct Ov208Form *p, struct Ov208Ctx *key)
{
    switch (p->state) {
    case 0:
        BG_SYS_ResetSlot(2, 0, -0x40);
        break;
    case 4:
        if (p->count >= 2)
            BG_SYS_ResetSlot(2, 0, 0);
        else
            BG_SYS_ResetSlot(2, 0, -0x40);
        break;
    }
}

extern struct Ctx *TCB_Init(u32 capacity, struct Ctx *c);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))

struct Sub02014CB8Obj;

struct Sub150;

struct Stats;

struct Personal;

struct Ov208MonArc {
    u8 d[0x24];
};

struct Ov208Cam {
    u32 pad0[6];
    Vec ofs;
};

struct Ov208Turn {
    int side;
    u8 *scene;
    u8  count;
    u8  pad9[3];
    int done;
};

typedef signed int     s32;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u8  b6;
    u8  b7;
} Ov208ObjPos;

typedef struct 
{
  u32 v[3];
} Ov208Gender3;

typedef struct 
{
  u32 v[2];
} Ov208Shiny2;

typedef enum { SIDE_0 = 0, SIDE_1 = 1 } Side;

typedef short          s16;

struct Ov208CellHdr {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
} Ov208Pos;

struct Ov208Cursor {
    u8  slot;
    u8  pad;
    s16 x;
    s16 y;
};

struct Ov208PoseEnt {
    u32 species;
    u32 form;
    u32 gender;
    u32 fc;
    u32 f10;
    u32 side;
    u32 f18;
    VecF pos[5];
};

extern void *MCSS_Init(u32 id, void *heap);

extern void MCSS_SetTextureTransAdrs(void *p, u32 v);

extern void MCSS_SetOrthoMode(void *obj);

extern void MCSS_OpenHandle(struct Sub02014CB8Obj *o, u32 x);

extern u32  TCB_GetTaskOffset(u32 n);

extern void MCSS_SetTaskSystem(u8 *p, u32 value);

extern void MCSS_CloseHandle(struct Sub02014CB8Obj *o);

extern void MCSS_Exit(u8 *a0);

extern void TCB_Noop(int);

extern void MCSS_TOOL_SetSpindaSpotHook(int a0, int a1);

extern void MCSS_TOOL_MakeAddWorkFromParam(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out, u32 a6);

extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);

extern void MCSS_SetShadowVanishFlag(char *p, int v);

extern void MCSS_SetAnmStopFlag(void *p);

extern void MCSS_SetScale(void *p, u32 *src);

extern void MCSS_Del(void *sys, void *obj);

extern s16 MCSS_GetOfsX(void *p);

extern void MCSS_SetOfsPosition(void *p, u32 *src);

extern void MCSS_GetPosition(void *p, u32 *out);

extern void *MCSS_GetAnimCtrl(void *p);

extern void NNS_G2dSetCellAnimationParam(int p0, int p1, int p2, int p3);

extern void NNS_G2dRestartMCAnimation(struct Obj *x);

extern void MCSS_ResetAnmStopFlag(void *p);

extern void MCSS_RequestAnimeStopAtStart(void *o);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void ARC_TOOL_DeleteHandle(void *);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern struct Obj *CLACT_CreateActor(void *owner, unsigned int res, unsigned int j, unsigned int k, const void *pos, unsigned short f, unsigned short heap);

extern void CLACT_SetActorAutoAnim(struct Obj *obj, u32 v);

extern void *POKE_PERSONAL_Create(u32 a, int b, u32 c);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *p);

extern u16 ZUKAN_SAVE_GetFormCount(u32 id);

extern u32 ZUKAN_SAVE_HasSeenGenderForm(u8 *p, u16 id, u32 sel, u32 alt, u32 form);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *p, u32 which);

extern void MCSS_SetPosition(void *p, u32 *src);








extern void GFL_USE_PlaySeDefaultVolume(u32 se);

extern void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(void *s, u32 on);

extern void ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(void *s, int v);

extern void ZUKAN_DETAIL_TOUCHBAR_SetMode(void *s, u32 mode, u32 kind, u32 flag);







extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32  TOUCHPANEL_GetPointCont(u32 *x, u32 *y);

extern void ZUKAN_DETAIL_FORM_CopyModelPosition(struct Ov208Mdl *u, int k, VecF *v);



extern void ZUKAN_SAVE_UpdateViewFlags(struct Blk37 *p, u16 id, u32 sel, u32 alt, u32 form);


u32 ZUKAN_DETAIL_FORM_AddModel(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny, u32 personality, u32 extra);

void ZUKAN_DETAIL_FORM_DeleteModel(int a, int b);

void ZUKAN_DETAIL_FORM_CenterModelOffset(u32 obj);

void ZUKAN_DETAIL_FORM_GetModelPosition(u32 obj, Vec *out);

void ZUKAN_DETAIL_FORM_CreateModelItem(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);

void ZUKAN_DETAIL_FORM_DestroyModelItem(struct Ov208Mdl *p, int a);

void ZUKAN_DETAIL_FORM_InitAnimState(struct Ov208AnmState *s, int side, struct Ov208Form *form);

void ZUKAN_DETAIL_FORM_RestartModelAnim(struct Ov208Mdl *s);

void ZUKAN_DETAIL_FORM_SignalAnimDone(int *p);

void ZUKAN_DETAIL_FORM_OnAnimStopRequest(struct Ov208Turn *t);

void ZUKAN_DETAIL_FORM_ToggleModelVisibility(u16 *heap,struct Ov208Form *p,struct Ov208Ctx *key);

u32 ZUKAN_DETAIL_FORM_CreateIconActor(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg);

void ZUKAN_DETAIL_FORM_DeleteIconActor(int a, int b);

void ZUKAN_DETAIL_FORM_PlaceModelItem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int a, int b, int pose, u16 idx);

void ZUKAN_DETAIL_FORM_CreateCurrentIcon(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, u16 idx);

void ZUKAN_DETAIL_FORM_RebuildModelsSwapped(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_RebuildModelsSingle(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_SwapIconActor(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);

int ZUKAN_DETAIL_FORM_HandleTouchArrows(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateArrowVisibility(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_UpdateCursorMarkers(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2);

void ZUKAN_DETAIL_FORM_UpdateScrollMarkers(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *a2);

u32 ZUKAN_DETAIL_FORM_HandleScrollTouch(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key);

int ZUKAN_DETAIL_FORM_HandleScrollKey(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *a2);

void ZUKAN_DETAIL_FORM_GetScrollSlotRange(int n, int i, u8 *lo, u8 *mid, u8 *hi);

u16 ZUKAN_DETAIL_FORM_GetScrollSlotAtX(u16 n, u8 x);

u16 ZUKAN_DETAIL_FORM_CountEntriesBefore(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2, u16 skip, u16 stop);

u16 ZUKAN_DETAIL_FORM_GetEntryIndex(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2, u16 skip, u16 want);

void ZUKAN_DETAIL_FORM_AdvanceSelection(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_PlaceSideModels(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2);

void ZUKAN_DETAIL_FORM_RebuildSideItems(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_SwapItems(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_FORM_GetModelOffsets(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality, u32 side, u32 extra);

void ZUKAN_DETAIL_FORM_ConvertModelPosition(struct Ov208Mdl *m, int i, Vec *out);

void ZUKAN_DETAIL_FORM_SelectModelPosition(int a, int b, int c);

extern const char data_021C8E64[];

extern const Vec data_021C8804;

extern struct Ov208Cam data_021C8E40;

extern const Ov208Gender3 data_021C8810;

extern const Ov208Shiny2 data_021C87FC;

extern const u8 data_021C87A0[4][8];

extern s16  FX_SinCosTable_[];

extern const VecF data_021C87C0[5];

extern const struct Ov208PoseEnt data_021C8854[15];

void ZUKAN_DETAIL_FORM_InitModelSystem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    p->cam = (u32)MCSS_Init(4, (void *)(*heap));
    MCSS_SetTextureTransAdrs((void *)p->cam, 0);
    MCSS_SetOrthoMode((void *)p->cam);
    MCSS_OpenHandle((struct Sub02014CB8Obj *)p->cam, POKEGRA_GetArcID());
    p->mem = GFL_HEAP_Alloc(*heap, TCB_GetTaskOffset(4), 0, data_021C8E64, 0xa53);
    p->heap3d = TCB_Init(4, p->mem);
    MCSS_SetTaskSystem((u8 *)p->cam, (u32)p->heap3d);
}

/*
 * Releases the file and the two allocations held in the 0x10-byte records.
 */
void ZUKAN_DETAIL_FORM_ExitModelSystem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    MCSS_CloseHandle((struct Sub02014CB8Obj *)p->cam);
    MCSS_Exit((u8 *)p->cam);
    TCB_Noop((int)p->heap3d);
    GFL_HEAP_Free(p->mem);
}

u32 ZUKAN_DETAIL_FORM_AddModel(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny,
                        u32 personality, u32 extra)
{
    Vec scale;
    struct Ov208MonArc arc;
    u32 obj;

    scale = data_021C8804;
    if (species == 0x147)
        MCSS_TOOL_SetSpindaSpotHook((int)sys, extra);
    MCSS_TOOL_MakeAddWorkFromParam(species, gender, side, form, shiny, (struct Stats *)(&arc), personality);
    obj = (u32)MCSS_Add(sys, 0, 0, 0, (const struct Sub150 *)(&arc));
    MCSS_SetShadowVanishFlag((char *)obj, 1);
    MCSS_SetAnmStopFlag((void *)obj);
    MCSS_SetScale((void *)obj, (u32 *)(&scale));
    ZUKAN_DETAIL_FORM_CenterModelOffset(obj);
    return obj;
}

/*
 * BLOCKED.  MATCH: the call at +0x08 targets 02015EA0, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void ZUKAN_DETAIL_FORM_DeleteModel(int a, int b)
{
    MCSS_SetVanishFlag((void *)b);
    MCSS_Del((void *)a, (void *)b);
}

void ZUKAN_DETAIL_FORM_CenterModelOffset(u32 obj)
{
    Vec v;
    float y;

    y = 0.25f * -(float)MCSS_GetOfsX((void *)obj);
    v.x = FX_F32_TO_FX32(y);
    v.y = 0;
    v.z = 0;
    MCSS_SetOfsPosition((void *)obj, (u32 *)(&v));
}

void ZUKAN_DETAIL_FORM_GetModelPosition(u32 obj, Vec *out)
{
    Vec v;

    MCSS_GetPosition((void *)obj, (u32 *)(&v));
    out->x = v.x + data_021C8E40.ofs.x;
    out->y = v.y + data_021C8E40.ofs.y;
    out->z = v.z + data_021C8E40.ofs.z;
}

void ZUKAN_DETAIL_FORM_CreateModelItem(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5,
                         u32 a6, u32 a7, u32 a8, u32 a9)
{
    m->obj = ZUKAN_DETAIL_FORM_AddModel(sys, species, a4, a5, a6, a7, a8, a9);
    m->state = GFL_HEAP_Alloc(heap, 0x10, 1, data_021C8E64, 0xab1);
    NNS_G2dSetCellAnimationParam((int)MCSS_GetAnimCtrl((void *)m->obj), 1, (int)m->state, (int)ZUKAN_DETAIL_FORM_OnAnimStopRequest);
    ZUKAN_DETAIL_FORM_GetModelOffsets(m->pos, species, a4, a5, a6, a7, a8, a9);
}

void ZUKAN_DETAIL_FORM_DestroyModelItem(struct Ov208Mdl *p, int a)
{
    if (p->obj != 0)
        ZUKAN_DETAIL_FORM_DeleteModel(a, p->obj);
    p->obj = 0;
    if (p->state != 0)
        GFL_HEAP_Free((void *)p->state);
    p->state = 0;
}

void ZUKAN_DETAIL_FORM_InitAnimState(struct Ov208AnmState *s, int side, struct Ov208Form *form)
{
    s->f0 = side;
    s->form = form;
    s->f8 = 0;
    s->active = 0;
}

void ZUKAN_DETAIL_FORM_RestartModelAnim(struct Ov208Mdl *s)
{
    if (s->obj != 0 && s->state != 0) {
        void *r = MCSS_GetAnimCtrl((void *)s->obj);
        s->state->f8 = 0;
        s->state->active = 0;
        NNS_G2dRestartMCAnimation(r);
        MCSS_ResetAnmStopFlag((void *)s->obj);
    }
}

void ZUKAN_DETAIL_FORM_SignalAnimDone(int *p)
{
    if (p[0] == 0)
        return;
    if (p[1] == 0)
        return;
    *(int *)(p[1] + 0xc) = 1;
}

void ZUKAN_DETAIL_FORM_StopModelAnim(struct Ov208Mdl *p)
{
    void *anm;

    if (p->obj != 0 && p->state != 0) {
        anm = MCSS_GetAnimCtrl((void *)p->obj);
        if (p->state->active != 0) {
            MCSS_SetAnmStopFlag((void *)p->obj);
            NNS_G2dRestartMCAnimation(anm);
            p->state->active = 0;
        }
    }
}

void ZUKAN_DETAIL_FORM_OnAnimStopRequest(struct Ov208Turn *t)
{
    u8 *scene = t->scene;

    t->count++;
    if (t->count >= 2)
        t->done = 1;
    MCSS_RequestAnimeStopAtStart((void *)(*(u32 *)(scene + t->side * 0x44 + 0xc)));
}

void ZUKAN_DETAIL_FORM_ToggleModelVisibility(u16 *heap,struct Ov208Form *p,struct Ov208Ctx *key)
{
    if(p->w124) {
        MCSS_SetVanishFlag((void *)p->item[0].obj);
        if(p->item[2].obj)MCSS_SetVanishFlag((void *)p->item[2].obj);
        p->w124=0;
    } else {
        MCSS_SetVanishFlag((void *)p->item[1].obj);
        if(p->item[3].obj)MCSS_SetVanishFlag((void *)p->item[3].obj);
        p->w124=1;
    }
    ZUKAN_DETAIL_FORM_RebuildModelsSwapped(heap,p,key);
    if(p->w124) {
        MCSS_ResetVanishFlag((void *)p->item[0].obj);
        if(p->item[2].obj)MCSS_ResetVanishFlag((void *)p->item[2].obj);
    } else {
        MCSS_ResetVanishFlag((void *)p->item[1].obj);
        if(p->item[3].obj)MCSS_ResetVanishFlag((void *)p->item[3].obj);
    }
}

void ZUKAN_DETAIL_FORM_LoadIconResources(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    p->arc = ARC_TOOL_CreateHandle(7, *heap);
    p->j = CLACT_RegisterPaletteCompressed(p->arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0, *heap);
    p->k = CLACT_RegisterCellAnim(p->arc, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), *heap);
}

/*
 * Calls 0x0204AFD8 on +0x138, 0x0204ADA4 on +0x134 and 0x02049238 on +0x128 of the second argument.
 */
void ZUKAN_DETAIL_FORM_ReleaseIconResources(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    CLACT_ReleaseCellAnim(p->k);
    CLACT_ReleasePalette(p->j);
    ARC_TOOL_DeleteHandle((void *)p->arc);
}

u32 ZUKAN_DETAIL_FORM_CreateIconActor(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                        u32 form, u32 gender, u32 isEgg)
{
    Ov208ObjPos pos;
    u32 obj;

    pos.x = 0x80;
    pos.y = 0x80;
    pos.z = 1;
    pos.b6 = 1;
    pos.b7 = 0;
    *res = CLACT_RegisterCharacter((void *)arc, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)CLACT_CreateActor((void *)owner, *res, j, k, &pos, 1, heap);
    CLACT_SetActorAutoAnim((struct Obj *)obj, 0);
    CLACT_SetActorPaletteOffset((struct Obj *)obj, POKE_TOOL_CalcIconPalette(species, form, gender, isEgg), 0);
    CLACT_SetActorObjMode((struct Actor *)obj, 0);
    return obj;
}

/*
 * Forwards its second argument to CLACT_DeleteActor and then the first to
 * CLACT_ReleaseCharacter.
 */
void ZUKAN_DETAIL_FORM_DeleteIconActor(int a, int b)
{
    CLACT_DeleteActor((struct Obj *)b);
    CLACT_ReleaseCharacter(a);
}

void ZUKAN_DETAIL_FORM_BuildFormEntries(u16 *heap, struct Ov208Ctx *key, struct Ov208Ent *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next)
{
  Ov208Gender3 genders = data_021C8810;
  Ov208Shiny2 shinies = data_021C87FC;
  u16 species = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
  void *pd = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(key));
  u32 h = (u32)POKE_PERSONAL_Create(species, 0, *heap);
  u32 ratio;
  u32 forms;
  u32 curGender;
  u32 curShiny;
  u32 curForm;
  u16 cur;
  u16 n = 0;
  u8 j;
  u8 k;
  u32 found;
  u32 g;
  u32 s;
  u8 m;
  u16 prev;
  u32 t;
  u32 i;
  POKE_PERSONAL_GetParam((const struct Personal *)h, 0x20);
  ratio = POKE_PERSONAL_GetParam((const struct Personal *)h, 0x14);
  POKE_PERSONAL_Delete((void *)h);
  forms = ZUKAN_SAVE_GetFormCount(species);
  ZUKAN_SAVE_GetViewGenderAndForm(pd, species, &curGender, &curShiny, &curForm, *heap);
  cur = 0;
  {
    u32 en[3] = {0, 0, 0};
    switch (ratio)
    {
      case 0:
        en[0] = 1;
        break;

      case 0xfe:
        en[1] = 1;
        break;

      case 0xff:
        en[2] = 1;
        break;

      default:
        en[0] = 1;
        en[1] = 1;
        break;

    }

    for (i = 0; i < forms; i++)
    {
      u32 seen[2] = {0, 0};
      for (j = 0; j < 3; j++)
      {
        if (en[j] != 0)
        {
          g = genders.v[j];
          for (k = 0; k < 2; k++)
          {
            found = 0;
            s = shinies.v[k];
            if (((curForm == i) && (curShiny == s)) && (curGender == g))
            {
              cur = n;
              found = 1;
            }
            else
              if ((((forms < 2) || (curForm != i)) || (curShiny != s)) && (ZUKAN_SAVE_HasSeenGenderForm(pd, species, g, s, i) != 0))
            {
              found = 1;
            }
            if (found)
            {
              if (((forms >= 2) && (seen[k] == 0)) || (forms < 2))
              {
                seen[k] = 1;
                if (forms >= 2)
                {
                  out[n].kind = 2;
                  out[n].mode = (s != 0) ? (2) : (1);
                  out[n].f8 = i;
                }
                else
                {
                  t = 0;
                  if (ratio != 0xff)
                    t = 1;
                  out[n].kind = t;
                  out[n].mode = (s != 0) ? (2) : (1);
                  out[n].f8 = (g == 1) ? (1) : (0);
                }
                out[n].gender = g;
                out[n].shiny = s;
                out[n].form = i;
                n++;
              }
            }
          }

        }
      }

    }

  }
  *count = n;
  *sel = cur;
  *next = (cur + 1) % n;
  *groups = 0;
  *twos = 0;
  for (m = 0; m < (*count); m++)
  {
    if ((out[m].mode) == 2)
      (*twos)++;
  }

  for (m = 0; m < (*count); m++)
  {
    if ((out[m].kind) == 0)
    {
      *groups = 1;
    }
    else
      if ((m == 0) || (prev != (out[m].f8)))
    {
      prev = out[m].f8;
      (*groups)++;
    }
  }

}

void ZUKAN_DETAIL_FORM_RefreshFormEntries(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    ZUKAN_DETAIL_FORM_BuildFormEntries(heap, key, p->ents, &p->count, &p->f54a,
                        &p->f54c, &p->sel, &p->sel2);
}

void ZUKAN_DETAIL_FORM_PlaceModelItem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int a, int b, int pose, u16 idx)
{
    Vec v;
    u16 species;
    u32 form;
    u32 f152;
    u32 f153;
    u32 extra;

    extra = 0;
    species = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    form = p->ents[idx].form;
    f152 = p->ents[idx].gender;
    f153 = p->ents[idx].shiny;
    if (species == 0x147)
        extra = ZUKAN_SAVE_GetSpindaPersonality(ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(key)), extra);
    if (a != 4) {
        ZUKAN_DETAIL_FORM_CreateModelItem(&p->item[a], *heap, (void *)p->cam, species, form, f152, f153, 0, 0, extra);
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[a], pose, (int)(&v));
        MCSS_SetPosition((void *)p->item[a].obj, (u32 *)(&v));
        if (p->w124 == 0)
            MCSS_SetVanishFlag((void *)p->item[a].obj);
    }
    if (b != 4) {
        ZUKAN_DETAIL_FORM_CreateModelItem(&p->item[b], *heap, (void *)p->cam, species, form, f152, f153, 0, 1, extra);
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[b], pose, (int)(&v));
        MCSS_SetPosition((void *)p->item[b].obj, (u32 *)(&v));
        if (p->w124 != 0)
            MCSS_SetVanishFlag((void *)p->item[b].obj);
    }
}

void ZUKAN_DETAIL_FORM_CreateCurrentIcon(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, u16 idx)
{
    u16 k = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);

    p->obj[p->cur] = ZUKAN_DETAIL_FORM_CreateIconActor((u32)p->arc, &p->res[p->cur], p->j, p->k, p->f0, *heap, k,
                                         p->ents[idx].form, p->ents[idx].gender, 0);
}

void ZUKAN_DETAIL_FORM_RebuildModels(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;
    int a;
    int b;
    int pose;

    for (i = 0; i < 4; i++)
        ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[i], p->cam);
    ZUKAN_DETAIL_FORM_RefreshFormEntries(heap, p, key);
    pose = 0;
    if (p->state == 4 && p->count >= 2)
        pose = 1;
    a = p->w124 != 0 ? 0 : 4;
    b = p->w124 != 0 ? 4 : 1;
    ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, pose, p->sel);
    if (a != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(p->item[0].state, 0, p);
    if (b != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(p->item[1].state, 1, p);
    if (p->state == 4 && p->count >= 2) {
        a = p->w124 != 0 ? 2 : 4;
        b = p->w124 != 0 ? 4 : 3;
        ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, 2, p->sel2);
        if (a != 4)
            ZUKAN_DETAIL_FORM_InitAnimState(p->item[2].state, 2, p);
        if (b != 4)
            ZUKAN_DETAIL_FORM_InitAnimState(p->item[3].state, 3, p);
    }
    ZUKAN_DETAIL_FORM_SwapIconActor((u16 *)heap, (struct Ov208Form *)p, key);
    ZUKAN_DETAIL_FORM_DrawSpeciesLabels(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateBgScrollForState(heap, p, key);
    ZUKAN_DETAIL_FORM_DrawFormLabelMain(heap, p, key);
    ZUKAN_DETAIL_FORM_DrawFormLabelSub(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateCursorMarkers(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateScrollMarkers(heap, p, key);
    ZUKAN_DETAIL_FORM_UpdateArrowVisibility(heap, p, key);
}

/*
 * Closed 2026-10-04: pose=0 stays linear via goto skip; models addressed as p + 0xc + i * 0x44.
 */
void ZUKAN_DETAIL_FORM_RebuildModelsSwapped(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    Vec v;
    int a;
    int b;
    int pose;
    a = 0;
    MCSS_SetTaskSystem((u8 *)p->cam, 0);
    if (p->item[0].obj != 0) a = 4;
    b = 1;
    if (p->item[1].obj != 0) b = 4;
    if (p->w124 != 0) b = 4;
    else a = 4;
    pose = 0;
    if (p->state != 4) goto skip;
    if (p->count < 2) goto skip;
    pose = 1;
skip:
    ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, pose, p->sel);
    if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[0].state, 0, p);
    else if (p->item[0].obj != 0) {
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[0], pose, (int)(&v));
        MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v));
    }
    if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[1].state, 1, p);
    else if (p->item[1].obj != 0) {
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[1], pose, (int)(&v));
        MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v));
    }
    if (p->state == 4 && p->count >= 2) {
        a = 2;
        if (p->item[2].obj != 0) a = 4;
        b = 3;
        if (p->item[3].obj != 0) b = 4;
        ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, 2, p->sel2);
        if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[2].state, 2, p);
        else if (p->item[2].obj != 0) {
            ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[2], 2, (int)(&v));
            MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v));
        }
        if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[3].state, 3, p);
        else if (p->item[3].obj != 0) {
            ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[3], 2, (int)(&v));
            MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v));
        }
    }
    MCSS_SetTaskSystem((u8 *)p->cam, (u32)p->heap3d);
    if (p->state == 0) {
        p->w6c8 = 1;
        ZUKAN_DETAIL_FORM_PlaceSideModels(heap, p, key);
    }
}

/*
 * note: 2026-10-05 (D4-11): EXACT. pose set with the goto form of sibling 021C595C;
 *   &p->item[i] as one byte offset (p + 0xc + i*0x44) so &p->item[1] folds to p+0x50.
 */
void ZUKAN_DETAIL_FORM_RebuildModelsSingle(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    Vec v;
    int a;
    int b;
    int pose;
    a = 0;
    MCSS_SetTaskSystem((u8 *)p->cam, 0);
    if (p->item[0].obj != 0) a = 4;
    b = 1;
    if (p->item[1].obj != 0) b = 4;
    pose = 0;
    if (p->state != 4) goto skip;
    if (p->count < 2) goto skip;
    pose = 1;
skip:
    ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, pose, p->sel);
    if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[0].state, 0, p);
    else {
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[0], pose, (int)(&v));
        MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v));
    }
    if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[1].state, 1, p);
    else {
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[1], pose, (int)(&v));
        MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v));
    }
    a = 2;
    if (p->item[2].obj != 0) a = 4;
    b = 3;
    if (p->item[3].obj != 0) b = 4;
    ZUKAN_DETAIL_FORM_PlaceModelItem(heap, p, key, a, b, 2, p->sel2);
    if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[2].state, 2, p);
    else {
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[2], 2, (int)(&v));
        MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v));
    }
    if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[3].state, 3, p);
    else {
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[3], 2, (int)(&v));
        MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v));
    }
    MCSS_SetTaskSystem((u8 *)p->cam, (u32)p->heap3d);
    if (p->state == 0) {
        p->w6c8 = 1;
        ZUKAN_DETAIL_FORM_PlaceSideModels(heap, p, key);
    }
}

void ZUKAN_DETAIL_FORM_RebuildSideModels(void *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    int a;
    int b;

    ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[2], p->cam);
    ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[3], p->cam);
    a = p->w124 != 0 ? 2 : 4;
    b = p->w124 != 0 ? 4 : 3;
    ZUKAN_DETAIL_FORM_PlaceModelItem(a0, p, key, a, b, 2, p->sel2);
    if (a != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(p->item[2].state, 2, p);
    if (b != 4)
        ZUKAN_DETAIL_FORM_InitAnimState(p->item[3].state, 3, p);
    ZUKAN_DETAIL_FORM_DrawFormLabelSub(a0, p, key);
    ZUKAN_DETAIL_FORM_UpdateCursorMarkers(a0, p, key);
}

void ZUKAN_DETAIL_FORM_SwapIconActor(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    if (p->obj[p->cur] != 0)
        CLACT_SetActorDrawEnable((struct Obj *)p->obj[p->cur], 0);
    p->cur = (p->cur + 1) % 2;
    if (p->obj[p->cur] != 0) {
        if (p->obj[p->cur] != 0)
            ZUKAN_DETAIL_FORM_DeleteIconActor(p->res[p->cur], p->obj[p->cur]);
        p->obj[p->cur] = 0;
    }
    ZUKAN_DETAIL_FORM_CreateCurrentIcon(heap, p, key, p->sel);
}

void ZUKAN_DETAIL_FORM_UpdateState(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u32 x;
    u32 y;
    void *scene;
    u8 touch;
    int ok;
    u32 r;
    u8 i;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    switch (p->state) {
    case 0:
        if (p->w6b4 == 0)
            break;
        r = ZUKAN_DETAIL_FORM_HandleTouchArrows(heap, p, key);
        if (r != 5) {
            switch (r) {
            case 0:
                ZUKAN_DETAIL_FORM_ToggleModelVisibility(heap, p, key);
                return;
            case 1:
                ZUKAN_DETAIL_FORM_RebuildModelsSingle(heap, p, key);
                for (i = 0; i < 4; i++)
                    ZUKAN_DETAIL_FORM_RestartModelAnim(&p->item[i]);
                return;
            case 2:
                p->w6c8 = 1;
                ZUKAN_DETAIL_FORM_AdvanceSelection(heap, p, key);
                ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 1);
                return;
            case 3:
                p->w6c8 = 0;
                ZUKAN_DETAIL_FORM_AdvanceSelection(heap, p, key);
                ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 1);
                return;
            }
        } else {
            ok = 0;
            if (KEY_GetTrg() & 1) {
                ok = 1;
                touch = 0;
            } else if (TOUCHPANEL_GetPointTrg(&x, &y) != 0 && y < 0xa8) {
                ok = 1;
                touch = 1;
            }
            if (ok != 0 && p->count >= 2) {
                if ((p->w124 != 0 && p->item[2].obj == 0) || (p->w124 == 0 && p->item[3].obj == 0)) {
                    ZUKAN_DETAIL_FORM_RebuildSideItems(heap, p, key);
                    p->w6c8 = 1;
                    ZUKAN_DETAIL_FORM_PlaceSideModels(heap, p, key);
                }
                ZUKAN_DETAIL_FORM_HandleStateEvent(heap, p, key, 2);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                UI_SetInputMode(touch);
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 0);
                return;
            }
        }
        break;
    case 4:
        if (p->w6b4 == 0 || p->w69c != 0)
            break;
        r = ZUKAN_DETAIL_FORM_HandleTouchArrows(heap, p, key);
        if (r != 5) {
            switch (r) {
            case 0:
                ZUKAN_DETAIL_FORM_ToggleModelVisibility(heap, p, key);
                return;
            case 1:
                ZUKAN_DETAIL_FORM_RebuildModelsSingle(heap, p, key);
                for (i = 0; i < 4; i++)
                    ZUKAN_DETAIL_FORM_RestartModelAnim(&p->item[i]);
                break;
            default:
                return;
            }
        }
        break;
    }
}

void ZUKAN_DETAIL_FORM_HandleStateEvent(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx, int ev)
{
    void *scene;
    void *icon;
    int flag;
    Side idx;
    Vec v;
    Vec v2;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(ctx);
    icon = ZUKAN_DETAIL_COMMON_GetCursorValue(ctx);
    flag = 0;
    switch (p->state) {
    case 0:
        switch (ev) {
        case 1:
            if (p->w6c4 == 0) {
                ZUKAN_DETAIL_FORM_SignalAnimDone((int *)&p->item[2]);
                ZUKAN_DETAIL_FORM_SignalAnimDone((int *)&p->item[3]);
                p->w6c4 = 1;
            }
            break;
        case 2:
            p->w6cc = 0;
            p->w6d0 = 0;
            if (p->count >= 2) {
                p->w6c8 = 1;
                ZUKAN_DETAIL_FORM_PlaceSideModels(a0, p, ctx);
            }
            break;
        }
        break;
    case 1:
        if (ev == 0 && p->w694 == 5)
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
        break;
    case 2:
        if (ev == 3)
            ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(scene, 0);
        break;
    case 3:
        if (ev == 4) {
            flag = 1;
            if (p->count >= 2) {
                if (p->item[0].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[0], 1, (int)(&v));
                    MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v));
                }
                if (p->item[1].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[1], 1, (int)(&v));
                    MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v));
                }
                if (p->item[2].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[2], 2, (int)(&v));
                    MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v));
                }
                if (p->item[3].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[3], 2, (int)(&v));
                    MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v));
                }
            }
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 2, 3, ZUKAN_DETAIL_COMMON_GetMaxValue(ctx) > 1);
            if (p->count >= 3)
                ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(scene, 1);
            else
                ZUKAN_DETAIL_TOUCHBAR_SetButtonVisible(scene, 0);
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 4);
        }
        break;
    case 4:
        switch (ev) {
        case 5:
            if (p->w6bc == 0) {
                p->w6bc = 1;
                p->w6c0 = 0;
            }
            break;
        case 6:
            p->w6cc = 0;
            p->w6d0 = 0;
            break;
        }
        break;
    case 5:
        if (ev == 4 && p->w6d8 != 0) {
            p->w6dc = 1;
            if (p->w6e0 != 0) {
                p->w6d8 = 0;
                ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            }
        }
        break;
    case 6:
        if (ev == 7)
            ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(scene, 0);
        break;
    case 7:
        if (ev == 0) {
            flag = 1;
            if (p->count >= 2) {
                if (p->item[0].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[0], 0, (int)(&v2));
                    MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v2));
                }
                if (p->item[1].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[1], 0, (int)(&v2));
                    MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v2));
                }
                idx = p->w124 != 0 ? SIDE_0 : SIDE_1;
                ZUKAN_DETAIL_FORM_GetModelPosition(p->item[idx].obj, &v2);
                if (p->item[2].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[2], 2, (int)(&v2));
                    MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v2));
                }
                if (p->item[3].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[3], 2, (int)(&v2));
                    MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v2));
                }
            }
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 3, ZUKAN_DETAIL_COMMON_GetMaxValue(ctx) > 1);
            ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scene, GAME_DATA_CheckSaveFlag(ZUKAN_DETAIL_COMMON_GetSource(ctx), 0x14));
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 3);
            if (p->count >= 2) {
                p->w6c8 = 1;
                ZUKAN_DETAIL_FORM_PlaceSideModels(a0, p, ctx);
            }
        }
        break;
    }
    p->state = ev;
    if (flag) {
        ZUKAN_DETAIL_FORM_UpdateBgScrollForState(a0, p, ctx);
        ZUKAN_DETAIL_FORM_DrawFormLabelSub(a0, p, ctx);
        ZUKAN_DETAIL_FORM_UpdateCursorMarkers(a0, p, ctx);
        ZUKAN_DETAIL_FORM_UpdateScrollMarkers(a0, p, ctx);
        ZUKAN_DETAIL_FORM_UpdateArrowVisibility(a0, p, ctx);
        p->w694 = 5;
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
    }
}

void ZUKAN_DETAIL_FORM_CreateArrowActors(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    struct Ov208CellHdr hdr[2];
    void *h;
    u8 i;
    const u8 *t;
    struct Ov208Form *e;

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    p->rs[1] = CLACT_RegisterPaletteEx(h, 3, 0, 0, 0, 3, *heap);
    p->rs[0] = CLACT_RegisterCharacter(h, 0xd, 0, 0, *heap);
    p->rs[2] = CLACT_RegisterCellAnim(h, 0x1b, 0x2c, *heap);
    p->rs[4] = CLACT_RegisterPaletteEx(h, 0, 0, 0x60, 0, 1, *heap);
    p->rs[3] = CLACT_RegisterCharacter(h, 0xa, 0, 0, *heap);
    p->rs[5] = CLACT_RegisterCellAnim(h, 0x1a, 0x2b, *heap);
    p->rs[7] = CLACT_RegisterPaletteEx(h, 6, 0, 0x80, 0, 2, *heap);
    p->rs[6] = CLACT_RegisterCharacter(h, 0x10, 0, 0, *heap);
    p->rs[8] = CLACT_RegisterCellAnim(h, 0x1d, 0x2e, *heap);
    ARC_TOOL_DeleteHandle(h);
    for (i = 0; i < 4; i++) {
        MI_CpuFill8(&hdr[1], 0, 8);
        t = data_021C87A0[i];
        hdr[1].x = t[0];
        hdr[1].y = t[1];
        hdr[1].z = t[2];
        hdr[1].a = t[3];
        hdr[1].b = t[4];
        p->act[i] = (u32)CLACT_CreateActor((void *)p->f0, p->rs[t[5]], p->rs[t[6]], p->rs[t[7]], &hdr[1], 0, *heap);
        CLACT_SetActorAutoAnim((struct Obj *)p->act[i], 1);
        CLACT_SetActorDrawEnable((struct Obj *)p->act[i], 0);
        CLACT_SetActorObjMode((struct Actor *)(p->act[i]), 1);
    }
    p->row[0].x = 0x40;
    p->row[0].y = 0x98;
    p->row[0].res[0] = 0x0;
    p->row[0].res[1] = 0x1;
    p->row[0].res[2] = 0x2;
    p->row[0].hit[0] = 0x40;
    p->row[0].hit[1] = 0x98;
    p->row[0].hit[2] = 0x40;
    p->row[0].hit[3] = 0x10;
    p->row[0].f14 = 0x18;
    p->row[0].f15 = 0x1a;
    p->row[0].mask = 0x4;
    p->row[0].se = 0x54c;
    p->row[0].st = 0x0;
    p->row[0].obj = 0x0;
    p->row[1].x = 0x80;
    p->row[1].y = 0x98;
    p->row[1].res[0] = 0x0;
    p->row[1].res[1] = 0x1;
    p->row[1].res[2] = 0x2;
    p->row[1].hit[0] = 0x80;
    p->row[1].hit[1] = 0x98;
    p->row[1].hit[2] = 0x40;
    p->row[1].hit[3] = 0x10;
    p->row[1].f14 = 0x17;
    p->row[1].f15 = 0x19;
    p->row[1].mask = 0x8;
    p->row[1].se = 0x54c;
    p->row[1].st = 0x0;
    p->row[1].obj = 0x0;
    p->row[2].x = 0x80;
    p->row[2].y = 0x60;
    p->row[2].res[0] = 0x6;
    p->row[2].res[1] = 0x7;
    p->row[2].res[2] = 0x8;
    p->row[2].hit[0] = 0x0;
    p->row[2].hit[1] = 0x0;
    p->row[2].hit[2] = 0x18;
    p->row[2].hit[3] = 0x10;
    p->row[2].f14 = 0x4;
    p->row[2].f15 = 0x5;
    p->row[2].mask = 0x200;
    p->row[2].se = 0x54a;
    p->row[2].st = 0x0;
    p->row[2].obj = 0x0;
    p->row[3].x = 0xe4;
    p->row[3].y = 0x60;
    p->row[3].res[0] = 0x6;
    p->row[3].res[1] = 0x7;
    p->row[3].res[2] = 0x8;
    p->row[3].hit[0] = 0xe8;
    p->row[3].hit[1] = 0x0;
    p->row[3].hit[2] = 0x18;
    p->row[3].hit[3] = 0x10;
    p->row[3].f14 = 0x2;
    p->row[3].f15 = 0x3;
    p->row[3].mask = 0x100;
    p->row[3].se = 0x54a;
    p->row[3].st = 0x0;
    p->row[3].obj = 0x0;
    for (i = 0; i < 4; i++) {
        MI_CpuFill8(&hdr[0], 0, 8);
        e = (struct Ov208Form *)((u8 *)p + i * 0x28);
        hdr[0].x = e->row[0].x;
        hdr[0].y = e->row[0].y;
        hdr[0].z = e->row[0].f14;
        hdr[0].a = 0;
        hdr[0].b = 3;
        e->row[0].obj = (u32)CLACT_CreateActor((void *)p->f0, p->rs[e->row[0].res[0]], p->rs[e->row[0].res[1]],
                                            p->rs[e->row[0].res[2]], &hdr[0], 0, *heap);
        CLACT_SetActorAutoAnim((struct Obj *)e->row[0].obj, 1);
        CLACT_SetActorObjMode((struct Actor *)e->row[0].obj, 1);
    }
    p->w694 = 5;
}

void ZUKAN_DETAIL_FORM_DeleteArrowActors(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct Obj *)p->row[i].obj);
    for (i = 0; i < 4; i++)
        CLACT_DeleteActor((struct Obj *)p->act[i]);
    CLACT_ReleasePalette(p->rs[1]);
    CLACT_ReleaseCharacter(p->rs[0]);
    CLACT_ReleaseCellAnim(p->rs[2]);
    CLACT_ReleasePalette(p->rs[4]);
    CLACT_ReleaseCharacter(p->rs[3]);
    CLACT_ReleaseCellAnim(p->rs[5]);
    CLACT_ReleasePalette(p->rs[7]);
    CLACT_ReleaseCharacter(p->rs[6]);
    CLACT_ReleaseCellAnim(p->rs[8]);
}

int ZUKAN_DETAIL_FORM_HandleTouchArrows(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key)
{
    void *sys;
    enum { HIT_NONE = 5 } hit;
    u8 type;
    u32 x;
    u32 y;
    u8 i;
    struct Ov208Form *b;
    struct Ov208Form *c;
    u8 j;
    int partner;
    int o;
    u32 *q;
    int k;
    sys = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    hit = HIT_NONE;
    if (hit == 5) {
        for (i = 0; i < 4; i++) {
            b = (struct Ov208Form *)((u8 *)p + i * 0x28);
            if (CLACT_GetActorDrawEnable((void *)b->row[0].obj) != 0) {
                if ((KEY_GetTrg() & b->row[0].mask) != 0) {
                    type = 0;
                    hit = i;
                    break;
                }
                if (i == 2 || i == 3) {
                    if ((KEY_GetRepeat() & b->row[0].mask) != 0) {
                        type = 0;
                        hit = i;
                        break;
                    }
                }
            }
        }
    }
    if (hit == 5) {
        if (TOUCHPANEL_GetPointTrg(&x, &y) != 0) {
            k = 0;
            for (j = 0; j < 4; j++) {
                c = (struct Ov208Form *)((u8 *)p + j * 0x28);
                if (CLACT_GetActorDrawEnable((void *)c->row[0].obj) != 0) {
                    if ((u32)c->row[0].hit[k] <= x && x < (u32)c->row[0].hit[k] + c->row[0].hit[k + 2]
                        && (u32)c->row[0].hit[k + 1] <= y && y < (u32)c->row[0].hit[k + 1] + c->row[0].hit[k + 3]) {
                        type = 1;
                        hit = j;
                        break;
                    }
                }
            }
        }
    }
    if (hit != 5) {
        if (p->w694 != 5) {
            hit = 6;
        } else {
            UI_SetInputMode(type);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(sys, 0);
            o = hit * 0x28;
            *(u32 *)((u8 *)&p->row[0].st + o) = 1;
            CLACT_SetActorAnimSeq((void *)((struct Ov208Form *)((u8 *)p + o))->row[0].obj,
                          ((struct Ov208Form *)((u8 *)p + o))->row[0].f15);
            GFL_USE_PlaySeDefaultVolume(((struct Ov208Row *)((u8 *)p + 0x5f4 + o))->se);
            partner = 5;
            if (hit == 2)
                partner = 3;
            else if (hit == 3)
                partner = 2;
            if (partner != 5) {
                q = &p->row[0].obj;
                CLACT_SetActorAutoAnim((void *)*(u32 *)((u8 *)q + partner * 0x28), 0);
                CLACT_SetActorAnimFrame((void *)*(u32 *)((u8 *)q + partner * 0x28), 0);
            }
            p->w694 = hit;
        }
    }
    return hit;
}

void ZUKAN_DETAIL_FORM_UpdateArrowVisibility(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key)
{
    int on = 0;

    switch (p->state) {
    case 0:
        if (p->count >= 2)
            on = 1;
        break;
    case 4:
        break;
    }
    if (on) {
        CLACT_SetActorDrawEnable((struct Obj *)p->row[2].obj, 1);
        CLACT_SetActorDrawEnable((struct Obj *)p->row[3].obj, 1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->row[2].obj, 0);
        CLACT_SetActorDrawEnable((struct Obj *)p->row[3].obj, 0);
    }
}

void ZUKAN_DETAIL_FORM_UpdateArrowAnim(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key)
{
    void *scene;
    u32 other;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    if (p->w694 == 5)
        return;
    switch (p->row[p->w694].st) {
    case 0:
        break;
    case 1:
        p->row[p->w694].st = 2;
        return;
    case 2:
        if (CLACT_IsActorAnimActive((struct Actor *)p->row[p->w694].obj) != 0)
            break;
        p->row[p->w694].st = 3;
        return;
    case 3:
        CLACT_SetActorAnimSeq((struct Obj *)p->row[p->w694].obj, p->row[p->w694].f14);
        p->row[p->w694].st = 0;
        other = 5;
        if (p->w694 == 2)
            other = 3;
        else if (p->w694 == 3)
            other = 2;
        if (other != 5 && p->row[other].st == 0) {
            CLACT_SetActorAutoAnim((struct Obj *)p->row[other].obj, 1);
            CLACT_SetActorAnimSeq((struct Obj *)p->row[other].obj, p->row[other].f14);
        }
        p->w694 = 5;
        if (p->state == 0 || p->state == 4)
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
        break;
    }
}

void ZUKAN_DETAIL_FORM_UpdateCursorMarkers(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2)
{
    int show = 1;
    int multi = 0;
    int v;
    int w;
    Ov208Pos pos;

    switch (p->state) {
    case 0:
        show = 1;
        break;
    case 4:
        if (p->count >= 2)
            multi = 1;
        break;
    }
    if (show && multi) {
        pos.x = 0;
        pos.y = 0;
        CLACT_AddActorSurfacePos((struct Obj *)(p->act[2]), (const struct Vec2 *)(&pos), 0);
        pos.x = 0x80;
        pos.y = 0;
        CLACT_AddActorSurfacePos((struct Obj *)(p->act[3]), (const struct Vec2 *)(&pos), 0);
    } else if (show) {
        pos.x = 0x40;
        pos.y = 0;
        CLACT_AddActorSurfacePos((struct Obj *)(p->act[2]), (const struct Vec2 *)(&pos), 0);
    }
    if (p->ents[p->sel].mode == 2)
        v = 1;
    else
        v = 0;
    CLACT_SetActorDrawEnable((struct Obj *)p->act[2], 1);
    CLACT_SetActorAnimSeq((struct Obj *)(p->act[2]), (u8)v);
    if (multi) {
        w = p->ents[p->sel2].mode == 2;
        CLACT_SetActorDrawEnable((struct Obj *)p->act[3], 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->act[3]), (u8)w);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->act[3], 0);
    }
}

void ZUKAN_DETAIL_FORM_UpdateScrollMarkers(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *a2)
{
    int on = 0;
    u16 n;
    u8 mid;
    Ov208Pos pos;

    switch (p->state) {
    case 0:
        break;
    case 4:
        if (p->count >= 3)
            on = 1;
        break;
    }
    if (on) {
        n = ZUKAN_DETAIL_FORM_CountEntriesBefore(a0, p, a2, p->sel, p->sel2);
        ZUKAN_DETAIL_FORM_GetScrollSlotRange((u16)(p->count - 1), n, 0, &mid, 0);
        pos.x = mid;
        pos.y = 0x30;
        CLACT_AddActorSurfacePos((struct Obj *)(p->act[1]), (const struct Vec2 *)(&pos), 0);
        CLACT_SetActorDrawEnable((struct Obj *)p->act[0], 1);
        CLACT_SetActorDrawEnable((struct Obj *)p->act[1], 1);
        p->w698 = 0;
        p->w6d4 = 0;
        p->w69c = 0;
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->act[0], 0);
        CLACT_SetActorDrawEnable((struct Obj *)p->act[1], 0);
    }
}

void ZUKAN_DETAIL_FORM_UpdateScrollInput(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    if ((p->state == 4 && p->w6b4 != 0 && p->w694 == 5) || p->w6d4 != 0) {
        if (ZUKAN_DETAIL_FORM_HandleScrollKey(a0, p, key) == 0)
            ZUKAN_DETAIL_FORM_HandleScrollTouch(a0, p, key);
    }
}

u32 ZUKAN_DETAIL_FORM_HandleScrollTouch(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u32 x;
    u32 y;
    s16 pos[2];
    void *scene;
    int moved;
    u16 old;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    moved = 0;
    if (p->w69c != 0) {
        if (TOUCHPANEL_GetPointCont(&x, &y) == 0) {
            p->w69c = 0;
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
        }
    } else if (p->count >= 3) {
        if (TOUCHPANEL_GetPointTrg(&x, &y) != 0 && x >= 0x90 && x <= 0xe7 && y >= 0x28 && y <= 0x3f) {
            p->w69c = 1;
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 0);
            moved = 1;
        }
    }
    if (p->w69c != 0) {
        old = p->sel2;
        x = x > 0xdc ? 0xdc : (x < 0x9c ? 0x9c : x);
        pos[0] = x;
        pos[1] = 0x30;
        CLACT_AddActorSurfacePos((struct Obj *)p->act[1], (const struct Vec2 *)pos, 0);
        p->sel2 = ZUKAN_DETAIL_FORM_GetEntryIndex(a0, p, key, p->sel,
                                       ZUKAN_DETAIL_FORM_GetScrollSlotAtX(p->count - 1, x));
        if (old != p->sel2) {
            ZUKAN_DETAIL_FORM_RebuildSideModels(a0, p, key);
            moved = 1;
        }
    }
    if (moved)
        GFL_USE_PlaySeDefaultVolume(0x645);
    if (p->w69c != 0)
        UI_SetInputMode(1);
    return p->w69c;
}

int ZUKAN_DETAIL_FORM_HandleScrollKey(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *a2)
{
    struct Ov208Cursor c;
    int moved;
    u16 i;

    moved = 0;
    if (p->w698 != 0) {
        i = ZUKAN_DETAIL_FORM_CountEntriesBefore(a0, p, a2, p->sel, p->sel2);
        ZUKAN_DETAIL_FORM_GetScrollSlotRange((u16)(p->count - 1), i, 0, &c.slot, 0);
        c.x = c.slot;
        c.y = 0x30;
        CLACT_AddActorSurfacePos((struct Obj *)p->act[1], (const struct Vec2 *)(&c.x), 0);
        moved = 1;
    }
    return moved;
}

void ZUKAN_DETAIL_FORM_GetScrollSlotRange(int n, int i, u8 *lo, u8 *mid, u8 *hi)
{
    u8 a = i * 65 / n + 0x9c;
    u8 b = (i + 1) * 65 / n + 0x9c;
    u8 m;

    if (i == 0)
        m = a;
    else if (i == n - 1)
        m = b - 1;
    else if (a >= b)
        m = a;
    else
        m = (a + b - 1) / 2;
    if (lo != 0)
        *lo = a;
    if (hi != 0)
        *hi = b;
    if (mid != 0)
        *mid = m;
}

u16 ZUKAN_DETAIL_FORM_GetScrollSlotAtX(u16 n, u8 x)
{
    u8 b[3];
    u16 i;

    for (i = 0; i < n; i++) {
        ZUKAN_DETAIL_FORM_GetScrollSlotRange(n, i, &b[2], &b[1], &b[0]);
        if (i == 0) {
            if (x < b[0])
                break;
        } else {
            if (i == n - 1)
                break;
            if (b[2] <= x && x < b[0])
                break;
        }
    }
    return i;
}

u16 ZUKAN_DETAIL_FORM_CountEntriesBefore(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2, u16 skip, u16 stop)
{
    u16 n = 0;
    u16 i;

    for (i = 0; i < p->count; i++) {
        if (i == skip)
            continue;
        if (i == stop)
            break;
        n++;
    }
    return n;
}

u16 ZUKAN_DETAIL_FORM_GetEntryIndex(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2, u16 skip, u16 want)
{
    u16 r = 0;
    u16 j = 0;
    u16 i;

    for (i = 0; i < p->count; i++) {
        if (i != skip) {
            if (j == want) {
                r = i;
                break;
            }
            j++;
        }
    }
    return r;
}

void ZUKAN_DETAIL_FORM_UpdateSlideLeft(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx)
{
    Vec u;
    VecF a;
    VecF b;
    Vec v;
    VecF c;
    VecF d;
    Vec w;
    float t;
    float x;
    float y;
    int idx;
    u16 id;
    void *obj;
    u32 f;
    u32 sh;

    if (p->w6bc == 1) {
        p->w6c0 += 0x400;
        if (p->w6c0 >= 0x8000) {
            p->w6c0 = 0x8000;
            p->w6bc = 0;
            ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 4);
            if (p->count >= 2) {
                if (p->item[2].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[2], 1, (int)(&u));
                    MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&u));
                }
                if (p->item[3].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[3], 1, (int)(&u));
                    MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&u));
                }
                idx = p->w124 != 0 ? 2 : 3;
                ZUKAN_DETAIL_FORM_GetModelPosition(p->item[idx].obj, &u);
                if (p->item[0].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[0], 2, (int)(&u));
                    MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&u));
                }
                if (p->item[1].obj != 0) {
                    ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[1], 2, (int)(&u));
                    MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&u));
                }
                ZUKAN_DETAIL_FORM_SwapItems(a0, p, ctx);
                ZUKAN_DETAIL_FORM_SwapIconActor(a0, p, ctx);
                ZUKAN_DETAIL_FORM_DrawFormLabelMain(a0, p, ctx);
                ZUKAN_DETAIL_FORM_DrawFormLabelSub(a0, p, ctx);
                ZUKAN_DETAIL_FORM_UpdateCursorMarkers(a0, p, ctx);
                id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
                obj = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(ctx));
                f = p->ents[p->sel].gender;
                sh = p->ents[p->sel].shiny != 0 ? 1 : 0;
                ZUKAN_SAVE_UpdateViewFlags(obj, id, f, sh, p->ents[p->sel].form);
                if (p->count >= 3)
                    p->w698 = 1;
            }
        } else {
            t = FX_SinCosTable_[(p->w6c0 >> 4) * 2] / 4096.0f;
            if (p->item[0].obj != 0) {
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[0], 3, &a);
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[0], 4, &b);
                x = a.x + p->w6c0 * (b.x - a.x) / 32768.0f;
                y = a.y + 16.0f * t;
                v.x = FX_F32_TO_FX32(x);
                v.y = FX_F32_TO_FX32(y);
                v.z = FX_F32_TO_FX32(a.z);
                MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v));
            }
            if (p->item[1].obj != 0) {
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[1], 3, &a);
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[1], 4, &b);
                x = a.x + p->w6c0 * (b.x - a.x) / 32768.0f;
                y = a.y + 16.0f * t;
                v.x = FX_F32_TO_FX32(x);
                v.y = FX_F32_TO_FX32(y);
                v.z = FX_F32_TO_FX32(a.z);
                MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v));
            }
            if (p->item[2].obj != 0) {
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[2], 3, &c);
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[2], 4, &d);
                x = d.x + p->w6c0 * (c.x - d.x) / 32768.0f;
                y = d.y + -16.0f * t;
                w.x = FX_F32_TO_FX32(x);
                w.y = FX_F32_TO_FX32(y);
                w.z = FX_F32_TO_FX32(d.z);
                MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&w));
            }
            if (p->item[3].obj != 0) {
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[3], 3, &c);
                ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[3], 4, &d);
                x = d.x + p->w6c0 * (c.x - d.x) / 32768.0f;
                y = d.y + -16.0f * t;
                w.x = FX_F32_TO_FX32(x);
                w.y = FX_F32_TO_FX32(y);
                w.z = FX_F32_TO_FX32(d.z);
                MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&w));
            }
        }
    }
}

void ZUKAN_DETAIL_FORM_AdvanceSelection(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u16 old = p->sel2;
    int a;
    int b;
    if (p->w6c8 == 0) {
        if (p->count >= 3) {
            p->sel2 = p->sel + p->count - 1;
            p->sel2 = (u32)p->sel2 % (u32)p->count;
        }
    } else {
        if (p->count >= 3) {
            p->sel2 = p->sel + 1;
            p->sel2 = (u32)p->sel2 % (u32)p->count;
        }
    }
    if ((p->w124 != 0 && p->item[2].obj == 0)
        || (p->w124 == 0 && p->item[3].obj == 0)
        || p->sel2 != old) {
        ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[2], p->cam);
        ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[3], p->cam);
        a = p->w124 != 0 ? 2 : 4;
        b = p->w124 != 0 ? 4 : 3;
        ZUKAN_DETAIL_FORM_PlaceModelItem(a0, p, key, a, b, 2, p->sel2);
        if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[2].state, 2, p);
        if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[3].state, 3, p);
    }
    ZUKAN_DETAIL_FORM_PlaceSideModels(a0, p, key);
}

void ZUKAN_DETAIL_FORM_PlaceSideModels(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2)
{
    Vec v;

    if (p->w6c8 == 0) {
        v.x = -0x40000;
        v.y = -0xde66;
        v.z = 0;
        if (p->item[2].obj != 0) {
            ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[2], 1, (Vec *)&v);
            MCSS_SetPosition((void *)(p->item[2].obj), (u32 *)(&v));
        }
        if (p->item[3].obj != 0) {
            ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[3], 1, (Vec *)&v);
            MCSS_SetPosition((void *)(p->item[3].obj), (u32 *)(&v));
        }
    } else {
        v.x = 0x40000;
        v.y = -0xde66;
        v.z = 0;
        if (p->item[2].obj != 0) {
            ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[2], 2, (Vec *)&v);
            MCSS_SetPosition((void *)(p->item[2].obj), (u32 *)(&v));
        }
        if (p->item[3].obj != 0) {
            ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[3], 2, (Vec *)&v);
            MCSS_SetPosition((void *)(p->item[3].obj), (u32 *)(&v));
        }
    }
}

void ZUKAN_DETAIL_FORM_UpdateSlideRight(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx)
{
    Vec v;
    VecF a;
    Vec u;
    Vec w;
    float x;
    float tx;
    int done;
    int idx;
    u16 id;
    void *obj;
    u32 f;
    u32 sh;

    if (p->w6c4 == 1) {
        done = 0;
        idx = p->w124 != 0 ? 2 : 3;
        ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[idx], 0, &a);
        tx = a.x;
        MCSS_GetPosition((void *)p->item[idx].obj, (u32 *)(&v));
        x = v.x / 4096.0f;
        if (p->w6c8 == 0) {
            x += 2.0f;
            if (x >= tx)
                done = 1;
        } else {
            x -= 2.0f;
            if (x <= tx)
                done = 1;
        }
        if (done) {
            x = tx;
            p->w6c4 = 2;
        }
        v.x = FX_F32_TO_FX32(x);
        if (p->item[2].obj != 0)
            MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v));
        if (p->item[3].obj != 0)
            MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v));
        idx = 0;
        if (p->w124 == 0)
            idx = 1;
        MCSS_GetPosition((void *)(p->item[idx].obj), (u32 *)(&v));
        x = v.x / 4096.0f;
        if (p->w6c8 == 0)
            x += 2.0f;
        else
            x -= 2.0f;
        v.x = FX_F32_TO_FX32(x);
        if (p->item[0].obj != 0)
            MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v));
        if (p->item[1].obj != 0)
            MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v));
    } else if (p->w6c4 == 2) {
        sh = 0;
        ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 0);
        ZUKAN_DETAIL_FORM_SwapItems(a0, p, ctx);
        ZUKAN_DETAIL_FORM_SignalAnimDone((int *)&p->item[2]);
        ZUKAN_DETAIL_FORM_SignalAnimDone((int *)&p->item[3]);
        ZUKAN_DETAIL_FORM_SwapIconActor(a0, p, ctx);
        ZUKAN_DETAIL_FORM_DrawFormLabelMain(a0, p, ctx);
        ZUKAN_DETAIL_FORM_DrawFormLabelSub(a0, p, ctx);
        ZUKAN_DETAIL_FORM_UpdateCursorMarkers(a0, p, ctx);
        id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(ctx);
        obj = ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(ctx));
        f = p->ents[p->sel].gender;
        if (p->ents[p->sel].shiny != 0)
            sh = 1;
        ZUKAN_SAVE_UpdateViewFlags(obj, id, f, sh, p->ents[p->sel].form);
        if (p->item[0].obj != 0) {
            ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[0], 0, (int)(&u));
            MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&u));
        }
        if (p->item[1].obj != 0) {
            ZUKAN_DETAIL_FORM_SelectModelPosition((int)&p->item[1], 0, (int)(&w));
            MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&w));
        }
        p->w6c8 = 1;
        ZUKAN_DETAIL_FORM_AdvanceSelection(a0, p, ctx);
        p->w6c4 = 0;
    }
}

void ZUKAN_DETAIL_FORM_UpdateSlideBoth(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *ctx)
{
    Vec v1;
    VecF a1;
    Vec b1;
    VecF a2;
    Vec c1;
    Vec v2;
    VecF a3;
    Vec b3;
    VecF a4;
    Vec c4;
    float x;
    float tx;
    int idx;

    if (p->count < 2) {
        if (p->state == 2) {
            ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 3);
            return;
        }
        if (p->state == 6) {
            ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 7);
            return;
        }
    } else if (p->state == 2) {
        if (p->w6cc == 0) {
            idx = 0;
            if (p->w124 == 0)
                idx = 1;
            ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[idx], 3, &a1);
            tx = a1.x;
            MCSS_GetPosition((void *)p->item[idx].obj, (u32 *)(&v1));
            x = v1.x / 4096.0f - 0.5f;
            if (x <= tx) {
                x = tx;
                p->w6cc = 1;
            }
            v1.x = FX_F32_TO_FX32(x);
            if (p->item[0].obj != 0)
                MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v1));
            if (p->item[1].obj != 0)
                MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v1));
            if (p->w6cc != 0) {
                if (p->item[0].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[0], 3, (Vec *)&b1);
                    MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&b1));
                }
                if (p->item[1].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[1], 3, (Vec *)&b1);
                    MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&b1));
                }
            }
        }
        if (p->w6d0 == 0) {
            idx = 2;
            if (p->w124 == 0)
                idx = 3;
            ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[idx], 4, &a2);
            tx = a2.x;
            MCSS_GetPosition((void *)p->item[idx].obj, (u32 *)(&v1));
            x = v1.x / 4096.0f - 1.5f;
            if (x <= tx) {
                x = tx;
                p->w6d0 = 1;
            }
            v1.x = FX_F32_TO_FX32(x);
            if (p->item[2].obj != 0)
                MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v1));
            if (p->item[3].obj != 0)
                MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v1));
            if (p->w6d0 != 0) {
                if (p->item[2].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[2], 4, (Vec *)&c1);
                    MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&c1));
                }
                if (p->item[3].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[3], 4, (Vec *)&c1);
                    MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&c1));
                }
            }
        }
        if (p->w6cc != 0 && p->w6d0 != 0) {
            ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 3);
            return;
        }
    } else if (p->state == 3) {
        ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 4);
        return;
    } else if (p->state == 6) {
        if (p->w6cc == 0) {
            idx = 0;
            if (p->w124 == 0)
                idx = 1;
            ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[idx], 0, &a3);
            tx = a3.x;
            MCSS_GetPosition((void *)p->item[idx].obj, (u32 *)(&v2));
            x = v2.x / 4096.0f;
            x += 0.5f;
            if (x >= tx) {
                x = tx;
                p->w6cc = 1;
            }
            v2.x = FX_F32_TO_FX32(x);
            if (p->item[0].obj != 0)
                MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&v2));
            if (p->item[1].obj != 0)
                MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&v2));
            if (p->w6cc != 0) {
                if (p->item[0].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[0], 0, (Vec *)&b3);
                    MCSS_SetPosition((void *)p->item[0].obj, (u32 *)(&b3));
                }
                if (p->item[1].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[1], 0, (Vec *)&b3);
                    MCSS_SetPosition((void *)p->item[1].obj, (u32 *)(&b3));
                }
            }
        }
        if (p->w6d0 == 0) {
            idx = 2;
            if (p->w124 == 0)
                idx = 3;
            ZUKAN_DETAIL_FORM_CopyModelPosition(&p->item[idx], 2, &a4);
            tx = (&a4)->x;
            MCSS_GetPosition((void *)p->item[idx].obj, (u32 *)(&v2));
            x = v2.x / 4096.0f;
            x += 1.5f;
            if (x >= tx) {
                x = tx;
                p->w6d0 = 1;
            }
            v2.x = FX_F32_TO_FX32(x);
            if (p->item[2].obj != 0)
                MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&v2));
            if (p->item[3].obj != 0)
                MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&v2));
            if (p->w6d0 != 0) {
                if (p->item[2].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[2], 2, (Vec *)&c4);
                    MCSS_SetPosition((void *)p->item[2].obj, (u32 *)(&c4));
                }
                if (p->item[3].obj != 0) {
                    ZUKAN_DETAIL_FORM_ConvertModelPosition(&p->item[3], 2, (Vec *)&c4);
                    MCSS_SetPosition((void *)p->item[3].obj, (u32 *)(&c4));
                }
            }
        }
        if (p->w6cc != 0 && p->w6d0 != 0) {
            ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 7);
            return;
        }
    } else if (p->state == 7) {
        ZUKAN_DETAIL_FORM_HandleStateEvent(a0, p, ctx, 0);
    }
}

void ZUKAN_DETAIL_FORM_RebuildSideItems(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    int a;
    int b;
    if (p->state != 0) return;
    ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[2], p->cam);
    ZUKAN_DETAIL_FORM_DestroyModelItem(&p->item[3], p->cam);
    MCSS_SetTaskSystem((u8 *)(p->cam), 0);
    a = p->w124 != 0 ? 2 : 4;
    b = p->w124 != 0 ? 4 : 3;
    ZUKAN_DETAIL_FORM_PlaceModelItem(a0, p, key, a, b, 2, p->sel2);
    if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[2].state, 2, p);
    if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(p->item[3].state, 3, p);
    MCSS_SetTaskSystem((u8 *)p->cam, (u32)p->heap3d);
}

void ZUKAN_DETAIL_FORM_SwapItems(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key)
{
    VecF t;
    VecF t2;
    u16 h;
    u32 w;
    struct Ov208AnmState *q;
    u8 i;

    h = p->sel;
    p->sel = p->sel2;
    p->sel2 = h;
    w = p->item[0].obj;
    p->item[0].obj = p->item[2].obj;
    p->item[2].obj = w;
    q = p->item[0].state;
    p->item[0].state = p->item[2].state;
    p->item[2].state = q;
    if (p->item[0].state != 0)
        p->item[0].state->f0 = 0;
    if (p->item[2].state != 0)
        p->item[2].state->f0 = 2;
    w = p->item[1].obj;
    p->item[1].obj = p->item[3].obj;
    p->item[3].obj = w;
    q = p->item[1].state;
    p->item[1].state = p->item[3].state;
    p->item[3].state = q;
    if (p->item[1].state != 0)
        p->item[1].state->f0 = 1;
    if (p->item[3].state != 0)
        p->item[3].state->f0 = 3;
    for (i = 0; i < 5; i++) {
        t = p->item[0].pos[i];
        p->item[0].pos[i] = p->item[2].pos[i];
        p->item[2].pos[i] = t;
        t2 = p->item[1].pos[i];
        p->item[1].pos[i] = p->item[3].pos[i];
        p->item[3].pos[i] = t2;
    }
}

void ZUKAN_DETAIL_FORM_SetActorsNormalMode(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (p->obj[i] != 0)
            CLACT_SetActorObjMode((struct Actor *)(p->obj[i]), 0);
    }
    CLACT_SetActorObjMode((struct Actor *)p->act[0], 0);
    CLACT_SetActorObjMode((struct Actor *)p->act[1], 0);
    for (i = 0; i < 4; i++)
        CLACT_SetActorObjMode((struct Actor *)((struct Ov208Form *)((u8 *)p + i * 0x28))->row[0].obj, 0);
    G2x_SetBlendAlpha_(0x04000050, 0, 0x3f, 0xc, 4);
    G2x_SetBlendAlpha_(0x04001050, 8, 0x3f, 0xc, 4);
}

void ZUKAN_DETAIL_FORM_SetActorsAlphaMode(u16 *a0, struct Ov208Form *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (p->obj[i] != 0)
            CLACT_SetActorObjMode((struct Actor *)(p->obj[i]), 1);
    }
    CLACT_SetActorObjMode((struct Actor *)p->act[0], 1);
    CLACT_SetActorObjMode((struct Actor *)p->act[1], 1);
    for (i = 0; i < 4; i++)
        CLACT_SetActorObjMode((struct Actor *)((struct Ov208Form *)((u8 *)p + i * 0x28))->row[0].obj, 1);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)p->w6a4);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)p->w6a8);
}

void ZUKAN_DETAIL_FORM_GetModelOffsets(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality,
                         u32 side, u32 extra)
{
    u16 k;
    u8 i;

    for (i = 0; i < 5; i++)
        pos[i] = data_021C87C0[i];
    for (k = 0; k < 15; k++) {
        if (species == data_021C8854[k].species && form == data_021C8854[k].form &&
            side == data_021C8854[k].side &&
            (data_021C8854[k].gender == 3 || gender == data_021C8854[k].gender)) {
            for (i = 0; i < 5; i++)
                pos[i] = data_021C8854[k].pos[i];
            return;
        }
    }
}

void ZUKAN_DETAIL_FORM_ConvertModelPosition(struct Ov208Mdl *m, int i, Vec *out)
{
    out->x = FX_F32_TO_FX32(m->pos[i].x);
    out->y = FX_F32_TO_FX32(m->pos[i].y);
    out->z = FX_F32_TO_FX32(m->pos[i].z);
}

void ZUKAN_DETAIL_FORM_SelectModelPosition(int a, int b, int c)
{
    int m = 0;

    switch (b) {
    case 0:
        break;
    case 1:
        m = 3;
        break;
    case 2:
        m = 4;
        break;
    }
    ZUKAN_DETAIL_FORM_ConvertModelPosition((struct Ov208Mdl *)(a), (int)(m), (Vec *)(c));
}

void ZUKAN_DETAIL_FORM_CopyModelPosition(struct Ov208Mdl *m, int index, VecF *dst)
{
    *dst = m->pos[index];
}
