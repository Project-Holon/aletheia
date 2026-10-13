/*
 * function: func_021C9544
 * address: 0x021C9544
 * packet: pkt_ov128_021C9544
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C94DC 0x021C94DC thumb ov128
 *   func_021C9450 0x021C9450 thumb ov128
 *   func_020355D8 0x020355D8 arm
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb  arm9
 */
#include "../include/Obj23105.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int func_021C94DC(void *p, void *q, void *r, int *flag);
extern int func_021C9450(void *, int *, void *);
extern void func_020355D8(u8 v);
int func_021C9544(void *p,int *q,char *r) {
 int flag=0; int ret;
 if(!PRINTSYS_QUE_IsFinished(((struct Obj23105 *)r)->f34)) return 2;
 ret=func_021C94DC(p,q,r,&flag);
 if(flag) {func_020355D8(1); *q=1; return ret;}
 return func_021C9450(p,q,r);
}
