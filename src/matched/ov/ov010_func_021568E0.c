/*
 * function: MUSICAL_EVENT_GetLocalSlot
 * address:  0x021568E0
 * packet:   pkt_ov010_021568E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf between MUSICAL_EVENT_CountNpcSlotsBelow and MUSICAL_EVENT_GetPlayerOfSlot: returns the
 * byte at +0x4C.
 */

typedef unsigned char u8;

typedef struct Work {
    u8 pad[0x4C];
    u8 f4c;
} Work;

u8 MUSICAL_EVENT_GetLocalSlot(Work *w)
{
    return w->f4c;
}
