#ifndef GAME_OV067_TOUCHBAR_TYPES_H
#define GAME_OV067_TOUCHBAR_TYPES_H

#include "../types.h"

/*
 * Types of the touch bar (touchbar.c): a row of touch-screen buttons, each
 * one an actor that plays an animation while it is pressed. The includer
 * defines u8, u16 and u32 first.
 */

struct Actor;
struct Unit;

#define TOUCHBAR_NO_BUTTON 0xffffffff

/* TouchBar.state */
#define TOUCHBAR_STATE_IDLE      0
#define TOUCHBAR_STATE_PRESSED   1
#define TOUCHBAR_STATE_ANIMATING 2
#define TOUCHBAR_STATE_DONE      3

/* TouchBarButtonDef.kind: below this value the built-in look table is used. */
#define TOUCHBAR_KIND_CUSTOM 7

/* Resource handles of the touch bar (char, palette, cell animation) and its tile range. */
typedef struct {
    int plttHandle;
    int charHandle;
    int animHandle;
    u32 bgLayer;
    u32 tileAlloc;
} TouchBarGfx;

/* One button of the bar as the caller describes it. */
typedef struct {
    int kind;
    short x;
    short y;
    u16 charRes;
    u16 plttRes;
    u16 animRes;
    u16 animIdle;
    u16 animDisabled;
    u16 animDown;
    u16 animDownAlt;
    u16 pad16;
    u32 keyMask;
    u32 soundId;
} TouchBarButtonDef;

/* Built-in button look, indexed by TouchBarButtonDef.kind below TOUCHBAR_KIND_CUSTOM. */
typedef struct {
    u16 animIdle;
    u16 animDisabled;
    u16 animDown;
    u16 animDownAlt;
    u16 soundId;
    u16 padA;
    u32 keyMask;
    u32 style;
} TouchBarButtonLook;

/* Start state passed to the actor creation call (leading part of the actor init request). */
typedef struct {
    short x;
    short y;
    u16 animSeq;
    u8 drawPriority;
    u8 bgPriority;
} TouchBarActorInit;

struct TouchBarButton;

typedef struct TouchBarButton {
    struct Actor *actor;
    u32 enabled;
    u32 anim;
    void (*onPress)(struct TouchBarButton *button);
    void (*setEnabled)(struct TouchBarButton *button, u32 enabled);
    u32 style;
    TouchBarButtonDef def;
} TouchBarButton;

/* Request for TOUCHBAR_Create. */
typedef struct {
    TouchBarButtonDef *defs;
    u32 count;
    struct Unit *actorSys;
    u32 bgLayer;
    u32 bgPlttSlot;
    u32 actorPlttSlot;
    u32 iconSet;
    u32 skipBgGfx;
} TouchBarParams;

typedef struct TouchBar {
    u32 pressedIndex;
    u32 buttonCount;
    u32 state;
    TouchBarGfx gfx;
    TouchBarButton buttons[1];
} TouchBar;

typedef char TouchBarGfx_size_check[sizeof(TouchBarGfx) == 0x14 ? 1 : -1];
typedef char TouchBarButtonDef_size_check[sizeof(TouchBarButtonDef) == 0x20 ? 1 : -1];
typedef char TouchBarButtonLook_size_check[sizeof(TouchBarButtonLook) == 0x14 ? 1 : -1];
typedef char TouchBarActorInit_size_check[sizeof(TouchBarActorInit) == 8 ? 1 : -1];
typedef char TouchBarButton_size_check[sizeof(TouchBarButton) == 0x38 ? 1 : -1];
typedef char TouchBarParams_size_check[sizeof(TouchBarParams) == 0x20 ? 1 : -1];
typedef char TouchBar_size_check[sizeof(TouchBar) == 0x58 ? 1 : -1];

struct BmpData;

/* Window the touch bar labels are printed into. */
typedef struct {
    struct BmpData *bitmap;
    u8 redraw;
} TouchBarWindow;

#endif
