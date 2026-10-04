/*
 * function: func_0220F4E0
 * address: 0x0220F4E0
 * packet: pkt_ov198_0220F4E0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword store at 0220F4EC writes display register 04001050.
 * symbols:
 *   d_04001050 0x04001050 data a2
 *   func_0207D534 0x0207D534 arm
 *   sub_0203101C 0x0203101C arm
 *   func_0220AF40 0x0220AF40 thumb ov196
 *   func_0220AFDC 0x0220AFDC thumb ov196
 *   func_02211034 0x02211034 thumb ov198
 *   func_0221099C 0x0221099C thumb ov198
 *   func_022104EC 0x022104EC thumb ov198
 *   func_02210608 0x02210608 thumb ov198
 *   func_02210710 0x02210710 thumb ov198
 *   func_02210D4C 0x02210D4C thumb ov198
 *   func_0220B848 0x0220B848 thumb ov198
 *   func_0220BB94 0x0220BB94 thumb ov198
 *   func_0220E2B4 0x0220E2B4 thumb ov198
 *   func_0220F060 0x0220F060 thumb ov198
 *   func_0220EA68 0x0220EA68 thumb ov198
 *   func_0220BC24 0x0220BC24 thumb ov198
 *   func_0220BE2C 0x0220BE2C thumb ov198
 *   func_0220E25C 0x0220E25C thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   func_02211998 0x02211998 thumb ov198
 *   func_02210BFC 0x02210BFC thumb ov198
 *   func_0202173C 0x0202173C thumb
 */
#include "../include/Obj00633.h"
#include "../include/Obj25226.h"
#include "../include/Obj25227.h"
#include "../include/Obj25228.h"
#include "../include/Obj25229.h"
#include "../include/Obj25231.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern volatile u16 d_04001050[];
struct Tcbl;
extern void func_0207D534(volatile u16 *reg, int brightness);
extern struct Tcbl *sub_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern u8 *func_0220AF40(u16 v);
extern void func_0220AFDC(u8 *,void *);
extern void func_02211034(u8 *),func_0221099C(u8 *),func_022104EC(u8 *),func_02210608(u8 *),func_02210710(u8 *);
extern void func_02210D4C(u8 *,u32),func_0220B848(u8 *,u32),func_0220BB94(u8 *,u32);
extern void func_0220E2B4(char *),func_0220F060(u8 *),func_0220EA68(char *,u32),func_0220BC24(u8 *);
extern int func_0220BE2C(char *,int);
extern void func_0220E25C(u8 *);
extern int func_022110D4(u8 *,int);
extern u32 func_02210F04(u32,u32);
extern void func_02211998(u8 *,u32,u32),func_02210BFC(u8 *,int);
extern int func_0202173C(void *,u16,u16,short,u8,u8,u16,void *);
int func_0220F4E0(u8 *p)
{
    d_04001050[0]=0;
    func_0207D534((u16 *)((u32)d_04001050+28),-16);
    ((struct Obj00633 *)p)->f1D4=sub_0203101C(((struct Obj25226 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,((struct Obj25227 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10,1,4);
    if((*(u8 **)p)[31]==4) p[0x2180]=6;
    else if((*(u8 **)p)[31]==5) p[0x2180]=4;
    else p[0x2180]=0;
    ((struct Obj00633 *)p)->f2188=func_0220AF40(((struct Obj25228 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f10);
    func_02211034(p);func_0221099C(p);func_022104EC(p);func_02210608(p);func_02210710(p);
    func_02210D4C(p,p[0x2180]);func_0220B848(p,p[0x2180]);func_0220BB94(p,p[0x2180]);
    func_0220E2B4((char *)p);
    if((*(u8 **)p)[31]==5) func_0220F060(p);
    func_0220EA68((char *)p,p[0x2180]);func_0220BC24(p);func_0220BE2C((char *)p,p[0x2180]);func_0220E25C(p);
    if(**(u8 * *)&((struct Obj25229 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f44==1) *(u32 *)&((struct Obj00633 *)p)->f218C=1;
    else *(u32 *)&((struct Obj00633 *)p)->f218C=0;
    func_0220AFDC(*(u8 * *)&((struct Obj00633 *)p)->f2188,((struct Obj00633 *)p)->f218C);
    if(p[0x2180]==0) {
        if(func_02210F04((u32)p,func_022110D4(p,0))==1) (*(u8 **)p)[32]=1;
        func_02211998(p,p[0x2180],(*(u8 **)p)[32]);
    } else if((*(u8 **)p)[31]==5) func_02211998(p,p[0x2180],(*(u8 **)p)[75]);
    else func_02211998(p,p[0x2180],0);
    func_02210BFC(p,p[0x2180]);
    func_0202173C(((struct Obj00633 *)p)->f1D8,10,65535,0,16,0,0,((struct Obj25231 *)(*(u8 * *)&((struct Obj00633 *)p)->f0))->f28);
    ((struct Obj00633 *)p)->f2540=1;
    return 1;
}
