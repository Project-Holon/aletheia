/*
 * file:     btl_server_p129.c
 * unit:     yes
 * function: func_021D1410, func_021D1708, func_021D171C, func_021D185C, func_021D18EC, func_021D1960, func_021D1A18, func_021D1A60, func_021D1A74, func_021D1BD0
 * address:  0x021D1410
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
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021EA600 0x021EA600 thumb ov093
 *   func_021BA02C  0x021BA02C  thumb  ov093
 *   func_02024450  0x02024450  thumb
 *   func_0202435C  0x0202435C  thumb
 *   func_021EA5E4  0x021EA5E4  thumb  ov093
 *   sub_02045808   0x02045808  arm
 *   func_021EA5F0  0x021EA5F0  thumb  ov093
 *   func_021EEC20 0x021EEC20 thumb ov093
 *   func_021BB570 0x021BB570 thumb ov093
 *   func_021B9184 0x021B9184 thumb ov093
 *   func_02082A90 0x02082A90 arm
 *   func_021EA824 0x021EA824 thumb ov093
 *   func_021D3F4C 0x021D3F4C thumb ov093
 *   func_021CD5E0 0x021CD5E0 thumb ov093
 *   d_021F00DC 0x021F00DC data a4
 *   func_021D1C40  0x021D1C40  thumb  ov093
 */
#include "../../matched/include/Obj00066.h"
#include "../../matched/include/Obj01237.h"

struct L;
struct H;
struct U16Vec;
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

typedef struct { u8 pad[0x1B2]; unsigned char f0:5; unsigned char flag:1; unsigned char f6:2; } Flags_021D1410;

typedef struct { u32 wpos, rpos; } Buf;

typedef struct { u8 pad[0x1B2]; unsigned char f0:3; unsigned char flag:1; unsigned char f4:4; } Flags_021D1A60;

typedef int (*Callback)(u8 *, int *, int *);

typedef struct { int code; Callback fn; } Entry;

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
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern int func_021EA6B0(char *p, u16 a, u16 b);
extern int func_021F7EB4(void);
extern void func_021F7F58(int a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F7998(u32 a);
extern void func_021B916C(u8 *p, u32 x);
extern void func_021EA600(char *p);
extern void *func_021BA02C(char *p, int i, int mode);
extern int func_02024450(const u16 *p);
extern void *func_0202435C(void *slots, unsigned int heap);
extern void func_021EA5E4(unsigned char *p, void *src);
extern void sub_02045808(struct U16Vec *vec);
extern void func_021EA5F0(char *p, struct H *h);
extern int func_021EEC20(int, u8 **);
extern int func_021BB570(u8 *, int, void *, u32);
extern void func_021B9184(void *);
extern void func_02082A90(const void *, void *, u32);
extern void func_021EA824(char *p);
extern int func_021D3F4C(void *);
extern int func_021CD5E0(Buf *, int *);
extern int func_021D1C40(BattleSeq *s, u8 x, int *out);
int func_021D1410(BattleSeq *s, int *state);
int func_021D1708(u8 *p, int *state);
int func_021D171C(u8 *p, int *state, void *a2);
void func_021D185C(BattleSeq *s, int a, int b);
int func_021D18EC(BattleSeq *s, int *state);
int func_021D1960(BattleSeq *s, int *state);
int func_021D1A18(BattleSeq *s, int *state);
int func_021D1A60(u8 *p, int *state);
int func_021D1A74(u8 *p, int *state, void *a2);
int func_021D1BD0(BattleSeq *s, int *state, int *pp);
extern const Entry d_021F00DC[];





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





/*
 * extent: compiled 18 bytes followed by two zero alignment bytes.
 * interface: r2 loads p+0x54 before bl; retained as third argument even where callee does not read it.
 */
int func_021D1708(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj00066 *)p)->f54;
    if (q != 0) return func_021D171C(p, state, q);
    return 1;
}





/*
 * lever: the 0x1B2 bit5 test is a byte bitfield, preserving the shift pair.
 */
int func_021D171C(u8 *p, int *state, void *a2)
{
    u32 mode;
    int idx;
    switch (*state) {
    case 0:
        if (((Flags_021D1410 *)p)->flag != 0) return 1;
        mode = func_021D13A4((BattleSeq *)p);
        func_021B916C(((struct Obj00066 *)p)->f0, mode);
        if (mode == 1) func_021F878C(func_021B86DC(((struct Obj00066 *)p)->f0));
        if (mode <= 1) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C((BattleSeq *)p, mode, 0);
            *state = 1;
        } else return 1;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) {
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 0);
            if (idx == func_021B904C(((struct Obj00066 *)p)->f0, 1)) return 1;
            func_021F7998(0x271);
            *state = 3;
        }
        break;
    case 3:
        if (func_021F7EB4() == 0) {
            mode = func_021D13A4((BattleSeq *)p);
            idx = func_021B904C(((struct Obj00066 *)p)->f0, 1);
            func_021F7F58(func_021BA020(((struct Obj00066 *)p)->f0, idx), 9, 0, 0, 0);
            func_021F7998(0x270);
            func_021D185C((BattleSeq *)p, mode, 1);
            *state = 4;
        }
        break;
    case 4:
        if (func_021F7EB4() == 0) {
            func_021EA600(((struct Obj00066 *)p)->f54);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA710(((struct Obj00066 *)p)->f54) != 0) return 1;
        break;
    }
    return 0;
}





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



int func_021D1A60(u8 *p, int *state)
{
    void *q;
    q = ((struct Obj01237 *)p)->f54;
    if (q != 0) return func_021D1A74(p, state, q);
    return 1;
}



int func_021D1A74(u8 *p, int *state, void *a2)
{
    u8 *args;
    int size;
    u16 len;
    Buf *buf;
    u32 i;
    int code;
again:
    switch (*state) {
    case 0:
        size = func_021EEC20(((struct Obj01237 *)p)->f50, &args);
        if (*(u8 * *)&((struct Obj01237 *)p)->fA0 != 0 && p[0x1AE] != 0 && ((Flags_021D1A60 *)p)->flag != 0) {
            if (func_021BB570(*(u8 * *)&((struct Obj01237 *)p)->fA0, p[0x1AE], args, size) != 0) {
                func_021B9184(((struct Obj01237 *)p)->f0);
                ((Flags_021D1A60 *)p)->flag = 0;
            }
            p[0x1AE] = 0;
        }
        buf = *(Buf * *)&((struct Obj01237 *)p)->f134;
        len = size;
        func_02082A90(args, buf + 1, len);
        buf->wpos = len;
        buf->rpos = 0;
        if (p[0x1A9] != 0) {
            p[0x1A9] = 0;
            func_021EA824(((struct Obj01237 *)p)->f54);
        }
        (*state)++;
    case 1:
        buf = *(Buf * *)&((struct Obj01237 *)p)->f134;
        if (buf->rpos == buf->wpos) {
            *state = 4;
            return 1;
        }
        if (func_021D3F4C(p + 0x18) != 0) return 1;
        (*state)++;
    case 2:
        code = func_021CD5E0(*(Buf * *)&((struct Obj01237 *)p)->f134, (int *)(p + 0x138));
        ((struct Obj01237 *)p)->f178 = code;
        if (code == 0x5E) return 1;
        for (i = 0; i < 0x5D; i++) {
            if (code == d_021F00DC[i].code) break;
        }
        if (i == 0x5D) {
            *state = 1;
            goto again;
        }
        *(Callback *)&((struct Obj01237 *)p)->f17C = d_021F00DC[i].fn;
        ((struct Obj01237 *)p)->f180 = 0;
        (*state)++;
    case 3:
        if ((*(Callback *)(p + 0x17C))(p, (int *)(p + 0x180), (int *)(p + 0x138)) != 0) {
            *state = 1;
            goto again;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}


int func_021D1BD0(BattleSeq *s, int *state, int *pp)
{
    int t;

    switch (*state) {
    case 0:
        func_021EAF18((struct L *)s->msg, 1, func_021D1C40(s, pp[0], &t));
        if (t != 0)
            func_021EAF50((struct L *)s->msg, pp[0]);
        func_021EAF50((struct L *)s->msg, pp[1]);
        func_021EA614(s->msgWin, (struct H *)s->msg);
        (*state)++;
        break;
    case 1:
        if (func_021EA710(s->msgWin) != 0)
            return 1;
        break;
    }
    return 0;
}
