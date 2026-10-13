/*
 * function: func_021FE8E8
 * address: 0x021FE8E8
 * packet: pkt_ov186_021FE8E8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PALANM_LoadHandlePaletteToSlotAt 0x02021660 thumb
 */
#include "../include/Obj24850.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PalAnmSlot; extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *,void *,u32,u32,u32,u32,u16,u16);
void func_021FE8E8(char *p,void *arc,u32 file,u32 idx,u32 off,u32 count,u16 tag) { PALANM_LoadHandlePaletteToSlotAt(*(struct PalAnmSlot * *)&((struct Obj24850 *)p)->f20,arc,file,tag,idx,count,off,0); }
