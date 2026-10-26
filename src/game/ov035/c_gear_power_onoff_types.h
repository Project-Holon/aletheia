#ifndef C_GEAR_POWER_ONOFF_TYPES_H
#define C_GEAR_POWER_ONOFF_TYPES_H

#include "../ov021/field_subscreen_types.h"

struct BmpWin;
struct GfFont;
struct MsgBank;
struct PrintQue;
struct Strbuf;

/* Values of CGearPowerOnOffWork.scene: index of the step function that runs. */
#define C_GEAR_POWER_ONOFF_SCENE_TURN_ON 0
#define C_GEAR_POWER_ONOFF_SCENE_TURN_OFF 1
#define C_GEAR_POWER_ONOFF_SCENE_UNAVAILABLE 2

/*
 * Work of the C-Gear power on/off panel (sub-screen mode 9, overlay 35).
 * Allocated with 0x50 bytes by C_GEAR_POWER_ONOFF_Create. Two text windows
 * and a yes/no task menu drive one of three step functions (scene).
 */
typedef struct CGearPowerOnOffWork {
    u16 heapId;
    u16 padHeap;
    void *gameSystem;
    void *beacon;                  /* communication state, from the game system */
    FieldSubscreen *subscreen;     /* sub-screen that owns this panel */
    u32 bgCharAlloc;               /* BG 6 character area: offset in the low half, size in the high half */
    u32 bmpMenuWork;
    struct BmpWin *messageWindow;  /* upper window: question and result message */
    struct BmpWin *menuWindow;     /* lower window: note next to the menu */
    void *tcbl;
    void *printStream;
    struct Strbuf *streamMessage;
    u32 reserved2C;
    void *keyCursor;
    struct GfFont *font;
    struct MsgBank *msgBank;
    struct PrintQue *printQue;
    void *taskMenuRes;
    void *taskMenu;                /* open yes/no menu, 0 when closed */
    u16 scene;                     /* C_GEAR_POWER_ONOFF_SCENE_* */
    u16 step;                      /* state of the running step function */
    u16 closeComm;                 /* turn-off scene: communication must be closed before the flag is cleared */
    u16 closeRequested;            /* the sub-screen was asked to close */
} CGearPowerOnOffWork;

#endif
