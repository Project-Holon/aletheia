/*
 * file:     screen.c
 * unit:     yes
 * function: ScrollTopScreen, PrintChar, VPrintf
 * address:  0x02183F68
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MIi_CpuCopyFast   0x02082B0C arm
 *   MIi_CpuClearFast  0x02082AC0 arm
 *   gScreenScrollBuffer        0x021AD1C8 data
 *   gScreenScrollCount     0x021AD1C4 data
 *   OS_VSNPrintf       0x02084FA8 arm
 *   OS_WaitVBlankIntr  0x02087AE4 arm
 *   gScreenFlag         0x021A3FBC data
 *   gScreenLogBuffer         0x021AD7C8 data
 */
#include "../arm9/mi_memory.h"
#include "../arm9/os_printf.h"
extern void PrintChar(char c);
#include "../arm9/os_system.h"
#include "../sdk_stdarg.h"
void ScrollTopScreen(void);
void PrintChar(char c);
void VPrintf(const char *format, va_list args);
extern unsigned short gScreenScrollBuffer[768];
extern int gScreenScrollCount;
extern int gScreenFlag;
extern char gScreenLogBuffer[2048];


/*
 * sdk:      ScrollTopScreen (screen)
 */
void ScrollTopScreen(void)
{
    int i;

    for (i = 0; i < 23; i++)
        MIi_CpuCopyFast(&gScreenScrollBuffer[(i + 1) * 32], &gScreenScrollBuffer[i * 32], 64);
    MIi_CpuClearFast(0, &gScreenScrollBuffer[23 * 32], 64);
}


/*
 * sdk:      PrintChar (screen)
 */
void PrintChar(char c)
{
    if (c == 13)
        return;
    if (gScreenScrollCount == 32)
    {
        ScrollTopScreen();
        gScreenScrollCount = 0;
        if (c == 10)
            return;
    }
    if (c == 10)
    {
        gScreenScrollCount = 32;
        return;
    }
    gScreenScrollBuffer[736 + gScreenScrollCount] = (unsigned short)(c | 0xf000);
    gScreenScrollCount++;
}


void VPrintf(const char *format, va_list args)
{
    int i;

    if ((gScreenFlag & 1) == 0)
        return;
    OS_VSNPrintf(gScreenLogBuffer, 2047, format, args);
    gScreenLogBuffer[2047] = 0;
    for (i = 0; gScreenLogBuffer[i] != 0; i++)
        PrintChar(gScreenLogBuffer[i]);
    OS_WaitVBlankIntr();
}
