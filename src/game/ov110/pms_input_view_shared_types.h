#ifndef PMS_INPUT_VIEW_SHARED_TYPES_H
#define PMS_INPUT_VIEW_SHARED_TYPES_H

#include "pms_input_data_shared_types.h"

#define PMS_INPUT_VIEW_TASK_SLOTS 4
#define PMS_INPUT_VIEW_SCREEN_COUNT 2

struct PmsInput;
struct PmsInputData;
struct PmsivEdit;
struct PmsivCategory;
struct PmsivWordwin;
struct PmsivMenu;
struct Unit;
struct BmpWin;
struct PrintQue;
struct GfFont;

/* Sprite resource handles of one screen (input or sub), as returned by the CLACT register calls. */
struct PmsInputViewSpriteRes {
    u32 palette;
    u32 character;
    u32 cellAnim;
};

/* Position record read by the actor creator CLACT_CreateActor. */
struct ClactActorSetup {
    short x;
    short y;
    short z;
    u8 priority;
    u8 mode;
};

/*
 * Work object of the PMS input screen view. It owns the sprite system, the
 * display setup and the four sub-views (edit, category, word window, menu).
 * Shared by pms_input_view.c and the pmsiv_* files.
 */
struct PmsInputView {
    void *mainTask;
    void *vblankTask;
    void *eventTasks[PMS_INPUT_VIEW_TASK_SLOTS];
    struct PmsInput *input;
    struct PmsInputData *wordData;
    struct Unit *clactUnit;
    struct PmsInputViewSpriteRes uiRes[PMS_INPUT_VIEW_SCREEN_COUNT];
    struct PmsInputViewSpriteRes cursorRes[PMS_INPUT_VIEW_SCREEN_COUNT];
    struct PmsivEdit *edit;
    struct PmsivCategory *category;
    struct PmsivWordwin *wordwin;
    u8 pad60[4];
    struct PmsivMenu *menu;
    u16 helpBgColor[2];
    struct BmpWin *helpWin;
    u32 helpTextPending;
    u8 inWordPick;
    u8 pad75[3];
    const u32 *uiInputMode;
    struct PrintQue *printQue;
    struct GfFont *font;
    u32 paletteChanged;
    u32 paletteVariant;
    void *arcHandle;
};

/* Work of one view event task (registered from the callback table by PMS_INPUT_VIEW_StartTask). */
struct PmsInputViewTask {
    struct PmsInputView *view;
    struct PmsInput *input;
    struct PmsInputData *wordData;
    int id;
    int slot;
    int state;
};

/*
 * Opaque SDK object tags still used by the other pms_input files' extern
 * declarations; they go away when those files name their own types.
 */
struct Cfg;
struct Bank;
struct Node;
struct PrintSys;
struct Descriptor;
struct CharBuf;
struct BgTemplate;
struct DispConfig;
struct DispVram;
struct Obj;
struct Actor;
struct Vec2;
struct MsgBank;
struct Rec;
struct U16Vec;

#endif
