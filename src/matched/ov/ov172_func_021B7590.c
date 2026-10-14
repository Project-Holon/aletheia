/*
 * function: CTVT_CAMVIEW_IsShutterIdle
 * address:  0x021B7590
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guarded tail call of CTVT_CAMERA_IsShutterSoundIdle on the field at +0xa4.
 *
 * symbols:
 *   COMM_TVT_SYS_IsNetIdle  0x021BE100  thumb  ov172
 *   CTVT_CAMERA_IsShutterSoundIdle  0x021B688C  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02992.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int COMM_TVT_SYS_IsNetIdle(void);
extern int CTVT_CAMERA_IsShutterSoundIdle(void *p);

int CTVT_CAMVIEW_IsShutterIdle(int x, char *p)
{
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        return CTVT_CAMERA_IsShutterSoundIdle(((struct Obj02992 *)p)->fA4);
    }
    return 1;
}
