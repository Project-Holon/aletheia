/*
 * file:     unit_02731718_p06.c
 * unit:     yes
 * function: func_02732B70, func_02732CAC
 * address:  0x02732B70
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_021656D0  0x021656D0  arm  ov009
 *   func_02165918  0x02165918  arm  ov009
 *   func_02702998  0x02702998  arm  twl
 *   MI_CpuCopy8    0x02082D44  arm
 *   data_021A1988  0x021A1988  data ov009 a4
 *   data_021A1990  0x021A1990  data ov009 a4
 *   func_02166378    0x02166378  arm  ov009
 *   func_02165AF4    0x02165AF4  arm  ov009
 *   OS_WakeupThread  0x02085800  arm
 */
typedef unsigned int u32;

extern int func_021657C8(void);
extern unsigned long func_021656D0(unsigned long option);
extern unsigned short func_02165918(unsigned short channel);
extern u32 func_02702998(u32 a);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *func_02166378(void);
extern void func_02165AF4(void);
extern void OS_WakeupThread(void *queue);
asm void func_02732B70(void *a, void *b, u32 c);
asm void func_02732CAC(void *arg);
extern void *data_021A1988;
extern void *data_021A1990;


asm void func_02732B70(void *a, void *b, u32 c)
{
    stmdb   sp!, {r3, r4, r5, r6, r7, lr}
    mov     r4, r2
    mov     r7, r0
    mov     r6, r1
    bl      func_021657C8
    mov     r5, r0
    mov     r0, r4
    bl      func_021656D0
    mov     r4, #0
    add     r2, r5, #0x600
    add     r1, r5, #0x4000
    str     r2, [r1, #0x3a0]
    mov     r0, r4
    add     r1, r5, #0x4300
    mov     r2, #0xc40
    strh    r2, [r1, #0xa4]
    bl      func_02165918
    mov     r2, #1
    mov     r0, r2, lsl r0
    mov     r1, r0, asr #1
    add     r0, r5, #0x4300
    strh    r1, [r0, #0xa6]
    add     r0, r5, #0x1000
    ldr     r0, [r0, #0x2d4]
    add     r1, r5, #0x4300
    and     r0, r0, #0x300000
    cmp     r0, #0x300000
    movne   r2, r4
    strh    r2, [r1, #0xaa]
    add     r0, r5, #0x1200
    ldrh    r0, [r0, #0xd8]
    cmp     r0, #0
    bne     @loc_02732BFC
    ldrh    r0, [r1, #0xaa]
    bl      func_02702998

@loc_02732BFC:
    add     r1, r5, #0x4300
    strh    r0, [r1, #0xa8]
    cmp     r7, #0
    add     r1, r5, #0x3ac
    mov     r2, #6
    bne     @loc_02732C1C
    ldr     r0, =data_021A1988
    b       @loc_02732C20

@loc_02732C1C:
    mov     r0, r7

@loc_02732C20:
    add     r1, r1, #0x4000
    bl      MI_CpuCopy8
    cmp     r6, #0
    ldrne   r0, =data_021A1990
    add     r1, r5, #0x3b4
    cmpne   r6, r0
    mov     r2, #0x20
    bne     @loc_02732C58
    ldr     r0, =data_021A1990
    add     r1, r1, #0x4000
    bl      MI_CpuCopy8
    add     r0, r5, #0x4300
    mov     r1, #0
    b       @loc_02732C8C

@loc_02732C58:
    mov     r0, r6
    add     r1, r1, #0x4000
    bl      MI_CpuCopy8
    mov     r1, #0

@loc_02732C68:
    ldrb    r0, [r6, r1]
    cmp     r0, #0
    beq     @loc_02732C80
    add     r1, r1, #1
    cmp     r1, #0x20
    blt     @loc_02732C68

@loc_02732C80:
    mov     r0, r1, lsl #0x10
    mov     r1, r0, lsr #0x10
    add     r0, r5, #0x4300

@loc_02732C8C:
    strh    r1, [r0, #0xb2]
    strh    r1, [r0, #0xd4]
    add     r0, r5, #0x4000
    mov     r1, #0
    str     r1, [r0, #0x3e0]
    ldmfd   sp!, {r3, r4, r5, r6, r7, pc}
}


asm void func_02732CAC(void *arg)
{
    stmdb   sp!, {r3, r4, r5, lr}
    mov     r5, r0
    bl      func_02166378
    ldrh    r1, [r5]
    mov     r4, r0
    cmp     r1, #0xb
    ldmnefd sp!, {r3, r4, r5, pc}
    ldrh    r0, [r5, #2]
    strh    r0, [r4, #0x24]
    ldrh    r0, [r5, #2]
    cmp     r0, #0
    bne     @loc_02732CE0
    bl      func_02165AF4

@loc_02732CE0:
    add     r0, r4, #4
    bl      OS_WakeupThread
    ldmfd   sp!, {r3, r4, r5, pc}
}
