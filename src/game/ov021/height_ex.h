#ifndef GAME_OV021_HEIGHT_EX_H
#define GAME_OV021_HEIGHT_EX_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of height_ex.c, prototypes copied from their definitions. */

#include "../ov021/height_ex_types.h"
#include "../types.h"

int HEIGHT_EX_IsPointInArea(int x, int z, const HeightExArea *area, int areaIndex);
HeightExTable *HEIGHT_EX_CreateTable(u32 count, u32 heapId);
void HEIGHT_EX_SetArea(int index, int x, int z, int width, int depth, int height, int attr, HeightExTable *table);
void HEIGHT_EX_FreeTable(HeightExTable *table);
int HEIGHT_EX_GetAreaCount(const HeightExTable *table);
int HEIGHT_EX_IsPointInAreaAt(int x, int z, const HeightExTable *table, u8 index);
int HEIGHT_EX_GetAreaHeight(u8 index, const HeightExTable *table);
int HEIGHT_EX_GetAreaAttr(u8 index, const HeightExTable *table);
void HEIGHT_EX_SetAreaHeight(u8 index, int height, HeightExTable *table);
/* END mkheaders: generated region */

#endif
