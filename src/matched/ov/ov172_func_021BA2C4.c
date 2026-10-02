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

extern u16  func_021BE00C(void *c);
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
extern void func_020498F4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_020409B4(u32 a);
extern void func_02040588(u32 a, u32 b);
extern u32  func_020275E4(void);
extern u32  func_0202762C(void);
extern void *func_020490F4(u32 id, u16 heap);
extern void func_020414EC(u32 a);
extern void func_02049990(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_020413B0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02040618(u32 a, u32 b, u32 c);
extern void func_02049238(void *a);
extern u32  func_0204B294(u32 a, u32 b, u32 c, u32 d, struct Desc *e, u32 f, u32 heap);
extern void func_0204B92C(u32 o, u32 k);
extern void func_0204B3DC(u32 o, u32 k);
extern void *func_020450F0(int a, u8 b, int c, int d, u8 e, u8 f, u8 g);
extern u32  func_02045770(void *w);
extern void func_02043B5C(u32 a, u32 b);
extern void *func_02045EC0(void *bank, u32 index);
extern void func_0201C724(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02045808(void *s);
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
    func_020498F4(func_021BE010(a0), 0x10, 7, 0, 0, 0, v);
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
    *(u32 *)(p + 0x58) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x38;
    d.z = 0x3;
    *(u32 *)(p + 0x5c) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x60;
    d.z = 0x5;
    *(u32 *)(p + 0x60) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0x88;
    d.z = 0x7;
    *(u32 *)(p + 0x64) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xc8;
    if (func_021BE0B4(a0) == 1) {
        d.z = 0xc;
    } else {
        d.z = 0xa;
    }
    *(u32 *)(p + 0x68) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    d.x = 0xe0;
    d.y = 0xc0;
    d.z = 0x1;
    *(u32 *)(p + 0x6c) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 7), func_021BE018(a0, 3), func_021BE018(a0, 10), &d, 0, v);
    func_0204B92C(*(u32 *)(p + 0x6c), 1);
    for (i = 0; i < 6; i++) {
        func_0204B3DC(*(u32 *)(p + i * 4 + 0x58), 1);
    }
    d.x = 0x38;
    d.y = 0x48;
    d.z = 0xe;
    *(u32 *)(p + 0x70) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x5c;
    d.z = 0xf;
    *(u32 *)(p + 0x74) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x70;
    d.z = 0x10;
    *(u32 *)(p + 0x78) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.y = 0x84;
    d.z = 0x11;
    *(u32 *)(p + 0x7c) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 5), func_021BE018(a0, 1), func_021BE018(a0, 9), &d, 1, v);
    d.x = 0x2c;
    d.y = 0x8c;
    d.z = 0x1;
    *(u32 *)(p + 0x80) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 6), func_021BE018(a0, 2), func_021BE018(a0, 10), &d, 1, v);
    for (i = 0; i < 5; i++) {
        func_0204B3DC(*(u32 *)(p + i * 4 + 0x70), 0);
    }
    d.x = 0x10;
    d.y = 0xa0;
    d.z = 0xf;
    *(u32 *)(p + 0x84) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC(*(u32 *)(p + 0x84), 0);
    d.x = 0x88;
    d.y = 0xa0;
    d.z = 0x10;
    *(u32 *)(p + 0x88) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC(*(u32 *)(p + 0x88), 0);
    d.a = 0;
    *(u32 *)(p + 0x8c) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC(*(u32 *)(p + 0x8c), 0);
    d.z = 0x19;
    d.a = 2;
    *(u32 *)(p + 0x90) = func_0204B294(func_021BE024(a0), func_021BE018(a0, 4), func_021BE018(a0, 0), func_021BE018(a0, 8), &d, 0, v);
    func_0204B3DC(*(u32 *)(p + 0x90), 0);
    func_021BB54C(a0, p);
    *(u32 *)(p + 0x48) = 0;
    *(u32 *)(p + 0x50) = 0;
    t1 = func_021BE034(a0);
    s = (void *)func_021BE03C(a0);
    t3 = func_021BE044(a0);
    *(u32 *)(p + 0x4c) = (u32)func_020450F0(4, 3, 1, 0x1c, 2, 0xa, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x4c)), 0);
    s = func_02045EC0(s, 0xb);
    func_0201C724(t3, func_02045770(*(void **)(p + 0x4c)), 1, 0, (u32)s, t1, 0x440);
    func_02045808(s);
    *(u32 *)(p + 0x40) = 1;
    *(u32 *)p = 0;
    p[4] = 0x18;
    p[5] = 0x18;
    *(u16 *)(p + 0x96) = 0;
    *(u32 *)(p + 0xc) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x44) = 0;
    *(u32 *)(p + 0x18) = 0;
    *(u32 *)(p + 0x1c) = 0;
    *(u32 *)(p + 0x20) = 0;
    *(volatile u16 *)0x0500021A = *(u16 *)(p + 0x34) & 0x7fff;
    func_021BB65C(a0, p, 0);
    func_0203D34C(1, v);
    func_021BE2E0(a0);
}
