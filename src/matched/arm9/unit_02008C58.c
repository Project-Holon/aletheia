/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008C58
 * packet:   pkt_02008A34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02008C58, sub_02008C64, sub_02008C94, sub_02008CB4,
 *           sub_02008CD4
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 *   sub_0203F2FC  0x0203F2FC  arm
 *   sub_0203F328  0x0203F328  arm
 *   sub_0203F37C  0x0203F37C  arm
 *
 * alias: the head of the save block with id 0x26, 0x1E0 bytes.  The original
 * file opens at 0x02008C20 with the four bytes that return that size
 * (src/matched/sub_02008C20.c) and this range follows the constructor; the
 * file runs on past 0x02008CF8, where it starts reaching into the static
 * tables at 0x0209DDB4 and 0x020A70C4, which is where this range stops.
 *
 * What the attestation rules say about the run after it, checked with the
 * indexes behind `python tools/match.py tu --suggest-split`:
 *
 *  - sub_02008CF8 itself stays blocked, and not for want of a cut.  It loads
 *    0x020A70C4 and 0x0209DDB4, and each of those two addresses is named by
 *    exactly one pool word in the whole image, its own, at 0x02008D14 and
 *    0x02008D18.  The `literal` class has nothing outside the range, and the
 *    `string` class cannot reach either: 0x020A70C4 is the data table
 *    immediately after "playtime.c", not a string.  It closes the day
 *    anything else in the image loads one of them.
 *  - the four functions after it, 0x02008D1C..0x02008E30, are no longer
 *    blocked by attestation at all, only by not having been written.  Each of
 *    them calls sub_02008C64, sub_02008C94, sub_02008CB4, sub_02008CD4 and
 *    sub_02008CF8, and the callers of each of those five are spread across
 *    several of the four, so any range holding at most two of the four leaves
 *    every one of the five a witness outside it.  0x02008D1C..0x02008DAC and
 *    0x02008DAC..0x02008E30 is such a pair, and the twelve byte thunk at
 *    0x02008DF0 is `local` to the second of them.
 *
 * The block is a flat table with two element widths and its own checksum:
 *
 *   +0x000  u32[0x47]   indices 0x00..0x46
 *   +0x11C  u16[0x60]   indices 0x47..0xA6
 *   +0x1DC  u16         the low half of a checksum over +4..+0x1DC
 *   +0x1DE  u16         ... and its high half
 *
 * sub_02008CB4 and sub_02008CD4 are the getter and setter over that split
 * index space, and both answer 0 for an index at or past 0xA7.  The setter
 * returns what the getter would return, by calling it: the `bl` at the point
 * where both arms have joined is a tail call the compiler could not turn into
 * a `b` because it still has `r4` to pop.
 *
 * The checksum covers 0x1D8 bytes starting at +4, not the whole block, and the
 * pair at +0x1DC and +0x1DE is one 32 bit value split across two `u16` fields:
 * sub_02008C64 reassembles it with an `adds`, not an `orrs`, so the source
 * adds rather than ors.
 *
 * NEAR MISS, 0x02008C28, 48 bytes, 3 concrete bytes wrong, skipped.  The
 * constructor clears the block and then seeds +0x1DE from the word at
 * 0x02FFFC3C in the region the two processors share.  That word is read twice
 * in a row and the two loads are not commoned up, which is a `volatile` read
 * and nothing else: written as a plain `extern u32` the function is two
 * instructions short.  With the `volatile` the size, the schedule and every
 * instruction are the original's, and the three wrong bytes are the register
 * numbering of the three loads alone: the original puts the pool address in
 * `r1` and the first value in `r0`, the compiler does the reverse.  Eleven
 * source shapes were tried (both operand orders, a temporary for either side,
 * a cast on either side, an array-typed declaration, a `const volatile`
 * declaration, and the multiply that folds the two terms into one) and none of
 * them moves it off three.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008C58.c  *       --addr 0x02008C58 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub020071CCCtrl;
extern void *sub_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

/* The checksum pair over a byte range: sub_0203F2FC computes it, sub_0203F328
 * writes it back into the range's own trailer. */
extern u16  sub_0203F2FC(const void *p, u32 size);
extern void sub_0203F328(void *p, u32 size, u32 sum);
extern void sub_0203F37C(void *p, u32 size, u32 sum);

#define BLOCK_ID 0x26

struct Sub02008C20Obj {
    u32 unk000[0x47];
    u16 unk11C[0x60];
    u16 unk1DC;
    u16 unk1DE;
};

void sub_02008C64(struct Sub02008C20Obj *obj, int commit);
u32  sub_02008CB4(const struct Sub02008C20Obj *obj, int i);

struct Sub02008C20Obj *sub_02008C58(void *sys)
{
    return sub_020071CC(sys, BLOCK_ID);
}

void sub_02008C64(struct Sub02008C20Obj *obj, int commit)
{
    if (commit) {
        obj->unk1DC = sub_0203F2FC(&obj->unk000[1], 0x1D8);
        sub_0203F328(&obj->unk000[1], 0x1D8,
                     obj->unk1DC + (obj->unk1DE << 16));
    }
}

void sub_02008C94(struct Sub02008C20Obj *obj, int commit)
{
    if (commit) {
        sub_0203F37C(&obj->unk000[1], 0x1D8,
                     obj->unk1DC + (obj->unk1DE << 16));
    }
}

u32 sub_02008CB4(const struct Sub02008C20Obj *obj, int i)
{
    if (i < 0x47) {
        return obj->unk000[i];
    }
    if (i < 0xA7) {
        return obj->unk11C[i - 0x47];
    }
    return 0;
}

u32 sub_02008CD4(struct Sub02008C20Obj *obj, int i, u32 value)
{
    if (i < 0x47) {
        obj->unk000[i] = value;
    } else if (i < 0xA7) {
        obj->unk11C[i - 0x47] = value;
    }
    return sub_02008CB4(obj, i);
}
