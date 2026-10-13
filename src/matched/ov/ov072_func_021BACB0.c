/*
 * function: TOWNMAP_TownTestNear
 * address:  0x021BACB0
 * packet:   pkt_ov072_021BACB0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 */

typedef unsigned int u32;

typedef struct {
    int f[13];
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern int TOWNMAP_TownGetField(char *p, int i);

int TOWNMAP_TownTestNear(W *p, int *c, int *o, u32 *out)
{
    int x;
    int y;
    int dx;
    int dy;
    int a;
    int lim;

    x = o[0] + TOWNMAP_TownGetField((char *)p, 4);
    y = o[1] + TOWNMAP_TownGetField((char *)p, 5);
    dx = x - c[0];
    dx = dx * dx;
    dy = y - c[1];
    dy = dy * dy;
    if (p->f40 != 0) {
        return 0;
    }
    a = p->f34;
    if (a < 0) {
        a = -a;
    }
    lim = (a * 0x90) >> 12;
    if ((u32)(dx + dy) < lim) {
        if (out != 0) {
            *out = dx + dy;
        }
        return 1;
    }
    return 0;
}
