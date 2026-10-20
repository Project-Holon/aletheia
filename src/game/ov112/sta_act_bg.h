#ifndef GAME_OV112_STA_ACT_BG_H
#define GAME_OV112_STA_ACT_BG_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_bg.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov112/sta_act_types.h"

u8 *STA_ACT_LIGHT_AllocElem(u32 heap,u32 v);
void STA_ACT_LIGHT_DeleteModel(u8 *p);
void STA_ACT_LIGHT_StepModelAnim(u8 *p);
void STA_ACT_LIGHT_DrawModel(u8 *p);
void STA_ACT_LIGHT_CreateModel(StaActLightModel *p, u32 id);
void STA_ACT_LIGHT_FreeModel(StaActLightModel *p);
void STA_ACT_LIGHT_SetModelFrame(u8 *p, u16 v);
/* END mkheaders: generated region */

#endif
