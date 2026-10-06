/*
 * function: func_021D56FC
 * address: 0x021D56FC
 * packet: pkt_ov123_021D56FC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01933.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void *func_0201CCE4(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern signed char func_02012FFC(void);
extern void func_02028470(u8 *p, u32 v);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D56FC(char *p,int mode)
{
    void *q;
    if (!((struct Obj01933 *)p)->f44) ((struct Obj01933 *)p)->f44=(void *)func_020450F0((int)5,(int)1,(u8)1,(int)30,4,11,1);
    q=((struct Obj01933 *)p)->f44;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    if (mode) {
        func_0201C7A4(func_02045770(q),0,0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28);
    } else {
        ((struct Obj01933 *)p)->f80=func_0201CCE4(q,(int)0,(int)0,((struct Obj01933 *)p)->f2C,((struct Obj01933 *)p)->f28,(int)func_02012FFC(),((struct Obj01933 *)p)->f84,(int)2,((struct Obj01933 *)p)->fB0,15);
        func_02028470((u8 *)(p+0xa8),(int)6);
    }
    func_0201F73C(q,1,(u16)(((struct Obj01933 *)p)->f8),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}
