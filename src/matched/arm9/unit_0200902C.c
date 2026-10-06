/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x0200902C
 * packet:   pkt_02008FD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0200902C, sub_0200903C
 *
 * symbols:
 *   sub_02008EAC  0x02008EAC  thumb
 *   sub_02008F3C  0x02008F3C  thumb
 *   sub_020090A0  0x020090A0  thumb
 *
 * alias: the table of twenty of the 0x38-byte objects described in
 * src/matched/unit_02008F80.c, and the operations over it.  The original file
 * runs 0x02008FFC..0x020090B0 in one piece, closed on both sides by the
 * size-returning openers this part of the image uses throughout: 0x02008FFC
 * returns 0x460, which is twenty times 0x38, and 0x020090B0 returns 0x2C for
 * the next file.  It is committed as three pieces plus one function left out,
 * and the split is forced by the attestation rule rather than by anything in
 * the code:
 *
 *   src/matched/unit_02008FFC.c   0x02008FFC..0x02009020
 *   0x02009020                    a near miss, see below
 *   src/matched/unit_0200902C.c   0x0200902C..0x02009050
 *   src/matched/unit_02009050.c   0x02009050..0x020090B0
 *
 * sub_0200903C and sub_02009050 are the only two callers of sub_02008F3C
 * anywhere in the ROM, so matched in one range they attest each other's call
 * site out of existence and the whole file caps at MATCH with every concrete
 * byte right.  Split so that the two sit in different ranges, each is the
 * other's outside witness.  The same trick closed the pair at 0x02008B20; see
 * "The honesty rule" in docs/MATCHING.md.
 *
 * NEAR MISS, 0x02009020, 12 bytes, every concrete byte right, skipped.  It is
 * a three-instruction tail call to sub_02009074 through a pool word, and that
 * pool word is the only reference to 0x02009074 in the image: nothing branches
 * to it, so the `label` class has nothing to offer and the `literal` class's
 * only witness is the word under test.  Inside a range that also defines
 * sub_02009074 the reference is `local` and needs no evidence, but such a
 * range spans both sub_0200903C and sub_02009050 and so gives the sub_02008F3C
 * problem back.  The two constraints cannot both be met, so this is the one
 * function of the file left out.
 *
 * 0x38 is not a power of two, so every index in this file costs a `muls` and
 * the element size sits in a register hoisted out of the loop.  That multiply
 * is the tell that the array is of a struct and not of words: an array of
 * anything 1, 2, 4 or 8 bytes wide would have been a shift.
 *
 * sub_020090A0 is the bounds-checked element lookup the three functions before
 * it go through, and it ignores its second argument entirely: the parameter is
 * in `r1`, `r1` is dead from the first instruction, and the callers pass their
 * own second argument straight through.  That is not an artefact of the
 * matching; no instruction in the function reads `r1`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200902C.c \
 *       --addr 0x0200902C --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The 0x38-byte element; the accessors over it are in unit_02008F80.c. */
struct Sub02008F80Obj {
    u8 unk00[0x38];
};

struct Sub02008EACObj;
extern void sub_02008EAC(struct Sub02008EACObj *obj);
extern int   sub_02008EF8(const struct Sub02008F80Obj *obj);
extern void *sub_02008F08(int a0);
extern void  sub_02008F3C(const struct Sub02008F80Obj *src,
                          struct Sub02008F80Obj *dest);

#define ENTRY_COUNT 0x14

struct Sub02008F80Obj *sub_020090A0(struct Sub02008F80Obj *arr, u32 unused,
                                    int i);
int sub_02009074(struct Sub02008F80Obj *arr, int n);

void sub_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);

    if (obj != 0) {
        sub_02008EAC((struct Sub02008EACObj *)obj);
    }
}

void sub_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i,
                  const struct Sub02008F80Obj *src)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);

    if (obj != 0) {
        sub_02008F3C(src, obj);
    }
}

