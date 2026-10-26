#ifndef GAME_ARM9_BMP_WIN_TYPES_H
#define GAME_ARM9_BMP_WIN_TYPES_H

#include "../types.h"

struct Bmp;

/* A bitmap window: a rectangle of a BG layer backed by a Bmp. */
struct BmpWin {
    u16 magic : 15;          /* +0x00, BMP_WIN_MAGIC while live */
    u16 is8bpp : 1;          /*        BG layer uses 8bpp characters */
    u8  bgLayer;             /* +0x02 */
    u8  posX;                /* +0x03, in tiles */
    u8  posY;                /* +0x04 */
    u8  width;               /* +0x05, in tiles */
    u8  height;              /* +0x06 */
    u8  dispWidth;           /* +0x07, on-screen extent, starts equal to width */
    u8  dispHeight;          /* +0x08, starts equal to height */
    u8  palette;             /* +0x09 */
    u16 charOffset;          /* +0x0a, first character number in BG VRAM */
    struct Bmp *bmp;         /* +0x0c */
};

#endif
