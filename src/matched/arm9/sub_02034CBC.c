/*
 * function: GF_OVERLAY_GetSlots
 * address:  0x02034CBC
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
 * Selects one of three registration tables out of the areaman singleton by
 * a small index.  The singleton holds the three table pointers at +4, +8
 * and +0xc; an out-of-range index yields the same table as index 0, which
 * is why the compiler cross-jumps the default return onto case 0's block
 * and the `cmp r0, #0` at the top branches to the tail rather than to a
 * block of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_OVERLAY_GetSlots.c \
 *       --func GF_OVERLAY_GetSlots --addr 0x02034CBC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct AreaTables {
    u32   unk0;
    void *t0;
    void *t1;
    void *t2;
};

extern struct AreaTables *unk_021469B8;

void *GF_OVERLAY_GetSlots(int i)
{
    switch (i) {
    default:
    case 0:
        return unk_021469B8->t0;
    case 1:
        return unk_021469B8->t1;
    case 2:
        return unk_021469B8->t2;
    }
}
