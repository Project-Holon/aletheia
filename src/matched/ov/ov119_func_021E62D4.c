/*
 * function: POKETRADE_2D_DeleteOfferIconActor
 * address: 0x021E62D4
 * packet: pkt_ov119_021E62D4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 */
typedef struct {
    char pad[0x1008];
    int h[2][3];
    int w[2][3];
} Work;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
typedef unsigned int   u32;
extern void CLACT_ReleaseCharacter(u32 i);

void POKETRADE_2D_DeleteOfferIconActor(Work *p, int a, int b)
{
    if (p->h[a][b]) {
        CLACT_DeleteActor((struct Obj *)p->h[a][b]);
        p->h[a][b] = 0;
        CLACT_ReleaseCharacter(p->w[a][b]);
    }
}
