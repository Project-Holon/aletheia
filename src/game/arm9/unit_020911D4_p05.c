/*
 * unit:     yes
 * function: _s32_to_float, _u32_to_float, _f2s, _f2u, _d2s, _d2u,
 *           _s32_to_double, _u32_to_double, _f2d
 * address:  0x0209BDBC
 * packet:   pkt_0209BDBC_converters
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * verdict:  EXACT per function (tools/match.py one, 9 of 9 re-run in round 4).
 *           tools/match.py tu reports DIFF for this file because its members are
 *           scattered over 0x0209B750..0x0209C554 with other parts between them.
 *
 * Filed as manifest kind `runtime` (tools/match.py): each function is
 * compared at its layout/runtime_arm9.txt row, and worklist.py keeps the
 * rows out of the game figure.
 *
 * Each function below is independently leaf code (no shared bodies, no
 * cross-entry branches), verified with:
 *   python tools/match.py one --src <this file> --func <name> --addr <addr>
 *     --cc 1.1p1 --arm
 *
 * _d2s and _d2u each carry one literal-pool word (the double exponent bias,
 * 0x41E and 0x43E) inside their own byte extent; kept as `ldr rd, [pc,
 * #imm]` with an explicit dcd word at the end, exactly as the existing
 * asm-block precedent (src/matched/OS_GetInitArenaHi.c) does.
 */

asm void _s32_to_float(void)
{
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    bxeq lr
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #0x9e
    ands r1, r0, #0xff
    add r0, r0, r0
    orr r0, r2, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r1, #0x80
    bxeq lr
    ands r3, r1, #0x7f
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
}

asm void _u32_to_float(void)
{
    cmp r0, #0
    bxeq lr
    mov r3, #0x9e
    bmi L_0209BE20
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
L_0209BE20:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
}

asm void _f2s(void)
{
    bic r1, r0, #0x80000000
    mov r2, #0x9e
    subs r2, r2, r1, lsr #23
    ble L_0209C4BC
    mov r1, r1, lsl #8
    orr r1, r1, #0x80000000
    cmp r0, #0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0
    bx lr
L_0209C4BC:
    mvn r0, r0, asr #31
    add r0, r0, #0x80000000
    bx lr
}

asm void _f2u(void)
{
    tst r0, #0x80000000
    bne L_0209C4EC
    mov r1, #0x9e
    subs r1, r1, r0, lsr #23
    blt L_0209C500
    mov r2, r0, lsl #8
    orr r0, r2, #0x80000000
    mov r0, r0, lsr r1
    bx lr
L_0209C4EC:
    mov r2, #0xff000000
    cmp r2, r0, lsl #1
    movhs r0, #0
    mvnlo r0, #0
    bx lr
L_0209C500:
    mvn r0, #0
    bx lr
}

asm void _d2s(void)
{
    bic r3, r1, #0x80000000
    ldr r2, [pc, #0x3c]
    subs r2, r2, r3, lsr #20
    ble L_0209C544
    cmp r2, #0x20
    bge L_0209C53C
    mov r3, r1, lsl #0xb
    orr r3, r3, #0x80000000
    orr r3, r3, r0, lsr #21
    cmp r1, #0
    mov r0, r3, lsr r2
    rsbmi r0, r0, #0
    bx lr
L_0209C53C:
    mov r0, #0
    bx lr
L_0209C544:
    mvn r0, r1, asr #31
    add r0, r0, #0x80000000
    bx lr
    dcd 0x0000041E
}

asm void _d2u(void)
{
    tst r1, #0x80000000
    bne L_0209C5B8
    ldr r2, [pc, #0x78]
    subs r2, r2, r1, lsr #20
    blt L_0209C5D0
    cmp r2, #0x40
    bge L_0209C5AC
    mov ip, r1, lsl #0xb
    orr ip, ip, #0x80000000
    orr ip, ip, r0, lsr #21
    cmp r2, #0x20
    ble L_0209C594
    sub r2, r2, #0x20
    mov r1, #0
    mov r0, ip, lsr r2
    bx lr
L_0209C594:
    mov r3, r0, lsl #0xb
    mov r1, ip, lsr r2
    mov r0, r3, lsr r2
    rsb r2, r2, #0x20
    orr r0, r0, ip, lsl r2
    bx lr
L_0209C5AC:
    mov r1, #0
    mov r0, #0
    bx lr
L_0209C5B8:
    cmn r1, #0x100000
    cmpeq r0, #0
    bhi L_0209C5D0
    mov r1, #0
    mov r0, #0
    bx lr
L_0209C5D0:
    mvn r1, #0
    mvn r0, #0
    bx lr
    dcd 0x0000043E
}

asm void _s32_to_double(void)
{
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #0x1e
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
    movs r1, r0
    mov r0, r1, lsl #0x15
    add r1, r1, r1
    orr r1, r2, r1, lsr #12
    orr r1, r1, r3, lsl #20
    bx lr
}

asm void _u32_to_double(void)
{
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #0x1e
    bmi L_0209B7B4
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
L_0209B7B4:
    mov r1, r0
    mov r0, r1, lsl #0x15
    add r1, r1, r1
    mov r1, r1, lsr #0xc
    orr r1, r1, r3, lsl #20
    bx lr
}

asm void _f2d(void)
{
    and r2, r0, #0x80000000
    mov ip, r0, lsr #0x17
    mov r3, r0, lsl #9
    ands ip, ip, #0xff
    beq L_0209BD68
    cmp ip, #0xff
    beq L_0209BD94
L_0209BD54:
    add ip, ip, #0x380
    mov r0, r3, lsl #0x14
    orr r1, r2, r3, lsr #12
    orr r1, r1, ip, lsl #20
    bx lr
L_0209BD68:
    cmp r3, #0
    bne L_0209BD7C
    mov r1, r2
    mov r0, #0
    bx lr
L_0209BD7C:
    mov r3, r3, lsr #1
    clz ip, r3
    movs r3, r3, lsl ip
    rsb ip, ip, #1
    add r3, r3, r3
    b L_0209BD54
L_0209BD94:
    cmp r3, #0
    bhi L_0209BDAC
    ldr r1, [pc, #0x14]
    orr r1, r1, r2
    mov r0, #0
    bx lr
L_0209BDAC:
    mvn r0, #0
    bic r1, r0, #0x80000000
    bx lr
    dcd 0x7FF00000
}
