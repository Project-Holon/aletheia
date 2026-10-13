/*
 * function: func_021CF8E4
 * address:  0x021CF8E4
 * packet:   pkt_ov021_021CF8E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Counts the party members whose value func_021CFA04 accepts.
 *
 * symbols:
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   func_021CFA04  0x021CFA04  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32   POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern int func_021CFA04(int a, int v, void *l);

int func_021CF8E4(void *a, void *src, int c)
{
    void *party = GAME_DATA_GetMyParty(src);
    int cnt = POKEPARTY_GetCount(party);
    int n = 0;
    int i;

    for (i = 0; i < cnt; i++) {
        void *p = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(p, 0x4c, 0) == 0) {
            u32 v = POKE_TOOL_GetPartyValue(p, 7, 0);
            if (func_021CFA04((int)a, v, (void *)c) != 0) {
                n++;
            }
        }
    }
    return n;
}
