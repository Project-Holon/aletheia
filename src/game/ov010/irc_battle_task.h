#ifndef GAME_OV010_IRC_BATTLE_TASK_H
#define GAME_OV010_IRC_BATTLE_TASK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of irc_battle_task.c, prototypes copied from their definitions. */

struct IrcBattleTaskWork;
struct GameEvent;
struct IrcBattleRequest;
typedef struct IrcBattleTaskWork IrcBattleTaskWork;
typedef struct IrcBattleRequest IrcBattleRequest;

#include "../types.h"

int IRC_BATTLE_TASK_Main(struct GameEvent *event, int *state, void *work);
struct GameEvent *IRC_BATTLE_TASK_Create(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request);
void IRC_BATTLE_TASK_SetFormationOnce(int *formation, int value);
void IRC_BATTLE_TASK_Empty0(void);
void IRC_BATTLE_TASK_Empty1(void);
void IRC_BATTLE_TASK_Empty2(void);
void IRC_BATTLE_TASK_Empty3(void);
/* END mkheaders: generated region */

#endif
