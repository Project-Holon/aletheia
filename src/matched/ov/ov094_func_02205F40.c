/*
 * function: BTLV_INPUT_DeleteTargetActors
 * address:  0x02205F40
 * packet:   pkt_ov094_02205F40
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

typedef struct { void *h; int x; } E;
typedef struct { char pad[0x180]; E a[6]; } W;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void BTLV_INPUT_DeleteTargetActors(W *p)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (p->a[i].h != 0) {
            CLACT_DeleteActor(p->a[i].h);
            p->a[i].h = 0;
        }
    }
}
