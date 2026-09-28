/*
 * function: MIi_CpuCopy16
 * address:  0x02082A60
 * packet:   pkt_02082A60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void MIi_CpuCopy16(void)
{
    mov ip, #0
loc_02082A64:
    cmp ip, r2
    ldrlth r3, [r0, ip]
    strlth r3, [r1, ip]
    addlt ip, ip, #2
    blt loc_02082A64
    bx lr
}
