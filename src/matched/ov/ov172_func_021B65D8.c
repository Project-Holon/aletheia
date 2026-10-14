/*
 * function: CTVT_CAMERA_OnBufferError
 * address:  0x021B65D8
 * packet:   pkt_021B6A00
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs the two ARM9 state probes and sets the +0x24/+0x1c flags on the global object.
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021B6608  0x021B6608  arm    ov172
 *   func_021B6610  0x021B6610  arm    ov172
 *   func_021B6618  0x021B6618  arm    ov172
 *   g_021C88E0     0x021C88E0  data
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14292.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int OS_IsRunOnTwl(void *p);
extern void func_021B6608(void);
extern u32 func_021B6610(u32 a);
extern void func_021B6618(void);
extern u32 g_021C88E0;

void CTVT_CAMERA_OnBufferError(void)
{
    u32 *p = (u32 *)g_021C88E0;

    if (OS_IsRunOnTwl(&g_021C88E0) == 1)
        func_021B6608();
    if (OS_IsRunOnTwl((void *)func_021B6610(1)) == 1)
        func_021B6618();
    ((struct Obj14292 *)p)->f24 = 1;
    ((struct Obj14292 *)p)->f1C = 1;
}
