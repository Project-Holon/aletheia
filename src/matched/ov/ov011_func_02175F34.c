/*
 * function: INTRUDE_COMM_SetMemberEntry
 * address:  0x02175F34
 * packet:   pkt_ov011_02175F34
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note:     the unlabelled 2-instruction leaf at 0x02175FB4 (ldrb r0,[r0,#0x10]; bx lr) follows.
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetBattleRecSlotByNetId  0x021583CC  thumb  ov010
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   func_0200855C  0x0200855C  thumb
 *   func_02008530  0x02008530  thumb
 *   INTRUDE_COMM_NormalizeVersion  0x021584F4  thumb  ov010
 *   INTRUDE_COMM_FillMemberName  0x02175EFC  thumb  ov011
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 h[8];
    u8  f10;
    u8  f11;
    u8  f12;
    u8  pad13;
    u8  f14[0x14];
} Ent;

typedef struct {
    u16 h[8];
} Half8;

extern u32 GAME_COMM_GetGameData(void *obj);
extern int GAME_DATA_GetBattleRecSlotByNetId(void *a0, int a1);
struct Sub0200852CObj;
extern int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern int    INTRUDE_COMM_NormalizeVersion(int a, int b);
extern void   INTRUDE_COMM_FillMemberName(void *w, void *p, u8 i);

void INTRUDE_COMM_SetMemberEntry(void *w, Ent *tbl, u32 arg, int idx)
{
    int sv;
    Ent *e;
    Half8 *src;
    int t;
    int u;
    u8 flag;

    sv = GAME_COMM_GetGameData(((void **)w)[1]);
    e = (Ent *)((u8 *)tbl + idx * 0x28);
    if (e->f10 != 1) {
        src = (Half8 *)GAME_DATA_GetBattleRecSlotByNetId((void *)sv, idx);
        t = GAME_DATA_GetMyStatusByNetId((void *)sv, idx);
        u = func_0200855C((const struct Sub0200852CObj *)t);
        flag = INTRUDE_COMM_NormalizeVersion(u, func_02008530((const struct Sub0200852CObj *)t)) == 0x15;
        *(Half8 *)e = *src;
        e->f11 = flag;
        e->f12 = arg;
        INTRUDE_COMM_FillMemberName(w, e->f14, idx);
        e->f10 = 1;
    }
}
