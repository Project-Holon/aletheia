/*
 * function: func_02085CBC
 * address:  0x02085CBC
 * packet:   pkt_02085CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      OS_GetConsoleType (os_emulator.o)
 *
 * symbols:
 *   OS_IsRunOnTwl         0x02085D3C  arm
 *   OSi_DetectDeviceType  0x02085D0C  arm
 *   g_020A86A4            0x020A86A4  data
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef int BOOL;
typedef u32 OSIntrMode;

extern char SDK_AUTOLOAD_DTCM_START[];

/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))

/* os_emulator.o .data from 0x020A86A4, addressed from one pool word: the
   file-scope OSi_RunningConsoleTypeCache, then OS_GetConsoleType's static
   OSi_ConsoleTypeCache (both start at 0xFFFFFFFF). */
typedef struct OsEmulatorData {
    u32 OSi_RunningConsoleTypeCache;
    u32 OSi_ConsoleTypeCache;
} OsEmulatorData;

extern OsEmulatorData g_020A86A4;
extern BOOL OS_IsRunOnTwl(void);
extern u32 OSi_DetectDeviceType(void);

u32 func_02085CBC(void)
{
    if (g_020A86A4.OSi_ConsoleTypeCache == 0xFFFFFFFF) {
        if (OS_IsRunOnTwl()) {
            g_020A86A4.OSi_ConsoleTypeCache = 0x01800004;
        } else {
            g_020A86A4.OSi_ConsoleTypeCache = 0x80000001;
        }
        g_020A86A4.OSi_ConsoleTypeCache |= OSi_DetectDeviceType();
    }
    return g_020A86A4.OSi_ConsoleTypeCache;
}
