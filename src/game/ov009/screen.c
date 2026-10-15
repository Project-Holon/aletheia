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
 *   g_021AD1C8        0x021AD1C8 data
 *   g_021AD1C4     0x021AD1C4 data
 *   OS_VSNPrintf       0x02084FA8 arm
 *   OS_WaitVBlankIntr  0x02087AE4 arm
 *   g_021A3FBC         0x021A3FBC data
 *   g_021AD7C8         0x021AD7C8 data
 */
extern void MIi_CpuCopyFast(void * srcp, void * destp, unsigned long size);
extern void MIi_CpuClearFast(unsigned long data, void * destp, unsigned long size);
extern int OS_VSNPrintf(char * dst, unsigned long len, const char * fmt, char * vlist);
extern void PrintChar(char c);
extern void OS_WaitVBlankIntr(void);
void ScrollTopScreen(void);
void PrintChar(char c);
void VPrintf(char * format, char * args);
extern unsigned short g_021AD1C8[768];
extern int g_021AD1C4;
extern int g_021A3FBC;
extern char g_021AD7C8[2048];


/*
 * sdk:      ScrollTopScreen (screen)
 */
void ScrollTopScreen(void)
{
    int i;

    for (i = 0; i < 23; i++)
        MIi_CpuCopyFast(&g_021AD1C8[(i + 1) * 32], &g_021AD1C8[i * 32], 64);
    MIi_CpuClearFast(0, &g_021AD1C8[23 * 32], 64);
}


/*
 * sdk:      PrintChar (screen)
 */
void PrintChar(char c)
{
    if (c == 13)
        return;
    if (g_021AD1C4 == 32)
    {
        ScrollTopScreen();
        g_021AD1C4 = 0;
        if (c == 10)
            return;
    }
    if (c == 10)
    {
        g_021AD1C4 = 32;
        return;
    }
    g_021AD1C8[736 + g_021AD1C4] = (unsigned short)(c | 0xf000);
    g_021AD1C4++;
}


void VPrintf(char * format, char * args)
{
    int i;

    if ((g_021A3FBC & 1) == 0)
        return;
    OS_VSNPrintf(g_021AD7C8, 2047, format, args);
    g_021AD7C8[2047] = 0;
    for (i = 0; g_021AD7C8[i] != 0; i++)
        PrintChar(g_021AD7C8[i]);
    OS_WaitVBlankIntr();
}
