#ifndef GAME_OV132_STA_ACT_EFFECT_H
#define GAME_OV132_STA_ACT_EFFECT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_effect.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov132/sta_acting_shared_types.h"

void STA_ACTING_SetCameraHoldScript(u8 *p,u32 hold);
u32 STA_ACTING_GetElapsedTicks(u8 *p);
void STA_ACT_EFFECT_Noop(u8 *scene);
char *STA_ACT_EFFECT_Create(unsigned heap);
void STA_ACT_EFFECT_Delete(u8 *p);
int STA_ACT_EFFECT_Update(u8 *manager);
int STA_ACT_EFFECT_Draw(u8 *manager);
char *STA_ACT_EFFECT_StartSystem(char *p, u32 memberIndex);
void STA_ACT_EFFECT_KillSystem(u8 *unused,u8 *p);
void STA_ACT_EFFECT_StartEffect(char *p, unsigned index, StaActingVec *pos);
void STA_ACT_EFFECT_KillEffect(char *p, int index);
void STA_ACT_EFFECT_SetEmitterPos(char *p, int index, int position);
/* END mkheaders: generated region */

#endif
