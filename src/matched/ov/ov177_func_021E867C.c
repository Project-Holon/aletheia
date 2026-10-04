/*
 * function: func_021E867C
 * address: 0x021E867C
 * packet: pkt_ov177_021E867C
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020286C4 0x020286C4 thumb
 *   func_02028484 0x02028484 thumb
 *   func_020310C4 0x020310C4 arm
 */
#include "../include/Obj00842.h"
typedef unsigned int   u32;
struct Ctx;
struct Descriptor;
struct PrintSys;
struct Tcbl;
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern int func_02028484(void *,void *);
extern void func_020310C4(struct Tcbl *p);
void func_021E867C(char *p)
{
 void *q;
 func_0201C4E4(((struct Obj00842 *)p)->f28);
 switch(((struct Obj00842 *)p)->f2C) {
 case 2:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && func_0201C6C4(q,(void *)((unsigned)func_02045770(((struct Obj00842 *)p)->f20)))==0) {
 func_02045334(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 break;
 case 0:
 q=((struct Obj00842 *)p)->f28;
 if(((struct Obj00842 *)p)->f24!=0 && func_0201C6C4(q,(void *)((unsigned)func_02045770(((struct Obj00842 *)p)->f20)))==0) {
 func_02045334(((struct Obj00842 *)p)->f20);((struct Obj00842 *)p)->f24=0;
 }
 ((struct Obj00842 *)p)->f30=((struct Obj00842 *)p)->f24==0;
 break;
 case 1:
 if(((struct Obj00842 *)p)->f8!=0) {
 if(((struct Obj00842 *)p)->f34!=0)func_020286C4(((struct Obj00842 *)p)->f34,((struct Obj00842 *)p)->f8,((struct Obj00842 *)p)->f14);
 if(func_02028484(p+0x38,((struct Obj00842 *)p)->f8)!=0)((struct Obj00842 *)p)->f30=1;
 }
 break;
 case 3:break;
 }
 func_020310C4(((struct Obj00842 *)p)->fC);
}
