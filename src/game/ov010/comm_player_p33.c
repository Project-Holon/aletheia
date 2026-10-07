/*
 * file:     comm_player_p33.c
 * unit:     yes
 * function: func_0216AE10, func_0216AED0, func_0216AEE8, func_0216AF1C, func_0216AF3C, func_0216AF74, func_0216B004
 * address:  0x0216AE10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012FB0  0x02012FB0  thumb
 *   func_0216662C  0x0216662C  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021767F0  0x021767F0  thumb  ov011
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_021665F0  0x021665F0  thumb  ov010
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02188C7C 0x02188C7C thumb ov021
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_0215901C 0x0215901C thumb ov010
 *   func_0217C274 0x0217C274 thumb ov018
 *   func_0217C2A0   0x0217C2A0  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217688C  0x0217688C  thumb  ov011
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020173EC  0x020173EC  thumb
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0200E2BC  0x0200E2BC  thumb
 *   func_021AA304  0x021AA304  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02029BCC  0x02029BCC  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_02012944  0x02012944  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_02012444  0x02012444  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02029C00  0x02029C00  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02029CC0  0x02029CC0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021B6100  0x021B6100  thumb  ov098
 *   func_021B6158  0x021B6158  thumb  ov098
 *   func_021B95A0  0x021B95A0  thumb  ov227
 *   func_021B95C8  0x021B95C8  thumb  ov227
 *   ov098_id       0x00000062  data
 *   ov227_id       0x000000E3  data
 *   d_021B6D74     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 */
#include "../../matched/include/Obj03543.h"

struct Ctx;
struct Obj00020;
struct VecFx32;
struct Desc;
struct Big;
struct Obj;
struct Work;
struct BigObj;
struct Evt;
struct P;
struct Sub02008700Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Key {
    u32 species : 11;
    u32 pad0 : 12;
    u32 form : 6;
    u32 pad1 : 3;
} Key;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 f10[0x10];       /* 0x10 */
    Key f20;            /* 0x20 */
    u16 f24;            /* 0x24 */
    u8 pad26[2];
    u16 *f28;           /* 0x28 */
} Work;

typedef signed int     s32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_02012FB0(unsigned char *base);
extern int func_0216662C(int a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02012138(const struct Ctx *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern void func_021767F0();
extern void *func_02184D38(void *p, int unused, int a, const int *q, u16 s, int t);
extern int func_021665F0(int a0, int a1, int a2);
extern struct Desc *func_0216B3A8(int a0, int a1, int a2);
extern void func_0215897C(void *vm, void *task);
extern void *func_02188C7C(u8 *p);
extern void *func_0216DE94(void *, u32);
extern u32 func_0215901C(void *, void *, u32);
extern void func_0217C274(unsigned int *out, char *p);
extern void func_0217C2A0(int, void *, void *);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E0B0(void *p);
extern int func_02158344(int a0);
extern int func_0217688C();
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC();
extern u32 func_020173EC(void);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode);
extern void func_021AA304();
extern void *func_020124E4(struct Obj *p);
extern void *func_02029BCC(void *a, u32 b);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern int func_020144DC(int a0, int a1);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007E50(u8 *base, u16 id, u16 qty, u16 d);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern u8 *func_02012944(void *p);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void *func_0200CA10(void *sv);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern void *func_02029C00(void *h);
extern void *func_020145CC(void *h);
extern void *func_02029CC0(void *h);
extern u32 func_020307B0(void *p);
extern int func_02189A08(unsigned char *p);
extern void func_021CF498(struct Ctx *c, u32 x, int idx);
extern struct P *func_021B6100(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u16 heap);
extern int func_021B6158(void *p);
extern void *func_021B95A0(u32 a, int b, u32 c, u32 heap);
extern void func_021B95C8(void *p);
int func_0216AE10(int a0, int a1);
void *func_0216AED0(void *p, u32 id);
void func_0216AEE8(int vm, int *out);
void func_0216AF1C(void *a0, void *a1, void *a2, void *a3);
void func_0216AF3C(int a0);
struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5);
int func_0216B004(void *evt, u32 *state, Work *w);
extern u8 ov098_id[];
extern u8 ov227_id[];
extern u8 d_021B6D74[];
extern u8 d_021B98A4[];


int func_0216AE10(int a0, int a1)
{
    int buf[3];
    int q[3];
    void *hd;
    void *b;
    void *c;
    int kind;
    int v;
    void *x;
    void *y;
    void *r;
    int s;

    hd = func_0215A5F4((void *)a1);
    b = func_0215A5DC((void *)a1);
    c = func_0215A5E4((void *)a1);
    kind = func_02159B10((void *)a0, (void *)a1);
    v = func_02012FB0(c);
    if (kind == 1 && func_0216662C(v) != 0) {
        x = func_0201210C((void *)b);
        y = func_02188CB4((void *)x);
        s = func_02012138(b);
        func_021A3038(y, (struct VecFx32 *)q);
        func_021767F0(s, c, buf);
        buf[0] = buf[0] + (q[0] - (0x3E << 14));
        r = func_02184D38(b, (int)x, 0x117, buf, 1, 0);
    } else {
        if (kind != 9)
            v = func_021665F0((int)b, func_02012FB0(c), kind);
        r = (void *)func_0216B3A8((int)b, kind, v);
    }
    func_0215897C(hd, r);
    return 1;
}

void *func_0216AED0(void *p, u32 id) { return func_0216DE94(func_02188C7C(func_0201210C(func_0215A5DC(p))), id); }

void func_0216AEE8(int vm, int *out)
{
    void *ws;
    ws = func_0215A5F4((void *)vm);
    func_0217C274((unsigned int *)out, (char *)((int)func_0216AED0((void *)vm, func_0215901C(ws, func_0215A5E4((void *)vm), 0x8011))));
}


/*
 * Overlay index on the first argument, then the pair call is staged with
 * the fourth argument.
 */
void func_0216AF1C(void *a0, void *a1, void *a2, void *a3)
{
    void *v = func_0215A5E4(a0);

    func_0217C274(a3, a1);
    func_0217C2A0(4, v, a3);
}


/*
 * Unblocked by matching func_0217688C (ov011, EXACT): the +0032 call site now
 * attests as `matched`.
 */
void func_0216AF3C(int a0)
{
    int a1;
    int t4;
    int t5;
    void *c;
    void *e;
    void *w;

t5 = a0 + 0;
    c = func_0215A5DC((void *)a0);
loc_0216AF44:
a0 = t5 + 0;
    e = func_0215A5E4((void *)a0);
loc_0216AF4C:
    w = func_02012EBC(e);
loc_0216AF52:
    func_0200E0B0(w);
loc_0216AF56:
    a0 = func_02012138(c);
loc_0216AF5C:
    a0 = func_02158344(a0);
loc_0216AF60:
t4 = a0 + 0;
    if (t4 == 0) goto loc_0216AF72;
loc_0216AF64:
    a0 = func_02012FB0(e);
loc_0216AF6A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0217688C(a0, a1);
loc_0216AF72:
    return;}


struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5)
{
    void *h;
    struct Desc *r;
    u8 *p;

    h = func_020120F4((const struct Ctx *)a0);
    r = func_020122C0((void *)a0, 0, (void *)func_0216B004, 0x3C);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x3C);
    ((struct Obj03543 *)p)->f0 = a1;
    *(u16 * *)&((struct Obj03543 *)p)->f28 = a4;
    ((struct Obj03543 *)p)->f24 = a5;
    ((struct Obj03543 *)p)->fC = a2;
    *(int *)&((struct Obj03543 *)p)->f20 = a3;
    ((struct Obj03543 *)p)->f2C = func_0203F1FC((const u8 *)a2, func_020173EC());
    if (func_0200E2BC(func_02012EBC(h), (u32 *)(&a3), (void *)a5, 0) == 0)
        ((struct Obj03543 *)p)->f20 = (((struct Obj03543 *)p)->f20 & 0xFFFFF800) | 0x28B;
    func_021AA304(p + 0x10, h, a1);
    return r;
}


/*
 * Proc main of an ov010 sub-sequence: a 9-state machine that registers the
 * party member's species/form key with the save (clearing the form to 12
 * when it is not yet seen), runs the ov098 screen and then the ov227 one,
 * and frees both work buffers when it runs past the last state.
 *
 * Byte-correct. Evidence gaps, not C: 0x02189A08 (ov021), 0x021B6158
 * (ov098) and 0x021B95C8 (ov227) carry no func_ label in their overlay
 * and have no second caller; d_021B6D74 and d_021B98A4 are the ov098 and
 * ov227 proc tables. Levers: `ok` at function scope (its slot sits above
 * the case-1 locals), heap declared before mon in both key blocks, and
 * the u16 flag stored in both arms of an if/else.
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int func_0216B004(void *evt, u32 *state, Work *w)
{
    void *h = func_020124E4(evt);
    void *sys = func_020120F4(h);
    int ok;

    switch (*state) {
    case 0:
        func_02012374(evt, func_02029BCC(h, 0x468));
        (*state)++;
        break;
    case 1: {
        u32 heap;
        void *mon;
        Key key;

        mon = w->f0c;
        heap = w->f24;

        key.species = func_02017E1C(mon, 5, 0);
        key.form = func_02017E1C(mon, 0x6F, 0);
        if (func_0200E2BC(func_02012EBC(sys), (u32 *)(&key), (void *)heap, 1) == 0)
            w->f20.form = 12;
        func_021CF498((struct Ctx *)func_02189A08(w->f00), (u32)evt, 0);
        (*state)++;
        break;
    }
    case 2:
        (*state)++;
        break;
    case 3:
        func_02012374(evt, (struct Evt **)func_020144DC((int)h, (int)w->f00));
        (*state)++;
        break;
    case 4: {
        void *sv = func_02012EBC(sys);

        func_02007E50(func_0201292C(sys), 0x240, 1, w->f24);
        func_02034AC4((u32)ov098_id);
        w->f04 = func_021B6100((u32)sys, (u32)w->f0c, (u32)w->f10, (u32)func_02012944(sys), (u32)func_0201292C(sys),
                               (u32)func_0200873C(sv), (u32)func_0200CA10(sv), w->f24);
        func_02012444(evt, -1, (u32)d_021B6D74, (u32)w->f04);
        (*state)++;
        break;
    }
    case 5: {
        u32 heap;
        void *mon;
        Key key;

        ok = func_021B6158(w->f04);
        mon = w->f0c;
        heap = w->f24;

        key.species = func_02017E1C(mon, 5, 0);
        key.form = func_02017E1C(mon, 0x6F, 0);
        if (func_0200E2BC(func_02012EBC(sys), (u32 *)(&key), (void *)heap, 1) == 0
            || func_0200E2BC(func_02012EBC(sys), (u32 *)(&w->f20), (void *)w->f24, 0) == 0)
            ok = 0;
        if (ok == 1)
            *w->f28 = 1;
        else
            *w->f28 = 0;
        func_02034A5C((u32)ov098_id);
        func_02034AC4((u32)ov227_id);
        w->f08 = func_021B95A0((u32)sys, ok, (u32)w->f0c, w->f24);
        func_02012444(evt, -1, (u32)d_021B98A4, (u32)w->f08);
        func_02007F1C(func_0201292C(sys), 0x240, 1, w->f24);
        (*state)++;
        break;
    }
    case 6:
        func_021B95C8(w->f08);
        func_02034A5C((u32)ov227_id);
        func_02012374(evt, func_02029C00(h));
        (*state)++;
        break;
    case 7:
        func_02012374(evt, func_020145CC(h));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_02029CC0(h));
        (*state)++;
        break;
    default:
        func_020307B0(w->f0c);
        func_020307B0(w->f04);
        return 1;
    }
    return 0;
}
