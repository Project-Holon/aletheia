/*
 * function: SODATEYA_GrantExp
 * address:  0x021C3530
 * packet:   pkt_ov021_021C3530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Learnset walk as in SODATEYA_AddLevelUpMoves. Load-bearing: lv is read from the
 * first entry copy right after it is made (the value stays in the
 * register), mv from the second copy, and mv is u32/int (u16 sinks its
 * load to the call).
 * symbols:
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_GetExpForLevel  0x02018584  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_PERSONAL_LoadDataDirect  0x0201ADD0  thumb
 *   SODATEYA_AddExpSaturated  0x021C3510  thumb  ov021
 *   SODATEYA_LearnMove  0x021C360C  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u16 x, y; } P;

extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_GetExpForLevel(u16 a, u16 b, u16 c);
extern void POKE_TOOL_RecalcParam(void *mon);
extern void POKE_PERSONAL_LoadDataDirect(unsigned int a, int b, void *buf);
extern u32 SODATEYA_AddExpSaturated(u32, u32);
extern void SODATEYA_LearnMove(void *a, u32 b);

void SODATEYA_GrantExp(void *mon, u32 b)
{
    P buf[26];
    P e, d, c, a;
    u32 species;
    u32 form;
    u32 max;
    int oldlv;
    int newlv;
    u32 exp;
    int i;
    int end;
    int lv;
    u32 mv;

    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    form = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
    max = POKE_TOOL_GetExpForLevel(species, form, 100);
    oldlv = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
    exp = SODATEYA_AddExpSaturated(POKE_TOOL_GetPartyValue(mon, 8, 0), b);
    if (max < exp)
        exp = max;
    POKE_TOOL_SetPartyValue(mon, 8, exp);
    POKE_TOOL_RecalcParam(mon);
    i = 0;
    newlv = POKE_TOOL_GetPartyValue(mon, 0x9e, 0);
    POKE_PERSONAL_LoadDataDirect((u16)species, (u16)form, buf);
    goto test;
body:
    e = a;
    lv = e.y;
    d = a;
    mv = d.x;
    if (newlv < lv)
        return;
    if (oldlv < lv)
        SODATEYA_LearnMove(mon, mv);
    i++;
test:
    a = buf[i];
    c = a;
    end = 0;
    if (c.x == 0xffff && c.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}
