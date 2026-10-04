/*
 * function: func_021FCC80
 * address: 0x021FCC80
 * packet: pkt_ov186_021FCC80
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020437AC 0x020437AC arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01571.h"
struct Descriptor;
struct Obj;
extern void func_021FD860(int,int,void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_020437AC(int,int);
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_020307B0(void *);
void func_021FCC80(char *p)
{
    int i;
    if(((struct Obj01571 *)p)->f1C) func_021FD860(((struct Obj01571 *)p)->f1C,0,0);
    for(i=0;i<4;i++) func_0204B3B4((struct Obj *)(*(int *)(p+0x28+i*4)));
    for(i=0;(unsigned)i<((struct Obj01571 *)p)->f4;i++) {
        if(*(int *)(p+0x8C+i*4) && *(int *)(((struct Obj01571 *)p)->f0+i*8)) func_020437AC(*(int *)(p+0x8C+i*4),*(int *)(((struct Obj01571 *)p)->f0+i*8));
    }
    func_020456F8((struct Descriptor *)(((struct Obj01571 *)p)->f38));func_020452E8((struct Descriptor *)(((struct Obj01571 *)p)->f38));
    if(((struct Obj01571 *)p)->fD<4) func_021FC0C8((char *)(((struct Obj01571 *)p)->f14),7);
    else func_021FC0C8((char *)(((struct Obj01571 *)p)->f14),8);
    if(((struct Obj01571 *)p)->f24) {
        *(unsigned short *)(((struct Obj01571 *)p)->f24)=((struct Obj01571 *)p)->f42;
        *(unsigned short *)(((struct Obj01571 *)p)->f24+2)=((struct Obj01571 *)p)->f40;
    }
    func_020307B0(p);
}
