#ifndef GAME_OV010_FLDMMDL_MOVE_H
#define GAME_OV010_FLDMMDL_MOVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of fldmmdl_move.c, prototypes copied from their definitions. */

struct EventInfo;
typedef struct EventInfo EventInfo;

#include "../ov010/fldmmdl_types.h"
#include "../types.h"
#include "../sdk_fx.h"
#include "../ov010/field_g3d_map_types.h"

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
/* END mkheaders: generated region */

#endif
