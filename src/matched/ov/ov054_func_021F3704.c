/*
 * function: func_021F3704
 * address: 0x021F3704
 * packet: pkt_ov054_021F3704
 * region: ov054
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021897BC 0x021897BC thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_0202B914 0x0202B914 thumb
 *   func_021F38B0 0x021F38B0 thumb ov054
 *   func_021C4DA8 0x021C4DA8 thumb ov021
 */
#include "../include/Obj20572.h"

extern int *func_021897BC(char *,int);
extern void func_021897A0(unsigned char *,int);
typedef unsigned int   u32;
struct Obj;
extern void func_0202B914(struct Obj *o, u32 v);
extern void func_021F38B0(char *,int);
extern int func_021C4DA8(void *a);
void func_021F3704(char *a) { int i=0; char *p=(char *)func_021897BC(a,0); func_0202B914((struct Obj *)(((struct Obj20572 *)p)->f4),0); func_021F38B0(p,(int)a); for(;i<2;i++) func_021C4DA8((void *)(*(void **)(p+8+4*i))); func_021897A0((unsigned char *)a,0); }
