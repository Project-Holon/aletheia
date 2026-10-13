/*
 * function: FIELD_MSGBG_IsSetupDone
 * address:  0x021903CC
 * packet:   pkt_ov021_021903CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf predicate, called from EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn.
 */
#include "../include/Obj19582.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

int FIELD_MSGBG_IsSetupDone(u8 *p)
{
    if (((struct Obj19582 *)p)->f16C == 0)
        return 1;
    return 0;
}
