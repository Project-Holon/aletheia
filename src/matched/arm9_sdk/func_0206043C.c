/*
 * function: func_0206043C
 * address:  0x0206043C
 * packet:   pkt_0205F7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Symbol at this offset is DWC_BACKUPlCheckAddress (libdwcbm dwc_backup.o,
 * dwc_backup.c:534).  No DW_TAG_variable children, only the formal
 * (unsigned char *address): hand-written assembly; kept as an asm body.
 *
 * symbols:
 *   DWC_BACKUPlCheckAddress 0x0206043C arm
 */

asm int func_0206043C(unsigned char *address)
{
    ldrb r0, [r0]
    cmp r0, #0x7f
    moveq r0, #0
    bxeq lr
    cmp r0, #1
    movlo r0, #0
    bxlo lr
    cmp r0, #0xdf
    movls r0, #1
    movhi r0, #0
    bx lr
}
