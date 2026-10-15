/*
 * function: BEACON_VIEW_PointInTriangle
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
 *   BEACON_VIEW_Sub2D  0x021F0884  thumb  ov032
 *   BEACON_VIEW_Cross2D  0x021F086C  thumb  ov032
 */

typedef struct { int x, y; } Vec2;

extern void BEACON_VIEW_Sub2D(int *a, int *b, int *c);
extern int BEACON_VIEW_Cross2D(int *a, int *b);

int BEACON_VIEW_PointInTriangle(Vec2 *pt, Vec2 *tri)
{
    int i;
    Vec2 a;
    Vec2 b;

    for (i = 0; i < 3; i++) {
        BEACON_VIEW_Sub2D((int *)pt, (int *)(&tri[i]), (int *)(&a));
        BEACON_VIEW_Sub2D((int *)(&tri[(i + 1) % 3]), (int *)(&tri[i]), (int *)(&b));
        if (BEACON_VIEW_Cross2D((int *)(&a), (int *)(&b)) < 0)
            return 0;
    }
    return 1;
}
