/*
 * function: func_021DFEFC
 * address: 0x021DFEFC
 * packet: pkt_ov137_021DFEFC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 */
#include "../include/Obj03842.h"
typedef unsigned int u32;struct PalAnmSlot;
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);extern void PALANM_Delete(struct PalAnmSlot *);
void func_021DFEFC(char *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78,1);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj03842 *)p)->fD78);}
