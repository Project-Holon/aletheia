/*
 * function: gpiIsValidDate
 * address:  0x0218BA10
 * packet:   pkt_0218BA10
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Date validity (day, month, year): all-zero is accepted, negatives rejected,
 * month dispatch with February leap handling, then a 1900..2079 window with a
 * 2079-07-06 upper cutoff.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int gpiIsValidDate(int day, int month, int year)
{
    if (day == 0 && month == 0 && year == 0)
        return 1;
    if (day < 0 || month < 0 || year < 0)
        return 0;
    switch (month) {
    case 0:
        if (day != 0)
            return 0;
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31)
            return 0;
        break;
    case 4: case 6: case 9: case 11:
        if (day > 30)
            return 0;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29)
                return 0;
        } else {
            if (day > 28)
                return 0;
        }
        break;
    default:
        return 0;
    }
    if (year < 1900)
        return 0;
    if (year > 2079)
        return 0;
    if (year == 2079) {
        if (month > 6)
            return 0;
        if (month == 6 && day > 6)
            return 0;
    }
    return 1;
}
