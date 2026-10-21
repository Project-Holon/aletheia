#ifndef GAME_OV224_SUBWAY_MAP_GRAPHIC_H
#define GAME_OV224_SUBWAY_MAP_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of subway_map_graphic.c, prototypes copied from their definitions. */

struct Proc;
struct TcbTask;

#include "../types.h"

int SUBWAY_MAP_GRAPHIC_Init(struct Proc *proc,void *unused,void **args);
int SUBWAY_MAP_GRAPHIC_Exit(void *a,int b,int c,char *p);
int SUBWAY_MAP_GRAPHIC_Main(void *a,unsigned *state,int b,char *p);
void SUBWAY_MAP_GRAPHIC_TaskNoop(struct TcbTask *unused, void *unused2);
void SUBWAY_MAP_GRAPHIC_LoadCommonAssets(u16 *work);
void SUBWAY_MAP_GRAPHIC_ReleaseCommonAssets(char *unused);
void SUBWAY_MAP_GRAPHIC_Setup3d(void);
void *SUBWAY_MAP_GRAPHIC_CreateScreen(u32 swap, u32 heap);
void SUBWAY_MAP_GRAPHIC_DeleteScreen(char *p);
void SUBWAY_MAP_GRAPHIC_DrawScreen(void *p);
void SUBWAY_MAP_GRAPHIC_VBlankScreen(struct TcbTask *unused, void *work_);
void SUBWAY_MAP_GRAPHIC_CreateBg(void *p, u32 heap);
void SUBWAY_MAP_GRAPHIC_DeleteBg(void *p);
void SUBWAY_MAP_GRAPHIC_DrawBg(void *work);
void SUBWAY_MAP_GRAPHIC_VBlankBg(void *work);
void SUBWAY_MAP_GRAPHIC_CreateClactUnit(unsigned char *p, struct DispVramCfg *a, int b);
void SUBWAY_MAP_GRAPHIC_DeleteClactUnit(char *p);
void SUBWAY_MAP_GRAPHIC_DrawClactUnit(void *work);
void SUBWAY_MAP_GRAPHIC_VBlankClactUnit(void *work);
void SUBWAY_MAP_GRAPHIC_CreateCamera(void **p,u32 heap);
void SUBWAY_MAP_GRAPHIC_DeleteCamera(u32 *p);
/* END mkheaders: generated region */

#endif
