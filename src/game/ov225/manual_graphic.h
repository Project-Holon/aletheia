#ifndef GAME_OV225_MANUAL_GRAPHIC_H
#define GAME_OV225_MANUAL_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of manual_graphic.c, prototypes copied from their definitions. */

struct ManualGraphicArgs;
struct Unit;
struct DispVramCfg;

#include "../types.h"

int MANUAL_GRAPHIC_Init(void *proc, void *unused, struct ManualGraphicArgs *args);
int MANUAL_GRAPHIC_Exit(void *proc, void *unusedA, void *unusedB, char *work);
int MANUAL_GRAPHIC_Main(void *unusedA,u32 *state,void *unused,char *work);
void MANUAL_GRAPHIC_TaskNoop(void *unused, char *work);
void *MANUAL_GRAPHIC_CreateScreen(u32 swap, u32 heap);
void MANUAL_GRAPHIC_DeleteScreen(char *screen);
void MANUAL_GRAPHIC_DrawScreen(char *screen);
struct Unit *MANUAL_GRAPHIC_GetClactUnit(const u8 *screen);
void MANUAL_GRAPHIC_VBlankScreen(void *unused, char *screen);
void MANUAL_GRAPHIC_CreateBg(void *screen, u32 heap);
void MANUAL_GRAPHIC_DeleteBg(void *screen);
void MANUAL_GRAPHIC_DrawBg(void *unused);
void MANUAL_GRAPHIC_VBlankBg(void *unused);
void MANUAL_GRAPHIC_CreateClactUnit(unsigned char *clact, struct DispVramCfg *arg, int heap);
void MANUAL_GRAPHIC_DeleteClactUnit(char *clact);
void MANUAL_GRAPHIC_DrawClactUnit(void *unused);
void MANUAL_GRAPHIC_VBlankClactUnit(void *unused);
struct Unit *MANUAL_GRAPHIC_GetUnitHandle(struct Unit *const *handle);
/* END mkheaders: generated region */

#endif
