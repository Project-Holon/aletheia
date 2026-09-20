/*
 * PARKED AT MATCH.  Every concrete byte is right.  The one open site is the
 * `bl` to 0x0203386C, which has exactly one caller image-wide, this one, so
 * `label` has nothing outside the range to point at.
 *
 * function: sub_020331D0
 * address:  0x020331D0
 * packet:   pkt_020328E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   func_0203386C  0x0203386C  arm
 *   func_02034FB8  0x02034FB8  arm
 *   unk_02146994   0x02146994  data
 *
 * savedata.c.  The same completion path as sub_020331A4 but for the
 * unconditional case: roll the generation back, hand the halfword at
 * +0x20C of the object the global at 0x02146994 points at to 0x0203386C,
 * and drop the busy flag.
 *
 * The `add r0, r0, #0x200` before the `ldrh r0, [r0, #0xc]` is the reach of
 * the Thumb-era halfword load showing through, not a second object: see
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_020331D0.c  *       --func sub_020331D0 --addr 0x020331D0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct SaveBackup {
    u8 pad00[0x10];
    u32 unk10;
    u32 unk14;
    u8 unk18;
    u8 unk19;
    u8 pad1A[2];
    u8 unk1C;
    u8 pad1D[11];
    u32 unk28;
    u8 pad2C[4];
    u32 unk30;
    u32 unk34;
    u8 pad38[0x10C];
    u32 unk144;
};

struct SaveMain {
    u8 pad000[0x20C];
    u16 unk20C;
};

extern struct SaveMain *unk_02146994;

extern void func_0203386C(u32 x);
extern void func_02034FB8(u32 bit);

void sub_020331D0(struct SaveBackup *p)
{
    p->unk28 = p->unk10;
    func_0203386C(unk_02146994->unk20C);
    func_02034FB8(1);
}
