/*
 * file:     unit_021DB650_p03.c
 * unit:     yes
 * function: func_021DB8E8, func_021DB93C
 * address:  0x021DB8E8
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
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   sub_0201C1BC   0x0201C1BC  thumb
 *   func_021DB99C  0x021DB99C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int func_021B9A24(u32 a, u32 b);
extern int func_021E85F8(int c);
extern u32 sub_0201C1BC(u16 move);
extern int func_021DB99C(int t);
extern int func_021D76BC(int key, u32 val);
void func_021DB8E8(void *a, void *p, int id);
void func_021DB93C(int a, int b, int x);


void func_021DB8E8(void *a, void *p, int id)
{
    u8 *r;

    if (id == func_021D775C(2)) {
        func_021C88B4(p, 2, id);
        r = (u8 *)func_021C88A4(p, 4, id);
        func_021C8838(r + 4, 2, 0x1e7);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(p, r);
        func_021C88B4(p, 3, id);
    }
}


static inline void set8(int k, u8 v)
{
    func_021D76BC(k, v);
}


void func_021DB93C(int a, int b, int x)
{
    int ok;
    u16 t;

    if (func_021B9A24((u8)func_021D775C(3), x) == 0) {
        ok = 0;
        if (func_021E85F8(x) != 0) {
            ok = 1;
        } else {
            t = func_021D775C(0x12);
            if (sub_0201C1BC(t) == 10)
                ok = 1;
            else if (func_021DB99C(t) != 0)
                ok = 1;
        }
        if (ok != 0)
            set8(0x20, func_021D775C(0x20) + 1);
    }
}
