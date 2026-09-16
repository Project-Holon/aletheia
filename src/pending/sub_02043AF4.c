/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * function: func_02043AF4
 * address:  0x02043AF4
 * packet:   pkt_0204384C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_02044BF0  0x02044BF0  arm
 *   func_02044CE0  0x02044CE0  arm
 *   func_02044D88  0x02044D88  arm
 *   func_02044EBC  0x02044EBC  arm
 *
 * bmp.c's six-argument fill dispatcher, the single-bitmap sibling of the
 * blit dispatcher at 0x020439A0: the same two-level switch on the source
 * bitmap's +0xA and +8 halfwords, over four workers, but with nothing to
 * narrow, so the two outgoing stack words are one `stm sp, {r4, lr}` written
 * out in each arm rather than a tail-merged run of `str`s.
 *
 * Both `ldrh`s are hoisted ahead of their `cmp`s and the +8 load is issued
 * even on the path that will not use it; that is scheduling, not a third
 * read of the struct.
 *
 * The fall-through arm is the source order in both tests
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md): `!= 2` first,
 * then `== 0x20`.
 *
 * Every one of the 104 concrete bytes is reproduced; all four relocations
 * stay wildcarded for the same reason as src/pending/sub_020439A0.c: each of
 * the four fill workers is called from this dispatcher and from nowhere else
 * in the image, so no site has a `label` witness outside the compared range,
 * none of the four is in the manifest, and the range is one function so
 * there is no cut.  0x02044CE0 already has a near-miss note,
 * docs/notes/sub_02044CE0.c.txt.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_02043AF4.c \
 *       --func func_02043AF4 --addr 0x02043AF4 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Bmp {
    u8  pad00[8];
    u16 unk08;
    u16 unk0A;
};

extern void func_02044BF0(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6);
extern void func_02044CE0(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6);
extern void func_02044D88(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6);
extern void func_02044EBC(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6);

void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6)
{
    if (b->unk0A != 2) {
        if (b->unk08 == 0x20) {
            func_02044BF0(b, a2, a3, a4, a5, a6);
        } else {
            func_02044CE0(b, a2, a3, a4, a5, a6);
        }
    } else {
        if (b->unk08 == 0x20) {
            func_02044D88(b, a2, a3, a4, a5, a6);
        } else {
            func_02044EBC(b, a2, a3, a4, a5, a6);
        }
    }
}
