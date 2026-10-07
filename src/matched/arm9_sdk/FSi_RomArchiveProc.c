/*
 * function: FSi_RomArchiveProc
 * address:  0x0207AA34
 * packet:   pkt_0207AA34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_02075E10 0x02075E10 arm
 *   func_02075E80 0x02075E80 arm
 *   func_0207A980 0x0207A980 arm
 *   g_02150DA0 0x02150DA0 data
 */

#include "../include/G_FSiRomState.h"

typedef unsigned short u16;
extern void func_02075E10(u16 lock_id);
extern void func_02075E80(void);
extern void func_0207A980(void);
extern struct FSiRomState g_02150DA0;

asm int FSi_RomArchiveProc(void *p_file, int cmd)
{
    stmfd sp!, {r3, lr}
    mov r2, r0
    cmp r1, #0xa
    addls pc, pc, r1, lsl #2
    b loc_default

    b loc_default
    b loc_ret4
    b loc_default
    b loc_default
    b loc_default
    b loc_default
    b loc_default
    b case_7
    b loc_default
    b case_9
    b case_10

case_9:
    ldr r0, [pc, #0x5c]
    ldr r0, [r0, #4]
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl func_02075E10
    mov r0, #0
    ldmfd sp!, {r3, pc}

case_10:
    ldr r0, [pc, #0x40]
    ldr r0, [r0, #4]
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl func_02075E80
    mov r0, #0
    ldmfd sp!, {r3, pc}

case_7:
    ldr r0, [r2, #8]
    ldr r1, [r2, #0x30]
    bl func_0207A980
    cmp r0, #0
    movne r0, #9
    ldreq r0, [pc, #0x14]
    ldmfd sp!, {r3, pc}

loc_ret4:
    mov r0, #4
    ldmfd sp!, {r3, pc}

loc_default:
    ldr r0, [pc, #8]
    ldmfd sp!, {r3, pc}

    dcd g_02150DA0
    dcd 0x00000101
    dcd 0x00000102

    mov r0, #4
    cmp r1, #1
    ldrne r0, [pc]
    bx lr
    dcd 0x00000102

    mov r0, #4
    bx lr

    mov r0, #4
    bx lr
}
