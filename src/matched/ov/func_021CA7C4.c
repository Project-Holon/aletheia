/*
 * function: func_021CA7C4
 * address:  0x021CA7C4
 * packet:   pkt_021CA7C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA7C4   0x021CA7C4  thumb
 */

typedef unsigned char u8;

typedef struct {
    u8 unk0[0x4A8];
    u8 *state;          /* 0x4A8 */
} BattleCtx;

/* command handler: copy the argument byte of the command into the state block */
u8 func_021CA7C4(BattleCtx *s, u8 *cmd)
{
    s->state[4] = cmd[4];
    return 1;
}
