/*
 * function: func_0219BA6C
 * address:  0x0219BA6C
 * packet:   pkt_ov021_0219BA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0219BA2C  0x0219BA2C  thumb  ov021
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_0219BA2C(int a);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_02197E7C(int a, int b);
extern void func_0216D438(int a0, int a1);

int func_0219BA6C(int a)
{
    int o;
    int x;
    int y;
    int tx;
    int ty;
    int k;

    o = (int)func_0216DEE0(func_0216D67C((void *)a));
    x = func_0216D83C((void *)a);
    y = func_0216D86C((void *)a);
    tx = func_0216D804((void *)o);
    ty = func_0216D81C((void *)o);
    if (x != tx || y != ty) {
        k = func_0219BA2C(a);
        func_0216D438(a, (u16)((u32)func_02197E7C((u16)((int)func_021642B4(x, y, tx, ty)), (u16)k)));
        return 1;
    }
    return 0;
}
