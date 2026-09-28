/*
 * function: func_02700230
 * address:  0x02700230
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02733FC8  0x02733FC8  data twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 */

typedef unsigned int u32;

extern u32 data_02733FC8[];
extern u32 data_02732FC8[];

extern void func_02085D3C(void);
extern void func_02700128(void);
extern void func_02700168(void);
extern void func_027001B8(void);
extern void func_02700C18(void);
extern void func_02700CEC(void);
extern void func_02700DF0(void);
extern void func_02700EB8(void);
extern void func_02701020(void);
extern void func_02701120(void);
extern void func_02701284(void);
extern void func_027013A4(void);
extern void func_02701488(void);
extern void func_02701570(void);
extern void func_02701644(void);
extern void func_02701718(void);
extern void func_02701814(void);
extern void func_02701940(void);

asm void func_02700230(u32 a0, u32 a1) {
    stmdb sp!, {r3, r4, r5, lr}
    ldr r4, [pc, #0x580]
    cmp r0, #0
    ldmnefd sp!, {r3, r4, r5, pc}
    cmp r1, #0x1e
    addls pc, pc, r1, lsl #2
    b @lbl_0270079C
    b @lbl_027002C8
    b @lbl_027002DC
    b @lbl_027002FC
    b @lbl_0270031C
    b @lbl_02700348
    b @lbl_02700374
    b @lbl_027003A0
    b @lbl_027003CC
    b @lbl_027003EC
    b @lbl_0270040C
    b @lbl_02700438
    b @lbl_02700464
    b @lbl_02700490
    b @lbl_027004BC
    b @lbl_027004E8
    b @lbl_02700514
    b @lbl_02700540
    b @lbl_0270056C
    b @lbl_02700594
    b @lbl_027005BC
    b @lbl_027005E8
    b @lbl_02700614
    b @lbl_02700640
    b @lbl_0270066C
    b @lbl_0270068C
    b @lbl_027006AC
    b @lbl_027006CC
    b @lbl_027006EC
    b @lbl_0270071C
    b @lbl_0270074C
    b @lbl_02700768
@lbl_027002C8:
    ldr r1, [pc, #0x4f0]
    mov r0, #3
    mov r2, #1
    bl func_02700C18
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027002DC:
    ldr r1, [r4, #0x140]
    cmp r1, #1
    beq @lbl_027002FC
    ldr r2, [pc, #0x4d0]
    mov r0, #1
    mov r3, #2
    bl func_027013A4
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027002FC:
    ldr r1, [r4, #0x17c]
    cmp r1, #0
    beq @lbl_0270031C
    ldr r2, [pc, #0x4b0]
    mov r0, #2
    mov r3, #3
    bl func_027013A4
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270031C:
    ldr r0, [r4, #0x128]
    cmp r0, #5
    beq @lbl_02700348
    mov r0, #4
    str r0, [sp]
    mov r0, #1
    ldr r2, [r4, #0x128]
    ldr r3, [pc, #0x480]
    mov r1, r0
    bl func_02700EB8
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700348:
    ldr r0, [r4, #0x12c]
    cmp r0, #0
    beq @lbl_02700374
    mov r0, #5
    str r0, [sp]
    ldr r2, [r4, #0x12c]
    ldr r3, [pc, #0x458]
    mov r0, #1
    mov r1, #2
    bl func_02700EB8
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700374:
    ldr r0, [r4, #0x164]
    cmp r0, #5
    beq @lbl_027003A0
    mov r0, #6
    str r0, [sp]
    ldr r2, [r4, #0x164]
    ldr r3, [pc, #0x42c]
    mov r0, #2
    mov r1, #1
    bl func_02700EB8
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027003A0:
    ldr r0, [r4, #0x168]
    cmp r0, #0
    beq @lbl_027003CC
    mov r0, #7
    str r0, [sp]
    mov r0, #2
    ldr r2, [r4, #0x168]
    ldr r3, [pc, #0x3fc]
    mov r1, r0
    bl func_02700EB8
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027003CC:
    ldr r1, [r4, #0x148]
    cmp r1, #0
    beq @lbl_027003EC
    ldr r2, [pc, #0x3e0]
    mov r0, #1
    mov r3, #8
    bl func_02701020
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027003EC:
    ldr r1, [r4, #0x184]
    cmp r1, #0
    beq @lbl_0270040C
    ldr r2, [pc, #0x3c0]
    mov r0, #2
    mov r3, #9
    bl func_02701020
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270040C:
    ldr r0, [r4, #0x130]
    cmp r0, #0
    beq @lbl_02700438
    mov r0, #0xa
    str r0, [sp]
    mov r0, #1
    ldr r2, [r4, #0x130]
    ldr r3, [pc, #0x390]
    mov r1, r0
    bl func_02701120
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700438:
    ldr r0, [r4, #0x134]
    cmp r0, #0
    beq @lbl_02700464
    mov r0, #0xb
    str r0, [sp]
    ldr r2, [r4, #0x134]
    ldr r3, [pc, #0x368]
    mov r0, #1
    mov r1, #2
    bl func_02701120
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700464:
    ldr r0, [r4, #0x16c]
    cmp r0, #0
    beq @lbl_02700490
    mov r0, #0xc
    str r0, [sp]
    ldr r2, [r4, #0x16c]
    ldr r3, [pc, #0x33c]
    mov r0, #2
    mov r1, #1
    bl func_02701120
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700490:
    ldr r0, [r4, #0x170]
    cmp r0, #0
    beq @lbl_027004BC
    mov r0, #0xd
    str r0, [sp]
    mov r0, #2
    ldr r2, [r4, #0x170]
    ldr r3, [pc, #0x30c]
    mov r1, r0
    bl func_02701120
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027004BC:
    ldr r0, [r4, #0x138]
    cmp r0, #2
    beq @lbl_027004E8
    mov r0, #0xe
    str r0, [sp]
    mov r0, #1
    ldr r2, [r4, #0x138]
    ldr r3, [pc, #0x2e0]
    mov r1, r0
    bl func_02701284
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027004E8:
    ldr r0, [r4, #0x13c]
    cmp r0, #2
    beq @lbl_02700514
    mov r0, #0xf
    str r0, [sp]
    ldr r2, [r4, #0x13c]
    ldr r3, [pc, #0x2b8]
    mov r0, #1
    mov r1, #2
    bl func_02701284
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700514:
    ldr r0, [r4, #0x174]
    cmp r0, #0
    beq @lbl_02700540
    mov r0, #0x10
    str r0, [sp]
    ldr r2, [r4, #0x174]
    ldr r3, [pc, #0x28c]
    mov r0, #2
    mov r1, #1
    bl func_02701284
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700540:
    ldr r0, [r4, #0x178]
    cmp r0, #0
    beq @lbl_0270056C
    mov r0, #0x11
    str r0, [sp]
    mov r0, #2
    ldr r2, [r4, #0x178]
    ldr r3, [pc, #0x25c]
    mov r1, r0
    bl func_02701284
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270056C:
    ldr r0, [r4, #0x140]
    bl func_02700128
    ldr r1, [r4, #0x144]
    cmp r1, r0
    beq @lbl_02700594
    ldr r2, [pc, #0x238]
    mov r0, #1
    mov r3, #0x12
    bl func_02701488
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700594:
    ldr r0, [r4, #0x17c]
    bl func_02700128
    ldr r1, [r4, #0x180]
    cmp r1, r0
    beq @lbl_027005BC
    ldr r2, [pc, #0x210]
    mov r0, #2
    mov r3, #0x13
    bl func_02701488
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027005BC:
    ldr r5, [r4, #0x14c]
    ldr r0, [r4, #0x140]
    bl func_027001B8
    cmp r5, r0
    beq @lbl_027005E8
    ldr r2, [pc, #0x1e8]
    mov r1, r5
    mov r0, #1
    mov r3, #0x14
    bl func_02701570
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027005E8:
    ldr r5, [r4, #0x188]
    ldr r0, [r4, #0x17c]
    bl func_027001B8
    cmp r5, r0
    beq @lbl_02700614
    ldr r2, [pc, #0x1bc]
    mov r1, r5
    mov r0, #2
    mov r3, #0x15
    bl func_02701570
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700614:
    ldr r5, [r4, #0x150]
    ldr r0, [r4, #0x140]
    bl func_02700168
    cmp r5, r0
    beq @lbl_02700640
    ldr r2, [pc, #0x190]
    mov r1, r5
    mov r0, #1
    mov r3, #0x16
    bl func_02701644
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700640:
    ldr r5, [r4, #0x18c]
    ldr r0, [r4, #0x17c]
    bl func_02700168
    cmp r5, r0
    beq @lbl_0270066C
    ldr r2, [pc, #0x164]
    mov r1, r5
    mov r0, #2
    mov r3, #0x17
    bl func_02701644
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270066C:
    ldr r1, [r4, #0x154]
    cmp r1, #1
    beq @lbl_0270068C
    ldr r2, [pc, #0x140]
    mov r0, #1
    mov r3, #0x18
    bl func_02701718
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270068C:
    ldr r1, [r4, #0x190]
    cmp r1, #1
    beq @lbl_027006AC
    ldr r2, [pc, #0x120]
    mov r0, #2
    mov r3, #0x19
    bl func_02701718
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027006AC:
    ldr r1, [r4, #0x158]
    cmp r1, #1
    beq @lbl_027006CC
    ldr r2, [pc, #0x100]
    mov r0, #1
    mov r3, #0x1a
    bl func_02701814
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027006CC:
    ldr r1, [r4, #0x194]
    cmp r1, #1
    beq @lbl_027006EC
    ldr r2, [pc, #0xe0]
    mov r0, #2
    mov r3, #0x1b
    bl func_02701814
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_027006EC:
    ldr r5, [r4, #0x15c]
    cmp r5, #1
    beq @lbl_0270071C
    bl func_02085D3C
    cmp r0, #1
    ldmnefd sp!, {r3, r4, r5, pc}
    ldr r2, [pc, #0xb4]
    mov r1, r5
    mov r0, #1
    mov r3, #0x1c
    bl func_02700DF0
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270071C:
    ldr r5, [r4, #0x198]
    cmp r5, #1
    beq @lbl_0270074C
    bl func_02085D3C
    cmp r0, #1
    ldmnefd sp!, {r3, r4, r5, pc}
    ldr r2, [pc, #0x84]
    mov r1, r5
    mov r0, #2
    mov r3, #0x1d
    bl func_02700DF0
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270074C:
    ldr r0, [r4, #0x124]
    cmp r0, #0
    beq @lbl_02700768
    ldr r1, [pc, #0x60]
    mov r2, #0x1e
    bl func_02700CEC
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_02700768:
    ldr r0, [r4, #0x124]
    cmp r0, #2
    ldreq r0, [r4, #0x19c]
    cmpeq r0, #1
    bne @lbl_0270079C
    bl func_02085D3C
    cmp r0, #1
    ldmnefd sp!, {r3, r4, r5, pc}
    ldr r1, [pc, #0x30]
    mov r0, #1
    mov r2, #0x1f
    bl func_02701940
    ldmfd sp!, {r3, r4, r5, pc}
@lbl_0270079C:
    mov r0, #0
    ldr r1, [pc, #0x1c]
    str r0, [r4, #0x1ac]
    ldr r1, [r1, #0x60]
    cmp r1, #0
    ldmeqfd sp!, {r3, r4, r5, pc}
    blx r1
    ldmfd sp!, {r3, r4, r5, pc}
    dcd data_02733FC8
    dcd 0x02700230
    dcd data_02732FC8
}