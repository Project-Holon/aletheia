#ifndef GAME_OV016_DWCUTIL_TYPES_H
#define GAME_OV016_DWCUTIL_TYPES_H

/* Screen geometry types shared by the DWC utility overlay. */

typedef struct tagCOORD {
    unsigned short x, y;
} COORD;

typedef struct tagRECT {
    unsigned short l, t, r, b;
} RECT;

typedef struct tagAREA {
    unsigned short x, y, w, h;
} AREA;

typedef struct tagAPINFO {
    unsigned char ssid[32];
    unsigned char bssid[6];
    unsigned short level;
    unsigned char wep;
    unsigned char pad;
} APINFO;

#endif
