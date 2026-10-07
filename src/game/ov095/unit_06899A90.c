/*
 * file:     unit_06899A90.c
 * unit:     yes
 * function: func_06899A90, func_06899A9C
 * address:  0x06899A90
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0689D720 0x0689D720 data a4
 *   func_06899AC0 0x06899AC0 thumb ov095
 *   func_06899AD0 0x06899AD0 thumb ov095
 *   func_06899AE0 0x06899AE0 thumb ov095
 */
typedef unsigned char u8;

extern int func_06899AC0(int);
extern u8 func_06899AD0(u8);
extern void func_06899AE0(int, int);
void *func_06899A90(unsigned int *p);
void func_06899A9C(int a, int b, int c);
extern unsigned int d_0689D720;

void *func_06899A90(unsigned int *p)
{
    *p = 1;
    return &d_0689D720;
}

void func_06899A9C(int a, int b, int c)
{
    if (c == func_06899AD0(func_06899AC0(2)))
        func_06899AE0(0x35, 0x400);
}
