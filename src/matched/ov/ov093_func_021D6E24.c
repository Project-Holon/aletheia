/*
 * function: BTL_EVENT_StartClientPalAnm
 * address: 0x021D6E24
 * packet: pkt_ov093_021D6E24
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 * prototype: reads r0 after PALANM_GetPairedCodeForFirst, so returns the live wrapper result.
 */
typedef unsigned int u32;
extern unsigned short PALANM_GetPairedCodeForFirst(int a0);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
void BTL_EVENT_StartClientPalAnm(void **p, int value)
{
    u32 n;
    n = PALANM_GetPairedCodeForFirst(value);
    if (n == 0) n = 4;
    POKE_TOOL_SetPartyValue(*p, 0x98, n);
}
