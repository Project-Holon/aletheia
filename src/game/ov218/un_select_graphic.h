#ifndef GAME_OV218_UN_SELECT_GRAPHIC_H
#define GAME_OV218_UN_SELECT_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of un_select_graphic.c, prototypes copied from their definitions. */

struct TcbTask;

#include "../types.h"

char *UN_SELECT_GRAPHIC_Create(unsigned swap, unsigned heap);
void UN_SELECT_GRAPHIC_Delete(char *ctx);
void UN_SELECT_GRAPHIC_Update(char *p);
u32 UN_SELECT_GRAPHIC_GetActor(char *p);
void UN_SELECT_GRAPHIC_Task(struct TcbTask *unused, void *work_);
void UN_SELECT_GRAPHIC_SetupBg(char *ctx, unsigned heap);
void UN_SELECT_GRAPHIC_CleanupBg(void *p);
void UN_SELECT_GRAPHIC_Noop(void *work);
void UN_SELECT_GRAPHIC_DrawObjects(void *work);
void UN_SELECT_GRAPHIC_SetupClact(unsigned char *p, struct DispVramCfg *a, int b);
void UN_SELECT_GRAPHIC_DeleteClact(char *p);
void UN_SELECT_GRAPHIC_Draw(void *p);
void UN_SELECT_GRAPHIC_VBlank(void *p);
u32 UN_SELECT_GRAPHIC_GetValue(u32 *p);
void UN_SELECT_GRAPHIC_SetupCamera(unsigned **out, unsigned heap);
void UN_SELECT_GRAPHIC_DeleteCamera(int *p);
/* END mkheaders: generated region */

#endif
