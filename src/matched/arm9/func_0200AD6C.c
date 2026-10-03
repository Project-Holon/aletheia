/*
 * function: func_0200AD6C
 * address:  0x0200AD6C
 * packet:   pkt_0200AD6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020071CC  0x020071CC  thumb
 *
 * Save-block getter for block 0x2E, the same one-line shape as
 * func_0200A864 / func_0200A8A0 (blocks 0x2B, 0x2C) in unit_0200A864.c:
 * a tail call through the pool with the id in r1.
 */

typedef unsigned int   u32;
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);

void *func_0200AD6C(void *sys)
{
    return func_020071CC(sys, 0x2e);
}
