/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020067E0
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020067E0, sub_02006868
 *
 * symbols:
 *   sub_0200674C   0x0200674C  thumb
 *   func_02072A44  0x02072A44  arm
 *   func_02072AA0  0x02072AA0  arm
 *   func_02074450  0x02074450  arm
 *   func_0207457C  0x0207457C  arm
 *   func_020745A4  0x020745A4  arm
 *   func_0208A638  0x0208A638  arm
 *   _ll_udiv       0x0209C00C  arm
 *
 * The loader and the player.  sub_020067E0 resolves an id to a resource,
 * reads the header at the end of the loaded block and fills in the entry's
 * four playback fields; sub_02006868 opens one or two channels for the
 * entry and marks it running.
 *
 * Three things in here are worth keeping.
 *
 * The first word of the object func_02074450 returns is read with a
 * `lsls #8` / `lsrs #8` pair, which is a 24 bit unsigned bitfield and not a
 * mask; src/matched/unit_020064B8.c matched the same object through the
 * same entry point and
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md is the
 * finding.
 *
 * The byte at +0x1E of an entry is two four bit unsigned bitfields, not one
 * value: sub_02006868 reads it twice, once as `lsls #0x1C` / `lsrs #0x1C`
 * and once as `lsls #0x18` / `lsrs #0x1C`, and passes each to
 * func_02072A44.  The same byte is written in sub_02006544 with a
 * `bics`/`orrs` pair against 0x0F and against 0xF0.  The first declared
 * field is the low nibble, so this front end allocates a `u8` bitfield from
 * the least significant end.
 *
 * The pair of `blx 0x0209C00C` with `asrs r3, r2, #0x1f` in front of each is
 * one 64 bit division chained twice, not two 32 bit ones: the helper takes
 * the dividend in r0:r1 and returns it in r0:r1, so the second call consumes
 * the first call's result.  The constant it starts from is
 * 0x7FD87F8000, which is 16756991 * 0x8000, and 16756991 is half the DS
 * system clock; only its low word is in a literal pool, because the high
 * word 0x7F fits a `movs`.  The `asrs` is the sign extension of an `int`
 * operand to the 64 bit type of the dividend, which is what a `u16` field
 * promoted to `int` and then converted costs.
 *
 * The two functions of this range are separated from the two before them
 * and from sub_02006948 after them by what the evidence allows rather than
 * by taste.  sub_020067A4's only branch in the image is the `bl` at
 * 0x0200697C inside sub_02006948, so a range holding both has no witness for
 * it; ending this range at 0x02006948 leaves the pool word at 0x020067DC,
 * which is the other kind of witness for the same address, outside it.
 *
 * The near miss immediately after this range is sub_02006948,
 * 0x02006948..0x02006984, 60 bytes.  Evidence class `label`, witness census
 * 2 image wide and 2 inside the range, for each of three separate targets:
 * func_02072BDC is branched to from 0x0200694E and 0x02006966, func_02072D20
 * from 0x02006954 and 0x0200696C, and func_02072A88 from 0x0200695A and
 * 0x02006972, and every one of those six sites is inside sub_02006948
 * itself.  ov172 holds the words 0x02072A88 and 0x02072BDC in its own
 * literal pools, but overlay pool words are deliberately not admitted to
 * the `literal` class, and nothing anywhere branches to those three
 * addresses from outside this one function.  No cut helps, because the
 * witnesses are the calls the function has to make.  Each closes the day a
 * second caller appears.
 */

typedef unsigned char      u8;
typedef signed char        s8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

struct Sub02006544Entry {
    u32   unk00;
    void *unk04;
    u32   unk08;
    u32   unk0C;
    void *unk10;
    u32   unk14;
    u32   unk18;
    s8    unk1C;
    s8    unk1D;
    u8    unk1E : 4;
    u8    unk1E_4 : 4;
    u8    unk1F;
    u32   unk20;
    u32   unk24;
    u8    unk28;
    u32   unk2C;
    u32   unk30;
};

struct Sub020067E0Head {
    u32 unk00 : 24;
    u32 unk03 : 8;
};

struct Sub020067E0Block {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u8  unk0C[0x30];
    u32 unk3C;
};

struct Sub020067E0Wave {
    u16 unk00;
    u16 unk02;
    u16 unk04;
};

extern u8   sub_0200674C(u8 volume);
extern u32  func_02072A44(u32 kind);
extern int  func_02072AA0(u32 channel, u32 a, void *data, u32 b, u32 c,
                          u32 length, u32 loop, u8 volume, u32 rate, u8 pan);
extern void *func_02074450(int index);
extern u32  func_0207457C(u32 group);
extern int func_020745A4(u32 idx, void *dst_buf, int total_len, u32 offset);
extern void *func_0208A638(char *p);

int sub_020067E0(struct Sub02006544Entry *e, u32 id)
{
    struct Sub020067E0Head *p;
    struct Sub020067E0Block *block;
    struct Sub020067E0Wave *wave;
    u32 handle;
    u32 size;
    int r;

    p = func_02074450(id);
    if (p == 0) {
        return 0;
    }
    handle = func_0207457C(p->unk00);
    if (handle == 0) {
        return 0;
    }
    r = func_020745A4(p->unk00, e->unk04, handle, 0);
    if (r == -1) {
        return 0;
    }
    if (r != handle) {
        return 0;
    }
    block = e->unk04;
    wave = (struct Sub020067E0Wave *)((u8 *)block + block->unk3C);
    func_0208A638((char *)block);
    size = block->unk08 - block->unk3C;
    e->unk10 = (u8 *)wave + 0xC;
    e->unk08 = size - 0xC;
    e->unk0C = wave->unk02;
    e->unk20 = (u32)(0x7FD87F8000ULL / wave->unk02 / wave->unk04);
    return 1;
}

int sub_02006868(struct Sub02006544Entry *e)
{
    int v;

    if (e->unk04 == 0) {
        return 0;
    }
    if (e->unk08 == 0) {
        return 0;
    }
    e->unk14 = func_02072A44(e->unk1E);
    if (e->unk14 == 0) {
        return 0;
    }
    if (func_02072AA0(e->unk14, 0, e->unk10, 0, 0, e->unk08, e->unk0C,
                      sub_0200674C(e->unk1C), e->unk20, e->unk28) == 0) {
        return 0;
    }
    if (e->unk2C == 1) {
        e->unk18 = func_02072A44(e->unk1E_4);
        if (e->unk18 == 0) {
            return 0;
        }
        v = e->unk1C + e->unk1D;
        if (v < 0) {
            v = 0;
        }
        if (v > 0x7F) {
            v = 0x7F;
        }
        if (func_02072AA0(e->unk18, 0, e->unk10, 0, 0, e->unk08, e->unk0C,
                          sub_0200674C((u8)v), e->unk20 + e->unk24,
                          e->unk28) == 0) {
            return 0;
        }
    }
    e->unk00 = 1;
    return 1;
}
