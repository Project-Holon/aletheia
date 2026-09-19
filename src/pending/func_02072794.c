/*
 * function: func_02072794
 * address:  0x02072794
 * packet:   pkt_02071B2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  +0010 PC24 func_02089754           -> unresolved: 02089754 (arm, from header) has no witness outside 02072794..020727B4; +0018 PC24 func_02089774           -> unresolved: 02089774 (arm, from header) has no witness outside 02072794..020727B4
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   func_02089754    0x02089754  arm
 *   func_02089774    0x02089774  arm
 *
 * Master-pan switch: sets the pan to 0x40 when the argument is non-zero,
 * otherwise resets it.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02072794.c \
 *       --func func_02072794 --addr 0x02072794 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_02089754(u32 pan);
extern void func_02089774(void);

void func_02072794(u32 on)
{
    if (on != 0) {
        func_02089754(0x40);
    } else {
        func_02089774();
    }
}
