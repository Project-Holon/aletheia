/*
 * function: func_021D81D0
 * address: 0x021D81D0
 * packet: pkt_ov116_021D81D0
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 */
#include "../include/Obj13870.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GAME_DATA_SaveStart(int);
void func_021D81D0(u8 *p) { GAME_DATA_SaveStart(((struct Obj13870 *)p)->f1844); ((struct Obj13870 *)p)->fB6A=1; }
