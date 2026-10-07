/*
 * file:     unit_021DDCA4_p01.c
 * unit:     yes
 * function: func_021DDCD8, func_021DDD38
 * address:  0x021DDCD8
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
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021D6D7C(u8 *p);
extern void func_021D7704(int a, int b);
extern u32 func_021C7EC4(u8 *p);
extern int func_021E85F8(int id);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
int func_021DDCD8(int a, u8 *b, int c, int *d, u8 e, int f);
void func_021DDD38(void *a, u8 *b, int c, int *d);


int func_021DDCD8(int a, u8 *b, int c, int *d, u8 e, int f)
{
    if (c == func_021D775C(4) && e == func_021D775C(0x16)
        && (f != 0 || func_021D775C(0x38) > 3)
        && func_021D6D7C(func_021C7CF4((int *)b, c)) == 0) {
        func_021D7704(0x35, 0x800);
        if (func_021C7EC4(b) == 0)
            *d = 1;
        return 1;
    }
    return 0;
}


void func_021DDD38(void *a, u8 *b, int c, int *d)
{
    u8 *p;
    if (*d != 0 && func_021E85F8(c) != 0) {
        p = func_021C88A4((char *)b, 0x23, c);
        func_021C8838(p + 8, 2, 219);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), func_021D70A8(a));
        func_021C88C8(b, p);
    }
}
