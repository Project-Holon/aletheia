#ifndef GAME_OV131_P_STATUS_H
#define GAME_OV131_P_STATUS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of p_status.c, prototypes copied from their definitions. */

struct BgSetup;
struct Bmp;
struct BmpWin;

#include "../ov131/p_status_types.h"
#include "../types.h"

struct TcbTask;

int P_STATUS_InitWork(PStatusWork *wk);
int P_STATUS_ExitWork(PStatusWork *wk);
int P_STATUS_MainSeq(PStatusWork *wk);
void P_STATUS_VBlankTask(struct TcbTask *unused0, void *unused1);
void P_STATUS_InitGraphics(PStatusWork *wk);
void P_STATUS_ExitGraphics(PStatusWork *wk);
void P_STATUS_InitBgLayer(struct BgSetup *cfg,u8 bg,u32 mode);
void P_STATUS_LoadObjResource(PStatusWork *wk);
void P_STATUS_DeleteObjResource(PStatusWork *wk);
void P_STATUS_CreateButtonActors(PStatusWork *wk);
void P_STATUS_DeleteButtonActors(PStatusWork *wk);
void P_STATUS_InitMessage(PStatusWork *wk);
void P_STATUS_ExitMessage(PStatusWork *wk);
void P_STATUS_UpdateTouch(PStatusWork *wk);
void P_STATUS_UpdateInput(PStatusWork *wk);
int P_STATUS_CheckKey(PStatusWork *wk);
void P_STATUS_CheckTouch(PStatusWork *wk);
s32 P_STATUS_UpdatePaletteAnime(PStatusWork *wk);
void P_STATUS_SetInputEnable(PStatusWork *wk,int enable);
int P_STATUS_ChangePokemon(PStatusWork *wk,int direction);
int P_STATUS_SearchPokemon(PStatusWork *wk,int direction,unsigned short *out);
void P_STATUS_LoadPokemonState(PStatusWork *wk);
void P_STATUS_RequestRefresh(PStatusWork *wk);
void P_STATUS_UpdateRefresh(PStatusWork *wk);
void *P_STATUS_GetPokePara(PStatusWork *wk);
void *P_STATUS_GetPokeParaSource(PStatusWork *wk);
void P_STATUS_SetParamDecoded(PStatusWork *wk,int fastMode);
void P_STATUS_PrintMsg(PStatusWork *wk,struct Bmp *bmpWin,int msgId,int x,unsigned short y,unsigned short color);
void P_STATUS_PrintMsgToWin(PStatusWork *wk, struct BmpWin *bmpWinData, int msgId, int x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsg(PStatusWork *wk,struct Bmp *bmpWin,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color);
void P_STATUS_PrintWordSetMsgToWin(PStatusWork *wk, struct BmpWin *bmpWinData, void *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);
void P_STATUS_PrintWordSetMsgRight(PStatusWork *wk,struct Bmp *bmpWin,void *wordSet,int msgId,unsigned short x,unsigned short y,unsigned short color);
void P_STATUS_PrintWordSetMsgRightToWin(PStatusWork *wk, struct BmpWin *bmpWinData, void *wordSet, int msgId, unsigned short x, unsigned short y, unsigned short color);
int P_STATUS_CanUseButtons(PStatusWork *wk);
int P_STATUS_HasRibbon(PStatusWork *wk, void *pp);
int P_STATUS_ProcInit(void *proc,int *seq,PStatusProcParam *pwk,PStatusWork *mywk);
int P_STATUS_ProcExit(void *proc, int *seq, PStatusProcParam *pwk, PStatusWork *mywk);
int P_STATUS_ProcMain(void *proc, int *seq, PStatusProcParam *pwk, PStatusWork *mywk);
/* END mkheaders: generated region */

#endif
