/*
 * function: FLDMMDL_MOVECODE_EndMirrorTurn
 * address:  0x0219B404
 * packet:   pkt_ov021_0219B404
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ClearStatusBit  0x0216D550  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 *FLDMMDL_ClearStatusBit(u32 *p, u32 v);

void FLDMMDL_MOVECODE_EndMirrorTurn(u32 a, u8 *s)
{
    if (s[2] == 0) {
        FLDMMDL_ClearStatusBit((u32 *)a, 8);
    }
}
