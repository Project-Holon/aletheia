/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37C4, func_021F37DC, func_021F385C, func_021F38BC
 * address:  0x021F36C0
 * region:   ov065
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F3918     0x021F3918  data  a4
 *   d_021F38F8     0x021F38F8  data  a4
 *   d_021F3970     0x021F3970  data  a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_020113D8  0x020113D8  thumb
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE418 0x021BE418 thumb ov021
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_021F38D0 0x021F38D0 thumb ov065
 */
#include "../../matched/include/G__anon_V.h"

struct Ctx;
struct Big;
struct Rec94;
struct BigObj;
struct Desc;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct _anon_V V;

typedef signed int     s32;

typedef unsigned char  u8;

extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern unsigned char *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern int func_02188D2C(int *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern int *func_021897BC(char *p, int idx);
extern u8 func_02012984(const struct BigObj *p);
extern u32   func_020113D8(u32 a);
extern void  func_021BE760(void *p, void *a, int b);
extern V    *func_021BE480(void *p, int i, u16 j);
extern void func_021BE4A4(char *p, int i, int j, int v);
extern void func_021BE4B4(char *p, int i, int j, int v);
extern void *func_021BE674(char *base, int i, unsigned int j, int k);
extern void func_021BE6B8(unsigned char *p, int v);
extern void func_021BE6B0(unsigned char *p, int v);
extern void  func_021BE700(void *p, int i, u16 j, u16 k, int flag);
extern void func_021BE418(unsigned char *p, unsigned short i);
extern void func_021897A0(unsigned char *p, int id);
extern void func_021BE580(int a);
extern int func_021BE6E8(int a, int b, int c, int d);
extern void func_020061E4(u32 a);
extern int func_021BE6BC(int *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F38D0(void *p);
void func_021F36C0(void *a0);
void func_021F37C4(unsigned char *p);
void func_021F37DC(int a);
void func_021F385C(int a);
void *func_021F38BC(void *p);
extern char d_021F3918[];
extern char d_021F38F8[];
extern struct _anon_V d_021F3970;


void func_021F36C0(void *a0)
{
    u32 sv;
    int *q;
    int *o;
    int i;
    void *b;
    void *s;

    sv = (u32)func_020120F4(func_02188C80(a0));
    q = func_0200B3A4((struct Rec94 *)func_02012EC4((struct Big *)sv), 0x36);
    s = (void *)func_02188D2C(a0);
    func_02189764(a0, 1, func_02188C84(a0), 8);
    o = func_021897BC(a0, 1);
    o[0] = 0;
    if (func_020113D8((u32)func_02012984((const struct BigObj *)sv)) - 3 <= 1) {
        func_021BE760(s, d_021F3918, 0);
        o[1] = 1;
    } else {
        func_021BE760(s, d_021F38F8, 0);
        o[1] = 0;
    }
    *func_021BE480(s, 0, 0) = d_021F3970;
    func_021BE4A4(s, 0, 0, 1);
    func_021BE4B4(s, 0, 0, *q == 0);
    for (i = 0; i < 2; i++) {
        b = func_021BE674(s, 0, (u16)0, (u16)i);
        func_021BE6B8(b, 0);
        func_021BE6B0(b, 1);
        func_021BE700(s, 0, 0, i, *q != 0);
    }
}


void func_021F37C4(unsigned char *p)
{
    func_021BE418((unsigned char *)func_02188D2C((int *)p), 0);
    func_021897A0(p, 1);
}


void func_021F37DC(int a)
{
    int s;
    int *w;

    s = func_02188D2C((int *)a);
    w = func_021897BC((char *)a, 1);
    if (w[0] != 0) {
        func_021BE580(s);
        if (w[1] == 0) {
            if (func_021BE6E8(s, 0, 0, 0) == 0x3C000)
                func_020061E4(0x7F9);
        }
        if (func_021BE6BC(func_021BE674((char *)s, 0, 0, 0)) != 0) {
            func_021BE4B4((char *)s, 0, 0, 1);
            w[0] = 0;
            *func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 0x36) = 0;
        }
    }
}


void func_021F385C(int a)
{
    int i;
    int s;
    int *w;

    s = func_02188D2C((int *)a);
    w = func_021897BC((char *)a, 1);
    w[0] = 1;
    func_021BE4B4((char *)s, 0, 0, 0);
    for (i = 0; i < 2; i++)
        func_021BE6B0(func_021BE674((char *)s, 0, (int)0, (unsigned short)i), 0);
    if (w[1] != 0)
        func_020061E4(0x7F7);
    else
        func_020061E4(0x7F8);
}


void *func_021F38BC(void *p)
{
    return func_020122C0(p, 0, (void *)func_021F38D0, 0);
}
