/*
 * file:     mail_p04.c
 * unit:     yes
 * function: func_02008FFC, func_02009004, func_02009020, func_0200902C, func_0200903C, func_02009050, func_02009074, func_020090A0, func_020090B0, func_020090B4, func_020090D8, func_020090E0, func_020090E8, func_020090F0, func_020090F8, func_02009108, func_0200910C
 * address:  0x02008FFC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_02008EAC  0x02008EAC  thumb
 *   func_02009074  0x02009074  thumb
 *   sub_02008F3C  0x02008F3C  thumb
 *   sub_020090A0  0x020090A0  thumb
 *   sub_02008EF8  0x02008EF8  thumb
 *   sub_02008F08  0x02008F08  thumb
 */
struct Sub02008EACObj;
struct Sub02008F80Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* The 0x38-byte element; the accessors over it are in unit_02008F80.c. */
struct Sub02008F80Obj {
    u8 unk00[0x38];
};

struct Sub020090B0Obj {
    u8  unk00[9][4];
    u16 unk24;
    u8  unk26;
    u8  unk27;
    u8  unk28;
    u8  unk29[3];
};

extern void sub_02008EAC(struct Sub02008EACObj *obj);
extern int   sub_02008EF8(const struct Sub02008F80Obj *obj);
extern void *sub_02008F08(int a0);
extern void  sub_02008F3C(const struct Sub02008F80Obj *src,
                          struct Sub02008F80Obj *dest);
struct Sub02008F80Obj *sub_020090A0(struct Sub02008F80Obj *arr, u32 unused,
                                    int i);
int sub_02009074(struct Sub02008F80Obj *arr, int n);
extern int func_02009074(struct Sub02008F80Obj *arr, int n);
u32 sub_02008FFC(void);
void func_02009020(void *table);
u32 sub_020090B0(void);
int func_020090B4(int a0, int a1, int a2, int a3);


#define ENTRY_COUNT 0x14


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
 *   python tools/match.py tu --src src/matched/unit_02008FFC.c \
 *       --addr 0x02008FFC --thumb
 */
u32 sub_02008FFC(void)
{
    return sizeof(struct Sub02008F80Obj[ENTRY_COUNT]);
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
 *   python tools/match.py tu --src src/matched/unit_02008FFC.c \
 *       --addr 0x02008FFC --thumb
 */
void sub_02009004(struct Sub02008F80Obj *arr)
{
    int i;

    for (i = 0; i < ENTRY_COUNT; i++) {
        sub_02008EAC((struct Sub02008EACObj *)(&arr[i]));
    }
}


/*
 * Tail call to func_02009074 with the count 0x14: the twenty-element table
 * of 0x38-byte objects described in src/matched/unit_02008FFC.c.  That file
 * left it out as a near miss because the pool word was the only reference to
 * 0x02009074; func_02009074 is now matched (src/matched/unit_02009050.c), so
 * the relocation attests through the `matched` class.  Seeded from ov119
 * 0x021E062E (tree_ov170_3).
 *
 * Addresses are Black-image addresses.
 */
void func_02009020(void *table)
{
    func_02009074(table, 0x14);
}


#define ENTRY_COUNT 0x14


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
void sub_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);

    if (obj != 0) {
        sub_02008EAC((struct Sub02008EACObj *)obj);
    }
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
void sub_0200903C(struct Sub02008F80Obj *arr, u32 unused, int i,
                  const struct Sub02008F80Obj *src)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);

    if (obj != 0) {
        sub_02008F3C(src, obj);
    }
}


#define ENTRY_COUNT 0x14


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
 *   python tools/match.py tu --src src/matched/unit_02009050.c \
 *       --addr 0x02009050 --thumb
 */
struct Sub02008F80Obj *sub_02009050(struct Sub02008F80Obj *arr, u32 unused,
                                    int i, u32 heap)
{
    struct Sub02008F80Obj *obj = sub_020090A0(arr, unused, i);
    struct Sub02008F80Obj *copy = sub_02008F08(heap);

    if (obj != 0) {
        sub_02008F3C(obj, copy);
    }
    return copy;
}

/* The index of the first element the predicate says is out of range, or -1. */
/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
 *   python tools/match.py tu --src src/matched/unit_02009050.c \
 *       --addr 0x02009050 --thumb
 */
int sub_02009074(struct Sub02008F80Obj *arr, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (sub_02008EF8(&arr[i]) == 0) {
            return i;
        }
    }
    return -1;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
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
 *   python tools/match.py tu --src src/matched/unit_02009050.c \
 *       --addr 0x02009050 --thumb
 */
struct Sub02008F80Obj *sub_020090A0(struct Sub02008F80Obj *arr, u32 unused,
                                    int i)
{
    if (i < ENTRY_COUNT) {
        return &arr[i];
    }
    return 0;
}


/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/001_02007664.s.  Not an SDK symbol: it is absent from
 * layout/symbols_sdk.txt.
 *
 * Original (4 bytes, leaf, no relocations):
 *   movs r0, #0x2c
 *   bx   lr
 *
 * The size-returning opener of the next file in the chain, and the value the
 * constructor at 0x020090B4 clears.  The accessors over the object are in
 * src/matched/unit_020090D8.c, which also says why the constructor between the
 * two is not matched here.
 */
u32 sub_020090B0(void)
{
    return sizeof(struct Sub020090B0Obj);
}

int func_020090B4(int a0, int a1, int a2, int a3){ int t0, t1, t2; t0 = func_020090B0(); t1 = func_02082BCC((int)((a0 + 0) + 0), (int)0, (int)(t0 + 0)); t2 = func_02082D44((int)0x20A7174, (int)((a0 + 0) + 0), (int)0x24); return t2; }


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
void sub_020090D8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk27 = value;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
u8 sub_020090E0(const struct Sub020090B0Obj *obj)
{
    return obj->unk27;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
void sub_020090E8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk28 = value;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
u8 sub_020090F0(const struct Sub020090B0Obj *obj)
{
    return obj->unk28;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
void sub_020090F8(struct Sub020090B0Obj *obj, u8 value)
{
    obj->unk26 = value;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
u8 sub_02009100(const struct Sub020090B0Obj *obj)
{
    return obj->unk26;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
void sub_02009108(struct Sub020090B0Obj *obj, u16 value)
{
    obj->unk24 = value;
}

/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 *           sub_020090F8, sub_02009100, sub_02009108, sub_0200910C
 *
 * The eight scalar accessors of the 0x2C-byte object whose size function is
 * src/matched/sub_020090B0.c.  Seven of the eight carry no label in the
 * generated listing: they have no register-saving prologue, so disasm.py's
 * sweep never fires and the listing emits them as data words.
 *
 * Layout, from the accessors and from the constructor's 0x24-byte copy:
 *
 *   +0x00  u8[9][4]  the table the three-argument readers after this range
 *                    index, with the row bound 9 and the column bound 4
 *   +0x24  u16       get/set
 *   +0x26  u8        get/set
 *   +0x27  u8        get/set
 *   +0x28  u8        get/set
 *
 * NEAR MISS, 0x020090B4, 36 bytes, skipped.  The constructor clears the object
 * and then copies 0x24 bytes of initial state over it from 0x020A7174.  That
 * address appears in exactly one literal pool in the image, the constructor's
 * own, so the `literal` class discards its only witness and there is nothing
 * else to attest a data address with.  It is the same shape as the hole the
 * `string` class was invented for, but the bytes at 0x020A7174 are a table
 * rather than a string, so that class does not reach it either.  It closes the
 * day anything else in the image loads that address.
 *
 * Six of the eight cost an extra `adds r0, #imm` before the load or store,
 * because `ldrb` and `strb` reach only +31 and the fields are at +0x26, +0x27
 * and +0x28.  The two `u16` accessors at +0x24 need no such thing: `ldrh`
 * reaches +62.  See docs/idioms/thumb-immediate-reach-costs-an-adds.md.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020090D8.c \
 *       --addr 0x020090D8 --thumb
 */
u16 sub_0200910C(const struct Sub020090B0Obj *obj)
{
    return obj->unk24;
}
