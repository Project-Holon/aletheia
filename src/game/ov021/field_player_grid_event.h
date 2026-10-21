#ifndef GAME_OV021_FIELD_PLAYER_GRID_EVENT_H
#define GAME_OV021_FIELD_PLAYER_GRID_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_player_grid_event.c, prototypes copied from their definitions. */

struct BoulderDropWork;
struct TcbTask;
struct HopWork;
struct JumpWork;
typedef struct BoulderDropWork BoulderDropWork;
typedef struct HopWork HopWork;
typedef struct JumpWork JumpWork;

#include "../ov021/field_player_types.h"
#include "../types.h"
#include "../ov020/event_mapchange_types.h"
#include "../ov010/fldmmdl_types.h"
#include "../ov021/field_flash_shared_types.h"
#include "../sdk_fx.h"

int FIELD_PLAYER_GRID_EVENT_TryPushBoulder(FieldPlayerGrid *player, int unused, int keyDir, int flags);
int FIELD_PLAYER_GRID_EVENT_PushBoulderByFlags(FieldPlayerGrid *player, u16 dir, u32 flags);
int FIELD_PLAYER_GRID_EVENT_StartBoulderDrop(FieldPlayerGrid *player, u16 dir, int hitResult);
GameEvent *FIELD_PLAYER_GRID_EVENT_CreateBoulderDropEvent(FieldPlayerGrid *player, u32 dir, Mmdl *boulder, u32 fillsHole);
int FIELD_PLAYER_GRID_EVENT_BoulderDropEvent(GameEvent *event, int *seq, BoulderDropWork *work);
struct TcbTask *FIELD_PLAYER_GRID_EVENT_CreateHopTask(FieldPlayer *player, u16 dir, u32 attr, u32 heapId);
int FIELD_PLAYER_GRID_EVENT_IsHopDone(struct TcbTask *task);
void FIELD_PLAYER_GRID_EVENT_DeleteHopTask(struct TcbTask *task);
void FIELD_PLAYER_GRID_EVENT_HopTask(struct TcbTask *task, HopWork *work);
struct TcbTask *FIELD_PLAYER_GRID_EVENT_CreateJumpTask(FieldPlayer *player, u16 dir, u32 attr, u32 heapId);
int FIELD_PLAYER_GRID_EVENT_IsJumpDone(struct TcbTask *task);
void FIELD_PLAYER_GRID_EVENT_DeleteJumpTask(struct TcbTask *task);
void FIELD_PLAYER_GRID_EVENT_SetJumpDrawOffset(Mmdl *mmdl, const VecFx32 *offset);
int FIELD_PLAYER_GRID_EVENT_JumpUpStart(JumpWork *work);
int FIELD_PLAYER_GRID_EVENT_JumpUpApproach(JumpWork *work);
int FIELD_PLAYER_GRID_EVENT_JumpUpRise(JumpWork *work);
int FIELD_PLAYER_GRID_EVENT_JumpUpArc(JumpWork *work);
int FIELD_PLAYER_GRID_EVENT_JumpUpLand(JumpWork *work);
int FIELD_PLAYER_GRID_EVENT_JumpUpWaitEffect(JumpWork *work);
void FIELD_PLAYER_GRID_EVENT_UpdateJumpDown(JumpWork *work);
void FIELD_PLAYER_GRID_EVENT_RunStateTable(void *work, u16 *state);
u32 FIELD_PLAYER_GRID_EVENT_GetFrontTileAttr(FieldPlayerGrid *work, u32 direction);
/* END mkheaders: generated region */

#endif
