/*
 * function: WF2DMAP_OBJDRAW_RemoveActor
 * address:  0x021C5704
 * packet:   pkt_021C5704
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WIFI_2DCHAR_DeleteActor  0x021C41BC  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23045.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void WIFI_2DCHAR_DeleteActor(u8 *p);
extern void MI_CpuFill8(void *, int, int);

void WF2DMAP_OBJDRAW_RemoveActor(u8 *p)
{
    WIFI_2DCHAR_DeleteActor(((struct Obj23045 *)p)->f4);
    MI_CpuFill8(p, 0, 0x14);
}
