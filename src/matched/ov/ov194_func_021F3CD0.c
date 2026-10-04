/*
 * function: func_021F3CD0
 * address: 0x021F3CD0
 * packet: pkt_ov194_021F3CD0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj01774.h"
extern void func_02082BCC(unsigned char *,unsigned,unsigned);
extern int func_020457B0(int,unsigned short);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int,unsigned char);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern int func_02045730(int);
extern void func_020409B4(unsigned);
void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e) {
    int window;
    func_02082BCC(p,0,0x24);
    ((struct Obj01774 *)p)->f20=15;
    ((struct Obj01774 *)p)->f4=a; ((struct Obj01774 *)p)->f18=d; ((struct Obj01774 *)p)->f0=b; ((struct Obj01774 *)p)->f10=c;
    ((struct Obj01774 *)p)->f1C=func_020457B0(255,e);
    ((struct Obj01774 *)p)->f14=func_020450F0(4,1,19,30,4,15,1);
    func_0201F73C((void *)(((struct Obj01774 *)p)->f14),2,1,14);
    ((struct Obj01774 *)p)->f8=((struct Obj01774 *)p)->f14;
    ((struct Obj01774 *)p)->fC=0;
    func_02043B5C((int)func_02045770((struct Descriptor *)((struct Obj01774 *)p)->f14),((struct Obj01774 *)p)->f20);
    window=((struct Obj01774 *)p)->f14;
    func_02045334((struct Descriptor *)window); func_02045374((struct Cfg *)window);
    func_020409B4(func_02045730(window));
}
