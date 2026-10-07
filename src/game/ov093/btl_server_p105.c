/*
 * file:     btl_server_p105.c
 * unit:     yes
 * function: func_021C9DE8, func_021C9E3C, func_021C9ECC, func_021C9F0C
 * address:  0x021C9DE8
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
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021C2128  0x021C2128  thumb  ov093
 *   func_021DCF78  0x021DCF78  thumb  ov093
 *   func_021DCF9C  0x021DCF9C  thumb  ov093
 *   func_021CD4FC  0x021CD4FC  thumb  ov093
 *   func_021CD568  0x021CD568  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C6E00  0x021C6E00  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021C60D4  0x021C60D4  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021C2250  0x021C2250  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D5734  0x021D5734  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

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

extern u8 *func_021B9934(char *p, int i);
extern int func_021D5B68(void *p);
extern int func_021D5B48(u8 *p);
extern int func_021C2128(u8 *p, u8 *a);
extern void *func_021DCF78(void *p, unsigned int k);
extern void func_021DCF9C(void *n);
extern int func_021CD4FC(void *p, int k);
extern void func_021CD568(void *p, int a, int k, u32 b);
extern u32 func_021CC8D8(void *lock, int line);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C6E00(u8 *p, u8 *a, u8 k);
extern int func_021C88E4(u8 *p);
extern void func_021C60D4(u8 *p, u8 *a);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021D5734(u8 *p, u8 i, u16 a, u8 b, u32 c);
int func_021C9DE8(u8 *w, struct Cmd_021C9DE8 *c);
int func_021C9E3C(u8 *w, struct Cmd_021C9E3C *c);
int func_021C9ECC(u8 *w, struct Cmd_021C9ECC *c);
int func_021C9F0C(u8 *w, const struct Cmd_021C9F0C *c);


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
