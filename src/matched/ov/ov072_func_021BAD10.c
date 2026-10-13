/*
 * function: TOWNMAP_TownSetScale
 * address:  0x021BAD10
 * packet:   pkt_ov072_021BAD10
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TOWNMAP_GRH_GetTownInfoValue  0x021BBB3C  thumb  ov072
 *   CLACT_SetActorScale  0x0204B5AC  arm
 */

typedef unsigned short u16;

typedef struct {
    int obj;
    char *f4;
    int f8;
    int v[8];
    int f2c;
    int f30;
    int f34;
} W;

extern u16 TOWNMAP_GRH_GetTownInfoValue(char *p, int a, int b);
struct Obj;
struct Pair;
extern void CLACT_SetActorScale(struct Obj *dst, struct Pair *src);

void TOWNMAP_TownSetScale(W *p, int s, int *r)
{
    int i;
    int base;
    int d;
    int t[2];

    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            base = r[0];
        } else {
            base = r[1];
        }
        d = TOWNMAP_GRH_GetTownInfoValue(p->f4, (u16)p->f8, i + 2) - base;
        d = d * s >> 12;
        p->v[i] = d + base;
    }
    p->f2c = s * TOWNMAP_GRH_GetTownInfoValue(p->f4, (u16)p->f8, 10) >> 12;
    p->f34 = s;
    if (p->obj != 0) {
        t[0] = s;
        t[1] = s;
        CLACT_SetActorScale((struct Obj *)p->obj, (struct Pair *)t);
    }
}
