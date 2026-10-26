#ifndef GAME_OV010_FIELD_SKILL_CHECK_H
#define GAME_OV010_FIELD_SKILL_CHECK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_skill_check.c, prototypes copied from their definitions. */

struct GameSystem;
struct GameEvent;
struct FieldMap;
struct GameData;
struct PlayerWork;
struct LinkEnterWork;
struct SubscreenToggleWork;
typedef struct LinkEnterWork LinkEnterWork;
typedef struct SubscreenToggleWork SubscreenToggleWork;

#include "../arm9/app_keycursor_types.h"
#include "../types.h"

void FIELD_SKILL_CHECK_FillUseFlags(FieldSkillUseFlags *flags, struct GameSystem *gameSystem, void *fieldMap);
int FIELD_SKILL_CHECK_CallHandler(int skillIndex, struct GameSystem *gameSystem, void *fieldMap);
struct GameEvent *FIELD_LINK_EVENT_Create(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int FIELD_SKILL_CHECK_Bicycle(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int FIELD_SKILL_CHECK_WeatherZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int FIELD_SKILL_CHECK_NormalFieldZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int FIELD_SKILL_CHECK_FrontTile(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int FIELD_SKILL_CHECK_NormalFieldZoneNotZone34(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int FIELD_LINK_EVENT_EnterEventMain(struct GameEvent *event, int *seq, LinkEnterWork *work);
struct GameEvent *FIELD_LINK_EVENT_CreateEnterEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
struct GameEvent *FIELD_LINK_EVENT_CreateIntrudeWarpEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
int FIELD_LINK_EVENT_ToggleSubscreenEventMain(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work);
struct GameEvent *FIELD_LINK_EVENT_CreateToggleSubscreenEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
