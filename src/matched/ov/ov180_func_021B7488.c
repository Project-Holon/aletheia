/*
 * function: func_021B7488
 * address: 0x021B7488
 * packet: pkt_ov180_021B7488
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B8C4(struct Obj *,u32),func_0204B878(struct Obj *,u16),func_0204B92C(struct Obj *,u32);
void func_021B7488(u8 *p,int n,int v) { func_0204B8C4(*(struct Obj **)(p+0x9048+n*4),0); func_0204B878(*(struct Obj **)(p+0x9048+n*4),v); func_0204B92C(*(struct Obj **)(p+0x9048+n*4),1); }
