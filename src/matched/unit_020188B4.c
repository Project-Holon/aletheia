/*
 * unit:     yes
 * address:  0x020188B4
 * packet:   pkt_0201854C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_020188B4, func_020188E0, func_0201891C, func_02018948,
 *           func_0201897C
 *
 * symbols:
 *   func_02017E1C        0x02017E1C  thumb
 *   func_02017E88        0x02017E88  thumb
 *   func_02018D10        0x02018D10  thumb
 *   func_02018D6C        0x02018D6C  thumb
 *   func_02019C38        0x02019C38  thumb
 *   func_02019C90        0x02019C90  thumb
 *
 * The three functions at 0x020189D0, 0x020189D8 and 0x020189F0 sit between
 * this file and src/matched/unit_02018A00.c and are a documented near miss:
 * every concrete byte of them is reproduced, but func_020189F0 loads the
 * s8[][5] table at 0x0209E2A4 and the only word in the image that holds that
 * address is the pool word under test, so no cut attests it.  See
 * docs/idioms/a-string-after-a-data-table-has-no-witness.md for the same
 * shape on a string.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef unsigned long long u64;

extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern u32  func_02018D10(void *p);
extern void func_02018D6C(void *p);
extern void *func_02019C38(void *p, u32 h, u32 i);
extern u32  func_02019C90(u16 a, u16 b, u32 i);

struct Hdr {
    u32 unk00;
};

struct RecA {
    u8  unk00[0x1C];
    u32 unk1C;
};

struct RecB {
    u8  unk00[0x14];
    u32 unk14;
};

struct RecC {
    u8  unk00[0x18];
    u64 unk18;
};

u32 func_020188E0(u16 a, u16 b, s32 v);
u32 func_02018948(u16 a, u16 b, s32 v);

u32 func_020188B4(void *p, s32 v)
{
    u16 a = (u16)func_02017E88(p, 5, 0);
    u16 b = (u16)func_02017E88(p, 0x6F, 0);

    return func_020188E0(a, b, v);
}

u32 func_020188E0(u16 a, u16 b, s32 v)
{
    u32 r;

    if (a == 0x28A) {
        r = 0;
    } else if (func_02019C90(a, b, v / 32 + 0x27) & (1 << (v % 32))) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 func_0201891C(void *p, s32 v)
{
    u16 a = (u16)func_02017E1C(p, 5, 0);
    u16 b = (u16)func_02017E1C(p, 0x6F, 0);

    return func_02018948(a, b, v);
}

u32 func_02018948(u16 a, u16 b, s32 v)
{
    u32 r;

    if (a == 0x28A) {
        r = 0;
    } else if (func_02019C90(a, b, 0x2B) & (1 << (v % 32))) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 func_0201897C(struct Hdr *p)
{
    u32 r;
    struct RecA *a;
    struct RecB *b;
    struct RecC *c;

    func_02018D10(p);
    r = 0;
    a = func_02019C38(p, p->unk00, 0);
    b = func_02019C38(p, p->unk00, 1);
    c = func_02019C38(p, p->unk00, 2);
    if (a->unk1C != 0 || b->unk14 != 0 || c->unk18 != 0) {
        r = 1;
    }
    func_02018D6C(p);
    return r;
}
