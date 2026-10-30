/*
 * file:     pokemontrade_2d.c
 * unit:     yes
 * function: POKETRADE_2D_GetMonMarkingIcon, POKETRADE_2D_BuildBoxMarkingTable, POKETRADE_2D_BuildPartyMarkingTable, POKETRADE_2D_BuildMarkingTablesFrom, POKETRADE_2D_InitClactSystemMain, POKETRADE_2D_InitClactSystemSub, POKETRADE_2D_LoadBackgroundGfx, POKETRADE_2D_FreeBackgroundPalette, POKETRADE_2D_LoadSubBackgroundGfx, POKETRADE_2D_NoOp, POKETRADE_2D_LoadMainGfxAndMessageWindow, POKETRADE_2D_CreateFontResource, POKETRADE_2D_FreeMainResources, POKETRADE_2D_RegisterIconCharResources, POKETRADE_2D_LoadSummaryBackground, POKETRADE_2D_ClearSummaryBackground, POKETRADE_2D_GetBoxScreenEntry, POKETRADE_2D_HitTestBoxGrid, POKETRADE_2D_DrawBoxGridScreen, POKETRADE_2D_LoadBoxScreenData, POKETRADE_2D_FreeBoxScreenData, POKETRADE_2D_CreateBoxWindows, POKETRADE_2D_DeleteBoxWindows, POKETRADE_2D_DrawBoxNames, POKETRADE_2D_CreateBoxIconActors, POKETRADE_2D_DeleteBoxIconRow, POKETRADE_2D_DeleteAllBoxIcons, POKETRADE_2D_DeleteOfferIcons, POKETRADE_2D_GetGridCellPos, POKETRADE_2D_ResolveGridCell, POKETRADE_2D_GetGridCellMon, POKETRADE_2D_PlaceBoxIconActors, POKETRADE_2D_IsBoxIconFiltered, POKETRADE_2D_IsBoxIconMatch, POKETRADE_2D_SetIconObjMode, POKETRADE_2D_UpdateIconObjMode, POKETRADE_2D_CreateBoxIcon, POKETRADE_2D_GetScrollColumn, POKETRADE_2D_GetVisibleColumnRange, POKETRADE_2D_UpdateVisibleColumns, POKETRADE_2D_UpdateBoxIconPositions, POKETRADE_2D_LoadBoxIconGfx, POKETRADE_2D_WrapIndex12, POKETRADE_2D_HideAllBoxIcons, POKETRADE_2D_HitTestBoxIcons, POKETRADE_2D_SetupSummaryBgs, POKETRADE_2D_ExitSummaryBgs, POKETRADE_2D_InitDisplayAndClact, POKETRADE_2D_SetupMainBgs, POKETRADE_2D_Setup3DRenderState, POKETRADE_2D_InitG3DSystem, POKETRADE_2D_SetupSubBgs, POKETRADE_2D_ExitSubBgs, POKETRADE_2D_SetDisplayConfig, POKETRADE_2D_RegisterMarkerResources, POKETRADE_2D_ReleaseMarkerResources, POKETRADE_2D_RegisterIconSpriteResources, POKETRADE_2D_LoadMainPalette, POKETRADE_2D_CreateTouchbarActors, POKETRADE_2D_PlaceTouchbarActors, POKETRADE_2D_DeleteTouchbarActors, POKETRADE_2D_LoadSubScreenGfx, POKETRADE_2D_ClearSubScreen, POKETRADE_2D_CreateMarkingIcon, POKETRADE_2D_DeleteMarkingIcon, POKETRADE_2D_CreatePokerusIcon, POKETRADE_2D_CreateCuredPokerusIcon, POKETRADE_2D_CreateSummaryIcons, POKETRADE_2D_DeleteSummaryIcons, POKETRADE_2D_UploadWindowPalette, POKETRADE_2D_DeleteOfferIconActor, POKETRADE_2D_SetOfferIconsVisible, POKETRADE_2D_CreateOfferIconActor, POKETRADE_2D_UpdateOfferIconHighlight, POKETRADE_2D_DeleteAllOfferIconActors, POKETRADE_2D_CreateFloatingIconActor, POKETRADE_2D_StartIconFlight, POKETRADE_2D_UpdateIconFlight, POKETRADE_2D_DeleteFloatingIconActor, POKETRADE_2D_SetupSubBlend, POKETRADE_2D_CreateMarkerActor, POKETRADE_2D_SetMarkerActorVisible, POKETRADE_2D_DeleteMarkerActor, POKETRADE_2D_SetMarkerActorAnim, POKETRADE_2D_CreateMarkerButtonActor, POKETRADE_2D_DeleteMarkerButtonPair, POKETRADE_2D_MovePickedIconActor, POKETRADE_2D_DeletePickedIconActor, POKETRADE_2D_StepCursorSlide, POKETRADE_2D_SetCursorSlidePositions, POKETRADE_2D_SetupCursorBg, POKETRADE_2D_CreateOfferWindows, POKETRADE_2D_DeleteOfferWindowActors, POKETRADE_2D_UpdateOfferWindowActors, POKETRADE_2D_LoadMonPalette, POKETRADE_2D_OnCursorAnimDone, POKETRADE_2D_CreateCursorActor, POKETRADE_2D_DeleteCursorActor, POKETRADE_2D_ClearCursorIfDisabled, POKETRADE_2D_FadePaletteBank, POKETRADE_2D_FadePaletteCopy, POKETRADE_2D_FadePaletteAll, POKETRADE_2D_ScheduleMainPlaneVisible, POKETRADE_2D_ScheduleSubPlaneVisible, POKETRADE_2D_TaskSetMainPlaneVisible, POKETRADE_2D_TaskSetSubPlaneVisible, POKETRADE_2D_InitBezierCurve, POKETRADE_2D_StepBezierCurve
 * address:  0x021E3D04
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Cut from pokemontrade_proc.c, pokemontrade_3d.c by tools/splitfile.py.
 * One step of a 20.12 fixed-point cubic Bezier: with t = idx / count the
 * four weights s^3, 3*t*s^2, 3*t^2*s, t^3 are built once, then applied to
 * the four control points p[0..3] to produce out.  When idx reaches
 * count-1 the result is p[3] and the return is 1; otherwise idx advances
 * and the return is 0.  (The struct is out, p[4], idx, count.)
 * Lever (3 bytes out): the left operand of the widening multiply in
 * FX_MUL is an rvalue (3 * t), so left inline the compiler commutes it
 * into the second _ll_mul slot and computes it in the low registers;
 * binding 3*t / 3*t2 to a named local first pins it to the accumulator
 * register, which is the only difference from the original.  This is the
 * arithmetic instance of
 * docs/idioms/commutative-operand-order-names-the-temporary.md.
 * Verified with:
 *   python tools/match.py one --src src/matched/POKETRADE_2D_StepBezierCurve.c \
 *       --func POKETRADE_2D_StepBezierCurve --addr 0x021E729C --cc dsi/1.1p1 \
 *       --thumb --region ov119 --flags=-O4,p
 *
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BOX_SAVEDATA_GetPokemon  0x02007A18  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   UI_GetInputMode 0x020355C4 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   POKE_TOOL_GetIconCellArcIdSub 0x0201BC78 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BMP_Clear 0x02043B5C arm
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   gClactConfigMain     0x021E7CE4  data  ov119
 *   gClactInitData     0x021E7D40  data  ov119
 *   gClactConfigSub     0x021E7CC8  data  ov119  a4
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   gSummaryBgTable 0x021E7DD0 data a4
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_SetupTileScreen 0x02042FB0 arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   BOX_SAVEDATA_GetBoxName 0x0200785C thumb
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKETRADE_PROC_GetSlotMonPtr 0x021D8E24 thumb ov119
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   gBoxIconFilter 0x021E82A4 data
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   gBoxIconAllocTag 0x021E8530 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   gSummaryBgTemplate6 0x021E7E24 data a4
 *   gSummaryBgTemplate7 0x021E7F44 data a4
 *   BG_SYS_FreeTiles 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 *   CLACT_SetActorObjMode  0x0204B688  arm  arm9
 *   POKETRADE_NEGO_IsMonOwnOffer 0x021DF614 thumb ov119
 *   POKETRADE_NEGO_IsMonPeerSelected 0x021DF6B4 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferStatusIcons 0x021E1CA8 thumb ov119
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   gMainBgTemplateC 0x021E7F24 data a4
 *   gMainBgTemplateB 0x021E7E84 data a4
 *   gMainBgTemplateA 0x021E7EA4 data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   gRenderLightTable 0x021E7D00 data a4
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   gCameraTargetC 0x021E7DE0 data a4
 *   gCameraTargetB 0x021E7CA0 data a4
 *   gCameraParams 0x020A1EB8 data a4
 *   gCameraTargetA 0x021E7C94 data a4
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   gSubBgTemplate4 0x021E7EE4 data a4
 *   gSubBgTemplate5 0x021E7F04 data a4
 *   gSubBgTemplate7 0x021E7F64 data a4
 *   gSubBgTemplate6 0x021E7E04 data a4
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   gDisplayConfig 0x021E7D20 data a4
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   gSubScreenWindowPos 0x021E81D4 data a4
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   APP_ICON_GetItemCellFileId 0x02027694 thumb
 *   APP_ICON_GetItemPaletteFileId 0x02027698 thumb
 *   APP_ICON_GetItemAnimFileId 0x0202769C thumb
 *   APP_ICON_GetItemFrameFileId 0x020276A0 thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   APP_ICON_GetSealCellFileId 0x020276B4 thumb
 *   APP_ICON_GetSealPaletteFileId 0x020276B8 thumb
 *   APP_ICON_GetSealAnimFileId 0x020276BC thumb
 *   APP_ICON_GetSealFrameFileId 0x020276C0 thumb
 *   APP_ICON_GetBallOpenAnimFileId 0x02027748 thumb
 *   APP_ICON_GetEffectCellFileId 0x0202774C thumb
 *   APP_ICON_GetEffectPaletteFileId 0x02027750 thumb
 *   APP_ICON_GetEffectAnimFileId 0x02027754 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_IsShiny 0x02017EAC thumb
 *   POKERUS_IsCured 0x0201B280 thumb
 *   gSummaryIconCoords 0x021E7EC4 data a4
 *   gSummaryIconStates 0x021E7F84 data a4
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   gOfferIconPosA 0x021E7D70 data a4
 *   gOfferIconPosB 0x021E7DA0 data a4
 *   FX_Sqrt 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   gPickedIconPath 0x021E7DEC data a2
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   gCursorBgTemplate 0x021E7E44 data a4
 *   POKERUS_IsInfected  0x0201B25C  thumb  arm9
 *   BMP_Create 0x02043678 arm
 *   gOfferWindowPos 0x021E7E64 data a2
 *   BMP_Delete 0x020437AC arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   DC_FlushRange 0x020862F0 arm
 *   GXS_LoadOBJ 0x0207E804 arm
 *   gOfferWindowActorTable 0x021E7DD8 data a1
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   GFL_USE_GetMainTaskList  0x020056BC  thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   FX_Div   0x0207C768  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   FILE_UTIL_IsMailItem  0x0202136C  thumb  arm9
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb  arm9
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb  arm9
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb  arm9
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb  arm9
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb  arm9
 *   POKE_TOOL_CastToBoxParam  0x020185F0  thumb  arm9
 *   TCB_AddTask  0x02030DA8  arm  arm9
 */
#include "pokemontrade_types.h"
#include "../sdk_ioreg.h"

#define FX32_ONE 4096
#define FX_MUL(v1, v2) ((fx32)(((fx64)(v1) * (v2) + 0x800LL) >> 12))
#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))
struct Struct36;
struct DispVram;
struct Light;
struct DispConfig;
struct ClactVec2;
struct PokemontradeCfg;
struct PokemontradeDescriptor;
struct MsgBank;
struct ClactVec2;
struct BezierCurve;
struct Bmp;
struct Bmp;
struct Cmd;
struct Chan02021FD8;
struct Node;
#include "../types.h"

typedef struct { unsigned int w[2]; } Tbl2;

typedef struct {
    char pad00[0x24];
    u16 v[0x300];       /* 0x024 */
} Pokemontrade2dBuf;


typedef struct { u16 id; u8 b2, b3; } Pokemontrade2dEnt;

typedef struct { short x, y; } PointS16;

typedef struct { int a, b, c, d[6]; } Pokemontrade2dInfo;

typedef struct Pokemontrade2dObject {u8 pad[0xac0];void *actors[12][5];} Pokemontrade2dObject;

#include "../arm9/bg_sys.h"



typedef struct { u16 x, y; } PointU16;

typedef struct { u32 x, y; } PointU32;

/* Actor graphics descriptor passed to UI_SCENE_LoadActorGfx. */
#include "../ov067/ui_scene_types.h"

typedef struct { int v[8]; } Pokemontrade2dCoords;

typedef struct { int v[8][2]; } States;


typedef struct { PointS16 pos[6]; } PointTable6;

typedef struct { PointS16 pos[8]; } PointTable8;

typedef struct { u8 v[8]; } ByteTable8;

typedef struct { u32 f0, f4, size; u16 data[1]; } Pal;

#include "../arm9/clact.h"
struct GameData;
struct BoxPokemon;
#include "../arm9/box_savedata.h"
#include "../arm9/poke_tool.h"
#include "../arm9/ui.h"
#include "../arm9/arc_tool.h"
#include "../arm9/poke_tool_ext.h"
struct BmpWin;
#include "../arm9/bmp_win.h"
#include "../arm9/arc_util.h"
struct Strbuf;
#include "../arm9/msgdata.h"
#include "../arm9/gfl_heap_wrap.h"
#include "pokemontrade_proc.h"
#include "../arm9/mi_memory.h"
#include "../arm9/bmp_menuwork.h"
struct Party;
#include "../arm9/pokeparty.h"
struct PokemonParam;
#include "../arm9/app_icon.h"
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/gf_font.h"
struct GfFont;
#include "../arm9/printsys.h"
struct PersonalData;
#include "../arm9/poke_personal.h"
struct DispVramCfg;
struct ClactSysInit;
struct ImageProxy;
#include "../arm9/nns_gfd_vram_transfer.h"
#include "pokemontrade_nego.h"
#include "pokemontrade_save.h"
#include "../arm9/g3x.h"
#ifdef __MWERKS__
#define G3D_SYSTEM_Init G3D_SYSTEM_InitArm9Proto
#endif
#include "../arm9/g3d_system.h"
#ifdef __MWERKS__
#undef G3D_SYSTEM_Init
/* The original callers declared heapId as u16; the definition takes s16. */
extern void G3D_SYSTEM_Init(int, int, int, int, u16, u16, void (*)(void));
#endif
#include "../arm9/g3d_camera.h"
struct G3dCamera;
#include "../arm9/file_util.h"
#include "../ov067/ui_scene.h"
#include "../arm9/pokerus.h"
#include "../arm9/fx_cp.h"
#include "../arm9/g2.h"
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/palanm.h"
struct TcbList;
#include "../arm9/gfl_use.h"
struct TcbSystem;
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../version.h"
/* Byte offset of a TradeWork member: the loops below step by row and column from the work base. */
void POKETRADE_2D_BuildBoxMarkingTable(TradeWork *p, int box, unsigned char *out);
void POKETRADE_2D_BuildPartyMarkingTable(TradeWork *p, void *party, unsigned char *out);
int POKETRADE_2D_BuildMarkingTablesFrom(TradeWork *p, int i);
void POKETRADE_2D_InitClactSystemMain(TradeWork *p);
void POKETRADE_2D_InitClactSystemSub(TradeWork *p);
void POKETRADE_2D_LoadBackgroundGfx(TradeWork *p);
void POKETRADE_2D_FreeBackgroundPalette(TradeWork *p);
void POKETRADE_2D_LoadSubBackgroundGfx(TradeWork *p);
void POKETRADE_2D_NoOp(void *p);
void POKETRADE_2D_LoadMainGfxAndMessageWindow(TradeWork *p);
void POKETRADE_2D_CreateFontResource(TradeWork *p);
void POKETRADE_2D_FreeMainResources(TradeWork *p);
void POKETRADE_2D_RegisterIconCharResources(TradeWork *p);
void POKETRADE_2D_LoadSummaryBackground(TradeWork *p, int shiftScroll, int bgIndex);
void POKETRADE_2D_ClearSummaryBackground(TradeWork *p);
unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, TradeWork *p, int mode);
int POKETRADE_2D_HitTestBoxGrid(TradeWork *p, int x, int y);
void POKETRADE_2D_DrawBoxGridScreen(TradeWork *p);
void POKETRADE_2D_LoadBoxScreenData(TradeWork *p, int d);
void POKETRADE_2D_FreeBoxScreenData(TradeWork *p);
void POKETRADE_2D_CreateBoxWindows(TradeWork *p);
void POKETRADE_2D_DeleteBoxWindows(TradeWork *p);
void POKETRADE_2D_DrawBoxNames(TradeWork *p);
void POKETRADE_2D_CreateBoxIconActors(TradeWork *p);
void POKETRADE_2D_DeleteBoxIconRow(TradeWork *p, int n);
void POKETRADE_2D_DeleteAllBoxIcons(TradeWork *p);
void POKETRADE_2D_DeleteOfferIcons(TradeWork *p);
void POKETRADE_2D_GetGridCellPos(int x, int y, unsigned short *out);
void *POKETRADE_2D_ResolveGridCell(struct GameData *v, int a, int b, TradeWork *p, int *out);
char *POKETRADE_2D_GetGridCellMon(int a, int b, TradeWork *p);
void POKETRADE_2D_PlaceBoxIconActors(TradeWork *p);
int POKETRADE_2D_IsBoxIconFiltered(TradeWork *p, int i);
int POKETRADE_2D_IsBoxIconMatch(int i, int x);
void POKETRADE_2D_SetIconObjMode(void *unused, struct ClactActor *actor, int enable);
void POKETRADE_2D_UpdateIconObjMode(TradeWork *p, int gridSlot, int column, void *mon, int cellKind, int row);
void POKETRADE_2D_CreateBoxIcon(TradeWork *p, struct GameData *v, int a, int row, int flag);
int POKETRADE_2D_GetScrollColumn(TradeWork *p);
int POKETRADE_2D_GetVisibleColumnRange(TradeWork *p, int *out);
void POKETRADE_2D_UpdateVisibleColumns(struct GameData *a, TradeWork *p, int b);
void POKETRADE_2D_UpdateBoxIconPositions(TradeWork *p);
void POKETRADE_2D_LoadBoxIconGfx(TradeWork *p, int b);
s32 POKETRADE_2D_WrapIndex12(s32 x);
void POKETRADE_2D_HideAllBoxIcons(TradeWork *p);
struct ClactActor *POKETRADE_2D_HitTestBoxIcons(TradeWork *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void POKETRADE_2D_SetupSummaryBgs(TradeWork *p,int mode);
void POKETRADE_2D_ExitSummaryBgs(TradeWork *p);
void POKETRADE_2D_InitDisplayAndClact(TradeWork *p);
void POKETRADE_2D_SetupMainBgs(void *unused);
void POKETRADE_2D_Setup3DRenderState(void);
void POKETRADE_2D_InitG3DSystem(TradeWork *p);
void POKETRADE_2D_SetupSubBgs(TradeWork *p);
void POKETRADE_2D_ExitSubBgs(TradeWork *p);
void POKETRADE_2D_SetDisplayConfig(int i);
void POKETRADE_2D_RegisterMarkerResources(TradeWork *p);
void POKETRADE_2D_ReleaseMarkerResources(TradeWork *p);
void POKETRADE_2D_RegisterIconSpriteResources(TradeWork *p);
void POKETRADE_2D_LoadMainPalette(TradeWork *p);
void POKETRADE_2D_CreateTouchbarActors(TradeWork *p);
void POKETRADE_2D_PlaceTouchbarActors(TradeWork *p, int b, int c);
void POKETRADE_2D_DeleteTouchbarActors(void *a);
void POKETRADE_2D_LoadSubScreenGfx(TradeWork *p);
void POKETRADE_2D_ClearSubScreen(TradeWork *p);
void POKETRADE_2D_CreateMarkingIcon(TradeWork *p, int side, void *mon);
void POKETRADE_2D_DeleteMarkingIcon(TradeIconSlot *p);
void POKETRADE_2D_CreatePokerusIcon(TradeWork *p, int side, int flag, void *mon);
void POKETRADE_2D_CreateCuredPokerusIcon(TradeWork *p, int b, void *c);
void POKETRADE_2D_CreateSummaryIcons(TradeWork *p,void *mon,int flag);
void POKETRADE_2D_DeleteSummaryIcons(TradeWork *p);
void POKETRADE_2D_UploadWindowPalette(TradeWork *p, int n, u32 x);
void POKETRADE_2D_DeleteOfferIconActor(TradeWork *p, int a, int b);
void POKETRADE_2D_SetOfferIconsVisible(TradeWork *p, int a, int v);
void POKETRADE_2D_CreateOfferIconActor(TradeWork *p,int i,int j,void *mon,int selected,u32 visible);
void POKETRADE_2D_UpdateOfferIconHighlight(TradeWork *p, int a, int b);
void POKETRADE_2D_DeleteAllOfferIconActors(TradeWork *p);
void POKETRADE_2D_CreateFloatingIconActor(TradeWork *p, int i, int j, int x, int y, void *q);
void POKETRADE_2D_StartIconFlight(TradeWork *p);
int POKETRADE_2D_UpdateIconFlight(TradeWork *p);
void POKETRADE_2D_DeleteFloatingIconActor(TradeWork *p);
void POKETRADE_2D_SetupSubBlend(void *p);
void POKETRADE_2D_CreateMarkerActor(TradeWork *p, int i);
void POKETRADE_2D_SetMarkerActorVisible(TradeWork *p, int i, int a);
void POKETRADE_2D_DeleteMarkerActor(TradeWork *p, int i);
void POKETRADE_2D_SetMarkerActorAnim(TradeWork *p, int i);
void POKETRADE_2D_CreateMarkerButtonActor(TradeWork *p, int z, int i);
void POKETRADE_2D_DeleteMarkerButtonPair(TradeWork *p, int n);
void POKETRADE_2D_MovePickedIconActor(TradeWork *p, int i);
void POKETRADE_2D_DeletePickedIconActor(TradeWork *p);
int POKETRADE_2D_StepCursorSlide(TradeWork *p);
void POKETRADE_2D_SetCursorSlidePositions(TradeWork *p);
void POKETRADE_2D_SetupCursorBg(TradeWork *p);
void POKETRADE_2D_CreateOfferWindows(TradeWork *p);
void POKETRADE_2D_DeleteOfferWindowActors(TradeWork *p);
void POKETRADE_2D_UpdateOfferWindowActors(TradeWork *p);
void POKETRADE_2D_LoadMonPalette(TradeWork *p, int side, void *mon);
void POKETRADE_2D_OnCursorAnimDone(void *param, u32 frame);
void POKETRADE_2D_CreateCursorActor(TradeWork *p, int x, int y);
void POKETRADE_2D_DeleteCursorActor(TradeWork *p);
int POKETRADE_2D_ClearCursorIfDisabled(TradeWork *p);
void POKETRADE_2D_FadePaletteBank(TradeWork *p, int bank, int mask);
void POKETRADE_2D_FadePaletteCopy(TradeWork *p, int capture, int bank, int mask);
void POKETRADE_2D_FadePaletteAll(TradeWork *p, int a);
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetMainPlaneVisible(struct TcbTask *p, void *a);
void POKETRADE_2D_TaskSetSubPlaneVisible(struct TcbTask *p, void *a);
void POKETRADE_2D_InitBezierCurve(struct BezierCurve *d, VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *dd, int e);
int POKETRADE_2D_StepBezierCurve(struct BezierCurve *c);
extern const char gClactConfigMain[];
extern const char gClactInitData[];
extern int gClactConfigSub;
extern const Tbl2 gSummaryBgTable;
extern const unsigned char gBoxIconFilter[];
extern char gBoxIconAllocTag[];
extern const struct BgTemplate gSummaryBgTemplate6,gSummaryBgTemplate7;
extern const struct BgTemplate gMainBgTemplateC,gMainBgTemplateB,gMainBgTemplateA;
extern char gRenderLightTable[];
extern VecFx32 gCameraTargetC, gCameraTargetB, gCameraTargetA;
extern const s16 gCameraParams[];
extern const struct BgTemplate gSubBgTemplate4,gSubBgTemplate5,gSubBgTemplate7,gSubBgTemplate6;
extern const char gDisplayConfig[];
extern PointU32 gSubScreenWindowPos[PM_LANG_JA(26, 44)];
extern const Pokemontrade2dCoords gSummaryIconCoords;
extern const States gSummaryIconStates;
extern const int gOfferIconPosA[6][2];
extern const int gOfferIconPosB[6][2];
extern const PointTable6 gPickedIconPath;
extern const struct BgTemplate gCursorBgTemplate;
extern const PointTable8 gOfferWindowPos;
extern const ByteTable8 gOfferWindowActorTable;

unsigned char POKETRADE_2D_GetMonMarkingIcon(void *mon, unsigned int heap)
{
    int old;
    unsigned short result;
    int species;
    void *data;
    result = 0;
    old = POKE_TOOL_DecodeBoxParam(mon);
    species = POKE_TOOL_GetBoxValue(mon, 5, 0);
    if (POKE_TOOL_GetBoxValue(mon, 0xA9, 0)) {
        if (!POKE_TOOL_GetBoxValue(mon, 0x4C, 0)) {
            unsigned short form = POKE_TOOL_GetBoxValue(mon, 0x6F, 0);
            data = POKE_PERSONAL_Create((unsigned short)species, form, heap);
            result = POKE_PERSONAL_GetParam(data, 0x21);
            POKE_PERSONAL_Delete(data);
        } else {
            result = 1;
            if (species != 0x1EA)
                result = 8;
        }
        result++;
    }
    POKE_TOOL_EncodeBoxParam(mon, old);
    return result;
}

void POKETRADE_2D_BuildBoxMarkingTable(TradeWork *p, int box, unsigned char *out)
{
    unsigned char i;

    for (i = 0; i < 30; i++)
        out[i] = POKETRADE_2D_GetMonMarkingIcon(BOX_SAVEDATA_GetPokemon((*(void * *)&p->boxManager), box, i), p->heapId);
}

void POKETRADE_2D_BuildPartyMarkingTable(TradeWork *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = POKETRADE_2D_GetMonMarkingIcon(POKE_TOOL_CastToBoxParam(POKEPARTY_GetMember(party, i)), p->heapId);
        else
            out[i] = 0;
    }
}

int POKETRADE_2D_BuildMarkingTablesFrom(TradeWork *p, int i)
{
    while (i < p->partyBoxId + 1) {
        if (i == p->partyBoxId) {
            POKETRADE_2D_BuildPartyMarkingTable(p, p->partyData, p->partyMarking);
            return 1;
        }
        POKETRADE_2D_BuildBoxMarkingTable(p, i, p->boxMarking[i]);
        break;
    }
    return 0;
}

/*
 * Unlabelled Thumb tail-call wrapper after pool_021E3E3C, seeded so that
 * ov117 POKETRADE_IRCDEMO_StepSetup has a witness: forwards the two ov119 tables and the
 * u16 heap id held at +0x5F4 to the ARM function 0x0204A48C.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_InitClactSystemMain(TradeWork *p)
{
    CLACT_InitSystem((struct ClactSysInit *)gClactConfigMain, (struct DispVramCfg *)gClactInitData, p->heapId);
}

/*
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of POKETRADE_SAVE_ResetClactAndBeginEvent's preamble.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_InitClactSystemSub(TradeWork *p)
{
    CLACT_InitSystem((struct ClactSysInit *)(&gClactConfigSub), (struct DispVramCfg *)(&gClactInitData), p->heapId);
}

void POKETRADE_2D_LoadBackgroundGfx(TradeWork *p)
{
    void *v;
    int kind;
    int mode;
    v = ARC_TOOL_CreateHandle(0x66, p->heapId);
    mode = POKETRADE_PROC_IsHostSide(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    ARC_UTIL_UploadPaletteFromHandleWhole(v, 9, 0, 0, 0, p->heapId);
    if (p->subBgHandle == 0)
        p->subBgHandle = ARC_UTIL_RegisterObjCharFromHandle(v, 10, 2, 0, 0, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, kind, (int)2, (int)0, (unsigned short)((p->subBgHandle)), (int)0, (int)0, (unsigned int)(p->heapId));
    ARC_TOOL_DeleteHandle(v);
}

void POKETRADE_2D_FreeBackgroundPalette(TradeWork *p)
{
    u32 v;

    v = (p->subBgHandle);
    if (v != 0)
        BG_SYS_FreeTileRun((int)2, (u16)v, (u16)(v >> 16));
    (p->subBgHandle) = 0;
}

void POKETRADE_2D_LoadSubBackgroundGfx(TradeWork *p)
{
    void *v;
    v = ARC_TOOL_CreateHandle(0x66, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, 12, (int)4, (int)0, (unsigned short)(p->mainBgHandle), (int)0, (int)0, (unsigned int)(p->heapId));
    ARC_TOOL_DeleteHandle(v);
}

/*
 * Empty stub.
 */
void POKETRADE_2D_NoOp(void *p)
{
}

void POKETRADE_2D_LoadMainGfxAndMessageWindow(TradeWork *p)
{
    void *v;

    v = ARC_TOOL_CreateHandle(0x66, p->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(v, 0x11, 4, 0, 0xC0, p->heapId);
    (p->boxBgHandle) = ARC_UTIL_RegisterObjCharFromHandle(v, 0xD, 7, 0, 0, p->heapId);
    (p->mainBgHandle) = ARC_UTIL_RegisterObjCharFromHandle(v, 0xD, 5, 0, 0, p->heapId);
    ARC_TOOL_DeleteHandle(v);
    POKETRADE_2D_LoadBoxScreenData(p, ((p->boxBgHandle)));
}

void POKETRADE_2D_CreateFontResource(TradeWork *p)
{
    p->fontBgHandle = BMP_MENUWORK_LoadFrameGfx(6, 15, 0, p->heapId);
}

void POKETRADE_2D_FreeMainResources(TradeWork *p)
{
    POKETRADE_2D_FreeBoxScreenData(p);
    if (p->mainBgHandle) {
        BG_SYS_FreeTileRun((int)5, (unsigned short)(p->mainBgHandle), (unsigned short)(p->mainBgHandle >> 16));
        p->mainBgHandle = 0;
    }
    if (p->boxBgHandle) {
        BG_SYS_FreeTileRun((int)7, (unsigned short)(p->boxBgHandle), (unsigned short)(p->boxBgHandle >> 16));
        p->boxBgHandle = 0;
    }
    if (p->fontBgHandle) {
        BG_SYS_FreeTileRun((int)6, (unsigned short)(p->fontBgHandle), (unsigned short)(p->fontBgHandle >> 16));
        p->fontBgHandle = 0;
    }
}

void POKETRADE_2D_RegisterIconCharResources(TradeWork *p)
{
    void *v;
    int a;
    if (p->iconPaletteEx == 0) {
        v = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), p->heapId);
        p->charD = CLACT_RegisterCharacter(v, APP_ICON_GetMoveKindAnimFileId(), 0, 1, p->heapId);
        p->iconPaletteEx = CLACT_RegisterPaletteEx(v, APP_ICON_GetMoveKindPaletteFileId(), 1, 0, 0, 3, p->heapId);
        a = APP_ICON_GetStatusCellFileId(2);
        p->cellAnimE = CLACT_RegisterCellAnim(v, a, APP_ICON_GetStatusPaletteFileId(2), p->heapId);
        ARC_TOOL_DeleteHandle(v);
    }
}

void POKETRADE_2D_LoadSummaryBackground(TradeWork *p, int shiftScroll, int bgIndex)
{
    Tbl2 tbl = gSummaryBgTable;
    void *v;
    v = ARC_TOOL_CreateHandle(0x66, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, tbl.w[bgIndex], 4, 0, (unsigned short)p->mainBgHandle, 0, 0, p->heapId);
    if (shiftScroll != 0) {
        BG_SYS_ChangeScrollImmediate(4, 0, 0x80);
    } else {
        BG_SYS_ChangeScrollImmediate(4, 0, 0);
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 0);
    ARC_TOOL_DeleteHandle(v);
    BG_SYS_SetPlaneVisible(4, 1);
}

void POKETRADE_2D_ClearSummaryBackground(TradeWork *p)
{
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_ChangeScrollImmediate(4, 0, 0);
    POKETRADE_2D_SetupSubBlend(p);
    BG_SYS_ClearSlot(4);
    BG_SYS_MarkTileDirty(4);
}

unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, TradeWork *p, int mode)
{
    if (i >= p->columnWrap)
        i -= p->columnWrap;
    if (i < 12) {
        if (mode)
            return ((unsigned short *)p->tilemap1A)[i + (row * 32 + 18)];
        else
            return ((unsigned short *)p->tilemapF)[i + (row * 32 + 18)];
    } else {
        i = (i - 12) % 20;
        if (mode)
            return ((unsigned short *)p->tilemap19)[i + (row * 32 + 18)];
        else
            return ((unsigned short *)p->tilemapE)[i + (row * 32 + 18)];
    }
}

/*
 * lever: initialize the inner counter before calculating the two outer cursors.
 */
int POKETRADE_2D_HitTestBoxGrid(TradeWork *p, int x, int y)
{
    int i, j, a, b;
    for (i = 0; i < 12; i++) {
        j = 0;
        for (; j < 5; j++) {
            if (p->boxIconShown[i][j]) {
                a = p->boxIconPos[i][j].x - 5;
                b = p->boxIconPos[i][j].y - 8;
                if (a < 0) a -= 8;
                a /= 8;
                b /= 8;
                if (a <= x && a + 3 > x && b <= y && b + 3 > y) return 1;
            }
        }
    }
    return 0;
}

void POKETRADE_2D_DrawBoxGridScreen(TradeWork *p)
{
    int x, y, n, mode;
    n = p->scrollX / 8;
    POKETRADE_2D_GetScrollColumn(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = POKETRADE_2D_HitTestBoxGrid(p, x, y);
            BG_SYS_SetupTileScreen(7, x, y, POKETRADE_2D_GetBoxScreenEntry(n + x, y, p, mode));
        }
    }
    p->scrollSub = p->scrollX % 8;
    p->redrawNeeded = 1;
    BG_SYS_MarkTileDirty(7);
}

/*
 * 2026-10-03 (wB3 lane07): EXACT. The doubled zero-extension of the loop-invariant
 * comes from an int parameter stored in a u16 local and then added as (int)e.
 */
void POKETRADE_2D_LoadBoxScreenData(TradeWork *p, int d)
{
    int i;
    u16 e;

    *(Pokemontrade2dBuf * *)&p->tilemapE = ARC_TOOL_LoadMember(0x66, 0xE, p->heapId);
    *(Pokemontrade2dBuf * *)&p->tilemapF = ARC_TOOL_LoadMember(0x66, 0xF, p->heapId);
    *(Pokemontrade2dBuf * *)&p->tilemap19 = ARC_TOOL_LoadMember(0x66, 0x19, p->heapId);
    *(Pokemontrade2dBuf * *)&p->tilemap1A = ARC_TOOL_LoadMember(0x66, 0x1A, p->heapId);
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Pokemontrade2dBuf * *)&p->tilemapE)->v[i] += (int)e;
        ((Pokemontrade2dBuf *)p->tilemapF)->v[i] += (int)e;
        ((Pokemontrade2dBuf *)p->tilemap19)->v[i] += (int)e;
        ((Pokemontrade2dBuf *)p->tilemap1A)->v[i] += (int)e;
    }
    (*(unsigned short *)&p->scrollX) = (p->gridOriginX) - 0x50;
    POKETRADE_2D_DrawBoxGridScreen(p);
}

void POKETRADE_2D_FreeBoxScreenData(TradeWork *p)
{
    if (p->tilemapE) {
        GFL_HEAP_Free(p->tilemapE);
        p->tilemapE = 0;
        GFL_HEAP_Free(p->tilemapF);
        p->tilemapF = 0;
        GFL_HEAP_Free(p->tilemap19);
        p->tilemap19 = 0;
        GFL_HEAP_Free(p->tilemap1A);
        p->tilemap1A = 0;
    }
}

/*
 * arithmetic: count additions wrap unsigned then compare signed results; indexed address uses typed word-pointer addition under valid-object preconditions; the guarded int counter never increments above INT_MAX.
 * note 2026-10-05 (wave D9r lane 131): removed the 11 dead first assignments
 * (`off1 = 0x5F4;` before `off1 = 0x6B8;`; `off3 = 0x828;` before `off3 =
 * 0x730;` and 9 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void POKETRADE_2D_CreateBoxWindows(TradeWork *p)
{
    int i, zero;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,p->heapId);
    i = 0;
    if (i >= (int)((u32)p->partyBoxId+1u)) goto done;
        zero = 0;
        do {
            if (p->boxNameWin[i] == 0)
                p->boxNameWin[i] = BMP_WIN_Create(5,0,0,15,2,14,0);
            if (i == p->partyBoxId)
                MSGDATA_ReadString((*(void * *)&p->messageBank),16,p->infoTextOut);
            else BOX_SAVEDATA_GetBoxName((*(void * *)&p->boxManager),i,p->infoTextOut);
            GF_FONT_SetTextColor(15,2,zero);
            BMP_Clear(BMP_WIN_GetBmp(p->boxNameWin[i]),zero);
            PRINTSYS_Print(BMP_WIN_GetBmp(p->boxNameWin[i]),zero,PM_LANG_JA(1, zero),p->infoTextOut,p->font);
            BMP_WIN_TransferChars(p->boxNameWin[i]);
            BMP_WIN_SetPosY(p->boxNameWin[i],zero);
        } while (++i < (int)((u32)p->partyBoxId+1u));
done:;
}

void POKETRADE_2D_DeleteBoxWindows(TradeWork *p)
{
    int i;
    for (i = 0; i < 25; i++) {
        if (p->boxNameWin[i]) {
            BMP_WIN_Delete(p->boxNameWin[i]);
            p->boxNameWin[i] = 0;
        }
    }
}

/*
 * arithmetic: full-word index and scroll ADD/SUB/MUL use modulo-2^32 arithmetic; casts restore the original signed comparisons.
 * note 2026-10-05 (wave D9r lane 131): removed the 3 dead first assignments
 * (`off1 = 0x638;` before `off1 = 0x6B8;`; `off2 = 0x638;` before `off2 =
 * 0x6B8;` and 1 more). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void POKETRADE_2D_DrawBoxNames(TradeWork *p)
{
    int x, y, scroll, first, i, n, pos, idx;
    scroll = p->scrollX / 8;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            BG_SYS_SetupTileScreen(5, x, y, 0);
        }
    }
    if (p->scrollX < 96) first = p->partyBoxId;
    else first = (p->scrollX - 96) / 160;
    i = 0;
    for (; i < 3; i++) {
        idx = (int)((u32)first+(u32)i);
        n = p->partyBoxId;
        if (idx > n) idx = (int)((u32)idx-(u32)n-1u);
        else if (idx < 0) idx = (int)((u32)idx+(u32)n+1u);
        if (idx == n) {
            pos = (int)((p->columnWrap)-(u32)scroll);
            if (scroll > pos) scroll = (int)((u32)scroll-(p->columnWrap));
            else pos = (int)(0u-(u32)scroll);
        } else pos = (int)((u32)idx*20u+12u-(u32)scroll);
        if (pos >= -10 && pos <= 33) {
            BMP_WIN_SetPosX(p->boxNameWin[idx], pos + 1);
            BMP_WIN_MakeScreen(p->boxNameWin[idx]);
        }
    }
    BG_SYS_MarkTileDirty(5);
}

void POKETRADE_2D_CreateBoxIconActors(TradeWork *p)
{
    int i, j, z;
    void *arc;
    struct ActorInitParam t;
    arc = ARC_TOOL_CreateHandle(7, p->heapId);
    p->iconPalette = CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0x60, p->heapId);
    p->cellAnimC = CLACT_RegisterCellAnim(arc, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryId(), p->heapId);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.anim_seq = 1;
            t.draw_priority = 0x10;
            t.bg_priority = 3;
            p->iconChar[i][j] = CLACT_RegisterCharacter(arc, 0x51b, z, 1, p->heapId);
            p->boxIconActors[i][j] = CLACT_CreateActor((*(void * *)&p->clactSystem), p->iconChar[i][j],
                p->iconPalette, p->cellAnimC, &t, 1, p->heapId);
            t.anim_seq = z;
            t.draw_priority = 0xf;
            p->boxIconAlt[i][j] = CLACT_CreateActor((*(void * *)&p->clactSystem), p->actorChar,
                p->actorPalette, p->actorCellAnim, &t, 1, p->heapId);
            CLACT_SetActorAutoAnim(p->boxIconActors[i][j], z);
            CLACT_SetActorDrawEnable(p->boxIconActors[i][j], z);
            CLACT_SetActorDrawEnable(p->boxIconAlt[i][j], z);
            CLACT_SetActorAutoAnim(p->boxIconAlt[i][j], 1);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * follower: two zero padding bytes at 0x021E4886 before labelled 021E4888.
 */
void POKETRADE_2D_DeleteBoxIconRow(TradeWork *p, int n)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (p->boxIconActors[n][i]) {
            CLACT_DeleteActor((struct ClactActor *)(p->boxIconActors[n][i]));
            p->boxIconActors[n][i] = 0;
        }
        if (p->boxIconAlt[n][i]) {
            CLACT_DeleteActor((struct ClactActor *)(p->boxIconAlt[n][i]));
            p->boxIconAlt[n][i] = 0;
        }
        if (p->iconChar[n][i]) {
            CLACT_ReleaseCharacter(p->iconChar[n][i]);
            p->iconChar[n][i] = 0;
        }
    }
}

void POKETRADE_2D_DeleteAllBoxIcons(TradeWork *p)
{
    int i;
    POKETRADE_2D_DeletePickedIconActor(p);
    for (i = 0; i < 12; i++) POKETRADE_2D_DeleteBoxIconRow(p, i);
    if ((p->iconPalette)) {
        CLACT_ReleasePalette((p->iconPalette));
        (p->iconPalette) = 0;
    }
    if ((p->cellAnimC)) {
        CLACT_ReleaseCellAnim((p->cellAnimC));
        (p->cellAnimC) = 0;
    }
    if (p->vramBuf) GFL_HEAP_Free(p->vramBuf);
    p->vramBuf = 0;
}

void POKETRADE_2D_DeleteOfferIcons(TradeWork *p)
{
    int i;
    POKETRADE_2D_DeleteCursorActor(p);
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    for (i = 0; i < 10; i++) {
        if (p->uiActor[i]) {
            CLACT_DeleteActor((struct ClactActor *)(p->uiActor[i]));
            p->uiActor[i] = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (p->resourceHandle[i]) {
            CLACT_ReleasePalette(p->resourceHandle[i]);
            p->resourceHandle[i] = 0;
        }
    }
    for (; i < 12; i++) {
        if (p->resourceHandle[i]) {
            CLACT_ReleaseCharacter(p->resourceHandle[i]);
            p->resourceHandle[i] = 0;
        }
    }
    for (; i < 18; i++) {
        if (p->resourceHandle[i]) {
            CLACT_ReleaseCellAnim(p->resourceHandle[i]);
            p->resourceHandle[i] = 0;
        }
    }
}

void POKETRADE_2D_GetGridCellPos(int x, int y, unsigned short *out)
{
    out[0] = (x + 1) * 0x18;
    out[1] = y * 0x18 + 0x48;
}

void *POKETRADE_2D_ResolveGridCell(struct GameData *v, int a, int b, TradeWork *p, int *out)
{
    int n, m;
    if (a >= 2) {
        n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
        m = POKETRADE_PROC_GetSlotIndexInBox(a, b);
        *out = 0;
        return POKETRADE_PROC_LoadSlotMonAlt(v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return POKETRADE_PROC_LoadSlotMonAlt(v, p->partyBoxId, a + b * 2, p);
    }
    return 0;
}

char *POKETRADE_2D_GetGridCellMon(int a, int b, TradeWork *p)
{
    int n;
    if (a >= 2) {
        n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
        return POKETRADE_PROC_GetSlotMonPtr(n, POKETRADE_PROC_GetSlotIndexInBox(a, b), p);
    }
    if (b < 3)
        return POKETRADE_PROC_GetSlotMonPtr(p->partyBoxId, a + b * 2, p);
    return 0;
}

void POKETRADE_2D_PlaceBoxIconActors(TradeWork *p)
{
    short xy[2];
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 12; j++) {
            if (CLACT_GetActorDrawEnable((struct ClactActor *)(p->boxIconAlt[j][i]))) {
                CLACT_GetActorSurfacePos((struct ClactActor *)p->boxIconAlt[j][i], (struct ClactVec2 *)xy, 1);
                p->iconPosX = xy[0];
                p->iconPosY = xy[1];
            }
        }
    }
}

int POKETRADE_2D_IsBoxIconFiltered(TradeWork *p, int i)
{
    int v = p->filterIndex;
    if (v != 0 && v - 1 == gBoxIconFilter[i]) {
        return 1;
    }
    return 0;
}

int POKETRADE_2D_IsBoxIconMatch(int i, int x)
{
    if (x == gBoxIconFilter[i]) {
        return 1;
    }
    return 0;
}

/*
 * Normalise the third argument to 0 or 1 and tail call the setter.
 */
void POKETRADE_2D_SetIconObjMode(void *unused, struct ClactActor *actor, int enable)
{
    CLACT_SetActorObjMode(actor, enable != 0);
}

void POKETRADE_2D_UpdateIconObjMode(TradeWork *p, int gridSlot, int column, void *mon, int cellKind, int row)
{
    int flag = 0;
    if (POKETRADE_NEGO_IsMonOwnOffer(p, gridSlot, column)) {
        flag = 1;
    }
    POKETRADE_2D_SetIconObjMode(p, p->boxIconActors[row][column], flag);
}

void POKETRADE_2D_CreateBoxIcon(TradeWork *p, struct GameData *v, int a, int row, int flag)
{
    int j; void *rec; int id, b2, b3, idx, n;
    Pokemontrade2dEnt *e;
    Pokemontrade2dInfo info;
    int kind;
    u16 pos[2];
    PointS16 pt;
    enum { VRAM_BASE = HW_DB_OBJ_VRAM } vram;
    if (a == p->cursorSlot && UI_GetInputMode() == 0) {
        CLACT_SetActorDrawEnable(p->boxIconAlt[row][p->cursorColumn], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = POKETRADE_2D_ResolveGridCell(v, a, j, p, &kind);
        e = (Pokemontrade2dEnt *)POKETRADE_2D_GetGridCellMon(a, j, p);
        if (e == 0) {
            p->boxIconSlot[row][j] = 0xff;
            continue;
        }
        if (e->id == 0) {
            p->boxIconSlot[row][j] = 0xff;
            continue;
        }
        p->boxIconSlot[row][j] = a;
        b2 = e->b2;
        id = e->id;
        b3 = e->b3;
        if (id == p->boxIconId[row][j] && b2 == p->boxIconB2[row][j]
            && b3 == p->boxIconB3[row][j]) {
            CLACT_SetActorDrawEnable(p->boxIconActors[row][j], 1);
            POKETRADE_2D_UpdateIconObjMode(p, a, j, rec, kind, row);
        } else if (id != p->boxIconId[row][j]
            || (id == p->boxIconId[row][j] && b2 != p->boxIconB2[row][j])
            || (id == p->boxIconId[row][j] && b3 != p->boxIconB3[row][j])) {
            p->boxIconId[row][j] = id;
            p->boxIconB2[row][j] = b2;
            p->boxIconB3[row][j] = b3;
            POKETRADE_2D_GetGridCellPos(a, j, pos);
            CLACT_GetActorImageProxy((const char *)p->boxIconActors[row][j], (struct ImageProxy *)(&info));
            n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
            idx = POKETRADE_PROC_GetSlotIndexInBox(a, j);
            idx += n * 30;
            CLACT_GetActorSurfacePos((struct ClactActor *)p->boxIconActors[row][j], (struct ClactVec2 *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (NNS_GfdRegisterNewVramTransferTask(0x23, info.c, (void *)((u8 *)p->vramBuf + idx * 0x200), 0x200) == 0) {
                    vram = VRAM_BASE;
                    MI_CpuCopy8((const void *)((u8 *)p->vramBuf + idx * 0x200), (void *)(vram + info.c), 0x200);
                }
            } else {
                vram = VRAM_BASE;
                MI_CpuCopy8((const void *)((u8 *)p->vramBuf + idx * 0x200), (void *)(vram + info.c), 0x200);
            }
            POKETRADE_2D_UpdateIconObjMode(p, a, j, rec, kind, row);
            CLACT_SetActorPaletteOffset(p->boxIconActors[row][j], POKE_TOOL_GetIconPalette((void *)rec), 1);
            CLACT_SetActorAutoAnim(p->boxIconActors[row][j], 0);
            CLACT_SetActorDrawEnable(p->boxIconActors[row][j], 1);
        }
        if (POKE_TOOL_GetBoxValue((void *)rec, 0x4c, 0) == 0 && POKETRADE_2D_IsBoxIconFiltered(p, id)) {
            p->boxIconShown[row][j] = 1;
        }
    }
}

/*
 * lever: a separate adjusted-coordinate local keeps the subtraction before division.
 */
int POKETRADE_2D_GetScrollColumn(TradeWork *p)
{
    int x, q, r, v;
    x = p->scrollX;
    if (x < 48) x = 0;
    else if (x < 96) x = 1;
    else {
        v = x - 96;
        q = v / 160;
        r = v - q * 160;
        x = q * 6 + 2;
        if (r >= 8) {
            if (r >= 152) x += 5;
            else x += (r - 8) / 24;
        }
    }
    return x;
}

int POKETRADE_2D_GetVisibleColumnRange(TradeWork *p, int *out)
{
    int x, hi, n, t;
    x = POKETRADE_2D_GetScrollColumn(p);
    *out = x + 2;
    hi = x + 10;
    n = p->slotCount;
    if (*out >= n) *out -= n;
    n = p->slotCount;
    if (hi >= n) {
        t = p->cursorSlot;
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = p->cursorSlot;
        if (x <= t && t <= hi) return 1;
    }
    return 0;
}

/*
 * lever: i before n gives n the earlier spill slot.
 */
void POKETRADE_2D_UpdateVisibleColumns(struct GameData *a, TradeWork *p, int b)
{
    int i, n, j;
    n = POKETRADE_2D_GetScrollColumn(p);
    if (p->cursorRow != n) {
        p->cursorRow = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                CLACT_SetActorDrawEnable(p->boxIconAlt[i][j], 0);
                p->boxIconShown[i][j] = 0;
            }
        }
        p->drawColumn = n;
        POKETRADE_2D_HideAllBoxIcons(p);
        for (i = 0; i < 12; i++) {
            POKETRADE_2D_CreateBoxIcon(p, a, n, POKETRADE_2D_WrapIndex12(p->cursorRow + i), b);
            n++;
            if (n >= p->slotCount) n = 0;
        }
    }
    POKETRADE_2D_UpdateBoxIconPositions(p);
}

/*
 * lever:    the hoisted column sum is written inside the else arm as two statements.
 */
void POKETRADE_2D_UpdateBoxIconPositions(TradeWork *p)
{
    char *qp;
    int i, off, y, row, j, x, ty, col;
    PointS16 b, a;
    off = 0;
    y = p->cursorRow;
    for (i = 0; i < 12; i++) {
        row = POKETRADE_2D_WrapIndex12(p->cursorRow + i);
        if (y >= p->slotCount) {
            y -= p->slotCount;
            off = p->gridOriginX;
        }
        for (j = 0; j < 5; j++) {
            ty = j * 24 + 0x20;
            if (y == 0) x = 0x1c;
            else if (y == 1) x = 0x3c;
            else {
                col = (y - 2) / 6 * 160;
                col += (y - 2) % 6 * 24 + 0x14;
                x = col + 0x60;
            }
            b.x = off + (x - p->scrollX);
            b.y = ty;
            a = b;
            if (POKETRADE_NEGO_IsMonPeerSelected(p, y, j) && UI_GetInputMode() == 1) {
                b.y -= 8;
                qp = (char *)p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority(p->boxIconActors[row][j], 11);
            } else {
                qp = (char *)p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority(p->boxIconActors[row][j], 0x1c - i);
            }
            CLACT_AddActorSurfacePos(p->boxIconActors[row][j], (const struct ClactVec2 *)(&b), 1);
            if (p->boxIconShown[row][j]) {
                *(PointS16 *)&((TradeWork *)qp)->boxIconPos[0][0] = a;
            }
            b.y = ty + 3;
            CLACT_AddActorSurfacePos(p->boxIconAlt[row][j], (const struct ClactVec2 *)(&b), 1);
        }
        y++;
    }
}

/*
 * lever: initial guard is a forward goto, with the exit after the body.
 */
void POKETRADE_2D_LoadBoxIconGfx(TradeWork *p, int b)
{
    int i, n; sptr x; void *t; struct GfxLoadResult *out;
    void *a;
    if (b == 0) p->vramBuf = GFL_HEAP_Alloc(p->heapId, 0x5ac00, 0, gBoxIconAllocTag, PM_SRC_LINE(0x50b, 0x509));
    a = ARC_TOOL_CreateHandle(7, p->heapId);
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = (sptr)POKETRADE_PROC_LoadSlotMonAlt((void *)(p->boxManager), b, i, p);
            if (x) x = POKE_TOOL_GetGraphicIndex((void *)x);
            else x = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
            t = ARC_UTIL_LoadBgCharDataFromHandle((void *)a, x, 0, (&out), p->heapId);
            MI_CpuCopy8(out->data, (void *)((u8 *)p->vramBuf + n * 512), 512);
            n++;
            GFL_HEAP_Free(t);
        }
    }
    goto done;
check:
    if (b < 25) goto body;
done:
    ARC_TOOL_DeleteHandle(a);
}

/*
 * Signed remainder by 12.  The MSL divide helper returns the quotient in r0
 * and the remainder in r1, so `x % 12` moves r1 down to r0.
 */
s32 POKETRADE_2D_WrapIndex12(s32 x)
{
    return x % 12;
}

/*
 * extent: two zero padding bytes at 0x021E51A2.
 */
void POKETRADE_2D_HideAllBoxIcons(TradeWork *p)
{
    int i, j;
    for (i = 0; i < 12; i++)
        for (j = 0; j < 5; j++)
            CLACT_SetActorDrawEnable(p->boxIconActors[i][j], 0);
}

/*
 * lever: pos precedes the integer locals; a typed return-base temporary
 * keeps the row/column byte offsets spilled instead of reusing r7.
 * initialization: the only ov119 calls are D9EEC and D9F5C. D9F24
 * passes p+f80 as outA; D9EBC forwards outA from its only caller DA3BC,
 * where r1=p+f98. Thus all reachable hit paths enter the outA block
 * before reading slot through outSlot. No default value is invented.
 * 0204B454 writes both coordinate halfwords through 0204B53C and then
 * subtracts the origin, itself written through 0204CF74/0204B0C8.
 */
struct ClactActor *POKETRADE_2D_HitTestBoxIcons(TradeWork *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow)
{
 PointS16 pos;
 int column,slot,row;
 for(row=0;row<12;row++) {
  for(column=0;column<5;column++) {
   CLACT_GetActorSurfacePos(p->boxIconActors[row][column],(struct ClactVec2 *)&pos,1);
   if(pos.x<=x && x<pos.x+24 && pos.y<=y && y<pos.y+24) {
    if(outA) {
     slot=p->boxIconSlot[row][column];
     if(slot==255)return 0;
     if(POKETRADE_PROC_GetSlotIndexInBox(slot,column)!=-1) {
      *outA=POKETRADE_PROC_GetBoxIndexForSlot(slot,p);
      *outB=POKETRADE_PROC_GetSlotIndexInBox(slot,column);
     } else return 0;
    }
    if(outSlot) {*outSlot=slot;*outColumn=column;*outRow=row;}
    return p->boxIconActors[row][column];
   }
  }
 }
 return 0;
}

/*
 * interface: 02040618's legacy fourth argument is forwarded only to
 * 02042360, whose complete matched body reads r0-r2 and never r3.
 * The original calls here set only r0-r2; retain its three-input API.
 */
void POKETRADE_2D_SetupSummaryBgs(TradeWork *p,int mode)
{
 struct BgTemplate a,b;
 void *v;
 POKETRADE_2D_SetDisplayConfig(1);p->summaryActive=1;
 a=gSummaryBgTemplate6;BG_SYS_InitBgLayer(6,&a,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,24,17);BG_SYS_PushTile(6);
 b=gSummaryBgTemplate7;BG_SYS_InitBgLayer(7,&b,2);
 if(mode==0) {
  v=ARC_TOOL_CreateHandle(0x67,p->heapId);
  ARC_UTIL_UploadPaletteFromHandleWhole(v,5,6,0x6000,0,p->heapId);
  ARC_UTIL_UploadBgCharFromHandle((void *)(v),4,7,0,0,0,p->heapId);
  ARC_UTIL_UploadBgPaletteFromHandle((void *)(v),6,7,0,0,0,p->heapId);
  BG_SYS_ChangeScrollImmediate(7,0,0);ARC_TOOL_DeleteHandle(v);
 } else {
  v=ARC_TOOL_CreateHandle(0x68,p->heapId);
  ARC_UTIL_UploadPaletteFromHandleWhole(v,1,6,0x6000,0,p->heapId);
  ARC_UTIL_UploadBgCharFromHandle((void *)(v),0,7,0,0,0,p->heapId);
  ARC_UTIL_UploadBgPaletteFromHandle((void *)(v),2,7,0,0,0,p->heapId);
  BG_SYS_ChangeScrollImmediate(7,0,0);ARC_TOOL_DeleteHandle(v);
 }
}

void POKETRADE_2D_ExitSummaryBgs(TradeWork *p)
{
    if (p->summaryActive != 0) {
        BG_SYS_FreeTiles(6, 1, 0);
        BG_SYS_FreeLayerBuf(6);
        BG_SYS_FreeLayerBuf(7);
        p->summaryActive = 0;
    }
}

void POKETRADE_2D_InitDisplayAndClact(TradeWork *p)
{
    BG_SYS_SetVramBanks((const struct DispVram *)gClactInitData);
    CLACT_InitSystem((struct ClactSysInit *)(&gClactConfigSub), (struct DispVramCfg *)gClactInitData, p->heapId);
    POKETRADE_2D_SetDisplayConfig(0);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
}

void POKETRADE_2D_SetupMainBgs(void *unused)
{
 struct BgTemplate a,b,c;
 a=gMainBgTemplateC;
 BG_SYS_InitBgLayer(3,&a,0);BG_SYS_Init(3,0,1,0);
 BG_SYS_SetTileEntry(3,0,0,0,32,24,17);BG_SYS_PushTile(3);
 b=gMainBgTemplateB;
 BG_SYS_InitBgLayer(2,&b,0);BG_SYS_Init(2,0,1,0);
 BG_SYS_SetTileEntry(2,0,0,0,32,24,17);BG_SYS_PushTile(2);
 c=gMainBgTemplateA;
 BG_SYS_InitBgLayer(1,&c,0);
 BG_SYS_SetTileEntry(1,0,0,0,32,24,17);BG_SYS_PushTile(1);
 BG_SYS_EnableBg0WithPriority(0);BG_SYS_SetPlaneVisible(0,1);BG_SYS_SetPriority(0,0);
}

static inline void shading(PokemontradeShading s) { *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3002) | (s << 1)); }

static inline void antialias(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 0x10); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3010; }

static inline void blend(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 8); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3008; }

static inline void edge(int b) { if(b) *(volatile u16 *)REG_DISP3DCNT_ADDR = (u16)((*(volatile u16 *)REG_DISP3DCNT_ADDR & ~0x3000) | 0x20); else *(volatile u16 *)REG_DISP3DCNT_ADDR &= (u16)~0x3020; }

/*
 * volatile: 0x04000060 reread at 021E552E, 021E553E, 021E554A, 021E5556; 0x04000008 display register; 0x04000580 hardware store at 021E557A.
 */
void POKETRADE_2D_Setup3DRenderState(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    shading(SHADING_HIGHLIGHT); antialias(1); blend(1); edge(0);
    G3X_SetFog(1,0,0,0);
    G3X_SetClearColor(0,0,0x7fff,0x3f,0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(struct G3dLight *)(gRenderLightTable+i*8));
    *(volatile u16 *)REG_BG0CNT_ADDR = (u16)((*(volatile u16 *)REG_BG0CNT_ADDR & ~3) | 2);
}

/*
 * lever: const camera s16 table keeps loads interleaved with stack arguments.
 * volatile: 0x04000060 hardware read-modify-write at 021E5644 and 021E5648.
 */
void POKETRADE_2D_InitG3DSystem(TradeWork *p)
{
    u16 heap;
    VecFx32 v;
    G3D_SYSTEM_Init(0,2,0,1,0,(p->heapId&0x7fff)|0x8000,POKETRADE_2D_Setup3DRenderState);
    heap = (p->heapId&0x7fff)|0x8000;
    v = gCameraTargetC;
    p->camera = G3D_CAMERA_Create(0,gCameraParams[6],gCameraParams[7],0x1555,0,0x1000,0x400000,0,&gCameraTargetB,&v,&gCameraTargetA,heap);
    G3D_CAMERA_Reset((struct G3dCamera *)(p->camera));
    *(volatile u16 *)REG_DISP3DCNT_ADDR &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}

void POKETRADE_2D_SetupSubBgs(TradeWork *p)
{
 struct BgTemplate a,b,c,d;
 a=gSubBgTemplate4;BG_SYS_InitBgLayer(4,&a,0);BG_SYS_SetTileEntry(4,0,0,0,32,24,17);
 b=gSubBgTemplate5;BG_SYS_InitBgLayer(5,&b,0);BG_SYS_Init(5,0,1,0);BG_SYS_SetTileEntry(5,0,0,0,32,24,17);BG_SYS_PushTile(5);
 c=gSubBgTemplate7;BG_SYS_InitBgLayer(7,&c,0);BG_SYS_SetTileEntry(7,0,0,0,64,24,17);BG_SYS_PushTile(7);
 d=gSubBgTemplate6;BG_SYS_InitBgLayer(6,&d,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,24,17);BG_SYS_PushTile(6);
 p->markerHandled=1;
}

void POKETRADE_2D_ExitSubBgs(TradeWork *p)
{
    if (p->markerHandled == 1) {
        BG_SYS_FreeTiles(4, 1, 0);
        BG_SYS_FreeTiles(6, 1, 0);
        BG_SYS_FreeLayerBuf(4);
        BG_SYS_FreeLayerBuf(5);
        BG_SYS_FreeLayerBuf(6);
        BG_SYS_FreeLayerBuf(7);
        p->markerHandled = 0;
    }
}

void POKETRADE_2D_SetDisplayConfig(int i)
{
    BG_SYS_SetGraphicsMode((struct DispConfig *)(gDisplayConfig + i * 16));
}

void POKETRADE_2D_RegisterMarkerResources(TradeWork *p)
{
    void *a;
    if (p->charA == 0) {
        a = ARC_TOOL_CreateHandle(0x66, p->heapId);
        p->charA = CLACT_RegisterCharacter(a, 0x15, 0, 0, p->heapId);
        p->paletteB = CLACT_RegisterPaletteEx(a, 0x12, 0, 0xc0, 0, 6, p->heapId);
        p->cellAnimD = CLACT_RegisterCellAnim(a, 0x14, 0x13, p->heapId);
        ARC_TOOL_DeleteHandle(a);
    }
}

void POKETRADE_2D_ReleaseMarkerResources(TradeWork *p)
{
    if (p->charA != 0) {
        CLACT_ReleaseCharacter(p->charA);
        CLACT_ReleasePalette(p->paletteB);
        CLACT_ReleaseCellAnim(p->cellAnimD);
        p->charA = 0;
        p->paletteB = 0;
        p->cellAnimD = 0;
    }
}

void POKETRADE_2D_RegisterIconSpriteResources(TradeWork *p)
{
    void *a;
    struct ActorInitParam s;
    a = ARC_TOOL_CreateHandle(0x66, p->heapId);
    p->actorChar = CLACT_RegisterCharacter(a, 0x18, 0, 1, p->heapId);
    p->actorPalette = CLACT_RegisterPaletteEx(a, 0x12, 1, 0xc0, 0, 6, p->heapId);
    p->actorCellAnim = CLACT_RegisterCellAnim(a, 0x17, 0x16, p->heapId);
    ARC_TOOL_DeleteHandle(a);
    s.x = 0x80; s.y = 0xb4; s.anim_seq = 2; s.draw_priority = 0xe; s.bg_priority = 0;
    p->cursorActor = CLACT_CreateActor((void *)p->clactSystem, p->actorChar, p->actorPalette, p->actorCellAnim, &s, 1, p->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->cursorActor, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 1);
}

void POKETRADE_2D_LoadMainPalette(TradeWork *p)
{
    void *a = ARC_TOOL_CreateHandle(0x66, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(a, (int)0x1d, (int)2, (int)0, (u16)(p->subBgHandle), (int)0, (int)0, p->heapId);
    ARC_TOOL_DeleteHandle(a);
}

void POKETRADE_2D_CreateTouchbarActors(TradeWork *p)
{
    void *arc;
    void *a, *b;
    int z;
    struct ActorInitParam u, t;
    u.x = 0x80;
    u.y = 0x10;
    u.anim_seq = 0x13;
    u.draw_priority = 0xe;
    u.bg_priority = 1;
    p->actorF08 = CLACT_CreateActor((*(void * *)&p->clactSystem), p->actorChar, p->actorPalette,
        p->actorCellAnim, &u, 1, p->heapId);
    CLACT_SetActorAutoAnim(p->actorF08, 1);
    CLACT_SetActorDrawEnable(p->actorF08, 1);
    u.x = 0x60;
    u.y = 0x10;
    u.anim_seq = 0;
    u.draw_priority = 0xb;
    u.bg_priority = 1;
    (*(void * *)&p->actorF0C) = CLACT_CreateActor((*(void * *)&p->clactSystem), p->actorChar, p->actorPalette,
        p->actorCellAnim, &u, 1, p->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&p->actorF0C), 1);
    if (UI_GetInputMode()) {
        CLACT_SetActorDrawEnable((*(void * *)&p->actorF0C), 0);
    }
    arc = ARC_TOOL_CreateHandle(7, p->heapId);
    z = 0;
    a = POKE_TOOL_GetBoxParam(POKETRADE_PROC_GetSideMon(p, 0));
    b = POKE_TOOL_GetBoxParam(POKETRADE_PROC_GetSideMon(p, 1));
    (p->charB) = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(a), z, 1, p->heapId);
    (p->charC) = CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(b), z, 1, p->heapId);
    t.x = 0x60;
    t.y = 0xc;
    t.anim_seq = z;
    t.draw_priority = 0xc;
    t.bg_priority = 1;
    (*(void * *)&p->iconActorA) = CLACT_CreateActor((*(void * *)&p->clactSystem), p->charB, p->iconPalette,
        p->cellAnimC, &t, 1, p->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&p->iconActorA), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->iconActorA), 1);
    CLACT_SetActorPaletteOffset((*(void * *)&p->iconActorA), POKE_TOOL_GetIconPalette(a), 1);
    t.x = 0xa0;
    (*(void * *)&p->iconActorB) = CLACT_CreateActor((*(void * *)&p->clactSystem), p->charC, p->iconPalette,
        p->cellAnimC, &t, 1, p->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&p->iconActorB), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->iconActorB), 1);
    CLACT_SetActorPaletteOffset((*(void * *)&p->iconActorB), POKE_TOOL_GetIconPalette(b), 1);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 */
void POKETRADE_2D_PlaceTouchbarActors(TradeWork *p, int b, int c)
{
    PointU16 pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActorA), (const struct ClactVec2 *)(&pos), 1);
        pos.x = 160; pos.y = 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActorB), (const struct ClactVec2 *)(&pos), 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActorA), (const struct ClactVec2 *)(&pos), 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActorB), (const struct ClactVec2 *)(&pos), 1);
    }
}

void POKETRADE_2D_DeleteTouchbarActors(void *a)
{
    if (((TradeWork *)a)->actorF08 != 0)
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)a)->actorF08));
    if (((TradeWork *)a)->actorF0C != 0)
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)a)->actorF0C));
    if (((TradeWork *)a)->iconActorA != 0)
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)a)->iconActorA));
    if (((TradeWork *)a)->iconActorB != 0)
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)a)->iconActorB));
    ((TradeWork *)a)->actorF08 = 0;
    ((TradeWork *)a)->actorF0C = 0;
    ((TradeWork *)a)->iconActorA = 0;
    ((TradeWork *)a)->iconActorB = 0;
    if (((TradeWork *)a)->charB != 0)
        CLACT_ReleaseCharacter(((TradeWork *)a)->charB);
    if (((TradeWork *)a)->charC != 0)
        CLACT_ReleaseCharacter(((TradeWork *)a)->charC);
    ((TradeWork *)a)->charB = 0;
    ((TradeWork *)a)->charC = 0;
}

void POKETRADE_2D_LoadSubScreenGfx(TradeWork *p)
{
    u32 i;
    void *h;
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    h = ARC_TOOL_CreateHandle(0x66, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 16, 4, 0, (u16)(p->mainBgHandle), 0, 0, p->heapId);
    BG_SYS_MarkTileDirty(4);
    BG_SYS_ChangeScrollImmediate(4, 0, -4);
    BG_SYS_ChangeScrollImmediate(6, 0, -4);
    ARC_TOOL_DeleteHandle(h);
    GF_FONT_SetTextColor(1, 2, 15);
    for (i = 0; i < PM_LANG_JA(26, 44); i++) {
        p->subScreenWin[i] = (void *)BMP_WIN_Create(6, (u8)gSubScreenWindowPos[i].x, (u8)gSubScreenWindowPos[i].y, 2, 2, 14, 0);
        MSGDATA_ReadString((struct MsgBank *)(p->messageBank), i + 0x35, (void *)(p->infoTextOut));
        PRINTSYS_Print(BMP_WIN_GetBmp(p->subScreenWin[i]), 0, 0, (*(void * *)&p->infoTextOut), p->font);
        BMP_WIN_MakeScreen(p->subScreenWin[i]);
        BMP_WIN_TransferChars(p->subScreenWin[i]);
    }
    BG_SYS_MarkTileDirty(6);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(6, 1);
}

/*
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 */
void POKETRADE_2D_ClearSubScreen(TradeWork *p)
{
    unsigned i;
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_ChangeScrollImmediate(4, 0, 0);
    BG_SYS_ChangeScrollImmediate(6, 0, 0);
    if (p->cursorActor) CLACT_SetActorDrawEnable((struct ClactActor *)p->cursorActor, 1);
    if (p->actorF18) CLACT_SetActorDrawEnable((struct ClactActor *)p->actorF18, 1);
    for (i = 0; i < PM_LANG_JA(26, 44); i++) {
        if (p->subScreenWin[i]) {
            BMP_WIN_ClearScreen((struct BmpWin *)(p->subScreenWin[i]));
            BMP_MENUWORK_DrawWindowBorder(p->subScreenWin[i], 2);
            BMP_WIN_Delete(p->subScreenWin[i]);
            p->subScreenWin[i] = 0;
        }
    }
    BG_SYS_MarkTileDirty(6);
}

/*
 * interface: x/y are u8 at 021E5ED6..021E5EE2; ov067's own u16 coordinate prototype is narrowed for this caller.
 * domain: side is 0/1 from 021E1E20/021E1E2C at call 021E1F14, or 2 at call 021E23B2 (r1 set 021E23AE).
 * initialization: both domain arms fill x, y, f0 and b1c; all remaining descriptor fields read by ov067 021B6208 are filled below.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`x
 * = side*128;` before `x = side*128+16;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void POKETRADE_2D_CreateMarkingIcon(TradeWork *p, int side, void *mon)
{
    TradeIconSlot *q = &p->markingIcon[0];
    ActorGfxDesc in;
    int x,y;
    int flag = 0;
    u32 species = POKE_TOOL_GetPartyValue(mon,6,0);
    if (FILE_UTIL_IsMailItem(species)) flag = 1;
    if (q->actor) {
        if (!species) CLACT_SetActorDrawEnable((struct ClactActor *)q->actor,0);
        else {
            CLACT_SetActorAnimSeq((struct ClactActor *)(q->actor),flag);
            CLACT_SetActorDrawEnable((struct ClactActor *)q->actor,1);
        }
        return;
    }
    if (!species) return;
    switch (side) {
    case 0: case 1:
        x = side*128+16; y = 132;
        in.screen = 1; in.plttSlot = 12;
        break;
    case 2:
        x = 32; y = 172;
        in.screen = 0; in.plttSlot = 6;
        break;
    }
    in.flags = 0;
    in.arcId = APP_ICON_GetArchiveId();
    in.charId = APP_ICON_GetItemCellFileId();
    in.plttId = APP_ICON_GetItemPaletteFileId();
    in.cellId = APP_ICON_GetItemAnimFileId(2);
    in.animId = APP_ICON_GetItemFrameFileId(2);
    in.charBase = 0; in.charSize = 1;
    UI_SCENE_LoadActorGfx(&q->gfx, (ActorGfxDesc *)&in, (void *)(p->clactSystem), p->heapId);
    q->actor = (void *)UI_SCENE_CreateActor( &q->gfx, (void *)(p->clactSystem), (u8)x, (u8)y,flag,p->heapId);
}

void POKETRADE_2D_DeleteMarkingIcon(TradeIconSlot *p)
{
    if (p->actor) {
        CLACT_DeleteActor((struct ClactActor *)(p->actor));
        UI_SCENE_FreeActorGfx(&p->gfx);
        p->actor = 0;
    }
}

/*
 * interface: x is narrowed to u8 at 021E5FE4/021E5FEC although ov067's callee declares u16.
 * initialization: ov067 UI_SCENE_LoadActorGfx reads only the seven words and bytes 1c..1e initialized below.
 * domain: call 021E1F20 loads side from the 0/1 slot initialized at 021E1E20/021E1E2C; call 021E2406 sets side=0 at 021E2400. Thus side*128+108 is 108 or 236.
 */
void POKETRADE_2D_CreatePokerusIcon(TradeWork *p, int side, int flag, void *mon)
{
    TradeIconSlot *q = &p->markingIcon[1];
    ActorGfxDesc in;
    u32 a = POKERUS_IsInfected(mon);
    if (q->actor) {
        if (!a) CLACT_SetActorDrawEnable((struct ClactActor *)q->actor,0);
        else CLACT_SetActorDrawEnable((struct ClactActor *)q->actor,1);
        return;
    }
    if (!a) {
        if (!flag) POKETRADE_2D_CreateCuredPokerusIcon(p,side,(void *)mon);
        return;
    }
    if (flag) { in.screen = 0; in.plttSlot = 0; }
    else { in.screen = 1; in.plttSlot = 11; }
    in.flags = 0;
    in.arcId = APP_ICON_GetArchiveId();
    in.charId = APP_ICON_GetSealCellFileId();
    in.plttId = APP_ICON_GetSealPaletteFileId();
    in.cellId = APP_ICON_GetSealAnimFileId(2);
    in.animId = APP_ICON_GetSealFrameFileId(2);
    in.charBase = 0; in.charSize = 1;
    UI_SCENE_LoadActorGfx(&q->gfx, (ActorGfxDesc *)&in, (void *)(p->clactSystem), p->heapId);
    if (flag) q->actor = (void *)UI_SCENE_CreateActor( &q->gfx, (void *)(p->clactSystem),244,104,0,p->heapId);
    else q->actor = (void *)UI_SCENE_CreateActor( &q->gfx, (void *)(p->clactSystem), (u8)(side*128+108),24,0,p->heapId);
}

/*
 * lever: caller truncates x to u8 despite callee's wider x type.
 */
void POKETRADE_2D_CreateCuredPokerusIcon(TradeWork *p, int b, void *c)
{
    TradeIconSlot *q = &p->markingIcon[2];
    ActorGfxDesc in;
    int a = POKERUS_IsCured(c);
    if (a == 0) return;
    if (q->actor) {
        if (a == 0) CLACT_SetActorDrawEnable((struct ClactActor *)q->actor, 0);
        else CLACT_SetActorDrawEnable((struct ClactActor *)q->actor, 1);
        return;
    }
    in.screen = 1; in.plttSlot = 14; in.flags = 0;
    in.arcId = APP_ICON_GetArchiveId();
    in.charId = APP_ICON_GetBallOpenAnimFileId();
    in.plttId = APP_ICON_GetEffectCellFileId(2);
    in.cellId = APP_ICON_GetEffectPaletteFileId(2);
    in.animId = APP_ICON_GetEffectAnimFileId(2);
    in.charBase = 0; in.charSize = 1;
    UI_SCENE_LoadActorGfx(&q->gfx, (ActorGfxDesc *)&in, (void *)(p->clactSystem), p->heapId);
    q->actor = (void *)UI_SCENE_CreateActor( &q->gfx, (void *)(p->clactSystem), (u8)(108 + b * 128), 20, 13, p->heapId);
}

/*
 * lever: signed long loop index, u8-qualified guard base versus char-qualified creation base, and mutable p keep the byte index live without a cached address spill.
 * domain: the local counter visits exactly 0..7; all unsigned index conversions preserve its full value. Creator x/state are caller-observed u8 arguments (021E61F8 and 021E620E); B878 state is u16 (021E61DA).
 * table-bounds: original words 021E7EC4..021E7EE0 are 25,26,27,28,29,30,20,21; coords.v[i]*8 is 160..240 without signed overflow or value loss.
 * initialization: both table objects are copied in full; every meaningful descriptor field is assigned before 021B6208.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`offOwner=0x98c;` before `offOwner=0x98c+0x38;`; `offStore=0x98c;` before
 * `offStore=0x98c+0x14;` and 2 more). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 */
void POKETRADE_2D_CreateSummaryIcons(TradeWork *p,void *mon,int flag)
{
    ActorGfxDesc in;
    Pokemontrade2dCoords coords;
    States states;
    u32 bits;
    long i;
    int state; struct ClactActor *sprite;
    int *row;
    bits=POKE_TOOL_GetPartyValue(mon,11,0);
    coords=gSummaryIconCoords;
    states=gSummaryIconStates;
    in.screen=0; in.flags=0;
    in.arcId=APP_ICON_GetArchiveId();
    in.charId=APP_ICON_GetBallOpenAnimFileId();
    in.plttId=APP_ICON_GetEffectCellFileId(2);
    in.cellId=APP_ICON_GetEffectPaletteFileId(2);
    in.animId=APP_ICON_GetEffectAnimFileId(2);
    in.plttSlot=13; in.charBase=0; in.charSize=1;
    if (!flag && POKE_TOOL_IsShiny(mon)) bits|=64;
    if (POKERUS_IsCured((struct PokemonParam *)mon)) bits|=128;
    if (!p->summary.loaded) {
        UI_SCENE_LoadActorGfx(&p->summary.gfx, (ActorGfxDesc *)&in, (void *)(p->clactSystem), p->heapId);
        p->summary.loaded=1;
    }
    for (i=0;i<8;i++) {
        sprite=p->summary.actor[(unsigned long)i];
        if (bits&(1<<i)) { row=states.v[(unsigned)i]; state=states.v[i][0]; }
        else { row=states.v[i]; state=row[1]; }
        if (sprite) {
            if (state==-1) CLACT_SetActorDrawEnable(sprite,0);
            else if (flag && i==6) CLACT_SetActorDrawEnable(sprite,0);
            else { CLACT_SetActorAnimSeq(sprite,state); CLACT_SetActorDrawEnable(sprite,1); }
        } else {
            p->summary.actor[(unsigned long)i]=(struct ClactActor *)UI_SCENE_CreateActor(&p->summary.gfx,p->clactSystem,(u8)(coords.v[(unsigned long)i]*8),101,state==-1?row[0]:state,p->heapId);
            sprite=p->summary.actor[(unsigned long)i];
            if (state==-1) CLACT_SetActorDrawEnable(sprite,0);
            else if (flag && i==6) CLACT_SetActorDrawEnable(sprite,0);
        }
    }
}

void POKETRADE_2D_DeleteSummaryIcons(TradeWork *p)
{
    TradeSummaryIcons *q = &p->summary;
    int i;
    for (i = 0; i < 8; i++) {
        if (q->actor[i]) {
            CLACT_DeleteActor(q->actor[i]);
            q->actor[i] = 0;
        }
    }
    if (q->loaded) {
        UI_SCENE_FreeActorGfx(&q->gfx);
        q->loaded = 0;
    }
}

void POKETRADE_2D_UploadWindowPalette(TradeWork *p, int n, u32 x) {
    int offset = n * 32;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,x,offset,32,p->heapId);
    ARC_UTIL_UploadPaletteFromArchive(APP_ICON_GetArchiveId(),31,x,28,offset+28,4,p->heapId);
}

void POKETRADE_2D_DeleteOfferIconActor(TradeWork *p, int a, int b)
{
    if (p->offerIconActor[a][b]) {
        CLACT_DeleteActor((struct ClactActor *)p->offerIconActor[a][b]);
        p->offerIconActor[a][b] = 0;
        CLACT_ReleaseCharacter(p->offerIconCharRes[a][b]);
    }
}

void POKETRADE_2D_SetOfferIconsVisible(TradeWork *p, int a, int v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->offerIconActor[a][i])
            CLACT_SetActorDrawEnable((struct ClactActor *)p->offerIconActor[a][i], v);
    }
}

/*
 * initialization: both coordinate arms initialize x/y; z/a/b are stored before creation.
 * domain: primary calls 021D9084, 021DD670 and 021E25FA prove i=0..1,j=0..2. Wrappers 021D90AC/C0/D4 supply j=0/1/2; 021DD428 returns -1 or 0..2 and caller rejects -1; 021E24E8 has bounded 2x3 loops. Table row i*3+j=0..5 and byte offset i*12+j*4=0..20.
 * interface: 0204B294's fifth full-word payload is a Create address; its body forwards unchanged to 0204CFDC's request pointer. r0 is consumed after that void-declared wrapper.
 * interface: 020185F0 is an empty forwarder; caller supplies r0 and consumes its unchanged pointer result at 021E6346.
 */
void POKETRADE_2D_CreateOfferIconActor(TradeWork *p,int i,int j,void *mon,int selected,u32 visible)
{
    struct ActorInitParam c;
    void *q = POKE_TOOL_CastToBoxParam(mon);
    void *h = ARC_TOOL_CreateHandle(7,p->heapId);
    int n;
    POKETRADE_2D_DeleteOfferIconActor((TradeWork *)p, i, j);
    if (selected) {
        c.x=gOfferIconPosA[i*3+j][0]; c.y=gOfferIconPosA[i*3+j][1]; n=0;
    } else {
        c.x=gOfferIconPosB[i*3+j][0]; c.y=gOfferIconPosB[i*3+j][1]; n=1;
    }
    c.anim_seq=1; c.draw_priority=16; c.bg_priority=1;
    p->offerIconCharRes[i][j] = CLACT_RegisterCharacter((void *)h,POKE_TOOL_GetGraphicIndex(q),0,n,p->heapId);
    p->offerIconActor[i][j] = CLACT_CreateActor((void *)p->clactSystem,p->offerIconCharRes[i][j],p->iconPaletteComp,p->cellAnimF,&c,n,p->heapId);
    CLACT_SetActorPaletteOffset(p->offerIconActor[i][j],POKE_TOOL_GetIconPalette(q),1);
    CLACT_SetActorAutoAnim(p->offerIconActor[i][j],0);
    CLACT_SetActorDrawEnable(p->offerIconActor[i][j],visible);
    ARC_TOOL_DeleteHandle((void *)(h));
}

void POKETRADE_2D_UpdateOfferIconHighlight(TradeWork *p, int a, int b) {
    int i,j;
    PointS16 pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (p->offerIconActor[i][j]) {
                pos.x=gOfferIconPosB[i*3+j][0]; pos.y=gOfferIconPosB[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                CLACT_AddActorSurfacePos((struct ClactActor *)(p->offerIconActor[i][j]),(const struct ClactVec2 *)(&pos),1);
            }
        }
    }
}

void POKETRADE_2D_DeleteAllOfferIconActors(TradeWork *p)
{
    int j, i;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            POKETRADE_2D_DeleteOfferIconActor((TradeWork *)p, i, j);
}

void POKETRADE_2D_CreateFloatingIconActor(TradeWork *p, int i, int j, int x, int y, void *q) {
    struct ActorInitParam c;
    c.x=x; c.y=y; c.anim_seq=1; c.draw_priority=0; c.bg_priority=0;
    p->iconActorC=CLACT_CreateActor((void *)p->clactSystem,p->iconChar[i][j],(p->iconPalette),(p->cellAnimC),&c,1,p->heapId);
    CLACT_SetActorPaletteOffset((struct ClactActor *)(p->iconActorC),POKE_TOOL_GetIconPalette(q),1);
}

static inline int mul(int a,int b) { return (int)(((s64)a*b+0x800LL)>>12); }

/*
 * initialization: 0204B454 writes both signed coordinates; all four vector arguments are fully assigned before 021E7248 reads each three-word object.
 * arithmetic: coordinate products fit signed32 for every signed-short input; fixed-point scalar sums use modulo32 ADD. Signed32 products plus 0x800 fit signed64 for every possible input.
 */
void POKETRADE_2D_StartIconFlight(TradeWork *p)
{
    VecFx32 end,third,second,first;
    PointS16 pos;
    int x,y,dx,dy,speed;
    CLACT_GetActorSurfacePos((struct ClactActor *)(*(void * *)&p->iconActorC),(struct ClactVec2 *)&pos,1);
    dx=(pos.x-p->originX)*4096;
    dy=(pos.y-p->originY)*4096;
    first.x=pos.x*4096; first.y=pos.y*4096; first.z=0;
    second.x=(pos.x*2-p->originX)*4096;
    second.y=(pos.y*2-p->originY)*4096; second.z=0;
    end.x=28*4096; end.y=0; end.z=0;
    x=first.x-end.x; y=first.y/2;
    speed=FX_Sqrt((int)((u32)mul(x,x)+(u32)mul(y,y)))/15;
    third.x=(int)((u32)x+(u32)mul(dx,speed)); third.y=(int)((u32)y+(u32)mul(dy,speed)); third.z=0;
    POKETRADE_2D_InitBezierCurve(&p->bezierCurve,&first,&second,&third,&end,19);
    p->flightTimer=21;
}

int POKETRADE_2D_UpdateIconFlight(TradeWork *p) {
    PointS16 pos;
    if (p->flightTimer) {
        --p->flightTimer;
        if (!p->flightTimer) return 1;
        CLACT_GetActorSurfacePos((struct ClactActor *)p->iconActorC,(struct ClactVec2 *)&pos,1);
        if (pos.y<0) p->flightTimer=1;
        if (p->flightTimer==1) POKETRADE_2D_DeleteFloatingIconActor(p);
        else {
            POKETRADE_2D_StepBezierCurve(&p->bezierCurve);
            pos.x=p->bezierCurve.out.x/4096;
            pos.y=p->bezierCurve.out.y/4096;
            CLACT_AddActorSurfacePos((struct ClactActor *)(p->iconActorC),(const struct ClactVec2 *)(&pos),1);
        }
    }
    return 0;
}

void POKETRADE_2D_DeleteFloatingIconActor(TradeWork *p)
{
    if (p->iconActorC) {
        CLACT_DeleteActor((struct ClactActor *)(p->iconActorC));
        p->iconActorC = 0;
    }
}

void POKETRADE_2D_SetupSubBlend(void *p)
{
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 0, 15, 8, 8);
}

void POKETRADE_2D_CreateMarkerActor(TradeWork *p, int i) {
    struct ActorInitParam c;
    if (!p->markerIconActor[i]) {
        c.x=i*24+8; c.y=144; c.anim_seq=i+11; c.draw_priority=50; c.bg_priority=1;
        p->markerIconActor[i]=CLACT_CreateActor((void *)p->clactSystem,p->actorChar,p->actorPalette,p->actorCellAnim,&c,1,p->heapId);
    }
    CLACT_SetActorAutoAnim(p->markerIconActor[i],1);
    CLACT_SetActorDrawEnable(p->markerIconActor[i],1);
}

void POKETRADE_2D_SetMarkerActorVisible(TradeWork *p, int i, int a)
{
    CLACT_SetActorDrawEnable(p->markerIconActor[i], a);
}

void POKETRADE_2D_DeleteMarkerActor(TradeWork *p, int i)
{
    if (p->markerIconActor[i]) {
        CLACT_DeleteActor(p->markerIconActor[i]);
        p->markerIconActor[i] = 0;
    }
}

void POKETRADE_2D_SetMarkerActorAnim(TradeWork *p, int i)
{
    CLACT_SetActorAnimSeq(p->markerIconActor[i], (u16)(i + 15));
}

void POKETRADE_2D_CreateMarkerButtonActor(TradeWork *p, int z, int i) {
    struct ActorInitParam c;
    c.x=i*206+8; c.y=160; c.anim_seq=4; c.draw_priority=1; c.bg_priority=0;
    if (!p->markerActor[i*2]) {
        p->markerActor[i*2]=CLACT_CreateActor((void *)p->clactSystem,p->charA,p->paletteB,p->cellAnimD,&c,0,p->heapId);
        CLACT_SetActorAutoAnim(p->markerActor[i*2],1);
        CLACT_SetActorDrawEnable(p->markerActor[i*2],1);
    } else {
        CLACT_SetActorDrawEnable(p->markerActor[i*2],1);
    }
    if (!p->markerActor[i*2+1]) {
        c.draw_priority=0; c.anim_seq=z;
        p->markerActor[i*2+1]=CLACT_CreateActor((void *)p->clactSystem,p->charA,p->paletteB,p->cellAnimD,&c,0,p->heapId);
        CLACT_SetActorAutoAnim(p->markerActor[i*2+1],1);
        CLACT_SetActorDrawEnable(p->markerActor[i*2+1],1);
    } else {
        CLACT_SetActorAnimSeq(p->markerActor[i*2+1],z);
    }
}

static inline void clear(TradeWork *p, int i) {
    if (p->markerActor[i]) {
        CLACT_DeleteActor((struct ClactActor *)(p->markerActor[i]));
        p->markerActor[(unsigned int)i]=0;
    }
}

/*
 * lever: unsigned cast on the store index prevents address CSE with the signed read index; without it 56 bytes, 37 byte DIFF.
 */
void POKETRADE_2D_DeleteMarkerButtonPair(TradeWork *p, int n) {
    int i=n*2;
    clear(p,i+1);
    clear(p,i);
}

void POKETRADE_2D_MovePickedIconActor(TradeWork *p, int i) {
    PointTable6 t=gPickedIconPath;
    struct ActorInitParam c;
    if(i==-1) {
        if(p->pickedIconActor) CLACT_SetActorDrawEnable((struct ClactActor *)p->pickedIconActor,0);
    } else {
        if(!p->pickedIconActor) {
            c.x=64;c.y=48;c.anim_seq=23;c.draw_priority=0;c.bg_priority=1;
            p->pickedIconActor=CLACT_CreateActor((void *)p->clactSystem,p->actorChar,p->actorPalette,p->actorCellAnim,&c,1,p->heapId);
        }
        CLACT_SetActorAutoAnim((struct ClactActor *)p->pickedIconActor,1);
        CLACT_SetActorDrawEnable((struct ClactActor *)p->pickedIconActor,1);
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->pickedIconActor),(const struct ClactVec2 *)(&t.pos[i]),1);
    }
}

void POKETRADE_2D_DeletePickedIconActor(TradeWork *p)
{
    if (p->pickedIconActor) {
        CLACT_DeleteActor((struct ClactActor *)(p->pickedIconActor));
        p->pickedIconActor = 0;
    }
}

/*
 * output: 0204B454 writes both halfwords via 0204B53C and 0204CF74/0204B0C8.
 * interface: 02040618 forwards legacy r3 only to 02042360, whose full body
 *            has three inputs and does not read it; caller supplies r0-r2.
 */
int POKETRADE_2D_StepCursorSlide(TradeWork *p)
{
    PointS16 a,b,c;
    int i;
    if(p->fadeLevel<128) p->fadeLevel+=4;
    else return 1;
    for(i=0;i<8;i++) {
        CLACT_GetActorSurfacePos(p->windowActor[i],(struct ClactVec2 *)&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        CLACT_AddActorSurfacePos(p->windowActor[i],(const struct ClactVec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(p->offerIconActor[0][i]) {
            CLACT_GetActorSurfacePos(p->offerIconActor[0][i],(struct ClactVec2 *)&b,1);
            b.x-=4;
            CLACT_AddActorSurfacePos(p->offerIconActor[0][i],(const struct ClactVec2 *)(&b),1);
        }
    }
    for(i=0;i<3;i++) {
        if(p->offerIconActor[1][i]) {
            CLACT_GetActorSurfacePos(p->offerIconActor[1][i],(struct ClactVec2 *)&c,1);
            c.x+=4;
            CLACT_AddActorSurfacePos(p->offerIconActor[1][i],(const struct ClactVec2 *)(&c),1);
        }
    }
    BG_SYS_ChangeScrollImmediate(5,0,-p->fadeLevel);
    BG_SYS_ChangeScrollImmediate(4,0,p->fadeLevel-128);
    return 0;
}

/*
 * lever: split temporary for first loop base and second loop index; 10-byte
 *         register swap without them. Permuter budget 300, 271 compiles.
 * output: 0204B454 and its full getter chain write both coordinate halfwords.
 */
void POKETRADE_2D_SetCursorSlidePositions(TradeWork *p)
{
    int j,i;
    PointS16 a,b,c;
    int tmp;
    for(i=0;i<8;i++) {
        CLACT_GetActorSurfacePos(p->windowActor[i],(struct ClactVec2 *)&a,1);
        if(i/4) {
            a.x-=128;
            CLACT_SetActorBgPriority(p->windowActor[i],3);
        } else a.x+=128;
        CLACT_AddActorSurfacePos(p->windowActor[i],(const struct ClactVec2 *)(&a),1);
    }
    for(j=0;j<3;j++) {
        if(p->offerIconActor[0][j]) {
            CLACT_GetActorSurfacePos(p->offerIconActor[0][j],(struct ClactVec2 *)&b,1);
            b.x+=128;
            tmp=j;
            tmp=tmp*4;
            CLACT_AddActorSurfacePos(p->offerIconActor[0][j],(const struct ClactVec2 *)(&b),1);
        }
    }
    for(j=0;j<3;j++) {
        if(p->offerIconActor[1][j]) {
            CLACT_GetActorSurfacePos(p->offerIconActor[1][j],(struct ClactVec2 *)&c,1);
            c.x-=128;
            CLACT_AddActorSurfacePos(p->offerIconActor[1][j],(const struct ClactVec2 *)(&c),1);
            CLACT_SetActorBgPriority(p->offerIconActor[1][j],3);
        }
    }
    BG_SYS_SetPriority(4,2);
    BG_SYS_SetPriority(5,3);
}

void POKETRADE_2D_SetupCursorBg(TradeWork *p)
{
    void *h;
    struct BgTemplate t;
    p->fontBgHandle = BMP_MENUWORK_LoadFrameGfx(6, 15, 0, p->heapId);
    h = ARC_TOOL_CreateHandle(0x66, p->heapId);
    p->mainBgHandle = ARC_UTIL_RegisterObjCharFromHandle(h, 13, 5, 0, 0, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 4, 0, (u16)p->mainBgHandle, 0, 0, p->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 5, 0, (u16)p->mainBgHandle, 0, 0, p->heapId);
    t = gCursorBgTemplate;
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_InitBgLayer(7, &t, 0);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 8, 7, 0, (u16)p->mainBgHandle, 0, 0, p->heapId);
    BG_SYS_ChangeScrollImmediate(4, 0, -0x80);
    BG_SYS_ChangeScrollImmediate(7, 0, 0);
    BG_SYS_SetPriority(4, 3);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 11, 2, 0, (u16)(p->subBgHandle), 0, 0, p->heapId);
    ARC_TOOL_DeleteHandle(h);
    (*(unsigned short *)&p->fadeLevel) = 0;
    POKETRADE_2D_SetCursorSlidePositions(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}

void POKETRADE_2D_CreateOfferWindows(TradeWork *work)
{
    TradeWork *p = work;
    PointTable8 t = gOfferWindowPos;
    void *h = ARC_TOOL_CreateHandle(0x66, p->heapId);
    struct ActorInitParam c;
    int i;
    (p->paletteE) = CLACT_RegisterPaletteEx(h, 0, 1, 0x1c0, 0, 1, p->heapId);
    p->cellAnimG = CLACT_RegisterCellAnim(h, 2, 1, p->heapId);
    for (i = 0; i < 8; i++) {
        p->windowBmp[i] = BMP_Create(16, 6, 32, p->heapId);
        p->windowChar[i] = CLACT_RegisterCharacter(h, 3, 0, 1, p->heapId);
    }
    for (i = 0; i < 8; i++) {
        c.x = *(short *)((char *)&t + i * 4); c.y = *(short *)((char *)&t + i * 4 + 2); c.anim_seq = 0; c.draw_priority = 0; c.bg_priority = 1;
        p->windowActor[i] = CLACT_CreateActor((void *)p->clactSystem, (*(int *)((char *)p->windowChar + i * (int)sizeof(int))), p->paletteE, p->cellAnimG, &c, 1, p->heapId);
        CLACT_SetActorDrawEnable(p->windowActor[i], 1);
    }
    ARC_TOOL_DeleteHandle(h);
}

void POKETRADE_2D_DeleteOfferWindowActors(TradeWork *p) {
    int i;
    for (i=0;i<8;i++) {
        if (p->windowActor[i]) {
            CLACT_DeleteActor((struct ClactActor *)(p->windowActor[i]));
            p->windowActor[i]=0;
            BMP_Delete(p->windowBmp[i]);
            p->windowBmp[i]=0;
            CLACT_ReleaseCharacter(p->windowChar[i]);
            p->windowChar[i]=0;
        }
    }
    if (p->paletteE) {CLACT_ReleasePalette(p->paletteE);p->paletteE=0;}
    if (p->paletteE) {CLACT_ReleaseCellAnim(p->windowChar[2]);p->paletteE=0;}
}

void POKETRADE_2D_UpdateOfferWindowActors(TradeWork *p) {
    ByteTable8 t=gOfferWindowActorTable;
    int i,j;
    char *dest,*source;
    for(i=0;i<8;i++) {
        dest=(char *)CLACT_GetCharacterVramAddress(p->windowChar[i],1);
        source=BMP_GetPixels(p->windowBmp[i]);
        DC_FlushRange(source,BMP_GetByteSize(p->windowBmp[i]));
        for(j=0;j<8;j++) {GXS_LoadOBJ(source+t.v[j]*256,(uptr)dest,256);dest+=256;}
    }
}

void POKETRADE_2D_LoadMonPalette(TradeWork *p, int side, void *mon)
{
    void *h = ARC_TOOL_CreateHandle(0x66, p->heapId);
    void *f;
    Pal *pal;
    u16 *d;
    u32 i;
    if (side == 0)
        f = ARC_UTIL_LoadPaletteDataFromHandle(h, 5, 0, (void **)&pal, p->heapId);
    else
        f = ARC_UTIL_LoadPaletteDataFromHandle(h, 6, 0, (void **)&pal, p->heapId);
    d = pal->data;
    for (i = 0; i < pal->size / 2; i++)
        d[i] += (u16)p->subBgHandle;
    if (!side)
        BG_SYS_DrawTile(1, (void *)d, 0, 0, 16, 24);
    else
        BG_SYS_DrawTile(1, (void *)pal->data, 16, 0, 16, 24);
    GFL_HEAP_Free(f);
    BG_SYS_SetPriority(3, 2);
    BG_SYS_SetPriority(2, 3);
    BG_SYS_SetPriority(1, 1);
    BG_SYS_SetPriority(0, 0);
    ARC_TOOL_DeleteHandle(h);
    BG_SYS_MarkTileDirty(1);
}

void POKETRADE_2D_OnCursorAnimDone(void *param, u32 frame) { ((TradeWork *)param)->cursorAnimDone=1; }

void POKETRADE_2D_CreateCursorActor(TradeWork *p, int x, int y) {
    struct ClactAnimCommand cb;
    struct ActorInitParam c;
    c.x=x+12;c.y=y+12;c.anim_seq=24;c.draw_priority=0;c.bg_priority=0;
    POKETRADE_2D_DeleteCursorActor(p);
    p->iconActorD=CLACT_CreateActor((void *)p->clactSystem,p->actorChar,p->actorPalette,p->actorCellAnim,&c,1,p->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)p->iconActorD,1);
    CLACT_SetActorAutoAnim((struct ClactActor *)p->iconActorD,1);
    p->cursorAnimDone=0;
    cb.op=0;cb.param=p;cb.func=POKETRADE_2D_OnCursorAnimDone;
    CLACT_ApplyActorAnimCommand((struct ClactActor *)(p->iconActorD),&cb);
}

void POKETRADE_2D_DeleteCursorActor(TradeWork *p)
{
    if (p->iconActorD) {
        CLACT_DeleteActor((struct ClactActor *)(p->iconActorD));
        p->iconActorD = 0;
        p->cursorAnimDone = 0;
    }
}

int POKETRADE_2D_ClearCursorIfDisabled(TradeWork *p)
{
    if (p->cursorAnimDone) {
        POKETRADE_2D_DeleteCursorActor(p);
        return 0;
    }
    return 1;
}

/*
 * interface: 02021540 forwards live r0 to 020307B0, so caller passes s.
 */
void POKETRADE_2D_FadePaletteBank(TradeWork *p, int bank, int mask)
{
    PaletteFade *s;
    char *buf;
    int i;
    int off;
    s=PALANM_Create(p->heapId);
    PALANM_AllocSlotBuffers(s,bank,0x200,p->heapId);
    PALANM_CopyHwPaletteToSlot(s,bank,0,0x200);
    PALANM_BlendChannel(s,bank,0,0x100,6,0);
    buf=(char *)PALANM_GetTransWork(s,bank);
    for(i=0;i<16;i++) {
        if(mask & (1<<i)) {
            off=i*32;
            DC_FlushRange(buf+off,32);
            switch(bank) {
            case 3: GXS_LoadOBJPltt(buf+off,off,32); break;
            case 1: GXS_LoadBGPltt(buf+off,off,32); break;
            case 2: GX_LoadOBJPltt(buf+off,off,32); break;
            case 0: GX_LoadBGPltt(buf+off,off,32); break;
            }
        }
    }
    PALANM_FreeSlotBuffers(s,bank);
    PALANM_Delete(s);
}

void POKETRADE_2D_FadePaletteCopy(TradeWork *p, int capture, int bank, int mask)
{
    if (capture != 0) {
        if (bank == 3)
            MI_CpuCopy8((void *)HW_DB_OBJ_PLTT, p->subObjPaletteCopy,
                          0x200);
        else if (bank == 1)
            MI_CpuCopy8((void *)HW_DB_BG_PLTT, p->subBgPaletteCopy,
                          0x200);
        POKETRADE_2D_FadePaletteBank(p, bank, mask);
        return;
    }
    if (bank == 3) {
        DC_FlushRange(p->subObjPaletteCopy, 0x200);
        GXS_LoadOBJPltt(p->subObjPaletteCopy, 0, 0x200);
        return;
    }
    if (bank == 1) {
        DC_FlushRange(p->subBgPaletteCopy, 0x200);
        GXS_LoadBGPltt(p->subBgPaletteCopy, 0, 0x200);
    }
}

void POKETRADE_2D_FadePaletteAll(TradeWork *p, int a)
{
    POKETRADE_2D_FadePaletteCopy(p, a, 3, 0xfffe);
}

/*
 * GFL_USE_GetMainTaskList (ARM9, unlabelled Thumb leaf) was filed EXACT by the
 * dependency-tree lane and now attests this call through `matched`.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a)
{
    TCB_AddTask((struct TcbSystem *)GFL_USE_GetMainTaskList(), POKETRADE_2D_TaskSetMainPlaneVisible, (void *)(uptr)a, 0xa);
}

void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a)
{
    TCB_AddTask((struct TcbSystem *)GFL_USE_GetMainTaskList(), POKETRADE_2D_TaskSetSubPlaneVisible, (void *)(uptr)a, 0xa);
}

void POKETRADE_2D_TaskSetMainPlaneVisible(struct TcbTask *p, void *a)
{
    BG_SYS_SetMainVisiblePlanes((int)(uptr)a);
    TCB_DeleteTask(p);
}

void POKETRADE_2D_TaskSetSubPlaneVisible(struct TcbTask *p, void *a)
{
    BG_SYS_SetSubVisiblePlanes((int)(uptr)a);
    TCB_DeleteTask(p);
}

void POKETRADE_2D_InitBezierCurve(struct BezierCurve *d, VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *dd, int e)
{
    d->out = *a;
    d->p[0] = *a;
    d->p[1] = *b;
    d->p[2] = *c;
    d->p[3] = *dd;
    d->idx = 0;
    d->count = e;
}

int POKETRADE_2D_StepBezierCurve(struct BezierCurve *c)
{
    fx32 t, s, t2, s2, ts2, s3, t2s, t3;
    fx32 tm3, t2m3;

    if (c->idx < c->count - 1) {
        t = FX_Div(FX_INT_TO_FX32(c->idx), FX_INT_TO_FX32(c->count));
        s = FX32_ONE - t;
        t2 = FX_MUL(t, t);
        s2 = FX_MUL(s, s);
        tm3 = 3 * t;
        ts2 = FX_MUL(tm3, s2);
        s3 = FX_MUL(s2, s);
        t2m3 = 3 * t2;
        t2s = FX_MUL(t2m3, s);
        t3 = FX_MUL(t2, t);
        c->out.x = FX_MUL(c->p[0].x, s3) + FX_MUL(c->p[1].x, ts2)
                 + FX_MUL(c->p[2].x, t2s) + FX_MUL(c->p[3].x, t3);
        c->out.y = FX_MUL(c->p[0].y, s3) + FX_MUL(c->p[1].y, ts2)
                 + FX_MUL(c->p[2].y, t2s) + FX_MUL(c->p[3].y, t3);
        c->out.z = FX_MUL(c->p[0].z, s3) + FX_MUL(c->p[1].z, ts2)
                 + FX_MUL(c->p[2].z, t2s) + FX_MUL(c->p[3].z, t3);
        c->idx++;
        return 0;
    }
    c->out = c->p[3];
    return 1;
}
