/*
 * function: DWCi_GdbRequestResultToAsyncResult
 * address:  0x021E1F6C
 * packet:   pkt_021E1F6C
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
 * Mode table, 24 entries: the state word starts at 0x13, modes 0 and 6 park a
 * replacement first, and the reported code walks up from 1 with 0x1e/0x20/0x16
 * at the top of the table; the default reports the same 0x16 as mode 0x17 but
 * from its own out-of-line block.
 */

typedef signed int s32;

s32 DWCi_GdbRequestResultToAsyncResult(s32 a, s32 *st)
{
    *st = 0x13;
    switch (a) {
    case 0:
        *st = 0;
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
        return 4;
    case 4:
        return 5;
    case 5:
        return 6;
    case 6:
        *st = 9;
        return 7;
    case 7:
        return 8;
    case 8:
        return 9;
    case 9:
        return 0xa;
    case 10:
        return 0xb;
    case 11:
        return 0xc;
    case 12:
        return 0xd;
    case 13:
        return 0xe;
    case 14:
        return 0xf;
    case 15:
        return 0x10;
    case 16:
        return 0x11;
    case 17:
        return 0x12;
    case 18:
        return 0x13;
    case 19:
        return 0x14;
    case 20:
        return 0x15;
    case 21:
        return 0x1e;
    case 23:
        return 0x20;
    case 22:
        return 0x16;
    default:
        return 0x16;
    }
}
