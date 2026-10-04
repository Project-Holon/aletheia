/*
 * function: func_021D5960
 * address: 0x021D5960
 * packet: pkt_ov123_021D5960
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj05361.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void *func_020450F0(int,int,u8,int,u8,u8,u8);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(unsigned int,unsigned int,unsigned int);
extern void func_0201C7A4(void *,short,short,void *,void *);
extern void func_0201F73C(void *,int,u16,int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D5960(char *p,int a,int b)
{
    void *q;
    if (((struct Obj05361 *)p)->f48) func_020452E8(((struct Obj05361 *)p)->f48);
    q=func_020450F0(6,1,a,30,b,11,1);
    ((struct Obj05361 *)p)->f48=q;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,((struct Obj05361 *)p)->f2C,((struct Obj05361 *)p)->f28);
    func_0201F73C(q,1,((struct Obj05361 *)p)->f4,12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(6);
}
