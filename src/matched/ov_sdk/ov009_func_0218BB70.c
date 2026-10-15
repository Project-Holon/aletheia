/*
 * function: gpiIntToDate
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
 *   gpiIsValidDate  0x0218BA10  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gGpiInfoErrorInvalidDate     0x021A4A98  data  ov009
 */

extern int gpiIsValidDate(int day, int month, int year);
extern void gpiSetErrorString(int *p, int b);
extern char gGpiInfoErrorInvalidDate[];

int gpiIntToDate(void **connection, int date, int *day, int *month, int *year)
{
    int d;
    int m;
    int y;

    d = (date >> 24) & 0xFF;
    m = (date >> 16) & 0xFF;
    y = date & 0xFFFF;
    if (!gpiIsValidDate(d, m, y)) {
        gpiSetErrorString((int *)connection, (int)gGpiInfoErrorInvalidDate);
        return 2;
    }
    *day = d;
    *month = m;
    *year = y;
    return 0;
}
