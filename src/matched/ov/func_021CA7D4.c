/*
 * function: BTL_SERVER_FLOW_ProcHandExLatchTurnStateFlag
 * address:  0x021CA7D4
 * packet:   pkt_021CA7D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_ProcHandExLatchTurnStateFlag   0x021CA7D4  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 unk0[5];
    u8 flag : 1;
    u8 unk5 : 7;
} BattleState;

typedef struct {
    u8 unk0[0x4A8];
    BattleState *state; /* 0x4A8 */
} BattleCtx;

/* command handler: latch the state flag once */
u8 BTL_SERVER_FLOW_ProcHandExLatchTurnStateFlag(BattleCtx *s, void *cmd)
{
    BattleState *st = s->state;

    if (!st->flag)
        st->flag = 1;
    return 1;
}
