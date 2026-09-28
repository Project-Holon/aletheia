/*
 * function: sub_0200AA68
 * address:  0x0200AA68
 * packet:   pkt_0200AA68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   sub_0200ACD0  0x0200ACD0  thumb
 *   sub_0200AC14  0x0200AC14  thumb
 *   sub_0200AB50  0x0200AB50  thumb
 *   sub_0200ABE0  0x0200ABE0  thumb
 *   sub_0200AD00  0x0200AD00  thumb
 *
 * EXACT*: the listing extent is 196 bytes because the two unlabelled leaves
 * at 0x0200AB04 and 0x0200AB24 follow without a label; they are already
 * matched separately as src/matched/unit_0200AB04.c.  This file reproduces
 * the 154 bytes of sub_0200AA68 itself.
 *
 * The orchestrator of the family (see docs/families/mystery_data.h).  Find an
 * existing Entry with the caller's key (sub_0200ACD0), take its 10-bit
 * counter if there is one, build a fresh Entry on the stack from that counter
 * and the caller's eleven arguments (sub_0200AC14), insert it in key order
 * (sub_0200AB50) recording the slot in the low byte of the record's flag word
 * at +0x348, and if the new entry duplicates one already present
 * (sub_0200ABE0) bump every matching entry's counter (sub_0200AD00).  It
 * returns the slot back out of the flag word.
 *
 * This row was the "unfilable" one of docs/notes/pkt_0200AA00.c.txt (misfiled
 * under that name; it is about 0x0200AA68).  That note's verdict was that
 * every one of the five call sites is unwitnessed outside the compared range
 * and the row therefore caps at MATCH.  THAT IS NO LONGER TRUE, for two
 * independent reasons: all five callees are matched today, and the
 * `sole-ref/code` class introduced 2026-09-21 carries a code target that is
 * exactly a traced function start with no outside-branch requirement, which
 * is precisely the single-caller-callee shape here.  All five sites now
 * resolve as `sole-ref`, and the row is EXACT* rather than MATCH.
 *
 * Three declaration-level levers, none of them a statement shape:
 *
 *  1. sub_0200AC14 takes EIGHT SEPARATE SCALAR PARAMETERS, not one 0x20-byte
 *     struct by value (see the header of src/matched/func_0200AC14.c, which
 *     this wave re-read the same way).  Passing a struct makes this caller
 *     emit an ldm/stm block copy where the original stores each field into
 *     its own outgoing word with `str`; the scalar form is what produces the
 *     `ldrb r1, [r0, #4] / str r1, [sp, #8]` ladder at +0x28..+0x48.
 *  2. `a2` is u16, not u32.  This is the one the permuter found:
 *       --mode hill --budget 800 --types, 189 single mutations tried,
 *       191st compile: type:p(a2:u32->u16), 74 concrete bytes out -> 46,
 *       and it aligned the whole first 0x5C bytes of the function.
 *     Nothing about the disassembly says a2 is narrow directly; it says so
 *     only through the register allocation downstream of it, which is exactly
 *     the residue class permuter.py exists for.
 *  3. The +0x348 flag word is read and written as an 8-bit BITFIELD, not
 *     masked by hand.  `((Flags *)&r->f348)->b0 = sub_0200AB50(...)` gives
 *     the interleaved `lsls r0, #0x18 / ... / lsrs r0, #0x18 / orrs r0, r2`
 *     the original has; the hand-written `r->f348 = (r->f348 & ~0xff) | slot`
 *     hoists the truncation out of the mask work and is 4 bytes short.  The
 *     read at the end needs the same bitfield, which is where the SECOND
 *     `lsls #0x18 / lsrs #0x18` pair at +0x92 comes from -- a plain
 *     `(u8)(r->f348 & 0xff)` folds the two pairs into one.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0200AA68.c \
 *       --func sub_0200AA68 --addr 0x0200AA68 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u16 w0[8];
    u32 b0 : 7;
    u32 b1 : 10;
    u32 b2 : 1;
    u32 b3 : 4;
    u32 b4 : 4;
    u32 b5 : 5;
    u32 b6 : 1;
    u32 f14;
    u16 f18;
    u8  f1a;
    u8  c0 : 6;
    u8  c1 : 1;
    u8  c2 : 1;
} Entry;

typedef struct {
    u32 b0 : 8;
    u32 b8 : 24;
} Flags;

typedef struct {
    Entry entries[30];
    u32   f348;
} Rec;

extern Entry *sub_0200ACD0(Entry *base, s32 n, u32 key);
extern void   sub_0200AC14(Entry *dst, const void *src, u32 a2, u32 a3,
                           u32 p0, u8 p1, u8 p2, u32 p3, u16 p4, u8 p5, u8 p6, u8 p7);
extern u8     sub_0200AB50(Entry *list, s32 n, Entry *dst);
extern s32    sub_0200ABE0(Entry *base, s32 n, Entry *other);
extern void   sub_0200AD00(Entry *base, s32 n, Entry *ref);

u8 sub_0200AA68(Rec *r, const void *src, u16 a2, u32 a3,
                u8 s0, u8 s1, u32 s2, u16 s3, u8 s4, u8 s5, u8 s6)
{
    Entry tmp;
    Entry *hit;
    u16 count = 0;

    hit = sub_0200ACD0(r->entries, 30, s2);
    if (hit != 0) {
        count = hit->b1;
    }
    sub_0200AC14(&tmp, src, a2, count, a3, s0, s1, s2, s3, s4, s5, s6);
    {
    ((Flags *)&r->f348)->b0 = sub_0200AB50(r->entries, 30, &tmp);
    }
    if (sub_0200ABE0(r->entries, 30, &tmp) != 0) {
        sub_0200AD00(r->entries, 30, &tmp);
    }
    {
        u8 v = ((Flags *)&r->f348)->b0;
        return v;
    }
}
