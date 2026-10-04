/*
 * function: func_021F35A8
 * address: 0x021F35A8
 * packet: pkt_ov194_021F35A8
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F2608 0x021F2608 thumb ov194
 *   func_021F3358 0x021F3358 thumb ov194
 *   func_021F256C 0x021F256C thumb ov194
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F26F0 0x021F26F0 thumb ov194
 *   func_02040AE0 0x02040AE0 arm
 *   func_02040588 0x02040588 arm
 *   func_020409B4 0x020409B4 arm
 *   func_021F2884 0x021F2884 thumb ov194
 */
#include "../include/Obj01773.h"
typedef unsigned int   u32;
extern void func_021F2608(void *p);
extern u32 func_021F3358(u32 a, u32 b, u32 c);
extern void func_021F256C(char *,unsigned,int,void *,unsigned short);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(int,unsigned);
typedef unsigned short u16;
extern void func_021F26F0(char *p, char *target, void *window, void *font, u16 heap);
extern void func_02040AE0(unsigned,const void *,unsigned);extern void func_02040588(unsigned,unsigned);extern void func_020409B4(unsigned);
extern void func_021F2884(int *,int,int);
void func_021F35A8(char *p,int mode) {
 int index;
 if(((struct Obj01773 *)p)->f100==mode)return;
 func_021F2608(p);
 index=func_021F3358(mode,((struct Obj01773 *)p)->f104,((struct Obj01773 *)p)->f108);
 func_021F256C(p,mode,index,((struct Obj01773 *)p)->f12C,((struct Obj01773 *)p)->fFE);
 func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj01773 *)p)->fE0),0);
 func_021F26F0(p,p+0xEC,(void *)(((struct Obj01773 *)p)->fF8),(void *)(((struct Obj01773 *)p)->fF4),((struct Obj01773 *)p)->fFE);
 if(mode==3) {func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f124+12,2048);func_02040588(2,0);}
 else func_02040AE0(1,*(char * *)&((struct Obj01773 *)p)->f128+12,2048);
 func_020409B4(1);
 if(mode==3 || ((struct Obj01773 *)p)->f100==3)func_021F2884((int *)(p+0xD8),((struct Obj01773 *)p)->f100,mode);
 ((struct Obj01773 *)p)->f100=mode;
}
