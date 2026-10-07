/*
 * file:     btl_server_p139.c
 * unit:     yes
 * function: func_021CF430, func_021CF448, func_021CF470, func_021CF524, func_021CF58C, func_021CF5B0, func_021CF81C, func_021CF89C, func_021CF8D4, func_021CF918, func_021CF9B4, func_021CFAC4, func_021CFADC, func_021CFB8C, func_021CFBA4
 * address:  0x021CF430
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
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D8434  0x021D8434  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D8444  0x021D8444  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021E8B80  0x021E8B80  thumb  ov093
 *   func_021D67C4  0x021D67C4  thumb  ov093
 *   func_021D82D0  0x021D82D0  thumb  ov093
 *   func_021D67A8  0x021D67A8  thumb  ov093
 *   func_021D5778  0x021D5778  thumb  ov093
 *   func_021D5448  0x021D5448  thumb  ov093
 *   func_021D54C0  0x021D54C0  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D5750 0x021D5750 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_0201C314 0x0201C314 thumb
 *   func_021D67B8 0x021D67B8 thumb ov093
 *   func_021D62D8 0x021D62D8 thumb ov093
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   func_021EFC1C 0x021EFC1C thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021B8D38 0x021B8D38 thumb ov093
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 */
#include "../../matched/include/Obj01894.h"
#include "../../matched/include/Obj07774.h"

struct Unk021D82D0;
struct QL;
struct Unk021D62A8;
struct UtilWork;
struct QG;
struct L;
struct QI;
struct UtilSlots;
struct S2;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 v; } Word;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

extern int func_021D5B68(void *q);
extern void func_021D8434(u32 *p);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D8444(u32 *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern Word func_021D6314(void *q, int i);
extern u16 func_021E8B80(Word v);
extern u8 func_021D67C4(u8 *p);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern u16 func_021D67A8(struct QL *p);
extern u8 func_021D5778(void *q, u32 id);
extern u8 func_021D5448(struct QG *p);
extern u16 func_021D54C0(u8 *p, int i);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern u32 func_021D81F8(void *, void *, void *, u32, void *);
extern int func_021D5750(void *, u32);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern u16 func_021D5B40(struct QI *p);
extern u8 func_021D5440(u8 *p);
extern u32 func_0201C314(void *p);
extern u16 func_021D67B8(u8 *p);
extern u16 func_021D62D8(struct UtilSlots *p, int i);
extern int func_0201BEB8(u32, int);
extern void *func_021EFCE4(char *arg0, int arg1);
extern int func_021EFC1C(int, int, void *, u32);
extern int func_021D59B4(u8 *p, int k);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021B8D8C(void *, void *, u32);
extern u8 func_021B8D38(void *p, int a, int k, u8 *out);
extern u8 *func_021B9934(char *p, int i);
extern int func_021D5814(void *m, int k);
void func_021CF430(u8 *p, u32 i, u32 v);
u8 func_021CF43C(u8 *p, u32 i);
u8 func_021CF448(u8 *p);
u32 func_021CF470(u8 *p, void *q, u8 *o);
u32 func_021CF524(u32 x, void *q, u32 y);
void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
int func_021CF5B0(u8 *g, void *m, u32 move, void *out);
u32 func_021CF81C(u8 *p, void *q, u8 *out);
int func_021CF89C(u8 *p, void *q);
u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b);
u32 func_021CF918(u8 *g, u8 *a, u16 *b);
u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b);
int func_021CFAC4(void *p, void *q);
int func_021CFADC(u8 *g, void *m);
int func_021CFB8C(void *p, void *q);
void func_021CFBA4(s8 *p);

/*
 * follower: unlabelled byte accessor at 0x021CF43C.
 */
void func_021CF430(u8 *p, u32 i, u32 v)
{
    (p + i)[0x130] = v;
}

u8 func_021CF43C(u8 *p, u32 i)
{
    return (p + i)[0x130];
}

u8 func_021CF448(u8 *p)
{
    u32 i;
    u32 sum;
    u32 n;
    sum = 0;
    n = p[0x11d];
    i = 0;
    for (; i < n; i++) sum += p[0x130+i];
    return sum;
}


u32 func_021CF470(u8 *p, void *q, u8 *o)
{
    u32 id;
    u32 a;
    u32 b;
    Word t;
    if (func_021D5B68(q) != 0) {
        if (o != 0) {
            func_021D8434((u32 *)o);
        }
        return 1;
    }
    if (func_021D5BDC(q, 0xc) != 0) {
        if (o != 0) {
            func_021D8444((u32 *)o);
        }
        return 1;
    }
    id = 0x19;
    if (func_021D62C4(q, id) != 0) {
        t = func_021D6314(q, id);
        id = func_021E8B80(t);
        b = func_021D67C4(q);
        if (o != 0) {
            func_021D82D0((struct Unk021D82D0 *)o, id, b);
        }
        return 1;
    }
    if (func_021D62C4(q, 0x1a) != 0) {
        a = func_021D67A8(q);
        b = func_021D67C4(q);
        func_021D5778(q, a);
        if (o != 0) {
            func_021D82D0((struct Unk021D82D0 *)o, a, b);
        }
        return 1;
    }
    return 0;
}


u32 func_021CF524(u32 x, void *q, u32 y)
{
    u32 n = func_021D5448(q);
    u32 c = 0;
    u32 i = 0;
    for (; i < n; i++) {
        if (func_021CF5B0((u8 *)x, q, (u32)func_021D54C0(q, (u8)i), 0) == 0) {
            if ((u32)func_021D5584(q, (u8)i) != 0) {
                c++;
            }
        }
    }
    if (c == 0) {
        func_021CF58C((struct Unk021D82D0 *)y, (u8 *)x, q);
        return 1;
    }
    return 0;
}

void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q)
{
    u32 v;
    v = func_021D81F8(((struct Obj01894 *)p)->f0, ((struct Obj01894 *)p)->f4, q, 165, p+0x38);
    func_021D82D0(out, 165, v);
}

int func_021CF5B0(u8 *g, void *m, u32 move, void *out)
{
    u32 k;
    u32 k2;
    Word w;
    if (move == 0xa5) return 0;
    if (func_021CF89C(g, m) && func_021D62C4(m, 0x1b)) {
        w = func_021D6314(m, 0x1b);
        k = func_021E8B80(w);
        if (func_021D5750(m, k) && k != move) {
            if (out) {
                func_021EAF18(out, 1, 0x63);
                func_021EAF50(out, func_021D5B40(m));
                func_021EAF50(out, k);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0x17)) {
        k2 = func_021E8B80(func_021D6314(m, 0x17));
        if (move != k2) {
            if (out) {
                func_021EAF18(out, 1, 0x64);
                func_021EAF50(out, func_021D5440(m));
                func_021EAF50(out, k2);
            }
            return 1;
        }
    }
    if (func_021D62C4(m, 0xb) && func_0201C314((void *)move) == 0) {
        if (out) {
            func_021EAF18(out, 2, 0x23b);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xc) && move == func_021D67B8(m)) {
        if (out) {
            func_021EAF18(out, 2, 0x244);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xd) && move == func_021D62D8(m, 0xd) && move != 0xa5) {
        if (out) {
            func_021EAF18(out, 2, 0x253);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021D62C4(m, 0xf) && func_0201BEB8(move, 0xc)) {
        if (out) {
            func_021EAF18(out, 2, 0x37a);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 3) && func_021EFC1C(*(int *)&((struct Obj01894 *)g)->f34, *(int *)&((struct Obj01894 *)g)->f4, m, move)) {
        if (out) {
            func_021EAF18(out, 2, 0x24d);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) && func_0201BEB8(move, 9)) {
        if (out) {
            func_021EAF18(out, 2, 0x43e);
            func_021EAF50(out, func_021D5440(m));
            func_021EAF50(out, move);
        }
        return 1;
    }
    return 0;
}


u32 func_021CF81C(u8 *p, void *q, u8 *out)
{
    u8 n = func_021D5448(q);
    u32 r = 4;
    u8 i = 0;
    for (; i < n; i++) {
        if (func_021D5584(q, i) != 0) {
            out[i] = (func_021CF5B0(p, q, func_021D54C0(q, i), 0) == 0) ? 1 : 0;
            if (r == 4 && out[i] != 0) {
                r = i;
            }
        } else {
            out[i] = 0;
        }
    }
    for (; i < 4; i++) {
        out[i] = 0;
    }
    return r;
}

int func_021CF89C(u8 *p, void *q)
{
    if (func_021EFCE4(*(char * *)&((struct Obj01894 *)p)->f34, 7)) return 0;
    if (func_021D62C4(q, 19)) return 0;
    if (func_021D59B4(q, 17) != 103) return 1;
    return 0;
}


u32 func_021CF8D4(u8 *p, void *q, u8 *a, u16 *b)
{
    u32 r;
    if (func_021CF89C(p, q) != 0) {
        if (func_021D5B40(q) == 0x127) {
            return 4;
        }
    }
    r = func_021CF9B4(p, q, a, b);
    if (r == 4) {
        *a = 0x1f;
        *b = 0;
        r = 4;
    }
    return r;
}


u32 func_021CF918(u8 *g, u8 *a, u16 *b)
{
    u32 i;
    u8 *m;
    u32 r;

    for (i = 0; i < g[0x11c]; i++) {
        m = func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i);
        if (func_021D5B68(m) == 0) {
            if (func_021CF89C(g, m) != 0 && func_021D5B40((struct QI *)m) == 0xe4)
                return 4;
            if (func_021D59B4(m, 0x11) == 0x32)
                return 4;
        }
    }
    for (i = 0; i < g[0x11c]; i++) {
        r = func_021CF9B4(g, func_021B9C00(((struct Obj07774 *)g)->f118, (u8)i), a, b);
        if (r != 4)
            return r;
    }
    return 4;
}

u32 func_021CF9B4(u8 *g, void *m, u8 *a, u16 *b)
{
    u8 buf[4];
    u8 n;
    u8 i;
    u8 *q;
    u16 k;
    n = func_021B8D38(((struct Obj01894 *)g)->f0, *(int *)&((struct Obj01894 *)g)->f4, (u16)(func_021B8D8C(((struct Obj01894 *)g)->f0, ((struct Obj01894 *)g)->f4, func_021D5440(m)) | 0x100), buf);
    for (i = 0; i < n; i++) {
        q = func_021B9934(((struct Obj01894 *)g)->f4, buf[i]);
        k = func_021D59B4(q, 0x11);
        func_021D5440(q);
        if (k == 0x17 && func_021CFAC4(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x47 && func_021CFADC(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
        if (k == 0x2a && func_021CFB8C(g, m)) {
            *a = func_021D5440(q);
            *b = k;
            return 0;
        }
    }
    if (func_021D62C4(m, 0x16) || func_021D62C4(m, 8) || func_021D62C4(m, 0x15)) {
        *a = func_021D5440(m);
        *b = 0;
        return 3;
    }
    return 4;
}

int func_021CFAC4(void *p, void *q)
{
    if (func_021D59B4(q, 17) != 23) return 1;
    return 0;
}


int func_021CFADC(u8 *g, void *m)
{
    u32 a;

    a = func_021CF89C(g, m);
    if (func_021EFCE4((char *)(*(int *)&((struct Obj01894 *)g)->f34), 2) != 0)
        return 1;
    if (func_021D62C4(m, 0x1f) != 0)
        return 1;
    if (func_021D62C4(m, 0x15) != 0)
        return 1;
    if (a != 0 && func_021D5B40(m) == 0x116)
        return 1;
    if (func_021D59B4(m, 0x11) == 0x1a)
        return 0;
    if (func_021D5814(m, 2) != 0)
        return 0;
    if (func_021D62C4(m, 0x1e) != 0)
        return 0;
    if (func_021D62C4(m, 0x20) != 0)
        return 0;
    if (a != 0 && func_021D5B40(m) == 0x21d)
        return 0;
    return 1;
}

/*
 * extent: follower 0x021CFBA4 already has its own matched source/shard.
 */
int func_021CFB8C(void *p, void *q)
{
    if (func_021D5814(q, 8)) return 1;
    return 0;
}

/*
 * semantic: signed byte -1 has the original stored bits 0xff. The body
 *   only writes bytes and never reads through p. Six stores cover p10c..p111.
 */
void func_021CFBA4(s8 *p)
{
    u32 i = 0;
    s8 fill = -1;
    for (; i < 6; i++) p[0x10c+i] = fill;
}
