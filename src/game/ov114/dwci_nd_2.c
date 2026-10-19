/*
 * file:     dwci_nd_2.c
 * unit:     yes
 * function: DWCi_Ndi_intToStrFigure, DWCi_Ndi_hexToStrFigure
 * address:  0x021C7A74
 * region:   ov114
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ll_udiv  0x0209C00C  arm
 *   sDwciNdPowersOfTen  0x021CE138  data
 */
#include "../types.h"

int DWCi_Ndi_intToStrFigure(char *buffer, u64 value, int figure);
int DWCi_Ndi_hexToStrFigure(char *buffer, unsigned long value, int figure);
extern u64 sDwciNdPowersOfTen[];

/*
 * Writes `value` (below 10^17) as decimal text, padded with zeros to `figure` digits.
 * Returns the number of characters written, or -1 when the value is too large.
 */
int DWCi_Ndi_intToStrFigure(char *buffer, u64 value, int figure)
{
    int i;
    int started;
    unsigned int digit;
    int len = 0;

    if (value >= 100000000000000000ULL)
        return -1;
    for (i = 0, started = 0; i < 16; i++) {
        if (value >= sDwciNdPowersOfTen[i]) {
            digit = value / sDwciNdPowersOfTen[i];
            value -= (u64)digit * sDwciNdPowersOfTen[i];
            buffer[len] = digit + '0';
            started = 1;
        } else {
            if (started == 0 && 17 - i > figure)
                continue;
            buffer[len] = '0';
        }
        len++;
    }
    buffer[len] = value + '0';
    return len + 1;
}

/*
 * Writes the low `figure` hex digits of `value` in lower case, most significant first.
 * Returns the number of characters written, or -1 when `figure` exceeds 8.
 */
int DWCi_Ndi_hexToStrFigure(char *buffer, unsigned long value, int figure)
{
    int i;
    unsigned long digit;
    int len = 0;

    if (figure > 8)
        return -1;
    for (i = 1; i <= figure; i++) {
        digit = (value >> ((figure - i) * 4)) & 0xf;
        if (digit < 10)
            buffer[len++] = digit + '0';
        else
            buffer[len++] = digit + 'a' - 10;
    }
    return len;
}
