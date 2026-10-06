/*
 * function: func_021BC75C
 * address:  0x021BC75C
 * packet:   pkt_ov088_021BC75C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045334  0x02045334  arm
 *   func_02045C04  0x02045C04  arm
 *   func_021BC870  0x021BC870  thumb  ov088
 */
#include "../include/Obj06206.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;

struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045334(struct Descriptor *d);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021BC870(u8 *p);

#define W(o) (*(u32 *)(p + (o)))

void func_021BC75C(u8 *p)
{
    u32 arc;
    u32 s;
    u8 i;
    u8 *q;

    arc = (u32)func_02045B38(0, 2, 0xab, 0x39);
    p[0] = 0;
    W(0xc) = func_020450F0((int)5, (int)1, (u8)0x13, (int)0x1d, (int)4, (int)0, (int)1);
    func_02045374((struct Cfg *)W(0xc));
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)W(0xc))), 0xf);
    s = (u32)func_02045EC0((struct MsgBank *)arc, W(4));
    func_0201F73C((void *)W(0xc), 0, 1, 1);
    func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)W(0xc))), 2, 2, (void *)s, (void *)W(8));
    func_02045808((struct U16Vec *)s);
    func_02045334((struct Descriptor *)W(0xc));
    for (i = 0; i < 2; i++) {
        q = p + i * 4;
        ((struct Obj06206 *)q)->f10 = func_020450F0((int)1, (int)6, (u8)(i * 4 + 0xc), (int)0x14, (int)2, (int)0, (int)1);
        func_02045374((struct Cfg *)(((struct Obj06206 *)q)->f10));
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj06206 *)q)->f10)), 0xf);
        s = (u32)func_02045EC0((struct MsgBank *)arc, i + 5 + W(4) * 2);
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)((struct Obj06206 *)q)->f10)), 2, 2, (void *)s, (void *)W(8));
        func_02045808((struct U16Vec *)s);
        func_02045334((struct Descriptor *)((struct Obj06206 *)q)->f10);
    }
    func_02045C04((struct Rec *)arc);
    func_021BC870(p);
}
