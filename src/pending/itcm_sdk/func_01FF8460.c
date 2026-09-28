/*
 * function: func_01FF8460
 * address:  0x01FF8460
 * packet:   itcm
 * region:   arm9_autoload0_ITCM
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_01FF852C    0x01FF852C  arm
 */

typedef unsigned int u32;

extern void func_01FF852C(u32, void *, u32);

asm void func_01FF8460(void)
{
    mov ip, #0x4000000
    str ip, [ip, #0x208]
    ldr r1, =0x02FE0000
    add r1, r1, #0x3fc0
    add r1, r1, #0x3c
    mov r0, #0
    str r0, [r1]
    ldr r1, =0x04000180
_loop1:
    ldrh r0, [r1]
    and r0, r0, #0xf
    cmp r0, #1
    bne _loop1
    mov r0, #0x100
    strh r0, [r1]
    mov r0, #0
    ldr r3, =0x02FFFD9C
    ldr r4, [r3]
    ldr r1, =0x02FFFD80
    mov r2, #0x80
    bl func_01FF852C
    str r4, [r3]
    ldr r1, =0x02FFFF80
    mov r2, #0x18
    bl func_01FF852C
    ldr r1, =0x02FFFF98
    strh r0, [r1]
    ldr r1, =0x02FFFF9C
    mov r2, #0x64
    bl func_01FF852C
    ldr r1, =0x04000180
_loop2:
    ldrh r0, [r1]
    and r0, r0, #0xf
    cmp r0, #1
    beq _loop2
    mov r0, #0
    strh r0, [r1]
    ldr r3, =0x02FFFE00
    ldr ip, [r3, #0x24]
    mov lr, ip
    ldr r11, =0x02FFFF80
    ldmia r11, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10}
    mov r11, #0
    bx ip
}
