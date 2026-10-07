/*
 * file:     unit_021BE6BC_p02.c
 * unit:     yes
 * function: func_021BE9C8, func_021BE9F8
 * address:  0x021BE9C8
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
 *   func_021BEC10  0x021BEC10  arm  ov114
 *   func_021BEF08  0x021BEF08  arm  ov114
 *   func_021BEF58  0x021BEF58  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern u8 *func_021BEF08(void);
extern void *func_021BEF58(int p);
extern int func_021BEC10(int, int);
int func_021BE9C8(int a, int b, int c);
int func_021BE9F8(u8 *p, int a, int b);


int func_021BE9C8(int a, int b, int c)
{
    return func_021BE9F8((u8 *)func_021BEC10((int)func_021BEF58((int)func_021BEF08()), a), b, c);
}


int func_021BE9F8(u8 *p, int a, int b)
{
    if (p == 0)
        return -1;
    *(u32 *)(p + 0xc8) = 0;
    *(u32 *)(p + 0xdc) = 0;
    *(u32 *)(p + 0xc0) = a;
    *(u32 *)(p + 0xc4) = b;
    return 0;
}
