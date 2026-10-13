/*
 * function: FIELD_EFFECT_Update
 * address:  0x021ABE04
 * packet:   pkt_021ABE04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: forwards to FIELD_EFFECT_RunTasks with no argument change.
 *
 * symbols:
 *   FIELD_EFFECT_RunTasks  0x021ABFDC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void FIELD_EFFECT_RunTasks();

void FIELD_EFFECT_Update(u32 a)
{
    FIELD_EFFECT_RunTasks();
}
