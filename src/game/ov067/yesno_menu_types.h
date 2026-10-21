#ifndef GAME_OV067_YESNO_MENU_TYPES_H
#define GAME_OV067_YESNO_MENU_TYPES_H

/*
 * Object types of the yes/no menu (yesno_menu.c).
 * Needs u8, u16 and u32 to be defined before it is included.
 */

#include "../ov067/ui_scene_types.h"

struct TextWindow;
struct PrintQueue;
struct GfFont;

/* Values of YesNoMenu.state. */
#define YESNO_MENU_STATE_IDLE 0
#define YESNO_MENU_STATE_OPENING 1
#define YESNO_MENU_STATE_WAIT_INPUT 2
#define YESNO_MENU_STATE_FLASH 3
#define YESNO_MENU_STATE_DONE 4

/* Values of YesNoMenu.answer. */
#define YESNO_MENU_ANSWER_NO 0
#define YESNO_MENU_ANSWER_YES 1
#define YESNO_MENU_ANSWER_PENDING 2

/* Palette resource block as the file parser returns it; colors holds 16-color rows. */
typedef struct {
    u8 header[0xc];
    u16 (*colors)[16];
} PlttFile;

typedef struct {
    u16 heapId;
    u16 pad02;
    void *actorSys;
    struct GfFont *font;
    struct PrintQueue *printer;
    u32 plttTarget;
    u8 buttonBgLayer;
    u8 buttonPriority;
    u8 yesPlttSlot;
    u8 noPlttSlot;
    u8 textBgLayer;
    u8 actorPriority;
    u8 textPlttSlot;
    u8 pad1B;
    u32 isSubScreen;
    u8 actorPlttSlot;
    u8 pad21;
    u16 palette[3][16];
    u16 pad82;
    u32 buttonTileAlloc;
    struct TextWindow *windowUpper;
    struct TextWindow *windowLower;
    u32 upperDone;
    u32 lowerDone;
    u32 state;
    u32 answer;
    struct Actor *buttonActors[4];
    ActorGfxSet gfx;
    u32 cursorIndex;
    u8 palAnimIndex;
    u8 padC5;
    u16 palAnimStep;
    u16 palAnimFrame;
    u8 padCA[2];
} YesNoMenu;

/* Screen position of a button actor. */
typedef struct {
    u16 x;
    u16 y;
} YesNoPoint;

/* One touch rectangle; a table ends with top == 0xFF. */
typedef struct {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} YesNoTouchRect;

/* Hit table of the two answer buttons plus the end mark. */
typedef struct {
    YesNoTouchRect rect[3];
} YesNoTouchTable;

/* Button origin per cursor position (x, y), added to the per-button offset. */
typedef struct {
    u8 v[2][2];
} YesNoCursorOrigin;

/* Offset of each of the four button actors (x, y). */
typedef struct {
    u8 v[4][2];
} YesNoButtonOffsets;

/* One step of the pressed-button palette flash: the frame it starts at and the palette row it shows. */
typedef struct {
    u16 frame;
    u16 palIndex;
} YesNoFlashStep;

#endif
