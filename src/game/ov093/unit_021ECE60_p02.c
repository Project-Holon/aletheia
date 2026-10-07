/*
 * file:     unit_021ECE60_p02.c
 * unit:     yes
 * function: func_021ED374, func_021ED384, func_021ED3D4, func_021ED450, func_021ED460, func_021ED494, func_021ED4D0, func_021ED4E4
 * address:  0x021ED374
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
 *   func_021F7A28  0x021F7A28  thumb  ov094
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021F80E4  0x021F80E4  thumb  ov094
 *   func_021F7F04  0x021F7F04  thumb  ov094
 *   func_02031194  0x02031194  arm
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_020311B8  0x020311B8  arm
 *   func_02031290  0x02031290  arm
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021F8118  0x021F8118  thumb  ov094
 *   func_021F80FC  0x021F80FC  thumb  ov094
 *   func_021F8180  0x021F8180  thumb  ov094
 *   func_021ED9EC  0x021ED9EC  thumb  ov093
 *   func_021F87D4  0x021F87D4  thumb  ov094
 */
#include "../../matched/include/Obj03709.h"
#include "../../matched/include/Obj10119.h"
#include "../../matched/include/Obj18521.h"
#include "../../matched/include/Obj13567.h"

struct TcblNode;
struct Work;
struct Q;
struct S02030FB4;
struct E;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct T { char *e; u16 st; u16 pad; u8 *cnt; };

struct Q { u8 *a; u16 state; u8 *cnt; };

extern void func_021F7A28(int a, u32 b);
extern int func_021F7EB4(void);
extern void func_021F80E4(u32 a);
extern void func_021F7F04(int a);
extern void func_02031194(struct TcblNode *n);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void *func_021D5864(struct Work *p);
extern void func_021F7EE8(void *m, int key);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_021EDA04(struct E *e);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern void func_021F8118(u32 a, u32 b);
extern void func_021F80FC(u32 a, u32 b);
extern int func_021F8180(void);
extern void func_021ED9EC(struct E *e);
extern void func_021F87D4(u32 v);
u32 func_021ED374(u8 *p);
void func_021ED384(u32 a, u8 *t);
void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag);
/* 021ED450 adds r0,#0x41; ldrb; cmp #0; bne ->0 else 1 */ int func_021ED450(u8 *p);
void func_021ED460(void *task, struct Q *q);
void func_021ED494(u8 *p, u8 k, int x);
int func_021ED4D0(void);
void func_021ED4E4(u8 *p, int a, int b);


u32 func_021ED374(u8 *p) { if (p[0x42] == 0) return 1; return 0; }


void func_021ED384(u32 a, u8 *t)
{
    switch (((struct Obj03709 *)t)->f4) {
    case 0:
        func_021F7A28(((struct Obj03709 *)t)->f6, ((struct Obj03709 *)t)->f8);
        (((struct Obj03709 *)t)->f4)++;
        break;
    case 1:
        if (func_021F7EB4() == 0) {
            func_021F80E4(((struct Obj03709 *)t)->f6);
            func_021F7F04(((struct Obj03709 *)t)->f6);
            (((struct Obj03709 *)t)->f4)++;
        }
        break;
    case 2:
        (**(u8 * *)&((struct Obj03709 *)t)->fC)--;
        func_02031194((struct TcblNode *)a);
        break;
    }
}


/*
 * Lever: the record from func_02031290 is a struct pointer, not u8 *: the
 * cnt field is then forwarded across the st store instead of being reloaded
 * (u8 * base plus a local kept in r1 gave 84 bytes out).
 */
void func_021ED3D4(char *p, u8 k, int a, u8 b, int flag)
{
    struct T *t;
    u8 *m;
    u8 y;

    t = (struct T *)func_02031290(func_020311B8(((struct Obj10119 *)p)->f2C, (void *)func_021ED460, 0xc, 1));
    t->e = p + 0x48 + k * 0xc;
    t->cnt = (u8 *)p + 0x41;
    t->st = 0;
    (*t->cnt)++;
    m = func_021B9920(((struct Obj10119 *)p)->f138, a, b);
    y = func_021B8E70(*(u8 * *)&((struct Obj10119 *)p)->f134, k);
    func_021F7EE8(func_021D5864((struct Work *)m), y);
    if (flag == 0)
        func_021F7A28(y, 0x26d);
}


/* 021ED450  adds r0,#0x41; ldrb; cmp #0; bne ->0 else 1 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: adds r0, #0x41; ldrb r0, [r0]; cmp r0, #0; bne loc_021ED45C; movs r0, #1; bx lr; movs r0, #0; bx lr.
 */
int func_021ED450(u8 *p) { return ((struct Obj18521 *)p)->f41 == 0; }

void func_021ED460(void *task, struct Q *q)
{
    switch (q->state) {
    case 0:
        if (func_021F7EB4() == 0) {
            func_021EDA04((struct E *)q->a);
            q->state = q->state + 1;
        }
        break;
    case 1:
        (*q->cnt)--;
        func_02031194(task);
        break;
    }
}

void func_021ED494(u8 *p, u8 k, int x)
{
    int d = func_021D59B4(func_021B98AC(*(char *const * *)&((struct Obj13567 *)p)->f138, k), 0xd);
    u8 r = func_021B8E70(*(u8 * *)&((struct Obj13567 *)p)->f134, k);
    if (x != 0)
        func_021F8118(r, d);
    else
        func_021F80FC(r, d);
}

int func_021ED4D0(void)
{
    if (func_021F8180() == 0)
        return 1;
    return 0;
}

void func_021ED4E4(u8 *p, int a, int b)
{
    func_021ED9EC((struct E *)(p + 0x48 + a * 12));
    func_021ED9EC((struct E *)(p + 0x48 + b * 12));
    func_021F87D4(1);
}
