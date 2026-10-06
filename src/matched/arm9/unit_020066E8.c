/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020066E8
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020066E8, sub_02006734, sub_02006740, sub_0200674C,
 *           sub_02006768, sub_020067A4, sub_020067D0
 *
 * symbols:
 *   sub_02006544_State  0x02140484  data
 *   sub_020065D8        0x020065D8  thumb
 *   sub_02006948        0x02006948  thumb
 *   func_020307B0       0x020307B0  arm
 *   _s32_div_f          0x0209C0A4  arm
 *
 * The teardown, the master volume pair, the round robin picker and the two
 * entry reset routines.  Three of the seven carry no label, because they
 * save nothing: sub_02006734 and sub_02006740 are a two instruction setter
 * and its reset, and sub_020067D0 is two stores and a tail call through a
 * pool word into sub_020067A4, which is the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes.
 *
 * _s32_div_f, at 0x0209C0A4, is the signed 32 bit division helper, the
 * counterpart of the `_u32_div_f` at 0x0209C2B0 that
 * docs/idioms/runtime-helper-reloc.md records.  sub_0200674C scales a u8 by
 * the master volume and both operands promote to `int`, so the signed
 * helper is what that source shape produces; nothing in the C names it.
 *
 * Why this range starts here and not one function earlier: sub_020065D8 is
 * called from exactly two places in the whole image, 0x0200667C inside
 * sub_02006674 and 0x020066EA inside sub_020066E8.  Put both in one range
 * and the honesty rule discards both witnesses and the site is unresolved;
 * cut between them, as src/matched/unit_020065D8.c and this file do, and
 * each call is the other's outside witness.  See
 * docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md.
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

struct Sub02006544State {
    u16 unk00;
    u16 unk02;
    struct Sub02006544Entry entries[3];
    u16 cur;
    u16 count;
    u32 unkA4;
    u32 unkA8;
    u8  unkAC;
};

extern struct Sub02006544State sub_02006544_State;

extern void sub_020065D8(void);
struct Sub02006948;
extern void sub_02006948(struct Sub02006948 *e);
extern u32 func_020307B0(void *p);

void sub_020067A4(struct Sub02006544Entry *e);
void sub_020067D0(struct Sub02006544Entry *e);

void sub_020066E8(void)
{
    struct Sub02006544Entry *e;
    int i;

    sub_020065D8();
    for (i = 0; i < sub_02006544_State.count; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk04 != 0 && e->unk30 == 1) {
            func_020307B0(e->unk04);
            sub_020067D0(e);
        }
    }
    sub_02006544_State.count = 1;
    sub_02006544_State.cur = 0;
}

void sub_02006734(u8 volume)
{
    sub_02006544_State.unkAC = volume;
}

void sub_02006740(void)
{
    sub_02006544_State.unkAC = 0x7F;
}

u8 sub_0200674C(u8 volume)
{
    return (u8)(volume * sub_02006544_State.unkAC / 0x7F);
}

u16 sub_02006768(void)
{
    struct Sub02006544Entry *e;
    u16 cur;

    cur = sub_02006544_State.cur;
    e = &sub_02006544_State.entries[cur];
    if (e->unk00 == 1) {
        sub_02006948((struct Sub02006948 *)e);
    }
    if (sub_02006544_State.cur < sub_02006544_State.count - 1) {
        sub_02006544_State.cur = sub_02006544_State.cur + 1;
    } else {
        sub_02006544_State.cur = 0;
    }
    return cur;
}

void sub_020067A4(struct Sub02006544Entry *e)
{
    e->unk08 = 0;
    e->unk1C = 0;
    e->unk1D = 0;
    e->unk24 = 0;
    e->unk0C = 0x3443;
    e->unk20 = 0x64E1;
    e->unk28 = 0x40;
    e->unk2C = 0;
    e->unk10 = e->unk04;
}

void sub_020067D0(struct Sub02006544Entry *e)
{
    e->unk04 = 0;
    e->unk30 = 0;
    sub_020067A4(e);
}
