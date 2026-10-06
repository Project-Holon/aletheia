/*
 * function: func_021D8270
 * address:  0x021D8270
 * packet:   pkt_ov093_021D8270
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT* (extent runs past compiled, trailing padding)
 * symbols:
 *   func_021B902C  0x021B902C  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 n; u8 v[4]; } List4;
extern int func_021B902C(int a, int b);
int func_021D8270(List4 *l, u8 y, u32 k)
{
    int miss = 0;
    int hit = 0;
    u32 i;
    for (i = 0; i < l->n; i++) {
        if (func_021B902C(l->v[i], y))
            hit = 1;
        else
            miss = 1;
    }
    if (hit && miss) {
        if (k <= 1)
            return 3;
        return 2;
    }
    return hit ? 3 : 4;
}
