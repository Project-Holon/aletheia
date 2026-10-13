/*
 * function: FORMCHANGE_RevertShayminAndRegister
 * address:  0x0216A390
 * packet:   pkt_ov010_0216A390
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0200CA1C(void *a);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
struct Blk37;
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern void func_0200CFA0(struct Blk37 *p, void *m);

void FORMCHANGE_RevertShayminAndRegister(int a0, int a1)
{
    int found;
    int n;
    void *l4;
    int i;
    void *e;
    int v;
    int w;

    l4 = func_0200CA1C((void *)a0);
    found = 0;
    n = POKEPARTY_GetCount((void *)a1);
    for (i = 0; i < n; i++) {
        e = POKEPARTY_GetMember((void *)a1, i);
        v = POKE_TOOL_GetPartyValue(e, 5, 0);
        w = POKE_TOOL_GetPartyValue(e, 0x6f, 0);
        if (v == 0x1EC && w == 1) {
            POKE_TOOL_ChangeForm(e, 0);
            if (found == 0) {
                func_0200CFA0(l4, e);
                found = 1;
            }
        }
    }
}
