/*
 * function: POKELIST_GetFieldMoveMenuIndex
 * address:  0x021B99E4
 * packet:   pkt_ov091_021B99E4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned int u32;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int POKELIST_GetFieldMoveMenuIndex(void *p, int i)
{
    switch (POKE_TOOL_GetPartyValue(p, i + 0x36, 0)) {
    case 0xf:
        return 0xb;
    case 0x13:
        return 0xf;
    case 0x39:
        return 0xc;
    case 0x46:
        return 0xe;
    case 0x7f:
        return 0xd;
    case 0x94:
        return 0x10;
    case 0x64:
        return 0x11;
    case 0x5b:
        return 0x12;
    case 0xe6:
        return 0x13;
    case 0x1c0:
        return 0x14;
    case 0x123:
        return 0x15;
    case 0xd0:
        return 0x16;
    case 0x87:
        return 0x17;
    }
    return 0;
}
