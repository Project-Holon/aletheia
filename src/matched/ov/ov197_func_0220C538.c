/*
 * function: B_BAG_MAIN_DisplaySingle
 * address: 0x0220C538
 * packet: pkt_ov197_0220C538
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_BAG_MAIN_LoadItemGraphic 0x0220C180 thumb ov197
 *   B_BAG_MAIN_PlaceActor 0x0220C4D4 thumb ov197
 *   B_BAG_MAIN_StartFingerCursor 0x0220C6F8 thumb ov197
 *   d_0220DB7C 0x0220DB7C data a4
 */
#include "../include/Obj01075.h"
#include "../include/Obj25036.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void B_BAG_MAIN_LoadItemGraphic(char *,u16,u32,u32);
extern void B_BAG_MAIN_PlaceActor(int,int);
extern void B_BAG_MAIN_StartFingerCursor(u8 *,u32,u32);
extern const int d_0220DB7C[];
void B_BAG_MAIN_DisplaySingle(char *p) { if(((struct Obj01075 *)p)->f540!=0) { B_BAG_MAIN_LoadItemGraphic(p,((struct Obj01075 *)p)->f540,6,6); B_BAG_MAIN_PlaceActor(((struct Obj01075 *)p)->f43C,(int)d_0220DB7C); } if(((struct Obj25036 *)(*(char * *)&((struct Obj01075 *)p)->f0))->f8==2) B_BAG_MAIN_StartFingerCursor((u8 *)p,192,24); }
