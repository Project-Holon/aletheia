/*
 * function: GTSNEGO_DISP_RedrawActors
 * address: 0x021D6814
 * packet: pkt_ov120_021D6814
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D68C2.
 * symbols:
 *   GTSNEGO_DISP_Noop 0x021D6810 thumb ov120
 *   GTSNEGO_MSG_CreateActorAt 0x021D6AF0 thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj06436.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_DISP_Noop(u8 *, int);
extern void GTSNEGO_MSG_CreateActorAt(u8 *, u16, u16, int);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
void GTSNEGO_DISP_RedrawActors(u8 *p)
{
    void *t;
    GTSNEGO_DISP_Noop(p, 0);
    t = func_020490F4(144, ((struct Obj06436 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t, 19, 4, 0, (u16)(((struct Obj06436 *)p)->f0), 0, 0, ((struct Obj06436 *)p)->fF4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(t, 20, 4, 0, (u16)(((struct Obj06436 *)p)->f0), 192, 0, ((struct Obj06436 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_MSG_CreateActorAt(p, 96, 56, 0);
    GTSNEGO_MSG_CreateActorAt(p, 240, 56, 1);
    GTSNEGO_MSG_CreateActorAt(p, 120, 96, 0);
    GTSNEGO_MSG_CreateActorAt(p, 240, 96, 1);
    GTSNEGO_MSG_CreateActorAt(p, 120, 136, 0);
    GTSNEGO_MSG_CreateActorAt(p, 240, 136, 1);
}
