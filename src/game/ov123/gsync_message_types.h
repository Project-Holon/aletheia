/* Work area of the Game Sync message system (gsync_message.c): windows, font, message data, print stream. */
#ifndef GSYNC_MESSAGE_TYPES_H
#define GSYNC_MESSAGE_TYPES_H

#include "gsync_common_types.h"
#include "gsync_menu_types.h"

struct WordSet;

/* 0xB4 bytes, one instance per proc. */
typedef struct GsyncMessageWork {
    unsigned int unused_00;     /* never accessed */
    unsigned int bg6Frame;      /* 0x04, frame allocation of BG 6 (sub screen), packed halves */
    unsigned int bg5Frame;      /* 0x08, frame allocation of BG 5 (main screen) */
    unsigned char unused_0C[16];
    void *buttonMan;            /* 0x1C */
    void *msgData;              /* 0x20 */
    void *wordSet;              /* 0x24 */
    void *font;                 /* 0x28 */
    void *msgBuf;               /* 0x2C, 400 chars */
    void *tmpBuf;               /* 0x30, 400 chars, source text before word set expansion */
    unsigned char unused_34[12];
    void *keyCursor;            /* 0x40 */
    void *mainWindow;           /* 0x44, BG 5 message window */
    void *subWindow;            /* 0x48, BG 6 window */
    void *windows[12];          /* 0x4C, extra windows, deleted on exit */
    void *timeIcon;             /* 0x7C */
    void *printStream;          /* 0x80 */
    void *tcbl;                 /* 0x84 */
    void *printQue;             /* 0x88 */
    TaskMenuItem menuItems[2]; /* 0x8C, Yes and No */
    void *taskMenuRes;          /* 0xA4 */
    unsigned char streamWait[8];/* 0xA8, state of the print wait cursor */
    unsigned short heap;        /* 0xB0 */
    unsigned char unused_B2[2]; /* tail of the 0xB4 allocation */
} GsyncMessageWork;

#endif
