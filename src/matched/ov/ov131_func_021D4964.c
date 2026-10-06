/*
 * function: func_021D4964
 * address: 0x021D4964
 * packet: pkt_ov131_021D4964
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * following: 0x021D4F22 is two bytes of alignment padding before func_021D4F24.
 * lever: the loop store associates (p+i*4)+0x130; the second constructor result after func_02027770/74 is stored at +0x120.
 * initialization: resource handles come from the original constructors; no uninitialized local or added success assumption. The u8 counter visits 0..16.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049238 0x02049238 arm
 *   func_021D67EC 0x021D67EC thumb ov131
 *   func_021D7B4C 0x021D7B4C thumb ov131
 *   func_021D9980 0x021D9980 thumb ov131
 *   func_021D8884 0x021D8884 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16);
extern int func_0204A6C8(void *,u32,u32,u32,u16);
extern int func_0204AF28(void *,u32,u32,u32);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_020275FC(u32);
extern u32 func_02027600(u32);
extern u32 func_020275F8(u32);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern int func_02027768(void);
extern int func_0202776C(int);
extern int func_02027770(int);
extern int func_02027774(int);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32);
extern u32 func_020276C0(u32);
extern int func_02027720(int);
extern int func_0202772C(int);
extern int func_02027738(int,int);
extern int func_02027740(int,int);
extern int func_02027748(void);
extern int func_0202774C(int);
extern int func_02027750(int);
extern int func_02027754(int);
extern void func_021D67EC(u16 *,int,void *);
extern void func_021D7B4C(u8 *,u8 *,void *);
extern void func_021D9980(u8 *,u8 *,void *);
extern void func_021D8884(u8 *,u8 *,void *);
#define H (*(u16 *)p)
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
void func_021D4964(u8 *p)
{
    u32 x, y;
    void *a;
    void *b;
    u8 i;
    a=func_020490F4(78,H);
    func_02049B68(a,0,0,0,0,H);
    func_02049658(a,8,2,0,0,0,H);
    func_020498F4(a,70,3,0,0,0,H);
    func_02049B68(a,1,4,0,0,H);
    func_02049658(a,10,6,0,0,0,H);
    func_02049658(a,9,5,0,0,0,H);
    func_020498F4(a,71,7,0,0,0,H);
    func_020498F4(a,65,5,0,0,0,H);
    I(0x98)=func_0204AC18(a,3,0,0,0,4,H);
    I(0xb0)=func_0204AC18(a,5,0,0x160,0,2,H);
    I(0xb4)=func_0204AC18(a,6,1,0,0,5,H);
    I(0xb8)=func_0204AC18(a,4,0,0x1a0,0,1,H);
    I(0xc4)=func_0204AC18(a,2,0,0x1c0,0,1,H);
    I(0xc8)=func_0204A6C8(a,11,0,0,H);
    I(0xe8)=func_0204A6C8(a,15,0,0,H);
    I(0xec)=func_0204A6C8(a,14,0,0,H);
    I(0xf8)=func_0204A6C8(a,13,0,0,H);
    I(0xfc)=func_0204AF28(a,78,129,H);
    I(0x118)=func_0204AF28(a,81,132,H);
    I(0x11c)=func_0204AF28(a,80,131,H);
    I(0x128)=func_0204AF28(a,82,133,H);
    I(0x12c)=func_0204AF28(a,79,130,H);
    b=func_020490F4(func_020275E4(),H);
    func_02049B68(b,func_02027624(),0,0x120,32,H);
    func_02049658(b,func_02027628(),1,0,0,0,H);
    func_020498F4(b,func_0202762C(),1,0,0,0,H);
    func_020413B0(1,0,21,32,3,9);
    func_02049B68(b,0,4,0x1a0,32,H);
    I(0xac)=func_0204AC18(b,1,1,0x100,0,1,H);
    I(0xe4)=func_0204A6C8(b,2,0,1,H);
    I(0x114)=func_0204AF28(b,5,8,H);
    I(0xa4)=func_0204AC18(b,func_020275E8(),0,0x100,0,3,H);
    I(0xa8)=func_0204AC18(b,func_020275E8(),1,0xa0,0,3,H);
    x=func_020275FC(2); y=func_02027600(2);
    I(0x10c)=func_0204AF28(b,x,y,H);
    x=func_020275FC(0); y=func_02027600(0);
    I(0x110)=func_0204AF28(b,x,y,H);
    for(i=0;i<17;i++) *(int *)(p+i*4+0x130)=func_0204A6C8(b,func_020275F8(i),0,0,H);
    I(0xd8)=func_0204A6C8(b,56,0,1,H);
    I(0xdc)=func_0204A6C8(b,57,0,1,H);
    I(0xe0)=func_0204A6C8(b,58,0,1,H);
    I(0xcc)=func_0204A6C8(b,func_02027618(),0,0,H);
    x=func_0202761C(2); y=func_02027620(2);
    I(0x100)=func_0204AF28(b,x,y,H);
    I(0xbc)=func_0204AC18(b,func_02027768(),0,0xa0,0,1,H);
    I(0xf0)=func_0204A6C8(b,func_0202776C(2),0,0,H);
    x=func_02027770(2); y=func_02027774(2);
    I(0x120)=func_0204AF28(b,x,y,H);
    I(0xa0)=func_0204AC18(b,func_02027748(),0,0xc0,0,1,H);
    I(0xd4)=func_0204A6C8(b,func_0202774C(2),0,0,H);
    x=func_02027750(2); y=func_02027754(2);
    I(0x108)=func_0204AF28(b,x,y,H);
    I(0xc0)=func_0204AC18(b,func_020276B4(),0,0x80,0,1,H);
    I(0xf4)=func_0204A6C8(b,func_020276B8(),0,0,H);
    x=func_020276BC(2); y=func_020276C0(2);
    I(0x124)=func_0204AF28(b,x,y,H);
    I(0x9c)=func_0204AC18(b,func_02027720(1),0,0xe0,0,1,H);
    I(0xd0)=func_0204A6C8(b,func_0202772C(1),0,0,H);
    x=func_02027738(1,2); y=func_02027740(1,2);
    I(0x104)=func_0204AF28(b,x,y,H);
    func_02049238(b);
    func_021D67EC((u16 *)p,I(0x88),a);
    func_021D7B4C(p,P(0x8c),a);
    func_021D9980(p,P(0x90),a);
    func_021D8884(p,P(0x94),a);
    func_02049238(a);
}
