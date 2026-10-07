/*
 * file:     unit_02731718_p04.c
 * unit:     yes
 * function: func_02731CFC, func_02731D6C, func_02731E50, func_02731F00, func_02731F14, func_027320D0
 * address:  0x02731CFC
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
 *   func_02703854  0x02703854  arm  twl
 *   func_02165A4C  0x02165A4C  arm  ov009
 *   func_02732A64  0x02732A64  arm  twl
 *   func_027028B0  0x027028B0  arm  twl
 *   func_02702A98  0x02702A98  arm  twl
 *   func_02702BFC  0x02702BFC  arm  twl
 *   func_02702FE8  0x02702FE8  arm  twl
 *   func_02703424  0x02703424  arm  twl
 *   func_02732874  0x02732874  arm  twl
 *   func_02166378   0x02166378  arm  ov009
 *   func_027036A0   0x027036A0  arm  twl
 *   OS_SleepThread  0x020857B0  arm
 *   func_02732CAC   0x02732CAC  arm  twl
 *   func_02732CEC   0x02732CEC  arm  twl
 *   func_02702980  0x02702980  arm  twl
 *   func_021659B4  0x021659B4  arm  ov009
 *   func_02702F38     0x02702F38  arm  twl
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_021665CC     0x021665CC  arm  ov009
 *   func_027035F4     0x027035F4  arm  twl
 *   func_0270379C     0x0270379C  arm  twl
 *   func_02732944     0x02732944  arm  twl
 */
typedef unsigned int u32;

extern int func_021657C8(void);
extern u32 func_02703854(u32 a0, u32 a1);
extern void func_02165A4C(unsigned char phase);
extern void func_02732A64(void);
extern u32 func_027028B0(void);
extern u32 func_02702A98(void);
extern u32 func_02702BFC(void *arg);
extern u32 func_02702FE8(void *arg);
extern u32 func_02703424(void *arg);
extern void func_02732874(void);
extern void *func_02166378(void);
extern u32 func_027036A0(void *cb, u32 a, u32 b, u32 c);
extern void OS_SleepThread(void *queue);
extern void func_02732CAC(void);
extern void func_02732CEC(void);
extern u32 func_02702980(void);
extern void func_021659B4(u32 a, void *b, u32 c, u32 d);
extern u32 func_02702F38(void *arg);
extern void OS_GetMacAddress(void *mac);
extern void func_021665CC(void *mac);
extern u32 func_027035F4(void *arg, u32 b);
extern u32 func_0270379C(void *arg, void *b, u32 c, u32 d);
extern void func_02732944(void);
asm u32 func_02731CFC(void);
asm u32 func_02731D6C(void);
asm u32 func_02731E50(u32 a, u32 b, u32 c, u32 d);
u32 func_02731F00(void);
asm void func_02731F14(void);
asm void func_027320D0(void *arg);


asm u32 func_02731CFC(void)
{
    stmdb   sp!, {r4, lr}
    bl      func_021657C8
    mov     r4, r0
    ldr     r0, =func_02732A64
    mov     r1, #0
    bl      func_02703854
    cmp     r0, #2
    beq     @loc_02731D30
    cmp     r0, #3
    beq     @loc_02731D50
    cmp     r0, #6
    beq     @loc_02731D48
    b       @loc_02731D50

@loc_02731D30:
    mov     r0, #0xa
    bl      func_02165A4C
    add     r0, r4, #0x1200
    mov     r1, #6
    strh    r1, [r0, #0xda]
    b       @loc_02731D60

@loc_02731D48:
    mov     r0, #4
    ldmfd   sp!, {r4, pc}

@loc_02731D50:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    ldmfd   sp!, {r4, pc}

@loc_02731D60:
    mov     r0, #3
    ldmfd   sp!, {r4, pc}
}


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


asm u32 func_02731E50(u32 a, u32 b, u32 c, u32 d)
{
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov     r5, r3
    mov     r8, r0
    mov     r7, r1
    mov     r6, r2
    bl      func_02166378
    mov     r4, r0
    cmp     r5, #0
    bne     @loc_02731E88
    ldr     r0, =func_02732CAC
    mov     r1, r8
    mov     r2, r7
    mov     r3, r6
    b       @loc_02731E9C

@loc_02731E88:
    ldr     r0, =func_02732CEC
    mov     r1, r8
    mov     r2, r7
    mov     r3, r6
    str     r5, [r4, #0x2c]

@loc_02731E9C:
    bl      func_027036A0
    cmp     r0, #6
    addls   pc, pc, r0, lsl #2
    b       @loc_02731EC8

    b       @loc_02731EC8
    b       @loc_02731EC8
    b       @loc_02731ED0
    b       @loc_02731EC8
    b       @loc_02731EC8
    b       @loc_02731EC8
    b       @loc_02731EC8

@loc_02731EC8:
    mvn     r0, #4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731ED0:
    cmp     r5, #0
    bne     @loc_02731EF0
    add     r0, r4, #4
    bl      OS_SleepThread
    ldrh    r0, [r4, #0x24]
    cmp     r0, #0
    mvnne   r0, #4
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731EF0:
    mov     r0, r6
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}
}


u32 func_02731F00(void)
{
    return (func_02702980() << 15) >> 16;
}


asm void func_02731F14(void)
{
    stmdb   sp!, {r4, r5, r6, r7, r8, lr}
    mov     r4, #3
    bl      func_021657C8
    mov     r7, r0
    add     r0, r7, #0x1000
    ldrb    r1, [r0, #0x2dd]
    cmp     r1, #0
    ldmnefd sp!, {r4, r5, r6, r7, r8, pc}
    mov     r5, #0
    strb    r5, [r0, #0x2dd]
    add     r1, r7, #0x4300
    strh    r5, [r1, #0xe4]
    ldrb    r0, [r0, #0x2de]
    mov     r6, #1
    cmp     r0, #0xd
    addls   pc, pc, r0, lsl #2
    b       @loc_027320A4

    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_027320A4
    b       @loc_02731F90
    b       @loc_02731F90
    b       @loc_02731FB0
    b       @loc_02731FD0
    b       @loc_02731FFC
    b       @loc_02732020
    b       @loc_027320A4
    b       @loc_02731FFC
    b       @loc_02732044

@loc_02731F90:
    mov     r0, r4
    bl      func_02165A4C
    mov     r0, r6
    mov     r1, r5
    mov     r2, r5
    add     r3, r4, #0x298
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FB0:
    mov     r0, r4
    bl      func_02165A4C
    mov     r0, r5
    mov     r1, r5
    mov     r2, r5
    rsb     r3, r4, #0x2a4
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FD0:
    ldrh    r8, [r1, #0xe6]
    mov     r0, r4
    strh    r5, [r1, #0xe6]
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    mov     r0, r6
    mov     r2, r8
    add     r1, r1, #0x1000
    add     r3, r4, #0x2a8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02731FFC:
    mov     r0, r4
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    mov     r0, r5
    mov     r2, r6
    add     r1, r1, #0x1000
    add     r3, r4, #0x2b0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732020:
    mov     r0, r4
    bl      func_02165A4C
    add     r1, r7, #0x2e0
    ldr     r3, =0x2BA
    mov     r0, r5
    mov     r2, r5
    add     r1, r1, #0x1000
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732044:
    ldr     r0, =func_027320D0
    bl      func_02702FE8
    cmp     r0, #2
    ldmeqfd sp!, {r4, r5, r6, r7, r8, pc}
    cmp     r0, #3
    beq     @loc_02732084
    cmp     r0, #6
    bne     @loc_02732084
    mov     r0, #0xc
    bl      func_02165A4C
    mov     r0, r6
    mov     r1, r5
    mov     r2, r5
    mov     r3, #0x2c8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_02732084:
    mov     r0, #0xb
    bl      func_02165A4C
    mov     r0, #7
    mov     r1, #0
    mov     r2, r1
    rsb     r3, r0, #0x2d8
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}

@loc_027320A4:
    mov     r0, #0xb
    bl      func_02165A4C
    add     r1, r7, #0x1000
    mov     r0, #7
    ldrb    r2, [r1, #0x2de]
    add     r3, r0, #0x2d0
    mov     r1, #0
    bl      func_021659B4
    ldmfd   sp!, {r4, r5, r6, r7, r8, pc}
}


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
