/*
 * function: func_0216D2AC
 * address:  0x0216D2AC
 * packet:   pkt_ov010_0216D2AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D948  0x0216D948  thumb  ov010
 *   func_0216DFAC  0x0216DFAC  thumb  ov010
 *   func_0216D780  0x0216D780  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DD1C(u32 x, u8 **o, int *n);
extern int func_0216D948(u32 x);
extern void func_0216DFAC(u8 *o);
extern void func_0216D780(u8 *o);
extern void func_0216D568(u8 *o, u32 v);

void func_0216D2AC(u32 x)
{
    int n;
    u8 *o;
    u32 k = 5;

    n = 0;
    if (func_0216D948(x)) {
        while (func_0216DD1C(x, &o, &n) == 1) {
            func_0216DFAC(o);
            func_0216D780(o);
            func_0216D568(o, k);
        }
    }
}
