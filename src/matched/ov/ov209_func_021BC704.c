/*
 * function: func_021BC704
 * address: 0x021BC704
 * packet: pkt_ov209_021BC704
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 */
#include "../include/Obj00088.h"
struct PalAnmSlot;extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);extern void PALANM_Delete(struct PalAnmSlot *);
void func_021BC704(char *p){PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,0);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,1);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,2);PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC,3);PALANM_Delete(*(struct PalAnmSlot * *)&((struct Obj00088 *)p)->fC);}
