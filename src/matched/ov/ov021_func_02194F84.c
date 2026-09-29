/*
 * function: func_02194F84
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
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045730  0x02045730  arm
 *   func_02040804  0x02040804  arm
 *   func_02194F5C  0x02194F5C  thumb  ov021
 *   func_0206E0C4  0x0206E0C4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02045758(u32 w);
extern int func_02045760(u32 w);
extern int func_02045748(u32 w);
extern int func_02045750(u32 w);
extern u32 func_02045730(u32 w);
extern int func_02040804(u32 a);
extern void func_02194F5C(int x, int w, int side, u16 *a, u16 *b);
extern void func_0206E0C4(int x, int y, void *c, int z);

int func_02194F84(u8 *e, int b, int c, void *d, void *f)
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

    x = (func_02045758(*(u32 *)(e + 0xC)) - 1) << 3;
    y = (func_02045760(*(u32 *)(e + 0xC)) - 1) << 3;
    w = (func_02045748(*(u32 *)(e + 0xC)) + 2) << 3;
    h = (func_02045750(*(u32 *)(e + 0xC)) + 2) << 3;
    y += func_02040804(func_02045730(*(u32 *)(e + 0xC)));
    switch (*(u32 *)(e + 4)) {
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
        if (*(int *)(e + 0x58) == 0) {
            if (b < 0x80) {
                side = 0;
                r = 7;
            } else {
                side = 1;
                r = 8;
            }
        } else if (*(int *)(e + 0x58) == 7) {
            side = 0;
            r = 7;
        } else {
            side = 1;
            r = 8;
        }
        func_02194F5C(x, w, side, &v[1], &v[0]);
        break;
    case 2:
        yb = ya =y + 4;
        if (*(int *)(e + 0x58) == 0) {
            if (b < 0x80) {
                side = 0;
                r = 5;
            } else {
                side = 1;
                r = 6;
            }
        } else if (*(int *)(e + 0x58) == 5) {
            side = 0;
            r = 5;
        } else {
            side = 1;
            r = 6;
        }
        func_02194F5C(x, w, side, &v[1], &v[0]);
        break;
    }
    func_0206E0C4(v[1], ya, d, 0);
    func_0206E0C4(v[0], yb, f, 0);
    return r;
}
