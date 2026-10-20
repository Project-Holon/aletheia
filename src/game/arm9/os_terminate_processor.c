/*
 * file:     os_terminate_processor.c
 * unit:     yes
 * function: OS_Terminate, OSi_DisableInterruptsAndHalt, OS_Halt
 * address:  0x02088234
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * TwlSDK libos os_terminate_proc.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * The object's .bss holds OSi_TerminateCallbackArg at +0,
 * OSi_TerminateCallback at +4 and the function-static `terminated` at +8,
 * addressed through one section-relative pool word; OsTerminateBss below is
 * that section.
 *
 * symbols:
 *   gOsTerminateBss            0x02151398  data
 *   OS_GetProcMode        0x020879EC  arm
 *   OS_EnableInterrupts   0x02087974  arm
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   FATFSi_IsInitialized  0x02704318  arm  twl
 *   FATFS_UnmountAll      0x02704328  arm  twl
 *   OSi_SendToPxi         0x02084A84  arm
 *   OSi_DisableInterruptsAndHalt     0x020882C0  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_Halt  0x020882D0  arm
 */
#define reg_OS_IME (*(vu16 *)REG_IME_ADDR)
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_os.h"

typedef enum OSProcMode {
    OS_PROCMODE_USER = 16,
    OS_PROCMODE_FIQ = 17,
    OS_PROCMODE_IRQ = 18,
    OS_PROCMODE_SVC = 19,
    OS_PROCMODE_ABORT = 23,
    OS_PROCMODE_UNDEF = 27,
    OS_PROCMODE_SYS = 31
} OSProcMode;

typedef void (*OSTerminateCallback)(void *arg);

typedef struct OsTerminateBss {
    void *OSi_TerminateCallbackArg;
    OSTerminateCallback OSi_TerminateCallback;
    BOOL terminated;
} OsTerminateBss;

#include "os_system.h"
#include "os_emulator.h"
#include "../twl/fatfs_api.h"
#include "os_pxi.h"
extern void OSi_DisableInterruptsAndHalt(void);
extern void OS_Halt(void);
void OS_Terminate(void);
void OSi_DisableInterruptsAndHalt(void);
extern OsTerminateBss gOsTerminateBss;

static inline BOOL OS_EnableIrq(void)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = 1;
    return (BOOL)prep;
}

void OS_Terminate(void)
{
    if (gOsTerminateBss.OSi_TerminateCallback) {
        OSTerminateCallback callback = gOsTerminateBss.OSi_TerminateCallback;
        gOsTerminateBss.OSi_TerminateCallback = 0;
        callback(gOsTerminateBss.OSi_TerminateCallbackArg);
    }

    if (!gOsTerminateBss.terminated) {
        gOsTerminateBss.terminated = 1;
        if (OS_GetProcMode() != OS_PROCMODE_IRQ) {
            (void)OS_EnableIrq();
            (void)OS_EnableInterrupts();
        }
        if (OS_IsRunOnTwl() && FATFSi_IsInitialized()) {
            (void)FATFS_UnmountAll();
        }
        OSi_SendToPxi(0x20);
    }
    OSi_DisableInterruptsAndHalt();
}

void OSi_DisableInterruptsAndHalt(void)
{
    OS_DisableInterrupts();
    while (1) {
        OS_Halt();
    }
}

/* hand-written in the original: mcr p15 wait for interrupt, one SDK line-table row per instruction */
asm void OS_Halt(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}
