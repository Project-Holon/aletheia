/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02008FFC
 * packet:   pkt_02008FD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: MAIL_GetBoxSize, MAIL_InitBox
 *
 * symbols:
 *   MAIL_Init  0x02008EAC  thumb
 *   MAIL_IsDesignValid  0x02008EF8  thumb
 *   MAIL_Copy  0x02008F3C  thumb
 *   MAIL_FindEmptySlotInRange  0x02009074  thumb
 *   MAIL_GetSlot  0x020090A0  thumb
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
 * MAIL_SetSlot and MAIL_CreateSlotCopy are the only two callers of MAIL_Copy
 * anywhere in the ROM, so matched in one range they attest each other's call
 * site out of existence and the whole file caps at MATCH with every concrete
 * byte right.  Split so that the two sit in different ranges, each is the
 * other's outside witness.  The same trick closed the pair at 0x02008B20; see
 * "The honesty rule" in docs/MATCHING.md.
 *
 * NEAR MISS, 0x02009020, 12 bytes, every concrete byte right, skipped.  It is
 * a three-instruction tail call to MAIL_FindEmptySlotInRange through a pool word, and that
 * pool word is the only reference to 0x02009074 in the image: nothing branches
 * to it, so the `label` class has nothing to offer and the `literal` class's
 * only witness is the word under test.  Inside a range that also defines
 * MAIL_FindEmptySlotInRange the reference is `local` and needs no evidence, but such a
 * range spans both MAIL_SetSlot and MAIL_CreateSlotCopy and so gives the MAIL_Copy
 * problem back.  The two constraints cannot both be met, so this is the one
 * function of the file left out.
 *
 * 0x38 is not a power of two, so every index in this file costs a `muls` and
 * the element size sits in a register hoisted out of the loop.  That multiply
 * is the tell that the array is of a struct and not of words: an array of
 * anything 1, 2, 4 or 8 bytes wide would have been a shift.
 *
 * MAIL_GetSlot is the bounds-checked element lookup the three functions before
 * it go through, and it ignores its second argument entirely: the parameter is
 * in `r1`, `r1` is dead from the first instruction, and the callers pass their
 * own second argument straight through.  That is not an artefact of the
 * matching; no instruction in the function reads `r1`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02008FFC.c \
 *       --addr 0x02008FFC --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* The 0x38-byte element; the accessors over it are in unit_02008F80.c. */
struct Sub02008F80Obj {
    u8 unk00[0x38];
};

struct Sub02008EACObj;
extern void MAIL_Init(struct Sub02008EACObj *obj);
extern int   MAIL_IsDesignValid(const struct Sub02008F80Obj *obj);
extern void *sub_02008F08(int a0);
extern void  MAIL_Copy(const struct Sub02008F80Obj *src,
                          struct Sub02008F80Obj *dest);

#define ENTRY_COUNT 0x14

struct Sub02008F80Obj *MAIL_GetSlot(struct Sub02008F80Obj *arr, u32 unused,
                                    int i);
int MAIL_FindEmptySlotInRange(struct Sub02008F80Obj *arr, int n);

u32 MAIL_GetBoxSize(void)
{
    return sizeof(struct Sub02008F80Obj[ENTRY_COUNT]);
}

void MAIL_InitBox(struct Sub02008F80Obj *arr)
{
    int i;

    for (i = 0; i < ENTRY_COUNT; i++) {
        MAIL_Init((struct Sub02008EACObj *)(&arr[i]));
    }
}

