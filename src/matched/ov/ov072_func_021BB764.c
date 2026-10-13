/*
 * function: TOWNMAP_GRH_GetBgId
 * address: 0x021BB764
 * packet: pkt_ov072_021BB764
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sTownMapGrhBgTable 0x021BBC28 data a4
 */

#include "../include/G_Ent.h"

typedef unsigned int u32;
typedef unsigned char u8;
extern struct Ent sTownMapGrhBgTable;
u8 TOWNMAP_GRH_GetBgId(int unused, u32 i) { return *(u32 *)((u32)&(*(u32 *)&sTownMapGrhBgTable) + i*40); }
