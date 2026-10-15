/*
 * function: BSUBWAY_SCR_GetMmdlParam
 * address:  0x021CBBA0
 * packet:   pkt_ov021_021CBBA0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call into ov010 with a fixed second argument of 1 (unlabelled start).
 *
 * symbols:
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FLDMMDL_GetParam(char *a0, int a1);

u32 BSUBWAY_SCR_GetMmdlParam(u32 a)
{
    return FLDMMDL_GetParam((char *)a, 1);
}
