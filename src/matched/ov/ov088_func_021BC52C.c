/*
 * function: func_021BC52C
 * address: 0x021BC52C
 * packet: pkt_ov088_021BC52C
 * region: ov088
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC84C 0x021BC84C thumb ov088
 *   func_0201D83C 0x0201D83C thumb
 *   func_020450C8 0x020450C8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj02128.h"
typedef unsigned char u8;
extern void func_021BC84C(u8 *p);
extern unsigned int func_0201D83C(void *ptr);
extern void func_020450C8(void);
typedef unsigned int   u32;
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(u32 a);
int func_021BC52C(int a,int b,int c,u8 *p) { func_021BC84C(p);func_0201D83C((void *)(((struct Obj02128 *)p)->f8));func_020450C8();func_020403F4(3);func_020403F4(1);func_020403F4(5);func_0203F9B4();func_020315D4((struct S020315D4 *)a);func_020306F0(0x39);return 1; }
