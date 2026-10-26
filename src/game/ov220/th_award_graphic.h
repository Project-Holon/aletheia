#ifndef GAME_OV220_TH_AWARD_GRAPHIC_H
#define GAME_OV220_TH_AWARD_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of th_award_graphic.c, prototypes copied from their definitions. */

struct Unit;
struct DispVramCfg;

#include "../types.h"

void *TH_AWARD_GRAPHIC_Create(unsigned mode,unsigned heap);
void TH_AWARD_GRAPHIC_Delete(unsigned char *p);
void TH_AWARD_GRAPHIC_Update(char *p);
struct Unit *TH_AWARD_GRAPHIC_GetActor(u8*p);
void TH_AWARD_GRAPHIC_Task(void *unused, char *p);
void TH_AWARD_GRAPHIC_SetupBg(void *p, unsigned heap);
void TH_AWARD_GRAPHIC_CleanupBg(void*p);
void TH_AWARD_GRAPHIC_Noop(void *p);
void TH_AWARD_GRAPHIC_DrawObjects(void *p);
void TH_AWARD_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b);
void TH_AWARD_GRAPHIC_DeleteClact(char *p);
void TH_AWARD_GRAPHIC_Draw(void *p);
void TH_AWARD_GRAPHIC_VBlank(void *p);
struct Unit *TH_AWARD_GRAPHIC_GetValue(u32*p);
/* END mkheaders: generated region */

#endif
