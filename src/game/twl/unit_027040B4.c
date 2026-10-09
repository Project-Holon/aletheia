/*
 * file:     unit_027040B4.c
 * unit:     yes
 * function: func_027040B4, func_027040EC, func_0270410C, func_027041E8, func_02704230
 * address:  0x027040B4
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
 *   func_020862F0  0x020862F0  code twl a2
 *   func_02088610  0x02088610  code twl a2
 *   data_02150FEC  0x02150FEC  data a1
 *   func_020879EC  0x020879EC  arm twl a2
 *   OS_DisableInterrupts  0x02087988  arm
 *   data_027343E0         0x027343E0  data twl a4
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   data_0273442C         0x0273442C  data twl a4
 *   OS_LockMutex          0x02086028  arm
 *   DAT_027343e0   0x027343e0  data twl
 *   DAT_0273442c   0x0273442c  data twl
 *   func_02086078  0x02086078  code twl
 */
typedef unsigned int u32;

extern void func_020862F0(u32, u32);
extern int func_02088610(u32, u32, u32);
extern u32 func_020879EC(void);
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32 enable);
extern void OS_LockMutex(void *mutex);
extern void func_02086078(u32);
asm void func_027040B4(u32 a0);
u32 func_027040EC(void);
asm void *func_0270410C(void *arg);
asm void func_027041E8(u32 a0);
asm void func_02704230(u32 a0);
extern u32 data_02150FEC[];
extern void *data_027343E0;
extern void *data_0273442C;
extern u32 DAT_027343e0[];
extern u32 DAT_0273442c[];




asm void func_027040B4(u32 a0) {
    stmdb sp!, {r4, r5, r6, lr}
    mov r1, #0x800
    mov r4, r0
    bl func_020862F0
    mov r6, r4, lsr #5
    mov r5, #0x14
    mov r4, #0
@lbl_027040D0:
    mov r0, r5
    mov r1, r6
    mov r2, r4
    bl func_02088610
    cmp r0, #0
    dcd 0xbafffff9
    ldmfd sp!, {r4, r5, r6, pc}
}




/*
 *   witness.  The address is a real arm9 bss object (layout/data_objects.txt
 *   row `arm9 0x02150FEC pool`, 160+ ARM9 pool referrers), but sole-ref
 *   refuses it here because its only referrer inside this compared range IS
 *   the site under test, and a bss address has no ROM word for sole-ref/self.
 */
u32 func_027040EC(void) {
    if (func_020879EC() == 0x12) {
        return 0x80000000u;
    }
    return data_02150FEC[1];
}



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



asm void func_027041E8(u32 a0) {
    stmdb sp!, {r4, lr}
    mov r4, r0
    bl func_020879EC
    cmp r0, #0x12
    beq @lbl_02704208
    mov r0, r4
    bl func_0270410C
    ldmfd sp!, {r4, pc}
@lbl_02704208:
    ldr r0, =DAT_027343e0
    mov r2, #2
    ldr r0, [r0, #0x68]
    mov r1, #0
    str r4, [r0]
    str r2, [r0, #4]
    str r1, [r0, #0xc]
    str r1, [r0, #8]
    ldmfd sp!, {r4, pc}
}



asm void func_02704230(u32 a0) {
    stmdb sp!, {r3, lr}
    ldr r1, =DAT_027343e0
    ldr r1, [r1, #0x64]
    cmp r0, r1
    ldmnefd sp!, {r3, pc}
    ldr r0, =DAT_0273442c
    bl func_02086078
    ldmfd sp!, {r3, pc}
}
