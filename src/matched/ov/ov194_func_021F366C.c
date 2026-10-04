/*
 * function: func_021F366C
 * address: 0x021F366C
 * packet: pkt_ov194_021F366C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 * symbols:
 *   func_021F3358 0x021F3358 thumb ov194
 *   func_021F25F8 0x021F25F8 thumb ov194
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 */
#include "../include/Obj00117.h"
extern int func_021F3358(int,int,unsigned char);extern void func_021F25F8(int *,int,void *);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(int,unsigned);
typedef unsigned short u16;
extern void func_021F26F0(char *p, char *target, void *window, void *font, u16 heap);
void func_021F366C(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)&((struct Obj00117 *)p)->f100!=3)return;
 if(((struct Obj00117 *)p)->f108==variant && ((struct Obj00117 *)p)->f104==index)return;
 selected=func_021F3358(*(volatile int *)&((struct Obj00117 *)p)->f100,index,variant);
 func_021F25F8((int *)p,selected,((struct Obj00117 *)p)->f12C);
 func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj00117 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj00117 *)p)->fF8),(void *)(((struct Obj00117 *)p)->fF4),((struct Obj00117 *)p)->fFE);
 ((struct Obj00117 *)p)->f104=index;((struct Obj00117 *)p)->f108=variant;
}
