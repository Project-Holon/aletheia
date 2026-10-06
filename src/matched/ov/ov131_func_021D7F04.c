/*
 * function: func_021D7F04
 * address: 0x021D7F04
 * packet: pkt_ov131_021D7F04
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): slot order closed by two source facts. (1) func_02017E88's third parameter is
 *   a buffer pointer (void *), so the 0x9a and 0x8d calls pass the v2 buffer directly with no
 *   conversion; casting it to u32 lets the compiler share one conversion temp, which moves v2 below
 *   the named locals. (2) The species argument in the first t arm is a named local; nested, t lands lowest.
 * symbols:
 *   func_021D618C 0x021D618C thumb ov131
 *   func_021D6214 0x021D6214 thumb ov131
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02017EB4 0x02017EB4 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_02018584 0x02018584 thumb
 *   func_02043AF4 0x02043AF4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   g_020A7370 0x020A7370 data
 */
#include "../include/Obj00112.h"
#include "../include/Obj01256.h"
#include "../include/Obj23145.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D618C(u8 *,u32,int,int,u16,u16);
extern void func_021D6214(u8 *,u32,void *,int,u16,u16,u16);
struct Bmp;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_02017E88(void *,u32,void *);
extern u32 func_02017EB4(void *);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *vec);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(void *,u32,const void *,u32,u32,u32);
extern u32 func_02018584(u16,u16,u16);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void *g_020A7370;
void func_021D7F04(u8 *p,u8 *q,void *mon)
{
    void *ws;
    u32 v;
    void *t;
    void *v2;
    void *ws2;
    u32 s18;
    u32 A;
    u32 B;
    u32 C;
    void *ws3,*ws4,*ws5;
    u32 s30,s34,n,tt,r,k;
    u16 pal;
    u32 tile;
    u16 x;
    u32 species;
    if(((struct Obj00112 *)p)->f38==0) {
        func_021D618C(p,((struct Obj01256 *)q)->fC,8,1,1,0x3c40);
        ws=func_0201EC64(((struct Obj00112 *)p)->f0);
        v=func_02017E88(mon,5,0);
        pal=0x440;
        if(((struct Obj23145 *)(*(u8 * *)&((struct Obj00112 *)p)->f8))->f18==0) v=(*(u16 **)(q+8))[v];
        if(func_02017EB4(mon)==1) pal=0xc80;
        if(v==999) {
            func_021D6214(p,((struct Obj01256 *)q)->fC,ws,0x16,0x41,1,pal);
        } else {
            func_0201EFA4(ws,0,v,3,2,1);
            func_021D6214(p,((struct Obj01256 *)q)->fC,ws,9,0x41,1,pal);
        }
        func_0201ED04(ws);
        func_021D618C(p,*(u32 *)&((struct Obj01256 *)q)->f10,10,1,1,0x3c40);
        if(((struct Obj00112 *)p)->f38==0) {species=func_02017E88(mon,5,0); t=func_02045EC0(g_020A7370,species);}
        else t=func_02045EC0(g_020A7370,0x28a);
        tile=(u32)func_02045770(((struct Obj01256 *)q)->f10);
        pal=0x440;
        func_0201C724(((struct Obj00112 *)p)->f84,tile,0x41,1,(u32)t,*(u32 *)&((struct Obj00112 *)p)->f80,pal);
        func_02045808(t);
        func_021D618C(p,((struct Obj01256 *)q)->f14,12,1,1,0x3c40);
        func_021D618C(p,((struct Obj01256 *)q)->f18,13,1,1,0x3c40);
        v2=func_020457B0(0x20,((struct Obj00112 *)p)->f0);
        ws2=func_0201EC64(((struct Obj00112 *)p)->f0);
        r=func_02017E88(mon,0x9a,v2);
        if(r==0) pal=0x14c0;
        else if(r==1) pal=0xc80;
        func_02017E88(mon,0x8d,v2);
        func_0201EE0C(ws2,0,v2,0,1,2);
        func_021D6214(p,((struct Obj01256 *)q)->f18,ws2,14,0x41,1,pal);
        func_0201ED04(ws2);
        func_02045808(v2);
        func_021D618C(p,((struct Obj01256 *)q)->f1C,15,1,1,0x3c40);
        ws3=func_0201EC64(((struct Obj00112 *)p)->f0);
        x=func_02017E88(mon,7,0);
        func_0201EFA4(ws3,0,x,5,2,1);
        func_021D6214(p,((struct Obj01256 *)q)->f1C,ws3,16,0x41,1,0x440);
        func_0201ED04(ws3);
        n=func_02017E88(mon,0x9e,0);
        s18=func_02017E88(mon,8,0);
        s30=func_02017E88(mon,5,0);
        tt=func_02017E88(mon,0x6f,0);
        A=func_02018584((u16)s30,(u16)tt,(u16)(n+1));
        s34=func_02017E88(mon,5,0);
        tt=func_02017E88(mon,0x6f,0);
        B=func_02018584((u16)s34,(u16)tt,(u16)n);
        C=A-s18;
        if(n==100) C=0;
        func_021D618C(p,((struct Obj01256 *)q)->f20,17,1,1,0x3c40);
        ws4=func_0201EC64(((struct Obj00112 *)p)->f0);
        func_0201EFA4(ws4,0,s18,7,0,1);
        func_021D6214(p,((struct Obj01256 *)q)->f24,ws4,18,1,1,0x440);
        func_0201ED04(ws4);
        func_021D618C(p,((struct Obj01256 *)q)->f28,19,1,1,0x3c40);
        func_021D618C(p,((struct Obj01256 *)q)->f2C,20,1,1,0x440);
        ws5=func_0201EC64(((struct Obj00112 *)p)->f0);
        func_0201EFA4(ws5,0,C,6,0,1);
        func_021D6214(p,((struct Obj01256 *)q)->f2C,ws5,21,0x21,1,0x440);
        func_0201ED04(ws5);
        if(n!=100) {
            r=A-B-C;
            k=(r<<6)/(A-B);
            if(r!=0 && k==0) k=1;
            if(k==0x40) k=k-1;
            func_02043AF4(func_02045770(((struct Obj01256 *)q)->f30),0,3,(u16)k,3,5);
        }
    }
    ((struct Obj01256 *)q)->f0=1;
}
