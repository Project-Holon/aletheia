/*
 * file:     ui_scene.c
 * unit:     yes
 * function: UI_SCENE_Create, UI_SCENE_Delete, UI_SCENE_Step, UI_SCENE_SetNextScene, UI_SCENE_GetPhaseFrame, UI_SCENE_AdvancePhaseFrame, UI_SCENE_LoadActorGfx, UI_SCENE_FreeActorGfx, UI_SCENE_CreateActor
 * address:  0x021B6100
 * region:   ov067
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_021B9540     0x021B9540  data  a1
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#include "ui_scene_types.h"

/* UiScene is allocated with this size; the header comment of ui_scene_types.h has the layout. */
#define UI_SCENE_SIZE 0x10

/* ActorGfxDesc.flags */
#define ACTOR_GFX_FLAG_NO_CHAR_RANGE 0x1 /* load the character data without charBase and charSize */
#define ACTOR_GFX_FLAG_PLTT_OPTION 0x2   /* passed to the palette loader as its option */

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 v, u32 n);
extern u32 GFL_HEAP_Free(void *p);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern int CLACT_RegisterPaletteCompressed(void *arc, u32 charId, u32 screen, u32 plttOffset, u16 heapId);
extern int CLACT_RegisterPaletteEx(void *arc, u32 charId, u32 screen, u32 plttOffset, u16 charBase, u16 charSize, u32 heapId);
extern int CLACT_RegisterCharacter(void *arc, u32 plttId, u32 option, u32 screen, u32 heapId);
extern int CLACT_RegisterCellAnim(void *arc, u32 cellId, u32 animId, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void *arc);
extern void CLACT_ReleasePalette(unsigned int charHandle);
extern void CLACT_ReleaseCharacter(unsigned int plttHandle);
extern void CLACT_ReleaseCellAnim(unsigned int animHandle);
extern struct Actor *CLACT_CreateActor(void *actorSys, unsigned int plttHandle, unsigned int charHandle, unsigned int animHandle, const void *rect, u16 screen, u16 heapId);
extern void CLACT_SetActorAnimSeq(struct Actor *actor, u16 animIndex);
struct UiScene *UI_SCENE_Create(u32 heapId, const struct UiSceneEntry *entries, u8 param, u16 sceneIndex, void *userData);
void UI_SCENE_Delete(struct UiScene *scene);
int UI_SCENE_Step(struct UiScene *scene);
void UI_SCENE_SetNextScene(struct UiScene *scene, int nextSceneIndex);
unsigned UI_SCENE_GetPhaseFrame(const struct UiScene *scene);
void UI_SCENE_AdvancePhaseFrame(struct UiScene *scene);
void UI_SCENE_LoadActorGfx(ActorGfxSet *out, ActorGfxDesc *desc, void *actorSys, u16 heapId);
void UI_SCENE_FreeActorGfx(ActorGfxSet *gfx);
struct Actor *UI_SCENE_CreateActor(ActorGfxSet *gfx, void *actorSys, u16 x, u16 y, u8 animIndex, u16 heapId);
extern const char d_021B9540[];


struct UiScene *UI_SCENE_Create(u32 heapId, const struct UiSceneEntry *entries, u8 param, u16 sceneIndex, void *userData)
{
    struct UiScene *scene;

    scene = GFL_HEAP_Alloc(heapId, UI_SCENE_SIZE, 0, d_021B9540, 0x4e);
    MI_CpuFill8(scene, 0, UI_SCENE_SIZE);
    scene->entries = entries;
    scene->param = param;
    scene->userData = userData;
    scene->sceneIndex = sceneIndex;
    scene->nextSceneIndex = UI_SCENE_NONE;
    return scene;
}


void UI_SCENE_Delete(struct UiScene *scene)
{
    GFL_HEAP_Free(scene);
}


/* Runs the current scene one step. Returns 1 when the scene list asks to finish. */
int UI_SCENE_Step(struct UiScene *scene)
{
    const struct UiSceneEntry *entry = &scene->entries[scene->sceneIndex];

    switch (scene->phase) {
    case UI_SCENE_PHASE_BEGIN_POLL:
        if (entry->beginPoll == 0) {
            scene->phase = UI_SCENE_PHASE_BEGIN;
        } else {
            if (entry->beginPoll(scene, scene->userData) == 0)
                break;
            scene->phaseFrames = 0;
            scene->phase = UI_SCENE_PHASE_BEGIN;
            break;
        }
        /* fallthrough */
    case UI_SCENE_PHASE_BEGIN:
        if (entry->begin != 0)
            entry->begin(scene, scene->userData);
        scene->phase = UI_SCENE_PHASE_UPDATE;
        /* fallthrough */
    case UI_SCENE_PHASE_UPDATE:
        if (entry->update(scene, scene->userData) == 0)
            break;
        scene->phaseFrames = 0;
        if (entry->end != 0)
            entry->end(scene, scene->userData);
        scene->phase = UI_SCENE_PHASE_END_POLL;
        break;
    case UI_SCENE_PHASE_END_POLL:
        if (entry->endPoll == 0) {
            scene->phase = UI_SCENE_PHASE_NEXT;
        } else {
            if (entry->endPoll(scene, scene->userData) == 0)
                break;
            scene->phaseFrames = 0;
            scene->phase = UI_SCENE_PHASE_NEXT;
            break;
        }
        /* fallthrough */
    case UI_SCENE_PHASE_NEXT: {
        u16 next = scene->nextSceneIndex;

        scene->nextSceneIndex = UI_SCENE_NONE;
        scene->sceneIndex = next;
        if (next == UI_SCENE_FINISH)
            return 1;
        scene->phase = UI_SCENE_PHASE_BEGIN_POLL;
        scene->phaseFrames = 0;
        break;
    }
    }
    return 0;
}


void UI_SCENE_SetNextScene(struct UiScene *scene, int nextSceneIndex)
{
    scene->nextSceneIndex = nextSceneIndex;
}


unsigned UI_SCENE_GetPhaseFrame(const struct UiScene *scene)
{
    return scene->phaseFrames;
}


/* Advances the frame counter of the current phase; callers in other overlays pair it with UI_SCENE_GetPhaseFrame. */
void UI_SCENE_AdvancePhaseFrame(struct UiScene *scene)
{
    scene->phaseFrames++;
}


/* Loads the character, palette and cell animation resources of a desc into out. */
void UI_SCENE_LoadActorGfx(ActorGfxSet *out, ActorGfxDesc *desc, void *actorSys, u16 heapId)
{
    int plttOption;
    void *arc;

    plttOption = desc->flags & ACTOR_GFX_FLAG_PLTT_OPTION;
    arc = ARC_TOOL_CreateHandle(desc->arcId, heapId);
    if (desc->flags & ACTOR_GFX_FLAG_NO_CHAR_RANGE)
        out->charHandle = CLACT_RegisterPaletteCompressed(arc, desc->charId, desc->screen, (u16)(desc->plttSlot << 5), heapId);
    else
        out->charHandle = CLACT_RegisterPaletteEx(arc, desc->charId, desc->screen, (u16)(desc->plttSlot << 5), desc->charBase, desc->charSize, heapId);
    out->plttHandle = CLACT_RegisterCharacter(arc, desc->plttId, plttOption, desc->screen, heapId);
    out->animHandle = CLACT_RegisterCellAnim(arc, desc->cellId, desc->animId, heapId);
    out->screen = desc->screen;
    ARC_TOOL_DeleteHandle(arc);
}


void UI_SCENE_FreeActorGfx(ActorGfxSet *gfx)
{
    CLACT_ReleasePalette(gfx->charHandle);
    CLACT_ReleaseCharacter(gfx->plttHandle);
    CLACT_ReleaseCellAnim(gfx->animHandle);
}


struct Actor *UI_SCENE_CreateActor(ActorGfxSet *gfx, void *actorSys, u16 x, u16 y, u8 animIndex, u16 heapId)
{
    ActorRect rect = {0, 0, 0, 0};
    struct Actor *actor;

    rect.x = x;
    rect.y = y;
    actor = CLACT_CreateActor(actorSys, gfx->plttHandle, gfx->charHandle, gfx->animHandle, &rect, (u16)gfx->screen, heapId);
    CLACT_SetActorAnimSeq(actor, animIndex);
    return actor;
}
