/*
 * file:     field_player_grid_event_p11.c
 * unit:     yes
 * function: func_021C0140, func_021C017C, func_021C01E4, func_021C01F8, func_021C021C, func_021C029C, func_021C02F8
 * address:  0x021C0140
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
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C7260  0x021C7260  thumb  ov021
 *   func_021C71D4  0x021C71D4  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218FE80  0x0218FE80  thumb  ov021
 *   func_0218FEA0  0x0218FEA0  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_0218FF00  0x0218FF00  thumb  ov021
 *   func_0218FF20  0x0218FF20  thumb  ov021
 *   func_0218FE98  0x0218FE98  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021C0374  0x021C0374  thumb  ov021
 *   func_021C0360  0x021C0360  thumb  ov021
 *   func_021C6E48  0x021C6E48  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C7D28  0x021C7D28  thumb  ov021
 */
#include "../../matched/include/Obj02723.h"
#include "../../matched/include/Obj12123.h"
#include "../../matched/include/Obj05073.h"
#include "../../matched/include/Obj20154.h"
#include "../../matched/include/Obj02724.h"

struct Evt;
struct Obj00020;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct { u32 w[8]; } Blk32;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02188D38(u8 *p);
extern void *func_021C7260(u32 a, u16 b, int c);
extern void *func_021C71D4(u32 a, u32 b, u32 c);
extern void func_021C6DE0(u8 *p, u32 *a, u32 b);
extern void *func_02188C58(void *p);
extern void *func_0218FE80(void *a);
extern void func_0218FEA0(u8 *p, u32 v);
extern void func_0218FEA4(u32 a);
extern void func_0218FE78(u32 a, u8 *b);
extern void func_0218FEC0(u8 *o);
extern int func_0218FF00(u32 a);
extern u32 func_0218FE98(u32);
extern void func_0218FF20(u8 *a);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021C0374(u32 *p);
extern int func_021C0360(u8 *a);
extern int func_021C6E48(u32 a);
extern void func_020061E4(u32 a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_021C7D28(int a, int b, u16 c, u16 d);
void func_021C0140(u32 *p);
void func_021C017C(u8 *p);
int func_021C01E4(void **a);
int func_021C01F8(u32 *p);
int func_021C021C(u32 a, int *st, u8 *p);
void func_021C029C(u8 *p);
void func_021C02F8(u8 *p);


void func_021C0140(u32 *p)
{
    u32 o = p[1];
    u32 r = func_02188D38((u8 *)o);
    u32 a = (u32)func_021C7260(o, 0x14, 3);
    u32 b = (u32)func_021C71D4(o, 0x14, 5);

    func_021C6DE0((u8 *)r, (u32 *)a, 0);
    func_021C6DE0((u8 *)r, (u32 *)b, a);
}


void func_021C017C(u8 *p)
{
    u32 a;
    u32 b;

    a = (u32)func_02188C58((void *)(((struct Obj02723 *)p)->f4));
    b = (u32)func_0218FE80((void *)(((struct Obj02723 *)p)->f4));
    ((struct Obj02723 *)p)->f24 = 0x3c;
    ((struct Obj02723 *)p)->f68 = 1;
    ((struct Obj02723 *)p)->f6C = 1;
    ((struct Obj02723 *)p)->f70 = b;
    func_0218FEA0((u8 *)b, (u32)(p + 0x24));
    func_0218FEA4(((struct Obj02723 *)p)->f70);
    func_0218FE78(a, p + 0x28);
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    ((struct Obj02723 *)p)->f4C -= 0x64000;
    func_0218FEC0((u8 *)(((struct Obj02723 *)p)->f70));
    func_0218FF00(((struct Obj02723 *)p)->f70);
}


int func_021C01E4(void **a)
{
func_0218FF20((u8 *)(((struct Obj12123 *)((u8 *)(a)))->f70));
return func_0218FE98(((struct Obj12123 *)((u8 *)(a)))->f70);
}


/*
 * Calls func_021BE8D4 with mode 0 or 1 by the flag at +0x78.
 */
int func_021C01F8(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];

    if (p[30] != 0)
        func_021BE8D4((void *)a, b, 0, 0);
    else
        return func_021BE8D4((void *)a, b, 1, 0);
}


int func_021C021C(u32 a, int *st, u8 *p)
{
    int n;

    u32 q;

    q = func_02188D38((u8 *)(((struct Obj05073 *)p)->f4));
    switch (*st) {
    case 0:
        func_021C029C(p);
        func_021C02F8(p);
        func_020061E4(0x6DF);
        *st = *st + 1;
        break;
    case 1:
        n = ((struct Obj05073 *)p)->f74;
        ((struct Obj05073 *)p)->f74 = n + 1;
        if (n > 0x23) {
            func_02012374((struct Evt *)a, (struct Evt **)func_021C0374((u32 *)p));
            *st = *st + 1;
            break;
        }
    case 2:
        if (func_021C6E48(q)) {
            func_020061E4(0x559);
            *st = *st + 1;
        }
        break;
    case 3:
        func_021C0360(p);
        return 1;
    }
    return 0;
}


void func_021C029C(u8 *p)
{
    u32 s;
    u32 a;
    u32 b;
    u32 c;
    u32 d;

    s = ((struct Obj20154 *)p)->f4;
    a = func_02188D38((u8 *)s);
    b = func_021C7D28(s, (int)func_021A3074(func_02188CB4((void *)s)), 0x28, 6);
    c = (u32)func_021C7260(s, 0x14, 4);
    d = (u32)func_021C71D4(s, 0x14, 5);
    func_021C6DE0((u8 *)a, (u32 *)b, 0);
    func_021C6DE0((u8 *)a, (u32 *)c, 0);
    func_021C6DE0((u8 *)a, (u32 *)d, c);
}


void func_021C02F8(u8 *p)
{
    u32 a;
    u32 b;

    a = (u32)func_02188C58((void *)(((struct Obj02724 *)p)->f4));
    b = (u32)func_0218FE80((void *)(((struct Obj02724 *)p)->f4));
    ((struct Obj02724 *)p)->f24 = 0x3c;
    ((struct Obj02724 *)p)->f68 = 1;
    ((struct Obj02724 *)p)->f6C = 1;
    ((struct Obj02724 *)p)->f70 = b;
    func_0218FEA0((u8 *)b, (u32)(p + 0x24));
    func_0218FEA4(((struct Obj02724 *)p)->f70);
    func_0218FE78(a, p + 0x28);
    *(Blk32 *)(p + 0x48) = *(Blk32 *)(p + 0x28);
    ((struct Obj02724 *)p)->f4C -= 0x64000;
    func_0218FEC0((u8 *)(((struct Obj02724 *)p)->f70));
    func_0218FF00(((struct Obj02724 *)p)->f70);
}
