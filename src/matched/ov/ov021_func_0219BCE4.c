/*
 * function: func_0219BCE4
 * address:  0x0219BCE4
 * packet:   pkt_ov021_0219BCE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 */

typedef unsigned int u32;

extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216DA5C(void *a0);
extern u32 func_0216D57C(void *p, u32 v);

int func_0219BCE4(u32 a, u32 b)
{
    u32 c = *(u32 *)(b + 8);
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 p = func_0216D804((void *)c);
    u32 q = func_0216D81C((void *)c);
    if (x != p || y != q) {
        if (func_0216DA5C((void *)c) == 1 || func_0216D57C((void *)c, 0x1808) == 0) {
            return 1;
        }
    }
    return 0;
}
