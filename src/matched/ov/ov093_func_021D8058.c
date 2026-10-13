/*
 * unit: yes
 * function: BTL_CALC_NoOp,BTL_CALC_GetMonParamWithHeap
 * address: 0x021D8058
 * packet: pkt_ov093_021D8058
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02020FE4 0x02020FE4 thumb
 *   gBtlCalcWork 0x021F6360 data ov093 a2
 */

#include "../include/G_Unk021F6360.h"

typedef unsigned short u16;
typedef unsigned int u32;
extern struct Unk021F6360 gBtlCalcWork;
extern u32 func_02020FE4(void *,u32,u32);
void BTL_CALC_NoOp(void) { }
u32 BTL_CALC_GetMonParamWithHeap(void *p,u32 n) { return func_02020FE4(p,n,(*(u16 *)&gBtlCalcWork)); }
