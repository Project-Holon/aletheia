/*
 * function: func_02009EC8
 * address:  0x02009EC8
 * packet:   pkt_02009EC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020071CC  0x020071CC  thumb
 *
 * Save-block getter for block 0x1F, the same one-line shape as
 * func_0200AD6C (block 0x2E): a tail call through the pool with the id in
 * r1. Seeded from ov120 (0x021D4A90, 0x021D4AC8), ov135 (0x02201B78) and
 * the ov175 root func_021D7E18 (0x021D827E).
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *func_02009EC8(void *sys)
{
    return func_020071CC(sys, 0x1f);
}
