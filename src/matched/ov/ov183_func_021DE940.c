/*
 * function: BR_CODEIN_ResultHitButton
 * address: 0x021DE940
 * packet: pkt_ov183_021DE940
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E3534 0x021E3534 data a4
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00785.h"
typedef unsigned int u32;
typedef struct Rect { u32 x0, y0, x1, y1; } Rect;
extern const Rect d_021E3534[];
extern void BR_UTIL_StartEffect(int, int, int *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int BR_CODEIN_ResultHitButton(char *p, int x, int y)
{
    int skip = ((struct Obj00785 *)p)->f68;
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            BR_UTIL_StartEffect(*(int *)&((struct Obj00785 *)p)->f64, 1, args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return i;
        }
    }
    return 0;
}
