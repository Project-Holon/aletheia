#ifndef GAME_OV176_BATTLE_CHAMPIONSHIP_CORE_H
#define GAME_OV176_BATTLE_CHAMPIONSHIP_CORE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of battle_championship_core.c, prototypes copied from their definitions. */

struct WifibattlematchCallback;
typedef struct WifibattlematchCallback WifibattlematchCallback;

#include "../ov176/battle_championship_flow_types.h"
#include "../types.h"
#include "../ov176/livebattlematch_shared_types.h"

int BATTLE_CHAMPIONSHIP_FLOW_Create(void *owner,void *unused,void *context);
int BATTLE_CHAMPIONSHIP_FLOW_Delete(void *owner, int unused, int unused2, BattleChampionshipFlowWork *work);
int BATTLE_CHAMPIONSHIP_FLOW_IsFinished(u32 unused,u32 unused2,u32 unused3,BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_CreateView(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_CreateText(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_UpdateText(BattleChampionshipFlowWork *work);
void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(WifibattlematchCallback *proc, int *unused, void *workArg);
void BATTLE_CHAMPIONSHIP_FLOW_End(WifibattlematchCallback *proc, int *unusedState, void *unusedWork);
void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(WifibattlematchCallback *proc, int *state, void *workArg);
void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(WifibattlematchCallback *proc, int *state, void *workArg);
void BATTLE_CHAMPIONSHIP_FLOW_StartMenu(WifibattlematchCallback *proc, int *state, void *workArg);
void BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch(WifibattlematchCallback *proc, int *state, void *workArg);
/* END mkheaders: generated region */

#endif
