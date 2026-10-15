/*
 * function: GTSNEGO_MSG_InitWindows
 * address: 0x021D6BB0
 * packet: pkt_ov120_021D6BB0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_DeleteTouchbar 0x021D698C thumb ov120
 *   GTSNEGO_DISP_CreateTouchbar 0x021D692C thumb ov120
 *   GTSNEGO_DISP_Noop 0x021D6810 thumb ov120
 *   GTSNEGO_MSG_CreateCursorActor 0x021D6E84 thumb ov120
 *   GTSNEGO_MSG_CreateIconActors 0x021D6EF4 thumb ov120
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj01540.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GTSNEGO_DISP_DeleteTouchbar(u8 *);
extern void GTSNEGO_DISP_CreateTouchbar(u8 *, int);
extern void GTSNEGO_DISP_Noop(u8 *, int);
extern void GTSNEGO_MSG_CreateCursorActor(u8 *);
extern void GTSNEGO_MSG_CreateIconActors(u8 *, int);
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void ARC_TOOL_DeleteHandle(void *);
void GTSNEGO_MSG_InitWindows(u8 *p, int n)
{
    void *t;
    GTSNEGO_DISP_DeleteTouchbar(p);
    GTSNEGO_DISP_CreateTouchbar(p, 8);
    GTSNEGO_DISP_Noop(p, 1);
    t = func_020490F4(144, ((struct Obj01540 *)p)->fF4);
    ((struct Obj01540 *)p)->f120 = ARC_UTIL_LoadPaletteDataFromHandle(t, 21, 0, (void **)(p + 0x11c), ((struct Obj01540 *)p)->fF4);
    ARC_UTIL_UploadPaletteFromHandle(t, 0, 5, 0, 320, 32, ((struct Obj01540 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    t = func_020490F4(32, ((struct Obj01540 *)p)->fF4);
    ARC_UTIL_UploadPaletteFromHandle(t, 0, 5, 0, 0, 256, ((struct Obj01540 *)p)->fF4);
    ARC_TOOL_DeleteHandle(t);
    GTSNEGO_MSG_CreateCursorActor(p);
    GTSNEGO_MSG_CreateIconActors(p, n);
    ((struct Obj01540 *)p)->f100 = 1;
}
