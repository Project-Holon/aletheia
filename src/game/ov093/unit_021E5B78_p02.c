/*
 * file:     unit_021E5B78_p02.c
 * unit:     yes
 * function: func_021E5D24, func_021E5D54
 * address:  0x021E5D24
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct QI;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *, unsigned int);
extern void func_021C88C8(void *a, void *b);
void func_021E5D24(int a, void *b, int c);
void func_021E5D54(u8 *p, void *a, int b);


void func_021E5D24(int a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        u16 n = (int)func_021D5B40(func_021C7CF4(b, c));
        func_021D76BC(0x30, func_021D805C((void *)n, 10));
    }
}


void func_021E5D54(u8 *p, void *a, int b)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != func_021D775C(3))
        return;
    r = func_021C7CF4(a, b);
    v = (u32)func_021D5B40(r);
    if (v == 0)
        return;
    q = func_021C88A4(a, 4, b);
    func_021C8838(q + 4, 2, 0x30b);
    func_021C8860((struct S *)(q + 4), b);
    func_021C8860((struct S *)(q + 4), v);
    func_021C88C8(a, q);
}
