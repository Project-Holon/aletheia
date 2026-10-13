/*
 * function: FIELD_EVENT_CHECK_IsEggReadyToHatch
 * address:  0x0218AB0C
 * packet:   pkt_ov021_0218AB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 when some egg in the party has field 9 (the step counter) at
 * zero.
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);

int FIELD_EVENT_CHECK_IsEggReadyToHatch(void *party)
{
    int count = func_0201AA18(party);
    int i;

    for (i = 0; i < count; i++) {
        void *mon = func_0201AB28(party, i);
        u32 flag = POKE_TOOL_GetPartyValue(mon, 0x4C, 0);
        u32 v = POKE_TOOL_GetPartyValue(mon, 9, 0);
        if (flag == 1 && v == 0)
            return 1;
    }
    return 0;
}
