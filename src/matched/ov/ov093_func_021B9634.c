/*
 * function: BTL_MAIN_FindLastLivingPartyIndex
 * address:  0x021B9634
 * packet:   pkt_ov093_021B9634
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int BTL_MAIN_FindLastLivingPartyIndex(void *a)
{
    int i;
    void *e;

    for (i = POKEPARTY_GetCount(a) - 1; i >= 0; i--) {
        e = POKEPARTY_GetMember(a, i);
        if (POKE_TOOL_GetPartyValue(e, 0x4c, 0) == 0 && POKE_TOOL_GetPartyValue(e, 0xa0, 0) != 0)
            return i;
    }
    return -1;
}
