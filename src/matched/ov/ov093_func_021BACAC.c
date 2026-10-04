/*
 * unit: yes
 * function: func_021BACAC, func_021BAE5C
 * address: 0x021BACAC
 * packet: pkt_ov093_021BACAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Contains the lead callback and its trailing return-one stub.
 * The fifth pool word is func_021BB0E0, the distinct case-1 callback;
 * reusing func_021BAEF8 there shortens the pool and cross-jumps the calls.
 * symbols:
 *   func_021BC390 0x021BC390 thumb ov093
 *   func_021BB724 0x021BB724 thumb ov093
 *   func_021BB798 0x021BB798 thumb ov093
 *   func_021BB718 0x021BB718 thumb ov093
 *   func_021BB7D0 0x021BB7D0 thumb ov093
 *   func_021BA5D8 0x021BA5D8 thumb ov093
 *   func_021BABEC 0x021BABEC thumb ov093
 *   func_021BB208 0x021BB208 thumb ov093
 *   func_021BA618 0x021BA618 thumb ov093
 *   func_021BB280 0x021BB280 thumb ov093
 *   func_021BB6A8 0x021BB6A8 thumb ov093
 *   func_021BB628 0x021BB628 thumb ov093
 *   func_021BBC34 0x021BBC34 thumb ov093
 *   func_021BBC44 0x021BBC44 thumb ov093
 *   func_021B86C0 0x021B86C0 thumb ov093
 *   func_021BB56C 0x021BB56C thumb ov093
 *   func_021BABF4 0x021BABF4 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BAE60 0x021BAE60 thumb ov093
 *   func_021BAEF8 0x021BAEF8 thumb ov093
 *   func_021BB0E0 0x021BB0E0 thumb ov093
 *   func_021BC55C 0x021BC55C thumb ov093
 *   func_021B9120 0x021B9120 thumb ov093
 *   func_021C84D8 0x021C84D8 thumb ov093
 *   func_021B916C 0x021B916C thumb ov093
 */
#include "../include/Obj01372.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BC390(u8 *);
extern void func_021BB724(u8 *p, int a, int b, int c);
extern int func_021BB798(u8 *);
extern void func_021BB718(int a, int b);
extern void func_021BB7D0(const u8 *p);
extern int func_021BA5D8(char *);
extern void func_021BABEC(void *, void *);
extern int func_021BB208(u8 *p, int *s);
extern int func_021BA618(u8 *);
extern int func_021BB280(u8 *p);
extern void func_021BB6A8(u8 *);
extern int func_021BB628(u8 *, int, int);
extern void func_021BBC34(u8 *);
extern int func_021BBC44(u8 *p, int a);
extern u8 func_021B86C0(u8 **p);
extern void func_021BB56C(void *);
extern void func_021BABF4(void *);
extern void *func_021B86B8(void ***);
extern u32 func_021B8588(void **p);
extern int func_021BAE60(u8 *, int *);
extern int func_021BAEF8(u8 *, int *);
extern int func_021BB0E0(u8 *p, int *s);
extern u8 func_021BC55C(u8 *);
extern void func_021B9120(void *, int);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
int func_021BAE5C(u8 *);

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
                func_021BABEC(p, (void *)func_021BB208);
                break;
            }
            if (func_021BA618(*(u8 * *)&((struct Obj01372 *)p)->fC)) {
                func_021BABEC(p, (void *)func_021BB280);
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
                        func_021BABEC(p, (void *)func_021BAE60);
                    else
                        func_021BABEC(p, (void *)func_021BAEF8);
                }
                break;
            case 1:
                func_021BABEC(p, (void *)func_021BB0E0);
                break;
            case 6:
                func_021B9120(((struct Obj01372 *)p)->fC, func_021BC55C(*(u8 * *)&((struct Obj01372 *)p)->f44));
                func_021BABEC(p, (void *)func_021BB280);
                return 0;
            case 4:
                func_021B916C((u8 *)(*(int *)&((struct Obj01372 *)p)->fC), func_021C84D8((u8 *)(*(int *)&((struct Obj01372 *)p)->f44)));
                func_021BABEC(p, (void *)func_021BB280);
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
