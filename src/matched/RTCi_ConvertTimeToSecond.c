/*
 * function: RTCi_ConvertTimeToSecond
 * address:  0x02088FEC
 * packet:   pkt_02088FEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

asm void RTCi_ConvertTimeToSecond(void)
{
    mov r1, #0x3c
    ldmia r0, {r2, r3}
    mla r3, r2, r1, r3
    ldr r0, [r0, #8]
    mla r0, r3, r1, r0
    bx lr
}
