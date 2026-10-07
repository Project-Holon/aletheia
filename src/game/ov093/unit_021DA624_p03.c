/*
 * file:     unit_021DA624_p03.c
 * unit:     yes
 * function: func_021DA8DC, func_021DA96C
 * address:  0x021DA8DC
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
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5B48   0x021D5B48  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 */
#include "../../matched/include/Obj10060.h"
#include "../../matched/include/Obj21303.h"
#include "../../matched/include/Obj04368.h"

struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B48(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 a);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int key, u32 val);
extern int func_021D5D14(s8 *p, int i, int sign);
void func_021DA8DC(int a, int b, int c);
void func_021DA96C(void *a, int id, u32 e, int d);


void func_021DA8DC(int a, int b, int c)
{
    void *m;
    u8 *p;
    u8 *q;

    m = func_021C7CF4((int *)a, b);
    if (func_021D5B48(m) == 0) {
        p = func_021C88A4((char *)a, 5, b);
        p[6] = b;
        ((struct Obj10060 *)p)->f4 = func_021D7B74(m, c);
        ((struct Obj10060 *)p)->f0 |= 2 << 22;
        func_021C8838(p + 8, 2, 0x183);
        func_021C8860((struct S *)(p + 8), b);
        func_021C88C8((void *)a, p);
    } else {
        q = func_021C88A4((char *)a, 4, b);
        func_021C8838(q + 4, 2, 0xd2);
        func_021C8860((struct S *)(q + 4), b);
        ((struct Obj21303 *)q)->f0 |= 2 << 22;
        func_021C88C8((void *)a, q);
    }
    func_021D76BC(0x51, 1);
}


void func_021DA96C(void *a, int id, u32 e, int d)
{
    u8 *r;

    if (func_021D5D14(func_021C7CF4(a, id), e, d) != 0) {
        r = (u8 *)func_021C88A4(a, 14, id);
        r[0xf] = 1;
        r[0x10] = id;
        r[0xe] = 1;
        ((struct Obj04368 *)r)->f4 = e;
        r[0xc] = d;
        ((struct Obj04368 *)r)->f0 |= 0x800000;
        func_021C88C8(a, r);
    } else {
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, 0xd2);
        func_021C8860((struct S *)(r + 4), id);
        ((struct Obj04368 *)r)->f0 |= 0x800000;
        func_021C88C8(a, r);
    }
}
