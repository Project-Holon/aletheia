/*
 * function: FIELD_PLAYER_GRID_GetHopAirResult
 * address:  0x021A4890
 * packet:   pkt_021A4890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckPossibleAcmd(int a0);

int FIELD_PLAYER_GRID_GetHopAirResult(u8 *a, u32 b, u32 c)
{
if (FLDMMDL_CheckPossibleAcmd(b) == 1) {
    return 9;
}
return 8;
}

