/*
 * file:     btl_server_p157.c
 * unit:     yes
 * function: func_021D2278, func_021D2320, func_021D2374, func_021D23B8, func_021D2424, func_021D2490, func_021D2510, func_021D2580, func_021D25C4, func_021D2628, func_021D266C, func_021D2700, func_021D2814, func_021D284C, func_021D28AC
 * address:  0x021D2278
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
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_0201BD28  0x0201BD28  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021EA0A0  0x021EA0A0  thumb  ov093
 *   func_021EA0E4  0x021EA0E4  thumb  ov093
 *   func_021EA0F4  0x021EA0F4  thumb  ov093
 *   func_021EA120  0x021EA120  thumb  ov093
 *   func_021EA40C  0x021EA40C  thumb  ov093
 *   func_021EA428  0x021EA428  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D646C  0x021D646C  thumb  ov093
 *   func_021EA438  0x021EA438  thumb  ov093
 *   func_021EA448  0x021EA448  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021B8590  0x021B8590  thumb  ov093
 *   func_021EA7C8  0x021EA7C8  thumb  ov093
 *   func_021EA7E8  0x021EA7E8  thumb  ov093
 *   func_021EA7D8  0x021EA7D8  thumb  ov093
 *   func_021EF9C0  0x021EF9C0  thumb  ov093
 *   func_021F7998  0x021F7998  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021EA678  0x021EA678  thumb  ov093
 *   func_021EA710  0x021EA710  thumb  ov093
 *   d_021EFFAE     0x021EFFAE  data   ov093  a2
 *   func_021EF9C8  0x021EF9C8  thumb  ov093
 *   func_021EA384  0x021EA384  thumb  ov093
 *   func_021EA3A0  0x021EA3A0  thumb  ov093
 *   func_021EA838  0x021EA838  thumb  ov093
 *   func_021EA850  0x021EA850  thumb  ov093
 *   func_021B8DEC  0x021B8DEC  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021EA904  0x021EA904  thumb  ov093
 *   func_021EA950  0x021EA950  thumb  ov093
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021F7E94 0x021F7E94 thumb ov094
 *   func_021F88BC  0x021F88BC  thumb  ov094
 *   func_021F7EA4  0x021F7EA4  thumb  ov094
 *   func_021B8DC0  0x021B8DC0  thumb  ov093
 *   func_021D6C50  0x021D6C50  thumb  ov093
 *   func_021EA8B4  0x021EA8B4  thumb  ov093
 *   func_021EA8D4  0x021EA8D4  thumb  ov093
 */
#include "../../matched/include/Obj06240.h"
#include "../../matched/include/Obj07782.h"
#include "../../matched/include/Obj05206.h"
#include "../../matched/include/Obj05207.h"
#include "../../matched/include/Obj10019.h"
#include "../../matched/include/Obj10021.h"
#include "../../matched/include/Obj07783.h"
#include "../../matched/include/Obj06241.h"
#include "../../matched/include/Obj07784.h"
#include "../../matched/include/Obj04364.h"
#include "../../matched/include/Obj21158.h"
#include "../../matched/include/Obj03693.h"

struct S;
struct Unk021D6C50;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u8 unk08[0x4C];
    void *win;            /* 0x54 */
} Seq;

typedef struct { u16 a; u16 b; } Pair16;

extern u32 func_021CD9E0(u8 *p);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u32 func_0201BD28(u16 id, u32 field);
extern void func_020061E4(unsigned int arg);
extern void func_021EA0A0(u32 *p, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u8 s7);
extern int func_021EA0E4(u32 *p);
extern void func_021EA0F4(struct S *s, u32 a, u32 b, u32 c);
extern int func_021EA120(struct S *s);
extern void func_021EA40C(char *ctx, int a);
extern int func_021EA428(u32 *p);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D646C(void *p);
extern void func_021EA438(u32 *p, u32 a2);
extern int func_021EA448(u32 *p);
extern u8 func_021B8E70(u8 *p, u32 k);
extern unsigned int func_021B8590(unsigned char *p);
extern void func_021EA7C8(void *ctx, int a);
extern int func_021EA7E8(void *w, int v);
extern void func_021EA7D8(void *ctx, int a);
extern int *func_021EF9C0(int *p, int a, int b);
extern void func_021F7998(u32 a);
extern int func_021F7EB4(void);
extern void func_021EA678(char *p, u16 k, int *c);
extern int func_021EA710(u32 *p);
extern void func_021EF9C8(int *p);
extern void func_021EA384(char *ctx, int a);
extern int func_021EA3A0(u32 *p);
extern void func_021EA838(u32 *p, u32 k);
extern int func_021EA850(u32 *p, u32 k);
extern int func_021B8DEC(void *p, u32 k);
extern char *func_021B9AEC(char *p, int i);
extern void func_021B9C10(u32 *p, int a, int b);
extern void func_021EA904(void *w, u32 a, u32 b, u32 c, int d, int e);
extern int func_021EA950(void *w);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern void func_021F7E94(int a);
extern void func_021F88BC(int v);
extern void func_021F7EA4(u32 v);
extern unsigned char func_021B8DC0(unsigned char *p, void *a, unsigned int b);
extern int func_021D6C50(struct Unk021D6C50 *a, struct Unk021D6C50 *b);
extern void func_021EA8B4(char *ctx, u32 a, u32 b);
extern int func_021EA8D4(u32 *p);
int func_021D2278(Seq *s, int *state, u32 *a);
int func_021D2320(u8 *p, int *st, u32 *c);
int func_021D2374(u8 *p, int *st, u32 *c);
int func_021D23B8(u8 *p, int *st, u32 *c);
int func_021D2424(u8 *p, int *st, u32 *c);
int func_021D2490(u8 *p, int *st, u32 *c);
int func_021D2510(u8 *p, int *st, u32 *c);
int func_021D2580(u8 *p, int *st, u32 *c);
int func_021D25C4(u8 *p, int *st, u32 *c);
int func_021D2628(u8 *p, int *st, u32 *c);
int func_021D266C(u8 *p, int *st, u32 *c);
int func_021D2700(u32 *p, int *st, u32 *c);
int func_021D2814(char *p, int *state, unsigned int *q);
int func_021D284C(u8 *p, int *st, u32 *c);
int func_021D28AC(u8 *p, int *st, u32 *c);
extern Pair16 d_021EFFAE[5];


int func_021D2278(Seq *s, int *state, u32 *a)
{
    int t;

    switch (*state) {
    case 0:
        if (func_021CD9E0((u8 *)s) == 0) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            func_021EA0A0(s->win, t, t, 1, func_0201BD28(1, 0x1B), 0, 0);
        }
        *state = *state + 1;
        break;
    case 1:
        if (func_021EA0E4(s->win)) {
            t = func_021B8D8C((void *)s->unk00, (void *)s->unk04, (u8)a[0]);
            if (func_021CD9E0((u8 *)s) == 0) {
                func_020061E4(0x564);
            }
            func_021EA0F4(s->win, 1, t, 1);
            *state = *state + 1;
        }
        break;
    case 2:
        if (func_021EA120(s->win)) {
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D2320(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA40C(((struct Obj06240 *)p)->f54, func_021B8D8C(((struct Obj06240 *)p)->f0, ((struct Obj06240 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA428(((struct Obj06240 *)p)->f54)) {
            func_021D646C(func_021B9934(((struct Obj06240 *)p)->f4, (u8)(*c)));
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D2374(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA438(((struct Obj07782 *)p)->f54, func_021B8D8C(((struct Obj07782 *)p)->f0, ((struct Obj07782 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA448(((struct Obj07782 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}


int func_021D23B8(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05206 *)p)->f0, func_021B8D8C(((struct Obj05206 *)p)->f0, ((struct Obj05206 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05206 *)p)->f0))
            return 1;
        func_021EA7C8(((struct Obj05206 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05206 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}


int func_021D2424(u8 *p, int *st, u32 *c)
{
    u32 t = func_021B8E70(((struct Obj05207 *)p)->f0, func_021B8D8C(((struct Obj05207 *)p)->f0, ((struct Obj05207 *)p)->f4, (u8)(*c)));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj05207 *)p)->f0))
            return 1;
        func_021EA7D8(((struct Obj05207 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA7E8(((struct Obj05207 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}


int func_021D2490(u8 *p, int *st, u32 *c)
{
    u8 id = c[0];

    switch (*st) {
    case 0:
        func_021EF9C0(((struct Obj10019 *)p)->f34, (u8)id, (u16)c[1]);
        if (func_021CD9E0(p))
            return 1;
        if (id < 5)
            func_021F7998(d_021EFFAE[id].b);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            func_021EA678(((struct Obj10019 *)p)->f54, d_021EFFAE[id].a, 0);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj10019 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}


int func_021D2510(u8 *p, int *st, u32 *c)
{
    u16 v;

    switch (*st) {
    case 0:
        switch ((u8)c[0]) {
        case 1:
            v = 0x59;
            break;
        case 2:
            v = 0x5a;
            break;
        case 4:
            v = 0x5b;
            break;
        case 3:
            v = 0x5c;
            break;
        default:
            return 1;
        }
        func_021EA678(((struct Obj10021 *)p)->f54, v, 0);
        (*st)++;
        break;
    case 1:
        if (func_021EA710(((struct Obj10021 *)p)->f54)) {
            func_021EF9C8(((struct Obj10021 *)p)->f34);
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D2580(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07783 *)p)->f54, func_021B8D8C(((struct Obj07783 *)p)->f0, ((struct Obj07783 *)p)->f4, (u8)(*c)));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07783 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}


int func_021D25C4(u8 *p, int *st, u32 *c)
{
    int t = func_021B8D8C(((struct Obj06241 *)p)->f0, ((struct Obj06241 *)p)->f4, (u8)(*c));

    switch (*st) {
    case 0:
        if (func_021CD9E0(p))
            return 1;
        if (!func_021B8590(((struct Obj06241 *)p)->f0))
            return 1;
        func_021EA838(((struct Obj06241 *)p)->f54, t);
        (*st)++;
        break;
    case 1:
        if (func_021EA850(((struct Obj06241 *)p)->f54, t))
            return 1;
        break;
    }
    return 0;
}


int func_021D2628(u8 *p, int *st, u32 *c)
{
    u8 id = *c;

    switch (*st) {
    case 0:
        func_021EA384(((struct Obj07784 *)p)->f54, func_021B8D8C(((struct Obj07784 *)p)->f0, ((struct Obj07784 *)p)->f4, id));
        (*st)++;
        break;
    case 1:
        if (func_021EA3A0(((struct Obj07784 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}


int func_021D266C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 a = c[0];
        u32 b = (u8)c[1];
        u32 d = (u8)c[2];
        int x = func_021B8DEC(((struct Obj04364 *)p)->f0, b);
        int y = func_021B8DEC(((struct Obj04364 *)p)->f0, d);
        u32 m = func_021B8E70(((struct Obj04364 *)p)->f0, b);
        u32 n = func_021B8E70(((struct Obj04364 *)p)->f0, d);
        func_021B9C10((u32 *)func_021B9AEC(((struct Obj04364 *)p)->f4, a), x, y);
        func_021EA904(((struct Obj04364 *)p)->f54, a, m, n, x, y);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA950(((struct Obj04364 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}

int func_021D2700(u32 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0:
        func_021F7998(0x281);
        (*st)++;
        break;
    case 1:
        if (!func_021F7EB4()) {
            u8 a = c[0], b = c[1];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 2:
        if (func_021EA950((void *)p[21])) {
            u8 a = c[2], b = c[3];
            u32 x, y, v, w;
            x = func_021B8BEC((u8 *)p[0], a, b);
            y = func_021B8BEC((u8 *)p[0], a, 1);
            v = func_021B8E70((u8 *)p[0], x);
            w = func_021B8E70((u8 *)p[0], y);
            func_021B9C10((u32 *)func_021B9AEC((char *)p[1], a), b, 1);
            func_021EA904((u32 *)p[21], a, v, w, b, 1);
            (*st)++;
        }
        break;
    case 3:
        if (func_021EA950((void *)p[21])) return 1;
        break;
    }
    return 0;
}

/*
 * evidence: Thumb 01 49 02 4b 18 47 c0 46; pools 0x26e and 0x021F7A29. No ARM9/SDK blocker work.
 * note 2026-10-05 (D8 lane16): re-verified MATCH. Callee 0x021F7E94 is an ov094 Thumb tail stub (pool 0x26E, 0x021F7A29); other overlay, not filed. Integrator: seed label.
 */
int func_021D2814(char *p, int *state, unsigned int *q)
{
    switch (*state) {
    case 0:
        func_021F7E94((u8)func_021B8E70(*(void **)p, (u8)q[0]));
        (*state)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) return 1;
        break;
    }
    return 0;
}


int func_021D284C(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u32 t = func_021B8E70(((struct Obj21158 *)p)->f0, (u8)(*c));
        if (func_021CD9E0(p))
            func_021F88BC(1);
        func_021F7EA4(t);
        (*st)++;
        break;
    }
    case 1:
        if (!func_021F7EB4()) {
            if (func_021CD9E0(p))
                func_021F88BC(0);
            return 1;
        }
        break;
    }
    return 0;
}


int func_021D28AC(u8 *p, int *st, u32 *c)
{
    switch (*st) {
    case 0: {
        u8 *a = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[0]);
        u8 *b = func_021B9934(*(char * *)&((struct Obj03693 *)p)->f4, (u8)c[1]);
        int d = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[0]);
        int e = (int)func_021B8DC0(((struct Obj03693 *)p)->f0, ((struct Obj03693 *)p)->f4, (u8)c[1]);
        func_021D6C50((struct Unk021D6C50 *)a, (struct Unk021D6C50 *)b);
        func_021EA8B4(((struct Obj03693 *)p)->f54, d, e);
        (*st)++;
        break;
    }
    case 1:
        if (func_021EA8D4(((struct Obj03693 *)p)->f54))
            return 1;
        break;
    }
    return 0;
}
