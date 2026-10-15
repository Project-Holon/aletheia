#ifndef BMP_MENULIST_SHARED_TYPES_H
#define BMP_MENULIST_SHARED_TYPES_H

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

struct Bmp;

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
