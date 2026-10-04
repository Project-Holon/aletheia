/*
 * function: func_021E2FE8
 * address: 0x021E2FE8
 * packet: pkt_ov183_021E2FE8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../include/Obj06616.h"
#include "../include/Obj24695.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FD860(char *,u32,const struct Pair *);
extern void func_021FD15C(void *,int);
void func_021E2FE8(char *p) { int zero=0;func_021FD860(*(char * *)&((struct Obj06616 *)p)->f30,0,0);if(((struct Obj06616 *)p)->f8){func_021FD15C(((struct Obj06616 *)p)->f8,((struct Obj24695 *)(*(char * *)&((struct Obj06616 *)p)->f3C))->f8);*(int *)&((struct Obj06616 *)p)->f8=zero;} }
