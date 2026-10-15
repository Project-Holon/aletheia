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
 *   CARD_LockRom 0x02075E10 arm
 *   CARD_UnlockRom 0x02075E80 arm
 *   FSi_IsUnreadableRomOffset 0x0207A980 arm
 *   fsi_default_dma_no 0x02150DA0 data
 */

#include "../include/G_FSiRomState.h"

typedef unsigned short u16;
extern void CARD_LockRom(u16 lock_id);
extern void CARD_UnlockRom(void);
extern void FSi_IsUnreadableRomOffset(void);
extern struct FSiRomState fsi_default_dma_no;

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
    bl CARD_LockRom
    mov r0, #0
    ldmfd sp!, {r3, pc}

case_10:
    ldr r0, [pc, #0x40]
    ldr r0, [r0, #4]
    mov r0, r0, lsl #0x10
    mov r0, r0, lsr #0x10
    bl CARD_UnlockRom
    mov r0, #0
    ldmfd sp!, {r3, pc}

case_7:
    ldr r0, [r2, #8]
    ldr r1, [r2, #0x30]
    bl FSi_IsUnreadableRomOffset
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

    dcd fsi_default_dma_no
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
