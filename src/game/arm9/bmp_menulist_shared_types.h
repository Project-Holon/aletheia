#ifndef BMP_MENULIST_SHARED_TYPES_H
#define BMP_MENULIST_SHARED_TYPES_H

#include "../types.h"

#include "../arm9/bmp_shared_types.h"

struct BmpWin;

/* Print target of a menu window: the window and a dirty flag. */
struct MenuTarget {
    struct BmpWin *win;
    u8             dirty;
};

/* The cursor object: 12 bytes. */
struct MenuCursor {
    u32         mode;
    void       *aux;
    struct Bmp *tile;
};

#endif
