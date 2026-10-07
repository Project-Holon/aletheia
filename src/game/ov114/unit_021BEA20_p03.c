/*
 * file:     unit_021BEA20_p03.c
 * unit:     yes
 * function: func_021BEC10, func_021BEC2C
 * address:  0x021BEC10
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BEC00  0x021BEC00  arm  ov114
 */
struct Conn;
typedef unsigned char u8;

typedef unsigned int u32;

extern struct Conn *func_021BEC00(int a, int b);
int func_021BEC10(int a, int d);
int func_021BEC2C(int a, int d);


/*
 * Looks node `a` up and returns its +0x10 field, or `d` when absent.
 */
int func_021BEC10(int a, int d)
{
    u8 *p = (u8 *)func_021BEC00(a, d);
    if (p != 0)
        d = *(int *)(p + 0x10);
    return d;
}


int func_021BEC2C(int a, int d)
{
    u8 *p = (u8 *)func_021BEC00(a, d);
    if (p != 0)
        d = *(int *)(p + 0x14);
    return d;
}
