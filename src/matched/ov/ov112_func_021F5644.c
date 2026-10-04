/*
 * function: func_021F5644
 * address: 0x021F5644
 * packet: pkt_ov112_021F5644
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F61D8 0x021F61D8 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj13832.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F61D8(char *,char *);
extern void func_020307B0(void *);
void func_021F5644(char *p) { int i; char *q; for(i=0;i<((struct Obj13832 *)p)->f0;i++) { q=(*(char ***)(p+4))[i]; if(q)func_021F61D8(p,q); } func_020307B0(((struct Obj13832 *)p)->f4); func_020307B0(p); }
