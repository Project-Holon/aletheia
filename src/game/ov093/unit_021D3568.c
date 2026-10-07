/*
 * file:     unit_021D3568.c
 * unit:     yes
 * function: func_021D3568, func_021D35C8, func_021D3630, func_021D3688, func_021D36CC, func_021D36EC, func_021D370C, func_021D3734, func_021D375C, func_021D377C, func_021D3794, func_021D37B8, func_021D37DC, func_021D37FC, func_021D381C, func_021D3894, func_021D38AC, func_021D38C4, func_021D38E0, func_021D3900, func_021D3918, func_021D3934, func_021D3988, func_021D39A8
 * address:  0x021D3568
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
 *   func_021B8E70  0x021B8E70  thumb  ov093
 *   func_021EA3E8  0x021EA3E8  thumb  ov093
 *   func_021EA3F8  0x021EA3F8  thumb  ov093
 *   func_021B8D8C  0x021B8D8C  thumb  ov093
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D66D8  0x021D66D8  thumb  ov093
 *   func_021EA888  0x021EA888  thumb  ov093
 *   func_021EA8A4  0x021EA8A4  thumb  ov093
 *   func_021EA768  0x021EA768  thumb  ov093
 *   func_021EA778  0x021EA778  thumb  ov093
 *   func_021EA788  0x021EA788  thumb  ov093
 *   func_021EA798  0x021EA798  thumb  ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 *   func_021D5FA4 0x021D5FA4 thumb ov093
 *   func_021D5608 0x021D5608 thumb ov093
 *   func_021D5640 0x021D5640 thumb ov093
 *   func_021D56CC 0x021D56CC thumb ov093
 *   func_021D5FB8   0x021D5FB8  thumb
 *   func_021D5674 0x021D5674 thumb ov093
 *   func_021D56A0 0x021D56A0 thumb ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 *   func_021D5E38 0x021D5E38 thumb ov093
 *   func_021D5EA8  0x021D5EA8  thumb  ov093
 *   func_021D5EFC   0x021D5EFC  thumb
 *   func_021D5F08   0x021D5F08  thumb
 *   func_021D5F38 0x021D5F38 thumb ov093
 *   func_021D6034 0x021D6034 thumb ov093
 *   func_021D61F0   0x021D61F0  thumb
 *   func_021D6238 0x021D6238 thumb ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9C10  0x021B9C10  thumb  ov093
 *   func_021B9BF0  0x021B9BF0  thumb  ov093
 *   func_021D63EC  0x021D63EC  thumb  ov093
 *   func_021D6580  0x021D6580  thumb  ov093
 *   func_021D66B0 0x021D66B0 thumb ov093
 *   func_021D8090  0x021D8090  thumb  ov093
 *   func_021D3A10  0x021D3A10  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021D6064  0x021D6064  thumb  ov093
 */
#include "../../matched/include/Obj21166.h"
#include "../../matched/include/Obj18381.h"
#include "../../matched/include/Obj18383.h"
#include "../../matched/include/Obj18385.h"
#include "../../matched/include/Obj18387.h"
#include "../../matched/include/Obj07795.h"
#include "../../matched/include/Obj21181.h"

struct Unk021D5FA4;
struct UtilWork;
struct Work;
struct S;
struct UtilSlots;
struct S2;
union Slot;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { int x; } S;

extern u32 func_021CD9E0(u8 *p);
extern u8 func_021B8E70(u8 *p, u32 k);
extern void func_021EA3E8(void *ctx, int a, int b, u32 c);
extern int func_021EA3F8(int a);
extern int func_021B8D8C(void *p, void *a, u32 b);
extern u8 *func_021B9934(char *p, int i);
extern void func_021D66D8(u8 *m, u8 v);
extern void func_021EA888(char *ctx, int a);
extern int func_021EA8A4(u32 *p);
extern void func_021EA768(u32 *p, u32 a2, u32 a3);
extern int func_021EA778(u32 *p, u32 a2);
extern void func_021EA788(u32 *p, u32 a2);
extern int func_021EA798(u32 *p, u32 a2);
extern void func_021D5F90(u8 *, u16);
extern void func_021D5FA4(struct Unk021D5FA4 *, u16);
extern void func_021D5608(struct UtilWork *, u8, u8);
extern void func_021D5640(struct Work *p, u32 i, u32 n);
extern void func_021D56CC(struct Work *, u8);
extern void func_021D5FB8(u8 *p);
extern u16 func_021D5674(u8 *p, u32 i, u8 n);
extern u16 func_021D56A0(u8 *p, u32 i, u8 n);
extern u8 func_021D5DC0(s8 *, int, u8);
extern u8 func_021D5E38(s8 *, int, u8);
extern void func_021D5EA8(u8 *p, int i, u8 n);
extern int func_021D5EFC(char *p);
extern void func_021D5F08(char *p);
extern int func_021D5F38(struct S *, int);
extern void func_021D6034(u8 *, int, S);
extern void func_021D61F0(struct UtilSlots *p);
extern void func_021D6238(struct UtilSlots *, int);
extern char *func_021B9AEC(char *p, int i);
extern void func_021B9C10(u32 *p, int a, int b);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern void func_021D63EC(u8 *p, u16 n);
extern void func_021D6580(void *p);
extern void func_021D66B0(u8 *p, int n);
extern void func_021D8090(u32 v, u8 *out);
extern u32 func_021D3A10(u32 i);
extern int func_021D5B68(void *p);
extern int func_021D6064(u8 *p, u32 k, union Slot *out, int *changed);
int func_021D3568(u32 *a, int *b, u32 *c);
int func_021D35C8(u32 *a, int *b, u32 *c);
int func_021D3630(u32 *a, int *b, u32 *c);
int func_021D3688(u32 *a, int *b, u32 *c);
int func_021D36CC(char *p, int *state, unsigned int *q);
int func_021D36EC(u32 *a, int b, u32 *c);
int func_021D370C(u32 *a, int b, u32 *c);
int func_021D3734(u32 *a, int b, u32 *c);
int func_021D375C(u32 *a, int b, u32 *c);
int func_021D377C(u8 *p, int b, u32 *q);
int func_021D3794(u32 *a, int b, u32 *c);
int func_021D37B8(u32 *a, int b, u32 *c);
int func_021D37DC(u32 *a, int b, u32 *c);
int func_021D37FC(u32 *a, int b, u32 *c);
int func_021D381C(u32 *a, int b, u32 *c);
int func_021D3894(u8 *p, int b, u32 *q);
int func_021D38AC(u8 *p, int b, u32 *q);
int func_021D38C4(u32 *a, int b, u32 *c);
int func_021D38E0(u32 *a, int b, u32 *c);
int func_021D3900(u8 *p, int b, u32 *q);
int func_021D3918(u32 *a, int b, u32 *c);
int func_021D3934(char *a, int b, u32 *s);
int func_021D3988(u32 *a, int b, u32 *c);
int func_021D39A8(u8 *a, int b, u32 *s);


int func_021D3568(u32 *a, int *b, u32 *c)
{
    int x;
    int y;

    if (*b == 0) {
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        x = func_021B8E70((u8 *)a[0], (u8)c[0]);
        y = func_021B8E70((u8 *)a[0], (u8)c[1]);
        func_021EA3E8((void *)a[0x15], x, y, (u16)c[2]);
        (*b)++;
    } else {
        if (func_021EA3F8(a[0x15]) != 0) {
            return 1;
        }
    }
    return 0;
}


int func_021D35C8(u32 *a, int *b, u32 *c)
{
    int x;

    switch (*b) {
    case 0:
        x = func_021B8E70((u8 *)a[0], func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]));
        func_021D66D8(func_021B9934((char *)a[1], (u8)c[0]), (u8)c[1]);
        func_021EA888((char *)a[0x15], x);
        (*b)++;
        break;
    case 1:
        if (func_021EA8A4((u32 *)a[0x15]) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


int func_021D3630(u32 *a, int *b, u32 *c)
{
    int s;

    s = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
    switch (*b) {
    case 0:
        if (func_021CD9E0((u8 *)a) != 0) {
            return 1;
        }
        func_021EA768((u32 *)a[0x15], s, 1);
        (*b)++;
        break;
    case 1:
        if (func_021EA778((u32 *)a[0x15], s) != 0) {
            (*b)++;
        }
        break;
    default:
        return 1;
    }
    return 0;
}


int func_021D3688(u32 *a, int *b, u32 *c)
{
    int s;

    s = func_021B8D8C((void *)a[0], (void *)a[1], (u8)c[0]);
    switch (*b) {
    case 0:
        func_021EA788((u32 *)a[0x15], s);
        (*b)++;
        break;
    case 1:
        if (func_021EA798((u32 *)a[0x15], s) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * extent: compiled 30 bytes followed by two zero alignment bytes.
 */
int func_021D36CC(char *p, int *state, unsigned int *q)
{
    func_021D5F90(func_021B9934(*(char * *)&((struct Obj21166 *)p)->f4, (u8)q[0]), q[1]);
    return 1;
}

int func_021D36EC(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5FA4((struct Unk021D5FA4 *)m, c[1]);
    return 1;
}

int func_021D370C(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k, n;
    k = c[1];
    n = c[2];
    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5608((struct UtilWork *)m, k, n);
    return 1;
}

int func_021D3734(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k, n;
    k = c[1];
    n = c[2];
    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5640((struct Work *)m, k, n);
    return 1;
}

int func_021D375C(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k;
    k = c[1];
    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D56CC((struct Work *)m, k);
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D5FB8; movs r0, #1; pop {r3, pc}.
 */
int func_021D377C(u8 *p, int b, u32 *q)
{
    func_021D5FB8(func_021B9934(*(char * *)&((struct Obj18381 *)p)->f4, (u8)*q));
    return 1;
}

int func_021D3794(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5674(m, (u8)c[1], c[2]);
    return 1;
}

int func_021D37B8(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D56A0(m, (u8)c[1], c[2]);
    return 1;
}

int func_021D37DC(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5DC0((s8 *)m, c[1], c[2]);
    return 1;
}

int func_021D37FC(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5E38((s8 *)m, c[1], c[2]);
    return 1;
}


int func_021D381C(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5EA8(m, 1, c[1]);
    func_021D5EA8(m, 2, c[2]);
    func_021D5EA8(m, 3, c[3]);
    func_021D5EA8(m, 4, c[4]);
    func_021D5EA8(m, 5, c[5]);
    func_021D5EA8(m, 6, c[6]);
    func_021D5EA8(m, 7, c[7]);
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D5EFC; movs r0, #1; pop {r3, pc}.
 */
int func_021D3894(u8 *p, int b, u32 *q)
{
    func_021D5EFC((char *)func_021B9934(*(char * *)&((struct Obj18383 *)p)->f4, (u8)*q));
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D5F08; movs r0, #1; pop {r3, pc}.
 */
int func_021D38AC(u8 *p, int b, u32 *q)
{
    func_021D5F08((char *)func_021B9934(*(char * *)&((struct Obj18385 *)p)->f4, (u8)*q));
    return 1;
}

int func_021D38C4(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5F38((struct S *)m, c[1]);
    return 1;
}

/*
 * lever: A declared one-word S local assigned from c[2] preserves all 32
 * bits and emits the otherwise unused frame word. A cast S lvalue at
 * c+2 compiled 30 bytes with the wrong frame and redundant address add.
 */
int func_021D38E0(u32 *a, int b, u32 *c)
{
    u8 *m;
    S s;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    s.x = c[2];
    func_021D6034(m, c[1], s);
    return 1;
}


/*
 * Leaf with no calls and no pool; 9 instructions, 22 bytes: push {r3, lr}; ldr r1, [r2]; ldr r0, [r0, #4]; lsls r1, r1, #0x18; lsrs r1, r1, #0x18; bl func_021B9934; bl func_021D61F0; movs r0, #1; pop {r3, pc}.
 */
int func_021D3900(u8 *p, int b, u32 *q)
{
    func_021D61F0((struct UtilSlots *)func_021B9934(*(char * *)&((struct Obj18387 *)p)->f4, (u8)*q));
    return 1;
}

int func_021D3918(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6238((struct UtilSlots *)m, c[1]);
    return 1;
}


int func_021D3934(char *a, int b, u32 *s)
{
    u8 x;
    u8 y;
    char *l;
    void *e;

    x = ((struct Obj07795 *)a)->f13C;
    y = ((struct Obj07795 *)a)->f140;
    l = func_021B9AEC(*(char * *)&((struct Obj07795 *)a)->f4, (u8)(((struct Obj07795 *)a)->f138));
    if (x != y)
        func_021B9C10((u32 *)l, x, y);
    e = (void *)func_021B9BF0((struct S2 *)l, x);
    func_021D63EC(e, s[3]);
    func_021D6580(e);
    return 1;
}

int func_021D3988(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D66B0(m, (u16)c[1]);
    return 1;
}


int func_021D39A8(u8 *a, int b, u32 *s)
{
    u8 buf[6];
    u32 i;
    u32 n;
    u32 m;
    u32 j;
    u32 t;
    u8 *q;

    n = s[1];
    m = s[0];
    func_021D8090(s[2], buf);
    for (i = 0; i < n; i++) {
        t = func_021D3A10(i);
        if (t == 0)
            break;
        for (j = 0; j < m; j++) {
            q = func_021B9934((char *)(*(u8 * *)&((struct Obj21181 *)a)->f4), buf[j]);
            if (func_021D5B68(q) == 0)
                func_021D6064(q, t, 0, 0);
        }
    }
    return 1;
}
