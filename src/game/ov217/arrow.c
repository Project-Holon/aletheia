/*
 * file:     arrow.c
 * unit:     yes
 * function: ARROW_Create, ARROW_Destroy, ARROW_Layout, ARROW_Update, ARROW_Start, ARROW_Reset, ARROW_RunState, ARROW_RunIdle, ARROW_RunDrawing, ARROW_RunDone, ARROW_SetState, ARROW_IsComplete, ARROW_ShowPart, ARROW_StopPart, ARROW_HideAll, ARROW_BuildParts, ARROW_InitPart, ARROW_Alloc, ARROW_Init, ARROW_Free, ARROW_CreateUnit, ARROW_DeleteUnit, ARROW_CreateActors, ARROW_DeleteActors, ARROW_SetResources, GRAPHTABLE_GetEntryId, GRAPHTABLE_GetEntryRed, GRAPHTABLE_GetEntryGreen, GRAPHTABLE_GetEntryBlue, GRAPHTABLE_FindGroup, GRAPHTABLE_FindEntry
 * address:  0x021C2070
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
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   _fadd 0x0209C95C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   ARROW_Update  0x021C20C4  thumb  ov217
 *   GRAPHTABLE_FindEntry 0x021C26AC thumb ov217
 *   GRAPHTABLE_GetEntryRed 0x021C2654 thumb ov217
 *   GRAPHTABLE_GetEntryGreen 0x021C2664 thumb ov217
 *   GRAPHTABLE_GetEntryBlue 0x021C2674 thumb ov217
 *   ARROW_Reset 0x021C20D8 thumb ov217
 *   ARROW_Layout 0x021C20B4 thumb ov217
 *   ARROW_Start 0x021C20CC thumb ov217
 *   CLACT_SetActorAnimLoopCount 0x0204B9C4 arm
 *   GRAPHTABLE_GetEntryId 0x021C2644 thumb ov217
 *   ARROW_Create 0x021C2070 thumb ov217
 *   ARROW_Destroy  0x021C209C  thumb  ov217
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm  arm9
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_StartActorAnim 0x0204B95C arm
 *   CLACT_StopActorAnim  0x0204B974  arm  arm9
 */
#include "arrow.h"
#include "research_graph_table.h"

typedef char ArrowSizeCheck[(sizeof(struct Arrow) == 0x29C) ? 1 : -1];
typedef char GraphTableSizeCheck[(sizeof(struct GraphTable) == 0x280) ? 1 : -1];

extern u32 GFL_HEAP_Free(void *mem);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, unsigned int enable);
extern struct ClactUnit *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern u32 CLACT_DeleteUnit(struct ClactUnit *unit);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern struct ClactActor *CLACT_CreateActor(void *unit, unsigned int charId, unsigned int palId, unsigned int cellId, const struct ActorHeader *header, unsigned short priority, unsigned short heapId);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const struct SurfacePos *pos, u32 space);
extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 seq);
extern void CLACT_SetActorAnimFrame(struct ClactActor *actor, u32 frame);
extern void CLACT_SetActorAnimLoopCount(struct ClactActor *actor, u32 count);
extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable);
extern void CLACT_SetActorAutoAnimSpeed(struct ClactActor *actor, u32 speed);
extern void CLACT_StartActorAnim(struct ClactActor *actor);
extern void CLACT_StopActorAnim(struct ClactActor *actor);

struct Arrow *ARROW_Create(u32 heapId, const struct ArrowResources *resources);
u32 ARROW_Destroy(struct Arrow *arrow);
void ARROW_Layout(struct Arrow *arrow, int tipX, int tipY, int cornerX, int endY);
void ARROW_Update(struct Arrow *arrow);
void ARROW_Start(struct Arrow *arrow);
void ARROW_Reset(struct Arrow *arrow);
void ARROW_RunState(struct Arrow *arrow);
void ARROW_RunIdle(struct Arrow *arrow);
void ARROW_RunDrawing(struct Arrow *arrow);
void ARROW_RunDone(struct Arrow *arrow);
void ARROW_SetState(struct Arrow *arrow, u32 state);
u32 ARROW_IsComplete(struct Arrow *arrow);
void ARROW_ShowPart(struct Arrow *arrow, int index);
void ARROW_StopPart(struct Arrow *arrow, u32 index);
void ARROW_HideAll(struct Arrow *arrow);
void ARROW_BuildParts(struct Arrow *arrow, int tipX, int tipY, int cornerX, int endY);
void ARROW_InitPart(struct ArrowPart *part, u8 x, u8 y, u32 startTime, u32 kind);
struct Arrow *ARROW_Alloc(u32 heapId);
void ARROW_Init(struct Arrow *arrow, u32 heapId);
u32 ARROW_Free(struct Arrow *arrow);
void ARROW_CreateUnit(struct Arrow *arrow);
void ARROW_DeleteUnit(struct Arrow *arrow);
void ARROW_CreateActors(struct Arrow *arrow);
void ARROW_DeleteActors(struct Arrow *arrow);
void ARROW_SetResources(struct Arrow *arrow, const struct ArrowResources *resources);
u32 GRAPHTABLE_GetEntryId(const struct GraphTable *table, u32 group, u8 entry);
u32 GRAPHTABLE_GetEntryRed(const struct GraphTable *table, u32 group, u32 entry);
u32 GRAPHTABLE_GetEntryGreen(const struct GraphTable *table, u32 group, u32 entry);
u32 GRAPHTABLE_GetEntryBlue(const struct GraphTable *table, u32 group, u32 entry);
u32 GRAPHTABLE_FindGroup(const struct GraphTable *table, u32 key);
u32 GRAPHTABLE_FindEntry(const struct GraphTable *table, u8 key, u8 entryId);

/* Allocates an arrow, sets it up and creates its unit and actors. */
struct Arrow *ARROW_Create(u32 heapId, const struct ArrowResources *resources)
{
    struct Arrow *arrow = ARROW_Alloc(heapId);
    ARROW_Init(arrow, heapId);
    ARROW_SetResources(arrow, resources);
    ARROW_CreateUnit(arrow);
    ARROW_CreateActors(arrow);
    return arrow;
}

/* Deletes the actors and the unit, then frees the arrow. */
u32 ARROW_Destroy(struct Arrow *arrow)
{
    ARROW_DeleteActors(arrow);
    ARROW_DeleteUnit(arrow);
    return ARROW_Free(arrow);
}

/* Veneer: lays out the parts, forwarding the fifth (stack) argument. */
void ARROW_Layout(struct Arrow *arrow, int tipX, int tipY, int cornerX, int endY)
{
    ARROW_BuildParts(arrow, tipX, tipY, cornerX, endY);
}

/* Veneer: advances the animation by one frame. */
void ARROW_Update(struct Arrow *arrow)
{
    ARROW_RunState(arrow);
}

/* Veneer: starts drawing the arrow. */
void ARROW_Start(struct Arrow *arrow)
{
    ARROW_SetState(arrow, ARROW_STATE_DRAWING);
}

/* Returns to the idle state and hides every part. */
void ARROW_Reset(struct Arrow *arrow)
{
    ARROW_SetState(arrow, ARROW_STATE_IDLE);
    ARROW_HideAll(arrow);
}

/* Runs the handler of the current state, then advances the timer. */
void ARROW_RunState(struct Arrow *arrow)
{
    switch (arrow->state) {
    case ARROW_STATE_IDLE: ARROW_RunIdle(arrow); break;
    case ARROW_STATE_DRAWING: ARROW_RunDrawing(arrow); break;
    case ARROW_STATE_DONE: ARROW_RunDone(arrow); break;
    }
    arrow->timer++;
}

/* Empty handler of the idle state. */
void ARROW_RunIdle(struct Arrow *arrow)
{
}

/* Shows each part when its start time is reached and stops its animation at its stop time. */
void ARROW_RunDrawing(struct Arrow *arrow)
{
    s32 i;
    for (i = 0; i < arrow->partCount; i++) {
        if (arrow->parts[i].shown == 0 && arrow->parts[i].startTime <= arrow->timer)
            ARROW_ShowPart(arrow, (u8)i);
        if (arrow->parts[i].shown == 1 && arrow->parts[i].stopEnabled == 1 && arrow->parts[i].stopTime <= arrow->timer)
            ARROW_StopPart(arrow, (u8)i);
    }
    if (ARROW_IsComplete(arrow))
        ARROW_SetState(arrow, ARROW_STATE_DONE);
}

/* Empty handler of the done state. */
void ARROW_RunDone(struct Arrow *arrow)
{
}

/* Sets the state and restarts the timer. */
void ARROW_SetState(struct Arrow *arrow, u32 state)
{
    arrow->state = state;
    arrow->timer = 0;
}

/* Returns 1 when every part is shown, else 0. */
u32 ARROW_IsComplete(struct Arrow *arrow)
{
    s32 i;
    for (i = 0; i < arrow->partCount; i++) {
        if (arrow->parts[i].shown == 0)
            return 0;
    }
    return 1;
}

/*
 * Shows one part: places its actor and starts its animation from the sequence
 * of its kind. The original has no default case, so an unknown kind leaves the
 * sequence uninitialised.
 */
void ARROW_ShowPart(struct Arrow *arrow, int index)
{
    struct ArrowPart *part = &arrow->parts[index];
    struct ClactActor *actor = part->actor;
    struct SurfacePos point;
    u16 animSeq;
    point.x = part->x;
    point.y = part->y;
    part->shown = 1;
    switch (part->kind) {
    case ARROW_PART_HORIZONTAL: animSeq = arrow->resources.animSeq[0]; break;
    case ARROW_PART_VERTICAL: animSeq = arrow->resources.animSeq[1]; break;
    case ARROW_PART_CORNER_TOP: animSeq = arrow->resources.animSeq[2]; break;
    case ARROW_PART_CORNER_BOTTOM: animSeq = arrow->resources.animSeq[3]; break;
    }
    CLACT_AddActorSurfacePos(actor, &point, arrow->resources.space);
    CLACT_SetActorAnimSeq(actor, animSeq);
    CLACT_SetActorAnimFrame(actor, 0);
    CLACT_SetActorAnimLoopCount(actor, 1);
    CLACT_SetActorAutoAnim(actor, 1);
    CLACT_SetActorAutoAnimSpeed(actor, 0x12000);
    CLACT_StartActorAnim(actor);
    CLACT_SetActorDrawEnable(actor, 1);
}

/* Stops the animation of one part. */
void ARROW_StopPart(struct Arrow *arrow, u32 index)
{
    CLACT_StopActorAnim(arrow->parts[index].actor);
}

/* Hides the actor of every part. */
void ARROW_HideAll(struct Arrow *arrow)
{
    s32 i;
    s32 n = arrow->partCount;
    for (i = 0; i < n; i++)
        CLACT_SetActorDrawEnable(arrow->parts[i].actor, 0);
}

/*
 * Lays out the parts of an arrow from (tipX, tipY) left to the corner at
 * cornerX, then down to endY, one part per 8 pixels. The start times f count
 * parts in units of one frame, with a fractional step for a short last piece.
 * Source shape (declaration order, statement order of i, f, y) follows the
 * original code generation. EXACT* = 690 bytes compiled, listing extent 692
 * (trailing pad).
 */
void ARROW_BuildParts(struct Arrow *arrow, int tipX, int tipY, int cornerX, int endY)
{
    int i;
    float f = 0.0f;
    int j;
    int yb;
    int w = tipX - cornerX;
    int half = (w - 4) / 8;
    int half2;
    int w2;
    int xx;
    int y;
    int r;

    i = 0;
    yb = tipY - 4;
    tipX -= 8;

    for (j = 0; j < half; j++) {
        ARROW_InitPart(&arrow->parts[i], tipX, yb, (u32)f, ARROW_PART_HORIZONTAL);
        tipX -= 8;
        f += 1.0f;
        i++;
    }
    if (half == 0) {
        if (w - 4 > 0) {
            ARROW_InitPart(&arrow->parts[i], tipX, yb, (u32)f, ARROW_PART_HORIZONTAL);
            if (w - 4 < 4) {
                arrow->parts[i].stopEnabled = 1;
                arrow->parts[i].stopTime = 1;
            }
            f = f + (2.0f * (float)(w - 4) / 8.0f - 1.0f);
            i++;
        }
    } else if ((w - 4) % 8 != 0) {
        r = (w - 4) - half * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        ARROW_InitPart(&arrow->parts[i], cornerX + 4, yb, (u32)f, ARROW_PART_HORIZONTAL);
        f += 1.0f;
        i++;
    }
    ARROW_InitPart(&arrow->parts[i], cornerX - 4, tipY - 4, (u32)f, ARROW_PART_CORNER_TOP);
    f += 1.0f;
    i++;
    w2 = endY - tipY;
    half2 = (w2 - 4) / 8;
    xx = cornerX - 4;
    y = tipY + 4;
    for (j = 0; j < half2; j++) {
        ARROW_InitPart(&arrow->parts[i], xx, y, (u32)f, ARROW_PART_VERTICAL);
        y += 8;
        f += 1.0f;
        i++;
    }
    if ((w2 - 4) % 8 != 0) {
        r = (w2 - 4) - half2 * 8;
        f = f - (2.0f - 2.0f * (float)r / 8.0f);
        ARROW_InitPart(&arrow->parts[i], xx, endY - 8, (u32)f, ARROW_PART_VERTICAL);
        f += 1.0f;
        i++;
    }
    ARROW_InitPart(&arrow->parts[i], cornerX - 4, endY - 4, (u32)f, ARROW_PART_CORNER_BOTTOM);
    arrow->partCount = i + 1;
}

/* Initialises one part: position, start time and kind, with the stop fields cleared. */
void ARROW_InitPart(struct ArrowPart *part, u8 x, u8 y, u32 startTime, u32 kind)
{
    part->x = x;
    part->shown = 0;
    part->stopEnabled = 0;
    part->stopTime = 0;
    part->y = y;
    part->startTime = startTime;
    part->kind = kind;
}

/* Allocates the arrow object. */
struct Arrow *ARROW_Alloc(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 668, 0, (const char *)0x21C4074, 558);
}

/* Initialises the arrow and clears its parts. */
void ARROW_Init(struct Arrow *arrow, u32 heapId)
{
    int i;
    arrow->heapId = heapId;
    arrow->state = 0;
    arrow->timer = 0;
    arrow->partCount = 0;
    arrow->unit = 0;
    for (i = 0; i < ARROW_MAX_PARTS; i++) {
        arrow->parts[i].shown = 0;
        arrow->parts[i].startTime = 0;
        arrow->parts[i].stopEnabled = 0;
        arrow->parts[i].stopTime = 0;
        arrow->parts[i].x = 0;
        arrow->parts[i].y = 0;
        arrow->parts[i].actor = 0;
    }
}

/* Frees the arrow object. */
u32 ARROW_Free(struct Arrow *arrow)
{
    return GFL_HEAP_Free(arrow);
}

/* Creates the CLACT unit with room for every part. */
void ARROW_CreateUnit(struct Arrow *arrow)
{
    arrow->unit = CLACT_CreateUnit(ARROW_MAX_PARTS, 0, arrow->heapId);
}

/* Deletes the CLACT unit. */
void ARROW_DeleteUnit(struct Arrow *arrow)
{
    CLACT_DeleteUnit(arrow->unit);
}

/*
 * Creates one actor per part. The original stores the returned pointer, so
 * the declaration of CLACT_CreateActor keeps its return value.
 */
void ARROW_CreateActors(struct Arrow *arrow)
{
    struct ActorHeader header;
    const struct ArrowResources *res = &arrow->resources;
    int i = 0;
    header.x = 0;
    header.y = 0;
    header.z = 0;
    header.animNo = 0;
    header.bgPriority = 0;
    for (; i < ARROW_MAX_PARTS; i++) {
        arrow->parts[i].actor = CLACT_CreateActor(arrow->unit, res->charId, res->paletteId, res->cellId, &header, res->space, arrow->heapId);
    }
}

/* Deletes the actor of every part. */
void ARROW_DeleteActors(struct Arrow *arrow)
{
    int i;
    for (i = 0; i < ARROW_MAX_PARTS; i++)
        CLACT_DeleteActor(arrow->parts[i].actor);
}

/* Copies the resource description into the arrow. */
void ARROW_SetResources(struct Arrow *arrow, const struct ArrowResources *resources)
{
    arrow->resources = *resources;
}

/* Returns the id of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryId(const struct GraphTable *table, u32 group, u8 entry)
{
    return table->groups[group].entries[entry].id;
}

/* Returns the red component of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryRed(const struct GraphTable *table, u32 group, u32 entry)
{
    return table->groups[group].entries[entry].red;
}

/* Returns the green component of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryGreen(const struct GraphTable *table, u32 group, u32 entry)
{
    return table->groups[group].entries[entry].green;
}

/* Returns the blue component of an entry of a graph group. */
u32 GRAPHTABLE_GetEntryBlue(const struct GraphTable *table, u32 group, u32 entry)
{
    return table->groups[group].entries[entry].blue;
}

/* Returns the index of the group with the given key, or zero. */
u32 GRAPHTABLE_FindGroup(const struct GraphTable *table, u32 key)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (table->groups[i].key == key)
            return (u8)i;
    }
    return 0;
}

/* Returns the index of the entry with the given id in the group with the given key, or zero. */
u32 GRAPHTABLE_FindEntry(const struct GraphTable *table, u8 key, u8 entryId)
{
    s32 i;
    const struct GraphTableGroup *group;
    group = &table->groups[GRAPHTABLE_FindGroup(table, key)];
    for (i = 0; i < group->entryCount; i++) {
        if (entryId == group->entries[i].id)
            return (u8)i;
    }
    return 0;
}
