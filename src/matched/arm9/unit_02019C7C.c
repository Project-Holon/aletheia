/*
 * unit:     yes
 * address:  0x02019C7C
 * packet:   pkt_02019388
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKE_TOOL_GetPersonalAbilityCount, POKE_TOOL_GetPersonalParam, POKE_TOOL_SetLevelAndRecalc, POKE_TOOL_CopyPartyPokemon
 *
 * POKE_TOOL_CopyPartyPokemon carries no label in the generated listing: it saves r3 and r4
 * but not lr, so disasm.py's prologue sweep never fires on it and its 24 bytes
 * arrive as a run of .word between two literal pools.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.  It is one
 * struct assignment: 27 ldm/stm pairs of eight bytes plus a trailing word is
 * 0xDC bytes, and the eight byte step is what says the record is at least four
 * aligned, which is docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md.
 *
 * The range stops at 0x02019CF8, which is an eight byte tail call whose pool
 * word names 0x02019BBC.  That address carries no func_ label and no other
 * pool word in the image holds it, so neither the label nor the literal class
 * can attest it and the stub cannot be matched from either side.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetExpForLevel  0x02018584  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_GetPersonalData  0x02019C54  thumb
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32  POKE_TOOL_GetExpForLevel(u16 a, u16 b, u16 v);
extern void POKE_TOOL_RecalcParam(void *p);
struct Personal;
extern void *POKE_TOOL_GetPersonalData(u32 a, u32 b);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

struct RecDC {
    u32 unk00[0x37];
};

u32 POKE_TOOL_GetPersonalAbilityCount(void *h)
{
    if (POKE_PERSONAL_GetParam(h, 0x1B) != 0) {
        return 2;
    }
    return 1;
}

u32 POKE_TOOL_GetPersonalParam(u16 a, u16 b, u32 k)
{
    return POKE_PERSONAL_GetParam(POKE_TOOL_GetPersonalData(a, b), k);
}

void POKE_TOOL_SetLevelAndRecalc(void *p, u32 v)
{
    u32 a = POKE_TOOL_GetPartyValue(p, 5, 0);
    u32 b = POKE_TOOL_GetPartyValue(p, 0x6F, 0);

    POKE_TOOL_SetPartyValue(p, 8, POKE_TOOL_GetExpForLevel((u16)a, (u16)b, (u16)v));
    POKE_TOOL_RecalcParam(p);
}

void POKE_TOOL_CopyPartyPokemon(const struct RecDC *src, struct RecDC *dest)
{
    *dest = *src;
}
