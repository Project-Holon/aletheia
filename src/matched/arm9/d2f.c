/*
 * unit:     no
 * function: _d2f
 * address:  0x0209B64C
 * packet:   pkt_0209B64C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Filed as manifest kind `runtime` (tools/match.py): compared at its
 * layout/runtime_arm9.txt row, and worklist.py keeps the row out of the game
 * figure.
 *
 * IEEE-754 binary64 to binary32 conversion (MSL runtime.a `_d2f`), 260
 * bytes, a leaf: sign kept in r2, exponent rebiased by 0x380 (1023 - 127),
 * overflow and Infinity/NaN returned as 0x7F800000 / 0x7FFFFFFF, results
 * below the normal range denormalised through `lsr ip`, round to nearest
 * even on the discarded 32 bits.  0x0209B648 (the word before it) is
 * __dmul's literal (src/matched/arm9/dmul.c), not part of this routine.
 * Identified by the vendor relocations naming `_d2f` at the callers'
 * call sites; see docs/sessions/2026-09-29/reports/w9_f2.md.
 *
 * Verified with:
 *   python tools/match.py one --src <this file> --func _d2f --addr
 *     0x0209B64C --cc 1.1p1 --arm
 */

asm void _d2f(void)
{
    and r2, r1, #0x80000000
    mov ip, r1, lsr #0x14
    bics ip, ip, #0x800
    beq L_0209B6C4
    mov r3, ip, lsl #0x15
    cmn r3, #0x200000
    bhs L_0209B6A8
    subs ip, ip, #0x380
    bls L_0209B6D4
    cmp ip, #0xff
    bge L_0209B744
    mov r1, r1, lsl #0xc
    orr r3, r2, r1, lsr #9
    orr r3, r3, r0, lsr #29
    movs r1, r0, lsl #3
    orr r0, r3, ip, lsl #23
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209B6A8:
    orrs r3, r0, r1, lsl #12
    bne L_0209B6BC
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
L_0209B6BC:
    mvn r0, #0x80000000
    bx lr
L_0209B6C4:
    orrs r3, r0, r1, lsl #12
    bne L_0209B73C
    mov r0, r2
    bx lr
L_0209B6D4:
    cmn ip, #0x17
    beq L_0209B728
    bmi L_0209B73C
    mov r1, r1, lsl #0xb
    orr r1, r1, #0x80000000
    mov r3, r1, lsr #8
    orr r3, r3, r0, lsr #29
    rsb ip, ip, #1
    movs r1, r0, lsl #3
    orr r0, r2, r3, lsr ip
    rsb ip, ip, #0x20
    mov r3, r3, lsl ip
    orrne r3, r3, #1
    movs r1, r3
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
L_0209B728:
    orr r0, r0, r1, lsl #12
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
L_0209B73C:
    mov r0, r2
    bx lr
L_0209B744:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
}
