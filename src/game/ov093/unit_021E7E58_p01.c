/*
 * file:     unit_021E7E58_p01.c
 * unit:     yes
 * function: func_021E7FE4, func_021E8070, func_021E80C0, func_021E8104, func_021E814C
 * address:  0x021E7FE4
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
 *   func_021C846C  0x021C846C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D69AC  0x021D69AC  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C8494  0x021C8494  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021C814C  0x021C814C  thumb  ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C846C(u8 *p, int a, int b, int *out);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char func_021D69AC(unsigned char *base, int idx);
extern int func_021C7D00(u8 *p, int b);
extern void func_021C8494(u8 *p, int i);
extern int func_021C815C(int *p);
extern int func_021C814C(u8 *p, int v);
extern int func_021D5814(void *a, int b);
void func_021E7FE4(int a, u8 *b, int c);
void func_021E8070(int a, void *b, int c);
void func_021E80C0(int a, void *b, int c);
void func_021E8104(int a, void *b, int c);
void func_021E814C(int a, void *b, int c);


void func_021E7FE4(int a, u8 *b, int c)
{
    u8 k;
    int x;
    u8 *p;

    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        x = 0;
        if (k == 0x1f || func_021C846C(b, c, k, &x) == 0) {
            func_021D76BC(0x41, 1);
            if (x != 0)
                func_021D76BC(0x4f, 1);
        } else if (func_021D76BC(0x51, 1) != 0) {
            p = func_021C88A4((char *)b, 4, c);
            func_021C8838(p + 4, 2, 1118);
            func_021C8860((struct S *)(p + 4), c);
            func_021C8860((struct S *)(p + 4), k);
            func_021C88C8(b, p);
        }
    }
}


void func_021E8070(int a, void *b, int c)
{
    u8 v, t;
    if (c == func_021D775C(3)) {
        v = func_021D69AC(func_021C7CF4(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t == 0x1f || func_021C7D00(b, t) == 6)
            func_021D76BC(0x41, 1);
        func_021C8494(b, c);
    }
}


void func_021E80C0(int a, void *b, int c)
{
    u8 v, t;
    if (func_021C815C(b) != 0 && func_021C815C(b) != 3) {
        v = func_021D69AC(func_021C7CF4(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t != 0x1f)
            func_021D76BC(4, t);
    }
}


void func_021E8104(int a, void *b, int c)
{
    u8 v, t;
    if (c == func_021D775C(2)) {
        v = func_021D69AC(func_021C7CF4(b, c), 4);
        if (v == 0 || (u8)(v - 1) >= 0x18)
            t = 0x1f;
        else
            t = v - 1;
        if (t != 0x1f && func_021C814C(b, t) == 0)
            func_021D76BC(0x22, 0x1a);
    }
}


void func_021E814C(int a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        if (func_021D5814(func_021C7CF4(b, (u8)func_021D775C(4)), 2) != 0)
            func_021D76BC(0x40, 1);
    }
}
