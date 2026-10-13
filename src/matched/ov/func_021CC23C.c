/*
 * function: FLD_TRADE_DumpPokemonParams
 * address:  0x021CC23C
 * packet:   pkt_021CC23C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Straight unrolled key list: 33 calls to POKE_TOOL_GetPartyValue(obj, key, 0).
 * EXACT* only because the follower at 0x021CC38C (`bx lr`) is an unlabelled
 * leaf, so the inferred extent runs long into its padding; report, not seeded.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 POKE_TOOL_GetPartyValue(void *obj, u32 key, u32 off);

void FLD_TRADE_DumpPokemonParams(int obj)
{
    POKE_TOOL_GetPartyValue((void *)obj, 0, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 5, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x6f, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 6, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 7, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 8, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 9, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0xa, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x6e, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x70, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0xb, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0xc, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0xd, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0xe, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0xf, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x10, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x11, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x12, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x13, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x14, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x15, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x16, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x17, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x18, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x46, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x47, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x48, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x49, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x4a, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x4b, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x9a, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x9e, 0);
    POKE_TOOL_GetPartyValue((void *)obj, 0x95, 0);
}
