/*
 * function: CTVT_CAMERA_SetSize
 * address: 0x021B6950
 * packet: pkt_ov172_021B6950
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   func_021B6974 0x021B6974 arm ov172
 *   CTVT_CAMERA_ResetTrimming 0x021B68A0 thumb ov172
 */
#include "../include/Obj01264.h"
extern int OS_IsRunOnTwl(void);
extern void func_021B6974(int, int, int);
extern void CTVT_CAMERA_ResetTrimming(char *);

void CTVT_CAMERA_SetSize(char *p, int v)
{
    if (OS_IsRunOnTwl() == 1) func_021B6974(3, 3, v);
    ((struct Obj01264 *)p)->f30 = v;
    CTVT_CAMERA_ResetTrimming(p);
}
