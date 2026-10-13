/*
 * function: FIELD_CAMERA_GetSettingId
 * address:  0x0218E188
 * packet:   pkt_ov021_0218E188
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (ldr r0,[r0,#0x10]; bx lr), filed for lane S30 (callee of
 * WEATHER_TASK_GetCameraState).
 *
 * symbols:
 *   FIELD_CAMERA_GetSettingId 0x0218E188 thumb ov021
 */
#include "../include/Obj19558.h"

int FIELD_CAMERA_GetSettingId(unsigned char *o)
{
    return ((struct Obj19558 *)o)->f10;
}
