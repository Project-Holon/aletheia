/*
 * function: BTLV_INPUT_DeleteStatusIcons
 * address:  0x02205D34
 * packet:   pkt_ov094_02205D34
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 */

typedef struct { void *h; } E;
typedef struct { char pad[0x210]; E a[2]; } W;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void BTLV_INPUT_DeleteStatusIcons(W *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}
