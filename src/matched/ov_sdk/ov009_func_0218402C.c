/*
 * function: VPrintf
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
 *   PrintChar      0x02183FB4 arm ov009
 *   OS_WaitVBlankIntr  0x02087AE4 arm
 *   gScreenFlag         0x021A3FBC data
 *   gScreenLogBuffer         0x021AD7C8 data
 */

extern int OS_VSNPrintf(char * dst, unsigned long len, const char * fmt, char * vlist);
extern void PrintChar(char c);
extern void OS_WaitVBlankIntr(void);
extern int gScreenFlag;
extern char gScreenLogBuffer[2048];

void VPrintf(char * format, char * args)
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
