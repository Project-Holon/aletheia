/*
 * function: FLDMMDL_BLACT_DeleteActorMmdl
 * address:  0x0219C8D4
 * packet:   pkt_ov021_0219C8D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_CancelReservedActor  0x0219D184  thumb  ov021
 *   FLDMMDL_BLACT_IsCodeChangePending  0x0219D3B4  thumb  ov021
 *   FLDMMDL_BLACT_DeleteActorRes  0x0219C880  thumb  ov021
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm

 * Addresses are Black-image addresses.
 */
#include "../include/Obj00429.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FLDMMDL_GetObjCode(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern void FLDMMDL_BLACT_CancelReservedActor(int *obj, int key);
extern int FLDMMDL_BLACT_IsCodeChangePending(u8 *, u32, u16);
extern void FLDMMDL_BLACT_DeleteActorRes(u8 *o, u32 a, u32 b, u32 c);
struct BbActSys;
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);

void FLDMMDL_BLACT_DeleteActorMmdl(u32 o, u32 a)
{
    u32 t = FLDMMDL_GetObjCode((void *)o);
    u8 *c = (u8 *)FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)o));
    if (a == 0xFFFF) {
        FLDMMDL_BLACT_CancelReservedActor((int *)c, (u32)o);
        return;
    }
    if (FLDMMDL_BLACT_IsCodeChangePending(c, o, a) != 1) {
        FLDMMDL_BLACT_DeleteActorRes(c, o, (u16)a, t);
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)(((struct Obj00429 *)c)->f4), a, 1);
    }
}
