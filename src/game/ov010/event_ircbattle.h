#ifndef GAME_OV010_EVENT_IRCBATTLE_H
#define GAME_OV010_EVENT_IRCBATTLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of event_ircbattle.c, prototypes copied from their definitions. */

struct GameEvent;

#include "../ov010/event_ircbattle_shared_types.h"
#include "../types.h"

int IRC_BATTLE_ENTRY_Main(void *parentEvent, int *step, IrcBattleEntryWork *work);
struct GameEvent *IRC_BATTLE_ENTRY_Create(void *gameSys, void *unused, struct GameEvent *event, int create);
void IRC_BATTLE_ENTRY_FreeParties(IrcBattleEntryWork *work);
void IRC_BATTLE_ENTRY_RestoreBgm(IrcBattleEntryWork *work);
void IRC_BATTLE_ENTRY_SetMode(IrcBattleEntryWork *work, u32 mode);
void *IRC_BATTLE_ENTRY_GetGameSys(IrcBattleEntryWork *work);
void *IRC_BATTLE_ENTRY_GetSaveControl(IrcBattleEntryWork *work);
/* END mkheaders: generated region */

#endif
