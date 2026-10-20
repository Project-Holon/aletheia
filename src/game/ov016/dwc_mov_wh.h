#ifndef GAME_OV016_DWC_MOV_WH_H
#define GAME_OV016_DWC_MOV_WH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_mov_wh.c, prototypes copied from their definitions. */

#include "../types.h"

void DWCi_MOV_WH_MemInit(void *mw);
void DWCi_MOV_WH_SetError(unsigned int v);
int DWCi_MOV_WH_StateInSetParentParam(void);
int DWCi_MOV_WH_StateInStartParentKeyShare(void);
int DWCi_MOV_WH_StateInEndParentKeyShare(void);
int DWCi_MOV_WH_StateInEndChildKeyShare(void);
void DWCi_MOV_WH_SetGgid(unsigned int v);
unsigned short DWCi_MOV_WH_GetBitmap(void);
unsigned int DWCi_MOV_WH_GetSystemState(void);
int DWCi_MOV_WH_StartMeasureChannel(void);
unsigned short DWCi_MOV_WH_GetMeasureChannel(void);
int DWCi_MOV_WH_Initialize(void);
int DWCi_MOV_WH_StateInInitialize(void);
int DWCi_MOV_WH_ParentConnect(int mode, unsigned short tgid, unsigned short channel);
void DWCi_MOV_WH_SetJudgeAcceptFunc(unsigned int v);
u16 *DWCi_MOV_WH_GetSharedDataAdr(u16 a);
int DWCi_MOV_WH_StepDS(void *data);
void DWCi_MOV_WH_Reset(void);
void DWCi_MOV_WH_Finalize(void);
int DWCi_MOV_WH_End(void);
/* END mkheaders: generated region */

#endif
