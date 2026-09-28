/*
 * function: func_0201EFFC
 * address:  0x0201EFFC
 * packet:   pkt_0201E4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Promoted from src/pending/sub_0201EFFC.c: every concrete byte was
 * already reproduced, and the one relocation, the call to
 * func_0202473C, was capped at MATCH because the only branch to that
 * address anywhere in the image is the one inside this function. Now
 * that src/matched/sub_0202473C.c is an EXACT entry, the `matched` class
 * attests the call without needing a second caller (docs/MATCHING.md,
 * "the matched class"), and this file closes to EXACT.
 *
 * The last function of wordset.c's body: it normalises a value through
 * func_0202473C and stores the result into the one-byte flag of the
 * slot's tag. The value is passed by address, so it lives on the stack
 * and is read back after the call; the `str r2, [sp]` before the call and
 * the `ldr r2, [sp]` after it are that, not a spill.
 *
 * symbols:
 *   func_0202473C  0x0202473C  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201EFFC.c \
 *       --func func_0201EFFC --addr 0x0201EFFC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202473C(u32 *p, u32 a);

struct Tag {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03 : 7;
    u8 unk03b : 1;
    u8 unk04;
};

struct Entry {
    struct Tag tag;
    void *str;
};

struct WordSet {
    u32 count;
    u32 heap;
    struct Entry *entries;
    void *buf;
};

void func_0201EFFC(struct WordSet *p, u32 i, u32 v)
{
    u32 x = v;

    func_0202473C(&x, 0);
    if (i < p->count) {
        p->entries[i].tag.unk04 = x;
    }
}
