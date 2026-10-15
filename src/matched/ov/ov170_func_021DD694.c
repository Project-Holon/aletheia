/*
 * function: BOX2_MAIN_HasOtherTradable
 * address:  0x021DD694
 * packet:   pkt_ov170_021DD694
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 */

extern unsigned POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, unsigned i);
extern unsigned POKE_TOOL_GetPartyValue(void *p, unsigned id, unsigned v);

int BOX2_MAIN_HasOtherTradable(void ***p, unsigned skip)
{
    unsigned i;
    for (i = 0; i < POKEPARTY_GetCount((*p)[2]); i++) {
        if (i != skip) {
            void *m = POKEPARTY_GetMember((*p)[2], i);
            if (POKE_TOOL_GetPartyValue(m, 0x4C, 0) == 0 && POKE_TOOL_GetPartyValue(m, 0xA0, 0) != 0)
                return 1;
        }
    }
    return 0;
}
