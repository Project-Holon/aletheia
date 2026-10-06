/*
 * function: func_0219C314
 * address:  0x0219C314
 * packet:   pkt_ov021_0219C314
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219C2E0  0x0219C2E0  thumb  ov021
 *   func_021639C0  0x021639C0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_0219C2E0(u32 a, int b, int c);
extern int func_021639C0(u32 a, u16 v);

int func_0219C314(int a, int *s, u32 c)
{
    int v = func_0219C2E0(a, *s, c);
    *s = v;
    if (v != 9) {
        return func_021639C0(a, v);
    }
    return 0;
}
