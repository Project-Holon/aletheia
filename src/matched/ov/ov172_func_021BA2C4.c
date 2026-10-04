/*
 * function: func_021BA2C4
 * address:  0x021BA2C4
 * packet:   pkt_ov172_021BA2C4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Scene constructor: loads the bank, builds fifteen sprite/button objects
 * from one descriptor, opens the text window and clears the state words.
 *
 * symbols:
 *   func_021BE00C  0x021BE00C  thumb  ov172
 *   func_021BE010  0x021BE010  thumb  ov172
 *   func_021BE018  0x021BE018  thumb  ov172
 *   func_021BE024  0x021BE024  thumb  ov172
 *   func_021BE034  0x021BE034  thumb  ov172
 *   func_021BE03C  0x021BE03C  thumb  ov172
 *   func_021BE044  0x021BE044  thumb  ov172
 *   func_021BE0B4  0x021BE0B4  thumb  ov172
 *   func_021BE2E0  0x021BE2E0  thumb  ov172
 *   func_021BB54C  0x021BB54C  thumb  ov172
 *   func_021BB65C  0x021BB65C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00276.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

struct MsgBank;
struct U16Vec;
extern u16 func_021BE00C(u16 *p);
extern u32  func_021BE010(void *c);
extern u32  func_021BE018(void *c, int i);
extern u32  func_021BE024(void *c);
extern u32  func_021BE034(void *c);
extern u32  func_021BE03C(void *c);
extern u32  func_021BE044(void *c);
extern u32  func_021BE0B4(void *c);
extern void func_021BE2E0(void *c);
extern void func_021BB54C(void *c, u8 *p);
extern void func_021BB65C(void *c, u8 *p, int k);
struct CharBuf;
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 a);
extern void func_02040588(u32 a, u32 b);
extern u32  func_020275E4(void);
extern u32  func_0202762C(void);
extern void *func_020490F4(u32 id, u16 heap);
extern void func_020414EC(u32 a);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void func_02049238(void *a);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
struct Obj;
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *o, unsigned int k);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *w);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045808(struct U16Vec *vec);
extern void func_0203D34C(u32 a, u32 b);

void func_021BA2C4(void *a0, u8 *p)
{
    struct Desc d;
    u16 v;
    u8 i;
    void *bank;
    void *s;
    u32 t1;
    u32 t3;

    v = func_021BE00C(a0);
    func_020498F4((void *)func_021BE010(a0), 0x10, 7, 0, 0, 0, v);
    func_020409B4(7);
    func_02040588(5, 0);
    {
        u32 t = *(volatile u16 *)0x04000304;
        *(volatile u16 *)0x04000304 = t & 0xFFFF7FFF;
    }
    bank = func_020490F4(func_020275E4(), v);
    func_020414EC(0);
    func_02049990(bank, func_0202762C(), 0, 0x60, 0, 0x600, 0, v);
    func_020413B0(0, 0, 0x15, 0x20, 3, 0);
    func_020409B4(0);
    func_02040618(0, 3, 0);
    func_02049238(bank);
    d.x = 0x10;
    d.y = 0xcc;
    d.z = 1;
    d.a = 8;
    d.b = 0;
    ((struct Obj00276 *)p)->f58 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x38;
    d.z = 0x3;
    ((struct Obj00276 *)p)->f5C = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x60;
    d.z = 0x5;
    ((struct Obj00276 *)p)->f60 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x88;
    d.z = 0x7;
    ((struct Obj00276 *)p)->f64 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xc8;
    if (func_021BE0B4(a0) == 1) {
        d.z = 0xc;
    } else {
        d.z = 0xa;
    }
    ((struct Obj00276 *)p)->f68 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xe0;
    d.y = 0xc0;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f6C = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 7), func_021BE018(a0, 3), func_021BE018(a0, 10), &d, 0, v);
    func_0204B92C((struct Obj *)((struct Obj00276 *)p)->f6C, 1);
    for (i = 0; i < 6; i++) {
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 1);
    }
    d.x = 0x38;
    d.y = 0x48;
    d.z = 0xe;
    ((struct Obj00276 *)p)->f70 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x5c;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f74 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x70;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f78 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x84;
    d.z = 0x11;
    ((struct Obj00276 *)p)->f7C = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.x = 0x2c;
    d.y = 0x8c;
    d.z = 0x1;
    ((struct Obj00276 *)p)->f80 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 6), func_021BE018(a0, 2), func_021BE018(a0, 10), &d, 1, v);
    for (i = 0; i < 5; i++) {
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x70), 0);
    }
    d.x = 0x10;
    d.y = 0xa0;
    d.z = 0xf;
    ((struct Obj00276 *)p)->f84 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f84, 0);
    d.x = 0x88;
    d.y = 0xa0;
    d.z = 0x10;
    ((struct Obj00276 *)p)->f88 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f88, 0);
    d.a = 0;
    ((struct Obj00276 *)p)->f8C = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f8C, 0);
    d.z = 0x19;
    d.a = 2;
    ((struct Obj00276 *)p)->f90 = (u32)func_0204B294((void *)func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC((struct Obj *)((struct Obj00276 *)p)->f90, 0);
    func_021BB54C(a0, p);
    ((struct Obj00276 *)p)->f48 = 0;
    ((struct Obj00276 *)p)->f50 = 0;
    t1 = func_021BE034(a0);
    s = (void *)func_021BE03C(a0);
    t3 = func_021BE044(a0);
    *(u32 *)&((struct Obj00276 *)p)->f4C = (u32)func_020450F0(4, 3, 1, 0x1c, 2, 0xa, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770(((struct Obj00276 *)p)->f4C)), 0);
    s = func_02045EC0(s, 0xb);
    func_0201C724(t3, (u32)func_02045770(((struct Obj00276 *)p)->f4C), 1, 0, (u32)s, t1, 0x440);
    func_02045808(s);
    ((struct Obj00276 *)p)->f40 = 1;
    ((struct Obj00276 *)p)->f0 = 0;
    p[4] = 0x18;
    p[5] = 0x18;
    ((struct Obj00276 *)p)->f96 = 0;
    ((struct Obj00276 *)p)->fC = 0;
    ((struct Obj00276 *)p)->f8 = 0;
    ((struct Obj00276 *)p)->f10 = 0;
    ((struct Obj00276 *)p)->f14 = 0;
    ((struct Obj00276 *)p)->f38 = 0;
    ((struct Obj00276 *)p)->f44 = 0;
    ((struct Obj00276 *)p)->f18 = 0;
    ((struct Obj00276 *)p)->f1C = 0;
    ((struct Obj00276 *)p)->f20 = 0;
    *(volatile u16 *)0x0500021A = ((struct Obj00276 *)p)->f34 & 0x7fff;
    func_021BB65C(a0, p, 0);
    func_0203D34C(1, v);
    func_021BE2E0(a0);
}
