/*
 * function: func_0200EC2C
 * address:  0x0200EC2C
 * packet:   pkt_0200EA3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_SetStringN  0x02045994  arm
 *
 * One record of a 0x3c-byte table copied into a destination object.
 *
 * This closes the 76-byte residue that docs/notes/pkt_0200EA3C.c.txt
 * section 2 recorded.  Three spellings had to hold at once:
 *
 *  1. the byte at source +3 is a `u8 :6 / u8 :2` bitfield PAIR, not a plain
 *     u8.  The source side is what produces the `lsls #26 / lsrs #26` pair
 *     the note could not reach; reading it as a plain u8 and shifting gives
 *     `ands` instead and compiles 104 bytes.
 *  2. the destination byte at +0x13 is the same bitfield pair.  That is what
 *     turns the insert into `movs r1, #0x3f; ands r1, r3` rather than a
 *     single immediate mask.  Both sides are needed: either one alone is
 *     still wrong.
 *  3. the source pointer must be `const`.  Without it, the store to
 *     dst->f13a may alias s->f03a, so mwcc reloads `ldrb [r4, #3]` a second
 *     time for the `:2` field, two bytes over at 110.  The original loads it
 *     once into r2 and keeps it live across the first insert.  See
 *     docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md.
 *
 * EXACT* : the inferred extent ran to 0x0200ECF0 because the accessor at
 * 0x0200EC98 saves no lr and so carries no label.  0x0200EC98 is an
 * unlabelled follower and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200EC2C.c \
 *       --func func_0200EC2C --addr 0x0200EC2C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bits {
    u8 a : 6;
    u8 b : 2;
};

struct Src0200EC2C {
    u16 f00;
    u8  f02;
    u8  f03a : 6;
    u8  f03b : 2;
    u32 f04;
    u32 f08;
    u8  f0C[0x16];
    u8  f22[0x10];
    u16 f32[4];
};

struct Dst0200EC2C {
    void *p00;
    void *p04;
    u32   f08;
    u32   f0C;
    u16   f10;
    u8    f12;
    u8    f13a : 6;
    u8    f13b : 2;
    u16   f14[4];
};

struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);

void func_0200EC2C(const struct Src0200EC2C *base, int idx, struct Dst0200EC2C *dst)
{
    const struct Src0200EC2C *s = base + idx;
    int i;

    dst->f10 = s->f00;
    dst->f12 = s->f02;
    dst->f08 = s->f04;
    dst->f0C = s->f08;
    dst->f13a = s->f03a;
    dst->f13b = s->f03b;

    STRBUF_SetStringN(dst->p00, (const u16 *)s->f0C, 0xb);
    STRBUF_SetStringN(dst->p04, (const u16 *)s->f22, 8);

    for (i = 0; i < 4; i++)
        dst->f14[i] = s->f32[i];
}
