/*
 * function: func_021BF03C
 * address:  0x021BF03C
 * packet:   pkt_021BF03C
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0203C3EC  0x0203C3EC  arm
 *
 * True when func_0203C3EC() reports 1: `push {r3, lr}; blx; cmp r0, #1; bne;
 * movs r0, #1; pop; movs r0, #0; pop`.
 *
 * NOT EXACT.  MATCH: the 14 bytes are right and the single relocation is
 * correct, but the target address 0x0203C3EC has no witness, so match.py
 * leaves the BL/BLX field wildcarded and will not claim the entry.
 *
 * Blocking class: missing witness.  0x0203C3EC is not a matched entry, is not
 * an SDK symbol and is not a labelled function start in arm9's listing; the
 * only references to it are BLX sites (ov099 at 0x021BF03C and 0x021BF06A, and
 * its other callers), so neither `matched` nor `sole-ref/code` attests it.  It
 * becomes EXACT as soon as the arm9 function at 0x0203C3EC is itself matched.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_021BF03C.c \
 *       --func func_021BF03C --addr 0x021BF03C --region ov099 --thumb --cc 1.1p1
 */

typedef unsigned long u32;
typedef int BOOL;

extern int func_0203C3EC(void);

BOOL func_021BF03C(void)
{
    if (func_0203C3EC() == 1) {
        return 1;
    }

    return 0;
}
