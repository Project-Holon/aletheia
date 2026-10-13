/*
 * function: BSUBWAY_SCR_PackBattleMon
 * address:  0x021CA3B4
 * packet:   pkt_ov021_021CA3B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Packs one party member into a 0x3c-byte slot: species/form, item, four moves with their PP-up bits, ids, stats and nickname.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 species : 11;
    u16 form    : 5;
    u16 item;
    u16 moves[4];
    u32 f0c;
    u32 f10;
    u32 f14;
    u8  f18[6];
    u8  ppups;
    u8  f1f;
    u8  f20;
    u8  f21;
    u16 name[13];
} Slot;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

void BSUBWAY_SCR_PackBattleMon(Slot *s, u32 m)
{
    int i;

    s->species = POKE_TOOL_GetPartyValue((void *)m, 5, 0);
    s->form = POKE_TOOL_GetPartyValue((void *)m, 0x6f, 0);
    s->item = POKE_TOOL_GetPartyValue((void *)m, 6, 0);
    for (i = 0; i < 4; i++) {
        s->moves[i] = POKE_TOOL_GetPartyValue((void *)m, 0x36 + i, 0);
        s->ppups |= POKE_TOOL_GetPartyValue((void *)m, 0x3e + i, 0) << (i * 2);
    }
    s->f1f = POKE_TOOL_GetPartyValue((void *)m, 0xc, 0);
    s->f0c = POKE_TOOL_GetPartyValue((void *)m, 7, 0);
    s->f10 = POKE_TOOL_GetPartyValue((void *)m, 0, 0);
    s->f14 = POKE_TOOL_GetPartyValue((void *)m, 0xac, 0);
    for (i = 0; i < 6; i++)
        s->f18[i] = POKE_TOOL_GetPartyValue((void *)m, 0xd + i, 0);
    s->f20 = POKE_TOOL_GetPartyValue((void *)m, 0xa, 0);
    s->f21 = POKE_TOOL_GetPartyValue((void *)m, 9, 0);
    POKE_TOOL_GetPartyValue((void *)m, 0x74, (u32)s->name);
}
