/*
 * function: POKETRADE_2D_DeleteMarkerActor
 * address: 0x021E67A8
 * packet: pkt_ov119_021E67A8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void POKETRADE_2D_DeleteMarkerActor(void *p, int i)
{
    if (*(int *)((char *)p + 0x10bc + i * 4)) {
        CLACT_DeleteActor((struct Obj *)(*(int *)((char *)p + 0x10bc + i * 4)));
        *(int *)((char *)p + 0x10bc + i * 4) = 0;
    }
}
