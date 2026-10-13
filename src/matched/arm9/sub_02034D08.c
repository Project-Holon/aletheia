/*
 * function: GF_OVERLAY_GetSlotCount
 * address:  0x02034D08
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469B8  0x021469B8  data
 *
 * The live-length companion of GF_OVERLAY_GetSlots: the same three-way index, but
 * reading the three `u8` counts packed at the head of the areaman singleton
 * rather than the table pointers at +4/+8/+0xc.  Here the default is its own
 * arm returning 0, so the `cmp r0, #0` block is distinct and the dispatch
 * chain ends in an explicit `b` to the zero tail instead of cross-jumping.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetSlotCount.c \
 *       --func GF_OVERLAY_GetSlotCount --addr 0x02034D08 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct AreaCounts {
    u8 n0;
    u8 n1;
    u8 n2;
};

extern struct AreaCounts *unk_021469B8;

u8 GF_OVERLAY_GetSlotCount(int i)
{
    switch (i) {
    case 0:
        return unk_021469B8->n0;
    case 1:
        return unk_021469B8->n1;
    case 2:
        return unk_021469B8->n2;
    }
    return 0;
}
