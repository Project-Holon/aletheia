/*
 * file:     btl_server_p44.c
 * unit:     yes
 * function: func_021C25A4, func_021C264C, func_021C26A8, func_021C26FC, func_021C2758, func_021C27A0, func_021C282C, func_021C2910
 * address:  0x021C25A4
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
 *   func_021C8810  0x021C8810  thumb  ov093
 *   func_021C8828  0x021C8828  thumb  ov093
 *   func_021C99A0  0x021C99A0  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C5C74  0x021C5C74  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021C2B3C  0x021C2B3C  thumb  ov093
 *   func_021C2BA4  0x021C2BA4  thumb  ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C2AA0 0x021C2AA0 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021C5D88 0x021C5D88 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021C2BF0 0x021C2BF0 thumb ov093
 *   func_021C2CA8 0x021C2CA8 thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021C2C50 0x021C2C50 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct Msg;
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 v; } Word;

struct Slot { u32 a : 3; u32 rest : 29; };

struct Unk021D62A8 { u8 pad[0x1c]; struct Slot e[6]; };


struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

extern void func_021C8810(u8 *lock);
extern u32 func_021C8828(u8 *p);
extern int func_021C99A0(void *w, const struct Msg *m);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021C5C74(u8 *p, u8 *a, int kind, u32 v);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021C2B3C(u8 *p, u8 *a, u8 *b, u32 c);
extern void func_021C2BA4(u8 *p, u8 *a, u8 *b, u32 c);
extern int func_021D62C4(struct Unk021D62A8 *, int);
extern int func_021D62A8(struct Unk021D62A8 *);
extern int func_021C2AB0(u8 *);
extern u16 func_021D57FC(void *);
extern int func_021E8D24(int x, int k);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C5C1C(u8 *, u8 *, int, Word);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C2AA0(int, Word, u8 *, struct Msg *);
extern u16 func_021D5444(struct QF *p);
extern void func_021D8510(void *p);
extern void func_021D66D8(void *, u8);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void *func_021D8484(void *a);
extern void func_021C5D88(u8 *, u8 *, int);
extern int func_021D7D6C(int);
extern void func_021C2BF0(u8 *, u8 *, u8 *, u32, u32);
extern void func_021C2CA8(u8 *p, u8 *a);
extern void func_021C3FDC(u8 *, u8 *);
extern void func_021C2C50(u8 *, u8 *, u8 *, u32);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
int func_021C25A4(u8 *p, u8 *a, u8 *b, u32 unused, u32 s0, Word s1, u32 s2);
int func_021C264C(u8 *p, u8 *a, u8 *b, u32 c);
void func_021C26A8(u8 *p, u32 a, u8 *b, u8 *c, u32 d);
void func_021C26FC(u8 *p, u8 *a, u8 *b, u32 c, Word *d);
int func_021C2758(u8 *p, u8 *x, u8 *y, int z, Word a, u32 b, u32 c);
int func_021C27A0(u8 *p, u8 *x, u8 *y, int z, Word a, u8 b, u32 c);
int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, Word d, u8 e);
void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, Word value, int f, int g, const struct Msg *m);





int func_021C25A4(u8 *p, u8 *a, u8 *b, u32 unused, u32 s0, Word s1, u32 s2)
{
    int t;
    func_021C8810(p + 0x1AE4);
    if (s0 == 0xFFFF) {
        s0 = func_021C264C(p, a, b, (u32)(p + 0x1AE4));
        if (s0 == 0 || s0 == 0xFFFF)
            return 0;
    } else {
        func_021C26A8(p, s0, a, b, (u32)(p + 0x1AE4));
    }
    func_021C26FC(p, a, b, s0, &s1);
    t = func_021C8828(p + 0x1AE4) ? 0 : 1;
    if (func_021C2758(p, b, a, s0, s1, s2, t) != 0) {
        if (t == 0) {
            func_021C99A0(p, (const struct Msg *)(p + 0x1AE4));
            func_021C8810(p + 0x1AE4);
        }
        return 1;
    }
    return 0;
}






int func_021C264C(u8 *p, u8 *a, u8 *b, u32 c)
{
    int r;
    func_021D74F8(7681);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x3f, c);
    func_021D75A8(0x1d, 0);
    func_021D70F0(p, 0x60);
    r = func_021D775C(0x1d);
    func_021D7540(7688);
    return r;
}






void func_021C26A8(u8 *p, u32 a, u8 *b, u8 *c, u32 d)
{
    func_021D74F8(7704);
    func_021D75EC(3, func_021D5440(b));
    func_021D75EC(4, func_021D5440(c));
    func_021D75EC(0x3f, d);
    func_021D75EC(0x1d, a);
    func_021D70F0(p, 0x61);
    func_021D7540(7710);
}






void func_021C26FC(u8 *p, u8 *a, u8 *b, u32 c, Word *d)
{
    func_021D74F8(7726);
    func_021D75EC(3, func_021D5440(a));
    func_021D75EC(4, func_021D5440(b));
    func_021D75EC(0x1d, c);
    func_021D75A8(0x1e, d->v);
    func_021D70F0(p, 0x62);
    d->v = func_021D775C(0x1e);
    func_021D7540(7726 + 7);
}




int func_021C2758(u8 *p, u8 *x, u8 *y, int z, Word a, u32 b, u32 c)
{
    if (func_021C27A0(p, x, y, z, a, 0, b) == 0) {
        func_021C2910(p, x, y, z, a, c, 0, 0);
        return 1;
    }
    return 0;
}



/*
 * The fifth parameter is a one-word struct passed by value and handed on
 * to func_021C282C by value (`add r3, sp, #0x20; ldr r3, [r3]`, the
 * push-r0-r3 struct idiom); a plain u32 folds to `ldr r3, [sp, #0x20]`.
 * The caller func_021C2758 passes it as a plain u32 word. Declaring s
 * before t puts s in [sp, #8].
 */
int func_021C27A0(u8 *p, u8 *x, u8 *y, int z, Word a, u8 b, u32 c)
{
    int r;
    u32 s;
    int t;
    r = func_021C282C(p, (struct Unk021D62A8 *)x, z, a, b);
    if (r != 0) {
        if (c != 0)
            func_021C5C74(p, x, r, z);
        return 1;
    }
    s = func_021CC8D8(p + 0x1D74, 7779);
    t = func_021C2B3C(p, y, x, z);
    if (t != 0 && c != 0) {
        func_021C2BA4(p, x, y, z);
        p[0x78A] |= 0x10;
    }
    func_021CC95C((u32 *)(p + 0x1D74), s, 7792);
    return t;
}


int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, Word d, u8 e)
{
    u16 t;
    if (func_021D62C4(b, c) && e != 2) return 1;
    if (c < 6 && func_021D62A8(b) && e == 0) return 3;
    if (func_021C2AB0(a) == 1 && c == 3) return 3;
    if (c == 5) {
        t = func_021D57FC(b);
        if (func_021E8D24(t, 8) || func_021E8D24(t, 3)) return 2;
    }
    if (c == 4 && func_021E8D24(func_021D57FC(b), 9)) return 2;
    if (c == 3 && func_021E8D24(func_021D57FC(b), 14)) return 2;
    if (c == 18 && func_021E8D24(func_021D57FC(b), 11)) return 2;
    if (c == 14 && func_021D62A8(b)) return 3;
    if (c == 16 && func_021D59B4((u8 *)b, 16) == 121) return 3;
    return 0;
}


void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, Word value, int f, int g, const struct Msg *m)
{
    u32 lock;
    func_021C5C1C(p, a, kind, value);
    switch (kind) {
    case 5: func_021C5480(p, a, 599); break;
    case 4: func_021C5480(p, a, 600); break;
    case 1: func_021C5480(p, a, 602); break;
    case 3: func_021C5480(p, a, 601); break;
    case 2: func_021C5480(p, a, 598); break;
    case 6: func_021C5480(p, a, 603); break;
    case 7: func_021C5480(p, a, 604); break;
    case 0: break;
    }
    if (f) {
        func_021C2AA0(kind, value, a, (struct Msg *)(p + 0x1ae4));
        func_021C99A0(p, (struct Msg *)(p + 0x1ae4));
        func_021C8810((u8 *)(p + 0x1ae4));
    } else if (m) func_021C99A0(p, m);
    if (kind == 3 && func_021D5444((struct QF *)a) == 492 && func_021D59B4(a, 19) == 1) {
        func_021D8510(a);
        func_021D66D8(a, 0);
        func_021CD4B0(((struct Obj00003 *)p)->fC, 79, func_021D5440(a), 0);
        func_021D8484(a);
        func_021C5D88(p, a, 222);
    }
    lock = func_021CC8D8(p + 0x1d74, 7936);
    if (func_021D7D6C(kind)) {
        func_021C2BF0(p, a, b, kind, value.v);
    } else if (kind == 16) {
        func_021C2CA8(p, (u8 *)((int)a));
        if (func_021D59B4(a, 17) == 127) func_021C3FDC(p, a);
    } else func_021C2C50(p, a, b, kind);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 7951);
    if (!g) func_021C195C(p, a, 3);
}
