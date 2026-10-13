/*
 * function: BTL_CALC_SetHeapId
 * address: 0x021D804C
 * packet: pkt_ov093_021D804C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   gBtlCalcWork 0x021F6360 data ov093 a2
 */

#include "../include/G_Unk021F6360.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern struct Unk021F6360 gBtlCalcWork;
void BTL_CALC_SetHeapId(u32 n) { (*(u16 *)&gBtlCalcWork)=n; }
