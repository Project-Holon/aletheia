/*
 * function: EVENT_RECOVERY_IsMachineAnimeDone
 * address:  0x021C0C80
 * packet:   pkt_021C0C80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_BUILDMODEL_TryOpenNodeCurrentSlot  0x0218C8D8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00959.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FIELD_BUILDMODEL_TryOpenNodeCurrentSlot(void *p);

int EVENT_RECOVERY_IsMachineAnimeDone(u32 a)
{
if (*(u32 *)&((struct Obj00959 *)((u8 *)(a)))->f34 != 0) {
    return FIELD_BUILDMODEL_TryOpenNodeCurrentSlot((void *)(*(u32 *)&((struct Obj00959 *)((u8 *)(a)))->f38));
}
return 1;
}

