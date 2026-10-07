/*
 * file:     btl_server_p09.c
 * unit:     yes
 * function: func_021BA020, func_021BA02C, func_021BA064, func_021BA080, func_021BA08C, func_021BA094, func_021BA0CC, func_021BA128, func_021BA178, func_021BA1A8, func_021BA1B4, func_021BA1CC, func_021BA1E4, func_021BA1EC, func_021BA20C
 * address:  0x021BA020
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
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B9F70 0x021B9F70 thumb ov093
 *   func_0202E7DC  0x0202E7DC  thumb
 *   func_0201A920 0x0201A920 thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0201A948  0x0201A948  thumb
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02013158  0x02013158  thumb
 *   sub_02008DF0 0x02008DF0 thumb
 *   sub_02008DAC 0x02008DAC thumb
 *   func_021B6818 0x021B6818 thumb ov093
 */
#include "../../matched/include/Obj20998.h"
#include "../../matched/include/Obj20999.h"
#include "../../matched/include/Obj21000.h"
#include "../../matched/include/Obj21001.h"
#include "../../matched/include/Obj21002.h"
#include "../../matched/include/Obj21004.h"

struct Party;
struct Rec534;
struct Sub02008C20Obj;
typedef unsigned char  u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021BA08C  movs r1,#0xaf; lsls r1,#2; ldr r0,[r0,r1] */
struct Q2 { u8 pad[0x2bc]; u32 v; };

struct S { char pad[0x298]; void *a[4]; void *b[4]; void *c; };

typedef enum { FALSE = 0, TRUE = 1 } BOOL;

extern void *func_021B86B8(void ***);
extern int func_021B9F70(u8 *p, int i);
char *func_0202E7DC(char *p);
extern struct Party *func_0201A920(u32);
extern u32 func_020307B0(void *p);
extern void func_0201A948(struct Party *p);
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
int func_02013158(char *base, int m);
extern u32 sub_02008DF0(struct Sub02008C20Obj *, int);
extern u32 sub_02008DAC(struct Sub02008C20Obj *, int, u32);
extern unsigned int func_021B6818(unsigned int *p);
unsigned short func_021BA020(char *p, int i);
void *func_021BA02C(char *p, int i, int mode);
int func_021BA064(char *p, int i);
void func_021BA080(char **p);
u32 func_021BA08C(struct Q2 *p);
void func_021BA094(struct S *p);
void func_021BA0CC(struct S *p);
void func_021BA128(struct S *p, int i, void *x);
void *func_021BA178(void *p, int i, int mode);
int func_021BA1A8(char **p, int m);
void func_021BA1B4(char **p, int i);
void func_021BA1CC(char **p, int i, u32 delta);
char *func_021BA1E4(char **p);
BOOL func_021BA1EC(char **p);
int func_021BA20C(char **p);

unsigned short func_021BA020(char *p, int i)
{
    return *(unsigned short *)(p + i * 0x28 + 0x28);
}

void *func_021BA02C(char *p, int i, int mode)
{
    if ((int)func_021B86B8((void ***)p) == 2 && func_021B9F70((u8 *)p, i)) {
        if (mode == 1) return (void *)(((u32)p + 0x40) + (u32)i * 0x28);
        return (void *)(((u32)p + 0x38) + (u32)i * 0x28);
    }
    return 0;
}

int func_021BA064(char *p, int i)
{
    if (func_021B9F70((u8 *)p, i)) return 0;
    return *(int *)((u32)p + (u32)i * 0x28 + 0x20);
}


/*
 * branch, so the pool relocation cannot be witnessed.  All bytes correct.
 */
void func_021BA080(char **p)
{
    func_0202E7DC((char *)(((struct Obj20998 *)(*p))->f70));
}

/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: movs r1, #0xaf; lsls r1, r1, #2; ldr r0, [r0, r1]; bx lr.
 */
u32 func_021BA08C(struct Q2 *p) { return p->v; }

void func_021BA094(struct S *p)
{
    unsigned int i;
    for (i = 0; i < 4; i++) {
        p->a[i] = func_0201A920(0x12);
        p->b[i] = func_0201A920(0x12);
    }
    p->c = func_0201A920(0x12);
}


void func_021BA0CC(struct S *p)
{
    unsigned int i;

    for (i = 0; i < 4; i++) {
        if (p->a[i]) {
            func_020307B0(p->a[i]);
            p->a[i] = 0;
        }
        if (p->b[i]) {
            func_020307B0(p->b[i]);
            p->b[i] = 0;
        }
    }
    if (p->c) {
        func_020307B0(p->c);
        p->c = 0;
    }
}


void func_021BA128(struct S *p, int i, void *x)
{
    if (p->a[i]) {
        func_0201A948(p->a[i]);
        func_0201A948(p->b[i]);
        func_0201AC2C(x, p->a[i]);
        func_0201AC2C(x, p->b[i]);
        if (func_0201AA18(p->b[i])) {
            func_0201AB28(p->b[i], 0);
        }
    }
}

void *func_021BA178(void *p, int i, int mode)
{
    if (mode) {
        if (func_0201AA18(*(void **)(((u32)p + 0x2a8) + (u32)i * 4)))
            func_0201AB28(*(void **)(((u32)p + 0x2a8) + (u32)i * 4), 0);
        return *(void **)(((u32)p + 0x2a8) + (u32)i * 4);
    }
    return *(void **)((u32)p + (u32)i * 4 + 0x298);
}


int func_021BA1A8(char **p, int m)
{
    return func_02013158(*p, m);
}

void func_021BA1B4(char **p, int i)
{
    if (((struct Obj20999 *)(*p))->f23 == 0)
        sub_02008DF0(*(struct Sub02008C20Obj * *)&((struct Obj21000 *)(*p))->f6C, i);
}

void func_021BA1CC(char **p, int i, u32 delta)
{
    if (((struct Obj21001 *)(*p))->f23 == 0)
        sub_02008DAC(*(struct Sub02008C20Obj * *)&((struct Obj21002 *)(*p))->f6C, i, delta);
}

char *func_021BA1E4(char **p)
{
    return *p + 0x78;
}

BOOL func_021BA1EC(char **p)
{
    BOOL result = FALSE;
    if (func_021B6818((unsigned int *)((int *)*p)) == 1) {
        if (((struct Obj21004 *)(*p))->f7F) result = TRUE;
    }
    return result;
}

int func_021BA20C(char **p)
{
    int v;
    if (func_021B6818((unsigned int *)((int *)*p)) == 1) return func_021BA1EC(p);
    v = (int)func_021B86B8((void ***)p);
    switch (v) {
    case 0:
    case 1: return 1;
    default: return 0;
    }
}
