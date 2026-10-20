#ifndef GAME_OV209_ZUKAN_LIST_H
#define GAME_OV209_ZUKAN_LIST_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_list.c, prototypes copied from their definitions. */

struct ProcSystem;
struct ZukanList;

#include "../types.h"

int ZUKAN_LIST_ProcInit(struct ProcSystem *p,int unused,unsigned arg);
int ZUKAN_LIST_ProcMain(int unused0, int unused1, int unused2, int work);
int ZUKAN_LIST_ProcExit(void *p);
void ZUKAN_LIST_StartVBlankTask(struct ZukanList *p);
void ZUKAN_LIST_StopVBlankTask(struct ZukanList *p);
void ZUKAN_LIST_VBlankTask(void *unused,struct ZukanList *p);
void ZUKAN_LIST_StartHBlankTask(struct ZukanList *p);
void ZUKAN_LIST_StopHBlankTask(struct ZukanList *p);
void ZUKAN_LIST_HBlankTask(void);
void ZUKAN_LIST_SetVramBanks(void);
void *ZUKAN_LIST_GetVramBankConfig(void);
void ZUKAN_LIST_InitBgSystem(void);
void ZUKAN_LIST_ExitBgSystem(void);
void ZUKAN_LIST_LoadBgGraphics(void);
void ZUKAN_LIST_InitPaletteAnim(struct ZukanList *p);
void ZUKAN_LIST_ExitPaletteAnim(struct ZukanList *p);
void ZUKAN_LIST_RequestFade(struct ZukanList *p, u8 fadeFrom, u8 fadeTo);
void ZUKAN_LIST_SetSubScreenBlendAlpha(void);
void ZUKAN_LIST_EnableSubWindows(void);
void ZUKAN_LIST_DisableSubWindows(void);
void ZUKAN_LIST_CreateFontAndPrinter(struct ZukanList *p);
void ZUKAN_LIST_DeleteFontAndPrinter(struct ZukanList *p);
void ZUKAN_LIST_LoadFormTable(struct ZukanList *p);
void ZUKAN_LIST_FreeFormTable(struct ZukanList *p);
void ZUKAN_LIST_MoveScrollBarActorsIn(struct ZukanList *p);
void ZUKAN_LIST_StartActorMoveFrames(struct ZukanList *p, int delta);
int ZUKAN_LIST_UpdateActorMove(struct ZukanList *p);
void ZUKAN_LIST_CreateFrameList(struct ZukanList *p);
void ZUKAN_LIST_DeleteFrameList(struct ZukanList *p);
void ZUKAN_LIST_FrameListMoveCallback(struct ZukanList *p, int index, int dest, u16 position, int mode);
void ZUKAN_LIST_FrameListSelectCallback(struct ZukanList *p, int index);
void ZUKAN_LIST_ScrollByDelta(struct ZukanList *p,int delta);
int ZUKAN_LIST_RunState(struct ZukanList *p);
int ZUKAN_LIST_StateInit(struct ZukanList *p);
int ZUKAN_LIST_StateExit(struct ZukanList *p);
int ZUKAN_LIST_StateWaitFade(struct ZukanList *p);
int ZUKAN_LIST_StateFadeIn(struct ZukanList *p);
int ZUKAN_LIST_StateMain(struct ZukanList *p);
int ZUKAN_LIST_StateScroll(struct ZukanList *p);
int ZUKAN_LIST_StateScrollWait(struct ZukanList *p);
int ZUKAN_LIST_StateCursorFlash(struct ZukanList *p);
int ZUKAN_LIST_StateFadeOut(struct ZukanList *p);
void ZUKAN_LIST_ResetPaletteSlots(struct ZukanList *p);
int ZUKAN_LIST_StartButtonAnim(struct ZukanList *p,int actorIndex,int animValue,int nextState);
int ZUKAN_LIST_IsSpeciesEntryValid(struct ZukanList *p,int speciesIndex);
void ZUKAN_LIST_StoreLastViewedSpecies(struct ZukanList *p,int speciesIndex);
int ZUKAN_LIST_StateSelectSpecies(struct ZukanList *p, int speciesIndex);
void ZUKAN_LIST_ToggleSaveFlag15(struct ZukanList *p);
void ZUKAN_LIST_CreateWindows(struct ZukanList *p);
void ZUKAN_LIST_DeleteWindows(struct ZukanList *p);
void ZUKAN_LIST_FlushWindows(struct ZukanList *p);
void ZUKAN_LIST_PrintTouchbarLabel(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);
void ZUKAN_LIST_PrintTouchbarLabelClone(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);
void ZUKAN_LIST_MakeWindowScreens(void **p);
void ZUKAN_LIST_ClearWindow(struct ZukanList *p, u32 windowIndex);
void ZUKAN_LIST_DrawHeaderRegional(struct ZukanList *p);
void ZUKAN_LIST_DrawHeaderCounts(struct ZukanList *p);
void ZUKAN_LIST_DrawHeaderNational(struct ZukanList *p);
void ZUKAN_LIST_PrintListRow(struct ZukanList *p, unsigned char *dest, unsigned text0, unsigned index);
void ZUKAN_LIST_InitActors(struct ZukanList *p);
void ZUKAN_LIST_ExitActors(struct ZukanList *list);
void ZUKAN_LIST_UpdateActors(struct ZukanList *p);
void ZUKAN_LIST_SetActorAnim(struct ZukanList *p, int actorIndex, int animValue);
void ZUKAN_LIST_StartActorAnim(struct ZukanList *p,int actorIndex,int value);
int ZUKAN_LIST_GetActorAnimSeq(struct ZukanList *p, int actorIndex);
u32 ZUKAN_LIST_IsActorAnimActive(struct ZukanList *p,u32 actorIndex);
void ZUKAN_LIST_SetActorVisible(struct ZukanList *p,u32 actorIndex,u32 value);
u32 ZUKAN_LIST_GetActorVisible(struct ZukanList *p,u32 actorIndex);
void ZUKAN_LIST_SetActorObjMode(struct ZukanList *p,u32 actorIndex,u32 flag);
void ZUKAN_LIST_AddActorPos(struct ZukanList *p, int actorIndex, short x, short y, unsigned short surface);
void ZUKAN_LIST_GetActorPos(struct ZukanList *p,u32 actorIndex,s16 *x,s16 *y,u16 space);
void ZUKAN_LIST_InitActorSystem(struct ZukanList *p);
void ZUKAN_LIST_LoadActorResources(struct ZukanList *p);
void ZUKAN_LIST_ReleaseActorResources(struct ZukanList *p);
void ZUKAN_LIST_CreateActors(struct ZukanList *p);
void ZUKAN_LIST_DeleteActor(struct ZukanList *p,u32 actorIndex);
void ZUKAN_LIST_DeleteActorUnit(struct ZukanList *p);
void ZUKAN_LIST_LoadSpeciesIcon(struct ZukanList *p,u16 species);
void ZUKAN_LIST_UpdateSpeciesActors(struct ZukanList *p);
void ZUKAN_LIST_TransferSpeciesGraphics(struct ZukanList *p, int actorIndex, unsigned species, u16 form, u16 charHalf, int mode);
int ZUKAN_LIST_FindHiddenSpeciesActor(struct ZukanList *list, int group);
void ZUKAN_LIST_ScrollActorsBy(struct ZukanList *p, int delta);
void ZUKAN_LIST_HideAllActors(struct ZukanList *p);
void ZUKAN_LIST_ShowAllActors(struct ZukanList *p);
void ZUKAN_LIST_MoveCursorActor(struct ZukanList *p,int index);
void ZUKAN_LIST_UpdateScrollBarActor(struct ZukanList *p);
void ZUKAN_LIST_UpdateArrowActors(struct ZukanList *p,int flag);
int ZUKAN_LIST_HandleTouchInput(struct ZukanList *p);
/* END mkheaders: generated region */

#endif
