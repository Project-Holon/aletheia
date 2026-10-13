/*
 * function: FLDMMDL_BLACT_DeleteActorPos
 * address:  0x0219C98C
 * packet:   pkt_ov021_0219C98C
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
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   BILLBOARD_ACT_GetEntrySlotIndex  0x020508D8  arm
 *   BILLBOARD_ACT_DeleteSlots  0x02050278  arm
 *   BILLBOARD_ACT_DeleteEntries  0x02050468  arm

 * Addresses are Black-image addresses.
 */
#include "../include/Obj09509.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BbActSys;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 BILLBOARD_ACT_GetEntrySlotIndex(u8 *o, u32 i);
extern void BILLBOARD_ACT_DeleteSlots(struct BbActSys *o, u32 first, u32 count);
extern void BILLBOARD_ACT_DeleteEntries(struct BbActSys *o, u16 first, u32 count);

void FLDMMDL_BLACT_DeleteActorPos(u32 a, u16 *b)
{
    u8 *c = (u8 *)FLDMMDL_SysGetBlActCont((void *)a);
    if (b[1] != 0xFFFF) {
        if (b[0] & 2) {
            u32 t = BILLBOARD_ACT_GetEntrySlotIndex((u8 *)(((struct Obj09509 *)c)->f4), b[1]);
            BILLBOARD_ACT_DeleteSlots((struct BbActSys *)(((struct Obj09509 *)c)->f4), t, 1);
        }
        BILLBOARD_ACT_DeleteEntries((struct BbActSys *)(((struct Obj09509 *)c)->f4), b[1], 1);
    }
    b[0] = 0;
    b[1] = 0xFFFF;
}
