#ifndef GAME_OV131_P_STA_OAM_H
#define GAME_OV131_P_STA_OAM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of p_sta_oam.c, prototypes copied from their definitions. */

struct StaOamManager;
struct Unit;
struct StaOamBitmapActors;
struct StaOamBitmapDesc;

#include "../types.h"

struct StaOamManager *P_STA_OAM_CreateManager(u32 heapId, struct Unit *clunit);
void P_STA_OAM_DeleteManager(struct StaOamManager *mgr);
struct StaOamBitmapActors *P_STA_OAM_CreateBitmapActors(struct StaOamManager *mgr, const struct StaOamBitmapDesc *desc);
void P_STA_OAM_DeleteBitmapActors(struct StaOamBitmapActors *grid);
void P_STA_OAM_SetBitmapActorsEnabled(struct StaOamBitmapActors *grid, int enable);
void P_STA_OAM_TransferBitmap(struct StaOamBitmapActors *grid);
void P_STA_OAM_SetBitmapActorsPos(struct StaOamBitmapActors *grid, s16 x, s16 y);
void P_STA_OAM_SwapInts(int *a, int *b);
int P_STA_OAM_GetCellResMode(struct StaOamManager *mgr, int screen, void *arc);
void P_STA_OAM_FreeCellRes(struct StaOamManager *mgr);
u32 P_STA_RIBBON_GetRibbonInfo(u32 index, u32 field);
unsigned int P_STA_RIBBON_GetRibbonDescMsg(int ribbonNo);
/* END mkheaders: generated region */

#endif
