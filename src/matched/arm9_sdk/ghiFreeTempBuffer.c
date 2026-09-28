/*
 * function: ghiFreeTempBuffer
 * address:  0x020913E8
 * packet:   pkt_020913E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020913A4 0x020913A4 arm
 */

extern void func_020913A4(void);
asm void ghiFreeTempBuffer(void)
{
    stmfd sp!, {r3, lr}
    cmp r0, #0
    ldmeqfd sp!, {r3, pc}
    bl func_020913A4
    ldmfd sp!, {r3, pc}
}
