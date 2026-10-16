#ifndef PMSIV_MENU_SHARED_TYPES_H
#define PMSIV_MENU_SHARED_TYPES_H

#include "pms_input_view_shared_types.h"

#define PMSIV_MENU_TEXT_COUNT 3
#define PMSIV_MENU_ITEM_COUNT 8
#define PMSIV_MENU_EXTRA_COUNT 2
#define PMSIV_MENU_BLEND_COLORS 5

struct AppTaskMenuRes;
struct AppTaskMenuWin;
struct ClactActor;
struct MsgData;

/* Entry record read by APP_TASKMENU_WIN_Create. */
struct PmsivMenuEntry {
    void *text;
    u16 color;
    u16 pad;
    int selected;
};

/*
 * Menu part of the PMS input view: the bottom row of task menu buttons, the
 * touch-screen sprite buttons and the pulsing colour of the selected one.
 */
struct PmsivMenu {
    struct PmsInputView *view;
    struct PmsInput *input;
    struct PmsInputData *wordData;
    const u32 *uiInputMode;
    struct PmsInputViewSpriteRes itemRes;
    u32 backPalette;
    u32 backCharacter;
    u32 backCellAnim;
    struct ClactActor *backButton;
    int backButtonState;
    struct MsgData *msgData;
    struct AppTaskMenuRes *taskMenuRes[PMSIV_MENU_TEXT_COUNT];
    struct PmsivMenuEntry entries[PMSIV_MENU_TEXT_COUNT];
    struct AppTaskMenuWin *taskMenuWin[PMSIV_MENU_TEXT_COUNT];
    struct ClactActor *items[PMSIV_MENU_ITEM_COUNT];
    struct ClactActor *extraItems[PMSIV_MENU_EXTRA_COUNT];
    u16 baseColors[PMSIV_MENU_BLEND_COLORS];
    u16 targetColors[PMSIV_MENU_BLEND_COLORS];
    u16 blendColors[PMSIV_MENU_BLEND_COLORS];
    int blendPhase;
};

/*
 * Opaque tags still used by the other pms_input files' extern declarations;
 * they go away when those files name their own types.
 */
struct TaskMenuState;

#endif
