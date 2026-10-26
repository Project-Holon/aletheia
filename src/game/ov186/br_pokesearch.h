#ifndef GAME_OV186_BR_POKESEARCH_H
#define GAME_OV186_BR_POKESEARCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_pokesearch.c, prototypes copied from their definitions. */

struct BrPokeSearch;
struct ZukanSave;
struct BrRes;
struct Unit;
struct BrFade;
struct BrTapFx;

#include "../types.h"

struct BrPokeSearch *BR_POKESEARCH_Create(struct ZukanSave *zukan, struct BrRes *res, struct Unit *uiParamA, void *uiParamB, struct BrFade *fade, void *listParam, struct BrTapFx *tapFx, unsigned short heapId);
void BR_POKESEARCH_Destroy(struct BrPokeSearch *ps);
int BR_POKESEARCH_Main(struct BrPokeSearch *ps);
unsigned BR_POKESEARCH_UpdatePrint(struct BrPokeSearch *ps);
void BR_POKESEARCH_Open(struct BrPokeSearch *ps);
void BR_POKESEARCH_Close(struct BrPokeSearch *ps);
int BR_POKESEARCH_GetResult(struct BrPokeSearch *ps, unsigned short *speciesOut);
void BR_POKESEARCH_CreateBackButton(struct BrPokeSearch *ps);
void BR_POKESEARCH_DestroyBackButton(struct BrPokeSearch *ps);
void BR_POKESEARCH_CreateGroupWindows(struct BrPokeSearch *ps);
void BR_POKESEARCH_DestroyGroupWindows(struct BrPokeSearch *ps);
void BR_POKESEARCH_CreateSpeciesList(struct BrPokeSearch *ps);
void BR_POKESEARCH_DestroySpeciesList(struct BrPokeSearch *ps);
int BR_POKESEARCH_PollGroupTouch(struct BrPokeSearch *ps);
int BR_POKESEARCH_HasSeenInGroup(struct ZukanSave *zukan, u32 group, const u16 *speciesTable);
u16 *BR_POKESEARCH_BuildSeenList(struct ZukanSave *zukan, u32 group, const u16 *speciesTable, u32 *countOut, u16 heapId);
/* END mkheaders: generated region */

#endif
