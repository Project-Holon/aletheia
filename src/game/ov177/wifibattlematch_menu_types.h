#ifndef GAME_OV177_WIFIBATTLEMATCH_MENU_TYPES_H
#define GAME_OV177_WIFIBATTLEMATCH_MENU_TYPES_H

#include "../types.h"

/* Menu descriptor (0x30 bytes) handed to WIFIBATTLEMATCH_UTIL_CreateMenu; ov175, ov176 and ov177 share it. */
typedef struct WifibattlematchMenuDesc {
    u32 msgBank;             /* 0x00 message bank */
    u32 font;                  /* 0x04 font (BmpMenuList font) */
    u32 printQue;             /* 0x08 PRINTSYS_QUE handle */
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
