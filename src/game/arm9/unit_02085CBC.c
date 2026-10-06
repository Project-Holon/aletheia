/*
 * file:     unit_02085CBC.c
 * unit:     yes
 * function: func_02085CBC, func_02085D0C, func_02085D24, func_02085D3C
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
 *   OSi_DetectDeviceType  0x02085D0C  arm
 *   g_020A86A4            0x020A86A4  data
 *   func_02087B04 0x02087B04 arm
 *   g_020A5CD4 0x020A5CD4 data
 *   g_02151244  0x02151244  data
 */
typedef unsigned long u32_02085CBC;

typedef unsigned short u16;

typedef int BOOL;

typedef u32_02085CBC OSIntrMode;

/* os_emulator.o .data from 0x020A86A4, addressed from one pool word: the
   file-scope OSi_RunningConsoleTypeCache, then OS_GetConsoleType's static
   OSi_ConsoleTypeCache (both start at 0xFFFFFFFF). */
typedef struct OsEmulatorData {
    u32_02085CBC OSi_RunningConsoleTypeCache;
    u32_02085CBC OSi_ConsoleTypeCache;
} OsEmulatorData;

typedef unsigned int   u32_2;

typedef struct OsSystemBss {
    int nitroModeOnTwl;
    int isTwl;
    int pad[5];
    int isChecked;
} OsSystemBss;

extern u32_02085CBC OSi_DetectDeviceType(void);
extern void func_02087B04(void);
extern void g_020A5CD4(void);
u32_02085CBC func_02085CBC(void);
asm void DWCi_CMNlFontFlag(void);
asm void OS_IsRunOnEmulator(void);
int OS_IsRunOnTwl(void);
extern char SDK_AUTOLOAD_DTCM_START[];
extern OsEmulatorData g_020A86A4;
extern OsSystemBss g_02151244;


/*
 * sdk:      OS_GetConsoleType (os_emulator.o)
 */
u32_02085CBC func_02085CBC(void)
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

asm void DWCi_CMNlFontFlag(void)
{
    stmfd sp!, {r3, lr}
    bl func_02087B04
    ldr r1, =g_020A5CD4
    ldr r0, [r1, r0, lsl #2]
    ldmfd sp!, {r3, pc}
}


asm void OS_IsRunOnEmulator(void)
{
    stmfd sp!, {r3, lr}
    bl func_02085CBC
    tst	r0, #0x10000000
    movne	r0, #1
    moveq	r0, #0
    ldmfd sp!, {r3, pc}
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
