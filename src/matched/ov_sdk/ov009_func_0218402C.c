/*
 * function: func_0218402C
 * address:  0x0218402C
 * packet:   pkt_ov009_0218402C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      VPrintf (screen)
 *
 * symbols:
 *   OS_VSNPrintf       0x02084FA8 arm
 *   func_02183FB4      0x02183FB4 arm ov009
 *   OS_WaitVBlankIntr  0x02087AE4 arm
 *   g_021A3FBC         0x021A3FBC data
 *   g_021AD7C8         0x021AD7C8 data
 */

extern int OS_VSNPrintf(char * dst, unsigned long len, const char * fmt, char * vlist);
extern void PrintChar(char c);
extern void OS_WaitVBlankIntr(void);
extern int g_021A3FBC;
extern char g_021AD7C8[2048];

void func_0218402C(char * format, char * args)
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
