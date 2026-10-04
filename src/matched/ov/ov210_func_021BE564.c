/*
 * function: func_021BE564
 * address:  0x021BE564
 * packet:   pkt_ov210_021BE564
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BE49C 0x021BE49C thumb ov210
 *   func_021BE7E4 0x021BE7E4 thumb ov210
 *   func_021BE44C 0x021BE44C thumb ov210
 *   func_021BCF00 0x021BCF00 thumb ov210
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 */
#include "../include/Obj00222.h"
#include "../include/Obj25617.h"
#include "../include/Obj25618.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021BE49C(u8 *p);
extern void func_021BE7E4(u8 *p);
extern void func_021BE44C(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
struct CharBuf;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern u16 func_021BCF00(int a0, int a1);
extern void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

static inline u8 *Bytes021BE564(u8 *p)
{
    return *(u8 * *)&((struct Obj25618 *)(*(u8 * *)&((struct Obj25617 *)p)->f0))->f8;
}

void func_021BE564(u8 *p)
{
    u32 v;
    u32 s1;
    u32 s2;
    u32 s3;
    u8 w;
    u8 x;

    func_021BE49C(p + 0x14C);
    func_021BE49C(p + 0x15C);
    func_021BE49C(p + 0x164);
    func_021BE49C(p + 0x16C);
    func_021BE49C(p + 0x174);
    func_021BE49C(p + 0x17C);
    func_021BE49C(p + 0x1A4);
    func_021BE7E4(p);

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f184)), 0);
    func_021BE44C(p, 7, Bytes021BE564(p)[1] + 0x19, 0x28, 4, 0x3C40, 2);
    func_021BE49C(p + 0x184);

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f18C)), 0);
    v = Bytes021BE564(p)[2];
    if (v == 0xFF)
        func_021BE44C(p, 8, 0x5F, 8, 4, 0x3C40, 2);
    else
        func_021BE44C(p, 8, v + 0x33, 8, 4, 0x3C40, 2);
    func_021BE49C(p + 0x18C);

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f194)), 0);
    if (Bytes021BE564(p)[3] == 0xFF) {
        func_021BE44C(p, 9, 0x30, 0x40, 4, 0x3C40, 2);
    } else if (Bytes021BE564(p)[4] == 0xFF) {
        func_021BE44C(p, 9, func_021BCF00((int)p, Bytes021BE564(p)[3]), 0x40, 4, 0x3C40, 2);
    } else {
        s1 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00222 *)p)->f1D0), 0x31);
        func_021B6AE4(p + 0x194, ((struct Obj00222 *)p)->f1DC, 0x42, 4, s1, ((struct Obj00222 *)p)->f1CC, 0x3C40, 2);
        w = func_0201D304((struct StrObj *)s1, ((struct Obj00222 *)p)->f1CC, 0);
        func_02045808((struct U16Vec *)s1);
        x = 0x40 - (u8)(w / 2);
        s2 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00222 *)p)->f1D0), func_021BCF00((int)p, Bytes021BE564(p)[3]));
        func_021B6AE4(p + 0x194, ((struct Obj00222 *)p)->f1DC, x + 2, 4, s2, ((struct Obj00222 *)p)->f1CC, 0x3C40, 1);
        func_02045808((struct U16Vec *)s2);
        x += w;
        s3 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)&((struct Obj00222 *)p)->f1D0), func_021BCF00((int)p, Bytes021BE564(p)[4]));
        func_021B6AE4(p + 0x194, ((struct Obj00222 *)p)->f1DC, x + 2, 4, s3, ((struct Obj00222 *)p)->f1CC, 0x3C40, 0);
        func_02045808((struct U16Vec *)s3);
    }
    func_021BE49C(p + 0x194);

    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj00222 *)p)->f19C)), 0);
    v = Bytes021BE564(p)[5];
    if (v == 0xFF)
        func_021BE44C(p, 10, 0x6A, 0x28, 4, 0x3C40, 2);
    else
        func_021BE44C(p, 10, v + 0x60, 0x28, 4, 0x3C40, 2);
    func_021BE49C(p + 0x19C);
}
