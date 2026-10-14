/*
 * function: ZUKAN_LIST_GetActorVisible
 * address: 0x021BD8F4
 * packet: pkt_ov209_021BD8F4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj; extern u32 CLACT_GetActorDrawEnable(struct Obj *);
u32 ZUKAN_LIST_GetActorVisible(char *p,u32 idx) {return CLACT_GetActorDrawEnable(*(struct Obj **)(p+idx*4+0xa74));}
