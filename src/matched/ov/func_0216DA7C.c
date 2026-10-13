/*
 * function: FLDMMDL_OffMoveBitMoveEnd
 * address:  0x0216DA7C
 * packet:   pkt_0216DA7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Thin wrapper: clear bit 6 of the word at +4 (tail call to FLDMMDL_ClearMoveBit).
 *
 * symbols:
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

void FLDMMDL_OffMoveBitMoveEnd(u8 *p)
{
FLDMMDL_ClearMoveBit((char *)p, 0x40);
}
