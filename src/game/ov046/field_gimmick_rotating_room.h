#ifndef GAME_OV046_FIELD_GIMMICK_ROTATING_ROOM_H
#define GAME_OV046_FIELD_GIMMICK_ROTATING_ROOM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_rotating_room.c, prototypes copied from their definitions. */

struct FieldMap;
struct FldExpObjCnt;
struct VecFx32;
struct GameSystem;
struct GameEvent;
struct Mmdl;
typedef struct VecFx32 VecFx32;

#include "../types.h"
#include "../ov037/gimmick_save_types.h"

void FIELD_GIMMICK_ROTATING_ROOM_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_ROTATING_ROOM_InitModel(struct FldExpObjCnt *expObj, int modelIndex, VecFx32 *pos, u16 *angle, int animCount, int cullDraw);
void FIELD_GIMMICK_ROTATING_ROOM_InitUnitPose(FieldGimmickRotatingRoomSave *save, struct FldExpObjCnt *expObj, int unitIdx);
void FIELD_GIMMICK_ROTATING_ROOM_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_ROTATING_ROOM_Update(struct FieldMap *fieldMap);
void FIELD_GIMMICK_ROTATING_ROOM_StartButtonEvent(struct GameSystem *gameSystem, int unitIndex, int side);
struct GameEvent;
struct GameEvent *FIELD_GIMMICK_ROTATING_ROOM_StartLeverEvent(struct GameSystem *gameSystem, int unitIndex, int side);
struct GameEvent *FIELD_GIMMICK_ROTATING_ROOM_StartRotateEvent(struct GameSystem *gameSystem, int unitIndex);
struct GameEvent *FIELD_GIMMICK_ROTATING_ROOM_StartHopEvent(struct GameSystem *gameSystem, int direction);
int FIELD_GIMMICK_ROTATING_ROOM_CalcUnitPose(FieldGimmickRotatingRoomUnit *unit);
int FIELD_GIMMICK_ROTATING_ROOM_GetRotateAnim(FieldGimmickRotatingRoomUnit *unit, int newPose);
int FIELD_GIMMICK_ROTATING_ROOM_ButtonEventProc(struct GameEvent *event, int *state, void *eventWork);
int FIELD_GIMMICK_ROTATING_ROOM_LeverEventProc(struct GameEvent *event, int *state, void *eventWork);
int FIELD_GIMMICK_ROTATING_ROOM_RotateEventProc(struct GameEvent *event, int *state, void *eventWork);
int FIELD_GIMMICK_ROTATING_ROOM_PlayAnimEventProc(struct GameEvent *event, int *state, void *eventWork);
int FIELD_GIMMICK_ROTATING_ROOM_HopEventProc(struct GameEvent *event, int *state, void *eventWork);
void FIELD_GIMMICK_ROTATING_ROOM_SetExteriorHidden(struct FldExpObjCnt *expObj, struct FieldMap *fieldMap, u32 hidden);
struct Mmdl *FIELD_GIMMICK_ROTATING_ROOM_FindMmdlByObjId(struct FieldMap *fieldMap, int objId);
void FIELD_GIMMICK_ROTATING_ROOM_SetMmdlVanish(struct FieldMap *fieldMap, int objId, u32 vanish);
void FIELD_GIMMICK_ROTATING_ROOM_ApplyPoseLines(struct FieldMap *fieldMap, int unitIndex, int pose);
int FIELD_GIMMICK_ROTATING_ROOM_IsPosInside(VecFx32 *pos);
/* END mkheaders: generated region */

#endif
