/*
 * file:     circle_graph.c
 * unit:     yes
 * function: CircleGraph_Create, CircleGraph_Destroy, CircleGraph_SetSlices, CircleGraph_Update, CircleGraph_Draw, CircleGraph_QueueDrawSlow, CircleGraph_QueueDrawFast, CircleGraph_QueueErase, CircleGraph_QueueDrawMedium, CircleGraph_SetEnabled, CircleGraph_HoldUpdate, CircleGraph_SetCenter, CircleGraph_SetCenterDepth, CircleGraph_FindSliceIndex, CircleGraph_GetSliceKey, CircleGraph_GetPercentByKey, CircleGraph_GetPercentByIndex, CircleGraph_IsAnimating, CircleGraph_GetLabelPositionByKey, CircleGraph_GetLabelPositionByIndex, CircleGraph_DrawSlices, CircleGraph_DrawOutline, CircleGraph_SetupCamera, CircleGraph_UpdateState, CircleGraph_UpdateHidden, CircleGraph_UpdateDrawSlow, CircleGraph_UpdateDrawFast, CircleGraph_UpdateErase, CircleGraph_UpdateShown, CircleGraph_UpdateDrawMedium, CircleGraph_AdvanceFrame, CircleGraph_TickHold, CircleGraph_QueueCommand, CircleGraph_NextCommand, CircleGraph_SetState, CircleGraph_ClearSlices, CircleGraph_AddSlice, CircleGraph_SortSlices, CircleGraph_ComputePercents, CircleGraph_ComputePointRanges, CircleGraph_BuildVertices, CircleGraph_SetEnabledImpl, CircleGraph_StartHold, CircleGraph_StoreCenter, CircleGraph_FindSliceIndexImpl, CircleGraph_GetSlice, CircleGraph_GetSliceByKey, CircleGraph_SumValues, CircleGraph_SumPercents, CircleGraph_GetPointRange, CircleGraph_GetRimColor, CircleGraph_GetCenterColor, CircleGraph_GetSliceMiddle, CircleGraph_IsEnabled, CircleGraph_IsAnimatingImpl, CircleGraph_Init, CircleGraph_DestroyQueueImpl, CircleGraph_InitFields, CircleGraph_Alloc, CircleGraph_Free, CircleGraph_CreateQueue, CircleGraph_DestroyQueue, CircleGraph_BuildCirclePoints, CircleGraph_ProjectToScreen
 * address:  0x021C10C8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, ov217_func_021C2E20.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   _ffix 0x0209C494 arm
 *   CircleGraph_SetEnabled  0x021C1184  thumb  ov217
 *   CircleGraph_QueueDrawSlow  0x021C1154  thumb  ov217
 *   CircleGraph_QueueDrawMedium 0x021C1178 thumb ov217
 *   CircleGraph_QueueErase  0x021C116C  thumb  ov217
 *   CircleGraph_HoldUpdate 0x021C118C thumb ov217
 *   CircleGraph_QueueDrawFast 0x021C1160 thumb ov217
 *   CircleGraph_GetSliceKey 0x021C11D0 thumb ov217
 *   CircleGraph_FindSliceIndex 0x021C11C8 thumb ov217
 *   CircleGraph_SetCenterDepth 0x021C11A4 thumb ov217
 *   CircleGraph_SetSlices 0x021C10E8 thumb ov217
 *   CircleGraph_Update 0x021C1124 thumb ov217
 *   CircleGraph_Draw 0x021C112C thumb ov217
 *   CircleGraph_GetPercentByKey 0x021C11DC thumb ov217
 *   CircleGraph_GetLabelPositionByKey 0x021C11FC thumb ov217
 *   CircleGraph_GetPercentByIndex 0x021C11E8 thumb ov217
 *   CircleGraph_GetLabelPositionByIndex 0x021C1224 thumb ov217
 *   CircleGraph_IsAnimating  0x021C11F4  thumb  ov217
 *   CircleGraph_Create 0x021C10C8 thumb ov217
 *   CircleGraph_Destroy 0x021C10D8 thumb ov217
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   d_021C4064 0x021C4064 data a1
 *   d_02148D8C  0x02148D8C  data  a4
 *   d_02148D98  0x02148D98  data  a4
 *   d_02148DA4  0x02148DA4  data  a4
 *   d_02148B98  0x02148B98  data  a4
 *   d_02148BCC  0x02148BCC  data  a4
 *   d_02148B54  0x02148B54  data  a4
 *   G3i_LookAt_  0x0207D7C4  arm
 *   G3i_OrthoW_  0x0207D760  arm
 *   NNS_G3dGlbInit  0x0206A700  arm
 *   MTX_LookAt  0x0207BCA0  arm
 *   func_0207C554  0x0207C554  arm
 *   NNS_G3dGlbFlush  0x0206A854  arm
 *   RingQueue_Reset  0x021C0E5C  thumb  ov217
 *   VEC_Fx16Add 0x0207CA30 arm
 *   cos 0x0209A390 arm
 *   sin 0x0209AA08 arm
 *   NNS_G3dWorldPosToScrPos  0x0206DF3C  arm
 */
#include "circle_graph.h"

typedef float f32;
typedef double f64;

/* Global state of the 3D engine; only the flag word is used here. */
struct G3dGlbState {
    u8 unknown0[0x7C];                  /* not accessed by this overlay, see open_items */
    u32 flag;
};

typedef enum { GX_POLYGONMODE_MODULATE = 0 } GXPolygonMode;
typedef enum { GX_CULL_NONE = 3 } GXCull;
typedef enum { GX_BEGIN_TRIANGLES = 0 } GXBegin;

/* First and last circle point of a slice, in the order the getter writes them. */
struct CircleArcRange {
    u8 last;
    u8 first;
};

#define FX32_CONST(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + 0.5f) : ((x) * 4096.0f - 0.5f)))

#define FX_FX32_TO_F32(x) ((f32)((x) / 4096.0f))

typedef char CircleGraphSizeCheck[(sizeof(struct CircleGraph) == 4044) ? 1 : -1];
typedef char CircleGraphEntrySizeCheck[(sizeof(struct CircleGraphEntry) == 20) ? 1 : -1];
typedef char CircleGraphVertexSizeCheck[(sizeof(struct CircleGraphVertex) == 10) ? 1 : -1];

extern u32 GFL_HEAP_Free(void *mem);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

/* SDK: G3i_LookAt_ */
extern void G3i_LookAt_(const VecFx32 *eye, const VecFx32 *up, const VecFx32 *target, int flag, int unused);
/* SDK: G3i_OrthoW_ */
extern void G3i_OrthoW_(int top, int bottom, int left, int right, int near, int far, int scaleW, int flag, int unused);
/* SDK: NNS_G3dGlbInit */
extern void NNS_G3dGlbInit(void);
/* SDK: MTX_LookAt */
extern void MTX_LookAt(const VecFx32 *eye, const VecFx32 *up, const VecFx32 *target, void *out);
/* SDK: MTX_OrthoW */
extern void func_0207C554(int top, int bottom, int left, int right, int near, int far, int scaleW, void *out);
/* SDK: NNS_G3dGlbFlush */
extern void NNS_G3dGlbFlush(void);
/* SDK: VEC_Fx16Add */
extern void VEC_Fx16Add(const s16 *a, const s16 *b, s16 *out);
extern double cos(double);
extern double sin(double);
/* SDK: NNS_G3dWorldPosToScrPos */
extern void NNS_G3dWorldPosToScrPos(const VecFx32 *pos, s32 *px, s32 *py);

extern const char d_021C4064[];
extern VecFx32 d_02148D8C;              /* camera eye */
extern VecFx32 d_02148D98;              /* camera up */
extern VecFx32 d_02148DA4;              /* camera target */
extern VecFx32 d_02148B98;              /* view matrix */
extern struct G3dGlbState d_02148BCC;
extern VecFx32 d_02148B54;              /* projection matrix */

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

/* Allocates a graph and initialises it. */
struct CircleGraph *CircleGraph_Create(u32 heapId)
{
    struct CircleGraph *graph = CircleGraph_Alloc(heapId);
    CircleGraph_Init(graph);
    return graph;
}

u32 CircleGraph_Destroy(struct CircleGraph *graph)
{
    CircleGraph_DestroyQueueImpl(graph);
    return CircleGraph_Free(graph);
}

/* Replaces the slices with count inputs, then computes shares, arcs and vertices. */
void CircleGraph_SetSlices(struct CircleGraph *graph, const struct CircleGraphInput *inputs, int count)
{
    int i;
    CircleGraph_ClearSlices(graph);
    for (i = 0; i < count; i++)
        CircleGraph_AddSlice(graph, inputs + i);
    CircleGraph_SortSlices(graph);
    CircleGraph_ComputePercents(graph);
    CircleGraph_ComputePointRanges(graph);
    CircleGraph_BuildVertices(graph);
}

/* Per-frame update. */
void CircleGraph_Update(struct CircleGraph *graph)
{
    CircleGraph_UpdateState(graph);
}

/* Draws the graph when it is enabled and not hidden. */
void CircleGraph_Draw(struct CircleGraph *graph)
{
    if (CircleGraph_IsEnabled(graph) == 1) {
        if (graph->state != 0) {
            CircleGraph_SetupCamera(graph);
            CircleGraph_DrawSlices(graph);
            CircleGraph_DrawOutline(graph);
        }
    }
}

/* Queue the slow draw-in. */
void CircleGraph_QueueDrawSlow(struct CircleGraph *graph)
{
    CircleGraph_QueueCommand(graph, CIRCLE_GRAPH_STATE_DRAW_SLOW);
}

/* Queue the fast draw-in. */
void CircleGraph_QueueDrawFast(struct CircleGraph *graph)
{
    CircleGraph_QueueCommand(graph, CIRCLE_GRAPH_STATE_DRAW_FAST);
}

/* Queue the erase. */
void CircleGraph_QueueErase(struct CircleGraph *graph)
{
    CircleGraph_QueueCommand(graph, CIRCLE_GRAPH_STATE_ERASE);
}

/* Queue the medium speed draw-in. */
void CircleGraph_QueueDrawMedium(struct CircleGraph *graph)
{
    CircleGraph_QueueCommand(graph, CIRCLE_GRAPH_STATE_DRAW_MEDIUM);
}

void CircleGraph_SetEnabled(struct CircleGraph *graph, u32 enabled)
{
    CircleGraph_SetEnabledImpl(graph, enabled);
}

/* Holds the state update for the given number of frames. */
void CircleGraph_HoldUpdate(struct CircleGraph *graph, u32 frames)
{
    CircleGraph_StartHold(graph, frames);
}

/* Moves the centre and rebuilds the vertices. */
void CircleGraph_SetCenter(struct CircleGraph *graph, const struct CircleGraphPosition *center)
{
    CircleGraph_StoreCenter(graph, center);
    CircleGraph_BuildVertices(graph);
}

/* Changes the depth of the centre. */
void CircleGraph_SetCenterDepth(struct CircleGraph *graph, int z)
{
    struct CircleGraphPosition center;
    s16 y = graph->centerY;
    s16 x = graph->centerX;
    center.x = x;
    center.y = y;
    center.z = z;
    CircleGraph_SetCenter(graph, &center);
}

u8 CircleGraph_FindSliceIndex(struct CircleGraph *graph, u8 key)
{
    return CircleGraph_FindSliceIndexImpl(graph, key);
}

u8 CircleGraph_GetSliceKey(struct CircleGraph *graph, u8 index)
{
    return CircleGraph_GetSlice(graph, index)->key;
}

u8 CircleGraph_GetPercentByKey(struct CircleGraph *graph, u8 key)
{
    return CircleGraph_GetSliceByKey(graph, key)->percent;
}

u8 CircleGraph_GetPercentByIndex(struct CircleGraph *graph, u8 index)
{
    return CircleGraph_GetSlice(graph, index)->percent;
}

/* 1 while a draw or erase animation is running. */
int CircleGraph_IsAnimating(const struct CircleGraph *graph)
{
    return CircleGraph_IsAnimatingImpl(graph);
}

/* Screen position of the middle of the slice with the given key. */
void CircleGraph_GetLabelPositionByKey(struct CircleGraph *graph, u8 key, s32 *px, s32 *py)
{
    struct CircleGraphPosition position;
    CircleGraph_GetSliceMiddle(graph, CircleGraph_GetSliceByKey(graph, key), &position);
    CircleGraph_ProjectToScreen(&position, px, py);
}

/* Screen position of the middle of the slice with the given index. */
void CircleGraph_GetLabelPositionByIndex(struct CircleGraph *graph, u8 index, s32 *px, s32 *py)
{
    struct CircleGraphPosition position;
    CircleGraph_GetSliceMiddle(graph, CircleGraph_GetSlice(graph, index), &position);
    CircleGraph_ProjectToScreen(&position, px, py);
}

static inline void G3_PolygonAttr(int light, GXPolygonMode mode, GXCull cull, int id, int alpha, int misc)
{
    *(volatile u32 *)0x040004a4 = light | (mode << 4) | (cull << 6) | (id << 24) | (alpha << 16) | misc;
}

static inline void G3_Begin(GXBegin primitive) { *(volatile u32 *)0x04000500 = primitive; }

static inline void G3_Color(u16 rgb) { *(volatile u32 *)0x04000480 = rgb; }

static inline void G3_Vtx(s16 x, s16 y, s16 z)
{
    *(volatile u32 *)0x0400048c = (u32)(u16)x | ((u32)(u16)y << 16);
    *(volatile u32 *)0x0400048c = (u32)(u16)z;
}

static inline void G3_End(void) { *(volatile u32 *)0x04000504 = 0; }

/*
 * Draws the filled slices as triangles of three vertices each. The number
 * of triangles drawn and the first one follow the animation state and frame.
 */
void CircleGraph_DrawSlices(struct CircleGraph *graph)
{
    int wedgeCount, i, index;
    u32 firstWedge = (u32)graph;
    switch (graph->state) {
    case 0: wedgeCount = 0; break;
    case 1: wedgeCount = graph->frame * 100 / 120; firstWedge = 100 - wedgeCount; break;
    case 2: wedgeCount = graph->frame * 100 / 30; firstWedge = 100 - wedgeCount; break;
    case 3: wedgeCount = (20 - graph->frame) * 100 / 20; firstWedge = 100 - wedgeCount; break;
    case 4: wedgeCount = 100; firstWedge = 0; break;
    case 5: wedgeCount = graph->frame * 100 / 60; firstWedge = 100 - wedgeCount; break;
    }
    index = firstWedge * 3;
    for (i = 0; i < wedgeCount; i++) {
        G3_PolygonAttr(0, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, graph->vertices[index].polygonId, 31, 0);
        G3_Begin(GX_BEGIN_TRIANGLES);
        G3_Color(graph->vertices[index].color);
        G3_Vtx(graph->vertices[index].x, graph->vertices[index].y, graph->vertices[index].z);
        index = (index + 1) % 300;
        G3_Color(graph->vertices[index].color);
        G3_Vtx(graph->vertices[index].x, graph->vertices[index].y, graph->vertices[index].z);
        index = (index + 1) % 300;
        G3_Color(graph->vertices[index].color);
        G3_Vtx(graph->vertices[index].x, graph->vertices[index].y, graph->vertices[index].z);
        index = (index + 1) % 300;
        G3_End();
    }
}

/*
 * Draws the outline of the fully drawn graph: for each slice whose share is at
 * least 3 percent, a line from the centre to the start point of its arc, as a
 * degenerate triangle through the GX FIFO. The vertex words are packed x first
 * ((u16)x | (u16)y << 16), and i is declared before n (spill slots n@0, i@4).
 */
void CircleGraph_DrawOutline(struct CircleGraph *graph)
{
    struct CircleArcRange arc;
    struct CircleGraphEntry *entry;
    int i;
    int n;

    if (CircleGraph_IsAnimatingImpl(graph) == 0) {
        *(volatile u32 *)0x040004A4 = 0x001F00C0;
        n = graph->entryCount;
        for (i = 0; i < n; i++) {
            entry = CircleGraph_GetSlice(graph, i);
            CircleGraph_GetPointRange(entry, &arc.first, &arc.last);
            if (entry->percent >= 3) {
                s16 px, py, x, y;
                u32 va, vb;
                px = graph->centerX;
                py = graph->centerY;
                x = px + graph->circle[arc.first].x;
                y = py + graph->circle[arc.first].y;
                *(volatile u32 *)0x04000500 = 0;
                *(volatile u32 *)0x04000480 = 0;
                va = (u16)px | ((u32)(u16)py << 16);
                vb = (u16)x | ((u32)(u16)y << 16);
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = va;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x0400048C = vb;
                *(volatile u32 *)0x0400048C = 0x4000;
                *(volatile u32 *)0x04000504 = 0;
            }
        }
    }
}

/* Sets up the camera and the orthographic projection used to draw the graph. */
void CircleGraph_SetupCamera(struct CircleGraph *graph)
{
    VecFx32 eye;
    VecFx32 up;
    VecFx32 target;

    eye.x = 0;
    eye.y = 0;
    eye.z = 0x1000;
    up.x = 0;
    up.y = 0x1000;
    up.z = 0;
    target.x = 0;
    target.y = 0;
    target.z = 0;
    G3i_LookAt_(&eye, &up, &target, 1, 0);
    G3i_OrthoW_(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, 1, 0);
    NNS_G3dGlbInit();
    d_02148D8C = eye;
    d_02148D98 = up;
    d_02148DA4 = target;
    MTX_LookAt(&eye, &up, &target, &d_02148B98);
    d_02148BCC.flag &= ~0xE8;
    func_0207C554(0x1000, -0x1000, -0x1554, 0x1554, 0x19A, 0x5000, 0x1000, &d_02148B54);
    d_02148BCC.flag &= ~0x50;
    NNS_G3dGlbFlush();
}

/* Runs the handler of the current state, then advances the frame and the hold. */
void CircleGraph_UpdateState(struct CircleGraph *graph)
{
    if (graph->holdActive == 0) {
        switch (graph->state) {
        case CIRCLE_GRAPH_STATE_HIDDEN: CircleGraph_UpdateHidden(graph); break;
        case CIRCLE_GRAPH_STATE_DRAW_SLOW: CircleGraph_UpdateDrawSlow(graph); break;
        case CIRCLE_GRAPH_STATE_DRAW_FAST: CircleGraph_UpdateDrawFast(graph); break;
        case CIRCLE_GRAPH_STATE_ERASE: CircleGraph_UpdateErase(graph); break;
        case CIRCLE_GRAPH_STATE_SHOWN: CircleGraph_UpdateShown(graph); break;
        case CIRCLE_GRAPH_STATE_DRAW_MEDIUM: CircleGraph_UpdateDrawMedium(graph); break;
        }
    }
    CircleGraph_AdvanceFrame(graph);
    CircleGraph_TickHold(graph);
}

/* Hidden: takes the next queued command. */
void CircleGraph_UpdateHidden(struct CircleGraph *graph)
{
    if (RingQueue_IsEmpty(graph->commandQueue) == 0) {
        CircleGraph_NextCommand(graph);
    }
}

/* Slow draw-in done after 120 frames. */
void CircleGraph_UpdateDrawSlow(struct CircleGraph *graph)
{
    if (graph->frame >= 120) {
        CircleGraph_SetState(graph, CIRCLE_GRAPH_STATE_SHOWN);
    }
}

/* Fast draw-in done after 30 frames. */
void CircleGraph_UpdateDrawFast(struct CircleGraph *graph)
{
    if (graph->frame >= 30) {
        CircleGraph_SetState(graph, CIRCLE_GRAPH_STATE_SHOWN);
    }
}

/* Erase done after 20 frames. */
void CircleGraph_UpdateErase(struct CircleGraph *graph)
{
    if (graph->frame >= 20) {
        CircleGraph_SetState(graph, CIRCLE_GRAPH_STATE_HIDDEN);
    }
}

/* Shown: takes the next queued command. */
void CircleGraph_UpdateShown(struct CircleGraph *graph)
{
    if (RingQueue_IsEmpty(graph->commandQueue) == 0) {
        CircleGraph_NextCommand(graph);
    }
}

/* Medium draw-in done after 60 frames. */
void CircleGraph_UpdateDrawMedium(struct CircleGraph *graph)
{
    if (graph->frame >= 60) {
        CircleGraph_SetState(graph, CIRCLE_GRAPH_STATE_SHOWN);
    }
}

/*
 * Advances the frame counter and clamps it to the length of the state. The
 * limit is uninitialised on the default path, which is how the image reads too.
 */
void CircleGraph_AdvanceFrame(struct CircleGraph *graph)
{
    u32 limit;

    graph->frame++;
    switch (graph->state) {
    case 0:
        limit = (u32)-1;
        break;
    case 1:
        limit = 0x78;
        break;
    case 2:
        limit = 0x1e;
        break;
    case 3:
        limit = 0x14;
        break;
    case 4:
        limit = (u32)-1;
        break;
    case 5:
        limit = 0x3c;
        break;
    }
    if (limit < graph->frame)
        graph->frame = limit;
}

/* Counts the hold down and releases it at zero. */
void CircleGraph_TickHold(struct CircleGraph *graph)
{
    u32 frames;
    if (graph->holdActive == 0)
        return;
    if (graph->holdFrames == 0)
        return;
    frames = graph->holdFrames - 1;
    graph->holdFrames = frames;
    if (frames == 0)
        graph->holdActive = 0;
}

/* Pushes a state number to the command queue. */
void CircleGraph_QueueCommand(struct CircleGraph *graph, u32 command)
{
    RingQueue_Push(graph->commandQueue, command);
}

/* Switches to the state taken from the command queue. */
void CircleGraph_NextCommand(struct CircleGraph *graph)
{
    CircleGraph_SetState(graph, RingQueue_Pop(graph->commandQueue));
}

/* Enters a state and restarts its frame counter. */
struct CircleGraph *CircleGraph_SetState(struct CircleGraph *graph, u32 state)
{
    graph->state = state;
    graph->frame = 0;
    return graph;
}

/* Removes all slices and queued commands, back to the hidden state. */
struct CircleGraph *CircleGraph_ClearSlices(struct CircleGraph *graph)
{
    graph->entryCount = 0;
    RingQueue_Reset(graph->commandQueue);
    return CircleGraph_SetState(graph, CIRCLE_GRAPH_STATE_HIDDEN);
}

/* Appends a slice. */
void CircleGraph_AddSlice(struct CircleGraph *graph, const struct CircleGraphInput *input)
{
    graph->entries[graph->entryCount].key = input->key;
    graph->entries[graph->entryCount].value = input->value;
    graph->entries[graph->entryCount].percent = 0;
    graph->entries[graph->entryCount].firstPoint = 0;
    graph->entries[graph->entryCount].lastPoint = 0;
    graph->entries[graph->entryCount].rimColor[0] = input->rimColor[0];
    graph->entries[graph->entryCount].rimColor[1] = input->rimColor[1];
    graph->entries[graph->entryCount].rimColor[2] = input->rimColor[2];
    graph->entries[graph->entryCount].centerColor[0] = input->centerColor[0];
    graph->entries[graph->entryCount].centerColor[1] = input->centerColor[1];
    graph->entries[graph->entryCount].centerColor[2] = input->centerColor[2];
    graph->entryCount = graph->entryCount + 1;
}

/*
 * Bubble sort of the slices by value, descending. Counters and bound are int
 * and are declared and assigned separately (int i; int n; int j; n = ...;
 * i = 0;): that order puts n in lr and i in ip and keeps n - 1 unhoisted.
 */
void CircleGraph_SortSlices(struct CircleGraph *graph)
{
    int i;
    int n;
    int j;
    n = graph->entryCount;
    i = 0;

    while (i < n - 1) {
        j = 0;
        while (j < n - 1 - i) {
            if (graph->entries[j].value < graph->entries[j + 1].value) {
                struct CircleGraphEntry temp = graph->entries[j];
                graph->entries[j] = graph->entries[j + 1];
                graph->entries[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

/*
 * Computes the share of each slice in percent, then hands the rounding
 * remainder out one percent at a time starting with the largest slice.
 * Declaration order matters: base before total, and the base store is kept.
 */
void CircleGraph_ComputePercents(struct CircleGraph *graph)
{
    struct CircleGraphEntry *base;
    u32 total = CircleGraph_SumValues(graph);
    int count = graph->entryCount;
    int i = 0;
    int remaining;
    if (count > 0) {
        base = graph->entries;
        do {
            struct CircleGraphEntry *entry = base + i;
            entry->percent = (entry->value * 100) / total;
            i++;
        } while (i < count);
    }
    remaining = 100 - CircleGraph_SumPercents(graph);
    i = 0;
    while (remaining > 0) {
        graph->entries[i].percent += 1;
        remaining--;
        i = (i + 1) % count;
    }
}

/* Assigns each slice its range of circle points from the shares. */
void CircleGraph_ComputePointRanges(struct CircleGraph *graph)
{
    int i;
    int n;
    int sum;
    n = graph->entryCount;
    sum = 0;
    for (i = 0; i < n; i++) {
        struct CircleGraphEntry *entry = &graph->entries[i];
        entry->firstPoint = sum;
        entry->lastPoint = sum + entry->percent - 1;
        sum += entry->percent;
    }
}

/*
 * Builds the triangle vertices of every slice: per circle point, one vertex
 * at the centre and two on the rim. Each slice sits 205 units deeper than the
 * previous one. The callees return the colours as u16.
 */
void CircleGraph_BuildVertices(struct CircleGraph *graph)
{
    struct {
        u8 last;
        u8 first;
        u16 x;                          /* centre of the slice, copied as unsigned halfwords */
        u16 y;
        u16 z;
    } arc;
    int count = graph->entryCount;
    int k = 0;
    int i;
    for (i = 0; i < count; i++) {
        struct CircleGraphEntry *entry;
        u16 centerColor, rimColor;
        int j;
        entry = CircleGraph_GetSlice(graph, i);
        centerColor = CircleGraph_GetCenterColor(entry);
        rimColor = CircleGraph_GetRimColor(entry);
        CircleGraph_GetPointRange(entry, &arc.first, &arc.last);
        arc.x = graph->centerX;
        arc.y = graph->centerY;
        arc.z = graph->centerZ + i * 205;
        for (j = arc.first; j <= arc.last; j++) {
            struct CircleGraph *at = (struct CircleGraph *)((u8 *)graph + k * 10);
            at->vertices[0].color = centerColor;
            at->vertices[0].x = arc.x;
            at->vertices[0].y = arc.y;
            at->vertices[0].z = arc.z;
            at->vertices[0].polygonId = i;
            at->vertices[1].color = rimColor;
            VEC_Fx16Add((s16 *)&arc.x, &graph->circle[j].x, &graph->vertices[k + 1].x);
            at->vertices[1].polygonId = i;
            at->vertices[2].color = rimColor;
            VEC_Fx16Add((s16 *)&arc.x, &graph->circle[(j + 1) % 100].x, &graph->vertices[k + 2].x);
            at->vertices[2].polygonId = i;
            k += 3;
        }
    }
}

void CircleGraph_SetEnabledImpl(struct CircleGraph *graph, u32 enabled)
{
    graph->enabled = enabled;
}

/* Starts holding the state update for the given number of frames. */
void CircleGraph_StartHold(struct CircleGraph *graph, u32 frames)
{
    graph->holdActive = 1;
    graph->holdFrames = frames;
}

/* A const source pointer fixes the load order (z, y, x). */
void CircleGraph_StoreCenter(struct CircleGraph *graph, const struct CircleGraphPosition *center)
{
    s16 z = center->z;
    s16 y = center->y;
    s16 x = center->x;
    graph->centerX = x;
    graph->centerY = y;
    graph->centerZ = z;
}

/* Index of the slice with the given key, 0 when there is none. */
u8 CircleGraph_FindSliceIndexImpl(struct CircleGraph *graph, u8 key)
{
    int i;
    int n;
    u8 entryKey;
    n = graph->entryCount;
    for (i = 0; i < n; i++) {
        entryKey = graph->entries[i].key;
        if (entryKey == key) {
            return i;
        }
    }
    return 0;
}

struct CircleGraphEntry *CircleGraph_GetSlice(struct CircleGraph *graph, u32 index)
{
    return graph->entries + index;
}

struct CircleGraphEntry *CircleGraph_GetSliceByKey(struct CircleGraph *graph, u8 key)
{
    return CircleGraph_GetSlice(graph, CircleGraph_FindSliceIndexImpl(graph, key));
}

/* Sum of the slice values. */
int CircleGraph_SumValues(struct CircleGraph *graph)
{
    int i;
    int n;
    int sum;
    n = graph->entryCount;
    sum = 0;
    for (i = 0; i < n; i++)
        sum += graph->entries[i].value;
    return sum;
}

/* Sum of the slice shares. */
int CircleGraph_SumPercents(struct CircleGraph *graph)
{
    int i;
    int n;
    int sum;
    n = graph->entryCount;
    sum = 0;
    for (i = 0; i < n; i++)
        sum += graph->entries[i].percent;
    return sum;
}

/* Reads the point range of a slice; the float round trip is kept from the image. */
void CircleGraph_GetPointRange(struct CircleGraphEntry *entry, u8 *first, u8 *last)
{
    u8 start = (u8)(int)(float)entry->firstPoint;
    u8 end = (u8)(int)(float)entry->lastPoint;
    *first = start;
    *last = end;
}

/* Packs the rim colour into RGB555. */
u16 CircleGraph_GetRimColor(struct CircleGraphEntry *entry)
{
    return (u16)(entry->rimColor[0] | (entry->rimColor[1] << 5) | (entry->rimColor[2] << 10));
}

/* Packs the centre colour into RGB555. */
u16 CircleGraph_GetCenterColor(struct CircleGraphEntry *entry)
{
    return (u16)(entry->centerColor[0] | (entry->centerColor[1] << 5) | (entry->centerColor[2] << 10));
}

/*
 * Position for a label in the middle of a slice: a point 0.42 from the centre
 * in the direction of the middle of its arc, at the depth of its last point.
 * The last block is a ternary on the float, then one cast, so the ffix tail is
 * shared; the last point is kept in an int local loaded before the first.
 */
void CircleGraph_GetSliceMiddle(struct CircleGraph *graph, struct CircleGraphEntry *entry, struct CircleGraphPosition *out)
{
    struct CircleArcRange arc;
    int last;
    float middle, angle, dx, dy, pointZ, cx, cy, cz;
    CircleGraph_GetPointRange(entry, &arc.first, &arc.last);
    last = arc.last;
    middle = (float)(arc.first + last + 1);
    angle = 1.5707964f - 0.01f * (3.1415927f * middle);
    dx = 0.42f * (float)cos((double)angle);
    dy = 0.42f * (float)sin((double)angle);
    pointZ = (float)graph->circle[last].z / 4096.0f;
    cx = (float)graph->centerX / 4096.0f;
    cy = (float)graph->centerY / 4096.0f;
    cz = (float)graph->centerZ / 4096.0f;
    if (cx + dx > 0.0f) out->x = (s16)(0.5f + 4096.0f * (cx + dx));
    else out->x = (s16)(4096.0f * (cx + dx) - 0.5f);
    if (cy + dy > 0.0f) out->y = (s16)(0.5f + 4096.0f * (cy + dy));
    else out->y = (s16)(4096.0f * (cy + dy) - 0.5f);
    out->z = (s16)((cz + pointZ > 0.0f) ? (0.5f + 4096.0f * (cz + pointZ)) : (4096.0f * (cz + pointZ) - 0.5f));
}

u32 CircleGraph_IsEnabled(struct CircleGraph *graph)
{
    return graph->enabled;
}

/* 1 in the draw and erase states, 0 in the hidden and shown states. */
s32 CircleGraph_IsAnimatingImpl(const struct CircleGraph *graph)
{
    switch (graph->state) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 0;
    case 5:
        return 1;
    }
    return 0;
}

void CircleGraph_Init(struct CircleGraph *graph)
{
    CircleGraph_CreateQueue(graph);
    CircleGraph_BuildCirclePoints(graph);
}

void CircleGraph_DestroyQueueImpl(struct CircleGraph *graph)
{
    CircleGraph_DestroyQueue(graph);
}

/* Starting values: hidden, no slices, centre in the upper left of the screen. */
void CircleGraph_InitFields(struct CircleGraph *graph, u32 heapId)
{
    graph->heapId = heapId;
    graph->enabled = 0;
    graph->state = 0;
    graph->commandQueue = 0;
    graph->holdActive = 0;
    graph->holdFrames = 0;
    graph->radius = 0x7db;
    graph->entryCount = 0;
    graph->centerX = -0xb2f;
    graph->centerY = -0xc9;
    graph->centerZ = -0x1000;
}

struct CircleGraph *CircleGraph_Alloc(u32 heapId)
{
    struct CircleGraph *graph = GFL_HEAP_Alloc(heapId, sizeof(struct CircleGraph), 0, d_021C4064, 1588);
    CircleGraph_InitFields(graph, heapId);
    return graph;
}

u32 CircleGraph_Free(struct CircleGraph *graph)
{
    return GFL_HEAP_Free(graph);
}

/* Creates the command queue, 10 commands deep. */
void CircleGraph_CreateQueue(struct CircleGraph *graph)
{
    graph->commandQueue = (struct RingQueue *)RingQueue_Create(10, graph->heapId);
}

void CircleGraph_DestroyQueue(struct CircleGraph *graph)
{
    RingQueue_Destroy(graph->commandQueue);
}

/*
 * Fills the 100 points of the circle of the given radius as 16-bit fixed
 * point triples, starting at the top and going clockwise. The first converted
 * value goes through a local so its _ffix call comes before the address of
 * the point.
 */
void CircleGraph_BuildCirclePoints(struct CircleGraph *graph)
{
    s32 i;
    f32 r;
    r = graph->radius / 4096.0f;
    for (i = 0; i < 100; i++) {
        f32 t = 1.5707964f - (6.2831855f * (f32)i) / 100.0f;
        f32 x = r * (f32)cos((f64)t);
        f32 y = r * (f32)sin((f64)t);
        f32 z = 0.0f;
        s32 v = FX32_CONST(x);
        graph->circle[i].x = v;
        graph->circle[i].y = FX32_CONST(y);
        graph->circle[i].z = FX32_CONST(z);
    }
}

/* Projects a fixed point position to the screen. */
void CircleGraph_ProjectToScreen(const struct CircleGraphPosition *position, s32 *px, s32 *py)
{
    VecFx32 v;
    v.x = FX32_CONST(FX_FX32_TO_F32(position->x));
    v.y = FX32_CONST(FX_FX32_TO_F32(position->y));
    v.z = FX32_CONST(FX_FX32_TO_F32(position->z));
    NNS_G3dWorldPosToScrPos(&v, px, py);
}
