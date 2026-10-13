/*
 * function: func_021D81EC
 * address: 0x021D81EC
 * packet: pkt_ov116_021D81EC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 */
#include "../include/Obj10346.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GAME_DATA_SaveMain(u8 *);
int func_021D81EC(u8 *p) { if(((struct Obj10346 *)p)->fB6A==0) return 1; if(GAME_DATA_SaveMain(*(u8 * *)&((struct Obj10346 *)p)->f1844)==2) { ((struct Obj10346 *)p)->fB6A=0; return 1; } return 0; }
