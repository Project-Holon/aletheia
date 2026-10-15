/*
 * function: func_0220EA30
 * address: 0x0220EA30
 * packet: pkt_ov198_0220EA30
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0220E7CC 0x0220E7CC thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,u32);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern u32 FILE_UTIL_Check136C(u32);
extern void func_0220E7CC(u8 *,u32);
void func_0220EA30(u32 mode,u8 *p,const struct Vec2 *q) { if(mode==0)CLACT_AddActorSurfacePos((struct Obj *)p,q,1);else {if(FILE_UTIL_Check136C(mode)==1)CLACT_SetActorAnimSeq((struct Obj *)p,1);else CLACT_SetActorAnimSeq((struct Obj *)p,0);func_0220E7CC(p,(u32)q);} }
