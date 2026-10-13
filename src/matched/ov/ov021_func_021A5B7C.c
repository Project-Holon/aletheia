/*
 * function: FIELD_PLAYER_NOGRID_UpdateSpin
 * address:  0x021A5B7C
 * packet:   pkt_ov021_021A5B7C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_NOGRID_HasFlags  0x021A66F8  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StartSpin  0x021A6B08  thumb  ov021
 *   FIELD_PLAYER_NOGRID_StopSpin  0x021A6B30  thumb  ov021
 *   FIELD_PLAYER_NOGRID_AdvanceSpin  0x021A6B50  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19806.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern int  FIELD_PLAYER_NOGRID_HasFlags(u8 *p, u32 f);
extern void FIELD_PLAYER_NOGRID_StartSpin(u8 *p, u32 v);
extern void FIELD_PLAYER_NOGRID_StopSpin(u8 *p);
extern void FIELD_PLAYER_NOGRID_AdvanceSpin(u8 *p, u32 v);

void FIELD_PLAYER_NOGRID_UpdateSpin(u8 *p)
{
    if (FIELD_PLAYER_NOGRID_HasFlags(p, 8)) {
        FIELD_PLAYER_NOGRID_StartSpin(p + 8, 0);
    } else if (FIELD_PLAYER_NOGRID_HasFlags(p, 0x10)) {
        FIELD_PLAYER_NOGRID_StartSpin(p + 8, 1);
    } else {
        FIELD_PLAYER_NOGRID_StopSpin(p + 8);
    }
    FIELD_PLAYER_NOGRID_AdvanceSpin(p + 8, ((struct Obj19806 *)p)->f1C);
}
