/*
 * function: FORMCHANGE_RevertShaymin
 * address:  0x0216A298
 * packet:   pkt_ov010_0216A298
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 */

typedef unsigned int u32;

extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);

void FORMCHANGE_RevertShaymin(void *a, void *list)
{
    int i;
    int n;
    void *e;
    int x;
    int y;

    n = func_0201AA18(list);
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        x = POKE_TOOL_GetPartyValue(e, 5, 0);
        y = POKE_TOOL_GetPartyValue(e, 0x6f, 0);
        if (x == 0x1ec && y == 1)
            POKE_TOOL_ChangeForm(e, 0);
    }
}
