/*
 * function: func_021D6B84
 * address: 0x021D6B84
 * packet: pkt_ov120_021D6B84
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding follows.
 * lever: compute the callee result before initializing mode; the original
 * signed BLT at 0x021D6B96 requires a signed full-word result declaration.
 * symbols:
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void func_021D6B84(u8 *p,u32 n){int got;int mode;got=CLACT_GetActorAnimSeq(*(void **)(p+0xc4+n*4));mode=1;if(got>=2)mode=3;CLACT_SetActorAnimSeq(*(void **)(p+0xc4+n*4),mode);CLACT_SetActorAutoAnim(*(void **)(p+0xc4+n*4),1);}
