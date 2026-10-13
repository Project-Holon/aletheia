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
 * function: PM_VOICE_FreeBuffers, PM_VOICE_SetMasterVolume, PM_VOICE_ResetMasterVolume, PM_VOICE_ScaleVolume,
 *           PM_VOICE_NextSlot, PM_VOICE_ResetParams, PM_VOICE_ClearSlot
 *
 * symbols:
 *   sub_02006544_State  0x02140484  data
 *   PM_VOICE_StopAll        0x020065D8  thumb
 *   PM_VOICE_Stop        0x02006948  thumb
 *   func_020307B0       0x020307B0  arm
 *   _s32_div_f          0x0209C0A4  arm
 *
 * The teardown, the master volume pair, the round robin picker and the two
 * entry reset routines.  Three of the seven carry no label, because they
 * save nothing: PM_VOICE_SetMasterVolume and PM_VOICE_ResetMasterVolume are a two instruction setter
 * and its reset, and PM_VOICE_ClearSlot is two stores and a tail call through a
 * pool word into PM_VOICE_ResetParams, which is the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes.
 *
 * _s32_div_f, at 0x0209C0A4, is the signed 32 bit division helper, the
 * counterpart of the `_u32_div_f` at 0x0209C2B0 that
 * docs/idioms/runtime-helper-reloc.md records.  PM_VOICE_ScaleVolume scales a u8 by
 * the master volume and both operands promote to `int`, so the signed
 * helper is what that source shape produces; nothing in the C names it.
 *
 * Why this range starts here and not one function earlier: PM_VOICE_StopAll is
 * called from exactly two places in the whole image, 0x0200667C inside
 * PM_VOICE_AllocBuffers and 0x020066EA inside PM_VOICE_FreeBuffers.  Put both in one range
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

extern void PM_VOICE_StopAll(void);
struct Sub02006948;
extern void PM_VOICE_Stop(struct Sub02006948 *e);
extern u32 func_020307B0(void *p);

void PM_VOICE_ResetParams(struct Sub02006544Entry *e);
void PM_VOICE_ClearSlot(struct Sub02006544Entry *e);

void PM_VOICE_FreeBuffers(void)
{
    struct Sub02006544Entry *e;
    int i;

    PM_VOICE_StopAll();
    for (i = 0; i < sub_02006544_State.count; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk04 != 0 && e->unk30 == 1) {
            func_020307B0(e->unk04);
            PM_VOICE_ClearSlot(e);
        }
    }
    sub_02006544_State.count = 1;
    sub_02006544_State.cur = 0;
}

void PM_VOICE_SetMasterVolume(u8 volume)
{
    sub_02006544_State.unkAC = volume;
}

void PM_VOICE_ResetMasterVolume(void)
{
    sub_02006544_State.unkAC = 0x7F;
}

u8 PM_VOICE_ScaleVolume(u8 volume)
{
    return (u8)(volume * sub_02006544_State.unkAC / 0x7F);
}

u16 PM_VOICE_NextSlot(void)
{
    struct Sub02006544Entry *e;
    u16 cur;

    cur = sub_02006544_State.cur;
    e = &sub_02006544_State.entries[cur];
    if (e->unk00 == 1) {
        PM_VOICE_Stop((struct Sub02006948 *)e);
    }
    if (sub_02006544_State.cur < sub_02006544_State.count - 1) {
        sub_02006544_State.cur = sub_02006544_State.cur + 1;
    } else {
        sub_02006544_State.cur = 0;
    }
    return cur;
}

void PM_VOICE_ResetParams(struct Sub02006544Entry *e)
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

void PM_VOICE_ClearSlot(struct Sub02006544Entry *e)
{
    e->unk04 = 0;
    e->unk30 = 0;
    PM_VOICE_ResetParams(e);
}
