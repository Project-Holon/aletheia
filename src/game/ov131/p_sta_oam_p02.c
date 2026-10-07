/*
 * file:     p_sta_oam_p02.c
 * unit:     yes
 * function: func_021D48E4, func_021D4940, func_021D4964, func_021D4F24, func_021D4FBC
 * address:  0x021D48E4
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02061C30 0x02061C30 arm
 *   func_02014BA8 0x02014BA8 thumb
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
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
 *   func_021D8904 0x021D8904 thumb ov131
 *   func_021D9A04 0x021D9A04 thumb ov131
 *   func_021D7BF0 0x021D7BF0 thumb ov131
 *   func_021D6808 0x021D6808 thumb ov131
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   g_BFA0 0x021DBFA0 data ov131
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D62E4 0x021D62E4 thumb ov131
 *   func_021D6810 0x021D6810 thumb ov131
 *   func_021D8938 0x021D8938 thumb ov131
 *   func_021D9A4C 0x021D9A4C thumb ov131
 */
#include "../../matched/include/Obj10503.h"
#include "../../matched/include/Obj08143.h"
#include "../../matched/include/Obj00591.h"

#define H (*(u16 *)p)
#define I(k) (*(int *)(p+(k)))
#define P(k) (*(void **)(p+(k)))
struct Bank;
struct BgConfig;
struct BgTemplate;
struct S;
struct Obj;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

struct Bytes { u8 v[8]; };

struct Desc {u16 x,y,z;u8 kind,flag;};

struct Context {u8 prefix[0x100];u8 rest[0x74];void *bank;void *actors[8];};

extern void func_02061C30(void);
extern void func_02014BA8(u8 *a0);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02046788(void);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_020403F4(unsigned int);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020409B4(u32);
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
extern void func_021D8904(void *a, struct S *s);
extern void func_021D9A04(u8 *a, u8 *p);
extern void func_021D7BF0(void *a, unsigned char *p);
extern void func_021D6808(void *,void *);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021D62E4(char *);
extern void func_021D6810(u8 *a, u8 *p);
extern void func_021D8938(u8 *a, u8 *p);
extern void func_021D9A4C(u8 *a, u8 *p);
void func_021D48E4(char *p);
void func_021D4940(struct BgConfig *cfg,u32 bg,u32 mode);
void func_021D4964(u8 *p);
void func_021D4F24(char *p);
void func_021D4FBC(struct Context *ctx);
extern struct Bytes g_BFA0[3];

/*
 * 2026-10-02 R3: closed by the arm9 witness src/matched/arm9/func_02061C30.c
 *   (the tail-call stub matches under ../2.0/sp2; see its header).
 * extent: Two zero padding bytes at 0x021D493E.
 */
void func_021D48E4(char *p)
{
    func_02061C30();
    func_02014BA8(((struct Obj10503 *)p)->f78);
    func_02048AC4(((struct Obj10503 *)p)->f70);
    func_02046788();
    func_0204B1CC(((struct Obj10503 *)p)->f174);
    func_0204A5AC();
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_020450C8();
    func_0203F9B4();
}

void func_021D4940(struct BgConfig *cfg,u32 bg,u32 mode)
{
    func_0203FCA0(bg,(const struct BgTemplate *)cfg,mode);
    func_02040588(bg,1);
    func_020414AC(bg);
    func_020409B4(bg);
}

/*
 * following: 0x021D4F22 is two bytes of alignment padding before func_021D4F24.
 * lever: the loop store associates (p+i*4)+0x130; the second constructor result after func_02027770/74 is stored at +0x120.
 * initialization: resource handles come from the original constructors; no uninitialized local or added success assumption. The u8 counter visits 0..16.
 */
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

/*
 * extent: Two trailing zero alignment bytes at 0x021D4FBA.
 */
void func_021D4F24(char *p)
{
    u8 i;
    func_021D8904(p,((struct Obj08143 *)p)->f94);
    func_021D9A04((u8 *)p,((struct Obj08143 *)p)->f90);
    func_021D7BF0(p,((struct Obj08143 *)p)->f8C);
    func_021D6808(p,((struct Obj08143 *)p)->f88);
    for(i=0;i<=11;i++) func_0204ADA4((u32)(*(void **)(p+i*4+0x98)));
    for(i=12;i<=24;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x98)));
    for(i=25;i<=37;i++) func_0204AFD8((u32)(*(void **)(p+i*4+0x98)));
    for(i=0;i<17;i++) func_0204A8D4((u32)(*(void **)(p+i*4+0x130)));
}

/*
 * lever: real far bank/actor struct fields retain four offset spills.
 * interface: owner 0204B294 legacy void prototype tail-forwards allocator
 *   0204CFDC, whose full body returns an object pointer; caller consumes r0.
 *   All seven arguments preserve owner's full-word ids and u16 stack args.
 *   Descriptor x/y/z/kind/flag all initialize before any consumer call.
 *   Byte tables are consecutive records at witnessed base 021DBFA0.
 */
void func_021D4FBC(struct Context *ctx)
{
    char *p=(char *)ctx;
    struct Bytes z=g_BFA0[2];
    struct Bytes x=g_BFA0[0];
    struct Desc d;
    u8 i,j;
    u32 a,b;
    d.kind=10;d.flag=0;
    for(i=0;i<8;i++){
        if(i<=2){a=((struct Obj00591 *)p)->fC8;b=((struct Obj00591 *)p)->fFC;}
        else{a=((struct Obj00591 *)p)->fCC;b=((struct Obj00591 *)p)->f100;}
        d.x=x.v[i];d.y=(i==3)?172:168;d.z=z.v[i];
        ctx->actors[i]=func_0204B294(ctx->bank,a,((struct Obj00591 *)p)->f98,b,&d,0,((struct Obj00591 *)p)->f0);
        func_0204B92C(ctx->actors[i],1);
        func_0204B3DC(ctx->actors[i],1);
    }
    d.x=0;d.y=0;d.z=0;
    ((struct Obj00591 *)p)->f198=func_0204B294((void *)*(u32 *)&((struct Obj00591 *)p)->f174,((struct Obj00591 *)p)->f130,((struct Obj00591 *)p)->fA4,((struct Obj00591 *)p)->f10C,&d,0,((struct Obj00591 *)p)->f0);
    ((struct Obj00591 *)p)->f19C=func_0204B294((void *)*(u32 *)&((struct Obj00591 *)p)->f174,((struct Obj00591 *)p)->f130,((struct Obj00591 *)p)->fA4,((struct Obj00591 *)p)->f10C,&d,0,((struct Obj00591 *)p)->f0);
    for(j=0;j<2;j++)func_0204B3DC(*(void **)(p+0x198+j*4),0);
    if((*(u8 **)(p+8))[13]==2)for(i=0;i<8;i++)if(i!=7)func_0204B3DC(*(void **)(p+0x178+i*4),0);
    if(func_021D62E4(p)==0){func_0204B3DC(((struct Obj00591 *)p)->f190,0);func_0204B3DC(((struct Obj00591 *)p)->f184,0);}
    func_021D6810((u8 *)p,((struct Obj00591 *)p)->f88);
    func_021D8938((u8 *)p,((struct Obj00591 *)p)->f94);
    func_021D9A4C((u8 *)p,((struct Obj00591 *)p)->f90);
}
