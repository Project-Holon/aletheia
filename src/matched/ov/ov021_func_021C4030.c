/*
 * function: SODATEYA_ApplyMasudaMethod
 * address:  0x021C4030
 * packet:   pkt_ov021_021C4030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_CheckShiny  0x02017ED8  thumb
 *   SODATEYA_RollRandomU32  0x021C4078  thumb  ov021
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern u32 POKE_TOOL_CheckShiny(u32 a, u32 b);
extern u32 SODATEYA_RollRandomU32(void);

void SODATEYA_ApplyMasudaMethod(u32 *p, u32 *q)
{
    int i = 0;
    u32 a = POKE_TOOL_GetPartyValue((void *)p[0], 0xc, 0);

    if (a == POKE_TOOL_GetPartyValue((void *)p[1], 0xc, 0))
        return;
    if (POKE_TOOL_CheckShiny(q[0xc], q[0xd]) != 0)
        return;
    do {
        q[0xd] = SODATEYA_RollRandomU32();
        if (POKE_TOOL_CheckShiny(q[0xc], q[0xd]) != 0)
            return;
        i++;
    } while (i < 5);
}
