#ifndef GAME_OV128_WF2DMAP_FRIEND_H
#define GAME_OV128_WF2DMAP_FRIEND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wf2dmap_friend.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov128/wf2dmap_ui_types.h"

int Wf2dmapFriend_Create(void *p,int unused,void *q);
int Wf2dmapFriend_Main(int result,int *stage,int unused,char *p);
int Wf2dmapFriend_Delete(void *p,int a,int b,char *q);
void Wf2dmapFriend_Proc(void *p,char *q);
void Wf2dmapFriend_Setup(char *p,u16 heap);
void Wf2dmapFriend_Teardown(u8 *p);
void Wf2dmapFriend_CreateWindow(void *p,u32 *out,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u32 unused,u8 g);
void Wf2dmapFriend_InitText(u8 *p, const u32 *q, int heap);
void Wf2dmapFriend_DeleteText(u8 *p, void *unused);
void Wf2dmapFriend_SetState(u8 *p, u8 a, u8 b);
void Wf2dmapFriend_CopyText(u8 *p,void *a,void *b);
int Wf2dmapFriend_SubmitFriendKey(char *p,void *q,u32 arg);
void Wf2dmapFriend_SetNameEntry(char *p,int x);
void Wf2dmapFriend_SetIndex(char *p,int x);
void Wf2dmapFriend_BuildEntryList(char *p);
void Wf2dmapFriend_InitGfx(char *p,void *q,u16 heap);
void Wf2dmapFriend_Draw(u8 *p);
void Wf2dmapFriend_VBlank(void *p);
void Wf2dmapFriend_DeleteGfx(u8 *p);
void Wf2dmapFriend_SetVramBanks(void *unused);
void Wf2dmapFriend_InitBg(char *p,u16 heap);
void Wf2dmapFriend_DeleteBg(u8 *unused);
void Wf2dmapFriend_InitActors(char *p,u16 heap);
void Wf2dmapFriend_DeleteActors(char *p);
void Wf2dmapFriend_InitFont(u8 *p, u16 heap);
void Wf2dmapFriend_DeleteFont(u8 *p);
void Wf2dmapFriend_InitWindows(u8 *p,const u8 *q,u16 heap);
void Wf2dmapFriend_DeleteWindows(u8 *p);
void Wf2dmapFriend_LoadBmps(u8 *p,u16 heap);
void Wf2dmapFriend_DeleteBmps(u8 *p);
void Wf2dmapFriend_DrawText(u8 *p,u8 *q,unsigned v);
void Wf2dmapFriend_ClearWindow(u8 *p);
void Wf2dmapFriend_SetFriendCode(void **p,u64 value);
void Wf2dmapFriend_PrintMyStatus(u8 *p,u8 *q,int idx,unsigned heap);
int Wf2dmapFriend_PrintTrainerStats(u8 *p,u8 *q,int idx);
void Wf2dmapFriend_SetWordSlot(char **p, int a);
void Wf2dmapFriend_CreateListActors(char *p,u16 heap);
void Wf2dmapFriend_DeleteListActors(u8 *p);
void Wf2dmapFriend_SetActorDrawEnable(u8 *p,u32 a);
void Wf2dmapFriend_SetActorAutoAnim(u8 *p,u32 a);
void Wf2dmapFriend_RestartActorAnim(u8 *p,int i,u16 a);
void *Wf2dmapFriend_OpenMenu(void *p,void **q,int a,int heap);
int Wf2dmapFriend_UpdateMenu(u8 *p);
void Wf2dmapFriend_InitTopBar(u8 *p,u8 *q,u8 *r,u16 heap);
int Wf2dmapFriend_TopBarMain(u8 *p, u8 *q, u8 *ctx, int heap);
void Wf2dmapFriend_Exit(u8 *p,u8 *q,u8 *ctx);
void Wf2dmapFriend_InitListScreen(Wf2dmapFriendListScreen *p, u8 *a, u8 *ctx, u16 heap);
void Wf2dmapFriend_DeleteListScreen(u8 *p, u8 *unused, u8 *q);
void Wf2dmapFriend_DrawListBg(u8 *p,int *q,u8 *ctx);
int Wf2dmapFriend_ListKeyInput(u32 *p, int *q, u8 *ctx);
int Wf2dmapFriend_ListTouchInput(int *p,int *q,u8 *ctx);
int Wf2dmapFriend_ListInput(int *p,int *q,u8 *r);
void Wf2dmapFriend_SetListState(u32 *p,u8 *q);
void Wf2dmapFriend_ClearListScreen(u8 *p,u8 *q);
void Wf2dmapFriend_PrintMessage(u8 *p,u8 *ctx,unsigned v,unsigned heap);
int Wf2dmapFriend_UpdatePrintStream(void *p, int *q);
int Wf2dmapFriend_CheckPrintStream(void *p,int *q,u8 *r);
void Wf2dmapFriend_ResetListWindow(u8 *p, void *ctx);
int Wf2dmapFriend_HasFreeFriendSlot(int *p,u8 *q);
void Wf2dmapFriend_InitItemScreen(u8 *p,u8 *q,u8 *ctx,u16 value);
int Wf2dmapFriend_ItemScreenMain(u8 *p,u8 *q,u8 *ctx,u16 heap);
void Wf2dmapFriend_DeleteItemScreen(u8 *p,u8 *q,u8 *ctx);
void Wf2dmapFriend_InitItemWidgets(u8 *p, void *unused, u8 *ctx, u16 heap);
void Wf2dmapFriend_DeleteItemWidgets(u8 *p, void *unused, u8 *a);
void Wf2dmapFriend_SetupItemScreen(u8 *p,u8 *q,u8 *r,u16 heap);
void Wf2dmapFriend_ClearItemScreens(u8 *p,void *q,u8 *r);
int Wf2dmapFriend_ItemSelect(s16 *p, u8 *a, void *b, int n);
int Wf2dmapFriend_ItemKeyInput(s16 *p, u8 *a, u8 *ctx);
int Wf2dmapFriend_ItemTouchInput(s16 *p, void *a, void *b, int *changed);
int Wf2dmapFriend_ItemInput(s16 *p,u8 *q,u8 *r);
void Wf2dmapFriend_StartItemOpen(u8 *p, void *a, u8 *b, u16 c);
int Wf2dmapFriend_StepItemOpen(u8 *p, u8 *a, u8 *b, u16 h);
int Wf2dmapFriend_WaitItemOpen(u8 *p,u8 *q);
unsigned long long Wf2dmapFriend_GetEntryFriendKey(s16 *p,u8 *q);
void Wf2dmapFriend_PrintEntryInfo(s16 *p,u8 *q,u8 *r,u16 heap);
void Wf2dmapFriend_OpenEntryMenu(u8 *p, u8 *a, void *unused, int heap);
int Wf2dmapFriend_UpdateEntryMenu(u8 *p, int *a, void *b);
int Wf2dmapFriend_ShowEntryFriendCode(u8 *p, u8 *a, u8 *b, int c);
void Wf2dmapFriend_PrintEntryName(s16 *p,u8 *q,u8 *r,u16 heap);
int Wf2dmapFriend_OpenConfirmMenu(u8 *p,int *q,u8 *r,int heap);
void Wf2dmapFriend_DrawEntry(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c);
void Wf2dmapFriend_DrawEntryOpen(u8 *p, u8 *a, u8 *b, int x, int y, u16 c);
void Wf2dmapFriend_NoopA(void);
void Wf2dmapFriend_NoopB(void);
void Wf2dmapFriend_SetEntryAnim(u8 *p, u8 *a, int n);
void Wf2dmapFriend_PrintEntryMessage(u8 *p, u8 *a, int n, int heap);
int Wf2dmapFriend_CheckEntryPrintStream(void *p,int *state,u8 *q);
void Wf2dmapFriend_ShowEntryDetail(char *p,char *q);
void Wf2dmapFriend_ClearEntryWindow(char *p);
int Wf2dmapFriend_GetEntryIndex(s16 *p);
void Wf2dmapFriend_ShowEntryActor(u8 *p, u8 *unused);
int Wf2dmapFriend_StepEntryActor(u8 *p, u8 *unused);
void Wf2dmapFriend_HideEntryActor(u8 *p, u8 *unused);
void Wf2dmapFriend_CopyPos(u16 *d, u16 *unused, u16 *s, u32 unused2, u16 heap);
void Wf2dmapFriend_NoopC(void *unused0, void *unused1);
void Wf2dmapFriend_DrawEntryBg(s16 *p, void *unused, u8 *q);
void Wf2dmapFriend_DrawEntryPage(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void Wf2dmapFriend_DrawEntryPageTransfer(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap);
void Wf2dmapFriend_ClearEntryPage(char *p, void *unusedArg, void *unused);
void Wf2dmapFriend_DeleteEntryActors(char *p,int unused);
void Wf2dmapFriend_DrawEntrySlot(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap);
void Wf2dmapFriend_CreateEntryActor(char *p,char *q,int unused,int i,u16 h);
int Wf2dmapFriend_NameEntryMain(void **p, u8 *a, u8 *b, void *unused, u16 heap);
/* END mkheaders: generated region */

#endif
