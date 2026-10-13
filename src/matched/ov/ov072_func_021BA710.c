/*
 * function: TOWNMAP_MapFindNearestTown
 * address:  0x021BA710
 * packet:   pkt_ov072_021BA710
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOWNMAP_CursorGetPos  0x021BA3BC  thumb  ov072
 *   TOWNMAP_TownTestNear  0x021BACB0  thumb  ov072
 */

typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    char *f8;
    u32 fc;
    int f10;
} W;

extern void TOWNMAP_CursorGetPos(char *p, int *q);
extern int TOWNMAP_TownTestNear(char *a, int *b, int *c, u32 *d);

char *TOWNMAP_MapFindNearestTown(W *p, int a)
{
    int pt[2];
    u32 i;
    u32 best;
    u32 d;
    int idx;

    TOWNMAP_CursorGetPos((char *)a, pt);
    idx = -1;
    best = -1;
    for (i = 0; i < p->fc; i++) {
        if (TOWNMAP_TownTestNear(p->f8 + i * 0x44, pt, &p->f10, &d) != 0 && best > d) {
            idx = i;
            best = d;
        }
    }
    if (idx == -1) {
        return 0;
    }
    return p->f8 + idx * 0x44;
}
