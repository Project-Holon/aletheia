/*
 * file:     unit_021D9118_p02.c
 * unit:     yes
 * function: func_021D92CC, func_021D9340, func_021D936C, func_021D93A8
 * address:  0x021D92CC
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
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F06B8 0x021F06B8 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021D7D6C 0x021D7D6C thumb ov093
 *   d_021F0A40 0x021F0A40 data a4
 */
struct S;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021D775C(int);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int func_021D76BC(int, unsigned int);
extern int func_021C8288(u8 *p);
extern int func_021D7D6C(int);
void func_021D92CC(void *a, int b, int *c, int d);
void func_021D9340(int a, int b, int c);
void *func_021D9360(int *p);
void func_021D936C(int a, void *b, int c, int *d);
void func_021D93A8(int a, void *b, int c);
void *func_021D93CC(int *p);
extern unsigned int d_021F06B8;
extern unsigned int d_021F0A40;


void func_021D92CC(void *a, int b, int *c, int d)
{
    int t;
    u8 *p;

    if (b == func_021D775C(2) && c[0] != 0) {
        t = func_021D775C(0x19);
        if (t == 0 || c[1] != t) {
            func_021C88B4(a, 2, b);
            p = func_021C88A4(a, 4, b);
            func_021C8838(p + 4, 2, d);
            func_021C8860((struct S *)(p + 4), b);
            func_021C88C8(a, p);
            func_021C88B4(a, 3, b);
            c[1] = t;
        }
        c[0] = 0;
    }
}

void func_021D9340(int a, int b, int c)
{
    if (c == func_021D775C(2)) func_021D76BC(0x20, func_021D775C(0x20) << 1);
}

void *func_021D9360(int *p) { *p = 1; return &d_021F06B8; }

void func_021D936C(int a, void *b, int c, int *d)
{
    int v;
    if (c == func_021D775C(4) && func_021C8288(b) == 1) {
        v = func_021D775C(0x1d);
        if (func_021D7D6C(v) || v == 0xe) *d = func_021D76BC(0x41, 1);
    }
}

void func_021D93A8(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021C8288(b) == 1) func_021D76BC(0x41, 1);
}

void *func_021D93CC(int *p) { *p = 3; return &d_021F0A40; }
