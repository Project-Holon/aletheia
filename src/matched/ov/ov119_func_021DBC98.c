/*
 * function: func_021DBC98
 * address: 0x021DBC98
 * packet: pkt_ov119_021DBC98
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD3D4 0x021DD3D4 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBC3C 0x021DBC3C thumb ov119
 */
#include "../include/Obj08057.h"
typedef unsigned short u16;extern int func_021D8AA8(void *);extern int func_021DD3D4(void *,int,int,int);extern void *func_020399A8(void);extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);extern void func_021D8E84(void *,int);extern void func_021DBC3C(void);
void func_021DBC98(char *p) {int same=0;if(((struct Obj08057 *)p)->fF88==((struct Obj08057 *)p)->f630)same=1;if(func_021D8AA8(p)) {int n=func_021DD3D4(p,0,((struct Obj08057 *)p)->fF84,((struct Obj08057 *)p)->fF88);if(n!=-1) {if(func_0203D3A8(func_020399A8(),n+0xc13,1,&same)) {func_021D8E84(p,(int)func_021DBC3C);return;}} else {func_021D8E84(p,(int)func_021DBC3C);return;}} else {if(func_0203D3A8(func_020399A8(),0xc16,1,&same))func_021D8E84(p,(int)func_021DBC3C);}}
