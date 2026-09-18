/*
 * function: func_02022D70
 * address:  0x02022D70
 * packet:   pkt_02022AD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Blocked: 02022D78 (thumb, from header) has no witness outside 02022D70..02022D78. Every concrete byte reproduces.
 * status:   EXACT
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 * symbols:
 *   func_02022D78  0x02022D78  thumb
 *
 */

extern void func_02022D78(void);

void func_02022D70(void)
{
    func_02022D78();
}
