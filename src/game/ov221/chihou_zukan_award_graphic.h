#ifndef GAME_OV221_CHIHOU_ZUKAN_AWARD_GRAPHIC_H
#define GAME_OV221_CHIHOU_ZUKAN_AWARD_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of chihou_zukan_award_graphic.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../types.h"

void*CHIHOU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Delete(char*p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
unsigned CHIHOU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Task(struct TcbTask *unused, void *work_);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupBg(void*p,u32 heap);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Noop(void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, int a, int b);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_Draw(void *work);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p);
unsigned CHIHOU_ZUKAN_AWARD_GRAPHIC_GetValue(unsigned *p);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32**p,u32 heap);
void CHIHOU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(int *p);
/* END mkheaders: generated region */

#endif
