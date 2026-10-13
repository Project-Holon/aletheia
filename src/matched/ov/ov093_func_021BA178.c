/*
 * function: BTL_MAIN_GetClientParty
 * address: 0x021BA178
 * packet: pkt_ov093_021BA178
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 */
extern unsigned int POKEPARTY_GetCount(void *);
typedef unsigned int u32;
extern void *POKEPARTY_GetMember(void *p, u32 idx);
void *BTL_MAIN_GetClientParty(void *p, int i, int mode)
{
    if (mode) {
        if (POKEPARTY_GetCount(*(void **)(((u32)p + 0x2a8) + (u32)i * 4)))
            POKEPARTY_GetMember(*(void **)(((u32)p + 0x2a8) + (u32)i * 4), 0);
        return *(void **)(((u32)p + 0x2a8) + (u32)i * 4);
    }
    return *(void **)((u32)p + (u32)i * 4 + 0x298);
}
