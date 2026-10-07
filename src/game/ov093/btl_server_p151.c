/*
 * file:     btl_server_p151.c
 * unit:     yes
 * function: func_021D185C, func_021D18EC, func_021D1960, func_021D1A18
 * address:  0x021D185C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B904C  0x021B904C  thumb  ov093
 *   func_021BA02C  0x021BA02C  thumb  ov093
 *   func_02024450  0x02024450  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   sub_02045808   0x02045808  arm
 *   func_021BA004  0x021BA004  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EAF50  0x021EAF50  thumb  ov093
 *   func_021EA5F0  0x021EA5F0  thumb  ov093
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021B9210  0x021B9210  thumb  ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021EA614  0x021EA614  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   func_021B9244  0x021B9244  thumb  ov093
 */
struct U16Vec;
struct H;
struct L;
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

extern u8 func_021B904C(u8 *p, int k);
extern void *func_021BA02C(char *p, int i, int mode);
extern int func_02024450(const u16 *p);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void sub_02045808(struct U16Vec *vec);
extern u16 func_021BA004(char *p, int i);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA5F0(char *p, struct H *h);
extern int func_021BA1A8(char **p, int m);
extern u32 func_021B9210(u8 *p);
extern u8 func_021B8FF4(u8 *p);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern u32 func_021B9244(char *p);
void func_021D185C(BattleSeq *s, int a, int b);
int func_021D18EC(BattleSeq *s, int *state);
int func_021D1960(BattleSeq *s, int *state);
int func_021D1A18(BattleSeq *s, int *state);


/*
 * Verified C for it (match.py one --thumb, no --region, EXACT, 20 bytes):
 *   int func_02024450(u16 *p) { return *p != 0xffff; }
 */
void func_021D185C(BattleSeq *s, int a, int b)
{
    int idx;
    void *p;
    void *r;
    int v;

    idx = func_021B904C(s->battle, b);
    p = func_021BA02C(s->battle, idx, a);
    if (p != 0 && func_02024450(p) != 0) {
        r = func_0202435C(p, (u16)((*(u16 *)((u8 *)s + 0x19a) & 0x7fff) | 0x8000));
        func_021EA5E4(s->msgWin, r);
        sub_02045808(r);
        return;
    }
    v = func_021BA004(s->battle, idx);
    if (v != 0) {
        func_021EAF18((struct L *)s->msg, 7, (int)0);
        func_021EAF50((struct L *)s->msg, (int)v);
        func_021EAF50((struct L *)s->msg, (int)a);
        func_021EA5F0(s->msgWin, (struct H *)s->msg);
    }
}


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


int func_021D1960(BattleSeq *s, int *state)
{
    int a;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0x36);
        func_021EAF50((struct L *)s->msg, s->unk1A6);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0) {
            a = func_021B9244(s->battle);
            if (a != 0) {
                func_021EAF18((struct L *)s->msg, 1, 0x37);
                func_021EAF50((struct L *)s->msg, s->unk1A6);
                func_021EAF50((struct L *)s->msg, a);
                func_021EA614(s->msgWin, (struct H *)s->msg);
            }
            (*state)++;
        }
        break;
    case 2:
        if (func_021EA710(s->msgWin) != 0) {
            func_021EAF18((struct L *)s->msg, 1, 0x39);
            func_021EAF50((struct L *)s->msg, s->unk1A6);
            func_021EA614(s->msgWin, (struct H *)s->msg);
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


int func_021D1A18(BattleSeq *s, int *state)
{
    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, 0xb7);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            (*state)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}
