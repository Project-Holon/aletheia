/*
 * file:     os_exception.c
 * unit:     yes
 * function: func_02086DD8, func_02086E40, func_02086EB4, func_02086EC8, func_02086F48
 * address:  0x02086DD8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   OSi_ExceptionHandler  0x02086E40  arm
 *   g_02151290            0x02151290  data
 *   OSi_ExContext  0x021512BC  data
 *   OS_EnableProtectionUnit      0x02086CF4  arm
 *   OS_DisableProtectionUnit     0x02086D04  arm
 *   OSi_UserExceptionHandlerArg  0x02151294  data
 *   OSi_UserExceptionHandler     0x02151298  data
 */
typedef unsigned long u32;

typedef int BOOL;

typedef void (*OSExceptionHandler)(u32 context, u32 arg);

/* os_exception.o .bss from 0x02151290, addressed from one pool word. */
typedef struct OsExceptionBss {
    void *OSi_DebuggerHandler;
    u32 OSi_UserExceptionHandlerArg;
    OSExceptionHandler OSi_UserExceptionHandler;
    u32 OSi_ExceptionHookStack[8];
} OsExceptionBss;

extern BOOL OS_IsRunOnTwl(void);
extern void OSi_ExceptionHandler(void);
extern void OS_EnableProtectionUnit(void);
extern void OS_DisableProtectionUnit(void);
void func_02086DD8(void);
asm void func_02086E40(void);
asm void OSi_GetAndDisplayContext(void);
asm void func_02086EC8(void);
void func_02086F48(void);
extern OsExceptionBss g_02151290;
extern unsigned long OSi_ExContext[28];
extern u32 OSi_UserExceptionHandlerArg;
extern OSExceptionHandler OSi_UserExceptionHandler;


/*
 * sdk:      OS_InitException (os_exception.o)
 */
void func_02086DD8(void)
{
    u32 ex = *(u32 *)0x02FFFD9C;

    if (!(0x02600000 <= ex && ex < 0x02800000)) {
        ex = 0;
    }
    g_02151290.OSi_DebuggerHandler = (void *)ex;

    if (!ex) {
        u32 *vec = (u32 *)0x02FFFD9C;
        *vec = (u32)OSi_ExceptionHandler;
        if (!OS_IsRunOnTwl()) {
            *(u32 *)((u32)vec & ~0x800000) = (u32)OSi_ExceptionHandler;
        }
    }

    g_02151290.OSi_UserExceptionHandler = 0;
}


/*
 * sdk:      OSi_ExceptionHandler (os_exception.o)
 * asm:      exception-vector entry with no prologue: uses r12 and a private
 *           stack outside the ABI and needs mrs on CPSR; the object agrees:
 *           .debug_line gives each instruction its own increasing line (285..332).
 */
asm void func_02086E40(void)
{
    ldr     r12, =g_02151290
    ldr     r12, [r12, #0]
    cmp     r12, #0
    movne   lr, pc
    bxne    r12
    ldr     r12, =0x02000000
    stmdb   r12!, {r0-r3, sp, lr}
    and     r0, sp, #1
    mov     sp, r12
    mrs     r1, cpsr
    and     r1, r1, #0x1f
    teq     r1, #0x17
    bne     _1
    bl      OSi_GetAndDisplayContext
    b       _2
_1:
    teq     r1, #0x1b
    bne     _2
    bl      OSi_GetAndDisplayContext
_2:
    ldr     r12, =g_02151290
    ldr     r12, [r12, #0]
    cmp     r12, #0
_3:
    beq     _3
_4:
    mov     r0, r0
    b       _4
    ldmia   sp!, {r0-r3, r12, lr}
    mov     sp, r12
    bx      lr
}

/* hand-written in the original: SDK asm wrapper; saves r0 and calls the mrs/msr routines, which take r12 (the exception frame) implicitly */
asm void OSi_GetAndDisplayContext(void)
{
    stmfd sp!, {r0, lr}
    bl func_02086EC8
    bl func_02086F48
    ldmfd sp!, {r0, lr}
    bx lr
}


/*
 * sdk:      OSi_SetExContext (os_exception.o)
 * asm:      needs mrs/msr on CPSR/SPSR and reads the exception frame through
 *           r12 outside the ABI; the object agrees: .debug_line gives each
 *           instruction its own increasing line (376..449).
 */
asm void func_02086EC8(void)
{
    ldr     r1, =OSi_ExContext
    str     r0, [r1, #0x6c]
    ldr     r0, [r12, #0]
    str     r0, [r1, #4]
    ldr     r0, [r12, #4]
    str     r0, [r1, #8]
    ldr     r0, [r12, #8]
    str     r0, [r1, #0xc]
    ldr     r0, [r12, #0xc]
    str     r0, [r1, #0x10]
    ldr     r2, [r12, #0x10]
    bic     r2, r2, #1
    add     r0, r1, #0x14
    stmia   r0, {r4-r11}
    ldr     r0, [r2, #0]
    str     r0, [r1, #0x64]
    ldr     r3, [r2, #4]
    str     r3, [r1, #0]
    ldr     r0, [r2, #8]
    str     r0, [r1, #0x34]
    ldr     r0, [r2, #0xc]
    str     r0, [r1, #0x40]
    mrs     r0, cpsr
    orr     r3, r3, #0x80
    bic     r3, r3, #0x20
    msr     cpsr_fsxc, r3
    str     sp, [r1, #0x38]
    str     lr, [r1, #0x3c]
    mrs     r2, spsr
    msr     cpsr_fsxc, r0
    bx      lr
}


/*
 * sdk:      OSi_DisplayExContext (os_exception.o)
 * asm:      C function with an asm block: switching to system mode and back
 *           needs mrs/msr on CPSR, and the handler call runs on a hand-built
 *           frame; .debug_line gives the block one increasing line per
 *           instruction (497..536) inside the C lines 462/541.
 */
void func_02086F48(void)
{
    if (g_02151290.OSi_UserExceptionHandler) {
        asm {
            mrs     r2, CPSR
            mov     r0, sp
            ldr     r1, =0x9f
            msr     CPSR_cxsf, r1
            mov     r1, sp
            mov     sp, r0
            stmfd   sp!, {r1, r2}
            bl      OS_EnableProtectionUnit
            ldr     r0, =OSi_ExContext
            ldr     r1, =OSi_UserExceptionHandlerArg
            ldr     r1, [r1]
            ldr     r12, =OSi_UserExceptionHandler
            ldr     r12, [r12]
            ldr     lr, =@1
            bx      r12
        @1:
            bl      OS_DisableProtectionUnit
            ldmfd   sp!, {r1, r2}
            mov     sp, r1
            msr     CPSR_cxsf, r2
        }
    }
}
