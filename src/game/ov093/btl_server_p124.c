/*
 * file:     btl_server_p124.c
 * unit:     yes
 * function: func_021D04E4, func_021D055C, func_021D05C4, func_021D0644, func_021D06C8, func_021D0770, func_021D0980
 * address:  0x021D04E4
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
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B8588  0x021B8588  thumb  ov093
 *   func_021D7F2C  0x021D7F2C  thumb  ov093
 *   func_021CFBBC  0x021CFBBC  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021D799C  0x021D799C  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_0201C314  0x0201C314  thumb
 *   func_021CF5B0  0x021CF5B0  thumb  ov093
 *   func_0201C1C8  0x0201C1C8  thumb
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   _ull_mul       0x0209C054  arm
 *   func_021CFBA4 0x021CFBA4 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021CF470 0x021CF470 thumb ov093
 *   func_021D3DC4 0x021D3DC4 thumb ov093
 *   func_021D8358 0x021D8358 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021CFBF0 0x021CFBF0 thumb ov093
 *   func_021D8394 0x021D8394 thumb ov093
 *   func_021D83FC 0x021D83FC thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D6314 0x021D6314 thumb ov093
 *   func_021E8B80 0x021E8B80 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021CF524 0x021CF524 thumb ov093
 *   func_021CF81C 0x021CF81C thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021880BC 0x021880BC thumb ov096
 *   func_021CF58C 0x021CF58C thumb ov093
 *   func_02187FB0 0x02187FB0 thumb ov096
 *   func_02188134 0x02188134 thumb ov096
 *   func_02188140 0x02188140 thumb ov096
 *   func_021D8414 0x021D8414 thumb ov093
 */
#include "../../matched/include/Obj01690.h"
#include "../../matched/include/Obj00340.h"
#include "../../matched/include/Obj03197.h"
#include "../../matched/include/Obj00464.h"
#include "../../matched/include/Obj00489.h"

#define M (*(void **)(p+8))
#define R (*(u8 **)(p+12))
struct Q1;
struct S2;
struct QG;
struct UtilWork;
struct Unk021D62A8;
struct G;
struct Unk021D82D0;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char    s8;

typedef unsigned long long u64;

struct G {
    u8 pad0[0xf4];
    u64 seed;
    u64 mul;
    u64 add;
    u8 pad1[0xc];
    void *list;
};

typedef struct { u32 v; } Word;

extern u8 func_021B9B94(struct Q1 *p);
extern u32 func_021B8588(void **p);
extern u8 func_021D7F2C(u32 a, u8 b);
extern int func_021CFBBC(s8 *p, int v);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B68(void *m);
extern int func_021D59B4(u8 *p, int k);
extern int func_021D5B7C(void *m);
extern u16 func_021D57FC(void *m);
extern int func_021D799C(int a, int b);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u32 func_0201C314(void *p);
extern int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
extern u8 func_0201C1C8(void *p);
extern int func_021B9AB0(int k);
extern void func_021CFBA4(s8 *);
extern void func_021D8434(u32 *p);
extern u32 func_021CF470(u8 *, void *, u8 *);
extern u32 func_021D3DC4(u8 *, void *, void *);
extern void func_021D8358(u32 *p, u32 id, u32 sub, u32 val);
extern void *func_021B86B8(void ***);
extern int func_021CFBF0(u8 *, void *, u32, u8 *);
extern void func_021D8394(void *, u8, u32);
extern void func_021D83FC(u32 *p, u32 sub);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *, int);
extern u16 func_021E8B80(Word);
extern u32 func_021D81F8(void *, void *, void *, u32, void *);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u32 func_021CF524(u32, void *, u32);
extern u32 func_021CF81C(u8 *, void *, u8 *);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern void func_021880BC(int, u8 *, int);
extern void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
extern int func_02187FB0(u8 *);
extern u8 func_02188134(u8 *);
extern u8 func_02188140(u8 *);
extern void func_021D8414(u32 *);
int func_021D04E4(u8 *g, u8 a, u8 *out);
int func_021D055C(u8 *g, void *a, int b);
int func_021D05C4(u8 *g, u8 a, int b, u8 *out);
int func_021D0644(void *g, void *m, void *a, int b);
u8 func_021D06C8(struct G *g);
int func_021D0770(u8 *p, u32 *state);
u8 func_021D0980(u8 *g, u8 *out);



int func_021D04E4(u8 *g, u8 a, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj01690 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj01690 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj01690 *)g)->f118, (u8)i);
            if (func_021D5B68(m) == 0 && a == func_021D59B4(m, 0x11)) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}



int func_021D055C(u8 *g, void *a, int b)
{
    u32 n;
    u32 i;

    n = func_021B9B94(((struct Obj00340 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00340 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            if (func_021D0644(g, func_021B9C00(((struct Obj00340 *)g)->f118, (u8)i), a, b))
                return 1;
        }
    }
    return 0;
}



int func_021D05C4(u8 *g, u8 a, int b, u8 *out)
{
    u32 n;
    u32 i;
    u8 *m;

    n = func_021B9B94(((struct Obj03197 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj03197 *)g)->f0), g[0x11c]);
    for (; i < n; i++) {
        if (func_021CFBBC((s8 *)g, (u8)i) == 0) {
            m = func_021B9C00(((struct Obj03197 *)g)->f118, (u8)i);
            if (func_021D5B7C(m) != 0 && func_021D799C(a, func_021D57FC(m)) <= b) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}



int func_021D0644(void *g, void *m, void *a, int b)
{
    int x;
    u8 n;
    u32 i;
    u32 q;

    if (func_021D5B68(m) == 0) {
        x = func_021D57FC(a);
        n = func_021D5448(m);
        for (i = 0; i < n; i++) {
            q = func_021D54C0(m, (u8)i);
            if (func_021D5584(m, (u8)i) && func_0201C314((void *)q)
                && func_021CF5B0(g, m, q, 0) == 0) {
                if (func_021D799C(func_0201C1C8((void *)q), x) >= b)
                    return 1;
            }
        }
    }
    return 0;
}



u8 func_021D06C8(struct G *g)
{
    u8 buf[2];
    u32 cnt;
    u32 v;

    cnt = 1;
    buf[0] = 1;
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(2))) == 0) {
        buf[cnt++] = 2;
    }
    if (func_021D5B68(func_021B9C00(g->list, (u8)func_021B9AB0(3))) == 0) {
        buf[cnt++] = 3;
    }
    if (cnt > 1) {
        g->seed = g->mul * g->seed + g->add;
        if (cnt == 0) {
            v = (u32)(g->seed >> 32);
        } else {
            v = (u32)(((g->seed >> 32) * (u32)cnt) >> 32);
        }
        return buf[v];
    }
    return 1;
}


/*
 * lever: nested one-word aggregate return removes its extra frame word;
 *   named count/bytes reproduce original final read/store order. Three
 *   iteration runs, two scheduling variants; no prior compiles.
 * semantic: state/cursor arithmetic is unsigned; byte counters promote
 *   safely and narrow on store. CF81C writes all four availability bytes
 *   before return; CFBF0 writes the single output byte on every nonzero
 *   return path. Full-width pointer payloads retain their original bits.
 */
int func_021D0770(u8 *p, u32 *state)
{
    u8 available[4];
    u8 choice;
    u32 move;
    u32 slot;
    u32 sub;
    u32 result;
    u32 count;
    u32 bytes;
    switch (*state) {
    case 0:
        func_021CFBA4((s8 *)p);
        p[0x11d] = 0;
        p[0x1af] = 0;
        *state = 1;
    case 1:
        if (p[0x11d] >= p[0x11c]) break;
        M = func_021B9C00(((struct Obj00464 *)p)->f118, p[0x11d]);
        R = p+0x124+p[0x11d]*4;
        if (func_021D5B68(M)) {
            func_021D8434((u32 *)R);
            goto complete;
        }
        if (func_021CF470(p,M,R)) goto complete;
        move = func_021D3DC4(p,M,((struct Obj00464 *)p)->f118);
        if (move) {
            func_021D8358((u32 *)R,move,p[0x11d],0);
            goto complete;
        }
        if (func_021B86B8(*(void *** *)&((struct Obj00464 *)p)->f0) && func_021CFBF0(p,M,p[0x11d],&choice)) {
            func_021D8394(R,p[0x11d],choice);
            goto complete;
        }
        if (func_021B8588(((struct Obj00464 *)p)->f0) == 3) {
            slot = func_021D06C8((struct G *)p);
            if (slot != 1) {
                sub = func_021B9AB0(slot);
                func_021D83FC((u32 *)R,slot);
                M = func_021B9C00(((struct Obj00464 *)p)->f118,sub);
                p[0x1af] = 1;
                R = (u8 *)((u32)R+4U);
            }
        }
        if (func_021D62C4(M,0x19)) {
            move = func_021E8B80(func_021D6314(M,0x19));
            result = func_021D81F8(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,M,move,p+0xf4);
            func_021D82D0((struct Unk021D82D0 *)R,move,result);
            goto complete;
        }
        if (func_021CF524((u32)p,M,(u32)R)) *state = 3;
        func_021D5448(M);
        slot = func_021CF81C(p,M,available);
        if (slot != 4) {
            result = func_021B8D8C(((struct Obj00464 *)p)->f0,((struct Obj00464 *)p)->f4,func_021D5440(M));
            func_021880BC(*(int *)&((struct Obj00464 *)p)->fF0,available,result);
            *state = 2;
        } else {
            func_021CF58C((struct Unk021D82D0 *)((u32)R),(u8 *)((u32)p),M);
            goto complete;
        }
        break;
    case 2:
        if (func_02187FB0(*(u8 * *)&((struct Obj00464 *)p)->fF0)) break;
        slot = func_02188134(*(u8 * *)&((struct Obj00464 *)p)->fF0);
        if (slot != 4) {
            sub = func_02188140(*(u8 * *)&((struct Obj00464 *)p)->fF0);
            move = func_021D54C0(M,slot);
            func_021D82D0((struct Unk021D82D0 *)R,move,sub);
        } else func_021D8414((u32 *)R);
complete:
        *state = 3;
        break;
    case 3:
        p[0x11d]++;
        count = p[0x11c];
        if (p[0x11d] >= count) {
            bytes = (count+p[0x1af])*4;
            *(u8 * *)&((struct Obj00464 *)p)->fD8 = p+0x124;
            ((struct Obj00464 *)p)->fDC = bytes;
            p[0x1af] = 0;
            return 1;
        }
        *state = 1;
        break;
    }
    return 0;
}



u8 func_021D0980(u8 *g, u8 *out)
{
    u32 n;
    u8 c;
    u32 i;

    n = func_021B9B94(((struct Obj00489 *)g)->f118);
    i = func_021D7F2C(func_021B8588(((struct Obj00489 *)g)->f0), g[0x11c]);
    c = 0;
    for (; i < n; i = (u8)(i + 1)) {
        if (func_021D5B7C(func_021B9C00(((struct Obj00489 *)g)->f118, i))) {
            if (out)
                out[c] = i;
            c = (u8)(c + 1);
        }
    }
    return c;
}
