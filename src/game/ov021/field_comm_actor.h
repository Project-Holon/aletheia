#ifndef GAME_OV021_FIELD_COMM_ACTOR_H
#define GAME_OV021_FIELD_COMM_ACTOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_comm_actor.c, prototypes copied from their definitions. */

struct FieldCommActorCtrl;
struct FieldCommActor;
struct GameEvent;
struct GameSystem;
struct FieldMap;
typedef struct FieldCommActorCtrl FieldCommActorCtrl;
typedef struct FieldCommActor FieldCommActor;

#include "../ov010/fldmmdl_types.h"
#include "../types.h"
#include "../sdk_fx.h"

FieldCommActorCtrl *FIELD_COMM_ACTOR_CTRL_Create(int actorMax, MmdlSys *mmdlSys, int heapId, int useRunAnime);
void FIELD_COMM_ACTOR_CTRL_Delete(FieldCommActorCtrl *ctrl);
void FIELD_COMM_ACTOR_CTRL_AddActor(FieldCommActorCtrl *ctrl, int id, int objCode, const u16 *dir, const VecFx32 *pos, const int *vanish);
void FIELD_COMM_ACTOR_CTRL_DeleteActor(FieldCommActorCtrl *ctrl, u32 id);
int FIELD_COMM_ACTOR_CTRL_SearchGridPos(FieldCommActorCtrl *ctrl, s16 gridX, int gridY, s16 gridZ, int *outId, unsigned *index);
Mmdl *FIELD_COMM_ACTOR_CTRL_GetMmdl(FieldCommActorCtrl *ctrl, u32 id);
void FIELD_COMM_ACTOR_DeleteActor(FieldCommActor *actor);
Mmdl *FIELD_COMM_ACTOR_AddMmdl(FieldCommActorCtrl *ctrl, int objCode, const u16 *dir, const VecFx32 *pos, const int *vanish, FieldCommActor *actor);
void FIELD_COMM_ACTOR_MoveInit(Mmdl *mmdl);
void FIELD_COMM_ACTOR_MoveDelete(Mmdl *mmdl);
void FIELD_COMM_ACTOR_Move(Mmdl *mmdl);
void FIELD_COMM_ACTOR_SetMoveWork(Mmdl *mmdl, const u16 *dir, const VecFx32 *pos, const int *vanish, FieldCommActor *actor);
int FIELD_COMM_ACTOR_ConvertDir(int dir);
struct GameEvent *FIELD_COMM_ACTOR_CreateSubscreenChangeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 mode);
int FIELD_COMM_ACTOR_SubscreenChangeMain(struct GameEvent *event, int *seq, void *work);
/* END mkheaders: generated region */

#endif
