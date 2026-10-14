/*
 * function: CTVT_CAMVIEW_RequestShutterSound0
 * address:  0x021B7B64
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guarded flag set at +0x24.
 *
 * symbols:
 *   COMM_TVT_SYS_IsNetIdle  0x021BE100  thumb  ov172
 *   CTVT_CAMERA_RequestShutterSound0  0x021B69D0  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14297.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int COMM_TVT_SYS_IsNetIdle(void);
extern void CTVT_CAMERA_RequestShutterSound0(void *p);

void CTVT_CAMVIEW_RequestShutterSound0(int x, char *p)
{
    if (COMM_TVT_SYS_IsNetIdle() != 1) {
        return;
    }
    CTVT_CAMERA_RequestShutterSound0(((struct Obj14297 *)p)->fA4);
    ((struct Obj14297 *)p)->f24 = 1;
}
