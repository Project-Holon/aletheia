/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020065D8
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PM_VOICE_StopAll, PM_VOICE_StopFinished, PM_VOICE_IsAnyActive, PM_VOICE_AllocBuffers
 *
 * symbols:
 *   sub_02006544_State  0x02140484  data
 *   sub_02006674_File   0x020A7024  data
 *   PM_VOICE_Stop        0x02006948  thumb
 *   func_02030734       0x02030734  arm
 *   NNS_SndWaveOutIsPlaying       0x02072CC4  arm
 *
 * The four functions that walk the three element voice array.
 *
 * There is one object here, not five.  sub_02006544_State is a single
 * 0xB0 byte record at 0x02140484: a halfword, three 0x34 byte entries at
 * +0x04, and a tail of five scalars at +0xA0.  The tail is reached through
 * literal pool words holding 0x02140504 and 0x02140524, which are the same
 * symbol with the addends 0x80 and 0xA0, because the Thumb immediate cannot
 * reach 0xA0 bytes from the symbol itself.  Which addend the compiler picks
 * follows the reach of the access width: the base is the field offset with
 * the low bits of the reach masked off, 0x7F for a word, 0x3F for a
 * halfword, 0x1F for a byte, so the word and halfword group at +0xA0..+0xA8
 * shares the base 0x02140504 and the byte at +0xAC gets 0x02140524.
 * Reading each pool word as a separate object is the wrong conclusion and
 * costs the file its relocations.
 *
 * PM_VOICE_AllocBuffers passes 0x020A7024 to the debug allocator at 0x02030734 with
 * the line number 0x105, and the bytes at 0x020A7024 spell "pm_voice.c", so
 * this run is that file.  The string is named by one literal pool word in
 * the image and it is this function's own, so the `literal` class discards
 * its only witness; the `string` class carries it, because
 * "wb_sound_data.sdat" ends with its NUL at 0x020A7022 and one byte of
 * padding puts the next string at 0x020A7024 by construction.
 *
 * PM_VOICE_IsAnyActive carries no label in the generated listing, because it saves
 * nothing: it is four instructions of loop, an early `return 1` and a
 * `return 0`, and `disasm.py` prints it as a run of `.word`s.  It is also
 * the reason this range and the next one can be matched at all.  The pool
 * word at 0x02006670 is one of the only two in the image that hold
 * 0x02140484, the other being 0x020065C0 inside PM_VOICE_Init, so each of
 * those two functions is the outside witness the other ranges need.
 *
 * The near miss immediately before this range is PM_VOICE_Init,
 * 0x02006544..0x020065D8, 148 bytes.  Evidence class `literal`, witness
 * census 1 image wide and 1 inside the range: the halfword pair table at
 * 0x0209D8C0 that its loop indexes is named by exactly one literal pool
 * word in the whole 3.9 MB image, 0x020065CC, which is PM_VOICE_Init's own
 * pool.  0x0209D8C0 is read only data in the image, so `label`, `veneer`
 * and `string` cannot apply and `literal` is the only class available; no
 * cut helps, because the witness is the pool word of the very function that
 * needs it.  It closes the day anything else in the image loads that
 * address.
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
extern const char sub_02006674_File[];

struct Sub02006948;
extern void  PM_VOICE_Stop(struct Sub02006948 *e);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct O;
extern int NNS_SndWaveOutIsPlaying(struct O *o);

void PM_VOICE_StopAll(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        struct Sub02006544Entry *e = &sub_02006544_State.entries[i];

        if (e->unk00 == 1) {
            PM_VOICE_Stop((struct Sub02006948 *)e);
        }
    }
}

void PM_VOICE_StopFinished(void)
{
    struct Sub02006544Entry *e;
    int i;
    u32 a;
    u32 b;

    for (i = 0; i < sub_02006544_State.count; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk00 == 1) {
            a = NNS_SndWaveOutIsPlaying((struct O *)e->unk14);
            if (e->unk2C == 1) {
                b = NNS_SndWaveOutIsPlaying((struct O *)e->unk18);
            } else {
                b = 0;
            }
            if (a == 0 && b == 0) {
                PM_VOICE_Stop((struct Sub02006948 *)e);
            }
        }
    }
}

int PM_VOICE_IsAnyActive(void)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (sub_02006544_State.entries[i].unk00 == 1) {
            return 1;
        }
    }
    return 0;
}

void PM_VOICE_AllocBuffers(int n, u32 heap)
{
    struct Sub02006544Entry *e;
    int i;

    PM_VOICE_StopAll();
    if (n > 2) {
        n = 2;
    }
    for (i = 1; i < n + 1; i++) {
        e = &sub_02006544_State.entries[i];
        if (e->unk04 == 0) {
            void *p = func_02030734(heap, 0x5C30, 1, sub_02006674_File, 0x105);

            e->unk04 = p;
            e->unk10 = p;
            e->unk30 = 1;
        }
    }
    sub_02006544_State.count = n + 1;
    sub_02006544_State.cur = 0;
}
