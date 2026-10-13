/*
 * function: SODATEYA_RollAbilitySlot
 * address:  0x021C3D1C
 * packet:   pkt_ov021_021C3D1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_02005728  0x02005728  thumb  ov021
 *   SODATEYA_GetAbilitySlot  0x021C452C  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern u32 POKE_TOOL_GetPartyValue(void *a, u32 b, u32 c);
extern u32 func_02005728(u32 n);
typedef unsigned char  u8;
extern u8 SODATEYA_GetAbilitySlot(u32 a, u32 b, u32 c, u32 d);

void SODATEYA_RollAbilitySlot(u32 *p, u32 *q, u32 d)
{
    u32 a = POKE_TOOL_GetPartyValue((void *)p[1], 5, 0);
    u32 b = POKE_TOOL_GetPartyValue((void *)p[1], 0x6f, 0);
    u32 c = POKE_TOOL_GetPartyValue((void *)p[1], 0xa, 0);
    u32 k = (u32)SODATEYA_GetAbilitySlot((u16)a, (u16)b, (u16)c, d);
    u32 r = func_02005728(100);

    switch (k) {
    default:
    case 0:
        if (r < 0x50)
            q[0x13] = 0;
        else
            q[0x13] = 1;
        return;
    case 1:
        if (r < 0x14)
            q[0x13] = 0;
        else
            q[0x13] = 1;
        return;
    case 2:
        if (r < 0x14)
            q[0x13] = 0;
        else if (r < 0x28)
            q[0x13] = 1;
        else
            q[0x13] = 2;
        return;
    }
}
