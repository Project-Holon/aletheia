/*
 * function: func_021CA3A0
 * address: 0x021CA3A0
 * packet: pkt_ov128_021CA3A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj03813.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct Obj;
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021CA3A0(char *p) {func_0204B8C4(((struct Obj03813 *)p)->f164,0);func_0204B878(((struct Obj03813 *)p)->f164,9);func_0204B92C(((struct Obj03813 *)p)->f164,1);}
