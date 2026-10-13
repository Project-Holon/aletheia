/*
 * function: func_021BC88C
 * address: 0x021BC88C
 * packet: pkt_ov209_021BC88C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 */
#include "../include/Obj00123.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);
void func_021BC88C(char *p) { ((struct Obj00123 *)p)->fC38=POKE_PERSONAL_LoadFormTable(107,0); }
