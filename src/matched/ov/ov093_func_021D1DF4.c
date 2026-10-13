/*
 * function: BTL_CLIENT_PickSendOutMessageId
 * address:  0x021D1DF4
 * packet:   pkt_ov093_021D1DF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_MAIN_GetOpponentClient  0x021B9064  thumb  ov093
 *   BTL_SIDE_GetClientPoke  0x021B9920  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetHpRatioFixed  0x021D5C44  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    void *unk04;          /* 0x04 */
    u8 unk08[0x4C];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern u32 BTL_MAIN_GetRule(void **p);
extern u32 BTL_MAIN_GetOpponentClient(u8 *p, int k, int x);
extern u8 *BTL_SIDE_GetClientPoke(void *p, u32 i, u8 j);
extern int BTL_POKEPARAM_IsFainted(void *p);
struct Rat;
extern int BTL_POKEPARAM_GetHpRatioFixed(struct Rat *p);

int BTL_CLIENT_PickSendOutMessageId(BattleSeq *s)
{
    u8 *m;
    u8 t;
    int v;

    if (BTL_MAIN_GetRule(s->battle) == 0) {
        t = BTL_MAIN_GetOpponentClient(s->battle, s->unk1A6, 0);
        m = BTL_SIDE_GetClientPoke(s->unk04, t, 0);
        if (BTL_POKEPARAM_IsFainted(m) != 0)
            return 0xb;
        v = BTL_POKEPARAM_GetHpRatioFixed((struct Rat *)m);
        if (v >= 0x4d800)
            return 0xb;
        if (v >= 0x37000)
            return 0x15;
        if (v >= 0x20800)
            return 0x16;
        if (v >= 0xa000)
            return 0x17;
        return 0x18;
    }
    return 0xb;
}
