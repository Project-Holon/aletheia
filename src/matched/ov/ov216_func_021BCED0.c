/*
 * function: BEACON_DETAIL_GRA_TransferChar
 * address: 0x021BCED0
 * packet: pkt_ov216_021BCED0
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   BEACON_DETAIL_GRA_LoadPalette 0x021BCD08 thumb ov216
 *   d_021BDD92 0x021BDD92 data a1
 */
#include "../include/Obj14719.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub0204A9D0;
extern void CLACT_TransferCharacter(int,struct Sub0204A9D0*);
extern void BEACON_DETAIL_GRA_LoadPalette(void*,u32,u32,u32);
extern const u8 d_021BDD92[];
void BEACON_DETAIL_GRA_TransferChar(u8*p,u32 n){CLACT_TransferCharacter(((struct Obj14719 *)p)->f84,*(struct Sub0204A9D0**)((u32)p+n*8+0x8c));BEACON_DETAIL_GRA_LoadPalette((u8*)*(void* *)&((struct Obj14719 *)p)->f110+(d_021BDD92[n]&15)*32,2,160,16);}
