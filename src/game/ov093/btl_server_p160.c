/*
 * file:     btl_server_p160.c
 * unit:     yes
 * function: func_021D2C7C, func_021D2CA8
 * address:  0x021D2C7C
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
 *   func_020061E4 0x020061E4 thumb
 *   func_02006254 0x02006254 thumb
 *   func_02005D90   0x02005D90  thumb
 *   func_02005DE4   0x02005DE4  thumb
 *   func_02005E64   0x02005E64  thumb
 *   func_02005E9C   0x02005E9C  thumb
 *   func_02005F38   0x02005F38  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   func_020181F4   0x020181F4  thumb
 *   func_02018328   0x02018328  thumb
 *   func_021B9934   0x021B9934  thumb ov093
 *   func_021B9AF8   0x021B9AF8  thumb ov093
 *   func_021B9CBC   0x021B9CBC  thumb ov093
 *   func_021D5440   0x021D5440  thumb ov093
 *   func_021D5844   0x021D5844  thumb ov093
 *   func_021D6BFC   0x021D6BFC  thumb ov093
 *   func_021EA614   0x021EA614  thumb ov093
 *   func_021EA638   0x021EA638  thumb ov093
 *   func_021EA710   0x021EA710  thumb ov093
 *   func_021EA720   0x021EA720  thumb ov093
 *   func_021EABC4   0x021EABC4  thumb ov093
 *   func_021EAC54   0x021EAC54  thumb ov093
 *   func_021EAC64   0x021EAC64  thumb ov093
 *   func_021EAC80   0x021EAC80  thumb ov093
 *   func_021EAF18   0x021EAF18  thumb ov093
 *   func_021EAF50   0x021EAF50  thumb ov093
 *   func_021EAF78   0x021EAF78  thumb ov093
 *   g_021F3B64      0x021F3B64  data
 */
#include "../../matched/include/G_StateData.h"

struct H;
struct L;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u8 data[0x24];
} MsgParam;

typedef struct {
    void *battle;       /* 0x000 */
    void *party;        /* 0x004 */
    u8 unk008[0x4C];
    void *msgWin;       /* 0x054 */
    MsgParam msg;       /* 0x058 */
    u8 unk07C[0x11E];
    u16 level;          /* 0x19A */
    u8 unk19C[0xA];
    u8 side;            /* 0x1A6 */
} LearnSeq;

extern void func_020061E4(unsigned int);
extern int func_02006254(unsigned int);
extern u8 func_021D5440(u8 *p);
extern void *func_021D5844(void *mon);
extern u16 func_02018328(void *p, u32 *idx, u32 heap);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D6BFC(u8 *p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *p, u8 v);
extern void func_021EA614(char *p, struct H *h);
extern void func_021EA638(char *p, struct H *h, int c);
extern int func_021EA720(u32 *p);
extern int func_021EA710(u32 *p);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int a, int b);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *win, int *sel);
extern char *func_021B9AF8(char *p, int i);
extern int func_021B9CBC(u8 *p, int v);
extern void func_021EAC64(u8 *p, u8 a, int c);
extern int func_021EAC80(u8 *p, u8 *out);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_020181F4(void *p, u16 move, u32 slot);
int func_021D2C7C(int n);
int func_021D2CA8(LearnSeq *s, int *state, void *mon);
extern struct StateData g_021F3B64;

int func_021D2C7C(int n)
{
    switch (n) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        if (func_02006254(0x56b) != 0) return 1;
        break;
    }
    return 0;
}


int func_021D2CA8(LearnSeq *s, int *state, void *mon)
{
    int idx = func_021D5440(mon);

    switch (*state) {
    case 0:
        g_021F3B64.iter = 0;
        g_021F3B64.move = 0;
        *state = 1;
    case 1:
        g_021F3B64.move = func_02018328(func_021D5844(mon), &g_021F3B64.iter, s->level);
        if (g_021F3B64.move == 0)
            return 1;
        if (g_021F3B64.move == 0xFFFE)
            break;
        if (g_021F3B64.move & 0x8000) {
            g_021F3B64.move &= 0x7FFF;
            *state = 5;
        } else {
            *state = 2;
        }
        break;
    case 2: {
        void *p = func_021B9934(s->party, idx);
        func_021D5844(p);
        func_021D6BFC(p);
        func_021EAF18((struct L *)(&s->msg), 5, 3);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 3;
    }
    case 3:
        if (func_021EA720(s->msgWin)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xFFFF);
        }
        if (func_021EA710(s->msgWin))
            *state = 4;
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02005E9C();
            func_02005DE4(0);
            *state = 1;
        }
        break;
    case 5:
        func_021EAF18((struct L *)(&s->msg), 5, 4);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 6;
    case 6:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 2);
            func_021EAF18((struct L *)(&no), 6, 3);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 7;
        break;
    case 7: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAC64(s->msgWin, func_021B9CBC((u8 *)func_021B9AF8(s->party, s->side), idx), g_021F3B64.move);
                *state = 8;
            } else {
                *state = 10;
            }
        }
        break;
    }
    case 8: {
        u8 slot;
        void *pp;
        u16 old;
        if (func_021EAC80(s->msgWin, &slot) == 0)
            break;
        if (slot == 4) {
            *state = 5;
            break;
        }
        pp = func_021D5844(func_021B9934(s->party, idx));
        old = func_02017E1C(pp, slot + 54, 0);
        func_020181F4(pp, g_021F3B64.move, slot);
        func_021EAF18((struct L *)(&s->msg), 5, 5);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), old);
        func_021EA638(s->msgWin, (struct H *)(&s->msg), (int)((void (*)(void))func_021D2C7C));
        *state = 9;
        break;
    }
    case 9:
        if (func_021EA710(s->msgWin))
            *state = 2;
        break;
    case 10:
        func_021EAF18((struct L *)(&s->msg), 5, 7);
        func_021EAF50((struct L *)(&s->msg), idx);
        func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
        func_021EAF78((u8 *)(&s->msg), 255);
        func_021EA614(s->msgWin, (struct H *)(&s->msg));
        *state = 11;
        break;
    case 11:
        if (func_021EA720(s->msgWin)) {
            MsgParam yes, no;
            func_021EAF18((struct L *)(&yes), 6, 4);
            func_021EAF50((struct L *)(&yes), g_021F3B64.move);
            func_021EAF18((struct L *)(&no), 6, 5);
            func_021EAF50((struct L *)(&no), g_021F3B64.move);
            func_021EABC4(s->msgWin, (u32)(&yes), (u32)(&no), 1);
        }
        if (func_021EA710(s->msgWin))
            *state = 12;
        break;
    case 12: {
        int sel;
        if (func_021EAC54(s->msgWin, &sel)) {
            if (sel == 0) {
                func_021EAF18((struct L *)(&s->msg), 5, 8);
                func_021EAF50((struct L *)(&s->msg), idx);
                func_021EAF50((struct L *)(&s->msg), g_021F3B64.move);
                func_021EA614(s->msgWin, (struct H *)(&s->msg));
                *state = 13;
            } else {
                *state = 5;
            }
        }
        break;
    }
    case 13:
        if (func_021EA710(s->msgWin))
            *state = 1;
        break;
    }
    return 0;
}
