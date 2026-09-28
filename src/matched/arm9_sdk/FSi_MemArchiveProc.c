/*
 * function: FSi_MemArchiveProc
 * address:  0x0207A7C4
 * packet:   pkt_0207A7C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02078530 0x02078530 arm
 *   func_0208CC78 0x0208CC78 arm
 *   func_0208D7E0 0x0208D7E0 arm
 */

extern void func_02078530(void);
extern void func_0208CC78(void);
extern void func_0208D7E0(void);

asm int FSi_MemArchiveProc(void *p_file, int cmd)
{
    stmfd sp!, {r3, r4, r5, r6, r7, lr}
    mov r6, r0
    cmp r1, #6
    addls pc, pc, r1, lsl #2
    b loc_default

    b loc_default
    b loc_default
    b loc_ret4
    b case_3
    b loc_ret4
    b loc_ret4
    b loc_ret4

case_3:
    ldr r5, [r6, #0x28]
    ldr r4, [r6, #0x30]
    cmp r5, #0
    moveq r0, #0
    streq r0, [r4, #0x10]
    streq r0, [r4, #0xc]
    moveq r0, #1
    ldmeqfd sp!, {r3, r4, r5, r6, r7, pc}
    mov r0, r5
    bl func_02078530
    mov r7, r0
    bl func_0208CC78
    add r0, r0, #1
    str r0, [r4, #0x10]
    mov r0, #1
    str r0, [r4, #0xc]
    ldr r0, [r6, #0x34]
    cmp r0, #0
    bne loc_nonzero
    ldr r1, [pc, #0x40]
    mov r2, r7
    add r0, r4, #0x14
    bl func_0208D7E0
    ldr r1, [r6, #8]
    mov r0, #0
    str r1, [r4]
    strh r0, [r4, #4]
    strh r0, [r4, #6]
    str r0, [r4, #8]

loc_nonzero:
    ldr r1, [r5, #4]
    mov r0, #0
    str r1, [r6, #0x28]
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}

loc_ret4:
    mov r0, #4
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}

loc_default:
    ldr r0, [pc, #4]
    ldmfd sp!, {r3, r4, r5, r6, r7, pc}

    dcd 0x020A84AC
    dcd 0x00000102
}
