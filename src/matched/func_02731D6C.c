/*
 * function: func_02731D6C
 * address:  0x02731D6C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021657C8  0x021657C8  arm  ov009
 *   func_027028B0  0x027028B0  arm  twl
 *   func_02702A98  0x02702A98  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02702BFC  0x02702BFC  arm  twl
 *   func_02702FE8  0x02702FE8  arm  twl
 *   func_02703424  0x02703424  arm  twl
 *   func_027320D0  0x027320D0  arm  twl
 *   func_02732874  0x02732874  arm  twl
 */

typedef unsigned int u32;

extern void *func_021657C8(void);
extern u32 func_027028B0(void);
extern u32 func_02702A98(void);
extern void func_02165A4C(u32 phase);
extern u32 func_02702BFC(void *arg);
extern u32 func_02702FE8(void *arg);
extern u32 func_02703424(void *arg);
extern void func_027320D0(void);
extern void func_02732874(void);

asm u32 func_02731D6C(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    bl      func_027028B0
    cmp     r0, #4
    addls   pc, pc, r0, lsl #2
    b       @loc_02731DE4

    b       @loc_02731DE4
    b       @loc_02731D9C
    b       @loc_02731DC0
    b       @loc_02731DCC
    b       @loc_02731DD8

@loc_02731D9C:
    bl      func_02702A98
    cmp     r0, #0
    bne     @loc_02731DF4
    mov     r0, #1
    bl      func_02165A4C
    add     r1, r4, #0x1200
    mov     r0, #0
    strh    r0, [r1, #0xda]
    ldmfd   sp!, {r4, pc}

@loc_02731DC0:
    ldr     r0, =func_027320D0
    bl      func_02702BFC
    b       @loc_02731DF4

@loc_02731DCC:
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    b       @loc_02731DF4

@loc_02731DD8:
    ldr     r0, =func_02732874
    bl      func_02703424
    b       @loc_02731DF4

@loc_02731DE4:
    add     r0, r4, #0x1000
    mov     r1, #1
    strb    r1, [r0, #0x2dd]
    mov     r0, #4

@loc_02731DF4:
    cmp     r0, #2
    beq     @loc_02731E10
    cmp     r0, #3
    beq     @loc_02731E30
    cmp     r0, #6
    beq     @loc_02731E28
    b       @loc_02731E30

@loc_02731E10:
    mov     r0, #0xd
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #9
    strh    r1, [r0, #0xda]
    b       @loc_02731E40

@loc_02731E28:
    mov     r0, #4
    ldmfd   sp!, {r4, pc}

@loc_02731E30:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731E40:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}
