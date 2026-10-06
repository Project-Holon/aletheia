/*
 * function: func_021D1410
 * address:  0x021D1410
 * packet:   pkt_021D1410
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D1410   0x021D1410  thumb
 *   func_021B86DC   0x021B86DC  thumb ov093
 *   func_021B8FF4   0x021B8FF4  thumb ov093
 *   func_021B904C   0x021B904C  thumb ov093
 *   func_021B919C   0x021B919C  thumb ov093
 *   func_021B9210   0x021B9210  thumb ov093
 *   func_021B9244   0x021B9244  thumb ov093
 *   func_021BA004   0x021BA004  thumb ov093
 *   func_021BA020   0x021BA020  thumb ov093
 *   func_021BA1A8   0x021BA1A8  thumb ov093
 *   func_021D13A4   0x021D13A4  thumb ov093
 *   func_021EA614   0x021EA614  thumb ov093
 *   func_021EA6B0   0x021EA6B0  thumb ov093
 *   func_021EA710   0x021EA710  thumb ov093
 *   func_021EAF18   0x021EAF18  thumb ov093
 *   func_021EAF50   0x021EAF50  thumb ov093
 *   func_021F7998   0x021F7998  thumb ov094
 *   func_021F7EB4   0x021F7EB4  thumb ov094
 *   func_021F7F58   0x021F7F58  thumb ov094
 *   func_021F878C   0x021F878C  thumb ov094
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

extern int func_021D13A4(BattleSeq *s);
extern u16 func_021B86DC(void **p);
extern void func_021F878C(u32 a);
extern u8 func_021B904C(u8 *p, int k);
extern int func_021BA1A8(char **p, int m);
extern u8 func_021B8FF4(u8 *p);
extern unsigned short func_021BA020(char *p, int i);
extern u16 func_021BA004(char *p, int i);
extern u32 func_021B919C(u8 *p);
extern u32 func_021B9210(u8 *p);
extern u32 func_021B9244(char *p);
struct L;
extern void func_021EAF18(struct L *p, int kind, int id);
struct H;
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern int func_021EA6B0(char *p, u16 a, u16 b);
extern int func_021F7EB4(void);
extern void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F7998(u32 a);

int func_021D1410(BattleSeq *s, int *state)
{
    int a;
    int b;

    switch (*state) {
    case 0:
        if (func_021D13A4(s) == 1) {
            func_021F878C(func_021B86DC(s->battle));
            a = func_021B904C(s->battle, 0);
            b = func_021B904C(s->battle, 1);
            if (a == b) {
                func_021EAF18((struct L *)s->msg, 1, 44);
                func_021EAF50((struct L *)s->msg, a);
            } else {
                func_021EAF18((struct L *)s->msg, 1, 45);
                func_021EAF50((struct L *)s->msg, a);
                func_021EAF50((struct L *)s->msg, b);
            }
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 1;
        } else if (func_021BA1A8(s->battle, 0x100) == 0) {
            a = func_021B8FF4(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 54);
            func_021EAF50((struct L *)s->msg, a);
            func_021EAF50((struct L *)s->msg, a);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 9;
        } else {
            return 1;
        }
        break;
    case 1:
        if (func_021EA710(s->msgWin)) {
            a = func_021B904C(s->battle, 0);
            func_021F7F58(func_021BA020(s->battle, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 2;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 0);
            func_021EA6B0(s->msgWin, func_021BA004(s->battle, a), 1);
            *state = 3;
        }
        break;
    case 3:
        if (func_021EA710(s->msgWin)) {
            a = func_021B904C(s->battle, 0);
            if (a != func_021B904C(s->battle, 1)) {
                func_021F7998(0x271);
                *state = 4;
            } else {
                *state = 7;
            }
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 1);
            func_021F7F58(func_021BA020(s->battle, a), 9, 0, 0, 0);
            func_021F7998(0x270);
            *state = 5;
        }
        break;
    case 5:
        if (func_021F7EB4() == 0) {
            a = func_021B904C(s->battle, 1);
            func_021EA6B0(s->msgWin, func_021BA004(s->battle, a), 1);
            *state = 6;
        }
        break;
    case 6:
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7:
        a = func_021B919C(s->battle);
        if (a) {
            b = func_021B8FF4(s->battle);
            func_021EAF18((struct L *)s->msg, 1, 58);
            func_021EAF50((struct L *)s->msg, b);
            func_021EAF50((struct L *)s->msg, a);
            func_021EA614(s->msgWin, (struct H *)s->msg);
        }
        if (func_021B9210(s->battle) == 0)
            *state = 11;
        else
            *state = 8;
        break;
    case 8:
        if (func_021EA710(s->msgWin)) {
            a = func_021B9210(s->battle);
            if (a) {
                b = func_021B8FF4(s->battle);
                func_021EAF18((struct L *)s->msg, 1, 59);
                func_021EAF50((struct L *)s->msg, b);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            *state = 11;
        }
        break;
    case 9:
        if (func_021EA710(s->msgWin)) {
            a = func_021B9244(s->battle);
            if (a) {
                func_021EAF18((struct L *)s->msg, 1, 56);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            *state = 10;
        }
        break;
    case 10:
        if (func_021EA710(s->msgWin)) {
            func_021EAF18((struct L *)s->msg, 1, 57);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            func_021EA614(s->msgWin, (struct H *)s->msg);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EA710(s->msgWin))
            return 1;
        break;
    default:
        return 1;
    }
    return 0;
}
