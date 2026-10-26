#ifndef GAME_OV176_LIVEBATTLEMATCH_IRC_H
#define GAME_OV176_LIVEBATTLEMATCH_IRC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of livebattlematch_irc.c, prototypes copied from their definitions. */

struct LiveBattleMatchIrcWork;
struct GameData;
struct GFLNetHandle;

#include "../ov176/livebattlematch_shared_types.h"
#include "../types.h"

void LIVEBATTLEMATCH_IRC_ShowMenu(LivebattlematchRequest *p, int a);
void LIVEBATTLEMATCH_IRC_CreateWindow(LivebattlematchRequest *p, int mode);
void LIVEBATTLEMATCH_IRC_DeleteWindow(LivebattlematchRequest *p);
int LIVEBATTLEMATCH_IRC_PollWindowResult(LivebattlematchRequest *p);
void LIVEBATTLEMATCH_IRC_SetMenuValue(LivebattlematchRequest *p, int a, int b);
int LIVEBATTLEMATCH_IRC_GetMenuValue(LivebattlematchRequest *p);
void LIVEBATTLEMATCH_IRC_ToggleSe(int unused, int visible);
void LIVEBATTLEMATCH_IRC_DeleteMenuRecord(LivebattlematchRequest *p);
struct LiveBattleMatchIrcWork *LIVEBATTLEMATCH_IRC_Create(struct GameData *unused, u16 heap);
void LIVEBATTLEMATCH_IRC_Delete(struct LiveBattleMatchIrcWork *p);
void LIVEBATTLEMATCH_IRC_NoOp(void *unused);
int LIVEBATTLEMATCH_IRC_CheckError(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_InitState(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_StartSession(struct LiveBattleMatchIrcWork *p);
void LIVEBATTLEMATCH_IRC_Exit(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_WaitExit(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_ResetState(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_EndSession(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_SendRegulation(struct LiveBattleMatchIrcWork *unused, void *arg);
int LIVEBATTLEMATCH_IRC_TakeRegulation(struct LiveBattleMatchIrcWork *p, void **out);
int LIVEBATTLEMATCH_IRC_SendSaveData(struct LiveBattleMatchIrcWork *unused, void *arg);
int LIVEBATTLEMATCH_IRC_RecvSaveData(struct LiveBattleMatchIrcWork *p,const void *q);
u32 LIVEBATTLEMATCH_IRC_SendSyncValue(struct LiveBattleMatchIrcWork *unused,void *a);
int LIVEBATTLEMATCH_IRC_RecvSyncValue(struct LiveBattleMatchIrcWork *p,const void *q);
void LIVEBATTLEMATCH_IRC_CreateDelivery(struct LiveBattleMatchIrcWork *p, void *value);
int LIVEBATTLEMATCH_IRC_DeliveryMain(struct LiveBattleMatchIrcWork *p);
void LIVEBATTLEMATCH_IRC_ClearState(struct LiveBattleMatchIrcWork *p);
int LIVEBATTLEMATCH_IRC_DeliveryEnd(struct LiveBattleMatchIrcWork *p);
void LIVEBATTLEMATCH_IRC_RecvHandler0(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e);
void LIVEBATTLEMATCH_IRC_RecvHandler1(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e);
void LIVEBATTLEMATCH_IRC_RecvHandler2(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e);
void LIVEBATTLEMATCH_IRC_RecvHandler3(u32 a, void *b, void *c, struct LiveBattleMatchIrcWork *p, struct GFLNetHandle *e);
int LIVEBATTLEMATCH_IRC_RecvHandler4(int a, int b);
int LIVEBATTLEMATCH_IRC_OnFilter(int a, int b);
/* END mkheaders: generated region */

#endif
