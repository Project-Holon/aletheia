/*
 * function: func_0219E9A8
 * address:  0x0219E9A8
 * packet:   pkt_ov021_0219E9A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D660  0x0216D660  thumb  ov010
 *   func_0216D66C  0x0216D66C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u32 pad0;
    s16 lx;
    u16 ly;
} L;

extern int func_0216D660(void *p);
extern int func_0216D66C(void *p);

int func_0219E9A8(u32 o, int a, int b, L *l)
{
    int x;
    int y;
    int lo;
    int hi;

    x = func_0216D660((void *)o);
    y = func_0216D66C((void *)o);
    if (x != -1) {
        lo = b - x;
        hi = b + x;
        if (lo > l->lx || hi < l->lx) {
            return 1;
        }
    }
    if (y != -1) {
        hi = a + y;
        lo = a - y;
        if (lo > l->ly || hi < l->ly) {
            return 1;
        }
    }
    return 0;
}
