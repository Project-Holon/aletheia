/*
 * function: EVENT_BATTLE_RETURN_RegisterShayminForms
 * address:  0x021B9CA4
 * packet:   pkt_ov092_021B9CA4
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u32 f00;
    u8 *f04;
};

extern u32 POKEPARTY_GetCount(void *party);
struct Blk37;
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 buf);
extern void *func_0200CA1C(void *a);
extern void func_0200CFA0(struct Blk37 *p, void *m);

void EVENT_BATTLE_RETURN_RegisterShayminForms(struct S *s, void *party)
{
    int i;
    void *mon;
    u32 t;

    t = *(u32 *)s->f04;
    switch (t) {
    case 0:
    case 1:
        for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                mon = POKEPARTY_GetMember(party, i);
                if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x1ec) {
                    func_0200CFA0(func_0200CA1C((void *)s->f00), mon);
                }
            }
        }
        break;
    }
}
