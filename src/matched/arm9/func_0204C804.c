/*
 * function: func_0204C804
 * address:  0x0204C804
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Find the first free 0x10-byte entry of a pool, free meaning a zero word at
 * +0x00.  Returns NULL when the pool is full.  A leaf: nothing here calls
 * anything, so both the entry array and the count are hoisted out of the loop
 * and the element address is only materialised on the arm that returns it
 * (`addeq r0, r2, r1, lsl #4`).
 *
 * The scaled register offset `ldr r0, [r2, r1, lsl #4]` is the subscript form
 * `p->ents[i].unk_00`; a walking cursor would have produced a post-indexed
 * load and an extra add
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C804.c \
 *       --func func_0204C804 --addr 0x0204C804 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u32 unk_00;   /* 0x00 */
    u8  pad_04[0x0c];
};

struct Pool {
    u8            pad_00[4];
    struct Entry *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
};

struct Entry *func_0204C804(struct Pool *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (p->ents[i].unk_00 == 0) {
            return &p->ents[i];
        }
    }

    return 0;
}
