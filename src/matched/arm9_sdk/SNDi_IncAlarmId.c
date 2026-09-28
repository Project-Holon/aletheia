/*
 * function: SNDi_IncAlarmId
 * address:  0x02089FC0
 * packet:   pkt_02089FC0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02152F40 0x02152F40 data
 */

extern void g_02152F40(void);

asm void SNDi_IncAlarmId(void)
{
    ldr r2, =g_02152F40
    mov	r1, #0xc
    mla	r1, r0, r1, r2
    ldrb	r0, [r1, #8]
    add	r0, r0, #1
    strb	r0, [r1, #8]
    bx	lr
}
