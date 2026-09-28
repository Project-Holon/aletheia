/*
 * function: func_02082AC0
 * address:  0x02082AC0
 * packet:   pkt_02082AC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   CCERR
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 */

asm void func_02082AC0(void)
{
    push {r4, r5, r6, r7, r8, r9}
    add r9, r1, r2
    lsr ip, r2, #5
    add ip, r1, ip, lsl #5
    mov r2, r0
    mov r3, r2
    mov r4, r2
    mov r5, r2
    mov r6, r2
    mov r7, r2
    mov r8, r2
loc_02082AEC:
    cmp r1, ip
    stmltia r1!, {r0, r2, r3, r4, r5, r6, r7, r8}
    blt loc_02082AEC
loc_02082AF8:
    cmp r1, r9
    stmltia r1!, {r0}
    blt loc_02082AF8
    pop {r4, r5, r6, r7, r8, r9}
    bx lr
}
