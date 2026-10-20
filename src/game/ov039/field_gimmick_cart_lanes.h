#ifndef GAME_OV039_FIELD_GIMMICK_CART_LANES_H
#define GAME_OV039_FIELD_GIMMICK_CART_LANES_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_cart_lanes.c, prototypes copied from their definitions. */

struct FieldMap;
struct TcbTask;
struct GameSystem;
struct GameEvent;

#include "../types.h"
#include "../ov039/field_gimmick_cart_lanes_types.h"
#include "../ov021/fld_exp_obj_types.h"
#include "../ov037/gimmick_save_types.h"
#include "../sdk_fx.h"

u8 FIELD_GIMMICK_CART_LANES_FindDockAt(int x, int z);
u8 FIELD_GIMMICK_CART_LANES_GetActiveCart(FieldGimmickCartLanesWork *work, int lane);
void FIELD_GIMMICK_CART_LANES_Setup(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_UpdateTask(struct TcbTask *tcb, struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_End(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_SaveCartFrames(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CART_LANES_TransferSound(struct GameSystem *gameSystem);
u8 FIELD_GIMMICK_CART_LANES_GetDockCart(FieldGimmickCartLanesWork *work, int dock);
unsigned char FIELD_GIMMICK_CART_LANES_GetDockLane(int dock);
int FIELD_GIMMICK_CART_LANES_IsCartAtDock(FieldGimmickCartLanesWork *work, int dock);
int FIELD_GIMMICK_CART_LANES_GetAnimeFrame(FldExpObjCnt *expObj, u16 lane, u16 animeIndex);
void FIELD_GIMMICK_CART_LANES_SetAnimeFrame(FldExpObjCnt *expObj, u8 lane, u16 animeIndex, int frame);
struct GameEvent *FIELD_GIMMICK_CART_LANES_CreateSwitchEvent(struct GameSystem *gameSystem, u32 lane);
int FIELD_GIMMICK_CART_LANES_SwitchEventMain(struct GameEvent *event, int *seq, void *eventWork);
struct GameEvent *FIELD_GIMMICK_CART_LANES_CheckRideEvent(struct GameSystem *gameSystem);
void FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(struct GameSystem *gameSystem, u32 lane);
int FIELD_GIMMICK_CART_LANES_IsLaneLocked(FieldGimmickCartLanesSave *save, int lane);
void FIELD_GIMMICK_CART_LANES_UnlockLane(FieldGimmickCartLanesSave *save, u8 lane);
int FIELD_GIMMICK_CART_LANES_RideEventMain(struct GameEvent *event, int *seq, void *eventWork);
int FIELD_GIMMICK_CART_LANES_RideRefusedEventMain(struct GameEvent *event, int *seq, void *eventWork);
void FIELD_GIMMICK_CART_LANES_ApplySwitch(struct FieldMap *fieldMap, FldExpObjCnt *expObj);
void FIELD_GIMMICK_CART_LANES_SwapCartAnimes(FldExpObjCnt *expObj, int oldState, int lane);
int FIELD_GIMMICK_CART_LANES_FindStopAtFrame(u32 cart, u32 frame, u8 *stopIndex);
int FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit(FldExpObjCnt *expObj, int lane, u8 cart);
void FIELD_GIMMICK_CART_LANES_SampleJointTranslation(const u8 *resAnm, int jointIndex, int frame, VecFx32 *out);
void FIELD_GIMMICK_CART_LANES_SampleJointTrack(int *out, int frame, const FieldGimmickCartLanesJointTrack *track, const u8 *base);
void FIELD_GIMMICK_CART_LANES_UpdateCartSound(struct FieldMap *fieldMap, FieldGimmickCartLanesWork *work);
/* END mkheaders: generated region */

#endif
