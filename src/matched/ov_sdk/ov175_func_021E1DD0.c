/*
 * function: DWCi_GdbStartRequestResultToError
 * address:  0x021E1DD0
 * packet:   pkt_021E1DD0
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
 * Session-state translation: the state word is parked at 0x13 up front, then
 * the caller's mode picks the reported code, with mode 0 also clearing the
 * word and mode 2 parking 9 and reporting 1.
 */

typedef signed int s32;

s32 DWCi_GdbStartRequestResultToError(s32 a, s32 *st)
{
    *st = 0x13;
    switch (a) {
    case 0:
        *st = 0;
        return 0;
    case 1:
        return 5;
    case 2:
        *st = 9;
        return 1;
    case 3:
        return 6;
    case 4:
        return 7;
    case 5:
        return 8;
    case 6:
        return 9;
    case 7:
        return 0xa;
    case 8:
        return 0xb;
    case 9:
        return 0xc;
    case 10:
        return 0xd;
    case 11:
        return 0xe;
    case 12:
        return 0xf;
    case 13:
        return 0x10;
    case 14:
        return 0x11;
    default:
        return 0x11;
    }
}
