/*
 * function: GAME_BEACON_ACCESSOR_GetTrainerId
 * address:  0x02165CE4
 * packet:   pkt_ov010_02165CE4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as a blocker of ov032 BEACON_VIEW_SetupEntry.
 */
#include "../include/Obj19000.h"

typedef unsigned char  u8;
typedef unsigned short u16;

u16 GAME_BEACON_ACCESSOR_GetTrainerId(u8 *r)
{
    return ((struct Obj19000 *)r)->f10;
}
