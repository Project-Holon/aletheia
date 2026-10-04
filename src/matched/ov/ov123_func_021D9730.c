/*
 * function: func_021D9730
 * address: 0x021D9730
 * packet: pkt_ov123_021D9730
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03801.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void func_0201F73C(void *,int,u16,int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D9730(char *p, int n)
{
    void *q;
    func_02045CAC(((struct Obj03801 *)p)->f20,n,((struct Obj03801 *)p)->f2C);
    if (!((struct Obj03801 *)p)->f4C) ((struct Obj03801 *)p)->f4C=(void *)func_020450F0(6,1,3,30,16,11,1);
    q=((struct Obj03801 *)p)->f4C;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj03801 *)p)->f2C,((struct Obj03801 *)p)->f28);
    func_0201F73C(q,1,((struct Obj03801 *)p)->f4,12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(6);
}
