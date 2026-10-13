/*
 * function: func_021B9AD8
 * address: 0x021B9AD8
 * packet: pkt_ov205_021B9AD8
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021B9B02 follow; no follower.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_020071F0 0x020071F0 thumb
 *   func_02008DAC 0x02008DAC thumb
 */
#include "../include/Obj14632.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big; struct Sub02008C20Obj;extern void *GAME_DATA_GetSaveControl(struct Big *);extern void *GAME_DATA_GetTrainerRecord(int *);extern int func_020071F0(void *);extern u32 func_02008DAC(struct Sub02008C20Obj *,int,u32);
void func_021B9AD8(char *p) { void *save,*obj;save=GAME_DATA_GetSaveControl(*(struct Big * *)&((struct Obj14632 *)p)->f4);obj=GAME_DATA_GetTrainerRecord(*(int * *)&((struct Obj14632 *)p)->f4);if(func_020071F0(save)==0)func_02008DAC(obj,71,1); }
