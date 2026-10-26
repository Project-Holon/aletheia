/*
 * file:     fldmmdl_move.c
 * unit:     yes
 * function: FLDMMDL_MOVE_SetupMove, FLDMMDL_MOVE_UpdateMove, FLDMMDL_MOVE_IsMoveProcAllowed, FLDMMDL_MOVE_UpdateHeightIfRequested, FLDMMDL_MOVE_UpdateAttrIfRequested, FLDMMDL_MOVE_ProcMoveStartFirst, FLDMMDL_MOVE_ProcMoveStartSecond, FLDMMDL_MOVE_ProcMoveEnd, FLDMMDL_MOVE_InitAttrInfo, FLDMMDL_MOVE_AttrProcMoveStartFirst, FLDMMDL_MOVE_AttrProcMoveStartSecond, FLDMMDL_MOVE_AttrProcJumpStart, FLDMMDL_MOVE_AttrProcMoveEnd, FLDMMDL_MOVE_AttrProcJumpEnd, FLDMMDL_MOVE_AttrSetDrawOffset, FLDMMDL_MOVE_GetFootMarkKind, FLDMMDL_MOVE_AttrEffectFootMark, FLDMMDL_MOVE_AttrEffectFootMarkIfFlag, FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag, FLDMMDL_MOVE_AttrEffectFootMarkJump, FLDMMDL_MOVE_AttrEffectGround, FLDMMDL_MOVE_AttrEffectReflect, FLDMMDL_MOVE_AttrEffectReflectOrBridge, FLDMMDL_MOVE_AttrEffectReflectOff, FLDMMDL_MOVE_CanShowShadow, FLDMMDL_MOVE_IsShadowAttr, FLDMMDL_MOVE_AttrEffectShadowStart, FLDMMDL_MOVE_AttrEffectShadowUpdate, FLDMMDL_MOVE_AttrEffectDust, FLDMMDL_MOVE_AttrEffectSplashOldPos, FLDMMDL_MOVE_AttrEffectSplashNowPos, FLDMMDL_MOVE_AttrEffectLongGrassStart, FLDMMDL_MOVE_AttrEffectLongGrassEnd, FLDMMDL_MOVE_AttrEffectSpecial, FLDMMDL_MOVE_AttrEffectNone, FLDMMDL_MOVE_HitCheckMove, FLDMMDL_MOVE_HitCheckMoveCurrent, FLDMMDL_MOVE_HitCheckMoveDir, FLDMMDL_MOVE_GetGridRect, FLDMMDL_MOVE_IsRectOverlap, FLDMMDL_MOVE_HitCheckObjectRect, FLDMMDL_MOVE_HitCheckOtherObjects, FLDMMDL_MOVE_IsGridInObjectRect, FLDMMDL_MOVE_HitCheckMoveLimit, FLDMMDL_MOVE_HitCheckAttr, FLDMMDL_MOVE_GetFieldG3dMapHit, FLDMMDL_MOVE_GetMapAttr, FLDMMDL_MOVE_GetMapHeight, FLDMMDL_MOVE_UpdateGridPosDir, FLDMMDL_MOVE_UpdateOldGridPos, FLDMMDL_MOVE_GetDirMapAttr, FLDMMDL_MOVE_AddVectorPos, FLDMMDL_MOVE_AddDirVectorPos, FLDMMDL_MOVE_UpdateHeight, FLDMMDL_MOVE_UpdateMapAttr, FLDMMDL_MOVE_IsNearPlayer, FLDMMDL_MOVE_StopAcmdWalkCodes, FLDMMDL_MOVE_GetDirAddGridX, FLDMMDL_MOVE_GetDirAddGridZ, FLDMMDL_MOVE_AddDirVector, FLDMMDL_MOVE_AddDirGrid, FLDMMDL_MOVE_GridToVectorPos, FLDMMDL_MOVE_GridToVector, FLDMMDL_MOVE_GetDirTableValue, FLDMMDL_MOVE_GetDirFromPoints, FLDMMDL_MOVE_GetRelativeDirCode, FLDMMDL_MOVE_SetStatusPauseDraw, FLDMMDL_MOVE_RequestRailMove, FLDMMDL_MOVE_SetRailMoveRequest, FLDMMDL_MOVE_GetRailMoveRequest
 * address:  0x02163010
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Field model movement, attribute effects and hit checks (guess: fldmmdl move code).
 *
 * symbols:
 *   ZONEDATA_DirToRailKey 0x0201441C thumb
 *   FLDMMDL_CallMoveInitProc  0x0216D6F4  thumb  ov010
 *   FLDMMDL_MOVECODE_InitEventTypeProcThunk  0x0219B414  thumb  ov021
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_CheckSysStatusBit  0x0216DA20  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ACMD_RunCmds  0x02197EB4  thumb  ov021
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_MOVECODE_UpdateEventTypeProc  0x0219B41C  thumb  ov021
 *   FLDMMDL_CallMoveProc  0x0216D708  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_GetMoveBit  0x0216D564  thumb  ov010
 *   FLDMMDL_CheckStatusBitHeightGetOff  0x0216DB68  thumb  ov010
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 *   FLDMMDL_OnMoveBitMoveStart 0x0216DA70 thumb ov010
 *   FLDMMDL_ClearMoveBit 0x0216D570 thumb ov010
 *   MI_CpuFill  0x02082C60  arm
 *   FLDMMDL_GetOldAttr  0x0216D7E4  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELD_EFFECT_GetModelBaseOffset  0x021ABE28  thumb  ov021
 *   FLDMMDL_CheckDrawInitComp  0x0216DB24  thumb  ov010
 *   FLDMMDL_CheckStatusBitAttrOffsetOff 0x0216DC00 thumb ov010
 *   MAP_ATTR_IsSand 0x021AB41C thumb ov021
 *   FLDMMDL_SetAttrOffset 0x0216D900 thumb ov010
 *   d_021714D0 0x021714D0 data ov010 a4
 *   MAP_ATTR_IsGrassSingleC  0x021AB4EC  thumb
 *   MAP_ATTR_IsGrassDoubleC  0x021AB4F8  thumb
 *   MAP_ATTR_IsGrassDoubleB  0x021AB434  thumb
 *   MAP_ATTR_IsGrassSingleB  0x021AB428  thumb
 *   MAP_ATTR_IsGrassDouble  0x021AB250  thumb
 *   MAP_ATTR_IsTallGrassSingle  0x021AB264  thumb
 *   MAP_ATTR_IsTallGrassDouble  0x021AB270  thumb
 *   FLDEFF_GRASS_Start  0x021AC760  thumb
 *   FLDMMDL_GetDirMove 0x0216D608 thumb ov010
 *   MAP_ATTR_IsPuddle  0x021AB3D4  thumb
 *   MAP_ATTR_IsMud  0x021AB3E0  thumb
 *   MAP_ATTR_IsSnowTile  0x021AB334  thumb
 *   MAP_ATTR_IsDeepSnow  0x021AB328  thumb
 *   FLDEFF_FOOTMARK_SetMMdl  0x021BBDD4  thumb
 *   MAP_ATTR_IsSplashWater  0x021AB304  thumb
 *   FLDMMDL_CheckMoveBitSplash  0x0216DBE8  thumb  ov010
 *   FLDEFF_SPLASH_AddModel  0x021C4BE0  thumb
 *   FLDMMDL_SetMoveBitSplash  0x0216DBCC  thumb  ov010
 *   MAP_ATTR_IsSplashWaterB  0x021AB364  thumb
 *   FLDEFF_SPLASH_AddBoard  0x021C4A10  thumb
 *   FLDMMDL_SysIsDrawEnable  0x0216D98C  thumb  ov010
 *   FLDEFF_SHADOW_Start  0x021AC2C0  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_CheckMoveBitShadowVanish 0x0216DD04 thumb ov010
 *   FLDEFF_KEMURI_Start 0x021AC528 thumb ov021
 *   MAP_ATTR_IsRippleWater  0x021AB2F8  thumb
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDEFF_RIPPLE_Start  0x021C484C  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   MAP_ATTR_IsMirrorFloor  0x021AB440  thumb  ov021
 *   MAP_ATTR_IsIce  0x021AB358  thumb  ov021
 *   FLDEFF_REFLECT_SetMMdl  0x021BBFB8  thumb  ov021
 *   MAP_ATTR_IsElectricFloor  0x021AB3EC  thumb
 *   FLDEFF_D06DENKI_StartSpark  0x021C8F7C  thumb  ov021
 *   FLDMMDL_SysGetG3dMapper  0x0216D52C  thumb  ov010
 *   FIELD_G3D_MAPPER_IsOutsideGrid  0x0218DC04  thumb  ov021
 *   FLDMMDL_GetPos 0x0216D88C thumb ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetSizeWidth 0x0216D91C thumb ov010
 *   FLDMMDL_GetSizeDepth 0x0216D924 thumb ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetGridOldY  0x0216D810  thumb  ov010
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb
 *   FLDMMDL_GetMoveLimitX  0x0216D660  thumb
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb
 *   FLDMMDL_GetMoveLimitZ  0x0216D66C  thumb
 *   MAP_ATTR_IsBlocked  0x021AB11C  thumb  ov021
 *   d_021714A0     0x021714A0  data
 *   d_02171490     0x02171490  data
 *   FIELD_G3D_MAPPER_QueryNearestHit 0x0218DAEC thumb ov021
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb
 *   FLDMMDL_AddGridNowX  0x0216D848  thumb
 *   FLDMMDL_AddGridNowZ  0x0216D87C  thumb
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb
 *   FLDMMDL_SetPos 0x0216D89C thumb ov010
 *   FLDMMDL_SetOldAttr  0x0216D7E0  thumb
 *   FLDMMDL_SetNowAttr  0x0216D7D8  thumb
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb
 *   d_02171480 0x02171480 data a4
 *   d_02171470 0x02171470 data a4
 *   d_021714B0     0x021714B0  data  a4
 *   d_02171458     0x02171458  data  a2
 *   d_02171460     0x02171460  data
 *   d_021714C0     0x021714C0  data  a4
 *   FLDMMDL_SysCheckStatusBit  0x0216D4D4  thumb
 *   FLDMMDL_RAIL_SetLocation  0x0219E2C0  thumb
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb
 *   FLDMMDL_GetMoveProcWork 0x0216D69C thumb ov010
 */

struct MapGrid;

#include "../ov021/fldmmdl_rail_types.h"
#include "fldmmdl_types.h"
#include "field_g3d_map_types.h"

#include "../types.h"

/* Grid place of a bg event: one cell, height within 2. */
typedef struct BgEventGridPos {
    s32 x;              /* 0x08 */
    s32 z;              /* 0x0C */
    s32 y;              /* 0x10 */
} BgEventGridPos;

/* Rail place of a bg event. */
typedef struct BgEventRailPos {
    u16 railIndex;      /* 0x08 */
    u16 lineGrid;       /* 0x0A */
    s16 widthGrid;      /* 0x0C */
} BgEventRailPos;

/* A bg event record (sign, hidden item), 0x14 bytes. */
typedef struct BgEventData {
    u16 scriptId;       /* 0x00 */
    u16 type;           /* 0x02: 2 hidden item */
    u16 dir;            /* 0x04: which talk directions fire it, 0..6 */
    u16 posType;        /* 0x06: 0 grid, 1 rail */
    union {
        s32 word[3];
        BgEventGridPos grid;
        BgEventRailPos rail;
    } pos;              /* 0x08 */
} BgEventData;

/* A stored rail move request: a RailLocation, valid while magic is 0xEFEFEFEF. */
typedef struct RailMoveRequest {
    u32 magic;          /* 0x00 */
    u16 location[4];    /* 0x04: RailLocation as halfwords */
} RailMoveRequest;

#include "../sdk_fx.h"

/* Map attributes under a field model and its draw parameters, read once per
 * step check (FLDMMDL_MOVE_InitAttrInfo). An attribute is a u32: value in the low 16
 * bits, flags in the high 16 bits. */
typedef struct EventInfo {
    int nowAttr;                    /* 0x00 */
    int oldAttr;                    /* 0x04 */
    u16 nowAttrValue;               /* 0x08 */
    u16 oldAttrValue;               /* 0x0A */
    u16 nowAttrFlag;                /* 0x0C */
    u16 oldAttrFlag;                /* 0x0E */
    MmdlObjCodeParam *objCodeParam; /* 0x10 */
    struct FieldEffectSys *effectCtrl; /* 0x14 */
    u8 effectMode;                  /* 0x18: 0 and 3 checked */
} EventInfo;

typedef struct { s16 x0, y0, x1, y1; } Rect;

typedef int (*AttrTest)(u16 attr);


/* A 4-byte entry of the direction table d_021714C0 (FLDMMDL_MOVE_GetRelativeDirCode reads the second byte). */
typedef struct DirLookupEntry {
    u8 entry0;          /* 0x00 */
    u8 dirCode;         /* 0x01 */
    u8 entry2;          /* 0x02 */
    u8 entry3;          /* 0x03 */
} DirLookupEntry;

#include "../arm9/zonedata.h"
extern void FLDMMDL_CallMoveInitProc(Mmdl *mmdl);
#include "../ov021/fldmmdl_movecode.h"
struct Mmdl;
extern u32 FLDMMDL_CheckSysStatusBit(Mmdl *mmdl, unsigned int v);
extern unsigned int FLDMMDL_CheckMoveBit(Mmdl *mmdl, unsigned int v);
#include "../ov021/fldmmdl_acmd.h"
extern int FLDMMDL_CheckMoveBitMovePause(Mmdl *mmdl);
extern void FLDMMDL_CallMoveProc(Mmdl *mmdl);
extern int FLDMMDL_CheckMoveBitMove(Mmdl *mmdl);
extern u16 FLDMMDL_GetMoveCode(Mmdl *mmdl);
extern u32 FLDMMDL_GetMoveBit(Mmdl *mmdl);
extern int FLDMMDL_CheckStatusBitHeightGetOff(Mmdl *mmdl);
extern int FLDMMDL_CheckStatusBitAttrGetOff(Mmdl *mmdl);
extern void FLDMMDL_OnMoveBitMoveStart(Mmdl *mmdl);
extern void FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 v);
#include "../arm9/mi_memory.h"
extern u32 FLDMMDL_GetOldAttr(Mmdl *mmdl);
extern u32 FLDMMDL_GetNowAttr(Mmdl *mmdl);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(Mmdl *mmdl);
extern MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
struct MmdlSys;
extern void *FLDMMDL_SysGetFieldMap(MmdlSys *mmdlSys);
struct FieldMap;
struct FieldEffectCont;
#include "../ov021/fieldmap.h"
struct FieldEffectSys;
#include "../ov021/field_effect.h"
extern int FLDMMDL_CheckDrawInitComp(Mmdl *mmdl);
extern int FLDMMDL_CheckStatusBitAttrOffsetOff(Mmdl *mmdl);
extern int MAP_ATTR_IsSand(unsigned short);
struct VecFx32;
extern int MAP_ATTR_IsGrassSingleC(u16 terrainId);
extern int MAP_ATTR_IsGrassDoubleC(u16 terrainId);
extern int MAP_ATTR_IsGrassDoubleB(u16 terrainId);
extern int MAP_ATTR_IsGrassSingleB(u16 terrainId);
extern int MAP_ATTR_IsGrassDouble(u16 terrainId);
extern int MAP_ATTR_IsTallGrassSingle(u16 terrainId);
extern int MAP_ATTR_IsTallGrassDouble(u16 terrainId);
#include "../ov021/fldeff_grass.h"
extern u16 FLDMMDL_GetDirMove(Mmdl *mmdl);
extern int MAP_ATTR_IsPuddle(s32 terrainId);
extern int MAP_ATTR_IsMud(u16 terrainId);
extern int MAP_ATTR_IsSnowTile(u16 terrainId);
extern int MAP_ATTR_IsDeepSnow(s32 terrainId);
#include "../ov021/fldeff_footmark.h"
extern int MAP_ATTR_IsSplashWater(u16 terrainId);
extern int FLDMMDL_CheckMoveBitSplash(Mmdl *mmdl);
extern int FLDMMDL_SysIsDrawEnable(MmdlSys *mmdlSys);
#include "../ov021/fldeff_shadow.h"
extern void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 v);
extern int FLDMMDL_CheckMoveBitShadowVanish(Mmdl *mmdl);
#include "../ov021/fldeff_kemuri.h"
extern int MAP_ATTR_IsRippleWater(s32 terrainId);
extern int FLDMMDL_GetGridOldX(Mmdl *mmdl);
extern int FLDMMDL_GetGridOldZ(Mmdl *mmdl);
extern s32 FLDMMDL_GetPosY(Mmdl *mmdl);
#include "../ov021/fldeff_ripple.h"
#ifdef __MWERKS__
extern int FLDMMDL_GetGridNowX(Mmdl *mmdl); /* original prototype; the definition returns short */
extern int FLDMMDL_GetGridNowZ(Mmdl *mmdl);
#else
extern short FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern short FLDMMDL_GetGridNowZ(Mmdl *mmdl);
#endif
extern int FLDMMDL_CheckMoveBitReflect(Mmdl *mmdl);
extern void FLDMMDL_SetMoveBitReflect(Mmdl *mmdl, int flag);
extern int MAP_ATTR_IsIce(int x);
#include "../ov021/fldeff_reflect.h"
extern int MAP_ATTR_IsElectricFloor(u16 id);
#include "../ov021/fldeff_d06denki.h"
extern void *FLDMMDL_SysGetG3dMapper(MmdlSys *mmdlSys);
struct FieldG3dMapper;
#include "../ov021/field_g3d_mapper.h"
extern u8 FLDMMDL_GetSizeWidth(Mmdl *mmdl);
extern u8 FLDMMDL_GetSizeDepth(Mmdl *mmdl);
extern u32 FLDMMDL_CheckStatusBit(struct Mmdl *mmdl, u32 bit);
extern int FLDMMDL_GetGridOldY(Mmdl *mmdl);
extern int FLDMMDL_GetGridInitX(Mmdl *mmdl);
extern int FLDMMDL_GetMoveLimitX(Mmdl *mmdl);
extern int FLDMMDL_GetGridInitZ(Mmdl *mmdl);
extern int FLDMMDL_GetMoveLimitZ(Mmdl *mmdl);
extern int MAP_ATTR_IsBlocked(u32 attr);
extern void FLDMMDL_SetGridOldY(struct Mmdl *mmdl, s16 y);
extern void FLDMMDL_SetAttrOffset(struct Mmdl *mmdl, struct VecFx32 *offset);
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct VecFx32 *out);
extern void FLDMMDL_SetPos(struct Mmdl *mmdl, struct VecFx32 *pos);
extern short FLDMMDL_GetGridNowY(struct Mmdl*);
extern int FLDMMDL_SysSearchUseMmdl(MmdlSys *mmdlSys, Mmdl **out, u32 *iter);
#ifdef __MWERKS__
extern void FLDMMDL_SetGridOldX(Mmdl *mmdl, int b); /* original prototype; the definition differs in argument width */
#else
extern void FLDMMDL_SetGridOldX(struct Mmdl*, s16);
#endif
#ifdef __MWERKS__
extern void FLDMMDL_SetGridOldZ(Mmdl *mmdl, int b); /* original prototype; the definition differs in argument width */
#else
extern void FLDMMDL_SetGridOldZ(struct Mmdl*, s16);
#endif
extern void FLDMMDL_AddGridNowX(struct Mmdl*, s16);
extern void FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_SetMoveBitSplash(Mmdl *mmdl, u32 flag);
extern void FLDMMDL_AddGridNowZ(struct Mmdl*, s16);
extern void FLDMMDL_SetGridNowY(Mmdl *mmdl, int v);
extern void FLDMMDL_SetOldAttr(Mmdl *mmdl, u32 v);
extern void FLDMMDL_SetNowAttr(Mmdl *mmdl, u32 v);
extern Mmdl *FLDMMDL_SysSearchPlayer(MmdlSys *mmdlSys);
extern u32 FLDMMDL_SysCheckStatusBit(struct MmdlSys *sys, u32 bit);
#include "../ov021/fldmmdl_rail.h"
#include "../ov021/fldeff_splash.h"
#ifdef __MWERKS__
extern int MAP_ATTR_IsSplashWaterB(u32 attr); /* original prototype: the definition takes u16 */
#ifdef __MWERKS__
extern int MAP_ATTR_IsMirrorFloor(u32 attr); /* original prototype; the definition differs in argument width */
#else
extern s32 MAP_ATTR_IsMirrorFloor(u16);
#endif
#else
#include "../ov021/map_attr.h"
#endif
extern void *FLDMMDL_InitMoveProcWork(Mmdl *mmdl, int b);
extern void *FLDMMDL_GetMoveProcWork(Mmdl *mmdl);
void FLDMMDL_MOVE_SetupMove(Mmdl *mmdl);
void FLDMMDL_MOVE_UpdateMove(Mmdl *mmdl);
int FLDMMDL_MOVE_IsMoveProcAllowed(Mmdl *mmdl);
int FLDMMDL_MOVE_UpdateHeightIfRequested(Mmdl *mmdl);
void FLDMMDL_MOVE_UpdateAttrIfRequested(Mmdl *mmdl);
void FLDMMDL_MOVE_ProcMoveStartFirst(Mmdl *mmdl);
void FLDMMDL_MOVE_ProcMoveStartSecond(Mmdl *mmdl);
void FLDMMDL_MOVE_ProcMoveEnd(Mmdl *mmdl);
void FLDMMDL_MOVE_InitAttrInfo(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrProcMoveStartFirst(Mmdl *mmdl);
void FLDMMDL_MOVE_AttrProcMoveStartSecond(Mmdl *mmdl);
void FLDMMDL_MOVE_AttrProcJumpStart(Mmdl *mmdl);
void FLDMMDL_MOVE_AttrProcMoveEnd(Mmdl *mmdl);
void FLDMMDL_MOVE_AttrProcJumpEnd(Mmdl *mmdl);
void FLDMMDL_MOVE_AttrSetDrawOffset(Mmdl *mmdl, EventInfo *info);
int FLDMMDL_MOVE_GetFootMarkKind(u16 attrValue, u8 effectMode);
void FLDMMDL_MOVE_AttrEffectFootMark(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectFootMarkIfFlag(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectFootMarkJump(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectGround(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectReflect(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectReflectOrBridge(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectReflectOff(Mmdl *mmdl, EventInfo *info);
int FLDMMDL_MOVE_CanShowShadow(Mmdl *mmdl, EventInfo *info);
int FLDMMDL_MOVE_IsShadowAttr(EventInfo *info);
void FLDMMDL_MOVE_AttrEffectShadowStart(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectShadowUpdate(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectDust(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectSplashOldPos(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectSplashNowPos(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectLongGrassStart(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectLongGrassEnd(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectSpecial(Mmdl *mmdl, EventInfo *info);
void FLDMMDL_MOVE_AttrEffectNone(Mmdl *mmdl, EventInfo *info);
u32 FLDMMDL_MOVE_HitCheckMove(Mmdl *mmdl, VecFx32 *currentPos, s16 gridX, s16 height, int gridZ, u16 kind);
u32 FLDMMDL_MOVE_HitCheckMoveCurrent(Mmdl *mmdl, s16 gridX, s16 height, int gridZ, u16 kind);
u32 FLDMMDL_MOVE_HitCheckMoveDir(Mmdl *mmdl, u16 dir);
void FLDMMDL_MOVE_GetGridRect(Mmdl *mmdl, int gridX, int gridZ, Rect *out);
int FLDMMDL_MOVE_IsRectOverlap(Rect *rectA, Rect *rectB);
int FLDMMDL_MOVE_HitCheckObjectRect(Mmdl *mmdl, Mmdl *other, int gridX, int height, s16 gridZ, int checkNext);
int FLDMMDL_MOVE_HitCheckOtherObjects(Mmdl *mmdl, int gridX, int height, s16 gridZ);
int FLDMMDL_MOVE_IsGridInObjectRect(Mmdl *mmdl, int gridX, int gridZ, int checkNext);
int FLDMMDL_MOVE_HitCheckMoveLimit(Mmdl *mmdl, int gridX, int gridZ);
int FLDMMDL_MOVE_HitCheckAttr(Mmdl *mmdl, u32 kind, VecFx32 topLeft);
int FLDMMDL_MOVE_GetFieldG3dMapHit(Mmdl *mmdl, VecFx32 *pos, FieldG3dMapHit *info);
int FLDMMDL_MOVE_GetMapAttr(Mmdl *mmdl, VecFx32 *pos, u32 *outAttr);
int FLDMMDL_MOVE_GetMapHeight(Mmdl *mmdl, VecFx32 *pos, int *outHeight);
void FLDMMDL_MOVE_UpdateGridPosDir(Mmdl *mmdl, int dir);
void FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl);
int FLDMMDL_MOVE_GetDirMapAttr(Mmdl *mmdl, int dir);
void FLDMMDL_MOVE_AddVectorPos(Mmdl *mmdl, const VecFx32 *delta);
void FLDMMDL_MOVE_AddDirVectorPos(Mmdl *mmdl, int dir, int amount);
int FLDMMDL_MOVE_UpdateHeight(Mmdl *mmdl);
int FLDMMDL_MOVE_UpdateMapAttr(Mmdl *mmdl);
int FLDMMDL_MOVE_IsNearPlayer(Mmdl *mmdl);
void FLDMMDL_MOVE_StopAcmdWalkCodes(Mmdl *mmdl);
s16 FLDMMDL_MOVE_GetDirAddGridX(int dir);
s16 FLDMMDL_MOVE_GetDirAddGridZ(int dir);
void FLDMMDL_MOVE_AddDirVector(int dir, VecFx32 *pos, int amount);
void FLDMMDL_MOVE_AddDirGrid(int dir, s16 *x, s16 *z, s16 amount);
void FLDMMDL_MOVE_GridToVectorPos(int gridX, int gridZ, VecFx32 *pos);
void FLDMMDL_MOVE_GridToVector(int gridX, int gridY, int gridZ, VecFx32 *pos);
u16 FLDMMDL_MOVE_GetDirTableValue(int index);
u16 FLDMMDL_MOVE_GetDirFromPoints(int fromX, int fromZ, int toX, int toZ);
u8 FLDMMDL_MOVE_GetRelativeDirCode(int tableIndex, int offset);
void FLDMMDL_MOVE_SetStatusPauseDraw(Mmdl *mmdl);
void FLDMMDL_MOVE_RequestRailMove(Mmdl *mmdl, MmdlHeader *header);
void FLDMMDL_MOVE_SetRailMoveRequest(Mmdl *mmdl, const u16 *locationWords);
int FLDMMDL_MOVE_GetRailMoveRequest(Mmdl *mmdl, u16 *outWords);
extern VecFx32 d_021714D0;
extern const AttrTest d_021714A0[];
extern const AttrTest d_02171490[];
extern const int d_02171480[];
extern const int d_02171470[];
extern u32 d_021714B0[];
extern u16 d_02171458[];
extern u8 d_02171460[];
extern DirLookupEntry d_021714C0[];

/*
 * Unblocked by the recursive MATCH unblocker: the +000A call targets
 * 0x0219B414, a labelless Thumb tail-call thunk in ov021 now matched in
 * src/matched/FLDMMDL_MOVECODE_InitEventTypeProcThunk.c, so the site attests as `matched`.
 */
void FLDMMDL_MOVE_SetupMove(Mmdl *mmdl)
{
    FLDMMDL_CallMoveInitProc(mmdl);
    FLDMMDL_MOVECODE_InitEventTypeProcThunk(mmdl);
    FLDMMDL_SetStatusBit(mmdl, 2);
}

void FLDMMDL_MOVE_UpdateMove(Mmdl *mmdl)
{
    int mask = 2;

    if (FLDMMDL_CheckSysStatusBit(mmdl, mask) == 0) {
        FLDMMDL_MOVE_UpdateHeightIfRequested(mmdl);
        FLDMMDL_MOVE_UpdateAttrIfRequested(mmdl);
        FLDMMDL_MOVE_ProcMoveStartFirst(mmdl);
        if (FLDMMDL_CheckMoveBit(mmdl, mask << 8) != 0) {
            FLDMMDL_ACMD_RunCmds((struct Mmdl *)mmdl);
        } else if (FLDMMDL_CheckMoveBitMovePause(mmdl) == 0) {
            if (FLDMMDL_MOVE_IsMoveProcAllowed(mmdl) == 1) {
                if (FLDMMDL_MOVECODE_UpdateEventTypeProc(mmdl) == 0) {
                    FLDMMDL_CallMoveProc(mmdl);
                }
            }
        }
        FLDMMDL_MOVE_ProcMoveStartSecond(mmdl);
        FLDMMDL_MOVE_ProcMoveEnd(mmdl);
    }
}

int FLDMMDL_MOVE_IsMoveProcAllowed(Mmdl *mmdl)
{
    u32 statusBits;

    if (FLDMMDL_CheckMoveBitMove(mmdl) == 0) {
        if (FLDMMDL_CheckMoveBit(mmdl, 0x1800) == 0)
            return 1;
        if (FLDMMDL_GetMoveCode(mmdl) == 0x32)
            return 1;
        statusBits = FLDMMDL_GetMoveBit(mmdl);
        if ((statusBits & 0x1000) != 0 && FLDMMDL_CheckStatusBitHeightGetOff(mmdl) == 0)
            return 0;
        if ((statusBits & 0x800) != 0 && FLDMMDL_CheckStatusBitAttrGetOff(mmdl) == 0)
            return 0;
    }
    return 1;
}

int FLDMMDL_MOVE_UpdateHeightIfRequested(Mmdl *mmdl)
{
    u32 hasBit = FLDMMDL_CheckMoveBit(mmdl, 0x1000);

    if (hasBit != 0)
        return FLDMMDL_MOVE_UpdateHeight(mmdl);
    return hasBit;
}

/*
 * trailing: two-byte zero alignment at 0x0216312E before FLDMMDL_MOVE_ProcMoveStartFirst.
 */
void FLDMMDL_MOVE_UpdateAttrIfRequested(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, 0x800) != 0 && FLDMMDL_MOVE_UpdateMapAttr(mmdl) == 1)
        FLDMMDL_OnMoveBitMoveStart(mmdl);
}

void FLDMMDL_MOVE_ProcMoveStartFirst(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, 0x20)) {
        FLDMMDL_MOVE_StopAcmdWalkCodes(mmdl);
        FLDMMDL_MOVE_AttrProcMoveStartFirst(mmdl);
    }
    FLDMMDL_ClearMoveBit(mmdl, 0xa0);
}

/*
 * trailing: two-byte zero alignment at 0x02163186 before FLDMMDL_MOVE_ProcMoveEnd.
 */
void FLDMMDL_MOVE_ProcMoveStartSecond(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, 0x80)) FLDMMDL_MOVE_AttrProcJumpStart(mmdl);
    else if (FLDMMDL_CheckMoveBit(mmdl, 0x20)) FLDMMDL_MOVE_AttrProcMoveStartSecond(mmdl);
    FLDMMDL_ClearMoveBit(mmdl, 0xa0);
}

/*
 * trailing: two-byte zero alignment at 0x021631BE before FLDMMDL_MOVE_InitAttrInfo.
 */
void FLDMMDL_MOVE_ProcMoveEnd(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, 0x100)) FLDMMDL_MOVE_AttrProcJumpEnd(mmdl);
    else if (FLDMMDL_CheckMoveBit(mmdl, 0x40)) FLDMMDL_MOVE_AttrProcMoveEnd(mmdl);
    FLDMMDL_ClearMoveBit(mmdl, 0x140);
}

void FLDMMDL_MOVE_InitAttrInfo(Mmdl *mmdl, EventInfo *info)
{
    int oldAttr;
    struct FieldEffectSys *effectCtrl;

    MI_CpuFill(info, 0, sizeof(*info));
    info->nowAttr = FLDMMDL_GetOldAttr(mmdl);
    oldAttr = FLDMMDL_GetNowAttr(mmdl);
    info->oldAttr = oldAttr;
    if (oldAttr != -1) {
        info->oldAttrValue = MAP_ATTR_GetTerrainId(oldAttr);
        info->oldAttrFlag = MAP_ATTR_GetFlags(info->oldAttr);
    }
    if (info->nowAttr != -1) {
        info->nowAttrValue = MAP_ATTR_GetTerrainId(info->nowAttr);
        info->nowAttrFlag = MAP_ATTR_GetFlags(info->nowAttr);
    }
    info->objCodeParam = FLDMMDL_GetObjCodeParam(mmdl);
    effectCtrl = (struct FieldEffectSys *)FIELDMAP_GetEffect((struct FieldMap *)FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys(mmdl)));
    info->effectCtrl = effectCtrl;
    info->effectMode = FIELD_EFFECT_GetModelBaseOffset((struct FieldEffectSys *)effectCtrl);
}

void FLDMMDL_MOVE_AttrProcMoveStartFirst(Mmdl *mmdl)
{
    EventInfo info;

    FLDMMDL_MOVE_UpdateMapAttr(mmdl);
    if (FLDMMDL_CheckMoveBit(mmdl, 0x800) == 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        FLDMMDL_MOVE_InitAttrInfo(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectFootMark(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectReflect(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectShadowStart(mmdl, &info);
        FLDMMDL_MOVE_AttrSetDrawOffset(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectLongGrassStart(mmdl, &info);
    }
}

void FLDMMDL_MOVE_AttrProcMoveStartSecond(Mmdl *mmdl)
{
    EventInfo info;

    FLDMMDL_MOVE_UpdateMapAttr(mmdl);
    if (FLDMMDL_CheckMoveBit(mmdl, 0x800) == 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        FLDMMDL_MOVE_InitAttrInfo(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectFootMarkIfFlag(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectGround(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectReflectOrBridge(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectShadowStart(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectSplashOldPos(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectLongGrassStart(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectNone(mmdl, &info);
    }
}

void FLDMMDL_MOVE_AttrProcJumpStart(Mmdl *mmdl)
{
    EventInfo info;

    FLDMMDL_MOVE_UpdateMapAttr(mmdl);
    if (FLDMMDL_CheckMoveBit(mmdl, 0x800) == 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        FLDMMDL_MOVE_InitAttrInfo(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectShadowStart(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectLongGrassStart(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectReflectOff(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectNone(mmdl, &info);
    }
}

void FLDMMDL_MOVE_AttrProcMoveEnd(Mmdl *mmdl)
{
    EventInfo info;

    FLDMMDL_MOVE_UpdateMapAttr(mmdl);
    if (FLDMMDL_CheckMoveBit(mmdl, 0x800) == 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        FLDMMDL_MOVE_InitAttrInfo(mmdl, &info);
        FLDMMDL_MOVE_AttrSetDrawOffset(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectSplashNowPos(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectReflectOrBridge(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectLongGrassEnd(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectShadowUpdate(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectSpecial(mmdl, &info);
    }
}

void FLDMMDL_MOVE_AttrProcJumpEnd(Mmdl *mmdl)
{
    EventInfo info;

    FLDMMDL_MOVE_UpdateMapAttr(mmdl);
    if (FLDMMDL_CheckMoveBit(mmdl, 0x800) == 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        FLDMMDL_MOVE_InitAttrInfo(mmdl, &info);
        FLDMMDL_MOVE_AttrSetDrawOffset(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectSplashNowPos(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectReflectOrBridge(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectLongGrassEnd(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectShadowUpdate(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectFootMarkJump(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectDust(mmdl, &info);
        FLDMMDL_MOVE_AttrEffectSpecial(mmdl, &info);
    }
}

static inline void vzero(VecFx32 *pos)
{
    pos->x = 0;
    pos->y = 0;
    pos->z = 0;
}

/*
 * lever: block-local cast byte buffer keeps the zeroing pointer on the zero path.
 */
void FLDMMDL_MOVE_AttrSetDrawOffset(Mmdl *mmdl, EventInfo *info)
{
    VecFx32 offset;
    if (FLDMMDL_CheckStatusBitAttrOffsetOff(mmdl) == 0 && MAP_ATTR_IsSand(info->oldAttrValue) != 0) {
        offset = d_021714D0;
        FLDMMDL_SetAttrOffset((struct Mmdl *)mmdl, (struct VecFx32 *)(&offset));
        return;
    }
    {
        unsigned char zeroBuf[12];
        VecFx32 *zero = (VecFx32 *)zeroBuf;
        vzero(zero);
        FLDMMDL_SetAttrOffset((struct Mmdl *)mmdl, (struct VecFx32 *)zero);
    }
}

int FLDMMDL_MOVE_GetFootMarkKind(u16 attrValue, u8 effectMode)
{
    int kind = 0;

    if (MAP_ATTR_IsGrassSingleC(attrValue) != 0) {
        kind = 6;
    } else if (MAP_ATTR_IsGrassDoubleC(attrValue) != 0) {
        kind = 7;
    } else if (MAP_ATTR_IsGrassDoubleB(attrValue) != 0) {
        kind = 1;
        if (effectMode == 3)
            kind = 5;
    } else if (MAP_ATTR_IsGrassSingleB(attrValue) != 0) {
        if (effectMode == 3)
            kind = 4;
    } else if (MAP_ATTR_IsGrassDouble(attrValue) != 0) {
        kind = 1;
    } else if (MAP_ATTR_IsTallGrassSingle(attrValue) != 0) {
        kind = 2;
    } else if (MAP_ATTR_IsTallGrassDouble(attrValue) != 0) {
        kind = 3;
    }
    return kind;
}

void FLDMMDL_MOVE_AttrEffectFootMark(Mmdl *mmdl, EventInfo *info)
{
    int kind;

    if (info->oldAttrFlag & 0x20) {
        kind = FLDMMDL_MOVE_GetFootMarkKind(info->oldAttrValue, info->effectMode);
        FLDEFF_GRASS_Start((struct FieldEffectSys *)info->effectCtrl, (struct Mmdl *)mmdl, 0, kind);
    }
}

/*
 * trailing: two-byte zero alignment at 0x0216352A before FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag.
 */
void FLDMMDL_MOVE_AttrEffectFootMarkIfFlag(Mmdl *mmdl, EventInfo *info)
{
    int stepFlag;
    int kind;
    if (info->oldAttrFlag & 0x20) {
        stepFlag = FLDMMDL_GetDirMove(mmdl);
        kind = FLDMMDL_MOVE_GetFootMarkKind(info->oldAttrValue, info->effectMode);
        if (stepFlag != 0)
            FLDEFF_GRASS_Start((struct FieldEffectSys *)info->effectCtrl, (struct Mmdl *)mmdl, 1, kind);
    }
}

/*
 * trailing: two-byte zero alignment at 0x0216355A before FLDMMDL_MOVE_AttrEffectFootMarkJump.
 */
void FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag(Mmdl *mmdl, EventInfo *info)
{
    int stepFlag;
    int kind;
    if (info->oldAttrFlag & 0x20) {
        stepFlag = FLDMMDL_GetDirMove(mmdl);
        kind = FLDMMDL_MOVE_GetFootMarkKind(info->oldAttrValue, info->effectMode);
        if (stepFlag == 0)
            FLDEFF_GRASS_Start((struct FieldEffectSys *)info->effectCtrl, (struct Mmdl *)mmdl, 1, kind);
    }
}

void FLDMMDL_MOVE_AttrEffectFootMarkJump(Mmdl *mmdl, EventInfo *info)
{
    int kind;

    if (info->oldAttrFlag & 0x20) {
        kind = FLDMMDL_MOVE_GetFootMarkKind(info->oldAttrValue, info->effectMode);
        FLDEFF_GRASS_Start((struct FieldEffectSys *)info->effectCtrl, (struct Mmdl *)mmdl, 1, kind);
    }
}

void FLDMMDL_MOVE_AttrEffectGround(Mmdl *mmdl, EventInfo *info)
{
    int kind;

    if (info->nowAttrFlag & 8) {
        kind = 5;
        if (MAP_ATTR_IsPuddle(info->nowAttrValue) != 0) {
            if (info->effectMode == 3) {
                kind = 2;
                if (info->objCodeParam->footMarkType == 2)
                    kind = 3;
            }
        } else if (MAP_ATTR_IsMud(info->nowAttrValue) != 0) {
            if (info->effectMode == 0 || info->effectMode == 3) {
                kind = 2;
                if (info->objCodeParam->footMarkType == 2)
                    kind = 3;
            }
        } else if (MAP_ATTR_IsSnowTile(info->nowAttrValue) == 1 || MAP_ATTR_IsDeepSnow(info->nowAttrValue) == 1) {
            kind = 2;
            if (info->objCodeParam->footMarkType == 2)
                kind = 3;
        } else if (MAP_ATTR_IsSand(info->nowAttrValue) == 1) {
            kind = 4;
        } else {
            kind = 0;
            if (info->objCodeParam->footMarkType == 2)
                kind = 1;
        }
        if (kind != 5)
            FLDEFF_FOOTMARK_SetMMdl(mmdl, info->effectCtrl, kind);
    }
}

void FLDMMDL_MOVE_AttrEffectReflect(Mmdl *mmdl, EventInfo *info)
{
    int ret;

    if (MAP_ATTR_IsSplashWater(info->oldAttrValue) == 1) {
        ret = FLDMMDL_CheckMoveBitSplash(mmdl);
        if (ret != 0)
            return;
        FLDEFF_SPLASH_AddModel(info->effectCtrl, mmdl);
        FLDMMDL_SetMoveBitSplash(mmdl, 1);
        return;
    }
    FLDMMDL_SetMoveBitSplash(mmdl, 0);
}

void FLDMMDL_MOVE_AttrEffectReflectOrBridge(Mmdl *mmdl, EventInfo *info)
{
    int ret;

    if (MAP_ATTR_IsSplashWater(info->oldAttrValue) == 1) {
        ret = FLDMMDL_CheckMoveBitSplash(mmdl);
        if (ret != 0)
            return;
        FLDEFF_SPLASH_AddModel(info->effectCtrl, mmdl);
        FLDMMDL_SetMoveBitSplash(mmdl, 1);
        return;
    }
    if (MAP_ATTR_IsSplashWaterB(info->oldAttrValue) == 1) {
        FLDEFF_SPLASH_AddBoard(info->effectCtrl, mmdl);
        return;
    }
    FLDMMDL_SetMoveBitSplash(mmdl, 0);
}

void FLDMMDL_MOVE_AttrEffectReflectOff(Mmdl *mmdl, EventInfo *info)
{
    FLDMMDL_SetMoveBitSplash(mmdl, 0);
}

int FLDMMDL_MOVE_CanShowShadow(Mmdl *mmdl, EventInfo *info)
{
    if (FLDMMDL_SysIsDrawEnable(FLDMMDL_GetMmdlSys(mmdl)) == 0 || info->objCodeParam->shadowSize == 0)
        return 0;
    return 1;
}

int FLDMMDL_MOVE_IsShadowAttr(EventInfo *info)
{
    if ((info->oldAttrFlag & 0x80) == 0)
        return 0;
    if (info->effectMode == 3 && MAP_ATTR_IsPuddle(info->oldAttrValue) != 0)
        return 0;
    return 1;
}

void FLDMMDL_MOVE_AttrEffectShadowStart(Mmdl *mmdl, EventInfo *info)
{
    if (FLDMMDL_MOVE_CanShowShadow(mmdl, info) == 1 && FLDMMDL_MOVE_IsShadowAttr(info) == 1) {
        if (FLDMMDL_CheckMoveBit(mmdl, 0x4000) == 0) {
            FLDEFF_SHADOW_Start(mmdl, (struct FieldEffectSys *)info->effectCtrl);
            FLDMMDL_SetMoveBit(mmdl, 0x4000);
        }
    }
}

void FLDMMDL_MOVE_AttrEffectShadowUpdate(Mmdl *mmdl, EventInfo *info)
{
    if (FLDMMDL_MOVE_CanShowShadow(mmdl, info) == 1) {
        if (FLDMMDL_MOVE_IsShadowAttr(info) == 0) {
            FLDMMDL_SetMoveBit(mmdl, 0x8000);
            return;
        }
        FLDMMDL_ClearMoveBit(mmdl, 0x8000);
    }
}

void FLDMMDL_MOVE_AttrEffectDust(Mmdl *mmdl, EventInfo *info)
{
    if (!(info->oldAttrFlag & 2) && !FLDMMDL_CheckMoveBitShadowVanish(mmdl))
        FLDEFF_KEMURI_Start((struct Mmdl *)mmdl, (struct FieldEffectSys *)info->effectCtrl);
}

void FLDMMDL_MOVE_AttrEffectSplashOldPos(Mmdl *mmdl, EventInfo *info)
{
    int gridX, gridZ, height;

    if (MAP_ATTR_IsRippleWater(info->nowAttrValue) == 1) {
        gridX = FLDMMDL_GetGridOldX(mmdl);
        gridZ = FLDMMDL_GetGridOldZ(mmdl);
        height = FLDMMDL_GetPosY(mmdl);
        FLDEFF_RIPPLE_Start((struct FieldEffectSys *)info->effectCtrl, gridX, gridZ, height);
    }
}

void FLDMMDL_MOVE_AttrEffectSplashNowPos(Mmdl *mmdl, EventInfo *info)
{
    int gridX, gridZ, height;

    if (MAP_ATTR_IsRippleWater(info->oldAttrValue) == 1) {
        gridX = FLDMMDL_GetGridNowX(mmdl);
        gridZ = FLDMMDL_GetGridNowZ(mmdl);
        height = FLDMMDL_GetPosY(mmdl);
        FLDEFF_RIPPLE_Start((struct FieldEffectSys *)info->effectCtrl, gridX, gridZ, height);
    }
}

void FLDMMDL_MOVE_AttrEffectLongGrassStart(Mmdl *mmdl, EventInfo *info)
{
    int reflectAttr, attrOrKind;
    struct MmdlSys *mmdlSys;

    if (info->objCodeParam->reflectType == 0) {
        return;
    }
    if (FLDMMDL_CheckMoveBitReflect(mmdl) != 0) {
        return;
    }
    reflectAttr = -1;
    if (info->oldAttrFlag & 0x40) {
        reflectAttr = info->oldAttr;
    } else {
        attrOrKind = FLDMMDL_MOVE_GetDirMapAttr(mmdl, 1);
        if (MAP_ATTR_GetFlags(attrOrKind) & 0x40) {
            reflectAttr = attrOrKind;
        }
    }
    if (reflectAttr == -1) {
        return;
    }
    attrOrKind = 1;
    reflectAttr = MAP_ATTR_GetTerrainId(reflectAttr);
    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    if (MAP_ATTR_IsMirrorFloor(reflectAttr) == 1 || MAP_ATTR_IsIce(reflectAttr) == 1) {
        attrOrKind = 2;
    }
    FLDEFF_REFLECT_SetMMdl(mmdlSys, mmdl, info->effectCtrl, attrOrKind);
    FLDMMDL_SetMoveBitReflect(mmdl, 1);
}

void FLDMMDL_MOVE_AttrEffectLongGrassEnd(Mmdl *mmdl, EventInfo *info)
{
    if (info->objCodeParam->reflectType != 0 && FLDMMDL_CheckMoveBitReflect(mmdl) != 0) {
        int neighborAttr = FLDMMDL_MOVE_GetDirMapAttr(mmdl, 1);

        if (neighborAttr == -1) {
            FLDMMDL_SetMoveBitReflect(mmdl, 0);
            return;
        }
        if ((MAP_ATTR_GetFlags(neighborAttr) & 0x40) == 0) {
            FLDMMDL_SetMoveBitReflect(mmdl, 0);
        }
    }
}

/*
 * unblocked: FLDEFF_D06DENKI_StartSpark is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 28 bytes against 26 compiled: the unlabelled follower that
 *   precedes ov021's next entry (its bytes are the original's 2-byte pad).
 */
void FLDMMDL_MOVE_AttrEffectSpecial(Mmdl *mmdl, EventInfo *info)
{
    if (MAP_ATTR_IsElectricFloor(info->oldAttrValue) == 1)
        FLDEFF_D06DENKI_StartSpark(mmdl, (struct FieldEffectSys *)info->effectCtrl);
}

void FLDMMDL_MOVE_AttrEffectNone(Mmdl *mmdl, EventInfo *info)
{
}

/*
 * Collects five placement-test failures into a bit mask: 1 from
 * FLDMMDL_MOVE_HitCheckMoveLimit, 2 from FLDMMDL_MOVE_HitCheckAttr (the cell-centre position by
 * value), 8 when the ground-height probe FLDMMDL_MOVE_GetMapHeight fails or lands
 * 0x14000 or more from the object's height, 4 from FLDMMDL_MOVE_HitCheckOtherObjects, 0x10
 * from the ov021 test at 0x0218DC04.
 *
 * x and y are s16 register parameters (their spill homes are stored at
 * entry); z is read as `*(s16 *)&z` from an int stack parameter: an s16
 * z is copied into a fresh spill slot, while this spelling keeps the
 * incoming slot as its home and reloads it with ldrsh after the calls.
 */
u32 FLDMMDL_MOVE_HitCheckMove(Mmdl *mmdl, VecFx32 *currentPos, s16 gridX, s16 height, int gridZ, u16 kind)
{
    u32 failMask = 0;
    VecFx32 cellPos;
    fx32 groundHeight;

    cellPos.x = (gridX << 16) + 0x8000;
    cellPos.y = currentPos->y;
    cellPos.z = (*(s16 *)&gridZ << 16) + 0x8000;
    if (FLDMMDL_MOVE_HitCheckMoveLimit(mmdl, gridX, *(s16 *)&gridZ) == 1)
        failMask |= 1;
    if (FLDMMDL_MOVE_HitCheckAttr(mmdl, kind, cellPos) == 1)
        failMask |= 2;
    if (FLDMMDL_MOVE_GetMapHeight(mmdl, &cellPos, &groundHeight) == 1) {
        fx32 heightDiff = currentPos->y - groundHeight;
        if (heightDiff < 0)
            heightDiff = -heightDiff;
        if (heightDiff >= 0x14000)
            failMask |= 8;
        height = (groundHeight >> 4) / 0x1000;
    } else {
        failMask |= 8;
    }
    if (FLDMMDL_MOVE_HitCheckOtherObjects(mmdl, gridX, height, *(s16 *)&gridZ) == 1)
        failMask |= 4;
    if (FIELD_G3D_MAPPER_IsOutsideGrid(FLDMMDL_SysGetG3dMapper(FLDMMDL_GetMmdlSys(mmdl)), &cellPos) == 1)
        failMask |= 0x10;
    return failMask;
}

/*
 * trailing: two-byte zero alignment at 0x021639BE before FLDMMDL_MOVE_HitCheckMoveDir.
 */
u32 FLDMMDL_MOVE_HitCheckMoveCurrent(Mmdl *mmdl, s16 gridX, s16 height, int gridZ, u16 kind)
{
    VecFx32 currentPos;
    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&currentPos));
    return FLDMMDL_MOVE_HitCheckMove(mmdl, &currentPos, gridX, height, gridZ, kind);
}

u32 FLDMMDL_MOVE_HitCheckMoveDir(Mmdl *mmdl, u16 dir)
{
    s16 gridX, height, gridZ;

    gridX = FLDMMDL_GetGridNowX(mmdl) + FLDMMDL_MOVE_GetDirAddGridX(dir);
    height = FLDMMDL_GetGridNowY(mmdl);
    gridZ = FLDMMDL_GetGridNowZ(mmdl) + FLDMMDL_MOVE_GetDirAddGridZ(dir);
    return FLDMMDL_MOVE_HitCheckMoveCurrent(mmdl, gridX, height, gridZ, dir);
}

/*
 * Builds a rectangle (s16 x0, y0, x1, y1) from a map object's width and
 * height getters: x spans x .. x + (w - 1), y spans y - (h - 1) .. y, each
 * size clamped at 0. EXACT* only for the 2-byte pad after the function
 * (54 of 56).
 *
 * Key: out->x0 = x is written before
 * out->x1 = x + w. Then x is dead at the add and does not interfere with
 * the sum temp, so x and y simplify in one pass and take r6 / r5 in
 * parameter order. With x1 stored first, x and y swapped registers (6 B).
 */
void FLDMMDL_MOVE_GetGridRect(Mmdl *mmdl, int gridX, int gridZ, Rect *out)
{
    s16 width;
    s16 height;
    width = FLDMMDL_GetSizeWidth(mmdl) - 1;
    if (width < 0) width = 0;
    out->x0 = gridX;
    out->x1 = gridX + width;
    height = FLDMMDL_GetSizeDepth(mmdl) - 1;
    if (height < 0) height = 0;
    out->y0 = gridZ - height;
    out->y1 = gridZ;
}

/*
 * Tests whether two rectangles (s16 x0, y0, x1, y1) overlap: per axis the
 * longer interval comes first, then either end of the shorter one must lie
 * inside it. Leaf, no calls. EXACT* only for the 2-byte pad after the
 * function (174 of 176).
 *
 * Key: each axis is a block with its own locals, and the second block
 * declares them in a different order (big0, big1, sm0, sm1, lo1, hi1, lo2,
 * hi2, d1, d2). Declaration order sets the colouring order of the second
 * axis (d1 after lo2); the first block keeps d1, d2, lo1, ... order.
 * Earlier 15 B residue (shared locals) was only the d1/lo2 register swap.
 */
int FLDMMDL_MOVE_IsRectOverlap(Rect *rectA, Rect *rectB)
{
    {
        s16 lenA, lenB, loA, hiA, loB, hiB, longLo, longHi, shortLo, shortHi;
        loA = rectA->x0; hiA = rectA->x1; lenA = hiA - loA; if (lenA < 0) { lenA = -lenA; }
        loB = rectB->x0; hiB = rectB->x1; lenB = hiB - loB; if (lenB < 0) { lenB = -lenB; }
        if (lenA > lenB) { longLo = loA; longHi = hiA; shortLo = loB; shortHi = hiB; }
        else { longLo = loB; longHi = hiB; shortLo = loA; shortHi = hiA; }
        if (!((longLo <= shortLo && longHi >= shortLo) || (longLo <= shortHi && longHi >= shortHi))) goto fail;
    }
    {
        s16 longLo, longHi, shortLo, shortHi, loA, hiA, loB, hiB, lenA, lenB;
        loA = rectA->y0; hiA = rectA->y1; lenA = hiA - loA; if (lenA < 0) { lenA = -lenA; }
        loB = rectB->y0; hiB = rectB->y1; lenB = hiB - loB; if (lenB < 0) { lenB = -lenB; }
        if (lenA > lenB) { longLo = loA; longHi = hiA; shortLo = loB; shortHi = hiB; }
        else { longLo = loB; longHi = hiB; shortLo = loA; shortHi = hiA; }
        if (!((longLo <= shortLo && longHi >= shortLo) || (longLo <= shortHi && longHi >= shortHi))) goto fail;
    }
    return 1;
fail:
    return 0;
}

int FLDMMDL_MOVE_HitCheckObjectRect(Mmdl *mmdl, Mmdl *other, int gridX, int height, s16 gridZ, int checkNext)
{
    Rect rect;
    Rect otherRect;
    s16 heightDiff;

    FLDMMDL_MOVE_GetGridRect(mmdl, gridX, gridZ, &rect);
    if (FLDMMDL_CheckStatusBit(other, 0x80) == 0) {
        FLDMMDL_MOVE_GetGridRect(other, FLDMMDL_GetGridNowX(other), FLDMMDL_GetGridNowZ(other), &otherRect);
        if (FLDMMDL_MOVE_IsRectOverlap(&rect, &otherRect) != 0) {
            heightDiff = height - FLDMMDL_GetGridNowY(other);
            if (heightDiff < 0) {
                heightDiff = -heightDiff;
            }
            if (heightDiff < 1) {
                return 1;
            }
        }
        if (checkNext == 1) {
            FLDMMDL_MOVE_GetGridRect(other, FLDMMDL_GetGridOldX(other), FLDMMDL_GetGridOldZ(other), &otherRect);
            if (FLDMMDL_MOVE_IsRectOverlap(&rect, &otherRect) != 0) {
                heightDiff = height - FLDMMDL_GetGridOldY(other);
                if (heightDiff < 0) {
                    heightDiff = -heightDiff;
                }
                if (heightDiff < 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int FLDMMDL_MOVE_HitCheckOtherObjects(Mmdl *mmdl, int gridX, int height, s16 gridZ)
{
    u32 iter;
    Mmdl *other;
    MmdlSys *mmdlSys;

    iter = 0;
    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &other, &iter) == 1) {
        if (mmdl != other) {
            if (FLDMMDL_MOVE_HitCheckObjectRect(mmdl, other, gridX, height, gridZ, 1) == 1)
                return 1;
        }
    }
    return 0;
}

int FLDMMDL_MOVE_IsGridInObjectRect(Mmdl *mmdl, int gridX, int gridZ, int checkNext)
{
    Rect rect;
    int cellX;

    cellX = FLDMMDL_GetGridNowX(mmdl);
    FLDMMDL_MOVE_GetGridRect(mmdl, cellX, FLDMMDL_GetGridNowZ(mmdl), &rect);
    if (rect.x0 <= gridX && rect.x1 >= gridX && rect.y0 <= gridZ && rect.y1 >= gridZ)
        return 1;
    if (checkNext == 1) {
        cellX = FLDMMDL_GetGridOldX(mmdl);
        FLDMMDL_MOVE_GetGridRect(mmdl, cellX, FLDMMDL_GetGridOldZ(mmdl), &rect);
        if (rect.x0 <= gridX && rect.x1 >= gridX && rect.y0 <= gridZ && rect.y1 >= gridZ)
            return 1;
    }
    return 0;
}

int FLDMMDL_MOVE_HitCheckMoveLimit(Mmdl *mmdl, int gridX, int gridZ)
{
    int center;
    int range;
    int maxPos;
    int minPos;

    center = FLDMMDL_GetGridInitX(mmdl);
    range = FLDMMDL_GetMoveLimitX(mmdl);
    if (range != -1) {
        maxPos = (s16)(center + range);
        minPos = (s16)(center - range);
        if (minPos > gridX || maxPos < gridX)
            return 1;
    }
    center = FLDMMDL_GetGridInitZ(mmdl);
    range = FLDMMDL_GetMoveLimitZ(mmdl);
    if (range != -1) {
        maxPos = (s16)(center + range);
        minPos = (s16)(center - range);
        if (minPos > gridZ || maxPos < gridZ)
            return 1;
    }
    return 0;
}

/*
 *   Closed by writing the inner loop init as "for (j = 0, cur = row; ...)" (copy inside the for-init,
 *   after j = 0).
 */
int FLDMMDL_MOVE_HitCheckAttr(Mmdl *mmdl, u32 kind, VecFx32 topLeft)
{
    int hasFirst;
    VecFx32 rowPos;
    VecFx32 cellPos;
    u32 cellAttr;
    u32 firstAttr;
    u8 i;
    u32 height;
    u8 j;
    u32 width;
    u16 nowAttrValue;

    if (FLDMMDL_CheckStatusBitAttrGetOff(mmdl) == 0) {
        hasFirst = 0;
        width = FLDMMDL_GetSizeWidth(mmdl);
        height = FLDMMDL_GetSizeDepth(mmdl);
        rowPos = topLeft;
        for (i = 0; i < height; i++, rowPos.z -= 0x10000) {
            for (j = 0, cellPos = rowPos; j < width; j++, cellPos.x += 0x10000) {
                if (FLDMMDL_MOVE_GetMapAttr(mmdl, &cellPos, &cellAttr) == 0)
                    return 1;
                if (MAP_ATTR_IsBlocked(cellAttr) == 1)
                    return 1;
                if (hasFirst == 0) {
                    firstAttr = cellAttr;
                    hasFirst = 1;
                }
            }
        }
        nowAttrValue = MAP_ATTR_GetTerrainId(FLDMMDL_GetNowAttr(mmdl));
        if (d_021714A0[kind](nowAttrValue) == 1)
            return 1;
        if (d_02171490[kind](MAP_ATTR_GetTerrainId(firstAttr)) == 1)
            return 1;
        return 0;
    }
    return 1;
}

int FLDMMDL_MOVE_GetFieldG3dMapHit(Mmdl *mmdl, VecFx32 *pos, FieldG3dMapHit *info) { return FIELD_G3D_MAPPER_QueryNearestHit(FLDMMDL_SysGetG3dMapper(FLDMMDL_GetMmdlSys(mmdl)),pos,info); }

int FLDMMDL_MOVE_GetMapAttr(Mmdl *mmdl, VecFx32 *pos, u32 *outAttr)
{
    FieldG3dMapHit info;

    *outAttr = 0;
    if (FLDMMDL_MOVE_GetFieldG3dMapHit(mmdl, pos, &info) == 1) {
        *outAttr = info.attr;
        return 1;
    }
    return 0;
}

int FLDMMDL_MOVE_GetMapHeight(Mmdl *mmdl, VecFx32 *pos, int *outHeight)
{
    FieldG3dMapHit info;

    *outHeight = 0;
    if (FLDMMDL_MOVE_GetFieldG3dMapHit(mmdl, pos, &info) == 1) {
        *outHeight = info.height;
        return 1;
    }
    return 0;
}

void FLDMMDL_MOVE_UpdateGridPosDir(Mmdl *mmdl, int dir)
{
    int groundHeight;
    VecFx32 cellPos;

    FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
    FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
    FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
    FLDMMDL_AddGridNowX(mmdl, FLDMMDL_MOVE_GetDirAddGridX(dir));
    FLDMMDL_AddGridNowZ(mmdl, FLDMMDL_MOVE_GetDirAddGridZ(dir));
    groundHeight = 0;
    FLDMMDL_MOVE_GridToVectorPos(FLDMMDL_GetGridNowX(mmdl), FLDMMDL_GetGridNowZ(mmdl), &cellPos);
    cellPos.y = FLDMMDL_GetPosY(mmdl);
    FLDMMDL_MOVE_GetMapHeight(mmdl, &cellPos, &groundHeight);
    FLDMMDL_SetGridNowY(mmdl, (s16)((groundHeight >> 4) / 4096));
}

void FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl)
{
    FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
    FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
    FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
}

int FLDMMDL_MOVE_GetDirMapAttr(Mmdl *mmdl, int dir)
{
    VecFx32 cellPos;
    int attr;

    attr = -1;
    FLDMMDL_MOVE_GridToVectorPos(FLDMMDL_GetGridNowX(mmdl), FLDMMDL_GetGridNowZ(mmdl), &cellPos);
    cellPos.y = FLDMMDL_GetPosY(mmdl);
    FLDMMDL_MOVE_AddDirVector(dir, &cellPos, 0x10000);
    FLDMMDL_MOVE_GetMapAttr(mmdl, &cellPos, (u32 *)&attr);
    return attr;
}

/*
 * contract: matched FLDMMDL_GetPos copies all three Actor.pos words to v;
 * no uninitialized local component is read. Additions wrap as unsigned32.
 */
void FLDMMDL_MOVE_AddVectorPos(Mmdl *mmdl, const VecFx32 *delta) { VecFx32 pos; FLDMMDL_GetPos(mmdl,(struct VecFx32 *)(&pos)); pos.x=(int)((unsigned)pos.x+(unsigned)delta->x); pos.y=(int)((unsigned)pos.y+(unsigned)delta->y); pos.z=(int)((unsigned)pos.z+(unsigned)delta->z); FLDMMDL_SetPos(mmdl,(struct VecFx32 *)(&pos)); }

void FLDMMDL_MOVE_AddDirVectorPos(Mmdl *mmdl, int dir, int amount)
{
    VecFx32 pos;

    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&pos));
    switch (dir) {
    case 0:
        pos.z -= amount;
        break;
    case 1:
        pos.z += amount;
        break;
    case 2:
        pos.x -= amount;
        break;
    case 3:
        pos.x += amount;
        break;
    }
    FLDMMDL_SetPos(mmdl, (struct VecFx32 *)(&pos));
}

int FLDMMDL_MOVE_UpdateHeight(Mmdl *mmdl)
{
    VecFx32 curPos;
    VecFx32 probePos;
    int groundHeight;
    int found;

    FLDMMDL_GetPos(mmdl, (struct VecFx32 *)(&curPos));
    probePos = curPos;
    if (FLDMMDL_CheckStatusBit(mmdl, 0x2000) != 0)
        return 0;
    if (FLDMMDL_CheckStatusBitHeightGetOff(mmdl) == 1) {
        FLDMMDL_ClearMoveBit(mmdl, 0x1000);
        return 0;
    }
    found = FLDMMDL_MOVE_GetMapHeight(mmdl, &probePos, &groundHeight);
    if (found == 1) {
        curPos.y = groundHeight;
        FLDMMDL_SetPos(mmdl, (struct VecFx32 *)(&curPos));
        FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
        FLDMMDL_SetGridNowY(mmdl, (s16)((groundHeight >> 4) / 4096));
        FLDMMDL_ClearMoveBit(mmdl, 0x1000);
    } else {
        FLDMMDL_SetMoveBit(mmdl, 0x1000);
    }
    return found;
}

int FLDMMDL_MOVE_UpdateMapAttr(Mmdl *mmdl)
{
    VecFx32 cellPos;
    int nowAttr;
    int oldAttr;
    int hasNowAttr;
    int hasOldAttr;

    hasNowAttr = 0;
    hasOldAttr = 0;
    nowAttr = -1;
    oldAttr = -1;
    if (FLDMMDL_CheckStatusBitAttrGetOff(mmdl) == 0) {
        int gridX = FLDMMDL_GetGridOldX(mmdl);
        int gridY = FLDMMDL_GetGridOldY(mmdl);
        int gridZ = FLDMMDL_GetGridOldZ(mmdl);
        cellPos.x = gridX << 16;
        cellPos.y = gridY << 16;
        cellPos.z = gridZ << 16;
        hasNowAttr = FLDMMDL_MOVE_GetMapAttr(mmdl, &cellPos, (u32 *)&nowAttr);
        FLDMMDL_MOVE_GridToVectorPos((s16)FLDMMDL_GetGridNowX(mmdl), (s16)FLDMMDL_GetGridNowZ(mmdl), &cellPos);
        cellPos.y = FLDMMDL_GetPosY(mmdl);
        hasOldAttr = FLDMMDL_MOVE_GetMapAttr(mmdl, &cellPos, (u32 *)&oldAttr);
    }
    if (hasNowAttr == 1)
        FLDMMDL_SetOldAttr(mmdl, nowAttr);
    if (hasOldAttr == 1)
        FLDMMDL_SetNowAttr(mmdl, oldAttr);
    if (hasOldAttr == 1) {
        FLDMMDL_ClearMoveBit(mmdl, 0x800);
        return 1;
    }
    FLDMMDL_SetMoveBit(mmdl, 0x800);
    return 0;
}

int FLDMMDL_MOVE_IsNearPlayer(Mmdl *mmdl)
{
    Mmdl *player;
    int playerX;
    int playerZ;
    int gridX;
    int gridZ;
    s16 minX;
    s16 minZ;
    s16 maxX;
    s16 maxZ;

    player = FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys(mmdl));
    if (player != 0) {
        playerX = FLDMMDL_GetGridNowX(player);
        playerZ = FLDMMDL_GetGridNowZ(player);
        gridX = FLDMMDL_GetGridNowX(mmdl);
        gridZ = FLDMMDL_GetGridNowZ(mmdl);
        minX = gridX - 18;
        minZ = gridZ - 18;
        maxX = gridX + 17;
        maxZ = gridZ + 17;
        if (minZ <= playerZ && maxZ >= playerZ && minX <= playerX && maxX >= playerX)
            return 1;
    }
    return 0;
}

/*
 * lever: halfword-wrapped +0xFFCD preserves the literal-pool bias;
 * spelling -51 produced a 26-byte DIFF instead of the 32-byte body.
 */
void FLDMMDL_MOVE_StopAcmdWalkCodes(Mmdl *mmdl) { if ((u16)(FLDMMDL_GetMoveCode(mmdl)+0xFFCD) <= 3) FLDMMDL_CallMoveProc(mmdl); }

/*
 * contract: ROM table at 0x02171480 holds {0,0,-1,1}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
s16 FLDMMDL_MOVE_GetDirAddGridX(int dir) { return (short)*(const int *)((u8 *)d_02171480+((unsigned)dir<<2)); }

/*
 * contract: ROM table at 0x02171470 holds {-1,1,0,0}. No caller
 * bounds assumption: unsigned32 address arithmetic preserves the image load.
 */
s16 FLDMMDL_MOVE_GetDirAddGridZ(int dir) { return (short)*(const int *)((u8 *)d_02171470+((unsigned)dir<<2)); }

void FLDMMDL_MOVE_AddDirVector(int dir, VecFx32 *pos, int amount)
{
    switch (dir) {
    case 0:
        pos->z -= amount;
        break;
    case 1:
        pos->z += amount;
        break;
    case 2:
        pos->x -= amount;
        break;
    case 3:
        pos->x += amount;
        break;
    }
}

/*
 * Unlabelled leaf (no lr save, prints as .word data): step one of two
 * halfword coordinates by amt in the direction dir (0 z-, 1 z+, 2 x-, 3 x+).
 * Halfword sibling of the word version FLDMMDL_MOVE_AddDirVector.  Filed as the sole
 * blocker of ov021 FIELD_PLAYER_CORE_FormStepSlot8Done.
 */
void FLDMMDL_MOVE_AddDirGrid(int dir, s16 *x, s16 *z, s16 amount)
{
    switch (dir) {
    case 0:
        z[0] -= amount;
        break;
    case 1:
        z[0] += amount;
        break;
    case 2:
        x[0] -= amount;
        break;
    case 3:
        x[0] += amount;
        break;
    }
}

void FLDMMDL_MOVE_GridToVectorPos(int gridX, int gridZ, VecFx32 *pos)
{
    pos->x = (gridX << 16) + 0x8000;
    pos->z = (gridZ << 16) + 0x8000;
}

/*
 * Unlabelled leaf, blocker of ov021 FIELD_EVENT_CHECK_SearchGridFrontMmdl: widens three integers to 16.16 fixed point.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void FLDMMDL_MOVE_GridToVector(int gridX, int gridY, int gridZ, VecFx32 *pos)
{
    pos->x = gridX << 16;
    pos->y = gridY << 16;
    pos->z = gridZ << 16;
}

/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov021 FLDMMDL_MOVECODE_SwingStepRotateDir and FLDMMDL_MOVECODE_BackForthStepFaceDir: returns
 * the low halfword of word i of a table.
 */
u16 FLDMMDL_MOVE_GetDirTableValue(int index)
{
    return d_021714B0[index];
}

/*
 * Unlabelled leaf (word run in the listing), blocker of FLDMMDL_MOVECODE_GetSightDirToPlayer and
 * FLDMMDL_MOVE_TurnToPlayer (ov021).  Direction code 0..3 from a point pair.
 */
u16 FLDMMDL_MOVE_GetDirFromPoints(int fromX, int fromZ, int toX, int toZ)
{
    int dir;

    if (fromX > toX) {
        return 2;
    }
    if (fromX < toX) {
        return 3;
    }
    dir = 1;
    if (fromZ > toZ) {
        dir = 0;
    }
    return dir;
}

/*
 * Unlabelled leaf, blocker of ov021 FLDMMDL_DRAW_GetDirIndex: three chained table lookups.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
u8 FLDMMDL_MOVE_GetRelativeDirCode(int tableIndex, int offset)
{
    u32 lookupIndex = (u16)(offset + d_02171458[tableIndex]);

    return d_021714C0[d_02171460[lookupIndex >> 12]].dirCode;
}

/*
 *
 * Tail call through a pool word and `bx r3`: a two-instruction
 * thunk into FLDMMDL_SetStatusBit, the shape of the arm9 copy.
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md)
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FLDMMDL_MOVE_SetStatusPauseDraw.c \
 *       --func FLDMMDL_MOVE_SetStatusPauseDraw --addr 0x021642F8 --region ov010 --cc dsi/1.1p1 --thumb
 */
void FLDMMDL_MOVE_SetStatusPauseDraw(Mmdl *mmdl)
{

    FLDMMDL_SetStatusBit(mmdl, 8192);
}

void FLDMMDL_MOVE_RequestRailMove(Mmdl *mmdl, MmdlHeader *header)
{
    RailLocation location;
    u16 *railPos;
    location.railIndex = header->pos[0];
    location.type = 1;
    railPos = header->pos;
    location.key = ZONEDATA_DirToRailKey((s16)header->dirHeader);
    location.lineGrid = railPos[1];
    location.widthGrid = ((s16 *)railPos)[2];
    if (FLDMMDL_SysCheckStatusBit(FLDMMDL_GetMmdlSys(mmdl), 0x10) != 0) {
        FLDMMDL_RAIL_SetLocation(mmdl, &location);
        return;
    }
    FLDMMDL_InitMoveProcWork(mmdl, 0xc);
    FLDMMDL_MOVE_SetRailMoveRequest(mmdl, (const u16 *)(&location));
}

void FLDMMDL_MOVE_SetRailMoveRequest(Mmdl *mmdl, const u16 *locationWords) { RailMoveRequest *request=FLDMMDL_GetMoveProcWork(mmdl); request->location[0]=locationWords[0]; request->location[1]=locationWords[1]; request->location[2]=locationWords[2]; request->location[3]=locationWords[3]; request->magic=0xEFEFEFEF; }

/*
 * contract: setter FLDMMDL_MOVE_SetRailMoveRequest writes the four payload halfwords
 * at +4,+6,+8,+10 before publishing 0xEFEFEFEF at +0;
 * this reader loads those halfwords only after the sentinel comparison.
 */
int FLDMMDL_MOVE_GetRailMoveRequest(Mmdl *mmdl, u16 *outWords) { RailMoveRequest *request=FLDMMDL_GetMoveProcWork(mmdl); if (request->magic==0xEFEFEFEF) { outWords[0]=request->location[0]; outWords[1]=request->location[1]; outWords[2]=request->location[2]; outWords[3]=request->location[3]; return 1; } return 0; }
