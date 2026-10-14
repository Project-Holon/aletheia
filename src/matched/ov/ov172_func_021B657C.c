/*
 * function: CTVT_CAMERA_LoadShutterSound
 * address: 0x021B657C
 * packet: pkt_ov172_021B657C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CTVT_CAMERA_FreeShutterSound 0x021B65C4 thumb ov172
 *   ARC_TOOL_GetMemberSize 0x020490A8 arm
 *   GFL_NET_AllocAligned 0x0203D7C8 arm
 *   ARC_TOOL_ReadMember 0x02048F4C arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   d_021C71C0 0x021C71C0 data a4
 */
#include "../include/Obj01559.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void CTVT_CAMERA_FreeShutterSound(void *);
extern u32 ARC_TOOL_GetMemberSize(u32 a, u32 b);
extern void *GFL_NET_AllocAligned(u32, u32, const char *, u16);
extern void ARC_TOOL_ReadMember(void *dst, u32 archive_id, u32 member);
extern void DWCi_ScreenDC_FlushRange(void *, u32);
extern const char d_021C71C0[];
void CTVT_CAMERA_LoadShutterSound(char *obj, int mode)
{
    char *p = obj;
    int which = 0;
    u32 size;
    if (mode != 1) which = 1;
    CTVT_CAMERA_FreeShutterSound(p);
    which = (u16)which;
    size = ARC_TOOL_GetMemberSize(0xD4, which);
    ((struct Obj01559 *)p)->f4C = size;
    ((struct Obj01559 *)p)->f48 = GFL_NET_AllocAligned(((struct Obj01559 *)p)->f0, size, d_021C71C0, 0x13B);
    ARC_TOOL_ReadMember(((struct Obj01559 *)p)->f48, 0xD4, which);
    DWCi_ScreenDC_FlushRange(((struct Obj01559 *)p)->f48, ((struct Obj01559 *)p)->f4C);
}
