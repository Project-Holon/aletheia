#ifndef GAME_OV172_DRAW_SYSTEM_H
#define GAME_OV172_DRAW_SYSTEM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of draw_system.c, prototypes copied from their definitions. */

struct DrawCanvas;
struct DrawCanvasParams;
struct DrawStroke;
typedef struct DrawCanvas DrawCanvas;
typedef struct DrawCanvasParams DrawCanvasParams;
typedef struct DrawStroke DrawStroke;

#include "../types.h"

DrawCanvas *DRAW_SYSTEM_CreateCanvas(DrawCanvasParams *params);
void DRAW_SYSTEM_DeleteCanvas(DrawCanvas *canvas);
void DRAW_SYSTEM_Nop(u32 unused);
void DRAW_SYSTEM_FlushStrokes(DrawCanvas *canvas);
void DRAW_SYSTEM_DrawStroke(DrawCanvas *canvas, const DrawStroke *stroke);
void DRAW_SYSTEM_DrawLine(DrawCanvas *canvas, u16 *plane, int x0, int x1, u16 y0, u16 y1, int brushIdx, u16 color);
void DRAW_SYSTEM_PutPixel(DrawCanvas *canvas, u16 *plane, u16 x, u16 y, unsigned short color);
void DRAW_SYSTEM_PushStroke(DrawCanvas *canvas, void *stroke);
void DRAW_SYSTEM_SetQueueIndex(DrawCanvas *canvas, u16 index);
void *DRAW_SYSTEM_GetPlane(void);
DrawStroke *DRAW_SYSTEM_GetStroke(DrawCanvas *canvas, int i);
void DRAW_SYSTEM_AdvanceIndex(DrawCanvas *canvas, u16 *idx);
/* END mkheaders: generated region */

#endif
