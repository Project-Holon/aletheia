/*
 * function: CAMERA_I2CContextSwitchAsyncCore
 * address:  0x02700DF0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   CAMERA_CheckRetryCount  0x027007C8  arm twl a2
 *   func_02087988  0x02087988  arm twl a2
 *   func_0208799C  0x0208799C  arm twl a2
 *   CameraSendPxiCommand  0x027019B4  arm twl a2
 *   CameraSendPxiData  0x02701A60  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC8[];
extern u32 data_02733FC8[];
extern u32 CAMERA_CheckRetryCount(void);
extern void func_02087988(void);
extern void func_0208799C(void);
extern u32 CameraSendPxiCommand(u32, u32, u32);
extern void CameraSendPxiData(u32);

asm void CAMERA_I2CContextSwitchAsyncCore(u32 a0, u32 a1, u32 a2, u32 a3) {
    stmdb sp!, {r3, r4, r5, r6, r7, r8, sb, lr}
    mov r7, r0
    mov r6, r1
    mov r5, r2
    mov r4, r3
    bl CAMERA_CheckRetryCount
    mov sb, r0
    cmp sb, #7
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r7, #1
    cmpne r7, #2
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    cmp r6, #1
    cmpne r6, #2
    movne r0, #3
    ldmnefd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    bl func_02087988
    ldr r8, =data_02732FC8
    ldr r1, [r8]
    cmp r1, #0
    beq @lbl_02700E5C
    bl func_0208799C
    mov r0, #6
    cmp sb, #6
    movne r0, #2
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
@lbl_02700E5C:
    mov r1, #1
    str r1, [r8]
    bl func_0208799C
    str r5, [r8, #4]
    ldr r0, =data_02733FC8
    str r4, [r8, #0xc]
    strb r7, [sp]
    strb r6, [sp, #1]
    str r7, [r0, #0x1a0]
    str r6, [r0, #0x1a8]
    ldrb r2, [sp]
    mov r0, #0x12
    mov r1, #2
    bl CameraSendPxiCommand
    cmp r0, #0
    moveq r0, #4
    ldmeqfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
    add r0, sp, #1
    bl CameraSendPxiData
    mov r0, #0
    ldmfd sp!, {r3, r4, r5, r6, r7, r8, sb, pc}
}
