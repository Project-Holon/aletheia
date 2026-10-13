/*
 * function: func_021C6E18
 * address: 0x021C6E18
 * packet: pkt_ov128_021C6E18
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
void func_021C6E18(u8 *p,int i,u16 a) {CLACT_SetActorAutoAnim(*(void **)((u32)p+0x15c+i*4),1);CLACT_SetActorAnimSeq(*(void **)((u32)p+0x15c+i*4),a);CLACT_RestartActorAnim(*(void **)((u32)p+0x15c+i*4));}
