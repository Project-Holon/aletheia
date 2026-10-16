/*
 * function: RTCi_ReadRawDateTimeAsync
 * address:  0x02088EEC
 * packet:   pkt_02088EEC
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
asm void RTCi_ReadRawDateTimeAsync(void)
{
    ldr ip, =RtcSendPxiCommand
    mov r0, #0x10
    bx ip
}
