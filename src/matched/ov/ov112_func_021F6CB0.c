/*
 * function: STA_ACT_LIGHT_UpdateElemActors
 * address: 0x021F6CB0
 * packet: pkt_ov112_021F6CB0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STA_ACT_LIGHT_PlaceActor 0x021F6CE0 thumb ov112
 *   STA_ACT_LIGHT_UpdateActor 0x021F6D68 thumb ov112
 */
#include "../include/Obj00771.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void STA_ACT_LIGHT_PlaceActor(char *,char *);
extern void STA_ACT_LIGHT_UpdateActor(char *);
void STA_ACT_LIGHT_UpdateElemActors(char *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*32+8)) STA_ACT_LIGHT_PlaceActor(p,p+8+i*32); if(*(int *)&((struct Obj00771 *)p)->f4) STA_ACT_LIGHT_UpdateActor(p); }
