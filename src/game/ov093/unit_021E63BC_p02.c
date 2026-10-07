/*
 * file:     unit_021E63BC_p02.c
 * unit:     yes
 * function: func_021E64B8, func_021E6500
 * address:  0x021E64B8
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F25DC     0x021F25DC  data  a4
 *   d_021F25D4     0x021F25D4  data   ov093  a4
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
void func_021E64B8(int u, void *a, u32 b);
int *func_021E64F4(int *p);
void func_021E6500(int u, void *a, u32 b);
int *func_021E653C(int *p);
extern int d_021F25DC[];
extern int d_021F25D4[];


void func_021E64B8(int u, void *a, u32 b)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x223);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}


int *func_021E64F4(int *p)
{
    *p = 1;
    return d_021F25DC;
}


void func_021E6500(int u, void *a, u32 b)
{
    u8 *e;

    if (b == func_021D775C(3)) {
        e = func_021C88A4(a, 4, b);
        func_021C8838(e + 4, 2, 0x226);
        func_021C8860((struct S *)(e + 4), b);
        func_021C88C8(a, e);
    }
}


int *func_021E653C(int *p)
{
    *p = 1;
    return d_021F25D4;
}
