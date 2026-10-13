/*
 * function: func_021B81F4
 * address: 0x021B81F4
 * packet: pkt_ov070_021B81F4
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B81B0 0x021B81B0 thumb ov070
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   func_0204B878 0x0204B878 arm
 */
#include "../include/Obj04328.h"

typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021B81B0(int x);
extern int GAME_DATA_CheckSaveFlag(int p, int a);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
void func_021B81F4(u8 *p) { if (((struct Obj04328 *)p)->f81C!=1) func_0204B878(((struct Obj04328 *)p)->f718,(unsigned int)GAME_DATA_CheckSaveFlag(*(int *)&((struct Obj04328 *)p)->f0,func_021B81B0(((struct Obj04328 *)p)->f80C))+6u); }
