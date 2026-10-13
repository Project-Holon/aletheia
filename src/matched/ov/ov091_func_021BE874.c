/*
 * function: PLIST_DEMO_RaiseMovePpUps
 * address:  0x021BE874
 * packet:   pkt_ov091_021BE874
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 WAZA_TOOL_GetMaxPP(u32 a, u32 b);

int PLIST_DEMO_RaiseMovePpUps(void *a, int b, int c)
{
    int r = 0;
    u32 x;
    u32 y;
    u32 v;
    u32 n;
    int t;
    n = (u8)POKE_TOOL_GetPartyValue(a, b + 0x3E, 0);
    if (n == 3)
        return r;
    x = (u16)POKE_TOOL_GetPartyValue(a, b + 0x36, r);
    if (WAZA_TOOL_GetMaxPP(x, r) < 5)
        return r;
    v = (u8)POKE_TOOL_GetPartyValue(a, b + 0x3A, r);
    y = WAZA_TOOL_GetMaxPP(x, n);
    t = n + c;
    if ((u32)t > 3)
        n = 3;
    else
        n = (u8)t;
    v = (u8)(v + WAZA_TOOL_GetMaxPP(x, n) - y);
    POKE_TOOL_SetPartyValue(a, b + 0x3E, n);
    POKE_TOOL_SetPartyValue(a, b + 0x3A, v);
    return 1;
}
