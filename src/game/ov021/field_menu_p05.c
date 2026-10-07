/*
 * file:     field_menu_p05.c
 * unit:     yes
 * function: func_021A8234, func_021A8244, func_021A8268, func_021A8278, func_021A82A8, func_021A82D8
 * address:  0x021A8234
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218C860  0x0218C860  thumb
 *   func_0218C8D8  0x0218C8D8  thumb  ov021
 *   func_0218C88C  0x0218C88C  thumb
 *   func_0218C990  0x0218C990  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 */
#include "../../matched/include/Obj18069.h"
#include "../../matched/include/Obj18070.h"

struct Evt;
typedef struct {
    int pad[10];
    int f28;
} S;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct Src {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    u8 pad10[0x3C - 0x10];
    int f3C;
    int f40;
    u8 f44;
    u8 f45;
} Src;

extern void func_0218C860(int a);
extern int func_0218C8D8(void *p);
extern void func_0218C88C(unsigned char *p, int v, int c);
extern int func_0218C990(unsigned char *p, int v);
extern void func_020061E4(u32 a);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
void func_021A8234(S *s);
int func_021A8244(u32 a);
int func_021A8268(u32 a);
void func_021A8278(S *s);
void func_021A82A8(S *s);
void func_021A82D8(void *a, Src **pp);


void func_021A8234(S *s)
{
    if (s->f28 != 0) {
        func_0218C860(s->f28);
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A8244(u32 a)
{
if (func_021A8268(a) == 0) {
    return 1;
}
if (func_0218C8D8((void *)(((struct Obj18069 *)((u8 *)(a)))->f28)) != 0) {
    return 1;
}
return 0;
}


int func_021A8268(u32 a)
{
if (((struct Obj18070 *)((u8 *)(a)))->f28 != 0) {
    return 1;
}
return 0;
}


void func_021A8278(S *s)
{
    u16 v;
    if (func_021A8268((unsigned int)s)) {
        func_0218C88C((unsigned char *)s->f28, 0, 0);
        if (func_0218C990((unsigned char *)s->f28, (int)(&v))) {
            func_020061E4(v);
        }
    }
}


void func_021A82A8(S *s)
{
    u16 v;
    if (func_021A8268((unsigned int)s)) {
        func_0218C88C((unsigned char *)s->f28, 1, 0);
        if (func_0218C990((unsigned char *)s->f28, (int)(&v))) {
            func_020061E4(v);
        }
    }
}


void func_021A82D8(void *a, Src **pp)
{
    Src *s;
    void *r;

    s = *pp;
    if (s->f40 != 0) {
        r = (void *)func_021BE92C(s->f04, (int)s->f0C, 3, 0, 0, s->f44, s->f45);
    } else {
        r = (void *)func_021BE92C(s->f04, (int)s->f0C, s->f3C, 0, 1, 0, 0);
    }
    func_02012374(a, r);
}
