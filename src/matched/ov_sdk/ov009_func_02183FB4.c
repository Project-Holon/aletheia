/*
 * function: PrintChar
 * address:  0x02183FB4
 * packet:   pkt_ov009_02183FB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      PrintChar (screen)
 *
 * symbols:
 *   ScrollTopScreen  0x02183F68 arm ov009
 *   gScreenScrollCount     0x021AD1C4 data
 *   gScreenScrollBuffer     0x021AD1C8 data
 */

extern void ScrollTopScreen(void);
extern int gScreenScrollCount;
extern unsigned short gScreenScrollBuffer[768];

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
