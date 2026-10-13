/*
 * function: func_021DB394
 * address: 0x021DB394
 * packet: pkt_ov183_021DB394
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 */
#include "../include/Obj06595.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct PrintSys;
extern void func_021FD71C(u8 *p);
extern void func_021FD854(char *);
extern int func_021FD72C(int *);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
int func_021DB394(int a,int b,int c,char *p) { func_021FD71C((u8 *)(*(int *)&((struct Obj06595 *)p)->f0)); PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj06595 *)p)->fC); func_021FD854(*(char * *)&((struct Obj06595 *)p)->f14); func_021FD854(*(char * *)&((struct Obj06595 *)p)->f18); if(func_021FD72C(*(int * *)&((struct Obj06595 *)p)->f0)) return 1; return 0; }
