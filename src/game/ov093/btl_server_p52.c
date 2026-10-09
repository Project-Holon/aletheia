/*
 * file:     btl_server_p52.c
 * unit:     yes
 * function: func_021C3810, func_021C39CC, func_021C39F4, func_021C3A4C
 * address:  0x021C3810
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
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021BDD7C 0x021BDD7C thumb ov093
 *   func_021C99A0 0x021C99A0 thumb ov093
 *   func_021BD9D4 0x021BD9D4 thumb ov093
 *   func_021CD64C 0x021CD64C thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021D8244 0x021D8244 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B99C0  0x021B99C0  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D7630  0x021D7630  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021C3A98  0x021C3A98  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13329.h"
#include "../../matched/include/Obj09971.h"
#include "../../matched/include/Obj21091.h"

struct B;
struct Unk021D62A8;
struct Q1;
struct S;
struct S2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

enum Mode { M0, M1, M2, Mneg = -1 };

struct Pair { u8 count, id; };

struct Msg { u16 a; u16 kind:8; u16 n:7; u16 flag:1; u8 data[0x1c]; u32 w20; };

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern int func_021D5B68(void *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D69AC(u8 *, int);
extern u32 func_021CC8D8(void *, int);
extern int func_021C88E4(u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021B8E28(u8 *, int, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *p, unsigned int i);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021BDD7C(u8 *, u8 *, u32);
extern int func_021C99A0(void *, const struct Msg *);
extern void func_021BD9D4(u8 *p, u8 i, u8 a, u8 b, int c);
extern void func_021CD64C(void *, u8, ...);
extern int func_021BDA00(u8 *);
extern u8 func_021B8DDC(u32 x);
extern int func_021D59B4(u8 *p, int k);
extern void func_021D8244(struct B *p, int n);
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***);
extern u8 func_021B9B94(struct Q1 *p);
extern int func_021B99C0(struct S **p, u32 b);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D5B7C(void *m);
extern u32 func_021D78AC(u32 range);
extern void func_021D74F8(int line);
extern void func_021D75EC(int key, u32 val);
extern void func_021D7630(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern void func_021C3A98(u8 *p, u8 *a);
int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg);
BOOL func_021C39CC(u8 *p);
int func_021C39F4(u8 *a, u8 *b);
int func_021C3A4C(u8 *p, int unused, u8 *a);

static inline u8 rule(u8 n)
{
    if (n != 0) {
        n--;
        if (n < 24) return n;
    }
    return 31;
}

/*
 * lever: func_021B8E28 receives the full position int; its own u8 signature adds an absent truncation.
 */
int func_021C3810(u8 *p, u8 *a, u8 *b, int force, int *out, u16 move, int ignore, const struct Msg *msg)
{
    enum Mode mode;
    int position;
    u32 lock;
    u8 blocked;
    struct Pair pair;
    *out = 0;
    if (force) mode = M1;
    else mode = func_021C39CC(p);
    if (mode == M2) return 0;
    position = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(b));
    if (position == 6) return 0;
    if (func_021D5B68(b)) return 0;
    if (func_021D62C4((struct Unk021D62A8 *)b, 33)) return 0;
    if (rule(func_021D69AC(b, 4)) != 31) return 0;
    lock = func_021CC8D8(p + 0x1d74, 8732);
    blocked = func_021C3A4C(p, (int)a, b);
    if (blocked && func_021C88E4(p)) *out = 1;
    func_021CC95C((u32 *)(p + 0x1d74), lock, 8740);
    if (blocked) return 0;
    func_021B8E28(*(u8 * *)&((struct Obj00003 *)p)->f4, position, &pair.id, &pair.count);
    if (mode == M1) {
        u8 id;
        mode = func_021C39F4(p, func_021BB85C(*(u8 * *)&((struct Obj00003 *)p)->f0, pair.id));
        if (mode >= 0) {
            id = func_021D5440((u8 *)func_021B990C((char *)(*(u32 *)&((struct Obj00003 *)p)->f8), pair.id, (u8)mode));
            func_021BDD7C(p, b, move);
            if (msg) func_021C99A0(p, msg);
            func_021BD9D4(p, pair.id, pair.count, (u8)mode, 0);
            func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 845, id, 0xffff0000);
            func_021BDA00(p);
        } else return 0;
    } else {
        int slot;
        slot = func_021B8DDC(func_021D5440(a));
        if (!ignore) {
            u8 speed;
            speed = (u8)func_021D59B4(a, 15);
            if ((u8)func_021D59B4(b, 15) > speed) return 0;
        }
        func_021D8244((struct B *)(p + 0x4b8), slot);
        func_021BDD7C(p, b, move);
        *(u32 *)&((struct Obj00003 *)p)->f14 = 5;
    }
    return 1;
}

BOOL func_021C39CC(u8 *p)
{
    u32 a;
    void *b;
    a = func_021B8588(((struct Obj13329 *)p)->f4);
    b = func_021B86B8(*(void *** *)&((struct Obj13329 *)p)->f4);
    if (a == 0) {
        if (b == 0) {
            return FALSE;
        } else {
            return TRUE;
        }
    }
    return TRUE;
}


int func_021C39F4(u8 *a, u8 *b)
{
    u8 buf[8];
    u32 n;
    u32 i;
    int c;

    n = func_021B9B94(((struct Obj09971 *)b)->f4);
    i = func_021B99C0(((struct Obj21091 *)a)->f4, b[0xb]);
    c = 0;
    for (; i < n; i++) {
        if (func_021D5B7C(func_021B9C00(((struct Obj09971 *)b)->f4, (u8)i))) {
            buf[c] = i;
            c++;
        }
    }
    if (c != 0) {
        return buf[func_021D78AC(c)];
    }
    return -1;
}


int func_021C3A4C(u8 *p, int unused, u8 *a)
{
    int r;
    func_021D74F8(8877);
    func_021D7630(0x41, 0);
    func_021D75EC(4, func_021D5440(a));
    func_021D70F0(p, 0x8b);
    func_021C3A98(p, a);
    r = func_021D775C(0x41);
    func_021D7540(8883);
    return r;
}
