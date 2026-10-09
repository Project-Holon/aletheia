/*
 * file:     unit_021EFA94.c
 * function: func_021EFA94
 * address:  0x021EFA94
 * packet:   pkt_ov093_021EFA94
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 *
 * symbols:
 *   func_021EFCE4  0x021EFCE4  thumb  ov093
 *   func_021EFAC8  0x021EFAC8  thumb  ov093
 *   func_021EF83C  0x021EF83C  thumb  ov093
 */

typedef unsigned int u32;

extern void *func_021EFCE4(char *a, int b);
extern void func_021EFAC8(u32 h);
extern void func_021EF83C(char *a, u32 b);

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
} S;

int func_021EFA94(S *a, u32 b)
{
    if (func_021EFCE4((char *)a, b) != 0) {
        if (a->t[b] != 0) {
            func_021EFAC8(a->t[b]);
            a->t[b] = 0;
        }
        func_021EF83C((char *)a, b);
        return 1;
    }
    return 0;
}
