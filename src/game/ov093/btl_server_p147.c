/*
 * file:     btl_server_p147.c
 * unit:     yes
 * function: func_021D0C78, func_021D0CC4
 * address:  0x021D0C78
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
 *   func_021EEC20  0x021EEC20  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021EAF18  0x021EAF18  thumb  ov093
 *   func_021EABC4  0x021EABC4  thumb  ov093
 *   func_021EAC54  0x021EAC54  thumb  ov093
 */
#include "../../matched/include/Obj09995.h"
#include "../../matched/include/Obj05202.h"

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

extern int func_021EEC20(int, int *);
extern u8 func_021B8DE4(char *p, int i);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *win, int *out);
u8 func_021D0C78(BattleSeq *s, u8 *out);
int func_021D0CC4(BattleSeq *s, int *state);


u8 func_021D0C78(BattleSeq *s, u8 *out)
{
    int arr;
    u8 n;
    u32 i;
    u32 cnt;

    n = func_021EEC20(((struct Obj09995 *)s)->f50, &arr);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        if (s->unk1A6 == func_021B8DE4(s->battle, ((u8 *)arr)[i])) {
            out[cnt] = ((u8 *)arr)[i];
            cnt++;
        }
    }
    return cnt;
}


int func_021D0CC4(BattleSeq *s, int *state)
{
    int t;
    u8 *q;
    u8 f;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 3, 5);
        func_021EAF18((struct L *)((u8 *)s + 0x7c), 3, 1);
        func_021EABC4(s->msgWin, (u32)s->msg, (u32)((u8 *)s + 0x7c), 0);
        (*state)++;
        break;
    case 1:
        if (func_021EAC54(s->msgWin, &t)) {
            f = 0;
            if (t != 0)
                f = 1;
            q = (u8 *)s + 0x1ac;
            *q = f;
            *(u8 * *)&((struct Obj05202 *)s)->fD8 = q;
            ((struct Obj05202 *)s)->fDC = 1;
            return 1;
        }
        break;
    }
    return 0;
}
