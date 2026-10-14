/*
 * function: GURU2_MAIN_CreatePaletteAnim
 * address: 0x021DFEC4
 * packet: pkt_ov137_021DFEC4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 */
#include "../include/Obj00835.h"
typedef unsigned int u32;struct PalAnmSlot;
extern void *PALANM_Create(u32);extern void PALANM_SetAutoTransfer(struct PalAnmSlot *,int);extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *,u32,u32,u32);
void GURU2_MAIN_CreatePaletteAnim(char *p){*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78=PALANM_Create(114);PALANM_SetAutoTransfer(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1);PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,0,512,114);PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1,512,114);}
