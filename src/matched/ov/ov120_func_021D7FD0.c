/*
 * function: func_021D7FD0
 * address: 0x021D7FD0
 * packet: pkt_ov120_021D7FD0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D80D2.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00131.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct WordSet;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D7FD0(char *p,void *r)
{
    u32 a,b,c,d;
    void *q;
    a=func_0200856C(r);
    b=func_02008570(r);
    c=func_02025C1C(a,b,func_02008564(r));
    d=func_02025C30(a,b,func_02008564(r));
    if(a==c && b==d) {
        func_0201F048(((struct Obj00131 *)p)->f10,0,func_0200856C(r));
        a=func_0200856C(r);
        func_0201F094(((struct Obj00131 *)p)->f10,1,a,func_02008570(r));
    } else {
        func_0201F048(((struct Obj00131 *)p)->f10,0,0);
        func_0201F094(((struct Obj00131 *)p)->f10,1,0,0);
    }
    func_02045CAC(((struct Obj00131 *)p)->fC,34,((struct Obj00131 *)p)->f20);
    func_0201F250(((struct Obj00131 *)p)->f10,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f20);
    if(!((struct Obj00131 *)p)->f84) ((struct Obj00131 *)p)->f84=(void *)func_020450F0(1,1,15,30,5,11,1);
    q=((struct Obj00131 *)p)->f84;
    func_02043B5C(func_02045770(q),0);
    func_0201DD78(15,2,0);
    func_0201C7A4(func_02045770(q),5,5,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f14);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
