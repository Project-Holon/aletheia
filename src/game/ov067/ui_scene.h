#ifndef GAME_OV067_UI_SCENE_H
#define GAME_OV067_UI_SCENE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ui_scene.c, prototypes copied from their definitions. */

struct UiScene;
struct UiSceneEntry;
struct Actor;

#include "../types.h"
#include "../ov067/ui_scene_types.h"
#include "../ov067/ui_scene_types.h"

struct UiScene *UI_SCENE_Create(u32 heapId, const struct UiSceneEntry *entries, u8 param, u16 sceneIndex, void *userData);
void UI_SCENE_Delete(struct UiScene *scene);
int UI_SCENE_Step(struct UiScene *scene);
void UI_SCENE_SetNextScene(struct UiScene *scene, int nextSceneIndex);
unsigned UI_SCENE_GetPhaseFrame(const struct UiScene *scene);
void UI_SCENE_AdvancePhaseFrame(struct UiScene *scene);
void UI_SCENE_LoadActorGfx(ActorGfxSet *out, ActorGfxDesc *desc, void *actorSys, u16 heapId);
void UI_SCENE_FreeActorGfx(ActorGfxSet *gfx);
struct Actor *UI_SCENE_CreateActor(ActorGfxSet *gfx, void *actorSys, u16 x, u16 y, u8 animIndex, u16 heapId);
/* END mkheaders: generated region */

#endif
