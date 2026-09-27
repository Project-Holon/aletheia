/*
 * function: RTCi_ReadRawDateAsync
 * address:  0x02088EFC
 * packet:   pkt_02088EFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02088F2C 0x02088F2C arm
 */

extern void func_02088F2C(void);
asm void RTCi_ReadRawDateAsync(void)
{
    ldr ip, =func_02088F2C
    mov r0, #0x11
    bx ip
}
