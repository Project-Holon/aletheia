#ifndef GAME_OV194_NAMEIN_GRAPHIC_MAIN_H
#define GAME_OV194_NAMEIN_GRAPHIC_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of namein_graphic_main.c, prototypes copied from their definitions. */

struct Proc;
struct Unit;
struct NameinGraphicMainRect;
typedef struct NameinGraphicMainRect NameinGraphicMainRect;

#include "../types.h"
#include "../ov010/namein_args.h"

u32 NAMEIN_GRAPHIC_Create(struct Proc *a, u32 b, NameInArgs *args);
int NAMEIN_GRAPHIC_Delete(void *a,u32 b,u32 c,u8 *d);
int NAMEIN_GRAPHIC_Main(int a,int b,int c,u8 *p);
void NAMEIN_GRAPHIC_LoadBgPalette(void *unused,u16 heap);
void NAMEIN_GRAPHIC_UpdateBg(void *unused);
void NAMEIN_GRAPHIC_CreateActors(char *p,struct Unit *owner,u16 heap);
void NAMEIN_GRAPHIC_DeleteActors(u8 *p);
void *NAMEIN_GRAPHIC_GetActor(u8 *p,u32 i);
void NAMEIN_GRAPHIC_InitCursor(u8 *a,int b,void *c,u32 d);
void NAMEIN_GRAPHIC_ClearCursor(void *p);
void NAMEIN_GRAPHIC_SetupCursor(char *p,int mode,const NameinGraphicMainRect *rect,int flag,int selected);
void NAMEIN_GRAPHIC_UpdateCursor(char *p, int sel, const void *rect);
/* END mkheaders: generated region */

#endif
