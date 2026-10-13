/*
 * function: FLDMMDL_DRAW_ShiftOffsetByDir
 * address:  0x0219FAB4
 * packet:   pkt_ov021_0219FAB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

void FLDMMDL_DRAW_ShiftOffsetByDir(u32 a, u32 b, u8 *c, int *d)
{
    if (c[7] == 0) {
        switch (b) {
        case 2:
            *d -= 0x2000;
            break;
        case 3:
            *d += 0x2000;
            break;
        }
    }
}
