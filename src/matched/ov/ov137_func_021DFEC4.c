/*
 * function: func_021DFEC4
 * address: 0x021DFEC4
 * packet: pkt_ov137_021DFEC4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021518 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 */
#include "../include/Obj00835.h"
typedef unsigned int u32;struct PalAnmSlot;
extern void *func_02021518(u32);extern void PALANM_SetAutoTransfer(struct PalAnmSlot *,int);extern void func_0202155C(struct PalAnmSlot *,u32,u32,u32);
void func_021DFEC4(char *p){*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78=func_02021518(114);PALANM_SetAutoTransfer(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1);func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,0,512,114);func_0202155C(*(struct PalAnmSlot * *)&((struct Obj00835 *)p)->fD78,1,512,114);}
