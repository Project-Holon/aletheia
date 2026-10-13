/*
 * function: UNION_SUBDISP_DeleteActors
 * address: 0x021F056C
 * packet: pkt_ov031_021F056C
 * region: ov031
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
void UNION_SUBDISP_DeleteActors(char *p) { int i; for (i=0;i<6;i++) CLACT_DeleteActor((struct Obj *)(*(unsigned *)(p+i*4+0x18))); }
