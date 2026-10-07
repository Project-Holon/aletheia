/*
 * function: GX_BeginLoadClearImage
 * address:  0x0207FB2C
 * packet:   pkt_0207FB2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208098C 0x0208098C arm
 *   g_02150E2C 0x02150E2C data
 */

#include "../include/G_GXLoad3DState.h"

extern void func_0208098C(int a0, int a1, int a2, int a3);
extern struct GXLoad3DState g_02150E2C;

asm void GX_BeginLoadClearImage(void)
{
    stmfd sp!, {r3, lr}
    bl func_0208098C
    ldr r1, =g_02150E2C
    cmp r0, #0xc
    str r0, [r1]
    addls pc, pc, r0, lsl #2
    ldmfd sp!, {r3, pc}

    ldmfd sp!, {r3, pc}
    b case_1
    b case_2
    b case_3
    b case_4
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    b case_8
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    ldmfd sp!, {r3, pc}
    b case_12

case_2:
case_3:
    mov r0, #0x06800000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}

case_8:
case_12:
    ldr r0, =0x06840000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}

case_1:
    ldr r0, =0x067E0000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}

case_4:
    ldr r0, =0x06820000
    str r0, [r1, #0x10]
    ldmfd sp!, {r3, pc}
}
