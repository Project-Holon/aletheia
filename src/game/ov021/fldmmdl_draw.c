/*
 * file:     fldmmdl_draw.c
 * unit:     yes
 * function: FLDMMDL_DRAW_GetBlactAnime, FLDMMDL_DRAW_SetBlactAnime, FLDMMDL_DRAW_InitDirAnime, FLDMMDL_DRAW_DeleteDirAnime, FLDMMDL_DRAW_DrawDirAnime, FLDMMDL_DRAW_GetBlactIdDirAnime, FLDMMDL_DRAW_DrawDirAnimeMoving, FLDMMDL_DRAW_InitDirAnimeB, FLDMMDL_DRAW_DeleteDirAnimeB, FLDMMDL_DRAW_DrawDirAnimeB, FLDMMDL_DRAW_DrawDirAnimeSized, FLDMMDL_DRAW_DrawWalkAnime, FLDMMDL_DRAW_DrawWalkAnimeB, FLDMMDL_DRAW_GetBlactIdWalkAnime, FLDMMDL_DRAW_DrawTwoFrame, FLDMMDL_DRAW_DrawThreeFrame, FLDMMDL_DRAW_SetState, FLDMMDL_DRAW_RotateByCamera, FLDMMDL_DRAW_GetFrameOffsetZero, FLDMMDL_DRAW_DrawBillboardOffset, FLDMMDL_DRAW_DrawStatic, FLDMMDL_DRAW_GetFrameGroup, FLDMMDL_DRAW_DrawPositionOnly, FLDMMDL_DRAW_InitFixedState, FLDMMDL_DRAW_DeleteFixedState, FLDMMDL_DRAW_DrawWalking, FLDMMDL_DRAW_UpdateWalkOffset, FLDMMDL_DRAW_ShiftOffsetByDir, FLDMMDL_DRAW_CheckStepFrame, FLDMMDL_DRAW_GetBlactIdFixedState, FLDMMDL_DRAW_InitDirAnimeC, FLDMMDL_DRAW_DeleteDirAnimeC, FLDMMDL_DRAW_DrawMultiPattern, FLDMMDL_DRAW_GetBlactIdMultiPattern, FLDMMDL_DRAW_GetBlactAnimeTypeA, FLDMMDL_DRAW_GetBlactAnimeTypeB, FLDMMDL_DRAW_DrawTwoPattern, FLDMMDL_DRAW_DrawThreePattern, FLDMMDL_DRAW_CheckBlactReady, FLDMMDL_DRAW_ResetBlactAnime, FLDMMDL_DRAW_InitDirState, FLDMMDL_DRAW_UpdateDirAnime, FLDMMDL_DRAW_AddHeightOffset, FLDMMDL_DRAW_GetDirIndex, FLDMMDL_DRAW_UpdateBlactFlags, FLDMMDL_DRAW_InitBlactId, FLDMMDL_DRAW_DrawEffect, FLDMMDL_DRAW_DeleteEffect, FLDMMDL_DRAW_DeleteEffectAlias, FLDMMDL_DRAW_InitEffectAlias
 * address:  0x0219F058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_fog.c (CL110): ends at the field_fog.c __FILE__ anchor function 0x021A0104.
 *
 * Unanchored original between field_rail_loader.c (0x0219EF44) and
 * field_fog.c (0x021A0104): moving-model draw procedures (init, draw,
 * delete, push, pop, get-actor-id) over the fldmmdl_g3dobj and blact
 * objects. File name inferred from the fldmmdl module prefix.
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetDrawProcWork  0x0216D6F0  thumb  ov010
 *   FLDMMDL_GetBlActCont  0x0216D910  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   BILLBOARD_ACT_GetEntryList  0x02050848  arm
 *   BILLBOARD_ACT_GetEntryCursor  0x02050880  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryCursor  0x0205085C  arm
 *   FLDMMDL_InitDrawProcWork  0x0216D6D8  thumb  ov010
 *   FLDMMDL_BLACT_AddActorMmdlOrReserve  0x0219C814  thumb  ov021
 *   FLDMMDL_BLACT_DeleteActorMmdl  0x0219C8D4  thumb  ov021
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_SetElemPos  0x0204F638  arm
 *   FLDMMDL_GetDrawStatus  0x0216D678  thumb  ov010
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_0207BCA0  0x0207BCA0  arm
 *   func_02082B60  0x02082B60  arm
 *   func_0207B0A4  0x0207B0A4  arm
 *   func_0207B51C  0x0207B51C  arm
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetFieldMap  0x0216D534  thumb  ov010
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   func_0207C9D0  0x0207C9D0  arm
 *   gMmdlDrawBillboardShift     0x021D854C  data  ov021  a4
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetDrawOffset  0x0216D8B0  thumb  ov010
 *   FLDMMDL_ACMD_CheckAnimePaused  0x02197C9C  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetZoneId  0x0216D590  thumb  ov010
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   FIELDMAP_IsFieldPlayerCreated  0x02188CBC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetStepKind  0x021A3080  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   BILLBOARD_ACT_GetEntryLastCommand  0x020508EC  arm
 *   FLDMMDL_CallDrawGetProc  0x0216D7A8  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   gMmdlDrawRestFrames  0x021D8548  data  ov021  a1
 *   FIELDMAP_GetCameraPitchScale  0x02189A78  thumb  ov021
 *   FLDMMDL_SysGetAreaId  0x0216D538  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_GetDirByAngle  0x0219D738  thumb  ov021
 *   FLDMMDL_MOVE_GetRelativeDirCode  0x021642D4  thumb  ov010
 *   BILLBOARD_ACT_SetEntryFlags  0x020507A0  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FLDMMDL_CheckStatusBitVanish  0x0216DAB4  thumb  ov010
 *   FLDMMDL_BLACT_GetEntryHookFlag  0x0219C648  thumb  ov021
 *   FLDMMDL_G3DOBJ_AddObj  0x0219D634  thumb  ov021
 *   FLDMMDL_G3DOBJ_GetObjCtrl  0x0219D49C  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectTrans  0x021C6664  thumb  ov021
 *   FIELD_G3DOBJ_SetObjectHidden  0x021C6678  thumb  ov021
 *   FIELD_G3DOBJ_LoopAnimeFrame  0x021C66EC  thumb  ov021
 *   FLDMMDL_G3DOBJ_DelObj  0x0219D680  thumb  ov021
 */
#include "fldmmdl_blact_types.h"

struct FieldMap;
struct FieldCamera;
struct G3dCamera;
struct FieldG3dObjCtrl;

/* The four bytes at MmdlDrawWork.dirAnime: direction and animation state of
 * a billboard model. dir is 8 until the first update. */
typedef struct MmdlDirAnimeState {
    u8 dir;   /* last facing, 8 = none */
    u8 anime; /* last animation index */
    u8 frame; /* animation frame group while a turn blends (see UpdateDirAnime) */
    u8 wait;  /* one-frame delay before a turn into a still pose */
} MmdlDirAnimeState;

/* Draw procedure work of a moving model (8 bytes, 12 for the walk variant),
 * allocated with FLDMMDL_InitDrawProcWork and read back with FLDMMDL_GetDrawProcWork. */
typedef struct MmdlDrawWork {
    u16 blactId;                 /* billboard actor slot, 0xFFFF = none */
    u8 state;
    u8 counter;
    MmdlDirAnimeState dirAnime;  /* the walking variant keeps other bytes here */
    u32 extra;
} MmdlDrawWork;

/* Frame groups to rest in after a turn (gMmdlDrawRestFrames). */
typedef struct MmdlRestFrames {
    u8 frames[4];
} MmdlRestFrames;

extern MmdlObjCodeParam *FLDMMDL_GetObjCodeParam(Mmdl *mmdl);
extern MmdlDrawWork *FLDMMDL_GetDrawProcWork(Mmdl *mmdl);
extern BlactSys *FLDMMDL_GetBlActCont(Mmdl *mmdl);
extern struct BbActSys *FLDMMDL_BLACT_GetBbActSys(BlactSys *cont);
extern u16 BILLBOARD_ACT_GetEntryList(struct BbActSys *sys, int entryIndex);
extern u16 BILLBOARD_ACT_GetEntryCursor(struct BbActSys *sys, int entryIndex);
extern void BILLBOARD_ACT_SetEntryList(struct BbActSys *sys, int entryIndex, u32 listIndex);
extern void BILLBOARD_ACT_SetEntryCursor(struct BbActSys *sys, int entryIndex, u32 cursor);
extern void *FLDMMDL_InitDrawProcWork(Mmdl *mmdl, int size);
extern int FLDMMDL_BLACT_AddActorMmdlOrReserve(Mmdl *mmdl, u16 *outBlactId);
extern void FLDMMDL_BLACT_DeleteActorMmdl(Mmdl *mmdl, u32 blactId);
extern void FLDMMDL_ACMD_GetDrawPos(Mmdl *mmdl, VecFx32 *out);
extern struct BbBoard *BILLBOARD_ACT_GetBoard(struct BbActSys *sys);
extern void BILLBOARD_SetElemPos(struct BbBoard *board, int elem, VecFx32 *pos);
extern u16 FLDMMDL_GetDrawStatus(Mmdl *mmdl);
extern u16 FLDMMDL_GetObjCode(Mmdl *mmdl);
extern void func_02048AE8(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B0C(struct G3dCamera *camera, VecFx32 *out);
extern void func_02048B30(struct G3dCamera *camera, VecFx32 *out);
extern void func_0207BCA0(VecFx32 *camPos, VecFx32 *camUp, VecFx32 *camTarget, s32 *outMtx43);
extern void func_02082B60(s32 *mtx43, s32 *outMtx33);
extern void func_0207B0A4(s32 *mtx33, s32 *outMtx33);
extern void func_0207B51C(VecFx32 *vec, s32 *mtx33, VecFx32 *out);
extern MmdlSys *FLDMMDL_GetMmdlSys(Mmdl *mmdl);
extern struct FieldMap *FLDMMDL_SysGetFieldMap(MmdlSys *sys);
extern struct FieldCamera *FIELDMAP_GetCamera(struct FieldMap *fieldMap);
extern struct G3dCamera *FIELD_CAMERA_GetG3dCamera(struct FieldCamera *camera);
extern void func_0207C9D0(VecFx32 *a, VecFx32 *b, VecFx32 *out);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern void FLDMMDL_GetDrawOffset(Mmdl *mmdl, VecFx32 *out);
extern s32 FLDMMDL_ACMD_CheckAnimePaused(Mmdl *mmdl);
extern int FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern u16 FLDMMDL_GetZoneId(Mmdl *mmdl);
extern u16 FLDMMDL_GetObjId(Mmdl *mmdl);
extern int FIELDMAP_IsFieldPlayerCreated(struct FieldMap *fieldMap);
extern void *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern u32 FIELD_PLAYER_GetStepKind(void *obj);
extern void FLDMMDL_SetDrawOffset(Mmdl *mmdl, VecFx32 *offset);
extern u32 ZONEDATA_IsZoneGroup118To120(u32 zoneId);
extern int FLDMMDL_CallDrawGetProc(Mmdl *mmdl, unsigned int kind);
extern u32 BILLBOARD_ACT_GetEntryLastCommand(struct BbActSys *sys, int entryIndex, u16 *outLastCommand);
extern u32 MI_CpuFill8(void *p, u32 value, u32 size);
extern int FIELDMAP_GetCameraPitchScale(struct FieldMap *fieldMap);
extern u32 FLDMMDL_SysGetAreaId(MmdlSys *sys);
extern int FLDMMDL_CheckStatusBit(Mmdl *mmdl, int bits);
extern u32 FLDMMDL_RAIL_MOVE_GetDirByAngle(Mmdl *mmdl, int angle);
extern u8 FLDMMDL_MOVE_GetRelativeDirCode(int tableIndex, int offset);
extern int FLDMMDL_BLACT_GetEntryHookFlag(Mmdl *mmdl);
extern int FLDMMDL_CheckStatusBitVanish(Mmdl *mmdl);
extern void BILLBOARD_ACT_SetEntryEnabled(struct BbActSys *sys, int entryIndex, u32 enabled);
extern int BILLBOARD_ACT_SetEntryFlags(struct BbActSys *sys, int entryIndex, u32 flags);
extern u32 FLDMMDL_G3DOBJ_AddObj(Mmdl *mmdl);
extern struct FieldG3dObjCtrl *FLDMMDL_G3DOBJ_GetObjCtrl(Mmdl *mmdl);
extern void FIELD_G3DOBJ_SetObjectTrans(struct FieldG3dObjCtrl *ctrl, int objIdx, VecFx32 *pos);
extern void FIELD_G3DOBJ_SetObjectHidden(struct FieldG3dObjCtrl *ctrl, int objIdx, int hidden);
extern int FIELD_G3DOBJ_LoopAnimeFrame(struct FieldG3dObjCtrl *ctrl, int objIdx, int speed);
extern void FLDMMDL_G3DOBJ_DelObj(Mmdl *mmdl, u32 objIdx);

void FLDMMDL_DRAW_RotateByCamera(struct G3dCamera *camera, VecFx32 *vec, VecFx32 *out);
int FLDMMDL_DRAW_GetFrameOffsetZero(Mmdl *mmdl, u32 listIndex, u32 cursor, VecFx32 *out);
void FLDMMDL_DRAW_UpdateWalkOffset(Mmdl *mmdl, MmdlDrawWork *work, u8 dir);
void FLDMMDL_DRAW_ShiftOffsetByDir(Mmdl *mmdl, u32 dir, MmdlObjCodeParam *param, VecFx32 *offset);
int FLDMMDL_DRAW_CheckStepFrame(MmdlDrawWork *work, int dir, MmdlObjCodeParam *param);
int FLDMMDL_DRAW_InitDirState(MmdlDirAnimeState *state);
void FLDMMDL_DRAW_UpdateDirAnime(MmdlDirAnimeState *state, Mmdl *mmdl, struct BbActSys *bbActSys, u16 blactId);
void FLDMMDL_DRAW_AddHeightOffset(Mmdl *mmdl, VecFx32 *pos);
u32 FLDMMDL_DRAW_GetDirIndex(Mmdl *mmdl);
void FLDMMDL_DRAW_UpdateBlactFlags(Mmdl *mmdl, struct BbActSys *bbActSys, u32 blactId, u32 isUpdated, u32 checkMode);
void FLDMMDL_DRAW_InitBlactId(Mmdl *mmdl);
void FLDMMDL_DRAW_DeleteEffect(Mmdl *mmdl);
extern const VecFx32 gMmdlDrawBillboardShift;
extern const MmdlRestFrames gMmdlDrawRestFrames;

/* Reads the animation list index and cursor of the billboard actor of a model
 * (0 and 0 when the model is not a billboard or has no actor). */
void FLDMMDL_DRAW_GetBlactAnime(Mmdl *mmdl, u16 *outAnime, u16 *outFrame)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    if (FLDMMDL_GetObjCodeParam(mmdl)->drawType == 1) {
        work = FLDMMDL_GetDrawProcWork(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
            *outAnime = BILLBOARD_ACT_GetEntryList(bbActSys, work->blactId);
            *outFrame = BILLBOARD_ACT_GetEntryCursor(bbActSys, work->blactId);
        } else {
            *outAnime = 0;
            *outFrame = 0;
        }
    } else {
        *outAnime = 0;
        *outFrame = 0;
    }
}

void FLDMMDL_DRAW_SetBlactAnime(Mmdl *mmdl, u32 listIndex, u32 cursor)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    if (FLDMMDL_GetObjCodeParam(mmdl)->drawType == 1) {
        work = FLDMMDL_GetDrawProcWork(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, listIndex);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, cursor);
        }
    }
}

/* Draw procedure init: reserves the work and registers the billboard actor. */
void FLDMMDL_DRAW_InitDirAnime(Mmdl *mmdl)
{
    MmdlDrawWork *work = FLDMMDL_InitDrawProcWork(mmdl, 8);
    FLDMMDL_DRAW_InitDirState(&work->dirAnime);
    FLDMMDL_BLACT_AddActorMmdlOrReserve(mmdl, &work->blactId);
}

/* Draw procedure remove: releases the billboard actor. */
void FLDMMDL_DRAW_DeleteDirAnime(Mmdl *mmdl, u32 kind)
{
    FLDMMDL_BLACT_DeleteActorMmdl(mmdl, FLDMMDL_GetDrawProcWork(mmdl)->blactId);
}

/* Draw procedure draw: direction and animation state, then the position. */
void FLDMMDL_DRAW_DrawDirAnime(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        FLDMMDL_DRAW_UpdateDirAnime(&work->dirAnime, mmdl, bbActSys, work->blactId);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Draw procedure getParam: the billboard actor id. */
int FLDMMDL_DRAW_GetBlactIdDirAnime(Mmdl *mmdl, u32 kind)
{
    return FLDMMDL_GetDrawProcWork(mmdl)->blactId;
}

void FLDMMDL_DRAW_DrawDirAnimeMoving(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 isUpdated;
    struct BbActSys *bbActSys;
    u32 dirIndex;
    u32 anime;
    isUpdated = 0;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (work->dirAnime.dir != dirIndex) {
            work->dirAnime.dir = dirIndex;
            work->dirAnime.anime = anime;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, dirIndex);
            isUpdated = 1;
        } else if (work->dirAnime.anime != anime) {
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, dirIndex);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, isUpdated);
            work->dirAnime.anime = anime;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

void FLDMMDL_DRAW_InitDirAnimeB(Mmdl *mmdl)
{
    MmdlDrawWork *work = FLDMMDL_InitDrawProcWork(mmdl, 8);
    FLDMMDL_DRAW_InitDirState(&work->dirAnime);
    FLDMMDL_BLACT_AddActorMmdlOrReserve(mmdl, &work->blactId);
}

void FLDMMDL_DRAW_DeleteDirAnimeB(Mmdl *mmdl, u32 kind)
{
    FLDMMDL_BLACT_DeleteActorMmdl(mmdl, FLDMMDL_GetDrawProcWork(mmdl)->blactId);
}

void FLDMMDL_DRAW_DrawDirAnimeB(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        FLDMMDL_DRAW_UpdateDirAnime(&work->dirAnime, mmdl, bbActSys, work->blactId);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Direction frames at an offset that depends on the draw procedure number. */
void FLDMMDL_DRAW_DrawDirAnimeSized(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 isUpdated;
    struct BbActSys *bbActSys;
    u32 isSpecialCode;
    u32 dirIndex;
    u32 frameBase;
    u32 frame;
    isUpdated = 0;
    isSpecialCode = 0;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
        if (FLDMMDL_GetObjCode(mmdl) == 0xCC) {
            isSpecialCode = 1;
        }
        frameBase = FLDMMDL_GetObjCodeParam(mmdl)->drawProcNo;
        if (frameBase == 0xF) {
            frameBase = 4;
        } else if (frameBase == 5) {
            frameBase = 8;
        } else {
            frameBase = 0x10;
        }
        frame = (u16)(frameBase + dirIndex);
        if (work->dirAnime.dir != dirIndex) {
            work->dirAnime.dir = dirIndex;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, frame);
            isUpdated = 1;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, isSpecialCode);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Walk animations (anime 10 and up) use list index anime + 30; lower ones use the direction state machine. */
void FLDMMDL_DRAW_DrawWalkAnime(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 anime;
    u32 dirIndex;
    u8 isUpdated;
    VecFx32 drawPos;

    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (anime >= 10) {
            isUpdated = 0;
            dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
            if (anime != work->dirAnime.anime) {
                isUpdated = 1;
                work->dirAnime.dir = dirIndex;
                work->dirAnime.anime = anime;
                work->dirAnime.frame = 0;
                BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, (u16)(anime + 30));
            }
            FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, 0);
        } else {
            FLDMMDL_DRAW_UpdateDirAnime(&work->dirAnime, mmdl, bbActSys, work->blactId);
        }
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Like FLDMMDL_DRAW_DrawWalkAnime, but the update flag is always set. */
void FLDMMDL_DRAW_DrawWalkAnimeB(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 anime;
    u32 dirIndex;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (anime >= 10) {
            dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
            if (anime != work->dirAnime.anime) {
                work->dirAnime.dir = dirIndex;
                work->dirAnime.anime = anime;
                work->dirAnime.frame = 0;
                BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, (u16)(anime + 0x1e));
            }
            FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, 1, 0);
        } else {
            FLDMMDL_DRAW_UpdateDirAnime(&work->dirAnime, mmdl, bbActSys, work->blactId);
        }
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

int FLDMMDL_DRAW_GetBlactIdWalkAnime(Mmdl *mmdl, u32 kind)
{
    return FLDMMDL_GetDrawProcWork(mmdl)->blactId;
}

/* Two-frame model: anime 0 or 1 selects the list index; larger values fall back to 0. */
void FLDMMDL_DRAW_DrawTwoFrame(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 anime;
    struct BbActSys *bbActSys;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (work->dirAnime.anime >= 2) {
            work->dirAnime.anime = 0;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, work->dirAnime.anime);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
        }
        if (anime < 2 && work->dirAnime.anime != anime) {
            work->dirAnime.anime = anime;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, work->dirAnime.anime);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, 0, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Three-frame model: same as FLDMMDL_DRAW_DrawTwoFrame with anime 0 to 2. */
void FLDMMDL_DRAW_DrawThreeFrame(Mmdl *mmdl)
{
    VecFx32 drawPos;
    MmdlDrawWork *work;
    u32 anime;
    struct BbActSys *bbActSys;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (work->dirAnime.anime >= 3) {
            work->dirAnime.anime = 0;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, work->dirAnime.anime);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
        }
        if (anime < 3 && work->dirAnime.anime != anime) {
            work->dirAnime.anime = anime;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, work->dirAnime.anime);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, 0, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

void FLDMMDL_DRAW_SetState(Mmdl *mmdl, int state)
{
    FLDMMDL_GetDrawProcWork(mmdl)->state = state;
}

/* Rotates vec by the inverse of the view rotation of the camera, into out. */
void FLDMMDL_DRAW_RotateByCamera(struct G3dCamera *camera, VecFx32 *vec, VecFx32 *out)
{
    VecFx32 camPos;
    VecFx32 camUp;
    VecFx32 camTarget;
    s32 viewMtx43[12];
    s32 viewMtx33[9];
    func_02048AE8(camera, &camPos);
    func_02048B0C(camera, &camUp);
    func_02048B30(camera, &camTarget);
    func_0207BCA0(&camPos, &camUp, &camTarget, viewMtx43);
    func_02082B60(viewMtx43, viewMtx33);
    func_0207B0A4(viewMtx33, viewMtx33);
    func_0207B51C(vec, viewMtx33, out);
}

/* Draw procedure frame offset: none. */
int FLDMMDL_DRAW_GetFrameOffsetZero(Mmdl *mmdl, u32 listIndex, u32 cursor, VecFx32 *out)
{
    out->x = 0;
    out->y = 0;
    out->z = 0;
    return 0;
}

/* Billboard with an offset per frame: rotated by the camera (state 0) or fixed. */
void FLDMMDL_DRAW_DrawBillboardOffset(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 dirIndex;
    u32 anime;
    u16 listIndex;
    VecFx32 pos;
    VecFx32 frameOffset;
    VecFx32 rotated;
    u32 isUpdated;
    u32 curListIndex;

    isUpdated = 0;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId == 0xFFFF) {
        return;
    }
    bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
    dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
    anime = FLDMMDL_GetDrawStatus(mmdl);
    listIndex = dirIndex + anime * 4;
    if (dirIndex != work->dirAnime.dir || work->dirAnime.anime != anime) {
        work->dirAnime.dir = dirIndex;
        isUpdated = 1;
        work->dirAnime.anime = anime;
        BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, listIndex);
        BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
    }
    FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, 1);
    FLDMMDL_ACMD_GetDrawPos(mmdl, &pos);
    FLDMMDL_DRAW_AddHeightOffset(mmdl, &pos);
    curListIndex = BILLBOARD_ACT_GetEntryList(bbActSys, work->blactId);
    FLDMMDL_DRAW_GetFrameOffsetZero(mmdl, curListIndex, BILLBOARD_ACT_GetEntryCursor(bbActSys, work->blactId), &frameOffset);
    pos.x += frameOffset.x;
    pos.y += frameOffset.y;
    pos.z += frameOffset.z;
    if (work->state == 0) {
        rotated = gMmdlDrawBillboardShift;
        FLDMMDL_DRAW_RotateByCamera(FIELD_CAMERA_GetG3dCamera(FIELDMAP_GetCamera(FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys(mmdl)))), &rotated, &rotated);
        func_0207C9D0(&pos, &rotated, &pos);
    } else {
        pos.y -= 0xC000;
        pos.z += 0x8000;
    }
    BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &pos);
}

/* Static model: direction frame only. */
void FLDMMDL_DRAW_DrawStatic(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;
    u32 dirIndex;

    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
        if (work->dirAnime.dir != dirIndex) {
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, dirIndex);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
            work->dirAnime.dir = dirIndex;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, 0, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Maps an animation command index to one of 13 groups; rewinds the cursor when the actor is in another group. */
int FLDMMDL_DRAW_GetFrameGroup(Mmdl *mmdl, u32 command)
{
    u32 group;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;
    u32 curGroup;

    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId == 0xFFFF) {
        return 0;
    }
    if (command < 0x18) {
        if (command < 6) group = 0;
        else if (command < 0xC) group = 1;
        else if (command < 0x12) group = 2;
        else group = 3;
    } else if (command < 0x28) {
        if (command < 0x1C) group = 4;
        else if (command < 0x20) group = 5;
        else if (command < 0x24) group = 6;
        else group = 7;
    } else if (command < 0x30) {
        if (command < 0x2A) group = 8;
        else if (command < 0x2C) group = 9;
        else if (command < 0x2E) group = 10;
        else group = 11;
    } else {
        group = 12;
    }
    bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
    curGroup = BILLBOARD_ACT_GetEntryCursor(bbActSys, work->blactId);
    if (curGroup != group) {
        BILLBOARD_ACT_SetEntryCursor(bbActSys, work->blactId, 0);
    }
    return 1;
}

/* Position update only, no animation change. */
void FLDMMDL_DRAW_DrawPositionOnly(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;

    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, 0, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

void FLDMMDL_DRAW_InitFixedState(Mmdl *mmdl)
{
    MmdlDrawWork *work = FLDMMDL_InitDrawProcWork(mmdl, 8);
    work->state = 9;
    FLDMMDL_BLACT_AddActorMmdlOrReserve(mmdl, &work->blactId);
}

void FLDMMDL_DRAW_DeleteFixedState(Mmdl *mmdl, u32 kind)
{
    FLDMMDL_BLACT_DeleteActorMmdl(mmdl, FLDMMDL_GetDrawProcWork(mmdl)->blactId);
}

/* Walking model: the state follows the direction; FLDMMDL_DRAW_UpdateWalkOffset moves the draw offset. */
void FLDMMDL_DRAW_DrawWalking(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    u8 isUpdated;
    struct BbActSys *bbActSys;
    u32 dir;
    VecFx32 drawPos;
    s32 offsetBuf[3]; /* read through a VecFx32 pointer: the bytes need the address in a register */

    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        isUpdated = 0;
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        dir = FLDMMDL_GetDirDisp(mmdl);
        if (dir != work->state) {
            isUpdated = 1;
            work->state = dir;
            work->counter = 0;
            work->extra = 0;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, work->state);
            {
                VecFx32 *clear = (VecFx32 *)offsetBuf;
                clear->x = 0;
                clear->y = 0;
                clear->z = 0;
                FLDMMDL_GetDrawOffset(mmdl, clear);
            }
        }
        FLDMMDL_DRAW_UpdateWalkOffset(mmdl, work, dir);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, 0);
    }
}

/* Bobbing and sideways offset of a walking model, written to the draw offset of the model. */
void FLDMMDL_DRAW_UpdateWalkOffset(Mmdl *mmdl, MmdlDrawWork *work, u8 dir)
{
    VecFx32 offset;
    VecFx32 curOffset;
    struct FieldMap *fieldMap;
    s32 isAnimePaused;
    u32 zoneId;
    s32 gridX;
    MmdlObjCodeParam *param;
    int isHidden;
    int canBob;
    int isPlayer;
    u32 objId;
    u8 gridMod;
    void *mapObj;

    canBob = 1;
    param = FLDMMDL_GetObjCodeParam(mmdl);
    isPlayer = 0;
    offset.x = 0;
    offset.y = 0;
    offset.z = 0;
    isAnimePaused = FLDMMDL_ACMD_CheckAnimePaused(mmdl);
    FLDMMDL_GetDrawOffset(mmdl, &curOffset);
    gridX = FLDMMDL_GetGridNowX(mmdl);
    zoneId = FLDMMDL_GetZoneId(mmdl);
    objId = FLDMMDL_GetObjId(mmdl);
    if (objId == 0xff)
        isPlayer = canBob;
    isHidden = (objId == 0xfc) ? 1 : 0;
    if (isPlayer != 0) {
        fieldMap = FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys(mmdl));
        if (FIELDMAP_IsFieldPlayerCreated(fieldMap) != 0 && (mapObj = FIELDMAP_GetFieldPlayer(fieldMap)) != 0) {
            canBob = FIELD_PLAYER_GetStepKind(mapObj) != 0;
        }
    }
    if (isAnimePaused != 0 || (curOffset.y > 0x1800 && param->drawProcNo != 11)) {
        offset.y = curOffset.y;
    } else if (FLDMMDL_DRAW_CheckStepFrame(work, dir, param) == 0 && canBob != 0) {
        offset.y = offset.y + 0x1800;
    }
    if (ZONEDATA_IsZoneGroup118To120(zoneId) != 0 && isPlayer == 0) {
        gridMod = gridX % 3;
        if (gridMod == 0)
            offset.z = offset.z - 0x219a;
        else if (gridMod == 2)
            offset.z = offset.z + 0x219a;
        offset.z = offset.z - 0x2000;
    }
    FLDMMDL_DRAW_ShiftOffsetByDir(mmdl, dir, param, &offset);
    if (isHidden) {
        offset.x = 0;
        offset.y = 0;
        offset.z = 0;
    }
    FLDMMDL_SetDrawOffset(mmdl, &offset);
    work->counter++;
}

/* Shifts the x offset by 0x2000 for directions 2 and 3 of a model with size class 0. */
void FLDMMDL_DRAW_ShiftOffsetByDir(Mmdl *mmdl, u32 dir, MmdlObjCodeParam *param, VecFx32 *offset)
{
    if (param->mdlSize == 0) {
        switch (dir) {
        case 2:
            offset->x -= 0x2000;
            break;
        case 3:
            offset->x += 0x2000;
            break;
        }
    }
}

/* Advances the 20-frame step counter; true while the model is in a lifted step phase. */
int FLDMMDL_DRAW_CheckStepFrame(MmdlDrawWork *work, int dir, MmdlObjCodeParam *param)
{
    int phase = work->counter % 20;
    u8 drawProcNo = param->drawProcNo;
    work->counter = phase;
    if (drawProcNo == 11) {
        if (dir == 1) {
            if (phase < 5 || phase >= 15)
                return 1;
        } else {
            if (phase < 10)
                return 1;
        }
    } else {
        if ((phase >= 5 && phase < 10) || phase >= 15)
            return 1;
    }
    return 0;
}

int FLDMMDL_DRAW_GetBlactIdFixedState(Mmdl *mmdl, u32 kind)
{
    return FLDMMDL_GetDrawProcWork(mmdl)->blactId;
}

void FLDMMDL_DRAW_InitDirAnimeC(Mmdl *mmdl)
{
    MmdlDrawWork *work = FLDMMDL_InitDrawProcWork(mmdl, 8);
    FLDMMDL_DRAW_InitDirState(&work->dirAnime);
    FLDMMDL_BLACT_AddActorMmdlOrReserve(mmdl, &work->blactId);
}

void FLDMMDL_DRAW_DeleteDirAnimeC(Mmdl *mmdl, u32 kind)
{
    FLDMMDL_BLACT_DeleteActorMmdl(mmdl, FLDMMDL_GetDrawProcWork(mmdl)->blactId);
}

/* Models with several animation patterns, chosen by object code (0xD3 to 0xD6, 0x79). */
void FLDMMDL_DRAW_DrawMultiPattern(Mmdl *mmdl)
{
    VecFx32 drawPos;
    u32 isUpdated;
    struct BbActSys *bbActSys;
    u32 anime;
    MmdlDrawWork *work;
    u32 objCode;
    u32 dirIndex;
    u32 frame;

    isUpdated = 0;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId == 0xFFFF)
        return;
    bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
    objCode = FLDMMDL_GetObjCode(mmdl);
    anime = FLDMMDL_GetDrawStatus(mmdl);
    if (objCode == 0xd3 || objCode == 0xd5 || objCode == 0x79) {
        frame = 0;
        if (anime == work->dirAnime.anime)
            goto draw;
        switch (anime) {
        case 10:
            frame = 1;
            break;
        case 11:
            frame = 2;
            break;
        case 12:
            frame = 3;
            break;
        }
        work->dirAnime.anime = anime;
        BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, frame);
        isUpdated = 1;
    } else if (objCode == 0xd4 || objCode == 0xd6) {
        dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
        frame = 0;
        if (anime < 10) {
            if (dirIndex == work->dirAnime.dir && anime == work->dirAnime.anime)
                goto draw;
            if (dirIndex == 0)
                frame = 0;
            else if (dirIndex == 1)
                frame = 1;
            work->dirAnime.dir = dirIndex;
        } else {
            if (anime == work->dirAnime.anime)
                goto draw;
            switch (anime) {
            case 10:
                frame = 2;
                break;
            case 11:
                frame = 3;
                break;
            }
        }
        work->dirAnime.anime = anime;
        BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, frame);
        isUpdated = 1;
    } else {
        if (anime == work->dirAnime.anime)
            goto draw;
        work->dirAnime.anime = anime;
        BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, isUpdated);
        isUpdated = 1;
    }
draw:
    FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, 1);
    FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
    FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
    BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
}

int FLDMMDL_DRAW_GetBlactIdMultiPattern(Mmdl *mmdl, u32 kind)
{
    return FLDMMDL_GetDrawProcWork(mmdl)->blactId;
}

/* Reads list index and cursor for object codes 0xD3 and 0xD5; other codes report 0 and 0. Returns 0 without an actor. */
int FLDMMDL_DRAW_GetBlactAnimeTypeA(Mmdl *mmdl, u16 *outAnime, u16 *outFrame)
{
    u32 objCode;
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;

    objCode = FLDMMDL_GetObjCode(mmdl);
    if (objCode == 0xD3 || objCode == 0xD5) {
        work = FLDMMDL_GetDrawProcWork(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
            *outAnime = BILLBOARD_ACT_GetEntryList(bbActSys, work->blactId);
            *outFrame = BILLBOARD_ACT_GetEntryCursor(bbActSys, work->blactId);
            return 1;
        }
        return 0;
    }
    *outAnime = 0;
    *outFrame = 0;
    return 1;
}

/* Same as FLDMMDL_DRAW_GetBlactAnimeTypeA for object codes 0xDD and 0xDE. */
int FLDMMDL_DRAW_GetBlactAnimeTypeB(Mmdl *mmdl, u16 *outAnime, u16 *outFrame)
{
    MmdlDrawWork *work;
    struct BbActSys *bbActSys;

    if ((u16)(FLDMMDL_GetObjCode(mmdl) + 0xFF23) <= 1) {
        work = FLDMMDL_GetDrawProcWork(mmdl);
        if (work->blactId != 0xFFFF) {
            bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
            *outAnime = BILLBOARD_ACT_GetEntryList(bbActSys, work->blactId);
            *outFrame = BILLBOARD_ACT_GetEntryCursor(bbActSys, work->blactId);
            return 1;
        }
        return 0;
    }
    *outAnime = 0;
    *outFrame = 0;
    return 1;
}

/* Two-pattern model: list index follows anime 0 or 1. */
void FLDMMDL_DRAW_DrawTwoPattern(Mmdl *mmdl)
{
    u32 isUpdated;
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;
    u32 anime;

    isUpdated = 0;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (anime != work->dirAnime.anime && anime < 2) {
            work->dirAnime.anime = anime;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, anime);
            isUpdated = 1;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, isUpdated, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Three-pattern model: anime 10 to 12 select list index 1 to 3. */
void FLDMMDL_DRAW_DrawThreePattern(Mmdl *mmdl)
{
    MmdlDrawWork *work;
    VecFx32 drawPos;
    struct BbActSys *bbActSys;
    u32 anime;
    u32 frameOrUpdated; /* list index while switching, then the update flag */

    frameOrUpdated = 0;
    work = FLDMMDL_GetDrawProcWork(mmdl);
    if (work->blactId != 0xFFFF) {
        bbActSys = FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl));
        anime = FLDMMDL_GetDrawStatus(mmdl);
        if (anime != work->dirAnime.anime) {
            switch (anime) {
            case 10: frameOrUpdated = 1; break;
            case 11: frameOrUpdated = 2; break;
            case 12: frameOrUpdated = 3; break;
            }
            work->dirAnime.anime = anime;
            BILLBOARD_ACT_SetEntryList(bbActSys, work->blactId, frameOrUpdated);
            frameOrUpdated = 1;
        }
        FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, work->blactId, frameOrUpdated, 0);
        FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
        FLDMMDL_DRAW_AddHeightOffset(mmdl, &drawPos);
        BILLBOARD_SetElemPos(BILLBOARD_ACT_GetBoard(bbActSys), work->blactId, &drawPos);
    }
}

/* Object code 0x7B: true when the model has no actor entry or the last command of the entry is in range. */
u32 FLDMMDL_DRAW_CheckBlactReady(Mmdl *mmdl, u32 kind)
{
    u32 blactId;
    u16 lastCommand;

    if (FLDMMDL_GetObjCode(mmdl) != 0x7B) {
        return 1;
    }
    blactId = (u16)FLDMMDL_CallDrawGetProc(mmdl, 0);
    if (blactId != 0xFFFF) {
        if (BILLBOARD_ACT_GetEntryLastCommand(FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl)), blactId, &lastCommand) == 1) {
            return 1;
        }
    }
    return 0;
}

/* Object code 0x7B: rewinds the animation cursor of the actor. */
void FLDMMDL_DRAW_ResetBlactAnime(Mmdl *mmdl)
{
    u16 blactId;
    u16 zero;
    if (FLDMMDL_GetObjCode(mmdl) == 0x7B) {
        zero = 0;
        blactId = FLDMMDL_CallDrawGetProc(mmdl, 0);
        if (blactId != 0xFFFF) {
            BILLBOARD_ACT_SetEntryCursor(FLDMMDL_BLACT_GetBbActSys(FLDMMDL_GetBlActCont(mmdl)), blactId, zero);
        }
    }
}

/* Clears the direction state and sets the direction to 8 (none). */
int FLDMMDL_DRAW_InitDirState(MmdlDirAnimeState *state)
{
    MI_CpuFill8(state, 0, 4);
    state->dir = 8;
    return 8;
}

/* Direction and animation state machine of billboard models: picks the list index (dir + anime * 4)
 * and blends turns through a rest frame group. */
void FLDMMDL_DRAW_UpdateDirAnime(MmdlDirAnimeState *state, Mmdl *mmdl, struct BbActSys *bbActSys, u16 blactId)
{
    MmdlRestFrames restFrames;
    u32 isUpdated;
    u16 listIndex;
    u32 dirIndex;
    u32 anime;

    isUpdated = 0;
    dirIndex = FLDMMDL_DRAW_GetDirIndex(mmdl);
    anime = FLDMMDL_GetDrawStatus(mmdl);
    listIndex = dirIndex + anime * 4;
    if (state->wait != 0 && anime == state->anime)
        state->wait = isUpdated;
    if (dirIndex != state->dir) {
        isUpdated = 1;
        state->anime = anime;
        state->dir = dirIndex;
        state->frame = 0;
        BILLBOARD_ACT_SetEntryList(bbActSys, blactId, listIndex);
    } else if (anime != state->anime) {
        isUpdated = 1;
        if (anime == 0) {
            if (state->anime == 0) {
                BILLBOARD_ACT_SetEntryList(bbActSys, blactId, listIndex);
                state->anime = anime;
                state->wait = 0;
            } else {
                if (state->wait == 0) {
                    state->wait++;
                    isUpdated = 0;
                    goto update;
                }
                restFrames = gMmdlDrawRestFrames;
                state->frame = BILLBOARD_ACT_GetEntryCursor(bbActSys, blactId);
                if (state->frame >= 4)
                    state->frame = 0;
                state->frame = restFrames.frames[state->frame];
                BILLBOARD_ACT_SetEntryList(bbActSys, blactId, listIndex);
                state->anime = anime;
                state->wait = 0;
            }
        } else {
            if (state->anime != 0) {
                state->frame = BILLBOARD_ACT_GetEntryCursor(bbActSys, blactId);
                state->frame = (state->frame >= 2) ? 0 : 2;
            }
            BILLBOARD_ACT_SetEntryList(bbActSys, blactId, listIndex);
            BILLBOARD_ACT_SetEntryCursor(bbActSys, blactId, state->frame);
            state->anime = anime;
            state->wait = 0;
        }
    }
update:
    FLDMMDL_DRAW_UpdateBlactFlags(mmdl, bbActSys, blactId, isUpdated, 0);
}

/* Adds the height offset of the field map to the draw position. */
void FLDMMDL_DRAW_AddHeightOffset(Mmdl *mmdl, VecFx32 *pos)
{
    pos->y += FIELDMAP_GetCameraPitchScale(FLDMMDL_SysGetFieldMap(FLDMMDL_GetMmdlSys(mmdl)));
}

/* Display direction as a table index. The matched bytes leave the result of the
 * called function in r0 and have no return statement. */
u32 FLDMMDL_DRAW_GetDirIndex(Mmdl *mmdl){
    u32 viewAngle = FLDMMDL_SysGetAreaId(FLDMMDL_GetMmdlSys(mmdl));
    u32 dirDisp = FLDMMDL_GetDirDisp(mmdl);
    if (FLDMMDL_CheckStatusBit(mmdl, 0x2000))
        FLDMMDL_RAIL_MOVE_GetDirByAngle(mmdl, viewAngle);
    else
        FLDMMDL_MOVE_GetRelativeDirCode(dirDisp, viewAngle);
}

/* Sets animation enable and visibility of the actor from the state of the model. */
void FLDMMDL_DRAW_UpdateBlactFlags(Mmdl *mmdl, struct BbActSys *bbActSys, u32 blactId, u32 isUpdated, u32 checkMode)
{
    u32 enable;
    u32 entryHookFlag;

    enable = 1;
    entryHookFlag = FLDMMDL_BLACT_GetEntryHookFlag(mmdl);
    if (isUpdated == 0) {
        if (checkMode == 1) {
            if (entryHookFlag == 1 && FLDMMDL_CheckStatusBit(mmdl, 0x10) != 0) enable = 0;
        } else {
            if (entryHookFlag == 1 && FLDMMDL_ACMD_CheckAnimePaused(mmdl) == 1) enable = 0;
        }
    }
    BILLBOARD_ACT_SetEntryEnabled(bbActSys, blactId, enable);
    enable = 1;
    if (FLDMMDL_CheckStatusBitVanish(mmdl) == 1) enable = 0;
    BILLBOARD_ACT_SetEntryFlags(bbActSys, blactId, enable);
}

/* G3D object draw procedure init. */
void FLDMMDL_DRAW_InitBlactId(Mmdl *mmdl)
{
    MmdlDrawWork *work = FLDMMDL_InitDrawProcWork(mmdl, 2);
    work->blactId = FLDMMDL_G3DOBJ_AddObj(mmdl);
}

/* G3D object draw procedure draw: position, visibility and animation step. */
void FLDMMDL_DRAW_DrawEffect(Mmdl *mmdl)
{
    u32 hidden;
    struct FieldG3dObjCtrl *g3dObjCtrl;
    VecFx32 drawPos;
    MmdlDrawWork *work;

    work = FLDMMDL_GetDrawProcWork(mmdl);
    g3dObjCtrl = FLDMMDL_G3DOBJ_GetObjCtrl(mmdl);
    FLDMMDL_ACMD_GetDrawPos(mmdl, &drawPos);
    FIELD_G3DOBJ_SetObjectTrans(g3dObjCtrl, work->blactId, &drawPos);
    hidden = 0;
    if (FLDMMDL_CheckStatusBitVanish(mmdl) == 1) hidden = 1;
    FIELD_G3DOBJ_SetObjectHidden(g3dObjCtrl, work->blactId, hidden);
    if (FLDMMDL_ACMD_CheckAnimePaused(mmdl) == 0) {
        FIELD_G3DOBJ_LoopAnimeFrame(g3dObjCtrl, work->blactId, 0x1000);
    }
}

/* G3D object draw procedure remove. */
void FLDMMDL_DRAW_DeleteEffect(Mmdl *mmdl)
{
    FLDMMDL_G3DOBJ_DelObj(mmdl, FLDMMDL_GetDrawProcWork(mmdl)->blactId);
}

void FLDMMDL_DRAW_DeleteEffectAlias(Mmdl *mmdl) { FLDMMDL_DRAW_DeleteEffect(mmdl); }

void FLDMMDL_DRAW_InitEffectAlias(Mmdl *mmdl) { FLDMMDL_DRAW_InitBlactId(mmdl); }
