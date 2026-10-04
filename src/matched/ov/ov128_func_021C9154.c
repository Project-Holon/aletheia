/*
 * function: func_021C9154
 * address: 0x021C9154
 * packet: pkt_ov128_021C9154
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj10489.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021CA444(char *);
extern void func_021CA458(char *p, void *q);
extern void func_020452E8(void *),func_020307B0(void *);
void func_021C9154(char *p,int unused,char *q) { func_021CA444(q);func_021CA458(q,q+12);func_020452E8(((struct Obj10489 *)p)->f0);func_020452E8(((struct Obj10489 *)p)->f8);func_020307B0(((struct Obj10489 *)p)->f10);}
