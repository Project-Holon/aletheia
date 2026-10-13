/*
 * function: FLDMMDL_BLACT_DeleteActorRes
 * address:  0x0219C880
 * packet:   pkt_ov021_0219C880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Former blocker (now filed in src/matched/arm9): the only unresolved site is the call to BILLBOARD_ACT_GetEntrySlotIndex
 * (0x020508D8, arm, arm9), an unlabelled arm9 leaf with no witness (the integrator's).
 * Verified C for the leaf (EXACT, dsi/1.1p1 -O4,p --arm --region arm9):
 *     u32 BILLBOARD_ACT_GetEntrySlotIndex(u8 *o, u32 i)
 *     {
 *         return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
 *     }
 *
 * symbols:
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   BILLBOARD_ACT_GetEntrySlotIndex  0x020508D8  arm
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   FLDMMDL_CheckSameObjCodeOther  0x0216DFC4  thumb  ov010
 *   FLDMMDL_BLACT_DeleteRes  0x0219CB98  thumb  ov021

 * Addresses are Black-image addresses.
 */
#include "../include/Obj00429.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BbActSys;
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern u32 BILLBOARD_ACT_GetEntrySlotIndex(u8 *o, u32 i);
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);
extern int FLDMMDL_CheckSameObjCodeOther(void *a, u32 id);
extern void FLDMMDL_BLACT_DeleteRes(u8 *, u32);

void FLDMMDL_BLACT_DeleteActorRes(u8 *o, u32 a, u32 b, u32 c)
{
    u16 v[2];
    if (FLDMMDL_BLACT_FindRes((u32)o, c, (u32)(&v[1]), (u32)(&v[0])) == 1) {
        if (v[0] & 2) {
            u32 t = BILLBOARD_ACT_GetEntrySlotIndex((u8 *)(((struct Obj00429 *)o)->f4), b);
            BILLBOARD_ACT_DeleteSlots((struct BbActSys *)(((struct Obj00429 *)o)->f4), t, 1);
        }
        if (v[0] & 1) {
            if (FLDMMDL_CheckSameObjCodeOther((void *)a, c) == 0)
                FLDMMDL_BLACT_DeleteRes(o, c);
        }
    }
}
