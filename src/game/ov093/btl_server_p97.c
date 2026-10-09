/*
 * file:     btl_server_p97.c
 * unit:     yes
 * function: func_021C9898, func_021C98C4, func_021C98E4, func_021C99A0, func_021C9A24
 * address:  0x021C9898
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
 *   func_021C3C60 0x021C3C60 thumb ov093
 *   func_021EF8E8 0x021EF8E8 thumb ov093
 *   func_021C4C50 0x021C4C50 thumb ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021C3B8C  0x021C3B8C  thumb  ov093
 *   func_021C3BB8  0x021C3BB8  thumb  ov093
 *   func_021C5A1C  0x021C5A1C  thumb  ov093
 *   func_021C5A34  0x021C5A34  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C7BF8  0x021C7BF8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C5DAC  0x021C5DAC  thumb  ov093
 *   func_021C5EFC  0x021C5EFC  thumb  ov093
 *   func_021C5E48  0x021C5E48  thumb  ov093
 *   func_021C5F98  0x021C5F98  thumb  ov093
 *   func_021C9A50 0x021C9A50 thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct Msg;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { int x; } S;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cmd_021C98E4 {
    u32 a : 8;
    u32 id : 5;
    u32 pad : 3;
    u32 pad2 : 7;
    u32 flag : 1;
    u32 pad3 : 8;
    u8 b4;
    u8 b5;
    u8 b6;
};

struct Msg {
    u16 a;
    u16 kind : 8;
    u16 n : 7;
    u16 flag : 1;
    u8 data[0x1C];
    u32 w20;
};

struct Cmd_021C9A24 { u32 a:8; u32 id:5; u32 pad:19; u32 w4; u8 b8; u8 pad9[3]; u8 data[16]; u8 b28; };

extern int func_021C3C60(u8 *, int, S, int);
extern int func_021EF8E8(int);
extern void func_021C4C50(u8 *, int);
extern u8 *func_021B9934(char *p, int i);
extern int func_021C3B8C(void *w, u32 a, u32 b);
extern void func_021C3BB8(u8 *p, u32 a, u32 b);
extern void func_021C5A1C(u8 *p, u8 *a);
extern void func_021C5A34(u8 *p, u8 *a);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021C7BF8(u8 *p);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C5DAC(u8 *p, u32 a, int n, const int *v);
extern void func_021C5EFC(u8 *p, u32 a, int n, const int *v);
extern void func_021C5E48(u8 *p, u32 a, u32 b, int n, int *v);
extern void func_021C5F98(u8 *p, u32 a, u32 b, int n, int *v);
extern int func_021C9A50(u32, u8, u8, const void *, u8);
int func_021C9898(u8 *p, u8 *q);
int func_021C98C4(u8 *p, u8 *q);
u8 func_021C98E4(u8 *w, struct Cmd_021C98E4 *c);
int func_021C99A0(void *w, const struct Msg *m);
u8 func_021C9A24(void *p, const struct Cmd_021C9A24 *q);

/*
 * extent: two bytes of trailing alignment padding.
 */
int func_021C9898(u8 *p, u8 *q)
{
    if (func_021C3C60(p, *(int *)(q + 4), *(S *)(q + 8), q[12])) {
        func_021C99A0(p, (const struct Msg *)(q + 16));
        return 1;
    }
    return 0;
}


int func_021C98C4(u8 *p, u8 *q)
{
    if (func_021EF8E8(*(int *)(q + 4))) {
        func_021C4C50(p, *(int *)(q + 4));
        return 1;
    }
    return 0;
}



u8 func_021C98E4(u8 *w, struct Cmd_021C98E4 *c)
{
    u8 *id = func_021B9934(*(char * *)&((struct Obj00003 *)w)->f8, (u8)c->id);
    int r = 0;
    u32 s;
    if (c->b4 != 0) {
        if (func_021C3B8C(w, c->b4, c->b5) != 0) {
            if (c->flag) func_021C5A1C(w, id);
            func_021C3BB8(w, c->b4, c->b5);
            func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
            r = 1;
            if (c->flag) func_021C5A34(w, id);
        }
    } else if (c->b6 != 0) {
        if (c->flag) func_021C5A1C(w, id);
        func_021C99A0(w, (const struct Msg *)((u8 *)c + 8));
        s = func_021CC8D8(w + 0x1D74, 15467);
        func_021C7BF8(w);
        func_021CC95C((u32 *)(w + 0x1D74), s, 15469);
        r = 1;
        if (c->flag) func_021C5A34(w, id);
    }
    return r;
}



int func_021C99A0(void *w, const struct Msg *m)
{
    if (!m->flag) {
        switch (m->kind) {
        case 1:
            func_021C5DAC(w, m->a, m->n, (const int *)m->data);
            return 1;
        case 2:
            func_021C5EFC(w, m->a, m->n, (const int *)m->data);
            return 1;
        }
    } else {
        u16 x = m->w20;
        switch (m->kind) {
        case 1:
            func_021C5E48(w, m->a, x, m->n, (int *)m->data);
            return 1;
        case 2:
            func_021C5F98(w, m->a, x, m->n, (int *)m->data);
            return 1;
        }
    }
    return 0;
}


/*
 * lever: const source pointer hoists the id load before the outgoing
 * stack-argument store; mutable source gave 16 scheduling bytes different.
 */
u8 func_021C9A24(void *p, const struct Cmd_021C9A24 *q)
{
    int r;
    if (func_021C9A50(q->w4, q->b8, q->id, q->data, q->b28)) r = 1;
    else r = 0;
    return r;
}
