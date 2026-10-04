/*
 * function: func_021C571C
 * address: 0x021C571C
 * packet: pkt_ov127_021C571C
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C58B8 0x021C58B8 thumb ov127
 *   func_021C574C 0x021C574C thumb ov127
 */
#include "../include/Obj10477.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C58B8(char *);
extern void func_021C574C(u8 *);
void func_021C571C(u8 *p) { int i,offset; for(i=0;i<((struct Obj10477 *)p)->f8;i++) { offset=i*20; if(func_021C58B8(*(char * *)&((struct Obj10477 *)p)->f4+offset)==0) func_021C574C(*(u8 * *)&((struct Obj10477 *)p)->f4+offset); } }
