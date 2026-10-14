/*
 * function: CTVT_CAMERA_GetSizeWidth
 * address:  0x021B697C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Guard on 0x02085D3C then an arm veneer call with the field at +0x30.
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021B6994  0x021B6994  arm  ov172
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24061.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int OS_IsRunOnTwl(void *p);
extern int func_021B6994(u32 v);

int CTVT_CAMERA_GetSizeWidth(void *p)
{
    u32 f = ((struct Obj24061 *)p)->f30;
    if (OS_IsRunOnTwl(p) == 1) {
        return func_021B6994(f);
    }
    return 0;
}
