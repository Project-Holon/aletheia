#ifndef GAME_OV006_EVENT_WIFICLUB_H
#define GAME_OV006_EVENT_WIFICLUB_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_wificlub.c, prototypes copied from their definitions. */

struct GameEvent;
struct Pair;
typedef struct Pair Pair;

#include "../ov006/event_wificlub_types.h"
#include "../types.h"

void EVENT_WIFICLUB_SetupBattle(WifiClubEventWork *work, int menuIndex);
void EVENT_WIFICLUB_BuildBattleEntry(WifiClubEventWork *work, void *gameData, int seq);
void EVENT_WIFICLUB_SetBattleParty(WifiClubEventWork *work, void *gameData, int seq);
void EVENT_WIFICLUB_ResetSound(WifiClubEventWork *work);
int EVENT_WIFICLUB_Main(struct GameEvent *event, u32 *seq, WifiClubEventWork *work);
void EVENT_WIFICLUB_FreeWork(WifiClubEventWork *work);
void EVENT_WIFICLUB_InitWork(void *event, void *gameSystem, struct FieldMap *fieldMap, int hideFieldObjects);
int EVENT_WIFICLUB_Create(int gameSystem, struct FieldMap *fieldMap, int hideFieldObjects);
int EVENT_WIFICLUB_Entry(int gameSystem, Pair *request);
/* END mkheaders: generated region */

#endif
