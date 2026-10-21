#ifndef GAME_OV222_ZENKOKU_ZUKAN_AWARD_GRAPHIC_H
#define GAME_OV222_ZENKOKU_ZUKAN_AWARD_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zenkoku_zukan_award_graphic.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../types.h"

void*ZENKOKU_ZUKAN_AWARD_GRAPHIC_Create(u32 swap,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Delete(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Update(char *p);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetActor(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Task(struct TcbTask *unused, void *work_);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupBg(void *p,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_CleanupBg(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Noop(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DrawObjects(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupClact(unsigned char *p, int a, int b);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteClact(char *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_Draw(void *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_VBlank(void *p);
u32 ZENKOKU_ZUKAN_AWARD_GRAPHIC_GetValue(const u32 *p);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_SetupCamera(u32 **out,u32 heap);
void ZENKOKU_ZUKAN_AWARD_GRAPHIC_DeleteCamera(u32 *p);
/* END mkheaders: generated region */

#endif
