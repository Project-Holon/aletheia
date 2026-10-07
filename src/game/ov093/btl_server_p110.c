/*
 * file:     btl_server_p110.c
 * unit:     yes
 * function: func_021CA7C4, func_021CA7D4
 * address:  0x021CA7C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef struct {
    u8 unk0[0x4A8];
    u8 *state;          /* 0x4A8 */
} BattleCtx_021CA7C4;

typedef struct {
    u8 unk0[5];
    u8 flag : 1;
    u8 unk5 : 7;
} BattleState;

typedef struct {
    u8 unk0[0x4A8];
    BattleState *state; /* 0x4A8 */
} BattleCtx_021CA7D4;

/* command handler: copy the argument byte of the command into the state block */ u8 func_021CA7C4(BattleCtx_021CA7C4 *s, u8 *cmd);
/* command handler: latch the state flag once */ u8 func_021CA7D4(BattleCtx_021CA7D4 *s, void *cmd);


/* command handler: copy the argument byte of the command into the state block */
u8 func_021CA7C4(BattleCtx_021CA7C4 *s, u8 *cmd)
{
    s->state[4] = cmd[4];
    return 1;
}


/* command handler: latch the state flag once */
u8 func_021CA7D4(BattleCtx_021CA7D4 *s, void *cmd)
{
    BattleState *st = s->state;

    if (!st->flag)
        st->flag = 1;
    return 1;
}
