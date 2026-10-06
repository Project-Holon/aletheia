/*
 * unit:     yes
 * address:  0x02012AE4
 * packet:   pkt_02012924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02012AE4, func_02012B28, func_02012B2C, func_02012B30,
 *           func_02012B34, func_02012B38, func_02012B40, func_02012B4C,
 *           func_02012B58, func_02012B64, func_02012B70, func_02012B78,
 *           func_02012B80, func_02012B8C, func_02012B98, func_02012BA4,
 *           func_02012BB0
 *
 * symbols:
 *   func_02008448  0x02008448  thumb
 *
 * 228 bytes, 0x02012AE4..0x02012BC8, 17 functions, the continuation of
 * src/matched/unit_02012924.c across two near misses.  The same two objects:
 * Rec44 for func_02012AE4 .. func_02012B34 and BigObj from func_02012B38 on.
 *
 * func_02012AE4 buckets the Rec44 field at +0x18 into 0, 1, 2 or 3.  The
 * result local has to be declared **before** the field is read into its own
 * local, or the compiler puts the result in r0, keeps its scratch in r1 and
 * duplicates `bx lr` into every arm instead of branching to one
 * `adds r0, r1, #0; bx lr` tail; that spelling is 28 concrete bytes wrong and
 * two bytes short with identical control flow.  Seven source shapes were
 * compiled and only the two with the result declared first are EXACT.
 *
 * Two near misses bracket this file, and neither is a codegen failure: both
 * reproduce every concrete byte and are held at MATCH by the honesty rule.
 *
 *  - 0x02012AD4, 16 bytes, `p->unk18 = Table[i];` over a u16 table at
 *    0x0209DFA8.  That address appears in exactly one literal pool in the
 *    image, the one inside this function, so the `literal` class discards its
 *    only witness and no cut helps.  It is data, so no label will ever exist
 *    for it.  The source is
 *
 *        void func_02012AD4(struct Rec44 *p, u32 i)
 *        {
 *            p->unk18 = func_02012AD4_Table[i];
 *        }
 *
 *    with `func_02012AD4_Table 0x0209DFA8 data`.  Evidence class: literal, 0
 *    witnesses outside.
 *  - 0x02012BC8, 24 bytes, a tail call through a pool word holding
 *    0x02008451.  0x02008450 is a real Thumb function (the setter whose
 *    getter is the labelled func_02008448 four bytes earlier) but it opens
 *    with no register-saving prologue, so disasm.py never labelled it, and
 *    this pool word is the only reference to it anywhere in the image.  The
 *    source is
 *
 *        void func_02012BC8(struct BigObj *p, u32 v)
 *        {
 *            func_02008450(p->unk198, v != 0);
 *        }
 *
 *    Evidence class: literal, 0 witnesses outside.  It closes the day
 *    0x02008450 goes into layout/function_starts.txt with a branch that
 *    attests it, which this file cannot provide because it is the only user.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012AE4.c \
 *       --addr 0x02012AE4 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern unsigned int func_02008448(int a0);

struct Rec44 {
    u8  unk00[0x18];
    u16 unk18;
    u8  unk1A;
    u8  unk1B;
    u16 unk1C;
    u8  unk1E[0x22];
    u32 unk40;
};

struct BigObj {
    u8  unk000[0x198];
    void *unk198;
    u8  unk19C[0x1C];
    void *unk1B8;
    u8  unk1BC[0xC];
    u8  unk1C8;
    u8  unk1C9;
    u8  unk1CA;
    u8  unk1CB;
    u8  unk1CC;
    u8  unk1CD;
    u8  unk1CE;
    u8  unk1CF;
    u8  unk1D0[0x414];
};

u32 func_02012AE4(const struct Rec44 *p)
{
    u32 r = 0;
    u16 v = p->unk18;

    if (v > 0x2000 && v < 0x6000) {
        r = 2;
    } else if (v >= 0x6000 && v <= 0xA000) {
        r = 1;
    } else if (v > 0xA000 && v < 0xE000) {
        r = 3;
    }
    return r;
}

u32 func_02012B28(const struct Rec44 *p)
{
    return p->unk40;
}

void func_02012B2C(struct Rec44 *p, u32 v)
{
    p->unk40 = v;
}

void func_02012B30(struct Rec44 *p, u16 v)
{
    p->unk1C = v;
}

u16 func_02012B34(const struct Rec44 *p)
{
    return p->unk1C;
}

void *func_02012B38(const struct BigObj *p)
{
    return p->unk1B8;
}

u8 func_02012B40(const struct BigObj *p)
{
    return p->unk1CA;
}

void func_02012B4C(struct BigObj *p, u8 v)
{
    p->unk1CA = v;
}

u8 func_02012B58(const struct BigObj *p)
{
    return p->unk1CB;
}

void func_02012B64(struct BigObj *p, u8 v)
{
    p->unk1CB = v;
}

int func_02012B70(const struct BigObj *p)
{
    return p->unk1CC;
}

void func_02012B78(struct BigObj *p, u8 v)
{
    p->unk1CC = v;
}

u8 func_02012B80(const struct BigObj *p)
{
    return p->unk1CD;
}

void func_02012B8C(struct BigObj *p, u32 v)
{
    p->unk1CD = v;
}

u8 func_02012B98(const struct BigObj *p, u32 i)
{
    return p->unk1D0[i];
}

void func_02012BA4(struct BigObj *p, int i, u8 v)
{
    p->unk1D0[i] = v;
}

u32 func_02012BB0(const struct BigObj *p)
{
    if (func_02008448((int)p->unk198) == 1) {
        return 1;
    }
    return 0;
}
