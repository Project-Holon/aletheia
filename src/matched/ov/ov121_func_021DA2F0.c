/*
 * function: func_021DA2F0
 * address: 0x021DA2F0
 * packet: pkt_ov121_021DA2F0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj13951.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
void func_021DA2F0(u8 *p,u32 i) { u8 *d=*(u8 **)(p+16+i*4); func_02043B5C(func_02045770(((struct Obj13951 *)d)->fC),((struct Obj13951 *)d)->f16&31); func_02045334(*(void **)(*(u8 **)(p+16+i*4)+12)); }
