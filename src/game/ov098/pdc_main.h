#ifndef GAME_OV098_PDC_MAIN_H
#define GAME_OV098_PDC_MAIN_H

struct PdcSys *PDC_MAIN_Create(struct PdcArgs *args, u16 heapId);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdc_main.c, prototypes copied from their definitions. */

struct PdcSys;
struct PdcArgs;

#include "../types.h"
#include "../ov098/pdc_types.h"

struct PdcSys *PDC_MAIN_Create(struct PdcArgs *args, u16 heapId);
int PDC_MAIN_Update(struct PdcSys *sys);
void PDC_MAIN_Delete(struct PdcSys *sys);
void PDC_MAIN_SetStep(struct PdcSys *sys, PdcStep step);
void PDC_MAIN_InitGraphics(u16 heapId);
void PDC_MAIN_ExitGraphics(void);
int PDC_MAIN_StepIntro(struct PdcSys *sys);
int PDC_MAIN_StepConfirm(struct PdcSys *sys);
int PDC_MAIN_StepChooseItem(struct PdcSys *sys);
int PDC_MAIN_StepDeclined(struct PdcSys *sys);
void PDC_MAIN_StartFadeIn(int speed);
/* END mkheaders: generated region */

#endif
