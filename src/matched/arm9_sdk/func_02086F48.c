/*
 * function: OSi_DisplayExContext
 * address:  0x02086F48
 * packet:   pkt_02086F48
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OSi_DisplayExContext (os_exception.o)
 * asm:      C function with an asm block: switching to system mode and back
 *           needs mrs/msr on CPSR, and the handler call runs on a hand-built
 *           frame; .debug_line gives the block one increasing line per
 *           instruction (497..536) inside the C lines 462/541.
 *
 * symbols:
 *   OS_EnableProtectionUnit      0x02086CF4  arm
 *   OS_DisableProtectionUnit     0x02086D04  arm
 *   g_02151290                   0x02151290  data
 *   OSi_UserExceptionHandlerArg  0x02151294  data
 *   OSi_UserExceptionHandler     0x02151298  data
 *   OSi_ExContext                0x021512BC  data
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

extern OsExceptionBss g_02151290;

extern void OS_EnableProtectionUnit(void);
extern void OS_DisableProtectionUnit(void);
extern u32 OSi_UserExceptionHandlerArg;
extern OSExceptionHandler OSi_UserExceptionHandler;
extern u32 OSi_ExContext[28];

void OSi_DisplayExContext(void)
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
