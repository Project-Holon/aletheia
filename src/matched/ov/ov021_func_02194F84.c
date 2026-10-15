/*
 * function: TALKMSGWIN_CalcTail
 * address:  0x02194F84
 * packet:   pkt_ov021_02194F84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetPosX  0x02045758  arm
 *   BMP_WIN_GetPosY  0x02045760  arm
 *   BMP_WIN_GetDispWidth  0x02045748  arm
 *   BMP_WIN_GetDispHeight  0x02045750  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02040804  0x02040804  arm
 *   TALKMSGWIN_GetTailBaseX  0x02194F5C  thumb  ov021
 *   NNS_G3dScrPosToWorldLine  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01494.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern u8 BMP_WIN_GetPosX(struct Descriptor *p);
extern u8 BMP_WIN_GetPosY(struct Descriptor *p);
extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 func_02040804(u32 layer);
extern void TALKMSGWIN_GetTailBaseX(int x, int w, int side, u16 *a, u16 *b);
extern void NNS_G3dScrPosToWorldLine(int x, int y, void *c, int z);

int TALKMSGWIN_CalcTail(u8 *e, int b, int c, void *d, void *f)
{
    int x;
    int y;
    int w;
    int h;
    int m;
    int r;
    int side;
    u16 t;
    u16 ya;
    u16 yb;
    u16 v[2];

    x = (BMP_WIN_GetPosX((struct Descriptor *)(((struct Obj01494 *)e)->fC)) - 1) << 3;
    y = (BMP_WIN_GetPosY((struct Descriptor *)(((struct Obj01494 *)e)->fC)) - 1) << 3;
    w = (BMP_WIN_GetDispWidth((struct Descriptor *)(((struct Obj01494 *)e)->fC)) + 2) << 3;
    h = (BMP_WIN_GetDispHeight((struct Descriptor *)(((struct Obj01494 *)e)->fC)) + 2) << 3;
    y += func_02040804(BMP_WIN_GetBgLayer((struct Descriptor *)(((struct Obj01494 *)e)->fC)));
    switch (((struct Obj01494 *)e)->f4) {
    case 0:
    default:
        if (w >= 16 && h >= 16) {
            m = 16;
        } else {
            m = h;
        }
        if (c < y) {
            yb = ya =y + 3;
            v[1] = x + w / 2 - m / 2;
            v[0] = m / 2 + (x + w / 2);
            r = 1;
        } else if (c > y + h) {
            yb = ya =y + h - 3;
            v[1] = x + w / 2 - m / 2;
            v[0] = m / 2 + (x + w / 2);
            r = 2;
        } else {
            ya = y + h / 2 - m / 2;
            yb = m / 2 + (y + h / 2);
            if (b < x) {
                t = x + 1;
                v[1] = t;
                v[0] = t;
                r = 3;
            } else if (b > x + w) {
                t = x + w - 1;
                v[1] = t;
                v[0] = t;
                r = 4;
            } else {
                t = x + w / 2;
                v[1] = t;
                v[0] = t;
                r = 0;
            }
        }
        break;
    case 1:
        yb = ya =y + h - 4;
        if (((struct Obj01494 *)e)->f58 == 0) {
            if (b < 0x80) {
                side = 0;
                r = 7;
            } else {
                side = 1;
                r = 8;
            }
        } else if (((struct Obj01494 *)e)->f58 == 7) {
            side = 0;
            r = 7;
        } else {
            side = 1;
            r = 8;
        }
        TALKMSGWIN_GetTailBaseX(x, w, side, &v[1], &v[0]);
        break;
    case 2:
        yb = ya =y + 4;
        if (((struct Obj01494 *)e)->f58 == 0) {
            if (b < 0x80) {
                side = 0;
                r = 5;
            } else {
                side = 1;
                r = 6;
            }
        } else if (((struct Obj01494 *)e)->f58 == 5) {
            side = 0;
            r = 5;
        } else {
            side = 1;
            r = 6;
        }
        TALKMSGWIN_GetTailBaseX(x, w, side, &v[1], &v[0]);
        break;
    }
    NNS_G3dScrPosToWorldLine(v[1], ya, d, 0);
    NNS_G3dScrPosToWorldLine(v[0], yb, f, 0);
    return r;
}
