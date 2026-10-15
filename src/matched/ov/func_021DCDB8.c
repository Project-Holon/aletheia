/*
 * function: BOX2_MAIN_CreatePalAnm
 * address:  0x021DCDB8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *
 * Allocate 76 bytes, keep the handle, then configure it.
 */
#include "../include/Obj12146.h"
#include "../include/Obj18439.h"
#include "../include/Obj18440.h"

typedef unsigned int   u32;
struct PalAnmSlot;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

void BOX2_MAIN_CreatePalAnm(char *p)
{
    int v = (int)PALANM_Create(0x4c);

    ((struct Obj18439 *)(*(char * *)&((struct Obj12146 *)p)->f2C))->f6C = v;
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(((struct Obj18440 *)(*(char * *)&((struct Obj12146 *)p)->f2C))->f6C), 0, 0x200, 0x4c);
}

