/*
 * function: func_021DE7FC
 * address: 0x021DE7FC
 * packet: pkt_ov137_021DE7FC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototypes: 0203159C returns live allocated r0 here; 0203D7B0/BC receive visible r0=1.
 * symbols:
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02012934 0x02012934 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_021DF800 0x021DF800 thumb ov137
 *   func_020056A0 0x020056A0 thumb
 *   func_021DF7E8 0x021DF7E8 thumb ov137
 *   func_02047CFC 0x02047CFC arm
 *   func_021E0640 0x021E0640 thumb ov137
 *   func_021E06E0 0x021E06E0 thumb ov137
 *   func_021E04E0 0x021E04E0 thumb ov137
 *   func_02039338 0x02039338 arm
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_021E0DE8 0x021E0DE8 thumb ov137
 *   func_021E0F20 0x021E0F20 thumb ov137
 *   func_021E104C 0x021E104C thumb ov137
 *   func_021E11B4 0x021E11B4 thumb ov137
 *   func_021E13BC 0x021E13BC thumb ov137
 *   func_021E1488 0x021E1488 thumb ov137
 *   func_0202208C 0x0202208C thumb
 *   func_0203D7BC 0x0203D7BC arm
 *   d_021E1FA0 0x021E1FA0 data a2
 *   d_021E22B8 0x021E22B8 data a1
 */
#include "../include/Obj02208.h"
#include "../include/Obj08213.h"
#include "../include/Obj23739.h"
#include "../include/Obj23740.h"
#include "../include/Obj23741.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0203D7B0(int),func_0203D7BC(int);
extern void func_0203064C(u32 src, u32 dst, u32 size);
extern u8 *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,int,u32);
extern void *func_02012934(void *),*func_020490F4(u32,u16);
extern void func_021DF800(u8 *),func_021E0640(u8 *),func_021E06E0(u8 *),func_021E04E0(u8 *);
extern void func_021E0DE8(u8 *),func_021E0F20(u8 *),func_021E104C(u8 *),func_021E11B4(u8 *),func_021E13BC(u8 *),func_021E1488(u8 *);
extern void *func_020056A0(void (*)(int,void *),void *,u32);
extern void func_021DF7E8(void *arg, char *p);
extern void *func_02047CFC(u16,u16,u16);
struct Ctx;
extern u16 func_02039338(void);
extern u32 func_02030CB0(u32);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern const u16 d_021E1FA0[][5];
extern const u8 d_021E22B8[];
int func_021DE7FC(void *obj,int unused,u8 *q)
{
    u8 *p,*s;
    void *r;
    int i,n,player;
    func_0203D7B0(1);
    func_0203064C(1,114,0x80000);
    p=func_0203159C(obj,0xdac,114);
    i=0;
    func_02082BCC(p,0,0xdac);
    *(u8 * *)&((struct Obj08213 *)q)->f1C=p;
    *(u8 * *)&((struct Obj02208 *)p)->fD8=q;
    ((struct Obj02208 *)p)->fDC=((struct Obj08213 *)q)->f18;
    ((struct Obj02208 *)p)->f24=func_02012934(((struct Obj23740 *)(*(u8 * *)&((struct Obj23739 *)(*(u8 * *)&((struct Obj02208 *)p)->fD8))->f14))->f4);
    ((struct Obj02208 *)p)->fD58=func_020490F4(183,114);
    func_021DF800(p);
    ((struct Obj02208 *)p)->fD9C=func_020056A0((void (*)(int,  void *))func_021DF7E8,p,1);
    ((struct Obj02208 *)p)->fAF4=func_02047CFC(20,11,114);
    func_021E0640(p);func_021E06E0(p);func_021E04E0(p);
    n=0;
    player=func_02039338();
    s=p+0xe0;
    q=*(u8 * *)&((struct Obj02208 *)p)->fD8;
    for(;i<5;i++) {
        if(((struct Obj08213 *)q)->fC&(1<<i)) {if(i==player) break;n++;}
    }
    ((struct Obj23741 *)s)->f40=d_021E1FA0[((struct Obj08213 *)q)->f8][n]<<12;
    r=func_02030734(0x8072,func_02030CB0(32),0,(const char *)d_021E22B8,0x4ec);
    ((struct Obj02208 *)p)->fD94=r;
    ((struct Obj02208 *)p)->fD98=func_02030CBC(32,r);
    func_021E0DE8(p);func_021E0F20(p);func_021E104C(p);func_021E11B4(p);func_021E13BC(p);func_021E1488(p);
    func_0202208C(0,1,1,0,8,1,114);
    func_0203D7BC(1);
    return 1;
}
