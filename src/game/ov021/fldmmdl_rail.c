/*
 * file:     fldmmdl_rail.c
 * unit:     yes
 * function: FLDMMDL_RAIL_SetLocation, FLDMMDL_RAIL_GetNextLocation, FLDMMDL_RAIL_GetNowLocation, FLDMMDL_RAIL_GetRailWork, FLDMMDL_RAIL_UpdateRailWork, FLDMMDL_RAIL_SetMoveRequest, FLDMMDL_RAIL_GetHitBitsLocation, FLDMMDL_RAIL_GetHitBitsDirNoAttr, FLDMMDL_RAIL_GetHitBitsDir, FLDMMDL_RAIL_CheckHitMmdl, FLDMMDL_RAIL_SearchMmdlByLocation, FLDMMDL_RAIL_GetFrontLocation, FLDMMDL_RAIL_GetLocationByDir, FLDMMDL_RAIL_SetGridPosByDir, FLDMMDL_RAIL_GetDrawOffset, FLDMMDL_RAIL_GetDrawOffsetByDir, FLDMMDL_RAIL_StayInit, FLDMMDL_RAIL_StayMove, FLDMMDL_RAIL_StayDelete, FLDMMDL_RAIL_AcquireRailWorkBody, FLDMMDL_RAIL_DirToRailKey, FLDMMDL_RAIL_RailKeyToDir, FLDMMDL_RAIL_InitMoveWork, FLDMMDL_RAIL_CheckOutsideHomeArea, FLDMMDL_RAIL_GetTableLength, FLDMMDL_RAIL_GetRandomTableEntry, FLDMMDL_RAIL_GetRandomDirOfKind, FLDMMDL_RAIL_GetDirListOfKind, FLDMMDL_RAIL_InitRailWork, FLDMMDL_RAIL_StoreNowLocation, FLDMMDL_RAIL_ReleaseRailWork, FLDMMDL_RAIL_AcquireRailWork, FLDMMDL_RAIL_StoreLocation, FLDMMDL_RAIL_ApplyStoredLocation, FLDMMDL_RAIL_LookAroundInit, FLDMMDL_RAIL_LookAroundMoveBody, FLDMMDL_RAIL_LookAroundDeleteBody, FLDMMDL_RAIL_WanderInit, FLDMMDL_RAIL_WanderMoveBody, FLDMMDL_RAIL_WanderDeleteBody, FLDMMDL_RAIL_ShuttleInitBody, FLDMMDL_RAIL_ShuttleMoveBody, FLDMMDL_RAIL_ShuttleDeleteBody
 * address:  0x0219E2C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl_g3dobj.c at 0x0219E2C0 (no anchor; the field model rail location API and rail move types; it never calls fldmmdl_rail_move.c, which calls it).
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   FLDMMDL_SysGetNogridMapper  0x0216D530  thumb
 *   FIELD_NOGRID_MAPPER_GetAttribute  0x021BB3C4  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_CheckStatusBitAttrGetOff  0x0216DCB4  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FIELD_RAIL_WORK_IsMoving  0x021B8040  thumb  ov021
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb  ov021
 *   FIELD_RAIL_WORK_GetLocation  0x021B7DC0  thumb
 *   FIELD_RAIL_WORK_QueryStep  0x021B7E60  thumb
 *   FIELD_RAIL_WORK_GetLastKey  0x021B8038  thumb
 *   FIELD_NOGRID_MAPPER_GetRailMan  0x021BB480  thumb
 *   FIELD_RAIL_WORK_UpdateStep  0x021B810C  thumb  ov021
 *   FIELD_RAIL_WORK_StartStep  0x021B80E0  thumb  ov021
 *   FIELD_RAIL_WORK_IsLocationValid  0x021B7DE0  thumb  ov021
 *   FIELD_RAIL_TryStepLocation  0x021B7CD8  thumb  ov021
 *   FIELD_RAIL_GetLocationPos  0x021B7D38  thumb  ov021
 *   FIELD_RAIL_GetUnitScale  0x021B7C38  thumb  ov021
 *   FX_Div  0x0207C768  arm
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FIELD_RAIL_WORK_GetPrevPos  0x021B7ED4  thumb  ov021
 *   FIELD_RAIL_IsPosNear  0x021B83B0  thumb  ov021
 *   ZONEDATA_DirToRailKey  0x0201441C  thumb
 *   FIELD_RAIL_StepLocation  0x021B7C90  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 *   FIELD_RAIL_WORK_GetStepVector  0x021B8050  thumb  ov021
 *   FIELD_RAIL_WORK_GetLineKey  0x021B80D8  thumb  ov021
 *   MTX_RotY33_  0x0207AF1C  thumb
 *   MTX_MultVec33  0x0207B51C  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   d_021D84D4     0x021D84D4  data  ov021  a1
 *   d_021D841C     0x021D841C  data  ov021  a2
 *   FX_SinCosTable_     0x020A1B38  data  a2
 *   FLDMMDL_MOVE_GetRailMoveRequest  0x02164380  thumb  ov010
 *   FLDMMDL_InitMoveProcWork  0x0216D684  thumb  ov010
 *   FLDMMDL_GetMoveLimitX  0x0216D660  thumb  ov010
 *   FLDMMDL_GetMoveLimitZ  0x0216D66C  thumb  ov010
 *   func_020056EC  0x020056EC  thumb
 *   d_021D84E8  0x021D84E8  data
 *   FIELD_NOGRID_MAPPER_CreateRailWork  0x021BB394  thumb  ov021
 *   FIELD_NOGRID_MAPPER_DeleteRailWork  0x021BB3A0  thumb  ov021
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   d_021D84AC     0x021D84AC  data
 *   FLDMMDL_OffMoveBitMoveEnd  0x0216DA7C  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb  ov010
 *   FLDMMDL_GetDirHeader  0x0216D5D4  thumb  ov010
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 */
#include "fldmmdl_rail_types.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;
typedef signed long long s64;

typedef struct { s32 x, y, z; } VecFx32;

/* Opaque types owned by other files. */
typedef struct Mmdl Mmdl;             /* a field model (fldmmdl.c) */
typedef struct MmdlSys MmdlSys;       /* the field model system */
typedef struct FieldSys FieldSys;
typedef struct RailManager RailManager;
typedef struct RailWork RailWork;     /* the rail walker of one field model */

/* Move work of every rail move type: the rail walker and the last location
 * read from it. Each move type appends its own fields at 0xC. */
typedef struct {
    RailWork *railWork;
    RailLocation location;
} RailMoveWork;

/* Look around move types (turn at random, never walk). */
typedef struct {
    RailMoveWork base;
    s16 waitCount;     /* frames until the next turn */
    u16 kind;          /* index into d_021D84E8 */
} RailLookAroundWork;

/* Wander move types (walk at random around the home location). */
typedef struct {
    RailMoveWork base;
    u8 state : 4;
    u8 kind : 4;       /* index into d_021D84E8 */
    s8 waitCount;
    s8 homeWidth;
    u8 homeLine;
} RailWanderWork;

/* Shuttle move type (walk forward, turn around when blocked, come back). */
typedef struct {
    RailMoveWork base;
    u8 state;
    u8 returning;
    s8 homeWidth;
    u8 homeLine;
} RailShuttleWork;

typedef struct {
    int kind;
    u32 *dirList;      /* mmdl directions, ended by _DIR_LIST_END */
} DirListEntry;

/* Mmdl status bits (FLDMMDL_CheckStatusBit tests, FLDMMDL_ClearStatusBit sets). */
#define _STATUSBIT_NO_HIT    0x80
#define _STATUSBIT_NO_RAIL   0x2000    /* the rail walker is released */

#define _DIR_LIST_END   9
#define _KIND_COUNT     11
#define _LOCATION_NOT_SET 2    /* RailLocation.type of a work not set yet */

/* Anime command kinds for FLDMMDL_ACMD_ConvertCodeByDir (direction, kind). */
#define _ACMD_KIND_STOP      0x00
#define _ACMD_KIND_WALK      0x0C
#define _ACMD_KIND_STAY_WALK 0x20

#define _WANDER_START      0    /* stop and play the idle animation */
#define _WANDER_IDLE_ANIM  1    /* wait for the idle animation to end */
#define _WANDER_WAIT       2    /* count the wait frames down */
#define _WANDER_PICK_STEP  3    /* pick a direction and start the step */
#define _WANDER_STEP_ANIM  4    /* wait for the step animation to end */

#define _SHUTTLE_START     0
#define _SHUTTLE_CHECK     1
#define _SHUTTLE_STEP_ANIM 2

extern void *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern void MI_CpuFill8(void *dst, u32 value, u32 size);
extern FieldSys *FLDMMDL_SysGetNogridMapper(MmdlSys *mmdlSys);
extern u32 FIELD_NOGRID_MAPPER_GetAttribute(FieldSys *fieldSys, RailLocation *loc);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern int FLDMMDL_CheckStatusBitAttrGetOff(Mmdl *mmdl);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern void FLDMMDL_SetDirDispCheckPause(Mmdl *mmdl, int dir);
extern void FLDMMDL_SetDrawStatus(Mmdl *mmdl, u16 value);
extern void FLDMMDL_SetDirAll(Mmdl *mmdl, u16 dir);
extern void FIELD_RAIL_WORK_GetPos(RailWork *railWork, VecFx32 *outPos);
extern u8 FIELD_RAIL_WORK_IsMoving(RailWork *railWork);
extern void FLDMMDL_SetPos(Mmdl *mmdl, VecFx32 *pos);
extern void *FLDMMDL_GetMoveProcWork(Mmdl *mmdl);
extern void FIELD_RAIL_WORK_SetLocation(RailWork *railWork, RailLocation *loc);
extern RailManager *FIELD_NOGRID_MAPPER_GetRailMan(FieldSys *fieldSys);
extern u8 FIELD_RAIL_WORK_GetLastKey(RailWork *railWork);
extern int FIELD_RAIL_WORK_QueryStep(RailWork *railWork, u32 key, RailLocation *outLoc, VecFx32 *outPos);
extern u32 FIELD_RAIL_WORK_GetLocation(RailWork *railWork, RailLocation *outLoc);
extern void FIELD_RAIL_WORK_UpdateStep(RailWork *railWork);
extern void FIELD_RAIL_WORK_StartStep(RailWork *railWork, u32 dir, u32 key);
extern int FIELD_RAIL_WORK_IsLocationValid(RailWork *railWork, RailLocation *loc);
extern int FIELD_RAIL_TryStepLocation(RailManager *mgr, RailLocation *loc, u32 key, RailLocation *outLoc);
extern void FIELD_RAIL_GetLocationPos(RailManager *mgr, RailLocation *loc, VecFx32 *outPos);
extern int FIELD_RAIL_GetUnitScale(RailManager *mgr);
extern u32 FX_Div(u32 a, u32 b);
extern int FLDMMDL_SysSearchUseMmdl(MmdlSys *mmdlSys, Mmdl **outMmdl, u32 *iter);
extern int FLDMMDL_CheckStatusBit(Mmdl *mmdl, int bits);
extern void FIELD_RAIL_WORK_GetPrevPos(RailWork *railWork, VecFx32 *outPos);
extern int FIELD_RAIL_IsPosNear(const VecFx32 *a, const VecFx32 *b, s32 radius);
extern u8 ZONEDATA_DirToRailKey(int dir);
extern int FIELD_RAIL_StepLocation(RailManager *mgr, RailLocation *loc, u32 key, VecFx32 *outPos);
extern int FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern void FLDMMDL_SetGridOldX(Mmdl *mmdl, int gridX);
extern int FLDMMDL_GetGridNowY(Mmdl *mmdl);
extern void FLDMMDL_SetGridOldY(Mmdl *mmdl, int gridY);
extern int FLDMMDL_GetGridNowZ(Mmdl *mmdl);
extern void FLDMMDL_SetGridOldZ(Mmdl *mmdl, int gridZ);
extern void FLDMMDL_SetGridNowX(Mmdl *mmdl, short gridX);
extern void FLDMMDL_SetGridNowY(Mmdl *mmdl, int gridY);
extern void FLDMMDL_SetGridNowZ(Mmdl *mmdl, int gridZ);
extern void FIELD_RAIL_WORK_GetStepVector(RailWork *railWork, s16 *outOffset);
extern u32 FIELD_RAIL_WORK_GetLineKey(RailWork *railWork);
extern void MTX_RotY33_(s32 *outMtx, s32 sin, s32 cos);
extern void MTX_MultVec33(VecFx32 *vec, s32 *mtx, VecFx32 *outVec);
extern void VEC_Normalize(VecFx32 *vec, VecFx32 *outVec);
extern int FLDMMDL_MOVE_GetRailMoveRequest(Mmdl *mmdl, RailLocation *outLoc);
extern void *FLDMMDL_InitMoveProcWork(Mmdl *mmdl, u32 size);
extern int FLDMMDL_GetMoveLimitX(Mmdl *mmdl);
extern int FLDMMDL_GetMoveLimitZ(Mmdl *mmdl);
extern u32 func_020056EC(u32 range);
extern RailWork *FIELD_NOGRID_MAPPER_CreateRailWork(FieldSys *fieldSys);
extern Mmdl *FLDMMDL_ClearStatusBit(Mmdl *mmdl, u32 bits);
extern void FIELD_NOGRID_MAPPER_DeleteRailWork(FieldSys *fieldSys, RailWork *railWork);
extern void FLDMMDL_OffMoveBitMove(Mmdl *mmdl);
extern void FLDMMDL_OffMoveBitMoveEnd(Mmdl *mmdl);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int dir, int kind);
extern void FLDMMDL_SetLocalAcmd(Mmdl *mmdl, int acmdCode);
extern u32 FLDMMDL_ACMD_Update(Mmdl *mmdl);
extern void FLDMMDL_OnMoveBitMove(Mmdl *mmdl);
extern int FLDMMDL_GetDirHeader(Mmdl *mmdl);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int dir);
extern u16 FLDMMDL_GetDirMove(Mmdl *mmdl);

void FLDMMDL_RAIL_SetLocation(Mmdl *mmdl, RailLocation *loc);
void FLDMMDL_RAIL_GetNextLocation(Mmdl *mmdl, RailLocation *outLoc);
int FLDMMDL_RAIL_GetNowLocation(Mmdl *mmdl, RailLocation *outLoc);
RailWork *FLDMMDL_RAIL_GetRailWork(Mmdl *mmdl);
void FLDMMDL_RAIL_UpdateRailWork(Mmdl *mmdl);
void FLDMMDL_RAIL_SetMoveRequest(Mmdl *mmdl, u32 dir, u32 key);
u32 FLDMMDL_RAIL_GetHitBitsLocation(Mmdl *mmdl, RailLocation *nowLoc, RailLocation *nextLoc, u32 *outAttr);
int FLDMMDL_RAIL_GetHitBitsDirNoAttr(Mmdl *mmdl, u16 dir);
int FLDMMDL_RAIL_GetHitBitsDir(Mmdl *mmdl, u32 dir, u32 *outAttr);
int FLDMMDL_RAIL_CheckHitMmdl(Mmdl *mmdl, RailLocation *loc);
Mmdl *FLDMMDL_RAIL_SearchMmdlByLocation(MmdlSys *mmdlSys, RailLocation *loc, u32 includeNow);
int FLDMMDL_RAIL_GetFrontLocation(Mmdl *mmdl, RailLocation *outLoc);
int FLDMMDL_RAIL_GetLocationByDir(Mmdl *mmdl, u32 dir, RailLocation *outLoc);
void FLDMMDL_RAIL_SetGridPosByDir(Mmdl *mmdl, u16 dir);
void FLDMMDL_RAIL_GetDrawOffset(Mmdl *mmdl, s16 *outOffset);
void FLDMMDL_RAIL_GetDrawOffsetByDir(Mmdl *mmdl, u32 dir, s16 *outOffset);
RailMoveWork *FLDMMDL_RAIL_StayInit(Mmdl *mmdl);
void FLDMMDL_RAIL_StayMove(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3);
int FLDMMDL_RAIL_StayDelete(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3);
void FLDMMDL_RAIL_AcquireRailWorkBody(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind0(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind1(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind2(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind3(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind4(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind5(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind6(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind7(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind8(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind9(Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInitKind10(Mmdl *mmdl);
int FLDMMDL_RAIL_LookAroundMove(Mmdl *mmdl);
int FLDMMDL_RAIL_LookAroundDelete(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderInitKind0(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderInitKind9(Mmdl *mmdl);
int FLDMMDL_RAIL_WanderMove(Mmdl *mmdl);
int FLDMMDL_RAIL_WanderDelete(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleInit(Mmdl *mmdl);
int FLDMMDL_RAIL_ShuttleMove(Mmdl *mmdl);
int FLDMMDL_RAIL_ShuttleDelete(Mmdl *mmdl);
u32 FLDMMDL_RAIL_DirToRailKey(int dir);
u32 FLDMMDL_RAIL_RailKeyToDir(int key);
RailMoveWork *FLDMMDL_RAIL_InitMoveWork(Mmdl *mmdl, u32 size);
int FLDMMDL_RAIL_CheckOutsideHomeArea(Mmdl *mmdl, int homeLine, int homeWidth, RailLocation *loc);
int FLDMMDL_RAIL_GetTableLength(u32 *table, u32 terminator);
int FLDMMDL_RAIL_GetRandomTableEntry(u32 *table, int terminator);
u32 FLDMMDL_RAIL_GetRandomDirOfKind(u32 kind, u32 terminator);
u32 *FLDMMDL_RAIL_GetDirListOfKind(int kind);
int FLDMMDL_RAIL_InitRailWork(RailMoveWork *work, Mmdl *mmdl);
void FLDMMDL_RAIL_StoreNowLocation(RailMoveWork *work, Mmdl *mmdl);
u32 FLDMMDL_RAIL_ReleaseRailWork(RailMoveWork *work, Mmdl *mmdl);
void FLDMMDL_RAIL_AcquireRailWork(RailMoveWork *work, Mmdl *mmdl);
void FLDMMDL_RAIL_StoreLocation(RailMoveWork *work, const RailLocation *loc);
void FLDMMDL_RAIL_ApplyStoredLocation(RailMoveWork *work, Mmdl *mmdl);
void FLDMMDL_RAIL_LookAroundInit(Mmdl *mmdl, u16 kind);
int FLDMMDL_RAIL_LookAroundMoveBody(Mmdl *mmdl);
int FLDMMDL_RAIL_LookAroundDeleteBody(Mmdl *mmdl);
void FLDMMDL_RAIL_WanderInit(Mmdl *mmdl, u32 kind);
int FLDMMDL_RAIL_WanderMoveBody(Mmdl *mmdl);
int FLDMMDL_RAIL_WanderDeleteBody(Mmdl *mmdl);
void FLDMMDL_RAIL_ShuttleInitBody(Mmdl *mmdl);
int FLDMMDL_RAIL_ShuttleMoveBody(Mmdl *mmdl);
int FLDMMDL_RAIL_ShuttleDeleteBody(Mmdl *mmdl);

extern u8 d_021D84D4[][4];       /* [slope kind][direction] -> angle index */
extern u16 d_021D841C[];         /* angles: 0, 180, 90, 270 degrees */
extern s16 FX_SinCosTable_[];         /* sin/cos table, pairs, 4096 = 1.0 */
extern DirListEntry d_021D84E8[];
extern u32 d_021D84AC[];         /* wait frames, ended by -1 */

/* Set the location of a model and place it there. */
void FLDMMDL_RAIL_SetLocation(Mmdl *mmdl, RailLocation *loc)
{
    RailMoveWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    VecFx32 pos;
    FIELD_RAIL_WORK_SetLocation(work->railWork, loc);
    FLDMMDL_RAIL_StoreLocation(work, loc);
    FIELD_RAIL_WORK_GetPos(work->railWork, &pos);
    FLDMMDL_SetPos(mmdl, &pos);
}

/* Read where the model goes: the target while it moves, else the place it is. */
void FLDMMDL_RAIL_GetNextLocation(Mmdl *mmdl, RailLocation *outLoc)
{
    RailMoveWork *work;

    FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)));
    work = FLDMMDL_GetMoveProcWork(mmdl);
    if (FIELD_RAIL_WORK_IsMoving(work->railWork))
        FIELD_RAIL_WORK_QueryStep(work->railWork, FIELD_RAIL_WORK_GetLastKey(work->railWork), outLoc, 0);
    else
        FIELD_RAIL_WORK_GetLocation(work->railWork, outLoc);
}

/* Read the place the model is at now. */
int FLDMMDL_RAIL_GetNowLocation(Mmdl *mmdl, RailLocation *outLoc)
{
    return FIELD_RAIL_WORK_GetLocation(((RailMoveWork *)FLDMMDL_GetMoveProcWork(mmdl))->railWork, outLoc);
}

RailWork *FLDMMDL_RAIL_GetRailWork(Mmdl *mmdl)
{
    return ((RailMoveWork *)FLDMMDL_GetMoveProcWork(mmdl))->railWork;
}

/* Run the rail walker and store the place it reaches. */
void FLDMMDL_RAIL_UpdateRailWork(Mmdl *mmdl)
{
    RailMoveWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    FIELD_RAIL_WORK_UpdateStep(work->railWork);
    FLDMMDL_RAIL_StoreNowLocation(work, mmdl);
}

/* Ask the rail walker for a step. */
void FLDMMDL_RAIL_SetMoveRequest(Mmdl *mmdl, u32 dir, u32 key)
{
    RailMoveWork *work = FLDMMDL_GetMoveProcWork(mmdl);
    u32 railKey = FLDMMDL_RAIL_DirToRailKey(dir);
    FIELD_RAIL_WORK_StartStep(work->railWork, FLDMMDL_RAIL_RailKeyToDir(key), railKey);
}

/* Test a step from nowLoc to nextLoc. Bit 0: no rail there. Bit 1: the map
 * attribute blocks it. Bit 2: another model stands there. */
u32 FLDMMDL_RAIL_GetHitBitsLocation(Mmdl *mmdl, RailLocation *nowLoc, RailLocation *nextLoc, u32 *outAttr)
{
    u32 hitBits;
    RailMoveWork *work;
    FieldSys *fieldSys;
    u32 attr;

    hitBits = 0;
    work = FLDMMDL_GetMoveProcWork(mmdl);
    fieldSys = FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl));
    if (!FIELD_RAIL_WORK_IsLocationValid(work->railWork, nowLoc)) {
        hitBits |= 1;
    }
    if (!FIELD_RAIL_WORK_IsLocationValid(work->railWork, nextLoc)) {
        hitBits |= 1;
    }
    if (!FLDMMDL_CheckStatusBitAttrGetOff(mmdl)) {
        attr = FIELD_NOGRID_MAPPER_GetAttribute(fieldSys, nextLoc);
        if (MAP_ATTR_GetFlags(attr) & 1) {
            hitBits |= 2;
        }
        if (outAttr) {
            *outAttr = attr;
        }
    }
    if (FLDMMDL_RAIL_CheckHitMmdl(mmdl, nextLoc)) {
        hitBits |= 4;
    }
    return hitBits;
}

/* Test a step in dir, ignoring the map attribute. */
int FLDMMDL_RAIL_GetHitBitsDirNoAttr(Mmdl *mmdl, u16 dir)
{
    return FLDMMDL_RAIL_GetHitBitsDir(mmdl, dir, 0);
}

/* Test a step in dir. Returns 1 when the rails have no place there. */
int FLDMMDL_RAIL_GetHitBitsDir(Mmdl *mmdl, u32 dir, u32 *outAttr)
{
    RailManager *railMgr;
    RailMoveWork *work;
    RailLocation nowLoc;
    RailLocation nextLoc;
    int found;
    u32 curDir;

    railMgr = FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)));
    work = FLDMMDL_GetMoveProcWork(mmdl);
    FIELD_RAIL_WORK_GetLocation(work->railWork, &nowLoc);
    curDir = FLDMMDL_GetDirDisp(mmdl);
    if (curDir == dir) {
        found = FIELD_RAIL_WORK_QueryStep(work->railWork, FLDMMDL_RAIL_DirToRailKey(dir), &nextLoc, 0);
    } else {
        found = FIELD_RAIL_TryStepLocation(railMgr, &nowLoc, FLDMMDL_RAIL_DirToRailKey(dir), &nextLoc);
    }
    if (found) {
        return FLDMMDL_RAIL_GetHitBitsLocation(mmdl, &nowLoc, &nextLoc, outAttr);
    }
    return 1;
}

/* Does another model stand within reach of loc? */
int FLDMMDL_RAIL_CheckHitMmdl(Mmdl *mmdl, RailLocation *loc)
{
    Mmdl *other;
    RailWork *otherWork;
    VecFx32 targetPos;
    VecFx32 otherPos;
    u32 iter;
    MmdlSys *mmdlSys;
    u32 mask;
    RailManager *railMgr;
    u32 reach;
    int notCounted;

    mmdlSys = FLDMMDL_GetMmdlSys(mmdl);
    railMgr = FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(mmdlSys));
    iter = 0;
    FIELD_RAIL_GetLocationPos(railMgr, loc, &targetPos);
    reach = FX_Div(FIELD_RAIL_GetUnitScale(railMgr), 0x4000);
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &other, &iter) == 1) {
        mask = _STATUSBIT_NO_RAIL;
        if (other == mmdl) {
            continue;
        }
        if (FLDMMDL_CheckStatusBit(other, _STATUSBIT_NO_HIT) != 0) {
            continue;
        }
        notCounted = (FLDMMDL_CheckStatusBit(other, mask) == 0);
        if (!notCounted) {
            otherWork = FLDMMDL_RAIL_GetRailWork(other);
            if (FIELD_RAIL_WORK_IsMoving(otherWork)) {
                FIELD_RAIL_WORK_QueryStep(otherWork, FIELD_RAIL_WORK_GetLastKey(otherWork), 0, &otherPos);
                if (FIELD_RAIL_IsPosNear(&targetPos, &otherPos, reach)) {
                    return 1;
                }
            }
            FIELD_RAIL_WORK_GetPrevPos(otherWork, &otherPos);
            if (FIELD_RAIL_IsPosNear(&targetPos, &otherPos, reach)) {
                return 1;
            }
        }
    }
    return 0;
}

/* Find the model that stands at loc (also at its target when includeNow). */
Mmdl *FLDMMDL_RAIL_SearchMmdlByLocation(MmdlSys *mmdlSys, RailLocation *loc, u32 includeNow)
{
    RailManager *railMgr;
    u32 reach;
    VecFx32 targetPos;
    VecFx32 otherPos;
    u32 iter;
    Mmdl *other;
    RailLocation otherLoc;
    RailLocation otherNextLoc;
    u32 mask;
    int notCounted;

    iter = 0;
    railMgr = FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(mmdlSys));
    FIELD_RAIL_GetLocationPos(railMgr, loc, &targetPos);
    reach = FX_Div(FIELD_RAIL_GetUnitScale(railMgr), 0x4000);
    while (FLDMMDL_SysSearchUseMmdl(mmdlSys, &other, &iter) == 1) {
        mask = _STATUSBIT_NO_RAIL;
        notCounted = (FLDMMDL_CheckStatusBit(other, mask) == 0);
        if (!notCounted) {
            if (includeNow) {
                FLDMMDL_RAIL_GetNowLocation(other, &otherLoc);
                FIELD_RAIL_GetLocationPos(railMgr, &otherLoc, &otherPos);
                if (FIELD_RAIL_IsPosNear(&targetPos, &otherPos, reach)) {
                    return other;
                }
            }
            FLDMMDL_RAIL_GetNextLocation(other, &otherNextLoc);
            FIELD_RAIL_GetLocationPos(railMgr, &otherNextLoc, &otherPos);
            if (FIELD_RAIL_IsPosNear(&targetPos, &otherPos, reach)) {
                return other;
            }
        }
    }
    return 0;
}

/* Read the place in front of the model. */
int FLDMMDL_RAIL_GetFrontLocation(Mmdl *mmdl, RailLocation *outLoc)
{
    RailMoveWork *work;

    FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl));
    work = FLDMMDL_GetMoveProcWork(mmdl);
    return FIELD_RAIL_WORK_QueryStep(work->railWork, ZONEDATA_DirToRailKey(FLDMMDL_GetDirDisp(mmdl)), outLoc, 0);
}

/* Read the place one step away in dir. */
int FLDMMDL_RAIL_GetLocationByDir(Mmdl *mmdl, u32 dir, RailLocation *outLoc)
{
    RailManager *railMgr;
    u32 curDir;
    RailMoveWork *work;

    railMgr = FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)));
    curDir = FLDMMDL_GetDirDisp(mmdl);
    work = FLDMMDL_GetMoveProcWork(mmdl);
    if (curDir != dir) {
        FLDMMDL_RAIL_GetNextLocation(mmdl, outLoc);
        return FIELD_RAIL_TryStepLocation(railMgr, outLoc, ZONEDATA_DirToRailKey(dir), outLoc);
    }
    return FIELD_RAIL_WORK_QueryStep(work->railWork, ZONEDATA_DirToRailKey(dir), outLoc, 0);
}

/* Put the model on the grid cell one step away in dir. */
void FLDMMDL_RAIL_SetGridPosByDir(Mmdl *mmdl, u16 dir)
{
    RailManager *railMgr;
    VecFx32 pos;
    RailLocation nowLoc;

    railMgr = FIELD_NOGRID_MAPPER_GetRailMan(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)));
    FLDMMDL_RAIL_GetNextLocation(mmdl, &nowLoc);
    FIELD_RAIL_StepLocation(railMgr, &nowLoc, ZONEDATA_DirToRailKey(dir), &pos);
    FLDMMDL_SetGridOldX(mmdl, FLDMMDL_GetGridNowX(mmdl));
    FLDMMDL_SetGridOldY(mmdl, FLDMMDL_GetGridNowY(mmdl));
    FLDMMDL_SetGridOldZ(mmdl, FLDMMDL_GetGridNowZ(mmdl));
    FLDMMDL_SetGridNowX(mmdl, (pos.x >> 4) / 4096);
    FLDMMDL_SetGridNowY(mmdl, (s16)((pos.y >> 4) / 4096));
    FLDMMDL_SetGridNowZ(mmdl, (s16)((pos.z >> 4) / 4096));
}

/* Read the draw offset of the model for the direction it faces. */
void FLDMMDL_RAIL_GetDrawOffset(Mmdl *mmdl, s16 *outOffset)
{
    FLDMMDL_RAIL_GetRailWork(mmdl);
    FLDMMDL_RAIL_GetDrawOffsetByDir(mmdl, (((u32)FLDMMDL_GetDirDisp(mmdl) << 16) >> 16), outOffset);
}

static inline void setVec(VecFx32 *vec, s32 x, s32 y, s32 z)
{
    vec->x = x;
    vec->y = y;
    vec->z = z;
}

static inline void setVec16(s16 *vec, s32 x, s32 y, s32 z)
{
    vec[0] = x;
    vec[1] = y;
    vec[2] = z;
}

/* Read the draw offset of the rail walker, tilted by the slope under it. */
void FLDMMDL_RAIL_GetDrawOffsetByDir(Mmdl *mmdl, u32 dir, s16 *outOffset)
{
    RailWork *railWork;
    u32 slopeKind;
    s32 sinIndex;
    s32 cos;
    s32 rotMtx[9];
    VecFx32 offsetVec;

    railWork = FLDMMDL_RAIL_GetRailWork(mmdl);
    FIELD_RAIL_WORK_GetStepVector(railWork, outOffset);
    slopeKind = FIELD_RAIL_WORK_GetLineKey(railWork);
    sinIndex = (d_021D841C[d_021D84D4[slopeKind][dir]] >> 4) * 2;
    cos = FX_SinCosTable_[sinIndex + 1];
    outOffset[1] = (s16)(((s64)cos * outOffset[1] + 0x800) >> 12);
    setVec(&offsetVec, outOffset[0], outOffset[1], outOffset[2]);
    MTX_RotY33_(rotMtx, FX_SinCosTable_[sinIndex], cos);
    MTX_MultVec33(&offsetVec, rotMtx, &offsetVec);
    VEC_Normalize(&offsetVec, &offsetVec);
    setVec16(outOffset, offsetVec.x, offsetVec.y, offsetVec.z);
}

/* Stay move type: init, move, delete, return. */
RailMoveWork *FLDMMDL_RAIL_StayInit(Mmdl *mmdl)
{
    return FLDMMDL_RAIL_InitMoveWork(mmdl, 0xc);
}

void FLDMMDL_RAIL_StayMove(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3)
{
    FLDMMDL_RAIL_StoreNowLocation(FLDMMDL_GetMoveProcWork(mmdl), mmdl);
}

int FLDMMDL_RAIL_StayDelete(Mmdl *mmdl, u32 unused1, u32 unused2, u32 unused3)
{
    return FLDMMDL_RAIL_ReleaseRailWork(FLDMMDL_GetMoveProcWork(mmdl), mmdl);
}

/*
 * The stay return proc is followed by twenty unlabelled tail-call thunks
 * (pool word plus `bx r3`): eleven look around inits for the kinds 0..10, then
 * the move and delete procs of the look around, the two wander inits, the
 * move and delete procs of the wander, and the shuttle init, move, delete.
 */
void FLDMMDL_RAIL_AcquireRailWorkBody(Mmdl *mmdl)
{
    FLDMMDL_RAIL_AcquireRailWork(FLDMMDL_GetMoveProcWork(mmdl), mmdl);
}

void FLDMMDL_RAIL_LookAroundInitKind0(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 0); }
void FLDMMDL_RAIL_LookAroundInitKind1(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 1); }
void FLDMMDL_RAIL_LookAroundInitKind2(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 2); }
void FLDMMDL_RAIL_LookAroundInitKind3(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 3); }
void FLDMMDL_RAIL_LookAroundInitKind4(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 4); }
void FLDMMDL_RAIL_LookAroundInitKind5(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 5); }
void FLDMMDL_RAIL_LookAroundInitKind6(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 6); }
void FLDMMDL_RAIL_LookAroundInitKind7(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 7); }
void FLDMMDL_RAIL_LookAroundInitKind8(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 8); }
void FLDMMDL_RAIL_LookAroundInitKind9(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 9); }
void FLDMMDL_RAIL_LookAroundInitKind10(Mmdl *mmdl) { FLDMMDL_RAIL_LookAroundInit(mmdl, 10); }

int FLDMMDL_RAIL_LookAroundMove(Mmdl *mmdl) { return FLDMMDL_RAIL_LookAroundMoveBody(mmdl); }
int FLDMMDL_RAIL_LookAroundDelete(Mmdl *mmdl) { return FLDMMDL_RAIL_LookAroundDeleteBody(mmdl); }

void FLDMMDL_RAIL_WanderInitKind0(Mmdl *mmdl) { FLDMMDL_RAIL_WanderInit(mmdl, 0); }
void FLDMMDL_RAIL_WanderInitKind9(Mmdl *mmdl) { FLDMMDL_RAIL_WanderInit(mmdl, 9); }

int FLDMMDL_RAIL_WanderMove(Mmdl *mmdl) { return FLDMMDL_RAIL_WanderMoveBody(mmdl); }
int FLDMMDL_RAIL_WanderDelete(Mmdl *mmdl) { return FLDMMDL_RAIL_WanderDeleteBody(mmdl); }

void FLDMMDL_RAIL_ShuttleInit(Mmdl *mmdl) { FLDMMDL_RAIL_ShuttleInitBody(mmdl); }
int FLDMMDL_RAIL_ShuttleMove(Mmdl *mmdl) { return FLDMMDL_RAIL_ShuttleMoveBody(mmdl); }
int FLDMMDL_RAIL_ShuttleDelete(Mmdl *mmdl) { return FLDMMDL_RAIL_ShuttleDeleteBody(mmdl); }

/* Model direction to rail key. */
u32 FLDMMDL_RAIL_DirToRailKey(int dir)
{
    return ZONEDATA_DirToRailKey(dir);
}

/* Rail key (2, 4, 8, 16) to model direction (0 up, 1 down, 2 left, 3 right). */
u32 FLDMMDL_RAIL_RailKeyToDir(int key)
{
    u32 dir = 1;
    switch (key) {
    case 16: dir = 0; break;
    case 4: dir = 2; break;
    case 2: dir = 3; break;
    case 8: break;
    }
    return dir;
}

/* Allocate the move work of a model and bind it to a rail walker. */
RailMoveWork *FLDMMDL_RAIL_InitMoveWork(Mmdl *mmdl, u32 size)
{
    RailLocation startLoc;
    int hasStartLoc = FLDMMDL_MOVE_GetRailMoveRequest(mmdl, &startLoc);
    RailMoveWork *work = FLDMMDL_InitMoveProcWork(mmdl, size);
    FLDMMDL_RAIL_InitRailWork(work, mmdl);
    if (hasStartLoc) {
        FLDMMDL_RAIL_SetLocation(mmdl, &startLoc);
    } else {
        MI_CpuFill8(&startLoc, 0, 8);
        FLDMMDL_RAIL_SetLocation(mmdl, &startLoc);
    }
    return work;
}

/* Is loc outside the area around the home cell the model may walk in? */
int FLDMMDL_RAIL_CheckOutsideHomeArea(Mmdl *mmdl, int homeLine, int homeWidth, RailLocation *loc)
{
    int limitWidth;
    int limitLine;
    int low;
    int high;

    limitWidth = FLDMMDL_GetMoveLimitX(mmdl);
    limitLine = FLDMMDL_GetMoveLimitZ(mmdl);
    if (limitWidth != -1) {
        low = homeWidth - limitWidth;
        high = homeWidth + limitWidth;
        if (low > loc->widthGrid || high < loc->widthGrid) {
            return 1;
        }
    }
    if (limitLine != -1) {
        high = homeLine + limitLine;
        low = homeLine - limitLine;
        if (low > loc->lineGrid || high < loc->lineGrid) {
            return 1;
        }
    }
    return 0;
}

/* Index of the first entry equal to terminator. */
int FLDMMDL_RAIL_GetTableLength(u32 *table, u32 terminator)
{
    int count;
    for (count = 0; table[count] != terminator; count++) {
    }
    return count;
}

/* Pick a random entry of a table ended by terminator. */
int FLDMMDL_RAIL_GetRandomTableEntry(u32 *table, int terminator)
{
    return *(u32 *)((u8 *)(table) + ((func_020056EC(FLDMMDL_RAIL_GetTableLength((u32 *)table, terminator)) << 2)));
}

/* Pick a random direction out of the direction list of a kind. */
u32 FLDMMDL_RAIL_GetRandomDirOfKind(u32 kind, u32 terminator)
{
    u32 *dirList = FLDMMDL_RAIL_GetDirListOfKind(kind);
    return dirList[func_020056EC(FLDMMDL_RAIL_GetTableLength(dirList, terminator))];
}

/* The direction list of a look around or wander kind. */
u32 *FLDMMDL_RAIL_GetDirListOfKind(int kind)
{
    DirListEntry *entry = d_021D84E8;
    int key = 0;
    do {
        if (key == kind) {
            return entry->dirList;
        }
        entry++;
        key = entry->kind;
    } while (key != _KIND_COUNT);
    return 0;
}

/* Get a rail walker for the model and mark the location as not set. */
int FLDMMDL_RAIL_InitRailWork(RailMoveWork *work, Mmdl *mmdl)
{
    work->railWork = FIELD_NOGRID_MAPPER_CreateRailWork(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)));
    work->location.type = _LOCATION_NOT_SET;
    return _LOCATION_NOT_SET;
}

/* Store the place the rail walker is at now. */
void FLDMMDL_RAIL_StoreNowLocation(RailMoveWork *work, Mmdl *mmdl)
{
    RailLocation nowLoc;
    FIELD_RAIL_WORK_GetLocation(work->railWork, &nowLoc);
    FLDMMDL_RAIL_StoreLocation(work, &nowLoc);
}

/* Release the rail walker. */
u32 FLDMMDL_RAIL_ReleaseRailWork(RailMoveWork *work, Mmdl *mmdl)
{
    FIELD_NOGRID_MAPPER_DeleteRailWork(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)), work->railWork);
    return (u32)FLDMMDL_ClearStatusBit(mmdl, _STATUSBIT_NO_RAIL);
}

/* Get a rail walker again and put it on the stored location. */
void FLDMMDL_RAIL_AcquireRailWork(RailMoveWork *work, Mmdl *mmdl)
{
    work->railWork = FIELD_NOGRID_MAPPER_CreateRailWork(FLDMMDL_SysGetNogridMapper(FLDMMDL_GetMmdlSys(mmdl)));
    FLDMMDL_RAIL_ApplyStoredLocation(work, mmdl);
}

/*
 * The source pointer is const: that lets mwcc load loc->lineGrid above the
 * store of loc->widthGrid.
 */
void FLDMMDL_RAIL_StoreLocation(RailMoveWork *work, const RailLocation *loc)
{
    work->location = *loc;
}

/* Put the rail walker and the model on the stored location. */
void FLDMMDL_RAIL_ApplyStoredLocation(RailMoveWork *work, Mmdl *mmdl)
{
    VecFx32 pos;
    if (work->location.type != _LOCATION_NOT_SET) {
        FIELD_RAIL_WORK_SetLocation(work->railWork, &work->location);
        FIELD_RAIL_WORK_GetPos(work->railWork, &pos);
        FLDMMDL_SetPos(mmdl, &pos);
    }
}

/* Look around init: kind selects the directions to turn to. */
void FLDMMDL_RAIL_LookAroundInit(Mmdl *mmdl, u16 kind)
{
    RailLookAroundWork *work = (RailLookAroundWork *)FLDMMDL_RAIL_InitMoveWork(mmdl, 16);
    work->waitCount = FLDMMDL_RAIL_GetRandomTableEntry(d_021D84AC, -1);
    work->kind = kind;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
}

/* Look around move: turn to a random direction of the kind after each wait. */
int FLDMMDL_RAIL_LookAroundMoveBody(Mmdl *mmdl)
{
    RailLookAroundWork *work;

    work = FLDMMDL_GetMoveProcWork(mmdl);
    work->waitCount = work->waitCount - 1;
    if (work->waitCount <= 0) {
        work->waitCount = FLDMMDL_RAIL_GetRandomTableEntry((u32 *)d_021D84AC, -1);
        FLDMMDL_SetDirDispCheckPause(mmdl, (u16)FLDMMDL_RAIL_GetRandomDirOfKind(work->kind, _DIR_LIST_END));
    }
    FLDMMDL_RAIL_StoreNowLocation(&work->base, mmdl);
}

/* Look around delete. */
int FLDMMDL_RAIL_LookAroundDeleteBody(Mmdl *mmdl)
{
    return FLDMMDL_RAIL_ReleaseRailWork(FLDMMDL_GetMoveProcWork(mmdl), mmdl);
}

/* Wander init: kind selects the directions to walk to. */
void FLDMMDL_RAIL_WanderInit(Mmdl *mmdl, u32 kind)
{
    RailWanderWork *work;
    RailLocation homeLoc;

    work = (RailWanderWork *)FLDMMDL_RAIL_InitMoveWork(mmdl, 0x10);
    FLDMMDL_RAIL_GetNextLocation(mmdl, &homeLoc);
    work->state = 0;
    work->waitCount = 0;
    work->kind = kind;
    work->homeLine = homeLoc.lineGrid;
    work->homeWidth = homeLoc.widthGrid;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
}

/* Wander move: idle, wait, then step to a random direction of the kind unless
 * the step is blocked, leaves the rail or leaves the home area. */
int FLDMMDL_RAIL_WanderMoveBody(Mmdl *mmdl)
{
    RailWanderWork *work;
    u32 dir;
    RailLocation nowLoc;
    RailLocation nextLoc;

    work = FLDMMDL_GetMoveProcWork(mmdl);
    switch (work->state) {
    case _WANDER_START:
        FLDMMDL_OffMoveBitMove(mmdl);
        FLDMMDL_OffMoveBitMoveEnd(mmdl);
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)((u32)FLDMMDL_GetDirDisp(mmdl)), (u32)_ACMD_KIND_STOP)));
        work->state++;
        break;
    case _WANDER_IDLE_ANIM:
        if (!FLDMMDL_ACMD_Update(mmdl)) {
            break;
        }
        work->waitCount = FLDMMDL_RAIL_GetRandomTableEntry((u32 *)d_021D84AC, -1);
        work->state++;
    case _WANDER_WAIT:
        work->waitCount--;
        if (work->waitCount != 0) {
            break;
        }
        work->state++;
    case _WANDER_PICK_STEP:
        dir = FLDMMDL_RAIL_GetRandomDirOfKind(work->kind, _DIR_LIST_END);
        FLDMMDL_SetDirAll(mmdl, dir);
        if (FLDMMDL_RAIL_GetHitBitsDirNoAttr(mmdl, dir)) {
            work->state = _WANDER_START;
            break;
        }
        FLDMMDL_RAIL_GetNextLocation(mmdl, &nowLoc);
        FLDMMDL_RAIL_GetLocationByDir(mmdl, (u16)dir, &nextLoc);
        if (nowLoc.railIndex != nextLoc.railIndex) {
            work->state = _WANDER_START;
            break;
        }
        if (FLDMMDL_RAIL_CheckOutsideHomeArea(mmdl, work->homeLine, work->homeWidth, &nextLoc)) {
            work->state = _WANDER_START;
            break;
        }
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u32)_ACMD_KIND_WALK)));
        FLDMMDL_OnMoveBitMove(mmdl);
        work->state++;
    case _WANDER_STEP_ANIM:
        if (FLDMMDL_ACMD_Update(mmdl)) {
            FLDMMDL_OffMoveBitMove(mmdl);
            work->state = _WANDER_START;
        }
        break;
    }
    FLDMMDL_RAIL_StoreNowLocation(&work->base, mmdl);
}

/* Wander delete. */
int FLDMMDL_RAIL_WanderDeleteBody(Mmdl *mmdl)
{
    return FLDMMDL_RAIL_ReleaseRailWork(FLDMMDL_GetMoveProcWork(mmdl), mmdl);
}

/* Shuttle init: the home cell is where the model starts. */
void FLDMMDL_RAIL_ShuttleInitBody(Mmdl *mmdl)
{
    RailShuttleWork *work = (RailShuttleWork *)FLDMMDL_RAIL_InitMoveWork(mmdl, 16);
    RailLocation homeLoc;
    FLDMMDL_RAIL_GetNextLocation(mmdl, &homeLoc);
    work->state = 0;
    work->returning = 0;
    work->homeLine = homeLoc.lineGrid;
    work->homeWidth = homeLoc.widthGrid;
    FLDMMDL_SetDrawStatus(mmdl, 0);
    FLDMMDL_OffMoveBitMove(mmdl);
}

/* Shuttle move: walk in the move direction; when blocked, leaves the rail or
 * leaves the area, turn around and walk back to the home cell, then turn
 * around again. */
int FLDMMDL_RAIL_ShuttleMoveBody(Mmdl *mmdl)
{
    RailShuttleWork *work;
    u32 hitBits;
    u32 dir;
    u32 typeChanged;
    int outOfArea;
    RailLocation nowLoc;
    RailLocation nextLoc;

    work = FLDMMDL_GetMoveProcWork(mmdl);
    switch (work->state) {
    case _SHUTTLE_START:
        dir = FLDMMDL_GetDirHeader(mmdl);
        if (work->returning == 1) {
            dir = (u32)FLDMMDL_MOVE_GetDirTableValue((u16)dir);
        }
        FLDMMDL_SetDirAll(mmdl, (u16)dir);
        work->state = _SHUTTLE_CHECK;
    case _SHUTTLE_CHECK:
        FLDMMDL_RAIL_GetNextLocation(mmdl, &nowLoc);
        if (work->returning != 0 && work->homeLine == nowLoc.lineGrid && work->homeWidth == nowLoc.widthGrid) {
            FLDMMDL_SetDirAll(mmdl, (u16)((u32)FLDMMDL_MOVE_GetDirTableValue((u16)FLDMMDL_GetDirMove(mmdl))));
            work->returning = 0;
        }
        typeChanged = 0;
        dir = FLDMMDL_GetDirMove(mmdl);
        hitBits = (u32)FLDMMDL_RAIL_GetHitBitsDirNoAttr(mmdl, (u16)dir);
        FLDMMDL_RAIL_GetLocationByDir(mmdl, (u16)dir, &nextLoc);
        outOfArea = FLDMMDL_RAIL_CheckOutsideHomeArea(mmdl, work->homeLine, work->homeWidth, &nextLoc);
        if (nowLoc.railIndex != nextLoc.railIndex) {
            typeChanged = 1;
        }
        if ((hitBits & 1) || outOfArea || typeChanged) {
            work->returning = 1;
            dir = (u32)FLDMMDL_MOVE_GetDirTableValue((u16)dir);
            hitBits = (u32)FLDMMDL_RAIL_GetHitBitsDirNoAttr(mmdl, (u16)dir);
            FLDMMDL_RAIL_GetLocationByDir(mmdl, (u16)dir, &nextLoc);
        }
        FLDMMDL_SetLocalAcmd(mmdl, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)dir, (u16)(hitBits == 0 ? _ACMD_KIND_WALK : _ACMD_KIND_STAY_WALK))));
        FLDMMDL_OnMoveBitMove(mmdl);
        work->state = _SHUTTLE_STEP_ANIM;
        break;
    case _SHUTTLE_STEP_ANIM:
        if (FLDMMDL_ACMD_Update(mmdl) == 1) {
            FLDMMDL_OffMoveBitMove(mmdl);
            work->state = _SHUTTLE_START;
        }
        break;
    }
    FLDMMDL_RAIL_StoreNowLocation(&work->base, mmdl);
}

/* Shuttle delete. */
int FLDMMDL_RAIL_ShuttleDeleteBody(Mmdl *mmdl)
{
    return FLDMMDL_RAIL_ReleaseRailWork(FLDMMDL_GetMoveProcWork(mmdl), mmdl);
}
