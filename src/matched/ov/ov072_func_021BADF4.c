/*
 * function: TOWNMAP_TownHighlight
 * address:  0x021BADF4
 * packet:   pkt_ov072_021BADF4
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOWNMAP_TownGetField  0x021BA774  thumb  ov072
 *   TOWNMAP_TownSetShown  0x021BAA30  thumb  ov072
 *   TOWNMAP_TownSetFrame  0x021BADBC  thumb  ov072
 */

typedef unsigned char u8;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern int TOWNMAP_TownGetField(char *p, int i);
extern void TOWNMAP_TownSetShown(W *p, int a);
extern void TOWNMAP_TownSetFrame(char *p, int v);

void TOWNMAP_TownHighlight(W *p)
{
    int r;

    r = 0;
    if (TOWNMAP_TownGetField((char *)p, 11) == 4 || TOWNMAP_TownGetField((char *)p, 11) == 5) {
        r = 1;
        if (p->f40 != 0) {
            r = 0;
        }
    }
    if (p->f38 != 0 || r != 0) {
        TOWNMAP_TownSetShown(p, 1);
        TOWNMAP_TownSetFrame((char *)p, p->f31);
    } else {
        TOWNMAP_TownSetShown(p, 0);
    }
}
