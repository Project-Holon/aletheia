#ifndef GAME_OV177_WIFIBATTLEMATCH_MENU_TYPES_H
#define GAME_OV177_WIFIBATTLEMATCH_MENU_TYPES_H

#include "../types.h"

struct GfFont;
struct PrintQueue;
struct WifibattlematchCallback;

/* Step function of a task callback record: the record itself, its state word, and the owner work object. */
typedef void (*WifibattlematchCallbackFn)(struct WifibattlematchCallback *self, int *state, void *work);

/* Menu descriptor (0x30 bytes) handed to WIFIBATTLEMATCH_UTIL_CreateMenu; ov175, ov176 and ov177 share it. */
typedef struct WifibattlematchMenuDesc {
    struct MsgBank *msgBank;             /* 0x00 message bank */
    struct GfFont *font;       /* 0x04 font (BmpMenuList font) */
    struct PrintQueue *printQue; /* 0x08 print queue */
    u32 items[4];       /* 0x0C up to four item value ids */
    u32 count;          /* 0x1C item count */
    u16 a;              /* 0x20 */
    u16 b;              /* 0x22 */
    u16 c;              /* 0x24 */
    u16 d;              /* 0x26 */
    int enabled;        /* 0x28 cursor enabled */
    u16 kind;           /* 0x2C */
    u16 row;            /* 0x2E first row (BMP_MENULIST_Create third argument) */
} WifibattlematchMenuDesc;

#endif
