/*
 * file:     ui_scene.c
 * unit:     yes
 * function: func_021B6100, func_021B613C, func_021B6144, func_021B61F8, func_021B61FC, func_021B6200, func_021B6208, func_021B6284, func_021B629C
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
 *   func_02030734  0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_021B9540     0x021B9540  data  a1
 *   func_020307B0 0x020307B0 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u32 func_020307B0(void *p);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *arc, u32 charId, u32 screen, u32 plttOffset, u16 heapId);
extern int func_0204AC18(void *arc, u32 charId, u32 screen, u32 plttOffset, u16 charBase, u16 charSize, u32 heapId);
extern int func_0204A6C8(void *arc, u32 plttId, u32 option, u32 screen, u32 heapId);
extern int func_0204AF28(void *arc, u32 cellId, u32 animId, u32 heapId);
extern void func_02049238(void *arc);
extern void func_0204ADA4(unsigned int charHandle);
extern void func_0204A8D4(unsigned int plttHandle);
extern void func_0204AFD8(unsigned int animHandle);
extern struct Actor *func_0204B294(void *actorSys, unsigned int plttHandle, unsigned int charHandle, unsigned int animHandle, const void *rect, u16 screen, u16 heapId);
extern void func_0204B878(struct Actor *actor, u16 animIndex);
struct UiScene *func_021B6100(u32 heapId, const struct UiSceneEntry *entries, u8 param, u16 sceneIndex, void *userData);
void func_021B613C(struct UiScene *scene);
int func_021B6144(struct UiScene *scene);
void func_021B61F8(struct UiScene *scene, int nextSceneIndex);
unsigned func_021B61FC(const struct UiScene *scene);
void func_021B6200(struct UiScene *scene);
void func_021B6208(ActorGfxSet *out, ActorGfxDesc *desc, void *actorSys, u16 heapId);
void func_021B6284(ActorGfxSet *gfx);
struct Actor *func_021B629C(ActorGfxSet *gfx, void *actorSys, u16 x, u16 y, u8 animIndex, u16 heapId);
extern const char d_021B9540[];


struct UiScene *func_021B6100(u32 heapId, const struct UiSceneEntry *entries, u8 param, u16 sceneIndex, void *userData)
{
    struct UiScene *scene;

    scene = func_02030734(heapId, UI_SCENE_SIZE, 0, d_021B9540, 0x4e);
    func_02082BCC(scene, 0, UI_SCENE_SIZE);
    scene->entries = entries;
    scene->param = param;
    scene->userData = userData;
    scene->sceneIndex = sceneIndex;
    scene->nextSceneIndex = UI_SCENE_NONE;
    return scene;
}


void func_021B613C(struct UiScene *scene)
{
    func_020307B0(scene);
}


/* Runs the current scene one step. Returns 1 when the scene list asks to finish. */
int func_021B6144(struct UiScene *scene)
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


void func_021B61F8(struct UiScene *scene, int nextSceneIndex)
{
    scene->nextSceneIndex = nextSceneIndex;
}


unsigned func_021B61FC(const struct UiScene *scene)
{
    return scene->phaseFrames;
}


/* Advances the frame counter of the current phase; callers in other overlays pair it with func_021B61FC. */
void func_021B6200(struct UiScene *scene)
{
    scene->phaseFrames++;
}


/* Loads the character, palette and cell animation resources of a desc into out. */
void func_021B6208(ActorGfxSet *out, ActorGfxDesc *desc, void *actorSys, u16 heapId)
{
    int plttOption;
    void *arc;

    plttOption = desc->flags & ACTOR_GFX_FLAG_PLTT_OPTION;
    arc = func_020490F4(desc->arcId, heapId);
    if (desc->flags & ACTOR_GFX_FLAG_NO_CHAR_RANGE)
        out->charHandle = func_0204ACEC(arc, desc->charId, desc->screen, (u16)(desc->plttSlot << 5), heapId);
    else
        out->charHandle = func_0204AC18(arc, desc->charId, desc->screen, (u16)(desc->plttSlot << 5), desc->charBase, desc->charSize, heapId);
    out->plttHandle = func_0204A6C8(arc, desc->plttId, plttOption, desc->screen, heapId);
    out->animHandle = func_0204AF28(arc, desc->cellId, desc->animId, heapId);
    out->screen = desc->screen;
    func_02049238(arc);
}


void func_021B6284(ActorGfxSet *gfx)
{
    func_0204ADA4(gfx->charHandle);
    func_0204A8D4(gfx->plttHandle);
    func_0204AFD8(gfx->animHandle);
}


struct Actor *func_021B629C(ActorGfxSet *gfx, void *actorSys, u16 x, u16 y, u8 animIndex, u16 heapId)
{
    ActorRect rect = {0, 0, 0, 0};
    struct Actor *actor;

    rect.x = x;
    rect.y = y;
    actor = func_0204B294(actorSys, gfx->plttHandle, gfx->charHandle, gfx->animHandle, &rect, (u16)gfx->screen, heapId);
    func_0204B878(actor, animIndex);
    return actor;
}
