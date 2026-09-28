/*
 * function: func_02731E50
 * address:  0x02731E50
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02166378   0x02166378  arm  ov009
 *   func_027036A0   0x027036A0  arm  twl
 *   OS_SleepThread  0x020857B0  arm
 *   func_02732CAC   0x02732CAC  arm  twl
 *   func_02732CEC   0x02732CEC  arm  twl
 */

typedef unsigned int u32;

extern void *func_02166378(void);
extern u32 func_027036A0(void *cb, u32 a, u32 b, u32 c);
extern void OS_SleepThread(void *queue);
extern void func_02732CAC(void);
extern void func_02732CEC(void);

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
