/*
 * function: func_027320D0
 * address:  0x027320D0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021657C8     0x021657C8  arm  ov009
 *   func_02702F38     0x02702F38  arm  twl
 *   func_02702A98     0x02702A98  arm  twl
 *   func_02165A4C     0x02165A4C  arm  ov009
 *   func_021659B4     0x021659B4  arm  ov009
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_021665CC     0x021665CC  arm  ov009
 *   func_02702BFC     0x02702BFC  arm  twl
 *   func_027035F4     0x027035F4  arm  twl
 *   func_0270379C     0x0270379C  arm  twl
 *   func_02732944     0x02732944  arm  twl
 */

typedef unsigned int u32;

extern int func_021657C8(void);
extern u32 func_02702F38(void *arg);
extern u32 func_02702A98(void);
extern void func_02165A4C(unsigned char phase);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern void OS_GetMacAddress(void *mac);
extern void func_021665CC(void *mac);
extern u32 func_02702BFC(void *arg);
extern u32 func_027035F4(void *arg, u32 b);
extern u32 func_0270379C(void *arg, void *b, u32 c, u32 d);
extern void func_02732944(void);

asm void func_027320D0(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    sub     sp, sp, #8
    mov     r6, r0
    mov     r5, #0xd
    bl      func_021657C8
    ldrh    r1, [r6, #2]
    mov     r4, r0
    cmp     r1, #0xa
    addls   pc, pc, r1, lsl #2
    b       @loc_0273235C

    b       @loc_02732124
    b       @loc_027322EC
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_0273235C
    b       @loc_02732324

@loc_02732124:
    ldrh    r0, [r6, #0]
    cmp     r0, #0x12
    addls   pc, pc, r0, lsl #2
    b       @loc_02732260

    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732180
    b       @loc_0273218C
    b       @loc_027321E0
    b       @loc_02732218
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732224
    b       @loc_02732248
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732260
    b       @loc_02732224

@loc_02732180:
    ldr     r0, =func_027320D0
    bl      func_02702F38
    b       @loc_0273225C

@loc_0273218C:
    bl      func_02702A98
    cmp     r0, #0
    bne     @loc_027321BC
    mov     r0, #1
    bl      func_02165A4C
    mov     r0, #0
    mov     r1, r0
    mov     r2, r0
    mov     r3, #0x300
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027321BC:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    mov     r1, #0
    mov     r2, r1
    rsb     r3, r0, #0x310
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027321E0:
    add     r4, sp, #0
    mov     r0, r4
    bl      OS_GetMacAddress
    mov     r0, r4
    bl      func_021665CC
    mov     r0, #3
    bl      func_02165A4C
    mov     r0, #0
    ldr     r3, =0x316
    mov     r1, r0
    mov     r2, r0
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732218:
    ldr     r0, =func_027320D0
    bl      func_02702BFC
    b       @loc_0273225C

@loc_02732224:
    add     r0, r4, #0x1000
    ldr     r0, [r0, #0x2d4]
    mov     r1, #0
    and     r0, r0, #0x30000
    cmp     r0, #0x30000
    ldr     r0, =func_027320D0
    movne   r1, #1
    bl      func_027035F4
    b       @loc_0273225C

@loc_02732248:
    ldr     r0, =func_02732944
    add     r1, r4, #0x600
    mov     r2, #0xc40
    mov     r3, #0
    bl      func_0270379C

@loc_0273225C:
    mov     r5, r0

@loc_02732260:
    cmp     r5, #2
    addeq   sp, sp, #8
    ldmeqfd sp!, {r4, r5, r6, pc}
    cmp     r5, #3
    beq     @loc_027322B4
    cmp     r5, #6
    bne     @loc_027322B4
    mov     r0, #0xc
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    ldr     r3, =0x34A
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    movne   r1, #0
    mov     r0, #1
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027322B4:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    mov     r0, #7
    movne   r1, #0
    add     r3, r0, #0x34c
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_027322EC:
    mov     r0, #0xc
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    ldr     r3, =0x372
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    movne   r1, #0
    mov     r0, #1
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_02732324:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    mov     r2, #0
    mov     r3, #0x378
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    movne   r1, #0
    mov     r0, #7
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}

@loc_0273235C:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r0, r4, #0x1200
    ldrsh   r0, [r0, #0xda]
    mov     r2, #0
    cmp     r0, #5
    addeq   r0, r4, #0x2e0
    addeq   r1, r0, #0x1000
    mov     r0, #7
    movne   r1, #0
    rsb     r3, r0, #0x38c
    bl      func_021659B4
    add     sp, sp, #8
    ldmfd   sp!, {r4, r5, r6, pc}
}
