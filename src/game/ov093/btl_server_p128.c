/*
 * file:     btl_server_p128.c
 * unit:     yes
 * function: func_021D123C, func_021D127C, func_021D1290, func_021D13A4, func_021D13FC
 * address:  0x021D123C
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
 *   func_021EE608  0x021EE608  thumb  ov093
 *   func_021BB4E0  0x021BB4E0  thumb  ov093
 *   func_021EE638  0x021EE638  thumb  ov093
 *   func_021B904C 0x021B904C thumb ov093
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021B86DC 0x021B86DC thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_02005D90 0x02005D90 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_021B902C  0x021B902C  thumb  ov093
 *   func_021D1410 0x021D1410 thumb ov093
 */
#include "../../matched/include/Obj05203.h"
#include "../../matched/include/Obj00066.h"

struct H;
struct L;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags;

typedef struct {
    void *battle;         /* 0x00 */
    u8 unk04[0x50];
    void *msgWin;         /* 0x54 */
    u8 msg[0x14E];        /* 0x58 */
    u8 unk1A6;            /* 0x1A6 */
} BattleSeq;

extern int func_021EEC20(int, int *);
extern void func_021EE608(u8 *p, const u8 *src, int n);
extern void func_021BB4E0(int, int, int);
extern u8 func_021EE638(u8 *p);
extern u8 func_021B904C(u8 *p, int k);
extern int func_021B86C8(unsigned char **p);
extern void func_021B916C(u8 *p, u32 x);
extern u16 func_021B86DC(void **p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void func_02005D90(u16, u16);
extern void func_02005E30(u32);
extern int func_02005E50(void);
extern void func_02005D28(void);
extern int func_021B902C(int a, int b);
extern int func_021D1410(u8 *, int *, void *);
int func_021D123C(int a);
int func_021D127C(u8 *p, int *state);
int func_021D1290(u8 *p, int *state, void *a2);
int func_021D13A4(BattleSeq *s);
int func_021D13FC(u8 *p, int *state);





int func_021D123C(int a)
{
    int tmp;
    int r4 = func_021EEC20(((struct Obj05203 *)a)->f50, &tmp);
    if (((struct Obj05203 *)a)->f10 != 0)
        func_021EE608((u8 *)(((struct Obj05203 *)a)->f10), (const u8 *)tmp, r4);
    if (((struct Obj05203 *)a)->fA0 != 0) {
        func_021BB4E0(((struct Obj05203 *)a)->fA0, tmp, r4);
        ((struct Obj05203 *)a)->f1AE = func_021EE638((u8 *)tmp);
    }
    return 1;
}




/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D127C(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1290(p, state, q);
    return 1;
}



/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, not a shifted integer mask.
 */
int func_021D1290(u8 *p, int *state, void *a2)
{
    int idx;
    int mode;
    u8 flag;
    u16 msg;
    switch (*state) {
    case 0:
        if (((Flags *)p)->flag != 0)
            return 1;
        idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
        mode = func_021D13A4((BattleSeq *)p);
        flag = func_021B86C8((unsigned char **)(*(u8 * *)&((struct Obj00066 *)p)->f0));
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        switch (mode) {
        case 1: msg = flag != 0 ? 0x31 : 0x30; break;
        case 0: msg = flag != 0 ? 0x33 : 0x32; break;
        case 2: msg = flag != 0 ? 0x35 : 0x34; break;
        default: return 1;
        }
        func_021EAF18((struct L *)(p + 0x58), 1, msg);
        func_021EAF50((struct L *)(p + 0x58), idx);
        if (flag != 0)
            func_021EAF50((struct L *)(p + 0x58), func_021B904C(((struct Obj00066 *)p)->f0, 1));
        func_021EA614(((struct Obj00066 *)p)->f54, (struct H *)(p + 0x58));
        if (mode == 1) {
            func_02005D90(func_021B86DC(((struct Obj00066 *)p)->f0), 0xFFFF);
            (*state)++;
        } else {
            func_02005E30(0x1E);
            *state += 2;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            return 1;
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0)
            (*state)++;
        break;
    case 3:
        if (func_02005E50() == 0) {
            func_02005D28();
            return 1;
        }
        break;
    }
    return 0;
}



int func_021D13A4(BattleSeq *s)
{
    u16 *q;

    func_021EEC20(((struct Obj00066 *)s)->f50, (int *)&q);
    switch (q[1]) {
    case 0:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 1;
        break;
    case 1:
        if (func_021B902C((u8)q[0], (u8)s->unk1A6) == 0)
            return 0;
        break;
    }
    return q[1];
}

int func_021D13FC(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D1410(p, state, q);
    return 1;
}
