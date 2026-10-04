/*
 * function: func_0218BB70
 * address:  0x0218BB70
 * packet:   pkt_ov009_0218BB70
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiIntToDate (gpiinfo.o)
 *
 * symbols:
 *   func_0218BA10  0x0218BA10  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   g_021A4A98     0x021A4A98  data  ov009
 */

extern int func_0218BA10(int day, int month, int year);
extern void func_02193734(int *p, int b);
extern char g_021A4A98[];

int func_0218BB70(void **connection, int date, int *day, int *month, int *year)
{
    int d;
    int m;
    int y;

    d = (date >> 24) & 0xFF;
    m = (date >> 16) & 0xFF;
    y = date & 0xFFFF;
    if (!func_0218BA10(d, m, y)) {
        func_02193734((int *)connection, (int)g_021A4A98);
        return 2;
    }
    *day = d;
    *month = m;
    *year = y;
    return 0;
}
