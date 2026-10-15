/*
 * function: BOX2_MAIN_GetPartyValueAt
 * address:  0x021DD25C
 * packet:   pkt_ov170_021DD25C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02007A18 0x02007A18 thumb
 */

extern unsigned POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *party, unsigned i);
extern unsigned POKE_TOOL_GetPartyValue(void *p, unsigned id, unsigned v);
extern unsigned func_02017E88(void *p, unsigned id, unsigned v);
typedef unsigned int   u32;
struct Sub020079BCEntry;
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

unsigned BOX2_MAIN_GetPartyValueAt(void ***p, unsigned short a, int box, unsigned id, unsigned v)
{
    if (a >= 0x1E) {
        if (a >= 0x1E)
            a -= 0x1E;
        if ((int)POKEPARTY_GetCount((*p)[2]) > a)
            return POKE_TOOL_GetPartyValue(POKEPARTY_GetMember((*p)[2], a), id, v);
    } else if (a != 0xFF) {
        void *m = func_02007A18((*p)[1], box, a);
        if (m != 0)
            return func_02017E88(m, id, v);
    }
    return 0;
}
