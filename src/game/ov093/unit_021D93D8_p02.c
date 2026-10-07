/*
 * file:     unit_021D93D8_p02.c
 * unit:     yes
 * function: func_021D9648, func_021D9670
 * address:  0x021D9648
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D76BC 0x021D76BC thumb ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int);
extern int func_021D76BC(int, unsigned int);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
int func_021D9648(int a, int b, int c);
void func_021D9670(void *a, void *b, int c, int *d, u16 e);

int func_021D9648(int a, int b, int c)
{
    if (b == func_021D775C(4) && c == func_021D775C(0x1d))
        return func_021D76BC(0x41, 1);
    return 0;
}


void func_021D9670(void *a, void *b, int c, int *d, u16 e)
{
    u8 *p;

    if (c == func_021D775C(4) && *d == 1) {
        func_021C88B4(b, 2, c);
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, e);
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
        func_021C88B4(b, 3, c);
        *d = 0;
    }
}
