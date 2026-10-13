/*
 * function: func_021D7430
 * address: 0x021D7430
 * packet: pkt_ov123_021D7430
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D73D8 0x021D73D8 thumb ov123
 */
#include "../include/Obj05364.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021D66D0(u8 *,int);
extern int GAME_DATA_SaveMain(u8 *p);
extern u32 func_020056EC(u32 range);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D73D8(char *p);
void func_021D7430(u8 *p) { if(((struct Obj05364 *)p)->f70<100) ++((struct Obj05364 *)p)->f70; func_021D66D0(*(u8 * *)&((struct Obj05364 *)p)->f14,((struct Obj05364 *)p)->f70); if(GAME_DATA_SaveMain(((struct Obj05364 *)p)->f2C)==1) { ((struct Obj05364 *)p)->f78=func_020056EC(190); func_021D6EE0((u8 *)p,(int)func_021D73D8,0x2e6); } }
