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
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
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
 *   ARC_UTIL_UploadBgPaletteAddFromHandle  0x02049990  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ZUKAN_DETAIL_AREA_SetHeapId 0x021BF784 thumb ov208
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_AddActorSurfacePos        0x0204B404  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole        0x02049B68  arm
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
 *   ZUKAN_DETAIL_COMMON_GetEntryCount 0x021BC3BC thumb
 *   ZUKAN_DETAIL_TOUCHBAR_SetMode 0x021BDAAC thumb
 *   ZUKAN_DETAIL_COMMON_GetSource 0x021BC3A4 thumb
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   ZUKAN_DETAIL_COMMON_GetDisplay 0x021BC3A8 thumb
 *   ZUKAN_DETAIL_TOUCHBAR_ClearButtonState 0x021BDBA0 thumb
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies  0x021BC3CC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies  0x021BC40C  thumb  ov208
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
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
 *   ZUKAN_DETAIL_COMMON_GetWorkPtr  0x021BC3B4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetHeadbar  0x021BC3B8  thumb  ov208
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   data_021C85C0  0x021C85C0  data
 *   data_021C8618  0x021C8618  data
 *   ZUKAN_DETAIL_AREA_CreateMapActors  0x021C0134  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc  0x021BC844  thumb  ov208
 *   ZUKAN_DETAIL_AREA_LoadAreaEntries  0x021C1AD4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots  0x021BC758  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeIn  0x021BC718  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessFull  0x021BC4F4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendIn  0x021BC4D8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOut  0x021BC6D8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetEntryCount  0x021BC3BC  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq  0x021BDC14  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_IsBlendBusy  0x021BC4C8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_IsFadeBusy  0x021BC6C8  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay  0x021C1D0C  thumb  ov208
 *   ZUKAN_DETAIL_AREA_RequestModeEvent4  0x021C1D24  thumb  ov208
 *   ZUKAN_DETAIL_AREA_HandleCursorInput  0x021C10B8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartBlendOut  0x021BC4E4  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_StartFadeOutAlt  0x021BC6F8  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled  0x021BDAE8  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBrightnessNone  0x021BC508  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_TickFlashEffect  0x021BC99C  thumb  ov208
 *   ZUKAN_DETAIL_AREA_UpdateScroll  0x021C0968  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdateBlendFades  0x021BC46C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_UpdatePaletteAnim  0x021BC678  thumb  ov208
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
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   SYMBOL_MAP_ResolveZoneId  0x02166C7C  thumb
 *   TOWNMAP_GRH_FindRecordIndex  0x021BBB48  thumb  ov072
 *   ZUKAN_DETAIL_AREA_FindPlayerTownIndex  0x021C0C14  thumb  ov208
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
 *   ZUKAN_DETAIL_AREA_HandleModeEvent  0x021C1920  thumb  ov208
 *   ZUKAN_DETAIL_AREA_BeginHideOverlay  0x021C1FE0  thumb  ov208
 *   ZUKAN_DETAIL_AREA_FinishHideOverlay  0x021C2090  thumb  ov208
 *   ZUKAN_DETAIL_AREA_DrawNoDataMessage  0x021C20C0  thumb  ov208
 *   ZUKAN_DETAIL_AREA_ClearOverlayWindow  0x021C21D0  thumb  ov208
 *   ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable  0x021BDBAC  thumb  ov208
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   ZUKAN_DETAIL_AREA_FlushPrintWindow  0x021C0740  thumb  ov208
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   BMP_GetWidth  0x020437DC  arm
 *   ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible 0x021C0C8C thumb ov208
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 *   G2x_SetBlendAlpha_ 0x0207D63C  arm
 *   ZUKAN_DETAIL_COMMON_InitBrightnessTarget  0x021BC518  thumb  ov208
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
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "../arm9/arc_util.h"
#include "../sdk_ioreg.h"
#include "../arm9/bmp.h"
#include "../arm9/bmp_win.h"
#include "../arm9/button_man.h"
#include "../arm9/fx_vec.h"
#include "../arm9/g2.h"
#include "../arm9/game_data.h"
#include "../arm9/gf_font.h"
#include "../arm9/gfl_use.h"
#include "../arm9/msgdata.h"
#include "../arm9/printsys.h"
#include "../arm9/strbuf.h"
#include "../arm9/tcb_list.h"
#include "../arm9/ui.h"
#include "../arm9/wordset.h"
#include "../arm9/zukan_save.h"
#include "../ov072/townmap_grh.h"
#include "zukan_detail_common.h"
#include "zukan_detail_touchbar.h"
#include "zukan_detail_types.h"
#include "zukan_detail_shared_types.h"

/*
 * Work object of the Pokedex detail area screen, 0x438 bytes, allocated by
 * ZUKAN_DETAIL_AREA_Init. Every per-function view of the object is folded into
 * this one struct. The town marker table sits at 0x1E0 and the mode /
 * overlay tail at 0x424 (read by the info screen as well).
 */
typedef struct {
    u8 allSeasons;
    u8 noArea;
    u8 rest[0x3c];
} ZukanDetailAreaEntry;

struct Ov208AreaWork {
    struct Unit *actorUnit;            /* 0x00 */
    struct GfFont *font;           /* 0x04 */
    struct Ov208Win *bgPalette;                   /* 0x08 */
    struct MsgBank *msg[2];                   /* 0x0C: screen text, place names */
    struct BmpWin *win[4];                   /* 0x14: the fourth is the no-data window */
    unsigned int printPending[4];                    /* 0x24 */
    struct PrintQueue *printQue[4];                    /* 0x34 */
    struct BmpWin *subWin[2];                  /* 0x44 */
    unsigned int iconCharKey[2];           /* 0x4C */
    unsigned int iconPalette;           /* 0x54 */
    unsigned int iconCellAnim;           /* 0x58 */
    struct ClactActor *iconActor[2];           /* 0x5C */
    int iconSlot;                    /* 0x64 */
    unsigned int subScreenChar;           /* 0x68 */
    int uiMode;                    /* 0x6C */
    unsigned int scrollState;           /* 0x70 */
    unsigned int iconSlideState;           /* 0x74 */
    unsigned char season;          /* 0x78 */
    unsigned char selectedTown;          /* 0x79 */
    unsigned char pad7A[2];
    unsigned int touchHit;           /* 0x7C */
    unsigned char touchX;          /* 0x80 */
    unsigned char touchY;          /* 0x81 */
    unsigned char pad82[2];
    unsigned int transitionStep;           /* 0x84 */
    unsigned int slotsEnabled;           /* 0x88 */
    unsigned int seasonal;           /* 0x8C */
    unsigned int hasAreaData;           /* 0x90 */
    ZukanDetailAreaEntry *areaEntries;           /* 0x94 */
    unsigned int markerChar;           /* 0x98 */
    unsigned int markerPalette;           /* 0x9C */
    unsigned int markerCellAnim;           /* 0xA0 */
    unsigned int mapChar;           /* 0xA4 */
    unsigned int mapPalette;           /* 0xA8 */
    unsigned int mapCellAnim;           /* 0xAC */
    unsigned int townIconChar;           /* 0xB0 */
    unsigned int townIconPalette;           /* 0xB4 */
    unsigned int townIconCellAnim;           /* 0xB8 */
    struct ClactActor *actor[7];                  /* 0xBC: map actors; 3 no-data, 4 cursor, 5 town select, 6 player */
    unsigned char arrowAnimIndex;          /* 0xD8 */
    unsigned char padD9[3];
    struct ClactActor *townIconActor[0x3d];                  /* 0xDC */
    struct Unit *mapUnit;                 /* 0x1D0 */
    void *mapRenderer;                 /* 0x1D4 */
    unsigned int blendAlpha;          /* 0x1D8 */
    unsigned short blendPhase;        /* 0x1DC */
    unsigned char pad1DE[2];
    struct { unsigned int state; struct ClactActor *obj; } markers[0x3d];                  /* 0x1E0 */
    struct TownMapInfoRow *townInfo;          /* 0x3C8 */
    unsigned char townOrder[0x40];          /* 0x3CC */
    void *areaArcHandle;                 /* 0x40C */
    struct TcbTask *effectTask;                 /* 0x410 */
    unsigned char pendingEffect;         /* 0x414 */
    unsigned char pad415[3];
    struct Ov208Blend *blendMain;                 /* 0x418 */
    struct Ov208Blend *blendSub;                 /* 0x41C */
    struct Ov208PalFade *paletteAnim;                 /* 0x420 */
    int mode;          /* 0x424 */
    unsigned int keyFlag;          /* 0x428 */
    unsigned int overlayPending;          /* 0x42C */
    unsigned int overlayReady;          /* 0x430 */
    unsigned int overlayCommitted;          /* 0x434 */
};

#include "../arm9/gfl_heap_wrap.h"


extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

#include "../arm9/arc_tool.h"

extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);

extern void BG_SYS_ChangeScroll(u32 index, u32 a, u32 b);






extern void BG_SYS_ChangeScrollImmediate(unsigned,unsigned,unsigned);

extern void BG_SYS_SetPriority(int,u16);

extern u32 BG_SYS_GetScrollY(u32 layer);














extern void BG_SYS_MarkTileDirty(u32 layer);

#include "zukan_detail_headbar.h"








#define FX(x) ((int)(((x)>0) ? ((float)((int)(x)<<12)+0.5f) : ((float)((int)(x)<<12)-0.5f)))

#define FIELD(n) TOWNMAP_GRH_GetTownInfoValue(p->townInfo,i,n)




#define REG32(a) (*(volatile u32 *)(a))

#define REG16(a) (*(volatile u16 *)(a))


struct BigObj;

struct SaveBlock;

struct Rec44;

struct ZukanDetailVec3;

#include "../types.h"

#include "../arm9/clact.h"
typedef struct {
    u16 x;
    u16 y;
    u16 animSeq;
    u8 drawPriority;
    u8 bgPriority;
} ZukanDetailAreaObjPos;

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





typedef enum { ONE = 1 } One;

#include "../arm9/mi_memory.h"

/* The DS code was built against other parameter widths for BG_SYS_InitBgLayer (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_InitBgLayer(u8 bgId, const struct BgTemplate *tmpl, u8 type);
#else
#include "../arm9/bg_sys.h"
#endif

extern void BG_SYS_FreeSlot(u8);

extern void BG_SYS_SetPlaneVisible(u8,u8);

extern void BG_SYS_FreeLayerBuf(u32 i);















#include "../arm9/touchpanel.h"


#include "../arm9/key.h"








#include "../arm9/gf_overlay.h"

#include "zukan_detail_procsys.h"

















#include "../arm9/gx.h"























#include "../ov010/symbol_map.h"





#include "../arm9/poke_tool_ext.h"



















extern void ZUKAN_DETAIL_AREA_FinishHideOverlay(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);







#include "../arm9/zonedata.h"




extern void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *, struct Ov208AreaWork *, struct Ov208Ctx *, int);



#include "zukan_detail_graphic.h"









void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v);

u32 ZUKAN_DETAIL_AREA_Init(void *fsm,u32 seq,u16 *heap,u32 workArg,struct Ov208Ctx *key);

u32 ZUKAN_DETAIL_AREA_Exit(void *fsm, u32 seq, void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

int ZUKAN_DETAIL_AREA_Main(void *proc, int *seq, u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_HandleKeyEvent(void *proc, void *seq, void *heap, struct Ov208AreaWork *st, struct Ov208Ctx *obj, int key);

void ZUKAN_DETAIL_AREA_ApplyPendingEffect(struct TcbTask *unused, void *work);

void ZUKAN_DETAIL_AREA_BuildTownOrderTable(u16 *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_LoadMapGraphics(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_NoOpLoad(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_CreateMapActors(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DeleteMapActors(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_CreateTownIconActors(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DeleteTownIconActors(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_CreateTownMarkerActors(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_CreatePrintQueues(unsigned short *a, struct Ov208AreaWork *b, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_FlushPrintWindow(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, u8 i);

void ZUKAN_DETAIL_AREA_CreateTextWindows(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DeleteTextWindows(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdateScroll(void *a, struct Ov208AreaWork *b, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdateScrollFade(void *a, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_NoOpUpdate(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdateSelectorAnim(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_ReleaseMarkerResources(void *a, struct Ov208AreaWork *q, struct Ov208Ctx *key);

struct ClactActor *ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 a, u32 b, struct Unit *res, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);

void ZUKAN_DETAIL_AREA_DeletePokemonIcon(u32 a, struct ClactActor *b);

u8 ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, int on);

u32 ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_SelectPlayerTown(void *a, struct Ov208AreaWork *b, struct Ov208Ctx *key);

u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused,struct Ov208AreaWork *p,struct Ov208Ctx *key,u8 x,u8 y);

int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key, u8 index, u8 x, u8 y, unsigned *out);

u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, u8 x, u8 y);

void ZUKAN_DETAIL_AREA_HandleCursorInput(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, int mode);

void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(void *a, struct Ov208AreaWork *b, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_RequestModeEvent4(void *a, struct Ov208AreaWork *b, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, int dir, int touch);

void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int a, int b, void *c);

void ZUKAN_DETAIL_AREA_FreeAreaEntryData(void *a);

void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_BeginModeTransition(void *a, struct Ov208AreaWork *b, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_BeginHideOverlay(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_DrawNoDataMessage(void *heap, struct Ov208AreaWork *st, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_ClearOverlayWindow(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_NoOpOverlay(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_ResetBlendAlpha(struct Ov208AreaWork *p);

void ZUKAN_DETAIL_AREA_ApplyBrightness(struct Ov208AreaWork *p);

void ZUKAN_DETAIL_AREA_SetupSplitWindows(struct Ov208AreaWork *p);

void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(struct Ov208AreaWork *p);

void ZUKAN_DETAIL_AREA_UpdateBlendPulse(struct Ov208AreaWork *p);

void ZUKAN_DETAIL_AREA_InitBlendPulse(struct Ov208AreaWork *p);

void ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key);

extern s16 FX_SinCosTable_[];

extern u8 ov072_id[];

extern const struct ZukanDetailBgEntry data_021C85C0[2];

extern const struct ZukanDetailBgEntry data_021C8618[2];

extern const u16 d_021C8670[];

extern const BankDesc data_021C8580;

extern const Row7 data_021C8558;

extern const Row7 data_021C8560;

extern const Row7 data_021C8568;

extern const struct WinCfg2 data_021C8570;

extern const struct WinCfg4 data_021C85A4;

extern const struct ZukanDetailPt data_021C8554;

extern const u8 data_021C8E14[3][2];

extern u8 data_021C8E1A[3][4];

extern s16 FX_SinCosTable_[];


void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v)
{
    *p = v;
}

/* Caller explicitly loads r2 for setup helpers whose filed bodies omit it. */
u32 ZUKAN_DETAIL_AREA_Init(void *fsm,u32 seq,u16 *heap,u32 workArg,struct Ov208Ctx *key)
{
    struct Ov208AreaWork *p;
    void *save;
    u8 i;
    save = ZUKAN_DETAIL_COMMON_GetSource(key);
    GF_OVERLAY_Load((sptr)ov072_id);
    p = ZUKAN_DETAIL_PROCSYS_AllocBuffer(fsm,sizeof(struct Ov208AreaWork),*heap);
    i = 0;
    MI_CpuFill8(p,0,sizeof(struct Ov208AreaWork));
    p->actorUnit = ZUKAN_DETAIL_GRAPHIC_Reset3dState(ZUKAN_DETAIL_COMMON_GetDisplay(key));
    p->font = ZUKAN_DETAIL_COMMON_GetFont(key);
    for (;i<2;i++) p->iconActor[i]=0;
    p->iconSlot=0;
    p->seasonal=0;
    p->hasAreaData=1;
    p->areaEntries=0;
    p->uiMode=0;
    p->scrollState=0;
    p->iconSlideState=0;
    p->season=GAME_DATA_GetSeason((const struct GameData *)save);
    p->selectedTown=0xff;
    p->transitionStep=0;
    p->slotsEnabled=1;
    p->townInfo=TOWNMAP_GRH_LoadTownInfo(*heap);
    ZUKAN_DETAIL_AREA_BuildTownOrderTable(heap,p,key);
    p->areaArcHandle=ARC_TOOL_CreateHandle(0xb2,*heap);
    p->effectTask=GFL_USE_AddMainTask(ZUKAN_DETAIL_AREA_ApplyPendingEffect,p,1);
    p->pendingEffect=0;
    ZUKAN_DETAIL_AREA_CreatePrintQueues(heap,p,key);
    p->blendMain=ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    p->blendSub=ZUKAN_DETAIL_COMMON_AllocBlendWork(*heap);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(p->blendMain);
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(p->blendSub);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(0,p->blendMain);
    ZUKAN_DETAIL_COMMON_SetBrightnessNone(1,p->blendSub);
    p->paletteAnim=ZUKAN_DETAIL_COMMON_CreatePaletteAnim(*heap,0xa);
    p->mode=0;
    p->keyFlag=1;
    p->overlayPending=0;
    p->overlayReady=1;
    p->overlayCommitted=1;
    return 1;
}

/* Caller explicitly loads r2 for the three-argument teardown helpers. */
u32 ZUKAN_DETAIL_AREA_Exit(void *fsm, u32 seq, void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;
    ZUKAN_DETAIL_AREA_FreeAreaEntryData(p->areaEntries);
    for (i = 0; i < 2; i++) {
        if (p->iconActor[i] != 0) ZUKAN_DETAIL_AREA_DeletePokemonIcon(p->iconCharKey[i], p->iconActor[i]);
        p->iconActor[i] = 0;
    }
    ZUKAN_DETAIL_AREA_ReleaseMarkerResources(heap, p, key);
    ZUKAN_DETAIL_AREA_ApplySubScreenScroll(heap, p, key);
    ZUKAN_DETAIL_AREA_DeleteTextWindows(heap, p, key);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(p->bgPalette);
    ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(heap, p, key);
    ZUKAN_DETAIL_AREA_DeleteTownIconActors(heap, p, key);
    ZUKAN_DETAIL_AREA_DeleteMapActors(heap, p, key);
    ZUKAN_DETAIL_COMMON_DeletePaletteAnim(p->paletteAnim);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(p->blendSub);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(p->blendMain);
    ZUKAN_DETAIL_AREA_DeletePrintQueues(heap, p, key);
    TCB_DeleteTask(p->effectTask);
    ARC_TOOL_DeleteHandle(p->areaArcHandle);
    TOWNMAP_GRH_FreeTownInfo(p->townInfo);
    ZUKAN_DETAIL_PROCSYS_FreeBuffer(fsm);
    GF_OVERLAY_Unload((sptr)ov072_id);
    return 1;
}

int ZUKAN_DETAIL_AREA_Main(void *proc, int *seq, u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *scene;
    void *icon;
    u32 j;
    u32 k;
    u8 i;
    int ready;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    icon = ZUKAN_DETAIL_COMMON_GetHeadbar(key);
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
                BG_SYS_ChangeScrollImmediate(i, 0, 0);
                BG_SYS_ChangeScrollImmediate(i, 3, 0);
                BG_SYS_FreeSlot(i);
            }
        }
        BG_SYS_SetPriority(2, 2);
        BG_SYS_SetPriority(3, 3);
        BG_SYS_SetPriority(0, 1);
        BG_SYS_SetPriority(6, 1);
        BG_SYS_SetPriority(7, 2);
        BG_SYS_SetPriority(4, 3);
        ZUKAN_DETAIL_AREA_LoadMapGraphics(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateMapActors(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateTownIconActors(heap, p, key);
        ZUKAN_DETAIL_AREA_CreateTownMarkerActors(heap, p, key);
        p->bgPalette = ZUKAN_DETAIL_COMMON_LoadBgPaletteAlloc(*heap, (u32)1, 4, 9, 10);
        ZUKAN_DETAIL_AREA_CreateTextWindows(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadMarkerResources(heap, p, key);
        ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, p, key);
        CLACT_SetActorObjMode((struct ClactActor *)(p->iconActor[p->iconSlot]), 1);
        ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(heap, p, key);
        if (p->hasAreaData == 1)
            ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(heap, p, key, 1);
        ZUKAN_DETAIL_COMMON_CopyHwPalettesToSlots(p->paletteAnim);
        ZUKAN_DETAIL_COMMON_StartFadeIn(p->paletteAnim);
        break;
    case 1:
        *seq = 2;
        ZUKAN_DETAIL_COMMON_SetBrightnessFull((int)(1), p->blendSub);
        ZUKAN_DETAIL_AREA_SetIconsNormalMode(heap, p, key);
        break;
    case 2:
        *seq = 3;
        ZUKAN_DETAIL_COMMON_StartBlendIn(p->blendMain);
        ZUKAN_DETAIL_COMMON_StartFadeOut(p->paletteAnim);
        if (ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) != 2) {
            ZUKAN_DETAIL_TOUCHBAR_SetMode(scene, 0, 1, ZUKAN_DETAIL_COMMON_GetEntryCount(key) > 1);
            ZUKAN_DETAIL_TOUCHBAR_SetEnabled(scene, 0);
        } else {
            ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(scene, 1);
        }
        ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 0);
        p->slotsEnabled = 0;
        ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq(scene, GAME_DATA_ContainsRecentId(ZUKAN_DETAIL_COMMON_GetSource(key), 18));
        if (ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) != 2) {
            ZUKAN_DETAIL_HEADBAR_SetIconKind(icon, 1);
            ZUKAN_DETAIL_HEADBAR_SetIconSpecies(icon);
        }
        break;
    case 3:
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(p->blendMain) == 0 && ZUKAN_DETAIL_COMMON_IsFadeBusy(p->paletteAnim) == 0
            && ZUKAN_DETAIL_TOUCHBAR_GetMode(scene) == 2 && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 2) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(scene);
            ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(heap, p, key);
            *seq = 4;
        }
        break;
    case 4:
        if (p->transitionStep == 0) {
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled(scene, 1);
            p->slotsEnabled = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (p->mode != 0) {
            ZUKAN_DETAIL_AREA_RequestModeEvent4(heap, p, key);
            *seq = 6;
        } else {
            if (p->hasAreaData == 1)
                ZUKAN_DETAIL_AREA_UpdateBlendPulse(p);
            ZUKAN_DETAIL_AREA_HandleCursorInput(heap, p, key);
        }
        break;
    case 6:
        if (p->transitionStep == 0) {
            ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(heap, p, key);
            *seq = 7;
            ZUKAN_DETAIL_COMMON_StartBlendOut(p->blendMain);
            ZUKAN_DETAIL_COMMON_StartFadeOutAlt(p->paletteAnim);
            ZUKAN_DETAIL_HEADBAR_SetIconForm(icon);
            if (p->mode == 2)
                ZUKAN_DETAIL_TOUCHBAR_SetButtonEnabled(scene, 0);
        }
        break;
    case 7:
        ready = 0;
        if (ZUKAN_DETAIL_COMMON_IsBlendBusy(p->blendMain) == 0 && ZUKAN_DETAIL_COMMON_IsFadeBusy(p->paletteAnim) == 0
            && ZUKAN_DETAIL_HEADBAR_GetIconKind(icon) == 0) {
            if (p->mode == 2) {
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
        ZUKAN_DETAIL_COMMON_SetBrightnessNone((int)(1), p->blendSub);
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
        ZUKAN_DETAIL_COMMON_TickFlashEffect(p->bgPalette);
        ZUKAN_DETAIL_AREA_UpdateScroll(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateSelectorAnim(heap, p, key);
    }
    ZUKAN_DETAIL_AREA_UpdateMode(heap, p, key);
    ZUKAN_DETAIL_COMMON_UpdateBlendFades(p->blendMain, p->blendSub);
    ZUKAN_DETAIL_COMMON_UpdatePaletteAnim(p->paletteAnim);
    ZUKAN_DETAIL_AREA_UpdatePrintQueues(heap, p, key);
    return 0;
}


void ZUKAN_DETAIL_AREA_HandleKeyEvent(void *proc, void *seq, void *heap, struct Ov208AreaWork *st, struct Ov208Ctx *obj, int key)
{
    void *sc;
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
        ZUKAN_DETAIL_COMMON_SelectNextSeenSpecies(obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, st, obj);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(heap, st, obj);
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
        ZUKAN_DETAIL_COMMON_SelectPrevSeenSpecies(obj);
        if (old != ZUKAN_DETAIL_COMMON_GetCurrentEntry(obj)) {
            ZUKAN_DETAIL_AREA_LoadAreaEntries(heap, st, obj);
            ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(heap, st, obj);
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
                ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
                return;
            }
        }
        break;
    case 4:
        if (st->overlayPending != 0) {
            st->overlayCommitted = 1;
            if (st->overlayReady != 0) {
                st->overlayPending = 0;
                ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
                return;
            }
        }
        break;
    case 5:
        GAME_DATA_SetRecentId(ZUKAN_DETAIL_COMMON_GetSource(obj), 0x12, ZUKAN_DETAIL_TOUCHBAR_IsButtonAnimActive((char *)sc));
        ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
        return;
    case 19:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, st, obj, 6);
        return;
    default:
        if (flag != 0) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(sc);
        }
        break;
    }
}

void ZUKAN_DETAIL_AREA_ApplyPendingEffect(struct TcbTask *unused, void *work)
{
    struct Ov208AreaWork *p = work;

    switch (p->pendingEffect) {
    case 1: ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(p); ZUKAN_DETAIL_AREA_ResetBlendAlpha(p); break;
    case 2: ZUKAN_DETAIL_AREA_ApplyBrightness(p); ZUKAN_DETAIL_AREA_SetupSplitWindows(p); break;
    case 3:
        ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(p);
        ZUKAN_DETAIL_AREA_ApplyBrightness(p);
        ZUKAN_DETAIL_COMMON_SetBrightnessFull(0, p->blendMain);
        break;
    }
    p->pendingEffect = 0;
    ZUKAN_DETAIL_COMMON_TransferPalettes(p->paletteAnim);
}

void ZUKAN_DETAIL_AREA_BuildTownOrderTable(u16 *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;
    for (i = 0; i < 61; i++) {
        u16 value = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)(p->townInfo), i, 0);
        u8 j;
        for (j = 0; j < 61; j++) {
            if (value == d_021C8670[j]) {
                p->townOrder[i] = j;
                break;
            }
        }
    }
}

void ZUKAN_DETAIL_AREA_LoadMapGraphics(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *h;

    h = ARC_TOOL_CreateHandle(0x55, *heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 2, 0x6000, 0x2000, *heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 2, 0x4000, 0x2000, *heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 5, 2, 0, 0x4000, 0, *heap);
    ARC_UTIL_UploadBgCharFromHandle(h, 7, 3, 0, 0xc000, 0, *heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x11, 2, 0, 0x800, 0, *heap);
    ARC_UTIL_UploadBgPaletteFromHandle(h, 0x10, 3, 0, 0x800, 0, *heap);
    ARC_TOOL_DeleteHandle(h);
}

void ZUKAN_DETAIL_AREA_NoOpLoad(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
}

void ZUKAN_DETAIL_AREA_CreateMapActors(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    BankDesc desc;
    Row7 anim, pri, pal;
    ZukanDetailAreaObjPos pos;
    struct ZukanDetailPtS pt;
    void *h;
    u8 i;

    desc = data_021C8580;
    p->mapRenderer = CLACT_CreateRenderer((struct SurfaceInit *)(&desc), 1, *heap);
    p->mapUnit = CLACT_CreateUnit(0x10, 0, *heap);
    CLACT_SetUnitRenderer(p->mapUnit, p->mapRenderer);

    h = ARC_TOOL_CreateHandle(0x55, *heap);
    p->markerPalette = CLACT_RegisterPaletteEx(h, 2, 0, 0, 0, 5, *heap);
    p->markerChar = CLACT_RegisterCharacter(h, 8, 0, 0, *heap);
    p->markerCellAnim = CLACT_RegisterCellAnim(h, 0xc, 0x13, *heap);
    ARC_TOOL_DeleteHandle(h);

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    p->mapPalette = CLACT_RegisterPaletteEx(h, 6, 0, 0xa0, 0, 2, *heap);
    p->mapChar = CLACT_RegisterCharacter(h, 0x10, 0, 0, *heap);
    p->mapCellAnim = CLACT_RegisterCellAnim(h, 0x1d, 0x2e, *heap);
    ARC_TOOL_DeleteHandle(h);

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    p->townIconPalette = CLACT_RegisterPaletteEx(h, 5, 0, 0xe0, 0, 1, *heap);
    p->townIconChar = CLACT_RegisterCharacter(h, 0xf, 0, 0, *heap);
    p->townIconCellAnim = CLACT_RegisterCellAnim(h, 0x1c, 0x2d, *heap);
    ARC_TOOL_DeleteHandle(h);

    anim = data_021C8560;
    pri = data_021C8558;
    pal = data_021C8568;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    for (i = 4; i < 7; i++)
        p->actor[i] = CLACT_CreateActor(p->mapUnit, p->markerChar, p->markerPalette, p->markerCellAnim, (struct ActorInitParam *)(&pos), 0, *heap);
    for (i = 0; i < 4; i++)
        p->actor[i] = CLACT_CreateActor(p->mapUnit, p->mapChar, p->mapPalette, p->mapCellAnim, (struct ActorInitParam *)(&pos), 0, *heap);

    for (i = 0; i < 7; i++) {
        CLACT_SetActorAnimSeq(p->actor[i], anim.v[i]);
        CLACT_SetActorAutoAnim(p->actor[i], 1);
        CLACT_SetActorBgPriority(p->actor[i], pri.v[i]);
        CLACT_SetActorDrawPriority(p->actor[i], pal.v[i]);
        CLACT_SetActorDrawEnable(p->actor[i], 0);
        CLACT_SetActorObjMode(p->actor[i], 1);
    }

    pt.x = 0x80;
    pt.y = 0x60;
    for (i = 0; i < 4; i++)
        CLACT_AddActorSurfacePos(p->actor[i], (const struct ClactVec2 *)(&pt), 0);

    p->arrowAnimIndex = 7;
}

/*
 * Tail: 021C044E..021C0450 is two zero alignment bytes, not a follower.
 */
void ZUKAN_DETAIL_AREA_DeleteMapActors(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;
    for (i = 0; i < 7; i++) CLACT_DeleteActor(p->actor[i]);
    CLACT_ReleaseCellAnim(p->townIconCellAnim);
    CLACT_ReleaseCharacter(p->townIconChar);
    CLACT_ReleasePalette(p->townIconPalette);
    CLACT_ReleaseCellAnim(p->mapCellAnim);
    CLACT_ReleaseCharacter(p->mapChar);
    CLACT_ReleasePalette(p->mapPalette);
    CLACT_ReleaseCellAnim(p->markerCellAnim);
    CLACT_ReleaseCharacter(p->markerChar);
    CLACT_ReleasePalette(p->markerPalette);
    CLACT_DeleteUnit(p->mapUnit);
    CLACT_DeleteRenderer(p->mapRenderer);
}

void ZUKAN_DETAIL_AREA_CreateTownIconActors(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    ZukanDetailAreaObjPos pos;
    u8 i;

    MI_CpuFill8(&pos, 0, sizeof(pos));
    for (i = 0; i < 0x3d; i++) {
        pos.x = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 0x19);
        pos.y = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 0x1a);
        p->townIconActor[i] = CLACT_CreateActor(p->actorUnit, p->townIconChar, p->townIconPalette, p->townIconCellAnim, (struct ActorInitParam *)(&pos), 0, *heap);
        CLACT_SetActorAnimSeq(p->townIconActor[i], TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 0x18));
        CLACT_SetActorAutoAnim(p->townIconActor[i], 1);
        CLACT_SetActorBgPriority(p->townIconActor[i], 2);
        CLACT_SetActorDrawPriority(p->townIconActor[i], 4);
        CLACT_SetActorDrawEnable(p->townIconActor[i], 0);
        CLACT_SetActorObjMode(p->townIconActor[i], 1);
    }
}

/*
 * Releases each of the 0x3D handles held from +0xDC on.
 */
void ZUKAN_DETAIL_AREA_DeleteTownIconActors(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++)
        CLACT_DeleteActor(p->townIconActor[i]);
}

void ZUKAN_DETAIL_AREA_CreateTownMarkerActors(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *k;
    u8 i;
    u16 kind;
    u16 msg;
    ZukanDetailAreaObjPos pos;

    k = ZUKAN_DETAIL_COMMON_GetSource(key);
    for (i = 0; i < 0x3d; i++) {
        msg = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 0x10);
        if (msg != 0xffff) {
            if ((SYMBOL_MAP_CheckEventFlag(k, msg) == 0 ? 1 : 0)) {
                p->markers[i].state = 1;
                p->markers[i].obj = 0;
            } else {
                kind = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 0xb);
                pos.x = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 2);
                pos.y = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, i, 3);
                pos.animSeq = kind == 4 ? 0xe : 0x10;
                pos.drawPriority = 5;
                pos.bgPriority = 2;
                p->markers[i].state = 2;
                p->markers[i].obj = CLACT_CreateActor(p->mapUnit, p->markerChar, p->markerPalette, p->markerCellAnim, (struct ActorInitParam *)(&pos), 0, *heap);
                CLACT_SetActorAutoAnim(p->markers[i].obj, 1);
                CLACT_SetActorDrawEnable(p->markers[i].obj, 1);
                CLACT_SetActorObjMode(p->markers[i].obj, 1);
            }
        } else {
            p->markers[i].state = 0;
            p->markers[i].obj = 0;
        }
    }
}

/*
 * Frees the second word of every entry whose first word is 2.
 */
void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++) {
        if (p->markers[i].state == 2)
            CLACT_DeleteActor(p->markers[i].obj);
    }
}

void ZUKAN_DETAIL_AREA_CreatePrintQueues(unsigned short *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        p->printQue[i] = PRINTSYS_QUE_Create((*heap));
        p->printPending[i] = 0;
    }
}

/*
 * Clears a word and releases two handles of each of four entries.
 */
void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        p->printPending[i] = 0;
        PRINTSYS_QUE_Clear(p->printQue[i]);
        PRINTSYS_QUE_Delete(p->printQue[i]);
    }
}







void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        PRINTSYS_QUE_Main(p->printQue[i]);
        ZUKAN_DETAIL_AREA_FlushPrintWindow(heap, p, key, i);
    }
}

void ZUKAN_DETAIL_AREA_FlushPrintWindow(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, u8 i)
{
    struct BmpWin *w;

    if (p->printPending[i] != 0) {
        if (PRINTSYS_QUE_IsExistTarget(p->printQue[i], BMP_WIN_GetBmp(p->win[i])) == 0) {
            w = p->win[i];
            BMP_WIN_TransferChars((struct BmpWin *)w);
            BMP_WIN_MakeScreen((struct BmpWin *)w);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)w));
            p->printPending[i] = 0;
        }
    }
}

void ZUKAN_DETAIL_AREA_CreateTextWindows(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    struct WinCfg2 a;
    struct WinCfg4 b;
    u8 i;

    a = data_021C8570;
    b = data_021C85A4;
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 4, 0, 0x100, 0x20, *heap);
    ARC_UTIL_UploadPaletteFromArchive(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 2; i++) {
        p->subWin[i] = BMP_WIN_Create((u32)a.e[i].bg, (u32)a.e[i].x, (u32)a.e[i].y, a.e[i].w, a.e[i].h, a.e[i].pal, a.e[i].base);
        BMP_Clear(BMP_WIN_GetBmp(p->subWin[i]), 0);
        BMP_WIN_TransferChars(p->subWin[i]);
    }
    for (i = 0; i < 4; i++) {
        p->win[i] = BMP_WIN_Create((u32)b.e[i].bg, (u32)b.e[i].x, (u32)b.e[i].y, b.e[i].w, b.e[i].h, b.e[i].pal, b.e[i].base);
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
        BMP_WIN_TransferChars(p->win[i]);
    }
    p->msg[0] = MSGDATA_CreateFromArchive(0, 2, 0xea, *heap);
    p->msg[1] = MSGDATA_CreateFromArchive(0, 2, 0x59, *heap);
}

void ZUKAN_DETAIL_AREA_DeleteTextWindows(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;
    for (i = 0; i < 2; i++) MSGDATA_Delete(p->msg[i]);
    for (i = 0; i < 4; i++) {
        p->printPending[i] = 0;
        PRINTSYS_QUE_Clear(p->printQue[i]);
        BMP_WIN_Delete(p->win[i]);
    }
    for (i = 0; i < 2; i++) BMP_WIN_Delete(p->subWin[i]);
}

void ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *h;

    h = ARC_TOOL_CreateHandle(0x9f, *heap);
    ARC_UTIL_UploadPaletteFromHandle(h, 2, 4, 0, 0, 0x100, *heap);
    p->subScreenChar = ARC_UTIL_RegisterObjCharFromHandle(h, 12, 7, 0, 0, *heap);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 0x26, 7, 0, (u16)p->subScreenChar, 0, 0, *heap);
    ARC_TOOL_DeleteHandle(h);
}

void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u32 v = p->subScreenChar;
    BG_SYS_FreeTileRun(7, (u16)v, (u16)(v >> 16));
}

void ZUKAN_DETAIL_AREA_UpdateScroll(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    ZUKAN_DETAIL_AREA_UpdateScrollFade(heap, p, key);
    ZUKAN_DETAIL_AREA_NoOpUpdate(heap, p, key);
}

void ZUKAN_DETAIL_AREA_UpdateScrollFade(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    switch (p->scrollState) {
    case 0:
        break;
    case 2:
        break;
    case 1:
        if ((int)BG_SYS_GetScrollY((int)7) >= 0x40) {
            BG_SYS_ChangeScroll(7, 3, 0x40);
            p->scrollState = 2;
        } else {
            BG_SYS_ChangeScroll(7, 4, 8);
            BG_SYS_ChangeScroll(6, 4, 8);
        }
        break;
    case 3:
        if ((int)BG_SYS_GetScrollY((int)7) <= 0) {
            BG_SYS_ChangeScroll(7, 3, 0);
            p->scrollState = 0;
        } else {
            BG_SYS_ChangeScroll(7, 5, 8);
            BG_SYS_ChangeScroll(6, 5, 8);
        }
        break;
    }
    if (p->iconActor[p->iconSlot] == 0)
        return;
    {
        short v[2];

        switch (p->iconSlideState) {
        case 0:
            break;
        case 2:
            break;
        case 1:
            CLACT_GetActorSurfacePos(p->iconActor[p->iconSlot], (struct ClactVec2 *)v, 1);
            if (v[1] <= 0x70) {
                v[1] = 0x70;
                p->iconSlideState = 2;
            } else {
                v[1] -= 8;
            }
            CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActor[p->iconSlot]), (const struct ClactVec2 *)v, 1);
            break;
        case 3:
            CLACT_GetActorSurfacePos(p->iconActor[p->iconSlot], (struct ClactVec2 *)v, 1);
            if (v[1] >= 0xb0) {
                v[1] = 0xb0;
                p->iconSlideState = 0;
            } else {
                v[1] += 8;
            }
            CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActor[p->iconSlot]), (const struct ClactVec2 *)v, 1);
            break;
        }
    }
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void ZUKAN_DETAIL_AREA_NoOpUpdate(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
}

void ZUKAN_DETAIL_AREA_UpdateSelectorAnim(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *scene;
    u8 sel;
    u16 anim;
    u32 next;
    u16 nextAnim;

    scene = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    sel = p->arrowAnimIndex;
    if (sel == 2) {
        anim = 2;
        next = 1;
        nextAnim = 4;
    } else if (sel == 1) {
        anim = 4;
        next = 2;
        nextAnim = 2;
    }
    if (sel != 7 && CLACT_IsActorAnimActive(p->actor[sel]) == 0) {
        CLACT_SetActorAnimSeq(p->actor[p->arrowAnimIndex], anim);
        CLACT_SetActorAutoAnim(p->actor[next], 1);
        CLACT_SetActorAnimSeq(p->actor[next], nextAnim);
        p->arrowAnimIndex = 7;
        if (p->uiMode == 0 || p->uiMode == 5)
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)scene, 1);
    }
}

void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *h;

    h = ARC_TOOL_CreateHandle(7, *heap);
    p->iconPalette = CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), 1, 0, *heap);
    p->iconCellAnim = CLACT_RegisterCellAnim(h, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryIdSub(), *heap);
    ARC_TOOL_DeleteHandle(h);
}

/*
 * Calls 0x0204AFD8 on +0x58 and 0x0204ADA4 on +0x54 of the second argument.
 */
void ZUKAN_DETAIL_AREA_ReleaseMarkerResources(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    CLACT_ReleaseCellAnim(p->iconCellAnim);
    CLACT_ReleasePalette(p->iconPalette);
}

struct ClactActor *ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 palette, u32 cellAnim, struct Unit *unit, u16 heap, u32 species, u32 form,
                  u32 gender, u32 isEgg, u8 x, u8 y)
{
    ZukanDetailAreaObjPos pos;
    void *h;
    struct ClactActor *obj;

    h = ARC_TOOL_CreateHandle(7, heap);
    pos.x = x;
    pos.y = y;
    pos.animSeq = 1;
    pos.drawPriority = 1;
    pos.bgPriority = 0;
    *slot = CLACT_RegisterCharacter(h, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), 0, 1, heap);
    obj = CLACT_CreateActor(unit, *slot, palette, cellAnim, (struct ActorInitParam *)(&pos), 1, heap);
    CLACT_SetActorAutoAnim(obj, 0);
    CLACT_SetActorPaletteOffset(obj, POKE_TOOL_CalcIconPalette(species, form, gender, isEgg), 0);
    CLACT_SetActorObjMode(obj, 0);
    ARC_TOOL_DeleteHandle(h);
    return obj;
}

/*
 * Calls 0x0204B3B4 on the second argument, then 0x0204A8D4 on the first.
 */
void ZUKAN_DETAIL_AREA_DeletePokemonIcon(u32 charKey, struct ClactActor *actor)
{
    CLACT_DeleteActor(actor);
    CLACT_ReleaseCharacter(charKey);
}

u8 ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *a;
    u32 m;
    int v;
    u8 r;

    a = ZUKAN_DETAIL_COMMON_GetSource(key);
    m = GAME_DATA_GetPlayerZoneId((const struct PlayerWork *)GAME_DATA_GetMyPlayerWork((struct GameData *)a));
    r = 0xff;
    v = TOWNMAP_GRH_FindRecordIndex(p->townInfo, SYMBOL_MAP_ResolveZoneId(a, m));
    if (v != 0xffff)
        r = v;
    return r;
}

void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 idx;
    u16 pos[2];

    idx = ZUKAN_DETAIL_AREA_FindPlayerTownIndex(heap, p, key);
    if (idx != 0xff) {
        pos[0] = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, idx, 2);
        pos[1] = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, idx, 3);
        CLACT_AddActorSurfacePos(p->actor[6], (const struct ClactVec2 *)pos, 0);
    }
}

void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, int on)
{
    if (on) {
        if (ZUKAN_DETAIL_AREA_FindPlayerTownIndex(heap, p, key) != 0xff) {
            CLACT_SetActorAnimSeq(p->actor[6], 6);
            CLACT_SetActorDrawEnable(p->actor[6], 1);
        }
    } else {
        CLACT_SetActorDrawEnable(p->actor[6], 0);
    }
}

/*
 * Loads the word at +0xD4 of the second argument and tail-calls the function at 0x0204B3F4 with it.
 *
 * The pool word carries the thumb bit, so the callee is deliberately left
 * undeclared here and resolved through the label class.
 */
u32 ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    return CLACT_GetActorDrawEnable(p->actor[6]);
}

void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    struct ZukanDetailPt pt = data_021C8554;

    if (p->selectedTown == 0xff)
        p->selectedTown = ZUKAN_DETAIL_AREA_FindPlayerTownIndex(heap, p, key);
    if (p->selectedTown != 0xff) {
        pt.x = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, p->selectedTown, 2);
        pt.y = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, p->selectedTown, 3);
    }
    CLACT_AddActorSurfacePos(p->actor[4], (const struct ClactVec2 *)(&pt), 0);
    CLACT_SetActorDrawEnable(p->actor[4], 1);
}

/*
 * Stores the byte result of ZUKAN_DETAIL_AREA_FindPlayerTownIndex at +0x79 of the second argument then calls ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown.
 */
void ZUKAN_DETAIL_AREA_SelectPlayerTown(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    p->selectedTown = ZUKAN_DETAIL_AREA_FindPlayerTownIndex((u16 *)heap, p, key);
    ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown((u16 *)heap, p, key);
}

u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused,struct Ov208AreaWork *p,struct Ov208Ctx *key,u8 x,u8 y)
{
    ButtonSphere ball;
    VecFx32 point;
    ButtonSegment seg;
    VecFx32 a,b;
    ButtonHitInfo out;
    int best;
    u8 i;
    u8 result=255;
    point.x=FX(x);
    point.y=FX(y);
    point.z=0;
    BUTTON_MAN_InitSphere(&ball,&point,0);
    for(i=0;i<61;i++) {
        if (p->markers[i].state==1) continue;
        a.x=FX(FIELD(6));
        a.y=FX(FIELD(7));
        a.z=0;
        b.x=FX(FIELD(8));
        b.y=FX(FIELD(9));
        b.z=0;
        BUTTON_MAN_InitSegment(&seg,&a,&b,FX(FIELD(10)));
        if (BUTTON_MAN_SegmentSphereTest(&seg,&ball,&out)) {
            if(result==255) { best=out.d; result=i; }
            else if(best>out.d) { best=out.d; result=i; }
        }
    }
    return result;
}

/*
 * Tail: 021C1066..021C1068 is two zero alignment bytes, not a follower.
 */
int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key, u8 index, u8 x, u8 y, unsigned *out)
{
    unsigned dx, dy, distance;
    if (p->markers[index].state == 1) return 0;
    dx = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)(p->townInfo), index, 4);
    dy = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)(p->townInfo), index, 5);
    dy -= y;
    dx -= x;
    distance = dx * dx + dy * dy;
    if (distance < 144) {
        if (out) *out = distance;
        return 1;
    }
    return 0;
}

u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, u8 x, u8 y)
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

void ZUKAN_DETAIL_AREA_HandleCursorInput(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *s;
    int hit, touch;
    int moved, done;
    u32 x, y, tx, ty;

    s = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    if (p->keyFlag == 0 || p->arrowAnimIndex != 7)
        return;

    switch (p->uiMode) {
    case 0:
        hit = 0;
        touch = 0;
        if (KEY_GetTrg() & 1) {
            touch = 1;
            hit = 1;
        } else if (p->seasonal != 0) {
            if (KEY_GetRepeat() & 0x100) {
                p->season++;
                if (p->season >= 4)
                    p->season = 0;
                hit = 1;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
            } else if (KEY_GetRepeat() & 0x200) {
                if (p->season == 0) p->season = 3; else p->season--;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
                hit = 1;
            }
        }
        if (hit) {
            UI_SetInputMode(0);
            if (touch)
                p->touchHit = 0;
        }
        if (hit == 0) {
            if (TOUCHPANEL_GetPointTrg(&x, &y)) {
                if (p->seasonal == 0) {
                    if (y < 0xa8) {
                        touch = 1;
                        hit = 1;
                    }
                } else if (x >= 0x88 && x < 0xa0 && y < 0x10) {
                    p->season++;
                    if (p->season >= 4)
                        p->season = 0;
                    hit = 1;
                    ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, hit);
                    GFL_USE_PlaySeDefaultVolume(0x54a);
                } else if (x < 0x18 && y < 0x10) {
                    if (p->season == 0) p->season = 3; else p->season--;
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
                UI_SetInputMode(1);
                if (touch) {
                    p->touchHit = hit;
                    p->touchX = x;
                    p->touchY = y;
                }
            }
        }
        if (touch && (p->seasonal != 0 || p->hasAreaData != 0)) {
            ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 0);
        }
        break;
    case 5:
        moved = 0;
        done = 1;
        if (KEY_GetTrg() & 2) {
            p->keyFlag = 0;
            moved = 1;
            done = 0;
        } else if (p->seasonal != 0) {
            if (KEY_GetRepeat() & 0x100) {
                p->season++;
                if (p->season >= 4)
                    p->season = 0;
                done = 0;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, done);
                moved = 1;
                GFL_USE_PlaySeDefaultVolume(0x54a);
            } else if (KEY_GetRepeat() & 0x200) {
                if (p->season == 0) p->season = 3; else p->season--;
                done = 0;
                ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 0, 0);
                GFL_USE_PlaySeDefaultVolume(0x54a);
                moved = 1;
            }
        }
        if (moved)
            UI_SetInputMode(0);
        if (moved == 0) {
            if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
                if (p->seasonal == 0) {
                    if (ty >= 0xa8)
                        done = 0;
                } else if (p->seasonal == 1) {
                    if (tx >= 0x88 && tx < 0xa0 && ty < 0x10) {
                        p->season++;
                        if (p->season >= 4)
                            p->season = 0;
                        moved = 1;
                        ZUKAN_DETAIL_AREA_SwitchAreaSet(heap, p, key, 1, moved);
                        GFL_USE_PlaySeDefaultVolume(0x54a);
                        done = 0;
                    } else if (tx < 0x18 && ty < 0x10) {
                        if (p->season == 0) p->season = 3; else p->season--;
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
                UI_SetInputMode(1);
        }
        if (done)
            ZUKAN_DETAIL_AREA_HandleTownTouchInput(heap, p, key);
        break;
    }
}

static inline void set3(struct ZukanDetailVec3 *v, int x, int y, int z)
{
    v->x = x;
    v->y = y;
    v->z = z;
}

void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u32 tx, ty;
    struct { struct ZukanDetailPtS t, c; } pt;
    u8 idx;
    u8 old;
    int found, near;
    int moved;
    unsigned int keys;
    int dx, dy;

    if (p->hasAreaData == 0)
        return;
    if (UI_GetInputMode() == 0) {
        if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
            UI_SetInputMode(1);
            CLACT_SetActorDrawEnable(p->actor[4], 0);
        }
    } else if (KEY_GetTrg()) {
        UI_SetInputMode(0);
        ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(heap, p, key);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        return;
    }
    if (UI_GetInputMode() == 0) {
        old = p->selectedTown;
        moved = 0;
        found = 0;
        near = 0;
        {
        struct ZukanDetailVec3 v = {0, 0, 0};
        struct ZukanDetailVec3 d = {0, 0, 0};
        struct ZukanDetailVec3 a;
        struct ZukanDetailVec3 b;
        CLACT_GetActorSurfacePos(p->actor[4], (struct ClactVec2 *)(&pt.c), 0);
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
        idx = ZUKAN_DETAIL_AREA_FindNearestTown(heap, p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (idx != 0xff) {
            found = 1;
            pt.t.x = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, idx, 4);
            pt.t.y = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, idx, 5);
            a.x = FX(pt.t.x);
            a.y = FX(pt.t.y);
            a.z = 0;
            b.x = FX(pt.c.x);
            b.y = FX(pt.c.y);
            b.z = 0;
            VEC_Subtract((struct VecFx32 *)(&a), (struct VecFx32 *)(&b), (struct VecFx32 *)(&d));
            if (VEC_Mag((struct VecFx32 *)(&d)) < 0x1BB6)
                near = 1;
            if (VEC_Mag((struct VecFx32 *)(&d)) > 0x1000) {
                VEC_Normalize((struct VecFx32 *)(&d), (struct VecFx32 *)(&d));
                BUTTON_MAN_ScaleVec((const struct VecFx32 *)(&d), 0x1000, (struct VecFx32 *)(&d));
            }
        }
        if (moved == 0 && found == 0)
            return;
        if (moved == 0 && found != 0 && near != 0) {
            pt.c = pt.t;
        } else {
            VEC_Normalize((struct VecFx32 *)(&v), (struct VecFx32 *)(&v));
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
        CLACT_AddActorSurfacePos(p->actor[4], (const struct ClactVec2 *)(&pt.c), 0);
        p->selectedTown = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, p, key, (u8)pt.c.x, (u8)pt.c.y);
        if (p->selectedTown != old) {
            ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
            if (p->selectedTown != 0xff)
                GFL_USE_PlaySeDefaultVolume(0x548);
        }
        }
    } else if (TOUCHPANEL_GetPointTrg(&tx, &ty)) {
        p->selectedTown = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, p, key, (u8)tx, (u8)ty);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
        ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        if (p->selectedTown != 0xff)
            GFL_USE_PlaySeDefaultVolume(0x54C);
    }
}

void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    switch (p->uiMode) {
    case 1:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 2);
        break;
    case 2:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 5);
        break;
    case 3:
        switch (p->transitionStep) {
        case 1:
            ZUKAN_DETAIL_AREA_BeginHideOverlay(heap, p, key);
            p->transitionStep = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_FinishHideOverlay(heap, p, key);
            p->transitionStep = 3;
            break;
        case 3:
            ZUKAN_DETAIL_AREA_DrawNoDataMessage(heap, p, key);
            p->transitionStep = 0;
            ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 0);
            break;
        }
        break;
    case 4:
        switch (p->transitionStep) {
        case 1:
            ZUKAN_DETAIL_AREA_ClearOverlayWindow(heap, p, key);
            p->transitionStep = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_RequestBlendRestore(heap, p, key);
            p->transitionStep = 3;
            break;
        case 3:
            ZUKAN_DETAIL_AREA_NoOpOverlay(heap, p, key);
            p->transitionStep = 0;
            break;
        }
        break;
    case 6:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 7);
        break;
    case 7:
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 0);
        break;
    case 8:
        switch (p->transitionStep) {
        case 1:
            ZUKAN_DETAIL_AREA_BeginHideOverlay(heap, p, key);
            p->transitionStep = 2;
            break;
        case 2:
            ZUKAN_DETAIL_AREA_FinishHideOverlay(heap, p, key);
            p->transitionStep = 3;
            break;
        case 3:
            ZUKAN_DETAIL_AREA_DrawNoDataMessage(heap, p, key);
            p->transitionStep = 0;
            ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 5);
            break;
        }
        break;
    }
}

void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, int mode)
{
    void *s;
    u32 wide;

    s = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    switch (p->uiMode) {
    case 0:
        if (mode == 1) {
        } else if (mode == 3) {
            p->transitionStep = 1;
        } else if (mode == 4) {
            p->transitionStep = 1;
        }
        break;
    case 1:
        if (mode == 2)
            ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(s, 0);
        break;
    case 2:
        if (mode == 5) {
            p->scrollState = 1;
            p->iconSlideState = 1;
            if (p->hasAreaData == 1) {
                if (p->touchHit == 0) {
                    ZUKAN_DETAIL_AREA_SelectPlayerTown(heap, p, key);
                } else {
                    p->selectedTown = ZUKAN_DETAIL_AREA_FindTownAtPoint(heap, p, key, p->touchX, p->touchY);
                    if (p->selectedTown != 0xff)
                        CLACT_SetActorDrawEnable(p->actor[5], 1);
                }
                ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
                ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
            }
            ZUKAN_DETAIL_TOUCHBAR_SetMode(s, 1, 1, ZUKAN_DETAIL_COMMON_GetEntryCount(key) > 1);
        }
        break;
    case 3:
        if (mode == 0) {
            if (p->overlayPending != 0) {
                p->overlayReady = 1;
                if (p->overlayCommitted != 0) {
                    p->overlayPending = 0;
                    ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(s);
                }
            }
            if (p->arrowAnimIndex == 7 && p->slotsEnabled != 0)
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 1);
        }
        break;
    case 4:
        break;
    case 5:
        if (mode == 6) {
        } else if (mode == 8) {
            p->transitionStep = 1;
        }
        break;
    case 6:
        if (mode == 7)
            ZUKAN_DETAIL_TOUCHBAR_SetButtonDrawEnable(s, 0);
        break;
    case 7:
        if (mode == 0) {
            p->scrollState = 3;
            p->iconSlideState = 3;
            CLACT_SetActorDrawEnable(p->actor[4], 0);
            CLACT_SetActorDrawEnable(p->actor[5], 0);
            wide = ZUKAN_DETAIL_COMMON_GetEntryCount(key) > 1 ? 1 : 0;
            ZUKAN_DETAIL_TOUCHBAR_SetMode(s, 0, 1, wide);
            ZUKAN_DETAIL_TOUCHBAR_SetButtonAnimSeq((struct Ov208Scene *)s, GAME_DATA_ContainsRecentId(ZUKAN_DETAIL_COMMON_GetSource(key), 0x12));
        }
        break;
    case 8:
        if (mode == 5) {
            ZUKAN_DETAIL_TOUCHBAR_ClearButtonState(s);
            if (p->arrowAnimIndex == 7 && p->slotsEnabled != 0)
                ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 1);
        }
        break;
    }
    p->uiMode = mode;
}

void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u32 prev;
    u16 id;
    void *win;
    void *str;
    void *buf;
    u32 out1, out2, form;

    prev = p->seasonal;
    id = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    ZUKAN_DETAIL_AREA_FreeAreaEntryData(p->areaEntries);
    p->areaEntries = ZUKAN_DETAIL_AREA_LoadAreaEntryData(id, *heap, p->areaArcHandle);
    p->seasonal = ((ZukanDetailAreaEntry *)p->areaEntries)->allSeasons == 0;
    if (p->seasonal == 0)
        p->hasAreaData = ((ZukanDetailAreaEntry *)p->areaEntries)[0].noArea == 0;
    else
        p->hasAreaData = ((ZukanDetailAreaEntry *)p->areaEntries)[p->season].noArea == 0;

    if (p->iconActor[p->iconSlot] != 0)
        CLACT_SetActorDrawEnable(p->iconActor[p->iconSlot], 0);
    p->iconSlot = (p->iconSlot + 1) % 2;
    if (p->iconActor[p->iconSlot] != 0) {
        if (p->iconActor[p->iconSlot] != 0)
            ZUKAN_DETAIL_AREA_DeletePokemonIcon(p->iconCharKey[p->iconSlot], p->iconActor[p->iconSlot]);
        p->iconActor[p->iconSlot] = 0;
    }

    ZUKAN_SAVE_GetViewGenderAndForm(ZUKAN_SAVE_GetFromGameData(ZUKAN_DETAIL_COMMON_GetSource(key)), id, &out1, &out2, &form, *heap);
    p->iconActor[p->iconSlot] = ZUKAN_DETAIL_AREA_CreatePokemonIcon(&p->iconCharKey[p->iconSlot], p->iconPalette, p->iconCellAnim, p->actorUnit,
                                               *heap, id, form, out1, 0, 0x38, 0xb0);
    p->printPending[0] = 0;
    PRINTSYS_QUE_Clear(p->printQue[0]);
    BMP_Clear(BMP_WIN_GetBmp(p->win[0]), 0);
    win = WORDSET_CreateDefault(*heap);
    str = MSGDATA_AllocString(p->msg[0], 0xbd);
    buf = STRBUF_Create(0x40, *heap);
    WORDSET_SetSlotSpeciesName(win, 0, id);
    WORDSET_CopyTaggedText(win, buf, str);
    STRBUF_Delete(str);
    WORDSET_Delete(win);
    PRINTSYS_PrintQueColor((void *)p->printQue[0], BMP_WIN_GetBmp(p->win[0]), 0, 5, buf, p->font, 0x3c40);
    STRBUF_Delete(buf);
    p->printPending[0] = 1;
    ZUKAN_DETAIL_AREA_FlushPrintWindow(heap, p, key, 0);

    if (p->seasonal == 0) {
        if (prev == 1) {
            p->printPending[2] = 0;
            PRINTSYS_QUE_Clear(p->printQue[2]);
            BMP_Clear(BMP_WIN_GetBmp(p->win[2]), 0);
            BMP_WIN_TransferChars(p->win[2]);
            CLACT_SetActorDrawEnable(p->actor[0], 0);
            CLACT_SetActorDrawEnable(p->actor[2], 0);
            CLACT_SetActorDrawEnable(p->actor[1], 0);
        }
    } else if (prev == 0) {
        ZUKAN_DETAIL_AREA_DrawAreaSetTitle(heap, p, key);
        CLACT_SetActorDrawEnable(p->actor[0], 1);
        CLACT_SetActorAnimSeq(p->actor[2], 2);
        CLACT_SetActorDrawEnable(p->actor[2], 1);
        CLACT_SetActorAnimSeq(p->actor[1], 4);
        CLACT_SetActorDrawEnable(p->actor[1], 1);
    }
}

/*
 * Calls ZUKAN_DETAIL_AREA_BeginModeTransition then ZUKAN_DETAIL_AREA_UpdateTerrainIcons on the same three arguments.
 */
void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    ZUKAN_DETAIL_AREA_BeginModeTransition(heap, p, key);
    ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
}

void ZUKAN_DETAIL_AREA_RequestModeEvent4(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 4);
}

void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *str;
    struct ZukanDetailPt pt;

    p->printPending[1] = 0;
    PRINTSYS_QUE_Clear(p->printQue[1]);
    BMP_Clear(BMP_WIN_GetBmp(p->win[1]), 0);
    if (p->selectedTown != 0xff) {
        str = MSGDATA_AllocString(p->msg[1], ZONEDATA_GetPlaceNameId(TOWNMAP_GRH_GetTownInfoValue(p->townInfo, p->selectedTown, 0)));
        PRINTSYS_PrintQueColor((void *)p->printQue[1], BMP_WIN_GetBmp(p->win[1]), 0, 1, str, p->font, 0x3c40);
        STRBUF_Delete(str);
        p->printPending[1] = 1;
        ZUKAN_DETAIL_AREA_FlushPrintWindow(heap, p, key, 1);
        pt.x = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, p->selectedTown, 2);
        pt.y = TOWNMAP_GRH_GetTownInfoValue(p->townInfo, p->selectedTown, 3);
        CLACT_SetActorAnimSeq(p->actor[5], 5);
        CLACT_AddActorSurfacePos(p->actor[5], (const struct ClactVec2 *)(&pt), 0);
        CLACT_SetActorDrawEnable(p->actor[5], 1);
    } else {
        BMP_WIN_TransferChars(p->win[1]);
        CLACT_SetActorDrawEnable(p->actor[5], 0);
    }
}







void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key, int dir, int touch)
{
    void *s;
    int other;
    u16 anim;

    s = ZUKAN_DETAIL_COMMON_GetWorkPtr(key);
    if (p->seasonal == 0)
        p->hasAreaData = ((ZukanDetailAreaEntry *)p->areaEntries)[0].noArea == 0;
    else
        p->hasAreaData = ((ZukanDetailAreaEntry *)p->areaEntries)[p->season].noArea == 0;
    p->printPending[2] = 0;
    PRINTSYS_QUE_Clear(p->printQue[2]);
    BMP_Clear(BMP_WIN_GetBmp(p->win[2]), 0);
    ZUKAN_DETAIL_AREA_DrawAreaSetTitle(heap, p, key);
    if (dir) {
        p->arrowAnimIndex = 2;
        anim = 3;
        other = 1;
    } else {
        p->arrowAnimIndex = 1;
        anim = 5;
        other = 2;
    }
    CLACT_SetActorAnimSeq(p->actor[p->arrowAnimIndex], anim);
    CLACT_SetActorAutoAnim(p->actor[other], 0);
    CLACT_SetActorAnimFrame(p->actor[other], 0);
    ZUKAN_DETAIL_TOUCHBAR_SetSlotsEnabled((struct Ov208Scene *)s, 0);
    if (touch == 1) {
        CLACT_SetActorDrawEnable(p->actor[4], 0);
    } else if (p->uiMode == 5 && p->hasAreaData == 1) {
        ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(heap, p, key);
        ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
    }
    ZUKAN_DETAIL_AREA_BeginModeTransition(heap, p, key);
    ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
}

/*
 * Forwards to ARC_UTIL_LoadHandleMemberWithSize with the first argument less one and an out slot.
 */
void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int entryId, int heapId, void *arcHandle)
{
    int out;

    return ARC_UTIL_LoadHandleMemberWithSize(arcHandle, entryId - 1, 0, heapId, (u32 *)(&out));
}

void ZUKAN_DETAIL_AREA_FreeAreaEntryData(void *data)
{
    if (data != 0)
        GFL_HEAP_Free(data);
}

void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    void *str;
    u16 tw;
    u32 w;

    str = MSGDATA_AllocString(p->msg[0], p->season + 0xbe);
    tw = PRINTSYS_MeasureWidestLine(str, p->font, 0);
    w = BMP_GetWidth(BMP_WIN_GetBmp(p->win[2]));
    PRINTSYS_PrintQueColor((void *)p->printQue[2], BMP_WIN_GetBmp(p->win[2]), (s16)((u16)((int)(w - tw) / 2)), (s16)1, str, p->font, 0x3c40);
    STRBUF_Delete(str);
    p->printPending[2] = 1;
    ZUKAN_DETAIL_AREA_FlushPrintWindow(heap, p, key, 2);
}

/*
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to ZUKAN_DETAIL_AREA_HandleModeEvent.
 */
void ZUKAN_DETAIL_AREA_BeginModeTransition(void *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    int s = p->uiMode;

    if (s == 0) {
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 3);
        return;
    }
    if (s == 5) {
        ZUKAN_DETAIL_AREA_HandleModeEvent(heap, p, key, 8);
    }
}

void ZUKAN_DETAIL_AREA_BeginHideOverlay(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;
    if (CLACT_GetActorDrawEnable(p->actor[3])) {
        if (p->hasAreaData == 1) {
            p->printPending[3] = 0;
            PRINTSYS_QUE_Clear(p->printQue[3]);
            BMP_Clear(BMP_WIN_GetBmp(p->win[3]), 0);
            BMP_WIN_TransferChars(p->win[3]);
            CLACT_SetActorDrawEnable(p->actor[3], 0);
        }
    } else {
        for (i = 0; i < 61; i++) CLACT_SetActorDrawEnable(p->townIconActor[i], 0);
        if (p->hasAreaData == 0) {
            ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(heap, p, key, 0);
            p->selectedTown = 255;
            CLACT_SetActorDrawEnable(p->actor[4], 0);
            CLACT_SetActorDrawEnable(p->actor[5], 0);
            ZUKAN_DETAIL_AREA_DrawTownName(heap, p, key);
            ZUKAN_DETAIL_AREA_UpdateTerrainIcons(heap, p, key);
        }
    }
}

void ZUKAN_DETAIL_AREA_FinishHideOverlay(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    if (CLACT_GetActorDrawEnable(p->actor[3]) == 0) {
        if (p->hasAreaData == 0) {
            p->pendingEffect = 1;
        } else {
            p->pendingEffect = 2;
        }
    }
}

void ZUKAN_DETAIL_AREA_DrawNoDataMessage(void *heap, struct Ov208AreaWork *st, struct Ov208Ctx *key)
{
    int res = CLACT_GetActorDrawEnable(st->actor[3]);

    if (st->hasAreaData == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            struct Bmp *t;

            msg = MSGDATA_AllocString(st->msg[0], 0x80);
            w = (u16)PRINTSYS_MeasureWidestLine(msg, st->font, 0);
            h = BMP_GetWidth(BMP_WIN_GetBmp(st->win[3]));
            t = BMP_WIN_GetBmp(st->win[3]);
            d = h - w;
            PRINTSYS_PrintQueColor(st->printQue[3], t, (s16)(u16)(d / 2), 1, msg, st->font, 0x3c40);
            STRBUF_Delete(msg);
            st->printPending[3] = 1;
            ZUKAN_DETAIL_AREA_FlushPrintWindow((u16 *)heap, st, key, 3);
            CLACT_SetActorDrawEnable(st->actor[3], 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = st->seasonal == 0 ? 0 : st->season;
        for (i = 0; i < 0x3d; i++) {
            tbl = (u8 *)st->areaEntries;
            if (tbl[v * 0x3e + st->townOrder[i] + 2] != 0 && st->markers[i].state != 1) {
                CLACT_SetActorDrawEnable(st->townIconActor[i], 1);
            }
        }
        if (ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(heap, st, key) == 0) {
            ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible((u16 *)heap, st, key, 1);
        }
    }
}

void ZUKAN_DETAIL_AREA_ClearOverlayWindow(void *unused, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;
    if (CLACT_GetActorDrawEnable(p->actor[3])) {
        p->printPending[3] = 0;
        PRINTSYS_QUE_Clear(p->printQue[3]);
        BMP_Clear(BMP_WIN_GetBmp(p->win[3]), 0);
        BMP_WIN_TransferChars(p->win[3]);
        CLACT_SetActorDrawEnable(p->actor[3], 0);
    } else {
        for (i = 0; i < 61; i++) CLACT_SetActorDrawEnable(p->townIconActor[i], 0);
    }
}

void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    p->pendingEffect = 3;
}

void ZUKAN_DETAIL_AREA_NoOpOverlay(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
}

/*
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 */
void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (p->hasAreaData == 1 && p->selectedTown != 0xff) {
        idx = p->seasonal != 0 ? p->season : 0;
        k = p->townOrder[p->selectedTown];
        if ((p->areaEntries)[idx].rest[k] & 7)
            on[0] = 1;
        if ((p->areaEntries)[idx].rest[k] & 0x18)
            on[1] = 1;
        if ((p->areaEntries)[idx].rest[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        BG_SYS_FillTileMap(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    BG_SYS_MarkTileDirty(7);
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
void ZUKAN_DETAIL_AREA_ResetBlendAlpha(struct Ov208AreaWork *p)
{
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 0, 0x3f, 0xc, 4);
}

/*
 * Loads the word at +0x418 and tail-calls ZUKAN_DETAIL_COMMON_InitBrightnessTarget with it.
 */
void ZUKAN_DETAIL_AREA_ApplyBrightness(struct Ov208AreaWork *p)
{
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(p->blendMain);
}

static inline void GX_SetVisibleWnd(int window)
{
    REG32(REG_DISPCNT_ADDR) = (u32)((REG32(REG_DISPCNT_ADDR) & ~0xe000) | (window << 13));
}

static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    REG16(REG_WIN0H_ADDR) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(REG_WIN0V_ADDR) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void G2_SetWnd1Position(int x1, int y1, int x2, int y2)
{
    REG16(REG_WIN1H_ADDR) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(REG_WIN1V_ADDR) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(REG_WININ_ADDR) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(REG_WININ_ADDR) = (u16)tmp;
}

static inline void G2_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(REG_WININ_ADDR) & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    REG16(REG_WININ_ADDR) = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(REG_WINOUT_ADDR) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(REG_WINOUT_ADDR) = (u16)tmp;
}

void ZUKAN_DETAIL_AREA_SetupSplitWindows(struct Ov208AreaWork *p)
{
    GX_SetVisibleWnd(3);
    G2_SetWnd0Position(0, 0, 160, 168);
    G2_SetWnd1Position(160, 0, 0, 168);
    G2_SetWnd0InsidePlane(31, 1);
    G2_SetWnd1InsidePlane(31, 1);
    G2_SetWndOutsidePlane(31, 0);
    ZUKAN_DETAIL_AREA_InitBlendPulse(p);
}

/*
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls ZUKAN_DETAIL_COMMON_InitBrightnessTarget on the word at +0x418.
 */
void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(struct Ov208AreaWork *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(p->blendMain);
}





void ZUKAN_DETAIL_AREA_UpdateBlendPulse(struct Ov208AreaWork *p)
{
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 0, 0x3f, p->blendAlpha, 16 - p->blendAlpha);
    if (p->blendPhase + 0x400u >= 0x10000)
        p->blendPhase = p->blendPhase - 0xfc00;
    else
        p->blendPhase += 0x400;
    p->blendAlpha = ((s16)((FX_SinCosTable_[(p->blendPhase >> 4) * 2 + 1] + 0x1000) / 2) * 14 >> 12) + 1;
}

void ZUKAN_DETAIL_AREA_InitBlendPulse(struct Ov208AreaWork *p)
{
    One one = ONE;
    p->blendAlpha = one;
    p->blendPhase = one << 15;
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR, 0, 0x3f, one, 16 - one);
}

void ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            CLACT_SetActorObjMode(p->actor[i], 0);
    }
    for (i = 0; i < 0x3d; i++) {
        if (p->markers[i].state == 2)
            CLACT_SetActorObjMode(p->markers[i].obj, 0);
    }
}

void ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            CLACT_SetActorObjMode(p->actor[i], 1);
    }
    for (i = 0; i < 0x3d; i++) {
        if (p->markers[i].state == 2)
            CLACT_SetActorObjMode(p->markers[i].obj, 1);
    }
}

void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (p->iconActor[i] != 0)
            CLACT_SetActorObjMode(p->iconActor[i], 0);
    }
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 8, 0x3f, 12, 4);
}

void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, struct Ov208AreaWork *p, struct Ov208Ctx *key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (p->iconActor[i] != 0)
            CLACT_SetActorObjMode(p->iconActor[i], 1);
    }
    ZUKAN_DETAIL_COMMON_InitBrightnessTarget(p->blendSub);
}
