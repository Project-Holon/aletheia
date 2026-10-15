/*
 * function: WORLDTRADE_Init
 * address:  0x0200AD7C
 * packet:   pkt_0200AD7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 18 lane ties_b: unlabelled follower of WORLDTRADE_GetSize; clears a 0xF8-byte record with MIi_CpuClearFast (tail call).
 *
 * symbols:
 *   MIi_CpuClearFast  0x02082AC0  arm
 */

typedef unsigned int u32;

extern void MIi_CpuClearFast(u32 val, void *dst, u32 size);

void WORLDTRADE_Init(void *rec)
{
    MIi_CpuClearFast(0, rec, 0xF8);
}
