#ifndef GAME_OV176_BATTLE_CHAMPIONSHIP_FLOW_H
#define GAME_OV176_BATTLE_CHAMPIONSHIP_FLOW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of battle_championship_flow.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov176/livebattlematch_shared_types.h"

int BATTLE_CHAMPIONSHIP_FLOW_Create(void *owner,void *unused,void *context);
int BATTLE_CHAMPIONSHIP_FLOW_Delete(int owner, int unused, int unused2, int *work);
int BATTLE_CHAMPIONSHIP_FLOW_IsFinished(u32 unused,u32 unused2,u32 unused3,int *work);
void BATTLE_CHAMPIONSHIP_FLOW_CreateGraphic(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteGraphic(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_ReleaseGraphic(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_CreateView(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteView(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_CreateText(char *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteText(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_UpdateText(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_SelectFlow(void *proc,int unused,char *work);
void BATTLE_CHAMPIONSHIP_FLOW_End(void *proc);
void BATTLE_CHAMPIONSHIP_FLOW_FadeIn(void *proc,int *state,char *work);
void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(void *proc,int *state,char *work);
void BATTLE_CHAMPIONSHIP_FLOW_DeleteMenu(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_InvokeCallback(struct WifibattlematchCallback **callback);
int BATTLE_CHAMPIONSHIP_FLOW_GetMenuResult(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_SelectMenuPhase(int proc, int unused, int *work);
void BATTLE_CHAMPIONSHIP_FLOW_EndMenu(int proc);
void BATTLE_CHAMPIONSHIP_FLOW_MenuMain(int proc, unsigned *state, int *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuConfirm(int *proc,int *state,u8 *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuBrowse(int proc,unsigned *state,int *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuClose(int proc,int *state,int *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck1(int proc, int *state, char *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuCardCheck2(int proc, int *state, char *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuExtra(int proc,unsigned *state,int *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraConfirm(int *proc,int *state,u8 *work);
void BATTLE_CHAMPIONSHIP_FLOW_MenuExtraBrowse(int *proc,int *state,u8 *work);
void BATTLE_CHAMPIONSHIP_FLOW_DrawMenu(int *work, int index);
void BATTLE_CHAMPIONSHIP_FLOW_HideWindow(int *work);
unsigned BATTLE_CHAMPIONSHIP_FLOW_GetWindowResult(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_SetOption(int *work, int option);
void BATTLE_CHAMPIONSHIP_FLOW_SetExtraOption(int *work, int option);
int BATTLE_CHAMPIONSHIP_FLOW_IsOptionDone(int *work);
void BATTLE_CHAMPIONSHIP_FLOW_FinishMenu(int *work,int result);
/* END mkheaders: generated region */

#endif
