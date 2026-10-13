/*
 * function: func_021BA624
 * address: 0x021BA624
 * packet: pkt_ov213_021BA624
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void func_021BA624(char *p){int i;for(i=0;i<3;i++)CLACT_DeleteActor(*(void **)((unsigned)p+i*4+24));for(i=0;i<2;i++)CLACT_DeleteActor(*(void **)((unsigned)p+i*4+16));}
