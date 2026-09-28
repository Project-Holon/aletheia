/*
 * function: sub_0200A940
 * address:  0x0200A940
 * packet:   pkt_0200A940
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200A8AC   0x0200A8AC  thumb
 *   sub_0200A8D0   0x0200A8D0  thumb
 *   sub_0200AA00   0x0200AA00  thumb
 *   sub_020056EC   0x020056EC  thumb
 */

typedef unsigned int u32;

extern u32  sub_0200A8AC(void *a0);
extern int  sub_0200A8D0(void *a0, int i);
extern int  sub_0200AA00(int a, int b, void *p);
extern int  sub_020056EC(int a);

int sub_0200A940(void *a0, int a1, int a2, void *a3)
{
    u32 n = sub_0200A8AC(a0);
    int target = sub_0200AA00(a1, a2, a3);
    int best = 0;
    u32 bestd = 0xffffffffu;
    u32 i;

    for (i = 0; i < n; i++) {
        int d = sub_0200A8D0(a0, i) - target;
        if (d < 0) {
            d = -d;
        }
        if (bestd == d) {
            u32 tmp[2];
            tmp[0] = (u32)best;
            tmp[1] = (u32)i;
            best = (int)tmp[sub_020056EC(2)];
        } else if (bestd > d) {
            best = i;
            bestd = d;
        }
    }
    return best;
}
