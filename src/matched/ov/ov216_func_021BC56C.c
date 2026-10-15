/*
 * function: BEACON_DETAIL_GRA_FreeTrainerGfx
 * address: 0x021BC56C
 * packet: pkt_ov216_021BC56C
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_DETAIL_GRA_ReleaseActorGfx 0x021BC43C thumb ov216
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj14716.h"
extern void BEACON_DETAIL_GRA_ReleaseActorGfx(void *,char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(void *);
void BEACON_DETAIL_GRA_FreeTrainerGfx(char *p)
{
    int i;
    for(i=0;i<2;i++) BEACON_DETAIL_GRA_ReleaseActorGfx(p,p+0x68+i*12);
    for(i=0;i<16;i++) func_020307B0(*(void **)(p+0x90+i*8));
    func_020307B0(((struct Obj14716 *)p)->f114);
    BEACON_DETAIL_GRA_ReleaseActorGfx(p,p+0x80);
    BEACON_DETAIL_GRA_ReleaseActorGfx(p,p+0x5c);
    ARC_TOOL_DeleteHandle(((struct Obj14716 *)p)->f58);
}
