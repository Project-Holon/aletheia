/*
 * function: CTVT_CAMVIEW_StopCapture
 * address:  0x021B7578
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guarded call to CTVT_CAMERA_StopCapture.
 *
 * symbols:
 *   COMM_TVT_SYS_IsNetIdle  0x021BE100  thumb  ov172
 *   CTVT_CAMERA_StopCapture  0x021B6868  thumb  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06558.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int COMM_TVT_SYS_IsNetIdle(void);
extern void CTVT_CAMERA_StopCapture(char *p);

void CTVT_CAMVIEW_StopCapture(int x, char *p)
{
    if (COMM_TVT_SYS_IsNetIdle() == 1) {
        CTVT_CAMERA_StopCapture(((struct Obj06558 *)p)->fA4);
    }
}
