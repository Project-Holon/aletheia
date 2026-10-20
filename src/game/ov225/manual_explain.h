#ifndef GAME_OV225_MANUAL_EXPLAIN_H
#define GAME_OV225_MANUAL_EXPLAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_explain.c, prototypes copied from their definitions. */

#include "../types.h"

char *MANUAL_CATEGORY_CreateOption(char *p, char *data);
void MANUAL_CATEGORY_DeleteOption(char *p);
int MANUAL_CATEGORY_UpdateOption(char *p);
void MANUAL_CATEGORY_OptionTaskNoop(void *p);
void MANUAL_CATEGORY_LoadOptionAssets(char *p);
void MANUAL_CATEGORY_SetOptionBgMode(char *work);
void MANUAL_CATEGORY_OptionNoop(char *work);
void MANUAL_CATEGORY_CreateOptionSlots(u8 *p);
void MANUAL_CATEGORY_DeleteOptionSlots(char *p);
void MANUAL_CATEGORY_UpdateOptionSlots(u8 *p);
void MANUAL_CATEGORY_DrawOption(char *p);
/* END mkheaders: generated region */

#endif
