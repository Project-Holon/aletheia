/*
 * function: COMM_BTL_DEMO_MAIN_DeleteActorRow
 * address: 0x021BA014
 * packet: pkt_ov213_021BA014
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void COMM_BTL_DEMO_MAIN_DeleteActorRow(u8 *p) {int i;for(i=0;i<p[11];i++)CLACT_DeleteActor((struct Obj *)(*(u32 *)(p+12+i*4)));}
