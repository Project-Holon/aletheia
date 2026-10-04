/*
 * function: func_0219A3D8
 * address:  0x0219A3D8
 * packet:   pkt_ov021_0219A3D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D7E8  0x0216D7E8  thumb  ov010
 *   func_0216D7F8  0x0216D7F8  thumb  ov010
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 * Addresses are Black-image addresses.
 * Store order in each arm is left, right, top, bottom (x pair, then y pair);
 * the field order left, top, right, bottom puts stores to +0/+8 first.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { int left, top, right, bottom; } Rect;
extern int func_0216D7E8(void *p);
extern int func_0216D7F8(void *p);
extern int func_0216D660(void *p);
extern int func_0216D66C(void *p);
extern u16 func_0216D5A0(void *p);

void func_0219A3D8(u32 a, Rect *r)
{
    int x;
    int y;
    int w;
    int h;

    x = func_0216D7E8((void *)a);
    y = func_0216D7F8((void *)a);
    w = func_0216D660((void *)a);
    h = func_0216D66C((void *)a);
    switch (func_0216D5A0((void *)a)) {
    case 6:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y;
        break;
    case 7:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 8:
        r->left = x - w;
        r->right = x;
        r->top = y;
        r->bottom = y + h;
        break;
    case 9:
        r->left = x;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    case 10:
        r->left = x - w;
        r->right = x;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 11:
        r->left = x;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y + h;
        break;
    case 12:
        r->left = x - w;
        r->right = x + w;
        r->top = y - h;
        r->bottom = y;
        break;
    case 13:
        r->left = x - w;
        r->right = x + w;
        r->top = y;
        r->bottom = y + h;
        break;
    }
}
