/*
 * function: FIELD_EVENT_CHECK_GetEggCycleDecrement
 * address:  0x0218AA2C
 * packet:   pkt_ov021_0218AA2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 2 when a non-egg party member holds item 0x31 or 0x28, else 1.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   POKEPARTY_GetMember  0x0201AB28  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

int FIELD_EVENT_CHECK_GetEggCycleDecrement(void *party)
{
    int count = POKEPARTY_GetCount(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = POKEPARTY_GetMember(party, i);
        u32 item = POKE_TOOL_GetPartyValue(mon, 0xA, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0 && (item == 0x31 || item == 0x28))
            return 2;
    }
    return 1;
}
