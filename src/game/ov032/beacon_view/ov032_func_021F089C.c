/*
 * function: func_021F089C
 * address:  0x021F089C
 * packet:   pkt_ov032_021F089C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0884  0x021F0884  thumb  ov032
 *   func_021F086C  0x021F086C  thumb  ov032
 */

typedef struct { int x, y; } Vec2;

extern void func_021F0884(int *a, int *b, int *c);
extern int func_021F086C(int *a, int *b);

int func_021F089C(Vec2 *pt, Vec2 *tri)
{
    int i;
    Vec2 a;
    Vec2 b;

    for (i = 0; i < 3; i++) {
        func_021F0884((int *)pt, (int *)(&tri[i]), (int *)(&a));
        func_021F0884((int *)(&tri[(i + 1) % 3]), (int *)(&tri[i]), (int *)(&b));
        if (func_021F086C((int *)(&a), (int *)(&b)) < 0)
            return 0;
    }
    return 1;
}
