/*
 * file:     unit_027026DC.c
 * unit:     yes
 * function: func_027026DC, func_027026EC, func_02702740, func_027028B0, func_027028E4
 * address:  0x027026DC
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   data_027341A4  0x027341A4  data twl a2
 *   func_020862B8  0x020862B8  code twl a2
 *   func_020862D4  0x020862D4  code twl a2
 *   DAT_027341a4   0x027341a4  data twl
 *   func_02702A78  0x02702A78  arm twl
 *   func_02731590  0x02731590  arm twl
 *   DAT_027341a8   0x027341a8  data twl
 *   func_02082BCC  0x02082BCC  arm twl
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

extern void func_020862B8(u32, u32);
extern void func_020862D4(u32, u32);
extern void func_02702A78(void);
extern void func_02731590(u32);
extern void func_02082BCC(u32, u32, u32);
u32 func_027026DC(void);
void func_027026EC(void);
asm void func_02702740(u32 a0, u32 a1, u32 a2);
u32 func_027028B0(void);
asm void func_027028E4(void);
extern u32 data_027341A4[];
extern u32 DAT_027341a4[];
extern u32 DAT_027341a8[];




u32 func_027026DC(void) {
    return data_027341A4[0];
}




void func_027026EC(void) {
    u8 val;
    u8 *r5;
    u32 r4;
    u32 base = data_027341A4[0];
    if (base != 0) {
        r5 = (u8 *)*(u32 *)(base + 0x2274);
        r4 = 1;
        func_020862B8((u32)r5, r4);
        val = r5[0];
        if (val & 1) {
            r5[0] = val & 0xFE;
            func_020862D4((u32)r5, r4);
        }
    }
}



asm void func_02702740(u32 a0, u32 a1, u32 a2) {
    stmdb sp!, {r4, r5, r6, lr}
    ldr r0, =DAT_027341a4
    mov r5, r1
    ldr r4, [r0]
    cmp r4, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    cmp r2, #0
    ldmnefd sp!, {r4, r5, r6, pc}
    cmp r5, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    ldrh r0, [r5]
    cmp r0, #0x14
    ldmhsfd sp!, {r4, r5, r6, pc}
    add r0, r4, #0x2000
    mov r6, #0x100
    ldr r0, [r0, #0x27c]
    mov r1, r6
    bl func_020862B8
    add r0, r4, #0x2000
    ldr r0, [r0, #0x278]
    mov r1, #0xc0
    bl func_020862B8
    add r0, r4, #0x2000
    ldr r0, [r0, #0x27c]
    cmp r5, r0
    beq @lbl_027027B4
    mov r0, r5
    mov r1, r6
    bl func_020862B8
@lbl_027027B4:
    ldrh r1, [r5]
    cmp r1, #3
    bne @lbl_027027CC
    ldrh r0, [r5, #2]
    cmp r0, #0
    bne @lbl_027027E4
@lbl_027027CC:
    cmp r1, #4
@dcd1:
    dcd 0x01d500b2
@dcd2:
    dcd 0x03500000
    beq @lbl_027027E4
    cmp r1, #0x13
    bne @lbl_027027E8
@lbl_027027E4:
    bl func_02702A78
@lbl_027027E8:
    ldrh r0, [r5]
    cmp r0, #0xb
    bne @lbl_02702810
    ldrh r0, [r5, #2]
    cmp r0, #0xc
@dcd3:
    dcd 0x15951004
@dcd4:
    dcd 0x13510000
    beq @lbl_02702810
    mov r0, r5
    blx r1
@lbl_02702810:
    ldrh r0, [r5]
    cmp r0, #0xb
    beq @lbl_02702878
    cmp r0, #4
    cmpne r0, #0x13
    beq @lbl_0270283C
    cmp r0, #3
    bne @lbl_02702844
    ldrh r0, [r5, #2]
    cmp r0, #0
    beq @lbl_02702844
@lbl_0270283C:
    ldr r0, =DAT_027341a8
    bl func_02731590
@lbl_02702844:
    ldrh r1, [r5]
    add r0, r4, r1, lsl #2
    add r0, r0, #0x2000
    cmp r1, #7
    ldr r6, [r0, #0x284]
    bne @lbl_02702868
    ldr r0, [r5, #0x10]
    ldr r1, [r5, #0xc]
    bl func_020862B8
@lbl_02702868:
    cmp r6, #0
    beq @lbl_02702878
    mov r0, r5
    blx r6
@lbl_02702878:
    mov r6, #0x100
    mov r0, r5
    mov r2, r6
    mov r1, #0
    bl func_02082BCC
    mov r0, r5
    mov r1, r6
    bl func_020862D4
    cmp r4, #0
    ldmeqfd sp!, {r4, r5, r6, pc}
    bl func_027026EC
    ldmfd sp!, {r4, r5, r6, pc}
}



u32 func_027028B0(void) {
    u32 base = func_027026DC();
    u32 r1 = 0;
    if (base != 0) {
        u32 ptr = *(u32 *)(base + 0x2278);
        func_020862B8(ptr, 2);
        r1 = *(u16 *)(ptr + 0x24);
    }
    return r1;
}


asm void func_027028E4(void) {
    stmdb sp!, {r0, r1, r2, r3}
}
