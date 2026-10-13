/*
 * function: BSUBWAY_SCR_GetTrainerObjCode
 * address:  0x021CA150
 * packet:   pkt_ov021_021CA150
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-calls into ov010 with the halfword at +0x8c of the 0x120-byte entry i.
 *
 * symbols:
 *   FLD_BTL_INST_TOOL_LookupKeyValue  0x02168AEC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 FLD_BTL_INST_TOOL_LookupKeyValue(u16 a0);

u32 BSUBWAY_SCR_GetTrainerObjCode(u8 *p, int i)
{
    return FLD_BTL_INST_TOOL_LookupKeyValue(*(u16 *)(p + i * 0x120 + 0x8c));
}
