/*
 * function: func_021A9154
 * address:  0x021A9154
 * packet:   pkt_ov021_021A9154
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904AC  0x021904AC  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B324  0x0204B324  arm
 *   func_0204B954  0x0204B954  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Item {
    int f00;
    int f04;
    int f08;
    u32 f0C;
    u32 f10;
    u8 f14;
    u8 f15;
    u8 pad16[2];
    u32 f18;
} Item;

typedef struct Src {
    int f00;
    u8 f04;
    u8 f05;
    u8 f06;
    u8 f07;
    u8 f08;
    u8 f09;
    u8 pad0A[2];
    u32 f0C;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
} Src;

typedef struct Obj {
    u16 f00;
    u16 f02;
    void *f04;
    u8 pad08[0x104 - 0x08];
    u32 f104;
    u8 pad108[0x11C - 0x108];
    u32 f11C;
    u8 pad120[0x12C - 0x120];
    u32 f12C;
} Obj;

typedef struct Hdr {
    u16 f00;
    u16 f02;
    u16 f04;
    u8 f06;
    u8 f07;
    u16 f08;
    u16 f0A;
    u32 f0C;
    u32 f10;
    u16 f14;
    u16 f16;
} Hdr;

extern void *func_02188C54(void *p);
extern u32 func_021904AC(u8 *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(int a);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(int, int);
extern void func_0201C724(u32 a, u32 bmp, u32 x, u32 y, u32 text, u32 f, u32 color);
extern u32 func_0204A6C8(u32 arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204AF28(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0204B324(u32 a, u32 b, u32 c, u32 d, Hdr *h, u32 f, u32 g);
extern void func_0204B954(u32, u32);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(u32, u16);
extern void func_0204B3DC(struct Obj *, unsigned int);

void func_021A9154(Obj *p, Item *it, const Src *s)
{
    Hdr h;
    u32 k;

    k = func_021904AC(func_02188C54(p->f04));
    it->f00 = 1;
    it->f08 = s->f00;
    it->f14 = s->f04;
    it->f15 = s->f05;
    it->f04 = func_020450F0(6, s->f06, s->f07, 8, 2, 0xD, 1);
    func_02045374(it->f04);
    func_02043B5C((int)func_02045770((struct Descriptor *)it->f04), 0);
    func_0201C724(p->f12C, (int)func_02045770((struct Descriptor *)it->f04), 2, 1, s->f0C, k, 0x440);
    if (s->f10 != 0) {
        it->f0C = func_0204A6C8(s->f10, s->f14, 0, 1, p->f00);
        it->f10 = func_0204AF28(s->f10, s->f18, s->f1C, p->f00);
        h.f00 = s->f08;
        h.f02 = s->f09;
        h.f04 = 0;
        h.f06 = 0;
        h.f07 = 0;
        h.f08 = 0;
        h.f0A = 0;
        h.f0C = 0x1000;
        h.f10 = 0x1000;
        h.f14 = 0;
        h.f16 = 2;
        it->f18 = func_0204B324(p->f11C, it->f0C, p->f104, it->f10, &h, 0, p->f00);
        func_0204B954(it->f18, 0x1000);
        func_0204B92C((struct Obj *)it->f18, 1);
        func_0204B878(it->f18, 0);
        if (it->f08 == 7)
            func_0204B3DC((struct Obj *)it->f18, 0);
        else
            func_0204B3DC((struct Obj *)it->f18, 1);
    } else {
        it->f18 = 0;
    }
}
