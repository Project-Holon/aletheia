/*
 * function: func_021BC800
 * address:  0x021BC800
 * packet:   pkt_ov210_021BC800
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);

void func_021BC800(u8 *p)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 1);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 2);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(*(u32 *)&((struct Obj00085 *)p)->fC), 3);
    PALANM_Delete((void *)(*(u32 *)&((struct Obj00085 *)p)->fC));
}
