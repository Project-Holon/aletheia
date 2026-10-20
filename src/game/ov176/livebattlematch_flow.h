#ifndef GAME_OV176_LIVEBATTLEMATCH_FLOW_H
#define GAME_OV176_LIVEBATTLEMATCH_FLOW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of livebattlematch_flow.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov176/livebattlematch_shared_types.h"

u8 *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u16 heap);
void LIVEBATTLEMATCH_FLOW_Delete(int *p);
void LIVEBATTLEMATCH_FLOW_Release(int *p);
int LIVEBATTLEMATCH_FLOW_GetResult(int *p);
void LIVEBATTLEMATCH_FLOW_SelectPhase(int p,int *state,char *q);
void LIVEBATTLEMATCH_FLOW_End(int p);
void LIVEBATTLEMATCH_FLOW_Main(int *sys,unsigned int *state,u8 *p);
void LIVEBATTLEMATCH_FLOW_Confirm(int *sys,unsigned int *state,u8 *p);
void LIVEBATTLEMATCH_FLOW_Battle(int *sys,unsigned int *state,u8 *p);
void LIVEBATTLEMATCH_FLOW_Result(int *sys,unsigned int *state,u8 *p);
void LIVEBATTLEMATCH_FLOW_Card(int *sys,unsigned int *state,u8 *p);
void LIVEBATTLEMATCH_FLOW_Sub(int *a, int *state, u8 *p);
void LIVEBATTLEMATCH_FLOW_DrawMenu(u8 *p, int mode);
void LIVEBATTLEMATCH_FLOW_HideWindow(int *p);
int LIVEBATTLEMATCH_FLOW_GetWindowResult(int *p);
/* END mkheaders: generated region */

#endif
