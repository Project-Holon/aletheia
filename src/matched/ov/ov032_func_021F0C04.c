/*
 * function: BEACON_VIEW_CreateTaskMenuButtons
 * address:  0x021F0C04
 * packet:   pkt_ov032_021F0C04
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_CreateTaskMenuButtons  0x021F0C04  thumb
 *   APP_TASKMENU_WIN_CreateEx  0x0202800C  thumb
 */
#include "../include/Obj13061.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 *APP_TASKMENU_WIN_CreateEx(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7,
                          u16 a8);

void BEACON_VIEW_CreateTaskMenuButtons(char *p, int flag)
{
    int i;
    int n;
    int base;
    char *q;

    if (flag == 0) {
        q = p + 0xc0;
        n = 3;
        base = 8;
    } else {
        q = p + 0xf0;
        n = 2;
        base = 0x10;
    }
    for (i = 0; i < n; i++) {
        *(u32 *)(q + i * 16) = (u32)APP_TASKMENU_WIN_CreateEx(((struct Obj13061 *)p)->fB8, (u32)(q + i * 16 + 4),
                                      (u8)(base + i * 8), 0x15, 8, 3, 1, 0,
                                      ((struct Obj13061 *)p)->f98);
    }
}
