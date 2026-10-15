/*
 * function: OS_UnLockCartridge
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
 *   OS_UnlockCartridge  0x02084D78  arm
 */

typedef signed int     s32;
typedef unsigned short u16;
extern s32 OS_UnlockCartridge(u16 lockID);

asm void OS_UnLockCartridge(int a)
{
    ldr r1, =OS_UnlockCartridge
    bx r1
}
