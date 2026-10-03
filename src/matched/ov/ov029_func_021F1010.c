/*
 * function: func_021F1010
 * address:  0x021F1010
 * packet:   pkt_ov029_021F1010
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1290  0x021F1290  thumb  ov029
 *   func_020409B4  0x020409B4  arm
 *   d_021F3324     0x021F3324  data  a4
 */

typedef struct { int a, b; } Pair;

extern const Pair d_021F3324;
extern void func_021F1290(void *p, int i, int j, int k);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);

void func_021F1010(void *p)
{
    Pair t = d_021F3324;
    int i, j, n;

    for (i = 0; i < 9; i++) {
        n = ((int *)&t)[i % 2];
        for (j = 0; j < n; j++)
            func_021F1290(p, i, j, 0);
    }
    func_020409B4(4);
}
