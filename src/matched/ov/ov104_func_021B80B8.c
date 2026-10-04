/*
 * function: func_021B80B8
 * address: 0x021B80B8
 * packet: pkt_ov104_021B80B8
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj10245.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
void func_021B80B8(u8 *p) { func_02043B5C(func_02045770(((struct Obj10245 *)p)->f0),((struct Obj10245 *)p)->f10); func_02045334(((struct Obj10245 *)p)->f0); }
