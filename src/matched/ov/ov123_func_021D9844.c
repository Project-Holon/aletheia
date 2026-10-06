/*
 * function: func_021D9844
 * address: 0x021D9844
 * packet: pkt_ov123_021D9844
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D97CC 0x021D97CC thumb ov123
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01737.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021D97CC(int,void *);
extern void *func_020450F0(int,int,u8,int,u8,u8,u8);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02041B6C(u32 bit);
void func_021D9844(char *p, int n, int a2)
{
    void *q;
    func_021D97CC(n,((struct Obj01737 *)p)->f2C);
    if (!((struct Obj01737 *)p)->f40) ((struct Obj01737 *)p)->f40=func_020450F0((int)1,(int)1,(u8)8,(int)30,4,11,1);
    q=((struct Obj01737 *)p)->f40;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj01737 *)p)->f0),12);
    func_02045334(q);
    func_02045374(q);
    if (!((struct Obj01737 *)p)->f44) ((struct Obj01737 *)p)->f44=func_020450F0((int)1,(int)3,(u8)3,(int)22,2,11,1);
    q=((struct Obj01737 *)p)->f44;
    func_0201DD78(1,2,0);
    func_02045CAC(((struct Obj01737 *)p)->f20,10,((struct Obj01737 *)p)->f2C);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj01737 *)p)->f2C,((struct Obj01737 *)p)->f28);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(5);
}
