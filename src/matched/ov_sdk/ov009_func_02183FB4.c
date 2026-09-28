/*
 * function: func_02183FB4
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
 *   func_02183F68  0x02183F68 arm ov009
 *   g_021AD1C4     0x021AD1C4 data
 *   g_021AD1C8     0x021AD1C8 data
 */

extern void func_02183F68(void);
extern int g_021AD1C4;
extern unsigned short g_021AD1C8[768];

void func_02183FB4(char c)
{
    if (c == 13)
        return;
    if (g_021AD1C4 == 32)
    {
        func_02183F68();
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
