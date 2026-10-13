/*
 * function: FIELD_BUILDMODEL_IsSlotIdle
 * address:  0x0218C43C
 * packet:   pkt_ov021_0218C43C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reports whether slot i (0 if out of range) is in state 0 or 2.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int FIELD_BUILDMODEL_IsSlotIdle(u32 *st, int i)
{
    u8 j = i;

    if (j >= 4)
        j = 0;
    switch ((st + j)[2]) {
    case 0:
        return 1;
    case 1:
        return 0;
    case 2:
        return 1;
    case 3:
    case 4:
        return 0;
    }
    return 0;
}
