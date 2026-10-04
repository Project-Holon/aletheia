/*
 * function: func_021C57F4
 * address: 0x021C57F4
 * packet: pkt_ov127_021C57F4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C58F8 0x021C58F8 thumb ov127
 *   func_021C5944 0x021C5944 thumb ov127
 *   func_021C574C 0x021C574C thumb ov127
 */
#include "../include/Obj00328.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C58F8(char *,int);
extern void func_021C5944(u8 *,int,int);
extern void func_021C574C(u8 *);
void func_021C57F4(u8 *p) { func_021C5944(p,func_021C58F8(*(char * *)&((struct Obj00328 *)p)->f4,((struct Obj00328 *)p)->f8),((struct Obj00328 *)p)->fA); func_021C574C(p); }
