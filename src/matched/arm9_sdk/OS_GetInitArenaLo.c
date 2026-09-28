/*
 * function: OS_GetInitArenaLo
 * address:  0x02086694
 * packet:   pkt_02086694
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
extern void func_02085CBC(void);
extern int g_02151264;

asm void *OS_GetInitArenaLo(int id)
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
    ldrne r0, [pc, #0x70]
    ldreq r0, [pc, #0x70]
    ldmfd sp!, {r4, pc}

case_2:
    ldr r0, [pc, #0x6c]
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
    ldrne r0, [pc, #0x40]
    ldmfd sp!, {r4, pc}

loc_twl_nitro:
    cmp r4, #1
    ldrne r0, [pc, #0x38]
    ldmfd sp!, {r4, pc}

case_3:
    ldr r0, [pc, #0x34]
    ldmfd sp!, {r4, pc}

case_4:
    ldr r0, [pc, #0x30]
    ldmfd sp!, {r4, pc}

case_5:
    ldr r0, [pc, #0x2c]
    ldmfd sp!, {r4, pc}

case_6:
    mov r0, #0x3040000
    ldmfd sp!, {r4, pc}

loc_default:
    mov r0, #0
    ldmfd sp!, {r4, pc}

    dcd 0x02735B40
    dcd 0x02213D20
    dcd g_02151264
    dcd 0x0D000000
    dcd 0x02400060
    dcd 0x01FF8820
    dcd 0x02FE00C0
    dcd 0x02FFF000
}
