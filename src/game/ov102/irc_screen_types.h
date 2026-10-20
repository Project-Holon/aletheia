#ifndef OV102_IRC_SCREEN_TYPES_H
#define OV102_IRC_SCREEN_TYPES_H
/*
 * Screen building blocks shared by the infrared compatibility screens of ov102
 * (menu) and ov103 (touch test): sprite resources, text system and BMP window.
 * Both overlays build the same objects with the same helper code.
 */
#include "../ov101/compatible_irc_sys_types.h"
#include "../sdk_ioreg_reg.h"

#include "../types.h"

/* Handles of the sprite system; the actor table follows in each screen's own sprite set. */
typedef struct IrcSpriteResources {
    void *unit;                      /* 0x00 sprite unit (actor bank) */
    int palette;                     /* 0x04 palette handle */
    int characters;                  /* 0x08 character data handle */
    int cellAnim;                    /* 0x0C cell animation handle */
} IrcSpriteResources;

#include "../ov102/irc_text_system_types.h"

/* Text window: a BMP window, its string buffer and a pending-print flag (20 bytes). */
typedef struct IrcWindow {
    void *bmpWin;                    /* 0x00 window the text is cleared in */
    void *printWin;                  /* 0x04 window the text is printed to (same as bmpWin) */
    u8 printPending;                 /* 0x08 set after a print is queued, cleared when it is done */
    u8 pad09[3];
    void *strBuf;                    /* 0x0C message buffer */
    u16 fillColor;                   /* 0x10 color index the window is cleared with */
} IrcWindow;

#endif
