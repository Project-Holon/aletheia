/*
 * function: func_021D5ED8
 * address: 0x021D5ED8
 * packet: pkt_ov115_021D5ED8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_02045874 0x02045874 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021D5FC4 0x021D5FC4 thumb ov115
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj01720.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_021D5FC4(u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32,u32,u32);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void func_02045808(struct U16Vec *vec);
void func_021D5ED8(u8 *p,u32 n) {
    void *w;
    void *s;
    func_02045CAC(((struct Obj01720 *)p)->f1C,n,((struct Obj01720 *)p)->f28);
    s=func_02045874(((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f4C);
    func_0201F250(((struct Obj01720 *)p)->f20,((struct Obj01720 *)p)->f28,s);
    if (((struct Obj01720 *)p)->f30==0) ((struct Obj01720 *)p)->f30=(void *)func_020450F0(func_021D5FC4(((struct Obj01720 *)p)->f50),1,1,30,16,11,1);
    w=((struct Obj01720 *)p)->f30;
    func_02043B5C(func_02045770(w),15);
    func_0201DD78(1,2,15);
    func_0201C7A4(func_02045770(w),0,0,((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f24);
    func_0201F73C(w,(u32)1,(u16)(((struct Obj01720 *)p)->f4),(u32)12);
    func_02045334(w);
    func_02045374(w);
    func_02041B6C(func_021D5FC4(((struct Obj01720 *)p)->f50));
    func_02045808(s);
}
