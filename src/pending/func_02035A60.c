/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x020358A0, which has no outside witness: the only branch to that
 * address in the whole image is the one inside this function, and the target
 * is a 448-byte function that carries no `func_` label, so the `label` class
 * cannot reach it either.  It closes the day 0x020358A0 is matched itself (its
 * manifest entry becomes the witness) or a second caller turns up.
 *
 * function: func_02035A60
 * address:  0x02035A60
 * packet:   pkt_02035760
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  `bl` to 0x020358A0: no branch outside this range reaches it and it carries no func_ label
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   func_020358A0  0x020358A0  arm
 *
 * Two calls in a row, the second one's result returned through the shared
 * `pop {r3, pc}`.  Nothing else: no stack frame, no locals.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02035A60.c \
 *       --func func_02035A60 --addr 0x02035A60 --cc 1.1p1 --arm
 */

extern void func_02035224(void);
extern void func_020358A0(void);

void func_02035A60(void)
{
    func_02035224();
    func_020358A0();
}
