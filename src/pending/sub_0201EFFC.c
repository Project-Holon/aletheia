/*
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * unit:     yes
 * address:  0x0201EFFC
 * packet:   pkt_0201E4C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * function: func_0201EFFC
 *
 * The last function of wordset.c's body: it normalises a value through
 * func_0202473C and stores the result into the one-byte flag of the slot's
 * tag.  Every concrete byte is reproduced; the one unresolved relocation is
 * the call to 0x0202473C, and 0x0201F008, the call inside this very function,
 * is the only branch to that address anywhere in the 3.9 MB image.  No cut
 * helps, because shrinking the range to this one function keeps the call in
 * it, and the `matched` class cannot carry it either until 0x0202473C itself
 * is matched.  See "The limit of the remedy" in docs/MATCHING.md.
 *
 * The value is passed by address, so it lives on the stack and is read back
 * after the call; the `str r2, [sp]` before the call and the `ldr r2, [sp]`
 * after it are that, not a spill.
 *
 * Promote this file the day 0x0202473C is EXACT.
 *
 * Verified with:
 *   python tools/match.py tu --src src/pending/sub_0201EFFC.c \
 *       --addr 0x0201EFFC --thumb
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
