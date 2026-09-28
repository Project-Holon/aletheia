/*
 * function: func_02086DD8
 * address:  0x02086DD8
 * packet:   pkt_02086DD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      OS_InitException (os_exception.o)
 *
 * symbols:
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   OSi_ExceptionHandler  0x02086E40  arm
 *   g_02151290            0x02151290  data
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

extern BOOL OS_IsRunOnTwl(void);
extern void OSi_ExceptionHandler(void);

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
