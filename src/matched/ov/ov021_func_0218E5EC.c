/*
 * function: FIELD_CAMERA_ClearEyeTrace
 * address: 0x0218E5EC
 * packet: pkt_ov021_0218E5EC
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 *
 * Function with no listing label, matched inside src/game/ov021/field_msgbg.c and filed here.
 */

#include "../include/Obj00519.h"

typedef unsigned char  u8;
void FIELD_CAMERA_ClearEyeTrace(u8 *p);

/*
 * Hidden leaf setters of the FIELD_CAMERA_Create object (covered by no member).
 */
void FIELD_CAMERA_ClearEyeTrace(u8 *p)
{
    ((struct Obj00519 *)p)->f20 = 0;
}
