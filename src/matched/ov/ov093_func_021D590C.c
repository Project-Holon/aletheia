/*
 * function: BTL_POKEPARAM_ReadStatsFromMon
 * address:  0x021D590C
 * packet:   pkt_ov093_021D590C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Sav;
extern u32 POKE_TOOL_DecodePartyParam(struct Sav *p);
extern u32 POKE_TOOL_GetPartyValue(void *h, u32 k, u32 z);
extern u32 POKE_TOOL_EncodePartyParam(struct Sav *p, u32 f);

void BTL_POKEPARAM_ReadStatsFromMon(void **p, u16 *out)
{
    u8 v = POKE_TOOL_DecodePartyParam(*p);
    out[1] = POKE_TOOL_GetPartyValue(*p, 0xa1, 0);
    out[2] = POKE_TOOL_GetPartyValue(*p, 0xa2, 0);
    out[3] = POKE_TOOL_GetPartyValue(*p, 0xa3, 0);
    out[4] = POKE_TOOL_GetPartyValue(*p, 0xa5, 0);
    out[5] = POKE_TOOL_GetPartyValue(*p, 0xa6, 0);
    out[6] = POKE_TOOL_GetPartyValue(*p, 0xa4, 0);
    POKE_TOOL_EncodePartyParam(*p, v);
}
