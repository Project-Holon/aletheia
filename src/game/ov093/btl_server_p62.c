/*
 * file:     btl_server_p62.c
 * unit:     yes
 * function: func_021C3AA8, func_021C3B68, func_021C3B8C, func_021C3BB8, func_021C3BE0, func_021C3C10, func_021C3C60, func_021C3CCC
 * address:  0x021C3AA8
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
 *   func_0201C184  0x0201C184  thumb
 *   func_021C5718  0x021C5718  thumb  ov093
 *   func_021CC8D8  0x021CC8D8  thumb  ov093
 *   func_021C88E4  0x021C88E4  thumb  ov093
 *   func_021CC95C  0x021CC95C  thumb  ov093
 *   func_021EF884 0x021EF884 thumb ov093
 *   func_021EF894 0x021EF894 thumb ov093
 *   func_021EF8A4 0x021EF8A4 thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 *   func_021C7998 0x021C7998 thumb ov093
 *   func_021D74F8  0x021D74F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D75EC  0x021D75EC  thumb  ov093
 *   func_021D75A8  0x021D75A8  thumb  ov093
 *   func_021D70F0  0x021D70F0  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7540  0x021D7540  thumb  ov093
 *   func_021EF8C8  0x021EF8C8  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EF8F8  0x021EF8F8  thumb  ov093
 */
#include "../../matched/include/Obj13330.h"
#include "../../matched/include/Obj00003.h"
#include "../../matched/include/Obj13331.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 pad[5]; u8 f : 1; } Q;

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

typedef struct { int x; } S;

extern u32 func_0201C184(int id);
extern void func_021C5718(u8 *p, u8 *b, int c);
extern u32 func_021CC8D8(void *lock, int line);
extern int func_021C88E4(u8 *p);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern int func_021EF884(void);
extern int func_021EF894(void);
extern void func_021EF8A4(u32, u32);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021C7998(u8 *, u32);
extern void func_021D74F8(int line);
extern u8 func_021D5440(u8 *p);
extern void func_021D75EC(int key, u32 val);
extern void func_021D75A8(int key, u32 val);
extern void func_021D70F0(void *a, int id);
extern int func_021D775C(int key);
extern void func_021D7540(int line);
extern int func_021EF8C8(int a, S c);
extern int func_021E8A98(S c);
extern void func_021EF8F8(int a, int r);
void func_021C3AA8(u8 *p, u16 *a, u8 *b);
int func_021C3B68(u8 *p, int a, u8 b);
BOOL func_021C3B8C(void *p, u32 a, u32 b);
void func_021C3BB8(u8 *p, u32 a, u32 b);
void func_021C3BE0(u8 *p, u32 a);
u8 func_021C3C10(u8 *p, int k, u8 *a);
int func_021C3C60(u8 *p, int a, S c, int d);
void func_021C3CCC(u8 *p, u8 *b, int c);


void func_021C3AA8(u8 *p, u16 *a, u8 *b)
{
    u8 k = func_0201C184(*a);
    if (k) {
        int x = func_021C3C10(p, k, b);
        if (func_021C3B68(p, k, (u8)(x + 5))) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
            return;
        }
        func_021C5718(p, b, *a);
    } else {
        u32 s;
        int e;
        s = func_021CC8D8(p + 0x1d74, 0x22c8);
        func_021C3CCC(p, b, *a);
        e = (func_021C88E4(p) == 2);
        func_021CC95C((u32 *)(p + 0x1d74), s, 0x22cc);
        if (e) {
            Q *q = *(Q * *)&((struct Obj13330 *)p)->f4A8;
            if (!q->f)
                q->f = 1;
        } else {
            func_021C5718(p, b, *a);
        }
    }
}

int func_021C3B68(u8 *p, int a, u8 b)
{
    if (func_021C3B8C(p, a, b)) {
        func_021C3BB8(p, a, b);
        return 1;
    }
    return 0;
}

BOOL func_021C3B8C(void *p, u32 a, u32 b)
{
    if (a >= 5) return FALSE;
    if (a == func_021EF884() && (b != 255 || func_021EF894() == 255)) {
        return FALSE;
    }
    return TRUE;
}

void func_021C3BB8(u8 *p, u32 a, u32 b)
{
    func_021EF8A4(a, b);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3f, a, b);
    func_021C3BE0(p, a);
}

/*
 * interface: Lock scalar word return preserves the complete r0 payload,
 * as in matched caller 021C3810; restore consumes the same word.
 */
void func_021C3BE0(u8 *p, u32 a)
{
    u32 old;
    int line = 0x2303;
    old = func_021CC8D8(p + 0x1d74, line);
    func_021C7998(p, a);
    func_021CC95C((u32 *)(p + 0x1d74), old, line + 2);
}


u8 func_021C3C10(u8 *p, int k, u8 *a)
{
    u8 r;
    func_021D74F8(8983);
    func_021D75EC(0x39, k);
    func_021D75EC(3, func_021D5440(a));
    func_021D75A8(0x24, 0);
    func_021D70F0(p, 0x7c);
    r = func_021D775C(0x24);
    func_021D7540(8989);
    return r;
}


/*
 * The handed address 0x021C3C62 is the second label after `push {r0-r3}`
 * (0x021C3C60). The third parameter is a one-word struct passed by value
 * (its home slot is read through `add r7, sp, #0x20`).
 */
int func_021C3C60(u8 *p, int a, S c, int d)
{
    int r;
    if (func_021EF8C8(a, c)) {
        func_021CD4B0(((struct Obj13331 *)p)->fC, 0x21, (u8)a, c.x);
        return 1;
    }
    if (d) {
        r = func_021E8A98(c);
        if (r != 0x1f) {
            func_021EF8F8(a, r);
            func_021CD4B0(((struct Obj13331 *)p)->fC, 0x22, (u8)a, r);
            return 1;
        }
    }
    return 0;
}

void func_021C3CCC(u8 *p, u8 *b, int c)
{
    int line = 0x2360;
    func_021D74F8(line);
    func_021D75A8(3, func_021D5440(b));
    func_021D75A8(0x12, c);
    func_021D70F0(p, 0x9e);
    func_021D7540(line + 4);
}
