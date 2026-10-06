/*
 * function: func_021D7F5C
 * address: 0x021D7F5C
 * packet: pkt_ov120_021D7F5C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
#include "../include/Obj00131.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, unsigned int index, void *dest);
extern unsigned int func_020450F0(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, u8 c, u8 d, u8 slot);
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
typedef signed short   s16;
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
void func_021D7F5C(char *p,u16 n)
{
    void *q;
    func_02045CAC(((struct Obj00131 *)p)->fC,n,(void *)(*(int *)&((struct Obj00131 *)p)->f18));
    if(!((struct Obj00131 *)p)->f94) ((struct Obj00131 *)p)->f94=(void *)func_020450F0(1,1,13,14,3,4,1);
    q=((struct Obj00131 *)p)->f94;
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,14,0);
    func_0201C7A4(func_02045770(q),2,3,(void *)(*(int *)&((struct Obj00131 *)p)->f18),(void *)(*(int *)&((struct Obj00131 *)p)->f14));
    func_02045334(q);
    func_02045374(q);
}
