/*
 * function: BSUBWAY_COMM_SetSendPlayerData
 * address:  0x02167B44
 * packet:   pkt_ov010_02167B44
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   BSUBWAY_SCR_GetParty  0x021CA210  thumb  ov021
 *   func_02008550  0x02008550  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BSUBWAY_SCR_GetWinCount  0x021CA234  thumb  ov021
 *   BSUBWAY_SCR_GetStageNo  0x021CA2CC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x1E];
    u8 b1e[2];
    u8 pad20[0x668 - 0x20];
    u16 h668;
    u16 h66a[2];
    u16 h66e;
} Obj;

struct Sub0200852CObj;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *BSUBWAY_SCR_GetParty(u8 *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u16 BSUBWAY_SCR_GetWinCount(u8 *p);
extern u16 BSUBWAY_SCR_GetStageNo(u16 v);

void BSUBWAY_COMM_SetSendPlayerData(Obj *o, void *a1)
{
    void *t;
    void *list;
    int i;

    t = GAME_DATA_GetMyStatus(a1);
    list = BSUBWAY_SCR_GetParty((u8 *)o);
    o->h668 = func_02008550(t);
    for (i = 0; i < 2; i++)
        o->h66a[i] = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(list, o->b1e[i]), 5, 0);
    o->h66e = BSUBWAY_SCR_GetStageNo(BSUBWAY_SCR_GetWinCount((u8 *)o));
}
