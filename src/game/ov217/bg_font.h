#ifndef GAME_OV217_BG_FONT_H
#define GAME_OV217_BG_FONT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of bg_font.c, prototypes copied from their definitions. */

struct BgTextLabel;
struct BgTextLabelConfig;

#include "../types.h"

struct BgTextLabel *BgTextLabel_Create(const struct BgTextLabelConfig *config, u32 font, u32 msgBank, u32 heapId);
void BgTextLabel_Destroy(struct BgTextLabel *label);
u32 BgTextLabel_PrintMessage(struct BgTextLabel *label, u32 msgIndex);
void BgTextLabel_PrintText(struct BgTextLabel *label, void *text);
void BgTextLabel_SetVisible(struct BgTextLabel *label, int visible);
void BgTextLabel_SetPalette(struct BgTextLabel *label, u8 palette);
int BgTextLabel_GetCenterOffset(struct BgTextLabel *label, void *text);
/* END mkheaders: generated region */

#endif
