/*
 * unit:     no
 * function: _double_arith_body
 * address:  0x0209C5E0
 * packet:   pkt_0209C5E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PENDING, not filed to the manifest -- see converters.c in this same
 * scratchpad for the leak reason (tools/worklist.py's proven_game
 * short-circuit at a layout/runtime_arm9.txt address; no manifest kind
 * exists for hand-written runtime library code).
 *
 * Shared double add/subtract/multiply significand-alignment kernel: binary
 * long division of the mantissas via a computed shift-and-subtract loop,
 * plus the two `clz`-based renormalise-and-retry tail branches
 * (0x0209C6D8, 0x0209C708) that jump back to 0x0209C600 mid-function.  No
 * cross-entry sharing with the other soft-float routines, but the two
 * internal re-entry branches into its own loop head are still a shape no
 * C source produces.  Three pool words at the end: the double bias
 * 0x7FF00000 / 0x7FF80000 (NaN/Inf highwords) and 0x02153FAC, the
 * FPSCR-like exception status word this routine's tail stores 0x21 into.
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func _double_arith_body
 *     --addr 0x0209C5E0 --cc 1.1p1 --arm
 */

asm void _double_arith_body(void)
{
    stmdb sp!, {r4, r5, r6, lr}
    ldr r2, [pc, #0x184]
    cmp r1, r2
    bhs L_0209C72C
    movs ip, r1, lsr #0x14
    beq L_0209C6D8
    bic r1, r1, r2
    orr r1, r1, #0x100000
L_0209C600:
    movs ip, ip, asr #1
    bhs L_0209C614
    sub ip, ip, #1
    movs r0, r0, lsl #1
    adc r1, r1, r1
L_0209C614:
    movs r3, r0, lsl #1
    adc r1, r1, r1
    mov r2, #0
    mov r4, #0
    mov lr, #0x200000
L_0209C628:
    add r6, r4, lr
    cmp r6, r1
    addle r4, r6, lr
    suble r1, r1, r6
    addle r2, r2, lr
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne L_0209C628
    mov r0, #0
    mov r5, #0
    cmp r1, r4
    cmpeq r3, #0x80000000
    blo L_0209C670
    subs r3, r3, #0x80000000
    sbc r1, r1, r4
    add r4, r4, #1
    mov r0, #0x80000000
L_0209C670:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    mov lr, #0x40000000
L_0209C67C:
    add r6, r5, lr
    cmp r4, r1
    cmpeq r6, r3
    bhi L_0209C69C
    add r5, r6, lr
    subs r3, r3, r6
    sbc r1, r1, r4
    add r0, r0, lr
L_0209C69C:
    movs r3, r3, lsl #1
    adc r1, r1, r1
    movs lr, lr, lsr #1
    bne L_0209C67C
    orrs r1, r1, r3
    biceq r0, r0, #1
    movs r1, r2, lsr #1
    movs r0, r0, rrx
    adcs r0, r0, #0
    adc r1, r1, #0
    add r1, r1, #0x20000000
    sub r1, r1, #0x100000
    add r1, r1, ip, lsl #20
    ldmia sp!, {r4, r5, r6, lr}
    bx lr
L_0209C6D8:
    cmp r1, #0
    bne L_0209C708
    cmp r0, #0
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    mvn ip, #0x13
    clz r5, r0
    movs r0, r0, lsl r5
    sub ip, ip, r5
    mov r1, r0, lsr #0xb
    mov r0, r0, lsl #0x15
    b L_0209C600
L_0209C708:
    clz r2, r1
    movs r1, r1, lsl r2
    rsb r2, r2, #0x2b
    mov r1, r1, lsr #0xb
    orr r1, r1, r0, lsr r2
    rsb r2, r2, #0x20
    mov r0, r0, lsl r2
    rsb ip, r2, #1
    b L_0209C600
L_0209C72C:
    tst r1, #0x80000000
    beq L_0209C748
    bics r3, r1, #0x80000000
    cmpeq r0, #0
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
    b L_0209C754
L_0209C748:
    orrs r2, r0, r1, lsl #12
    ldmeqia sp!, {r4, r5, r6, lr}
    bxeq lr
L_0209C754:
    ldr r2, [pc, #0x18]
    orr r1, r1, r2
    ldr r3, [pc, #0x14]
    mov r4, #0x21
    str r4, [r3]
    ldmia sp!, {r4, r5, r6, lr}
    bx lr

    dcd 0x7FF00000
    dcd 0x7FF80000
    dcd 0x02153FAC
}
