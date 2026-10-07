/*
 * file:     unit_021EE740_p10.c
 * unit:     yes
 * function: func_021EF4E4, func_021EF514
 * address:  0x021EF4E4
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A21B8 0x021A21B8 thumb ov021
 *   func_021A2248 0x021A2248 thumb ov021
 *   func_021A244C 0x021A244C thumb ov021
 *   func_021A2564 0x021A2564 thumb ov021
 *   func_021A2228 0x021A2228 thumb ov021
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { char pad[0x774]; int *list; } Obj;

extern int *func_021A21B8(int *);
extern int func_021A2248(u8 *, int);
extern void func_021A244C(u8 *, int *, int *);
extern void func_021A2564(Obj *, int, int);
extern void func_021A2228(u8 *, int, int, int, int);
int func_021EF4E4(u8 *a, int b, int c);
int func_021EF514(u8 *a);


int func_021EF4E4(u8 *a, int b, int c)
{
    int x;
    int y;
    func_021A21B8((int *)a);
    func_021A2248(a, c);
    func_021A244C(a, &x, &y);
    func_021A2564((Obj *)a, x, y);
    return 0;
}


int func_021EF514(u8 *a)
{
    int *p;
    p = func_021A21B8((int *)a);
    func_021A2228(a, 0, 16, 2, -2);
    *p = 100;
    return 1;
}
