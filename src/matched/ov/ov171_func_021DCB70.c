/*
 * function: func_021DCB70
 * address:  0x021DCB70
 * packet:   pkt_021DCB70
 * region:   ov171
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 */
#include "../include/Obj24050.h"

typedef unsigned int   u32;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

void func_021DCB70(int *p)
{
    int x = (int)PALANM_Create(0x8c);

    ((struct Obj24050 *)p)->fB30 = x;
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)x, 2, 0x200, 0x8c);
}
