/*
 * function: func_021D9F24
 * address: 0x021D9F24
 * packet: pkt_ov121_021D9F24
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: duplicate the case 2/0 drawing bodies; cross-jumping retains the case 2 branch.
 * interface: 02028590 forwards the allocation result of 020285A4 in r0;
 *            this caller stores that result at +0x30 despite the old void definition.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021DA010 0x021DA010 thumb ov121
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 */
#include "../include/Obj00236.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct Rec3;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201CE48(struct Rec3 *p);
struct PrintSys;
extern int APP_KEYCURSOR_Delete(int a0);
extern void func_021DA010(u8 *);
extern u32 func_020056BC(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02028470(u8 *p, u32 v);
extern void *func_02028590(u32,u32,u32,u32);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *,u32,u32,u32,u32,int,void *,u32,u16,u16);
void func_021D9F24(u8 *p,int mode)
{
    u32 q;
    BMP_Clear(func_02045770(((struct Obj00236 *)p)->f10),((struct Obj00236 *)p)->f18);
    if(((struct Obj00236 *)p)->f8) {
        func_0201CE48(((struct Obj00236 *)p)->f8);
        ((struct Obj00236 *)p)->f8=0;
    }
    if(((struct Obj00236 *)p)->f30) {
        APP_KEYCURSOR_Delete((int)(((struct Obj00236 *)p)->f30));
        ((struct Obj00236 *)p)->f30=0;
    }
    func_021DA010(p);
    switch(mode) {
    case 2:
        ((struct Obj00236 *)p)->f3C=TIME_ICON_Create((void *)func_020056BC(),((struct Obj00236 *)p)->f10,((struct Obj00236 *)p)->f18,16,((struct Obj00236 *)p)->f1A);
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 0:
        q=((struct Obj00236 *)p)->f24;
        func_0201C6FC((struct PrintSys *)q,(u32)func_02045770(((struct Obj00236 *)p)->f1C),0,0,((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4);
        p[0x20]=1;
        ((struct Obj00236 *)p)->f28=0;
        break;
    case 1:
        func_02028470(p+0x34,2);
        ((struct Obj00236 *)p)->f30=func_02028590(((struct Obj00236 *)p)->f18,1,0,((struct Obj00236 *)p)->f1A);
        ((struct Obj00236 *)p)->f8=PRINTSYS_PrintStream(((struct Obj00236 *)p)->f10,0,0,*(u32 *)&((struct Obj00236 *)p)->f14,((struct Obj00236 *)p)->f4,func_02012FFC(),((struct Obj00236 *)p)->fC,0,((struct Obj00236 *)p)->f1A,((struct Obj00236 *)p)->f18);
        ((struct Obj00236 *)p)->f28=1;
        break;
    }
    ((struct Obj00236 *)p)->f2C=0;
}
