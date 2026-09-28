/*
 * function: func_0205D010
 * address:  0x0205D010
 * packet:   pkt_0205D010
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  +0008 ABS32 func_0205CF24          -> unresolved: 0205CF24 (arm, from name) has no witness outside 0205D010..0205D01C
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 */

extern void func_0205CF24(void);
void func_0205D010(void)
{
    func_0205CF24();
}
