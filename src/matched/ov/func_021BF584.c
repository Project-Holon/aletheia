/*
 * function: EVENT_FIELDMAP_CONTROL_ResetBgAffine
 * address:  0x021BF584
 * packet:   pkt_021BF584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELDMAP_ResetBgAffineShowMsg with no argument change.
 *
 * symbols:
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELDMAP_ResetBgAffineShowMsg(u8 *a);

void EVENT_FIELDMAP_CONTROL_ResetBgAffine(u8 *a0)
{
    FIELDMAP_ResetBgAffineShowMsg(a0);
}
