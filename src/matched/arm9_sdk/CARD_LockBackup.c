/*
 * function: CARD_LockBackup
 * address:  0x02075E9C
 * packet:   pkt_02075E9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CARDi_LockResource 0x02075ED4 arm
 */

typedef signed int     s32;
extern void CARDi_LockResource(s32 owner, int target);
asm void CARD_LockBackup(void)
{
    ldr ip, =CARDi_LockResource
    mov r1, #2
    bx ip
}
