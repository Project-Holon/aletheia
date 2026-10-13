/*
 * function: func_021DDFA0
 * address: 0x021DDFA0
 * packet: pkt_ov183_021DDFA0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E3440 0x021E3440 data a4
 *   func_021FD860 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00731.h"
typedef unsigned int u32;
typedef struct Rect { u32 x0, y0, x1, y1; } Rect;
extern const Rect d_021E3440[];
extern void func_021FD860(int, int, int *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021DDFA0(char *p, int x, int y)
{
    int skip = ((struct Obj00731 *)p)->f78;
    int i;
    for (i = 0; i < 5; i++) {
        if (i != skip && (u32)(x - d_021E3440[i].x0) <= d_021E3440[i].x1 - d_021E3440[i].x0 &&
            (u32)(y - d_021E3440[i].y0) <= d_021E3440[i].y1 - d_021E3440[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            func_021FD860(*(int *)&((struct Obj00731 *)p)->f74, 1, args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return i;
        }
    }
    return 0;
}
