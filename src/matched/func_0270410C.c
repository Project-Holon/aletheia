/*
 * function: func_0270410C
 * address:  0x0270410C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_027040EC         0x027040EC  arm  twl
 *   data_027343E0         0x027343E0  data twl a4
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_0273442C         0x0273442C  data twl a4
 *   OS_LockMutex          0x02086028  arm
 */

typedef unsigned int u32;

extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enable);
extern void OS_LockMutex(void *mutex);
extern u32 func_027040EC(void);
extern void *data_027343E0;
extern void *data_0273442C;

asm void *func_0270410C(void *arg)
{
    stmdb   sp!, {r4, r5, r6, lr}
    mov     r5, r0
    mov     r4, #0
    bl      OS_DisableInterrupts
    mov     r6, r0
    bl      func_027040EC
    ldr     r1, =data_027343E0
    ldr     r2, [r1, #0x20]
    b       @loc_02704158

@loc_02704130:
    ldr     r1, [r2, #0x800]
    cmp     r1, r0
    bne     @loc_02704154
    mov     r0, #0
    str     r0, [r2, #0x800]
    mov     r0, #2
    mov     r4, r2
    str     r0, [r2, #8]
    b       @loc_02704160

@loc_02704154:
    ldr     r2, [r2, #0x80c]

@loc_02704158:
    cmp     r2, #0
    bne     @loc_02704130

@loc_02704160:
    mov     r0, r6
    bl      OS_RestoreInterrupts
    cmp     r4, #0
    bne     @loc_02704188
    ldr     r0, =data_0273442C
    bl      OS_LockMutex
    ldr     r0, =data_027343E0
    mov     r1, #0
    ldr     r4, [r0, #0x64]
    str     r1, [r4, #8]

@loc_02704188:
    bl      OS_DisableInterrupts
    mov     r6, r0
    bl      func_027040EC
    ldr     r1, =data_027343E0
    ldr     r2, [r1, #4]
    b       @loc_027041B4

@loc_027041A0:
    ldr     r1, [r2, #4]
    cmp     r1, r0
    streq   r4, [r2, #8]
    beq     @loc_027041BC
    ldr     r2, [r2]

@loc_027041B4:
    cmp     r2, #0
    bne     @loc_027041A0

@loc_027041BC:
    mov     r0, r6
    bl      OS_RestoreInterrupts
    str     r5, [r4]
    mov     r0, #2
    str     r0, [r4, #4]
    mov     r1, #0
    mov     r0, r4
    str     r1, [r4, #0xc]
    ldmfd   sp!, {r4, r5, r6, pc}
}
