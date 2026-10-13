/*
 * function: func_021BC990
 * address: 0x021BC990
 * packet: pkt_ov110_021BC990
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021C3C68 0x021C3C68 data
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   func_021BF6D4 0x021BF6D4 thumb ov110
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BAC4C 0x021BAC4C thumb ov110
 *   func_021BD194 0x021BD194 thumb ov110
 *   func_021BD044 0x021BD044 thumb ov110
 *   func_021BD114 0x021BD114 thumb ov110
 *   func_021BD2F0 0x021BD2F0 thumb ov110
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 */
#include "../include/Obj01249.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern const char d_021C3C68[];
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u8 *func_021BF6D4(u8 *);
typedef unsigned int   u32;
struct MsgBank;
struct R;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned func_021BAC44(u8 *);
extern unsigned func_021BAC4C(u8 *);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_021BD194(u8 *);
extern void func_021BD044(u8 *);
extern void func_021BD114(u8 *);
extern void func_021BD2F0(u8 *);
u8 *func_021BC990(u8 *a,u8 *b,void *c)
{
    u8 *p;
    int i;
    unsigned x;
    p=func_02030734(42,188,1,d_021C3C68,309);
    *(u8 * *)&((struct Obj01249 *)p)->f0=a; *(u8 * *)&((struct Obj01249 *)p)->f4=b; ((struct Obj01249 *)p)->f8=c;
    *(u8 * *)&((struct Obj01249 *)p)->fC=func_021BF6D4(b);
    ((struct Obj01249 *)p)->f30=func_02045B38(0,2,146,42);
    for (i=0;i<3;i++) {
        x=func_021BAC44(*(u8 * *)&((struct Obj01249 *)p)->f0);
        *(void **)(p+0x34+i*4)=APP_TASKMENU_RES_Create(0,8,x,func_021BAC4C(*(u8 * *)&((struct Obj01249 *)p)->f0),42);
    }
    func_02049B40(43,9,0,448,64,42);
    func_021BD194(p);func_021BD044(p);func_021BD114(p);func_021BD2F0(p);
    return p;
}
