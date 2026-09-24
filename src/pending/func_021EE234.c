/*
 * function: func_021EE234
 * address:  0x021EE234
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  020257C4
 *
 * symbols:
 *
 * Forward the i-th entry word to the per-entry handler.
 *
 * MATCH, not EXACT: the pool word is 0x020257C5 (a Thumb tail call to
 * 0x020257C4) and that address has no witness in the image outside this
 * function (match.py: "unresolved: 020257C4 (thumb, from header) has no
 * witness outside 021EE234..021EE244").  Its sibling func_021EE224 is EXACT:
 * it pools 0x02025775, and 0x02025774 does have a witness.  Aiming the call at
 * a literal `((void(*)(int))0x020257C5)` instead does reproduce the four pool
 * bytes but the compiler then keeps the value in a register and emits
 * `push/blx/pop` instead of the image's `ldr r3,=T; bx r3`, so the literal
 * spelling is worse, not better.  Everything else reproduces.
 */

extern void func_020257C4(int);

void func_021EE234(char *p, int i)
{
    func_020257C4(*(int *)(p + i * 8 + 4));
}
