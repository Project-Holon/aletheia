/*
 * function: OS_Terminate
 * address:  0x02088234
 * packet:   pkt_02088234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *   OSi_TerminateCore     0x020882C0  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef volatile u16 vu16;
typedef int BOOL;
typedef u32 OSIntrMode;

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

extern OsTerminateBss gOsTerminateBss;
#define OSi_TerminateCallbackArg (gOsTerminateBss.OSi_TerminateCallbackArg)
#define OSi_TerminateCallback    (gOsTerminateBss.OSi_TerminateCallback)
#define terminated               (gOsTerminateBss.terminated)

#define reg_OS_IME (*(vu16 *)0x04000208)

extern OSProcMode OS_GetProcMode(void);
extern OSIntrMode OS_EnableInterrupts(void);
extern BOOL OS_IsRunOnTwl(void);
extern BOOL FATFSi_IsInitialized(void);
extern BOOL FATFS_UnmountAll(void);
extern void OSi_SendToPxi(u16 data);
extern void OSi_TerminateCore(void);

static inline BOOL OS_EnableIrq(void)
{
    u16 prep = reg_OS_IME;
    reg_OS_IME = 1;
    return (BOOL)prep;
}

void OS_Terminate(void)
{
    if (OSi_TerminateCallback) {
        OSTerminateCallback callback = OSi_TerminateCallback;
        OSi_TerminateCallback = 0;
        callback(OSi_TerminateCallbackArg);
    }

    if (!terminated) {
        terminated = 1;
        if (OS_GetProcMode() != OS_PROCMODE_IRQ) {
            (void)OS_EnableIrq();
            (void)OS_EnableInterrupts();
        }
        if (OS_IsRunOnTwl() && FATFSi_IsInitialized()) {
            (void)FATFS_UnmountAll();
        }
        OSi_SendToPxi(0x20);
    }
    OSi_TerminateCore();
}
