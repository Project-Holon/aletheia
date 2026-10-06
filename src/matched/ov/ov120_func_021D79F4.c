/*
 * function: func_021D79F4
 * address: 0x021D79F4
 * packet: pkt_ov120_021D79F4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03783.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short   s16;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
void func_021D79F4(u8 *p,u16 n)
{
    void *q;
    func_02045CAC(((struct Obj03783 *)p)->fC,n,(void *)(((struct Obj03783 *)p)->f1C));
    if (!((struct Obj03783 *)p)->f30) ((struct Obj03783 *)p)->f30=(void *)func_020450F0(1,1,19,30,4,11,1);
    q=((struct Obj03783 *)p)->f30;
    func_02043B5C(func_02045770(q),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(q),0,0,(void *)(((struct Obj03783 *)p)->f1C),(void *)(((struct Obj03783 *)p)->f14));
    func_0201F73C(q,1,(u16)(((struct Obj03783 *)p)->f4),12);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
