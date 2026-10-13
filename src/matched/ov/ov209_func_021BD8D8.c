/*
 * function: func_021BD8D8
 * address: 0x021BD8D8
 * packet: pkt_ov209_021BD8D8
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj; extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
void func_021BD8D8(char *p,u32 idx,u32 value) {struct Obj *o;o=*(struct Obj **)(p+idx*4+0xa74);if(o) CLACT_SetActorDrawEnable(o,value);}
