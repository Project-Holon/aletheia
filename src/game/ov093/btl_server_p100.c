/*
 * file:     btl_server_p100.c
 * unit:     yes
 * function: func_021C9BB8, func_021C9CC0, func_021C9DCC, func_021C9DE8, func_021C9E3C, func_021C9ECC, func_021C9F0C, func_021C9F4C, func_021C9F6C
 * address:  0x021C9BB8
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
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C7A54 0x021C7A54 thumb ov093
 *   func_021C7AA0 0x021C7AA0 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C2250 0x021C2250 thumb ov093
 *   func_021D6738 0x021D6738 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C5A1C 0x021C5A1C thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 *   func_021DCF78  0x021DCF78  thumb  ov093
 *   func_021DCF9C  0x021DCF9C  thumb  ov093
 *   func_021CD4FC  0x021CD4FC  thumb  ov093
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021C6E00  0x021C6E00  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021C60D4  0x021C60D4  thumb  ov093
 *   func_021D5734  0x021D5734  thumb  ov093
 *   func_021C0780 0x021C0780 thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA0B8 0x021CA0B8 thumb ov093
 *   func_021CA0C8 0x021CA0C8 thumb ov093
 *   func_021CA0D8 0x021CA0D8 thumb ov093
 *   func_021CA0E8 0x021CA0E8 thumb ov093
 *   func_021CA0F8 0x021CA0F8 thumb ov093
 *   func_021CA108 0x021CA108 thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021BF83C 0x021BF83C thumb ov093
 *   func_021BF3D8 0x021BF3D8 thumb ov093
 *   func_021BF4AC 0x021BF4AC thumb ov093
 *   func_021BF8D4 0x021BF8D4 thumb ov093
 *   func_021CA118 0x021CA118 thumb ov093
 *   func_021BD1E0 0x021BD1E0 thumb ov093
 *   func_021BD200 0x021BD200 thumb ov093
 *   func_021C091C 0x021C091C thumb ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj05194.h"

struct Msg;
struct QI;
struct Out64B4;
struct Unk021BD1E0;
struct Unk021BD200;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u16 value; u8 id,a,b,c; u8 padA[2]; u8 msg[36]; } Ent_021C9BB8;

typedef struct { u32 low:8,index:5,pad:10,flag:1,high:8; u8 id,pad5[3]; u8 msg[108]; } Ent_021C9CC0;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cmd_021C9DE8 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 f0 : 1;
    u32 f1 : 1;
};

struct Cmd_021C9E3C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u16 h6;
};

struct Cmd_021C9ECC {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u32 w4;
};

struct Cmd_021C9F0C {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 19;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u16 h8;
};

struct Out { u16 h0,h2,h4; u8 b6,pad7; u32 w8,wc,w10; };

struct State { u16 h0; u8 b2,b3,b4; u8 flag:1; u8 rest:7; };

extern u8 *func_021B9934(char *p, int i);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021C7A54(u8 *, u8 *, u32);
extern void func_021C7AA0(u8 *, u8 *);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
extern void func_021D6738(u8 *);
extern void func_021C195C(u8 *, u8 *, u32);
extern u16 func_021D5B40(struct QI *p);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern int func_021D5B68(void *p);
extern int func_021D5B48(u8 *p);
extern int func_021C2128(u8 *p, u8 *a);
extern void *func_021DCF78(void *p, unsigned int k);
extern void func_021DCF9C(void *n);
extern int func_021CD4FC(void *p, int k);
extern void func_021CD568(void *p, int a, int k, u32 b);
extern void func_021C6E00(u8 *p, u8 *a, u8 k);
extern int func_021C88E4(u8 *p);
extern void func_021C60D4(u8 *p, u8 *a);
extern void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
extern void func_021C0780(u8 *, u8 *, int, u8);
extern void func_021C64B4(u8 *p, u16 q, u8 *a, struct Out64B4 *out);
extern void func_021CA0B8(void *);
extern void func_021CA0C8(void *);
extern void func_021CA0D8(void *, u8 *);
extern void func_021CA0E8(void *, int);
extern void func_021CA0F8(void *);
extern int func_021CA108(void *);
extern void func_021C5718(u8 *, u8 *, u32);
extern void func_021BF83C(u8 *, u16 *, u8 *, int);
extern void func_021BF3D8(u8 *, int, u8 *, int, void *);
extern void func_021BF4AC(u8 *, u8 *, u8 *, void *, void *);
extern void func_021BF8D4(u8 *, u16 *, u8 *, int);
extern int func_021CA118(void *);
extern void func_021BD1E0(struct Unk021BD1E0 *p);
extern void func_021BD200(struct Unk021BD200 *p, u8 *q, u8 *a, int t);
extern void func_021C091C(u8 *, u8 *, u8 *, u8 *, u32, u32);
int func_021C9BB8(u8 *p, const Ent_021C9BB8 *e);
int func_021C9CC0(u8 *p, const Ent_021C9CC0 *e);
int func_021C9DCC(u8 *p, u8 *q);
int func_021C9DE8(u8 *w, struct Cmd_021C9DE8 *c);
int func_021C9E3C(u8 *w, struct Cmd_021C9E3C *c);
int func_021C9ECC(u8 *w, struct Cmd_021C9ECC *c);
int func_021C9F0C(u8 *w, const struct Cmd_021C9F0C *c);
int func_021C9F4C(u8 *p, u8 *q);
u8 func_021C9F6C(u8 *p, u8 *q);




int func_021C9BB8(u8 *p, const Ent_021C9BB8 *e)
{
    u8 *a;
    int line;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(((struct Obj00003 *)p)->f8, e->id);
    if (e->index != e->id) {
        line = 15615;
        s = func_021CC8D8(p + 0x1d74, line);
        f = func_021C7A54(p, a, e->value);
        func_021CC95C((u32 *)(p + 0x1d74), s, line + 2);
        if (f) {
            t = func_021CC8D8(p + 0x1d74, line + 6);
            func_021C7AA0(p, a);
            func_021CC95C((u32 *)(p + 0x1d74), t, line + 8);
            return 0;
        }
    }
    if (e->flag) func_021CD4B0(((struct Obj00003 *)p)->fC, 87, (u8)e->index);
    func_021C99A0(p, (const struct Msg *)e->msg);
    func_021C2250(p, a, e->value, 0);
    if (e->flag) func_021CD4B0(((struct Obj00003 *)p)->fC, 88, (u8)e->index);
    if (e->a) {
        func_021D6738(a);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 43, e->id);
    }
    if (e->b) {
        func_021D6738(func_021B9934(((struct Obj00003 *)p)->f8, e->c));
        func_021CD4B0(((struct Obj00003 *)p)->fC, 43, e->c);
    }
    func_021C195C(p, a, 0);
    return 1;
}





/*
 * lever: truncated accessor results live in u32 locals; u16 locals rotate seven spill offsets.
 */
int func_021C9CC0(u8 *p, const Ent_021C9CC0 *e)
{
    u8 *a;
    u8 *b;
    u16 x;
    u16 y;
    u32 s;
    u8 f;
    u32 t;
    a = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->id);
    b = func_021B9934(((struct Obj00003 *)p)->f8, (u8)e->index);
    x = (u16)(int)func_021D5B40((struct QI *)b);
    y = (u16)(int)func_021D5B40((struct QI *)a);
    s = func_021CC8D8(p + 0x1d74, 15671);
    f = func_021C7A54(p, a, x);
    func_021CC95C((u32 *)(p + 0x1d74), s, 15673);
    if (f) {
        t = func_021CC8D8(p + 0x1d74, 15676);
        func_021C7AA0(p, a);
        func_021CC95C((u32 *)(p + 0x1d74), t, 15678);
        return 0;
    }
    if (e->flag) func_021C5A1C(p, b);
    func_021C99A0(p, (const struct Msg *)e->msg);
    func_021C99A0(p, (const struct Msg *)(e->msg + 36));
    func_021C99A0(p, (const struct Msg *)(e->msg + 72));
    if (e->flag) func_021C5A34(p, b);
    func_021C2250(p, b, y, 0);
    func_021C2250(p, a, x, 0);
    func_021C195C(p, b, 0);
    func_021C195C(p, a, 0);
    return 1;
}





int func_021C9DCC(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    func_021C195C(p, a, *(u32 *)(q + 8));
    return 1;
}





int func_021C9DE8(u8 *w, struct Cmd_021C9DE8 *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    if (func_021D5B68(r) == 0 || c->f1) {
        if (c->f0 && func_021D5B48(r) != 0) return 0;
        if (func_021C2128(w, r) != 0) return 1;
    }
    return 0;
}





int func_021C9E3C(u8 *w, struct Cmd_021C9E3C *c)
{
    int r = (int)func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    int x;
    int t;
    u32 s;
    if (func_021D5B68((void *)r) == 0) {
        x = (int)func_021DCF78((void *)r, c->h6);
        if (x != 0) {
            t = func_021CD4FC(((struct Obj00003 *)w)->fC, 0x42);
            s = func_021CC8D8(w + 0x1D74, 15755);
            func_021C6E00(w, (u8 *)r, c->id);
            if (func_021C88E4(w) == 2) {
                func_021CD568(((struct Obj00003 *)w)->fC, t, 0x42, c->b4);
            }
            func_021CC95C((u32 *)(w + 0x1D74), s, 15762);
            func_021DCF9C((void *)x);
            return 1;
        }
    }
    return 0;
}





int func_021C9ECC(u8 *w, struct Cmd_021C9ECC *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    if (c->w4 == 0) {
        func_021C60D4(w, r);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
    }
    func_021C2250(w, r, 0, 1);
    return 1;
}





int func_021C9F0C(u8 *w, const struct Cmd_021C9F0C *c)
{
    u8 *r = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, c->b4);
    func_021CD4B0(((struct Obj00003 *)w)->fC, 0x1F, c->b4, c->b5, c->b6, c->b7, c->h8);
    func_021D5734(r, c->b5, c->h8, c->b6, c->b7);
    return 1;
}


int func_021C9F4C(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    func_021C0780(p, a, q[5], q[6]);
    return 1;
}

u8 func_021C9F6C(u8 *p, u8 *q)
{
    u8 work[28];
    struct Out *out = (struct Out *)(work + 8);
    u16 *saved;
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    u8 *b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[5]);
    struct State *state;
    u32 flag;
    func_021C64B4(p, *(u16 *)(q + 6), a, (struct Out64B4 *)out);
    func_021CA0B8(((struct Obj00003 *)p)->f860);
    func_021CA0C8(((struct Obj00003 *)p)->f868);
    func_021CA0D8(((struct Obj00003 *)p)->f868, b);
    func_021CA0E8(((struct Obj00003 *)p)->f868, 1);
    func_021CA0F8(((struct Obj00003 *)p)->f868);
    if (func_021CA108(((struct Obj00003 *)p)->f868)) {
        func_021C5718(p, a, ((u16 *)work)[4]);
        return 0;
    }
    func_021BF83C(p, (u16 *)out, a, *(int *)&((struct Obj00003 *)p)->f868);
    func_021BF3D8(p, (int)out, a, *(int *)&((struct Obj00003 *)p)->f868, p + 0x1f88);
    func_021BF4AC(p, (u8 *)out, a, ((struct Obj00003 *)p)->f868, p + 0x1f88);
    func_021BF8D4(p, (u16 *)out, a, *(int *)&((struct Obj00003 *)p)->f868);
    if (func_021CA118(((struct Obj00003 *)p)->f868)) return 0;
    state = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
    saved = (u16 *)work;
    saved[0] = ((struct Obj05194 *)state)->f0;
    saved[1] = ((struct Obj05194 *)state)->f2;
    saved[2] = ((struct Obj05194 *)state)->f4;
    func_021BD1E0((struct Unk021BD1E0 *)state);
    func_021BD200((struct Unk021BD200 *)(*(struct State * *)&((struct Obj00003 *)p)->f4A8), p, a, *(int *)&((struct Obj00003 *)p)->f868);
    (*(struct State * *)&((struct Obj00003 *)p)->f4A8)->b4 = 1;
    func_021C091C(p, (u8 *)out, a, *(u8 * *)&((struct Obj00003 *)p)->f868, (u32)(p + 0x1f88), 1);
    state = *(struct State * *)&((struct Obj00003 *)p)->f4A8;
    flag = state->flag;
    ((struct Obj05194 *)state)->f0 = saved[0];
    ((struct Obj05194 *)state)->f2 = saved[1];
    ((struct Obj05194 *)state)->f4 = saved[2];
    return flag;
}
