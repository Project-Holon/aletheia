/*
 * function: FIELD_EVENT_CHECK_DecrementEggCycles
 * address:  0x0218AA74
 * packet:   pkt_ov021_0218AA74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * For every egg in the party, lowers field 9 (the step counter) by the amount
 * from FIELD_EVENT_CHECK_GetEggCycleDecrement, clamping at zero.
 *
 * symbols:
 *   FIELD_EVENT_CHECK_GetEggCycleDecrement  0x0218AA2C  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern int FIELD_EVENT_CHECK_GetEggCycleDecrement(void *party);

void FIELD_EVENT_CHECK_DecrementEggCycles(void *party)
{
    int count = func_0201AA18(party);
    u32 amount = FIELD_EVENT_CHECK_GetEggCycleDecrement(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
        u32 v = POKE_TOOL_GetPartyValue(mon, 9, 0);
        if (flag == 1) {
            u32 nv = 0;
            if (v >= amount)
                nv = v - amount;
            POKE_TOOL_SetPartyValue(mon, 9, nv);
        }
    }
}
