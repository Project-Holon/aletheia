/*
 * function: PLIST_DEMO_RestoreHp
 * address: 0x021BE914
 * packet: pkt_ov091_021BE914
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 */
typedef unsigned int u32;
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
void PLIST_DEMO_RestoreHp(void *p, u32 v, u32 limit, u32 step)
{
    if (limit == 1) step = 1;
    else if (step == 0xff) step = limit;
    else if (step == 0xfe) step = limit >> 1;
    else if (step == 0xfd) step = limit >> 2;
    v += step;
    if (v > limit) v = limit;
    POKE_TOOL_SetPartyValue(p, 0xa0, v);
}
