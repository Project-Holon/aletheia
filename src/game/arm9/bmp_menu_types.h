#ifndef GAME_ARM9_BMP_MENU_TYPES_H
#define GAME_ARM9_BMP_MENU_TYPES_H

#include "../types.h"

struct BmpWin;

/* Print state of one window: the window and a flag set after an item was printed. */
typedef struct PrintUtil {
    struct BmpWin *win;     /* +0x00 */
    u8    transReq;         /* +0x04  1: transfer once the print queue is done */
} PrintUtil;

/* Where a menu window goes: BG layer, tile position, palette and first character. */
typedef struct WinDat {
    u8  bgFrame;            /* +0x00 */
    u8  x;                  /* +0x01 */
    u8  y;                  /* +0x02 */
    u8  palette;            /* +0x03 */
    u16 charBase;           /* +0x04  callers pass it as base */
} WinDat;

#endif
