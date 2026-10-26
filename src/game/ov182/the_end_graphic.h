#ifndef GAME_OV182_THE_END_GRAPHIC_H
#define GAME_OV182_THE_END_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of the_end_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

int THE_END_GRAPHIC_Init(void *task, int b, int c);
int THE_END_GRAPHIC_Exit(void *task, int b, int c, char *p);
int THE_END_GRAPHIC_Main(void *a, unsigned *state, void *c, char *p);
void THE_END_GRAPHIC_DummyTask(struct TcbTask *unused, void *work);
void THE_END_GRAPHIC_LoadGraphics(unsigned short *p);
void THE_END_GRAPHIC_Dummy(void *p);
void THE_END_GRAPHIC_StartFade(int a, int b, int c);
void THE_END_GRAPHIC_Setup3d(void);
char *THE_END_GRAPHIC_Create(int a, u16 heap);
void THE_END_GRAPHIC_Delete(char *p);
void THE_END_GRAPHIC_Update(char *p);
void THE_END_GRAPHIC_VBlankTask(struct TcbTask *unused, void *p);
void THE_END_GRAPHIC_InitWindows(void *p, u16 heap);
void THE_END_GRAPHIC_ExitWindows(void *p);
void THE_END_GRAPHIC_Dummy2(void *p);
void THE_END_GRAPHIC_RefreshDisplay(void *unused);
void THE_END_GRAPHIC_InitActors(void **p, struct DispVramCfg *b, int c);
void THE_END_GRAPHIC_DeleteActors(void *p);
void THE_END_GRAPHIC_DrawActors(void *unused);
void THE_END_GRAPHIC_VBlankActors(void *unused);
void THE_END_GRAPHIC_InitCamera(void **p,u16 heap);
void THE_END_GRAPHIC_DeleteCamera(void **p);
/* END mkheaders: generated region */

#endif
