/*
 * function: WEATHER_TASK_GetCameraSettingId
 * address:  0x021A2148
 * packet:   pkt_ov021_021A2148
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf (ldr r0,[r0,#0x14]; ldr r3,[pc]; bx r3), filed
 * for lane S30 (callee of ov028 functions).
 *
 * symbols:
 *   FIELD_CAMERA_GetSettingId 0x0218E188 thumb ov021
 */
#include "../include/Obj19729.h"

int FIELD_CAMERA_GetSettingId(unsigned char *o);

int WEATHER_TASK_GetCameraSettingId(unsigned char *o)
{
    return FIELD_CAMERA_GetSettingId((unsigned char *)(((struct Obj19729 *)o)->f14));
}
