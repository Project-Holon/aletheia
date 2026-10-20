#ifndef CIRCLE_GRAPH_H
#define CIRCLE_GRAPH_H

#include "../types.h"
#include "../ov217/ring_queue.h"

#define CIRCLE_GRAPH_MAX_ENTRIES 20
#define CIRCLE_GRAPH_POINT_COUNT 100
#define CIRCLE_GRAPH_VERTEX_COUNT (CIRCLE_GRAPH_POINT_COUNT * 3)

/* States of the circle graph animation (field state). */
#define CIRCLE_GRAPH_STATE_HIDDEN 0
#define CIRCLE_GRAPH_STATE_DRAW_SLOW 1      /* 120 frames */
#define CIRCLE_GRAPH_STATE_DRAW_FAST 2      /* 30 frames */
#define CIRCLE_GRAPH_STATE_ERASE 3          /* 20 frames */
#define CIRCLE_GRAPH_STATE_SHOWN 4
#define CIRCLE_GRAPH_STATE_DRAW_MEDIUM 5    /* 60 frames */

/* Commands pushed to the command queue are state numbers. */

#include "../sdk_fx.h"

/* 16-bit fixed point position. */
struct CircleGraphPosition {
    s16 x;
    s16 y;
    s16 z;
};

/* One slice as passed by the caller, 16 bytes. */
struct CircleGraphInput {
    u8 key;
    u32 value;
    u8 rimColor[3];                     /* red, green, blue, 5 bits each */
    u8 centerColor[3];
};

/* One slice of the graph, 20 bytes. */
struct CircleGraphEntry {
    u8 key;
    u32 value;
    u8 percent;                         /* share of the total, sums to 100 */
    u8 firstPoint;                      /* first circle point of the slice */
    u8 lastPoint;
    u8 rimColor[3];
    u8 centerColor[3];
};

/* One vertex of the slice triangles, 10 bytes. */
struct CircleGraphVertex {
    s16 x;
    s16 y;
    s16 z;
    u16 color;                          /* RGB555 */
    u8 polygonId;
};

/* 3D pie chart, 4044 bytes. */
struct CircleGraph {
    u16 heapId;
    u16 pad2;                           /* alignment before the word */
    u32 enabled;
    u32 state;
    struct RingQueue *commandQueue;
    u32 frame;                          /* frames spent in the current state */
    u32 holdActive;                     /* 1 while the update is held */
    u32 holdFrames;                     /* frames left of the hold */
    struct CircleGraphEntry entries[CIRCLE_GRAPH_MAX_ENTRIES];
    u8 entryCount;
    u8 pad1AD[3];                       /* alignment before the word */
    s32 radius;                         /* fixed point, 12 fractional bits */
    s16 centerX;
    s16 centerY;
    s16 centerZ;
    struct CircleGraphPosition circle[CIRCLE_GRAPH_POINT_COUNT];
    struct CircleGraphVertex vertices[CIRCLE_GRAPH_VERTEX_COUNT];
};

struct CircleGraph *CircleGraph_Create(u32 heapId);
u32 CircleGraph_Destroy(struct CircleGraph *graph);
void CircleGraph_SetSlices(struct CircleGraph *graph, const struct CircleGraphInput *inputs, int count);
void CircleGraph_Update(struct CircleGraph *graph);
void CircleGraph_Draw(struct CircleGraph *graph);
void CircleGraph_QueueDrawSlow(struct CircleGraph *graph);
void CircleGraph_QueueDrawFast(struct CircleGraph *graph);
void CircleGraph_QueueErase(struct CircleGraph *graph);
void CircleGraph_QueueDrawMedium(struct CircleGraph *graph);
void CircleGraph_SetEnabled(struct CircleGraph *graph, u32 enabled);
void CircleGraph_HoldUpdate(struct CircleGraph *graph, u32 frames);
void CircleGraph_SetCenter(struct CircleGraph *graph, const struct CircleGraphPosition *center);
void CircleGraph_SetCenterDepth(struct CircleGraph *graph, int z);
u8 CircleGraph_FindSliceIndex(struct CircleGraph *graph, u8 key);
u8 CircleGraph_GetSliceKey(struct CircleGraph *graph, u8 index);
u8 CircleGraph_GetPercentByKey(struct CircleGraph *graph, u8 key);
u8 CircleGraph_GetPercentByIndex(struct CircleGraph *graph, u8 index);
int CircleGraph_IsAnimating(const struct CircleGraph *graph);
void CircleGraph_GetLabelPositionByKey(struct CircleGraph *graph, u8 key, s32 *px, s32 *py);
void CircleGraph_GetLabelPositionByIndex(struct CircleGraph *graph, u8 index, s32 *px, s32 *py);

struct CircleGraph;
struct CircleGraphInput;
struct CircleGraphPosition;
struct CircleGraphEntry;
void CircleGraph_DrawSlices(struct CircleGraph *graph);
void CircleGraph_DrawOutline(struct CircleGraph *graph);
void CircleGraph_SetupCamera(struct CircleGraph *graph);
void CircleGraph_UpdateState(struct CircleGraph *graph);
void CircleGraph_UpdateHidden(struct CircleGraph *graph);
void CircleGraph_UpdateDrawSlow(struct CircleGraph *graph);
void CircleGraph_UpdateDrawFast(struct CircleGraph *graph);
void CircleGraph_UpdateErase(struct CircleGraph *graph);
void CircleGraph_UpdateShown(struct CircleGraph *graph);
void CircleGraph_UpdateDrawMedium(struct CircleGraph *graph);
void CircleGraph_AdvanceFrame(struct CircleGraph *graph);
void CircleGraph_TickHold(struct CircleGraph *graph);
void CircleGraph_QueueCommand(struct CircleGraph *graph, u32 command);
void CircleGraph_NextCommand(struct CircleGraph *graph);
struct CircleGraph *CircleGraph_SetState(struct CircleGraph *graph, u32 state);
struct CircleGraph *CircleGraph_ClearSlices(struct CircleGraph *graph);
void CircleGraph_AddSlice(struct CircleGraph *graph, const struct CircleGraphInput *input);
void CircleGraph_SortSlices(struct CircleGraph *graph);
void CircleGraph_ComputePercents(struct CircleGraph *graph);
void CircleGraph_ComputePointRanges(struct CircleGraph *graph);
void CircleGraph_BuildVertices(struct CircleGraph *graph);
void CircleGraph_SetEnabledImpl(struct CircleGraph *graph, u32 enabled);
void CircleGraph_StartHold(struct CircleGraph *graph, u32 frames);
void CircleGraph_StoreCenter(struct CircleGraph *graph, const struct CircleGraphPosition *center);
u8 CircleGraph_FindSliceIndexImpl(struct CircleGraph *graph, u8 key);
struct CircleGraphEntry *CircleGraph_GetSlice(struct CircleGraph *graph, u32 index);
struct CircleGraphEntry *CircleGraph_GetSliceByKey(struct CircleGraph *graph, u8 key);
int CircleGraph_SumValues(struct CircleGraph *graph);
int CircleGraph_SumPercents(struct CircleGraph *graph);
void CircleGraph_GetPointRange(struct CircleGraphEntry *entry, u8 *first, u8 *last);
u16 CircleGraph_GetRimColor(struct CircleGraphEntry *entry);
u16 CircleGraph_GetCenterColor(struct CircleGraphEntry *entry);
void CircleGraph_GetSliceMiddle(struct CircleGraph *graph, struct CircleGraphEntry *entry, struct CircleGraphPosition *out);
u32 CircleGraph_IsEnabled(struct CircleGraph *graph);
s32 CircleGraph_IsAnimatingImpl(const struct CircleGraph *graph);
void CircleGraph_Init(struct CircleGraph *graph);
void CircleGraph_DestroyQueueImpl(struct CircleGraph *graph);
void CircleGraph_InitFields(struct CircleGraph *graph, u32 heapId);
struct CircleGraph *CircleGraph_Alloc(u32 heapId);
u32 CircleGraph_Free(struct CircleGraph *graph);
void CircleGraph_CreateQueue(struct CircleGraph *graph);
void CircleGraph_DestroyQueue(struct CircleGraph *graph);
void CircleGraph_BuildCirclePoints(struct CircleGraph *graph);
void CircleGraph_ProjectToScreen(const struct CircleGraphPosition *position, s32 *px, s32 *py);

#endif
