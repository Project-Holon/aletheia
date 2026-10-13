/*
 * function: DWCi_GdbStartupResultToError
 * address:  0x021E1D70
 * packet:   pkt_021E1D70
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * ARM jump-table selector: four values map to a threshold stored through the
 * out pointer and to a distinct status code, anything else is 0x11.
 */

typedef int s32;

s32 DWCi_GdbStartupResultToError(s32 a, s32 *p)
{
    switch (a) {
    case 0:
        *p = 0;
        return 0;
    case 1:
        *p = 8;
        return 2;
    case 2:
        *p = 8;
        return 3;
    case 3:
        *p = 9;
        return 1;
    }
    return 0x11;
}
