/*
 * function: FLDMMDL_OnMoveBitMove
 * address:  0x0216DA44
 * packet:   pkt_0216DA44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to FLDMMDL_SetMoveBit with a masked second argument.
 *
 * symbols:
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *FLDMMDL_SetMoveBit(void *p, u32 v);


void FLDMMDL_OnMoveBitMove(u32 a)
{
    FLDMMDL_SetMoveBit((void *)a, 0x10);
}

