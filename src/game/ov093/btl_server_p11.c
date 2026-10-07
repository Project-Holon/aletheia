/*
 * file:     btl_server_p11.c
 * unit:     yes
 * function: func_021BAC04, func_021BACAC, func_021BAE60, func_021BAEF8, func_021BB040, func_021BB0A0, func_021BB0E0, func_021BB208, func_021BB280, func_021BB320, func_021BB368, func_021BB3B0, func_021BB3F8, func_021BB43C, func_021BB484
 * address:  0x021BAC04
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
 *   func_021BB718  0x021BB718  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021BBB60  0x021BBB60  thumb  ov093
 *   func_021BB5FC  0x021BB5FC  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BABF4  0x021BABF4  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BC390 0x021BC390 thumb ov093
 *   func_021BA5D8 0x021BA5D8 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   func_021BB6A8 0x021BB6A8 thumb ov093
 *   func_021BB628 0x021BB628 thumb ov093
 *   func_021BBC34 0x021BBC34 thumb ov093
 *   func_021BBC44 0x021BBC44 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021BB56C 0x021BB56C thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BC55C 0x021BC55C thumb ov093
 *   func_021B9120 0x021B9120 thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 *   func_021B8FF4  0x021B8FF4  thumb  ov093
 *   func_021EEB64  0x021EEB64  thumb  ov093
 *   func_021BC360  0x021BC360  thumb  ov093
 *   func_021BB768 0x021BB768 thumb ov093
 *   func_021BBD80 0x021BBD80 thumb ov093
 *   func_021BBD8C 0x021BBD8C thumb ov093
 *   func_021B85A8  0x021B85A8  thumb  ov093
 *   func_021B8DE4  0x021B8DE4  thumb  ov093
 *   func_021B9AEC  0x021B9AEC  thumb  ov093
 *   func_021B9B98  0x021B9B98  thumb  ov093
 *   func_021BB830  0x021BB830  thumb  ov093
 *   func_021D8454  0x021D8454  thumb  ov093
 *   func_021B9920  0x021B9920  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021BBD20 0x021BBD20 thumb ov093
 *   func_021BBD2C 0x021BBD2C thumb ov093
 *   func_021EE9A4  0x021EE9A4  thumb  ov093
 *   func_021B917C  0x021B917C  thumb  ov093
 *   func_021B86DC  0x021B86DC  thumb  ov093
 *   func_02005D90  0x02005D90  thumb
 *   func_021B9114  0x021B9114  thumb  ov093
 *   func_020362DC  0x020362DC  arm
 *   func_02035C60  0x02035C60  arm
 */
#include "../../matched/include/Obj09946.h"
#include "../../matched/include/Obj01372.h"
#include "../../matched/include/Obj06222.h"
#include "../../matched/include/Obj01235.h"
#include "../../matched/include/Obj21031.h"
#include "../../matched/include/Obj21032.h"
#include "../../matched/include/Obj02775.h"
#include "../../matched/include/Obj13292.h"
#include "../../matched/include/Obj05188.h"
#include "../../matched/include/Obj21033.h"
#include "../../matched/include/Obj21034.h"

struct QW;
typedef unsigned char  u8;

typedef unsigned int u32;

typedef struct {
    u32 pad : 7;
    u32 f : 3;
} B;

typedef unsigned short u16;

extern void func_021BB718(int a, int b);
extern int func_021BB798(unsigned char *p);
extern void func_021BB7D0(const unsigned char *p);
extern void *func_021B86B8(void ***);
extern int func_021BBB60(unsigned char *p);
extern int func_021BB5FC(unsigned char *p, int b);
extern void func_021BABEC(int *p, void *f);
extern void func_021BABF4(void *);
extern void func_021BB724(unsigned char *p, int a, int b, int c);
extern int func_021BC390(u8 *);
extern int func_021BA5D8(char *);
extern int func_021BA618(char *p);
extern void func_021BB6A8(u8 *);
extern int func_021BB628(u8 *, int, int);
extern void func_021BBC34(u8 *);
extern int func_021BBC44(u8 *p, int a);
extern u8 func_021B86C0(u8 **p);
extern void func_021BB56C(void *);
extern u32 func_021B8588(void **p);
extern u8 func_021BC55C(u8 *);
extern void func_021B9120(u8 *p, u8 n);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern u8 func_021B8FF4(u8 *);
extern u32 func_021EEB64(struct QW *p, u32 *out);
extern int func_021BC360(u8 *p);
extern void func_021BB768(u8 *p, int a, u32 i, int b, int c);
extern void func_021BBD80(u8 *);
extern int func_021BBD8C(u8 *, void *);
extern int func_021B85A8(u8 *);
extern u8 func_021B8DE4(char *p, int i);
extern char *func_021B9AEC(char *, int);
extern u8 func_021B9B98(u8 *p);
extern int func_021BB830(u8 *);
extern u32 func_021D8454(B *);
extern u8 *func_021B9920(void *p, u32 i, u8 j);
extern u8 func_021D5440(u8 *p);
extern void func_021BBD20(u8 *p);
extern int func_021BBD2C(u8 *p, int a);
extern u8 *func_021EE9A4(u8 *p, unsigned int *out);
extern int func_021B917C(char *p);
extern u16 func_021B86DC(void **);
extern void func_02005D90(u32, u32);
extern u8 func_021B9114(u8 **);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
int func_021BAC04(char *p, int *st);
int func_021BACAC(u8 *p, int *s);
int func_021BAE5C(u8 *p);
int func_021BAE60(u8 *p, int *s);
int func_021BAEF8(u8 *p, int *s);
int func_021BB040(u8 *p);
u32 func_021BB0A0(u8 *p);
int func_021BB0E0(u8 *p, int *s);
int func_021BB208(u8 *p, int *s);
int func_021BB280(u8 *p);
int func_021BB320(u8 *p, int *s);
int func_021BB368(u8 *p, int *s);
int func_021BB3B0(u8 *p, int *s);
int func_021BB3F8(u8 *p, int *s);
int func_021BB43C(u8 *p, int *s);
int func_021BB484(u8 *p, int *s);


int func_021BAC04(char *p, int *st)
{
    int *q;

    switch (*st) {
    case 0:
        func_021BB718((int)p, 1);
        (*st)++;
    case 1:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            if (func_021B86B8(*(void *** *)&((struct Obj09946 *)p)->fC) != (void *)4) {
                func_021BB5FC((unsigned char *)p, func_021BBB60((unsigned char *)(((struct Obj09946 *)p)->f44)));
                (*st)++;
            } else {
                func_021BABEC((int *)p, (void *)func_021BB280);
            }
        }
        break;
    case 2:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            (*st)++;
        }
        break;
    case 3:
        q = *(int * *)&((struct Obj09946 *)p)->fCB0;
        func_021BB724((unsigned char *)p, 8, (int)(q + 2), *q);
        (*st)++;
        break;
    case 4:
        if (func_021BB798((unsigned char *)p)) {
            func_021BB7D0((const unsigned char *)p);
            func_021BABF4(p);
        }
        break;
    }
    return 0;
}


/*
 * Contains the lead callback and its trailing return-one stub.
 * The fifth pool word is func_021BB0E0, the distinct case-1 callback;
 * reusing func_021BAEF8 there shortens the pool and cross-jumps the calls.
 */
int func_021BACAC(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        if (func_021BC390(*(u8 * *)&((struct Obj01372 *)p)->f44)) {
            int *q = *(int * *)&((struct Obj01372 *)p)->fCB0;
            func_021BB724(p, 8, (int)(q + 2), *q);
            (*s)++;
        } else
            *s += 2;
        break;
    case 1:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BB718((int)p, 3);
        (*s)++;
        break;
    case 3:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA5D8(*(char * *)&((struct Obj01372 *)p)->fC)) {
                func_021BABEC((int *)p, (void *)func_021BB208);
                break;
            }
            if (func_021BA618((char *)(*(u8 * *)&((struct Obj01372 *)p)->fC))) {
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            }
            func_021BB6A8(p);
            if (func_021BB628(p, 1, func_021BAE5C(p)))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 4:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 5:
        func_021BBC34(*(u8 * *)&((struct Obj01372 *)p)->f44);
        func_021BB7D0(p);
        (*s)++;
    case 6:
        ((struct Obj01372 *)p)->f48 = func_021BBC44(*(u8 * *)&((struct Obj01372 *)p)->f44, (int)(p + 0xb4));
        if (func_021B86C0(((struct Obj01372 *)p)->fC))
            func_021BB56C(p + 0xb4);
        {
            int *q = *(int * *)&((struct Obj01372 *)p)->fCB0;
            func_021BB724(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 7:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj01372 *)p)->f48) {
            case 0:
                func_021BABF4(p);
                break;
            case 3:
                *s = 6;
                break;
            case 2:
                {
                    void *a = func_021B86B8(*(void *** *)&((struct Obj01372 *)p)->fC);
                    u32 b = func_021B8588(((struct Obj01372 *)p)->fC);
                    if (!a && !b)
                        func_021BABEC((int *)p, (void *)func_021BAE60);
                    else
                        func_021BABEC((int *)p, (void *)func_021BAEF8);
                }
                break;
            case 1:
                func_021BABEC((int *)p, (void *)func_021BB0E0);
                break;
            case 6:
                func_021B9120(((struct Obj01372 *)p)->fC, func_021BC55C(*(u8 * *)&((struct Obj01372 *)p)->f44));
                func_021BABEC((int *)p, (void *)func_021BB280);
                return 0;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01372 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01372 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                return 0;
            case 5:
            default:
                return 1;
            }
        }
        break;
    }
    return 0;
}


int func_021BAE5C(u8 *p)
{
    return 1;
}


int func_021BAE60(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB718((int)p, 7);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            u8 idx = func_021B8FF4(*(u8 * *)&((struct Obj06222 *)p)->fC);
            int *q;

            func_021BB7D0(p);
            if (*((u8 *)func_021EEB64((struct QW *)(*(u32 *)(p + 0x14 + idx * 12)), 0)) == 0) {
                func_021BABEC((int *)p, (void *)func_021BAEF8);
            } else {
                ((struct Obj06222 *)p)->f48 = func_021BC360((u8 *)(((struct Obj06222 *)p)->f44));
                q = *(int * *)&((struct Obj06222 *)p)->fCB0;
                func_021BB724(p, 8, (int)(q + 2), *q);
                (*s)++;
            }
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            if (((struct Obj06222 *)p)->f48 != 0)
                return 1;
            func_021BABEC((int *)p, (void *)func_021BAEF8);
        }
        break;
    }
    return 0;
}


/*
 * Case 4 falls through into case 5; the two entry points prevent the
 * field-address setup from moving above the state increment.
 */
int func_021BAEF8(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 5, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p)) {
            if (func_021BB040(p)) {
                p[0xec] = func_021BB0A0(p);
                func_021BB768(p, 4, 0, (int)(p + 0xec), 1);
            }
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA618((char *)(*(u8 * *)&((struct Obj01235 *)p)->fC))) {
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            }
            func_021BB6A8(p);
            if (func_021BB628(p, 2, 0))
                (*s)++;
            else
                *s += 2;
        }
        break;
    case 3:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 4:
        func_021BB7D0(p);
        func_021BBD80(*(u8 * *)&((struct Obj01235 *)p)->f44);
        (*s)++;
    case 5:
        ((struct Obj01235 *)p)->f48 = func_021BBD8C(*(u8 * *)&((struct Obj01235 *)p)->f44, p + 0xb4);
        {
            int *q = *(int * *)&((struct Obj01235 *)p)->fCB0;
            func_021BB724(p, 8, (int)(q + 2), *q);
        }
        (*s)++;
        break;
    case 6:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj01235 *)p)->f48) {
            case 2:
                *s = 0;
                break;
            case 3:
                *s = 5;
                break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01235 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01235 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            case 5:
                return 1;
            default:
                func_021BABF4(p);
                break;
            }
        }
        break;
    }
    return 0;
}


int func_021BB040(u8 *p)
{
    unsigned i;

    if (func_021B85A8(*(u8 * *)&((struct Obj01235 *)p)->fC) != 0 && p[0xcba] != 0) {
        for (i = 0; i < p[0xcba]; i++) {
            if (func_021B8DE4((char *)(*(u8 * *)&((struct Obj01235 *)p)->fC), p[0xcb4 + i]) == 0)
                return 0;
        }
        if (func_021B9B98((u8 *)func_021B9AEC(*(char * *)&((struct Obj01235 *)p)->f10, func_021B8FF4(*(u8 * *)&((struct Obj01235 *)p)->fC))) < 2)
            return 0;
        return 1;
    }
    return 0;
}


u32 func_021BB0A0(u8 *p)
{
    u8 *q = p + 0x20;
    B *b;

    if (func_021BB830(q) != 0) {
        b = (B *)func_021EEB64((struct QW *)(((struct Obj21032 *)q)->f0), 0);
        if (func_021D8454(b) == 3) {
            u8 *r = func_021B9920(((struct Obj21031 *)p)->f10, 1, b->f);
            return func_021D5440(r);
        }
    }
    return 0x1f;
}

int func_021BB0E0(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 6, (int)(p + 0xcb4), p[0xcba]);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            if (func_021BA618(((struct Obj02775 *)p)->fC)) {
                func_021BABEC((int *)p, (void *)func_021BB280);
            } else {
                func_021BB6A8(p);
                if (func_021BB628(p, 3, 0)) (*s)++;
                else *s += 2;
            }
        }
        break;
    case 2:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 3:
        func_021BB7D0(p);
        func_021BBD20(((struct Obj02775 *)p)->f44);
        (*s)++;
    case 4: {
        int *q;
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        q[0] = 0;
        q[1] = 0;
        ((struct Obj02775 *)p)->f48 = func_021BBD2C(((struct Obj02775 *)p)->f44, (int)(p + 0xb4));
        q = *(int * *)&((struct Obj02775 *)p)->fCB0;
        func_021BB724(p, 8, (int)(q + 2), q[0]);
        (*s)++;
        break;
    }
    case 5:
        if (func_021BB798(p)) {
            func_021BB7D0(p);
            switch (((struct Obj02775 *)p)->f48) {
            case 1: *s = 0; break;
            case 3: *s = 4; break;
            case 2: func_021BABEC((int *)p, (void *)func_021BAEF8); break;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj02775 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj02775 *)p)->f44)));
                func_021BABEC((int *)p, (void *)func_021BB280);
                break;
            case 5: return 1;
            case 0:
            default: func_021BABF4(p); break;
            }
        }
        break;
    }
    return 0;
}


int func_021BB208(u8 *p, int *s)
{
    int n;

    switch (*s) {
    case 0: {
        u8 *r = func_021EE9A4(p + 0x68, (unsigned int *)(&n));
        func_021BB724(p, 0xa, (int)r, n);
        (*s)++;
        break;
    }
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021BB718((int)p, 0x10);
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021B916C((u8 *)(((struct Obj13292 *)p)->fC), func_021C84D8((u8 *)(((struct Obj13292 *)p)->f44)));
            func_021BABEC((int *)p, (void *)func_021BB280);
        }
        break;
    }
    return 0;
}


int func_021BB280(u8 *p)
{
    int r5 = func_021B917C((char *)(*(u8 * *)&((struct Obj05188 *)p)->fC));

    ((struct Obj05188 *)p)->fAA = r5;
    ((struct Obj05188 *)p)->fA8 = func_021B8FF4(*(u8 * *)&((struct Obj05188 *)p)->fC);

    switch ((int)func_021B86B8(*(void *** *)&((struct Obj05188 *)p)->fC)) {
    case 1:
        func_021BABEC((int *)p, (void *)func_021BB43C);
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB484);
        break;
    case 3:
        func_021BABEC((int *)p, (void *)func_021BB3F8);
        break;
    case 0:
        if (r5 == 1) {
            func_021BABEC((int *)p, (void *)func_021BB368);
        } else if (r5 == 0 || r5 == 2) {
            func_021BABEC((int *)p, (void *)func_021BB3B0);
        } else {
            func_021BABEC((int *)p, (void *)func_021BB320);
        }
        break;
    default:
        if (r5 == 1) {
            func_02005D90(func_021B86DC(*(void ** *)&((struct Obj05188 *)p)->fC), 0xffff);
        }
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}


int func_021BB320(u8 *p, int *s)
{
    switch (*s) {
    case 0: {
        int r = 0;
        if (func_021B9114(*(u8 ** *)&((struct Obj21033 *)p)->fC) == 0) {
            if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) r = 1;
        } else {
            r = 1;
        }
        if (r != 0) {
            (*s)++;
            return 1;
        }
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}


int func_021BB368(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xe, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}


int func_021BB3B0(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xf, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}


int func_021BB3F8(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xd, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}


int func_021BB43C(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xb, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        func_021BABEC((int *)p, (void *)func_021BB320);
        break;
    }
    return 0;
}


int func_021BB484(u8 *p, int *s)
{
    switch (*s) {
    case 0:
        func_021BB724(p, 0xc, (int)(p + 0xa8), 4);
        (*s)++;
        break;
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            (*s)++;
        }
        break;
    case 2:
        if (func_021B86C0(*(u8 ** *)&((struct Obj21034 *)p)->fC) == 0) {
            func_021BABEC((int *)p, (void *)func_021BB320);
        } else {
            return 1;
        }
        break;
    }
    return 0;
}
