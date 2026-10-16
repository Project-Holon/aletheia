/*
 * file:     zukan_detail_area.c
 * unit:     yes
 * function: ZUKAN_DETAIL_AREA_SetHeapId, ZUKAN_DETAIL_AREA_Init, ZUKAN_DETAIL_AREA_Exit, ZUKAN_DETAIL_AREA_Main, ZUKAN_DETAIL_AREA_HandleKeyEvent, ZUKAN_DETAIL_AREA_ApplyPendingEffect, ZUKAN_DETAIL_AREA_BuildTownOrderTable, ZUKAN_DETAIL_AREA_LoadMapGraphics, ZUKAN_DETAIL_AREA_NoOpLoad, ZUKAN_DETAIL_AREA_CreateMapActors, ZUKAN_DETAIL_AREA_DeleteMapActors, ZUKAN_DETAIL_AREA_CreateTownIconActors, ZUKAN_DETAIL_AREA_DeleteTownIconActors, ZUKAN_DETAIL_AREA_CreateTownMarkerActors, ZUKAN_DETAIL_AREA_DeleteTownMarkerActors, ZUKAN_DETAIL_AREA_CreatePrintQueues, ZUKAN_DETAIL_AREA_DeletePrintQueues, ZUKAN_DETAIL_AREA_UpdatePrintQueues, ZUKAN_DETAIL_AREA_FlushPrintWindow, ZUKAN_DETAIL_AREA_CreateTextWindows, ZUKAN_DETAIL_AREA_DeleteTextWindows, ZUKAN_DETAIL_AREA_LoadSubScreenGraphics, ZUKAN_DETAIL_AREA_ApplySubScreenScroll, ZUKAN_DETAIL_AREA_UpdateScroll, ZUKAN_DETAIL_AREA_UpdateScrollFade, ZUKAN_DETAIL_AREA_NoOpUpdate, ZUKAN_DETAIL_AREA_UpdateSelectorAnim, ZUKAN_DETAIL_AREA_LoadMarkerResources, ZUKAN_DETAIL_AREA_ReleaseMarkerResources, ZUKAN_DETAIL_AREA_CreatePokemonIcon, ZUKAN_DETAIL_AREA_DeletePokemonIcon, ZUKAN_DETAIL_AREA_FindPlayerTownIndex, ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown, ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible, ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible, ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown, ZUKAN_DETAIL_AREA_SelectPlayerTown, ZUKAN_DETAIL_AREA_FindTownAtPoint, ZUKAN_DETAIL_AREA_GetTownPointDistance, ZUKAN_DETAIL_AREA_FindNearestTown, ZUKAN_DETAIL_AREA_HandleCursorInput, ZUKAN_DETAIL_AREA_HandleTownTouchInput, ZUKAN_DETAIL_AREA_UpdateMode, ZUKAN_DETAIL_AREA_HandleModeEvent, ZUKAN_DETAIL_AREA_LoadAreaEntries, ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay, ZUKAN_DETAIL_AREA_RequestModeEvent4, ZUKAN_DETAIL_AREA_DrawTownName, ZUKAN_DETAIL_AREA_SwitchAreaSet, ZUKAN_DETAIL_AREA_LoadAreaEntryData, ZUKAN_DETAIL_AREA_FreeAreaEntryData, ZUKAN_DETAIL_AREA_DrawAreaSetTitle, ZUKAN_DETAIL_AREA_BeginModeTransition, ZUKAN_DETAIL_AREA_BeginHideOverlay, ZUKAN_DETAIL_AREA_FinishHideOverlay, ZUKAN_DETAIL_AREA_DrawNoDataMessage, ZUKAN_DETAIL_AREA_ClearOverlayWindow, ZUKAN_DETAIL_AREA_RequestBlendRestore, ZUKAN_DETAIL_AREA_NoOpOverlay, ZUKAN_DETAIL_AREA_UpdateTerrainIcons, ZUKAN_DETAIL_AREA_ResetBlendAlpha, ZUKAN_DETAIL_AREA_ApplyBrightness, ZUKAN_DETAIL_AREA_SetupSplitWindows, ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness, ZUKAN_DETAIL_AREA_UpdateBlendPulse, ZUKAN_DETAIL_AREA_InitBlendPulse, ZUKAN_DETAIL_AREA_SetMapActorsNormalMode, ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode, ZUKAN_DETAIL_AREA_SetIconsNormalMode, ZUKAN_DETAIL_AREA_SetIconsAlphaMode
 * address:  0x021BF784
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
 *   GFL_HEAP_Free 0x020307B0  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_UTIL_UploadPaletteFromHandle  0x02049BDC  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BG_SYS_SetVisibleLayer 0x0204047C arm
 *   func_02040804 0x02040804 arm
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
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_AREA_SetHeapId 0x021BF784 thumb ov208
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   func_02049B68        0x02049B68  arm
 *   CLACT_RegisterPaletteEx        0x0204AC18  arm
 *   CLACT_RegisterCharacter        0x0204A6C8  arm
 *   CLACT_RegisterCellAnim        0x0204AF28  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   KEY_GetTrg 0x020362DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   ZUKAN_DETAIL_PROCSYS_AllocBuffer 0x021BC32C thumb
 *   ZUKAN_DETAIL_COMMON_AllocBlendWork 0x021BC448 thumb
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget 0x021BC518 thumb
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone 0x021BC508 thumb
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork 0x021BC464 thumb ov208
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer 0x021BC34C thumb ov208
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr 0x021BC3B4 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   ZUKAN_DETAIL_COMMON_GetFont 0x021BC3AC thumb ov208
 *   ZUKAN_DETAIL_COMMON_CreatePaletteAnim 0x021BC560 thumb ov208
 *   TOWNMAP_GRH_LoadTownInfo 0x021BBB24 thumb ov072
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   ov072_id 0x00000048 data a1
 *   ZUKAN_DETAIL_COMMON_FreeBgPalette 0x021BC97C thumb ov208
 *   ZUKAN_DETAIL_COMMON_DeletePaletteAnim 0x021BC61C thumb ov208
 *   TOWNMAP_GRH_FreeTownInfo 0x021BBB34 thumb ov072
 *   ov208_func_021BC3B4  0x021BC3B4  thumb  ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   data_021C85C0  0x021C85C0  data
 *   data_021C8618  0x021C8618  data
 *   ov208_func_021C0134  0x021C0134  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc  0x021BC844  thumb  ov208
 *   ov208_func_021C1AD4  0x021C1AD4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendIn  0x021BC4D8  thumb  ov208
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetMaxValue  0x021BC3BC  thumb  ov208
 *   ov208_func_021BC3A4  0x021BC3A4  thumb  ov208
 *   ov208_func_021BDC14  0x021BDC14  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_IsBlendBusy  0x021BC4C8  thumb  ov208
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ov208_func_021C1D0C  0x021C1D0C  thumb  ov208
 *   ov208_func_021C1D24  0x021C1D24  thumb  ov208
 *   ov208_func_021C10B8  0x021C10B8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendOut  0x021BC4E4  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ov208_func_021BC508  0x021BC508  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ov208_func_021C0968  0x021C0968  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull 0x021BC4F4 thumb ov208
 *   ZUKAN_DETAIL_COMMON_TransferPalettes 0x021BC6BC thumb ov208
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 *   d_021C8670 0x021C8670 data a2
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   data_021C8558  0x021C8558  data
 *   data_021C8560  0x021C8560  data
 *   data_021C8568  0x021C8568  data
 *   data_021C8580  0x021C8580  data
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   SYMBOL_MAP_CheckEventFlag  0x02166CD0  thumb
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   data_021C8570  0x021C8570  data
 *   data_021C85A4  0x021C85A4  data
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   POKE_TOOL_GetIconCellArcIdSub  0x0201BC78  thumb
 *   POKE_TOOL_GetIconCellEntryIdSub  0x0201BCEC  thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   SYMBOL_MAP_ResolveZoneId  0x02166C7C  thumb
 *   TOWNMAP_GRH_FindRecordIndex  0x021BBB48  thumb  ov072
 *   func_021C0C14  0x021C0C14  thumb  ov208
 *   data_021C8554  0x021C8554  data
 *   BUTTON_MAN_InitSphere 0x02051F1C arm
 *   BUTTON_MAN_InitSegment 0x0205207C arm
 *   BUTTON_MAN_SegmentSphereTest 0x02051F34 arm
 *   UI_GetInputMode 0x020355C4 arm
 *   KEY_GetCont 0x0203630C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Mag 0x0207CBD0 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   BUTTON_MAN_ScaleVec 0x020520A4 arm
 *   ov208_func_021C1920  0x021C1920  thumb  ov208
 *   ov208_func_021C1FE0  0x021C1FE0  thumb  ov208
 *   ov208_func_021C2090  0x021C2090  thumb  ov208
 *   ov208_func_021C20C0  0x021C20C0  thumb  ov208
 *   ov208_func_021C21D0  0x021C21D0  thumb  ov208
 *   func_021BDBAC  0x021BDBAC  thumb  ov208
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_Callback  0x0201EE60  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   func_021C0740  0x021C0740  thumb  ov208
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   func_0201D304  0x0201D304  thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   GF_FONT_MeasureWidestLine  0x0201D304  thumb
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 *   G2x_SetBlendAlpha_ 0x0207D63C  arm
 *   ov208_func_021BC518  0x021BC518  thumb  ov208
 *   ARC_UTIL_LoadHandleMemberWithSize  0x0204A39C  arm  arm9
 *   ZUKAN_DETAIL_TOUCHBAR_GetMode  0x021BDAD0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode  0x021BDAAC  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetEnabled  0x021BDAD4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind  0x021BDBB8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState  0x021BDBA0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled  0x021BDC48  thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb
 *   ZUKAN_DETAIL_GRAPHIC_Reset3dState 0x021BCF4C thumb ov208
 *   ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive 0x021BDC2C thumb ov208
 */
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"

/*
 * Work object of the Pokedex detail area screen, 0x438 bytes, allocated by
 * ZUKAN_DETAIL_AREA_Init. Every per-function view of the object is folded into
 * this one struct; the offsets keep the historical fNN names until they are
 * named in a later pass. The town marker table sits at 0x1E0 and the mode /
 * overlay tail at 0x424 (see struct Ov208AreaState).
 */
struct Ov208AreaWork {
    unsigned int f0;            /* 0x00 */
    unsigned int f4;            /* 0x04 */
    void *f8;                   /* 0x08 */
    void *fC;                   /* 0x0C */
    unsigned char pad10[0x10];
    void *f20;                  /* 0x20 */
    int f24;                    /* 0x24 */
    unsigned char pad28[8];
    unsigned int f30;           /* 0x30 */
    int f34;                    /* 0x34 */
    unsigned char pad38[8];
    void *f40;                  /* 0x40 */
    unsigned char pad44[8];
    unsigned int f4C;           /* 0x4C */
    unsigned char pad50[4];
    unsigned int f54;           /* 0x54 */
    unsigned int f58;           /* 0x58 */
    unsigned int f5C;           /* 0x5C */
    unsigned char pad60[4];
    int f64;                    /* 0x64 */
    unsigned int f68;           /* 0x68 */
    int f6C;                    /* 0x6C */
    unsigned int f70;           /* 0x70 */
    unsigned int f74;           /* 0x74 */
    unsigned char f78;          /* 0x78 */
    unsigned char f79;          /* 0x79 */
    unsigned char pad7A[6];
    unsigned char f80;          /* 0x80 */
    unsigned char f81;          /* 0x81 */
    unsigned char pad82[2];
    unsigned int f84;           /* 0x84 */
    unsigned int f88;           /* 0x88 */
    unsigned int f8C;           /* 0x8C */
    unsigned int f90;           /* 0x90 */
    unsigned int f94;           /* 0x94 */
    unsigned int f98;           /* 0x98 */
    unsigned int f9C;           /* 0x9C */
    unsigned int fA0;           /* 0xA0 */
    unsigned int fA4;           /* 0xA4 */
    unsigned int fA8;           /* 0xA8 */
    unsigned int fAC;           /* 0xAC */
    unsigned int fB0;           /* 0xB0 */
    unsigned int fB4;           /* 0xB4 */
    unsigned int fB8;           /* 0xB8 */
    unsigned char padBC[0xC];
    void *fC8;                  /* 0xC8 */
    void *fCC;                  /* 0xCC */
    void *fD0;                  /* 0xD0 */
    unsigned int fD4;           /* 0xD4 */
    unsigned char fD8;          /* 0xD8 */
    unsigned char padD9[0x1D0 - 0xD9];
    void *f1D0;                 /* 0x1D0 */
    void *f1D4;                 /* 0x1D4 */
    unsigned int f1D8;          /* 0x1D8 */
    unsigned short f1DC;        /* 0x1DC */
    unsigned char pad1DE[0x3C8 - 0x1DE];
    unsigned int f3C8;          /* 0x3C8 */
    unsigned char pad3CC[0x40C - 0x3CC];
    void *f40C;                 /* 0x40C */
    void *f410;                 /* 0x410 */
    unsigned char f414;         /* 0x414 */
    unsigned char pad415[3];
    void *f418;                 /* 0x418 */
    void *f41C;                 /* 0x41C */
    void *f420;                 /* 0x420 */
    unsigned int f424;          /* 0x424 */
    unsigned int f428;          /* 0x428 */
    unsigned int f42C;          /* 0x42C */
    unsigned int f430;          /* 0x430 */
    unsigned int f434;          /* 0x434 */
};

extern u32 GFL_HEAP_Free(void *p);

extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void ARC_TOOL_DeleteHandle(void *h);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);

extern void TCB_DeleteTask(struct Node *n);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);

extern void *ARC_TOOL_CreateHandle(unsigned int id, unsigned int heap);

extern void BG_SYS_FillScrollArea(unsigned,unsigned,unsigned);

extern void BG_SYS_SetVisibleLayer(int,u16);

extern u32 func_02040804(u32 layer);

extern unsigned PRINTSYS_QUE_Create(void *);

extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);

extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);

extern void *BMP_WIN_GetBmp(struct Descriptor *a);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void BMP_WIN_TransferChars(struct Descriptor *a);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern unsigned int MSGDATA_Delete(struct Rec *rec);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void BG_SYS_SetFlagField06(u32 layer);

void ZUKAN_DETAIL_HEADBAR_SetIconKind(struct Ov208Icon *p, int kind);

int ZUKAN_DETAIL_HEADBAR_GetIconKind(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_SetIconSpecies(struct Ov208Icon *p);

void ZUKAN_DETAIL_HEADBAR_SetIconForm(struct Ov208Icon *p);

extern void *ZUKAN_SAVE_GetFromGameData(void *a);

extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);

extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);

#define WP(o) (*(void **)(p + (o)))

#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))

#define FIELD(n) TOWNMAP_GRH_GetTownInfoValue(*(char **)(p+0x3c8),i,n)

#define SLOT4C(i) (((u32 *)(p + 0x4c))[i])

#define SLOT5C(i) (((u32 *)(p + 0x5c))[i])

#define REG32(a) (*(volatile u32 *)(a))

#define REG16(a) (*(volatile u16 *)(a))

#define H(o) (*(u16 *)(p + (o)))

struct BigObj;

struct SaveBlock;

struct Rec44;

struct Vec3;

typedef short          s16;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u8 pri;
    u8 f7;
} ObjPos;

typedef struct {
    u32 w[4];
} BankDesc;

typedef struct {
    u8 v[7];
} Row7;



struct WinCfg {
    u8 bg;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
    u8 pal;
    u8 base;
};

struct WinCfg2 {
    struct WinCfg e[2];
};

struct WinCfg4 {
    struct WinCfg e[4];
};





struct Ball { struct Vec3 p; int radius; };

struct Seg { struct Vec3 a,b; int radius; };

struct Out { u32 hit; struct Vec3 n; int distance; };



typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry;



typedef short          s16;

typedef signed short   s16;



typedef int BOOL;

typedef enum { ONE = 1 } One;

extern void MI_CpuFill8(void *p, u32 v, u32 n);

extern void BG_SYS_InitBgLayer(u8 bgId, const struct BgTemplate *tmpl, u8 type);

extern void BG_SYS_FreeSlot(u8);

extern void BG_SYS_SetPlaneVisible(u8,u8);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);

extern u32  CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern u32  CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleasePalette(u32 i);

extern struct Obj *CLACT_CreateActor(u32 owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 CLACT_GetActorDrawEnable(struct Obj *p);

extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);

extern void func_020355D8(u8 v);

extern u32 KEY_GetTrg(void);

extern u32 CLACT_IsActorAnimActive(struct Actor *a);

extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern void CLACT_SetActorBgPriority(int, int);

extern u32 KEY_GetRepeat(void);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern int GF_OVERLAY_Load(s32 handle);

extern void *ZUKAN_DETAIL_PROCSYS_AllocBuffer(struct Ov208Fsm *p, u32 size, u32 heap);

extern void *ZUKAN_DETAIL_COMMON_AllocBlendWork(u32 heap);

extern void ZUKAN_DETAIL_COMMON_InitBrightnessTarget(int *p);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessNone(int flag, int *p);

extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *);

extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *);

extern void GF_OVERLAY_Unload(int);

extern int ZUKAN_DETAIL_COMMON_GetWorkPtr(int *p);

extern u16 func_021BC3BC(int *ctx);

extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);

extern int ZUKAN_DETAIL_COMMON_GetSource(int *ctx);

extern int GAME_DATA_CheckSaveFlag(int a, int b);

extern int ZUKAN_DETAIL_COMMON_GetDisplay(int *ctx);

extern void func_021BDBA0(void *s);

extern u16 ZUKAN_DETAIL_COMMON_GetCurrentEntry(void *p);

extern void ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(char *p);

extern void ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(struct Ov208Ctx *p);

extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);

extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);

extern void ZUKAN_SAVE_GetViewGenderAndForm(void *, u32, u32 *, u32 *, u32 *, u16);

extern int ZUKAN_DETAIL_COMMON_GetFont(int *p);

extern u8 GAME_DATA_GetSeason(const struct BigObj *p);

extern int TOWNMAP_GRH_LoadTownInfo(int);

extern void *ZUKAN_DETAIL_COMMON_CreatePaletteAnim(u32,u16);

extern void ZUKAN_DETAIL_COMMON_FreeBgPalette(char *p);

extern void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(char *p);

extern void TOWNMAP_GRH_FreeTownInfo(void *);

extern void *ov208_func_021BC3B4(int key);

extern void *ov208_func_021BC3B8(int key);

extern void GX_SetGraphicsMode(int dispMode, int bgMode, int bg0_2d3d);

extern void ov208_func_021C0134(u16 *heap, u8 *p, int key);

extern u32  ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);

extern void ov208_func_021C1AD4(u16 *heap, u8 *p, int key);

extern void ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(u32 fade);

extern void ov208_func_021BC718(u32 fade);

extern void ov208_func_021BC4F4(int sub, u32 blend);

extern void ZUKAN_DETAIL_COMMON_StartBlendIn(u32 blend);

extern void ov208_func_021BC6D8(u32 fade);

extern u16  ZUKAN_DETAIL_COMMON_GetMaxValue(char *p);

extern int  ov208_func_021BC3A4(int key);

extern void ov208_func_021BDC14(void *s, int b);

extern int  ZUKAN_DETAIL_COMMON_IsBlendBusy(u32 blend);

extern int  ov208_func_021BC6C8(u32 fade);

extern void ov208_func_021C1D0C(u16 *heap, u8 *p, int key);

extern void ov208_func_021C1D24(u16 *heap, u8 *p, int key);

extern void ov208_func_021C10B8(u16 *heap, u8 *p, int key);

extern void ZUKAN_DETAIL_COMMON_StartBlendOut(u32 blend);

extern void ov208_func_021BC6F8(u32 fade);

extern void ov208_func_021BDAE8(void *s, int v);

extern void ov208_func_021BC508(int sub, u32 blend);

extern void ov208_func_021BC99C(u32 win);

extern void ov208_func_021C0968(u16 *heap, u8 *p, int key);

extern void ZUKAN_DETAIL_COMMON_UpdateBlendFades(u32 main, u32 sub);

extern void ov208_func_021BC678(u32 fade);

extern void ZUKAN_DETAIL_COMMON_SetBrightnessFull(int flag, int *p);

extern void ZUKAN_DETAIL_COMMON_TransferPalettes(char *p);

extern u16 TOWNMAP_GRH_GetTownInfoValue(char *, int, int);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);

extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);

extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);

extern void CLACT_DeleteRenderer(void *);

extern int  SYMBOL_MAP_CheckEventFlag(int a, u32 msg);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern int POKE_TOOL_GetIconPaletteArcId(void);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern int POKE_TOOL_GetIconCellArcIdSub(void);

extern int POKE_TOOL_GetIconCellEntryIdSub(void);

extern u32  POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);

extern u32  POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);

extern void *GAME_DATA_GetField114(struct SaveBlock *p);

extern u16  GAME_DATA_GetPlayerZoneId(const struct Rec44 *a);

extern u32  SYMBOL_MAP_ResolveZoneId(int a, u32 b);

extern int TOWNMAP_GRH_FindRecordIndex(int a0, int a1);

extern u8   func_021C0C14(u16 *heap, u8 *p, int key);

extern void BUTTON_MAN_InitSphere(struct Ball *,struct Vec3 *,u32);

extern void BUTTON_MAN_InitSegment(char *p, struct Vec3 *q, struct Vec3 *r, u32 v);

extern u32 BUTTON_MAN_SegmentSphereTest(struct Seg *,struct Ball *,struct Out *);

extern u8 UI_GetInputMode(void);

extern unsigned int KEY_GetCont(void);

extern void VEC_Subtract(struct Vec3 *a, struct Vec3 *b, struct Vec3 *out);

extern int VEC_Mag(struct Vec3 *v);

extern void VEC_Normalize(struct Vec3 *src, struct Vec3 *dst);

extern void BUTTON_MAN_ScaleVec(const struct Vec3 *v, int s, struct Vec3 *dst);

extern void ov208_func_021C1920(u16 *heap, u8 *p, int key, int mode);

extern void ov208_func_021C1FE0(u16 *heap, u8 *p, int key);

extern void ov208_func_021C2090(u16 *heap, u8 *p, int key);

extern void ov208_func_021C20C0(u16 *heap, u8 *p, int key);

extern void ov208_func_021C21D0(u16 *heap, u8 *p, int key);

extern void func_021BDBAC(void *s, u32 on);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);

extern u32 ZONEDATA_GetPlaceNameId(u32 id);

extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

extern void *ARC_UTIL_LoadHandleMemberWithSize(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);

extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

extern u16 BMP_GetWidth(const struct Bmp *bmp);

extern void func_021C0C8C(u16 *, u8 *, int, int);

extern u32 GF_FONT_MeasureWidestLine(struct StrObj *s, u32 a, u32 b);


extern void G2x_SetBlendAlpha_(volatile void *, int, int, int, int);

extern void ov208_func_021BC518(u32 blend);

int ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetMode(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);

int ZUKAN_DETAIL_TOUCHBAR_GetMode(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetEnabled(struct Ov208Scene *p, int v);

void ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind);

void ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(struct Ov208Scene *p, int b);

int ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive(char *p);

void ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(struct Ov208Scene *p, u32 on);

void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v);

u32 ZUKAN_DETAIL_AREA_Init(void *a0,u32 a1,u16 *heap,u32 a3,int key);

u32 ZUKAN_DETAIL_AREA_Exit(void *a0, u32 a1, void *a2, char *p, void *a4);

int ZUKAN_DETAIL_AREA_Main(void *proc, int *seq, u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_HandleKeyEvent(void *a0, void *a1, void *heap, struct Ov208AreaState *st, int *obj, int key);

void ZUKAN_DETAIL_AREA_ApplyPendingEffect(void *unused, char *p);

void ZUKAN_DETAIL_AREA_BuildTownOrderTable(u16 *unused, char *p, int a2);

void ZUKAN_DETAIL_AREA_LoadMapGraphics(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_NoOpLoad(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_CreateMapActors(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_DeleteMapActors(void *unused, char *p, void *a2);

void ZUKAN_DETAIL_AREA_CreateTownIconActors(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_DeleteTownIconActors(void *unused, char *p, void *a2);

void ZUKAN_DETAIL_AREA_CreateTownMarkerActors(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(void *a0, char *p, void *a2);

void ZUKAN_DETAIL_AREA_CreatePrintQueues(unsigned short *a, char *b, int a2);

void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *unused, char *p, void *a2);

void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_FlushPrintWindow(u16 *heap, u8 *p, int key, u8 i);

void ZUKAN_DETAIL_AREA_CreateTextWindows(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_DeleteTextWindows(void *unused, char *p, void *a2);

void ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, u8 *p, void *a2);

void ZUKAN_DETAIL_AREA_UpdateScroll(int a, int b, int c);

void ZUKAN_DETAIL_AREA_UpdateScrollFade(int a, unsigned char *p, int a2);

void ZUKAN_DETAIL_AREA_NoOpUpdate(int a0, int a1, int a2);

void ZUKAN_DETAIL_AREA_UpdateSelectorAnim(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_ReleaseMarkerResources(void *a, char *q, void *a2);

u32 ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);

void ZUKAN_DETAIL_AREA_DeletePokemonIcon(void *a, void *b);

u8 ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *heap, u8 *p, int key, int on);

u32 ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(void *a0, u8 *p, void *a2);

void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_SelectPlayerTown(int a, char *b, int c);

u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused,char *p,int unused2,u8 x,u8 y);

int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out);

u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, char *p, int key, u8 x, u8 y);

void ZUKAN_DETAIL_AREA_HandleCursorInput(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, int key, int mode);

void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(int a, int b, int c);

void ZUKAN_DETAIL_AREA_RequestModeEvent4(void *a, int b, int c);

void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, u8 *p, int key, int dir, int touch);

void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int a, int b, int c);

void ZUKAN_DETAIL_AREA_FreeAreaEntryData(int a);

void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_BeginModeTransition(void *a, char *b, int c);

void ZUKAN_DETAIL_AREA_BeginHideOverlay(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_FinishHideOverlay(void *unused, u8 *p);

void ZUKAN_DETAIL_AREA_DrawNoDataMessage(void *a0, u8 *st, void *a2);

void ZUKAN_DETAIL_AREA_ClearOverlayWindow(void *unused, char *p, int key);

void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_NoOpOverlay(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_ResetBlendAlpha(char *a0);

void ZUKAN_DETAIL_AREA_ApplyBrightness(char *p);

void ZUKAN_DETAIL_AREA_SetupSplitWindows(char *p);

void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(char *p);

void ZUKAN_DETAIL_AREA_UpdateBlendPulse(u8 *p);

void ZUKAN_DETAIL_AREA_InitBlendPulse(u8 *p);

void ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, u8 *p, int key);

void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, u8 *p, int key);

extern s16 FX_SinCosTable_[];

extern u8 ov072_id[];

extern const struct BgEntry data_021C85C0[2];

extern const struct BgEntry data_021C8618[2];

extern const u16 d_021C8670[];

extern const BankDesc data_021C8580;

extern const Row7 data_021C8558;

extern const Row7 data_021C8560;

extern const Row7 data_021C8568;

extern const struct WinCfg2 data_021C8570;

extern const struct WinCfg4 data_021C85A4;

extern const struct Pt data_021C8554;

extern const u8 data_021C8E14[3][2];

extern u8 data_021C8E1A[3][4];

extern s16 FX_SinCosTable_[];

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v)
{
    *p = v;
}

/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */
u32 ZUKAN_DETAIL_AREA_Init(void *a0,u32 a1,u16 *heap,u32 a3,int key)
{
    u8 *p;
    int save;
    u8 i;
    save = ZUKAN_DETAIL_COMMON_GetSource((int *)key);
    GF_OVERLAY_Load((int)ov072_id);
    p = (u8 *)ZUKAN_DETAIL_PROCSYS_AllocBuffer(a0,0x438,*heap);
    i = 0;
    MI_CpuFill8(p,0,0x438);
    ((struct Ov208AreaWork *)p)->f0 = ZUKAN_DETAIL_GRAPHIC_Reset3dState((char *)ZUKAN_DETAIL_COMMON_GetDisplay((int *)key));
    ((struct Ov208AreaWork *)p)->f4 = ZUKAN_DETAIL_COMMON_GetFont((int *)key);
    for (;i<2;i++) *(u32 *)(p+i*4+0x5c)=0;
    ((struct Ov208AreaWork *)p)->f64=0;
    ((struct Ov208AreaWork *)p)->f8C=0;
    ((struct Ov208AreaWork *)p)->f90=1;
    ((struct Ov208AreaWork *)p)->f94=0;
    ((struct Ov208AreaWork *)p)->f6C=0;
    ((struct Ov208AreaWork *)p)->f70=0;
    ((struct Ov208AreaWork *)p)->f74=0;
    p[0x78]=GAME_DATA_GetSeason((const struct BigObj *)save);
    p[0x79]=0xff;
    ((struct Ov208AreaWork *)p)->f84=0;
    ((struct Ov208AreaWork *)p)->f88=1;
    ((struct Ov208AreaWork *)p)->f3C8=TOWNMAP_GRH_LoadTownInfo(*heap);
    ZUKAN_DETAIL_AREA_BuildTownOrderTable(heap,(char *)p,key);
    ((struct Ov208AreaWork *)p)->f40C=ARC_TOOL_CreateHandle(0xb2,*heap);
    ((struct Ov208AreaWork *)p)->f410=GFL_USE_AddMainTask((u32)ZUKAN_DETAIL_AREA_ApplyPendingEffect,(u32)p,1);
    p[0x414]=0;
    ZUKAN_DETAIL_AREA_CreatePrintQueues(heap,(char *)p,key);
    ((struct Ov208AreaWork *)p)->f418=ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ((struct Ov208AreaWork *)p)->f41C=ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)(*(u32 * *)&((struct Ov208AreaWork *)p)->f418));
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)(*(u32 * *)&((struct Ov208AreaWork *)p)->f41C));
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0,(int *)(*(u32 * *)&((struct Ov208AreaWork *)p)->f418));
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1,(int *)(*(u32 * *)&((struct Ov208AreaWork *)p)->f41C));
    ((struct Ov208AreaWork *)p)->f420=ZUKAN_DETAIL_COMMON_CreatePaletteAnim(*heap,0xa);
    ((struct Ov208AreaWork *)p)->f424=0;
    ((struct Ov208AreaWork *)p)->f428=1;
    ((struct Ov208AreaWork *)p)->f42C=0;
    ((struct Ov208AreaWork *)p)->f430=1;
    ((struct Ov208AreaWork *)p)->f434=1;
    return 1;
}

/* Caller explicitly loads r2 for the three-argument teardown helpers. */
u32 ZUKAN_DETAIL_AREA_Exit(void *a0, u32 a1, void *a2, char *p, void *a4)
{
    u8 i;
    ZUKAN_DETAIL_AREA_FreeAreaEntryData(((struct Ov208AreaWork *)p)->f94);
    for (i = 0; i < 2; i++) {
        char *q = p + i * 4;
        if (((struct Ov208AreaWork *)q)->f5C != 0) ZUKAN_DETAIL_AREA_DeletePokemonIcon((void *)(((struct Ov208AreaWork *)q)->f4C), (void *)(((struct Ov208AreaWork *)q)->f5C));
        ((struct Ov208AreaWork *)q)->f5C = 0;
    }
    ZUKAN_DETAIL_AREA_ReleaseMarkerResources(a2, p, a4);
    ZUKAN_DETAIL_AREA_ApplySubScreenScroll(a2, (u8 *)p, a4);
    ZUKAN_DETAIL_AREA_DeleteTextWindows(a2, p, a4);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(((struct Ov208AreaWork *)p)->f8);
    ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(a2, p, a4);
    ZUKAN_DETAIL_AREA_DeleteTownIconActors(a2, p, a4);
    ZUKAN_DETAIL_AREA_DeleteMapActors(a2, p, a4);
    ZUKAN_DETAIL_COMMON_DeletePaletteAnim(((struct Ov208AreaWork *)p)->f420);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Ov208AreaWork *)p)->f41C);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(((struct Ov208AreaWork *)p)->f418);
    ZUKAN_DETAIL_AREA_DeletePrintQueues(a2, p, a4);
    TCB_DeleteTask(((struct Ov208AreaWork *)p)->f410);
    ARC_TOOL_DeleteHandle(((struct Ov208AreaWork *)p)->f40C);
    TOWNMAP_GRH_FreeTownInfo((void *)((struct Ov208AreaWork *)p)->f3C8);
    ZUKAN_DETAIL_PROCSYS_FreeBuffer(a0);
    GF_OVERLAY_Unload((int)ov072_id);
    return 1;
}

int ZUKAN_DETAIL_AREA_Main(void *proc, int *seq, u16 *heap, u8 *p, int key)
{
    void *scene;
    void *icon;
    u32 j;
    u32 k;
    u8 i;
    int ready;

    scene = ov208_func_021BC3B4(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        GX_SetGraphicsMode(1, 5, 0);
        for (j = 0; j < 2; j++) {
            BG_SYS_FreeLayerBuf((u8)data_021C85C0[j].bg);
            BG_SYS_InitBgLayer(data_021C85C0[j].bg, &data_021C85C0[j].tmpl, data_021C85C0[j].type);
            BG_SYS_FreeSlot(data_021C85C0[j].bg);
            BG_SYS_SetPlaneVisible(data_021C85C0[j].bg, data_021C85C0[j].on);
        }
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                BG_SYS_FillScrollArea(i, 0, 0);
                BG_SYS_FillScrollArea(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        BG_SYS_SetVisibleLayer(2, 2);
        BG_SYS_SetVisibleLayer(3, 3);
        BG_SYS_SetVisibleLayer(0, 1);
        BG_SYS_SetVisibleLayer(6, 1);
        BG_SYS_SetVisibleLayer(7, 2);
        BG_SYS_SetVisibleLayer(4, 3);
        ZUKAN_DETAIL_AREA_LoadMapGraphics(heap, p, key);
        ov208_func_021C0134(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateTownIconActors(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateTownMarkerActors(heap, p, key);
        W(8) = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, 1, 4, 9, 10);
        ZUKAN_DETAIL_AREA_CreateTextWindows(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadMarkerResources(heap, p, key);
        ov208_func_021C1AD4(heap, p, key);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + W(0x64) * 4 + 0x5c)), 1);
        ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(heap, p, key);
        if (W(0x90) == 1)
            ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(heap, p, key, 1);
        ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(W(0x420));
        ov208_func_021BC718(W(0x420));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(1, W(0x41c));
        ZUKAN_DETAIL_AREA_SetIconsNormalMode(heap, p, key);
        break;
    case 2:
        *seq = 3;
        ZUKAN_DETAIL_COMMON_StartBlendIn(W(0x418));
        ov208_func_021BC6D8(W(0x420));
        if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) != 2) {
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 1, ZUKAN_DETAIL_COMMON_GetMaxValue((char *)key) > 1);
            ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scene, 0);
        } else {
            ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scene, 1);
        }
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 0);
        W(0x88) = 0;
        ov208_func_021BDC14(scene, GAME_DATA_CheckSaveFlag(ov208_func_021BC3A4(key), 18));
        if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 1);
            ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
        }
        break;
    case 3:
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 2 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(heap, p, key);
            ov208_func_021C1D0C(heap, p, key);
            *seq = 4;
        }
        break;
    case 4:
        if (W(0x84) == 0) {
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
            W(0x88) = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x424) != 0) {
            ov208_func_021C1D24(heap, p, key);
            *seq = 6;
        } else {
            if (W(0x90) == 1)
                ZUKAN_DETAIL_AREA_UpdateBlendPulse(p);
            ov208_func_021C10B8(heap, p, key);
        }
        break;
    case 6:
        if (W(0x84) == 0) {
            ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(heap, p, key);
            *seq = 7;
            ZUKAN_DETAIL_COMMON_StartBlendOut(W(0x418));
            ov208_func_021BC6F8(W(0x420));
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (W(0x424) == 2)
                ov208_func_021BDAE8(scene, 0);
        }
        break;
    case 7:
        ready = 0;
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(W(0x418)) == 0 && ov208_func_021BC6C8(W(0x420)) == 0
            && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0) {
            if (W(0x424) == 2) {
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
        ZUKAN_DETAIL_AREA_SetIconsAlphaMode(heap, p, key);
        ov208_func_021BC508(1, W(0x41c));
        break;
    case 9:
        ZUKAN_DETAIL_AREA_NoOpLoad(heap, p, key);
        GX_SetGraphicsMode(1, 0, 0);
        for (k = 0; k < 2; k++) {
            BG_SYS_FreeLayerBuf((u8)data_021C8618[k].bg);
            BG_SYS_InitBgLayer(data_021C8618[k].bg, &data_021C8618[k].tmpl, data_021C8618[k].type);
            BG_SYS_FreeSlot(data_021C8618[k].bg);
            BG_SYS_SetPlaneVisible(data_021C8618[k].bg, data_021C8618[k].on);
        }
        return 1;
    }
    if (*seq >= 2) {
        ov208_func_021BC99C(W(8));
        ov208_func_021C0968(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateSelectorAnim(heap, p, key);
    }
    ZUKAN_DETAIL_AREA_UpdateMode(heap, p, key);
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(W(0x418), W(0x41c));
    ov208_func_021BC678(W(0x420));
    ZUKAN_DETAIL_AREA_UpdatePrintQueues(heap, p, key);
    return 0;
}

#define OBJ(i) (*(u32 *)(p + (i) * 4 + 0xbc))

void ZUKAN_DETAIL_AREA_HandleKeyEvent(void *a0, void *a1, void *heap, struct Ov208AreaState *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = ZUKAN_DETAIL_COMMON_GetWorkPtr(obj);
    flag = 0;
    switch (key) {
    case 16: case 19:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 17: case 18: case 20:
        st->keyFlag = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 8: case 9: case 19:
        flag = 1;
        st->keyFlag = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies((char *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, (u8 *)st, (int)obj);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay((int)heap, (int)st, (int)obj);
            st->overlayPending = 1;
            st->overlayReady = 0;
            st->overlayCommitted = 0;
        } else {
            st->overlayPending = 1;
            st->overlayReady = 1;
            st->overlayCommitted = 0;
        }
        break;
    }
    case 13: {
        u16 old = ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj);
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies((struct Ov208Ctx *)obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, (u8 *)st, (int)obj);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay((int)heap, (int)st, (int)obj);
            st->overlayPending = 1;
            st->overlayReady = 0;
            st->overlayCommitted = 0;
        } else {
            st->overlayPending = 1;
            st->overlayReady = 1;
            st->overlayCommitted = 0;
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->mode = 2;
        return;
    case 6: case 8: case 9:
        st->mode = 1;
        return;
    case 3:
        if (st->overlayPending != 0) {
            st->overlayCommitted = 1;
            if (st->overlayReady != 0) {
                st->overlayPending = 0;
                func_021BDBA0((void *)sc);
                return;
            }
        }
        break;
    case 4:
        if (st->overlayPending != 0) {
            st->overlayCommitted = 1;
            if (st->overlayReady != 0) {
                st->overlayPending = 0;
                func_021BDBA0((void *)sc);
                return;
            }
        }
        break;
    case 5:
        GAME_DATA_SetSaveFlag((void *)ZUKAN_DETAIL_COMMON_GetSource(obj), 0x12, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sc));
        func_021BDBA0((void *)sc);
        return;
    case 19:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, (u8 *)st, (int)obj, 6);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((void *)sc);
        }
        break;
    }
}

void ZUKAN_DETAIL_AREA_ApplyPendingEffect(void *unused, char *p)
{
    switch (((struct Ov208AreaWork *)p)->f414) {
    case 1: ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(p); ZUKAN_DETAIL_AREA_ResetBlendAlpha(p); break;
    case 2: ZUKAN_DETAIL_AREA_ApplyBrightness(p); ZUKAN_DETAIL_AREA_SetupSplitWindows(p); break;
    case 3:
        ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(p);
        ZUKAN_DETAIL_AREA_ApplyBrightness(p);
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(0, (int *)(((struct Ov208AreaWork *)p)->f418));
        break;
    }
    ((struct Ov208AreaWork *)p)->f414 = 0;
    ZUKAN_DETAIL_COMMON_TransferPalettes(((struct Ov208AreaWork *)p)->f420);
}

void ZUKAN_DETAIL_AREA_BuildTownOrderTable(u16 *unused, char *p, int a2)
{
    u8 i;
    for (i = 0; i < 61; i++) {
        u16 value = TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Ov208AreaWork *)p)->f3C8, i, 0);
        u8 j;
        for (j = 0; j < 61; j++) {
            if (value == d_021C8670[j]) {
                *(u8 *)(p + i + 0x3cc) = j;
                break;
            }
        }
    }
}

void ZUKAN_DETAIL_AREA_LoadMapGraphics(u16 *heap, u8 *p, int key)
{
    void *h;

    h = ARC_TOOL_CreateHandle(0x55, *heap);
    func_02049B68(h, 0, 2, 0x6000, 0x2000, *heap);
    func_02049B68(h, 0, 2, 0x4000, 0x2000, *heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 5, 2, 0, 0x4000, 0, *heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 7, 3, 0, 0xc000, 0, *heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x11, 2, 0, 0x800, 0, *heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x10, 3, 0, 0x800, 0, *heap);
    ARC_TOOL_DeleteHandle(h);
}

void ZUKAN_DETAIL_AREA_NoOpLoad(u16 *heap, u8 *p, int key)
{
}

void ZUKAN_DETAIL_AREA_CreateMapActors(u16 *heap, u8 *p, int key)
{
    BankDesc desc;
    Row7 anim, pri, pal;
    ObjPos pos;
    struct PtS pt;
    void *h;
    u8 i;

    desc = data_021C8580;
    WP(0x1d4) = CLACT_CreateRenderer((u8 *)(&desc), 1, *heap);
    W(0x1d0) = (u32)CLACT_CreateUnit(0x10, 0, *heap);
    CLACT_SetUnitRenderer((struct Bank *)W(0x1d0), WP(0x1d4));

    h = ARC_TOOL_CreateHandle(0x55, *heap);
    W(0x9c) = CLACT_RegisterPaletteEx(h, 2, 0, 0, 0, 5, *heap);
    W(0x98) = CLACT_RegisterCharacter(h, 8, 0, 0, *heap);
    W(0xa0) = CLACT_RegisterCellAnim(h, 0xc, 0x13, *heap);
    ARC_TOOL_DeleteHandle(h);

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    W(0xa8) = CLACT_RegisterPaletteEx(h, 6, 0, 0xa0, 0, 2, *heap);
    W(0xa4) = CLACT_RegisterCharacter(h, 0x10, 0, 0, *heap);
    W(0xac) = CLACT_RegisterCellAnim(h, 0x1d, 0x2e, *heap);
    ARC_TOOL_DeleteHandle(h);

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    W(0xb4) = CLACT_RegisterPaletteEx(h, 5, 0, 0xe0, 0, 1, *heap);
    W(0xb0) = CLACT_RegisterCharacter(h, 0xf, 0, 0, *heap);
    W(0xb8) = CLACT_RegisterCellAnim(h, 0x1c, 0x2d, *heap);
    ARC_TOOL_DeleteHandle(h);

    anim = data_021C8560;
    pri = data_021C8558;
    pal = data_021C8568;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    for (i = 4; i < 7; i++)
        OBJ(i) = (u32)CLACT_CreateActor((u32)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
    for (i = 0; i < 4; i++)
        OBJ(i) = (u32)CLACT_CreateActor((u32)W(0x1d0), W(0xa4), W(0xa8), W(0xac), &pos, 0, *heap);

    for (i = 0; i < 7; i++) {
        CLACT_SetActorAnimSeq((struct Obj *)OBJ(i), anim.v[i]);
        CLACT_SetActorAutoAnim((struct Obj *)OBJ(i), 1);
        CLACT_SetActorBgPriority(OBJ(i), pri.v[i]);
        CLACT_SetActorDrawPriority((struct Node *)OBJ(i), pal.v[i]);
        CLACT_SetActorDrawEnable((struct Obj *)OBJ(i), 0);
        CLACT_SetActorObjMode((struct Actor *)OBJ(i), 1);
    }

    pt.x = 0x80;
    pt.y = 0x60;
    for (i = 0; i < 4; i++)
        CLACT_AddActorSurfacePos((struct Obj *)OBJ(i), (const struct Vec2 *)(&pt), 0);

    p[0xd8] = 7;
}

/*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 */
void ZUKAN_DETAIL_AREA_DeleteMapActors(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++) CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0xbc));
    CLACT_ReleaseCellAnim(((struct Ov208AreaWork *)p)->fB8);
    CLACT_ReleaseCharacter(((struct Ov208AreaWork *)p)->fB0);
    CLACT_ReleasePalette(((struct Ov208AreaWork *)p)->fB4);
    CLACT_ReleaseCellAnim(((struct Ov208AreaWork *)p)->fAC);
    CLACT_ReleaseCharacter(((struct Ov208AreaWork *)p)->fA4);
    CLACT_ReleasePalette(((struct Ov208AreaWork *)p)->fA8);
    CLACT_ReleaseCellAnim(((struct Ov208AreaWork *)p)->fA0);
    CLACT_ReleaseCharacter(((struct Ov208AreaWork *)p)->f98);
    CLACT_ReleasePalette(((struct Ov208AreaWork *)p)->f9C);
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Ov208AreaWork *)p)->f1D0);
    CLACT_DeleteRenderer(((struct Ov208AreaWork *)p)->f1D4);
}

void ZUKAN_DETAIL_AREA_CreateTownIconActors(u16 *heap, u8 *p, int key)
{
    ObjPos pos;
    u8 i;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    for (i = 0; i < 0x3d; i++) {
        pos.x = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 0x19);
        pos.y = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 0x1a);
        *(u32 *)(p + i * 4 + 0xdc) = (u32)CLACT_CreateActor((u32)W(0), W(0xb0), W(0xb4), W(0xb8), &pos, 0, *heap);
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + i * 4 + 0xdc)), TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 0x18));
        CLACT_SetActorAutoAnim((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 1);
        CLACT_SetActorBgPriority(*(u32 *)(p + i * 4 + 0xdc), 2);
        CLACT_SetActorDrawPriority((struct Node *)(*(u32 *)(p + i * 4 + 0xdc)), 4);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + i * 4 + 0xdc), 0);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 4 + 0xdc)), 1);
    }
}

/*
 * Releases each of the 0x3D handles held from +0xDC on.
 */
void ZUKAN_DETAIL_AREA_DeleteTownIconActors(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++)
        CLACT_DeleteActor((struct Obj *)(*(int *)(p + i * 4 + 0xdc)));
}

void ZUKAN_DETAIL_AREA_CreateTownMarkerActors(u16 *heap, u8 *p, int key)
{
    int k;
    u8 i;
    u16 kind;
    u16 msg;
    ObjPos pos;

    k = ov208_func_021BC3A4(key);
    for (i = 0; i < 0x3d; i++) {
        msg = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 0x10);
        if (msg != 0xffff) {
            if ((SYMBOL_MAP_CheckEventFlag(k, msg) == 0 ? 1 : 0)) {
                *(u32 *)(p + i * 8 + 0x1e0) = 1;
                *(u32 *)(p + i * 8 + 0x1e4) = 0;
            } else {
                kind = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 0xb);
                pos.x = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 2);
                pos.y = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), i, 3);
                pos.z = kind == 4 ? 0xe : 0x10;
                pos.pri = 5;
                pos.f7 = 2;
                *(u32 *)(p + i * 8 + 0x1e0) = 2;
                *(u32 *)(p + i * 8 + 0x1e4) = (u32)CLACT_CreateActor((u32)W(0x1d0), W(0x98), W(0x9c), W(0xa0), &pos, 0, *heap);
                CLACT_SetActorAutoAnim((struct Obj *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
                CLACT_SetActorDrawEnable((struct Obj *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
                CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
            }
        } else {
            *(u32 *)(p + i * 8 + 0x1e0) = 0;
            *(u32 *)(p + i * 8 + 0x1e4) = 0;
        }
    }
}

/*
 * Frees the second word of every entry whose first word is 2.
 */
void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(void *a0, char *p, void *a2)
{
    Ov208MarkerTable *s = (Ov208MarkerTable *)p;
    unsigned char i;

    for (i = 0; i < 0x3d; i++) {
        if (s->markers[i].state == 2)
            CLACT_DeleteActor((struct Obj *)s->markers[i].obj);
    }
}

void ZUKAN_DETAIL_AREA_CreatePrintQueues(unsigned short *a, char *b, int a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = b + i * 4;
        ((struct Ov208AreaWork *)e)->f34 = PRINTSYS_QUE_Create((void *)(*a));
        ((struct Ov208AreaWork *)e)->f24 = 0;
    }
}

/*
 * Clears a word and releases two handles of each of four entries.
 */
void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *unused, char *p, void *a2)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        char *e = p + i * 4;
        ((struct Ov208AreaWork *)e)->f24 = 0;
        PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Ov208AreaWork *)e)->f34));
        PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Ov208AreaWork *)e)->f34));
    }
}

#undef OBJ

#undef OBJ

#undef OBJ

#undef OBJ

#undef OBJ

#define OBJ(i) (((u32 *)(p + 0xbc))[i])

void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        PRINTSYS_QUE_Main((struct PrintSys *)(((u32 *)(p + 0x34))[i]));
        ZUKAN_DETAIL_AREA_FlushPrintWindow(heap, p, key, i);
    }
}

void ZUKAN_DETAIL_AREA_FlushPrintWindow(u16 *heap, u8 *p, int key, u8 i)
{
    u32 w;

    if (((u32 *)(p + 0x24))[i] != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((u32 *)(p + 0x34))[i]), (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((u32 *)(p + 0x14))[i]))) == 0) {
            w = ((u32 *)(p + 0x14))[i];
            BMP_WIN_TransferChars((struct Descriptor *)w);
            BMP_WIN_MakeScreen((struct Cfg *)w);
            BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer((struct Descriptor *)w));
            ((u32 *)(p + 0x24))[i] = 0;
        }
    }
}

void ZUKAN_DETAIL_AREA_CreateTextWindows(u16 *heap, u8 *p, int key)
{
    struct WinCfg2 a;
    struct WinCfg4 b;
    u8 i;

    a = data_021C8570;
    b = data_021C85A4;
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 4, 0, 0x100, 0x20, *heap);
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x44) = BMP_WIN_Create(a.e[i].bg, a.e[i].x, a.e[i].y, a.e[i].w, a.e[i].h, a.e[i].pal, a.e[i].base);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44))), 0);
        BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)(p + i * 4 + 0x44));
    }
    for (i = 0; i < 4; i++) {
        *(u32 *)(p + i * 4 + 0x14) = BMP_WIN_Create(b.e[i].bg, b.e[i].x, b.e[i].y, b.e[i].w, b.e[i].h, b.e[i].pal, b.e[i].base);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14))), 0);
        BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)(p + i * 4 + 0x14));
    }
    W(0xc) = (u32)MSGDATA_CreateFromArchive(0, 2, 0xea, *heap);
    W(0x10) = (u32)MSGDATA_CreateFromArchive(0, 2, 0x59, *heap);
}

void ZUKAN_DETAIL_AREA_DeleteTextWindows(void *unused, char *p, void *a2)
{
    u8 i;
    for (i = 0; i < 2; i++) MSGDATA_Delete(*(struct Rec **)(p + i * 4 + 0xc));
    for (i = 0; i < 4; i++) {
        *(unsigned *)(p + i * 4 + 0x24) = 0;
        PRINTSYS_QUE_Clear(*(struct PrintSys **)(p + i * 4 + 0x34));
        BMP_WIN_Delete(*(struct Descriptor **)(p + i * 4 + 0x14));
    }
    for (i = 0; i < 2; i++) BMP_WIN_Delete(*(struct Descriptor **)(p + i * 4 + 0x44));
}

void ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(u16 *heap, u8 *p, int key)
{
    void *h;

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 4, 0, 0, 0x100, *heap);
    ((struct Ov208AreaWork *)p)->f68 = ARC_UTIL_RegisterObjCharFromHandle(h, 12, 7, 0, 0, *heap);
    func_02049990(h, 0x26, 7, 0, (u16)((struct Ov208AreaWork *)p)->f68, 0, 0, *heap);
    ARC_TOOL_DeleteHandle(h);
}

void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, u8 *p, void *a2)
{
    u32 v = ((struct Ov208AreaWork *)p)->f68;
    BG_SYS_DeleteHalf(7, (u16)v, (u16)(v >> 16));
}

void ZUKAN_DETAIL_AREA_UpdateScroll(int a, int b, int c)
{
    ZUKAN_DETAIL_AREA_UpdateScrollFade(a, (unsigned char *)b, c);
    ZUKAN_DETAIL_AREA_NoOpUpdate(a, b, c);
}

void ZUKAN_DETAIL_AREA_UpdateScrollFade(int a, unsigned char *p, int a2)
{
    switch (*(unsigned int *)&((struct Ov208AreaWork *)p)->f70) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if ((int)func_02040804((int)7) >= 0x40) {
            BG_SYS_ResetSlot(7, 3, 0x40);
            ((struct Ov208AreaWork *)p)->f70 = 2;
        } else {
            BG_SYS_ResetSlot(7, 4, 8);
            BG_SYS_ResetSlot(6, 4, 8);
        }
        break;
    case 3:
        if ((int)func_02040804((int)7) <= 0) {
            BG_SYS_ResetSlot(7, 3, 0);
            ((struct Ov208AreaWork *)p)->f70 = 0;
        } else {
            BG_SYS_ResetSlot(7, 5, 8);
            BG_SYS_ResetSlot(6, 5, 8);
        }
        break;
    }
    if (*(int *)(p + 0x5c + 4 * ((struct Ov208AreaWork *)p)->f64) == 0)
        return;
    {
        short v[2];

        switch (*(unsigned int *)&((struct Ov208AreaWork *)p)->f74) {
        case 0:
            break;
        case 2:
            break;
        case 1:
            CLACT_GetActorSurfacePos((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Ov208AreaWork *)p)->f64), (struct PtS *)v, 1);
            if (v[1] <= 0x70) {
                v[1] = 0x70;
                ((struct Ov208AreaWork *)p)->f74 = 2;
            } else {
                v[1] -= 8;
            }
            CLACT_AddActorSurfacePos((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Ov208AreaWork *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        case 3:
            CLACT_GetActorSurfacePos((struct Actor *)*(int *)(p + 0x5c + 4 * ((struct Ov208AreaWork *)p)->f64), (struct PtS *)v, 1);
            if (v[1] >= 0xb0) {
                v[1] = 0xb0;
                ((struct Ov208AreaWork *)p)->f74 = 0;
            } else {
                v[1] += 8;
            }
            CLACT_AddActorSurfacePos((struct Obj *)(*(int *)(p + 0x5c + 4 * ((struct Ov208AreaWork *)p)->f64)), (const struct Vec2 *)v, 1);
            break;
        }
    }
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void ZUKAN_DETAIL_AREA_NoOpUpdate(int a0, int a1, int a2)
{
}

void ZUKAN_DETAIL_AREA_UpdateSelectorAnim(u16 *heap, u8 *p, int key)
{
    void *scene;
    u8 sel;
    u16 anim;
    u32 next;
    u16 nextAnim;

    scene = ov208_func_021BC3B4(key);
    sel = p[0xd8];
    if (sel == 2) {
        anim = 2;
        next = 1;
        nextAnim = 4;
    } else if (sel == 1) {
        anim = 4;
        next = 2;
        nextAnim = 2;
    }
    if (sel != 7 && CLACT_IsActorAnimActive((struct Actor *)OBJ(sel)) == 0) {
        CLACT_SetActorAnimSeq((struct Obj *)OBJ(p[0xd8]), anim);
        CLACT_SetActorAutoAnim((struct Obj *)OBJ(next), 1);
        CLACT_SetActorAnimSeq((struct Obj *)OBJ(next), nextAnim);
        p[0xd8] = 7;
        if (((struct Ov208AreaWork *)p)->f6C == 0 || ((struct Ov208AreaWork *)p)->f6C == 5)
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)scene, 1);
    }
}

void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, u8 *p, int key)
{
    void *h;

    h = ARC_TOOL_CreateHandle(7, *heap);
    ((struct Ov208AreaWork *)p)->f54 = CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), 1, 0, *heap);
    ((struct Ov208AreaWork *)p)->f58 = CLACT_RegisterCellAnim(h, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), *heap);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Calls 0x0204AFD8 on +0x58 and 0x0204ADA4 on +0x54 of the second argument.
 */
void ZUKAN_DETAIL_AREA_ReleaseMarkerResources(void *a, char *q, void *a2)
{
    CLACT_ReleaseCellAnim(((struct Ov208AreaWork *)q)->f58);
    CLACT_ReleasePalette(((struct Ov208AreaWork *)q)->f54);
}

u32 ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 a, u32 b, u32 res, u16 heap, u32 species, u32 form,
                  u32 gender, u32 isEgg, u8 x, u8 y)
{
    ObjPos pos;
    void *h;
    u32 obj;

    h = ARC_TOOL_CreateHandle(7, heap);
    pos.x = x;
    pos.y = y;
    pos.z = 1;
    pos.pri = 1;
    pos.f7 = 0;
    *slot = CLACT_RegisterCharacter(h, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)CLACT_CreateActor((u32)res, *slot, a, b, &pos, 1, heap);
    CLACT_SetActorAutoAnim((struct Obj *)obj, 0);
    CLACT_SetActorPaletteOffset((struct Obj *)obj, POKE_TOOL_CalcIconPalette(species, form, gender, isEgg), 0);
    CLACT_SetActorObjMode((struct Actor *)obj, 0);
    ARC_TOOL_DeleteHandle(h);
    return obj;
}

/*
 * Calls 0x0204B3B4 on the second argument, then 0x0204A8D4 on the first.
 */
void ZUKAN_DETAIL_AREA_DeletePokemonIcon(void *a, void *b)
{
    CLACT_DeleteActor(b);
    CLACT_ReleaseCharacter((u32)a);
}

u8 ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, u8 *p, int key)
{
    int a;
    u32 m;
    int v;
    u8 r;

    a = ov208_func_021BC3A4(key);
    m = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAME_DATA_GetField114((struct SaveBlock *)a));
    r = 0xff;
    v = TOWNMAP_GRH_FindRecordIndex(((struct Ov208AreaWork *)p)->f3C8, SYMBOL_MAP_ResolveZoneId(a, m));
    if (v != 0xffff)
        r = v;
    return r;
}

void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, u8 *p, int key)
{
    u8 idx;
    u16 pos[2];

    idx = ZUKAN_DETAIL_AREA_FindPlayerTownIndex(heap, p, key);
    if (idx != 0xff) {
        pos[0] = TOWNMAP_GRH_GetTownInfoValue((char *)(((struct Ov208AreaWork *)p)->f3C8), idx, 2);
        pos[1] = TOWNMAP_GRH_GetTownInfoValue((char *)(((struct Ov208AreaWork *)p)->f3C8), idx, 3);
        CLACT_AddActorSurfacePos((struct Obj *)(((struct Ov208AreaWork *)p)->fD4), (const struct Vec2 *)pos, 0);
    }
}

void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *heap, u8 *p, int key, int on)
{
    if (on) {
        if (ZUKAN_DETAIL_AREA_FindPlayerTownIndex(heap, p, key) != 0xff) {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Ov208AreaWork *)p)->fD4), 6);
            CLACT_SetActorDrawEnable((struct Obj *)((struct Ov208AreaWork *)p)->fD4, 1);
        }
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Ov208AreaWork *)p)->fD4, 0);
    }
}

/*
 * Loads the word at +0xD4 of the second argument and tail-calls the function at 0x0204B3F4 with it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */
u32 ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(void *a0, u8 *p, void *a2)
{
    return CLACT_GetActorDrawEnable((struct Obj *)(((struct Ov208AreaWork *)p)->fD4));
}

void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, u8 *p, int key)
{
    struct Pt pt = data_021C8554;

    if (p[0x79] == 0xff)
        p[0x79] = func_021C0C14(heap, p, key);
    if (p[0x79] != 0xff) {
        pt.x = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 2);
        pt.y = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 3);
    }
    CLACT_AddActorSurfacePos((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt), 0);
    CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 1);
}

/*
 * Stores the byte result of func_021C0C14 at +0x79 of the second argument then calls ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown.
 */
void ZUKAN_DETAIL_AREA_SelectPlayerTown(int a, char *b, int c)
{
    b[0x79] = func_021C0C14((u16 *)a, (u8 *)b, c);
    ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown((u16 *)a, (u8 *)b, c);
}

u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused,char *p,int unused2,u8 x,u8 y)
{
    struct Ball ball;
    struct Vec3 point;
    struct Seg seg;
    struct Vec3 a,b;
    struct Out out;
    int best;
    u8 i;
    u8 result=255;
    point.x=FX(x);
    point.y=FX(y);
    point.z=0;
    BUTTON_MAN_InitSphere(&ball,&point,0);
    for(i=0;i<61;i++) {
        if (*(u32 *)(p+i*8+0x1e0)==1) continue;
        a.x=FX(FIELD(6));
        a.y=FX(FIELD(7));
        a.z=0;
        b.x=FX(FIELD(8));
        b.y=FX(FIELD(9));
        b.z=0;
        BUTTON_MAN_InitSegment((char *)(&seg),(struct Vec3 *)(&a),(struct Vec3 *)(&b),FX(FIELD(10)));
        if (BUTTON_MAN_SegmentSphereTest(&seg,&ball,&out)) {
            if(result==255) { best=out.distance; result=i; }
            else if(best>out.distance) { best=out.distance; result=i; }
        }
    }
    return result;
}

/*
 * Tail: 021C1066..021C1068 is two zero alignment bytes, not a follower.
 */
int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *unused, char *p, int key, u8 index, u8 x, u8 y, unsigned *out)
{
    unsigned dx, dy, distance;
    if (*(unsigned *)(p + index * 8 + 0x1e0) == 1) return 0;
    dx = TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Ov208AreaWork *)p)->f3C8, index, 4);
    dy = TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct Ov208AreaWork *)p)->f3C8, index, 5);
    dy -= y;
    dx -= x;
    distance = dx * dx + dy * dy;
    if (distance < 144) {
        if (out) *out = distance;
        return 1;
    }
    return 0;
}

u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, char *p, int key, u8 x, u8 y)
{
    unsigned distance, bestDistance;
    u8 best = 255, i;
    for (i = 0; i < 61; i++) {
        if (ZUKAN_DETAIL_AREA_GetTownPointDistance(heap, p, key, i, x, y, &distance)) {
            if (best == 255) {
                best = i;
                bestDistance = distance;
            } else if (bestDistance > distance) {
                best = i;
                bestDistance = distance;
            }
        }
    }
    return best;
}

void ZUKAN_DETAIL_AREA_HandleCursorInput(u16 *heap, u8 *p, int key)
{
    void *s;
    int hit, touch;
    int moved, done;
    u32 x, y, tx, ty;

    s = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    if (W(0x428) == 0 || p[0xd8] != 7)
        return;

    switch (W(0x6c)) {
    case 0:
        hit = 0;
        touch = 0;
        if (KEY_GetTrg() & 1) {
            touch = 1;
            hit = 1;
        } else if (W(0x8c) != 0) {
            if (KEY_GetRepeat() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                hit = 1;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
            } else if (KEY_GetRepeat() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
                hit = 1;
            }
        }
        if (hit) {
            func_020355D8(0);
            if (touch)
                W(0x7c) = 0;
        }
        if (hit == 0) {
            if (TOUCHPANEL_GetPointTrg(&x, &y)) {
                if (W(0x8c) == 0) {
                    if (y < 0xa8) {
                        touch = 1;
                        hit = 1;
                    }
                } else if (x >= 0x88 && x < 0xa0 && y < 0x10) {
                    p[0x78]++;
                    if (p[0x78] >= 4)
                        p[0x78] = 0;
                    hit = 1;
                    ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, hit);
                    GFL_USE_PlaySeDefaultVolume(0x54a);
                } else if (x < 0x18 && y < 0x10) {
                    if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                    hit = 1;
                    ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, hit);
                    GFL_USE_PlaySeDefaultVolume(0x54a);
                } else if ((x >= 0xa0 || y >= 0x18) && y < 0xa8) {
                    touch = 1;
                    hit = 1;
                }
            }
            if (hit) {
                hit = 1;
                func_020355D8(1);
                if (touch) {
                    W(0x7c) = hit;
                    p[0x80] = x;
                    p[0x81] = y;
                }
            }
        }
        if (touch && (W(0x8c) != 0 || W(0x90) != 0)) {
            ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 0);
        }
        break;
    case 5:
        moved = 0;
        done = 1;
        if (KEY_GetTrg() & 2) {
            W(0x428) = 0;
            moved = 1;
            done = 0;
        } else if (W(0x8c) != 0) {
            if (KEY_GetRepeat() & 0x100) {
                p[0x78]++;
                if (p[0x78] >= 4)
                    p[0x78] = 0;
                done = 0;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, done);
                moved = 1;
                GFL_USE_PlaySeDefaultVolume(0x54a);
            } else if (KEY_GetRepeat() & 0x200) {
                if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                done = 0;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
                moved = 1;
            }
        }
        if (moved)
            func_020355D8(0);
        if (moved == 0) {
            if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
                if (W(0x8c) == 0) {
                    if (ty >= 0xa8)
                        done = 0;
                } else if (W(0x8c) == 1) {
                    if (tx >= 0x88 && tx < 0xa0 && ty < 0x10) {
                        p[0x78]++;
                        if (p[0x78] >= 4)
                            p[0x78] = 0;
                        moved = 1;
                        ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, moved);
                        GFL_USE_PlaySeDefaultVolume(0x54a);
                        done = 0;
                    } else if (tx < 0x18 && ty < 0x10) {
                        if (p[0x78] == 0) p[0x78] = 3; else p[0x78]--;
                        moved = 1;
                        ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, moved);
                        done = 0;
                        GFL_USE_PlaySeDefaultVolume(0x54a);
                    } else if (tx < 0xa0 && ty < 0x18) {
                        done = 0;
                    } else if (ty >= 0xa8) {
                        done = 0;
                    }
                }
            }
            if (moved)
                func_020355D8(1);
        }
        if (done)
            ZUKAN_DETAIL_AREA_HandleTownTouchInput(heap, p, key);
        break;
    }
}

static inline void set3(struct Vec3 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, u8 *p, int key)
{
    u32 tx, ty;
    struct { struct PtS t, c; } pt;
    u8 idx;
    u8 old;
    int found, near;
    int moved;
    unsigned int keys;
    int dx, dy;

    if (W(0x90) == 0)
        return;
    if (UI_GetInputMode() == 0) {
        if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
            func_020355D8(1);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 0);
        }
    } else if (KEY_GetTrg()) {
        func_020355D8(0);
        ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(heap, p, key);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        return;
    }
    if (UI_GetInputMode() == 0) {
        old = p[0x79];
        moved = 0;
        found = 0;
        near = 0;
        {
        struct Vec3 v = {0, 0, 0};
        struct Vec3 d = {0, 0, 0};
        struct Vec3 a;
        struct Vec3 b;
        CLACT_GetActorSurfacePos((struct Actor *)W(0xcc), &pt.c, 0);
        keys = KEY_GetCont();
        if ((keys & 0x10) || (keys & 0x20) || (keys & 0x40) || (keys & 0x80)) {
            moved = 1;
            if (keys & 0x10)
                v.x += 0x1000;
            if (keys & 0x20)
                v.x -= 0x1000;
            if (keys & 0x40)
                v.y -= 0x1000;
            if (keys & 0x80)
                v.y += 0x1000;
        }
        idx = ZUKAN_DETAIL_AREA_FindNearestTown(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (idx != 0xff) {
            found = 1;
            pt.t.x = TOWNMAP_GRH_GetTownInfoValue(*(char **)(p + 0x3c8), idx, 4);
            pt.t.y = TOWNMAP_GRH_GetTownInfoValue(*(char **)(p + 0x3c8), idx, 5);
            a.x = FX(pt.t.x);
            a.y = FX(pt.t.y);
            a.z = 0;
            b.x = FX(pt.c.x);
            b.y = FX(pt.c.y);
            b.z = 0;
            VEC_Subtract(&a, &b, &d);
            if (VEC_Mag(&d) < 0x1BB6)
                near = 1;
            if (VEC_Mag(&d) > 0x1000) {
                VEC_Normalize(&d, &d);
                BUTTON_MAN_ScaleVec((const struct Vec3 *)(&d), 0x1000, (struct Vec3 *)(&d));
            }
        }
        if (moved == 0 && found == 0)
            return;
        if (moved == 0 && found != 0 && near != 0) {
            pt.c = pt.t;
        } else {
            VEC_Normalize(&v, &v);
            dx = d.x + v.x * 3;
            dy = d.y + v.y * 3;
            if (dx > 0 && dx < 0x1000)
                dx = 0x1000;
            else if (dx > -0x1000 && dx < 0)
                dx = -0x1000;
            if (dy > 0 && dy < 0x1000)
                dy = 0x1000;
            else if (dy > -0x1000 && dy < 0)
                dy = -0x1000;
            pt.c.x = pt.c.x + (s16)(dx >> 12);
            pt.c.y = pt.c.y + (s16)(dy >> 12);
        }
        pt.c.x = pt.c.x > 0xf8 ? 0xf8 : (pt.c.x < 0 ? 0 : pt.c.x);
        pt.c.y = pt.c.y > 0xa8 ? 0xa8 : (pt.c.y < 8 ? 8 : pt.c.y);
        CLACT_AddActorSurfacePos((struct Obj *)W(0xcc), (const struct Vec2 *)(&pt.c), 0);
        p[0x79] = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, (char *)p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (p[0x79] != old) {
            ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
            if (p[0x79] != 0xff)
                GFL_USE_PlaySeDefaultVolume(0x548);
        }
        }
    } else if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
        p[0x79] = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, (char *)p, key, (u8)tx, (u8)ty);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        if (p[0x79] != 0xff)
            GFL_USE_PlaySeDefaultVolume(0x54C);
    }
}

void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, u8 *p, int key)
{
    switch (W(0x6c)) {
    case 1:
        ov208_func_021C1920(heap, p, key, 2);
        break;
    case 2:
        ov208_func_021C1920(heap, p, key, 5);
        break;
    case 3:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2090(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 0);
            break;
        }
        break;
    case 4:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C21D0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_RequestBlendRestore(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ZUKAN_DETAIL_AREA_NoOpOverlay(heap, p, key);
            W(0x84) = 0;
            break;
        }
        break;
    case 6:
        ov208_func_021C1920(heap, p, key, 7);
        break;
    case 7:
        ov208_func_021C1920(heap, p, key, 0);
        break;
    case 8:
        switch (W(0x84)) {
        case 1:
            ov208_func_021C1FE0(heap, p, key);
            W(0x84) = 2;
            break;
        case 2:
            ov208_func_021C2090(heap, p, key);
            W(0x84) = 3;
            break;
        case 3:
            ov208_func_021C20C0(heap, p, key);
            W(0x84) = 0;
            ov208_func_021C1920(heap, p, key, 5);
            break;
        }
        break;
    }
}

void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, int key, int mode)
{
    void *s;
    u32 wide;

    s = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    switch (W(0x6c)) {
    case 0:
        if (mode == 1) {
        } else if (mode == 3) {
            W(0x84) = 1;
        } else if (mode == 4) {
            W(0x84) = 1;
        }
        break;
    case 1:
        if (mode == 2)
            func_021BDBAC(s, 0);
        break;
    case 2:
        if (mode == 5) {
            W(0x70) = 1;
            W(0x74) = 1;
            if (W(0x90) == 1) {
                if (W(0x7c) == 0) {
                    ZUKAN_DETAIL_AREA_SelectPlayerTown((int)heap, (char *)p, key);
                } else {
                    p[0x79] = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, (char *)p, key, p[0x80], p[0x81]);
                    if (p[0x79] != 0xff)
                        CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 1);
                }
                ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
                ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
            }
            func_021BDAAC(s, 1, 1, func_021BC3BC((int *)((char *)key)) > 1);
        }
        break;
    case 3:
        if (mode == 0) {
            if (W(0x42c) != 0) {
                W(0x430) = 1;
                if (W(0x434) != 0) {
                    W(0x42c) = 0;
                    func_021BDBA0((void *)((int)s));
                }
            }
            if (p[0xd8] == 7 && W(0x88) != 0)
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 1);
        }
        break;
    case 4:
        break;
    case 5:
        if (mode == 6) {
        } else if (mode == 8) {
            W(0x84) = 1;
        }
        break;
    case 6:
        if (mode == 7)
            func_021BDBAC(s, 0);
        break;
    case 7:
        if (mode == 0) {
            W(0x70) = 3;
            W(0x74) = 3;
            CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 0);
            wide = func_021BC3BC((int *)((char *)key)) > 1 ? 1 : 0;
            func_021BDAAC(s, 0, 1, wide);
            ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq((struct Ov208Scene *)s, GAME_DATA_CheckSaveFlag(ZUKAN_DETAIL_COMMON_GetSource((int *)key), 0x12));
        }
        break;
    case 8:
        if (mode == 5) {
            func_021BDBA0((void *)((int)s));
            if (p[0xd8] == 7 && W(0x88) != 0)
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 1);
        }
        break;
    }
    W(0x6c) = mode;
}

void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, u8 *p, int key)
{
    u32 prev;
    u16 id;
    void *win;
    void *str;
    void *buf;
    u32 out1, out2, form;

    prev = W(0x8c);
    id = ZUKAN_DETAIL_COMMON_GetCurrentEntry((void *)key);
    ZUKAN_DETAIL_AREA_FreeAreaEntryData(W(0x94));
    W(0x94) = (u32)ZUKAN_DETAIL_AREA_LoadAreaEntryData(id, *heap, W(0x40c));
    W(0x8c) = ((Entry *)W(0x94))->f0 == 0;
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;

    if (SLOT5C(((struct Ov208AreaWork *)p)->f64) != 0)
        CLACT_SetActorDrawEnable((struct Obj *)SLOT5C(((struct Ov208AreaWork *)p)->f64), 0);
    ((struct Ov208AreaWork *)p)->f64 = (((struct Ov208AreaWork *)p)->f64 + 1) % 2;
    if (SLOT5C(((struct Ov208AreaWork *)p)->f64) != 0) {
        if (SLOT5C(((struct Ov208AreaWork *)p)->f64) != 0)
            ZUKAN_DETAIL_AREA_DeletePokemonIcon((void *)SLOT4C(((struct Ov208AreaWork *)p)->f64), (void *)SLOT5C(((struct Ov208AreaWork *)p)->f64));
        SLOT5C(*(int *)(p + 0x64)) = 0;
    }

    ZUKAN_SAVE_GetViewGenderAndForm(ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource((int *)key)), id, &out1, &out2, &form, *heap);
    SLOT5C(*(int *)(p + 0x64)) = ZUKAN_DETAIL_AREA_CreatePokemonIcon(&SLOT4C(((struct Ov208AreaWork *)p)->f64), W(0x54), W(0x58), W(0),
                                               *heap, id, form, out1, 0, 0x38, 0xb0);
    W(0x24) = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)W(0x34));
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x14)), 0);
    win = WORDSET_CreateDefault(*heap);
    str = MSGDATA_AllocString((struct MsgBank *)W(0xc), 0xbd);
    buf = STRBUF_Create(0x40, *heap);
    WORDSET_Callback(win, 0, id);
    WORDSET_CopyTaggedText(win, buf, str);
    STRBUF_Delete(str);
    WORDSET_DeleteStrbufED04(win);
    PRINTSYS_PrintQueColor((void *)W(0x34), (u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x14)), 0, 5, (u32)buf, W(4), 0x3c40);
    STRBUF_Delete(buf);
    W(0x24) = 1;
    func_021C0740(heap, p, key, 0);

    if (W(0x8c) == 0) {
        if (prev == 1) {
            W(0x2c) = 0;
            PRINTSYS_QUE_Clear((struct PrintSys *)W(0x3c));
            BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)), 0);
            BMP_WIN_TransferChars((struct Descriptor *)W(0x1c));
            CLACT_SetActorDrawEnable((struct Obj *)W(0xbc), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xc4), 0);
            CLACT_SetActorDrawEnable((struct Obj *)W(0xc0), 0);
        }
    } else if (prev == 0) {
        ZUKAN_DETAIL_AREA_DrawAreaSetTitle(heap, p, key);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xbc), 1);
        CLACT_SetActorAnimSeq((struct Obj *)W(0xc4), 2);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xc4), 1);
        CLACT_SetActorAnimSeq((struct Obj *)W(0xc0), 4);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xc0), 1);
    }
}

/*
 * Calls ZUKAN_DETAIL_AREA_BeginModeTransition then ZUKAN_DETAIL_AREA_UpdateTerrainIcons on the same three arguments.
 */
void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(int a, int b, int c)
{
    ZUKAN_DETAIL_AREA_BeginModeTransition((void *)a, (char *)b, c);
    ZUKAN_DETAIL_AREA_UpdateTerrainIcons((u16 *)a, (u8 *)b, c);
}

void ZUKAN_DETAIL_AREA_RequestModeEvent4(void *a, int b, int c)
{
    ZUKAN_DETAIL_AREA_HandleModeEvent(a, (u8 *)b, c, 4);
}

void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, int key)
{
    void *str;
    struct Pt pt;

    W(0x28) = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)W(0x38));
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x18)), 0);
    if (p[0x79] != 0xff) {
        str = MSGDATA_AllocString((struct MsgBank *)W(0x10), ZONEDATA_GetPlaceNameId(TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 0)));
        PRINTSYS_PrintQueColor((void *)W(0x38), (u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x18)), 0, 1, (u32)str, W(4), 0x3c40);
        STRBUF_Delete(str);
        W(0x28) = 1;
        func_021C0740(heap, p, key, 1);
        pt.x = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 2);
        pt.y = TOWNMAP_GRH_GetTownInfoValue((char *)W(0x3c8), p[0x79], 3);
        CLACT_SetActorAnimSeq((struct Obj *)W(0xd0), 5);
        CLACT_AddActorSurfacePos((struct Obj *)W(0xd0), (const struct Vec2 *)(&pt), 0);
        CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 1);
    } else {
        BMP_WIN_TransferChars((struct Descriptor *)W(0x18));
        CLACT_SetActorDrawEnable((struct Obj *)W(0xd0), 0);
    }
}

#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))

#undef OBJ

#undef OBJ

#define OBJ(i) (((u32 *)(p + 0xbc))[i])

void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, u8 *p, int key, int dir, int touch)
{
    void *s;
    int other;
    u16 anim;

    s = (void *)ZUKAN_DETAIL_COMMON_GetWorkPtr((int *)key);
    if (W(0x8c) == 0)
        W(0x90) = ((Entry *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry *)W(0x94))[p[0x78]].f1 == 0;
    W(0x2c) = 0;
    PRINTSYS_QUE_Clear((struct PrintSys *)W(0x3c));
    BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)), 0);
    ZUKAN_DETAIL_AREA_DrawAreaSetTitle(heap, p, key);
    if (dir) {
        p[0xd8] = 2;
        anim = 3;
        other = 1;
    } else {
        p[0xd8] = 1;
        anim = 5;
        other = 2;
    }
    CLACT_SetActorAnimSeq((struct Obj *)OBJ(p[0xd8]), anim);
    CLACT_SetActorAutoAnim((struct Obj *)OBJ(other), 0);
    CLACT_SetActorAnimFrame((struct Obj *)OBJ(other), 0);
    ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 0);
    if (touch == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)W(0xcc), 0);
    } else if (W(0x6c) == 5 && W(0x90) == 1) {
        ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(heap, p, key);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
    }
    ZUKAN_DETAIL_AREA_BeginModeTransition(heap, (char *)p, key);
    ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
}

/*
 * Forwards to ARC_UTIL_LoadHandleMemberWithSize with the first argument less one and an out slot.
 */
void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int a, int b, int c)
{
    int out;

    return ARC_UTIL_LoadHandleMemberWithSize((void *)c, a - 1, 0, b, (u32 *)(&out));
}

void ZUKAN_DETAIL_AREA_FreeAreaEntryData(int a)
{
    if (a != 0)
        GFL_HEAP_Free((void *)a);
}

void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = MSGDATA_AllocString((struct MsgBank *)W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = BMP_GetWidth(BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)));
    PRINTSYS_PrintQueColor((void *)W(0x3c), (u32)BMP_WIN_GetBmp((struct Descriptor *)W(0x1c)), (s16)((u16)((int)(w - tw) / 2)), (s16)1, (u32)str, W(4), 0x3c40);
    STRBUF_Delete(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}

/*
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to ZUKAN_DETAIL_AREA_HandleModeEvent.
 */
void ZUKAN_DETAIL_AREA_BeginModeTransition(void *a, char *b, int c)
{
    int s = ((struct Ov208AreaWork *)b)->f6C;

    if (s == 0) {
        ZUKAN_DETAIL_AREA_HandleModeEvent(a, (u8 *)b, c, 3);
        return;
    }
    if (s == 5) {
        ZUKAN_DETAIL_AREA_HandleModeEvent(a, (u8 *)b, c, 8);
    }
}

void ZUKAN_DETAIL_AREA_BeginHideOverlay(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (CLACT_GetActorDrawEnable(*(struct Obj * *)&((struct Ov208AreaWork *)p)->fC8)) {
        if (((struct Ov208AreaWork *)p)->f90 == 1) {
            ((struct Ov208AreaWork *)p)->f30 = 0;
            PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Ov208AreaWork *)p)->f40);
            BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Ov208AreaWork *)p)->f20), 0);
            BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Ov208AreaWork *)p)->f20);
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Ov208AreaWork *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) CLACT_SetActorDrawEnable(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Ov208AreaWork *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Ov208AreaWork *)p)->fCC, 0);
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Ov208AreaWork *)p)->fD0, 0);
            ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        }
    }
}

void ZUKAN_DETAIL_AREA_FinishHideOverlay(void *unused, u8 *p)
{
    if (CLACT_GetActorDrawEnable((struct Obj *)(*(int *)&((struct Ov208AreaWork *)p)->fC8)) == 0) {
        if (*(int *)&((struct Ov208AreaWork *)p)->f90 == 0) {
            p[0x414] = 1;
        } else {
            p[0x414] = 2;
        }
    }
}

void ZUKAN_DETAIL_AREA_DrawNoDataMessage(void *a0, u8 *st, void *a2)
{
    int res = CLACT_GetActorDrawEnable((struct Obj *)(*(int *)&((struct Ov208AreaWork *)st)->fC8));

    if (((struct Ov208AreaWork *)st)->f90 == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            u32 t;

            msg = MSGDATA_AllocString(((struct Ov208AreaWork *)st)->fC, 0x80);
            w = (u16)GF_FONT_MeasureWidestLine(msg, ((struct Ov208AreaWork *)st)->f4, 0);
            h = BMP_GetWidth((const struct Bmp *)((u32)BMP_WIN_GetBmp(((struct Ov208AreaWork *)st)->f20)));
            t = (u32)BMP_WIN_GetBmp(((struct Ov208AreaWork *)st)->f20);
            d = h - w;
            PRINTSYS_PrintQueColor(((struct Ov208AreaWork *)st)->f40, t, (s16)(u16)(d / 2), 1, (u32)msg, ((struct Ov208AreaWork *)st)->f4, 0x3c40);
            STRBUF_Delete(msg);
            ((struct Ov208AreaWork *)st)->f30 = 1;
            func_021C0740((u16 *)a0, st, (int)a2, 3);
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Ov208AreaWork *)st)->fC8, 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = ((struct Ov208AreaWork *)st)->f8C == 0 ? 0 : st[0x78];
        for (i = 0; i < 0x3d; i++) {
            tbl = *(u8 * *)&((struct Ov208AreaWork *)st)->f94;
            if (tbl[v * 0x3e + st[0x3cc + i] + 2] != 0 && *(u32 *)(st + 0x1e0 + i * 8) != 1) {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(st + 0xdc + i * 4), 1);
            }
        }
        if (ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(a0, st, a2) == 0) {
            func_021C0C8C((u16 *)a0, st, (int)a2, 1);
        }
    }
}

void ZUKAN_DETAIL_AREA_ClearOverlayWindow(void *unused, char *p, int key)
{
    u8 i;
    if (CLACT_GetActorDrawEnable(*(struct Obj * *)&((struct Ov208AreaWork *)p)->fC8)) {
        ((struct Ov208AreaWork *)p)->f30 = 0;
        PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Ov208AreaWork *)p)->f40);
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Ov208AreaWork *)p)->f20), 0);
        BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Ov208AreaWork *)p)->f20);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Ov208AreaWork *)p)->fC8, 0);
    } else {
        for (i = 0; i < 61; i++) CLACT_SetActorDrawEnable(*(struct Obj **)(p + i * 4 + 0xdc), 0);
    }
}

void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, u8 *p, int key)
{
    p[0x414] = 3;
}

void ZUKAN_DETAIL_AREA_NoOpOverlay(u16 *heap, u8 *p, int key)
{
}

/*
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 */
void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, int key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (W(0x90) == 1 && p[0x79] != 0xff) {
        idx = W(0x8c) != 0 ? p[0x78] : 0;
        k = (p + p[0x79])[0x3cc];
        if ((*(Entry **)(p + 0x94))[idx].rest[k] & 7)
            on[0] = 1;
        if ((*(Entry **)(p + 0x94))[idx].rest[k] & 0x18)
            on[1] = 1;
        if ((*(Entry **)(p + 0x94))[idx].rest[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        BG_SYS_FillTileMap(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    BG_SYS_SetFlagField06(7);
}

/*
 * Writes 4 on the stack and calls the SDK function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_, and the `sdk` class attests the call once
 * the symbols block declares `arm`.  The old `thumb` declaration fought the
 * image's ISA and suppressed the witness.  Verified EXACT, 24 bytes.
 */
void ZUKAN_DETAIL_AREA_ResetBlendAlpha(char *a0)
{
    G2x_SetBlendAlpha_((volatile void *)0x04000050, 0, 0x3f, 0xc, 4);
}

/*
 * Loads the word at +0x418 and tail-calls ZUKAN_DETAIL_COMMON_InitBrightnessTarget with it.
 */
void ZUKAN_DETAIL_AREA_ApplyBrightness(char *p)
{
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)(((struct Ov208AreaWork *)p)->f418));
}

static inline void GX_SetVisibleWnd(int window)
{
    REG32(0x04000000) = (u32)((REG32(0x04000000) & ~0xe000) | (window << 13));
}

static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void G2_SetWnd1Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x04000048) = (u16)tmp;
}

static inline void G2_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    REG16(0x04000048) = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x0400004a) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x0400004a) = (u16)tmp;
}

void ZUKAN_DETAIL_AREA_SetupSplitWindows(char *p)
{
    GX_SetVisibleWnd(3);
    G2_SetWnd0Position(0, 0, 160, 168);
    G2_SetWnd1Position(160, 0, 0, 168);
    G2_SetWnd0InsidePlane(31, 1);
    G2_SetWnd1InsidePlane(31, 1);
    G2_SetWndOutsidePlane(31, 0);
    ZUKAN_DETAIL_AREA_InitBlendPulse((u8 *)p);
}

/*
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls ZUKAN_DETAIL_COMMON_InitBrightnessTarget on the word at +0x418.
 */
void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget((int *)(((struct Ov208AreaWork *)p)->f418));
}

#undef W

#undef W

#undef W

#define W(o) (*(u32 *)(p + (o)))

void ZUKAN_DETAIL_AREA_UpdateBlendPulse(u8 *p)
{
    G2x_SetBlendAlpha_((volatile void *)0x04000050, 0, 0x3f, W(0x1d8), 16 - W(0x1d8));
    if (H(0x1dc) + 0x400u >= 0x10000)
        H(0x1dc) = H(0x1dc) - 0xfc00;
    else
        H(0x1dc) += 0x400;
    W(0x1d8) = ((s16)((FX_SinCosTable_[(H(0x1dc) >> 4) * 2 + 1] + 0x1000) / 2) * 14 >> 12) + 1;
}

void ZUKAN_DETAIL_AREA_InitBlendPulse(u8 *p)
{
    One one = ONE;
    ((struct Ov208AreaWork *)p)->f1D8 = one;
    ((struct Ov208AreaWork *)p)->f1DC = one << 15;
    G2x_SetBlendAlpha_((volatile void *)0x04000050, 0, 0x3f, one, 16 - one);
}

void ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 0);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 0);
    }
}

void ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 1);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            CLACT_SetActorObjMode((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
    }
}

void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            CLACT_SetActorObjMode((struct Actor *)(((u32 *)(p + 0x5c))[i]), 0);
    }
    G2x_SetBlendAlpha_((volatile void *)0x04001050, 8, 0x3f, 12, 4);
}

void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            CLACT_SetActorObjMode((struct Actor *)(((u32 *)(p + 0x5c))[i]), 1);
    }
    ov208_func_021BC518((u32)((struct Ov208AreaWork *)p)->f41C);
}
