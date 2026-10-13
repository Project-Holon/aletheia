#ifndef GAME_OV067_UI_SCENE_TYPES_H
#define GAME_OV067_UI_SCENE_TYPES_H

/*
 * Base types of overlay 67 (ui_scene.c): the scene runner and the actor
 * graphics set that touchbar.c and yesno_menu.c also use.
 * Needs u8, u16 and u32 to be defined before it is included.
 */

/* Sprite actor of the actor system; its layout belongs to that module. */
struct Actor;

struct UiScene;

typedef int (*UiSceneStepFn)(struct UiScene *scene, void *userData);

/* One scene: five step functions, 0x14 bytes. A null step is skipped. */
struct UiSceneEntry {
    UiSceneStepFn beginPoll; /* polled until it returns nonzero */
    UiSceneStepFn begin;     /* called once */
    UiSceneStepFn update;    /* called each frame until it returns nonzero */
    UiSceneStepFn end;       /* called once */
    UiSceneStepFn endPoll;   /* polled until it returns nonzero */
};

/* Phase of UiScene.phase, in the order UI_SCENE_Step runs them. */
#define UI_SCENE_PHASE_BEGIN_POLL 0
#define UI_SCENE_PHASE_BEGIN 1
#define UI_SCENE_PHASE_UPDATE 2
#define UI_SCENE_PHASE_END_POLL 3
#define UI_SCENE_PHASE_NEXT 4

/* Scene to switch to when nextSceneIndex holds none / asks to finish. */
#define UI_SCENE_NONE 0xFFFF
#define UI_SCENE_FINISH 0xFFFE

struct UiScene {
    const struct UiSceneEntry *entries;
    void *userData;
    u16 sceneIndex;
    u16 nextSceneIndex;
    u8 param;
    u8 phase;
    u8 phaseFrames;
    u8 pad0F;
};

/* Handles of the actor resources made by UI_SCENE_LoadActorGfx. */
typedef struct {
    int plttHandle;
    int charHandle;
    int animHandle;
    int screen;
} ActorGfxSet;

/* Request for UI_SCENE_LoadActorGfx. */
typedef struct {
    int screen;
    u32 flags;
    int arcId;
    int charId;
    int plttId;
    int cellId;
    int animId;
    u8 plttSlot;
    u8 charBase;
    u8 charSize;
} ActorGfxDesc;

typedef struct {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} ActorRect;

#endif
