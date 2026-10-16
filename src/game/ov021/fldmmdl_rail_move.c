/*
 * file:     fldmmdl_rail_move.c
 * unit:     yes
 * function: FLDMMDL_RAIL_MOVE_InitMove, FLDMMDL_RAIL_MOVE_UpdateMove, FLDMMDL_RAIL_MOVE_GetLocationAttr, FLDMMDL_RAIL_MOVE_GetDirByAngle, FLDMMDL_RAIL_MOVE_CheckMoveStart, FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove, FLDMMDL_RAIL_MOVE_ProcMoveStartFirst, FLDMMDL_RAIL_MOVE_ProcMoveStartSecond, FLDMMDL_RAIL_MOVE_ProcMoveEnd, FLDMMDL_RAIL_MOVE_UpdateCurrentAttr, FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst, FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartSecond, FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond, FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd, FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump, FLDMMDL_RAIL_MOVE_MapAttrGrassProc0, FLDMMDL_RAIL_MOVE_MapAttrGrassProc12, FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1, FLDMMDL_RAIL_MOVE_MapAttrShadowProc0, FLDMMDL_RAIL_MOVE_MapAttrShadowProc12, FLDMMDL_RAIL_MOVE_MapAttrEndNopProc, FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2, FLDMMDL_RAIL_MOVE_MapAttrReflectProc01, FLDMMDL_RAIL_MOVE_MapAttrReflectProc2, FLDMMDL_RAIL_MOVE_GetFldEffCtrl, FLDMMDL_RAIL_MOVE_AcEnd, FLDMMDL_RAIL_MOVE_AcNextStep, FLDMMDL_RAIL_MOVE_AcDirSet, FLDMMDL_RAIL_MOVE_AcDirU0, FLDMMDL_RAIL_MOVE_AcDirD0, FLDMMDL_RAIL_MOVE_AcDirL0, FLDMMDL_RAIL_MOVE_AcDirR0, FLDMMDL_RAIL_MOVE_AcWalkSet, FLDMMDL_RAIL_MOVE_AcWalk1, FLDMMDL_RAIL_MOVE_AcWalkEnd, FLDMMDL_RAIL_MOVE_AcWalkU16F0, FLDMMDL_RAIL_MOVE_AcWalkD16F0, FLDMMDL_RAIL_MOVE_AcWalkL16F0, FLDMMDL_RAIL_MOVE_AcWalkR16F0, FLDMMDL_RAIL_MOVE_AcWalkU8F0, FLDMMDL_RAIL_MOVE_AcWalkD8F0, FLDMMDL_RAIL_MOVE_AcWalkL8F0, FLDMMDL_RAIL_MOVE_AcWalkR8F0, FLDMMDL_RAIL_MOVE_AcWalkU4F0, FLDMMDL_RAIL_MOVE_AcWalkD4F0, FLDMMDL_RAIL_MOVE_AcWalkL4F0, FLDMMDL_RAIL_MOVE_AcWalkR4F0, FLDMMDL_RAIL_MOVE_AcWalkU2F0, FLDMMDL_RAIL_MOVE_AcWalkD2F0, FLDMMDL_RAIL_MOVE_AcWalkL2F0, FLDMMDL_RAIL_MOVE_AcWalkR2F0, FLDMMDL_RAIL_MOVE_AcDashU4F0, FLDMMDL_RAIL_MOVE_AcDashD4F0, FLDMMDL_RAIL_MOVE_AcDashL4F0, FLDMMDL_RAIL_MOVE_AcDashR4F0, FLDMMDL_RAIL_MOVE_AcStayWalkSet, FLDMMDL_RAIL_MOVE_AcStayWalk1, FLDMMDL_RAIL_MOVE_AcStayWalkU32F0, FLDMMDL_RAIL_MOVE_AcStayWalkD32F0, FLDMMDL_RAIL_MOVE_AcStayWalkL32F0, FLDMMDL_RAIL_MOVE_AcStayWalkR32F0, FLDMMDL_RAIL_MOVE_AcStayWalkU16F0, FLDMMDL_RAIL_MOVE_AcStayWalkD16F0, FLDMMDL_RAIL_MOVE_AcStayWalkL16F0, FLDMMDL_RAIL_MOVE_AcStayWalkR16F0, FLDMMDL_RAIL_MOVE_AcStayWalkU8F0, FLDMMDL_RAIL_MOVE_AcStayWalkD8F0, FLDMMDL_RAIL_MOVE_AcStayWalkL8F0, FLDMMDL_RAIL_MOVE_AcStayWalkR8F0, FLDMMDL_RAIL_MOVE_AcStayWalkU2F0, FLDMMDL_RAIL_MOVE_AcStayWalkD2F0, FLDMMDL_RAIL_MOVE_AcStayWalkL2F0, FLDMMDL_RAIL_MOVE_AcStayWalkR2F0, FLDMMDL_RAIL_MOVE_AcStayWalkU4F0, FLDMMDL_RAIL_MOVE_AcStayWalkD4F0, FLDMMDL_RAIL_MOVE_AcStayWalkL4F0, FLDMMDL_RAIL_MOVE_AcStayWalkR4F0, FLDMMDL_RAIL_MOVE_AcJumpSetSe, FLDMMDL_RAIL_MOVE_AcJumpSet, FLDMMDL_RAIL_MOVE_AcJump1, FLDMMDL_RAIL_MOVE_AcJumpU8F0, FLDMMDL_RAIL_MOVE_AcJumpD8F0, FLDMMDL_RAIL_MOVE_AcJumpL8F0, FLDMMDL_RAIL_MOVE_AcJumpR8F0, FLDMMDL_RAIL_MOVE_AcJumpU16F0, FLDMMDL_RAIL_MOVE_AcJumpD16F0, FLDMMDL_RAIL_MOVE_AcJumpL16F0, FLDMMDL_RAIL_MOVE_AcJumpR16F0
 * address:  0x0219D6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_g3dobj.c at 0x0219D6B8 (no anchor; the field model rail move and rail anime command code, with its own const tables at 0x021D80E4..0x021D841B).
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_CallMoveInitProc  0x0216D6F4  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_CheckSysStatusBit  0x0216DA20  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_ACMD_RunCmds  0x02197EB4  thumb  ov021
 *   FLDMMDL_CheckMoveBitMovePause  0x0216DB10  thumb  ov010
 *   FLDMMDL_CallMoveProc  0x0216D708  thumb  ov010
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   VEC_Fx16Normalize  0x0207CDB8  arm
 *   FX_Atan2Idx  0x0207CFB8  arm
 *   d_021D80E4     0x021D80E4  data   ov021  a1
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_OnMoveBitMoveStart  0x0216DA70  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 *   FLDMMDL_SetOldAttr  0x0216D7E0  thumb  ov010
 *   FLDMMDL_SetNowAttr  0x0216D7D8  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_CheckDrawInitComp  0x0216DB24  thumb  ov010
 *   FLDMMDL_GetNowAttr  0x0216D7DC  thumb  ov010
 *   FLDMMDL_GetOldAttr  0x0216D7E4  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDEFF_GRASS_Start  0x021AC760  thumb  ov021
 *   FLDEFF_FOOTMARK_SetMMdl  0x021BBDD4  thumb  ov021
 *   FLDMMDL_SysIsDrawEnable  0x0216D98C  thumb  ov010
 *   FLDEFF_SHADOW_Start  0x021AC2C0  thumb  ov021
 *   FLDEFF_KEMURI_StartFacing  0x021AC578  thumb  ov021
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_MOVE_GetDirMapAttr  0x02163F40  thumb  ov010
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   FLDEFF_REFLECT_SetMMdl  0x021BBFB8  thumb  ov021
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FIELD_RAIL_WORK_IsMoving  0x021B8040  thumb  ov021
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   d_021DDD94     0x021DDD94  data
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   FLDMMDL_RAIL_GetNowLocation  0x0219E334  thumb  ov021
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_RAIL_UpdateRailWork  0x0219E354  thumb  ov021
 *   FLDMMDL_RAIL_SetMoveRequest  0x0219E370  thumb  ov021
 *   FLDMMDL_RAIL_SetGridPosByDir  0x0219E6C8  thumb  ov021
 *   FLDMMDL_RAIL_GetDrawOffsetByDir  0x0219E784  thumb  ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

/* A field model (opaque here; fldmmdl.c owns the layout). */
typedef struct Mmdl Mmdl;

/* The start of the object code parameter of a field model. */
typedef struct {
    u16 code;
    u8 drawType;
    u8 drawProcNo;
    u8 shadowSize;
    u8 footMarkType;   /* 2: cycle foot marks */
    u8 reflectType;    /* 0: no reflection */
} MmdlObjCodeParam;

/* A rail location (8 bytes; fldmmdl_rail.c fills it). */
typedef struct {
    u32 word[2];
} RailLocation;

/* Anime command work of the stay walk commands (walk in place). */
typedef struct {
    u16 drawStatus;
    s16 frameCount;
} RailAcmdStayWalkWork;

/* Anime command work of the rail jump commands (0x10). */
typedef struct {
    s32 speed;        /* rail move speed added to moveAcc each frame */
    s32 moveAcc;      /* 0x10000 = one grid moved */
    u16 heightStep;   /* added to heightPos each frame */
    u16 heightPos;    /* 0x100 per height table entry */
    s8 dir;
    s8 frameCount;
    s8 drawStatus;
    s8 heightTable;   /* index into _JumpHeightTables */
} RailAcmdJumpWork;

/* Field model move bits (the status word fldmmdl.c sets and tests). */
#define _MOVEBIT_MOVE_START     0x20
#define _MOVEBIT_MOVE_END       0x40
#define _MOVEBIT_JUMP_START     0x80
#define _MOVEBIT_JUMP_END       0x100
#define _MOVEBIT_ACMD           0x200
#define _MOVEBIT_ACMD_END       0x400
#define _MOVEBIT_ATTR_GET_ERROR 0x800
#define _MOVEBIT_SHADOW_SET     0x4000

/* Map attribute flags (MAP_ATTR_GetFlags). */
#define _ATTRFLAG_FOOTMARK 0x08
#define _ATTRFLAG_GRASS    0x20
#define _ATTRFLAG_REFLECT  0x40

#define _ATTR_NONE 0xFFFFFFFF

#define _DIR_UP    0
#define _DIR_DOWN  1
#define _DIR_LEFT  2
#define _DIR_RIGHT 3

#define _DRAW_STA_STOP     0
#define _DRAW_STA_WALK_32F 1
#define _DRAW_STA_WALK_16F 2
#define _DRAW_STA_WALK_8F  3
#define _DRAW_STA_WALK_4F  4
#define _DRAW_STA_WALK_2F  5
#define _DRAW_STA_DASH_4F  10

#define _SE_RAIL_JUMP 0x55E
#define _SE_RAIL_LAND 0x67B

extern void *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(Mmdl *mmdl);
extern u32 *FLDMMDL_SetStatusBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_CallMoveInitProc(Mmdl *mmdl);
extern int FLDMMDL_CheckSysStatusBit(Mmdl *mmdl, unsigned int bit);
extern u32 FLDMMDL_CheckMoveBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_ACMD_RunCmds(Mmdl *mmdl);
extern int FLDMMDL_CheckMoveBitMovePause(Mmdl *mmdl);
extern void FLDMMDL_CallMoveProc(Mmdl *mmdl);
extern void *FLDMMDL_SysGetNogridMapper(void *mmdlSys);
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(void *railMapper, RailLocation *location);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern void VEC_Fx16Normalize(s16 *src, s16 *dst);
extern int FX_Atan2Idx(int y, int x);
extern int FLDMMDL_CheckMoveBitMove(Mmdl *mmdl);
extern u16 FLDMMDL_GetMoveCode(Mmdl *mmdl);
extern void FLDMMDL_OnMoveBitMoveStart(Mmdl *mmdl);
extern char *FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 bit);
extern int FLDMMDL_CheckStatusBitAttrGetOff(Mmdl *mmdl);
extern void FLDMMDL_SetOldAttr(Mmdl *mmdl, u32 attr);
extern void FLDMMDL_SetNowAttr(Mmdl *mmdl, u32 attr);
extern void *FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bit);
extern int FLDMMDL_CheckDrawInitComp(Mmdl *mmdl);
extern u32 FLDMMDL_GetNowAttr(Mmdl *mmdl);
extern u32 FLDMMDL_GetOldAttr(Mmdl *mmdl);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern void FLDEFF_GRASS_Start(u32 fldEffCtrl, Mmdl *mmdl, u32 animate, int arg);
extern void FLDEFF_FOOTMARK_SetMMdl(Mmdl *mmdl, u32 fldEffCtrl, int cycle);
extern int FLDMMDL_SysIsDrawEnable(void *mmdlSys);
extern void FLDEFF_SHADOW_Start(Mmdl *mmdl, u32 fldEffCtrl);
extern u32 FLDEFF_KEMURI_StartFacing(Mmdl *mmdl, u32 fldEffCtrl);
extern int FLDMMDL_CheckMoveBitReflect(Mmdl *mmdl);
extern int FLDMMDL_MOVE_GetDirMapAttr(Mmdl *mmdl, int dir);
extern int FLDMMDL_SetMoveBitReflect(Mmdl *mmdl, int on);
extern void FLDEFF_REFLECT_SetMMdl(void *mmdlSys, Mmdl *mmdl, u32 fldEffCtrl, u32 arg);
extern void *FLDMMDL_SysGetFieldMap(void *mmdlSys);
extern u32 FIELDMAP_GetEffect(void *fieldmap);
extern void FLDMMDL_IncAcmdSeq(Mmdl *mmdl);
extern int FLDMMDL_MOVE_UpdateOldGridPos(Mmdl *mmdl);
extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 drawStatus);
extern void FLDMMDL_SetDirAll(Mmdl *mmdl, u16 dir);
extern void FIELD_RAIL_WORK_GetPos();
extern u8 FIELD_RAIL_WORK_IsMoving(void *railWork);
extern void FLDMMDL_SetPos();
extern void *FLDMMDL_InitMoveCmdWork(Mmdl *mmdl, int size, int arg);
extern void *FLDMMDL_GetMoveCmdWork(Mmdl *mmdl);
extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern void FLDMMDL_SetDrawOffset(Mmdl *mmdl, VecFx32 *offset);

int FLDMMDL_RAIL_MOVE_InitMove(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_UpdateMove(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_GetLocationAttr(Mmdl *mmdl, RailLocation *location);
u32 FLDMMDL_RAIL_MOVE_GetDirByAngle(Mmdl *mmdl, int angle);
int FLDMMDL_RAIL_MOVE_CheckMoveStart(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_ProcMoveStartSecond(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_ProcMoveEnd(Mmdl *mmdl);
u32 FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartSecond(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_MapAttrGrassProc0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrGrassProc12(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrShadowProc0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrEndNopProc(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
int FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
void FLDMMDL_RAIL_MOVE_MapAttrReflectProc2(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param);
u32 FLDMMDL_RAIL_MOVE_GetFldEffCtrl(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcEnd(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcNextStep(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcDirSet(Mmdl *mmdl, u32 dir);
int FLDMMDL_RAIL_MOVE_AcDirU0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDirD0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDirL0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDirR0(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcWalkSet(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus);
int FLDMMDL_RAIL_MOVE_AcWalk1(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkEnd(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkU2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkD2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkL2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcWalkR2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashU4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashD4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashL4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcDashR4F0(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcStayWalkSet(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus);
int FLDMMDL_RAIL_MOVE_AcStayWalk1(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR32F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR2F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkU4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkD4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkL4F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcStayWalkR4F0(Mmdl *mmdl);
void FLDMMDL_RAIL_MOVE_AcJumpSetSe(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 seNo);
void FLDMMDL_RAIL_MOVE_AcJumpSet(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep);
int FLDMMDL_RAIL_MOVE_AcJump1(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpU8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpD8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpL8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpR8F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpU16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpD16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpL16F0(Mmdl *mmdl);
int FLDMMDL_RAIL_MOVE_AcJumpR16F0(Mmdl *mmdl);

/* fldmmdl_rail.c */
void FLDMMDL_RAIL_GetNextLocation(Mmdl *mmdl, RailLocation *location);
int FLDMMDL_RAIL_GetNowLocation(Mmdl *mmdl, RailLocation *location);
void *FLDMMDL_RAIL_GetRailWork(Mmdl *mmdl);
void FLDMMDL_RAIL_UpdateRailWork(Mmdl *mmdl);
void FLDMMDL_RAIL_SetMoveRequest(Mmdl *mmdl, u32 dir, u32 frames);
void FLDMMDL_RAIL_SetGridPosByDir(Mmdl *mmdl, u16 dir);
void FLDMMDL_RAIL_GetDrawOffsetByDir(Mmdl *mmdl, u32 dir, s16 *vec);

/* Display direction for each 1/16 turn of the camera relative angle. */
extern u8 d_021D80E4[];
/* Jump height tables (16 entries each), indexed by RailAcmdJumpWork.heightTable. */
extern s32 *d_021DDD94[];

/* Move proc init of the rail move. */
int FLDMMDL_RAIL_MOVE_InitMove(Mmdl *mmdl)
{
    FLDMMDL_CallMoveInitProc(mmdl);
    return (int)FLDMMDL_SetStatusBit(mmdl, 2);
}

/* Per-frame update of a field model on a rail: anime command or move proc,
 * with the map attribute procs before and after. */
void FLDMMDL_RAIL_MOVE_UpdateMove(Mmdl *mmdl)
{
    if (FLDMMDL_CheckSysStatusBit(mmdl, 2) == 0) {
        FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(mmdl);
        FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(mmdl);
        if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_ACMD) != 0) {
            FLDMMDL_ACMD_RunCmds(mmdl);
        } else if (FLDMMDL_CheckMoveBitMovePause(mmdl) == 0 && FLDMMDL_RAIL_MOVE_CheckMoveStart(mmdl) == 1) {
            FLDMMDL_CallMoveProc(mmdl);
        }
        FLDMMDL_RAIL_MOVE_ProcMoveStartSecond(mmdl);
        FLDMMDL_RAIL_MOVE_ProcMoveEnd(mmdl);
    }
}

/* Map attribute at a rail location of the field model's rail mapper. */
int FLDMMDL_RAIL_MOVE_GetLocationAttr(Mmdl *mmdl, RailLocation *location)
{
    return FIELD_NOGRID_MAPPER_GetAttribute(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)), location);
}

/* Display direction of the field model's rail direction seen at `angle`. */
u32 FLDMMDL_RAIL_MOVE_GetDirByAngle(Mmdl *mmdl, int angle)
{
    s16 vec[4];
    int relAngle;
    FLDMMDL_RAIL_GetDrawOffsetByDir(mmdl, FLDMMDL_GetDirDisp(mmdl), vec);
    vec[1] = 0;
    VEC_Fx16Normalize(vec, vec);
    relAngle = FX_Atan2Idx(vec[0], vec[2]) - angle;
    if (relAngle < 0) {
        relAngle += 0x10000;
    }
    return d_021D80E4[relAngle >> 12];
}

int FLDMMDL_RAIL_MOVE_CheckMoveStart(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBitMove(mmdl) == 1) {
        return 1;
    }
    if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_ATTR_GET_ERROR) == 0) {
        return 1;
    }
    FLDMMDL_GetMoveCode(mmdl);
    return 1;
}

void FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_ATTR_GET_ERROR) != 0 && FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(mmdl) == 1) {
        FLDMMDL_OnMoveBitMoveStart(mmdl);
    }
}

void FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_MOVE_START) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst(mmdl);
    }
    FLDMMDL_ClearMoveBit(mmdl, _MOVEBIT_MOVE_START | _MOVEBIT_JUMP_START);
}

void FLDMMDL_RAIL_MOVE_ProcMoveStartSecond(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_JUMP_START) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond(mmdl);
    } else if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_MOVE_START) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartSecond(mmdl);
    }
    FLDMMDL_ClearMoveBit(mmdl, _MOVEBIT_MOVE_START | _MOVEBIT_JUMP_START);
}

void FLDMMDL_RAIL_MOVE_ProcMoveEnd(Mmdl *mmdl)
{
    if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_JUMP_END) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump(mmdl);
    } else if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_MOVE_END) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd(mmdl);
    }
    FLDMMDL_ClearMoveBit(mmdl, _MOVEBIT_MOVE_END | _MOVEBIT_JUMP_END);
}

/* Reads the map attributes at the current and the previous rail location;
 * returns 0 (and sets _MOVEBIT_ATTR_GET_ERROR) when there is none. */
u32 FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(Mmdl *mmdl)
{
    RailLocation prevLocation;
    RailLocation nowLocation;
    u32 attrOld = _ATTR_NONE;
    u32 attrNow = _ATTR_NONE;
    void *railMapper;
    if (FLDMMDL_CheckStatusBitAttrGetOff(mmdl) == 0) {
        railMapper = FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl));
        FLDMMDL_RAIL_GetNextLocation(mmdl, &nowLocation);
        FLDMMDL_RAIL_GetNowLocation(mmdl, &prevLocation);
        attrOld = FIELD_NOGRID_MAPPER_GetAttribute(railMapper, &prevLocation);
        attrNow = FIELD_NOGRID_MAPPER_GetAttribute(railMapper, &nowLocation);
    }
    FLDMMDL_SetOldAttr(mmdl, attrOld);
    FLDMMDL_SetNowAttr(mmdl, attrNow);
    if (attrNow == _ATTR_NONE) {
        FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_ATTR_GET_ERROR);
        return 0;
    }
    FLDMMDL_ClearMoveBit(mmdl, _MOVEBIT_ATTR_GET_ERROR);
    return 1;
}

void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(mmdl) != 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        attrNow = FLDMMDL_GetNowAttr(mmdl);
        attrOld = FLDMMDL_GetOldAttr(mmdl);
        param = FLDMMDL_GetObjCodeParam(mmdl);
        FLDMMDL_RAIL_MOVE_MapAttrGrassProc0(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrShadowProc0(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(mmdl, attrNow, attrOld, param);
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartSecond(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(mmdl) != 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        attrNow = FLDMMDL_GetNowAttr(mmdl);
        attrOld = FLDMMDL_GetOldAttr(mmdl);
        param = FLDMMDL_GetObjCodeParam(mmdl);
        FLDMMDL_RAIL_MOVE_MapAttrGrassProc12(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(mmdl, attrNow, attrOld, param);
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartJumpSecond(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(mmdl) != 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        attrNow = FLDMMDL_GetNowAttr(mmdl);
        attrOld = FLDMMDL_GetOldAttr(mmdl);
        param = FLDMMDL_GetObjCodeParam(mmdl);
        FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(mmdl, attrNow, attrOld, param);
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(mmdl) != 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        attrNow = FLDMMDL_GetNowAttr(mmdl);
        attrOld = FLDMMDL_GetOldAttr(mmdl);
        param = FLDMMDL_GetObjCodeParam(mmdl);
        FLDMMDL_RAIL_MOVE_MapAttrReflectProc2(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrEndNopProc(mmdl, attrNow, attrOld, param);
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump(Mmdl *mmdl)
{
    u32 attrNow;
    u32 attrOld;
    MmdlObjCodeParam *param;
    if (FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(mmdl) != 0 && FLDMMDL_CheckDrawInitComp(mmdl) == 1) {
        attrNow = FLDMMDL_GetNowAttr(mmdl);
        attrOld = FLDMMDL_GetOldAttr(mmdl);
        param = FLDMMDL_GetObjCodeParam(mmdl);
        FLDMMDL_RAIL_MOVE_MapAttrReflectProc2(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrEndNopProc(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrGrassProc12(mmdl, attrNow, attrOld, param);
        FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2(mmdl, attrNow, attrOld, param);
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrGrassProc0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    if (MAP_ATTR_GetFlags(attrNow) & _ATTRFLAG_GRASS)
        FLDEFF_GRASS_Start(FLDMMDL_RAIL_MOVE_GetFldEffCtrl(mmdl), mmdl, 0, 0);
}

void FLDMMDL_RAIL_MOVE_MapAttrGrassProc12(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    if (attrNow != _ATTR_NONE && (MAP_ATTR_GetFlags(attrNow) & _ATTRFLAG_GRASS))
        FLDEFF_GRASS_Start(FLDMMDL_RAIL_MOVE_GetFldEffCtrl(mmdl), mmdl, 1, 0);
}

void FLDMMDL_RAIL_MOVE_MapAttrFootMarkProc1(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    u32 fldEffCtrl;
    int cycle;
    if (attrOld != _ATTR_NONE && (MAP_ATTR_GetFlags(attrOld) & _ATTRFLAG_FOOTMARK)) {
        fldEffCtrl = FLDMMDL_RAIL_MOVE_GetFldEffCtrl(mmdl);
        cycle = 0;
        if (param->footMarkType == 2)
            cycle = 1;
        FLDEFF_FOOTMARK_SetMMdl(mmdl, fldEffCtrl, cycle);
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrShadowProc0(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(mmdl, attrNow, attrOld, param);
}

void FLDMMDL_RAIL_MOVE_MapAttrShadowProc12(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    if (FLDMMDL_SysIsDrawEnable(FLDMMDL_GetMmdlSys(mmdl)) != 0) {
        if (FLDMMDL_CheckMoveBit(mmdl, _MOVEBIT_SHADOW_SET) == 0) {
            FLDEFF_SHADOW_Start(mmdl, FLDMMDL_RAIL_MOVE_GetFldEffCtrl(mmdl));
            FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_SHADOW_SET);
        }
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrEndNopProc(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
}

int FLDMMDL_RAIL_MOVE_MapAttrGroundSmokeProc2(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    return FLDEFF_KEMURI_StartFacing(mmdl, FLDMMDL_RAIL_MOVE_GetFldEffCtrl(mmdl));
}

void FLDMMDL_RAIL_MOVE_MapAttrReflectProc01(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    u32 reflectAttr;
    u32 fldEffCtrl;
    void *mmdlSys;
    if (param->reflectType != 0 && FLDMMDL_CheckMoveBitReflect(mmdl) == 0) {
        reflectAttr = _ATTR_NONE;
        if (attrNow != _ATTR_NONE) {
            if (MAP_ATTR_GetFlags(attrNow) & _ATTRFLAG_REFLECT) {
                reflectAttr = attrNow;
            } else {
                attrNow = FLDMMDL_MOVE_GetDirMapAttr(mmdl, _DIR_DOWN);
                if (MAP_ATTR_GetFlags(attrNow) & _ATTRFLAG_REFLECT) {
                    reflectAttr = attrNow;
                }
            }
            if (reflectAttr != _ATTR_NONE) {
                fldEffCtrl = FLDMMDL_RAIL_MOVE_GetFldEffCtrl(mmdl);
                mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
                FLDMMDL_SetMoveBitReflect(mmdl, 1);
                FLDEFF_REFLECT_SetMMdl(mmdlSys, mmdl, fldEffCtrl, 1);
            }
        }
    }
}

void FLDMMDL_RAIL_MOVE_MapAttrReflectProc2(Mmdl *mmdl, u32 attrNow, u32 attrOld, MmdlObjCodeParam *param)
{
    int attrBelow;
    if (param->reflectType != 0 && FLDMMDL_CheckMoveBitReflect(mmdl) != 0) {
        attrBelow = FLDMMDL_MOVE_GetDirMapAttr(mmdl, _DIR_DOWN);
        if (attrBelow == -1) {
            FLDMMDL_SetMoveBitReflect(mmdl, 0);
            return;
        }
        if ((MAP_ATTR_GetFlags(attrBelow) & _ATTRFLAG_REFLECT) == 0) {
            FLDMMDL_SetMoveBitReflect(mmdl, 0);
        }
    }
}

/* Field effect control of the field map that owns the field model. */
u32 FLDMMDL_RAIL_MOVE_GetFldEffCtrl(Mmdl *mmdl)
{
    return FIELDMAP_GetEffect(FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys(mmdl)));
}

/* Anime command step: end of the command. */
int FLDMMDL_RAIL_MOVE_AcEnd(Mmdl *mmdl)
{
    FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_ACMD_END);
    return 0;
}

/* Anime command step: nothing, go to the next step. */
int FLDMMDL_RAIL_MOVE_AcNextStep(Mmdl *mmdl)
{
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

void FLDMMDL_RAIL_MOVE_AcDirSet(Mmdl *mmdl, u32 dir)
{
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
    FLDMMDL_SetDrawStatus(mmdl, _DRAW_STA_STOP);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_RAIL_MOVE_AcDirU0(Mmdl *mmdl)
{
    FLDMMDL_RAIL_MOVE_AcDirSet(mmdl, _DIR_UP);
    return 1;
}

int FLDMMDL_RAIL_MOVE_AcDirD0(Mmdl *mmdl)
{
    FLDMMDL_RAIL_MOVE_AcDirSet(mmdl, _DIR_DOWN);
    return 1;
}

int FLDMMDL_RAIL_MOVE_AcDirL0(Mmdl *mmdl)
{
    FLDMMDL_RAIL_MOVE_AcDirSet(mmdl, _DIR_LEFT);
    return 1;
}

int FLDMMDL_RAIL_MOVE_AcDirR0(Mmdl *mmdl)
{
    FLDMMDL_RAIL_MOVE_AcDirSet(mmdl, _DIR_RIGHT);
    return 1;
}

void FLDMMDL_RAIL_MOVE_AcWalkSet(Mmdl *mmdl, u32 dir, u32 frames, u16 drawStatus)
{
    FLDMMDL_RAIL_SetMoveRequest(mmdl, (u16)dir, frames);
    FLDMMDL_RAIL_SetGridPosByDir(mmdl, dir);
    FLDMMDL_SetDirAll(mmdl, (u16)dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_MOVE_START);
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_RAIL_MOVE_AcWalk1(Mmdl *mmdl)
{
    void *railWork;
    VecFx32 pos;
    railWork = FLDMMDL_RAIL_GetRailWork(mmdl);
    FLDMMDL_RAIL_UpdateRailWork(mmdl);
    FIELD_RAIL_WORK_GetPos(railWork, &pos);
    FLDMMDL_SetPos(mmdl, &pos);
    if (FIELD_RAIL_WORK_IsMoving(railWork)) {
        return 0;
    }
    FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_MOVE_END | _MOVEBIT_ACMD_END);
    FLDMMDL_SetDrawStatus(mmdl, _DRAW_STA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 0;
}

/* Anime command step: end of a walk command (stop animation). */
int FLDMMDL_RAIL_MOVE_AcWalkEnd(Mmdl *mmdl)
{
    FLDMMDL_SetDrawStatus(mmdl, _DRAW_STA_STOP);
    return 0;
}

int FLDMMDL_RAIL_MOVE_AcWalkU16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_UP, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkD16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_DOWN, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkL16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_LEFT, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkR16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_RIGHT, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkU8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_UP, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkD8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_DOWN, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkL8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_LEFT, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkR8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_RIGHT, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkU4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_UP, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkD4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_DOWN, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkL4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_LEFT, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkR4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_RIGHT, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkU2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_UP, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkD2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_DOWN, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkL2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_LEFT, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcWalkR2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_RIGHT, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcDashU4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_UP, 4, _DRAW_STA_DASH_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcDashD4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_DOWN, 4, _DRAW_STA_DASH_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcDashL4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_LEFT, 4, _DRAW_STA_DASH_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcDashR4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcWalkSet(mmdl, _DIR_RIGHT, 4, _DRAW_STA_DASH_4F); return 1; }

void FLDMMDL_RAIL_MOVE_AcStayWalkSet(Mmdl *mmdl, u32 dir, u16 frames, u16 drawStatus)
{
    RailAcmdStayWalkWork *work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(RailAcmdStayWalkWork), frames);
    work->drawStatus = drawStatus;
    work->frameCount = frames;
    FLDMMDL_SetDirDispCheckPause(mmdl, (u16)dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_IncAcmdSeq(mmdl);
}

int FLDMMDL_RAIL_MOVE_AcStayWalk1(Mmdl *mmdl)
{
    RailAcmdStayWalkWork *work = FLDMMDL_GetMoveCmdWork(mmdl);
    work->frameCount--;
    if (work->frameCount > 0)
        return 0;
    FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_ACMD_END);
    FLDMMDL_SetDrawStatus(mmdl, _DRAW_STA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    return 1;
}

int FLDMMDL_RAIL_MOVE_AcStayWalkU32F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_UP, 32, _DRAW_STA_WALK_32F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkD32F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_DOWN, 32, _DRAW_STA_WALK_32F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkL32F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_LEFT, 32, _DRAW_STA_WALK_32F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkR32F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_RIGHT, 32, _DRAW_STA_WALK_32F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkU16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_UP, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkD16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_DOWN, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkL16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_LEFT, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkR16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_RIGHT, 16, _DRAW_STA_WALK_16F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkU8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_UP, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkD8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_DOWN, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkL8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_LEFT, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkR8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_RIGHT, 8, _DRAW_STA_WALK_8F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkU2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_UP, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkD2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_DOWN, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkL2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_LEFT, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkR2F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_RIGHT, 2, _DRAW_STA_WALK_2F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkU4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_UP, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkD4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_DOWN, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkL4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_LEFT, 4, _DRAW_STA_WALK_4F); return 1; }
int FLDMMDL_RAIL_MOVE_AcStayWalkR4F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcStayWalkSet(mmdl, _DIR_RIGHT, 4, _DRAW_STA_WALK_4F); return 1; }

void FLDMMDL_RAIL_MOVE_AcJumpSetSe(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep, u32 seNo)
{
    RailAcmdJumpWork *work;
    work = FLDMMDL_InitMoveCmdWork(mmdl, sizeof(RailAcmdJumpWork), speed);
    work->dir = dir;
    work->speed = speed;
    work->frameCount = frames;
    work->drawStatus = drawStatus;
    work->heightTable = heightTable;
    work->heightStep = heightStep;
    if (speed == 0) {
        FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    } else {
        FLDMMDL_RAIL_SetMoveRequest(mmdl, (u16)dir, 8);
        FLDMMDL_RAIL_SetGridPosByDir(mmdl, dir);
    }
    FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_MOVE_START | _MOVEBIT_JUMP_START);
    FLDMMDL_SetDirAll(mmdl, (u16)dir);
    FLDMMDL_SetDrawStatus(mmdl, drawStatus);
    FLDMMDL_IncAcmdSeq(mmdl);
    if (seNo) {
        GFL_USE_PlaySeDefaultVolume(seNo);
    }
}

void FLDMMDL_RAIL_MOVE_AcJumpSet(Mmdl *mmdl, u32 dir, u32 speed, u8 frames, u16 drawStatus, s16 heightTable, u16 heightStep)
{
    FLDMMDL_RAIL_MOVE_AcJumpSetSe(mmdl, dir, speed, frames, drawStatus, heightTable, heightStep, _SE_RAIL_JUMP);
}

int FLDMMDL_RAIL_MOVE_AcJump1(Mmdl *mmdl)
{
    RailAcmdJumpWork *work;
    void *railWork;
    s32 absSpeed;
    s32 heightIndex;
    s32 table;
    VecFx32 pos;
    VecFx32 offset;
    s32 zeroOffset[3]; /* stand-in: a VecFx32 here moves it on the stack; the s32[3] seen through a VecFx32 pointer keeps the layout */
    work = FLDMMDL_GetMoveCmdWork(mmdl);
    work->frameCount--;
    if (work->speed != 0) {
        railWork = FLDMMDL_RAIL_GetRailWork(mmdl);
        FLDMMDL_RAIL_UpdateRailWork(mmdl);
        FIELD_RAIL_WORK_GetPos(railWork, &pos);
        FLDMMDL_SetPos(mmdl, &pos);
        if (work->moveAcc >= 0x10000 && work->frameCount > 0) {
            work->moveAcc = 0;
            FLDMMDL_RAIL_SetMoveRequest(mmdl, work->dir, 8);
            FLDMMDL_RAIL_SetGridPosByDir(mmdl, work->dir);
            FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_MOVE_START);
        }
        absSpeed = work->speed;
        if (absSpeed < 0) {
            absSpeed = -absSpeed;
        }
        work->moveAcc += absSpeed;
    }
    work->heightPos += work->heightStep;
    if (work->heightPos > 0xF00) {
        work->heightPos = 0xF00;
    }
    heightIndex = (u16)(work->heightPos / 256);
    table = work->heightTable;
    offset.x = 0;
    offset.y = d_021DDD94[table][heightIndex];
    offset.z = 0;
    FLDMMDL_SetDrawOffset(mmdl, &offset);
    if (work->frameCount > 0 || FIELD_RAIL_WORK_IsMoving(railWork)) {
        return 0;
    }
    {
        VecFx32 *zero = (VecFx32 *)zeroOffset;
        zero->x = 0;
        zero->y = 0;
        zero->z = 0;
        FLDMMDL_SetDrawOffset(mmdl, zero);
    }
    FLDMMDL_SetMoveBit(mmdl, _MOVEBIT_MOVE_END | _MOVEBIT_JUMP_END | _MOVEBIT_ACMD_END);
    FLDMMDL_MOVE_UpdateOldGridPos(mmdl);
    FLDMMDL_SetDrawStatus(mmdl, _DRAW_STA_STOP);
    FLDMMDL_IncAcmdSeq(mmdl);
    GFL_USE_PlaySeDefaultVolume(_SE_RAIL_LAND);
    return 1;
}

int FLDMMDL_RAIL_MOVE_AcJumpU8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_UP, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpD8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_DOWN, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpL8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_LEFT, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpR8F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_RIGHT, 0x2000, 8, _DRAW_STA_WALK_8F, 0, 0x200); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpU16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_UP, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpD16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_DOWN, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpL16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_LEFT, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
int FLDMMDL_RAIL_MOVE_AcJumpR16F0(Mmdl *mmdl) { FLDMMDL_RAIL_MOVE_AcJumpSet(mmdl, _DIR_RIGHT, 0x2000, 16, _DRAW_STA_WALK_8F, 0, 0x100); return 1; }
