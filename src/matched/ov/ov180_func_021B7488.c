/*
 * function: HALL_OF_FAME_PlayActorAnim
 * address: 0x021B7488
 * packet: pkt_ov180_021B7488
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *,u32),CLACT_SetActorAnimSeq(struct Obj *,u16),CLACT_SetActorAutoAnim(struct Obj *,u32);
void HALL_OF_FAME_PlayActorAnim(u8 *p,int n,int v) { CLACT_SetActorAnimFrame(*(struct Obj **)(p+0x9048+n*4),0); CLACT_SetActorAnimSeq(*(struct Obj **)(p+0x9048+n*4),v); CLACT_SetActorAutoAnim(*(struct Obj **)(p+0x9048+n*4),1); }
