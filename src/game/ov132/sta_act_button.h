#ifndef GAME_OV132_STA_ACT_BUTTON_H
#define GAME_OV132_STA_ACT_BUTTON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sta_act_button.c, prototypes copied from their definitions. */

#include "../types.h"

char *STA_ACT_BUTTON_Create(unsigned heap, void *scene, char *playerRecord);
void STA_ACT_BUTTON_Delete(char *p);
void STA_ACT_BUTTON_Update(char *p);
void STA_ACT_BUTTON_CreateActors(char *p);
void STA_ACT_BUTTON_LoadCharacter(u8 *p,u16 slot,int resource,u32 type);
void STA_ACT_BUTTON_SetVisible(char *p, unsigned flag);
/* END mkheaders: generated region */

#endif
