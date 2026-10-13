/*
 * function: INTRUDE_SUBDISP_ClactActorDelete
 * address: 0x0217DA90
 * packet: pkt_ov018_0217DA90
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void INTRUDE_SUBDISP_ClactActorDelete(void **p)
{
    int i;
    for (i = 0; i < 21; i++) CLACT_DeleteActor(p[23 + i]);
}
