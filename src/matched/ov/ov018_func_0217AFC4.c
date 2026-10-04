/*
 * function: func_0217AFC4
 * address:  0x0217AFC4
 * packet:   pkt_ov018_0217AFC4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 */

typedef short s16;

extern int func_021A3098(int);
typedef unsigned int   u32;
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern int func_021679A4(int, int, int, int, int *, int *);

int func_0217AFC4(int *a, int b, int *out)
{
    int r;
    int idx;
    int hit;
    int ret;
    s16 v[3];

    ret = 0;
    hit = ret;
    if (a == 0 || a[2] == 0)
        return 0;
    r = func_021A3098(b);
    if (r != 0 && r != 1)
        return ret;
    func_021A3460(b, (u32)(v + 2), (u32)(v + 1), (u32)v);
    for (;;) {
        r = func_021679A4(a[2], v[2], v[1], v[0], &idx, &hit);
        if (r != 1)
            break;
        if (*(int *)((char *)a + idx * 28 + 0x8c) == 0) {
            *out = idx;
            return 1;
        }
    }
    return 0;
}
