/*
 * function: func_021D43F4
 * address: 0x021D43F4
 * packet: pkt_ov115_021D43F4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_02009CC0 0x02009CC0 thumb
 *   func_02008540 0x02008540 thumb
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   func_021D43CC 0x021D43CC thumb ov115
 */
#include "../include/Obj06413.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int func_021D5C70(int); extern void func_021D426C(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern u8 *GAME_DATA_GetMyStatus(void *); extern void *func_02009CC0(void *); extern void func_02008540(void *,void *); extern void GAME_DATA_SaveStart(u8 *); extern void func_021D43CC(u8 *);
void func_021D43F4(u8 *p) { void *a; if(func_021D5C70(((struct Obj06413 *)p)->f38)) { a=GAME_DATA_GetMyStatus(((struct Obj06413 *)p)->f44); func_02008540(a,func_02009CC0(((struct Obj06413 *)p)->f3C)); GAME_DATA_SaveStart(*(u8 * *)&((struct Obj06413 *)p)->f44); ((struct Obj06413 *)p)->f24=1; func_021D426C(p,(u32)func_021D43CC); } }
