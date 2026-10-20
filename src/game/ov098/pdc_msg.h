#ifndef GAME_OV098_PDC_MSG_H
#define GAME_OV098_PDC_MSG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pdc_msg.c, prototypes copied from their definitions. */

struct PdcMsg;
struct GfFont;
struct Config;
struct Tcbl;
struct PdcArgs;
struct PdcBlend;
struct BmpWin;

#include "../types.h"

struct PdcMsg *PDC_MSG_Create(struct GfFont *font, struct Config *config, struct Tcbl *tcbl, u32 heapId);
void PDC_MSG_Delete(struct PdcMsg *msg);
void PDC_MSG_PrintMessage0(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage3(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage1(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage2(struct PdcMsg *msg, struct PdcArgs *args);
void PDC_MSG_PrintMessage4(struct PdcMsg *msg, struct PdcArgs *args);
int PDC_MSG_Update(struct PdcMsg *msg);
void PDC_MSG_StartFadeIn(struct PdcMsg *msg);
int PDC_MSG_UpdateFade(struct PdcMsg *msg);
int PDC_MSG_TakeStreamEnded(struct PdcMsg *msg);
void PDC_MSG_StartPrint(struct PdcMsg *msg, int waitFrames);
void PDC_MSG_InitBlend(struct PdcBlend *blend, struct BmpWin *window);
void PDC_MSG_BlendStartFadeIn(struct PdcBlend *blend);
void PDC_MSG_BlendStartFadeOut(struct PdcBlend *blend, int keepText);
int PDC_MSG_BlendUpdate(struct PdcBlend *blend);
/* END mkheaders: generated region */

#endif
