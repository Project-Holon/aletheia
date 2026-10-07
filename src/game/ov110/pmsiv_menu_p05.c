/*
 * file:     pmsiv_menu_p05.c
 * unit:     yes
 * function: func_021BC6E0, func_021BC6EC, func_021BC6F8, func_021BC704, func_021BC724, func_021BC728, func_021BC72C
 * address:  0x021BC6E0
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC69C  0x021BC69C  thumb  ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BC578 0x021BC578 thumb ov110
 *   func_0204B404 0x0204B404 arm
 */
#include "../../matched/include/Obj01393.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021BC6EC;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

typedef short s16_021BC6F8;

typedef signed short s16_021BC704;

typedef short s16_021BC724;

typedef short s16_021BC728;

typedef signed short s16_021BC72C;

struct Pt { s16_021BC72C a, b, x, y; };

extern void func_021BC69C(u8 *p, int flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021BC578(const s16_021BC72C *a, s16_021BC72C *b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
u16 func_021BC6E0(u8 *p, int i);
void func_021BC6EC(void *p);
void func_021BC6F8(void *p);
void func_021BC704(u8 *p, u32 flag);
void func_021BC724(u8 *a0);
void func_021BC728(u8 *a0);
void func_021BC72C(char *p, int i);


/*
 * Halfword accessor: p + i*2 + 0x40.
 */
u16 func_021BC6E0(u8 *p, int i)
{
    return *(u16 *)(p + i * 2 + 0x40);
}

void func_021BC6EC(void *p) { func_021BC69C(p, 0); }

void func_021BC6F8(void *p) { func_021BC69C(p, 1); }

void func_021BC704(u8 *p, u32 flag)
{
    func_0204B3DC(((struct Obj01393 *)p)->f14, flag);
    func_0204B3DC(((struct Obj01393 *)p)->f18, flag);
    func_021BC69C(p, 1);
}


void func_021BC724(u8 *a0) { }


void func_021BC728(u8 *a0) { }

void func_021BC72C(char *p, int i)
{
    struct Pt t;
    if (*(u32 *)(p + 0x44) != 0) {
        func_021BC578((const s16_021BC72C *)(p + 0x38 + i * 4), (s16_021BC72C *)(&t));
        t.x = t.a;
        t.y = t.b;
    } else {
        t.x = 0x80;
        t.y = 0x18;
    }
    func_0204B404(*(void **)(p + 0x14), (const struct Vec2 *)(&t.x), 0);
    t.y += 0xC0;
    func_0204B404(*(void **)(p + 0x18), (const struct Vec2 *)(&t.x), 1);
    func_021BC69C((u8 *)p, 1);
}
