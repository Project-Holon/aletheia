/*
 * function: func_02084D98
 * address:  0x02084D98
 * packet:   pkt_02084D98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * note:     hand-written SDK asm stub: `ldr r1, =target; bx r1` (a compiled
 *           tail call spends ip in ARM, never r1), wave 17 lane untried_small
 *
 * symbols:
 *   func_02084D78  0x02084D78  arm
 */

extern void func_02084D78(int a);

asm void func_02084D98(int a)
{
    ldr r1, =func_02084D78
    bx r1
}
