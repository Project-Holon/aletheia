/*
 * file:     unit_021BA2F8_p08.c
 * unit:     yes
 * function: func_021BC5A0, func_021BC5C4
 * address:  0x021BC5A0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DCFD0   0x021DCFD0  data
 */
typedef unsigned int   u32;

extern void *func_020923B0(void *p, int c, u32 n);
void *func_021BC5A0(int a, int b);
void func_021BC5C4(int a);

extern void *(*func_021DCFD0[])(int);


void *func_021BC5A0(int a, int b)
{
    int n = a * b;
    void *p = func_021DCFD0[1](n);

    if (p)
        func_020923B0(p, 0, n);
    return p;
}

extern void *(*func_021DCFD0[])(int);


void func_021BC5C4(int a)
{
    func_021DCFD0[3](a);
}
