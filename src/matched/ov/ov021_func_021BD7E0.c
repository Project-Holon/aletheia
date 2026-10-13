/*
 * function: EVENT_ENTRANCE_IN_RunCamera
 * address:  0x021BD7E0
 * packet:   pkt_ov021_021BD7E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03588.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Args;
struct Evt;
extern void *FIELDMAP_GetCamera(void *p);
extern int FIELD_CAMERA_HasDelay(u8 *a);
extern u32 FIELD_CAMERA_IsDelayEnabled(u8 *a);
extern void FIELD_CAMERA_EndDelay(u8 *a);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void *func_021A7E3C(struct Args *a);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);

u32 EVENT_ENTRANCE_IN_RunCamera(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 h = (u32)FIELDMAP_GetCamera((void *)(*(u32 *)&((struct Obj03588 *)p)->fC));

    switch (*st) {
    case 0:
        if (FIELD_CAMERA_HasDelay((u8 *)h) && FIELD_CAMERA_IsDelayEnabled((u8 *)h)) {
            FIELD_CAMERA_EndDelay((u8 *)h);
            *st = 1;
        } else {
            *st = 2;
        }
        return 0x21;
    case 1:
        if (!FIELD_CAMERA_HasDelay((u8 *)h)) {
            *st = 2;
            return 0x21;
        }
        if (FIELD_CAMERA_IsDelayEnabled((u8 *)h))
            break;
        FIELD_CAMERA_StopTargetTrace((u8 *)h);
        *st = 2;
        return 0x21;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)a, func_021A7E3C((struct Args *)((u32)p)));
        *st = 3;
        return 0x21;
    case 3:
        return 1;
    }
    return 0;
}
