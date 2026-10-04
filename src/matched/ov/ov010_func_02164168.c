/*
 * function: func_02164168
 * address:  0x02164168
 * packet:   pkt_ov010_02164168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb
 *   func_0216DEE0  0x0216DEE0  thumb
 *   func_0216D83C  0x0216D83C  thumb
 *   func_0216D86C  0x0216D86C  thumb
 */

typedef short s16;

extern void *func_0216D67C(void *a0);
extern void *func_0216DEE0(void *a0);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);

int func_02164168(int a)
{
    int t;
    int tx;
    int ty;
    int x;
    int y;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    t = (int)func_0216DEE0(func_0216D67C((void *)a));
    if (t != 0) {
        tx = func_0216D83C((void *)t);
        ty = func_0216D86C((void *)t);
        x = func_0216D83C((void *)a);
        y = func_0216D86C((void *)a);
        x0 = x - 18;
        y0 = y - 18;
        x1 = x + 17;
        y1 = y + 17;
        if (y0 <= ty && y1 >= ty && x0 <= tx && x1 >= tx)
            return 1;
    }
    return 0;
}
