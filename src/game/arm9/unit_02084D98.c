/*
 * file:     unit_02084D98.c
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

typedef signed int     s32;
typedef unsigned short u16;
extern s32 func_02084D78(u16 lockID);

/* hand-written in the original: ldr r1, =target; bx r1 stub, a compiled tail call uses ip */
asm void func_02084D98(int lockID)
{
    ldr r1, =func_02084D78
    bx r1
}
