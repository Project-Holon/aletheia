/*
 * function: PLIST_MESSAGE_RequestPrompt
 * address:  0x021BBA68
 * packet:   pkt_ov091_021BBA68
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled store-and-return leaf (listed as .word at 0x021BBA68) called
 * from POKELIST_UpdatePhase with (p, *(p + 0x150)).
 */
#include "../include/Obj20898.h"

typedef unsigned char u8;

void PLIST_MESSAGE_RequestPrompt(u8 *p, u8 *s)
{
    ((struct Obj20898 *)s)->f30 = 1;
}
