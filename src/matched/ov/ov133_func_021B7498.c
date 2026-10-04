/*
 * function: func_021B7498
 * address: 0x021B7498
 * packet: pkt_ov133_021B7498
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA1D8 0x021BA1D8 thumb ov133
 *   func_021BA0F8 0x021BA0F8 thumb ov133
 *   func_021F4D40 0x021F4D40 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_0204F5A8 0x0204F5A8 arm
 *   func_0204F150 0x0204F150 arm
 */
#include "../include/Obj00777.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 * func_021BA184(void *);
extern u32 func_021BA208(u8 *p);
extern void func_021BA1D8(u8 *,void *),func_021BA0F8(void *);
extern void func_0204F5A8(void *,unsigned int),func_0204F150(u8 *,int);
extern void func_021F4D40(u8 *p, u8 *e);
extern void func_021F4948(u8 *);
void func_021B7498(u8 *p)
{
    u8 *e,*next;
    int i;
    e=func_021BA184(((struct Obj00777 *)p)->f181C);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1820);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1824);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    e=func_021BA184(((struct Obj00777 *)p)->f1828);
    while(e){next=(u8 *)func_021BA208(e);func_021BA1D8(e,((struct Obj00777 *)p)->f1884);e=next;}
    for(i=0;i<14;i++)func_0204F5A8(((struct Obj00777 *)p)->f188C,*(unsigned int *)(p+i*4+0x5c));
    func_0204F150(*(u8 * *)&((struct Obj00777 *)p)->f188C,((struct Obj00777 *)p)->f58);
    func_021F4D40((u8 *)(*(int *)&((struct Obj00777 *)p)->f1884),(u8 *)(((struct Obj00777 *)p)->f4C));
    func_0204F150(*(u8 * *)&((struct Obj00777 *)p)->f188C,((struct Obj00777 *)p)->f54);
    for(i=0;i<((struct Obj00777 *)p)->fA8;i++){
        func_0204F150(*(u8 **)(p+0x188c),*(int *)(p+i*20+0xb0));
        func_0204F150(*(u8 **)(p+0x188c),*(int *)(p+i*20+0xb4));
    }
    func_021BA0F8(((struct Obj00777 *)p)->f181C);func_021BA0F8(((struct Obj00777 *)p)->f1820);
    func_021BA0F8(((struct Obj00777 *)p)->f1824);func_021BA0F8(((struct Obj00777 *)p)->f1828);
    func_021F4948(*(u8 **)(p+0x1884));
}
