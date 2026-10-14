/*
 * function: POKETRADE_2D_SetMarkerActorVisible
 * address: 0x021E6790
 * packet: pkt_ov119_021E6790
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void POKETRADE_2D_SetMarkerActorVisible(void *p, int i, int a)
{
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)((char *)p + i * 4 + 0x10bc), a);
}
