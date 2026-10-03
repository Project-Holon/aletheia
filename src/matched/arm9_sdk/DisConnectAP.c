/*
 * function: DisConnectAP
 * address:  0x0205B264
 * packet:   pkt_0205B264
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021656A0 0x021656A0 arm
 *   func_02164EE0 0x02164EE0 arm
 *   func_02165088 0x02165088 arm
 *   func_02165204 0x02165204 arm
 *   func_02165478 0x02165478 arm
 *   func_02165560 0x02165560 arm
 *   func_0205C2E4 0x0205C2E4 arm
 */

extern void func_021656A0(void);
extern void func_02164EE0(void);
extern void func_02165088(void);
extern void func_02165204(void);
extern void func_02165478(void);
extern void func_02165560(void);
extern void func_0205C2E4(int error);

asm int DisConnectAP(void)
{
    stmfd sp!, {r4, lr}
    bl func_021656A0
    cmp r0, #0xc
    addls pc, pc, r0, lsl #2
    b loc_default

    b case_0
    b case_1
    b loc_default
    b case_3
    b loc_default
    b loc_default
    b case_6
    b loc_default
    b loc_default
    b case_9
    b loc_default
    b case_11
    b case_12

case_0:
    mov r0, #1
    ldmfd sp!, {r4, pc}

case_1:
    bl func_02164EE0
    b loc_default

case_3:
    bl func_02165088
    b loc_default

case_6:
    bl func_02165204
    b loc_default

case_9:
    bl func_02165478
    b loc_default

case_12:
    bl func_02165560
    b loc_default

case_11:
    mov r4, #0
    mov r0, r4
    bl func_0205C2E4
    sub r0, r4, #1
    ldmfd sp!, {r4, pc}

loc_default:
    mov r0, #0
    ldmfd sp!, {r4, pc}
}
