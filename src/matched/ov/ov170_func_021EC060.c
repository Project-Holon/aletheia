/*
 * function: BOX2_SEQ_SetActorObjMode
 * address: 0x021EC060
 * packet: pkt_ov170_021EC060
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorObjMode 0x0204B688 arm
 */
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
void BOX2_SEQ_SetActorObjMode(char *p,unsigned i,int b){if(b==1)CLACT_SetActorObjMode(*(void **)((unsigned)p+i*4+0x9e74),1);else CLACT_SetActorObjMode(*(void **)((unsigned)p+i*4+0x9e74),0);}
