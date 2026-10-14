/*
 * function: ZUKAN_LIST_StoreLastViewedSpecies
 * address: 0x021BD314
 * packet: pkt_ov209_021BD314
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_IsSpeciesEntryValid 0x021BD2F4 thumb ov209
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 */
#include "../include/Obj00088.h"
#include "../include/Obj25556.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int ZUKAN_LIST_IsSpeciesEntryValid(char *,int);extern u32 FRAME_LIST_GetItemValue(char *,int);extern void ZUKAN_SAVE_SetLastViewedSpecies(void *,u16);
void ZUKAN_LIST_StoreLastViewedSpecies(char *p,int i) { if(ZUKAN_LIST_IsSpeciesEntryValid(p,i)==1)ZUKAN_SAVE_SetLastViewedSpecies(((struct Obj25556 *)(*(char * *)&((struct Obj00088 *)p)->f0))->f4,FRAME_LIST_GetItemValue(*(char * *)&((struct Obj00088 *)p)->fC2C,i)); }
