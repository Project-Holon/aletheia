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
 *   func_02007A18  0x02007A18  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02017E88 0x02017E88 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_020355C4 0x020355C4 arm
 *   func_02040588 0x02040588 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   func_02049B40 0x02049B40 arm
 *   func_02040618 0x02040618 arm
 *   func_02030734 0x02030734 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02017DBC 0x02017DBC thumb
 *   func_02017DE4 0x02017DE4 thumb
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   func_020275E4  0x020275E4  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02049990 0x02049990 arm
 *   POKETRADE_PROC_GetBoxIndexForSlot 0x021D8AF4 thumb ov119
 *   POKETRADE_PROC_GetSlotIndexInBox 0x021D8B0C thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   func_02041300 0x02041300 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   BMP_Clear 0x02043B5C arm
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   CLACT_InitSystem  0x0204A48C  arm
 *   d_021E7CE4     0x021E7CE4  data  ov119
 *   d_021E7D40     0x021E7D40  data  ov119
 *   d_021E7CC8     0x021E7CC8  data  ov119  a4
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   d_021E7DD0 0x021E7DD0 data a4
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   func_02042FB0 0x02042FB0 arm
 *   ARC_TOOL_LoadMember  0x02048F60  arm
 *   func_0200785C 0x0200785C thumb
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   BMP_WIN_SetPosX 0x02045780 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   POKETRADE_PROC_LoadSlotMonAlt 0x021D8DD0 thumb ov119
 *   POKETRADE_PROC_GetSlotMonPtr 0x021D8E24 thumb ov119
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   d_021E82A4 0x021E82A4 data
 *   CLACT_GetActorImageProxy 0x0204B7C8 arm
 *   func_02061CA4 0x02061CA4 arm
 *   POKE_TOOL_GetIconPalette 0x0201BBE8 thumb
 *   func_02049DF4 0x02049DF4 arm
 *   d_021E8530 0x021E8530 data a4
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   d_021E7E24 0x021E7E24 data a4
 *   d_021E7F44 0x021E7F44 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   POKE_TOOL_GetGraphicIndex  0x0201BA68  thumb  arm9
 *   CLACT_SetActorObjMode  0x0204B688  arm  arm9
 *   POKETRADE_NEGO_IsMonOwnOffer 0x021DF614 thumb ov119
 *   POKETRADE_NEGO_IsMonPeerSelected 0x021DF6B4 thumb ov119
 *   POKETRADE_SAVE_DeleteOfferStatusIcons 0x021E1CA8 thumb ov119
 *   BG_SYS_SetLowBit 0x0204044C arm
 *   func_0204047C 0x0204047C arm
 *   d_021E7F24 0x021E7F24 data a4
 *   d_021E7E84 0x021E7E84 data a4
 *   d_021E7EA4 0x021E7EA4 data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   d_021E7D00 0x021E7D00 data a4
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   d_021E7DE0 0x021E7DE0 data a4
 *   d_021E7CA0 0x021E7CA0 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   d_021E7C94 0x021E7C94 data a4
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021E7EE4 0x021E7EE4 data a4
 *   d_021E7F04 0x021E7F04 data a4
 *   d_021E7F64 0x021E7F64 data a4
 *   d_021E7E04 0x021E7E04 data a4
 *   func_0203FC28 0x0203FC28 arm
 *   d_021E7D20 0x021E7D20 data a4
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   d_021E81D4 0x021E81D4 data a4
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_02027694 0x02027694 thumb
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   func_020276B4 0x020276B4 thumb
 *   func_020276B8 0x020276B8 thumb
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_02027748 0x02027748 thumb
 *   func_0202774C 0x0202774C thumb
 *   func_02027750 0x02027750 thumb
 *   func_02027754 0x02027754 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017EAC 0x02017EAC thumb
 *   POKERUS_IsCured 0x0201B280 thumb
 *   d_021E7EC4 0x021E7EC4 data a4
 *   d_021E7F84 0x021E7F84 data a4
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   d_021E7D70 0x021E7D70 data a4
 *   d_021E7DA0 0x021E7DA0 data a4
 *   FX_Sqrt 0x0207C7B4 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207D63C 0x0207D63C arm
 *   d_021E7DEC 0x021E7DEC data a2
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   d_021E7E44 0x021E7E44 data a4
 *   POKERUS_IsInfected  0x0201B25C  thumb  arm9
 *   BMP_Create 0x02043678 arm
 *   d_021E7E64 0x021E7E64 data a2
 *   BMP_Delete 0x020437AC arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E804 0x0207E804 arm
 *   d_021E7DD8 0x021E7DD8 data a1
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   func_02041090 0x02041090 arm
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   PALANM_GetTransWork 0x02021730 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   func_020056BC  0x020056BC  thumb
 *   func_02030EAC 0x02030EAC arm
 *   FX_Div   0x0207C768  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   FILE_UTIL_Check136C  0x0202136C  thumb  arm9
 */
#include "pokemontrade_types.h"

#define FX32_ONE 4096
#define FX_MUL(v1, v2) ((fx32)(((fx64)(v1) * (v2) + 0x800LL) >> 12))
#define FX_INT_TO_FX32(x) ((fx32)(((x) > 0) ? ((float)((x) << 12) + .5f) \
                                            : ((float)((x) << 12) - .5f)))
struct Struct36;
struct DispVram;
struct Light;
struct DispConfig;
struct Obj;
struct Vec2;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Actor;
struct PtS;
struct BezierCurve;
struct Bmp;
struct Obj020437AC;
struct Cmd;
struct Chan02021FD8;
struct PalAnmSlot;
struct Node;
typedef signed short s16;

typedef signed int s32;

typedef signed long long s64;

typedef struct { unsigned int w[2]; } Tbl2;

typedef struct {
    char pad00[0x24];
    u16 v[0x300];       /* 0x024 */
} Buf;

typedef struct { u16 x, y, prio; u8 pal, mode; } ObjTmpl;

typedef struct { u16 id; u8 b2, b3; } Ent;

typedef struct { short x, y; } PointS16;

typedef struct { int a, b, c, d[6]; } Info;

typedef struct Object {u8 pad[0xac0];void *actors[12][5];} Object;

typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;

typedef enum { SHADING_TOON, SHADING_HIGHLIGHT } Shading;

typedef struct { int x,y,z; } Vec;

typedef struct { u16 x, y, z; u8 a, b; } Sprite;

typedef struct { u16 x, y; } PointU16;

typedef struct { u32 x, y; } PointU32;

/* Actor graphics descriptor passed to UI_SCENE_LoadActorGfx. */
typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } ActorGfxDesc;

typedef struct { int v[8]; } Coords;

typedef struct { int v[8][2]; } States;

typedef struct { short x,y,z; u8 a,b; } Create;

typedef struct {
    char pad0[0x5f4];
    u16 heap;
    char pad1[0x884-0x5f6];
    int g884;
    char pad2[0x898-0x888];
    int g898;
    char pad3[0x8b4-0x89c];
    int g8b4;
    char pad4[0x9c4-0x8b8];
    int g9c4;
    char pad5[0x10ac-0x9c8];
    int slot[8];
} Work;

typedef struct { PointS16 pos[6]; } PointTable6;

typedef struct { PointS16 pos[8]; } PointTable8;

typedef struct { u8 v[8]; } ByteTable8;

typedef struct { u32 f0, f4, size; u16 data[1]; } Pal;

typedef struct { short v; void *p; void (*fn)(void *); } Callback;

typedef struct { void *a, *b; u32 size, c, d; } Slot;

typedef signed char        s8;

typedef s32 fx32;

typedef s64 fx64;

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u8 func_020355C4(void);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0201BC3C(void);
extern int func_0201BC78(void);
extern int func_0201BCB4(void);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02045CAC(struct MsgBank *,unsigned,void *);
extern u32 func_020307B0(void *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern int POKETRADE_PROC_GetBoxIndexForSlot(int,char *);
extern int POKETRADE_PROC_GetSlotIndexInBox(int,int);
extern int POKETRADE_PROC_IsHostSide(void *);
extern void func_02041B6C(u32 bit);
extern void func_02041300(int,int,unsigned char,int,int,int,int);
extern void MI_CpuCopy8(const void *,void *,unsigned);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void CLACT_DeleteActor(struct Obj *p);
extern u32 func_020275E4(void);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 BMP_WIN_Create(u32 layer, u8 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *h);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void *func_020185F0(void *);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02027618(void);
extern u32 func_02027614(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void BG_SYS_ClearSlot(u32 i);
extern void func_02042FB0(u32 idx, u32 x, u32 y, u16 value);
extern void *ARC_TOOL_LoadMember(u32 archive_id, u32 member, u32 heap);
extern void func_0200785C(void *,u32,void *);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
extern void BMP_WIN_SetPosX(struct Descriptor *p, u8 v);
extern int CLACT_RegisterPaletteCompressed(void *a0, unsigned int a1, unsigned int a2, unsigned int a3, u16 a4);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void *POKETRADE_PROC_LoadSlotMonAlt(void *a, int b, int c, char *p);
extern char *POKETRADE_PROC_GetSlotMonPtr(int, int, char *);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_GetActorImageProxy(const char *src, struct Struct36 *dst);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern int POKE_TOOL_GetIconPalette(void *a0);
extern void CLACT_SetActorDrawPriority(int, u8);
extern unsigned int POKE_TOOL_GetGraphicIndex(void *mon);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void BG_SYS_InitBgLayer(u32,const BgTemplate *,u32);
extern void BG_SYS_Init(u32,u32,u32,u32);
extern void func_020409B4(u32);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
int POKETRADE_NEGO_IsMonOwnOffer(char *p,int a,int b);
int POKETRADE_NEGO_IsMonPeerSelected(char *p, int a, int b);
void POKETRADE_SAVE_DeleteOfferStatusIcons(char *p);
extern void BG_SYS_SetLowBit(u32);
extern void func_0204047C(int,u16);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_Init(int,int,int,int,u16,u16,void (*)(void));
extern int G3D_CAMERA_Create(int,int,int,int,int,int,int,int,const Vec *,const Vec *,const Vec *,u16);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void func_0203FC28(struct DispConfig *cfg);
extern void *POKETRADE_PROC_GetSideMon(void *p, int a);
extern void *POKE_TOOL_GetBoxParam(void *a);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 FILE_UTIL_Check136C(u16);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern void UI_SCENE_LoadActorGfx(void *,ActorGfxDesc *,int,u16);
extern int UI_SCENE_CreateActor(void *,int,u8,u8,u8,u16);
extern void UI_SCENE_FreeActorGfx(unsigned int *p);
extern u32 POKERUS_IsInfected(void *);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32);
extern u32 func_020276C0(u32);
extern unsigned int POKERUS_IsCured(void *a);
extern int func_02027748(void);
extern int func_0202774C(int);
extern int func_02027750(int);
extern int func_02027754(int);
extern u32 func_02017EAC(void *);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern int FX_Sqrt(int);
extern void func_0207D63C(int, int, int, int, int);
extern void CLACT_SetActorBgPriority(void *,unsigned int);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_Delete(struct Obj020437AC *p);
extern int CLACT_GetCharacterVramAddress(unsigned int idx, unsigned int flag);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void DWCi_ScreenDC_FlushRange(void *,int);
extern void func_0207E804(const void *,void *,unsigned int);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const struct Cmd *cmd);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *,int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_0207E5D0(void *,u32,u32);
extern void func_0207E468(void *,u32,u32);
extern void GX_LoadOBJPltt(void *,u32,u32);
extern void GX_LoadBGPltt(void *,u32,u32);
extern u32 func_020056BC(void);
extern void func_02030DA8(u32, void (*)(void), int, int);
extern void func_02030EAC(struct Node *n);
extern u32 FX_Div(u32 a, u32 b);
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
void POKETRADE_2D_LoadSummaryBackground(char *p, int a1, int a2);
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
void POKETRADE_2D_SetIconObjMode(int a0, int a1, int a2);
void POKETRADE_2D_UpdateIconObjMode(char *p, int a1, int a2, int a3, int a4, int a5);
void POKETRADE_2D_CreateBoxIcon(char *p, int v, int a, int row, int flag);
int POKETRADE_2D_GetScrollColumn(char *p);
int POKETRADE_2D_GetVisibleColumnRange(char *p, int *out);
void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
void POKETRADE_2D_UpdateBoxIconPositions(char *p);
void POKETRADE_2D_LoadBoxIconGfx(char *p, int b);
s32 POKETRADE_2D_WrapIndex12(s32 x);
void POKETRADE_2D_HideAllBoxIcons(int p);
int POKETRADE_2D_HitTestBoxIcons(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void POKETRADE_2D_SetupSummaryBgs(char *p,int mode);
void POKETRADE_2D_ExitSummaryBgs(int p);
void POKETRADE_2D_InitDisplayAndClact(char *p);
void POKETRADE_2D_SetupMainBgs(void *a0);
void POKETRADE_2D_Setup3DRenderState(void);
void POKETRADE_2D_InitG3DSystem(char *p);
void POKETRADE_2D_SetupSubBgs(char *p);
void POKETRADE_2D_ExitSubBgs(int p);
void POKETRADE_2D_SetDisplayConfig(int i);
void POKETRADE_2D_RegisterMarkerResources(int p);
void POKETRADE_2D_ReleaseMarkerResources(char *p);
void POKETRADE_2D_RegisterIconSpriteResources(int p);
void POKETRADE_2D_LoadMainPalette(int p);
void POKETRADE_2D_CreateTouchbarActors(char *p);
void POKETRADE_2D_PlaceTouchbarActors(int p, int b, int c);
void POKETRADE_2D_DeleteTouchbarActors(int a);
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
void POKETRADE_2D_UpdateOfferIconHighlight(int p, int a, int b);
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
void POKETRADE_2D_CreateMarkerButtonActor(Work *p, int z, int i);
void POKETRADE_2D_DeleteMarkerButtonPair(int p, int n);
void POKETRADE_2D_MovePickedIconActor(int p, int i);
void POKETRADE_2D_DeletePickedIconActor(char *p);
int POKETRADE_2D_StepCursorSlide(char *p);
void POKETRADE_2D_SetCursorSlidePositions(const char *p);
void POKETRADE_2D_SetupCursorBg(char *p);
void POKETRADE_2D_CreateOfferWindows(char *p);
void POKETRADE_2D_DeleteOfferWindowActors(int p);
void POKETRADE_2D_UpdateOfferWindowActors(int p);
void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon);
void POKETRADE_2D_OnCursorAnimDone(char *p);
void POKETRADE_2D_CreateCursorActor(char *p, int x, int y);
void POKETRADE_2D_DeleteCursorActor(void *p);
int POKETRADE_2D_ClearCursorIfDisabled(void *p);
void POKETRADE_2D_FadePaletteBank(char *p, int bank, int mask);
void POKETRADE_2D_FadePaletteCopy(void *p, int a1, int a2, int a3);
void POKETRADE_2D_FadePaletteAll(void *p, int a);
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetMainPlaneVisible(void *p, int a);
void POKETRADE_2D_TaskSetSubPlaneVisible(void *p, int a);
void POKETRADE_2D_InitBezierCurve(struct BezierCurve *d, VecFx32 *a, VecFx32 *b, VecFx32 *c, VecFx32 *dd, int e);
int POKETRADE_2D_StepBezierCurve(struct BezierCurve *c);
extern const char d_021E7CE4[];
extern const char d_021E7D40[];
extern int d_021E7CC8;
extern const Tbl2 d_021E7DD0;
extern const unsigned char d_021E82A4[];
extern char d_021E8530[];
extern const BgTemplate d_021E7E24,d_021E7F44;
extern const BgTemplate d_021E7F24,d_021E7E84,d_021E7EA4;
extern char d_021E7D00[];
extern Vec d_021E7DE0, d_021E7CA0, d_021E7C94;
extern const s16 d_020A1EB8[];
extern const BgTemplate d_021E7EE4,d_021E7F04,d_021E7F64,d_021E7E04;
extern const char d_021E7D20[];
extern PointU32 d_021E81D4[26];
extern const Coords d_021E7EC4;
extern const States d_021E7F84;
extern const int d_021E7D70[6][2];
extern const int d_021E7DA0[6][2];
extern const PointTable6 d_021E7DEC;
extern const BgTemplate d_021E7E44;
extern const PointTable8 d_021E7E64;
extern const ByteTable8 d_021E7DD8;


unsigned char POKETRADE_2D_GetMonMarkingIcon(void *mon, unsigned int heap)
{
    int old;
    unsigned short result;
    int species;
    void *data;
    result = 0;
    old = func_02017DBC(mon);
    species = func_02017E88(mon, 5, 0);
    if (func_02017E88(mon, 0xA9, 0)) {
        if (!func_02017E88(mon, 0x4C, 0)) {
            unsigned short form = func_02017E88(mon, 0x6F, 0);
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
    func_02017DE4(mon, old);
    return result;
}


void POKETRADE_2D_BuildBoxMarkingTable(char *p, int box, unsigned char *out)
{
    unsigned char i;

    for (i = 0; i < 30; i++)
        out[i] = POKETRADE_2D_GetMonMarkingIcon(func_02007A18((*(void * *)&((TradeWork *)p)->gameData), box, i), ((TradeWork *)p)->heapId);
}


void POKETRADE_2D_BuildPartyMarkingTable(char *p, void *party, unsigned char *out)
{
    int count;
    unsigned char i;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < 6; i++) {
        if (count > i)
            out[i] = POKETRADE_2D_GetMonMarkingIcon(func_020185F0(POKEPARTY_GetMember(party, i)), ((TradeWork *)p)->heapId);
        else
            out[i] = 0;
    }
}


int POKETRADE_2D_BuildMarkingTablesFrom(char *p, int i)
{
    while (i < ((TradeWork *)p)->partyBoxId + 1) {
        if (i == ((TradeWork *)p)->partyBoxId) {
            POKETRADE_2D_BuildPartyMarkingTable(p, ((TradeWork *)p)->f838, (unsigned char *)(p + 0x2E0));
            return 1;
        }
        POKETRADE_2D_BuildBoxMarkingTable(p, i, (unsigned char *)(p + 0x10 + i * 30));
        break;
    }
    return 0;
}


/*
 * Unlabelled Thumb tail-call wrapper after pool_021E3E3C, seeded so that
 * ov117 func_021D4BF4 has a witness: forwards the two ov119 tables and the
 * u16 heap id held at +0x5F4 to the ARM function 0x0204A48C.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_InitClactSystemMain(char *p)
{
    CLACT_InitSystem((const struct Cfg *)d_021E7CE4, (u32)d_021E7D40, ((TradeWork *)p)->heapId);
}


/*
 * Tail call: forward the two ov119 data pointers and *(u16*)(p+0x5f4) to
 * the ARM helper. Non-SDK dep of POKETRADE_SAVE_ResetClactAndBeginEvent's preamble.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_InitClactSystemSub(void *p)
{
    CLACT_InitSystem((const struct Cfg *)(&d_021E7CC8), (u32)(&d_021E7D40), ((TradeWork *)p)->heapId);
}


void POKETRADE_2D_LoadBackgroundGfx(char *p)
{
    void *v;
    int kind;
    int mode;
    v = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    mode = POKETRADE_PROC_IsHostSide(p);
    kind = 4;
    if (mode == 0)
        kind = 11;
    func_02049B68(v, 9, 0, 0, 0, ((TradeWork *)p)->heapId);
    if (((TradeWork *)p)->f86C == 0)
        ((TradeWork *)p)->f86C = func_02049740(v, 10, 2, 0, 0, ((TradeWork *)p)->heapId);
    func_02049990(v, kind, (int)2, (int)0, (unsigned short)((*(unsigned int *)&((TradeWork *)p)->f86C)), (int)0, (int)0, (unsigned int)(((TradeWork *)p)->heapId));
    ARC_TOOL_DeleteHandle(v);
}


void POKETRADE_2D_FreeBackgroundPalette(char *p)
{
    u32 v;

    v = (*(unsigned int *)&((TradeWork *)p)->f86C);
    if (v != 0)
        BG_SYS_DeleteHalf((int)2, (u16)v, (u16)(v >> 16));
    (*(unsigned int *)&((TradeWork *)p)->f86C) = 0;
}


void POKETRADE_2D_LoadSubBackgroundGfx(char *p)
{
    void *v;
    v = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    func_02049990(v, 12, (int)4, (int)0, (unsigned short)(((TradeWork *)p)->f870), (int)0, (int)0, (unsigned int)(((TradeWork *)p)->heapId));
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

    v = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    func_02049B68(v, 0x11, 4, 0, 0xC0, ((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->f874) = (void *)func_02049740(v, 0xD, 7, 0, 0, ((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->f870) = (void *)func_02049740(v, 0xD, 5, 0, 0, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(v);
    POKETRADE_2D_LoadBoxScreenData(p, (int)((*(void * *)&((TradeWork *)p)->f874)));
}


void POKETRADE_2D_CreateFontResource(char *p)
{
    (*(void * *)&((TradeWork *)p)->f644) = func_0201F5DC((void *)6, 15, 0, ((TradeWork *)p)->heapId);
}


void POKETRADE_2D_FreeMainResources(char *p)
{
    POKETRADE_2D_FreeBoxScreenData(p);
    if (((TradeWork *)p)->f870) {
        BG_SYS_DeleteHalf((int)5, (unsigned short)(((TradeWork *)p)->f870), (unsigned short)(((TradeWork *)p)->f870 >> 16));
        *(int *)&((TradeWork *)p)->f870 = 0;
    }
    if (((TradeWork *)p)->f874) {
        BG_SYS_DeleteHalf((int)7, (unsigned short)(((TradeWork *)p)->f874), (unsigned short)(((TradeWork *)p)->f874 >> 16));
        *(int *)&((TradeWork *)p)->f874 = 0;
    }
    if (((TradeWork *)p)->f644) {
        BG_SYS_DeleteHalf((int)6, (unsigned short)(((TradeWork *)p)->f644), (unsigned short)(((TradeWork *)p)->f644 >> 16));
        *(int *)&((TradeWork *)p)->f644 = 0;
    }
}


void POKETRADE_2D_RegisterIconCharResources(char *p)
{
    void *v;
    int a;
    if (((TradeWork *)p)->f888 == 0) {
        v = func_020490F4(func_020275E4(), ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->f8A4 = CLACT_RegisterCharacter(v, func_02027618(), 0, 1, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->f888 = CLACT_RegisterPaletteEx(v, func_02027614(), 1, 0, 0, 3, ((TradeWork *)p)->heapId);
        a = func_0202761C(2);
        ((TradeWork *)p)->f8B8 = CLACT_RegisterCellAnim(v, a, func_02027620(2), ((TradeWork *)p)->heapId);
        ARC_TOOL_DeleteHandle(v);
    }
}


void POKETRADE_2D_LoadSummaryBackground(char *p, int a1, int a2)
{
    Tbl2 tbl = d_021E7DD0;
    void *v;
    v = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    func_02049990(v, tbl.w[a2], 4, 0, (unsigned short)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->heapId);
    if (a1 != 0) {
        func_02040618(4, 0, 0x80);
    } else {
        func_02040618(4, 0, 0);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04, 0);
    ARC_TOOL_DeleteHandle(v);
    func_02040588(4, 1);
}


void POKETRADE_2D_ClearSummaryBackground(char *p)
{
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    POKETRADE_2D_SetupSubBlend(p);
    BG_SYS_ClearSlot(4);
    func_02041B6C(4);
}


unsigned short POKETRADE_2D_GetBoxScreenEntry(int i, int row, char *p, int mode)
{
    if (i >= ((TradeWork *)p)->f638)
        i -= ((TradeWork *)p)->f638;
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
                a = ((TradeWork *)r)->fDCC - 5;
                b = ((TradeWork *)r)->fDCE - 8;
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
    n = ((TradeWork *)p)->f107C / 8;
    POKETRADE_2D_GetScrollColumn(p);
    for (y = 0; y < 24; y++) {
        for (x = 0; x < 52; x++) {
            mode = POKETRADE_2D_HitTestBoxGrid(p, x, y);
            func_02042FB0(7, x, y, POKETRADE_2D_GetBoxScreenEntry(n + x, y, p, mode));
        }
    }
    ((TradeWork *)p)->f108C = ((TradeWork *)p)->f107C % 8;
    ((TradeWork *)p)->f1084 = 1;
    func_02041B6C(7);
}


/*
 * 2026-10-03 (wB3 lane07): EXACT. The doubled zero-extension of the loop-invariant
 * comes from an int parameter stored in a u16 local and then added as (int)e.
 */
void POKETRADE_2D_LoadBoxScreenData(char *p, int d)
{
    int i;
    u16 e;

    *(Buf * *)&((TradeWork *)p)->f1174 = ARC_TOOL_LoadMember(0x66, 0xE, ((TradeWork *)p)->heapId);
    *(Buf * *)&((TradeWork *)p)->f1178 = ARC_TOOL_LoadMember(0x66, 0xF, ((TradeWork *)p)->heapId);
    *(Buf * *)&((TradeWork *)p)->f117C = ARC_TOOL_LoadMember(0x66, 0x19, ((TradeWork *)p)->heapId);
    *(Buf * *)&((TradeWork *)p)->f1180 = ARC_TOOL_LoadMember(0x66, 0x1A, ((TradeWork *)p)->heapId);
    e = d;
    for (i = 0; i < 0x300; i++) {
        (*(Buf * *)&((TradeWork *)p)->f1174)->v[i] += (int)e;
        (*(Buf **)(p + 0x1178))->v[i] += (int)e;
        (*(Buf **)(p + 0x117C))->v[i] += (int)e;
        (*(Buf **)(p + 0x1180))->v[i] += (int)e;
    }
    (*(unsigned short *)&((TradeWork *)p)->f107C) = (*(unsigned int *)&((TradeWork *)p)->f63C) - 0x50;
    POKETRADE_2D_DrawBoxGridScreen(p);
}


void POKETRADE_2D_FreeBoxScreenData(char *p)
{
    if (((TradeWork *)p)->f1174) {
        func_020307B0(((TradeWork *)p)->f1174);
        ((TradeWork *)p)->f1174 = 0;
        func_020307B0(((TradeWork *)p)->f1178);
        ((TradeWork *)p)->f1178 = 0;
        func_020307B0(((TradeWork *)p)->f117C);
        ((TradeWork *)p)->f117C = 0;
        func_020307B0(((TradeWork *)p)->f1180);
        ((TradeWork *)p)->f1180 = 0;
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
    func_02049B40(23,5,4,448,32,*(u16 *)(p+off));
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
                *(u32 *)(q+off1) = BMP_WIN_Create(5,0,0,15,2,14,0);
            if (i == *(int *)(p+off))
                func_02045CAC((*(void * *)&((TradeWork *)p)->messageBank),16,*(void **)(p+off2));
            else func_0200785C((*(void * *)&((TradeWork *)p)->gameData),i,*(void **)(p+off3));
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
    scroll = ((TradeWork *)p)->f107C / 8;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 64; x++) {
            func_02042FB0(5, x, y, 0);
        }
    }
    if (((TradeWork *)p)->f107C < 96) first = ((TradeWork *)p)->partyBoxId;
    else first = (((TradeWork *)p)->f107C - 96) / 160;
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
            pos = (int)((*(unsigned int *)&((TradeWork *)p)->f638)-(u32)scroll);
            if (scroll > pos) scroll = (int)((u32)scroll-(*(unsigned int *)&((TradeWork *)p)->f638));
            else pos = (int)(0u-(u32)scroll);
        } else pos = (int)((u32)idx*20u+12u-(u32)scroll);
        if (pos >= -10 && pos <= 33) {
            q = (char *)((u32)p+(u32)idx*4u);
            BMP_WIN_SetPosX(*(void **)(q + off1), pos + 1);
            BMP_WIN_MakeScreen(*(void **)(q + off2));
        }
    }
    func_02041B6C(5);
}


void POKETRADE_2D_CreateBoxIconActors(char *p)
{
    int i, j, z;
    void *arc;
    char *q;
    ObjTmpl t;
    arc = func_020490F4(7, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f87C = (void *)CLACT_RegisterPaletteCompressed(arc, func_0201BC3C(), 1, 0x60, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f8AC = (void *)CLACT_RegisterCellAnim(arc, func_0201BC78(), func_0201BCB4(), ((TradeWork *)p)->heapId);
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 5; j++) {
            z = 0;
            t.x = z;
            t.y = z;
            t.prio = 1;
            t.pal = 0x10;
            t.mode = 3;
            q = p + i * 20 + j * 4;
            ((TradeWork *)q)->f9CC = (void *)CLACT_RegisterCharacter(arc, 0x51b, z, 1, ((TradeWork *)p)->heapId);
            ((TradeWork *)q)->fAC0 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (unsigned int)((TradeWork *)q)->f9CC,
                (unsigned int)((TradeWork *)p)->f87C, (unsigned int)((TradeWork *)p)->f8AC, &t, 1, ((TradeWork *)p)->heapId);
            t.prio = z;
            t.pal = 0xf;
            ((TradeWork *)q)->fBB0 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (unsigned int)(*(void * *)&((TradeWork *)p)->f894),
                (unsigned int)(*(void * *)&((TradeWork *)p)->f880), (unsigned int)(*(void * *)&((TradeWork *)p)->f8B0), &t, 1, ((TradeWork *)p)->heapId);
            CLACT_SetActorAutoAnim(((TradeWork *)q)->fAC0, z);
            CLACT_SetActorDrawEnable(((TradeWork *)q)->fAC0, z);
            CLACT_SetActorDrawEnable(((TradeWork *)q)->fBB0, z);
            CLACT_SetActorAutoAnim(((TradeWork *)q)->fBB0, 1);
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
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + n * 20 + i * 4 + 0xac0)));
            *(int *)(p + n * 20 + i * 4 + 0xac0) = 0;
        }
        if (*(int *)(p + n * 20 + i * 4 + 0xbb0)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + n * 20 + i * 4 + 0xbb0)));
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
    if ((*(int *)&((TradeWork *)p)->f87C)) {
        CLACT_ReleasePalette((*(int *)&((TradeWork *)p)->f87C));
        (*(int *)&((TradeWork *)p)->f87C) = 0;
    }
    if ((*(int *)&((TradeWork *)p)->f8AC)) {
        CLACT_ReleaseCellAnim((*(int *)&((TradeWork *)p)->f8AC));
        (*(int *)&((TradeWork *)p)->f8AC) = 0;
    }
    if (((TradeWork *)p)->f1184) func_020307B0(((TradeWork *)p)->f1184);
    ((TradeWork *)p)->f1184 = 0;
}


void POKETRADE_2D_DeleteOfferIcons(char *p)
{
    int i;
    POKETRADE_2D_DeleteCursorActor(p);
    POKETRADE_SAVE_DeleteOfferStatusIcons(p);
    for (i = 0; i < 10; i++) {
        if (*(int *)(p + i * 4 + 0xefc)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p + i * 4 + 0xefc)));
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
        return (int)POKETRADE_PROC_LoadSlotMonAlt((void *)v, n, m, p);
    }
    if (b < 3) {
        *out = 1;
        return (int)POKETRADE_PROC_LoadSlotMonAlt((void *)v, ((TradeWork *)p)->partyBoxId, a + b * 2, p);
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
            if (CLACT_GetActorDrawEnable((struct Obj *)((*(int *)&((TradeWork *)r)->fBB0)))) {
                CLACT_GetActorSurfacePos((struct Actor *)(*(int *)&((TradeWork *)r)->fBB0), (struct PtS *)xy, 1);
                ((TradeWork *)p)->fF54 = xy[0];
                ((TradeWork *)p)->fF58 = xy[1];
            }
        }
    }
}


int POKETRADE_2D_IsBoxIconFiltered(char *p, int i)
{
    int v = ((TradeWork *)p)->f800;
    if (v != 0 && v - 1 == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}


int POKETRADE_2D_IsBoxIconMatch(int i, int x)
{
    if (x == d_021E82A4[i]) {
        return 1;
    }
    return 0;
}


/*
 * Normalise the third argument to 0 or 1 and tail call the setter.
 */
void POKETRADE_2D_SetIconObjMode(int a0, int a1, int a2)
{
    CLACT_SetActorObjMode((struct Actor *)a1, a2 != 0);
}


void POKETRADE_2D_UpdateIconObjMode(char *p, int a1, int a2, int a3, int a4, int a5)
{
    int flag = 0;
    if (POKETRADE_NEGO_IsMonOwnOffer(p, a1, a2)) {
        flag = 1;
    }
    POKETRADE_2D_SetIconObjMode((int)p, ((int (*)[5])(p + 0xAC0))[a5][a2], flag);
}


void POKETRADE_2D_CreateBoxIcon(char *p, int v, int a, int row, int flag)
{
    int j, rec, id, b2, b3, idx, n;
    Ent *e;
    Info info;
    int kind;
    u16 pos[2];
    PointS16 pt;
    enum { VRAM_BASE = 0x06600000 } vram;
    if (a == ((TradeWork *)p)->fF74 && func_020355C4() == 0) {
        CLACT_SetActorDrawEnable(((void **)(p + row * 20 + 0xbb0))[((TradeWork *)p)->fF78], 1);
    }
    for (j = 0; j < 5; j++) {
        rec = POKETRADE_2D_ResolveGridCell(v, a, j, p, &kind);
        e = (Ent *)POKETRADE_2D_GetGridCellMon(a, j, p);
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
            CLACT_GetActorImageProxy(*(void **)(p + row * 20 + j * 4 + 0xac0), (struct Struct36 *)(&info));
            n = POKETRADE_PROC_GetBoxIndexForSlot(a, p);
            idx = POKETRADE_PROC_GetSlotIndexInBox(a, j);
            idx += n * 30;
            CLACT_GetActorSurfacePos((struct Actor *)*(void **)(p + row * 20 + j * 4 + 0xac0), (struct PtS *)&pt, 1);
            if (flag == 1 && pt.x >= -16 && pt.x <= 0x110) {
                if (func_02061CA4((void *)0x23, info.c, *(int *)(p + 0x1184) + idx * 0x200, 0x200) == 0) {
                    vram = VRAM_BASE;
                    MI_CpuCopy8((const void *)(*(int *)(p + 0x1184) + idx * 0x200), (void *)(vram + info.c), 0x200);
                }
            } else {
                vram = VRAM_BASE;
                MI_CpuCopy8((const void *)(*(int *)&((TradeWork *)p)->f1184 + idx * 0x200), (void *)(vram + info.c), 0x200);
            }
            POKETRADE_2D_UpdateIconObjMode(p, a, j, rec, kind, row);
            CLACT_SetActorPaletteOffset(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), POKE_TOOL_GetIconPalette((void *)rec), 1);
            CLACT_SetActorAutoAnim(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 0);
            CLACT_SetActorDrawEnable(*(void **)(p + row * 20 + (u32)j * 4 + 0xac0), 1);
        }
        if (func_02017E88((void *)rec, 0x4c, 0) == 0 && POKETRADE_2D_IsBoxIconFiltered(p, id)) {
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
    x = ((TradeWork *)p)->f107C;
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
    n = ((TradeWork *)p)->f634;
    if (*out >= n) *out -= n;
    n = ((TradeWork *)p)->f634;
    if (hi >= n) {
        t = ((TradeWork *)p)->fF74;
        if (t < 20) t = t + 1 + n;
        if (x <= t && t <= hi) return 1;
    } else {
        t = ((TradeWork *)p)->fF74;
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
    if (((TradeWork *)p)->f1080 != n) {
        ((TradeWork *)p)->f1080 = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xbb0), 0);
                *(unsigned char *)(p + i * 5 + j + 0xebc) = 0;
            }
        }
        ((TradeWork *)p)->f1090 = n;
        POKETRADE_2D_HideAllBoxIcons((int)p);
        for (i = 0; i < 12; i++) {
            POKETRADE_2D_CreateBoxIcon(p, a, n, POKETRADE_2D_WrapIndex12(((TradeWork *)p)->f1080 + i), b);
            n++;
            if (n >= ((TradeWork *)p)->f634) n = 0;
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
    y = ((TradeWork *)p)->f1080;
    for (i = 0; i < 12; i++) {
        row = POKETRADE_2D_WrapIndex12(((TradeWork *)p)->f1080 + i);
        if (y >= ((TradeWork *)p)->f634) {
            y -= ((TradeWork *)p)->f634;
            off = ((TradeWork *)p)->f63C;
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
            b.x = off + (x - ((TradeWork *)p)->f107C);
            b.y = ty;
            a = b;
            if (POKETRADE_NEGO_IsMonPeerSelected(p, y, j) && func_020355C4() == 1) {
                b.y -= 8;
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority((*(int *)&((TradeWork *)q)->fAC0), 11);
            } else {
                q = p + row * 20 + j * 4;
                CLACT_SetActorDrawPriority((*(int *)&((TradeWork *)q)->fAC0), 0x1c - i);
            }
            CLACT_AddActorSurfacePos((struct Obj *)((*(int *)&((TradeWork *)q)->fAC0)), (const struct Vec2 *)(&b), 1);
            if (*(u8 *)(p + row * 5 + j + 0xebc)) {
                *(PointS16 *)(q + 0xdcc) = a;
            }
            b.y = ty + 3;
            CLACT_AddActorSurfacePos((struct Obj *)((*(int *)&((TradeWork *)q)->fBB0)), (const struct Vec2 *)(&b), 1);
        }
        y++;
    }
}


/*
 * lever: initial guard is a forward goto, with the exit after the body.
 */
void POKETRADE_2D_LoadBoxIconGfx(char *p, int b)
{
    int i, n, x, t, out;
    void *a;
    if (b == 0) *(int *)&((TradeWork *)p)->f1184 = (int)func_02030734(((TradeWork *)p)->heapId, 0x5ac00, 0, d_021E8530, 0x50b);
    a = func_020490F4(7, ((TradeWork *)p)->heapId);
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = (int)POKETRADE_PROC_LoadSlotMonAlt((void *)(((TradeWork *)p)->gameData), b, i, p);
            if (x) x = POKE_TOOL_GetGraphicIndex((void *)x);
            else x = POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0);
            t = (int)func_02049DF4(a, x, 0, (u32)(&out), ((TradeWork *)p)->heapId);
            MI_CpuCopy8(((struct GfxLoadResult *)out)->data, (void *)(*(int *)&((TradeWork *)p)->f1184 + n * 512), 512);
            n++;
            func_020307B0((void *)t);
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
            CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xac0), 0);
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
int POKETRADE_2D_HitTestBoxIcons(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow)
{
 PointS16 pos;
 int column,slot,row;
 Object *tmp;
 for(row=0;row<12;row++) {
  for(column=0;column<5;column++) {
   CLACT_GetActorSurfacePos((struct Actor *)((Object *)p)->actors[row][column],(struct PtS *)&pos,1);
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
    tmp=(Object *)p;
    return (int)tmp->actors[row][column];
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
 BgTemplate a,b;
 void *v;
 POKETRADE_2D_SetDisplayConfig(1);p[0x11ec]=1;
 a=d_021E7E24;BG_SYS_InitBgLayer(6,&a,0);BG_SYS_Init(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 b=d_021E7F44;BG_SYS_InitBgLayer(7,&b,2);
 if(mode==0) {
  v=func_020490F4(0x67,((TradeWork *)p)->heapId);
  func_02049B68(v,5,6,0x6000,0,((TradeWork *)p)->heapId);
  func_02049658((void *)((u32)v),4,7,0,0,0,((TradeWork *)p)->heapId);
  func_020498F4((void *)((u32)v),6,7,0,0,0,((TradeWork *)p)->heapId);
  func_02040618(7,0,0);ARC_TOOL_DeleteHandle(v);
 } else {
  v=func_020490F4(0x68,((TradeWork *)p)->heapId);
  func_02049B68(v,1,6,0x6000,0,((TradeWork *)p)->heapId);
  func_02049658((void *)((u32)v),0,7,0,0,0,((TradeWork *)p)->heapId);
  func_020498F4((void *)((u32)v),2,7,0,0,0,((TradeWork *)p)->heapId);
  func_02040618(7,0,0);ARC_TOOL_DeleteHandle(v);
 }
}


void POKETRADE_2D_ExitSummaryBgs(int p)
{
    if (((TradeWork *)p)->f11EC != 0) {
        func_02040DA8(6, 1, 0);
        func_020403F4(6);
        func_020403F4(7);
        ((TradeWork *)p)->f11EC = 0;
    }
}


void POKETRADE_2D_InitDisplayAndClact(char *p)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021E7D40);
    CLACT_InitSystem((const struct Cfg *)(&d_021E7CC8), (unsigned int)d_021E7D40, ((TradeWork *)p)->heapId);
    POKETRADE_2D_SetDisplayConfig(0);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
}


void POKETRADE_2D_SetupMainBgs(void *a0)
{
 BgTemplate a,b,c;
 a=d_021E7F24;
 BG_SYS_InitBgLayer(3,&a,0);BG_SYS_Init(3,0,1,0);
 func_02041300(3,0,0,0,32,24,17);func_020409B4(3);
 b=d_021E7E84;
 BG_SYS_InitBgLayer(2,&b,0);BG_SYS_Init(2,0,1,0);
 func_02041300(2,0,0,0,32,24,17);func_020409B4(2);
 c=d_021E7EA4;
 BG_SYS_InitBgLayer(1,&c,0);
 func_02041300(1,0,0,0,32,24,17);func_020409B4(1);
 BG_SYS_SetLowBit(0);func_02040588(0,1);func_0204047C(0,0);
}


static inline void shading(Shading s) { *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3002) | (s << 1)); }


static inline void antialias(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x10); else *(volatile u16 *)0x04000060 &= (u16)~0x3010; }


static inline void blend(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 8); else *(volatile u16 *)0x04000060 &= (u16)~0x3008; }


static inline void edge(int b) { if(b) *(volatile u16 *)0x04000060 = (u16)((*(volatile u16 *)0x04000060 & ~0x3000) | 0x20); else *(volatile u16 *)0x04000060 &= (u16)~0x3020; }


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
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(const u16 *)(d_021E7D00+i*8));
    *(volatile u16 *)0x04000008 = (u16)((*(volatile u16 *)0x04000008 & ~3) | 2);
}


/*
 * lever: const camera s16 table keeps loads interleaved with stack arguments.
 * volatile: 0x04000060 hardware read-modify-write at 021E5644 and 021E5648.
 */
void POKETRADE_2D_InitG3DSystem(char *p)
{
    u16 heap;
    Vec v;
    G3D_SYSTEM_Init(0,2,0,1,0,(((TradeWork *)p)->heapId&0x7fff)|0x8000,POKETRADE_2D_Setup3DRenderState);
    heap = (((TradeWork *)p)->heapId&0x7fff)|0x8000;
    v = d_021E7DE0;
    ((TradeWork *)p)->camera = G3D_CAMERA_Create(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,0x1000,0x400000,0,&d_021E7CA0,&v,&d_021E7C94,heap);
    G3D_CAMERA_Reset((struct Light *)(((TradeWork *)p)->camera));
    *(volatile u16 *)0x04000060 &= 0xcfdf;
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}








void POKETRADE_2D_SetupSubBgs(char *p)
{
 BgTemplate a,b,c,d;
 a=d_021E7EE4;BG_SYS_InitBgLayer(4,&a,0);func_02041300(4,0,0,0,32,24,17);
 b=d_021E7F04;BG_SYS_InitBgLayer(5,&b,0);BG_SYS_Init(5,0,1,0);func_02041300(5,0,0,0,32,24,17);func_020409B4(5);
 c=d_021E7F64;BG_SYS_InitBgLayer(7,&c,0);func_02041300(7,0,0,0,64,24,17);func_020409B4(7);
 d=d_021E7E04;BG_SYS_InitBgLayer(6,&d,0);BG_SYS_Init(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 p[0x11eb]=1;
}








void POKETRADE_2D_ExitSubBgs(int p)
{
    if (((TradeWork *)p)->f11EB == 1) {
        func_02040DA8(4, 1, 0);
        func_02040DA8(6, 1, 0);
        func_020403F4(4);
        func_020403F4(5);
        func_020403F4(6);
        func_020403F4(7);
        ((TradeWork *)p)->f11EB = 0;
    }
}








void POKETRADE_2D_SetDisplayConfig(int i)
{
    func_0203FC28((struct DispConfig *)(d_021E7D20 + i * 16));
}








void POKETRADE_2D_RegisterMarkerResources(int p)
{
    void *a;
    if (((TradeWork *)p)->f898 == 0) {
        a = func_020490F4(0x66, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->f898 = CLACT_RegisterCharacter(a, 0x15, 0, 0, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->f884 = CLACT_RegisterPaletteEx(a, 0x12, 0, 0xc0, 0, 6, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->f8B4 = CLACT_RegisterCellAnim(a, 0x14, 0x13, ((TradeWork *)p)->heapId);
        ARC_TOOL_DeleteHandle(a);
    }
}








void POKETRADE_2D_ReleaseMarkerResources(char *p)
{
    if (((TradeWork *)p)->f898 != 0) {
        CLACT_ReleaseCharacter(((TradeWork *)p)->f898);
        CLACT_ReleasePalette(((TradeWork *)p)->f884);
        CLACT_ReleaseCellAnim(((TradeWork *)p)->f8B4);
        ((TradeWork *)p)->f898 = 0;
        ((TradeWork *)p)->f884 = 0;
        ((TradeWork *)p)->f8B4 = 0;
    }
}








void POKETRADE_2D_RegisterIconSpriteResources(int p)
{
    void *a;
    Sprite s;
    a = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f894 = CLACT_RegisterCharacter(a, 0x18, 0, 1, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f880 = CLACT_RegisterPaletteEx(a, 0x12, 1, 0xc0, 0, 6, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f8B0 = CLACT_RegisterCellAnim(a, 0x17, 0x16, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(a);
    s.x = 0x80; s.y = 0xb4; s.z = 2; s.a = 0xe; s.b = 0;
    ((TradeWork *)p)->fF04 = (int)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem, ((TradeWork *)p)->f894, ((TradeWork *)p)->f880, ((TradeWork *)p)->f8B0, &s, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((struct Obj *)((TradeWork *)p)->fF04, 0);
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04, 1);
}








void POKETRADE_2D_LoadMainPalette(int p)
{
    void *a = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    func_02049990(a, (int)0x1d, (int)2, (int)0, (u16)(((TradeWork *)p)->f86C), (int)0, (int)0, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(a);
}








void POKETRADE_2D_CreateTouchbarActors(char *p)
{
    void *arc;
    void *a, *b;
    int z;
    ObjTmpl u, t;
    u.x = 0x80;
    u.y = 0x10;
    u.prio = 0x13;
    u.pal = 0xe;
    u.mode = 1;
    ((TradeWork *)p)->fF08 = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (unsigned int)(*(void * *)&((TradeWork *)p)->f894), (unsigned int)(*(void * *)&((TradeWork *)p)->f880),
        (unsigned int)(*(void * *)&((TradeWork *)p)->f8B0), &u, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim(((TradeWork *)p)->fF08, 1);
    CLACT_SetActorDrawEnable(((TradeWork *)p)->fF08, 1);
    u.x = 0x60;
    u.y = 0x10;
    u.prio = 0;
    u.pal = 0xb;
    u.mode = 1;
    (*(void * *)&((TradeWork *)p)->fF0C) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (unsigned int)(*(void * *)&((TradeWork *)p)->f894), (unsigned int)(*(void * *)&((TradeWork *)p)->f880),
        (unsigned int)(*(void * *)&((TradeWork *)p)->f8B0), &u, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&((TradeWork *)p)->fF0C), 1);
    if (func_020355C4()) {
        CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->fF0C), 0);
    }
    arc = func_020490F4(7, ((TradeWork *)p)->heapId);
    z = 0;
    a = POKE_TOOL_GetBoxParam(POKETRADE_PROC_GetSideMon(p, 0));
    b = POKE_TOOL_GetBoxParam(POKETRADE_PROC_GetSideMon(p, 1));
    (*(void * *)&((TradeWork *)p)->f89C) = (void *)CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(a), z, 1, ((TradeWork *)p)->heapId);
    (*(void * *)&((TradeWork *)p)->f8A0) = (void *)CLACT_RegisterCharacter(arc, POKE_TOOL_GetGraphicIndex(b), z, 1, ((TradeWork *)p)->heapId);
    t.x = 0x60;
    t.y = 0xc;
    t.prio = z;
    t.pal = 0xc;
    t.mode = 1;
    (*(void * *)&((TradeWork *)p)->fF10) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (unsigned int)(*(void * *)&((TradeWork *)p)->f89C), (unsigned int)((TradeWork *)p)->f87C,
        (unsigned int)((TradeWork *)p)->f8AC, &t, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&((TradeWork *)p)->fF10), 0);
    CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->fF10), 1);
    CLACT_SetActorPaletteOffset((*(void * *)&((TradeWork *)p)->fF10), POKE_TOOL_GetIconPalette(a), 1);
    t.x = 0xa0;
    (*(void * *)&((TradeWork *)p)->fF14) = CLACT_CreateActor((*(void * *)&((TradeWork *)p)->clactSystem), (unsigned int)(*(void * *)&((TradeWork *)p)->f8A0), (unsigned int)((TradeWork *)p)->f87C,
        (unsigned int)((TradeWork *)p)->f8AC, &t, 1, ((TradeWork *)p)->heapId);
    CLACT_SetActorAutoAnim((*(void * *)&((TradeWork *)p)->fF14), 0);
    CLACT_SetActorDrawEnable((*(void * *)&((TradeWork *)p)->fF14), 1);
    CLACT_SetActorPaletteOffset((*(void * *)&((TradeWork *)p)->fF14), POKE_TOOL_GetIconPalette(b), 1);
    ARC_TOOL_DeleteHandle(arc);
}








/*
 * lever: first y ternary is b == 0 ? 8 : 12 to retain branch polarity.
 */
void POKETRADE_2D_PlaceTouchbarActors(int p, int b, int c)
{
    PointU16 pos;
    if (c) {
        pos.x = 96; pos.y = 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    } else {
        pos.x = 96; pos.y = b == 0 ? 8 : 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF10), (const struct Vec2 *)(&pos), 1);
        pos.x = 160; pos.y = b ? 8 : 12;
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF14), (const struct Vec2 *)(&pos), 1);
    }
}









void POKETRADE_2D_DeleteTouchbarActors(int a)
{
    if ((*(int *)&((TradeWork *)a)->fF08) != 0)
        CLACT_DeleteActor((struct Obj *)((*(int *)&((TradeWork *)a)->fF08)));
    if (((TradeWork *)a)->fF0C != 0)
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)a)->fF0C));
    if (((TradeWork *)a)->fF10 != 0)
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)a)->fF10));
    if (((TradeWork *)a)->fF14 != 0)
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)a)->fF14));
    (*(int *)&((TradeWork *)a)->fF08) = 0;
    ((TradeWork *)a)->fF0C = 0;
    ((TradeWork *)a)->fF10 = 0;
    ((TradeWork *)a)->fF14 = 0;
    if (((TradeWork *)a)->f89C != 0)
        CLACT_ReleaseCharacter(((TradeWork *)a)->f89C);
    if (((TradeWork *)a)->f8A0 != 0)
        CLACT_ReleaseCharacter(((TradeWork *)a)->f8A0);
    ((TradeWork *)a)->f89C = 0;
    ((TradeWork *)a)->f8A0 = 0;
}








void POKETRADE_2D_LoadSubScreenGfx(char *p)
{
    u32 i;
    void *h;
    func_02040588(4, 0);
    func_02040588(6, 0);
    h = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    func_02049990(h, 16, 4, 0, (u16)(*(int *)&((TradeWork *)p)->f870), 0, 0, ((TradeWork *)p)->heapId);
    func_02041B6C(4);
    func_02040618(4, 0, -4);
    func_02040618(6, 0, -4);
    ARC_TOOL_DeleteHandle(h);
    GF_FONT_SetTextColor(1, 2, 15);
    for (i = 0; i < 26; i++) {
        *(void **)(p + i * 4 + 0x750) = (void *)BMP_WIN_Create(6, (u8)d_021E81D4[i].x, (u8)d_021E81D4[i].y, 2, 2, 14, 0);
        func_02045CAC((struct MsgBank *)(((TradeWork *)p)->messageBank), i + 0x35, (void *)(((TradeWork *)p)->f730));
        PRINTSYS_Print(BMP_WIN_GetBmp(*(void **)(p + i * 4 + 0x750)), 0, 0, (*(void * *)&((TradeWork *)p)->f730), ((TradeWork *)p)->f728);
        BMP_WIN_MakeScreen(*(void **)(p + i * 4 + 0x750));
        BMP_WIN_TransferChars(*(void **)(p + i * 4 + 0x750));
    }
    func_02041B6C(6);
    func_02040588(4, 1);
    func_02040588(6, 1);
}








/*
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 */
void POKETRADE_2D_ClearSubScreen(char *p)
{
    unsigned i;
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_02040618(6, 0, 0);
    if (((TradeWork *)p)->fF04) CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF04, 1);
    if (((TradeWork *)p)->fF18) CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF18, 1);
    for (i = 0; i < 26; i++) {
        if (*(int *)(p + i * 4 + 0x750)) {
            BMP_WIN_ClearScreen((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            func_0201F7A8((void *)(*(int *)(p + i * 4 + 0x750)), 2);
            BMP_WIN_Delete((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            *(int *)(p + i * 4 + 0x750) = 0;
        }
    }
    func_02041B6C(6);
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
    u32 species = func_02017E1C(mon,6,0);
    if (FILE_UTIL_Check136C(species)) flag = 1;
    if (((struct UiScene *)q)->actor) {
        if (!species) CLACT_SetActorDrawEnable((struct Obj *)((struct UiScene *)q)->actor,0);
        else {
            CLACT_SetActorAnimSeq((struct Obj *)(((struct UiScene *)q)->actor),flag);
            CLACT_SetActorDrawEnable((struct Obj *)((struct UiScene *)q)->actor,1);
        }
        return;
    }
    if (!species) return;
    switch (side) {
    case 0: case 1:
        x = side*128+16; y = 132;
        in.f0 = 1; in.b1c = 12;
        break;
    case 2:
        x = 32; y = 172;
        in.f0 = 0; in.b1c = 6;
        break;
    }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027694();
    in.f10 = func_02027698();
    in.f14 = func_0202769C(2);
    in.f18 = func_020276A0(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, (ActorGfxDesc *)&in, ((TradeWork *)p)->clactSystem, ((TradeWork *)p)->heapId);
    ((struct UiScene *)q)->actor = (void *)UI_SCENE_CreateActor(q,((TradeWork *)p)->clactSystem,x,y,flag,((TradeWork *)p)->heapId);
}









void POKETRADE_2D_DeleteMarkingIcon(void *p)
{
    if (((struct UiScene *)p)->actor) {
        CLACT_DeleteActor((struct Obj *)(((struct UiScene *)p)->actor));
        UI_SCENE_FreeActorGfx(p);
        ((struct UiScene *)p)->actor = 0;
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
    if (((struct UiScene *)q)->actor) {
        if (!a) CLACT_SetActorDrawEnable((struct Obj *)((struct UiScene *)q)->actor,0);
        else CLACT_SetActorDrawEnable((struct Obj *)((struct UiScene *)q)->actor,1);
        return;
    }
    if (!a) {
        if (!flag) POKETRADE_2D_CreateCuredPokerusIcon(p,side,(void *)mon);
        return;
    }
    if (flag) { in.f0 = 0; in.b1c = 0; }
    else { in.f0 = 1; in.b1c = 11; }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_020276B4();
    in.f10 = func_020276B8();
    in.f14 = func_020276BC(2);
    in.f18 = func_020276C0(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, (ActorGfxDesc *)&in, ((TradeWork *)p)->clactSystem, ((TradeWork *)p)->heapId);
    if (flag) ((struct UiScene *)q)->actor = (void *)UI_SCENE_CreateActor(q,((TradeWork *)p)->clactSystem,244,104,0,((TradeWork *)p)->heapId);
    else ((struct UiScene *)q)->actor = (void *)UI_SCENE_CreateActor(q,((TradeWork *)p)->clactSystem,side*128+108,24,0,((TradeWork *)p)->heapId);
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
    if (((struct UiScene *)q)->actor) {
        if (a == 0) CLACT_SetActorDrawEnable((struct Obj *)((struct UiScene *)q)->actor, 0);
        else CLACT_SetActorDrawEnable((struct Obj *)((struct UiScene *)q)->actor, 1);
        return;
    }
    in.f0 = 1; in.b1c = 14; in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027748();
    in.f10 = func_0202774C(2);
    in.f14 = func_02027750(2);
    in.f18 = func_02027754(2);
    in.b1d = 0; in.b1e = 1;
    UI_SCENE_LoadActorGfx(q, (ActorGfxDesc *)&in, ((TradeWork *)p)->clactSystem, ((TradeWork *)p)->heapId);
    ((struct UiScene *)q)->actor = (void *)UI_SCENE_CreateActor(q, ((TradeWork *)p)->clactSystem, 108 + b * 128, 20, 13, ((TradeWork *)p)->heapId);
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
    Coords coords;
    States states;
    int offOwner,offStore,offLoad,offSprite;
    u32 bits;
    long i;
    int state,sprite;
    int *row;
    bits=func_02017E1C(mon,11,0);
    coords=d_021E7EC4;
    states=d_021E7F84;
    in.f0=0; in.f4=0;
    in.f8=func_020275E4();
    in.fC=func_02027748();
    in.f10=func_0202774C(2);
    in.f14=func_02027750(2);
    in.f18=func_02027754(2);
    in.b1c=13; in.b1d=0; in.b1e=1;
    if (!flag && func_02017EAC(mon)) bits|=64;
    if (POKERUS_IsCured(mon)) bits|=128;
    if (!((TradeWork *)p)->f99C) {
        UI_SCENE_LoadActorGfx((void *)(p+0x98c), (ActorGfxDesc *)&in, ((TradeWork *)p)->clactSystem, ((TradeWork *)p)->heapId);
        ((TradeWork *)p)->f99C=1;
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
            if (state==-1) CLACT_SetActorDrawEnable((struct Obj *)sprite,0);
            else if (flag && i==6) CLACT_SetActorDrawEnable((struct Obj *)sprite,0);
            else { CLACT_SetActorAnimSeq((struct Obj *)sprite,state); CLACT_SetActorDrawEnable((struct Obj *)sprite,1); }
        } else {
            *(int *)(p+(unsigned long)i*4+offStore)=UI_SCENE_CreateActor((void *)(p+0x98c),*(int *)(p+offOwner),coords.v[(unsigned long)i]*8,101,state==-1?row[0]:state,((TradeWork *)p)->heapId);
            sprite=*(int *)(p+(unsigned long)i*4+offLoad);
            if (state==-1) CLACT_SetActorDrawEnable((struct Obj *)sprite,0);
            else if (flag && i==6) CLACT_SetActorDrawEnable((struct Obj *)sprite,0);
        }
    }
}






void POKETRADE_2D_DeleteSummaryIcons(void *p)
{
    char *q = (char *)p + 0x98c;
    int i;
    for (i = 0; i < 8; i++) {
        if (*(int *)(q + i * 4 + 0x14)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(q + i * 4 + 0x14)));
            *(int *)(q + i * 4 + 0x14) = 0;
        }
    }
    if (((struct UiScene *)q)->actor) {
        UI_SCENE_FreeActorGfx((unsigned int *)q);
        ((struct UiScene *)q)->actor = 0;
    }
}





void POKETRADE_2D_UploadWindowPalette(char *p, int n, u32 x) {
    int offset = n * 32;
    func_02049B40(23,5,x,offset,32,((TradeWork *)p)->heapId);
    ARC_UTIL_UploadPaletteFromArchive(func_020275E4(),31,x,28,offset+28,4,((TradeWork *)p)->heapId);
}






void POKETRADE_2D_DeleteOfferIconActor(TradeWork *p, int a, int b)
{
    if (p->offerIconActor[a][b]) {
        CLACT_DeleteActor((struct Obj *)p->offerIconActor[a][b]);
        p->offerIconActor[a][b] = 0;
        CLACT_ReleaseCharacter(p->offerIconCharRes[a][b]);
    }
}





void POKETRADE_2D_SetOfferIconsVisible(TradeWork *p, int a, int v)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (p->offerIconActor[a][i])
            CLACT_SetActorDrawEnable((struct Obj *)p->offerIconActor[a][i], v);
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
    Create c;
    void *q = func_020185F0(mon);
    void *h = func_020490F4(7,((TradeWork *)p)->heapId);
    int n;
    POKETRADE_2D_DeleteOfferIconActor((TradeWork *)p, i, j);
    if (selected) {
        c.x=d_021E7D70[i*3+j][0]; c.y=d_021E7D70[i*3+j][1]; n=0;
    } else {
        c.x=d_021E7DA0[i*3+j][0]; c.y=d_021E7DA0[i*3+j][1]; n=1;
    }
    c.z=1; c.a=16; c.b=1;
    *(int *)(p+0x1020+i*12+j*4) = CLACT_RegisterCharacter((void *)((u32)h),POKE_TOOL_GetGraphicIndex(q),0,n,((TradeWork *)p)->heapId);
    *(int *)(p+0x1008+i*12+j*4) = (int)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,*(int *)(p+0x1020+i*12+j*4),*(int *)&((TradeWork *)p)->f890,*(int *)&((TradeWork *)p)->f8C0,&c,n,((TradeWork *)p)->heapId);
    CLACT_SetActorPaletteOffset((struct Obj *)(*(int *)(p+0x1008+i*12+j*4)),POKE_TOOL_GetIconPalette(q),1);
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p+0x1008+i*12+j*4),0);
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p+0x1008+i*12+j*4),visible);
    ARC_TOOL_DeleteHandle((void *)((int)h));
}




void POKETRADE_2D_UpdateOfferIconHighlight(int p, int a, int b) {
    int i,j;
    PointS16 pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (((TradeWork *)p)->offerIconActor[i][j]) {
                pos.x=d_021E7DA0[i*3+j][0]; pos.y=d_021E7DA0[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->offerIconActor[i][j]),(const struct Vec2 *)(&pos),1);
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
    Create c;
    c.x=x; c.y=y; c.z=1; c.a=0; c.b=0;
    ((TradeWork *)p)->fF20=(int)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,*(int *)(p+i*20+j*4+0x9cc),(*(int *)&((TradeWork *)p)->f87C),(*(int *)&((TradeWork *)p)->f8AC),&c,1,((TradeWork *)p)->heapId);
    CLACT_SetActorPaletteOffset((struct Obj *)(((TradeWork *)p)->fF20),POKE_TOOL_GetIconPalette(q),1);
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
    CLACT_GetActorSurfacePos((struct Actor *)(*(void * *)&((TradeWork *)p)->fF20),(struct PtS *)&pos,1);
    dx=(pos.x-((TradeWork *)p)->fF6C)*4096;
    dy=(pos.y-((TradeWork *)p)->fF6E)*4096;
    first.x=pos.x*4096; first.y=pos.y*4096; first.z=0;
    second.x=(pos.x*2-((TradeWork *)p)->fF6C)*4096;
    second.y=(pos.y*2-((TradeWork *)p)->fF6E)*4096; second.z=0;
    end.x=28*4096; end.y=0; end.z=0;
    x=first.x-end.x; y=first.y/2;
    speed=FX_Sqrt((int)((u32)mul(x,x)+(u32)mul(y,y)))/15;
    third.x=(int)((u32)x+(u32)mul(dx,speed)); third.y=(int)((u32)y+(u32)mul(dy,speed)); third.z=0;
    POKETRADE_2D_InitBezierCurve(&((TradeWork *)p)->bezierCurve,&first,&second,&third,&end,19);
    ((TradeWork *)p)->f11DC=21;
}




int POKETRADE_2D_UpdateIconFlight(char *p) {
    PointS16 pos;
    if (((TradeWork *)p)->f11DC) {
        --((TradeWork *)p)->f11DC;
        if (!((TradeWork *)p)->f11DC) return 1;
        CLACT_GetActorSurfacePos((struct Actor *)((TradeWork *)p)->fF20,(struct PtS *)&pos,1);
        if (pos.y<0) ((TradeWork *)p)->f11DC=1;
        if (((TradeWork *)p)->f11DC==1) POKETRADE_2D_DeleteFloatingIconActor(p);
        else {
            POKETRADE_2D_StepBezierCurve(&((TradeWork *)p)->bezierCurve);
            pos.x=((TradeWork *)p)->bezierCurve.out.x/4096;
            pos.y=((TradeWork *)p)->bezierCurve.out.y/4096;
            CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->fF20),(const struct Vec2 *)(&pos),1);
        }
    }
    return 0;
}





void POKETRADE_2D_DeleteFloatingIconActor(void *p)
{
    if (((TradeWork *)p)->fF20) {
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)p)->fF20));
        ((TradeWork *)p)->fF20 = 0;
    }
}





void POKETRADE_2D_SetupSubBlend(void *p)
{
    func_0207D63C(0x04001050, 0, 15, 8, 8);
}




void POKETRADE_2D_CreateMarkerActor(char *p, int i) {
    Create c;
    if (!*(int *)(p+0x10bc+i*4)) {
        c.x=i*24+8; c.y=144; c.z=i+11; c.a=50; c.b=1;
        *(int *)(p+0x10bc+i*4)=(int)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,((TradeWork *)p)->f894,((TradeWork *)p)->f880,((TradeWork *)p)->f8B0,&c,1,((TradeWork *)p)->heapId);
    }
    CLACT_SetActorAutoAnim((struct Obj *)*(int *)(p+0x10bc+i*4),1);
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p+0x10bc+i*4),1);
}




void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a)
{
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)((char *)p + i * 4 + 0x10bc), a);
}




void POKETRADE_2D_DeleteMarkerActor(void *p, int i)
{
    if (*(int *)((char *)p + 0x10bc + i * 4)) {
        CLACT_DeleteActor((struct Obj *)(*(int *)((char *)p + 0x10bc + i * 4)));
        *(int *)((char *)p + 0x10bc + i * 4) = 0;
    }
}




void POKETRADE_2D_SetMarkerActorAnim(void *p, int i)
{
    CLACT_SetActorAnimSeq((struct Obj *)(*(int *)((char *)p + i * 4 + 0x10bc)), (u16)(i + 15));
}



void POKETRADE_2D_CreateMarkerButtonActor(Work *p, int z, int i) {
    Create c;
    c.x=i*206+8; c.y=160; c.z=4; c.a=1; c.b=0;
    if (!p->slot[i*2]) {
        p->slot[i*2]=(int)CLACT_CreateActor((void *)p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        CLACT_SetActorAutoAnim((struct Obj *)p->slot[i*2],1);
        CLACT_SetActorDrawEnable((struct Obj *)p->slot[i*2],1);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->slot[i*2],1);
    }
    if (!p->slot[i*2+1]) {
        c.a=0; c.z=z;
        p->slot[i*2+1]=(int)CLACT_CreateActor((void *)p->g9c4,p->g898,p->g884,p->g8b4,&c,0,p->heap);
        CLACT_SetActorAutoAnim((struct Obj *)p->slot[i*2+1],1);
        CLACT_SetActorDrawEnable((struct Obj *)p->slot[i*2+1],1);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)p->slot[i*2+1],z);
    }
}



static inline void clear(int p, int i) {
    if (*(int *)(p+i*4+0x10ac)) {
        CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*4+0x10ac)));
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



void POKETRADE_2D_MovePickedIconActor(int p, int i) {
    PointTable6 t=d_021E7DEC;
    Create c;
    if(i==-1) {
        if(((TradeWork *)p)->pickedIconActor) CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->pickedIconActor,0);
    } else {
        if(!((TradeWork *)p)->pickedIconActor) {
            c.x=64;c.y=48;c.z=23;c.a=0;c.b=1;
            ((TradeWork *)p)->pickedIconActor=CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,((TradeWork *)p)->f894,((TradeWork *)p)->f880,((TradeWork *)p)->f8B0,&c,1,((TradeWork *)p)->heapId);
        }
        CLACT_SetActorAutoAnim((struct Obj *)((TradeWork *)p)->pickedIconActor,1);
        CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->pickedIconActor,1);
        CLACT_AddActorSurfacePos((struct Obj *)(((TradeWork *)p)->pickedIconActor),(const struct Vec2 *)(&t.pos[i]),1);
    }
}




void POKETRADE_2D_DeletePickedIconActor(char *p)
{
    if (((TradeWork *)p)->pickedIconActor) {
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)p)->pickedIconActor));
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
    if(((TradeWork *)p)->f11DE<128) ((TradeWork *)p)->f11DE+=4;
    else return 1;
    for(i=0;i<8;i++) {
        CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x10cc),(struct PtS *)&a,1);
        if(i/4) a.x+=4; else a.x-=4;
        CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(((TradeWork *)p)->offerIconActor[0][i]) {
            CLACT_GetActorSurfacePos(((TradeWork *)p)->offerIconActor[0][i],(struct PtS *)&b,1);
            b.x-=4;
            CLACT_AddActorSurfacePos(((TradeWork *)p)->offerIconActor[0][i],(const struct Vec2 *)(&b),1);
        }
    }
    for(i=0;i<3;i++) {
        if(((TradeWork *)p)->offerIconActor[1][i]) {
            CLACT_GetActorSurfacePos(((TradeWork *)p)->offerIconActor[1][i],(struct PtS *)&c,1);
            c.x+=4;
            CLACT_AddActorSurfacePos(((TradeWork *)p)->offerIconActor[1][i],(const struct Vec2 *)(&c),1);
        }
    }
    func_02040618(5,0,-((TradeWork *)p)->f11DE);
    func_02040618(4,0,((TradeWork *)p)->f11DE-128);
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
    const char *tmp1;
    for(i=0;i<8;i++) {
        tmp1=p+i*4;
        tmp1=tmp1+0x10cc;
        CLACT_GetActorSurfacePos(*(void **)tmp1,(struct PtS *)&a,1);
        if(i/4) {
            a.x-=128;
            CLACT_SetActorBgPriority(*(void **)(p+i*4+0x10cc),3);
        } else a.x+=128;
        CLACT_AddActorSurfacePos(*(void **)(p+i*4+0x10cc),(const struct Vec2 *)(&a),1);
    }
    for(i=0;i<3;i++) {
        if(*(void **)(p+i*4+0x1008)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0x1008),(struct PtS *)&b,1);
            b.x+=128;
            tmp=i;
            tmp=tmp*4;
            CLACT_AddActorSurfacePos(*(void **)(p+tmp+0x1008),(const struct Vec2 *)(&b),1);
        }
    }
    for(j=0;j<3;j++) {
        if(*(void **)(p+j*4+0x1014)) {
            CLACT_GetActorSurfacePos(*(void **)(p+j*4+0x1014),(struct PtS *)&c,1);
            c.x-=128;
            CLACT_AddActorSurfacePos(*(void **)(p+j*4+0x1014),(const struct Vec2 *)(&c),1);
            CLACT_SetActorBgPriority(*(void **)(p+j*4+0x1014),3);
        }
    }
    func_0204047C(4,2);
    func_0204047C(5,3);
}



void POKETRADE_2D_SetupCursorBg(char *p)
{
    void *h;
    BgTemplate t;
    (*(void * *)&((TradeWork *)p)->f644) = func_0201F5DC((void *)6, 15, 0, ((TradeWork *)p)->heapId);
    h = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f870 = func_02049740(h, 13, 5, 0, 0, ((TradeWork *)p)->heapId);
    func_02049990(h, 7, 4, 0, (u16)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->heapId);
    func_02049990(h, 7, 5, 0, (u16)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->heapId);
    t = d_021E7E44;
    func_020403F4(7);
    BG_SYS_InitBgLayer(7, &t, 0);
    func_02049990(h, 8, 7, 0, (u16)((TradeWork *)p)->f870, 0, 0, ((TradeWork *)p)->heapId);
    func_02040618(4, 0, -0x80);
    func_02040618(7, 0, 0);
    func_0204047C(4, 3);
    func_02049990(h, 11, 2, 0, (u16)(*(unsigned int *)&((TradeWork *)p)->f86C), 0, 0, ((TradeWork *)p)->heapId);
    ARC_TOOL_DeleteHandle(h);
    (*(unsigned short *)&((TradeWork *)p)->f11DE) = 0;
    POKETRADE_2D_SetCursorSlidePositions(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}


void POKETRADE_2D_CreateOfferWindows(char *p)
{
    PointTable8 t = d_021E7E64;
    void *h = func_020490F4(0x66, ((TradeWork *)p)->heapId);
    Create c;
    int i;
    (*(unsigned int *)&((TradeWork *)p)->f10EC) = CLACT_RegisterPaletteEx(h, 0, 1, 0x1c0, 0, 1, ((TradeWork *)p)->heapId);
    ((TradeWork *)p)->f10F0 = CLACT_RegisterCellAnim(h, 2, 1, ((TradeWork *)p)->heapId);
    for (i = 0; i < 8; i++) {
        *(void **)(p + i * 4 + 0x10f4) = BMP_Create(16, 6, 32, ((TradeWork *)p)->heapId);
        *(u32 *)(p + i * 4 + 0x1114) = CLACT_RegisterCharacter(h, 3, 0, 1, ((TradeWork *)p)->heapId);
    }
    for (i = 0; i < 8; i++) {
        c.x = *(short *)((char *)&t + i * 4); c.y = *(short *)((char *)&t + i * 4 + 2); c.z = 0; c.a = 0; c.b = 1;
        *(int *)(p + i * 4 + 0x10cc) = (int)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem, *(int *)(p + i * 4 + 0x1114), *(int *)(p + 0x10ec), *(int *)(p + 0x10f0), &c, 1, ((TradeWork *)p)->heapId);
        CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 4 + 0x10cc), 1);
    }
    ARC_TOOL_DeleteHandle(h);
}


void POKETRADE_2D_DeleteOfferWindowActors(int p) {
    int i;
    for (i=0;i<8;i++) {
        if (*(int *)(p+i*4+0x10cc)) {
            CLACT_DeleteActor((struct Obj *)(*(int *)(p+i*4+0x10cc)));
            *(int *)(p+i*4+0x10cc)=0;
            BMP_Delete(*(void **)(p+i*4+0x10f4));
            *(int *)(p+i*4+0x10f4)=0;
            CLACT_ReleaseCharacter(*(int *)(p+i*4+0x1114));
            *(int *)(p+i*4+0x1114)=0;
        }
    }
    if (((TradeWork *)p)->f10EC) {CLACT_ReleasePalette(((TradeWork *)p)->f10EC);((TradeWork *)p)->f10EC=0;}
    if (((TradeWork *)p)->f10EC) {CLACT_ReleaseCellAnim(((TradeWork *)p)->f111C);((TradeWork *)p)->f10EC=0;}
}


void POKETRADE_2D_UpdateOfferWindowActors(int p) {
    ByteTable8 t=d_021E7DD8;
    int i,j;
    char *dest,*source;
    for(i=0;i<8;i++) {
        dest=(char *)CLACT_GetCharacterVramAddress(*(int *)(p+i*4+0x1114),1);
        source=BMP_GetPixels((const struct Bmp *)(*(int *)(p+i*4+0x10f4)));
        DWCi_ScreenDC_FlushRange(source,BMP_GetByteSize((const struct Bmp *)(*(int *)(p+i*4+0x10f4))));
        for(j=0;j<8;j++) {func_0207E804(source+t.v[j]*256,dest,256);dest+=256;}
    }
}


void POKETRADE_2D_LoadMonPalette(char *p, int side, void *mon)
{
    void *h = func_020490F4(0x66, ((TradeWork *)p)->heapId);
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
        d[i] += (u16)((TradeWork *)p)->f86C;
    if (!side)
        func_02041090(1, (u32)d, 0, 0, 16, 24);
    else
        func_02041090(1, (u32)pal->data, 16, 0, 16, 24);
    func_020307B0(f);
    func_0204047C(3, 2);
    func_0204047C(2, 3);
    func_0204047C(1, 1);
    func_0204047C(0, 0);
    ARC_TOOL_DeleteHandle(h);
    func_02041B6C(1);
}


void POKETRADE_2D_OnCursorAnimDone(char *p) { p[0x11f5]=1; }


void POKETRADE_2D_CreateCursorActor(char *p, int x, int y) {
    Callback cb;
    Create c;
    c.x=x+12;c.y=y+12;c.z=24;c.a=0;c.b=0;
    POKETRADE_2D_DeleteCursorActor(p);
    ((TradeWork *)p)->fF24=(int)CLACT_CreateActor((void *)((TradeWork *)p)->clactSystem,((TradeWork *)p)->f894,((TradeWork *)p)->f880,((TradeWork *)p)->f8B0,&c,1,((TradeWork *)p)->heapId);
    CLACT_SetActorDrawEnable((struct Obj *)((TradeWork *)p)->fF24,1);
    CLACT_SetActorAutoAnim((struct Obj *)((TradeWork *)p)->fF24,1);
    p[0x11f5]=0;
    cb.v=0;cb.p=p;cb.fn=(void (*)(void *))POKETRADE_2D_OnCursorAnimDone;
    CLACT_ApplyActorAnimCommand((struct Actor *)(((TradeWork *)p)->fF24),(const struct Cmd *)(&cb));
}



void POKETRADE_2D_DeleteCursorActor(void *p)
{
    if (((TradeWork *)p)->fF24) {
        CLACT_DeleteActor((struct Obj *)(((TradeWork *)p)->fF24));
        ((TradeWork *)p)->fF24 = 0;
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
    Slot *s;
    char *buf;
    int i;
    int off;
    s=PALANM_Create(((TradeWork *)p)->heapId);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)s,bank,0x200,((TradeWork *)p)->heapId);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)s,bank,0,0x200);
    PALANM_BlendChannel((struct Chan02021FD8 *)s,bank,0,0x100,6,0);
    buf=(char *)PALANM_GetTransWork((char *)s,bank);
    for(i=0;i<16;i++) {
        if(mask & (1<<i)) {
            off=i*32;
            DWCi_ScreenDC_FlushRange(buf+off,32);
            switch(bank) {
            case 3: func_0207E5D0(buf+off,off,32); break;
            case 1: func_0207E468(buf+off,off,32); break;
            case 2: GX_LoadOBJPltt(buf+off,off,32); break;
            case 0: GX_LoadBGPltt(buf+off,off,32); break;
            }
        }
    }
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)s,bank);
    PALANM_Delete(s);
}



void POKETRADE_2D_FadePaletteCopy(void *p, int a1, int a2, int a3)
{
    if (a1 != 0) {
        if (a2 == 3)
            MI_CpuCopy8((void *)0x05000600, ((TradeWork *)p)->subObjPaletteCopy,
                          0x200);
        else if (a2 == 1)
            MI_CpuCopy8((void *)0x05000400, ((TradeWork *)p)->subBgPaletteCopy,
                          0x200);
        POKETRADE_2D_FadePaletteBank(p, a2, a3);
        return;
    }
    if (a2 == 3) {
        DWCi_ScreenDC_FlushRange(((TradeWork *)p)->subObjPaletteCopy, 0x200);
        func_0207E5D0(((TradeWork *)p)->subObjPaletteCopy, 0, 0x200);
        return;
    }
    if (a2 == 1) {
        DWCi_ScreenDC_FlushRange(((TradeWork *)p)->subBgPaletteCopy, 0x200);
        func_0207E468(((TradeWork *)p)->subBgPaletteCopy, 0, 0x200);
    }
}



void POKETRADE_2D_FadePaletteAll(void *p, int a)
{
    POKETRADE_2D_FadePaletteCopy(p, a, 3, 0xfffe);
}



/*
 * func_020056BC (ARM9, unlabelled Thumb leaf) was filed EXACT by the
 * dependency-tree lane and now attests this call through `matched`.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a)
{
    func_02030DA8(func_020056BC(), (void (*)(void))POKETRADE_2D_TaskSetMainPlaneVisible, a, 0xa);
}



void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a)
{
    func_02030DA8(func_020056BC(), (void (*)(void))POKETRADE_2D_TaskSetSubPlaneVisible, a, 0xa);
}



void POKETRADE_2D_TaskSetMainPlaneVisible(void *p, int a)
{
    BG_SYS_SetMainVisiblePlanes(a);
    func_02030EAC(p);
}



void POKETRADE_2D_TaskSetSubPlaneVisible(void *p, int a)
{
    BG_SYS_SetSubVisiblePlanes(a);
    func_02030EAC(p);
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
