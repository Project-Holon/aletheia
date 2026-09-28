/*
 * function: func_0203D010
 * address:  0x0203D010
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper (`ldr ip, [pc]; bx ip`, docs/idioms tail-call-is-a-
 * pool-word-and-bx), called by state 10 of func_0203DC70.  An unlabelled
 * ARM leaf inside func_0203CFA0's EXACT* extent; filed as a witness.
 *
 * symbols:
 *   func_0203B1B0  0x0203B1B0  arm
 */

extern void func_0203B1B0(void);

void func_0203D010(void)
{
    func_0203B1B0();
}
