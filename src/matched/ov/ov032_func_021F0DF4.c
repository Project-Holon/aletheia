/*
 * function: func_021F0DF4
 * address: 0x021F0DF4
 * packet: pkt_ov032_021F0DF4
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 */
typedef unsigned short u16;
struct Actor;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
void func_021F0DF4(void *p, unsigned short v) { CLACT_SetActorAnimSeq(p,v); CLACT_RestartActorAnim(p); }
