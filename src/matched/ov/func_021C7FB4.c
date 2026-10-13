/*
 * function: FIELDSKILL_MAPEFF_Apply
 * address:  0x021C7FB4
 * packet:   pkt_021C8000
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELDSKILL_MAPEFF_ApplyFlash with no argument change.
 *
 * symbols:
 *   FIELDSKILL_MAPEFF_ApplyFlash  0x021C800C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELDSKILL_MAPEFF_ApplyFlash(u8 *p);

void FIELDSKILL_MAPEFF_Apply(u32 a)
{
    FIELDSKILL_MAPEFF_ApplyFlash((u8 *)a);
}
