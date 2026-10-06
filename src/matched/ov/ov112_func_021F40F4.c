/*
 * function: func_021F40F4
 * address: 0x021F40F4
 * packet: pkt_ov112_021F40F4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment at 0x021F427E; next code at 0x021F4280.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02049B40 0x02049B40 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045924 0x02045924 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj00669.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 pad:9; u32 a:7; u32 b:5; u32 c:6; u32 tail:5; } Input;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct GfFont;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *,s16,s16,void *,void *,u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
struct Strbuf;
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_020409B4(u32);
void func_021F40F4(u8 *p)
{
    void *buf;
    void *t;
    void *f;
    void *b;
    ((struct Obj00669 *)p)->f54=(void *)func_020450F0(1,24,22,8,2,10,1);
    ((struct Obj00669 *)p)->f58=(void *)func_020450F0(1,1,1,30,2,10,1);
    func_02043B5C(func_02045770(((struct Obj00669 *)p)->f54),0);
    func_02043B5C(func_02045770(((struct Obj00669 *)p)->f58),0);
    ((struct Obj00669 *)p)->f5C=func_0201D7EC(23,3,0,0,((struct Obj00669 *)p)->f0);
    ((struct Obj00669 *)p)->f60=func_0201D7EC(23,0,0,0,((struct Obj00669 *)p)->f0);
    func_02049B40(23,5,0,320,32,((struct Obj00669 *)p)->f0);
    buf=func_020457B0(128,((struct Obj00669 *)p)->f0);
    t=func_0201EC64(((struct Obj00669 *)p)->f0);
    f=func_02045B38(0,2,78,((struct Obj00669 *)p)->f0);
    b=func_02045EC0(f,0);
    func_0201EFA4(t,0,(*(Input * *)&((struct Obj00669 *)p)->f4)->a,2,2,1);
    func_0201EFA4(t,1,(*(Input * *)&((struct Obj00669 *)p)->f4)->b,2,2,1);
    func_0201EFA4(t,2,(*(Input * *)&((struct Obj00669 *)p)->f4)->c,2,2,1);
    func_0201F250(t,buf,b);
    func_0201C7D0(func_02045770(((struct Obj00669 *)p)->f54),0,0,buf,((struct Obj00669 *)p)->f5C,3424);
    func_02045808(buf);
    func_02045808(b);
    func_0201ED04(t);
    func_02045C04(f);
    buf=func_020457B0(37,((struct Obj00669 *)p)->f0);
    func_02045924(buf,(const u16 *)(*(u8 * *)&((struct Obj00669 *)p)->f4+356));
    func_0201C7D0(func_02045770(((struct Obj00669 *)p)->f58),0,0,buf,((struct Obj00669 *)p)->f60,15424);
    func_02045808(buf);
    func_02045334(((struct Obj00669 *)p)->f54);
    func_02045374(((struct Obj00669 *)p)->f54);
    func_02045334(((struct Obj00669 *)p)->f58);
    func_02045374(((struct Obj00669 *)p)->f58);
    func_020409B4(1);
}
