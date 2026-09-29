/*
 * function: func_021D1CAC
 * address:  0x021D1CAC
 * packet:   pkt_ov093_021D1CAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021EA458  0x021EA458  thumb  ov093
 *   func_021EA478  0x021EA478  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern u8 func_021B8E70(void *p, u8 k);
extern int func_021EA458(void *win, u32 v, u32 i);
extern int func_021EA478(void *win);

int func_021D1CAC(BattleSeq *s, int *state, int *pp)
{
    switch (*state) {
    case 0:
        func_021EA458(s->msgWin, func_021B8E70(s->battle, pp[0]), (u16)pp[1]);
        (*state)++;
        break;
    case 1:
        if (func_021EA478(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}
