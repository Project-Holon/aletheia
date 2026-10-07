/*
 * file:     unit_0217AE20_p05.c
 * unit:     yes
 * function: func_0217B6B4, func_0217B75C, func_0217B798, func_0217B80C, func_0217B83C, func_0217B840, func_0217B8E4, func_0217B8F0, func_0217B908, func_0217B974, func_0217B9BC
 * address:  0x0217B6B4
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217AFB0 0x0217AFB0  thumb  ov019
 *   func_0217AED4 0x0217AED4  thumb  ov019
 *   func_0216D3CC 0x0216D3CC  thumb  ov010
 *   func_02188CB4 0x02188CB4  thumb  ov021
 *   func_021A3074 0x021A3074  thumb  ov021
 *   func_0216D5F8 0x0216D5F8  thumb  ov010
 *   func_0216D410 0x0216D410  thumb  ov010
 *   func_0216D480 0x0216D480  thumb  ov010
 *   func_0216D548 0x0216D548  thumb  ov010
 *   func_0216D550 0x0216D550  thumb  ov010
 *   func_021BBA70 0x021BBA70  thumb  ov021
 *   func_02087C6C 0x02087C6C  arm
 *   memcmp        0x0203EFC8  arm
 *   func_021734A8 0x021734A8  thumb  ov012
 *   func_02012138 0x02012138 thumb
 *   func_02026474 0x02026474 thumb
 *   func_0217413C 0x0217413C thumb ov012
 *   d_02180074  0x02180074  data  a4
 *   d_02180078  0x02180078  data  a4
 *   d_0218007C  0x0218007C  data  a4
 */
#include "../../matched/include/Obj07381.h"
#include "../../matched/include/Obj12521.h"

struct Obj00020;
struct Ctx;
struct Src;
typedef unsigned short u16;

struct S {
    char pad[0x58];
    u16 f58;
};

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {
    u8 pad[7];
    unsigned char low : 4;
    unsigned char flag : 1;
    unsigned char high : 3;
} Flags;

typedef int (*fn_t)(char *, unsigned char *, int, unsigned char *);

struct ent { fn_t f; int a; int b; };

extern void *func_0217AFB0(void **a, u8 *b, u8 *c);
extern u16 func_0217AED4(u8 *a, u8 *b);
extern int func_0216D3CC(int);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern void func_0216D410(int, int);
extern int func_0216D480(char *p);
extern u32 *func_0216D548(u32 *p, u32 v);
extern u32 *func_0216D550(u32 *p, u32 v);
extern void func_021BBA70(struct Ctx *ctx, struct Src *src, u16 *v, u8 kind);
extern void func_02087C6C(void *);
extern int memcmp(const void *a, const void *b, int n);
extern void func_021734A8(u8 *self, u32 id, u32 v);
extern unsigned int func_02012138(const struct Ctx *p);
extern u32 func_02026474(void *obj);
extern int func_0217413C(int, int, unsigned char *);
int func_0217B6B4(char *base, int *p, int r2, unsigned char *state);
void func_0217B75C(char *p);
void func_0217B798(char *base, u8 *p);
int func_0217B80C(int a, int b);
int func_0217B83C(void *sys, void *pos);
int func_0217B840(char *base, int r1);
int func_0217B8E4(char *p, int v);
int func_0217B8F0(char *p, char v);
int func_0217B908(int x);
int func_0217B974(int x);
int func_0217B9BC(unsigned int x);
extern struct ent d_02180074[];
extern struct ent d_02180078[];
extern struct ent d_0218007C[];


int func_0217B6B4(char *base, int *p, int r2, unsigned char *state)
{
    struct S *q = (struct S *)(base + 0x2830);
    int h;
    int k;

    h = (int)func_0217AFB0((void **)base, (u8 *)(*p), (u8 *)p);
    switch (*state) {
    case 0:
        if (func_0216D3CC(h) == 1) {
            switch (func_0216D5F8(func_021A3074(func_02188CB4((void *)r2)))) {
            case 0:
                k = 1;
                break;
            case 1:
                k = 0;
                break;
            case 2:
                k = 3;
                break;
            case 3:
            default:
                k = 2;
                break;
            }
            func_0216D410(h, k);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_0216D480((char *)h) == 1) {
            func_0216D548((u32 *)h, 8);
            *state = *state + 1;
        }
        break;
    case 2:
        if (q->f58 != func_0217AED4((u8 *)(*p), (u8 *)p)) {
            func_0216D550((u32 *)h, 8);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * lever: the bit at byte 7, bit 4 is a one-bit unsigned char field;
 * integer masks instead produce asrs/movs/ands and grow the body by 4 bytes.
 */
void func_0217B75C(char *p)
{
    int i;
    u8 *q;
    q = (u8 *)p + 0x2910;
    for (i = 0; i < 10; i++, q += 0x8c) {
        if (((Flags *)q)->flag == 1 && q[0x6a] != 0) {
            func_0217B798(p, q);
            q[0x6a] = 0;
        }
    }
}


void func_0217B798(char *base, u8 *p)
{
    u8 *q = (u8 *)base + 0x2830;
    u8 buf[6];

    func_021BBA70((struct Ctx *)base, (struct Src *)p, 0, 0);
    if (q[1] == 0 && q[0x71] == 0 && p[0xa] == 5 && ((struct Obj07381 *)p)->f6C != 0) {
        func_02087C6C(buf);
        if (memcmp(p, buf, 6) == 0 && func_0217B8F0(base, 6) == 1) {
            func_021734A8((u8 *)base, 2, (u32)p);
            func_021734A8((u8 *)base, 0, (u32)p);
        }
    }
}

/*
 * extent: follower 0217B83C already has its own source and shard.
 */
int func_0217B80C(int a, int b)
{
    char *p;
    char *q;
    int result;
    p = (char *)func_02026474((void *)func_02012138((const struct Ctx *)a));
    result = 0;
    q = p + 0x3548;
    if (((struct Obj12521 *)q)->f4 != 0 && ((struct Obj12521 *)q)->f0 == 0) result = func_0217413C(a, b, (unsigned char *)p);
    return result;
}

/*
 * Unlabelled leaf (a .word after a pool in the ov019 listing): returns 0.
 * Callee of ov021 func_0218A0E4, which passes (sys, pos).
 * Addresses are Black-image addresses.
 */
int func_0217B83C(void *sys, void *pos)
{
    return 0;
}


int func_0217B840(char *base, int r1)
{
    unsigned char *q = (unsigned char *)base + 0x2830;
    int res = 1;
    fn_t fn;

    switch (q[0x72]) {
    case 0:
        fn = d_02180074[q[1]].f;
        break;
    case 1:
        fn = d_02180078[q[1]].f;
        break;
    case 2:
        fn = d_0218007C[q[1]].f;
        break;
    }
    if (fn != 0) {
        res = fn(base, q, r1, q + 0x73);
    }
    if (res == 1) {
        q[0x73] = 0;
        q[0x72] = q[0x72] + 1;
        if (q[0x72] > 2) {
            q[0x72] = 0;
            q[0x70] = q[1];
            q[1] = q[0x71];
            q[0x71] = 0;
        }
    }
    return q[1];
}

int func_0217B8E4(char *p, int v)
{
    p[0x28a1] = v;
    return 1;
}

int func_0217B8F0(char *p, char v)
{
    if ((unsigned char)p[0x28a2] == 1) return func_0217B8E4(p, v);
    return 0;
}

int func_0217B908(int x)
{
    switch (x) {
    case 0: case 1: case 2: case 3:
        break;
    case 4: case 5:
        return 5;
    case 6: case 7:
        return 0x18;
    case 8: case 9:
        return 6;
    case 10: case 11:
        return 0x19;
    case 12: case 13:
        return 7;
    case 14: case 15:
        return 0x1a;
    case 16: case 17:
        return 8;
    case 18: case 19:
        return 0x1b;
    case 20: case 21:
        return 9;
    case 22: case 23:
        return 0x1c;
    }
    return 5;
}

int func_0217B974(int x)
{
    switch (x) {
    case 0: case 1: case 2: case 3:
    case 5: case 7: case 9: case 11: case 13: case 15:
    case 17: case 19: case 21:
        break;
    case 4: case 6: case 8: case 10: case 12: case 14:
    case 16: case 18: case 20: case 22:
        return 1;
    }
    return 0;
}

int func_0217B9BC(unsigned int x)
{
    if (x < 4 || x > 23) return 0;
    return 1;
}
