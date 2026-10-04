/*
 * function: func_0220F1F4
 * address: 0x0220F1F4
 * packet: pkt_ov198_0220F1F4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220AF6C 0x0220AF6C thumb ov196
 *   func_0220AFDC 0x0220AFDC thumb ov196
 */
#include "../include/Obj00172.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0220AF6C(char *,int,int,int,int),func_0220AFDC(char *,void *);
void func_0220F1F4(u8 *p) { func_0220AF6C(*(char * *)&((struct Obj00172 *)p)->f2188,*(int *)&((struct Obj00172 *)p)->f1EB8,((struct Obj00172 *)p)->f2504,((struct Obj00172 *)p)->f251C,((struct Obj00172 *)p)->f2534);func_0220AFDC(*(char * *)&((struct Obj00172 *)p)->f2188,0); }
