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
 *   RtcSendPxiCommand 0x02088F2C arm
 */

typedef unsigned int   u32;
extern int RtcSendPxiCommand(u32 command);
asm void RTCi_ReadRawDateAsync(void)
{
    ldr ip, =RtcSendPxiCommand
    mov r0, #0x11
    bx ip
}
