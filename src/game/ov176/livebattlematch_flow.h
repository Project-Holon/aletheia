#ifndef GAME_OV176_LIVEBATTLEMATCH_FLOW_H
#define GAME_OV176_LIVEBATTLEMATCH_FLOW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of livebattlematch_flow.c, prototypes copied from their definitions. */

struct LiveBattleMatchWork;
struct WifibattlematchCallback;
typedef struct WifibattlematchCallback WifibattlematchCallback;

#include "../ov176/livebattlematch_shared_types.h"
#include "../types.h"

struct LiveBattleMatchWork *LIVEBATTLEMATCH_FLOW_Create(LiveBattleMatchInit *src,u16 heap);
void LIVEBATTLEMATCH_FLOW_Delete(struct LiveBattleMatchWork *p);
void LIVEBATTLEMATCH_FLOW_Release(struct LiveBattleMatchWork *p);
int LIVEBATTLEMATCH_FLOW_GetResult(struct LiveBattleMatchWork *p);
void LIVEBATTLEMATCH_FLOW_SelectPhase(WifibattlematchCallback *p, int *state, void *qArg);
void LIVEBATTLEMATCH_FLOW_End(WifibattlematchCallback *p, int *unusedState, void *unusedWork);
void LIVEBATTLEMATCH_FLOW_Main(WifibattlematchCallback *sys, int *state, void *pArg);
void LIVEBATTLEMATCH_FLOW_Confirm(WifibattlematchCallback *sys, int *state, void *pArg);
void LIVEBATTLEMATCH_FLOW_Battle(WifibattlematchCallback *sys, int *state, void *pArg);
void LIVEBATTLEMATCH_FLOW_Result(WifibattlematchCallback *sys, int *state, void *pArg);
void LIVEBATTLEMATCH_FLOW_Card(WifibattlematchCallback *sys, int *state, void *pArg);
void LIVEBATTLEMATCH_FLOW_Sub(WifibattlematchCallback *a, int *state, void *pArg);
void LIVEBATTLEMATCH_FLOW_DrawMenu(struct LiveBattleMatchWork *p, int mode);
void LIVEBATTLEMATCH_FLOW_HideWindow(struct LiveBattleMatchWork *p);
int LIVEBATTLEMATCH_FLOW_GetWindowResult(struct LiveBattleMatchWork *p);
/* END mkheaders: generated region */

#endif
