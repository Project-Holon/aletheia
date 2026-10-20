#ifndef GAME_OV021_FIELD_BBD_COLOR_H
#define GAME_OV021_FIELD_BBD_COLOR_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of field_bbd_color.c, prototypes copied from their definitions. */

struct FieldBbdColor;
typedef struct FieldBbdColor FieldBbdColor;

#include "../types.h"

FieldBbdColor *FIELD_BBD_COLOR_Create(u32 heapId);
int FIELD_BBD_COLOR_Delete(FieldBbdColor *bbdColor);
void FIELD_BBD_COLOR_Load(FieldBbdColor *bbdColor, u32 colorId);
void FIELD_BBD_COLOR_Apply(FieldBbdColor *bbdColor, void *bbdSys);
/* END mkheaders: generated region */

#endif
