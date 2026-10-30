/*
 * file:     draw_system.c
 * unit:     yes
 * function: DRAW_SYSTEM_CreateCanvas, DRAW_SYSTEM_DeleteCanvas, DRAW_SYSTEM_Nop, DRAW_SYSTEM_FlushStrokes, DRAW_SYSTEM_DrawStroke, DRAW_SYSTEM_DrawLine, DRAW_SYSTEM_PutPixel, DRAW_SYSTEM_PushStroke, DRAW_SYSTEM_SetQueueIndex, DRAW_SYSTEM_GetPlane, DRAW_SYSTEM_GetStroke, DRAW_SYSTEM_AdvanceIndex
 * address:  0x021B6BE0
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from camera_system.c, draw_system.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   GFL_NET_FreeAligned  0x0203D7FC  arm
 *   d_021C71D0 0x021C71D0 data a4
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   gDrawBrushes 0x021C4E84 data a4
 *   MI_CpuCopy8  0x02082D44  arm
 *   G2_GetBG2ScrPtr  0x0207E008  arm
 *   DRAW_SYSTEM_SetQueueIndex 0x021B6EA8 thumb ov172
 *   DRAW_SYSTEM_PushStroke 0x021B6E88 thumb ov172
 *   DRAW_SYSTEM_CreateCanvas 0x021B6BE0 thumb ov172
 *   DRAW_SYSTEM_DeleteCanvas 0x021B6C34 thumb ov172
 *   DRAW_SYSTEM_Nop  0x021B6C48  thumb  ov172
 *   DRAW_SYSTEM_FlushStrokes  0x021B6C4C  thumb  ov172
 */
#include "../types.h"
#include "../version.h"

/* Creation parameters of a draw canvas. */
typedef struct DrawCanvasParams {
    u16 heapId;
    u8 kind;
    u8 pad3;                    /* alignment before the next halfword */
    u16 capacity;               /* number of stroke entries */
    u16 clipX0;
    u16 clipX1;
    u16 clipY0;
    u16 clipY1;
} DrawCanvasParams;

/* One queued line segment; the size of 8 bytes is what the queue copy relies on. */
typedef struct DrawStroke {
    u8 x0;
    u8 y0;
    u8 x1;
    u8 y1;
    u16 color;
    u8 brush;
    u8 pad7;                    /* fills the entry to 8 bytes */
} DrawStroke;

/* Ring buffer of strokes plus the clip rectangle they are drawn into. */
typedef struct DrawCanvas {
    u8 kind;
    u8 pad1;                    /* alignment before the next halfword */
    u16 capacity;
    u16 writeIdx;
    u16 readIdx;
    u16 clipX0;
    u16 clipX1;
    u16 clipY0;
    u16 clipY1;
    DrawStroke *strokes;
} DrawCanvas;

/* Brush stamp: a bit mask per pixel, bits select which edges of a segment step draw it. */
typedef struct DrawBrush {
    u8 w;
    u8 h;
    u8 mask[32][32];
} DrawBrush;

#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/net.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gx_bgcnt.h"
extern const char d_021C71D0[];
extern const char str_ja_021C7070[];
extern const DrawBrush gDrawBrushes[];

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

/* Allocates a canvas and its stroke ring buffer. */
DrawCanvas *DRAW_SYSTEM_CreateCanvas(DrawCanvasParams *params)
{
    DrawCanvas *canvas;
    canvas = GFL_HEAP_Alloc(params->heapId, sizeof(DrawCanvas), 1, PM_LANG_JA(d_021C71D0, str_ja_021C7070), 64);
    canvas->strokes = GFL_NET_AllocAligned(params->heapId, params->capacity * 8, PM_LANG_JA(d_021C71D0, str_ja_021C7070), 65);
    canvas->kind = params->kind;
    canvas->capacity = params->capacity;
    canvas->clipX0 = params->clipX0;
    canvas->clipX1 = params->clipX1;
    canvas->clipY0 = params->clipY0;
    canvas->clipY1 = params->clipY1;
    canvas->writeIdx = 0;
    canvas->readIdx = 0;
    return canvas;
}

/* Frees the stroke buffer and the canvas. */
void DRAW_SYSTEM_DeleteCanvas(DrawCanvas *canvas)
{
    GFL_NET_FreeAligned(canvas->strokes);
    GFL_HEAP_Free(canvas);
}

/* Empty in the original. */
void DRAW_SYSTEM_Nop(u32 unused)
{
}

/* Draws every queued stroke into the current plane and empties the queue. */
void DRAW_SYSTEM_FlushStrokes(DrawCanvas *canvas)
{
    if (canvas->readIdx != canvas->writeIdx) do {
        DRAW_SYSTEM_DrawStroke(canvas, DRAW_SYSTEM_GetStroke(canvas, canvas->readIdx));
        DRAW_SYSTEM_AdvanceIndex(canvas, &canvas->readIdx);
    } while (canvas->readIdx != canvas->writeIdx);
}

/*
 * note: 2026-10-02 the record pointer is const: that lets the scheduler hoist the r2/r3 loads
 *   above the outgoing stack stores (a plain pointer may alias the stack, which pins the order).
 */
/* Draws one stroke into the current plane. */
void DRAW_SYSTEM_DrawStroke(DrawCanvas *canvas, const DrawStroke *stroke)
{
    DRAW_SYSTEM_DrawLine(canvas, DRAW_SYSTEM_GetPlane(), stroke->x0, stroke->x1, stroke->y0, stroke->y1, stroke->brush, stroke->color);
}

/*
 * note 2026-10-05 wD4 lane05: EXACT. Rewritten from the listing: const brush table {u8 w, h; u8 m[32][32]}
 *   (const lets the t->w / t->h loop bounds hoist), u32 w/h locals, callee seen with u16 x/y, m1/m2 as
 *   `sx >= 0 ? 2 : 8`, px/py computed with ox/oy as copies inside an `if (n > 0)` around a do-while,
 *   and the abs values in the ternary macro form `(v < 0) ? -(v) : (v)` (fixes the y0/y1 colours).
 */
/* Draws a line from (x0, y0) to (x1, y1) by stamping the brush at every step. The
 * steps use 20.12 fixed point; the brush mask bits pick which pixels of the stamp are
 * drawn depending on the direction of the last step. */
void DRAW_SYSTEM_DrawLine(DrawCanvas *canvas, u16 *plane, int x0, int x1, u16 y0, u16 y1, int brushIdx, u16 color)
{
    const DrawBrush *brush = &gDrawBrushes[brushIdx];
    int stepX, stepY, accX, accY, k;
    u8 maskX, maskY, j;
    int stampX, stampY, originX, originY, steps;
    int absDx, absDy, delta, prevX, prevY;
    u8 mask, i;
    u32 w, h;
    absDx = ((x0 - x1) < 0) ? -(x0 - x1) : (x0 - x1);
    absDy = ((y0 - y1) < 0) ? -(y0 - y1) : (y0 - y1);
    steps = (absDx > absDy ? absDx : absDy) + 1;
    delta = x1 - x0;
    stepX = (int)(delta > 0 ? 0.5f + (float)(delta << 12) : (float)(delta << 12) - 0.5f) / steps;
    delta = y1 - y0;
    stepY = (int)(delta > 0 ? 0.5f + (float)(delta << 12) : (float)(delta << 12) - 0.5f) / steps;
    accX = 0;
    accY = 0;
    w = brush->w;
    h = brush->h;
    prevX = x0 - (w >> 1);
    prevY = y0 - (h >> 1);
    maskX = (stepX >= 0) ? 2 : 8;
    maskY = (stepY >= 0) ? 4 : 1;
    k = 0;
    if (steps > 0) {
    originX = prevX;
    originY = prevY;
    do {
        stampX = originX + (accX >> 12);
        stampY = originY + (accY >> 12);
        if (k > 0) {
            mask = 0;
            if (stampX != prevX) mask += maskX;
            if (stampY != prevY) mask += maskY;
        } else {
            mask = 0x1F;
        }
        for (j = 0; j < brush->h; j++) {
            for (i = 0; i < brush->w; i++) {
                if (brush->mask[j][i] & mask)
                    DRAW_SYSTEM_PutPixel(canvas, plane, stampX + i, stampY + j, color);
            }
        }
        accX += stepX;
        accY += stepY;
        prevX = stampX;
        prevY = stampY;
    } while (++k < steps);
    }
}

/* Writes one pixel (RGB halfword, 256 pixels per row) when it lies in the clip rectangle. */
void DRAW_SYSTEM_PutPixel(DrawCanvas *canvas, u16 *plane, u16 x, u16 y, unsigned short color)
{
    if (x >= canvas->clipX0 && x < canvas->clipX1 && y >= canvas->clipY0 && y < canvas->clipY1) {
        *(u16 *)((char *)plane + x * 2 + y * 512) = color;
    }
}

/* Queues a stroke: copies the 8 byte entry to the write index and advances it. */
void DRAW_SYSTEM_PushStroke(DrawCanvas *canvas, void *stroke)
{
    MI_CpuCopy8(stroke, DRAW_SYSTEM_GetStroke(canvas, canvas->writeIdx), 8);
    DRAW_SYSTEM_AdvanceIndex(canvas, &canvas->writeIdx);
}

/* Sets the write index to index and the read index 5 entries after it (wrapped). */
void DRAW_SYSTEM_SetQueueIndex(DrawCanvas *canvas, u16 index)
{
    canvas->writeIdx = index;
    canvas->readIdx = index + 5;
    if (canvas->readIdx >= canvas->capacity)
        canvas->readIdx -= canvas->capacity;
}

/* Returns the plane the strokes are drawn into. */
void *DRAW_SYSTEM_GetPlane(void)
{
    return G2_GetBG2ScrPtr();
}

/* Returns stroke entry i. */
DrawStroke *DRAW_SYSTEM_GetStroke(DrawCanvas *canvas, int i)
{
    return canvas->strokes + i;
}

/* Advances a queue index, wrapping at the capacity. */
void DRAW_SYSTEM_AdvanceIndex(DrawCanvas *canvas, u16 *idx)
{
    *idx += 1;
    if (*idx >= canvas->capacity) {
        *idx = 0;
    }
}
