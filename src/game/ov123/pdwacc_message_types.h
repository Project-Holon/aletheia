/* Work area of the Pokemon Dream World account message system (pdwacc_message.c). */
#ifndef PDWACC_MESSAGE_TYPES_H
#define PDWACC_MESSAGE_TYPES_H

#include "../ov123/gsync_common_types.h"
#include "../ov123/gsync_menu_types.h"

struct WordSet;

/* 0xB4 bytes, one instance per proc. */
typedef struct PdwaccMessageWork {
    u32 bg1Frame;               /* 0x00, frame allocation of BG 1, packed halves */
    u32 bg6Frame;               /* 0x04, frame allocation of BG 6 (sub screen) */
    u32 bg5Frame;               /* 0x08, frame allocation of BG 5 (main screen) */
    u8 unused_0C[16];           /* never accessed */
    void *buttonMan;            /* 0x1C */
    void *msgData;              /* 0x20 */
    struct WordSet *wordSet;    /* 0x24 */
    void *font;                 /* 0x28 */
    void *msgBuf;               /* 0x2C, 400 chars */
    void *tmpBuf;               /* 0x30, 400 chars */
    u8 unused_34[12];           /* never accessed */
    void *codeWin;              /* 0x40, BG 1 window with the account code */
    void *labelWin;             /* 0x44, label below the code */
    void *mainWin;              /* 0x48, BG 5 message window */
    void *subWin;               /* 0x4C, BG 6 message window */
    void *windows[12];          /* 0x50, extra windows, deleted on exit */
    void *printStream;          /* 0x80 */
    u8 unused_84[4];            /* never accessed */
    void *tcbl;                 /* 0x88 */
    void *printQue;             /* 0x8C */
    u8 *timeIcon;               /* 0x90 */
    TaskMenuItem menuItems[2];  /* 0x94, Yes and No */
    void *taskMenuRes;          /* 0xAC */
    u16 heap;                   /* 0xB0 */
} PdwaccMessageWork;

#endif
