/*
 * function: func_021DC894
 * address: 0x021DC894
 * packet: pkt_ov119_021DC894
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   ov114_id 0x00000072 data a1
 *   ov117_id 0x00000075 data a1
 *   ov118_id 0x00000076 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_0204363C 0x0204363C arm
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   d_021E80B0 0x021E80B0 data a4
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_021DC538 0x021DC538 thumb ov119
 *   func_021DC5F0 0x021DC5F0 thumb ov119
 *   func_021DC3EC 0x021DC3EC thumb ov119
 *   func_021DC458 0x021DC458 thumb ov119
 *   func_0204B100 0x0204B100 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_0203A574 0x0203A574 arm
 *   d_021E7614 0x021E7614 data a4
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021DC500 0x021DC500 thumb ov119
 *   func_021E30EC 0x021E30EC thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0B34 0x021E0B34 thumb ov119
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_021E3FE4 0x021E3FE4 thumb ov119
 *   func_021DC494 0x021DC494 thumb ov119
 *   func_021E3C20 0x021E3C20 thumb ov119
 *   func_0203D34C 0x0203D34C arm
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_020435F4 0x020435F4 arm
 *   func_021DAC60 0x021DAC60 thumb ov119
 */
#include "../include/Obj03256.h"
#include "../include/Obj04478.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_02034AC4(int),func_020173EC(void),func_021D8A24(void *);
extern char ov067_id[],ov114_id[],ov117_id[],ov118_id[];
extern void func_0204363C(int),func_0203D7B0(int),func_0203D7BC(int),func_02043534(int),func_020435F4(int),func_0203D34C(int,int);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern const char d_021E80B0[];
extern char d_021E7614[];
extern void *func_0200CA1C(void *);
typedef unsigned int   u32;
struct Bank;
struct Blk37;
extern u32 func_0200CA38(struct Blk37 *p);
extern void func_021DC538(char *,void *,u16),func_021DC5F0(char *),func_021DC3EC(char *),func_021DC458(char *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0203A574(unsigned,unsigned,unsigned,unsigned);
extern void *func_020056A0(void (*)(void *,void *),void *,int);
extern void func_021DC500(int a, char *p);
extern void func_021E30EC(char *);
extern void func_021D8E84(void *,int);
extern void func_021E0B34(char *p);
extern void func_021E10D8(void *);
extern void func_021E3FE4(void *);
extern void func_021DC494(char *);
extern void func_021E3C20(void *);
extern void func_021E3208(void *,int);
extern void func_021DAC60(char *p);
#define I(o) (*(int *)(p+(o)))
#define H(o) (*(u16 *)(p+(o)))
int func_021DC894(int a,int b,char *q,char *p,int n)
{
    if(n<5) {func_02034AC4((int)ov067_id);func_02034AC4((int)ov114_id);}
    if(n==0 || n==4) func_02034AC4((int)ov117_id);
    else func_02034AC4((int)ov118_id);
    func_0204363C(1);
    H(0x5f4)=31;
    I(0x118c)=n;
    *(char * *)&((struct Obj03256 *)p)->f8=q;
    I(0x5dc)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0x110b);
    I(0x5e0)=(int)func_02030734(0x91,func_020173EC(),1,d_021E80B0,0x110c);
    I(0x10a4)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110d);
    I(0x10a8)=(int)func_02030734(0x91,512,0,d_021E80B0,0x110e);
    ((struct Obj03256 *)p)->f11F6=func_0200CA38(func_0200CA1C(((struct Obj04478 *)q)->f14));
    if(q) func_021DC538(p,((struct Obj04478 *)q)->f14,((struct Obj04478 *)q)->f2E);
    func_021DC5F0(p);func_021DC3EC(p);func_021DC458(p);
    I(0x9c4)=(int)func_0204B100(0x154,0,H(0x5f4));
    if(func_021D8A24(p)) {
        func_0203A574(0xc00,(unsigned)d_021E7614,24,(unsigned)p);
        func_0203D7B0(1);func_0203D7BC(1);
    }
    I(0x9c8)=(int)func_020056A0((void (*)(void *, void *))func_021DC500,p,0);
    I(0xf60)=0;
    I(0xf84)=-1;I(0x109c)=-1;I(0xf7c)=-1;I(0xf80)=-1;I(0xf98)=-1;I(0xf94)=-1;
    func_021E30EC(p);
    if(((struct Obj04478 *)q)->f8==1) {
        func_02043534(16);func_021D8E84(p,(int)func_021E0B34);((struct Obj04478 *)q)->f8=0;return 1;
    }
    func_021E10D8(p);func_021E3FE4(p);
    if(I(0x118c)<4) {func_021DC494(p);func_021E3C20(p);func_0203D34C(1,H(0x5f4));}
    func_021E3208(p,0);func_02043534(0);func_020435F4(0);func_021D8E84(p,(int)func_021DAC60);
    return 1;
}
