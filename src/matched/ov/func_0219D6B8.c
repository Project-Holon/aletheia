/*
 * function: FLDMMDL_RAIL_MOVE_InitMove
 * address:  0x0219D6B8
 * packet:   pkt_0219D6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_CallMoveInitProc  0x0216D6F4  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern void FLDMMDL_CallMoveInitProc(void *a0);

int FLDMMDL_RAIL_MOVE_InitMove(u32 *a, u32 b, u32 c, u32 d)
{
FLDMMDL_CallMoveInitProc((void *)a);
return (int)FLDMMDL_SetStatusBit(a, 2);
}

