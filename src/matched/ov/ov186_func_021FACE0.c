/*
 * function: func_021FACE0
 * address: 0x021FACE0
 * packet: pkt_ov186_021FACE0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045808 0x02045808 arm
 *   func_021FB494 0x021FB494 thumb ov186
 *   memset 0x02082BCC arm
 */
#include "../include/Obj10784.h"
struct U16Vec;
extern void func_02045808(struct U16Vec *);
extern void func_021FB494(char *p);
extern void *memset(void *,int,unsigned);
void func_021FACE0(char *p) { if(((struct Obj10784 *)p)->f0!=0){func_02045808(*(struct U16Vec * *)&((struct Obj10784 *)p)->f40);func_021FB494(((struct Obj10784 *)p)->f8);memset(p,0,0x44);} }
