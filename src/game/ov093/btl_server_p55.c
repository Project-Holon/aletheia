/*
 * file:     btl_server_p55.c
 * unit:     yes
 * function: func_021C282C, func_021C2910
 * address:  0x021C282C
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
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D62A8 0x021D62A8 thumb ov093
 *   func_021C2AB0 0x021C2AB0 thumb ov093
 *   func_021D57FC 0x021D57FC thumb ov093
 *   func_021E8D24 0x021E8D24 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021C5480 0x021C5480 thumb ov093
 *   func_021C2AA0 0x021C2AA0 thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021C8810 0x021C8810 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021D8510 0x021D8510 thumb ov093
 *   func_021D66D8 0x021D66D8 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021D8484 0x021D8484 thumb ov093
 *   func_021C5D88 0x021C5D88 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   func_021C2BF0 0x021C2BF0 thumb ov093
 *   func_021C2CA8 0x021C2CA8 thumb ov093
 *   func_021C3FDC 0x021C3FDC thumb ov093
 *   func_021C2C50 0x021C2C50 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 */
#include "../../matched/include/Obj00003.h"

struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Slot { u32 a : 3; u32 rest : 29; };

struct Unk021D62A8 { u8 pad[0x1c]; struct Slot e[6]; };

typedef struct { int x; } S;

struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

extern int func_021D62C4(struct Unk021D62A8 *, int);
extern int func_021D62A8(struct Unk021D62A8 *);
extern int func_021C2AB0(u8 *);
extern u16 func_021D57FC(void *);
extern int func_021E8D24(int x, int k);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C5C1C(u8 *, u8 *, int, S);
extern void func_021C5480(u8 *, u8 *, int);
extern void func_021C2AA0(int, S, u8 *, struct Msg *);
extern int func_021C99A0(void *, const struct Msg *);
extern void func_021C8810(u8 *p);
extern u16 func_021D5444(struct QF *p);
extern void func_021D8510(void *p);
extern void func_021D66D8(void *, u8);
extern u8 func_021D5440(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void *func_021D8484(void *a);
extern void func_021C5D88(u8 *, u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern int func_021D7D6C(int);
extern void func_021C2BF0(u8 *, u8 *, u8 *, u32, u32);
extern void func_021C2CA8(u8 *p, u8 *a);
extern void func_021C3FDC(u8 *, u8 *);
extern void func_021C2C50(u8 *, u8 *, u8 *, u32);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, int d, u8 e);
void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, S value, int f, int g, const struct Msg *m);

int func_021C282C(u8 *a, struct Unk021D62A8 *b, int c, int d, u8 e)
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

void func_021C2910(u8 *p, u8 *a, u8 *b, int kind, S value, int f, int g, const struct Msg *m)
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
        func_021C2BF0(p, a, b, kind, value.x);
    } else if (kind == 16) {
        func_021C2CA8(p, (u8 *)((int)a));
        if (func_021D59B4(a, 17) == 127) func_021C3FDC(p, a);
    } else func_021C2C50(p, a, b, kind);
    func_021CC95C((u32 *)(p + 0x1d74), lock, 7951);
    if (!g) func_021C195C(p, a, 3);
}
