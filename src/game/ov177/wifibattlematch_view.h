#ifndef GAME_OV177_WIFIBATTLEMATCH_VIEW_H
#define GAME_OV177_WIFIBATTLEMATCH_VIEW_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_view.c, prototypes copied from their definitions. */

struct PrintSys;

#include "../types.h"
#include "../ov177/wifibattlematch_view_types.h"

u32 *WIFIBATTLEMATCH_VIEW_Create(int unused, int mode, u16 heap);
void WIFIBATTLEMATCH_VIEW_Delete(WifiBattleMatchViewRoot *p);
void WIFIBATTLEMATCH_VIEW_LoadBgPalette(int unused, int mode, unsigned color);
int WIFIBATTLEMATCH_VIEW_GetFrameIndex(int *p, int i);
void WIFIBATTLEMATCH_VIEW_UpdateAnimation(WifiBattleMatchViewAnimState *p);
void WIFIBATTLEMATCH_VIEW_BlendColors(u32 slot, u16 *out, const u16 *phase, u32 unused, u8 a, u8 b, u16 c0, u16 c1);
void WIFIBATTLEMATCH_VIEW_DrawTaggedText(u32 *p, struct PrintSys *win, u32 str, u32 c2, u32 c1, u16 heap);
WifibattlematchViewWork *WIFIBATTLEMATCH_VIEW_CreateMainWindow(const WifiBattleMatchViewMainInfo *info, u32 headerMsgId, void *myStatus, void *owner, void *table, int font, void *printQue, void *msgData, void *wordSet, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteMainWindow(void *p);
char *WIFIBATTLEMATCH_VIEW_CreateStatusWindow(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteStatusWindow(void *p);
void WIFIBATTLEMATCH_VIEW_DrawStatusWindow(char *p, int mode, void *mgr, void *print, int font, u16 unused);
char *WIFIBATTLEMATCH_VIEW_CreateDateWindow(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteDateWindow(void *p);
void WIFIBATTLEMATCH_VIEW_DrawDateWindow(char *p, int mode, void *mgr, void *print, int font, u32 unused);
int WIFIBATTLEMATCH_VIEW_UpdatePokeList(unsigned char *p, void *mgr);
int WIFIBATTLEMATCH_VIEW_StepMainWindow(WifibattlematchViewWork *w);
int WIFIBATTLEMATCH_VIEW_StepMainWindowIdle(WifibattlematchViewWork *w);
void WIFIBATTLEMATCH_VIEW_SetupMainWindow(WifibattlematchViewWork *w, unsigned headerMsgId, const WifiBattleMatchViewMainInfo *info, void *myStatus, u32 font, void *printQue, void *msgData, void *wordSet, int highlight, u16 h);
int WIFIBATTLEMATCH_VIEW_UpdateWindow(unsigned char *p, void *mgr);
void WIFIBATTLEMATCH_VIEW_DeleteWindow(unsigned *p);
void WIFIBATTLEMATCH_VIEW_CreatePokeActors(WifibattlematchViewWork *w, void *owner, void *rec, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeletePokeActors(char *p);
void WIFIBATTLEMATCH_VIEW_CreatePokeActor(unsigned char *p, unsigned idx, void *owner, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeletePokeActor(char *p);
void WIFIBATTLEMATCH_VIEW_CreateActorFromTable(char *p, void *owner, void *table, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteActorFromTable(int *p);
void WIFIBATTLEMATCH_VIEW_CreateActorFromInfo(char *p, const WifiBattleMatchViewMainInfo *desc, void *owner, void *table, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteActorFromInfo(char *p);
WifiBattleMatchViewRecordWork *WIFIBATTLEMATCH_VIEW_CreateRecordWindow(const WifiBattleMatchViewRecord *rec, void *clunit, void *table, void *font, void *printQue, void *msgData, void *wordSet, u32 mode, u32 owner, int style, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteRecordWindow(char *p);
int WIFIBATTLEMATCH_VIEW_UpdateRecordWindow(void *p, void *mgr);
int WIFIBATTLEMATCH_VIEW_StepRecordWindow(WifiBattleMatchViewRecordWork *p);
void WIFIBATTLEMATCH_VIEW_SetupRecordWindow(WifiBattleMatchViewRecordWork *p, const WifiBattleMatchViewRecord *data, unsigned font, void *print, void *msg, void *fmt, int alt, u16 heap);
int WIFIBATTLEMATCH_VIEW_UpdateRecordWindowInner(unsigned char *p, void *mgr);
void WIFIBATTLEMATCH_VIEW_DeleteRecordWin(WifiBattleMatchViewRecordWork *p);
void WIFIBATTLEMATCH_VIEW_CreateRecordActor(char *p, unsigned idx, void *owner, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteRecordActor(char *p);
void WIFIBATTLEMATCH_VIEW_CreateRecordActorFromRec(char *p, const WifiBattleMatchViewRecord *q, void *x, void *data, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteRecordActorObj(WifiBattleMatchViewRecordWork *p);
unsigned WIFIBATTLEMATCH_VIEW_GetEntryValue(void *total, unsigned wins, unsigned losses);
void **WIFIBATTLEMATCH_VIEW_CreateActorArray(void *owner, void *src, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeleteActorArray(int *p);
void WIFIBATTLEMATCH_VIEW_Noop(int p);
void WIFIBATTLEMATCH_VIEW_SetActorVisible(void **p, int on);
WifiBattleMatchViewPartyWork *WIFIBATTLEMATCH_VIEW_CreatePartyWindow(void *src, void *owner, void *table, unsigned font, void *print, void *msg, u16 heap);
void WIFIBATTLEMATCH_VIEW_DeletePartyWindow(char *p);
int WIFIBATTLEMATCH_VIEW_StepPartyWindow(WifiBattleMatchViewPartyWork *p);
int WIFIBATTLEMATCH_VIEW_StepPartyWindowAlt(WifiBattleMatchViewPartyWork *p);
int WIFIBATTLEMATCH_VIEW_UpdatePartyWindow(char *p, void *q);
/* END mkheaders: generated region */

#endif
