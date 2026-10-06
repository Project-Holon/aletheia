/*
 * unit:     yes
 * address:  0x02012924
 * packet:   pkt_02012924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02012924, func_0201292C, func_02012934, func_0201293C,
 *           func_02012944, func_02012950, func_0201295C, func_02012964,
 *           func_0201296C, func_02012974, func_0201297C, func_02012984,
 *           func_0201298C, func_02012994, func_020129A0, func_020129AC,
 *           func_020129B8, func_020129C4, func_020129D0, func_020129DC,
 *           func_020129F0, func_020129FC, func_02012A24, func_02012A30,
 *           func_02012A38, func_02012A44, func_02012A4C, func_02012A54,
 *           func_02012A60, func_02012A90, func_02012AA0, func_02012AA4,
 *           func_02012AB8, func_02012ABC, func_02012AC0, func_02012AC4,
 *           func_02012AC8, func_02012ACC, func_02012AD0
 *
 * symbols:
 *   func_020127A4         0x020127A4  thumb
 *
 * 432 bytes, 0x02012924..0x02012AD4, 39 functions, only nine of which carry a
 * label in the generated listing: the rest are leaf accessors that save no lr
 * and arrive in asm/arm9/src/004_02010BB8.s as runs of .word, which is
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * Two objects are accessed here and they are not the same struct.
 *
 *  - BigObj is reached through a plain pointer argument and every field this
 *    file touches is past +0x18C, so each access is a register offset built
 *    with movs/lsls (0x63 << 2 is +0x18C) or, where the constant is not of
 *    that shape, out of the function's own literal pool (+0x1C5 .. +0x1CD).
 *    Those pool words are plain constants and carry no relocation.
 *  - Rec44 is the 0x44-byte record func_02012950 indexes, and func_02012A60
 *    onwards are its constructor and accessors.  func_02012A60 is the
 *    constructor: its store order is the source's statement order, and the
 *    two strb at +0x12 and +0x13 next to the strh at +0x10, +0x14 and +0x16
 *    are what make +0x10 a union of a four-halfword view (the one
 *    func_02012AA4 copies whole) and a five-field view.
 *
 * func_020129FC is a post-increment and not an assignment:
 * `return p->unk1C8++;` spends an extra `adds r1, r4, #0` copy that
 * `n = p->unk1C8; p->unk1C8 = n + 1; return n;` does not, and the two are
 * otherwise the same eighteen instructions.  See
 * docs/idioms/post-increment-of-a-field-spends-a-copy.md.
 *
 * The file stops at 0x02012AD4 because func_02012AD4 cannot be attested; see
 * the header of src/matched/unit_02012AE4.c for that near miss.
 *
 * Addresses are Black-image addresses.  Nothing here reads a version flag or
 * a species table, so none of it looks version specific.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012924.c \
 *       --addr 0x02012924 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *func_020127A4(void *p);

struct Vec12 {
    u32 x;
    u32 y;
    u32 z;
};

struct H4 {
    u16 v[4];
};

union U10 {
    struct H4 all;
    struct {
        u16 a;
        u8  b;
        u8  c;
        u16 d;
        u16 e;
    } f;
};

struct Rec44 {
    u16 unk00;
    u16 unk02;
    struct Vec12 unk04;
    union U10 unk10;
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u8  unk1E[0x12];
    u32 unk30;
    u8  unk34[6];
    u8  unk3A;
    u8  unk3B;
    u8  unk3C;
    u8  unk3D;
    u8  unk3E[2];
    u32 unk40;
};

struct Sub24 {
    u8 unk00[0x24];
    struct Rec44 unk24[8];
};

struct BigObj {
    u8  unk000[0x18C];
    u32 unk18C;
    void *unk190;
    void *unk194;
    u32 unk198;
    u32 unk19C;
    u32 unk1A0;
    u32 unk1A4;
    u32 unk1A8;
    u32 unk1AC;
    u32 unk1B0;
    u32 unk1B4;
    u32 unk1B8;
    u32 unk1BC;
    u8  unk1C0[4];
    u8  unk1C4;
    u8  unk1C5;
    u8  unk1C6;
    u8  unk1C7;
    u8  unk1C8;
    u8  unk1C9;
    u8  unk1CA;
    u8  unk1CB;
    u8  unk1CC;
    u8  unk1CD;
    u8  unk1CE;
    u8  unk1CF;
    u8  unk1D0[0x414];
    u32 unk5E4;
    u8  unk5E8[0xA4];
    u32 unk68C;
    u32 unk690;
};

u32 func_02012924(const struct BigObj *p)
{
    return p->unk18C;
}

void *func_0201292C(const struct BigObj *p)
{
    return p->unk190;
}

void *func_02012934(const struct BigObj *p)
{
    return p->unk194;
}

u32 func_0201293C(const struct BigObj *p)
{
    return p->unk19C;
}

u8 *func_02012944(void *p)
{
    return func_020127A4(p) + 0x20;
}

struct Rec44 *func_02012950(struct Sub24 *p, u32 i)
{
    return &p->unk24[i];
}

u32 func_0201295C(const struct BigObj *p)
{
    return p->unk1A4;
}

u32 func_02012964(const struct BigObj *p)
{
    return p->unk1A8;
}

u32 func_0201296C(const struct BigObj *p)
{
    return p->unk1AC;
}

u32 func_02012974(const struct BigObj *p)
{
    return p->unk1B0;
}

u32 func_0201297C(const struct BigObj *p)
{
    return p->unk690;
}

u8 func_02012984(const struct BigObj *p)
{
    return p->unk1C4;
}

void func_0201298C(struct BigObj *p, u8 v)
{
    p->unk1C4 = v;
}

u8 func_02012994(const struct BigObj *p)
{
    return p->unk1C5;
}

void func_020129A0(struct BigObj *p, u8 v)
{
    p->unk1C5 = v;
}

u8 func_020129AC(const struct BigObj *p)
{
    return p->unk1C6;
}

void func_020129B8(struct BigObj *p, u32 v)
{
    p->unk1C6 = v;
}

u8 func_020129C4(const struct BigObj *p)
{
    return p->unk1C7;
}

void func_020129D0(struct BigObj *p, u8 v)
{
    p->unk1C7 = v;
}

void func_020129DC(struct BigObj *p, u8 v)
{
    p->unk1C9 = v;
    if (v != 0) {
        p->unk1C8 = 0;
    }
}

void func_020129F0(struct BigObj *p)
{
    p->unk1C8 = 0;
}

u8 func_020129FC(struct BigObj *p)
{
    if (p->unk1C9 != 0) {
        return p->unk1C8++;
    }
    return 0;
}

u8 func_02012A24(const struct BigObj *p)
{
    return p->unk1C9;
}

u32 func_02012A30(const struct BigObj *p)
{
    return p->unk1B4;
}

u32 func_02012A38(const struct BigObj *p)
{
    return p->unk5E4;
}

u32 func_02012A44(const struct BigObj *p)
{
    return p->unk1BC;
}

void func_02012A4C(struct BigObj *p, u32 v)
{
    p->unk1BC = v;
}

u32 func_02012A54(const struct BigObj *p)
{
    return p->unk68C;
}

void func_02012A60(struct Rec44 *p)
{
    p->unk3D = 0;
    p->unk3A = 0;
    p->unk00 = 0;
    p->unk04.x = 0;
    p->unk04.y = 0;
    p->unk04.z = 0;
    p->unk18 = 0;
    p->unk1B = 0;
    p->unk30 = 0;
    p->unk10.f.b = 0;
    p->unk10.f.c = 0;
    p->unk10.f.a = 0;
    p->unk10.f.e = 0;
    p->unk10.f.d = 0;
    p->unk1C = 0xFFFF;
}

void func_02012A90(struct Rec44 *p, const struct Vec12 *src)
{
    p->unk04 = *src;
}

struct Vec12 *func_02012AA0(struct Rec44 *p)
{
    return &p->unk04;
}

void func_02012AA4(struct Rec44 *p, const struct H4 *src)
{
    p->unk10.all = *src;
}

struct H4 *func_02012AB8(struct Rec44 *p)
{
    return &p->unk10.all;
}

void func_02012ABC(struct Rec44 *p, u8 v)
{
    p->unk1B = v;
}

u8 func_02012AC0(const struct Rec44 *p)
{
    return p->unk1B;
}

void func_02012AC4(struct Rec44 *p, u16 v)
{
    p->unk00 = v;
}

u16 func_02012AC8(const struct Rec44 *p)
{
    return p->unk00;
}

void func_02012ACC(struct Rec44 *p, u16 v)
{
    p->unk18 = v;
}

u16 func_02012AD0(const struct Rec44 *p)
{
    return p->unk18;
}
