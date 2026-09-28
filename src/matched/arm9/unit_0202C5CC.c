/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C5CC
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_0202C5CC, sub_0202C5E0
 *
 * Two plain functions on the object of src/matched/unit_0202C5B4.c and
 * src/matched/sub_0202C5C4.c, contiguous with no gap and neither calling
 * out. sub_0202C5CC increments a bounded counter at offset 4 and clamps it
 * back down to the limit held at offset 6 (a saturating counter, not a
 * wrapping one: the increment always happens, and only the store is
 * undone when it overshoots). sub_0202C5E0 is the complementary test,
 * returning 0 while the limit still exceeds the counter and 1 once it has
 * caught up.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C5CC.c \
 *       --addr 0x0202C5CC --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Counter0202C5B4 {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
};

void sub_0202C5CC(struct Counter0202C5B4 *p)
{
    p->unk04 = p->unk04 + 1;
    if (p->unk06 < p->unk04) {
        p->unk04 = p->unk06;
    }
}

u32 sub_0202C5E0(struct Counter0202C5B4 *p)
{
    if (p->unk06 > p->unk04) {
        return 0;
    }
    return 1;
}
