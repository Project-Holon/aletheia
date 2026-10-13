/*
 * function: func_021DE080
 * address: 0x021DE080
 * packet: pkt_ov171_021DE080
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorAnimFrame(struct Obj *,u32);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void func_0204B92C(struct Obj *,u32);
void func_021DE080(u8 *p, int i, int value)
{
    struct Obj **base=(struct Obj **)(p+0xb74);
    CLACT_SetActorAnimFrame(*(struct Obj **)((u32)base+i*4),0);
    CLACT_SetActorAnimSeq(*(struct Obj **)((u32)base+i*4),value);
    func_0204B92C(*(struct Obj **)((u32)base+i*4),1);
}
