/*
 * function: EVENT_BATTLE_RETURN_FlagLeveledUpMembers
 * address:  0x021B9A14
 * packet:   pkt_ov092_021B9A14
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct In {
    u32 f00;
    u8 pad04[0x20];
    void *f24;
    u8 pad28[0x64];
    u32 f8c;
};

struct S {
    void *f00;
    struct In *f04;
};

struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 buf);

void EVENT_BATTLE_RETURN_FlagLeveledUpMembers(u8 *a0, struct S *s)
{
    struct In *in = s->f04;
    void *p1;
    int n;
    int i;
    u16 *dst;

    if (in->f8c == 1 || in->f8c == 3 || in->f8c == 5) {
        switch (in->f00) {
        case 0:
        case 1:
            p1 = GAME_DATA_GetMyParty(s->f00);
            n = func_0201AA18(p1);
            i = 0;
            if (n > 0) {
                dst = (u16 *)(a0 + 0x3a);
                do {
                    void *m1 = func_0201AB28(p1, i);
                    void *m2 = func_0201AB28(s->f04->f24, i);
                    u32 v1 = POKE_TOOL_GetPartyValue(m1, 0x9e, 0);
                    u32 v2 = POKE_TOOL_GetPartyValue(m2, 0x9e, 0);
                    if (v1 < v2) {
                        *dst |= (u16)(1 << i);
                    }
                    i++;
                } while (i < n);
            }
            break;
        }
    }
}
