/*
 * function: func_021D1960
 * address:  0x021D1960
 * packet:   pkt_ov093_021D1960
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9244  0x021B9244  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EA614  0x021EA614  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
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

extern int func_021B9244(void *battle);
extern void func_021EAF18(void *msg, int a, int id);
extern void func_021EAF50(void *msg, int v);
extern void func_021EA614(void *win, void *msg);
extern int func_021EA710(void *win);

int func_021D1960(BattleSeq *s, int *state)
{
    int a;

    switch (*state) {
    case 0:
        func_021EAF18(s->msg, 1, 0x36);
        func_021EAF50(s->msg, s->unk1A6);
        func_021EA614(s->msgWin, s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0) {
            a = func_021B9244(s->battle);
            if (a != 0) {
                func_021EAF18(s->msg, 1, 0x37);
                func_021EAF50(s->msg, s->unk1A6);
                func_021EAF50(s->msg, a);
                func_021EA614(s->msgWin, s->msg);
            }
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(s->msgWin) != 0) {
            func_021EAF18(s->msg, 1, 0x39);
            func_021EAF50(s->msg, s->unk1A6);
            func_021EA614(s->msgWin, s->msg);
            (*state)++;
        }
        break;
    case 3:
        if (func_021EA710(s->msgWin) != 0)
            (*state)++;
        break;
    default:
        return 1;
    }
    return 0;
}
