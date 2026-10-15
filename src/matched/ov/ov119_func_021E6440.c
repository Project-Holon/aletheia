/*
 * function: POKETRADE_2D_UpdateOfferIconHighlight
 * address: 0x021E6440
 * packet: pkt_ov119_021E6440
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   gOfferIconPosB 0x021E7DA0 data a4
 */
typedef struct { short x,y; } Pt;
extern const int gOfferIconPosB[6][2];
typedef unsigned int   u32;
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void POKETRADE_2D_UpdateOfferIconHighlight(int p, int a, int b) {
    int i,j;
    Pt pos;
    for (i=0;i<2;i++) {
        for (j=0;j<3;j++) {
            if (*(int *)(p+i*12+j*4+0x1008)) {
                pos.x=gOfferIconPosB[i*3+j][0]; pos.y=gOfferIconPosB[i*3+j][1];
                if (i==a && j==b) pos.y-=4;
                CLACT_AddActorSurfacePos((struct Obj *)(*(int *)(p+i*12+j*4+0x1008)),(const struct Vec2 *)(&pos),1);
            }
        }
    }
}
