/*
 * function: MIi_CpuClear16
 * address:  0x02082A48
 * packet:   pkt_02082A48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void MIi_CpuClear16(void)
{
    mov r3, #0
loc_02082A4C:
    cmp r3, r2
    strlth r0, [r1, r3]
    addlt r3, r3, #2
    blt loc_02082A4C
    bx lr
}
