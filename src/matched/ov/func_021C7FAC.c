/*
 * function: FIELDSKILL_MAPEFF_Update
 * address:  0x021C7FAC
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELDSKILL_MAPEFF_UpdateFlash with no argument change.
 *
 * symbols:
 *   FIELDSKILL_MAPEFF_UpdateFlash  0x021C8000  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELDSKILL_MAPEFF_UpdateFlash(u8 *p);

void FIELDSKILL_MAPEFF_Update(u32 a)
{
    FIELDSKILL_MAPEFF_UpdateFlash((u8 *)a);
}
