/*
 * file:     field_place_name_p26.c
 * unit:     yes
 * function: func_021BDC94, func_021BDCB8, func_021BDCC8, func_021BDD20, func_021BDD34, func_021BDD40
 * address:  0x021BDC94
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_021BDD58  0x021BDD58  thumb  ov021
 *   func_021BDD7C  0x021BDD7C  thumb  ov021
 *   func_021BDD9C  0x021BDD9C  thumb  ov021
 *   func_021BDDAC  0x021BDDAC  thumb  ov021
 *   func_021BDD74  0x021BDD74  thumb  ov021
 *   func_021BE184  0x021BE184  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_021BE1A0  0x021BE1A0  thumb  ov021
 *   func_021BDFB0  0x021BDFB0  thumb  ov021
 *   func_021BE068  0x021BE068  thumb  ov021
 *   func_021BDDC0  0x021BDDC0  thumb  ov021
 *   func_021BDEB4  0x021BDEB4  thumb  ov021
 *   func_021BE1C4  0x021BE1C4  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb
 */
#include "../../matched/include/Obj00282.h"
#include "../../matched/include/Obj18252.h"

typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    char pad[0x54];
    void *f54;
} Obj;

extern u16 func_02188C84(u8 *p);
extern void *func_021BDD58(int a);
extern void func_021BDD7C(void *r, void *a);
extern void func_021BDD9C(void *r, void *x);
extern void func_021BDDAC(void *p);
extern void func_021BDD74(void *p);
extern void func_021BE184(void *a, void *b);
extern void func_0218FEA0(u8 *p, u32 v);
extern int func_021BE1A0(u32 a);
extern void func_021BDFB0(char *a);
extern void func_021BE068(void *a);
extern void func_021BDDC0(void *a);
extern void func_021BDEB4(void *a);
extern int func_021BE1C4(u32 a);
extern int func_0218FF00(u32 a);
extern void func_0218FF20(u8 *a);
void *func_021BDC94(void *a);
void func_021BDCB8(u8 *p);
void func_021BDCC8(char *a, int *b);
void func_021BDD20(Obj *p);
void func_021BDD34(u8 *p);
int func_021BDD40(void *a);


void *func_021BDC94(void *a)
{
    void *x = (void *)func_02188C84(a);
    void *r = func_021BDD58((int)x);

    func_021BDD7C(r, a);
    func_021BDD9C(r, x);
    return r;
}


void func_021BDCB8(u8 *p)
{
    func_021BDDAC(p);
    func_021BDD74(p);
}


void func_021BDCC8(char *a, int *b)
{
    func_021BE184(a, b);
    func_0218FEA0(((struct Obj00282 *)a)->f54, (u32)(a + 8));
    if (func_021BE1A0((u32)a) != 0) {
        switch (b[1]) {
        case 0:
            func_021BDFB0(a);
            break;
        case 1:
            func_021BE068(a);
            break;
        }
    } else {
        switch (b[1]) {
        case 0:
            func_021BDDC0(a);
            break;
        case 1:
            func_021BDEB4(a);
            break;
        }
    }
    ((struct Obj00282 *)a)->f64 = 1;
}


void func_021BDD20(Obj *p)
{
    if (func_021BE1C4((u32)p)) {
        func_0218FF00((u32)p->f54);
    }
}


/*
 * Tail-call thunk: the object's word at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void func_021BDD34(u8 *p)
{
    func_0218FF20((u8 *)(((struct Obj18252 *)p)->f54));
}


int func_021BDD40(void *a)
{
    return func_021BE1C4((u32)a);
}
