/*
 * function: OS_GetInitArenaHi
 * address:  0x02086594
 * packet:   pkt_02086594
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02085D3C 0x02085D3C arm
 *   func_02085CBC 0x02085CBC arm
 *   g_02151264 0x02151264 data
 */

extern void func_02085D3C(void);
typedef unsigned int   u32;
extern u32 func_02085CBC(void);
extern int g_02151264;

asm void *OS_GetInitArenaHi(int id)
{
    stmfd sp!, {r4, lr}
    cmp r0, #6
    addls pc, pc, r0, lsl #2
    b loc_default

    b case_0
    b loc_default
    b case_2
    b case_3
    b case_4
    b case_5
    b case_6

case_0:
    bl func_02085D3C
    cmp r0, #0
    movne r0, #0x2f80000
    ldreq r0, [pc, #0xa4]
    ldmfd sp!, {r4, pc}

case_2:
    ldr r0, [pc, #0xa0]
    ldr r0, [r0, #4]
    cmp r0, #0
    moveq r0, #0
    ldmeqfd sp!, {r4, pc}
    bl func_02085CBC
    and r4, r0, #0xf
    bl func_02085D3C
    cmp r0, #0
    mov r0, #0
    beq loc_twl_nitro
    cmp r4, #4
    movne r0, #0xdf00000
    ldmfd sp!, {r4, pc}

loc_twl_nitro:
    cmp r4, #1
    movne r0, #0x2700000
    ldmfd sp!, {r4, pc}

case_3:
    mov r0, #0x2000000
    ldmfd sp!, {r4, pc}

case_4:
    ldr r0, [pc, #0x58]
    ldr r1, [pc, #0x58]
    ldr r2, [pc, #0x58]
    add r3, r0, #0x3f80
    cmp r1, #0
    sub r2, r3, r2
    bne loc_stack_nonzero
    ldr r1, [pc, #0x48]
    cmp r0, r1
    movlo r0, r1
    ldmfd sp!, {r4, pc}

loc_stack_nonzero:
    cmp r1, #0
    ldrlt r0, [pc, #0x34]
    sublt r0, r0, r1
    subge r0, r2, r1
    ldmfd sp!, {r4, pc}

case_5:
    ldr r0, [pc, #0x28]
    ldmfd sp!, {r4, pc}

case_6:
    mov r0, #0x3040000
    ldmfd sp!, {r4, pc}

loc_default:
    mov r0, #0
    ldmfd sp!, {r4, pc}

    dcd 0x023E0000
    dcd g_02151264
    dcd 0x02FE0000
    dcd 0x00001800
    dcd 0x00000800
    dcd 0x02FE00C0
    dcd 0x02FFF680
}
