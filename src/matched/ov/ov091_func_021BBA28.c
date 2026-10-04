/*
 * function: func_021BBA28
 * address: 0x021BBA28
 * packet: pkt_ov091_021BBA28
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03681.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021BBA28(int a,int b) {unsigned int q; func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj03681 *)b)->f4)),15); q=((struct Obj03681 *)b)->f4; func_02045334((struct Descriptor *)q);func_02045374((struct Cfg *)q);func_02041B6C(func_02045730((struct Descriptor *)q));}
