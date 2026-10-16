/*
 * file:     os_emulator.c
 * unit:     yes
 * function: OS_GetConsoleType, OSi_DetectDeviceType, OS_IsRunOnEmulator, OS_IsRunOnTwl, OSi_IsRunOnTwl
 * address:  0x02085CBC
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
 *   g_020A86A4            0x020A86A4  data
 *   OS_GetBootType 0x02087B04 arm
 *   g_020A5CD4 0x020A5CD4 data
 *   g_02151244  0x02151244  data
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef int BOOL;

typedef u32 OSIntrMode;

/* os_emulator.o .data from 0x020A86A4, addressed from one pool word: the
   file-scope OSi_RunningConsoleTypeCache, then OS_GetConsoleType's static
   OSi_ConsoleTypeCache (both start at 0xFFFFFFFF). */
typedef struct OsEmulatorData {
    u32 OSi_RunningConsoleTypeCache;
    u32 OSi_ConsoleTypeCache;
} OsEmulatorData;

typedef struct OsSystemBss {
    int nitroModeOnTwl;
    int isTwl;
    int pad[5];
    int isChecked;
} OsSystemBss;

extern u16 OS_GetBootType(void);
u32 OS_GetConsoleType(void);
int OS_IsRunOnEmulator(void);
int OS_IsRunOnTwl(void);
int OSi_IsRunOnTwl(void);
extern u32 g_020A5CD4[];
extern char SDK_AUTOLOAD_DTCM_START[];
extern OsEmulatorData g_020A86A4;
extern OsSystemBss g_02151244;

static u32 OSi_DetectDeviceType(void);



/*
 * sdk:      OS_GetConsoleType (os_emulator.o)
 */
u32 OS_GetConsoleType(void)
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


static u32 OSi_DetectDeviceType(void)
{
    return g_020A5CD4[OS_GetBootType()];
}



int OS_IsRunOnEmulator(void)
{
    return (OS_GetConsoleType() & 0x10000000) ? 1 : 0;
}



int OS_IsRunOnTwl(void)
{
    if (!g_02151244.isChecked) {
        unsigned char rom9 = *(volatile unsigned char *)0x04004000;
        g_02151244.isTwl = ((rom9 & 3) == 1) ? 1 : 0;
        g_02151244.isChecked = 1;
    }
    return g_02151244.isTwl;
}


int OSi_IsRunOnTwl(void)
{
    return OS_IsRunOnTwl();
}
