/*
 * function: func_021B81B8
 * address: 0x021B81B8
 * packet: pkt_ov070_021B81B8
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B81B0 0x021B81B0 thumb ov070
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021B81F4 0x021B81F4 thumb ov070
 */
#include "../include/Obj04328.h"

typedef unsigned char u8;
extern int func_021B81B0(int x);
extern int GAME_DATA_CheckSaveFlag(int p, int a);
extern void GAME_DATA_SetSaveFlag(void *p, unsigned int a, unsigned int b);
extern void func_020061E4(unsigned int id);
extern void func_021B81F4(u8 *p);
void func_021B81B8(u8 *p) { int a; int v; a=func_021B81B0(((struct Obj04328 *)p)->f80C); v=GAME_DATA_CheckSaveFlag(*(int *)&((struct Obj04328 *)p)->f0,a); GAME_DATA_SetSaveFlag(((struct Obj04328 *)p)->f0,a,v^1); func_020061E4(0x646); func_021B81F4(p); }
