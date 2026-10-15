/*
 * function: GTSNEGO_MSG_DeleteActors
 * address: 0x021D6B5C
 * packet: pkt_ov120_021D6B5C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * lever: base + index*4 + 0xc4 preserves the original add order.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
void GTSNEGO_MSG_DeleteActors(u8 *p){int i;for(i=0;i<12;i++){if(*(void **)(p+i*4+0xc4)){CLACT_DeleteActor(*(void **)(p+i*4+0xc4));*(int *)(p+i*4+0xc4)=0;}}}
