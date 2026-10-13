/*
 * function: func_0217D2BC
 * address: 0x0217D2BC
 * packet: pkt_ov176_0217D2BC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00053.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_0200BAF4(int,int);
extern int POKE_REGULATION_GetDataSize(void);
extern void func_02082D44(void *,const void *,u32);
extern u32 func_020307B0(void *p);
void func_0217D2BC(u8 *p,const void *q) {void *v;v=func_0200BAF4((int)func_0200BAC8(GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8)),((struct Obj00053 *)p)->f1C8);func_02082D44(v,q,POKE_REGULATION_GetDataSize());func_020307B0(v);}
