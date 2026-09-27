/*
 * function: CRYPTOi__BN_lshift1
 * address:  0x02078C18
 * packet:   pkt_02078C18
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020789FC 0x020789FC arm
 */

extern void func_020789FC(void);
asm void CRYPTOi__BN_lshift1(void)
{
    ldr ip, =func_020789FC
    mov r2, #1
    bx ip
}
