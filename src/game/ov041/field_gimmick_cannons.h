#ifndef GAME_OV041_FIELD_GIMMICK_CANNONS_H
#define GAME_OV041_FIELD_GIMMICK_CANNONS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_gimmick_cannons.c, prototypes copied from their definitions. */

struct FieldMap;
struct GameEvent;
struct GameSystem;
struct FieldCamera;

#include "../types.h"
#include "../ov041/field_gimmick_cannons_types.h"

void FIELD_GIMMICK_CANNONS_Init(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CANNONS_Exit(struct FieldMap *fieldMap);
void FIELD_GIMMICK_CANNONS_Update(struct FieldMap *fieldMap);
struct GameEvent *FIELD_GIMMICK_CANNONS_CreateLaunchEvent(struct GameSystem *gameSystem);
int FIELD_GIMMICK_CANNONS_EventLaunch(struct GameEvent *event, int *seq, void *eventWork);
u8 FIELD_GIMMICK_CANNONS_FindCannonAt(int cellX, int cellZ);
u16 FIELD_GIMMICK_CANNONS_GetFirstAnimeSlot(int direction);
int FIELD_GIMMICK_CANNONS_FacingToRingIndex(int facing);
int FIELD_GIMMICK_CANNONS_TurnRingDirection(int direction, int turns);
int FIELD_GIMMICK_CANNONS_GetCannonDirection(unsigned int facing, int cannonIndex);
void FIELD_GIMMICK_CANNONS_StartBounce(FieldGimmickCannonsWork *work);
void FIELD_GIMMICK_CANNONS_ResetBounce(FieldGimmickCannonsBounce *bounce);
void FIELD_GIMMICK_CANNONS_UpdateBounce(FieldGimmickCannonsBounce *bounce, struct FieldCamera *camera);
/* END mkheaders: generated region */

#endif
