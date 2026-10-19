#ifndef BMP_SHARED_TYPES_H
#define BMP_SHARED_TYPES_H

struct Bmp;

#include "../types.h"

/* Tile byte sizes (Bmp.tileBytes): one 8x8 tile at 4 and at 8 bits per pixel. */
#define BMP_TILE_BYTES_4BPP 0x20

#define BMP_TILE_BYTES_8BPP 0x40

/*
 * A tiled character bitmap.  width and height are in pixels, the pixels are
 * stored as 8x8 tiles of tileBytes bytes each.
 */
struct Bmp {
    u8  *pixels;     /* 0x00 */
    u16  width;      /* 0x04 */
    u16  height;     /* 0x06 */
    u16  tileBytes;  /* 0x08 */
    u16  storage;    /* 0x0a, BMP_STORAGE_* */
};

#endif
