/*
 * function: func_021BA4D4
 * address: 0x021BA4D4
 * packet: pkt_ov218_021BA4D4
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: original reads r0 at 021BA4F0 after 0204B294; extern retains that live return despite legacy void declaration.
 * symbols:
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../include/Obj08448.h"
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Obj;extern u32 func_0204B294(u32,u32,u32,u32,u32,u16,u16);extern void func_0204B92C(struct Obj *,u32);
struct Obj *func_021BA4D4(u32 owner,char *p){struct Obj *r;r=(struct Obj *)func_0204B294(owner,((struct Obj08448 *)p)->f8,((struct Obj08448 *)p)->fC,((struct Obj08448 *)p)->f10,(u32)p,((struct Obj08448 *)p)->f16,122);func_0204B92C(r,1);return r;}
