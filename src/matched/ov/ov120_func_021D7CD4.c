/*
 * function: GTSNEGO_MSG_CreateRowEx
 * address:  0x021D7CD4
 * packet:   pkt_021D7CD4
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GTSNEGO_MSG_CreateRow  0x021D7C48  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int GTSNEGO_MSG_CreateRow(u8 *p, int n, int a, int b, int c, int d);

int GTSNEGO_MSG_CreateRowEx(int a, int b, int c, int d)
{
    return GTSNEGO_MSG_CreateRow((u8 *)a, b, c, d, 0x14, 6);
}
