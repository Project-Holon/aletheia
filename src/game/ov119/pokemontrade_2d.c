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

typedef struct { short v; void *p; void (*fn)(void *); } Pokemontrade2dCallback;

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
unsigned char POKETRADE_2D_GetMonMarkingIcon(void *mon, unsigned int heap);
void POKETRADE_2D_BuildBoxMarkingTable(char *p, int box, unsigned char *out);
void POKETRADE_2D_BuildPartyMarkingTable(char *p, void *party, unsigned char *out);
int POKETRADE_2D_BuildMarkingTablesFrom(char *p, int i);
void POKETRADE_2D_InitClactSystemMain(char *p);
void POKETRADE_2D_InitClactSystemSub(void *p);
void POKETRADE_2D_LoadBackgroundGfx(char *p);
void POKETRADE_2D_FreeBackgroundPalette(char *p);
void POKETRADE_2D_LoadSubBackgroundGfx(char *p);
void POKETRADE_2D_NoOp(void *p);
void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p);
void POKETRADE_2D_CreateFontResource(char *p);
void POKETRADE_2D_FreeMainResources(char *p);
void POKETRADE_2D_RegisterIconCharResources(char *p);
void POKETRADE_2D_LoadSummaryBackground(char *p, int shiftScroll, int bgIndex);
void POKETRADE_2D_ClearSummaryBackground(char *p);
unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, char *p, int mode);
int POKETRADE_2D_HitTestBoxGrid(char *p, int x, int y);
void POKETRADE_2D_DrawBoxGridScreen(char *p);
void POKETRADE_2D_LoadBoxScreenData(char *p, int d);
void POKETRADE_2D_FreeBoxScreenData(char *p);
void POKETRADE_2D_CreateBoxWindows(char *p);
void POKETRADE_2D_DeleteBoxWindows(char *p);
void POKETRADE_2D_DrawBoxNames(char *p);
void POKETRADE_2D_CreateBoxIconActors(char *p);
void POKETRADE_2D_DeleteBoxIconRow(char *p, int n);
void POKETRADE_2D_DeleteAllBoxIcons(char *p);
void POKETRADE_2D_DeleteOfferIcons(char *p);
void POKETRADE_2D_GetGridCellPos(int x, int y, unsigned short *out);
int POKETRADE_2D_ResolveGridCell(int v, int a, int b, char *p, int *out);
char *POKETRADE_2D_GetGridCellMon(int a, int b, char *p);
void POKETRADE_2D_PlaceBoxIconActors(char *p);
int POKETRADE_2D_IsBoxIconFiltered(char *p, int i);
int POKETRADE_2D_IsBoxIconMatch(int i, int x);
void POKETRADE_2D_SetIconObjMode(int unused, struct ClactActor *actor, int enable);
void POKETRADE_2D_UpdateIconObjMode(char *p, int gridSlot, int column, int recordId, int cellKind, int row);
void POKETRADE_2D_CreateBoxIcon(char *p, int v, int a, int row, int flag);
int POKETRADE_2D_GetScrollColumn(char *p);
int POKETRADE_2D_GetVisibleColumnRange(char *p, int *out);
void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
void POKETRADE_2D_UpdateBoxIconPositions(char *p);
void POKETRADE_2D_LoadBoxIconGfx(char *p, int b);
s32 POKETRADE_2D_WrapIndex12(s32 x);
void POKETRADE_2D_HideAllBoxIcons(int p);
struct ClactActor *POKETRADE_2D_HitTestBoxIcons(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void POKETRADE_2D_SetupSummaryBgs(char *p,int mode);
void POKETRADE_2D_ExitSummaryBgs(int p);
void POKETRADE_2D_InitDisplayAndClact(char *p);
void POKETRADE_2D_SetupMainBgs(void *unused);
void POKETRADE_2D_Setup3DRenderState(void);
void POKETRADE_2D_InitG3DSystem(char *p);
void POKETRADE_2D_SetupSubBgs(char *p);
void POKETRADE_2D_ExitSubBgs(char *p);
void POKETRADE_2D_SetDisplayConfig(int i);
void POKETRADE_2D_RegisterMarkerResources(int p);
void POKETRADE_2D_ReleaseMarkerResources(char *p);
void POKETRADE_2D_RegisterIconSpriteResources(char *p);
void POKETRADE_2D_LoadMainPalette(char *p);
void POKETRADE_2D_CreateTouchbarActors(char *p);
void POKETRADE_2D_PlaceTouchbarActors(char *p, int b, int c);
void POKETRADE_2D_DeleteTouchbarActors(void *a);
void POKETRADE_2D_LoadSubScreenGfx(char *p);
void POKETRADE_2D_ClearSubScreen(char *p);
void POKETRADE_2D_CreateMarkingIcon(char *p, int side, void *mon);
void POKETRADE_2D_DeleteMarkingIcon(void *p);
void POKETRADE_2D_CreatePokerusIcon(char *p, int side, int flag, void *mon);
void POKETRADE_2D_CreateCuredPokerusIcon(char *p, int b, void *c);
void POKETRADE_2D_CreateSummaryIcons(char *p,void *mon,int flag);
void POKETRADE_2D_DeleteSummaryIcons(void *p);
void POKETRADE_2D_UploadWindowPalette(char *p, int n, u32 x);
void POKETRADE_2D_DeleteOfferIconActor(TradeWork *p, int a, int b);
void POKETRADE_2D_SetOfferIconsVisible(TradeWork *p, int a, int v);
void POKETRADE_2D_CreateOfferIconActor(char *p,int i,int j,void *mon,int selected,u32 visible);
void POKETRADE_2D_UpdateOfferIconHighlight(void *p, int a, int b);
void POKETRADE_2D_DeleteAllOfferIconActors(void *p);
void POKETRADE_2D_CreateFloatingIconActor(int p, int i, int j, int x, int y, void *q);
void POKETRADE_2D_StartIconFlight(char *p);
int POKETRADE_2D_UpdateIconFlight(char *p);
void POKETRADE_2D_DeleteFloatingIconActor(void *p);
void POKETRADE_2D_SetupSubBlend(void *p);
void POKETRADE_2D_CreateMarkerActor(char *p, int i);
void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a);
void POKETRADE_2D_DeleteMarkerActor(void *p, int i);
void POKETRADE_2D_SetMarkerActorAnim(void *p, int i);
void POKETRADE_2D_CreateMarkerButtonActor(TradeWork *p, int z, int i);
void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n);
void POKETRADE_2D_MovePickedIconActor(void *p, int i);
void POKETRADE_2D_DeletePickedIconActor(char *p);
int POKETRADE_2D_StepCursorSlide(char *p);
void POKETRADE_2D_SetCursorSlidePositions(const char *p);
void POKETRADE_2D_SetupCursorBg(char *p);
void POKETRADE_2D_CreateOfferWindows(char *p);
void POKETRADE_2D_DeleteOfferWindowActors(char *p);
void POKETRADE_2D_UpdateOfferWindowActors(char *p);
void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon);
void POKETRADE_2D_OnCursorAnimDone(char *p);
void POKETRADE_2D_CreateCursorActor(char *p, int x, int y);
void POKETRADE_2D_DeleteCursorActor(void *p);
int POKETRADE_2D_ClearCursorIfDisabled(void *p);
void POKETRADE_2D_FadePaletteBank(char *p, int bank, int mask);
void POKETRADE_2D_FadePaletteCopy(void *p, int capture, int bank, int mask);
void POKETRADE_2D_FadePaletteAll(void *p, int a);
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetMainPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetSubPlaneVisible(void *p, int a);
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
extern PointU32 gSubScreenWindowPos[26];
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

void POKETRADE_2D_BuildBoxMarkingTable(char *p, int box, unsigned char *out)
{
    unsigned char i;

    for (i = 0; i < 30; i++)
        out[i] = POKETRADE_2D_GetMonMarkingIcon(BOX_SAVEDATA_GetPokemon((*(void * *)&((TradeWork *)p)->boxManager), box, i), ((TradeWork *)p)->heapId);
}

void POKETRADE_2D_BuildPartyMarkingTable(char *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = POKETRADE_2D_GetMonMarkingIcon(POKE_TOOL_CastToBoxParam(POKEPARTY_GetMember(party, i)), ((TradeWork *)p)->heapId);
        else
            out[i] = 0;
    }
}

int POKETRADE_2D_BuildMarkingTablesFrom(char *p, int i)
{
    while (i < ((TradeWork *)p)->partyBoxId + 1) {
        if (i == ((TradeWork *)p)->partyBoxId) {
            POKETRADE_2D_BuildPartyMarkingTable(p, ((TradeWork *)p)->partyData, (unsigned char *)(p + 0x2E0));
            return 1;
        }
        POKETRADE_2D_BuildBoxMarkingTable(p, i, (unsigned char *)(p + 0x10 + i * 30));
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
void POKETRADE_2D_InitClactSystemMain(char *p)
{
    CLACT_InitSystem((struct ClactSysInit *)gClactConfigMain, (struct DispVramCfg *)gClactInitData, ((TradeWork *)p)->heapId);
}

/*
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of POKETRADE_SAVE_ResetClactAndBeginEvent's preamble.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_InitClactSystemSub(void *p)
{
    CLACT_InitSystem((struct ClactSysInit *)(&gClactConfigSub), (struct DispVramCfg *)(&gClactInitData), ((TradeWork *)p)->heapId);
}

void POKETRADE_2D_LoadBackgroundGfx(char *p)
{
    void *v;
    int kind;
    int mode;
    v = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    mode = POKETRADE_PROC_IsHostSide(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    ARC_UTIL_UploadPaletteFromHandleWhole(v, 9, 0, 0, 0, ((TradeWork *)p)->heapId);
    if (((TradeWork *)p)->subBgHandle == 0)
        ((TradeWork *)p)->subBgHandle = ARC_UTIL_RegisterObjCharFromHandle(v, 10, 2, 0, 0, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, kind, (int)2, (int)0, (unsigned short)((*(unsigned int *)&((TradeWork *)p)->subBgHandle)), (int)0, (int)0, (unsigned int)(((TradeWork *)p)->heapId));
    ARC_TOOL_DeleteHandle(v);
}

void POKETRADE_2D_FreeBackgroundPalette(char *p)
{
    u32 v;

    v = (*(unsigned int *)&((TradeWork *)p)->subBgHandle);
    if (v != 0)
        BG_SYS_FreeTileRun((int)2, (u16)v, (u16)(v >> 16));
    (*(unsigned int *)&((TradeWork *)p)->subBgHandle) = 0;
}

void POKETRADE_2D_LoadSubBackgroundGfx(char *p)
{
    void *v;
    v = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, 12, (int)4, (int)0, (unsigned short)(((TradeWork *)p)->mainBgHandle), (int)0, (int)0, (unsigned int)(((TradeWork *)p)->heapId));
    ARC_TOOL_DeleteHandle(v);
}

/*
 * Empty stub.
 */
void POKETRADE_2D_NoOp(void *p)
{
}

void POKETRADE_2D_LoadMainGfxAndMessageWindow(char *p)
{
    void *v;

    v = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(v, 0x11, 4, 0, 0xC0, ((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->boxBgHandle) = (void *)ARC_UTIL_RegisterObjCharFromHandle(v, 0xD, 7, 0, 0, ((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->mainBgHandle) = (void *)ARC_UTIL_RegisterObjCharFromHandle(v, 0xD, 5, 0, 0, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(v);
    POKETRADE_2D_LoadBoxScreenData(p, (sptr)((*(void * *)&((TradeWork *)p)->boxBgHandle)));
}

void POKETRADE_2D_CreateFontResource(char *p)
{
    (*(void * *)&((TradeWork *)p)->fontBgHandle) = BMP_MENUWORK_LoadFrameGfx((unsigned int)6, 15, 0, ((TradeWork *)p)->heapId);
}

void POKETRADE_2D_FreeMainResources(char *p)
{
    POKETRADE_2D_FreeBoxScreenData(p);
    if (((TradeWork *)p)->mainBgHandle) {
        BG_SYS_FreeTileRun((int)5, (unsigned short)(((TradeWork *)p)->mainBgHandle), (unsigned short)(((TradeWork *)p)->mainBgHandle >> 16));
        *(int *)&((TradeWork *)p)->mainBgHandle = 0;
    }
    if (((TradeWork *)p)->boxBgHandle) {
        BG_SYS_FreeTileRun((int)7, (unsigned short)(((TradeWork *)p)->boxBgHandle), (unsigned short)(((TradeWork *)p)->boxBgHandle >> 16));
        *(int *)&((TradeWork *)p)->boxBgHandle = 0;
    }
    if (((TradeWork *)p)->fontBgHandle) {
        BG_SYS_FreeTileRun((int)6, (unsigned short)(((TradeWork *)p)->fontBgHandle), (unsigned short)(((TradeWork *)p)->fontBgHandle >> 16));
        *(int *)&((TradeWork *)p)->fontBgHandle = 0;
    }
}

void POKETRADE_2D_RegisterIconCharResources(char *p)
{
    void *v;
    int a;
    if (((TradeWork *)p)->iconPaletteEx == 0) {
        v = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->charD = CLACT_RegisterCharacter(v, APP_ICON_GetMoveKindAnimFileId(), 0, 1, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->iconPaletteEx = CLACT_RegisterPaletteEx(v, APP_ICON_GetMoveKindPaletteFileId(), 1, 0, 0, 3, ((TradeWork *)p)->heapId);
        a = APP_ICON_GetStatusCellFileId(2);
        ((TradeWork *)p)->cellAnimE = CLACT_RegisterCellAnim(v, a, APP_ICON_GetStatusPaletteFileId(2), ((TradeWork *)p)->heapId);
        ARC_TOOL_DeleteHandle(v);
    }
}

void POKETRADE_2D_LoadSummaryBackground(char *p, int shiftScroll, int bgIndex)
{
    Tbl2 tbl = gSummaryBgTable;
    void *v;
    v = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, tbl.w[bgIndex], 4, 0, (unsigned short)((TradeWork *)p)->mainBgHandle, 0, 0, ((TradeWork *)p)->heapId);
    if (shiftScroll != 0) {
        BG_SYS_ChangeScrollImmediate(4, 0, 0x80);
    } else {
        BG_SYS_ChangeScrollImmediate(4, 0, 0);
    }
    CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->cursorActor, 0);
    ARC_TOOL_DeleteHandle(v);
    BG_SYS_SetPlaneVisible(4, 1);
}

void POKETRADE_2D_ClearSummaryBackground(char *p)
{
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_ChangeScrollImmediate(4, 0, 0);
    POKETRADE_2D_SetupSubBlend(p);
    BG_SYS_ClearSlot(4);
    BG_SYS_MarkTileDirty(4);
}

unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, char *p, int mode)
{
    if (i >= ((TradeWork *)p)->columnWrap)
        i -= ((TradeWork *)p)->columnWrap;
    if (i < 12) {
        if (mode)
            return (*(unsigned short **)(p + 0x1180))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1178))[i + (row * 32 + 18)];
    } else {
        i = (i - 12) % 20;
        if (mode)
            return (*(unsigned short **)(p + 0x117C))[i + (row * 32 + 18)];
        else
            return (*(unsigned short **)(p + 0x1174))[i + (row * 32 + 18)];
    }
}

/*
 * lever: initialize the inner counter before calculating the two outer cursors.
 */
int POKETRADE_2D_HitTestBoxGrid(char *p, int x, int y)
{
    int i, j, a, b;
    char *q, *r, *s;
    for (i = 0; i < 12; i++) {
        j = 0;
        q = p + i * 5;
        s = p + i * 20;
        for (; j < 5; j++) {
            if (*(unsigned char *)(q + j + 0xebc)) {
                r = s + j * 4;
                a = ((TradeWork *)r)->iconX - 5;
                b = ((TradeWork *)r)->iconY - 8;
                if (a < 0) a -= 8;
                a /= 8;
                b /= 8;
                if (a <= x && a + 3 > x && b <= y && b + 3 > y) return 1;
            }
        }
    }
    return 0;
}

void POKETRADE_2D_DrawBoxGridScreen(char *p)
{
    int x, y, n, mode;
    n = ((TradeWork *)p)->scrollX / 8;
    POKETRADE_2D_GetScrollColumn(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = POKETRADE_2D_HitTestBoxGrid(p, x, y);
            BG_SYS_SetupTileScreen(7, x, y, POKETRADE_2D_GetBoxScreenEntry(n + x, y, p, mode));
        }
    }
    ((TradeWork *)p)->scrollSub = ((TradeWork *)p)->scrollX % 8;
    ((TradeWork *)p)->redrawNeeded = 1;
    BG_SYS_MarkTileDirty(7);
}

/*
 * 2026-10-03 (wB3 lane07): EXACT. The doubled zero-extension of the loop-invariant
 * comes from an int parameter stored in a u16 local and then added as (int)e.
 */
void POKETRADE_2D_LoadBoxScreenData(char *p, int d)
{
    int i;
    u16 e;

    *(Pokemontrade2dBuf * *)&((TradeWork *)p)->tilemapE = ARC_TOOL_LoadMember(0x66, 0xE, ((TradeWork *)p)->heapId);
    *(Pokemontrade2dBuf * *)&((TradeWork *)p)->tilemapF = ARC_TOOL_LoadMember(0x66, 0xF, ((TradeWork *)p)->heapId);
    *(Pokemontrade2dBuf * *)&((TradeWork *)p)->tilemap19 = ARC_TOOL_LoadMember(0x66, 0x19, ((TradeWork *)p)->heapId);
    *(Pokemontrade2dBuf * *)&((TradeWork *)p)->tilemap1A = ARC_TOOL_LoadMember(0x66, 0x1A, ((TradeWork *)p)->heapId);
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Pokemontrade2dBuf * *)&((TradeWork *)p)->tilemapE)->v[i] += (int)e;
        (*(Pokemontrade2dBuf **)(p + 0x1178))->v[i] += (int)e;
        (*(Pokemontrade2dBuf **)(p + 0x117C))->v[i] += (int)e;
        (*(Pokemontrade2dBuf **)(p + 0x1180))->v[i] += (int)e;
    }
    (*(unsigned short *)&((TradeWork *)p)->scrollX) = (*(unsigned int *)&((TradeWork *)p)->gridOriginX) - 0x50;
    POKETRADE_2D_DrawBoxGridScreen(p);
}

void POKETRADE_2D_FreeBoxScreenData(char *p)
{
    if (((TradeWork *)p)->tilemapE) {
        GFL_HEAP_Free(((TradeWork *)p)->tilemapE);
        ((TradeWork *)p)->tilemapE = 0;
        GFL_HEAP_Free(((TradeWork *)p)->tilemapF);
        ((TradeWork *)p)->tilemapF = 0;
        GFL_HEAP_Free(((TradeWork *)p)->tilemap19);
        ((TradeWork *)p)->tilemap19 = 0;
        GFL_HEAP_Free(((TradeWork *)p)->tilemap1A);
        ((TradeWork *)p)->tilemap1A = 0;
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
void POKETRADE_2D_CreateBoxWindows(char *p)
{
    int off1, h, off, off2, off3;
    int a,b,c,d,e,f,g;
    int i, zero;
    char *q;
    off = 0x5F4;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,448,32,*(u16 *)(p+off));
    i = 0;
    if (i >= (int)((u32)*(int *)(p+off+0x3C)+1u)) goto done;
        zero = 0;
        off1 = 0x6B8;
        off = 0x630;
        off3 = 0x730;
        off2 = 0x730;
        a = 0x6B8;
        b = 0x6B8;
        c = 0x728;
        d = 0x730;
        e = 0x6B8;
        f = 0x6B8;
        g = 0x630;
        h = 0x6B8;
        do {
            q = (char *)((u32 *)p+i);
            if (*(u32 *)(q+h) == 0)
                *(u32 *)(q+off1) = (uptr)BMP_WIN_Create(5,0,0,15,2,14,0);
            if (i == *(int *)(p+off))
                MSGDATA_ReadString((*(void * *)&((TradeWork *)p)->messageBank),16,*(void **)(p+off2));
            else BOX_SAVEDATA_GetBoxName((*(void * *)&((TradeWork *)p)->boxManager),i,*(void **)(p+off3));
            GF_FONT_SetTextColor(15,2,zero);
            BMP_Clear(BMP_WIN_GetBmp(*(void **)(q+a)),zero);
            PRINTSYS_Print(BMP_WIN_GetBmp(*(void **)(q+b)),zero,1,*(void **)(p+d),*(void **)(p+c));
            BMP_WIN_TransferChars(*(void **)(q+e));
            BMP_WIN_SetPosY(*(void **)(q+f),zero);
        } while (++i < (int)((u32)*(int *)(p+g)+1u));
done:;
}

void POKETRADE_2D_DeleteBoxWindows(char *p)
{
    int i;
    for (i = 0; i < 25; i++) {
        if (*(void **)(p + i * 4 + 0x6B8)) {
            BMP_WIN_Delete(*(void **)(p + i * 4 + 0x6B8));
            *(void **)(p + i * 4 + 0x6B8) = 0;
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
void POKETRADE_2D_DrawBoxNames(char *p)
{
    int x, y, scroll, first, i, n, pos, idx;
    int off1, off2, bound;
    char *q;
    scroll = ((TradeWork *)p)->scrollX / 8;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            BG_SYS_SetupTileScreen(5, x, y, 0);
        }
    }
    if (((TradeWork *)p)->scrollX < 96) first = ((TradeWork *)p)->partyBoxId;
    else first = (((TradeWork *)p)->scrollX - 96) / 160;
    i = 0;
    off1 = 0x6B8;
    off2 = 0x6B8;
    bound = 0x630;
    for (; i < 3; i++) {
        idx = (int)((u32)first+(u32)i);
        n = *(int *)(p + bound);
        if (idx > n) idx = (int)((u32)idx-(u32)n-1u);
        else if (idx < 0) idx = (int)((u32)idx+(u32)n+1u);
        if (idx == n) {
            pos = (int)((*(unsigned int *)&((TradeWork *)p)->columnWrap)-(u32)scroll);
            if (scroll > pos) scroll = (int)((u32)scroll-(*(unsigned int *)&((TradeWork *)p)->columnWrap));
            else pos = (int)(0u-(u32)scroll);
        } else pos = (int)((u32)idx*20u+12u-(u32)scroll);
        if (pos >= -10 && pos <= 33) {
            q = (char *)((uptr)p+(u32)idx*4u);
            BMP_WIN_SetPosX(*(void **)(q + off1), pos + 1);
            BMP_WIN_MakeScreen(*(void **)(q + off2));
        }
    }
    BG_SYS_MarkTileDirty(5);
}

void POKETRADE_2D_CreateBoxIconActors(char *p)
{
    int i, j, z;
    void *arc;
    char *q;
    struct ActorInitParam t;
    arc = ARC_TOOL_CreateHandle(7, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->iconPalette = (void *)CLACT_RegisterPaletteCompressed(arc, POKE_TOOL_GetIconPaletteArcId(), 1, 0x60, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->cellAnimC = (void *)CLACT_RegisterCellAnim(arc, POKE_TOOL_GetIconCellArcIdSub(), POKE_TOOL_GetIconCellEntryId(), ((TradeWork *)p)->heapId);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.anim_seq = 1;
            t.draw_priority = 0x10;
            t.bg_priority = 3;
            q = p + i * 20 + j * 4;
            ((TradeWork *)q)->charE = (void *)CLACT_RegisterCharacter(arc, 0x51b, z, 1, ((TradeWork *)p)->heapId);
            ((TradeWork *)q)->boxIconActor = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (uptr)((TradeWork *)q)->charE,
                (uptr)((TradeWork *)p)->iconPalette, (uptr)((TradeWork *)p)->cellAnimC, &t, 1, ((TradeWork *)p)->heapId);
            t.anim_seq = z;
            t.draw_priority = 0xf;
            ((TradeWork *)q)->boxIconActorAlt = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (uptr)(*(void * *)&((TradeWork *)p)->actorChar),
                (uptr)(*(void * *)&((TradeWork *)p)->actorPalette), (uptr)(*(void * *)&((TradeWork *)p)->actorCellAnim), &t, 1, ((TradeWork *)p)->heapId);
            CLACT_SetActorAutoAnim(((TradeWork *)q)->boxIconActor, z);
            CLACT_SetActorDrawEnable(((TradeWork *)q)->boxIconActor, z);
            CLACT_SetActorDrawEnable(((TradeWork *)q)->boxIconActorAlt, z);
            CLACT_SetActorAutoAnim(((TradeWork *)q)->boxIconActorAlt, 1);
        }
    }
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * follower: two zero padding bytes at 0x021E4886 before labelled 021E4888.
 */
void POKETRADE_2D_DeleteBoxIconRow(char *p, int n)
{
    int i;
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + n * 20 + i * 4 + 0xac0)) {
            CLACT_DeleteActor((struct ClactActor *)(*(int *)(p + n * 20 + i * 4 + 0xac0)));
            *(int *)(p + n * 20 + i * 4 + 0xac0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0xbb0)) {
            CLACT_DeleteActor((struct ClactActor *)(*(int *)(p + n * 20 + i * 4 + 0xbb0)));
            *(int *)(p + n * 20 + i * 4 + 0xbb0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0x9cc)) {
            CLACT_ReleaseCharacter(*(int *)(p + n * 20 + i * 4 + 0x9cc));
            *(int *)(p + n * 20 + i * 4 + 0x9cc) = 0;
        }
    }
}

void POKETRADE_2D_DeleteAllBoxIcons(char *p)
{
    int i;
    POKETRADE_2D_DeletePickedIconActor(p);
    for (i = 0; i < 12; i++) POKETRADE_2D_DeleteBoxIconRow(p, i);
    if ((*(int *)&((TradeWork *)p)->iconPalette)) {
        CLACT_ReleasePalette((*(int *)&((TradeWork *)p)->iconPalette));
        (*(int *)&((TradeWork *)p)->iconPalette) = 0;
    }
    if ((*(int *)&((TradeWork *)p)->cellAnimC)) {
        CLACT_ReleaseCellAnim((*(int *)&((TradeWork *)p)->cellAnimC));
        (*(int *)&((TradeWork *)p)->cellAnimC) = 0;
    }
    if (((TradeWork *)p)->vramBuf) GFL_HEAP_Free(((TradeWork *)p)->vramBuf);
    ((TradeWork *)p)->vramBuf = 0;
}

void POKETRADE_2D_DeleteOfferIcons(char *p)
{
    int i;
    POKETRADE_2D_DeleteCursorActor(p);
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    for (i = 0; i < 10; i++) {
        if (*(int *)(p + i * 4 + 0xefc)) {
            CLACT_DeleteActor((struct ClactActor *)(*(int *)(p + i * 4 + 0xefc)));
            *(int *)(p + i * 4 + 0xefc) = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleasePalette(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 12; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
    for (; i < 18; i++) {
        if (*(int *)(p + i * 4 + 0x87c)) {
            CLACT_ReleaseCellAnim(*(int *)(p + i * 4 + 0x87c));
            *(int *)(p + i * 4 + 0x87c) = 0;
        }
    }
}

void POKETRADE_2D_GetGridCellPos(int x, int y, unsigned short *out)
{
    out[0] = (x + 1) * 0x18;
    out[1] = y * 0x18 + 0x48;
}

int POKETRADE_2D_ResolveGridCell(int v, int a, int b, char *p, int *out)
{
    int n, m;
    if (a >= 2) {
        n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
        m = POKETRADE_PROC_GetSlotIndexInBox(a, b);
        *out = 0;
        return (sptr)POKETRADE_PROC_LoadSlotMonAlt((void *)v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return (sptr)POKETRADE_PROC_LoadSlotMonAlt((void *)v, ((TradeWork *)p)->partyBoxId, a + b * 2, p);
    }
    return 0;
}

char *POKETRADE_2D_GetGridCellMon(int a, int b, char *p)
{
    int n;
    if (a >= 2) {
        n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
        return POKETRADE_PROC_GetSlotMonPtr(n, POKETRADE_PROC_GetSlotIndexInBox(a, b), p);
    }
    if (b < 3)
        return POKETRADE_PROC_GetSlotMonPtr(((TradeWork *)p)->partyBoxId, a + b * 2, p);
    return 0;
}

void POKETRADE_2D_PlaceBoxIconActors(char *p)
{
    short xy[2];
    int i, j;
    char *q, *r;
    for (i = 0; i < 5; i++) {
        q = p + i * 4;
        for (j = 0; j < 12; j++) {
            r = q + j * 20;
            if (CLACT_GetActorDrawEnable((struct ClactActor *)(((TradeWork *)r)->boxIconActorAlt))) {
                CLACT_GetActorSurfacePos((struct ClactActor *)((TradeWork *)r)->boxIconActorAlt, (struct ClactVec2 *)xy, 1);
                ((TradeWork *)p)->iconPosX = xy[0];
                ((TradeWork *)p)->iconPosY = xy[1];
            }
        }
    }
}

int POKETRADE_2D_IsBoxIconFiltered(char *p, int i)
{
    int v = ((TradeWork *)p)->filterIndex;
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
void POKETRADE_2D_SetIconObjMode(int unused, struct ClactActor *actor, int enable)
{
    CLACT_SetActorObjMode(actor, enable != 0);
}

void POKETRADE_2D_UpdateIconObjMode(char *p, int gridSlot, int column, int recordId, int cellKind, int row)
{
    int flag = 0;
    if (POKETRADE_NEGO_IsMonOwnOffer(p, gridSlot, column)) {
        flag = 1;
    }
    POKETRADE_2D_SetIconObjMode((sptr)p, ((struct ClactActor *(*)[5])(p + 0xAC0))[row][column], flag);
}

void POKETRADE_2D_CreateBoxIcon(char *p, int v, int a, int row, int flag)
{
    int j; sptr rec; int id, b2, b3, idx, n;
    Pokemontrade2dEnt *e;
    Pokemontrade2dInfo info;
    int kind;
    u16 pos[2];
    PointS16 pt;
    enum { VRAM_BASE = HW_DB_OBJ_VRAM } vram;
    if (a == ((TradeWork *)p)->cursorSlot && UI_GetInputMode() == 0) {
        CLACT_SetActorDrawEnable(((void **)(p + row * 20 + 0xbb0))[((TradeWork *)p)->cursorColumn], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = POKETRADE_2D_ResolveGridCell(v, a, j, p, &kind);
        e = (Pokemontrade2dEnt *)POKETRADE_2D_GetGridCellMon(a, j, p);
        if (e == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        if (e->id == 0) {
            *(u8 *)(p + row * 5 + j + 0xd90) = 0xff;
            continue;
        }
        ((u8 *)(p + row * 5) + j)[0xd90] = a;
        b2 = e->b2;
        id = e->id;
        b3 = e->b3;
        if (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 == ((u8 *)(p + row * 5) + j)[0xd18]
            && b3 == ((u8 *)(p + row * 5) + j)[0xd54]) {
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + j * 4 + 0xac0), 1);
            POKETRADE_2D_UpdateIconObjMode(p, a, j, rec, kind, row);
        } else if (id != *(u16 *)(p + row * 10 + j * 2 + 0xca0)
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b2 != ((u8 *)(p + row * 5) + j)[0xd18])
            || (id == *(u16 *)(p + row * 10 + j * 2 + 0xca0) && b3 != ((u8 *)(p + row * 5) + j)[0xd54])) {
            *(u16 *)(p + row * 10 + j * 2 + 0xca0) = id;
            *(u8 *)(p + row * 5 + j + 0xd18) = b2;
            *(u8 *)(p + row * 5 + j + 0xd54) = b3;
            POKETRADE_2D_GetGridCellPos(a, j, pos);
            CLACT_GetActorImageProxy(*(void **)(p + row * 20 + j * 4 + 0xac0), (struct ImageProxy *)(&info));
            n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
            idx = POKETRADE_PROC_GetSlotIndexInBox(a, j);
            idx += n * 30;
            CLACT_GetActorSurfacePos((struct ClactActor *)*(void **)(p + row * 20 + j * 4 + 0xac0), (struct ClactVec2 *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (NNS_GfdRegisterNewVramTransferTask(0x23, info.c, (void *)(*(int *)(p + 0x1184) + idx * 0x200), 0x200) == 0) {
                    vram = VRAM_BASE;
                    MI_CpuCopy8((const void *)(*(int *)(p + 0x1184) + idx * 0x200), (void *)(vram + info.c), 0x200);
                }
            } else {
                vram = VRAM_BASE;
                MI_CpuCopy8((const void *)(*(int *)&((TradeWork *)p)->vramBuf + idx * 0x200), (void *)(vram + info.c), 0x200);
            }
            POKETRADE_2D_UpdateIconObjMode(p, a, j, rec, kind, row);
            CLACT_SetActorPaletteOffset(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), POKE_TOOL_GetIconPalette((void *)rec), 1);
            CLACT_SetActorAutoAnim(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 0);
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 1);
        }
        if (POKE_TOOL_GetBoxValue((void *)rec, 0x4c, 0) == 0 && POKETRADE_2D_IsBoxIconFiltered(p, id)) {
            ((u8 *)(p + row * 5) + j)[0xebc] = 1;
        }
    }
}

/*
 * lever: a separate adjusted-coordinate local keeps the subtraction before division.
 */
int POKETRADE_2D_GetScrollColumn(char *p)
{
    int x, q, r, v;
    x = ((TradeWork *)p)->scrollX;
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

int POKETRADE_2D_GetVisibleColumnRange(char *p, int *out)
{
    int x, hi, n, t;
    x = POKETRADE_2D_GetScrollColumn(p);
    *out = x + 2;
    hi = x + 10;
    n = ((TradeWork *)p)->slotCount;
    if (*out >= n) *out -= n;
    n = ((TradeWork *)p)->slotCount;
    if (hi >= n) {
        t = ((TradeWork *)p)->cursorSlot;
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = ((TradeWork *)p)->cursorSlot;
        if (x <= t && t <= hi) return 1;
    }
    return 0;
}

/*
 * lever: i before n gives n the earlier spill slot.
 */
void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b)
{
    int i, n, j;
    n = POKETRADE_2D_GetScrollColumn(p);
    if (((TradeWork *)p)->cursorRow != n) {
        ((TradeWork *)p)->cursorRow = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)(p + i * 20 + j * 4 + 0xbb0), 0);
                *(unsigned char *)(p + i * 5 + j + 0xebc) = 0;
            }
        }
        ((TradeWork *)p)->drawColumn = n;
        POKETRADE_2D_HideAllBoxIcons((sptr)p);
        for (i = 0; i < 12; i++) {
            POKETRADE_2D_CreateBoxIcon(p, a, n, POKETRADE_2D_WrapIndex12(((TradeWork *)p)->cursorRow + i), b);
            n++;
            if (n >= ((TradeWork *)p)->slotCount) n = 0;
        }
    }
    POKETRADE_2D_UpdateBoxIconPositions(p);
}

/*
 * lever:    the hoisted column sum is written inside the else arm as two statements.
 */
void POKETRADE_2D_UpdateBoxIconPositions(char *p)
{
    char *q;
    int i, off, y, row, j, x, ty, col;
    PointS16 b, a;
    off = 0;
    y = ((TradeWork *)p)->cursorRow;
    for (i = 0; i < 12; i++) {
        row = POKETRADE_2D_WrapIndex12(((TradeWork *)p)->cursorRow + i);
        if (y >= ((TradeWork *)p)->slotCount) {
            y -= ((TradeWork *)p)->slotCount;
            off = ((TradeWork *)p)->gridOriginX;
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
            b.x = off + (x - ((TradeWork *)p)->scrollX);
            b.y = ty;
            a = b;
            if (POKETRADE_NEGO_IsMonPeerSelected(p, y, j) && UI_GetInputMode() == 1) {
                b.y -= 8;
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority( ((TradeWork *)q)->boxIconActor, 11);
            } else {
                q = p + row * 20 + j * 4;
#ifdef __MWERKS__
                /* The original caller declared the priority as u8 and the actor as int. */
                ((void (*)(int, u8))CLACT_SetActorDrawPriority)((*(int *)&((TradeWork *)q)->boxIconActor), 0x1c - i);
#else
                CLACT_SetActorDrawPriority(((TradeWork *)q)->boxIconActor, 0x1c - i);
#endif
            }
            CLACT_AddActorSurfacePos(((TradeWork *)q)->boxIconActor, (const struct ClactVec2 *)(&b), 1);
            if (*(u8 *)(p + row * 5 + j + 0xebc)) {
                *(PointS16 *)(q + 0xdcc) = a;
            }
            b.y = ty + 3;
            CLACT_AddActorSurfacePos(((TradeWork *)q)->boxIconActorAlt, (const struct ClactVec2 *)(&b), 1);
        }
        y++;
    }
}

/*
 * lever: initial guard is a forward goto, with the exit after the body.
 */
void POKETRADE_2D_LoadBoxIconGfx(char *p, int b)
{
    int i, n; sptr x, t, out;
    void *a;
    if (b == 0) *(int *)&((TradeWork *)p)->vramBuf = (sptr)GFL_HEAP_Alloc(((TradeWork *)p)->heapId, 0x5ac00, 0, gBoxIconAllocTag, 0x50b);
    a = ARC_TOOL_CreateHandle(7, ((TradeWork *)p)->heapId);
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = (sptr)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->boxManager), b, i, p);
            if (x) x = POKE_TOOL_GetGraphicIndex((void *)x);
            else x = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
            t = (sptr)ARC_UTIL_LoadBgCharDataFromHandle((void *)a, x, 0, (&out), ((TradeWork *)p)->heapId);
            MI_CpuCopy8(((struct GfxLoadResult *)out)->data, (void *)(*(int *)&((TradeWork *)p)->vramBuf + n * 512), 512);
            n++;
            GFL_HEAP_Free((void *)t);
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
void POKETRADE_2D_HideAllBoxIcons(int p)
{
    int i, j;
    for (i = 0; i < 12; i++)
        for (j = 0; j < 5; j++)
            CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)(p + i * 20 + j * 4 + 0xac0), 0);
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
struct ClactActor *POKETRADE_2D_HitTestBoxIcons(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow)
{
 PointS16 pos;
 int column,slot,row;
 Pokemontrade2dObject *tmp;
 for(row=0;row<12;row++) {
  for(column=0;column<5;column++) {
   CLACT_GetActorSurfacePos((struct ClactActor *)((Pokemontrade2dObject *)p)->actors[row][column],(struct ClactVec2 *)&pos,1);
   if(pos.x<=x && x<pos.x+24 && pos.y<=y && y<pos.y+24) {
    if(outA) {
     slot=*(u8 *)(p+0xd90+row*5+column);
     if(slot==255)return 0;
     if(POKETRADE_PROC_GetSlotIndexInBox(slot,column)!=-1) {
      *outA=POKETRADE_PROC_GetBoxIndexForSlot(slot,p);
      *outB=POKETRADE_PROC_GetSlotIndexInBox(slot,column);
     } else return 0;
    }
    if(outSlot) {*outSlot=slot;*outColumn=column;*outRow=row;}
    tmp=(Pokemontrade2dObject *)p;
    return tmp->actors[row][column];
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
void POKETRADE_2D_SetupSummaryBgs(char *p,int mode)
{
 struct BgTemplate a,b;
 void *v;
 POKETRADE_2D_SetDisplayConfig(1);p[0x11ec]=1;
 a=gSummaryBgTemplate6;BG_SYS_InitBgLayer(6,&a,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,24,17);BG_SYS_PushTile(6);
 b=gSummaryBgTemplate7;BG_SYS_InitBgLayer(7,&b,2);
 if(mode==0) {
  v=ARC_TOOL_CreateHandle(0x67,((TradeWork *)p)->heapId);
  ARC_UTIL_UploadPaletteFromHandleWhole(v,5,6,0x6000,0,((TradeWork *)p)->heapId);
  ARC_UTIL_UploadBgCharFromHandle((void *)((uptr)v),4,7,0,0,0,((TradeWork *)p)->heapId);
  ARC_UTIL_UploadBgPaletteFromHandle((void *)((uptr)v),6,7,0,0,0,((TradeWork *)p)->heapId);
  BG_SYS_ChangeScrollImmediate(7,0,0);ARC_TOOL_DeleteHandle(v);
 } else {
  v=ARC_TOOL_CreateHandle(0x68,((TradeWork *)p)->heapId);
  ARC_UTIL_UploadPaletteFromHandleWhole(v,1,6,0x6000,0,((TradeWork *)p)->heapId);
  ARC_UTIL_UploadBgCharFromHandle((void *)((uptr)v),0,7,0,0,0,((TradeWork *)p)->heapId);
  ARC_UTIL_UploadBgPaletteFromHandle((void *)((uptr)v),2,7,0,0,0,((TradeWork *)p)->heapId);
  BG_SYS_ChangeScrollImmediate(7,0,0);ARC_TOOL_DeleteHandle(v);
 }
}

void POKETRADE_2D_ExitSummaryBgs(int p)
{
    if (((TradeWork *)p)->summaryActive != 0) {
        BG_SYS_FreeTiles(6, 1, 0);
        BG_SYS_FreeLayerBuf(6);
        BG_SYS_FreeLayerBuf(7);
        ((TradeWork *)p)->summaryActive = 0;
    }
}

void POKETRADE_2D_InitDisplayAndClact(char *p)
{
    BG_SYS_SetVramBanks((const struct DispVram *)gClactInitData);
    CLACT_InitSystem((struct ClactSysInit *)(&gClactConfigSub), (struct DispVramCfg *)gClactInitData, ((TradeWork *)p)->heapId);
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
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | 2);
}

/*
 * lever: const camera s16 table keeps loads interleaved with stack arguments.
 * volatile: 0x04000060 hardware read-modify-write at 021E5644 and 021E5648.
 */
void POKETRADE_2D_InitG3DSystem(char *p)
{
    u16 heap;
    VecFx32 v;
    G3D_SYSTEM_Init(0,2,0,1,0,(((TradeWork *)p)->heapId&0x7fff)|0x8000,POKETRADE_2D_Setup3DRenderState);
    heap = (((TradeWork *)p)->heapId&0x7fff)|0x8000;
    v = gCameraTargetC;
    ((TradeWork *)p)->camera = G3D_CAMERA_Create(0,gCameraParams[6],gCameraParams[7],0x1555,0,0x1000,0x400000,0,&gCameraTargetB,&v,&gCameraTargetA,heap);
    G3D_CAMERA_Reset((struct G3dCamera *)(((TradeWork *)p)->camera));
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}

void POKETRADE_2D_SetupSubBgs(char *p)
{
 struct BgTemplate a,b,c,d;
 a=gSubBgTemplate4;BG_SYS_InitBgLayer(4,&a,0);BG_SYS_SetTileEntry(4,0,0,0,32,24,17);
 b=gSubBgTemplate5;BG_SYS_InitBgLayer(5,&b,0);BG_SYS_Init(5,0,1,0);BG_SYS_SetTileEntry(5,0,0,0,32,24,17);BG_SYS_PushTile(5);
 c=gSubBgTemplate7;BG_SYS_InitBgLayer(7,&c,0);BG_SYS_SetTileEntry(7,0,0,0,64,24,17);BG_SYS_PushTile(7);
 d=gSubBgTemplate6;BG_SYS_InitBgLayer(6,&d,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,24,17);BG_SYS_PushTile(6);
 p[0x11eb]=1;
}

void POKETRADE_2D_ExitSubBgs(char *p)
{
    if (((TradeWork *)p)->markerHandled == 1) {
        BG_SYS_FreeTiles(4, 1, 0);
        BG_SYS_FreeTiles(6, 1, 0);
        BG_SYS_FreeLayerBuf(4);
        BG_SYS_FreeLayerBuf(5);
        BG_SYS_FreeLayerBuf(6);
        BG_SYS_FreeLayerBuf(7);
        ((TradeWork *)p)->markerHandled = 0;
    }
}

void POKETRADE_2D_SetDisplayConfig(int i)
{
    BG_SYS_SetGraphicsMode((struct DispConfig *)(gDisplayConfig + i * 16));
}

void POKETRADE_2D_RegisterMarkerResources(int p)
{
    void *a;
    if (((TradeWork *)p)->charA == 0) {
        a = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->charA = CLACT_RegisterCharacter(a, 0x15, 0, 0, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->paletteB = CLACT_RegisterPaletteEx(a, 0x12, 0, 0xc0, 0, 6, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->cellAnimD = CLACT_RegisterCellAnim(a, 0x14, 0x13, ((TradeWork *)p)->heapId);
        ARC_TOOL_DeleteHandle(a);
    }
}

void POKETRADE_2D_ReleaseMarkerResources(char *p)
{
    if (((TradeWork *)p)->charA != 0) {
        CLACT_ReleaseCharacter(((TradeWork *)p)->charA);
        CLACT_ReleasePalette(((TradeWork *)p)->paletteB);
        CLACT_ReleaseCellAnim(((TradeWork *)p)->cellAnimD);
        ((TradeWork *)p)->charA = 0;
        ((TradeWork *)p)->paletteB = 0;
        ((TradeWork *)p)->cellAnimD = 0;
    }
}

void POKETRADE_2D_RegisterIconSpriteResources(char *p)
{
    void *a;
    struct ActorInitParam s;
    a = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->actorChar = CLACT_RegisterCharacter(a, 0x18, 0, 1, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->actorPalette = CLACT_RegisterPaletteEx(a, 0x12, 1, 0xc0, 0, 6, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->actorCellAnim = CLACT_RegisterCellAnim(a, 0x17, 0x16, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(a);
    s.x = 0x80; s.y = 0xb4; s.anim_seq = 2; s.draw_priority = 0xe; s.bg_priority = 0;
    ((TradeWork *)p)->cursorActor = CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem, ((TradeWork *)p)->actorChar, ((TradeWork *)p)->actorPalette, ((TradeWork *)p)->actorCellAnim, &s, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)((TradeWork *)p)->cursorActor, 0);
    CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->cursorActor, 1);
}

void POKETRADE_2D_LoadMainPalette(char *p)
{
    void *a = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(a, (int)0x1d, (int)2, (int)0, (u16)(((TradeWork *)p)->subBgHandle), (int)0, (int)0, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(a);
}

void POKETRADE_2D_CreateTouchbarActors(char *p)
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
    ((TradeWork *)p)->actorF08 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (uptr)(*(void * *)&((TradeWork *)p)->actorChar), (uptr)(*(void * *)&((TradeWork *)p)->actorPalette),
        (uptr)(*(void * *)&((TradeWork *)p)->actorCellAnim), &u, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim(((TradeWork *)p)->actorF08, 1);
    CLACT_SetActorDrawEnable(((TradeWork *)p)->actorF08, 1);
    u.x = 0x60;
    u.y = 0x10;
    u.anim_seq = 0;
    u.draw_priority = 0xb;
    u.bg_priority = 1;
    (*(void * *)&((TradeWork *)p)->actorF0C) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (uptr)(*(void * *)&((TradeWork *)p)->actorChar), (uptr)(*(void * *)&((TradeWork *)p)->actorPalette),
        (uptr)(*(void * *)&((TradeWork *)p)->actorCellAnim), &u, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&((TradeWork *)p)->actorF0C), 1);
    if (UI_GetInputMode()) {
        CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->actorF0C), 0);
    }
    arc = ARC_TOOL_CreateHandle(7, ((TradeWork *)p)->heapId);
    z = 0;
    a = POKE_TOOL_GetBoxParam(POKETRADE_PROC_GetSideMon(p, 0));
    b = POKE_TOOL_GetBoxParam(POKETRADE_PROC_GetSideMon(p, 1));
    (*(void * *)&((TradeWork *)p)->charB) = (void *)CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(a), z, 1, ((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->charC) = (void *)CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(b), z, 1, ((TradeWork *)p)->heapId);
    t.x = 0x60;
    t.y = 0xc;
    t.anim_seq = z;
    t.draw_priority = 0xc;
    t.bg_priority = 1;
    (*(void * *)&((TradeWork *)p)->iconActorA) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (uptr)(*(void * *)&((TradeWork *)p)->charB), (uptr)((TradeWork *)p)->iconPalette,
        (uptr)((TradeWork *)p)->cellAnimC, &t, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&((TradeWork *)p)->iconActorA), 0);
    CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->iconActorA), 1);
    CLACT_SetActorPaletteOffset((*(void * *)&((TradeWork *)p)->iconActorA), POKE_TOOL_GetIconPalette(a), 1);
    t.x = 0xa0;
    (*(void * *)&((TradeWork *)p)->iconActorB) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (uptr)(*(void * *)&((TradeWork *)p)->charC), (uptr)((TradeWork *)p)->iconPalette,
        (uptr)((TradeWork *)p)->cellAnimC, &t, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&((TradeWork *)p)->iconActorB), 0);
    CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->iconActorB), 1);
    CLACT_SetActorPaletteOffset((*(void * *)&((TradeWork *)p)->iconActorB), POKE_TOOL_GetIconPalette(b), 1);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 */
void POKETRADE_2D_PlaceTouchbarActors(char *p, int b, int c)
{
    PointU16 pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->iconActorA), (const struct ClactVec2 *)(&pos), 1);
        pos.x = 160; pos.y = 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->iconActorB), (const struct ClactVec2 *)(&pos), 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->iconActorA), (const struct ClactVec2 *)(&pos), 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->iconActorB), (const struct ClactVec2 *)(&pos), 1);
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

void POKETRADE_2D_LoadSubScreenGfx(char *p)
{
    u32 i;
    void *h;
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_SetPlaneVisible(6, 0);
    h = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 16, 4, 0, (u16)(*(int *)&((TradeWork *)p)->mainBgHandle), 0, 0, ((TradeWork *)p)->heapId);
    BG_SYS_MarkTileDirty(4);
    BG_SYS_ChangeScrollImmediate(4, 0, -4);
    BG_SYS_ChangeScrollImmediate(6, 0, -4);
    ARC_TOOL_DeleteHandle(h);
    GF_FONT_SetTextColor(1, 2, 15);
    for (i = 0; i < 26; i++) {
        *(void **)(p + i * 4 + 0x750) = (void *)BMP_WIN_Create(6, (u8)gSubScreenWindowPos[i].x, (u8)gSubScreenWindowPos[i].y, 2, 2, 14, 0);
        MSGDATA_ReadString((struct MsgBank *)(((TradeWork *)p)->messageBank), i + 0x35, (void *)(((TradeWork *)p)->infoTextOut));
        PRINTSYS_Print(BMP_WIN_GetBmp(*(void **)(p + i * 4 + 0x750)), 0, 0, (*(void * *)&((TradeWork *)p)->infoTextOut), ((TradeWork *)p)->font);
        BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0x750));
        BMP_WIN_TransferChars(*(void **)(p + i * 4 + 0x750));
    }
    BG_SYS_MarkTileDirty(6);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(6, 1);
}

/*
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 */
void POKETRADE_2D_ClearSubScreen(char *p)
{
    unsigned i;
    BG_SYS_SetPlaneVisible(4, 0);
    BG_SYS_ChangeScrollImmediate(4, 0, 0);
    BG_SYS_ChangeScrollImmediate(6, 0, 0);
    if (((TradeWork *)p)->cursorActor) CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->cursorActor, 1);
    if (((TradeWork *)p)->actorF18) CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->actorF18, 1);
    for (i = 0; i < 26; i++) {
        if (*(int *)(p + i * 4 + 0x750)) {
            BMP_WIN_ClearScreen((struct BmpWin *)(*(int *)(p + i * 4 + 0x750)));
            BMP_MENUWORK_DrawWindowBorder((void *)(*(int *)(p + i * 4 + 0x750)), 2);
            BMP_WIN_Delete((struct BmpWin *)(*(int *)(p + i * 4 + 0x750)));
            *(int *)(p + i * 4 + 0x750) = 0;
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
void POKETRADE_2D_CreateMarkingIcon(char *p, int side, void *mon)
{
    char *q = p + 0x950;
    ActorGfxDesc in;
    int x,y;
    int flag = 0;
    u32 species = POKE_TOOL_GetPartyValue(mon,6,0);
    if (FILE_UTIL_IsMailItem(species)) flag = 1;
    if (((struct PokemontradeUiScene *)q)->actor) {
        if (!species) CLACT_SetActorDrawEnable((struct ClactActor *)((struct PokemontradeUiScene *)q)->actor,0);
        else {
            CLACT_SetActorAnimSeq((struct ClactActor *)(((struct PokemontradeUiScene *)q)->actor),flag);
            CLACT_SetActorDrawEnable((struct ClactActor *)((struct PokemontradeUiScene *)q)->actor,1);
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
    UI_SCENE_LoadActorGfx((ActorGfxSet *)q, (ActorGfxDesc *)&in, (void *)(((TradeWork *)p)->clactSystem), ((TradeWork *)p)->heapId);
    ((struct PokemontradeUiScene *)q)->actor = (void *)UI_SCENE_CreateActor( (ActorGfxSet *)q, (void *)(((TradeWork *)p)->clactSystem), (u8)x, (u8)y,flag,((TradeWork *)p)->heapId);
}

void POKETRADE_2D_DeleteMarkingIcon(void *p)
{
    if (((struct PokemontradeUiScene *)p)->actor) {
        CLACT_DeleteActor((struct ClactActor *)(((struct PokemontradeUiScene *)p)->actor));
        UI_SCENE_FreeActorGfx(p);
        ((struct PokemontradeUiScene *)p)->actor = 0;
    }
}

/*
 * interface: x is narrowed to u8 at 021E5FE4/021E5FEC although ov067's callee declares u16.
 * initialization: ov067 UI_SCENE_LoadActorGfx reads only the seven words and bytes 1c..1e initialized below.
 * domain: call 021E1F20 loads side from the 0/1 slot initialized at 021E1E20/021E1E2C; call 021E2406 sets side=0 at 021E2400. Thus side*128+108 is 108 or 236.
 */
void POKETRADE_2D_CreatePokerusIcon(char *p, int side, int flag, void *mon)
{
    char *q = p + 0x964;
    ActorGfxDesc in;
    u32 a = POKERUS_IsInfected(mon);
    if (((struct PokemontradeUiScene *)q)->actor) {
        if (!a) CLACT_SetActorDrawEnable((struct ClactActor *)((struct PokemontradeUiScene *)q)->actor,0);
        else CLACT_SetActorDrawEnable((struct ClactActor *)((struct PokemontradeUiScene *)q)->actor,1);
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
    UI_SCENE_LoadActorGfx((ActorGfxSet *)q, (ActorGfxDesc *)&in, (void *)(((TradeWork *)p)->clactSystem), ((TradeWork *)p)->heapId);
    if (flag) ((struct PokemontradeUiScene *)q)->actor = (void *)UI_SCENE_CreateActor( (ActorGfxSet *)q, (void *)(((TradeWork *)p)->clactSystem),244,104,0,((TradeWork *)p)->heapId);
    else ((struct PokemontradeUiScene *)q)->actor = (void *)UI_SCENE_CreateActor( (ActorGfxSet *)q, (void *)(((TradeWork *)p)->clactSystem), (u8)(side*128+108),24,0,((TradeWork *)p)->heapId);
}

/*
 * lever: caller truncates x to u8 despite callee's wider x type.
 */
void POKETRADE_2D_CreateCuredPokerusIcon(char *p, int b, void *c)
{
    char *q = p + 0x978;
    ActorGfxDesc in;
    int a = POKERUS_IsCured(c);
    if (a == 0) return;
    if (((struct PokemontradeUiScene *)q)->actor) {
        if (a == 0) CLACT_SetActorDrawEnable((struct ClactActor *)((struct PokemontradeUiScene *)q)->actor, 0);
        else CLACT_SetActorDrawEnable((struct ClactActor *)((struct PokemontradeUiScene *)q)->actor, 1);
        return;
    }
    in.screen = 1; in.plttSlot = 14; in.flags = 0;
    in.arcId = APP_ICON_GetArchiveId();
    in.charId = APP_ICON_GetBallOpenAnimFileId();
    in.plttId = APP_ICON_GetEffectCellFileId(2);
    in.cellId = APP_ICON_GetEffectPaletteFileId(2);
    in.animId = APP_ICON_GetEffectAnimFileId(2);
    in.charBase = 0; in.charSize = 1;
    UI_SCENE_LoadActorGfx((ActorGfxSet *)q, (ActorGfxDesc *)&in, (void *)(((TradeWork *)p)->clactSystem), ((TradeWork *)p)->heapId);
    ((struct PokemontradeUiScene *)q)->actor = (void *)UI_SCENE_CreateActor( (ActorGfxSet *)q, (void *)(((TradeWork *)p)->clactSystem), (u8)(108 + b * 128), 20, 13, ((TradeWork *)p)->heapId);
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
void POKETRADE_2D_CreateSummaryIcons(char *p,void *mon,int flag)
{
    ActorGfxDesc in;
    Pokemontrade2dCoords coords;
    States states;
    int offOwner,offStore,offLoad,offSprite;
    u32 bits;
    long i;
    int state; sptr sprite;
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
    if (!((TradeWork *)p)->subScreenActive) {
        UI_SCENE_LoadActorGfx((ActorGfxSet *)((void *)(p+0x98c)), (ActorGfxDesc *)&in, (void *)(((TradeWork *)p)->clactSystem), ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->subScreenActive=1;
    }
    offOwner=0x98c+0x38;
    offStore=0x98c+0x14;
    offLoad=0x98c+0x14;
    offSprite=0x98c+0x14;
    for (i=0;i<8;i++) {
        sprite=*(int *)((const u8 *)p+(unsigned long)i*4+offSprite);
        if (bits&(1<<i)) { row=states.v[(unsigned)i]; state=states.v[i][0]; }
        else { row=states.v[i]; state=row[1]; }
        if (sprite) {
            if (state==-1) CLACT_SetActorDrawEnable((struct ClactActor *)sprite,0);
            else if (flag && i==6) CLACT_SetActorDrawEnable((struct ClactActor *)sprite,0);
            else { CLACT_SetActorAnimSeq((struct ClactActor *)sprite,state); CLACT_SetActorDrawEnable((struct ClactActor *)sprite,1); }
        } else {
            *(void **)(p+(unsigned long)i*4+offStore)=UI_SCENE_CreateActor((ActorGfxSet *)(p+0x98c),(void *)*(int *)(p+offOwner),(u8)(coords.v[(unsigned long)i]*8),101,state==-1?row[0]:state,((TradeWork *)p)->heapId);
            sprite=*(int *)(p+(unsigned long)i*4+offLoad);
            if (state==-1) CLACT_SetActorDrawEnable((struct ClactActor *)sprite,0);
            else if (flag && i==6) CLACT_SetActorDrawEnable((struct ClactActor *)sprite,0);
        }
    }
}

void POKETRADE_2D_DeleteSummaryIcons(void *p)
{
    char *q = (char *)p + 0x98c;
    int i;
    for (i = 0; i < 8; i++) {
        if (*(int *)(q + i * 4 + 0x14)) {
            CLACT_DeleteActor((struct ClactActor *)(*(int *)(q + i * 4 + 0x14)));
            *(int *)(q + i * 4 + 0x14) = 0;
        }
    }
    if (((struct PokemontradeUiScene *)q)->actor) {
        UI_SCENE_FreeActorGfx((ActorGfxSet *)q);
        ((struct PokemontradeUiScene *)q)->actor = 0;
    }
}

void POKETRADE_2D_UploadWindowPalette(char *p, int n, u32 x) {
    int offset = n * 32;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,x,offset,32,((TradeWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchive(APP_ICON_GetArchiveId(),31,x,28,offset+28,4,((TradeWork *)p)->heapId);
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
void POKETRADE_2D_CreateOfferIconActor(char *p,int i,int j,void *mon,int selected,u32 visible)
{
    struct ActorInitParam c;
    void *q = POKE_TOOL_CastToBoxParam(mon);
    void *h = ARC_TOOL_CreateHandle(7,((TradeWork *)p)->heapId);
    int n;
    POKETRADE_2D_DeleteOfferIconActor((TradeWork *)p, i, j);
    if (selected) {
        c.x=gOfferIconPosA[i*3+j][0]; c.y=gOfferIconPosA[i*3+j][1]; n=0;
    } else {
        c.x=gOfferIconPosB[i*3+j][0]; c.y=gOfferIconPosB[i*3+j][1]; n=1;
    }
    c.anim_seq=1; c.draw_priority=16; c.bg_priority=1;
    *(int *)(p+0x1020+i*12+j*4) = CLACT_RegisterCharacter((void *)((uptr)h),POKE_TOOL_GetGraphicIndex(q),0,n,((TradeWork *)p)->heapId);
    *(int *)(p+0x1008+i*12+j*4) = (sptr)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,*(int *)(p+0x1020+i*12+j*4),*(int *)&((TradeWork *)p)->iconPaletteComp,*(int *)&((TradeWork *)p)->cellAnimF,&c,n,((TradeWork *)p)->heapId);
    CLACT_SetActorPaletteOffset((struct ClactActor *)(*(int *)(p+0x1008+i*12+j*4)),POKE_TOOL_GetIconPalette(q),1);
    CLACT_SetActorAutoAnim((struct ClactActor *)*(int *)(p+0x1008+i*12+j*4),0);
    CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)(p+0x1008+i*12+j*4),visible);
    ARC_TOOL_DeleteHandle((void *)((sptr)h));
}

void POKETRADE_2D_UpdateOfferIconHighlight(void *p, int a, int b) {
    int i,j;
    PointS16 pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (((TradeWork *)p)->offerIconActor[i][j]) {
                pos.x=gOfferIconPosB[i*3+j][0]; pos.y=gOfferIconPosB[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->offerIconActor[i][j]),(const struct ClactVec2 *)(&pos),1);
            }
        }
    }
}

void POKETRADE_2D_DeleteAllOfferIconActors(void *p)
{
    int j, i;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            POKETRADE_2D_DeleteOfferIconActor((TradeWork *)p, i, j);
}

void POKETRADE_2D_CreateFloatingIconActor(int p, int i, int j, int x, int y, void *q) {
    struct ActorInitParam c;
    c.x=x; c.y=y; c.anim_seq=1; c.draw_priority=0; c.bg_priority=0;
    ((TradeWork *)p)->iconActorC=CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,*(int *)(p+i*20+j*4+0x9cc),(*(int *)&((TradeWork *)p)->iconPalette),(*(int *)&((TradeWork *)p)->cellAnimC),&c,1,((TradeWork *)p)->heapId);
    CLACT_SetActorPaletteOffset((struct ClactActor *)(((TradeWork *)p)->iconActorC),POKE_TOOL_GetIconPalette(q),1);
}

static inline int mul(int a,int b) { return (int)(((s64)a*b+0x800LL)>>12); }

/*
 * initialization: 0204B454 writes both signed coordinates; all four vector arguments are fully assigned before 021E7248 reads each three-word object.
 * arithmetic: coordinate products fit signed32 for every signed-short input; fixed-point scalar sums use modulo32 ADD. Signed32 products plus 0x800 fit signed64 for every possible input.
 */
void POKETRADE_2D_StartIconFlight(char *p)
{
    VecFx32 end,third,second,first;
    PointS16 pos;
    int x,y,dx,dy,speed;
    CLACT_GetActorSurfacePos((struct ClactActor *)(*(void * *)&((TradeWork *)p)->iconActorC),(struct ClactVec2 *)&pos,1);
    dx=(pos.x-((TradeWork *)p)->originX)*4096;
    dy=(pos.y-((TradeWork *)p)->originY)*4096;
    first.x=pos.x*4096; first.y=pos.y*4096; first.z=0;
    second.x=(pos.x*2-((TradeWork *)p)->originX)*4096;
    second.y=(pos.y*2-((TradeWork *)p)->originY)*4096; second.z=0;
    end.x=28*4096; end.y=0; end.z=0;
    x=first.x-end.x; y=first.y/2;
    speed=FX_Sqrt((int)((u32)mul(x,x)+(u32)mul(y,y)))/15;
    third.x=(int)((u32)x+(u32)mul(dx,speed)); third.y=(int)((u32)y+(u32)mul(dy,speed)); third.z=0;
    POKETRADE_2D_InitBezierCurve(&((TradeWork *)p)->bezierCurve,&first,&second,&third,&end,19);
    ((TradeWork *)p)->flightTimer=21;
}

int POKETRADE_2D_UpdateIconFlight(char *p) {
    PointS16 pos;
    if (((TradeWork *)p)->flightTimer) {
        --((TradeWork *)p)->flightTimer;
        if (!((TradeWork *)p)->flightTimer) return 1;
        CLACT_GetActorSurfacePos((struct ClactActor *)((TradeWork *)p)->iconActorC,(struct ClactVec2 *)&pos,1);
        if (pos.y<0) ((TradeWork *)p)->flightTimer=1;
        if (((TradeWork *)p)->flightTimer==1) POKETRADE_2D_DeleteFloatingIconActor(p);
        else {
            POKETRADE_2D_StepBezierCurve(&((TradeWork *)p)->bezierCurve);
            pos.x=((TradeWork *)p)->bezierCurve.out.x/4096;
            pos.y=((TradeWork *)p)->bezierCurve.out.y/4096;
            CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->iconActorC),(const struct ClactVec2 *)(&pos),1);
        }
    }
    return 0;
}

void POKETRADE_2D_DeleteFloatingIconActor(void *p)
{
    if (((TradeWork *)p)->iconActorC) {
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)p)->iconActorC));
        ((TradeWork *)p)->iconActorC = 0;
    }
}

void POKETRADE_2D_SetupSubBlend(void *p)
{
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR, 0, 15, 8, 8);
}

void POKETRADE_2D_CreateMarkerActor(char *p, int i) {
    struct ActorInitParam c;
    if (!*(int *)(p+0x10bc+i*4)) {
        c.x=i*24+8; c.y=144; c.anim_seq=i+11; c.draw_priority=50; c.bg_priority=1;
        *(int *)(p+0x10bc+i*4)=(sptr)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,((TradeWork *)p)->actorChar,((TradeWork *)p)->actorPalette,((TradeWork *)p)->actorCellAnim,&c,1,((TradeWork *)p)->heapId);
    }
    CLACT_SetActorAutoAnim((struct ClactActor *)*(int *)(p+0x10bc+i*4),1);
    CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)(p+0x10bc+i*4),1);
}

void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)((char *)p + i * 4 + 0x10bc), a);
}

void POKETRADE_2D_DeleteMarkerActor(void *p, int i)
{
    if (*(int *)((char *)p + 0x10bc + i * 4)) {
        CLACT_DeleteActor((struct ClactActor *)(*(int *)((char *)p + 0x10bc + i * 4)));
        *(int *)((char *)p + 0x10bc + i * 4) = 0;
    }
}

void POKETRADE_2D_SetMarkerActorAnim(void *p, int i)
{
    CLACT_SetActorAnimSeq((struct ClactActor *)(*(int *)((char *)p + i * 4 + 0x10bc)), (u16)(i + 15));
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

static inline void clear(int p, int i) {
    if (*(int *)(p+i*4+0x10ac)) {
        CLACT_DeleteActor((struct ClactActor *)(*(int *)(p+i*4+0x10ac)));
        *(int *)(p+(unsigned int)i*4+0x10ac)=0;
    }
}

/*
 * lever: unsigned cast on the store index prevents address CSE with the signed read index; without it 56 bytes, 37 byte DIFF.
 */
void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n) {
    int i=n*2;
    clear(p,i+1);
    clear(p,i);
}

void POKETRADE_2D_MovePickedIconActor(void *p, int i) {
    PointTable6 t=gPickedIconPath;
    struct ActorInitParam c;
    if(i==-1) {
        if(((TradeWork *)p)->pickedIconActor) CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->pickedIconActor,0);
    } else {
        if(!((TradeWork *)p)->pickedIconActor) {
            c.x=64;c.y=48;c.anim_seq=23;c.draw_priority=0;c.bg_priority=1;
            ((TradeWork *)p)->pickedIconActor=CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,((TradeWork *)p)->actorChar,((TradeWork *)p)->actorPalette,((TradeWork *)p)->actorCellAnim,&c,1,((TradeWork *)p)->heapId);
        }
        CLACT_SetActorAutoAnim((struct ClactActor *)((TradeWork *)p)->pickedIconActor,1);
        CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->pickedIconActor,1);
        CLACT_AddActorSurfacePos((struct ClactActor *)(((TradeWork *)p)->pickedIconActor),(const struct ClactVec2 *)(&t.pos[i]),1);
    }
}

void POKETRADE_2D_DeletePickedIconActor(char *p)
{
    if (((TradeWork *)p)->pickedIconActor) {
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)p)->pickedIconActor));
        ((TradeWork *)p)->pickedIconActor = 0;
    }
}

/*
 * output: 0204B454 writes both halfwords via 0204B53C and 0204CF74/0204B0C8.
 * interface: 02040618 forwards legacy r3 only to 02042360, whose full body
 *            has three inputs and does not read it; caller supplies r0-r2.
 */
int POKETRADE_2D_StepCursorSlide(char *p)
{
    PointS16 a,b,c;
    int i;
    if(((TradeWork *)p)->fadeLevel<128) ((TradeWork *)p)->fadeLevel+=4;
    else return 1;
    for(i=0;i<8;i++) {
        CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x10cc),(struct ClactVec2 *)&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x10cc),(const struct ClactVec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(((TradeWork *)p)->offerIconActor[0][i]) {
            CLACT_GetActorSurfacePos(((TradeWork *)p)->offerIconActor[0][i],(struct ClactVec2 *)&b,1);
            b.x-=4;
            CLACT_AddActorSurfacePos(((TradeWork *)p)->offerIconActor[0][i],(const struct ClactVec2 *)(&b),1);
        }
    }
    for(i=0;i<3;i++) {
        if(((TradeWork *)p)->offerIconActor[1][i]) {
            CLACT_GetActorSurfacePos(((TradeWork *)p)->offerIconActor[1][i],(struct ClactVec2 *)&c,1);
            c.x+=4;
            CLACT_AddActorSurfacePos(((TradeWork *)p)->offerIconActor[1][i],(const struct ClactVec2 *)(&c),1);
        }
    }
    BG_SYS_ChangeScrollImmediate(5,0,-((TradeWork *)p)->fadeLevel);
    BG_SYS_ChangeScrollImmediate(4,0,((TradeWork *)p)->fadeLevel-128);
    return 0;
}

/*
 * lever: split temporary for first loop base and second loop index; 10-byte
 *         register swap without them. Permuter budget 300, 271 compiles.
 * output: 0204B454 and its full getter chain write both coordinate halfwords.
 */
void POKETRADE_2D_SetCursorSlidePositions(const char *p)
{
    int i,j;
    PointS16 a,b,c;
    int tmp;
    const char *actorSlot;
    for(i=0;i<8;i++) {
        actorSlot=p+i*4;
        actorSlot=actorSlot+0x10cc;
        CLACT_GetActorSurfacePos(*(void **)actorSlot,(struct ClactVec2 *)&a,1);
        if(i/4) {
            a.x-=128;
            CLACT_SetActorBgPriority(*(void **)(p+i*4+0x10cc),3);
        } else a.x+=128;
        CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x10cc),(const struct ClactVec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1008),(struct ClactVec2 *)&b,1);
            b.x+=128;
            tmp=i;
            tmp=tmp*4;
            CLACT_AddActorSurfacePos(*(void **)(p+tmp+0x1008),(const struct ClactVec2 *)(&b),1);
        }
    }
    for(j=0;j<3;j++) {
        if(*(void **)(p+j*4+0x1014)) {
            CLACT_GetActorSurfacePos(*(void **)(p+j*4+0x1014),(struct ClactVec2 *)&c,1);
            c.x-=128;
            CLACT_AddActorSurfacePos(*(void **)(p+j*4+0x1014),(const struct ClactVec2 *)(&c),1);
            CLACT_SetActorBgPriority(*(void **)(p+j*4+0x1014),3);
        }
    }
    BG_SYS_SetPriority(4,2);
    BG_SYS_SetPriority(5,3);
}

void POKETRADE_2D_SetupCursorBg(char *p)
{
    void *h;
    struct BgTemplate t;
    (*(void * *)&((TradeWork *)p)->fontBgHandle) = BMP_MENUWORK_LoadFrameGfx((unsigned int)6, 15, 0, ((TradeWork *)p)->heapId);
    h = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->mainBgHandle = ARC_UTIL_RegisterObjCharFromHandle(h, 13, 5, 0, 0, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 4, 0, (u16)((TradeWork *)p)->mainBgHandle, 0, 0, ((TradeWork *)p)->heapId);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 7, 5, 0, (u16)((TradeWork *)p)->mainBgHandle, 0, 0, ((TradeWork *)p)->heapId);
    t = gCursorBgTemplate;
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_InitBgLayer(7, &t, 0);
#ifdef __MWERKS__
    /* The original prototype returned void. */
    ((void (*)(void *, u32, u32, u32, u32, u32, u32, u16))ARC_UTIL_UploadBgPaletteAddFromHandle)(h, 8, 7, 0, (u16)((TradeWork *)p)->mainBgHandle, 0, 0, ((TradeWork *)p)->heapId);
#else
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 8, 7, 0, (u16)((TradeWork *)p)->mainBgHandle, 0, 0, ((TradeWork *)p)->heapId);
#endif
    BG_SYS_ChangeScrollImmediate(4, 0, -0x80);
    BG_SYS_ChangeScrollImmediate(7, 0, 0);
    BG_SYS_SetPriority(4, 3);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 11, 2, 0, (u16)(*(unsigned int *)&((TradeWork *)p)->subBgHandle), 0, 0, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(h);
    (*(unsigned short *)&((TradeWork *)p)->fadeLevel) = 0;
    POKETRADE_2D_SetCursorSlidePositions(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}

void POKETRADE_2D_CreateOfferWindows(char *p)
{
    PointTable8 t = gOfferWindowPos;
    void *h = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    struct ActorInitParam c;
    int i;
    (*(unsigned int *)&((TradeWork *)p)->paletteE) = CLACT_RegisterPaletteEx(h, 0, 1, 0x1c0, 0, 1, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->cellAnimG = CLACT_RegisterCellAnim(h, 2, 1, ((TradeWork *)p)->heapId);
    for (i = 0; i < 8; i++) {
        *(void **)(p + i * 4 + 0x10f4) = BMP_Create(16, 6, 32, ((TradeWork *)p)->heapId);
        *(u32 *)(p + i * 4 + 0x1114) = CLACT_RegisterCharacter(h, 3, 0, 1, ((TradeWork *)p)->heapId);
    }
    for (i = 0; i < 8; i++) {
        c.x = *(short *)((char *)&t + i * 4); c.y = *(short *)((char *)&t + i * 4 + 2); c.anim_seq = 0; c.draw_priority = 0; c.bg_priority = 1;
        *(int *)(p + i * 4 + 0x10cc) = (sptr)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem, *(int *)(p + i * 4 + 0x1114), *(int *)(p + 0x10ec), *(int *)(p + 0x10f0), &c, 1, ((TradeWork *)p)->heapId);
        CLACT_SetActorDrawEnable((struct ClactActor *)*(int *)(p + i * 4 + 0x10cc), 1);
    }
    ARC_TOOL_DeleteHandle(h);
}

void POKETRADE_2D_DeleteOfferWindowActors(char *p) {
    int i;
    for (i=0;i<8;i++) {
        if (*(int *)(p+i*4+0x10cc)) {
            CLACT_DeleteActor((struct ClactActor *)(*(int *)(p+i*4+0x10cc)));
            *(int *)(p+i*4+0x10cc)=0;
            BMP_Delete(*(void **)(p+i*4+0x10f4));
            *(int *)(p+i*4+0x10f4)=0;
            CLACT_ReleaseCharacter(*(int *)(p+i*4+0x1114));
            *(int *)(p+i*4+0x1114)=0;
        }
    }
    if (((TradeWork *)p)->paletteE) {CLACT_ReleasePalette(((TradeWork *)p)->paletteE);((TradeWork *)p)->paletteE=0;}
    if (((TradeWork *)p)->paletteE) {CLACT_ReleaseCellAnim(((TradeWork *)p)->cellAnimH);((TradeWork *)p)->paletteE=0;}
}

void POKETRADE_2D_UpdateOfferWindowActors(char *p) {
    ByteTable8 t=gOfferWindowActorTable;
    int i,j;
    char *dest,*source;
    for(i=0;i<8;i++) {
        dest=(char *)CLACT_GetCharacterVramAddress(*(int *)(p+i*4+0x1114),1);
        source=BMP_GetPixels((const struct Bmp *)(*(int *)(p+i*4+0x10f4)));
        DC_FlushRange(source,BMP_GetByteSize((const struct Bmp *)(*(int *)(p+i*4+0x10f4))));
        for(j=0;j<8;j++) {GXS_LoadOBJ(source+t.v[j]*256,(uptr)dest,256);dest+=256;}
    }
}

void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon)
{
    void *h = ARC_TOOL_CreateHandle(0x66, ((TradeWork *)p)->heapId);
    void *f;
    Pal *pal;
    u16 *d;
    u32 i;
    if (side == 0)
        f = ARC_UTIL_LoadPaletteDataFromHandle(h, 5, 0, (void **)&pal, ((TradeWork *)p)->heapId);
    else
        f = ARC_UTIL_LoadPaletteDataFromHandle(h, 6, 0, (void **)&pal, ((TradeWork *)p)->heapId);
    d = pal->data;
    for (i = 0; i < pal->size / 2; i++)
        d[i] += (u16)((TradeWork *)p)->subBgHandle;
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

void POKETRADE_2D_OnCursorAnimDone(char *p) { p[0x11f5]=1; }

void POKETRADE_2D_CreateCursorActor(char *p, int x, int y) {
    Pokemontrade2dCallback cb;
    struct ActorInitParam c;
    c.x=x+12;c.y=y+12;c.anim_seq=24;c.draw_priority=0;c.bg_priority=0;
    POKETRADE_2D_DeleteCursorActor(p);
    ((TradeWork *)p)->iconActorD=CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,((TradeWork *)p)->actorChar,((TradeWork *)p)->actorPalette,((TradeWork *)p)->actorCellAnim,&c,1,((TradeWork *)p)->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)((TradeWork *)p)->iconActorD,1);
    CLACT_SetActorAutoAnim((struct ClactActor *)((TradeWork *)p)->iconActorD,1);
    p[0x11f5]=0;
    cb.v=0;cb.p=p;cb.fn=(void (*)(void *))POKETRADE_2D_OnCursorAnimDone;
    CLACT_ApplyActorAnimCommand((struct ClactActor *)(((TradeWork *)p)->iconActorD),(const struct ClactAnimCommand *)(&cb));
}

void POKETRADE_2D_DeleteCursorActor(void *p)
{
    if (((TradeWork *)p)->iconActorD) {
        CLACT_DeleteActor((struct ClactActor *)(((TradeWork *)p)->iconActorD));
        ((TradeWork *)p)->iconActorD = 0;
        *((char *)p + 0x11f5) = 0;
    }
}

int POKETRADE_2D_ClearCursorIfDisabled(void *p)
{
    if (*((unsigned char *)p + 0x11f5)) {
        POKETRADE_2D_DeleteCursorActor(p);
        return 0;
    }
    return 1;
}

/*
 * interface: 02021540 forwards live r0 to 020307B0, so caller passes s.
 */
void POKETRADE_2D_FadePaletteBank(char *p, int bank, int mask)
{
    PaletteFade *s;
    char *buf;
    int i;
    int off;
    s=PALANM_Create(((TradeWork *)p)->heapId);
    PALANM_AllocSlotBuffers(s,bank,0x200,((TradeWork *)p)->heapId);
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

void POKETRADE_2D_FadePaletteCopy(void *p, int capture, int bank, int mask)
{
    if (capture != 0) {
        if (bank == 3)
            MI_CpuCopy8((void *)HW_DB_OBJ_PLTT, ((TradeWork *)p)->subObjPaletteCopy,
                          0x200);
        else if (bank == 1)
            MI_CpuCopy8((void *)HW_DB_BG_PLTT, ((TradeWork *)p)->subBgPaletteCopy,
                          0x200);
        POKETRADE_2D_FadePaletteBank(p, bank, mask);
        return;
    }
    if (bank == 3) {
        DC_FlushRange(((TradeWork *)p)->subObjPaletteCopy, 0x200);
        GXS_LoadOBJPltt(((TradeWork *)p)->subObjPaletteCopy, 0, 0x200);
        return;
    }
    if (bank == 1) {
        DC_FlushRange(((TradeWork *)p)->subBgPaletteCopy, 0x200);
        GXS_LoadBGPltt(((TradeWork *)p)->subBgPaletteCopy, 0, 0x200);
    }
}

void POKETRADE_2D_FadePaletteAll(void *p, int a)
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
    TCB_AddTask((struct TcbSystem *)GFL_USE_GetMainTaskList(), (TcbFunc)((void (*)(void))POKETRADE_2D_TaskSetMainPlaneVisible), (void *)a, 0xa);
}

void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a)
{
    TCB_AddTask((struct TcbSystem *)GFL_USE_GetMainTaskList(), (TcbFunc)((void (*)(void))POKETRADE_2D_TaskSetSubPlaneVisible), (void *)a, 0xa);
}

void POKETRADE_2D_TaskSetMainPlaneVisible(void *p, int a)
{
    BG_SYS_SetMainVisiblePlanes(a);
    TCB_DeleteTask(p);
}

void POKETRADE_2D_TaskSetSubPlaneVisible(void *p, int a)
{
    BG_SYS_SetSubVisiblePlanes(a);
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
