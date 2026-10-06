/*
 * function: func_021D18EC
 * address:  0x021D18EC
 * packet:   pkt_ov093_021D18EC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021B9210  0x021B9210  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
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

extern int func_021BA1A8(char **p, int m);
extern u32 func_021B9210(u8 *p);
extern u8 func_021B8FF4(u8 *p);
struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
struct H;
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);

int func_021D18EC(BattleSeq *s, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021BA1A8(s->battle, 0x200) == 0) {
            a = func_021B9210(s->battle);
            if (a != 0) {
                b = func_021B8FF4(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 0x3b);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
        }
        (*state)++;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}
