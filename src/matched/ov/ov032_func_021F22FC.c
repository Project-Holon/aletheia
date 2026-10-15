/*
 * function: BEACON_VIEW_Delete
 * address:  0x021F22FC
 * packet:   pkt_ov032_021F22FC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BEACON_VIEW_Delete 0x021F22FC thumb
 *   BEACON_VIEW_DeleteWindows 0x021F30B4 thumb
 *   BEACON_VIEW_DeleteActors 0x021F2FCC thumb
 *   BEACON_VIEW_FreeGraphics 0x021F2EDC thumb
 *   BEACON_VIEW_DeleteTaskMenuRes 0x021F2CC4 thumb
 *   BEACON_VIEW_FreeBackgrounds 0x021F2BD4 thumb
 *   BEACON_VIEW_DestroySubSystems 0x021F2A04 thumb
 *   BEACON_VIEW_FreeWorkResources 0x021F28DC thumb
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00812.h"

typedef unsigned int u32;

extern void BEACON_VIEW_DeleteWindows(char *p);
extern void BEACON_VIEW_DeleteActors(char *p);
extern void BEACON_VIEW_FreeGraphics(char *p);
extern void BEACON_VIEW_DeleteTaskMenuRes(char *p);
extern void BEACON_VIEW_FreeBackgrounds(char *p);
extern void BEACON_VIEW_DestroySubSystems(char *p);
extern void BEACON_VIEW_FreeWorkResources(char *p);
struct Tcbl;
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void ARC_TOOL_DeleteHandle(u32 a);
extern u32 func_020307B0(void *p);

void BEACON_VIEW_Delete(char *p)
{
    TCBL_DeleteAllTasks((struct Tcbl *)(((struct Obj00812 *)p)->fA0));
    BEACON_VIEW_DeleteWindows(p);
    BEACON_VIEW_DeleteActors(p);
    BEACON_VIEW_FreeGraphics(p);
    BEACON_VIEW_DeleteTaskMenuRes(p);
    BEACON_VIEW_FreeBackgrounds(p);
    BEACON_VIEW_DestroySubSystems(p);
    BEACON_VIEW_FreeWorkResources(p);
    ARC_TOOL_DeleteHandle(((struct Obj00812 *)p)->f9C);
    func_020307B0(p);
}
