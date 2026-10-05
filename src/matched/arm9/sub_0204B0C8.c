/*
 * unit:     no
 * function: sub_0204B0C8
 * address:  0x0204B0C8
 * packet:   pkt_0204B0C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * EXACT*, not EXACT: the listing extent runs 12 bytes long because what
 * follows at 0x0204B0F4 is not code from this file at all, it is a linker
 * veneer, `ldr ip, [pc]; bx ip; .word 0x0204BE38`
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * describes the Thumb-side form of the same stub).  0x0204B0F4 is a seed for
 * layout/function_starts.txt, and no `tu` range may span it.
 *
 * Read back one cell actor's position: the 0x48-byte records hang off +0x98 of
 * the owner, their first two words are the x and y coordinates in 20.12 fixed
 * point, and the caller gets them as a pair of whole-pixel s16 values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B0C8.c \
 *       --func sub_0204B0C8 --addr 0x0204B0C8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed short  s16;

struct Item {
    int x;
    int y;
    u8  pad_08[0x40];
};

struct Owner {
    u8           pad_00[0x98];
    struct Item *items;
};

struct Pt {
    s16 x;
    s16 y;
};

void sub_0204B0C8(struct Owner *owner, u32 index, struct Pt *out)
{
    struct Item *item = &owner->items[index];

    out->x = item->x >> 12;
    out->y = item->y >> 12;
}
