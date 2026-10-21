#ifndef GAME_OV207_ZUKAN_TOROKU_GRAPHIC_H
#define GAME_OV207_ZUKAN_TOROKU_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_toroku_graphic.c, prototypes copied from their definitions. */

struct ZukanTorokuWork;
struct ZukanTorokuDisplay;
struct Unit;
struct TcbTask;
typedef struct ZukanTorokuWork ZukanTorokuWork;
typedef struct ZukanTorokuDisplay ZukanTorokuDisplay;

#include "../types.h"

int ZUKAN_TOROKU_GRAPHIC_Init(void *owner,int unused,u32 *args);
int ZUKAN_TOROKU_GRAPHIC_Exit(void *a,int b,int c,ZukanTorokuWork *work);
int ZUKAN_TOROKU_GRAPHIC_Main(void *unused,int unused2,u32 *args,ZukanTorokuWork *work);
void ZUKAN_TOROKU_GRAPHIC_CreateBg(ZukanTorokuWork *work);
void ZUKAN_TOROKU_GRAPHIC_DeleteBg(ZukanTorokuWork *work);
void ZUKAN_TOROKU_GRAPHIC_ClearTask(struct TcbTask *task, void *taskWork);
void *ZUKAN_TOROKU_GRAPHIC_CreateDisplay(int a,int heap);
void ZUKAN_TOROKU_GRAPHIC_DeleteDisplay(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_Draw(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_Update(void *unused);
void ZUKAN_TOROKU_GRAPHIC_UpdateSub(void *unused);
u32 ZUKAN_TOROKU_GRAPHIC_GetDisplay(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_VBlank(struct TcbTask *task, void *taskWork);
void ZUKAN_TOROKU_GRAPHIC_InitBg(ZukanTorokuDisplay *display,int heap);
void ZUKAN_TOROKU_GRAPHIC_ExitBg(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_UpdateBg(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_ResetDisplay(ZukanTorokuDisplay *display);
void ZUKAN_TOROKU_GRAPHIC_InitActors(struct Unit **actors, int a, int b);
void ZUKAN_TOROKU_GRAPHIC_DeleteActors(struct Unit**p);
void ZUKAN_TOROKU_GRAPHIC_DrawActors(void*p);
void ZUKAN_TOROKU_GRAPHIC_VBlankActors(void*p);
u32 ZUKAN_TOROKU_GRAPHIC_GetWord(u32*p);
/* END mkheaders: generated region */

#endif
