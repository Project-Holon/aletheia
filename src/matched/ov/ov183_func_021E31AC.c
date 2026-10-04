/*
 * function: func_021E31AC
 * address: 0x021E31AC
 * packet: pkt_ov183_021E31AC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 */
#include "../include/Obj10763.h"
#include "../include/Obj10764.h"
#include "../include/Obj14446.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FD15C(void *,int);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *,unsigned);
void func_021E31AC(char *p,char *q) { int i;char *s;if(((struct Obj10763 *)p)->f8){func_021FD15C(((struct Obj10763 *)p)->f8,*(int *)&((struct Obj14446 *)q)->f8);*(int *)&((struct Obj10763 *)p)->f8=0;}for(i=0;i<4;i++){s=p+i*4;if(((struct Obj10764 *)s)->f14){func_021FB494(((struct Obj10764 *)s)->f14);((struct Obj10764 *)s)->f14=0;}}func_021FC0C8(*(char * *)&((struct Obj14446 *)q)->f8,1); }
