#ifndef GAME_OV186_BR_BTN_DATA_H
#define GAME_OV186_BR_BTN_DATA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_btn_data.c, prototypes copied from their definitions. */

struct BrBtnTable;
struct MsgBank;

#include "../types.h"

void *BR_BTN_DATA_Create(int *configPtr, u16 heapId);
void BR_BTN_DATA_Delete(void *table);
void BR_BTN_DATA_Fill(struct BrBtnTable *table);
void *BR_BTN_DATA_GetRow(struct BrBtnTable *table, int section, unsigned item);
unsigned short BR_BTN_DATA_GetSectionCount(void *table, int section);
unsigned BR_BTN_DATA_GetMaxSectionCount(void *table);
int BR_BTN_DATA_GetRowField(void *record,int fieldIndex);
void *BR_BTN_DATA_CreateLabel(unsigned *const *wordSetSrc,void *record,struct MsgBank *archive,unsigned short heapId);
/* END mkheaders: generated region */

#endif
